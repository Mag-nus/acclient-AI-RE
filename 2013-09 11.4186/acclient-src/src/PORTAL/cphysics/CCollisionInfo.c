/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCollisionInfo
   Object     : PORTAL\cphysics\CCollisionInfo.obj
   Functions  : 11
   Addresses  : 006B4D40 - 007237C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B4D40) --------------------------------------------------------  // acclient.c:718653
void __thiscall DArray<CPhysicsObj const *>::grow(DArray<CPhysicsObj const *> *this, unsigned int size)
{
  DArray<CPhysicsObj const *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (CPhysicsObj **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CPhysicsObj const *>::shrink(this, size);
  }
}

//----- (006B4DA0) --------------------------------------------------------  // acclient.c:718684
void __thiscall DArray<CPhysicsObj const *>::shrink(DArray<CPhysicsObj const *> *this, unsigned int size)
{
  DArray<CPhysicsObj const *> *v2; // esi@1
  CPhysicsObj **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (CPhysicsObj **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<CPhysicsObj const *>::grow(this, size);
  }
}

//----- (006B4E20) --------------------------------------------------------  // acclient.c:718728
void __thiscall COLLISIONINFO::add_object(COLLISIONINFO *this, CPhysicsObj *object, TransitionState ts)
{
  COLLISIONINFO *v3; // esi@1
  unsigned int v4; // edx@1
  unsigned int v5; // eax@1
  CPhysicsObj **v6; // ecx@2

  v3 = this;
  v4 = this->num_collide_object;
  v5 = 0;
  if ( v4 )
  {
    v6 = this->collide_object.data;
    while ( object != *v6 )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3->num_collide_object )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( v4 >= v3->collide_object.sizeOf )
      DArray<CPhysicsObj const *>::grow(&v3->collide_object, v4 + 10);
    v3->collide_object.data[v3->num_collide_object++] = object;
    if ( ts != 1 )
      v3->last_collided_object = object;
  }
}

//----- (007236F0) --------------------------------------------------------  // acclient.c:821293
int _E77_26()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_49;
  dword_8FA83C = LOWEST_DATA_RATE_49;
  return result;
}

//----- (00723700) --------------------------------------------------------  // acclient.c:821303
void sub_723700()
{
  flt_8FA840 = 1000.0 + 1.0;
}

//----- (00723720) --------------------------------------------------------  // acclient.c:821309
void _E99_50()
{
  flt_8FA844 = 24.0 * 8.0;
}

//----- (00723740) --------------------------------------------------------  // acclient.c:821315
void _E101_49()
{
  flt_8FA848 = 24.0 * 0.5;
}

//----- (00723760) --------------------------------------------------------  // acclient.c:821321
void sub_723760()
{
  flt_8FA850 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00723780) --------------------------------------------------------  // acclient.c:821327
void _E105_63()
{
  dbl_8FA858 = 1.0 / 30.0;
}

//----- (007237A0) --------------------------------------------------------  // acclient.c:821333
void _E107_51()
{
  dbl_8FA860 = 1.0 / 5.0;
}

//----- (007237C0) --------------------------------------------------------  // acclient.c:821339
int sub_7237C0()
{
  return atexit(nullsub_1079);
}

