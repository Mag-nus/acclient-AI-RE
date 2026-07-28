/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : comraise
   Object     : _other\misc\comraise.obj
   Functions  : 4
   Addresses  : 005DE710 - 005DE7C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE710) --------------------------------------------------------  // acclient.c:521265
void __stdcall __noreturn _com_raise_error(int hr, IErrorInfo *perrinfo)
{
  int v2; // [sp+0h] [bp-10h]@1

  _CxxThrowException(&v2, &_TI1_AV_com_error__, &_com_error::vftable, hr, perrinfo, 0);
}
// 6B7CBC: using guessed type int __cdecl _CxxThrowException(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 7E9938: using guessed type int (__thiscall *_com_error::vftable)(void *, char);

//----- (005DE750) --------------------------------------------------------  // acclient.c:521275
void __thiscall _com_error::_com_error(_com_error *this, _com_error *that)
{
  IErrorInfo *v2; // edx@1

  this->vfptr = (_com_errorVtbl *)&_com_error::vftable;
  this->m_hresult = that->m_hresult;
  v2 = that->m_perrinfo;
  this->m_perrinfo = v2;
  this->m_pszMsg = 0;
  if ( v2 )
    v2->vfptr->AddRef((IUnknown *)v2);
}
// 7E9938: using guessed type int (__thiscall *_com_error::vftable)(void *, char);

//----- (005DE790) --------------------------------------------------------  // acclient.c:521290
void __thiscall _com_error::~_com_error(_com_error *this)
{
  _com_error *v1; // esi@1
  IErrorInfo *v2; // eax@1
  void *v3; // esi@3

  v1 = this;
  v2 = this->m_perrinfo;
  this->vfptr = (_com_errorVtbl *)&_com_error::vftable;
  if ( v2 )
    v2->vfptr->Release((IUnknown *)v2);
  v3 = v1->m_pszMsg;
  if ( v3 )
    LocalFree(v3);
}
// 7E9938: using guessed type int (__thiscall *_com_error::vftable)(void *, char);

//----- (005DE7C0) --------------------------------------------------------  // acclient.c:521308
_com_error *__thiscall _com_error::scalar_deleting_destructor(_com_error *this, unsigned int a2)
{
  _com_error *v2; // esi@1
  IErrorInfo *v3; // eax@1

  v2 = this;
  v3 = this->m_perrinfo;
  this->vfptr = (_com_errorVtbl *)&_com_error::vftable;
  if ( v3 )
    v3->vfptr->Release((IUnknown *)v3);
  if ( v2->m_pszMsg )
    LocalFree(v2->m_pszMsg);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9938: using guessed type int (__thiscall *_com_error::vftable)(void *, char);

