/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AvailableProperty
   Object     : ENGINE\property\AvailableProperty.obj
   Functions  : 3
   Addresses  : 0042C430 - 007281F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042C430) --------------------------------------------------------  // acclient.c:105423
void __thiscall AvailableProperty::operator=(AvailableProperty *this, AvailableProperty *rhs)
{
  if ( this != rhs )
    this->m_name = rhs->m_name;
}

//----- (006C5700) --------------------------------------------------------  // acclient.c:733752
int _E73_22()
{
  KW_NULL_0.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E74_25);
}

//----- (007281F0) --------------------------------------------------------  // acclient.c:825969
void __cdecl _E74_25()
{
  char *v0; // esi@1

  v0 = &KW_NULL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

