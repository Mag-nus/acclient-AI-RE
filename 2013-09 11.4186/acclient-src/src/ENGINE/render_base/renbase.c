/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : renbase
   Object     : ENGINE\render_base\renbase.obj
   Functions  : 86
   Addresses  : 006BCD70 - 006BF140 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BCD70) --------------------------------------------------------  // acclient.c:724693
HRESULT __stdcall CBaseVideoRenderer::QueryInterface(CBaseInputPin *this, _GUID *riid, void **ppv)
{
  return (**(int (__stdcall ***)(char *, _GUID *, void **))this[-1].m_SampleProps.pbBuffer)(
           this[-1].m_SampleProps.pbBuffer,
           riid,
           ppv);
}

//----- (006BCD80) --------------------------------------------------------  // acclient.c:724702
int __stdcall CBaseVideoRenderer::AddRef(CBaseInputPin *this)
{
  return (*(int (__stdcall **)(char *))(*(_DWORD *)this[-1].m_SampleProps.pbBuffer + 4))(this[-1].m_SampleProps.pbBuffer);
}

//----- (006BCD90) --------------------------------------------------------  // acclient.c:724708
int __stdcall CBaseFilter::Release(CBaseInputPin *this)
{
  return (*(int (__stdcall **)(char *))(*(_DWORD *)this[-1].m_SampleProps.pbBuffer + 8))(this[-1].m_SampleProps.pbBuffer);
}

//----- (006BCDA0) --------------------------------------------------------  // acclient.c:724714
HRESULT __stdcall CBaseInputPin::QueryInterface(CBaseInputPin *this, _GUID *a2, void **a3)
{
  return CBaseVideoRenderer::QueryInterface((CBaseInputPin *)((char *)this - 4), a2, a3);
}

//----- (006BCDB0) --------------------------------------------------------  // acclient.c:724720
int __stdcall CBaseFilter::AddRef(int a1)
{
  return CBaseVideoRenderer::AddRef((CBaseInputPin *)(a1 - 4));
}

//----- (006BCDC0) --------------------------------------------------------  // acclient.c:724726
int __stdcall CBaseVideoRenderer::Release(int a1)
{
  return CBaseFilter::Release((CBaseInputPin *)(a1 - 4));
}

//----- (006BCEB0) --------------------------------------------------------  // acclient.c:724809
void __thiscall CAutoLock::CAutoLock(CAutoLock *this, CCritSec *plock)
{
  this->m_pLock = plock;
  EnterCriticalSection(&plock->m_CritSec);
}

//----- (006BCED0) --------------------------------------------------------  // acclient.c:724816
void __thiscall CBaseRenderer::CBaseRenderer(CBaseRenderer *this, _GUID *RenderClass, char *pName, IUnknown *pUnk, HRESULT *phr)
{
  CBaseRenderer *v5; // esi@1
  _RTL_CRITICAL_SECTION *v6; // ebx@1

  v5 = this;
  v6 = &this->m_InterfaceLock.m_CritSec;
  CBaseFilter::CBaseFilter((CBaseFilter *)&this->vfptr, pName, pUnk, &this->m_InterfaceLock, RenderClass);
  v5->vfptr = (INonDelegatingUnknownVtbl *)&CBaseRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  v5->m_pPosition = 0;
  CAMEvent::CAMEvent(&v5->m_RenderEvent, 0);
  CAMEvent::CAMEvent(&v5->m_ThreadSignal, 1);
  CAMEvent::CAMEvent(&v5->m_evComplete, 1);
  v5->m_bAbort = 0;
  v5->m_bStreaming = 0;
  v5->m_dwAdvise = 0;
  v5->m_pMediaSample = 0;
  v5->m_bEOS = 0;
  v5->m_bEOSDelivered = 0;
  v5->m_pInputPin = 0;
  InitializeCriticalSection(v6);
  InitializeCriticalSection(&v5->m_RendererLock.m_CritSec);
  v5->m_pQSink = 0;
  v5->m_bRepaintStatus = 1;
  v5->m_bInReceive = 0;
  LODWORD(v5->m_SignalTime) = 0;
  HIDWORD(v5->m_SignalTime) = 0;
  v5->m_EndOfStreamTimer = 0;
  InitializeCriticalSection(&v5->m_ObjectCreationLock.m_CritSec);
  SetEvent(v5->m_evComplete.m_hEvent);
}
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806CC0: using guessed type __int32 (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806D00: using guessed type __int32 (__stdcall *CBaseRenderer::vftable)(CBaseRenderer *this, _GUID *riid, void **ppv);

//----- (006BCFA0) --------------------------------------------------------  // acclient.c:724854
HRESULT __thiscall CBaseRenderer::GetMediaPositionInterface(CBaseRenderer *this, _GUID *riid, void **ppv)
{
  CBaseRenderer *v3; // esi@1
  _RTL_CRITICAL_SECTION *v4; // edi@1
  CRendererPosPassThru *v5; // eax@1
  int v6; // esi@2
  HRESULT result; // eax@2
  CRendererPosPassThru *v8; // ebx@3
  int v9; // eax@4
  IPin *v10; // ecx@5
  int v11; // eax@7
  int v12; // esi@13
  HRESULT hr; // [sp+4h] [bp-4h]@1

  hr = (HRESULT)this;
  v3 = this;
  v4 = &this->m_ObjectCreationLock.m_CritSec;
  EnterCriticalSection(&this->m_ObjectCreationLock.m_CritSec);
  v5 = v3->m_pPosition;
  if ( v5 )
  {
    v6 = v5->vfptr->NonDelegatingQueryInterface(&v5->vfptr, riid, ppv);
    LeaveCriticalSection(v4);
    result = v6;
  }
  else
  {
    hr = 0;
    v8 = (CRendererPosPassThru *)operator new(0x50u);
    if ( v8 )
    {
      v9 = ((int (__thiscall *)(CBaseRenderer *, _DWORD))v3->vfptr[2].NonDelegatingAddRef)(v3, 0);
      if ( v9 )
        v10 = (IPin *)(v9 + 12);
      else
        v10 = 0;
      CRendererPosPassThru::CRendererPosPassThru(v8, "Renderer CPosPassThru", v3->m_pUnknown, &hr, v10);
    }
    else
    {
      v11 = 0;
    }
    v3->m_pPosition = (CRendererPosPassThru *)v11;
    if ( v11 )
    {
      if ( hr >= 0 )
      {
        v12 = ((int (__thiscall *)(CBaseRenderer *, _GUID *, void **))v3->vfptr[3].NonDelegatingQueryInterface)(
                v3,
                riid,
                ppv);
        LeaveCriticalSection(v4);
        result = v12;
      }
      else
      {
        (*(void (__thiscall **)(int, signed int))(*(_DWORD *)(v11 + 8) + 12))(v11 + 8, 1);
        v3->m_pPosition = 0;
        LeaveCriticalSection(v4);
        result = -2147467262;
      }
    }
    else
    {
      LeaveCriticalSection(v4);
      result = -2147024882;
    }
  }
  return result;
}

//----- (006BD090) --------------------------------------------------------  // acclient.c:724926
HRESULT __stdcall CBaseRenderer::NonDelegatingQueryInterface(CBaseRenderer *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@3

  if ( !memcmp(riid, &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770, 0x10u) || !memcmp(riid, &IID_IMediaSeeking, 0x10u) )
    result = ((int (__stdcall *)(_GUID *, void **))this->vfptr[3].NonDelegatingQueryInterface)(riid, ppv);
  else
    result = CBaseFilter::NonDelegatingQueryInterface((CBaseFilter *)&this->vfptr, riid, ppv);
  return result;
}

//----- (006BD0E0) --------------------------------------------------------  // acclient.c:724938
HRESULT __thiscall CBaseRenderer::SourceThreadCanWait(CBaseRenderer *this, int bCanWait)
{
  HRESULT result; // eax@2

  if ( bCanWait == 1 )
  {
    ResetEvent(this->m_ThreadSignal.m_hEvent);
    result = 0;
  }
  else
  {
    SetEvent(this->m_ThreadSignal.m_hEvent);
    result = 0;
  }
  return result;
}

//----- (006BD110) --------------------------------------------------------  // acclient.c:724956
void __thiscall CBaseRenderer::WaitForReceiveToComplete(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  DWORD v2; // eax@4
  tagMSG msg; // [sp+4h] [bp-1Ch]@2

  v1 = this;
  while ( v1->m_bInReceive )
  {
    PeekMessageA(&msg, 0, 0, 0, 0);
    Sleep(1u);
  }
  if ( (GetQueueStatus(8u) >> 16) & 8 )
  {
    v2 = GetCurrentThreadId();
    PostThreadMessageA(v2, 0, 0, 0);
  }
}

//----- (006BD180) --------------------------------------------------------  // acclient.c:724976
HRESULT __stdcall CBaseRenderer::GetState(CBaseRenderer *this, unsigned int dwMSecs, _FilterState *State)
{
  HRESULT result; // eax@2

  if ( State )
  {
    if ( WaitDispatchingMessages(this->m_pPosition, dwMSecs, 0, 0, 0) == 258 )
    {
      *State = this->m_cRef;
      result = 262711;
    }
    else
    {
      *State = this->m_cRef;
      result = 0;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BD1D0) --------------------------------------------------------  // acclient.c:725001
HRESULT __thiscall CBaseRenderer::CompleteStateChange(CBaseRenderer *this, _FilterState OldState)
{
  CBaseRenderer *v2; // esi@1
  HRESULT result; // eax@3

  v2 = this;
  if ( !this->m_pInputPin->m_Connected )
    goto LABEL_10;
  if ( this->m_bEOS == 1 )
  {
    SetEvent(this->m_evComplete.m_hEvent);
    return 0;
  }
  if ( ((int (__thiscall *)(CBaseRenderer *))this->vfptr[13].NonDelegatingAddRef)(this) != 1
    || OldState == State_Stopped )
  {
    ResetEvent(v2->m_evComplete.m_hEvent);
    result = 1;
  }
  else
  {
LABEL_10:
    SetEvent(v2->m_evComplete.m_hEvent);
    result = 0;
  }
  return result;
}

//----- (006BD230) --------------------------------------------------------  // acclient.c:725030
HRESULT __stdcall CBaseRenderer::FindPin(CBaseRenderer *this, const unsigned __int16 *Id, IPin **ppPin)
{
  HRESULT result; // eax@2
  int v4; // eax@4
  IPin *v5; // eax@5

  if ( ppPin )
  {
    if ( lstrcmpWInternal(Id, L"In") )
    {
      *ppPin = 0;
      result = -2147220970;
    }
    else
    {
      v4 = (*(int (__thiscall **)(void **, _DWORD))((int (__thiscall **)(_DWORD, _DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                                  + 7))(
             &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
             0);
      if ( v4 )
      {
        v5 = (IPin *)(v4 + 12);
        *ppPin = v5;
        v5->vfptr->AddRef((IUnknown *)v5);
        result = 0;
      }
      else
      {
        *ppPin = 0;
        (*(void (__stdcall **)(_DWORD))(v0 + 4))(0);
        result = 0;
      }
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BD2A0) --------------------------------------------------------  // acclient.c:725072
HRESULT __thiscall CBaseRenderer::EndOfStream(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  IMediaSample *v2; // eax@2

  v1 = this;
  if ( this->m_State )
  {
    v2 = this->m_pMediaSample;
    this->m_bEOS = 1;
    if ( !v2 )
    {
      SetEvent(this->m_evComplete.m_hEvent);
      if ( v1->m_bStreaming )
        ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[8].NonDelegatingQueryInterface)(v1);
    }
  }
  return 0;
}

//----- (006BD2E0) --------------------------------------------------------  // acclient.c:725093
HRESULT __thiscall CBaseRenderer::BeginFlush(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1

  v1 = this;
  if ( this->m_State == 1 )
    ResetEvent(this->m_evComplete.m_hEvent);
  ((void (__thiscall *)(CBaseRenderer *, _DWORD))v1->vfptr[3].NonDelegatingAddRef)(v1, 0);
  ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[9].NonDelegatingQueryInterface)(v1);
  ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[9].NonDelegatingAddRef)(v1);
  CBaseRenderer::WaitForReceiveToComplete(v1);
  return 0;
}

//----- (006BD320) --------------------------------------------------------  // acclient.c:725108
HRESULT __thiscall CBaseRenderer::EndFlush(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  CRendererPosPassThru *v2; // ecx@1

  v1 = this;
  v2 = this->m_pPosition;
  if ( v2 )
    CRendererPosPassThru::ResetMediaTime(v2);
  ((void (__thiscall *)(CBaseRenderer *, signed int))v1->vfptr[3].NonDelegatingAddRef)(v1, 1);
  return 0;
}

//----- (006BD340) --------------------------------------------------------  // acclient.c:725122
HRESULT __thiscall CBaseRenderer::Inactive(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  CRendererPosPassThru *v2; // ecx@1

  v1 = this;
  v2 = this->m_pPosition;
  if ( v2 )
    CRendererPosPassThru::ResetMediaTime(v2);
  ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[9].NonDelegatingAddRef)(v1);
  return 0;
}

//----- (006BD360) --------------------------------------------------------  // acclient.c:725136
HRESULT __thiscall CBaseRenderer::GetSampleTimes(CBaseRenderer *this, IMediaSample *pMediaSample, __int64 *pStartTime, __int64 *pEndTime)
{
  CBaseRenderer *v4; // ebx@1
  HRESULT result; // eax@3

  v4 = this;
  if ( ((int (__stdcall *)(IMediaSample *, __int64 *, __int64 *))pMediaSample->vfptr[1].Release)(
         pMediaSample,
         pStartTime,
         pEndTime) < 0 )
    goto LABEL_9;
  if ( *pEndTime < *pStartTime )
    return -2147220952;
  if ( v4->m_pClock )
    result = ((int (__thiscall *)(CBaseRenderer *, IMediaSample *, __int64 *, __int64 *))v4->vfptr[7].NonDelegatingRelease)(
               v4,
               pMediaSample,
               pStartTime,
               pEndTime);
  else
LABEL_9:
    result = 0;
  return result;
}

//----- (006BD3C0) --------------------------------------------------------  // acclient.c:725162
HRESULT __stdcall CBaseRenderer::ShouldDrawSampleNow(IMediaSample *pMediaSample, __int64 *ptrStart, __int64 *ptrEnd)
{
  return 1;
}

//----- (006BD3D0) --------------------------------------------------------  // acclient.c:725168
BOOL __thiscall CBaseRenderer::CancelNotification(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = this->m_dwAdvise;
  if ( v2 )
  {
    ((void (__stdcall *)(IReferenceClock *, unsigned int))this->m_pClock->vfptr[2].QueryInterface)(this->m_pClock, v2);
    v1->m_dwAdvise = 0;
  }
  ResetEvent(v1->m_RenderEvent.m_hEvent);
  return v2 == 0;
}

//----- (006BD400) --------------------------------------------------------  // acclient.c:725185
int __thiscall CBaseRenderer::ScheduleSample(CBaseRenderer *this, IMediaSample *pMediaSample)
{
  CBaseRenderer *v2; // esi@1
  int result; // eax@2
  int v4; // eax@3
  __int64 StartSample; // [sp+Ch] [bp-10h]@3
  __int64 EndSample; // [sp+14h] [bp-8h]@3

  v2 = this;
  if ( pMediaSample
    && (v4 = ((int (__stdcall *)(IMediaSample *, __int64 *, __int64 *))this->vfptr[7].NonDelegatingAddRef)(
               pMediaSample,
               &StartSample,
               &EndSample),
        v4 >= 0) )
  {
    if ( v4 )
    {
      result = ((int (__stdcall *)(IReferenceClock *, _DWORD, _DWORD, _DWORD, _DWORD, void *, int))v2->m_pClock->vfptr[1].AddRef)(
                 v2->m_pClock,
                 LODWORD(v2->m_tStart.m_time),
                 HIDWORD(v2->m_tStart.m_time),
                 StartSample,
                 HIDWORD(StartSample),
                 v2->m_RenderEvent.m_hEvent,
                 &v2->m_dwAdvise) >= 0;
    }
    else
    {
      SetEvent(v2->m_RenderEvent.m_hEvent);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006BD480) --------------------------------------------------------  // acclient.c:725226
HRESULT __thiscall CBaseRenderer::Render(CBaseRenderer *this, IMediaSample *pMediaSample)
{
  CBaseRenderer *v2; // esi@1
  HRESULT result; // eax@3

  v2 = this;
  if ( pMediaSample && this->m_bStreaming )
  {
    this->vfptr[4].NonDelegatingRelease((INonDelegatingUnknown *)pMediaSample);
    ((void (__thiscall *)(CBaseRenderer *, IMediaSample *))v2->vfptr[14].NonDelegatingAddRef)(v2, pMediaSample);
    ((void (__thiscall *)(CBaseRenderer *, IMediaSample *))v2->vfptr[5].NonDelegatingQueryInterface)(v2, pMediaSample);
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006BD4C0) --------------------------------------------------------  // acclient.c:725247
int __thiscall CBaseRenderer::HaveCurrentSample(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  int v3; // esi@1

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v3 = v1->m_pMediaSample != 0;
  LeaveCriticalSection(v2);
  return v3;
}

//----- (006BD4F0) --------------------------------------------------------  // acclient.c:725262
IMediaSample *__thiscall CBaseRenderer::GetCurrentSample(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  IMediaSample *v3; // eax@1
  IMediaSample *v4; // esi@3

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v3 = v1->m_pMediaSample;
  if ( v3 )
    v3->vfptr->AddRef((IUnknown *)v1->m_pMediaSample);
  v4 = v1->m_pMediaSample;
  LeaveCriticalSection(v2);
  return v4;
}

//----- (006BD520) --------------------------------------------------------  // acclient.c:725281
HRESULT __thiscall CBaseRenderer::Receive(CBaseRenderer *this, IMediaSample *pSample)
{
  CBaseRenderer *v2; // esi@1
  unsigned int v3; // eax@1
  HRESULT result; // eax@2

  v2 = this;
  v3 = this->vfptr[12].NonDelegatingRelease((INonDelegatingUnknown *)pSample);
  if ( (v3 & 0x80000000) != 0 )
    return v3 == -2147220949 ? 0 : v3;
  if ( v2->m_State == 1 )
  {
    ((void (__thiscall *)(CBaseRenderer *))v2->vfptr[6].NonDelegatingRelease)(v2);
    v2->m_bInReceive = 0;
    EnterCriticalSection(&v2->m_InterfaceLock.m_CritSec);
    if ( v2->m_State == State_Stopped )
    {
      LeaveCriticalSection(&v2->m_InterfaceLock.m_CritSec);
      return 0;
    }
    v2->m_bInReceive = 1;
    EnterCriticalSection(&v2->m_RendererLock.m_CritSec);
    ((void (__thiscall *)(CBaseRenderer *, IMediaSample *))v2->vfptr[4].NonDelegatingAddRef)(v2, pSample);
    LeaveCriticalSection(&v2->m_RendererLock.m_CritSec);
    LeaveCriticalSection(&v2->m_InterfaceLock.m_CritSec);
    SetEvent(v2->m_evComplete.m_hEvent);
  }
  if ( ((int (__thiscall *)(CBaseRenderer *))v2->vfptr[3].NonDelegatingRelease)(v2) >= 0 )
  {
    ((void (__thiscall *)(CBaseRenderer *))v2->vfptr[6].NonDelegatingRelease)(v2);
    v2->m_bInReceive = 0;
    EnterCriticalSection(&v2->m_InterfaceLock.m_CritSec);
    if ( v2->m_State )
    {
      EnterCriticalSection(&v2->m_RendererLock.m_CritSec);
      ((void (__thiscall *)(CBaseRenderer *, IMediaSample *))v2->vfptr[14].NonDelegatingQueryInterface)(
        v2,
        v2->m_pMediaSample);
      ((void (__thiscall *)(CBaseRenderer *))v2->vfptr[9].NonDelegatingAddRef)(v2);
      ((void (__thiscall *)(CBaseRenderer *))v2->vfptr[8].NonDelegatingQueryInterface)(v2);
      ((void (__thiscall *)(CBaseRenderer *))v2->vfptr[9].NonDelegatingQueryInterface)(v2);
      LeaveCriticalSection(&v2->m_RendererLock.m_CritSec);
      LeaveCriticalSection(&v2->m_InterfaceLock.m_CritSec);
      result = 0;
    }
    else
    {
      LeaveCriticalSection(&v2->m_InterfaceLock.m_CritSec);
      result = 0;
    }
  }
  else
  {
    v2->m_bInReceive = 0;
    result = 0;
  }
  return result;
}

//----- (006BD640) --------------------------------------------------------  // acclient.c:725341
HRESULT __thiscall CBaseRenderer::ClearPendingSample(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  IMediaSample *v3; // eax@1

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v3 = v1->m_pMediaSample;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v1->m_pMediaSample);
    v1->m_pMediaSample = 0;
  }
  LeaveCriticalSection(v2);
  return 0;
}

//----- (006BD680) --------------------------------------------------------  // acclient.c:725361
HRESULT __thiscall CBaseRenderer::NotifyEndOfStream(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  HRESULT result; // eax@2
  CRendererPosPassThru *v4; // ecx@3
  HRESULT v5; // esi@5

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  if ( v1->m_bStreaming )
  {
    v4 = v1->m_pPosition;
    v1->m_EndOfStreamTimer = 0;
    if ( v4 )
      CRendererPosPassThru::EOS(v4);
    v1->m_bEOSDelivered = 1;
    v5 = CBaseFilter::NotifyEvent((CBaseFilter *)&v1->vfptr, 1, 0, (int)&v1->vfptr);
    LeaveCriticalSection(v2);
    result = v5;
  }
  else
  {
    LeaveCriticalSection(v2);
    result = 0;
  }
  return result;
}

//----- (006BD6E0) --------------------------------------------------------  // acclient.c:725392
HRESULT __thiscall CBaseRenderer::StartStreaming(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  INonDelegatingUnknownVtbl *v3; // edx@2
  int v4; // esi@3

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  if ( v1->m_bStreaming != 1 )
  {
    v1->m_bStreaming = 1;
    timeBeginPeriod(1u);
    ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[5].NonDelegatingAddRef)(v1);
    v3 = v1->vfptr;
    if ( !v1->m_pMediaSample )
    {
      v4 = ((int (__thiscall *)(CBaseRenderer *))v3[8].NonDelegatingQueryInterface)(v1);
      LeaveCriticalSection(v2);
      return v4;
    }
    if ( !((int (__thiscall *)(CBaseRenderer *, IMediaSample *))v3[7].NonDelegatingQueryInterface)(
            v1,
            v1->m_pMediaSample) )
      SetEvent(v1->m_RenderEvent.m_hEvent);
  }
  LeaveCriticalSection(v2);
  return 0;
}

//----- (006BD750) --------------------------------------------------------  // acclient.c:725424
HRESULT __thiscall CBaseRenderer::StopStreaming(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  int v3; // ecx@1

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v3 = v1->m_bStreaming;
  v1->m_bEOSDelivered = 0;
  if ( v3 == 1 )
  {
    v1->m_bStreaming = 0;
    ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[5].NonDelegatingRelease)(v1);
    timeEndPeriod(1u);
  }
  LeaveCriticalSection(v2);
  return 0;
}

//----- (006BD790) --------------------------------------------------------  // acclient.c:725446
void __thiscall CBaseRenderer::SetRepaintStatus(CBaseRenderer *this, int bRepaint)
{
  CBaseRenderer *v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // edi@1

  v2 = this;
  v3 = &this->m_RendererLock.m_CritSec;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v2->m_bRepaintStatus = bRepaint;
  LeaveCriticalSection(v3);
}

//----- (006BD7C0) --------------------------------------------------------  // acclient.c:725459
void __thiscall CRendererInputPin::CRendererInputPin(CRendererInputPin *this, CBaseRenderer *pRenderer, HRESULT *phr, const unsigned __int16 *pPinName)
{
  CRendererInputPin *v4; // esi@1

  v4 = this;
  CBaseInputPin::CBaseInputPin(
    (CBaseInputPin *)&this->vfptr,
    "Renderer pin",
    (CBaseFilter *)&pRenderer->vfptr,
    &pRenderer->m_InterfaceLock,
    phr,
    pPinName);
  v4->m_pRenderer = pRenderer;
  v4->vfptr = (INonDelegatingUnknownVtbl *)&CRendererInputPin::vftable;
  v4->vfptr = (IUnknownVtbl *)&CRendererInputPin::vftable;
  v4->vfptr = (IUnknownVtbl *)&CRendererInputPin::vftable;
  v4->vfptr = (IUnknownVtbl *)&CRendererInputPin::vftable;
}
// 806DD4: using guessed type int (__stdcall *CRendererInputPin::vftable)(CBaseInputPin *this, int, int);
// 806DF8: using guessed type int (__stdcall *CRendererInputPin::vftable)(CBaseVideoRenderer *this, int, int);
// 806E10: using guessed type __int32 (__stdcall *CRendererInputPin::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806E58: using guessed type __int32 (__stdcall *CRendererInputPin::vftable)(CBaseInputPin *this, _GUID *riid, void **ppv);

//----- (006BD810) --------------------------------------------------------  // acclient.c:725483
HRESULT __stdcall CRendererInputPin::EndOfStream(CRendererInputPin *this)
{
  _RTL_CRITICAL_SECTION *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  int v3; // ebp@1

  v1 = (_RTL_CRITICAL_SECTION *)this->m_SampleProps.pMediaType[1].formattype.Data4;
  EnterCriticalSection(v1);
  v2 = (_RTL_CRITICAL_SECTION *)&this->m_SampleProps.pMediaType[2].majortype.Data2;
  EnterCriticalSection(v2);
  v3 = (*(int (__thiscall **)(int *))(this[-1].m_SampleProps.cbBuffer + 56))(&this[-1].m_SampleProps.cbBuffer);
  if ( !v3 )
  {
    v3 = (*(int (**)(void))(this->m_SampleProps.pMediaType->majortype.Data1 + 104))();
    if ( v3 >= 0 )
      v3 = InfoRegion::GetVitaeModifier((Enchantment *)this);
  }
  LeaveCriticalSection(v2);
  LeaveCriticalSection(v1);
  return v3;
}

//----- (006BD880) --------------------------------------------------------  // acclient.c:725506
HRESULT __stdcall CRendererInputPin::BeginFlush(CRendererInputPin *this)
{
  _RTL_CRITICAL_SECTION *v1; // edi@1
  _RTL_CRITICAL_SECTION *v2; // ebx@1
  int v3; // esi@1

  v1 = (_RTL_CRITICAL_SECTION *)this->m_SampleProps.pMediaType[1].formattype.Data4;
  EnterCriticalSection(v1);
  v2 = (_RTL_CRITICAL_SECTION *)&this->m_SampleProps.pMediaType[2].majortype.Data2;
  EnterCriticalSection(v2);
  CBaseInputPin::BeginFlush((CBaseInputPin *)&this->vfptr);
  (*(void (**)(void))(this->m_SampleProps.pMediaType->majortype.Data1 + 132))();
  LeaveCriticalSection(v2);
  v3 = (*(int (**)(void))(this->m_SampleProps.pMediaType->majortype.Data1 + 100))();
  LeaveCriticalSection(v1);
  return v3;
}

//----- (006BD8E0) --------------------------------------------------------  // acclient.c:725525
HRESULT __stdcall CRendererInputPin::EndFlush(CRendererInputPin *this)
{
  _RTL_CRITICAL_SECTION *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  int v3; // ebp@1

  v1 = (_RTL_CRITICAL_SECTION *)this->m_SampleProps.pMediaType[1].formattype.Data4;
  EnterCriticalSection(v1);
  v2 = (_RTL_CRITICAL_SECTION *)&this->m_SampleProps.pMediaType[2].majortype.Data2;
  EnterCriticalSection(v2);
  v3 = (*(int (**)(void))(this->m_SampleProps.pMediaType->majortype.Data1 + 136))();
  if ( v3 >= 0 )
    v3 = CBaseInputPin::EndFlush((CBaseInputPin *)&this->vfptr);
  LeaveCriticalSection(v2);
  LeaveCriticalSection(v1);
  return v3;
}

//----- (006BD940) --------------------------------------------------------  // acclient.c:725544
HRESULT __stdcall CRendererInputPin::Receive(CRendererInputPin *this, IMediaSample *pSample)
{
  CRendererInputPin *v2; // esi@1
  int v3; // ebx@1
  _RTL_CRITICAL_SECTION *v4; // edi@2
  int v5; // ecx@4
  int v6; // ecx@6

  v2 = this;
  v3 = (*(int (__stdcall **)(IMediaSample *))(**(_DWORD **)&this->m_mt.majortype.Data4[4] + 156))(pSample);
  if ( v3 < 0 )
  {
    v4 = (_RTL_CRITICAL_SECTION *)(*(_DWORD *)&v2->m_mt.majortype.Data4[4] + 124);
    EnterCriticalSection(v4);
    if ( v2[-1].m_mt.pUnk[5].vfptr )
    {
      if ( !BYTE1(v2->m_cRef) )
      {
        v5 = *(_DWORD *)&v2->m_mt.majortype.Data4[4];
        if ( !*(_DWORD *)(v5 + 96) && !v2[-1].m_mt.formattype.Data4[4] )
        {
          CBaseFilter::NotifyEvent((CBaseFilter *)v5, 3, v3, 0);
          CAutoLock::CAutoLock((CAutoLock *)&this, (CCritSec *)(*(_DWORD *)&v2->m_mt.majortype.Data4[4] + 148));
          v6 = *(_DWORD *)&v2->m_mt.majortype.Data4[4];
          if ( *(_DWORD *)(v6 + 100) && !*(_DWORD *)(v6 + 116) )
            CBaseRenderer::NotifyEndOfStream((CBaseRenderer *)v6);
          LeaveCriticalSection((LPCRITICAL_SECTION)this);
          v2[-1].m_mt.formattype.Data4[4] = 1;
        }
      }
    }
    LeaveCriticalSection(v4);
  }
  return v3;
}

//----- (006BD9E0) --------------------------------------------------------  // acclient.c:725581
HRESULT __thiscall CRendererInputPin::BreakConnect(CRendererInputPin *this)
{
  CBaseInputPin *v1; // esi@1
  HRESULT result; // eax@1

  v1 = (CBaseInputPin *)this;
  result = ((int (*)(void))this->m_pRenderer->vfptr[11].NonDelegatingRelease)();
  if ( result >= 0 )
    result = CBaseInputPin::BreakConnect(v1);
  return result;
}

//----- (006BDA00) --------------------------------------------------------  // acclient.c:725594
HRESULT __thiscall CRendererInputPin::CompleteConnect(CRendererInputPin *this, IPin *pReceivePin)
{
  HRESULT result; // eax@1

  result = this->m_pRenderer->vfptr[12].NonDelegatingAddRef((INonDelegatingUnknown *)pReceivePin);
  if ( result >= 0 )
    result = InfoRegion::GetVitaeModifier((Enchantment *)pReceivePin);
  return result;
}

//----- (006BDA30) --------------------------------------------------------  // acclient.c:725605
HRESULT __stdcall CRendererInputPin::QueryId(CRendererInputPin *this, unsigned __int16 **Id)
{
  HRESULT result; // eax@2
  unsigned __int16 *v3; // eax@3

  if ( Id )
  {
    v3 = (unsigned __int16 *)CoTaskMemAlloc(8u);
    *Id = v3;
    if ( v3 )
    {
      lstrcpyWInternal(v3, L"In");
      result = 0;
    }
    else
    {
      result = -2147024882;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BDA70) --------------------------------------------------------  // acclient.c:725632
HRESULT __thiscall CRendererInputPin::CheckMediaType(CRendererInputPin *this, CMediaType *pmt)
{
  return this->m_pRenderer->vfptr[14].NonDelegatingRelease((INonDelegatingUnknown *)pmt);
}

//----- (006BDA80) --------------------------------------------------------  // acclient.c:725638
HRESULT __thiscall CRendererInputPin::Active(CRendererInputPin *this)
{
  return ((int (*)(void))this->m_pRenderer->vfptr[9].NonDelegatingRelease)();
}

//----- (006BDA90) --------------------------------------------------------  // acclient.c:725644
HRESULT __thiscall CRendererInputPin::Inactive(CRendererInputPin *this)
{
  this->m_bRunTimeError = 0;
  return ((int (*)(void))this->m_pRenderer->vfptr[10].NonDelegatingQueryInterface)();
}

//----- (006BDAA0) --------------------------------------------------------  // acclient.c:725651
HRESULT __thiscall CRendererInputPin::SetMediaType(CRendererInputPin *this, CMediaType *pmt)
{
  CRendererInputPin *v2; // esi@1
  HRESULT result; // eax@1

  v2 = this;
  result = CBasePin::SetMediaType((CBasePin *)&this->vfptr, pmt);
  if ( result >= 0 )
    result = ((int (__stdcall *)(CMediaType *))v2->m_pRenderer->vfptr[12].NonDelegatingQueryInterface)(pmt);
  return result;
}

//----- (006BDAD0) --------------------------------------------------------  // acclient.c:725664
HRESULT __thiscall CBaseVideoRenderer::ResetStreamingTimes(CBaseVideoRenderer *this)
{
  CBaseVideoRenderer *v1; // esi@1
  HRESULT result; // eax@1

  v1 = this;
  LODWORD(this->m_trLastDraw) = -1000;
  HIDWORD(this->m_trLastDraw) = -1;
  this->m_tStreamingStart = timeGetTime();
  result = 0;
  v1->m_trRenderAvg = 0;
  v1->m_trFrameAvg = -1;
  v1->m_trDuration = 0;
  v1->m_trRenderLast = 0;
  v1->m_trWaitAvg = 0;
  v1->m_tRenderStart = 0;
  v1->m_cFramesDrawn = 0;
  v1->m_cFramesDropped = 0;
  LODWORD(v1->m_iTotAcc) = 0;
  HIDWORD(v1->m_iTotAcc) = 0;
  LODWORD(v1->m_iSumSqAcc) = 0;
  HIDWORD(v1->m_iSumSqAcc) = 0;
  LODWORD(v1->m_iSumSqFrameTime) = 0;
  HIDWORD(v1->m_iSumSqFrameTime) = 0;
  v1->m_trFrame = 0;
  v1->m_trLate = 0;
  LODWORD(v1->m_iSumFrameTime) = 0;
  HIDWORD(v1->m_iSumFrameTime) = 0;
  v1->m_nNormal = 0;
  v1->m_trEarliness = 0;
  v1->m_trTarget = -300000;
  v1->m_trThrottle = 0;
  LODWORD(v1->m_trRememberStampForPerf) = 0;
  HIDWORD(v1->m_trRememberStampForPerf) = 0;
  return result;
}

//----- (006BDB90) --------------------------------------------------------  // acclient.c:725702
HRESULT __thiscall CBaseVideoRenderer::OnStartStreaming(CBaseVideoRenderer *this)
{
  ((void (*)(void))this->vfptr[15].NonDelegatingRelease)();
  return 0;
}

//----- (006BDBA0) --------------------------------------------------------  // acclient.c:725709
HRESULT __thiscall CBaseVideoRenderer::OnStopStreaming(CBaseVideoRenderer *this)
{
  this->m_tStreamingStart = timeGetTime() - this->m_tStreamingStart;
  return 0;
}

//----- (006BDBC0) --------------------------------------------------------  // acclient.c:725716
void __thiscall CBaseVideoRenderer::RecordFrameLateness(CBaseVideoRenderer *this, int trLate, int trFrame)
{
  int v3; // esi@1
  __int16 v4; // dx@5
  int v5; // edi@6
  __int64 v6; // kr08_8@7
  __int64 v7; // kr10_8@7
  int v8; // esi@9
  int v9; // ebx@12
  __int64 v10; // rax@12
  __int64 v11; // kr18_8@12

  v3 = trLate / 10000;
  if ( trLate / 10000 > 1000 || v3 < -1000 )
  {
    if ( this->m_cFramesDrawn > 1 )
    {
      v4 = v3 < 0;
      LOBYTE(v4) = v3 <= 0;
      v3 = ((v4 - 1) & 0x7D0) - 1000;
    }
    else
    {
      v3 = 0;
    }
  }
  v5 = this->m_cFramesDrawn;
  if ( v5 > 1 )
  {
    v6 = v3 + this->m_iTotAcc;
    HIDWORD(this->m_iTotAcc) = HIDWORD(v6);
    v7 = v3 * v3 + this->m_iSumSqAcc;
    LODWORD(this->m_iTotAcc) = v6;
    this->m_iSumSqAcc = v7;
  }
  if ( v5 > 2 )
  {
    v8 = trFrame / 10000;
    if ( trFrame / 10000 > 1000 || v8 < 0 )
      v8 = 1000;
    v9 = LODWORD(this->m_iSumSqFrameTime);
    v10 = v8 * v8;
    LODWORD(this->m_iSumSqFrameTime) = v10 + v9;
    v11 = v8 + this->m_iSumFrameTime;
    HIDWORD(this->m_iSumSqFrameTime) += HIDWORD(v10) + __CFADD__((_DWORD)v10, v9);
    this->m_iSumFrameTime = v11;
  }
  this->m_cFramesDrawn = v5 + 1;
}

//----- (006BDCD0) --------------------------------------------------------  // acclient.c:725767
void __thiscall CBaseVideoRenderer::OnDirectRender(CBaseVideoRenderer *this, IMediaSample *pMediaSample)
{
  CBaseVideoRenderer *v2; // esi@1
  INonDelegatingUnknownVtbl *v3; // eax@1
  int v4; // ST04_4@1
  int v5; // ST00_4@1
  signed int v6; // esi@1

  v2 = this;
  v3 = this->vfptr;
  v4 = this->m_trFrame;
  v5 = this->m_trLate;
  this->m_trRenderAvg = 0;
  this->m_trRenderLast = (int)((char *)&loc_4C4B3E + 2);
  ((void (__stdcall *)(int, int))v3[15].NonDelegatingQueryInterface)(v5, v4);
  v6 = v2->m_trThrottle;
  if ( v6 <= 0 )
    Sleep(0);
  else
    Sleep(v6 / 10000);
}

//----- (006BDD40) --------------------------------------------------------  // acclient.c:725790
void __thiscall CBaseVideoRenderer::OnRenderStart(CBaseVideoRenderer *this, IMediaSample *pMediaSample)
{
  CBaseVideoRenderer *v2; // esi@1

  v2 = this;
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[15].NonDelegatingQueryInterface)(this->m_trLate, this->m_trFrame);
  v2->m_tRenderStart = timeGetTime();
}

//----- (006BDD70) --------------------------------------------------------  // acclient.c:725800
void __thiscall CBaseVideoRenderer::OnRenderEnd(CBaseVideoRenderer *this, IMediaSample *pMediaSample)
{
  CBaseVideoRenderer *v2; // esi@1
  DWORD v3; // ecx@1
  int v4; // eax@1
  int v5; // ecx@1
  signed int v6; // esi@4

  v2 = this;
  v3 = timeGetTime() - this->m_tRenderStart;
  v4 = v2->m_trRenderAvg;
  v5 = 10000 * v3;
  if ( v5 < 2 * v4 || v5 < 2 * v2->m_trRenderLast )
    v2->m_trRenderAvg = (v5 + 2 * v4 + v4) / 4;
  v2->m_trRenderLast = v5;
  v6 = v2->m_trThrottle;
  if ( v6 <= 0 )
    Sleep(0);
  else
    Sleep(v6 / 10000);
}

//----- (006BDDF0) --------------------------------------------------------  // acclient.c:725823
HRESULT __stdcall CBaseVideoRenderer::SetSink(CBaseVideoRenderer *this, IQualityControl *piqc)
{
  LODWORD(this[-1].m_iTotAcc) = piqc;
  return 0;
}

//----- (006BDE00) --------------------------------------------------------  // acclient.c:725830
HRESULT __stdcall CBaseVideoRenderer::Notify(CBaseVideoRenderer *this, IBaseFilter *pSelf, tagQuality q)
{
  HRESULT result; // eax@2

  if ( q.Proportion < 1000 )
  {
    this->vfptr = (IUnknownVtbl *)(388880000 / (q.Proportion + 167) - 330000);
    result = 0;
  }
  else
  {
    this->vfptr = 0;
    result = 0;
  }
  return result;
}

//----- (006BDE40) --------------------------------------------------------  // acclient.c:725848
HRESULT __thiscall CBaseVideoRenderer::SendQuality(CBaseVideoRenderer *this, __int64 trLate, __int64 trRealStream)
{
  CBaseVideoRenderer *v3; // ebx@1
  int v4; // eax@1
  int v5; // ecx@10
  __int64 v6; // rax@16
  unsigned __int8 v7; // cf@16
  CRendererInputPin *v8; // eax@17
  IQualityControl *v9; // eax@19
  IUnknownVtbl *v10; // edx@20
  HRESULT result; // eax@20
  tagQuality v12; // [sp-18h] [bp-3Ch]@20
  int v13; // [sp-14h] [bp-38h]@20
  __int64 v14; // [sp-10h] [bp-34h]@8
  signed __int64 v15; // [sp-8h] [bp-2Ch]@8
  tagQuality q; // [sp+Ch] [bp-18h]@1

  v3 = this;
  q.TimeStamp = trRealStream;
  v4 = this->m_trFrameAvg;
  if ( v4 >= 0 )
    q.Type = v4 <= 2 * this->m_trRenderAvg;
  else
    q.Type = 0;
  q.Proportion = 1000;
  if ( v4 >= 0 )
  {
    if ( SHIDWORD(trLate) >= 0 && (SHIDWORD(trLate) > 0 || (_DWORD)trLate) )
    {
      v15 = 10000i64;
      v14 = trLate;
      q.Proportion = 1000 - (unsigned __int64)(trLate / 10000);
      if ( q.Proportion < 500 )
        q.Proportion = 500;
    }
    else
    {
      v5 = this->m_trWaitAvg;
      if ( v5 > 20000 && trLate < -20000 )
      {
        if ( v5 >= v4 || v4 + 20000 <= v5 || (q.Proportion = 1000 * (v4 / (v4 - v5 + 20000)), q.Proportion > 2000) )
          q.Proportion = 2000;
      }
    }
  }
  v6 = v3->m_trRenderAvg / 2;
  v7 = __CFADD__((_DWORD)trLate, (_DWORD)v6);
  LODWORD(q.Late) = trLate + v6;
  LODWORD(v6) = v3->m_pQSink;
  HIDWORD(q.Late) = HIDWORD(trLate) + v7 + HIDWORD(v6);
  if ( !(_DWORD)v6 )
  {
    v8 = v3->m_pInputPin;
    LODWORD(trRealStream) = 0;
    if ( v8->m_Connected->vfptr->QueryInterface(
           (IUnknown *)v8->m_Connected,
           &IID_IQualityControl,
           (void **)&trRealStream) >= 0 )
      v3->m_pQSink = (IQualityControl *)trRealStream;
  }
  v9 = v3->m_pQSink;
  if ( v9 )
  {
    v10 = v9->vfptr;
    qmemcpy(&v12, &q, sizeof(v12));
    result = ((int (__stdcall *)(IQualityControl *, int, tagQualityMessageType, int, _DWORD, _DWORD, _DWORD, _DWORD))v10[1].QueryInterface)(
               v9,
               &v3->vfptr,
               v12.Type,
               v13,
               v14,
               HIDWORD(v14),
               v15,
               HIDWORD(v15));
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006BDFB0) --------------------------------------------------------  // acclient.c:725931
HRESULT __thiscall CBaseVideoRenderer::ShouldDrawSampleNow(CBaseVideoRenderer *this, IMediaSample *pMediaSample, __int64 *ptrStart, __int64 *ptrEnd)
{
  __int64 *v4; // ebx@1
  __int64 *v5; // edi@1
  unsigned int v6; // eax@1
  CBaseVideoRenderer *v7; // esi@1
  unsigned int v8; // ecx@1
  IReferenceClock *v9; // eax@5
  int v10; // eax@5
  int v11; // edx@5
  unsigned int v12; // ebp@5
  unsigned int v13; // ecx@5
  unsigned int v14; // eax@5
  int v15; // ecx@12
  int v16; // eax@12
  signed int v17; // ebx@12
  int v18; // eax@13
  int v19; // eax@20
  signed int v20; // ebx@24
  int v21; // ecx@29
  int v22; // eax@31
  int v23; // ebx@31
  unsigned int v24; // eax@31
  unsigned int v25; // ecx@31
  signed int v26; // edx@31
  int v27; // ebx@34
  int v28; // ebp@35
  HRESULT result; // eax@42
  signed int v30; // ecx@45
  int v31; // ecx@51
  __int64 v32; // rax@51
  bool v33; // zf@51
  bool v34; // sf@51
  unsigned __int8 v35; // of@51
  int v36; // ecx@51
  int v37; // eax@54
  int v38; // eax@56
  int v39; // ebx@57
  signed __int64 v40; // kr18_8@57
  signed int v41; // eax@65
  unsigned int v42; // edi@65
  unsigned __int64 v43; // kr20_8@65
  int trWaitAvg; // [sp+1Ch] [bp-1Ch]@31
  int bJustDroppedFrame; // [sp+20h] [bp-18h]@22
  signed int v46; // [sp+24h] [bp-14h]@31
  __int64 trRealStream; // [sp+28h] [bp-10h]@5
  __int64 tr; // [sp+30h] [bp-8h]@31
  signed int pMediaSamplea; // [sp+3Ch] [bp+4h]@33
  int trFrame; // [sp+40h] [bp+8h]@12
  int trFramea; // [sp+40h] [bp+8h]@56
  HRESULT Result; // [sp+44h] [bp+Ch]@6

  v4 = ptrEnd;
  v5 = ptrStart;
  v6 = *((_DWORD *)ptrStart + 1);
  v7 = this;
  v8 = *(_DWORD *)ptrStart;
  if ( (v6 & 0x80000000) == 0 && ((signed int)v6 > 0 || v8 >= 0x13880) )
  {
    *ptrStart = __PAIR__(v6, v8) - 80000;
    *ptrEnd -= 80000i64;
  }
  LODWORD(v7->m_trRememberStampForPerf) = *(_DWORD *)ptrStart;
  v9 = v7->m_pClock;
  HIDWORD(v7->m_trRememberStampForPerf) = *((_DWORD *)ptrStart + 1);
  ((void (__stdcall *)(IReferenceClock *, __int64 *))v9->vfptr[1].QueryInterface)(v9, &trRealStream);
  v10 = LODWORD(v7->m_tStart.m_time);
  v12 = (unsigned __int64)(trRealStream - v7->m_tStart.m_time) >> 32;
  v11 = trRealStream - LODWORD(v7->m_tStart.m_time);
  v13 = trRealStream - v10 - *(_DWORD *)ptrStart;
  v14 = (__PAIR__(v12, (signed int)trRealStream - v10) - *ptrStart) >> 32;
  trRealStream -= v7->m_tStart.m_time;
  if ( (signed __int64)__PAIR__(v14, v13) >= -500000000 )
  {
    if ( (v14 & 0x80000000) != 0 || (signed int)v14 <= 0 && v13 <= 0x1DCD6500 )
      Result = v13;
    else
      Result = 500000000;
  }
  else
  {
    Result = -500000000;
  }
  v15 = ((int (__thiscall *)(CBaseVideoRenderer *, HRESULT, _DWORD, int, unsigned int))v7->vfptr[16].NonDelegatingQueryInterface)(
          v7,
          Result,
          (unsigned __int64)Result >> 32,
          v11,
          v12) == 0;
  v7->m_bSupplierHandlingQuality = v15;
  v16 = *(_DWORD *)v4;
  v17 = v7->m_trDuration;
  trFrame = v16 - *(_DWORD *)ptrStart;
  if ( trFrame > v17 + v17 / 32 )
  {
    v18 = trFrame;
  }
  else
  {
    v18 = trFrame;
    if ( trFrame >= v17 - v17 / 32 )
      goto LABEL_17;
  }
  v7->m_trFrameAvg = v18;
  v7->m_trDuration = v18;
LABEL_17:
  v19 = v15 && !((int (__stdcall *)(IMediaSample *))pMediaSample->vfptr[5].QueryInterface)(pMediaSample)
     || v7->m_nNormal == -1;
  bJustDroppedFrame = v19;
  if ( Result <= 0 )
  {
    v20 = v7->m_trEarliness;
    if ( Result >= v20 || v19 )
      v7->m_trEarliness = Result;
    else
      v7->m_trEarliness = v20 - v20 / 8;
  }
  else
  {
    v7->m_trEarliness = 0;
  }
  if ( Result >= 0 )
    v21 = 0;
  else
    v21 = -Result;
  v22 = 3 * v7->m_trWaitAvg;
  v46 = v22;
  v23 = (v21 + v22) / 4;
  v24 = (unsigned __int64)(trRealStream - v7->m_trLastDraw) >> 32;
  trWaitAvg = v23;
  v26 = trRealStream - LODWORD(v7->m_trLastDraw);
  LODWORD(tr) = trRealStream - LODWORD(v7->m_trLastDraw);
  v25 = tr;
  if ( (signed __int64)__PAIR__(v24, (unsigned int)tr) > 10000000 )
  {
    v26 = 10000000;
    tr = 10000000i64;
  }
  pMediaSamplea = v26;
  if ( 3 * v7->m_trRenderAvg <= v7->m_trFrameAvg )
  {
    v28 = Result;
  }
  else
  {
    v27 = 0;
    if ( v7->m_bSupplierHandlingQuality )
    {
      v28 = Result;
      LOBYTE(v27) = Result <= 4 * trFrame;
    }
    else
    {
      v28 = Result;
      LOBYTE(v27) = 2 * Result < trFrame;
    }
    if ( !v27 && v7->m_trWaitAvg <= 80000 && (signed int)v24 <= 0 && ((v24 & 0x80000000) != 0 || v25 <= 0x989680) )
    {
      v7->m_trWaitAvg = trWaitAvg;
      v7->m_nNormal = -1;
      return -2147467259;
    }
    v23 = trWaitAvg;
  }
  v30 = 0;
  if ( bJustDroppedFrame || v7->m_trFrameAvg > trFrame + trFrame / 16 && v28 > -10 * trFrame )
    v30 = 1;
  if ( v28 >= -9000000 && v30 )
  {
    v31 = tr;
    v7->m_trWaitAvg = v46 / 4;
    v32 = v31 + 2 * v7->m_trFrameAvg + v7->m_trFrameAvg;
    v7->m_trFrameAvg = ((BYTE4(v32) & 3) + (signed int)v32) >> 2;
    LODWORD(v7->m_trLastDraw) = trRealStream;
    v35 = __OFSUB__(v7->m_trEarliness, v28);
    v33 = v7->m_trEarliness == v28;
    v34 = v7->m_trEarliness - v28 < 0;
    v7->m_trFrame = v31;
    v36 = HIDWORD(trRealStream);
    v7->m_nNormal = 0;
    v7->m_trLate = v28;
    HIDWORD(v7->m_trLastDraw) = v36;
    if ( !((unsigned __int8)(v34 ^ v35) | v33) )
      v7->m_trEarliness = v28;
    result = 0;
  }
  else
  {
    ++v7->m_nNormal;
    v37 = v7->m_trEarliness;
    v7->m_trFrameAvg = trFrame;
    if ( v37 < -trFrame )
      v37 = -trFrame;
    *v5 += v37;
    v38 = -v28;
    v7->m_trWaitAvg = v23;
    trFramea = -v28 >= 0 && v28 != 0;
    if ( trFramea == 1 )
    {
      v39 = *(_DWORD *)v5;
      v40 = *v5 - v7->m_trLastDraw;
      if ( v40 >= -500000000 )
      {
        if ( v40 <= 500000000 )
          pMediaSamplea = v40;
        else
          pMediaSamplea = 500000000;
      }
      else
      {
        pMediaSamplea = -500000000;
      }
      HIDWORD(v7->m_trLastDraw) = *((_DWORD *)v5 + 1);
      v28 = Result;
      LODWORD(v7->m_trLastDraw) = v39;
    }
    else
    {
      v7->m_trLastDraw = trRealStream;
    }
    if ( v38 <= 0 )
    {
      v41 = v28;
    }
    else
    {
      v43 = *v5 - v7->m_trRememberStampForPerf;
      v42 = v43 >> 32;
      v41 = v43;
      if ( (signed __int64)__PAIR__(v42, (unsigned int)v43) >= -500000000 )
      {
        if ( (v42 & 0x80000000) == 0 && ((signed int)v42 > 0 || (unsigned int)v43 > 0x1DCD6500) )
          v41 = 500000000;
      }
      else
      {
        v41 = -500000000;
      }
    }
    v7->m_trLate = v41;
    result = trFramea;
    v7->m_trFrame = pMediaSamplea;
  }
  return result;
}

//----- (006BE410) --------------------------------------------------------  // acclient.c:726178
int __thiscall CBaseVideoRenderer::ScheduleSample(CBaseVideoRenderer *this, IMediaSample *pMediaSample)
{
  CBaseVideoRenderer *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( CBaseRenderer::ScheduleSample((CBaseRenderer *)&this->vfptr, pMediaSample) )
  {
    result = 1;
  }
  else
  {
    ++v2->m_cFramesDropped;
    result = 0;
  }
  return result;
}

//----- (006BE440) --------------------------------------------------------  // acclient.c:726197
HRESULT __stdcall CBaseVideoRenderer::get_FramesDroppedInRenderer(CBaseVideoRenderer *this, int *pcFramesDropped)
{
  HRESULT result; // eax@2

  if ( pcFramesDropped )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    *pcFramesDropped = (int)this->m_pGraph;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BE480) --------------------------------------------------------  // acclient.c:726216
HRESULT __stdcall CBaseVideoRenderer::get_FramesDrawn(CBaseVideoRenderer *this, int *pcFramesDrawn)
{
  HRESULT result; // eax@2

  if ( pcFramesDrawn )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    *pcFramesDrawn = (int)this->m_pSink;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BE4C0) --------------------------------------------------------  // acclient.c:726235
HRESULT __stdcall CBaseVideoRenderer::get_AvgFrameRate(CBaseVideoRenderer *this, int *piAvgFrameRate)
{
  HRESULT result; // eax@2
  _RTL_CRITICAL_SECTION *v3; // ebx@3
  int v4; // eax@4

  if ( piAvgFrameRate )
  {
    v3 = (_RTL_CRITICAL_SECTION *)&this[-1].m_tRenderStart;
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    if ( this[-1].vfptr )
      v4 = timeGetTime() - (unsigned int)this->m_pInputPin;
    else
      v4 = (int)this->m_pInputPin;
    if ( v4 > 0 )
    {
      *piAvgFrameRate = MulDiv(100000, (int)this->m_pSink, v4);
      LeaveCriticalSection(v3);
      result = 0;
    }
    else
    {
      *piAvgFrameRate = 0;
      LeaveCriticalSection(v3);
      result = 0;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BE540) --------------------------------------------------------  // acclient.c:726270
HRESULT __stdcall CBaseVideoRenderer::get_AvgSyncOffset(CBaseVideoRenderer *this, int *piAvg)
{
  HRESULT result; // eax@2
  _RTL_CRITICAL_SECTION *v3; // ebx@3
  IMediaEventSink *v4; // eax@5

  if ( piAvg )
  {
    v3 = (_RTL_CRITICAL_SECTION *)&this[-1].m_tRenderStart;
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_tRenderStart);
    if ( this[-1].m_RendererLock.m_CritSec.LockCount && (v4 = this->m_pSink, (signed int)v4 > 1) )
    {
      *piAvg = *(_QWORD *)&this->m_PinVersion / (signed __int64)(signed int)((char *)&v4[-1].vfptr + 3);
      LeaveCriticalSection(v3);
      result = 0;
    }
    else
    {
      *piAvg = 0;
      LeaveCriticalSection(v3);
      result = 0;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BE5B0) --------------------------------------------------------  // acclient.c:726301
int __cdecl isqrt(int x)
{
  signed int v1; // ecx@1
  int result; // eax@2

  v1 = 1;
  if ( x <= 0x40000000 )
  {
    if ( x > 1 )
    {
      do
        v1 *= 2;
      while ( v1 * v1 < x );
    }
    if ( x )
    {
      result = (x + v1 * v1) / (2 * v1);
      if ( result >= 0 )
      {
        result = (x + result * result) / (2 * result);
        if ( result >= 0 )
          result = (x + result * result) / (2 * result);
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0x8000;
  }
  return result;
}

//----- (006BE620) --------------------------------------------------------  // acclient.c:726338
HRESULT __thiscall CBaseVideoRenderer::GetStdDev(CBaseVideoRenderer *this, int nSamples, int *piResult, __int64 llSumSq, __int64 iTot)
{
  CBaseVideoRenderer *v5; // esi@1
  HRESULT result; // eax@2
  _RTL_CRITICAL_SECTION *v7; // ebx@3
  __int64 v8; // rax@6

  v5 = this;
  if ( piResult )
  {
    v7 = &this->m_InterfaceLock.m_CritSec;
    EnterCriticalSection(&this->m_InterfaceLock.m_CritSec);
    if ( v5->m_pClock && nSamples > 1 )
    {
      LODWORD(v8) = llMulDiv(iTot, iTot, nSamples, 0i64);
      *piResult = isqrt((llSumSq - v8) / (nSamples - 1));
      LeaveCriticalSection(v7);
      result = 0;
    }
    else
    {
      *piResult = 0;
      LeaveCriticalSection(v7);
      result = 0;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BE6C0) --------------------------------------------------------  // acclient.c:726372
HRESULT __stdcall CBaseVideoRenderer::get_DevSyncOffset(CBaseVideoRenderer *this, int *piDev)
{
  return CBaseVideoRenderer::GetStdDev(
           (CBaseVideoRenderer *)((char *)this - 224),
           (int)((char *)&this->m_pSink[-1].vfptr + 3),
           piDev,
           *(_QWORD *)&this->m_pPosition,
           *(_QWORD *)&this->m_PinVersion);
}

//----- (006BE6F0) --------------------------------------------------------  // acclient.c:726383
HRESULT __stdcall CBaseVideoRenderer::get_Jitter(CBaseVideoRenderer *this, int *piJitter)
{
  return CBaseVideoRenderer::GetStdDev(
           (CBaseVideoRenderer *)((char *)this - 224),
           (int)((char *)&this->m_pSink[-1].vfptr + 2),
           piJitter,
           *(_QWORD *)&this->m_bAbort,
           *(_QWORD *)&this->m_dwAdvise);
}

//----- (006BE720) --------------------------------------------------------  // acclient.c:726394
HRESULT __stdcall CBaseVideoRenderer::NonDelegatingQueryInterface(CBaseVideoRenderer *this, _GUID *riid, void **ppv)
{
  if ( !memcmp(riid, &IID_IQualProp, 0x10u) )
  {
    if ( this )
      return GetInterface((IUnknown *)&this->vfptr, ppv);
    return GetInterface(0, ppv);
  }
  if ( !memcmp(riid, &IID_IQualityControl, 0x10u) )
  {
    if ( this )
      return GetInterface((IUnknown *)&this->vfptr, ppv);
    return GetInterface(0, ppv);
  }
  return CBaseRenderer::NonDelegatingQueryInterface((CBaseRenderer *)&this->vfptr, riid, ppv);
}

//----- (006BE7B0) --------------------------------------------------------  // acclient.c:726412
HRESULT __stdcall CBaseVideoRenderer::JoinFilterGraph(CBaseVideoRenderer *this, IFilterGraph *pGraph, const unsigned __int16 *pName)
{
  IFilterGraph *v3; // edi@1

  v3 = pGraph;
  if ( !pGraph && *(_DWORD *)&this->m_clsid.Data4[4] )
  {
    this->vfptr->NonDelegatingQueryInterface((INonDelegatingUnknown *)this, &IID_IBaseFilter, (void **)&pGraph);
    CBaseFilter::NotifyEvent((CBaseFilter *)&this[-1].m_trFrame, 21, (int)pGraph, 0);
    pGraph->vfptr->Release((IUnknown *)pGraph);
  }
  return CBaseFilter::JoinFilterGraph((CBaseFilter *)&this->vfptr, v3, pName);
}

//----- (006BE800) --------------------------------------------------------  // acclient.c:726427
HRESULT __stdcall CBaseInputPin::QueryInterface(CBaseInputPin *this, _GUID *a2, void **a3)
{
  return CBaseVideoRenderer::QueryInterface((CBaseInputPin *)((char *)this - 140), a2, a3);
}

//----- (006BE810) --------------------------------------------------------  // acclient.c:726433
int __stdcall CBaseInputPin::AddRef(int a1)
{
  return CBaseVideoRenderer::AddRef((CBaseInputPin *)(a1 - 140));
}

//----- (006BE820) --------------------------------------------------------  // acclient.c:726439
int __stdcall CBaseInputPin::Release(int a1)
{
  return CBaseFilter::Release((CBaseInputPin *)(a1 - 140));
}

//----- (006BE830) --------------------------------------------------------  // acclient.c:726445
void __thiscall CBaseRenderer::~CBaseRenderer(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1
  int v3; // eax@1
  INonDelegatingUnknownVtbl *v4; // eax@2
  IMediaSample *v5; // eax@3
  CRendererPosPassThru *v6; // eax@5
  CRendererInputPin *v7; // ecx@7

  v1 = this;
  v2 = &this->m_RendererLock.m_CritSec;
  this->vfptr = (INonDelegatingUnknownVtbl *)&CBaseRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  EnterCriticalSection(&this->m_RendererLock.m_CritSec);
  v3 = v1->m_bStreaming;
  v1->m_bEOSDelivered = 0;
  if ( v3 == 1 )
  {
    v4 = v1->vfptr;
    v1->m_bStreaming = 0;
    ((void (__thiscall *)(CBaseRenderer *))v4[5].NonDelegatingRelease)(v1);
    timeEndPeriod(1u);
  }
  LeaveCriticalSection(v2);
  EnterCriticalSection(v2);
  v5 = v1->m_pMediaSample;
  if ( v5 )
  {
    v5->vfptr->Release((IUnknown *)v1->m_pMediaSample);
    v1->m_pMediaSample = 0;
  }
  LeaveCriticalSection(v2);
  v6 = v1->m_pPosition;
  if ( v6 )
  {
    ((void (__thiscall *)(int, signed int))v6->vfptr[1].NonDelegatingQueryInterface)(&v6->vfptr, 1);
    v1->m_pPosition = 0;
  }
  v7 = v1->m_pInputPin;
  if ( v7 )
  {
    ((void (__stdcall *)(signed int))v7->vfptr[1].NonDelegatingQueryInterface)(1);
    v1->m_pInputPin = 0;
  }
  DeleteCriticalSection(&v1->m_ObjectCreationLock.m_CritSec);
  DeleteCriticalSection(v2);
  DeleteCriticalSection(&v1->m_InterfaceLock.m_CritSec);
  CAMEvent::~CAMEvent(&v1->m_evComplete);
  CAMEvent::~CAMEvent(&v1->m_ThreadSignal);
  CAMEvent::~CAMEvent(&v1->m_RenderEvent);
  CBaseFilter::~CBaseFilter((CBaseFilter *)&v1->vfptr);
}
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806CC0: using guessed type __int32 (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806D00: using guessed type __int32 (__stdcall *CBaseRenderer::vftable)(CBaseRenderer *this, _GUID *riid, void **ppv);

//----- (006BE900) --------------------------------------------------------  // acclient.c:726504
HRESULT __thiscall CBaseRenderer::WaitForRenderTime(CBaseRenderer *this)
{
  CBaseRenderer *v1; // ebx@1
  void *v2; // eax@1
  INonDelegatingUnknownVtbl *v3; // edx@1
  DWORD v4; // esi@2
  HRESULT result; // eax@4
  void *WaitObjects[2]; // [sp+8h] [bp-8h]@1

  v1 = this;
  v2 = this->m_ThreadSignal.m_hEvent;
  v3 = this->vfptr;
  WaitObjects[1] = this->m_RenderEvent.m_hEvent;
  WaitObjects[0] = v2;
  ((void (*)(void))v3[6].NonDelegatingQueryInterface)();
  do
    v4 = WaitForMultipleObjects(2u, WaitObjects, 0, 0x2710u);
  while ( v4 == 258 );
  ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[6].NonDelegatingAddRef)(v1);
  if ( v4 )
  {
    v1->m_dwAdvise = 0;
    result = 0;
  }
  else
  {
    result = -2147220957;
  }
  return result;
}

//----- (006BE970) --------------------------------------------------------  // acclient.c:726536
HRESULT __stdcall CBaseRenderer::Stop(CBaseRenderer *this)
{
  _RTL_CRITICAL_SECTION *v1; // ebp@1
  IMediaSample *v3; // ecx@5
  IUnknownVtbl *v4; // eax@5

  v1 = (_RTL_CRITICAL_SECTION *)&this->m_bEOS;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->m_bEOS);
  if ( !this->m_cRef )
    goto LABEL_4;
  if ( !this->m_pMediaSample[6].vfptr )
  {
    this->m_cRef = 0;
LABEL_4:
    LeaveCriticalSection(v1);
    return 0;
  }
  CBaseFilter::Stop((CBaseFilter *)&this->vfptr);
  v3 = this->m_pMediaSample;
  v4 = v3[39].vfptr;
  if ( v4 )
    (*((void (__stdcall **)(IUnknownVtbl *))v4->QueryInterface + 6))(v3[39].vfptr);
  EnterCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&this->m_InterfaceLock.m_CritSec + 12));
  this->m_RendererLock.m_CritSec.LockSemaphore = (void *)1;
  LeaveCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&this->m_InterfaceLock.m_CritSec + 12));
  (*(void (__thiscall **)(void **))((void (__thiscall **)(_DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                  + 32))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  (*(void (__thiscall **)(void **, _DWORD))((void (__thiscall **)(_DWORD, _DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                          + 10))(
    &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
    0);
  (*(void (__thiscall **)(void **))((void (__thiscall **)(_DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                  + 25))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  (*(void (__thiscall **)(void **))((void (__thiscall **)(_DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                  + 27))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  SetEvent(this->m_pPosition);
  CBaseRenderer::WaitForReceiveToComplete((CBaseRenderer *)((char *)this - 12));
  this->m_RenderEvent.m_hEvent = 0;
  LeaveCriticalSection(v1);
  return 0;
}

//----- (006BEA30) --------------------------------------------------------  // acclient.c:726579
HRESULT __userpurge CBaseRenderer::Pause@<eax>(int a1@<ebx>, CBaseRenderer *this, int a3)
{
  _RTL_CRITICAL_SECTION *v3; // ebp@1
  int v4; // esi@2
  void *v6; // edx@4
  int v7; // esi@4
  char *v8; // esi@7
  IMediaSample *v9; // ecx@9
  IUnknownVtbl *v10; // eax@9
  int v11; // eax@12
  int v12; // esi@13

  v3 = (_RTL_CRITICAL_SECTION *)&this->m_bEOS;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->m_bEOS);
  if ( this->m_cRef == 1 )
  {
    v4 = (*(int (__thiscall **)(void **, signed int))((int (__thiscall **)(_DWORD, _DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                                    + 12))(
           &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
           1);
    LeaveCriticalSection(v3);
    return v4;
  }
  if ( !this->m_pMediaSample[6].vfptr )
  {
    v6 = this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore;
    this->m_cRef = 1;
    v7 = (*((int (__thiscall **)(void **, signed int))v6 + 12))(
           &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
           1);
LABEL_5:
    LeaveCriticalSection(v3);
    return v7;
  }
  v7 = CBaseFilter::Pause((CBaseFilter *)&this->vfptr);
  if ( v7 < 0 )
    goto LABEL_5;
  v8 = (char *)&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore;
  EnterCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&this->m_InterfaceLock.m_CritSec + 12));
  this->m_RendererLock.m_CritSec.LockSemaphore = (void *)1;
  LeaveCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&this->m_InterfaceLock.m_CritSec + 12));
  (*(void (__thiscall **)(void **, int))((void (__thiscall **)(_DWORD, _DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                       + 32))(
    &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
    a1);
  (*(void (__thiscall **)(void **, signed int))((void (__thiscall **)(_DWORD, _DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                              + 10))(
    &this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
    1);
  (*(void (__thiscall **)(void **))((void (__thiscall **)(_DWORD))this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore
                                  + 27))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  if ( this->m_bInReceive )
  {
    timeKillEvent(*((_DWORD *)v8 + 48));
    *((_DWORD *)v8 + 48) = 0;
  }
  v9 = this->m_pMediaSample;
  v10 = v9[39].vfptr;
  if ( v10 )
    (*((void (__stdcall **)(IUnknownVtbl *))v10->QueryInterface + 5))(v9[39].vfptr);
  if ( !a3 )
  {
    v11 = *(_DWORD *)v8;
    this->m_RenderEvent.m_hEvent = 0;
    (*(void (__thiscall **)(void **))(v11 + 112))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  }
  v12 = (*(int (__thiscall **)(void **))(*(_DWORD *)v8 + 48))(&this[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
  LeaveCriticalSection(v3);
  return v12;
}
// 6BEA30: could not find valid save-restore pair for ebx

//----- (006BEB40) --------------------------------------------------------  // acclient.c:726652
HRESULT __stdcall CBaseRenderer::Run(CBaseRenderer *this, __int64 StartTime)
{
  CBaseRenderer *v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // ebp@1
  HRESULT result; // eax@4
  HRESULT v5; // edi@5
  int v6; // edi@7
  IUnknownVtbl *v7; // eax@7
  int v8; // edx@10
  int v9; // esi@11
  CBaseRenderer *const thisa; // [sp+Ch] [bp+4h]@1

  v2 = this;
  v3 = (_RTL_CRITICAL_SECTION *)&this->m_bEOS;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->m_bEOS);
  thisa = (CBaseRenderer *const )this->m_cRef;
  if ( thisa == (CBaseRenderer *const )2 )
    goto LABEL_4;
  if ( !v2->m_pMediaSample[6].vfptr )
  {
    CBaseFilter::NotifyEvent(
      (CBaseFilter *)&v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
      1,
      0,
      v2 != (CBaseRenderer *)12 ? (unsigned int)v2 : 0);
    v2->m_cRef = 2;
LABEL_4:
    LeaveCriticalSection(v3);
    return 0;
  }
  SetEvent(v2->m_pPosition);
  v5 = CBaseFilter::Run((CBaseFilter *)&v2->vfptr, StartTime);
  if ( v5 >= 0 )
  {
    v6 = (int)&v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore;
    (*((void (__thiscall **)(int, signed int))v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore + 10))(
      &v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore,
      1);
    EnterCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&v2->m_InterfaceLock.m_CritSec + 12));
    v2->m_RendererLock.m_CritSec.LockSemaphore = 0;
    LeaveCriticalSection((_RTL_CRITICAL_SECTION *)((char *)&v2->m_InterfaceLock.m_CritSec + 12));
    v7 = v2->m_pMediaSample[39].vfptr;
    if ( v7 )
      (*((void (__stdcall **)(IUnknownVtbl *))v7->QueryInterface + 5))(v2->m_pMediaSample[39].vfptr);
    if ( !thisa )
    {
      v8 = *(_DWORD *)v6;
      v2->m_RenderEvent.m_hEvent = 0;
      (*(void (__thiscall **)(int))(v8 + 112))(&v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
    }
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 124))(&v2[-1].m_ObjectCreationLock.m_CritSec.LockSemaphore);
    LeaveCriticalSection(v3);
    result = v9;
  }
  else
  {
    LeaveCriticalSection(v3);
    result = v5;
  }
  return result;
}

//----- (006BEC30) --------------------------------------------------------  // acclient.c:726715
CRendererInputPin *__thiscall CBaseRenderer::GetPin(CBaseRenderer *this, int n)
{
  CBaseRenderer *v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // edi@1
  CRendererInputPin *v4; // eax@3
  CRendererInputPin *v5; // eax@4
  CRendererInputPin *v7; // esi@10

  v2 = this;
  v3 = &this->m_ObjectCreationLock.m_CritSec;
  EnterCriticalSection(&this->m_ObjectCreationLock.m_CritSec);
  if ( n )
    goto LABEL_9;
  if ( !v2->m_pInputPin )
  {
    n = 0;
    v4 = (CRendererInputPin *)operator new(0xE0u);
    if ( v4 )
      CRendererInputPin::CRendererInputPin(v4, v2, &n, L"In");
    else
      v5 = 0;
    v2->m_pInputPin = v5;
    if ( !v5 )
      goto LABEL_9;
    if ( n < 0 )
    {
      ((void (__thiscall *)(CRendererInputPin *, signed int))v5->vfptr[1].NonDelegatingQueryInterface)(v5, 1);
      v2->m_pInputPin = 0;
LABEL_9:
      LeaveCriticalSection(v3);
      return 0;
    }
  }
  v7 = v2->m_pInputPin;
  LeaveCriticalSection(v3);
  return v7;
}

//----- (006BECC0) --------------------------------------------------------  // acclient.c:726754
HRESULT __thiscall CBaseRenderer::CompleteConnect(CBaseRenderer *this, IPin *pReceivePin)
{
  CBaseRenderer *v2; // esi@1
  bool v3; // zf@1
  HRESULT result; // eax@2

  v2 = this;
  v3 = this->m_State == 2;
  this->m_bAbort = 0;
  if ( v3 )
  {
    result = ((int (*)(void))this->vfptr[10].NonDelegatingAddRef)();
    if ( result >= 0 )
    {
      EnterCriticalSection(&v2->m_RendererLock.m_CritSec);
      v2->m_bRepaintStatus = 0;
      LeaveCriticalSection(&v2->m_RendererLock.m_CritSec);
      result = 0;
    }
  }
  else
  {
    EnterCriticalSection(&this->m_RendererLock.m_CritSec);
    v2->m_bRepaintStatus = 1;
    LeaveCriticalSection(&v2->m_RendererLock.m_CritSec);
    result = 0;
  }
  return result;
}

//----- (006BED30) --------------------------------------------------------  // acclient.c:726785
HRESULT __thiscall CBaseRenderer::BreakConnect(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1
  IQualityControl *v2; // eax@1
  CRendererInputPin *v3; // eax@3
  HRESULT result; // eax@4
  bool v5; // zf@8

  v1 = this;
  v2 = this->m_pQSink;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v2);
    v1->m_pQSink = 0;
  }
  v3 = v1->m_pInputPin;
  if ( v3->m_Connected )
  {
    if ( v1->m_State == State_Stopped || v3->m_bCanReconnectWhenActive )
    {
      EnterCriticalSection(&v1->m_RendererLock.m_CritSec);
      v1->m_bRepaintStatus = 0;
      LeaveCriticalSection(&v1->m_RendererLock.m_CritSec);
      ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[8].NonDelegatingAddRef)(v1);
      ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[9].NonDelegatingAddRef)(v1);
      v5 = v1->m_State == 2;
      v1->m_bAbort = 0;
      if ( v5 )
        ((void (__thiscall *)(CBaseRenderer *))v1->vfptr[10].NonDelegatingRelease)(v1);
      result = 0;
    }
    else
    {
      result = -2147220956;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006BEDC0) --------------------------------------------------------  // acclient.c:726829
HRESULT __thiscall CBaseRenderer::PrepareReceive(CBaseRenderer *this, IMediaSample *pMediaSample)
{
  int v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // edi@1
  CBaseInputPin *v4; // ST00_4@1
  HRESULT result; // eax@2
  int v6; // ecx@3
  int v7; // eax@3
  int v8; // ebx@4
  _RTL_CRITICAL_SECTION *v9; // ebx@6
  CRendererPosPassThru *v10; // ecx@9
  int v11; // ecx@14
  IMediaSample2 *v12; // [sp+0h] [bp-Ch]@0
  int v13; // [sp+4h] [bp-8h]@0

  v2 = (int)this;
  v3 = &this->m_InterfaceLock.m_CritSec;
  EnterCriticalSection(&this->m_InterfaceLock.m_CritSec);
  v4 = (CBaseInputPin *)(*(_DWORD *)(v2 + 120) + 152);
  *(_DWORD *)(v2 + 180) = 1;
  if ( CBaseInputPin::Receive((int)pMediaSample, v2, v4, pMediaSample, v12, v13) )
  {
    *(_DWORD *)(v2 + 180) = 0;
    LeaveCriticalSection(v3);
    result = -2147467259;
  }
  else
  {
    v6 = *(_DWORD *)(v2 + 120);
    v7 = *(_DWORD *)(v6 + 204);
    if ( v7 && (v8 = (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 36))(v7), v8 < 0) )
    {
      *(_DWORD *)(v2 + 180) = 0;
      LeaveCriticalSection(v3);
      result = v8;
    }
    else
    {
      v9 = (_RTL_CRITICAL_SECTION *)(v2 + 148);
      EnterCriticalSection((LPCRITICAL_SECTION)(v2 + 148));
      if ( *(_DWORD *)(v2 + 108) || *(_DWORD *)(v2 + 112) || *(_DWORD *)(v2 + 96) )
      {
        SetEvent(*(HANDLE *)(v2 + 92));
        *(_DWORD *)(v2 + 180) = 0;
        LeaveCriticalSection(v9);
        LeaveCriticalSection(v3);
        result = -2147418113;
      }
      else
      {
        v10 = *(CRendererPosPassThru **)(v2 + 80);
        if ( v10 )
          CRendererPosPassThru::RegisterMediaTime(v10, pMediaSample);
        if ( *(_DWORD *)(v2 + 100) != 1
          || (*(int (__thiscall **)(int, IMediaSample *))(*(_DWORD *)v2 + 84))(v2, pMediaSample) )
        {
          v11 = *(_DWORD *)(v2 + 120);
          *(_DWORD *)(v2 + 184) = *(_DWORD *)(v11 + 192);
          *(_DWORD *)(v2 + 188) = *(_DWORD *)(v11 + 196);
          *(_DWORD *)(v2 + 108) = pMediaSample;
          pMediaSample->vfptr->AddRef((IUnknown *)pMediaSample);
          if ( !*(_DWORD *)(v2 + 100) )
            CBaseRenderer::SetRepaintStatus((CBaseRenderer *)v2, 1);
          LeaveCriticalSection(v9);
          LeaveCriticalSection(v3);
          result = 0;
        }
        else
        {
          *(_DWORD *)(v2 + 180) = 0;
          LeaveCriticalSection(v9);
          LeaveCriticalSection(v3);
          result = -2147220949;
        }
      }
    }
  }
  return result;
}

//----- (006BEF30) --------------------------------------------------------  // acclient.c:726910
void __stdcall EndOfStreamTimer(unsigned int uID, unsigned int uMsg, unsigned int dwUser, unsigned int dw1, unsigned int dw2)
{
  int v5; // eax@2

  EnterCriticalSection((LPCRITICAL_SECTION)(dwUser + 148));
  if ( *(_DWORD *)(dwUser + 192) )
  {
    v5 = *(_DWORD *)dwUser;
    *(_DWORD *)(dwUser + 192) = 0;
    (*(void (__thiscall **)(unsigned int))(v5 + 96))(dwUser);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(dwUser + 148));
}

//----- (006BEF70) --------------------------------------------------------  // acclient.c:726925
HRESULT __thiscall CBaseRenderer::SendEndOfStream(CBaseRenderer *this)
{
  unsigned int v1; // esi@1
  IReferenceClock *v2; // eax@4
  __int64 v3; // kr00_8@5
  __int64 v4; // rax@5
  unsigned int v5; // eax@6
  HRESULT result; // eax@7
  __int64 CurrentTime; // [sp+8h] [bp-8h]@5

  v1 = (unsigned int)this;
  if ( !this->m_bEOS
    || this->m_bEOSDelivered
    || this->m_EndOfStreamTimer
    || (v2 = this->m_pClock) != 0
    && (v3 = this->m_tStart.m_time + this->m_SignalTime,
        ((void (__stdcall *)(IReferenceClock *, __int64 *))v2->vfptr[1].QueryInterface)(v2, &CurrentTime),
        v4 = (v3 - CurrentTime) / 10000,
        (signed int)v4 >= 50)
    && (v5 = CompatibleTimeSetEvent(v4, 0xAu, EndOfStreamTimer, v1, 0), (*(_DWORD *)(v1 + 192) = v5) != 0) )
    result = 0;
  else
    result = CBaseRenderer::NotifyEndOfStream((CBaseRenderer *)v1);
  return result;
}

//----- (006BF010) --------------------------------------------------------  // acclient.c:726952
HRESULT __thiscall CBaseRenderer::ResetEndOfStream(CBaseRenderer *this)
{
  CBaseRenderer *v1; // esi@1

  v1 = this;
  if ( this->m_EndOfStreamTimer )
  {
    timeKillEvent(this->m_EndOfStreamTimer);
    v1->m_EndOfStreamTimer = 0;
  }
  EnterCriticalSection(&v1->m_RendererLock.m_CritSec);
  v1->m_bEOS = 0;
  v1->m_bEOSDelivered = 0;
  LODWORD(v1->m_SignalTime) = 0;
  HIDWORD(v1->m_SignalTime) = 0;
  LeaveCriticalSection(&v1->m_RendererLock.m_CritSec);
  return 0;
}

//----- (006BF060) --------------------------------------------------------  // acclient.c:726972
CRendererInputPin *__thiscall CRendererInputPin::scalar_deleting_destructor(CRendererInputPin *this, unsigned int a2)
{
  CRendererInputPin *v2; // esi@1

  v2 = this;
  CBaseInputPin::~CBaseInputPin((CBaseInputPin *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006BF080) --------------------------------------------------------  // acclient.c:726984
void __thiscall CBaseVideoRenderer::~CBaseVideoRenderer(CBaseVideoRenderer *this)
{
  this->vfptr = (INonDelegatingUnknownVtbl *)&CBaseVideoRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseVideoRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  CBaseRenderer::~CBaseRenderer((CBaseRenderer *)&this->vfptr);
}
// 806B74: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B9C: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806EA4: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806EC8: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);

//----- (006BF0B0) --------------------------------------------------------  // acclient.c:727000
CBaseRenderer *__thiscall CBaseRenderer::vector_deleting_destructor(CBaseRenderer *this, unsigned int a2)
{
  CBaseRenderer *v2; // esi@1

  v2 = this;
  CBaseRenderer::~CBaseRenderer(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006BF0D0) --------------------------------------------------------  // acclient.c:727012
void __thiscall CBaseVideoRenderer::CBaseVideoRenderer(CBaseVideoRenderer *this, _GUID *RenderClass, char *pName, IUnknown *pUnk, HRESULT *phr)
{
  CBaseVideoRenderer *v5; // esi@1

  v5 = this;
  CBaseRenderer::CBaseRenderer((CBaseRenderer *)&this->vfptr, RenderClass, pName, pUnk, phr);
  v5->vfptr = (INonDelegatingUnknownVtbl *)&CBaseVideoRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CBaseVideoRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  v5->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  v5->m_bSupplierHandlingQuality = 0;
  v5->m_cFramesDropped = 0;
  v5->m_cFramesDrawn = 0;
  CBaseVideoRenderer::ResetStreamingTimes(v5);
}
// 806B74: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B9C: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806EA4: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806EC8: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);

//----- (006BF140) --------------------------------------------------------  // acclient.c:727035
CBaseVideoRenderer *__thiscall CBaseVideoRenderer::vector_deleting_destructor(CBaseVideoRenderer *this, unsigned int a2)
{
  CBaseVideoRenderer *v2; // esi@1

  v2 = this;
  this->vfptr = (INonDelegatingUnknownVtbl *)&CBaseVideoRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseVideoRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  this->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  CBaseRenderer::~CBaseRenderer((CBaseRenderer *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 806B74: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B9C: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806EA4: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806EC8: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);

