/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACRenderDevice
   Object     : PORTAL\acrenderdev\ACRenderDevice.obj
   Functions  : 156
   Addresses  : 0059EF70 - 00776200 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0059EF70) --------------------------------------------------------  // acclient.c:456754
RenderIndexBuffer *__thiscall RenderIndexBufferD3D::vector_deleting_destructor(RenderIndexBufferD3D *this, unsigned int a2)
{
  RenderIndexBuffer *v2; // esi@1

  v2 = (RenderIndexBuffer *)this;
  this->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBufferD3D::vftable;
  RenderIndexBufferD3D::End(this);
  v2->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
  RenderIndexBuffer::End(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);
// 7E57A0: using guessed type int (__thiscall *RenderIndexBufferD3D::vftable)(void *, char);

//----- (0059EFB0) --------------------------------------------------------  // acclient.c:456771
int __thiscall RenderDeviceD3D::Init(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  PView *v2; // eax@1
  PView *v3; // eax@2
  PView *v4; // eax@3
  PView *v5; // eax@4
  int result; // eax@5

  v1 = this;
  v2 = (PView *)operator new(0x7Cu);
  if ( v2 )
  {
    PView::PView(v2, 1);
    RenderDeviceD3D::indoor_pview = v3;
    if ( !v3 )
      return 0;
    v4 = (PView *)operator new(0x7Cu);
    if ( v4 )
    {
      PView::PView(v4, 0);
      RenderDeviceD3D::outdoor_pview = v5;
      if ( !v5 )
        return 0;
      v1->m_pSolidColorTexture = 0;
      v1->m_pCurrMaterial = 0;
      v1->m_bMaterialAlphaMode = 0;
      v1->m_ParticleState = 0;
      v1->m_currentlyDrawingSky = 0;
      v1->m_primitiveVbuf = 0;
      LODWORD(v1->m_gammaBrightnessVal) = 0;
      LODWORD(v1->m_defaultMaterial.Diffuse.r) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Diffuse.g) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Diffuse.b) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Diffuse.a) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Ambient.r) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Ambient.g) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Ambient.b) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Ambient.a) = 1065353216;
      LODWORD(v1->m_defaultMaterial.Emissive.r) = 0;
      LODWORD(v1->m_defaultMaterial.Emissive.g) = 0;
      LODWORD(v1->m_defaultMaterial.Emissive.b) = 0;
      LODWORD(v1->m_defaultMaterial.Emissive.a) = 0;
      LODWORD(v1->m_defaultMaterial.Specular.r) = 0;
      LODWORD(v1->m_defaultMaterial.Specular.g) = 0;
      LODWORD(v1->m_defaultMaterial.Specular.b) = 0;
      LODWORD(v1->m_defaultMaterial.Specular.a) = 0;
      LODWORD(v1->m_defaultMaterial.Power) = 0;
      v1->m_currentSolidColor = -16777216;
      result = 1;
    }
    else
    {
      RenderDeviceD3D::outdoor_pview = 0;
      result = 0;
    }
  }
  else
  {
    RenderDeviceD3D::indoor_pview = 0;
    result = 0;
  }
  return result;
}

//----- (0059F0C0) --------------------------------------------------------  // acclient.c:456837
void __stdcall RenderDeviceD3D::SetLandscape(LScape *lscape)
{
  RenderDeviceD3D::indoor_pview->lscape = lscape;
}

//----- (0059F0D0) --------------------------------------------------------  // acclient.c:456843
void __stdcall RenderDeviceD3D::DrawInside(CEnvCell *cell)
{
  PView::DrawInside(RenderDeviceD3D::indoor_pview, cell);
}

//----- (0059F0E0) --------------------------------------------------------  // acclient.c:456849
void __stdcall RenderDeviceD3D::DrawPortal(CPortalPoly *portal, int check, int portalPolyOrPortalContents)
{
  RenderDeviceD3D::backup_building_view = RenderDeviceD3D::building_view;
  RenderDeviceD3D::building_view = -1;
  PView::DrawPortal(RenderDeviceD3D::outdoor_pview, portal, check, portalPolyOrPortalContents);
  RenderDeviceD3D::building_view = RenderDeviceD3D::backup_building_view;
}
// 820E44: using guessed type __int32 RenderDeviceD3D::building_view;
// 820E48: using guessed type __int32 RenderDeviceD3D::backup_building_view;

//----- (0059F120) --------------------------------------------------------  // acclient.c:456860
void __stdcall RenderDeviceD3D::DrawLandCell(CLandCell *cell)
{
  ACRender::landPolysDraw(cell->polygons, 2);
}

//----- (0059F140) --------------------------------------------------------  // acclient.c:456866
void __thiscall RenderDeviceD3D::DrawSortCell(RenderDeviceD3D *this, CSortCell *cell)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( cell->building )
    ((void (__stdcall *)(_DWORD))this->vfptr->DrawBuilding)(cell->building);
  v2->vfptr->DrawObjCell((RenderDevice *)v2, (CObjCell *)cell);
}

//----- (0059F170) --------------------------------------------------------  // acclient.c:456877
void __stdcall RenderDeviceD3D::DrawEnvCell(CEnvCell *cell)
{
  float v2; // ST14_4@3
  CCellStruct *v3; // eax@6
  unsigned int v4; // ecx@6
  int v5; // edx@7

  if ( !CEnvCell::GetDrawnThisFrame(cell) )
  {
    CEnvCell::SetDrawnThisFrame(cell);
    Render::obj_view_set();
    if ( !skipMinimStep )
    {
      v2 = BSPTREE::GetSphere(cell->structure->drawing_bsp)->radius;
      Render::minimize_envcell_lighting();
    }
    Render::curr_detail_surface = Render::environment_detail_surface;
    Render::curr_detail_tiling = Render::environment_detail_tiling;
    Render::curr_detail_src_blend = 9;
    Render::curr_detail_dst_blend = 6;
    if ( cell->use_built_mesh )
    {
      D3DPolyRender::SetStaticLightingVertexColors(cell->constructed_mesh, &cell->pos);
      D3DPolyRender::DrawMesh(cell->num_surfaces, cell->surfaces, cell->constructed_mesh, 1);
      Render::curr_detail_surface = 0;
    }
    else
    {
      v3 = cell->structure;
      v4 = 0;
      if ( v3->num_polygons )
      {
        v5 = 0;
        do
        {
          Render::PolyNext->poly = &v3->polygons[v5];
          Render::PolyNext->planeMask = -1;
          ++Render::PolyNext;
          v3 = cell->structure;
          ++v4;
          ++v5;
        }
        while ( v4 < v3->num_polygons );
      }
      ((void (*)(void))Render::m_pRenderer->vfptr->polyListFinishInternal)();
      Render::PolyNext = (struct polyListEntry *)&Render::PolyList;
      Render::curr_detail_surface = 0;
    }
  }
}
// 81ECAC: using guessed type float Render::environment_detail_tiling;
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;
// 86635C: using guessed type struct CSurface *Render::environment_detail_surface;

//----- (0059F2A0) --------------------------------------------------------  // acclient.c:456932
void __stdcall RenderDeviceD3D::DrawBuilding(CBuildingObj *building)
{
  CPhysicsPart *v2; // eax@1

  RenderDeviceD3D::outdoor_pview->outdoor_portal_list = building->portals;
  CPhysicsPart::UpdateViewerDistance(*building->part_array->parts);
  v2 = *building->part_array->parts;
  if ( v2->gfxobj[v2->deg_level] )
  {
    CBuildingObj::curr_pos = &building->m_position;
    Render::curr_detail_surface = Render::building_detail_surface;
    Render::curr_detail_tiling = Render::building_detail_tiling;
    Render::curr_detail_src_blend = 9;
    Render::curr_detail_dst_blend = 6;
    D3DPolyRender::FlushAlphaList(0.0);
    CPhysicsPart::Draw(*building->part_array->parts, 1);
    RenderDeviceD3D::ObjBuildingOrBuildingPart = 1;
    CPhysicsPart::Draw(*building->part_array->parts, 0);
    RenderDeviceD3D::ObjBuildingOrBuildingPart = 0;
    Render::curr_detail_surface = 0;
  }
}
// 81ECB0: using guessed type float Render::building_detail_tiling;
// 866358: using guessed type struct CSurface *Render::building_detail_surface;
// 8ED3C4: using guessed type int RenderDeviceD3D::ObjBuildingOrBuildingPart;

//----- (0059F360) --------------------------------------------------------  // acclient.c:456959
signed int __stdcall RenderDeviceD3D::DrawMeshInternal(CGfxObj *i_pObj, bool i_bBuilding, BoundingType i_bt)
{
  CPhysicsPart *v4; // esi@1
  __int32 v5; // edi@10

  v4 = RenderDeviceD3D::s_current_physics_part;
  if ( !i_bBuilding
    && RenderDeviceD3D::s_current_physics_part
    && !(unsigned __int8)CPhysicsPart::IsPartOfPlayerObj(RenderDeviceD3D::s_current_physics_part) )
  {
    if ( CPhysicsPart::GetDrawnThisFrame(v4) )
      return 2;
    CPhysicsPart::SetDrawnThisFrame(v4);
  }
  if ( !Render::useSunlight )
    Render::minimize_object_lighting();
  if ( i_pObj->use_built_mesh )
  {
    if ( i_bBuilding )
    {
      Render::obj_view_set();
      v5 = RenderDeviceD3D::building_view;
      RenderDeviceD3D::building_view = Render::portal_view_num;
      BSPTREE::build_draw_portals_only(i_pObj->drawing_bsp, 1);
      BSPTREE::build_draw_portals_only(i_pObj->drawing_bsp, 2);
      RenderDeviceD3D::building_view = v5;
      return 2;
    }
    D3DPolyRender::DrawMesh(i_pObj, i_pObj->constructed_mesh);
  }
  return 2;
}
// 820E44: using guessed type __int32 RenderDeviceD3D::building_view;
// 8662DC: using guessed type int Render::portal_view_num;
// 866334: using guessed type int Render::useSunlight;

//----- (0059F410) --------------------------------------------------------  // acclient.c:456996
void RenderDeviceD3D::CreateSurface()
{
  RenderSurfaceD3D *v1; // eax@1

  v1 = (RenderSurfaceD3D *)operator new(0x130u);
  if ( v1 )
    RenderSurfaceD3D::RenderSurfaceD3D(v1);
}

//----- (0059F430) --------------------------------------------------------  // acclient.c:457006
void RenderDeviceD3D::CreateTexture()
{
  RenderTextureD3D *v1; // eax@1

  v1 = (RenderTextureD3D *)operator new(0xB0u);
  if ( v1 )
    RenderTextureD3D::RenderTextureD3D(v1);
}

//----- (0059F450) --------------------------------------------------------  // acclient.c:457016
RenderIndexBufferD3D *RenderDeviceD3D::CreateIndexBuffer()
{
  RenderIndexBuffer *v1; // eax@1
  RenderIndexBufferD3D *v2; // esi@1
  RenderIndexBufferD3D *result; // eax@2

  v1 = (RenderIndexBuffer *)operator new(0x2Cu);
  v2 = (RenderIndexBufferD3D *)v1;
  if ( v1 )
  {
    v1->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
    RenderIndexBuffer::Begin(v1);
    v2->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBufferD3D::vftable;
    RenderIndexBufferD3D::Begin(v2);
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);
// 7E57A0: using guessed type int (__thiscall *RenderIndexBufferD3D::vftable)(void *, char);

//----- (0059F490) --------------------------------------------------------  // acclient.c:457042
void __thiscall RenderDeviceD3D::SetVertexStream(RenderDeviceD3D *this, const unsigned int _StreamIndex, RenderVertexStreamD3D *_pStream)
{
  RenderDeviceD3D *v3; // esi@1
  IDirect3DVertexBuffer9 *v4; // eax@1

  v3 = this;
  v4 = RenderVertexStreamD3D::GetD3DVertexBuffer(_pStream);
  if ( v4 )
    ((void (__stdcall *)(_DWORD, const unsigned int, IDirect3DVertexBuffer9 *, _DWORD, unsigned int))v3->m_pDirect3DDevice->vfptr[33].AddRef)(
      v3->m_pDirect3DDevice,
      _StreamIndex,
      v4,
      0,
      _pStream->m_VertexFormatInfo.size);
}

//----- (0059F4D0) --------------------------------------------------------  // acclient.c:457059
char __thiscall RenderDeviceD3D::IsResetPossible(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  char result; // al@2

  v1 = this;
  if ( ((int (__stdcall *)(_DWORD))this->m_pDirect3DDevice->vfptr[1].QueryInterface)(this->m_pDirect3DDevice) == -2005530520 )
  {
    v1->m_bDeviceLost = 1;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0059F500) --------------------------------------------------------  // acclient.c:457078
void __stdcall RenderDeviceD3D::ApplyVertexFormat(VertexFormatInfo *_VFI)
{
  (*(void (__stdcall **)(_DWORD, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 356))(
    LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
    _VFI->format);
}

//----- (0059F520) --------------------------------------------------------  // acclient.c:457086
char __thiscall RenderDeviceD3D::DetectDeviceCaps(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  unsigned int v2; // ecx@1
  unsigned int v3; // edi@1
  unsigned int v4; // ebp@1
  unsigned int v5; // edx@1
  unsigned int v6; // eax@1
  unsigned int v7; // ecx@1
  unsigned int v8; // edx@3
  unsigned int v9; // ecx@3
  char v10; // al@3
  bool v11; // al@5
  double v12; // st7@7
  unsigned int v13; // eax@7
  unsigned int v14; // ecx@7
  unsigned int v15; // ebx@7
  unsigned int v16; // eax@7
  unsigned int v17; // ecx@7
  bool v18; // zf@7
  unsigned int v19; // eax@8
  bool v20; // al@9
  char result; // al@15
  _D3DADAPTER_IDENTIFIER9 D3DAdapterIdentifier; // [sp+Ch] [bp-44Ch]@1

  v1 = this;
  ((void (__stdcall *)(IDirect3D9 *, unsigned int, _DWORD, _D3DADAPTER_IDENTIFIER9 *))Render::m_pRenderer->m_pDirect3D->vfptr[1].Release)(
    Render::m_pRenderer->m_pDirect3D,
    this->m_AdapterID,
    0,
    &D3DAdapterIdentifier);
  ((void (__stdcall *)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, _D3DCAPS9 *))Render::m_pRenderer->m_pDirect3D->vfptr[4].Release)(
    Render::m_pRenderer->m_pDirect3D,
    v1->m_AdapterID,
    v1->m_D3DDeviceType,
    &v1->m_D3DCaps);
  v2 = v1->m_D3DCaps.MaxTextureHeight;
  v3 = v1->m_D3DCaps.MaxSimultaneousTextures;
  v4 = v1->m_D3DCaps.MaxTextureBlendStages;
  v5 = v1->m_D3DCaps.NumSimultaneousRTs;
  v1->m_caps.MaxTextureWidth = v1->m_D3DCaps.MaxTextureWidth;
  v6 = v1->m_D3DCaps.MaxActiveLights;
  v1->m_caps.MaxTextureHeight = v2;
  v7 = v1->m_D3DCaps.MaxUserClipPlanes;
  v1->m_caps.MaxSimultaneousTextures = v3;
  v1->m_caps.MaxTextureBlendStages = v4;
  v1->m_caps.MaxSimultaneousRenderTargets = v5;
  v1->m_caps.MaxActiveLights = v6;
  v1->m_caps.MaxUserClipPlanes = v7;
  if ( v6 > 8 )
    v1->m_caps.MaxActiveLights = 8;
  v8 = v1->m_D3DCaps.TextureOpCaps;
  v9 = v1->m_D3DCaps.TextureOpCaps >> 21;
  v1->m_caps.bTexOpDotProduct3 = (v1->m_D3DCaps.TextureOpCaps >> 23) & 1;
  v10 = LOBYTE(v1->m_D3DCaps.Caps3);
  v1->m_caps.bTexOpBumpEnvMap = v9 & 1;
  v11 = v10 & 0x20 && SLOBYTE(v1->m_D3DCaps.PrimitiveMiscCaps) < 0;
  v1->m_caps.bDestinationAlpha = v11;
  v12 = v1->m_D3DCaps.MaxPointSize;
  v13 = v1->m_D3DCaps.TextureCaps;
  v1->m_caps.bSquareTexturesOnly = (v1->m_D3DCaps.TextureCaps >> 5) & 1;
  v1->m_caps.bCubeTextures = (v13 >> 11) & 1;
  v1->m_caps.b3DTextures = (v13 >> 13) & 1;
  v14 = v1->m_D3DCaps.PrimitiveMiscCaps;
  v1->m_caps.bColorWriteControl = (v1->m_D3DCaps.PrimitiveMiscCaps >> 7) & 1;
  v1->m_caps.bHardwareVertexProcessing = BYTE2(v1->m_D3DCaps.DevCaps) & 1;
  v1->m_caps.bSimpleNonPowerOfTwoTextures = 0;
  v1->m_caps.bPointSprites = v12 >= 64.0;
  v15 = v1->m_D3DCaps.Caps2;
  v1->m_caps.bDynamicTextures = (v15 >> 29) & 1;
  v16 = v1->m_D3DCaps.RasterCaps >> 25;
  v1->m_caps.bBlendOp = (v14 >> 11) & 1;
  v17 = v1->m_D3DCaps.StencilCaps >> 8;
  v1->m_caps.bSlopeScaleDepthBias = v16 & 1;
  v18 = D3DAdapterIdentifier.VendorId == 4318;
  v1->m_caps.bAutoGenMipMaps = (v15 >> 30) & 1;
  v1->m_caps.bTwoSidedStencil = v17 & 1;
  v20 = 0;
  if ( v18 )
  {
    v19 = v1->m_D3DCaps.PixelShaderVersion;
    if ( !(BYTE1(v19) & 0xF) )
      v20 = 1;
  }
  if ( v3 >= 2 && v4 >= 2 && SBYTE1(v8) < 0 && v8 & 0x10000 )
  {
    v18 = v20 == 0;
    result = 1;
    if ( v18 )
      v1->m_caps.bCanDoSinglePassDetailing = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0059F6F0) --------------------------------------------------------  // acclient.c:457185
void __thiscall RenderDeviceD3D::SetViewport(RenderDeviceD3D *this, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool i_UseAutoAspect)
{
  RenderDeviceD3D *v6; // esi@1
  unsigned int v7; // edx@1
  unsigned int v8; // eax@1
  unsigned int v9; // edx@1
  IDirect3DDevice9 *v10; // esi@1
  _D3DVIEWPORT9 D3DViewport; // [sp+4h] [bp-18h]@1

  v6 = this;
  RenderDevice::SetViewport((RenderDevice *)&this->vfptr, x, y, width, height, i_UseAutoAspect);
  v7 = v6->m_viewportX;
  v8 = v6->m_viewportY;
  D3DViewport.Width = v6->m_viewportWidth;
  D3DViewport.X = v7;
  v9 = v6->m_viewportHeight;
  v10 = v6->m_pDirect3DDevice;
  D3DViewport.Y = v8;
  D3DViewport.Height = v9;
  LODWORD(D3DViewport.MinZ) = 0;
  LODWORD(D3DViewport.MaxZ) = 1065353216;
  ((void (__stdcall *)(IDirect3DDevice9 *, _D3DVIEWPORT9 *))v10->vfptr[15].Release)(v10, &D3DViewport);
}

//----- (0059F770) --------------------------------------------------------  // acclient.c:457210
signed int __thiscall RenderDeviceD3D::SelectPixelFormat(RenderDeviceD3D *this, PixelFormatID displayFormat, const unsigned int usage, _D3DRESOURCETYPE resource, const bool use32, const char *formats, const unsigned int numFormats)
{
  const unsigned int v7; // ebp@1
  RenderDeviceD3D *v8; // edi@1
  signed int v9; // esi@4

  v7 = 0;
  v8 = this;
  if ( numFormats )
  {
    while ( 1 )
    {
      switch ( formats[v7] )
      {
        case 0:
          if ( !use32 )
            goto LABEL_17;
          v9 = 20;
          goto LABEL_16;
        case 1:
          if ( !use32 )
            goto LABEL_17;
          v9 = 21;
          goto LABEL_16;
        case 2:
          if ( !use32 )
            goto LABEL_17;
          v9 = 22;
          goto LABEL_16;
        case 3:
          v9 = 23;
          goto LABEL_16;
        case 4:
          v9 = 24;
          goto LABEL_16;
        case 5:
          v9 = 25;
          goto LABEL_16;
        case 6:
          v9 = 26;
          goto LABEL_16;
        case 7:
          v9 = 30;
          goto LABEL_16;
        case 8:
          v9 = 29;
          goto LABEL_16;
        case 9:
          v9 = 28;
LABEL_16:
          if ( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))Render::m_pRenderer->m_pDirect3D->vfptr[3].AddRef)(
                 Render::m_pRenderer->m_pDirect3D,
                 v8->m_AdapterID,
                 v8->m_D3DDeviceType,
                 displayFormat,
                 usage,
                 resource,
                 v9) )
            goto LABEL_17;
          return v9;
        default:
LABEL_17:
          ++v7;
          if ( v7 >= numFormats )
            return 0;
          break;
      }
    }
  }
  return 0;
}

//----- (0059F870) --------------------------------------------------------  // acclient.c:457283
char __thiscall RenderDeviceD3D::ChoosePixelFormats(RenderDeviceD3D *this, PixelFormatID displayFormat)
{
  RenderDeviceD3D *v2; // esi@1
  signed int v3; // eax@7
  PixelFormatID v4; // ecx@7
  PixelFormatID v5; // edx@7
  char fARGB[9]; // [sp+8h] [bp-90h]@1
  char fRGB[9]; // [sp+14h] [bp-84h]@1
  char fAlpha[5]; // [sp+20h] [bp-78h]@1
  PixelFormatDesc PFD_RGB; // [sp+28h] [bp-70h]@1
  PixelFormatDesc PFD_ARGB; // [sp+60h] [bp-38h]@1

  fRGB[8] = 8;
  fARGB[2] = 8;
  fAlpha[2] = 8;
  v2 = this;
  fRGB[6] = 6;
  fARGB[1] = 6;
  fAlpha[3] = 6;
  fRGB[0] = 0;
  fRGB[1] = 2;
  fRGB[2] = 1;
  fRGB[3] = 3;
  fRGB[4] = 4;
  fRGB[5] = 5;
  fRGB[7] = 7;
  fARGB[0] = 1;
  fARGB[3] = 5;
  fARGB[4] = 0;
  fARGB[5] = 2;
  fARGB[6] = 3;
  fARGB[7] = 4;
  fARGB[8] = 7;
  fAlpha[0] = 9;
  fAlpha[1] = 1;
  fAlpha[4] = 5;
  this->m_displayInfo.pfRenderTargets = RenderDeviceD3D::SelectPixelFormat(
                                          this,
                                          displayFormat,
                                          1u,
                                          D3DRTYPE_TEXTURE,
                                          1,
                                          fRGB,
                                          9u);
  v2->m_displayInfo.pfRGBTextures = RenderDeviceD3D::SelectPixelFormat(
                                      v2,
                                      displayFormat,
                                      0,
                                      D3DRTYPE_TEXTURE,
                                      1,
                                      fRGB,
                                      9u);
  v2->m_displayInfo.pfARGBTextures = RenderDeviceD3D::SelectPixelFormat(
                                       v2,
                                       displayFormat,
                                       0,
                                       D3DRTYPE_TEXTURE,
                                       1,
                                       fARGB,
                                       9u);
  ClipPlane::ClipPlane((ClipPlane *)&PFD_RGB);
  ClipPlane::ClipPlane((ClipPlane *)&PFD_ARGB);
  PixelFormatDesc::SetFormat(&PFD_RGB, v2->m_displayInfo.pfRGBTextures);
  PixelFormatDesc::SetFormat(&PFD_ARGB, v2->m_displayInfo.pfARGBTextures);
  if ( PFD_RGB.format != PFD_ARGB.format
    && PFD_RGB.bitsPerPixel == PFD_ARGB.bitsPerPixel
    && PFD_RGB.redBitCount == PFD_ARGB.redBitCount
    && PFD_RGB.greenBitCount == PFD_ARGB.greenBitCount
    && PFD_RGB.blueBitCount == PFD_ARGB.blueBitCount )
    v2->m_displayInfo.pfRGBTextures = v2->m_displayInfo.pfARGBTextures;
  v3 = RenderDeviceD3D::SelectPixelFormat(v2, displayFormat, 0, D3DRTYPE_TEXTURE, 1, fAlpha, 5u);
  v4 = v2->m_displayInfo.pfRGBTextures;
  v5 = v2->m_displayInfo.pfARGBTextures;
  v2->m_displayInfo.pfAlphaTextures = v3;
  v2->m_displayInfo.pfAlphaSurfaces = v3;
  v2->m_displayInfo.pfRGBSurfaces = v4;
  v2->m_displayInfo.pfARGBSurfaces = v5;
  v2->m_displayInfo.pfLowRGBSurfaces = RenderDeviceD3D::SelectPixelFormat(
                                         v2,
                                         displayFormat,
                                         0,
                                         D3DRTYPE_TEXTURE,
                                         0,
                                         fRGB,
                                         9u);
  v2->m_displayInfo.pfLowARGBSurfaces = RenderDeviceD3D::SelectPixelFormat(
                                          v2,
                                          displayFormat,
                                          0,
                                          D3DRTYPE_TEXTURE,
                                          0,
                                          fARGB,
                                          9u);
  ClipPlane::ClipPlane((ClipPlane *)&PFD_ARGB);
  ClipPlane::ClipPlane((ClipPlane *)&PFD_RGB);
  PixelFormatDesc::SetFormat(&PFD_ARGB, v2->m_displayInfo.pfLowRGBSurfaces);
  PixelFormatDesc::SetFormat(&PFD_RGB, v2->m_displayInfo.pfLowARGBSurfaces);
  if ( PFD_ARGB.format != PFD_RGB.format
    && PFD_ARGB.bitsPerPixel == PFD_RGB.bitsPerPixel
    && PFD_ARGB.redBitCount == PFD_RGB.redBitCount
    && PFD_ARGB.greenBitCount == PFD_RGB.greenBitCount
    && PFD_ARGB.blueBitCount == PFD_RGB.blueBitCount )
    v2->m_displayInfo.pfLowRGBSurfaces = v2->m_displayInfo.pfLowARGBSurfaces;
  v2->m_displayInfo.pfLowAlphaSurfaces = RenderDeviceD3D::SelectPixelFormat(
                                           v2,
                                           displayFormat,
                                           0,
                                           D3DRTYPE_TEXTURE,
                                           0,
                                           fARGB,
                                           9u);
  return 1;
}

//----- (0059FAB0) --------------------------------------------------------  // acclient.c:457398
bool __thiscall RenderDeviceD3D::CheckDisplayModes(RenderDeviceD3D *this, PixelFormatID displayFormat, const unsigned int _DesiredRefreshRate, unsigned int *optimalRefreshRate)
{
  PixelFormatID v4; // ebp@1
  RenderDeviceD3D *v5; // esi@1
  int v6; // eax@1
  bool v7; // cl@1
  unsigned int v8; // edi@1
  bool result; // al@10
  unsigned int numModes; // [sp+20h] [bp-14h]@1
  _D3DDISPLAYMODE mode; // [sp+24h] [bp-10h]@2
  bool displayFormata; // [sp+38h] [bp+4h]@1

  v4 = displayFormat;
  v5 = this;
  v6 = Render::m_pRenderer->m_pDirect3D->vfptr[2].QueryInterface(
         (IUnknown *)Render::m_pRenderer->m_pDirect3D,
         (_GUID *)this->m_AdapterID,
         (void **)displayFormat);
  v7 = v5->m_presentation.FullScreen == 0;
  v8 = 0;
  numModes = v6;
  displayFormata = v5->m_presentation.FullScreen == 0;
  *optimalRefreshRate = 0;
  if ( v6 )
  {
    do
    {
      ((void (__stdcall *)(IDirect3D9 *, unsigned int, PixelFormatID, unsigned int, _D3DDISPLAYMODE *))Render::m_pRenderer->m_pDirect3D->vfptr[2].AddRef)(
        Render::m_pRenderer->m_pDirect3D,
        v5->m_AdapterID,
        v4,
        v8,
        &mode);
      if ( mode.Format == v4 )
      {
        if ( v5->m_presentation.FullScreen )
        {
          if ( mode.Width == v5->m_presentation.Width && mode.Height == v5->m_presentation.Height )
          {
            displayFormata = 1;
            if ( mode.RefreshRate > *optimalRefreshRate && mode.RefreshRate <= _DesiredRefreshRate )
              *optimalRefreshRate = mode.RefreshRate;
          }
        }
      }
      ++v8;
    }
    while ( v8 < numModes );
    result = displayFormata;
  }
  else
  {
    result = v7;
  }
  return result;
}

//----- (0059FB70) --------------------------------------------------------  // acclient.c:457456
void __thiscall RenderDeviceD3D::ReleaseD3DResources(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  IDirect3DVertexBuffer9 *v2; // eax@1
  IDirect3DSwapChain9 *v3; // eax@3
  IDirect3DTexture9 *v4; // eax@5

  v1 = this;
  RenderDevice::ReleaseSurfaceResources((RenderDevice *)&this->vfptr);
  v2 = v1->m_primitiveVbuf;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_primitiveVbuf);
    v1->m_primitiveVbuf = 0;
  }
  v3 = v1->m_pPrimarySwapChain;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v1->m_pPrimarySwapChain);
    v1->m_pPrimarySwapChain = 0;
  }
  v4 = v1->m_pSolidColorTexture;
  if ( v4 )
  {
    v4->vfptr->Release((IUnknown *)v1->m_pSolidColorTexture);
    v1->m_pSolidColorTexture = 0;
  }
}

//----- (0059FBD0) --------------------------------------------------------  // acclient.c:457486
void __thiscall RenderDeviceD3D::SetupDisplayAspectRatio(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  float v2; // ST04_4@3

  v1 = this;
  if ( dword_81EFA8 == 1 )
  {
    LODWORD(this->m_DisplayAspectRatio) = 1068149419;
  }
  else if ( dword_81EFA8 == 2 )
  {
    LODWORD(this->m_DisplayAspectRatio) = 1071877689;
  }
  else
  {
    v2 = (double)RenderDevice::GetDisplayWidth((RenderDevice *)&this->vfptr);
    v1->m_DisplayAspectRatio = v2 / (double)RenderDevice::GetDisplayHeight((RenderDevice *)&v1->vfptr);
  }
}
// 81EFA8: using guessed type int dword_81EFA8;

//----- (0059FC50) --------------------------------------------------------  // acclient.c:457509
void __thiscall RenderDeviceD3D::SetMipmapLODBiasForAllSamplers(RenderDeviceD3D *this, const float _Bias)
{
  RenderDeviceD3D *v2; // edi@1
  signed int v3; // esi@1

  v2 = this;
  v3 = 15;
  do
    RenderDeviceD3D::SetSamplerMipmapLODBias(v2, v3--, _Bias);
  while ( v3 >= 0 );
}

//----- (0059FC80) --------------------------------------------------------  // acclient.c:457522
void __thiscall RenderDeviceD3D::BeginScene(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  bool v2; // cf@2
  signed int v3; // edi@5
  const float MipMapLODBias; // [sp+4h] [bp-4h]@3

  v1 = this;
  if ( !this->m_bOpenScene )
  {
    this->m_pDirect3DDevice->vfptr[13].Release((IUnknown *)this->m_pDirect3DDevice);
    v2 = v1->m_WireframeMode != 0;
    v1->m_bOpenScene = 1;
    RenderDeviceD3D::SetFillMode(v1, (FillModeType)(3 - v2));
    if ( Render::m_RenderPrefs.TextureFiltering == 2 )
      MipMapLODBias = -1.4;
    else
      MipMapLODBias = Render::m_pRenderer->m_GlobalMipmapLODBias;
    v3 = 15;
    do
      RenderDeviceD3D::SetSamplerMipmapLODBias(v1, v3--, MipMapLODBias);
    while ( v3 >= 0 );
  }
}
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;

//----- (0059FD00) --------------------------------------------------------  // acclient.c:457549
void __thiscall RenderDeviceD3D::EndScene(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1

  v1 = this;
  if ( this->m_bOpenScene )
  {
    ((void (__stdcall *)(_DWORD))this->m_pDirect3DDevice->vfptr[14].QueryInterface)(this->m_pDirect3DDevice);
    v1->m_bOpenScene = 0;
  }
}

//----- (0059FD30) --------------------------------------------------------  // acclient.c:457562
void __thiscall RenderDeviceD3D::Clear(RenderDeviceD3D *this, unsigned int clearFlags, RGBAColor *color, const float depth)
{
  RenderDeviceD3D *v4; // esi@1
  signed int v5; // edi@1
  float v6; // ecx@1
  unsigned int height; // [sp+30h] [bp-20h]@1
  unsigned int width; // [sp+34h] [bp-1Ch]@1
  unsigned int y; // [sp+38h] [bp-18h]@1
  unsigned int x; // [sp+3Ch] [bp-14h]@1

  v4 = this;
  x = this->m_viewportX;
  v5 = 0;
  height = this->m_viewportHeight;
  y = this->m_viewportY;
  width = this->m_viewportWidth;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->SetViewport)(
    0,
    0,
    this->m_presentation.Width,
    this->m_presentation.Height,
    0);
  v6 = color->a;
  if ( clearFlags & 1 )
    v5 = 1;
  if ( clearFlags & 2 )
  {
    LOBYTE(v6) = v4->m_displayInfo.bStencilBuffer;
    if ( LOBYTE(v6) )
      v5 |= 4u;
  }
  if ( clearFlags & 4 )
    v5 |= 2u;
  if ( v5 )
    ((void (__fastcall *)(float, _DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD))v4->m_pDirect3DDevice->vfptr[14].AddRef)(
      LODWORD(v6),
      (unsigned __int64)(color->b * 255.0) >> 32,
      v4->m_pDirect3DDevice,
      0,
      0,
      v5,
      (unsigned __int64)(color->b * 255.0) | (((unsigned int)(unsigned __int64)(color->g * 255.0) | (((unsigned int)(unsigned __int64)(color->r * 255.0) | 0x6600) << 8)) << 8),
      LODWORD(depth),
      0);
  v4->vfptr->SetViewport((RenderDevice *)v4, x, y, width, height, 0);
}

//----- (0059FE50) --------------------------------------------------------  // acclient.c:457610
void __thiscall RenderDeviceD3D::Flip(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  char *v2; // edi@1
  char *v3; // ebx@1
  int v4; // eax@3
  unsigned int v5; // edi@6

  v1 = this;
  v2 = 0;
  v3 = 0;
  if ( !this->m_presentation.FullScreen )
  {
    v2 = (char *)&this->m_PresentSourceRect;
    v3 = (char *)&this->m_PresentDestRect;
  }
  do
    v4 = ((int (__stdcall *)(_DWORD, char *, char *, _DWORD, _DWORD, signed int))v1->m_pPrimarySwapChain->vfptr[1].QueryInterface)(
           v1->m_pPrimarySwapChain,
           v2,
           v3,
           v1->m_hPresentWindow,
           0,
           1);
  while ( v4 == -2005532132 );
  if ( v4 == -2005530520 )
    v1->m_bDeviceLost = 1;
  v5 = 0;
  do
    RenderDeviceD3D::SetStageTexture(v1, v5++, 0);
  while ( v5 < 8 );
  D3DPolyRender::ResetDynamicBuffers(Render::m_pRenderer);
  Profiler::ResetFrameStats();
  ++v1->m_nFrameStamp;
}

//----- (0059FEE0) --------------------------------------------------------  // acclient.c:457647
void __thiscall RenderDeviceD3D::SetCurrentMaterial(RenderDeviceD3D *this, CMaterial *material, bool force)
{
  RenderDeviceD3D *v3; // esi@1
  IDirect3DDevice9 *v4; // eax@3
  IUnknownVtbl *v5; // ecx@3

  v3 = this;
  if ( material != this->m_pCurrMaterial || force )
  {
    v4 = this->m_pDirect3DDevice;
    this->m_pCurrMaterial = material;
    v5 = v4->vfptr;
    if ( material )
    {
      ((void (__stdcall *)(IDirect3DDevice9 *, _D3DMATERIAL9 *))v5[16].AddRef)(v4, &material->d3d_material);
      v3->m_bMaterialAlphaMode = material->has_alpha != 0;
      RenderDeviceD3D::SetFFDiffuseColorSource(v3, 0);
      RenderDeviceD3D::SetFFAmbientColorSource(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(IDirect3DDevice9 *, int))v5[16].AddRef)(v4, &v3->m_defaultMaterial);
      v3->m_bMaterialAlphaMode = 0;
      RenderDeviceD3D::SetFFDiffuseColorSource(v3, FromVertex);
      RenderDeviceD3D::SetFFAmbientColorSource(v3, FromVertex);
    }
  }
}

//----- (0059FF70) --------------------------------------------------------  // acclient.c:457677
char __thiscall RenderDeviceD3D::SetSolidColorTextureColor(RenderDeviceD3D *this, unsigned int color, bool force)
{
  RenderDeviceD3D *v3; // esi@1
  IDirect3DTexture9 *v4; // eax@3
  _D3DLOCKED_RECT lockedRect; // [sp+10h] [bp-8h]@4

  v3 = this;
  if ( this->m_currentSolidColor != color || force )
  {
    v4 = this->m_pSolidColorTexture;
    if ( !v4
      || ((int (__stdcall *)(IDirect3DTexture9 *, _DWORD, _D3DLOCKED_RECT *, _DWORD, _DWORD))v4->vfptr[6].AddRef)(
           v4,
           0,
           &lockedRect,
           0,
           0) < 0 )
      return 0;
    *(_DWORD *)lockedRect.pBits = color;
    v3->m_currentSolidColor = color;
    ((void (__stdcall *)(_DWORD, _DWORD))v3->m_pSolidColorTexture->vfptr[6].Release)(v3->m_pSolidColorTexture, 0);
  }
  return 1;
}

//----- (0059FFE0) --------------------------------------------------------  // acclient.c:457703
char __thiscall RenderDeviceD3D::SetDefaultDeviceStates(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  unsigned int v2; // edi@1
  const unsigned int v3; // edi@3
  const unsigned int v4; // edi@5

  v1 = this;
  this->m_bForceStates = 1;
  RenderDeviceD3D::SetAlphaBlendEnable(this, 0);
  RenderDeviceD3D::SetAlphaTestEnable(v1, 0);
  RenderDeviceD3D::SetAlphaTestFunction(v1, ALPHATESTFUNC_GREATEREQUAL);
  RenderDeviceD3D::SetAlphaTestRef(v1, 1u);
  RenderDeviceD3D::SetBlendFunction(v1, BLEND_ONE, BLEND_ZERO, BLENDOP_ADD);
  RenderDeviceD3D::SetCullMode(v1, CULLMODE_NONE);
  RenderDeviceD3D::SetDepthBias(v1, 0.0);
  RenderDeviceD3D::SetDepthBufferEnable(v1, 0);
  RenderDeviceD3D::SetDepthBufferMode(v1, DEPTHTEST_ALWAYS, 0);
  RenderDeviceD3D::SetFFAmbientColor32(v1, 0);
  RenderDeviceD3D::SetFFDiffuseColorSource(v1, FromVertex);
  RenderDeviceD3D::SetFFSpecularColorSource(v1, FromVertex);
  RenderDeviceD3D::SetFFFogEnable(v1, 0);
  RenderDeviceD3D::SetFFFogProperties(v1, &Color, 0.0, 1000.0);
  RenderDeviceD3D::SetFFLighting(v1, 0);
  v2 = 0;
  do
    RenderDeviceD3D::SetFFLightEnable(v1, v2++, 0);
  while ( v2 < 8 );
  RenderDeviceD3D::SetFFSpecularEnable(v1, 0);
  RenderDeviceD3D::SetFFTextureFactor32(v1, 0);
  RenderDeviceD3D::SetFillMode(v1, FILLMODE_SOLID);
  RenderDeviceD3D::SetMultiSampleAntialias(v1, 1);
  v3 = 0;
  do
  {
    RenderDeviceD3D::SetSamplerAddressMode(v1, v3, TEXADDRESS_WRAP, TEXADDRESS_WRAP);
    RenderDeviceD3D::SetSamplerFilterMode(v1, v3++, TEXFILTER_LINEAR, TEXFILTER_LINEAR, TEXFILTER_POINT);
  }
  while ( v3 < 0x10 );
  v4 = 0;
  do
  {
    RenderDeviceD3D::SetStageFFAlphaSource(v1, v4, TEXOP_DISABLE, 0, 0);
    RenderDeviceD3D::SetStageFFColorSource(v1, v4, TEXOP_DISABLE, 0, 0);
    RenderDeviceD3D::SetStageFFTexCoordIndex(v1, v4, v4);
    RenderDeviceD3D::SetStageFFTextureTransformFlags(v1, v4, 0);
    RenderDeviceD3D::SetStageTexture(v1, v4++, 0);
  }
  while ( v4 < 8 );
  ((void (__stdcall *)(_DWORD, int))v1->m_pDirect3DDevice->vfptr[16].AddRef)(
    v1->m_pDirect3DDevice,
    &v1->m_defaultMaterial);
  v1->m_bMaterialAlphaMode = 0;
  v1->m_ParticleState = 0;
  v1->m_bForceStates = 0;
  v1->m_State.pVertexBuffer = 0;
  return 1;
}

//----- (005A0150) --------------------------------------------------------  // acclient.c:457763
void __thiscall RenderDeviceD3D::SetRenderTarget(RenderDeviceD3D *this, const unsigned int _Index, RenderSurface *_pRenderTarget, RenderSurface *_pDepthStencilTarget)
{
  RenderDeviceD3D *v4; // esi@1
  IUnknownVtbl *v5; // ebx@1
  IDirect3DSurface9 *v6; // eax@1
  IDirect3DSurface9 *v7; // eax@2
  RenderSurface *v8; // ecx@6
  RenderSurface *v9; // ecx@8
  RenderDeviceVtbl *v10; // edx@10
  unsigned int v11; // eax@10
  unsigned int v12; // ST0C_4@10

  v4 = this;
  v5 = this->m_pDirect3DDevice->vfptr;
  v6 = RenderSurfaceD3D::GetDirect3DSurface((RenderSurfaceD3D *)_pRenderTarget);
  ((void (__stdcall *)(_DWORD, const unsigned int, IDirect3DSurface9 *))v5[12].AddRef)(
    v4->m_pDirect3DDevice,
    _Index,
    v6);
  if ( _pDepthStencilTarget )
    v7 = RenderSurfaceD3D::GetDirect3DSurface((RenderSurfaceD3D *)_pDepthStencilTarget);
  else
    v7 = 0;
  ((void (__stdcall *)(_DWORD, IDirect3DSurface9 *))v4->m_pDirect3DDevice->vfptr[13].QueryInterface)(
    v4->m_pDirect3DDevice,
    v7);
  _pRenderTarget->vfptr->AddRef((Interface *)_pRenderTarget);
  if ( _pDepthStencilTarget )
    _pDepthStencilTarget->vfptr->AddRef((Interface *)_pDepthStencilTarget);
  v8 = v4->m_pRenderTarget;
  if ( v8 )
    ((void (*)(void))v8->vfptr->Release)();
  v9 = v4->m_pDepthStencilTarget;
  if ( v9 )
    ((void (*)(void))v9->vfptr->Release)();
  v10 = v4->vfptr;
  v4->m_pRenderTarget = _pRenderTarget;
  v4->m_pDepthStencilTarget = _pDepthStencilTarget;
  v11 = _pRenderTarget->width;
  v4->m_RenderTargetWidth = v11;
  v12 = _pRenderTarget->height;
  v4->m_RenderTargetHeight = v12;
  v10->SetViewport((RenderDevice *)v4, 0, 0, v11, v12, 0);
}

//----- (005A0210) --------------------------------------------------------  // acclient.c:457809
RenderSurfaceD3D *__thiscall RenderDeviceD3D::GenerateSurfaceFromFrontBuffer(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  RenderSurfaceD3D *v2; // edi@1
  IUnknownVtbl *v3; // ebx@3
  IDirect3DSurface9 *v4; // eax@3
  int v5; // eax@3

  v1 = this;
  v2 = (RenderSurfaceD3D *)((int (*)(void))this->vfptr->CreateSurface)();
  if ( !v2
    || !(unsigned __int8)((int (__thiscall *)(RenderSurfaceD3D *, _DWORD, _DWORD, signed int, _DWORD))v2->vfptr[3].AddRef)(
                           v2,
                           v1->m_nFrontBufferWidth,
                           v1->m_nFrontBufferHeight,
                           21,
                           0) )
    return 0;
  v3 = v1->m_pDirect3DDevice->vfptr;
  v4 = RenderSurfaceD3D::GetDirect3DSurface(v2);
  v5 = v3[11].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, 0, (void **)v4);
  if ( v5 && v5 == -2005530520 )
  {
    v1->m_bDeviceLost = 1;
    return 0;
  }
  return v2;
}

//----- (005A0280) --------------------------------------------------------  // acclient.c:457839
void __thiscall RenderDeviceD3D::EndRenderingDebugText(RenderDeviceD3D *this)
{
  TextureBasedFont *v1; // ecx@1

  v1 = this->m_pDebugFont;
  if ( v1 )
    TextureBasedFont::EndRenderingText(v1);
}

//----- (005A0290) --------------------------------------------------------  // acclient.c:457849
void __thiscall RenderDeviceD3D::RenderDebugText(RenderDeviceD3D *this, const int _ViewportX, const int _ViewportY, const char *_pText, const unsigned int _Color32)
{
  TextureBasedFont *v5; // ecx@1

  v5 = this->m_pDebugFont;
  if ( v5 )
    TextureBasedFont::RenderText(v5, _ViewportX, _ViewportY, _pText, _Color32, 1u);
}

//----- (005A02C0) --------------------------------------------------------  // acclient.c:457859
bool __stdcall RenderDeviceD3D::RenderPrimitivesInHardware(PrimType _PrimType, const unsigned int _NumPrimitives, RenderVertexStreamD3D *_VertexStream, const unsigned int _VertexStreamFrameID, const unsigned int _FirstRemoteVertexIndex, const unsigned int _NumVertices)
{
  RenderDevice *v7; // edi@2
  IDirect3DVertexBuffer9 *v8; // eax@2
  int v9; // eax@4

  if ( _VertexStream->m_nStreamFrameID == _VertexStreamFrameID )
  {
    v7 = RenderDevice::render_device;
    v8 = RenderVertexStreamD3D::GetD3DVertexBuffer(_VertexStream);
    if ( v8 )
      (*(void (__stdcall **)(_DWORD, _DWORD, IDirect3DVertexBuffer9 *, _DWORD, unsigned int))(*LODWORD(v7[1].m_GState.ViewToClipMatrix._24)
                                                                                            + 400))(
        LODWORD(v7[1].m_GState.ViewToClipMatrix._24),
        0,
        v8,
        0,
        _VertexStream->m_VertexFormatInfo.size);
    (*(void (__stdcall **)(_DWORD, unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                + 356))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      _VertexStream->m_VertexFormatInfo.format);
    v9 = (*(int (__stdcall **)(_DWORD, PrimType, const unsigned int, const unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                                        + 324))(
           LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
           _PrimType,
           _FirstRemoteVertexIndex,
           _NumPrimitives) == 0;
  }
  else
  {
    LOBYTE(v9) = 0;
  }
  return v9;
}

//----- (005A0350) --------------------------------------------------------  // acclient.c:457896
bool __stdcall RenderDeviceD3D::RenderDynamicPrimitives(PrimType _PrimType, const unsigned int _NumPrimitives, const void *_pVertices, const unsigned int _VertexFormat)
{
  const unsigned int v5; // ebp@1
  const unsigned int v6; // esi@1
  RenderVertexStreamD3D *v7; // edi@7
  char v8; // bl@8
  bool result; // al@11

  v5 = _NumPrimitives;
  v6 = 0;
  switch ( _PrimType )
  {
    case 1:
      v6 = _NumPrimitives;
      break;
    case 2:
      v6 = 2 * _NumPrimitives;
      break;
    case 3:
      v6 = _NumPrimitives + 1;
      break;
    case 4:
      v6 = 3 * _NumPrimitives;
      break;
    case 5:
    case 6:
      v6 = _NumPrimitives + 2;
      break;
    default:
      break;
  }
  v7 = D3DPolyRender::ReferenceVertexStream(Render::m_pRenderer, _VertexFormat, v6);
  if ( !v7 )
    goto LABEL_15;
  v8 = 1;
  if ( !RenderVertexStreamD3D::FillData(
          v7,
          0,
          v6,
          _pVertices,
          &v7->m_VertexFormatInfo,
          0,
          (unsigned int *)&_NumPrimitives) )
    v8 = 0;
  if ( v8 )
    result = RenderDeviceD3D::RenderPrimitivesInHardware(_PrimType, v5, v7, v7->m_nStreamFrameID, _NumPrimitives, v6) != 0;
  else
LABEL_15:
    result = 0;
  return result;
}

//----- (005A0410) --------------------------------------------------------  // acclient.c:457949
HRESULT __cdecl RenderDeviceD3D::DrawPrimitiveUP(_D3DPRIMITIVETYPE PrimitiveType, unsigned int _nNumPrimitives, const void *pVertexStreamZeroData, unsigned int VertexStreamZeroStride)
{
  HRESULT result; // eax@2

  if ( RenderDeviceD3D::s_bAllowDrawPrimitiveUP )
    result = (*(int (__stdcall **)(_DWORD, _D3DPRIMITIVETYPE, unsigned int, const void *, unsigned int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 332))(
               LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
               PrimitiveType,
               _nNumPrimitives,
               pVertexStreamZeroData,
               VertexStreamZeroStride);
  else
    result = 1;
  return result;
}
// 820E4C: using guessed type bool RenderDeviceD3D::s_bAllowDrawPrimitiveUP;

//----- (005A0450) --------------------------------------------------------  // acclient.c:457967
bool __thiscall RenderDeviceD3D::GetFFFogEnable(RenderDeviceD3D *this)
{
  return this->m_State.FFFogEnable;
}

//----- (005A0460) --------------------------------------------------------  // acclient.c:457973
bool __thiscall RenderDeviceD3D::IsAvailableVideoMemoryLow(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  unsigned int v2; // eax@2
  bool result; // al@3

  v1 = this;
  if ( this->m_TotalVideoMemoryInBytes >= 0xC00000
    && (v2 = this->m_pDirect3DDevice->vfptr[1].AddRef((IUnknown *)this->m_pDirect3DDevice), v2 >= 0x1800000) )
    result = v2 < v1->m_TotalVideoMemoryInBytes >> 2;
  else
    result = 1;
  return result;
}

//----- (005A04A0) --------------------------------------------------------  // acclient.c:457989
void __thiscall RenderDeviceD3D::InvalidateCachedTexturePointer(RenderDeviceD3D *this, void *_pD3DTexture)
{
  char *v2; // eax@1
  signed int v3; // ecx@1

  v2 = (char *)this->m_State.Stages;
  v3 = 8;
  do
  {
    if ( *(void **)v2 == _pD3DTexture )
      *(_DWORD *)v2 = 0;
    v2 += 36;
    --v3;
  }
  while ( v3 );
}

//----- (005A04D0) --------------------------------------------------------  // acclient.c:458007
void __thiscall RenderDeviceD3D::InvalidateCachedVertexBufferPointer(RenderDeviceD3D *this, void *_pD3DVertexBuffer)
{
  if ( this->m_State.pVertexBuffer == _pD3DVertexBuffer )
    this->m_State.pVertexBuffer = 0;
}

//----- (005A04F0) --------------------------------------------------------  // acclient.c:458014
void __cdecl ACRender::backup_curr_state()
{
  ACRender::back_curr_material = Render::curr_material;
  ACRender::back_curr_surfaces = Render::curr_surfaces;
  ACRender::back_object_scale = Render::object_scale;
  ACRender::back_object_scale_vec = Render::object_scale_vec;
  ACRender::back_lighting_type = Render::lighting_type;
  ACRender::BackupList = Render::PortalList;
  ACRender::backup_view = Render::portal_view;
  ACRender::backup_view_num = Render::portal_view_num;
  ACRender::backup_detail_surface = Render::curr_detail_surface;
  ACRender::backup_detail_tiling = Render::curr_detail_tiling;
}
// 81EC74: using guessed type float Render::object_scale;
// 81EC9C: using guessed type enum Render::LightingType Render::lighting_type;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 835B68: using guessed type float ACRender::back_object_scale;
// 835B6C: using guessed type enum Render::LightingType ACRender::back_lighting_type;
// 835B70: using guessed type float ACRender::backup_detail_tiling;
// 835BD4: using guessed type struct Vector3 ACRender::back_object_scale_vec;
// 846044: using guessed type struct view_type *Render::portal_view;
// 8662DC: using guessed type int Render::portal_view_num;
// 866320: using guessed type struct portal_view_type *Render::PortalList;
// 866368: using guessed type struct CMaterial *Render::curr_material;
// 8FB60C: using guessed type struct CMaterial *ACRender::back_curr_material;
// 8FB610: using guessed type struct CSurface **ACRender::back_curr_surfaces;
// 8FB61C: using guessed type struct portal_view_type *ACRender::BackupList;
// 8FB620: using guessed type struct CSurface *ACRender::backup_detail_surface;

//----- (005A0590) --------------------------------------------------------  // acclient.c:458046
void __cdecl ACRender::restore_curr_state()
{
  RenderDevice *v0; // esi@1
  struct CMaterial *v1; // edi@1
  float v2; // eax@2
  int v3; // ecx@2

  v0 = RenderDevice::render_device;
  v1 = ACRender::back_curr_material;
  if ( ACRender::back_curr_material != LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) )
  {
    v2 = RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24;
    LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) = ACRender::back_curr_material;
    v3 = *LODWORD(v2);
    if ( v1 )
    {
      (*(void (__stdcall **)(float, int))(v3 + 196))(LODWORD(v2), &v1->d3d_material);
      LOBYTE(v0[2].m_GState.AmbientLight.g) = v1->has_alpha != 0;
      RenderDeviceD3D::SetFFDiffuseColorSource((RenderDeviceD3D *)v0, 0);
      RenderDeviceD3D::SetFFAmbientColorSource((RenderDeviceD3D *)v0, 0);
    }
    else
    {
      (*(void (__stdcall **)(_DWORD, int))(v3 + 196))(LODWORD(v2), &v0[2].m_GState.AmbientLight.a);
      LOBYTE(v0[2].m_GState.AmbientLight.g) = 0;
      RenderDeviceD3D::SetFFDiffuseColorSource((RenderDeviceD3D *)v0, FromVertex);
      RenderDeviceD3D::SetFFAmbientColorSource((RenderDeviceD3D *)v0, FromVertex);
    }
  }
  Render::object_scale = ACRender::back_object_scale;
  Render::object_scale_vec = ACRender::back_object_scale_vec;
  Render::curr_surfaces = ACRender::back_curr_surfaces;
  Render::lighting_type = ACRender::back_lighting_type;
  Render::PortalList = ACRender::BackupList;
  Render::set_view(ACRender::backup_view, ACRender::backup_view_num);
  Render::curr_detail_surface = ACRender::backup_detail_surface;
  Render::curr_detail_tiling = ACRender::backup_detail_tiling;
}
// 81EC74: using guessed type float Render::object_scale;
// 81EC9C: using guessed type enum Render::LightingType Render::lighting_type;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 835B68: using guessed type float ACRender::back_object_scale;
// 835B6C: using guessed type enum Render::LightingType ACRender::back_lighting_type;
// 835B70: using guessed type float ACRender::backup_detail_tiling;
// 835BD4: using guessed type struct Vector3 ACRender::back_object_scale_vec;
// 866320: using guessed type struct portal_view_type *Render::PortalList;
// 8FB60C: using guessed type struct CMaterial *ACRender::back_curr_material;
// 8FB610: using guessed type struct CSurface **ACRender::back_curr_surfaces;
// 8FB61C: using guessed type struct portal_view_type *ACRender::BackupList;
// 8FB620: using guessed type struct CSurface *ACRender::backup_detail_surface;

//----- (005A0690) --------------------------------------------------------  // acclient.c:458100
void __userpurge RenderDeviceD3D::UpdateObjCell(RenderDeviceD3D *this@<ecx>, double a2@<st0>, CObjCell *cell)
{
  CObjCell *v3; // esi@1
  unsigned int v4; // edi@2
  unsigned int v5; // eax@2
  double v6; // st7@3
  AC1Legacy::Vector3 diff_vec; // [sp+4h] [bp-Ch]@2
  float cella; // [sp+14h] [bp+4h]@2

  v3 = cell;
  if ( cell->num_shadow_objects )
  {
    ((void (__thiscall *)(CObjCell *, AC1Legacy::Vector3 *))cell->vfptr[4].QueryInterface)(cell, &diff_vec);
    cella = a2;
    v4 = 0;
    v5 = v3->num_shadow_objects;
    if ( a2 <= 50.0 )
    {
      if ( v5 )
      {
        do
          CPhysicsObj::UpdateViewerDistance(v3->shadow_object_list.data[v4++]->physobj);
        while ( v4 < v3->num_shadow_objects );
      }
    }
    else
    {
      v6 = 1.0 / cella;
      diff_vec.x = diff_vec.x * v6;
      diff_vec.y = diff_vec.y * v6;
      diff_vec.z = v6 * diff_vec.z;
      if ( v5 )
      {
        do
          CPhysicsObj::UpdateViewerDistance(v3->shadow_object_list.data[v4++]->physobj, cella, &diff_vec);
        while ( v4 < v3->num_shadow_objects );
      }
    }
  }
}

//----- (005A0760) --------------------------------------------------------  // acclient.c:458142
void __userpurge RenderDeviceD3D::DrawObjCellForDummies(RenderDeviceD3D *this@<ecx>, double a2@<st0>, CObjCell *cell)
{
  RenderDeviceD3D *v3; // edi@1
  char *v4; // eax@2

  v3 = this;
  RenderDeviceD3D::UpdateObjCell(this, a2, cell);
  if ( cell )
    v4 = (char *)&cell->vfptr;
  else
    v4 = 0;
  if ( *((_DWORD *)v4 + 1) > 1u )
    CShadowPart::insertion_sort((DArray<CShadowPart *> *)(v4 + 8), *((_DWORD *)v4 + 1));
  v3->vfptr->DrawObjCell((RenderDevice *)v3, cell);
}

//----- (005A07A0) --------------------------------------------------------  // acclient.c:458159
void __stdcall RenderDeviceD3D::DrawPartCell(unsigned int cellID, CPartCell *cell, unsigned int leaf_index)
{
  unsigned int v4; // esi@1
  CShadowPart *v5; // ecx@2

  Render::curr_detail_surface = 0;
  v4 = 0;
  if ( cell->num_shadow_parts )
  {
    do
    {
      v5 = cell->shadow_part_list.data[v4];
      if ( v5 )
        CShadowPart::draw(v5, leaf_index);
      ++v4;
    }
    while ( v4 < cell->num_shadow_parts );
  }
}

//----- (005A07E0) --------------------------------------------------------  // acclient.c:458180
void __stdcall RenderDeviceD3D::DrawBuildingLeaf(unsigned int leaf_index)
{
  struct CPartCell *v2; // eax@1

  v2 = CBuildingObj::curr_leaf_cells[leaf_index];
  if ( v2 )
  {
    if ( v2->num_shadow_parts )
    {
      ((void (*)(void))Render::m_pRenderer->vfptr->polyListFinishInternal)();
      Render::PolyNext = (struct polyListEntry *)&Render::PolyList;
      ACRender::backup_curr_state();
      Render::pushLevelOffset = 1;
      RenderDeviceD3D::DrawPartCell(
        CBuildingObj::curr_pos->objcell_id,
        CBuildingObj::curr_leaf_cells[leaf_index],
        leaf_index);
      Render::pushLevelOffset = 0;
      ACRender::restore_curr_state();
      Render::obj_view_set();
    }
  }
}
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;
// 86632C: using guessed type int Render::pushLevelOffset;
// 8FA9BC: using guessed type struct CPartCell **CBuildingObj::curr_leaf_cells;

//----- (005A0860) --------------------------------------------------------  // acclient.c:458208
signed int __stdcall RenderDeviceD3D::DrawMesh(CGfxObj *i_pObj, Position *i_posObj, bool i_bBuilding)
{
  signed int v4; // ebp@1
  struct portal_view_type *v5; // ecx@2
  int v6; // eax@2
  int v7; // esi@5
  signed int v8; // eax@8
  signed int v9; // eax@11
  signed int result; // eax@19
  int v11; // edi@20
  signed int v12; // eax@21
  ObjectDrawStatus v13; // ebp@22
  signed int v14; // eax@24
  ObjectDrawStatus v15; // ebp@25
  int pushed; // [sp+14h] [bp-8h]@2
  int pres_view; // [sp+18h] [bp-4h]@2
  Position *i_posObja; // [sp+24h] [bp+8h]@2

  v4 = 0;
  Render::lighting_type = 2;
  if ( Render::PortalList )
  {
    pushed = 0;
    Render::positionPush(1, i_posObj);
    v5 = Render::PortalList;
    v6 = 0;
    i_posObja = 0;
    for ( pres_view = 0; pres_view < (signed int)Render::PortalList->view_count; ++pres_view )
    {
      if ( RenderDeviceD3D::building_view == -1 || RenderDeviceD3D::building_view == v6 )
      {
        Render::set_view(&v5->view, v6);
        v7 = Render::viewconeCheck(i_pObj->drawing_sphere);
        if ( v7 )
        {
          if ( !pushed )
          {
            Render::positionPush(2, 0);
            Render::GfxObjUnderSelectionRay(i_pObj);
            pushed = 1;
          }
          v8 = RenderDeviceD3D::DrawMeshInternal(i_pObj, i_bBuilding, (BoundingType)v7);
          if ( v8 > v4 )
            v4 = v8;
        }
        else
        {
          if ( i_bBuilding )
          {
            Render::positionPush(2, 0);
            v9 = RenderDeviceD3D::DrawMeshInternal(i_pObj, i_bBuilding, 0);
            if ( v9 > v4 )
              v4 = v9;
          }
          else if ( v4 < 1 )
          {
            v4 = 1;
          }
          i_posObja = (Position *)((char *)i_posObja + 1);
        }
      }
      v5 = Render::PortalList;
      v6 = pres_view + 1;
    }
    if ( i_posObja != (Position *)v5->view_count )
      goto LABEL_19;
    goto LABEL_18;
  }
  Render::positionPush(1, i_posObj);
  v11 = Render::viewconeCheck(i_pObj->drawing_sphere);
  if ( v11 )
  {
    Render::positionPush(2, 0);
    Render::GfxObjUnderSelectionRay(i_pObj);
    v12 = RenderDeviceD3D::DrawMeshInternal(i_pObj, i_bBuilding, (BoundingType)v11);
    if ( v12 <= 0 )
      goto LABEL_19;
    v13 = v12;
    Render::framePop();
    result = v13;
  }
  else
  {
    if ( !i_bBuilding )
    {
LABEL_18:
      v4 = 1;
LABEL_19:
      Render::framePop();
      return v4;
    }
    Render::positionPush(2, 0);
    v14 = RenderDeviceD3D::DrawMeshInternal(i_pObj, i_bBuilding, 0);
    if ( v14 <= 0 )
      goto LABEL_19;
    v15 = v14;
    Render::framePop();
    result = v15;
  }
  return result;
}
// 81EC9C: using guessed type enum Render::LightingType Render::lighting_type;
// 820E44: using guessed type __int32 RenderDeviceD3D::building_view;
// 866320: using guessed type struct portal_view_type *Render::PortalList;

//----- (005A0A30) --------------------------------------------------------  // acclient.c:458314
char __thiscall RenderDeviceD3D::GetD3DResources(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  int v2; // eax@1
  IDirect3DSurface9 *v3; // ecx@1
  RenderSurface *v4; // eax@2
  GraphicsResource *v5; // eax@3
  RenderSurface *v6; // ecx@5
  RenderSurface *v7; // eax@5
  unsigned int v8; // edx@5
  IDirect3DDevice9 *v9; // eax@5
  int v10; // eax@5
  IDirect3DSurface9 *v11; // ecx@5
  char result; // al@6
  RenderSurface *v13; // eax@7
  GraphicsResource *v14; // eax@8
  RenderSurface *v15; // ecx@10
  IDirect3DSurface9 *pBackBuffer; // [sp+1Ch] [bp-8h]@1
  IDirect3DSurface9 *pD3DDepthStencil; // [sp+20h] [bp-4h]@5

  v1 = this;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[12].Release)(
    this->m_pDirect3DDevice,
    0,
    &pBackBuffer);
  v2 = (int)v1->vfptr->CreateSurface((RenderDevice *)v1);
  v3 = pBackBuffer;
  v1->m_pFrameBufferSurface = (RenderSurface *)v2;
  if ( (unsigned __int8)(*(int (__thiscall **)(int, IDirect3DSurface9 *, _DWORD, signed int))(*(_DWORD *)v2 + 112))(
                          v2,
                          v3,
                          0,
                          1)
    && ((v4 = v1->m_pFrameBufferSurface) == 0 ? (v5 = 0) : (v5 = (GraphicsResource *)&v4->vfptr),
        GraphicsResource::UnlinkResource(v5),
        v6 = v1->m_pFrameBufferSurface,
        v1->m_pRenderTarget = v6,
        ((void (*)(void))v6->vfptr->AddRef)(),
        v7 = v1->m_pRenderTarget,
        v1->m_RenderTargetWidth = v7->width,
        v8 = v7->height,
        v9 = v1->m_pDirect3DDevice,
        v1->m_RenderTargetHeight = v8,
        ((void (__stdcall *)(IDirect3DDevice9 *, IDirect3DSurface9 **))v9->vfptr[13].AddRef)(v9, &pD3DDepthStencil),
        v10 = (int)v1->vfptr->CreateSurface((RenderDevice *)v1),
        v11 = pD3DDepthStencil,
        v1->m_pDepthStencilSurface = (RenderSurface *)v10,
        (unsigned __int8)(*(int (__thiscall **)(int, IDirect3DSurface9 *, _DWORD, signed int))(*(_DWORD *)v10 + 112))(
                           v10,
                           v11,
                           0,
                           1)) )
  {
    v13 = v1->m_pDepthStencilSurface;
    if ( v13 )
      v14 = (GraphicsResource *)&v13->vfptr;
    else
      v14 = 0;
    GraphicsResource::UnlinkResource(v14);
    v15 = v1->m_pDepthStencilSurface;
    v1->m_pDepthStencilTarget = v15;
    ((void (*)(void))v15->vfptr->AddRef)();
    ((void (__stdcall *)(_DWORD, _DWORD, int))v1->m_pDirect3DDevice->vfptr[4].Release)(
      v1->m_pDirect3DDevice,
      0,
      &v1->m_pPrimarySwapChain);
    ((void (__stdcall *)(_DWORD, signed int, signed int, signed int, _DWORD, signed int, signed int, int, _DWORD))v1->m_pDirect3DDevice->vfptr[7].Release)(
      v1->m_pDirect3DDevice,
      1,
      1,
      1,
      0,
      21,
      1,
      &v1->m_pSolidColorTexture,
      0);
    RenderDeviceD3D::SetSolidColorTextureColor(v1, 0xFF000000, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A0B70) --------------------------------------------------------  // acclient.c:458401
void __thiscall RenderDeviceD3D::SetGamma(RenderDeviceD3D *this, const float _fBrightness, const bool _bWantCalibration)
{
  double v3; // st7@1
  RenderDeviceD3D *v4; // ebx@1
  int v5; // edi@5
  unsigned int v6; // esi@5
  signed int v7; // ecx@6
  bool v8; // cl@13
  int nLevel; // [sp+0h] [bp-604h]@5
  _D3DGAMMARAMP ramp; // [sp+4h] [bp-600h]@10

  v3 = _fBrightness;
  v4 = this;
  if ( _fBrightness <= 1.0 )
  {
    if ( _fBrightness < -0.2 )
      v3 = -0.2;
  }
  else
  {
    v3 = 1.0;
  }
  this->m_gammaBrightnessVal = v3;
  v5 = 0;
  nLevel = 0;
  v6 = 0;
  do
  {
    v7 = v5 - (unsigned __int64)((double)nLevel * v3 * -2.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 0xFFFF )
        LOWORD(v7) = -1;
    }
    else
    {
      LOWORD(v7) = 0;
    }
    ramp.blue[v6] = v7;
    ramp.green[v6] = v7;
    v5 += 255;
    ramp.red[v6++] = v7;
    nLevel = v5;
  }
  while ( v6 < 0x100 );
  v8 = (v4->m_D3DCaps.Caps2 >> 20) & 1 && _bWantCalibration;
  ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD, _DWORD, _D3DGAMMARAMP *))v4->m_pDirect3DDevice->vfptr[7].QueryInterface)(
    v4->m_pDirect3DDevice,
    0,
    v8 != 0,
    &ramp);
}

//----- (005A0C70) --------------------------------------------------------  // acclient.c:458455
void __thiscall RenderDeviceD3D::SetupState(RenderDeviceD3D *this, MaterialLayer *_pReferenceLayer, MaterialLayer *_pLayer, const unsigned int _VertexFormat, RGBAColor *_DiffuseColorScale, RGBAColor *_AmbientLightBoost, const bool _ForceTranslucent)
{
  MaterialLayer *v7; // edi@1
  unsigned int v8; // ebx@1
  RenderDeviceD3D *v9; // ebp@1
  char *v10; // eax@3
  bool v11; // al@5
  const unsigned int v12; // ebx@9
  LayerStage **v13; // ecx@10
  int v14; // eax@10
  const unsigned int v15; // esi@10
  LayerModifier **v16; // eax@19
  LayerModifier *v17; // ebp@19
  bool v18; // bl@27
  BlendMode v19; // ecx@27
  BlendMode v20; // edx@27
  CullModeType v21; // eax@55
  unsigned int v22; // esi@61
  unsigned __int64 v23; // rax@61
  double v24; // st7@61
  const unsigned int i; // ebx@65
  LayerStage *v26; // esi@66
  unsigned int v27; // eax@69
  const unsigned int v28; // ebx@70
  LayerStage *v29; // esi@71
  unsigned int _Stage; // [sp+18h] [bp-54h]@9
  unsigned int v31; // [sp+1Ch] [bp-50h]@17
  RenderDeviceD3D *v32; // [sp+20h] [bp-4Ch]@1
  LayerStage *Stage; // [sp+24h] [bp-48h]@10
  const unsigned int NumStages; // [sp+28h] [bp-44h]@1
  Matrix4 mTextureMatrix; // [sp+2Ch] [bp-40h]@11
  char _pLayera; // [sp+74h] [bp+8h]@10
  const bool _pLayerb; // [sp+74h] [bp+8h]@27
  const unsigned int _DiffuseColorScalea; // [sp+7Ch] [bp+10h]@10
  DepthTestMode _DiffuseColorScaleb; // [sp+7Ch] [bp+10h]@27
  unsigned int nTexTransformFlags; // [sp+80h] [bp+14h]@18
  const bool nTexTransformFlagsa; // [sp+80h] [bp+14h]@30
  unsigned int im; // [sp+84h] [bp+18h]@69

  v7 = _pLayer;
  v8 = _pLayer->m_Stages.m_num;
  v9 = this;
  v32 = this;
  NumStages = _pLayer->m_Stages.m_num;
  if ( !(_S225_31 & 1) )
    _S225_31 |= 1u;
  stru_8ED56C.r = this->m_GState.AmbientLight.r;
  stru_8ED56C.g = this->m_GState.AmbientLight.g;
  stru_8ED56C.b = this->m_GState.AmbientLight.b;
  stru_8ED56C.a = this->m_GState.AmbientLight.a;
  stru_8ED56C.r = stru_8ED56C.r + _AmbientLightBoost->r;
  stru_8ED56C.g = stru_8ED56C.g + _AmbientLightBoost->g;
  stru_8ED56C.b = stru_8ED56C.b + _AmbientLightBoost->b;
  RGBAColor::CapHigh(&stru_8ED56C);
  unk_8ED558 = Waveform::GetValue(&_pLayer->m_wSpecularPower, Timer::local_time);
  unk_8ED57C = (unsigned __int64)(Waveform::GetValue(&_pLayer->m_AlphaTestRef, Timer::local_time) * 255.0);
  flt_8ED538 = _pLayer->m_cDiffuse.r;
  flt_8ED53C = _pLayer->m_cDiffuse.g;
  flt_8ED540 = _pLayer->m_cDiffuse.b;
  flt_8ED544 = _pLayer->m_cDiffuse.a;
  flt_8ED538 = flt_8ED538 * _DiffuseColorScale->r;
  flt_8ED53C = flt_8ED53C * _DiffuseColorScale->g;
  flt_8ED540 = flt_8ED540 * _DiffuseColorScale->b;
  flt_8ED544 = flt_8ED544 * _DiffuseColorScale->a;
  v10 = (char *)&AmbientLightBoost;
  if ( unk_8ED558 >= 0.5 )
    v10 = (char *)&_pLayer->m_cSpecular;
  LODWORD(flt_8ED548) = *(_DWORD *)v10;
  LODWORD(flt_8ED54C) = *((_DWORD *)v10 + 1);
  LODWORD(flt_8ED550) = *((_DWORD *)v10 + 2);
  LODWORD(flt_8ED554) = *((_DWORD *)v10 + 3);
  flt_8ED548 = flt_8ED548 * _DiffuseColorScale->r;
  flt_8ED54C = flt_8ED54C * _DiffuseColorScale->g;
  flt_8ED550 = flt_8ED550 * _DiffuseColorScale->b;
  flt_8ED554 = flt_8ED554 * _DiffuseColorScale->a;
  flt_8ED55C = _pLayer->m_cDye.r;
  flt_8ED560 = _pLayer->m_cDye.g;
  flt_8ED564 = _pLayer->m_cDye.b;
  flt_8ED568 = _pLayer->m_cDye.a;
  v11 = (_pLayer->m_Options & 2) == 2;
  MGStates.WantFFLighting = (_pLayer->m_Options & 2) == 2;
  unk_8ED531 = (_pLayer->m_Options & 4) == 4;
  unk_8ED533 = (_pLayer->m_Options & 0x20) == 32;
  unk_8ED534 = (_pLayer->m_Options & 0x40) == 64;
  byte_8ED535[0] = 1;
  if ( !(_pLayer->m_Options & 8) || !v11 || (unk_8ED532 = 1, unk_8ED558 <= 0.0) )
    unk_8ED532 = 0;
  (*(void (__stdcall **)(_DWORD, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 368))(
    LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
    0);
  RenderDeviceD3D::SetFFFogEnable(v9, byte_8ED535[0]);
  RenderDeviceD3D::SetFFLighting(v9, MGStates.WantFFLighting);
  v12 = v8 - 1;
  _Stage = v12;
  if ( (v12 & 0x80000000) == 0 )
  {
    while ( 1 )
    {
      v13 = v7->m_Stages.m_data;
      Stage = v13[v12];
      v14 = v13[v12]->m_FFTexCoordIndex & 0xFF00;
      v15 = v13[v12]->m_FFTexCoordIndex & 0xFFFF00FF;
      _pLayera = 0;
      _DiffuseColorScalea = 0;
      if ( !v14 )
        goto LABEL_36;
      LODWORD(mTextureMatrix._14) = 0;
      LODWORD(mTextureMatrix._13) = 0;
      LODWORD(mTextureMatrix._12) = 0;
      LODWORD(mTextureMatrix._24) = 0;
      LODWORD(mTextureMatrix._23) = 0;
      LODWORD(mTextureMatrix._21) = 0;
      LODWORD(mTextureMatrix._34) = 0;
      LODWORD(mTextureMatrix._32) = 0;
      LODWORD(mTextureMatrix._31) = 0;
      LODWORD(mTextureMatrix._43) = 0;
      LODWORD(mTextureMatrix._42) = 0;
      LODWORD(mTextureMatrix._41) = 0;
      LODWORD(mTextureMatrix._44) = 1065353216;
      LODWORD(mTextureMatrix._33) = 1065353216;
      LODWORD(mTextureMatrix._22) = 1065353216;
      LODWORD(mTextureMatrix._11) = 1065353216;
      _pLayera = 1;
      v15 = v12;
      if ( (unsigned int)v14 > 0x400 )
        break;
      if ( v14 == 1024 )
      {
        v15 = v12 | 0x40000;
LABEL_17:
        v31 = v7->m_FFModifiers.m_num;
        if ( v7->m_FFModifiers.m_num )
        {
          LODWORD(mTextureMatrix._14) = 0;
          LODWORD(mTextureMatrix._13) = 0;
          LODWORD(mTextureMatrix._12) = 0;
          LODWORD(mTextureMatrix._24) = 0;
          LODWORD(mTextureMatrix._23) = 0;
          LODWORD(mTextureMatrix._21) = 0;
          LODWORD(mTextureMatrix._34) = 0;
          LODWORD(mTextureMatrix._32) = 0;
          LODWORD(mTextureMatrix._31) = 0;
          LODWORD(mTextureMatrix._43) = 0;
          LODWORD(mTextureMatrix._42) = 0;
          LODWORD(mTextureMatrix._41) = 0;
          LODWORD(mTextureMatrix._44) = 1065353216;
          LODWORD(mTextureMatrix._33) = 1065353216;
          LODWORD(mTextureMatrix._22) = 1065353216;
          LODWORD(mTextureMatrix._11) = 1065353216;
          nTexTransformFlags = 0;
          do
          {
            v16 = v7->m_FFModifiers.m_data;
            v17 = v16[nTexTransformFlags];
            if ( (*((int (__thiscall **)(LayerModifier *))&v17->vfptr->GetType + 1))(v16[nTexTransformFlags]) == v12 )
            {
              _pLayera = 1;
              v17->vfptr->ApplyTextureTransform(v17, &mTextureMatrix);
            }
            ++nTexTransformFlags;
          }
          while ( nTexTransformFlags < v31 );
          v9 = v32;
        }
        if ( !_pLayera )
          goto LABEL_26;
        goto LABEL_24;
      }
      if ( v14 == 256 )
        goto LABEL_35;
      if ( v14 == 512 )
        goto LABEL_34;
      if ( v14 == 768 )
      {
        v15 = v12 | 0x20000;
        goto LABEL_17;
      }
LABEL_36:
      if ( v14 == 1280 )
      {
        Matrix4::Inverse(&mTextureMatrix, &v9->m_GState.WorldToViewMatrix);
        *(Vector3 *)&mTextureMatrix._41 = stru_8ED3D8;
      }
      else
      {
        if ( v14 != 1536 )
          goto LABEL_17;
        LODWORD(mTextureMatrix._14) = 0;
        LODWORD(mTextureMatrix._13) = 0;
        LODWORD(mTextureMatrix._12) = 0;
        LODWORD(mTextureMatrix._24) = 0;
        LODWORD(mTextureMatrix._23) = 0;
        LODWORD(mTextureMatrix._21) = 0;
        LODWORD(mTextureMatrix._34) = 0;
        LODWORD(mTextureMatrix._32) = 0;
        LODWORD(mTextureMatrix._31) = 0;
        LODWORD(mTextureMatrix._43) = 0;
        LODWORD(mTextureMatrix._42) = 0;
        LODWORD(mTextureMatrix._41) = 0;
        LODWORD(mTextureMatrix._44) = 1065353216;
        LODWORD(mTextureMatrix._33) = 1065353216;
        LODWORD(mTextureMatrix._22) = 1065353216;
        LODWORD(mTextureMatrix._11) = 1065353216;
      }
LABEL_24:
      (*(void (__stdcall **)(_DWORD, int, Matrix4 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                    + 176))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        v12 + 16,
        &mTextureMatrix);
      _DiffuseColorScalea = 3;
      if ( Stage->m_FFUseProjection )
        _DiffuseColorScalea = 259;
LABEL_26:
      RenderDeviceD3D::SetStageFFTexCoordIndex((RenderDeviceD3D *)RenderDevice::render_device, v12, v15);
      RenderDeviceD3D::SetStageFFTextureTransformFlags(
        (RenderDeviceD3D *)RenderDevice::render_device,
        v12--,
        _DiffuseColorScalea);
      if ( (v12 & 0x80000000) != 0 )
        goto LABEL_27;
    }
    if ( v14 != 1280 )
    {
      if ( v14 != 1536 )
        goto LABEL_36;
LABEL_34:
      v15 = v12 | 0x10000;
      goto LABEL_36;
    }
LABEL_35:
    v15 = v12 | 0x30000;
    goto LABEL_36;
  }
LABEL_27:
  v18 = v7->m_AlphaTest;
  v19 = v7->m_SourceBlend;
  v20 = v7->m_DestBlend;
  _DiffuseColorScaleb = v7->m_DepthTest;
  _pLayerb = v7->m_DepthWrite;
  if ( v18 || v19 == 5 && !(v9->m_State.ColorWriteEnable & 8) )
  {
    nTexTransformFlagsa = 1;
    if ( v18 && flt_8ED544 < 0.89999998 )
      v18 = 0;
  }
  else
  {
    nTexTransformFlagsa = 0;
  }
  if ( _ForceTranslucent && v20 != 2 )
  {
    v18 = 0;
    _pLayerb = 0;
  }
  if ( !v9->m_caps.bDestinationAlpha )
  {
    if ( v19 == 7 )
    {
      v19 = 5;
    }
    else if ( v19 == 8 )
    {
      v19 = 6;
    }
    if ( v20 == 7 )
    {
      v20 = 5;
    }
    else if ( v20 == 8 )
    {
      v20 = 6;
    }
  }
  RenderDeviceD3D::SetBlendFunction(v9, v19, v20, v7->m_BlendOp);
  RenderDeviceD3D::SetDepthBufferMode(v9, _DiffuseColorScaleb, _pLayerb);
  RenderDeviceD3D::SetAlphaTestEnable(v9, nTexTransformFlagsa);
  RenderDeviceD3D::SetAlphaTestFunction(v9, ALPHATESTFUNC_GREATER);
  RenderDeviceD3D::SetAlphaTestRef(v9, v18 != 0 ? unk_8ED57C : 0);
  v21 = v7->m_CullMode;
  if ( v9->m_ReverseCulling )
  {
    if ( v21 == 2 )
    {
      v21 = 3;
    }
    else if ( v21 == 3 )
    {
      v21 = 2;
    }
  }
  RenderDeviceD3D::SetCullMode(v9, v21);
  RenderDeviceD3D::SetFFSpecularEnable(v9, unk_8ED532);
  if ( unk_8ED531 )
  {
    v22 = ((unsigned int)(unsigned __int64)(flt_8ED55C * 255.0) | ((unsigned int)(unsigned __int64)(flt_8ED568 * 255.0) << 8)) << 8;
    v23 = (unsigned __int64)(flt_8ED560 * 255.0);
    v24 = flt_8ED564;
  }
  else if ( MGStates.WantFFLighting )
  {
    v22 = ((unsigned int)(unsigned __int64)(flt_8ED548 * 255.0) | ((unsigned int)(unsigned __int64)(flt_8ED554 * 255.0) << 8)) << 8;
    v23 = (unsigned __int64)(flt_8ED54C * 255.0);
    v24 = flt_8ED550;
  }
  else
  {
    v22 = ((unsigned int)(unsigned __int64)(flt_8ED538 * 255.0) | ((unsigned int)(unsigned __int64)(flt_8ED544 * 255.0) << 8)) << 8;
    v23 = (unsigned __int64)(flt_8ED53C * 255.0);
    v24 = flt_8ED540;
  }
  RenderDeviceD3D::SetFFTextureFactor32(v9, (unsigned __int64)(v24 * 255.0) | (((unsigned int)v23 | v22) << 8));
  for ( i = _Stage; (i & 0x80000000) == 0; --i )
  {
    v26 = v7->m_Stages.m_data[i];
    RenderDeviceD3D::SetStageFFColorSource(v9, i, v26->m_FFColorOp, v26->m_FFColorArg1, v26->m_FFColorArg2);
    RenderDeviceD3D::SetStageFFAlphaSource(v9, i, v26->m_FFAlphaOp, v26->m_FFAlphaArg1, v26->m_FFAlphaArg2);
  }
  if ( NumStages < 8 )
  {
    RenderDeviceD3D::SetStageFFColorSource(v9, NumStages, TEXOP_DISABLE, 2u, 1u);
    RenderDeviceD3D::SetStageFFAlphaSource(v9, NumStages, TEXOP_DISABLE, 2u, 1u);
  }
  v27 = _Stage;
  for ( im = _Stage; (v27 & 0x80000000) == 0; im = v27 )
  {
    v28 = v9->m_DefaultSamplerMappings.m_data[v27];
    if ( v28 != -1 )
    {
      v29 = v7->m_Stages.m_data[v28];
      RenderDeviceD3D::SetStageTexture(v9, v28, v29->m_pTexture);
      RenderDeviceD3D::SetSamplerAddressMode(
        v9,
        v28,
        (TexAddress)*(_QWORD *)&v29->m_AddressModeU,
        (TexAddress)(*(_QWORD *)&v29->m_AddressModeU >> 32));
      RenderDeviceD3D::SetSamplerFilterMode(v9, v28, v29->m_MinFilterMode, v29->m_MagFilterMode, v29->m_MipFilterMode);
      v27 = im;
    }
    --v27;
  }
}

//----- (005A1510) --------------------------------------------------------  // acclient.c:458799
char __thiscall RenderDeviceD3D::InitDebugFont(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // edi@1
  TextureBasedFont *v2; // ecx@1
  int v3; // esi@1
  bool v4; // zf@2
  int v5; // esi@7
  char v6; // al@7
  TResult result; // [sp+4h] [bp-4h]@1

  result.m_val = (unsigned int)this;
  v1 = this;
  v2 = this->m_pDebugFont;
  v3 = (int)&v1->m_pDebugFont;
  if ( v2 )
  {
    v4 = v2->m_cRef-- == 1;
    if ( v4 )
      ((void (__stdcall *)(signed int))v2->vfptr->__vecDelDtor)(1);
    *(_DWORD *)v3 = 0;
  }
  if ( (TextureBasedFont::CreateFromFont(&result, 8u, &v1->m_pDebugFont)->m_val & 0x80000000) == 0 && *(_DWORD *)v3 )
  {
    *(_DWORD *)(*(_DWORD *)v3 + 28) = 8;
    *(_DWORD *)(*(_DWORD *)v3 + 32) = 14;
    v5 = *(_DWORD *)v3;
    v1->m_DebugFontWidth = *(_DWORD *)(v5 + 28);
    v1->m_DebugFontHeight = *(_DWORD *)(v5 + 32);
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}

//----- (005A1590) --------------------------------------------------------  // acclient.c:458837
void __thiscall RenderDeviceD3D::BeginRenderingDebugText(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1

  v1 = this;
  if ( this->m_pDebugFont || RenderDeviceD3D::InitDebugFont(this) )
    TextureBasedFont::BeginRenderingText(v1->m_pDebugFont);
}

//----- (005A15C0) --------------------------------------------------------  // acclient.c:458847
bool __stdcall RenderDeviceD3D::RenderDynamicPrimitivesUsingMaterial(PrimType _PrimType, const unsigned int _NumPrimitives, const void *_pVertices, const unsigned int _VertexFormat, RenderMaterial *_ReferenceMaterial, RenderMaterial *_Material, RGBAColor *_Color)
{
  bool result; // al@2
  unsigned __int8 v9; // al@4
  int v10; // eax@5
  MaterialLayer *v11; // ecx@5
  bool WasDrawn; // [sp+3h] [bp-9h]@3
  unsigned int TableIndex; // [sp+4h] [bp-8h]@3

  if ( LODWORD(_Color->a) )
  {
    WasDrawn = 0;
    TableIndex = 0;
    do
    {
      v9 = *((_BYTE *)&_Material->properties.vfptr
           + 2 * (SceneTool::m_CachedMaterialConditions + 56)
           + TableIndex
           + SceneTool::m_CachedMaterialConditions);
      if ( v9 == -1 )
        break;
      v10 = v9;
      v11 = _Material->layers.m_data[v10];
      if ( !LODWORD(v11->m_cDiffuse.a) )
        break;
      RenderDeviceD3D::SetupState(
        (RenderDeviceD3D *)RenderDevice::render_device,
        _ReferenceMaterial->layers.m_data[v10],
        v11,
        _VertexFormat,
        _Color,
        &AmbientLightBoost,
        0);
      if ( RenderDeviceD3D::RenderDynamicPrimitives(_PrimType, _NumPrimitives, _pVertices, _VertexFormat) )
        WasDrawn = 1;
      ++TableIndex;
    }
    while ( TableIndex < 3 );
    result = WasDrawn;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 83741C: using guessed type unsigned __int32 SceneTool::m_CachedMaterialConditions;

//----- (005A1690) --------------------------------------------------------  // acclient.c:458896
void __thiscall RenderVertexBufferD3D::RenderVertexBufferD3D(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // esi@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VertexArray::vftable;
  this->m_InfluencedBoneIndexArray.m_data = 0;
  this->m_InfluencedBoneIndexArray.m_sizeAndDeallocate = 0;
  this->m_InfluencedBoneIndexArray.m_num = 0;
  VertexArray::Begin((VertexArray *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBuffer::vftable;
  RenderVertexBuffer::Begin((RenderVertexBuffer *)&v1->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBufferD3D::vftable;
  v1->m_saDirtyVertices.m_data = 0;
  v1->m_saDirtyVertices.m_sizeAndDeallocate = 0;
  v1->m_saDirtyVertices.m_num = 0;
  v1->m_saVertexStreams.m_data = 0;
  v1->m_saVertexStreams.m_sizeAndDeallocate = 0;
  v1->m_saVertexStreams.m_num = 0;
  RenderVertexBufferD3D::Begin(v1);
}
// 79AFE8: using guessed type int (__thiscall *VertexArray::vftable)(void *, char);
// 79AFFC: using guessed type int (__thiscall *RenderVertexBuffer::vftable)(void *, char);
// 7E57BC: using guessed type int (__thiscall *RenderVertexBufferD3D::vftable)(void *, char);

//----- (005A1700) --------------------------------------------------------  // acclient.c:458923
RenderVertexBufferD3D *__thiscall RenderVertexBufferD3D::vector_deleting_destructor(RenderVertexBufferD3D *this, unsigned int a2)
{
  RenderVertexBufferD3D *v2; // esi@1

  v2 = this;
  RenderVertexBufferD3D::~RenderVertexBufferD3D(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005A1720) --------------------------------------------------------  // acclient.c:458935
void __thiscall RenderVertexBufferD3D::~RenderVertexBufferD3D(RenderVertexBufferD3D *this)
{
  RenderVertexBufferD3D *v1; // esi@1

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBufferD3D::vftable;
  RenderVertexBufferD3D::End(this);
  if ( (v1->m_saVertexStreams.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_saVertexStreams.m_data);
  if ( (v1->m_saDirtyVertices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_saDirtyVertices.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderVertexBuffer::vftable;
  RenderVertexBuffer::End((RenderVertexBuffer *)&v1->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VertexArray::vftable;
  VertexArray::End((VertexArray *)&v1->vfptr);
  if ( (v1->m_InfluencedBoneIndexArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_InfluencedBoneIndexArray.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 79AFE8: using guessed type int (__thiscall *VertexArray::vftable)(void *, char);
// 79AFFC: using guessed type int (__thiscall *RenderVertexBuffer::vftable)(void *, char);
// 7E57BC: using guessed type int (__thiscall *RenderVertexBufferD3D::vftable)(void *, char);

//----- (005A17C0) --------------------------------------------------------  // acclient.c:458960
void __userpurge RenderDeviceD3D::DrawBlock(RenderDeviceD3D *this@<ecx>, double a2@<st0>, CLandBlock *block)
{
  unsigned int v3; // ebp@1
  RenderDeviceD3D *v4; // ebx@1
  CLandBlock *v5; // edi@1
  CLandCell **v6; // edx@2
  CLandCell *v7; // esi@2
  int v8; // ecx@7
  unsigned int v9; // ebp@7
  RenderDevice *v10; // esi@8
  float v11; // eax@9
  char *v12; // ST04_4@9
  unsigned int v13; // eax@10
  CLandCell *v14; // esi@10
  Position block_pos; // [sp+1Ch] [bp-48h]@1
  CLandBlock *blocka; // [sp+68h] [bp+4h]@7

  v3 = 0;
  v4 = this;
  dword_81EEB4 = 1065353216;
  LODWORD(Render::object_scale_vec.x) = 1065353216;
  dword_81EEB8 = 1065353216;
  LODWORD(Render::object_scale) = 1065353216;
  block_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  block_pos.objcell_id = 0;
  LODWORD(block_pos.frame.qw) = 1065353216;
  LODWORD(block_pos.frame.qx) = 0;
  LODWORD(block_pos.frame.qy) = 0;
  LODWORD(block_pos.frame.qz) = 0;
  LODWORD(block_pos.frame.m_fOrigin.x) = 0;
  LODWORD(block_pos.frame.m_fOrigin.y) = 0;
  LODWORD(block_pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&block_pos.frame);
  v5 = block;
  block_pos.objcell_id = block->m_DID.id;
  Render::positionPush(3, &block_pos);
  ACRender::curLandBlockVertexLighting = block->vertex_lighting;
  if ( v5->side_cell_count * v5->side_cell_count )
  {
    do
    {
      v6 = block->draw_array;
      v7 = v6[v3];
      if ( ((int (__thiscall *)(CLandCell *))v7->vfptr[4].IUnknown_Release)(v6[v3]) )
      {
        if ( v7->num_shadow_objects )
        {
          RenderDeviceD3D::UpdateObjCell(v4, a2, (CObjCell *)&v7->vfptr);
          if ( v7->num_shadow_parts > 1 )
            CShadowPart::insertion_sort(&v7->shadow_part_list, v7->num_shadow_parts);
        }
      }
      ++v3;
    }
    while ( v3 < block->side_cell_count * block->side_cell_count );
  }
  v8 = block->side_cell_count;
  v9 = 0;
  blocka = (CLandBlock *)(v8 == 8);
  if ( v5->side_cell_count * v8 )
  {
    do
    {
      v10 = RenderDevice::render_device;
      if ( LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) )
      {
        v11 = RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24;
        v12 = (char *)&RenderDevice::render_device[2].m_GState.AmbientLight.a;
        LODWORD(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.g) = 0;
        (*(void (__stdcall **)(float, char *))(*LODWORD(v11) + 196))(LODWORD(v11), v12);
        LOBYTE(v10[2].m_GState.AmbientLight.g) = 0;
        RenderDeviceD3D::SetFFDiffuseColorSource((RenderDeviceD3D *)v10, FromVertex);
        RenderDeviceD3D::SetFFAmbientColorSource((RenderDeviceD3D *)v10, FromVertex);
      }
      v13 = CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
      Render::SetSurfaceArray(*(CSurface ***)(v13 + 16));
      LODWORD(Render::object_scale_vec.x) = 1065353216;
      dword_81EEB4 = 1065353216;
      dword_81EEB8 = 1065353216;
      LODWORD(Render::object_scale) = 1065353216;
      v14 = v5->draw_array[v9];
      if ( ((int (__thiscall *)(CLandCell *))v14->vfptr[4].IUnknown_Release)(v5->draw_array[v9]) )
      {
        if ( blocka )
        {
          Render::curr_detail_surface = Render::landscape_detail_surface;
          Render::curr_detail_tiling = Render::landscape_detail_tiling;
          Render::curr_detail_src_blend = 5;
          Render::curr_detail_dst_blend = 6;
        }
        v4->vfptr->DrawLandCell((RenderDevice *)v4, v14);
        Render::curr_detail_surface = 0;
      }
      if ( alwaysDrawObjects || ((int (__thiscall *)(CLandCell *))v14->vfptr[4].IUnknown_Release)(v14) )
      {
        v4->vfptr->DrawSortCell((RenderDevice *)v4, (CSortCell *)v14);
        if ( flush <= 1.0 )
          D3DPolyRender::FlushAlphaList(flush);
      }
      ++v9;
    }
    while ( v9 < v5->side_cell_count * v5->side_cell_count );
  }
  ACRender::curLandBlockVertexLighting = 0;
  Render::framePop();
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 81EC74: using guessed type float Render::object_scale;
// 81ECA8: using guessed type float Render::landscape_detail_tiling;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 866354: using guessed type struct CSurface *Render::landscape_detail_surface;
// 8FB624: using guessed type struct RGBColor *ACRender::curLandBlockVertexLighting;

//----- (005A1A40) --------------------------------------------------------  // acclient.c:459076
void __stdcall RenderDeviceD3D::DrawObjCell(CObjCell *cell)
{
  if ( cell )
    RenderDeviceD3D::DrawPartCell(cell->m_DID.id, (CPartCell *)&cell->vfptr, 0);
  else
    RenderDeviceD3D::DrawPartCell(v28, 0, 0);
}

//----- (005A1A70) --------------------------------------------------------  // acclient.c:459085
void RenderDeviceD3D::CreateVertexBuffer()
{
  RenderVertexBufferD3D *v1; // eax@1

  v1 = (RenderVertexBufferD3D *)operator new(0x164u);
  if ( v1 )
    RenderVertexBufferD3D::RenderVertexBufferD3D(v1);
}

//----- (005A1A90) --------------------------------------------------------  // acclient.c:459095
void __thiscall RenderDeviceD3D::OnDeviceDisplayModeChange(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  signed int v2; // ebx@3
  RenderDeviceVtbl *v3; // eax@4
  int v4; // [sp+1Ch] [bp-10h]@4
  int v5; // [sp+20h] [bp-Ch]@4
  int v6; // [sp+24h] [bp-8h]@4
  int v7; // [sp+28h] [bp-4h]@4

  v1 = this;
  RenderDeviceD3D::SetupDisplayAspectRatio(this);
  RenderDeviceD3D::SetDefaultD3DStates(v1);
  RenderDeviceD3D::SetDefaultDeviceStates(v1);
  v1->vfptr->SetViewport((RenderDevice *)v1, 0, 0, v1->m_presentation.Width, v1->m_presentation.Height, 0);
  RenderUI::RecalculateClampedPosition();
  if ( v1->m_presentation.FullScreen )
  {
    ((void (__stdcall *)(IDirect3DDevice9 *, signed int))v1->m_pDirect3DDevice->vfptr[6].Release)(
      v1->m_pDirect3DDevice,
      1);
    RenderDeviceD3D::SetGamma(v1, v1->m_gammaBrightnessVal, 0);
  }
  v2 = 3;
  do
  {
    v3 = v1->vfptr;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 1065353216;
    ((void (__thiscall *)(RenderDeviceD3D *, signed int, int *, signed int))v3->Clear)(v1, 7, &v4, 1065353216);
    v1->vfptr->Flip((RenderDevice *)v1);
    Sleep(1u);
    --v2;
  }
  while ( v2 );
}

//----- (005A1B40) --------------------------------------------------------  // acclient.c:459135
void __thiscall RenderDeviceD3D::End(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // edi@1
  PView *v2; // esi@2
  PView *v3; // esi@4
  char *v4; // esi@5
  PStringBase<char> _Name; // [sp+0h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  if ( RenderDeviceD3D::indoor_pview )
  {
    v2 = RenderDeviceD3D::indoor_pview;
    PView::~PView(RenderDeviceD3D::indoor_pview);
    operator delete(v2);
    RenderDeviceD3D::indoor_pview = 0;
  }
  if ( RenderDeviceD3D::outdoor_pview )
  {
    v3 = RenderDeviceD3D::outdoor_pview;
    PView::~PView(RenderDeviceD3D::outdoor_pview);
    operator delete(v3);
    RenderDeviceD3D::outdoor_pview = 0;
  }
  RenderDeviceD3D::ReleaseD3DResources(v1);
  PStringBase<char>::PStringBase<char>(&_Name, "RenderDeviceD3D.AllowDrawPrimUP");
  GlobalRegistry::UnregisterVariable(&_Name);
  v4 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (005A1BE0) --------------------------------------------------------  // acclient.c:459171
char __thiscall RenderDeviceD3D::DetectDisplayFormats(RenderDeviceD3D *this, PixelFormatID displayFormat)
{
  PixelFormatID v2; // esi@1
  RenderDeviceD3D *v3; // edi@1
  unsigned int v4; // ebp@1
  PStringBase<unsigned short> v5; // ST14_4@13
  PStringBase<unsigned short> v6; // ST10_4@13
  PStringBase<unsigned short> v7; // ST0C_4@13
  char result; // al@13

  v2 = displayFormat;
  v3 = this;
  this->m_caps.bCompressedTextures = 1;
  v4 = 0;
  while ( 1 )
  {
    switch ( v4 )
    {
      case 0u:
        v2 = 827611204;
        break;
      case 1u:
        v2 = 844388420;
        break;
      case 2u:
        v2 = 861165636;
        break;
      case 3u:
        v2 = 877942852;
        break;
      case 4u:
        v2 = 894720068;
        break;
      default:
        break;
    }
    if ( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))Render::m_pRenderer->m_pDirect3D->vfptr[3].AddRef)(
           Render::m_pRenderer->m_pDirect3D,
           v3->m_AdapterID,
           v3->m_D3DDeviceType,
           displayFormat,
           0,
           3,
           v2) )
      break;
    ++v4;
    if ( v4 >= 5 )
      goto LABEL_12;
  }
  v3->m_caps.bCompressedTextures = 0;
LABEL_12:
  if ( RenderDeviceD3D::ChoosePixelFormats(v3, displayFormat) )
  {
    result = 1;
  }
  else
  {
    v5.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v6.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v7.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PlatformString::DisplayString(0x80u, v7, v6, v5, 0);
    result = 0;
  }
  return result;
}

//----- (005A1CE0) --------------------------------------------------------  // acclient.c:459241
char __thiscall RenderDeviceD3D::SetupDisplayInfo(RenderDeviceD3D *this, PixelFormatID displayFormat, PixelFormatID colorFormat, PixelFormatID depthStencilFormat, const bool has8BitStencil, const bool _bFullScreen)
{
  RenderDeviceD3D *v6; // esi@1
  PixelFormatID v7; // edx@3
  PixelFormatID v8; // eax@5
  PixelFormatID v9; // ecx@5
  PixelFormatID v10; // eax@8
  PixelFormatID v11; // edx@10
  PSRefBufferCharData<unsigned short> *v13; // ecx@20
  PSRefBufferCharData<unsigned short> *v14; // ecx@20
  PStringBase<unsigned short> v15; // [sp-10h] [bp-18h]@20
  PStringBase<unsigned short> v16; // [sp-Ch] [bp-14h]@20
  PStringBase<unsigned short> v17; // [sp-8h] [bp-10h]@20
  PixelFormatID v18; // [sp-4h] [bp-Ch]@1

  v6 = this;
  v18 = displayFormat;
  this->m_displayInfo.bStencilBuffer = has8BitStencil;
  if ( !RenderDeviceD3D::DetectDisplayFormats(this, v18) || !Render::m_pRenderer->m_pDirect3D )
    return 0;
  v7 = v6->m_displayInfo.pfRenderTargets;
  v6->m_displayInfo.bMultiSampling = 0;
  v6->m_displayInfo.bTextureRenderTargets = v7 != 0;
  if ( v7 )
    v6->m_displayInfo.pfRenderTargets = colorFormat;
  v8 = v6->m_displayInfo.pfRGBTextures;
  v9 = depthStencilFormat;
  v6->m_displayInfo.pfDepthBuffers = depthStencilFormat;
  if ( v8 == PFID_UNKNOWN
    || v6->m_displayInfo.pfARGBTextures == PFID_UNKNOWN
    || v6->m_displayInfo.pfAlphaTextures == PFID_UNKNOWN
    || (v10 = v6->m_displayInfo.pfRGBSurfaces) == 0
    || (v9 = v6->m_displayInfo.pfARGBSurfaces) == 0
    || (v11 = v6->m_displayInfo.pfAlphaSurfaces) == 0 )
  {
    v18 = 0;
    v17.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v9;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v17, &word_794320);
    v16.m_charbuffer = v13;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v16, &word_794320);
    v15.m_charbuffer = v14;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, &word_794320);
    PlatformString::DisplayString(0x80u, v15, v16, v17, (PlatformString::DisplayStringMode)v18);
    return 0;
  }
  if ( v6->m_displayInfo.pfLowRGBSurfaces == PFID_UNKNOWN )
    v6->m_displayInfo.pfLowRGBSurfaces = v10;
  if ( v6->m_displayInfo.pfLowARGBSurfaces == PFID_UNKNOWN )
    v6->m_displayInfo.pfLowARGBSurfaces = v9;
  if ( v6->m_displayInfo.pfLowAlphaSurfaces == PFID_UNKNOWN )
    v6->m_displayInfo.pfLowAlphaSurfaces = v11;
  if ( !v6->m_config.bUseStencilBuffer )
    v6->m_displayInfo.bStencilBuffer = 0;
  return 1;
}

//----- (005A1DE0) --------------------------------------------------------  // acclient.c:459298
char __thiscall RenderDeviceD3D::SelectBufferFormats(RenderDeviceD3D *this, RenderDevicePresentation *renderPres, PixelFormatID *colorFormat, PixelFormatID *depthStencilFormat, unsigned int *optimalRefreshRate)
{
  RenderDeviceD3D *v5; // esi@1
  _D3DFORMAT v6; // ebx@1
  unsigned int v7; // eax@2
  PSRefBufferCharData<unsigned short> *v8; // ecx@6
  PSRefBufferCharData<unsigned short> *v9; // ecx@9
  PSRefBufferCharData<unsigned short> *v10; // ecx@9
  unsigned int v11; // edx@10
  PixelFormatID v12; // ebp@11
  PixelFormatID v13; // esi@11
  PixelFormatID v14; // edi@11
  bool v15; // cl@17
  RenderDeviceD3D *v16; // ebx@19
  PixelFormatID *v17; // ecx@19
  char v18; // al@30
  unsigned int v19; // edi@30
  PixelFormatID v20; // esi@34
  PSRefBufferCharData<unsigned short> *v22; // ecx@56
  PSRefBufferCharData<unsigned short> *v23; // ecx@56
  PSRefBufferCharData<unsigned short> *v24; // ecx@57
  PSRefBufferCharData<unsigned short> *v25; // ecx@57
  PStringBase<unsigned short> v26; // [sp+36h] [bp-B4h]@9
  PStringBase<unsigned short> v27; // [sp+3Ah] [bp-B0h]@9
  PStringBase<unsigned short> v28; // [sp+3Eh] [bp-ACh]@9
  PlatformString::DisplayStringMode v29; // [sp+42h] [bp-A8h]@9
  bool test8BitStencil; // [sp+59h] [bp-91h]@31
  PixelFormatID displayFormat; // [sp+5Ah] [bp-90h]@1
  PixelFormatID secondaryFormat; // [sp+5Eh] [bp-8Ch]@11
  int has8BitStencil; // [sp+62h] [bp-88h]@1
  RenderDeviceD3D *v34; // [sp+66h] [bp-84h]@1
  _D3DDISPLAYMODE currentMode; // [sp+6Ah] [bp-80h]@6
  PixelFormatDesc colorPFDesc; // [sp+7Ah] [bp-70h]@6
  PixelFormatDesc displayPFD; // [sp+B2h] [bp-38h]@1

  v5 = this;
  v6 = 0;
  *colorFormat = 0;
  *depthStencilFormat = 0;
  v34 = this;
  LOBYTE(has8BitStencil) = 0;
  displayFormat = 0;
  ClipPlane::ClipPlane((ClipPlane *)&displayPFD);
  if ( renderPres->FullScreen )
  {
    v7 = renderPres->FSBitsPerPixel;
    if ( v7 != 16 && v7 != 24 && v7 != 32 )
      return 0;
    v5->m_nFrontBufferWidth = renderPres->Width;
    v5->m_nFrontBufferHeight = renderPres->Height;
  }
  else
  {
    ((void (__stdcall *)(IDirect3D9 *, unsigned int, _D3DDISPLAYMODE *))Render::m_pRenderer->m_pDirect3D->vfptr[2].Release)(
      Render::m_pRenderer->m_pDirect3D,
      v5->m_AdapterID,
      &currentMode);
    v6 = currentMode.Format;
    displayFormat = currentMode.Format;
    ClipPlane::ClipPlane((ClipPlane *)&colorPFDesc);
    PixelFormatDesc::SetFormat(&colorPFDesc, (PixelFormatID)v6);
    if ( v6 == 41 || colorPFDesc.bitsPerPixel < 0x10u )
    {
      v29 = 0;
      v28.m_charbuffer = v8;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v28, &word_794320);
      v27.m_charbuffer = v24;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v27, &word_794320);
      v26.m_charbuffer = v25;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v26, &word_794320);
      PlatformString::DisplayString(0x7Cu, v26, v27, v28, v29);
      return 0;
    }
    if ( v6 == D3DFMT_UNKNOWN )
    {
      v29 = 0;
      v28.m_charbuffer = v8;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v28, &word_794320);
      v27.m_charbuffer = v9;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v27, &word_794320);
      v26.m_charbuffer = v10;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v26, &word_794320);
      PlatformString::DisplayString(0x7Eu, v26, v27, v28, v29);
      return 0;
    }
    v11 = currentMode.Height;
    v7 = (unsigned __int8)colorPFDesc.bitsPerPixel;
    v5->m_nFrontBufferWidth = currentMode.Width;
    v5->m_nFrontBufferHeight = v11;
  }
  v12 = 0;
  v13 = 0;
  v14 = 0;
  secondaryFormat = 0;
  switch ( v7 )
  {
    case 0x10u:
      v13 = 24;
      v14 = 23;
      v12 = 24;
      secondaryFormat = 23;
      break;
    case 0x18u:
      v12 = 20;
      v13 = 20;
      v14 = 20;
      secondaryFormat = 20;
      break;
    case 0x20u:
      v13 = 22;
      v12 = 22;
      v14 = 22;
      secondaryFormat = 21;
      break;
  }
  v15 = renderPres->FullScreen;
  if ( !v15 )
  {
    v14 = v6;
    v13 = v6;
  }
  v16 = v34;
  if ( !((int (__stdcall *)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, PixelFormatID, PixelFormatID, _DWORD))Render::m_pRenderer->m_pDirect3D->vfptr[3].QueryInterface)(
          Render::m_pRenderer->m_pDirect3D,
          v34->m_AdapterID,
          v34->m_D3DDeviceType,
          v13,
          v12,
          v15 == 0)
    && (!renderPres->FullScreen
     || RenderDeviceD3D::CheckDisplayModes(v34, v13, renderPres->FSRefreshRate, optimalRefreshRate)) )
  {
    v17 = colorFormat;
    displayFormat = v13;
    *colorFormat = v12;
  }
  if ( *colorFormat == PFID_UNKNOWN )
  {
    if ( !((int (__stdcall *)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, PixelFormatID, PixelFormatID, _DWORD))Render::m_pRenderer->m_pDirect3D->vfptr[3].QueryInterface)(
            Render::m_pRenderer->m_pDirect3D,
            v16->m_AdapterID,
            v16->m_D3DDeviceType,
            v14,
            secondaryFormat,
            renderPres->FullScreen == 0)
      && (!renderPres->FullScreen
       || RenderDeviceD3D::CheckDisplayModes(v16, v14, renderPres->FSRefreshRate, optimalRefreshRate)) )
    {
      displayFormat = v14;
      *colorFormat = secondaryFormat;
    }
    v17 = colorFormat;
    if ( *colorFormat == PFID_UNKNOWN )
      goto LABEL_56;
  }
  if ( displayFormat == PFID_UNKNOWN )
  {
LABEL_56:
    v29 = 0;
    v28.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v17;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v28, &word_794320);
    v27.m_charbuffer = v22;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v27, &word_794320);
    v26.m_charbuffer = v23;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v26, &word_794320);
    PlatformString::DisplayString(0x80u, v26, v27, v28, v29);
    return 0;
  }
  PixelFormatDesc::SetFormat(&displayPFD, displayFormat);
  v18 = displayPFD.bitsPerPixel;
  v19 = 0;
  while ( 2 )
  {
    test8BitStencil = 0;
    switch ( v19 )
    {
      case 0u:
        if ( (unsigned __int8)v18 <= 0x10u )
          goto LABEL_48;
        if ( !v16->m_config.bUseStencilBuffer )
          goto LABEL_37;
        goto LABEL_34;
      case 1u:
        if ( (unsigned __int8)v18 <= 0x10u )
          goto LABEL_48;
        if ( v16->m_config.bUseStencilBuffer )
        {
LABEL_37:
          v20 = 71;
        }
        else
        {
LABEL_34:
          v20 = 75;
          test8BitStencil = 1;
        }
        goto LABEL_46;
      case 2u:
        if ( (unsigned __int8)v18 <= 0x10u )
          goto LABEL_48;
        v20 = 77;
        goto LABEL_46;
      case 3u:
        if ( (unsigned __int8)v18 <= 0x10u )
          goto LABEL_48;
        v20 = 79;
        goto LABEL_46;
      case 4u:
        if ( (unsigned __int8)v18 > 0x10u )
          goto LABEL_48;
        v20 = 80;
        goto LABEL_46;
      case 5u:
        if ( (unsigned __int8)v18 > 0x10u )
          goto LABEL_48;
        v20 = 73;
LABEL_46:
        if ( ((int (__stdcall *)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, PixelFormatID, signed int, signed int, PixelFormatID))Render::m_pRenderer->m_pDirect3D->vfptr[3].AddRef)(
               Render::m_pRenderer->m_pDirect3D,
               v16->m_AdapterID,
               v16->m_D3DDeviceType,
               displayFormat,
               2,
               1,
               v20) )
        {
          v18 = displayPFD.bitsPerPixel;
LABEL_48:
          ++v19;
          if ( v19 >= 6 )
            goto LABEL_51;
          continue;
        }
        LOBYTE(v17) = test8BitStencil;
        *depthStencilFormat = v20;
        LOBYTE(has8BitStencil) = (_BYTE)v17;
LABEL_51:
        if ( *depthStencilFormat == PFID_UNKNOWN )
          goto LABEL_56;
        if ( !RenderDeviceD3D::SetupDisplayInfo(
                v16,
                displayFormat,
                *colorFormat,
                *depthStencilFormat,
                has8BitStencil,
                renderPres->FullScreen) )
          return 0;
        ClipPlane::ClipPlane((ClipPlane *)&colorPFDesc);
        PixelFormatDesc::SetFormat(&colorPFDesc, *colorFormat);
        if ( !(colorPFDesc.flags & 2) )
          v16->m_caps.bDestinationAlpha = 0;
        return 1;
      default:
        goto LABEL_48;
    }
  }
}

//----- (005A2200) --------------------------------------------------------  // acclient.c:459557
void __thiscall RenderDeviceD3D::Begin(RenderDeviceD3D *this)
{
  char *v1; // edx@1
  char *v2; // ecx@1
  const void *v3; // eax@1
  unsigned int v4; // ebp@1
  int v5; // eax@2
  unsigned int v6; // edx@3
  char *v12; // esi@13
  char *v13; // esi@16
  RenderDeviceD3D *v14; // [sp+10h] [bp-32Ch]@1
  PStringBase<char> _Description; // [sp+14h] [bp-328h]@8
  PStringBase<char> _Name; // [sp+18h] [bp-324h]@13
  RenderStateCacheType v17; // [sp+1Ch] [bp-320h]@1

  v14 = this;
  this->m_AdapterID = 0;
  this->m_D3DDeviceType = 1;
  memset(&this->m_D3DCaps, 0, sizeof(this->m_D3DCaps));
  v1 = (char *)&this->m_PresentSourceRect;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  v2 = (char *)&this->m_PresentDestRect;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  v14->m_hPresentWindow = 0;
  v14->m_nFrontBufferWidth = 0;
  v14->m_nFrontBufferHeight = 0;
  v14->m_pDirect3DDevice = 0;
  v14->m_pPrimarySwapChain = 0;
  v14->m_bForceStates = 0;
  RenderStateCacheType::RenderStateCacheType(&v17);
  qmemcpy(&v14->m_State, v3, sizeof(v14->m_State));
  RenderDeviceD3D::s_bAllowDrawPrimitiveUP = 1;
  RenderDeviceD3D::Init(v14);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v14->m_DefaultSamplerMappings);
  v4 = 0;
  do
  {
    v5 = v14->m_DefaultSamplerMappings.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v14->m_DefaultSamplerMappings.m_num < v5 )
      goto LABEL_21;
    v6 = v5 + 1;
    if ( (unsigned int)(v5 + 1) > 8 )
    {
      if ( v6 <= 0x4000 )
      {
        _Description.m_charbuffer = (PSRefBufferCharData<char> *)(v5 + 1);
        __asm { bsr     this, [esp+33Ch+_Description.m_charbuffer] }
        if ( v6 > 1 << _EAX )
          v6 = 2 * (1 << _EAX);
      }
      else if ( v6 & 0x3FFF )
      {
        v6 += 0x4000 - (v6 & 0x3FFF);
      }
    }
    else
    {
      v6 = 8;
    }
    if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v14->m_DefaultSamplerMappings, v6) )
LABEL_21:
      v14->m_DefaultSamplerMappings.m_data[v14->m_DefaultSamplerMappings.m_num++] = v4;
    ++v4;
  }
  while ( v4 < 8 );
  v14->m_pDebugFont = 0;
  v14->m_DebugFontWidth = 0;
  v14->m_DebugFontHeight = 0;
  PStringBase<char>::PStringBase<char>(&_Description, "Toggle for rendering all the DrawPrimitiveUP crap.");
  PStringBase<char>::PStringBase<char>(&_Name, "RenderDeviceD3D.AllowDrawPrimUP");
  GlobalRegistry::RegisterVariableInternal(
    &RenderDeviceD3D::s_bAllowDrawPrimitiveUP,
    GRVDataType_Bool,
    &_Name,
    &_Description,
    0,
    0,
    0,
    0);
  v12 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  v13 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) )
  {
    if ( v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  }
}
// 820E4C: using guessed type bool RenderDeviceD3D::s_bAllowDrawPrimitiveUP;

//----- (005A2410) --------------------------------------------------------  // acclient.c:459655
void __thiscall RenderDeviceD3D::Shutdown(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  IDirect3DDevice9 *v2; // eax@1

  v1 = this;
  RenderDeviceD3D::End(this);
  RenderDevice::Shutdown((RenderDevice *)&v1->vfptr);
  v2 = v1->m_pDirect3DDevice;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_pDirect3DDevice);
    v1->m_pDirect3DDevice = 0;
  }
  RenderDeviceD3D::Begin(v1);
}

//----- (005A2450) --------------------------------------------------------  // acclient.c:459673
char __thiscall RenderDeviceD3D::SetupPresentation(RenderDeviceD3D *this, RenderDevicePresentation *renderPres, _D3DPRESENT_PARAMETERS_ *present)
{
  RenderDevicePresentation *v3; // ebx@1
  RenderDeviceD3D *v4; // ebp@1
  int v5; // eax@2
  _D3DPRESENT_PARAMETERS_ *v6; // esi@2
  int v7; // eax@2
  RenderDevicePresentation *v8; // eax@2
  int v9; // eax@2
  signed int v10; // ecx@2
  unsigned int v11; // eax@3
  int v13; // ebp@15
  int v14; // eax@15
  PSRefBufferCharData<unsigned short> *v15; // ecx@18
  PStringBase<unsigned short> v16; // ST08_4@18
  PStringBase<unsigned short> v17; // ST04_4@18
  char *v18; // esi@18
  int v19; // edx@20
  char *v20; // esi@21
  int v21; // edx@23
  PStringBase<unsigned short> v22; // [sp-8h] [bp-20h]@18
  PlatformString::DisplayStringMode v23; // [sp-4h] [bp-1Ch]@18
  unsigned int optimalRefreshRate; // [sp+10h] [bp-8h]@1
  PixelFormatID depthStencilFormat; // [sp+14h] [bp-4h]@1

  v3 = renderPres;
  v4 = this;
  optimalRefreshRate = 0;
  if ( !RenderDeviceD3D::SelectBufferFormats(
          this,
          renderPres,
          (PixelFormatID *)&renderPres,
          &depthStencilFormat,
          &optimalRefreshRate) )
    return 0;
  v4->m_PresentDestRect.left = 0;
  v4->m_PresentSourceRect.left = 0;
  v4->m_PresentDestRect.top = 0;
  v4->m_PresentSourceRect.top = 0;
  v5 = v3->Width;
  v6 = present;
  v4->m_PresentDestRect.right = v5;
  v4->m_PresentSourceRect.right = v5;
  v7 = v3->Height;
  v4->m_PresentDestRect.bottom = v7;
  v4->m_PresentSourceRect.bottom = v7;
  v4->m_hPresentWindow = v3->hRenderWindow;
  memset(v6, 0, 0x38u);
  v8 = renderPres;
  v6->BackBufferWidth = v3->Width;
  v6->BackBufferHeight = v3->Height;
  v6->BackBufferFormat = (_D3DFORMAT)v8;
  v6->BackBufferCount = 1;
  v6->MultiSampleType = 0;
  v6->MultiSampleQuality = 0;
  v6->SwapEffect = 1;
  v6->hDeviceWindow = v3->hRenderWindow;
  v9 = v3->FullScreen == 0;
  v6->AutoDepthStencilFormat = depthStencilFormat;
  v10 = 2147483648;
  v6->EnableAutoDepthStencil = 1;
  v6->Flags = 0;
  v6->FullScreen_RefreshRateInHz = 0;
  v6->PresentationInterval = 2147483648;
  v6->Windowed = v9;
  if ( !v3->FullScreen )
  {
    v13 = GetSystemMetrics(0);
    v14 = GetSystemMetrics(1);
    if ( v13 >= v6->BackBufferWidth && v14 >= v6->BackBufferHeight )
      return 1;
    present = (_D3DPRESENT_PARAMETERS_ *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    renderPres = (RenderDevicePresentation *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::append_uint32((PStringBase<unsigned short> *)&present, v6->BackBufferWidth);
    PStringBase<unsigned short>::append_uint32((PStringBase<unsigned short> *)&renderPres, v6->BackBufferHeight);
    v23 = 0;
    v22.m_charbuffer = v15;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, &word_794320);
    v16.m_charbuffer = (PSRefBufferCharData<unsigned short> *)renderPres;
    InterlockedIncrement((volatile LONG *)&renderPres[-1].FullScreen);
    v17.m_charbuffer = (PSRefBufferCharData<unsigned short> *)present;
    InterlockedIncrement((volatile LONG *)&present[-1].AutoDepthStencilFormat);
    PlatformString::DisplayString(0x6Cu, v17, v16, v22, v23);
    v18 = (char *)&renderPres[-1].Height;
    if ( !InterlockedDecrement((volatile LONG *)&renderPres[-1].FullScreen) && v18 )
    {
      v19 = *(_DWORD *)v18;
      v23 = 1;
      (*(void (__thiscall **)(char *, signed int))v19)(v18, 1);
    }
    v20 = (char *)&present[-1].EnableAutoDepthStencil;
    if ( !InterlockedDecrement((volatile LONG *)&present[-1].AutoDepthStencilFormat) && v20 )
    {
      v21 = *(_DWORD *)v20;
      v23 = 1;
      (*(void (__thiscall **)(char *, signed int))v21)(v20, 1);
    }
    return 0;
  }
  v6->FullScreen_RefreshRateInHz = optimalRefreshRate > 0 ? optimalRefreshRate : 0;
  v11 = v4->m_D3DCaps.PresentationIntervals;
  if ( v11 & 8 )
    v10 = 8;
  if ( v11 & 4 )
    v10 = 4;
  if ( v11 & 2 )
    v10 = 2;
  if ( v11 & 1 )
    v10 = 1;
  if ( !v3->FSSyncToDisplayRefresh && (v11 & 0x80000000) != 0 )
    v10 = 2147483648;
  v6->PresentationInterval = v10;
  return 1;
}

//----- (005A2670) --------------------------------------------------------  // acclient.c:459791
char __thiscall RenderDeviceD3D::ResetDevice(RenderDeviceD3D *this, RenderDevicePresentation *newPres)
{
  RenderDeviceD3D *v2; // ebx@1
  int v3; // ebx@1
  int v4; // esi@2
  int v5; // eax@2
  int v6; // edi@5
  char v7; // bl@6
  int v8; // esi@8
  PSRefBufferCharData<unsigned short> *v9; // ecx@8
  PSRefBufferCharData<unsigned short> *v10; // ecx@15
  PSRefBufferCharData<unsigned short> *v11; // ecx@15
  char result; // al@16
  PStringBase<unsigned short> v13; // [sp-10h] [bp-68h]@15
  PStringBase<unsigned short> v14; // [sp-Ch] [bp-64h]@15
  PStringBase<unsigned short> v15; // [sp-8h] [bp-60h]@15
  PlatformString::DisplayStringMode v16; // [sp-4h] [bp-5Ch]@15
  double ia; // [sp+10h] [bp-48h]@1
  long double dStartTime; // [sp+18h] [bp-40h]@7
  _D3DPRESENT_PARAMETERS_ presentD3D; // [sp+20h] [bp-38h]@5

  v2 = this;
  LODWORD(ia) = this;
  KeyStone::Release();
  GraphicsResource::PurgeResources();
  v3 = (int)&v2->m_presentation;
  qmemcpy((void *)v3, newPres, 0x1Cu);
  if ( !*(_BYTE *)(v3 + 12) )
  {
    v4 = GetSystemMetrics(0);
    v5 = GetSystemMetrics(1);
    if ( (unsigned int)v4 < *(_DWORD *)(v3 + 4) || (unsigned int)v5 < *(_DWORD *)(v3 + 8) )
    {
      *(_DWORD *)(v3 + 4) = v4;
      *(_DWORD *)(v3 + 8) = v5;
    }
  }
  v6 = LODWORD(ia);
  if ( RenderDeviceD3D::SetupPresentation(LODWORD(ia), (RenderDevicePresentation *)v3, &presentD3D) )
  {
    RenderDeviceD3D::ReleaseD3DResources(LODWORD(ia));
    v7 = 0;
    LODWORD(ia) = 0;
    while ( 2 )
    {
      HIDWORD(ia) = Timer::get_real_time();
      dStartTime = (double)SHIDWORD(ia);
      while ( 1 )
      {
        v8 = (*(int (__stdcall **)(_DWORD, _D3DPRESENT_PARAMETERS_ *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                     + 64))(
               LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
               &presentD3D);
        HIDWORD(ia) = Timer::get_real_time();
        if ( (double)SHIDWORD(ia) - dStartTime > 10.0 )
          v7 = 1;
        if ( v8 != -2005530520 )
          break;
        if ( v7 )
          goto LABEL_14;
        Sleep(0xC8u);
      }
      if ( v8 < 0 )
      {
LABEL_14:
        ++LODWORD(ia);
        if ( LODWORD(ia) < 2 )
          continue;
        v16 = 0;
        v15.m_charbuffer = v9;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, &word_794320);
        v14.m_charbuffer = v10;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v14, &word_794320);
        v13.m_charbuffer = v11;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v13, &word_794320);
        if ( v8 == -2005532292 )
        {
          PlatformString::DisplayString(0x79u, v13, v14, v15, v16);
          return 0;
        }
        PlatformString::DisplayString(0x69u, v13, v14, v15, v16);
        goto LABEL_18;
      }
      break;
    }
    *(_DWORD *)(v6 + 2068) = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v6 + 1128) + 16))(*(_DWORD *)(v6 + 1128));
    *(_BYTE *)(v6 + 173) = 0;
    if ( !RenderDeviceD3D::GetD3DResources((RenderDeviceD3D *)v6) )
      goto LABEL_18;
    RenderDeviceD3D::OnDeviceDisplayModeChange((RenderDeviceD3D *)v6);
    KeyStone::Create();
    result = 1;
  }
  else
  {
LABEL_18:
    result = 0;
  }
  return result;
}

//----- (005A2800) --------------------------------------------------------  // acclient.c:459893
char __thiscall RenderDeviceD3D::Startup(RenderDeviceD3D *this, const unsigned int _nDisplayAdapter, RenderDevicePresentation *_presentation, RenderDeviceConfig *_config)
{
  RenderDeviceD3D *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // ecx@2
  PSRefBufferCharData<unsigned short> *v6; // ecx@3
  PSRefBufferCharData<unsigned short> *v7; // ecx@3
  char result; // al@4
  int v9; // ebx@6
  int v10; // eax@6
  PSRefBufferCharData<unsigned short> *v11; // ecx@9
  HRESULT v12; // edi@10
  unsigned int v13; // eax@10
  signed int v14; // ebx@11
  PSRefBufferCharData<unsigned short> *v15; // ecx@32
  PSRefBufferCharData<unsigned short> *v16; // ecx@32
  PStringBase<unsigned short> v17; // [sp-6h] [bp-70h]@3
  PStringBase<unsigned short> v18; // [sp-2h] [bp-6Ch]@3
  PStringBase<unsigned short> v19; // [sp+2h] [bp-68h]@3
  PlatformString::DisplayStringMode v20; // [sp+6h] [bp-64h]@3
  bool bTimedOut; // [sp+1Dh] [bp-4Dh]@20
  unsigned int ia; // [sp+1Eh] [bp-4Ch]@20
  unsigned int ib; // [sp+22h] [bp-48h]@10
  HRESULT hDeviceResult; // [sp+26h] [bp-44h]@10
  long double dStartTime; // [sp+2Ah] [bp-40h]@21
  _D3DPRESENT_PARAMETERS_ presentD3D; // [sp+32h] [bp-38h]@9

  v4 = this;
  if ( !RenderDevice::Startup((RenderDevice *)&this->vfptr, _nDisplayAdapter, _presentation, _config) )
    return 0;
  v4->m_AdapterID = _nDisplayAdapter;
  if ( !RenderDeviceD3D::DetectDeviceCaps(v4) )
  {
    v20 = 0;
    v19.m_charbuffer = v5;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v19, &word_794320);
    v18.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, &word_794320);
    v17.m_charbuffer = v7;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v17, &word_794320);
    PlatformString::DisplayString(0x80u, v17, v18, v19, v20);
    return 0;
  }
  if ( !v4->m_presentation.FullScreen )
  {
    v9 = GetSystemMetrics(0);
    v10 = GetSystemMetrics(1);
    if ( v9 < v4->m_presentation.Width || v10 < v4->m_presentation.Height )
    {
      v4->m_presentation.Width = v9;
      v4->m_presentation.Height = v10;
    }
  }
  if ( !RenderDeviceD3D::SetupPresentation(v4, &v4->m_presentation, &presentD3D) )
    return 0;
  v12 = hDeviceResult;
  v13 = 0;
  ib = 0;
  do
  {
    v14 = 32;
    if ( v13 )
    {
      if ( v13 == 1 )
      {
        LOBYTE(v11) = v4->m_caps.bHardwareVertexProcessing;
        if ( !(_BYTE)v11 )
          goto LABEL_30;
        v14 = 64;
      }
      else if ( v13 == 2 )
      {
        v14 = 32;
      }
    }
    else
    {
      LOBYTE(v11) = v4->m_caps.bHardwareVertexProcessing;
      if ( !(_BYTE)v11 )
        goto LABEL_30;
      LOBYTE(v11) = v4->m_config.bUsePureDevice;
      if ( !(_BYTE)v11 )
        goto LABEL_30;
      v14 = 80;
    }
    v14 |= 0x106u;
    bTimedOut = 0;
    ia = 0;
    do
    {
      hDeviceResult = Timer::get_real_time();
      dStartTime = (double)hDeviceResult;
      while ( 1 )
      {
        v12 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))Render::m_pRenderer->m_pDirect3D->vfptr[5].AddRef)(
                Render::m_pRenderer->m_pDirect3D,
                v4->m_AdapterID,
                v4->m_D3DDeviceType,
                v4->m_config.hFocusWindow,
                v14,
                &presentD3D,
                &v4->m_pDirect3DDevice);
        hDeviceResult = Timer::get_real_time();
        if ( (double)hDeviceResult - dStartTime > 10.0 )
          bTimedOut = 1;
        if ( v12 != -2005530520 )
          break;
        if ( bTimedOut )
          goto LABEL_28;
        Sleep(0xC8u);
      }
      if ( v12 >= 0 )
        goto LABEL_35;
LABEL_28:
      ++ia;
    }
    while ( ia < 2 );
    v13 = ib;
LABEL_30:
    ++v13;
    ib = v13;
  }
  while ( v13 < 3 );
  if ( v12 >= 0 )
  {
LABEL_35:
    v4->m_TotalVideoMemoryInBytes = v4->m_pDirect3DDevice->vfptr[1].AddRef((IUnknown *)v4->m_pDirect3DDevice);
    if ( v14 & 0x20 )
      v4->m_caps.bHardwareVertexProcessing = 0;
    if ( RenderDeviceD3D::GetD3DResources(v4) && RenderDeviceD3D::InitDebugFont(v4) )
    {
      RenderDeviceD3D::OnDeviceDisplayModeChange(v4);
      return 1;
    }
    return 0;
  }
  v20 = 0;
  v19.m_charbuffer = v11;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v19, &word_794320);
  v18.m_charbuffer = v15;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, &word_794320);
  v17.m_charbuffer = v16;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v17, &word_794320);
  if ( v12 == -2005532292 )
  {
    PlatformString::DisplayString(0x79u, v17, v18, v19, v20);
    (*(void (__thiscall **)(RenderDeviceD3D *))&v4->vfptr->gap4[4])(v4);
    result = 0;
  }
  else
  {
    PlatformString::DisplayString(0x69u, v17, v18, v19, v20);
    (*(void (__thiscall **)(RenderDeviceD3D *))&v4->vfptr->gap4[4])(v4);
    result = 0;
  }
  return result;
}

//----- (0070BEF0) --------------------------------------------------------  // acclient.c:798980
int sub_70BEF0()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_36, "Display.Resolution");
  return atexit(_E74_87);
}

//----- (0070BF10) --------------------------------------------------------  // acclient.c:798987
int _E76_71()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_36, "Display.FullScreen");
  return atexit(sub_7761A0);
}

//----- (0070BF30) --------------------------------------------------------  // acclient.c:798994
int _E79_65()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_36, "Display.RefreshRate");
  return atexit(_E80_64);
}

//----- (0070BF50) --------------------------------------------------------  // acclient.c:799001
int _E82_43()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_36, "Display.SyncToRefresh");
  return atexit(_E83_41);
}

//----- (0070BF70) --------------------------------------------------------  // acclient.c:799008
void _E101_39()
{
  LODWORD(dword_8ED3F4) = 1053364187;
}

//----- (0070BF80) --------------------------------------------------------  // acclient.c:799014
void sub_70BF80()
{
  flt_8ED3F8 = 1000.0 + 1.0;
}

//----- (0070BFA0) --------------------------------------------------------  // acclient.c:799020
void _E105_52()
{
  flt_8ED3FC = 24.0 * 8.0;
}

//----- (0070BFC0) --------------------------------------------------------  // acclient.c:799026
void _E107_43()
{
  flt_8ED400 = 24.0 * 0.5;
}

//----- (0070BFE0) --------------------------------------------------------  // acclient.c:799032
void _E109_79()
{
  dword_8ED408 = 1024;
}

//----- (0070BFF0) --------------------------------------------------------  // acclient.c:799038
void _E111_55()
{
  dword_8ED40C = 0x7FFF;
}

//----- (0070C000) --------------------------------------------------------  // acclient.c:799044
int _E113_30()
{
  const int result; // eax@1

  result = dword_8ED408;
  dword_8ED410 = dword_8ED408;
  return result;
}

//----- (0070C010) --------------------------------------------------------  // acclient.c:799054
void _E115_85()
{
  flt_8ED414 = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070C030) --------------------------------------------------------  // acclient.c:799060
void _E117_80()
{
  dbl_8ED418 = 1.0 / 30.0;
}

//----- (0070C050) --------------------------------------------------------  // acclient.c:799066
void _E119_31()
{
  dbl_8ED420 = 1.0 / 5.0;
}

//----- (0070C070) --------------------------------------------------------  // acclient.c:799072
int _E121_71()
{
  return atexit(_E122_98);
}

//----- (0070C080) --------------------------------------------------------  // acclient.c:799078
int _E124_70()
{
  return atexit(_E125_67);
}

//----- (0070C090) --------------------------------------------------------  // acclient.c:799084
int _E127_59()
{
  return atexit(_E128_65);
}

//----- (0070C0A0) --------------------------------------------------------  // acclient.c:799090
void _E130_53()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8ED428, PFID_A8R8G8B8);
}

//----- (0070C0B0) --------------------------------------------------------  // acclient.c:799096
int _E132_46()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_39, "Render.TextureFiltering");
  return atexit(sub_775B40);
}

//----- (0070C0D0) --------------------------------------------------------  // acclient.c:799103
int _E135_53()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_39, "Render.LandscapeDetailTextures");
  return atexit(_E136_88);
}

//----- (0070C0F0) --------------------------------------------------------  // acclient.c:799110
int _E138_41()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_39, "Render.BuildingDetailTextures");
  return atexit(_E139_88);
}

//----- (0070C110) --------------------------------------------------------  // acclient.c:799117
int _E141_43()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_39, "Render.FieldOfView");
  return atexit(_E142_83);
}

//----- (0070C130) --------------------------------------------------------  // acclient.c:799124
int _E144_40()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_39, "Render.LandscapeTextureDetail");
  return atexit(_E145_85);
}

//----- (0070C150) --------------------------------------------------------  // acclient.c:799131
int _E147_39()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_39, "Render.EnvironmentTextureDetail");
  return atexit(_E148_81);
}

//----- (0070C170) --------------------------------------------------------  // acclient.c:799138
int _E150_38()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_39, "Render.SceneryDrawDistance");
  return atexit(_E151_79);
}

//----- (0070C190) --------------------------------------------------------  // acclient.c:799145
int _E153_36()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_39, "Render.LandscapeDrawDistance");
  return atexit(_E154_80);
}

//----- (0070C1B0) --------------------------------------------------------  // acclient.c:799152
int _E156_38()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_39, "Render.ScreenBrightness");
  return atexit(_E157_76);
}

//----- (0070C1D0) --------------------------------------------------------  // acclient.c:799159
int _E159_36()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_39, "Render.AspectRatio");
  return atexit(_E160_79);
}

//----- (0070C1F0) --------------------------------------------------------  // acclient.c:799166
int _E162_39()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_39, "Render.DisplayAdapter");
  return atexit(_E163_72);
}

//----- (0070C210) --------------------------------------------------------  // acclient.c:799173
int _E165_34()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_39, "Render.MaxHardwareClass");
  return atexit(_E166_74);
}

//----- (0070C230) --------------------------------------------------------  // acclient.c:799180
int _E168_35()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_39, "Render.AutomaticDegrades");
  return atexit(_E169_73);
}

//----- (0070C250) --------------------------------------------------------  // acclient.c:799187
int _E171_34()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_39, "Render.GraphicsPerformance");
  return atexit(_E172_71);
}

//----- (0070C270) --------------------------------------------------------  // acclient.c:799194
int _E174_36()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_39, "Render.DegradeDistance");
  return atexit(_E175_68);
}

//----- (0070C290) --------------------------------------------------------  // acclient.c:799201
int _E177_33()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_39, "Render.MultiPassAlpha");
  return atexit(_E178_68);
}

//----- (0070C2B0) --------------------------------------------------------  // acclient.c:799208
int _E180_33()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_39, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED4A4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED4A8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8ED4AC, "Anisotropic");
  return atexit(_E181_68);
}

//----- (0070C300) --------------------------------------------------------  // acclient.c:799218
int _E183_32()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_39, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED4B4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED4B8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED4BC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED4C0, "VeryHigh");
  return atexit(_E184_65);
}

//----- (0070C360) --------------------------------------------------------  // acclient.c:799229
int _E186_32()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_39, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED4C8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED4CC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED4D0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED4D4, "VeryHigh");
  return atexit(_E187_64);
}

//----- (0070C3C0) --------------------------------------------------------  // acclient.c:799240
int _E189_31()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_39, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED4DC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED4E0, "High");
  return atexit(_E190_65);
}

//----- (0070C400) --------------------------------------------------------  // acclient.c:799249
int _E192_26()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_39, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED4E8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED4EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED4F0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED4F4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8ED4F8, "Extreme");
  return atexit(_E193_52);
}

//----- (0070C470) --------------------------------------------------------  // acclient.c:799261
int _E195_18()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_39, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8ED500, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8ED504, "Wide");
  return atexit(_E196_59);
}

//----- (0070C4B0) --------------------------------------------------------  // acclient.c:799270
int _E198_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_66, "None");
  return atexit(_E199_51);
}

//----- (0070C4D0) --------------------------------------------------------  // acclient.c:799277
int _E201_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_66, "Speed");
  return atexit(_E202_52);
}

//----- (0070C4F0) --------------------------------------------------------  // acclient.c:799284
int _E204_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_66, "Noise");
  return atexit(_E205_44);
}

//----- (0070C510) --------------------------------------------------------  // acclient.c:799291
int _E207_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_66, "Sine");
  return atexit(_E208_48);
}

//----- (0070C530) --------------------------------------------------------  // acclient.c:799298
int _E210_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_66, "Square");
  return atexit(_E211_44);
}

//----- (0070C550) --------------------------------------------------------  // acclient.c:799305
int _E213_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_66, "Bounce");
  return atexit(_E214_46);
}

//----- (0070C570) --------------------------------------------------------  // acclient.c:799312
int _E216_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_66, "Perlin");
  return atexit(_E217_42);
}

//----- (0070C590) --------------------------------------------------------  // acclient.c:799319
int _E219_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_66, "Fractal");
  return atexit(_E220_41);
}

//----- (0070C5B0) --------------------------------------------------------  // acclient.c:799326
int _E222_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_66, "FrameLoop");
  return atexit(_E223_41);
}

//----- (0070C5D0) --------------------------------------------------------  // acclient.c:799333
int sub_70C5D0()
{
  return atexit(nullsub_1447);
}

//----- (00775B40) --------------------------------------------------------  // acclient.c:909362
void __cdecl sub_775B40()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775B70) --------------------------------------------------------  // acclient.c:909375
void __cdecl _E136_88()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775BA0) --------------------------------------------------------  // acclient.c:909388
void __cdecl _E139_88()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775BD0) --------------------------------------------------------  // acclient.c:909401
void __cdecl _E142_83()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775C00) --------------------------------------------------------  // acclient.c:909414
void __cdecl _E145_85()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775C30) --------------------------------------------------------  // acclient.c:909427
void __cdecl _E148_81()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775C60) --------------------------------------------------------  // acclient.c:909440
void __cdecl _E151_79()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775C90) --------------------------------------------------------  // acclient.c:909453
void __cdecl _E154_80()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775CC0) --------------------------------------------------------  // acclient.c:909466
void __cdecl _E157_76()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775CF0) --------------------------------------------------------  // acclient.c:909479
void __cdecl _E160_79()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775D20) --------------------------------------------------------  // acclient.c:909492
void __cdecl _E163_72()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775D50) --------------------------------------------------------  // acclient.c:909505
void __cdecl _E166_74()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775D80) --------------------------------------------------------  // acclient.c:909518
void __cdecl _E169_73()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775DB0) --------------------------------------------------------  // acclient.c:909531
void __cdecl _E172_71()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775DE0) --------------------------------------------------------  // acclient.c:909544
void __cdecl _E175_68()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775E10) --------------------------------------------------------  // acclient.c:909557
void __cdecl _E178_68()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775E40) --------------------------------------------------------  // acclient.c:909570
void __cdecl _E181_68()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_39;
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

//----- (00775E80) --------------------------------------------------------  // acclient.c:909595
void __cdecl _E184_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_39;
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

//----- (00775EC0) --------------------------------------------------------  // acclient.c:909620
void __cdecl _E187_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_39;
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

//----- (00775F00) --------------------------------------------------------  // acclient.c:909645
void __cdecl _E190_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_39;
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

//----- (00775F40) --------------------------------------------------------  // acclient.c:909670
void __cdecl _E193_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_39;
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

//----- (00775F80) --------------------------------------------------------  // acclient.c:909695
void __cdecl _E196_59()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_66;
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

//----- (00775FC0) --------------------------------------------------------  // acclient.c:909720
void __cdecl _E199_51()
{
  char *v0; // esi@1

  v0 = &waveform_None_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775FF0) --------------------------------------------------------  // acclient.c:909733
void __cdecl _E202_52()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776020) --------------------------------------------------------  // acclient.c:909746
void __cdecl _E205_44()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776050) --------------------------------------------------------  // acclient.c:909759
void __cdecl _E208_48()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776080) --------------------------------------------------------  // acclient.c:909772
void __cdecl _E211_44()
{
  char *v0; // esi@1

  v0 = &waveform_Square_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007760B0) --------------------------------------------------------  // acclient.c:909785
void __cdecl _E214_46()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007760E0) --------------------------------------------------------  // acclient.c:909798
void __cdecl _E217_42()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776110) --------------------------------------------------------  // acclient.c:909811
void __cdecl _E220_41()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776140) --------------------------------------------------------  // acclient.c:909824
void __cdecl _E223_41()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776170) --------------------------------------------------------  // acclient.c:909837
void __cdecl _E74_87()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007761A0) --------------------------------------------------------  // acclient.c:909850
void __cdecl sub_7761A0()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007761D0) --------------------------------------------------------  // acclient.c:909863
void __cdecl _E80_64()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776200) --------------------------------------------------------  // acclient.c:909876
void __cdecl _E83_41()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

