/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderMeshBatch
   Object     : ENGINE\render_base\RenderMeshBatch.obj
   Functions  : 175
   Addresses  : 0044F280 - 0074CEF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044F280) --------------------------------------------------------  // acclient.c:140523
void __thiscall RenderMeshBatch::RenderMeshBatch(RenderMeshBatch *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderMeshBatch::vftable;
  this->m_PrimitivesType = 0x7FFFFFFF;
  this->m_pContainerMesh = 0;
  this->m_MaterialIndex = -1;
  this->m_VertexArrayIndex = -1;
  this->m_IndexArrayIndex = -1;
  this->m_FirstIndex = 0;
  this->m_NumPrimitives = 0;
  this->m_pIBTrickUserObjectPointer = 0;
  this->m_IBTrickVertexSkinningID = 0;
  this->m_IBTrickStreamFrameID = -1;
  this->m_IBTrickBaseVertexIndex = -1;
}
// 79B38C: using guessed type int (__thiscall *RenderMeshBatch::vftable)(void *, char);

//----- (0044F2C0) --------------------------------------------------------  // acclient.c:140542
RenderMeshBatch *__thiscall RenderMeshBatch::scalar_deleting_destructor(RenderMeshBatch *this, unsigned int a2)
{
  RenderMeshBatch *v2; // esi@1

  v2 = this;
  this->m_pContainerMesh = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);

//----- (0044F2F0) --------------------------------------------------------  // acclient.c:140556
bool __thiscall RenderMeshBatch::InitRenderBatch(RenderMeshBatch *this, MaterialInstance *_pMaterial, PrimType _PrimitivesType, const unsigned int _ExistingVertexArrayIndex, const unsigned int _NumVertices, const unsigned int _VertexFormat, int _UseStaticVertices, int _OnlyWriteVerticesOnce, RenderVertexBuffer **_pNewVertexArray)
{
  const unsigned int v9; // ebp@1
  RenderMeshBatch *v10; // esi@1
  RenderVertexBuffer *v11; // eax@2
  RenderVertexBuffer *v12; // ecx@3
  bool v13; // zf@4
  bool result; // al@7
  const unsigned int v15; // eax@10

  v9 = _NumVertices;
  v10 = this;
  *_pNewVertexArray = 0;
  if ( _ExistingVertexArrayIndex != -1
    || (RenderVertexBuffer::AllocateVertexBuffer(),
        *_pNewVertexArray = v11,
        (unsigned __int8)((int (__thiscall *)(RenderVertexBuffer *, const unsigned int, const unsigned int, int, int, signed int))v11->vfptr[1].__vecDelDtor)(
                           v11,
                           _NumVertices,
                           _VertexFormat,
                           _UseStaticVertices,
                           _OnlyWriteVerticesOnce,
                           -1)) )
  {
    v10->m_PrimitivesType = _PrimitivesType;
    if ( _pMaterial )
    {
      _pMaterial->vfptr->AddRef((Interface *)_pMaterial);
      v10->m_MaterialIndex = RenderMesh::AddMaterial(
                               v10->m_pContainerMesh,
                               (_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>)__PAIR__(
                                                                                          (unsigned int)_pMaterial,
                                                                                          INVALID_DID_44.id));
    }
    v15 = _ExistingVertexArrayIndex;
    if ( _ExistingVertexArrayIndex == -1 )
      v15 = RenderMesh::AddVertexArray(v10->m_pContainerMesh, *_pNewVertexArray);
    v10->m_VertexArrayIndex = v15;
    v10->m_FirstIndex = 0;
    v10->m_NumPrimitives = 0;
    switch ( v10->m_PrimitivesType )
    {
      case 2:
        v10->m_NumPrimitives = _NumVertices >> 1;
        return 1;
      case 3:
        v10->m_NumPrimitives = _NumVertices - 1;
        return 1;
      case 4:
        v10->m_NumPrimitives = _NumVertices / 3;
        return 1;
      case 5:
      case 6:
        v9 = _NumVertices - 2;
        goto $L105517;
      case 1:
$L105517:
        v10->m_NumPrimitives = v9;
        break;
      default:
        break;
    }
    result = 1;
  }
  else
  {
    v12 = *_pNewVertexArray;
    if ( *_pNewVertexArray )
    {
      v13 = v12->m_cRef-- == 1;
      if ( v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      *_pNewVertexArray = 0;
    }
    result = 0;
  }
  return result;
}

//----- (0044F410) --------------------------------------------------------  // acclient.c:140636
void __thiscall RenderMeshBatch::Serialize(RenderMeshBatch *this, Archive *io_archive, RenderMesh *_pContainerMesh)
{
  RenderMeshBatch *v3; // edi@1
  unsigned __int8 v4; // bl@3
  unsigned int v5; // eax@3
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17
  unsigned int v9; // eax@21
  unsigned int v10; // eax@25

  v3 = this;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    this->m_pContainerMesh = _pContainerMesh;
  v4 = LOBYTE(this->m_PrimitivesType);
  Archive::CheckAlignment(io_archive, 1u);
  v5 = Archive::GetBytes(io_archive, 1u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v5 = v4;
    else
      v4 = *(_BYTE *)v5;
  }
  if ( !(io_archive->m_flags & 5) )
    v3->m_PrimitivesType = v4;
  Archive::CheckAlignment(io_archive, 4u);
  v6 = Archive::GetBytes(io_archive, 4u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v6 = v3->m_MaterialIndex;
    else
      v3->m_MaterialIndex = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v7 = v3->m_VertexArrayIndex;
    else
      v3->m_VertexArrayIndex = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v8 = Archive::GetBytes(io_archive, 4u);
  if ( v8 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v8 = v3->m_IndexArrayIndex;
    else
      v3->m_IndexArrayIndex = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v9 = Archive::GetBytes(io_archive, 4u);
  if ( v9 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v9 = v3->m_FirstIndex;
    else
      v3->m_FirstIndex = *(_DWORD *)v9;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v10 = Archive::GetBytes(io_archive, 4u);
  if ( v10 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v10 = v3->m_NumPrimitives;
    else
      v3->m_NumPrimitives = *(_DWORD *)v10;
  }
}

//----- (0044F530) --------------------------------------------------------  // acclient.c:140710
char __userpurge RenderMeshBatch::ParseFromFileNode@<al>(RenderMeshBatch *this@<ecx>, int a2@<edi>, PFileNode *_pBaseNode)
{
  RenderMeshBatch *v3; // ebp@1
  PFileNode *v4; // esi@2
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // eax@4
  PFileNode *v6; // eax@4
  PFileNode *v7; // esi@4
  int v8; // ecx@15
  ReferenceCountTemplate<1048576,0>Vtbl *v9; // edx@18
  PFileNode *v10; // eax@18
  int v11; // ecx@18
  char *v12; // esi@22
  int v13; // edx@24
  char *v14; // ecx@24
  unsigned int v16; // eax@29
  char *v17; // esi@29
  int v18; // eax@31
  ReferenceCountTemplate<1048576,0>Vtbl *v19; // edx@33
  int v20; // eax@33
  PFileNode *v21; // eax@33
  int v22; // ecx@33
  int v23; // ecx@35
  ReferenceCountTemplate<1048576,0>Vtbl *v24; // eax@36
  PFileNode *v25; // eax@36
  int v26; // ecx@36
  bool v27; // zf@45
  int v28; // eax@46
  __int64 v29; // [sp-8h] [bp-28h]@29
  IDClass<_tagDataID,32,0> result; // [sp+10h] [bp-10h]@21
  PFileNodeIter iter; // [sp+14h] [bp-Ch]@2

  v3 = this;
  if ( !_pBaseNode )
    return 0;
  PFileNodeIter::PFileNodeIter(&iter, _pBaseNode);
  v4 = PFileNodeIter::Curr(&iter);
  if ( !v4 )
  {
LABEL_40:
    if ( v3->m_VertexArrayIndex == -1 || v3->m_PrimitivesType == 0x7FFFFFFF )
      goto LABEL_26;
    PFileNodeIter::~PFileNodeIter(&iter);
    return 1;
  }
  while ( 1 )
  {
    if ( PFileNode::IsKeyword(v4, a2, &PrimitivesType_1) )
    {
      v5 = v4->vfptr;
      HIDWORD(v29) = 0;
      v6 = (PFileNode *)v5[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 0);
      v7 = v6;
      if ( !v6 )
        goto LABEL_26;
      if ( PFileNode::IsKeyword(v6, a2, &PrimitivesType_PointList_1) )
      {
        v3->m_PrimitivesType = 1;
      }
      else if ( PFileNode::IsKeyword(v7, a2, &PrimitivesType_LineList_1) )
      {
        v3->m_PrimitivesType = 2;
      }
      else if ( PFileNode::IsKeyword(v7, a2, &PrimitivesType_LineStrip_1) )
      {
        v3->m_PrimitivesType = 3;
      }
      else if ( PFileNode::IsKeyword(v7, a2, &PrimitivesType_TriangleList_1) )
      {
        v3->m_PrimitivesType = 4;
      }
      else if ( PFileNode::IsKeyword(v7, a2, &PrimitivesType_TriangleStrip_1) )
      {
        v3->m_PrimitivesType = 5;
      }
      else
      {
        if ( !PFileNode::IsKeyword(v7, a2, &PrimitivesType_TriangleFan_1) )
        {
          HIDWORD(v29) = v8;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v29 + 1, "Unrecognized primitives type");
          PFileNode::ReportError(a2, v7, HIDWORD(v29));
          goto LABEL_26;
        }
        v3->m_PrimitivesType = 6;
      }
      goto LABEL_39;
    }
    if ( !PFileNode::IsKeyword(v4, a2, &Material_25) )
      break;
    _pBaseNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v9 = v4->vfptr;
    HIDWORD(v29) = 0;
    v10 = (PFileNode *)v9[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 0);
    if ( v10 )
      PFileNode::GetNameAsPString(v10, a2, (PStringBase<char> *)&_pBaseNode);
    a2 = INVALID_DID_44.id;
    if ( _pBaseNode[-1].user_data == 1 )
    {
      HIDWORD(v29) = v11;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v29 + 1, "Material file name is empty!");
      PFileNode::ReportWarning(a2, v4, HIDWORD(v29));
    }
    else
    {
      a2 = FileArray::GetDID(&result, (PStringBase<char> *)&_pBaseNode, 0x21u)->id;
      if ( a2 == INVALID_DID_44.id )
      {
        v12 = (char *)&_pBaseNode[-1].sub_nodes.m_num;
        if ( !InterlockedDecrement((volatile LONG *)&_pBaseNode[-1].m_bProcessed) && v12 )
        {
          v13 = *(_DWORD *)v12;
          HIDWORD(v29) = 1;
          v14 = v12;
LABEL_25:
          (*(void (__thiscall **)(char *, _DWORD))v13)(v14, HIDWORD(v29));
          goto LABEL_26;
        }
        goto LABEL_26;
      }
    }
    v29 = (unsigned int)a2;
    v16 = RenderMesh::AddMaterial(
            v3->m_pContainerMesh,
            (_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>)(unsigned int)a2);
    v17 = (char *)&_pBaseNode[-1].sub_nodes.m_num;
    HIDWORD(v29) = (char *)_pBaseNode - 16;
    v3->m_MaterialIndex = v16;
    if ( !InterlockedDecrement(HIDWORD(v29)) && v17 )
    {
      v18 = *(_DWORD *)v17;
      HIDWORD(v29) = 1;
      (*(void (__thiscall **)(char *, signed int))v18)(v17, 1);
    }
LABEL_39:
    v4 = (PFileNode *)PFileNodeIter::Next(&iter);
    if ( !v4 )
      goto LABEL_40;
  }
  if ( PFileNode::IsKeyword(v4, a2, &Vertices_1) )
  {
    RenderVertexBuffer::AllocateVertexBuffer();
    v19 = v4->vfptr;
    HIDWORD(v29) = 0;
    a2 = v20;
    v21 = (PFileNode *)v19[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 0);
    if ( !VertexArray::FromFileNode((VertexArray *)a2, a2, v21) )
    {
      HIDWORD(v29) = v22;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v29 + 1, "Error loading vertex array");
      PFileNode::ReportError(a2, v4, HIDWORD(v29));
      if ( a2 )
      {
        v27 = (*(_DWORD *)(a2 + 4))-- == 1;
        if ( v27 )
        {
          v28 = *(_DWORD *)a2;
          HIDWORD(v29) = 1;
          (*(void (__thiscall **)(int, signed int))v28)(a2, 1);
        }
      }
      goto LABEL_26;
    }
    v3->m_VertexArrayIndex = RenderMesh::AddVertexArray(v3->m_pContainerMesh, (RenderVertexBuffer *)a2);
    goto LABEL_39;
  }
  if ( !PFileNode::IsKeyword(v4, a2, &Indices_9) )
  {
    HIDWORD(v29) = v23;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v29 + 1, "Unrecognized keyword in mesh file");
    PFileNode::ReportWarning(a2, v4, HIDWORD(v29));
    goto LABEL_39;
  }
  a2 = (int)RenderIndexBuffer::AllocateIndexBuffer();
  v24 = v4->vfptr;
  HIDWORD(v29) = 0;
  v25 = (PFileNode *)v24[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 0);
  if ( RenderIndexBuffer::FromFileNode((RenderIndexBuffer *)a2, a2, v25) )
  {
    v3->m_IndexArrayIndex = RenderMesh::AddIndexArray(v3->m_pContainerMesh, (RenderIndexBuffer *)a2);
    goto LABEL_39;
  }
  HIDWORD(v29) = v26;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v29 + 1, "Error loading index array");
  PFileNode::ReportError(a2, v4, HIDWORD(v29));
  if ( a2 )
  {
    v13 = *(_DWORD *)a2;
    HIDWORD(v29) = 1;
    v14 = (char *)a2;
    goto LABEL_25;
  }
LABEL_26:
  PFileNodeIter::~PFileNodeIter(&iter);
  return 0;
}

//----- (006DEA80) --------------------------------------------------------  // acclient.c:755954
int _E73_50()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_21, "None");
  return atexit(_E74_38);
}

//----- (006DEAA0) --------------------------------------------------------  // acclient.c:755961
int _E76_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_21, "Speed");
  return atexit(_E77_52);
}

//----- (006DEAC0) --------------------------------------------------------  // acclient.c:755968
int _E79_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_21, "Noise");
  return atexit(_E80_26);
}

//----- (006DEAE0) --------------------------------------------------------  // acclient.c:755975
int _E82_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_21, "Sine");
  return atexit(_E83_16);
}

//----- (006DEB00) --------------------------------------------------------  // acclient.c:755982
int _E85_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_21, "Square");
  return atexit(_E86_13);
}

//----- (006DEB20) --------------------------------------------------------  // acclient.c:755989
int _E88_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_21, "Bounce");
  return atexit(_E89_24);
}

//----- (006DEB40) --------------------------------------------------------  // acclient.c:755996
int _E91_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_21, "Perlin");
  return atexit(_E92_26);
}

//----- (006DEB60) --------------------------------------------------------  // acclient.c:756003
int _E94_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_21, "Fractal");
  return atexit(sub_74C0B0);
}

//----- (006DEB80) --------------------------------------------------------  // acclient.c:756010
int _E97_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_21, "FrameLoop");
  return atexit(_E98_41);
}

//----- (006DEBA0) --------------------------------------------------------  // acclient.c:756017
void _E100_20()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_24, PFID_A8R8G8B8);
}

//----- (006DEBB0) --------------------------------------------------------  // acclient.c:756023
int _E118_15()
{
  PStringBase<char>::PStringBase<char>(&PHeader_6, "PREPROC_HEADER");
  return atexit(_E119_64);
}

//----- (006DEBD0) --------------------------------------------------------  // acclient.c:756030
int _E121_12()
{
  PStringBase<char>::PStringBase<char>(&PreprocHeader_1, "PREPROC_HEADER");
  return atexit(_E122_51);
}

//----- (006DEBF0) --------------------------------------------------------  // acclient.c:756037
int _E124_15()
{
  PStringBase<char>::PStringBase<char>(&MeshAppearanceType_1, "MeshAppearanceType");
  return atexit(_E125_26);
}

//----- (006DEC10) --------------------------------------------------------  // acclient.c:756044
int _E127_11()
{
  PStringBase<char>::PStringBase<char>(&Fragment_1, "Fragment");
  return atexit(_E128_27);
}

//----- (006DEC30) --------------------------------------------------------  // acclient.c:756051
int _E130_12()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_1, "FragmentType");
  return atexit(_E131_23);
}

//----- (006DEC50) --------------------------------------------------------  // acclient.c:756058
int _E133_11()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_LevelOfDetailModel_1, "LevelOfDetailModel");
  return atexit(_E134_22);
}

//----- (006DEC70) --------------------------------------------------------  // acclient.c:756065
int _E136_10()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_OccludeModel_1, "OccludeModel");
  return atexit(_E137_22);
}

//----- (006DEC90) --------------------------------------------------------  // acclient.c:756072
int _E139_9()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_ShadowLODModel_1, "ShadowLODModel");
  return atexit(_E140_17);
}

//----- (006DECB0) --------------------------------------------------------  // acclient.c:756079
int _E142_9()
{
  PStringBase<char>::PStringBase<char>(&FragmentTopology_1, "FragmentTopology");
  return atexit(_E143_18);
}

//----- (006DECD0) --------------------------------------------------------  // acclient.c:756086
int _E145_8()
{
  PStringBase<char>::PStringBase<char>(&FragmentMOPP_1, "FragmentMOPP");
  return atexit(_E146_17);
}

//----- (006DECF0) --------------------------------------------------------  // acclient.c:756093
int _E148_8()
{
  PStringBase<char>::PStringBase<char>(&MaterialBatch_1, "MaterialBatch");
  return atexit(_E149_17);
}

//----- (006DED10) --------------------------------------------------------  // acclient.c:756100
int _E151_8()
{
  PStringBase<char>::PStringBase<char>(&FragmentBatch_1, "FragmentBatch");
  return atexit(_E152_16);
}

//----- (006DED30) --------------------------------------------------------  // acclient.c:756107
int _E154_9()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_1, "PrimitivesType");
  return atexit(_E155_14);
}

//----- (006DED50) --------------------------------------------------------  // acclient.c:756114
int _E157_8()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_PointList_1, "PointList");
  return atexit(_E158_17);
}

//----- (006DED70) --------------------------------------------------------  // acclient.c:756121
int _E160_9()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineList_1, "LineList");
  return atexit(_E161_14);
}

//----- (006DED90) --------------------------------------------------------  // acclient.c:756128
int _E163_7()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineStrip_1, "LineStrip");
  return atexit(_E164_17);
}

//----- (006DEDB0) --------------------------------------------------------  // acclient.c:756135
int _E166_8()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleList_1, "TriangleList");
  return atexit(_E167_13);
}

//----- (006DEDD0) --------------------------------------------------------  // acclient.c:756142
int _E169_6()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleStrip_1, "TriangleStrip");
  return atexit(_E170_12);
}

//----- (006DEDF0) --------------------------------------------------------  // acclient.c:756149
int _E172_6()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleFan_1, "TriangleFan");
  return atexit(_E173_11);
}

//----- (006DEE10) --------------------------------------------------------  // acclient.c:756156
int _E175_6()
{
  PStringBase<char>::PStringBase<char>(&Material_25, "Material");
  return atexit(_E176_12);
}

//----- (006DEE30) --------------------------------------------------------  // acclient.c:756163
int _E178_6()
{
  PStringBase<char>::PStringBase<char>(&Vertices_1, "Vertices");
  return atexit(_E179_11);
}

//----- (006DEE50) --------------------------------------------------------  // acclient.c:756170
int _E181_6()
{
  PStringBase<char>::PStringBase<char>(&Indices_9, "Indices");
  return atexit(_E182_11);
}

//----- (006DEE70) --------------------------------------------------------  // acclient.c:756177
int _E184_4()
{
  PStringBase<char>::PStringBase<char>(&ExportMeshAppearanceType_1, "MeshType");
  return atexit(_E185_8);
}

//----- (006DEE90) --------------------------------------------------------  // acclient.c:756184
int _E187_4()
{
  PStringBase<char>::PStringBase<char>(&MeshDegradeType_1, "MeshDegradeType");
  return atexit(_E188_9);
}

//----- (006DEEB0) --------------------------------------------------------  // acclient.c:756191
int _E190_4()
{
  PStringBase<char>::PStringBase<char>(&DegradeLevel_1, "DegLevel");
  return atexit(_E191_8);
}

//----- (006DEED0) --------------------------------------------------------  // acclient.c:756198
int _E193_4()
{
  PStringBase<char>::PStringBase<char>(&NumDegradeLevels_1, "NumDegrades");
  return atexit(_E194_15);
}

//----- (006DEEF0) --------------------------------------------------------  // acclient.c:756205
int _E196_6()
{
  PStringBase<char>::PStringBase<char>(&CellMesh_1, "CellMesh");
  return atexit(_E197_6);
}

//----- (006DEF10) --------------------------------------------------------  // acclient.c:756212
int _E199_4()
{
  PStringBase<char>::PStringBase<char>(&MaterialArray_1, "MaterialArray");
  return atexit(_E200_11);
}

//----- (006DEF30) --------------------------------------------------------  // acclient.c:756219
int _E202_4()
{
  PStringBase<char>::PStringBase<char>(&Render_1, "Render");
  return atexit(_E203_10);
}

//----- (006DEF50) --------------------------------------------------------  // acclient.c:756226
int _E205_5()
{
  PStringBase<char>::PStringBase<char>(&RenderMesh_1, "RenderMesh");
  return atexit(_E206_13);
}

//----- (006DEF70) --------------------------------------------------------  // acclient.c:756233
int _E208_6()
{
  PStringBase<char>::PStringBase<char>(&RenderMeshVersion_1, "RenderMeshVersioned");
  return atexit(_E209_8);
}

//----- (006DEF90) --------------------------------------------------------  // acclient.c:756240
int _E211_5()
{
  PStringBase<char>::PStringBase<char>(&Sphere_7, "Sphere");
  return atexit(_E212_11);
}

//----- (006DEFB0) --------------------------------------------------------  // acclient.c:756247
int _E214_5()
{
  PStringBase<char>::PStringBase<char>(&DetailedBSP_1, "DetailedBSP");
  return atexit(_E215_7);
}

//----- (006DEFD0) --------------------------------------------------------  // acclient.c:756254
int _E217_5()
{
  PStringBase<char>::PStringBase<char>(&PolygonArray_1, "PolygonArray");
  return atexit(_E218_8);
}

//----- (006DEFF0) --------------------------------------------------------  // acclient.c:756261
int _E220_5()
{
  PStringBase<char>::PStringBase<char>(&BinaryPolygonArray_1, "BinaryPolygonArray");
  return atexit(_E221_8);
}

//----- (006DF010) --------------------------------------------------------  // acclient.c:756268
int _E223_5()
{
  PStringBase<char>::PStringBase<char>(&Physics_1, "Physics");
  return atexit(_E224_8);
}

//----- (006DF030) --------------------------------------------------------  // acclient.c:756275
int _E226_5()
{
  PStringBase<char>::PStringBase<char>(&BSPTree_1, "BSPTree");
  return atexit(_E227_8);
}

//----- (006DF050) --------------------------------------------------------  // acclient.c:756282
int _E229_5()
{
  PStringBase<char>::PStringBase<char>(&BinaryBSPTree_1, "BinaryBSPTree");
  return atexit(_E230_8);
}

//----- (006DF070) --------------------------------------------------------  // acclient.c:756289
int _E232_5()
{
  PStringBase<char>::PStringBase<char>(&Cell_1, "Cell");
  return atexit(_E233_7);
}

//----- (006DF090) --------------------------------------------------------  // acclient.c:756296
int _E235_5()
{
  PStringBase<char>::PStringBase<char>(&CellBSP_1, "CellBSP");
  return atexit(_E236_7);
}

//----- (006DF0B0) --------------------------------------------------------  // acclient.c:756303
int _E238_5()
{
  PStringBase<char>::PStringBase<char>(&Portals_1, "Portals");
  return atexit(_E239_8);
}

//----- (006DF0D0) --------------------------------------------------------  // acclient.c:756310
int _E241_5()
{
  PStringBase<char>::PStringBase<char>(&Portal_7, "Portal");
  return atexit(_E242_8);
}

//----- (006DF0F0) --------------------------------------------------------  // acclient.c:756317
int _E244_5()
{
  PStringBase<char>::PStringBase<char>(&NonPortals_1, "NonPortals");
  return atexit(_E245_7);
}

//----- (006DF110) --------------------------------------------------------  // acclient.c:756324
int _E247_5()
{
  PStringBase<char>::PStringBase<char>(&NonPortal_1, "NonPortal");
  return atexit(_E248_7);
}

//----- (006DF130) --------------------------------------------------------  // acclient.c:756331
int _E250_5()
{
  PStringBase<char>::PStringBase<char>(&Info_1, "Info");
  return atexit(_E251_7);
}

//----- (006DF150) --------------------------------------------------------  // acclient.c:756338
int _E253_5()
{
  PStringBase<char>::PStringBase<char>(&CellVolumeInfo_1, "CellVolumeInfo");
  return atexit(_E254_8);
}

//----- (006DF170) --------------------------------------------------------  // acclient.c:756345
int _E256_5()
{
  PStringBase<char>::PStringBase<char>(&CellStructure_1, "CellStructure ");
  return atexit(_E257_6);
}

//----- (006DF190) --------------------------------------------------------  // acclient.c:756352
int _E259_5()
{
  PStringBase<char>::PStringBase<char>(&CellRotation_1, "Rotation");
  return atexit(_E260_7);
}

//----- (006DF1B0) --------------------------------------------------------  // acclient.c:756359
int _E262_5()
{
  PStringBase<char>::PStringBase<char>(&CellGridSize_1, "GridSize");
  return atexit(_E263_5);
}

//----- (006DF1D0) --------------------------------------------------------  // acclient.c:756366
int _E265_5()
{
  PStringBase<char>::PStringBase<char>(&CellNeverCull_1, "CellNeverCull");
  return atexit(_E266_5);
}

//----- (006DF1F0) --------------------------------------------------------  // acclient.c:756373
int _E268_5()
{
  PStringBase<char>::PStringBase<char>(&CellDrawSky_1, "CellDrawSky");
  return atexit(_E269_5);
}

//----- (006DF210) --------------------------------------------------------  // acclient.c:756380
int _E271_4()
{
  PStringBase<char>::PStringBase<char>(&DegradeArray_1, "Degrades");
  return atexit(_E272_4);
}

//----- (006DF230) --------------------------------------------------------  // acclient.c:756387
int _E274_4()
{
  PStringBase<char>::PStringBase<char>(&OccludeMeshArray_1, "OccludeMeshes");
  return atexit(_E275_4);
}

//----- (006DF250) --------------------------------------------------------  // acclient.c:756394
int _E277_4()
{
  PStringBase<char>::PStringBase<char>(&DegradeMesh_1, "DegradeMesh");
  return atexit(_E278_4);
}

//----- (006DF270) --------------------------------------------------------  // acclient.c:756401
int _E280_4()
{
  PStringBase<char>::PStringBase<char>(&BSP_1, "BSP");
  return atexit(_E281_5);
}

//----- (006DF290) --------------------------------------------------------  // acclient.c:756408
int _E283_4()
{
  PStringBase<char>::PStringBase<char>(&BumpMap_1, "BumpMap");
  return atexit(_E284_4);
}

//----- (006DF2B0) --------------------------------------------------------  // acclient.c:756415
int _E286_4()
{
  PStringBase<char>::PStringBase<char>(&UVSets_1, "UVSets");
  return atexit(_E287_5);
}

//----- (006DF2D0) --------------------------------------------------------  // acclient.c:756422
int _E289_4()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMesh_1, "PhysicsMesh");
  return atexit(_E290_5);
}

//----- (006DF2F0) --------------------------------------------------------  // acclient.c:756429
int _E292_4()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterials_1, "PhysicsMaterials");
  return atexit(_E293_4);
}

//----- (006DF310) --------------------------------------------------------  // acclient.c:756436
int _E295_4()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterialArray_1, "PhysicsMaterialArray");
  return atexit(_E296_5);
}

//----- (006DF330) --------------------------------------------------------  // acclient.c:756443
int _E298_4()
{
  PStringBase<char>::PStringBase<char>(&PathMapMeshArray_1, "PathMapMeshes");
  return atexit(_E299_3);
}

//----- (006DF350) --------------------------------------------------------  // acclient.c:756450
int _E301_3()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygonArray_1, "PathMapPolygonArray");
  return atexit(_E302_4);
}

//----- (006DF370) --------------------------------------------------------  // acclient.c:756457
int _E304_3()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygon_1, "PathMapPolygon");
  return atexit(_E305_3);
}

//----- (006DF390) --------------------------------------------------------  // acclient.c:756464
int _E307_3()
{
  PStringBase<char>::PStringBase<char>(&VertexSetArray_1, "VertexSetArray");
  return atexit(_E308_4);
}

//----- (006DF3B0) --------------------------------------------------------  // acclient.c:756471
int _E310_3()
{
  PStringBase<char>::PStringBase<char>(&VertexSets_1, "VertexSets");
  return atexit(_E311_3);
}

//----- (006DF3D0) --------------------------------------------------------  // acclient.c:756478
int _E313_3()
{
  PStringBase<char>::PStringBase<char>(&VertexSet_1, "VertexSet");
  return atexit(_E314_4);
}

//----- (006DF3F0) --------------------------------------------------------  // acclient.c:756485
int _E316_3()
{
  PStringBase<char>::PStringBase<char>(&Set_1, "Set");
  return atexit(_E317_3);
}

//----- (006DF410) --------------------------------------------------------  // acclient.c:756492
int _E319_3()
{
  PStringBase<char>::PStringBase<char>(&ID_13, "ID");
  return atexit(_E320_4);
}

//----- (006DF430) --------------------------------------------------------  // acclient.c:756499
int _E322_3()
{
  PStringBase<char>::PStringBase<char>(&Name_3, "Name");
  return atexit(_E323_3);
}

//----- (006DF450) --------------------------------------------------------  // acclient.c:756506
int _E325_3()
{
  PStringBase<char>::PStringBase<char>(&Indices_10, "Indices");
  return atexit(_E326_4);
}

//----- (006DF470) --------------------------------------------------------  // acclient.c:756513
int _E328_3()
{
  PStringBase<char>::PStringBase<char>(&MorphMeshArray_1, "MorphMeshArray");
  return atexit(_E329_3);
}

//----- (006DF490) --------------------------------------------------------  // acclient.c:756520
int _E331_3()
{
  PStringBase<char>::PStringBase<char>(&MorphMesh_1, "MorphMesh");
  return atexit(_E332_4);
}

//----- (006DF4B0) --------------------------------------------------------  // acclient.c:756527
int _E334_3()
{
  PStringBase<char>::PStringBase<char>(&MorphTargets_1, "MorphTargets");
  return atexit(_E335_3);
}

//----- (006DF4D0) --------------------------------------------------------  // acclient.c:756534
int _E337_3()
{
  PStringBase<char>::PStringBase<char>(&Target_1, "Target");
  return atexit(_E338_3);
}

//----- (006DF4F0) --------------------------------------------------------  // acclient.c:756541
int _E340_3()
{
  PStringBase<char>::PStringBase<char>(&Name_4, "Name");
  return atexit(_E341_3);
}

//----- (006DF510) --------------------------------------------------------  // acclient.c:756548
int _E1_44()
{
  return atexit(_E2_44);
}

//----- (0074BF60) --------------------------------------------------------  // acclient.c:866099
void __cdecl _E74_38()
{
  char *v0; // esi@1

  v0 = &waveform_None_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BF90) --------------------------------------------------------  // acclient.c:866112
void __cdecl _E77_52()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BFC0) --------------------------------------------------------  // acclient.c:866125
void __cdecl _E80_26()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074BFF0) --------------------------------------------------------  // acclient.c:866138
void __cdecl _E83_16()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C020) --------------------------------------------------------  // acclient.c:866151
void __cdecl _E86_13()
{
  char *v0; // esi@1

  v0 = &waveform_Square_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C050) --------------------------------------------------------  // acclient.c:866164
void __cdecl _E89_24()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C080) --------------------------------------------------------  // acclient.c:866177
void __cdecl _E92_26()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C0B0) --------------------------------------------------------  // acclient.c:866190
void __cdecl sub_74C0B0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C0E0) --------------------------------------------------------  // acclient.c:866203
void __cdecl _E98_41()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C110) --------------------------------------------------------  // acclient.c:866216
void __cdecl _E119_64()
{
  char *v0; // esi@1

  v0 = &PHeader_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C140) --------------------------------------------------------  // acclient.c:866229
void __cdecl _E122_51()
{
  char *v0; // esi@1

  v0 = &PreprocHeader_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PreprocHeader_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C170) --------------------------------------------------------  // acclient.c:866242
void __cdecl _E125_26()
{
  char *v0; // esi@1

  v0 = &MeshAppearanceType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshAppearanceType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C1A0) --------------------------------------------------------  // acclient.c:866255
void __cdecl _E128_27()
{
  char *v0; // esi@1

  v0 = &Fragment_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Fragment_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C1D0) --------------------------------------------------------  // acclient.c:866268
void __cdecl _E131_23()
{
  char *v0; // esi@1

  v0 = &FragmentType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C200) --------------------------------------------------------  // acclient.c:866281
void __cdecl _E134_22()
{
  char *v0; // esi@1

  v0 = &FragmentType_LevelOfDetailModel_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_LevelOfDetailModel_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C230) --------------------------------------------------------  // acclient.c:866294
void __cdecl _E137_22()
{
  char *v0; // esi@1

  v0 = &FragmentType_OccludeModel_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_OccludeModel_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C260) --------------------------------------------------------  // acclient.c:866307
void __cdecl _E140_17()
{
  char *v0; // esi@1

  v0 = &FragmentType_ShadowLODModel_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_ShadowLODModel_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C290) --------------------------------------------------------  // acclient.c:866320
void __cdecl _E143_18()
{
  char *v0; // esi@1

  v0 = &FragmentTopology_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentTopology_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C2C0) --------------------------------------------------------  // acclient.c:866333
void __cdecl _E146_17()
{
  char *v0; // esi@1

  v0 = &FragmentMOPP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentMOPP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C2F0) --------------------------------------------------------  // acclient.c:866346
void __cdecl _E149_17()
{
  char *v0; // esi@1

  v0 = &MaterialBatch_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialBatch_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C320) --------------------------------------------------------  // acclient.c:866359
void __cdecl _E152_16()
{
  char *v0; // esi@1

  v0 = &FragmentBatch_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentBatch_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C350) --------------------------------------------------------  // acclient.c:866372
void __cdecl _E155_14()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C380) --------------------------------------------------------  // acclient.c:866385
void __cdecl _E158_17()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_PointList_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_PointList_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C3B0) --------------------------------------------------------  // acclient.c:866398
void __cdecl _E161_14()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineList_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineList_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C3E0) --------------------------------------------------------  // acclient.c:866411
void __cdecl _E164_17()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineStrip_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineStrip_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C410) --------------------------------------------------------  // acclient.c:866424
void __cdecl _E167_13()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleList_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleList_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C440) --------------------------------------------------------  // acclient.c:866437
void __cdecl _E170_12()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleStrip_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleStrip_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C470) --------------------------------------------------------  // acclient.c:866450
void __cdecl _E173_11()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleFan_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleFan_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C4A0) --------------------------------------------------------  // acclient.c:866463
void __cdecl _E176_12()
{
  char *v0; // esi@1

  v0 = &Material_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C4D0) --------------------------------------------------------  // acclient.c:866476
void __cdecl _E179_11()
{
  char *v0; // esi@1

  v0 = &Vertices_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertices_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C500) --------------------------------------------------------  // acclient.c:866489
void __cdecl _E182_11()
{
  char *v0; // esi@1

  v0 = &Indices_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C530) --------------------------------------------------------  // acclient.c:866502
void __cdecl _E185_8()
{
  char *v0; // esi@1

  v0 = &ExportMeshAppearanceType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExportMeshAppearanceType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C560) --------------------------------------------------------  // acclient.c:866515
void __cdecl _E188_9()
{
  char *v0; // esi@1

  v0 = &MeshDegradeType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshDegradeType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C590) --------------------------------------------------------  // acclient.c:866528
void __cdecl _E191_8()
{
  char *v0; // esi@1

  v0 = &DegradeLevel_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeLevel_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C5C0) --------------------------------------------------------  // acclient.c:866541
void __cdecl _E194_15()
{
  char *v0; // esi@1

  v0 = &NumDegradeLevels_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumDegradeLevels_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C5F0) --------------------------------------------------------  // acclient.c:866554
void __cdecl _E197_6()
{
  char *v0; // esi@1

  v0 = &CellMesh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellMesh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C620) --------------------------------------------------------  // acclient.c:866567
void __cdecl _E200_11()
{
  char *v0; // esi@1

  v0 = &MaterialArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C650) --------------------------------------------------------  // acclient.c:866580
void __cdecl _E203_10()
{
  char *v0; // esi@1

  v0 = &Render_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C680) --------------------------------------------------------  // acclient.c:866593
void __cdecl _E206_13()
{
  char *v0; // esi@1

  v0 = &RenderMesh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMesh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C6B0) --------------------------------------------------------  // acclient.c:866606
void __cdecl _E209_8()
{
  char *v0; // esi@1

  v0 = &RenderMeshVersion_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMeshVersion_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C6E0) --------------------------------------------------------  // acclient.c:866619
void __cdecl _E212_11()
{
  char *v0; // esi@1

  v0 = &Sphere_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C710) --------------------------------------------------------  // acclient.c:866632
void __cdecl _E215_7()
{
  char *v0; // esi@1

  v0 = &DetailedBSP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailedBSP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C740) --------------------------------------------------------  // acclient.c:866645
void __cdecl _E218_8()
{
  char *v0; // esi@1

  v0 = &PolygonArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PolygonArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C770) --------------------------------------------------------  // acclient.c:866658
void __cdecl _E221_8()
{
  char *v0; // esi@1

  v0 = &BinaryPolygonArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryPolygonArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C7A0) --------------------------------------------------------  // acclient.c:866671
void __cdecl _E224_8()
{
  char *v0; // esi@1

  v0 = &Physics_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Physics_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C7D0) --------------------------------------------------------  // acclient.c:866684
void __cdecl _E227_8()
{
  char *v0; // esi@1

  v0 = &BSPTree_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSPTree_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C800) --------------------------------------------------------  // acclient.c:866697
void __cdecl _E230_8()
{
  char *v0; // esi@1

  v0 = &BinaryBSPTree_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryBSPTree_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C830) --------------------------------------------------------  // acclient.c:866710
void __cdecl _E233_7()
{
  char *v0; // esi@1

  v0 = &Cell_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Cell_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C860) --------------------------------------------------------  // acclient.c:866723
void __cdecl _E236_7()
{
  char *v0; // esi@1

  v0 = &CellBSP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellBSP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C890) --------------------------------------------------------  // acclient.c:866736
void __cdecl _E239_8()
{
  char *v0; // esi@1

  v0 = &Portals_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portals_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C8C0) --------------------------------------------------------  // acclient.c:866749
void __cdecl _E242_8()
{
  char *v0; // esi@1

  v0 = &Portal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C8F0) --------------------------------------------------------  // acclient.c:866762
void __cdecl _E245_7()
{
  char *v0; // esi@1

  v0 = &NonPortals_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortals_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C920) --------------------------------------------------------  // acclient.c:866775
void __cdecl _E248_7()
{
  char *v0; // esi@1

  v0 = &NonPortal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C950) --------------------------------------------------------  // acclient.c:866788
void __cdecl _E251_7()
{
  char *v0; // esi@1

  v0 = &Info_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Info_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C980) --------------------------------------------------------  // acclient.c:866801
void __cdecl _E254_8()
{
  char *v0; // esi@1

  v0 = &CellVolumeInfo_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellVolumeInfo_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C9B0) --------------------------------------------------------  // acclient.c:866814
void __cdecl _E257_6()
{
  char *v0; // esi@1

  v0 = &CellStructure_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellStructure_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074C9E0) --------------------------------------------------------  // acclient.c:866827
void __cdecl _E260_7()
{
  char *v0; // esi@1

  v0 = &CellRotation_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellRotation_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CA10) --------------------------------------------------------  // acclient.c:866840
void __cdecl _E263_5()
{
  char *v0; // esi@1

  v0 = &CellGridSize_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellGridSize_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CA40) --------------------------------------------------------  // acclient.c:866853
void __cdecl _E266_5()
{
  char *v0; // esi@1

  v0 = &CellNeverCull_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellNeverCull_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CA70) --------------------------------------------------------  // acclient.c:866866
void __cdecl _E269_5()
{
  char *v0; // esi@1

  v0 = &CellDrawSky_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellDrawSky_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CAA0) --------------------------------------------------------  // acclient.c:866879
void __cdecl _E272_4()
{
  char *v0; // esi@1

  v0 = &DegradeArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CAD0) --------------------------------------------------------  // acclient.c:866892
void __cdecl _E275_4()
{
  char *v0; // esi@1

  v0 = &OccludeMeshArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OccludeMeshArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CB00) --------------------------------------------------------  // acclient.c:866905
void __cdecl _E278_4()
{
  char *v0; // esi@1

  v0 = &DegradeMesh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeMesh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CB30) --------------------------------------------------------  // acclient.c:866918
void __cdecl _E281_5()
{
  char *v0; // esi@1

  v0 = &BSP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CB60) --------------------------------------------------------  // acclient.c:866931
void __cdecl _E284_4()
{
  char *v0; // esi@1

  v0 = &BumpMap_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BumpMap_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CB90) --------------------------------------------------------  // acclient.c:866944
void __cdecl _E287_5()
{
  char *v0; // esi@1

  v0 = &UVSets_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVSets_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CBC0) --------------------------------------------------------  // acclient.c:866957
void __cdecl _E290_5()
{
  char *v0; // esi@1

  v0 = &PhysicsMesh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMesh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CBF0) --------------------------------------------------------  // acclient.c:866970
void __cdecl _E293_4()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterials_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterials_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CC20) --------------------------------------------------------  // acclient.c:866983
void __cdecl _E296_5()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterialArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterialArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CC50) --------------------------------------------------------  // acclient.c:866996
void __cdecl _E299_3()
{
  char *v0; // esi@1

  v0 = &PathMapMeshArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapMeshArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CC80) --------------------------------------------------------  // acclient.c:867009
void __cdecl _E302_4()
{
  char *v0; // esi@1

  v0 = &PathMapPolygonArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygonArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CCB0) --------------------------------------------------------  // acclient.c:867022
void __cdecl _E305_3()
{
  char *v0; // esi@1

  v0 = &PathMapPolygon_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygon_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CCE0) --------------------------------------------------------  // acclient.c:867035
void __cdecl _E308_4()
{
  char *v0; // esi@1

  v0 = &VertexSetArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSetArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CD10) --------------------------------------------------------  // acclient.c:867048
void __cdecl _E311_3()
{
  char *v0; // esi@1

  v0 = &VertexSets_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSets_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CD40) --------------------------------------------------------  // acclient.c:867061
void __cdecl _E314_4()
{
  char *v0; // esi@1

  v0 = &VertexSet_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSet_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CD70) --------------------------------------------------------  // acclient.c:867074
void __cdecl _E317_3()
{
  char *v0; // esi@1

  v0 = &Set_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Set_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CDA0) --------------------------------------------------------  // acclient.c:867087
void __cdecl _E320_4()
{
  char *v0; // esi@1

  v0 = &ID_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CDD0) --------------------------------------------------------  // acclient.c:867100
void __cdecl _E323_3()
{
  char *v0; // esi@1

  v0 = &Name_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CE00) --------------------------------------------------------  // acclient.c:867113
void __cdecl _E326_4()
{
  char *v0; // esi@1

  v0 = &Indices_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CE30) --------------------------------------------------------  // acclient.c:867126
void __cdecl _E329_3()
{
  char *v0; // esi@1

  v0 = &MorphMeshArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMeshArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CE60) --------------------------------------------------------  // acclient.c:867139
void __cdecl _E332_4()
{
  char *v0; // esi@1

  v0 = &MorphMesh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMesh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CE90) --------------------------------------------------------  // acclient.c:867152
void __cdecl _E335_3()
{
  char *v0; // esi@1

  v0 = &MorphTargets_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphTargets_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CEC0) --------------------------------------------------------  // acclient.c:867165
void __cdecl _E338_3()
{
  char *v0; // esi@1

  v0 = &Target_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Target_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CEF0) --------------------------------------------------------  // acclient.c:867178
void __cdecl _E341_3()
{
  char *v0; // esi@1

  v0 = &Name_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

