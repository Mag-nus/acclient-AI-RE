/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderMeshFragment
   Object     : ENGINE\render_base\RenderMeshFragment.obj
   Functions  : 199
   Addresses  : 0044D920 - 0074BF20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044D920) --------------------------------------------------------  // acclient.c:138737
signed int __thiscall SmartArray<Vector3,1>::WhatNum(SmartArray<Vector3,1> *this, Vector3 *i_rData)
{
  unsigned int v2; // edi@1
  signed int v3; // edx@1
  Vector3 *v4; // ecx@2
  signed int result; // eax@7

  v2 = this->m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_data;
    while ( fabs(v4->x - i_rData->x) > 0.00019999999
         || fabs(v4->y - i_rData->y) > 0.00019999999
         || fabs(v4->z - i_rData->z) > 0.00019999999 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_7;
    }
    result = v3;
  }
  else
  {
LABEL_7:
    result = -1;
  }
  return result;
}

//----- (0044D990) --------------------------------------------------------  // acclient.c:138769
void __thiscall RenderMeshFragmentTopology::TopTriangleType::Serialize(RenderMeshFragmentTopology::TopTriangleType *this, Archive *io_archive)
{
  RenderMeshFragmentTopology::TopTriangleType *v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@6

  v2 = this;
  v3 = 0;
  do
  {
    Archive::CheckAlignment(io_archive, 2u);
    v4 = Archive::GetBytes(io_archive, 2u);
    if ( v4 )
    {
      if ( io_archive->m_flags & 1 )
        *(_WORD *)v4 = v2->m_TopVertexIndices[v3];
      else
        v2->m_TopVertexIndices[v3] = *(_WORD *)v4;
    }
    Archive::CheckAlignment(io_archive, 2u);
    v5 = Archive::GetBytes(io_archive, 2u);
    if ( v5 )
    {
      if ( io_archive->m_flags & 1 )
        *(_WORD *)v5 = v2->m_TopEdgeIndices[v3];
      else
        v2->m_TopEdgeIndices[v3] = *(_WORD *)v5;
    }
    ++v3;
  }
  while ( v3 < 3 );
}

//----- (0044DA10) --------------------------------------------------------  // acclient.c:138804
void __thiscall RenderMeshFragmentTopology::TopEdgeType::Serialize(RenderMeshFragmentTopology::TopEdgeType *this, Archive *io_archive)
{
  RenderMeshFragmentTopology::TopEdgeType *v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@6

  v2 = this;
  v3 = 0;
  do
  {
    Archive::CheckAlignment(io_archive, 2u);
    v4 = Archive::GetBytes(io_archive, 2u);
    if ( v4 )
    {
      if ( io_archive->m_flags & 1 )
        *(_WORD *)v4 = v2->m_TopVertexIndices[v3];
      else
        v2->m_TopVertexIndices[v3] = *(_WORD *)v4;
    }
    Archive::CheckAlignment(io_archive, 2u);
    v5 = Archive::GetBytes(io_archive, 2u);
    if ( v5 )
    {
      if ( io_archive->m_flags & 1 )
        *(_WORD *)v5 = v2->m_NeighbourTopTriangleIndices[v3];
      else
        v2->m_NeighbourTopTriangleIndices[v3] = *(_WORD *)v5;
    }
    ++v3;
  }
  while ( v3 < 2 );
}

//----- (0044DA90) --------------------------------------------------------  // acclient.c:138839
void __thiscall SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::Reset(SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *this)
{
  SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4
  SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *v5; // [sp+0h] [bp-4h]@1

  v5 = this;
  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v1->m_data[i + 1] = (RenderMeshFragmentTopology::TopVertexType)v5 )
      --i;
  }
}

//----- (0044DAF0) --------------------------------------------------------  // acclient.c:138866
char __thiscall SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::grow(SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *this, unsigned int i_nSize)
{
  SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *v2; // esi@1
  void *v4; // ebx@5
  int i; // eax@7

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + i + 1) = v2->m_data[i + 1] )
          --i;
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (RenderMeshFragmentTopology::TopVertexType *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0044DB90) --------------------------------------------------------  // acclient.c:138901
char __thiscall SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::SetNElements(SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *this, const unsigned int i_nSize, int i_bGrowExactly)
{
  SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int i; // eax@7

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
      this->m_data[i] = (RenderMeshFragmentTopology::TopVertexType)i_bGrowExactly;
    goto LABEL_9;
  }
  if ( (_BYTE)i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::grow(v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (0044DBF0) --------------------------------------------------------  // acclient.c:138930
char __thiscall SmartArray<Vector3,1>::grow(SmartArray<Vector3,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebx@1
  SmartArray<Vector3,1> *v3; // esi@1
  void *v5; // eax@5
  Vector3 *v6; // edi@5
  int v7; // ecx@7
  int v8; // eax@8
  int v9; // edx@9
  int v10; // ecx@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@8

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<gmCombatPanelUI::PanelChildInfo,1>::Reset((SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)this);
      return 1;
    }
    v5 = operator new[](12 * i_nSize);
    v6 = (Vector3 *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0xCu,
        i_nSize,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v3->m_data )
      {
        v7 = v3->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          i_nSizea = v3->m_num;
          do
          {
            v9 = (int)&v3->m_data[v8];
            v10 = (int)&v6[v8];
            *(_DWORD *)v10 = *(_DWORD *)v9;
            *(_DWORD *)(v10 + 4) = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v10 + 8) = *(_DWORD *)(v9 + 8);
            --v8;
            --i_nSizea;
          }
          while ( i_nSizea );
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v3->m_data);
      }
      v3->m_data = v6;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0044DCC0) --------------------------------------------------------  // acclient.c:138993
void __thiscall RenderMeshFragmentTopology::TopBatchType::TopBatchType(RenderMeshFragmentTopology::TopBatchType *this)
{
  this->m_BatchVertexToTopVertexIndices.m_data = 0;
  this->m_BatchVertexToTopVertexIndices.m_sizeAndDeallocate = 0;
  this->m_BatchVertexToTopVertexIndices.m_num = 0;
}

//----- (0044DCD0) --------------------------------------------------------  // acclient.c:139001
void __thiscall SmartArray<unsigned short,1>::Reset(SmartArray<unsigned short,1> *this)
{
  SmartArray<unsigned short,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v1->m_data[i + 1] = 0 )
      --i;
  }
}

//----- (0044DD30) --------------------------------------------------------  // acclient.c:139026
void __thiscall RenderMeshFragment::RenderMeshFragment(RenderMeshFragment *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)RenderMeshFragment::vftable;
  this->m_Type = 0;
  this->m_MaterialBatches.m_data = 0;
  this->m_MaterialBatches.m_sizeAndDeallocate = 0;
  this->m_MaterialBatches.m_num = 0;
  this->m_pTopology = 0;
  this->m_AttribID = -1;
}
// 79B340: using guessed type int (__thiscall *RenderMeshFragment::vftable[2])(void *, char);

//----- (0044DD60) --------------------------------------------------------  // acclient.c:139040
void __thiscall RenderMeshFragment::~RenderMeshFragment(RenderMeshFragment *this)
{
  RenderMeshFragment *v1; // esi@1
  RenderMeshFragmentTopology *v2; // ecx@1
  bool v3; // zf@2
  unsigned int i; // edi@5
  RenderMeshBatch *v5; // ecx@6
  unsigned int v6; // eax@11
  unsigned int v7; // ecx@11
  int j; // eax@14

  v1 = this;
  v2 = this->m_pTopology;
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)RenderMeshFragment::vftable;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pTopology = 0;
  }
  for ( i = 0; i < v1->m_MaterialBatches.m_num; ++i )
  {
    v5 = v1->m_MaterialBatches.m_data[i];
    if ( v5 )
    {
      v3 = v5->m_cRef-- == 1;
      if ( v3 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      v1->m_MaterialBatches.m_data[i] = 0;
    }
  }
  v6 = v1->m_MaterialBatches.m_sizeAndDeallocate;
  v7 = v1->m_MaterialBatches.m_sizeAndDeallocate & 0x80000000;
  v1->m_MaterialBatches.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_MaterialBatches.m_data);
    v1->m_MaterialBatches.m_data = 0;
    v1->m_MaterialBatches.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_MaterialBatches.m_data )
  {
    for ( j = (v6 & 0x7FFFFFFF) - 1; j >= 0; v1->m_MaterialBatches.m_data[j + 1] = 0 )
      --j;
  }
  v1->m_Type = 0;
  if ( (v1->m_MaterialBatches.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_MaterialBatches.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 79B340: using guessed type int (__thiscall *RenderMeshFragment::vftable[2])(void *, char);

//----- (0044DE30) --------------------------------------------------------  // acclient.c:139095
void __thiscall RenderMeshFragmentTopology::~RenderMeshFragmentTopology(RenderMeshFragmentTopology *this)
{
  RenderMeshFragmentTopology *v1; // esi@1

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderMeshFragmentTopology::vftable;
  if ( (this->m_TopEdges.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_TopEdges.m_data);
  if ( (v1->m_TopTriangles.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_TopTriangles.m_data);
  if ( (v1->m_TopVertices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_TopVertices.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 79B344: using guessed type int (__thiscall *RenderMeshFragmentTopology::vftable)(void *, char);

//----- (0044DEA0) --------------------------------------------------------  // acclient.c:139113
void __thiscall SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::Serialize(SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *this, Archive *io_rcArchive)
{
  SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@1
  int v6; // edi@10
  unsigned int v7; // eax@10
  unsigned int v8; // eax@14

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  v5 = 0;
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::SetNElements(v2, v3, 1);
  }
  if ( v2->m_num )
  {
    do
    {
      v6 = (int)&v2->m_data[v5];
      Archive::CheckAlignment(io_rcArchive, 1u);
      v7 = Archive::GetBytes(io_rcArchive, 1u);
      if ( v7 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_BYTE *)v7 = *(_BYTE *)v6;
        else
          *(_BYTE *)v6 = *(_BYTE *)v7;
      }
      Archive::CheckAlignment(io_rcArchive, 2u);
      v8 = Archive::GetBytes(io_rcArchive, 2u);
      if ( v8 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_WORD *)v8 = *(_WORD *)(v6 + 2);
        else
          *(_WORD *)(v6 + 2) = *(_WORD *)v8;
      }
      ++v5;
    }
    while ( v5 < v2->m_num );
  }
}

//----- (0044E0D0) --------------------------------------------------------  // acclient.c:139271
char __thiscall SmartArray<unsigned short,1>::grow(SmartArray<unsigned short,1> *this, unsigned int i_nSize)
{
  SmartArray<unsigned short,1> *v2; // esi@1
  void *v4; // ebx@5
  int i; // eax@7

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<unsigned short,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](2 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_WORD *)v4 + i + 1) = v2->m_data[i + 1] )
          --i;
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (unsigned __int16 *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0044E170) --------------------------------------------------------  // acclient.c:139306
char __thiscall SmartArray<RenderMeshFragmentTopology::TopTriangleType,1>::SetNElements(SmartArray<RenderMeshFragmentTopology::TopTriangleType,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<RenderMeshFragmentTopology::TopTriangleType,1> *v3; // esi@1
  const unsigned int v4; // edi@1
  unsigned int v5; // eax@3
  char result; // al@5
  const unsigned int v7; // ecx@7
  const unsigned int v8; // eax@8
  int v9; // ebp@9
  int v10; // [sp+8h] [bp-Ch]@0
  int v11; // [sp+Ch] [bp-8h]@0
  int v12; // [sp+10h] [bp-4h]@0

  v3 = this;
  v4 = i_nSize;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v7 = i_nSize;
    if ( i_nSize < v3->m_num )
    {
      v8 = i_nSize;
      do
      {
        v9 = (int)&v3->m_data[v8];
        *(_DWORD *)v9 = v10;
        *(_DWORD *)(v9 + 4) = v11;
        *(_DWORD *)(v9 + 8) = v12;
        ++v7;
        ++v8;
      }
      while ( v7 < v3->m_num );
      v4 = i_nSize;
    }
    goto LABEL_11;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<gmCombatPanelUI::PanelChildInfo,1>::grow((SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)v3, v5);
  if ( result )
  {
LABEL_11:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}

//----- (0044E280) --------------------------------------------------------  // acclient.c:139389
SmartArray<unsigned short,1> *__thiscall SmartArray<unsigned short,1>::operator=(SmartArray<unsigned short,1> *this, int a2)
{
  SmartArray<unsigned short,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  unsigned __int16 *v5; // ecx@3
  unsigned int i; // eax@5

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<unsigned short,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 2 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        *v5 = *(_WORD *)v3;
        v3 += 2;
        ++v5;
      }
      while ( v3 < v4 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
      v2->m_data[i] = 0;
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (0044E310) --------------------------------------------------------  // acclient.c:139422
RenderMeshFragment *__thiscall RenderMeshFragment::vector_deleting_destructor(RenderMeshFragment *this, unsigned int a2)
{
  RenderMeshFragment *v2; // esi@1

  v2 = this;
  RenderMeshFragment::~RenderMeshFragment(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044E330) --------------------------------------------------------  // acclient.c:139434
RenderMeshFragmentTopology *__thiscall RenderMeshFragmentTopology::vector_deleting_destructor(RenderMeshFragmentTopology *this, unsigned int a2)
{
  RenderMeshFragmentTopology *v2; // esi@1

  v2 = this;
  RenderMeshFragmentTopology::~RenderMeshFragmentTopology(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044E350) --------------------------------------------------------  // acclient.c:139446
void __thiscall SmartArray<RenderMeshFragmentTopology::TopTriangleType,1>::Serialize(SmartArray<RenderMeshFragmentTopology::TopTriangleType,1> *this, Archive *io_rcArchive)
{
  SmartArray<RenderMeshFragmentTopology::TopTriangleType,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  int v5; // ebp@1
  unsigned int i; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  v5 = 0;
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<RenderMeshFragmentTopology::TopTriangleType,1>::SetNElements(v2, v3, 1);
  }
  for ( i = 0; i < v2->m_num; ++v5 )
  {
    RenderMeshFragmentTopology::TopTriangleType::Serialize(&v2->m_data[v5], io_rcArchive);
    ++i;
  }
}

//----- (0044E3E0) --------------------------------------------------------  // acclient.c:139484
void __thiscall SmartArray<RenderMeshFragmentTopology::TopEdgeType,1>::Serialize(SmartArray<RenderMeshFragmentTopology::TopEdgeType,1> *this, Archive *io_rcArchive)
{
  SmartArray<RenderMeshFragmentTopology::TopEdgeType,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<LOAD_WEIGHTS,1>::SetNElements((SmartArray<LOAD_WEIGHTS,1> *)v2, v3, 1);
  }
  v5 = 0;
  if ( v2->m_num )
  {
    do
      RenderMeshFragmentTopology::TopEdgeType::Serialize(&v2->m_data[v5++], io_rcArchive);
    while ( v5 < v2->m_num );
  }
}

//----- (0044E470) --------------------------------------------------------  // acclient.c:139522
void *__thiscall RenderMeshFragmentTopology::TopBatchType::vector_deleting_destructor(RenderMeshFragmentTopology::TopBatchType *this, unsigned int a2)
{
  RenderMeshFragmentTopology::TopBatchType *v2; // esi@1
  unsigned int v3; // ecx@2
  void *v4; // edi@2
  int v5; // eax@2
  int v6; // ecx@2
  void **v7; // esi@3
  int v8; // ebp@3
  int v9; // eax@4
  void *result; // eax@9

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].m_BatchVertexToTopVertexIndices.m_num;
    v4 = &v2[-1].m_BatchVertexToTopVertexIndices.m_num;
    v5 = (int)&v2[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = (void **)(v5 + 4);
      v8 = v6 + 1;
      do
      {
        v9 = (int)*(v7 - 3);
        v7 -= 4;
        if ( (v9 & 0x80000000) == 0x80000000 )
          operator delete[](*v7);
        --v8;
      }
      while ( v8 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    if ( (this->m_BatchVertexToTopVertexIndices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](this->m_BatchVertexToTopVertexIndices.m_data);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (0044E500) --------------------------------------------------------  // acclient.c:139571
void __thiscall SmartArray<RenderMeshFragmentTopology::TopBatchType,1>::Reset(SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *this)
{
  SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // esi@7
  int v6; // ebx@7
  int v7; // eax@8
  int v8; // [sp+8h] [bp-10h]@0
  int v9; // [sp+Ch] [bp-Ch]@7
  int v10; // [sp+10h] [bp-8h]@7
  int v11; // [sp+14h] [bp-4h]@7

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      RenderMeshFragmentTopology::TopBatchType::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        v7 = (int)&v1->m_data[v5];
        *(_DWORD *)v7 = v8;
        SmartArray<unsigned short,1>::operator=((SmartArray<unsigned short,1> *)(v7 + 4), (int)&v9);
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (0044E590) --------------------------------------------------------  // acclient.c:139620
void __thiscall RenderMeshFragment::AddMaterialBatch(RenderMeshFragment *this, RenderMeshBatch *_pBatch)
{
  char *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2

  ++_pBatch->m_cRef;
  v2 = (char *)&this->m_MaterialBatches;
  v3 = this->m_MaterialBatches.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_MaterialBatches.m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v4)) )
    *(_DWORD *)(*(_DWORD *)v2 + 4 * (*((_DWORD *)v2 + 2))++) = _pBatch;
}

//----- (0044E5D0) --------------------------------------------------------  // acclient.c:139636
char __userpurge RenderMeshFragment::ParseFromFileNode@<al>(RenderMeshFragment *this@<ecx>, int a2@<edi>, PFileNode *_pBaseNode, RenderMesh *_pContainerMesh)
{
  RenderMeshFragment *v4; // ebp@1
  PFileNode *v5; // esi@2
  ReferenceCountTemplate<1048576,0>Vtbl *v6; // eax@5
  PFileNode *v7; // eax@5
  ReferenceCountTemplate<1048576,0>Vtbl *v8; // edx@7
  PFileNode *v9; // eax@7
  ReferenceCountTemplate<1048576,0>Vtbl *v10; // eax@9
  PFileNode *v11; // eax@9
  PStringBase<char> *v12; // ecx@9
  PStringBase<char> *v13; // ecx@11
  RenderMeshBatch *v14; // eax@12
  int v15; // eax@13
  PStringBase<char> *v16; // ecx@15
  bool v17; // zf@16
  int v18; // edx@17
  int v20; // eax@24
  int v21; // eax@25
  PStringBase<char> *v22; // [sp-4h] [bp-1Ch]@5
  PFileNodeIter iter; // [sp+Ch] [bp-Ch]@2

  v4 = this;
  if ( !_pBaseNode )
    return 0;
  PFileNodeIter::PFileNodeIter(&iter, _pBaseNode);
  v5 = PFileNodeIter::Curr(&iter);
  if ( !v5 )
  {
LABEL_20:
    PFileNodeIter::~PFileNodeIter(&iter);
    return 1;
  }
  while ( PFileNode::IsKeyword(v5, a2, &FragmentType_0) )
  {
    v4->m_Type = 0;
    if ( !PFileNode::GetNumSubNodes(v5) )
      goto LABEL_22;
    v6 = v5->vfptr;
    v22 = &FragmentType_LevelOfDetailModel_0;
    v7 = (PFileNode *)v6[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 0);
    if ( PFileNode::IsKeyword(v7, a2, v22) )
    {
      v4->m_Type = 1;
    }
    else
    {
      v8 = v5->vfptr;
      v22 = &FragmentType_OccludeModel_0;
      v9 = (PFileNode *)v8[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 0);
      if ( PFileNode::IsKeyword(v9, a2, v22) )
      {
        v4->m_Type = 2;
      }
      else
      {
        v10 = v5->vfptr;
        v22 = &FragmentType_ShadowLODModel_0;
        v11 = (PFileNode *)v10[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 0);
        if ( !PFileNode::IsKeyword(v11, a2, v22) )
        {
          v22 = v12;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22, "Unrecognized mesh fragment type");
          PFileNode::ReportError(a2, v5, (PStringBase<char>)v22);
          goto LABEL_22;
        }
        v4->m_Type = 4;
      }
    }
LABEL_19:
    v5 = (PFileNode *)PFileNodeIter::Next(&iter);
    if ( !v5 )
      goto LABEL_20;
  }
  if ( !PFileNode::IsKeyword(v5, a2, &MaterialBatch_0) )
  {
    v22 = v13;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22, "Unrecognized keyword in mesh file");
    PFileNode::ReportWarning(a2, v5, (PStringBase<char>)v22);
    goto LABEL_19;
  }
  v14 = (RenderMeshBatch *)operator new(0x34u);
  if ( v14 )
  {
    RenderMeshBatch::RenderMeshBatch(v14);
    a2 = v15;
  }
  else
  {
    a2 = 0;
  }
  *(_DWORD *)(a2 + 12) = _pContainerMesh;
  if ( RenderMeshBatch::ParseFromFileNode((RenderMeshBatch *)a2, a2, v5) )
  {
    RenderMeshFragment::AddMaterialBatch(v4, (RenderMeshBatch *)a2);
    v17 = (*(_DWORD *)(a2 + 4))-- == 1;
    if ( v17 )
    {
      v18 = *(_DWORD *)a2;
      v22 = (PStringBase<char> *)1;
      (*(void (__thiscall **)(int, signed int))v18)(a2, 1);
    }
    goto LABEL_19;
  }
  v22 = v16;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22, "Error parsing mesh batch");
  PFileNode::ReportError(a2, v5, (PStringBase<char>)v22);
  v20 = *(_DWORD *)(a2 + 4) - 1;
  *(_DWORD *)(a2 + 4) = v20;
  if ( v20 )
  {
LABEL_22:
    PFileNodeIter::~PFileNodeIter(&iter);
    return 0;
  }
  v21 = *(_DWORD *)a2;
  v22 = (PStringBase<char> *)1;
  (*(void (__thiscall **)(int, signed int))v21)(a2, 1);
  PFileNodeIter::~PFileNodeIter(&iter);
  return 0;
}

//----- (0044E7A0) --------------------------------------------------------  // acclient.c:139759
void __thiscall RenderMeshFragment::OrganizeMaterialBatches(RenderMeshFragment *this)
{
  RenderMeshFragment *v1; // edi@1
  char *v2; // esi@2
  unsigned int v3; // ebx@2
  bool v4; // zf@2
  RenderMeshBatch *v5; // edi@3
  unsigned int v6; // eax@3
  MaterialInstance *v7; // eax@4
  RenderMaterial *v8; // eax@5
  int v9; // ecx@7
  unsigned int v10; // eax@9
  int v11; // eax@11
  unsigned int v12; // eax@12
  unsigned int i; // eax@15
  RenderMeshBatch *v14; // edi@16
  int v15; // ecx@16
  unsigned int v16; // ecx@17
  SmartArray<RenderMeshBatch *,1> TransparentBatches; // [sp+8h] [bp-18h]@2
  SmartArray<RenderMeshBatch *,1> OriginalMaterialBatches; // [sp+14h] [bp-Ch]@2

  v1 = this;
  if ( !this->m_pTopology )
  {
    v2 = (char *)&this->m_MaterialBatches;
    OriginalMaterialBatches.m_data = 0;
    OriginalMaterialBatches.m_sizeAndDeallocate = 0;
    OriginalMaterialBatches.m_num = 0;
    SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)&OriginalMaterialBatches, (int)&this->m_MaterialBatches);
    v3 = 0;
    v4 = OriginalMaterialBatches.m_num == 0;
    v1->m_MaterialBatches.m_num = 0;
    TransparentBatches.m_data = 0;
    TransparentBatches.m_sizeAndDeallocate = 0;
    TransparentBatches.m_num = 0;
    if ( !v4 )
    {
      do
      {
        v5 = OriginalMaterialBatches.m_data[v3];
        v6 = v5->m_MaterialIndex;
        if ( v6 != -1
          && (v7 = v5->m_pContainerMesh->m_pMaterialArray->m_Materials.m_data[v6].second) != 0
          && (v8 = v7->m_pMaterial) != 0
          && v8->layers.m_num > 0
          && (v9 = **(_DWORD **)v8->layers.m_data, BYTE1(v9) & 1) )
        {
          if ( TransparentBatches.m_num < (TransparentBatches.m_sizeAndDeallocate & 0x7FFFFFFF)
            || (v10 = SmartArray<UIChildFramework *,1>::get_new_size((TransparentBatches.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
                SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&TransparentBatches, v10)) )
            TransparentBatches.m_data[TransparentBatches.m_num++] = v5;
        }
        else
        {
          v11 = *((_DWORD *)v2 + 1) & 0x7FFFFFFF;
          if ( *((_DWORD *)v2 + 2) < (unsigned int)v11
            || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
                SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v12)) )
            *(_DWORD *)(*(_DWORD *)v2 + 4 * (*((_DWORD *)v2 + 2))++) = v5;
        }
        ++v3;
      }
      while ( v3 < OriginalMaterialBatches.m_num );
    }
    SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, TransparentBatches.m_num + *((_DWORD *)v2 + 2));
    for ( i = TransparentBatches.m_num - 1; (i & 0x80000000) == 0; *(_DWORD *)(*(_DWORD *)v2 + 4 * v15) = v14 )
    {
      v14 = TransparentBatches.m_data[i];
      v15 = i-- + *((_DWORD *)v2 + 2);
    }
    v16 = TransparentBatches.m_sizeAndDeallocate;
    *((_DWORD *)v2 + 2) += TransparentBatches.m_num;
    if ( (v16 & 0x80000000) == 0x80000000 )
      operator delete[](TransparentBatches.m_data);
    if ( (OriginalMaterialBatches.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](OriginalMaterialBatches.m_data);
  }
}

//----- (0044E930) --------------------------------------------------------  // acclient.c:139839
void __thiscall RenderMeshFragment::GenerateAdjacencyGraph(RenderMeshFragment *this, SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *_TopBatches)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // esi@1
  RenderMeshFragmentTopology::TopBatchType *v4; // edi@2
  SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *v5; // edi@5
  int v6; // ebx@7
  RenderIndexBuffer *v7; // ecx@7
  char *v8; // ebp@8
  RenderMeshFragmentTopology *v9; // eax@10
  unsigned int v10; // edx@10
  unsigned int v11; // ecx@10
  int v12; // edi@10
  int v13; // eax@10
  unsigned int v14; // edx@11
  unsigned int v15; // ST30_4@16
  int v21; // eax@20
  int v22; // eax@23
  int v23; // eax@25
  int v24; // eax@26
  unsigned int v25; // edx@26
  int v26; // ecx@26
  RenderMeshFragmentTopology *v27; // esi@29
  unsigned int v28; // edx@29
  unsigned int v29; // eax@29
  RenderMeshFragmentTopology::TopEdgeType *v30; // ecx@30
  int v31; // eax@38
  unsigned int v32; // ebx@38
  unsigned int v33; // edx@39
  int v34; // ST3C_4@44
  int v36; // eax@48
  unsigned __int16 v37; // dx@51
  RenderMeshFragment *v38; // [sp+Ch] [bp-30h]@1
  unsigned int TopVertexIndexA; // [sp+10h] [bp-2Ch]@0
  unsigned int TopVertexIndexB; // [sp+14h] [bp-28h]@0
  char *v41; // [sp+18h] [bp-24h]@8
  unsigned int TopTriangleIndex; // [sp+1Ch] [bp-20h]@10
  RenderMeshFragmentTopology::TopBatchType *TopBatch; // [sp+20h] [bp-1Ch]@7
  int v44; // [sp+24h] [bp-18h]@6
  unsigned int i; // [sp+28h] [bp-14h]@20
  unsigned int v46; // [sp+2Ch] [bp-10h]@8
  unsigned int TopBatchIndex; // [sp+30h] [bp-Ch]@5
  RenderMeshFragmentTopology::TopTriangleType *TopTriangle; // [sp+38h] [bp-4h]@20

  v38 = this;
  v2 = _TopBatches->m_num;
  v3 = 0;
  if ( !v2 )
    return;
  v4 = _TopBatches->m_data;
  do
  {
    v3 += v4->m_pBatch->m_pContainerMesh->m_pIndicesArray->m_IndexArrays.m_data[v4->m_pBatch->m_IndexArrayIndex]->m_nNumIndices
        / 3;
    ++v4;
    --v2;
  }
  while ( v2 );
  if ( !v3 )
    return;
  SmartArray<gmCombatPanelUI::PanelChildInfo,1>::grow(
    (SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)&this->m_pTopology->m_TopTriangles,
    v3);
  SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v38->m_pTopology->m_TopEdges, 3 * v3);
  v5 = _TopBatches;
  TopBatchIndex = 0;
  if ( !_TopBatches->m_num )
    return;
  v44 = 0;
  do
  {
    v6 = (int)&v5->m_data[v44];
    v7 = v5->m_data[v44].m_pBatch->m_pContainerMesh->m_pIndicesArray->m_IndexArrays.m_data[v5->m_data[v44].m_pBatch->m_IndexArrayIndex];
    TopBatch = &v5->m_data[v44];
    if ( !(v7->m_nNumIndices / 3) )
      goto LABEL_53;
    v8 = v7->indices;
    v41 = v7->indices;
    v46 = v7->m_nNumIndices / 3;
    while ( 2 )
    {
      v9 = v38->m_pTopology;
      v10 = v9->m_TopTriangles.m_num;
      v11 = v9->m_TopTriangles.m_num;
      v12 = (int)&v9->m_TopTriangles;
      v13 = v9->m_TopTriangles.m_sizeAndDeallocate & 0x7FFFFFFF;
      TopTriangleIndex = v10;
      if ( v11 < v13 )
        goto LABEL_56;
      v14 = v13 + 1;
      if ( (unsigned int)(v13 + 1) > 8 )
      {
        if ( v14 <= 0x4000 )
        {
          v15 = v13 + 1;
          __asm { bsr     this, [esp+40h+i] }
          if ( v14 > 1 << _EAX )
            v14 = 2 * (1 << _EAX);
        }
        else if ( v14 & 0x3FFF )
        {
          v14 += 0x4000 - (v14 & 0x3FFF);
        }
      }
      else
      {
        v14 = 8;
      }
      if ( SmartArray<gmCombatPanelUI::PanelChildInfo,1>::grow((SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)v12, v14) )
LABEL_56:
        ++*(_DWORD *)(v12 + 8);
      v21 = 0;
      TopTriangle = &v38->m_pTopology->m_TopTriangles.m_data[TopTriangleIndex];
      i = 0;
      while ( 1 )
      {
        if ( !v21 )
        {
          v24 = *(_DWORD *)(v6 + 4);
          v25 = *(_WORD *)(v24 + 2 * *(_WORD *)v8);
          v26 = *((_WORD *)v8 + 1);
          goto LABEL_28;
        }
        v22 = v21 - 1;
        if ( !v22 )
        {
          v24 = *(_DWORD *)(v6 + 4);
          v25 = *(_WORD *)(v24 + 2 * *((_WORD *)v8 + 1));
          v26 = *((_WORD *)v8 + 2);
LABEL_28:
          TopVertexIndexA = v25;
          TopVertexIndexB = *(_WORD *)(v24 + 2 * v26);
          goto LABEL_29;
        }
        if ( v22 == 1 )
        {
          v23 = *(_DWORD *)(v6 + 4);
          TopVertexIndexA = *(_WORD *)(v23 + 2 * *((_WORD *)v8 + 2));
          TopVertexIndexB = *(_WORD *)(v23 + 2 * *(_WORD *)v8);
        }
LABEL_29:
        v27 = v38->m_pTopology;
        v28 = v27->m_TopEdges.m_num;
        v29 = 0;
        if ( v28 )
        {
          v30 = v27->m_TopEdges.m_data;
          while ( v30->m_TopVertexIndices[0] != TopVertexIndexB
               || v30->m_TopVertexIndices[1] != TopVertexIndexA
               || v30->m_NeighbourTopTriangleIndices[1] != -1 )
          {
            ++v29;
            ++v30;
            if ( v29 >= v28 )
              goto LABEL_37;
          }
          if ( v29 == 0xFFFF )
          {
LABEL_37:
            v8 = v41;
            goto LABEL_38;
          }
          v8 = v41;
          LOWORD(v32) = v29;
          v27->m_TopEdges.m_data[v29].m_NeighbourTopTriangleIndices[1] = TopTriangleIndex;
        }
        else
        {
LABEL_38:
          v31 = v27->m_TopEdges.m_sizeAndDeallocate & 0x7FFFFFFF;
          v32 = v27->m_TopEdges.m_num;
          if ( v27->m_TopEdges.m_num < v31 )
            goto LABEL_57;
          v33 = v31 + 1;
          if ( (unsigned int)(v31 + 1) > 8 )
          {
            if ( v33 <= 0x4000 )
            {
              v34 = v31 + 1;
              __asm { bsr     this, [esp+40h+var_8] }
              if ( v33 > 1 << _EAX )
                v33 = 2 * (1 << _EAX);
            }
            else if ( v33 & 0x3FFF )
            {
              v33 += 0x4000 - (v33 & 0x3FFF);
            }
          }
          else
          {
            v33 = 8;
          }
          if ( SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v27->m_TopEdges, v33) )
LABEL_57:
            ++v27->m_TopEdges.m_num;
          v36 = (int)&v38->m_pTopology->m_TopEdges.m_data[v32];
          *(_WORD *)v36 = TopVertexIndexA;
          *(_WORD *)(v36 + 2) = TopVertexIndexB;
          *(_WORD *)(v36 + 4) = TopTriangleIndex;
          *(_WORD *)(v36 + 6) = -1;
        }
        TopTriangle->m_TopEdgeIndices[i] = v32;
        v21 = i + 1;
        i = v21;
        if ( (unsigned int)v21 >= 3 )
          break;
        v6 = (int)TopBatch;
      }
      TopTriangle->m_TopVertexIndices[0] = TopBatch->m_BatchVertexToTopVertexIndices.m_data[*(_WORD *)v8];
      TopTriangle->m_TopVertexIndices[1] = TopBatch->m_BatchVertexToTopVertexIndices.m_data[*((_WORD *)v8 + 1)];
      v37 = TopBatch->m_BatchVertexToTopVertexIndices.m_data[*((_WORD *)v8 + 2)];
      v8 += 6;
      _ZF = v46 == 1;
      TopTriangle->m_TopVertexIndices[2] = v37;
      v41 = v8;
      --v46;
      if ( !_ZF )
      {
        v6 = (int)TopBatch;
        continue;
      }
      break;
    }
    v5 = _TopBatches;
LABEL_53:
    _CF = TopBatchIndex++ + 1 < v5->m_num;
    ++v44;
  }
  while ( _CF );
}

//----- (0044EC70) --------------------------------------------------------  // acclient.c:140071
char __thiscall SmartArray<RenderMeshFragmentTopology::TopBatchType,1>::grow(SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *v3; // ebx@1
  void *v5; // eax@5
  int v6; // edi@6
  int v7; // eax@8
  int v8; // esi@9
  int v9; // ST08_4@10
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<RenderMeshFragmentTopology::TopBatchType,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x10u,
        i_nSize,
        (void *(__thiscall *)(void *))RenderMeshFragmentTopology::TopBatchType::TopBatchType);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              v9 = (int)&v3->m_data[v8].m_BatchVertexToTopVertexIndices;
              *(_DWORD *)(v8 * 16 + v6) = v3->m_data[v8].m_pBatch;
              SmartArray<unsigned short,1>::operator=((SmartArray<unsigned short,1> *)(v8 * 16 + v6 + 4), v9);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              RenderMeshFragmentTopology::TopBatchType::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (RenderMeshFragmentTopology::TopBatchType *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (0044ED50) --------------------------------------------------------  // acclient.c:140138
void __thiscall RenderMeshFragment::Serialize(RenderMeshFragment *this, Archive *io_archive, RenderMesh *_pContainerMesh)
{
  Archive *v3; // edi@1
  RenderMeshFragment *v4; // ebx@1
  unsigned int v5; // eax@1
  Archive *v6; // esi@5
  unsigned int v7; // eax@5
  unsigned int v8; // ebp@9
  int v9; // esi@10
  RenderMeshBatch *v10; // eax@12
  int v11; // eax@13
  int v12; // ebx@13
  int v13; // eax@15
  unsigned int v14; // eax@16
  bool v15; // bl@20
  unsigned int v16; // eax@20
  void *v17; // eax@30
  RenderMeshFragmentTopology *v18; // esi@34
  RenderMeshFragment *v19; // [sp+0h] [bp-4h]@1
  Archive *io_archivea; // [sp+8h] [bp+4h]@5

  v3 = io_archive;
  v4 = this;
  v19 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v4->m_Type;
    else
      v4->m_Type = *(_DWORD *)v5;
  }
  v6 = (Archive *)v4->m_MaterialBatches.m_num;
  io_archivea = (Archive *)v4->m_MaterialBatches.m_num;
  Archive::CheckAlignment(v3, 4u);
  v7 = Archive::GetBytes(v3, 4u);
  if ( v7 )
  {
    if ( v3->m_flags & 1 )
    {
      *(_DWORD *)v7 = v6;
    }
    else
    {
      io_archivea = *(Archive **)v7;
      v6 = *(Archive **)v7;
    }
  }
  v8 = 0;
  if ( v6 )
  {
    v9 = (int)&v4->m_MaterialBatches;
    do
    {
      if ( ~LOBYTE(v3->m_flags) & 1 )
      {
        v10 = (RenderMeshBatch *)operator new(0x34u);
        if ( v10 )
        {
          RenderMeshBatch::RenderMeshBatch(v10);
          v12 = v11;
        }
        else
        {
          v12 = 0;
        }
        v13 = *(_DWORD *)(v9 + 4) & 0x7FFFFFFF;
        if ( *(_DWORD *)(v9 + 8) < (unsigned int)v13
          || (v14 = SmartArray<UIChildFramework *,1>::get_new_size(v13 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v9, v14)) )
          *(_DWORD *)(*(_DWORD *)v9 + 4 * (*(_DWORD *)(v9 + 8))++) = v12;
        v4 = v19;
      }
      RenderMeshBatch::Serialize(*(RenderMeshBatch **)(*(_DWORD *)v9 + 4 * v8++), v3, _pContainerMesh);
    }
    while ( v8 < (unsigned int)io_archivea );
  }
  v15 = v4->m_pTopology != 0;
  Archive::CheckAlignment(v3, 1u);
  v16 = Archive::GetBytes(v3, 1u);
  if ( v16 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v16 = v15;
    else
      v15 = *(_BYTE *)v16;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( !v15 )
      return;
    if ( v15 != 1 )
      Archive::RaiseError(v3);
  }
  if ( v15 )
  {
    if ( ~LOBYTE(v3->m_flags) & 1 )
    {
      v17 = operator new(0x2Cu);
      if ( v17 )
      {
        *((_DWORD *)v17 + 1) = 1;
        *(_DWORD *)v17 = &RenderMeshFragmentTopology::vftable;
        *((_DWORD *)v17 + 2) = 0;
        *((_DWORD *)v17 + 3) = 0;
        *((_DWORD *)v17 + 4) = 0;
        *((_DWORD *)v17 + 5) = 0;
        *((_DWORD *)v17 + 6) = 0;
        *((_DWORD *)v17 + 7) = 0;
        *((_DWORD *)v17 + 8) = 0;
        *((_DWORD *)v17 + 9) = 0;
        *((_DWORD *)v17 + 10) = 0;
      }
      else
      {
        v17 = 0;
      }
      v19->m_pTopology = (RenderMeshFragmentTopology *)v17;
    }
    v18 = v19->m_pTopology;
    SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::Serialize(&v18->m_TopVertices, v3);
    SmartArray<RenderMeshFragmentTopology::TopTriangleType,1>::Serialize(&v18->m_TopTriangles, v3);
    SmartArray<RenderMeshFragmentTopology::TopEdgeType,1>::Serialize(&v18->m_TopEdges, v3);
  }
}
// 79B344: using guessed type int (__thiscall *RenderMeshFragmentTopology::vftable)(void *, char);

//----- (0044EEF0) --------------------------------------------------------  // acclient.c:140267
void __thiscall RenderMeshFragment::GenerateTopologyVertices(RenderMeshFragment *this, SmartArray<Vector3,1> *_WeldedPoints, SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *_TopBatches)
{
  int v3; // eax@1
  RenderMeshBatch *v4; // esi@2
  unsigned int v5; // eax@2
  MaterialInstance *v6; // eax@3
  RenderVertexBuffer *v7; // edi@6
  SmartArray<RenderMeshFragmentTopology::TopBatchType,1> *v8; // ecx@6
  unsigned int v9; // eax@6
  unsigned int v10; // eax@7
  RenderMeshFragmentTopology::TopBatchType *v11; // eax@10
  unsigned int v12; // ebx@10
  void *v13; // edx@13
  int v14; // esi@13
  SmartArray<Vector3,1> *v15; // edi@13
  int v16; // esi@13
  signed int v17; // eax@13
  unsigned int v18; // ebp@13
  unsigned int v19; // eax@14
  unsigned int v20; // edx@15
  int v21; // ST24_4@20
  int v27; // ecx@25
  RenderMeshFragmentTopology *v28; // eax@26
  int v29; // edi@26
  unsigned int v30; // ecx@26
  int v31; // eax@26
  unsigned int v32; // edx@27
  int v33; // ST24_4@32
  int v35; // eax@36
  unsigned int v36; // edx@37
  int v37; // ST24_4@42
  RenderMeshFragment *v39; // [sp+0h] [bp-18h]@1
  unsigned int BatchIndex; // [sp+4h] [bp-14h]@1
  RenderMeshFragmentTopology::TopVertexType TopVertex; // [sp+8h] [bp-10h]@0
  RenderVertexBuffer *pVertexArray; // [sp+Ch] [bp-Ch]@6
  SmartArray<unsigned short,1> *v43; // [sp+14h] [bp-4h]@11

  v39 = this;
  v3 = 0;
  BatchIndex = 0;
  if ( this->m_MaterialBatches.m_num )
  {
    while ( 1 )
    {
      v4 = this->m_MaterialBatches.m_data[v3];
      v5 = v4->m_MaterialIndex;
      if ( v5 != -1 )
      {
        v6 = v4->m_pContainerMesh->m_pMaterialArray->m_Materials.m_data[v5].second;
        if ( v6 )
        {
          if ( !v6->m_AllowStencilShadows || v6->m_WantDiscardGeometry )
            goto LABEL_48;
        }
      }
      v7 = v4->m_pContainerMesh->m_pVerticesArray->m_VertexArrays.m_data[v4->m_VertexArrayIndex];
      v8 = _TopBatches;
      v9 = _TopBatches->m_sizeAndDeallocate & 0x7FFFFFFF;
      pVertexArray = v4->m_pContainerMesh->m_pVerticesArray->m_VertexArrays.m_data[v4->m_VertexArrayIndex];
      if ( _TopBatches->m_num < v9 )
        goto LABEL_9;
      v10 = SmartArray<UIChildFramework *,1>::get_new_size(v9 + 1);
      if ( SmartArray<RenderMeshFragmentTopology::TopBatchType,1>::grow(_TopBatches, v10) )
        break;
LABEL_10:
      v11 = &_TopBatches->m_data[_TopBatches->m_num - 1];
      v11->m_pBatch = v4;
      v12 = 0;
      if ( v7->numVertices )
      {
        v43 = &v11->m_BatchVertexToTopVertexIndices;
        while ( 2 )
        {
          v13 = v7->vertices;
          v14 = v12 * v7->vertexFormat.size;
          v15 = _WeldedPoints;
          v16 = (int)((char *)v13 + v14);
          v17 = SmartArray<Vector3,1>::WhatNum(_WeldedPoints, (Vector3 *)v16);
          LOWORD(v18) = v17;
          if ( v17 != -1 )
            goto LABEL_36;
          v19 = _WeldedPoints->m_sizeAndDeallocate & 0x7FFFFFFF;
          if ( _WeldedPoints->m_num < v19 )
          {
LABEL_25:
            v27 = (int)&v15->m_data[v15->m_num];
            *(_DWORD *)v27 = *(_DWORD *)v16;
            *(_DWORD *)(v27 + 4) = *(_DWORD *)(v16 + 4);
            *(_DWORD *)(v27 + 8) = *(_DWORD *)(v16 + 8);
            ++_WeldedPoints->m_num;
          }
          else
          {
            v20 = v19 + 1;
            if ( v19 + 1 > 8 )
            {
              if ( v20 <= 0x4000 )
              {
                v21 = v19 + 1;
                __asm { bsr     this, [esp+28h+var_8] }
                if ( v20 > 1 << _EAX )
                  v20 = 2 * (1 << _EAX);
                v15 = _WeldedPoints;
              }
              else if ( v20 & 0x3FFF )
              {
                v20 += 0x4000 - (v20 & 0x3FFF);
              }
            }
            else
            {
              v20 = 8;
            }
            if ( SmartArray<Vector3,1>::grow(v15, v20) )
            {
              v15 = _WeldedPoints;
              goto LABEL_25;
            }
          }
          v28 = v39->m_pTopology;
          v18 = v28->m_TopVertices.m_num;
          v29 = (int)&v28->m_TopVertices;
          TopVertex.m_BatchIndex = BatchIndex;
          v30 = v28->m_TopVertices.m_num;
          v31 = v28->m_TopVertices.m_sizeAndDeallocate & 0x7FFFFFFF;
          TopVertex.m_VertexIndex = v12;
          if ( v30 < v31 )
            goto LABEL_51;
          v32 = v31 + 1;
          if ( (unsigned int)(v31 + 1) > 8 )
          {
            if ( v32 <= 0x4000 )
            {
              v33 = v31 + 1;
              __asm { bsr     this, [esp+28h+var_8] }
              if ( v32 > 1 << _EAX )
                v32 = 2 * (1 << _EAX);
            }
            else if ( v32 & 0x3FFF )
            {
              v32 += 0x4000 - (v32 & 0x3FFF);
            }
          }
          else
          {
            v32 = 8;
          }
          if ( SmartArray<RenderMeshFragmentTopology::TopVertexType,1>::grow(
                 (SmartArray<RenderMeshFragmentTopology::TopVertexType,1> *)v29,
                 v32) )
LABEL_51:
            *(_DWORD *)(*(_DWORD *)v29 + 4 * (*(_DWORD *)(v29 + 8))++) = TopVertex;
LABEL_36:
          v35 = v43->m_sizeAndDeallocate & 0x7FFFFFFF;
          if ( v43->m_num < v35 )
            goto LABEL_52;
          v36 = v35 + 1;
          if ( (unsigned int)(v35 + 1) > 8 )
          {
            if ( v36 <= 0x4000 )
            {
              v37 = v35 + 1;
              __asm { bsr     this, [esp+28h+var_8] }
              if ( v36 > 1 << _EAX )
                v36 = 2 * (1 << _EAX);
            }
            else if ( v36 & 0x3FFF )
            {
              v36 += 0x4000 - (v36 & 0x3FFF);
            }
          }
          else
          {
            v36 = 8;
          }
          if ( SmartArray<unsigned short,1>::grow(v43, v36) )
LABEL_52:
            v43->m_data[v43->m_num++] = v18;
          ++v12;
          if ( v12 >= pVertexArray->numVertices )
            break;
          v7 = pVertexArray;
          continue;
        }
      }
      this = v39;
LABEL_48:
      v3 = BatchIndex++ + 1;
      if ( BatchIndex >= this->m_MaterialBatches.m_num )
        return;
    }
    v8 = _TopBatches;
LABEL_9:
    ++v8->m_num;
    goto LABEL_10;
  }
}

//----- (0044F1A0) --------------------------------------------------------  // acclient.c:140466
void __thiscall RenderMeshFragment::GenerateTopology(RenderMeshFragment *this)
{
  RenderMeshFragment *v1; // edi@1
  RenderMeshFragmentTopology *v2; // ecx@1
  bool v3; // zf@2
  void *v4; // eax@5
  SmartArray<RenderMeshFragmentTopology::TopBatchType,1> TopBatches; // [sp+8h] [bp-18h]@8
  SmartArray<Vector3,1> WeldedPoints; // [sp+14h] [bp-Ch]@8

  v1 = this;
  v2 = this->m_pTopology;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pTopology = 0;
  }
  v4 = operator new(0x2Cu);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = &RenderMeshFragmentTopology::vftable;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 8) = 0;
    *((_DWORD *)v4 + 9) = 0;
    *((_DWORD *)v4 + 10) = 0;
  }
  else
  {
    v4 = 0;
  }
  v1->m_pTopology = (RenderMeshFragmentTopology *)v4;
  TopBatches.m_data = 0;
  TopBatches.m_sizeAndDeallocate = 0;
  TopBatches.m_num = 0;
  WeldedPoints.m_data = 0;
  WeldedPoints.m_sizeAndDeallocate = 0;
  WeldedPoints.m_num = 0;
  RenderMeshFragment::GenerateTopologyVertices(v1, &WeldedPoints, &TopBatches);
  RenderMeshFragment::GenerateAdjacencyGraph(v1, &TopBatches);
  if ( (WeldedPoints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](WeldedPoints.m_data);
  if ( (TopBatches.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( (_DWORD)TopBatches.m_data )
      RenderMeshFragmentTopology::TopBatchType::vector_deleting_destructor(TopBatches.m_data, 3u);
  }
}
// 79B344: using guessed type int (__thiscall *RenderMeshFragmentTopology::vftable)(void *, char);

//----- (006DDFF0) --------------------------------------------------------  // acclient.c:755360
int _E73_49()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_20, "None");
  return atexit(_E74_37);
}

//----- (006DE010) --------------------------------------------------------  // acclient.c:755367
int _E76_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_20, "Speed");
  return atexit(_E77_51);
}

//----- (006DE030) --------------------------------------------------------  // acclient.c:755374
int _E79_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_20, "Noise");
  return atexit(_E80_25);
}

//----- (006DE050) --------------------------------------------------------  // acclient.c:755381
int _E82_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_20, "Sine");
  return atexit(_E83_15);
}

//----- (006DE070) --------------------------------------------------------  // acclient.c:755388
int _E85_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_20, "Square");
  return atexit(_E86_12);
}

//----- (006DE090) --------------------------------------------------------  // acclient.c:755395
int _E88_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_20, "Bounce");
  return atexit(_E89_23);
}

//----- (006DE0B0) --------------------------------------------------------  // acclient.c:755402
int _E91_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_20, "Perlin");
  return atexit(_E92_25);
}

//----- (006DE0D0) --------------------------------------------------------  // acclient.c:755409
int _E94_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_20, "Fractal");
  return atexit(sub_74B0E0);
}

//----- (006DE0F0) --------------------------------------------------------  // acclient.c:755416
int _E97_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_20, "FrameLoop");
  return atexit(_E98_40);
}

//----- (006DE110) --------------------------------------------------------  // acclient.c:755423
void _E100_19()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_23, PFID_A8R8G8B8);
}

//----- (006DE120) --------------------------------------------------------  // acclient.c:755429
int _E118_14()
{
  PStringBase<char>::PStringBase<char>(&PHeader_5, "PREPROC_HEADER");
  return atexit(_E119_63);
}

//----- (006DE140) --------------------------------------------------------  // acclient.c:755436
int _E121_11()
{
  PStringBase<char>::PStringBase<char>(&PreprocHeader_0, "PREPROC_HEADER");
  return atexit(_E122_50);
}

//----- (006DE160) --------------------------------------------------------  // acclient.c:755443
int _E124_14()
{
  PStringBase<char>::PStringBase<char>(&MeshAppearanceType_0, "MeshAppearanceType");
  return atexit(_E125_25);
}

//----- (006DE180) --------------------------------------------------------  // acclient.c:755450
int _E127_10()
{
  PStringBase<char>::PStringBase<char>(&Fragment_0, "Fragment");
  return atexit(_E128_26);
}

//----- (006DE1A0) --------------------------------------------------------  // acclient.c:755457
int _E130_11()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_0, "FragmentType");
  return atexit(_E131_22);
}

//----- (006DE1C0) --------------------------------------------------------  // acclient.c:755464
int _E133_10()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_LevelOfDetailModel_0, "LevelOfDetailModel");
  return atexit(_E134_21);
}

//----- (006DE1E0) --------------------------------------------------------  // acclient.c:755471
int _E136_9()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_OccludeModel_0, "OccludeModel");
  return atexit(_E137_21);
}

//----- (006DE200) --------------------------------------------------------  // acclient.c:755478
int _E139_8()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_ShadowLODModel_0, "ShadowLODModel");
  return atexit(_E140_16);
}

//----- (006DE220) --------------------------------------------------------  // acclient.c:755485
int _E142_8()
{
  PStringBase<char>::PStringBase<char>(&FragmentTopology_0, "FragmentTopology");
  return atexit(_E143_17);
}

//----- (006DE240) --------------------------------------------------------  // acclient.c:755492
int _E145_7()
{
  PStringBase<char>::PStringBase<char>(&FragmentMOPP_0, "FragmentMOPP");
  return atexit(_E146_16);
}

//----- (006DE260) --------------------------------------------------------  // acclient.c:755499
int _E148_7()
{
  PStringBase<char>::PStringBase<char>(&MaterialBatch_0, "MaterialBatch");
  return atexit(_E149_16);
}

//----- (006DE280) --------------------------------------------------------  // acclient.c:755506
int _E151_7()
{
  PStringBase<char>::PStringBase<char>(&FragmentBatch_0, "FragmentBatch");
  return atexit(_E152_15);
}

//----- (006DE2A0) --------------------------------------------------------  // acclient.c:755513
int _E154_8()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_0, "PrimitivesType");
  return atexit(_E155_13);
}

//----- (006DE2C0) --------------------------------------------------------  // acclient.c:755520
int _E157_7()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_PointList_0, "PointList");
  return atexit(_E158_16);
}

//----- (006DE2E0) --------------------------------------------------------  // acclient.c:755527
int _E160_8()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineList_0, "LineList");
  return atexit(_E161_13);
}

//----- (006DE300) --------------------------------------------------------  // acclient.c:755534
int _E163_6()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineStrip_0, "LineStrip");
  return atexit(_E164_16);
}

//----- (006DE320) --------------------------------------------------------  // acclient.c:755541
int _E166_7()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleList_0, "TriangleList");
  return atexit(_E167_12);
}

//----- (006DE340) --------------------------------------------------------  // acclient.c:755548
int _E169_5()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleStrip_0, "TriangleStrip");
  return atexit(_E170_11);
}

//----- (006DE360) --------------------------------------------------------  // acclient.c:755555
int _E172_5()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleFan_0, "TriangleFan");
  return atexit(_E173_10);
}

//----- (006DE380) --------------------------------------------------------  // acclient.c:755562
int _E175_5()
{
  PStringBase<char>::PStringBase<char>(&Material_24, "Material");
  return atexit(_E176_11);
}

//----- (006DE3A0) --------------------------------------------------------  // acclient.c:755569
int _E178_5()
{
  PStringBase<char>::PStringBase<char>(&Vertices_0, "Vertices");
  return atexit(_E179_10);
}

//----- (006DE3C0) --------------------------------------------------------  // acclient.c:755576
int _E181_5()
{
  PStringBase<char>::PStringBase<char>(&Indices_7, "Indices");
  return atexit(_E182_10);
}

//----- (006DE3E0) --------------------------------------------------------  // acclient.c:755583
int _E184_3()
{
  PStringBase<char>::PStringBase<char>(&ExportMeshAppearanceType_0, "MeshType");
  return atexit(_E185_7);
}

//----- (006DE400) --------------------------------------------------------  // acclient.c:755590
int _E187_3()
{
  PStringBase<char>::PStringBase<char>(&MeshDegradeType_0, "MeshDegradeType");
  return atexit(_E188_8);
}

//----- (006DE420) --------------------------------------------------------  // acclient.c:755597
int _E190_3()
{
  PStringBase<char>::PStringBase<char>(&DegradeLevel_0, "DegLevel");
  return atexit(_E191_7);
}

//----- (006DE440) --------------------------------------------------------  // acclient.c:755604
int _E193_3()
{
  PStringBase<char>::PStringBase<char>(&NumDegradeLevels_0, "NumDegrades");
  return atexit(_E194_14);
}

//----- (006DE460) --------------------------------------------------------  // acclient.c:755611
int _E196_5()
{
  PStringBase<char>::PStringBase<char>(&CellMesh_0, "CellMesh");
  return atexit(_E197_5);
}

//----- (006DE480) --------------------------------------------------------  // acclient.c:755618
int _E199_3()
{
  PStringBase<char>::PStringBase<char>(&MaterialArray_0, "MaterialArray");
  return atexit(_E200_10);
}

//----- (006DE4A0) --------------------------------------------------------  // acclient.c:755625
int _E202_3()
{
  PStringBase<char>::PStringBase<char>(&Render_0, "Render");
  return atexit(_E203_9);
}

//----- (006DE4C0) --------------------------------------------------------  // acclient.c:755632
int _E205_4()
{
  PStringBase<char>::PStringBase<char>(&RenderMesh_0, "RenderMesh");
  return atexit(_E206_12);
}

//----- (006DE4E0) --------------------------------------------------------  // acclient.c:755639
int _E208_5()
{
  PStringBase<char>::PStringBase<char>(&RenderMeshVersion_0, "RenderMeshVersioned");
  return atexit(_E209_7);
}

//----- (006DE500) --------------------------------------------------------  // acclient.c:755646
int _E211_4()
{
  PStringBase<char>::PStringBase<char>(&Sphere_6, "Sphere");
  return atexit(_E212_10);
}

//----- (006DE520) --------------------------------------------------------  // acclient.c:755653
int _E214_4()
{
  PStringBase<char>::PStringBase<char>(&DetailedBSP_0, "DetailedBSP");
  return atexit(_E215_6);
}

//----- (006DE540) --------------------------------------------------------  // acclient.c:755660
int _E217_4()
{
  PStringBase<char>::PStringBase<char>(&PolygonArray_0, "PolygonArray");
  return atexit(_E218_7);
}

//----- (006DE560) --------------------------------------------------------  // acclient.c:755667
int _E220_4()
{
  PStringBase<char>::PStringBase<char>(&BinaryPolygonArray_0, "BinaryPolygonArray");
  return atexit(_E221_7);
}

//----- (006DE580) --------------------------------------------------------  // acclient.c:755674
int _E223_4()
{
  PStringBase<char>::PStringBase<char>(&Physics_0, "Physics");
  return atexit(_E224_7);
}

//----- (006DE5A0) --------------------------------------------------------  // acclient.c:755681
int _E226_4()
{
  PStringBase<char>::PStringBase<char>(&BSPTree_0, "BSPTree");
  return atexit(_E227_7);
}

//----- (006DE5C0) --------------------------------------------------------  // acclient.c:755688
int _E229_4()
{
  PStringBase<char>::PStringBase<char>(&BinaryBSPTree_0, "BinaryBSPTree");
  return atexit(_E230_7);
}

//----- (006DE5E0) --------------------------------------------------------  // acclient.c:755695
int _E232_4()
{
  PStringBase<char>::PStringBase<char>(&Cell_0, "Cell");
  return atexit(_E233_6);
}

//----- (006DE600) --------------------------------------------------------  // acclient.c:755702
int _E235_4()
{
  PStringBase<char>::PStringBase<char>(&CellBSP_0, "CellBSP");
  return atexit(_E236_6);
}

//----- (006DE620) --------------------------------------------------------  // acclient.c:755709
int _E238_4()
{
  PStringBase<char>::PStringBase<char>(&Portals_0, "Portals");
  return atexit(_E239_7);
}

//----- (006DE640) --------------------------------------------------------  // acclient.c:755716
int _E241_4()
{
  PStringBase<char>::PStringBase<char>(&Portal_6, "Portal");
  return atexit(_E242_7);
}

//----- (006DE660) --------------------------------------------------------  // acclient.c:755723
int _E244_4()
{
  PStringBase<char>::PStringBase<char>(&NonPortals_0, "NonPortals");
  return atexit(_E245_6);
}

//----- (006DE680) --------------------------------------------------------  // acclient.c:755730
int _E247_4()
{
  PStringBase<char>::PStringBase<char>(&NonPortal_0, "NonPortal");
  return atexit(_E248_6);
}

//----- (006DE6A0) --------------------------------------------------------  // acclient.c:755737
int _E250_4()
{
  PStringBase<char>::PStringBase<char>(&Info_0, "Info");
  return atexit(_E251_6);
}

//----- (006DE6C0) --------------------------------------------------------  // acclient.c:755744
int _E253_4()
{
  PStringBase<char>::PStringBase<char>(&CellVolumeInfo_0, "CellVolumeInfo");
  return atexit(_E254_7);
}

//----- (006DE6E0) --------------------------------------------------------  // acclient.c:755751
int _E256_4()
{
  PStringBase<char>::PStringBase<char>(&CellStructure_0, "CellStructure ");
  return atexit(_E257_5);
}

//----- (006DE700) --------------------------------------------------------  // acclient.c:755758
int _E259_4()
{
  PStringBase<char>::PStringBase<char>(&CellRotation_0, "Rotation");
  return atexit(_E260_6);
}

//----- (006DE720) --------------------------------------------------------  // acclient.c:755765
int _E262_4()
{
  PStringBase<char>::PStringBase<char>(&CellGridSize_0, "GridSize");
  return atexit(_E263_4);
}

//----- (006DE740) --------------------------------------------------------  // acclient.c:755772
int _E265_4()
{
  PStringBase<char>::PStringBase<char>(&CellNeverCull_0, "CellNeverCull");
  return atexit(_E266_4);
}

//----- (006DE760) --------------------------------------------------------  // acclient.c:755779
int _E268_4()
{
  PStringBase<char>::PStringBase<char>(&CellDrawSky_0, "CellDrawSky");
  return atexit(_E269_4);
}

//----- (006DE780) --------------------------------------------------------  // acclient.c:755786
int _E271_3()
{
  PStringBase<char>::PStringBase<char>(&DegradeArray_0, "Degrades");
  return atexit(_E272_3);
}

//----- (006DE7A0) --------------------------------------------------------  // acclient.c:755793
int _E274_3()
{
  PStringBase<char>::PStringBase<char>(&OccludeMeshArray_0, "OccludeMeshes");
  return atexit(_E275_3);
}

//----- (006DE7C0) --------------------------------------------------------  // acclient.c:755800
int _E277_3()
{
  PStringBase<char>::PStringBase<char>(&DegradeMesh_0, "DegradeMesh");
  return atexit(_E278_3);
}

//----- (006DE7E0) --------------------------------------------------------  // acclient.c:755807
int _E280_3()
{
  PStringBase<char>::PStringBase<char>(&BSP_0, "BSP");
  return atexit(_E281_4);
}

//----- (006DE800) --------------------------------------------------------  // acclient.c:755814
int _E283_3()
{
  PStringBase<char>::PStringBase<char>(&BumpMap_0, "BumpMap");
  return atexit(_E284_3);
}

//----- (006DE820) --------------------------------------------------------  // acclient.c:755821
int _E286_3()
{
  PStringBase<char>::PStringBase<char>(&UVSets_0, "UVSets");
  return atexit(_E287_4);
}

//----- (006DE840) --------------------------------------------------------  // acclient.c:755828
int _E289_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMesh_0, "PhysicsMesh");
  return atexit(_E290_4);
}

//----- (006DE860) --------------------------------------------------------  // acclient.c:755835
int _E292_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterials_0, "PhysicsMaterials");
  return atexit(_E293_3);
}

//----- (006DE880) --------------------------------------------------------  // acclient.c:755842
int _E295_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterialArray_0, "PhysicsMaterialArray");
  return atexit(_E296_4);
}

//----- (006DE8A0) --------------------------------------------------------  // acclient.c:755849
int _E298_3()
{
  PStringBase<char>::PStringBase<char>(&PathMapMeshArray_0, "PathMapMeshes");
  return atexit(_E299_2);
}

//----- (006DE8C0) --------------------------------------------------------  // acclient.c:755856
int _E301_2()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygonArray_0, "PathMapPolygonArray");
  return atexit(_E302_3);
}

//----- (006DE8E0) --------------------------------------------------------  // acclient.c:755863
int _E304_2()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygon_0, "PathMapPolygon");
  return atexit(_E305_2);
}

//----- (006DE900) --------------------------------------------------------  // acclient.c:755870
int _E307_2()
{
  PStringBase<char>::PStringBase<char>(&VertexSetArray_0, "VertexSetArray");
  return atexit(_E308_3);
}

//----- (006DE920) --------------------------------------------------------  // acclient.c:755877
int _E310_2()
{
  PStringBase<char>::PStringBase<char>(&VertexSets_0, "VertexSets");
  return atexit(_E311_2);
}

//----- (006DE940) --------------------------------------------------------  // acclient.c:755884
int _E313_2()
{
  PStringBase<char>::PStringBase<char>(&VertexSet_0, "VertexSet");
  return atexit(_E314_3);
}

//----- (006DE960) --------------------------------------------------------  // acclient.c:755891
int _E316_2()
{
  PStringBase<char>::PStringBase<char>(&Set_0, "Set");
  return atexit(_E317_2);
}

//----- (006DE980) --------------------------------------------------------  // acclient.c:755898
int _E319_2()
{
  PStringBase<char>::PStringBase<char>(&ID_12, "ID");
  return atexit(_E320_3);
}

//----- (006DE9A0) --------------------------------------------------------  // acclient.c:755905
int _E322_2()
{
  PStringBase<char>::PStringBase<char>(&Name_1, "Name");
  return atexit(_E323_2);
}

//----- (006DE9C0) --------------------------------------------------------  // acclient.c:755912
int _E325_2()
{
  PStringBase<char>::PStringBase<char>(&Indices_8, "Indices");
  return atexit(_E326_3);
}

//----- (006DE9E0) --------------------------------------------------------  // acclient.c:755919
int _E328_2()
{
  PStringBase<char>::PStringBase<char>(&MorphMeshArray_0, "MorphMeshArray");
  return atexit(_E329_2);
}

//----- (006DEA00) --------------------------------------------------------  // acclient.c:755926
int _E331_2()
{
  PStringBase<char>::PStringBase<char>(&MorphMesh_0, "MorphMesh");
  return atexit(_E332_3);
}

//----- (006DEA20) --------------------------------------------------------  // acclient.c:755933
int _E334_2()
{
  PStringBase<char>::PStringBase<char>(&MorphTargets_0, "MorphTargets");
  return atexit(_E335_2);
}

//----- (006DEA40) --------------------------------------------------------  // acclient.c:755940
int _E337_2()
{
  PStringBase<char>::PStringBase<char>(&Target_0, "Target");
  return atexit(_E338_2);
}

//----- (006DEA60) --------------------------------------------------------  // acclient.c:755947
int _E340_2()
{
  PStringBase<char>::PStringBase<char>(&Name_2, "Name");
  return atexit(_E341_2);
}

//----- (0074AF90) --------------------------------------------------------  // acclient.c:865007
void __cdecl _E74_37()
{
  char *v0; // esi@1

  v0 = &waveform_None_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AFC0) --------------------------------------------------------  // acclient.c:865020
void __cdecl _E77_51()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AFF0) --------------------------------------------------------  // acclient.c:865033
void __cdecl _E80_25()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B020) --------------------------------------------------------  // acclient.c:865046
void __cdecl _E83_15()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B050) --------------------------------------------------------  // acclient.c:865059
void __cdecl _E86_12()
{
  char *v0; // esi@1

  v0 = &waveform_Square_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B080) --------------------------------------------------------  // acclient.c:865072
void __cdecl _E89_23()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B0B0) --------------------------------------------------------  // acclient.c:865085
void __cdecl _E92_25()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B0E0) --------------------------------------------------------  // acclient.c:865098
void __cdecl sub_74B0E0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B110) --------------------------------------------------------  // acclient.c:865111
void __cdecl _E98_40()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B140) --------------------------------------------------------  // acclient.c:865124
void __cdecl _E119_63()
{
  char *v0; // esi@1

  v0 = &PHeader_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B170) --------------------------------------------------------  // acclient.c:865137
void __cdecl _E122_50()
{
  char *v0; // esi@1

  v0 = &PreprocHeader_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PreprocHeader_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B1A0) --------------------------------------------------------  // acclient.c:865150
void __cdecl _E125_25()
{
  char *v0; // esi@1

  v0 = &MeshAppearanceType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshAppearanceType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B1D0) --------------------------------------------------------  // acclient.c:865163
void __cdecl _E128_26()
{
  char *v0; // esi@1

  v0 = &Fragment_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Fragment_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B200) --------------------------------------------------------  // acclient.c:865176
void __cdecl _E131_22()
{
  char *v0; // esi@1

  v0 = &FragmentType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B230) --------------------------------------------------------  // acclient.c:865189
void __cdecl _E134_21()
{
  char *v0; // esi@1

  v0 = &FragmentType_LevelOfDetailModel_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_LevelOfDetailModel_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B260) --------------------------------------------------------  // acclient.c:865202
void __cdecl _E137_21()
{
  char *v0; // esi@1

  v0 = &FragmentType_OccludeModel_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_OccludeModel_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B290) --------------------------------------------------------  // acclient.c:865215
void __cdecl _E140_16()
{
  char *v0; // esi@1

  v0 = &FragmentType_ShadowLODModel_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_ShadowLODModel_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B2C0) --------------------------------------------------------  // acclient.c:865228
void __cdecl _E143_17()
{
  char *v0; // esi@1

  v0 = &FragmentTopology_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentTopology_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B2F0) --------------------------------------------------------  // acclient.c:865241
void __cdecl _E146_16()
{
  char *v0; // esi@1

  v0 = &FragmentMOPP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentMOPP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B320) --------------------------------------------------------  // acclient.c:865254
void __cdecl _E149_16()
{
  char *v0; // esi@1

  v0 = &MaterialBatch_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialBatch_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B350) --------------------------------------------------------  // acclient.c:865267
void __cdecl _E152_15()
{
  char *v0; // esi@1

  v0 = &FragmentBatch_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentBatch_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B380) --------------------------------------------------------  // acclient.c:865280
void __cdecl _E155_13()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B3B0) --------------------------------------------------------  // acclient.c:865293
void __cdecl _E158_16()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_PointList_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_PointList_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B3E0) --------------------------------------------------------  // acclient.c:865306
void __cdecl _E161_13()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineList_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineList_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B410) --------------------------------------------------------  // acclient.c:865319
void __cdecl _E164_16()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineStrip_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineStrip_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B440) --------------------------------------------------------  // acclient.c:865332
void __cdecl _E167_12()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleList_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleList_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B470) --------------------------------------------------------  // acclient.c:865345
void __cdecl _E170_11()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleStrip_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleStrip_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B4A0) --------------------------------------------------------  // acclient.c:865358
void __cdecl _E173_10()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleFan_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleFan_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B4D0) --------------------------------------------------------  // acclient.c:865371
void __cdecl _E176_11()
{
  char *v0; // esi@1

  v0 = &Material_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B500) --------------------------------------------------------  // acclient.c:865384
void __cdecl _E179_10()
{
  char *v0; // esi@1

  v0 = &Vertices_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertices_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B530) --------------------------------------------------------  // acclient.c:865397
void __cdecl _E182_10()
{
  char *v0; // esi@1

  v0 = &Indices_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B560) --------------------------------------------------------  // acclient.c:865410
void __cdecl _E185_7()
{
  char *v0; // esi@1

  v0 = &ExportMeshAppearanceType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExportMeshAppearanceType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B590) --------------------------------------------------------  // acclient.c:865423
void __cdecl _E188_8()
{
  char *v0; // esi@1

  v0 = &MeshDegradeType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshDegradeType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B5C0) --------------------------------------------------------  // acclient.c:865436
void __cdecl _E191_7()
{
  char *v0; // esi@1

  v0 = &DegradeLevel_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeLevel_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B5F0) --------------------------------------------------------  // acclient.c:865449
void __cdecl _E194_14()
{
  char *v0; // esi@1

  v0 = &NumDegradeLevels_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumDegradeLevels_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B620) --------------------------------------------------------  // acclient.c:865462
void __cdecl _E197_5()
{
  char *v0; // esi@1

  v0 = &CellMesh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellMesh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B650) --------------------------------------------------------  // acclient.c:865475
void __cdecl _E200_10()
{
  char *v0; // esi@1

  v0 = &MaterialArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B680) --------------------------------------------------------  // acclient.c:865488
void __cdecl _E203_9()
{
  char *v0; // esi@1

  v0 = &Render_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B6B0) --------------------------------------------------------  // acclient.c:865501
void __cdecl _E206_12()
{
  char *v0; // esi@1

  v0 = &RenderMesh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMesh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B6E0) --------------------------------------------------------  // acclient.c:865514
void __cdecl _E209_7()
{
  char *v0; // esi@1

  v0 = &RenderMeshVersion_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMeshVersion_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B710) --------------------------------------------------------  // acclient.c:865527
void __cdecl _E212_10()
{
  char *v0; // esi@1

  v0 = &Sphere_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B740) --------------------------------------------------------  // acclient.c:865540
void __cdecl _E215_6()
{
  char *v0; // esi@1

  v0 = &DetailedBSP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailedBSP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B770) --------------------------------------------------------  // acclient.c:865553
void __cdecl _E218_7()
{
  char *v0; // esi@1

  v0 = &PolygonArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PolygonArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B7A0) --------------------------------------------------------  // acclient.c:865566
void __cdecl _E221_7()
{
  char *v0; // esi@1

  v0 = &BinaryPolygonArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryPolygonArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B7D0) --------------------------------------------------------  // acclient.c:865579
void __cdecl _E224_7()
{
  char *v0; // esi@1

  v0 = &Physics_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Physics_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B800) --------------------------------------------------------  // acclient.c:865592
void __cdecl _E227_7()
{
  char *v0; // esi@1

  v0 = &BSPTree_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSPTree_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B830) --------------------------------------------------------  // acclient.c:865605
void __cdecl _E230_7()
{
  char *v0; // esi@1

  v0 = &BinaryBSPTree_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryBSPTree_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B860) --------------------------------------------------------  // acclient.c:865618
void __cdecl _E233_6()
{
  char *v0; // esi@1

  v0 = &Cell_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Cell_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B890) --------------------------------------------------------  // acclient.c:865631
void __cdecl _E236_6()
{
  char *v0; // esi@1

  v0 = &CellBSP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellBSP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B8C0) --------------------------------------------------------  // acclient.c:865644
void __cdecl _E239_7()
{
  char *v0; // esi@1

  v0 = &Portals_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portals_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B8F0) --------------------------------------------------------  // acclient.c:865657
void __cdecl _E242_7()
{
  char *v0; // esi@1

  v0 = &Portal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B920) --------------------------------------------------------  // acclient.c:865670
void __cdecl _E245_6()
{
  char *v0; // esi@1

  v0 = &NonPortals_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortals_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B950) --------------------------------------------------------  // acclient.c:865683
void __cdecl _E248_6()
{
  char *v0; // esi@1

  v0 = &NonPortal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B980) --------------------------------------------------------  // acclient.c:865696
void __cdecl _E251_6()
{
  char *v0; // esi@1

  v0 = &Info_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Info_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B9B0) --------------------------------------------------------  // acclient.c:865709
void __cdecl _E254_7()
{
  char *v0; // esi@1

  v0 = &CellVolumeInfo_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellVolumeInfo_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074B9E0) --------------------------------------------------------  // acclient.c:865722
void __cdecl _E257_5()
{
  char *v0; // esi@1

  v0 = &CellStructure_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellStructure_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BA10) --------------------------------------------------------  // acclient.c:865735
void __cdecl _E260_6()
{
  char *v0; // esi@1

  v0 = &CellRotation_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellRotation_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BA40) --------------------------------------------------------  // acclient.c:865748
void __cdecl _E263_4()
{
  char *v0; // esi@1

  v0 = &CellGridSize_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellGridSize_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BA70) --------------------------------------------------------  // acclient.c:865761
void __cdecl _E266_4()
{
  char *v0; // esi@1

  v0 = &CellNeverCull_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellNeverCull_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BAA0) --------------------------------------------------------  // acclient.c:865774
void __cdecl _E269_4()
{
  char *v0; // esi@1

  v0 = &CellDrawSky_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellDrawSky_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BAD0) --------------------------------------------------------  // acclient.c:865787
void __cdecl _E272_3()
{
  char *v0; // esi@1

  v0 = &DegradeArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BB00) --------------------------------------------------------  // acclient.c:865800
void __cdecl _E275_3()
{
  char *v0; // esi@1

  v0 = &OccludeMeshArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OccludeMeshArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BB30) --------------------------------------------------------  // acclient.c:865813
void __cdecl _E278_3()
{
  char *v0; // esi@1

  v0 = &DegradeMesh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeMesh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BB60) --------------------------------------------------------  // acclient.c:865826
void __cdecl _E281_4()
{
  char *v0; // esi@1

  v0 = &BSP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BB90) --------------------------------------------------------  // acclient.c:865839
void __cdecl _E284_3()
{
  char *v0; // esi@1

  v0 = &BumpMap_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BumpMap_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BBC0) --------------------------------------------------------  // acclient.c:865852
void __cdecl _E287_4()
{
  char *v0; // esi@1

  v0 = &UVSets_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVSets_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BBF0) --------------------------------------------------------  // acclient.c:865865
void __cdecl _E290_4()
{
  char *v0; // esi@1

  v0 = &PhysicsMesh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMesh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BC20) --------------------------------------------------------  // acclient.c:865878
void __cdecl _E293_3()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterials_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterials_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BC50) --------------------------------------------------------  // acclient.c:865891
void __cdecl _E296_4()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterialArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterialArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BC80) --------------------------------------------------------  // acclient.c:865904
void __cdecl _E299_2()
{
  char *v0; // esi@1

  v0 = &PathMapMeshArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapMeshArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BCB0) --------------------------------------------------------  // acclient.c:865917
void __cdecl _E302_3()
{
  char *v0; // esi@1

  v0 = &PathMapPolygonArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygonArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BCE0) --------------------------------------------------------  // acclient.c:865930
void __cdecl _E305_2()
{
  char *v0; // esi@1

  v0 = &PathMapPolygon_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygon_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BD10) --------------------------------------------------------  // acclient.c:865943
void __cdecl _E308_3()
{
  char *v0; // esi@1

  v0 = &VertexSetArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSetArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BD40) --------------------------------------------------------  // acclient.c:865956
void __cdecl _E311_2()
{
  char *v0; // esi@1

  v0 = &VertexSets_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSets_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BD70) --------------------------------------------------------  // acclient.c:865969
void __cdecl _E314_3()
{
  char *v0; // esi@1

  v0 = &VertexSet_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSet_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BDA0) --------------------------------------------------------  // acclient.c:865982
void __cdecl _E317_2()
{
  char *v0; // esi@1

  v0 = &Set_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Set_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BDD0) --------------------------------------------------------  // acclient.c:865995
void __cdecl _E320_3()
{
  char *v0; // esi@1

  v0 = &ID_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BE00) --------------------------------------------------------  // acclient.c:866008
void __cdecl _E323_2()
{
  char *v0; // esi@1

  v0 = &Name_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BE30) --------------------------------------------------------  // acclient.c:866021
void __cdecl _E326_3()
{
  char *v0; // esi@1

  v0 = &Indices_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BE60) --------------------------------------------------------  // acclient.c:866034
void __cdecl _E329_2()
{
  char *v0; // esi@1

  v0 = &MorphMeshArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMeshArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BE90) --------------------------------------------------------  // acclient.c:866047
void __cdecl _E332_3()
{
  char *v0; // esi@1

  v0 = &MorphMesh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMesh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BEC0) --------------------------------------------------------  // acclient.c:866060
void __cdecl _E335_2()
{
  char *v0; // esi@1

  v0 = &MorphTargets_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphTargets_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BEF0) --------------------------------------------------------  // acclient.c:866073
void __cdecl _E338_2()
{
  char *v0; // esi@1

  v0 = &Target_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Target_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BF20) --------------------------------------------------------  // acclient.c:866086
void __cdecl _E341_2()
{
  char *v0; // esi@1

  v0 = &Name_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

