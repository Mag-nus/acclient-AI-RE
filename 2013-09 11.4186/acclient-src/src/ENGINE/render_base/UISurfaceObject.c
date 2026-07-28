/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UISurfaceObject
   Object     : ENGINE\render_base\UISurfaceObject.obj
   Functions  : 46
   Addresses  : 00693F30 - 00784960 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00693F30) --------------------------------------------------------  // acclient.c:683934
void __thiscall UISurfaceObject::SetTransform(UISurfaceObject *this, Matrix4 *_transform)
{
  qmemcpy(&this->m_transform, _transform, sizeof(this->m_transform));
  Matrix4::Inverse(&this->m_invTransform, &this->m_transform);
}

//----- (00693F60) --------------------------------------------------------  // acclient.c:683941
void __thiscall UISurfaceObject::InqRotateVals(UISurfaceObject *this, int *rx, int *ry, int *rz)
{
  *rx = this->m_virtualXRot;
  *ry = this->m_virtualYRot;
  *rz = this->m_virtualZRot;
}

//----- (00693F90) --------------------------------------------------------  // acclient.c:683949
char __thiscall UISurfaceObject::SetPhysicalSize(UISurfaceObject *this, const unsigned int i_width, const unsigned int i_height)
{
  UISurface *v3; // ecx@1
  char result; // al@2

  v3 = this->m_surface;
  if ( v3 )
    result = UISurface::Resize(v3, i_width, i_height);
  else
    result = 0;
  return result;
}

//----- (00693FB0) --------------------------------------------------------  // acclient.c:683963
char __thiscall UISurfaceObject::GetPhysicalSize(UISurfaceObject *this, unsigned int *o_nWidth, unsigned int *o_nHeight)
{
  UISurface *v3; // eax@1
  char result; // al@2

  v3 = this->m_surface;
  if ( v3 )
  {
    *o_nWidth = v3->m_nPhysicalWidth;
    *o_nHeight = this->m_surface->m_nPhysicalHeight;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00693FE0) --------------------------------------------------------  // acclient.c:683983
void __thiscall UISurfaceObject::ObjectToUISurface(UISurfaceObject *this, const float *i_fObjX, const float *i_fObjY, int *o_nSurfX, int *o_nSurfY)
{
  UISurface *v5; // eax@1

  v5 = this->m_surface;
  if ( v5 )
  {
    *o_nSurfX = (unsigned __int64)((*i_fObjX + 0.5) * (double)v5->m_nPhysicalWidth);
    *o_nSurfY = (unsigned __int64)((double)this->m_surface->m_nPhysicalHeight * (0.5 - *i_fObjY));
  }
}

//----- (00694050) --------------------------------------------------------  // acclient.c:683996
void __thiscall UISurfaceObject::SetSurface(UISurfaceObject *this, UISurface *_surface, const bool i_bTile)
{
  UISurfaceObject *v3; // esi@1
  UISurface *v4; // ecx@1
  bool v5; // zf@2
  RenderMaterial *v6; // eax@5
  UISurface *v7; // eax@7

  v3 = this;
  ++_surface->m_cRef;
  v4 = this->m_surface;
  if ( v4 )
  {
    v5 = v4->m_cRef-- == 1;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_surface = 0;
  }
  v6 = v3->m_material;
  v3->m_surface = _surface;
  v3->m_bTile = i_bTile;
  if ( !v6 )
    v3->vfptr[15].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v3, stru_8F86BC.id);
  v7 = v3->m_surface;
  if ( v7 )
  {
    v3->m_nVirtualWidth = v7->m_nPhysicalWidth;
    v3->m_nVirtualHeight = v7->m_nPhysicalHeight;
  }
}

//----- (006940C0) --------------------------------------------------------  // acclient.c:684028
void __thiscall UISurfaceObject::SetMaterialColor(UISurfaceObject *this, RGBAColor *_Color)
{
  RenderMaterial *v2; // eax@1
  MaterialLayer *v3; // eax@3
  float v4; // edx@3
  float v5; // esi@3
  float cNew_12; // ST14_4@3
  float v7; // edi@3

  v2 = this->m_material;
  if ( v2 )
  {
    if ( v2->m_DID.id == stru_8F86BC.id )
    {
      v3 = *v2->layers.m_data;
      v4 = _Color->g;
      v5 = _Color->b;
      cNew_12 = _Color->a;
      v7 = v3->m_cDiffuse.a;
      v3 = (MaterialLayer *)((char *)v3 + 124);
      v3->m_Options = LODWORD(_Color->r);
      *(float *)&v3->m_TrueFlags = v4;
      *(float *)&v3->m_FalseFlags = v5;
      *(float *)&v3->m_RenderPass = v7;
    }
  }
}

//----- (00694120) --------------------------------------------------------  // acclient.c:684057
void __thiscall UISurfaceObject::SetMaterialOpacity(UISurfaceObject *this, const float _fOpacity)
{
  RenderMaterial *v2; // eax@1
  MaterialLayer *v3; // eax@3
  float v4; // edx@3
  float v5; // esi@3
  float v6; // edi@3
  float v7; // ebx@3

  v2 = this->m_material;
  if ( v2 )
  {
    if ( v2->m_DID.id == stru_8F86BC.id )
    {
      v3 = *v2->layers.m_data;
      v4 = v3->m_cDiffuse.r;
      v5 = v3->m_cDiffuse.g;
      v6 = v3->m_cDiffuse.b;
      v7 = v3->m_cDiffuse.a;
      v3 = (MaterialLayer *)((char *)v3 + 124);
      *(float *)&v3->m_Options = v4;
      *(float *)&v3->m_TrueFlags = v5;
      *(float *)&v3->m_FalseFlags = v6;
      *(const float *)&v3->m_RenderPass = _fOpacity;
      this->m_opacity = _fOpacity;
    }
  }
}

//----- (00694180) --------------------------------------------------------  // acclient.c:684087
void __thiscall UISurfaceObject::SetMaterialAlphaEnable(UISurfaceObject *this, const bool _Enable)
{
  RenderMaterial *v2; // edx@1
  UISurface *v3; // eax@3
  signed int v4; // eax@5

  v2 = this->m_material;
  if ( v2 )
  {
    if ( v2->m_DID.id == stru_8F86BC.id )
    {
      v3 = this->m_surface;
      if ( v3 )
      {
        if ( !v3->m_bHasAlpha || (v4 = 4, !_Enable) )
          v4 = 3;
        (*(*v2->layers.m_data)->m_Stages.m_data)->m_FFAlphaOp = v4;
      }
    }
  }
}

//----- (006941D0) --------------------------------------------------------  // acclient.c:684110
void __thiscall UISurfaceObject::SetMaterialFiltering(UISurfaceObject *this, const bool _bFiltering)
{
  RenderMaterial *v2; // edx@1
  TexFilterMode v3; // eax@3

  v2 = this->m_material;
  if ( v2 )
  {
    if ( v2->m_DID.id == stru_8F86BC.id )
    {
      v3 = (_bFiltering != 0) + 1;
      (*(*v2->layers.m_data)->m_Stages.m_data)->m_MinFilterMode = v3;
      (*(*this->m_material->layers.m_data)->m_Stages.m_data)->m_MagFilterMode = v3;
    }
  }
}

//----- (00694220) --------------------------------------------------------  // acclient.c:684128
void __thiscall UISurfaceObject::Render(UISurfaceObject *this)
{
  UISurfaceObject *v1; // edi@1
  UISurface *v2; // esi@1
  UISurface *v3; // esi@2
  LayerStage *v4; // ebx@2
  RenderIndexBuffer *v5; // esi@2
  unsigned int v6; // ebx@2
  unsigned int v7; // ebp@2
  Matrix4 mIdentity; // [sp+8h] [bp-40h]@2

  v1 = this;
  v2 = this->m_surface;
  UISurface::RefreshHardware(this->m_surface);
  if ( v2->m_pRemoteTexture )
  {
    SceneTool::StoreMatrices();
    LODWORD(mIdentity._14) = 0;
    LODWORD(mIdentity._13) = 0;
    LODWORD(mIdentity._12) = 0;
    LODWORD(mIdentity._24) = 0;
    LODWORD(mIdentity._23) = 0;
    LODWORD(mIdentity._21) = 0;
    LODWORD(mIdentity._34) = 0;
    LODWORD(mIdentity._32) = 0;
    LODWORD(mIdentity._31) = 0;
    LODWORD(mIdentity._43) = 0;
    LODWORD(mIdentity._42) = 0;
    LODWORD(mIdentity._41) = 0;
    LODWORD(mIdentity._44) = 1065353216;
    LODWORD(mIdentity._33) = 1065353216;
    LODWORD(mIdentity._22) = 1065353216;
    LODWORD(mIdentity._11) = 1065353216;
    RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &v1->m_transform);
    RenderDeviceD3D::SetWorldToViewMatrix((RenderDeviceD3D *)RenderDevice::render_device, &mIdentity);
    RenderDeviceD3D::SetViewToClipMatrix((RenderDeviceD3D *)RenderDevice::render_device, &mIdentity);
    v3 = v1->m_surface;
    v4 = *(*v1->m_material->layers.m_data)->m_Stages.m_data;
    UISurface::RefreshHardware(v1->m_surface);
    LayerStage::SetTexture(v4, v3->m_pRemoteTexture);
    RenderDeviceD3D::SetMultiSampleAntialias((RenderDeviceD3D *)RenderDevice::render_device, 0);
    v5 = RenderUI::s_pUISurfaceIB;
    RenderIndexBuffer::RecalculateMinMaxIndices(RenderUI::s_pUISurfaceIB);
    v6 = v5->m_nMaxVertexIndex;
    RenderIndexBuffer::RecalculateMinMaxIndices(v5);
    v7 = v5->m_nMinVertexIndex;
    RenderIndexBuffer::RecalculateMinMaxIndices(v5);
    RenderVertexBuffer::RenderIndexedUsingMaterial(
      v1->m_surface->m_pVertexBuffer,
      PRIMTYPE_TRIANGLELIST,
      0,
      v5->m_nNumIndices / 3,
      v5->m_nMinVertexIndex,
      v6 - v7 + 1,
      0,
      v5,
      v1->m_material,
      v1->m_material,
      0,
      &cColor,
      &stru_834548,
      0,
      1,
      0,
      0,
      0);
    RenderDeviceD3D::SetMultiSampleAntialias((RenderDeviceD3D *)RenderDevice::render_device, 1);
    SceneTool::RestoreMatrices();
  }
}

//----- (006943B0) --------------------------------------------------------  // acclient.c:684200
void __thiscall UISurfaceObject::UpdateTransform(UISurfaceObject *this)
{
  UISurfaceObject *v1; // esi@1
  float v2; // ST14_4@1
  double v3; // st7@1
  float fUScale; // ST18_4@1
  float v5; // ST14_4@1
  unsigned int v6; // ST1C_4@1
  float v7; // ST14_4@1
  RenderMaterial *v8; // eax@3
  unsigned int v9; // ebp@4
  MaterialLayer *v10; // edi@5
  LM_UVScale *v11; // ebx@6
  float v12; // ST18_4@6
  Waveform *v13; // eax@6
  Waveform *v14; // eax@6
  signed int v15; // eax@6
  signed int v16; // eax@8
  UISurface *v17; // eax@12
  bool v18; // al@15
  float fVScale; // [sp+4h] [bp-114h]@6
  float clipX; // [sp+10h] [bp-108h]@1
  float clipY; // [sp+14h] [bp-104h]@1
  Matrix4 b; // [sp+18h] [bp-100h]@1
  Matrix4 uiPosSize; // [sp+58h] [bp-C0h]@1
  Matrix4 offset; // [sp+98h] [bp-80h]@1
  Matrix4 rotPosSize; // [sp+D8h] [bp-40h]@1

  v1 = this;
  SurfaceWindow::WindowToClip(
    &RenderDevice::render_device->m_pFrameBufferSurface->window,
    this->m_nVirtualX,
    this->m_nVirtualY + this->m_nVirtualHeight - 1,
    &clipX,
    &clipY);
  v2 = (double)v1->m_nVirtualWidth - 0.25;
  v3 = (double)RenderDevice::GetDisplayWidth(RenderDevice::render_device);
  fUScale = v2 / v3 + v2 / v3;
  v5 = (double)v1->m_nVirtualHeight - 0.25;
  v6 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
  v7 = v5 / (double)v6 + v5 / (double)v6;
  Matrix4::Translate(&offset, 0.5, 0.5, 0.0);
  b._11 = fUScale;
  b._22 = v7;
  b._41 = clipX;
  b._42 = clipY;
  LODWORD(b._14) = 0;
  LODWORD(b._13) = 0;
  LODWORD(b._12) = 0;
  LODWORD(b._24) = 0;
  LODWORD(b._23) = 0;
  LODWORD(b._21) = 0;
  LODWORD(b._34) = 0;
  LODWORD(b._32) = 0;
  LODWORD(b._31) = 0;
  LODWORD(b._43) = 0;
  LODWORD(b._44) = 1065353216;
  LODWORD(b._33) = 1065353216;
  Matrix4::Multiply_C(&uiPosSize, &offset, &b);
  Matrix4::Multiply_C(&rotPosSize, &v1->m_rotMatrix, &uiPosSize);
  v1->vfptr[13].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v1, (unsigned int)&rotPosSize);
  if ( v1->m_bTile )
  {
    if ( v1->m_surface )
    {
      v8 = v1->m_material;
      if ( v8 )
      {
        v9 = 0;
        if ( v8->layers.m_num )
        {
          do
          {
            v10 = v8->layers.m_data[v9];
            if ( v10->m_FFModifiers.m_num )
            {
              v11 = (LM_UVScale *)*v10->m_FFModifiers.m_data;
              v12 = (double)v1->m_nVirtualWidth / (double)v1->m_surface->m_nPhysicalWidth;
              Waveform::Waveform((Waveform *)&uiPosSize, v12);
              LM_UVTranslate::SetUTranslate(v11, v13);
              fVScale = (double)v1->m_nVirtualHeight / (double)v1->m_surface->m_nPhysicalHeight;
              Waveform::Waveform((Waveform *)&b, fVScale);
              LM_UVTranslate::SetVTranslate(v11, v14);
              v15 = 3;
              if ( fabs(fabs(v12) - 1.0) > 0.00019999999 )
                v15 = 1;
              (*v10->m_Stages.m_data)->m_AddressModeU = v15;
              v16 = 3;
              if ( fabs(fabs(fVScale) - 1.0) > 0.00019999999 )
                v16 = 1;
              (*v10->m_Stages.m_data)->m_AddressModeV = v16;
            }
            v8 = v1->m_material;
            ++v9;
          }
          while ( v9 < v8->layers.m_num );
        }
      }
    }
  }
  v17 = v1->m_surface;
  v18 = v1->m_nVirtualWidth != v17->m_nPhysicalWidth
     || v1->m_nVirtualHeight != v17->m_nPhysicalHeight
     || !(unsigned __int8)Matrix4::AreEqual(&v1->m_rotMatrix, &Matrix4_IdentityMatrix___36);
  if ( v1->m_surface )
  {
    if ( v18 )
      v1->vfptr[20].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v1, 1u);
    else
      v1->vfptr[20].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v1, 0);
  }
}

//----- (006946F0) --------------------------------------------------------  // acclient.c:684314
void __thiscall UISurfaceObject::ClipToUISurface(UISurfaceObject *this, const float *i_fClipX, const float *i_fClipY, int *o_nSurfX, int *o_nSurfY)
{
  UISurfaceObject *v5; // esi@1
  float v6; // eax@1
  Vector3 point; // [sp+4h] [bp-18h]@1
  Vector3 objSpacePoint; // [sp+10h] [bp-Ch]@1

  v5 = this;
  v6 = *i_fClipY;
  LODWORD(point.x) = *(_DWORD *)i_fClipX;
  point.y = v6;
  LODWORD(point.z) = 0;
  Matrix4::TransformVector_C(&this->m_invTransform, &point, &objSpacePoint);
  UISurfaceObject::ObjectToUISurface(v5, &objSpacePoint.x, &objSpacePoint.y, o_nSurfX, o_nSurfY);
}

//----- (006947A0) --------------------------------------------------------  // acclient.c:684348
void __thiscall UISurfaceObject::UISurfaceObject(UISurfaceObject *this)
{
  UISurfaceObject *v1; // esi@1

  v1 = this;
  UIObject::UIObject((UIObject *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UISurfaceObject::vftable;
  v1->m_surface = 0;
  v1->m_material = 0;
  v1->m_bTile = 0;
  v1->m_virtualXRot = 0;
  v1->m_virtualYRot = 0;
  v1->m_virtualZRot = 0;
  LODWORD(v1->m_opacity) = 1065353216;
  LODWORD(v1->m_transform._14) = 0;
  LODWORD(v1->m_transform._13) = 0;
  LODWORD(v1->m_transform._12) = 0;
  LODWORD(v1->m_transform._24) = 0;
  LODWORD(v1->m_transform._23) = 0;
  LODWORD(v1->m_transform._21) = 0;
  LODWORD(v1->m_transform._34) = 0;
  LODWORD(v1->m_transform._32) = 0;
  LODWORD(v1->m_transform._31) = 0;
  LODWORD(v1->m_transform._43) = 0;
  LODWORD(v1->m_transform._42) = 0;
  LODWORD(v1->m_transform._41) = 0;
  LODWORD(v1->m_transform._44) = 1065353216;
  LODWORD(v1->m_transform._33) = 1065353216;
  LODWORD(v1->m_transform._22) = 1065353216;
  LODWORD(v1->m_transform._11) = 1065353216;
  LODWORD(v1->m_invTransform._14) = 0;
  LODWORD(v1->m_invTransform._13) = 0;
  LODWORD(v1->m_invTransform._12) = 0;
  LODWORD(v1->m_invTransform._24) = 0;
  LODWORD(v1->m_invTransform._23) = 0;
  LODWORD(v1->m_invTransform._21) = 0;
  LODWORD(v1->m_invTransform._34) = 0;
  LODWORD(v1->m_invTransform._32) = 0;
  LODWORD(v1->m_invTransform._31) = 0;
  LODWORD(v1->m_invTransform._43) = 0;
  LODWORD(v1->m_invTransform._42) = 0;
  LODWORD(v1->m_invTransform._41) = 0;
  LODWORD(v1->m_invTransform._44) = 1065353216;
  LODWORD(v1->m_invTransform._33) = 1065353216;
  LODWORD(v1->m_invTransform._22) = 1065353216;
  LODWORD(v1->m_invTransform._11) = 1065353216;
  LODWORD(v1->m_rotMatrix._14) = 0;
  LODWORD(v1->m_rotMatrix._13) = 0;
  LODWORD(v1->m_rotMatrix._12) = 0;
  LODWORD(v1->m_rotMatrix._24) = 0;
  LODWORD(v1->m_rotMatrix._23) = 0;
  LODWORD(v1->m_rotMatrix._21) = 0;
  LODWORD(v1->m_rotMatrix._34) = 0;
  LODWORD(v1->m_rotMatrix._32) = 0;
  LODWORD(v1->m_rotMatrix._31) = 0;
  LODWORD(v1->m_rotMatrix._43) = 0;
  LODWORD(v1->m_rotMatrix._42) = 0;
  LODWORD(v1->m_rotMatrix._41) = 0;
  LODWORD(v1->m_rotMatrix._44) = 1065353216;
  LODWORD(v1->m_rotMatrix._33) = 1065353216;
  LODWORD(v1->m_rotMatrix._22) = 1065353216;
  LODWORD(v1->m_rotMatrix._11) = 1065353216;
}
// 8006B0: using guessed type int (__thiscall *UISurfaceObject::vftable)(void *, char);

//----- (006948E0) --------------------------------------------------------  // acclient.c:684414
double __thiscall UISurfaceObject::GetMaterialOpacity(UISurfaceObject *this)
{
  return this->m_opacity;
}

//----- (00694900) --------------------------------------------------------  // acclient.c:684420
void __thiscall UISurfaceObject::~UISurfaceObject(UISurfaceObject *this)
{
  UISurfaceObject *v1; // esi@1
  UISurface *v2; // ecx@1
  bool v3; // zf@2
  RenderMaterial *v4; // ecx@5

  v1 = this;
  v2 = this->m_surface;
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UISurfaceObject::vftable;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_surface = 0;
  }
  v4 = v1->m_material;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v1->m_material = 0;
  }
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UIObject::vftable;
  if ( (v1->m_dirtyRects.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_dirtyRects.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 800678: using guessed type int (__thiscall *UIObject::vftable)(void *, char);
// 8006B0: using guessed type int (__thiscall *UISurfaceObject::vftable)(void *, char);

//----- (00694970) --------------------------------------------------------  // acclient.c:684453
void __thiscall UISurfaceObject::SetRotateVals(UISurfaceObject *this, int rx, int ry, int rz)
{
  UISurfaceObject *v4; // esi@1
  float radians; // ST04_4@1
  float v6; // ST04_4@1
  float v7; // ST04_4@1
  Matrix4 rxMatrix; // [sp+14h] [bp-100h]@1
  Matrix4 rzMatrix; // [sp+54h] [bp-C0h]@1
  Matrix4 ryMatrix; // [sp+94h] [bp-80h]@1
  Matrix4 rxyMatrix; // [sp+D4h] [bp-40h]@1

  v4 = this;
  this->m_virtualXRot = rx;
  this->m_virtualYRot = ry;
  this->m_virtualZRot = rz;
  radians = (double)(rx % 360) * 0.017453292;
  Matrix4::RotateX(&rxMatrix, radians);
  v6 = (double)(ry % 360) * 0.017453292;
  Matrix4::RotateY(&ryMatrix, v6);
  v7 = (double)(rz % 360) * 0.017453292;
  Matrix4::RotateZ(&rzMatrix, v7);
  Matrix4::Multiply_C(&rxyMatrix, &rxMatrix, &ryMatrix);
  Matrix4::Multiply_C(&v4->m_rotMatrix, &rxyMatrix, &rzMatrix);
  UISurfaceObject::UpdateTransform(v4);
}

//----- (00694A60) --------------------------------------------------------  // acclient.c:684480
void __thiscall UISurfaceObject::SetVirtualScreenPosition(UISurfaceObject *this, const unsigned int i_x, const unsigned int i_y, const unsigned int i_width, const unsigned int i_height)
{
  UISurfaceObject *v5; // esi@1

  v5 = this;
  UIObject::SetVirtualScreenPosition((UIObject *)&this->vfptr, i_x, i_y, i_width, i_height);
  UISurfaceObject::UpdateTransform(v5);
}

//----- (00694A90) --------------------------------------------------------  // acclient.c:684490
UISurfaceObject *__thiscall UISurfaceObject::vector_deleting_destructor(UISurfaceObject *this, unsigned int a2)
{
  UISurfaceObject *v2; // esi@1

  v2 = this;
  UISurfaceObject::~UISurfaceObject(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00694AB0) --------------------------------------------------------  // acclient.c:684502
bool __thiscall UISurfaceObject::RayTest(UISurfaceObject *this, const unsigned int *i_nScreenX, const unsigned int *i_nScreenY)
{
  UISurfaceObject *v3; // esi@1
  UISurface *v4; // edi@1
  bool result; // al@6
  int dummyX; // [sp+8h] [bp-8h]@2
  int dummyY; // [sp+Ch] [bp-4h]@2

  v3 = this;
  SurfaceWindow::WindowToClip(
    &RenderDevice::render_device->m_pFrameBufferSurface->window,
    *i_nScreenX,
    *i_nScreenY,
    (float *)&i_nScreenX,
    (float *)&i_nScreenY);
  v4 = v3->m_surface;
  result = 0;
  if ( v4 )
  {
    UISurfaceObject::ClipToUISurface(v3, (const float *)&i_nScreenX, (const float *)&i_nScreenY, &dummyX, &dummyY);
    if ( dummyX >= 0
      && dummyY >= 0
      && dummyX <= (signed int)v4->m_nPhysicalWidth
      && dummyY <= (signed int)v4->m_nPhysicalHeight )
      result = 1;
  }
  return result;
}

//----- (00694B40) --------------------------------------------------------  // acclient.c:684532
RenderMaterial *__thiscall UISurfaceObject::GenerateMaterial(UISurfaceObject *this)
{
  UISurfaceObject *v1; // ebp@1
  RenderMaterial *v2; // eax@1
  RenderMaterial *v3; // eax@2
  MaterialLayer *v4; // eax@4
  float v5; // eax@5
  float v6; // edi@5
  LayerStage *v7; // eax@7
  float v8; // eax@8
  float v9; // esi@8
  int v10; // eax@13
  int v11; // eax@13
  UISurface *v12; // eax@13
  unsigned int v13; // ST04_4@16
  LM_UVScale *v14; // eax@18
  float v15; // eax@19
  float v16; // ebx@19
  float fUScale; // ST1C_4@20
  Waveform *v18; // eax@20
  Waveform *v19; // eax@20
  signed int v20; // eax@20
  long double v21; // st7@22
  signed int v22; // eax@22
  unsigned int v23; // ST04_4@25
  RenderMaterial *pMaterial; // [sp+10h] [bp-38h]@2
  float fVScale; // [sp+18h] [bp-30h]@16
  Waveform v27; // [sp+1Ch] [bp-2Ch]@20

  v1 = this;
  v2 = (RenderMaterial *)operator new(0x4E0u);
  if ( v2 )
  {
    RenderMaterial::RenderMaterial(v2);
    pMaterial = v3;
  }
  else
  {
    pMaterial = 0;
  }
  v4 = (MaterialLayer *)operator new(0xD8u);
  if ( v4 )
  {
    MaterialLayer::MaterialLayer(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0.0;
  }
  v7 = (LayerStage *)operator new(0x48u);
  if ( v7 )
  {
    LayerStage::LayerStage(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0.0;
  }
  if ( pMaterial && v6 != 0.0 && v9 != 0.0 )
  {
    v10 = v1->m_bTile == 0;
    *(_DWORD *)(LODWORD(v9) + 28) = 1;
    *(_DWORD *)(LODWORD(v9) + 32) = 1;
    *(_DWORD *)(LODWORD(v9) + 40) = 4;
    v11 = 2 * v10 + 1;
    *(_DWORD *)(LODWORD(v9) + 20) = v11;
    *(_DWORD *)(LODWORD(v9) + 24) = v11;
    *(_DWORD *)(LODWORD(v9) + 44) = 2;
    *(_DWORD *)(LODWORD(v9) + 48) = 3;
    *(_DWORD *)(LODWORD(v9) + 52) = 3;
    *(_DWORD *)(LODWORD(v9) + 56) = 2;
    *(_DWORD *)(LODWORD(v9) + 60) = 3;
    v12 = v1->m_surface;
    if ( v12 && v12->m_bHasAlpha )
      *(_DWORD *)(LODWORD(v9) + 52) = 4;
    *(_DWORD *)(LODWORD(v6) + 72) = 1;
    *(_DWORD *)(LODWORD(v6) + 52) = 5;
    *(_DWORD *)(LODWORD(v6) + 56) = 6;
    *(_DWORD *)(LODWORD(v6) + 64) = 8;
    *(_BYTE *)(LODWORD(v6) + 68) = 0;
    *(_OWORD *)(LODWORD(v6) + 124) = cColor;
    v13 = *(_DWORD *)(LODWORD(v6) + 36);
    fVScale = v9;
    SmartArray<LayerStage *,1>::InsertOrderedByIndex(
      (SmartArray<EffectInfoRegion *,1> *)(LODWORD(v6) + 28),
      (EffectInfoRegion *const *)&fVScale,
      v13);
    if ( !v1->m_bTile || !v1->m_surface )
      goto LABEL_25;
    v14 = (LM_UVScale *)operator new(0x60u);
    if ( v14 )
    {
      LM_UVScale::LM_UVScale(v14);
      v16 = v15;
      if ( v15 != 0.0 )
      {
        *(_DWORD *)(LODWORD(v15) + 4) = 0;
        fUScale = (double)v1->m_nVirtualWidth / (double)v1->m_surface->m_nPhysicalWidth;
        Waveform::Waveform(&v27, fUScale);
        LM_UVTranslate::SetUTranslate(LODWORD(v16), v18);
        fVScale = (double)v1->m_nVirtualHeight / (double)v1->m_surface->m_nPhysicalHeight;
        Waveform::Waveform(&v27, fVScale);
        LM_UVTranslate::SetVTranslate(LODWORD(v16), v19);
        v20 = 3;
        if ( fabs(fabs(fUScale) - 1.0) > 0.00019999999 )
          v20 = 1;
        v21 = fVScale;
        *(_DWORD *)(LODWORD(v9) + 20) = v20;
        v22 = 3;
        if ( fabs(fabs(v21) - 1.0) > 0.00019999999 )
          v22 = 1;
        *(_DWORD *)(LODWORD(v9) + 24) = v22;
        fVScale = v16;
        SmartArray<LayerStage *,1>::InsertOrderedByIndex(
          (SmartArray<EffectInfoRegion *,1> *)(LODWORD(v6) + 40),
          (EffectInfoRegion *const *)&fVScale,
          0);
LABEL_25:
        v23 = pMaterial->layers.m_num;
        fVScale = v6;
        SmartArray<LayerStage *,1>::InsertOrderedByIndex(
          (SmartArray<EffectInfoRegion *,1> *)&pMaterial->layers,
          (EffectInfoRegion *const *)&fVScale,
          v23);
        RenderMaterial::Optimize(pMaterial);
        return pMaterial;
      }
    }
  }
  return 0;
}

//----- (00694DE0) --------------------------------------------------------  // acclient.c:684667
void __thiscall UISurfaceObject::SetMaterial(UISurfaceObject *this, IDClass<_tagDataID,32,0> dataID)
{
  UISurfaceObject *v2; // esi@1
  RenderMaterial *v3; // ecx@1
  QualifiedDataID *v4; // eax@5
  int v5; // eax@5
  QualifiedDataID v6; // [sp+4h] [bp-8h]@5

  v2 = this;
  v3 = this->m_material;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_material = 0;
  }
  if ( dataID.id == stru_8F86BC.id )
  {
    v2->m_material = UISurfaceObject::GenerateMaterial(v2);
  }
  else
  {
    QualifiedDataID::QualifiedDataID(&v6, dataID, 0x1Fu);
    v5 = DBObj::Get(v4);
    v2->m_material = (RenderMaterial *)v5;
    if ( !v5 )
      v2->vfptr[15].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v2, stru_8F86BC.id);
  }
}

//----- (007191A0) --------------------------------------------------------  // acclient.c:811826
void sub_7191A0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8660, PFID_A8R8G8B8);
}

//----- (007191B0) --------------------------------------------------------  // acclient.c:811832
int sub_7191B0()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_76, "None");
  return atexit(_E92_49);
}

//----- (007191D0) --------------------------------------------------------  // acclient.c:811839
int _E94_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_76, "Speed");
  return atexit(sub_784810);
}

//----- (007191F0) --------------------------------------------------------  // acclient.c:811846
int sub_7191F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_76, "Noise");
  return atexit(sub_784840);
}

//----- (00719210) --------------------------------------------------------  // acclient.c:811853
int sub_719210()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_76, "Sine");
  return atexit(sub_784870);
}

//----- (00719230) --------------------------------------------------------  // acclient.c:811860
int sub_719230()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_76, "Square");
  return atexit(sub_7848A0);
}

//----- (00719250) --------------------------------------------------------  // acclient.c:811867
int sub_719250()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_76, "Bounce");
  return atexit(sub_7848D0);
}

//----- (00719270) --------------------------------------------------------  // acclient.c:811874
int _E109_89()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_76, "Perlin");
  return atexit(sub_784900);
}

//----- (00719290) --------------------------------------------------------  // acclient.c:811881
int sub_719290()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_76, "Fractal");
  return atexit(_E113_75);
}

//----- (007192B0) --------------------------------------------------------  // acclient.c:811888
int _E115_94()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_76, "FrameLoop");
  return atexit(_E116_67);
}

//----- (007192D0) --------------------------------------------------------  // acclient.c:811895
void _E118_85()
{
  LODWORD(dword_8F86C0) = 1053364187;
}

//----- (007192E0) --------------------------------------------------------  // acclient.c:811901
void _E120_77()
{
  flt_8F86C4 = 1000.0 + 1.0;
}

//----- (00719300) --------------------------------------------------------  // acclient.c:811907
void _E122_34()
{
  flt_8F86C8 = 24.0 * 8.0;
}

//----- (00719320) --------------------------------------------------------  // acclient.c:811913
void _E124_76()
{
  flt_8F86CC = 24.0 * 0.5;
}

//----- (00719340) --------------------------------------------------------  // acclient.c:811919
int sub_719340()
{
  return atexit(nullsub_291);
}

//----- (007847E0) --------------------------------------------------------  // acclient.c:923614
void __cdecl _E92_49()
{
  char *v0; // esi@1

  v0 = &waveform_None_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784810) --------------------------------------------------------  // acclient.c:923627
void __cdecl sub_784810()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784840) --------------------------------------------------------  // acclient.c:923640
void __cdecl sub_784840()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784870) --------------------------------------------------------  // acclient.c:923653
void __cdecl sub_784870()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007848A0) --------------------------------------------------------  // acclient.c:923666
void __cdecl sub_7848A0()
{
  char *v0; // esi@1

  v0 = &waveform_Square_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007848D0) --------------------------------------------------------  // acclient.c:923679
void __cdecl sub_7848D0()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784900) --------------------------------------------------------  // acclient.c:923692
void __cdecl sub_784900()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784930) --------------------------------------------------------  // acclient.c:923705
void __cdecl _E113_75()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784960) --------------------------------------------------------  // acclient.c:923718
void __cdecl _E116_67()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

