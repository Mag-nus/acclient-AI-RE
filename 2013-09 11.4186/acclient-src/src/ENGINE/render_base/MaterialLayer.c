/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MaterialLayer
   Object     : ENGINE\render_base\MaterialLayer.obj
   Functions  : 929
   Addresses  : 0044A200 - 00740BD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044A200) --------------------------------------------------------  // acclient.c:134934
char __thiscall MaterialLayer::GetSubObjects(MaterialLayer *this, SmartArray<PStringBase<char>,1> *_MaterialShaderConstants)
{
  MaterialLayer *v2; // edi@1
  unsigned int v3; // esi@1
  char v4; // bl@1

  v2 = this;
  v3 = 0;
  v4 = 1;
  if ( this->m_Stages.m_num )
  {
    do
    {
      if ( !LayerStage::GetSubObjects(v2->m_Stages.m_data[v3]) )
        v4 = 0;
      ++v3;
    }
    while ( v3 < v2->m_Stages.m_num );
  }
  return v4;
}

//----- (0044A240) --------------------------------------------------------  // acclient.c:134957
char __thiscall MaterialLayer::ReleaseSubObjects(MaterialLayer *this)
{
  MaterialLayer *v1; // edi@1
  unsigned int v2; // esi@1
  char v3; // bl@1

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->m_Stages.m_num )
  {
    do
    {
      if ( !LayerStage::ReleaseSubObjects(v1->m_Stages.m_data[v2]) )
        v3 = 0;
      ++v2;
    }
    while ( v2 < v1->m_Stages.m_num );
  }
  return v3;
}

//----- (0044A270) --------------------------------------------------------  // acclient.c:134980
void __thiscall ShaderResourceType::ShaderResourceType(ShaderResourceType *this)
{
  ShaderResourceType *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->VertexShaderFunctionName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->PixelShaderFunctionName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  SmartBuffer::SmartBuffer(&v1->BinaryVertexShaderData);
  SmartBuffer::SmartBuffer(&v1->BinaryPixelShaderData);
}

//----- (0044A2B0) --------------------------------------------------------  // acclient.c:134998
void __thiscall ShaderResourceType::~ShaderResourceType(ShaderResourceType *this)
{
  ShaderResourceType *v1; // edi@1
  int v2; // esi@1
  int v3; // edi@4

  v1 = this;
  SmartBuffer::ReleaseMasterBuffer(&this->BinaryPixelShaderData);
  SmartBuffer::ReleaseMasterBuffer(&v1->BinaryVertexShaderData);
  v2 = (int)&v1->PixelShaderFunctionName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->VertexShaderFunctionName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (0044A310) --------------------------------------------------------  // acclient.c:135019
int __thiscall ShaderResourceType::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // ebx@7
  int v8; // eax@10

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *(_DWORD *)(v2 + 8);
  if ( v6 != *(_DWORD *)(a2 + 8) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  SmartBuffer::operator=(v2 + 12, a2 + 12);
  SmartBuffer::operator=(v2 + 24, a2 + 24);
  return v2;
}

//----- (0044A3B0) --------------------------------------------------------  // acclient.c:135057
void __thiscall MaterialLayer::End(MaterialLayer *this)
{
  MaterialLayer *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int i; // edi@3
  LayerStage **v4; // ecx@4
  void *v5; // ebx@4
  unsigned int v6; // eax@7
  unsigned int v7; // ecx@7
  int j; // eax@10
  unsigned int k; // edi@12
  unsigned int v10; // eax@14
  unsigned int v11; // edx@14
  int l; // eax@17

  v1 = this;
  v2 = 0;
  if ( this->m_Stages.m_num )
  {
    do
      LayerStage::ReleaseSubObjects(v1->m_Stages.m_data[v2++]);
    while ( v2 < v1->m_Stages.m_num );
  }
  for ( i = 0; i < v1->m_Stages.m_num; ++i )
  {
    v4 = v1->m_Stages.m_data;
    v5 = v4[i];
    if ( v5 )
    {
      LayerStage::~LayerStage(v4[i]);
      operator delete(v5);
    }
    v1->m_Stages.m_data[i] = 0;
  }
  v6 = v1->m_Stages.m_sizeAndDeallocate;
  v7 = v1->m_Stages.m_sizeAndDeallocate & 0x80000000;
  v1->m_Stages.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_Stages.m_data);
    v1->m_Stages.m_data = 0;
    v1->m_Stages.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_Stages.m_data )
  {
    for ( j = (v6 & 0x7FFFFFFF) - 1; j >= 0; v1->m_Stages.m_data[j + 1] = 0 )
      --j;
  }
  for ( k = 0; k < v1->m_FFModifiers.m_num; ++k )
  {
    operator delete(v1->m_FFModifiers.m_data[k]);
    v1->m_FFModifiers.m_data[k] = 0;
  }
  v10 = v1->m_FFModifiers.m_sizeAndDeallocate;
  v11 = v1->m_FFModifiers.m_sizeAndDeallocate & 0x80000000;
  v1->m_FFModifiers.m_num = 0;
  if ( v11 == 0x80000000 )
  {
    operator delete[](v1->m_FFModifiers.m_data);
    v1->m_FFModifiers.m_data = 0;
    v1->m_FFModifiers.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_FFModifiers.m_data )
  {
    for ( l = (v10 & 0x7FFFFFFF) - 1; l >= 0; v1->m_FFModifiers.m_data[l + 1] = 0 )
      --l;
  }
}

//----- (0044A4C0) --------------------------------------------------------  // acclient.c:135127
void *__thiscall ShaderResourceType::vector_deleting_destructor(ShaderResourceType *this, unsigned int a2)
{
  ShaderResourceType *v2; // esi@1
  GrowBuffer *v3; // eax@2
  char *v4; // ebx@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@2
  int v8; // edi@3
  int v9; // esi@4
  int v10; // esi@7
  void *result; // eax@13
  int v12; // [sp+8h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].BinaryPixelShaderData.m_masterBuffer;
    v4 = (char *)&this[-1].BinaryPixelShaderData.m_masterBuffer;
    v5 = 9 * (_DWORD)v3;
    v6 = (int)(&v3[-1].m_bAllocateFromFreelist + 1);
    v7 = (int)&v2[4 * v5 / 0x24u];
    if ( v6 >= 0 )
    {
      v8 = v7 + 12;
      v12 = v6 + 1;
      do
      {
        v8 -= 36;
        SmartBuffer::ReleaseMasterBuffer((SmartBuffer *)(v8 + 12));
        SmartBuffer::ReleaseMasterBuffer((SmartBuffer *)v8);
        v9 = *(_DWORD *)(v8 - 4) - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        v10 = *(_DWORD *)(v8 - 8) - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        --v12;
      }
      while ( v12 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    ShaderResourceType::~ShaderResourceType(this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (0044A580) --------------------------------------------------------  // acclient.c:135183
void __thiscall SmartArray<ShaderResourceType,1>::Reset(SmartArray<ShaderResourceType,1> *this)
{
  SmartArray<ShaderResourceType,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // esi@7
  int v6; // ebp@7
  ShaderResourceType v7; // [sp+8h] [bp-24h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      ShaderResourceType::vector_deleting_destructor(v1->m_data, 3u);
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
        v7.VertexShaderFunctionName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v7.PixelShaderFunctionName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        SmartBuffer::SmartBuffer(&v7.BinaryVertexShaderData);
        SmartBuffer::SmartBuffer(&v7.BinaryPixelShaderData);
        ShaderResourceType::operator=((int)&v1->m_data[v5], (int)&v7);
        ShaderResourceType::~ShaderResourceType(&v7);
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (0044A6A0) --------------------------------------------------------  // acclient.c:135267
char __thiscall SmartArray<ShaderResourceType,1>::grow(SmartArray<ShaderResourceType,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<ShaderResourceType,1> *v3; // edi@1
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
      SmartArray<ShaderResourceType,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](36 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x24u,
        i_nSize,
        (void *(__thiscall *)(void *))ShaderResourceType::ShaderResourceType);
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
              ShaderResourceType::operator=(v8 * 36 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              ShaderResourceType::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (ShaderResourceType *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (0044A780) --------------------------------------------------------  // acclient.c:135331
void __thiscall MaterialLayer::~MaterialLayer(MaterialLayer *this)
{
  MaterialLayer *v1; // esi@1
  ShaderResourceType *v2; // ecx@6

  v1 = this;
  MaterialLayer::End(this);
  if ( (v1->m_FFModifiers.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_FFModifiers.m_data);
  if ( (v1->m_Stages.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_Stages.m_data);
  if ( (v1->m_ShaderResources.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = v1->m_ShaderResources.m_data;
    if ( v2 )
      ShaderResourceType::vector_deleting_destructor(v2, 3u);
  }
}

//----- (0044A7F0) --------------------------------------------------------  // acclient.c:135351
void __thiscall MaterialLayer::Begin(MaterialLayer *this)
{
  MaterialLayer *v1; // esi@1
  int v2; // eax@1
  int v3; // ecx@1
  float v4; // eax@1
  Waveform v5; // [sp+8h] [bp-2Ch]@1

  v1 = this;
  this->m_Options = 0;
  this->m_TrueFlags = 0;
  this->m_FalseFlags = 0;
  this->m_RenderPass = 0;
  SmartArray<ShaderResourceType,1>::Reset(&this->m_ShaderResources);
  v1->m_SourceBlend = 2;
  v1->m_CullMode = 2;
  v1->m_DestBlend = 1;
  v1->m_BlendOp = 1;
  v1->m_DepthTest = 4;
  v1->m_DepthWrite = 1;
  v1->m_AlphaTest = 0;
  Waveform::Waveform(&v5, 0.89999998);
  v1->m_AlphaTestRef.type = *(_DWORD *)v2;
  LODWORD(v1->m_AlphaTestRef.base) = *(_DWORD *)(v2 + 4);
  LODWORD(v1->m_AlphaTestRef.base_vel) = *(_DWORD *)(v2 + 8);
  LODWORD(v1->m_AlphaTestRef.amplitude) = *(_DWORD *)(v2 + 12);
  LODWORD(v1->m_AlphaTestRef.amplitude_vel) = *(_DWORD *)(v2 + 16);
  LODWORD(v1->m_AlphaTestRef.phase) = *(_DWORD *)(v2 + 20);
  LODWORD(v1->m_AlphaTestRef.phase_vel) = *(_DWORD *)(v2 + 24);
  LODWORD(v1->m_AlphaTestRef.frequency) = *(_DWORD *)(v2 + 28);
  LODWORD(v1->m_AlphaTestRef.frequency_vel) = *(_DWORD *)(v2 + 32);
  LODWORD(v1->m_AlphaTestRef.roughness) = *(_DWORD *)(v2 + 36);
  LODWORD(v1->m_AlphaTestRef.roughness_vel) = *(_DWORD *)(v2 + 40);
  v1->m_cDiffuse = RGBAColor_White_19;
  v3 = (int)&v1->m_cSpecular;
  *(_DWORD *)v3 = (_DWORD)RGBAColor_White_19.r;
  *(_DWORD *)(v3 + 4) = LODWORD(RGBAColor_White_19.g);
  *(_DWORD *)(v3 + 8) = LODWORD(RGBAColor_White_19.b);
  v4 = RGBAColor_White_19.a;
  LODWORD(v1->m_wSpecularPower.base) = 0;
  *(float *)(v3 + 12) = v4;
  v1->m_cDye = RGBAColor_White_19;
}

//----- (0044A900) --------------------------------------------------------  // acclient.c:135396
void __thiscall MaterialLayer::MaterialLayer(MaterialLayer *this)
{
  MaterialLayer *v1; // esi@1

  v1 = this;
  this->m_ShaderResources.m_data = 0;
  this->m_ShaderResources.m_sizeAndDeallocate = 0;
  this->m_ShaderResources.m_num = 0;
  this->m_Stages.m_data = 0;
  this->m_Stages.m_sizeAndDeallocate = 0;
  this->m_Stages.m_num = 0;
  this->m_FFModifiers.m_data = 0;
  this->m_FFModifiers.m_sizeAndDeallocate = 0;
  this->m_FFModifiers.m_num = 0;
  Waveform::Waveform(&this->m_AlphaTestRef);
  Waveform::Waveform(&v1->m_wSpecularPower);
  MaterialLayer::Begin(v1);
}

//----- (0044A940) --------------------------------------------------------  // acclient.c:135416
char __thiscall MaterialLayer::CopyInto(MaterialLayer *this, const bool _IsInstance, MaterialLayer *target)
{
  unsigned int v3; // ecx@2
  int v4; // esi@2
  unsigned int v5; // eax@3
  unsigned int v6; // eax@4
  int v7; // edi@6
  char *v8; // ebp@6
  int v9; // eax@6
  int v10; // ebx@7
  int v11; // eax@10
  int v12; // edi@11
  char *v13; // ebp@11
  int v14; // eax@11
  int v15; // ebx@12
  int v16; // eax@15
  ShaderResourceType *v17; // edi@16
  int v18; // eax@16
  ShaderResourceType *v19; // edi@16
  int v20; // eax@16
  unsigned int v21; // ecx@16
  char *v22; // ecx@17
  char *v23; // edx@17
  char *v24; // eax@17
  char *v25; // ecx@17
  char *v26; // edx@17
  MaterialLayer *v27; // eax@17
  unsigned int v28; // esi@17
  unsigned int v29; // edi@18
  unsigned int v30; // eax@19
  void **v31; // esi@19
  unsigned int v32; // ecx@19
  int i; // eax@22
  MaterialLayer *v34; // eax@24
  unsigned int v35; // edx@24
  unsigned int v36; // ecx@24
  unsigned int v37; // ebx@25
  char *v38; // esi@25
  int v39; // ebp@25
  unsigned int v40; // eax@25
  unsigned int v41; // ecx@26
  unsigned int v42; // edx@27
  unsigned int v48; // edx@35
  int v49; // ecx@36
  int j; // eax@36
  unsigned int v51; // edx@39
  MaterialLayer *v53; // [sp+10h] [bp-24h]@1
  unsigned int im; // [sp+14h] [bp-20h]@2
  unsigned int v55; // [sp+18h] [bp-1Ch]@32
  SmartBuffer result; // [sp+1Ch] [bp-18h]@16
  SmartBuffer v57; // [sp+28h] [bp-Ch]@16

  v53 = this;
  MaterialLayer::End(target);
  target->m_Options = v53->m_Options;
  target->m_TrueFlags = v53->m_TrueFlags;
  target->m_FalseFlags = v53->m_FalseFlags;
  target->m_RenderPass = v53->m_RenderPass;
  SmartArray<ShaderResourceType,1>::Reset(&target->m_ShaderResources);
  if ( !_IsInstance )
  {
    v3 = v53->m_ShaderResources.m_num;
    v4 = 0;
    im = 0;
    if ( v3 )
    {
      do
      {
        v5 = target->m_ShaderResources.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( target->m_ShaderResources.m_num < v5
          || (v6 = SmartArray<UIChildFramework *,1>::get_new_size(v5 + 1),
              SmartArray<ShaderResourceType,1>::grow(&target->m_ShaderResources, v6)) )
          ++target->m_ShaderResources.m_num;
        target->m_ShaderResources.m_data[v4].Version = v53->m_ShaderResources.m_data[v4].Version;
        v7 = (int)&v53->m_ShaderResources.m_data[v4].VertexShaderFunctionName;
        v8 = (char *)&target->m_ShaderResources.m_data[v4].VertexShaderFunctionName;
        v9 = *(_DWORD *)v8;
        if ( *(_DWORD *)v8 != *(_DWORD *)v7 )
        {
          v10 = v9 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v9 - 20 + 4)) && v10 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
          v11 = *(_DWORD *)v7;
          *(_DWORD *)v8 = *(_DWORD *)v7;
          InterlockedIncrement((volatile LONG *)(v11 - 16));
        }
        v12 = (int)&v53->m_ShaderResources.m_data[v4].PixelShaderFunctionName;
        v13 = (char *)&target->m_ShaderResources.m_data[v4].PixelShaderFunctionName;
        v14 = *(_DWORD *)v13;
        if ( *(_DWORD *)v13 != *(_DWORD *)v12 )
        {
          v15 = v14 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v14 - 20 + 4)) && v15 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
          v16 = *(_DWORD *)v12;
          *(_DWORD *)v13 = *(_DWORD *)v12;
          InterlockedIncrement((volatile LONG *)(v16 - 16));
        }
        v17 = &target->m_ShaderResources.m_data[v4];
        v18 = (int)SmartBuffer::Clone(&v53->m_ShaderResources.m_data[v4].BinaryVertexShaderData, &result);
        SmartBuffer::operator=((int)&v17->BinaryVertexShaderData, v18);
        SmartBuffer::ReleaseMasterBuffer(&result);
        v19 = &target->m_ShaderResources.m_data[v4];
        v20 = (int)SmartBuffer::Clone(&v53->m_ShaderResources.m_data[v4].BinaryPixelShaderData, &v57);
        SmartBuffer::operator=((int)&v19->BinaryPixelShaderData, v20);
        SmartBuffer::ReleaseMasterBuffer(&v57);
        v21 = v53->m_ShaderResources.m_num;
        ++v4;
        ++im;
      }
      while ( im < v21 );
    }
  }
  target->m_SourceBlend = v53->m_SourceBlend;
  target->m_DestBlend = v53->m_DestBlend;
  target->m_BlendOp = v53->m_BlendOp;
  target->m_DepthTest = v53->m_DepthTest;
  target->m_DepthWrite = v53->m_DepthWrite;
  target->m_CullMode = v53->m_CullMode;
  target->m_AlphaTest = v53->m_AlphaTest;
  target->m_AlphaTestRef.type = v53->m_AlphaTestRef.type;
  target->m_AlphaTestRef.base = v53->m_AlphaTestRef.base;
  target->m_AlphaTestRef.base_vel = v53->m_AlphaTestRef.base_vel;
  v22 = (char *)&target->m_AlphaTestRef;
  *((_DWORD *)v22 + 3) = LODWORD(v53->m_AlphaTestRef.amplitude);
  *((_DWORD *)v22 + 4) = LODWORD(v53->m_AlphaTestRef.amplitude_vel);
  *((_DWORD *)v22 + 5) = LODWORD(v53->m_AlphaTestRef.phase);
  *((_DWORD *)v22 + 6) = LODWORD(v53->m_AlphaTestRef.phase_vel);
  *((_DWORD *)v22 + 7) = LODWORD(v53->m_AlphaTestRef.frequency);
  *((_DWORD *)v22 + 8) = LODWORD(v53->m_AlphaTestRef.frequency_vel);
  *((_DWORD *)v22 + 9) = LODWORD(v53->m_AlphaTestRef.roughness);
  *((_DWORD *)v22 + 10) = LODWORD(v53->m_AlphaTestRef.roughness_vel);
  v23 = (char *)&target->m_cDiffuse;
  *(_DWORD *)v23 = LODWORD(v53->m_cDiffuse.r);
  *((_DWORD *)v23 + 1) = LODWORD(v53->m_cDiffuse.g);
  *((_DWORD *)v23 + 2) = LODWORD(v53->m_cDiffuse.b);
  *((_DWORD *)v23 + 3) = LODWORD(v53->m_cDiffuse.a);
  v24 = (char *)&target->m_cSpecular;
  *(_DWORD *)v24 = LODWORD(v53->m_cSpecular.r);
  *((_DWORD *)v24 + 1) = LODWORD(v53->m_cSpecular.g);
  *((_DWORD *)v24 + 2) = LODWORD(v53->m_cSpecular.b);
  *((_DWORD *)v24 + 3) = LODWORD(v53->m_cSpecular.a);
  target->m_wSpecularPower.type = v53->m_wSpecularPower.type;
  v25 = (char *)&target->m_wSpecularPower;
  *((_DWORD *)v25 + 1) = LODWORD(v53->m_wSpecularPower.base);
  *((_DWORD *)v25 + 2) = LODWORD(v53->m_wSpecularPower.base_vel);
  *((_DWORD *)v25 + 3) = LODWORD(v53->m_wSpecularPower.amplitude);
  *((_DWORD *)v25 + 4) = LODWORD(v53->m_wSpecularPower.amplitude_vel);
  *((_DWORD *)v25 + 5) = LODWORD(v53->m_wSpecularPower.phase);
  *((_DWORD *)v25 + 6) = LODWORD(v53->m_wSpecularPower.phase_vel);
  *((_DWORD *)v25 + 7) = LODWORD(v53->m_wSpecularPower.frequency);
  *((_DWORD *)v25 + 8) = LODWORD(v53->m_wSpecularPower.frequency_vel);
  *((_DWORD *)v25 + 9) = LODWORD(v53->m_wSpecularPower.roughness);
  *((_DWORD *)v25 + 10) = LODWORD(v53->m_wSpecularPower.roughness_vel);
  v26 = (char *)&target->m_cDye;
  *(_DWORD *)v26 = LODWORD(v53->m_cDye.r);
  *((_DWORD *)v26 + 1) = LODWORD(v53->m_cDye.g);
  *((_DWORD *)v26 + 2) = LODWORD(v53->m_cDye.b);
  *((_DWORD *)v26 + 3) = LODWORD(v53->m_cDye.a);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&target->m_Stages);
  v27 = v53;
  v28 = 0;
  if ( v53->m_Stages.m_num )
  {
    do
    {
      v29 = target->m_Stages.m_num;
      im = LayerStage::Copy(v27->m_Stages.m_data[v28], _IsInstance);
      SmartArray<LayerStage *,1>::InsertOrderedByIndex(
        (SmartArray<EffectInfoRegion *,1> *)&target->m_Stages,
        (EffectInfoRegion *const *)&im,
        v29);
      v27 = v53;
      ++v28;
    }
    while ( v28 < v53->m_Stages.m_num );
  }
  v30 = target->m_FFModifiers.m_sizeAndDeallocate;
  v31 = (void **)&target->m_FFModifiers.m_data;
  v32 = target->m_FFModifiers.m_sizeAndDeallocate & 0x80000000;
  target->m_FFModifiers.m_num = 0;
  if ( v32 == 0x80000000 )
  {
    operator delete[](*v31);
    *v31 = 0;
    target->m_FFModifiers.m_sizeAndDeallocate = 0;
  }
  else if ( *v31 )
  {
    for ( i = (v30 & 0x7FFFFFFF) - 1; i >= 0; *((_DWORD *)*v31 + i + 1) = 0 )
      --i;
  }
  v34 = v53;
  v35 = v53->m_FFModifiers.m_num;
  v36 = 0;
  im = 0;
  if ( v35 > 0 )
  {
    do
    {
      v37 = target->m_FFModifiers.m_num;
      v38 = (char *)&target->m_FFModifiers;
      v39 = ((int (*)(void))v34->m_FFModifiers.m_data[v36]->vfptr->Copy)();
      v40 = target->m_FFModifiers.m_num;
      if ( v37 <= v40 )
      {
        v41 = target->m_FFModifiers.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v40 < v41 )
          goto LABEL_43;
        v42 = v41 + 1;
        if ( v41 + 1 > 8 )
        {
          if ( v42 <= 0x4000 )
          {
            v55 = v41 + 1;
            __asm { bsr     this, [esp+34h+var_1C] }
            if ( v42 > 1 << _EAX )
              v42 = 2 * (1 << _EAX);
          }
          else if ( v42 & 0x3FFF )
          {
            v42 += 0x4000 - (v42 & 0x3FFF);
          }
        }
        else
        {
          v42 = 8;
        }
        if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&target->m_FFModifiers, v42) )
        {
LABEL_43:
          v48 = target->m_FFModifiers.m_num;
          if ( v48 )
          {
            v49 = *(_DWORD *)v38 + 4 * v37;
            for ( j = *(_DWORD *)v38 + 4 * v48 - 4; j >= (unsigned int)v49; j -= 4 )
              *(_DWORD *)(j + 4) = *(_DWORD *)j;
          }
          *(_DWORD *)(*(_DWORD *)v38 + 4 * v37) = v39;
          ++target->m_FFModifiers.m_num;
        }
      }
      v34 = v53;
      v51 = v53->m_FFModifiers.m_num;
      v36 = im++ + 1;
    }
    while ( im < v51 );
  }
  return 1;
}

//----- (0044AE20) --------------------------------------------------------  // acclient.c:135668
void __thiscall MaterialLayer::Serialize(MaterialLayer *this, Archive *io_archive)
{
  unsigned int v2; // eax@1
  int v3; // esi@5
  unsigned int v4; // eax@5
  int v5; // esi@9
  unsigned int v6; // eax@9
  int v7; // esi@13
  unsigned int v8; // eax@13
  unsigned int v9; // esi@17
  unsigned int v10; // eax@17
  int v11; // edi@22
  unsigned int v12; // ebx@22
  int v13; // eax@24
  unsigned int v14; // eax@25
  int v15; // esi@27
  unsigned int v16; // eax@27
  unsigned int v17; // ebx@32
  unsigned int v18; // eax@32
  unsigned int v19; // edi@36
  LayerStage *v20; // eax@38
  unsigned int v21; // eax@39
  unsigned int v22; // esi@39
  unsigned int v23; // ST0C_4@43
  unsigned int v24; // esi@45
  unsigned int *v25; // eax@45
  int v26; // eax@49
  unsigned int v27; // eax@51
  LM_UVTranslate *v28; // eax@52
  LayerModifier *v29; // eax@53
  LayerModifier *v30; // ebp@53
  LM_UVRotate *v31; // eax@54
  LayerModifier *v32; // eax@55
  LM_UVScale *v33; // eax@56
  LayerModifier *v34; // eax@57
  LM_UVTransform *v35; // eax@59
  LayerModifier *v36; // eax@60
  unsigned int v37; // ebx@63
  unsigned int v38; // ecx@63
  int v39; // esi@63
  int v40; // eax@64
  unsigned int v41; // edx@65
  unsigned int v46; // edx@73
  int v47; // ecx@74
  int i; // eax@74
  unsigned __int8 v49; // bl@78
  unsigned int v50; // eax@78
  unsigned __int8 v51; // bl@84
  unsigned int v52; // eax@84
  unsigned __int8 v53; // bl@90
  unsigned int v54; // eax@90
  unsigned __int8 v55; // bl@96
  unsigned int v56; // eax@96
  bool v57; // bl@102
  unsigned int v58; // eax@102
  unsigned __int8 v60; // bl@111
  unsigned int v61; // eax@111
  bool v62; // bl@117
  unsigned int v63; // eax@117
  bool v64; // zf@122
  MaterialLayer *v65; // [sp+4h] [bp-10h]@1
  unsigned int im; // [sp+8h] [bp-Ch]@49
  unsigned int NumFFModifiers; // [sp+Ch] [bp-8h]@43
  int v68; // [sp+10h] [bp-4h]@70

  v65 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v2 = Archive::GetBytes(io_archive, 4u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v2 = v65->m_Options;
    else
      v65->m_Options = *(_DWORD *)v2;
  }
  v3 = (int)&v65->m_TrueFlags;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = *(_DWORD *)v3;
    else
      *(_DWORD *)v3 = *(_DWORD *)v4;
  }
  v5 = (int)&v65->m_FalseFlags;
  Archive::CheckAlignment(io_archive, 4u);
  v6 = Archive::GetBytes(io_archive, 4u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v6 = *(_DWORD *)v5;
    else
      *(_DWORD *)v5 = *(_DWORD *)v6;
  }
  v7 = (int)&v65->m_RenderPass;
  Archive::CheckAlignment(io_archive, 4u);
  v8 = Archive::GetBytes(io_archive, 4u);
  if ( v8 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v8 = *(_DWORD *)v7;
    else
      *(_DWORD *)v7 = *(_DWORD *)v8;
  }
  v9 = v65->m_ShaderResources.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v10 = Archive::GetBytes(io_archive, 4u);
  if ( v10 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v10 = v9;
    else
      v9 = *(_DWORD *)v10;
  }
  if ( v9 )
  {
    v11 = 0;
    v12 = v9;
    do
    {
      if ( ~LOBYTE(io_archive->m_flags) & 1 )
      {
        v13 = v65->m_ShaderResources.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v65->m_ShaderResources.m_num < v13
          || (v14 = SmartArray<UIChildFramework *,1>::get_new_size(v13 + 1),
              SmartArray<ShaderResourceType,1>::grow(&v65->m_ShaderResources, v14)) )
          ++v65->m_ShaderResources.m_num;
      }
      v15 = (int)&v65->m_ShaderResources.m_data[v11];
      Archive::CheckAlignment(io_archive, 4u);
      v16 = Archive::GetBytes(io_archive, 4u);
      if ( v16 )
      {
        if ( io_archive->m_flags & 1 )
          *(_DWORD *)v16 = *(_DWORD *)v15;
        else
          *(_DWORD *)v15 = *(_DWORD *)v16;
      }
      Serializer::SerializeObject((SmartBuffer *)(v15 + 12), io_archive);
      Serializer::SerializeObject((SmartBuffer *)(v15 + 24), io_archive);
      ++v11;
      --v12;
    }
    while ( v12 );
  }
  v17 = v65->m_Stages.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v18 = Archive::GetBytes(io_archive, 4u);
  if ( v18 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v18 = v17;
    else
      v17 = *(_DWORD *)v18;
  }
  v19 = 0;
  if ( v17 )
  {
    do
    {
      if ( ~LOBYTE(io_archive->m_flags) & 1 )
      {
        v20 = (LayerStage *)operator new(0x48u);
        if ( v20 )
        {
          LayerStage::LayerStage(v20);
          v22 = v21;
        }
        else
        {
          v22 = 0;
        }
      }
      else
      {
        v22 = (unsigned int)v65->m_Stages.m_data[v19];
      }
      LayerStage::Serialize((LayerStage *)v22, io_archive);
      if ( ~LOBYTE(io_archive->m_flags) & 1 )
      {
        v23 = v65->m_Stages.m_num;
        NumFFModifiers = v22;
        SmartArray<LayerStage *,1>::InsertOrderedByIndex(
          (SmartArray<EffectInfoRegion *,1> *)&v65->m_Stages,
          (EffectInfoRegion *const *)&NumFFModifiers,
          v23);
      }
      ++v19;
    }
    while ( v19 < v17 );
  }
  v24 = v65->m_FFModifiers.m_num;
  NumFFModifiers = v65->m_FFModifiers.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v25 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
  if ( v25 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *v25 = v24;
    }
    else
    {
      v24 = *v25;
      NumFFModifiers = *v25;
    }
  }
  v26 = 0;
  im = 0;
  if ( !v24 )
  {
LABEL_78:
    v49 = LOBYTE(v65->m_SourceBlend);
    Archive::CheckAlignment(io_archive, 1u);
    v50 = Archive::GetBytes(io_archive, 1u);
    if ( v50 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v50 = v49;
      else
        v49 = *(_BYTE *)v50;
    }
    if ( !(io_archive->m_flags & 5) )
      v65->m_SourceBlend = v49;
    v51 = LOBYTE(v65->m_DestBlend);
    Archive::CheckAlignment(io_archive, 1u);
    v52 = Archive::GetBytes(io_archive, 1u);
    if ( v52 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v52 = v51;
      else
        v51 = *(_BYTE *)v52;
    }
    if ( !(io_archive->m_flags & 5) )
      v65->m_DestBlend = v51;
    v53 = LOBYTE(v65->m_BlendOp);
    Archive::CheckAlignment(io_archive, 1u);
    v54 = Archive::GetBytes(io_archive, 1u);
    if ( v54 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v54 = v53;
      else
        v53 = *(_BYTE *)v54;
    }
    if ( !(io_archive->m_flags & 5) )
      v65->m_BlendOp = v53;
    v55 = LOBYTE(v65->m_DepthTest);
    Archive::CheckAlignment(io_archive, 1u);
    v56 = Archive::GetBytes(io_archive, 1u);
    if ( v56 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v56 = v55;
      else
        v55 = *(_BYTE *)v56;
    }
    if ( !(io_archive->m_flags & 5) )
      v65->m_DepthTest = v55;
    v57 = v65->m_DepthWrite;
    Archive::CheckAlignment(io_archive, 1u);
    v58 = Archive::GetBytes(io_archive, 1u);
    if ( v58 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v58 = v57;
      else
        v57 = *(_BYTE *)v58;
    }
    if ( !(io_archive->m_flags & 5) )
    {
      _ZF = v57 == 0;
      if ( !v57 )
        goto LABEL_111;
      if ( v57 != 1 )
        Archive::RaiseError(io_archive);
    }
    _ZF = v57 == 0;
LABEL_111:
    v65->m_DepthWrite = !_ZF;
    v60 = LOBYTE(v65->m_CullMode);
    Archive::CheckAlignment(io_archive, 1u);
    v61 = Archive::GetBytes(io_archive, 1u);
    if ( v61 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v61 = v60;
      else
        v60 = *(_BYTE *)v61;
    }
    if ( !(io_archive->m_flags & 5) )
      v65->m_CullMode = v60;
    v62 = v65->m_AlphaTest;
    Archive::CheckAlignment(io_archive, 1u);
    v63 = Archive::GetBytes(io_archive, 1u);
    if ( v63 )
    {
      if ( io_archive->m_flags & 1 )
        *(_BYTE *)v63 = v62;
      else
        v62 = *(_BYTE *)v63;
    }
    if ( !(io_archive->m_flags & 5) )
    {
      v64 = v62 == 0;
      if ( !v62 )
      {
LABEL_126:
        v65->m_AlphaTest = !v64;
        Waveform::Serialize(&v65->m_AlphaTestRef, io_archive);
        RGBAColor::Serialize(&v65->m_cDiffuse, io_archive);
        RGBAColor::Serialize(&v65->m_cSpecular, io_archive);
        Waveform::Serialize(&v65->m_wSpecularPower, io_archive);
        RGBAColor::Serialize(&v65->m_cDye, io_archive);
        return;
      }
      if ( v62 != 1 )
        Archive::RaiseError(io_archive);
    }
    v64 = v62 == 0;
    goto LABEL_126;
  }
  while ( !(~LOBYTE(io_archive->m_flags) & 1) )
  {
    v30 = v65->m_FFModifiers.m_data[v26];
LABEL_62:
    v30->vfptr->Serialize(v30, io_archive);
    if ( ~LOBYTE(io_archive->m_flags) & 1 )
    {
      v37 = v65->m_FFModifiers.m_num;
      v38 = v65->m_FFModifiers.m_num;
      v39 = (int)&v65->m_FFModifiers;
      if ( v37 <= v38 )
      {
        v40 = v65->m_FFModifiers.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v38 < v40 )
          goto LABEL_129;
        v41 = v40 + 1;
        if ( (unsigned int)(v40 + 1) > 8 )
        {
          if ( v41 <= 0x4000 )
          {
            v68 = v40 + 1;
            __asm { bsr     this, [esp+20h+var_4] }
            if ( v41 > 1 << _EAX )
              v41 = 2 * (1 << _EAX);
          }
          else if ( v41 & 0x3FFF )
          {
            v41 += 0x4000 - (v41 & 0x3FFF);
          }
        }
        else
        {
          v41 = 8;
        }
        if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v65->m_FFModifiers, v41) )
        {
LABEL_129:
          v46 = v65->m_FFModifiers.m_num;
          if ( v46 )
          {
            v47 = *(_DWORD *)v39 + 4 * v37;
            for ( i = *(_DWORD *)v39 + 4 * v46 - 4; i >= (unsigned int)v47; i -= 4 )
              *(_DWORD *)(i + 4) = *(_DWORD *)i;
          }
          *(_DWORD *)(*(_DWORD *)v39 + 4 * v37) = v30;
          ++v65->m_FFModifiers.m_num;
        }
      }
    }
    v26 = im++ + 1;
    if ( im >= NumFFModifiers )
      goto LABEL_78;
  }
  v27 = Archive::GetSizeUsed(io_archive);
  switch ( *(_BYTE *)Archive::PeekBytes(io_archive, v27, 1u) )
  {
    case 1:
      v28 = (LM_UVTranslate *)operator new(0x60u);
      if ( !v28 )
        goto LABEL_58;
      LM_UVTranslate::LM_UVTranslate(v28);
      v30 = v29;
      goto LABEL_62;
    case 2:
      v31 = (LM_UVRotate *)operator new(0x34u);
      if ( !v31 )
        goto LABEL_58;
      LM_UVRotate::LM_UVRotate(v31);
      v30 = v32;
      goto LABEL_62;
    case 3:
      v33 = (LM_UVScale *)operator new(0x60u);
      if ( !v33 )
        goto LABEL_58;
      LM_UVScale::LM_UVScale(v33);
      v30 = v34;
      goto LABEL_62;
    case 4:
      v35 = (LM_UVTransform *)operator new(0x48u);
      if ( v35 )
      {
        LM_UVTransform::LM_UVTransform(v35);
        v30 = v36;
      }
      else
      {
LABEL_58:
        v30 = 0;
      }
      goto LABEL_62;
    default:
      return;
  }
}

//----- (0044B4B0) --------------------------------------------------------  // acclient.c:136088
unsigned int __thiscall MaterialLayer::Copy(MaterialLayer *this, const bool _IsInstance)
{
  MaterialLayer *v2; // edi@1
  void *v3; // esi@1
  unsigned int result; // eax@2

  v2 = this;
  v3 = operator new(0xD8u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    *((_DWORD *)v3 + 10) = 0;
    *((_DWORD *)v3 + 11) = 0;
    *((_DWORD *)v3 + 12) = 0;
    Waveform::Waveform((Waveform *)((char *)v3 + 80));
    Waveform::Waveform((Waveform *)((char *)v3 + 156));
    MaterialLayer::Begin((MaterialLayer *)v3);
    result = MaterialLayer::CopyInto(v2, _IsInstance, (MaterialLayer *)v3) != 0 ? (unsigned int)v3 : 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006D3480) --------------------------------------------------------  // acclient.c:745870
void _E73_43()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_18, PFID_A8R8G8B8);
}

//----- (006D3490) --------------------------------------------------------  // acclient.c:745876
int _E91_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_16, "None");
  return atexit(_E92_22);
}

//----- (006D34B0) --------------------------------------------------------  // acclient.c:745883
int _E94_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_16, "Speed");
  return atexit(sub_740610);
}

//----- (006D34D0) --------------------------------------------------------  // acclient.c:745890
int _E97_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_16, "Noise");
  return atexit(_E98_37);
}

//----- (006D34F0) --------------------------------------------------------  // acclient.c:745897
int _E100_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_16, "Sine");
  return atexit(_E101_62);
}

//----- (006D3510) --------------------------------------------------------  // acclient.c:745904
int _E103_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_16, "Square");
  return atexit(_E104_32);
}

//----- (006D3530) --------------------------------------------------------  // acclient.c:745911
int _E106_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_16, "Bounce");
  return atexit(_E107_64);
}

//----- (006D3550) --------------------------------------------------------  // acclient.c:745918
int _E109_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_16, "Perlin");
  return atexit(sub_740700);
}

//----- (006D3570) --------------------------------------------------------  // acclient.c:745925
int _E112_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_16, "Fractal");
  return atexit(_E113_43);
}

//----- (006D3590) --------------------------------------------------------  // acclient.c:745932
int _E115_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_16, "FrameLoop");
  return atexit(_E116_35);
}

//----- (006D35B0) --------------------------------------------------------  // acclient.c:745939
void _E118_11()
{
  LODWORD(dword_839A64) = 1053364187;
}

//----- (006D35C0) --------------------------------------------------------  // acclient.c:745945
void _E120_6()
{
  outside_val_14 = 1000.0 + 1.0;
}

//----- (006D35E0) --------------------------------------------------------  // acclient.c:745951
void _E122_2()
{
  block_length_14 = 24.0 * 8.0;
}

//----- (006D3600) --------------------------------------------------------  // acclient.c:745957
void _E124_11()
{
  half_square_length_14 = 24.0 * 0.5;
}

//----- (006D3620) --------------------------------------------------------  // acclient.c:745963
int _E126_7()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_9, "Render.TextureFiltering");
  return atexit(_E127_88);
}

//----- (006D3640) --------------------------------------------------------  // acclient.c:745970
int _E129_6()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_9, "Render.LandscapeDetailTextures");
  return atexit(_E130_80);
}

//----- (006D3660) --------------------------------------------------------  // acclient.c:745977
int _E132_7()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_9, "Render.BuildingDetailTextures");
  return atexit(_E133_73);
}

//----- (006D3680) --------------------------------------------------------  // acclient.c:745984
int _E135_6()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_9, "Render.FieldOfView");
  return atexit(_E136_57);
}

//----- (006D36A0) --------------------------------------------------------  // acclient.c:745991
int _E138_7()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_9, "Render.LandscapeTextureDetail");
  return atexit(_E139_58);
}

//----- (006D36C0) --------------------------------------------------------  // acclient.c:745998
int _E141_7()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_9, "Render.EnvironmentTextureDetail");
  return atexit(_E142_55);
}

//----- (006D36E0) --------------------------------------------------------  // acclient.c:746005
int _E144_7()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_9, "Render.SceneryDrawDistance");
  return atexit(_E145_57);
}

//----- (006D3700) --------------------------------------------------------  // acclient.c:746012
int _E147_7()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_9, "Render.LandscapeDrawDistance");
  return atexit(_E148_56);
}

//----- (006D3720) --------------------------------------------------------  // acclient.c:746019
int _E150_7()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_9, "Render.ScreenBrightness");
  return atexit(_E151_54);
}

//----- (006D3740) --------------------------------------------------------  // acclient.c:746026
int _E153_7()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_9, "Render.AspectRatio");
  return atexit(_E154_55);
}

//----- (006D3760) --------------------------------------------------------  // acclient.c:746033
int _E156_8()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_9, "Render.DisplayAdapter");
  return atexit(_E157_52);
}

//----- (006D3780) --------------------------------------------------------  // acclient.c:746040
int _E159_7()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_9, "Render.MaxHardwareClass");
  return atexit(_E160_55);
}

//----- (006D37A0) --------------------------------------------------------  // acclient.c:746047
int _E162_8()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_9, "Render.AutomaticDegrades");
  return atexit(_E163_48);
}

//----- (006D37C0) --------------------------------------------------------  // acclient.c:746054
int _E165_7()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_9, "Render.GraphicsPerformance");
  return atexit(_E166_50);
}

//----- (006D37E0) --------------------------------------------------------  // acclient.c:746061
int _E168_8()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_9, "Render.DegradeDistance");
  return atexit(_E169_49);
}

//----- (006D3800) --------------------------------------------------------  // acclient.c:746068
int _E171_8()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_9, "Render.MultiPassAlpha");
  return atexit(_E172_47);
}

//----- (006D3820) --------------------------------------------------------  // acclient.c:746075
int _E174_8()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_9, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_839ABC, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_839AC0, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_839AC4, "Anisotropic");
  return atexit(_E175_44);
}

//----- (006D3870) --------------------------------------------------------  // acclient.c:746085
int _E177_8()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_9, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839ACC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839AD0, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_839AD4, "High");
  PStringBase<char>::PStringBase<char>(&stru_839AD8, "VeryHigh");
  return atexit(_E178_44);
}

//----- (006D38D0) --------------------------------------------------------  // acclient.c:746096
int _E180_8()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_9, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839AE0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839AE4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_839AE8, "High");
  PStringBase<char>::PStringBase<char>(&stru_839AEC, "VeryHigh");
  return atexit(_E181_44);
}

//----- (006D3930) --------------------------------------------------------  // acclient.c:746107
int _E183_8()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_9, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839AF4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_839AF8, "High");
  return atexit(_E184_42);
}

//----- (006D3970) --------------------------------------------------------  // acclient.c:746116
int _E186_8()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_9, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839B00, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839B04, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_839B08, "High");
  PStringBase<char>::PStringBase<char>(&stru_839B0C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_839B10, "Extreme");
  return atexit(_E187_41);
}

//----- (006D39E0) --------------------------------------------------------  // acclient.c:746128
int _E189_8()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_9, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_839B18, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_839B1C, "Wide");
  return atexit(_E190_42);
}

//----- (006D3A20) --------------------------------------------------------  // acclient.c:746137
int _E192_7()
{
  PStringBase<char>::PStringBase<char>(&PHeader_2, "PREPROC_HEADER");
  return atexit(_E193_38);
}

//----- (006D3A40) --------------------------------------------------------  // acclient.c:746144
int _E195_4()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_2, "VertexArray");
  return atexit(_E196_45);
}

//----- (006D3A60) --------------------------------------------------------  // acclient.c:746151
int _E198_5()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_2, "BinaryVertexArray");
  return atexit(_E199_37);
}

//----- (006D3A80) --------------------------------------------------------  // acclient.c:746158
int _E201_3()
{
  PStringBase<char>::PStringBase<char>(&VertexType_3, "VertexType");
  return atexit(_E202_38);
}

//----- (006D3AA0) --------------------------------------------------------  // acclient.c:746165
int _E204_2()
{
  PStringBase<char>::PStringBase<char>(&VertexData_2, "VertexData");
  return atexit(_E205_35);
}

//----- (006D3AC0) --------------------------------------------------------  // acclient.c:746172
int _E207_1()
{
  PStringBase<char>::PStringBase<char>(&Vertex_2, "Vertex");
  return atexit(_E208_39);
}

//----- (006D3AE0) --------------------------------------------------------  // acclient.c:746179
int _E210_2()
{
  PStringBase<char>::PStringBase<char>(&Index_5, "Index");
  return atexit(_E211_35);
}

//----- (006D3B00) --------------------------------------------------------  // acclient.c:746186
int _E213_3()
{
  PStringBase<char>::PStringBase<char>(&Origin_5, "P");
  return atexit(_E214_38);
}

//----- (006D3B20) --------------------------------------------------------  // acclient.c:746193
int _E216_3()
{
  PStringBase<char>::PStringBase<char>(&Normal_2, "N");
  return atexit(_E217_34);
}

//----- (006D3B40) --------------------------------------------------------  // acclient.c:746200
int _E219_1()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_5, "Diffuse");
  return atexit(_E220_34);
}

//----- (006D3B60) --------------------------------------------------------  // acclient.c:746207
int _E222_1()
{
  PStringBase<char>::PStringBase<char>(&Specular_5, "Specular");
  return atexit(_E223_34);
}

//----- (006D3B80) --------------------------------------------------------  // acclient.c:746214
int _E225_1()
{
  PStringBase<char>::PStringBase<char>(&UVS_2, "UVS");
  return atexit(_E226_20);
}

//----- (006D3BA0) --------------------------------------------------------  // acclient.c:746221
int _E228_1()
{
  PStringBase<char>::PStringBase<char>(&VectorS_2, "VectorS");
  return atexit(_E229_20);
}

//----- (006D3BC0) --------------------------------------------------------  // acclient.c:746228
int _E231_1()
{
  PStringBase<char>::PStringBase<char>(&VectorT_2, "VectorT");
  return atexit(_E232_20);
}

//----- (006D3BE0) --------------------------------------------------------  // acclient.c:746235
int _E234_1()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_2, "VectorSxT");
  return atexit(_E235_20);
}

//----- (006D3C00) --------------------------------------------------------  // acclient.c:746242
int _E237_1()
{
  PStringBase<char>::PStringBase<char>(&Weights_2, "Weights");
  return atexit(_E238_18);
}

//----- (006D3C20) --------------------------------------------------------  // acclient.c:746249
int _E240_1()
{
  PStringBase<char>::PStringBase<char>(&Importance_2, "Importance");
  return atexit(_E241_18);
}

//----- (006D3C40) --------------------------------------------------------  // acclient.c:746256
int _E243_1()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_2, "PhysMtl");
  return atexit(_E244_18);
}

//----- (006D3C60) --------------------------------------------------------  // acclient.c:746263
int _E246_1()
{
  PStringBase<char>::PStringBase<char>(&Material_12, "Material");
  return atexit(_E247_17);
}

//----- (006D3C80) --------------------------------------------------------  // acclient.c:746270
int _E249_1()
{
  PStringBase<char>::PStringBase<char>(&ID_6, "ID");
  return atexit(_E250_17);
}

//----- (006D3CA0) --------------------------------------------------------  // acclient.c:746277
int _E252_1()
{
  PStringBase<char>::PStringBase<char>(&FileName_2, "FileName");
  return atexit(_E253_17);
}

//----- (006D3CC0) --------------------------------------------------------  // acclient.c:746284
int _E255_1()
{
  PStringBase<char>::PStringBase<char>(&Polygon_5, "Polygon");
  return atexit(_E256_17);
}

//----- (006D3CE0) --------------------------------------------------------  // acclient.c:746291
int _E258_1()
{
  PStringBase<char>::PStringBase<char>(&ID_7, "ID");
  return atexit(_E259_18);
}

//----- (006D3D00) --------------------------------------------------------  // acclient.c:746298
int _E261_1()
{
  PStringBase<char>::PStringBase<char>(&Indices_4, "INDICES");
  return atexit(_E262_18);
}

//----- (006D3D20) --------------------------------------------------------  // acclient.c:746305
int _E264_1()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_2, "MaterialID");
  return atexit(_E265_18);
}

//----- (006D3D40) --------------------------------------------------------  // acclient.c:746312
int _E267_1()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_2, "PhysMaterialID");
  return atexit(_E268_17);
}

//----- (006D3D60) --------------------------------------------------------  // acclient.c:746319
int _E270_1()
{
  PStringBase<char>::PStringBase<char>(&Markings_2, "Markings");
  return atexit(_E271_16);
}

//----- (006D3D80) --------------------------------------------------------  // acclient.c:746326
int _E273_1()
{
  PStringBase<char>::PStringBase<char>(&Material_13, "Material");
  return atexit(_E274_16);
}

//----- (006D3DA0) --------------------------------------------------------  // acclient.c:746333
int _E276_1()
{
  PStringBase<char>::PStringBase<char>(&Index_6, "Index");
  return atexit(_E277_16);
}

//----- (006D3DC0) --------------------------------------------------------  // acclient.c:746340
int _E279_1()
{
  PStringBase<char>::PStringBase<char>(&Filename_2, "Filename");
  return atexit(_E280_15);
}

//----- (006D3DE0) --------------------------------------------------------  // acclient.c:746347
int _E282_1()
{
  PStringBase<char>::PStringBase<char>(&Surface_2, "Surface");
  return atexit(_E283_15);
}

//----- (006D3E00) --------------------------------------------------------  // acclient.c:746354
int _E285_1()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_2, "CellPoly");
  return atexit(_E286_14);
}

//----- (006D3E20) --------------------------------------------------------  // acclient.c:746361
int _E288_1()
{
  PStringBase<char>::PStringBase<char>(&Sphere_3, "Sphere");
  return atexit(_E289_13);
}

//----- (006D3E40) --------------------------------------------------------  // acclient.c:746368
int _E291_1()
{
  PStringBase<char>::PStringBase<char>(&Side_2, "Side");
  return atexit(_E292_14);
}

//----- (006D3E60) --------------------------------------------------------  // acclient.c:746375
int _E294_1()
{
  PStringBase<char>::PStringBase<char>(&Positive_2, "Positive");
  return atexit(_E295_13);
}

//----- (006D3E80) --------------------------------------------------------  // acclient.c:746382
int _E297_1()
{
  PStringBase<char>::PStringBase<char>(&Negative_2, "Negative");
  return atexit(_E298_14);
}

//----- (006D3EA0) --------------------------------------------------------  // acclient.c:746389
int _E300_1()
{
  PStringBase<char>::PStringBase<char>(&Polygon_6, "PolygonIndex");
  return atexit(_E301_12);
}

//----- (006D3EC0) --------------------------------------------------------  // acclient.c:746396
int _E303_1()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_5, "OtherCellMeshIndex");
  return atexit(_E304_13);
}

//----- (006D3EE0) --------------------------------------------------------  // acclient.c:746403
int _E306_1()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_2, "CellPortal");
  return atexit(_E307_12);
}

//----- (006D3F00) --------------------------------------------------------  // acclient.c:746410
int _E309_1()
{
  PStringBase<char>::PStringBase<char>(&Portal_3, "PortalIndex");
  return atexit(_E310_13);
}

//----- (006D3F20) --------------------------------------------------------  // acclient.c:746417
int _E312_1()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_6, "OtherCellID");
  return atexit(_E313_12);
}

//----- (006D3F40) --------------------------------------------------------  // acclient.c:746424
int _E315_1()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_2, "OtherPortalIndex");
  return atexit(_E316_13);
}

//----- (006D3F60) --------------------------------------------------------  // acclient.c:746431
int _E318_1()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_2, "ExactMatch");
  return atexit(_E319_12);
}

//----- (006D3F80) --------------------------------------------------------  // acclient.c:746438
int _E321_1()
{
  PStringBase<char>::PStringBase<char>(&StabList_2, "StabList");
  return atexit(_E322_12);
}

//----- (006D3FA0) --------------------------------------------------------  // acclient.c:746445
int _E324_1()
{
  PStringBase<char>::PStringBase<char>(&Period_2, "Period");
  return atexit(_E325_11);
}

//----- (006D3FC0) --------------------------------------------------------  // acclient.c:746452
int _E327_1()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_2, "GrannyAnimation");
  return atexit(_E328_12);
}

//----- (006D3FE0) --------------------------------------------------------  // acclient.c:746459
int _E330_1()
{
  PStringBase<char>::PStringBase<char>(&Transform_2, "Transform");
  return atexit(_E331_11);
}

//----- (006D4000) --------------------------------------------------------  // acclient.c:746466
int _E333_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_8, "Scale");
  return atexit(_E334_11);
}

//----- (006D4020) --------------------------------------------------------  // acclient.c:746473
int _E336_1()
{
  PStringBase<char>::PStringBase<char>(&Weight_2, "Weight");
  return atexit(_E337_11);
}

//----- (006D4040) --------------------------------------------------------  // acclient.c:746480
int _E339_1()
{
  PStringBase<char>::PStringBase<char>(&Offset_2, "Offset");
  return atexit(_E340_11);
}

//----- (006D4060) --------------------------------------------------------  // acclient.c:746487
int _E342_1()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_3, "Quaternion");
  return atexit(_E343_8);
}

//----- (006D4080) --------------------------------------------------------  // acclient.c:746494
int _E345_1()
{
  PStringBase<char>::PStringBase<char>(&Rotation_5, "Rotation");
  return atexit(_E346_8);
}

//----- (006D40A0) --------------------------------------------------------  // acclient.c:746501
int _E348_1()
{
  PStringBase<char>::PStringBase<char>(&STime_2, "STime");
  return atexit(_E349_8);
}

//----- (006D40C0) --------------------------------------------------------  // acclient.c:746508
int _E351_1()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_2, "PhysicsSplines");
  return atexit(_E352_8);
}

//----- (006D40E0) --------------------------------------------------------  // acclient.c:746515
int _E354_1()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_2, "BoneOpacities");
  return atexit(_E355_8);
}

//----- (006D4100) --------------------------------------------------------  // acclient.c:746522
int _E357_1()
{
  PStringBase<char>::PStringBase<char>(&LowPt_2, "LowPoint");
  return atexit(_E358_8);
}

//----- (006D4120) --------------------------------------------------------  // acclient.c:746529
int _E360_1()
{
  PStringBase<char>::PStringBase<char>(&Radius_2, "Radius");
  return atexit(_E361_8);
}

//----- (006D4140) --------------------------------------------------------  // acclient.c:746536
int _E363_1()
{
  PStringBase<char>::PStringBase<char>(&Height_2, "Height");
  return atexit(_E364_8);
}

//----- (006D4160) --------------------------------------------------------  // acclient.c:746543
int _E366_1()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_2, "Texture2D");
  return atexit(_E367_8);
}

//----- (006D4180) --------------------------------------------------------  // acclient.c:746550
int _E369_1()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_2, "Texture3D");
  return atexit(_E370_8);
}

//----- (006D41A0) --------------------------------------------------------  // acclient.c:746557
int _E372_1()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_2, "TextureCube");
  return atexit(_E373_8);
}

//----- (006D41C0) --------------------------------------------------------  // acclient.c:746564
int _E375_1()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_2, "TextureMovie2D");
  return atexit(_E376_8);
}

//----- (006D41E0) --------------------------------------------------------  // acclient.c:746571
int _E378_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_2, "MovieFile");
  return atexit(_E379_8);
}

//----- (006D4200) --------------------------------------------------------  // acclient.c:746578
int _E381_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_2, "MovieFPS");
  return atexit(_E382_8);
}

//----- (006D4220) --------------------------------------------------------  // acclient.c:746585
int _E384_1()
{
  PStringBase<char>::PStringBase<char>(&Levels_2, "Levels");
  return atexit(_E385_8);
}

//----- (006D4240) --------------------------------------------------------  // acclient.c:746592
int _E387_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_29, "Instance");
  return atexit(_E388_8);
}

//----- (006D4260) --------------------------------------------------------  // acclient.c:746599
int _E390_1()
{
  PStringBase<char>::PStringBase<char>(&Material_14, "Material");
  return atexit(_E391_8);
}

//----- (006D4280) --------------------------------------------------------  // acclient.c:746606
int _E393_1()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_2, "MaterialType");
  return atexit(_E394_8);
}

//----- (006D42A0) --------------------------------------------------------  // acclient.c:746613
int _E396_1()
{
  PStringBase<char>::PStringBase<char>(&Modifier_2, "Modifier");
  return atexit(_E397_8);
}

//----- (006D42C0) --------------------------------------------------------  // acclient.c:746620
int _E399_1()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_2, "AllowStencilShadows");
  return atexit(_E400_8);
}

//----- (006D42E0) --------------------------------------------------------  // acclient.c:746627
int _E402_1()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_2, "DiscardGeometry");
  return atexit(_E403_8);
}

//----- (006D4300) --------------------------------------------------------  // acclient.c:746634
int _E405_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_30, "Material");
  return atexit(_E406_8);
}

//----- (006D4320) --------------------------------------------------------  // acclient.c:746641
int _E408_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_2, "SortMode");
  return atexit(_E409_8);
}

//----- (006D4340) --------------------------------------------------------  // acclient.c:746648
int _E411_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_2, "None");
  return atexit(_E412_8);
}

//----- (006D4360) --------------------------------------------------------  // acclient.c:746655
int _E414_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_2, "Triangle");
  return atexit(_E415_8);
}

//----- (006D4380) --------------------------------------------------------  // acclient.c:746662
int _E417_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_31, "Modifier");
  return atexit(_E418_8);
}

//----- (006D43A0) --------------------------------------------------------  // acclient.c:746669
int _E420_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_32, "Property");
  return atexit(_E421_8);
}

//----- (006D43C0) --------------------------------------------------------  // acclient.c:746676
int _E423_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_2, "Data");
  return atexit(_E424_8);
}

//----- (006D43E0) --------------------------------------------------------  // acclient.c:746683
int _E426_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_2, "Waveform");
  return atexit(_E427_8);
}

//----- (006D4400) --------------------------------------------------------  // acclient.c:746690
int _E429_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_2, "Color");
  return atexit(_E430_8);
}

//----- (006D4420) --------------------------------------------------------  // acclient.c:746697
int _E432_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_2, "Texture");
  return atexit(_E433_8);
}

//----- (006D4440) --------------------------------------------------------  // acclient.c:746704
int _E435_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_2, "Bool");
  return atexit(_E436_8);
}

//----- (006D4460) --------------------------------------------------------  // acclient.c:746711
int _E438_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_33, "Layer");
  return atexit(_E439_8);
}

//----- (006D4480) --------------------------------------------------------  // acclient.c:746718
int _E441_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_2, "UVTranslate");
  return atexit(_E442_8);
}

//----- (006D44A0) --------------------------------------------------------  // acclient.c:746725
int _E444_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_2, "UVRotate");
  return atexit(_E445_8);
}

//----- (006D44C0) --------------------------------------------------------  // acclient.c:746732
int _E447_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_2, "UVScale");
  return atexit(_E448_8);
}

//----- (006D44E0) --------------------------------------------------------  // acclient.c:746739
int _E450_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_2, "UVTransform");
  return atexit(_E451_8);
}

//----- (006D4500) --------------------------------------------------------  // acclient.c:746746
int _E453_1()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_2, "TrueFlags");
  return atexit(_E454_8);
}

//----- (006D4520) --------------------------------------------------------  // acclient.c:746753
int _E456_1()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_2, "FalseFlags");
  return atexit(_E457_8);
}

//----- (006D4540) --------------------------------------------------------  // acclient.c:746760
int _E459_1()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_2, "RenderPass");
  return atexit(_E460_8);
}

//----- (006D4560) --------------------------------------------------------  // acclient.c:746767
int _E462_1()
{
  PStringBase<char>::PStringBase<char>(&Blend_2, "Blend");
  return atexit(_E463_8);
}

//----- (006D4580) --------------------------------------------------------  // acclient.c:746774
int _E465_1()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_2, "DepthTest");
  return atexit(_E466_8);
}

//----- (006D45A0) --------------------------------------------------------  // acclient.c:746781
int _E468_1()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_2, "DepthWrite");
  return atexit(_E469_8);
}

//----- (006D45C0) --------------------------------------------------------  // acclient.c:746788
int _E471_1()
{
  PStringBase<char>::PStringBase<char>(&CullMode_2, "CullMode");
  return atexit(_E472_8);
}

//----- (006D45E0) --------------------------------------------------------  // acclient.c:746795
int _E474_1()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_2, "DepthFog");
  return atexit(_E475_8);
}

//----- (006D4600) --------------------------------------------------------  // acclient.c:746802
int _E477_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_2, "AlphaTestMode");
  return atexit(_E478_8);
}

//----- (006D4620) --------------------------------------------------------  // acclient.c:746809
int _E480_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_2, "AlphaTestRef");
  return atexit(_E481_8);
}

//----- (006D4640) --------------------------------------------------------  // acclient.c:746816
int _E483_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_2, "FFUseLighting");
  return atexit(_E484_8);
}

//----- (006D4660) --------------------------------------------------------  // acclient.c:746823
int _E486_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_2, "FFUseDyeColorInTFactor");
  return atexit(_E487_8);
}

//----- (006D4680) --------------------------------------------------------  // acclient.c:746830
int _E489_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_2, "FFUseSpecularLighting");
  return atexit(_E490_8);
}

//----- (006D46A0) --------------------------------------------------------  // acclient.c:746837
int _E492_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_2, "FFUseDistanceFog");
  return atexit(_E493_8);
}

//----- (006D46C0) --------------------------------------------------------  // acclient.c:746844
int _E495_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_2, "FFUseVertexDiffuse");
  return atexit(_E496_8);
}

//----- (006D46E0) --------------------------------------------------------  // acclient.c:746851
int _E498_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_2, "FFUseVertexSpecular");
  return atexit(_E499_8);
}

//----- (006D4700) --------------------------------------------------------  // acclient.c:746858
int _E501_1()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_2, "ShaderSupportsDynamicLights");
  return atexit(_E502_8);
}

//----- (006D4720) --------------------------------------------------------  // acclient.c:746865
int _E504_1()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_2, "UsesTransparency");
  return atexit(_E505_8);
}

//----- (006D4740) --------------------------------------------------------  // acclient.c:746872
int _E507_1()
{
  PStringBase<char>::PStringBase<char>(&Ambient_2, "Ambient");
  return atexit(_E508_8);
}

//----- (006D4760) --------------------------------------------------------  // acclient.c:746879
int _E510_1()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_6, "Diffuse");
  return atexit(_E511_8);
}

//----- (006D4780) --------------------------------------------------------  // acclient.c:746886
int _E513_1()
{
  PStringBase<char>::PStringBase<char>(&Specular_6, "Specular");
  return atexit(_E514_8);
}

//----- (006D47A0) --------------------------------------------------------  // acclient.c:746893
int _E516_1()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_2, "SpecularPower");
  return atexit(_E517_8);
}

//----- (006D47C0) --------------------------------------------------------  // acclient.c:746900
int _E519_1()
{
  PStringBase<char>::PStringBase<char>(&Dye_2, "Dye");
  return atexit(_E520_8);
}

//----- (006D47E0) --------------------------------------------------------  // acclient.c:746907
int _E522_1()
{
  PStringBase<char>::PStringBase<char>(&Emissive_2, "Emissive");
  return atexit(_E523_8);
}

//----- (006D4800) --------------------------------------------------------  // acclient.c:746914
int _E525_1()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_2, "VertexFormat");
  return atexit(_E526_8);
}

//----- (006D4820) --------------------------------------------------------  // acclient.c:746921
int _E528_1()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_2, "VertexShader");
  return atexit(_E529_8);
}

//----- (006D4840) --------------------------------------------------------  // acclient.c:746928
int _E531_1()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_2, "PixelShader");
  return atexit(_E532_8);
}

//----- (006D4860) --------------------------------------------------------  // acclient.c:746935
int _E534_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_2, "None");
  return atexit(_E535_8);
}

//----- (006D4880) --------------------------------------------------------  // acclient.c:746942
int _E537_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_2, "Reflections");
  return atexit(_E538_8);
}

//----- (006D48A0) --------------------------------------------------------  // acclient.c:746949
int _E540_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_2, "VideoPost");
  return atexit(_E541_8);
}

//----- (006D48C0) --------------------------------------------------------  // acclient.c:746956
int _E543_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_2, "HighDetail");
  return atexit(_E544_8);
}

//----- (006D48E0) --------------------------------------------------------  // acclient.c:746963
int _E546_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_2, "Specular");
  return atexit(_E547_8);
}

//----- (006D4900) --------------------------------------------------------  // acclient.c:746970
int _E549_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_2, "Class1");
  return atexit(_E550_8);
}

//----- (006D4920) --------------------------------------------------------  // acclient.c:746977
int _E552_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_2, "Class2");
  return atexit(_E553_8);
}

//----- (006D4940) --------------------------------------------------------  // acclient.c:746984
int _E555_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_2, "Class3");
  return atexit(_E556_8);
}

//----- (006D4960) --------------------------------------------------------  // acclient.c:746991
int _E558_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_2, "Default");
  return atexit(_E559_8);
}

//----- (006D4980) --------------------------------------------------------  // acclient.c:746998
int _E561_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_2,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E562_8);
}

//----- (006D49A0) --------------------------------------------------------  // acclient.c:747007
int _E564_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_2, "PointLightDiffuseAndSpecular");
  return atexit(_E565_8);
}

//----- (006D49C0) --------------------------------------------------------  // acclient.c:747014
int _E567_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_2,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E568_8);
}

//----- (006D49E0) --------------------------------------------------------  // acclient.c:747023
int _E570_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_2,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E571_8);
}

//----- (006D4A00) --------------------------------------------------------  // acclient.c:747032
int _E573_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_2,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E574_8);
}

//----- (006D4A20) --------------------------------------------------------  // acclient.c:747041
int _E576_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_2, "DistanceFog");
  return atexit(_E577_8);
}

//----- (006D4A40) --------------------------------------------------------  // acclient.c:747048
int _E579_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_2, "FFGlow");
  return atexit(_E580_8);
}

//----- (006D4A60) --------------------------------------------------------  // acclient.c:747055
int _E582_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_2, "ShaderGlow");
  return atexit(_E583_8);
}

//----- (006D4A80) --------------------------------------------------------  // acclient.c:747062
int _E585_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_2, "LandscapeShadowMap");
  return atexit(_E586_8);
}

//----- (006D4AA0) --------------------------------------------------------  // acclient.c:747069
int _E588_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_2, "AlphaBlend");
  return atexit(_E589_8);
}

//----- (006D4AC0) --------------------------------------------------------  // acclient.c:747076
int _E591_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_2, "AL_0DL_0PL");
  return atexit(_E592_8);
}

//----- (006D4AE0) --------------------------------------------------------  // acclient.c:747083
int _E594_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_2, "AL_0DL_1PL");
  return atexit(_E595_8);
}

//----- (006D4B00) --------------------------------------------------------  // acclient.c:747090
int _E597_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_2, "AL_0DL_2PL");
  return atexit(_E598_8);
}

//----- (006D4B20) --------------------------------------------------------  // acclient.c:747097
int _E600_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_2, "AL_0DL_3PL");
  return atexit(_E601_8);
}

//----- (006D4B40) --------------------------------------------------------  // acclient.c:747104
int _E603_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_2, "AL_0DL_4PL");
  return atexit(_E604_8);
}

//----- (006D4B60) --------------------------------------------------------  // acclient.c:747111
int _E606_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_2, "AL_0DL_5PL");
  return atexit(_E607_8);
}

//----- (006D4B80) --------------------------------------------------------  // acclient.c:747118
int _E609_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_2, "AL_0DL_6PL");
  return atexit(_E610_8);
}

//----- (006D4BA0) --------------------------------------------------------  // acclient.c:747125
int _E612_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_2, "AL_0DL_7PL");
  return atexit(_E613_8);
}

//----- (006D4BC0) --------------------------------------------------------  // acclient.c:747132
int _E615_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_2, "AL_0DL_8PL");
  return atexit(_E616_8);
}

//----- (006D4BE0) --------------------------------------------------------  // acclient.c:747139
int _E618_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_2, "AL_1DL_0PL");
  return atexit(_E619_8);
}

//----- (006D4C00) --------------------------------------------------------  // acclient.c:747146
int _E621_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_2, "AL_1DL_1PL");
  return atexit(_E622_8);
}

//----- (006D4C20) --------------------------------------------------------  // acclient.c:747153
int _E624_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_2, "AL_1DL_2PL");
  return atexit(_E625_8);
}

//----- (006D4C40) --------------------------------------------------------  // acclient.c:747160
int _E627_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_2, "AL_1DL_3PL");
  return atexit(_E628_8);
}

//----- (006D4C60) --------------------------------------------------------  // acclient.c:747167
int _E630_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_2, "AL_1DL_4PL");
  return atexit(_E631_8);
}

//----- (006D4C80) --------------------------------------------------------  // acclient.c:747174
int _E633_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_2, "AL_1DL_5PL");
  return atexit(_E634_8);
}

//----- (006D4CA0) --------------------------------------------------------  // acclient.c:747181
int _E636_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_2, "AL_1DL_6PL");
  return atexit(_E637_8);
}

//----- (006D4CC0) --------------------------------------------------------  // acclient.c:747188
int _E639_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_2, "AL_1DL_7PL");
  return atexit(_E640_8);
}

//----- (006D4CE0) --------------------------------------------------------  // acclient.c:747195
int _E642_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_2, "AL_0DL_0PL_Fog");
  return atexit(_E643_8);
}

//----- (006D4D00) --------------------------------------------------------  // acclient.c:747202
int _E645_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_2, "AL_0DL_1PL_Fog");
  return atexit(_E646_8);
}

//----- (006D4D20) --------------------------------------------------------  // acclient.c:747209
int _E648_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_2, "AL_0DL_2PL_Fog");
  return atexit(_E649_8);
}

//----- (006D4D40) --------------------------------------------------------  // acclient.c:747216
int _E651_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_2, "AL_0DL_3PL_Fog");
  return atexit(_E652_8);
}

//----- (006D4D60) --------------------------------------------------------  // acclient.c:747223
int _E654_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_2, "AL_0DL_4PL_Fog");
  return atexit(_E655_8);
}

//----- (006D4D80) --------------------------------------------------------  // acclient.c:747230
int _E657_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_2, "AL_0DL_5PL_Fog");
  return atexit(_E658_8);
}

//----- (006D4DA0) --------------------------------------------------------  // acclient.c:747237
int _E660_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_2, "AL_0DL_6PL_Fog");
  return atexit(_E661_8);
}

//----- (006D4DC0) --------------------------------------------------------  // acclient.c:747244
int _E663_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_2, "AL_0DL_7PL_Fog");
  return atexit(_E664_8);
}

//----- (006D4DE0) --------------------------------------------------------  // acclient.c:747251
int _E666_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_2, "AL_0DL_8PL_Fog");
  return atexit(_E667_8);
}

//----- (006D4E00) --------------------------------------------------------  // acclient.c:747258
int _E669_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_2, "AL_1DL_0PL_Fog");
  return atexit(_E670_8);
}

//----- (006D4E20) --------------------------------------------------------  // acclient.c:747265
int _E672_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_2, "AL_1DL_1PL_Fog");
  return atexit(_E673_8);
}

//----- (006D4E40) --------------------------------------------------------  // acclient.c:747272
int _E675_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_2, "AL_1DL_2PL_Fog");
  return atexit(_E676_8);
}

//----- (006D4E60) --------------------------------------------------------  // acclient.c:747279
int _E678_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_2, "AL_1DL_3PL_Fog");
  return atexit(_E679_8);
}

//----- (006D4E80) --------------------------------------------------------  // acclient.c:747286
int _E681_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_2, "AL_1DL_4PL_Fog");
  return atexit(_E682_8);
}

//----- (006D4EA0) --------------------------------------------------------  // acclient.c:747293
int _E684_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_2, "AL_1DL_5PL_Fog");
  return atexit(_E685_8);
}

//----- (006D4EC0) --------------------------------------------------------  // acclient.c:747300
int _E687_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_2, "AL_1DL_6PL_Fog");
  return atexit(_E688_8);
}

//----- (006D4EE0) --------------------------------------------------------  // acclient.c:747307
int _E690_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_2, "AL_1DL_7PL_Fog");
  return atexit(_E691_8);
}

//----- (006D4F00) --------------------------------------------------------  // acclient.c:747314
int _E693_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_2, "Zero");
  return atexit(_E694_8);
}

//----- (006D4F20) --------------------------------------------------------  // acclient.c:747321
int _E696_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_2, "One");
  return atexit(_E697_8);
}

//----- (006D4F40) --------------------------------------------------------  // acclient.c:747328
int _E699_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_2, "SrcColor");
  return atexit(_E700_8);
}

//----- (006D4F60) --------------------------------------------------------  // acclient.c:747335
int _E702_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_2, "InvSrcColor");
  return atexit(_E703_8);
}

//----- (006D4F80) --------------------------------------------------------  // acclient.c:747342
int _E705_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_2, "SrcAlpha");
  return atexit(_E706_8);
}

//----- (006D4FA0) --------------------------------------------------------  // acclient.c:747349
int _E708_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_2, "InvSrcAlpha");
  return atexit(_E709_8);
}

//----- (006D4FC0) --------------------------------------------------------  // acclient.c:747356
int _E711_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_2, "DstAlpha");
  return atexit(_E712_8);
}

//----- (006D4FE0) --------------------------------------------------------  // acclient.c:747363
int _E714_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_2, "InvDstAlpha");
  return atexit(_E715_8);
}

//----- (006D5000) --------------------------------------------------------  // acclient.c:747370
int _E717_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_2, "DstColor");
  return atexit(_E718_8);
}

//----- (006D5020) --------------------------------------------------------  // acclient.c:747377
int _E720_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_2, "InvDstColor");
  return atexit(_E721_8);
}

//----- (006D5040) --------------------------------------------------------  // acclient.c:747384
int _E723_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_2, "SrcAlphaSat");
  return atexit(_E724_8);
}

//----- (006D5060) --------------------------------------------------------  // acclient.c:747391
int _E726_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_2, "Less");
  return atexit(_E727_8);
}

//----- (006D5080) --------------------------------------------------------  // acclient.c:747398
int _E729_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_2, "Equal");
  return atexit(_E730_8);
}

//----- (006D50A0) --------------------------------------------------------  // acclient.c:747405
int _E732_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_2, "LessEqual");
  return atexit(_E733_8);
}

//----- (006D50C0) --------------------------------------------------------  // acclient.c:747412
int _E735_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_2, "Greater");
  return atexit(_E736_8);
}

//----- (006D50E0) --------------------------------------------------------  // acclient.c:747419
int _E738_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_2, "NotEqual");
  return atexit(_E739_8);
}

//----- (006D5100) --------------------------------------------------------  // acclient.c:747426
int _E741_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_2, "GreaterEqual");
  return atexit(_E742_8);
}

//----- (006D5120) --------------------------------------------------------  // acclient.c:747433
int _E744_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_2, "Always");
  return atexit(_E745_8);
}

//----- (006D5140) --------------------------------------------------------  // acclient.c:747440
int _E747_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_2, "On");
  return atexit(_E748_8);
}

//----- (006D5160) --------------------------------------------------------  // acclient.c:747447
int _E750_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_2, "Off");
  return atexit(_E751_8);
}

//----- (006D5180) --------------------------------------------------------  // acclient.c:747454
int _E753_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_2, "LayerDiffuse");
  return atexit(_E754_8);
}

//----- (006D51A0) --------------------------------------------------------  // acclient.c:747461
int _E756_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_2, "LayerSpecular");
  return atexit(_E757_8);
}

//----- (006D51C0) --------------------------------------------------------  // acclient.c:747468
int _E759_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_2, "VertexDiffuse");
  return atexit(_E760_8);
}

//----- (006D51E0) --------------------------------------------------------  // acclient.c:747475
int _E762_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_2, "VertexSpecular");
  return atexit(_E763_8);
}

//----- (006D5200) --------------------------------------------------------  // acclient.c:747482
int _E765_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_2, "None");
  return atexit(_E766_8);
}

//----- (006D5220) --------------------------------------------------------  // acclient.c:747489
int _E768_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_2, "CW");
  return atexit(_E769_8);
}

//----- (006D5240) --------------------------------------------------------  // acclient.c:747496
int _E771_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_2, "CCW");
  return atexit(_E772_8);
}

//----- (006D5260) --------------------------------------------------------  // acclient.c:747503
int _E774_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_2, "None");
  return atexit(_E775_8);
}

//----- (006D5280) --------------------------------------------------------  // acclient.c:747510
int _E777_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_2, "Simple");
  return atexit(_E778_8);
}

//----- (006D52A0) --------------------------------------------------------  // acclient.c:747517
int _E780_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_2, "Diffuse");
  return atexit(_E781_8);
}

//----- (006D52C0) --------------------------------------------------------  // acclient.c:747524
int _E783_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_2, "Specular");
  return atexit(_E784_8);
}

//----- (006D52E0) --------------------------------------------------------  // acclient.c:747531
int _E786_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_2, "Off");
  return atexit(_E787_8);
}

//----- (006D5300) --------------------------------------------------------  // acclient.c:747538
int _E789_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_2, "On");
  return atexit(_E790_8);
}

//----- (006D5320) --------------------------------------------------------  // acclient.c:747545
int _E792_1()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_2, "Off");
  return atexit(_E793_8);
}

//----- (006D5340) --------------------------------------------------------  // acclient.c:747552
int _E795_1()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_2, "On");
  return atexit(_E796_8);
}

//----- (006D5360) --------------------------------------------------------  // acclient.c:747559
int _E798_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_2, "Origin");
  return atexit(_E799_8);
}

//----- (006D5380) --------------------------------------------------------  // acclient.c:747566
int _E801_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_2, "Normal");
  return atexit(_E802_8);
}

//----- (006D53A0) --------------------------------------------------------  // acclient.c:747573
int _E804_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_2, "PointSize");
  return atexit(_E805_8);
}

//----- (006D53C0) --------------------------------------------------------  // acclient.c:747580
int _E807_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_2, "Diffuse");
  return atexit(_E808_8);
}

//----- (006D53E0) --------------------------------------------------------  // acclient.c:747587
int _E810_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_2, "Specular");
  return atexit(_E811_8);
}

//----- (006D5400) --------------------------------------------------------  // acclient.c:747594
int _E813_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_2, "TCPairX1");
  return atexit(_E814_8);
}

//----- (006D5420) --------------------------------------------------------  // acclient.c:747601
int _E816_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_2, "TCPairX2");
  return atexit(_E817_8);
}

//----- (006D5440) --------------------------------------------------------  // acclient.c:747608
int _E819_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_2, "TCPairX3");
  return atexit(_E820_8);
}

//----- (006D5460) --------------------------------------------------------  // acclient.c:747615
int _E822_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_2, "TCPairX4");
  return atexit(_E823_8);
}

//----- (006D5480) --------------------------------------------------------  // acclient.c:747622
int _E825_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_2, "TCPairX5");
  return atexit(_E826_8);
}

//----- (006D54A0) --------------------------------------------------------  // acclient.c:747629
int _E828_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_2, "TCPairX6");
  return atexit(_E829_8);
}

//----- (006D54C0) --------------------------------------------------------  // acclient.c:747636
int _E831_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_2, "TCPairX7");
  return atexit(_E832_8);
}

//----- (006D54E0) --------------------------------------------------------  // acclient.c:747643
int _E834_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_2, "TCPairX8");
  return atexit(_E835_8);
}

//----- (006D5500) --------------------------------------------------------  // acclient.c:747650
int _E837_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_2, "VectorS");
  return atexit(_E838_8);
}

//----- (006D5520) --------------------------------------------------------  // acclient.c:747657
int _E840_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_2, "VectorT");
  return atexit(_E841_8);
}

//----- (006D5540) --------------------------------------------------------  // acclient.c:747664
int _E843_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_34, "Stage");
  return atexit(_E844_8);
}

//----- (006D5560) --------------------------------------------------------  // acclient.c:747671
int _E846_1()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_2, "Sampler");
  return atexit(_E847_8);
}

//----- (006D5580) --------------------------------------------------------  // acclient.c:747678
int _E849_1()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_2, "SamplerName");
  return atexit(_E850_8);
}

//----- (006D55A0) --------------------------------------------------------  // acclient.c:747685
int _E852_1()
{
  PStringBase<char>::PStringBase<char>(&Texture_2, "Texture");
  return atexit(_E853_8);
}

//----- (006D55C0) --------------------------------------------------------  // acclient.c:747692
int _E855_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_2, "!FrameBuffer");
  return atexit(_E856_8);
}

//----- (006D55E0) --------------------------------------------------------  // acclient.c:747699
int _E858_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_2, "!Distortion");
  return atexit(_E859_8);
}

//----- (006D5600) --------------------------------------------------------  // acclient.c:747706
int _E861_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_2, "!Reflection");
  return atexit(_E862_8);
}

//----- (006D5620) --------------------------------------------------------  // acclient.c:747713
int _E864_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_2, "!NormalizeCube");
  return atexit(_E865_8);
}

//----- (006D5640) --------------------------------------------------------  // acclient.c:747720
int _E867_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_2, "!LightProjectorCube");
  return atexit(_E868_8);
}

//----- (006D5660) --------------------------------------------------------  // acclient.c:747727
int _E870_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_2, "!EnvironmentCube");
  return atexit(_E871_8);
}

//----- (006D5680) --------------------------------------------------------  // acclient.c:747734
int _E873_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_2, "!LandscapeShadows");
  return atexit(_E874_8);
}

//----- (006D56A0) --------------------------------------------------------  // acclient.c:747741
int _E876_1()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_2, "AddressMode");
  return atexit(_E877_8);
}

//----- (006D56C0) --------------------------------------------------------  // acclient.c:747748
int _E879_1()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_2, "FilterMode");
  return atexit(_E880_8);
}

//----- (006D56E0) --------------------------------------------------------  // acclient.c:747755
int _E882_1()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_2, "FFColorOp");
  return atexit(_E883_8);
}

//----- (006D5700) --------------------------------------------------------  // acclient.c:747762
int _E885_1()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_2, "FFColorArg1");
  return atexit(_E886_8);
}

//----- (006D5720) --------------------------------------------------------  // acclient.c:747769
int _E888_1()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_2, "FFColorArg2");
  return atexit(_E889_8);
}

//----- (006D5740) --------------------------------------------------------  // acclient.c:747776
int _E891_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_2, "FFAlphaOp");
  return atexit(_E892_8);
}

//----- (006D5760) --------------------------------------------------------  // acclient.c:747783
int _E894_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_2, "FFAlphaArg1");
  return atexit(_E895_8);
}

//----- (006D5780) --------------------------------------------------------  // acclient.c:747790
int _E897_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_2, "FFAlphaArg2");
  return atexit(_E898_8);
}

//----- (006D57A0) --------------------------------------------------------  // acclient.c:747797
int _E900_1()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_2, "FFTexCoordIndex");
  return atexit(_E901_8);
}

//----- (006D57C0) --------------------------------------------------------  // acclient.c:747804
int _E903_1()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_2, "FFUseProjection");
  return atexit(_E904_8);
}

//----- (006D57E0) --------------------------------------------------------  // acclient.c:747811
int _E906_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_2, "SelectArg1");
  return atexit(_E907_8);
}

//----- (006D5800) --------------------------------------------------------  // acclient.c:747818
int _E909_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_2, "SelectArg2");
  return atexit(_E910_8);
}

//----- (006D5820) --------------------------------------------------------  // acclient.c:747825
int _E912_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_2, "Modulate");
  return atexit(_E913_8);
}

//----- (006D5840) --------------------------------------------------------  // acclient.c:747832
int _E915_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_2, "Modulate2X");
  return atexit(_E916_8);
}

//----- (006D5860) --------------------------------------------------------  // acclient.c:747839
int _E918_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_2, "Modulate4X");
  return atexit(_E919_8);
}

//----- (006D5880) --------------------------------------------------------  // acclient.c:747846
int _E921_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_2, "Add");
  return atexit(_E922_8);
}

//----- (006D58A0) --------------------------------------------------------  // acclient.c:747853
int _E924_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_2, "AddSigned");
  return atexit(_E925_8);
}

//----- (006D58C0) --------------------------------------------------------  // acclient.c:747860
int _E927_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_2, "AddSigned2X");
  return atexit(_E928_8);
}

//----- (006D58E0) --------------------------------------------------------  // acclient.c:747867
int _E930_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_2, "Subtract");
  return atexit(_E931_8);
}

//----- (006D5900) --------------------------------------------------------  // acclient.c:747874
int _E933_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_2, "AddSmooth");
  return atexit(_E934_8);
}

//----- (006D5920) --------------------------------------------------------  // acclient.c:747881
int _E936_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_2, "BlendDiffuseAlpha");
  return atexit(_E937_8);
}

//----- (006D5940) --------------------------------------------------------  // acclient.c:747888
int _E939_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_2, "BlendTextureAlpha");
  return atexit(_E940_8);
}

//----- (006D5960) --------------------------------------------------------  // acclient.c:747895
int _E942_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_2, "BlendFactorAlpha");
  return atexit(_E943_8);
}

//----- (006D5980) --------------------------------------------------------  // acclient.c:747902
int _E945_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_2, "BlendTextureAlphaPM");
  return atexit(_E946_8);
}

//----- (006D59A0) --------------------------------------------------------  // acclient.c:747909
int _E948_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_2, "BlendCurrentAlpha");
  return atexit(_E949_8);
}

//----- (006D59C0) --------------------------------------------------------  // acclient.c:747916
int _E951_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_2, "Premodulate");
  return atexit(_E952_8);
}

//----- (006D59E0) --------------------------------------------------------  // acclient.c:747923
int _E954_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_2, "ModulateAlphaAddColor");
  return atexit(_E955_8);
}

//----- (006D5A00) --------------------------------------------------------  // acclient.c:747930
int _E957_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_2, "ModulateColorAddAlpha");
  return atexit(_E958_8);
}

//----- (006D5A20) --------------------------------------------------------  // acclient.c:747937
int _E960_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_2, "ModulateInvAlphaAddColor");
  return atexit(_E961_8);
}

//----- (006D5A40) --------------------------------------------------------  // acclient.c:747944
int _E963_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_2, "ModulateInvColorAddAlpha");
  return atexit(_E964_8);
}

//----- (006D5A60) --------------------------------------------------------  // acclient.c:747951
int _E966_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_2, "BumpEnvMap");
  return atexit(_E967_8);
}

//----- (006D5A80) --------------------------------------------------------  // acclient.c:747958
int _E969_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_2, "BumpEnvMapLuminance");
  return atexit(_E970_8);
}

//----- (006D5AA0) --------------------------------------------------------  // acclient.c:747965
int _E972_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_2, "DotProduct3");
  return atexit(_E973_8);
}

//----- (006D5AC0) --------------------------------------------------------  // acclient.c:747972
int _E975_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_2, "MultiplyAdd");
  return atexit(_E976_8);
}

//----- (006D5AE0) --------------------------------------------------------  // acclient.c:747979
int _E978_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_2, "Lerp");
  return atexit(_E979_8);
}

//----- (006D5B00) --------------------------------------------------------  // acclient.c:747986
int _E981_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_2, "Diffuse");
  return atexit(_E982_8);
}

//----- (006D5B20) --------------------------------------------------------  // acclient.c:747993
int _E984_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_2, "Specular");
  return atexit(_E985_8);
}

//----- (006D5B40) --------------------------------------------------------  // acclient.c:748000
int _E987_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_2, "Current");
  return atexit(_E988_8);
}

//----- (006D5B60) --------------------------------------------------------  // acclient.c:748007
int _E990_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_2, "Texture");
  return atexit(_E991_8);
}

//----- (006D5B80) --------------------------------------------------------  // acclient.c:748014
int _E993_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_2, "TFactor");
  return atexit(_E994_8);
}

//----- (006D5BA0) --------------------------------------------------------  // acclient.c:748021
int _E996_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_2, "Wrap");
  return atexit(_E997_8);
}

//----- (006D5BC0) --------------------------------------------------------  // acclient.c:748028
int _E999_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_2, "Mirror");
  return atexit(_E1000_8);
}

//----- (006D5BE0) --------------------------------------------------------  // acclient.c:748035
int _E1002_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_2, "Clamp");
  return atexit(_E1003_8);
}

//----- (006D5C00) --------------------------------------------------------  // acclient.c:748042
int _E1005_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_2, "Border");
  return atexit(_E1006_8);
}

//----- (006D5C20) --------------------------------------------------------  // acclient.c:748049
int _E1008_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_2, "None");
  return atexit(_E1009_8);
}

//----- (006D5C40) --------------------------------------------------------  // acclient.c:748056
int _E1011_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_2, "Point");
  return atexit(_E1012_8);
}

//----- (006D5C60) --------------------------------------------------------  // acclient.c:748063
int _E1014_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_2, "Linear");
  return atexit(_E1015_8);
}

//----- (006D5C80) --------------------------------------------------------  // acclient.c:748070
int _E1017_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_2, "Anisotropic");
  return atexit(_E1018_8);
}

//----- (006D5CA0) --------------------------------------------------------  // acclient.c:748077
int _E1020_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_2, "ReflectionVector");
  return atexit(_E1021_8);
}

//----- (006D5CC0) --------------------------------------------------------  // acclient.c:748084
int _E1023_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_2, "ViewNormal");
  return atexit(_E1024_8);
}

//----- (006D5CE0) --------------------------------------------------------  // acclient.c:748091
int _E1026_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_2, "ViewOrigin");
  return atexit(_E1027_8);
}

//----- (006D5D00) --------------------------------------------------------  // acclient.c:748098
int _E1029_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_2, "SphereMap");
  return atexit(_E1030_8);
}

//----- (006D5D20) --------------------------------------------------------  // acclient.c:748105
int _E1032_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_2, "CubeMapReflection");
  return atexit(_E1033_8);
}

//----- (006D5D40) --------------------------------------------------------  // acclient.c:748112
int _E1035_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_2, "CubeMapFakeLight");
  return atexit(_E1036_8);
}

//----- (006D5D60) --------------------------------------------------------  // acclient.c:748119
int _E1038_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_35, "FFModifier");
  return atexit(_E1039_8);
}

//----- (006D5D80) --------------------------------------------------------  // acclient.c:748126
int _E1041_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_2, "Origin");
  return atexit(_E1042_8);
}

//----- (006D5DA0) --------------------------------------------------------  // acclient.c:748133
int _E1044_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_2, "Normal");
  return atexit(_E1045_8);
}

//----- (006D5DC0) --------------------------------------------------------  // acclient.c:748140
int _E1047_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_2, "Diffuse");
  return atexit(_E1048_8);
}

//----- (006D5DE0) --------------------------------------------------------  // acclient.c:748147
int _E1050_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_2, "UVTranslate");
  return atexit(_E1051_8);
}

//----- (006D5E00) --------------------------------------------------------  // acclient.c:748154
int _E1053_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_2, "UVRotate");
  return atexit(_E1054_8);
}

//----- (006D5E20) --------------------------------------------------------  // acclient.c:748161
int _E1056_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_2, "UVScale");
  return atexit(_E1057_8);
}

//----- (006D5E40) --------------------------------------------------------  // acclient.c:748168
int _E1059_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_2, "UVTransform");
  return atexit(_E1060_8);
}

//----- (006D5E60) --------------------------------------------------------  // acclient.c:748175
int _E1062_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_2, "TexCoordIndex");
  return atexit(_E1063_8);
}

//----- (006D5E80) --------------------------------------------------------  // acclient.c:748182
int _E1065_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_2, "Translate");
  return atexit(_E1066_8);
}

//----- (006D5EA0) --------------------------------------------------------  // acclient.c:748189
int _E1068_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_2, "TexCoordIndex");
  return atexit(_E1069_8);
}

//----- (006D5EC0) --------------------------------------------------------  // acclient.c:748196
int _E1071_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_2, "Rotate");
  return atexit(_E1072_8);
}

//----- (006D5EE0) --------------------------------------------------------  // acclient.c:748203
int _E1074_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_2, "TexCoordIndex");
  return atexit(_E1075_8);
}

//----- (006D5F00) --------------------------------------------------------  // acclient.c:748210
int _E1077_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_2, "Scale");
  return atexit(_E1078_8);
}

//----- (006D5F20) --------------------------------------------------------  // acclient.c:748217
int _E1080_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_36, "PSDesc");
  return atexit(_E1081_8);
}

//----- (006D5F40) --------------------------------------------------------  // acclient.c:748224
int _E1083_1()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_2, "PhysicsTimeStep");
  return atexit(_E1084_8);
}

//----- (006D5F60) --------------------------------------------------------  // acclient.c:748231
int _E1086_1()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_2, "FastForwardTime");
  return atexit(_E1087_8);
}

//----- (006D5F80) --------------------------------------------------------  // acclient.c:748238
int _E1089_1()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_2, "StartFadeDistance");
  return atexit(_E1090_8);
}

//----- (006D5FA0) --------------------------------------------------------  // acclient.c:748245
int _E1092_1()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_2, "StopFadeDistance");
  return atexit(_E1093_8);
}

//----- (006D5FC0) --------------------------------------------------------  // acclient.c:748252
int _E1095_1()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_2, "PhysicsDuration");
  return atexit(_E1096_8);
}

//----- (006D5FE0) --------------------------------------------------------  // acclient.c:748259
int _E1098_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_2, "ScaleType");
  return atexit(_E1099_8);
}

//----- (006D6000) --------------------------------------------------------  // acclient.c:748266
int _E1101_1()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_2, "WorldSpace");
  return atexit(_E1102_8);
}

//----- (006D6020) --------------------------------------------------------  // acclient.c:748273
int _E1104_1()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_2, "ForceDraw");
  return atexit(_E1105_8);
}

//----- (006D6040) --------------------------------------------------------  // acclient.c:748280
int _E1107_1()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_2, "NumEmitters");
  return atexit(_E1108_8);
}

//----- (006D6060) --------------------------------------------------------  // acclient.c:748287
int _E1110_1()
{
  PStringBase<char>::PStringBase<char>(&Material_15, "Material");
  return atexit(_E1111_8);
}

//----- (006D6080) --------------------------------------------------------  // acclient.c:748294
int _E1113_1()
{
  PStringBase<char>::PStringBase<char>(&Version_2, "Version");
  return atexit(_E1114_8);
}

//----- (006D60A0) --------------------------------------------------------  // acclient.c:748301
int _E1116_1()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_2, "MaxParticles");
  return atexit(_E1117_8);
}

//----- (006D60C0) --------------------------------------------------------  // acclient.c:748308
int _E1119_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_37, "Emitter");
  return atexit(_E1120_8);
}

//----- (006D60E0) --------------------------------------------------------  // acclient.c:748315
int _E1122_1()
{
  PStringBase<char>::PStringBase<char>(&Origin_6, "Origin");
  return atexit(_E1123_8);
}

//----- (006D6100) --------------------------------------------------------  // acclient.c:748322
int _E1125_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_2, "Shape");
  return atexit(_E1126_8);
}

//----- (006D6120) --------------------------------------------------------  // acclient.c:748329
int _E1128_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_2, "Point");
  return atexit(_E1129_8);
}

//----- (006D6140) --------------------------------------------------------  // acclient.c:748336
int _E1131_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_2, "Line");
  return atexit(_E1132_8);
}

//----- (006D6160) --------------------------------------------------------  // acclient.c:748343
int _E1134_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_2, "Quad");
  return atexit(_E1135_8);
}

//----- (006D6180) --------------------------------------------------------  // acclient.c:748350
int _E1137_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_2, "Disc");
  return atexit(_E1138_8);
}

//----- (006D61A0) --------------------------------------------------------  // acclient.c:748357
int _E1140_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_2, "Sphere");
  return atexit(_E1141_8);
}

//----- (006D61C0) --------------------------------------------------------  // acclient.c:748364
int _E1143_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_2, "ParticleShape");
  return atexit(_E1144_8);
}

//----- (006D61E0) --------------------------------------------------------  // acclient.c:748371
int _E1146_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_2, "Triangle");
  return atexit(_E1147_8);
}

//----- (006D6200) --------------------------------------------------------  // acclient.c:748378
int _E1149_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_2, "Quad");
  return atexit(_E1150_8);
}

//----- (006D6220) --------------------------------------------------------  // acclient.c:748385
int _E1152_1()
{
  PStringBase<char>::PStringBase<char>(&Streak_2, "Streak");
  return atexit(_E1153_8);
}

//----- (006D6240) --------------------------------------------------------  // acclient.c:748392
int _E1155_1()
{
  PStringBase<char>::PStringBase<char>(&Rotation_6, "Rotation");
  return atexit(_E1156_8);
}

//----- (006D6260) --------------------------------------------------------  // acclient.c:748399
int _E1158_1()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_2, "WorldRotation");
  return atexit(_E1159_8);
}

//----- (006D6280) --------------------------------------------------------  // acclient.c:748406
int _E1161_1()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_2, "RotateVelocity");
  return atexit(_E1162_8);
}

//----- (006D62A0) --------------------------------------------------------  // acclient.c:748413
int _E1164_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_2, "ParticleScale");
  return atexit(_E1165_8);
}

//----- (006D62C0) --------------------------------------------------------  // acclient.c:748420
int _E1167_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_9, "Scale");
  return atexit(_E1168_8);
}

//----- (006D62E0) --------------------------------------------------------  // acclient.c:748427
int _E1170_1()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_2, "ExplodingDir");
  return atexit(_E1171_8);
}

//----- (006D6300) --------------------------------------------------------  // acclient.c:748434
int _E1173_1()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_2, "BirthRate");
  return atexit(_E1174_8);
}

//----- (006D6320) --------------------------------------------------------  // acclient.c:748441
int _E1176_1()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_2, "Lifespan");
  return atexit(_E1177_8);
}

//----- (006D6340) --------------------------------------------------------  // acclient.c:748448
int _E1179_1()
{
  PStringBase<char>::PStringBase<char>(&Velocity_2, "Velocity");
  return atexit(_E1180_8);
}

//----- (006D6360) --------------------------------------------------------  // acclient.c:748455
int _E1182_1()
{
  PStringBase<char>::PStringBase<char>(&Direction_2, "Direction");
  return atexit(_E1183_8);
}

//----- (006D6380) --------------------------------------------------------  // acclient.c:748462
int _E1185_1()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_2, "MinSpread");
  return atexit(_E1186_8);
}

//----- (006D63A0) --------------------------------------------------------  // acclient.c:748469
int _E1188_1()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_2, "MaxSpread");
  return atexit(_E1189_8);
}

//----- (006D63C0) --------------------------------------------------------  // acclient.c:748476
int _E1191_1()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_2, "EmissionLimit");
  return atexit(_E1192_8);
}

//----- (006D63E0) --------------------------------------------------------  // acclient.c:748483
int _E1194_1()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_2, "BlastCount");
  return atexit(_E1195_8);
}

//----- (006D6400) --------------------------------------------------------  // acclient.c:748490
int _E1197_1()
{
  PStringBase<char>::PStringBase<char>(&StartTime_2, "StartTime");
  return atexit(_E1198_8);
}

//----- (006D6420) --------------------------------------------------------  // acclient.c:748497
int _E1200_1()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_2, "TimeLimit");
  return atexit(_E1201_8);
}

//----- (006D6440) --------------------------------------------------------  // acclient.c:748504
int _E1203_1()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_2, "EmissionDistance");
  return atexit(_E1204_8);
}

//----- (006D6460) --------------------------------------------------------  // acclient.c:748511
int _E1206_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_2, "ParticleSnap");
  return atexit(_E1207_8);
}

//----- (006D6480) --------------------------------------------------------  // acclient.c:748518
int _E1209_1()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_2, "InclusiveShape");
  return atexit(_E1210_8);
}

//----- (006D64A0) --------------------------------------------------------  // acclient.c:748525
int _E1212_1()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_2, "NumKeyframes");
  return atexit(_E1213_8);
}

//----- (006D64C0) --------------------------------------------------------  // acclient.c:748532
int _E1215_1()
{
  PStringBase<char>::PStringBase<char>(&IsActive_2, "IsActive");
  return atexit(_E1216_8);
}

//----- (006D64E0) --------------------------------------------------------  // acclient.c:748539
int _E1218_1()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_2, "FadeIn");
  return atexit(_E1219_8);
}

//----- (006D6500) --------------------------------------------------------  // acclient.c:748546
int _E1221_1()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_2, "FadeOut");
  return atexit(_E1222_8);
}

//----- (006D6520) --------------------------------------------------------  // acclient.c:748553
int _E1224_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_2, "ConstrainX");
  return atexit(_E1225_8);
}

//----- (006D6540) --------------------------------------------------------  // acclient.c:748560
int _E1227_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_2, "ConstrainY");
  return atexit(_E1228_8);
}

//----- (006D6560) --------------------------------------------------------  // acclient.c:748567
int _E1230_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_2, "ConstrainZ");
  return atexit(_E1231_8);
}

//----- (006D6580) --------------------------------------------------------  // acclient.c:748574
int _E1233_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_38, "Keyframe");
  return atexit(_E1234_8);
}

//----- (006D65A0) --------------------------------------------------------  // acclient.c:748581
int _E1236_1()
{
  PStringBase<char>::PStringBase<char>(&Time_2, "Time");
  return atexit(_E1237_8);
}

//----- (006D65C0) --------------------------------------------------------  // acclient.c:748588
int _E1239_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_2, "Flags");
  return atexit(_E1240_8);
}

//----- (006D65E0) --------------------------------------------------------  // acclient.c:748595
int _E1242_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_2, "None");
  return atexit(_E1243_8);
}

//----- (006D6600) --------------------------------------------------------  // acclient.c:748602
int _E1245_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_2, "BlendScale");
  return atexit(_E1246_8);
}

//----- (006D6620) --------------------------------------------------------  // acclient.c:748609
int _E1248_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_2, "BlendColor");
  return atexit(_E1249_8);
}

//----- (006D6640) --------------------------------------------------------  // acclient.c:748616
int _E1251_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_2, "BlendMass");
  return atexit(_E1252_8);
}

//----- (006D6660) --------------------------------------------------------  // acclient.c:748623
int _E1254_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_2, "SetScale");
  return atexit(_E1255_8);
}

//----- (006D6680) --------------------------------------------------------  // acclient.c:748630
int _E1257_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_2, "SetColor");
  return atexit(_E1258_7);
}

//----- (006D66A0) --------------------------------------------------------  // acclient.c:748637
int _E1260_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_2, "SetMass");
  return atexit(_E1261_6);
}

//----- (006D66C0) --------------------------------------------------------  // acclient.c:748644
int _E1263_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_2, "SetParticleFlags");
  return atexit(_E1264_6);
}

//----- (006D66E0) --------------------------------------------------------  // acclient.c:748651
int _E1266_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_2, "SetControllerType");
  return atexit(_E1267_6);
}

//----- (006D6700) --------------------------------------------------------  // acclient.c:748658
int _E1269_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_2, "SetPhysicsFlags");
  return atexit(_E1270_6);
}

//----- (006D6720) --------------------------------------------------------  // acclient.c:748665
int _E1272_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_2, "SetParams");
  return atexit(_E1273_6);
}

//----- (006D6740) --------------------------------------------------------  // acclient.c:748672
int _E1275_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_10, "Scale");
  return atexit(_E1276_7);
}

//----- (006D6760) --------------------------------------------------------  // acclient.c:748679
int _E1278_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_2, "ScaleX");
  return atexit(_E1279_6);
}

//----- (006D6780) --------------------------------------------------------  // acclient.c:748686
int _E1281_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_2, "ScaleY");
  return atexit(_E1282_7);
}

//----- (006D67A0) --------------------------------------------------------  // acclient.c:748693
int _E1284_1()
{
  PStringBase<char>::PStringBase<char>(&Color_2, "Color");
  return atexit(_E1285_6);
}

//----- (006D67C0) --------------------------------------------------------  // acclient.c:748700
int _E1287_1()
{
  PStringBase<char>::PStringBase<char>(&Mass_2, "Mass");
  return atexit(_E1288_6);
}

//----- (006D67E0) --------------------------------------------------------  // acclient.c:748707
int _E1290_1()
{
  PStringBase<char>::PStringBase<char>(&PFlags_2, "ParticleFlags");
  return atexit(_E1291_5);
}

//----- (006D6800) --------------------------------------------------------  // acclient.c:748714
int _E1293_1()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_2, "None");
  return atexit(_E1294_6);
}

//----- (006D6820) --------------------------------------------------------  // acclient.c:748721
int _E1296_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_2, "ControllerType");
  return atexit(_E1297_5);
}

//----- (006D6840) --------------------------------------------------------  // acclient.c:748728
int _E1299_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_2, "None");
  return atexit(_E1300_5);
}

//----- (006D6860) --------------------------------------------------------  // acclient.c:748735
int _E1302_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_2, "Physics");
  return atexit(_E1303_4);
}

//----- (006D6880) --------------------------------------------------------  // acclient.c:748742
int _E1305_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_2, "Parametric");
  return atexit(_E1306_3);
}

//----- (006D68A0) --------------------------------------------------------  // acclient.c:748749
int _E1308_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_2, "AttractRepulse");
  return atexit(_E1309_3);
}

//----- (006D68C0) --------------------------------------------------------  // acclient.c:748756
int _E1311_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_2, "PointFile");
  return atexit(_E1312_3);
}

//----- (006D68E0) --------------------------------------------------------  // acclient.c:748763
int _E1314_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_2, "PointFileLerp");
  return atexit(_E1315_1);
}

//----- (006D6900) --------------------------------------------------------  // acclient.c:748770
int _E1317_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_2, "PhysicsFlags");
  return atexit(_E1318_1);
}

//----- (006D6920) --------------------------------------------------------  // acclient.c:748777
int _E1320_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_2, "None");
  return atexit(_E1321_1);
}

//----- (006D6940) --------------------------------------------------------  // acclient.c:748784
int _E1323_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_2, "Gravity");
  return atexit(_E1324_1);
}

//----- (006D6960) --------------------------------------------------------  // acclient.c:748791
int _E1326_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_2, "Wind");
  return atexit(_E1327_1);
}

//----- (006D6980) --------------------------------------------------------  // acclient.c:748798
int _E1329_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_2, "Momentum");
  return atexit(_E1330_1);
}

//----- (006D69A0) --------------------------------------------------------  // acclient.c:748805
int _E1332_1()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_2, "RandomPoint");
  return atexit(_E1333_1);
}

//----- (006D69C0) --------------------------------------------------------  // acclient.c:748812
int _E1335_1()
{
  PStringBase<char>::PStringBase<char>(&Position_3, "Position");
  return atexit(_E1336_1);
}

//----- (006D69E0) --------------------------------------------------------  // acclient.c:748819
int _E1338_1()
{
  PStringBase<char>::PStringBase<char>(&PointList_2, "PointList");
  return atexit(_E1339_1);
}

//----- (006D6A00) --------------------------------------------------------  // acclient.c:748826
int _E1341_1()
{
  PStringBase<char>::PStringBase<char>(&Point_6, "pt");
  return atexit(_E1342_1);
}

//----- (006D6A20) --------------------------------------------------------  // acclient.c:748833
int _E1344_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_2, "DetailLevels");
  return atexit(_E1345_1);
}

//----- (006D6A40) --------------------------------------------------------  // acclient.c:748840
int _E1347_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_2, "Low");
  return atexit(_E1348_1);
}

//----- (006D6A60) --------------------------------------------------------  // acclient.c:748847
int _E1350_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_2, "Medium");
  return atexit(_E1351_1);
}

//----- (006D6A80) --------------------------------------------------------  // acclient.c:748854
int _E1353_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_2, "High");
  return atexit(_E1354_1);
}

//----- (006D6AA0) --------------------------------------------------------  // acclient.c:748861
int _E1356_1()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_2, "FadeSpeed");
  return atexit(_E1357_1);
}

//----- (006D6AC0) --------------------------------------------------------  // acclient.c:748868
int _E1359_1()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_2, "MaxOpacity");
  return atexit(_E1360_1);
}

//----- (006D6AE0) --------------------------------------------------------  // acclient.c:748875
int _E1362_1()
{
  PStringBase<char>::PStringBase<char>(&Point_7, "Point");
  return atexit(_E1363_1);
}

//----- (006D6B00) --------------------------------------------------------  // acclient.c:748882
int _E1365_1()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_2, "AxisPos");
  return atexit(_E1366_1);
}

//----- (006D6B20) --------------------------------------------------------  // acclient.c:748889
int _E1368_1()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_2, "Texture");
  return atexit(_E1369_1);
}

//----- (006D6B40) --------------------------------------------------------  // acclient.c:748896
int _E1371_1()
{
  PStringBase<char>::PStringBase<char>(&PointSize_2, "Size");
  return atexit(_E1372_1);
}

//----- (006D6B60) --------------------------------------------------------  // acclient.c:748903
int _E1374_1()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_2, "UseOcclusion");
  return atexit(_E1375_1);
}

//----- (006D6B80) --------------------------------------------------------  // acclient.c:748910
int _E1377_1()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_2, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83A150, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83A154, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_83A158, "PREPROC_OPTIONS");
  return atexit(_E1378_1);
}

//----- (006D6BD0) --------------------------------------------------------  // acclient.c:748920
int _E1380_0()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"ProjectSetting");
  PStringBase<unsigned short>::allocate_ref_buffer(&PROJECTSETTING_2, v0);
  _wcscpy(PROJECTSETTING_2.m_charbuffer->m_data, L"ProjectSetting");
  return atexit(_E1381_0);
}

//----- (006D6C10) --------------------------------------------------------  // acclient.c:748931
int _E1383_0()
{
  PStringBase<char>::PStringBase<char>(&NAME_2, "name");
  return atexit(_E1384_0);
}

//----- (006D6C30) --------------------------------------------------------  // acclient.c:748938
int _E1386_0()
{
  PStringBase<char>::PStringBase<char>(&VALUE_2, "value");
  return atexit(_E1387_0);
}

//----- (006D6C50) --------------------------------------------------------  // acclient.c:748945
int _E1389_0()
{
  PStringBase<char>::PStringBase<char>(&BRANCH_2, "branch");
  return atexit(_E1390_0);
}

//----- (006D6C70) --------------------------------------------------------  // acclient.c:748952
int _E1392_0()
{
  PStringBase<char>::PStringBase<char>(&BRANCHBASEDIR_2, "branchbasedir");
  return atexit(_E1393_0);
}

//----- (006D6C90) --------------------------------------------------------  // acclient.c:748959
int _E1395_0()
{
  PStringBase<char>::PStringBase<char>(&PROJECTNAME_2, "projectname");
  return atexit(_E1396_0);
}

//----- (006D6CB0) --------------------------------------------------------  // acclient.c:748966
int _E1398_0()
{
  PStringBase<char>::PStringBase<char>(&LONGNAME_2, "longname");
  return atexit(_E1399_0);
}

//----- (006D6CD0) --------------------------------------------------------  // acclient.c:748973
int _E1401_0()
{
  PStringBase<char>::PStringBase<char>(&ENUMDB_2, "enumdb");
  return atexit(_E1402_0);
}

//----- (006D6CF0) --------------------------------------------------------  // acclient.c:748980
int _E1404_0()
{
  PStringBase<char>::PStringBase<char>(&DIDNAME_2, "didname");
  return atexit(_E1405_0);
}

//----- (006D6D10) --------------------------------------------------------  // acclient.c:748987
int _E1407_0()
{
  PStringBase<char>::PStringBase<char>(&RCS_2, "rcs");
  return atexit(_E1408_0);
}

//----- (006D6D30) --------------------------------------------------------  // acclient.c:748994
int _E1410_0()
{
  PStringBase<char>::PStringBase<char>(&PREPROC_KEYS_BASE_PATH_2, "SOFTWARE\\Turbine\\Preproc");
  return atexit(_E1411_0);
}

//----- (006D6D50) --------------------------------------------------------  // acclient.c:749001
int _E1413_0()
{
  PStringBase<char>::PStringBase<char>(&CURRENT_PROJECT_2, "CURRENT_PROJECT");
  return atexit(_E1414_0);
}

//----- (006D6D70) --------------------------------------------------------  // acclient.c:749008
int _E1416_0()
{
  PStringBase<char>::PStringBase<char>(&DATA_GAME_PATH_2, "data/game");
  return atexit(_E1417_0);
}

//----- (006D6D90) --------------------------------------------------------  // acclient.c:749015
int _E1419_0()
{
  PStringBase<char>::PStringBase<char>(&DATA_ENGINE_PATH_2, "data/engine");
  return atexit(_E1420_0);
}

//----- (006D6DB0) --------------------------------------------------------  // acclient.c:749022
int _E1422_0()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_GAME_PATH_2, "src/game");
  return atexit(_E1423_0);
}

//----- (006D6DD0) --------------------------------------------------------  // acclient.c:749029
int _E1425_0()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_ENGINE_PATH_2, "src/engine");
  return atexit(_E1426_0);
}

//----- (006D6DF0) --------------------------------------------------------  // acclient.c:749036
int _E1428_0()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_BIN_PATH_2, "tools/bin");
  return atexit(_E1429_0);
}

//----- (006D6E10) --------------------------------------------------------  // acclient.c:749043
int _E1431_0()
{
  PStringBase<char>::PStringBase<char>(&CONFIG_TOOLS_PATH_2, "config/tools");
  return atexit(_E1432_0);
}

//----- (006D6E30) --------------------------------------------------------  // acclient.c:749050
int _E1434_0()
{
  PStringBase<char>::PStringBase<char>(&OUTPUT_INI_PATH_2, "output/ini");
  return atexit(_E1435_0);
}

//----- (006D6E50) --------------------------------------------------------  // acclient.c:749057
int _E1437_0()
{
  PStringBase<char>::PStringBase<char>(&DATA_PATH_2, "data");
  return atexit(_E1438_0);
}

//----- (006D6E70) --------------------------------------------------------  // acclient.c:749064
int _E1440_0()
{
  PStringBase<char>::PStringBase<char>(&DOC_PATH_2, "doc");
  return atexit(_E1441_0);
}

//----- (006D6E90) --------------------------------------------------------  // acclient.c:749071
int _E1443_0()
{
  PStringBase<char>::PStringBase<char>(&EXPORT_PATH_2, "export");
  return atexit(_E1444_0);
}

//----- (006D6EB0) --------------------------------------------------------  // acclient.c:749078
int _E1446_0()
{
  PStringBase<char>::PStringBase<char>(&SDK_PATH_2, "sdk");
  return atexit(_E1447_0);
}

//----- (006D6ED0) --------------------------------------------------------  // acclient.c:749085
int _E1449_0()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_PATH_2, "src");
  return atexit(_E1450_0);
}

//----- (006D6EF0) --------------------------------------------------------  // acclient.c:749092
int _E1452_0()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_PATH_2, "tools");
  return atexit(_E1453_0);
}

//----- (006D6F10) --------------------------------------------------------  // acclient.c:749099
int _E1455_0()
{
  PStringBase<char>::PStringBase<char>(&PORTAL_PATH_2, "portal");
  return atexit(_E1456_0);
}

//----- (006D6F30) --------------------------------------------------------  // acclient.c:749106
int _E1458_0()
{
  PStringBase<char>::PStringBase<char>(&AC_PATH_2, "ac");
  return atexit(_E1459_0);
}

//----- (006D6F50) --------------------------------------------------------  // acclient.c:749113
int _E1_39()
{
  return atexit(_E2_39);
}

//----- (0073B680) --------------------------------------------------------  // acclient.c:847624
void __cdecl _E193_38()
{
  char *v0; // esi@1

  v0 = &PHeader_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B6B0) --------------------------------------------------------  // acclient.c:847637
void __cdecl _E196_45()
{
  char *v0; // esi@1

  v0 = &VertexArray_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B6E0) --------------------------------------------------------  // acclient.c:847650
void __cdecl _E199_37()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B710) --------------------------------------------------------  // acclient.c:847663
void __cdecl _E202_38()
{
  char *v0; // esi@1

  v0 = &VertexType_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B740) --------------------------------------------------------  // acclient.c:847676
void __cdecl _E205_35()
{
  char *v0; // esi@1

  v0 = &VertexData_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B770) --------------------------------------------------------  // acclient.c:847689
void __cdecl _E208_39()
{
  char *v0; // esi@1

  v0 = &Vertex_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B7A0) --------------------------------------------------------  // acclient.c:847702
void __cdecl _E211_35()
{
  char *v0; // esi@1

  v0 = &Index_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B7D0) --------------------------------------------------------  // acclient.c:847715
void __cdecl _E214_38()
{
  char *v0; // esi@1

  v0 = &Origin_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B800) --------------------------------------------------------  // acclient.c:847728
void __cdecl _E217_34()
{
  char *v0; // esi@1

  v0 = &Normal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B830) --------------------------------------------------------  // acclient.c:847741
void __cdecl _E220_34()
{
  char *v0; // esi@1

  v0 = &Diffuse_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B860) --------------------------------------------------------  // acclient.c:847754
void __cdecl _E223_34()
{
  char *v0; // esi@1

  v0 = &Specular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B890) --------------------------------------------------------  // acclient.c:847767
void __cdecl _E226_20()
{
  char *v0; // esi@1

  v0 = &UVS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B8C0) --------------------------------------------------------  // acclient.c:847780
void __cdecl _E229_20()
{
  char *v0; // esi@1

  v0 = &VectorS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B8F0) --------------------------------------------------------  // acclient.c:847793
void __cdecl _E232_20()
{
  char *v0; // esi@1

  v0 = &VectorT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B920) --------------------------------------------------------  // acclient.c:847806
void __cdecl _E235_20()
{
  char *v0; // esi@1

  v0 = &VectorSxT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B950) --------------------------------------------------------  // acclient.c:847819
void __cdecl _E238_18()
{
  char *v0; // esi@1

  v0 = &Weights_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B980) --------------------------------------------------------  // acclient.c:847832
void __cdecl _E241_18()
{
  char *v0; // esi@1

  v0 = &Importance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B9B0) --------------------------------------------------------  // acclient.c:847845
void __cdecl _E244_18()
{
  char *v0; // esi@1

  v0 = &PhysMtl_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B9E0) --------------------------------------------------------  // acclient.c:847858
void __cdecl _E247_17()
{
  char *v0; // esi@1

  v0 = &Material_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BA10) --------------------------------------------------------  // acclient.c:847871
void __cdecl _E250_17()
{
  char *v0; // esi@1

  v0 = &ID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BA40) --------------------------------------------------------  // acclient.c:847884
void __cdecl _E253_17()
{
  char *v0; // esi@1

  v0 = &FileName_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BA70) --------------------------------------------------------  // acclient.c:847897
void __cdecl _E256_17()
{
  char *v0; // esi@1

  v0 = &Polygon_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BAA0) --------------------------------------------------------  // acclient.c:847910
void __cdecl _E259_18()
{
  char *v0; // esi@1

  v0 = &ID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BAD0) --------------------------------------------------------  // acclient.c:847923
void __cdecl _E262_18()
{
  char *v0; // esi@1

  v0 = &Indices_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BB00) --------------------------------------------------------  // acclient.c:847936
void __cdecl _E265_18()
{
  char *v0; // esi@1

  v0 = &MaterialID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BB30) --------------------------------------------------------  // acclient.c:847949
void __cdecl _E268_17()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BB60) --------------------------------------------------------  // acclient.c:847962
void __cdecl _E271_16()
{
  char *v0; // esi@1

  v0 = &Markings_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BB90) --------------------------------------------------------  // acclient.c:847975
void __cdecl _E274_16()
{
  char *v0; // esi@1

  v0 = &Material_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BBC0) --------------------------------------------------------  // acclient.c:847988
void __cdecl _E277_16()
{
  char *v0; // esi@1

  v0 = &Index_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BBF0) --------------------------------------------------------  // acclient.c:848001
void __cdecl _E280_15()
{
  char *v0; // esi@1

  v0 = &Filename_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BC20) --------------------------------------------------------  // acclient.c:848014
void __cdecl _E283_15()
{
  char *v0; // esi@1

  v0 = &Surface_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BC50) --------------------------------------------------------  // acclient.c:848027
void __cdecl _E286_14()
{
  char *v0; // esi@1

  v0 = &CellPoly_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BC80) --------------------------------------------------------  // acclient.c:848040
void __cdecl _E289_13()
{
  char *v0; // esi@1

  v0 = &Sphere_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BCB0) --------------------------------------------------------  // acclient.c:848053
void __cdecl _E292_14()
{
  char *v0; // esi@1

  v0 = &Side_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BCE0) --------------------------------------------------------  // acclient.c:848066
void __cdecl _E295_13()
{
  char *v0; // esi@1

  v0 = &Positive_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BD10) --------------------------------------------------------  // acclient.c:848079
void __cdecl _E298_14()
{
  char *v0; // esi@1

  v0 = &Negative_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BD40) --------------------------------------------------------  // acclient.c:848092
void __cdecl _E301_12()
{
  char *v0; // esi@1

  v0 = &Polygon_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BD70) --------------------------------------------------------  // acclient.c:848105
void __cdecl _E304_13()
{
  char *v0; // esi@1

  v0 = &OtherCell_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BDA0) --------------------------------------------------------  // acclient.c:848118
void __cdecl _E307_12()
{
  char *v0; // esi@1

  v0 = &CellPortal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BDD0) --------------------------------------------------------  // acclient.c:848131
void __cdecl _E310_13()
{
  char *v0; // esi@1

  v0 = &Portal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BE00) --------------------------------------------------------  // acclient.c:848144
void __cdecl _E313_12()
{
  char *v0; // esi@1

  v0 = &OtherCell_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BE30) --------------------------------------------------------  // acclient.c:848157
void __cdecl _E316_13()
{
  char *v0; // esi@1

  v0 = &OtherPortal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BE60) --------------------------------------------------------  // acclient.c:848170
void __cdecl _E319_12()
{
  char *v0; // esi@1

  v0 = &ExactMatch_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BE90) --------------------------------------------------------  // acclient.c:848183
void __cdecl _E322_12()
{
  char *v0; // esi@1

  v0 = &StabList_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BEC0) --------------------------------------------------------  // acclient.c:848196
void __cdecl _E325_11()
{
  char *v0; // esi@1

  v0 = &Period_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BEF0) --------------------------------------------------------  // acclient.c:848209
void __cdecl _E328_12()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BF20) --------------------------------------------------------  // acclient.c:848222
void __cdecl _E331_11()
{
  char *v0; // esi@1

  v0 = &Transform_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BF50) --------------------------------------------------------  // acclient.c:848235
void __cdecl _E334_11()
{
  char *v0; // esi@1

  v0 = &Scale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BF80) --------------------------------------------------------  // acclient.c:848248
void __cdecl _E337_11()
{
  char *v0; // esi@1

  v0 = &Weight_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BFB0) --------------------------------------------------------  // acclient.c:848261
void __cdecl _E340_11()
{
  char *v0; // esi@1

  v0 = &Offset_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073BFE0) --------------------------------------------------------  // acclient.c:848274
void __cdecl _E343_8()
{
  char *v0; // esi@1

  v0 = &Quaternion_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C010) --------------------------------------------------------  // acclient.c:848287
void __cdecl _E346_8()
{
  char *v0; // esi@1

  v0 = &Rotation_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C040) --------------------------------------------------------  // acclient.c:848300
void __cdecl _E349_8()
{
  char *v0; // esi@1

  v0 = &STime_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C070) --------------------------------------------------------  // acclient.c:848313
void __cdecl _E352_8()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C0A0) --------------------------------------------------------  // acclient.c:848326
void __cdecl _E355_8()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C0D0) --------------------------------------------------------  // acclient.c:848339
void __cdecl _E358_8()
{
  char *v0; // esi@1

  v0 = &LowPt_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C100) --------------------------------------------------------  // acclient.c:848352
void __cdecl _E361_8()
{
  char *v0; // esi@1

  v0 = &Radius_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C130) --------------------------------------------------------  // acclient.c:848365
void __cdecl _E364_8()
{
  char *v0; // esi@1

  v0 = &Height_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C160) --------------------------------------------------------  // acclient.c:848378
void __cdecl _E367_8()
{
  char *v0; // esi@1

  v0 = &Texture2D_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C190) --------------------------------------------------------  // acclient.c:848391
void __cdecl _E370_8()
{
  char *v0; // esi@1

  v0 = &Texture3D_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C1C0) --------------------------------------------------------  // acclient.c:848404
void __cdecl _E373_8()
{
  char *v0; // esi@1

  v0 = &TextureCube_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C1F0) --------------------------------------------------------  // acclient.c:848417
void __cdecl _E376_8()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C220) --------------------------------------------------------  // acclient.c:848430
void __cdecl _E379_8()
{
  char *v0; // esi@1

  v0 = &MovieFileName_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C250) --------------------------------------------------------  // acclient.c:848443
void __cdecl _E382_8()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C280) --------------------------------------------------------  // acclient.c:848456
void __cdecl _E385_8()
{
  char *v0; // esi@1

  v0 = &Levels_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C2B0) --------------------------------------------------------  // acclient.c:848469
void __cdecl _E388_8()
{
  char *v0; // esi@1

  v0 = &NodeName_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C2E0) --------------------------------------------------------  // acclient.c:848482
void __cdecl _E391_8()
{
  char *v0; // esi@1

  v0 = &Material_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C310) --------------------------------------------------------  // acclient.c:848495
void __cdecl _E394_8()
{
  char *v0; // esi@1

  v0 = &MaterialType_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C340) --------------------------------------------------------  // acclient.c:848508
void __cdecl _E397_8()
{
  char *v0; // esi@1

  v0 = &Modifier_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C370) --------------------------------------------------------  // acclient.c:848521
void __cdecl _E400_8()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C3A0) --------------------------------------------------------  // acclient.c:848534
void __cdecl _E403_8()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C3D0) --------------------------------------------------------  // acclient.c:848547
void __cdecl _E406_8()
{
  char *v0; // esi@1

  v0 = &NodeName_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C400) --------------------------------------------------------  // acclient.c:848560
void __cdecl _E409_8()
{
  char *v0; // esi@1

  v0 = &SortMode_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C430) --------------------------------------------------------  // acclient.c:848573
void __cdecl _E412_8()
{
  char *v0; // esi@1

  v0 = &SortMode_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C460) --------------------------------------------------------  // acclient.c:848586
void __cdecl _E415_8()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C490) --------------------------------------------------------  // acclient.c:848599
void __cdecl _E418_8()
{
  char *v0; // esi@1

  v0 = &NodeName_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C4C0) --------------------------------------------------------  // acclient.c:848612
void __cdecl _E421_8()
{
  char *v0; // esi@1

  v0 = &NodeName_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C4F0) --------------------------------------------------------  // acclient.c:848625
void __cdecl _E424_8()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C520) --------------------------------------------------------  // acclient.c:848638
void __cdecl _E427_8()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C550) --------------------------------------------------------  // acclient.c:848651
void __cdecl _E430_8()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C580) --------------------------------------------------------  // acclient.c:848664
void __cdecl _E433_8()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C5B0) --------------------------------------------------------  // acclient.c:848677
void __cdecl _E436_8()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C5E0) --------------------------------------------------------  // acclient.c:848690
void __cdecl _E439_8()
{
  char *v0; // esi@1

  v0 = &NodeName_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C610) --------------------------------------------------------  // acclient.c:848703
void __cdecl _E442_8()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C640) --------------------------------------------------------  // acclient.c:848716
void __cdecl _E445_8()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C670) --------------------------------------------------------  // acclient.c:848729
void __cdecl _E448_8()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C6A0) --------------------------------------------------------  // acclient.c:848742
void __cdecl _E451_8()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C6D0) --------------------------------------------------------  // acclient.c:848755
void __cdecl _E454_8()
{
  char *v0; // esi@1

  v0 = &TrueFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C700) --------------------------------------------------------  // acclient.c:848768
void __cdecl _E457_8()
{
  char *v0; // esi@1

  v0 = &FalseFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C730) --------------------------------------------------------  // acclient.c:848781
void __cdecl _E460_8()
{
  char *v0; // esi@1

  v0 = &RenderPass_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C760) --------------------------------------------------------  // acclient.c:848794
void __cdecl _E463_8()
{
  char *v0; // esi@1

  v0 = &Blend_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C790) --------------------------------------------------------  // acclient.c:848807
void __cdecl _E466_8()
{
  char *v0; // esi@1

  v0 = &DepthTest_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C7C0) --------------------------------------------------------  // acclient.c:848820
void __cdecl _E469_8()
{
  char *v0; // esi@1

  v0 = &DepthWrite_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C7F0) --------------------------------------------------------  // acclient.c:848833
void __cdecl _E472_8()
{
  char *v0; // esi@1

  v0 = &CullMode_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C820) --------------------------------------------------------  // acclient.c:848846
void __cdecl _E475_8()
{
  char *v0; // esi@1

  v0 = &DepthFog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C850) --------------------------------------------------------  // acclient.c:848859
void __cdecl _E478_8()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C880) --------------------------------------------------------  // acclient.c:848872
void __cdecl _E481_8()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C8B0) --------------------------------------------------------  // acclient.c:848885
void __cdecl _E484_8()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C8E0) --------------------------------------------------------  // acclient.c:848898
void __cdecl _E487_8()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C910) --------------------------------------------------------  // acclient.c:848911
void __cdecl _E490_8()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C940) --------------------------------------------------------  // acclient.c:848924
void __cdecl _E493_8()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C970) --------------------------------------------------------  // acclient.c:848937
void __cdecl _E496_8()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C9A0) --------------------------------------------------------  // acclient.c:848950
void __cdecl _E499_8()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073C9D0) --------------------------------------------------------  // acclient.c:848963
void __cdecl _E502_8()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CA00) --------------------------------------------------------  // acclient.c:848976
void __cdecl _E505_8()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CA30) --------------------------------------------------------  // acclient.c:848989
void __cdecl _E508_8()
{
  char *v0; // esi@1

  v0 = &Ambient_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CA60) --------------------------------------------------------  // acclient.c:849002
void __cdecl _E511_8()
{
  char *v0; // esi@1

  v0 = &Diffuse_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CA90) --------------------------------------------------------  // acclient.c:849015
void __cdecl _E514_8()
{
  char *v0; // esi@1

  v0 = &Specular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CAC0) --------------------------------------------------------  // acclient.c:849028
void __cdecl _E517_8()
{
  char *v0; // esi@1

  v0 = &SpecularPower_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CAF0) --------------------------------------------------------  // acclient.c:849041
void __cdecl _E520_8()
{
  char *v0; // esi@1

  v0 = &Dye_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CB20) --------------------------------------------------------  // acclient.c:849054
void __cdecl _E523_8()
{
  char *v0; // esi@1

  v0 = &Emissive_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CB50) --------------------------------------------------------  // acclient.c:849067
void __cdecl _E526_8()
{
  char *v0; // esi@1

  v0 = &VertexFormat_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CB80) --------------------------------------------------------  // acclient.c:849080
void __cdecl _E529_8()
{
  char *v0; // esi@1

  v0 = &VertexShader_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CBB0) --------------------------------------------------------  // acclient.c:849093
void __cdecl _E532_8()
{
  char *v0; // esi@1

  v0 = &PixelShader_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CBE0) --------------------------------------------------------  // acclient.c:849106
void __cdecl _E535_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CC10) --------------------------------------------------------  // acclient.c:849119
void __cdecl _E538_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CC40) --------------------------------------------------------  // acclient.c:849132
void __cdecl _E541_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CC70) --------------------------------------------------------  // acclient.c:849145
void __cdecl _E544_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CCA0) --------------------------------------------------------  // acclient.c:849158
void __cdecl _E547_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CCD0) --------------------------------------------------------  // acclient.c:849171
void __cdecl _E550_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CD00) --------------------------------------------------------  // acclient.c:849184
void __cdecl _E553_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CD30) --------------------------------------------------------  // acclient.c:849197
void __cdecl _E556_8()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CD60) --------------------------------------------------------  // acclient.c:849210
void __cdecl _E559_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CD90) --------------------------------------------------------  // acclient.c:849223
void __cdecl _E562_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CDC0) --------------------------------------------------------  // acclient.c:849236
void __cdecl _E565_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CDF0) --------------------------------------------------------  // acclient.c:849249
void __cdecl _E568_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CE20) --------------------------------------------------------  // acclient.c:849262
void __cdecl _E571_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CE50) --------------------------------------------------------  // acclient.c:849275
void __cdecl _E574_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CE80) --------------------------------------------------------  // acclient.c:849288
void __cdecl _E577_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CEB0) --------------------------------------------------------  // acclient.c:849301
void __cdecl _E580_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CEE0) --------------------------------------------------------  // acclient.c:849314
void __cdecl _E583_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CF10) --------------------------------------------------------  // acclient.c:849327
void __cdecl _E586_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CF40) --------------------------------------------------------  // acclient.c:849340
void __cdecl _E589_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CF70) --------------------------------------------------------  // acclient.c:849353
void __cdecl _E592_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CFA0) --------------------------------------------------------  // acclient.c:849366
void __cdecl _E595_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073CFD0) --------------------------------------------------------  // acclient.c:849379
void __cdecl _E598_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D000) --------------------------------------------------------  // acclient.c:849392
void __cdecl _E601_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D030) --------------------------------------------------------  // acclient.c:849405
void __cdecl _E604_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D060) --------------------------------------------------------  // acclient.c:849418
void __cdecl _E607_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D090) --------------------------------------------------------  // acclient.c:849431
void __cdecl _E610_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D0C0) --------------------------------------------------------  // acclient.c:849444
void __cdecl _E613_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D0F0) --------------------------------------------------------  // acclient.c:849457
void __cdecl _E616_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D120) --------------------------------------------------------  // acclient.c:849470
void __cdecl _E619_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D150) --------------------------------------------------------  // acclient.c:849483
void __cdecl _E622_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D180) --------------------------------------------------------  // acclient.c:849496
void __cdecl _E625_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D1B0) --------------------------------------------------------  // acclient.c:849509
void __cdecl _E628_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D1E0) --------------------------------------------------------  // acclient.c:849522
void __cdecl _E631_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D210) --------------------------------------------------------  // acclient.c:849535
void __cdecl _E634_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D240) --------------------------------------------------------  // acclient.c:849548
void __cdecl _E637_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D270) --------------------------------------------------------  // acclient.c:849561
void __cdecl _E640_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D2A0) --------------------------------------------------------  // acclient.c:849574
void __cdecl _E643_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D2D0) --------------------------------------------------------  // acclient.c:849587
void __cdecl _E646_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D300) --------------------------------------------------------  // acclient.c:849600
void __cdecl _E649_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D330) --------------------------------------------------------  // acclient.c:849613
void __cdecl _E652_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D360) --------------------------------------------------------  // acclient.c:849626
void __cdecl _E655_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D390) --------------------------------------------------------  // acclient.c:849639
void __cdecl _E658_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D3C0) --------------------------------------------------------  // acclient.c:849652
void __cdecl _E661_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D3F0) --------------------------------------------------------  // acclient.c:849665
void __cdecl _E664_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D420) --------------------------------------------------------  // acclient.c:849678
void __cdecl _E667_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D450) --------------------------------------------------------  // acclient.c:849691
void __cdecl _E670_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D480) --------------------------------------------------------  // acclient.c:849704
void __cdecl _E673_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D4B0) --------------------------------------------------------  // acclient.c:849717
void __cdecl _E676_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D4E0) --------------------------------------------------------  // acclient.c:849730
void __cdecl _E679_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D510) --------------------------------------------------------  // acclient.c:849743
void __cdecl _E682_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D540) --------------------------------------------------------  // acclient.c:849756
void __cdecl _E685_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D570) --------------------------------------------------------  // acclient.c:849769
void __cdecl _E688_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D5A0) --------------------------------------------------------  // acclient.c:849782
void __cdecl _E691_8()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D5D0) --------------------------------------------------------  // acclient.c:849795
void __cdecl _E694_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D600) --------------------------------------------------------  // acclient.c:849808
void __cdecl _E697_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D630) --------------------------------------------------------  // acclient.c:849821
void __cdecl _E700_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D660) --------------------------------------------------------  // acclient.c:849834
void __cdecl _E703_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D690) --------------------------------------------------------  // acclient.c:849847
void __cdecl _E706_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D6C0) --------------------------------------------------------  // acclient.c:849860
void __cdecl _E709_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D6F0) --------------------------------------------------------  // acclient.c:849873
void __cdecl _E712_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D720) --------------------------------------------------------  // acclient.c:849886
void __cdecl _E715_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D750) --------------------------------------------------------  // acclient.c:849899
void __cdecl _E718_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D780) --------------------------------------------------------  // acclient.c:849912
void __cdecl _E721_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D7B0) --------------------------------------------------------  // acclient.c:849925
void __cdecl _E724_8()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D7E0) --------------------------------------------------------  // acclient.c:849938
void __cdecl _E727_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D810) --------------------------------------------------------  // acclient.c:849951
void __cdecl _E730_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D840) --------------------------------------------------------  // acclient.c:849964
void __cdecl _E733_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D870) --------------------------------------------------------  // acclient.c:849977
void __cdecl _E736_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D8A0) --------------------------------------------------------  // acclient.c:849990
void __cdecl _E739_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D8D0) --------------------------------------------------------  // acclient.c:850003
void __cdecl _E742_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D900) --------------------------------------------------------  // acclient.c:850016
void __cdecl _E745_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D930) --------------------------------------------------------  // acclient.c:850029
void __cdecl _E748_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D960) --------------------------------------------------------  // acclient.c:850042
void __cdecl _E751_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D990) --------------------------------------------------------  // acclient.c:850055
void __cdecl _E754_8()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D9C0) --------------------------------------------------------  // acclient.c:850068
void __cdecl _E757_8()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073D9F0) --------------------------------------------------------  // acclient.c:850081
void __cdecl _E760_8()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DA20) --------------------------------------------------------  // acclient.c:850094
void __cdecl _E763_8()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DA50) --------------------------------------------------------  // acclient.c:850107
void __cdecl _E766_8()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DA80) --------------------------------------------------------  // acclient.c:850120
void __cdecl _E769_8()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DAB0) --------------------------------------------------------  // acclient.c:850133
void __cdecl _E772_8()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DAE0) --------------------------------------------------------  // acclient.c:850146
void __cdecl _E775_8()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DB10) --------------------------------------------------------  // acclient.c:850159
void __cdecl _E778_8()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DB40) --------------------------------------------------------  // acclient.c:850172
void __cdecl _E781_8()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DB70) --------------------------------------------------------  // acclient.c:850185
void __cdecl _E784_8()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DBA0) --------------------------------------------------------  // acclient.c:850198
void __cdecl _E787_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DBD0) --------------------------------------------------------  // acclient.c:850211
void __cdecl _E790_8()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DC00) --------------------------------------------------------  // acclient.c:850224
void __cdecl _E793_8()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DC30) --------------------------------------------------------  // acclient.c:850237
void __cdecl _E796_8()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DC60) --------------------------------------------------------  // acclient.c:850250
void __cdecl _E799_8()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DC90) --------------------------------------------------------  // acclient.c:850263
void __cdecl _E802_8()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DCC0) --------------------------------------------------------  // acclient.c:850276
void __cdecl _E805_8()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DCF0) --------------------------------------------------------  // acclient.c:850289
void __cdecl _E808_8()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DD20) --------------------------------------------------------  // acclient.c:850302
void __cdecl _E811_8()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DD50) --------------------------------------------------------  // acclient.c:850315
void __cdecl _E814_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DD80) --------------------------------------------------------  // acclient.c:850328
void __cdecl _E817_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DDB0) --------------------------------------------------------  // acclient.c:850341
void __cdecl _E820_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DDE0) --------------------------------------------------------  // acclient.c:850354
void __cdecl _E823_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DE10) --------------------------------------------------------  // acclient.c:850367
void __cdecl _E826_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DE40) --------------------------------------------------------  // acclient.c:850380
void __cdecl _E829_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DE70) --------------------------------------------------------  // acclient.c:850393
void __cdecl _E832_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DEA0) --------------------------------------------------------  // acclient.c:850406
void __cdecl _E835_8()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DED0) --------------------------------------------------------  // acclient.c:850419
void __cdecl _E838_8()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DF00) --------------------------------------------------------  // acclient.c:850432
void __cdecl _E841_8()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DF30) --------------------------------------------------------  // acclient.c:850445
void __cdecl _E844_8()
{
  char *v0; // esi@1

  v0 = &NodeName_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DF60) --------------------------------------------------------  // acclient.c:850458
void __cdecl _E847_8()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DF90) --------------------------------------------------------  // acclient.c:850471
void __cdecl _E850_8()
{
  char *v0; // esi@1

  v0 = &SamplerName_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DFC0) --------------------------------------------------------  // acclient.c:850484
void __cdecl _E853_8()
{
  char *v0; // esi@1

  v0 = &Texture_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073DFF0) --------------------------------------------------------  // acclient.c:850497
void __cdecl _E856_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E020) --------------------------------------------------------  // acclient.c:850510
void __cdecl _E859_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E050) --------------------------------------------------------  // acclient.c:850523
void __cdecl _E862_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E080) --------------------------------------------------------  // acclient.c:850536
void __cdecl _E865_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E0B0) --------------------------------------------------------  // acclient.c:850549
void __cdecl _E868_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E0E0) --------------------------------------------------------  // acclient.c:850562
void __cdecl _E871_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E110) --------------------------------------------------------  // acclient.c:850575
void __cdecl _E874_8()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E140) --------------------------------------------------------  // acclient.c:850588
void __cdecl _E877_8()
{
  char *v0; // esi@1

  v0 = &AddressMode_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E170) --------------------------------------------------------  // acclient.c:850601
void __cdecl _E880_8()
{
  char *v0; // esi@1

  v0 = &TexFilter_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E1A0) --------------------------------------------------------  // acclient.c:850614
void __cdecl _E883_8()
{
  char *v0; // esi@1

  v0 = &ColorOp_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E1D0) --------------------------------------------------------  // acclient.c:850627
void __cdecl _E886_8()
{
  char *v0; // esi@1

  v0 = &ColorArg1_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E200) --------------------------------------------------------  // acclient.c:850640
void __cdecl _E889_8()
{
  char *v0; // esi@1

  v0 = &ColorArg2_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E230) --------------------------------------------------------  // acclient.c:850653
void __cdecl _E892_8()
{
  char *v0; // esi@1

  v0 = &AlphaOp_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E260) --------------------------------------------------------  // acclient.c:850666
void __cdecl _E895_8()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E290) --------------------------------------------------------  // acclient.c:850679
void __cdecl _E898_8()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E2C0) --------------------------------------------------------  // acclient.c:850692
void __cdecl _E901_8()
{
  char *v0; // esi@1

  v0 = &TexCoord_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E2F0) --------------------------------------------------------  // acclient.c:850705
void __cdecl _E904_8()
{
  char *v0; // esi@1

  v0 = &UseProjection_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E320) --------------------------------------------------------  // acclient.c:850718
void __cdecl _E907_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E350) --------------------------------------------------------  // acclient.c:850731
void __cdecl _E910_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E380) --------------------------------------------------------  // acclient.c:850744
void __cdecl _E913_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E3B0) --------------------------------------------------------  // acclient.c:850757
void __cdecl _E916_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E3E0) --------------------------------------------------------  // acclient.c:850770
void __cdecl _E919_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E410) --------------------------------------------------------  // acclient.c:850783
void __cdecl _E922_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E440) --------------------------------------------------------  // acclient.c:850796
void __cdecl _E925_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E470) --------------------------------------------------------  // acclient.c:850809
void __cdecl _E928_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E4A0) --------------------------------------------------------  // acclient.c:850822
void __cdecl _E931_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E4D0) --------------------------------------------------------  // acclient.c:850835
void __cdecl _E934_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E500) --------------------------------------------------------  // acclient.c:850848
void __cdecl _E937_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E530) --------------------------------------------------------  // acclient.c:850861
void __cdecl _E940_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E560) --------------------------------------------------------  // acclient.c:850874
void __cdecl _E943_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E590) --------------------------------------------------------  // acclient.c:850887
void __cdecl _E946_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E5C0) --------------------------------------------------------  // acclient.c:850900
void __cdecl _E949_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E5F0) --------------------------------------------------------  // acclient.c:850913
void __cdecl _E952_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E620) --------------------------------------------------------  // acclient.c:850926
void __cdecl _E955_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E650) --------------------------------------------------------  // acclient.c:850939
void __cdecl _E958_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E680) --------------------------------------------------------  // acclient.c:850952
void __cdecl _E961_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E6B0) --------------------------------------------------------  // acclient.c:850965
void __cdecl _E964_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E6E0) --------------------------------------------------------  // acclient.c:850978
void __cdecl _E967_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E710) --------------------------------------------------------  // acclient.c:850991
void __cdecl _E970_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E740) --------------------------------------------------------  // acclient.c:851004
void __cdecl _E973_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E770) --------------------------------------------------------  // acclient.c:851017
void __cdecl _E976_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E7A0) --------------------------------------------------------  // acclient.c:851030
void __cdecl _E979_8()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E7D0) --------------------------------------------------------  // acclient.c:851043
void __cdecl _E982_8()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E800) --------------------------------------------------------  // acclient.c:851056
void __cdecl _E985_8()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E830) --------------------------------------------------------  // acclient.c:851069
void __cdecl _E988_8()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E860) --------------------------------------------------------  // acclient.c:851082
void __cdecl _E991_8()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E890) --------------------------------------------------------  // acclient.c:851095
void __cdecl _E994_8()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E8C0) --------------------------------------------------------  // acclient.c:851108
void __cdecl _E997_8()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E8F0) --------------------------------------------------------  // acclient.c:851121
void __cdecl _E1000_8()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E920) --------------------------------------------------------  // acclient.c:851134
void __cdecl _E1003_8()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E950) --------------------------------------------------------  // acclient.c:851147
void __cdecl _E1006_8()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E980) --------------------------------------------------------  // acclient.c:851160
void __cdecl _E1009_8()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E9B0) --------------------------------------------------------  // acclient.c:851173
void __cdecl _E1012_8()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073E9E0) --------------------------------------------------------  // acclient.c:851186
void __cdecl _E1015_8()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EA10) --------------------------------------------------------  // acclient.c:851199
void __cdecl _E1018_8()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EA40) --------------------------------------------------------  // acclient.c:851212
void __cdecl _E1021_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EA70) --------------------------------------------------------  // acclient.c:851225
void __cdecl _E1024_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EAA0) --------------------------------------------------------  // acclient.c:851238
void __cdecl _E1027_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EAD0) --------------------------------------------------------  // acclient.c:851251
void __cdecl _E1030_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EB00) --------------------------------------------------------  // acclient.c:851264
void __cdecl _E1033_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EB30) --------------------------------------------------------  // acclient.c:851277
void __cdecl _E1036_8()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EB60) --------------------------------------------------------  // acclient.c:851290
void __cdecl _E1039_8()
{
  char *v0; // esi@1

  v0 = &NodeName_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EB90) --------------------------------------------------------  // acclient.c:851303
void __cdecl _E1042_8()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EBC0) --------------------------------------------------------  // acclient.c:851316
void __cdecl _E1045_8()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EBF0) --------------------------------------------------------  // acclient.c:851329
void __cdecl _E1048_8()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EC20) --------------------------------------------------------  // acclient.c:851342
void __cdecl _E1051_8()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EC50) --------------------------------------------------------  // acclient.c:851355
void __cdecl _E1054_8()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EC80) --------------------------------------------------------  // acclient.c:851368
void __cdecl _E1057_8()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ECB0) --------------------------------------------------------  // acclient.c:851381
void __cdecl _E1060_8()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ECE0) --------------------------------------------------------  // acclient.c:851394
void __cdecl _E1063_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ED10) --------------------------------------------------------  // acclient.c:851407
void __cdecl _E1066_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ED40) --------------------------------------------------------  // acclient.c:851420
void __cdecl _E1069_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ED70) --------------------------------------------------------  // acclient.c:851433
void __cdecl _E1072_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EDA0) --------------------------------------------------------  // acclient.c:851446
void __cdecl _E1075_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EDD0) --------------------------------------------------------  // acclient.c:851459
void __cdecl _E1078_8()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EE00) --------------------------------------------------------  // acclient.c:851472
void __cdecl _E1081_8()
{
  char *v0; // esi@1

  v0 = &NodeName_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EE30) --------------------------------------------------------  // acclient.c:851485
void __cdecl _E1084_8()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EE60) --------------------------------------------------------  // acclient.c:851498
void __cdecl _E1087_8()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EE90) --------------------------------------------------------  // acclient.c:851511
void __cdecl _E1090_8()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EEC0) --------------------------------------------------------  // acclient.c:851524
void __cdecl _E1093_8()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EEF0) --------------------------------------------------------  // acclient.c:851537
void __cdecl _E1096_8()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EF20) --------------------------------------------------------  // acclient.c:851550
void __cdecl _E1099_8()
{
  char *v0; // esi@1

  v0 = &ScaleType_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EF50) --------------------------------------------------------  // acclient.c:851563
void __cdecl _E1102_8()
{
  char *v0; // esi@1

  v0 = &WorldSpace_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EF80) --------------------------------------------------------  // acclient.c:851576
void __cdecl _E1105_8()
{
  char *v0; // esi@1

  v0 = &ForceDraw_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EFB0) --------------------------------------------------------  // acclient.c:851589
void __cdecl _E1108_8()
{
  char *v0; // esi@1

  v0 = &NumEmitters_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073EFE0) --------------------------------------------------------  // acclient.c:851602
void __cdecl _E1111_8()
{
  char *v0; // esi@1

  v0 = &Material_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F010) --------------------------------------------------------  // acclient.c:851615
void __cdecl _E1114_8()
{
  char *v0; // esi@1

  v0 = &Version_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F040) --------------------------------------------------------  // acclient.c:851628
void __cdecl _E1117_8()
{
  char *v0; // esi@1

  v0 = &MaxParticles_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F070) --------------------------------------------------------  // acclient.c:851641
void __cdecl _E1120_8()
{
  char *v0; // esi@1

  v0 = &NodeName_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F0A0) --------------------------------------------------------  // acclient.c:851654
void __cdecl _E1123_8()
{
  char *v0; // esi@1

  v0 = &Origin_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F0D0) --------------------------------------------------------  // acclient.c:851667
void __cdecl _E1126_8()
{
  char *v0; // esi@1

  v0 = &Shape_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F100) --------------------------------------------------------  // acclient.c:851680
void __cdecl _E1129_8()
{
  char *v0; // esi@1

  v0 = &Shape_Point_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F130) --------------------------------------------------------  // acclient.c:851693
void __cdecl _E1132_8()
{
  char *v0; // esi@1

  v0 = &Shape_Line_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F160) --------------------------------------------------------  // acclient.c:851706
void __cdecl _E1135_8()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F190) --------------------------------------------------------  // acclient.c:851719
void __cdecl _E1138_8()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F1C0) --------------------------------------------------------  // acclient.c:851732
void __cdecl _E1141_8()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F1F0) --------------------------------------------------------  // acclient.c:851745
void __cdecl _E1144_8()
{
  char *v0; // esi@1

  v0 = &ParticleShape_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F220) --------------------------------------------------------  // acclient.c:851758
void __cdecl _E1147_8()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F250) --------------------------------------------------------  // acclient.c:851771
void __cdecl _E1150_8()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F280) --------------------------------------------------------  // acclient.c:851784
void __cdecl _E1153_8()
{
  char *v0; // esi@1

  v0 = &Streak_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F2B0) --------------------------------------------------------  // acclient.c:851797
void __cdecl _E1156_8()
{
  char *v0; // esi@1

  v0 = &Rotation_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F2E0) --------------------------------------------------------  // acclient.c:851810
void __cdecl _E1159_8()
{
  char *v0; // esi@1

  v0 = &WorldRotation_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F310) --------------------------------------------------------  // acclient.c:851823
void __cdecl _E1162_8()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F340) --------------------------------------------------------  // acclient.c:851836
void __cdecl _E1165_8()
{
  char *v0; // esi@1

  v0 = &ParticleScale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F370) --------------------------------------------------------  // acclient.c:851849
void __cdecl _E1168_8()
{
  char *v0; // esi@1

  v0 = &Scale_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F3A0) --------------------------------------------------------  // acclient.c:851862
void __cdecl _E1171_8()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F3D0) --------------------------------------------------------  // acclient.c:851875
void __cdecl _E1174_8()
{
  char *v0; // esi@1

  v0 = &BirthRate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F400) --------------------------------------------------------  // acclient.c:851888
void __cdecl _E1177_8()
{
  char *v0; // esi@1

  v0 = &Lifespan_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F430) --------------------------------------------------------  // acclient.c:851901
void __cdecl _E1180_8()
{
  char *v0; // esi@1

  v0 = &Velocity_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F460) --------------------------------------------------------  // acclient.c:851914
void __cdecl _E1183_8()
{
  char *v0; // esi@1

  v0 = &Direction_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F490) --------------------------------------------------------  // acclient.c:851927
void __cdecl _E1186_8()
{
  char *v0; // esi@1

  v0 = &MinSpread_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F4C0) --------------------------------------------------------  // acclient.c:851940
void __cdecl _E1189_8()
{
  char *v0; // esi@1

  v0 = &MaxSpread_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F4F0) --------------------------------------------------------  // acclient.c:851953
void __cdecl _E1192_8()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F520) --------------------------------------------------------  // acclient.c:851966
void __cdecl _E1195_8()
{
  char *v0; // esi@1

  v0 = &BlastCount_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F550) --------------------------------------------------------  // acclient.c:851979
void __cdecl _E1198_8()
{
  char *v0; // esi@1

  v0 = &StartTime_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F580) --------------------------------------------------------  // acclient.c:851992
void __cdecl _E1201_8()
{
  char *v0; // esi@1

  v0 = &TimeLimit_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F5B0) --------------------------------------------------------  // acclient.c:852005
void __cdecl _E1204_8()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F5E0) --------------------------------------------------------  // acclient.c:852018
void __cdecl _E1207_8()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F610) --------------------------------------------------------  // acclient.c:852031
void __cdecl _E1210_8()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F640) --------------------------------------------------------  // acclient.c:852044
void __cdecl _E1213_8()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F670) --------------------------------------------------------  // acclient.c:852057
void __cdecl _E1216_8()
{
  char *v0; // esi@1

  v0 = &IsActive_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F6A0) --------------------------------------------------------  // acclient.c:852070
void __cdecl _E1219_8()
{
  char *v0; // esi@1

  v0 = &FadeIn_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F6D0) --------------------------------------------------------  // acclient.c:852083
void __cdecl _E1222_8()
{
  char *v0; // esi@1

  v0 = &FadeOut_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F700) --------------------------------------------------------  // acclient.c:852096
void __cdecl _E1225_8()
{
  char *v0; // esi@1

  v0 = &ConstrainX_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F730) --------------------------------------------------------  // acclient.c:852109
void __cdecl _E1228_8()
{
  char *v0; // esi@1

  v0 = &ConstrainY_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F760) --------------------------------------------------------  // acclient.c:852122
void __cdecl _E1231_8()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F790) --------------------------------------------------------  // acclient.c:852135
void __cdecl _E1234_8()
{
  char *v0; // esi@1

  v0 = &NodeName_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F7C0) --------------------------------------------------------  // acclient.c:852148
void __cdecl _E1237_8()
{
  char *v0; // esi@1

  v0 = &Time_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F7F0) --------------------------------------------------------  // acclient.c:852161
void __cdecl _E1240_8()
{
  char *v0; // esi@1

  v0 = &Flags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F820) --------------------------------------------------------  // acclient.c:852174
void __cdecl _E1243_8()
{
  char *v0; // esi@1

  v0 = &Flags_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F850) --------------------------------------------------------  // acclient.c:852187
void __cdecl _E1246_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F880) --------------------------------------------------------  // acclient.c:852200
void __cdecl _E1249_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F8B0) --------------------------------------------------------  // acclient.c:852213
void __cdecl _E1252_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F8E0) --------------------------------------------------------  // acclient.c:852226
void __cdecl _E1255_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F910) --------------------------------------------------------  // acclient.c:852239
void __cdecl _E1258_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F940) --------------------------------------------------------  // acclient.c:852252
void __cdecl _E1261_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F970) --------------------------------------------------------  // acclient.c:852265
void __cdecl _E1264_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F9A0) --------------------------------------------------------  // acclient.c:852278
void __cdecl _E1267_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073F9D0) --------------------------------------------------------  // acclient.c:852291
void __cdecl _E1270_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FA00) --------------------------------------------------------  // acclient.c:852304
void __cdecl _E1273_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FA30) --------------------------------------------------------  // acclient.c:852317
void __cdecl _E1276_7()
{
  char *v0; // esi@1

  v0 = &Scale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FA60) --------------------------------------------------------  // acclient.c:852330
void __cdecl _E1279_6()
{
  char *v0; // esi@1

  v0 = &ScaleX_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FA90) --------------------------------------------------------  // acclient.c:852343
void __cdecl _E1282_7()
{
  char *v0; // esi@1

  v0 = &ScaleY_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FAC0) --------------------------------------------------------  // acclient.c:852356
void __cdecl _E1285_6()
{
  char *v0; // esi@1

  v0 = &Color_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FAF0) --------------------------------------------------------  // acclient.c:852369
void __cdecl _E1288_6()
{
  char *v0; // esi@1

  v0 = &Mass_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FB20) --------------------------------------------------------  // acclient.c:852382
void __cdecl _E1291_5()
{
  char *v0; // esi@1

  v0 = &PFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FB50) --------------------------------------------------------  // acclient.c:852395
void __cdecl _E1294_6()
{
  char *v0; // esi@1

  v0 = &PFlags_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FB80) --------------------------------------------------------  // acclient.c:852408
void __cdecl _E1297_5()
{
  char *v0; // esi@1

  v0 = &PCType_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FBB0) --------------------------------------------------------  // acclient.c:852421
void __cdecl _E1300_5()
{
  char *v0; // esi@1

  v0 = &PCType_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FBE0) --------------------------------------------------------  // acclient.c:852434
void __cdecl _E1303_4()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FC10) --------------------------------------------------------  // acclient.c:852447
void __cdecl _E1306_3()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FC40) --------------------------------------------------------  // acclient.c:852460
void __cdecl _E1309_3()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FC70) --------------------------------------------------------  // acclient.c:852473
void __cdecl _E1312_3()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FCA0) --------------------------------------------------------  // acclient.c:852486
void __cdecl _E1315_1()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FCD0) --------------------------------------------------------  // acclient.c:852499
void __cdecl _E1318_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FD00) --------------------------------------------------------  // acclient.c:852512
void __cdecl _E1321_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FD30) --------------------------------------------------------  // acclient.c:852525
void __cdecl _E1324_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FD60) --------------------------------------------------------  // acclient.c:852538
void __cdecl _E1327_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FD90) --------------------------------------------------------  // acclient.c:852551
void __cdecl _E1330_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FDC0) --------------------------------------------------------  // acclient.c:852564
void __cdecl _E1333_1()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FDF0) --------------------------------------------------------  // acclient.c:852577
void __cdecl _E1336_1()
{
  char *v0; // esi@1

  v0 = &Position_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FE20) --------------------------------------------------------  // acclient.c:852590
void __cdecl _E1339_1()
{
  char *v0; // esi@1

  v0 = &PointList_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FE50) --------------------------------------------------------  // acclient.c:852603
void __cdecl _E1342_1()
{
  char *v0; // esi@1

  v0 = &Point_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FE80) --------------------------------------------------------  // acclient.c:852616
void __cdecl _E1345_1()
{
  char *v0; // esi@1

  v0 = &DetailLevels_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FEB0) --------------------------------------------------------  // acclient.c:852629
void __cdecl _E1348_1()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FEE0) --------------------------------------------------------  // acclient.c:852642
void __cdecl _E1351_1()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FF10) --------------------------------------------------------  // acclient.c:852655
void __cdecl _E1354_1()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FF40) --------------------------------------------------------  // acclient.c:852668
void __cdecl _E1357_1()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FF70) --------------------------------------------------------  // acclient.c:852681
void __cdecl _E1360_1()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FFA0) --------------------------------------------------------  // acclient.c:852694
void __cdecl _E1363_1()
{
  char *v0; // esi@1

  v0 = &Point_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073FFD0) --------------------------------------------------------  // acclient.c:852707
void __cdecl _E1366_1()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740000) --------------------------------------------------------  // acclient.c:852720
void __cdecl _E1369_1()
{
  char *v0; // esi@1

  v0 = &PointTexture_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740030) --------------------------------------------------------  // acclient.c:852733
void __cdecl _E1372_1()
{
  char *v0; // esi@1

  v0 = &PointSize_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740060) --------------------------------------------------------  // acclient.c:852746
void __cdecl _E1375_1()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740090) --------------------------------------------------------  // acclient.c:852759
void __cdecl _E1378_1()
{
  PStringBase<unsigned short> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<unsigned short> *v2; // esi@2
  int v3; // esi@2

  v0 = &PROJECTSETTING_2;
  v1 = 4;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007400D0) --------------------------------------------------------  // acclient.c:852784
void __cdecl _E1381_0()
{
  char *v0; // esi@1

  v0 = (char *)&PROJECTSETTING_2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTSETTING_2.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740100) --------------------------------------------------------  // acclient.c:852797
void __cdecl _E1384_0()
{
  char *v0; // esi@1

  v0 = &NAME_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NAME_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740130) --------------------------------------------------------  // acclient.c:852810
void __cdecl _E1387_0()
{
  char *v0; // esi@1

  v0 = &VALUE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VALUE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740160) --------------------------------------------------------  // acclient.c:852823
void __cdecl _E1390_0()
{
  char *v0; // esi@1

  v0 = &BRANCH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740190) --------------------------------------------------------  // acclient.c:852836
void __cdecl _E1393_0()
{
  char *v0; // esi@1

  v0 = &BRANCHBASEDIR_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCHBASEDIR_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007401C0) --------------------------------------------------------  // acclient.c:852849
void __cdecl _E1396_0()
{
  char *v0; // esi@1

  v0 = &PROJECTNAME_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTNAME_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007401F0) --------------------------------------------------------  // acclient.c:852862
void __cdecl _E1399_0()
{
  char *v0; // esi@1

  v0 = &LONGNAME_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LONGNAME_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740220) --------------------------------------------------------  // acclient.c:852875
void __cdecl _E1402_0()
{
  char *v0; // esi@1

  v0 = &ENUMDB_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ENUMDB_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740250) --------------------------------------------------------  // acclient.c:852888
void __cdecl _E1405_0()
{
  char *v0; // esi@1

  v0 = &DIDNAME_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DIDNAME_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740280) --------------------------------------------------------  // acclient.c:852901
void __cdecl _E1408_0()
{
  char *v0; // esi@1

  v0 = &RCS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RCS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007402B0) --------------------------------------------------------  // acclient.c:852914
void __cdecl _E1411_0()
{
  char *v0; // esi@1

  v0 = &PREPROC_KEYS_BASE_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PREPROC_KEYS_BASE_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007402E0) --------------------------------------------------------  // acclient.c:852927
void __cdecl _E1414_0()
{
  char *v0; // esi@1

  v0 = &CURRENT_PROJECT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CURRENT_PROJECT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740310) --------------------------------------------------------  // acclient.c:852940
void __cdecl _E1417_0()
{
  char *v0; // esi@1

  v0 = &DATA_GAME_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_GAME_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740340) --------------------------------------------------------  // acclient.c:852953
void __cdecl _E1420_0()
{
  char *v0; // esi@1

  v0 = &DATA_ENGINE_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_ENGINE_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740370) --------------------------------------------------------  // acclient.c:852966
void __cdecl _E1423_0()
{
  char *v0; // esi@1

  v0 = &SOURCE_GAME_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_GAME_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007403A0) --------------------------------------------------------  // acclient.c:852979
void __cdecl _E1426_0()
{
  char *v0; // esi@1

  v0 = &SOURCE_ENGINE_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_ENGINE_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007403D0) --------------------------------------------------------  // acclient.c:852992
void __cdecl _E1429_0()
{
  char *v0; // esi@1

  v0 = &TOOLS_BIN_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_BIN_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740400) --------------------------------------------------------  // acclient.c:853005
void __cdecl _E1432_0()
{
  char *v0; // esi@1

  v0 = &CONFIG_TOOLS_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CONFIG_TOOLS_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740430) --------------------------------------------------------  // acclient.c:853018
void __cdecl _E1435_0()
{
  char *v0; // esi@1

  v0 = &OUTPUT_INI_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OUTPUT_INI_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740460) --------------------------------------------------------  // acclient.c:853031
void __cdecl _E1438_0()
{
  char *v0; // esi@1

  v0 = &DATA_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740490) --------------------------------------------------------  // acclient.c:853044
void __cdecl _E1441_0()
{
  char *v0; // esi@1

  v0 = &DOC_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DOC_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007404C0) --------------------------------------------------------  // acclient.c:853057
void __cdecl _E1444_0()
{
  char *v0; // esi@1

  v0 = &EXPORT_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EXPORT_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007404F0) --------------------------------------------------------  // acclient.c:853070
void __cdecl _E1447_0()
{
  char *v0; // esi@1

  v0 = &SDK_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SDK_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740520) --------------------------------------------------------  // acclient.c:853083
void __cdecl _E1450_0()
{
  char *v0; // esi@1

  v0 = &SOURCE_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740550) --------------------------------------------------------  // acclient.c:853096
void __cdecl _E1453_0()
{
  char *v0; // esi@1

  v0 = &TOOLS_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740580) --------------------------------------------------------  // acclient.c:853109
void __cdecl _E1456_0()
{
  char *v0; // esi@1

  v0 = &PORTAL_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PORTAL_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007405B0) --------------------------------------------------------  // acclient.c:853122
void __cdecl _E1459_0()
{
  char *v0; // esi@1

  v0 = &AC_PATH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AC_PATH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007405E0) --------------------------------------------------------  // acclient.c:853135
void __cdecl _E92_22()
{
  char *v0; // esi@1

  v0 = &waveform_None_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740610) --------------------------------------------------------  // acclient.c:853148
void __cdecl sub_740610()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740640) --------------------------------------------------------  // acclient.c:853161
void __cdecl _E98_37()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740670) --------------------------------------------------------  // acclient.c:853174
void __cdecl _E101_62()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007406A0) --------------------------------------------------------  // acclient.c:853187
void __cdecl _E104_32()
{
  char *v0; // esi@1

  v0 = &waveform_Square_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007406D0) --------------------------------------------------------  // acclient.c:853200
void __cdecl _E107_64()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740700) --------------------------------------------------------  // acclient.c:853213
void __cdecl sub_740700()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740730) --------------------------------------------------------  // acclient.c:853226
void __cdecl _E113_43()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740760) --------------------------------------------------------  // acclient.c:853239
void __cdecl _E116_35()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740790) --------------------------------------------------------  // acclient.c:853252
void __cdecl _E127_88()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007407C0) --------------------------------------------------------  // acclient.c:853265
void __cdecl _E130_80()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007407F0) --------------------------------------------------------  // acclient.c:853278
void __cdecl _E133_73()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740820) --------------------------------------------------------  // acclient.c:853291
void __cdecl _E136_57()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740850) --------------------------------------------------------  // acclient.c:853304
void __cdecl _E139_58()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740880) --------------------------------------------------------  // acclient.c:853317
void __cdecl _E142_55()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007408B0) --------------------------------------------------------  // acclient.c:853330
void __cdecl _E145_57()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007408E0) --------------------------------------------------------  // acclient.c:853343
void __cdecl _E148_56()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740910) --------------------------------------------------------  // acclient.c:853356
void __cdecl _E151_54()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740940) --------------------------------------------------------  // acclient.c:853369
void __cdecl _E154_55()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740970) --------------------------------------------------------  // acclient.c:853382
void __cdecl _E157_52()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007409A0) --------------------------------------------------------  // acclient.c:853395
void __cdecl _E160_55()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007409D0) --------------------------------------------------------  // acclient.c:853408
void __cdecl _E163_48()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740A00) --------------------------------------------------------  // acclient.c:853421
void __cdecl _E166_50()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740A30) --------------------------------------------------------  // acclient.c:853434
void __cdecl _E169_49()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740A60) --------------------------------------------------------  // acclient.c:853447
void __cdecl _E172_47()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740A90) --------------------------------------------------------  // acclient.c:853460
void __cdecl _E175_44()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_9;
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

//----- (00740AD0) --------------------------------------------------------  // acclient.c:853485
void __cdecl _E178_44()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_9;
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

//----- (00740B10) --------------------------------------------------------  // acclient.c:853510
void __cdecl _E181_44()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_9;
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

//----- (00740B50) --------------------------------------------------------  // acclient.c:853535
void __cdecl _E184_42()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_9;
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

//----- (00740B90) --------------------------------------------------------  // acclient.c:853560
void __cdecl _E187_41()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_9;
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

//----- (00740BD0) --------------------------------------------------------  // acclient.c:853585
void __cdecl _E190_42()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &PHeader_2;
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

