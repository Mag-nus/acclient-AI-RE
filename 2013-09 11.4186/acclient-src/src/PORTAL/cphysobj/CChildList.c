/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CChildList
   Object     : PORTAL\cphysobj\CChildList.obj
   Functions  : 19
   Addresses  : 0051ADD0 - 006FC8D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051ADD0) --------------------------------------------------------  // acclient.c:328665
void __thiscall SArray<CPhysicsObj *>::grow(SArray<CPhysicsObj *> *this, unsigned __int16 size)
{
  SArray<CPhysicsObj *> *v2; // esi@1
  void *v3; // eax@3
  int v4; // ecx@3
  CPhysicsObj **v5; // edi@3
  int v6; // eax@4

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    v5 = (CPhysicsObj **)v3;
    if ( v2->sizeOf )
    {
      do
      {
        v6 = (unsigned __int16)v4++;
        v5[v6] = v2->data[v6];
      }
      while ( (unsigned __int16)v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = v5;
    v2->sizeOf = size;
  }
  else
  {
    SArray<CPhysicsObj *>::shrink(this, size);
  }
}

//----- (0051AE30) --------------------------------------------------------  // acclient.c:328699
void __thiscall SArray<unsigned long>::grow(SArray<unsigned long> *this, unsigned __int16 size)
{
  SArray<unsigned long> *v2; // esi@1
  void *v3; // eax@3
  int v4; // ecx@3
  unsigned int *v5; // edi@3
  int v6; // eax@4

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    v5 = (unsigned int *)v3;
    if ( v2->sizeOf )
    {
      do
      {
        v6 = (unsigned __int16)v4++;
        v5[v6] = v2->data[v6];
      }
      while ( (unsigned __int16)v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = v5;
    v2->sizeOf = size;
  }
  else
  {
    SArray<unsigned long>::shrink(this, size);
  }
}

//----- (0051AE90) --------------------------------------------------------  // acclient.c:328733
void __thiscall SArray<CPhysicsObj *>::shrink(SArray<CPhysicsObj *> *this, const unsigned __int16 size)
{
  SArray<CPhysicsObj *> *v2; // esi@1
  void *v3; // eax@5
  int v4; // ecx@5
  CPhysicsObj **v5; // ebx@5
  int v6; // eax@6

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v3 = operator new[](4 * size);
      v4 = 0;
      v5 = (CPhysicsObj **)v3;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          v6 = (unsigned __int16)v4++;
          v5[v6] = v2->data[v6];
        }
        while ( (unsigned __int16)v4 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = v5;
    }
    else
    {
      operator delete[](this->data);
      v2->sizeOf = 0;
      v2->data = 0;
    }
  }
  else
  {
    SArray<CPhysicsObj *>::grow(this, size);
  }
}

//----- (0051AF10) --------------------------------------------------------  // acclient.c:328776
void __thiscall SArray<unsigned long>::shrink(SArray<unsigned long> *this, const unsigned __int16 size)
{
  SArray<unsigned long> *v2; // esi@1
  void *v3; // eax@5
  int v4; // ecx@5
  unsigned int *v5; // ebx@5
  int v6; // eax@6

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v3 = operator new[](4 * size);
      v4 = 0;
      v5 = (unsigned int *)v3;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          v6 = (unsigned __int16)v4++;
          v5[v6] = v2->data[v6];
        }
        while ( (unsigned __int16)v4 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = v5;
    }
    else
    {
      operator delete[](this->data);
      v2->sizeOf = 0;
      v2->data = 0;
    }
  }
  else
  {
    SArray<unsigned long>::grow(this, size);
  }
}

//----- (0051AF90) --------------------------------------------------------  // acclient.c:328819
void __thiscall CHILDLIST::remove_child(CHILDLIST *this, CPhysicsObj *obj)
{
  int v2; // eax@1
  unsigned __int16 v3; // dx@4
  int v4; // esi@5
  int v5; // ST10_4@5
  CPhysicsObj *v6; // edx@5
  Frame *v7; // edi@5
  int v8; // eax@5
  int v9; // edx@5
  int v10; // ebx@5
  CPhysicsObj *obja; // [sp+18h] [bp+4h]@5

  v2 = 0;
  if ( this->num_objects )
  {
    do
    {
      if ( this->objects.data[(unsigned __int16)v2] == obj )
        break;
      ++v2;
    }
    while ( (unsigned __int16)v2 < this->num_objects );
  }
  v3 = this->num_objects - 1;
  this->num_objects = v3;
  if ( (unsigned __int16)v2 < v3 )
  {
    do
    {
      v4 = (unsigned __int16)(v2 + 1);
      v5 = v2 + 1;
      v6 = (CPhysicsObj *)(unsigned __int16)v2;
      this->objects.data[(_DWORD)v6] = this->objects.data[v4];
      v7 = this->frames.data;
      v8 = (int)&v7[v4];
      obja = v6;
      v9 = (int)&v7[(_DWORD)v6];
      v10 = v9 + 52;
      *(_DWORD *)v10 = *(_DWORD *)(v8 + 52);
      *(_DWORD *)(v10 + 4) = *(_DWORD *)(v8 + 56);
      *(_DWORD *)(v10 + 8) = *(_DWORD *)(v8 + 60);
      *(_DWORD *)v9 = *(_DWORD *)v8;
      *(_DWORD *)(v9 + 4) = *(_DWORD *)(v8 + 4);
      *(_DWORD *)(v9 + 8) = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(v9 + 12) = *(_DWORD *)(v8 + 12);
      *(_DWORD *)(v9 + 16) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(v9 + 20) = *(_DWORD *)(v8 + 20);
      *(_DWORD *)(v9 + 24) = *(_DWORD *)(v8 + 24);
      *(_DWORD *)(v9 + 28) = *(_DWORD *)(v8 + 28);
      *(_DWORD *)(v9 + 32) = *(_DWORD *)(v8 + 32);
      *(_DWORD *)(v9 + 36) = *(_DWORD *)(v8 + 36);
      *(_DWORD *)(v9 + 40) = *(_DWORD *)(v8 + 40);
      *(_DWORD *)(v9 + 44) = *(_DWORD *)(v8 + 44);
      *(_DWORD *)(v9 + 48) = *(_DWORD *)(v8 + 48);
      this->part_numbers.data[(_DWORD)obja] = this->part_numbers.data[v4];
      this->location_ids.data[(_DWORD)obja] = this->location_ids.data[v4];
      v2 = v5;
    }
    while ( (unsigned __int16)v5 < this->num_objects );
  }
}

//----- (0051B080) --------------------------------------------------------  // acclient.c:328883
int __thiscall CHILDLIST::FindChildIndex(CHILDLIST *this, CPhysicsObj *child, unsigned __int16 *index)
{
  unsigned __int16 v3; // dx@1
  unsigned __int16 v4; // ax@1
  CPhysicsObj **v5; // ecx@2
  int result; // eax@5

  v3 = this->num_objects;
  v4 = 0;
  if ( this->num_objects )
  {
    v5 = this->objects.data;
    while ( v5[v4] != child )
    {
      ++v4;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
    *index = v4;
    result = 1;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (0051B0C0) --------------------------------------------------------  // acclient.c:328913
void __thiscall SArray<Frame>::grow(SArray<Frame> *this, unsigned __int16 size)
{
  SArray<Frame> *v2; // esi@1
  void *v3; // eax@3
  int v4; // ebx@4
  unsigned __int16 v5; // di@6

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[]((size << 6) + 4);
    if ( v3 )
    {
      v4 = (int)((char *)v3 + 4);
      *(_DWORD *)v3 = size;
      vector_constructor_iterator((char *)v3 + 4, 0x40u, size, (void *(__thiscall *)(void *))Frame::Frame);
    }
    else
    {
      v4 = 0;
    }
    v5 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        Frame::operator=((v5 << 6) + v4, (int)&v2->data[v5]);
        ++v5;
      }
      while ( v5 < v2->sizeOf );
    }
    if ( v2->data )
      operator delete[](&v2->data[-1].m_fOrigin.z);
    v2->data = (Frame *)v4;
    v2->sizeOf = size;
  }
  else
  {
    SArray<Frame>::shrink(this, size);
  }
}

//----- (0051B150) --------------------------------------------------------  // acclient.c:328956
void __thiscall SArray<Frame>::shrink(SArray<Frame> *this, const unsigned __int16 size)
{
  SArray<Frame> *v2; // esi@1
  int v3; // ebp@3
  void *v4; // eax@7
  unsigned __int16 v5; // di@9

  v2 = this;
  if ( size <= this->sizeOf )
  {
    v3 = 0;
    if ( size )
    {
      v4 = operator new[]((size << 6) + 4);
      if ( v4 )
      {
        v3 = (int)((char *)v4 + 4);
        *(_DWORD *)v4 = size;
        vector_constructor_iterator((char *)v4 + 4, 0x40u, size, (void *(__thiscall *)(void *))Frame::Frame);
      }
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          Frame::operator=((v5 << 6) + v3, (int)&v2->data[v5]);
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      if ( v2->data )
        operator delete[](&v2->data[-1].m_fOrigin.z);
      v2->data = (Frame *)v3;
    }
    else
    {
      if ( this->data )
        operator delete[](&this->data[-1].m_fOrigin.z);
      v2->sizeOf = 0;
      v2->data = 0;
    }
  }
  else
  {
    SArray<Frame>::grow(this, size);
  }
}

//----- (0051B200) --------------------------------------------------------  // acclient.c:329006
void __thiscall CHILDLIST::CHILDLIST(CHILDLIST *this)
{
  this->num_objects = 0;
  this->objects.data = 0;
  this->objects.sizeOf = 0;
  this->frames.data = 0;
  this->frames.sizeOf = 0;
  this->part_numbers.data = 0;
  this->part_numbers.sizeOf = 0;
  this->location_ids.data = 0;
  this->location_ids.sizeOf = 0;
}

//----- (0051B230) --------------------------------------------------------  // acclient.c:329020
void __thiscall CHILDLIST::~CHILDLIST(CHILDLIST *this)
{
  CHILDLIST *v1; // esi@1
  Frame *v2; // eax@1

  v1 = this;
  operator delete[](this->location_ids.data);
  operator delete[](v1->part_numbers.data);
  v2 = v1->frames.data;
  if ( v2 )
    operator delete[](&v2[-1].m_fOrigin.z);
  operator delete[](v1->objects.data);
}

//----- (0051B270) --------------------------------------------------------  // acclient.c:329035
void __thiscall CHILDLIST::add_child(CHILDLIST *this, CPhysicsObj *obj, Frame *frame, unsigned int part_no, unsigned int location_id)
{
  CHILDLIST *v5; // esi@1
  unsigned __int16 v6; // ax@1
  unsigned __int16 v7; // di@2

  v5 = this;
  v6 = this->objects.sizeOf;
  if ( v6 <= this->num_objects )
  {
    v7 = v6 + 4;
    SArray<CPhysicsObj *>::grow(&this->objects, v6 + 4);
    SArray<Frame>::grow(&v5->frames, v7);
    SArray<unsigned long>::grow(&v5->part_numbers, v7);
    SArray<unsigned long>::grow(&v5->location_ids, v7);
  }
  v5->objects.data[v5->num_objects] = obj;
  Frame::operator=((int)&v5->frames.data[v5->num_objects], (int)frame);
  v5->part_numbers.data[v5->num_objects] = part_no;
  v5->location_ids.data[v5->num_objects++] = location_id;
}

//----- (006FC800) --------------------------------------------------------  // acclient.c:784843
int sub_6FC800()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_7;
  INITIAL_MAX_DATA_RATE_74 = LOWEST_DATA_RATE_7;
  return result;
}

//----- (006FC810) --------------------------------------------------------  // acclient.c:784853
void sub_6FC810()
{
  flt_8440B8 = 1000.0 + 1.0;
}

//----- (006FC830) --------------------------------------------------------  // acclient.c:784859
void _E99_16()
{
  flt_8440BC = 24.0 * 8.0;
}

//----- (006FC850) --------------------------------------------------------  // acclient.c:784865
void _E101_13()
{
  flt_8440C0 = 24.0 * 0.5;
}

//----- (006FC870) --------------------------------------------------------  // acclient.c:784871
void sub_6FC870()
{
  flt_8440C8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC890) --------------------------------------------------------  // acclient.c:784877
void _E105_20()
{
  dbl_8440D0 = 1.0 / 30.0;
}

//----- (006FC8B0) --------------------------------------------------------  // acclient.c:784883
void _E107_15()
{
  dbl_8440D8 = 1.0 / 5.0;
}

//----- (006FC8D0) --------------------------------------------------------  // acclient.c:784889
int sub_6FC8D0()
{
  return atexit(nullsub_1099);
}

