/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MasterStringTableGen
   Object     : ENGINE\stringtable\MasterStringTableGen.obj
   Functions  : 1
   Addresses  : 00430A20 - 00430A20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00430A20) --------------------------------------------------------  // acclient.c:109832
char __cdecl MasterStringTableGen::AddString(PStringBase<char> _fromFile, PStringBase<char> _stringTable, PStringBase<char> _stringToken, PStringBase<char> _stringEnglish, PStringBase<char> _stringComment)
{
  char bRetval; // [sp+29h] [bp-1h]@1

  bRetval = 0;
  if ( MasterStringTableGen::s_pStringTableGen )
  {
    InterlockedIncrement((volatile LONG *)&_stringComment.m_charbuffer[-1]);
    InterlockedIncrement((volatile LONG *)&_stringEnglish.m_charbuffer[-1]);
    InterlockedIncrement((volatile LONG *)&_stringToken.m_charbuffer[-1]);
    InterlockedIncrement((volatile LONG *)&_stringTable.m_charbuffer[-1]);
    InterlockedIncrement((volatile LONG *)&_fromFile.m_charbuffer[-1]);
    bRetval = ((int (__stdcall *)(PSRefBufferCharData<char> *, PSRefBufferCharData<char> *, PSRefBufferCharData<char> *, PSRefBufferCharData<char> *, PSRefBufferCharData<char> *))MasterStringTableGen::s_pStringTableGen->vfptr->AddString)(
                _fromFile.m_charbuffer,
                _stringTable.m_charbuffer,
                _stringToken.m_charbuffer,
                _stringEnglish.m_charbuffer,
                _stringComment.m_charbuffer);
  }
  if ( !InterlockedDecrement((volatile LONG *)&_fromFile.m_charbuffer[-1])
    && _fromFile.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_fromFile.m_charbuffer[-2].m_data[12])(
      &_fromFile.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&_stringTable.m_charbuffer[-1])
    && _stringTable.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_stringTable.m_charbuffer[-2].m_data[12])(
      &_stringTable.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&_stringToken.m_charbuffer[-1])
    && _stringToken.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_stringToken.m_charbuffer[-2].m_data[12])(
      &_stringToken.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&_stringEnglish.m_charbuffer[-1])
    && _stringEnglish.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_stringEnglish.m_charbuffer[-2].m_data[12])(
      &_stringEnglish.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&_stringComment.m_charbuffer[-1])
    && _stringComment.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_stringComment.m_charbuffer[-2].m_data[12])(
      &_stringComment.m_charbuffer[-2].m_data[12],
      1);
  return bRetval;
}
// 836F58: using guessed type struct StringTableGen *MasterStringTableGen::s_pStringTableGen;

