/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPartCell
   Object     : PORTAL\ccell\CPartCell.obj
   Functions  : 16
   Addresses  : 0052E510 - 006FEB80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0052E510) --------------------------------------------------------  // acclient.c:350415
void __thiscall DArray<CShadowPart *>::shrink(DArray<CShadowPart *> *this, unsigned int size)
{
  DArray<CShadowPart *> *v2; // esi@1
  CShadowPart **v3; // ST04_4@4
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
      v2->data = (CShadowPart **)v4;
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
    DArray<CShadowPart *>::grow(this, size);
  }
}

//----- (0052E590) --------------------------------------------------------  // acclient.c:350459
void __thiscall DArray<CShadowPart *>::grow(DArray<CShadowPart *> *this, unsigned int size)
{
  DArray<CShadowPart *> *v2; // esi@1
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
    v2->data = (CShadowPart **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CShadowPart *>::shrink(this, size);
  }
}

//----- (0052E5F0) --------------------------------------------------------  // acclient.c:350490
void __thiscall CPartCell::CPartCell(CPartCell *this)
{
  this->vfptr = (CPartCellVtbl *)&CPartCell::vftable;
  this->num_shadow_parts = 0;
  this->shadow_part_list.data = 0;
  this->shadow_part_list.sizeOf = 0;
  this->shadow_part_list.next_available = 0;
  this->shadow_part_list.blocksize = 128;
}
// 7C8DE8: using guessed type void (__thiscall *CPartCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);

//----- (0052E610) --------------------------------------------------------  // acclient.c:350502
void __thiscall CPartCell::~CPartCell(CPartCell *this)
{
  CPartCell *v1; // esi@1

  v1 = this;
  this->vfptr = (CPartCellVtbl *)&CPartCell::vftable;
  operator delete[](this->shadow_part_list.data);
  v1->shadow_part_list.data = 0;
}
// 7C8DE8: using guessed type void (__thiscall *CPartCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);

//----- (0052E630) --------------------------------------------------------  // acclient.c:350514
void __thiscall CPartCell::remove_part(CPartCell *this, CPhysicsPart *part)
{
  CPartCell *v2; // esi@1
  unsigned int v3; // ebx@1
  CShadowPart **v4; // eax@2
  CShadowPart *v5; // edi@3
  CShadowPart *v6; // ecx@6
  int v7; // eax@6
  unsigned int v8; // eax@7

  v2 = this;
  v3 = 0;
  if ( this->num_shadow_parts )
  {
    v4 = this->shadow_part_list.data;
    while ( 1 )
    {
      v5 = *v4;
      if ( (*v4)->part == part )
        break;
      ++v3;
      ++v4;
      if ( v3 >= this->num_shadow_parts )
        goto LABEL_7;
    }
    v6 = *v4;
    v5->planes = 0;
    v5->num_planes = 0;
    CShadowPart::~CShadowPart(v6);
    operator delete(v5);
    v7 = v2->num_shadow_parts - 1;
    v2->num_shadow_parts = v7;
    v2->shadow_part_list.data[v3] = v2->shadow_part_list.data[v7];
  }
LABEL_7:
  v8 = v2->num_shadow_parts;
  if ( v8 + 200 < v2->shadow_part_list.sizeOf )
    DArray<CShadowPart *>::shrink(&v2->shadow_part_list, v8 + 100);
}

//----- (0052E6B0) --------------------------------------------------------  // acclient.c:350555
void __thiscall CPartCell::remove_shadows(CPartCell *this, int del_flag)
{
  CPartCell *v2; // esi@1
  unsigned int v3; // ebx@2
  CShadowPart **v4; // eax@3
  void *v5; // edi@3

  v2 = this;
  if ( del_flag )
  {
    v3 = 0;
    if ( this->num_shadow_parts )
    {
      do
      {
        v4 = v2->shadow_part_list.data;
        v5 = v4[v3];
        if ( v5 )
        {
          CShadowPart::~CShadowPart(v4[v3]);
          operator delete(v5);
        }
        ++v3;
      }
      while ( v3 < v2->num_shadow_parts );
    }
  }
  v2->num_shadow_parts = 0;
}

//----- (0052E700) --------------------------------------------------------  // acclient.c:350586
CPartCell *__thiscall CPartCell::scalar_deleting_destructor(CPartCell *this, unsigned int a2)
{
  CPartCell *v2; // esi@1

  v2 = this;
  this->vfptr = (CPartCellVtbl *)&CPartCell::vftable;
  operator delete[](this->shadow_part_list.data);
  v2->shadow_part_list.data = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C8DE8: using guessed type void (__thiscall *CPartCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);

//----- (0052E740) --------------------------------------------------------  // acclient.c:350601
void __thiscall CPartCell::add_part(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned int num_shadow_parts)
{
  CPartCell *v5; // edi@1
  CShadowPart *v6; // eax@1
  CShadowPart *v7; // eax@3
  CShadowPart *v8; // esi@3
  CShadowPart *v9; // eax@5
  unsigned int v10; // eax@7
  unsigned int v11; // eax@9
  CShadowPart **v12; // ecx@9

  v5 = this;
  v6 = (CShadowPart *)operator new(0x10u);
  if ( planes )
  {
    if ( v6 )
    {
      CShadowPart::CShadowPart(v6, 1u, planes, frame, part);
      v8 = v9;
      goto LABEL_7;
    }
  }
  else if ( v6 )
  {
    CShadowPart::CShadowPart(v6, 0, 0, part);
    v8 = v7;
    goto LABEL_7;
  }
  v8 = 0;
LABEL_7:
  v10 = v5->shadow_part_list.sizeOf;
  if ( v5->num_shadow_parts >= v10 )
    DArray<CShadowPart *>::grow(&v5->shadow_part_list, v10 + 100);
  v11 = v5->num_shadow_parts;
  v12 = v5->shadow_part_list.data;
  v5->num_shadow_parts = v11 + 1;
  v12[v11] = v8;
}

//----- (006FEAB0) --------------------------------------------------------  // acclient.c:786777
int _E77_4()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_17;
  INITIAL_MAX_DATA_RATE_87 = LOWEST_DATA_RATE_17;
  return result;
}

//----- (006FEAC0) --------------------------------------------------------  // acclient.c:786787
void sub_6FEAC0()
{
  flt_844A60 = 1000.0 + 1.0;
}

//----- (006FEAE0) --------------------------------------------------------  // acclient.c:786793
void _E99_28()
{
  flt_844A64 = 24.0 * 8.0;
}

//----- (006FEB00) --------------------------------------------------------  // acclient.c:786799
void _E101_26()
{
  flt_844A68 = 24.0 * 0.5;
}

//----- (006FEB20) --------------------------------------------------------  // acclient.c:786805
void sub_6FEB20()
{
  flt_844A70 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FEB40) --------------------------------------------------------  // acclient.c:786811
void _E105_33()
{
  dbl_844A78 = 1.0 / 30.0;
}

//----- (006FEB60) --------------------------------------------------------  // acclient.c:786817
void _E107_26()
{
  dbl_844A80 = 1.0 / 5.0;
}

//----- (006FEB80) --------------------------------------------------------  // acclient.c:786823
int sub_6FEB80()
{
  return atexit(nullsub_1150);
}

