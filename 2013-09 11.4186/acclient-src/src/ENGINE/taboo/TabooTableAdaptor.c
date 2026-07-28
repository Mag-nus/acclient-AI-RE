/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TabooTableAdaptor
   Object     : ENGINE\taboo\TabooTableAdaptor.obj
   Functions  : 1
   Addresses  : 00682A30 - 00682A30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00682A30) --------------------------------------------------------  // acclient.c:666093
signed int __cdecl TabooTableAdaptor::CheckCensorsW(PStringBase<unsigned short> *strToCheck, unsigned int audience, unsigned int chkType, PStringBase<unsigned short> *tabooPatternMatchOut)
{
  int v4; // esi@1
  signed int result; // eax@2
  unsigned int v6; // edi@3

  v4 = DBObj::GetByEnum(17, 2, 0x14u);
  if ( v4 )
  {
    v6 = TabooTable::CheckCensorsW((TabooTable *)v4, strToCheck, audience, chkType, tabooPatternMatchOut);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    result = v6;
  }
  else
  {
    result = 2;
  }
  return result;
}

