/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : VertexArray
   Object     : ENGINE\engine_client_geometry\VertexArray.obj
   Functions  : 883
   Addresses  : 0044E030 - 0077DF00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044E030) --------------------------------------------------------  // acclient.c:139231
char __thiscall SmartArray<LOAD_UVPAIR,1>::grow(SmartArray<LOAD_WEIGHTS,1> *this, unsigned int i_nSize)
{
  SmartArray<LOAD_WEIGHTS,1> *v2; // esi@1
  void *v4; // edi@5
  int i; // eax@7
  void *v6; // edx@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<MaterialShaderConstant,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + 2 * i + 3) = *((_DWORD *)v6 + 2 * i + 3) )
        {
          --i;
          v6 = v2->m_data;
          *((_DWORD *)v4 + 2 * i + 2) = v2->m_data[i + 1].matrix_index;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (LOAD_WEIGHTS *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00459540) --------------------------------------------------------  // acclient.c:149780
void __thiscall SmartArray<MaterialShaderConstant,1>::Reset(SmartArray<LOAD_WEIGHTS,1> *this)
{
  SmartArray<LOAD_WEIGHTS,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4
  void *v5; // edi@5
  int v6; // [sp+8h] [bp-8h]@0
  int v7; // [sp+Ch] [bp-4h]@0

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
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; *((_DWORD *)v5 + 2 * i + 3) = v7 )
    {
      --i;
      v5 = v1->m_data;
      *((_DWORD *)v5 + 2 * i + 2) = v6;
    }
  }
}

//----- (005D7290) --------------------------------------------------------  // acclient.c:515333
char __thiscall VertexArray::RequestStripHWExtraTexCoords(VertexArray *this, const bool _b)
{
  char result; // al@2

  if ( this->vertices )
  {
    result = 0;
  }
  else
  {
    this->m_bStripHWExtraTexCoords = _b;
    result = 1;
  }
  return result;
}

//----- (005D72B0) --------------------------------------------------------  // acclient.c:515350
bool __thiscall VertexArray::Startup(VertexArray *this, const unsigned int _numVertices, const unsigned int _format, const bool _staticVertices, const bool _OnlyWriteOnce, const unsigned int _HardwareFormatMask)
{
  VertexArray *v6; // esi@1
  VertexFormatInfo *v7; // ecx@2
  unsigned int v8; // ST00_4@2
  void *v9; // eax@2
  bool result; // al@2

  v6 = this;
  if ( _numVertices )
  {
    v7 = &this->vertexFormat;
    v7->format = _format;
    VertexFormatInfo::GenerateOffsets(v7);
    v8 = _numVertices * v6->vertexFormat.size;
    v6->numVertices = _numVertices;
    v6->staticVertices = _staticVertices;
    v6->m_OnlyWriteOnce = _OnlyWriteOnce;
    v9 = operator new[](v8);
    v6->vertices = v9;
    result = v9 != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005D7310) --------------------------------------------------------  // acclient.c:515380
int __thiscall VertexArray::Lock(VertexArray *this, const unsigned int firstVertex, const unsigned int numVerts)
{
  unsigned int v3; // eax@2
  const unsigned int v4; // eax@4
  void *v5; // edx@4
  int result; // eax@4

  if ( this->locked || (v3 = this->numVertices, firstVertex >= v3) || firstVertex + numVerts > v3 )
  {
    result = 0;
  }
  else
  {
    v4 = firstVertex * this->vertexFormat.size;
    v5 = this->vertices;
    this->locked = 1;
    result = (int)((char *)v5 + v4);
  }
  return result;
}

//----- (005D7350) --------------------------------------------------------  // acclient.c:515402
char __cdecl SetDiffuse(char *vertex, VertexFormatInfo *dstVF, const unsigned int diffuse)
{
  if ( dstVF->format & 0x40 )
    *(_DWORD *)&vertex[dstVF->offsetDiffuse] = diffuse;
  return 1;
}

//----- (005D7370) --------------------------------------------------------  // acclient.c:515410
char __cdecl SetSpecular(char *vertex, VertexFormatInfo *dstVF, const unsigned int specular)
{
  if ( SLOBYTE(dstVF->format) < 0 )
    *(_DWORD *)&vertex[dstVF->offsetSpecular] = specular;
  return 1;
}

//----- (005D7390) --------------------------------------------------------  // acclient.c:515418
char __cdecl SetVectorS(char *vertex, VertexFormatInfo *dstVF, Vector3 *vectorS)
{
  char result; // al@2

  if ( dstVF->format & 0x10000000 )
  {
    *(Vector3 *)&vertex[dstVF->offsetVectorS] = *vectorS;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005D73C0) --------------------------------------------------------  // acclient.c:515435
char __cdecl SetVectorT(char *vertex, VertexFormatInfo *dstVF, Vector3 *vectorT)
{
  char result; // al@2

  if ( dstVF->format & 0x20000000 )
  {
    *(Vector3 *)&vertex[dstVF->offsetVectorT] = *vectorT;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005D73F0) --------------------------------------------------------  // acclient.c:515452
char __cdecl SetTCPair(char *vertex, VertexFormatInfo *dstVF, const unsigned int tcIndex, const float *tcPair)
{
  unsigned int v4; // edx@2
  char result; // al@2

  if ( tcIndex >= dstVF->numTCPairs )
  {
    result = 0;
  }
  else
  {
    v4 = dstVF->offsetTCPair[tcIndex];
    *(_DWORD *)&vertex[v4] = *(_DWORD *)tcPair;
    *(_DWORD *)&vertex[v4 + 4] = *((_DWORD *)tcPair + 1);
    result = 1;
  }
  return result;
}

//----- (005D7420) --------------------------------------------------------  // acclient.c:515472
char __cdecl SetMatrixWeight(char *vertex, VertexFormatInfo *dstVF, const unsigned int index, const char matrixIndex, const float matrixWeight)
{
  char result; // al@2

  if ( index >= dstVF->numMatrices )
  {
    result = 0;
  }
  else
  {
    *(&vertex[dstVF->offsetMatrices] + index) = matrixIndex;
    *(const float *)(&vertex[4 * index] + dstVF->offsetMWeights) = matrixWeight;
    result = 1;
  }
  return result;
}

//----- (005D7460) --------------------------------------------------------  // acclient.c:515490
void __thiscall VertexArray::GenerateBoundingBox(VertexArray *this)
{
  VertexArray *v1; // esi@1
  BBox *v2; // ebx@1
  unsigned int v3; // edi@1
  Vector3 *v4; // eax@2
  float v5; // ecx@3
  float v6; // edx@3
  Vector3 SwappedVertex; // [sp+Ch] [bp-Ch]@3

  v1 = this;
  v2 = &this->m_BoundingBox;
  BBox::InitForAdjustment(&this->m_BoundingBox);
  v3 = 0;
  if ( v1->numVertices )
  {
    do
    {
      v4 = (Vector3 *)((char *)v1->vertices + v3 * v1->vertexFormat.size);
      if ( v1->m_IsYAndZSwapped )
      {
        v5 = v4->x;
        v6 = v4->y;
        SwappedVertex.y = v4->z;
        SwappedVertex.x = v5;
        SwappedVertex.z = v6;
        v4 = &SwappedVertex;
      }
      BBox::AdjustBBox(v2, v4);
      ++v3;
    }
    while ( v3 < v1->numVertices );
  }
}

//----- (005D74D0) --------------------------------------------------------  // acclient.c:515526
void __thiscall VertexArray::Begin(VertexArray *this)
{
  this->numVertices = 0;
  this->vertices = 0;
  this->staticVertices = 1;
  this->locked = 0;
  this->m_IsYAndZSwapped = 0;
  this->m_OnlyWriteOnce = 0;
  qmemcpy(&this->m_BoundingBox, &BBox::s_cZeroAABB, sizeof(this->m_BoundingBox));
  this->m_bStripHWExtraTexCoords = 0;
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&this->m_InfluencedBoneIndexArray);
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (005D7520) --------------------------------------------------------  // acclient.c:515541
void __thiscall VertexArray::End(VertexArray *this)
{
  VertexArray *v1; // esi@1

  v1 = this;
  if ( this->vertices )
  {
    operator delete[](this->vertices);
    v1->vertices = 0;
  }
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_InfluencedBoneIndexArray);
}

//----- (005D7550) --------------------------------------------------------  // acclient.c:515555
void __thiscall VertexArray::Shutdown(VertexArray *this)
{
  VertexArray *v1; // esi@1

  v1 = this;
  if ( this->vertices )
  {
    operator delete[](this->vertices);
    v1->vertices = 0;
  }
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_InfluencedBoneIndexArray);
  VertexArray::Begin(v1);
}

//----- (005D7590) --------------------------------------------------------  // acclient.c:515570
char __thiscall SmartArray<LOAD_WEIGHTS,1>::SetNElements(SmartArray<LOAD_WEIGHTS,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<LOAD_WEIGHTS,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int i; // eax@7
  LOAD_WEIGHTS *v7; // ebx@8
  unsigned int v8; // [sp+8h] [bp-8h]@0
  float v9; // [sp+Ch] [bp-4h]@0

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
    {
      v7 = this->m_data;
      v7[i].matrix_index = v8;
      v7[i].matrix_weight = v9;
    }
    goto LABEL_9;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<LOAD_UVPAIR,1>::grow(v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (005D7600) --------------------------------------------------------  // acclient.c:515606
char __userpurge PFileNode::GetSubName@<al>(PFileNode *this@<ecx>, int a2@<edi>, unsigned int i_index, unsigned int *o_retval)
{
  PFileNode *v4; // eax@1
  char result; // al@2

  v4 = (PFileNode *)((int (__stdcall *)(_DWORD))this->vfptr[3].__vecDelDtor)(i_index);
  if ( v4 )
    result = PFileNode::GetNameAsUInt32(v4, a2, o_retval);
  else
    result = 0;
  return result;
}

//----- (005D7630) --------------------------------------------------------  // acclient.c:515620
char __userpurge PFileNode::GetSubName@<al>(PFileNode *this@<ecx>, int a2@<edi>, unsigned int i_index, float *o_retval)
{
  PFileNode *v4; // eax@1
  char result; // al@2

  v4 = (PFileNode *)((int (__stdcall *)(_DWORD))this->vfptr[3].__vecDelDtor)(i_index);
  if ( v4 )
    result = PFileNode::GetNameAsFloat(v4, a2, o_retval);
  else
    result = 0;
  return result;
}

//----- (005D7660) --------------------------------------------------------  // acclient.c:515634
void __thiscall SmartArray<LOAD_UVPAIR,1>::Serialize(SmartArray<LOAD_WEIGHTS,1> *this, Archive *io_rcArchive)
{
  SmartArray<LOAD_WEIGHTS,1> *v2; // ebp@1
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
    SmartArray<LOAD_WEIGHTS,1>::SetNElements(v2, v3, 1);
  }
  if ( v2->m_num )
  {
    do
    {
      v6 = (int)&v2->m_data[v5];
      Archive::CheckAlignment(io_rcArchive, 4u);
      v7 = Archive::GetBytes(io_rcArchive, 4u);
      if ( v7 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_DWORD *)v7 = *(_DWORD *)v6;
        else
          *(_DWORD *)v6 = *(_DWORD *)v7;
      }
      Archive::CheckAlignment(io_rcArchive, 4u);
      v8 = Archive::GetBytes(io_rcArchive, 4u);
      if ( v8 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_DWORD *)v8 = *(_DWORD *)(v6 + 4);
        else
          *(_DWORD *)(v6 + 4) = *(_DWORD *)v8;
      }
      ++v5;
    }
    while ( v5 < v2->m_num );
  }
}

//----- (005D7730) --------------------------------------------------------  // acclient.c:515696
void __thiscall VertexArray::Serialize(VertexArray *this, Archive *io_archive)
{
  Archive *v2; // ebx@1
  VertexArray *v3; // ebp@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@12
  char *v8; // eax@15
  void *v9; // edi@20
  unsigned int v10; // eax@20
  const void *v11; // esi@22

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3->vertexFormat.format;
    else
      v3->vertexFormat.format = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
    {
      v6 = v3->numVertices;
      *(_DWORD *)v5 = v6;
    }
    else
    {
      v3->numVertices = *(_DWORD *)v5;
    }
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    if ( !v3->vertices )
      v3->m_bStripHWExtraTexCoords = 1;
    v7 = v3->vertexFormat.format;
    LOBYTE(v6) = 1;
    LOBYTE(io_archive) = 1;
    if ( v7 & 0xFF0000 )
    {
      LOBYTE(v6) = 0;
      LOBYTE(io_archive) = 0;
    }
    LOBYTE(v6) = (_BYTE)v6 != 0;
    if ( !(unsigned __int8)((int (__thiscall *)(VertexArray *, _DWORD, _DWORD, Archive *, _DWORD, signed int))v3->vfptr[1].__vecDelDtor)(
                             v3,
                             v3->numVertices,
                             v7,
                             io_archive,
                             v6,
                             -1)
      || (v8 = (char *)((int (__thiscall *)(VertexArray *, _DWORD, _DWORD))v3->vfptr[3].__vecDelDtor)(
                         v3,
                         0,
                         v3->numVertices)) == 0 )
    {
      Archive::RaiseError(v2);
      return;
    }
  }
  else
  {
    v8 = (char *)v3->vertices;
  }
  Serializer::SerializeBytes(v8, v3->numVertices * v3->vertexFormat.size, v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    ((void (__thiscall *)(VertexArray *, _DWORD, _DWORD))v3->vfptr[4].__vecDelDtor)(v3, 0, 0);
  v9 = &v3->m_BoundingBox;
  Archive::CheckAlignment(v2, 0x18u);
  v10 = Archive::GetBytes(v2, 0x18u);
  if ( v10 )
  {
    if ( v2->m_flags & 1 )
    {
      v11 = &v3->m_BoundingBox;
      v9 = (void *)v10;
    }
    else
    {
      v11 = (const void *)v10;
    }
    qmemcpy(v9, v11, 0x18u);
  }
  SmartArray<unsigned long,1>::Serialize(&v3->m_InfluencedBoneIndexArray, v2);
}

//----- (005D7870) --------------------------------------------------------  // acclient.c:515790
char __usercall LoadArbitraryVertex@<al>(int a1@<edi>, PFileNode *node, VertexFormatInfo *dstVF, char *vertex)
{
  int v4; // eax@3
  int v5; // esi@5
  PFileNode *v7; // esi@9
  float v8; // ecx@11
  const unsigned int v9; // eax@28
  const unsigned int v10; // eax@32
  const unsigned int v11; // ebx@36
  PFileNode *v12; // eax@37
  float v13; // ecx@38
  const unsigned int v14; // ebx@44
  PFileNode *v15; // eax@45
  float v16; // ecx@46
  float v17; // ecx@47
  float v18; // ecx@48
  float v19; // [sp-4h] [bp-7Ch]@5
  float matrixWeight; // [sp+Ch] [bp-6Ch]@3
  unsigned int matrixIndexUINT32; // [sp+10h] [bp-68h]@47
  float tcPair[2]; // [sp+14h] [bp-64h]@39
  PFileNodeIter iter; // [sp+1Ch] [bp-5Ch]@9
  Vector3 origin; // [sp+28h] [bp-50h]@11
  Vector3 normal; // [sp+34h] [bp-44h]@15
  Vector3 vectorS; // [sp+40h] [bp-38h]@19
  Vector3 vectorT; // [sp+4Ch] [bp-2Ch]@23
  RGBAColor diffuse; // [sp+58h] [bp-20h]@27
  RGBAColor specular; // [sp+68h] [bp-10h]@31

  if ( !node )
    return 0;
  if ( !PFileNode::IsKeyword(node, a1, &Vertex_9) )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&matrixWeight, "expected ");
    v4 = *(_DWORD *)&Vertex_9.m_charbuffer[-1].m_data[12];
    if ( v4 != 1 )
      PStringBase<char>::append_n_chars((PStringBase<char> *)&matrixWeight, Vertex_9.m_charbuffer->m_data, v4 - 1);
    v19 = matrixWeight;
    InterlockedIncrement((volatile LONG *)(LODWORD(matrixWeight) - 16));
    PFileNode::ReportError(a1, node, LODWORD(v19));
    v5 = LODWORD(matrixWeight) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(LODWORD(matrixWeight) - 20 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    return 0;
  }
  PFileNodeIter::PFileNodeIter(&iter, node);
  v7 = PFileNodeIter::Curr(&iter);
  if ( !v7 )
  {
LABEL_52:
    PFileNodeIter::~PFileNodeIter(&iter);
    return 1;
  }
  while ( 1 )
  {
    if ( PFileNode::IsKeyword(v7, a1, &Origin_19) )
    {
      if ( !Vector3::FromFileNode(&origin, v7) )
        goto LABEL_53;
      if ( !(dstVF->format & 2) )
        goto LABEL_59;
      *(Vector3 *)&vertex[dstVF->offsetOrigin] = origin;
      goto LABEL_51;
    }
    if ( PFileNode::IsKeyword(v7, a1, &Normal_9) )
    {
      if ( !Vector3::FromFileNode(&normal, v7) )
        goto LABEL_53;
      if ( !(dstVF->format & 0x10) )
        goto LABEL_59;
      *(Vector3 *)&vertex[dstVF->offsetNormal] = normal;
      goto LABEL_51;
    }
    if ( PFileNode::IsKeyword(v7, a1, &VectorS_9) )
    {
      if ( !Vector3::FromFileNode(&vectorS, v7) )
        goto LABEL_53;
      if ( !SetVectorS(vertex, dstVF, &vectorS) )
        goto LABEL_59;
      goto LABEL_51;
    }
    if ( PFileNode::IsKeyword(v7, a1, &VectorT_9) )
    {
      if ( !Vector3::FromFileNode(&vectorT, v7) )
        goto LABEL_53;
      if ( !SetVectorT(vertex, dstVF, &vectorT) )
        goto LABEL_59;
      goto LABEL_51;
    }
    if ( PFileNode::IsKeyword(v7, a1, &Diffuse_19) )
    {
      if ( !RGBAColor::FromFileNode(&diffuse, v7, 1, 1) )
        goto LABEL_53;
      v9 = RGBAColor::GetColor32(&diffuse);
      if ( !SetDiffuse(vertex, dstVF, v9) )
        goto LABEL_59;
      goto LABEL_51;
    }
    if ( !PFileNode::IsKeyword(v7, a1, &Specular_19) )
      break;
    if ( !RGBAColor::FromFileNode(&specular, v7, 1, 1) )
    {
LABEL_53:
      v19 = v8;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "invalid vertex");
      PFileNode::ReportError(a1, v7, LODWORD(v19));
      goto LABEL_59;
    }
    v10 = RGBAColor::GetColor32(&specular);
    if ( !SetSpecular(vertex, dstVF, v10) )
      goto LABEL_59;
LABEL_51:
    v7 = (PFileNode *)PFileNodeIter::Next(&iter);
    if ( !v7 )
      goto LABEL_52;
  }
  if ( !PFileNode::IsKeyword(v7, a1, &UVS_9) )
  {
    if ( PFileNode::IsKeyword(v7, a1, &Weights_9) )
    {
      if ( dstVF->numMatrices != PFileNode::GetNumSubNodes(v7) )
        goto LABEL_59;
      v14 = 0;
      if ( PFileNode::GetNumSubNodes(v7) )
      {
        while ( 1 )
        {
          v15 = (PFileNode *)v7->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, v14);
          a1 = (int)v15;
          if ( !v15 )
            goto LABEL_59;
          if ( PFileNode::GetNumSubNodes(v15) != 2 )
            break;
          matrixWeight = 0.0;
          if ( !PFileNode::GetSubName((PFileNode *)a1, a1, 0, &matrixIndexUINT32) )
          {
            v19 = v17;
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "unable to read matrix index");
            goto LABEL_58;
          }
          if ( !PFileNode::GetSubName((PFileNode *)a1, a1, 1u, &matrixWeight) )
          {
            v19 = v18;
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "unable to read vertex weight");
            goto LABEL_58;
          }
          if ( !SetMatrixWeight(vertex, dstVF, v14, matrixIndexUINT32, matrixWeight) )
            goto LABEL_59;
          ++v14;
          if ( v14 >= PFileNode::GetNumSubNodes(v7) )
            goto LABEL_51;
        }
        v19 = v16;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "invalid vertex weight");
LABEL_58:
        PFileNode::ReportError(a1, (PFileNode *)a1, LODWORD(v19));
        goto LABEL_59;
      }
    }
    goto LABEL_51;
  }
  if ( dstVF->numTCPairs != PFileNode::GetNumSubNodes(v7) )
    goto LABEL_59;
  v11 = 0;
  if ( !PFileNode::GetNumSubNodes(v7) )
    goto LABEL_51;
  while ( 1 )
  {
    v12 = (PFileNode *)v7->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, v11);
    a1 = (int)v12;
    if ( !v12 )
      break;
    if ( PFileNode::GetNumSubNodes(v12) != 2 )
    {
      v19 = v13;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "invalid uv pair");
      goto LABEL_58;
    }
    PFileNode::GetSubName((PFileNode *)a1, a1, 0, tcPair);
    PFileNode::GetSubName((PFileNode *)a1, a1, 1u, &tcPair[1]);
    if ( !SetTCPair(vertex, dstVF, v11, tcPair) )
      break;
    ++v11;
    if ( v11 >= PFileNode::GetNumSubNodes(v7) )
      goto LABEL_51;
  }
LABEL_59:
  PFileNodeIter::~PFileNodeIter(&iter);
  return 0;
}

//----- (005D7CB0) --------------------------------------------------------  // acclient.c:515984
char __cdecl StreamArbitraryVertex(Archive *archive, VertexFormatInfo *dstVF, char *vertex, const unsigned int version)
{
  unsigned int v4; // eax@1
  unsigned int v5; // eax@4
  float v6; // edx@6
  float v7; // ecx@6
  float v8; // ecx@7
  float v9; // edx@7
  unsigned int v10; // eax@8
  int v11; // ebx@10
  float v12; // edi@10
  float v13; // ebp@10
  unsigned int v14; // eax@13
  unsigned int v15; // eax@17
  unsigned int v16; // eax@23
  char *v17; // edx@29
  unsigned int v18; // eax@35
  char *v19; // edi@36
  LOAD_UVPAIR *v20; // edx@37
  int v21; // ebx@38
  unsigned int v22; // eax@44
  unsigned int diffuse; // [sp+10h] [bp-50h]@1
  unsigned int specular; // [sp+14h] [bp-4Ch]@1
  SmartArray<LOAD_UVPAIR,1> uvs; // [sp+18h] [bp-48h]@1
  SmartArray<LOAD_WEIGHTS,1> weights; // [sp+24h] [bp-3Ch]@1
  Vector3 origin; // [sp+30h] [bp-30h]@1
  Vector3 vDummy; // [sp+3Ch] [bp-24h]@1
  Vector3 vectorS; // [sp+48h] [bp-18h]@1
  Vector3 vectorT; // [sp+54h] [bp-Ch]@1
  float versiona; // [sp+70h] [bp+10h]@45

  origin = stru_8EFFFC;
  vDummy = stru_8EFFFC;
  diffuse = -1;
  specular = -1;
  vectorS.y = stru_8EFFFC.y;
  vectorT.y = stru_8EFFFC.y;
  uvs.m_data = 0;
  uvs.m_sizeAndDeallocate = 0;
  uvs.m_num = 0;
  weights.m_data = 0;
  weights.m_sizeAndDeallocate = 0;
  weights.m_num = 0;
  LODWORD(vectorS.x) = (_DWORD)stru_8EFFFC.x;
  vectorS.z = stru_8EFFFC.z;
  LODWORD(vectorT.x) = (_DWORD)stru_8EFFFC.x;
  vectorT.z = stru_8EFFFC.z;
  Archive::CheckAlignment(archive, 4u);
  v4 = Archive::GetBytes(archive, 4u);
  if ( v4 && archive->m_flags & 1 )
    *(_DWORD *)v4 = 0;
  Archive::CheckAlignment(archive, 0xCu);
  v5 = Archive::GetBytes(archive, 0xCu);
  if ( v5 )
  {
    if ( archive->m_flags & 1 )
    {
      v6 = origin.y;
      *(_DWORD *)v5 = (_DWORD)origin.x;
      v7 = origin.z;
      *(float *)(v5 + 4) = v6;
      *(float *)(v5 + 8) = v7;
    }
    else
    {
      v8 = *(float *)(v5 + 4);
      LODWORD(origin.x) = *(_DWORD *)v5;
      v9 = *(float *)(v5 + 8);
      origin.y = v8;
      origin.z = v9;
    }
  }
  Archive::CheckAlignment(archive, 0xCu);
  v10 = Archive::GetBytes(archive, 0xCu);
  if ( v10 )
  {
    if ( archive->m_flags & 1 )
    {
      v11 = (signed int)vDummy.x;
      v12 = vDummy.y;
      v13 = vDummy.z;
      *(_DWORD *)v10 = (_DWORD)vDummy.x;
      *(float *)(v10 + 4) = v12;
      *(float *)(v10 + 8) = v13;
    }
    else
    {
      v11 = *(_DWORD *)v10;
      v12 = *(float *)(v10 + 4);
      v13 = *(float *)(v10 + 8);
    }
  }
  else
  {
    v12 = vDummy.y;
    v13 = vDummy.z;
    v11 = (signed int)vDummy.x;
  }
  Archive::CheckAlignment(archive, 4u);
  v14 = Archive::GetBytes(archive, 4u);
  if ( v14 )
  {
    if ( archive->m_flags & 1 )
      *(_DWORD *)v14 = -1;
    else
      diffuse = *(_DWORD *)v14;
  }
  Archive::CheckAlignment(archive, 4u);
  v15 = Archive::GetBytes(archive, 4u);
  if ( v15 )
  {
    if ( archive->m_flags & 1 )
      *(_DWORD *)v15 = -1;
    else
      specular = *(_DWORD *)v15;
  }
  vDummy.y = stru_8EFFFC.y;
  LODWORD(vDummy.x) = (_DWORD)stru_8EFFFC.x;
  vDummy.z = stru_8EFFFC.z;
  if ( version >= 1 )
  {
    Serializer::SerializeObject(&vectorS, archive);
    Serializer::SerializeObject(&vectorT, archive);
    Serializer::SerializeObject(&vDummy, archive);
  }
  SmartArray<LOAD_UVPAIR,1>::Serialize((SmartArray<LOAD_WEIGHTS,1> *)&uvs, archive);
  SmartArray<LOAD_UVPAIR,1>::Serialize(&weights, archive);
  Archive::CheckAlignment(archive, 4u);
  v16 = Archive::GetBytes(archive, 4u);
  if ( v16 && archive->m_flags & 1 )
    *(_DWORD *)v16 = 0;
  if ( dstVF->format & 2 )
    *(Vector3 *)&vertex[dstVF->offsetOrigin] = origin;
  if ( dstVF->format & 0x10 )
  {
    v17 = &vertex[dstVF->offsetNormal];
    *(_DWORD *)v17 = v11;
    *((float *)v17 + 1) = v12;
    *((float *)v17 + 2) = v13;
  }
  if ( dstVF->format & 0x40 )
    *(_DWORD *)&vertex[dstVF->offsetDiffuse] = diffuse;
  if ( SLOBYTE(dstVF->format) < 0 )
    *(_DWORD *)&vertex[dstVF->offsetSpecular] = specular;
  if ( dstVF->numTCPairs != uvs.m_num )
  {
    if ( (weights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](weights.m_data);
LABEL_64:
    if ( (uvs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](uvs.m_data);
    return 0;
  }
  v18 = 0;
  if ( uvs.m_num )
  {
    v19 = (char *)dstVF->offsetTCPair;
    while ( 1 )
    {
      v20 = &uvs.m_data[v18];
      if ( v18 >= dstVF->numTCPairs )
        break;
      v21 = *(_DWORD *)v19;
      *(_DWORD *)&vertex[v21] = LODWORD(v20->tcPair[0]);
      *(_DWORD *)&vertex[v21 + 4] = LODWORD(v20->tcPair[1]);
      ++v18;
      v19 += 4;
      if ( v18 >= uvs.m_num )
        goto LABEL_39;
    }
    if ( (weights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](weights.m_data);
    if ( (uvs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](uvs.m_data);
      return 0;
    }
    return 0;
  }
LABEL_39:
  if ( dstVF->format & 0x10000000 )
    *(Vector3 *)&vertex[dstVF->offsetVectorS] = vectorS;
  if ( dstVF->format & 0x20000000 )
    *(Vector3 *)&vertex[dstVF->offsetVectorT] = vectorT;
  if ( dstVF->numMatrices != weights.m_num )
  {
    if ( (weights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](weights.m_data);
    if ( (uvs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](uvs.m_data);
      return 0;
    }
    return 0;
  }
  v22 = 0;
  if ( weights.m_num )
  {
    while ( 1 )
    {
      versiona = weights.m_data[v22].matrix_weight;
      if ( v22 >= dstVF->numMatrices )
        break;
      *(&vertex[v22] + dstVF->offsetMatrices) = LOBYTE(weights.m_data[v22].matrix_index);
      *(float *)(&vertex[4 * v22++] + dstVF->offsetMWeights) = versiona;
      if ( v22 >= weights.m_num )
        goto LABEL_47;
    }
    if ( (weights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](weights.m_data);
    goto LABEL_64;
  }
LABEL_47:
  if ( (weights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](weights.m_data);
  if ( (uvs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](uvs.m_data);
  return 1;
}

//----- (005D8100) --------------------------------------------------------  // acclient.c:516205
char __userpurge VertexArray::FromFileNode@<al>(VertexArray *this@<ecx>, int a2@<edi>, PFileNode *_node)
{
  VertexArray *v3; // esi@1
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // eax@4
  PFileNode *v5; // eax@4
  unsigned int v6; // ecx@4
  PFileNode *v7; // ebp@4
  int v8; // eax@6
  unsigned int v9; // esi@8
  PFileNode *v11; // eax@11
  unsigned int v12; // ecx@11
  PFileNode *v13; // eax@14
  PFileNode *v14; // ebp@14
  unsigned int v15; // ecx@17
  int v16; // eax@20
  unsigned int v17; // ecx@20
  int v18; // eax@26
  unsigned int v19; // ecx@28
  void *v20; // ebp@30
  unsigned int v21; // eax@31
  char v22; // bl@31
  int v23; // edi@33
  int v24; // edx@33
  PFileNode *v25; // eax@33
  char v26; // al@33
  unsigned int v27; // ecx@33
  unsigned int v28; // ecx@36
  ReferenceCountTemplate<1048576,1>Vtbl *v29; // eax@39
  unsigned int v30; // [sp+14h] [bp-B0h]@8
  unsigned int iq; // [sp+28h] [bp-9Ch]@4
  bool textFormat; // [sp+2Fh] [bp-95h]@2
  int dummy; // [sp+30h] [bp-94h]@14
  SmartBuffer buff; // [sp+34h] [bp-90h]@20
  AutoStoreVersionArchive archive; // [sp+40h] [bp-84h]@18

  v3 = this;
  if ( !_node )
    return 0;
  textFormat = 1;
  if ( PFileNode::IsKeyword(_node, a2, &BinaryVertexArray_9) )
    textFormat = 0;
  v4 = _node->vfptr;
  iq = 0;
  v5 = (PFileNode *)v4[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_node, 0);
  v7 = v5;
  if ( !v5 )
    goto LABEL_42;
  if ( !PFileNode::IsKeyword(v5, a2, &VertexType_10) )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&iq, "expected ");
    v8 = *(_DWORD *)&VertexType_10.m_charbuffer[-1].m_data[12];
    if ( v8 != 1 )
      PStringBase<char>::append_n_chars((PStringBase<char> *)&iq, VertexType_10.m_charbuffer->m_data, v8 - 1);
    v30 = iq;
    InterlockedIncrement((volatile LONG *)(iq - 16));
    PFileNode::ReportError(a2, v7, (PStringBase<char>)v30);
    v9 = iq - 20;
    if ( !InterlockedDecrement((volatile LONG *)(iq - 20 + 4)) && v9 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      return 0;
    }
    return 0;
  }
  v11 = (PFileNode *)v7->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, 0);
  if ( !v11 || !PFileNode::GetNameAsUInt32(v11, a2, &iq) )
  {
    v30 = v12;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, "invalid vertex type");
    PFileNode::ReportError(a2, v7, (PStringBase<char>)v30);
    return 0;
  }
  a2 = iq & 0xFFFFFF3F;
  v13 = (PFileNode *)_node->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_node, 1u);
  v14 = v13;
  dummy = (int)v13;
  if ( !v13 )
  {
LABEL_42:
    v30 = v6;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, "invalid vertex array");
    PFileNode::ReportError(a2, _node, (PStringBase<char>)v30);
    return 0;
  }
  if ( !PFileNode::IsKeyword(v13, a2, &VertexData_9) )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&iq, "expected ");
    PStringBase<char>::operator+=((PStringBase<char> *)&iq, &VertexData_9);
    v30 = v15;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v30,
      (PStringBase<char> *)&iq);
    PFileNode::ReportError(a2, v14, (PStringBase<char>)v30);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&iq);
    return 0;
  }
  AutoStoreVersionArchive::AutoStoreVersionArchive(&archive);
  if ( textFormat )
  {
    v3->numVertices = PFileNode::GetNumSubNodes(v14);
  }
  else
  {
    SmartBuffer::SmartBuffer(&buff);
    v16 = PFileNode::GetLeaf(v14);
    if ( !v16 || !PFileNode::GetNameAsBinary((PFileNode *)v16, a2, &buff) )
    {
      v30 = v17;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, "corrupt vertex data");
      PFileNode::ReportError(a2, v14, (PStringBase<char>)v30);
      SmartBuffer::ReleaseMasterBuffer(&buff);
LABEL_23:
      AutoStoreVersionArchive::~AutoStoreVersionArchive(&archive);
      return 0;
    }
    AutoStoreVersionArchive::InitForUnpacking(&archive, &buff);
    SB_As32Bit_Compressed::Serialize(&dummy, &v3->numVertices, (Archive *)&archive.vfptr);
    SmartBuffer::ReleaseMasterBuffer(&buff);
  }
  VertexArray::RequestStripHWExtraTexCoords(v3, 1);
  LOBYTE(v18) = 1;
  LOBYTE(iq) = 1;
  if ( a2 & 0xFF0000 )
  {
    LOBYTE(v18) = 0;
    LOBYTE(iq) = 0;
  }
  LOBYTE(v18) = (_BYTE)v18 != 0;
  if ( !(unsigned __int8)((int (__thiscall *)(VertexArray *, unsigned int, int, unsigned int, int, signed int))v3->vfptr[1].__vecDelDtor)(
                           v3,
                           v3->numVertices,
                           a2,
                           iq,
                           v18,
                           -1) )
  {
    v30 = v19;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, "could not allocate vertex array");
    PFileNode::ReportError(a2, v14, (PStringBase<char>)v30);
    goto LABEL_23;
  }
  v20 = (void *)((int (__thiscall *)(VertexArray *, _DWORD, unsigned int))v3->vfptr[3].__vecDelDtor)(
                  v3,
                  0,
                  v3->numVertices);
  if ( !v20 )
    goto LABEL_23;
  v21 = v3->numVertices;
  v22 = 1;
  iq = 0;
  if ( v21 )
  {
    while ( 1 )
    {
      memset(v20, 0, v3->vertexFormat.size);
      if ( textFormat )
      {
        v23 = dummy;
        v24 = *(_DWORD *)dummy;
        v30 = (unsigned int)v20;
        v25 = (PFileNode *)(*(int (__thiscall **)(int, unsigned int))(v24 + 12))(dummy, iq);
        v26 = LoadArbitraryVertex(v23, v25, &v3->vertexFormat, (char *)v20);
      }
      else
      {
        v26 = StreamArbitraryVertex((Archive *)&archive.vfptr, &v3->vertexFormat, (char *)v20, 1u);
        v23 = dummy;
      }
      v22 &= v26;
      if ( !v22 )
        break;
      v28 = v3->numVertices;
      v20 = (char *)v20 + v3->vertexFormat.size;
      ++iq;
      if ( iq >= v28 )
        goto LABEL_39;
    }
    v30 = v27;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, "could not read vertex");
    PFileNode::ReportError(v23, (PFileNode *)v23, (PStringBase<char>)v30);
  }
LABEL_39:
  v29 = v3->vfptr;
  v30 = 1;
  ((void (__thiscall *)(VertexArray *, signed int, signed int))v29[4].__vecDelDtor)(v3, 1, 1);
  AutoStoreVersionArchive::OnSerializingDone(&archive);
  AutoStoreVersionArchive::~AutoStoreVersionArchive(&archive);
  return v22;
}

//----- (005D84B0) --------------------------------------------------------  // acclient.c:516396
void __thiscall VertexArray::ComputeInfluencedBoneIndices(VertexArray *this)
{
  VertexArray *v1; // ecx@2
  unsigned int v2; // ebp@3
  int v3; // edx@4
  unsigned int v4; // ebx@5
  HashSetData<unsigned long> *v5; // eax@5
  int v6; // esi@10
  int v7; // eax@10
  unsigned int v8; // edx@11
  int v9; // ST1C_4@16
  VertexArray *v15; // [sp+0h] [bp-80h]@1
  int VertexIndex; // [sp+4h] [bp-7Ch]@2
  HashSet<unsigned long> InfluencedBones; // [sp+Ch] [bp-74h]@2

  v15 = this;
  this->m_InfluencedBoneIndexArray.m_num = 0;
  if ( this->vertexFormat.numMatrices )
  {
    IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(
      &InfluencedBones.m_intrusiveTable,
      0x17u);
    v1 = v15;
    for ( VertexIndex = v15->numVertices - 1; VertexIndex >= 0; --VertexIndex )
    {
      v2 = 0;
      if ( v1->vertexFormat.numMatrices )
      {
        do
        {
          v3 = (int)((char *)v1->vertices + VertexIndex * v1->vertexFormat.size);
          if ( *(float *)(v1->vertexFormat.offsetMWeights + v3) > 0.00019999999 )
          {
            v4 = *(_BYTE *)(v1->vertexFormat.offsetMatrices + v3);
            v5 = InfluencedBones.m_intrusiveTable.m_buckets[v4 % InfluencedBones.m_intrusiveTable.m_numBuckets];
            if ( !v5 )
              goto LABEL_10;
            while ( v5->m_hashKey != v4 )
            {
              v5 = v5->m_hashNext;
              if ( !v5 )
                goto LABEL_10;
            }
            if ( !v5 )
            {
LABEL_10:
              v6 = (int)&v1->m_InfluencedBoneIndexArray;
              v7 = v1->m_InfluencedBoneIndexArray.m_sizeAndDeallocate & 0x7FFFFFFF;
              if ( v1->m_InfluencedBoneIndexArray.m_num < v7 )
                goto LABEL_27;
              v8 = v7 + 1;
              if ( (unsigned int)(v7 + 1) > 8 )
              {
                if ( v8 <= 0x4000 )
                {
                  v9 = v7 + 1;
                  __asm { bsr     this, [esp+90h+var_78] }
                  if ( v8 > 1 << _EAX )
                    v8 = 2 * (1 << _EAX);
                }
                else if ( v8 & 0x3FFF )
                {
                  v8 += 0x4000 - (v8 & 0x3FFF);
                }
              }
              else
              {
                v8 = 8;
              }
              if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v6, v8) )
LABEL_27:
                *(_DWORD *)(*(_DWORD *)v6 + 4 * (*(_DWORD *)(v6 + 8))++) = v4;
              v1 = v15;
            }
          }
          ++v2;
        }
        while ( v2 < v1->vertexFormat.numMatrices );
      }
    }
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&InfluencedBones.m_intrusiveTable);
    InfluencedBones.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
    if ( (HashSetData<unsigned long> **)InfluencedBones.m_intrusiveTable.m_buckets != InfluencedBones.m_intrusiveTable.m_aInplaceBuckets )
      operator delete[](InfluencedBones.m_intrusiveTable.m_buckets);
  }
}
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);

//----- (005D8640) --------------------------------------------------------  // acclient.c:516485
void __thiscall VertexArray::Unlock(VertexArray *this, const bool _bRecalcBounds, const bool _bRecalcBoneInfluences)
{
  VertexArray *v3; // esi@1

  v3 = this;
  this->locked = 0;
  if ( _bRecalcBounds )
    VertexArray::GenerateBoundingBox(this);
  if ( _bRecalcBoneInfluences )
    VertexArray::ComputeInfluencedBoneIndices(v3);
}

//----- (007104E0) --------------------------------------------------------  // acclient.c:803585
int sub_7104E0()
{
  PStringBase<char>::PStringBase<char>(&PHeader_11, "PREPROC_HEADER");
  return atexit(_E74_95);
}

//----- (00710500) --------------------------------------------------------  // acclient.c:803592
int _E76_78()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_9, "VertexArray");
  return atexit(sub_779550);
}

//----- (00710520) --------------------------------------------------------  // acclient.c:803599
int _E79_73()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_9, "BinaryVertexArray");
  return atexit(_E80_71);
}

//----- (00710540) --------------------------------------------------------  // acclient.c:803606
int _E82_49()
{
  PStringBase<char>::PStringBase<char>(&VertexType_10, "VertexType");
  return atexit(_E83_47);
}

//----- (00710560) --------------------------------------------------------  // acclient.c:803613
int _E85_35()
{
  PStringBase<char>::PStringBase<char>(&VertexData_9, "VertexData");
  return atexit(_E86_28);
}

//----- (00710580) --------------------------------------------------------  // acclient.c:803620
int _E88_25()
{
  PStringBase<char>::PStringBase<char>(&Vertex_9, "Vertex");
  return atexit(_E89_38);
}

//----- (007105A0) --------------------------------------------------------  // acclient.c:803627
int sub_7105A0()
{
  PStringBase<char>::PStringBase<char>(&Index_19, "Index");
  return atexit(_E92_43);
}

//----- (007105C0) --------------------------------------------------------  // acclient.c:803634
int _E94_34()
{
  PStringBase<char>::PStringBase<char>(&Origin_19, "P");
  return atexit(sub_779670);
}

//----- (007105E0) --------------------------------------------------------  // acclient.c:803641
int sub_7105E0()
{
  PStringBase<char>::PStringBase<char>(&Normal_9, "N");
  return atexit(sub_7796A0);
}

//----- (00710600) --------------------------------------------------------  // acclient.c:803648
int sub_710600()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_19, "Diffuse");
  return atexit(sub_7796D0);
}

//----- (00710620) --------------------------------------------------------  // acclient.c:803655
int sub_710620()
{
  PStringBase<char>::PStringBase<char>(&Specular_19, "Specular");
  return atexit(sub_779700);
}

//----- (00710640) --------------------------------------------------------  // acclient.c:803662
int sub_710640()
{
  PStringBase<char>::PStringBase<char>(&UVS_9, "UVS");
  return atexit(sub_779730);
}

//----- (00710660) --------------------------------------------------------  // acclient.c:803669
int _E109_86()
{
  PStringBase<char>::PStringBase<char>(&VectorS_9, "VectorS");
  return atexit(sub_779760);
}

//----- (00710680) --------------------------------------------------------  // acclient.c:803676
int sub_710680()
{
  PStringBase<char>::PStringBase<char>(&VectorT_9, "VectorT");
  return atexit(_E113_73);
}

//----- (007106A0) --------------------------------------------------------  // acclient.c:803683
int _E115_92()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_9, "VectorSxT");
  return atexit(_E116_65);
}

//----- (007106C0) --------------------------------------------------------  // acclient.c:803690
int _E118_83()
{
  PStringBase<char>::PStringBase<char>(&Weights_9, "Weights");
  return atexit(_E119_91);
}

//----- (007106E0) --------------------------------------------------------  // acclient.c:803697
int _E121_76()
{
  PStringBase<char>::PStringBase<char>(&Importance_9, "Importance");
  return atexit(sub_779820);
}

//----- (00710700) --------------------------------------------------------  // acclient.c:803704
int _E124_74()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_9, "PhysMtl");
  return atexit(_E125_71);
}

//----- (00710720) --------------------------------------------------------  // acclient.c:803711
int _E127_63()
{
  PStringBase<char>::PStringBase<char>(&Material_42, "Material");
  return atexit(_E128_69);
}

//----- (00710740) --------------------------------------------------------  // acclient.c:803718
int _E130_57()
{
  PStringBase<char>::PStringBase<char>(&ID_22, "ID");
  return atexit(_E131_58);
}

//----- (00710760) --------------------------------------------------------  // acclient.c:803725
int _E133_49()
{
  PStringBase<char>::PStringBase<char>(&FileName_9, "FileName");
  return atexit(_E134_42);
}

//----- (00710780) --------------------------------------------------------  // acclient.c:803732
int _E136_34()
{
  PStringBase<char>::PStringBase<char>(&Polygon_19, "Polygon");
  return atexit(_E137_41);
}

//----- (007107A0) --------------------------------------------------------  // acclient.c:803739
int _E139_34()
{
  PStringBase<char>::PStringBase<char>(&ID_23, "ID");
  return atexit(_E140_35);
}

//----- (007107C0) --------------------------------------------------------  // acclient.c:803746
int _E142_31()
{
  PStringBase<char>::PStringBase<char>(&Indices_15, "INDICES");
  return atexit(_E143_35);
}

//----- (007107E0) --------------------------------------------------------  // acclient.c:803753
int _E145_33()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_9, "MaterialID");
  return atexit(_E146_35);
}

//----- (00710800) --------------------------------------------------------  // acclient.c:803760
int _E148_32()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_9, "PhysMaterialID");
  return atexit(_E149_34);
}

//----- (00710820) --------------------------------------------------------  // acclient.c:803767
int _E151_30()
{
  PStringBase<char>::PStringBase<char>(&Markings_9, "Markings");
  return atexit(_E152_35);
}

//----- (00710840) --------------------------------------------------------  // acclient.c:803774
int _E154_31()
{
  PStringBase<char>::PStringBase<char>(&Material_43, "Material");
  return atexit(_E155_31);
}

//----- (00710860) --------------------------------------------------------  // acclient.c:803781
int _E157_28()
{
  PStringBase<char>::PStringBase<char>(&Index_20, "Index");
  return atexit(_E158_32);
}

//----- (00710880) --------------------------------------------------------  // acclient.c:803788
int _E160_31()
{
  PStringBase<char>::PStringBase<char>(&Filename_9, "Filename");
  return atexit(_E161_29);
}

//----- (007108A0) --------------------------------------------------------  // acclient.c:803795
int _E163_24()
{
  PStringBase<char>::PStringBase<char>(&Surface_9, "Surface");
  return atexit(_E164_31);
}

//----- (007108C0) --------------------------------------------------------  // acclient.c:803802
int _E166_26()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_9, "CellPoly");
  return atexit(_E167_27);
}

//----- (007108E0) --------------------------------------------------------  // acclient.c:803809
int _E169_24()
{
  PStringBase<char>::PStringBase<char>(&Sphere_12, "Sphere");
  return atexit(_E170_27);
}

//----- (00710900) --------------------------------------------------------  // acclient.c:803816
int _E172_22()
{
  PStringBase<char>::PStringBase<char>(&Side_9, "Side");
  return atexit(_E173_22);
}

//----- (00710920) --------------------------------------------------------  // acclient.c:803823
int _E175_19()
{
  PStringBase<char>::PStringBase<char>(&Positive_9, "Positive");
  return atexit(_E176_24);
}

//----- (00710940) --------------------------------------------------------  // acclient.c:803830
int _E178_19()
{
  PStringBase<char>::PStringBase<char>(&Negative_9, "Negative");
  return atexit(_E179_23);
}

//----- (00710960) --------------------------------------------------------  // acclient.c:803837
int _E181_19()
{
  PStringBase<char>::PStringBase<char>(&Polygon_20, "PolygonIndex");
  return atexit(_E182_23);
}

//----- (00710980) --------------------------------------------------------  // acclient.c:803844
int _E184_17()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_19, "OtherCellMeshIndex");
  return atexit(_E185_20);
}

//----- (007109A0) --------------------------------------------------------  // acclient.c:803851
int _E187_16()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_9, "CellPortal");
  return atexit(_E188_21);
}

//----- (007109C0) --------------------------------------------------------  // acclient.c:803858
int _E190_17()
{
  PStringBase<char>::PStringBase<char>(&Portal_12, "PortalIndex");
  return atexit(_E191_20);
}

//----- (007109E0) --------------------------------------------------------  // acclient.c:803865
int _E193_16()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_20, "OtherCellID");
  return atexit(_E194_27);
}

//----- (00710A00) --------------------------------------------------------  // acclient.c:803872
int _E196_23()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_9, "OtherPortalIndex");
  return atexit(_E197_17);
}

//----- (00710A20) --------------------------------------------------------  // acclient.c:803879
int _E199_15()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_9, "ExactMatch");
  return atexit(_E200_21);
}

//----- (00710A40) --------------------------------------------------------  // acclient.c:803886
int _E202_19()
{
  PStringBase<char>::PStringBase<char>(&StabList_9, "StabList");
  return atexit(_E203_20);
}

//----- (00710A60) --------------------------------------------------------  // acclient.c:803893
int _E205_16()
{
  PStringBase<char>::PStringBase<char>(&Period_9, "Period");
  return atexit(_E206_23);
}

//----- (00710A80) --------------------------------------------------------  // acclient.c:803900
int _E208_21()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_9, "GrannyAnimation");
  return atexit(_E209_18);
}

//----- (00710AA0) --------------------------------------------------------  // acclient.c:803907
int _E211_16()
{
  PStringBase<char>::PStringBase<char>(&Transform_9, "Transform");
  return atexit(_E212_21);
}

//----- (00710AC0) --------------------------------------------------------  // acclient.c:803914
int _E214_18()
{
  PStringBase<char>::PStringBase<char>(&Scale_29, "Scale");
  return atexit(_E215_18);
}

//----- (00710AE0) --------------------------------------------------------  // acclient.c:803921
int _E217_15()
{
  PStringBase<char>::PStringBase<char>(&Weight_9, "Weight");
  return atexit(_E218_18);
}

//----- (00710B00) --------------------------------------------------------  // acclient.c:803928
int _E220_15()
{
  PStringBase<char>::PStringBase<char>(&Offset_9, "Offset");
  return atexit(_E221_18);
}

//----- (00710B20) --------------------------------------------------------  // acclient.c:803935
int _E223_16()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_10, "Quaternion");
  return atexit(_E224_18);
}

//----- (00710B40) --------------------------------------------------------  // acclient.c:803942
int _E226_15()
{
  PStringBase<char>::PStringBase<char>(&Rotation_19, "Rotation");
  return atexit(_E227_18);
}

//----- (00710B60) --------------------------------------------------------  // acclient.c:803949
int _E229_16()
{
  PStringBase<char>::PStringBase<char>(&STime_9, "STime");
  return atexit(_E230_19);
}

//----- (00710B80) --------------------------------------------------------  // acclient.c:803956
int _E232_16()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_9, "PhysicsSplines");
  return atexit(_E233_18);
}

//----- (00710BA0) --------------------------------------------------------  // acclient.c:803963
int _E235_16()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_9, "BoneOpacities");
  return atexit(_E236_17);
}

//----- (00710BC0) --------------------------------------------------------  // acclient.c:803970
int _E238_14()
{
  PStringBase<char>::PStringBase<char>(&LowPt_9, "LowPoint");
  return atexit(_E239_17);
}

//----- (00710BE0) --------------------------------------------------------  // acclient.c:803977
int _E241_14()
{
  PStringBase<char>::PStringBase<char>(&Radius_9, "Radius");
  return atexit(_E242_17);
}

//----- (00710C00) --------------------------------------------------------  // acclient.c:803984
int _E244_14()
{
  PStringBase<char>::PStringBase<char>(&Height_9, "Height");
  return atexit(_E245_16);
}

//----- (00710C20) --------------------------------------------------------  // acclient.c:803991
int _E247_13()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_9, "Texture2D");
  return atexit(_E248_16);
}

//----- (00710C40) --------------------------------------------------------  // acclient.c:803998
int _E250_13()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_9, "Texture3D");
  return atexit(_E251_15);
}

//----- (00710C60) --------------------------------------------------------  // acclient.c:804005
int _E253_13()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_9, "TextureCube");
  return atexit(_E254_16);
}

//----- (00710C80) --------------------------------------------------------  // acclient.c:804012
int _E256_13()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_9, "TextureMovie2D");
  return atexit(_E257_14);
}

//----- (00710CA0) --------------------------------------------------------  // acclient.c:804019
int _E259_14()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_9, "MovieFile");
  return atexit(_E260_15);
}

//----- (00710CC0) --------------------------------------------------------  // acclient.c:804026
int _E262_14()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_9, "MovieFPS");
  return atexit(_E263_14);
}

//----- (00710CE0) --------------------------------------------------------  // acclient.c:804033
int _E265_14()
{
  PStringBase<char>::PStringBase<char>(&Levels_9, "Levels");
  return atexit(_E266_14);
}

//----- (00710D00) --------------------------------------------------------  // acclient.c:804040
int _E268_13()
{
  PStringBase<char>::PStringBase<char>(&stru_8F010C, "Instance");
  return atexit(_E269_13);
}

//----- (00710D20) --------------------------------------------------------  // acclient.c:804047
int _E271_12()
{
  PStringBase<char>::PStringBase<char>(&Material_44, "Material");
  return atexit(_E272_12);
}

//----- (00710D40) --------------------------------------------------------  // acclient.c:804054
int _E274_12()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_9, "MaterialType");
  return atexit(_E275_12);
}

//----- (00710D60) --------------------------------------------------------  // acclient.c:804061
int _E277_12()
{
  PStringBase<char>::PStringBase<char>(&Modifier_9, "Modifier");
  return atexit(_E278_12);
}

//----- (00710D80) --------------------------------------------------------  // acclient.c:804068
int _E280_11()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_9, "AllowStencilShadows");
  return atexit(_E281_12);
}

//----- (00710DA0) --------------------------------------------------------  // acclient.c:804075
int _E283_11()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_9, "DiscardGeometry");
  return atexit(_E284_10);
}

//----- (00710DC0) --------------------------------------------------------  // acclient.c:804082
int _E286_10()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0124, "Material");
  return atexit(_E287_11);
}

//----- (00710DE0) --------------------------------------------------------  // acclient.c:804089
int _E289_9()
{
  PStringBase<char>::PStringBase<char>(&SortMode_9, "SortMode");
  return atexit(_E290_10);
}

//----- (00710E00) --------------------------------------------------------  // acclient.c:804096
int _E292_10()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_9, "None");
  return atexit(_E293_9);
}

//----- (00710E20) --------------------------------------------------------  // acclient.c:804103
int _E295_9()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_9, "Triangle");
  return atexit(_E296_10);
}

//----- (00710E40) --------------------------------------------------------  // acclient.c:804110
int _E298_10()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0134, "Modifier");
  return atexit(_E299_8);
}

//----- (00710E60) --------------------------------------------------------  // acclient.c:804117
int _E301_8()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0138, "Property");
  return atexit(_E302_9);
}

//----- (00710E80) --------------------------------------------------------  // acclient.c:804124
int _E304_9()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_9, "Data");
  return atexit(_E305_8);
}

//----- (00710EA0) --------------------------------------------------------  // acclient.c:804131
int _E307_8()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_9, "Waveform");
  return atexit(_E308_9);
}

//----- (00710EC0) --------------------------------------------------------  // acclient.c:804138
int _E310_9()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_9, "Color");
  return atexit(_E311_8);
}

//----- (00710EE0) --------------------------------------------------------  // acclient.c:804145
int _E313_8()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_9, "Texture");
  return atexit(_E314_9);
}

//----- (00710F00) --------------------------------------------------------  // acclient.c:804152
int _E316_9()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_9, "Bool");
  return atexit(_E317_8);
}

//----- (00710F20) --------------------------------------------------------  // acclient.c:804159
int _E319_8()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0150, "Layer");
  return atexit(_E320_9);
}

//----- (00710F40) --------------------------------------------------------  // acclient.c:804166
int _E322_8()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_9, "UVTranslate");
  return atexit(_E323_7);
}

//----- (00710F60) --------------------------------------------------------  // acclient.c:804173
int _E325_7()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_9, "UVRotate");
  return atexit(_E326_8);
}

//----- (00710F80) --------------------------------------------------------  // acclient.c:804180
int _E328_8()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_9, "UVScale");
  return atexit(_E329_7);
}

//----- (00710FA0) --------------------------------------------------------  // acclient.c:804187
int _E331_7()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_9, "UVTransform");
  return atexit(_E332_8);
}

//----- (00710FC0) --------------------------------------------------------  // acclient.c:804194
int _E334_7()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_9, "TrueFlags");
  return atexit(_E335_7);
}

//----- (00710FE0) --------------------------------------------------------  // acclient.c:804201
int _E337_7()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_9, "FalseFlags");
  return atexit(_E338_7);
}

//----- (00711000) --------------------------------------------------------  // acclient.c:804208
int _E340_7()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_9, "RenderPass");
  return atexit(_E341_7);
}

//----- (00711020) --------------------------------------------------------  // acclient.c:804215
int _E343_4()
{
  PStringBase<char>::PStringBase<char>(&Blend_9, "Blend");
  return atexit(_E344_4);
}

//----- (00711040) --------------------------------------------------------  // acclient.c:804222
int _E346_4()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_9, "DepthTest");
  return atexit(_E347_4);
}

//----- (00711060) --------------------------------------------------------  // acclient.c:804229
int _E349_4()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_9, "DepthWrite");
  return atexit(_E350_4);
}

//----- (00711080) --------------------------------------------------------  // acclient.c:804236
int _E352_4()
{
  PStringBase<char>::PStringBase<char>(&CullMode_9, "CullMode");
  return atexit(_E353_4);
}

//----- (007110A0) --------------------------------------------------------  // acclient.c:804243
int _E355_4()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_9, "DepthFog");
  return atexit(_E356_4);
}

//----- (007110C0) --------------------------------------------------------  // acclient.c:804250
int _E358_4()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_9, "AlphaTestMode");
  return atexit(_E359_4);
}

//----- (007110E0) --------------------------------------------------------  // acclient.c:804257
int _E361_4()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_9, "AlphaTestRef");
  return atexit(_E362_4);
}

//----- (00711100) --------------------------------------------------------  // acclient.c:804264
int _E364_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_9, "FFUseLighting");
  return atexit(_E365_4);
}

//----- (00711120) --------------------------------------------------------  // acclient.c:804271
int _E367_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_9, "FFUseDyeColorInTFactor");
  return atexit(_E368_4);
}

//----- (00711140) --------------------------------------------------------  // acclient.c:804278
int _E370_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_9, "FFUseSpecularLighting");
  return atexit(_E371_4);
}

//----- (00711160) --------------------------------------------------------  // acclient.c:804285
int _E373_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_9, "FFUseDistanceFog");
  return atexit(_E374_4);
}

//----- (00711180) --------------------------------------------------------  // acclient.c:804292
int _E376_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_9, "FFUseVertexDiffuse");
  return atexit(_E377_4);
}

//----- (007111A0) --------------------------------------------------------  // acclient.c:804299
int _E379_4()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_9, "FFUseVertexSpecular");
  return atexit(_E380_4);
}

//----- (007111C0) --------------------------------------------------------  // acclient.c:804306
int _E382_4()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_9, "ShaderSupportsDynamicLights");
  return atexit(_E383_4);
}

//----- (007111E0) --------------------------------------------------------  // acclient.c:804313
int _E385_4()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_9, "UsesTransparency");
  return atexit(_E386_4);
}

//----- (00711200) --------------------------------------------------------  // acclient.c:804320
int _E388_4()
{
  PStringBase<char>::PStringBase<char>(&Ambient_9, "Ambient");
  return atexit(_E389_4);
}

//----- (00711220) --------------------------------------------------------  // acclient.c:804327
int _E391_4()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_20, "Diffuse");
  return atexit(_E392_4);
}

//----- (00711240) --------------------------------------------------------  // acclient.c:804334
int _E394_4()
{
  PStringBase<char>::PStringBase<char>(&Specular_20, "Specular");
  return atexit(_E395_4);
}

//----- (00711260) --------------------------------------------------------  // acclient.c:804341
int _E397_4()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_9, "SpecularPower");
  return atexit(_E398_4);
}

//----- (00711280) --------------------------------------------------------  // acclient.c:804348
int _E400_4()
{
  PStringBase<char>::PStringBase<char>(&Dye_9, "Dye");
  return atexit(_E401_4);
}

//----- (007112A0) --------------------------------------------------------  // acclient.c:804355
int _E403_4()
{
  PStringBase<char>::PStringBase<char>(&Emissive_9, "Emissive");
  return atexit(_E404_4);
}

//----- (007112C0) --------------------------------------------------------  // acclient.c:804362
int _E406_4()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_9, "VertexFormat");
  return atexit(_E407_4);
}

//----- (007112E0) --------------------------------------------------------  // acclient.c:804369
int _E409_4()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_9, "VertexShader");
  return atexit(_E410_4);
}

//----- (00711300) --------------------------------------------------------  // acclient.c:804376
int _E412_4()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_9, "PixelShader");
  return atexit(_E413_4);
}

//----- (00711320) --------------------------------------------------------  // acclient.c:804383
int _E415_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_9, "None");
  return atexit(_E416_4);
}

//----- (00711340) --------------------------------------------------------  // acclient.c:804390
int _E418_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_9, "Reflections");
  return atexit(_E419_4);
}

//----- (00711360) --------------------------------------------------------  // acclient.c:804397
int _E421_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_9, "VideoPost");
  return atexit(_E422_4);
}

//----- (00711380) --------------------------------------------------------  // acclient.c:804404
int _E424_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_9, "HighDetail");
  return atexit(_E425_4);
}

//----- (007113A0) --------------------------------------------------------  // acclient.c:804411
int _E427_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_9, "Specular");
  return atexit(_E428_4);
}

//----- (007113C0) --------------------------------------------------------  // acclient.c:804418
int _E430_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_9, "Class1");
  return atexit(_E431_4);
}

//----- (007113E0) --------------------------------------------------------  // acclient.c:804425
int _E433_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_9, "Class2");
  return atexit(_E434_4);
}

//----- (00711400) --------------------------------------------------------  // acclient.c:804432
int _E436_4()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_9, "Class3");
  return atexit(_E437_4);
}

//----- (00711420) --------------------------------------------------------  // acclient.c:804439
int _E439_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_9, "Default");
  return atexit(_E440_4);
}

//----- (00711440) --------------------------------------------------------  // acclient.c:804446
int _E442_4()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_9,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E443_4);
}

//----- (00711460) --------------------------------------------------------  // acclient.c:804455
int _E445_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_9, "PointLightDiffuseAndSpecular");
  return atexit(_E446_4);
}

//----- (00711480) --------------------------------------------------------  // acclient.c:804462
int _E448_4()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_9,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E449_4);
}

//----- (007114A0) --------------------------------------------------------  // acclient.c:804471
int _E451_4()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_9,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E452_4);
}

//----- (007114C0) --------------------------------------------------------  // acclient.c:804480
int _E454_4()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_9,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E455_4);
}

//----- (007114E0) --------------------------------------------------------  // acclient.c:804489
int _E457_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_9, "DistanceFog");
  return atexit(_E458_4);
}

//----- (00711500) --------------------------------------------------------  // acclient.c:804496
int _E460_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_9, "FFGlow");
  return atexit(_E461_4);
}

//----- (00711520) --------------------------------------------------------  // acclient.c:804503
int _E463_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_9, "ShaderGlow");
  return atexit(_E464_4);
}

//----- (00711540) --------------------------------------------------------  // acclient.c:804510
int _E466_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_9, "LandscapeShadowMap");
  return atexit(_E467_4);
}

//----- (00711560) --------------------------------------------------------  // acclient.c:804517
int _E469_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_9, "AlphaBlend");
  return atexit(_E470_4);
}

//----- (00711580) --------------------------------------------------------  // acclient.c:804524
int _E472_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_9, "AL_0DL_0PL");
  return atexit(_E473_4);
}

//----- (007115A0) --------------------------------------------------------  // acclient.c:804531
int _E475_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_9, "AL_0DL_1PL");
  return atexit(_E476_4);
}

//----- (007115C0) --------------------------------------------------------  // acclient.c:804538
int _E478_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_9, "AL_0DL_2PL");
  return atexit(_E479_4);
}

//----- (007115E0) --------------------------------------------------------  // acclient.c:804545
int _E481_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_9, "AL_0DL_3PL");
  return atexit(_E482_4);
}

//----- (00711600) --------------------------------------------------------  // acclient.c:804552
int _E484_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_9, "AL_0DL_4PL");
  return atexit(_E485_4);
}

//----- (00711620) --------------------------------------------------------  // acclient.c:804559
int _E487_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_9, "AL_0DL_5PL");
  return atexit(_E488_4);
}

//----- (00711640) --------------------------------------------------------  // acclient.c:804566
int _E490_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_9, "AL_0DL_6PL");
  return atexit(_E491_4);
}

//----- (00711660) --------------------------------------------------------  // acclient.c:804573
int _E493_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_9, "AL_0DL_7PL");
  return atexit(_E494_4);
}

//----- (00711680) --------------------------------------------------------  // acclient.c:804580
int _E496_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_9, "AL_0DL_8PL");
  return atexit(_E497_4);
}

//----- (007116A0) --------------------------------------------------------  // acclient.c:804587
int _E499_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_9, "AL_1DL_0PL");
  return atexit(_E500_4);
}

//----- (007116C0) --------------------------------------------------------  // acclient.c:804594
int _E502_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_9, "AL_1DL_1PL");
  return atexit(_E503_4);
}

//----- (007116E0) --------------------------------------------------------  // acclient.c:804601
int _E505_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_9, "AL_1DL_2PL");
  return atexit(_E506_4);
}

//----- (00711700) --------------------------------------------------------  // acclient.c:804608
int _E508_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_9, "AL_1DL_3PL");
  return atexit(_E509_4);
}

//----- (00711720) --------------------------------------------------------  // acclient.c:804615
int _E511_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_9, "AL_1DL_4PL");
  return atexit(_E512_4);
}

//----- (00711740) --------------------------------------------------------  // acclient.c:804622
int _E514_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_9, "AL_1DL_5PL");
  return atexit(_E515_4);
}

//----- (00711760) --------------------------------------------------------  // acclient.c:804629
int _E517_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_9, "AL_1DL_6PL");
  return atexit(_E518_4);
}

//----- (00711780) --------------------------------------------------------  // acclient.c:804636
int _E520_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_9, "AL_1DL_7PL");
  return atexit(_E521_4);
}

//----- (007117A0) --------------------------------------------------------  // acclient.c:804643
int _E523_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_9, "AL_0DL_0PL_Fog");
  return atexit(_E524_4);
}

//----- (007117C0) --------------------------------------------------------  // acclient.c:804650
int _E526_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_9, "AL_0DL_1PL_Fog");
  return atexit(_E527_4);
}

//----- (007117E0) --------------------------------------------------------  // acclient.c:804657
int _E529_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_9, "AL_0DL_2PL_Fog");
  return atexit(_E530_4);
}

//----- (00711800) --------------------------------------------------------  // acclient.c:804664
int _E532_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_9, "AL_0DL_3PL_Fog");
  return atexit(_E533_4);
}

//----- (00711820) --------------------------------------------------------  // acclient.c:804671
int _E535_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_9, "AL_0DL_4PL_Fog");
  return atexit(_E536_4);
}

//----- (00711840) --------------------------------------------------------  // acclient.c:804678
int _E538_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_9, "AL_0DL_5PL_Fog");
  return atexit(_E539_4);
}

//----- (00711860) --------------------------------------------------------  // acclient.c:804685
int _E541_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_9, "AL_0DL_6PL_Fog");
  return atexit(_E542_4);
}

//----- (00711880) --------------------------------------------------------  // acclient.c:804692
int _E544_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_9, "AL_0DL_7PL_Fog");
  return atexit(_E545_4);
}

//----- (007118A0) --------------------------------------------------------  // acclient.c:804699
int _E547_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_9, "AL_0DL_8PL_Fog");
  return atexit(_E548_4);
}

//----- (007118C0) --------------------------------------------------------  // acclient.c:804706
int _E550_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_9, "AL_1DL_0PL_Fog");
  return atexit(_E551_4);
}

//----- (007118E0) --------------------------------------------------------  // acclient.c:804713
int _E553_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_9, "AL_1DL_1PL_Fog");
  return atexit(_E554_4);
}

//----- (00711900) --------------------------------------------------------  // acclient.c:804720
int _E556_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_9, "AL_1DL_2PL_Fog");
  return atexit(_E557_4);
}

//----- (00711920) --------------------------------------------------------  // acclient.c:804727
int _E559_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_9, "AL_1DL_3PL_Fog");
  return atexit(_E560_4);
}

//----- (00711940) --------------------------------------------------------  // acclient.c:804734
int _E562_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_9, "AL_1DL_4PL_Fog");
  return atexit(_E563_4);
}

//----- (00711960) --------------------------------------------------------  // acclient.c:804741
int _E565_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_9, "AL_1DL_5PL_Fog");
  return atexit(_E566_4);
}

//----- (00711980) --------------------------------------------------------  // acclient.c:804748
int _E568_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_9, "AL_1DL_6PL_Fog");
  return atexit(_E569_4);
}

//----- (007119A0) --------------------------------------------------------  // acclient.c:804755
int _E571_4()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_9, "AL_1DL_7PL_Fog");
  return atexit(_E572_4);
}

//----- (007119C0) --------------------------------------------------------  // acclient.c:804762
int _E574_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_9, "Zero");
  return atexit(_E575_4);
}

//----- (007119E0) --------------------------------------------------------  // acclient.c:804769
int _E577_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_9, "One");
  return atexit(_E578_4);
}

//----- (00711A00) --------------------------------------------------------  // acclient.c:804776
int _E580_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_9, "SrcColor");
  return atexit(_E581_4);
}

//----- (00711A20) --------------------------------------------------------  // acclient.c:804783
int _E583_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_9, "InvSrcColor");
  return atexit(_E584_4);
}

//----- (00711A40) --------------------------------------------------------  // acclient.c:804790
int _E586_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_9, "SrcAlpha");
  return atexit(_E587_4);
}

//----- (00711A60) --------------------------------------------------------  // acclient.c:804797
int _E589_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_9, "InvSrcAlpha");
  return atexit(_E590_4);
}

//----- (00711A80) --------------------------------------------------------  // acclient.c:804804
int _E592_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_9, "DstAlpha");
  return atexit(_E593_4);
}

//----- (00711AA0) --------------------------------------------------------  // acclient.c:804811
int _E595_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_9, "InvDstAlpha");
  return atexit(_E596_4);
}

//----- (00711AC0) --------------------------------------------------------  // acclient.c:804818
int _E598_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_9, "DstColor");
  return atexit(_E599_4);
}

//----- (00711AE0) --------------------------------------------------------  // acclient.c:804825
int _E601_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_9, "InvDstColor");
  return atexit(_E602_4);
}

//----- (00711B00) --------------------------------------------------------  // acclient.c:804832
int _E604_4()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_9, "SrcAlphaSat");
  return atexit(_E605_4);
}

//----- (00711B20) --------------------------------------------------------  // acclient.c:804839
int _E607_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_9, "Less");
  return atexit(_E608_4);
}

//----- (00711B40) --------------------------------------------------------  // acclient.c:804846
int _E610_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_9, "Equal");
  return atexit(_E611_4);
}

//----- (00711B60) --------------------------------------------------------  // acclient.c:804853
int _E613_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_9, "LessEqual");
  return atexit(_E614_4);
}

//----- (00711B80) --------------------------------------------------------  // acclient.c:804860
int _E616_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_9, "Greater");
  return atexit(_E617_4);
}

//----- (00711BA0) --------------------------------------------------------  // acclient.c:804867
int _E619_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_9, "NotEqual");
  return atexit(_E620_4);
}

//----- (00711BC0) --------------------------------------------------------  // acclient.c:804874
int _E622_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_9, "GreaterEqual");
  return atexit(_E623_4);
}

//----- (00711BE0) --------------------------------------------------------  // acclient.c:804881
int _E625_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_9, "Always");
  return atexit(_E626_4);
}

//----- (00711C00) --------------------------------------------------------  // acclient.c:804888
int _E628_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_9, "On");
  return atexit(_E629_4);
}

//----- (00711C20) --------------------------------------------------------  // acclient.c:804895
int _E631_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_9, "Off");
  return atexit(_E632_4);
}

//----- (00711C40) --------------------------------------------------------  // acclient.c:804902
int _E634_4()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_9, "LayerDiffuse");
  return atexit(_E635_4);
}

//----- (00711C60) --------------------------------------------------------  // acclient.c:804909
int _E637_4()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_9, "LayerSpecular");
  return atexit(_E638_4);
}

//----- (00711C80) --------------------------------------------------------  // acclient.c:804916
int _E640_4()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_9, "VertexDiffuse");
  return atexit(_E641_4);
}

//----- (00711CA0) --------------------------------------------------------  // acclient.c:804923
int _E643_4()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_9, "VertexSpecular");
  return atexit(_E644_4);
}

//----- (00711CC0) --------------------------------------------------------  // acclient.c:804930
int _E646_4()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_9, "None");
  return atexit(_E647_4);
}

//----- (00711CE0) --------------------------------------------------------  // acclient.c:804937
int _E649_4()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_9, "CW");
  return atexit(_E650_4);
}

//----- (00711D00) --------------------------------------------------------  // acclient.c:804944
int _E652_4()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_9, "CCW");
  return atexit(_E653_4);
}

//----- (00711D20) --------------------------------------------------------  // acclient.c:804951
int _E655_4()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_9, "None");
  return atexit(_E656_4);
}

//----- (00711D40) --------------------------------------------------------  // acclient.c:804958
int _E658_4()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_9, "Simple");
  return atexit(_E659_4);
}

//----- (00711D60) --------------------------------------------------------  // acclient.c:804965
int _E661_4()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_9, "Diffuse");
  return atexit(_E662_4);
}

//----- (00711D80) --------------------------------------------------------  // acclient.c:804972
int _E664_4()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_9, "Specular");
  return atexit(_E665_4);
}

//----- (00711DA0) --------------------------------------------------------  // acclient.c:804979
int _E667_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_9, "Off");
  return atexit(_E668_4);
}

//----- (00711DC0) --------------------------------------------------------  // acclient.c:804986
int _E670_4()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_9, "On");
  return atexit(_E671_4);
}

//----- (00711DE0) --------------------------------------------------------  // acclient.c:804993
int _E673_4()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_9, "Off");
  return atexit(_E674_4);
}

//----- (00711E00) --------------------------------------------------------  // acclient.c:805000
int _E676_4()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_9, "On");
  return atexit(_E677_4);
}

//----- (00711E20) --------------------------------------------------------  // acclient.c:805007
int _E679_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_9, "Origin");
  return atexit(_E680_4);
}

//----- (00711E40) --------------------------------------------------------  // acclient.c:805014
int _E682_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_9, "Normal");
  return atexit(_E683_4);
}

//----- (00711E60) --------------------------------------------------------  // acclient.c:805021
int _E685_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_9, "PointSize");
  return atexit(_E686_4);
}

//----- (00711E80) --------------------------------------------------------  // acclient.c:805028
int _E688_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_9, "Diffuse");
  return atexit(_E689_4);
}

//----- (00711EA0) --------------------------------------------------------  // acclient.c:805035
int _E691_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_9, "Specular");
  return atexit(_E692_4);
}

//----- (00711EC0) --------------------------------------------------------  // acclient.c:805042
int _E694_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_9, "TCPairX1");
  return atexit(_E695_4);
}

//----- (00711EE0) --------------------------------------------------------  // acclient.c:805049
int _E697_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_9, "TCPairX2");
  return atexit(_E698_4);
}

//----- (00711F00) --------------------------------------------------------  // acclient.c:805056
int _E700_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_9, "TCPairX3");
  return atexit(_E701_4);
}

//----- (00711F20) --------------------------------------------------------  // acclient.c:805063
int _E703_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_9, "TCPairX4");
  return atexit(_E704_4);
}

//----- (00711F40) --------------------------------------------------------  // acclient.c:805070
int _E706_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_9, "TCPairX5");
  return atexit(_E707_4);
}

//----- (00711F60) --------------------------------------------------------  // acclient.c:805077
int _E709_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_9, "TCPairX6");
  return atexit(_E710_4);
}

//----- (00711F80) --------------------------------------------------------  // acclient.c:805084
int _E712_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_9, "TCPairX7");
  return atexit(_E713_4);
}

//----- (00711FA0) --------------------------------------------------------  // acclient.c:805091
int _E715_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_9, "TCPairX8");
  return atexit(_E716_4);
}

//----- (00711FC0) --------------------------------------------------------  // acclient.c:805098
int _E718_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_9, "VectorS");
  return atexit(_E719_4);
}

//----- (00711FE0) --------------------------------------------------------  // acclient.c:805105
int _E721_4()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_9, "VectorT");
  return atexit(_E722_4);
}

//----- (00712000) --------------------------------------------------------  // acclient.c:805112
int _E724_4()
{
  PStringBase<char>::PStringBase<char>(&stru_8F036C, "Stage");
  return atexit(_E725_4);
}

//----- (00712020) --------------------------------------------------------  // acclient.c:805119
int _E727_4()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_9, "Sampler");
  return atexit(_E728_4);
}

//----- (00712040) --------------------------------------------------------  // acclient.c:805126
int _E730_4()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_9, "SamplerName");
  return atexit(_E731_4);
}

//----- (00712060) --------------------------------------------------------  // acclient.c:805133
int _E733_4()
{
  PStringBase<char>::PStringBase<char>(&Texture_9, "Texture");
  return atexit(_E734_4);
}

//----- (00712080) --------------------------------------------------------  // acclient.c:805140
int _E736_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_9, "!FrameBuffer");
  return atexit(_E737_4);
}

//----- (007120A0) --------------------------------------------------------  // acclient.c:805147
int _E739_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_9, "!Distortion");
  return atexit(_E740_4);
}

//----- (007120C0) --------------------------------------------------------  // acclient.c:805154
int _E742_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_9, "!Reflection");
  return atexit(_E743_4);
}

//----- (007120E0) --------------------------------------------------------  // acclient.c:805161
int _E745_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_9, "!NormalizeCube");
  return atexit(_E746_4);
}

//----- (00712100) --------------------------------------------------------  // acclient.c:805168
int _E748_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_9, "!LightProjectorCube");
  return atexit(_E749_4);
}

//----- (00712120) --------------------------------------------------------  // acclient.c:805175
int _E751_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_9, "!EnvironmentCube");
  return atexit(_E752_4);
}

//----- (00712140) --------------------------------------------------------  // acclient.c:805182
int _E754_4()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_9, "!LandscapeShadows");
  return atexit(_E755_4);
}

//----- (00712160) --------------------------------------------------------  // acclient.c:805189
int _E757_4()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_9, "AddressMode");
  return atexit(_E758_4);
}

//----- (00712180) --------------------------------------------------------  // acclient.c:805196
int _E760_4()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_9, "FilterMode");
  return atexit(_E761_4);
}

//----- (007121A0) --------------------------------------------------------  // acclient.c:805203
int _E763_4()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_9, "FFColorOp");
  return atexit(_E764_4);
}

//----- (007121C0) --------------------------------------------------------  // acclient.c:805210
int _E766_4()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_9, "FFColorArg1");
  return atexit(_E767_4);
}

//----- (007121E0) --------------------------------------------------------  // acclient.c:805217
int _E769_4()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_9, "FFColorArg2");
  return atexit(_E770_4);
}

//----- (00712200) --------------------------------------------------------  // acclient.c:805224
int _E772_4()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_9, "FFAlphaOp");
  return atexit(_E773_4);
}

//----- (00712220) --------------------------------------------------------  // acclient.c:805231
int _E775_4()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_9, "FFAlphaArg1");
  return atexit(_E776_4);
}

//----- (00712240) --------------------------------------------------------  // acclient.c:805238
int _E778_4()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_9, "FFAlphaArg2");
  return atexit(_E779_4);
}

//----- (00712260) --------------------------------------------------------  // acclient.c:805245
int _E781_4()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_9, "FFTexCoordIndex");
  return atexit(_E782_4);
}

//----- (00712280) --------------------------------------------------------  // acclient.c:805252
int _E784_4()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_9, "FFUseProjection");
  return atexit(_E785_4);
}

//----- (007122A0) --------------------------------------------------------  // acclient.c:805259
int _E787_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_9, "SelectArg1");
  return atexit(_E788_4);
}

//----- (007122C0) --------------------------------------------------------  // acclient.c:805266
int _E790_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_9, "SelectArg2");
  return atexit(_E791_4);
}

//----- (007122E0) --------------------------------------------------------  // acclient.c:805273
int _E793_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_9, "Modulate");
  return atexit(_E794_4);
}

//----- (00712300) --------------------------------------------------------  // acclient.c:805280
int _E796_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_9, "Modulate2X");
  return atexit(_E797_4);
}

//----- (00712320) --------------------------------------------------------  // acclient.c:805287
int _E799_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_9, "Modulate4X");
  return atexit(_E800_4);
}

//----- (00712340) --------------------------------------------------------  // acclient.c:805294
int _E802_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_9, "Add");
  return atexit(_E803_4);
}

//----- (00712360) --------------------------------------------------------  // acclient.c:805301
int _E805_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_9, "AddSigned");
  return atexit(_E806_4);
}

//----- (00712380) --------------------------------------------------------  // acclient.c:805308
int _E808_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_9, "AddSigned2X");
  return atexit(_E809_4);
}

//----- (007123A0) --------------------------------------------------------  // acclient.c:805315
int _E811_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_9, "Subtract");
  return atexit(_E812_4);
}

//----- (007123C0) --------------------------------------------------------  // acclient.c:805322
int _E814_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_9, "AddSmooth");
  return atexit(_E815_4);
}

//----- (007123E0) --------------------------------------------------------  // acclient.c:805329
int _E817_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_9, "BlendDiffuseAlpha");
  return atexit(_E818_4);
}

//----- (00712400) --------------------------------------------------------  // acclient.c:805336
int _E820_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_9, "BlendTextureAlpha");
  return atexit(_E821_4);
}

//----- (00712420) --------------------------------------------------------  // acclient.c:805343
int _E823_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_9, "BlendFactorAlpha");
  return atexit(_E824_4);
}

//----- (00712440) --------------------------------------------------------  // acclient.c:805350
int _E826_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_9, "BlendTextureAlphaPM");
  return atexit(_E827_4);
}

//----- (00712460) --------------------------------------------------------  // acclient.c:805357
int _E829_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_9, "BlendCurrentAlpha");
  return atexit(_E830_4);
}

//----- (00712480) --------------------------------------------------------  // acclient.c:805364
int _E832_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_9, "Premodulate");
  return atexit(_E833_4);
}

//----- (007124A0) --------------------------------------------------------  // acclient.c:805371
int _E835_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_9, "ModulateAlphaAddColor");
  return atexit(_E836_4);
}

//----- (007124C0) --------------------------------------------------------  // acclient.c:805378
int _E838_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_9, "ModulateColorAddAlpha");
  return atexit(_E839_4);
}

//----- (007124E0) --------------------------------------------------------  // acclient.c:805385
int _E841_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_9, "ModulateInvAlphaAddColor");
  return atexit(_E842_4);
}

//----- (00712500) --------------------------------------------------------  // acclient.c:805392
int _E844_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_9, "ModulateInvColorAddAlpha");
  return atexit(_E845_4);
}

//----- (00712520) --------------------------------------------------------  // acclient.c:805399
int _E847_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_9, "BumpEnvMap");
  return atexit(_E848_4);
}

//----- (00712540) --------------------------------------------------------  // acclient.c:805406
int _E850_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_9, "BumpEnvMapLuminance");
  return atexit(_E851_4);
}

//----- (00712560) --------------------------------------------------------  // acclient.c:805413
int _E853_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_9, "DotProduct3");
  return atexit(_E854_4);
}

//----- (00712580) --------------------------------------------------------  // acclient.c:805420
int _E856_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_9, "MultiplyAdd");
  return atexit(_E857_4);
}

//----- (007125A0) --------------------------------------------------------  // acclient.c:805427
int _E859_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_9, "Lerp");
  return atexit(_E860_4);
}

//----- (007125C0) --------------------------------------------------------  // acclient.c:805434
int _E862_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_9, "Diffuse");
  return atexit(_E863_4);
}

//----- (007125E0) --------------------------------------------------------  // acclient.c:805441
int _E865_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_9, "Specular");
  return atexit(_E866_4);
}

//----- (00712600) --------------------------------------------------------  // acclient.c:805448
int _E868_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_9, "Current");
  return atexit(_E869_4);
}

//----- (00712620) --------------------------------------------------------  // acclient.c:805455
int _E871_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_9, "Texture");
  return atexit(_E872_4);
}

//----- (00712640) --------------------------------------------------------  // acclient.c:805462
int _E874_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_9, "TFactor");
  return atexit(_E875_4);
}

//----- (00712660) --------------------------------------------------------  // acclient.c:805469
int _E877_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_9, "Wrap");
  return atexit(_E878_4);
}

//----- (00712680) --------------------------------------------------------  // acclient.c:805476
int _E880_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_9, "Mirror");
  return atexit(_E881_4);
}

//----- (007126A0) --------------------------------------------------------  // acclient.c:805483
int _E883_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_9, "Clamp");
  return atexit(_E884_4);
}

//----- (007126C0) --------------------------------------------------------  // acclient.c:805490
int _E886_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_9, "Border");
  return atexit(_E887_4);
}

//----- (007126E0) --------------------------------------------------------  // acclient.c:805497
int _E889_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_9, "None");
  return atexit(_E890_4);
}

//----- (00712700) --------------------------------------------------------  // acclient.c:805504
int _E892_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_9, "Point");
  return atexit(_E893_4);
}

//----- (00712720) --------------------------------------------------------  // acclient.c:805511
int _E895_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_9, "Linear");
  return atexit(_E896_4);
}

//----- (00712740) --------------------------------------------------------  // acclient.c:805518
int _E898_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_9, "Anisotropic");
  return atexit(_E899_4);
}

//----- (00712760) --------------------------------------------------------  // acclient.c:805525
int _E901_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_9, "ReflectionVector");
  return atexit(_E902_4);
}

//----- (00712780) --------------------------------------------------------  // acclient.c:805532
int _E904_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_9, "ViewNormal");
  return atexit(_E905_4);
}

//----- (007127A0) --------------------------------------------------------  // acclient.c:805539
int _E907_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_9, "ViewOrigin");
  return atexit(_E908_4);
}

//----- (007127C0) --------------------------------------------------------  // acclient.c:805546
int _E910_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_9, "SphereMap");
  return atexit(_E911_4);
}

//----- (007127E0) --------------------------------------------------------  // acclient.c:805553
int _E913_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_9, "CubeMapReflection");
  return atexit(_E914_4);
}

//----- (00712800) --------------------------------------------------------  // acclient.c:805560
int _E916_4()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_9, "CubeMapFakeLight");
  return atexit(_E917_4);
}

//----- (00712820) --------------------------------------------------------  // acclient.c:805567
int _E919_4()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0470, "FFModifier");
  return atexit(_E920_4);
}

//----- (00712840) --------------------------------------------------------  // acclient.c:805574
int _E922_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_9, "Origin");
  return atexit(_E923_4);
}

//----- (00712860) --------------------------------------------------------  // acclient.c:805581
int _E925_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_9, "Normal");
  return atexit(_E926_4);
}

//----- (00712880) --------------------------------------------------------  // acclient.c:805588
int _E928_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_9, "Diffuse");
  return atexit(_E929_4);
}

//----- (007128A0) --------------------------------------------------------  // acclient.c:805595
int _E931_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_9, "UVTranslate");
  return atexit(_E932_4);
}

//----- (007128C0) --------------------------------------------------------  // acclient.c:805602
int _E934_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_9, "UVRotate");
  return atexit(_E935_4);
}

//----- (007128E0) --------------------------------------------------------  // acclient.c:805609
int _E937_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_9, "UVScale");
  return atexit(_E938_4);
}

//----- (00712900) --------------------------------------------------------  // acclient.c:805616
int _E940_4()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_9, "UVTransform");
  return atexit(_E941_4);
}

//----- (00712920) --------------------------------------------------------  // acclient.c:805623
int _E943_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_9, "TexCoordIndex");
  return atexit(_E944_4);
}

//----- (00712940) --------------------------------------------------------  // acclient.c:805630
int _E946_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_9, "Translate");
  return atexit(_E947_4);
}

//----- (00712960) --------------------------------------------------------  // acclient.c:805637
int _E949_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_9, "TexCoordIndex");
  return atexit(_E950_4);
}

//----- (00712980) --------------------------------------------------------  // acclient.c:805644
int _E952_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_9, "Rotate");
  return atexit(_E953_4);
}

//----- (007129A0) --------------------------------------------------------  // acclient.c:805651
int _E955_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_9, "TexCoordIndex");
  return atexit(_E956_4);
}

//----- (007129C0) --------------------------------------------------------  // acclient.c:805658
int _E958_4()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_9, "Scale");
  return atexit(_E959_4);
}

//----- (007129E0) --------------------------------------------------------  // acclient.c:805665
int _E961_4()
{
  PStringBase<char>::PStringBase<char>(&stru_8F04A8, "PSDesc");
  return atexit(_E962_4);
}

//----- (00712A00) --------------------------------------------------------  // acclient.c:805672
int _E964_4()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_9, "PhysicsTimeStep");
  return atexit(_E965_4);
}

//----- (00712A20) --------------------------------------------------------  // acclient.c:805679
int _E967_4()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_9, "FastForwardTime");
  return atexit(_E968_4);
}

//----- (00712A40) --------------------------------------------------------  // acclient.c:805686
int _E970_4()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_9, "StartFadeDistance");
  return atexit(_E971_4);
}

//----- (00712A60) --------------------------------------------------------  // acclient.c:805693
int _E973_4()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_9, "StopFadeDistance");
  return atexit(_E974_4);
}

//----- (00712A80) --------------------------------------------------------  // acclient.c:805700
int _E976_4()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_9, "PhysicsDuration");
  return atexit(_E977_4);
}

//----- (00712AA0) --------------------------------------------------------  // acclient.c:805707
int _E979_4()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_9, "ScaleType");
  return atexit(_E980_4);
}

//----- (00712AC0) --------------------------------------------------------  // acclient.c:805714
int _E982_4()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_9, "WorldSpace");
  return atexit(_E983_4);
}

//----- (00712AE0) --------------------------------------------------------  // acclient.c:805721
int _E985_4()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_9, "ForceDraw");
  return atexit(_E986_4);
}

//----- (00712B00) --------------------------------------------------------  // acclient.c:805728
int _E988_4()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_9, "NumEmitters");
  return atexit(_E989_4);
}

//----- (00712B20) --------------------------------------------------------  // acclient.c:805735
int _E991_4()
{
  PStringBase<char>::PStringBase<char>(&Material_45, "Material");
  return atexit(_E992_4);
}

//----- (00712B40) --------------------------------------------------------  // acclient.c:805742
int _E994_4()
{
  PStringBase<char>::PStringBase<char>(&Version_9, "Version");
  return atexit(_E995_4);
}

//----- (00712B60) --------------------------------------------------------  // acclient.c:805749
int _E997_4()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_9, "MaxParticles");
  return atexit(_E998_4);
}

//----- (00712B80) --------------------------------------------------------  // acclient.c:805756
int _E1000_4()
{
  PStringBase<char>::PStringBase<char>(&stru_8F04DC, "Emitter");
  return atexit(_E1001_4);
}

//----- (00712BA0) --------------------------------------------------------  // acclient.c:805763
int _E1003_4()
{
  PStringBase<char>::PStringBase<char>(&Origin_20, "Origin");
  return atexit(_E1004_4);
}

//----- (00712BC0) --------------------------------------------------------  // acclient.c:805770
int _E1006_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_9, "Shape");
  return atexit(_E1007_4);
}

//----- (00712BE0) --------------------------------------------------------  // acclient.c:805777
int _E1009_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_9, "Point");
  return atexit(_E1010_4);
}

//----- (00712C00) --------------------------------------------------------  // acclient.c:805784
int _E1012_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_9, "Line");
  return atexit(_E1013_4);
}

//----- (00712C20) --------------------------------------------------------  // acclient.c:805791
int _E1015_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_9, "Quad");
  return atexit(_E1016_4);
}

//----- (00712C40) --------------------------------------------------------  // acclient.c:805798
int _E1018_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_9, "Disc");
  return atexit(_E1019_4);
}

//----- (00712C60) --------------------------------------------------------  // acclient.c:805805
int _E1021_4()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_9, "Sphere");
  return atexit(_E1022_4);
}

//----- (00712C80) --------------------------------------------------------  // acclient.c:805812
int _E1024_4()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_9, "ParticleShape");
  return atexit(_E1025_4);
}

//----- (00712CA0) --------------------------------------------------------  // acclient.c:805819
int _E1027_4()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_9, "Triangle");
  return atexit(_E1028_4);
}

//----- (00712CC0) --------------------------------------------------------  // acclient.c:805826
int _E1030_4()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_9, "Quad");
  return atexit(_E1031_4);
}

//----- (00712CE0) --------------------------------------------------------  // acclient.c:805833
int _E1033_4()
{
  PStringBase<char>::PStringBase<char>(&Streak_9, "Streak");
  return atexit(_E1034_4);
}

//----- (00712D00) --------------------------------------------------------  // acclient.c:805840
int _E1036_4()
{
  PStringBase<char>::PStringBase<char>(&Rotation_20, "Rotation");
  return atexit(_E1037_4);
}

//----- (00712D20) --------------------------------------------------------  // acclient.c:805847
int _E1039_4()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_9, "WorldRotation");
  return atexit(_E1040_4);
}

//----- (00712D40) --------------------------------------------------------  // acclient.c:805854
int _E1042_4()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_9, "RotateVelocity");
  return atexit(_E1043_4);
}

//----- (00712D60) --------------------------------------------------------  // acclient.c:805861
int _E1045_4()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_9, "ParticleScale");
  return atexit(_E1046_4);
}

//----- (00712D80) --------------------------------------------------------  // acclient.c:805868
int _E1048_4()
{
  PStringBase<char>::PStringBase<char>(&Scale_30, "Scale");
  return atexit(_E1049_4);
}

//----- (00712DA0) --------------------------------------------------------  // acclient.c:805875
int _E1051_4()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_9, "ExplodingDir");
  return atexit(_E1052_4);
}

//----- (00712DC0) --------------------------------------------------------  // acclient.c:805882
int _E1054_4()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_9, "BirthRate");
  return atexit(_E1055_4);
}

//----- (00712DE0) --------------------------------------------------------  // acclient.c:805889
int _E1057_4()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_9, "Lifespan");
  return atexit(_E1058_4);
}

//----- (00712E00) --------------------------------------------------------  // acclient.c:805896
int _E1060_4()
{
  PStringBase<char>::PStringBase<char>(&Velocity_9, "Velocity");
  return atexit(_E1061_4);
}

//----- (00712E20) --------------------------------------------------------  // acclient.c:805903
int _E1063_4()
{
  PStringBase<char>::PStringBase<char>(&Direction_9, "Direction");
  return atexit(_E1064_4);
}

//----- (00712E40) --------------------------------------------------------  // acclient.c:805910
int _E1066_4()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_9, "MinSpread");
  return atexit(_E1067_4);
}

//----- (00712E60) --------------------------------------------------------  // acclient.c:805917
int _E1069_4()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_9, "MaxSpread");
  return atexit(_E1070_4);
}

//----- (00712E80) --------------------------------------------------------  // acclient.c:805924
int _E1072_4()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_9, "EmissionLimit");
  return atexit(_E1073_4);
}

//----- (00712EA0) --------------------------------------------------------  // acclient.c:805931
int _E1075_4()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_9, "BlastCount");
  return atexit(_E1076_4);
}

//----- (00712EC0) --------------------------------------------------------  // acclient.c:805938
int _E1078_4()
{
  PStringBase<char>::PStringBase<char>(&StartTime_9, "StartTime");
  return atexit(_E1079_4);
}

//----- (00712EE0) --------------------------------------------------------  // acclient.c:805945
int _E1081_4()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_9, "TimeLimit");
  return atexit(_E1082_4);
}

//----- (00712F00) --------------------------------------------------------  // acclient.c:805952
int _E1084_4()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_9, "EmissionDistance");
  return atexit(_E1085_4);
}

//----- (00712F20) --------------------------------------------------------  // acclient.c:805959
int _E1087_4()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_9, "ParticleSnap");
  return atexit(_E1088_4);
}

//----- (00712F40) --------------------------------------------------------  // acclient.c:805966
int _E1090_4()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_9, "InclusiveShape");
  return atexit(_E1091_4);
}

//----- (00712F60) --------------------------------------------------------  // acclient.c:805973
int _E1093_4()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_9, "NumKeyframes");
  return atexit(_E1094_4);
}

//----- (00712F80) --------------------------------------------------------  // acclient.c:805980
int _E1096_4()
{
  PStringBase<char>::PStringBase<char>(&IsActive_9, "IsActive");
  return atexit(_E1097_4);
}

//----- (00712FA0) --------------------------------------------------------  // acclient.c:805987
int _E1099_4()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_9, "FadeIn");
  return atexit(_E1100_4);
}

//----- (00712FC0) --------------------------------------------------------  // acclient.c:805994
int _E1102_4()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_9, "FadeOut");
  return atexit(_E1103_4);
}

//----- (00712FE0) --------------------------------------------------------  // acclient.c:806001
int _E1105_4()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_9, "ConstrainX");
  return atexit(_E1106_4);
}

//----- (00713000) --------------------------------------------------------  // acclient.c:806008
int _E1108_4()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_9, "ConstrainY");
  return atexit(_E1109_4);
}

//----- (00713020) --------------------------------------------------------  // acclient.c:806015
int _E1111_4()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_9, "ConstrainZ");
  return atexit(_E1112_4);
}

//----- (00713040) --------------------------------------------------------  // acclient.c:806022
int _E1114_4()
{
  PStringBase<char>::PStringBase<char>(&stru_8F0574, "Keyframe");
  return atexit(_E1115_4);
}

//----- (00713060) --------------------------------------------------------  // acclient.c:806029
int _E1117_4()
{
  PStringBase<char>::PStringBase<char>(&Time_9, "Time");
  return atexit(_E1118_4);
}

//----- (00713080) --------------------------------------------------------  // acclient.c:806036
int _E1120_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_9, "Flags");
  return atexit(_E1121_4);
}

//----- (007130A0) --------------------------------------------------------  // acclient.c:806043
int _E1123_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_9, "None");
  return atexit(_E1124_4);
}

//----- (007130C0) --------------------------------------------------------  // acclient.c:806050
int _E1126_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_9, "BlendScale");
  return atexit(_E1127_4);
}

//----- (007130E0) --------------------------------------------------------  // acclient.c:806057
int _E1129_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_9, "BlendColor");
  return atexit(_E1130_4);
}

//----- (00713100) --------------------------------------------------------  // acclient.c:806064
int _E1132_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_9, "BlendMass");
  return atexit(_E1133_4);
}

//----- (00713120) --------------------------------------------------------  // acclient.c:806071
int _E1135_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_9, "SetScale");
  return atexit(_E1136_4);
}

//----- (00713140) --------------------------------------------------------  // acclient.c:806078
int _E1138_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_9, "SetColor");
  return atexit(_E1139_4);
}

//----- (00713160) --------------------------------------------------------  // acclient.c:806085
int _E1141_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_9, "SetMass");
  return atexit(_E1142_4);
}

//----- (00713180) --------------------------------------------------------  // acclient.c:806092
int _E1144_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_9, "SetParticleFlags");
  return atexit(_E1145_4);
}

//----- (007131A0) --------------------------------------------------------  // acclient.c:806099
int _E1147_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_9, "SetControllerType");
  return atexit(_E1148_4);
}

//----- (007131C0) --------------------------------------------------------  // acclient.c:806106
int _E1150_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_9, "SetPhysicsFlags");
  return atexit(_E1151_4);
}

//----- (007131E0) --------------------------------------------------------  // acclient.c:806113
int _E1153_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_9, "SetParams");
  return atexit(_E1154_4);
}

//----- (00713200) --------------------------------------------------------  // acclient.c:806120
int _E1156_4()
{
  PStringBase<char>::PStringBase<char>(&Scale_31, "Scale");
  return atexit(_E1157_4);
}

//----- (00713220) --------------------------------------------------------  // acclient.c:806127
int _E1159_4()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_9, "ScaleX");
  return atexit(_E1160_4);
}

//----- (00713240) --------------------------------------------------------  // acclient.c:806134
int _E1162_4()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_9, "ScaleY");
  return atexit(_E1163_4);
}

//----- (00713260) --------------------------------------------------------  // acclient.c:806141
int _E1165_4()
{
  PStringBase<char>::PStringBase<char>(&Color_9, "Color");
  return atexit(_E1166_4);
}

//----- (00713280) --------------------------------------------------------  // acclient.c:806148
int _E1168_4()
{
  PStringBase<char>::PStringBase<char>(&Mass_9, "Mass");
  return atexit(_E1169_4);
}

//----- (007132A0) --------------------------------------------------------  // acclient.c:806155
int _E1171_4()
{
  PStringBase<char>::PStringBase<char>(&PFlags_9, "ParticleFlags");
  return atexit(_E1172_4);
}

//----- (007132C0) --------------------------------------------------------  // acclient.c:806162
int _E1174_4()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_9, "None");
  return atexit(_E1175_4);
}

//----- (007132E0) --------------------------------------------------------  // acclient.c:806169
int _E1177_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_9, "ControllerType");
  return atexit(_E1178_4);
}

//----- (00713300) --------------------------------------------------------  // acclient.c:806176
int _E1180_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_9, "None");
  return atexit(_E1181_4);
}

//----- (00713320) --------------------------------------------------------  // acclient.c:806183
int _E1183_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_9, "Physics");
  return atexit(_E1184_4);
}

//----- (00713340) --------------------------------------------------------  // acclient.c:806190
int _E1186_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_9, "Parametric");
  return atexit(_E1187_4);
}

//----- (00713360) --------------------------------------------------------  // acclient.c:806197
int _E1189_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_9, "AttractRepulse");
  return atexit(_E1190_4);
}

//----- (00713380) --------------------------------------------------------  // acclient.c:806204
int _E1192_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_9, "PointFile");
  return atexit(_E1193_4);
}

//----- (007133A0) --------------------------------------------------------  // acclient.c:806211
int _E1195_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_9, "PointFileLerp");
  return atexit(_E1196_4);
}

//----- (007133C0) --------------------------------------------------------  // acclient.c:806218
int _E1198_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_9, "PhysicsFlags");
  return atexit(_E1199_4);
}

//----- (007133E0) --------------------------------------------------------  // acclient.c:806225
int _E1201_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_9, "None");
  return atexit(_E1202_4);
}

//----- (00713400) --------------------------------------------------------  // acclient.c:806232
int _E1204_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_9, "Gravity");
  return atexit(_E1205_4);
}

//----- (00713420) --------------------------------------------------------  // acclient.c:806239
int _E1207_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_9, "Wind");
  return atexit(_E1208_4);
}

//----- (00713440) --------------------------------------------------------  // acclient.c:806246
int _E1210_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_9, "Momentum");
  return atexit(_E1211_4);
}

//----- (00713460) --------------------------------------------------------  // acclient.c:806253
int _E1213_4()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_9, "RandomPoint");
  return atexit(_E1214_4);
}

//----- (00713480) --------------------------------------------------------  // acclient.c:806260
int _E1216_4()
{
  PStringBase<char>::PStringBase<char>(&Position_10, "Position");
  return atexit(_E1217_4);
}

//----- (007134A0) --------------------------------------------------------  // acclient.c:806267
int _E1219_4()
{
  PStringBase<char>::PStringBase<char>(&PointList_9, "PointList");
  return atexit(_E1220_4);
}

//----- (007134C0) --------------------------------------------------------  // acclient.c:806274
int _E1222_4()
{
  PStringBase<char>::PStringBase<char>(&Point_20, "pt");
  return atexit(_E1223_4);
}

//----- (007134E0) --------------------------------------------------------  // acclient.c:806281
int _E1225_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_9, "DetailLevels");
  return atexit(_E1226_4);
}

//----- (00713500) --------------------------------------------------------  // acclient.c:806288
int _E1228_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_9, "Low");
  return atexit(_E1229_4);
}

//----- (00713520) --------------------------------------------------------  // acclient.c:806295
int _E1231_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_9, "Medium");
  return atexit(_E1232_4);
}

//----- (00713540) --------------------------------------------------------  // acclient.c:806302
int _E1234_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_9, "High");
  return atexit(_E1235_4);
}

//----- (00713560) --------------------------------------------------------  // acclient.c:806309
int _E1237_4()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_9, "FadeSpeed");
  return atexit(_E1238_4);
}

//----- (00713580) --------------------------------------------------------  // acclient.c:806316
int _E1240_4()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_9, "MaxOpacity");
  return atexit(_E1241_4);
}

//----- (007135A0) --------------------------------------------------------  // acclient.c:806323
int _E1243_4()
{
  PStringBase<char>::PStringBase<char>(&Point_21, "Point");
  return atexit(_E1244_4);
}

//----- (007135C0) --------------------------------------------------------  // acclient.c:806330
int _E1246_4()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_9, "AxisPos");
  return atexit(_E1247_4);
}

//----- (007135E0) --------------------------------------------------------  // acclient.c:806337
int _E1249_4()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_9, "Texture");
  return atexit(_E1250_4);
}

//----- (00713600) --------------------------------------------------------  // acclient.c:806344
int _E1252_4()
{
  PStringBase<char>::PStringBase<char>(&PointSize_9, "Size");
  return atexit(_E1253_4);
}

//----- (00713620) --------------------------------------------------------  // acclient.c:806351
int _E1255_4()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_9, "UseOcclusion");
  return atexit(_E1256_4);
}

//----- (00713640) --------------------------------------------------------  // acclient.c:806358
void _E1258_4()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F0634, PFID_A8R8G8B8);
}

//----- (00713650) --------------------------------------------------------  // acclient.c:806364
void _E1276_4()
{
  LODWORD(dword_8F066C) = 1053364187;
}

//----- (00713660) --------------------------------------------------------  // acclient.c:806370
void _E1278_4()
{
  flt_8F0670 = 1000.0 + 1.0;
}

//----- (00713680) --------------------------------------------------------  // acclient.c:806376
void _E1280()
{
  flt_8F0674 = 24.0 * 8.0;
}

//----- (007136A0) --------------------------------------------------------  // acclient.c:806382
void _E1282_4()
{
  flt_8F0678 = 24.0 * 0.5;
}

//----- (007136C0) --------------------------------------------------------  // acclient.c:806388
int _E1284_4()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_42, "Render.TextureFiltering");
  return atexit(_E1285_9);
}

//----- (007136E0) --------------------------------------------------------  // acclient.c:806395
int _E1287_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_42, "Render.LandscapeDetailTextures");
  return atexit(_E1288_9);
}

//----- (00713700) --------------------------------------------------------  // acclient.c:806402
int _E1290_5()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_42, "Render.BuildingDetailTextures");
  return atexit(_E1291_8);
}

//----- (00713720) --------------------------------------------------------  // acclient.c:806409
int _E1293_4()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_42, "Render.FieldOfView");
  return atexit(_E1294_9);
}

//----- (00713740) --------------------------------------------------------  // acclient.c:806416
int _E1296_5()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_42, "Render.LandscapeTextureDetail");
  return atexit(_E1297_9);
}

//----- (00713760) --------------------------------------------------------  // acclient.c:806423
int _E1299_5()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_42, "Render.EnvironmentTextureDetail");
  return atexit(_E1300_9);
}

//----- (00713780) --------------------------------------------------------  // acclient.c:806430
int _E1302_5()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_42, "Render.SceneryDrawDistance");
  return atexit(_E1303_8);
}

//----- (007137A0) --------------------------------------------------------  // acclient.c:806437
int _E1305_5()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_42, "Render.LandscapeDrawDistance");
  return atexit(_E1306_7);
}

//----- (007137C0) --------------------------------------------------------  // acclient.c:806444
int _E1308_5()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_42, "Render.ScreenBrightness");
  return atexit(_E1309_7);
}

//----- (007137E0) --------------------------------------------------------  // acclient.c:806451
int _E1311_5()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_42, "Render.AspectRatio");
  return atexit(_E1312_7);
}

//----- (00713800) --------------------------------------------------------  // acclient.c:806458
int _E1314_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_42, "Render.DisplayAdapter");
  return atexit(_E1315_5);
}

//----- (00713820) --------------------------------------------------------  // acclient.c:806465
int _E1317_5()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_42, "Render.MaxHardwareClass");
  return atexit(_E1318_5);
}

//----- (00713840) --------------------------------------------------------  // acclient.c:806472
int _E1320_5()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_42, "Render.AutomaticDegrades");
  return atexit(_E1321_5);
}

//----- (00713860) --------------------------------------------------------  // acclient.c:806479
int _E1323_5()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_42, "Render.GraphicsPerformance");
  return atexit(_E1324_5);
}

//----- (00713880) --------------------------------------------------------  // acclient.c:806486
int _E1326_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_42, "Render.DegradeDistance");
  return atexit(_E1327_5);
}

//----- (007138A0) --------------------------------------------------------  // acclient.c:806493
int _E1329_5()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_42, "Render.MultiPassAlpha");
  return atexit(_E1330_5);
}

//----- (007138C0) --------------------------------------------------------  // acclient.c:806500
int _E1332_5()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_42, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F06C4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F06C8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F06CC, "Anisotropic");
  return atexit(_E1333_5);
}

//----- (00713910) --------------------------------------------------------  // acclient.c:806510
int _E1335_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_42, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F06D4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F06D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F06DC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F06E0, "VeryHigh");
  return atexit(_E1336_5);
}

//----- (00713970) --------------------------------------------------------  // acclient.c:806521
int _E1338_5()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_42, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F06E8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F06EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F06F0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F06F4, "VeryHigh");
  return atexit(_E1339_5);
}

//----- (007139D0) --------------------------------------------------------  // acclient.c:806532
int _E1341_5()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_42, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F06FC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F0700, "High");
  return atexit(_E1342_5);
}

//----- (00713A10) --------------------------------------------------------  // acclient.c:806541
int _E1344_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_42, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F0708, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F070C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F0710, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F0714, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F0718, "Extreme");
  return atexit(_E1345_5);
}

//----- (00713A80) --------------------------------------------------------  // acclient.c:806553
int _E1347_5()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_42, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F0720, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F0724, "Wide");
  return atexit(_E1348_5);
}

//----- (00713AC0) --------------------------------------------------------  // acclient.c:806562
int _E1350_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_70, "None");
  return atexit(_E1351_5);
}

//----- (00713AE0) --------------------------------------------------------  // acclient.c:806569
int _E1353_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_70, "Speed");
  return atexit(_E1354_5);
}

//----- (00713B00) --------------------------------------------------------  // acclient.c:806576
int _E1356_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_70, "Noise");
  return atexit(_E1357_5);
}

//----- (00713B20) --------------------------------------------------------  // acclient.c:806583
int _E1359_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_70, "Sine");
  return atexit(_E1360_5);
}

//----- (00713B40) --------------------------------------------------------  // acclient.c:806590
int _E1362_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_70, "Square");
  return atexit(_E1363_5);
}

//----- (00713B60) --------------------------------------------------------  // acclient.c:806597
int _E1365_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_70, "Bounce");
  return atexit(_E1366_5);
}

//----- (00713B80) --------------------------------------------------------  // acclient.c:806604
int _E1368_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_70, "Perlin");
  return atexit(_E1369_5);
}

//----- (00713BA0) --------------------------------------------------------  // acclient.c:806611
int _E1371_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_70, "Fractal");
  return atexit(_E1372_5);
}

//----- (00713BC0) --------------------------------------------------------  // acclient.c:806618
int _E1374_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_70, "FrameLoop");
  return atexit(_E1375_5);
}

//----- (00713BE0) --------------------------------------------------------  // acclient.c:806625
int sub_713BE0()
{
  return atexit(nullsub_1850);
}

//----- (00778EF0) --------------------------------------------------------  // acclient.c:911489
void __cdecl _E1285_9()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00778F20) --------------------------------------------------------  // acclient.c:911502
void __cdecl _E1288_9()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00778F50) --------------------------------------------------------  // acclient.c:911515
void __cdecl _E1291_8()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00778F80) --------------------------------------------------------  // acclient.c:911528
void __cdecl _E1294_9()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00778FB0) --------------------------------------------------------  // acclient.c:911541
void __cdecl _E1297_9()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00778FE0) --------------------------------------------------------  // acclient.c:911554
void __cdecl _E1300_9()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779010) --------------------------------------------------------  // acclient.c:911567
void __cdecl _E1303_8()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779040) --------------------------------------------------------  // acclient.c:911580
void __cdecl _E1306_7()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779070) --------------------------------------------------------  // acclient.c:911593
void __cdecl _E1309_7()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007790A0) --------------------------------------------------------  // acclient.c:911606
void __cdecl _E1312_7()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007790D0) --------------------------------------------------------  // acclient.c:911619
void __cdecl _E1315_5()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779100) --------------------------------------------------------  // acclient.c:911632
void __cdecl _E1318_5()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779130) --------------------------------------------------------  // acclient.c:911645
void __cdecl _E1321_5()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779160) --------------------------------------------------------  // acclient.c:911658
void __cdecl _E1324_5()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779190) --------------------------------------------------------  // acclient.c:911671
void __cdecl _E1327_5()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007791C0) --------------------------------------------------------  // acclient.c:911684
void __cdecl _E1330_5()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007791F0) --------------------------------------------------------  // acclient.c:911697
void __cdecl _E1333_5()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_42;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00779230) --------------------------------------------------------  // acclient.c:911722
void __cdecl _E1336_5()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_42;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00779270) --------------------------------------------------------  // acclient.c:911747
void __cdecl _E1339_5()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_42;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007792B0) --------------------------------------------------------  // acclient.c:911772
void __cdecl _E1342_5()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_42;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007792F0) --------------------------------------------------------  // acclient.c:911797
void __cdecl _E1345_5()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_42;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00779330) --------------------------------------------------------  // acclient.c:911822
void __cdecl _E1348_5()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_70;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00779370) --------------------------------------------------------  // acclient.c:911847
void __cdecl _E1351_5()
{
  char *v0; // esi@1

  v0 = &waveform_None_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007793A0) --------------------------------------------------------  // acclient.c:911860
void __cdecl _E1354_5()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007793D0) --------------------------------------------------------  // acclient.c:911873
void __cdecl _E1357_5()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779400) --------------------------------------------------------  // acclient.c:911886
void __cdecl _E1360_5()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779430) --------------------------------------------------------  // acclient.c:911899
void __cdecl _E1363_5()
{
  char *v0; // esi@1

  v0 = &waveform_Square_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779460) --------------------------------------------------------  // acclient.c:911912
void __cdecl _E1366_5()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779490) --------------------------------------------------------  // acclient.c:911925
void __cdecl _E1369_5()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007794C0) --------------------------------------------------------  // acclient.c:911938
void __cdecl _E1372_5()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007794F0) --------------------------------------------------------  // acclient.c:911951
void __cdecl _E1375_5()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779520) --------------------------------------------------------  // acclient.c:911964
void __cdecl _E74_95()
{
  char *v0; // esi@1

  v0 = &PHeader_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779550) --------------------------------------------------------  // acclient.c:911977
void __cdecl sub_779550()
{
  char *v0; // esi@1

  v0 = &VertexArray_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779580) --------------------------------------------------------  // acclient.c:911990
void __cdecl _E80_71()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007795B0) --------------------------------------------------------  // acclient.c:912003
void __cdecl _E83_47()
{
  char *v0; // esi@1

  v0 = &VertexType_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007795E0) --------------------------------------------------------  // acclient.c:912016
void __cdecl _E86_28()
{
  char *v0; // esi@1

  v0 = &VertexData_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779610) --------------------------------------------------------  // acclient.c:912029
void __cdecl _E89_38()
{
  char *v0; // esi@1

  v0 = &Vertex_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779640) --------------------------------------------------------  // acclient.c:912042
void __cdecl _E92_43()
{
  char *v0; // esi@1

  v0 = &Index_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779670) --------------------------------------------------------  // acclient.c:912055
void __cdecl sub_779670()
{
  char *v0; // esi@1

  v0 = &Origin_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007796A0) --------------------------------------------------------  // acclient.c:912068
void __cdecl sub_7796A0()
{
  char *v0; // esi@1

  v0 = &Normal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007796D0) --------------------------------------------------------  // acclient.c:912081
void __cdecl sub_7796D0()
{
  char *v0; // esi@1

  v0 = &Diffuse_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779700) --------------------------------------------------------  // acclient.c:912094
void __cdecl sub_779700()
{
  char *v0; // esi@1

  v0 = &Specular_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779730) --------------------------------------------------------  // acclient.c:912107
void __cdecl sub_779730()
{
  char *v0; // esi@1

  v0 = &UVS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779760) --------------------------------------------------------  // acclient.c:912120
void __cdecl sub_779760()
{
  char *v0; // esi@1

  v0 = &VectorS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779790) --------------------------------------------------------  // acclient.c:912133
void __cdecl _E113_73()
{
  char *v0; // esi@1

  v0 = &VectorT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007797C0) --------------------------------------------------------  // acclient.c:912146
void __cdecl _E116_65()
{
  char *v0; // esi@1

  v0 = &VectorSxT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007797F0) --------------------------------------------------------  // acclient.c:912159
void __cdecl _E119_91()
{
  char *v0; // esi@1

  v0 = &Weights_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779820) --------------------------------------------------------  // acclient.c:912172
void __cdecl sub_779820()
{
  char *v0; // esi@1

  v0 = &Importance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779850) --------------------------------------------------------  // acclient.c:912185
void __cdecl _E125_71()
{
  char *v0; // esi@1

  v0 = &PhysMtl_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779880) --------------------------------------------------------  // acclient.c:912198
void __cdecl _E128_69()
{
  char *v0; // esi@1

  v0 = &Material_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007798B0) --------------------------------------------------------  // acclient.c:912211
void __cdecl _E131_58()
{
  char *v0; // esi@1

  v0 = &ID_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007798E0) --------------------------------------------------------  // acclient.c:912224
void __cdecl _E134_42()
{
  char *v0; // esi@1

  v0 = &FileName_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779910) --------------------------------------------------------  // acclient.c:912237
void __cdecl _E137_41()
{
  char *v0; // esi@1

  v0 = &Polygon_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779940) --------------------------------------------------------  // acclient.c:912250
void __cdecl _E140_35()
{
  char *v0; // esi@1

  v0 = &ID_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779970) --------------------------------------------------------  // acclient.c:912263
void __cdecl _E143_35()
{
  char *v0; // esi@1

  v0 = &Indices_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007799A0) --------------------------------------------------------  // acclient.c:912276
void __cdecl _E146_35()
{
  char *v0; // esi@1

  v0 = &MaterialID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007799D0) --------------------------------------------------------  // acclient.c:912289
void __cdecl _E149_34()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779A00) --------------------------------------------------------  // acclient.c:912302
void __cdecl _E152_35()
{
  char *v0; // esi@1

  v0 = &Markings_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779A30) --------------------------------------------------------  // acclient.c:912315
void __cdecl _E155_31()
{
  char *v0; // esi@1

  v0 = &Material_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779A60) --------------------------------------------------------  // acclient.c:912328
void __cdecl _E158_32()
{
  char *v0; // esi@1

  v0 = &Index_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779A90) --------------------------------------------------------  // acclient.c:912341
void __cdecl _E161_29()
{
  char *v0; // esi@1

  v0 = &Filename_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779AC0) --------------------------------------------------------  // acclient.c:912354
void __cdecl _E164_31()
{
  char *v0; // esi@1

  v0 = &Surface_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779AF0) --------------------------------------------------------  // acclient.c:912367
void __cdecl _E167_27()
{
  char *v0; // esi@1

  v0 = &CellPoly_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779B20) --------------------------------------------------------  // acclient.c:912380
void __cdecl _E170_27()
{
  char *v0; // esi@1

  v0 = &Sphere_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779B50) --------------------------------------------------------  // acclient.c:912393
void __cdecl _E173_22()
{
  char *v0; // esi@1

  v0 = &Side_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779B80) --------------------------------------------------------  // acclient.c:912406
void __cdecl _E176_24()
{
  char *v0; // esi@1

  v0 = &Positive_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779BB0) --------------------------------------------------------  // acclient.c:912419
void __cdecl _E179_23()
{
  char *v0; // esi@1

  v0 = &Negative_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779BE0) --------------------------------------------------------  // acclient.c:912432
void __cdecl _E182_23()
{
  char *v0; // esi@1

  v0 = &Polygon_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779C10) --------------------------------------------------------  // acclient.c:912445
void __cdecl _E185_20()
{
  char *v0; // esi@1

  v0 = &OtherCell_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779C40) --------------------------------------------------------  // acclient.c:912458
void __cdecl _E188_21()
{
  char *v0; // esi@1

  v0 = &CellPortal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779C70) --------------------------------------------------------  // acclient.c:912471
void __cdecl _E191_20()
{
  char *v0; // esi@1

  v0 = &Portal_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779CA0) --------------------------------------------------------  // acclient.c:912484
void __cdecl _E194_27()
{
  char *v0; // esi@1

  v0 = &OtherCell_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779CD0) --------------------------------------------------------  // acclient.c:912497
void __cdecl _E197_17()
{
  char *v0; // esi@1

  v0 = &OtherPortal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779D00) --------------------------------------------------------  // acclient.c:912510
void __cdecl _E200_21()
{
  char *v0; // esi@1

  v0 = &ExactMatch_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779D30) --------------------------------------------------------  // acclient.c:912523
void __cdecl _E203_20()
{
  char *v0; // esi@1

  v0 = &StabList_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779D60) --------------------------------------------------------  // acclient.c:912536
void __cdecl _E206_23()
{
  char *v0; // esi@1

  v0 = &Period_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779D90) --------------------------------------------------------  // acclient.c:912549
void __cdecl _E209_18()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779DC0) --------------------------------------------------------  // acclient.c:912562
void __cdecl _E212_21()
{
  char *v0; // esi@1

  v0 = &Transform_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779DF0) --------------------------------------------------------  // acclient.c:912575
void __cdecl _E215_18()
{
  char *v0; // esi@1

  v0 = &Scale_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779E20) --------------------------------------------------------  // acclient.c:912588
void __cdecl _E218_18()
{
  char *v0; // esi@1

  v0 = &Weight_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779E50) --------------------------------------------------------  // acclient.c:912601
void __cdecl _E221_18()
{
  char *v0; // esi@1

  v0 = &Offset_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779E80) --------------------------------------------------------  // acclient.c:912614
void __cdecl _E224_18()
{
  char *v0; // esi@1

  v0 = &Quaternion_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779EB0) --------------------------------------------------------  // acclient.c:912627
void __cdecl _E227_18()
{
  char *v0; // esi@1

  v0 = &Rotation_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779EE0) --------------------------------------------------------  // acclient.c:912640
void __cdecl _E230_19()
{
  char *v0; // esi@1

  v0 = &STime_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779F10) --------------------------------------------------------  // acclient.c:912653
void __cdecl _E233_18()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779F40) --------------------------------------------------------  // acclient.c:912666
void __cdecl _E236_17()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779F70) --------------------------------------------------------  // acclient.c:912679
void __cdecl _E239_17()
{
  char *v0; // esi@1

  v0 = &LowPt_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779FA0) --------------------------------------------------------  // acclient.c:912692
void __cdecl _E242_17()
{
  char *v0; // esi@1

  v0 = &Radius_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00779FD0) --------------------------------------------------------  // acclient.c:912705
void __cdecl _E245_16()
{
  char *v0; // esi@1

  v0 = &Height_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A000) --------------------------------------------------------  // acclient.c:912718
void __cdecl _E248_16()
{
  char *v0; // esi@1

  v0 = &Texture2D_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A030) --------------------------------------------------------  // acclient.c:912731
void __cdecl _E251_15()
{
  char *v0; // esi@1

  v0 = &Texture3D_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A060) --------------------------------------------------------  // acclient.c:912744
void __cdecl _E254_16()
{
  char *v0; // esi@1

  v0 = &TextureCube_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A090) --------------------------------------------------------  // acclient.c:912757
void __cdecl _E257_14()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A0C0) --------------------------------------------------------  // acclient.c:912770
void __cdecl _E260_15()
{
  char *v0; // esi@1

  v0 = &MovieFileName_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A0F0) --------------------------------------------------------  // acclient.c:912783
void __cdecl _E263_14()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A120) --------------------------------------------------------  // acclient.c:912796
void __cdecl _E266_14()
{
  char *v0; // esi@1

  v0 = &Levels_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A150) --------------------------------------------------------  // acclient.c:912809
void __cdecl _E269_13()
{
  char *v0; // esi@1

  v0 = &stru_8F010C.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F010C.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A180) --------------------------------------------------------  // acclient.c:912822
void __cdecl _E272_12()
{
  char *v0; // esi@1

  v0 = &Material_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A1B0) --------------------------------------------------------  // acclient.c:912835
void __cdecl _E275_12()
{
  char *v0; // esi@1

  v0 = &MaterialType_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A1E0) --------------------------------------------------------  // acclient.c:912848
void __cdecl _E278_12()
{
  char *v0; // esi@1

  v0 = &Modifier_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A210) --------------------------------------------------------  // acclient.c:912861
void __cdecl _E281_12()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A240) --------------------------------------------------------  // acclient.c:912874
void __cdecl _E284_10()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A270) --------------------------------------------------------  // acclient.c:912887
void __cdecl _E287_11()
{
  char *v0; // esi@1

  v0 = &stru_8F0124.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0124.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A2A0) --------------------------------------------------------  // acclient.c:912900
void __cdecl _E290_10()
{
  char *v0; // esi@1

  v0 = &SortMode_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A2D0) --------------------------------------------------------  // acclient.c:912913
void __cdecl _E293_9()
{
  char *v0; // esi@1

  v0 = &SortMode_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A300) --------------------------------------------------------  // acclient.c:912926
void __cdecl _E296_10()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A330) --------------------------------------------------------  // acclient.c:912939
void __cdecl _E299_8()
{
  char *v0; // esi@1

  v0 = &stru_8F0134.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0134.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A360) --------------------------------------------------------  // acclient.c:912952
void __cdecl _E302_9()
{
  char *v0; // esi@1

  v0 = &stru_8F0138.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0138.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A390) --------------------------------------------------------  // acclient.c:912965
void __cdecl _E305_8()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A3C0) --------------------------------------------------------  // acclient.c:912978
void __cdecl _E308_9()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A3F0) --------------------------------------------------------  // acclient.c:912991
void __cdecl _E311_8()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A420) --------------------------------------------------------  // acclient.c:913004
void __cdecl _E314_9()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A450) --------------------------------------------------------  // acclient.c:913017
void __cdecl _E317_8()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A480) --------------------------------------------------------  // acclient.c:913030
void __cdecl _E320_9()
{
  char *v0; // esi@1

  v0 = &stru_8F0150.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0150.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A4B0) --------------------------------------------------------  // acclient.c:913043
void __cdecl _E323_7()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A4E0) --------------------------------------------------------  // acclient.c:913056
void __cdecl _E326_8()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A510) --------------------------------------------------------  // acclient.c:913069
void __cdecl _E329_7()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A540) --------------------------------------------------------  // acclient.c:913082
void __cdecl _E332_8()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A570) --------------------------------------------------------  // acclient.c:913095
void __cdecl _E335_7()
{
  char *v0; // esi@1

  v0 = &TrueFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A5A0) --------------------------------------------------------  // acclient.c:913108
void __cdecl _E338_7()
{
  char *v0; // esi@1

  v0 = &FalseFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A5D0) --------------------------------------------------------  // acclient.c:913121
void __cdecl _E341_7()
{
  char *v0; // esi@1

  v0 = &RenderPass_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A600) --------------------------------------------------------  // acclient.c:913134
void __cdecl _E344_4()
{
  char *v0; // esi@1

  v0 = &Blend_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A630) --------------------------------------------------------  // acclient.c:913147
void __cdecl _E347_4()
{
  char *v0; // esi@1

  v0 = &DepthTest_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A660) --------------------------------------------------------  // acclient.c:913160
void __cdecl _E350_4()
{
  char *v0; // esi@1

  v0 = &DepthWrite_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A690) --------------------------------------------------------  // acclient.c:913173
void __cdecl _E353_4()
{
  char *v0; // esi@1

  v0 = &CullMode_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A6C0) --------------------------------------------------------  // acclient.c:913186
void __cdecl _E356_4()
{
  char *v0; // esi@1

  v0 = &DepthFog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A6F0) --------------------------------------------------------  // acclient.c:913199
void __cdecl _E359_4()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A720) --------------------------------------------------------  // acclient.c:913212
void __cdecl _E362_4()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A750) --------------------------------------------------------  // acclient.c:913225
void __cdecl _E365_4()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A780) --------------------------------------------------------  // acclient.c:913238
void __cdecl _E368_4()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A7B0) --------------------------------------------------------  // acclient.c:913251
void __cdecl _E371_4()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A7E0) --------------------------------------------------------  // acclient.c:913264
void __cdecl _E374_4()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A810) --------------------------------------------------------  // acclient.c:913277
void __cdecl _E377_4()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A840) --------------------------------------------------------  // acclient.c:913290
void __cdecl _E380_4()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A870) --------------------------------------------------------  // acclient.c:913303
void __cdecl _E383_4()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A8A0) --------------------------------------------------------  // acclient.c:913316
void __cdecl _E386_4()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A8D0) --------------------------------------------------------  // acclient.c:913329
void __cdecl _E389_4()
{
  char *v0; // esi@1

  v0 = &Ambient_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A900) --------------------------------------------------------  // acclient.c:913342
void __cdecl _E392_4()
{
  char *v0; // esi@1

  v0 = &Diffuse_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A930) --------------------------------------------------------  // acclient.c:913355
void __cdecl _E395_4()
{
  char *v0; // esi@1

  v0 = &Specular_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A960) --------------------------------------------------------  // acclient.c:913368
void __cdecl _E398_4()
{
  char *v0; // esi@1

  v0 = &SpecularPower_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A990) --------------------------------------------------------  // acclient.c:913381
void __cdecl _E401_4()
{
  char *v0; // esi@1

  v0 = &Dye_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A9C0) --------------------------------------------------------  // acclient.c:913394
void __cdecl _E404_4()
{
  char *v0; // esi@1

  v0 = &Emissive_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077A9F0) --------------------------------------------------------  // acclient.c:913407
void __cdecl _E407_4()
{
  char *v0; // esi@1

  v0 = &VertexFormat_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AA20) --------------------------------------------------------  // acclient.c:913420
void __cdecl _E410_4()
{
  char *v0; // esi@1

  v0 = &VertexShader_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AA50) --------------------------------------------------------  // acclient.c:913433
void __cdecl _E413_4()
{
  char *v0; // esi@1

  v0 = &PixelShader_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AA80) --------------------------------------------------------  // acclient.c:913446
void __cdecl _E416_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AAB0) --------------------------------------------------------  // acclient.c:913459
void __cdecl _E419_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AAE0) --------------------------------------------------------  // acclient.c:913472
void __cdecl _E422_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AB10) --------------------------------------------------------  // acclient.c:913485
void __cdecl _E425_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AB40) --------------------------------------------------------  // acclient.c:913498
void __cdecl _E428_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AB70) --------------------------------------------------------  // acclient.c:913511
void __cdecl _E431_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ABA0) --------------------------------------------------------  // acclient.c:913524
void __cdecl _E434_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ABD0) --------------------------------------------------------  // acclient.c:913537
void __cdecl _E437_4()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AC00) --------------------------------------------------------  // acclient.c:913550
void __cdecl _E440_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AC30) --------------------------------------------------------  // acclient.c:913563
void __cdecl _E443_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AC60) --------------------------------------------------------  // acclient.c:913576
void __cdecl _E446_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AC90) --------------------------------------------------------  // acclient.c:913589
void __cdecl _E449_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ACC0) --------------------------------------------------------  // acclient.c:913602
void __cdecl _E452_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ACF0) --------------------------------------------------------  // acclient.c:913615
void __cdecl _E455_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AD20) --------------------------------------------------------  // acclient.c:913628
void __cdecl _E458_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AD50) --------------------------------------------------------  // acclient.c:913641
void __cdecl _E461_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AD80) --------------------------------------------------------  // acclient.c:913654
void __cdecl _E464_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ADB0) --------------------------------------------------------  // acclient.c:913667
void __cdecl _E467_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ADE0) --------------------------------------------------------  // acclient.c:913680
void __cdecl _E470_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AE10) --------------------------------------------------------  // acclient.c:913693
void __cdecl _E473_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AE40) --------------------------------------------------------  // acclient.c:913706
void __cdecl _E476_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AE70) --------------------------------------------------------  // acclient.c:913719
void __cdecl _E479_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AEA0) --------------------------------------------------------  // acclient.c:913732
void __cdecl _E482_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AED0) --------------------------------------------------------  // acclient.c:913745
void __cdecl _E485_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AF00) --------------------------------------------------------  // acclient.c:913758
void __cdecl _E488_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AF30) --------------------------------------------------------  // acclient.c:913771
void __cdecl _E491_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AF60) --------------------------------------------------------  // acclient.c:913784
void __cdecl _E494_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AF90) --------------------------------------------------------  // acclient.c:913797
void __cdecl _E497_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AFC0) --------------------------------------------------------  // acclient.c:913810
void __cdecl _E500_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077AFF0) --------------------------------------------------------  // acclient.c:913823
void __cdecl _E503_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B020) --------------------------------------------------------  // acclient.c:913836
void __cdecl _E506_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B050) --------------------------------------------------------  // acclient.c:913849
void __cdecl _E509_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B080) --------------------------------------------------------  // acclient.c:913862
void __cdecl _E512_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B0B0) --------------------------------------------------------  // acclient.c:913875
void __cdecl _E515_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B0E0) --------------------------------------------------------  // acclient.c:913888
void __cdecl _E518_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B110) --------------------------------------------------------  // acclient.c:913901
void __cdecl _E521_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B140) --------------------------------------------------------  // acclient.c:913914
void __cdecl _E524_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B170) --------------------------------------------------------  // acclient.c:913927
void __cdecl _E527_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B1A0) --------------------------------------------------------  // acclient.c:913940
void __cdecl _E530_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B1D0) --------------------------------------------------------  // acclient.c:913953
void __cdecl _E533_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B200) --------------------------------------------------------  // acclient.c:913966
void __cdecl _E536_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B230) --------------------------------------------------------  // acclient.c:913979
void __cdecl _E539_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B260) --------------------------------------------------------  // acclient.c:913992
void __cdecl _E542_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B290) --------------------------------------------------------  // acclient.c:914005
void __cdecl _E545_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B2C0) --------------------------------------------------------  // acclient.c:914018
void __cdecl _E548_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B2F0) --------------------------------------------------------  // acclient.c:914031
void __cdecl _E551_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B320) --------------------------------------------------------  // acclient.c:914044
void __cdecl _E554_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B350) --------------------------------------------------------  // acclient.c:914057
void __cdecl _E557_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B380) --------------------------------------------------------  // acclient.c:914070
void __cdecl _E560_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B3B0) --------------------------------------------------------  // acclient.c:914083
void __cdecl _E563_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B3E0) --------------------------------------------------------  // acclient.c:914096
void __cdecl _E566_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B410) --------------------------------------------------------  // acclient.c:914109
void __cdecl _E569_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B440) --------------------------------------------------------  // acclient.c:914122
void __cdecl _E572_4()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B470) --------------------------------------------------------  // acclient.c:914135
void __cdecl _E575_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B4A0) --------------------------------------------------------  // acclient.c:914148
void __cdecl _E578_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B4D0) --------------------------------------------------------  // acclient.c:914161
void __cdecl _E581_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B500) --------------------------------------------------------  // acclient.c:914174
void __cdecl _E584_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B530) --------------------------------------------------------  // acclient.c:914187
void __cdecl _E587_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B560) --------------------------------------------------------  // acclient.c:914200
void __cdecl _E590_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B590) --------------------------------------------------------  // acclient.c:914213
void __cdecl _E593_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B5C0) --------------------------------------------------------  // acclient.c:914226
void __cdecl _E596_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B5F0) --------------------------------------------------------  // acclient.c:914239
void __cdecl _E599_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B620) --------------------------------------------------------  // acclient.c:914252
void __cdecl _E602_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B650) --------------------------------------------------------  // acclient.c:914265
void __cdecl _E605_4()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B680) --------------------------------------------------------  // acclient.c:914278
void __cdecl _E608_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B6B0) --------------------------------------------------------  // acclient.c:914291
void __cdecl _E611_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B6E0) --------------------------------------------------------  // acclient.c:914304
void __cdecl _E614_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B710) --------------------------------------------------------  // acclient.c:914317
void __cdecl _E617_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B740) --------------------------------------------------------  // acclient.c:914330
void __cdecl _E620_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B770) --------------------------------------------------------  // acclient.c:914343
void __cdecl _E623_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B7A0) --------------------------------------------------------  // acclient.c:914356
void __cdecl _E626_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B7D0) --------------------------------------------------------  // acclient.c:914369
void __cdecl _E629_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B800) --------------------------------------------------------  // acclient.c:914382
void __cdecl _E632_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B830) --------------------------------------------------------  // acclient.c:914395
void __cdecl _E635_4()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B860) --------------------------------------------------------  // acclient.c:914408
void __cdecl _E638_4()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B890) --------------------------------------------------------  // acclient.c:914421
void __cdecl _E641_4()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B8C0) --------------------------------------------------------  // acclient.c:914434
void __cdecl _E644_4()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B8F0) --------------------------------------------------------  // acclient.c:914447
void __cdecl _E647_4()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B920) --------------------------------------------------------  // acclient.c:914460
void __cdecl _E650_4()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B950) --------------------------------------------------------  // acclient.c:914473
void __cdecl _E653_4()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B980) --------------------------------------------------------  // acclient.c:914486
void __cdecl _E656_4()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B9B0) --------------------------------------------------------  // acclient.c:914499
void __cdecl _E659_4()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077B9E0) --------------------------------------------------------  // acclient.c:914512
void __cdecl _E662_4()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BA10) --------------------------------------------------------  // acclient.c:914525
void __cdecl _E665_4()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BA40) --------------------------------------------------------  // acclient.c:914538
void __cdecl _E668_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BA70) --------------------------------------------------------  // acclient.c:914551
void __cdecl _E671_4()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BAA0) --------------------------------------------------------  // acclient.c:914564
void __cdecl _E674_4()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BAD0) --------------------------------------------------------  // acclient.c:914577
void __cdecl _E677_4()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BB00) --------------------------------------------------------  // acclient.c:914590
void __cdecl _E680_4()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BB30) --------------------------------------------------------  // acclient.c:914603
void __cdecl _E683_4()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BB60) --------------------------------------------------------  // acclient.c:914616
void __cdecl _E686_4()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BB90) --------------------------------------------------------  // acclient.c:914629
void __cdecl _E689_4()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BBC0) --------------------------------------------------------  // acclient.c:914642
void __cdecl _E692_4()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BBF0) --------------------------------------------------------  // acclient.c:914655
void __cdecl _E695_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BC20) --------------------------------------------------------  // acclient.c:914668
void __cdecl _E698_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BC50) --------------------------------------------------------  // acclient.c:914681
void __cdecl _E701_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BC80) --------------------------------------------------------  // acclient.c:914694
void __cdecl _E704_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BCB0) --------------------------------------------------------  // acclient.c:914707
void __cdecl _E707_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BCE0) --------------------------------------------------------  // acclient.c:914720
void __cdecl _E710_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BD10) --------------------------------------------------------  // acclient.c:914733
void __cdecl _E713_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BD40) --------------------------------------------------------  // acclient.c:914746
void __cdecl _E716_4()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BD70) --------------------------------------------------------  // acclient.c:914759
void __cdecl _E719_4()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BDA0) --------------------------------------------------------  // acclient.c:914772
void __cdecl _E722_4()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BDD0) --------------------------------------------------------  // acclient.c:914785
void __cdecl _E725_4()
{
  char *v0; // esi@1

  v0 = &stru_8F036C.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F036C.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BE00) --------------------------------------------------------  // acclient.c:914798
void __cdecl _E728_4()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BE30) --------------------------------------------------------  // acclient.c:914811
void __cdecl _E731_4()
{
  char *v0; // esi@1

  v0 = &SamplerName_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BE60) --------------------------------------------------------  // acclient.c:914824
void __cdecl _E734_4()
{
  char *v0; // esi@1

  v0 = &Texture_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BE90) --------------------------------------------------------  // acclient.c:914837
void __cdecl _E737_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BEC0) --------------------------------------------------------  // acclient.c:914850
void __cdecl _E740_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BEF0) --------------------------------------------------------  // acclient.c:914863
void __cdecl _E743_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BF20) --------------------------------------------------------  // acclient.c:914876
void __cdecl _E746_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BF50) --------------------------------------------------------  // acclient.c:914889
void __cdecl _E749_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BF80) --------------------------------------------------------  // acclient.c:914902
void __cdecl _E752_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BFB0) --------------------------------------------------------  // acclient.c:914915
void __cdecl _E755_4()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077BFE0) --------------------------------------------------------  // acclient.c:914928
void __cdecl _E758_4()
{
  char *v0; // esi@1

  v0 = &AddressMode_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C010) --------------------------------------------------------  // acclient.c:914941
void __cdecl _E761_4()
{
  char *v0; // esi@1

  v0 = &TexFilter_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C040) --------------------------------------------------------  // acclient.c:914954
void __cdecl _E764_4()
{
  char *v0; // esi@1

  v0 = &ColorOp_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C070) --------------------------------------------------------  // acclient.c:914967
void __cdecl _E767_4()
{
  char *v0; // esi@1

  v0 = &ColorArg1_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C0A0) --------------------------------------------------------  // acclient.c:914980
void __cdecl _E770_4()
{
  char *v0; // esi@1

  v0 = &ColorArg2_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C0D0) --------------------------------------------------------  // acclient.c:914993
void __cdecl _E773_4()
{
  char *v0; // esi@1

  v0 = &AlphaOp_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C100) --------------------------------------------------------  // acclient.c:915006
void __cdecl _E776_4()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C130) --------------------------------------------------------  // acclient.c:915019
void __cdecl _E779_4()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C160) --------------------------------------------------------  // acclient.c:915032
void __cdecl _E782_4()
{
  char *v0; // esi@1

  v0 = &TexCoord_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C190) --------------------------------------------------------  // acclient.c:915045
void __cdecl _E785_4()
{
  char *v0; // esi@1

  v0 = &UseProjection_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C1C0) --------------------------------------------------------  // acclient.c:915058
void __cdecl _E788_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C1F0) --------------------------------------------------------  // acclient.c:915071
void __cdecl _E791_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C220) --------------------------------------------------------  // acclient.c:915084
void __cdecl _E794_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C250) --------------------------------------------------------  // acclient.c:915097
void __cdecl _E797_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C280) --------------------------------------------------------  // acclient.c:915110
void __cdecl _E800_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C2B0) --------------------------------------------------------  // acclient.c:915123
void __cdecl _E803_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C2E0) --------------------------------------------------------  // acclient.c:915136
void __cdecl _E806_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C310) --------------------------------------------------------  // acclient.c:915149
void __cdecl _E809_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C340) --------------------------------------------------------  // acclient.c:915162
void __cdecl _E812_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C370) --------------------------------------------------------  // acclient.c:915175
void __cdecl _E815_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C3A0) --------------------------------------------------------  // acclient.c:915188
void __cdecl _E818_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C3D0) --------------------------------------------------------  // acclient.c:915201
void __cdecl _E821_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C400) --------------------------------------------------------  // acclient.c:915214
void __cdecl _E824_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C430) --------------------------------------------------------  // acclient.c:915227
void __cdecl _E827_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C460) --------------------------------------------------------  // acclient.c:915240
void __cdecl _E830_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C490) --------------------------------------------------------  // acclient.c:915253
void __cdecl _E833_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C4C0) --------------------------------------------------------  // acclient.c:915266
void __cdecl _E836_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C4F0) --------------------------------------------------------  // acclient.c:915279
void __cdecl _E839_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C520) --------------------------------------------------------  // acclient.c:915292
void __cdecl _E842_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C550) --------------------------------------------------------  // acclient.c:915305
void __cdecl _E845_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C580) --------------------------------------------------------  // acclient.c:915318
void __cdecl _E848_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C5B0) --------------------------------------------------------  // acclient.c:915331
void __cdecl _E851_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C5E0) --------------------------------------------------------  // acclient.c:915344
void __cdecl _E854_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C610) --------------------------------------------------------  // acclient.c:915357
void __cdecl _E857_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C640) --------------------------------------------------------  // acclient.c:915370
void __cdecl _E860_4()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C670) --------------------------------------------------------  // acclient.c:915383
void __cdecl _E863_4()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C6A0) --------------------------------------------------------  // acclient.c:915396
void __cdecl _E866_4()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C6D0) --------------------------------------------------------  // acclient.c:915409
void __cdecl _E869_4()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C700) --------------------------------------------------------  // acclient.c:915422
void __cdecl _E872_4()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C730) --------------------------------------------------------  // acclient.c:915435
void __cdecl _E875_4()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C760) --------------------------------------------------------  // acclient.c:915448
void __cdecl _E878_4()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C790) --------------------------------------------------------  // acclient.c:915461
void __cdecl _E881_4()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C7C0) --------------------------------------------------------  // acclient.c:915474
void __cdecl _E884_4()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C7F0) --------------------------------------------------------  // acclient.c:915487
void __cdecl _E887_4()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C820) --------------------------------------------------------  // acclient.c:915500
void __cdecl _E890_4()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C850) --------------------------------------------------------  // acclient.c:915513
void __cdecl _E893_4()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C880) --------------------------------------------------------  // acclient.c:915526
void __cdecl _E896_4()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C8B0) --------------------------------------------------------  // acclient.c:915539
void __cdecl _E899_4()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C8E0) --------------------------------------------------------  // acclient.c:915552
void __cdecl _E902_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C910) --------------------------------------------------------  // acclient.c:915565
void __cdecl _E905_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C940) --------------------------------------------------------  // acclient.c:915578
void __cdecl _E908_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C970) --------------------------------------------------------  // acclient.c:915591
void __cdecl _E911_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C9A0) --------------------------------------------------------  // acclient.c:915604
void __cdecl _E914_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077C9D0) --------------------------------------------------------  // acclient.c:915617
void __cdecl _E917_4()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CA00) --------------------------------------------------------  // acclient.c:915630
void __cdecl _E920_4()
{
  char *v0; // esi@1

  v0 = &stru_8F0470.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0470.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CA30) --------------------------------------------------------  // acclient.c:915643
void __cdecl _E923_4()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CA60) --------------------------------------------------------  // acclient.c:915656
void __cdecl _E926_4()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CA90) --------------------------------------------------------  // acclient.c:915669
void __cdecl _E929_4()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CAC0) --------------------------------------------------------  // acclient.c:915682
void __cdecl _E932_4()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CAF0) --------------------------------------------------------  // acclient.c:915695
void __cdecl _E935_4()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CB20) --------------------------------------------------------  // acclient.c:915708
void __cdecl _E938_4()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CB50) --------------------------------------------------------  // acclient.c:915721
void __cdecl _E941_4()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CB80) --------------------------------------------------------  // acclient.c:915734
void __cdecl _E944_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CBB0) --------------------------------------------------------  // acclient.c:915747
void __cdecl _E947_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CBE0) --------------------------------------------------------  // acclient.c:915760
void __cdecl _E950_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CC10) --------------------------------------------------------  // acclient.c:915773
void __cdecl _E953_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CC40) --------------------------------------------------------  // acclient.c:915786
void __cdecl _E956_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CC70) --------------------------------------------------------  // acclient.c:915799
void __cdecl _E959_4()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CCA0) --------------------------------------------------------  // acclient.c:915812
void __cdecl _E962_4()
{
  char *v0; // esi@1

  v0 = &stru_8F04A8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F04A8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CCD0) --------------------------------------------------------  // acclient.c:915825
void __cdecl _E965_4()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CD00) --------------------------------------------------------  // acclient.c:915838
void __cdecl _E968_4()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CD30) --------------------------------------------------------  // acclient.c:915851
void __cdecl _E971_4()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CD60) --------------------------------------------------------  // acclient.c:915864
void __cdecl _E974_4()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CD90) --------------------------------------------------------  // acclient.c:915877
void __cdecl _E977_4()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CDC0) --------------------------------------------------------  // acclient.c:915890
void __cdecl _E980_4()
{
  char *v0; // esi@1

  v0 = &ScaleType_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CDF0) --------------------------------------------------------  // acclient.c:915903
void __cdecl _E983_4()
{
  char *v0; // esi@1

  v0 = &WorldSpace_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CE20) --------------------------------------------------------  // acclient.c:915916
void __cdecl _E986_4()
{
  char *v0; // esi@1

  v0 = &ForceDraw_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CE50) --------------------------------------------------------  // acclient.c:915929
void __cdecl _E989_4()
{
  char *v0; // esi@1

  v0 = &NumEmitters_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CE80) --------------------------------------------------------  // acclient.c:915942
void __cdecl _E992_4()
{
  char *v0; // esi@1

  v0 = &Material_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CEB0) --------------------------------------------------------  // acclient.c:915955
void __cdecl _E995_4()
{
  char *v0; // esi@1

  v0 = &Version_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CEE0) --------------------------------------------------------  // acclient.c:915968
void __cdecl _E998_4()
{
  char *v0; // esi@1

  v0 = &MaxParticles_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CF10) --------------------------------------------------------  // acclient.c:915981
void __cdecl _E1001_4()
{
  char *v0; // esi@1

  v0 = &stru_8F04DC.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F04DC.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CF40) --------------------------------------------------------  // acclient.c:915994
void __cdecl _E1004_4()
{
  char *v0; // esi@1

  v0 = &Origin_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CF70) --------------------------------------------------------  // acclient.c:916007
void __cdecl _E1007_4()
{
  char *v0; // esi@1

  v0 = &Shape_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CFA0) --------------------------------------------------------  // acclient.c:916020
void __cdecl _E1010_4()
{
  char *v0; // esi@1

  v0 = &Shape_Point_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077CFD0) --------------------------------------------------------  // acclient.c:916033
void __cdecl _E1013_4()
{
  char *v0; // esi@1

  v0 = &Shape_Line_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D000) --------------------------------------------------------  // acclient.c:916046
void __cdecl _E1016_4()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D030) --------------------------------------------------------  // acclient.c:916059
void __cdecl _E1019_4()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D060) --------------------------------------------------------  // acclient.c:916072
void __cdecl _E1022_4()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D090) --------------------------------------------------------  // acclient.c:916085
void __cdecl _E1025_4()
{
  char *v0; // esi@1

  v0 = &ParticleShape_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D0C0) --------------------------------------------------------  // acclient.c:916098
void __cdecl _E1028_4()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D0F0) --------------------------------------------------------  // acclient.c:916111
void __cdecl _E1031_4()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D120) --------------------------------------------------------  // acclient.c:916124
void __cdecl _E1034_4()
{
  char *v0; // esi@1

  v0 = &Streak_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D150) --------------------------------------------------------  // acclient.c:916137
void __cdecl _E1037_4()
{
  char *v0; // esi@1

  v0 = &Rotation_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D180) --------------------------------------------------------  // acclient.c:916150
void __cdecl _E1040_4()
{
  char *v0; // esi@1

  v0 = &WorldRotation_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D1B0) --------------------------------------------------------  // acclient.c:916163
void __cdecl _E1043_4()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D1E0) --------------------------------------------------------  // acclient.c:916176
void __cdecl _E1046_4()
{
  char *v0; // esi@1

  v0 = &ParticleScale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D210) --------------------------------------------------------  // acclient.c:916189
void __cdecl _E1049_4()
{
  char *v0; // esi@1

  v0 = &Scale_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D240) --------------------------------------------------------  // acclient.c:916202
void __cdecl _E1052_4()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D270) --------------------------------------------------------  // acclient.c:916215
void __cdecl _E1055_4()
{
  char *v0; // esi@1

  v0 = &BirthRate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D2A0) --------------------------------------------------------  // acclient.c:916228
void __cdecl _E1058_4()
{
  char *v0; // esi@1

  v0 = &Lifespan_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D2D0) --------------------------------------------------------  // acclient.c:916241
void __cdecl _E1061_4()
{
  char *v0; // esi@1

  v0 = &Velocity_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D300) --------------------------------------------------------  // acclient.c:916254
void __cdecl _E1064_4()
{
  char *v0; // esi@1

  v0 = &Direction_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D330) --------------------------------------------------------  // acclient.c:916267
void __cdecl _E1067_4()
{
  char *v0; // esi@1

  v0 = &MinSpread_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D360) --------------------------------------------------------  // acclient.c:916280
void __cdecl _E1070_4()
{
  char *v0; // esi@1

  v0 = &MaxSpread_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D390) --------------------------------------------------------  // acclient.c:916293
void __cdecl _E1073_4()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D3C0) --------------------------------------------------------  // acclient.c:916306
void __cdecl _E1076_4()
{
  char *v0; // esi@1

  v0 = &BlastCount_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D3F0) --------------------------------------------------------  // acclient.c:916319
void __cdecl _E1079_4()
{
  char *v0; // esi@1

  v0 = &StartTime_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D420) --------------------------------------------------------  // acclient.c:916332
void __cdecl _E1082_4()
{
  char *v0; // esi@1

  v0 = &TimeLimit_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D450) --------------------------------------------------------  // acclient.c:916345
void __cdecl _E1085_4()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D480) --------------------------------------------------------  // acclient.c:916358
void __cdecl _E1088_4()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D4B0) --------------------------------------------------------  // acclient.c:916371
void __cdecl _E1091_4()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D4E0) --------------------------------------------------------  // acclient.c:916384
void __cdecl _E1094_4()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D510) --------------------------------------------------------  // acclient.c:916397
void __cdecl _E1097_4()
{
  char *v0; // esi@1

  v0 = &IsActive_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D540) --------------------------------------------------------  // acclient.c:916410
void __cdecl _E1100_4()
{
  char *v0; // esi@1

  v0 = &FadeIn_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D570) --------------------------------------------------------  // acclient.c:916423
void __cdecl _E1103_4()
{
  char *v0; // esi@1

  v0 = &FadeOut_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D5A0) --------------------------------------------------------  // acclient.c:916436
void __cdecl _E1106_4()
{
  char *v0; // esi@1

  v0 = &ConstrainX_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D5D0) --------------------------------------------------------  // acclient.c:916449
void __cdecl _E1109_4()
{
  char *v0; // esi@1

  v0 = &ConstrainY_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D600) --------------------------------------------------------  // acclient.c:916462
void __cdecl _E1112_4()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D630) --------------------------------------------------------  // acclient.c:916475
void __cdecl _E1115_4()
{
  char *v0; // esi@1

  v0 = &stru_8F0574.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F0574.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D660) --------------------------------------------------------  // acclient.c:916488
void __cdecl _E1118_4()
{
  char *v0; // esi@1

  v0 = &Time_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D690) --------------------------------------------------------  // acclient.c:916501
void __cdecl _E1121_4()
{
  char *v0; // esi@1

  v0 = &Flags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D6C0) --------------------------------------------------------  // acclient.c:916514
void __cdecl _E1124_4()
{
  char *v0; // esi@1

  v0 = &Flags_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D6F0) --------------------------------------------------------  // acclient.c:916527
void __cdecl _E1127_4()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D720) --------------------------------------------------------  // acclient.c:916540
void __cdecl _E1130_4()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D750) --------------------------------------------------------  // acclient.c:916553
void __cdecl _E1133_4()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D780) --------------------------------------------------------  // acclient.c:916566
void __cdecl _E1136_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D7B0) --------------------------------------------------------  // acclient.c:916579
void __cdecl _E1139_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D7E0) --------------------------------------------------------  // acclient.c:916592
void __cdecl _E1142_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D810) --------------------------------------------------------  // acclient.c:916605
void __cdecl _E1145_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D840) --------------------------------------------------------  // acclient.c:916618
void __cdecl _E1148_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D870) --------------------------------------------------------  // acclient.c:916631
void __cdecl _E1151_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D8A0) --------------------------------------------------------  // acclient.c:916644
void __cdecl _E1154_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D8D0) --------------------------------------------------------  // acclient.c:916657
void __cdecl _E1157_4()
{
  char *v0; // esi@1

  v0 = &Scale_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D900) --------------------------------------------------------  // acclient.c:916670
void __cdecl _E1160_4()
{
  char *v0; // esi@1

  v0 = &ScaleX_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D930) --------------------------------------------------------  // acclient.c:916683
void __cdecl _E1163_4()
{
  char *v0; // esi@1

  v0 = &ScaleY_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D960) --------------------------------------------------------  // acclient.c:916696
void __cdecl _E1166_4()
{
  char *v0; // esi@1

  v0 = &Color_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D990) --------------------------------------------------------  // acclient.c:916709
void __cdecl _E1169_4()
{
  char *v0; // esi@1

  v0 = &Mass_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D9C0) --------------------------------------------------------  // acclient.c:916722
void __cdecl _E1172_4()
{
  char *v0; // esi@1

  v0 = &PFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077D9F0) --------------------------------------------------------  // acclient.c:916735
void __cdecl _E1175_4()
{
  char *v0; // esi@1

  v0 = &PFlags_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DA20) --------------------------------------------------------  // acclient.c:916748
void __cdecl _E1178_4()
{
  char *v0; // esi@1

  v0 = &PCType_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DA50) --------------------------------------------------------  // acclient.c:916761
void __cdecl _E1181_4()
{
  char *v0; // esi@1

  v0 = &PCType_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DA80) --------------------------------------------------------  // acclient.c:916774
void __cdecl _E1184_4()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DAB0) --------------------------------------------------------  // acclient.c:916787
void __cdecl _E1187_4()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DAE0) --------------------------------------------------------  // acclient.c:916800
void __cdecl _E1190_4()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DB10) --------------------------------------------------------  // acclient.c:916813
void __cdecl _E1193_4()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DB40) --------------------------------------------------------  // acclient.c:916826
void __cdecl _E1196_4()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DB70) --------------------------------------------------------  // acclient.c:916839
void __cdecl _E1199_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DBA0) --------------------------------------------------------  // acclient.c:916852
void __cdecl _E1202_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DBD0) --------------------------------------------------------  // acclient.c:916865
void __cdecl _E1205_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DC00) --------------------------------------------------------  // acclient.c:916878
void __cdecl _E1208_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DC30) --------------------------------------------------------  // acclient.c:916891
void __cdecl _E1211_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DC60) --------------------------------------------------------  // acclient.c:916904
void __cdecl _E1214_4()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DC90) --------------------------------------------------------  // acclient.c:916917
void __cdecl _E1217_4()
{
  char *v0; // esi@1

  v0 = &Position_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DCC0) --------------------------------------------------------  // acclient.c:916930
void __cdecl _E1220_4()
{
  char *v0; // esi@1

  v0 = &PointList_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DCF0) --------------------------------------------------------  // acclient.c:916943
void __cdecl _E1223_4()
{
  char *v0; // esi@1

  v0 = &Point_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DD20) --------------------------------------------------------  // acclient.c:916956
void __cdecl _E1226_4()
{
  char *v0; // esi@1

  v0 = &DetailLevels_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DD50) --------------------------------------------------------  // acclient.c:916969
void __cdecl _E1229_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DD80) --------------------------------------------------------  // acclient.c:916982
void __cdecl _E1232_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DDB0) --------------------------------------------------------  // acclient.c:916995
void __cdecl _E1235_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DDE0) --------------------------------------------------------  // acclient.c:917008
void __cdecl _E1238_4()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DE10) --------------------------------------------------------  // acclient.c:917021
void __cdecl _E1241_4()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DE40) --------------------------------------------------------  // acclient.c:917034
void __cdecl _E1244_4()
{
  char *v0; // esi@1

  v0 = &Point_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DE70) --------------------------------------------------------  // acclient.c:917047
void __cdecl _E1247_4()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DEA0) --------------------------------------------------------  // acclient.c:917060
void __cdecl _E1250_4()
{
  char *v0; // esi@1

  v0 = &PointTexture_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DED0) --------------------------------------------------------  // acclient.c:917073
void __cdecl _E1253_4()
{
  char *v0; // esi@1

  v0 = &PointSize_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DF00) --------------------------------------------------------  // acclient.c:917086
void __cdecl _E1256_4()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

