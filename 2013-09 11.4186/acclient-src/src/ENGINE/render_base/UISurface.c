/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UISurface
   Object     : ENGINE\render_base\UISurface.obj
   Functions  : 78
   Addresses  : 00440650 - 0072A780 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00440650) --------------------------------------------------------  // acclient.c:124660
void __thiscall UISurface::UISurface(UISurface *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UISurface::vftable;
  this->m_pLocalTexture = 0;
  this->m_pLocalSurface = 0;
  this->m_pRemoteTexture = 0;
  this->m_pVertexBuffer = 0;
  this->m_bHasAlpha = 0;
  this->m_nPhysicalWidth = 0;
  this->m_nPhysicalHeight = 0;
  this->m_IsInitialized = 0;
}
// 7995B0: using guessed type int (__thiscall *UISurface::vftable)(void *, char);

//----- (00440680) --------------------------------------------------------  // acclient.c:124676
char __usercall UISurface::SetupVertexBuffer@<al>(UISurface *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  UISurface *v3; // esi@1
  RenderVertexBuffer *v4; // ecx@1
  bool v5; // zf@2
  RenderVertexBuffer *v6; // eax@5
  char v7; // al@5
  RenderVertexBuffer *v8; // ecx@5
  char result; // al@10
  int v10; // eax@11
  RenderTexture *v11; // ecx@11
  double v12; // st7@11
  double v13; // st6@11
  int v14; // [sp+1Ch] [bp-8h]@1
  UISurface *v15; // [sp+20h] [bp-4h]@1

  v15 = this;
  v14 = a3;
  v3 = this;
  v4 = this->m_pVertexBuffer;
  if ( v4 )
  {
    v5 = v4->m_cRef-- == 1;
    if ( v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    v3->m_pVertexBuffer = 0;
  }
  RenderVertexBuffer::AllocateVertexBuffer();
  v3->m_pVertexBuffer = v6;
  v7 = ((int (__thiscall *)(RenderVertexBuffer *, signed int, signed int, signed int, signed int, signed int))v6->vfptr[1].__vecDelDtor)(
         v6,
         4,
         258,
         1,
         1,
         -1);
  v8 = v3->m_pVertexBuffer;
  if ( v7 )
  {
    v10 = ((int (__stdcall *)(_DWORD, unsigned int, int, int))v8->vfptr[3].__vecDelDtor)(0, v8->numVertices, a2, v14);
    v11 = v3->m_pLocalTexture;
    v12 = (double)(v3->m_nPhysicalWidth - 1) / (double)(v11->m_nWidth - 1);
    v13 = (double)(v3->m_nPhysicalHeight - 1) / (double)(v11->m_nHeight - 1);
    *(_DWORD *)(v10 + 4) = 0;
    *(_DWORD *)(v10 + 12) = 0;
    *(_DWORD *)(v10 + 16) = 0;
    *(_DWORD *)v10 = -1090519040;
    *(_DWORD *)(v10 + 8) = 1056964608;
    *(_DWORD *)(v10 + 20) = 1056964608;
    *(_DWORD *)(v10 + 24) = 0;
    *(_DWORD *)(v10 + 28) = 1056964608;
    *(_DWORD *)(v10 + 36) = 0;
    *(float *)(v10 + 32) = v12;
    *(_DWORD *)(v10 + 40) = -1090519040;
    *(_DWORD *)(v10 + 44) = 0;
    *(_DWORD *)(v10 + 48) = -1090519040;
    *(float *)(v10 + 56) = v13;
    *(_DWORD *)(v10 + 52) = 0;
    *(_DWORD *)(v10 + 60) = 1056964608;
    *(_DWORD *)(v10 + 64) = 0;
    *(_DWORD *)(v10 + 68) = -1090519040;
    *(float *)(v10 + 72) = v12;
    *(float *)(v10 + 76) = v13;
    ((void (__cdecl *)(signed int, _DWORD, UISurface *))v3->m_pVertexBuffer->vfptr[4].__vecDelDtor)(1, 0, v15);
    result = 1;
  }
  else
  {
    if ( v8 )
    {
      v5 = v8->m_cRef-- == 1;
      if ( v5 )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      v3->m_pVertexBuffer = 0;
    }
    result = 0;
  }
  return result;
}
// 440680: could not find valid save-restore pair for edi
// 440680: could not find valid save-restore pair for esi

//----- (004407A0) --------------------------------------------------------  // acclient.c:124759
void __thiscall UISurface::DestroySurface(UISurface *this)
{
  UISurface *v1; // esi@1
  RenderTexture *v2; // eax@1
  unsigned int v3; // ebp@2
  unsigned int v4; // edi@2
  int v5; // eax@2
  RenderTexture *v6; // eax@3
  RenderTexture *v7; // ecx@4
  RenderVertexBuffer *v8; // ecx@6
  bool v9; // zf@7
  RenderSurface *v10; // ecx@10
  RenderTexture *v11; // ecx@12
  PixelFormatDesc v12; // [sp+8h] [bp-38h]@2

  v1 = this;
  v2 = this->m_pLocalTexture;
  this->m_IsInitialized = 0;
  if ( v2 )
  {
    v3 = v2->m_nHeight;
    v4 = v2->m_nWidth;
    PixelFormatDesc::PixelFormatDesc(&v12, v2->m_PixelFormat);
    UISurface::s_nBytesConsumed -= v4 * v3 * *(_BYTE *)(v5 + 12) >> 3;
  }
  v6 = v1->m_pRemoteTexture;
  if ( v6 )
  {
    v6->m_LastManagedReleaseTime = Timer::local_time - 1000.0;
    v7 = v1->m_pRemoteTexture;
    if ( v7 )
    {
      ((void (*)(void))v7->vfptr->Release)();
      v1->m_pRemoteTexture = 0;
    }
  }
  v8 = v1->m_pVertexBuffer;
  if ( v8 )
  {
    v9 = v8->m_cRef-- == 1;
    if ( v9 )
      ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
    v1->m_pVertexBuffer = 0;
  }
  v10 = v1->m_pLocalSurface;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr->Release)();
    v1->m_pLocalSurface = 0;
  }
  v11 = v1->m_pLocalTexture;
  if ( v11 )
  {
    ((void (*)(void))v11->vfptr->Release)();
    v1->m_pLocalTexture = 0;
  }
}
// 837CD4: using guessed type __int32 UISurface::s_nBytesConsumed;

//----- (00440850) --------------------------------------------------------  // acclient.c:124819
char __cdecl UISurface::GetBestWidthHeight(const unsigned int _width, const unsigned int _height, unsigned int *bestWidth, unsigned int *bestHeight, const bool i_bForceCheck)
{
  char result; // al@3
  const unsigned int v6; // ST04_4@8
  const unsigned int v12; // ST04_4@14

  if ( !RenderDevice::render_device->m_caps.bSimpleNonPowerOfTwoTextures || i_bForceCheck )
  {
    if ( _width )
    {
      if ( _width < 0x800 )
      {
        *bestWidth = _width;
        v6 = _width;
        __asm { bsr     eax, [esp+8+var_4] }
        if ( *bestWidth > 1 << _EAX )
          *bestWidth = 2 * (1 << _EAX);
      }
      else
      {
        *bestWidth = 2048;
      }
    }
    else
    {
      *bestWidth = 0;
    }
    if ( _height )
    {
      if ( _height < 0x800 )
      {
        *bestHeight = _height;
        v12 = _height;
        __asm { bsr     eax, [esp+8+var_4] }
        if ( *bestHeight > 1 << _EAX )
          *bestHeight = 2 * (1 << _EAX);
        result = 1;
      }
      else
      {
        *bestHeight = 2048;
        result = 1;
      }
    }
    else
    {
      *bestHeight = 0;
      result = 1;
    }
  }
  else
  {
    *bestWidth = _width;
    *bestHeight = _height;
    result = 1;
  }
  return result;
}

//----- (00440930) --------------------------------------------------------  // acclient.c:124879
BOOL __cdecl UISurface::IsPowerOfTwo(const unsigned int i_nWidth, const unsigned int i_nHeight)
{
  unsigned int nBestWidth; // [sp+8h] [bp-8h]@1
  unsigned int nBestHeight; // [sp+Ch] [bp-4h]@1

  nBestWidth = 0;
  nBestHeight = 0;
  UISurface::GetBestWidthHeight(i_nWidth, i_nHeight, &nBestWidth, &nBestHeight, 1);
  return i_nWidth == nBestWidth && i_nHeight == nBestHeight;
}

//----- (00440990) --------------------------------------------------------  // acclient.c:124891
char __thiscall UISurface::CreateSurface(UISurface *this, const unsigned int _nWidth, const unsigned int _nHeight, const unsigned int _Flags)
{
  int v4; // edi@6
  unsigned int v5; // edx@6
  unsigned int v6; // ebp@7
  unsigned int v7; // ST28_4@12
  unsigned int v13; // ST28_4@18
  int v15; // esi@22
  RenderTexture *v16; // ecx@24
  int v17; // eax@26
  int v18; // eax@27
  RenderTexture *v19; // eax@31
  unsigned int v20; // esi@31
  unsigned int v21; // edi@31
  int v22; // eax@31
  char result; // al@31
  UISurface *v24; // [sp+1Ch] [bp-40h]@1
  PixelFormatDesc v25; // [sp+24h] [bp-38h]@31

  v24 = this;
  if ( !RenderDevice::render_device || _nWidth > 0x800 || _nHeight > 0x800 || !_nWidth || !_nHeight )
    goto LABEL_35;
  this->m_nPhysicalWidth = _nWidth;
  this->m_nPhysicalHeight = _nHeight;
  v4 = this->m_nPhysicalHeight;
  v5 = this->m_nPhysicalWidth;
  if ( RenderDevice::render_device->m_caps.bSimpleNonPowerOfTwoTextures )
  {
    v6 = this->m_nPhysicalWidth;
  }
  else
  {
    if ( v5 )
    {
      if ( v5 < 0x800 )
      {
        v6 = this->m_nPhysicalWidth;
        v7 = this->m_nPhysicalWidth;
        __asm { bsr     this, [esp+50h+var_3C] }
        if ( v5 > 1 << _EAX )
          v6 = 2 * (1 << _EAX);
      }
      else
      {
        v6 = 2048;
      }
    }
    else
    {
      v6 = 0;
    }
    if ( v4 )
    {
      if ( (unsigned int)v4 < 0x800 )
      {
        v13 = this->m_nPhysicalHeight;
        __asm { bsr     this, [esp+50h+var_3C] }
        if ( v4 > (unsigned int)(1 << _EAX) )
          v4 = 2 * (1 << _EAX);
      }
      else
      {
        v4 = 2048;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  if ( !v6 || !v4 )
    goto LABEL_35;
  v15 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
  v24->m_bHasAlpha = 0;
  if ( _Flags & 1 )
  {
    v24->m_bHasAlpha = 1;
    v15 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
  }
  if ( (v24->m_pLocalTexture = (RenderTexture *)((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)(),
        (v16 = v24->m_pLocalTexture) != 0)
    && (unsigned __int8)((int (__stdcall *)(unsigned int, int, signed int, int, signed int))v16->vfptr[3].AddRef)(
                          v6,
                          v4,
                          1,
                          v15,
                          2)
    && ((v17 = ((int (__stdcall *)(_DWORD, _DWORD))v24->m_pLocalTexture->vfptr[4].IUnknown_AddRef)(0, 0)) == 0 ? (v18 = 0) : (v18 = v17 - 48),
        (v24->m_pLocalSurface = (RenderSurface *)v18) != 0 && UISurface::SetupVertexBuffer(v24, v4, v15)) )
  {
    v24->m_pLocalSurface->m_IsDirty = 1;
    v19 = v24->m_pLocalTexture;
    v20 = v19->m_nWidth;
    v21 = v19->m_nHeight;
    PixelFormatDesc::PixelFormatDesc(&v25, v19->m_PixelFormat);
    UISurface::s_nBytesConsumed += v21 * v20 * *(_BYTE *)(v22 + 12) >> 3;
    v24->m_IsInitialized = 1;
    result = 1;
  }
  else
  {
LABEL_35:
    result = 0;
  }
  return result;
}
// 837CD4: using guessed type __int32 UISurface::s_nBytesConsumed;

//----- (00440B80) --------------------------------------------------------  // acclient.c:125000
bool __thiscall UISurface::PrepareSurface(UISurface *this)
{
  UISurface *v1; // esi@1
  bool v2; // bl@5
  unsigned int v3; // ebp@5
  unsigned int v4; // edi@5
  bool result; // al@6

  v1 = this;
  result = 0;
  if ( this->m_IsInitialized && RenderDevice::render_device )
  {
    if ( !this->m_pLocalTexture->m_bIsLost && !this->m_pLocalSurface->m_bIsLost
      || (v2 = this->m_bHasAlpha,
          v3 = this->m_nPhysicalHeight,
          v4 = this->m_nPhysicalWidth,
          UISurface::DestroySurface(this),
          UISurface::CreateSurface(v1, v4, v3, v2 != 0)) )
      result = 1;
  }
  return result;
}

//----- (00440BE0) --------------------------------------------------------  // acclient.c:125024
UISurface *__thiscall UISurface::vector_deleting_destructor(UISurface *this, unsigned int a2)
{
  UISurface *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UISurface::vftable;
  UISurface::DestroySurface(this);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7995B0: using guessed type int (__thiscall *UISurface::vftable)(void *, char);

//----- (00440C10) --------------------------------------------------------  // acclient.c:125040
char __thiscall UISurface::Resize(UISurface *this, const unsigned int _nNewWidth, const unsigned int _nNewHeight)
{
  UISurface *v3; // esi@1
  RenderTexture *v4; // eax@8
  bool v6; // bl@12

  v3 = this;
  if ( !this->m_IsInitialized || _nNewWidth > 0x800 || _nNewHeight > 0x800 || !_nNewWidth || !_nNewHeight )
    return 0;
  if ( _nNewWidth != this->m_nPhysicalWidth || _nNewHeight != this->m_nPhysicalHeight )
  {
    v4 = this->m_pLocalTexture;
    if ( _nNewWidth >= v4->m_nWidth || _nNewHeight >= v4->m_nHeight )
    {
      v6 = this->m_bHasAlpha;
      UISurface::DestroySurface(this);
      if ( !UISurface::CreateSurface(v3, _nNewWidth, _nNewHeight, v6 != 0) )
      {
        UISurface::DestroySurface(v3);
        return 0;
      }
    }
    else
    {
      this->m_nPhysicalWidth = _nNewWidth;
      this->m_nPhysicalHeight = _nNewHeight;
      if ( !UISurface::SetupVertexBuffer(this, _nNewWidth, (int)this) )
        return 0;
    }
  }
  return 1;
}

//----- (00440CB0) --------------------------------------------------------  // acclient.c:125074
char __thiscall UISurface::RefreshHardware(UISurface *this)
{
  UISurface *v1; // esi@1
  bool v2; // bl@1
  RenderSurface *v3; // eax@3
  RenderTexture *v4; // eax@6
  RenderTexture *v5; // ecx@9
  int v6; // eax@11
  char v7; // al@12
  RenderTexture *v8; // ecx@12

  v1 = this;
  v2 = 0;
  if ( !this->m_IsInitialized )
    return 0;
  if ( !UISurface::PrepareSurface(this) )
    return 0;
  v3 = v1->m_pLocalSurface;
  if ( !v3 || !v1->m_pLocalTexture )
    return 0;
  if ( v3->m_IsDirty )
  {
    v4 = v1->m_pRemoteTexture;
    if ( v4 )
    {
      if ( !v4->m_bIsLost )
        goto LABEL_17;
      if ( v4 )
      {
        v4->m_LastManagedReleaseTime = Timer::local_time - 1000.0;
        v5 = v1->m_pRemoteTexture;
        if ( v5 )
        {
          ((void (*)(void))v5->vfptr->Release)();
          v1->m_pRemoteTexture = 0;
        }
      }
    }
    v6 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
    v1->m_pRemoteTexture = (RenderTexture *)v6;
    if ( !v6 )
      return 0;
    v7 = (*(int (__thiscall **)(int, unsigned int, unsigned int, unsigned int, PixelFormatID, _DWORD))(*(_DWORD *)v6 + 88))(
           v6,
           v1->m_pLocalTexture->m_nWidth,
           v1->m_pLocalTexture->m_nHeight,
           v1->m_pLocalTexture->m_nNumLevels,
           v1->m_pLocalTexture->m_PixelFormat,
           0);
    v8 = v1->m_pRemoteTexture;
    if ( !v7 )
    {
      if ( v8 )
      {
        ((void (*)(void))v8->vfptr->Release)();
        v1->m_pRemoteTexture = 0;
      }
      return 0;
    }
    v2 = 0;
    v8->m_AllowManagement = 0;
LABEL_17:
    if ( (unsigned __int8)((int (__stdcall *)(RenderTexture *))v1->m_pRemoteTexture->vfptr[4].IUnknown_QueryInterface)(v1->m_pLocalTexture) )
    {
      v1->m_pLocalSurface->m_IsDirty = v2;
      return 1;
    }
    return 0;
  }
  return 1;
}

//----- (006C7130) --------------------------------------------------------  // acclient.c:735157
void _E73_33()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_8, PFID_A8R8G8B8);
}

//----- (006C7140) --------------------------------------------------------  // acclient.c:735163
void _E91_11()
{
  LODWORD(dword_837D2C) = 1053364187;
}

//----- (006C7150) --------------------------------------------------------  // acclient.c:735169
void _E93_2()
{
  outside_val_7 = 1000.0 + 1.0;
}

//----- (006C7170) --------------------------------------------------------  // acclient.c:735175
void _E95_2()
{
  block_length_7 = 24.0 * 8.0;
}

//----- (006C7190) --------------------------------------------------------  // acclient.c:735181
void _E97_11()
{
  half_square_length_7 = 24.0 * 0.5;
}

//----- (006C71B0) --------------------------------------------------------  // acclient.c:735187
int _E99()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_3, "Render.TextureFiltering");
  return atexit(sub_72A180);
}

//----- (006C71D0) --------------------------------------------------------  // acclient.c:735194
int _E102_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_3, "Render.LandscapeDetailTextures");
  return atexit(sub_72A1B0);
}

//----- (006C71F0) --------------------------------------------------------  // acclient.c:735201
int _E105()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_3, "Render.BuildingDetailTextures");
  return atexit(sub_72A1E0);
}

//----- (006C7210) --------------------------------------------------------  // acclient.c:735208
int _E108_1()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_3, "Render.FieldOfView");
  return atexit(sub_72A210);
}

//----- (006C7230) --------------------------------------------------------  // acclient.c:735215
int _E111()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_3, "Render.LandscapeTextureDetail");
  return atexit(sub_72A240);
}

//----- (006C7250) --------------------------------------------------------  // acclient.c:735222
int _E114_1()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_3, "Render.EnvironmentTextureDetail");
  return atexit(sub_72A270);
}

//----- (006C7270) --------------------------------------------------------  // acclient.c:735229
int _E117()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_3, "Render.SceneryDrawDistance");
  return atexit(sub_72A2A0);
}

//----- (006C7290) --------------------------------------------------------  // acclient.c:735236
int _E120_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_3, "Render.LandscapeDrawDistance");
  return atexit(sub_72A2D0);
}

//----- (006C72B0) --------------------------------------------------------  // acclient.c:735243
int _E123()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_3, "Render.ScreenBrightness");
  return atexit(_E124_93);
}

//----- (006C72D0) --------------------------------------------------------  // acclient.c:735250
int _E126_1()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_3, "Render.AspectRatio");
  return atexit(_E127_82);
}

//----- (006C72F0) --------------------------------------------------------  // acclient.c:735257
int _E129_0()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_3, "Render.DisplayAdapter");
  return atexit(_E130_74);
}

//----- (006C7310) --------------------------------------------------------  // acclient.c:735264
int _E132_1()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_3, "Render.MaxHardwareClass");
  return atexit(_E133_67);
}

//----- (006C7330) --------------------------------------------------------  // acclient.c:735271
int _E135_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_3, "Render.AutomaticDegrades");
  return atexit(_E136_51);
}

//----- (006C7350) --------------------------------------------------------  // acclient.c:735278
int _E138_1()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_3, "Render.GraphicsPerformance");
  return atexit(_E139_52);
}

//----- (006C7370) --------------------------------------------------------  // acclient.c:735285
int _E141_1()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_3, "Render.DegradeDistance");
  return atexit(_E142_49);
}

//----- (006C7390) --------------------------------------------------------  // acclient.c:735292
int _E144_1()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_3, "Render.MultiPassAlpha");
  return atexit(_E145_51);
}

//----- (006C73B0) --------------------------------------------------------  // acclient.c:735299
int _E147_1()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_3, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_837D80, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_837D84, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_837D88, "Anisotropic");
  return atexit(_E148_50);
}

//----- (006C7400) --------------------------------------------------------  // acclient.c:735309
int _E150_1()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_3, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837D90, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837D94, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837D98, "High");
  PStringBase<char>::PStringBase<char>(&stru_837D9C, "VeryHigh");
  return atexit(_E151_48);
}

//----- (006C7460) --------------------------------------------------------  // acclient.c:735320
int _E153_1()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_3, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837DA4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837DA8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837DAC, "High");
  PStringBase<char>::PStringBase<char>(&stru_837DB0, "VeryHigh");
  return atexit(_E154_49);
}

//----- (006C74C0) --------------------------------------------------------  // acclient.c:735331
int _E156_2()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_3, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837DB8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837DBC, "High");
  return atexit(_E157_46);
}

//----- (006C7500) --------------------------------------------------------  // acclient.c:735340
int _E159_1()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_3, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837DC4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837DC8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837DCC, "High");
  PStringBase<char>::PStringBase<char>(&stru_837DD0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_837DD4, "Extreme");
  return atexit(_E160_49);
}

//----- (006C7570) --------------------------------------------------------  // acclient.c:735352
int _E162_2()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_3, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_837DDC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_837DE0, "Wide");
  return atexit(_E163_42);
}

//----- (006C75B0) --------------------------------------------------------  // acclient.c:735361
int _E165_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_9, "None");
  return atexit(_E166_44);
}

//----- (006C75D0) --------------------------------------------------------  // acclient.c:735368
int _E168_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_9, "Speed");
  return atexit(_E169_43);
}

//----- (006C75F0) --------------------------------------------------------  // acclient.c:735375
int _E171_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_9, "Noise");
  return atexit(_E172_41);
}

//----- (006C7610) --------------------------------------------------------  // acclient.c:735382
int _E174_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_9, "Sine");
  return atexit(_E175_38);
}

//----- (006C7630) --------------------------------------------------------  // acclient.c:735389
int _E177_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_9, "Square");
  return atexit(_E178_38);
}

//----- (006C7650) --------------------------------------------------------  // acclient.c:735396
int _E180_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_9, "Bounce");
  return atexit(_E181_38);
}

//----- (006C7670) --------------------------------------------------------  // acclient.c:735403
int _E183_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_9, "Perlin");
  return atexit(_E184_36);
}

//----- (006C7690) --------------------------------------------------------  // acclient.c:735410
int _E186_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_9, "Fractal");
  return atexit(_E187_35);
}

//----- (006C76B0) --------------------------------------------------------  // acclient.c:735417
int _E189_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_9, "FrameLoop");
  return atexit(_E190_36);
}

//----- (006C76D0) --------------------------------------------------------  // acclient.c:735424
int _E1_30()
{
  return atexit(_E2_30);
}

//----- (0072A180) --------------------------------------------------------  // acclient.c:828212
void __cdecl sub_72A180()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A1B0) --------------------------------------------------------  // acclient.c:828225
void __cdecl sub_72A1B0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A1E0) --------------------------------------------------------  // acclient.c:828238
void __cdecl sub_72A1E0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A210) --------------------------------------------------------  // acclient.c:828251
void __cdecl sub_72A210()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A240) --------------------------------------------------------  // acclient.c:828264
void __cdecl sub_72A240()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A270) --------------------------------------------------------  // acclient.c:828277
void __cdecl sub_72A270()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A2A0) --------------------------------------------------------  // acclient.c:828290
void __cdecl sub_72A2A0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A2D0) --------------------------------------------------------  // acclient.c:828303
void __cdecl sub_72A2D0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A300) --------------------------------------------------------  // acclient.c:828316
void __cdecl _E124_93()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A330) --------------------------------------------------------  // acclient.c:828329
void __cdecl _E127_82()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A360) --------------------------------------------------------  // acclient.c:828342
void __cdecl _E130_74()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A390) --------------------------------------------------------  // acclient.c:828355
void __cdecl _E133_67()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A3C0) --------------------------------------------------------  // acclient.c:828368
void __cdecl _E136_51()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A3F0) --------------------------------------------------------  // acclient.c:828381
void __cdecl _E139_52()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A420) --------------------------------------------------------  // acclient.c:828394
void __cdecl _E142_49()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A450) --------------------------------------------------------  // acclient.c:828407
void __cdecl _E145_51()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A480) --------------------------------------------------------  // acclient.c:828420
void __cdecl _E148_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_3;
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

//----- (0072A4C0) --------------------------------------------------------  // acclient.c:828445
void __cdecl _E151_48()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_3;
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

//----- (0072A500) --------------------------------------------------------  // acclient.c:828470
void __cdecl _E154_49()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_3;
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

//----- (0072A540) --------------------------------------------------------  // acclient.c:828495
void __cdecl _E157_46()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_3;
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

//----- (0072A580) --------------------------------------------------------  // acclient.c:828520
void __cdecl _E160_49()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_3;
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

//----- (0072A5C0) --------------------------------------------------------  // acclient.c:828545
void __cdecl _E163_42()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_9;
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

//----- (0072A600) --------------------------------------------------------  // acclient.c:828570
void __cdecl _E166_44()
{
  char *v0; // esi@1

  v0 = &waveform_None_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A630) --------------------------------------------------------  // acclient.c:828583
void __cdecl _E169_43()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A660) --------------------------------------------------------  // acclient.c:828596
void __cdecl _E172_41()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A690) --------------------------------------------------------  // acclient.c:828609
void __cdecl _E175_38()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A6C0) --------------------------------------------------------  // acclient.c:828622
void __cdecl _E178_38()
{
  char *v0; // esi@1

  v0 = &waveform_Square_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A6F0) --------------------------------------------------------  // acclient.c:828635
void __cdecl _E181_38()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A720) --------------------------------------------------------  // acclient.c:828648
void __cdecl _E184_36()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A750) --------------------------------------------------------  // acclient.c:828661
void __cdecl _E187_35()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A780) --------------------------------------------------------  // acclient.c:828674
void __cdecl _E190_36()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

