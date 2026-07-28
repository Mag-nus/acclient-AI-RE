/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderDevice
   Object     : PORTAL\renderdev\RenderDevice.obj
   Functions  : 38
   Addresses  : 0054F0B0 - 00771C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0054F0B0) --------------------------------------------------------  // acclient.c:382317
void __thiscall RenderDevice::ReleaseSurfaceResources(RenderDevice *this)
{
  RenderDevice *v1; // esi@1
  RenderSurface *v2; // ecx@1
  RenderSurface *v3; // ecx@3
  RenderSurface *v4; // ecx@5
  RenderSurface *v5; // ecx@7

  v1 = this;
  v2 = this->m_pDepthStencilTarget;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pDepthStencilTarget = 0;
  }
  v3 = v1->m_pRenderTarget;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pRenderTarget = 0;
  }
  v4 = v1->m_pDepthStencilSurface;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v1->m_pDepthStencilSurface = 0;
  }
  v5 = v1->m_pFrameBufferSurface;
  if ( v5 )
  {
    ((void (*)(void))v5->vfptr->Release)();
    v1->m_pFrameBufferSurface = 0;
  }
}

//----- (0054F110) --------------------------------------------------------  // acclient.c:382353
unsigned int __thiscall RenderDevice::GetDisplayWidth(RenderDevice *this)
{
  return this->m_pFrameBufferSurface->width;
}

//----- (0054F120) --------------------------------------------------------  // acclient.c:382359
unsigned int __thiscall RenderDevice::GetDisplayHeight(RenderDevice *this)
{
  return this->m_pFrameBufferSurface->height;
}

//----- (0054F130) --------------------------------------------------------  // acclient.c:382365
void RenderDevice::CreateLocalSurface()
{
  RenderSurface *v1; // eax@1

  v1 = (RenderSurface *)operator new(0x120u);
  if ( v1 )
    RenderSurface::RenderSurface(v1);
}

//----- (0054F150) --------------------------------------------------------  // acclient.c:382375
double __thiscall RenderDevice::ComputeAspectForViewport(RenderDevice *this, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool _UseAutoAspect)
{
  double v6; // st7@1
  double result; // st7@4

  v6 = (double)(signed int)width;
  if ( _UseAutoAspect )
  {
    if ( (width & 0x80000000) != 0 )
      v6 = v6 + 4294967300.0;
    result = v6 / (double)height;
  }
  else
  {
    if ( (width & 0x80000000) != 0 )
      v6 = v6 + 4294967300.0;
    result = v6 / (double)height * this->m_DisplayAspectRatio * 0.75;
  }
  return result;
}

//----- (0054F1C0) --------------------------------------------------------  // acclient.c:382397
void __thiscall RenderDevice::SetViewport(RenderDevice *this, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool _UseAutoAspect)
{
  RenderDevice *v6; // esi@1
  unsigned int v7; // ecx@1
  int v8; // edi@1
  unsigned int v9; // edx@3
  int v10; // eax@3
  int v11; // ebx@5
  int v12; // ecx@7

  v6 = this;
  v7 = this->m_RenderTargetWidth;
  v8 = x;
  if ( x >= v7 )
    v8 = v7 - 1;
  v9 = v6->m_RenderTargetHeight;
  v10 = y;
  if ( y >= v9 )
    v10 = v9 - 1;
  v11 = width;
  if ( v8 + width > v7 )
    v11 = v7 - v8;
  v12 = height;
  if ( v10 + height > v9 )
    v12 = v9 - v10;
  v6->m_viewportHeight = v12;
  v6->m_viewportX = v8;
  v6->m_viewportY = v10;
  v6->m_viewportWidth = v11;
  v6->m_ViewportAspectRatio = RenderDevice::ComputeAspectForViewport(v6, v8, v10, v11, v12, _UseAutoAspect);
}

//----- (0054F240) --------------------------------------------------------  // acclient.c:382430
char __thiscall RenderDevice::Startup(RenderDevice *this, const unsigned int _nDisplayAdapter, RenderDevicePresentation *_presentation, RenderDeviceConfig *_config)
{
  this->m_config = *_config;
  qmemcpy(&this->m_presentation, _presentation, sizeof(this->m_presentation));
  return 1;
}

//----- (0054F270) --------------------------------------------------------  // acclient.c:382438
PixelFormatID __thiscall RenderDevice::GetUISurfaceFormat(RenderDevice *this)
{
  return this->m_displayInfo.pfARGBSurfaces;
}

//----- (0054F280) --------------------------------------------------------  // acclient.c:382444
void *__thiscall LIGHTINFO::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@1

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  Frame::operator=((int)((char *)this + 4), a2 + 4);
  v3 = (int)((char *)v2 + 68);
  *(_DWORD *)v3 = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(v3 + 4) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v3 + 8) = *(_DWORD *)(a2 + 76);
  v4 = (int)((char *)v2 + 80);
  *(_DWORD *)v4 = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v4 + 4) = *(_DWORD *)(a2 + 84);
  *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 88);
  *((_DWORD *)v2 + 23) = *(_DWORD *)(a2 + 92);
  *((_DWORD *)v2 + 24) = *(_DWORD *)(a2 + 96);
  *((_DWORD *)v2 + 25) = *(_DWORD *)(a2 + 100);
  return v2;
}

//----- (0054F2E0) --------------------------------------------------------  // acclient.c:382468
int __thiscall RenderLight::operator=(int this, int a2)
{
  int v2; // ebx@1

  v2 = this;
  qmemcpy((void *)this, (const void *)a2, 0x70u);
  LIGHTINFO::operator=((void *)(this + 112), a2 + 112);
  *(_DWORD *)(v2 + 216) = *(_DWORD *)(a2 + 216);
  return v2;
}

//----- (0054F330) --------------------------------------------------------  // acclient.c:382480
void __thiscall SmartArray<RenderLight,1>::Reset(SmartArray<RenderLight,1> *this)
{
  SmartArray<RenderLight,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // ebp@7
  int v6; // ebx@9
  bool v7; // zf@9
  int v8; // [sp+8h] [bp-E4h]@7
  SmartArray<RenderLight,1> *v9; // [sp+Ch] [bp-E0h]@1
  char v10; // [sp+10h] [bp-DCh]@9
  int v11; // [sp+78h] [bp-74h]@9
  int v12; // [sp+7Ch] [bp-70h]@9
  char v13; // [sp+80h] [bp-6Ch]@9
  Frame v14; // [sp+84h] [bp-68h]@9
  int v15; // [sp+E8h] [bp-4h]@9

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v9 = v1;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      operator delete[](&v1->m_data[-1].distancesq);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v8 = v4 + 1;
      while ( 1 )
      {
        LODWORD(v14.qw) = 1065353216;
        LODWORD(v14.qx) = 0;
        LODWORD(v14.qy) = 0;
        LODWORD(v14.qz) = 0;
        LODWORD(v14.m_fOrigin.x) = 0;
        LODWORD(v14.m_fOrigin.y) = 0;
        LODWORD(v14.m_fOrigin.z) = 0;
        Frame::cache(&v14);
        v6 = (int)&v1->m_data[v5];
        qmemcpy((void *)v6, &v10, 0x68u);
        *(_DWORD *)(v6 + 104) = v11;
        *(_DWORD *)(v6 + 108) = v12;
        LIGHTINFO::operator=((void *)(v6 + 112), (int)&v13);
        --v5;
        v7 = v8 == 1;
        *(_DWORD *)(v6 + 216) = v15;
        --v8;
        if ( v7 )
          break;
        v1 = v9;
      }
    }
  }
}

//----- (0054F460) --------------------------------------------------------  // acclient.c:382545
char __thiscall SmartArray<RenderLight,1>::grow(SmartArray<RenderLight,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<RenderLight,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<RenderLight,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](220 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0xDCu,
        i_nSize,
        (void *(__thiscall *)(void *))RenderLight::RenderLight);
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
              RenderLight::operator=(v8 * 220 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              operator delete[](&v3->m_data[-1].distancesq);
          }
        }
        v3->m_data = (RenderLight *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (0054F540) --------------------------------------------------------  // acclient.c:382609
void __thiscall RenderDevice::GraphicsStatesType::GraphicsStatesType(RenderDevice::GraphicsStatesType *this)
{
  qmemcpy(this, &Matrix4::NULL_MATRIX4, 0x40u);
  qmemcpy(&this->WorldToViewMatrix, &Matrix4::NULL_MATRIX4, sizeof(this->WorldToViewMatrix));
  qmemcpy(&this->ViewToClipMatrix, &Matrix4::NULL_MATRIX4, sizeof(this->ViewToClipMatrix));
  this->AmbientLight = stru_81F050;
  this->DistanceFogColor = stru_81F040;
  LODWORD(this->DistanceFogNear) = 0;
  LODWORD(this->DistantSpriteOpacityNear) = 0;
  LODWORD(this->OpacityFogNearDistance) = 0;
  this->pMPLightSource = 0;
  this->pMPLightProjectorTexture = 0;
  LODWORD(this->DistanceFogFar) = 1120403456;
  LODWORD(this->DistantSpriteOpacityRange) = 1065353216;
  LODWORD(this->OpacityFogRange) = 1065353216;
  this->FFLightSources.m_data = 0;
  this->FFLightSources.m_sizeAndDeallocate = 0;
  this->FFLightSources.m_num = 0;
  this->ChangedFFLightSources = 1;
  this->FrameBufferBloomRGBAmount = stru_81F040;
  LODWORD(this->BSVLightOriginAndExtrusionOffset.x) = 1065353216;
  LODWORD(this->BSVLightOriginAndExtrusionOffset.y) = 1065353216;
  LODWORD(this->BSVLightOriginAndExtrusionOffset.z) = 1065353216;
  LODWORD(this->BSVLightOriginAndExtrusionOffset.w) = 1065353216;
  LODWORD(this->FrameBufferViewportScaleX) = 1065353216;
  LODWORD(this->FrameBufferViewportScaleY) = 1065353216;
  LODWORD(this->FrameBufferViewportOffsetX) = 0;
  LODWORD(this->FrameBufferViewportOffsetY) = 0;
  memset(this->PixelFilterTexCoords, 0, sizeof(this->PixelFilterTexCoords));
}

//----- (0054F690) --------------------------------------------------------  // acclient.c:382641
void __thiscall RenderDevice::End(RenderDevice *this)
{
  RenderDevice *v1; // edi@1
  char *v2; // esi@1
  TextureBasedFont *v3; // ecx@4
  bool v4; // zf@5
  PStringBase<char> _Name; // [sp+0h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Name, "RenderDevice.Wireframe");
  GlobalRegistry::UnregisterVariable(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  RenderDevice::ReleaseSurfaceResources(v1);
  v3 = v1->m_pDebugFont;
  if ( v3 )
  {
    v4 = v3->m_cRef-- == 1;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->m_pDebugFont = 0;
  }
}

//----- (0054F700) --------------------------------------------------------  // acclient.c:382668
SmartArray<RenderLight,1> *__thiscall SmartArray<RenderLight,1>::operator=(SmartArray<RenderLight,1> *this, int a2)
{
  SmartArray<RenderLight,1> *v2; // esi@1
  const void *v3; // ebx@3
  void *v4; // edi@3
  int v5; // ebp@3
  int v6; // edx@4
  int v7; // eax@4
  int v8; // esi@6
  int v9; // esi@6
  int v10; // esi@6
  int v11; // ebx@8
  int v12; // ebp@9
  int v13; // eax@10
  int v14; // edx@10
  int v15; // ecx@10
  int v16; // ecx@10
  SmartArray<RenderLight,1> *v18; // [sp+8h] [bp-E4h]@1
  RenderLight *v19; // [sp+Ch] [bp-E0h]@3
  char v20; // [sp+10h] [bp-DCh]@10
  int v21; // [sp+78h] [bp-74h]@10
  int v22; // [sp+7Ch] [bp-70h]@10
  int v23; // [sp+80h] [bp-6Ch]@10
  Frame v24; // [sp+84h] [bp-68h]@10
  int v25; // [sp+C4h] [bp-28h]@10
  int v26; // [sp+C8h] [bp-24h]@10
  int v27; // [sp+CCh] [bp-20h]@10
  int v28; // [sp+D0h] [bp-1Ch]@10
  int v29; // [sp+D4h] [bp-18h]@10
  int v30; // [sp+D8h] [bp-14h]@10
  int v31; // [sp+DCh] [bp-10h]@10
  int v32; // [sp+E0h] [bp-Ch]@10
  int v33; // [sp+E4h] [bp-8h]@10
  int v34; // [sp+E8h] [bp-4h]@10

  v2 = this;
  v18 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<RenderLight,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(const void **)a2;
    v4 = v2->m_data;
    v5 = *(_DWORD *)a2 + 220 * *(_DWORD *)(a2 + 8);
    v19 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = (int)((char *)v4 + 120);
      v7 = (int)((char *)v3 + 120);
      while ( 1 )
      {
        qmemcpy(v4, v3, 0x68u);
        *(_DWORD *)(v6 - 16) = *(_DWORD *)(v7 - 16);
        *(_DWORD *)(v6 - 12) = *(_DWORD *)(v7 - 12);
        *(_DWORD *)(v6 - 8) = *(_DWORD *)(v7 - 8);
        v8 = v6 + 48;
        *(_DWORD *)v8 = *(_DWORD *)(v7 + 48);
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(v7 + 52);
        *(_DWORD *)(v8 + 8) = *(_DWORD *)(v7 + 56);
        *(_DWORD *)(v6 - 4) = *(_DWORD *)(v7 - 4);
        *(_DWORD *)v6 = *(_DWORD *)v7;
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v7 + 4);
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v7 + 8);
        *(_DWORD *)(v6 + 12) = *(_DWORD *)(v7 + 12);
        *(_DWORD *)(v6 + 16) = *(_DWORD *)(v7 + 16);
        *(_DWORD *)(v6 + 20) = *(_DWORD *)(v7 + 20);
        *(_DWORD *)(v6 + 24) = *(_DWORD *)(v7 + 24);
        *(_DWORD *)(v6 + 28) = *(_DWORD *)(v7 + 28);
        *(_DWORD *)(v6 + 32) = *(_DWORD *)(v7 + 32);
        *(_DWORD *)(v6 + 36) = *(_DWORD *)(v7 + 36);
        *(_DWORD *)(v6 + 40) = *(_DWORD *)(v7 + 40);
        *(_DWORD *)(v6 + 44) = *(_DWORD *)(v7 + 44);
        v9 = v6 + 60;
        *(_DWORD *)v9 = *(_DWORD *)(v7 + 60);
        *(_DWORD *)(v9 + 4) = *(_DWORD *)(v7 + 64);
        *(_DWORD *)(v9 + 8) = *(_DWORD *)(v7 + 68);
        v10 = v6 + 72;
        *(_DWORD *)v10 = *(_DWORD *)(v7 + 72);
        *(_DWORD *)(v10 + 4) = *(_DWORD *)(v7 + 76);
        *(_DWORD *)(v10 + 8) = *(_DWORD *)(v7 + 80);
        *(_DWORD *)(v6 + 84) = *(_DWORD *)(v7 + 84);
        *(_DWORD *)(v6 + 88) = *(_DWORD *)(v7 + 88);
        *(_DWORD *)(v6 + 92) = *(_DWORD *)(v7 + 92);
        *(_DWORD *)(v6 + 96) = *(_DWORD *)(v7 + 96);
        v3 = (char *)v3 + 220;
        v7 += 220;
        v6 += 220;
        ++v19;
        if ( (unsigned int)v3 >= v5 )
          break;
        v4 = v19;
      }
      v2 = v18;
    }
    v11 = *(_DWORD *)(a2 + 8);
    if ( v11 < v2->m_num )
    {
      v12 = v11;
      do
      {
        LODWORD(v24.qw) = 1065353216;
        LODWORD(v24.qx) = 0;
        LODWORD(v24.qy) = 0;
        LODWORD(v24.qz) = 0;
        LODWORD(v24.m_fOrigin.x) = 0;
        LODWORD(v24.m_fOrigin.y) = 0;
        LODWORD(v24.m_fOrigin.z) = 0;
        Frame::cache(&v24);
        v13 = (int)&v2->m_data[v12];
        qmemcpy(&v2->m_data[v12], &v20, 0x68u);
        *(_DWORD *)(v13 + 104) = v21;
        *(_DWORD *)(v13 + 108) = v22;
        *(_DWORD *)(v13 + 112) = v23;
        v14 = v13 + 168;
        *(_DWORD *)v14 = LODWORD(v24.m_fOrigin.x);
        *(_DWORD *)(v14 + 4) = LODWORD(v24.m_fOrigin.y);
        *(_DWORD *)(v14 + 8) = LODWORD(v24.m_fOrigin.z);
        *(_DWORD *)(v13 + 116) = (_DWORD)v24.qw;
        *(_DWORD *)(v13 + 120) = LODWORD(v24.qx);
        *(_DWORD *)(v13 + 124) = LODWORD(v24.qy);
        *(_DWORD *)(v13 + 128) = LODWORD(v24.qz);
        *(_DWORD *)(v13 + 132) = LODWORD(v24.m_fl2gv[0]);
        *(_DWORD *)(v13 + 136) = LODWORD(v24.m_fl2gv[1]);
        *(_DWORD *)(v13 + 140) = LODWORD(v24.m_fl2gv[2]);
        *(_DWORD *)(v13 + 144) = LODWORD(v24.m_fl2gv[3]);
        *(_DWORD *)(v13 + 148) = LODWORD(v24.m_fl2gv[4]);
        *(_DWORD *)(v13 + 152) = LODWORD(v24.m_fl2gv[5]);
        *(_DWORD *)(v13 + 156) = LODWORD(v24.m_fl2gv[6]);
        *(_DWORD *)(v13 + 160) = LODWORD(v24.m_fl2gv[7]);
        *(_DWORD *)(v13 + 164) = LODWORD(v24.m_fl2gv[8]);
        v15 = v13 + 180;
        *(_DWORD *)v15 = v25;
        *(_DWORD *)(v15 + 4) = v26;
        *(_DWORD *)(v15 + 8) = v27;
        v16 = v13 + 192;
        *(_DWORD *)v16 = v28;
        *(_DWORD *)(v16 + 4) = v29;
        *(_DWORD *)(v16 + 8) = v30;
        *(_DWORD *)(v13 + 204) = v31;
        *(_DWORD *)(v13 + 208) = v32;
        *(_DWORD *)(v13 + 212) = v33;
        *(_DWORD *)(v13 + 216) = v34;
        ++v11;
        ++v12;
        v2 = v18;
      }
      while ( v11 < v18->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (0054FA80) --------------------------------------------------------  // acclient.c:382821
int __thiscall RenderDevice::GraphicsStatesType::operator=(int this, int a2)
{
  int v2; // ebx@1
  int v3; // ebp@1
  int v4; // ecx@1
  int v5; // edx@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // ecx@1
  int v9; // ecx@3
  signed int v11; // [sp+14h] [bp+4h]@1

  v2 = this;
  v3 = a2;
  qmemcpy((void *)this, (const void *)a2, 0x40u);
  qmemcpy((void *)(this + 64), (const void *)(a2 + 64), 0x40u);
  qmemcpy((void *)(this + 128), (const void *)(a2 + 128), 0x44u);
  v4 = this + 192;
  *(_DWORD *)(v4 + 4) = *(_DWORD *)(a2 + 196);
  *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 200);
  *(_DWORD *)(v4 + 12) = *(_DWORD *)(a2 + 204);
  v5 = v2 + 208;
  *(_DWORD *)v5 = *(_DWORD *)(a2 + 208);
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(a2 + 212);
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(a2 + 216);
  *(_DWORD *)(v5 + 12) = *(_DWORD *)(a2 + 220);
  *(_DWORD *)(v2 + 224) = *(_DWORD *)(a2 + 224);
  *(_DWORD *)(v2 + 228) = *(_DWORD *)(a2 + 228);
  *(_DWORD *)(v2 + 232) = *(_DWORD *)(a2 + 232);
  *(_DWORD *)(v2 + 236) = *(_DWORD *)(a2 + 236);
  *(_DWORD *)(v2 + 240) = *(_DWORD *)(a2 + 240);
  *(_DWORD *)(v2 + 244) = *(_DWORD *)(a2 + 244);
  *(_DWORD *)(v2 + 248) = *(_DWORD *)(a2 + 248);
  *(_DWORD *)(v2 + 252) = *(_DWORD *)(a2 + 252);
  SmartArray<RenderLight,1>::operator=((SmartArray<RenderLight,1> *)(v2 + 256), a2 + 256);
  *(_BYTE *)(v2 + 268) = *(_BYTE *)(a2 + 268);
  v6 = v2 + 272;
  *(_DWORD *)v6 = *(_DWORD *)(a2 + 272);
  *(_DWORD *)(v6 + 4) = *(_DWORD *)(a2 + 276);
  *(_DWORD *)(v6 + 8) = *(_DWORD *)(a2 + 280);
  *(_DWORD *)(v6 + 12) = *(_DWORD *)(a2 + 284);
  v7 = v2 + 288;
  v8 = a2 - v2;
  v11 = 15;
  do
  {
    *(_DWORD *)v7 = *(_DWORD *)(v8 + v7);
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(v8 + v7 + 4);
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + v7 + 8);
    *(_DWORD *)(v7 + 12) = *(_DWORD *)(v8 + v7 + 12);
    v7 += 16;
    --v11;
  }
  while ( v11 );
  v9 = v2 + 528;
  *(_DWORD *)v9 = *(_DWORD *)(v3 + 528);
  *(_DWORD *)(v9 + 4) = *(_DWORD *)(v3 + 532);
  *(_DWORD *)(v9 + 8) = *(_DWORD *)(v3 + 536);
  *(_DWORD *)(v9 + 12) = *(_DWORD *)(v3 + 540);
  *(_DWORD *)(v2 + 544) = *(_DWORD *)(v3 + 544);
  *(_DWORD *)(v2 + 548) = *(_DWORD *)(v3 + 548);
  *(_DWORD *)(v2 + 552) = *(_DWORD *)(v3 + 552);
  *(_DWORD *)(v2 + 556) = *(_DWORD *)(v3 + 556);
  return v2;
}

//----- (0054FC40) --------------------------------------------------------  // acclient.c:382888
void __thiscall RenderDevice::Begin(RenderDevice *this)
{
  RenderDevice *v1; // ebp@1
  int v2; // eax@1
  char *v3; // esi@6
  char *v4; // esi@9
  int v5; // [sp+10h] [bp-270h]@1
  int v6; // [sp+14h] [bp-26Ch]@1
  int v7; // [sp+18h] [bp-268h]@1
  int v8; // [sp+1Ch] [bp-264h]@1
  int v9; // [sp+20h] [bp-260h]@1
  int v10; // [sp+24h] [bp-25Ch]@1
  int v11; // [sp+28h] [bp-258h]@1
  int v12; // [sp+2Ch] [bp-254h]@1
  int v13; // [sp+30h] [bp-250h]@1
  int v14; // [sp+34h] [bp-24Ch]@1
  int v15; // [sp+38h] [bp-248h]@1
  int v16; // [sp+3Ch] [bp-244h]@1
  int v17; // [sp+40h] [bp-240h]@1
  PStringBase<char> _Description; // [sp+44h] [bp-23Ch]@4
  int v19; // [sp+48h] [bp-238h]@1
  PStringBase<char> _Name; // [sp+4Ch] [bp-234h]@4
  RenderDevice::GraphicsStatesType v21; // [sp+50h] [bp-230h]@1

  v1 = this;
  v5 = 0;
  v6 = 800;
  v7 = 600;
  LOBYTE(v8) = 0;
  v9 = 0;
  v10 = 32;
  LOWORD(v11) = 0;
  BYTE2(v11) = 0;
  qmemcpy(&this->m_presentation, &v5, sizeof(this->m_presentation));
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  LOWORD(v16) = 0;
  qmemcpy(&this->m_caps, &v5, sizeof(this->m_caps));
  LOWORD(v19) = 1;
  BYTE2(v19) = 1;
  *(_DWORD *)&this->m_config.bUseStencilBuffer = v19;
  v5 = 0;
  LOBYTE(v6) = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  this->m_config.hFocusWindow = 0;
  qmemcpy(&this->m_displayInfo, &v5, sizeof(this->m_displayInfo));
  this->m_viewportX = 0;
  this->m_viewportY = 0;
  this->m_viewportWidth = 0;
  this->m_viewportHeight = 0;
  this->m_RenderTargetWidth = 0;
  this->m_RenderTargetHeight = 0;
  LODWORD(this->m_DisplayAspectRatio) = 1065353216;
  LODWORD(this->m_ViewportAspectRatio) = 1065353216;
  this->m_bOpenScene = 0;
  this->m_bDeviceLost = 0;
  this->m_nFrameStamp = 1;
  this->m_pFrameBufferSurface = 0;
  this->m_pDepthStencilSurface = 0;
  this->m_pRenderTarget = 0;
  this->m_pDepthStencilTarget = 0;
  this->m_WireframeMode = 0;
  this->m_ReverseCulling = 0;
  RenderDevice::GraphicsStatesType::GraphicsStatesType(&v21);
  RenderDevice::GraphicsStatesType::operator=((int)&v1->m_GState, v2);
  if ( (v21.FFLightSources.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && v21.FFLightSources.m_data )
    operator delete[](&v21.FFLightSources.m_data[-1].distancesq);
  v1->m_pDebugFont = 0;
  v1->m_DebugFontWidth = 0;
  v1->m_DebugFontHeight = 0;
  PStringBase<char>::PStringBase<char>(&_Description, "Enable wireframe rendering");
  PStringBase<char>::PStringBase<char>(&_Name, "RenderDevice.Wireframe");
  if ( v1 != (RenderDevice *)-196 )
    GlobalRegistry::RegisterVariableInternal(&v1->m_WireframeMode, GRVDataType_Bool, &_Name, &_Description, 0, 0, 0, 0);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  }
}

//----- (0054FEB0) --------------------------------------------------------  // acclient.c:382993
void __thiscall RenderDevice::Shutdown(RenderDevice *this)
{
  RenderDevice *v1; // esi@1

  v1 = this;
  RenderDevice::End(this);
  RenderDevice::Begin(v1);
}

//----- (00706180) --------------------------------------------------------  // acclient.c:793383
void sub_706180()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86F340, PFID_A8R8G8B8);
}

//----- (00706190) --------------------------------------------------------  // acclient.c:793389
int sub_706190()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_59, "None");
  return atexit(_E92_35);
}

//----- (007061B0) --------------------------------------------------------  // acclient.c:793396
int _E94_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_59, "Speed");
  return atexit(sub_771AC0);
}

//----- (007061D0) --------------------------------------------------------  // acclient.c:793403
int sub_7061D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_59, "Noise");
  return atexit(sub_771AF0);
}

//----- (007061F0) --------------------------------------------------------  // acclient.c:793410
int sub_7061F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_59, "Sine");
  return atexit(sub_771B20);
}

//----- (00706210) --------------------------------------------------------  // acclient.c:793417
int sub_706210()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_59, "Square");
  return atexit(sub_771B50);
}

//----- (00706230) --------------------------------------------------------  // acclient.c:793424
int sub_706230()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_59, "Bounce");
  return atexit(_E107_88);
}

//----- (00706250) --------------------------------------------------------  // acclient.c:793431
int _E109_69()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_59, "Perlin");
  return atexit(sub_771BB0);
}

//----- (00706270) --------------------------------------------------------  // acclient.c:793438
int _E112_94()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_59, "Fractal");
  return atexit(_E113_67);
}

//----- (00706290) --------------------------------------------------------  // acclient.c:793445
int _E115_68()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_59, "FrameLoop");
  return atexit(_E116_59);
}

//----- (007062B0) --------------------------------------------------------  // acclient.c:793452
int sub_7062B0()
{
  return atexit(nullsub_1240);
}

//----- (00771A90) --------------------------------------------------------  // acclient.c:905545
void __cdecl _E92_35()
{
  char *v0; // esi@1

  v0 = &waveform_None_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771AC0) --------------------------------------------------------  // acclient.c:905558
void __cdecl sub_771AC0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771AF0) --------------------------------------------------------  // acclient.c:905571
void __cdecl sub_771AF0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771B20) --------------------------------------------------------  // acclient.c:905584
void __cdecl sub_771B20()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771B50) --------------------------------------------------------  // acclient.c:905597
void __cdecl sub_771B50()
{
  char *v0; // esi@1

  v0 = &waveform_Square_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771B80) --------------------------------------------------------  // acclient.c:905610
void __cdecl _E107_88()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771BB0) --------------------------------------------------------  // acclient.c:905623
void __cdecl sub_771BB0()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771BE0) --------------------------------------------------------  // acclient.c:905636
void __cdecl _E113_67()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771C10) --------------------------------------------------------  // acclient.c:905649
void __cdecl _E116_59()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

