/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTextureRenderer
   Object     : ENGINE\render_base\CTextureRenderer.obj
   Functions  : 32
   Addresses  : 006BC940 - 00791DA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BC940) --------------------------------------------------------  // acclient.c:724447
HRESULT __stdcall CTextureRenderer::CheckMediaType(CMediaType *pmt)
{
  HRESULT result; // eax@1

  result = -2147467259;
  if ( pmt )
  {
    if ( !memcmp(&pmt->formattype, &FORMAT_VideoInfo, 0x10u) )
    {
      if ( !memcmp(pmt, &MEDIATYPE_Video, 0x10u) && !memcmp(&pmt->subtype, &MEDIASUBTYPE_RGB24, 0x10u) )
        result = 0;
    }
    else
    {
      result = -2147024809;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (006BC9B0) --------------------------------------------------------  // acclient.c:724472
HRESULT __thiscall CTextureRenderer::SetMediaType(CTextureRenderer *this, CMediaType *pmt)
{
  char *v2; // eax@1

  v2 = pmt->pbFormat;
  this->m_lVidWidth = *((_DWORD *)v2 + 13);
  this->m_lVidHeight = abs(*((_DWORD *)v2 + 14));
  this->m_lVidPitch = 3 * (this->m_lVidWidth + 1) & 0xFFFFFFFC;
  return 0;
}

//----- (006BC9F0) --------------------------------------------------------  // acclient.c:724484
HRESULT __thiscall CTextureRenderer::DoRenderSample(CTextureRenderer *this, IMediaSample *pSample)
{
  CTextureRenderer *v2; // edi@1
  UISurface *v3; // esi@1
  RenderSurface *v4; // ebx@2
  int v5; // edx@2
  int v6; // ecx@2
  int v8; // ecx@9
  PixelFormatID v9; // eax@9
  int v10; // edx@9
  char *v11; // esi@9
  int v12; // eax@10
  char *v13; // edx@11
  char *v14; // ecx@12
  int v15; // esi@13
  unsigned int v16; // ebp@16
  int v17; // ecx@17
  bool v18; // cf@20
  int v19; // edx@24
  char *v20; // eax@24
  int v21; // ecx@25
  char *v22; // ebp@25
  int v23; // ebp@28
  bool v24; // sf@28
  unsigned __int8 v25; // of@28
  void *pTargetData; // [sp+18h] [bp-14h]@4
  int y; // [sp+1Ch] [bp-10h]@10
  RenderSurface *targetSurface; // [sp+20h] [bp-Ch]@2
  int SurfacePitch; // [sp+24h] [bp-8h]@4
  char *pTxtBufferOld; // [sp+28h] [bp-4h]@12

  v2 = this;
  v3 = this->m_pUISurface;
  if ( !v3 )
    return 0;
  UISurface::PrepareSurface(this->m_pUISurface);
  v4 = v3->m_pLocalSurface;
  v5 = v2->m_lVidWidth;
  v6 = v4->window.rect.right - v4->window.rect.left;
  targetSurface = v3->m_pLocalSurface;
  if ( v6 < (unsigned int)v5 || (unsigned int)(v4->window.rect.bottom - v4->window.rect.top) < v2->m_lVidHeight )
    return -2147418113;
  pTargetData = 0;
  if ( !(unsigned __int8)((int (__thiscall *)(RenderSurface *, int, signed int, int *, void **))v4->vfptr[4].IUnknown_QueryInterface)(
                           v4,
                           &v4->window.rect,
                           1,
                           &SurfacePitch,
                           &pTargetData) )
    return 0;
  if ( !pSample )
    return -2147467261;
  if ( !pTargetData )
    return -2147418113;
  ((void (__stdcall *)(IMediaSample *, IMediaSample **))pSample->vfptr[1].QueryInterface)(pSample, &pSample);
  v8 = v2->m_lVidHeight;
  v9 = v4->pfDesc.format;
  v10 = v2->m_lVidPitch * (v8 - 1);
  v11 = (char *)pSample + v10;
  pSample = (IMediaSample *)((char *)pSample + v10);
  if ( v9 != 21 )
  {
    if ( v9 == 25 )
    {
      y = 0;
      if ( v8 > 0 )
      {
        v19 = v2->m_lVidWidth;
        v20 = (char *)pTargetData;
        do
        {
          v21 = 0;
          v22 = v11;
          pTxtBufferOld = v20;
          if ( v19 > 0 )
          {
            do
            {
              v20 += 2;
              *((_WORD *)v20 - 1) = ((unsigned __int8)*v11 >> 3)
                                  + 4
                                  * ((unsigned __int8)(v11[1] & 0xF8) + 32 * ((unsigned __int8)(v11[2] & 0xF8) + 256));
              v19 = v2->m_lVidWidth;
              v11 = (char *)&pSample->vfptr + 3;
              ++v21;
              pSample = (IMediaSample *)((char *)pSample + 3);
            }
            while ( v21 < v19 );
            v4 = targetSurface;
          }
          v20 = &pTxtBufferOld[SurfacePitch];
          v11 = &v22[-v2->m_lVidPitch];
          v23 = v2->m_lVidHeight;
          v25 = __OFSUB__(y + 1, v23);
          v24 = y + 1 - v23 < 0;
          pSample = (IMediaSample *)v11;
          pTargetData = &pTxtBufferOld[SurfacePitch];
          ++y;
        }
        while ( v24 ^ v25 );
      }
    }
    goto LABEL_29;
  }
  v12 = v2->m_lVidWidth / 4;
  y = 0;
  if ( (unsigned int)v8 <= 0 )
  {
LABEL_29:
    ((void (__thiscall *)(RenderSurface *))v4->vfptr[4].IUnknown_AddRef)(v4);
    return 0;
  }
  v13 = (char *)pTargetData;
  do
  {
    pTxtBufferOld = v13;
    v14 = v11;
    if ( v12 )
    {
      v15 = v12;
      do
      {
        *(_DWORD *)v13 = *(_DWORD *)v14 | 0xFF000000;
        *((_DWORD *)v13 + 1) = ((*((_DWORD *)v14 + 1) | 0xFFFF0000) << 8) | (unsigned __int8)v14[3];
        *((_DWORD *)v13 + 2) = ((*((_DWORD *)v14 + 2) | 0xFFFFFF00) << 16) | *((_WORD *)v14 + 3);
        *((_DWORD *)v13 + 3) = (*((_DWORD *)v14 + 2) >> 8) | 0xFF000000;
        v13 += 16;
        v14 += 12;
        --v15;
      }
      while ( v15 );
      v11 = (char *)pSample;
    }
    v16 = 0;
    if ( v2->m_lVidWidth & 3 )
    {
      v17 = (int)(v14 + 1);
      do
      {
        *(_DWORD *)v13 = *(_BYTE *)(v17 - 1) | ((*(_BYTE *)v17 | ((*(_BYTE *)(v17 + 1) | 0xFFFFFF00) << 8)) << 8);
        v13 += 4;
        v17 += 3;
        ++v16;
      }
      while ( v16 < (v2->m_lVidWidth & 3u) );
      v11 = (char *)pSample;
    }
    v11 -= v2->m_lVidPitch;
    v13 = &pTxtBufferOld[SurfacePitch];
    v18 = (unsigned int)(y + 1) < v2->m_lVidHeight;
    pSample = (IMediaSample *)v11;
    pTargetData = &pTxtBufferOld[SurfacePitch];
    ++y;
  }
  while ( v18 );
  ((void (__thiscall *)(RenderSurface *))targetSurface->vfptr[4].IUnknown_AddRef)(targetSurface);
  return 0;
}

//----- (006BCCB0) --------------------------------------------------------  // acclient.c:724644
void __thiscall CTextureRenderer::CTextureRenderer(CTextureRenderer *this, IUnknown *pUnk, HRESULT *phr, UIElement *owner)
{
  CTextureRenderer *v4; // esi@1
  UIObject *v5; // eax@5
  UIRegion *v6; // ecx@6
  int v7; // eax@8
  int v8; // eax@9

  v4 = this;
  CBaseVideoRenderer::CBaseVideoRenderer(
    (CBaseVideoRenderer *)&this->vfptr,
    &_GUID_71771540_2017_11cf_ae26_0020afd79767,
    "Texture Renderer",
    pUnk,
    phr);
  v4->vfptr = (INonDelegatingUnknownVtbl *)&CTextureRenderer::vftable;
  v4->vfptr = (IUnknownVtbl *)&CBaseVideoRenderer::vftable;
  v4->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  v4->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  v4->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  v4->m_pUISurface = 0;
  if ( phr )
    *phr = 0;
  if ( (owner->m_nFlags >> 17) & 1 )
  {
    if ( (*((_DWORD *)&owner->0 + 41) >> 1) & 1 )
    {
      v5 = owner->m_object;
      if ( v5 || (v6 = owner->m_parent) != 0 && (v5 = UIRegion::GetObjectA(v6)) != 0 )
      {
        v7 = ((int (__thiscall *)(UIObject *))v5->vfptr[7].__vecDelDtor)(v5);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 272);
          v4->m_pUISurface = (UISurface *)v8;
          if ( v8 )
            ++*(_DWORD *)(v8 + 4);
        }
      }
    }
  }
}
// 806B74: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B9C: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806BD8: using guessed type __int32 (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806EA4: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);

//----- (006BCDD0) --------------------------------------------------------  // acclient.c:724732
HRESULT __stdcall CBaseVideoRenderer::QueryInterface(CBaseVideoRenderer *this, _GUID *a2, void **a3)
{
  return CBaseVideoRenderer::QueryInterface((CBaseInputPin *)&this[-1].m_InterfaceLock.m_CritSec.LockSemaphore, a2, a3);
}

//----- (006BCDE0) --------------------------------------------------------  // acclient.c:724738
int __stdcall CBaseVideoRenderer::AddRef(int a1)
{
  return CBaseVideoRenderer::AddRef((CBaseInputPin *)(a1 - 212));
}

//----- (006BCDF0) --------------------------------------------------------  // acclient.c:724744
int __stdcall CBaseVideoRenderer::Release(int a1)
{
  return CBaseFilter::Release((CBaseInputPin *)(a1 - 212));
}

//----- (006BCE00) --------------------------------------------------------  // acclient.c:724750
HRESULT __stdcall CBaseVideoRenderer::QueryInterface(CBaseVideoRenderer *this, _GUID *a2, void **a3)
{
  return CBaseVideoRenderer::QueryInterface((CBaseInputPin *)&this[-1].m_InterfaceLock.m_CritSec.OwningThread, a2, a3);
}

//----- (006BCE10) --------------------------------------------------------  // acclient.c:724756
int __stdcall CBaseVideoRenderer::AddRef(int a1)
{
  return CBaseVideoRenderer::AddRef((CBaseInputPin *)(a1 - 216));
}

//----- (006BCE20) --------------------------------------------------------  // acclient.c:724762
int __stdcall CBaseVideoRenderer::Release(int a1)
{
  return CBaseFilter::Release((CBaseInputPin *)(a1 - 216));
}

//----- (006BCE30) --------------------------------------------------------  // acclient.c:724768
void __thiscall CTextureRenderer::~CTextureRenderer(CTextureRenderer *this)
{
  CTextureRenderer *v1; // esi@1
  UISurface *v2; // ecx@1
  bool v3; // zf@2

  v1 = this;
  v2 = this->m_pUISurface;
  v1->vfptr = (INonDelegatingUnknownVtbl *)&CTextureRenderer::vftable;
  v1->vfptr = (IUnknownVtbl *)&CBaseVideoRenderer::vftable;
  v1->vfptr = (IUnknownVtbl *)&CBaseRenderer::vftable;
  v1->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  v1->vfptr = (IUnknownVtbl *)&CTextureRenderer::vftable;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pUISurface = 0;
  }
  CBaseVideoRenderer::~CBaseVideoRenderer((CBaseVideoRenderer *)&v1->vfptr);
}
// 806B74: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B88: using guessed type int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int);
// 806B9C: using guessed type __int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806BD8: using guessed type __int32 (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv);
// 806EA4: using guessed type int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int);

//----- (006BCE90) --------------------------------------------------------  // acclient.c:724797
CTextureRenderer *__thiscall CTextureRenderer::scalar_deleting_destructor(CTextureRenderer *this, unsigned int a2)
{
  CTextureRenderer *v2; // esi@1

  v2 = this;
  CTextureRenderer::~CTextureRenderer(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00724C20) --------------------------------------------------------  // acclient.c:822488
int sub_724C20()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_88, "None");
  return atexit(sub_791C20);
}

//----- (00724C40) --------------------------------------------------------  // acclient.c:822495
int sub_724C40()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_88, "Speed");
  return atexit(sub_791C50);
}

//----- (00724C60) --------------------------------------------------------  // acclient.c:822502
int sub_724C60()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_88, "Noise");
  return atexit(sub_791C80);
}

//----- (00724C80) --------------------------------------------------------  // acclient.c:822509
int _E82_76()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_88, "Sine");
  return atexit(_E83_72);
}

//----- (00724CA0) --------------------------------------------------------  // acclient.c:822516
int _E85_57()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_88, "Square");
  return atexit(_E86_49);
}

//----- (00724CC0) --------------------------------------------------------  // acclient.c:822523
int _E88_46()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_88, "Bounce");
  return atexit(_E89_59);
}

//----- (00724CE0) --------------------------------------------------------  // acclient.c:822530
int sub_724CE0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_88, "Perlin");
  return atexit(_E92_70);
}

//----- (00724D00) --------------------------------------------------------  // acclient.c:822537
int _E94_62()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_88, "Fractal");
  return atexit(sub_791D70);
}

//----- (00724D20) --------------------------------------------------------  // acclient.c:822544
int sub_724D20()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_88, "FrameLoop");
  return atexit(sub_791DA0);
}

//----- (00724D40) --------------------------------------------------------  // acclient.c:822551
void sub_724D40()
{
  PixelFormatDesc::PixelFormatDesc(&stru_905704, PFID_A8R8G8B8);
}

//----- (00724D50) --------------------------------------------------------  // acclient.c:822557
int sub_724D50()
{
  return atexit(nullsub_294);
}

//----- (00791C20) --------------------------------------------------------  // acclient.c:937893
void __cdecl sub_791C20()
{
  char *v0; // esi@1

  v0 = &waveform_None_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791C50) --------------------------------------------------------  // acclient.c:937906
void __cdecl sub_791C50()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791C80) --------------------------------------------------------  // acclient.c:937919
void __cdecl sub_791C80()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791CB0) --------------------------------------------------------  // acclient.c:937932
void __cdecl _E83_72()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791CE0) --------------------------------------------------------  // acclient.c:937945
void __cdecl _E86_49()
{
  char *v0; // esi@1

  v0 = &waveform_Square_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791D10) --------------------------------------------------------  // acclient.c:937958
void __cdecl _E89_59()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791D40) --------------------------------------------------------  // acclient.c:937971
void __cdecl _E92_70()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791D70) --------------------------------------------------------  // acclient.c:937984
void __cdecl sub_791D70()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791DA0) --------------------------------------------------------  // acclient.c:937997
void __cdecl sub_791DA0()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

#error "There were 2 decompilation failure(s) on 36603 function(s)"

