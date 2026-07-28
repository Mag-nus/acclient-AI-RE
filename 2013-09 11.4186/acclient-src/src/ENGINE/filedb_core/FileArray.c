/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FileArray
   Object     : ENGINE\filedb_core\FileArray.obj
   Functions  : 5
   Addresses  : 00678190 - 00714FA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00678190) --------------------------------------------------------  // acclient.c:654796
IDClass<_tagDataID,32,0> *__cdecl FileArray::GetDID(IDClass<_tagDataID,32,0> *result, PStringBase<char> *filename, const unsigned int otype)
{
  IDClass<_tagDataID,32,0> *v3; // eax@2

  if ( *(_DWORD *)&filename->m_charbuffer[-1].m_data[12] == 1 )
  {
    v3 = result;
  }
  else
  {
    v3 = result;
    if ( !otype )
    {
      result->id = stru_8F7700.id;
      return v3;
    }
  }
  v3->id = stru_8F7700.id;
  return v3;
}

//----- (006781C0) --------------------------------------------------------  // acclient.c:654818
PStringBase<char> *__cdecl FileArray::GetRelativeFilePath(PStringBase<char> *result)
{
  volatile LONG *v1; // ST00_4@1

  v1 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
  result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
  InterlockedIncrement(v1);
  return result;
}

//----- (006781E0) --------------------------------------------------------  // acclient.c:654829
PStringBase<char> *__cdecl FileArray::GetFileNameForDummies(PStringBase<char> *result, IDClass<_tagDataID,32,0> did)
{
  volatile LONG *v2; // ST00_4@2
  PStringBase<char> *v3; // eax@2
  volatile LONG *v4; // ST00_4@3

  if ( did.id == stru_8F7700.id )
  {
    v2 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v2);
    v3 = result;
  }
  else
  {
    MasterDBMap::DivineType(did);
    v4 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v4);
    v3 = result;
  }
  return v3;
}

//----- (00678230) --------------------------------------------------------  // acclient.c:654854
PStringBase<char> *__cdecl FileArray::GetAbsoluteFilePathForDummies(PStringBase<char> *result, PStringBase<char> *filename)
{
  volatile LONG *v2; // ST00_4@2
  PStringBase<char> *v3; // eax@2
  volatile LONG *v4; // ST00_4@3

  if ( MasterDBMap::DivineType(filename) )
  {
    v4 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v4);
    v3 = result;
  }
  else
  {
    v2 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v2);
    v3 = result;
  }
  return v3;
}

//----- (00714FA0) --------------------------------------------------------  // acclient.c:807901
int sub_714FA0()
{
  return atexit(nullsub_123);
}

