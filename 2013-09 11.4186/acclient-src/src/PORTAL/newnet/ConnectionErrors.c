/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ConnectionErrors
   Object     : PORTAL\newnet\ConnectionErrors.obj
   Functions  : 43
   Addresses  : 0070D9C0 - 00777640 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0070D9C0) --------------------------------------------------------  // acclient.c:800568
int sub_70D9C0()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_NetError_BadServerAddress");
  ID_NetError_BadServerAddress.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDEB8 = v0;
  dword_8EDEBC = 8;
  return atexit(_E74_91);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDEB4: using guessed type const struct NetError ID_NetError_BadServerAddress;
// 8EDEB8: using guessed type int dword_8EDEB8;
// 8EDEBC: using guessed type int dword_8EDEBC;

//----- (0070DA00) --------------------------------------------------------  // acclient.c:800584
int _E76_75()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_NetError_CantBind");
  ID_NetError_CantBind.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDEC4 = v0;
  dword_8EDEC8 = 8;
  return atexit(sub_777510);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDEC0: using guessed type const struct NetError ID_NetError_CantBind;
// 8EDEC4: using guessed type int dword_8EDEC4;
// 8EDEC8: using guessed type int dword_8EDEC8;

//----- (0070DA40) --------------------------------------------------------  // acclient.c:800600
int _E79_69()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_NetError_CantSocket");
  ID_NetError_CantSocket.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDED0 = v0;
  dword_8EDED4 = 8;
  return atexit(_E80_68);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDECC: using guessed type const struct NetError ID_NetError_CantSocket;
// 8EDED0: using guessed type int dword_8EDED0;
// 8EDED4: using guessed type int dword_8EDED4;

//----- (0070DA80) --------------------------------------------------------  // acclient.c:800616
int _E82_46()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_NetError_CantCrypto");
  ID_NetError_CantCrypto.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDEDC = v0;
  dword_8EDEE0 = 8;
  return atexit(_E83_44);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDED8: using guessed type const struct NetError ID_NetError_CantCrypto;
// 8EDEDC: using guessed type int dword_8EDEDC;
// 8EDEE0: using guessed type int dword_8EDEE0;

//----- (0070DAC0) --------------------------------------------------------  // acclient.c:800632
int _E85_31()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_NetError_AbortedHandshake");
  ID_NetError_AbortedHandshake.vfptr = (PackObjVtbl *)&NetError::vftable;
  ID_NetError_AbortedHandshake.m_stringID = v0;
  ID_NetError_AbortedHandshake.m_tableID = 8;
  return atexit(_E86_25);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (0070DB00) --------------------------------------------------------  // acclient.c:800645
int _E88_22()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_RunningSpeedhack");
  ID_ConnectionError_RunningSpeedhack.vfptr = (PackObjVtbl *)&NetError::vftable;
  ID_ConnectionError_RunningSpeedhack.m_stringID = v0;
  ID_ConnectionError_RunningSpeedhack.m_tableID = 8;
  return atexit(_E89_35);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (0070DB40) --------------------------------------------------------  // acclient.c:800658
int sub_70DB40()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_NoLogonServer");
  ID_ConnectionError_NoLogonServer.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF00 = v0;
  dword_8EDF04 = 8;
  return atexit(_E92_40);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDEFC: using guessed type const struct NetError ID_ConnectionError_NoLogonServer;
// 8EDF00: using guessed type int dword_8EDF00;
// 8EDF04: using guessed type int dword_8EDF04;

//----- (0070DB80) --------------------------------------------------------  // acclient.c:800674
int _E94_31()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_NetVersionMismatch");
  ID_ConnectionError_NetVersionMismatch.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF0C = v0;
  dword_8EDF10 = 8;
  return atexit(sub_777570);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF08: using guessed type const struct NetError ID_ConnectionError_NetVersionMismatch;
// 8EDF0C: using guessed type int dword_8EDF0C;
// 8EDF10: using guessed type int dword_8EDF10;

//----- (0070DBC0) --------------------------------------------------------  // acclient.c:800690
int sub_70DBC0()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_ServerFull");
  ID_ConnectionError_ServerFull.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF18 = v0;
  dword_8EDF1C = 8;
  return atexit(sub_777580);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF14: using guessed type const struct NetError ID_ConnectionError_ServerFull;
// 8EDF18: using guessed type int dword_8EDF18;
// 8EDF1C: using guessed type int dword_8EDF1C;

//----- (0070DC00) --------------------------------------------------------  // acclient.c:800706
int sub_70DC00()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_BadCryptoKey");
  ID_ConnectionError_BadCryptoKey.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF24 = v0;
  dword_8EDF28 = 8;
  return atexit(sub_777590);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF20: using guessed type const struct NetError ID_ConnectionError_BadCryptoKey;
// 8EDF24: using guessed type int dword_8EDF24;
// 8EDF28: using guessed type int dword_8EDF28;

//----- (0070DC40) --------------------------------------------------------  // acclient.c:800722
int sub_70DC40()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_InsufficientPriveledge");
  ID_ConnectionError_InsufficientPriveledge.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF30 = v0;
  dword_8EDF34 = 8;
  return atexit(sub_7775A0);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF2C: using guessed type const struct NetError ID_ConnectionError_InsufficientPriveledge;
// 8EDF30: using guessed type int dword_8EDF30;
// 8EDF34: using guessed type int dword_8EDF34;

//----- (0070DC80) --------------------------------------------------------  // acclient.c:800738
int sub_70DC80()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_SecondLogon");
  ID_ConnectionError_SecondLogon.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF3C = v0;
  dword_8EDF40 = 8;
  return atexit(_E107_98);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF38: using guessed type const struct NetError ID_ConnectionError_SecondLogon;
// 8EDF3C: using guessed type int dword_8EDF3C;
// 8EDF40: using guessed type int dword_8EDF40;

//----- (0070DCC0) --------------------------------------------------------  // acclient.c:800754
int _E109_82()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_ServerClosedConnection");
  ID_ConnectionError_ServerClosedConnection.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF48 = v0;
  dword_8EDF4C = 8;
  return atexit(sub_7775C0);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF44: using guessed type const struct NetError ID_ConnectionError_ServerClosedConnection;
// 8EDF48: using guessed type int dword_8EDF48;
// 8EDF4C: using guessed type int dword_8EDF4C;

//----- (0070DD00) --------------------------------------------------------  // acclient.c:800770
int sub_70DD00()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_ServerTimedOutClient");
  ID_ConnectionError_ServerTimedOutClient.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF54 = v0;
  dword_8EDF58 = 8;
  return atexit(_E113_70);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF50: using guessed type const struct NetError ID_ConnectionError_ServerTimedOutClient;
// 8EDF54: using guessed type int dword_8EDF54;
// 8EDF58: using guessed type int dword_8EDF58;

//----- (0070DD40) --------------------------------------------------------  // acclient.c:800786
int _E115_88()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_ClientTimedOutServer");
  ID_ConnectionError_ClientTimedOutServer.vfptr = (PackObjVtbl *)&NetError::vftable;
  ID_ConnectionError_ClientTimedOutServer.m_stringID = v0;
  ID_ConnectionError_ClientTimedOutServer.m_tableID = 8;
  return atexit(_E116_62);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (0070DD80) --------------------------------------------------------  // acclient.c:800799
int _E118_80()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_PlayerAlreadyLoggedOn");
  ID_ConnectionError_PlayerAlreadyLoggedOn.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF6C = v0;
  dword_8EDF70 = 8;
  return atexit(_E119_88);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF68: using guessed type const struct NetError ID_ConnectionError_PlayerAlreadyLoggedOn;
// 8EDF6C: using guessed type int dword_8EDF6C;
// 8EDF70: using guessed type int dword_8EDF70;

//----- (0070DDC0) --------------------------------------------------------  // acclient.c:800815
int _E121_74()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_ClientLogOnFailed");
  ID_ConnectionError_ClientLogOnFailed.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF78 = v0;
  dword_8EDF7C = 8;
  return atexit(sub_777600);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF74: using guessed type const struct NetError ID_ConnectionError_ClientLogOnFailed;
// 8EDF78: using guessed type int dword_8EDF78;
// 8EDF7C: using guessed type int dword_8EDF7C;

//----- (0070DE00) --------------------------------------------------------  // acclient.c:800831
int _E124_72()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_AccountAuthenticationFailed");
  ID_ConnectionError_AccountAuthenticationFailed.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF84 = v0;
  dword_8EDF88 = 8;
  return atexit(_E125_69);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF80: using guessed type const struct NetError ID_ConnectionError_AccountAuthenticationFailed;
// 8EDF84: using guessed type int dword_8EDF84;
// 8EDF88: using guessed type int dword_8EDF88;

//----- (0070DE40) --------------------------------------------------------  // acclient.c:800847
int _E127_61()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_LogonServerMigrated");
  ID_ConnectionError_LogonServerMigrated.vfptr = (PackObjVtbl *)&NetError::vftable;
  dword_8EDF90 = v0;
  dword_8EDF94 = 8;
  return atexit(_E128_67);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDF8C: using guessed type const struct NetError ID_ConnectionError_LogonServerMigrated;
// 8EDF90: using guessed type int dword_8EDF90;
// 8EDF94: using guessed type int dword_8EDF94;

//----- (0070DE80) --------------------------------------------------------  // acclient.c:800863
int _E130_55()
{
  unsigned int v0; // eax@1

  v0 = compute_str_hash("ID_ConnectionError_Generic");
  ID_ConnectionError_Generic.vfptr = (PackObjVtbl *)&NetError::vftable;
  ID_ConnectionError_Generic.m_stringID = v0;
  ID_ConnectionError_Generic.m_tableID = 8;
  return atexit(_E131_56);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (0070DEC0) --------------------------------------------------------  // acclient.c:800876
int _E133_47()
{
  return atexit(_E134_40);
}

//----- (0070DED0) --------------------------------------------------------  // acclient.c:800882
int sub_70DED0()
{
  return atexit(nullsub_1536);
}

//----- (00777500) --------------------------------------------------------  // acclient.c:910901
void __cdecl _E74_91()
{
  ID_NetError_BadServerAddress.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDEB4: using guessed type const struct NetError ID_NetError_BadServerAddress;

//----- (00777510) --------------------------------------------------------  // acclient.c:910909
void __cdecl sub_777510()
{
  ID_NetError_CantBind.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDEC0: using guessed type const struct NetError ID_NetError_CantBind;

//----- (00777520) --------------------------------------------------------  // acclient.c:910917
void __cdecl _E80_68()
{
  ID_NetError_CantSocket.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDECC: using guessed type const struct NetError ID_NetError_CantSocket;

//----- (00777530) --------------------------------------------------------  // acclient.c:910925
void __cdecl _E83_44()
{
  ID_NetError_CantCrypto.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDED8: using guessed type const struct NetError ID_NetError_CantCrypto;

//----- (00777540) --------------------------------------------------------  // acclient.c:910933
void __cdecl _E86_25()
{
  ID_NetError_AbortedHandshake.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00777550) --------------------------------------------------------  // acclient.c:910940
void __cdecl _E89_35()
{
  ID_ConnectionError_RunningSpeedhack.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00777560) --------------------------------------------------------  // acclient.c:910947
void __cdecl _E92_40()
{
  ID_ConnectionError_NoLogonServer.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDEFC: using guessed type const struct NetError ID_ConnectionError_NoLogonServer;

//----- (00777570) --------------------------------------------------------  // acclient.c:910955
void __cdecl sub_777570()
{
  ID_ConnectionError_NetVersionMismatch.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF08: using guessed type const struct NetError ID_ConnectionError_NetVersionMismatch;

//----- (00777580) --------------------------------------------------------  // acclient.c:910963
void __cdecl sub_777580()
{
  ID_ConnectionError_ServerFull.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF14: using guessed type const struct NetError ID_ConnectionError_ServerFull;

//----- (00777590) --------------------------------------------------------  // acclient.c:910971
void __cdecl sub_777590()
{
  ID_ConnectionError_BadCryptoKey.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF20: using guessed type const struct NetError ID_ConnectionError_BadCryptoKey;

//----- (007775A0) --------------------------------------------------------  // acclient.c:910979
void __cdecl sub_7775A0()
{
  ID_ConnectionError_InsufficientPriveledge.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF2C: using guessed type const struct NetError ID_ConnectionError_InsufficientPriveledge;

//----- (007775B0) --------------------------------------------------------  // acclient.c:910987
void __cdecl _E107_98()
{
  ID_ConnectionError_SecondLogon.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF38: using guessed type const struct NetError ID_ConnectionError_SecondLogon;

//----- (007775C0) --------------------------------------------------------  // acclient.c:910995
void __cdecl sub_7775C0()
{
  ID_ConnectionError_ServerClosedConnection.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF44: using guessed type const struct NetError ID_ConnectionError_ServerClosedConnection;

//----- (007775D0) --------------------------------------------------------  // acclient.c:911003
void __cdecl _E113_70()
{
  ID_ConnectionError_ServerTimedOutClient.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF50: using guessed type const struct NetError ID_ConnectionError_ServerTimedOutClient;

//----- (007775E0) --------------------------------------------------------  // acclient.c:911011
void __cdecl _E116_62()
{
  ID_ConnectionError_ClientTimedOutServer.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (007775F0) --------------------------------------------------------  // acclient.c:911018
void __cdecl _E119_88()
{
  ID_ConnectionError_PlayerAlreadyLoggedOn.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF68: using guessed type const struct NetError ID_ConnectionError_PlayerAlreadyLoggedOn;

//----- (00777600) --------------------------------------------------------  // acclient.c:911026
void __cdecl sub_777600()
{
  ID_ConnectionError_ClientLogOnFailed.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF74: using guessed type const struct NetError ID_ConnectionError_ClientLogOnFailed;

//----- (00777610) --------------------------------------------------------  // acclient.c:911034
void __cdecl _E125_69()
{
  ID_ConnectionError_AccountAuthenticationFailed.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF80: using guessed type const struct NetError ID_ConnectionError_AccountAuthenticationFailed;

//----- (00777620) --------------------------------------------------------  // acclient.c:911042
void __cdecl _E128_67()
{
  ID_ConnectionError_LogonServerMigrated.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 8EDF8C: using guessed type const struct NetError ID_ConnectionError_LogonServerMigrated;

//----- (00777630) --------------------------------------------------------  // acclient.c:911050
void __cdecl _E131_56()
{
  ID_ConnectionError_Generic.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00777640) --------------------------------------------------------  // acclient.c:911057
void __cdecl _E134_40()
{
  ID_NetError_None.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

