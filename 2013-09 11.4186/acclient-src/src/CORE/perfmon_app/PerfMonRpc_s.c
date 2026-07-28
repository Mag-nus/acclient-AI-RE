/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PerfMonRpc_s
   Object     : CORE\perfmon_app\PerfMonRpc_s.obj
   Functions  : 3
   Addresses  : 006836E0 - 00683A50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006836E0) --------------------------------------------------------  // acclient.c:666998
void __stdcall turbineperfmonrpcserverapi_GetNumberPerfCounters(_RPC_MESSAGE *_pRpcMessage)
{
  void *v1; // ebx@1
  unsigned int v2; // edi@3
  signed int v3; // eax@5
  signed int v4; // ebx@5
  int v5; // eax@5
  _MIDL_STUB_MESSAGE _StubMsg; // [sp+Ch] [bp-100h]@1
  unsigned int *arraySize; // [sp+E8h] [bp-24h]@3
  int _Status; // [sp+ECh] [bp-20h]@5
  unsigned int _RetVal; // [sp+F0h] [bp-1Ch]@5
  CPPEH_RECORD ms_exc; // [sp+F4h] [bp-18h]@1

  NdrServerInitializeNew(_pRpcMessage, &_StubMsg, &turbineperfmonrpcserverapi_StubDesc);
  v1 = _pRpcMessage->Handle;
  ms_exc.registration.TryLevel = 1;
  if ( (_pRpcMessage->DataRepresentation & 0xFFFF) != 16 )
    NdrConvert(&_StubMsg, _MIDL_ProcFormatString.Format);
  v2 = (unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC;
  arraySize = (unsigned int *)((unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC);
  _StubMsg.Buffer = (char *)(v2 + 4);
  if ( (char *)(v2 + 4) > _StubMsg.BufferEnd )
    RpcRaiseException(1783);
  ms_exc.registration.TryLevel = 0;
  v3 = GetNumberPerfCounters(v1, (unsigned int *)v2);
  v4 = v3;
  _RetVal = v3;
  _StubMsg.BufferLength = 36;
  _pRpcMessage->BufferLength = 36;
  v5 = I_RpcGetBuffer(_pRpcMessage);
  _Status = v5;
  if ( v5 )
    RpcRaiseException(v5);
  _StubMsg.Buffer = (char *)((unsigned int)((char *)_pRpcMessage->Buffer + 3) & 0xFFFFFFFC);
  *(_DWORD *)_StubMsg.Buffer = *(_DWORD *)v2;
  _StubMsg.Buffer = (char *)((unsigned int)(_StubMsg.Buffer + 7) & 0xFFFFFFFC);
  *(_DWORD *)_StubMsg.Buffer = v4;
  ms_exc.registration.TryLevel = -1;
  _pRpcMessage->BufferLength = _StubMsg.Buffer + 4 - _pRpcMessage->Buffer;
}

//----- (00683870) --------------------------------------------------------  // acclient.c:667040
void __stdcall turbineperfmonrpcserverapi_GetPerfCounterDescriptions(_RPC_MESSAGE *_pRpcMessage)
{
  unsigned int v1; // eax@3
  char *v2; // ecx@3
  char *v3; // edx@3
  unsigned int v4; // esi@5
  unsigned int (*v5)[]; // eax@7
  unsigned __int8 *v6; // edi@7
  int v7; // eax@7
  _MIDL_STUB_MESSAGE _StubMsg; // [sp+Ch] [bp-108h]@1
  int _Status; // [sp+E8h] [bp-2Ch]@7
  unsigned int arraySize; // [sp+ECh] [bp-28h]@5
  void *h1; // [sp+F0h] [bp-24h]@1
  unsigned int _RetVal; // [sp+F4h] [bp-20h]@7
  unsigned int (*counterType)[]; // [sp+F8h] [bp-1Ch]@1
  CPPEH_RECORD ms_exc; // [sp+FCh] [bp-18h]@1

  NdrServerInitializeNew(_pRpcMessage, &_StubMsg, &turbineperfmonrpcserverapi_StubDesc);
  h1 = _pRpcMessage->Handle;
  counterType = 0;
  ms_exc.registration.TryLevel = 1;
  if ( (_pRpcMessage->DataRepresentation & 0xFFFF) != 16 )
    NdrConvert(&_StubMsg, &_MIDL_ProcFormatString.Format[8]);
  v1 = (unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC;
  _StubMsg.Buffer = (char *)v1;
  v2 = (char *)(v1 + 4);
  v3 = _StubMsg.BufferEnd;
  if ( (char *)(v1 + 4) > _StubMsg.BufferEnd )
    RpcRaiseException(1783);
  v4 = *(_DWORD *)v1;
  arraySize = *(_DWORD *)v1;
  _StubMsg.Buffer = v2;
  if ( v2 > v3 )
    RpcRaiseException(1783);
  ms_exc.registration.TryLevel = 0;
  v5 = (unsigned int (*)[])NdrAllocate(&_StubMsg, 4 * v4);
  v6 = (unsigned __int8 *)v5;
  counterType = v5;
  _RetVal = GetPerfCounterDescriptions(h1, v4, (unsigned int *)v5);
  _StubMsg.BufferLength = 8;
  _StubMsg.MaxCount = v4;
  NdrConformantArrayBufferSize(&_StubMsg, v6, &_MIDL_TypeFormatString.Format[6]);
  _pRpcMessage->BufferLength = _StubMsg.BufferLength;
  v7 = I_RpcGetBuffer(_pRpcMessage);
  _Status = v7;
  if ( v7 )
    RpcRaiseException(v7);
  _StubMsg.Buffer = (char *)_pRpcMessage->Buffer;
  _StubMsg.MaxCount = v4;
  NdrConformantArrayMarshall(&_StubMsg, v6, &_MIDL_TypeFormatString.Format[6]);
  _StubMsg.Buffer = (char *)((unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC);
  *(_DWORD *)_StubMsg.Buffer = _RetVal;
  _StubMsg.Buffer += 4;
  ms_exc.registration.TryLevel = -1;
  if ( v6 )
    _StubMsg.pfnFree(v6);
  _pRpcMessage->BufferLength = _StubMsg.Buffer - _pRpcMessage->Buffer;
}

//----- (00683A50) --------------------------------------------------------  // acclient.c:667100
void __stdcall turbineperfmonrpcserverapi_GetPerfCounterValues(_RPC_MESSAGE *_pRpcMessage)
{
  unsigned int v1; // eax@3
  char *v2; // ecx@3
  char *v3; // edx@3
  unsigned int v4; // esi@5
  unsigned __int64 (*v5)[]; // eax@7
  unsigned __int8 *v6; // edi@7
  int v7; // eax@7
  _MIDL_STUB_MESSAGE _StubMsg; // [sp+Ch] [bp-108h]@1
  int _Status; // [sp+E8h] [bp-2Ch]@7
  unsigned int arraySize; // [sp+ECh] [bp-28h]@5
  void *h1; // [sp+F0h] [bp-24h]@1
  unsigned int _RetVal; // [sp+F4h] [bp-20h]@7
  unsigned __int64 (*values)[]; // [sp+F8h] [bp-1Ch]@1
  CPPEH_RECORD ms_exc; // [sp+FCh] [bp-18h]@1

  NdrServerInitializeNew(_pRpcMessage, &_StubMsg, &turbineperfmonrpcserverapi_StubDesc);
  h1 = _pRpcMessage->Handle;
  values = 0;
  ms_exc.registration.TryLevel = 1;
  if ( (_pRpcMessage->DataRepresentation & 0xFFFF) != 16 )
    NdrConvert(&_StubMsg, &_MIDL_ProcFormatString.Format[18]);
  v1 = (unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC;
  _StubMsg.Buffer = (char *)v1;
  v2 = (char *)(v1 + 4);
  v3 = _StubMsg.BufferEnd;
  if ( (char *)(v1 + 4) > _StubMsg.BufferEnd )
    RpcRaiseException(1783);
  v4 = *(_DWORD *)v1;
  arraySize = *(_DWORD *)v1;
  _StubMsg.Buffer = v2;
  if ( v2 > v3 )
    RpcRaiseException(1783);
  ms_exc.registration.TryLevel = 0;
  v5 = (unsigned __int64 (*)[])NdrAllocate(&_StubMsg, 8 * v4);
  v6 = (unsigned __int8 *)v5;
  values = v5;
  _RetVal = GetPerfCounterValues(h1, v4, (unsigned __int64 *)v5);
  _StubMsg.BufferLength = 8;
  _StubMsg.MaxCount = v4;
  NdrConformantArrayBufferSize(&_StubMsg, v6, &_MIDL_TypeFormatString.Format[16]);
  _pRpcMessage->BufferLength = _StubMsg.BufferLength;
  v7 = I_RpcGetBuffer(_pRpcMessage);
  _Status = v7;
  if ( v7 )
    RpcRaiseException(v7);
  _StubMsg.Buffer = (char *)_pRpcMessage->Buffer;
  _StubMsg.MaxCount = v4;
  NdrConformantArrayMarshall(&_StubMsg, v6, &_MIDL_TypeFormatString.Format[16]);
  _StubMsg.Buffer = (char *)((unsigned int)(_StubMsg.Buffer + 3) & 0xFFFFFFFC);
  *(_DWORD *)_StubMsg.Buffer = _RetVal;
  _StubMsg.Buffer += 4;
  ms_exc.registration.TryLevel = -1;
  if ( v6 )
    _StubMsg.pfnFree(v6);
  _pRpcMessage->BufferLength = _StubMsg.Buffer - _pRpcMessage->Buffer;
}

