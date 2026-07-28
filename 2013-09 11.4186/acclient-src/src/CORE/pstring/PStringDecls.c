/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PStringDecls
   Object     : CORE\pstring\PStringDecls.obj
   Functions  : 8
   Addresses  : 006C3960 - 00725C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C3960) --------------------------------------------------------  // acclient.c:731998
int _E73_3()
{
  InterlockedIncrement((volatile LONG *)&s_SPString_Null.m_charbuffer[-1]);
  return atexit(_E74_5);
}

//----- (006C3980) --------------------------------------------------------  // acclient.c:732005
int _E76_2()
{
  PStringBase<char>::whitespace_string.m_charbuffer = s_SPString_Whitespace.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&s_SPString_Whitespace.m_charbuffer[-1]);
  return atexit(_E77_30);
}

//----- (006C39A0) --------------------------------------------------------  // acclient.c:732013
int _E79_2()
{
  PStringBase<unsigned short>::null_string.m_charbuffer = s_WPString_Null.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&s_WPString_Null.m_charbuffer[-1].m_data[8]);
  return atexit(_E80_4);
}

//----- (006C39C0) --------------------------------------------------------  // acclient.c:732021
int _E82_0()
{
  PStringBase<unsigned short>::whitespace_string = s_WPString_Whitespace.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&s_WPString_Whitespace.m_charbuffer[-1].m_data[8]);
  return atexit(_E83_0);
}

//----- (00725B80) --------------------------------------------------------  // acclient.c:823527
void __cdecl _E74_5()
{
  char *v0; // esi@1

  v0 = &PStringBase<char>::null_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725BB0) --------------------------------------------------------  // acclient.c:823540
void __cdecl _E77_30()
{
  char *v0; // esi@1

  v0 = &PStringBase<char>::whitespace_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725BE0) --------------------------------------------------------  // acclient.c:823553
void __cdecl _E80_4()
{
  char *v0; // esi@1

  v0 = (char *)&PStringBase<unsigned short>::null_string.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&PStringBase<unsigned short>::null_string.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725C10) --------------------------------------------------------  // acclient.c:823566
void __cdecl _E83_0()
{
  char *v0; // esi@1

  v0 = (char *)PStringBase<unsigned short>::whitespace_string - 20;
  if ( !InterlockedDecrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

