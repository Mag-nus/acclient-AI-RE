/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Timer
   Object     : CORE\timer\Timer.obj
   Functions  : 8
   Addresses  : 0040F7D0 - 0040FA10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040F7D0) --------------------------------------------------------  // acclient.c:75323
int __cdecl Timer::get_real_time()
{
  return _time(0);
}

//----- (0040F7E0) --------------------------------------------------------  // acclient.c:75329
long double __cdecl Timer::compute_time()
{
  long double result; // st7@2
  struct PreciseTimerInstance *v1; // esi@3

  if ( Timer::initialized_ )
  {
    v1 = Timer::s_pcTimerInstance;
    result = TimeSource_QueryPerformanceCounter::ComputeElapsedTime(&Timer::s_pcTimerInstance->m_cTimeSource, 0)
           + v1->m_rExternalOffset;
  }
  else
  {
    result = 0.0;
  }
  return result;
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;
// 8369B8: using guessed type bool Timer::initialized_;

//----- (0040F810) --------------------------------------------------------  // acclient.c:75350
long double __cdecl Timer::compute_local_time()
{
  long double result; // st7@2

  if ( Timer::initialized_ )
    result = TimeSource_QueryPerformanceCounter::ComputeElapsedTime(&Timer::s_pcTimerInstance->m_cTimeSource, 0);
  else
    result = 0.0;
  return result;
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;
// 8369B8: using guessed type bool Timer::initialized_;

//----- (0040F840) --------------------------------------------------------  // acclient.c:75364
void __cdecl Timer::set_time(const long double *now)
{
  struct PreciseTimerInstance *v1; // ecx@2
  char *v2; // esi@2
  struct PreciseTimerInstance *v3; // ebx@2
  char *v4; // edi@3
  double v5; // st7@3
  unsigned __int8 v7; // c0@3
  unsigned __int8 v8; // c3@3
  double v9; // [sp+0h] [bp-10h]@3
  double v10; // [sp+8h] [bp-8h]@2

  if ( Timer::initialized_ )
  {
    v1 = Timer::s_pcTimerInstance;
    v10 = *(double *)now;
    v2 = (char *)&Timer::s_pcTimerInstance->m_tExternalTime;
    v3 = Timer::s_pcTimerInstance;
    if ( v10 > Timer::s_pcTimerInstance->m_tExternalTime )
    {
      v4 = (char *)&Timer::s_pcTimerInstance->m_tElapsedTime;
      v9 = Timer::s_pcTimerInstance->m_tElapsedTime;
      v5 = TimeSource_QueryPerformanceCounter::ComputeElapsedTime(&Timer::s_pcTimerInstance->m_cTimeSource, 1);
      *(double *)v4 = v5;
      if ( v7 | v8 )
        *(double *)v4 = v9;
      else
        *(double *)v2 = v5 + v3->m_rExternalOffset;
      if ( v10 > *(double *)v2 + 0.000000001 )
      {
        v3->m_rExternalOffset = v10 - *(double *)v4;
        *(double *)v2 = v10;
      }
      else if ( v10 + 0.000000001 < *(double *)v2 )
      {
        *(double *)v4 = *(double *)v4 - (*(double *)v2 - v10);
        *(double *)v2 = v10;
      }
      v1 = Timer::s_pcTimerInstance;
    }
    Timer::local_time = v1->m_tElapsedTime;
    COERCE_DOUBLE(Timer::cur_time.Cmd) = v1->m_tExternalTime;
  }
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;
// 8369B8: using guessed type bool Timer::initialized_;

//----- (0040F910) --------------------------------------------------------  // acclient.c:75412
void __cdecl Timer::update_time()
{
  char *v0; // esi@2
  struct PreciseTimerInstance *v1; // edi@2
  double v2; // st7@2
  unsigned __int8 v4; // c0@2
  unsigned __int8 v5; // c3@2
  double v6; // [sp+0h] [bp-8h]@2

  if ( Timer::initialized_ )
  {
    v6 = Timer::s_pcTimerInstance->m_tElapsedTime;
    v0 = (char *)&Timer::s_pcTimerInstance->m_tElapsedTime;
    v1 = Timer::s_pcTimerInstance;
    v2 = TimeSource_QueryPerformanceCounter::ComputeElapsedTime(&Timer::s_pcTimerInstance->m_cTimeSource, 1);
    *(double *)v0 = v2;
    if ( v4 | v5 )
      *(double *)v0 = v6;
    else
      v1->m_tExternalTime = v2 + v1->m_rExternalOffset;
    Timer::local_time = Timer::s_pcTimerInstance->m_tElapsedTime;
    COERCE_DOUBLE(Timer::cur_time.Cmd) = Timer::s_pcTimerInstance->m_tExternalTime;
  }
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;
// 8369B8: using guessed type bool Timer::initialized_;

//----- (0040F9A0) --------------------------------------------------------  // acclient.c:75453
void __thiscall PreciseTimerInstance::PreciseTimerInstance(PreciseTimerInstance *this)
{
  PreciseTimerInstance *v1; // esi@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  TimeSource_QueryPerformanceCounter::TimeSource_QueryPerformanceCounter(&this->m_cTimeSource);
  v1->m_rExternalOffset = 0.0;
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  v1->m_tElapsedTime = 0.0;
  v1->m_tExternalTime = 0.0;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (0040F9E0) --------------------------------------------------------  // acclient.c:75469
void __cdecl Timer::GetTimerInstance()
{
  PreciseTimerInstance *v0; // eax@2
  struct PreciseTimerInstance *v1; // eax@3

  if ( !Timer::s_pcTimerInstance )
  {
    v0 = (PreciseTimerInstance *)operator new(0x78u);
    if ( v0 )
    {
      PreciseTimerInstance::PreciseTimerInstance(v0);
      Timer::s_pcTimerInstance = v1;
    }
    else
    {
      Timer::s_pcTimerInstance = 0;
    }
  }
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;

//----- (0040FA10) --------------------------------------------------------  // acclient.c:75491
void __cdecl Timer::Init()
{
  struct PreciseTimerInstance *v0; // eax@2
  PreciseTimerInstance *v1; // eax@3
  struct PreciseTimerInstance *v2; // esi@7

  if ( !Timer::initialized_ )
  {
    v0 = Timer::s_pcTimerInstance;
    COERCE_DOUBLE(Timer::cur_time.Cmd) = 0.0;
    Timer::local_time = 0.0;
    if ( !Timer::s_pcTimerInstance )
    {
      v1 = (PreciseTimerInstance *)operator new(0x78u);
      if ( v1 )
        PreciseTimerInstance::PreciseTimerInstance(v1);
      else
        v0 = 0;
      Timer::s_pcTimerInstance = v0;
    }
    v2 = v0;
    TimeSource_QueryPerformanceCounter::Init(&v0->m_cTimeSource);
    v2->m_bInitialized = 1;
    Timer::initialized_ = 1;
  }
}
// 8369A0: using guessed type struct PreciseTimerInstance *Timer::s_pcTimerInstance;
// 8369B8: using guessed type bool Timer::initialized_;

