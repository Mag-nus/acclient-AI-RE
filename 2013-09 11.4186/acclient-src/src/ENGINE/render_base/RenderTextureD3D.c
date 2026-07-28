/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderTextureD3D
   Object     : ENGINE\render_base\RenderTextureD3D.obj
   Functions  : 92
   Addresses  : 00695120 - 00785620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00695120) --------------------------------------------------------  // acclient.c:684828
void __thiscall D3DLevelResourceType::D3DLevelResourceType(D3DLevelResourceType *this)
{
  memset(this, 0, 0x18u);
}

//----- (00695140) --------------------------------------------------------  // acclient.c:684834
bool __thiscall RenderTextureD3D::GetSubObjects(RenderTextureD3D *this)
{
  RenderTexture *v1; // esi@1
  bool result; // al@2

  v1 = (RenderTexture *)this;
  if ( DBCache::IsRunTime() )
  {
    if ( Render::m_pRenderer )
      result = RenderTexture::GetSubObjects(v1) != 0;
    else
      result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00695170) --------------------------------------------------------  // acclient.c:684855
void __thiscall SmartArray<D3DLevelResourceType,1>::Reset(SmartArray<D3DLevelResourceType,1> *this)
{
  SmartArray<D3DLevelResourceType,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // edx@5
  int v6; // ebp@5
  void *v7; // edi@6
  char v8; // [sp+8h] [bp-18h]@6

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
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        memset(&v8, 0, 0x18u);
        v7 = &v1->m_data[v5];
        --v5;
        --v6;
        qmemcpy(v7, &v8, 0x18u);
      }
      while ( v6 );
    }
  }
}

//----- (006951F0) --------------------------------------------------------  // acclient.c:684897
char __thiscall SmartArray<D3DLevelResourceType,1>::grow(SmartArray<D3DLevelResourceType,1> *this, unsigned int i_nSize)
{
  SmartArray<D3DLevelResourceType,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  D3DLevelResourceType *v6; // ebp@5
  int v7; // ecx@7
  int v8; // eax@8
  unsigned int v9; // edx@8
  const void *v10; // esi@9
  void *v11; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<D3DLevelResourceType,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](24 * i_nSize);
    v6 = (D3DLevelResourceType *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0x18u,
        i_nSize,
        (void *(__thiscall *)(void *))D3DLevelResourceType::D3DLevelResourceType);
      if ( v2->m_data )
      {
        v7 = v2->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          v9 = v2->m_num;
          do
          {
            v10 = &v2->m_data[v8];
            v11 = &v6[v8];
            --v8;
            --v9;
            qmemcpy(v11, v10, 0x18u);
          }
          while ( v9 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v6;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (006952B0) --------------------------------------------------------  // acclient.c:684959
void __thiscall RenderTextureD3D::ReleaseD3DSurfaces(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // edi@1
  unsigned int v2; // ebp@1
  int v3; // esi@2
  signed int v4; // ebx@3
  RenderSurfaceD3D *v5; // ecx@4

  v1 = this;
  v2 = 0;
  if ( this->m_D3DSurfaces.m_num )
  {
    v3 = 0;
    do
    {
      v4 = 6;
      do
      {
        v5 = v1->m_D3DSurfaces.m_data->m_Resources[v3];
        if ( v5 )
        {
          ((void (*)(void))v5->vfptr->Release)();
          v1->m_D3DSurfaces.m_data->m_Resources[v3] = 0;
        }
        ++v3;
        --v4;
      }
      while ( v4 );
      ++v2;
    }
    while ( v2 < v1->m_D3DSurfaces.m_num );
  }
  SmartArray<D3DLevelResourceType,1>::Reset(&v1->m_D3DSurfaces);
}

//----- (00695320) --------------------------------------------------------  // acclient.c:684995
void __thiscall RenderTextureD3D::ReleaseD3DTexture(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  IDirect3DTexture9 *v2; // eax@4
  IDirect3DCubeTexture9 *v3; // eax@10

  v1 = this;
  RenderTextureD3D::ReleaseD3DSurfaces(this);
  if ( v1->m_p2DTextureD3D )
  {
    if ( RenderDevice::render_device )
      RenderDeviceD3D::InvalidateCachedTexturePointer(
        (RenderDeviceD3D *)RenderDevice::render_device,
        v1->m_p2DTextureD3D);
    v2 = v1->m_p2DTextureD3D;
    if ( v2 )
    {
      v2->vfptr->Release((IUnknown *)v1->m_p2DTextureD3D);
      v1->m_p2DTextureD3D = 0;
    }
    g_nTotalTextureRemoteBytes -= v1->m_nResourceSize;
  }
  if ( v1->m_pCubeTextureD3D )
  {
    if ( RenderDevice::render_device )
      RenderDeviceD3D::InvalidateCachedTexturePointer(
        (RenderDeviceD3D *)RenderDevice::render_device,
        v1->m_pCubeTextureD3D);
    v3 = v1->m_pCubeTextureD3D;
    if ( v3 )
    {
      v3->vfptr->Release((IUnknown *)v1->m_pCubeTextureD3D);
      v1->m_pCubeTextureD3D = 0;
    }
    g_nTotalTextureRemoteBytes -= v1->m_nResourceSize;
  }
}
// 8F888C: using guessed type __int32 g_nTotalTextureRemoteBytes;

//----- (006953B0) --------------------------------------------------------  // acclient.c:685035
char __thiscall RenderTextureD3D::PurgeResource(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  char result; // al@1

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    RenderTextureD3D::ReleaseD3DTexture((RenderTextureD3D *)((char *)v1 - 48));
    result = 1;
  }
  return result;
}

//----- (006953D0) --------------------------------------------------------  // acclient.c:685051
char __thiscall SmartArray<D3DLevelResourceType,1>::SetNElements(SmartArray<D3DLevelResourceType,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<D3DLevelResourceType,1> *v3; // ebx@1
  unsigned int v4; // ebp@1
  unsigned int v5; // eax@3
  char result; // al@5
  const unsigned int v7; // edx@8
  char v8; // [sp+8h] [bp-18h]@9

  v3 = this;
  v4 = i_nSize;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    if ( i_nSize < this->m_num )
    {
      v7 = i_nSize;
      do
      {
        memset(&v8, 0, 0x18u);
        qmemcpy(&this->m_data[v7], &v8, sizeof(this->m_data[v7]));
        ++v4;
        ++v7;
      }
      while ( v4 < this->m_num );
      v4 = i_nSize;
    }
    goto LABEL_11;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<D3DLevelResourceType,1>::grow(v3, v5);
  if ( result )
  {
LABEL_11:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}

//----- (00695460) --------------------------------------------------------  // acclient.c:685094
char __thiscall RenderTextureD3D::CopyInto(RenderTextureD3D *this, DBObj *retval)
{
  DBObj *v2; // esi@1
  RenderTextureD3D *v3; // ebx@1
  char result; // al@1
  const unsigned int v5; // eax@2
  char *v6; // edi@3
  int v7; // esi@4
  signed int v8; // ebp@5
  int v9; // ecx@6
  InterfaceVtbl *v10; // eax@11
  GraphicsResource *v11; // esi@11
  unsigned int il; // [sp+0h] [bp-4h]@3

  v2 = retval;
  v3 = this;
  result = RenderTexture::CopyInto((RenderTexture *)&this->vfptr, retval);
  if ( result )
  {
    RenderTextureD3D::ReleaseD3DSurfaces((RenderTextureD3D *)retval);
    v5 = v3->m_D3DSurfaces.m_num;
    if ( v5 )
    {
      v6 = (char *)&retval[3].m_timeStamp;
      SmartArray<D3DLevelResourceType,1>::SetNElements(
        (SmartArray<D3DLevelResourceType,1> *)&retval[3].m_timeStamp,
        v5,
        1);
      il = 0;
      if ( v3->m_D3DSurfaces.m_num )
      {
        v7 = 0;
        do
        {
          v8 = 6;
          do
          {
            *(_DWORD *)(v7 * 4 + *(_DWORD *)v6) = v3->m_D3DSurfaces.m_data->m_Resources[v7];
            v9 = *(_DWORD *)(v7 * 4 + *(_DWORD *)v6);
            if ( v9 )
              (*(void (**)(void))(*(_DWORD *)v9 + 16))();
            ++v7;
            --v8;
          }
          while ( v8 );
          ++il;
        }
        while ( il < v3->m_D3DSurfaces.m_num );
        v2 = retval;
      }
    }
    v10 = v2[1].vfptr;
    *(_DWORD *)&v2[3].m_bLoaded = 0;
    *((_DWORD *)&v2[3].m_bLoaded + 1) = 0;
    v11 = (GraphicsResource *)&v2[1];
    if ( (unsigned __int8)((int (__thiscall *)(GraphicsResource *))v10->IUnknown_Release)(v11) )
      GraphicsResource::MarkResourceAsLost(v11);
    result = 1;
  }
  return result;
}

//----- (00695520) --------------------------------------------------------  // acclient.c:685157
bool __thiscall RenderTextureD3D::ReleaseSubObjects(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  bool result; // al@2

  v1 = this;
  if ( DBCache::IsRunTime() )
  {
    RenderTextureD3D::ReleaseD3DTexture(v1);
    result = RenderTexture::ReleaseSubObjects((RenderTexture *)&v1->vfptr) != 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00695550) --------------------------------------------------------  // acclient.c:685176
char __thiscall RenderTextureD3D::CreateD3DTexture(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  unsigned int v2; // eax@5
  unsigned int v3; // ecx@5
  unsigned int v4; // ebx@13
  TextureType v5; // eax@14
  const unsigned int v6; // ebp@14
  int v7; // eax@15
  unsigned int v8; // ecx@15
  unsigned int v9; // eax@15
  int v10; // eax@24
  unsigned int v11; // ecx@24
  unsigned int v12; // eax@24
  int v13; // ebx@37
  unsigned int v14; // eax@37
  unsigned int v15; // edx@37
  unsigned int v16; // ebp@39
  TextureType v17; // eax@40
  int v18; // eax@41
  __int32 v19; // edi@53
  int v20; // eax@53
  int v21; // ecx@53
  int v22; // ecx@53
  unsigned int v23; // eax@56
  TextureType v24; // eax@58
  GraphicsResource *v25; // esi@62
  char bCanDiscardMoreMemory; // [sp+13h] [bp-55h]@13
  _D3DCUBEMAP_FACES D3DCubeFace; // [sp+14h] [bp-54h]@3
  IDirect3DSurface9 *pD3DSurface; // [sp+18h] [bp-50h]@40
  _D3DPOOL poolD3D; // [sp+1Ch] [bp-4Ch]@5
  unsigned int il; // [sp+20h] [bp-48h]@37
  int v32; // [sp+24h] [bp-44h]@38
  unsigned int nResourceSize; // [sp+28h] [bp-40h]@14
  unsigned int NumResources; // [sp+2Ch] [bp-3Ch]@13
  PixelFormatDesc PFD; // [sp+30h] [bp-38h]@13

  v1 = this;
  if ( this->m_TextureType == 5 )
    return 1;
  if ( !this->m_nNumLevels )
    return 0;
  D3DCubeFace = 0;
  RenderTextureD3D::ReleaseD3DSurfaces(this);
  if ( v1->m_Flags & 1 )
    D3DCubeFace = 1;
  v2 = v1->m_Flags;
  v3 = v1->m_Flags >> 1;
  poolD3D = 0;
  if ( v3 & 1 )
    poolD3D = 2;
  if ( v2 & 4 && RenderDevice::render_device->m_caps.bAutoGenMipMaps )
    D3DCubeFace |= 0x400u;
  if ( v2 & 8 && RenderDevice::render_device->m_caps.bDynamicTextures )
    D3DCubeFace |= 0x200u;
  ClipPlane::ClipPlane((ClipPlane *)&PFD);
  PixelFormatDesc::SetFormat(&PFD, v1->m_PixelFormat);
  v4 = NumResources;
  for ( bCanDiscardMoreMemory = 1; ; bCanDiscardMoreMemory = GraphicsResource::DiscardResourceBytes(v6) )
  {
    v5 = v1->m_TextureType;
    v6 = 0;
    nResourceSize = 0;
    if ( v5 == 2 )
    {
      v7 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, unsigned int, _D3DCUBEMAP_FACES, PixelFormatID, _D3DPOOL, int, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 92))(
             LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
             v1->m_nWidth,
             v1->m_nHeight,
             v1->m_nNumLevels,
             D3DCubeFace,
             v1->m_PixelFormat,
             poolD3D,
             &v1->m_p2DTextureD3D,
             0);
      v8 = v1->m_nHeight;
      v4 = v7;
      v9 = v1->m_nWidth;
      if ( v1->m_nNumLevels )
      {
        nResourceSize = v1->m_nNumLevels;
        do
        {
          v6 += v9 * v8 * (unsigned __int8)PFD.bitsPerPixel >> 3;
          if ( v9 )
            v9 >>= 1;
          if ( v8 )
            v8 >>= 1;
          --nResourceSize;
        }
        while ( nResourceSize );
        nResourceSize = v6;
      }
    }
    else if ( v5 == 4 )
    {
      v10 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, _D3DCUBEMAP_FACES, PixelFormatID, _D3DPOOL, int, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 100))(
              LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
              v1->m_nEdgeLength,
              v1->m_nNumLevels,
              D3DCubeFace,
              v1->m_PixelFormat,
              poolD3D,
              &v1->m_pCubeTextureD3D,
              0);
      v11 = v1->m_nNumLevels;
      v4 = v10;
      v12 = v1->m_nEdgeLength;
      if ( v11 )
      {
        do
        {
          v6 += v12 * v12 * (unsigned __int8)PFD.bitsPerPixel >> 3;
          if ( v12 )
            v12 >>= 1;
          --v11;
        }
        while ( v11 );
        nResourceSize = v6;
      }
    }
    else if ( v5 != 5 )
    {
      return 0;
    }
    if ( !v4 )
      break;
    if ( v4 != -2005532292 )
    {
      if ( (v4 & 0x80000000) != 0 )
        return 0;
      break;
    }
    if ( !bCanDiscardMoreMemory )
      return 0;
  }
  if ( !v1->m_p2DTextureD3D && !v1->m_pCubeTextureD3D )
    return 0;
  v13 = (int)&v1->m_D3DSurfaces;
  SmartArray<D3DLevelResourceType,1>::SetNElements(&v1->m_D3DSurfaces, v1->m_nNumLevels, 1);
  v14 = v1->m_nNumLevels;
  v15 = 0;
  il = 0;
  if ( !v14 )
  {
LABEL_58:
    v24 = v1->m_TextureType;
    if ( v24 == 2 || v24 != 3 && v24 == 4 )
      g_nTotalTextureRemoteBytes += v6;
    v25 = (GraphicsResource *)&v1->vfptr;
    GraphicsResource::SetResourceSize(v25, v6);
    GraphicsResource::MarkResourceAsNotLost(v25);
    return 1;
  }
  v32 = 0;
  poolD3D = 0;
  while ( 1 )
  {
    memset((void *)(poolD3D + *(_DWORD *)v13), 0, 0x18u);
    v16 = 0;
    NumResources = v1->m_TextureType != 4 ? 1 : 6;
    if ( NumResources )
      break;
LABEL_56:
    v23 = v1->m_nNumLevels;
    ++v15;
    il = v15;
    poolD3D += 24;
    v32 += 6;
    if ( v15 >= v23 )
    {
      v6 = nResourceSize;
      goto LABEL_58;
    }
  }
  while ( 1 )
  {
    v17 = v1->m_TextureType;
    pD3DSurface = 0;
    if ( v17 == 2 )
    {
      v18 = v1->m_p2DTextureD3D->vfptr[6].QueryInterface(
              (IUnknown *)v1->m_p2DTextureD3D,
              (_GUID *)v15,
              (void **)&pD3DSurface);
    }
    else
    {
      if ( v17 != 4 )
        return 0;
      switch ( v16 )
      {
        case 0u:
          D3DCubeFace = 0;
          break;
        case 1u:
          D3DCubeFace = 1;
          break;
        case 2u:
          D3DCubeFace = 2;
          break;
        case 3u:
          D3DCubeFace = 3;
          break;
        case 4u:
          D3DCubeFace = 4;
          break;
        case 5u:
          D3DCubeFace = 5;
          break;
        default:
          break;
      }
      v18 = ((int (__stdcall *)(IDirect3DCubeTexture9 *, _D3DCUBEMAP_FACES, unsigned int, IDirect3DSurface9 **))v1->m_pCubeTextureD3D->vfptr[6].QueryInterface)(
              v1->m_pCubeTextureD3D,
              D3DCubeFace,
              v15,
              &pD3DSurface);
    }
    if ( v18 < 0 || !pD3DSurface )
      return 0;
    v19 = poolD3D + *(_DWORD *)v13;
    v20 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    v21 = v32;
    *(_DWORD *)(v19 + 4 * v16) = v20;
    v22 = *(_DWORD *)(*(_DWORD *)v13 + 4 * (v16 + v21));
    if ( !v22 )
    {
      if ( pD3DSurface )
        pD3DSurface->vfptr->Release((IUnknown *)pD3DSurface);
      return 0;
    }
    if ( !(unsigned __int8)(*(int (__stdcall **)(IDirect3DSurface9 *, _DWORD, _DWORD))(*(_DWORD *)v22 + 112))(
                             pD3DSurface,
                             0,
                             0) )
      return 0;
    v15 = il;
    ++v16;
    if ( v16 >= NumResources )
      goto LABEL_56;
  }
}
// 8F888C: using guessed type __int32 g_nTotalTextureRemoteBytes;

//----- (00695920) --------------------------------------------------------  // acclient.c:685422
bool __thiscall RenderTextureD3D::RestoreResource(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1

  v1 = this;
  return GraphicsResource::RestoreResource((GraphicsResource *)this)
      && (v1[-1].m_D3DSurfaces.m_num != stru_8F88E0.id
       && (unsigned __int8)(*(int (__thiscall **)(int))(v1[-1].m_SourceLevels.m_sizeAndDeallocate + 84))(&v1[-1].m_SourceLevels.m_sizeAndDeallocate)
       || RenderTextureD3D::CreateD3DTexture((RenderTextureD3D *)((char *)v1 - 48)));
}

//----- (00695960) --------------------------------------------------------  // acclient.c:685434
void __thiscall RenderTextureD3D::Destroy(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1

  v1 = this;
  if ( DBCache::IsRunTime() )
  {
    RenderTextureD3D::ReleaseD3DTexture(v1);
    RenderTexture::ReleaseSubObjects((RenderTexture *)&v1->vfptr);
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
  RenderTexture::Destroy((RenderTexture *)&v1->vfptr);
  v1->m_p2DTextureD3D = 0;
  SmartArray<D3DLevelResourceType,1>::Reset(&v1->m_D3DSurfaces);
  v1->m_pCubeTextureD3D = 0;
}

//----- (006959B0) --------------------------------------------------------  // acclient.c:685452
IDirect3DTexture9 *__thiscall RenderTextureD3D::Get2DTextureD3D(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  IDirect3DTexture9 *result; // eax@3
  int v3; // edx@4

  v1 = this;
  if ( !this->m_bIsLost || this->vfptr->RestoreResource((GraphicsResource *)&this->vfptr) )
  {
    v3 = HIDWORD(Timer::local_time);
    LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
    HIDWORD(v1->m_TimeUsed) = v3;
    if ( RenderDevice::render_device )
      v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
    if ( !v1->m_p2DTextureD3D )
      RenderTextureD3D::CreateD3DTexture(v1);
    result = v1->m_p2DTextureD3D;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00695A10) --------------------------------------------------------  // acclient.c:685478
IDirect3DCubeTexture9 *__thiscall RenderTextureD3D::GetCubeTextureD3D(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  IDirect3DCubeTexture9 *result; // eax@3
  int v3; // edx@4

  v1 = this;
  if ( !this->m_bIsLost || this->vfptr->RestoreResource((GraphicsResource *)&this->vfptr) )
  {
    v3 = HIDWORD(Timer::local_time);
    LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
    HIDWORD(v1->m_TimeUsed) = v3;
    if ( RenderDevice::render_device )
      v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
    if ( !v1->m_pCubeTextureD3D )
      RenderTextureD3D::CreateD3DTexture(v1);
    result = v1->m_pCubeTextureD3D;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00695A70) --------------------------------------------------------  // acclient.c:685504
void __thiscall RenderTextureD3D::RenderTextureD3D(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  RenderTexture::RenderTexture((RenderTexture *)&this->vfptr);
  v2 = (int)&v1->m_D3DSurfaces;
  v1->vfptr = (InterfaceVtbl *)&RenderTextureD3D::vftable;
  v1->vfptr = (GraphicsResourceVtbl *)&RenderTextureD3D::vftable;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  v1->m_p2DTextureD3D = 0;
  SmartArray<D3DLevelResourceType,1>::Reset(&v1->m_D3DSurfaces);
  v1->m_pCubeTextureD3D = 0;
}
// 800888: using guessed type void *RenderTextureD3D::vftable;
// 800898: using guessed type __int32 (__stdcall *RenderTextureD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00695AB0) --------------------------------------------------------  // acclient.c:685525
RenderTextureD3D *__thiscall RenderTextureD3D::vector_deleting_destructor(RenderTextureD3D *this, unsigned int a2)
{
  return RenderTextureD3D::scalar_deleting_destructor((RenderTextureD3D *)((char *)this - 48), a2);
}

//----- (00695AC0) --------------------------------------------------------  // acclient.c:685531
void __thiscall RenderTextureD3D::~RenderTextureD3D(RenderTextureD3D *this)
{
  RenderTextureD3D *v1; // esi@1
  GraphicsResource *v2; // edi@1

  v1 = this;
  v2 = (GraphicsResource *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&RenderTextureD3D::vftable;
  this->vfptr = (GraphicsResourceVtbl *)&RenderTextureD3D::vftable;
  if ( DBCache::IsRunTime() )
  {
    RenderTextureD3D::ReleaseD3DTexture(v1);
    RenderTexture::ReleaseSubObjects((RenderTexture *)&v1->vfptr);
  }
  GraphicsResource::MarkResourceAsNotLost(v2);
  if ( (v1->m_D3DSurfaces.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_D3DSurfaces.m_data);
  v1->vfptr = (InterfaceVtbl *)&RenderTexture::vftable;
  v2->vfptr = (GraphicsResourceVtbl *)&RenderTexture::vftable;
  RenderTexture::End((RenderTexture *)&v1->vfptr);
  SmartArray<DBLevelInfo,1>::~SmartArray<DBLevelInfo,1>(&v1->m_SourceLevels);
  GraphicsResource::~GraphicsResource(v2);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79B198: using guessed type void *RenderTexture::vftable;
// 79B1A8: using guessed type __int32 (__stdcall *RenderTexture::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 800888: using guessed type void *RenderTextureD3D::vftable;
// 800898: using guessed type __int32 (__stdcall *RenderTextureD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00695B40) --------------------------------------------------------  // acclient.c:685561
int __thiscall RenderTextureD3D::GetLevelRef(RenderTextureD3D *this, const unsigned int _nLevel, const unsigned int _Resource)
{
  RenderTextureD3D *v3; // esi@1
  TextureType v4; // eax@1
  const unsigned int v5; // edi@4
  RenderSurfaceD3D *v6; // ecx@4
  RenderSurfaceD3D *v7; // esi@6
  RenderSurfaceD3D *v9; // ecx@11

  v3 = this;
  v4 = this->m_TextureType;
  if ( v4 == 2 )
  {
    if ( !RenderTextureD3D::Get2DTextureD3D(this) )
      return 0;
    if ( _nLevel >= v3->m_D3DSurfaces.m_num )
      return 0;
    v5 = _Resource + 6 * _nLevel;
    v6 = v3->m_D3DSurfaces.m_data->m_Resources[v5];
    if ( !v6 )
      return 0;
    ((void (*)(void))v6->vfptr->AddRef)();
  }
  else
  {
    if ( v4 != 4 )
      return 0;
    if ( !RenderTextureD3D::GetCubeTextureD3D(this) )
      return 0;
    if ( _nLevel >= v3->m_D3DSurfaces.m_num )
      return 0;
    v5 = _Resource + 6 * _nLevel;
    v9 = v3->m_D3DSurfaces.m_data->m_Resources[v5];
    if ( !v9 )
      return 0;
    ((void (*)(void))v9->vfptr->AddRef)();
  }
  v7 = v3->m_D3DSurfaces.m_data->m_Resources[v5];
  if ( v7 )
    return (int)&v7->vfptr;
  return 0;
}

//----- (00695BE0) --------------------------------------------------------  // acclient.c:685605
char __thiscall RenderTextureD3D::LoadTexture(RenderTextureD3D *this, RenderTexture *_Source)
{
  RenderTextureD3D *v2; // esi@1
  TextureType v3; // eax@3
  IDirect3DTexture9 *v4; // edi@8
  IDirect3DTexture9 *v5; // eax@9

  v2 = this;
  if ( !((_Source->m_Flags >> 1) & 1) )
    return 0;
  if ( (this->m_Flags >> 1) & 1 )
    return 0;
  v3 = this->m_TextureType;
  if ( v3 != _Source->m_TextureType )
    return 0;
  if ( v3 == 2 || v3 == 5 )
  {
    v4 = RenderTextureD3D::Get2DTextureD3D((RenderTextureD3D *)_Source);
    if ( !v4 )
      return 0;
    v5 = RenderTextureD3D::Get2DTextureD3D(v2);
    goto LABEL_12;
  }
  if ( v3 == 3 )
    return 1;
  if ( v3 == 4 )
  {
    v4 = (IDirect3DTexture9 *)RenderTextureD3D::GetCubeTextureD3D((RenderTextureD3D *)_Source);
    if ( v4 )
    {
      v5 = (IDirect3DTexture9 *)RenderTextureD3D::GetCubeTextureD3D(v2);
LABEL_12:
      if ( v5
        && (*(int (__stdcall **)(_DWORD, IDirect3DTexture9 *, IDirect3DTexture9 *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                                  + 124))(
             LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
             v4,
             v5) >= 0 )
        return 1;
      return 0;
    }
  }
  return 0;
}

//----- (00695C70) --------------------------------------------------------  // acclient.c:685651
RenderTextureD3D *__thiscall RenderTextureD3D::scalar_deleting_destructor(RenderTextureD3D *this, unsigned int a2)
{
  RenderTextureD3D *v2; // esi@1

  v2 = this;
  RenderTextureD3D::~RenderTextureD3D(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00719A20) --------------------------------------------------------  // acclient.c:812274
void sub_719A20()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F88A8, PFID_A8R8G8B8);
}

//----- (00719A30) --------------------------------------------------------  // acclient.c:812280
int sub_719A30()
{
  return atexit(_E92_50);
}

//----- (00719A40) --------------------------------------------------------  // acclient.c:812286
int _E94_41()
{
  return atexit(nullsub_264);
}

//----- (00719A50) --------------------------------------------------------  // acclient.c:812292
int sub_719A50()
{
  return atexit(nullsub_265);
}

//----- (00719A60) --------------------------------------------------------  // acclient.c:812298
void sub_719A60()
{
  LODWORD(dword_8F88E4) = 1053364187;
}

//----- (00719A70) --------------------------------------------------------  // acclient.c:812304
void _E102_38()
{
  flt_8F88E8 = 1000.0 + 1.0;
}

//----- (00719A90) --------------------------------------------------------  // acclient.c:812310
void _E104_19()
{
  flt_8F88EC = 24.0 * 8.0;
}

//----- (00719AB0) --------------------------------------------------------  // acclient.c:812316
void sub_719AB0()
{
  flt_8F88F0 = 24.0 * 0.5;
}

//----- (00719AD0) --------------------------------------------------------  // acclient.c:812322
int sub_719AD0()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_45, "Render.TextureFiltering");
  return atexit(sub_785020);
}

//----- (00719AF0) --------------------------------------------------------  // acclient.c:812329
int _E111_63()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_45, "Render.LandscapeDetailTextures");
  return atexit(sub_785050);
}

//----- (00719B10) --------------------------------------------------------  // acclient.c:812336
int _E114_69()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_45, "Render.BuildingDetailTextures");
  return atexit(sub_785080);
}

//----- (00719B30) --------------------------------------------------------  // acclient.c:812343
int _E117_87()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_45, "Render.FieldOfView");
  return atexit(sub_7850B0);
}

//----- (00719B50) --------------------------------------------------------  // acclient.c:812350
int _E120_79()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_45, "Render.LandscapeTextureDetail");
  return atexit(sub_7850E0);
}

//----- (00719B70) --------------------------------------------------------  // acclient.c:812357
int _E123_51()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_45, "Render.EnvironmentTextureDetail");
  return atexit(sub_785110);
}

//----- (00719B90) --------------------------------------------------------  // acclient.c:812364
int _E126_57()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_45, "Render.SceneryDrawDistance");
  return atexit(sub_785140);
}

//----- (00719BB0) --------------------------------------------------------  // acclient.c:812371
int _E129_52()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_45, "Render.LandscapeDrawDistance");
  return atexit(sub_785170);
}

//----- (00719BD0) --------------------------------------------------------  // acclient.c:812378
int _E132_52()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_45, "Render.ScreenBrightness");
  return atexit(sub_7851A0);
}

//----- (00719BF0) --------------------------------------------------------  // acclient.c:812385
int _E135_60()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_45, "Render.AspectRatio");
  return atexit(_E136_94);
}

//----- (00719C10) --------------------------------------------------------  // acclient.c:812392
int _E138_46()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_45, "Render.DisplayAdapter");
  return atexit(_E139_94);
}

//----- (00719C30) --------------------------------------------------------  // acclient.c:812399
int _E141_48()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_45, "Render.MaxHardwareClass");
  return atexit(_E142_88);
}

//----- (00719C50) --------------------------------------------------------  // acclient.c:812406
int _E144_45()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_45, "Render.AutomaticDegrades");
  return atexit(_E145_90);
}

//----- (00719C70) --------------------------------------------------------  // acclient.c:812413
int _E147_44()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_45, "Render.GraphicsPerformance");
  return atexit(_E148_86);
}

//----- (00719C90) --------------------------------------------------------  // acclient.c:812420
int _E150_43()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_45, "Render.DegradeDistance");
  return atexit(_E151_84);
}

//----- (00719CB0) --------------------------------------------------------  // acclient.c:812427
int _E153_41()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_45, "Render.MultiPassAlpha");
  return atexit(_E154_85);
}

//----- (00719CD0) --------------------------------------------------------  // acclient.c:812434
int _E156_43()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_45, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8938, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F893C, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F8940, "Anisotropic");
  return atexit(_E157_81);
}

//----- (00719D20) --------------------------------------------------------  // acclient.c:812444
int _E159_41()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_45, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8948, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F894C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8950, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8954, "VeryHigh");
  return atexit(_E160_84);
}

//----- (00719D80) --------------------------------------------------------  // acclient.c:812455
int _E162_44()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_45, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F895C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8960, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8964, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8968, "VeryHigh");
  return atexit(_E163_77);
}

//----- (00719DE0) --------------------------------------------------------  // acclient.c:812466
int _E165_39()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_45, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8970, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8974, "High");
  return atexit(_E166_79);
}

//----- (00719E20) --------------------------------------------------------  // acclient.c:812475
int _E168_40()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_45, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F897C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8980, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8984, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8988, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F898C, "Extreme");
  return atexit(_E169_78);
}

//----- (00719E90) --------------------------------------------------------  // acclient.c:812487
int _E171_39()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_45, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F8994, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F8998, "Wide");
  return atexit(_E172_76);
}

//----- (00719ED0) --------------------------------------------------------  // acclient.c:812496
int _E174_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_78, "None");
  return atexit(_E175_73);
}

//----- (00719EF0) --------------------------------------------------------  // acclient.c:812503
int _E177_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_78, "Speed");
  return atexit(_E178_73);
}

//----- (00719F10) --------------------------------------------------------  // acclient.c:812510
int _E180_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_78, "Noise");
  return atexit(_E181_73);
}

//----- (00719F30) --------------------------------------------------------  // acclient.c:812517
int _E183_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_78, "Sine");
  return atexit(_E184_70);
}

//----- (00719F50) --------------------------------------------------------  // acclient.c:812524
int _E186_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_78, "Square");
  return atexit(_E187_69);
}

//----- (00719F70) --------------------------------------------------------  // acclient.c:812531
int _E189_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_78, "Bounce");
  return atexit(_E190_70);
}

//----- (00719F90) --------------------------------------------------------  // acclient.c:812538
int _E192_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_78, "Perlin");
  return atexit(_E193_56);
}

//----- (00719FB0) --------------------------------------------------------  // acclient.c:812545
int _E195_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_78, "Fractal");
  return atexit(_E196_63);
}

//----- (00719FD0) --------------------------------------------------------  // acclient.c:812552
int _E198_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_78, "FrameLoop");
  return atexit(_E199_55);
}

//----- (00719FF0) --------------------------------------------------------  // acclient.c:812559
int sub_719FF0()
{
  return atexit(nullsub_262);
}

//----- (00785020) --------------------------------------------------------  // acclient.c:924206
void __cdecl sub_785020()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785050) --------------------------------------------------------  // acclient.c:924219
void __cdecl sub_785050()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785080) --------------------------------------------------------  // acclient.c:924232
void __cdecl sub_785080()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007850B0) --------------------------------------------------------  // acclient.c:924245
void __cdecl sub_7850B0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007850E0) --------------------------------------------------------  // acclient.c:924258
void __cdecl sub_7850E0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785110) --------------------------------------------------------  // acclient.c:924271
void __cdecl sub_785110()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785140) --------------------------------------------------------  // acclient.c:924284
void __cdecl sub_785140()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785170) --------------------------------------------------------  // acclient.c:924297
void __cdecl sub_785170()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007851A0) --------------------------------------------------------  // acclient.c:924310
void __cdecl sub_7851A0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007851D0) --------------------------------------------------------  // acclient.c:924323
void __cdecl _E136_94()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785200) --------------------------------------------------------  // acclient.c:924336
void __cdecl _E139_94()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785230) --------------------------------------------------------  // acclient.c:924349
void __cdecl _E142_88()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785260) --------------------------------------------------------  // acclient.c:924362
void __cdecl _E145_90()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785290) --------------------------------------------------------  // acclient.c:924375
void __cdecl _E148_86()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007852C0) --------------------------------------------------------  // acclient.c:924388
void __cdecl _E151_84()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007852F0) --------------------------------------------------------  // acclient.c:924401
void __cdecl _E154_85()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785320) --------------------------------------------------------  // acclient.c:924414
void __cdecl _E157_81()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_45;
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

//----- (00785360) --------------------------------------------------------  // acclient.c:924439
void __cdecl _E160_84()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_45;
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

//----- (007853A0) --------------------------------------------------------  // acclient.c:924464
void __cdecl _E163_77()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_45;
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

//----- (007853E0) --------------------------------------------------------  // acclient.c:924489
void __cdecl _E166_79()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_45;
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

//----- (00785420) --------------------------------------------------------  // acclient.c:924514
void __cdecl _E169_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_45;
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

//----- (00785460) --------------------------------------------------------  // acclient.c:924539
void __cdecl _E172_76()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_78;
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

//----- (007854A0) --------------------------------------------------------  // acclient.c:924564
void __cdecl _E175_73()
{
  char *v0; // esi@1

  v0 = &waveform_None_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007854D0) --------------------------------------------------------  // acclient.c:924577
void __cdecl _E178_73()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785500) --------------------------------------------------------  // acclient.c:924590
void __cdecl _E181_73()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785530) --------------------------------------------------------  // acclient.c:924603
void __cdecl _E184_70()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785560) --------------------------------------------------------  // acclient.c:924616
void __cdecl _E187_69()
{
  char *v0; // esi@1

  v0 = &waveform_Square_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785590) --------------------------------------------------------  // acclient.c:924629
void __cdecl _E190_70()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007855C0) --------------------------------------------------------  // acclient.c:924642
void __cdecl _E193_56()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007855F0) --------------------------------------------------------  // acclient.c:924655
void __cdecl _E196_63()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785620) --------------------------------------------------------  // acclient.c:924668
void __cdecl _E199_55()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

