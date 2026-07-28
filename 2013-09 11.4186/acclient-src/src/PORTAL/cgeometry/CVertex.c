/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CVertex
   Object     : PORTAL\cgeometry\CVertex.obj
   Functions  : 5
   Addresses  : 0053DD30 - 0053DE50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053DD30) --------------------------------------------------------  // acclient.c:364759
void __thiscall CSWVertex::Init(CSWVertex *this)
{
  this->vert_id = 0;
  this->num_uvs = 0;
  this->uvs = 0;
}

//----- (0053DD40) --------------------------------------------------------  // acclient.c:364767
int __thiscall CSWVertex::pack_size(CSWVertex *this)
{
  return 8 * this->num_uvs + 28;
}

//----- (0053DD50) --------------------------------------------------------  // acclient.c:364773
int __thiscall CSWVertex::Pack(CSWVertex *this, void **addr, unsigned int size)
{
  int result; // eax@1
  char *v4; // esi@2
  char *v5; // ebx@2
  char *v6; // ebx@3
  char *v7; // edi@3
  char *v8; // esi@3
  char *v9; // ebx@4
  char *v10; // edi@4
  signed int v11; // edi@5
  CVec2Duv *v12; // esi@6
  char *v13; // ebx@7
  unsigned int retval; // [sp+4h] [bp-4h]@1

  result = 8 * this->num_uvs + 28;
  retval = 8 * this->num_uvs + 28;
  if ( size >= result )
  {
    *(_WORD *)*addr = this->vert_id;
    v4 = (char *)*addr + 2;
    *addr = v4;
    *(_WORD *)v4 = this->num_uvs;
    v5 = (char *)*addr + 2;
    *addr = v5;
    if ( size >= 0xC )
    {
      *(_DWORD *)v5 = LODWORD(this->x);
      v6 = (char *)*addr + 4;
      *addr = v6;
      *(float *)v6 = this->y;
      v7 = (char *)*addr + 4;
      *addr = v7;
      *(float *)v7 = this->z;
      v8 = (char *)*addr + 4;
      *addr = v8;
      if ( size >= 0xC )
      {
        *(_DWORD *)v8 = LODWORD(this->normal.x);
        v9 = (char *)*addr + 4;
        *addr = v9;
        *(float *)v9 = this->normal.y;
        v10 = (char *)*addr + 4;
        *addr = v10;
        *(float *)v10 = this->normal.z;
        *addr = (char *)*addr + 4;
      }
    }
    v11 = 0;
    if ( this->num_uvs )
    {
      do
      {
        v12 = &this->uvs[v11];
        if ( size >= 8 )
        {
          *(_DWORD *)*addr = LODWORD(v12->u);
          v13 = (char *)*addr + 4;
          *addr = v13;
          *(float *)v13 = v12->v;
          *addr = (char *)*addr + 4;
          result = retval;
        }
        ++v11;
      }
      while ( v11 < this->num_uvs );
    }
  }
  return result;
}

//----- (0053DE30) --------------------------------------------------------  // acclient.c:364845
void __thiscall CSWVertex::Destroy(CSWVertex *this)
{
  CSWVertex *v1; // esi@1
  CVec2Duv *v2; // eax@1

  v1 = this;
  v2 = this->uvs;
  if ( v2 )
  {
    operator delete[](&v2[-1].v);
    v1->uvs = 0;
  }
}

//----- (0053DE50) --------------------------------------------------------  // acclient.c:364860
int __thiscall CSWVertex::UnPack(CSWVertex *this, void **addr, unsigned int size)
{
  CSWVertex *v3; // edi@1
  CVec2Duv *v4; // eax@1
  int v5; // ebp@1
  char *v6; // eax@3
  char *v7; // ebx@3
  char *v8; // ebx@4
  char *v9; // edx@4
  char *v10; // eax@4
  char *v11; // edx@5
  char *v12; // ecx@5
  unsigned __int16 v13; // ax@6
  int v14; // ebx@7
  void *v15; // eax@7
  signed int v16; // eax@9
  bool v17; // zf@9
  CVec2Duv *v18; // ecx@10
  char *v19; // edx@10

  v3 = this;
  v4 = this->uvs;
  v5 = 0;
  if ( v4 )
  {
    operator delete[](&v4[-1].v);
    v3->uvs = 0;
  }
  v3->vert_id = *(_WORD *)*addr;
  v6 = (char *)*addr + 2;
  *addr = v6;
  v3->num_uvs = *(_WORD *)v6;
  v7 = (char *)*addr + 2;
  *addr = v7;
  if ( size >= 0xC )
  {
    LODWORD(v3->x) = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(v3->y) = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LODWORD(v3->z) = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    if ( size >= 0xC )
    {
      LODWORD(v3->normal.x) = *(_DWORD *)v10;
      v11 = (char *)*addr + 4;
      *addr = v11;
      LODWORD(v3->normal.y) = *(_DWORD *)v11;
      v12 = (char *)*addr + 4;
      *addr = v12;
      LODWORD(v3->normal.z) = *(_DWORD *)v12;
      *addr = (char *)*addr + 4;
    }
  }
  v13 = v3->num_uvs;
  if ( v13 )
  {
    v14 = v13;
    v15 = operator new[](8 * v13 + 4);
    if ( v15 )
    {
      v5 = (int)((char *)v15 + 4);
      *(_DWORD *)v15 = v14;
      vector_constructor_iterator(
        (char *)v15 + 4,
        8u,
        v14,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
    }
    v16 = 0;
    v17 = v3->num_uvs == 0;
    v3->uvs = (CVec2Duv *)v5;
    if ( !v17 )
    {
      do
      {
        v18 = v3->uvs;
        LODWORD(v18[v16].u) = *(_DWORD *)*addr;
        v19 = (char *)*addr + 4;
        *addr = v19;
        LODWORD(v18[v16].v) = *(_DWORD *)v19;
        *addr = (char *)*addr + 4;
        ++v16;
      }
      while ( v16 < v3->num_uvs );
    }
  }
  return 1;
}

