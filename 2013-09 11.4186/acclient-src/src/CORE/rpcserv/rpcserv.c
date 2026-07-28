/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : rpcserv
   Object     : CORE\rpcserv\rpcserv.obj
   Functions  : 11
   Addresses  : 006B9B20 - 00724AD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B9B20) --------------------------------------------------------  // acclient.c:721769
RPC_STATUS __thiscall RpcServer::UnRegisterInterface(RpcServer *this)
{
  RpcServer *v1; // esi@1
  RPC_STATUS result; // eax@1

  v1 = this;
  result = 0;
  if ( this->m_fEpRegistered )
  {
    result = RpcEpUnregister(this->m_hRpcInterface, this->m_pBindingVector, 0);
    v1->m_fEpRegistered = 0;
  }
  if ( v1->m_pBindingVector )
  {
    result = RpcBindingVectorFree(&v1->m_pBindingVector);
    v1->m_pBindingVector = 0;
  }
  if ( v1->m_fInterfaceAdded )
  {
    result = RpcServerUnregisterIf(v1->m_hRpcInterface, 0, 1u);
    v1->m_fInterfaceAdded = 0;
  }
  return result;
}

//----- (006B9B80) --------------------------------------------------------  // acclient.c:721795
void __thiscall RpcServer::~RpcServer(RpcServer *this)
{
  RpcServer *v1; // esi@1

  v1 = this;
  if ( this->m_fServerStarted )
  {
    --g_dwRpcServersListening;
    if ( !g_dwRpcServersListening && !RpcMgmtStopServerListening(0) )
      RpcMgmtWaitServerListen();
    v1->m_fServerStarted = 0;
  }
  RpcServer::UnRegisterInterface(v1);
  v1->m_dwProtocols = 0;
  v1->m_hRpcInterface = 0;
  *(_DWORD *)&RpcServer::sm_sid.Revision = 0;
  dword_9055C4 = 0;
  dword_9055C8 = 0;
  dword_9055CC = 0;
  dword_9055D0 = 0;
  operator delete[](v1->m_pszServiceName);
  v1->m_pszServiceName = 0;
}
// 9055C0: using guessed type struct _SECURITY_DESCRIPTOR RpcServer::sm_sid;
// 9055C4: using guessed type int dword_9055C4;
// 9055C8: using guessed type int dword_9055C8;
// 9055CC: using guessed type int dword_9055CC;
// 9055D0: using guessed type int dword_9055D0;

//----- (00724A10) --------------------------------------------------------  // acclient.c:822353
int sub_724A10()
{
  return atexit(nullsub_28);
}

//----- (00724A20) --------------------------------------------------------  // acclient.c:822359
int _E4_38()
{
  return atexit(_E5_38);
}

//----- (00724A30) --------------------------------------------------------  // acclient.c:822365
int _E7_38()
{
  Outside_CellID_38.id = Invalid_CellID_38.id + 1;
  return atexit(_E8_38);
}

//----- (00724A50) --------------------------------------------------------  // acclient.c:822372
int _E10_37()
{
  In_Limbo_CellID_37.id = Outside_CellID_38.id + 1;
  return atexit(_E11_37);
}

//----- (00724A70) --------------------------------------------------------  // acclient.c:822379
int _E13_37()
{
  First_Interior_CellID_37.id = In_Limbo_CellID_37.id + 1;
  return atexit(_E14_37);
}

//----- (00724A90) --------------------------------------------------------  // acclient.c:822386
int _E16_37()
{
  Last_Interior_CellID_37.id = Invalid_CellID_38.id - 1;
  return atexit(_E17_37);
}

//----- (00724AB0) --------------------------------------------------------  // acclient.c:822393
int _E21_40()
{
  return atexit(_E22_40);
}

//----- (00724AC0) --------------------------------------------------------  // acclient.c:822399
int _E40_39()
{
  return atexit(_E41_39);
}

//----- (00724AD0) --------------------------------------------------------  // acclient.c:822405
int _E43_42()
{
  return atexit(_E44_42);
}

