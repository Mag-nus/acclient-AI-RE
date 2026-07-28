/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CNetKeyExch
   Object     : PORTAL\clinet\CNetKeyExch.obj
   Functions  : 6
   Addresses  : 005498E0 - 005499E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005498E0) --------------------------------------------------------  // acclient.c:377088
void __thiscall NetKeyExch::SetPrivateRandom(NetKeyExch *this, AC1Legacy::vlong *rnum)
{
  NetKeyExch *v2; // esi@1

  v2 = this;
  AC1Legacy::vlong::operator=(&this->rnum_, rnum);
  v2->fInitialized_ = 1;
}

//----- (00549900) --------------------------------------------------------  // acclient.c:377098
unsigned int __thiscall NetKeyExch::Pack(NetKeyExch *this, void **addr, unsigned int size)
{
  NetKeyExch *v3; // ebp@1
  PackObjVtbl *v4; // eax@1
  char *v5; // edi@1
  unsigned int v6; // esi@1
  int v8; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = this->rnum_.vfptr;
  v5 = (char *)&this->rnum_;
  v8 = 0;
  v6 = ((int (__thiscall *)(AC1Legacy::vlong *, int *, _DWORD))v4->Pack)(&this->rnum_, &v8, 0) + 4;
  if ( size >= v6 )
  {
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
    *(_DWORD *)*addr = v3->fInitialized_;
    *addr = (char *)*addr + 4;
  }
  return v6;
}

//----- (00549950) --------------------------------------------------------  // acclient.c:377121
int __thiscall NetKeyExch::UnPack(NetKeyExch *this, void **addr, unsigned int size)
{
  NetKeyExch *v3; // edi@1
  int result; // eax@1

  v3 = this;
  result = ((int (__thiscall *)(AC1Legacy::vlong *, void **, unsigned int))this->rnum_.vfptr->UnPack)(
             &this->rnum_,
             addr,
             size);
  if ( result )
  {
    v3->fInitialized_ = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  return result;
}

//----- (00549990) --------------------------------------------------------  // acclient.c:377141
void __thiscall NetKeyExch::NetKeyExch(NetKeyExch *this, PortalDH *dh)
{
  NetKeyExch *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&NetKeyExch::vftable;
  this->dh_ = dh;
  AC1Legacy::vlong::vlong(&this->rnum_, 0);
  v2->fInitialized_ = 0;
}
// 7CA718: using guessed type int (__thiscall *NetKeyExch::vftable)(void *, char);

//----- (005499C0) --------------------------------------------------------  // acclient.c:377154
int __thiscall NetKeyExch::GetPackSize(NetKeyExch *this)
{
  PackObjVtbl *v1; // eax@1
  NetKeyExch *v3; // [sp+0h] [bp-4h]@1

  v3 = this;
  v1 = this->rnum_.vfptr;
  v3 = 0;
  return ((int (__thiscall *)(AC1Legacy::vlong *, int *, _DWORD))v1->Pack)(&this->rnum_, &v3, 0) + 4;
}

//----- (005499E0) --------------------------------------------------------  // acclient.c:377166
NetKeyExch *__thiscall NetKeyExch::scalar_deleting_destructor(NetKeyExch *this, unsigned int a2)
{
  NetKeyExch *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&NetKeyExch::vftable;
  this->fInitialized_ = 0;
  this->dh_ = 0;
  AC1Legacy::vlong::~vlong(&this->rnum_);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CA718: using guessed type int (__thiscall *NetKeyExch::vftable)(void *, char);

