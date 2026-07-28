/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : mtype
   Object     : ENGINE\render_base\mtype.obj
   Functions  : 8
   Addresses  : 006C2800 - 006C2A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C2800) --------------------------------------------------------  // acclient.c:730980
void __thiscall CMediaType::InitMediaType(CMediaType *this)
{
  memset(this, 0, 0x48u);
  this->lSampleSize = 1;
  this->bFixedSizeSamples = 1;
}

//----- (006C2820) --------------------------------------------------------  // acclient.c:730988
int __thiscall CMediaType::IsPartiallySpecified(CMediaType *this)
{
  CMediaType *v1; // eax@1
  const void *v2; // esi@2
  int result; // eax@2

  v1 = this;
  if ( !memcmp(this, &GUID_NULL, 0x10u) || (v2 = &v1->formattype, result = 0, !memcmp(v2, &GUID_NULL, 0x10u)) )
    result = 1;
  return result;
}

//----- (006C2860) --------------------------------------------------------  // acclient.c:731001
int __thiscall CMediaType::MatchesPartial(CMediaType *this, CMediaType *ppartial)
{
  CMediaType *v2; // edx@1
  int result; // eax@3
  unsigned int v4; // ecx@9

  v2 = this;
  if ( !memcmp(ppartial, &GUID_NULL, 0x10u) || !memcmp(v2, ppartial, 0x10u) )
  {
    result = 0;
    if ( !memcmp(&ppartial->subtype, &GUID_NULL, 0x10u) || !memcmp(&v2->subtype, &ppartial->subtype, 0x10u) )
    {
      if ( !memcmp(&ppartial->formattype, &GUID_NULL, 0x10u)
        || !memcmp(&v2->formattype, &ppartial->formattype, 0x10u)
        && (v4 = v2->cbFormat, v4 == ppartial->cbFormat)
        && (!v4 || !memcmp(v2->pbFormat, ppartial->pbFormat, v4)) )
        result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006C2910) --------------------------------------------------------  // acclient.c:731028
HRESULT __stdcall CopyMediaType(_AMMediaType *pmtTarget, _AMMediaType *pmtSource)
{
  char *v2; // eax@2
  IUnknown *v4; // ebx@5

  qmemcpy(pmtTarget, pmtSource, 0x48u);
  if ( pmtSource->cbFormat )
  {
    v2 = (char *)CoTaskMemAlloc(pmtSource->cbFormat);
    pmtTarget->pbFormat = v2;
    if ( !v2 )
    {
      pmtTarget->cbFormat = 0;
      return -2147024882;
    }
    qmemcpy(v2, pmtSource->pbFormat, pmtTarget->cbFormat);
  }
  v4 = pmtTarget->pUnk;
  if ( v4 )
    v4->vfptr->AddRef(v4);
  return 0;
}

//----- (006C2980) --------------------------------------------------------  // acclient.c:731052
void __thiscall CMediaType::~CMediaType(CMediaType *this)
{
  CMediaType *v1; // esi@1
  IUnknown *v2; // eax@3

  v1 = this;
  if ( this->cbFormat )
  {
    CoTaskMemFree(this->pbFormat);
    v1->cbFormat = 0;
    v1->pbFormat = 0;
  }
  v2 = v1->pUnk;
  if ( v2 )
  {
    v2->vfptr->Release(v1->pUnk);
    v1->pUnk = 0;
  }
}

//----- (006C29C0) --------------------------------------------------------  // acclient.c:731073
void __thiscall CMediaType::CMediaType(CMediaType *this)
{
  memset(this, 0, 0x48u);
  this->lSampleSize = 1;
  this->bFixedSizeSamples = 1;
}

//----- (006C29E0) --------------------------------------------------------  // acclient.c:731081
HRESULT __thiscall CMediaType::Set(CMediaType *this, _AMMediaType *rt)
{
  CMediaType *v2; // esi@1
  IUnknown *v3; // eax@4
  HRESULT result; // eax@7

  v2 = this;
  if ( (CMediaType *)rt == this )
    goto LABEL_11;
  if ( this->cbFormat )
  {
    CoTaskMemFree(this->pbFormat);
    v2->cbFormat = 0;
    v2->pbFormat = 0;
  }
  v3 = v2->pUnk;
  if ( v3 )
  {
    v3->vfptr->Release(v2->pUnk);
    v2->pUnk = 0;
  }
  if ( CopyMediaType((_AMMediaType *)&v2->majortype, rt) >= 0 )
LABEL_11:
    result = 0;
  else
    result = -2147024882;
  return result;
}

//----- (006C2A40) --------------------------------------------------------  // acclient.c:731111
void __stdcall DeleteMediaType(_AMMediaType *pmt)
{
  IUnknown *v1; // eax@4

  if ( pmt )
  {
    if ( pmt->cbFormat )
    {
      CoTaskMemFree(pmt->pbFormat);
      pmt->cbFormat = 0;
      pmt->pbFormat = 0;
    }
    v1 = pmt->pUnk;
    if ( v1 )
    {
      v1->vfptr->Release(pmt->pUnk);
      pmt->pUnk = 0;
    }
    CoTaskMemFree(pmt);
  }
}

