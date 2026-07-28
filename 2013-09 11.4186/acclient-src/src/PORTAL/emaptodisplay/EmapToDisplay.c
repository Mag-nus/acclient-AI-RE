/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EmapToDisplay
   Object     : PORTAL\emaptodisplay\EmapToDisplay.obj
   Functions  : 2
   Addresses  : 005A91B0 - 005A9260 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A91B0) --------------------------------------------------------  // acclient.c:466844
AC1Legacy::PStringBase<char> *__thiscall AC1Legacy::PStringBase<char>::substring(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *result, unsigned int first, unsigned int last)
{
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  volatile LONG *v5; // esi@1
  AC1Legacy::PStringBase<char> *v6; // ebx@1
  unsigned int v7; // ecx@1
  AC1Legacy::PStringBase<char> *v8; // ebx@2
  unsigned int v10; // eax@5
  AC1Legacy::PSRefBuffer<char> *v11; // edi@7
  volatile LONG *v12; // esi@7
  volatile LONG *v13; // ST04_4@7
  AC1Legacy::PStringBase<char> retval; // [sp+10h] [bp-4h]@1

  v4 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v6 = this;
  retval.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v7 = v6->m_buffer->m_len - 1;
  if ( first < v7 )
  {
    v10 = last;
    if ( last >= v7 )
      v10 = v6->m_buffer->m_len - 2;
    AC1Legacy::PStringBase<char>::append_n_chars(&retval, &v6->m_buffer->m_data[first], v10 - first + 1);
    v11 = retval.m_buffer;
    v8 = result;
    v12 = (volatile LONG *)&retval.m_buffer->m_cRef;
    v13 = (volatile LONG *)&retval.m_buffer->m_cRef;
    result->m_buffer = retval.m_buffer;
    InterlockedIncrement(v13);
    if ( !InterlockedDecrement(v12) && v11 )
      v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  }
  else
  {
    v8 = result;
    result->m_buffer = v4;
    InterlockedIncrement(v5);
    if ( !InterlockedDecrement(v5) && v4 )
    {
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
      return result;
    }
  }
  return v8;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005A9260) --------------------------------------------------------  // acclient.c:466894
int __cdecl EmapToDisplay::LowerCaseRemoveUnderscores(AC1Legacy::PStringBase<char> *instring, AC1Legacy::PStringBase<char> *outstring)
{
  AC1Legacy::PStringBase<char> *v2; // ebp@1
  int result; // eax@2
  AC1Legacy::PStringBase<char> *v4; // edi@3
  AC1Legacy::PSRefBuffer<char> *v5; // esi@3
  AC1Legacy::PSRefBuffer<char> *v6; // eax@7
  AC1Legacy::PStringBase<char> *v7; // esi@8
  AC1Legacy::PSRefBuffer<char> *v8; // esi@11
  AC1Legacy::PStringBase<char> strFind; // [sp+8h] [bp-4h]@8

  v2 = instring;
  if ( instring->m_buffer->m_len == 1 )
  {
    result = 0;
  }
  else
  {
    v4 = outstring;
    v5 = outstring->m_buffer;
    if ( outstring->m_buffer != instring->m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      v6 = v2->m_buffer;
      v4->m_buffer = v2->m_buffer;
      InterlockedIncrement((volatile LONG *)&v6->m_cRef);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&strFind, "_");
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&instring, " ");
    AC1Legacy::PStringBase<char>::replace(v4, &strFind, (AC1Legacy::PStringBase<char> *)&instring);
    AC1Legacy::PStringBase<char>::break_reference(v4);
    __strlwr(v4->m_buffer->m_data);
    v7 = instring;
    if ( !InterlockedDecrement((volatile LONG *)&instring[1]) && v7 )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v7->m_buffer->vfptr)(v7, 1);
    v8 = strFind.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strFind.m_buffer->m_cRef) )
    {
      if ( v8 )
        v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    }
    result = 1;
  }
  return result;
}

