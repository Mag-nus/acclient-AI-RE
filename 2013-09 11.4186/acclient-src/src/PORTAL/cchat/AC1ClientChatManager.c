/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AC1ClientChatManager
   Object     : PORTAL\cchat\AC1ClientChatManager.obj
   Functions  : 12
   Addresses  : 005567E0 - 007072D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005567E0) --------------------------------------------------------  // acclient.c:389885
void __thiscall AC1ClientChatManager::AC1ClientChatManager(AC1ClientChatManager *this)
{
  AC1ClientChatManager *v1; // esi@1

  v1 = this;
  TurbineDwExceptionFilter::WatsonCrashReportHelper::WatsonCrashReportHelper((TurbineDwExceptionFilter::WatsonCrashReportHelper *)&this->vfptr);
  v1->m_pChatClient = 0;
  v1->m_hChatClientLib = 0;
  v1->vfptr = (CPluginPrototypeVtbl *)&AC1ClientChatManager::vftable;
  s_pAC1ClientChatManager = v1;
}
// 7CB718: using guessed type int (__thiscall *AC1ClientChatManager::vftable)(void *, char);

//----- (00556800) --------------------------------------------------------  // acclient.c:389899
IChatClient *__cdecl AC1ClientChatManager::GetIChatClient()
{
  IChatClient *result; // eax@1

  result = (IChatClient *)s_pAC1ClientChatManager;
  if ( s_pAC1ClientChatManager )
    result = s_pAC1ClientChatManager->m_pChatClient;
  return result;
}

//----- (00556810) --------------------------------------------------------  // acclient.c:389910
AC1ClientChatManager *__thiscall AC1ClientChatManager::vector_deleting_destructor(AC1ClientChatManager *this, unsigned int a2)
{
  AC1ClientChatManager *v2; // esi@1
  IChatClient *v3; // eax@1
  IChatClient *v4; // eax@2

  v2 = this;
  v3 = this->m_pChatClient;
  this->vfptr = (CPluginPrototypeVtbl *)&AC1ClientChatManager::vftable;
  if ( v3 )
  {
    v3->vfptr[1].Release((IUnknown *)v3);
    v4 = v2->m_pChatClient;
    if ( v4 )
    {
      v4->vfptr->Release((IUnknown *)v2->m_pChatClient);
      v2->m_pChatClient = 0;
    }
  }
  if ( v2->m_hChatClientLib )
  {
    FreeLibrary(v2->m_hChatClientLib);
    v2->m_hChatClientLib = 0;
  }
  TurbineDwExceptionFilter::WatsonCrashReportHelper::~WatsonCrashReportHelper((TurbineDwExceptionFilter::WatsonCrashReportHelper *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CB718: using guessed type int (__thiscall *AC1ClientChatManager::vftable)(void *, char);

//----- (00556870) --------------------------------------------------------  // acclient.c:389942
int __stdcall AC1ClientChatManager::IncludeFileInWatsonUpload(unsigned __int16 *o_swzFilename, unsigned int dwCharsAvailable)
{
  unsigned int i; // esi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v4; // edi@4
  volatile LONG *v5; // ST0C_4@7
  AC1Legacy::PSRefBuffer<unsigned short> *v6; // esi@7
  AC1Legacy::PSRefBuffer<char> *v7; // esi@10
  int result; // eax@13
  AC1Legacy::PSRefBuffer<char> *v9; // esi@16
  AC1Legacy::PStringBase<unsigned short> filename; // [sp+4h] [bp-10Ch]@4
  AC1Legacy::PStringBase<char> logName; // [sp+8h] [bp-108h]@4
  char szDllPath[260]; // [sp+Ch] [bp-104h]@1

  GetModuleFileNameA(0, szDllPath, 0x104u);
  for ( i = (unsigned int)&szDllPath[strlen(szDllPath)]; i >= (unsigned int)szDllPath; --i )
  {
    if ( *(_BYTE *)i == 92 )
      break;
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>(&logName, (const char *)(i + 1));
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&filename, ".log");
  PSUtils::change_extension(&logName, (AC1Legacy::PStringBase<char> *)&filename);
  v4 = filename.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&filename.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  filename.m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4);
  *(_BYTE *)i = 0;
  InterlockedIncrement(v5);
  AC1Legacy::PStringBase<unsigned short>::sprintf(&filename, L"%hs\\%hs", szDllPath, logName.m_buffer->m_data);
  v6 = filename.m_buffer;
  if ( dwCharsAvailable >= filename.m_buffer->m_len - 1 )
  {
    _wcscpy(o_swzFilename, filename.m_buffer->m_data);
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v9 = logName.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&logName.m_buffer->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    result = 1;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)&filename.m_buffer->m_cRef) )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v7 = logName.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&logName.m_buffer->m_cRef) )
    {
      if ( v7 )
        v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    }
    result = 0;
  }
  return result;
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (005569E0) --------------------------------------------------------  // acclient.c:390000
int __thiscall AC1ClientChatManager::Init(AC1ClientChatManager *this, PStringBase<char> dllName, CCommunicationSystem::ChatInterfaceProvider *pChatProvider, AC1Legacy::PStringBase<unsigned short> *accountName)
{
  PSRefBufferCharData<char> *v4; // ebp@1
  AC1ClientChatManager *v5; // ebx@1
  HMODULE v6; // eax@1
  char *v7; // esi@2
  int v8; // esi@5
  LONG v9; // eax@5
  const unsigned __int16 **v10; // eax@6
  char *v11; // esi@6
  FARPROC v12; // edi@9
  int v13; // eax@12
  unsigned __int32 v14; // eax@13
  IChatClient *v15; // esi@14
  char *v16; // edx@16
  char *v17; // eax@16
  PStringBase<unsigned short> result; // [sp+18h] [bp-4h]@6
  char *retaddr; // [sp+1Ch] [bp+0h]@15

  v4 = dllName.m_charbuffer;
  v5 = this;
  v6 = LoadLibraryA(dllName.m_charbuffer->m_data);
  v5->m_hChatClientLib = v6;
  if ( !v6 )
  {
    PStringBase<char>::PStringBase<char>(&dllName, 0, "FATAL ERROR: Cannot load %s!\n", v4);
    v7 = &dllName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&dllName.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = (int)&v4[-2].m_data[12];
    v9 = InterlockedDecrement((volatile LONG *)&v4[-1]);
    goto LABEL_22;
  }
  v10 = (const unsigned __int16 **)PStringBase<char>::to_wpstring(&dllName, &result, 0);
  TurbineDwExceptionFilter::AddDllToDumpCapture(*v10);
  v11 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  v12 = GetProcAddress(v5->m_hChatClientLib, "CreateChatClient");
  if ( !v12 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
    {
      (**(void (__thiscall ***)(char *, signed int))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
      return 0;
    }
    return 0;
  }
  v14 = Turbine::Debug::GetDebugFlags();
  if ( !(unsigned __int8)((int (__cdecl *)(IChatClient **, signed int, unsigned __int32))v12)(
                           &v5->m_pChatClient,
                           1,
                           ~v14 | 0x1600)
    || (v15 = v5->m_pChatClient) == 0 )
  {
    v8 = (int)&v4[-2].m_data[12];
    v9 = InterlockedDecrement((volatile LONG *)&v4[-1]);
LABEL_22:
    if ( !v9 )
    {
      if ( v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    }
    return 0;
  }
  if ( retaddr )
  {
    v16 = retaddr + 8;
    v17 = retaddr + 4;
  }
  else
  {
    v16 = 0;
    v17 = 0;
  }
  if ( ((int (__stdcall *)(IChatClient *, char *, char *, char *, int))v15->vfptr[1].AddRef)(
         v15,
         retaddr,
         v17,
         v16,
         *(_DWORD *)&dllName.m_charbuffer->m_data[0] + 20) )
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    v13 = 0;
  }
  else
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    v13 = 1;
  }
  return v13;
}

//----- (00707270) --------------------------------------------------------  // acclient.c:794409
int sub_707270()
{
  return atexit(_E74_80);
}

//----- (00707280) --------------------------------------------------------  // acclient.c:794415
int _E76_65()
{
  return atexit(_E77_93);
}

//----- (00707290) --------------------------------------------------------  // acclient.c:794421
int _E79_59()
{
  return atexit(_E80_58);
}

//----- (007072A0) --------------------------------------------------------  // acclient.c:794427
void _E98_12()
{
  dword_86FC0C = 1024;
}

//----- (007072B0) --------------------------------------------------------  // acclient.c:794433
void sub_7072B0()
{
  dword_86FC10 = 0x7FFF;
}

//----- (007072C0) --------------------------------------------------------  // acclient.c:794439
int _E102_29()
{
  const int result; // eax@1

  result = dword_86FC0C;
  dword_86FC14 = dword_86FC0C;
  return result;
}

//----- (007072D0) --------------------------------------------------------  // acclient.c:794449
int sub_7072D0()
{
  return atexit(nullsub_1262);
}

