/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetInitializer
   Object     : PORTAL\newnet\NetInitializer.obj
   Functions  : 6
   Addresses  : 005AA6F0 - 00777660 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AA6F0) --------------------------------------------------------  // acclient.c:468044
NetInitializer::AllSocketsCrashCleaner *__thiscall NetInitializer::AllSocketsCrashCleaner::vector_deleting_destructor(NetInitializer::AllSocketsCrashCleaner *this, unsigned int a2)
{
  NetInitializer::AllSocketsCrashCleaner *v2; // esi@1

  v2 = this;
  CrashCleaner::~CrashCleaner((CrashCleaner *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005AA710) --------------------------------------------------------  // acclient.c:468056
void NetInitializer::NetInitializer()
{
  WSAData stWSAData; // [sp+4h] [bp-190h]@2

  ++NetInitializer::s_RefCount;
  if ( NetInitializer::s_RefCount == 1 )
    WSAStartup(0x101u, &stWSAData);
}
// 8EDFB8: using guessed type unsigned __int32 NetInitializer::s_RefCount;

//----- (005AA750) --------------------------------------------------------  // acclient.c:468067
void NetInitializer::~NetInitializer()
{
  --NetInitializer::s_RefCount;
  if ( !NetInitializer::s_RefCount )
    WSACleanup();
}
// 8EDFB8: using guessed type unsigned __int32 NetInitializer::s_RefCount;

//----- (005AA760) --------------------------------------------------------  // acclient.c:468076
void NetInitializer::AllSocketsCrashCleaner::CrashCleanup()
{
  while ( WSACleanup() != -1 )
    ;
}

//----- (0070DF20) --------------------------------------------------------  // acclient.c:800924
int sub_70DF20()
{
  CrashCleaner::CrashCleaner(&NetInitializer::S_sockerCleaner);
  NetInitializer::S_sockerCleaner.vfptr = (CPluginPrototypeVtbl *)&NetInitializer::AllSocketsCrashCleaner::vftable;
  return atexit(_E74_92);
}
// 7E5FEC: using guessed type int (__thiscall *NetInitializer::AllSocketsCrashCleaner::vftable)(void *, char);

//----- (00777660) --------------------------------------------------------  // acclient.c:911064
void __cdecl _E74_92()
{
  CrashCleaner::~CrashCleaner(&NetInitializer::S_sockerCleaner);
}

