/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : combase
   Object     : ENGINE\render_base\combase.obj
   Functions  : 7
   Addresses  : 006C0F60 - 006C1080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C0F60) --------------------------------------------------------  // acclient.c:729167
void CBaseObject::~CBaseObject()
{
  if ( !InterlockedDecrement(&CBaseObject::m_cObjects) )
  {
    if ( hlibOLEAut32 )
    {
      FreeLibrary(hlibOLEAut32);
      hlibOLEAut32 = 0;
    }
  }
}

//----- (006C0F90) --------------------------------------------------------  // acclient.c:729180
HINSTANCE__ *__cdecl LoadOLEAut32()
{
  HINSTANCE__ *result; // eax@1

  result = hlibOLEAut32;
  if ( !hlibOLEAut32 )
  {
    result = LoadLibraryA("OleAut32.dll");
    hlibOLEAut32 = result;
  }
  return result;
}

//----- (006C0FB0) --------------------------------------------------------  // acclient.c:729194
HRESULT __stdcall GetInterface(IUnknown *pUnk, void **ppv)
{
  HRESULT result; // eax@2

  if ( ppv )
  {
    *ppv = pUnk;
    pUnk->vfptr->AddRef(pUnk);
    result = 0;
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006C0FE0) --------------------------------------------------------  // acclient.c:729212
void __thiscall CUnknown::CUnknown(CUnknown *this, const char *pName, IUnknown *pUnk)
{
  CUnknown *v3; // esi@1
  IUnknown *v4; // eax@1

  v3 = this;
  InterlockedIncrement(&CBaseObject::m_cObjects);
  v4 = pUnk;
  if ( !pUnk )
    v4 = (IUnknown *)v3;
  v3->m_pUnknown = v4;
  v3->m_cRef = 0;
}

//----- (006C1010) --------------------------------------------------------  // acclient.c:729227
HRESULT __stdcall CUnknown::NonDelegatingQueryInterface(CUnknown *this, _GUID *riid, void **ppv)
{
  HRESULT result; // eax@2

  if ( ppv )
  {
    if ( !memcmp(riid, &_GUID_00000000_0000_0000_c000_000000000046, 0x10u) )
    {
      *ppv = this;
      this->vfptr->NonDelegatingAddRef((INonDelegatingUnknown *)this);
      result = 0;
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

//----- (006C1060) --------------------------------------------------------  // acclient.c:729253
int __stdcall CUnknown::NonDelegatingAddRef(CUnknown *this)
{
  volatile int result; // eax@1

  InterlockedIncrement(&this->m_cRef);
  result = this->m_cRef;
  if ( (unsigned int)result <= 1 )
    result = 1;
  return result;
}

//----- (006C1080) --------------------------------------------------------  // acclient.c:729265
signed int __stdcall CUnknown::NonDelegatingRelease(CUnknown *this)
{
  char *v1; // esi@1
  signed int result; // eax@2

  v1 = (char *)&this->m_cRef;
  if ( InterlockedDecrement(&this->m_cRef) )
  {
    result = *(_DWORD *)v1;
    if ( *(_DWORD *)v1 <= 1u )
      result = 1;
  }
  else
  {
    ++*(_DWORD *)v1;
    ((void (__thiscall *)(_DWORD, _DWORD))this->vfptr[1].NonDelegatingQueryInterface)(this, 1);
    result = 0;
  }
  return result;
}

