/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Debug
   Object     : CORE\debug_common\Debug.obj
   Functions  : 24
   Addresses  : 00405AE0 - 00725B20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00405AE0) --------------------------------------------------------  // acclient.c:64781
char __cdecl CreateAndRunDebugWorkerThread(unsigned int (__stdcall *pfnThreadProc)(void *), DebugWorkerThreadData *i_pData)
{
  HANDLE v2; // esi@1

  i_pData->hRunning = CreateEventA(0, 1, 0, 0);
  v2 = CreateThread(0, 0, pfnThreadProc, i_pData, 0, &i_pData->idThread);
  if ( v2 )
  {
    if ( !WaitForSingleObject(i_pData->hRunning, 0x3E8u) )
    {
      WaitForSingleObject(v2, 0xFFFFFFFF);
      CloseHandle(v2);
      CloseHandle(i_pData->hRunning);
      return 1;
    }
    CloseHandle(v2);
  }
  CloseHandle(i_pData->hRunning);
  return 0;
}

//----- (00405B60) --------------------------------------------------------  // acclient.c:64803
void __cdecl Turbine::Debug::SetDebugFlags(unsigned int Mask, bool bValueToSet)
{
  if ( bValueToSet )
    Turbine::Debug::DebugFlags |= Mask;
  else
    Turbine::Debug::DebugFlags &= ~Mask;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405B80) --------------------------------------------------------  // acclient.c:64813
unsigned __int32 __cdecl Turbine::Debug::GetDebugFlags()
{
  return Turbine::Debug::DebugFlags;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405B90) --------------------------------------------------------  // acclient.c:64820
bool __cdecl Turbine::Debug::IsDebugFlagSet(unsigned int Value)
{
  return (Value & Turbine::Debug::DebugFlags) == Value;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405BB0) --------------------------------------------------------  // acclient.c:64827
void __cdecl Turbine::Debug::Abort()
{
  if ( !s_bDebugAborting )
  {
    CrashCleaners::CallCrashCleaners();
    s_bDebugAborting = 1;
    __exit(0);
  }
}
// 836724: using guessed type bool s_bDebugAborting;

//----- (00405BD0) --------------------------------------------------------  // acclient.c:64839
int __cdecl Turbine::Debug::ReportException(_EXCEPTION_POINTERS *pep)
{
  unsigned __int32 v1; // eax@1
  bool v2; // bl@1
  int result; // eax@5

  v1 = Turbine::Debug::DebugFlags;
  v2 = (Turbine::Debug::DebugFlags & 0x4000) == 0x4000;
  BYTE1(v1) &= 0xBFu;
  Turbine::Debug::DebugFlags = v1;
  CrashCleaners::CallCrashCleaners();
  Turbine::Debug::DebugFlags &= 0xFFFFFFB7;
  if ( v2 )
    BYTE1(Turbine::Debug::DebugFlags) |= 0x40u;
  else
    BYTE1(Turbine::Debug::DebugFlags) &= 0xBFu;
  if ( G_oldFilter )
    result = G_oldFilter(pep);
  else
    result = 0;
  return result;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405C30) --------------------------------------------------------  // acclient.c:64864
void __thiscall Turbine::Debug::Debug(Turbine::Debug *this)
{
  this->vfptr = (Turbine::DebugVtbl *)&Turbine::Debug::vftable;
}
// 7942B0: using guessed type bool (__thiscall *Turbine::Debug::vftable)(Turbine::Debug *__hidden this);

//----- (00405C40) --------------------------------------------------------  // acclient.c:64871
void __thiscall Turbine::Debug::~Debug(Turbine::Debug *this)
{
  this->vfptr = (Turbine::DebugVtbl *)&Turbine::Debug::vftable;
  if ( G_oldFilter )
  {
    SetUnhandledExceptionFilter(G_oldFilter);
    G_oldFilter = 0;
  }
  DbgHelpWrapper::FreeDbgHelpFunctions();
}
// 7942B0: using guessed type bool (__thiscall *Turbine::Debug::vftable)(Turbine::Debug *__hidden this);

//----- (00405C70) --------------------------------------------------------  // acclient.c:64884
unsigned int __thiscall ReferenceCountTemplate<1048576,0>::Release(ReferenceCountTemplate<1048576,0> *this)
{
  ReferenceCountTemplate<1048576,0> *v1; // esi@1
  char *v2; // edi@1
  unsigned int result; // eax@2

  v1 = this;
  v2 = (char *)&this->m_cRef;
  if ( InterlockedDecrement((volatile LONG *)&this->m_cRef) )
  {
    result = *(_DWORD *)v2;
  }
  else
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor(v1, 1u);
    result = 0;
  }
  return result;
}

//----- (00405CA0) --------------------------------------------------------  // acclient.c:64906
unsigned int __cdecl Turbine::Debug::SetFloatingPointException(bool fCrashOnCondition, unsigned int conditionToCheck)
{
  unsigned int v2; // esi@1
  unsigned int result; // eax@2

  v2 = __control87(0, 0);
  __clearfp();
  if ( fCrashOnCondition )
    result = __control87(~conditionToCheck & v2, 0x8001Fu);
  else
    result = __control87(conditionToCheck | v2, 0x8001Fu);
  return result;
}

//----- (00405CF0) --------------------------------------------------------  // acclient.c:64921
unsigned int __stdcall ProtectedDebug::ExceptionFilterThread(void *lpParam)
{
  SetEvent(*(HANDLE *)lpParam);
  *((_DWORD *)lpParam + 3) = Turbine::Debug::ReportException(*((_EXCEPTION_POINTERS **)lpParam + 2));
  return 0;
}

//----- (00405D20) --------------------------------------------------------  // acclient.c:64929
int __cdecl RunInBackupStack(_EXCEPTION_POINTERS *pep)
{
  unsigned int v1; // esi@2
  int result; // eax@2
  int v3; // esi@4
  ExceptionThreadInfo Info; // [sp+4h] [bp-20h]@1

  s_bBackupStackAvailable = 0;
  Info.pep = pep;
  DbgReportContext::DbgReportContext(&Info.ctxt, pep);
  if ( CreateAndRunDebugWorkerThread(ProtectedDebug::ExceptionFilterThread, (DebugWorkerThreadData *)&Info.hRunning) )
  {
    v1 = Info.dwRetVal;
    DbgReportContext::~DbgReportContext(&Info.ctxt);
    result = v1;
  }
  else if ( G_oldFilter )
  {
    v3 = G_oldFilter(pep);
    DbgReportContext::~DbgReportContext(&Info.ctxt);
    result = v3;
  }
  else
  {
    DbgReportContext::~DbgReportContext(&Info.ctxt);
    result = 0;
  }
  return result;
}

//----- (00405DA0) --------------------------------------------------------  // acclient.c:64960
int __stdcall Turbine::Debug::TurbineExceptionFilter(_EXCEPTION_POINTERS *pep)
{
  unsigned int v1; // eax@1
  int result; // eax@4
  HANDLE v3; // eax@10
  LPVOID v4; // ST08_4@10
  bool v5; // bl@10
  HANDLE v6; // eax@10
  HANDLE v7; // eax@13
  LPVOID v8; // ST08_4@13
  bool v9; // bl@13
  HANDLE v10; // eax@13
  int v11; // esi@20
  DbgReportContext ctxt; // [sp+4h] [bp-10h]@20

  __clearfp();
  v1 = pep->ExceptionRecord->ExceptionCode;
  if ( v1 == -2147483645 )
    goto LABEL_7;
  if ( v1 == -1073741801 && !(BYTE1(Turbine::Debug::DebugFlags) & 0x40) )
    return -1;
  if ( S_inDebugExecptionHandler )
  {
    CrashCleaners::CallCrashCleaners();
LABEL_7:
    if ( G_oldFilter )
      result = G_oldFilter(pep);
    else
      result = 0;
    return result;
  }
  S_inDebugExecptionHandler = 1;
  if ( v1 != -1073741801 )
  {
    v3 = GetProcessHeap();
    v4 = HeapAlloc(v3, 0, 0x400000u);
    v5 = v4 == 0;
    v6 = GetProcessHeap();
    HeapFree(v6, 0, v4);
    if ( !v5 )
      goto LABEL_24;
  }
  if ( g_EmergencyMemoryPool.m_pReservedMemory )
    VirtualFree(g_EmergencyMemoryPool.m_pReservedMemory, 0, 0x8000u);
  g_EmergencyMemoryPool.m_pReservedMemory = 0;
  v7 = GetProcessHeap();
  v8 = HeapAlloc(v7, 0, 0x400000u);
  v9 = v8 == 0;
  v10 = GetProcessHeap();
  HeapFree(v10, 0, v8);
  if ( v9 )
  {
    CrashCleaners::CallCrashCleaners();
    if ( G_oldFilter )
      result = G_oldFilter(pep);
    else
      result = 0;
  }
  else
  {
LABEL_24:
    if ( pep->ExceptionRecord->ExceptionCode == -1073741571 && s_bBackupStackAvailable )
    {
      result = RunInBackupStack(pep);
      S_inDebugExecptionHandler = 0;
    }
    else
    {
      DbgReportContext::DbgReportContext(&ctxt, pep);
      v11 = Turbine::Debug::ReportException(pep);
      S_inDebugExecptionHandler = 0;
      DbgReportContext::~DbgReportContext(&ctxt);
      result = v11;
    }
  }
  return result;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405F20) --------------------------------------------------------  // acclient.c:65040
char Turbine::Debug::InitCommon()
{
  unsigned int v1; // esi@5

  if ( BYTE1(Turbine::Debug::DebugFlags) & 2 && !G_oldFilter )
    G_oldFilter = SetUnhandledExceptionFilter(Turbine::Debug::TurbineExceptionFilter);
  if ( BYTE1(Turbine::Debug::DebugFlags) & 4 )
  {
    v1 = __control87(0, 0);
    __clearfp();
    __control87(v1 & 0xFFFFFFF7, 0x8001Fu);
  }
  return 1;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405F80) --------------------------------------------------------  // acclient.c:65057
bool Turbine::Debug::InitDebug()
{
  BYTE1(Turbine::Debug::DebugFlags) &= 0xFEu;
  return Turbine::Debug::InitCommon() != 0;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;

//----- (00405FA0) --------------------------------------------------------  // acclient.c:65065
void __thiscall Turbine::InplaceString<4096,char>::Init(Turbine::InplaceString<4096,char> *this, const char *i_szFormat, char *i_args)
{
  Turbine::InplaceString<4096,char> *v3; // edi@1
  int v4; // eax@2
  size_t v5; // esi@2
  char *v6; // eax@2

  v3 = this;
  if ( __vsnprintf(this->m_pBuffer, 0x1000u, i_szFormat, i_args) < 0 )
  {
    v4 = __vscprintf(i_szFormat, i_args);
    v5 = v4;
    v6 = (char *)operator new[](v4 + 1);
    if ( v6 )
    {
      v3->m_pBuffer = v6;
      __vsnprintf(v6, v5, i_szFormat, i_args);
      v3->m_pBuffer[v5] = 0;
    }
  }
}

//----- (00406000) --------------------------------------------------------  // acclient.c:65088
char __cdecl Turbine::Debug::Init(const char *pszProjectName, const char *pszProjectEmail, unsigned int dwFlags)
{
  unsigned __int32 v3; // eax@1
  char result; // al@4

  Turbine::Debug::DebugFlags &= ~dwFlags;
  PStringBase<char>::set(&g_strProjectName, pszProjectName);
  PStringBase<char>::set(&g_strEmailAssertions, pszProjectEmail);
  v3 = Turbine::Debug::DebugFlags;
  if ( BYTE1(v3) & 0x20 )
  {
    BYTE1(v3) &= 0xDFu;
    Turbine::Debug::DebugFlags = v3;
    Logger::Initialize((v3 & 0x800) != 2048);
    if ( BYTE1(Turbine::Debug::DebugFlags) & 2 )
      g_EmergencyMemoryPool.m_pReservedMemory = VirtualAlloc(0, 0x6400000u, 0x2000u, 4u);
    result = ((int (*)(void))Turbine::Debug::s_pDebug->vfptr->InitDebug)();
  }
  else
  {
    result = 1;
  }
  return result;
}
// 817338: using guessed type unsigned __int32 Turbine::Debug::DebugFlags;
// 817550: using guessed type struct Turbine::Debug *Turbine::Debug::s_pDebug;

//----- (006C38E0) --------------------------------------------------------  // acclient.c:731960
int _E79_1()
{
  return atexit(_E80_3);
}

//----- (006C38F0) --------------------------------------------------------  // acclient.c:731966
unsigned int _E82()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("Debug::Assert");
  LC_DebugAssert = result;
  return result;
}

//----- (006C3910) --------------------------------------------------------  // acclient.c:731976
int _E73_1()
{
  g_strProjectName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E74_3);
}

//----- (006C3930) --------------------------------------------------------  // acclient.c:731984
int _E76_1()
{
  g_strEmailAssertions.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E77_29);
}

//----- (00725AC0) --------------------------------------------------------  // acclient.c:823477
void __cdecl _E80_3()
{
  if ( g_EmergencyMemoryPool.m_pReservedMemory )
    VirtualFree(g_EmergencyMemoryPool.m_pReservedMemory, 0, 0x8000u);
  g_EmergencyMemoryPool.m_pReservedMemory = 0;
}

//----- (00725AF0) --------------------------------------------------------  // acclient.c:823485
void __cdecl _E74_3()
{
  char *v0; // esi@1

  v0 = &g_strProjectName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&g_strProjectName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725B20) --------------------------------------------------------  // acclient.c:823498
void __cdecl _E77_29()
{
  char *v0; // esi@1

  v0 = &g_strEmailAssertions.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&g_strEmailAssertions.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

