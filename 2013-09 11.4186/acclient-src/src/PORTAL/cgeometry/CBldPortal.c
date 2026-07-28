/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBldPortal
   Object     : PORTAL\cgeometry\CBldPortal.obj
   Functions  : 19
   Addresses  : 0053BB30 - 00700AA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053BB30) --------------------------------------------------------  // acclient.c:362405
void __thiscall CBldPortal::CBldPortal(CBldPortal *this)
{
  this->portal_side = -1;
  this->other_cell_id = 0;
  this->other_portal_id = -1;
  this->exact_match = 0;
  this->num_stabs = 0;
  this->stab_list = 0;
}

//----- (0053BB50) --------------------------------------------------------  // acclient.c:362416
void __thiscall CBldPortal::~CBldPortal(CBldPortal *this)
{
  operator delete[](this->stab_list);
}

//----- (0053BB60) --------------------------------------------------------  // acclient.c:362422
void __thiscall CBldPortal::add_to_stablist(CBldPortal *this, unsigned int **block_stab_list, unsigned int *max_size, unsigned int *stab_num)
{
  unsigned int v4; // edx@1
  unsigned int v5; // eax@2
  bool v6; // zf@2
  unsigned int v7; // edx@3
  unsigned int *v8; // ecx@3
  unsigned int *v9; // ebx@9
  unsigned int v10; // eax@9
  CBldPortal *v11; // [sp+0h] [bp-8h]@1
  unsigned int iq; // [sp+4h] [bp-4h]@1

  v4 = 0;
  v11 = this;
  iq = 0;
  if ( this->num_stabs )
  {
    do
    {
      v5 = *stab_num;
      v6 = *stab_num == 0;
      if ( *stab_num )
      {
        v7 = this->stab_list[v4];
        v8 = &(*block_stab_list)[v5 - 1];
        do
        {
          if ( v7 == *v8 )
            break;
          --v5;
          --v8;
        }
        while ( v5 );
        this = v11;
        v4 = iq;
        v6 = v5 == 0;
      }
      if ( v6 )
      {
        if ( *stab_num >= *max_size )
        {
          v9 = *block_stab_list;
          *block_stab_list = (unsigned int *)operator new[](4 * *max_size + 40);
          *max_size += 10;
          v10 = 0;
          if ( *stab_num )
          {
            do
            {
              (*block_stab_list)[v10] = v9[v10];
              ++v10;
            }
            while ( v10 < *stab_num );
          }
          operator delete(v9);
          this = v11;
          v4 = iq;
        }
        (*block_stab_list)[*stab_num] = this->stab_list[v4];
        this = v11;
        ++*stab_num;
      }
      ++v4;
      iq = v4;
    }
    while ( v4 < this->num_stabs );
  }
}

//----- (0053BC30) --------------------------------------------------------  // acclient.c:362492
RenderVertexStreamD3D *__thiscall CBldPortal::GetOtherCell(CBldPortal *this)
{
  return CEnvCell::GetVisible(this->other_cell_id);
}

//----- (0053BC40) --------------------------------------------------------  // acclient.c:362498
int __thiscall CBldPortal::UnPack(CBldPortal *this, unsigned int block_mask, void **addr, unsigned int size)
{
  void **v4; // esi@1
  CBldPortal *v5; // edi@1
  __int16 v6; // ax@1
  unsigned __int16 v7; // cx@1
  __int16 v8; // cx@1
  unsigned __int16 v9; // cx@1
  void *v10; // eax@1
  unsigned int v11; // ecx@1
  unsigned int v12; // eax@1
  unsigned __int16 v13; // dx@2

  v4 = addr;
  v5 = this;
  v6 = *(_WORD *)*addr;
  *addr = (char *)*addr + 2;
  this->exact_match = v6 & 1;
  this->portal_side = ((unsigned int)(unsigned __int8)~(_BYTE)v6 >> 1) & 1;
  v7 = *(_WORD *)*addr;
  *v4 = (char *)*v4 + 2;
  v5->other_cell_id = block_mask | v7;
  v8 = *(_WORD *)*addr;
  *v4 = (char *)*v4 + 2;
  v5->other_portal_id = v8;
  v9 = *(_WORD *)*addr;
  *v4 = (char *)*v4 + 2;
  v5->num_stabs = v9;
  v10 = operator new[](4 * v9);
  v11 = v5->num_stabs;
  v5->stab_list = (unsigned int *)v10;
  v12 = 0;
  if ( v11 )
  {
    do
    {
      v13 = *(_WORD *)*addr;
      *addr = (char *)*addr + 2;
      v5->stab_list[v12++] = block_mask | v13;
    }
    while ( v12 < v5->num_stabs );
  }
  if ( v5->num_stabs & 1 )
    *addr = (char *)*addr + 2;
  return 1;
}

//----- (0053BD00) --------------------------------------------------------  // acclient.c:362546
int __thiscall CBldPortal::PreFetchCells(CBldPortal *this)
{
  CBldPortal *v1; // esi@1
  unsigned int v2; // edi@1
  signed int v3; // ebx@1
  QualifiedDataID *v4; // eax@2
  CACHE_OBJECT_CODES v5; // eax@2
  QualifiedDataID v7; // [sp+Ch] [bp-8h]@2

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->num_stabs )
  {
    do
    {
      QualifiedDataID::QualifiedDataID(&v7, (IDClass<_tagDataID,32,0>)v1->stab_list[v2], 3u);
      v5 = DBObj::PreFetch(v4);
      if ( v5 != 2 && v5 != 1 )
        v3 = 0;
      ++v2;
    }
    while ( v2 < v1->num_stabs );
  }
  return v3;
}

//----- (0053BD50) --------------------------------------------------------  // acclient.c:362574
int __thiscall CBldPortal::pack_size(CBldPortal *this)
{
  unsigned int v1; // edx@1
  int v2; // ecx@1
  int result; // eax@2

  v1 = 2 * this->num_stabs + 8;
  v2 = (2 * LOBYTE(this->num_stabs) + 8) & 3;
  if ( v2 )
    result = v1 + 4 - v2;
  else
    result = v1;
  return result;
}

//----- (0053BD70) --------------------------------------------------------  // acclient.c:362590
int __thiscall CBldPortal::Pack(CBldPortal *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  int v4; // edx@2
  int result; // eax@4
  signed __int16 v6; // si@5
  char *v7; // esi@9
  char *v8; // ebx@9
  char *v9; // edi@9
  char *v10; // esi@9
  char *v11; // edi@9
  unsigned int v12; // esi@9

  v3 = 2 * this->num_stabs + 8;
  if ( (2 * LOBYTE(this->num_stabs) + 8) & 3 )
    v4 = 4 - ((2 * LOBYTE(this->num_stabs) + 8) & 3);
  else
    v4 = 0;
  result = v4 + v3;
  if ( size >= v4 + v3 )
  {
    v6 = 0;
    if ( this->exact_match )
      v6 = 1;
    if ( !this->portal_side )
      v6 |= 2u;
    *(_WORD *)*addr = v6;
    v7 = (char *)*addr + 2;
    *addr = v7;
    *(_WORD *)v7 = LOWORD(this->other_cell_id);
    v8 = (char *)*addr + 2;
    *addr = v8;
    *(_WORD *)v8 = LOWORD(this->other_portal_id);
    v9 = (char *)*addr + 2;
    *addr = v9;
    *(_WORD *)v9 = LOWORD(this->num_stabs);
    v10 = (char *)*addr + 2;
    *addr = v10;
    v11 = v10;
    v12 = 0;
    if ( this->num_stabs )
    {
      do
      {
        *(_WORD *)v11 = LOWORD(this->stab_list[v12]);
        v11 = (char *)*addr + 2;
        *addr = v11;
        ++v12;
      }
      while ( v12 < this->num_stabs );
    }
    if ( this->num_stabs & 1 )
    {
      *(_WORD *)v11 = 0;
      *addr = (char *)*addr + 2;
    }
  }
  return result;
}

//----- (007009A0) --------------------------------------------------------  // acclient.c:788468
int _E89_3()
{
  return atexit(_E90_2);
}

//----- (007009B0) --------------------------------------------------------  // acclient.c:788474
int _E92_2()
{
  return atexit(nullsub_1189);
}

//----- (007009C0) --------------------------------------------------------  // acclient.c:788480
int sub_7009C0()
{
  return atexit(_E96_6);
}

//----- (007009D0) --------------------------------------------------------  // acclient.c:788486
void _E98_9()
{
  LODWORD(dword_845340) = 1053364187;
}

//----- (007009E0) --------------------------------------------------------  // acclient.c:788492
void sub_7009E0()
{
  flt_845344 = 1000.0 + 1.0;
}

//----- (00700A00) --------------------------------------------------------  // acclient.c:788498
void _E102_22()
{
  flt_845348 = 24.0 * 8.0;
}

//----- (00700A20) --------------------------------------------------------  // acclient.c:788504
void _E104_12()
{
  flt_84534C = 24.0 * 0.5;
}

//----- (00700A40) --------------------------------------------------------  // acclient.c:788510
void sub_700A40()
{
  flt_845350 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00700A60) --------------------------------------------------------  // acclient.c:788516
void _E108_77()
{
  dbl_845358 = 1.0 / 30.0;
}

//----- (00700A80) --------------------------------------------------------  // acclient.c:788522
void _E110_63()
{
  dbl_845360 = 1.0 / 5.0;
}

//----- (00700AA0) --------------------------------------------------------  // acclient.c:788528
int sub_700AA0()
{
  return atexit(nullsub_1187);
}

