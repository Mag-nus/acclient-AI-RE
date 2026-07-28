/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DataFilePropertyValue
   Object     : ENGINE\property\DataFilePropertyValue.obj
   Functions  : 2
   Addresses  : 0042B1A0 - 006C5690 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042B1A0) --------------------------------------------------------  // acclient.c:104100
char __thiscall DataFilePropertyValue::GetValueAsString(DataFilePropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  DataFilePropertyValue *v4; // esi@1
  PStringBase<char> *v5; // edi@2
  unsigned int v6; // ST08_4@3
  unsigned int v7; // ST04_4@3
  PStringBase<char> *v8; // eax@3
  int v9; // esi@5

  v4 = this;
  if ( this->m_value.id )
  {
    v5 = _value;
    PStringBase<char>::sprintf(_value, "0x%08X", this->m_value.id);
    if ( _desc->m_propertyType != 10 )
      return 0;
    v6 = _desc->m_data;
    v7 = v4->m_value.id;
    FileArray::GetRelativeFilePath((PStringBase<char> *)&_value);
    v8 = _value;
    if ( _value[-1].m_charbuffer != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::sprintf(v5, "%s", _value);
      v8 = _value;
    }
    v9 = (int)&v8[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-4]) && v9 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      return 1;
    }
  }
  else
  {
    PStringBase<char>::sprintf(_value, "<file unset>");
  }
  return 1;
}

//----- (006C5690) --------------------------------------------------------  // acclient.c:733714
int _E1_21()
{
  return atexit(_E2_21);
}

