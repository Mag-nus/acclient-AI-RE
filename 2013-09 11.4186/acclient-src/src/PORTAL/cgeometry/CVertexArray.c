/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CVertexArray
   Object     : PORTAL\cgeometry\CVertexArray.obj
   Functions  : 7
   Addresses  : 0053BE30 - 0053C030 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053BE30) --------------------------------------------------------  // acclient.c:362651
int __thiscall CVertexArray::AllocateVertex(CVertexArray *this, unsigned int size, VertexType type)
{
  CVertexArray *v3; // esi@1
  void *v4; // eax@1
  unsigned int v5; // edi@6
  int result; // eax@8

  v3 = this;
  v4 = _malloc(CVertexArray::vertex_size * (size + 1));
  v3->vertex_memory = v4;
  if ( v4 )
  {
    if ( CVertexArray::vertex_size == 32 && (unsigned __int8)v4 & 0x1F )
      v4 = (char *)v4 + -((unsigned __int8)v4 & 0x1F) + 32;
    v3->vertices = (CVertex *)v4;
    v3->vertex_type = type;
    v3->num_vertices = size;
    if ( type == 1 )
    {
      v5 = 0;
      if ( size )
      {
        do
          CSWVertex::Init((CSWVertex *)((char *)v3->vertices + v5++ * CVertexArray::vertex_size));
        while ( v5 < v3->num_vertices );
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (0053BEB0) --------------------------------------------------------  // acclient.c:362689
void __thiscall CVertexArray::DestroyVertex(CVertexArray *this)
{
  CVertexArray *v1; // esi@1
  unsigned int v2; // edi@2

  v1 = this;
  if ( this->vertex_type == 1 )
  {
    v2 = 0;
    if ( this->num_vertices )
    {
      do
        CSWVertex::Destroy((CSWVertex *)((char *)v1->vertices + v2++ * CVertexArray::vertex_size));
      while ( v2 < v1->num_vertices );
    }
  }
  _free(v1->vertex_memory);
  v1->vertex_memory = 0;
  v1->vertex_type = 0;
  v1->num_vertices = 0;
  v1->vertices = 0;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (0053BF10) --------------------------------------------------------  // acclient.c:362714
void __thiscall CVertexArray::BuildBoundingBox(CVertexArray *this)
{
  CVertexArray *v1; // esi@1
  BBox *v2; // ebx@1
  unsigned int v3; // edi@1

  v1 = this;
  v2 = &this->bbox;
  BBox::InitForAdjustment(&this->bbox);
  v3 = 0;
  if ( v1->num_vertices )
  {
    do
      BBox::AdjustBBox(v2, (Vector3 *)((char *)v1->vertices + v3++ * CVertexArray::vertex_size));
    while ( v3 < v1->num_vertices );
  }
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (0053BF60) --------------------------------------------------------  // acclient.c:362734
signed int __thiscall CVertexArray::pack_size(CVertexArray *this)
{
  CVertexArray *v1; // edi@1
  signed int v2; // ebx@1
  unsigned int v3; // esi@2

  v1 = this;
  v2 = 8;
  if ( this->vertex_type == 1 )
  {
    v3 = 0;
    if ( this->num_vertices )
    {
      do
        v2 += CSWVertex::pack_size((CSWVertex *)((char *)v1->vertices + v3++ * CVertexArray::vertex_size));
      while ( v3 < v1->num_vertices );
    }
  }
  return v2;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (0053BFB0) --------------------------------------------------------  // acclient.c:362757
void __thiscall CVertexArray::CVertexArray(CVertexArray *this)
{
  this->vertex_memory = 0;
  this->vertex_type = 0;
  this->num_vertices = 0;
  this->vertices = 0;
}

//----- (0053BFC0) --------------------------------------------------------  // acclient.c:362766
signed int __thiscall CVertexArray::Pack(CVertexArray *this, void **addr, unsigned int size)
{
  CVertexArray *v3; // esi@1
  signed int v4; // ecx@1
  char *v5; // eax@2
  unsigned int v6; // ebx@3
  unsigned int retval; // [sp+8h] [bp-4h]@1

  v3 = this;
  v4 = CVertexArray::pack_size(this);
  retval = v4;
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->vertex_type;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->num_vertices;
    *addr = (char *)*addr + 4;
    if ( v3->vertex_type == 1 )
    {
      v6 = 0;
      if ( v3->num_vertices )
      {
        do
          CSWVertex::Pack((CSWVertex *)((char *)v3->vertices + v6++ * CVertexArray::vertex_size), addr, size);
        while ( v6 < v3->num_vertices );
        v4 = retval;
      }
    }
  }
  return v4;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (0053C030) --------------------------------------------------------  // acclient.c:362801
int __thiscall CVertexArray::UnPack(CVertexArray *this, void **addr, unsigned int size)
{
  CVertexArray *v3; // esi@1
  char *v4; // eax@1
  int result; // eax@1
  unsigned int v6; // ebx@3

  v3 = this;
  this->vertex_type = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  this->num_vertices = *(_DWORD *)v4;
  *addr = (char *)*addr + 4;
  result = CVertexArray::AllocateVertex(this, this->num_vertices, this->vertex_type);
  if ( result )
  {
    if ( v3->vertex_type == 1 )
    {
      v6 = 0;
      if ( v3->num_vertices )
      {
        do
          CSWVertex::UnPack((CSWVertex *)((char *)v3->vertices + v6++ * CVertexArray::vertex_size), addr, size);
        while ( v6 < v3->num_vertices );
      }
    }
    CVertexArray::BuildBoundingBox(v3);
    result = 1;
  }
  return result;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

