/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ctlutil
   Object     : ENGINE\render_base\ctlutil.obj
   Functions  : 55
   Addresses  : 006C1780 - 006C2620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C1780) --------------------------------------------------------  // acclient.c:729690
HRESULT __userpurge CBaseDispatch::GetTypeInfo@<eax>(int a1@<ebx>, CBaseDispatch *this, _GUID *riid, unsigned int itinfo, unsigned int lcid, ITypeInfo **pptinfo)
{
  ITypeInfo **v6; // ebp@1
  HRESULT result; // eax@2
  bool v8; // zf@3
  CBaseDispatch *v9; // ebx@5
  HMODULE v10; // eax@6
  void (__stdcall *v11)(); // edi@8
  FARPROC v12; // eax@8
  int (__stdcall *v13)(_DWORD, _DWORD); // eax@10
  int v14; // esi@12
  int v15; // [sp+1Ch] [bp-8h]@5

  v6 = pptinfo;
  if ( !pptinfo )
    return -2147467261;
  v8 = itinfo == 0;
  *pptinfo = 0;
  if ( !v8 )
    return -2147319765;
  v15 = a1;
  v9 = this;
  if ( this->m_pti )
    goto LABEL_14;
  v10 = LoadOLEAut32();
  if ( !v10 )
    return GetLastError() | 0x80070000;
  v11 = *(void (__stdcall **)())GetProcAddress;
  v12 = GetProcAddress(v10, "LoadRegTypeLib");
  if ( !v12 )
    return GetLastError() | 0x80070000;
  if ( ((int (__stdcall *)(GUID *, signed int, _DWORD, _GUID *, unsigned int *))v12)(
         &LIBID_QuartzTypeLib,
         1,
         0,
         riid,
         &itinfo) >= 0 )
    goto LABEL_12;
  v11();
  if ( !v13 )
    return GetLastError() | 0x80070000;
  result = v13(L"control.tlb", &this);
  if ( result < 0 )
    return result;
LABEL_12:
  v14 = ((int (__stdcall *)(CBaseDispatch *, int, CBaseDispatch *))this->m_pti[6].vfptr)(this, v15, v9);
  ((void (__stdcall *)(CBaseDispatch *))this->m_pti[2].vfptr)(this);
  if ( v14 < 0 )
    return v14;
LABEL_14:
  *v6 = v9->m_pti;
  v9->m_pti->vfptr->AddRef((IUnknown *)v9->m_pti);
  return 0;
}
// 6C1780: could not find valid save-restore pair for ebx

//----- (006C1860) --------------------------------------------------------  // acclient.c:729747
DWORD __stdcall CBaseDispatch::GetIDsOfNames(CBaseDispatch *this, _GUID *riid, unsigned __int16 **rgszNames, unsigned int cNames, unsigned int lcid, int *rgdispid)
{
  ITypeInfo *v6; // ebp@1
  DWORD result; // eax@2
  HMODULE v8; // eax@4
  void (__stdcall *v9)(); // edi@5
  FARPROC v10; // eax@5
  int (__stdcall *v11)(_DWORD, _DWORD); // eax@7
  int v12; // esi@9
  int v13; // esi@14
  int v14; // [sp+28h] [bp-Ch]@8
  int v15; // [sp+2Ch] [bp-8h]@9
  ITypeInfo *pti; // [sp+30h] [bp-4h]@1

  v6 = 0;
  if ( !&pti )
    return -2147467261;
  if ( this->m_pti )
    goto LABEL_11;
  v8 = LoadOLEAut32();
  if ( !v8 )
    goto LABEL_17;
  v9 = *(void (__stdcall **)())GetProcAddress;
  v10 = GetProcAddress(v8, "LoadRegTypeLib");
  if ( !v10 )
    goto LABEL_17;
  if ( ((int (__stdcall *)(GUID *, signed int, _DWORD, unsigned __int16 **, ITypeInfo **))v10)(
         &LIBID_QuartzTypeLib,
         1,
         0,
         rgszNames,
         &pti) >= 0 )
    goto LABEL_9;
  v9();
  if ( !v11 )
  {
LABEL_17:
    result = GetLastError() | 0x80070000;
LABEL_13:
    if ( (result & 0x80000000) != 0 )
      return result;
    goto LABEL_14;
  }
  result = v11(L"control.tlb", &v14);
  if ( (result & 0x80000000) != 0 )
    return result;
LABEL_9:
  v12 = (*(int (__stdcall **)(int, int, CBaseDispatch *))(*(_DWORD *)v14 + 24))(v14, v15, this);
  (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(v14);
  if ( v12 < 0 )
  {
    result = v12;
    goto LABEL_13;
  }
LABEL_11:
  v6 = this->m_pti;
  this->m_pti->vfptr->AddRef((IUnknown *)this->m_pti);
LABEL_14:
  v13 = ((int (__stdcall *)(ITypeInfo *, unsigned __int16 **, unsigned int, int *))v6->vfptr[3].AddRef)(
          v6,
          rgszNames,
          cNames,
          rgdispid);
  v6->vfptr->Release((IUnknown *)v6);
  return v13;
}

//----- (006C1940) --------------------------------------------------------  // acclient.c:729815
HRESULT __stdcall CMediaPosition::GetTypeInfoCount(CMediaPosition *this, unsigned int *pctinfo)
{
  HRESULT result; // eax@2

  if ( pctinfo )
  {
    *pctinfo = 1;
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C1960) --------------------------------------------------------  // acclient.c:729832
HRESULT __userpurge CMediaPosition::GetTypeInfo@<eax>(int a1@<ebx>, CMediaPosition *this, unsigned int itinfo, unsigned int lcid, ITypeInfo **pptinfo)
{
  return CBaseDispatch::GetTypeInfo(
           a1,
           &this->m_basedisp,
           &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770,
           itinfo,
           lcid,
           pptinfo);
}

//----- (006C1990) --------------------------------------------------------  // acclient.c:729844
DWORD __stdcall CMediaPosition::GetIDsOfNames(CMediaPosition *this, _GUID *riid, unsigned __int16 **rgszNames, unsigned int cNames, unsigned int lcid, int *rgdispid)
{
  return CBaseDispatch::GetIDsOfNames(
           &this->m_basedisp,
           &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770,
           rgszNames,
           cNames,
           lcid,
           rgdispid);
}

//----- (006C19B0) --------------------------------------------------------  // acclient.c:729856
HRESULT __stdcall CMediaPosition::Invoke(CMediaPosition *this, int dispidMember, _GUID *riid, unsigned int lcid, unsigned __int16 wFlags, tagDISPPARAMS *pdispparams, tagVARIANT *pvarResult, tagEXCEPINFO *pexcepinfo, unsigned int *puArgErr)
{
  HRESULT result; // eax@2
  int v10; // esi@4

  if ( !memcmp(&GUID_NULL, riid, 0x10u) )
  {
    result = ((int (__stdcall *)(CMediaPosition *, _DWORD, unsigned int, _GUID **))this->vfptr[1].AddRef)(
               this,
               0,
               lcid,
               &riid);
    if ( result >= 0 )
    {
      v10 = (*(int (__stdcall **)(_GUID *, CMediaPosition *, int, _DWORD, tagDISPPARAMS *, tagVARIANT *, tagEXCEPINFO *, unsigned int *))(riid->Data1 + 44))(
              riid,
              this,
              dispidMember,
              wFlags,
              pdispparams,
              pvarResult,
              pexcepinfo,
              puArgErr);
      (*(void (__stdcall **)(_GUID *))(riid->Data1 + 8))(riid);
      result = v10;
    }
  }
  else
  {
    result = -2147352575;
  }
  return result;
}

//----- (006C1A30) --------------------------------------------------------  // acclient.c:729891
void __thiscall CPosPassThru::~CPosPassThru(CPosPassThru *this)
{
  char *v1; // eax@2
  int v2; // esi@4
  int v3; // eax@4

  if ( this == (CPosPassThru *)8 )
    v1 = 0;
  else
    v1 = (char *)&this[-1].m_pPin;
  v2 = (int)(v1 + 4);
  v3 = *((_DWORD *)v1 + 4);
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  if ( v2 != 4 && v2 )
    CBaseObject::~CBaseObject();
  else
    CBaseObject::~CBaseObject();
}

//----- (006C1A70) --------------------------------------------------------  // acclient.c:729912
HRESULT __stdcall CPosPassThru::NonDelegatingQueryInterface(CPosPassThru *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@2

  if ( ppv )
  {
    *ppv = 0;
    if ( !memcmp(riid, &IID_IMediaSeeking, 0x10u) )
    {
      result = GetInterface((IUnknown *)&this[-1].m_basedisp, ppv);
    }
    else if ( !memcmp(riid, &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770, 0x10u) )
    {
      result = GetInterface((IUnknown *)&this[-1].m_pPin, ppv);
    }
    else
    {
      result = CUnknown::NonDelegatingQueryInterface((CUnknown *)this, riid, ppv);
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C1AF0) --------------------------------------------------------  // acclient.c:729940
HRESULT __thiscall CPosPassThru::GetPeer(CPosPassThru *this, IMediaPosition **ppMP)
{
  IMediaPosition **v2; // edi@1
  int v3; // esi@2
  HRESULT result; // eax@3
  IMediaPosition *pMP; // [sp+18h] [bp-4h]@1

  pMP = (IMediaPosition *)this;
  v2 = ppMP;
  *ppMP = 0;
  if ( ((int (__stdcall *)(IPin *, IMediaPosition ***))this->m_pPin->vfptr[2].QueryInterface)(this->m_pPin, &ppMP) >= 0
    && (v3 = ((int (__stdcall *)(IMediaPosition **, GUID *, IMediaPosition **))(*ppMP)->vfptr)(
               ppMP,
               &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770,
               &pMP),
        ((void (__stdcall *)(IMediaPosition **))(*ppMP)[2].vfptr)(ppMP),
        v3 >= 0) )
  {
    *v2 = pMP;
    result = 0;
  }
  else
  {
    result = -2147467263;
  }
  return result;
}

//----- (006C1B50) --------------------------------------------------------  // acclient.c:729969
HRESULT __thiscall CPosPassThru::GetPeerSeeking(CPosPassThru *this, IMediaSeeking **ppMS)
{
  IMediaSeeking **v2; // edi@1
  int v3; // esi@2
  HRESULT result; // eax@3
  IMediaSeeking *pMS; // [sp+18h] [bp-4h]@1

  pMS = (IMediaSeeking *)this;
  v2 = ppMS;
  *ppMS = 0;
  if ( ((int (__stdcall *)(IPin *, IMediaSeeking ***))this->m_pPin->vfptr[2].QueryInterface)(this->m_pPin, &ppMS) >= 0
    && (v3 = ((int (__stdcall *)(IMediaSeeking **, GUID *, IMediaSeeking **))(*ppMS)->vfptr)(
               ppMS,
               &IID_IMediaSeeking,
               &pMS),
        ((void (__stdcall *)(IMediaSeeking **))(*ppMS)[2].vfptr)(ppMS),
        v3 >= 0) )
  {
    *v2 = pMS;
    result = 0;
  }
  else
  {
    result = -2147467263;
  }
  return result;
}

//----- (006C1BB0) --------------------------------------------------------  // acclient.c:729998
HRESULT __stdcall CPosPassThru::GetCapabilities(CPosPassThru *this, unsigned int *pCaps)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, unsigned int *))this->vfptr[1].QueryInterface)(this, pCaps);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1BF0) --------------------------------------------------------  // acclient.c:730016
HRESULT __stdcall CPosPassThru::CheckCapabilities(CPosPassThru *this, unsigned int *pCaps)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, unsigned int *))this->vfptr[1].AddRef)(this, pCaps);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1C30) --------------------------------------------------------  // acclient.c:730034
HRESULT __stdcall CPosPassThru::IsFormatSupported(CPosPassThru *this, _GUID *pFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _GUID *))this->vfptr[1].Release)(this, pFormat);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1C70) --------------------------------------------------------  // acclient.c:730052
HRESULT __stdcall CPosPassThru::QueryPreferredFormat(CPosPassThru *this, _GUID *pFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _GUID *))this->vfptr[2].QueryInterface)(this, pFormat);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1CB0) --------------------------------------------------------  // acclient.c:730070
HRESULT __stdcall CPosPassThru::SetTimeFormat(CPosPassThru *this, _GUID *pFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _GUID *))this->vfptr[3].QueryInterface)(this, pFormat);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1CF0) --------------------------------------------------------  // acclient.c:730088
HRESULT __stdcall CPosPassThru::GetTimeFormatA(CPosPassThru *this, _GUID *pFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _GUID *))this->vfptr[2].AddRef)(this, pFormat);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1D30) --------------------------------------------------------  // acclient.c:730106
HRESULT __stdcall CPosPassThru::IsUsingTimeFormat(CPosPassThru *this, _GUID *pFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _GUID *))this->vfptr[2].Release)(this, pFormat);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1D70) --------------------------------------------------------  // acclient.c:730124
HRESULT __stdcall CPosPassThru::ConvertTimeFormat(CPosPassThru *this, __int64 *pTarget, _GUID *pTargetFormat, __int64 Source, _GUID *pSourceFormat)
{
  HRESULT result; // eax@1
  CPosPassThru *v6; // esi@2
  int v7; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v6 = this;
    v7 = ((int (__stdcall *)(CPosPassThru *, __int64 *, _GUID *, _DWORD, _DWORD, _GUID *))this->vfptr[4].AddRef)(
           this,
           pTarget,
           pTargetFormat,
           Source,
           HIDWORD(Source),
           pSourceFormat);
    v6->vfptr->Release((IUnknown *)v6);
    result = v7;
  }
  return result;
}

//----- (006C1DC0) --------------------------------------------------------  // acclient.c:730148
HRESULT __stdcall CPosPassThru::SetPositions(CPosPassThru *this, __int64 *pCurrent, unsigned int CurrentFlags, __int64 *pStop, unsigned int StopFlags)
{
  HRESULT result; // eax@1
  CPosPassThru *v6; // esi@2
  int v7; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v6 = this;
    v7 = ((int (__stdcall *)(CPosPassThru *, __int64 *, unsigned int, __int64 *, unsigned int))this->vfptr[4].Release)(
           this,
           pCurrent,
           CurrentFlags,
           pStop,
           StopFlags);
    v6->vfptr->Release((IUnknown *)v6);
    result = v7;
  }
  return result;
}

//----- (006C1E10) --------------------------------------------------------  // acclient.c:730171
HRESULT __stdcall CPosPassThru::GetPositions(CPosPassThru *this, __int64 *pCurrent, __int64 *pStop)
{
  HRESULT result; // eax@1
  CPosPassThru *v4; // esi@2
  int v5; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v4 = this;
    v5 = this->vfptr[5].QueryInterface((IUnknown *)this, (_GUID *)pCurrent, (void **)pStop);
    v4->vfptr->Release((IUnknown *)v4);
    result = v5;
  }
  return result;
}

//----- (006C1E50) --------------------------------------------------------  // acclient.c:730189
HRESULT __stdcall CPosPassThru::GetAvailable(CPosPassThru *this, __int64 *pEarliest, __int64 *pLatest)
{
  HRESULT result; // eax@1
  CPosPassThru *v4; // esi@2
  int v5; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v4 = this;
    v5 = ((int (__stdcall *)(CPosPassThru *, __int64 *, __int64 *))this->vfptr[5].AddRef)(this, pEarliest, pLatest);
    v4->vfptr->Release((IUnknown *)v4);
    result = v5;
  }
  return result;
}

//----- (006C1E90) --------------------------------------------------------  // acclient.c:730207
HRESULT __stdcall CPosPassThru::GetRate(CPosPassThru *this, long double *pdRate)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[6].QueryInterface)(this, pdRate);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1ED0) --------------------------------------------------------  // acclient.c:730225
HRESULT __stdcall CPosPassThru::SetRate(CPosPassThru *this, long double dRate)
{
  HRESULT result; // eax@2
  CPosPassThru *v3; // esi@4
  int v4; // edi@4

  if ( 0.0 == dRate )
  {
    result = -2147024809;
  }
  else
  {
    result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
    if ( result >= 0 )
    {
      v3 = this;
      v4 = ((int (__stdcall *)(CPosPassThru *, _DWORD, _DWORD))this->vfptr[5].Release)(
             this,
             LODWORD(dRate),
             HIDWORD(dRate));
      v3->vfptr->Release((IUnknown *)v3);
      result = v4;
    }
  }
  return result;
}

//----- (006C1F20) --------------------------------------------------------  // acclient.c:730253
HRESULT __stdcall CPosPassThru::get_Duration(CPosPassThru *this, long double *plength)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[2].AddRef)(this, plength);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1F60) --------------------------------------------------------  // acclient.c:730271
HRESULT __stdcall CPosPassThru::get_CurrentPosition(CPosPassThru *this, long double *pllTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[3].QueryInterface)(this, pllTime);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1FA0) --------------------------------------------------------  // acclient.c:730289
HRESULT __stdcall CPosPassThru::put_CurrentPosition(CPosPassThru *this, long double llTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _DWORD, _DWORD))this->vfptr[2].Release)(
           this,
           LODWORD(llTime),
           HIDWORD(llTime));
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C1FE0) --------------------------------------------------------  // acclient.c:730310
HRESULT __stdcall CPosPassThru::get_StopTime(CPosPassThru *this, long double *pllTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[3].AddRef)(this, pllTime);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C2020) --------------------------------------------------------  // acclient.c:730328
HRESULT __stdcall CPosPassThru::put_StopTime(CPosPassThru *this, long double llTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _DWORD, _DWORD))this->vfptr[3].Release)(
           this,
           LODWORD(llTime),
           HIDWORD(llTime));
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C2060) --------------------------------------------------------  // acclient.c:730349
HRESULT __stdcall CPosPassThru::get_PrerollTime(CPosPassThru *this, long double *pllTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[4].QueryInterface)(this, pllTime);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C20A0) --------------------------------------------------------  // acclient.c:730367
HRESULT __stdcall CPosPassThru::put_PrerollTime(CPosPassThru *this, long double llTime)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, _DWORD, _DWORD))this->vfptr[4].AddRef)(
           this,
           LODWORD(llTime),
           HIDWORD(llTime));
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C20E0) --------------------------------------------------------  // acclient.c:730388
HRESULT __stdcall CPosPassThru::get_Rate(CPosPassThru *this, long double *pdRate)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, long double *))this->vfptr[5].QueryInterface)(this, pdRate);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C2120) --------------------------------------------------------  // acclient.c:730406
HRESULT __stdcall CPosPassThru::put_Rate(CPosPassThru *this, long double dRate)
{
  HRESULT result; // eax@2
  CPosPassThru *v3; // esi@4
  int v4; // edi@4

  if ( 0.0 == dRate )
  {
    result = -2147024809;
  }
  else
  {
    result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
    if ( result >= 0 )
    {
      v3 = this;
      v4 = ((int (__stdcall *)(CPosPassThru *, _DWORD, _DWORD))this->vfptr[4].Release)(
             this,
             LODWORD(dRate),
             HIDWORD(dRate));
      v3->vfptr->Release((IUnknown *)v3);
      result = v4;
    }
  }
  return result;
}

//----- (006C2180) --------------------------------------------------------  // acclient.c:730434
HRESULT __stdcall CPosPassThru::CanSeekForward(CPosPassThru *this, int *pCanSeekForward)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, int *))this->vfptr[5].AddRef)(this, pCanSeekForward);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C21C0) --------------------------------------------------------  // acclient.c:730452
HRESULT __stdcall CPosPassThru::CanSeekBackward(CPosPassThru *this, int *pCanSeekBackward)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  int v4; // edi@2

  result = CPosPassThru::GetPeer((CPosPassThru *)((char *)this - 4), (IMediaPosition **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = ((int (__stdcall *)(CPosPassThru *, int *))this->vfptr[5].Release)(this, pCanSeekBackward);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C2200) --------------------------------------------------------  // acclient.c:730470
HRESULT __thiscall CRendererPosPassThru::RegisterMediaTime(CRendererPosPassThru *this, IMediaSample *pMediaSample)
{
  CRendererPosPassThru *v2; // esi@1
  _RTL_CRITICAL_SECTION *v3; // edi@1
  int v4; // ebx@1
  HRESULT result; // eax@2
  int v6; // ecx@3
  int v7; // edx@3
  int v8; // eax@3
  __int64 StartMedia; // [sp+Ch] [bp-10h]@1
  __int64 EndMedia; // [sp+14h] [bp-8h]@1

  v2 = this;
  v3 = &this->m_PositionLock.m_CritSec;
  EnterCriticalSection(&this->m_PositionLock.m_CritSec);
  v4 = ((int (__stdcall *)(IMediaSample *, __int64 *, __int64 *))pMediaSample->vfptr[1].Release)(
         pMediaSample,
         &StartMedia,
         &EndMedia);
  if ( v4 >= 0 )
  {
    v6 = HIDWORD(StartMedia);
    v7 = EndMedia;
    LODWORD(v2->m_StartMedia) = StartMedia;
    v8 = HIDWORD(EndMedia);
    HIDWORD(v2->m_StartMedia) = v6;
    LODWORD(v2->m_EndMedia) = v7;
    HIDWORD(v2->m_EndMedia) = v8;
    v2->m_bReset = 0;
    LeaveCriticalSection(v3);
    result = 0;
  }
  else
  {
    LeaveCriticalSection(v3);
    result = v4;
  }
  return result;
}

//----- (006C2280) --------------------------------------------------------  // acclient.c:730511
HRESULT __thiscall CRendererPosPassThru::GetMediaTime(CRendererPosPassThru *this, __int64 *pStartTime, __int64 *pEndTime)
{
  CRendererPosPassThru *v3; // esi@1
  _RTL_CRITICAL_SECTION *v4; // ebx@1
  HRESULT result; // eax@2
  int v6; // edi@3

  v3 = this;
  v4 = &this->m_PositionLock.m_CritSec;
  EnterCriticalSection(&this->m_PositionLock.m_CritSec);
  if ( v3->m_bReset == 1 )
  {
    LeaveCriticalSection(v4);
    result = -2147467259;
  }
  else
  {
    v6 = ((int (__stdcall *)(CRendererPosPassThru *, __int64 *, _DWORD, _DWORD, _DWORD, const GUID *))v3->vfptr[4].AddRef)(
           v3,
           pStartTime,
           0,
           LODWORD(v3->m_StartMedia),
           HIDWORD(v3->m_StartMedia),
           &TIME_FORMAT_MEDIA_TIME);
    if ( pEndTime )
    {
      if ( v6 >= 0 )
        v6 = ((int (__stdcall *)(CRendererPosPassThru *, __int64 *, _DWORD, _DWORD, _DWORD, const GUID *))v3->vfptr[4].AddRef)(
               v3,
               pEndTime,
               0,
               LODWORD(v3->m_EndMedia),
               HIDWORD(v3->m_EndMedia),
               &TIME_FORMAT_MEDIA_TIME);
    }
    LeaveCriticalSection(v4);
    result = v6;
  }
  return result;
}

//----- (006C2300) --------------------------------------------------------  // acclient.c:730553
HRESULT __thiscall CRendererPosPassThru::ResetMediaTime(CRendererPosPassThru *this)
{
  CRendererPosPassThru *v1; // esi@1
  _RTL_CRITICAL_SECTION *v2; // edi@1

  v1 = this;
  v2 = &this->m_PositionLock.m_CritSec;
  EnterCriticalSection(&this->m_PositionLock.m_CritSec);
  LODWORD(v1->m_StartMedia) = 0;
  HIDWORD(v1->m_StartMedia) = 0;
  LODWORD(v1->m_EndMedia) = 0;
  HIDWORD(v1->m_EndMedia) = 0;
  v1->m_bReset = 1;
  LeaveCriticalSection(v2);
  return 0;
}

//----- (006C2330) --------------------------------------------------------  // acclient.c:730571
HRESULT __thiscall CRendererPosPassThru::EOS(CRendererPosPassThru *this)
{
  CRendererPosPassThru *v1; // esi@1
  HRESULT result; // eax@2
  int v3; // ebx@3
  __int64 v4; // kr00_8@4
  __int64 llStop; // [sp+8h] [bp-8h]@3

  v1 = this;
  if ( this->m_bReset == 1 )
  {
    result = -2147467259;
  }
  else
  {
    v3 = ((int (__stdcall *)(CRendererPosPassThru *, __int64 *))this->vfptr[3].Release)(this, &llStop);
    if ( v3 >= 0 )
    {
      EnterCriticalSection(&v1->m_PositionLock.m_CritSec);
      v4 = llStop;
      v1->m_EndMedia = llStop;
      v1->m_StartMedia = v4;
      LeaveCriticalSection(&v1->m_PositionLock.m_CritSec);
    }
    result = v3;
  }
  return result;
}

//----- (006C2390) --------------------------------------------------------  // acclient.c:730601
HRESULT __stdcall vcall(IMediaSeeking *this, __int64 *a2)
{
  return ((int (__stdcall *)(IMediaSeeking *, __int64 *))this->vfptr[3].AddRef)(this, a2);
}

//----- (006C23A0) --------------------------------------------------------  // acclient.c:730607
HRESULT __stdcall vcall(IMediaSeeking *this, __int64 *a2)
{
  return ((int (__stdcall *)(IMediaSeeking *, __int64 *))this->vfptr[6].AddRef)(this, a2);
}

//----- (006C23B0) --------------------------------------------------------  // acclient.c:730613
HRESULT __stdcall vcall(IMediaSeeking *this, __int64 *a2)
{
  return ((int (__stdcall *)(IMediaSeeking *, __int64 *))this->vfptr[3].Release)(this, a2);
}

//----- (006C23C0) --------------------------------------------------------  // acclient.c:730619
HRESULT __stdcall vcall(IMediaSeeking *this, __int64 *a2)
{
  return ((int (__stdcall *)(IMediaSeeking *, __int64 *))this->vfptr[4].QueryInterface)(this, a2);
}

//----- (006C23D0) --------------------------------------------------------  // acclient.c:730625
HRESULT __stdcall CPosPassThru::GetCurrentPosition(CPosPassThru *this, __int64 *pCurrent)
{
  CPosPassThru *v2; // esi@1
  __int64 *v3; // edi@1
  HRESULT result; // eax@2
  HRESULT v5; // esi@3
  __int64 *v6; // ST04_4@4
  CPosPassThru *v7; // edi@4

  v2 = this;
  v3 = pCurrent;
  if ( ((int (__thiscall *)(CPosPassThru *, __int64 *, _DWORD))this->vfptr[6].Release)(this, pCurrent, 0) < 0 )
  {
    v5 = CPosPassThru::GetPeerSeeking(v2, (IMediaSeeking **)&this);
    if ( v5 >= 0 )
    {
      v6 = v3;
      v7 = this;
      v5 = vcall((IMediaSeeking *)&this->vfptr, v6);
      v7->vfptr->Release((IUnknown *)v7);
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006C2420) --------------------------------------------------------  // acclient.c:730656
HRESULT __stdcall CPosPassThru::GetStopPosition(CPosPassThru *this, __int64 *pStop)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  HRESULT v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = vcall((IMediaSeeking *)&this->vfptr, pStop);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C2460) --------------------------------------------------------  // acclient.c:730674
HRESULT __stdcall CPosPassThru::GetDuration(CPosPassThru *this, __int64 *pDuration)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  HRESULT v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = vcall((IMediaSeeking *)&this->vfptr, pDuration);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C24A0) --------------------------------------------------------  // acclient.c:730692
HRESULT __stdcall CPosPassThru::GetPreroll(CPosPassThru *this, __int64 *pllPreroll)
{
  HRESULT result; // eax@1
  CPosPassThru *v3; // esi@2
  HRESULT v4; // edi@2

  result = CPosPassThru::GetPeerSeeking(this, (IMediaSeeking **)&this);
  if ( result >= 0 )
  {
    v3 = this;
    v4 = vcall((IMediaSeeking *)&this->vfptr, pllPreroll);
    v3->vfptr->Release((IUnknown *)v3);
    result = v4;
  }
  return result;
}

//----- (006C24E0) --------------------------------------------------------  // acclient.c:730710
HRESULT __stdcall CPosPassThru::QueryInterface(CPosPassThru *this, _GUID *riid, void **ppv)
{
  return this->m_pUnknown->vfptr->QueryInterface(this->m_pUnknown, riid, ppv);
}

//----- (006C24F0) --------------------------------------------------------  // acclient.c:730716
int __stdcall CPosPassThru::AddRef(CPosPassThru *this)
{
  return this->m_pUnknown->vfptr->AddRef(this->m_pUnknown);
}

//----- (006C2500) --------------------------------------------------------  // acclient.c:730722
int __stdcall CPosPassThru::Release(CPosPassThru *this)
{
  return this->m_pUnknown->vfptr->Release(this->m_pUnknown);
}

//----- (006C2510) --------------------------------------------------------  // acclient.c:730728
HRESULT __stdcall CPosPassThru::QueryInterface(CPosPassThru *this, _GUID *a2, void **a3)
{
  return CPosPassThru::QueryInterface((CPosPassThru *)((char *)this - 4), a2, a3);
}

//----- (006C2520) --------------------------------------------------------  // acclient.c:730734
int __stdcall CPosPassThru::AddRef(CPosPassThru *this)
{
  return CPosPassThru::AddRef((CPosPassThru *)((char *)this - 4));
}

//----- (006C2530) --------------------------------------------------------  // acclient.c:730740
int __stdcall CPosPassThru::Release(CPosPassThru *this)
{
  return CPosPassThru::Release((CPosPassThru *)((char *)this - 4));
}

//----- (006C2540) --------------------------------------------------------  // acclient.c:730746
int __thiscall CPosPassThru::vector_deleting_destructor(void *this, char a2)
{
  void *v2; // edi@1
  int v3; // eax@2
  int v4; // eax@4
  int result; // eax@6

  v2 = this;
  if ( this == (void *)8 )
    v3 = 0;
  else
    v3 = (int)((char *)this - 4);
  v4 = *(_DWORD *)(v3 + 16);
  if ( v4 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
  CBaseObject::~CBaseObject();
  result = (int)((char *)v2 - 8);
  if ( a2 & 1 )
  {
    operator delete((char *)v2 - 8);
    result = (int)((char *)v2 - 8);
  }
  return result;
}

//----- (006C25A0) --------------------------------------------------------  // acclient.c:730772
void __thiscall CRendererPosPassThru::CRendererPosPassThru(CRendererPosPassThru *this, const char *pName, IUnknown *pUnk, HRESULT *phr, IPin *pPin)
{
  CRendererPosPassThru *v5; // esi@1

  v5 = this;
  CUnknown::CUnknown((CUnknown *)&this->vfptr, pName, pUnk);
  v5->m_basedisp.m_pti = 0;
  v5->vfptr = (IUnknownVtbl *)&CPosPassThru::vftable;
  v5->vfptr = (IUnknownVtbl *)&CPosPassThru::vftable;
  v5->vfptr = (INonDelegatingUnknownVtbl *)&CPosPassThru::vftable;
  v5->m_pPin = pPin;
  if ( !pPin )
    *phr = -2147467261;
  v5->vfptr = (IUnknownVtbl *)&CRendererPosPassThru::vftable;
  v5->vfptr = (IUnknownVtbl *)&CPosPassThru::vftable;
  v5->vfptr = (INonDelegatingUnknownVtbl *)&CRendererPosPassThru::vftable;
  InitializeCriticalSection(&v5->m_PositionLock.m_CritSec);
  LODWORD(v5->m_StartMedia) = 0;
  HIDWORD(v5->m_StartMedia) = 0;
  LODWORD(v5->m_EndMedia) = 0;
  HIDWORD(v5->m_EndMedia) = 0;
  v5->m_bReset = 1;
}
// 807028: using guessed type __int32 (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv);
// 807038: using guessed type __int32 (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv);
// 80708C: using guessed type __int32 (__stdcall *CRendererPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv);
// 8070A0: using guessed type int (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, int, int);
// 8070E8: using guessed type __int32 (__stdcall *CRendererPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv);

//----- (006C2620) --------------------------------------------------------  // acclient.c:730802
CBaseDispatch *__thiscall CRendererPosPassThru::scalar_deleting_destructor(CPosPassThru *this, char a2)
{
  CPosPassThru *v2; // esi@1

  v2 = this;
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_basedisp);
  CPosPassThru::~CPosPassThru(v2);
  if ( a2 & 1 )
    operator delete(&v2[-1].m_basedisp);
  return &v2[-1].m_basedisp;
}

