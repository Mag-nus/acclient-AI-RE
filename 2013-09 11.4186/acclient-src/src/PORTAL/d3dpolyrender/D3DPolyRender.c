/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : D3DPolyRender
   Object     : PORTAL\d3dpolyrender\D3DPolyRender.obj
   Functions  : 127
   Addresses  : 00439CE0 - 00775AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00439CE0) --------------------------------------------------------  // acclient.c:118777
char __thiscall SmartArray<RenderDisplayModeType,1>::grow(SmartArray<RenderDisplayModeType,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebx@1
  SmartArray<RenderDisplayModeType,1> *v3; // esi@1
  void *v5; // edi@5
  int v6; // ecx@7
  int v7; // eax@8
  unsigned int v8; // ecx@8
  int v9; // edx@9
  int v10; // ebx@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<RenderDisplayModeType,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize);
    if ( v5 )
    {
      if ( v3->m_data )
      {
        v6 = v3->m_num - 1;
        if ( v6 >= 0 )
        {
          v7 = v6;
          v8 = v3->m_num;
          do
          {
            v9 = (int)&v3->m_data[v7];
            v10 = (int)((char *)v5 + v7 * 16);
            *(_DWORD *)v10 = *(_DWORD *)v9;
            *(_DWORD *)(v10 + 4) = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v10 + 8) = *(_DWORD *)(v9 + 8);
            --v7;
            --v8;
            *(_DWORD *)(v10 + 12) = *(_DWORD *)(v9 + 12);
          }
          while ( v8 );
          v2 = i_nSize;
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v3->m_data);
      }
      v3->m_data = (RenderDisplayModeType *)v5;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0043C810) --------------------------------------------------------  // acclient.c:121417
char __thiscall HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(HashTable<unsigned long,RenderVertexStreamD3D *,0> *this, const unsigned int *_key, RenderVertexStreamD3D *const *_data)
{
  HashTable<unsigned long,RenderVertexStreamD3D *,0> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00442710) --------------------------------------------------------  // acclient.c:126632
void __thiscall SmartArray<unsigned char,0>::Reset(SmartArray<_D3DXATTRIBUTERANGE,0> *this)
{
  SmartArray<_D3DXATTRIBUTERANGE,0> *v1; // esi@1
  unsigned int v2; // eax@1

  v1 = this;
  v2 = this->m_sizeAndDeallocate & 0x80000000;
  this->m_num = 0;
  if ( v2 == 0x80000000 )
  {
    operator delete[](this->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
}

//----- (00548120) --------------------------------------------------------  // acclient.c:375469
char __thiscall IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *this, HashTableData<unsigned long,RenderVertexStreamD3D *> *data)
{
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v2; // edx@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v3; // eax@1
  char result; // al@6

  v2 = &this->m_buckets[data->m_hashKey % this->m_numBuckets];
  v3 = *v2;
  if ( !*v2 )
    goto LABEL_4;
  while ( v3->m_hashKey != data->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    data->m_hashNext = *v2;
    *v2 = data;
    if ( v2 < this->m_firstInterestingBucket )
      this->m_firstInterestingBucket = v2;
    ++this->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0059BB30) --------------------------------------------------------  // acclient.c:453771
void __thiscall RenderStateCacheType::RenderStateCacheType(RenderStateCacheType *this)
{
  RenderStateCacheType *v1; // eax@1
  signed int v2; // ebx@1
  char *v3; // ecx@1
  signed int v4; // edi@1
  int v5; // ecx@3
  int v6; // edx@5

  v1 = this;
  this->BlendOp = 0x7FFFFFFF;
  this->DestBlend = 0x7FFFFFFF;
  this->AlphaBlendEnable = 0;
  this->AlphaTestEnable = 0;
  v2 = 8;
  this->AlphaTestFunction = 8;
  this->AlphaTestRef = 0;
  this->ColorWriteEnable = 0;
  LODWORD(this->DepthBias) = 0;
  this->DepthBufferEnable = 0;
  this->DepthTestFunction = 8;
  this->DepthWriteEnable = 0;
  this->FFAmbientColor32 = 0;
  this->FFAmbientColorSource = 0;
  this->FFDiffuseColorSource = 0;
  this->CullMode = 1;
  this->FFFogColor = stru_820DF0;
  this->FillMode = 0x7FFFFFFF;
  this->SourceBlend = 0x7FFFFFFF;
  this->FFFogEnable = 0;
  this->FFFogSystemDisabled = 0;
  this->FFFogUserDisabled = 0;
  this->FFFogAlphaDisabled = 0;
  LODWORD(this->FFFogFarDistance) = 0;
  LODWORD(this->FFFogNearDistance) = 0;
  this->FFLighting = 0;
  this->FFEmissiveColorSource = 0;
  this->FFSpecularColorSource = 0;
  this->FFSpecularEnable = 0;
  this->FFTextureFactor32 = 0;
  this->MultiSampleAntialias = 0;
  this->pVertexBuffer = 0;
  v3 = (char *)this->Samplers;
  v4 = 16;
  do
  {
    *(_DWORD *)v3 = 3;
    *((_DWORD *)v3 + 1) = 3;
    *((_DWORD *)v3 + 2) = 1;
    *((_DWORD *)v3 + 3) = 1;
    *((_DWORD *)v3 + 4) = 1;
    *((_DWORD *)v3 + 5) = 0;
    v3 += 24;
    --v4;
  }
  while ( v4 );
  v5 = (int)v1->Stages;
  do
  {
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 2;
    *(_DWORD *)(v5 + 8) = 2;
    *(_DWORD *)(v5 + 12) = 1;
    *(_DWORD *)(v5 + 16) = 2;
    *(_DWORD *)(v5 + 20) = 2;
    *(_DWORD *)(v5 + 24) = 1;
    *(_DWORD *)(v5 + 28) = 0;
    *(_DWORD *)(v5 + 32) = 0;
    v5 += 36;
    --v2;
  }
  while ( v2 );
  v6 = (int)v1->FFLightEnable;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
}

//----- (0059BC30) --------------------------------------------------------  // acclient.c:453849
GraphicsResource *__thiscall RenderVertexStreamD3D::scalar_deleting_destructor(RenderVertexStreamD3D *this, unsigned int a2)
{
  GraphicsResource *v2; // esi@1

  v2 = (GraphicsResource *)this;
  this->vfptr = (GraphicsResourceVtbl *)&RenderVertexStreamD3D::vftable;
  RenderVertexStreamD3D::End(this);
  GraphicsResource::~GraphicsResource(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E5438: using guessed type int (__thiscall *RenderVertexStreamD3D::vftable)(void *, char);

//----- (0059BC60) --------------------------------------------------------  // acclient.c:453864
int D3DPolyRender::InitInternal()
{
  int result; // eax@1

  result = PrimD3DRender::InitInternal();
  if ( result )
  {
    D3DPolyRender::alphaedMeshCountClip = 0;
    D3DPolyRender::alphaedMeshCountAlpha = 0;
    result = 1;
  }
  return result;
}
// 8719AC: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountClip;
// 8719B0: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountAlpha;

//----- (0059BC90) --------------------------------------------------------  // acclient.c:453881
void __cdecl D3DPolyRender::DrawPortalPolyInternal(CPolygon *p, bool zClear)
{
  unsigned int v2; // edi@1
  char v3; // bl@3
  signed int v4; // esi@3
  CVertex *v5; // ecx@4
  int v6; // ST04_4@19
  signed __int16 v7; // ax@21
  int v8; // ecx@30
  int v9; // edx@30
  RenderDevice *v10; // ebp@31
  unsigned __int16 v11; // cx@31
  int v12; // esi@31
  unsigned int v13; // edi@31
  char *v14; // eax@31
  Vec2Dscreen *v15; // ecx@32
  double v16; // st7@33
  double v17; // st7@35
  bool v18; // sf@35
  unsigned __int8 v19; // of@35
  bool south; // [sp+11h] [bp-7h]@3
  bool east; // [sp+12h] [bp-6h]@3
  bool west; // [sp+13h] [bp-5h]@3
  int clip_pts; // [sp+14h] [bp-4h]@19

  Render::CalcObjectMatrix();
  v2 = maxZ1;
  if ( !zClear )
    v2 = maxZ2;
  v3 = 1;
  v4 = 0;
  south = 1;
  east = 1;
  west = 1;
  if ( p->num_pts )
  {
    do
    {
      v5 = p->vertices[v4];
      if ( v5->x != 12.0 )
        v3 = 0;
      if ( v5->x != -12.0 )
        south = 0;
      if ( v5->y != 12.0 )
        west = 0;
      if ( v5->y != -12.0 )
        east = 0;
      scrBuf[v4++] = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v5, 1);
    }
    while ( v4 < p->num_pts );
    if ( !v3 && !south && !east && !west )
    {
      if ( !zClear )
        ++D3DPolyRender::portalsDrawnCount;
      v6 = p->num_pts;
      clip_pts = 0;
      Render::PolyCurrent = 0;
      LODWORD(Render::PolyCurrentMod) = 1065353216;
      Render::PolyCurrentPos = 1;
      ACRender::polyClipFinish(scrBuf, v6, scrBufclipped, &clip_pts, 0);
      if ( clip_pts >= 3 )
      {
        RenderDeviceD3D::SetStageTexture((RenderDeviceD3D *)RenderDevice::render_device, 0, 0);
        RenderDeviceD3D::SetAlphaTestEnable((RenderDeviceD3D *)RenderDevice::render_device, 0);
        RenderDeviceD3D::SetBlendFunction(
          (RenderDeviceD3D *)RenderDevice::render_device,
          BLEND_SRCALPHA,
          BLEND_INVSRCALPHA,
          BLENDOP_ADD);
        RenderDeviceD3D::SetDepthBufferMode(
          (RenderDeviceD3D *)RenderDevice::render_device,
          DEPTHTEST_ALWAYS,
          (v2 >> 2) & 1);
        (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                  + 356))(
          LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
          324);
        RenderDeviceD3D::SetCullMode((RenderDeviceD3D *)RenderDevice::render_device, CULLMODE_NONE);
        ++colorSel;
        switch ( colorSel )
        {
          case 0:
            v7 = -1;
            portalColorVal = 0xFFFFFF;
            break;
          case 1:
            v7 = 0;
            portalColorVal = 16711680;
            break;
          case 2:
            v7 = -256;
            portalColorVal = 65280;
            break;
          case 3:
            v7 = 255;
            portalColorVal = 255;
            break;
          case 4:
            v7 = -256;
            portalColorVal = 16776960;
            break;
          case 5:
            v7 = -1;
            portalColorVal = 0xFFFF;
            break;
          case 6:
            v7 = 255;
            portalColorVal = 16711935;
            break;
          case 7:
            v7 = 0;
            portalColorVal = 0;
            colorSel = -1;
            break;
          default:
            v7 = portalColorVal;
            break;
        }
        v8 = clip_pts;
        v9 = 0;
        if ( clip_pts > 0 )
        {
          v10 = RenderDevice::render_device;
          HIBYTE(v11) = BYTE2(portalColorVal);
          v12 = v2 & 1;
          LOBYTE(v11) = HIBYTE(v7);
          v13 = (unsigned __int8)v7 | ~(v2 << 30) & 0x80000000 | (v11 << 8);
          v14 = (char *)&v[0].y;
          do
          {
            v15 = scrBufclipped[v9];
            *((float *)v14 - 1) = v15->xw / v15->w + (double)v10->m_viewportX;
            *(float *)v14 = v15->yw / v15->w + (double)v10->m_viewportY;
            if ( v12 )
              v16 = 0.99999899;
            else
              v16 = v15->zw / v15->w;
            *((float *)v14 + 1) = v16;
            ++v9;
            v14 += 28;
            v17 = 1.0 / v15->w;
            v8 = clip_pts;
            v19 = __OFSUB__(v9, clip_pts);
            v18 = v9 - clip_pts < 0;
            *((_DWORD *)v14 - 4) = v13;
            *((float *)v14 - 5) = v17;
          }
          while ( v18 ^ v19 );
        }
        RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLEFAN, v8 - 2, v, 0x1Cu);
      }
    }
  }
}
// 846054: using guessed type float Render::PolyCurrentMod;
// 8460B8: using guessed type int Render::PolyCurrentPos;
// 8662FC: using guessed type struct CPolygon *Render::PolyCurrent;
// 8719B4: using guessed type unsigned __int16 D3DPolyRender::portalsDrawnCount;

//----- (0059BFC0) --------------------------------------------------------  // acclient.c:454041
char __thiscall D3DPolyRender::SelectBestAdapter(D3DPolyRender *this)
{
  D3DPolyRender *v1; // edi@1
  unsigned int v2; // esi@1
  char v3; // bl@1
  unsigned int v4; // ebp@1
  unsigned int v5; // eax@13
  char result; // al@15
  bool bPreferAdapterOK; // [sp+25h] [bp-585h]@1
  unsigned int nPreferAdapter; // [sp+26h] [bp-584h]@1
  unsigned int bestAdapter; // [sp+2Ah] [bp-580h]@1
  _D3DCAPS9 caps; // [sp+2Eh] [bp-57Ch]@6
  _D3DADAPTER_IDENTIFIER9 identifier; // [sp+15Eh] [bp-44Ch]@5

  v1 = this;
  v2 = 0;
  v3 = 0;
  bestAdapter = 0;
  v4 = this->m_pDirect3D->vfptr[1].AddRef((IUnknown *)this->m_pDirect3D);
  nPreferAdapter = -1;
  bPreferAdapterOK = 0;
  if ( dword_81EFAC && dword_81EFAC <= v4 )
    nPreferAdapter = dword_81EFAC - 1;
  if ( !v4 )
    goto LABEL_19;
  do
  {
    if ( !((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _D3DADAPTER_IDENTIFIER9 *))v1->m_pDirect3D->vfptr[1].Release)(
            v1->m_pDirect3D,
            v2,
            0,
            &identifier)
      && !((int (__stdcall *)(_DWORD, _DWORD, signed int, _D3DCAPS9 *))v1->m_pDirect3D->vfptr[4].Release)(
            v1->m_pDirect3D,
            v2,
            1,
            &caps) )
    {
      if ( !v3 )
      {
        bestAdapter = v2;
        v3 = 1;
      }
      if ( nPreferAdapter == v2 )
        bPreferAdapterOK = 1;
    }
    ++v2;
  }
  while ( v2 < v4 );
  if ( v3 )
  {
    v5 = nPreferAdapter;
    if ( !bPreferAdapterOK )
      v5 = bestAdapter;
    v1->m_nDisplayAdapter = v5;
    result = 1;
  }
  else
  {
LABEL_19:
    result = 0;
  }
  return result;
}
// 81EFAC: using guessed type int dword_81EFAC;

//----- (0059C080) --------------------------------------------------------  // acclient.c:454108
void __usercall copyVert(void *vert@<eax>, CSWVertex *acVert@<esi>, char uvSet@<dl>, int a4@<ecx>, char a5@<bl>, int a6@<edi>, int index, int normalMultiplier, float detailTextureUVFactor, float translucency, bool isEnvCell, unsigned int _MeshFVF)
{
  double v12; // st7@1
  int v13; // esi@1
  int v14; // ecx@3

  v12 = (double)normalMultiplier;
  v13 = index * (8 * (_MeshFVF == 594) + 36) + a4;
  *(_DWORD *)v13 = *(_DWORD *)a6;
  *(_DWORD *)(v13 + 4) = *(_DWORD *)(a6 + 4);
  *(_DWORD *)(v13 + 8) = *(_DWORD *)(a6 + 8);
  *(float *)(v13 + 12) = v12 * *(float *)(a6 + 20);
  *(float *)(v13 + 16) = v12 * *(float *)(a6 + 24);
  *(float *)(v13 + 20) = v12 * *(float *)(a6 + 28);
  *(_DWORD *)(v13 + 24) = ((unsigned int)(unsigned __int64)((1.0 - translucency) * 255.0) << 24) | 0xFFFFFF;
  if ( a5 >= 0 && a5 < (signed int)*(_WORD *)(a6 + 14) && (v14 = *(_DWORD *)(a6 + 16)) != 0 )
  {
    *(_DWORD *)(v13 + 28) = *(_DWORD *)(v14 + 8 * a5);
    *(_DWORD *)(v13 + 32) = *(_DWORD *)(*(_DWORD *)(a6 + 16) + 8 * a5 + 4);
    if ( _MeshFVF == 594 )
    {
      *(float *)(v13 + 36) = detailTextureUVFactor * *(float *)(v13 + 28);
      *(float *)(v13 + 40) = detailTextureUVFactor * *(float *)(v13 + 32);
    }
  }
  else
  {
    *(_DWORD *)(v13 + 28) = 0;
    *(_DWORD *)(v13 + 32) = 0;
    if ( _MeshFVF == 594 )
    {
      *(_DWORD *)(v13 + 36) = 0;
      *(_DWORD *)(v13 + 40) = 0;
    }
  }
}

//----- (0059C150) --------------------------------------------------------  // acclient.c:454146
char __cdecl D3DPolyRender::SetDetailTiling(MeshBuffer *pMeshBuffer, float new_detail_tiling)
{
  MeshBuffer *v2; // ebx@1
  char result; // al@2
  ID3DXMesh *v4; // esi@3
  unsigned int v5; // edi@3
  int v6; // ecx@6
  unsigned int v7; // edx@6
  double v8; // st7@7
  char *v9; // eax@7

  v2 = pMeshBuffer;
  if ( pMeshBuffer->meshFVF == 594 )
  {
    v4 = pMeshBuffer->pMesh;
    v5 = pMeshBuffer->pMesh->vfptr[1].Release((IUnknown *)pMeshBuffer->pMesh);
    if ( v4->vfptr[5].QueryInterface((IUnknown *)v4, 0, (void **)&pMeshBuffer) >= 0 )
    {
      if ( (signed int)v5 > 0 )
      {
        v6 = 0;
        v7 = v5;
        do
        {
          v8 = new_detail_tiling * *(float *)((char *)&pMeshBuffer->m_vUVDelta.v + v6);
          v9 = (char *)pMeshBuffer + v6;
          v6 += 44;
          --v7;
          *((float *)v9 + 9) = v8;
          *((float *)v9 + 10) = new_detail_tiling * *((float *)v9 + 8);
        }
        while ( v7 );
      }
      v4->vfptr[5].AddRef((IUnknown *)v4);
      v2->detailTilingFactorSet = new_detail_tiling;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0059C1D0) --------------------------------------------------------  // acclient.c:454196
char __cdecl D3DPolyRender::DestroyMesh(MeshBuffer **meshBuffer)
{
  MeshBuffer *v1; // esi@1
  RenderMesh *v2; // ecx@4

  v1 = *meshBuffer;
  if ( *meshBuffer )
  {
    if ( v1->pMesh )
    {
      v1->pMesh->vfptr->Release((IUnknown *)v1->pMesh);
      v1->pMesh = 0;
    }
    v2 = v1->pRenderMesh;
    if ( v2 )
    {
      ((void (*)(void))v2->vfptr->Release)();
      v1->pRenderMesh = 0;
    }
    operator delete[](v1->isStippledOrAlphaedMask);
    v1->isStippledOrAlphaedMask = 0;
    operator delete(v1);
  }
  *meshBuffer = 0;
  return 1;
}

//----- (0059C230) --------------------------------------------------------  // acclient.c:454224
char __cdecl D3DPolyRender::AddMeshToAlphaList(MeshBuffer *mesh, int surfaceNum, CSurface *surface, bool bFirstInGroup, bool overrideClip, bool clipOrAlpha)
{
  unsigned __int16 v6; // dx@2
  unsigned int v7; // eax@3
  int v8; // eax@4
  unsigned __int16 v10; // dx@6
  unsigned int v11; // eax@7
  int v12; // eax@8

  if ( clipOrAlpha )
  {
    v6 = D3DPolyRender::alphaedMeshCountClip;
    if ( D3DPolyRender::alphaedMeshCountClip < 0xBB8u )
    {
      v7 = 21 * D3DPolyRender::alphaedMeshCountClip;
      (&D3DPolyRender::alphaedMeshListClip)[v7 / 0x15] = (struct AlphaListEntry *)mesh;
      dword_871B14[v7] = surfaceNum;
      dword_871B18[v7] = (int)surface;
      byte_871B61[v7 * 4] = overrideClip;
      byte_871B60[v7 * 4] = bFirstInGroup;
      if ( bFirstInGroup )
      {
        dword_871B1C[v7] = LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g);
        v8 = Render::GetObjectMatrix();
        v6 = D3DPolyRender::alphaedMeshCountClip;
        qmemcpy((char *)&m + 84 * D3DPolyRender::alphaedMeshCountClip, (const void *)v8, 0x40u);
      }
      D3DPolyRender::alphaedMeshCountClip = v6 + 1;
      return 1;
    }
    return 0;
  }
  v10 = D3DPolyRender::alphaedMeshCountAlpha;
  if ( D3DPolyRender::alphaedMeshCountAlpha >= 0xBB8u )
    return 0;
  v11 = 21 * D3DPolyRender::alphaedMeshCountAlpha;
  (&D3DPolyRender::alphaedMeshListAlpha)[v11 / 0x15] = (struct AlphaListEntry *)mesh;
  dword_8AF374[v11] = surfaceNum;
  dword_8AF378[v11] = (int)surface;
  byte_8AF3C1[v11 * 4] = overrideClip;
  byte_8AF3C0[v11 * 4] = bFirstInGroup;
  if ( bFirstInGroup )
  {
    dword_8AF37C[v11] = LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g);
    v12 = Render::GetObjectMatrix();
    v10 = D3DPolyRender::alphaedMeshCountAlpha;
    qmemcpy((char *)&stru_8AF380 + 84 * D3DPolyRender::alphaedMeshCountAlpha, (const void *)v12, 0x40u);
  }
  D3DPolyRender::alphaedMeshCountAlpha = v10 + 1;
  return 1;
}
// 8719AC: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountClip;
// 8719B0: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountAlpha;
// 871B10: using guessed type struct AlphaListEntry *D3DPolyRender::alphaedMeshListClip;
// 871B14: using guessed type int dword_871B14[];
// 871B18: using guessed type int dword_871B18[];
// 871B1C: using guessed type int dword_871B1C[];
// 8AF370: using guessed type struct AlphaListEntry *D3DPolyRender::alphaedMeshListAlpha;
// 8AF374: using guessed type int dword_8AF374[];
// 8AF378: using guessed type int dword_8AF378[];
// 8AF37C: using guessed type int dword_8AF37C[];

//----- (0059C360) --------------------------------------------------------  // acclient.c:454287
RenderIndexStreamD3D *__thiscall D3DPolyRender::ReferenceDynamicIndexStream(D3DPolyRender *this)
{
  D3DPolyRender *v1; // esi@1
  RenderIndexStreamD3D *v2; // eax@2
  RenderIndexStreamD3D *v3; // eax@3
  RenderIndexStreamD3D *v4; // ecx@7

  v1 = this;
  if ( !this->m_pDynamicIndexStream )
  {
    v2 = (RenderIndexStreamD3D *)operator new(0x48u);
    if ( v2 )
      RenderIndexStreamD3D::RenderIndexStreamD3D(v2);
    else
      v3 = 0;
    v1->m_pDynamicIndexStream = v3;
    if ( !v3 )
      return 0;
    if ( !RenderIndexStreamD3D::Init(v3, 0xFFFFu, 1u) )
    {
      v4 = v1->m_pDynamicIndexStream;
      if ( v4 )
        ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
      v1->m_pDynamicIndexStream = 0;
      return 0;
    }
  }
  return v1->m_pDynamicIndexStream;
}

//----- (0059C3D0) --------------------------------------------------------  // acclient.c:454318
void __cdecl LIGHTINFO::convert_to_local(LIGHTINFO *local_light, LIGHTINFO *global_light, Frame *frame)
{
  int v3; // eax@1
  int v4; // eax@2
  AC1Legacy::Vector3 *v5; // eax@4
  char *v6; // ecx@4
  char *v7; // edx@5
  AC1Legacy::Vector3 *v8; // eax@6
  AC1Legacy::Vector3 *v9; // eax@6
  char *v10; // edx@6
  AC1Legacy::Vector3 v11; // [sp+8h] [bp-24h]@6
  AC1Legacy::Vector3 v12; // [sp+14h] [bp-18h]@6
  AC1Legacy::Vector3 result; // [sp+20h] [bp-Ch]@4

  v3 = global_light->type;
  local_light->type = global_light->type;
  if ( !v3 )
    goto LABEL_9;
  v4 = v3 - 1;
  if ( !v4 )
  {
    v8 = Frame::get_vector_heading(&global_light->offset, &v11);
    v9 = Frame::globaltolocalvec(frame, &v12, v8);
    v10 = (char *)&local_light->offset.m_fOrigin;
    *(_DWORD *)v10 = LODWORD(v9->x);
    *((_DWORD *)v10 + 1) = LODWORD(v9->y);
    *((_DWORD *)v10 + 2) = LODWORD(v9->z);
    goto LABEL_5;
  }
  if ( v4 == 1 )
  {
LABEL_9:
    v5 = Frame::globaltolocal(frame, &result, &global_light->offset.m_fOrigin);
    v6 = (char *)&local_light->offset.m_fOrigin;
    *(_DWORD *)v6 = LODWORD(v5->x);
    *((_DWORD *)v6 + 1) = LODWORD(v5->y);
    *((_DWORD *)v6 + 2) = LODWORD(v5->z);
  }
LABEL_5:
  v7 = (char *)&local_light->color;
  *(_DWORD *)v7 = LODWORD(global_light->color.r);
  *((_DWORD *)v7 + 1) = LODWORD(global_light->color.g);
  *((_DWORD *)v7 + 2) = LODWORD(global_light->color.b);
  local_light->intensity = global_light->intensity;
  local_light->falloff = global_light->falloff;
  local_light->cone_angle = global_light->cone_angle;
}

//----- (0059C470) --------------------------------------------------------  // acclient.c:454367
ImgTex *__thiscall CSurface::GetTextureMap(CSurface *this)
{
  CSurface *v1; // esi@1
  int v2; // ecx@6

  v1 = this;
  if ( this->type & 6 && !this->base1map && this->m_bIsLost && CSurface::RestoreLostSurface(this) )
    GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
  v2 = HIDWORD(Timer::local_time);
  LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
  HIDWORD(v1->m_TimeUsed) = v2;
  if ( RenderDevice::render_device )
    v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
  return v1->base1map;
}

//----- (0059C4D0) --------------------------------------------------------  // acclient.c:454384
__int32 __cdecl D3DPolyRender::SetSurface(CSurface *surface, bool stippled, bool singlePassDetailing, bool overrideClipmap)
{
  RenderDevice *v4; // esi@1
  ImgTex *v5; // edi@1
  TexAddress v6; // eax@6
  double v7; // st7@10
  double v8; // st7@12
  BlendMode v9; // edi@16
  BlendMode v10; // ebp@16
  char v11; // bl@20
  __int32 v12; // ecx@29
  float v13; // eax@39
  DepthTestMode v14; // ebx@48
  __int32 result; // eax@52
  const unsigned int v16; // [sp-10h] [bp-20h]@2
  ImgTex *curr_texture; // [sp+8h] [bp-8h]@1
  bool curr_texturea; // [sp+8h] [bp-8h]@43
  IDirect3DTexture9 *new_d3dtss_texture; // [sp+Ch] [bp-4h]@8
  const bool surfacea; // [sp+14h] [bp+4h]@24
  const bool singlePassDetailinga; // [sp+1Ch] [bp+Ch]@13

  Render::curr_surface = surface;
  v4 = RenderDevice::render_device;
  Render::curr_surface_type = surface->type | 0x10000000;
  v5 = CSurface::GetTextureMap(surface);
  curr_texture = v5;
  Render::curr_texture_is_set = v5 != 0;
  if ( singlePassDetailing )
  {
    RenderDeviceD3D::SetStageFFColorSource((RenderDeviceD3D *)v4, 0, TEXOP_MODULATE, 2u, 0);
    RenderDeviceD3D::SetStageFFAlphaSource((RenderDeviceD3D *)v4, 0, TEXOP_PREMODULATE, 0, 0);
    RenderDeviceD3D::SetStageFFColorSource((RenderDeviceD3D *)v4, 1u, TEXOP_BLENDCURRENTALPHA, 2u, 1u);
    RenderDeviceD3D::SetStageFFAlphaSource((RenderDeviceD3D *)v4, 1u, TEXOP_MODULATE, 2u, 1u);
    RenderDeviceD3D::SetSamplerAddressMode((RenderDeviceD3D *)v4, 1u, TEXADDRESS_WRAP, TEXADDRESS_WRAP);
    RenderDeviceD3D::SetSamplerFilterMode(
      (RenderDeviceD3D *)v4,
      1u,
      TEXFILTER_LINEAR,
      TEXFILTER_LINEAR,
      TEXFILTER_LINEAR);
    RenderDeviceD3D::SetStageFFColorSource((RenderDeviceD3D *)v4, 2u, TEXOP_DISABLE, 2u, 1u);
    v16 = 2;
  }
  else
  {
    RenderDeviceD3D::SetStageFFColorSource((RenderDeviceD3D *)v4, 0, TEXOP_MODULATE, 2u, 0);
    RenderDeviceD3D::SetStageFFAlphaSource((RenderDeviceD3D *)v4, 0, TEXOP_MODULATE, 2u, 0);
    RenderDeviceD3D::SetStageFFColorSource((RenderDeviceD3D *)v4, 1u, TEXOP_DISABLE, 2u, 1u);
    v16 = 1;
  }
  RenderDeviceD3D::SetStageFFAlphaSource((RenderDeviceD3D *)v4, v16, TEXOP_DISABLE, 2u, 1u);
  if ( !v5
    || (!stippled ? (v6 = 3) : (Render::curr_surface_type |= 0x40000000u, v6 = 1),
        RenderDeviceD3D::SetSamplerAddressMode((RenderDeviceD3D *)v4, 0, v6, v6),
        RenderDeviceD3D::SetSamplerFilterMode(
          (RenderDeviceD3D *)v4,
          0,
          TEXFILTER_LINEAR,
          TEXFILTER_LINEAR,
          TEXFILTER_LINEAR),
        (new_d3dtss_texture = ImgTex::GetD3DTexture(v5)) == 0) )
  {
    curr_color = Render::curr_surface->color_value;
    curr_alpha = (unsigned __int64)((1.0 - Render::curr_surface->translucency) * 255.0);
    RenderDeviceD3D::SetSolidColorTextureColor((RenderDeviceD3D *)v4, curr_color & 0xFFFFFF | (curr_alpha << 24), 0);
    new_d3dtss_texture = (IDirect3DTexture9 *)LODWORD(v4[2].m_GState.FrameBufferBloomRGBAmount.a);
  }
  v7 = Render::curr_surface->luminosity;
  flt_866400 = Render::curr_surface->luminosity;
  flt_8663FC = v7;
  Render::luminosity.r = v7;
  if ( Render::useSunlight )
  {
    Render::diffuse.r = Render::viewer_lights.sunlight_color.r * Render::curr_surface->diffuse;
    flt_81EFC4 = Render::viewer_lights.sunlight_color.g * Render::curr_surface->diffuse;
    flt_81EFC8 = Render::viewer_lights.sunlight_color.b * Render::curr_surface->diffuse;
  }
  else
  {
    v8 = Render::curr_surface->diffuse;
    flt_81EFC8 = Render::curr_surface->diffuse;
    flt_81EFC4 = v8;
    Render::diffuse.r = v8;
  }
  singlePassDetailinga = 0;
  if ( BYTE1(Render::curr_surface_type) & 1 || overrideClipmap )
  {
    v9 = 5;
    v10 = 2;
    if ( !(Render::curr_surface_type & 0x10000) )
      v10 = 6;
    goto LABEL_23;
  }
  if ( BYTE1(Render::curr_surface_type) & 2 )
  {
    v9 = 6;
    v10 = 2;
    if ( !(Render::curr_surface_type & 0x10000) )
      v10 = 5;
    goto LABEL_23;
  }
  v9 = 2;
  if ( Render::curr_surface_type & 0x10000 )
  {
    v10 = 2;
LABEL_23:
    v11 = 1;
    singlePassDetailinga = 0;
    goto LABEL_24;
  }
  v10 = 1;
  v11 = 0;
LABEL_24:
  surfacea = v11;
  if ( Render::curr_surface_type & 4 && !overrideClipmap )
  {
    if ( !v11 )
    {
      v9 = 2;
      v10 = 6;
    }
    if ( !Render::curr_texture_is_set || (v12 = D3DPolyRender::s_256AlphaTestRef, !curr_texture->m_pPalette) )
      v12 = D3DPolyRender::s_ddsAlphaTestRef;
    v11 = 1;
    testRef = v12;
    surfacea = 1;
    singlePassDetailinga = 1;
  }
  if ( Render::curr_surface_type & 0x10 )
  {
    if ( skipChk || !v11 || singlePassDetailinga == 1 )
    {
      v11 = 1;
      v9 = 5;
      v10 = 6;
      surfacea = 1;
      singlePassDetailinga = 0;
    }
    curr_alpha = (unsigned __int64)((1.0 - Render::curr_surface->translucency) * 255.0);
  }
  else
  {
    curr_alpha = 255;
  }
  v13 = v4[2].m_GState.FrameBufferBloomRGBAmount.g;
  if ( v13 == 0.0 || !*(_DWORD *)(LODWORD(v13) + 8) || v11 && singlePassDetailinga != 1 )
  {
    curr_texturea = singlePassDetailinga || !v11;
  }
  else
  {
    v9 = 5;
    v10 = 6;
    surfacea = 1;
    singlePassDetailinga = 0;
    curr_texturea = 0;
  }
  v14 = zfuncVal;
  RenderDeviceD3D::SetStageTexture((RenderDeviceD3D *)v4, 0, new_d3dtss_texture);
  RenderDeviceD3D::SetAlphaTestEnable((RenderDeviceD3D *)v4, singlePassDetailinga);
  RenderDeviceD3D::SetAlphaTestRef((RenderDeviceD3D *)v4, testRef);
  RenderDeviceD3D::SetAlphaTestFunction((RenderDeviceD3D *)v4, ALPHATESTFUNC_GREATEREQUAL);
  RenderDeviceD3D::SetBlendFunction((RenderDeviceD3D *)v4, v9, v10, BLENDOP_ADD);
  RenderDeviceD3D::SetAlphaBlendEnable((RenderDeviceD3D *)v4, surfacea);
  if ( !LOBYTE(v4[2].m_GState.FrameBufferBloomRGBAmount.r) )
    RenderDeviceD3D::SetDepthBufferMode((RenderDeviceD3D *)v4, v14, curr_texturea);
  if ( !RenderDeviceD3D::GetFFFogEnable((RenderDeviceD3D *)v4) || Render::curr_surface_type & 0x10000 )
  {
    RenderDeviceD3D::SetFFFogAlphaDisabled((RenderDeviceD3D *)v4, 1);
    result = curr_alpha;
  }
  else
  {
    RenderDeviceD3D::SetFFFogAlphaDisabled((RenderDeviceD3D *)v4, 0);
    result = curr_alpha;
  }
  return result;
}
// 81EFC0: using guessed type struct RGBColor Render::diffuse;
// 81EFC4: using guessed type float flt_81EFC4;
// 81EFC8: using guessed type float flt_81EFC8;
// 820D8C: using guessed type __int32 D3DPolyRender::s_256AlphaTestRef;
// 820D90: using guessed type __int32 D3DPolyRender::s_ddsAlphaTestRef;
// 820D94: using guessed type __int32 curr_alpha;
// 820D98: using guessed type __int32 curr_color;
// 866334: using guessed type int Render::useSunlight;
// 866370: using guessed type struct CSurface *Render::curr_surface;
// 866374: using guessed type unsigned __int32 Render::curr_surface_type;
// 866378: using guessed type int Render::curr_texture_is_set;
// 8663F8: using guessed type struct RGBColor Render::luminosity;
// 8663FC: using guessed type float flt_8663FC;
// 866400: using guessed type float flt_866400;

//----- (0059C8B0) --------------------------------------------------------  // acclient.c:454578
void __cdecl calc_point_light(CUSTOM_D3D_VERTEX2 *vert, float *rval, float *gval, float *bval, LIGHTINFO *local_light_info)
{
  CUSTOM_D3D_VERTEX2 *v5; // edx@1
  LIGHTINFO *v6; // ecx@1
  double v7; // st7@1
  double v8; // st6@1
  long double v9; // st5@1
  double v10; // st4@2
  double v11; // st7@4
  double v12; // st7@6
  double v13; // st6@6
  double v14; // st6@8
  double v15; // st7@10
  float range; // [sp+0h] [bp-1Ch]@1
  float diff; // [sp+4h] [bp-18h]@1
  float verta; // [sp+20h] [bp+4h]@1
  float local_light_infoa; // [sp+30h] [bp+14h]@1

  v5 = vert;
  v6 = local_light_info;
  diff = local_light_info->offset.m_fOrigin.x - vert->x;
  v7 = local_light_info->offset.m_fOrigin.y - vert->y;
  v8 = local_light_info->offset.m_fOrigin.z - vert->z;
  v9 = v8 * v8 + v7 * v7 + diff * diff;
  local_light_infoa = v9;
  verta = sqrt(v9);
  range = v6->falloff * static_light_factor;
  if ( verta < (double)range )
  {
    v10 = ((0.75 + 0.75 - 1.0) * verta + v5->nz * v8 + v5->ny * v7 + v5->nx * diff) * (1.0 / (0.75 + 0.75));
    if ( v10 > 0.0 )
    {
      if ( local_light_infoa <= 1.0 )
        v11 = v10 / verta;
      else
        v11 = v10 / (local_light_infoa * verta);
      v12 = v11 * ((1.0 - verta / range) * v6->intensity);
      v13 = v12 * v6->color.r;
      if ( v13 > v6->color.r )
        v13 = v6->color.r;
      *rval = v13 + *rval;
      v14 = v12 * v6->color.g;
      if ( v14 > v6->color.g )
        v14 = v6->color.g;
      *gval = v14 + *gval;
      v15 = v12 * v6->color.b;
      if ( v15 > v6->color.b )
        v15 = v6->color.b;
      *bval = v15 + *bval;
    }
  }
}

//----- (0059CA10) --------------------------------------------------------  // acclient.c:454632
char __cdecl D3DPolyRender::RenderMeshSubset(int subsetNum, CSurface *surface, bool detail_surface_is_set, bool overrideClipmapSetting, MeshBuffer *meshBuffer)
{
  MeshBuffer *v5; // ebp@1
  signed int v6; // esi@7
  CSurface *v7; // ebx@9
  float v8; // ecx@20
  int v9; // eax@22
  float v10; // edx@22
  float v11; // eax@24
  float v12; // ecx@24
  ID3DXMesh *v13; // esi@26
  char i; // bl@27
  ID3DXMesh *v15; // esi@36
  char j; // bl@37
  RenderDeviceD3D *v17; // esi@41
  RenderMesh *v18; // ecx@42
  RenderMesh *v19; // ecx@44
  float v20; // eax@51
  int v21; // eax@53
  RenderDeviceD3D *acDev; // [sp+28h] [bp-58h]@1
  int trydetailing; // [sp+2Ch] [bp-54h]@1
  Matrix4 matUVAnim; // [sp+40h] [bp-40h]@24
  MeshBuffer *meshBuffera; // [sp+94h] [bp+14h]@7

  v5 = meshBuffer;
  acDev = (RenderDeviceD3D *)RenderDevice::render_device;
  trydetailing = 1;
  if ( meshBuffer->detailTilingFactorSet == 0.0 )
    trydetailing = 0;
  if ( trysinglepass_2
    && RenderDevice::render_device->m_caps.bCanDoSinglePassDetailing
    && detail_surface_is_set
    && trydetailing )
  {
    v6 = 1;
    meshBuffera = (MeshBuffer *)1;
  }
  else
  {
    meshBuffera = 0;
    v6 = 0;
  }
  v7 = surface;
  D3DPolyRender::SetSurface(surface, v5->isStippledOrAlphaedMask[subsetNum] & 1, v6 != 0, overrideClipmapSetting);
  if ( v6 )
  {
    ACRender::SetDetailSurfaceInternal(1);
    if ( v5->detailTilingFactorSet != Render::curr_detail_tiling )
      D3DPolyRender::SetDetailTiling(v5, Render::curr_detail_tiling);
  }
  RenderDeviceD3D::SetCullMode(acDev, (CullModeType)((override_cull_state == 0) + 1));
  if ( !override_light_state || LOBYTE(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.r) )
    RenderDeviceD3D::SetFFLighting(acDev, 1);
  else
    RenderDeviceD3D::SetFFLighting(acDev, 0);
  if ( v5->burnedInStaticLights >= 0 )
  {
    if ( surface->luminosity > 0.0 )
    {
      v8 = RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g;
      if ( v8 == 0.0 )
      {
        tmpmaterial.Emissive.g = surface->luminosity;
        tmpmaterial.Emissive.r = tmpmaterial.Emissive.g;
        tmpmaterial.Emissive.b = tmpmaterial.Emissive.g;
        LODWORD(tmpmaterial.Emissive.a) = 1065353216;
        (*(void (__stdcall **)(_DWORD, _D3DMATERIAL9 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                       + 196))(
          LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
          &tmpmaterial);
      }
      else
      {
        v9 = LODWORD(v8) + 60;
        LODWORD(tmpmaterial.Emissive.r) = *(_DWORD *)(LODWORD(v8) + 60);
        LODWORD(tmpmaterial.Emissive.g) = *(_DWORD *)(LODWORD(v8) + 64);
        LODWORD(tmpmaterial.Emissive.b) = *(_DWORD *)(LODWORD(v8) + 68);
        LODWORD(tmpmaterial.Emissive.a) = *(_DWORD *)(LODWORD(v8) + 72);
        v10 = surface->luminosity;
        *(float *)v9 = v10;
        *(float *)(v9 + 4) = v10;
        *(float *)(v9 + 8) = v10;
        *(_DWORD *)(v9 + 12) = 1065353216;
        (*(void (__stdcall **)(_DWORD, int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 196))(
          LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
          LODWORD(v8) + 12);
      }
    }
  }
  else
  {
    RenderDeviceD3D::SetFFEmissiveColorSource(acDev, FromVertex);
    if ( !LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) )
    {
      tmpmaterial.Ambient.g = diffuseVal;
      LODWORD(tmpmaterial.Ambient.a) = 1065353216;
      tmpmaterial.Ambient.r = diffuseVal;
      tmpmaterial.Ambient.b = diffuseVal;
      tmpmaterial.Diffuse.g = diffuseVal;
      tmpmaterial.Diffuse.r = diffuseVal;
      tmpmaterial.Diffuse.b = diffuseVal;
      LODWORD(tmpmaterial.Diffuse.a) = 1065353216;
      (*(void (__stdcall **)(_DWORD, _D3DMATERIAL9 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                     + 196))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        &tmpmaterial);
      RenderDeviceD3D::SetFFDiffuseColorSource(acDev, 0);
      RenderDeviceD3D::SetFFAmbientColorSource(acDev, 0);
    }
  }
  if ( v5->m_bUseUVAnimation )
  {
    v11 = v5->m_vUVDelta.u;
    v12 = v5->m_vUVDelta.v;
    LODWORD(matUVAnim._14) = 0;
    LODWORD(matUVAnim._13) = 0;
    LODWORD(matUVAnim._12) = 0;
    LODWORD(matUVAnim._24) = 0;
    LODWORD(matUVAnim._23) = 0;
    LODWORD(matUVAnim._21) = 0;
    LODWORD(matUVAnim._34) = 0;
    LODWORD(matUVAnim._43) = 0;
    LODWORD(matUVAnim._42) = 0;
    LODWORD(matUVAnim._41) = 0;
    LODWORD(matUVAnim._44) = 1065353216;
    LODWORD(matUVAnim._33) = 1065353216;
    LODWORD(matUVAnim._22) = 1065353216;
    LODWORD(matUVAnim._11) = 1065353216;
    matUVAnim._31 = v11;
    matUVAnim._32 = v12;
    (*(void (__stdcall **)(_DWORD, signed int, Matrix4 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                         + 176))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      16,
      &matUVAnim);
    RenderDeviceD3D::SetStageFFTextureTransformFlags((RenderDeviceD3D *)RenderDevice::render_device, 0, 3u);
  }
  else
  {
    RenderDeviceD3D::SetStageFFTextureTransformFlags((RenderDeviceD3D *)RenderDevice::render_device, 0, 0);
  }
  v13 = v5->pMesh;
  if ( v5->pMesh )
  {
    for ( i = 1;
          ((int (__stdcall *)(ID3DXMesh *, int))v13->vfptr[1].QueryInterface)(v13, subsetNum) == -2005532292;
          i = GraphicsResource::DiscardResourceBytes(0xFFFFu) )
    {
      if ( !i )
        break;
    }
    v7 = surface;
  }
  else
  {
    v18 = v5->pRenderMesh;
    if ( v18 )
      RenderMesh::DrawSubset(v18, subsetNum);
  }
  if ( detail_surface_is_set && !meshBuffera && trydetailing )
  {
    ACRender::SetDetailSurfaceInternal(0);
    RenderDeviceD3D::SetStageFFTexCoordIndex(acDev, 0, 1u);
    if ( v5->detailTilingFactorSet != Render::curr_detail_tiling )
      D3DPolyRender::SetDetailTiling(v5, Render::curr_detail_tiling);
    v15 = v5->pMesh;
    if ( v5->pMesh )
    {
      for ( j = 1;
            ((int (__stdcall *)(ID3DXMesh *, int))v15->vfptr[1].QueryInterface)(v15, subsetNum) == -2005532292;
            j = GraphicsResource::DiscardResourceBytes(0xFFFFu) )
      {
        if ( !j )
          break;
      }
      v7 = surface;
      goto LABEL_41;
    }
    v19 = v5->pRenderMesh;
    if ( !v19 )
    {
LABEL_41:
      v17 = acDev;
      RenderDeviceD3D::SetStageFFTexCoordIndex(acDev, 0, 0);
      goto LABEL_47;
    }
    RenderMesh::DrawSubset(v19, subsetNum);
    v17 = acDev;
    RenderDeviceD3D::SetStageFFTexCoordIndex(acDev, 0, 0);
  }
  else
  {
    v17 = acDev;
  }
LABEL_47:
  if ( v5->burnedInStaticLights >= 0 )
  {
    if ( v7->luminosity > 0.0 )
    {
      v20 = RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g;
      if ( v20 == 0.0 )
      {
        RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, 0, 1);
      }
      else
      {
        v21 = LODWORD(v20) + 60;
        *(_DWORD *)v21 = LODWORD(tmpmaterial.Emissive.r);
        *(_DWORD *)(v21 + 4) = LODWORD(tmpmaterial.Emissive.g);
        *(_DWORD *)(v21 + 8) = LODWORD(tmpmaterial.Emissive.b);
        *(_DWORD *)(v21 + 12) = LODWORD(tmpmaterial.Emissive.a);
      }
    }
  }
  else
  {
    RenderDeviceD3D::SetFFEmissiveColorSource(v17, 0);
    if ( !LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) )
    {
      RenderDeviceD3D::SetFFDiffuseColorSource(v17, FromVertex);
      RenderDeviceD3D::SetFFAmbientColorSource(v17, FromVertex);
      RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, 0, 1);
    }
  }
  if ( v5->m_bUseUVAnimation )
    RenderDeviceD3D::SetStageFFTextureTransformFlags((RenderDeviceD3D *)RenderDevice::render_device, 0, 0);
  return 1;
}

//----- (0059CF30) --------------------------------------------------------  // acclient.c:454862
char __thiscall SmartArray<_D3DXATTRIBUTERANGE,0>::grow(SmartArray<_D3DXATTRIBUTERANGE,0> *this, unsigned int i_nSize)
{
  SmartArray<_D3DXATTRIBUTERANGE,0> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // ebp@5
  int v6; // ecx@7
  int v7; // eax@8
  unsigned int v8; // edx@8
  const void *v9; // esi@9
  void *v10; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<unsigned char,0>::Reset(this);
      return 1;
    }
    v5 = operator new[](20 * i_nSize);
    if ( v5 )
    {
      if ( v2->m_data )
      {
        v6 = v2->m_num - 1;
        if ( v6 >= 0 )
        {
          v7 = v6;
          v8 = v2->m_num;
          do
          {
            v9 = &v2->m_data[v7];
            v10 = (char *)v5 + v7 * 20;
            --v7;
            --v8;
            qmemcpy(v10, v9, 0x14u);
          }
          while ( v8 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (_D3DXATTRIBUTERANGE *)v5;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0059CFE0) --------------------------------------------------------  // acclient.c:454917
char __cdecl D3DPolyRender::SetStaticLightingVertexColors(MeshBuffer *pMeshBuffer, Position *pos)
{
  MeshBuffer *v2; // edi@1
  char result; // al@2
  char v4; // al@4
  ID3DXMesh *v5; // esi@7
  IUnknownVtbl *v6; // eax@7
  int v7; // ebx@7
  int v8; // edi@10
  int v9; // ebx@11
  LIGHTINFO *v10; // esi@12
  CUSTOM_D3D_VERTEX2 *v11; // esi@12
  double v12; // st4@14
  double v13; // st7@15
  int v14; // eax@31
  float rval; // [sp+10h] [bp-80h]@11
  float gval; // [sp+14h] [bp-7Ch]@11
  float bval; // [sp+18h] [bp-78h]@11
  CUSTOM_D3D_VERTEX2 *verts; // [sp+1Ch] [bp-74h]@7
  int v19; // [sp+20h] [bp-70h]@10
  ID3DXMesh *pMesh; // [sp+24h] [bp-6Ch]@7
  LIGHTINFO local_light_info; // [sp+28h] [bp-68h]@12

  v2 = pMeshBuffer;
  if ( pMeshBuffer->meshFVF == 594 )
  {
    if ( onlyOnce
      && ((v4 = pMeshBuffer->burnedInStaticLights, v4 >= 0) || (v4 & 0x7F) == Render::world_lights.num_static_lights) )
    {
      result = 1;
    }
    else
    {
      v6 = pMeshBuffer->pMesh->vfptr;
      pMesh = pMeshBuffer->pMesh;
      v5 = pMesh;
      v7 = v6[1].Release((IUnknown *)pMesh);
      if ( v5->vfptr[5].QueryInterface((IUnknown *)v5, 0, (void **)&verts) >= 0 )
      {
        if ( v7 > 0 )
        {
          v8 = 0;
          v19 = v7;
          do
          {
            v9 = 0;
            rval = 0.0;
            gval = 0.0;
            bval = 0.0;
            if ( Render::world_lights.num_static_lights <= 0 )
            {
              v11 = verts;
            }
            else
            {
              do
              {
                v10 = &Render::world_lights.sorted_static_lights[v9]->info;
                LODWORD(local_light_info.offset.qw) = 1065353216;
                LODWORD(local_light_info.offset.qx) = 0;
                LODWORD(local_light_info.offset.qy) = 0;
                LODWORD(local_light_info.offset.qz) = 0;
                LODWORD(local_light_info.offset.m_fOrigin.x) = 0;
                LODWORD(local_light_info.offset.m_fOrigin.y) = 0;
                LODWORD(local_light_info.offset.m_fOrigin.z) = 0;
                Frame::cache(&local_light_info.offset);
                LIGHTINFO::convert_to_local(&local_light_info, v10, &pos->frame);
                v11 = verts;
                if ( local_light_info.type )
                {
                  if ( local_light_info.type == 1 )
                  {
                    v12 = local_light_info.offset.m_fOrigin.z * verts[v8].nz
                        + local_light_info.offset.m_fOrigin.x * verts[v8].nx
                        + local_light_info.offset.m_fOrigin.y * verts[v8].ny;
                    if ( v12 > 0.0 )
                    {
                      v13 = v12 * local_light_info.intensity;
                      rval = local_light_info.color.r * v13 + rval;
                      gval = local_light_info.color.g * v13 + gval;
                      bval = local_light_info.color.b * v13 + bval;
                    }
                  }
                }
                else
                {
                  calc_point_light(&verts[v8], &rval, &gval, &bval, &local_light_info);
                }
                ++v9;
              }
              while ( v9 < Render::world_lights.num_static_lights );
              if ( rval >= 0.0 )
              {
                if ( rval > 1.0 )
                  rval = 1.0;
              }
              else
              {
                rval = 0.0;
              }
              if ( gval >= 0.0 )
              {
                if ( gval > 1.0 )
                  gval = 1.0;
              }
              else
              {
                gval = 0.0;
              }
              if ( bval >= 0.0 )
              {
                if ( bval > 1.0 )
                  bval = 1.0;
              }
              else
              {
                bval = 0.0;
              }
            }
            v14 = v19;
            v11[v8].diffuse = (unsigned __int8)(unsigned __int64)(bval * 255.0) | (((unsigned __int8)(unsigned __int64)(gval * 255.0) | (((unsigned __int8)(unsigned __int64)(rval * 255.0) | 0xFFFFFF00) << 8)) << 8);
            ++v8;
            v19 = v14 - 1;
          }
          while ( v14 != 1 );
          v2 = pMeshBuffer;
          v5 = pMesh;
        }
        v5->vfptr[5].AddRef((IUnknown *)v5);
        v2->burnedInStaticLights = (Render::world_lights.num_static_lights & 0x7F) + -128;
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0059D2E0) --------------------------------------------------------  // acclient.c:455063
char __cdecl D3DPolyRender::FlushAlphaList(float threshholdVal)
{
  char v1; // bl@1
  unsigned __int16 v2; // bp@3
  double v3; // st7@5
  char result; // al@7
  signed int v5; // edi@9
  Matrix4 *v6; // esi@10
  signed int v7; // edi@16
  Matrix4 *v8; // esi@17
  Matrix4 worldMatrixSave; // [sp+14h] [bp-40h]@9

  v1 = 1;
  if ( maxAlphaMeshCountClip < D3DPolyRender::alphaedMeshCountClip )
    maxAlphaMeshCountClip = D3DPolyRender::alphaedMeshCountClip;
  v2 = D3DPolyRender::alphaedMeshCountAlpha;
  if ( maxAlphaMeshCountAlpha < D3DPolyRender::alphaedMeshCountAlpha )
    maxAlphaMeshCountAlpha = D3DPolyRender::alphaedMeshCountAlpha;
  v3 = threshholdVal * 3000.0;
  if ( (double)D3DPolyRender::alphaedMeshCountClip >= v3 || (double)D3DPolyRender::alphaedMeshCountAlpha >= v3 )
  {
    if ( D3DPolyRender::alphaedMeshCountClip )
    {
      qmemcpy(&worldMatrixSave, &RenderDevice::render_device->m_GState, sizeof(worldMatrixSave));
      v5 = 0;
      if ( (signed int)D3DPolyRender::alphaedMeshCountClip > 0 )
      {
        v6 = &m;
        do
        {
          if ( LOBYTE(v6[1]._11) )
          {
            RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, v6);
            RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, LODWORD(v6[-1]._44), 0);
          }
          v1 &= D3DPolyRender::RenderMeshSubset(
                  LODWORD(v6[-1]._42),
                  LODWORD(v6[-1]._43),
                  0,
                  BYTE1(v6[1]._11),
                  LODWORD(v6[-1]._41));
          ++v5;
          v6 = (Matrix4 *)((char *)v6 + 84);
        }
        while ( v5 < D3DPolyRender::alphaedMeshCountClip );
      }
      RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &worldMatrixSave);
      v2 = D3DPolyRender::alphaedMeshCountAlpha;
    }
    D3DPolyRender::alphaedMeshCountClip = 0;
    if ( v2 )
    {
      qmemcpy(&worldMatrixSave, &RenderDevice::render_device->m_GState, sizeof(worldMatrixSave));
      v7 = 0;
      if ( v2 )
      {
        v8 = &stru_8AF380;
        do
        {
          if ( LOBYTE(v8[1]._11) )
          {
            RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, v8);
            RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, LODWORD(v8[-1]._44), 0);
          }
          v1 &= D3DPolyRender::RenderMeshSubset(
                  LODWORD(v8[-1]._42),
                  LODWORD(v8[-1]._43),
                  0,
                  BYTE1(v8[1]._11),
                  LODWORD(v8[-1]._41));
          ++v7;
          v8 = (Matrix4 *)((char *)v8 + 84);
        }
        while ( v7 < D3DPolyRender::alphaedMeshCountAlpha );
      }
      RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &worldMatrixSave);
    }
    result = v1;
    D3DPolyRender::alphaedMeshCountAlpha = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8719AC: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountClip;
// 8719B0: using guessed type unsigned __int16 D3DPolyRender::alphaedMeshCountAlpha;

//----- (0059D4A0) --------------------------------------------------------  // acclient.c:455153
char __cdecl D3DPolyRender::DrawMesh(int num_surfaces, CSurface **surfaces, MeshBuffer *meshBuffer, bool isEnvCell)
{
  MeshBuffer *v4; // edi@1
  char v5; // bl@1
  int v6; // esi@1
  char v7; // al@13
  unsigned __int8 v9; // al@17
  char v10; // al@19
  float v11; // eax@25
  bool bFirstDelayedAlpha; // [sp+Ch] [bp-Ch]@1
  char clip; // [sp+14h] [bp-4h]@18
  bool meshBuffera; // [sp+24h] [bp+Ch]@1

  v4 = meshBuffer;
  (*(void (__stdcall **)(_DWORD, unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                              + 356))(
    LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
    meshBuffer->meshFVF);
  v5 = 1;
  v6 = 0;
  meshBuffera = 1;
  for ( bFirstDelayedAlpha = 1; v6 < num_surfaces; ++v6 )
  {
    if ( skipNoTexture && !(surfaces[v6]->type & 6) )
    {
      if ( RenderDeviceD3D::ObjBuildingOrBuildingPart || isEnvCell )
        continue;
      skipNoTexture = 1;
    }
    if ( !LOBYTE(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.r)
      && D3DPolyRender::s_AlphaDelayMask
      && !Render::curr_detail_surface )
    {
      if ( byte_81EF96 && v4->isStippledOrAlphaedMask[v6] & 8 )
      {
        v5 &= D3DPolyRender::AddMeshToAlphaList(v4, v6, surfaces[v6], meshBuffera, 1, 1);
        meshBuffera = 0;
      }
      else
      {
        v9 = v4->isStippledOrAlphaedMask[v6];
        if ( v9 & (unsigned __int8)D3DPolyRender::s_AlphaDelayMask )
        {
          clip = (v9 >> 3) & 1;
          if ( clip )
            v10 = D3DPolyRender::AddMeshToAlphaList(v4, v6, surfaces[v6], meshBuffera, 0, clip);
          else
            v10 = D3DPolyRender::AddMeshToAlphaList(v4, v6, surfaces[v6], bFirstDelayedAlpha, 0, 0);
          v5 &= v10;
          if ( clip )
            meshBuffera = 0;
          else
            bFirstDelayedAlpha = 0;
          continue;
        }
        if ( D3DPolyRender::s_AlphaDelayMask & 4 )
        {
          v11 = RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g;
          if ( v11 != 0.0 )
          {
            if ( *(_DWORD *)(LODWORD(v11) + 8) )
            {
              v7 = D3DPolyRender::AddMeshToAlphaList(v4, v6, surfaces[v6], bFirstDelayedAlpha, 0, 0);
              bFirstDelayedAlpha = 0;
              goto LABEL_14;
            }
          }
        }
      }
    }
    Render::CalcObjectMatrix();
    v7 = D3DPolyRender::RenderMeshSubset(v6, surfaces[v6], Render::curr_detail_surface != 0, 0, v4);
LABEL_14:
    v5 &= v7;
  }
  return v5;
}
// 81EF96: using guessed type char byte_81EF96;
// 820D88: using guessed type unsigned __int32 D3DPolyRender::s_AlphaDelayMask;
// 8ED3C4: using guessed type int RenderDeviceD3D::ObjBuildingOrBuildingPart;

//----- (0059D650) --------------------------------------------------------  // acclient.c:455235
__int32 __cdecl D3DPolyRender::SetSurface(CPolygon *p, Sidedness side, int singlePassDetailing)
{
  signed int v3; // edx@1
  char v4; // bl@1
  int v5; // ecx@2
  char *v6; // eax@4

  v3 = 0;
  v4 = p->stippling;
  if ( side )
  {
    v5 = p->neg_surface;
    if ( v4 & 2 )
      v3 = 1;
    v6 = p->neg_uv_indices;
  }
  else
  {
    v5 = p->pos_surface;
    if ( v4 & 1 )
      v3 = 1;
    v6 = p->pos_uv_indices;
  }
  Render::UVIndexTbl = v6;
  return D3DPolyRender::SetSurface(Render::curr_surfaces[v5], v3 != 0, singlePassDetailing != 0, 0);
}
// 86637C: using guessed type char *Render::UVIndexTbl;

//----- (0059D6B0) --------------------------------------------------------  // acclient.c:455264
char __stdcall D3DPolyRender::CreateDxDiagReportFile(PStringBase<char> *o_fileLocation)
{
  char v2; // bl@1
  _PROCESS_INFORMATION piInfo; // [sp+Ch] [bp-25Ch]@1
  _STARTUPINFOA siInfo; // [sp+1Ch] [bp-24Ch]@1
  char tmpPath[260]; // [sp+60h] [bp-208h]@1
  char dxdiagCommand[260]; // [sp+164h] [bp-104h]@1

  GetTempPathA(0x104u, tmpPath);
  PStringBase<char>::sprintf(o_fileLocation, "%s%s", tmpPath, "dxdiag.txt");
  __snprintf(dxdiagCommand, 0x104u, "dxdiag.exe %hs", o_fileLocation->m_charbuffer);
  memset(&siInfo, 0, sizeof(siInfo));
  piInfo.hProcess = 0;
  piInfo.hThread = 0;
  piInfo.dwProcessId = 0;
  piInfo.dwThreadId = 0;
  v2 = 0;
  siInfo.cb = 68;
  if ( CreateProcessA(0, dxdiagCommand, 0, 0, 0, 0x4000020u, 0, 0, &siInfo, &piInfo) )
  {
    if ( !WaitForSingleObject(piInfo.hProcess, 0xEA60u) )
      v2 = 1;
    CloseHandle(piInfo.hProcess);
    CloseHandle(piInfo.hThread);
  }
  return v2;
}

//----- (0059D790) --------------------------------------------------------  // acclient.c:455293
char __cdecl D3DPolyRender::DrawMesh(CGfxObj *obj, MeshBuffer *meshBuffer)
{
  char result; // al@2

  if ( gfxobjs )
    result = D3DPolyRender::DrawMesh(obj->num_surfaces, Render::curr_surfaces, meshBuffer, 0);
  else
    result = 1;
  return result;
}

//----- (0059D7C0) --------------------------------------------------------  // acclient.c:455305
void __cdecl D3DPolyRender::DrawPolyInternal(CPolygon *p)
{
  int v1; // edi@7
  int v2; // ecx@9
  signed int v3; // eax@9
  __int32 v4; // esi@11
  signed int v5; // ebx@20
  char *v6; // ecx@21
  char *v7; // esi@21
  CVertex *v8; // edi@22
  int v9; // edx@22
  char v10; // al@22
  Vec2Dscreen *v11; // eax@23
  bool v12; // zf@24
  unsigned int v13; // eax@25
  signed int v14; // edx@29
  char *v15; // edi@30
  char *v16; // eax@30
  CVertex *v17; // ecx@31
  double v18; // st7@36
  int v19; // eax@40
  signed int v20; // ebx@44
  signed int v21; // edi@44
  char *v22; // esi@45
  char v23; // al@46
  Vec2Dscreen *v24; // eax@47

  if ( !skipPolys && Render::curr_surfaces[p->pos_surface]->type & 6 )
  {
    Render::CalcObjectMatrix();
    v1 = trysinglepass
      && RenderDevice::render_device->m_caps.bCanDoSinglePassDetailing
      && Render::curr_detail_surface
      && trydetailing;
    v2 = p->pos_surface;
    v3 = 0;
    if ( p->stippling & 1 )
      v3 = 1;
    Render::UVIndexTbl = p->pos_uv_indices;
    v4 = D3DPolyRender::SetSurface(Render::curr_surfaces[v2], v3 != 0, v1 != 0, 0);
    if ( override_cull_state_0 || p->sides_type == 1 )
      RenderDeviceD3D::SetCullMode((RenderDeviceD3D *)RenderDevice::render_device, CULLMODE_NONE);
    else
      RenderDeviceD3D::SetCullMode((RenderDeviceD3D *)RenderDevice::render_device, CULLMODE_CW);
    if ( !override_light_state_0 || LOBYTE(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.r) )
      RenderDeviceD3D::SetFFLighting((RenderDeviceD3D *)RenderDevice::render_device, 1);
    else
      RenderDeviceD3D::SetFFLighting((RenderDeviceD3D *)RenderDevice::render_device, 0);
    if ( v1 )
    {
      ACRender::SetDetailSurfaceInternal(1);
      (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                + 356))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        594);
      v5 = 0;
      if ( p->num_pts )
      {
        v6 = Render::UVIndexTbl;
        v7 = (char *)&v_1[0].y;
        do
        {
          v8 = p->vertices[v5];
          *((_DWORD *)v7 - 1) = LODWORD(v8->x);
          *(_DWORD *)v7 = LODWORD(v8->y);
          *((_DWORD *)v7 + 1) = LODWORD(v8->z);
          *((_DWORD *)v7 + 2) = v8->reserve6;
          *((_DWORD *)v7 + 3) = v8->reserve7;
          v9 = noFadeDetail;
          *((_DWORD *)v7 + 4) = v8->reserve8;
          v10 = -1;
          if ( !v9 )
          {
            v11 = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v8, 0);
            v10 = ACRender::get_alpha_for_z(v11->zw);
            v6 = Render::UVIndexTbl;
          }
          v12 = Render::curr_texture_is_set == 0;
          *((_DWORD *)v7 + 5) = ((unsigned __int8)v10 << 24) | 0xFFFFFF;
          if ( !v12 )
          {
            v13 = v8->reserve5;
            if ( v13 )
            {
              *((float *)v7 + 6) = Render::TextureUSize * *(float *)(v13 + 8 * v6[v5]);
              *((float *)v7 + 7) = Render::TextureVSize * *(float *)(v8->reserve5 + 8 * v6[v5] + 4);
              *((float *)v7 + 8) = Render::curr_detail_tiling * *((float *)v7 + 6);
              *((float *)v7 + 9) = Render::curr_detail_tiling * *((float *)v7 + 7);
            }
          }
          ++v5;
          v7 += 44;
        }
        while ( v5 < p->num_pts );
      }
      RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLEFAN, p->num_pts - 2, v_1, 0x2Cu);
    }
    else
    {
      (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                + 356))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        338);
      v14 = 0;
      if ( p->num_pts )
      {
        v15 = Render::UVIndexTbl;
        v16 = (char *)&v_0[0].y;
        do
        {
          v17 = p->vertices[v14];
          *((_DWORD *)v16 - 1) = LODWORD(v17->x);
          *(_DWORD *)v16 = LODWORD(v17->y);
          *((_DWORD *)v16 + 1) = LODWORD(v17->z);
          *((_DWORD *)v16 + 2) = v17->reserve6;
          *((_DWORD *)v16 + 3) = v17->reserve7;
          *((_DWORD *)v16 + 4) = v17->reserve8;
          *((_DWORD *)v16 + 5) = (v4 << 24) | 0xFFFFFF;
          if ( Render::curr_detail_surface && trydetailing && v4 != 255 )
            v4 = 255;
          if ( Render::curr_texture_is_set )
          {
            v18 = Render::TextureUSize * *(float *)(v17->reserve5 + 8 * v15[v14]);
            v15 = Render::UVIndexTbl;
            *((float *)v16 + 6) = v18;
            *((float *)v16 + 7) = Render::TextureVSize * *(float *)(v17->reserve5 + 8 * v15[v14] + 4);
          }
          ++v14;
          v16 += 36;
        }
        while ( v14 < p->num_pts );
      }
      RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLEFAN, p->num_pts - 2, v_0, 0x24u);
      v19 = trydetailing && !(Render::curr_surface->type & 4);
      if ( Render::curr_detail_surface )
      {
        if ( v19 )
        {
          ACRender::SetDetailSurfaceInternal(0);
          v20 = 0;
          v21 = 0;
          if ( p->num_pts )
          {
            v22 = (char *)&v_0[0].tu;
            do
            {
              v23 = -1;
              if ( noFadeDetail
                || (v24 = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)p->vertices[v21], 0),
                    (v23 = ACRender::get_alpha_for_z(v24->zw)) != 0) )
                v20 = 1;
              *((_DWORD *)v22 - 1) = *((_DWORD *)v22 - 1) & 0xFFFFFF | ((unsigned __int8)v23 << 24);
              if ( Render::curr_texture_is_set )
              {
                *(float *)v22 = Render::curr_detail_tiling * *(float *)v22;
                *((float *)v22 + 1) = Render::curr_detail_tiling * *((float *)v22 + 1);
              }
              ++v21;
              v22 += 36;
            }
            while ( v21 < p->num_pts );
            if ( v20 )
              RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLEFAN, p->num_pts - 2, v_0, 0x24u);
          }
        }
      }
    }
  }
}
// 81ECBC: using guessed type float Render::TextureUSize;
// 81ECC0: using guessed type float Render::TextureVSize;
// 866370: using guessed type struct CSurface *Render::curr_surface;
// 866378: using guessed type int Render::curr_texture_is_set;
// 86637C: using guessed type char *Render::UVIndexTbl;

//----- (0059DBA0) --------------------------------------------------------  // acclient.c:455481
void D3DPolyRender::polyListFinishInternal()
{
  CPolygon **v1; // esi@1

  v1 = (CPolygon **)&Render::PolyList;
  if ( (unsigned int)Render::PolyNext > (unsigned int)&Render::PolyList )
  {
    do
    {
      D3DPolyRender::DrawPolyInternal(*v1);
      v1 += 2;
    }
    while ( (unsigned int)v1 < (unsigned int)Render::PolyNext );
  }
}
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;

//----- (0059DBD0) --------------------------------------------------------  // acclient.c:455499
char __thiscall D3DPolyRender::ResetDynamicBuffers(D3DPolyRender *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // ebx@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ecx@1
  RenderVertexStreamD3D *v5; // esi@2
  signed int v6; // edi@3
  unsigned int v7; // ecx@3
  unsigned int v8; // ebp@6
  unsigned int v9; // eax@6
  int v10; // edi@8
  RenderIndexStreamD3D *v11; // ecx@16
  D3DPolyRender *v13; // [sp+10h] [bp-1Ch]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *Iter; // [sp+14h] [bp-18h]@1
  HashTableData<unsigned long,HeritageGroup_CG> **Iter_4; // [sp+18h] [bp-14h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+20h] [bp-Ch]@1

  v13 = this;
  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_DynamicVertexStreamHash.m_intrusiveTable,
         &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  Iter = v1->m_currHashTable;
  Iter_4 = v1->m_currBucket;
  if ( v2 )
  {
    do
    {
LABEL_2:
      v5 = (RenderVertexStreamD3D *)v2->m_data.vfptr;
      if ( v5 )
      {
        v6 = v5->m_nIdealVertexCount;
        v7 = v5->m_nNumVertices;
        if ( (unsigned int)v6 > 0xFFFF )
          v6 = 0xFFFF;
        if ( v6 > v7 )
        {
          v8 = v5->m_VertexFormatInfo.format;
          v9 = ((v6 - v7) >> 1) + v6 - v7;
          if ( v9 < 0x1000 )
            v9 = 4096;
          v10 = v9 + v6;
          if ( (unsigned int)v10 > 0xFFFF )
            v10 = 0xFFFF;
          ((void (__thiscall *)(_DWORD))v5->vfptr[1].CopyInto)(v2->m_data.vfptr);
          if ( !(unsigned __int8)((int (__thiscall *)(RenderVertexStreamD3D *, int, _DWORD, signed int))v5->vfptr[1].__vecDelDtor)(
                                   v5,
                                   v10,
                                   v8,
                                   1) )
            return 0;
        }
        RenderVertexStreamD3D::ResetVertexIndices(v5);
        v3 = Iter;
        v4 = Iter_4;
      }
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    while ( 1 )
    {
      ++v4;
      Iter_4 = v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v2 = *v4;
        if ( *v4 )
          goto LABEL_2;
        break;
      }
    }
  }
  v11 = v13->m_pDynamicIndexStream;
  if ( v11 )
    RenderIndexStreamD3D::NotifyFrameChanged(v11);
  return 1;
}

//----- (0059DCD0) --------------------------------------------------------  // acclient.c:455584
void __thiscall RenderDevice::RenderDevice(RenderDevice *this)
{
  RenderDevice *v1; // esi@1

  v1 = this;
  this->vfptr = (RenderDeviceVtbl *)&RenderDevice::vftable;
  this->m_presentation.hRenderWindow = 0;
  this->m_presentation.Width = 800;
  this->m_presentation.Height = 600;
  this->m_presentation.FullScreen = 0;
  this->m_presentation.FSRefreshRate = 0;
  this->m_presentation.FSBitsPerPixel = 32;
  this->m_presentation.FSTripleBuffering = 0;
  this->m_presentation.FSSyncToDisplayRefresh = 0;
  this->m_presentation.Antialiasing = 0;
  this->m_config.hFocusWindow = 0;
  this->m_config.bSoftwareVertexProcessing = 0;
  this->m_config.bUseStencilBuffer = 1;
  this->m_config.bUsePureDevice = 1;
  this->m_caps.MaxTextureWidth = 0;
  this->m_caps.MaxTextureHeight = 0;
  this->m_caps.MaxSimultaneousTextures = 0;
  this->m_caps.MaxTextureBlendStages = 0;
  this->m_caps.MaxSimultaneousRenderTargets = 0;
  this->m_caps.MaxActiveLights = 0;
  this->m_caps.MaxUserClipPlanes = 0;
  this->m_caps.bCanDoSinglePassDetailing = 0;
  this->m_caps.bTexOpDotProduct3 = 0;
  this->m_caps.bTexOpBumpEnvMap = 0;
  this->m_caps.bDestinationAlpha = 0;
  this->m_caps.bSquareTexturesOnly = 0;
  this->m_caps.b3DTextures = 0;
  this->m_caps.bCubeTextures = 0;
  this->m_caps.bColorWriteControl = 0;
  this->m_caps.bHardwareVertexProcessing = 0;
  this->m_caps.bOcclusionQueries = 0;
  this->m_caps.bSimpleNonPowerOfTwoTextures = 0;
  this->m_caps.bPointSprites = 0;
  this->m_caps.bAutoGenMipMaps = 0;
  this->m_caps.bDynamicTextures = 0;
  this->m_caps.bSlopeScaleDepthBias = 0;
  this->m_caps.bBlendOp = 0;
  this->m_caps.bTwoSidedStencil = 0;
  this->m_caps.bCompressedTextures = 0;
  this->m_displayInfo.bStencilBuffer = 0;
  this->m_displayInfo.bTextureRenderTargets = 0;
  this->m_displayInfo.bMultiSampling = 0;
  this->m_displayInfo.bMultiSample_2_Samples = 0;
  this->m_displayInfo.bMultiSample_4_Samples = 0;
  this->m_displayInfo.pfRenderTargets = 0;
  this->m_displayInfo.pfDepthBuffers = 0;
  this->m_displayInfo.pfRGBTextures = 0;
  this->m_displayInfo.pfARGBTextures = 0;
  this->m_displayInfo.pfAlphaTextures = 0;
  this->m_displayInfo.pfRGBSurfaces = 0;
  this->m_displayInfo.pfARGBSurfaces = 0;
  this->m_displayInfo.pfAlphaSurfaces = 0;
  this->m_displayInfo.pfLowRGBSurfaces = 0;
  this->m_displayInfo.pfLowARGBSurfaces = 0;
  this->m_displayInfo.pfLowAlphaSurfaces = 0;
  RenderDevice::GraphicsStatesType::GraphicsStatesType(&this->m_GState);
  RenderDevice::Begin(v1);
}
// 7E5488: using guessed type int (__thiscall *RenderDevice::vftable)(void *, char);

//----- (0059DDB0) --------------------------------------------------------  // acclient.c:455650
BOOL __thiscall RenderDevice::IsResetPossible(RenderDevice *this)
{
  return this->m_bDeviceLost == 0;
}

//----- (0059DDC0) --------------------------------------------------------  // acclient.c:455656
void __thiscall RenderDevice::~RenderDevice(RenderDevice *this)
{
  RenderDevice *v1; // esi@1
  RenderLight *v2; // esi@2

  v1 = this;
  this->vfptr = (RenderDeviceVtbl *)&RenderDevice::vftable;
  RenderDevice::End(this);
  if ( (v1->m_GState.FFLightSources.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = v1->m_GState.FFLightSources.m_data;
    if ( v2 )
      operator delete[](&v2[-1].distancesq);
  }
}
// 7E5488: using guessed type int (__thiscall *RenderDevice::vftable)(void *, char);

//----- (0059DE00) --------------------------------------------------------  // acclient.c:455674
RenderDevice *__thiscall RenderDevice::scalar_deleting_destructor(RenderDevice *this, unsigned int a2)
{
  RenderDevice *v2; // esi@1
  RenderLight *v3; // eax@2

  v2 = this;
  this->vfptr = (RenderDeviceVtbl *)&RenderDevice::vftable;
  RenderDevice::End(this);
  if ( (v2->m_GState.FFLightSources.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v3 = v2->m_GState.FFLightSources.m_data;
    if ( v3 )
      operator delete[](&v3[-1].distancesq);
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E5488: using guessed type int (__thiscall *RenderDevice::vftable)(void *, char);

//----- (0059DE50) --------------------------------------------------------  // acclient.c:455695
RenderDeviceD3D *__thiscall RenderDeviceD3D::scalar_deleting_destructor(RenderDeviceD3D *this, unsigned int a2)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  this->vfptr = (RenderDeviceVtbl *)&RenderDeviceD3D::vftable;
  RenderDeviceD3D::End(this);
  SmartArray<char *,1>::~SmartArray<char *,1>((SmartArray<long,1> *)&v2->m_DefaultSamplerMappings);
  RenderDevice::~RenderDevice((RenderDevice *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E5500: using guessed type int (__thiscall *RenderDeviceD3D::vftable)(void *, char);

//----- (0059DE90) --------------------------------------------------------  // acclient.c:455711
char __thiscall D3DPolyRender::DetectDisplayModes(D3DPolyRender *this)
{
  int v1; // ebp@1
  unsigned int v2; // ebx@1
  int v3; // eax@2
  unsigned int v4; // edx@3
  int v5; // ST28_4@8
  int v11; // esi@12
  D3DPolyRender *v13; // [sp+20h] [bp-50h]@1
  _D3DDISPLAYMODE D3DDisplayMode; // [sp+28h] [bp-48h]@2
  PixelFormatDesc PFD; // [sp+38h] [bp-38h]@12

  v13 = this;
  v1 = this->m_pDirect3D->vfptr[2].QueryInterface(
         (IUnknown *)this->m_pDirect3D,
         (_GUID *)this->m_nDisplayAdapter,
         (void **)22);
  v2 = 0;
  if ( v1 )
  {
    do
    {
      ((void (__stdcall *)(IDirect3D9 *, unsigned int, signed int, unsigned int, _D3DDISPLAYMODE *))v13->m_pDirect3D->vfptr[2].AddRef)(
        v13->m_pDirect3D,
        v13->m_nDisplayAdapter,
        22,
        v2,
        &D3DDisplayMode);
      v3 = v13->m_DisplayModes.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v13->m_DisplayModes.m_num < v3 )
        goto LABEL_16;
      v4 = v3 + 1;
      if ( (unsigned int)(v3 + 1) > 8 )
      {
        if ( v4 <= 0x4000 )
        {
          v5 = v3 + 1;
          __asm { bsr     this, [esp+60h+var_4C] }
          if ( v4 > 1 << _EAX )
            v4 = 2 * (1 << _EAX);
        }
        else if ( v4 & 0x3FFF )
        {
          v4 += 0x4000 - (v4 & 0x3FFF);
        }
      }
      else
      {
        v4 = 8;
      }
      if ( SmartArray<RenderDisplayModeType,1>::grow(&v13->m_DisplayModes, v4) )
LABEL_16:
        ++v13->m_DisplayModes.m_num;
      v11 = (int)&v13->m_DisplayModes.m_data[v13->m_DisplayModes.m_num - 1];
      *(_DWORD *)v11 = D3DDisplayMode.Width;
      *(_DWORD *)(v11 + 4) = D3DDisplayMode.Height;
      *(_DWORD *)(v11 + 8) = D3DDisplayMode.Format;
      *(_DWORD *)(v11 + 12) = D3DDisplayMode.RefreshRate;
      ClipPlane::ClipPlane((ClipPlane *)&PFD);
      PixelFormatDesc::SetFormat(&PFD, *(PixelFormatID *)(v11 + 8));
      ++v2;
    }
    while ( v2 < v1 );
  }
  return 1;
}

//----- (0059DFA0) --------------------------------------------------------  // acclient.c:455779
char __cdecl D3DPolyRender::ConstructMesh(int num_surfaces, CSurface **surfaces, CVertexArray *vertex_array, int num_polygons, CPolygon *polygons, float detailTextureUVFactor, bool burn_in_static_lights, MeshBuffer **constructedMesh)
{
  void *v8; // eax@1
  unsigned int v9; // ebp@1
  MeshBuffer *v10; // ebx@2
  int v11; // edi@4
  char *v12; // eax@5
  unsigned int v13; // edx@5
  unsigned int v14; // esi@10
  int v15; // esi@12
  int v16; // ecx@15
  int v17; // edx@16
  MeshBatchType *v18; // eax@17
  unsigned int v19; // eax@17
  char *v21; // eax@21
  char *v22; // ecx@26
  int v23; // esi@27
  int v24; // eax@27
  int v25; // esi@27
  int v26; // edx@27
  signed int v27; // ebx@30
  signed int i; // edi@32
  unsigned __int16 v29; // ax@34
  MeshBatchType *v30; // eax@36
  int v31; // edx@36
  int j; // edx@39
  int v33; // edi@40
  int v34; // eax@41
  int v35; // esi@43
  int v36; // eax@45
  int v37; // edi@49
  int v38; // esi@50
  int v39; // eax@52
  int v40; // esi@54
  int v41; // edi@58
  int v42; // esi@59
  int v43; // eax@61
  int v44; // esi@63
  unsigned int v45; // eax@69
  int v46; // edx@70
  MeshBatchType *v47; // ecx@71
  unsigned __int32 v48; // eax@72
  int v49; // ecx@74
  RenderMesh *v50; // ecx@79
  char result; // al@81
  RenderMesh *v52; // ecx@85
  IUnknownVtbl *v54; // edx@89
  RenderMesh *v55; // ecx@92
  RenderMesh *v56; // ecx@99
  char *v57; // ebp@104
  int v58; // eax@105
  signed int v59; // ecx@105
  unsigned __int16 v60; // ax@111
  int v61; // ecx@113
  CSurface *v62; // eax@113
  signed int v63; // esi@122
  int v64; // edx@124
  unsigned int v65; // eax@127
  int v66; // ecx@130
  MeshBatchType *v67; // ecx@132
  int v68; // ecx@138
  char v69; // bl@141
  int v70; // ecx@146
  unsigned int v71; // ecx@152
  unsigned int v72; // ebp@152
  int v73; // esi@153
  unsigned int v74; // eax@154
  char *v75; // esi@154
  unsigned int v76; // eax@155
  unsigned int v77; // ebx@155
  unsigned int v78; // edx@156
  _D3DXATTRIBUTERANGE *v82; // eax@166
  MeshBuffer *v83; // esi@171
  RenderMesh *v84; // ecx@173
  RenderMesh *v85; // ecx@181
  MeshBuffer *v86; // eax@186
  ID3DXMesh *pMesh; // [sp+40h] [bp-5Ch]@76
  unsigned int v88; // [sp+44h] [bp-58h]@4
  MeshBuffer *meshBuffer; // [sp+48h] [bp-54h]@4
  int maxUVsPerVertex; // [sp+4Ch] [bp-50h]@4
  int *vertmap; // [sp+50h] [bp-4Ch]@10
  int numTris; // [sp+54h] [bp-48h]@4
  char *uvsForSide; // [sp+58h] [bp-44h]@118
  MeshBatchType *MeshBatch; // [sp+5Ch] [bp-40h]@116
  int poly; // [sp+60h] [bp-3Ch]@26
  int numWindingsThisPoly; // [sp+64h] [bp-38h]@27
  unsigned __int16 *indexBuf; // [sp+68h] [bp-34h]@89
  void *verts; // [sp+6Ch] [bp-30h]@82
  unsigned int *attribBuf; // [sp+70h] [bp-2Ch]@96
  float translucency; // [sp+74h] [bp-28h]@114
  int numTrisInThisPoly; // [sp+78h] [bp-24h]@105
  int numSidesThisPoly; // [sp+7Ch] [bp-20h]@105
  int v103; // [sp+80h] [bp-1Ch]@104
  int numVerts; // [sp+84h] [bp-18h]@4
  int v105; // [sp+88h] [bp-14h]@121
  unsigned int v106; // [sp+8Ch] [bp-10h]@122
  int surfaceToUse; // [sp+90h] [bp-Ch]@113
  unsigned int TriangleBaseIndex; // [sp+94h] [bp-8h]@122
  unsigned int VertexSizeInBytes; // [sp+98h] [bp-4h]@74
  int num_surfacesa; // [sp+A0h] [bp+4h]@109
  int num_surfacesb; // [sp+A0h] [bp+4h]@153
  int num_polygonsa; // [sp+ACh] [bp+10h]@116
  int num_polygonsb; // [sp+ACh] [bp+10h]@161

  v8 = operator new(0x24u);
  v9 = 0;
  if ( v8 )
  {
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 4) = 0;
    *((_BYTE *)v8 + 20) = 0;
    *((_BYTE *)v8 + 21) = 0;
    *((_DWORD *)v8 + 8) = 0;
    v10 = (MeshBuffer *)v8;
  }
  else
  {
    v10 = 0;
  }
  meshBuffer = v10;
  v10->isStippledOrAlphaedMask = (char *)operator new[](num_surfaces);
  v11 = 1;
  numTris = 0;
  numVerts = 0;
  maxUVsPerVertex = 1;
  v10->burnedInStaticLights = (burn_in_static_lights == 0) - 1;
  v88 = vertex_array->num_vertices;
  if ( v88 > 0 )
  {
    v12 = (char *)&vertex_array->vertices->reserve4 + 2;
    v13 = v88;
    do
    {
      if ( *(_WORD *)v12 > v11 )
        v11 = *(_WORD *)v12;
      v12 += 32;
      --v13;
    }
    while ( v13 );
    maxUVsPerVertex = v11;
  }
  v14 = 8 * v11 * v88;
  vertmap = (int *)operator new[](v14);
  memset(vertmap, 0xFFu, v14);
  if ( !(_S214_1 & 1) )
  {
    _S214_1 |= 1u;
    s_MeshBatches.m_data = 0;
    s_MeshBatches.m_sizeAndDeallocate = 0;
    s_MeshBatches.m_num = 0;
    atexit(_E215_15);
  }
  v15 = num_surfaces;
  if ( (s_MeshBatches.m_sizeAndDeallocate & 0x7FFFFFFF) >= num_surfaces
    || SmartArray<_D3DXATTRIBUTERANGE,0>::grow((SmartArray<_D3DXATTRIBUTERANGE,0> *)&s_MeshBatches, num_surfaces) )
    s_MeshBatches.m_num = num_surfaces;
  v16 = 0;
  if ( num_surfaces > 0 )
  {
    v17 = 0;
    do
    {
      v18 = &s_MeshBatches.m_data[v17];
      v18->m_NumTriangles = 0;
      v18->m_CurTriangleIndex = 0;
      v18->m_FirstTriangleIndex = 0;
      v18->m_FirstVertexIndex = -1;
      v18->m_LastVertexIndex = 0;
      v19 = surfaces[v16]->type;
      if ( v19 & 0x10300 )
      {
        v10->isStippledOrAlphaedMask[v16] = 2;
      }
      else if ( v19 & 4 )
      {
        v10->isStippledOrAlphaedMask[v16] = 8;
      }
      else
      {
        _ZF = (v19 & 0x10) == 0;
        v21 = v10->isStippledOrAlphaedMask;
        if ( _ZF )
          v21[v16] = 0;
        else
          v21[v16] = 4;
      }
      ++v16;
      ++v17;
    }
    while ( v16 < num_surfaces );
  }
  if ( num_polygons > 0 )
  {
    v22 = (char *)&polygons->sides_type;
    poly = num_polygons;
    do
    {
      v23 = (unsigned __int8)*(v22 - 2);
      v24 = *(_DWORD *)v22;
      numWindingsThisPoly = v23;
      v25 = v23 - 2;
      v26 = v25;
      if ( v24 == 2 || v24 == 1 )
        v26 = 2 * v25;
      numTris += v26;
      v27 = 1;
      if ( v24 == 2 )
        v27 = 2;
      for ( i = 0; i < v27; ++i )
      {
        if ( i )
          v29 = *((_WORD *)v22 + 7);
        else
          v29 = *((_WORD *)v22 + 6);
        v30 = &s_MeshBatches.m_data[v29];
        v31 = v25 + v30->m_NumTriangles;
        v30->m_NumTriangles = v31;
        if ( *(_DWORD *)v22 == 1 )
          v30->m_NumTriangles = v25 + v31;
      }
      meshBuffer->isStippledOrAlphaedMask[*((_WORD *)v22 + 6)] |= *(v22 - 1) > 0;
      for ( j = 0; j < numWindingsThisPoly; ++j )
      {
        v33 = *((_DWORD *)v22 + 1);
        if ( v33 )
          v34 = *(_BYTE *)(v33 + j);
        else
          v34 = 0;
        v35 = *(_WORD *)(*((_DWORD *)v22 - 3) + 2 * j);
        if ( vertmap[v35 + v88 * v34] == -1 )
        {
          if ( v33 )
            v36 = *(_BYTE *)(v33 + j);
          else
            v36 = 0;
          vertmap[v35 + v88 * v36] = v9++;
        }
        if ( *(_DWORD *)v22 == 1 )
        {
          v37 = *((_DWORD *)v22 + 1);
          v38 = v37 ? *(_BYTE *)(v37 + j) : 0;
          v39 = *(_WORD *)(*((_DWORD *)v22 - 3) + 2 * j);
          if ( vertmap[v39 + v88 * (maxUVsPerVertex + v38)] == -1 )
          {
            if ( v37 )
              v40 = *(_BYTE *)(v37 + j);
            else
              v40 = 0;
            vertmap[v39 + v88 * (maxUVsPerVertex + v40)] = v9++;
          }
        }
        if ( *(_DWORD *)v22 == 2 )
        {
          v41 = *((_DWORD *)v22 + 2);
          v42 = v41 ? *(_BYTE *)(v41 + j) : 0;
          v43 = *(_WORD *)(*((_DWORD *)v22 - 3) + 2 * j);
          if ( vertmap[v43 + v88 * (maxUVsPerVertex + v42)] == -1 )
          {
            if ( v41 )
              v44 = *(_BYTE *)(v41 + j);
            else
              v44 = 0;
            vertmap[v43 + v88 * (maxUVsPerVertex + v44)] = v9++;
          }
        }
      }
      v22 += 48;
      --poly;
    }
    while ( poly );
    v10 = meshBuffer;
    v15 = num_surfaces;
    numVerts = v9;
  }
  v45 = 0;
  if ( v15 > 0 )
  {
    v46 = 0;
    do
    {
      v47 = &s_MeshBatches.m_data[v46];
      v47->m_FirstTriangleIndex = v45;
      v45 += v47->m_NumTriangles;
      ++v46;
      --v15;
    }
    while ( v15 );
  }
  v48 = 594;
  if ( detailTextureUVFactor <= 0.0 )
    v48 = 338;
  v10->meshFVF = v48;
  v49 = 544;
  VertexSizeInBytes = 8 * (v48 == 594) + 36;
  if ( !RenderDevice::render_device->m_caps.bHardwareVertexProcessing )
    v49 = 98848;
  if ( D3DXCreateMeshFVF(
         0,
         numTris,
         v9,
         v49,
         v48,
         LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
         (int)&pMesh) < 0 )
  {
    if ( v10->pMesh )
    {
      v10->pMesh->vfptr->Release((IUnknown *)v10->pMesh);
      v10->pMesh = 0;
    }
    v50 = v10->pRenderMesh;
    if ( v50 )
    {
      ((void (*)(void))v50->vfptr->Release)();
      v10->pRenderMesh = 0;
    }
    operator delete[](v10->isStippledOrAlphaedMask);
    v10->isStippledOrAlphaedMask = 0;
    operator delete(v10);
    return 0;
  }
  if ( pMesh->vfptr[5].QueryInterface((IUnknown *)pMesh, 0, &verts) < 0 )
  {
    if ( v10->pMesh )
    {
      v10->pMesh->vfptr->Release((IUnknown *)v10->pMesh);
      v10->pMesh = 0;
    }
    v52 = v10->pRenderMesh;
    if ( v52 )
    {
      ((void (*)(void))v52->vfptr->Release)();
      v10->pRenderMesh = 0;
    }
    operator delete[](v10->isStippledOrAlphaedMask);
    v10->isStippledOrAlphaedMask = 0;
    operator delete(v10);
    if ( !pMesh )
      goto LABEL_185;
    pMesh->vfptr->Release((IUnknown *)pMesh);
    return 0;
  }
  _SF = ((int (__stdcall *)(ID3DXMesh *, _DWORD, unsigned __int16 **))pMesh->vfptr[5].Release)(pMesh, 0, &indexBuf) < 0;
  v54 = pMesh->vfptr;
  if ( _SF )
  {
    v54[5].AddRef((IUnknown *)pMesh);
    if ( v10->pMesh )
    {
      v10->pMesh->vfptr->Release((IUnknown *)v10->pMesh);
      v10->pMesh = 0;
    }
    v55 = v10->pRenderMesh;
    if ( v55 )
    {
      ((void (*)(void))v55->vfptr->Release)();
      v10->pRenderMesh = 0;
    }
    operator delete[](v10->isStippledOrAlphaedMask);
    v10->isStippledOrAlphaedMask = 0;
    operator delete(v10);
    if ( !pMesh )
      goto LABEL_185;
    pMesh->vfptr->Release((IUnknown *)pMesh);
    return 0;
  }
  if ( v54[8].QueryInterface((IUnknown *)pMesh, 0, (void **)&attribBuf) < 0 )
  {
    pMesh->vfptr[5].AddRef((IUnknown *)pMesh);
    ((void (__stdcall *)(ID3DXMesh *))pMesh->vfptr[6].QueryInterface)(pMesh);
    if ( v10->pMesh )
    {
      v10->pMesh->vfptr->Release((IUnknown *)v10->pMesh);
      v10->pMesh = 0;
    }
    v56 = v10->pRenderMesh;
    if ( v56 )
    {
      ((void (*)(void))v56->vfptr->Release)();
      v10->pRenderMesh = 0;
    }
    operator delete[](v10->isStippledOrAlphaedMask);
    v10->isStippledOrAlphaedMask = 0;
    operator delete(v10);
    if ( !pMesh )
      goto LABEL_185;
    pMesh->vfptr->Release((IUnknown *)pMesh);
    return 0;
  }
  if ( num_polygons > 0 )
  {
    v57 = (char *)&polygons->sides_type;
    v103 = num_polygons;
    do
    {
      numTrisInThisPoly = (unsigned __int8)*(v57 - 2) - 2;
      v58 = *(_DWORD *)v57;
      _ZF = *(_DWORD *)v57 == 2;
      v59 = 1;
      numSidesThisPoly = 1;
      numWindingsThisPoly = 1;
      if ( _ZF )
      {
        v59 = v58;
        numSidesThisPoly = v58;
      }
      if ( v58 == 1 )
        numWindingsThisPoly = 2;
      num_surfacesa = 0;
      if ( v59 > 0 )
      {
        do
        {
          if ( num_surfacesa )
            v60 = *((_WORD *)v57 + 7);
          else
            v60 = *((_WORD *)v57 + 6);
          v61 = v60;
          v62 = surfaces[v60];
          _ZF = (v62->type & 0x10) == 0;
          surfaceToUse = v61;
          if ( _ZF )
            translucency = 0.0;
          else
            translucency = v62->translucency;
          MeshBatch = &s_MeshBatches.m_data[v61];
          for ( num_polygonsa = 0; num_polygonsa < numWindingsThisPoly; ++num_polygonsa )
          {
            if ( num_surfacesa )
              uvsForSide = (char *)*((_DWORD *)v57 + 2);
            else
              uvsForSide = (char *)*((_DWORD *)v57 + 1);
            poly = 0;
            if ( numTrisInThisPoly > 0 )
            {
              v105 = maxUVsPerVertex * (num_surfacesa + num_polygonsa);
              do
              {
                TriangleBaseIndex = MeshBatch->m_CurTriangleIndex + MeshBatch->m_FirstTriangleIndex;
                v63 = 0;
                v106 = 3 * TriangleBaseIndex;
                do
                {
                  if ( v63 )
                    v64 = v63 + poly;
                  else
                    v64 = 0;
                  if ( uvsForSide )
                    v65 = uvsForSide[v64];
                  else
                    v65 = 0;
                  LOWORD(v65) = LOWORD(vertmap[*(_WORD *)(*((_DWORD *)v57 - 3) + 2 * v64) + v88 * (v65 + v105)]);
                  if ( num_polygonsa )
                    v66 = 2 - v63;
                  else
                    v66 = v63;
                  indexBuf[v66 + v106] = v65;
                  v67 = MeshBatch;
                  v65 = (unsigned __int16)v65;
                  if ( (unsigned __int16)v65 < MeshBatch->m_FirstVertexIndex )
                    MeshBatch->m_FirstVertexIndex = v65;
                  if ( v65 > v67->m_LastVertexIndex )
                    v67->m_LastVertexIndex = v65;
                  if ( num_polygonsa || num_surfacesa )
                    v68 = -1;
                  else
                    v68 = 1;
                  if ( uvsForSide )
                    v69 = uvsForSide[v64];
                  else
                    v69 = 0;
                  copyVert(
                    (void *)v65,
                    (CSWVertex *)v63++,
                    (char)vertex_array,
                    (int)verts,
                    v69,
                    (int)&vertex_array->vertices[*(_WORD *)(*((_DWORD *)v57 - 3) + 2 * v64)],
                    v65,
                    v68,
                    detailTextureUVFactor,
                    translucency,
                    burn_in_static_lights,
                    meshBuffer->meshFVF);
                }
                while ( v63 < 3 );
                if ( attribBuf )
                  attribBuf[TriangleBaseIndex] = surfaceToUse;
                v70 = numTrisInThisPoly;
                ++MeshBatch->m_CurTriangleIndex;
                ++poly;
              }
              while ( poly < v70 );
            }
          }
          ++num_surfacesa;
        }
        while ( num_surfacesa < numSidesThisPoly );
      }
      v57 += 48;
      --v103;
    }
    while ( v103 );
  }
  operator delete[](vertmap);
  pMesh->vfptr[5].AddRef((IUnknown *)pMesh);
  ((void (__stdcall *)(ID3DXMesh *))pMesh->vfptr[6].QueryInterface)(pMesh);
  pMesh->vfptr[8].AddRef((IUnknown *)pMesh);
  if ( !(_S214_1 & 2) )
  {
    _S214_1 |= 2u;
    s_D3DXAttributeRanges.m_data = 0;
    s_D3DXAttributeRanges.m_sizeAndDeallocate = 0;
    s_D3DXAttributeRanges.m_num = 0;
    atexit(_E216_15);
  }
  v71 = 0;
  v72 = 0;
  s_D3DXAttributeRanges.m_num = 0;
  if ( !s_MeshBatches.m_num )
  {
LABEL_169:
    if ( pMesh )
    {
      pMesh->vfptr->Release((IUnknown *)pMesh);
      pMesh = 0;
    }
    v83 = meshBuffer;
    if ( meshBuffer->pMesh )
    {
      meshBuffer->pMesh->vfptr->Release((IUnknown *)meshBuffer->pMesh);
      v83->pMesh = 0;
    }
    v84 = v83->pRenderMesh;
    if ( v84 )
    {
      ((void (*)(void))v84->vfptr->Release)();
      v83->pRenderMesh = 0;
    }
    operator delete[](v83->isStippledOrAlphaedMask);
    goto LABEL_184;
  }
  v73 = 0;
  num_surfacesb = 0;
  do
  {
    v74 = *(unsigned int *)((char *)&s_MeshBatches.m_data->m_NumTriangles + v73);
    v75 = (char *)s_MeshBatches.m_data + v73;
    if ( v74 <= 0 )
      goto LABEL_167;
    v76 = s_D3DXAttributeRanges.m_sizeAndDeallocate & 0x7FFFFFFF;
    v77 = v71;
    if ( v71 >= (s_D3DXAttributeRanges.m_sizeAndDeallocate & 0x7FFFFFFF) )
    {
      v78 = v76 + 1;
      if ( v76 + 1 > 8 )
      {
        if ( v78 <= 0x4000 )
        {
          num_polygonsb = v76 + 1;
          __asm { bsr     eax, [esp+6Ch+num_polygons] }
          if ( v78 > 1 << _EAX )
            v78 = 2 * (1 << _EAX);
        }
        else if ( v78 & 0x3FFF )
        {
          v78 += 0x4000 - (v78 & 0x3FFF);
        }
      }
      else
      {
        v78 = 8;
      }
      if ( !SmartArray<_D3DXATTRIBUTERANGE,0>::grow(&s_D3DXAttributeRanges, v78) )
        goto LABEL_166;
      v71 = s_D3DXAttributeRanges.m_num;
    }
    s_D3DXAttributeRanges.m_num = v71 + 1;
LABEL_166:
    v82 = &s_D3DXAttributeRanges.m_data[v77];
    v82->AttribId = v72;
    v82->FaceStart = *(_DWORD *)v75;
    v82->FaceCount = *((_DWORD *)v75 + 1);
    v82->VertexStart = *((_DWORD *)v75 + 3);
    v82->VertexCount = *((_DWORD *)v75 + 4) - *((_DWORD *)v75 + 3) + 1;
    v71 = s_D3DXAttributeRanges.m_num;
LABEL_167:
    ++v72;
    v73 = num_surfacesb + 20;
    num_surfacesb += 20;
  }
  while ( v72 < s_MeshBatches.m_num );
  if ( !v71 )
    goto LABEL_169;
  if ( ((int (__stdcall *)(ID3DXMesh *, _D3DXATTRIBUTERANGE *, unsigned int))pMesh->vfptr[9].AddRef)(
         pMesh,
         s_D3DXAttributeRanges.m_data,
         v71) )
  {
    if ( pMesh )
    {
      pMesh->vfptr->Release((IUnknown *)pMesh);
      pMesh = 0;
    }
    v83 = meshBuffer;
    if ( meshBuffer->pMesh )
    {
      meshBuffer->pMesh->vfptr->Release((IUnknown *)meshBuffer->pMesh);
      v83->pMesh = 0;
    }
    v85 = v83->pRenderMesh;
    if ( v85 )
    {
      ((void (*)(void))v85->vfptr->Release)();
      v83->pRenderMesh = 0;
    }
    operator delete[](v83->isStippledOrAlphaedMask);
LABEL_184:
    v83->isStippledOrAlphaedMask = 0;
    operator delete(v83);
LABEL_185:
    result = 0;
  }
  else
  {
    v86 = meshBuffer;
    meshBuffer->m_RemoteSizeInBytes = numVerts * VertexSizeInBytes + 20 * s_D3DXAttributeRanges.m_num + 6 * numTris;
    v86->pMesh = pMesh;
    v86->detailTilingFactorSet = detailTextureUVFactor;
    *constructedMesh = v86;
    result = 1;
  }
  return result;
}

//----- (0059E990) --------------------------------------------------------  // acclient.c:456418
RenderDevice *D3DPolyRender::CreateRenderDevice()
{
  RenderDevice *v1; // eax@1
  RenderDevice *v2; // esi@1
  RenderDevice *result; // eax@2

  v1 = (RenderDevice *)operator new(0x818u);
  v2 = v1;
  if ( v1 )
  {
    RenderDevice::RenderDevice(v1);
    v2->vfptr = (RenderDeviceVtbl *)&RenderDeviceD3D::vftable;
    RenderStateCacheType::RenderStateCacheType((RenderStateCacheType *)&v2[1].m_GState.ViewToClipMatrix._33);
    LODWORD(v2[2].m_GState.PixelFilterTexCoords[0].w) = 0;
    LODWORD(v2[2].m_GState.PixelFilterTexCoords[1].x) = 0;
    LODWORD(v2[2].m_GState.PixelFilterTexCoords[1].y) = 0;
    RenderDeviceD3D::Begin((RenderDeviceD3D *)v2);
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E5500: using guessed type int (__thiscall *RenderDeviceD3D::vftable)(void *, char);

//----- (0059E9F0) --------------------------------------------------------  // acclient.c:456446
bool __thiscall D3DPolyRender::Startup(D3DPolyRender *this, RenderConfig *_config)
{
  D3DPolyRender *v2; // esi@1
  HMODULE v3; // eax@2
  PSRefBufferCharData<unsigned short> *v4; // ecx@2
  FARPROC v5; // eax@3
  int v6; // eax@4
  PSRefBufferCharData<unsigned short> *v7; // ecx@5
  PSRefBufferCharData<unsigned short> *v8; // ecx@5
  PStringBase<unsigned short> v10; // [sp-18h] [bp-1Ch]@5
  PStringBase<unsigned short> v11; // [sp-14h] [bp-18h]@5
  PStringBase<unsigned short> v12; // [sp-10h] [bp-14h]@5
  PlatformString::DisplayStringMode v13; // [sp-Ch] [bp-10h]@5

  v2 = this;
  if ( !Render::Startup((Render *)&this->vfptr, _config) )
    return 0;
  v3 = LoadLibraryA("d3d9.dll");
  v2->m_hD3D9DLL = v3;
  if ( !v3
    || (v5 = GetProcAddress(v3, "Direct3DCreate9")) == 0
    || (v6 = ((int (__stdcall *)(signed int))v5)(32), (v2->m_pDirect3D = (IDirect3D9 *)v6) == 0) )
  {
    v13 = 0;
    v12.m_charbuffer = v4;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v12, &word_794320);
    v11.m_charbuffer = v7;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v11, &word_794320);
    v10.m_charbuffer = v8;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, &word_794320);
    PlatformString::DisplayString(0x69u, v10, v11, v12, v13);
    return 0;
  }
  v2->m_nDisplayAdapter = 0;
  if ( !D3DPolyRender::SelectBestAdapter(v2) )
    return 0;
  return D3DPolyRender::DetectDisplayModes(v2) != 0;
}

//----- (0059EA90) --------------------------------------------------------  // acclient.c:456486
char __cdecl D3DPolyRender::ConstructMesh(CGfxObj *obj, MeshBuffer **constructedMesh)
{
  return D3DPolyRender::ConstructMesh(
           obj->num_surfaces,
           obj->m_rgSurfaces,
           &obj->vertex_array,
           obj->num_polygons,
           obj->polygons,
           1.0,
           0,
           constructedMesh);
}

//----- (0059EAD0) --------------------------------------------------------  // acclient.c:456500
void __thiscall D3DPolyRender::Begin(D3DPolyRender *this)
{
  D3DPolyRender *v1; // esi@1
  void *v2; // esi@1
  char *v3; // esi@3
  char *v4; // esi@6
  char *v5; // esi@9
  char *v6; // esi@12
  char *v7; // esi@15
  char *v8; // esi@18
  char *v9; // esi@21
  char *v10; // esi@24
  PStringBase<char> _Name; // [sp+1Ch] [bp-8h]@1
  PStringBase<char> _Description; // [sp+20h] [bp-4h]@1

  v1 = this;
  this->m_hD3D9DLL = 0;
  this->m_pDirect3D = 0;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&this->m_DynamicVertexStreamHash.m_intrusiveTable);
  v1->m_pDynamicIndexStream = 0;
  v2 = &v1->m_GlobalMipmapLODBias;
  *(_DWORD *)v2 = 0;
  PStringBase<char>::PStringBase<char>(&_Description, "Texture sampler mipmap LOD bias");
  PStringBase<char>::PStringBase<char>(&_Name, "RenderD3D.MipmapLODBias");
  if ( v2 )
    GlobalRegistry::RegisterVariableInternal(v2, GRVDataType_Float32, &_Name, &_Description, 0, 0, 0, 0);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(
    &_Name,
    "Mask for what mesh types will get delay-rendered. Alpha=2, Translucent=4, ClipMap=8.");
  PStringBase<char>::PStringBase<char>(&_Description, "RenderD3D.AlphaDelayMask");
  GlobalRegistry::RegisterVariableInternal(
    &D3DPolyRender::s_AlphaDelayMask,
    GRVDataType_UInt32,
    &_Description,
    &_Name,
    0,
    0,
    0,
    0);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Z-Buffer test ref value (for DDS textures)");
  PStringBase<char>::PStringBase<char>(&_Description, "RenderD3D.DDSAlphaTestRef");
  GlobalRegistry::RegisterVariableInternal(
    &D3DPolyRender::s_ddsAlphaTestRef,
    GRVDataType_Int32,
    &_Description,
    &_Name,
    0,
    0,
    0,
    0);
  v7 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Z-Buffer test ref value (for palettized textures)");
  PStringBase<char>::PStringBase<char>(&_Description, "RenderD3D.256AlphaTestRef");
  GlobalRegistry::RegisterVariableInternal(
    &D3DPolyRender::s_256AlphaTestRef,
    GRVDataType_Int32,
    &_Description,
    &_Name,
    0,
    0,
    0,
    0);
  v9 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
}
// 820D88: using guessed type unsigned __int32 D3DPolyRender::s_AlphaDelayMask;
// 820D8C: using guessed type __int32 D3DPolyRender::s_256AlphaTestRef;
// 820D90: using guessed type __int32 D3DPolyRender::s_ddsAlphaTestRef;

//----- (0059ECF0) --------------------------------------------------------  // acclient.c:456594
void __thiscall D3DPolyRender::End(D3DPolyRender *this)
{
  D3DPolyRender *v1; // ebx@1
  char *v2; // esi@1
  char *v3; // esi@4
  char *v4; // esi@7
  char *v5; // esi@10
  RenderIndexStreamD3D *v6; // ecx@13
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@15
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v8; // esi@15
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v9; // edx@15
  HashTableData<unsigned long,HeritageGroup_CG> **v10; // edi@15
  RenderVertexStreamD3D *v11; // ecx@16
  IDirect3D9 *v12; // eax@22
  PStringBase<char> _Name; // [sp+14h] [bp-1Ch]@1
  HashIterator<unsigned long,RenderVertexStreamD3D *,0> Iter; // [sp+18h] [bp-18h]@15
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+24h] [bp-Ch]@15

  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Name, "RenderD3D.MipmapLODBias");
  GlobalRegistry::UnregisterVariable(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "RenderD3D.AlphaDelayMask");
  GlobalRegistry::UnregisterVariable(&_Name);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "RenderD3D.DDSAlphaTestRef");
  GlobalRegistry::UnregisterVariable(&_Name);
  v4 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "RenderD3D.256AlphaTestRef");
  GlobalRegistry::UnregisterVariable(&_Name);
  v5 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = v1->m_pDynamicIndexStream;
  if ( v6 )
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  v1->m_pDynamicIndexStream = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_DynamicVertexStreamHash.m_intrusiveTable,
         &result);
  v8 = (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v7->m_currElement;
  v9 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v7->m_currHashTable;
  v10 = v7->m_currBucket;
  Iter.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v7->m_currHashTable;
  if ( v8 )
  {
    do
    {
LABEL_16:
      v11 = v8->m_data;
      if ( v11 )
      {
        ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
        v9 = Iter.m_iter.m_currHashTable;
      }
      v8 = v8->m_hashNext;
    }
    while ( v8 );
    while ( 1 )
    {
      ++v10;
      if ( v10 == (HashTableData<unsigned long,HeritageGroup_CG> **)&v9->m_buckets[v9->m_numBuckets] )
        break;
      if ( *v10 )
      {
        v8 = (HashTableData<unsigned long,RenderVertexStreamD3D *> *)*v10;
        if ( *v10 )
          goto LABEL_16;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&v1->m_DynamicVertexStreamHash.m_intrusiveTable);
  v12 = v1->m_pDirect3D;
  if ( v12 )
  {
    v12->vfptr->Release((IUnknown *)v1->m_pDirect3D);
    v1->m_pDirect3D = 0;
  }
  if ( v1->m_hD3D9DLL )
  {
    FreeLibrary(v1->m_hD3D9DLL);
    v1->m_hD3D9DLL = 0;
  }
}

//----- (0059EE90) --------------------------------------------------------  // acclient.c:456687
void __thiscall D3DPolyRender::Shutdown(D3DPolyRender *this)
{
  Render *v1; // esi@1

  v1 = (Render *)this;
  D3DPolyRender::End(this);
  Render::Shutdown(v1);
  D3DPolyRender::Begin((D3DPolyRender *)v1);
}

//----- (0059EEB0) --------------------------------------------------------  // acclient.c:456698
RenderVertexStreamD3D *__thiscall D3DPolyRender::ReferenceVertexStream(D3DPolyRender *this, const unsigned int _VertexFormat, const unsigned int _nMinVertices)
{
  const unsigned int v3; // edi@1
  D3DPolyRender *v4; // ebx@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v5; // eax@1
  GraphicsResource *v6; // eax@4
  RenderVertexStreamD3D *v7; // esi@4
  const unsigned int v8; // eax@5
  RenderVertexStreamD3D *pStream; // [sp+Ch] [bp-4h]@1

  pStream = (RenderVertexStreamD3D *)this;
  v3 = _VertexFormat;
  v4 = this;
  v5 = this->m_DynamicVertexStreamHash.m_intrusiveTable.m_buckets[_VertexFormat
                                                                % this->m_DynamicVertexStreamHash.m_intrusiveTable.m_numBuckets];
  if ( v5 )
  {
    while ( v5->m_hashKey != _VertexFormat )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        goto LABEL_4;
    }
    if ( v5 )
      return v5->m_data;
  }
LABEL_4:
  v6 = (GraphicsResource *)operator new(0xB8u);
  v7 = (RenderVertexStreamD3D *)v6;
  if ( !v6 )
    return 0;
  GraphicsResource::GraphicsResource(v6);
  v7->vfptr = (GraphicsResourceVtbl *)&RenderVertexStreamD3D::vftable;
  RenderVertexStreamD3D::Begin(v7);
  v8 = 0x2000;
  pStream = v7;
  if ( _nMinVertices > 0x2000 )
    v8 = _nMinVertices;
  if ( !(unsigned __int8)((int (__thiscall *)(RenderVertexStreamD3D *, const unsigned int, const unsigned int, signed int))v7->vfptr[1].__vecDelDtor)(
                           v7,
                           v8,
                           v3,
                           1) )
  {
    v7->vfptr->__vecDelDtor((GraphicsResource *)v7, 1u);
    return 0;
  }
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    &v4->m_DynamicVertexStreamHash,
    &_VertexFormat,
    &pStream);
  return v7;
}
// 7E5438: using guessed type int (__thiscall *RenderVertexStreamD3D::vftable)(void *, char);

//----- (006B3DB0) --------------------------------------------------------  // acclient.c:717710
ObjectDrawStatus __stdcall IInputActionCallback::OnLoseFocus(CGfxObj *mesh, Position *mesh_pos, bool building_flag)
{
  return 0;
}

//----- (0070B800) --------------------------------------------------------  // acclient.c:798613
int sub_70B800()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_35, "Display.Resolution");
  return atexit(_E74_86);
}

//----- (0070B820) --------------------------------------------------------  // acclient.c:798620
int _E76_70()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_35, "Display.FullScreen");
  return atexit(_E77_98);
}

//----- (0070B840) --------------------------------------------------------  // acclient.c:798627
int _E79_64()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_35, "Display.RefreshRate");
  return atexit(_E80_63);
}

//----- (0070B860) --------------------------------------------------------  // acclient.c:798634
int _E82_42()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_35, "Display.SyncToRefresh");
  return atexit(_E83_40);
}

//----- (0070B880) --------------------------------------------------------  // acclient.c:798641
void _E101_38()
{
  LODWORD(dword_8719E0) = 1053364187;
}

//----- (0070B890) --------------------------------------------------------  // acclient.c:798647
void sub_70B890()
{
  flt_8719E4 = 1000.0 + 1.0;
}

//----- (0070B8B0) --------------------------------------------------------  // acclient.c:798653
void _E105_51()
{
  flt_8719E8 = 24.0 * 8.0;
}

//----- (0070B8D0) --------------------------------------------------------  // acclient.c:798659
void _E107_42()
{
  flt_8719EC = 24.0 * 0.5;
}

//----- (0070B8F0) --------------------------------------------------------  // acclient.c:798665
void _E109_78()
{
  flt_8719F4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070B910) --------------------------------------------------------  // acclient.c:798671
void _E111_54()
{
  dbl_8719F8 = 1.0 / 30.0;
}

//----- (0070B930) --------------------------------------------------------  // acclient.c:798677
void _E113_29()
{
  dbl_871A00 = 1.0 / 5.0;
}

//----- (0070B950) --------------------------------------------------------  // acclient.c:798683
void _E115_84()
{
  PixelFormatDesc::PixelFormatDesc(&stru_871A08, PFID_A8R8G8B8);
}

//----- (0070B960) --------------------------------------------------------  // acclient.c:798689
int _E117_79()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_38, "Render.TextureFiltering");
  return atexit(sub_775640);
}

//----- (0070B980) --------------------------------------------------------  // acclient.c:798696
int _E120_73()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_38, "Render.LandscapeDetailTextures");
  return atexit(sub_775670);
}

//----- (0070B9A0) --------------------------------------------------------  // acclient.c:798703
int _E123_44()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_38, "Render.BuildingDetailTextures");
  return atexit(sub_7756A0);
}

//----- (0070B9C0) --------------------------------------------------------  // acclient.c:798710
int _E126_51()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_38, "Render.FieldOfView");
  return atexit(sub_7756D0);
}

//----- (0070B9E0) --------------------------------------------------------  // acclient.c:798717
int _E129_45()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_38, "Render.LandscapeTextureDetail");
  return atexit(sub_775700);
}

//----- (0070BA00) --------------------------------------------------------  // acclient.c:798724
int _E132_45()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_38, "Render.EnvironmentTextureDetail");
  return atexit(sub_775730);
}

//----- (0070BA20) --------------------------------------------------------  // acclient.c:798731
int _E135_52()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_38, "Render.SceneryDrawDistance");
  return atexit(_E136_87);
}

//----- (0070BA40) --------------------------------------------------------  // acclient.c:798738
int _E138_40()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_38, "Render.LandscapeDrawDistance");
  return atexit(_E139_87);
}

//----- (0070BA60) --------------------------------------------------------  // acclient.c:798745
int _E141_42()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_38, "Render.ScreenBrightness");
  return atexit(_E142_82);
}

//----- (0070BA80) --------------------------------------------------------  // acclient.c:798752
int _E144_39()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_38, "Render.AspectRatio");
  return atexit(_E145_84);
}

//----- (0070BAA0) --------------------------------------------------------  // acclient.c:798759
int _E147_38()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_38, "Render.DisplayAdapter");
  return atexit(_E148_80);
}

//----- (0070BAC0) --------------------------------------------------------  // acclient.c:798766
int _E150_37()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_38, "Render.MaxHardwareClass");
  return atexit(_E151_78);
}

//----- (0070BAE0) --------------------------------------------------------  // acclient.c:798773
int _E153_35()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_38, "Render.AutomaticDegrades");
  return atexit(_E154_79);
}

//----- (0070BB00) --------------------------------------------------------  // acclient.c:798780
int _E156_37()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_38, "Render.GraphicsPerformance");
  return atexit(_E157_75);
}

//----- (0070BB20) --------------------------------------------------------  // acclient.c:798787
int _E159_35()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_38, "Render.DegradeDistance");
  return atexit(_E160_78);
}

//----- (0070BB40) --------------------------------------------------------  // acclient.c:798794
int _E162_38()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_38, "Render.MultiPassAlpha");
  return atexit(_E163_71);
}

//----- (0070BB60) --------------------------------------------------------  // acclient.c:798801
int _E165_33()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_38, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_871A84, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_871A88, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_871A8C, "Anisotropic");
  return atexit(_E166_73);
}

//----- (0070BBB0) --------------------------------------------------------  // acclient.c:798811
int _E168_34()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_38, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_871A94, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871A98, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871A9C, "High");
  PStringBase<char>::PStringBase<char>(&stru_871AA0, "VeryHigh");
  return atexit(_E169_72);
}

//----- (0070BC10) --------------------------------------------------------  // acclient.c:798822
int _E171_33()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_38, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_871AA8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871AAC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871AB0, "High");
  PStringBase<char>::PStringBase<char>(&stru_871AB4, "VeryHigh");
  return atexit(_E172_70);
}

//----- (0070BC70) --------------------------------------------------------  // acclient.c:798833
int _E174_35()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_38, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871ABC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871AC0, "High");
  return atexit(_E175_67);
}

//----- (0070BCB0) --------------------------------------------------------  // acclient.c:798842
int _E177_32()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_38, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_871AC8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871ACC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871AD0, "High");
  PStringBase<char>::PStringBase<char>(&stru_871AD4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_871AD8, "Extreme");
  return atexit(_E178_67);
}

//----- (0070BD20) --------------------------------------------------------  // acclient.c:798854
int _E180_32()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_38, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_871AE0, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_871AE4, "Wide");
  return atexit(_E181_67);
}

//----- (0070BD60) --------------------------------------------------------  // acclient.c:798863
int _E183_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_65, "None");
  return atexit(_E184_64);
}

//----- (0070BD80) --------------------------------------------------------  // acclient.c:798870
int _E186_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_65, "Speed");
  return atexit(_E187_63);
}

//----- (0070BDA0) --------------------------------------------------------  // acclient.c:798877
int _E189_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_65, "Noise");
  return atexit(_E190_64);
}

//----- (0070BDC0) --------------------------------------------------------  // acclient.c:798884
int _E192_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_65, "Sine");
  return atexit(_E193_51);
}

//----- (0070BDE0) --------------------------------------------------------  // acclient.c:798891
int _E195_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_65, "Square");
  return atexit(_E196_58);
}

//----- (0070BE00) --------------------------------------------------------  // acclient.c:798898
int _E198_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_65, "Bounce");
  return atexit(_E199_50);
}

//----- (0070BE20) --------------------------------------------------------  // acclient.c:798905
int _E201_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_65, "Perlin");
  return atexit(_E202_51);
}

//----- (0070BE40) --------------------------------------------------------  // acclient.c:798912
int _E204_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_65, "Fractal");
  return atexit(_E205_43);
}

//----- (0070BE60) --------------------------------------------------------  // acclient.c:798919
int _E207_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_65, "FrameLoop");
  return atexit(_E208_47);
}

//----- (0070BE80) --------------------------------------------------------  // acclient.c:798926
int *_E210_14()
{
  int *result; // eax@1
  signed int v1; // edx@1

  result = dword_871B18;
  v1 = 3000;
  do
  {
    *(result - 2) = 0;
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    *((_BYTE *)result + 72) = 1;
    *((_BYTE *)result + 73) = 0;
    result += 21;
    --v1;
  }
  while ( v1 );
  return result;
}
// 871B18: using guessed type int dword_871B18[];

//----- (0070BEB0) --------------------------------------------------------  // acclient.c:798950
int *_E212_3()
{
  int *result; // eax@1
  signed int v1; // edx@1

  result = dword_8AF378;
  v1 = 3000;
  do
  {
    *(result - 2) = 0;
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    *((_BYTE *)result + 72) = 1;
    *((_BYTE *)result + 73) = 0;
    result += 21;
    --v1;
  }
  while ( v1 );
  return result;
}
// 8AF378: using guessed type int dword_8AF378[];

//----- (0070BEE0) --------------------------------------------------------  // acclient.c:798974
int sub_70BEE0()
{
  return atexit(nullsub_1443);
}

//----- (007753D0) --------------------------------------------------------  // acclient.c:908821
void __cdecl _E184_64()
{
  char *v0; // esi@1

  v0 = &waveform_None_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775400) --------------------------------------------------------  // acclient.c:908834
void __cdecl _E187_63()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775430) --------------------------------------------------------  // acclient.c:908847
void __cdecl _E190_64()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775460) --------------------------------------------------------  // acclient.c:908860
void __cdecl _E193_51()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775490) --------------------------------------------------------  // acclient.c:908873
void __cdecl _E196_58()
{
  char *v0; // esi@1

  v0 = &waveform_Square_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007754C0) --------------------------------------------------------  // acclient.c:908886
void __cdecl _E199_50()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007754F0) --------------------------------------------------------  // acclient.c:908899
void __cdecl _E202_51()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775520) --------------------------------------------------------  // acclient.c:908912
void __cdecl _E205_43()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775550) --------------------------------------------------------  // acclient.c:908925
void __cdecl _E208_47()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775580) --------------------------------------------------------  // acclient.c:908938
void __cdecl _E74_86()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007755B0) --------------------------------------------------------  // acclient.c:908951
void __cdecl _E77_98()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007755E0) --------------------------------------------------------  // acclient.c:908964
void __cdecl _E80_63()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775610) --------------------------------------------------------  // acclient.c:908977
void __cdecl _E83_40()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775640) --------------------------------------------------------  // acclient.c:908990
void __cdecl sub_775640()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775670) --------------------------------------------------------  // acclient.c:909003
void __cdecl sub_775670()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007756A0) --------------------------------------------------------  // acclient.c:909016
void __cdecl sub_7756A0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007756D0) --------------------------------------------------------  // acclient.c:909029
void __cdecl sub_7756D0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775700) --------------------------------------------------------  // acclient.c:909042
void __cdecl sub_775700()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775730) --------------------------------------------------------  // acclient.c:909055
void __cdecl sub_775730()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775760) --------------------------------------------------------  // acclient.c:909068
void __cdecl _E136_87()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775790) --------------------------------------------------------  // acclient.c:909081
void __cdecl _E139_87()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007757C0) --------------------------------------------------------  // acclient.c:909094
void __cdecl _E142_82()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007757F0) --------------------------------------------------------  // acclient.c:909107
void __cdecl _E145_84()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775820) --------------------------------------------------------  // acclient.c:909120
void __cdecl _E148_80()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775850) --------------------------------------------------------  // acclient.c:909133
void __cdecl _E151_78()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775880) --------------------------------------------------------  // acclient.c:909146
void __cdecl _E154_79()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007758B0) --------------------------------------------------------  // acclient.c:909159
void __cdecl _E157_75()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007758E0) --------------------------------------------------------  // acclient.c:909172
void __cdecl _E160_78()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775910) --------------------------------------------------------  // acclient.c:909185
void __cdecl _E163_71()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775940) --------------------------------------------------------  // acclient.c:909198
void __cdecl _E166_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_38;
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

//----- (00775980) --------------------------------------------------------  // acclient.c:909223
void __cdecl _E169_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_38;
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

//----- (007759C0) --------------------------------------------------------  // acclient.c:909248
void __cdecl _E172_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_38;
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

//----- (00775A00) --------------------------------------------------------  // acclient.c:909273
void __cdecl _E175_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_38;
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

//----- (00775A40) --------------------------------------------------------  // acclient.c:909298
void __cdecl _E178_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_38;
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

//----- (00775A80) --------------------------------------------------------  // acclient.c:909323
void __cdecl _E181_67()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_65;
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

//----- (00775AC0) --------------------------------------------------------  // acclient.c:909348
void __cdecl _E216_15()
{
  if ( (s_D3DXAttributeRanges.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](s_D3DXAttributeRanges.m_data);
}

//----- (00775AE0) --------------------------------------------------------  // acclient.c:909355
void __cdecl _E215_15()
{
  if ( (s_MeshBatches.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](s_MeshBatches.m_data);
}

