/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PSUtils
   Object     : PORTAL\oldcore_utils\PSUtils.obj
   Functions  : 13
   Addresses  : 00683C30 - 0077F770 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00683C30) --------------------------------------------------------  // acclient.c:667160
char *__thiscall AC1Legacy::PStringBaseIter<char>::IndexToConstPointer(AC1Legacy::PStringBaseIter<char> *this, unsigned int n)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1
  unsigned int v3; // ecx@1
  char *result; // eax@2

  v2 = this->pstring_ptr->m_buffer;
  v3 = v2->m_len;
  if ( n < v3 )
    result = &v2->m_data[n];
  else
    result = (char *)&v2->m_hash + v3 + 3;
  return result;
}

//----- (00683C50) --------------------------------------------------------  // acclient.c:667176
char __thiscall AC1Legacy::PStringBaseIter<char>::IndexToChar(AC1Legacy::PStringBaseIter<char> *this, unsigned int n)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1
  unsigned int v3; // ecx@1
  char result; // al@2

  v2 = this->pstring_ptr->m_buffer;
  v3 = v2->m_len;
  if ( n < v3 )
    result = v2->m_data[n];
  else
    result = *((_BYTE *)&v2->m_hash + v3 + 3);
  return result;
}

//----- (00683C70) --------------------------------------------------------  // acclient.c:667192
unsigned int __thiscall AC1Legacy::PStringBaseIter<char>::GetStrLen(AC1Legacy::PStringBaseIter<char> *this)
{
  return this->pstring_ptr->m_buffer->m_len - 1;
}

//----- (00683C80) --------------------------------------------------------  // acclient.c:667198
int __thiscall AC1Legacy::PStringBaseIter<char>::Truncate(AC1Legacy::PStringBaseIter<char> *this)
{
  AC1Legacy::PStringBaseIter<char> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // ebp@1
  AC1Legacy::PStringBase<char> *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  volatile LONG *v5; // ST04_4@5
  unsigned int v6; // eax@8

  v1 = this;
  v2 = this->pstring_ptr->m_buffer;
  InterlockedIncrement((volatile LONG *)&v2->m_cRef);
  v3 = v1->pstring_ptr;
  v4 = v3->m_buffer;
  if ( v3->m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v3->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v5);
  }
  if ( v1->curr )
    AC1Legacy::PStringBase<char>::append_n_chars(v1->pstring_ptr, v2->m_data, v1->curr);
  v6 = v1->curr;
  if ( v1->mark > v6 )
    v1->mark = v6;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00683D20) --------------------------------------------------------  // acclient.c:667232
int __thiscall AC1Legacy::PStringBaseIter<char>::Split(AC1Legacy::PStringBaseIter<char> *this, AC1Legacy::PStringBase<char> *start, AC1Legacy::PStringBase<char> *middle, AC1Legacy::PStringBase<char> *end)
{
  AC1Legacy::PStringBaseIter<char> *v4; // ebp@1
  unsigned int v5; // eax@1
  unsigned int v6; // ecx@1
  unsigned int v7; // ebx@2
  AC1Legacy::PStringBase<char> *v8; // eax@4
  AC1Legacy::PSRefBuffer<char> *v9; // esi@4
  AC1Legacy::PStringBase<char> *v10; // edi@4
  AC1Legacy::PSRefBuffer<char> *v11; // edi@8
  AC1Legacy::PSRefBuffer<char> *v12; // esi@9
  LONG (__stdcall *v13)(volatile LONG *); // edi@9
  AC1Legacy::PStringBase<char> *v14; // ebx@13
  AC1Legacy::PSRefBuffer<char> *v15; // esi@13
  volatile LONG *v16; // ST08_4@17
  AC1Legacy::PStringBase<char> *v17; // eax@18
  AC1Legacy::PStringBase<char> *v18; // ebx@18
  AC1Legacy::PSRefBuffer<char> *v19; // esi@18
  AC1Legacy::PStringBase<char> *v20; // edi@18
  AC1Legacy::PSRefBuffer<char> *v21; // edi@22
  AC1Legacy::PStringBase<char> *v22; // esi@23
  unsigned int v23; // eax@27
  AC1Legacy::PStringBase<char> *v24; // eax@27
  AC1Legacy::PStringBase<char> *v25; // ebp@27
  AC1Legacy::PSRefBuffer<char> *v26; // esi@27
  AC1Legacy::PSRefBuffer<char> **v27; // ebx@27
  AC1Legacy::PSRefBuffer<char> *v28; // eax@31
  AC1Legacy::PStringBase<char> *v29; // esi@32
  unsigned int second; // [sp+10h] [bp-8h]@2
  AC1Legacy::PStringBase<char> result; // [sp+14h] [bp-4h]@4

  v4 = this;
  v5 = this->curr;
  v6 = this->mark;
  if ( v5 >= v6 )
  {
    v7 = v6;
    second = v5;
  }
  else
  {
    v7 = v5;
    second = v6;
  }
  v8 = AC1Legacy::PStringBase<char>::substring(v4->pstring_ptr, &result, 0, v7 - 1);
  v9 = start->m_buffer;
  v10 = v8;
  if ( start->m_buffer != v8->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    v11 = v10->m_buffer;
    start->m_buffer = v11;
    InterlockedIncrement((volatile LONG *)&v11->m_cRef);
  }
  v12 = result.m_buffer;
  v13 = InterlockedDecrement;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v12 )
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  if ( v7 == second )
  {
    v14 = middle;
    v15 = middle->m_buffer;
    if ( middle->m_buffer != AC1Legacy::PStringBase<char>::null_string.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v15->m_cRef) && v15 )
        v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
      v16 = (volatile LONG *)&AC1Legacy::PStringBase<char>::null_string.m_buffer->m_cRef;
      v14->m_buffer = AC1Legacy::PStringBase<char>::null_string.m_buffer;
      InterlockedIncrement(v16);
    }
  }
  else
  {
    v17 = AC1Legacy::PStringBase<char>::substring(
            v4->pstring_ptr,
            (AC1Legacy::PStringBase<char> *)&start,
            v7,
            second - 1);
    v18 = middle;
    v19 = middle->m_buffer;
    v20 = v17;
    if ( middle->m_buffer != v17->m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v19->m_cRef) && v19 )
        v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
      v21 = v20->m_buffer;
      v18->m_buffer = v21;
      InterlockedIncrement((volatile LONG *)&v21->m_cRef);
    }
    v22 = start;
    if ( !InterlockedDecrement((volatile LONG *)&start[1]) && v22 )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v22->m_buffer->vfptr)(v22, 1);
    v13 = InterlockedDecrement;
  }
  v23 = v4->vfptr->GetStrLen((AC1Legacy::PStringBaseIter_Common<char> *)v4);
  v24 = AC1Legacy::PStringBase<char>::substring(v4->pstring_ptr, (AC1Legacy::PStringBase<char> *)&start, second, v23);
  v25 = end;
  v26 = end->m_buffer;
  v27 = (AC1Legacy::PSRefBuffer<char> **)v24;
  if ( end->m_buffer != v24->m_buffer )
  {
    if ( !v13((volatile LONG *)&v26->m_cRef) && v26 )
      v26->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v26, 1u);
    v28 = *v27;
    v25->m_buffer = *v27;
    InterlockedIncrement((volatile LONG *)&v28->m_cRef);
  }
  v29 = start;
  if ( !v13((volatile LONG *)&start[1]) && v29 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v29->m_buffer->vfptr)(v29, 1);
  return 1;
}

//----- (00683ED0) --------------------------------------------------------  // acclient.c:667347
int __thiscall AC1Legacy::PStringBaseIter<char>::Split(AC1Legacy::PStringBaseIter<char> *this, AC1Legacy::PStringBase<char> *start, AC1Legacy::PStringBase<char> *end)
{
  AC1Legacy::PStringBaseIter<char> *v3; // esi@1
  AC1Legacy::PStringBase<char> *v4; // eax@1
  AC1Legacy::PStringBase<char> *v5; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v6; // edi@1
  AC1Legacy::PStringBase<char> *v7; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v8; // ebx@5
  AC1Legacy::PSRefBuffer<char> *v9; // edi@6
  unsigned int v10; // eax@9
  AC1Legacy::PStringBase<char> *v11; // eax@9
  AC1Legacy::PStringBase<char> *v12; // ebx@9
  AC1Legacy::PSRefBuffer<char> *v13; // esi@9
  AC1Legacy::PSRefBuffer<char> **v14; // edi@9
  AC1Legacy::PSRefBuffer<char> *v15; // eax@13
  AC1Legacy::PStringBase<char> *v16; // esi@14
  AC1Legacy::PStringBase<char> result; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = AC1Legacy::PStringBase<char>::substring(this->pstring_ptr, &result, 0, this->curr - 1);
  v5 = start;
  v6 = start->m_buffer;
  v7 = v4;
  if ( start->m_buffer != v4->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v8 = v7->m_buffer;
    v5->m_buffer = v8;
    InterlockedIncrement((volatile LONG *)&v8->m_cRef);
  }
  v9 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v9 )
    v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  v10 = v3->vfptr->GetStrLen((AC1Legacy::PStringBaseIter_Common<char> *)v3);
  v11 = AC1Legacy::PStringBase<char>::substring(v3->pstring_ptr, (AC1Legacy::PStringBase<char> *)&start, v3->curr, v10);
  v12 = end;
  v13 = end->m_buffer;
  v14 = (AC1Legacy::PSRefBuffer<char> **)v11;
  if ( end->m_buffer != v11->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
      v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
    v15 = *v14;
    v12->m_buffer = *v14;
    InterlockedIncrement((volatile LONG *)&v15->m_cRef);
  }
  v16 = start;
  if ( !InterlockedDecrement((volatile LONG *)&start[1]) && v16 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v16->m_buffer->vfptr)(v16, 1);
  return 1;
}

//----- (00683FB0) --------------------------------------------------------  // acclient.c:667401
int __cdecl PSUtils::change_extension(AC1Legacy::PStringBase<char> *filename, AC1Legacy::PStringBase<char> *new_extension)
{
  AC1Legacy::PStringBase<char> *v2; // ebx@1
  unsigned int i; // eax@1
  AC1Legacy::PStringBase<char> *v4; // edi@7
  AC1Legacy::PSRefBuffer<char> *v5; // ecx@7
  unsigned int v6; // eax@7
  bool v7; // zf@8
  int v8; // eax@8
  AC1Legacy::PStringBase<char> *v9; // esi@11
  AC1Legacy::PSRefBuffer<char> *v10; // eax@11
  AC1Legacy::PSRefBuffer<char> *v11; // eax@16
  unsigned int v12; // ecx@16
  AC1Legacy::PStringBaseIter<char> iter; // [sp+8h] [bp-10h]@1

  v2 = filename;
  iter.vfptr = (AC1Legacy::PStringBaseIter_Common<char>Vtbl *)&AC1Legacy::PStringBaseIter<char>::vftable;
  iter.pstring_ptr = filename;
  iter.curr = 0;
  iter.mark = 0;
  for ( i = AC1Legacy::PStringBaseIter<char>::vftable(&iter); ; i = iter.curr )
  {
    if ( i < 1 )
    {
      iter.curr = 0;
      goto LABEL_7;
    }
    iter.curr = i - 1;
    if ( iter.vfptr->IndexToChar((AC1Legacy::PStringBaseIter_Common<char> *)&iter, i - 1) == 46 )
      break;
  }
  AC1Legacy::PStringBaseIter<char>::Truncate(&iter);
LABEL_7:
  v4 = new_extension;
  v5 = new_extension->m_buffer;
  v6 = new_extension->m_buffer->m_len;
  if ( v6 != 1 )
  {
    v7 = v6 == 0;
    v8 = (int)((char *)&v5->m_hash + v6 + 3);
    if ( !v7 )
      v8 = (int)v5->m_data;
    if ( *(_BYTE *)v8 != 46 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&filename, ".");
      v9 = filename;
      v10 = filename[2].m_buffer;
      if ( v10 != (AC1Legacy::PSRefBuffer<char> *)1
        && filename != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)&filename[5], (unsigned int)&v10[-1].m_data[3]);
      if ( !InterlockedDecrement((volatile LONG *)&v9[1]) )
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v9->m_buffer->vfptr)(v9, 1);
    }
  }
  v11 = v4->m_buffer;
  v12 = v4->m_buffer->m_len;
  if ( v12 != 1 && v11 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v2, v11->m_data, v12 - 1);
  return 1;
}
// 7FED9C: using guessed type int (__thiscall *AC1Legacy::PStringBaseIter<char>::vftable)(_DWORD);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006840A0) --------------------------------------------------------  // acclient.c:667465
int __cdecl PSUtils::narrowify(AC1Legacy::PStringBase<char> *dest, AC1Legacy::PStringBase<unsigned short> *org)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  AC1Legacy::PStringBase<char> result; // [sp+10h] [bp-4h]@1

  AC1Legacy::PStringBase<unsigned short>::to_spstring(org, &result, 0);
  v2 = dest->m_buffer;
  v3 = result.m_buffer;
  if ( dest->m_buffer != result.m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    dest->m_buffer = v3;
    InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return 1;
}

//----- (00684110) --------------------------------------------------------  // acclient.c:667487
AC1Legacy::PStringBase<char> *__cdecl PSUtils::narrowify(AC1Legacy::PStringBase<char> *result, AC1Legacy::PStringBase<unsigned short> *org)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  volatile LONG *v3; // edi@1
  volatile LONG *v4; // ST04_4@1
  AC1Legacy::PStringBase<char> ret; // [sp+10h] [bp-4h]@1

  ret.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  PSUtils::narrowify(&ret, org);
  v2 = ret.m_buffer;
  v3 = (volatile LONG *)&ret.m_buffer->m_cRef;
  v4 = (volatile LONG *)&ret.m_buffer->m_cRef;
  result->m_buffer = ret.m_buffer;
  InterlockedIncrement(v4);
  if ( !InterlockedDecrement(v3) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (007157B0) --------------------------------------------------------  // acclient.c:808482
int sub_7157B0()
{
  AC1Legacy::PStringBase<char>::PStringBase<char>(&ignore1_0, ".");
  return atexit(sub_77F740);
}

//----- (007157D0) --------------------------------------------------------  // acclient.c:808489
int _E76_96()
{
  AC1Legacy::PStringBase<char>::PStringBase<char>(&ignore2_0, "..");
  return atexit(sub_77F770);
}

//----- (0077F740) --------------------------------------------------------  // acclient.c:918090
void __cdecl sub_77F740()
{
  AC1Legacy::PSRefBuffer<char> *v0; // esi@1

  v0 = ignore1_0.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ignore1_0.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (0077F770) --------------------------------------------------------  // acclient.c:918103
void __cdecl sub_77F770()
{
  AC1Legacy::PSRefBuffer<char> *v0; // esi@1

  v0 = ignore2_0.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ignore2_0.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

