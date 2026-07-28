/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCellArray
   Object     : PORTAL\cphysics\CCellArray.obj
   Functions  : 4
   Addresses  : 006B4E80 - 006B4FF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B4E80) --------------------------------------------------------  // acclient.c:718761
void __thiscall CELLARRAY::remove_cell(CELLARRAY *this, const unsigned int index)
{
  unsigned int v2; // eax@1
  CELLINFO *v3; // edx@2
  unsigned int v4; // eax@2

  v2 = this->num_cells;
  if ( v2 )
  {
    v3 = this->cells.data;
    v4 = v2 - 1;
    this->num_cells = v4;
    v3[index].cell_id = v3[v4].cell_id;
    this->cells.data[index].cell = this->cells.data[this->num_cells].cell;
  }
}

//----- (006B4EB0) --------------------------------------------------------  // acclient.c:718779
void __thiscall DArray<CELLINFO>::grow(DArray<CELLINFO> *this, unsigned int size)
{
  DArray<CELLINFO> *v2; // esi@1
  void *v3; // eax@3
  int v4; // edi@4
  unsigned int v5; // eax@6
  CELLINFO *v6; // ecx@7

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](8 * size + 4);
    if ( v3 )
    {
      v4 = (int)((char *)v3 + 4);
      *(_DWORD *)v3 = size;
      vector_constructor_iterator(
        (char *)v3 + 4,
        8u,
        size,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
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
        v6 = v2->data;
        *(_DWORD *)(v4 + 8 * v5) = v2->data[v5].cell_id;
        *(_DWORD *)(v4 + 8 * v5 + 4) = v6[v5].cell;
        ++v5;
      }
      while ( v5 < v2->sizeOf );
    }
    if ( v2->data )
      operator delete[](&v2->data[-1].cell);
    v2->data = (CELLINFO *)v4;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CELLINFO>::shrink(this, size);
  }
}

//----- (006B4F40) --------------------------------------------------------  // acclient.c:718829
void __thiscall DArray<CELLINFO>::shrink(DArray<CELLINFO> *this, unsigned int size)
{
  DArray<CELLINFO> *v2; // esi@1
  CELLINFO *v3; // eax@4
  bool v4; // zf@4
  void *v5; // eax@7
  int v6; // ebx@8
  unsigned int v7; // eax@10
  CELLINFO *v8; // ecx@11

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v5 = operator new[](8 * size + 4);
      if ( v5 )
      {
        v6 = (int)((char *)v5 + 4);
        *(_DWORD *)v5 = size;
        vector_constructor_iterator(
          (char *)v5 + 4,
          8u,
          size,
          (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      }
      else
      {
        v6 = 0;
      }
      v7 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          v8 = v2->data;
          *(_DWORD *)(v6 + 8 * v7) = v2->data[v7].cell_id;
          *(_DWORD *)(v6 + 8 * v7 + 4) = v8[v7].cell;
          ++v7;
        }
        while ( v7 < v2->sizeOf );
      }
      if ( v2->data )
        operator delete[](&v2->data[-1].cell);
      v2->data = (CELLINFO *)v6;
    }
    else
    {
      v3 = this->data;
      v4 = this->data == 0;
      this->sizeOf = 0;
      if ( !v4 )
        operator delete[](&v3[-1].cell);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<CELLINFO>::grow(this, size);
  }
}

//----- (006B4FF0) --------------------------------------------------------  // acclient.c:718895
void __thiscall CELLARRAY::add_cell(CELLARRAY *this, const unsigned int cell_id, CObjCell *cell)
{
  CELLARRAY *v3; // esi@1
  unsigned int v4; // edx@1
  unsigned int v5; // eax@1
  CELLINFO *v6; // ecx@2

  v3 = this;
  v4 = this->num_cells;
  v5 = 0;
  if ( v4 )
  {
    v6 = this->cells.data;
    while ( cell_id != v6->cell_id )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3->num_cells )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( v4 >= v3->cells.sizeOf )
      DArray<CELLINFO>::grow(&v3->cells, v4 + 8);
    v3->cells.data[v3->num_cells].cell_id = cell_id;
    v3->cells.data[v3->num_cells++].cell = cell;
  }
}

