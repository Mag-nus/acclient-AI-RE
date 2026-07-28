/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PStringDecls
   Object     : PORTAL\pstring\PStringDecls.obj
   Functions  : 14
   Addresses  : 0070E200 - 007777B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0070E200) --------------------------------------------------------  // acclient.c:801111
void *sub_70E200()
{
  void *result; // eax@1

  result = operator new(0x18u);
  if ( result )
  {
    *((_DWORD *)result + 1) = 1;
    *(_DWORD *)result = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)result + 2) = 1;
    *((_DWORD *)result + 3) = 1;
    *((_DWORD *)result + 4) = -1;
    *((_BYTE *)result + 20) = 0;
    AC1Legacy::PStringBase<char>::s_NullBuffer = (int)result;
  }
  else
  {
    AC1Legacy::PStringBase<char>::s_NullBuffer = 0;
  }
  return result;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070E240) --------------------------------------------------------  // acclient.c:801136
int _E75_0()
{
  AC1Legacy::PStringBase<char>::null_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  return atexit(sub_7776C0);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070E260) --------------------------------------------------------  // acclient.c:801145
int _E78()
{
  AC1Legacy::PStringBase<char>::PStringBase<char>(&AC1Legacy::PStringBase<char>::whitespace_string, " \n\r\t\f");
  return atexit(sub_7776F0);
}

//----- (0070E280) --------------------------------------------------------  // acclient.c:801152
int _E81_0()
{
  return atexit(_E82_77);
}

//----- (0070E290) --------------------------------------------------------  // acclient.c:801158
void *_E84()
{
  void *result; // eax@1

  result = operator new(0x18u);
  if ( result )
  {
    *((_DWORD *)result + 1) = 1;
    *(_DWORD *)result = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)result + 2) = 1;
    *((_DWORD *)result + 3) = 1;
    *((_DWORD *)result + 4) = -1;
    *((_WORD *)result + 10) = 0;
    AC1Legacy::PStringBase<unsigned short>::s_NullBuffer = (int)result;
  }
  else
  {
    AC1Legacy::PStringBase<unsigned short>::s_NullBuffer = 0;
  }
  return result;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (0070E2D0) --------------------------------------------------------  // acclient.c:801183
int _E86()
{
  AC1Legacy::PStringBase<unsigned short>::null_string = AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4));
  return atexit(_E87_1);
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
// 8EE120: using guessed type int AC1Legacy::PStringBase<unsigned short>::null_string;

//----- (0070E2F0) --------------------------------------------------------  // acclient.c:801193
int _E89_11()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &AC1Legacy::PStringBase<unsigned short>::whitespace_string,
    L" \n\r\t\f");
  return atexit(_E90_5);
}

//----- (0070E310) --------------------------------------------------------  // acclient.c:801202
int _E92_6()
{
  return atexit(sub_7777B0);
}

//----- (007776C0) --------------------------------------------------------  // acclient.c:911070
void __cdecl sub_7776C0()
{
  AC1Legacy::PSRefBuffer<char> *v0; // esi@1

  v0 = AC1Legacy::PStringBase<char>::null_string.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&AC1Legacy::PStringBase<char>::null_string.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (007776F0) --------------------------------------------------------  // acclient.c:911083
void __cdecl sub_7776F0()
{
  AC1Legacy::PSRefBuffer<char> *v0; // esi@1

  v0 = AC1Legacy::PStringBase<char>::whitespace_string.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&AC1Legacy::PStringBase<char>::whitespace_string.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00777720) --------------------------------------------------------  // acclient.c:911096
void __cdecl _E82_77()
{
  int v0; // esi@1

  v0 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  if ( !InterlockedDecrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4)) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00777750) --------------------------------------------------------  // acclient.c:911110
void __cdecl _E87_1()
{
  int v0; // esi@1

  v0 = AC1Legacy::PStringBase<unsigned short>::null_string;
  if ( !InterlockedDecrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::null_string + 4)) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}
// 8EE120: using guessed type int AC1Legacy::PStringBase<unsigned short>::null_string;

//----- (00777780) --------------------------------------------------------  // acclient.c:911124
void __cdecl _E90_5()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = AC1Legacy::PStringBase<unsigned short>::whitespace_string.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&AC1Legacy::PStringBase<unsigned short>::whitespace_string.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (007777B0) --------------------------------------------------------  // acclient.c:911137
void __cdecl sub_7777B0()
{
  int v0; // esi@1

  v0 = AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  if ( !InterlockedDecrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4)) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

