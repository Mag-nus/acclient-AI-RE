/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PortalThread
   Object     : CORE\newthread\PortalThread.obj
   Functions  : 6
   Addresses  : 0065D960 - 0065DA90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065D960) --------------------------------------------------------  // acclient.c:627361
void __thiscall PortalThread::~PortalThread(PortalThread *this)
{
  PortalThread *v1; // esi@1
  bool v2; // zf@1
  void *v3; // ST00_4@2
  unsigned int dwExitCode; // [sp+0h] [bp-4h]@1

  dwExitCode = (unsigned int)this;
  v1 = this;
  v2 = this->m_fThreadRunning == 0;
  this->vfptr = (PortalThreadVtbl *)&PortalThread::vftable;
  if ( !v2 )
  {
    v3 = this->m_hThread;
    dwExitCode = 0;
    GetExitCodeThread(v3, &dwExitCode);
  }
  CloseHandle(v1->m_hThread);
}
// 7FDA54: using guessed type int (__thiscall *PortalThread::vftable)(void *, char);

//----- (0065D9A0) --------------------------------------------------------  // acclient.c:627383
char __thiscall PortalThread::Resume(PortalThread *this)
{
  PortalThread *v1; // esi@1
  char result; // al@4

  v1 = this;
  if ( ResumeThread(this->m_hThread) == 1 )
  {
    while ( !v1->m_fThreadHasEverRun )
      Sleep(0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065D9E0) --------------------------------------------------------  // acclient.c:627403
bool __thiscall PortalThread::Join(PortalThread *this)
{
  bool result; // al@2

  if ( this->m_fThreadRunning )
    result = WaitForSingleObject(this->m_hThread, 0xFFFFFFFF) == 0;
  else
    result = 1;
  return result;
}

//----- (0065DA00) --------------------------------------------------------  // acclient.c:627415
PortalThread *__thiscall PortalThread::scalar_deleting_destructor(PortalThread *this, unsigned int a2)
{
  PortalThread *v2; // esi@1
  bool v3; // zf@1
  void *v4; // ST00_4@2
  unsigned int ExitCode; // [sp+0h] [bp-4h]@1

  ExitCode = (unsigned int)this;
  v2 = this;
  v3 = this->m_fThreadRunning == 0;
  this->vfptr = (PortalThreadVtbl *)&PortalThread::vftable;
  if ( !v3 )
  {
    v4 = this->m_hThread;
    ExitCode = 0;
    GetExitCodeThread(v4, &ExitCode);
  }
  CloseHandle(v2->m_hThread);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FDA54: using guessed type int (__thiscall *PortalThread::vftable)(void *, char);

//----- (0065DA50) --------------------------------------------------------  // acclient.c:627440
int __stdcall PortalThread::_portal_startup(void *i_lpdwparam)
{
  int result; // eax@3

  *((_BYTE *)i_lpdwparam + 12) = 1;
  *((_BYTE *)i_lpdwparam + 14) = 1;
  if ( Turbine::Debug::IsDebugFlagSet(0x400u) )
    Turbine::Debug::SetFloatingPointException(1, 8u);
  result = (*(int (__thiscall **)(void *))(*(_DWORD *)i_lpdwparam + 4))(i_lpdwparam);
  *((_BYTE *)i_lpdwparam + 12) = 0;
  return result;
}

//----- (0065DA90) --------------------------------------------------------  // acclient.c:627454
void __thiscall PortalThread::PortalThread(PortalThread *this, unsigned int i_defaultStackSize)
{
  PortalThread *v2; // esi@1
  HANDLE v3; // eax@1
  char *v4; // ecx@2

  v2 = this;
  this->vfptr = (PortalThreadVtbl *)&PortalThread::vftable;
  this->m_hThread = 0;
  this->m_fThreadRunning = 0;
  this->m_fShouldExit = 0;
  this->m_fThreadHasEverRun = 0;
  v3 = CreateThread(
         0,
         i_defaultStackSize,
         (LPTHREAD_START_ROUTINE)PortalThread::_portal_startup,
         this,
         4u,
         &this->m_idThread);
  v2->m_hThread = v3;
  if ( !v3 )
  {
    GetLastError();
    PortalThreadErrorDump::DumpLastError(v4);
  }
}
// 7FDA54: using guessed type int (__thiscall *PortalThread::vftable)(void *, char);

