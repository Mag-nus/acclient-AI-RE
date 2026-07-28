/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : String
   Object     : PORTAL\string\String.obj
   Functions  : 5
   Addresses  : 005AE190 - 0070E320 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AE190) --------------------------------------------------------  // acclient.c:472424
void __thiscall String::String(String *this, IDClass<_tagDataID,32,0> gid)
{
  String *v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v2->vfptr = (InterfaceVtbl *)&String::vftable;
}
// 7E6110: using guessed type __int32 (__stdcall *String::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005AE1C0) --------------------------------------------------------  // acclient.c:472439
signed int String::GetDBOType()
{
  return 41;
}

//----- (005AE1E0) --------------------------------------------------------  // acclient.c:472445
DBObj *__thiscall String::scalar_deleting_destructor(String *this, unsigned int a2)
{
  DBObj *v2; // edi@1
  char *v3; // esi@1

  v2 = (DBObj *)this;
  this->vfptr = (InterfaceVtbl *)&String::vftable;
  v3 = &this->m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  DBObj::~DBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E6110: using guessed type __int32 (__stdcall *String::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005AE230) --------------------------------------------------------  // acclient.c:472463
void __thiscall String::Serialize(String *this, Archive *io_archive)
{
  String *v2; // esi@1

  v2 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  PStringBase<char>::Serialize((PStringBase<char> *)&v2->m_charbuffer, io_archive);
}

//----- (0070E320) --------------------------------------------------------  // acclient.c:801208
int sub_70E320()
{
  return atexit(nullsub_1542);
}

