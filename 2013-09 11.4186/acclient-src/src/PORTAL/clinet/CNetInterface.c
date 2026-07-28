/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CNetInterface
   Object     : PORTAL\clinet\CNetInterface.obj
   Functions  : 4
   Addresses  : 00548C40 - 00705690 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00548C40) --------------------------------------------------------  // acclient.c:376145
void __thiscall NetInterface::NetInterface(NetInterface *this)
{
  NetInterface::netInterface_ = this;
}

//----- (00548C50) --------------------------------------------------------  // acclient.c:376151
int NetInterface::GetNonEphemeralID()
{
  PacketController *v1; // eax@1

  v1 = PacketController::Instance();
  return v1->vfptr->GetNonEphemeralID(v1);
}

//----- (00705680) --------------------------------------------------------  // acclient.c:792690
int _E77_12()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_29;
  dword_845F68 = LOWEST_DATA_RATE_29;
  return result;
}

//----- (00705690) --------------------------------------------------------  // acclient.c:792700
int sub_705690()
{
  return atexit(nullsub_1217);
}

