/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : amfilter
   Object     : ENGINE\render_base\amfilter.obj
   Functions  : 68
   Addresses  : 006BF190 - 006C0F00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BF190) --------------------------------------------------------  // acclient.c:727057
HRESULT __stdcall CBaseFilter::NonDelegatingQueryInterface(CBaseFilter *this, _GUID *riid, void **ppv)
{
  if ( !memcmp(riid, &IID_IBaseFilter, 0x10u)
    || !memcmp(riid, &IID_IMediaFilter, 0x10u)
    || !memcmp(riid, &IID_IPersist, 0x10u) )
  {
    if ( this )
      return GetInterface((IUnknown *)&this->vfptr, ppv);
    return GetInterface(0, ppv);
  }
  if ( !memcmp(riid, &IID_IAMovieSetup, 0x10u) )
  {
    if ( this )
      return GetInterface((IUnknown *)&this->vfptr, ppv);
    return GetInterface(0, ppv);
  }
  return CUnknown::NonDelegatingQueryInterface((CUnknown *)&this->vfptr, riid, ppv);
}

//----- (006BF240) --------------------------------------------------------  // acclient.c:727077
void __thiscall CBaseFilter::~CBaseFilter(CBaseFilter *this)
{
  CBaseFilter *v1; // esi@1
  IReferenceClock *v2; // eax@1

  v1 = this;
  operator delete[](this->m_pName);
  v2 = v1->m_pClock;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_pClock);
    v1->m_pClock = 0;
  }
  CBaseObject::~CBaseObject();
}

//----- (006BF270) --------------------------------------------------------  // acclient.c:727094
HRESULT __stdcall CBaseFilter::GetClassID(CBaseFilter *this, _GUID *pClsID)
{
  HRESULT result; // eax@2

  if ( pClsID )
  {
    pClsID->Data1 = (unsigned int)(&this->m_pClock)[1];
    *(_QWORD *)&pClsID->Data2 = this->m_tStart.m_time;
    *(_DWORD *)&pClsID->Data4[4] = this->m_clsid.Data1;
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BF2B0) --------------------------------------------------------  // acclient.c:727113
HRESULT __stdcall CBaseFilter::SetSyncSource(CBaseFilter *this, IReferenceClock *pClock)
{
  _RTL_CRITICAL_SECTION *v2; // edi@1
  IUnknownVtbl *v3; // eax@3

  v2 = *(_RTL_CRITICAL_SECTION **)&this->m_clsid.Data2;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_clsid.Data2);
  if ( pClock )
    pClock->vfptr->AddRef((IUnknown *)pClock);
  v3 = this->vfptr;
  if ( v3 )
    (*((void (__stdcall **)(IUnknownVtbl *))v3->QueryInterface + 2))(this->vfptr);
  this->vfptr = (IUnknownVtbl *)pClock;
  LeaveCriticalSection(v2);
  return 0;
}

//----- (006BF2F0) --------------------------------------------------------  // acclient.c:727131
HRESULT __stdcall CBaseFilter::GetSyncSource(CBaseFilter *this, IReferenceClock **pClock)
{
  HRESULT result; // eax@2
  _RTL_CRITICAL_SECTION *v3; // edi@3
  IUnknownVtbl *v4; // eax@3

  if ( pClock )
  {
    v3 = *(_RTL_CRITICAL_SECTION **)&this->m_clsid.Data2;
    EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_clsid.Data2);
    v4 = this->vfptr;
    if ( v4 )
      (*((void (__stdcall **)(IUnknownVtbl *))v4->QueryInterface + 1))(this->vfptr);
    *pClock = (IReferenceClock *)this->vfptr;
    LeaveCriticalSection(v3);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BF340) --------------------------------------------------------  // acclient.c:727156
HRESULT __stdcall CBaseFilter::Stop(CBaseFilter *this)
{
  CBaseFilter *v1; // ebp@1
  int v2; // ebx@1
  signed int v3; // edi@2
  int v4; // eax@3
  int v5; // eax@4
  CAutoLock cObjectLock; // [sp+8h] [bp-4h]@1
  CBaseFilter *const thisa; // [sp+10h] [bp+4h]@2

  v1 = this;
  cObjectLock.m_pLock = *(CCritSec **)&this->m_clsid.Data2;
  EnterCriticalSection(&cObjectLock.m_pLock->m_CritSec);
  v2 = 0;
  if ( this->m_cRef )
  {
    v3 = 0;
    thisa = (CBaseFilter *const )((int (__thiscall *)(IMediaEventSink **))this[-1].m_pSink[6].vfptr)(&this[-1].m_pSink);
    if ( (signed int)thisa > 0 )
    {
      do
      {
        v4 = ((int (__thiscall *)(int, signed int))v1[-1].m_pSink[7].vfptr)(&v1[-1].m_pSink, v3);
        if ( *(_DWORD *)(v4 + 24) )
        {
          v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 24))(v4);
          if ( v5 < 0 && v2 >= 0 )
            v2 = v5;
        }
        ++v3;
      }
      while ( v3 < (signed int)thisa );
    }
  }
  v1->m_cRef = 0;
  LeaveCriticalSection(&cObjectLock.m_pLock->m_CritSec);
  return v2;
}

//----- (006BF3C0) --------------------------------------------------------  // acclient.c:727196
HRESULT __stdcall CBaseFilter::Pause(CBaseFilter *this)
{
  CBaseFilter *v1; // ebx@1
  int v2; // ebp@2
  int v3; // edi@2
  int v4; // eax@3
  int v5; // ebx@4
  CAutoLock cObjectLock; // [sp+10h] [bp-4h]@1

  v1 = this;
  cObjectLock.m_pLock = *(CCritSec **)&this->m_clsid.Data2;
  EnterCriticalSection(&cObjectLock.m_pLock->m_CritSec);
  if ( this->m_cRef
    || (v2 = ((int (__thiscall *)(IMediaEventSink **))this[-1].m_pSink[6].vfptr)(&this[-1].m_pSink), v3 = 0, v2 <= 0) )
  {
LABEL_7:
    v1->m_cRef = 1;
    LeaveCriticalSection(&cObjectLock.m_pLock->m_CritSec);
    return 0;
  }
  while ( 1 )
  {
    v4 = ((int (__thiscall *)(IMediaEventSink **, int))this[-1].m_pSink[7].vfptr)(&this[-1].m_pSink, v3);
    if ( *(_DWORD *)(v4 + 24) )
      break;
LABEL_6:
    ++v3;
    if ( v3 >= v2 )
      goto LABEL_7;
  }
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  if ( v5 >= 0 )
  {
    v1 = this;
    goto LABEL_6;
  }
  LeaveCriticalSection(&cObjectLock.m_pLock->m_CritSec);
  return v5;
}

//----- (006BF450) --------------------------------------------------------  // acclient.c:727237
HRESULT __stdcall CBaseFilter::Run(CBaseFilter *this, __int64 tStart)
{
  CBaseFilter *v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // edi@1
  int v4; // ebx@2
  int v6; // ebx@5
  int v7; // ebp@5
  int v8; // eax@6
  int v9; // ebx@7
  int cPins; // [sp+Ch] [bp-4h]@5
  _RTL_CRITICAL_SECTION *thisa; // [sp+14h] [bp+4h]@1

  v2 = this;
  thisa = *(_RTL_CRITICAL_SECTION **)&this->m_clsid.Data2;
  v3 = thisa;
  EnterCriticalSection(thisa);
  *(_QWORD *)&v2->m_State = tStart;
  if ( !v2->m_cRef )
  {
    v4 = v2->vfptr[1].NonDelegatingRelease((INonDelegatingUnknown *)v2);
    if ( v4 < 0 )
    {
      LeaveCriticalSection(thisa);
      return v4;
    }
  }
  if ( v2->m_cRef == 2 )
    goto LABEL_11;
  v6 = ((int (__thiscall *)(int))v2[-1].m_pSink[6].vfptr)(&v2[-1].m_pSink);
  v7 = 0;
  cPins = v6;
  if ( v6 <= 0 )
  {
LABEL_10:
    v3 = thisa;
LABEL_11:
    v2->m_cRef = 2;
    LeaveCriticalSection(v3);
    return 0;
  }
  while ( 1 )
  {
    v8 = ((int (__thiscall *)(int, int))v2[-1].m_pSink[7].vfptr)(&v2[-1].m_pSink, v7);
    if ( *(_DWORD *)(v8 + 24) )
      break;
LABEL_9:
    ++v7;
    if ( v7 >= v6 )
      goto LABEL_10;
  }
  v9 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v8 + 28))(v8, tStart, HIDWORD(tStart));
  if ( v9 >= 0 )
  {
    v6 = cPins;
    goto LABEL_9;
  }
  LeaveCriticalSection(thisa);
  return v9;
}

//----- (006BF520) --------------------------------------------------------  // acclient.c:727298
HRESULT __thiscall CBaseFilter::StreamTime(CBaseFilter *this, CRefTime *rtStream)
{
  CBaseFilter *v2; // edi@1
  IReferenceClock *v3; // eax@1
  HRESULT result; // eax@2
  unsigned int v5; // edx@4
  int v6; // ecx@4
  bool v7; // cf@4

  v2 = this;
  v3 = this->m_pClock;
  if ( v3 )
  {
    result = ((int (__stdcall *)(IReferenceClock *, CRefTime *))v3->vfptr[1].QueryInterface)(v3, rtStream);
    if ( result >= 0 )
    {
      v5 = LODWORD(v2->m_tStart.m_time);
      v6 = HIDWORD(rtStream->m_time);
      v7 = LODWORD(rtStream->m_time) < v5;
      LODWORD(rtStream->m_time) -= v5;
      HIDWORD(rtStream->m_time) = v6 - (v7 + HIDWORD(v2->m_tStart.m_time));
      result = 0;
    }
  }
  else
  {
    result = -2147220973;
  }
  return result;
}

//----- (006BF560) --------------------------------------------------------  // acclient.c:727330
HRESULT __stdcall CBaseFilter::QueryFilterInfo(CBaseFilter *this, _FilterInfo *pInfo)
{
  HRESULT result; // eax@2
  const unsigned __int16 *v3; // eax@3
  int v4; // eax@6

  if ( pInfo )
  {
    v3 = *(const unsigned __int16 **)&this->m_clsid.Data4[0];
    if ( v3 )
      lstrcpynWInternal(pInfo->achName, v3, 128);
    else
      pInfo->achName[0] = 0;
    pInfo->pGraph = *(IFilterGraph **)&this->m_clsid.Data4[4];
    v4 = *(_DWORD *)&this->m_clsid.Data4[4];
    if ( v4 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 4))(v4);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BF5B0) --------------------------------------------------------  // acclient.c:727357
HRESULT __stdcall CBaseFilter::JoinFilterGraph(CBaseFilter *this, IFilterGraph *pGraph, const unsigned __int16 *pName)
{
  CBaseFilter *v3; // ebx@1
  unsigned int v4; // edi@8
  void *v5; // eax@8
  _RTL_CRITICAL_SECTION *thisa; // [sp+Ch] [bp+4h]@1

  v3 = this;
  thisa = *(_RTL_CRITICAL_SECTION **)&this->m_clsid.Data2;
  EnterCriticalSection(thisa);
  *(_DWORD *)&v3->m_clsid.Data4[4] = pGraph;
  if ( pGraph )
  {
    if ( pGraph->vfptr->QueryInterface((IUnknown *)pGraph, &IID_IMediaEventSink, (void **)&v3->m_pLock) >= 0 )
      ((void (__stdcall *)(CCritSec *))v3->m_pLock->m_CritSec.DebugInfo->ProcessLocksList.Flink)(v3->m_pLock);
  }
  else
  {
    v3->m_pLock = 0;
  }
  if ( *(_DWORD *)&v3->m_clsid.Data4[0] )
  {
    operator delete[](*(void **)&v3->m_clsid.Data4[0]);
    *(_DWORD *)&v3->m_clsid.Data4[0] = 0;
  }
  if ( pName )
  {
    v4 = 2 * (lstrlenWInternal(pName) + 1);
    v5 = operator new[](v4);
    *(_DWORD *)&v3->m_clsid.Data4[0] = v5;
    if ( v5 )
      qmemcpy(v5, pName, v4);
  }
  LeaveCriticalSection(thisa);
  return 0;
}

//----- (006BF660) --------------------------------------------------------  // acclient.c:727395
HRESULT __thiscall CBaseFilter::NotifyEvent(CBaseFilter *this, int EventCode, int EventParam1, int EventParam2)
{
  IMediaEventSink *v4; // eax@1
  HRESULT result; // eax@3

  v4 = this->m_pSink;
  if ( v4 )
  {
    if ( EventCode == 1 )
      result = ((int (__stdcall *)(IMediaEventSink *, signed int, int, IUnknownVtbl **))v4->vfptr[1].QueryInterface)(
                 v4,
                 1,
                 EventParam1,
                 &this->vfptr);
    else
      result = ((int (__stdcall *)(IMediaEventSink *, int, int, int))v4->vfptr[1].QueryInterface)(
                 v4,
                 EventCode,
                 EventParam1,
                 EventParam2);
  }
  else
  {
    result = -2147467263;
  }
  return result;
}

//----- (006BF6B0) --------------------------------------------------------  // acclient.c:727424
HRESULT __stdcall CEnumPins::QueryInterface(CEnumPins *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@2

  if ( ppv )
  {
    if ( !memcmp(riid, &IID_IEnumPins, 0x10u) || !memcmp(riid, &_GUID_00000000_0000_0000_c000_000000000046, 0x10u) )
    {
      result = GetInterface((IUnknown *)&this->vfptr, ppv);
    }
    else
    {
      *ppv = 0;
      result = -2147467262;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BF710) --------------------------------------------------------  // acclient.c:727448
LONG __stdcall CEnumPins::AddRef(CEnumPins *this)
{
  return InterlockedIncrement(&this->m_cRef);
}

//----- (006BF730) --------------------------------------------------------  // acclient.c:727454
LONG __stdcall CEnumPins::Release(CEnumPins *this)
{
  LONG v1; // edi@1

  v1 = InterlockedDecrement(&this->m_cRef);
  if ( !v1 && this )
    ((void (__thiscall *)(_DWORD, _DWORD))this->vfptr[2].AddRef)(this, 1);
  return v1;
}

//----- (006BF760) --------------------------------------------------------  // acclient.c:727465
HRESULT __stdcall CEnumPins::Skip(CEnumPins *this, unsigned int cPins)
{
  HRESULT result; // eax@2
  int v3; // eax@3

  if ( ((int (*)(void))this->m_pFilter->vfptr[1].NonDelegatingRelease)() == this->m_Version )
  {
    v3 = this->m_Position;
    if ( cPins <= this->m_PinCount - v3 )
    {
      this->m_Position = cPins + v3;
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = -2147220989;
  }
  return result;
}

//----- (006BF7A0) --------------------------------------------------------  // acclient.c:727491
HRESULT __stdcall CEnumPins::Reset(CEnumPins *this)
{
  int v1; // eax@1
  CBaseFilter *v2; // ecx@1

  v1 = ((int (*)(void))this->m_pFilter->vfptr[1].NonDelegatingRelease)();
  v2 = this->m_pFilter;
  this->m_Version = v1;
  this->m_PinCount = ((int (*)(void))v2->vfptr[2].NonDelegatingQueryInterface)();
  this->m_Position = 0;
  CBaseList::RemoveAll((CBaseList *)&this->m_PinCache.m_pFirst);
  return 0;
}

//----- (006BF7D0) --------------------------------------------------------  // acclient.c:727506
HRESULT __stdcall CEnumMediaTypes::QueryInterface(CEnumMediaTypes *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@2

  if ( ppv )
  {
    if ( !memcmp(riid, &IID_IEnumMediaTypes, 0x10u) || !memcmp(riid, &_GUID_00000000_0000_0000_c000_000000000046, 0x10u) )
    {
      result = GetInterface((IUnknown *)&this->vfptr, ppv);
    }
    else
    {
      *ppv = 0;
      result = -2147467262;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BF850) --------------------------------------------------------  // acclient.c:727536
LONG __stdcall CEnumMediaTypes::Release(CEnumMediaTypes *this)
{
  LONG v1; // edi@1

  v1 = InterlockedDecrement(&this->m_cRef);
  if ( !v1 && this )
    ((void (__thiscall *)(_DWORD, _DWORD))this->vfptr[2].AddRef)(this, 1);
  return v1;
}

//----- (006BF880) --------------------------------------------------------  // acclient.c:727547
HRESULT __stdcall CEnumMediaTypes::Next(CEnumMediaTypes *this, unsigned int cMediaTypes, _AMMediaType **ppMediaTypes, unsigned int *pcFetched)
{
  _AMMediaType **v4; // ebp@1
  CEnumMediaTypes *v6; // esi@3
  unsigned int v7; // ebx@5
  int v8; // eax@12
  LPVOID v9; // eax@13
  CMediaType cmt; // [sp+4h] [bp-48h]@12
  unsigned int ppMediaTypesa; // [sp+58h] [bp+Ch]@7

  v4 = ppMediaTypes;
  if ( !ppMediaTypes )
    return -2147467261;
  v6 = this;
  if ( ((int (*)(void))this->m_pPin->vfptr[1].NonDelegatingAddRef)() != this->m_Version )
    return -2147220989;
  v7 = cMediaTypes;
  if ( pcFetched )
  {
    *pcFetched = 0;
  }
  else if ( cMediaTypes > 1 )
  {
    return -2147024809;
  }
  ppMediaTypesa = 0;
  if ( cMediaTypes )
  {
    while ( 1 )
    {
      CMediaType::CMediaType(&cmt);
      v8 = v6->m_Position;
      v6->m_Position = v8 + 1;
      if ( ((int (__stdcall *)(int, CMediaType *))v6->m_pPin->vfptr[4].NonDelegatingAddRef)(v8, &cmt) )
        break;
      v9 = CoTaskMemAlloc(0x48u);
      *v4 = (_AMMediaType *)v9;
      if ( !v9 )
        break;
      qmemcpy(v9, &cmt, 0x48u);
      ++v4;
      cmt.pbFormat = 0;
      cmt.cbFormat = 0;
      cmt.pUnk = 0;
      ++ppMediaTypesa;
      --v7;
      CMediaType::~CMediaType(&cmt);
      if ( !v7 )
        goto LABEL_17;
      v6 = this;
    }
    CMediaType::~CMediaType(&cmt);
  }
LABEL_17:
  if ( pcFetched )
    *pcFetched = ppMediaTypesa;
  return v7 != 0;
}

//----- (006BF990) --------------------------------------------------------  // acclient.c:727607
HRESULT __stdcall CEnumMediaTypes::Skip(CEnumMediaTypes *this, unsigned int cMediaTypes)
{
  HRESULT result; // eax@2
  HRESULT v3; // esi@5
  CMediaType cmt; // [sp+8h] [bp-48h]@5

  if ( cMediaTypes )
  {
    if ( ((int (*)(void))this->m_pPin->vfptr[1].NonDelegatingAddRef)() == this->m_Version )
    {
      this->m_Position += cMediaTypes;
      CMediaType::CMediaType(&cmt);
      v3 = ((int (__stdcall *)(int, CMediaType *))this->m_pPin->vfptr[4].NonDelegatingAddRef)(
             this->m_Position - 1,
             &cmt) != 0;
      CMediaType::~CMediaType(&cmt);
      result = v3;
    }
    else
    {
      result = -2147220989;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006BFA10) --------------------------------------------------------  // acclient.c:727638
HRESULT __stdcall CEnumMediaTypes::Reset(CEnumMediaTypes *this)
{
  CBasePin *v1; // ecx@1

  v1 = this->m_pPin;
  this->m_Position = 0;
  this->m_Version = ((int (*)(void))v1->vfptr[1].NonDelegatingAddRef)();
  return 0;
}

//----- (006BFA30) --------------------------------------------------------  // acclient.c:727649
HRESULT __stdcall CBasePin::NonDelegatingQueryInterface(CBasePin *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@3

  if ( !memcmp(riid, &IID_IPin, 0x10u) )
  {
    if ( this )
      return GetInterface((IUnknown *)&this->vfptr, ppv);
    return GetInterface(0, ppv);
  }
  if ( !memcmp(riid, &IID_IQualityControl, 0x10u) )
  {
    if ( !this )
      return GetInterface(0, ppv);
    result = GetInterface((IUnknown *)&this->vfptr, ppv);
  }
  else
  {
    result = CUnknown::NonDelegatingQueryInterface((CUnknown *)&this->vfptr, riid, ppv);
  }
  return result;
}

//----- (006BFAB0) --------------------------------------------------------  // acclient.c:727673
int __stdcall CBasePin::NonDelegatingAddRef(CBasePin *this)
{
  return this->m_pFilter->vfptr->AddRef((IUnknown *)&this->m_pFilter->vfptr);
}

//----- (006BFAD0) --------------------------------------------------------  // acclient.c:727679
int __stdcall CBasePin::NonDelegatingRelease(CBasePin *this)
{
  return this->m_pFilter->vfptr->Release((IUnknown *)&this->m_pFilter->vfptr);
}

//----- (006BFAF0) --------------------------------------------------------  // acclient.c:727685
unsigned int __thiscall CBasePin::AttemptConnection(CBasePin *this, IPin *pReceivePin, CMediaType *pmt)
{
  CBasePin *v3; // esi@1
  unsigned int v4; // edi@1
  int v6; // eax@3
  int v7; // edi@3
  IPin *v8; // eax@12

  v3 = this;
  v4 = this->vfptr[3].NonDelegatingAddRef((INonDelegatingUnknown *)pReceivePin);
  if ( (v4 & 0x80000000) != 0 )
  {
    ((void (__thiscall *)(CBasePin *))v3->vfptr[3].NonDelegatingRelease)(v3);
    return v4;
  }
  v6 = ((int (__thiscall *)(CBasePin *, CMediaType *))v3->vfptr[2].NonDelegatingRelease)(v3, pmt);
  v7 = v6;
  if ( v6 )
  {
    if ( v6 >= 0 || v6 == -2147467259 || v6 == -2147024809 )
      v7 = -2147220950;
    goto LABEL_12;
  }
  v3->m_Connected = pReceivePin;
  pReceivePin->vfptr->AddRef((IUnknown *)pReceivePin);
  v7 = ((int (__thiscall *)(CBasePin *, CMediaType *))v3->vfptr[3].NonDelegatingQueryInterface)(v3, pmt);
  if ( v7 < 0
    || (v7 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))pReceivePin->vfptr[1].AddRef)(pReceivePin, &v3->vfptr, pmt),
        v7 < 0) )
  {
LABEL_12:
    ((void (__thiscall *)(_DWORD))v3->vfptr[3].NonDelegatingRelease)(v3);
    v8 = v3->m_Connected;
    if ( v8 )
    {
      v8->vfptr->Release((IUnknown *)v3->m_Connected);
      v3->m_Connected = 0;
    }
    return v7;
  }
  v7 = ((int (__thiscall *)(CBasePin *, IPin *))v3->vfptr[4].NonDelegatingQueryInterface)(v3, pReceivePin);
  if ( v7 < 0 )
  {
    pReceivePin->vfptr[1].Release((IUnknown *)pReceivePin);
    goto LABEL_12;
  }
  return v7;
}

//----- (006BFBA0) --------------------------------------------------------  // acclient.c:727735
HRESULT __thiscall CBasePin::TryMediaTypes(CBasePin *this, IPin *pReceivePin, CMediaType *pmt, IEnumMediaTypes *pEnum)
{
  IEnumMediaTypes *v4; // edi@1
  IUnknownVtbl *v5; // eax@1
  HRESULT result; // eax@1
  IUnknownVtbl *v7; // ecx@2
  signed int v8; // ebx@2
  signed int v9; // esi@5
  unsigned int v10; // eax@6
  unsigned int ulMediaCount; // [sp+14h] [bp-8h]@2
  CBasePin *v12; // [sp+18h] [bp-4h]@1

  v4 = pEnum;
  v5 = pEnum->vfptr;
  v12 = this;
  result = v5[1].Release((IUnknown *)pEnum);
  if ( result >= 0 )
  {
    v7 = v4->vfptr;
    pEnum = 0;
    ulMediaCount = 0;
    v8 = 0;
    if ( !((int (__stdcall *)(IEnumMediaTypes *, signed int, IEnumMediaTypes **, unsigned int *))v7[1].QueryInterface)(
            v4,
            1,
            &pEnum,
            &ulMediaCount) )
    {
      do
      {
        if ( !pmt || CMediaType::MatchesPartial((CMediaType *)pEnum, pmt) )
        {
          v10 = CBasePin::AttemptConnection(v12, pReceivePin, (CMediaType *)pEnum);
          v9 = v10;
          if ( (v10 & 0x80000000) != 0 && v8 >= 0 && v10 != -2147467259 && v10 != -2147024809 && v10 != -2147220950 )
            v8 = v10;
        }
        else
        {
          v9 = -2147220985;
        }
        DeleteMediaType((_AMMediaType *)pEnum);
        if ( !v9 )
          return 0;
      }
      while ( !((int (__stdcall *)(IEnumMediaTypes *, signed int, IEnumMediaTypes **, unsigned int *))v4->vfptr[1].QueryInterface)(
                 v4,
                 1,
                 &pEnum,
                 &ulMediaCount) );
      if ( v8 )
        goto LABEL_16;
    }
    v8 = -2147220985;
LABEL_16:
    result = v8;
  }
  return result;
}

//----- (006BFC80) --------------------------------------------------------  // acclient.c:727796
unsigned int __thiscall CBasePin::AgreeMediaType(CBasePin *this, IPin *pReceivePin, CMediaType *pmt)
{
  CMediaType *v3; // ebp@1
  CBasePin *v4; // edi@1
  int v6; // eax@4
  int v7; // eax@6
  HRESULT v8; // esi@9
  bool v9; // sf@14
  unsigned __int8 v10; // of@14
  IEnumMediaTypes *pEnumMediaTypes; // [sp+8h] [bp-8h]@1
  HRESULT hrFailure; // [sp+Ch] [bp-4h]@4
  CMediaType *pmta; // [sp+18h] [bp+8h]@4

  v3 = pmt;
  v4 = this;
  pEnumMediaTypes = 0;
  if ( pmt && !CMediaType::IsPartiallySpecified(pmt) )
    return CBasePin::AttemptConnection(v4, pReceivePin, pmt);
  v6 = 0;
  hrFailure = -2147220985;
  pmta = 0;
  while ( 1 )
  {
    if ( v6 == v4->m_bTryMyTypesFirst )
      v7 = ((int (__stdcall *)(_DWORD, _DWORD))pReceivePin->vfptr[4].QueryInterface)(pReceivePin, &pEnumMediaTypes);
    else
      v7 = ((int (__stdcall *)(int, IEnumMediaTypes **))v4->vfptr[4].QueryInterface)(&v4->vfptr, &pEnumMediaTypes);
    if ( v7 < 0 )
      goto LABEL_14;
    v8 = CBasePin::TryMediaTypes(v4, pReceivePin, v3, pEnumMediaTypes);
    pEnumMediaTypes->vfptr->Release((IUnknown *)pEnumMediaTypes);
    if ( v8 >= 0 )
      return 0;
    if ( v8 != -2147467259 && v8 != -2147024809 && v8 != -2147220950 )
      hrFailure = v8;
LABEL_14:
    v6 = (int)((char *)&pmta->majortype.Data1 + 1);
    v10 = __OFSUB__((char *)&pmta->majortype.Data1 + 1, 2);
    v9 = (signed int)((char *)&pmta[-1].pbFormat + 3) < 0;
    pmta = (CMediaType *)((char *)pmta + 1);
    if ( !(v9 ^ v10) )
      return hrFailure;
  }
}

//----- (006BFD60) --------------------------------------------------------  // acclient.c:727842
HRESULT __thiscall CBasePin::SetMediaType(CBasePin *this, CMediaType *pmt)
{
  HRESULT v2; // eax@1

  v2 = CMediaType::Set(&this->m_mt, pmt);
  return v2 >= 0 ? 0 : v2;
}

//----- (006BFD80) --------------------------------------------------------  // acclient.c:727851
HRESULT __thiscall CBasePin::CheckConnect(CBasePin *this, IPin *pPin)
{
  CBasePin *v2; // esi@1

  v2 = this;
  ((void (__stdcall *)(IPin *, IPin **))pPin->vfptr[3].QueryInterface)(pPin, &pPin);
  return pPin != (IPin *)v2->m_dir ? 0 : 0x80040208;
}

//----- (006BFDB0) --------------------------------------------------------  // acclient.c:727861
HRESULT __stdcall CBasePin::ReceiveConnection(CBasePin *this, IPin *pConnector, _AMMediaType *pmt)
{
  IUnknownVtbl *v3; // ebp@1
  unsigned __int16 *v5; // esi@4
  char *v6; // esi@9
  int v7; // ebx@9
  char *v8; // ecx@9
  int v9; // ebx@11
  int v10; // edx@19
  unsigned __int16 *pConnectora; // [sp+14h] [bp+8h]@4

  v3 = (IUnknownVtbl *)pConnector;
  if ( !pConnector || !pmt )
    return -2147467261;
  v5 = this->m_pName;
  pConnectora = this->m_pName;
  EnterCriticalSection((LPCRITICAL_SECTION)v5);
  if ( this->vfptr )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)v5);
    return -2147220988;
  }
  if ( *(_DWORD *)(this->m_dir + 20) && !BYTE1(this->m_Connected) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)v5);
    return -2147220956;
  }
  v6 = (char *)&this[-1].m_tStop.m_time + 4;
  v7 = (*(int (__thiscall **)(char *, IUnknownVtbl *))(HIDWORD(this[-1].m_tStop.m_time) + 40))(
         (char *)&this[-1].m_tStop.m_time + 4,
         v3);
  v8 = (char *)&this[-1].m_tStop.m_time + 4;
  if ( v7 < 0 )
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)v6 + 44))(v8);
    LeaveCriticalSection((LPCRITICAL_SECTION)pConnectora);
    return v7;
  }
  v9 = (*(int (__thiscall **)(char *, _AMMediaType *))(*(_DWORD *)v6 + 32))(v8, pmt);
  if ( v9 )
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)v6 + 44))((char *)&this[-1].m_tStop.m_time + 4);
    if ( v9 >= 0 || v9 == -2147467259 || v9 == -2147024809 )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)pConnectora);
      return -2147220950;
    }
  }
  else
  {
    this->vfptr = v3;
    (*((void (__stdcall **)(IUnknownVtbl *))v3->QueryInterface + 1))(v3);
    v9 = (*(int (__thiscall **)(char *, _AMMediaType *))(*(_DWORD *)v6 + 36))((char *)&this[-1].m_tStop.m_time + 4, pmt);
    if ( v9 >= 0 )
    {
      v9 = (*(int (__thiscall **)(char *, IUnknownVtbl *))(*(_DWORD *)v6 + 48))(
             (char *)&this[-1].m_tStop.m_time + 4,
             v3);
      if ( v9 >= 0 )
      {
        LeaveCriticalSection((LPCRITICAL_SECTION)pConnectora);
        return 0;
      }
    }
    (*(void (__stdcall **)(IUnknownVtbl *))((void (__stdcall **)(_DWORD))this->vfptr->QueryInterface + 2))(this->vfptr);
    v10 = *(_DWORD *)v6;
    this->vfptr = 0;
    (*(void (__thiscall **)(char *))(v10 + 44))((char *)&this[-1].m_tStop.m_time + 4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)pConnectora);
  return v9;
}

//----- (006BFF00) --------------------------------------------------------  // acclient.c:727935
HRESULT __stdcall CBasePin::ConnectedTo(CBasePin *this, IPin **ppPin)
{
  HRESULT result; // eax@2
  IUnknownVtbl *v3; // eax@3

  if ( ppPin )
  {
    v3 = this->vfptr;
    *ppPin = (IPin *)v3;
    if ( v3 )
    {
      (*((void (__stdcall **)(IUnknownVtbl *))v3->QueryInterface + 1))(v3);
      result = 0;
    }
    else
    {
      result = -2147220983;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BFF30) --------------------------------------------------------  // acclient.c:727962
HRESULT __stdcall CBasePin::ConnectionMediaType(CBasePin *this, _AMMediaType *pmt)
{
  HRESULT result; // eax@2
  unsigned __int16 *v3; // esi@3

  if ( pmt )
  {
    v3 = this->m_pName;
    EnterCriticalSection((LPCRITICAL_SECTION)this->m_pName);
    if ( this->vfptr )
    {
      CopyMediaType(pmt, (_AMMediaType *)&this->m_pFilter);
      LeaveCriticalSection((LPCRITICAL_SECTION)v3);
      result = 0;
    }
    else
    {
      CMediaType::InitMediaType((CMediaType *)pmt);
      LeaveCriticalSection((LPCRITICAL_SECTION)v3);
      result = -2147220983;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BFF90) --------------------------------------------------------  // acclient.c:727992
HRESULT __stdcall CBasePin::QueryPinInfo(CBasePin *this, _PinInfo *pInfo)
{
  HRESULT result; // eax@2
  _PinDirection v3; // eax@3
  IBaseFilter *v4; // eax@4
  _PinDirection v5; // eax@6
  const unsigned __int16 *v6; // eax@8

  if ( pInfo )
  {
    v3 = this->m_dir;
    if ( v3 )
      v4 = (IBaseFilter *)(v3 + 12);
    else
      v4 = 0;
    pInfo->pFilter = v4;
    v5 = this->m_dir;
    if ( v5 )
      (*(void (__stdcall **)(int))(*(_DWORD *)(v5 + 12) + 4))(v5 + 12);
    v6 = (const unsigned __int16 *)this->m_cRef;
    if ( v6 )
    {
      lstrcpynWInternal(pInfo->achName, v6, 128);
      pInfo->dir = (_PinDirection)this->vfptr;
      result = 0;
    }
    else
    {
      pInfo->achName[0] = 0;
      pInfo->dir = (_PinDirection)this->vfptr;
      result = 0;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0000) --------------------------------------------------------  // acclient.c:728033
HRESULT __stdcall CBasePin::QueryDirection(CBasePin *this, _PinDirection *pPinDir)
{
  HRESULT result; // eax@2

  if ( pPinDir )
  {
    *pPinDir = (_PinDirection)this->vfptr;
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0020) --------------------------------------------------------  // acclient.c:728050
HRESULT __stdcall CBasePin::QueryAccept(CBasePin *this, _AMMediaType *pmt)
{
  HRESULT result; // eax@2

  if ( pmt )
  {
    result = (*(int (__thiscall **)(char *, _AMMediaType *))(HIDWORD(this[-1].m_tStop.m_time) + 32))(
               (char *)&this[-1].m_tStop.m_time + 4,
               pmt);
    if ( result < 0 )
      result = 1;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0050) --------------------------------------------------------  // acclient.c:728070
HRESULT __stdcall CBasePin::GetMediaType(int iPosition, CMediaType *pMediaType)
{
  return -2147418113;
}

//----- (006C0060) --------------------------------------------------------  // acclient.c:728076
HRESULT __stdcall CBasePin::SetSink(CBasePin *this, IQualityControl *piqc)
{
  IUnknownVtbl *v2; // esi@1

  v2 = this->vfptr;
  EnterCriticalSection((LPCRITICAL_SECTION)this->vfptr);
  this->m_dir = (_PinDirection)piqc;
  LeaveCriticalSection((LPCRITICAL_SECTION)v2);
  return 0;
}

//----- (006C0090) --------------------------------------------------------  // acclient.c:728088
HRESULT __stdcall CBasePin::NewSegment(CBasePin *this, __int64 tStart, __int64 tStop, long double dRate)
{
  *(_QWORD *)&this->m_mt.cbFormat = tStart;
  *((_QWORD *)&this->m_mt + 9) = tStop;
  *(long double *)((char *)&this->m_tStart.m_time + 4) = dRate;
  return 0;
}

//----- (006C00D0) --------------------------------------------------------  // acclient.c:728097
void __thiscall CBaseInputPin::~CBaseInputPin(CBaseInputPin *this)
{
  CBaseInputPin *v1; // esi@1
  IMemAllocator *v2; // eax@1

  v1 = this;
  v2 = this->m_pAllocator;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v2);
    v1->m_pAllocator = 0;
  }
  operator delete[](v1->m_pName);
  CMediaType::~CMediaType(&v1->m_mt);
  CBaseObject::~CBaseObject();
}

//----- (006C0110) --------------------------------------------------------  // acclient.c:728115
HRESULT __stdcall CBaseInputPin::NonDelegatingQueryInterface(CBaseInputPin *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@3

  if ( !memcmp(riid, &IID_IMemInputPin, 0x10u) )
  {
    if ( this )
      result = GetInterface((IUnknown *)&this->vfptr, ppv);
    else
      result = GetInterface(0, ppv);
  }
  else
  {
    result = CBasePin::NonDelegatingQueryInterface((CBasePin *)&this->vfptr, riid, ppv);
  }
  return result;
}

//----- (006C0160) --------------------------------------------------------  // acclient.c:728134
HRESULT __stdcall CBaseInputPin::GetAllocator(CBaseInputPin *this, IMemAllocator **ppAllocator)
{
  HRESULT result; // eax@2
  unsigned int v3; // edi@3
  IMemAllocator **v4; // esi@3
  HRESULT v5; // ebx@4

  if ( ppAllocator )
  {
    v3 = this[-1].m_mt.formattype.Data1;
    EnterCriticalSection((LPCRITICAL_SECTION)this[-1].m_mt.formattype.Data1);
    v4 = (IMemAllocator **)&this->m_pUnknown;
    if ( this->m_pUnknown
      || (v5 = CoCreateInstance(&CLSID_MemoryAllocator, 0, 1u, &IID_IMemAllocator, (LPVOID *)v4), v5 >= 0) )
    {
      *ppAllocator = *v4;
      (*v4)->vfptr->AddRef((IUnknown *)*v4);
      LeaveCriticalSection((LPCRITICAL_SECTION)v3);
      result = 0;
    }
    else
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)v3);
      result = v5;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C01E0) --------------------------------------------------------  // acclient.c:728168
HRESULT __stdcall CBaseInputPin::NotifyAllocator(CBaseInputPin *this, IMemAllocator *pAllocator, int bReadOnly)
{
  HRESULT result; // eax@2
  unsigned int v4; // ebp@3
  IUnknown *const v5; // ebx@3

  if ( pAllocator )
  {
    v4 = this[-1].m_mt.formattype.Data1;
    EnterCriticalSection((LPCRITICAL_SECTION)this[-1].m_mt.formattype.Data1);
    v5 = this->m_pUnknown;
    pAllocator->vfptr->AddRef((IUnknown *)pAllocator);
    this->m_pUnknown = (IUnknown *const )pAllocator;
    if ( v5 )
      v5->vfptr->Release(v5);
    LOBYTE(this->m_cRef) = bReadOnly;
    LeaveCriticalSection((LPCRITICAL_SECTION)v4);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0230) --------------------------------------------------------  // acclient.c:728195
HRESULT __thiscall CBaseInputPin::BreakConnect(CBaseInputPin *this)
{
  CBaseInputPin *v1; // esi@1
  IMemAllocator *v2; // eax@1
  HRESULT result; // eax@2

  v1 = this;
  v2 = this->m_pAllocator;
  if ( v2 )
  {
    result = ((int (__stdcall *)(IMemAllocator *))v2->vfptr[2].QueryInterface)(v2);
    if ( result < 0 )
      return result;
    v1->m_pAllocator->vfptr->Release((IUnknown *)v1->m_pAllocator);
    v1->m_pAllocator = 0;
  }
  return 0;
}

//----- (006C0270) --------------------------------------------------------  // acclient.c:728215
HRESULT __userpurge CBaseInputPin::Receive@<eax>(int a1@<ebp>, int a2@<esi>, CBaseInputPin *this, IMediaSample *pSample, IMediaSample2 *pSample2, int a6)
{
  IMediaSample *v6; // edi@1
  HRESULT result; // eax@2
  int v8; // edi@5
  int v9; // ecx@21
  int v10; // eax@21

  v6 = pSample;
  if ( !pSample )
    return -2147467261;
  result = (*(int (__thiscall **)(char *))(*(_DWORD *)&this[-1].m_mt.majortype.Data4[4] + 56))(&this[-1].m_mt.majortype.Data4[4]);
  if ( !result )
  {
    if ( ((int (__stdcall *)(IMediaSample *, GUID *, IMediaSample **, int, int))v6->vfptr->QueryInterface)(
           v6,
           &IID_IMediaSample2,
           &pSample,
           a2,
           a1) < 0 )
    {
      this->vfptr = (IUnknownVtbl *)48;
      this->m_pName = 0;
      this->m_TypeVersion = 0;
      this->m_Connected = 0;
      if ( !((int (__stdcall *)(IMediaSample *))v6->vfptr[5].QueryInterface)(v6) )
        this->m_Connected = (IPin *)((unsigned int)this->m_Connected | 4);
      if ( !((int (__stdcall *)(IMediaSample *))v6->vfptr[3].QueryInterface)(v6) )
        this->m_Connected = (IPin *)((unsigned int)this->m_Connected | 2);
      if ( !v6->vfptr[2].AddRef((IUnknown *)v6) )
        this->m_Connected = (IPin *)((unsigned int)this->m_Connected | 1);
      if ( ((int (__stdcall *)(IMediaSample *, CCritSec **, CBaseFilter **))v6->vfptr[1].Release)(
             v6,
             &this->m_pLock,
             &this->m_pFilter) >= 0 )
        this->m_Connected = (IPin *)((unsigned int)this->m_Connected | 0x110);
      if ( !((int (__stdcall *)(IMediaSample *, CMediaType *))v6->vfptr[4].AddRef)(v6, &this->m_mt) )
        this->m_Connected = (IPin *)((unsigned int)this->m_Connected | 8);
      ((void (__cdecl *)(IMediaSample *, unsigned __int16 *))v6->vfptr[1].QueryInterface)(
        v6,
        &this->m_mt.majortype.Data2);
      this->m_dir = v6->vfptr[3].Release((IUnknown *)v6);
      *(_DWORD *)&this->m_mt.majortype.Data4[0] = v6->vfptr[1].AddRef((IUnknown *)v6);
    }
    else
    {
      v8 = (*(int (__stdcall **)(int))(*(_DWORD *)a6 + 76))(a6);
      pSample->vfptr->Release((IUnknown *)pSample);
      if ( v8 < 0 )
        return v8;
    }
    if ( (unsigned int)this->m_Connected & 8
      && (*(int (__thiscall **)(char *, unsigned int))(*(_DWORD *)&this[-1].m_mt.majortype.Data4[4] + 32))(
           &this[-1].m_mt.majortype.Data4[4],
           this->m_mt.majortype.Data1) )
    {
      v9 = *(_DWORD *)&this[-1].m_mt.subtype.Data4[0];
      LOBYTE(this[-1].m_mt.formattype.Data2) = 1;
      (*(void (__stdcall **)(char *))(v9 + 56))(this[-1].m_mt.subtype.Data4);
      v10 = *(_DWORD *)(*(_DWORD *)&this[-1].m_mt.formattype.Data4[0] + 68);
      if ( v10 )
        (*(void (__stdcall **)(int, signed int, signed int, _DWORD))(*(_DWORD *)v10 + 12))(v10, 3, -2147220950, 0);
      result = -2147220992;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 6C0270: could not find valid save-restore pair for ebp
// 6C0270: could not find valid save-restore pair for esi

//----- (006C03D0) --------------------------------------------------------  // acclient.c:728290
HRESULT __stdcall CBaseInputPin::ReceiveMultiple(CBaseInputPin *this, IMediaSample **pSamples, int nSamples, int *nSamplesProcessed)
{
  HRESULT result; // eax@2
  int v5; // edi@3

  if ( pSamples )
  {
    v5 = nSamples;
    result = 0;
    for ( *nSamplesProcessed = 0; v5 > 0; ++*nSamplesProcessed )
    {
      --v5;
      result = ((int (__stdcall *)(CBaseInputPin *, IMediaSample *))this->vfptr[2].NonDelegatingQueryInterface)(
                 this,
                 pSamples[*nSamplesProcessed]);
      if ( result )
        break;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0430) --------------------------------------------------------  // acclient.c:728317
HRESULT __stdcall CBaseInputPin::ReceiveCanBlock(CBaseInputPin *this)
{
  CBaseInputPin *v1; // ebx@1
  int v2; // ebp@1
  int v3; // edi@1
  int v4; // eax@2
  int v5; // esi@2
  HRESULT result; // eax@2
  HRESULT v7; // esi@5
  unsigned int v8; // esi@6
  IMemInputPin *pInputPin; // [sp+28h] [bp-Ch]@5
  _PinDirection pd; // [sp+2Ch] [bp-8h]@2
  int cPins; // [sp+30h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  v3 = 0;
  cPins = (*(int (**)(void))(**(_DWORD **)&this[-1].m_mt.formattype.Data4[0] + 24))();
  if ( cPins <= 0 )
  {
LABEL_8:
    result = v2 != 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = (*(int (__stdcall **)(int))(**(_DWORD **)&v1[-1].m_mt.formattype.Data4[0] + 28))(v3);
      v5 = v4 + 12;
      result = (*(int (__stdcall **)(int, _PinDirection *))(*(_DWORD *)(v4 + 12) + 36))(v4 + 12, &pd);
      if ( result < 0 )
        break;
      if ( pd == 1 && (*(int (__stdcall **)(int, CBaseInputPin **))(*(_DWORD *)v5 + 24))(v5, &this) >= 0 )
      {
        ++v2;
        v7 = this->vfptr->NonDelegatingQueryInterface(
               (INonDelegatingUnknown *)this,
               &IID_IMemInputPin,
               (void **)&pInputPin);
        this->vfptr->NonDelegatingRelease((INonDelegatingUnknown *)this);
        if ( v7 < 0 )
          return 0;
        v8 = pInputPin->vfptr[2].Release((IUnknown *)pInputPin);
        pInputPin->vfptr->Release((IUnknown *)pInputPin);
        if ( v8 != 1 )
          return 0;
      }
      ++v3;
      if ( v3 >= cPins )
        goto LABEL_8;
    }
  }
  return result;
}

//----- (006C04F0) --------------------------------------------------------  // acclient.c:728373
HRESULT __stdcall CBaseInputPin::BeginFlush(CBaseInputPin *this)
{
  unsigned __int16 *v1; // esi@1

  v1 = this->m_pName;
  EnterCriticalSection((LPCRITICAL_SECTION)this->m_pName);
  BYTE5(this->m_dRate) = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)v1);
  return 0;
}

//----- (006C0520) --------------------------------------------------------  // acclient.c:728385
HRESULT __stdcall CBaseInputPin::EndFlush(CBaseInputPin *this)
{
  unsigned __int16 *v1; // edi@1

  v1 = this->m_pName;
  EnterCriticalSection((LPCRITICAL_SECTION)this->m_pName);
  BYTE5(this->m_dRate) = 0;
  LOBYTE(this->m_Connected) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)v1);
  return 0;
}

//----- (006C0550) --------------------------------------------------------  // acclient.c:728398
HRESULT __stdcall CBaseInputPin::Notify(CBaseInputPin *this, IBaseFilter *pSender, tagQuality q)
{
  return pSender != 0 ? 0 : 0x80004003;
}

//----- (006C0570) --------------------------------------------------------  // acclient.c:728404
HRESULT __thiscall CBaseInputPin::CheckStreaming(CBaseInputPin *this)
{
  HRESULT result; // eax@2

  if ( this->m_pFilter->m_State )
  {
    if ( this->m_bFlushing )
      result = 1;
    else
      result = this->m_bRunTimeError != 0 ? 0x8004020B : 0;
  }
  else
  {
    result = -2147220953;
  }
  return result;
}

//----- (006C05A0) --------------------------------------------------------  // acclient.c:728423
HRESULT __stdcall AMovieSetupRegisterFilter(_AMOVIESETUP_FILTER *const psetupdata, IFilterMapper *pIFM, int bRegister)
{
  _AMOVIESETUP_FILTER *const v3; // edi@1
  unsigned int v4; // esi@1
  HRESULT result; // eax@2
  _GUID *v6; // ecx@3
  IFilterMapper *v7; // ebx@3
  IUnknownVtbl *v8; // eax@3
  const unsigned __int16 *v9; // ebp@3
  unsigned int v10; // ecx@3
  int v11; // eax@3
  const unsigned __int16 *v12; // ecx@4
  IUnknownVtbl *v13; // edx@4
  _GUID *v14; // eax@4
  unsigned int v15; // ebp@4
  unsigned int v16; // ebp@4
  int v17; // eax@4
  IUnknownVtbl *v18; // edx@6
  int v19; // eax@6
  int v20; // ecx@6
  int v21; // ebp@6
  const unsigned __int16 *v22; // ecx@6
  unsigned __int16 *v23; // ecx@6
  int v24; // eax@6
  _GUID *v25; // ecx@6
  unsigned int v26; // ebx@6
  int v27; // ebx@6
  int v28; // ecx@6
  __MIDL___MIDL_itf_strmif_0134_0002 *v29; // ecx@7
  int v30; // edx@7
  int v31; // eax@8
  IUnknownVtbl *v32; // edx@8
  int v33; // eax@8
  unsigned __int16 *v34; // ecx@8
  const unsigned __int16 *v35; // ebp@8
  unsigned int v36; // eax@8
  int v37; // eax@8
  unsigned int v38; // ebp@8
  int v39; // eax@8
  _GUID *v40; // eax@8
  unsigned int v41; // ebx@8
  int v42; // ebx@8
  int v43; // eax@8
  IFilterMapper *v44; // [sp+54h] [bp-4Ch]@6
  unsigned int v45; // [sp+58h] [bp-48h]@6
  int v46; // [sp+5Ch] [bp-44h]@6
  int v47; // [sp+60h] [bp-40h]@6
  int v48; // [sp+64h] [bp-3Ch]@6
  unsigned __int16 *v49; // [sp+68h] [bp-38h]@6
  int v50; // [sp+6Ch] [bp-34h]@6
  int v51; // [sp+70h] [bp-30h]@6
  unsigned int v52; // [sp+74h] [bp-2Ch]@4
  int v53; // [sp+78h] [bp-28h]@4
  unsigned int v54; // [sp+7Ch] [bp-24h]@3
  int v55; // [sp+80h] [bp-20h]@3
  const unsigned __int16 *v56; // [sp+84h] [bp-1Ch]@3
  unsigned int v57; // [sp+88h] [bp-18h]@3
  int v58; // [sp+9Ch] [bp-4h]@8
  _AMOVIESETUP_FILTER *const psetupdataa; // [sp+A4h] [bp+4h]@7
  int bRegistera; // [sp+ACh] [bp+Ch]@5

  v3 = psetupdata;
  v4 = 0;
  if ( psetupdata )
  {
    v6 = psetupdata->clsID;
    v7 = pIFM;
    v8 = pIFM->vfptr;
    v54 = psetupdata->clsID->Data1;
    v55 = *(_DWORD *)&v6->Data2;
    v9 = *(const unsigned __int16 **)&v6->Data4[0];
    v10 = *(_DWORD *)&v6->Data4[4];
    v56 = v9;
    v57 = v10;
    v11 = ((int (__stdcall *)(IFilterMapper *, unsigned int, int, const unsigned __int16 *, unsigned int))v8[2].AddRef)(
            pIFM,
            v54,
            v55,
            v9,
            v10);
    if ( bRegister )
    {
      v12 = psetupdata->strName;
      v13 = pIFM->vfptr;
      v57 = psetupdata->dwMerit;
      v14 = psetupdata->clsID;
      v15 = psetupdata->clsID->Data1;
      v56 = v12;
      v52 = v15;
      v53 = *(_DWORD *)&v14->Data2;
      v16 = *(_DWORD *)&v14->Data4[0];
      v17 = *(_DWORD *)&v14->Data4[4];
      v54 = v16;
      v55 = v17;
      v11 = ((int (__stdcall *)(IFilterMapper *, unsigned int, int, unsigned int, int, const unsigned __int16 *, unsigned int))v13[1].QueryInterface)(
              pIFM,
              v52,
              v53,
              v16,
              v17,
              v12,
              v57);
      if ( v11 >= 0 )
      {
        bRegistera = 0;
        if ( psetupdata->nPins )
        {
          do
          {
            v18 = v7->vfptr;
            v19 = (int)&v3->lpPin[v4];
            v57 = *(_DWORD *)(v19 + 24);
            v20 = *(_DWORD *)(v19 + 20);
            v53 = *(_DWORD *)v20;
            v54 = *(_DWORD *)(v20 + 4);
            v21 = *(_DWORD *)(v20 + 8);
            v22 = *(const unsigned __int16 **)(v20 + 12);
            v55 = v21;
            v56 = v22;
            v52 = *(_DWORD *)(v19 + 16);
            v51 = *(_DWORD *)(v19 + 12);
            v50 = *(_DWORD *)(v19 + 8);
            v23 = *(unsigned __int16 **)(v19 + 4);
            v24 = *(_DWORD *)v19;
            v49 = v23;
            v25 = v3->clsID;
            v26 = v3->clsID->Data1;
            v48 = v24;
            v44 = (IFilterMapper *)v26;
            v45 = *(_DWORD *)&v25->Data2;
            v27 = *(_DWORD *)&v25->Data4[0];
            v28 = *(_DWORD *)&v25->Data4[4];
            v46 = v27;
            v7 = pIFM;
            v47 = v28;
            v11 = ((int (__stdcall *)(IFilterMapper *, IFilterMapper *, unsigned int, int, int, int, unsigned __int16 *, int, int, unsigned int, int, unsigned int, int, const unsigned __int16 *, unsigned int))v18[1].Release)(
                    pIFM,
                    v44,
                    v45,
                    v46,
                    v28,
                    v24,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v21,
                    v56,
                    v57);
            if ( v11 < 0 )
              break;
            v29 = v3->lpPin;
            v30 = 0;
            psetupdataa = 0;
            if ( v29[v4].nMediaTypes )
            {
              do
              {
                v31 = (int)&v29[v4].lpMediaType[v30];
                v32 = v7->vfptr;
                v58 = v31;
                v33 = *(_DWORD *)(v31 + 4);
                v34 = v29[v4].strName;
                v54 = *(_DWORD *)v33;
                v55 = *(_DWORD *)(v33 + 4);
                v35 = *(const unsigned __int16 **)(v33 + 8);
                v36 = *(_DWORD *)(v33 + 12);
                v56 = v35;
                v57 = v36;
                v37 = *(_DWORD *)v58;
                v50 = **(_DWORD **)v58;
                v51 = *(_DWORD *)(v37 + 4);
                v38 = *(_DWORD *)(v37 + 8);
                v39 = *(_DWORD *)(v37 + 12);
                v52 = v38;
                v53 = v39;
                v40 = v3->clsID;
                v41 = v3->clsID->Data1;
                v49 = v34;
                v45 = v41;
                v46 = *(_DWORD *)&v40->Data2;
                v42 = *(_DWORD *)&v40->Data4[0];
                v43 = *(_DWORD *)&v40->Data4[4];
                v47 = v42;
                v7 = pIFM;
                v44 = pIFM;
                v48 = v43;
                v11 = ((int (__stdcall *)(IFilterMapper *, unsigned int, int, int, int, unsigned __int16 *, int, int, unsigned int, int, unsigned int, int, const unsigned __int16 *, unsigned int))v32[2].QueryInterface)(
                        pIFM,
                        v45,
                        v46,
                        v47,
                        v43,
                        v34,
                        v50,
                        v51,
                        v38,
                        v53,
                        v54,
                        v55,
                        v56,
                        v57);
                if ( v11 < 0 )
                  goto LABEL_11;
                v29 = v3->lpPin;
                v30 = (int)((char *)&psetupdataa->clsID + 1);
                psetupdataa = (_AMOVIESETUP_FILTER *const )((char *)psetupdataa + 1);
              }
              while ( (unsigned int)psetupdataa < v29[v4].nMediaTypes );
            }
            ++v4;
            ++bRegistera;
          }
          while ( bRegistera < v3->nPins );
        }
      }
    }
LABEL_11:
    result = v11 == -2147024894 ? 0 : v11;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006C0770) --------------------------------------------------------  // acclient.c:728653
HRESULT __stdcall CBaseFilter::Register(CBaseFilter *this)
{
  _AMOVIESETUP_FILTER *v1; // esi@1
  HRESULT result; // eax@2

  v1 = (_AMOVIESETUP_FILTER *)((int (__thiscall *)(IFilterGraph **))this[-1].m_pGraph[8].vfptr)(&this[-1].m_pGraph);
  if ( v1 )
  {
    CoInitialize(0);
    if ( CoCreateInstance(&CLSID_FilterMapper, 0, 1u, &IID_IFilterMapper, (LPVOID *)&this) >= 0 )
    {
      AMovieSetupRegisterFilter(v1, (IFilterMapper *)this, 1);
      this->vfptr->NonDelegatingRelease((INonDelegatingUnknown *)this);
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006C07E0) --------------------------------------------------------  // acclient.c:728679
HRESULT __stdcall CBaseFilter::Unregister(CBaseFilter *this)
{
  _AMOVIESETUP_FILTER *v1; // esi@1
  HRESULT result; // eax@2
  HRESULT v3; // edi@3

  v1 = (_AMOVIESETUP_FILTER *)((int (__thiscall *)(IFilterGraph **))this[-1].m_pGraph[8].vfptr)(&this[-1].m_pGraph);
  if ( v1 )
  {
    CoInitialize(0);
    v3 = CoCreateInstance(&CLSID_FilterMapper, 0, 1u, &IID_IFilterMapper, (LPVOID *)&this);
    if ( v3 >= 0 )
    {
      v3 = AMovieSetupRegisterFilter(v1, (IFilterMapper *)this, 0);
      this->vfptr->NonDelegatingRelease((INonDelegatingUnknown *)this);
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    result = v3 == -2147024894 ? 0 : v3;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006C0860) --------------------------------------------------------  // acclient.c:728707
void __thiscall CEnumPins::CEnumPins(CEnumPins *this, CBaseFilter *pFilter, CEnumPins *pEnumPins)
{
  CEnumPins *v3; // esi@1
  CBaseList *v4; // edi@1
  int v5; // eax@2
  CBaseFilter *v6; // ecx@2

  v3 = this;
  v4 = (CBaseList *)&this->m_PinCache.m_pFirst;
  this->vfptr = (IUnknownVtbl *)&CEnumPins::vftable;
  this->m_Position = 0;
  this->m_PinCount = 0;
  this->m_pFilter = pFilter;
  this->m_cRef = 1;
  CBaseList::CBaseList((CBaseList *)&this->m_PinCache.m_pFirst, "Pin Cache");
  v3->m_pFilter->vfptr->AddRef((IUnknown *)&v3->m_pFilter->vfptr);
  if ( pEnumPins )
  {
    v3->m_Position = pEnumPins->m_Position;
    v3->m_PinCount = pEnumPins->m_PinCount;
    v3->m_Version = pEnumPins->m_Version;
    CBaseList::AddTail(v4, (CBaseList *)&pEnumPins->m_PinCache.m_pFirst);
  }
  else
  {
    v5 = ((int (*)(void))v3->m_pFilter->vfptr[1].NonDelegatingRelease)();
    v6 = v3->m_pFilter;
    v3->m_Version = v5;
    v3->m_PinCount = ((int (*)(void))v6->vfptr[2].NonDelegatingQueryInterface)();
  }
}
// 806F8C: using guessed type __int32 (__stdcall *CEnumPins::vftable)(CEnumPins *this, _GUID *riid, void **ppv);

//----- (006C08F0) --------------------------------------------------------  // acclient.c:728741
CEnumPins *__thiscall CEnumPins::vector_deleting_destructor(CEnumPins *this, unsigned int a2)
{
  CEnumPins *v2; // esi@1
  char *v3; // eax@1

  v2 = this;
  v3 = (char *)&this->m_pFilter->vfptr;
  this->vfptr = (IUnknownVtbl *)&CEnumPins::vftable;
  (*(void (__stdcall **)(char *))(*(_DWORD *)v3 + 8))(v3);
  CBaseList::~CBaseList((CBaseList *)&v2->m_PinCache.m_pFirst);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 806F8C: using guessed type __int32 (__stdcall *CEnumPins::vftable)(CEnumPins *this, _GUID *riid, void **ppv);

//----- (006C0930) --------------------------------------------------------  // acclient.c:728758
HRESULT __stdcall CEnumPins::Clone(CEnumPins *this, IEnumPins **ppEnum)
{
  HRESULT result; // eax@2
  signed int v3; // edi@3
  CEnumPins *v4; // eax@5
  IEnumPins *v5; // eax@6

  if ( ppEnum )
  {
    v3 = 0;
    if ( ((int (*)(void))this->m_pFilter->vfptr[1].NonDelegatingRelease)() == this->m_Version )
    {
      v4 = (CEnumPins *)operator new(0x30u);
      if ( v4 )
        CEnumPins::CEnumPins(v4, this->m_pFilter, this);
      else
        v5 = 0;
      *ppEnum = v5;
      if ( !v5 )
        v3 = -2147024882;
      result = v3;
    }
    else
    {
      *ppEnum = 0;
      result = -2147220989;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C09A0) --------------------------------------------------------  // acclient.c:728794
HRESULT __stdcall CEnumPins::Next(CEnumPins *this, unsigned int cPins, IPin **ppPins, unsigned int *pcFetched)
{
  HRESULT result; // eax@2
  CEnumPins *v5; // esi@5
  int v6; // eax@6
  CBaseFilter *v7; // ecx@6
  int v8; // eax@7
  bool v9; // sf@7
  unsigned __int8 v10; // of@7
  CEnumPins **v11; // eax@7
  CEnumPins *v12; // ebp@9
  int v13; // eax@13
  CBaseFilter *v14; // ecx@14
  void *v15; // eax@14
  void *v16; // edi@14
  unsigned int cFetched; // [sp+8h] [bp-8h]@5
  int v18; // [sp+Ch] [bp-4h]@7

  if ( !ppPins )
    return -2147467261;
  if ( pcFetched )
  {
    *pcFetched = 0;
  }
  else if ( cPins > 1 )
  {
    return -2147024809;
  }
  v5 = this;
  cFetched = 0;
  if ( ((int (*)(void))this->m_pFilter->vfptr[1].NonDelegatingRelease)() != v5->m_Version )
  {
    v6 = ((int (*)(void))v5->m_pFilter->vfptr[1].NonDelegatingRelease)();
    v7 = v5->m_pFilter;
    v5->m_Version = v6;
    v5->m_PinCount = ((int (*)(void))v7->vfptr[2].NonDelegatingQueryInterface)();
    v5->m_Position = 0;
  }
  v8 = v5->m_PinCount - v5->m_Position;
  v18 = v8;
  v10 = __OFSUB__(cPins, v8);
  v9 = ((cPins - v8) & 0x80000000) != 0;
  this = (CEnumPins *)cPins;
  v11 = &this;
  if ( !(v9 ^ v10) )
    v11 = (CEnumPins **)&v18;
  v12 = *v11;
  if ( *v11 )
  {
    do
    {
      v13 = v5->m_Position;
      if ( v5->m_PinCount == v13 )
        break;
      v14 = v5->m_pFilter;
      v5->m_Position = v13 + 1;
      v15 = (void *)v14->vfptr[2].NonDelegatingAddRef((INonDelegatingUnknown *)v13);
      v16 = v15;
      if ( !v15 )
        return -2147220989;
      if ( !CBaseList::FindI((CBaseList *)&v5->m_PinCache.m_pFirst, v15) )
      {
        *ppPins = (IPin *)((char *)v16 + 12);
        (*(void (__stdcall **)(int))(*((_DWORD *)v16 + 3) + 4))((char *)v16 + 12);
        ++cFetched;
        ++ppPins;
        CBaseList::AddTailI((CBaseList *)&v5->m_PinCache.m_pFirst, v16);
        v12 = (CEnumPins *)((char *)v12 - 1);
      }
    }
    while ( v12 );
    if ( pcFetched )
      *pcFetched = cFetched;
    result = cPins != cFetched;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006C0AE0) --------------------------------------------------------  // acclient.c:728877
void __thiscall CEnumMediaTypes::CEnumMediaTypes(CEnumMediaTypes *this, CBasePin *pPin, CEnumMediaTypes *pEnumMediaTypes)
{
  CEnumMediaTypes *v3; // esi@1

  v3 = this;
  this->m_pPin = pPin;
  this->vfptr = (IUnknownVtbl *)&CEnumMediaTypes::vftable;
  this->m_Position = 0;
  this->m_cRef = 1;
  pPin->vfptr->AddRef((IUnknown *)&pPin->vfptr);
  if ( pEnumMediaTypes )
  {
    v3->m_Position = pEnumMediaTypes->m_Position;
    v3->m_Version = pEnumMediaTypes->m_Version;
  }
  else
  {
    v3->m_Version = ((int (*)(void))v3->m_pPin->vfptr[1].NonDelegatingAddRef)();
  }
}
// 806FAC: using guessed type __int32 (__stdcall *CEnumMediaTypes::vftable)(CEnumMediaTypes *this, _GUID *riid, void **ppv);

//----- (006C0B40) --------------------------------------------------------  // acclient.c:728900
CEnumMediaTypes *__thiscall CEnumMediaTypes::scalar_deleting_destructor(CEnumMediaTypes *this, unsigned int a2)
{
  CEnumMediaTypes *v2; // esi@1
  char *v3; // eax@1

  v2 = this;
  v3 = (char *)&this->m_pPin->vfptr;
  this->vfptr = (IUnknownVtbl *)&CEnumMediaTypes::vftable;
  (*(void (__stdcall **)(char *))(*(_DWORD *)v3 + 8))(v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 806FAC: using guessed type __int32 (__stdcall *CEnumMediaTypes::vftable)(CEnumMediaTypes *this, _GUID *riid, void **ppv);

//----- (006C0B70) --------------------------------------------------------  // acclient.c:728916
HRESULT __stdcall CEnumMediaTypes::Clone(CEnumMediaTypes *this, IEnumMediaTypes **ppEnum)
{
  HRESULT result; // eax@2
  signed int v3; // edi@3
  CEnumMediaTypes *v4; // eax@5
  IEnumMediaTypes *v5; // eax@6

  if ( ppEnum )
  {
    v3 = 0;
    if ( ((int (*)(void))this->m_pPin->vfptr[1].NonDelegatingAddRef)() == this->m_Version )
    {
      v4 = (CEnumMediaTypes *)operator new(0x14u);
      if ( v4 )
        CEnumMediaTypes::CEnumMediaTypes(v4, this->m_pPin, this);
      else
        v5 = 0;
      *ppEnum = v5;
      if ( !v5 )
        v3 = -2147024882;
      result = v3;
    }
    else
    {
      *ppEnum = 0;
      result = -2147220989;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0BE0) --------------------------------------------------------  // acclient.c:728952
void __thiscall CBasePin::CBasePin(CBasePin *this, char *pObjectName, CBaseFilter *pFilter, CCritSec *pLock, HRESULT *phr, const unsigned __int16 *pName, _PinDirection dir)
{
  CBasePin *v7; // ebp@1
  unsigned int v8; // edi@2
  void *v9; // eax@2

  v7 = this;
  CUnknown::CUnknown((CUnknown *)&this->vfptr, pObjectName, 0);
  v7->m_dir = dir;
  v7->m_pName = 0;
  v7->m_Connected = 0;
  v7->m_pLock = pLock;
  v7->m_bRunTimeError = 0;
  v7->m_bCanReconnectWhenActive = 0;
  v7->m_bTryMyTypesFirst = 0;
  v7->m_pFilter = pFilter;
  v7->m_pQSink = 0;
  v7->m_TypeVersion = 1;
  CMediaType::CMediaType(&v7->m_mt);
  LODWORD(v7->m_tStart.m_time) = 0;
  HIDWORD(v7->m_tStart.m_time) = 0;
  LODWORD(v7->m_tStop.m_time) = -1;
  HIDWORD(v7->m_tStop.m_time) = 0x7FFFFFFF;
  LODWORD(v7->m_dRate) = 0;
  HIDWORD(v7->m_dRate) = 1072693248;
  if ( pName )
  {
    v8 = 2 * (lstrlenWInternal(pName) + 1);
    v9 = operator new[](v8);
    v7->m_pName = (unsigned __int16 *)v9;
    if ( v9 )
      qmemcpy(v9, pName, v8);
  }
}

//----- (006C0CA0) --------------------------------------------------------  // acclient.c:728988
unsigned int __stdcall CBasePin::Connect(CBasePin *this, IPin *pReceivePin, _AMMediaType *pmt)
{
  unsigned int result; // eax@2
  unsigned __int16 *v4; // ebx@3
  unsigned int v5; // edi@8

  if ( pReceivePin )
  {
    v4 = this->m_pName;
    EnterCriticalSection((LPCRITICAL_SECTION)this->m_pName);
    if ( this->vfptr )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)v4);
      result = -2147220988;
    }
    else if ( !*(_DWORD *)(this->m_dir + 20) || BYTE1(this->m_Connected) )
    {
      v5 = CBasePin::AgreeMediaType((CBasePin *)((char *)this - 12), pReceivePin, (CMediaType *)pmt);
      if ( (v5 & 0x80000000) == 0 )
      {
        LeaveCriticalSection((LPCRITICAL_SECTION)v4);
        result = 0;
      }
      else
      {
        (*(void (__thiscall **)(char *))(HIDWORD(this[-1].m_tStop.m_time) + 44))((char *)&this[-1].m_tStop.m_time + 4);
        LeaveCriticalSection((LPCRITICAL_SECTION)v4);
        result = v5;
      }
    }
    else
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)v4);
      result = -2147220956;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0D40) --------------------------------------------------------  // acclient.c:729032
HRESULT __stdcall CBasePin::Disconnect(CBasePin *this)
{
  unsigned __int16 *v1; // edi@1
  HRESULT result; // eax@2
  char *v3; // esi@3
  int v4; // eax@4
  HRESULT v5; // esi@5

  v1 = this->m_pName;
  EnterCriticalSection((LPCRITICAL_SECTION)this->m_pName);
  if ( *(_DWORD *)(this->m_dir + 20) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)v1);
    result = -2147220956;
  }
  else
  {
    v3 = (char *)&this[-1].m_tStop.m_time + 4;
    if ( this->vfptr )
    {
      v4 = (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 44))(v3);
      if ( v4 >= 0 )
      {
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v3 + 6) + 8))(*((_DWORD *)v3 + 6));
        *((_DWORD *)v3 + 6) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)v1);
        result = 0;
      }
      else
      {
        v5 = v4;
        LeaveCriticalSection((LPCRITICAL_SECTION)v1);
        result = v5;
      }
    }
    else
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)v1);
      result = 1;
    }
  }
  return result;
}

//----- (006C0DD0) --------------------------------------------------------  // acclient.c:729077
HRESULT __stdcall CBasePin::EnumMediaTypes(CBasePin *this, IEnumMediaTypes **ppEnum)
{
  HRESULT result; // eax@2
  void *v3; // esi@3

  if ( ppEnum )
  {
    v3 = operator new(0x14u);
    if ( v3 )
    {
      *((_DWORD *)v3 + 2) = (char *)this - 12;
      *(_DWORD *)v3 = &CEnumMediaTypes::vftable;
      *((_DWORD *)v3 + 1) = 0;
      *((_DWORD *)v3 + 4) = 1;
      this->vfptr->NonDelegatingAddRef((INonDelegatingUnknown *)this);
      *((_DWORD *)v3 + 3) = (*(int (**)(void))(**((_DWORD **)v3 + 2) + 16))();
      *ppEnum = (IEnumMediaTypes *)v3;
      result = v3 != 0 ? 0 : 0x8007000E;
    }
    else
    {
      *ppEnum = 0;
      result = -2147024882;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}
// 806FAC: using guessed type __int32 (__stdcall *CEnumMediaTypes::vftable)(CEnumMediaTypes *this, _GUID *riid, void **ppv);

//----- (006C0E50) --------------------------------------------------------  // acclient.c:729111
void __thiscall CBaseInputPin::CBaseInputPin(CBaseInputPin *this, char *pObjectName, CBaseFilter *pFilter, CCritSec *pLock, HRESULT *phr, const unsigned __int16 *pPinName)
{
  CBaseInputPin *v6; // esi@1

  v6 = this;
  CBasePin::CBasePin((CBasePin *)&this->vfptr, pObjectName, pFilter, pLock, phr, pPinName, 0);
  v6->m_pAllocator = 0;
  v6->m_bReadOnly = 0;
  v6->m_bFlushing = 0;
  memset(&v6->m_SampleProps, 0, sizeof(v6->m_SampleProps));
}

//----- (006C0EB0) --------------------------------------------------------  // acclient.c:729124
HRESULT __stdcall CBaseFilter::EnumPins(CBaseFilter *this, IEnumPins **ppEnum)
{
  HRESULT result; // eax@2
  CEnumPins *v3; // eax@3
  IEnumPins *v4; // eax@4

  if ( ppEnum )
  {
    v3 = (CEnumPins *)operator new(0x30u);
    if ( v3 )
      CEnumPins::CEnumPins(v3, (CBaseFilter *)((char *)this - 12), 0);
    else
      v4 = 0;
    *ppEnum = v4;
    result = v4 != 0 ? 0 : 0x8007000E;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0F00) --------------------------------------------------------  // acclient.c:729148
void __thiscall CBaseFilter::CBaseFilter(CBaseFilter *this, const char *pName, IUnknown *pUnk, CCritSec *pLock, _GUID *clsid)
{
  CBaseFilter *v5; // esi@1

  v5 = this;
  CUnknown::CUnknown((CUnknown *)&this->vfptr, pName, pUnk);
  v5->m_State = 0;
  v5->m_pClock = 0;
  LODWORD(v5->m_tStart.m_time) = 0;
  HIDWORD(v5->m_tStart.m_time) = 0;
  v5->m_clsid = *clsid;
  v5->m_pName = 0;
  v5->m_pGraph = 0;
  v5->m_pSink = 0;
  v5->m_pLock = pLock;
  v5->m_PinVersion = 1;
}

