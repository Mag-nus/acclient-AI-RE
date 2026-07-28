/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MovieTheatre
   Object     : ENGINE\movie\MovieTheatre.obj
   Functions  : 15
   Addresses  : 006BC440 - 00724C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BC440) --------------------------------------------------------  // acclient.c:724089
unsigned __int16 *__stdcall AtlA2WHelper(unsigned __int16 *lpw, const char *lpa, int nChars, unsigned int acp)
{
  unsigned __int16 *result; // eax@2

  if ( lpw )
  {
    *lpw = 0;
    MultiByteToWideChar(acp, 0, lpa, -1, lpw, nChars);
    result = lpw;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006BC480) --------------------------------------------------------  // acclient.c:724107
HRESULT __thiscall ATL::CComPtrBase<IGraphBuilder>::QueryInterface(ATL::CComPtrBase<IGraphBuilder> *this, IMediaControl **pp)
{
  return this->p->vfptr->QueryInterface((IUnknown *)this->p, &_GUID_56a868b1_0ad4_11ce_b03a_0020af0ba770, (void **)pp);
}

//----- (006BC4A0) --------------------------------------------------------  // acclient.c:724113
HRESULT __thiscall ATL::CComPtrBase<IGraphBuilder>::QueryInterface(ATL::CComPtrBase<IGraphBuilder> *this, IMediaPosition **pp)
{
  return this->p->vfptr->QueryInterface((IUnknown *)this->p, &_GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770, (void **)pp);
}

//----- (006BC4C0) --------------------------------------------------------  // acclient.c:724119
HRESULT __thiscall ATL::CComPtrBase<IGraphBuilder>::QueryInterface(ATL::CComPtrBase<IGraphBuilder> *this, IMediaEvent **pp)
{
  return this->p->vfptr->QueryInterface((IUnknown *)this->p, &_GUID_56a868b6_0ad4_11ce_b03a_0020af0ba770, (void **)pp);
}

//----- (006BC4E0) --------------------------------------------------------  // acclient.c:724125
void __thiscall MovieTheatre::~MovieTheatre(MovieTheatre *this)
{
  MovieTheatre *v1; // esi@1
  IMediaControl *v2; // eax@1
  IMediaControl *v3; // eax@3
  IMediaEvent *v4; // eax@5
  IMediaPosition *v5; // eax@7
  IGraphBuilder *v6; // eax@9
  IBaseFilter *v7; // eax@11
  IBaseFilter *v8; // eax@13
  IMediaEvent *v9; // eax@15
  IMediaPosition *v10; // eax@17
  IMediaControl *v11; // eax@19
  IGraphBuilder *v12; // eax@21

  v1 = this;
  v2 = this->m_pMC.p;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&MovieTheatre::vftable;
  if ( v2 )
    ((void (__stdcall *)(IMediaControl *))v2->vfptr[3].QueryInterface)(v2);
  v3 = v1->m_pMC.p;
  if ( v3 )
  {
    v1->m_pMC.p = 0;
    v3->vfptr->Release((IUnknown *)v3);
  }
  v4 = v1->m_pME.p;
  if ( v4 )
  {
    v1->m_pME.p = 0;
    v4->vfptr->Release((IUnknown *)v4);
  }
  v5 = v1->m_pMP.p;
  if ( v5 )
  {
    v1->m_pMP.p = 0;
    v5->vfptr->Release((IUnknown *)v5);
  }
  v6 = v1->m_pGB.p;
  if ( v6 )
  {
    v1->m_pGB.p = 0;
    v6->vfptr->Release((IUnknown *)v6);
  }
  v7 = v1->m_pRenderer.p;
  if ( v7 )
  {
    v1->m_pRenderer.p = 0;
    v7->vfptr->Release((IUnknown *)v7);
  }
  v8 = v1->m_pRenderer.p;
  if ( v8 )
    v8->vfptr->Release((IUnknown *)v1->m_pRenderer.p);
  v9 = v1->m_pME.p;
  if ( v9 )
    v9->vfptr->Release((IUnknown *)v1->m_pME.p);
  v10 = v1->m_pMP.p;
  if ( v10 )
    v10->vfptr->Release((IUnknown *)v1->m_pMP.p);
  v11 = v1->m_pMC.p;
  if ( v11 )
    v11->vfptr->Release((IUnknown *)v1->m_pMC.p);
  v12 = v1->m_pGB.p;
  if ( v12 )
    v12->vfptr->Release((IUnknown *)v1->m_pGB.p);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 806B2C: using guessed type int (__thiscall *MovieTheatre::vftable)(void *, char);

//----- (006BC5B0) --------------------------------------------------------  // acclient.c:724196
char __thiscall MovieTheatre::HasFinishedPlaying(MovieTheatre *this)
{
  MovieTheatre *v1; // esi@1
  IMediaEvent *v2; // eax@1
  char v3; // bl@1
  char result; // al@3
  IMediaControl *v5; // eax@8
  int lEventCode; // [sp+18h] [bp-Ch]@4
  int lParam2; // [sp+1Ch] [bp-8h]@4
  int lParam1; // [sp+20h] [bp-4h]@4

  v1 = this;
  v2 = this->m_pME.p;
  v3 = 0;
  if ( v2 && !this->m_bStopped )
  {
    if ( ((int (__stdcall *)(IMediaEvent *, int *, int *, int *, _DWORD))v2->vfptr[2].Release)(
           v2,
           &lEventCode,
           &lParam1,
           &lParam2,
           0) >= 0 )
    {
      if ( lEventCode == 1 )
      {
        if ( v1->m_Flags & 1 )
        {
          ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))v1->m_pMP.p->vfptr[2].Release)(v1->m_pMP.p, 0, 0);
        }
        else
        {
          v5 = v1->m_pMC.p;
          if ( v5 )
            ((void (__stdcall *)(IMediaControl *))v5->vfptr[3].QueryInterface)(v1->m_pMC.p);
          v1->m_bStopped = 1;
          v3 = 1;
        }
      }
      ((void (__stdcall *)(_DWORD, int, int, int))v1->m_pME.p->vfptr[4].QueryInterface)(
        v1->m_pME.p,
        lEventCode,
        lParam1,
        lParam2);
    }
    result = v3;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006BC640) --------------------------------------------------------  // acclient.c:724250
MovieTheatre *__thiscall MovieTheatre::vector_deleting_destructor(MovieTheatre *this, unsigned int a2)
{
  MovieTheatre *v2; // esi@1

  v2 = this;
  MovieTheatre::~MovieTheatre(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006BC660) --------------------------------------------------------  // acclient.c:724262
char __thiscall MovieTheatre::Init(MovieTheatre *this, PStringBase<char> *i_strFilename, UIElement *i_pOwner, const unsigned int _Flags)
{
  MovieTheatre *v4; // esi@1
  UIElement *v5; // ecx@1
  int v6; // ebx@1
  CTextureRenderer *v8; // eax@6
  int v9; // eax@7
  int v10; // edi@11
  IBaseFilter *v11; // eax@13
  const unsigned int v12; // eax@16
  int v13; // eax@17
  void *v14; // esp@17
  const wchar_t *v15; // eax@17
  HRESULT v16; // eax@17
  HRESULT v17; // eax@25
  bool v18; // sf@25
  UIElement *v19; // eax@28
  bool v20; // zf@28
  int v21; // [sp+0h] [bp-31Ch]@17
  unsigned __int16 wFileName[260]; // [sp+Ch] [bp-310h]@17
  char strFileName[260]; // [sp+214h] [bp-108h]@17
  HRESULT hr; // [sp+318h] [bp-4h]@6
  unsigned int _acp; // [sp+324h] [bp+8h]@17

  v4 = this;
  v5 = i_pOwner;
  v6 = (int)&v4->m_pGB;
  v4->m_Flags = _Flags;
  v4->m_pOwner = v5;
  i_pOwner = 0;
  _Flags = 0;
  if ( CoCreateInstance(&CLSID_FilterGraph, 0, 3u, &_GUID_56a868a9_0ad4_11ce_b03a_0020af0ba770, (LPVOID *)&v4->m_pGB.p) < 0 )
  {
    if ( _Flags )
      (*(void (__stdcall **)(const unsigned int))(*(_DWORD *)_Flags + 8))(_Flags);
    if ( i_pOwner )
    {
      ((void (__stdcall *)(UIElement *))i_pOwner->vfptr->OnLoseFocus)(i_pOwner);
      return 0;
    }
    return 0;
  }
  hr = 0;
  v8 = (CTextureRenderer *)operator new(0x178u);
  if ( v8 )
    CTextureRenderer::CTextureRenderer(v8, 0, &hr, v4->m_pOwner);
  else
    v9 = 0;
  if ( hr < 0 || !v9 )
  {
    if ( _Flags )
      (*(void (__stdcall **)(const unsigned int))(*(_DWORD *)_Flags + 8))(_Flags);
    v19 = i_pOwner;
    v20 = i_pOwner == 0;
    goto LABEL_37;
  }
  v10 = v9 + 12;
  if ( v9 != -12 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 4))(v9 + 12);
  v11 = v4->m_pRenderer.p;
  if ( v11 )
    v11->vfptr->Release((IUnknown *)v4->m_pRenderer.p);
  v4->m_pRenderer.p = (IBaseFilter *)v10;
  hr = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)v6 + 12))(*(_DWORD *)v6, v10, L"TEXTURERENDERER");
  if ( hr < 0 )
  {
    v12 = _Flags;
LABEL_26:
    if ( v12 )
      (*(void (__stdcall **)(const unsigned int))(*(_DWORD *)v12 + 8))(v12);
    v19 = i_pOwner;
    v20 = i_pOwner == 0;
LABEL_37:
    if ( !v20 )
      ((void (__stdcall *)(UIElement *))v19->vfptr->OnLoseFocus)(v19);
    return 0;
  }
  lstrcpyA(strFileName, i_strFilename->m_charbuffer->m_data);
  _acp = ((unsigned int (__stdcall *)())ATL::g_pfnGetThreadACP)();
  v13 = lstrlenA(strFileName);
  v14 = alloca(2 * (v13 + 1));
  v15 = AtlA2WHelper((unsigned __int16 *)&v21, strFileName, v13 + 1, _acp);
  _wcsncpy(wFileName, v15, 0x104u);
  v16 = (*(int (__stdcall **)(_DWORD, unsigned __int16 *, _DWORD, UIElement **))(**(_DWORD **)v6 + 56))(
          *(_DWORD *)v6,
          wFileName,
          L"SOURCE",
          &i_pOwner);
  hr = v16;
  if ( v16 == -2147220970 )
  {
    v12 = _Flags;
    goto LABEL_26;
  }
  if ( v16 < 0 )
  {
    v12 = _Flags;
    goto LABEL_26;
  }
  hr = ((int (__stdcall *)(UIElement *, _DWORD, const unsigned int *))i_pOwner->vfptr[3].OnLoseFocus)(
         i_pOwner,
         L"Output",
         &_Flags);
  if ( hr < 0 )
  {
    v12 = _Flags;
    goto LABEL_26;
  }
  hr = (*(int (__stdcall **)(_DWORD, const unsigned int))(**(_DWORD **)v6 + 48))(*(_DWORD *)v6, _Flags);
  if ( hr < 0 )
  {
    v12 = _Flags;
    goto LABEL_26;
  }
  ATL::CComPtrBase<IGraphBuilder>::QueryInterface((ATL::CComPtrBase<IGraphBuilder> *)&v4->m_pGB.p, &v4->m_pMC.p);
  ATL::CComPtrBase<IGraphBuilder>::QueryInterface((ATL::CComPtrBase<IGraphBuilder> *)&v4->m_pGB.p, &v4->m_pMP.p);
  ATL::CComPtrBase<IGraphBuilder>::QueryInterface((ATL::CComPtrBase<IGraphBuilder> *)&v4->m_pGB.p, &v4->m_pME.p);
  v17 = v4->m_pMC.p->vfptr[2].AddRef((IUnknown *)v4->m_pMC.p);
  hr = v17;
  v18 = v17 < 0;
  v12 = _Flags;
  if ( v18 )
    goto LABEL_26;
  v4->m_bStopped = 0;
  if ( v12 )
    (*(void (__stdcall **)(const unsigned int))(*(_DWORD *)v12 + 8))(v12);
  if ( i_pOwner )
    ((void (__stdcall *)(UIElement *))i_pOwner->vfptr->OnLoseFocus)(i_pOwner);
  return 1;
}
// 81FA8C: invalid function type has been ignored
// 806B30: using guessed type wchar_t aOutput[7];
// 806B40: using guessed type wchar_t aSource[7];
// 806B50: using guessed type wchar_t aTexturerendere[16];

//----- (006BC8B0) --------------------------------------------------------  // acclient.c:724398
TResult *__cdecl MovieTheatre::CreateTheatreForMovie(TResult *result, PStringBase<char> *_FileName, const unsigned int _Flags, UIElement *i_pOwner, MovieTheatre **_pOutMovieTheatre)
{
  void *v5; // eax@1
  TResult *v6; // eax@6
  MovieTheatre *v7; // ecx@7
  bool v8; // zf@8

  v5 = operator new(0x28u);
  if ( v5 )
  {
    *((_DWORD *)v5 + 1) = 1;
    *(_DWORD *)v5 = &MovieTheatre::vftable;
    *((_DWORD *)v5 + 2) = 0;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 5) = 0;
    *((_DWORD *)v5 + 6) = 0;
    *((_DWORD *)v5 + 7) = 0;
    *((_DWORD *)v5 + 8) = 0;
    *((_DWORD *)v5 + 9) = 0;
  }
  else
  {
    v5 = 0;
  }
  *_pOutMovieTheatre = (MovieTheatre *)v5;
  if ( v5 )
  {
    if ( MovieTheatre::Init((MovieTheatre *)v5, _FileName, i_pOwner, _Flags) )
    {
      v6 = result;
      result->m_val = 0;
      return v6;
    }
    v7 = *_pOutMovieTheatre;
    if ( *_pOutMovieTheatre )
    {
      v8 = v7->m_cRef-- == 1;
      if ( v8 )
        ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
      *_pOutMovieTheatre = 0;
    }
  }
  v6 = result;
  result->m_val = -2147467259;
  return v6;
}
// 806B2C: using guessed type int (__thiscall *MovieTheatre::vftable)(void *, char);

//----- (00724B90) --------------------------------------------------------  // acclient.c:822452
void _E74_0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_905684, PFID_A8R8G8B8);
}

//----- (00724BA0) --------------------------------------------------------  // acclient.c:822458
void _E92_8()
{
  LODWORD(dword_9056C0) = 1053364187;
}

//----- (00724BB0) --------------------------------------------------------  // acclient.c:822464
void _E94_61()
{
  flt_9056C4 = 1000.0 + 1.0;
}

//----- (00724BD0) --------------------------------------------------------  // acclient.c:822470
void _E96_2()
{
  flt_9056C8 = 24.0 * 8.0;
}

//----- (00724BF0) --------------------------------------------------------  // acclient.c:822476
void _E98_21()
{
  flt_9056CC = 24.0 * 0.5;
}

//----- (00724C10) --------------------------------------------------------  // acclient.c:822482
int sub_724C10()
{
  return atexit(nullsub_247);
}

