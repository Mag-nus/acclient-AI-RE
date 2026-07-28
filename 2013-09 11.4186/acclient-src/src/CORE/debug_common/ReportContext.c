/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ReportContext
   Object     : CORE\debug_common\ReportContext.obj
   Functions  : 2
   Addresses  : 0040E450 - 0040E470 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040E450) --------------------------------------------------------  // acclient.c:74002
void __thiscall DbgReportContext::~DbgReportContext(DbgReportContext *this)
{
  DbgReportContext *v1; // esi@1

  v1 = this;
  CloseHandle(this->m_hThread);
  CloseHandle(v1->m_hProcess);
}

//----- (0040E470) --------------------------------------------------------  // acclient.c:74012
void __thiscall DbgReportContext::DbgReportContext(DbgReportContext *this, _EXCEPTION_POINTERS *pep)
{
  DbgReportContext *v2; // esi@1
  HANDLE v3; // edi@1
  HANDLE v4; // eax@1
  HANDLE v5; // edi@3
  HANDLE v6; // eax@3
  _CONTEXT *v7; // eax@6
  void *TargetHandle; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = GetCurrentProcess();
  TargetHandle = v3;
  v4 = GetCurrentProcess();
  if ( DuplicateHandle(v4, v3, v4, &TargetHandle, 0, 1, 2u) )
    v3 = TargetHandle;
  v2->m_hProcess = v3;
  v2->m_idThread = GetCurrentThreadId();
  v5 = GetCurrentThread();
  TargetHandle = v5;
  v6 = GetCurrentProcess();
  if ( DuplicateHandle(v6, v5, v6, &TargetHandle, 0, 1, 2u) )
    v5 = TargetHandle;
  v2->m_hThread = v5;
  if ( pep && (v7 = pep->ContextRecord) != 0 )
    v2->m_hModule = GetModuleFromAddress((char *)v7->Eip);
  else
    v2->m_hModule = GetModuleHandleA(0);
}

