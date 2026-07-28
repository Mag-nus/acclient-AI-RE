/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderSurfaceD3D
   Object     : ENGINE\render_base\RenderSurfaceD3D.obj
   Functions  : 16
   Addresses  : 00695C90 - 0071A010 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00695C90) --------------------------------------------------------  // acclient.c:685663
char __thiscall RenderSurfaceD3D::CreateFromD3DSurface(RenderSurfaceD3D *this, IDirect3DSurface9 *_pExistingSurface, const bool _CountAsSystemMemory, const bool _CountAsVideoMemory)
{
  RenderSurfaceD3D *v4; // esi@1
  unsigned int v5; // eax@3
  char result; // al@5
  _D3DSURFACE_DESC desc; // [sp+8h] [bp-20h]@2

  v4 = this;
  if ( _pExistingSurface
    && (((void (__stdcall *)(_DWORD, _DWORD))_pExistingSurface->vfptr[4].QueryInterface)(_pExistingSurface, &desc),
        RenderSurface::Create((RenderSurface *)&v4->vfptr, desc.Width, desc.Height, (PixelFormatID)desc.Format, 0)) )
  {
    v5 = v4->width * v4->height * v4->pfDesc.bitsPerPixel >> 3;
    v4->m_pD3DSurface = _pExistingSurface;
    v4->size = v5;
    GraphicsResource::SetResourceSize((GraphicsResource *)&v4->vfptr, v5);
    v4->m_CountAsSystemMemory = _CountAsSystemMemory;
    v4->m_CountAsVideoMemory = _CountAsVideoMemory;
    if ( _CountAsVideoMemory )
      g_nTotalSurfaceRemoteBytes += v4->size;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8F89C4: using guessed type __int32 g_nTotalSurfaceRemoteBytes;

//----- (00695D30) --------------------------------------------------------  // acclient.c:685694
IDirect3DSurface9 *__thiscall RenderSurfaceD3D::GetDirect3DSurface(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1
  IDirect3DSurface9 *result; // eax@3
  int v3; // edx@4

  v1 = this;
  if ( !this->m_bIsLost || this->vfptr->RestoreResource((GraphicsResource *)&this->vfptr) )
  {
    v3 = HIDWORD(Timer::local_time);
    LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
    HIDWORD(v1->m_TimeUsed) = v3;
    if ( RenderDevice::render_device )
      v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
    result = v1->m_pD3DSurface;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00695D80) --------------------------------------------------------  // acclient.c:685718
char __userpurge RenderSurfaceD3D::Convert@<al>(RenderSurfaceD3D *this@<ecx>, void **a2@<edi>, RenderSurface *source)
{
  RenderSurfaceD3D *v3; // esi@1
  struct IDirect3DSurface9 *v4; // ST0C_4@3
  struct IDirect3DSurface9 *v5; // eax@3
  char result; // al@3

  v3 = this;
  if ( this->m_pSurfaceBits || source->m_pSurfaceBits )
  {
    result = RenderSurface::Convert((RenderSurface *)&this->vfptr, source);
  }
  else
  {
    v4 = RenderSurfaceD3D::GetDirect3DSurface((RenderSurfaceD3D *)source);
    v5 = RenderSurfaceD3D::GetDirect3DSurface(v3);
    D3DXLoadSurfaceFromSurface(a2, v5, 0, 0, v4, 0, 0, 2u, 0);
    result = 1;
    v3->m_IsDirty = 1;
  }
  return result;
}

//----- (00695DE0) --------------------------------------------------------  // acclient.c:685742
char __thiscall RenderSurfaceD3D::CreateD3DSurface(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1
  unsigned int v2; // ST18_4@2

  v1 = this;
  if ( !this->m_pSurfaceBits )
  {
    (*(void (__stdcall **)(_DWORD, unsigned int, unsigned int, PixelFormatID, _D3DPOOL, IDirect3DSurface9 **, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 144))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      this->width,
      this->height,
      this->pfDesc.format,
      this->m_pool,
      &this->m_pD3DSurface,
      0);
    v2 = v1->width * v1->height * v1->pfDesc.bitsPerPixel >> 3;
    v1->size = v2;
    GraphicsResource::SetResourceSize((GraphicsResource *)&v1->vfptr, v2);
    if ( v1->m_CountAsVideoMemory )
      g_nTotalSurfaceRemoteBytes += v1->size;
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
  return 1;
}
// 8F89C4: using guessed type __int32 g_nTotalSurfaceRemoteBytes;

//----- (00695E70) --------------------------------------------------------  // acclient.c:685770
char __thiscall RenderSurfaceD3D::PurgeResource(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1
  char result; // al@1
  unsigned int v3; // eax@3
  char v4; // al@4

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    if ( !v1->pfDesc.fourCC )
    {
      v3 = v1->pfDesc.greenBitMask;
      if ( v3 )
      {
        (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v3 + 8))(v1->pfDesc.greenBitMask);
        v4 = BYTE1(v1->pfDesc.alphaBitMask);
        v1->pfDesc.greenBitMask = 0;
        if ( v4 )
          g_nTotalSurfaceRemoteBytes -= (__int32)v1->m_pMaintainer;
      }
    }
    result = 1;
  }
  return result;
}
// 8F89C4: using guessed type __int32 g_nTotalSurfaceRemoteBytes;

//----- (00695EC0) --------------------------------------------------------  // acclient.c:685800
void __thiscall RenderSurfaceD3D::RenderSurfaceD3D(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1

  v1 = this;
  RenderSurface::RenderSurface((RenderSurface *)&this->vfptr);
  v1->m_pD3DSurface = 0;
  v1->m_CountAsSystemMemory = 0;
  v1->m_CountAsVideoMemory = 0;
  v1->vfptr = (InterfaceVtbl *)&RenderSurfaceD3D::vftable;
  v1->vfptr = (GraphicsResourceVtbl *)&RenderSurfaceD3D::vftable;
  v1->m_pool = 3;
}
// 800904: using guessed type void *RenderSurfaceD3D::vftable;
// 800918: using guessed type __int32 (__stdcall *RenderSurfaceD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00695F00) --------------------------------------------------------  // acclient.c:685817
RenderSurfaceD3D *__thiscall RenderSurfaceD3D::vector_deleting_destructor(RenderSurfaceD3D *this, unsigned int a2)
{
  return RenderSurfaceD3D::scalar_deleting_destructor((RenderSurfaceD3D *)((char *)this - 48), a2);
}

//----- (00695F10) --------------------------------------------------------  // acclient.c:685823
char __thiscall RenderSurfaceD3D::Create(RenderSurfaceD3D *this, unsigned int _width, unsigned int _height, PixelFormatID _pixelFormat, bool _bLocalData)
{
  RenderSurfaceD3D *v5; // esi@1
  void *v6; // eax@2
  bool v7; // zf@2
  unsigned int v9; // ST0C_4@5

  v5 = this;
  if ( !RenderSurface::Create((RenderSurface *)&this->vfptr, _width, _height, _pixelFormat, 0) )
    return 0;
  v6 = v5->m_pSurfaceBits;
  v7 = v6 == 0;
  if ( !v6 )
  {
    if ( !RenderSurfaceD3D::CreateD3DSurface(v5) )
      return 0;
    v9 = v5->width * v5->height * v5->pfDesc.bitsPerPixel >> 3;
    v5->size = v9;
    GraphicsResource::SetResourceSize((GraphicsResource *)&v5->vfptr, v9);
    v7 = v5->m_pSurfaceBits == 0;
  }
  v5->m_CountAsSystemMemory = v7;
  v5->m_CountAsVideoMemory = 0;
  return 1;
}

//----- (00695F90) --------------------------------------------------------  // acclient.c:685850
void __thiscall RenderSurfaceD3D::Destroy(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1
  IDirect3DSurface9 *v2; // eax@2
  bool v3; // zf@3

  v1 = this;
  if ( !this->m_pSurfaceBits )
  {
    v2 = this->m_pD3DSurface;
    if ( v2 )
    {
      v2->vfptr->Release((IUnknown *)this->m_pD3DSurface);
      v3 = v1->m_CountAsVideoMemory == 0;
      v1->m_pD3DSurface = 0;
      if ( !v3 )
        g_nTotalSurfaceRemoteBytes -= v1->m_nResourceSize;
    }
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
  RenderSurface::Destroy((RenderSurface *)&v1->vfptr);
  v1->m_pD3DSurface = 0;
  v1->m_CountAsSystemMemory = 0;
  v1->m_CountAsVideoMemory = 0;
}
// 8F89C4: using guessed type __int32 g_nTotalSurfaceRemoteBytes;

//----- (00695FF0) --------------------------------------------------------  // acclient.c:685878
char __thiscall RenderSurfaceD3D::Lock(RenderSurfaceD3D *this, tagRECT *rect, const unsigned int flags, int *_pitch, void **_data)
{
  RenderSurfaceD3D *v5; // esi@1
  char result; // al@3
  signed int v7; // ecx@6
  void *v8; // eax@10
  _D3DLOCKED_RECT lockedRect; // [sp+10h] [bp-8h]@10

  v5 = this;
  if ( this->m_pSurfaceBits || RenderSurfaceD3D::GetDirect3DSurface(this) )
  {
    result = RenderSurface::Lock((RenderSurface *)&v5->vfptr, rect, flags, _pitch, _data);
    if ( result )
    {
      if ( !v5->m_pSurfaceBits )
      {
        v7 = 2048;
        if ( flags & 2 )
          v7 = 2064;
        if ( flags & 4 )
          v7 |= 0x8000u;
        ((void (__stdcall *)(_DWORD, _D3DLOCKED_RECT *, tagRECT *, signed int))v5->m_pD3DSurface->vfptr[4].AddRef)(
          v5->m_pD3DSurface,
          &lockedRect,
          rect,
          v7);
        v8 = lockedRect.pBits;
        *_pitch = lockedRect.Pitch;
        *_data = v8;
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00696090) --------------------------------------------------------  // acclient.c:685919
void __thiscall RenderSurfaceD3D::Unlock(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1

  v1 = this;
  if ( !this->m_pSurfaceBits )
  {
    if ( !RenderSurfaceD3D::GetDirect3DSurface(this) )
      return;
    v1->m_pD3DSurface->vfptr[4].Release((IUnknown *)v1->m_pD3DSurface);
  }
  RenderSurface::Unlock((RenderSurface *)&v1->vfptr);
}

//----- (006960C0) --------------------------------------------------------  // acclient.c:685934
bool __thiscall RenderSurfaceD3D::RestoreResource(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1

  v1 = this;
  return GraphicsResource::RestoreResource((GraphicsResource *)this)
      && (v1->pfDesc.fourCC
       || *(_DWORD *)&v1[-1].m_CountAsSystemMemory != stru_8F8A0C.id
       && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)&v1[-1].pfDesc.redBitOffset + 84))(&v1[-1].pfDesc.redBitOffset)
       || RenderSurfaceD3D::CreateD3DSurface((RenderSurfaceD3D *)((char *)v1 - 48)));
}

//----- (00696110) --------------------------------------------------------  // acclient.c:685947
void __thiscall RenderSurfaceD3D::~RenderSurfaceD3D(RenderSurfaceD3D *this)
{
  RenderSurfaceD3D *v1; // esi@1
  void *v2; // eax@1
  GraphicsResource *v3; // edi@1
  IDirect3DSurface9 *v4; // eax@2
  bool v5; // al@3

  v1 = this;
  v2 = this->m_pSurfaceBits;
  v3 = (GraphicsResource *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&RenderSurfaceD3D::vftable;
  this->vfptr = (GraphicsResourceVtbl *)&RenderSurfaceD3D::vftable;
  if ( !v2 )
  {
    v4 = this->m_pD3DSurface;
    if ( v4 )
    {
      v4->vfptr->Release((IUnknown *)this->m_pD3DSurface);
      v5 = v1->m_CountAsVideoMemory;
      v1->m_pD3DSurface = 0;
      if ( v5 )
        g_nTotalSurfaceRemoteBytes -= v1->m_nResourceSize;
    }
  }
  GraphicsResource::MarkResourceAsNotLost(v3);
  RenderSurface::~RenderSurface((RenderSurface *)&v1->vfptr);
}
// 800904: using guessed type void *RenderSurfaceD3D::vftable;
// 800918: using guessed type __int32 (__stdcall *RenderSurfaceD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8F89C4: using guessed type __int32 g_nTotalSurfaceRemoteBytes;

//----- (00696170) --------------------------------------------------------  // acclient.c:685980
RenderSurfaceD3D *__thiscall RenderSurfaceD3D::scalar_deleting_destructor(RenderSurfaceD3D *this, unsigned int a2)
{
  RenderSurfaceD3D *v2; // esi@1

  v2 = this;
  RenderSurfaceD3D::~RenderSurfaceD3D(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0071A000) --------------------------------------------------------  // acclient.c:812565
void sub_71A000()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F89D4, PFID_A8R8G8B8);
}

//----- (0071A010) --------------------------------------------------------  // acclient.c:812571
int sub_71A010()
{
  return atexit(nullsub_257);
}

