/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetUtils
   Object     : PORTAL\newnet\NetUtils.obj
   Functions  : 3
   Addresses  : 005AA450 - 0070DEF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AA450) --------------------------------------------------------  // acclient.c:467880
char __cdecl NetUtils::GetSinAddr(const char *host, in_addr *retVal)
{
  unsigned __int32 v2; // eax@1
  char result; // al@2
  struct hostent *v4; // eax@3

  NetInitializer::NetInitializer();
  v2 = inet_addr(host);
  if ( v2 == -1 )
  {
    v4 = gethostbyname(host);
    if ( v4 )
    {
      qmemcpy(retVal, *(const void **)v4->h_addr_list, v4->h_length);
      NetInitializer::~NetInitializer();
      result = 1;
    }
    else
    {
      WSAGetLastError();
      NetInitializer::~NetInitializer();
      result = 0;
    }
  }
  else
  {
    retVal->S_un.S_addr = v2;
    NetInitializer::~NetInitializer();
    result = 1;
  }
  return result;
}

//----- (005AA4D0) --------------------------------------------------------  // acclient.c:467914
void __cdecl NetUtils::GetIPString(sockaddr_in *addr, AC1Legacy::PStringBase<char> *result, bool fShortFormat)
{
  const char *v3; // edi@1
  u_short v4; // ax@3
  char ipstring[40]; // [sp+8h] [bp-28h]@1

  ipstring[39] = 0;
  v3 = "%d.%d.%d.%d:%d";
  if ( !fShortFormat )
    v3 = "%d.%d.%d.%d - Port:%d";
  v4 = ntohs(addr->sin_port);
  __snprintf(
    ipstring,
    0x27u,
    v3,
    addr->sin_addr.S_un.S_un_b.s_b1,
    addr->sin_addr.S_un.S_un_b.s_b2,
    addr->sin_addr.S_un.S_un_b.s_b3,
    addr->sin_addr.S_un.S_un_b.s_b4,
    v4);
  AC1Legacy::PStringBase<char>::set(result, ipstring);
}

//----- (0070DEF0) --------------------------------------------------------  // acclient.c:800898
int _E77_22()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_44;
  dword_8EDFA8 = LOWEST_DATA_RATE_44;
  return result;
}

