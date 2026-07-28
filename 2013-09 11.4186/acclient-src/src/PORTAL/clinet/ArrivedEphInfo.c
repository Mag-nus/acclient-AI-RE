/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArrivedEphInfo
   Object     : PORTAL\clinet\ArrivedEphInfo.obj
   Functions  : 5
   Addresses  : 0054ADB0 - 00705760 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0054ADB0) --------------------------------------------------------  // acclient.c:378545
void __thiscall ArrivedEphInfo::ArrivedEphInfo(ArrivedEphInfo *this, unsigned __int64 _sequence, unsigned __int64 _netBlobID)
{
  unsigned int v3; // edx@1

  LODWORD(this->id) = _sequence;
  this->hash_next = 0;
  HIDWORD(this->id) = HIDWORD(_sequence);
  this->m_next = 0;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  this->m_latestNetBlobID = _netBlobID;
  v3 = Timer::cur_time.Param;
  LODWORD(this->m_timeStamp) = Timer::cur_time.Cmd;
  HIDWORD(this->m_timeStamp) = v3;
}
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);

//----- (0054AE00) --------------------------------------------------------  // acclient.c:378562
void __thiscall ArrivedEphInfo::UpdateNetBlobID(ArrivedEphInfo *this, unsigned __int64 _netBlobID)
{
  unsigned int v2; // edx@1

  this->m_latestNetBlobID = _netBlobID;
  v2 = Timer::cur_time.Param;
  LODWORD(this->m_timeStamp) = Timer::cur_time.Cmd;
  HIDWORD(this->m_timeStamp) = v2;
}

//----- (0054AE30) --------------------------------------------------------  // acclient.c:378573
BOOL __thiscall ArrivedEphInfo::fTimedOut(ArrivedEphInfo *this)
{
  return COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_timeStamp > 5.0;
}

//----- (0054AE50) --------------------------------------------------------  // acclient.c:378579
ArrivedEphInfo *__thiscall ArrivedEphInfo::scalar_deleting_destructor(ArrivedEphInfo *this, unsigned int a2)
{
  ArrivedEphInfo *v2; // esi@1

  v2 = this;
  this->hash_next = 0;
  this->id = 0i64;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);

//----- (00705760) --------------------------------------------------------  // acclient.c:792802
int _E77_19()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_36;
  dword_845FB8 = LOWEST_DATA_RATE_36;
  return result;
}

