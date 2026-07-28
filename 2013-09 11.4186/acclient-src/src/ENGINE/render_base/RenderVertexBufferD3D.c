/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderVertexBufferD3D
   Object     : ENGINE\render_base\RenderVertexBufferD3D.obj
   Functions  : 80
   Addresses  : 00698180 - 00786630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00698180) --------------------------------------------------------  // acclient.c:688010
int __thiscall RenderVertexBufferD3D::Lock(RenderVertexBufferD3D *this, const unsigned int firstVertex, const unsigned int numVerts)
{
  RenderVertexBufferD3D *v3; // esi@1
  int v4; // edi@1
  ReferenceCountTemplate<1048576,1>Vtbl *v5; // eax@3
  VertexRange vrDirty; // [sp+10h] [bp-8h]@3

  v3 = this;
  v4 = VertexArray::Lock((VertexArray *)&this->vfptr, firstVertex, numVerts);
  if ( v4 && v3->staticVertices )
  {
    v5 = v3->vfptr;
    vrDirty.m_nFirstVertex = firstVertex;
    vrDirty.m_nNumVertices = numVerts;
    v5[9].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v3, (unsigned int)&vrDirty);
  }
  return v4;
}

//----- (006981D0) --------------------------------------------------------  // acclient.c:688030
char __thiscall SmartArray<VertexRange,1>::RemoveUnOrderedByIndex(SmartArray<VertexRange,1> *this, unsigned int index)
{
  unsigned int v2; // eax@1
  int v3; // edx@2
  VertexRange *v4; // eax@3
  unsigned int v5; // eax@3
  VertexRange *v6; // ecx@3
  char result; // al@4
  unsigned int v8; // [sp+4h] [bp-8h]@0
  unsigned int v9; // [sp+8h] [bp-4h]@0

  v2 = this->m_num;
  if ( index >= v2 )
  {
    result = 0;
  }
  else
  {
    v3 = v2 - 1;
    this->m_num = v2 - 1;
    if ( index != v2 - 1 )
    {
      v4 = this->m_data;
      v4[index].m_nFirstVertex = v4[v3].m_nFirstVertex;
      v4[index].m_nNumVertices = v4[v3].m_nNumVertices;
      v5 = this->m_num;
      v6 = this->m_data;
      v6[v5].m_nFirstVertex = v8;
      v6[v5].m_nNumVertices = v9;
    }
    result = 1;
  }
  return result;
}

//----- (00698230) --------------------------------------------------------  // acclient.c:688066
void __thiscall RenderVertexBufferD3D::SetupVertexStreams(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // edi@1
  const unsigned int v2; // esi@1

  v1 = this;
  v2 = 0;
  if ( this->m_saVertexStreams.m_num )
  {
    do
    {
      RenderDeviceD3D::SetVertexStream(
        (RenderDeviceD3D *)RenderDevice::render_device,
        v2,
        v1->m_saVertexStreams.m_data[v2]);
      ++v2;
    }
    while ( v2 < v1->m_saVertexStreams.m_num );
  }
  RenderDeviceD3D::ApplyVertexFormat(&v1->m_HardwareVertexFormat);
}

//----- (00698280) --------------------------------------------------------  // acclient.c:688089
void __thiscall RenderVertexBufferD3D::Begin(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // esi@1

  v1 = this;
  SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&this->m_saDirtyVertices);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_saVertexStreams);
}

//----- (006982A0) --------------------------------------------------------  // acclient.c:688099
void __thiscall RenderVertexBufferD3D::ReleaseVertexStreams(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // esi@1
  unsigned int v2; // edi@1
  RenderVertexStreamD3D *v3; // ecx@3
  unsigned int v4; // eax@8
  unsigned int v5; // edx@8
  int i; // eax@11

  v1 = this;
  v2 = 0;
  if ( this->m_saVertexStreams.m_num )
  {
    do
    {
      if ( v1->staticVertices )
      {
        v3 = v1->m_saVertexStreams.m_data[v2];
        if ( v3 )
          ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
        v1->m_saVertexStreams.m_data[v2] = 0;
      }
      else
      {
        v1->m_saVertexStreams.m_data[v2] = 0;
      }
      ++v2;
    }
    while ( v2 < v1->m_saVertexStreams.m_num );
  }
  v4 = v1->m_saVertexStreams.m_sizeAndDeallocate;
  v5 = v1->m_saVertexStreams.m_sizeAndDeallocate & 0x80000000;
  v1->m_saVertexStreams.m_num = 0;
  if ( v5 == 0x80000000 )
  {
    operator delete[](v1->m_saVertexStreams.m_data);
    v1->m_saVertexStreams.m_data = 0;
    v1->m_saVertexStreams.m_sizeAndDeallocate = 0;
    SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_saDirtyVertices);
  }
  else
  {
    if ( v1->m_saVertexStreams.m_data )
    {
      for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; v1->m_saVertexStreams.m_data[i + 1] = 0 )
        --i;
    }
    SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_saDirtyVertices);
  }
}

//----- (00698390) --------------------------------------------------------  // acclient.c:688151
void __thiscall RenderVertexBufferD3D::Shutdown(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // esi@1

  v1 = this;
  RenderVertexBufferD3D::ReleaseVertexStreams(this);
  RenderVertexBuffer::Shutdown((RenderVertexBuffer *)&v1->vfptr);
  SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_saDirtyVertices);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_saVertexStreams);
}

//----- (00698410) --------------------------------------------------------  // acclient.c:688189
char __thiscall RenderVertexBufferD3D::UpdateVertexBuffer(RenderVertexBufferD3D *this, unsigned int _nFirstVertexIndex, unsigned int _nNumVerticesInRange, unsigned int *_nBaseVertexIndex)
{
  unsigned int *v4; // ebp@1
  RenderVertexBufferD3D *v5; // esi@1
  RenderVertexStreamD3D **v6; // eax@1
  RenderVertexStreamD3D *v7; // edi@1
  int v8; // eax@4
  int v9; // edi@7
  const unsigned int v10; // edx@8
  int v11; // ecx@8
  int v12; // eax@8
  void *v14; // ebx@15
  char *v15; // ecx@15
  RenderVertexStreamD3D *pStream; // [sp+10h] [bp-Ch]@1
  VertexRange vrAll; // [sp+14h] [bp-8h]@3
  bool _nFirstVertexIndexa; // [sp+20h] [bp+4h]@8
  unsigned int NeedSwapYAndZ; // [sp+24h] [bp+8h]@4
  bool id; // [sp+28h] [bp+Ch]@15

  v4 = _nBaseVertexIndex;
  v5 = this;
  *_nBaseVertexIndex = 0;
  v6 = this->m_saVertexStreams.m_data;
  v7 = *v6;
  pStream = *v6;
  if ( this->staticVertices )
  {
    if ( v7->m_bIsLost )
    {
      vrAll.m_nNumVertices = this->numVertices;
      this->m_saDirtyVertices.m_num = 0;
      vrAll.m_nFirstVertex = 0;
      SmartArray<UIMessageRemovalData,1>::add(
        (SmartArray<UIMessageData,1> *)&this->m_saDirtyVertices,
        (UIMessageData *)&vrAll);
    }
    v8 = 0;
    NeedSwapYAndZ = 0;
    if ( v5->m_saDirtyVertices.m_num > 0 )
    {
      while ( 1 )
      {
        v9 = (int)&v5->m_saDirtyVertices.m_data[v8];
        if ( v5->m_UseVirtualArray )
        {
          v10 = *(_DWORD *)v9;
          v11 = (int)&v5->m_HardwareVertexFormat;
          v12 = (int)((char *)v5->m_pVirtualArray + *(_DWORD *)v9 * v5->m_HardwareVertexFormat.size);
          _nFirstVertexIndexa = 0;
        }
        else
        {
          v11 = (int)&v5->vertexFormat;
          _nFirstVertexIndexa = v5->m_IsYAndZSwapped == 0;
          v10 = *(_DWORD *)v9;
          v12 = (int)((char *)v5->vertices + *(_DWORD *)v9 * v5->vertexFormat.size);
        }
        if ( !RenderVertexStreamD3D::FillData(
                pStream,
                v10,
                *(_DWORD *)(v9 + 4),
                (const void *)v12,
                (VertexFormatInfo *)v11,
                _nFirstVertexIndexa,
                v4) )
          return 0;
        v8 = NeedSwapYAndZ++ + 1;
        if ( NeedSwapYAndZ >= v5->m_saDirtyVertices.m_num )
          break;
        v4 = _nBaseVertexIndex;
      }
    }
    v5->m_saDirtyVertices.m_num = 0;
    return 1;
  }
  if ( this->m_UseVirtualArray )
  {
    id = 0;
    v14 = this->m_pVirtualArray;
    v15 = (char *)&this->m_HardwareVertexFormat;
  }
  else
  {
    v14 = this->vertices;
    id = this->m_IsYAndZSwapped == 0;
    v15 = (char *)&this->vertexFormat;
  }
  if ( RenderVertexStreamD3D::FillData(
         v7,
         _nFirstVertexIndex,
         _nNumVerticesInRange,
         (char *)v14 + _nFirstVertexIndex * *((_DWORD *)v15 + 1),
         (VertexFormatInfo *)v15,
         id,
         v4) )
    return 1;
  return 0;
}

//----- (00698580) --------------------------------------------------------  // acclient.c:688289
char __thiscall RenderVertexBufferD3D::AddDirtyRange(RenderVertexBufferD3D *this, VertexRange *_vrRange)
{
  UIMessageData *v2; // ebx@1
  unsigned int v3; // eax@1
  RenderVertexBufferD3D *v4; // ebp@1
  unsigned int v5; // ecx@1
  unsigned int v6; // edi@3
  unsigned int v7; // edx@3
  unsigned int v8; // esi@3
  int v9; // ecx@4
  unsigned int v10; // eax@4
  bool v11; // cf@4
  int v12; // ecx@4
  char result; // al@13
  unsigned int newRangeLastVertex; // [sp+10h] [bp-4h]@3

  v2 = (UIMessageData *)_vrRange;
  v3 = _vrRange->m_nFirstVertex;
  v4 = this;
  v5 = this->numVertices;
  if ( _vrRange->m_nFirstVertex >= v5 || v3 + _vrRange->m_nNumVertices > v5 )
  {
    result = 0;
  }
  else
  {
    v6 = _vrRange->m_nFirstVertex;
    v7 = _vrRange->m_nNumVertices + v3 - 1;
    v8 = 0;
    newRangeLastVertex = _vrRange->m_nNumVertices + v3 - 1;
    if ( v4->m_saDirtyVertices.m_num )
    {
      do
      {
        v9 = (int)&v4->m_saDirtyVertices.m_data[v8];
        v10 = *(_DWORD *)v9;
        v11 = v6 < *(_DWORD *)v9;
        v12 = *(_DWORD *)(v9 + 4) + *(_DWORD *)v9 - 1;
        if ( !v11 )
        {
          if ( v12 >= v7 )
            goto LABEL_13;
          if ( v6 >= v10 )
            goto LABEL_17;
        }
        if ( v7 > v12 )
        {
          SmartArray<VertexRange,1>::RemoveUnOrderedByIndex(&v4->m_saDirtyVertices, v8);
          v7 = newRangeLastVertex;
        }
        else
        {
LABEL_17:
          ++v8;
        }
      }
      while ( v8 < v4->m_saDirtyVertices.m_num );
      v2 = (UIMessageData *)_vrRange;
    }
    SmartArray<UIMessageRemovalData,1>::add((SmartArray<UIMessageData,1> *)&v4->m_saDirtyVertices, v2);
LABEL_13:
    result = 1;
  }
  return result;
}

//----- (00698620) --------------------------------------------------------  // acclient.c:688356
char __thiscall RenderVertexBufferD3D::CreateVertexStreams(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // edi@1
  unsigned int v2; // ebx@1
  GraphicsResource *v3; // eax@2
  RenderVertexStreamD3D *v4; // esi@2
  unsigned int v5; // ecx@3
  GraphicsResourceVtbl *v6; // edx@3
  bool v7; // cf@3
  ReferenceCountTemplate<1048576,1>Vtbl *v9; // edx@6
  RenderVertexStreamD3D *pStream; // [sp+Ch] [bp-Ch]@3
  VertexRange vrDirty; // [sp+10h] [bp-8h]@6

  v1 = this;
  v2 = this->m_HardwareVertexFormat.format;
  if ( this->staticVertices )
  {
    v3 = (GraphicsResource *)operator new(0xB8u);
    v4 = (RenderVertexStreamD3D *)v3;
    if ( !v3 )
      return 0;
    GraphicsResource::GraphicsResource(v3);
    v4->vfptr = (GraphicsResourceVtbl *)&RenderVertexStreamD3D::vftable;
    RenderVertexStreamD3D::Begin(v4);
    v5 = v1->numVertices;
    v6 = v4->vfptr;
    v7 = v1->m_OnlyWriteOnce != 0;
    pStream = v4;
    if ( !(unsigned __int8)((int (__thiscall *)(RenderVertexStreamD3D *, unsigned int, unsigned int, int))v6[1].__vecDelDtor)(
                             v4,
                             v5,
                             v2,
                             v7 ? 0x10 : 0) )
    {
      v4->vfptr->__vecDelDtor((GraphicsResource *)v4, 1u);
      return 0;
    }
    v9 = v1->vfptr;
    vrDirty.m_nNumVertices = v1->numVertices;
    vrDirty.m_nFirstVertex = 0;
    v9[9].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v1, (unsigned int)&vrDirty);
  }
  else
  {
    pStream = D3DPolyRender::ReferenceVertexStream(Render::m_pRenderer, v2, this->numVertices);
    if ( !pStream )
      return 0;
  }
  SmartArray<UIElement_Button *,1>::AddToEnd(
    (SmartArray<BSPNODE *,1> *)&v1->m_saVertexStreams,
    (BSPNODE *const *)&pStream);
  return 1;
}
// 7E5438: using guessed type int (__thiscall *RenderVertexStreamD3D::vftable)(void *, char);

//----- (006986E0) --------------------------------------------------------  // acclient.c:688412
char __thiscall RenderVertexBufferD3D::RenderIndexedPrimitives(RenderVertexBufferD3D *this, PrimType _PrimType, const unsigned int _nFirstIndex, const unsigned int _nNumPrimitives, const unsigned int _nFirstVertexIndex, const unsigned int _nNumVertexIndices, const unsigned int _nVertexOffset, RenderIndexBuffer *_IndexBuffer, const bool _bForceBlend, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex, const bool _bUseBaseVertexIndex)
{
  RenderVertexBufferD3D *v12; // esi@1
  bool v13; // al@1
  const unsigned int v14; // ebx@1
  unsigned int *v15; // ecx@5
  unsigned int v16; // eax@9
  RenderIndexBufferVtbl *v17; // ecx@21
  IDirect3DIndexBuffer9 *v18; // eax@23
  unsigned int nBaseVertexIndex; // [sp+10h] [bp-8h]@1
  RenderVertexStreamD3D *pStream; // [sp+14h] [bp-4h]@1

  v12 = this;
  v13 = this->m_NeedRefreshVirtualArray;
  v14 = 0;
  pStream = *this->m_saVertexStreams.m_data;
  nBaseVertexIndex = 0;
  if ( v13
    || this->staticVertices
    || _bForceBlend
    || !_pnStreamFrameID
    || (v15 = _pnBaseVertexIndex) == 0
    || *_pnStreamFrameID == -1
    || pStream->m_nStreamFrameID != *_pnStreamFrameID )
  {
    RenderVertexBuffer::RefreshVirtualArray((RenderVertexBuffer *)&v12->vfptr);
    v16 = _nFirstVertexIndex;
    if ( !v12->staticVertices )
      v16 = _nFirstVertexIndex + _nVertexOffset;
    if ( !RenderVertexBufferD3D::UpdateVertexBuffer(v12, v16, _nNumVertexIndices, &nBaseVertexIndex) )
      return 0;
    v15 = _pnBaseVertexIndex;
  }
  else
  {
    nBaseVertexIndex = *_pnBaseVertexIndex;
  }
  if ( v12->staticVertices )
  {
    if ( _bUseBaseVertexIndex )
    {
      v14 = 0;
      nBaseVertexIndex = _nVertexOffset + _nFirstVertexIndex;
    }
    else
    {
      v14 = _nFirstVertexIndex;
      nBaseVertexIndex = _nVertexOffset;
    }
  }
  if ( _pnStreamFrameID && v15 )
  {
    *_pnStreamFrameID = pStream->m_nStreamFrameID;
    *v15 = nBaseVertexIndex;
  }
  RenderVertexBufferD3D::SetupVertexStreams(v12);
  if ( RenderIndexBufferD3D::UpdateIndexBuffer((RenderIndexBufferD3D *)_IndexBuffer) )
    v17 = _IndexBuffer[1].vfptr;
  else
    v17 = 0;
  v18 = RenderIndexStreamD3D::GetDirect3DIndexBuffer((RenderIndexStreamD3D *)v17);
  if ( v18 )
  {
    (*(void (__stdcall **)(_DWORD, IDirect3DIndexBuffer9 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                           + 416))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      v18);
    (*(void (__stdcall **)(_DWORD, PrimType, unsigned int, const unsigned int, const unsigned int, const unsigned int, const unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 328))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      _PrimType,
      nBaseVertexIndex,
      v14,
      _nNumVertexIndices,
      _nFirstIndex,
      _nNumPrimitives);
    return 1;
  }
  return 0;
}

//----- (00698840) --------------------------------------------------------  // acclient.c:688493
char __thiscall RenderVertexBufferD3D::RenderPrimitives(RenderVertexBufferD3D *this, PrimType _PrimType, const unsigned int _nFirstVertex, const unsigned int _nNumPrimitives, unsigned int *_pnStreamFrameID, unsigned int *_pnBaseVertexIndex)
{
  unsigned int v6; // esi@1
  RenderVertexBufferD3D *v7; // edi@1
  RenderVertexStreamD3D *v8; // ecx@7
  bool v9; // al@7
  char result; // al@14
  unsigned int v11; // eax@18
  unsigned int nBaseVertexIndex; // [sp+10h] [bp-8h]@7
  RenderVertexStreamD3D *pStream; // [sp+14h] [bp-4h]@7

  v6 = 0;
  v7 = this;
  switch ( _PrimType )
  {
    case 1:
      v6 = _nNumPrimitives;
      break;
    case 2:
      v6 = 2 * _nNumPrimitives;
      break;
    case 3:
      v6 = _nNumPrimitives + 1;
      break;
    case 4:
      v6 = 3 * _nNumPrimitives;
      break;
    case 5:
    case 6:
      v6 = _nNumPrimitives + 2;
      break;
    default:
      break;
  }
  v8 = *this->m_saVertexStreams.m_data;
  v9 = v7->m_NeedRefreshVirtualArray;
  pStream = v8;
  nBaseVertexIndex = 0;
  if ( v9
    || v7->staticVertices
    || !_pnStreamFrameID
    || !_pnBaseVertexIndex
    || *_pnStreamFrameID == -1
    || v8->m_nStreamFrameID != *_pnStreamFrameID )
  {
    RenderVertexBuffer::RefreshVirtualArray((RenderVertexBuffer *)&v7->vfptr);
    result = RenderVertexBufferD3D::UpdateVertexBuffer(v7, _nFirstVertex, v6, &nBaseVertexIndex);
    if ( !result )
      return result;
    v8 = pStream;
  }
  else
  {
    nBaseVertexIndex = *_pnBaseVertexIndex;
  }
  if ( _pnStreamFrameID )
  {
    if ( _pnBaseVertexIndex )
    {
      v11 = nBaseVertexIndex;
      *_pnStreamFrameID = v8->m_nStreamFrameID;
      *_pnBaseVertexIndex = v11;
    }
  }
  RenderVertexBufferD3D::SetupVertexStreams(v7);
  (*(void (__stdcall **)(_DWORD, PrimType, unsigned int, const unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                            + 324))(
    LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
    _PrimType,
    nBaseVertexIndex,
    _nNumPrimitives);
  return 1;
}

//----- (00698970) --------------------------------------------------------  // acclient.c:688568
bool __thiscall RenderVertexBufferD3D::Startup(RenderVertexBufferD3D *this, const unsigned int _numVertices, const unsigned int _format, const bool _staticVertices, const bool _OnlyWriteOnce, const unsigned int _HardwareFormatMask)
{
  RenderVertexBufferD3D *v6; // esi@1
  bool result; // al@3

  v6 = this;
  if ( _numVertices
    && RenderVertexBuffer::Startup(
         (RenderVertexBuffer *)&this->vfptr,
         _numVertices,
         _format,
         _staticVertices,
         _OnlyWriteOnce,
         _HardwareFormatMask) )
    result = RenderVertexBufferD3D::CreateVertexStreams(v6) != 0;
  else
    result = 0;
  return result;
}

//----- (0071A8D0) --------------------------------------------------------  // acclient.c:813030
int sub_71A8D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_82, "None");
  return atexit(sub_786040);
}

//----- (0071A8F0) --------------------------------------------------------  // acclient.c:813037
int sub_71A8F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_82, "Speed");
  return atexit(sub_786070);
}

//----- (0071A910) --------------------------------------------------------  // acclient.c:813044
int _E79_94()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_82, "Noise");
  return atexit(_E80_91);
}

//----- (0071A930) --------------------------------------------------------  // acclient.c:813051
int _E82_59()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_82, "Sine");
  return atexit(_E83_55);
}

//----- (0071A950) --------------------------------------------------------  // acclient.c:813058
int _E85_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_82, "Square");
  return atexit(_E86_34);
}

//----- (0071A970) --------------------------------------------------------  // acclient.c:813065
int _E88_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_82, "Bounce");
  return atexit(_E89_44);
}

//----- (0071A990) --------------------------------------------------------  // acclient.c:813072
int sub_71A990()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_82, "Perlin");
  return atexit(_E92_53);
}

//----- (0071A9B0) --------------------------------------------------------  // acclient.c:813079
int _E94_44()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_82, "Fractal");
  return atexit(sub_786190);
}

//----- (0071A9D0) --------------------------------------------------------  // acclient.c:813086
int sub_71A9D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_82, "FrameLoop");
  return atexit(sub_7861C0);
}

//----- (0071A9F0) --------------------------------------------------------  // acclient.c:813093
void sub_71A9F0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8CD0, PFID_A8R8G8B8);
}

//----- (0071AA00) --------------------------------------------------------  // acclient.c:813099
void _E118_87()
{
  LODWORD(dword_8F8D08) = 1053364187;
}

//----- (0071AA10) --------------------------------------------------------  // acclient.c:813105
void _E120_82()
{
  flt_8F8D0C = 1000.0 + 1.0;
}

//----- (0071AA30) --------------------------------------------------------  // acclient.c:813111
void _E122_36()
{
  flt_8F8D10 = 24.0 * 8.0;
}

//----- (0071AA50) --------------------------------------------------------  // acclient.c:813117
void _E124_78()
{
  flt_8F8D14 = 24.0 * 0.5;
}

//----- (0071AA70) --------------------------------------------------------  // acclient.c:813123
int _E126_60()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_47, "Render.TextureFiltering");
  return atexit(sub_7861F0);
}

//----- (0071AA90) --------------------------------------------------------  // acclient.c:813130
int _E129_54()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_47, "Render.LandscapeDetailTextures");
  return atexit(sub_786220);
}

//----- (0071AAB0) --------------------------------------------------------  // acclient.c:813137
int _E132_54()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_47, "Render.BuildingDetailTextures");
  return atexit(sub_786250);
}

//----- (0071AAD0) --------------------------------------------------------  // acclient.c:813144
int _E135_62()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_47, "Render.FieldOfView");
  return atexit(_E136_96);
}

//----- (0071AAF0) --------------------------------------------------------  // acclient.c:813151
int _E138_48()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_47, "Render.LandscapeTextureDetail");
  return atexit(_E139_96);
}

//----- (0071AB10) --------------------------------------------------------  // acclient.c:813158
int _E141_50()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_47, "Render.EnvironmentTextureDetail");
  return atexit(_E142_90);
}

//----- (0071AB30) --------------------------------------------------------  // acclient.c:813165
int _E144_47()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_47, "Render.SceneryDrawDistance");
  return atexit(_E145_92);
}

//----- (0071AB50) --------------------------------------------------------  // acclient.c:813172
int _E147_46()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_47, "Render.LandscapeDrawDistance");
  return atexit(_E148_88);
}

//----- (0071AB70) --------------------------------------------------------  // acclient.c:813179
int _E150_45()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_47, "Render.ScreenBrightness");
  return atexit(_E151_86);
}

//----- (0071AB90) --------------------------------------------------------  // acclient.c:813186
int _E153_43()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_47, "Render.AspectRatio");
  return atexit(_E154_87);
}

//----- (0071ABB0) --------------------------------------------------------  // acclient.c:813193
int _E156_45()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_47, "Render.DisplayAdapter");
  return atexit(_E157_83);
}

//----- (0071ABD0) --------------------------------------------------------  // acclient.c:813200
int _E159_43()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_47, "Render.MaxHardwareClass");
  return atexit(_E160_86);
}

//----- (0071ABF0) --------------------------------------------------------  // acclient.c:813207
int _E162_46()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_47, "Render.AutomaticDegrades");
  return atexit(_E163_79);
}

//----- (0071AC10) --------------------------------------------------------  // acclient.c:813214
int _E165_41()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_47, "Render.GraphicsPerformance");
  return atexit(_E166_81);
}

//----- (0071AC30) --------------------------------------------------------  // acclient.c:813221
int _E168_42()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_47, "Render.DegradeDistance");
  return atexit(_E169_80);
}

//----- (0071AC50) --------------------------------------------------------  // acclient.c:813228
int _E171_41()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_47, "Render.MultiPassAlpha");
  return atexit(_E172_78);
}

//----- (0071AC70) --------------------------------------------------------  // acclient.c:813235
int _E174_43()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_47, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8D60, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8D64, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F8D68, "Anisotropic");
  return atexit(_E175_75);
}

//----- (0071ACC0) --------------------------------------------------------  // acclient.c:813245
int _E177_40()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_47, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8D70, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8D74, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8D78, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8D7C, "VeryHigh");
  return atexit(_E178_75);
}

//----- (0071AD20) --------------------------------------------------------  // acclient.c:813256
int _E180_40()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_47, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8D84, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8D88, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8D8C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8D90, "VeryHigh");
  return atexit(_E181_75);
}

//----- (0071AD80) --------------------------------------------------------  // acclient.c:813267
int _E183_39()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_47, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8D98, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8D9C, "High");
  return atexit(_E184_72);
}

//----- (0071ADC0) --------------------------------------------------------  // acclient.c:813276
int _E186_39()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_47, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8DA4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8DA8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8DAC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8DB0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F8DB4, "Extreme");
  return atexit(_E187_71);
}

//----- (0071AE30) --------------------------------------------------------  // acclient.c:813288
int _E189_38()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_47, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F8DBC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F8DC0, "Wide");
  return atexit(_E190_72);
}

//----- (0071AE70) --------------------------------------------------------  // acclient.c:813297
int sub_71AE70()
{
  return atexit(nullsub_249);
}

//----- (00786040) --------------------------------------------------------  // acclient.c:925397
void __cdecl sub_786040()
{
  char *v0; // esi@1

  v0 = &waveform_None_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786070) --------------------------------------------------------  // acclient.c:925410
void __cdecl sub_786070()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007860A0) --------------------------------------------------------  // acclient.c:925423
void __cdecl _E80_91()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007860D0) --------------------------------------------------------  // acclient.c:925436
void __cdecl _E83_55()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786100) --------------------------------------------------------  // acclient.c:925449
void __cdecl _E86_34()
{
  char *v0; // esi@1

  v0 = &waveform_Square_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786130) --------------------------------------------------------  // acclient.c:925462
void __cdecl _E89_44()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786160) --------------------------------------------------------  // acclient.c:925475
void __cdecl _E92_53()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786190) --------------------------------------------------------  // acclient.c:925488
void __cdecl sub_786190()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007861C0) --------------------------------------------------------  // acclient.c:925501
void __cdecl sub_7861C0()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007861F0) --------------------------------------------------------  // acclient.c:925514
void __cdecl sub_7861F0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786220) --------------------------------------------------------  // acclient.c:925527
void __cdecl sub_786220()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786250) --------------------------------------------------------  // acclient.c:925540
void __cdecl sub_786250()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786280) --------------------------------------------------------  // acclient.c:925553
void __cdecl _E136_96()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007862B0) --------------------------------------------------------  // acclient.c:925566
void __cdecl _E139_96()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007862E0) --------------------------------------------------------  // acclient.c:925579
void __cdecl _E142_90()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786310) --------------------------------------------------------  // acclient.c:925592
void __cdecl _E145_92()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786340) --------------------------------------------------------  // acclient.c:925605
void __cdecl _E148_88()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786370) --------------------------------------------------------  // acclient.c:925618
void __cdecl _E151_86()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007863A0) --------------------------------------------------------  // acclient.c:925631
void __cdecl _E154_87()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007863D0) --------------------------------------------------------  // acclient.c:925644
void __cdecl _E157_83()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786400) --------------------------------------------------------  // acclient.c:925657
void __cdecl _E160_86()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786430) --------------------------------------------------------  // acclient.c:925670
void __cdecl _E163_79()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786460) --------------------------------------------------------  // acclient.c:925683
void __cdecl _E166_81()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786490) --------------------------------------------------------  // acclient.c:925696
void __cdecl _E169_80()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007864C0) --------------------------------------------------------  // acclient.c:925709
void __cdecl _E172_78()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007864F0) --------------------------------------------------------  // acclient.c:925722
void __cdecl _E175_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_47;
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

//----- (00786530) --------------------------------------------------------  // acclient.c:925747
void __cdecl _E178_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_47;
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

//----- (00786570) --------------------------------------------------------  // acclient.c:925772
void __cdecl _E181_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_47;
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

//----- (007865B0) --------------------------------------------------------  // acclient.c:925797
void __cdecl _E184_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_47;
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

//----- (007865F0) --------------------------------------------------------  // acclient.c:925822
void __cdecl _E187_71()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_47;
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

//----- (00786630) --------------------------------------------------------  // acclient.c:925847
void __cdecl _E190_72()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_8F8DC4;
  v1 = 3;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
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

