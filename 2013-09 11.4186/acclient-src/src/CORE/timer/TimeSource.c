/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TimeSource
   Object     : CORE\timer\TimeSource.obj
   Functions  : 4
   Addresses  : 00410DE0 - 00410F20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00410DE0) --------------------------------------------------------  // acclient.c:77027
void __thiscall CSpinLock<512,0>::Enter(CSpinLock<512,0> *this)
{
  volatile LONG *v1; // edi@1
  unsigned int v2; // esi@1

  v1 = (volatile LONG *)this;
  v2 = 0;
  while ( InterlockedExchange(v1, 1) )
  {
    while ( *v1 )
    {
      ++v2;
      if ( v2 >= 0x200 )
      {
        Sleep(0);
        v2 = 0;
      }
    }
  }
}

//----- (00410E30) --------------------------------------------------------  // acclient.c:77049
void __thiscall TimeSource_QueryPerformanceCounter::TimeSource_QueryPerformanceCounter(TimeSource_QueryPerformanceCounter *this)
{
  this->m_SpinLock.m_Lock = 0;
  this->m_SpinLock.m_hCurThread = 0;
  this->m_SpinLock.m_nEnterCount = 0;
  this->m_cVolatileState.dwFlags = 0;
}

//----- (00410E50) --------------------------------------------------------  // acclient.c:77058
void __thiscall TimeSource_QueryPerformanceCounter::Init(TimeSource_QueryPerformanceCounter *this)
{
  TimeSource_QueryPerformanceCounter *v1; // esi@1
  char v2; // bl@1
  __int64 v3; // ST00_8@2
  int v4; // eax@4
  unsigned int v5; // eax@7
  unsigned int v6; // edx@7
  _LARGE_INTEGER i64; // [sp+Ch] [bp-8h]@1

  v1 = this;
  v2 = 0;
  if ( QueryPerformanceFrequency(&i64) )
  {
    v2 = 1;
    v3 = i64.QuadPart;
    v1->m_qwPerfsPerMS = i64.QuadPart / 1000;
    v1->m_rPerfsPerSecond = (double)i64.QuadPart;
    v1->m_qwPerfCountTolerance = v3 / 2;
    QueryPerformanceCounter(&i64);
  }
  CSpinLock<512,0>::Enter(&v1->m_SpinLock);
  if ( !(v1->m_cVolatileState.dwFlags & 1) )
  {
    v4 = i64.HighPart;
    LODWORD(v1->m_cVolatileState.qwReferenceQPC) = i64.LowPart;
    HIDWORD(v1->m_cVolatileState.qwReferenceQPC) = v4;
    v1->m_cVolatileState.tLastTime = 0.0;
    v1->m_cVolatileState.tReference = 0.0;
    v1->m_cVolatileState.dwReferenceTGT = timeGetTime();
    if ( v2 )
      v1->m_cVolatileState.dwFlags &= 0xFFFFFFFD;
    else
      v1->m_cVolatileState.dwFlags |= 2u;
    v5 = v1->m_cVolatileState.dwFlags;
    v1->m_cVolatileState.dwFlags |= 1u;
    v6 = v1->m_cVolatileState.dwFlags;
  }
  InterlockedExchange(&v1->m_SpinLock.m_Lock, 0);
}

//----- (00410F20) --------------------------------------------------------  // acclient.c:77100
long double __thiscall TimeSource_QueryPerformanceCounter::ComputeElapsedTime(TimeSource_QueryPerformanceCounter *this, bool i_bUpdateInternalData)
{
  TimeSource_QueryPerformanceCounter *v2; // ebx@1
  long double result; // st7@2
  DWORD v4; // eax@3
  unsigned int v5; // ecx@3
  long double v6; // st7@5
  unsigned int dwElapsedTGT; // [sp+10h] [bp-48h]@3
  volatile LONG *Target; // [sp+14h] [bp-44h]@1
  unsigned int dwTGT; // [sp+18h] [bp-40h]@3
  long double *v10; // [sp+1Ch] [bp-3Ch]@1
  _LARGE_INTEGER i64QPC; // [sp+28h] [bp-30h]@4
  TimeSource_QueryPerformanceCounter::StateData cState; // [sp+30h] [bp-28h]@1

  v2 = this;
  Target = &this->m_SpinLock.m_Lock;
  CSpinLock<512,0>::Enter(&this->m_SpinLock);
  v10 = &v2->m_cVolatileState.tLastTime;
  qmemcpy(&cState, &v2->m_cVolatileState, sizeof(cState));
  InterlockedExchange(Target, 0);
  if ( cState.dwFlags & 1 )
  {
    v4 = timeGetTime();
    v5 = v4 - cState.dwReferenceTGT;
    dwTGT = v4;
    dwElapsedTGT = v4 - cState.dwReferenceTGT;
    if ( cState.dwFlags & 2 )
    {
      v6 = (double)v5 * 0.001 + cState.tReference;
    }
    else
    {
      QueryPerformanceCounter(&i64QPC);
      if ( *(_QWORD *)&i64QPC - cState.qwReferenceQPC >= v2->m_qwPerfCountTolerance + v2->m_qwPerfsPerMS * dwElapsedTGT )
      {
        cState.dwFlags |= 2u;
        v6 = (double)dwElapsedTGT * 0.001 + cState.tReference;
        if ( !bComplainedAlready_0 )
          bComplainedAlready_0 = 1;
        if ( i_bUpdateInternalData && !bComplainedAlready )
          bComplainedAlready = 1;
      }
      else
      {
        v6 = (double)(*(_QWORD *)&i64QPC - cState.qwReferenceQPC) / v2->m_rPerfsPerSecond + cState.tReference;
      }
      v5 = dwElapsedTGT;
    }
    if ( v6 > cState.tLastTime )
    {
      cState.tLastTime = v6;
      if ( v5 >= 0x2710 )
      {
        cState.tReference = v6;
        cState.dwReferenceTGT = dwTGT;
        cState.qwReferenceQPC = i64QPC.QuadPart;
      }
    }
    CSpinLock<512,0>::Enter((CSpinLock<512,0> *)Target);
    if ( *v10 >= cState.tLastTime )
    {
      cState.tLastTime = *v10;
    }
    else if ( i_bUpdateInternalData )
    {
      qmemcpy(v10, &cState, 0x28u);
    }
    else
    {
      *v10 = cState.tLastTime;
    }
    InterlockedExchange(Target, 0);
    result = cState.tLastTime;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

