/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACRenderDeviceState
   Object     : PORTAL\acrenderdev\ACRenderDeviceState.obj
   Functions  : 108
   Addresses  : 005A2A90 - 00776840 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A2A90) --------------------------------------------------------  // acclient.c:460051
void __thiscall RenderDeviceD3D::SetAlphaBlendEnable(RenderDeviceD3D *this, const bool _bValue)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.AlphaBlendEnable != _bValue )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)27,
      (void **)(unsigned __int8)_bValue);
    v2->m_State.AlphaBlendEnable = _bValue;
  }
}

//----- (005A2AD0) --------------------------------------------------------  // acclient.c:460067
void __thiscall RenderDeviceD3D::SetAlphaTestEnable(RenderDeviceD3D *this, const bool _bValue)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.AlphaTestEnable != _bValue )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)15,
      (void **)(unsigned __int8)_bValue);
    v2->m_State.AlphaTestEnable = _bValue;
  }
}

//----- (005A2B10) --------------------------------------------------------  // acclient.c:460083
void __thiscall RenderDeviceD3D::SetAlphaTestFunction(RenderDeviceD3D *this, AlphaTestFunc _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.AlphaTestFunction != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)25, (void **)_Value);
    v2->m_State.AlphaTestFunction = _Value;
  }
}

//----- (005A2B50) --------------------------------------------------------  // acclient.c:460096
void __thiscall RenderDeviceD3D::SetAlphaTestRef(RenderDeviceD3D *this, const unsigned int _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.AlphaTestRef != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)24, (void **)_Value);
    v2->m_State.AlphaTestRef = _Value;
  }
}

//----- (005A2B90) --------------------------------------------------------  // acclient.c:460109
void __thiscall RenderDeviceD3D::SetBlendFunction(RenderDeviceD3D *this, BlendMode _SourceFactor, BlendMode _DestFactor, BlendOpType _Op)
{
  RenderDeviceD3D *v4; // esi@1
  bool v5; // bl@14

  v4 = this;
  if ( this->m_bForceStates || this->m_State.SourceBlend != _SourceFactor )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)19,
      (void **)_SourceFactor);
    v4->m_State.SourceBlend = _SourceFactor;
  }
  if ( v4->m_bForceStates || v4->m_State.DestBlend != _DestFactor )
  {
    v4->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)v4->m_pDirect3DDevice,
      (_GUID *)20,
      (void **)_DestFactor);
    v4->m_State.DestBlend = _DestFactor;
  }
  if ( v4->m_bForceStates || v4->m_State.BlendOp != _Op )
  {
    if ( v4->m_caps.bBlendOp )
      v4->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v4->m_pDirect3DDevice, (_GUID *)171, (void **)_Op);
    v4->m_State.BlendOp = _Op;
  }
  v5 = _SourceFactor != 2 || _DestFactor != 1;
  if ( v4->m_bForceStates || v4->m_State.AlphaBlendEnable != v5 )
  {
    v4->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v4->m_pDirect3DDevice, (_GUID *)27, (void **)v5);
    v4->m_State.AlphaBlendEnable = v5;
  }
}

//----- (005A2C70) --------------------------------------------------------  // acclient.c:460146
void __thiscall RenderDeviceD3D::SetCullMode(RenderDeviceD3D *this, CullModeType _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.CullMode != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)22, (void **)_Value);
    v2->m_State.CullMode = _Value;
  }
}

//----- (005A2CB0) --------------------------------------------------------  // acclient.c:460159
void __thiscall RenderDeviceD3D::SetDepthBias(RenderDeviceD3D *this, const float _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_caps.bSlopeScaleDepthBias )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)175,
      LODWORD(_Value));
    v2->m_State.DepthBias = _Value;
  }
}

//----- (005A2CF0) --------------------------------------------------------  // acclient.c:460175
void __thiscall RenderDeviceD3D::SetDepthBufferEnable(RenderDeviceD3D *this, const bool _bValue)
{
  this->m_pDirect3DDevice->vfptr[19].QueryInterface(
    (IUnknown *)this->m_pDirect3DDevice,
    (_GUID *)7,
    (void **)(unsigned __int8)_bValue);
}

//----- (005A2D10) --------------------------------------------------------  // acclient.c:460184
void __thiscall RenderDeviceD3D::SetDepthBufferMode(RenderDeviceD3D *this, DepthTestMode _DepthTestMode, const bool _DepthWriteEnable)
{
  RenderDeviceD3D *v3; // esi@1
  bool v4; // al@9

  v3 = this;
  if ( this->m_bForceStates || this->m_State.DepthTestFunction != _DepthTestMode )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)23,
      (void **)_DepthTestMode);
    v3->m_State.DepthTestFunction = _DepthTestMode;
  }
  if ( v3->m_bForceStates || v3->m_State.DepthWriteEnable != _DepthWriteEnable )
  {
    v3->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)v3->m_pDirect3DDevice,
      (_GUID *)14,
      (void **)(unsigned __int8)_DepthWriteEnable);
    v3->m_State.DepthWriteEnable = _DepthWriteEnable;
  }
  v4 = _DepthWriteEnable == 1 || _DepthTestMode != 8;
  v3->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v3->m_pDirect3DDevice, (_GUID *)7, (void **)v4);
}

//----- (005A2DA0) --------------------------------------------------------  // acclient.c:460211
void __thiscall RenderDeviceD3D::SetFFAmbientColor32(RenderDeviceD3D *this, const unsigned int _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFAmbientColor32 != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)139,
      (void **)_Value);
    v2->m_State.FFAmbientColor32 = _Value;
  }
}

//----- (005A2DE0) --------------------------------------------------------  // acclient.c:460227
void __thiscall RenderDeviceD3D::SetFFDiffuseColorSource(RenderDeviceD3D *this, ColorSource _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFDiffuseColorSource != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)145,
      (void **)(_Value == 1));
    v2->m_State.FFDiffuseColorSource = _Value;
  }
}

//----- (005A2E30) --------------------------------------------------------  // acclient.c:460243
void __thiscall RenderDeviceD3D::SetFFAmbientColorSource(RenderDeviceD3D *this, ColorSource _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFAmbientColorSource != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)147,
      (void **)(_Value == 1));
    v2->m_State.FFAmbientColorSource = _Value;
  }
}

//----- (005A2E80) --------------------------------------------------------  // acclient.c:460259
void __thiscall RenderDeviceD3D::SetFFFogEnable(RenderDeviceD3D *this, const bool _bValue)
{
  bool v2; // al@3

  if ( this->m_bForceStates || this->m_State.FFFogEnable != _bValue )
  {
    v2 = _bValue && this->m_State.FFFogSystemDisabled == 0 && this->m_State.FFFogUserDisabled == 0;
    this->m_State.FFFogEnable = v2;
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)28, (void **)v2);
  }
}

//----- (005A2ED0) --------------------------------------------------------  // acclient.c:460272
void __thiscall RenderDeviceD3D::SetFFFogSystemDisabled(RenderDeviceD3D *this, const bool _bValue)
{
  if ( this->m_bForceStates || this->m_State.FFFogSystemDisabled != _bValue )
  {
    this->m_State.FFFogSystemDisabled = _bValue;
    if ( _bValue == 1 )
      RenderDeviceD3D::SetFFFogEnable(this, 0);
  }
}

//----- (005A2F00) --------------------------------------------------------  // acclient.c:460283
void __thiscall RenderDeviceD3D::SetFFFogUserDisabled(RenderDeviceD3D *this, const bool _bValue)
{
  if ( this->m_bForceStates || this->m_State.FFFogUserDisabled != _bValue )
  {
    this->m_State.FFFogUserDisabled = _bValue;
    if ( _bValue == 1 )
      RenderDeviceD3D::SetFFFogEnable(this, 0);
  }
}

//----- (005A2F30) --------------------------------------------------------  // acclient.c:460294
void __thiscall RenderDeviceD3D::SetFFFogAlphaDisabled(RenderDeviceD3D *this, const bool _bValue)
{
  if ( this->m_bForceStates || this->m_State.FFFogAlphaDisabled != _bValue )
  {
    this->m_State.FFFogAlphaDisabled = _bValue;
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)28,
      (void **)(_bValue == 0));
  }
}

//----- (005A2F70) --------------------------------------------------------  // acclient.c:460307
void __thiscall RenderDeviceD3D::SetFFFogProperties(RenderDeviceD3D *this, RGBAColor *_Color, const float _NearDistance, const float _FarDistance)
{
  RenderDeviceD3D *v4; // esi@1
  unsigned __int64 v5; // rax@3
  __int16 v6; // ax@6

  v4 = this;
  if ( this->m_bForceStates || !(unsigned __int8)RGBAColor::operator==(&this->m_State.FFFogColor, _Color) )
  {
    v5 = (unsigned __int64)(_Color->b * 255.0);
    ((void (__fastcall *)(RenderDeviceD3D *, _DWORD, IDirect3DDevice9 *, signed int, _DWORD))v4->m_pDirect3DDevice->vfptr[19].QueryInterface)(
      this,
      HIDWORD(v5),
      v4->m_pDirect3DDevice,
      34,
      v5 | (((unsigned int)(unsigned __int64)(_Color->g * 255.0) | (((unsigned int)(unsigned __int64)(_Color->r * 255.0) | ((unsigned int)(unsigned __int64)(_Color->a * 255.0) << 8)) << 8)) << 8));
    v4->m_State.FFFogColor = *_Color;
  }
  if ( v4->m_bForceStates || v4->m_State.FFFogNearDistance != _NearDistance )
  {
    v6 = v4->m_pDirect3DDevice->vfptr[19].QueryInterface(
           (IUnknown *)v4->m_pDirect3DDevice,
           (_GUID *)36,
           LODWORD(_NearDistance));
    v4->m_State.FFFogNearDistance = _NearDistance;
  }
  if ( v4->m_bForceStates || v4->m_State.FFFogFarDistance != _FarDistance )
  {
    v4->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)v4->m_pDirect3DDevice,
      (_GUID *)37,
      LODWORD(_FarDistance));
    v4->m_State.FFFogFarDistance = _FarDistance;
  }
}

//----- (005A30A0) --------------------------------------------------------  // acclient.c:460344
void __thiscall RenderDeviceD3D::SetFFFogProperties(RenderDeviceD3D *this, RGBAUnion *_Color, const float _NearDistance, const float _FarDistance)
{
  RenderDeviceD3D *v4; // esi@1
  RGBAColor color; // [sp+4h] [bp-10h]@1

  v4 = this;
  RGBAColor::SetColor32(&color, _Color->color);
  RenderDeviceD3D::SetFFFogProperties(v4, &color, _NearDistance, _FarDistance);
}

//----- (005A30E0) --------------------------------------------------------  // acclient.c:460355
void __thiscall RenderDeviceD3D::SetFFLighting(RenderDeviceD3D *this, const bool _bValue)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFLighting != _bValue )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)137,
      (void **)(unsigned __int8)_bValue);
    v2->m_State.FFLighting = _bValue;
  }
}

//----- (005A3120) --------------------------------------------------------  // acclient.c:460371
void __thiscall RenderDeviceD3D::SetFFLightEnable(RenderDeviceD3D *this, const unsigned int _Index, const bool _bValue)
{
  RenderDeviceD3D *v3; // esi@1

  v3 = this;
  if ( this->m_bForceStates || this->m_State.FFLightEnable[_Index] != _bValue )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[17].Release)(
      this->m_pDirect3DDevice,
      _Index,
      (unsigned __int8)_bValue);
    v3->m_State.FFLightEnable[_Index] = _bValue;
  }
}

//----- (005A3170) --------------------------------------------------------  // acclient.c:460387
void __thiscall RenderDeviceD3D::SetFFSpecularColorSource(RenderDeviceD3D *this, ColorSource _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFSpecularColorSource != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)146,
      (void **)(_Value != 1 ? 0 : 2));
    v2->m_State.FFSpecularColorSource = _Value;
  }
}

//----- (005A31C0) --------------------------------------------------------  // acclient.c:460403
void __thiscall RenderDeviceD3D::SetFFSpecularEnable(RenderDeviceD3D *this, const bool _bValue)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFSpecularEnable != _bValue )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)29,
      (void **)(unsigned __int8)_bValue);
    v2->m_State.FFSpecularEnable = _bValue;
  }
}

//----- (005A3200) --------------------------------------------------------  // acclient.c:460419
void __thiscall RenderDeviceD3D::SetFFEmissiveColorSource(RenderDeviceD3D *this, ColorSource _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFEmissiveColorSource != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface(
      (IUnknown *)this->m_pDirect3DDevice,
      (_GUID *)148,
      (void **)_Value);
    v2->m_State.FFEmissiveColorSource = _Value;
  }
}

//----- (005A3240) --------------------------------------------------------  // acclient.c:460435
void __thiscall RenderDeviceD3D::SetFFTextureFactor32(RenderDeviceD3D *this, const unsigned int _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FFTextureFactor32 != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)60, (void **)_Value);
    v2->m_State.FFTextureFactor32 = _Value;
  }
}

//----- (005A3280) --------------------------------------------------------  // acclient.c:460448
void __thiscall RenderDeviceD3D::SetFillMode(RenderDeviceD3D *this, FillModeType _Value)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.FillMode != _Value )
  {
    this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)8, (void **)_Value);
    v2->m_State.FillMode = _Value;
  }
}

//----- (005A32C0) --------------------------------------------------------  // acclient.c:460461
void __thiscall RenderDeviceD3D::SetMultiSampleAntialias(RenderDeviceD3D *this, const bool _bValue)
{
  RenderDeviceD3D *v2; // esi@1

  v2 = this;
  if ( this->m_bForceStates || this->m_State.MultiSampleAntialias != _bValue )
  {
    if ( this->m_presentation.Antialiasing )
    {
      if ( this->m_displayInfo.bMultiSampling )
      {
        this->m_pDirect3DDevice->vfptr[19].QueryInterface(
          (IUnknown *)this->m_pDirect3DDevice,
          (_GUID *)161,
          (void **)(unsigned __int8)_bValue);
        v2->m_State.MultiSampleAntialias = _bValue;
      }
    }
  }
}

//----- (005A3310) --------------------------------------------------------  // acclient.c:460483
void __thiscall RenderDeviceD3D::SetSamplerAddressMode(RenderDeviceD3D *this, const unsigned int _Sampler, TexAddress _AddressModeU, TexAddress _AddressModeV)
{
  RenderDeviceD3D *v4; // esi@1

  v4 = this;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    this->m_pDirect3DDevice,
    _Sampler,
    1,
    _AddressModeU);
  ((void (__stdcall *)(_DWORD, const unsigned int, signed int, TexAddress))v4->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    v4->m_pDirect3DDevice,
    _Sampler,
    2,
    _AddressModeV);
}

//----- (005A3350) --------------------------------------------------------  // acclient.c:460501
void __thiscall RenderDeviceD3D::SetSamplerFilterMode(RenderDeviceD3D *this, const unsigned int _Sampler, TexFilterMode _MagFilterMode, TexFilterMode _MinFilterMode, TexFilterMode _MipFilterMode)
{
  RenderDeviceD3D *v5; // esi@1
  TexFilterMode v6; // ecx@1
  unsigned int v7; // eax@5
  TexFilterMode v8; // ecx@7
  TexFilterMode v9; // eax@13

  v5 = this;
  v6 = _MinFilterMode;
  if ( _MinFilterMode == 2 )
  {
    if ( Render::m_RenderPrefs.TextureFiltering != 3 )
      goto LABEL_7;
    v6 = 3;
  }
  else if ( _MinFilterMode != 3 )
  {
    goto LABEL_7;
  }
  v7 = v5->m_D3DCaps.TextureFilterCaps;
  if ( !(BYTE1(v7) & 4) )
    v6 = 2;
LABEL_7:
  ((void (__stdcall *)(_DWORD, const unsigned int, signed int, TexFilterMode))v5->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    v5->m_pDirect3DDevice,
    _Sampler,
    6,
    v6);
  v8 = _MagFilterMode;
  if ( _MagFilterMode == 2 )
  {
    if ( Render::m_RenderPrefs.TextureFiltering != 3 )
      goto LABEL_13;
    v8 = 3;
  }
  else if ( _MagFilterMode != 3 )
  {
    goto LABEL_13;
  }
  if ( !(v5->m_D3DCaps.TextureFilterCaps & 0x4000000) )
    v8 = 2;
LABEL_13:
  ((void (__stdcall *)(_DWORD, _DWORD, signed int, TexFilterMode))v5->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    v5->m_pDirect3DDevice,
    _Sampler,
    5,
    v8);
  v9 = _MipFilterMode;
  if ( _MipFilterMode == 2 && !Render::m_RenderPrefs.TextureFiltering )
    v9 = 1;
  ((void (__stdcall *)(_DWORD, _DWORD, signed int, TexFilterMode))v5->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    v5->m_pDirect3DDevice,
    _Sampler,
    7,
    v9);
}
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;

//----- (005A3410) --------------------------------------------------------  // acclient.c:460561
void __thiscall RenderDeviceD3D::SetSamplerMipmapLODBias(RenderDeviceD3D *this, const unsigned int _Sampler, const float _Bias)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[23].QueryInterface)(
    this->m_pDirect3DDevice,
    _Sampler,
    8,
    LODWORD(_Bias));
}

//----- (005A3440) --------------------------------------------------------  // acclient.c:460571
void __thiscall RenderDeviceD3D::SetStageFFAlphaSource(RenderDeviceD3D *this, const unsigned int _Stage, TextureOp _AlphaOp, const unsigned int _AlphaArg1, const unsigned int _AlphaArg2)
{
  RenderDeviceD3D *v5; // esi@1
  char *v6; // ebx@2

  v5 = this;
  if ( this->m_bForceStates || (v6 = (char *)this + 36 * _Stage, *((_DWORD *)v6 + 416) != _AlphaOp) )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[22].AddRef)(
      this->m_pDirect3DDevice,
      _Stage,
      4,
      _AlphaOp);
    v6 = (char *)v5 + 36 * _Stage;
    *((_DWORD *)v6 + 416) = _AlphaOp;
  }
  if ( v5->m_bForceStates || *((_DWORD *)&v5->vfptr + 9 * _Stage + 414) != _AlphaArg1 )
  {
    ((void (__stdcall *)(_DWORD, const unsigned int, signed int, const unsigned int))v5->m_pDirect3DDevice->vfptr[22].AddRef)(
      v5->m_pDirect3DDevice,
      _Stage,
      5,
      _AlphaArg1);
    *((_DWORD *)&v5->vfptr + 9 * _Stage + 414) = _AlphaArg1;
  }
  if ( v5->m_bForceStates || *((_DWORD *)v6 + 415) != _AlphaArg2 )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v5->m_pDirect3DDevice->vfptr[22].AddRef)(
      v5->m_pDirect3DDevice,
      _Stage,
      6,
      _AlphaArg2);
    *((_DWORD *)v6 + 415) = _AlphaArg2;
  }
}

//----- (005A3500) --------------------------------------------------------  // acclient.c:460608
void __thiscall RenderDeviceD3D::SetStageFFColorSource(RenderDeviceD3D *this, const unsigned int _Stage, TextureOp _ColorOp, const unsigned int _ColorArg1, const unsigned int _ColorArg2)
{
  RenderDeviceD3D *v5; // esi@1
  char *v6; // edi@2

  v5 = this;
  if ( this->m_bForceStates || (v6 = (char *)this + 36 * _Stage, *((_DWORD *)v6 + 419) != _ColorOp) )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[22].AddRef)(
      this->m_pDirect3DDevice,
      _Stage,
      1,
      _ColorOp);
    v6 = (char *)v5 + 36 * _Stage;
    *((_DWORD *)v6 + 419) = _ColorOp;
  }
  if ( v5->m_bForceStates || *((_DWORD *)v6 + 417) != _ColorArg1 )
  {
    ((void (__stdcall *)(_DWORD, const unsigned int, signed int, const unsigned int))v5->m_pDirect3DDevice->vfptr[22].AddRef)(
      v5->m_pDirect3DDevice,
      _Stage,
      2,
      _ColorArg1);
    *((_DWORD *)v6 + 417) = _ColorArg1;
  }
  if ( v5->m_bForceStates || *((_DWORD *)v6 + 418) != _ColorArg2 )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v5->m_pDirect3DDevice->vfptr[22].AddRef)(
      v5->m_pDirect3DDevice,
      _Stage,
      3,
      _ColorArg2);
    *((_DWORD *)v6 + 418) = _ColorArg2;
  }
}

//----- (005A35B0) --------------------------------------------------------  // acclient.c:460645
void __thiscall RenderDeviceD3D::SetStageFFTexCoordIndex(RenderDeviceD3D *this, const unsigned int _Stage, const unsigned int _TexCoordIndex)
{
  RenderDeviceD3D *v3; // edi@1

  v3 = this;
  if ( this->m_bForceStates || this->m_State.Stages[_Stage].FFTexCoordIndex != _TexCoordIndex )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[22].AddRef)(
      this->m_pDirect3DDevice,
      _Stage,
      11,
      _TexCoordIndex);
    v3->m_State.Stages[_Stage].FFTexCoordIndex = _TexCoordIndex;
  }
}

//----- (005A3600) --------------------------------------------------------  // acclient.c:460662
void __thiscall RenderDeviceD3D::SetStageFFTextureTransformFlags(RenderDeviceD3D *this, const unsigned int _Stage, const unsigned int _TextureTransformFlags)
{
  RenderDeviceD3D *v3; // edi@1

  v3 = this;
  if ( this->m_bForceStates || this->m_State.Stages[_Stage].FFTextureTransformFlags != _TextureTransformFlags )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[22].AddRef)(
      this->m_pDirect3DDevice,
      _Stage,
      24,
      _TextureTransformFlags);
    v3->m_State.Stages[_Stage].FFTextureTransformFlags = _TextureTransformFlags;
  }
}

//----- (005A3650) --------------------------------------------------------  // acclient.c:460679
void __thiscall RenderDeviceD3D::SetStageTexture(RenderDeviceD3D *this, const unsigned int _Stage, RenderTexture *_pTexture)
{
  IDirect3DTexture9 *v3; // ebx@1
  RenderDeviceD3D *v4; // edi@1

  v3 = 0;
  v4 = this;
  if ( _pTexture
    && (!_pTexture->m_bIsLost || _pTexture->vfptr->RestoreResource((GraphicsResource *)&_pTexture->vfptr))
    && _pTexture->m_TextureType == 2 )
    v3 = RenderTextureD3D::Get2DTextureD3D((RenderTextureD3D *)_pTexture);
  if ( v4->m_bForceStates || v3 != (IDirect3DTexture9 *)v4->m_State.Stages[_Stage].pTexture )
  {
    ((void (__stdcall *)(_DWORD, const unsigned int, IDirect3DTexture9 *))v4->m_pDirect3DDevice->vfptr[21].Release)(
      v4->m_pDirect3DDevice,
      _Stage,
      v3);
    v4->m_State.Stages[_Stage].pTexture = v3;
  }
}

//----- (005A36C0) --------------------------------------------------------  // acclient.c:460701
void __thiscall RenderDeviceD3D::SetStageTexture(RenderDeviceD3D *this, const unsigned int _Stage, IDirect3DTexture9 *_pTexture)
{
  RenderDeviceD3D *v3; // edi@1

  v3 = this;
  if ( this->m_bForceStates || _pTexture != (IDirect3DTexture9 *)this->m_State.Stages[_Stage].pTexture )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pDirect3DDevice->vfptr[21].Release)(
      this->m_pDirect3DDevice,
      _Stage,
      _pTexture);
    v3->m_State.Stages[_Stage].pTexture = _pTexture;
  }
}

//----- (005A3710) --------------------------------------------------------  // acclient.c:460717
void __thiscall RenderDeviceD3D::SetModelToWorldMatrix(RenderDeviceD3D *this, Matrix4 *_m)
{
  IDirect3DDevice9 *v2; // eax@1

  v2 = this->m_pDirect3DDevice;
  qmemcpy(&this->m_GState, _m, 0x40u);
  ((void (__stdcall *)(IDirect3DDevice9 *, signed int, Matrix4 *))v2->vfptr[14].Release)(v2, 256, _m);
}

//----- (005A3750) --------------------------------------------------------  // acclient.c:460727
void __thiscall RenderDeviceD3D::SetWorldToViewMatrix(RenderDeviceD3D *this, Matrix4 *_m)
{
  IDirect3DDevice9 *v2; // eax@1

  v2 = this->m_pDirect3DDevice;
  qmemcpy(&this->m_GState.WorldToViewMatrix, _m, sizeof(this->m_GState.WorldToViewMatrix));
  ((void (__stdcall *)(IDirect3DDevice9 *, signed int, Matrix4 *))v2->vfptr[14].Release)(v2, 2, _m);
}

//----- (005A3780) --------------------------------------------------------  // acclient.c:460737
void __thiscall RenderDeviceD3D::SetViewToClipMatrix(RenderDeviceD3D *this, Matrix4 *_m)
{
  IDirect3DDevice9 *v2; // eax@1

  v2 = this->m_pDirect3DDevice;
  qmemcpy(&this->m_GState.ViewToClipMatrix, _m, sizeof(this->m_GState.ViewToClipMatrix));
  ((void (__stdcall *)(IDirect3DDevice9 *, signed int, Matrix4 *))v2->vfptr[14].Release)(v2, 3, _m);
}

//----- (005A37B0) --------------------------------------------------------  // acclient.c:460747
void __cdecl RenderDeviceD3D::TransformPixelToClipPoint(const int _nX, const int _nY, const int _nWidth, const int _nHeight, float *_fClipX, float *_fClipY)
{
  double v6; // st7@1
  double v7; // st6@1

  v6 = 1.0 / (double)_nWidth;
  v7 = 1.0 / (double)_nHeight;
  *_fClipX = (double)_nX * v6 + (double)_nX * v6 - 1.0;
  *_fClipY = -((double)_nY * v7 + (double)_nY * v7 - 1.0);
  *_fClipX = *_fClipX - v6;
  *_fClipY = *_fClipY - v7;
}

//----- (005A3800) --------------------------------------------------------  // acclient.c:460761
char __thiscall RenderDeviceD3D::SetDefaultD3DStates(RenderDeviceD3D *this)
{
  RenderDeviceD3D *v1; // esi@1
  void **v2; // ecx@3
  unsigned int v3; // edi@5
  unsigned int v4; // edi@7

  v1 = this;
  this->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)this->m_pDirect3DDevice, (_GUID *)7, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)8, (void **)3);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)9, (void **)2);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)14, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)15, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)16, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)19, (void **)2);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)20, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)22, (void **)3);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)23, (void **)4);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)24, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)25, (void **)7);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)26, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)27, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)28, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)29, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)34, (void **)11184810);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)35, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)36, (void **)1137180672);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)37, (void **)1157234688);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)38, (void **)1045220557);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)48, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)52, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)53, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)54, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)55, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)56, (void **)8);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)57, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)58, (void **)-1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)59, (void **)-1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)60, (void **)-1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)128, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)129, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)130, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)131, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)132, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)133, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)134, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)135, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)136, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)137, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)139, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)140, (void **)3);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)141, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)142, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)143, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)145, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)146, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)147, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)148, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)151, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)152, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)154, (void **)1065353216);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)155, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)156, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)157, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)158, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)159, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)160, (void **)1065353216);
  v2 = (void **)(v1->m_displayInfo.bMultiSampling && v1->m_presentation.Antialiasing);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)161, v2);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)162, (void **)-1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)163, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)165, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface(
    (IUnknown *)v1->m_pDirect3DDevice,
    (_GUID *)166,
    LODWORD(v1->m_D3DCaps.MaxPointSize));
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)167, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)168, (void **)7);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)170, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)171, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)172, (void **)3);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)173, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)174, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)176, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)178, (void **)1065353216);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)179, (void **)1065353216);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)180, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)181, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)182, (void **)1065353216);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)183, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)184, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)186, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)187, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)188, (void **)1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)189, (void **)8);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)193, (void **)-1);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)194, 0);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)195, 0);
  v3 = 0;
  do
  {
    ((void (__stdcall *)(_DWORD, unsigned int, signed int, signed int))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      1,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      2,
      2);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      3,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      4,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      5,
      2);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      6,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      7,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      8,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      9,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      10,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, unsigned int))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      11,
      v3);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      22,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      23,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      24,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      26,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3,
      27,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[22].AddRef)(
      v1->m_pDirect3DDevice,
      v3++,
      28,
      1);
  }
  while ( v3 < 8 );
  v4 = 0;
  do
  {
    ((void (__stdcall *)(_DWORD, unsigned int, signed int, signed int))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      1,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      2,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      3,
      3);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      4,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      5,
      2);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      6,
      2);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      7,
      1);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      8,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      9,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      10,
      v1->m_D3DCaps.MaxAnisotropy);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      11,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4,
      12,
      0);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v1->m_pDirect3DDevice->vfptr[23].QueryInterface)(
      v1->m_pDirect3DDevice,
      v4++,
      13,
      256);
  }
  while ( v4 < 0x10 );
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)140, (void **)3);
  v1->m_pDirect3DDevice->vfptr[19].QueryInterface((IUnknown *)v1->m_pDirect3DDevice, (_GUID *)48, (void **)1);
  ((void (__stdcall *)(_DWORD, _DWORD))v1->m_pDirect3DDevice->vfptr[25].Release)(
    v1->m_pDirect3DDevice,
    v1->m_caps.bHardwareVertexProcessing == 0);
  return 1;
}

//----- (0070C5E0) --------------------------------------------------------  // acclient.c:799339
void sub_70C5E0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8ED5A0, PFID_A8R8G8B8);
}

//----- (0070C5F0) --------------------------------------------------------  // acclient.c:799345
void sub_70C5F0()
{
  LODWORD(dword_8ED5D8) = 1053364187;
}

//----- (0070C600) --------------------------------------------------------  // acclient.c:799351
void sub_70C600()
{
  flt_8ED5DC = 1000.0 + 1.0;
}

//----- (0070C620) --------------------------------------------------------  // acclient.c:799357
void sub_70C620()
{
  flt_8ED5E0 = 24.0 * 8.0;
}

//----- (0070C640) --------------------------------------------------------  // acclient.c:799363
void sub_70C640()
{
  flt_8ED5E4 = 24.0 * 0.5;
}

//----- (0070C660) --------------------------------------------------------  // acclient.c:799369
int _E99_40()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_40, "Render.TextureFiltering");
  return atexit(sub_776240);
}

//----- (0070C680) --------------------------------------------------------  // acclient.c:799376
int _E102_35()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_40, "Render.LandscapeDetailTextures");
  return atexit(sub_776270);
}

//----- (0070C6A0) --------------------------------------------------------  // acclient.c:799383
int _E105_53()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_40, "Render.BuildingDetailTextures");
  return atexit(sub_7762A0);
}

//----- (0070C6C0) --------------------------------------------------------  // acclient.c:799390
int sub_70C6C0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_40, "Render.FieldOfView");
  return atexit(sub_7762D0);
}

//----- (0070C6E0) --------------------------------------------------------  // acclient.c:799397
int _E111_56()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_40, "Render.LandscapeTextureDetail");
  return atexit(sub_776300);
}

//----- (0070C700) --------------------------------------------------------  // acclient.c:799404
int _E114_64()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_40, "Render.EnvironmentTextureDetail");
  return atexit(sub_776330);
}

//----- (0070C720) --------------------------------------------------------  // acclient.c:799411
int _E117_81()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_40, "Render.SceneryDrawDistance");
  return atexit(sub_776360);
}

//----- (0070C740) --------------------------------------------------------  // acclient.c:799418
int _E120_74()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_40, "Render.LandscapeDrawDistance");
  return atexit(sub_776390);
}

//----- (0070C760) --------------------------------------------------------  // acclient.c:799425
int _E123_45()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_40, "Render.ScreenBrightness");
  return atexit(sub_7763C0);
}

//----- (0070C780) --------------------------------------------------------  // acclient.c:799432
int _E126_52()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_40, "Render.AspectRatio");
  return atexit(sub_7763F0);
}

//----- (0070C7A0) --------------------------------------------------------  // acclient.c:799439
int _E129_46()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_40, "Render.DisplayAdapter");
  return atexit(sub_776420);
}

//----- (0070C7C0) --------------------------------------------------------  // acclient.c:799446
int _E132_47()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_40, "Render.MaxHardwareClass");
  return atexit(sub_776450);
}

//----- (0070C7E0) --------------------------------------------------------  // acclient.c:799453
int _E135_54()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_40, "Render.AutomaticDegrades");
  return atexit(_E136_89);
}

//----- (0070C800) --------------------------------------------------------  // acclient.c:799460
int _E138_42()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_40, "Render.GraphicsPerformance");
  return atexit(_E139_89);
}

//----- (0070C820) --------------------------------------------------------  // acclient.c:799467
int _E141_44()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_40, "Render.DegradeDistance");
  return atexit(_E142_84);
}

//----- (0070C840) --------------------------------------------------------  // acclient.c:799474
int _E144_41()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_40, "Render.MultiPassAlpha");
  return atexit(_E145_86);
}

//----- (0070C860) --------------------------------------------------------  // acclient.c:799481
int _E147_40()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_40, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED630, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED634, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8ED638, "Anisotropic");
  return atexit(_E148_82);
}

//----- (0070C8B0) --------------------------------------------------------  // acclient.c:799491
int _E150_39()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_40, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED640, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED644, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED648, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED64C, "VeryHigh");
  return atexit(_E151_80);
}

//----- (0070C910) --------------------------------------------------------  // acclient.c:799502
int _E153_37()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_40, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED654, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED658, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED65C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED660, "VeryHigh");
  return atexit(_E154_81);
}

//----- (0070C970) --------------------------------------------------------  // acclient.c:799513
int _E156_39()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_40, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED668, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED66C, "High");
  return atexit(_E157_77);
}

//----- (0070C9B0) --------------------------------------------------------  // acclient.c:799522
int _E159_37()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_40, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED674, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED678, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED67C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED680, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8ED684, "Extreme");
  return atexit(_E160_80);
}

//----- (0070CA20) --------------------------------------------------------  // acclient.c:799534
int _E162_40()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_40, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8ED68C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8ED690, "Wide");
  return atexit(_E163_73);
}

//----- (0070CA60) --------------------------------------------------------  // acclient.c:799543
int _E165_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_67, "None");
  return atexit(_E166_75);
}

//----- (0070CA80) --------------------------------------------------------  // acclient.c:799550
int _E168_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_67, "Speed");
  return atexit(_E169_74);
}

//----- (0070CAA0) --------------------------------------------------------  // acclient.c:799557
int _E171_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_67, "Noise");
  return atexit(_E172_72);
}

//----- (0070CAC0) --------------------------------------------------------  // acclient.c:799564
int _E174_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_67, "Sine");
  return atexit(_E175_69);
}

//----- (0070CAE0) --------------------------------------------------------  // acclient.c:799571
int _E177_34()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_67, "Square");
  return atexit(_E178_69);
}

//----- (0070CB00) --------------------------------------------------------  // acclient.c:799578
int _E180_34()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_67, "Bounce");
  return atexit(_E181_69);
}

//----- (0070CB20) --------------------------------------------------------  // acclient.c:799585
int _E183_33()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_67, "Perlin");
  return atexit(_E184_66);
}

//----- (0070CB40) --------------------------------------------------------  // acclient.c:799592
int _E186_33()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_67, "Fractal");
  return atexit(_E187_65);
}

//----- (0070CB60) --------------------------------------------------------  // acclient.c:799599
int _E189_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_67, "FrameLoop");
  return atexit(_E190_66);
}

//----- (0070CB80) --------------------------------------------------------  // acclient.c:799606
int sub_70CB80()
{
  return atexit(nullsub_1448);
}

//----- (00776240) --------------------------------------------------------  // acclient.c:909889
void __cdecl sub_776240()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776270) --------------------------------------------------------  // acclient.c:909902
void __cdecl sub_776270()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007762A0) --------------------------------------------------------  // acclient.c:909915
void __cdecl sub_7762A0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007762D0) --------------------------------------------------------  // acclient.c:909928
void __cdecl sub_7762D0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776300) --------------------------------------------------------  // acclient.c:909941
void __cdecl sub_776300()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776330) --------------------------------------------------------  // acclient.c:909954
void __cdecl sub_776330()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776360) --------------------------------------------------------  // acclient.c:909967
void __cdecl sub_776360()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776390) --------------------------------------------------------  // acclient.c:909980
void __cdecl sub_776390()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007763C0) --------------------------------------------------------  // acclient.c:909993
void __cdecl sub_7763C0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007763F0) --------------------------------------------------------  // acclient.c:910006
void __cdecl sub_7763F0()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776420) --------------------------------------------------------  // acclient.c:910019
void __cdecl sub_776420()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776450) --------------------------------------------------------  // acclient.c:910032
void __cdecl sub_776450()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776480) --------------------------------------------------------  // acclient.c:910045
void __cdecl _E136_89()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007764B0) --------------------------------------------------------  // acclient.c:910058
void __cdecl _E139_89()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007764E0) --------------------------------------------------------  // acclient.c:910071
void __cdecl _E142_84()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776510) --------------------------------------------------------  // acclient.c:910084
void __cdecl _E145_86()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776540) --------------------------------------------------------  // acclient.c:910097
void __cdecl _E148_82()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_40;
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

//----- (00776580) --------------------------------------------------------  // acclient.c:910122
void __cdecl _E151_80()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_40;
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

//----- (007765C0) --------------------------------------------------------  // acclient.c:910147
void __cdecl _E154_81()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_40;
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

//----- (00776600) --------------------------------------------------------  // acclient.c:910172
void __cdecl _E157_77()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_40;
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

//----- (00776640) --------------------------------------------------------  // acclient.c:910197
void __cdecl _E160_80()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_40;
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

//----- (00776680) --------------------------------------------------------  // acclient.c:910222
void __cdecl _E163_73()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_67;
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

//----- (007766C0) --------------------------------------------------------  // acclient.c:910247
void __cdecl _E166_75()
{
  char *v0; // esi@1

  v0 = &waveform_None_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007766F0) --------------------------------------------------------  // acclient.c:910260
void __cdecl _E169_74()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776720) --------------------------------------------------------  // acclient.c:910273
void __cdecl _E172_72()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776750) --------------------------------------------------------  // acclient.c:910286
void __cdecl _E175_69()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776780) --------------------------------------------------------  // acclient.c:910299
void __cdecl _E178_69()
{
  char *v0; // esi@1

  v0 = &waveform_Square_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007767B0) --------------------------------------------------------  // acclient.c:910312
void __cdecl _E181_69()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007767E0) --------------------------------------------------------  // acclient.c:910325
void __cdecl _E184_66()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776810) --------------------------------------------------------  // acclient.c:910338
void __cdecl _E187_65()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776840) --------------------------------------------------------  // acclient.c:910351
void __cdecl _E190_66()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

