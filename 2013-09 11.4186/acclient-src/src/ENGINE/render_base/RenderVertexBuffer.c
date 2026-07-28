/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderVertexBuffer
   Object     : ENGINE\render_base\RenderVertexBuffer.obj
   Functions  : 90
   Addresses  : 00447330 - 007312E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00447330) --------------------------------------------------------  // acclient.c:131640
void __thiscall RGBAColor::CapHigh(RGBAColor *this)
{
  if ( this->a > 1.0 )
    LODWORD(this->a) = 1065353216;
  if ( this->r > 1.0 )
    LODWORD(this->r) = 1065353216;
  if ( this->g > 1.0 )
    LODWORD(this->g) = 1065353216;
  if ( this->b > 1.0 )
    LODWORD(this->b) = 1065353216;
}

//----- (00447380) --------------------------------------------------------  // acclient.c:131653
void __thiscall RenderVertexBuffer::Begin(RenderVertexBuffer *this)
{
  this->m_UseVirtualArray = 0;
  this->m_pVirtualArray = 0;
  this->m_IsVirtualArrayLocked = 0;
  this->m_NeedRefreshVirtualArray = 1;
  qmemcpy(&this->m_VirtualArrayBoundingBox, &BBox::s_cZeroAABB, sizeof(this->m_VirtualArrayBoundingBox));
  this->m_IsVirtualArrayBoundingBoxValid = 0;
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (004473C0) --------------------------------------------------------  // acclient.c:131665
void __thiscall RenderVertexBuffer::End(RenderVertexBuffer *this)
{
  RenderVertexBuffer *v1; // esi@1

  v1 = this;
  if ( this->m_pVirtualArray )
  {
    operator delete[](this->m_pVirtualArray);
    v1->m_pVirtualArray = 0;
  }
}

//----- (004473F0) --------------------------------------------------------  // acclient.c:131678
char __thiscall RenderVertexBuffer::Startup(RenderVertexBuffer *this, const unsigned int _numVertices, const unsigned int _format, const bool _staticVertices, const bool _OnlyWriteOnce, const unsigned int _HardwareFormatMask)
{
  RenderVertexBuffer *v6; // ebp@1
  unsigned int v7; // edx@2
  bool v8; // bl@2
  int v9; // eax@2
  VertexFormatInfo *v10; // ecx@2
  void *v11; // eax@7
  char result; // al@8

  v6 = this;
  if ( !VertexArray::Startup(
          (VertexArray *)&this->vfptr,
          _numVertices,
          _format,
          _staticVertices,
          _OnlyWriteOnce,
          _HardwareFormatMask) )
    goto LABEL_12;
  v7 = v6->vertexFormat.format;
  v8 = v6->m_bStripHWExtraTexCoords;
  v6->m_UseVirtualArray = _staticVertices == 0;
  v9 = v7 & 0x52;
  v10 = &v6->m_HardwareVertexFormat;
  v6->m_HardwareVertexFormat.format = v9;
  if ( v8 )
  {
    if ( v6->vertexFormat.numTCPairs )
      v10->format = v9 | 0x100;
  }
  else
  {
    v10->format = v9 | v7 & 0xF00;
  }
  v10->format &= _HardwareFormatMask;
  VertexFormatInfo::GenerateOffsets(v10);
  if ( !v6->m_UseVirtualArray
    || (v11 = operator new[](v6->numVertices * v6->m_HardwareVertexFormat.size), (v6->m_pVirtualArray = v11) != 0) )
  {
    qmemcpy(&v6->m_VirtualArrayBoundingBox, &BBox::s_cZeroAABB, sizeof(v6->m_VirtualArrayBoundingBox));
    v6->m_IsVirtualArrayBoundingBoxValid = 0;
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (004474C0) --------------------------------------------------------  // acclient.c:131731
void __thiscall RenderVertexBuffer::Shutdown(RenderVertexBuffer *this)
{
  RenderVertexBuffer *v1; // ebp@1

  v1 = this;
  if ( this->m_pVirtualArray )
  {
    operator delete[](this->m_pVirtualArray);
    v1->m_pVirtualArray = 0;
  }
  VertexArray::Shutdown((VertexArray *)&v1->vfptr);
  v1->m_UseVirtualArray = 0;
  v1->m_pVirtualArray = 0;
  v1->m_IsVirtualArrayLocked = 0;
  v1->m_NeedRefreshVirtualArray = 1;
  qmemcpy(&v1->m_VirtualArrayBoundingBox, &BBox::s_cZeroAABB, sizeof(v1->m_VirtualArrayBoundingBox));
  v1->m_IsVirtualArrayBoundingBoxValid = 0;
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (00447520) --------------------------------------------------------  // acclient.c:131752
void __thiscall RenderVertexBuffer::UnlockVirtualArray(RenderVertexBuffer *this)
{
  if ( this->m_UseVirtualArray )
  {
    if ( this->m_IsVirtualArrayLocked )
      this->m_IsVirtualArrayLocked = 0;
  }
}

//----- (00447540) --------------------------------------------------------  // acclient.c:131762
void __thiscall RenderVertexBuffer::Unlock(RenderVertexBuffer *this, const bool _bRecalcBounds, const bool _bRecalcBoneInfluences)
{
  RenderVertexBuffer *v3; // esi@1

  v3 = this;
  VertexArray::Unlock((VertexArray *)&this->vfptr, _bRecalcBounds, _bRecalcBoneInfluences);
  if ( v3->m_UseVirtualArray )
    v3->m_NeedRefreshVirtualArray = 1;
}

//----- (00447570) --------------------------------------------------------  // acclient.c:131773
void __cdecl RenderVertexBuffer::TransferVertices(const void *_pSourceData, VertexFormatInfo *_SourceVFI, void *_pDestData, VertexFormatInfo *_DestVFI, const unsigned int _NumVertices, const bool _SwapYAndZ)
{
  VertexFormatInfo *v6; // ebp@1
  unsigned int v7; // edx@1
  VertexFormatInfo *v8; // edi@1
  unsigned int v9; // ecx@1
  unsigned int v10; // ebx@4
  unsigned int v11; // esi@6
  const void *v12; // ecx@26
  void *v13; // eax@26
  double v14; // st7@29
  double v15; // st6@29
  double v16; // st7@29
  signed int v17; // ebx@32
  int v18; // esi@32
  signed int v19; // edx@33
  int v20; // edi@34
  bool v21; // cf@34
  int v22; // edx@36
  unsigned int v23; // esi@39
  int v24; // ebx@39
  int v25; // esi@39
  int v26; // edx@39
  double v27; // st7@39
  double v28; // st6@39
  double v29; // st7@39
  int v30; // edx@40
  int v31; // esi@40
  int v32; // edx@49
  int v33; // esi@49
  int v34; // esi@51
  int v35; // edx@51
  bool v36; // zf@51
  unsigned int v37; // esi@54
  int v38; // ebx@54
  int v39; // esi@54
  int v40; // edx@54
  double v41; // st7@54
  double v42; // st6@54
  double v43; // st7@54
  int v44; // edx@55
  int v45; // esi@55
  unsigned int v46; // esi@58
  int v47; // ebx@58
  int v48; // esi@58
  int v49; // edx@58
  double v50; // st7@58
  double v51; // st6@58
  double v52; // st7@58
  int v53; // edx@59
  int v54; // esi@59
  bool WantCopyNormal; // [sp+Ch] [bp-20h]@9
  bool WantCopyPointSize; // [sp+Dh] [bp-1Fh]@12
  bool WantCopyDiffuse; // [sp+Eh] [bp-1Eh]@15
  bool WantCopySpecular; // [sp+Fh] [bp-1Dh]@18
  bool WantCopyVectorS; // [sp+10h] [bp-1Ch]@21
  bool WantCopyVectorT; // [sp+11h] [bp-1Bh]@24
  bool WantCopyWeights; // [sp+12h] [bp-1Ah]@8
  bool WantCopyTextureCoordinates; // [sp+13h] [bp-19h]@20
  signed int NumDestWeights; // [sp+14h] [bp-18h]@6
  unsigned int w; // [sp+18h] [bp-14h]@32
  unsigned int wa; // [sp+18h] [bp-14h]@49
  signed int v66; // [sp+1Ch] [bp-10h]@33
  int v67; // [sp+1Ch] [bp-10h]@49
  unsigned int NumDestTCPairs; // [sp+20h] [bp-Ch]@4
  const unsigned int v69; // [sp+24h] [bp-8h]@27

  v6 = _SourceVFI;
  v7 = _SourceVFI->format;
  v8 = _DestVFI;
  v9 = _DestVFI->format;
  if ( _SourceVFI->format != _DestVFI->format || _SwapYAndZ )
  {
    v10 = _DestVFI->numTCPairs;
    NumDestTCPairs = _DestVFI->numTCPairs;
    if ( _SourceVFI->numTCPairs < v10 )
    {
      v10 = _SourceVFI->numTCPairs;
      NumDestTCPairs = _SourceVFI->numTCPairs;
    }
    v11 = _DestVFI->numWeights;
    NumDestWeights = _DestVFI->numWeights;
    if ( _SourceVFI->numWeights < v11 )
    {
      v11 = _SourceVFI->numWeights;
      NumDestWeights = _SourceVFI->numWeights;
    }
    WantCopyWeights = v11 != 0;
    if ( !(v9 & 0x10) || (WantCopyNormal = 1, !(v7 & 0x10)) )
      WantCopyNormal = 0;
    if ( !(v9 & 0x20) || (WantCopyPointSize = 1, !(v7 & 0x20)) )
      WantCopyPointSize = 0;
    if ( !(v9 & 0x40) || (WantCopyDiffuse = 1, !(v7 & 0x40)) )
      WantCopyDiffuse = 0;
    if ( (v9 & 0x80u) == 0 || (WantCopySpecular = 1, (v7 & 0x80u) == 0) )
      WantCopySpecular = 0;
    WantCopyTextureCoordinates = v10 != 0;
    if ( !(v9 & 0x10000000) || (WantCopyVectorS = 1, !(v7 & 0x10000000)) )
      WantCopyVectorS = 0;
    if ( !(v9 & 0x20000000) || (WantCopyVectorT = 1, !(v7 & 0x20000000)) )
      WantCopyVectorT = 0;
    v12 = _pSourceData;
    v13 = _pDestData;
    if ( _NumVertices )
    {
      v69 = _NumVertices;
      do
      {
        if ( _SwapYAndZ )
        {
          *(_DWORD *)v13 = *(_DWORD *)v12;
          v14 = *((float *)v12 + 1);
          *((float *)v13 + 1) = *((float *)v12 + 1);
          v15 = v14;
          v16 = *((float *)v12 + 2);
          *((float *)v13 + 2) = v15;
          *((float *)v13 + 1) = v16;
        }
        else
        {
          *(_DWORD *)v13 = *(_DWORD *)v12;
          *((_DWORD *)v13 + 1) = *((_DWORD *)v12 + 1);
          *((_DWORD *)v13 + 2) = *((_DWORD *)v12 + 2);
        }
        if ( WantCopyWeights )
        {
          v17 = NumDestWeights;
          v18 = 0;
          w = 0;
          if ( NumDestWeights >= 4 )
          {
            v66 = 3;
            v19 = 8;
            do
            {
              *(_DWORD *)((char *)v13 + v19 + v8->offsetWeight0 - 8) = *(_DWORD *)((char *)v12
                                                                                 + v19
                                                                                 + v6->offsetWeight0
                                                                                 - 8);
              *(_DWORD *)((char *)v13 + v19 + _DestVFI->offsetWeight0 - 4) = *(_DWORD *)((char *)v12
                                                                                       + v19
                                                                                       + _SourceVFI->offsetWeight0
                                                                                       - 4);
              *(_DWORD *)((char *)v13 + v19 + _DestVFI->offsetWeight0) = *(_DWORD *)((char *)v12
                                                                                   + v19
                                                                                   + _SourceVFI->offsetWeight0);
              v17 = NumDestWeights;
              *(_DWORD *)((char *)v13 + v19 + _DestVFI->offsetWeight0 + 4) = *(_DWORD *)((char *)v12
                                                                                       + v19
                                                                                       + _SourceVFI->offsetWeight0
                                                                                       + 4);
              v6 = _SourceVFI;
              v20 = v66 + 4;
              v18 = w + 4;
              v19 += 16;
              v66 = v20;
              v21 = v20 < (unsigned int)NumDestWeights;
              v8 = _DestVFI;
              w += 4;
            }
            while ( v21 );
          }
          if ( v18 < (unsigned int)v17 )
          {
            do
            {
              v22 = *(_DWORD *)((char *)v12 + 4 * v18 + v6->offsetWeight0);
              v6 = _SourceVFI;
              *(_DWORD *)((char *)v13 + 4 * v18 + v8->offsetWeight0) = v22;
              v8 = _DestVFI;
              ++v18;
            }
            while ( v18 < (unsigned int)NumDestWeights );
          }
        }
        if ( WantCopyNormal )
        {
          if ( _SwapYAndZ )
          {
            v23 = v6->offsetNormal;
            v24 = *(_DWORD *)((char *)v12 + v23);
            v25 = (int)((char *)v12 + v23);
            v26 = (int)((char *)v13 + v8->offsetNormal);
            *(_DWORD *)v26 = v24;
            v27 = *(float *)(v25 + 4);
            *(float *)(v26 + 4) = *(float *)(v25 + 4);
            v28 = v27;
            v29 = *(float *)(v25 + 8);
            *(float *)(v26 + 8) = v28;
            *(float *)(v26 + 4) = v29;
          }
          else
          {
            v30 = (int)((char *)v12 + v6->offsetNormal);
            v31 = (int)((char *)v13 + v8->offsetNormal);
            *(_DWORD *)v31 = *(_DWORD *)v30;
            *(_DWORD *)(v31 + 4) = *(_DWORD *)(v30 + 4);
            *(_DWORD *)(v31 + 8) = *(_DWORD *)(v30 + 8);
          }
        }
        if ( WantCopyPointSize )
          *(_DWORD *)((char *)v13 + v8->offsetPointSize) = *(_DWORD *)((char *)v12 + v6->offsetPointSize);
        if ( WantCopyDiffuse )
          *(_DWORD *)((char *)v13 + v8->offsetDiffuse) = *(_DWORD *)((char *)v12 + v6->offsetDiffuse);
        if ( WantCopySpecular )
          *(_DWORD *)((char *)v13 + v8->offsetSpecular) = *(_DWORD *)((char *)v12 + v6->offsetSpecular);
        if ( WantCopyTextureCoordinates && NumDestTCPairs )
        {
          v32 = (int)v8->offsetTCPair;
          v33 = (char *)v6 - (char *)v8;
          v67 = (int)v8->offsetTCPair;
          wa = NumDestTCPairs;
          while ( 1 )
          {
            v34 = *(_DWORD *)(v33 + v32);
            v35 = *(_DWORD *)v32;
            *(_DWORD *)((char *)v13 + v35) = *(_DWORD *)((char *)v12 + v34);
            *(_DWORD *)((char *)v13 + v35 + 4) = *(_DWORD *)((char *)v12 + v34 + 4);
            v32 = v67 + 4;
            v36 = wa == 1;
            v67 += 4;
            --wa;
            if ( v36 )
              break;
            v33 = (char *)v6 - (char *)v8;
          }
        }
        if ( WantCopyVectorS )
        {
          if ( _SwapYAndZ )
          {
            v37 = v6->offsetVectorS;
            v38 = *(_DWORD *)((char *)v12 + v37);
            v39 = (int)((char *)v12 + v37);
            v40 = (int)((char *)v13 + v8->offsetVectorS);
            *(_DWORD *)v40 = v38;
            v41 = *(float *)(v39 + 4);
            *(float *)(v40 + 4) = *(float *)(v39 + 4);
            v42 = v41;
            v43 = *(float *)(v39 + 8);
            *(float *)(v40 + 8) = v42;
            *(float *)(v40 + 4) = v43;
          }
          else
          {
            v44 = (int)((char *)v12 + v6->offsetVectorS);
            v45 = (int)((char *)v13 + v8->offsetVectorS);
            *(_DWORD *)v45 = *(_DWORD *)v44;
            *(_DWORD *)(v45 + 4) = *(_DWORD *)(v44 + 4);
            *(_DWORD *)(v45 + 8) = *(_DWORD *)(v44 + 8);
          }
        }
        if ( WantCopyVectorT )
        {
          if ( _SwapYAndZ )
          {
            v46 = v6->offsetVectorT;
            v47 = *(_DWORD *)((char *)v12 + v46);
            v48 = (int)((char *)v12 + v46);
            v49 = (int)((char *)v13 + v8->offsetVectorT);
            *(_DWORD *)v49 = v47;
            v50 = *(float *)(v48 + 4);
            *(float *)(v49 + 4) = *(float *)(v48 + 4);
            v51 = v50;
            v52 = *(float *)(v48 + 8);
            *(float *)(v49 + 8) = v51;
            *(float *)(v49 + 4) = v52;
          }
          else
          {
            v53 = (int)((char *)v12 + v6->offsetVectorT);
            v54 = (int)((char *)v13 + v8->offsetVectorT);
            *(_DWORD *)v54 = *(_DWORD *)v53;
            *(_DWORD *)(v54 + 4) = *(_DWORD *)(v53 + 4);
            *(_DWORD *)(v54 + 8) = *(_DWORD *)(v53 + 8);
          }
        }
        v12 = (char *)v12 + v6->size;
        v13 = (char *)v13 + v8->size;
        --v69;
      }
      while ( v69 );
    }
  }
  else
  {
    qmemcpy(_pDestData, _pSourceData, _NumVertices * _DestVFI->size);
  }
}

//----- (00447940) --------------------------------------------------------  // acclient.c:132064
bool __thiscall RenderVertexBuffer::RenderIndexedUsingMaterial(RenderVertexBuffer *this, PrimType _PrimType, const unsigned int _nFirstIndex, const unsigned int _nNumPrimitives, const unsigned int _nFirstVertexIndex, const unsigned int _nNumVertexIndices, const unsigned int _nVertexOffset, RenderIndexBuffer *_IndexBuffer, RenderMaterial *_ReferenceMaterial, RenderMaterial *_Material, RenderPassType _RenderPass, RGBAColor *_cColor, RGBAColor *_AmbientLightBoost, const bool _ForceTranslucent, int _bForceBlend, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex, int _UseBaseVertexIndex)
{
  RenderVertexBuffer *v18; // esi@1
  RenderMaterial *v19; // edx@2
  unsigned __int8 v20; // al@5
  int v21; // ecx@6
  MaterialLayer *v22; // edx@6
  bool result; // al@10
  bool WasDrawn; // [sp+2Dh] [bp-5h]@3
  unsigned int TableIndex; // [sp+2Eh] [bp-4h]@3

  v18 = this;
  if ( _cColor->a == 0.0 || (v19 = _Material, _Material->m_Opacity == 0.0) )
  {
    result = 0;
  }
  else
  {
    WasDrawn = 0;
    TableIndex = 0;
    while ( 1 )
    {
      v20 = *((_BYTE *)&v19->properties.vfptr
            + 8 * _RenderPass
            + 2 * (SceneTool::m_CachedMaterialConditions + 8 * _RenderPass + 56)
            + TableIndex
            + SceneTool::m_CachedMaterialConditions);
      if ( v20 == -1 )
        break;
      v21 = v20;
      v22 = v19->layers.m_data[v21];
      if ( v22->m_cDiffuse.a == 0.0 )
        break;
      RenderDeviceD3D::SetupState(
        (RenderDeviceD3D *)RenderDevice::render_device,
        _ReferenceMaterial->layers.m_data[v21],
        v22,
        v18->m_HardwareVertexFormat.format,
        _cColor,
        _AmbientLightBoost,
        _ForceTranslucent);
      if ( (unsigned __int8)((int (__thiscall *)(RenderVertexBuffer *, PrimType, const unsigned int, const unsigned int, const unsigned int, const unsigned int, const unsigned int, RenderIndexBuffer *, int, unsigned int *, unsigned int *, int))v18->vfptr[5].__vecDelDtor)(
                              v18,
                              _PrimType,
                              _nFirstIndex,
                              _nNumPrimitives,
                              _nFirstVertexIndex,
                              _nNumVertexIndices,
                              _nVertexOffset,
                              _IndexBuffer,
                              _bForceBlend,
                              _pnStreamFrameID,
                              _pnBaseVertexIndex,
                              _UseBaseVertexIndex) )
        WasDrawn = 1;
      ++TableIndex;
      if ( TableIndex >= 3 )
        break;
      v19 = _Material;
    }
    result = WasDrawn;
  }
  return result;
}
// 795344: using guessed type float FLOAT_0_0;
// 83741C: using guessed type unsigned __int32 SceneTool::m_CachedMaterialConditions;

//----- (00447A80) --------------------------------------------------------  // acclient.c:132132
bool __thiscall RenderVertexBuffer::RenderUsingMaterial(RenderVertexBuffer *this, PrimType _PrimType, const unsigned int _nFirstVertex, const unsigned int _nNumPrimitives, RenderMaterial *_ReferenceMaterial, RenderMaterial *_Material, RenderPassType _RenderPass, RGBAColor *_cColor, RGBAColor *_AmbientLightBoost, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex)
{
  RenderVertexBuffer *v11; // esi@1
  RenderMaterial *v12; // edx@2
  unsigned __int8 v13; // al@5
  int v14; // ecx@6
  MaterialLayer *v15; // edx@6
  bool result; // al@10
  bool WasDrawn; // [sp+15h] [bp-5h]@3
  unsigned int TableIndex; // [sp+16h] [bp-4h]@3

  v11 = this;
  if ( _cColor->a == 0.0 || (v12 = _Material, _Material->m_Opacity == 0.0) )
  {
    result = 0;
  }
  else
  {
    WasDrawn = 0;
    TableIndex = 0;
    while ( 1 )
    {
      v13 = *((_BYTE *)&v12->properties.vfptr
            + 8 * _RenderPass
            + 2 * (SceneTool::m_CachedMaterialConditions + 8 * _RenderPass + 56)
            + TableIndex
            + SceneTool::m_CachedMaterialConditions);
      if ( v13 == -1 )
        break;
      v14 = v13;
      v15 = v12->layers.m_data[v14];
      if ( v15->m_cDiffuse.a == 0.0 )
        break;
      RenderDeviceD3D::SetupState(
        (RenderDeviceD3D *)RenderDevice::render_device,
        _ReferenceMaterial->layers.m_data[v14],
        v15,
        v11->m_HardwareVertexFormat.format,
        _cColor,
        _AmbientLightBoost,
        0);
      if ( (unsigned __int8)((int (__thiscall *)(RenderVertexBuffer *, PrimType, const unsigned int, const unsigned int, unsigned int *, unsigned int *))v11->vfptr[6].__vecDelDtor)(
                              v11,
                              _PrimType,
                              _nFirstVertex,
                              _nNumPrimitives,
                              _pnStreamFrameID,
                              _pnBaseVertexIndex) )
        WasDrawn = 1;
      ++TableIndex;
      if ( TableIndex >= 3 )
        break;
      v12 = _Material;
    }
    result = WasDrawn;
  }
  return result;
}
// 83741C: using guessed type unsigned __int32 SceneTool::m_CachedMaterialConditions;

//----- (00447B90) --------------------------------------------------------  // acclient.c:132193
void __thiscall VertexArray::~VertexArray(VertexArray *this)
{
  VertexArray *v1; // esi@1

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VertexArray::vftable;
  VertexArray::End(this);
  if ( (v1->m_InfluencedBoneIndexArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_InfluencedBoneIndexArray.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 79AFE8: using guessed type int (__thiscall *VertexArray::vftable)(void *, char);

//----- (00447BD0) --------------------------------------------------------  // acclient.c:132208
VertexArray *__thiscall VertexArray::vector_deleting_destructor(VertexArray *this, unsigned int a2)
{
  VertexArray *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VertexArray::vftable;
  VertexArray::End(this);
  if ( (v2->m_InfluencedBoneIndexArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_InfluencedBoneIndexArray.m_data);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 79AFE8: using guessed type int (__thiscall *VertexArray::vftable)(void *, char);

//----- (00447C20) --------------------------------------------------------  // acclient.c:132226
void __thiscall RenderVertexBuffer::RenderVertexBuffer(RenderVertexBuffer *this)
{
  RenderVertexBuffer *v1; // ebp@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VertexArray::vftable;
  this->m_InfluencedBoneIndexArray.m_data = 0;
  this->m_InfluencedBoneIndexArray.m_sizeAndDeallocate = 0;
  this->m_InfluencedBoneIndexArray.m_num = 0;
  VertexArray::Begin((VertexArray *)&this->vfptr);
  v1->m_UseVirtualArray = 0;
  v1->m_pVirtualArray = 0;
  v1->m_IsVirtualArrayLocked = 0;
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBuffer::vftable;
  v1->m_NeedRefreshVirtualArray = 1;
  qmemcpy(&v1->m_VirtualArrayBoundingBox, &BBox::s_cZeroAABB, sizeof(v1->m_VirtualArrayBoundingBox));
  v1->m_IsVirtualArrayBoundingBoxValid = 0;
}
// 79AFE8: using guessed type int (__thiscall *VertexArray::vftable)(void *, char);
// 79AFFC: using guessed type int (__thiscall *RenderVertexBuffer::vftable)(void *, char);
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (00447C90) --------------------------------------------------------  // acclient.c:132250
bool __stdcall RenderVertexBuffer::RenderIndexedPrimitives(PrimType _PrimType, const unsigned int _nFirstIndex, const unsigned int _nNumPrimitives, const unsigned int _nFirstVertexIndex, const unsigned int _nNumVertexIndices, const unsigned int _nVertexOffset, RenderIndexBuffer *_IndexBuffer, const bool _bForceBlend, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex, const bool _bUseBaseVertexIndex)
{
  return 0;
}

//----- (00447CA0) --------------------------------------------------------  // acclient.c:132256
bool __stdcall RenderVertexBuffer::RenderPrimitives(PrimType _PrimType, const unsigned int _nFirstVertex, const unsigned int _nNumPrimitives, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex)
{
  return 0;
}

//----- (00447CB0) --------------------------------------------------------  // acclient.c:132262
VertexArray *__thiscall RenderVertexBuffer::scalar_deleting_destructor(RenderVertexBuffer *this, unsigned int a2)
{
  VertexArray *v2; // esi@1

  v2 = (VertexArray *)this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBuffer::vftable;
  RenderVertexBuffer::End(this);
  VertexArray::~VertexArray(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79AFFC: using guessed type int (__thiscall *RenderVertexBuffer::vftable)(void *, char);

//----- (00447CE0) --------------------------------------------------------  // acclient.c:132277
void __cdecl RenderVertexBuffer::AllocateVertexBuffer()
{
  RenderVertexBuffer *v0; // eax@3

  if ( Render::m_pRenderer )
  {
    ((void (*)(void))RenderDevice::render_device->vfptr->CreateVertexBuffer)();
  }
  else
  {
    v0 = (RenderVertexBuffer *)operator new(0x14Cu);
    if ( v0 )
      RenderVertexBuffer::RenderVertexBuffer(v0);
  }
}

//----- (00447D10) --------------------------------------------------------  // acclient.c:132294
void __thiscall RenderVertexBuffer::RefreshVirtualArray(RenderVertexBuffer *this)
{
  RenderVertexBuffer *v1; // ebx@1

  v1 = this;
  if ( this->m_UseVirtualArray )
  {
    if ( this->m_NeedRefreshVirtualArray )
    {
      RenderVertexBuffer::TransferVertices(
        this->vertices,
        &this->vertexFormat,
        this->m_pVirtualArray,
        &this->m_HardwareVertexFormat,
        this->numVertices,
        this->m_IsYAndZSwapped == 0);
      qmemcpy(&v1->m_VirtualArrayBoundingBox, &v1->m_BoundingBox, sizeof(v1->m_VirtualArrayBoundingBox));
      v1->m_IsVirtualArrayBoundingBoxValid = 1;
      v1->m_NeedRefreshVirtualArray = 0;
    }
  }
}

//----- (00447D80) --------------------------------------------------------  // acclient.c:132318
unsigned int __thiscall RenderVertexBuffer::LockVirtualArray(RenderVertexBuffer *this, const unsigned int firstVertex, const unsigned int numVerts)
{
  RenderVertexBuffer *v3; // esi@1
  bool v4; // al@3
  const unsigned int result; // eax@5
  VertexRange vrDirty; // [sp+8h] [bp-8h]@3

  v3 = this;
  if ( !this->m_UseVirtualArray
    || (RenderVertexBuffer::RefreshVirtualArray(this), v3->m_IsVirtualArrayLocked)
    || (vrDirty.m_nNumVertices = numVerts,
        v4 = v3->staticVertices,
        v3->m_IsVirtualArrayLocked = 1,
        vrDirty.m_nFirstVertex = firstVertex,
        v4)
    && !(unsigned __int8)v3->vfptr[9].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v3, (unsigned int)&vrDirty) )
    result = 0;
  else
    result = (const unsigned int)((char *)v3->m_pVirtualArray + firstVertex * v3->m_HardwareVertexFormat.size);
  return result;
}

//----- (006CBE10) --------------------------------------------------------  // acclient.c:739363
int _E73_39()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_12, "None");
  return atexit(_E74_33);
}

//----- (006CBE30) --------------------------------------------------------  // acclient.c:739370
int _E76_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_12, "Speed");
  return atexit(_E77_48);
}

//----- (006CBE50) --------------------------------------------------------  // acclient.c:739377
int _E79_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_12, "Noise");
  return atexit(_E80_22);
}

//----- (006CBE70) --------------------------------------------------------  // acclient.c:739384
int _E82_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_12, "Sine");
  return atexit(_E83_12);
}

//----- (006CBE90) --------------------------------------------------------  // acclient.c:739391
int _E85_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_12, "Square");
  return atexit(_E86_9);
}

//----- (006CBEB0) --------------------------------------------------------  // acclient.c:739398
int _E88_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_12, "Bounce");
  return atexit(_E89_20);
}

//----- (006CBED0) --------------------------------------------------------  // acclient.c:739405
int _E91_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_12, "Perlin");
  return atexit(_E92_20);
}

//----- (006CBEF0) --------------------------------------------------------  // acclient.c:739412
int _E94_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_12, "Fractal");
  return atexit(sub_730E40);
}

//----- (006CBF10) --------------------------------------------------------  // acclient.c:739419
int _E97_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_12, "FrameLoop");
  return atexit(_E98_35);
}

//----- (006CBF30) --------------------------------------------------------  // acclient.c:739426
void _E100_14()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_14, PFID_A8R8G8B8);
}

//----- (006CBF40) --------------------------------------------------------  // acclient.c:739432
void _E118_9()
{
  LODWORD(dword_838948) = 1053364187;
}

//----- (006CBF50) --------------------------------------------------------  // acclient.c:739438
void _E120_3()
{
  outside_val_11 = 1000.0 + 1.0;
}

//----- (006CBF70) --------------------------------------------------------  // acclient.c:739444
void _E122_1()
{
  block_length_11 = 24.0 * 8.0;
}

//----- (006CBF90) --------------------------------------------------------  // acclient.c:739450
void _E124_9()
{
  half_square_length_11 = 24.0 * 0.5;
}

//----- (006CBFB0) --------------------------------------------------------  // acclient.c:739456
int _E126_4()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_6, "Render.TextureFiltering");
  return atexit(_E127_85);
}

//----- (006CBFD0) --------------------------------------------------------  // acclient.c:739463
int _E129_3()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_6, "Render.LandscapeDetailTextures");
  return atexit(_E130_77);
}

//----- (006CBFF0) --------------------------------------------------------  // acclient.c:739470
int _E132_4()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_6, "Render.BuildingDetailTextures");
  return atexit(_E133_70);
}

//----- (006CC010) --------------------------------------------------------  // acclient.c:739477
int _E135_3()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_6, "Render.FieldOfView");
  return atexit(_E136_54);
}

//----- (006CC030) --------------------------------------------------------  // acclient.c:739484
int _E138_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_6, "Render.LandscapeTextureDetail");
  return atexit(_E139_55);
}

//----- (006CC050) --------------------------------------------------------  // acclient.c:739491
int _E141_4()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_6, "Render.EnvironmentTextureDetail");
  return atexit(_E142_52);
}

//----- (006CC070) --------------------------------------------------------  // acclient.c:739498
int _E144_4()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_6, "Render.SceneryDrawDistance");
  return atexit(_E145_54);
}

//----- (006CC090) --------------------------------------------------------  // acclient.c:739505
int _E147_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_6, "Render.LandscapeDrawDistance");
  return atexit(_E148_53);
}

//----- (006CC0B0) --------------------------------------------------------  // acclient.c:739512
int _E150_4()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_6, "Render.ScreenBrightness");
  return atexit(_E151_51);
}

//----- (006CC0D0) --------------------------------------------------------  // acclient.c:739519
int _E153_4()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_6, "Render.AspectRatio");
  return atexit(_E154_52);
}

//----- (006CC0F0) --------------------------------------------------------  // acclient.c:739526
int _E156_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_6, "Render.DisplayAdapter");
  return atexit(_E157_49);
}

//----- (006CC110) --------------------------------------------------------  // acclient.c:739533
int _E159_4()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_6, "Render.MaxHardwareClass");
  return atexit(_E160_52);
}

//----- (006CC130) --------------------------------------------------------  // acclient.c:739540
int _E162_5()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_6, "Render.AutomaticDegrades");
  return atexit(_E163_45);
}

//----- (006CC150) --------------------------------------------------------  // acclient.c:739547
int _E165_4()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_6, "Render.GraphicsPerformance");
  return atexit(_E166_47);
}

//----- (006CC170) --------------------------------------------------------  // acclient.c:739554
int _E168_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_6, "Render.DegradeDistance");
  return atexit(_E169_46);
}

//----- (006CC190) --------------------------------------------------------  // acclient.c:739561
int _E171_5()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_6, "Render.MultiPassAlpha");
  return atexit(_E172_44);
}

//----- (006CC1B0) --------------------------------------------------------  // acclient.c:739568
int _E174_5()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_6, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8389A0, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8389A4, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8389A8, "Anisotropic");
  return atexit(_E175_41);
}

//----- (006CC200) --------------------------------------------------------  // acclient.c:739578
int _E177_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_6, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8389B0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8389B4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8389B8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8389BC, "VeryHigh");
  return atexit(_E178_41);
}

//----- (006CC260) --------------------------------------------------------  // acclient.c:739589
int _E180_5()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_6, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8389C4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8389C8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8389CC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8389D0, "VeryHigh");
  return atexit(_E181_41);
}

//----- (006CC2C0) --------------------------------------------------------  // acclient.c:739600
int _E183_5()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_6, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8389D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8389DC, "High");
  return atexit(_E184_39);
}

//----- (006CC300) --------------------------------------------------------  // acclient.c:739609
int _E186_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_6, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8389E4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8389E8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8389EC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8389F0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8389F4, "Extreme");
  return atexit(_E187_38);
}

//----- (006CC370) --------------------------------------------------------  // acclient.c:739621
int _E189_5()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_6, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8389FC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_838A00, "Wide");
  return atexit(_E190_39);
}

//----- (006CC3B0) --------------------------------------------------------  // acclient.c:739630
void _E192_4()
{
  DEFAULT_VIEW_RADIUS_4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006CC3D0) --------------------------------------------------------  // acclient.c:739636
void _E194_0()
{
  MIN_QUANTUM_4 = 1.0 / 30.0;
}

//----- (006CC3F0) --------------------------------------------------------  // acclient.c:739642
void _E196_1()
{
  MAX_QUANTUM_4 = 1.0 / 5.0;
}

//----- (006CC410) --------------------------------------------------------  // acclient.c:739648
int _E1_35()
{
  return atexit(_E2_35);
}

//----- (00730CF0) --------------------------------------------------------  // acclient.c:835748
void __cdecl _E74_33()
{
  char *v0; // esi@1

  v0 = &waveform_None_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730D20) --------------------------------------------------------  // acclient.c:835761
void __cdecl _E77_48()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730D50) --------------------------------------------------------  // acclient.c:835774
void __cdecl _E80_22()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730D80) --------------------------------------------------------  // acclient.c:835787
void __cdecl _E83_12()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730DB0) --------------------------------------------------------  // acclient.c:835800
void __cdecl _E86_9()
{
  char *v0; // esi@1

  v0 = &waveform_Square_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730DE0) --------------------------------------------------------  // acclient.c:835813
void __cdecl _E89_20()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730E10) --------------------------------------------------------  // acclient.c:835826
void __cdecl _E92_20()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730E40) --------------------------------------------------------  // acclient.c:835839
void __cdecl sub_730E40()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730E70) --------------------------------------------------------  // acclient.c:835852
void __cdecl _E98_35()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730EA0) --------------------------------------------------------  // acclient.c:835865
void __cdecl _E127_85()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730ED0) --------------------------------------------------------  // acclient.c:835878
void __cdecl _E130_77()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730F00) --------------------------------------------------------  // acclient.c:835891
void __cdecl _E133_70()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730F30) --------------------------------------------------------  // acclient.c:835904
void __cdecl _E136_54()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730F60) --------------------------------------------------------  // acclient.c:835917
void __cdecl _E139_55()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730F90) --------------------------------------------------------  // acclient.c:835930
void __cdecl _E142_52()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730FC0) --------------------------------------------------------  // acclient.c:835943
void __cdecl _E145_54()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730FF0) --------------------------------------------------------  // acclient.c:835956
void __cdecl _E148_53()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731020) --------------------------------------------------------  // acclient.c:835969
void __cdecl _E151_51()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731050) --------------------------------------------------------  // acclient.c:835982
void __cdecl _E154_52()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731080) --------------------------------------------------------  // acclient.c:835995
void __cdecl _E157_49()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007310B0) --------------------------------------------------------  // acclient.c:836008
void __cdecl _E160_52()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007310E0) --------------------------------------------------------  // acclient.c:836021
void __cdecl _E163_45()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731110) --------------------------------------------------------  // acclient.c:836034
void __cdecl _E166_47()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731140) --------------------------------------------------------  // acclient.c:836047
void __cdecl _E169_46()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731170) --------------------------------------------------------  // acclient.c:836060
void __cdecl _E172_44()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007311A0) --------------------------------------------------------  // acclient.c:836073
void __cdecl _E175_41()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_6;
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

//----- (007311E0) --------------------------------------------------------  // acclient.c:836098
void __cdecl _E178_41()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_6;
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

//----- (00731220) --------------------------------------------------------  // acclient.c:836123
void __cdecl _E181_41()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_6;
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

//----- (00731260) --------------------------------------------------------  // acclient.c:836148
void __cdecl _E184_39()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_6;
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

//----- (007312A0) --------------------------------------------------------  // acclient.c:836173
void __cdecl _E187_38()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_6;
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

//----- (007312E0) --------------------------------------------------------  // acclient.c:836198
void __cdecl _E190_39()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &DEFAULT_VIEW_RADIUS_4;
  v1 = 3;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

