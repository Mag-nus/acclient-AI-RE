/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderSurface
   Object     : ENGINE\render_base\RenderSurface.obj
   Functions  : 90
   Addresses  : 00443960 - 0072AE30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00443960) --------------------------------------------------------  // acclient.c:127809
char __cdecl RenderSurface::IsD3DFormat(PixelFormatID pf)
{
  char result; // al@2

  switch ( pf )
  {
    case 41:
    case 101:
    case 243:
    case 244:
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

//----- (00443A60) --------------------------------------------------------  // acclient.c:127829
void __thiscall RenderSurface::Begin(RenderSurface *this)
{
  RenderSurface *v1; // esi@1
  unsigned int v2; // eax@1

  v1 = this;
  this->sourceData.width = 0;
  this->sourceData.height = 0;
  this->sourceData.imageSize = 0;
  this->sourceData.sourceBits = 0;
  PixelFormatDesc::SetFormat(&this->sourceData.pfDesc, 0);
  v1->width = 0;
  v1->height = 0;
  v1->size = 0;
  v1->locked = 0;
  PixelFormatDesc::SetFormat(&v1->pfDesc, 0);
  v1->m_pSurfaceBits = 0;
  v2 = INVALID_DID_33.id;
  v1->m_IsDirty = 0;
  v1->m_ReadOnlyLock = 0;
  v1->m_didPalatte.id = v2;
}

//----- (00443AC0) --------------------------------------------------------  // acclient.c:127853
char __thiscall RenderSurface::InitLoad(RenderSurface *this)
{
  RenderSurface *v1; // esi@1
  char result; // al@2

  v1 = this;
  if ( !DBCache::IsRunTime() || (result = v1->vfptr[3].Release((Interface *)v1)) != 0 )
    result = 1;
  return result;
}

//----- (00443AE0) --------------------------------------------------------  // acclient.c:127865
char __thiscall RenderSurface::Lock(RenderSurface *this, tagRECT *rect, const unsigned int flags, int *_pitch, void **_data)
{
  int v5; // esi@3
  char result; // al@4

  if ( this->locked )
  {
    result = 0;
  }
  else
  {
    if ( this->m_pSurfaceBits )
    {
      v5 = this->pfDesc.bitsPerPixel * this->width >> 3;
      *_pitch = v5;
      *_data = (char *)this->m_pSurfaceBits + v5 * rect->top + rect->left * this->pfDesc.bitsPerPixel / 8;
    }
    result = 1;
    this->m_ReadOnlyLock = (flags >> 1) & 1;
    this->locked = 1;
  }
  return result;
}

//----- (00443B60) --------------------------------------------------------  // acclient.c:127890
void __thiscall RenderSurface::Unlock(RenderSurface *this)
{
  if ( this->locked )
  {
    if ( !this->m_ReadOnlyLock )
      this->m_IsDirty = 1;
    this->locked = 0;
    this->m_ReadOnlyLock = 0;
  }
}

//----- (00443B90) --------------------------------------------------------  // acclient.c:127902
PixelFormatID __thiscall RenderSurface::SelectSurfaceFormat(RenderSurface *this, PixelFormatID format)
{
  RenderSurface *v2; // edi@1
  PixelFormatID result; // eax@5
  unsigned int v4; // eax@6
  bool v5; // zf@8
  unsigned int v6; // ecx@9

  v2 = this;
  if ( DBCache::IsRunTime() && Render::m_pRenderer && HACK_formatConversion )
  {
    if ( RenderSurface::IsD3DFormat(format) )
    {
      v4 = v2->m_dataCategory;
      if ( v4 == 6 )
      {
        result = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
      }
      else
      {
        v5 = v4 == 10;
        result = format;
        if ( !v5 )
        {
          v6 = v2->sourceData.pfDesc.flags;
          if ( v6 & 4 )
          {
            if ( !RenderDevice::render_device->m_caps.bCompressedTextures )
              result = RenderDevice::render_device->m_displayInfo.pfARGBTextures;
          }
          else if ( v6 & 2 && v6 & 1 )
          {
            result = RenderDevice::render_device->m_displayInfo.pfARGBTextures;
          }
          else if ( v6 & 2 )
          {
            result = RenderDevice::render_device->m_displayInfo.pfAlphaTextures;
          }
          else if ( v6 & 1 )
          {
            result = RenderDevice::render_device->m_displayInfo.pfRGBTextures;
          }
        }
      }
    }
    else
    {
      result = format;
    }
  }
  else
  {
    result = format;
  }
  return result;
}
// 818248: using guessed type bool HACK_formatConversion;

//----- (00443C60) --------------------------------------------------------  // acclient.c:127961
char __thiscall RenderSurface::SaveJPG(RenderSurface *this, PStringBase<char> *filename)
{
  RenderSurface *v2; // edi@1
  RenderSurface *v3; // esi@1
  int v4; // ecx@8
  int v5; // edx@8
  char result; // al@10
  char *v7; // [sp+24h] [bp-4E70h]@5
  int v8; // [sp+28h] [bp-4E6Ch]@5
  struct _JPEG_CORE_PROPERTIES v9; // [sp+2Ch] [bp-4E68h]@7

  v2 = this;
  v3 = this;
  if ( this->pfDesc.format != 20 )
  {
    v3 = (RenderSurface *)((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    if ( !v3
      || !(unsigned __int8)((int (__thiscall *)(RenderSurface *, unsigned int, unsigned int, signed int, signed int))v3->vfptr[3].AddRef)(
                             v3,
                             v2->width,
                             v2->height,
                             20,
                             1)
      || !(unsigned __int8)((int (__thiscall *)(RenderSurface *, RenderSurface *))v3->vfptr[4].IUnknown_Release)(v3, v2) )
      return 0;
  }
  v7 = 0;
  if ( !(unsigned __int8)((int (__thiscall *)(RenderSurface *, int, signed int, int *, int *))v3->vfptr[4].IUnknown_QueryInterface)(
                           v3,
                           &v2->window.rect,
                           2,
                           &v8,
                           &v7)
    || !v7
    || ijlInit((int)&v9) )
    return 0;
  v9.DIBWidth = v3->width;
  v9.DIBHeight = v3->height;
  v9.DIBBytes = v7;
  v9.DIBPadBytes = v8 - (v3->width * v3->pfDesc.bitsPerPixel >> 3);
  v4 = (unsigned int)v3->pfDesc.bitsPerPixel >> 3;
  v9.JPGFile = filename->m_charbuffer->m_data;
  v9.DIBChannels = v4;
  v9.DIBColor = 2;
  v9.JPGWidth = v3->width;
  v5 = v3->height;
  v9.JPGChannels = 3;
  v9.JPGColor = 3;
  v9.JPGHeight = v5;
  v9.JPGSubsampling = 1;
  v9.jquality = 90;
  if ( ijlWrite(&v9, 8) )
  {
    ((void (__thiscall *)(RenderSurface *))v3->vfptr[4].IUnknown_AddRef)(v3);
    return 0;
  }
  if ( ijlFree((int)&v9) )
  {
    ((void (__thiscall *)(RenderSurface *))v3->vfptr[4].IUnknown_AddRef)(v3);
    result = 0;
  }
  else
  {
    ((void (__thiscall *)(RenderSurface *))v3->vfptr[4].IUnknown_AddRef)(v3);
    if ( v3 != v2 )
      v3->vfptr->Release((Interface *)v3);
    result = 1;
  }
  return result;
}

//----- (00443E00) --------------------------------------------------------  // acclient.c:128033
char __thiscall RenderSurface::Convert(RenderSurface *this, RenderSurface *source)
{
  PixelFormatID v2; // ebx@1
  RenderSurface *v3; // esi@1
  PixelFormatID v4; // eax@1
  char result; // al@4
  int v6; // ebp@9
  RenderSurface *v7; // ebx@14

  v2 = source->pfDesc.format;
  v3 = this;
  v4 = this->pfDesc.format;
  if ( v2 == v4 && source->width == this->width && source->height == this->height )
    return SurfaceWindow::Blit(&this->window, &source->window);
  if ( !RenderSurface::IsD3DFormat(v4) || !RenderSurface::IsD3DFormat(v2) || !RenderDevice::render_device )
    goto LABEL_11;
  if ( v3->m_pSurfaceBits )
  {
    v6 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    if ( !v6
      || !(unsigned __int8)(*(int (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 88))(
                             v6,
                             v3->width,
                             v3->height,
                             v3->pfDesc.format,
                             0) )
      goto LABEL_11;
  }
  else
  {
    v6 = (int)v3;
    v3->vfptr->AddRef((Interface *)v3);
  }
  if ( !source->m_pSurfaceBits )
  {
    v7 = source;
    source->vfptr->AddRef((Interface *)source);
    goto LABEL_19;
  }
  v7 = (RenderSurface *)((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
  if ( !v7
    || !(unsigned __int8)((int (__thiscall *)(RenderSurface *, unsigned int, unsigned int, PixelFormatID, _DWORD))v7->vfptr[3].AddRef)(
                           v7,
                           source->width,
                           source->height,
                           source->pfDesc.format,
                           0) )
    goto LABEL_11;
  result = SurfaceWindow::Blit(&v7->window, &source->window);
  if ( result )
  {
LABEL_19:
    if ( (unsigned __int8)(*(int (__thiscall **)(int, RenderSurface *))(*(_DWORD *)v6 + 104))(v6, v7)
      && (!v3->m_pSurfaceBits || SurfaceWindow::Blit(&v3->window, (SurfaceWindow *)(v6 + 172))) )
    {
      v7->vfptr->Release((Interface *)v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
      return 1;
    }
LABEL_11:
    result = 0;
  }
  return result;
}

//----- (00443F70) --------------------------------------------------------  // acclient.c:128099
void __thiscall RenderSurface::DestroySourceSurfaceBits(RenderSurface *this)
{
  RenderSurface *v1; // esi@1

  v1 = this;
  if ( this->sourceData.sourceBits )
  {
    operator delete[](this->sourceData.sourceBits);
    v1->sourceData.sourceBits = 0;
  }
}

//----- (00443F90) --------------------------------------------------------  // acclient.c:128112
void __thiscall RenderSurface::RenderSurface(RenderSurface *this)
{
  RenderSurface *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_33);
  GraphicsResource::GraphicsResource((GraphicsResource *)&v1->vfptr);
  v1->vfptr = (InterfaceVtbl *)&RenderSurface::vftable;
  v1->vfptr = (GraphicsResourceVtbl *)&RenderSurface::vftable;
  ClipPlane::ClipPlane((ClipPlane *)&v1->sourceData.pfDesc);
  SurfaceWindow::SurfaceWindow(&v1->window);
  ClipPlane::ClipPlane((ClipPlane *)&v1->pfDesc);
  RenderSurface::Begin(v1);
}
// 79967C: using guessed type void *RenderSurface::vftable;
// 799690: using guessed type __int32 (__stdcall *RenderSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00443FE0) --------------------------------------------------------  // acclient.c:128130
RenderSurface *__thiscall RenderSurface::vector_deleting_destructor(RenderSurface *this, unsigned int a2)
{
  return RenderSurface::scalar_deleting_destructor((RenderSurface *)((char *)this - 48), a2);
}

//----- (00443FF0) --------------------------------------------------------  // acclient.c:128136
bool __thiscall RenderSurface::Create(RenderSurface *this, unsigned int _width, unsigned int _height, PixelFormatID _pixelFormat, bool _bLocalData)
{
  RenderSurface *v5; // esi@1
  unsigned int v6; // ecx@1
  unsigned int v7; // eax@1
  void *v8; // eax@3
  bool result; // al@4

  v5 = this;
  this->height = _height;
  this->width = _width;
  this->locked = 0;
  this->m_IsDirty = 0;
  PixelFormatDesc::SetFormat(&this->pfDesc, _pixelFormat);
  v6 = v5->width;
  v7 = v5->height;
  v5->size = v7 * v6 * v5->pfDesc.bitsPerPixel >> 3;
  SurfaceWindow::Attach(&v5->window, v5, 0, 0, v6 - 1, v7 - 1);
  result = 1;
  if ( _bLocalData || !RenderSurface::IsD3DFormat(_pixelFormat) )
  {
    v8 = operator new[](v5->size);
    v5->m_pSurfaceBits = v8;
    if ( !v8 )
      result = 0;
  }
  return result;
}

//----- (004440A0) --------------------------------------------------------  // acclient.c:128166
char __thiscall RenderSurface::CreateFromSourceData(RenderSurface *this)
{
  RenderSurface *v1; // ebp@1
  PixelFormatID v2; // esi@3
  int v3; // ecx@5
  char result; // al@7
  int v5; // ebx@9
  InterfaceVtbl *v6; // eax@11
  void *v7; // edx@14
  const void *v8; // esi@20
  unsigned int v9; // eax@22
  unsigned int v10; // ecx@24
  bool v11; // cf@25
  char v12; // [sp+21h] [bp-4EC1h]@8
  int v13; // [sp+22h] [bp-4EC0h]@3
  int v14; // [sp+26h] [bp-4EBCh]@3
  int v15; // [sp+2Ah] [bp-4EB8h]@13
  char *v16; // [sp+2Eh] [bp-4EB4h]@22
  RenderSurface *v17; // [sp+32h] [bp-4EB0h]@9
  int v18; // [sp+36h] [bp-4EACh]@24
  char *v19; // [sp+3Ah] [bp-4EA8h]@13
  PixelFormatID v20; // [sp+3Eh] [bp-4EA4h]@8
  ClipPlane v21; // [sp+42h] [bp-4EA0h]@17
  unsigned __int8 v22; // [sp+4Eh] [bp-4E94h]@17
  struct _JPEG_CORE_PROPERTIES v23; // [sp+7Ah] [bp-4E68h]@4

  v1 = this;
  if ( !this->sourceData.sourceBits )
    return 0;
  if ( !RenderDevice::render_device )
    return 0;
  v2 = this->sourceData.pfDesc.format;
  v14 = this->sourceData.width;
  v13 = this->sourceData.height;
  if ( v2 == 500 )
  {
    memset(&v23, 0, sizeof(v23));
    if ( ijlInit((int)&v23) )
      return 0;
    v3 = v1->sourceData.imageSize;
    v23.JPGBytes = v1->sourceData.sourceBits;
    v23.JPGSizeBytes = v3;
    if ( ijlRead(&v23, 1) )
      return 0;
    v14 = v23.JPGWidth;
    v13 = v23.JPGHeight;
    v2 = 20;
    if ( v23.JPGChannels != 3 )
      return 0;
  }
  v12 = 0;
  v20 = RenderSurface::SelectSurfaceFormat(v1, v2);
  if ( v20 == v2 )
  {
    v6 = v1->vfptr;
    v5 = (int)v1;
    v17 = v1;
    v6->AddRef((Interface *)v1);
  }
  else
  {
    v12 = 1;
    v5 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    v17 = (RenderSurface *)v5;
    if ( !v5 )
      return 0;
  }
  if ( !(unsigned __int8)(*(int (__thiscall **)(int, int, int, PixelFormatID, signed int))(*(_DWORD *)v5 + 88))(
                           v5,
                           v14,
                           v13,
                           v2,
                           1)
    || !(unsigned __int8)(*(int (__thiscall **)(int, int, signed int, int *, int *))(*(_DWORD *)v5 + 96))(
                           v5,
                           v5 + 184,
                           1,
                           &v15,
                           &v19) )
    goto LABEL_34;
  v7 = v19;
  if ( !v19 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    return 0;
  }
  if ( v1->sourceData.pfDesc.format == 500 )
  {
    ClipPlane::ClipPlane(&v21);
    PixelFormatDesc::SetFormat((PixelFormatDesc *)&v21, v2);
    v23.DIBWidth = v14;
    v23.DIBHeight = v13;
    v23.DIBChannels = 3;
    v23.DIBColor = 2;
    v23.DIBPadBytes = v15 - (v14 * (unsigned int)v22 >> 3);
    v23.DIBBytes = v19;
    v23.JPGColor = 3;
    if ( ijlRead(&v23, 3) )
      return 0;
    if ( ijlFree((int)&v23) )
      return 0;
  }
  else
  {
    v8 = v1->sourceData.sourceBits;
    if ( v1->sourceData.pfDesc.flags & 4 )
    {
      qmemcpy(v19, v8, v1->sourceData.imageSize);
    }
    else
    {
      v9 = v1->sourceData.width * v1->sourceData.pfDesc.bitsPerPixel >> 3;
      v16 = v1->sourceData.sourceBits;
      if ( v15 == v9 )
      {
        qmemcpy(v19, v8, v1->sourceData.imageSize);
      }
      else
      {
        v10 = v1->sourceData.height;
        v18 = 0;
        if ( v10 )
        {
          do
          {
            qmemcpy(
              v7,
              v8,
              4 * (v1->sourceData.width * v1->sourceData.pfDesc.bitsPerPixel >> 5)
            + ((v1->sourceData.width * v1->sourceData.pfDesc.bitsPerPixel >> 3) & 3));
            v7 = (char *)v7 + v15;
            v8 = &v16[v9];
            v11 = v18 + 1 < v1->sourceData.height;
            v16 += v9;
            ++v18;
          }
          while ( v11 );
          v5 = (int)v17;
        }
      }
    }
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 100))(v5);
  RenderSurface::DestroySourceSurfaceBits(v1);
  if ( !v12
    || (unsigned __int8)((int (__thiscall *)(RenderSurface *, int, int, PixelFormatID, signed int))v1->vfptr[3].AddRef)(
                          v1,
                          v14,
                          v13,
                          v20,
                          1)
    && (unsigned __int8)((int (__thiscall *)(RenderSurface *, int))v1->vfptr[4].IUnknown_Release)(v1, v5) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    result = 1;
  }
  else
  {
LABEL_34:
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    result = 0;
  }
  return result;
}

//----- (004443A0) --------------------------------------------------------  // acclient.c:128332
void RenderSurface::Allocator()
{
  RenderSurface *v1; // eax@4

  if ( DBCache::IsRunTime() )
  {
    if ( Render::m_pRenderer )
      ((void (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
  }
  else
  {
    v1 = (RenderSurface *)operator new(0x120u);
    if ( v1 )
      RenderSurface::RenderSurface(v1);
  }
}

//----- (004443E0) --------------------------------------------------------  // acclient.c:128350
void __thiscall RenderSurface::Destroy(RenderSurface *this)
{
  RenderSurface *v1; // esi@1

  v1 = this;
  if ( this->sourceData.sourceBits )
  {
    operator delete[](this->sourceData.sourceBits);
    v1->sourceData.sourceBits = 0;
  }
  if ( v1->m_pSurfaceBits )
  {
    operator delete[](v1->m_pSurfaceBits);
    v1->m_pSurfaceBits = 0;
  }
  RenderSurface::Begin(v1);
}

//----- (00444420) --------------------------------------------------------  // acclient.c:128369
void __thiscall RenderSurface::~RenderSurface(RenderSurface *this)
{
  RenderSurface *v1; // esi@1
  char *v2; // eax@1
  GraphicsResource *v3; // edi@1

  v1 = this;
  v2 = this->sourceData.sourceBits;
  v3 = (GraphicsResource *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&RenderSurface::vftable;
  this->vfptr = (GraphicsResourceVtbl *)&RenderSurface::vftable;
  if ( v2 )
  {
    operator delete[](v2);
    v1->sourceData.sourceBits = 0;
  }
  if ( v1->m_pSurfaceBits )
  {
    operator delete[](v1->m_pSurfaceBits);
    v1->m_pSurfaceBits = 0;
  }
  v1->window.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::End(&v1->window);
  GraphicsResource::~GraphicsResource(v3);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);
// 79967C: using guessed type void *RenderSurface::vftable;
// 799690: using guessed type __int32 (__stdcall *RenderSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00444490) --------------------------------------------------------  // acclient.c:128400
void __thiscall RenderSurface::GetSubDataIDs(RenderSurface *this, QualifiedDataIDArray *id_array)
{
  QualifiedDataID *v2; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, this->m_didPalatte, 0);
  QualifiedDataIDArray::AddQDID(id_array, v2, 0);
}

//----- (004444C0) --------------------------------------------------------  // acclient.c:128410
RenderSurface *__thiscall RenderSurface::scalar_deleting_destructor(RenderSurface *this, unsigned int a2)
{
  RenderSurface *v2; // esi@1

  v2 = this;
  RenderSurface::~RenderSurface(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004444E0) --------------------------------------------------------  // acclient.c:128422
void __thiscall RenderSurface::Serialize(RenderSurface *this, Archive *io_archive)
{
  Archive *v2; // ebp@1
  RenderSurface *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  PixelFormatID v6; // esi@9
  PixelFormatID v7; // edi@9
  unsigned int v8; // eax@9
  unsigned int v9; // eax@15
  unsigned int v10; // eax@20
  bool v11; // al@22
  unsigned int v12; // esi@30
  void *v13; // edi@30
  unsigned int v14; // eax@30
  unsigned int v15; // ecx@31
  const void *v16; // esi@32
  void *v17; // edi@32
  char v18; // al@32
  unsigned int v19; // ecx@32
  int v20; // edi@32
  int v21; // esi@32
  char v22; // cl@32
  char v23; // dl@33
  unsigned int v24; // ecx@33
  unsigned int v25; // eax@37
  Archive *io_archivea; // [sp+14h] [bp+4h]@9

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3->sourceData.width;
    else
      v3->sourceData.width = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v3->sourceData.height;
    else
      v3->sourceData.height = *(_DWORD *)v5;
  }
  v6 = v3->sourceData.pfDesc.format;
  io_archivea = (Archive *)v3->sourceData.pfDesc.format;
  v7 = v3->sourceData.pfDesc.format;
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v6;
    else
      v7 = *(_DWORD *)v8;
  }
  if ( !(v2->m_flags & 5) )
  {
    io_archivea = (Archive *)v7;
    v6 = v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v9 = Archive::GetBytes(v2, 4u);
  if ( v9 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v9 = v3->sourceData.imageSize;
    else
      v3->sourceData.imageSize = *(_DWORD *)v9;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
  {
    v10 = v3->m_dataCategory;
    v11 = v10 == 6 || v10 == 10;
    v3->m_AllowedInFreeList = v11;
    PixelFormatDesc::SetFormat(&v3->sourceData.pfDesc, v6);
    if ( !(v3->sourceData.pfDesc.flags & 0x10)
      && v3->sourceData.imageSize != v3->sourceData.width * v3->sourceData.height * v3->sourceData.pfDesc.bitsPerPixel >> 3 )
    {
      Archive::RaiseError(v2);
      return;
    }
    if ( v3->sourceData.sourceBits )
    {
      operator delete[](v3->sourceData.sourceBits);
      v3->sourceData.sourceBits = 0;
    }
    v3->sourceData.sourceBits = (char *)operator new[](v3->sourceData.imageSize);
  }
  v12 = v3->sourceData.imageSize;
  v13 = v3->sourceData.sourceBits;
  v14 = Archive::GetBytes(v2, v3->sourceData.imageSize);
  if ( v14 )
  {
    v15 = v12;
    if ( v2->m_flags & 1 )
    {
      v16 = v13;
      v17 = (void *)v14;
      v18 = v15;
      v19 = v15 >> 2;
      qmemcpy(v17, v16, 4 * v19);
      v21 = (int)((char *)v16 + 4 * v19);
      v20 = (int)((char *)v17 + 4 * v19);
      v22 = v18;
    }
    else
    {
      v23 = v12;
      v24 = v12 >> 2;
      qmemcpy(v13, (const void *)v14, 4 * (v12 >> 2));
      v21 = v14 + 4 * (v12 >> 2);
      v20 = (int)((char *)v13 + 4 * v24);
      v22 = v23;
    }
    qmemcpy((void *)v20, (const void *)v21, v22 & 3);
  }
  if ( io_archivea == (Archive *)41 || io_archivea == (Archive *)101 )
  {
    Archive::CheckAlignment(v2, 4u);
    v25 = Archive::GetBytes(v2, 4u);
    if ( v25 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v25 = v3->m_didPalatte.id;
      else
        v3->m_didPalatte.id = *(_DWORD *)v25;
    }
  }
}

//----- (006C7790) --------------------------------------------------------  // acclient.c:735478
void _E73_36()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_11, PFID_A8R8G8B8);
}

//----- (006C77A0) --------------------------------------------------------  // acclient.c:735484
int _E91_13()
{
  return atexit(_E92_18);
}

//----- (006C77B0) --------------------------------------------------------  // acclient.c:735490
int _E94_8()
{
  return atexit(nullsub_254);
}

//----- (006C77C0) --------------------------------------------------------  // acclient.c:735496
int _E97_13()
{
  return atexit(_E98_34);
}

//----- (006C77D0) --------------------------------------------------------  // acclient.c:735502
void _E100_13()
{
  LODWORD(dword_837F18) = 1053364187;
}

//----- (006C77E0) --------------------------------------------------------  // acclient.c:735508
void _E102_3()
{
  outside_val_9 = 1000.0 + 1.0;
}

//----- (006C7800) --------------------------------------------------------  // acclient.c:735514
void _E104_2()
{
  block_length_9 = 24.0 * 8.0;
}

//----- (006C7820) --------------------------------------------------------  // acclient.c:735520
void _E106_11()
{
  half_square_length_9 = 24.0 * 0.5;
}

//----- (006C7840) --------------------------------------------------------  // acclient.c:735526
int _E108_2()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_4, "Render.TextureFiltering");
  return atexit(sub_72A830);
}

//----- (006C7860) --------------------------------------------------------  // acclient.c:735533
int _E111_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_4, "Render.LandscapeDetailTextures");
  return atexit(sub_72A860);
}

//----- (006C7880) --------------------------------------------------------  // acclient.c:735540
int _E114_2()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_4, "Render.BuildingDetailTextures");
  return atexit(sub_72A890);
}

//----- (006C78A0) --------------------------------------------------------  // acclient.c:735547
int _E117_0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_4, "Render.FieldOfView");
  return atexit(sub_72A8C0);
}

//----- (006C78C0) --------------------------------------------------------  // acclient.c:735554
int _E120_1()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_4, "Render.LandscapeTextureDetail");
  return atexit(sub_72A8F0);
}

//----- (006C78E0) --------------------------------------------------------  // acclient.c:735561
int _E123_0()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_4, "Render.EnvironmentTextureDetail");
  return atexit(_E124_94);
}

//----- (006C7900) --------------------------------------------------------  // acclient.c:735568
int _E126_2()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_4, "Render.SceneryDrawDistance");
  return atexit(_E127_83);
}

//----- (006C7920) --------------------------------------------------------  // acclient.c:735575
int _E129_1()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_4, "Render.LandscapeDrawDistance");
  return atexit(_E130_75);
}

//----- (006C7940) --------------------------------------------------------  // acclient.c:735582
int _E132_2()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_4, "Render.ScreenBrightness");
  return atexit(_E133_68);
}

//----- (006C7960) --------------------------------------------------------  // acclient.c:735589
int _E135_1()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_4, "Render.AspectRatio");
  return atexit(_E136_52);
}

//----- (006C7980) --------------------------------------------------------  // acclient.c:735596
int _E138_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_4, "Render.DisplayAdapter");
  return atexit(_E139_53);
}

//----- (006C79A0) --------------------------------------------------------  // acclient.c:735603
int _E141_2()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_4, "Render.MaxHardwareClass");
  return atexit(_E142_50);
}

//----- (006C79C0) --------------------------------------------------------  // acclient.c:735610
int _E144_2()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_4, "Render.AutomaticDegrades");
  return atexit(_E145_52);
}

//----- (006C79E0) --------------------------------------------------------  // acclient.c:735617
int _E147_2()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_4, "Render.GraphicsPerformance");
  return atexit(_E148_51);
}

//----- (006C7A00) --------------------------------------------------------  // acclient.c:735624
int _E150_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_4, "Render.DegradeDistance");
  return atexit(_E151_49);
}

//----- (006C7A20) --------------------------------------------------------  // acclient.c:735631
int _E153_2()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_4, "Render.MultiPassAlpha");
  return atexit(_E154_50);
}

//----- (006C7A40) --------------------------------------------------------  // acclient.c:735638
int _E156_3()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_4, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_837F6C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_837F70, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_837F74, "Anisotropic");
  return atexit(_E157_47);
}

//----- (006C7A90) --------------------------------------------------------  // acclient.c:735648
int _E159_2()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_4, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837F7C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837F80, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837F84, "High");
  PStringBase<char>::PStringBase<char>(&stru_837F88, "VeryHigh");
  return atexit(_E160_50);
}

//----- (006C7AF0) --------------------------------------------------------  // acclient.c:735659
int _E162_3()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_4, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837F90, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837F94, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837F98, "High");
  PStringBase<char>::PStringBase<char>(&stru_837F9C, "VeryHigh");
  return atexit(_E163_43);
}

//----- (006C7B50) --------------------------------------------------------  // acclient.c:735670
int _E165_2()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837FA4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837FA8, "High");
  return atexit(_E166_45);
}

//----- (006C7B90) --------------------------------------------------------  // acclient.c:735679
int _E168_3()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_4, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837FB0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837FB4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837FB8, "High");
  PStringBase<char>::PStringBase<char>(&stru_837FBC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_837FC0, "Extreme");
  return atexit(_E169_44);
}

//----- (006C7C00) --------------------------------------------------------  // acclient.c:735691
int _E171_3()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_4, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_837FC8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_837FCC, "Wide");
  return atexit(_E172_42);
}

//----- (006C7C40) --------------------------------------------------------  // acclient.c:735700
int _E174_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_10, "None");
  return atexit(_E175_39);
}

//----- (006C7C60) --------------------------------------------------------  // acclient.c:735707
int _E177_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_10, "Speed");
  return atexit(_E178_39);
}

//----- (006C7C80) --------------------------------------------------------  // acclient.c:735714
int _E180_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_10, "Noise");
  return atexit(_E181_39);
}

//----- (006C7CA0) --------------------------------------------------------  // acclient.c:735721
int _E183_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_10, "Sine");
  return atexit(_E184_37);
}

//----- (006C7CC0) --------------------------------------------------------  // acclient.c:735728
int _E186_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_10, "Square");
  return atexit(_E187_36);
}

//----- (006C7CE0) --------------------------------------------------------  // acclient.c:735735
int _E189_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_10, "Bounce");
  return atexit(_E190_37);
}

//----- (006C7D00) --------------------------------------------------------  // acclient.c:735742
int _E192_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_10, "Perlin");
  return atexit(_E193_34);
}

//----- (006C7D20) --------------------------------------------------------  // acclient.c:735749
int _E195_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_10, "Fractal");
  return atexit(_E196_42);
}

//----- (006C7D40) --------------------------------------------------------  // acclient.c:735756
int _E198_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_10, "FrameLoop");
  return atexit(_E199_34);
}

//----- (006C7D60) --------------------------------------------------------  // acclient.c:735763
int _E1_33()
{
  return atexit(_E2_33);
}

//----- (0072A830) --------------------------------------------------------  // acclient.c:828694
void __cdecl sub_72A830()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A860) --------------------------------------------------------  // acclient.c:828707
void __cdecl sub_72A860()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A890) --------------------------------------------------------  // acclient.c:828720
void __cdecl sub_72A890()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A8C0) --------------------------------------------------------  // acclient.c:828733
void __cdecl sub_72A8C0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A8F0) --------------------------------------------------------  // acclient.c:828746
void __cdecl sub_72A8F0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A920) --------------------------------------------------------  // acclient.c:828759
void __cdecl _E124_94()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A950) --------------------------------------------------------  // acclient.c:828772
void __cdecl _E127_83()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A980) --------------------------------------------------------  // acclient.c:828785
void __cdecl _E130_75()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A9B0) --------------------------------------------------------  // acclient.c:828798
void __cdecl _E133_68()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A9E0) --------------------------------------------------------  // acclient.c:828811
void __cdecl _E136_52()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AA10) --------------------------------------------------------  // acclient.c:828824
void __cdecl _E139_53()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AA40) --------------------------------------------------------  // acclient.c:828837
void __cdecl _E142_50()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AA70) --------------------------------------------------------  // acclient.c:828850
void __cdecl _E145_52()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AAA0) --------------------------------------------------------  // acclient.c:828863
void __cdecl _E148_51()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AAD0) --------------------------------------------------------  // acclient.c:828876
void __cdecl _E151_49()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AB00) --------------------------------------------------------  // acclient.c:828889
void __cdecl _E154_50()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AB30) --------------------------------------------------------  // acclient.c:828902
void __cdecl _E157_47()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_4;
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

//----- (0072AB70) --------------------------------------------------------  // acclient.c:828927
void __cdecl _E160_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_4;
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

//----- (0072ABB0) --------------------------------------------------------  // acclient.c:828952
void __cdecl _E163_43()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_4;
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

//----- (0072ABF0) --------------------------------------------------------  // acclient.c:828977
void __cdecl _E166_45()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_4;
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

//----- (0072AC30) --------------------------------------------------------  // acclient.c:829002
void __cdecl _E169_44()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_4;
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

//----- (0072AC70) --------------------------------------------------------  // acclient.c:829027
void __cdecl _E172_42()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_10;
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

//----- (0072ACB0) --------------------------------------------------------  // acclient.c:829052
void __cdecl _E175_39()
{
  char *v0; // esi@1

  v0 = &waveform_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ACE0) --------------------------------------------------------  // acclient.c:829065
void __cdecl _E178_39()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AD10) --------------------------------------------------------  // acclient.c:829078
void __cdecl _E181_39()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AD40) --------------------------------------------------------  // acclient.c:829091
void __cdecl _E184_37()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AD70) --------------------------------------------------------  // acclient.c:829104
void __cdecl _E187_36()
{
  char *v0; // esi@1

  v0 = &waveform_Square_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ADA0) --------------------------------------------------------  // acclient.c:829117
void __cdecl _E190_37()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ADD0) --------------------------------------------------------  // acclient.c:829130
void __cdecl _E193_34()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AE00) --------------------------------------------------------  // acclient.c:829143
void __cdecl _E196_42()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AE30) --------------------------------------------------------  // acclient.c:829156
void __cdecl _E199_34()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

