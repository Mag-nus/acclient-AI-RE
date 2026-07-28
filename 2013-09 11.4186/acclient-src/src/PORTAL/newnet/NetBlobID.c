/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetBlobID
   Object     : PORTAL\newnet\NetBlobID.obj
   Functions  : 8
   Addresses  : 005AA300 - 0070DEE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AA300) --------------------------------------------------------  // acclient.c:467807
BOOL __cdecl NetBlobIDUtils::IsEphemeralFlagSet(unsigned __int64 _id)
{
  return (HIDWORD(_id) & 0x80000000) != 0;
}

//----- (005AA320) --------------------------------------------------------  // acclient.c:467813
unsigned __int64 __cdecl NetBlobIDUtils::GetOrderingType(unsigned __int64 _id)
{
  return _id & 0x1F00000000000000i64;
}

//----- (005AA330) --------------------------------------------------------  // acclient.c:467819
unsigned __int64 __cdecl NetBlobIDUtils::GetSequenceID(unsigned __int64 _id)
{
  return _id & 0xFF0000FFFFFFFFi64;
}

//----- (005AA340) --------------------------------------------------------  // acclient.c:467825
int __cdecl NetBlobIDUtils::MakeInitialSequenceID(unsigned int _serverID)
{
  int result; // eax@1

  result = 0;
  if ( ((_serverID << 16) & 0xFF0000) != _serverID << 16 )
    result = 0;
  return result;
}

//----- (005AA370) --------------------------------------------------------  // acclient.c:467836
int __cdecl NetBlobIDUtils::MakeNetBlobID(unsigned __int64 _eventType, unsigned __int16 _orderingStamp, unsigned __int64 _sequenceID)
{
  int v3; // ebx@1

  v3 = _eventType;
  if ( __PAIR__(HIDWORD(_eventType) & 0xFF000000, 0) != _eventType )
    v3 = 0;
  return _sequenceID | v3;
}

//----- (005AA3D0) --------------------------------------------------------  // acclient.c:467847
int __cdecl NetBlobIDUtils::NextNonEphemeralSequenceID(unsigned __int64 _seqID)
{
  return _seqID + 1;
}

//----- (005AA400) --------------------------------------------------------  // acclient.c:467853
bool __cdecl NetBlobIDUtils::LHSNewerOrderingStamp(unsigned __int64 _lhs, unsigned __int64 _rhs)
{
  bool result; // al@2
  unsigned __int16 v3; // dx@3
  int v4; // esi@3

  if ( WORD2(_lhs) == WORD2(_rhs) )
  {
    result = 0;
  }
  else
  {
    v3 = WORD2(_lhs) - WORD2(_rhs);
    v4 = 1;
    if ( WORD2(_lhs) < WORD2(_rhs) )
    {
      v3 = WORD2(_rhs) - WORD2(_lhs);
      v4 = -1;
    }
    if ( v3 > 0x7FFFu )
      v4 = -v4;
    result = v4 > 0;
  }
  return result;
}

//----- (0070DEE0) --------------------------------------------------------  // acclient.c:800888
int _E77_21()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_43;
  dword_8EDFA4 = LOWEST_DATA_RATE_43;
  return result;
}

