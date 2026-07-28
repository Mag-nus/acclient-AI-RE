/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Turbine_GUID
   Object     : CORE\tcom_interface\Turbine_GUID.obj
   Functions  : 2
   Addresses  : 0040FA70 - 0040FB20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040FA70) --------------------------------------------------------  // acclient.c:75521
char __thiscall Turbine_GUID::Convert(Turbine_GUID *this, const char *const _pString)
{
  Turbine_GUID *v2; // esi@1
  char *v3; // ebx@1
  char *v4; // ebp@1
  char *v5; // edi@1
  char result; // al@2
  __int16 v7; // cx@3
  __int16 v8; // dx@3
  char *v9; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = &this->m_data4[4];
  v4 = &this->m_data4[2];
  v5 = this->m_data4;
  v9 = (char *)&this->m_data2;
  if ( _sscanf(
         _pString,
         "%08lX-%04hX-%04hX-%04hX-%04hX%08lX",
         this,
         &this->m_data2,
         &this->m_data3,
         this->m_data4,
         &this->m_data4[2],
         &this->m_data4[4]) == 6 )
  {
    LOBYTE(v7) = *(_WORD *)v5 >> 8;
    HIBYTE(v7) = *(_WORD *)v5;
    *(_WORD *)v5 = v7;
    LOBYTE(v8) = *(_WORD *)v4 >> 8;
    HIBYTE(v8) = *(_WORD *)v4;
    *(_WORD *)v4 = v8;
    *(_DWORD *)v3 = (((*(_DWORD *)v3 << 16) | *(_DWORD *)v3 & 0xFF00) << 8) | (((*(_DWORD *)v3 >> 16) | *(_DWORD *)v3 & 0xFF0000u) >> 8);
    result = 1;
  }
  else
  {
    *(_DWORD *)v5 = 0;
    v2->m_data1 = 0;
    *(_DWORD *)v9 = 0;
    *(_DWORD *)v3 = 0;
    result = 0;
  }
  return result;
}

//----- (0040FB20) --------------------------------------------------------  // acclient.c:75568
PStringBase<char> *__thiscall Turbine_GUID::ToString(Turbine_GUID *this, PStringBase<char> *result)
{
  Turbine_GUID *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST30_4@1
  int v5; // esi@1
  PStringBase<char> str; // [sp+0h] [bp-4h]@1

  str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(
    &str,
    "%08X-%04hX-%04hX-%02X%02X-%02X%02X%02X%02X%02X%02X",
    v2->m_data1,
    v2->m_data2,
    v2->m_data3,
    v2->m_data4[0],
    v2->m_data4[1],
    v2->m_data4[2],
    v2->m_data4[3],
    v2->m_data4[4],
    v2->m_data4[5],
    v2->m_data4[6],
    v2->m_data4[7]);
  v3 = str.m_charbuffer;
  v4 = (volatile LONG *)&str.m_charbuffer[-1];
  result->m_charbuffer = str.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

