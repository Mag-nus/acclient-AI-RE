/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DwExceptionHandler
   Object     : PORTAL\debug_common\DwExceptionHandler.obj
   Functions  : 11
   Addresses  : 006B5680 - 00791110 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B5680) --------------------------------------------------------  // acclient.c:719336
void __thiscall TurbineDwExceptionFilter::TurnOnDwExceptionHandler::AddDllToDumpCapture(TurbineDwExceptionFilter::TurnOnDwExceptionHandler *this, const unsigned __int16 *wzDllReq)
{
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler *v2; // esi@1
  size_t v3; // eax@1

  v2 = this;
  _wcsncpy(
    &this->m_wzExtraDllsForDataCapture[this->m_dwIndexIntoExtraDlls],
    wzDllReq,
    260 - this->m_dwIndexIntoExtraDlls);
  v3 = _wcslen(wzDllReq) + 1 + v2->m_dwIndexIntoExtraDlls;
  v2->m_dwIndexIntoExtraDlls = v3;
  if ( v3 > 0x104 )
    v2->m_dwIndexIntoExtraDlls = 260;
}

//----- (006B56E0) --------------------------------------------------------  // acclient.c:719353
void __cdecl TurbineDwExceptionFilter::TurnOnDwExceptionHandler::SetRegistryKeysForWatson(const char *szPathToDW, const wchar_t *wzFormalAppName)
{
  HKEY v2; // [sp+0h] [bp-238h]@1
  signed int v3; // [sp+8h] [bp-230h]@3
  HKEY__ *hk; // [sp+24h] [bp-214h]@1
  unsigned int dwCreateResult; // [sp+28h] [bp-210h]@1
  wchar_t regPath[260]; // [sp+30h] [bp-208h]@1

  hk = 0;
  dwCreateResult = 0;
  __snwprintf(regPath, 0x104u, L"SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application\\%s", wzFormalAppName);
  if ( !RegCreateKeyExW(HKEY_LOCAL_MACHINE, regPath, 0, 0, 0, 0xF003Fu, 0, &hk, &dwCreateResult)
    && !RegSetValueExA(
          v2,
          "EventMessageFile",
          0,
          1u,
          *(const BYTE **)&regPath[244],
          strlen(*(const char **)&regPath[244]) + 1) )
  {
    v3 = 7;
    RegSetValueExA(v2, "TypesSupported", 0, 4u, (const BYTE *)&v3, 4u);
  }
}

//----- (006B57A0) --------------------------------------------------------  // acclient.c:719379
void __cdecl TurbineDwExceptionFilter::AddDllToDumpCapture(const unsigned __int16 *wzDllReq)
{
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler::AddDllToDumpCapture(
    &TurbineDwExceptionFilter::G_dwHandler,
    wzDllReq);
}

//----- (006B57B0) --------------------------------------------------------  // acclient.c:719387
void __thiscall TurbineDwExceptionFilter::TurnOnDwExceptionHandler::BuildListOfFilesToUpload(TurbineDwExceptionFilter::TurnOnDwExceptionHandler *this)
{
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler *v1; // ebp@1
  unsigned int v2; // edi@1
  int v3; // esi@1
  int i; // ebx@1
  size_t v5; // eax@3

  v1 = this;
  memset(this->m_wzExtraFilesForDataCapture, 0, sizeof(this->m_wzExtraFilesForDataCapture));
  v2 = this->m_Plugins.m_num;
  v3 = 0;
  for ( i = 1024; v2; --v2 )
  {
    if ( ((int (__stdcall *)(int, int))v1->m_Plugins.m_data[v2 - 1]->vfptr[1].__vecDelDtor)(
           &v1->m_wzExtraFilesForDataCapture[v3],
           i - 2) )
    {
      v5 = _wcslen(v1->m_wzExtraFilesForDataCapture);
      v1->m_wzExtraFilesForDataCapture[v5] = 124;
      v3 = v5 + 1;
      i = 1025 - (v5 + 1);
    }
  }
}

//----- (006B5820) --------------------------------------------------------  // acclient.c:719414
int __userpurge TurbineDwExceptionFilter::TurnOnDwExceptionHandler::DwExceptionFilter@<eax>(void *a1@<edi>, void *a2@<esi>, _EXCEPTION_POINTERS *pep)
{
  _EXCEPTION_RECORD *v3; // eax@1
  LPVOID v4; // ebp@1
  int result; // eax@4
  HANDLE v6; // eax@6
  void *v7; // esi@6
  HANDLE v8; // edi@8
  HANDLE v9; // ST34_4@8
  HANDLE v10; // ST30_4@8
  HANDLE v11; // eax@8
  char *v12; // esi@13
  void (__stdcall *v13)(HANDLE); // edi@16
  signed int v14; // esi@21
  void *v15; // ebx@23
  DWORD v16; // eax@25
  int v17; // ebx@37
  void *v18; // [sp+0h] [bp-5A0h]@13
  void *v19; // [sp+4h] [bp-59Ch]@13
  void *v20; // [sp+8h] [bp-598h]@6
  void *v21; // [sp+Ch] [bp-594h]@6
  void *v22; // [sp+10h] [bp-590h]@0
  HANDLE hEventDone; // [sp+18h] [bp-588h]@8
  HANDLE hMutex; // [sp+1Ch] [bp-584h]@8
  void *hEventAlive; // [sp+20h] [bp-580h]@8
  void *hFileMap; // [sp+24h] [bp-57Ch]@6
  void *hProc; // [sp+28h] [bp-578h]@1
  _SECURITY_ATTRIBUTES sa; // [sp+2Ch] [bp-574h]@6
  _STARTUPINFOA StartupInfo; // [sp+48h] [bp-558h]@13
  char szAppFolderPath[260]; // [sp+8Ch] [bp-514h]@20
  char szModPath[260]; // [sp+294h] [bp-30Ch]@13
  char szCommandLine[520]; // [sp+398h] [bp-208h]@39

  __clearfp();
  v3 = pep->ExceptionRecord;
  v4 = 0;
  hProc = 0;
  if ( v3->ExceptionCode == -2147483645 || S_inDWExecptionHandler )
  {
    if ( TurbineDwExceptionFilter::G_dwHandler.m_oldFilter )
      result = TurbineDwExceptionFilter::G_dwHandler.m_oldFilter(pep);
    else
      result = 0;
    return result;
  }
  v21 = a2;
  v20 = a1;
  sa.lpSecurityDescriptor = 0;
  S_inDWExecptionHandler = 1;
  sa.nLength = 12;
  sa.bInheritHandle = 1;
  v6 = CreateFileMappingA((HANDLE)0xFFFFFFFF, &sa, 4u, 0, 0x1C50u, 0);
  v7 = v6;
  hFileMap = v6;
  if ( !v6 || (v4 = MapViewOfFile(v6, 6u, 0, 0, 0)) == 0 )
  {
    v13 = (void (__stdcall *)(HANDLE))CloseHandle;
    goto LABEL_47;
  }
  memset(v4, 0, 0x1C50u);
  v8 = CreateEventA(&sa, 0, 0, 0);
  hEventAlive = v8;
  hEventDone = CreateEventA(&sa, 0, 0, 0);
  hMutex = CreateMutexA(&sa, 0, 0);
  v9 = GetCurrentProcess();
  v10 = GetCurrentProcess();
  v11 = GetCurrentProcess();
  if ( !DuplicateHandle(v11, v10, v9, &hProc, 0x1F0FFFu, 1, 0) )
    goto LABEL_16;
  if ( !v8 )
  {
    v13 = (void (__stdcall *)(HANDLE))CloseHandle;
    goto LABEL_42;
  }
  if ( !hEventDone )
    goto LABEL_16;
  if ( !hMutex )
    goto LABEL_16;
  if ( !hProc )
    goto LABEL_16;
  *((_DWORD *)v4 + 9) = hProc;
  *((_DWORD *)v4 + 1) = GetCurrentProcessId();
  *((_DWORD *)v4 + 2) = GetCurrentThreadId();
  *((_DWORD *)v4 + 5) = hEventDone;
  *((_DWORD *)v4 + 7) = v8;
  *((_DWORD *)v4 + 8) = hMutex;
  *(_DWORD *)v4 = 7248;
  *((_DWORD *)v4 + 4) = pep;
  *((_DWORD *)v4 + 3) = pep->ExceptionRecord->ExceptionAddress;
  *((_DWORD *)v4 + 13) = 1;
  *((_DWORD *)v4 + 15) = 1;
  *((_DWORD *)v4 + 11) = 16;
  *((_DWORD *)v4 + 10) = 4428;
  strcpy((char *)v4 + 3640, TurbineDwExceptionFilter::G_dwHandler.m_szWatsonServer);
  qmemcpy((char *)v4 + 4424, "Microsoft\\PCHealth\\ErrorReporting\\DW", 0x25u);
  qmemcpy((char *)v4 + 4160, "HKLM\\Software\\Microsoft\\Internet Explorer\\Registration\\DigitalProductID", 0x48u);
  *((_DWORD *)v4 + 1105) = GetUserDefaultLCID();
  _wcsncpy((wchar_t *)v4 + 2312, TurbineDwExceptionFilter::G_dwHandler.m_wzExtraDllsForDataCapture, 0x104u);
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler::BuildListOfFilesToUpload(&TurbineDwExceptionFilter::G_dwHandler);
  _printf("%ls\n", TurbineDwExceptionFilter::G_dwHandler.m_wzExtraFilesForDataCapture);
  _wcsncpy((wchar_t *)v4 + 2572, TurbineDwExceptionFilter::G_dwHandler.m_wzExtraFilesForDataCapture, 0x400u);
  GetModuleFileNameA(0, szModPath, 0x104u);
  MultiByteToWideChar(0, 0, szModPath, -1, (LPWSTR)v4 + 92, 260);
  GetModuleFileNameA(0, (LPSTR)&StartupInfo.dwFlags, 0x104u);
  v12 = (char *)&StartupInfo.dwFlags + strlen((const char *)&StartupInfo.dwFlags);
  if ( (unsigned int)v12 < (unsigned int)&StartupInfo.dwFlags )
    goto LABEL_16;
  while ( *v12 != 92 )
  {
    --v12;
    if ( (unsigned int)v12 < (unsigned int)&StartupInfo.dwFlags )
      goto LABEL_16;
  }
  if ( (unsigned int)v12 < (unsigned int)&StartupInfo.dwFlags )
  {
LABEL_16:
    v13 = (void (__stdcall *)(HANDLE))CloseHandle;
    goto LErrorCleanup;
  }
  __snwprintf((wchar_t *)v4 + 36, 0x104u, L"%hs", v12 + 1);
  *v12 = 0;
  _wsprintfA(&szAppFolderPath[236], "%s\\watson\\dw15.exe", &StartupInfo.dwFlags);
  _wsprintfA(&szModPath[236], " -x -s %u", v21);
  memset(&sa.lpSecurityDescriptor, 0, 0x44u);
  hEventAlive = 0;
  hFileMap = 0;
  hProc = 0;
  sa.lpSecurityDescriptor = (void *)68;
  sa.nLength = 0;
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler::SetRegistryKeysForWatson(
    &szAppFolderPath[236],
    (const wchar_t *)v4 + 36);
  DialogBoxGateways::ReportThread_PrepareForDialogBox();
  CrashCleaners::CallCrashCleaners();
  if ( !CreateProcessA(
          &szAppFolderPath[236],
          &szModPath[236],
          0,
          0,
          1,
          0x4000020u,
          0,
          0,
          (LPSTARTUPINFOA)&sa.lpSecurityDescriptor,
          (LPPROCESS_INFORMATION)&hEventAlive) )
  {
    v13 = (void (__stdcall *)(HANDLE))CloseHandle;
    goto LABEL_37;
  }
  v14 = 1;
  while ( 1 )
  {
    if ( !WaitForSingleObject(v20, 0x4E20u) )
    {
      v15 = v19;
      if ( !WaitForSingleObject(v18, 1u) )
        goto LABEL_35;
      goto LABEL_32;
    }
    v15 = v19;
    v16 = WaitForSingleObject(v19, 0x2710u);
    if ( v16 == 258 )
      goto LABEL_35;
    if ( v16 == 128 )
      break;
    if ( WaitForSingleObject(v20, 1u) )
    {
      SetEvent(v18);
LABEL_30:
      v14 = 0;
      goto LABEL_31;
    }
    if ( !WaitForSingleObject(v18, 1u) )
      goto LABEL_30;
LABEL_31:
    ReleaseMutex(v19);
LABEL_32:
    if ( !v14 )
      goto LABEL_35;
  }
  ReleaseMutex(v19);
LABEL_35:
  v13 = (void (__stdcall *)(HANDLE))CloseHandle;
  CloseHandle(v20);
  v20 = 0;
  CloseHandle(v18);
  CloseHandle(v15);
  CloseHandle(v22);
LABEL_37:
  v17 = *((_DWORD *)v4 + 11);
  UnmapViewOfFile(v4);
  v4 = 0;
  v13(v21);
  if ( v17 == 16 )
  {
    if ( TurbineDwExceptionFilter::G_dwHandler.m_oldFilter )
      result = TurbineDwExceptionFilter::G_dwHandler.m_oldFilter(*(_EXCEPTION_POINTERS **)&szCommandLine[500]);
    else
      result = 0;
    return result;
  }
LErrorCleanup:
  if ( v20 )
    v13(v20);
LABEL_42:
  if ( hEventDone )
    v13(hEventDone);
  if ( hMutex )
    v13(hMutex);
  v7 = hFileMap;
LABEL_47:
  if ( hProc )
    v13(hProc);
  if ( v4 )
    UnmapViewOfFile(v4);
  if ( v7 )
    v13(v7);
  return 1;
}
// 6B5820: could not find valid save-restore pair for edi
// 6B5820: could not find valid save-restore pair for esi

//----- (006B5D30) --------------------------------------------------------  // acclient.c:719637
void __thiscall TurbineDwExceptionFilter::WatsonCrashReportHelper::~WatsonCrashReportHelper(TurbineDwExceptionFilter::WatsonCrashReportHelper *this)
{
  TurbineDwExceptionFilter::WatsonCrashReportHelper *v1; // esi@1
  CPluginManager *v2; // ecx@1

  v1 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable;
  CPluginManager::RemovePluginPrototype(
    (CPluginManager *)&TurbineDwExceptionFilter::G_dwHandler.m_Plugins,
    (CPluginPrototype *)&this->vfptr);
  v2 = v1->m_pManager;
  v1->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v2 )
  {
    CPluginManager::RemovePluginPrototype(v2, (CPluginPrototype *)&v1->vfptr);
    v1->m_pManager = 0;
  }
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 8064F0: using guessed type int (__thiscall *TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable)(void *, char);

//----- (006B5D60) --------------------------------------------------------  // acclient.c:719659
TurbineDwExceptionFilter::WatsonCrashReportHelper *__thiscall TurbineDwExceptionFilter::WatsonCrashReportHelper::vector_deleting_destructor(TurbineDwExceptionFilter::WatsonCrashReportHelper *this, unsigned int a2)
{
  TurbineDwExceptionFilter::WatsonCrashReportHelper *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable;
  CPluginManager::RemovePluginPrototype(
    (CPluginManager *)&TurbineDwExceptionFilter::G_dwHandler.m_Plugins,
    (CPluginPrototype *)&this->vfptr);
  v3 = v2->m_pManager;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, (CPluginPrototype *)&v2->vfptr);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 8064F0: using guessed type int (__thiscall *TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable)(void *, char);

//----- (006B5DB0) --------------------------------------------------------  // acclient.c:719684
void __thiscall TurbineDwExceptionFilter::TurnOnDwExceptionHandler::TurnOnDwExceptionHandler(TurbineDwExceptionFilter::TurnOnDwExceptionHandler *this, int fInstallNow, const char *szWatsonServer)
{
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler *v3; // esi@1
  char *v4; // ebp@1

  v3 = this;
  this->m_Plugins.m_data = 0;
  this->m_Plugins.m_sizeAndDeallocate = 0;
  this->m_Plugins.m_num = 0;
  this->m_dwIndexIntoExtraDlls = 0;
  this->m_fInstalled = 0;
  this->m_oldFilter = 0;
  v4 = this->m_szWatsonServer;
  memset(this->m_szWatsonServer, 0, 0x104u);
  this->m_szWatsonServer[260] = 0;
  memset(this->m_wzExtraDllsForDataCapture, 0, 0x208u);
  this->m_wzExtraDllsForDataCapture[260] = 0;
  if ( fInstallNow && !this->m_fInstalled )
  {
    this->m_oldFilter = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)TurbineDwExceptionFilter::TurnOnDwExceptionHandler::DwExceptionFilter);
    v3->m_fInstalled = 1;
  }
  if ( szWatsonServer )
  {
    if ( *szWatsonServer )
      _strncpy(v4, szWatsonServer, 0x104u);
  }
}

//----- (006B5E40) --------------------------------------------------------  // acclient.c:719714
void __thiscall TurbineDwExceptionFilter::WatsonCrashReportHelper::WatsonCrashReportHelper(TurbineDwExceptionFilter::WatsonCrashReportHelper *this)
{
  this->m_pManager = 0;
  this->vfptr = (CPluginPrototypeVtbl *)&TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable;
  CPluginManager::AddPluginPrototype(
    (CPluginManager *)&TurbineDwExceptionFilter::G_dwHandler.m_Plugins,
    (CPluginPrototype *)&this->vfptr);
}
// 8064F0: using guessed type int (__thiscall *TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable)(void *, char);

//----- (00723F60) --------------------------------------------------------  // acclient.c:821730
int sub_723F60()
{
  TurbineDwExceptionFilter::TurnOnDwExceptionHandler::TurnOnDwExceptionHandler(
    &TurbineDwExceptionFilter::G_dwHandler,
    0,
    "watson.microsoft.com");
  return atexit(sub_791110);
}

//----- (00791110) --------------------------------------------------------  // acclient.c:937251
void __cdecl sub_791110()
{
  if ( TurbineDwExceptionFilter::G_dwHandler.m_fInstalled )
  {
    SetUnhandledExceptionFilter(TurbineDwExceptionFilter::G_dwHandler.m_oldFilter);
    TurbineDwExceptionFilter::G_dwHandler.m_oldFilter = 0;
    TurbineDwExceptionFilter::G_dwHandler.m_fInstalled = 0;
  }
  CPluginManager::~CPluginManager((CPluginManager *)&TurbineDwExceptionFilter::G_dwHandler.m_Plugins);
}

