/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SharedCritSec
   Object     : CORE\newthread\SharedCritSec.obj
   Functions  : 5
   Addresses  : 0065D8B0 - 0065D930 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065D8B0) --------------------------------------------------------  // acclient.c:627305
void __thiscall SharedCriticalSection::SharedCriticalSection(SharedCriticalSection *this)
{
  this->lockHolder_ = 0;
  this->lockCount_ = 0;
  this->vfptr = (SharedCriticalSectionVtbl *)&SharedCriticalSection::vftable;
  InitializeCriticalSection(&this->myCritSection_);
}
// 7FDA4C: using guessed type int (__thiscall *SharedCriticalSection::vftable)(void *, char);

//----- (0065D8D0) --------------------------------------------------------  // acclient.c:627315
void __thiscall SharedCriticalSection::~SharedCriticalSection(SharedCriticalSection *this)
{
  this->vfptr = (SharedCriticalSectionVtbl *)&SharedCriticalSection::vftable;
  DeleteCriticalSection(&this->myCritSection_);
}
// 7FDA4C: using guessed type int (__thiscall *SharedCriticalSection::vftable)(void *, char);

//----- (0065D8F0) --------------------------------------------------------  // acclient.c:627323
void __thiscall SharedCriticalSection::EnterCriticalSection(SharedCriticalSection *this)
{
  SharedCriticalSection *v1; // esi@1
  DWORD v2; // eax@1

  v1 = this;
  EnterCriticalSection(&this->myCritSection_);
  v2 = GetCurrentThreadId();
  ++v1->lockCount_;
  v1->lockHolder_ = v2;
}

//----- (0065D910) --------------------------------------------------------  // acclient.c:627336
void __thiscall SharedCriticalSection::LeaveCriticalSection(SharedCriticalSection *this)
{
  bool v1; // zf@1

  v1 = this->lockCount_-- == 1;
  if ( v1 )
    this->lockHolder_ = 0;
  LeaveCriticalSection(&this->myCritSection_);
}

//----- (0065D930) --------------------------------------------------------  // acclient.c:627347
SharedCriticalSection *__thiscall SharedCriticalSection::vector_deleting_destructor(SharedCriticalSection *this, unsigned int a2)
{
  SharedCriticalSection *v2; // esi@1

  v2 = this;
  this->vfptr = (SharedCriticalSectionVtbl *)&SharedCriticalSection::vftable;
  DeleteCriticalSection(&this->myCritSection_);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FDA4C: using guessed type int (__thiscall *SharedCriticalSection::vftable)(void *, char);

