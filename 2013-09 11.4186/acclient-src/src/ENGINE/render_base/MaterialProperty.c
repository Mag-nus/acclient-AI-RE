/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MaterialProperty
   Object     : ENGINE\render_base\MaterialProperty.obj
   Functions  : 876
   Addresses  : 0044F890 - 00751F70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044F890) --------------------------------------------------------  // acclient.c:140908
void __thiscall LM_UVTranslate::SetUTranslate(LM_UVScale *this, Waveform *_uScale)
{
  this->uScale = *_uScale;
}

//----- (0044F8E0) --------------------------------------------------------  // acclient.c:140914
void __thiscall LM_UVTranslate::SetVTranslate(LM_UVScale *this, Waveform *_vScale)
{
  this->vScale = *_vScale;
}

//----- (0044F930) --------------------------------------------------------  // acclient.c:140920
void __thiscall MaterialLayer::SetAlphaTestRef(MaterialLayer *this, Waveform *_w)
{
  this->m_AlphaTestRef = *_w;
}

//----- (0044F980) --------------------------------------------------------  // acclient.c:140926
void __thiscall MaterialLayer::SetSpecularPower(MaterialLayer *this, Waveform *_wWave)
{
  this->m_wSpecularPower = *_wWave;
}

//----- (0044F9F0) --------------------------------------------------------  // acclient.c:140932
char __thiscall MaterialProperty::ReleaseSubObjects(MaterialProperty *this)
{
  MaterialProperty *v1; // esi@1

  v1 = this;
  if ( DBCache::IsRunTime() )
    Render::SafelyStopUsingAndReleaseTexture(&v1->m_pCachedTexture);
  return 1;
}

//----- (0044FA10) --------------------------------------------------------  // acclient.c:140943
void __thiscall MaterialProperty::Begin(MaterialProperty *this)
{
  MaterialProperty *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10

  v1 = this;
  v2 = this->name.m_charbuffer;
  if ( this->name.m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v1->nameID = 0;
  v1->dataType = 0x7FFFFFFF;
  v1->dataLength = 0;
  v1->data = 0;
  v5 = v1->dataName.m_charbuffer;
  if ( v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->dataName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  v1->m_pCachedTexture = 0;
}

//----- (0044FAB0) --------------------------------------------------------  // acclient.c:140982
void __thiscall MaterialProperty::Apply(MaterialProperty *this, RenderMaterial *material, MaterialProperty *refProp)
{
  MaterialProperty *v3; // esi@1
  unsigned int v4; // ebp@2
  MaterialField *v5; // edx@3
  unsigned int v6; // ecx@3
  MaterialLayer *v7; // eax@3
  LayerStage *v8; // ebx@5
  unsigned int v9; // ecx@6
  LM_UVScale *v10; // ecx@8
  unsigned int v11; // edi@9
  void *v12; // ecx@12
  int v13; // eax@12
  int v14; // eax@13
  void *v15; // edx@16
  RMDataType v16; // eax@22

  v3 = this;
  if ( !this->m_IsShaderConstant )
  {
    v4 = 0;
    if ( refProp->fields.m_num )
    {
      do
      {
        v5 = refProp->fields.m_data[v4];
        v6 = v5->layerIndex;
        v7 = 0;
        if ( material->layers.m_num > v6 )
          v7 = material->layers.m_data[v6];
        v8 = 0;
        if ( v7 )
        {
          v9 = v5->tcIndex;
          if ( v7->m_Stages.m_num > v9 )
            v8 = v7->m_Stages.m_data[v9];
        }
        v10 = 0;
        if ( v7 )
        {
          v11 = v5->tcIndex;
          if ( v7->m_FFModifiers.m_num > v11 )
            v10 = (LM_UVScale *)v7->m_FFModifiers.m_data[v11];
        }
        switch ( v5->fieldType )
        {
          case 0:
            v12 = v3->data;
            v13 = (int)&v7->m_cDiffuse;
            *(_DWORD *)v13 = *(_DWORD *)v12;
            *(_DWORD *)(v13 + 4) = *((_DWORD *)v12 + 1);
            *(_DWORD *)(v13 + 8) = *((_DWORD *)v12 + 2);
            *(_DWORD *)(v13 + 12) = *((_DWORD *)v12 + 3);
            break;
          case 1:
            v14 = (int)&v7->m_cSpecular;
            goto LABEL_16;
          case 2:
            MaterialLayer::SetSpecularPower(v7, (Waveform *)v3->data);
            break;
          case 3:
            v14 = (int)&v7->m_cDye;
LABEL_16:
            v15 = v3->data;
            *(_DWORD *)v14 = *(_DWORD *)v15;
            *(_DWORD *)(v14 + 4) = *((_DWORD *)v15 + 1);
            *(_DWORD *)(v14 + 8) = *((_DWORD *)v15 + 2);
            *(_DWORD *)(v14 + 12) = *((_DWORD *)v15 + 3);
            break;
          case 4:
            v7->m_CullMode = (*(_DWORD *)v3->data == 0) + 1;
            break;
          case 5:
            v7->m_DepthTest = 4 * (*(_DWORD *)v3->data == 0) + 4;
            break;
          case 6:
            v7->m_DepthWrite = *(_DWORD *)v3->data != 0;
            break;
          case 7:
            v7->m_AlphaTest = *(_DWORD *)v3->data != 0;
            break;
          case 8:
            MaterialLayer::SetAlphaTestRef(v7, (Waveform *)v3->data);
            break;
          case 9:
            v16 = v3->dataType;
            if ( v16 == 3000 )
            {
              LayerStage::SetTexture(v8, &v3->dataName, *(IDClass<_tagDataID,32,0> *)v3->data);
            }
            else if ( v16 == 10000 )
            {
              LayerStage::SetTexture(v8, *(RenderTexture **)v3->data);
            }
            break;
          case 0xA:
            v8->m_AddressModeU = 2 * (*(_DWORD *)v3->data == 0) + 1;
            break;
          case 0xB:
            v8->m_AddressModeV = 2 * (*(_DWORD *)v3->data == 0) + 1;
            break;
          case 0x20:
            LM_UVTranslate::SetUTranslate(v10, (Waveform *)v3->data);
            break;
          case 0x21:
            LM_UVTranslate::SetVTranslate(v10, (Waveform *)v3->data);
            break;
          case 0x22:
            LM_UVTranslate::SetUTranslate(v10, (Waveform *)v3->data);
            break;
          case 0x23:
            LM_UVTranslate::SetUTranslate(v10, (Waveform *)v3->data);
            break;
          case 0x24:
            LM_UVTranslate::SetVTranslate(v10, (Waveform *)v3->data);
            break;
          default:
            break;
        }
        ++v4;
      }
      while ( v4 < refProp->fields.m_num );
    }
  }
}

//----- (0044FD10) --------------------------------------------------------  // acclient.c:141109
char __thiscall MaterialProperty::GetSubObjects(MaterialProperty *this)
{
  MaterialProperty *v1; // esi@1
  IDClass<_tagDataID,32,0> v2; // eax@3
  QualifiedDataID *v3; // eax@4
  int v4; // eax@4
  DiskSpace *v5; // ecx@4
  QualifiedDataID v7; // [sp+8h] [bp-8h]@4

  v1 = this;
  if ( !DBCache::IsRunTime() )
    return 1;
  if ( v1->dataType != 3000 )
    return 1;
  v2.id = *(_DWORD *)v1->data;
  if ( v2.id == INVALID_DID_45.id )
    return 1;
  QualifiedDataID::QualifiedDataID(&v7, v2, 0x1Eu);
  v4 = DBObj::Get(v3);
  v1->m_pCachedTexture = (RenderTexture *)v4;
  if ( v4 )
  {
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v5);
    return 1;
  }
  return 0;
}

//----- (0044FD70) --------------------------------------------------------  // acclient.c:141138
void __thiscall MaterialProperty::MaterialProperty(MaterialProperty *this)
{
  MaterialProperty *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->dataName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->fields.m_data = 0;
  v1->fields.m_sizeAndDeallocate = 0;
  v1->fields.m_num = 0;
  MaterialProperty::Begin(v1);
}

//----- (0044FDC0) --------------------------------------------------------  // acclient.c:141158
void __thiscall MaterialProperty::End(MaterialProperty *this)
{
  MaterialProperty *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@3
  int v3; // edi@4
  volatile LONG *v4; // ST00_4@7
  unsigned int v5; // eax@8
  unsigned int v6; // edi@8
  unsigned int v7; // eax@10
  unsigned int v8; // ecx@10
  int i; // eax@13

  v1 = this;
  if ( DBCache::IsRunTime() )
    Render::SafelyStopUsingAndReleaseTexture(&v1->m_pCachedTexture);
  v2 = v1->name.m_charbuffer;
  if ( v1->name.m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  operator delete[](v1->data);
  v5 = v1->fields.m_num;
  v6 = 0;
  v1->data = 0;
  v1->dataLength = 0;
  if ( v5 > 0 )
  {
    do
    {
      operator delete(v1->fields.m_data[v6]);
      v1->fields.m_data[v6++] = 0;
    }
    while ( v6 < v1->fields.m_num );
  }
  v7 = v1->fields.m_sizeAndDeallocate;
  v8 = v1->fields.m_sizeAndDeallocate & 0x80000000;
  v1->fields.m_num = 0;
  if ( v8 == 0x80000000 )
  {
    operator delete[](v1->fields.m_data);
    v1->fields.m_data = 0;
    v1->fields.m_sizeAndDeallocate = 0;
  }
  else if ( v1->fields.m_data )
  {
    for ( i = (v7 & 0x7FFFFFFF) - 1; i >= 0; v1->fields.m_data[i + 1] = 0 )
      --i;
  }
}

//----- (0044FEA0) --------------------------------------------------------  // acclient.c:141214
void __thiscall MaterialProperty::GetSubDataIDs(MaterialProperty *this, QualifiedDataIDArray *id_array)
{
  IDClass<_tagDataID,32,0> v2; // eax@2
  QualifiedDataID *v3; // eax@3
  QualifiedDataID v4; // [sp+0h] [bp-8h]@3

  if ( this->dataType == 3000 )
  {
    v2.id = *(_DWORD *)this->data;
    if ( v2.id != INVALID_DID_45.id )
    {
      QualifiedDataID::QualifiedDataID(&v4, v2, 0);
      QualifiedDataIDArray::AddQDID(id_array, v3, 0);
    }
  }
}

//----- (0044FEE0) --------------------------------------------------------  // acclient.c:141232
void __thiscall MaterialProperty::~MaterialProperty(MaterialProperty *this)
{
  MaterialProperty *v1; // edi@1
  int v2; // esi@3
  int v3; // esi@6

  v1 = this;
  MaterialProperty::End(this);
  if ( (v1->fields.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->fields.m_data);
  v2 = (int)&v1->dataName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (0044FF50) --------------------------------------------------------  // acclient.c:141254
char __thiscall MaterialProperty::CopyInto(MaterialProperty *this, MaterialProperty *target)
{
  MaterialProperty *v2; // ebp@1
  PSRefBufferCharData<char> *v3; // eax@1
  MaterialProperty *v4; // ebx@1
  int v5; // esi@2
  PSRefBufferCharData<char> *v6; // eax@5
  void *v7; // eax@8
  PSRefBufferCharData<char> *v8; // esi@10
  int v9; // esi@11
  PSRefBufferCharData<char> *v10; // eax@14
  unsigned int v11; // eax@15
  void *v12; // edi@16
  MaterialField *v13; // eax@17
  int v14; // eax@17
  unsigned int v15; // eax@18
  unsigned int v16; // ecx@20
  RenderTexture *v17; // ebx@21
  DiskSpace *v18; // ecx@22
  RenderTexture *v19; // ST04_4@22

  v2 = target;
  v3 = target->name.m_charbuffer;
  v4 = this;
  if ( target->name.m_charbuffer != this->name.m_charbuffer )
  {
    v5 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = v4->name.m_charbuffer;
    v2->name.m_charbuffer = v4->name.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
  }
  v2->nameID = v4->nameID;
  v2->dataType = v4->dataType;
  v2->dataLength = v4->dataLength;
  if ( v4->data )
  {
    if ( !v4->dataLength )
      return 0;
    v7 = operator new[](v4->dataLength);
    v2->data = v7;
    if ( !v7 )
      return 0;
    qmemcpy(v7, v4->data, v4->dataLength);
  }
  v8 = v2->dataName.m_charbuffer;
  if ( v8 != v4->dataName.m_charbuffer )
  {
    v9 = (int)&v8[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = v4->dataName.m_charbuffer;
    v2->dataName.m_charbuffer = v10;
    InterlockedIncrement((volatile LONG *)&v10[-1]);
  }
  v2->m_IsShaderConstant = v4->m_IsShaderConstant;
  v11 = v4->fields.m_num;
  target = 0;
  if ( v11 )
  {
    do
    {
      v12 = operator new(0x10u);
      if ( !v12 )
        return 0;
      v13 = v4->fields.m_data[(_DWORD)target];
      *(_DWORD *)v12 = v13->fieldType;
      *((_DWORD *)v12 + 1) = v13->dataType;
      *((_DWORD *)v12 + 2) = v13->layerIndex;
      *((_DWORD *)v12 + 3) = v13->tcIndex;
      v14 = v2->fields.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v2->fields.m_num < v14
        || (v15 = SmartArray<UIChildFramework *,1>::get_new_size(v14 + 1),
            SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v2->fields, v15)) )
        v2->fields.m_data[v2->fields.m_num++] = (MaterialField *)v12;
      v16 = v4->fields.m_num;
      target = (MaterialProperty *)((char *)target + 1);
    }
    while ( (unsigned int)target < v16 );
  }
  v17 = v4->m_pCachedTexture;
  if ( v17 )
  {
    target = (MaterialProperty *)v2->m_pCachedTexture;
    v2->m_pCachedTexture = v17;
    v17->vfptr->AddRef((Interface *)v17);
    v19 = v2->m_pCachedTexture;
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v18);
    Render::SafelyStopUsingAndReleaseTexture((RenderTexture **)&target);
  }
  return 1;
}

//----- (004500E0) --------------------------------------------------------  // acclient.c:141349
void __thiscall MaterialProperty::Serialize(MaterialProperty *this, Archive *io_archive)
{
  Archive *v2; // ebp@1
  MaterialProperty *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned __int16 v5; // si@5
  unsigned int v6; // eax@5
  unsigned int v7; // eax@11
  unsigned int v8; // esi@17
  const void *v9; // edi@17
  unsigned int v10; // eax@17
  unsigned int v11; // ecx@18
  char v12; // dl@19
  unsigned int v13; // ecx@19
  int v14; // edi@19
  int v15; // esi@19
  char v16; // cl@19
  const void *v17; // esi@20
  char v18; // al@20
  unsigned int v19; // ecx@20
  unsigned int v20; // esi@22
  unsigned int v21; // eax@22
  void *v22; // edi@28
  unsigned __int16 v23; // si@30
  unsigned int v24; // eax@30
  unsigned __int16 v25; // si@36
  unsigned int v26; // eax@36
  unsigned int v27; // eax@42
  unsigned int v28; // eax@46
  int v29; // eax@51
  unsigned int v30; // eax@52
  unsigned int numFields; // [sp+10h] [bp-4h]@22
  Archive *io_archivea; // [sp+18h] [bp+4h]@26

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3->nameID;
    else
      v3->nameID = *(_DWORD *)v4;
  }
  v5 = LOWORD(v3->dataType);
  Archive::CheckAlignment(io_archive, 2u);
  v6 = Archive::GetBytes(io_archive, 2u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_WORD *)v6 = v5;
    else
      v5 = *(_WORD *)v6;
  }
  if ( !(io_archive->m_flags & 5) )
    v3->dataType = v5;
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v7 = v3->dataLength;
    else
      v3->dataLength = *(_DWORD *)v7;
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    v3->data = operator new[](v3->dataLength);
  v8 = v3->dataLength;
  v9 = v3->data;
  v10 = Archive::GetBytes(io_archive, v3->dataLength);
  if ( v10 )
  {
    v11 = v8;
    if ( io_archive->m_flags & 1 )
    {
      v12 = v8;
      v13 = v8 >> 2;
      qmemcpy((void *)v10, v9, 4 * (v8 >> 2));
      v15 = (int)((char *)v9 + 4 * (v8 >> 2));
      v14 = v10 + 4 * v13;
      v16 = v12;
    }
    else
    {
      v17 = (const void *)v10;
      v18 = v11;
      v19 = v11 >> 2;
      qmemcpy((void *)v9, v17, 4 * v19);
      v15 = (int)((char *)v17 + 4 * v19);
      v14 = (int)((char *)v9 + 4 * v19);
      v16 = v18;
    }
    qmemcpy((void *)v14, (const void *)v15, v16 & 3);
  }
  v20 = v3->fields.m_num;
  numFields = v3->fields.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v21 = Archive::GetBytes(io_archive, 4u);
  if ( v21 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v21 = v20;
    }
    else
    {
      numFields = *(_DWORD *)v21;
      v20 = *(_DWORD *)v21;
    }
  }
  Serializer::SerializeObject(&v3->m_IsShaderConstant, io_archive);
  io_archivea = 0;
  if ( v20 )
  {
    do
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
        v22 = operator new(0x10u);
      else
        v22 = v3->fields.m_data[(_DWORD)io_archivea];
      v23 = *(_WORD *)v22;
      Archive::CheckAlignment(v2, 2u);
      v24 = Archive::GetBytes(v2, 2u);
      if ( v24 )
      {
        if ( v2->m_flags & 1 )
          *(_WORD *)v24 = v23;
        else
          v23 = *(_WORD *)v24;
      }
      if ( !(v2->m_flags & 5) )
        *(_DWORD *)v22 = v23;
      v25 = *((_WORD *)v22 + 2);
      Archive::CheckAlignment(v2, 2u);
      v26 = Archive::GetBytes(v2, 2u);
      if ( v26 )
      {
        if ( v2->m_flags & 1 )
          *(_WORD *)v26 = v25;
        else
          v25 = *(_WORD *)v26;
      }
      if ( !(v2->m_flags & 5) )
        *((_DWORD *)v22 + 1) = v25;
      Archive::CheckAlignment(v2, 4u);
      v27 = Archive::GetBytes(v2, 4u);
      if ( v27 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v27 = *((_DWORD *)v22 + 2);
        else
          *((_DWORD *)v22 + 2) = *(_DWORD *)v27;
      }
      Archive::CheckAlignment(v2, 4u);
      v28 = Archive::GetBytes(v2, 4u);
      if ( v28 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v28 = *((_DWORD *)v22 + 3);
        else
          *((_DWORD *)v22 + 3) = *(_DWORD *)v28;
      }
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v29 = v3->fields.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v3->fields.m_num < v29
          || (v30 = SmartArray<UIChildFramework *,1>::get_new_size(v29 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3->fields, v30)) )
          v3->fields.m_data[v3->fields.m_num++] = (MaterialField *)v22;
      }
      io_archivea = (Archive *)((char *)io_archivea + 1);
    }
    while ( (unsigned int)io_archivea < numFields );
  }
}

//----- (00450340) --------------------------------------------------------  // acclient.c:141527
unsigned int __thiscall MaterialProperty::Copy(MaterialProperty *this)
{
  MaterialProperty *v1; // ebx@1
  void *v2; // esi@1
  volatile LONG *v3; // ST00_4@2
  volatile LONG *v4; // ST00_4@2
  unsigned int result; // eax@2

  v1 = this;
  v2 = operator new(0x2Cu);
  if ( v2 )
  {
    v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *(_DWORD *)v2 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v3);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *((_DWORD *)v2 + 5) = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
    *((_DWORD *)v2 + 7) = 0;
    *((_DWORD *)v2 + 8) = 0;
    *((_DWORD *)v2 + 9) = 0;
    MaterialProperty::Begin((MaterialProperty *)v2);
    result = MaterialProperty::CopyInto(v1, (MaterialProperty *)v2) != 0 ? (unsigned int)v2 : 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006DF520) --------------------------------------------------------  // acclient.c:756554
int _E73_51()
{
  return atexit(_E74_39);
}

//----- (006DF530) --------------------------------------------------------  // acclient.c:756560
int _E76_25()
{
  return atexit(_E77_53);
}

//----- (006DF540) --------------------------------------------------------  // acclient.c:756566
int _E79_25()
{
  return atexit(_E80_27);
}

//----- (006DF550) --------------------------------------------------------  // acclient.c:756572
void _E82_16()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_25, PFID_A8R8G8B8);
}

//----- (006DF560) --------------------------------------------------------  // acclient.c:756578
void _E100_21()
{
  LODWORD(dword_83B508) = 1053364187;
}

//----- (006DF570) --------------------------------------------------------  // acclient.c:756584
void _E102_8()
{
  outside_val_17 = 1000.0 + 1.0;
}

//----- (006DF590) --------------------------------------------------------  // acclient.c:756590
void _E104_3()
{
  block_length_17 = 24.0 * 8.0;
}

//----- (006DF5B0) --------------------------------------------------------  // acclient.c:756596
void _E106_14()
{
  half_square_length_17 = 24.0 * 0.5;
}

//----- (006DF5D0) --------------------------------------------------------  // acclient.c:756602
int _E108_7()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_12, "Render.TextureFiltering");
  return atexit(sub_751970);
}

//----- (006DF5F0) --------------------------------------------------------  // acclient.c:756609
int _E111_5()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_12, "Render.LandscapeDetailTextures");
  return atexit(sub_7519A0);
}

//----- (006DF610) --------------------------------------------------------  // acclient.c:756616
int _E114_7()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_12, "Render.BuildingDetailTextures");
  return atexit(sub_7519D0);
}

//----- (006DF630) --------------------------------------------------------  // acclient.c:756623
int _E117_5()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_12, "Render.FieldOfView");
  return atexit(sub_751A00);
}

//----- (006DF650) --------------------------------------------------------  // acclient.c:756630
int _E120_8()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_12, "Render.LandscapeTextureDetail");
  return atexit(sub_751A30);
}

//----- (006DF670) --------------------------------------------------------  // acclient.c:756637
int _E123_5()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_12, "Render.EnvironmentTextureDetail");
  return atexit(sub_751A60);
}

//----- (006DF690) --------------------------------------------------------  // acclient.c:756644
int _E126_9()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_12, "Render.SceneryDrawDistance");
  return atexit(_E127_90);
}

//----- (006DF6B0) --------------------------------------------------------  // acclient.c:756651
int _E129_8()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_12, "Render.LandscapeDrawDistance");
  return atexit(_E130_82);
}

//----- (006DF6D0) --------------------------------------------------------  // acclient.c:756658
int _E132_9()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_12, "Render.ScreenBrightness");
  return atexit(_E133_75);
}

//----- (006DF6F0) --------------------------------------------------------  // acclient.c:756665
int _E135_8()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_12, "Render.AspectRatio");
  return atexit(_E136_59);
}

//----- (006DF710) --------------------------------------------------------  // acclient.c:756672
int _E138_9()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_12, "Render.DisplayAdapter");
  return atexit(_E139_60);
}

//----- (006DF730) --------------------------------------------------------  // acclient.c:756679
int _E141_9()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_12, "Render.MaxHardwareClass");
  return atexit(_E142_57);
}

//----- (006DF750) --------------------------------------------------------  // acclient.c:756686
int _E144_9()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_12, "Render.AutomaticDegrades");
  return atexit(_E145_59);
}

//----- (006DF770) --------------------------------------------------------  // acclient.c:756693
int _E147_9()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_12, "Render.GraphicsPerformance");
  return atexit(_E148_58);
}

//----- (006DF790) --------------------------------------------------------  // acclient.c:756700
int _E150_9()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_12, "Render.DegradeDistance");
  return atexit(_E151_56);
}

//----- (006DF7B0) --------------------------------------------------------  // acclient.c:756707
int _E153_9()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_12, "Render.MultiPassAlpha");
  return atexit(_E154_57);
}

//----- (006DF7D0) --------------------------------------------------------  // acclient.c:756714
int _E156_10()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_12, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83B55C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83B560, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83B564, "Anisotropic");
  return atexit(_E157_54);
}

//----- (006DF820) --------------------------------------------------------  // acclient.c:756724
int _E159_9()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_12, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83B56C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83B570, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83B574, "High");
  PStringBase<char>::PStringBase<char>(&stru_83B578, "VeryHigh");
  return atexit(_E160_57);
}

//----- (006DF880) --------------------------------------------------------  // acclient.c:756735
int _E162_10()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_12, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83B580, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83B584, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83B588, "High");
  PStringBase<char>::PStringBase<char>(&stru_83B58C, "VeryHigh");
  return atexit(_E163_50);
}

//----- (006DF8E0) --------------------------------------------------------  // acclient.c:756746
int _E165_9()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_12, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83B594, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83B598, "High");
  return atexit(_E166_52);
}

//----- (006DF920) --------------------------------------------------------  // acclient.c:756755
int _E168_10()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_12, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83B5A0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83B5A4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83B5A8, "High");
  PStringBase<char>::PStringBase<char>(&stru_83B5AC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83B5B0, "Extreme");
  return atexit(_E169_51);
}

//----- (006DF990) --------------------------------------------------------  // acclient.c:756767
int _E171_10()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_12, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83B5B8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83B5BC, "Wide");
  return atexit(_E172_49);
}

//----- (006DF9D0) --------------------------------------------------------  // acclient.c:756776
int _E174_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_22, "None");
  return atexit(_E175_46);
}

//----- (006DF9F0) --------------------------------------------------------  // acclient.c:756783
int _E177_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_22, "Speed");
  return atexit(_E178_46);
}

//----- (006DFA10) --------------------------------------------------------  // acclient.c:756790
int _E180_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_22, "Noise");
  return atexit(_E181_46);
}

//----- (006DFA30) --------------------------------------------------------  // acclient.c:756797
int _E183_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_22, "Sine");
  return atexit(_E184_44);
}

//----- (006DFA50) --------------------------------------------------------  // acclient.c:756804
int _E186_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_22, "Square");
  return atexit(_E187_43);
}

//----- (006DFA70) --------------------------------------------------------  // acclient.c:756811
int _E189_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_22, "Bounce");
  return atexit(_E190_44);
}

//----- (006DFA90) --------------------------------------------------------  // acclient.c:756818
int _E192_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_22, "Perlin");
  return atexit(_E193_39);
}

//----- (006DFAB0) --------------------------------------------------------  // acclient.c:756825
int _E195_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_22, "Fractal");
  return atexit(_E196_46);
}

//----- (006DFAD0) --------------------------------------------------------  // acclient.c:756832
int _E198_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_22, "FrameLoop");
  return atexit(_E199_38);
}

//----- (006DFAF0) --------------------------------------------------------  // acclient.c:756839
int _E201_4()
{
  PStringBase<char>::PStringBase<char>(&PHeader_7, "PREPROC_HEADER");
  return atexit(_E202_39);
}

//----- (006DFB10) --------------------------------------------------------  // acclient.c:756846
int _E204_3()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_5, "VertexArray");
  return atexit(_E205_36);
}

//----- (006DFB30) --------------------------------------------------------  // acclient.c:756853
int _E207_2()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_5, "BinaryVertexArray");
  return atexit(_E208_40);
}

//----- (006DFB50) --------------------------------------------------------  // acclient.c:756860
int _E210_3()
{
  PStringBase<char>::PStringBase<char>(&VertexType_6, "VertexType");
  return atexit(_E211_36);
}

//----- (006DFB70) --------------------------------------------------------  // acclient.c:756867
int _E213_4()
{
  PStringBase<char>::PStringBase<char>(&VertexData_5, "VertexData");
  return atexit(_E214_39);
}

//----- (006DFB90) --------------------------------------------------------  // acclient.c:756874
int _E216_4()
{
  PStringBase<char>::PStringBase<char>(&Vertex_5, "Vertex");
  return atexit(_E217_35);
}

//----- (006DFBB0) --------------------------------------------------------  // acclient.c:756881
int _E219_2()
{
  PStringBase<char>::PStringBase<char>(&Index_11, "Index");
  return atexit(_E220_35);
}

//----- (006DFBD0) --------------------------------------------------------  // acclient.c:756888
int _E222_2()
{
  PStringBase<char>::PStringBase<char>(&Origin_11, "P");
  return atexit(_E223_35);
}

//----- (006DFBF0) --------------------------------------------------------  // acclient.c:756895
int _E225_2()
{
  PStringBase<char>::PStringBase<char>(&Normal_5, "N");
  return atexit(_E226_21);
}

//----- (006DFC10) --------------------------------------------------------  // acclient.c:756902
int _E228_2()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_11, "Diffuse");
  return atexit(_E229_21);
}

//----- (006DFC30) --------------------------------------------------------  // acclient.c:756909
int _E231_2()
{
  PStringBase<char>::PStringBase<char>(&Specular_11, "Specular");
  return atexit(_E232_21);
}

//----- (006DFC50) --------------------------------------------------------  // acclient.c:756916
int _E234_2()
{
  PStringBase<char>::PStringBase<char>(&UVS_5, "UVS");
  return atexit(_E235_21);
}

//----- (006DFC70) --------------------------------------------------------  // acclient.c:756923
int _E237_2()
{
  PStringBase<char>::PStringBase<char>(&VectorS_5, "VectorS");
  return atexit(_E238_19);
}

//----- (006DFC90) --------------------------------------------------------  // acclient.c:756930
int _E240_2()
{
  PStringBase<char>::PStringBase<char>(&VectorT_5, "VectorT");
  return atexit(_E241_19);
}

//----- (006DFCB0) --------------------------------------------------------  // acclient.c:756937
int _E243_2()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_5, "VectorSxT");
  return atexit(_E244_19);
}

//----- (006DFCD0) --------------------------------------------------------  // acclient.c:756944
int _E246_2()
{
  PStringBase<char>::PStringBase<char>(&Weights_5, "Weights");
  return atexit(_E247_18);
}

//----- (006DFCF0) --------------------------------------------------------  // acclient.c:756951
int _E249_2()
{
  PStringBase<char>::PStringBase<char>(&Importance_5, "Importance");
  return atexit(_E250_18);
}

//----- (006DFD10) --------------------------------------------------------  // acclient.c:756958
int _E252_2()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_5, "PhysMtl");
  return atexit(_E253_18);
}

//----- (006DFD30) --------------------------------------------------------  // acclient.c:756965
int _E255_2()
{
  PStringBase<char>::PStringBase<char>(&Material_26, "Material");
  return atexit(_E256_18);
}

//----- (006DFD50) --------------------------------------------------------  // acclient.c:756972
int _E258_2()
{
  PStringBase<char>::PStringBase<char>(&ID_14, "ID");
  return atexit(_E259_19);
}

//----- (006DFD70) --------------------------------------------------------  // acclient.c:756979
int _E261_2()
{
  PStringBase<char>::PStringBase<char>(&FileName_5, "FileName");
  return atexit(_E262_19);
}

//----- (006DFD90) --------------------------------------------------------  // acclient.c:756986
int _E264_2()
{
  PStringBase<char>::PStringBase<char>(&Polygon_11, "Polygon");
  return atexit(_E265_19);
}

//----- (006DFDB0) --------------------------------------------------------  // acclient.c:756993
int _E267_2()
{
  PStringBase<char>::PStringBase<char>(&ID_15, "ID");
  return atexit(_E268_18);
}

//----- (006DFDD0) --------------------------------------------------------  // acclient.c:757000
int _E270_2()
{
  PStringBase<char>::PStringBase<char>(&Indices_11, "INDICES");
  return atexit(_E271_17);
}

//----- (006DFDF0) --------------------------------------------------------  // acclient.c:757007
int _E273_2()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_5, "MaterialID");
  return atexit(_E274_17);
}

//----- (006DFE10) --------------------------------------------------------  // acclient.c:757014
int _E276_2()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_5, "PhysMaterialID");
  return atexit(_E277_17);
}

//----- (006DFE30) --------------------------------------------------------  // acclient.c:757021
int _E279_2()
{
  PStringBase<char>::PStringBase<char>(&Markings_5, "Markings");
  return atexit(_E280_16);
}

//----- (006DFE50) --------------------------------------------------------  // acclient.c:757028
int _E282_2()
{
  PStringBase<char>::PStringBase<char>(&Material_27, "Material");
  return atexit(_E283_16);
}

//----- (006DFE70) --------------------------------------------------------  // acclient.c:757035
int _E285_2()
{
  PStringBase<char>::PStringBase<char>(&Index_12, "Index");
  return atexit(_E286_15);
}

//----- (006DFE90) --------------------------------------------------------  // acclient.c:757042
int _E288_2()
{
  PStringBase<char>::PStringBase<char>(&Filename_5, "Filename");
  return atexit(_E289_14);
}

//----- (006DFEB0) --------------------------------------------------------  // acclient.c:757049
int _E291_2()
{
  PStringBase<char>::PStringBase<char>(&Surface_5, "Surface");
  return atexit(_E292_15);
}

//----- (006DFED0) --------------------------------------------------------  // acclient.c:757056
int _E294_2()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_5, "CellPoly");
  return atexit(_E295_14);
}

//----- (006DFEF0) --------------------------------------------------------  // acclient.c:757063
int _E297_2()
{
  PStringBase<char>::PStringBase<char>(&Sphere_8, "Sphere");
  return atexit(_E298_15);
}

//----- (006DFF10) --------------------------------------------------------  // acclient.c:757070
int _E300_2()
{
  PStringBase<char>::PStringBase<char>(&Side_5, "Side");
  return atexit(_E301_13);
}

//----- (006DFF30) --------------------------------------------------------  // acclient.c:757077
int _E303_2()
{
  PStringBase<char>::PStringBase<char>(&Positive_5, "Positive");
  return atexit(_E304_14);
}

//----- (006DFF50) --------------------------------------------------------  // acclient.c:757084
int _E306_2()
{
  PStringBase<char>::PStringBase<char>(&Negative_5, "Negative");
  return atexit(_E307_13);
}

//----- (006DFF70) --------------------------------------------------------  // acclient.c:757091
int _E309_2()
{
  PStringBase<char>::PStringBase<char>(&Polygon_12, "PolygonIndex");
  return atexit(_E310_14);
}

//----- (006DFF90) --------------------------------------------------------  // acclient.c:757098
int _E312_2()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_11, "OtherCellMeshIndex");
  return atexit(_E313_13);
}

//----- (006DFFB0) --------------------------------------------------------  // acclient.c:757105
int _E315_2()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_5, "CellPortal");
  return atexit(_E316_14);
}

//----- (006DFFD0) --------------------------------------------------------  // acclient.c:757112
int _E318_2()
{
  PStringBase<char>::PStringBase<char>(&Portal_8, "PortalIndex");
  return atexit(_E319_13);
}

//----- (006DFFF0) --------------------------------------------------------  // acclient.c:757119
int _E321_2()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_12, "OtherCellID");
  return atexit(_E322_13);
}

//----- (006E0010) --------------------------------------------------------  // acclient.c:757126
int _E324_2()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_5, "OtherPortalIndex");
  return atexit(_E325_12);
}

//----- (006E0030) --------------------------------------------------------  // acclient.c:757133
int _E327_2()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_5, "ExactMatch");
  return atexit(_E328_13);
}

//----- (006E0050) --------------------------------------------------------  // acclient.c:757140
int _E330_2()
{
  PStringBase<char>::PStringBase<char>(&StabList_5, "StabList");
  return atexit(_E331_12);
}

//----- (006E0070) --------------------------------------------------------  // acclient.c:757147
int _E333_2()
{
  PStringBase<char>::PStringBase<char>(&Period_5, "Period");
  return atexit(_E334_12);
}

//----- (006E0090) --------------------------------------------------------  // acclient.c:757154
int _E336_2()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_5, "GrannyAnimation");
  return atexit(_E337_12);
}

//----- (006E00B0) --------------------------------------------------------  // acclient.c:757161
int _E339_2()
{
  PStringBase<char>::PStringBase<char>(&Transform_5, "Transform");
  return atexit(_E340_12);
}

//----- (006E00D0) --------------------------------------------------------  // acclient.c:757168
int _E342_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_17, "Scale");
  return atexit(_E343_9);
}

//----- (006E00F0) --------------------------------------------------------  // acclient.c:757175
int _E345_2()
{
  PStringBase<char>::PStringBase<char>(&Weight_5, "Weight");
  return atexit(_E346_9);
}

//----- (006E0110) --------------------------------------------------------  // acclient.c:757182
int _E348_2()
{
  PStringBase<char>::PStringBase<char>(&Offset_5, "Offset");
  return atexit(_E349_9);
}

//----- (006E0130) --------------------------------------------------------  // acclient.c:757189
int _E351_2()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_6, "Quaternion");
  return atexit(_E352_9);
}

//----- (006E0150) --------------------------------------------------------  // acclient.c:757196
int _E354_2()
{
  PStringBase<char>::PStringBase<char>(&Rotation_11, "Rotation");
  return atexit(_E355_9);
}

//----- (006E0170) --------------------------------------------------------  // acclient.c:757203
int _E357_2()
{
  PStringBase<char>::PStringBase<char>(&STime_5, "STime");
  return atexit(_E358_9);
}

//----- (006E0190) --------------------------------------------------------  // acclient.c:757210
int _E360_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_5, "PhysicsSplines");
  return atexit(_E361_9);
}

//----- (006E01B0) --------------------------------------------------------  // acclient.c:757217
int _E363_2()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_5, "BoneOpacities");
  return atexit(_E364_9);
}

//----- (006E01D0) --------------------------------------------------------  // acclient.c:757224
int _E366_2()
{
  PStringBase<char>::PStringBase<char>(&LowPt_5, "LowPoint");
  return atexit(_E367_9);
}

//----- (006E01F0) --------------------------------------------------------  // acclient.c:757231
int _E369_2()
{
  PStringBase<char>::PStringBase<char>(&Radius_5, "Radius");
  return atexit(_E370_9);
}

//----- (006E0210) --------------------------------------------------------  // acclient.c:757238
int _E372_2()
{
  PStringBase<char>::PStringBase<char>(&Height_5, "Height");
  return atexit(_E373_9);
}

//----- (006E0230) --------------------------------------------------------  // acclient.c:757245
int _E375_2()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_5, "Texture2D");
  return atexit(_E376_9);
}

//----- (006E0250) --------------------------------------------------------  // acclient.c:757252
int _E378_2()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_5, "Texture3D");
  return atexit(_E379_9);
}

//----- (006E0270) --------------------------------------------------------  // acclient.c:757259
int _E381_2()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_5, "TextureCube");
  return atexit(_E382_9);
}

//----- (006E0290) --------------------------------------------------------  // acclient.c:757266
int _E384_2()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_5, "TextureMovie2D");
  return atexit(_E385_9);
}

//----- (006E02B0) --------------------------------------------------------  // acclient.c:757273
int _E387_2()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_5, "MovieFile");
  return atexit(_E388_9);
}

//----- (006E02D0) --------------------------------------------------------  // acclient.c:757280
int _E390_2()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_5, "MovieFPS");
  return atexit(_E391_9);
}

//----- (006E02F0) --------------------------------------------------------  // acclient.c:757287
int _E393_2()
{
  PStringBase<char>::PStringBase<char>(&Levels_5, "Levels");
  return atexit(_E394_9);
}

//----- (006E0310) --------------------------------------------------------  // acclient.c:757294
int _E396_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_59, "Instance");
  return atexit(_E397_9);
}

//----- (006E0330) --------------------------------------------------------  // acclient.c:757301
int _E399_2()
{
  PStringBase<char>::PStringBase<char>(&Material_28, "Material");
  return atexit(_E400_9);
}

//----- (006E0350) --------------------------------------------------------  // acclient.c:757308
int _E402_2()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_5, "MaterialType");
  return atexit(_E403_9);
}

//----- (006E0370) --------------------------------------------------------  // acclient.c:757315
int _E405_2()
{
  PStringBase<char>::PStringBase<char>(&Modifier_5, "Modifier");
  return atexit(_E406_9);
}

//----- (006E0390) --------------------------------------------------------  // acclient.c:757322
int _E408_2()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_5, "AllowStencilShadows");
  return atexit(_E409_9);
}

//----- (006E03B0) --------------------------------------------------------  // acclient.c:757329
int _E411_2()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_5, "DiscardGeometry");
  return atexit(_E412_9);
}

//----- (006E03D0) --------------------------------------------------------  // acclient.c:757336
int _E414_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_60, "Material");
  return atexit(_E415_9);
}

//----- (006E03F0) --------------------------------------------------------  // acclient.c:757343
int _E417_2()
{
  PStringBase<char>::PStringBase<char>(&SortMode_5, "SortMode");
  return atexit(_E418_9);
}

//----- (006E0410) --------------------------------------------------------  // acclient.c:757350
int _E420_2()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_5, "None");
  return atexit(_E421_9);
}

//----- (006E0430) --------------------------------------------------------  // acclient.c:757357
int _E423_2()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_5, "Triangle");
  return atexit(_E424_9);
}

//----- (006E0450) --------------------------------------------------------  // acclient.c:757364
int _E426_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_61, "Modifier");
  return atexit(_E427_9);
}

//----- (006E0470) --------------------------------------------------------  // acclient.c:757371
int _E429_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_62, "Property");
  return atexit(_E430_9);
}

//----- (006E0490) --------------------------------------------------------  // acclient.c:757378
int _E432_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_5, "Data");
  return atexit(_E433_9);
}

//----- (006E04B0) --------------------------------------------------------  // acclient.c:757385
int _E435_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_5, "Waveform");
  return atexit(_E436_9);
}

//----- (006E04D0) --------------------------------------------------------  // acclient.c:757392
int _E438_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_5, "Color");
  return atexit(_E439_9);
}

//----- (006E04F0) --------------------------------------------------------  // acclient.c:757399
int _E441_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_5, "Texture");
  return atexit(_E442_9);
}

//----- (006E0510) --------------------------------------------------------  // acclient.c:757406
int _E444_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_5, "Bool");
  return atexit(_E445_9);
}

//----- (006E0530) --------------------------------------------------------  // acclient.c:757413
int _E447_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_63, "Layer");
  return atexit(_E448_9);
}

//----- (006E0550) --------------------------------------------------------  // acclient.c:757420
int _E450_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_5, "UVTranslate");
  return atexit(_E451_9);
}

//----- (006E0570) --------------------------------------------------------  // acclient.c:757427
int _E453_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_5, "UVRotate");
  return atexit(_E454_9);
}

//----- (006E0590) --------------------------------------------------------  // acclient.c:757434
int _E456_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_5, "UVScale");
  return atexit(_E457_9);
}

//----- (006E05B0) --------------------------------------------------------  // acclient.c:757441
int _E459_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_5, "UVTransform");
  return atexit(_E460_9);
}

//----- (006E05D0) --------------------------------------------------------  // acclient.c:757448
int _E462_2()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_5, "TrueFlags");
  return atexit(_E463_9);
}

//----- (006E05F0) --------------------------------------------------------  // acclient.c:757455
int _E465_2()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_5, "FalseFlags");
  return atexit(_E466_9);
}

//----- (006E0610) --------------------------------------------------------  // acclient.c:757462
int _E468_2()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_5, "RenderPass");
  return atexit(_E469_9);
}

//----- (006E0630) --------------------------------------------------------  // acclient.c:757469
int _E471_2()
{
  PStringBase<char>::PStringBase<char>(&Blend_5, "Blend");
  return atexit(_E472_9);
}

//----- (006E0650) --------------------------------------------------------  // acclient.c:757476
int _E474_2()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_5, "DepthTest");
  return atexit(_E475_9);
}

//----- (006E0670) --------------------------------------------------------  // acclient.c:757483
int _E477_2()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_5, "DepthWrite");
  return atexit(_E478_9);
}

//----- (006E0690) --------------------------------------------------------  // acclient.c:757490
int _E480_2()
{
  PStringBase<char>::PStringBase<char>(&CullMode_5, "CullMode");
  return atexit(_E481_9);
}

//----- (006E06B0) --------------------------------------------------------  // acclient.c:757497
int _E483_2()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_5, "DepthFog");
  return atexit(_E484_9);
}

//----- (006E06D0) --------------------------------------------------------  // acclient.c:757504
int _E486_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_5, "AlphaTestMode");
  return atexit(_E487_9);
}

//----- (006E06F0) --------------------------------------------------------  // acclient.c:757511
int _E489_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_5, "AlphaTestRef");
  return atexit(_E490_9);
}

//----- (006E0710) --------------------------------------------------------  // acclient.c:757518
int _E492_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_5, "FFUseLighting");
  return atexit(_E493_9);
}

//----- (006E0730) --------------------------------------------------------  // acclient.c:757525
int _E495_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_5, "FFUseDyeColorInTFactor");
  return atexit(_E496_9);
}

//----- (006E0750) --------------------------------------------------------  // acclient.c:757532
int _E498_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_5, "FFUseSpecularLighting");
  return atexit(_E499_9);
}

//----- (006E0770) --------------------------------------------------------  // acclient.c:757539
int _E501_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_5, "FFUseDistanceFog");
  return atexit(_E502_9);
}

//----- (006E0790) --------------------------------------------------------  // acclient.c:757546
int _E504_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_5, "FFUseVertexDiffuse");
  return atexit(_E505_9);
}

//----- (006E07B0) --------------------------------------------------------  // acclient.c:757553
int _E507_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_5, "FFUseVertexSpecular");
  return atexit(_E508_9);
}

//----- (006E07D0) --------------------------------------------------------  // acclient.c:757560
int _E510_2()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_5, "ShaderSupportsDynamicLights");
  return atexit(_E511_9);
}

//----- (006E07F0) --------------------------------------------------------  // acclient.c:757567
int _E513_2()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_5, "UsesTransparency");
  return atexit(_E514_9);
}

//----- (006E0810) --------------------------------------------------------  // acclient.c:757574
int _E516_2()
{
  PStringBase<char>::PStringBase<char>(&Ambient_5, "Ambient");
  return atexit(_E517_9);
}

//----- (006E0830) --------------------------------------------------------  // acclient.c:757581
int _E519_2()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_12, "Diffuse");
  return atexit(_E520_9);
}

//----- (006E0850) --------------------------------------------------------  // acclient.c:757588
int _E522_2()
{
  PStringBase<char>::PStringBase<char>(&Specular_12, "Specular");
  return atexit(_E523_9);
}

//----- (006E0870) --------------------------------------------------------  // acclient.c:757595
int _E525_2()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_5, "SpecularPower");
  return atexit(_E526_9);
}

//----- (006E0890) --------------------------------------------------------  // acclient.c:757602
int _E528_2()
{
  PStringBase<char>::PStringBase<char>(&Dye_5, "Dye");
  return atexit(_E529_9);
}

//----- (006E08B0) --------------------------------------------------------  // acclient.c:757609
int _E531_2()
{
  PStringBase<char>::PStringBase<char>(&Emissive_5, "Emissive");
  return atexit(_E532_9);
}

//----- (006E08D0) --------------------------------------------------------  // acclient.c:757616
int _E534_2()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_5, "VertexFormat");
  return atexit(_E535_9);
}

//----- (006E08F0) --------------------------------------------------------  // acclient.c:757623
int _E537_2()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_5, "VertexShader");
  return atexit(_E538_9);
}

//----- (006E0910) --------------------------------------------------------  // acclient.c:757630
int _E540_2()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_5, "PixelShader");
  return atexit(_E541_9);
}

//----- (006E0930) --------------------------------------------------------  // acclient.c:757637
int _E543_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_5, "None");
  return atexit(_E544_9);
}

//----- (006E0950) --------------------------------------------------------  // acclient.c:757644
int _E546_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_5, "Reflections");
  return atexit(_E547_9);
}

//----- (006E0970) --------------------------------------------------------  // acclient.c:757651
int _E549_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_5, "VideoPost");
  return atexit(_E550_9);
}

//----- (006E0990) --------------------------------------------------------  // acclient.c:757658
int _E552_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_5, "HighDetail");
  return atexit(_E553_9);
}

//----- (006E09B0) --------------------------------------------------------  // acclient.c:757665
int _E555_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_5, "Specular");
  return atexit(_E556_9);
}

//----- (006E09D0) --------------------------------------------------------  // acclient.c:757672
int _E558_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_5, "Class1");
  return atexit(_E559_9);
}

//----- (006E09F0) --------------------------------------------------------  // acclient.c:757679
int _E561_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_5, "Class2");
  return atexit(_E562_9);
}

//----- (006E0A10) --------------------------------------------------------  // acclient.c:757686
int _E564_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_5, "Class3");
  return atexit(_E565_9);
}

//----- (006E0A30) --------------------------------------------------------  // acclient.c:757693
int _E567_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_5, "Default");
  return atexit(_E568_9);
}

//----- (006E0A50) --------------------------------------------------------  // acclient.c:757700
int _E570_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_5,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E571_9);
}

//----- (006E0A70) --------------------------------------------------------  // acclient.c:757709
int _E573_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_5, "PointLightDiffuseAndSpecular");
  return atexit(_E574_9);
}

//----- (006E0A90) --------------------------------------------------------  // acclient.c:757716
int _E576_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_5,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E577_9);
}

//----- (006E0AB0) --------------------------------------------------------  // acclient.c:757725
int _E579_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_5,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E580_9);
}

//----- (006E0AD0) --------------------------------------------------------  // acclient.c:757734
int _E582_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_5,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E583_9);
}

//----- (006E0AF0) --------------------------------------------------------  // acclient.c:757743
int _E585_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_5, "DistanceFog");
  return atexit(_E586_9);
}

//----- (006E0B10) --------------------------------------------------------  // acclient.c:757750
int _E588_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_5, "FFGlow");
  return atexit(_E589_9);
}

//----- (006E0B30) --------------------------------------------------------  // acclient.c:757757
int _E591_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_5, "ShaderGlow");
  return atexit(_E592_9);
}

//----- (006E0B50) --------------------------------------------------------  // acclient.c:757764
int _E594_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_5, "LandscapeShadowMap");
  return atexit(_E595_9);
}

//----- (006E0B70) --------------------------------------------------------  // acclient.c:757771
int _E597_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_5, "AlphaBlend");
  return atexit(_E598_9);
}

//----- (006E0B90) --------------------------------------------------------  // acclient.c:757778
int _E600_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_5, "AL_0DL_0PL");
  return atexit(_E601_9);
}

//----- (006E0BB0) --------------------------------------------------------  // acclient.c:757785
int _E603_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_5, "AL_0DL_1PL");
  return atexit(_E604_9);
}

//----- (006E0BD0) --------------------------------------------------------  // acclient.c:757792
int _E606_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_5, "AL_0DL_2PL");
  return atexit(_E607_9);
}

//----- (006E0BF0) --------------------------------------------------------  // acclient.c:757799
int _E609_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_5, "AL_0DL_3PL");
  return atexit(_E610_9);
}

//----- (006E0C10) --------------------------------------------------------  // acclient.c:757806
int _E612_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_5, "AL_0DL_4PL");
  return atexit(_E613_9);
}

//----- (006E0C30) --------------------------------------------------------  // acclient.c:757813
int _E615_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_5, "AL_0DL_5PL");
  return atexit(_E616_9);
}

//----- (006E0C50) --------------------------------------------------------  // acclient.c:757820
int _E618_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_5, "AL_0DL_6PL");
  return atexit(_E619_9);
}

//----- (006E0C70) --------------------------------------------------------  // acclient.c:757827
int _E621_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_5, "AL_0DL_7PL");
  return atexit(_E622_9);
}

//----- (006E0C90) --------------------------------------------------------  // acclient.c:757834
int _E624_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_5, "AL_0DL_8PL");
  return atexit(_E625_9);
}

//----- (006E0CB0) --------------------------------------------------------  // acclient.c:757841
int _E627_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_5, "AL_1DL_0PL");
  return atexit(_E628_9);
}

//----- (006E0CD0) --------------------------------------------------------  // acclient.c:757848
int _E630_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_5, "AL_1DL_1PL");
  return atexit(_E631_9);
}

//----- (006E0CF0) --------------------------------------------------------  // acclient.c:757855
int _E633_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_5, "AL_1DL_2PL");
  return atexit(_E634_9);
}

//----- (006E0D10) --------------------------------------------------------  // acclient.c:757862
int _E636_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_5, "AL_1DL_3PL");
  return atexit(_E637_9);
}

//----- (006E0D30) --------------------------------------------------------  // acclient.c:757869
int _E639_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_5, "AL_1DL_4PL");
  return atexit(_E640_9);
}

//----- (006E0D50) --------------------------------------------------------  // acclient.c:757876
int _E642_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_5, "AL_1DL_5PL");
  return atexit(_E643_9);
}

//----- (006E0D70) --------------------------------------------------------  // acclient.c:757883
int _E645_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_5, "AL_1DL_6PL");
  return atexit(_E646_9);
}

//----- (006E0D90) --------------------------------------------------------  // acclient.c:757890
int _E648_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_5, "AL_1DL_7PL");
  return atexit(_E649_9);
}

//----- (006E0DB0) --------------------------------------------------------  // acclient.c:757897
int _E651_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_5, "AL_0DL_0PL_Fog");
  return atexit(_E652_9);
}

//----- (006E0DD0) --------------------------------------------------------  // acclient.c:757904
int _E654_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_5, "AL_0DL_1PL_Fog");
  return atexit(_E655_9);
}

//----- (006E0DF0) --------------------------------------------------------  // acclient.c:757911
int _E657_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_5, "AL_0DL_2PL_Fog");
  return atexit(_E658_9);
}

//----- (006E0E10) --------------------------------------------------------  // acclient.c:757918
int _E660_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_5, "AL_0DL_3PL_Fog");
  return atexit(_E661_9);
}

//----- (006E0E30) --------------------------------------------------------  // acclient.c:757925
int _E663_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_5, "AL_0DL_4PL_Fog");
  return atexit(_E664_9);
}

//----- (006E0E50) --------------------------------------------------------  // acclient.c:757932
int _E666_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_5, "AL_0DL_5PL_Fog");
  return atexit(_E667_9);
}

//----- (006E0E70) --------------------------------------------------------  // acclient.c:757939
int _E669_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_5, "AL_0DL_6PL_Fog");
  return atexit(_E670_9);
}

//----- (006E0E90) --------------------------------------------------------  // acclient.c:757946
int _E672_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_5, "AL_0DL_7PL_Fog");
  return atexit(_E673_9);
}

//----- (006E0EB0) --------------------------------------------------------  // acclient.c:757953
int _E675_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_5, "AL_0DL_8PL_Fog");
  return atexit(_E676_9);
}

//----- (006E0ED0) --------------------------------------------------------  // acclient.c:757960
int _E678_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_5, "AL_1DL_0PL_Fog");
  return atexit(_E679_9);
}

//----- (006E0EF0) --------------------------------------------------------  // acclient.c:757967
int _E681_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_5, "AL_1DL_1PL_Fog");
  return atexit(_E682_9);
}

//----- (006E0F10) --------------------------------------------------------  // acclient.c:757974
int _E684_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_5, "AL_1DL_2PL_Fog");
  return atexit(_E685_9);
}

//----- (006E0F30) --------------------------------------------------------  // acclient.c:757981
int _E687_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_5, "AL_1DL_3PL_Fog");
  return atexit(_E688_9);
}

//----- (006E0F50) --------------------------------------------------------  // acclient.c:757988
int _E690_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_5, "AL_1DL_4PL_Fog");
  return atexit(_E691_9);
}

//----- (006E0F70) --------------------------------------------------------  // acclient.c:757995
int _E693_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_5, "AL_1DL_5PL_Fog");
  return atexit(_E694_9);
}

//----- (006E0F90) --------------------------------------------------------  // acclient.c:758002
int _E696_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_5, "AL_1DL_6PL_Fog");
  return atexit(_E697_9);
}

//----- (006E0FB0) --------------------------------------------------------  // acclient.c:758009
int _E699_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_5, "AL_1DL_7PL_Fog");
  return atexit(_E700_9);
}

//----- (006E0FD0) --------------------------------------------------------  // acclient.c:758016
int _E702_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_5, "Zero");
  return atexit(_E703_9);
}

//----- (006E0FF0) --------------------------------------------------------  // acclient.c:758023
int _E705_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_5, "One");
  return atexit(_E706_9);
}

//----- (006E1010) --------------------------------------------------------  // acclient.c:758030
int _E708_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_5, "SrcColor");
  return atexit(_E709_9);
}

//----- (006E1030) --------------------------------------------------------  // acclient.c:758037
int _E711_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_5, "InvSrcColor");
  return atexit(_E712_9);
}

//----- (006E1050) --------------------------------------------------------  // acclient.c:758044
int _E714_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_5, "SrcAlpha");
  return atexit(_E715_9);
}

//----- (006E1070) --------------------------------------------------------  // acclient.c:758051
int _E717_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_5, "InvSrcAlpha");
  return atexit(_E718_9);
}

//----- (006E1090) --------------------------------------------------------  // acclient.c:758058
int _E720_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_5, "DstAlpha");
  return atexit(_E721_9);
}

//----- (006E10B0) --------------------------------------------------------  // acclient.c:758065
int _E723_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_5, "InvDstAlpha");
  return atexit(_E724_9);
}

//----- (006E10D0) --------------------------------------------------------  // acclient.c:758072
int _E726_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_5, "DstColor");
  return atexit(_E727_9);
}

//----- (006E10F0) --------------------------------------------------------  // acclient.c:758079
int _E729_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_5, "InvDstColor");
  return atexit(_E730_9);
}

//----- (006E1110) --------------------------------------------------------  // acclient.c:758086
int _E732_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_5, "SrcAlphaSat");
  return atexit(_E733_9);
}

//----- (006E1130) --------------------------------------------------------  // acclient.c:758093
int _E735_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_5, "Less");
  return atexit(_E736_9);
}

//----- (006E1150) --------------------------------------------------------  // acclient.c:758100
int _E738_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_5, "Equal");
  return atexit(_E739_9);
}

//----- (006E1170) --------------------------------------------------------  // acclient.c:758107
int _E741_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_5, "LessEqual");
  return atexit(_E742_9);
}

//----- (006E1190) --------------------------------------------------------  // acclient.c:758114
int _E744_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_5, "Greater");
  return atexit(_E745_9);
}

//----- (006E11B0) --------------------------------------------------------  // acclient.c:758121
int _E747_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_5, "NotEqual");
  return atexit(_E748_9);
}

//----- (006E11D0) --------------------------------------------------------  // acclient.c:758128
int _E750_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_5, "GreaterEqual");
  return atexit(_E751_9);
}

//----- (006E11F0) --------------------------------------------------------  // acclient.c:758135
int _E753_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_5, "Always");
  return atexit(_E754_9);
}

//----- (006E1210) --------------------------------------------------------  // acclient.c:758142
int _E756_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_5, "On");
  return atexit(_E757_9);
}

//----- (006E1230) --------------------------------------------------------  // acclient.c:758149
int _E759_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_5, "Off");
  return atexit(_E760_9);
}

//----- (006E1250) --------------------------------------------------------  // acclient.c:758156
int _E762_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_5, "LayerDiffuse");
  return atexit(_E763_9);
}

//----- (006E1270) --------------------------------------------------------  // acclient.c:758163
int _E765_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_5, "LayerSpecular");
  return atexit(_E766_9);
}

//----- (006E1290) --------------------------------------------------------  // acclient.c:758170
int _E768_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_5, "VertexDiffuse");
  return atexit(_E769_9);
}

//----- (006E12B0) --------------------------------------------------------  // acclient.c:758177
int _E771_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_5, "VertexSpecular");
  return atexit(_E772_9);
}

//----- (006E12D0) --------------------------------------------------------  // acclient.c:758184
int _E774_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_5, "None");
  return atexit(_E775_9);
}

//----- (006E12F0) --------------------------------------------------------  // acclient.c:758191
int _E777_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_5, "CW");
  return atexit(_E778_9);
}

//----- (006E1310) --------------------------------------------------------  // acclient.c:758198
int _E780_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_5, "CCW");
  return atexit(_E781_9);
}

//----- (006E1330) --------------------------------------------------------  // acclient.c:758205
int _E783_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_5, "None");
  return atexit(_E784_9);
}

//----- (006E1350) --------------------------------------------------------  // acclient.c:758212
int _E786_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_5, "Simple");
  return atexit(_E787_9);
}

//----- (006E1370) --------------------------------------------------------  // acclient.c:758219
int _E789_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_5, "Diffuse");
  return atexit(_E790_9);
}

//----- (006E1390) --------------------------------------------------------  // acclient.c:758226
int _E792_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_5, "Specular");
  return atexit(_E793_9);
}

//----- (006E13B0) --------------------------------------------------------  // acclient.c:758233
int _E795_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_5, "Off");
  return atexit(_E796_9);
}

//----- (006E13D0) --------------------------------------------------------  // acclient.c:758240
int _E798_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_5, "On");
  return atexit(_E799_9);
}

//----- (006E13F0) --------------------------------------------------------  // acclient.c:758247
int _E801_2()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_5, "Off");
  return atexit(_E802_9);
}

//----- (006E1410) --------------------------------------------------------  // acclient.c:758254
int _E804_2()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_5, "On");
  return atexit(_E805_9);
}

//----- (006E1430) --------------------------------------------------------  // acclient.c:758261
int _E807_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_5, "Origin");
  return atexit(_E808_9);
}

//----- (006E1450) --------------------------------------------------------  // acclient.c:758268
int _E810_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_5, "Normal");
  return atexit(_E811_9);
}

//----- (006E1470) --------------------------------------------------------  // acclient.c:758275
int _E813_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_5, "PointSize");
  return atexit(_E814_9);
}

//----- (006E1490) --------------------------------------------------------  // acclient.c:758282
int _E816_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_5, "Diffuse");
  return atexit(_E817_9);
}

//----- (006E14B0) --------------------------------------------------------  // acclient.c:758289
int _E819_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_5, "Specular");
  return atexit(_E820_9);
}

//----- (006E14D0) --------------------------------------------------------  // acclient.c:758296
int _E822_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_5, "TCPairX1");
  return atexit(_E823_9);
}

//----- (006E14F0) --------------------------------------------------------  // acclient.c:758303
int _E825_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_5, "TCPairX2");
  return atexit(_E826_9);
}

//----- (006E1510) --------------------------------------------------------  // acclient.c:758310
int _E828_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_5, "TCPairX3");
  return atexit(_E829_9);
}

//----- (006E1530) --------------------------------------------------------  // acclient.c:758317
int _E831_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_5, "TCPairX4");
  return atexit(_E832_9);
}

//----- (006E1550) --------------------------------------------------------  // acclient.c:758324
int _E834_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_5, "TCPairX5");
  return atexit(_E835_9);
}

//----- (006E1570) --------------------------------------------------------  // acclient.c:758331
int _E837_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_5, "TCPairX6");
  return atexit(_E838_9);
}

//----- (006E1590) --------------------------------------------------------  // acclient.c:758338
int _E840_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_5, "TCPairX7");
  return atexit(_E841_9);
}

//----- (006E15B0) --------------------------------------------------------  // acclient.c:758345
int _E843_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_5, "TCPairX8");
  return atexit(_E844_9);
}

//----- (006E15D0) --------------------------------------------------------  // acclient.c:758352
int _E846_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_5, "VectorS");
  return atexit(_E847_9);
}

//----- (006E15F0) --------------------------------------------------------  // acclient.c:758359
int _E849_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_5, "VectorT");
  return atexit(_E850_9);
}

//----- (006E1610) --------------------------------------------------------  // acclient.c:758366
int _E852_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_64, "Stage");
  return atexit(_E853_9);
}

//----- (006E1630) --------------------------------------------------------  // acclient.c:758373
int _E855_2()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_5, "Sampler");
  return atexit(_E856_9);
}

//----- (006E1650) --------------------------------------------------------  // acclient.c:758380
int _E858_2()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_5, "SamplerName");
  return atexit(_E859_9);
}

//----- (006E1670) --------------------------------------------------------  // acclient.c:758387
int _E861_2()
{
  PStringBase<char>::PStringBase<char>(&Texture_5, "Texture");
  return atexit(_E862_9);
}

//----- (006E1690) --------------------------------------------------------  // acclient.c:758394
int _E864_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_5, "!FrameBuffer");
  return atexit(_E865_9);
}

//----- (006E16B0) --------------------------------------------------------  // acclient.c:758401
int _E867_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_5, "!Distortion");
  return atexit(_E868_9);
}

//----- (006E16D0) --------------------------------------------------------  // acclient.c:758408
int _E870_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_5, "!Reflection");
  return atexit(_E871_9);
}

//----- (006E16F0) --------------------------------------------------------  // acclient.c:758415
int _E873_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_5, "!NormalizeCube");
  return atexit(_E874_9);
}

//----- (006E1710) --------------------------------------------------------  // acclient.c:758422
int _E876_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_5, "!LightProjectorCube");
  return atexit(_E877_9);
}

//----- (006E1730) --------------------------------------------------------  // acclient.c:758429
int _E879_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_5, "!EnvironmentCube");
  return atexit(_E880_9);
}

//----- (006E1750) --------------------------------------------------------  // acclient.c:758436
int _E882_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_5, "!LandscapeShadows");
  return atexit(_E883_9);
}

//----- (006E1770) --------------------------------------------------------  // acclient.c:758443
int _E885_2()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_5, "AddressMode");
  return atexit(_E886_9);
}

//----- (006E1790) --------------------------------------------------------  // acclient.c:758450
int _E888_2()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_5, "FilterMode");
  return atexit(_E889_9);
}

//----- (006E17B0) --------------------------------------------------------  // acclient.c:758457
int _E891_2()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_5, "FFColorOp");
  return atexit(_E892_9);
}

//----- (006E17D0) --------------------------------------------------------  // acclient.c:758464
int _E894_2()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_5, "FFColorArg1");
  return atexit(_E895_9);
}

//----- (006E17F0) --------------------------------------------------------  // acclient.c:758471
int _E897_2()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_5, "FFColorArg2");
  return atexit(_E898_9);
}

//----- (006E1810) --------------------------------------------------------  // acclient.c:758478
int _E900_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_5, "FFAlphaOp");
  return atexit(_E901_9);
}

//----- (006E1830) --------------------------------------------------------  // acclient.c:758485
int _E903_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_5, "FFAlphaArg1");
  return atexit(_E904_9);
}

//----- (006E1850) --------------------------------------------------------  // acclient.c:758492
int _E906_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_5, "FFAlphaArg2");
  return atexit(_E907_9);
}

//----- (006E1870) --------------------------------------------------------  // acclient.c:758499
int _E909_2()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_5, "FFTexCoordIndex");
  return atexit(_E910_9);
}

//----- (006E1890) --------------------------------------------------------  // acclient.c:758506
int _E912_2()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_5, "FFUseProjection");
  return atexit(_E913_9);
}

//----- (006E18B0) --------------------------------------------------------  // acclient.c:758513
int _E915_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_5, "SelectArg1");
  return atexit(_E916_9);
}

//----- (006E18D0) --------------------------------------------------------  // acclient.c:758520
int _E918_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_5, "SelectArg2");
  return atexit(_E919_9);
}

//----- (006E18F0) --------------------------------------------------------  // acclient.c:758527
int _E921_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_5, "Modulate");
  return atexit(_E922_9);
}

//----- (006E1910) --------------------------------------------------------  // acclient.c:758534
int _E924_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_5, "Modulate2X");
  return atexit(_E925_9);
}

//----- (006E1930) --------------------------------------------------------  // acclient.c:758541
int _E927_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_5, "Modulate4X");
  return atexit(_E928_9);
}

//----- (006E1950) --------------------------------------------------------  // acclient.c:758548
int _E930_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_5, "Add");
  return atexit(_E931_9);
}

//----- (006E1970) --------------------------------------------------------  // acclient.c:758555
int _E933_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_5, "AddSigned");
  return atexit(_E934_9);
}

//----- (006E1990) --------------------------------------------------------  // acclient.c:758562
int _E936_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_5, "AddSigned2X");
  return atexit(_E937_9);
}

//----- (006E19B0) --------------------------------------------------------  // acclient.c:758569
int _E939_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_5, "Subtract");
  return atexit(_E940_9);
}

//----- (006E19D0) --------------------------------------------------------  // acclient.c:758576
int _E942_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_5, "AddSmooth");
  return atexit(_E943_9);
}

//----- (006E19F0) --------------------------------------------------------  // acclient.c:758583
int _E945_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_5, "BlendDiffuseAlpha");
  return atexit(_E946_9);
}

//----- (006E1A10) --------------------------------------------------------  // acclient.c:758590
int _E948_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_5, "BlendTextureAlpha");
  return atexit(_E949_9);
}

//----- (006E1A30) --------------------------------------------------------  // acclient.c:758597
int _E951_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_5, "BlendFactorAlpha");
  return atexit(_E952_9);
}

//----- (006E1A50) --------------------------------------------------------  // acclient.c:758604
int _E954_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_5, "BlendTextureAlphaPM");
  return atexit(_E955_9);
}

//----- (006E1A70) --------------------------------------------------------  // acclient.c:758611
int _E957_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_5, "BlendCurrentAlpha");
  return atexit(_E958_9);
}

//----- (006E1A90) --------------------------------------------------------  // acclient.c:758618
int _E960_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_5, "Premodulate");
  return atexit(_E961_9);
}

//----- (006E1AB0) --------------------------------------------------------  // acclient.c:758625
int _E963_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_5, "ModulateAlphaAddColor");
  return atexit(_E964_9);
}

//----- (006E1AD0) --------------------------------------------------------  // acclient.c:758632
int _E966_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_5, "ModulateColorAddAlpha");
  return atexit(_E967_9);
}

//----- (006E1AF0) --------------------------------------------------------  // acclient.c:758639
int _E969_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_5, "ModulateInvAlphaAddColor");
  return atexit(_E970_9);
}

//----- (006E1B10) --------------------------------------------------------  // acclient.c:758646
int _E972_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_5, "ModulateInvColorAddAlpha");
  return atexit(_E973_9);
}

//----- (006E1B30) --------------------------------------------------------  // acclient.c:758653
int _E975_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_5, "BumpEnvMap");
  return atexit(_E976_9);
}

//----- (006E1B50) --------------------------------------------------------  // acclient.c:758660
int _E978_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_5, "BumpEnvMapLuminance");
  return atexit(_E979_9);
}

//----- (006E1B70) --------------------------------------------------------  // acclient.c:758667
int _E981_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_5, "DotProduct3");
  return atexit(_E982_9);
}

//----- (006E1B90) --------------------------------------------------------  // acclient.c:758674
int _E984_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_5, "MultiplyAdd");
  return atexit(_E985_9);
}

//----- (006E1BB0) --------------------------------------------------------  // acclient.c:758681
int _E987_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_5, "Lerp");
  return atexit(_E988_9);
}

//----- (006E1BD0) --------------------------------------------------------  // acclient.c:758688
int _E990_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_5, "Diffuse");
  return atexit(_E991_9);
}

//----- (006E1BF0) --------------------------------------------------------  // acclient.c:758695
int _E993_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_5, "Specular");
  return atexit(_E994_9);
}

//----- (006E1C10) --------------------------------------------------------  // acclient.c:758702
int _E996_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_5, "Current");
  return atexit(_E997_9);
}

//----- (006E1C30) --------------------------------------------------------  // acclient.c:758709
int _E999_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_5, "Texture");
  return atexit(_E1000_9);
}

//----- (006E1C50) --------------------------------------------------------  // acclient.c:758716
int _E1002_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_5, "TFactor");
  return atexit(_E1003_9);
}

//----- (006E1C70) --------------------------------------------------------  // acclient.c:758723
int _E1005_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_5, "Wrap");
  return atexit(_E1006_9);
}

//----- (006E1C90) --------------------------------------------------------  // acclient.c:758730
int _E1008_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_5, "Mirror");
  return atexit(_E1009_9);
}

//----- (006E1CB0) --------------------------------------------------------  // acclient.c:758737
int _E1011_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_5, "Clamp");
  return atexit(_E1012_9);
}

//----- (006E1CD0) --------------------------------------------------------  // acclient.c:758744
int _E1014_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_5, "Border");
  return atexit(_E1015_9);
}

//----- (006E1CF0) --------------------------------------------------------  // acclient.c:758751
int _E1017_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_5, "None");
  return atexit(_E1018_9);
}

//----- (006E1D10) --------------------------------------------------------  // acclient.c:758758
int _E1020_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_5, "Point");
  return atexit(_E1021_9);
}

//----- (006E1D30) --------------------------------------------------------  // acclient.c:758765
int _E1023_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_5, "Linear");
  return atexit(_E1024_9);
}

//----- (006E1D50) --------------------------------------------------------  // acclient.c:758772
int _E1026_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_5, "Anisotropic");
  return atexit(_E1027_9);
}

//----- (006E1D70) --------------------------------------------------------  // acclient.c:758779
int _E1029_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_5, "ReflectionVector");
  return atexit(_E1030_9);
}

//----- (006E1D90) --------------------------------------------------------  // acclient.c:758786
int _E1032_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_5, "ViewNormal");
  return atexit(_E1033_9);
}

//----- (006E1DB0) --------------------------------------------------------  // acclient.c:758793
int _E1035_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_5, "ViewOrigin");
  return atexit(_E1036_9);
}

//----- (006E1DD0) --------------------------------------------------------  // acclient.c:758800
int _E1038_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_5, "SphereMap");
  return atexit(_E1039_9);
}

//----- (006E1DF0) --------------------------------------------------------  // acclient.c:758807
int _E1041_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_5, "CubeMapReflection");
  return atexit(_E1042_9);
}

//----- (006E1E10) --------------------------------------------------------  // acclient.c:758814
int _E1044_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_5, "CubeMapFakeLight");
  return atexit(_E1045_9);
}

//----- (006E1E30) --------------------------------------------------------  // acclient.c:758821
int _E1047_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_65, "FFModifier");
  return atexit(_E1048_9);
}

//----- (006E1E50) --------------------------------------------------------  // acclient.c:758828
int _E1050_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_5, "Origin");
  return atexit(_E1051_9);
}

//----- (006E1E70) --------------------------------------------------------  // acclient.c:758835
int _E1053_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_5, "Normal");
  return atexit(_E1054_9);
}

//----- (006E1E90) --------------------------------------------------------  // acclient.c:758842
int _E1056_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_5, "Diffuse");
  return atexit(_E1057_9);
}

//----- (006E1EB0) --------------------------------------------------------  // acclient.c:758849
int _E1059_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_5, "UVTranslate");
  return atexit(_E1060_9);
}

//----- (006E1ED0) --------------------------------------------------------  // acclient.c:758856
int _E1062_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_5, "UVRotate");
  return atexit(_E1063_9);
}

//----- (006E1EF0) --------------------------------------------------------  // acclient.c:758863
int _E1065_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_5, "UVScale");
  return atexit(_E1066_9);
}

//----- (006E1F10) --------------------------------------------------------  // acclient.c:758870
int _E1068_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_5, "UVTransform");
  return atexit(_E1069_9);
}

//----- (006E1F30) --------------------------------------------------------  // acclient.c:758877
int _E1071_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_5, "TexCoordIndex");
  return atexit(_E1072_9);
}

//----- (006E1F50) --------------------------------------------------------  // acclient.c:758884
int _E1074_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_5, "Translate");
  return atexit(_E1075_9);
}

//----- (006E1F70) --------------------------------------------------------  // acclient.c:758891
int _E1077_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_5, "TexCoordIndex");
  return atexit(_E1078_9);
}

//----- (006E1F90) --------------------------------------------------------  // acclient.c:758898
int _E1080_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_5, "Rotate");
  return atexit(_E1081_9);
}

//----- (006E1FB0) --------------------------------------------------------  // acclient.c:758905
int _E1083_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_5, "TexCoordIndex");
  return atexit(_E1084_9);
}

//----- (006E1FD0) --------------------------------------------------------  // acclient.c:758912
int _E1086_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_5, "Scale");
  return atexit(_E1087_9);
}

//----- (006E1FF0) --------------------------------------------------------  // acclient.c:758919
int _E1089_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_66, "PSDesc");
  return atexit(_E1090_9);
}

//----- (006E2010) --------------------------------------------------------  // acclient.c:758926
int _E1092_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_5, "PhysicsTimeStep");
  return atexit(_E1093_9);
}

//----- (006E2030) --------------------------------------------------------  // acclient.c:758933
int _E1095_2()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_5, "FastForwardTime");
  return atexit(_E1096_9);
}

//----- (006E2050) --------------------------------------------------------  // acclient.c:758940
int _E1098_2()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_5, "StartFadeDistance");
  return atexit(_E1099_9);
}

//----- (006E2070) --------------------------------------------------------  // acclient.c:758947
int _E1101_2()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_5, "StopFadeDistance");
  return atexit(_E1102_9);
}

//----- (006E2090) --------------------------------------------------------  // acclient.c:758954
int _E1104_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_5, "PhysicsDuration");
  return atexit(_E1105_9);
}

//----- (006E20B0) --------------------------------------------------------  // acclient.c:758961
int _E1107_2()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_5, "ScaleType");
  return atexit(_E1108_9);
}

//----- (006E20D0) --------------------------------------------------------  // acclient.c:758968
int _E1110_2()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_5, "WorldSpace");
  return atexit(_E1111_9);
}

//----- (006E20F0) --------------------------------------------------------  // acclient.c:758975
int _E1113_2()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_5, "ForceDraw");
  return atexit(_E1114_9);
}

//----- (006E2110) --------------------------------------------------------  // acclient.c:758982
int _E1116_2()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_5, "NumEmitters");
  return atexit(_E1117_9);
}

//----- (006E2130) --------------------------------------------------------  // acclient.c:758989
int _E1119_2()
{
  PStringBase<char>::PStringBase<char>(&Material_29, "Material");
  return atexit(_E1120_9);
}

//----- (006E2150) --------------------------------------------------------  // acclient.c:758996
int _E1122_2()
{
  PStringBase<char>::PStringBase<char>(&Version_5, "Version");
  return atexit(_E1123_9);
}

//----- (006E2170) --------------------------------------------------------  // acclient.c:759003
int _E1125_2()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_5, "MaxParticles");
  return atexit(_E1126_9);
}

//----- (006E2190) --------------------------------------------------------  // acclient.c:759010
int _E1128_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_67, "Emitter");
  return atexit(_E1129_9);
}

//----- (006E21B0) --------------------------------------------------------  // acclient.c:759017
int _E1131_2()
{
  PStringBase<char>::PStringBase<char>(&Origin_12, "Origin");
  return atexit(_E1132_9);
}

//----- (006E21D0) --------------------------------------------------------  // acclient.c:759024
int _E1134_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_5, "Shape");
  return atexit(_E1135_9);
}

//----- (006E21F0) --------------------------------------------------------  // acclient.c:759031
int _E1137_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_5, "Point");
  return atexit(_E1138_9);
}

//----- (006E2210) --------------------------------------------------------  // acclient.c:759038
int _E1140_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_5, "Line");
  return atexit(_E1141_9);
}

//----- (006E2230) --------------------------------------------------------  // acclient.c:759045
int _E1143_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_5, "Quad");
  return atexit(_E1144_9);
}

//----- (006E2250) --------------------------------------------------------  // acclient.c:759052
int _E1146_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_5, "Disc");
  return atexit(_E1147_9);
}

//----- (006E2270) --------------------------------------------------------  // acclient.c:759059
int _E1149_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_5, "Sphere");
  return atexit(_E1150_9);
}

//----- (006E2290) --------------------------------------------------------  // acclient.c:759066
int _E1152_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_5, "ParticleShape");
  return atexit(_E1153_9);
}

//----- (006E22B0) --------------------------------------------------------  // acclient.c:759073
int _E1155_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_5, "Triangle");
  return atexit(_E1156_9);
}

//----- (006E22D0) --------------------------------------------------------  // acclient.c:759080
int _E1158_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_5, "Quad");
  return atexit(_E1159_9);
}

//----- (006E22F0) --------------------------------------------------------  // acclient.c:759087
int _E1161_2()
{
  PStringBase<char>::PStringBase<char>(&Streak_5, "Streak");
  return atexit(_E1162_9);
}

//----- (006E2310) --------------------------------------------------------  // acclient.c:759094
int _E1164_2()
{
  PStringBase<char>::PStringBase<char>(&Rotation_12, "Rotation");
  return atexit(_E1165_9);
}

//----- (006E2330) --------------------------------------------------------  // acclient.c:759101
int _E1167_2()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_5, "WorldRotation");
  return atexit(_E1168_9);
}

//----- (006E2350) --------------------------------------------------------  // acclient.c:759108
int _E1170_2()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_5, "RotateVelocity");
  return atexit(_E1171_9);
}

//----- (006E2370) --------------------------------------------------------  // acclient.c:759115
int _E1173_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_5, "ParticleScale");
  return atexit(_E1174_9);
}

//----- (006E2390) --------------------------------------------------------  // acclient.c:759122
int _E1176_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_18, "Scale");
  return atexit(_E1177_9);
}

//----- (006E23B0) --------------------------------------------------------  // acclient.c:759129
int _E1179_2()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_5, "ExplodingDir");
  return atexit(_E1180_9);
}

//----- (006E23D0) --------------------------------------------------------  // acclient.c:759136
int _E1182_2()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_5, "BirthRate");
  return atexit(_E1183_9);
}

//----- (006E23F0) --------------------------------------------------------  // acclient.c:759143
int _E1185_2()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_5, "Lifespan");
  return atexit(_E1186_9);
}

//----- (006E2410) --------------------------------------------------------  // acclient.c:759150
int _E1188_2()
{
  PStringBase<char>::PStringBase<char>(&Velocity_5, "Velocity");
  return atexit(_E1189_9);
}

//----- (006E2430) --------------------------------------------------------  // acclient.c:759157
int _E1191_2()
{
  PStringBase<char>::PStringBase<char>(&Direction_5, "Direction");
  return atexit(_E1192_9);
}

//----- (006E2450) --------------------------------------------------------  // acclient.c:759164
int _E1194_2()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_5, "MinSpread");
  return atexit(_E1195_9);
}

//----- (006E2470) --------------------------------------------------------  // acclient.c:759171
int _E1197_2()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_5, "MaxSpread");
  return atexit(_E1198_9);
}

//----- (006E2490) --------------------------------------------------------  // acclient.c:759178
int _E1200_2()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_5, "EmissionLimit");
  return atexit(_E1201_9);
}

//----- (006E24B0) --------------------------------------------------------  // acclient.c:759185
int _E1203_2()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_5, "BlastCount");
  return atexit(_E1204_9);
}

//----- (006E24D0) --------------------------------------------------------  // acclient.c:759192
int _E1206_2()
{
  PStringBase<char>::PStringBase<char>(&StartTime_5, "StartTime");
  return atexit(_E1207_9);
}

//----- (006E24F0) --------------------------------------------------------  // acclient.c:759199
int _E1209_2()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_5, "TimeLimit");
  return atexit(_E1210_9);
}

//----- (006E2510) --------------------------------------------------------  // acclient.c:759206
int _E1212_2()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_5, "EmissionDistance");
  return atexit(_E1213_9);
}

//----- (006E2530) --------------------------------------------------------  // acclient.c:759213
int _E1215_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_5, "ParticleSnap");
  return atexit(_E1216_9);
}

//----- (006E2550) --------------------------------------------------------  // acclient.c:759220
int _E1218_2()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_5, "InclusiveShape");
  return atexit(_E1219_9);
}

//----- (006E2570) --------------------------------------------------------  // acclient.c:759227
int _E1221_2()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_5, "NumKeyframes");
  return atexit(_E1222_9);
}

//----- (006E2590) --------------------------------------------------------  // acclient.c:759234
int _E1224_2()
{
  PStringBase<char>::PStringBase<char>(&IsActive_5, "IsActive");
  return atexit(_E1225_9);
}

//----- (006E25B0) --------------------------------------------------------  // acclient.c:759241
int _E1227_2()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_5, "FadeIn");
  return atexit(_E1228_9);
}

//----- (006E25D0) --------------------------------------------------------  // acclient.c:759248
int _E1230_2()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_5, "FadeOut");
  return atexit(_E1231_9);
}

//----- (006E25F0) --------------------------------------------------------  // acclient.c:759255
int _E1233_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_5, "ConstrainX");
  return atexit(_E1234_9);
}

//----- (006E2610) --------------------------------------------------------  // acclient.c:759262
int _E1236_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_5, "ConstrainY");
  return atexit(_E1237_9);
}

//----- (006E2630) --------------------------------------------------------  // acclient.c:759269
int _E1239_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_5, "ConstrainZ");
  return atexit(_E1240_9);
}

//----- (006E2650) --------------------------------------------------------  // acclient.c:759276
int _E1242_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_68, "Keyframe");
  return atexit(_E1243_9);
}

//----- (006E2670) --------------------------------------------------------  // acclient.c:759283
int _E1245_2()
{
  PStringBase<char>::PStringBase<char>(&Time_5, "Time");
  return atexit(_E1246_9);
}

//----- (006E2690) --------------------------------------------------------  // acclient.c:759290
int _E1248_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_5, "Flags");
  return atexit(_E1249_9);
}

//----- (006E26B0) --------------------------------------------------------  // acclient.c:759297
int _E1251_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_5, "None");
  return atexit(_E1252_9);
}

//----- (006E26D0) --------------------------------------------------------  // acclient.c:759304
int _E1254_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_5, "BlendScale");
  return atexit(_E1255_9);
}

//----- (006E26F0) --------------------------------------------------------  // acclient.c:759311
int _E1257_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_5, "BlendColor");
  return atexit(_E1258_8);
}

//----- (006E2710) --------------------------------------------------------  // acclient.c:759318
int _E1260_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_5, "BlendMass");
  return atexit(_E1261_7);
}

//----- (006E2730) --------------------------------------------------------  // acclient.c:759325
int _E1263_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_5, "SetScale");
  return atexit(_E1264_7);
}

//----- (006E2750) --------------------------------------------------------  // acclient.c:759332
int _E1266_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_5, "SetColor");
  return atexit(_E1267_7);
}

//----- (006E2770) --------------------------------------------------------  // acclient.c:759339
int _E1269_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_5, "SetMass");
  return atexit(_E1270_7);
}

//----- (006E2790) --------------------------------------------------------  // acclient.c:759346
int _E1272_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_5, "SetParticleFlags");
  return atexit(_E1273_7);
}

//----- (006E27B0) --------------------------------------------------------  // acclient.c:759353
int _E1275_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_5, "SetControllerType");
  return atexit(_E1276_8);
}

//----- (006E27D0) --------------------------------------------------------  // acclient.c:759360
int _E1278_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_5, "SetPhysicsFlags");
  return atexit(_E1279_7);
}

//----- (006E27F0) --------------------------------------------------------  // acclient.c:759367
int _E1281_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_5, "SetParams");
  return atexit(_E1282_8);
}

//----- (006E2810) --------------------------------------------------------  // acclient.c:759374
int _E1284_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_19, "Scale");
  return atexit(_E1285_7);
}

//----- (006E2830) --------------------------------------------------------  // acclient.c:759381
int _E1287_2()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_5, "ScaleX");
  return atexit(_E1288_7);
}

//----- (006E2850) --------------------------------------------------------  // acclient.c:759388
int _E1290_3()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_5, "ScaleY");
  return atexit(_E1291_6);
}

//----- (006E2870) --------------------------------------------------------  // acclient.c:759395
int _E1293_2()
{
  PStringBase<char>::PStringBase<char>(&Color_5, "Color");
  return atexit(_E1294_7);
}

//----- (006E2890) --------------------------------------------------------  // acclient.c:759402
int _E1296_3()
{
  PStringBase<char>::PStringBase<char>(&Mass_5, "Mass");
  return atexit(_E1297_7);
}

//----- (006E28B0) --------------------------------------------------------  // acclient.c:759409
int _E1299_3()
{
  PStringBase<char>::PStringBase<char>(&PFlags_5, "ParticleFlags");
  return atexit(_E1300_7);
}

//----- (006E28D0) --------------------------------------------------------  // acclient.c:759416
int _E1302_3()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_5, "None");
  return atexit(_E1303_6);
}

//----- (006E28F0) --------------------------------------------------------  // acclient.c:759423
int _E1305_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_5, "ControllerType");
  return atexit(_E1306_5);
}

//----- (006E2910) --------------------------------------------------------  // acclient.c:759430
int _E1308_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_5, "None");
  return atexit(_E1309_5);
}

//----- (006E2930) --------------------------------------------------------  // acclient.c:759437
int _E1311_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_5, "Physics");
  return atexit(_E1312_5);
}

//----- (006E2950) --------------------------------------------------------  // acclient.c:759444
int _E1314_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_5, "Parametric");
  return atexit(_E1315_3);
}

//----- (006E2970) --------------------------------------------------------  // acclient.c:759451
int _E1317_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_5, "AttractRepulse");
  return atexit(_E1318_3);
}

//----- (006E2990) --------------------------------------------------------  // acclient.c:759458
int _E1320_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_5, "PointFile");
  return atexit(_E1321_3);
}

//----- (006E29B0) --------------------------------------------------------  // acclient.c:759465
int _E1323_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_5, "PointFileLerp");
  return atexit(_E1324_3);
}

//----- (006E29D0) --------------------------------------------------------  // acclient.c:759472
int _E1326_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_5, "PhysicsFlags");
  return atexit(_E1327_3);
}

//----- (006E29F0) --------------------------------------------------------  // acclient.c:759479
int _E1329_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_5, "None");
  return atexit(_E1330_3);
}

//----- (006E2A10) --------------------------------------------------------  // acclient.c:759486
int _E1332_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_5, "Gravity");
  return atexit(_E1333_3);
}

//----- (006E2A30) --------------------------------------------------------  // acclient.c:759493
int _E1335_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_5, "Wind");
  return atexit(_E1336_3);
}

//----- (006E2A50) --------------------------------------------------------  // acclient.c:759500
int _E1338_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_5, "Momentum");
  return atexit(_E1339_3);
}

//----- (006E2A70) --------------------------------------------------------  // acclient.c:759507
int _E1341_3()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_5, "RandomPoint");
  return atexit(_E1342_3);
}

//----- (006E2A90) --------------------------------------------------------  // acclient.c:759514
int _E1344_3()
{
  PStringBase<char>::PStringBase<char>(&Position_6, "Position");
  return atexit(_E1345_3);
}

//----- (006E2AB0) --------------------------------------------------------  // acclient.c:759521
int _E1347_3()
{
  PStringBase<char>::PStringBase<char>(&PointList_5, "PointList");
  return atexit(_E1348_3);
}

//----- (006E2AD0) --------------------------------------------------------  // acclient.c:759528
int _E1350_3()
{
  PStringBase<char>::PStringBase<char>(&Point_12, "pt");
  return atexit(_E1351_3);
}

//----- (006E2AF0) --------------------------------------------------------  // acclient.c:759535
int _E1353_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_5, "DetailLevels");
  return atexit(_E1354_3);
}

//----- (006E2B10) --------------------------------------------------------  // acclient.c:759542
int _E1356_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_5, "Low");
  return atexit(_E1357_3);
}

//----- (006E2B30) --------------------------------------------------------  // acclient.c:759549
int _E1359_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_5, "Medium");
  return atexit(_E1360_3);
}

//----- (006E2B50) --------------------------------------------------------  // acclient.c:759556
int _E1362_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_5, "High");
  return atexit(_E1363_3);
}

//----- (006E2B70) --------------------------------------------------------  // acclient.c:759563
int _E1365_3()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_5, "FadeSpeed");
  return atexit(_E1366_3);
}

//----- (006E2B90) --------------------------------------------------------  // acclient.c:759570
int _E1368_3()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_5, "MaxOpacity");
  return atexit(_E1369_3);
}

//----- (006E2BB0) --------------------------------------------------------  // acclient.c:759577
int _E1371_3()
{
  PStringBase<char>::PStringBase<char>(&Point_13, "Point");
  return atexit(_E1372_3);
}

//----- (006E2BD0) --------------------------------------------------------  // acclient.c:759584
int _E1374_3()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_5, "AxisPos");
  return atexit(_E1375_3);
}

//----- (006E2BF0) --------------------------------------------------------  // acclient.c:759591
int _E1377_3()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_5, "Texture");
  return atexit(_E1378_3);
}

//----- (006E2C10) --------------------------------------------------------  // acclient.c:759598
int _E1380_2()
{
  PStringBase<char>::PStringBase<char>(&PointSize_5, "Size");
  return atexit(_E1381_2);
}

//----- (006E2C30) --------------------------------------------------------  // acclient.c:759605
int _E1383_2()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_5, "UseOcclusion");
  return atexit(_E1384_2);
}

//----- (006E2C50) --------------------------------------------------------  // acclient.c:759612
int _E1_45()
{
  return atexit(_E2_45);
}

//----- (0074CF60) --------------------------------------------------------  // acclient.c:867191
void __cdecl _E202_39()
{
  char *v0; // esi@1

  v0 = &PHeader_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CF90) --------------------------------------------------------  // acclient.c:867204
void __cdecl _E205_36()
{
  char *v0; // esi@1

  v0 = &VertexArray_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CFC0) --------------------------------------------------------  // acclient.c:867217
void __cdecl _E208_40()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074CFF0) --------------------------------------------------------  // acclient.c:867230
void __cdecl _E211_36()
{
  char *v0; // esi@1

  v0 = &VertexType_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D020) --------------------------------------------------------  // acclient.c:867243
void __cdecl _E214_39()
{
  char *v0; // esi@1

  v0 = &VertexData_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D050) --------------------------------------------------------  // acclient.c:867256
void __cdecl _E217_35()
{
  char *v0; // esi@1

  v0 = &Vertex_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D080) --------------------------------------------------------  // acclient.c:867269
void __cdecl _E220_35()
{
  char *v0; // esi@1

  v0 = &Index_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D0B0) --------------------------------------------------------  // acclient.c:867282
void __cdecl _E223_35()
{
  char *v0; // esi@1

  v0 = &Origin_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D0E0) --------------------------------------------------------  // acclient.c:867295
void __cdecl _E226_21()
{
  char *v0; // esi@1

  v0 = &Normal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D110) --------------------------------------------------------  // acclient.c:867308
void __cdecl _E229_21()
{
  char *v0; // esi@1

  v0 = &Diffuse_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D140) --------------------------------------------------------  // acclient.c:867321
void __cdecl _E232_21()
{
  char *v0; // esi@1

  v0 = &Specular_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D170) --------------------------------------------------------  // acclient.c:867334
void __cdecl _E235_21()
{
  char *v0; // esi@1

  v0 = &UVS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D1A0) --------------------------------------------------------  // acclient.c:867347
void __cdecl _E238_19()
{
  char *v0; // esi@1

  v0 = &VectorS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D1D0) --------------------------------------------------------  // acclient.c:867360
void __cdecl _E241_19()
{
  char *v0; // esi@1

  v0 = &VectorT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D200) --------------------------------------------------------  // acclient.c:867373
void __cdecl _E244_19()
{
  char *v0; // esi@1

  v0 = &VectorSxT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D230) --------------------------------------------------------  // acclient.c:867386
void __cdecl _E247_18()
{
  char *v0; // esi@1

  v0 = &Weights_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D260) --------------------------------------------------------  // acclient.c:867399
void __cdecl _E250_18()
{
  char *v0; // esi@1

  v0 = &Importance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D290) --------------------------------------------------------  // acclient.c:867412
void __cdecl _E253_18()
{
  char *v0; // esi@1

  v0 = &PhysMtl_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D2C0) --------------------------------------------------------  // acclient.c:867425
void __cdecl _E256_18()
{
  char *v0; // esi@1

  v0 = &Material_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D2F0) --------------------------------------------------------  // acclient.c:867438
void __cdecl _E259_19()
{
  char *v0; // esi@1

  v0 = &ID_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D320) --------------------------------------------------------  // acclient.c:867451
void __cdecl _E262_19()
{
  char *v0; // esi@1

  v0 = &FileName_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D350) --------------------------------------------------------  // acclient.c:867464
void __cdecl _E265_19()
{
  char *v0; // esi@1

  v0 = &Polygon_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D380) --------------------------------------------------------  // acclient.c:867477
void __cdecl _E268_18()
{
  char *v0; // esi@1

  v0 = &ID_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D3B0) --------------------------------------------------------  // acclient.c:867490
void __cdecl _E271_17()
{
  char *v0; // esi@1

  v0 = &Indices_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D3E0) --------------------------------------------------------  // acclient.c:867503
void __cdecl _E274_17()
{
  char *v0; // esi@1

  v0 = &MaterialID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D410) --------------------------------------------------------  // acclient.c:867516
void __cdecl _E277_17()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D440) --------------------------------------------------------  // acclient.c:867529
void __cdecl _E280_16()
{
  char *v0; // esi@1

  v0 = &Markings_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D470) --------------------------------------------------------  // acclient.c:867542
void __cdecl _E283_16()
{
  char *v0; // esi@1

  v0 = &Material_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D4A0) --------------------------------------------------------  // acclient.c:867555
void __cdecl _E286_15()
{
  char *v0; // esi@1

  v0 = &Index_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D4D0) --------------------------------------------------------  // acclient.c:867568
void __cdecl _E289_14()
{
  char *v0; // esi@1

  v0 = &Filename_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D500) --------------------------------------------------------  // acclient.c:867581
void __cdecl _E292_15()
{
  char *v0; // esi@1

  v0 = &Surface_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D530) --------------------------------------------------------  // acclient.c:867594
void __cdecl _E295_14()
{
  char *v0; // esi@1

  v0 = &CellPoly_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D560) --------------------------------------------------------  // acclient.c:867607
void __cdecl _E298_15()
{
  char *v0; // esi@1

  v0 = &Sphere_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D590) --------------------------------------------------------  // acclient.c:867620
void __cdecl _E301_13()
{
  char *v0; // esi@1

  v0 = &Side_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D5C0) --------------------------------------------------------  // acclient.c:867633
void __cdecl _E304_14()
{
  char *v0; // esi@1

  v0 = &Positive_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D5F0) --------------------------------------------------------  // acclient.c:867646
void __cdecl _E307_13()
{
  char *v0; // esi@1

  v0 = &Negative_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D620) --------------------------------------------------------  // acclient.c:867659
void __cdecl _E310_14()
{
  char *v0; // esi@1

  v0 = &Polygon_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D650) --------------------------------------------------------  // acclient.c:867672
void __cdecl _E313_13()
{
  char *v0; // esi@1

  v0 = &OtherCell_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D680) --------------------------------------------------------  // acclient.c:867685
void __cdecl _E316_14()
{
  char *v0; // esi@1

  v0 = &CellPortal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D6B0) --------------------------------------------------------  // acclient.c:867698
void __cdecl _E319_13()
{
  char *v0; // esi@1

  v0 = &Portal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D6E0) --------------------------------------------------------  // acclient.c:867711
void __cdecl _E322_13()
{
  char *v0; // esi@1

  v0 = &OtherCell_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D710) --------------------------------------------------------  // acclient.c:867724
void __cdecl _E325_12()
{
  char *v0; // esi@1

  v0 = &OtherPortal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D740) --------------------------------------------------------  // acclient.c:867737
void __cdecl _E328_13()
{
  char *v0; // esi@1

  v0 = &ExactMatch_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D770) --------------------------------------------------------  // acclient.c:867750
void __cdecl _E331_12()
{
  char *v0; // esi@1

  v0 = &StabList_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D7A0) --------------------------------------------------------  // acclient.c:867763
void __cdecl _E334_12()
{
  char *v0; // esi@1

  v0 = &Period_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D7D0) --------------------------------------------------------  // acclient.c:867776
void __cdecl _E337_12()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D800) --------------------------------------------------------  // acclient.c:867789
void __cdecl _E340_12()
{
  char *v0; // esi@1

  v0 = &Transform_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D830) --------------------------------------------------------  // acclient.c:867802
void __cdecl _E343_9()
{
  char *v0; // esi@1

  v0 = &Scale_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D860) --------------------------------------------------------  // acclient.c:867815
void __cdecl _E346_9()
{
  char *v0; // esi@1

  v0 = &Weight_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D890) --------------------------------------------------------  // acclient.c:867828
void __cdecl _E349_9()
{
  char *v0; // esi@1

  v0 = &Offset_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D8C0) --------------------------------------------------------  // acclient.c:867841
void __cdecl _E352_9()
{
  char *v0; // esi@1

  v0 = &Quaternion_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D8F0) --------------------------------------------------------  // acclient.c:867854
void __cdecl _E355_9()
{
  char *v0; // esi@1

  v0 = &Rotation_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D920) --------------------------------------------------------  // acclient.c:867867
void __cdecl _E358_9()
{
  char *v0; // esi@1

  v0 = &STime_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D950) --------------------------------------------------------  // acclient.c:867880
void __cdecl _E361_9()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D980) --------------------------------------------------------  // acclient.c:867893
void __cdecl _E364_9()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D9B0) --------------------------------------------------------  // acclient.c:867906
void __cdecl _E367_9()
{
  char *v0; // esi@1

  v0 = &LowPt_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074D9E0) --------------------------------------------------------  // acclient.c:867919
void __cdecl _E370_9()
{
  char *v0; // esi@1

  v0 = &Radius_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DA10) --------------------------------------------------------  // acclient.c:867932
void __cdecl _E373_9()
{
  char *v0; // esi@1

  v0 = &Height_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DA40) --------------------------------------------------------  // acclient.c:867945
void __cdecl _E376_9()
{
  char *v0; // esi@1

  v0 = &Texture2D_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DA70) --------------------------------------------------------  // acclient.c:867958
void __cdecl _E379_9()
{
  char *v0; // esi@1

  v0 = &Texture3D_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DAA0) --------------------------------------------------------  // acclient.c:867971
void __cdecl _E382_9()
{
  char *v0; // esi@1

  v0 = &TextureCube_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DAD0) --------------------------------------------------------  // acclient.c:867984
void __cdecl _E385_9()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DB00) --------------------------------------------------------  // acclient.c:867997
void __cdecl _E388_9()
{
  char *v0; // esi@1

  v0 = &MovieFileName_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DB30) --------------------------------------------------------  // acclient.c:868010
void __cdecl _E391_9()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DB60) --------------------------------------------------------  // acclient.c:868023
void __cdecl _E394_9()
{
  char *v0; // esi@1

  v0 = &Levels_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DB90) --------------------------------------------------------  // acclient.c:868036
void __cdecl _E397_9()
{
  char *v0; // esi@1

  v0 = &NodeName_59.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_59.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DBC0) --------------------------------------------------------  // acclient.c:868049
void __cdecl _E400_9()
{
  char *v0; // esi@1

  v0 = &Material_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DBF0) --------------------------------------------------------  // acclient.c:868062
void __cdecl _E403_9()
{
  char *v0; // esi@1

  v0 = &MaterialType_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DC20) --------------------------------------------------------  // acclient.c:868075
void __cdecl _E406_9()
{
  char *v0; // esi@1

  v0 = &Modifier_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DC50) --------------------------------------------------------  // acclient.c:868088
void __cdecl _E409_9()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DC80) --------------------------------------------------------  // acclient.c:868101
void __cdecl _E412_9()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DCB0) --------------------------------------------------------  // acclient.c:868114
void __cdecl _E415_9()
{
  char *v0; // esi@1

  v0 = &NodeName_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DCE0) --------------------------------------------------------  // acclient.c:868127
void __cdecl _E418_9()
{
  char *v0; // esi@1

  v0 = &SortMode_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DD10) --------------------------------------------------------  // acclient.c:868140
void __cdecl _E421_9()
{
  char *v0; // esi@1

  v0 = &SortMode_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DD40) --------------------------------------------------------  // acclient.c:868153
void __cdecl _E424_9()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DD70) --------------------------------------------------------  // acclient.c:868166
void __cdecl _E427_9()
{
  char *v0; // esi@1

  v0 = &NodeName_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DDA0) --------------------------------------------------------  // acclient.c:868179
void __cdecl _E430_9()
{
  char *v0; // esi@1

  v0 = &NodeName_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DDD0) --------------------------------------------------------  // acclient.c:868192
void __cdecl _E433_9()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DE00) --------------------------------------------------------  // acclient.c:868205
void __cdecl _E436_9()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DE30) --------------------------------------------------------  // acclient.c:868218
void __cdecl _E439_9()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DE60) --------------------------------------------------------  // acclient.c:868231
void __cdecl _E442_9()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DE90) --------------------------------------------------------  // acclient.c:868244
void __cdecl _E445_9()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DEC0) --------------------------------------------------------  // acclient.c:868257
void __cdecl _E448_9()
{
  char *v0; // esi@1

  v0 = &NodeName_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DEF0) --------------------------------------------------------  // acclient.c:868270
void __cdecl _E451_9()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DF20) --------------------------------------------------------  // acclient.c:868283
void __cdecl _E454_9()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DF50) --------------------------------------------------------  // acclient.c:868296
void __cdecl _E457_9()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DF80) --------------------------------------------------------  // acclient.c:868309
void __cdecl _E460_9()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DFB0) --------------------------------------------------------  // acclient.c:868322
void __cdecl _E463_9()
{
  char *v0; // esi@1

  v0 = &TrueFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074DFE0) --------------------------------------------------------  // acclient.c:868335
void __cdecl _E466_9()
{
  char *v0; // esi@1

  v0 = &FalseFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E010) --------------------------------------------------------  // acclient.c:868348
void __cdecl _E469_9()
{
  char *v0; // esi@1

  v0 = &RenderPass_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E040) --------------------------------------------------------  // acclient.c:868361
void __cdecl _E472_9()
{
  char *v0; // esi@1

  v0 = &Blend_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E070) --------------------------------------------------------  // acclient.c:868374
void __cdecl _E475_9()
{
  char *v0; // esi@1

  v0 = &DepthTest_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E0A0) --------------------------------------------------------  // acclient.c:868387
void __cdecl _E478_9()
{
  char *v0; // esi@1

  v0 = &DepthWrite_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E0D0) --------------------------------------------------------  // acclient.c:868400
void __cdecl _E481_9()
{
  char *v0; // esi@1

  v0 = &CullMode_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E100) --------------------------------------------------------  // acclient.c:868413
void __cdecl _E484_9()
{
  char *v0; // esi@1

  v0 = &DepthFog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E130) --------------------------------------------------------  // acclient.c:868426
void __cdecl _E487_9()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E160) --------------------------------------------------------  // acclient.c:868439
void __cdecl _E490_9()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E190) --------------------------------------------------------  // acclient.c:868452
void __cdecl _E493_9()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E1C0) --------------------------------------------------------  // acclient.c:868465
void __cdecl _E496_9()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E1F0) --------------------------------------------------------  // acclient.c:868478
void __cdecl _E499_9()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E220) --------------------------------------------------------  // acclient.c:868491
void __cdecl _E502_9()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E250) --------------------------------------------------------  // acclient.c:868504
void __cdecl _E505_9()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E280) --------------------------------------------------------  // acclient.c:868517
void __cdecl _E508_9()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E2B0) --------------------------------------------------------  // acclient.c:868530
void __cdecl _E511_9()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E2E0) --------------------------------------------------------  // acclient.c:868543
void __cdecl _E514_9()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E310) --------------------------------------------------------  // acclient.c:868556
void __cdecl _E517_9()
{
  char *v0; // esi@1

  v0 = &Ambient_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E340) --------------------------------------------------------  // acclient.c:868569
void __cdecl _E520_9()
{
  char *v0; // esi@1

  v0 = &Diffuse_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E370) --------------------------------------------------------  // acclient.c:868582
void __cdecl _E523_9()
{
  char *v0; // esi@1

  v0 = &Specular_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E3A0) --------------------------------------------------------  // acclient.c:868595
void __cdecl _E526_9()
{
  char *v0; // esi@1

  v0 = &SpecularPower_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E3D0) --------------------------------------------------------  // acclient.c:868608
void __cdecl _E529_9()
{
  char *v0; // esi@1

  v0 = &Dye_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E400) --------------------------------------------------------  // acclient.c:868621
void __cdecl _E532_9()
{
  char *v0; // esi@1

  v0 = &Emissive_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E430) --------------------------------------------------------  // acclient.c:868634
void __cdecl _E535_9()
{
  char *v0; // esi@1

  v0 = &VertexFormat_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E460) --------------------------------------------------------  // acclient.c:868647
void __cdecl _E538_9()
{
  char *v0; // esi@1

  v0 = &VertexShader_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E490) --------------------------------------------------------  // acclient.c:868660
void __cdecl _E541_9()
{
  char *v0; // esi@1

  v0 = &PixelShader_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E4C0) --------------------------------------------------------  // acclient.c:868673
void __cdecl _E544_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E4F0) --------------------------------------------------------  // acclient.c:868686
void __cdecl _E547_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E520) --------------------------------------------------------  // acclient.c:868699
void __cdecl _E550_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E550) --------------------------------------------------------  // acclient.c:868712
void __cdecl _E553_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E580) --------------------------------------------------------  // acclient.c:868725
void __cdecl _E556_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E5B0) --------------------------------------------------------  // acclient.c:868738
void __cdecl _E559_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E5E0) --------------------------------------------------------  // acclient.c:868751
void __cdecl _E562_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E610) --------------------------------------------------------  // acclient.c:868764
void __cdecl _E565_9()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E640) --------------------------------------------------------  // acclient.c:868777
void __cdecl _E568_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E670) --------------------------------------------------------  // acclient.c:868790
void __cdecl _E571_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E6A0) --------------------------------------------------------  // acclient.c:868803
void __cdecl _E574_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E6D0) --------------------------------------------------------  // acclient.c:868816
void __cdecl _E577_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E700) --------------------------------------------------------  // acclient.c:868829
void __cdecl _E580_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E730) --------------------------------------------------------  // acclient.c:868842
void __cdecl _E583_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E760) --------------------------------------------------------  // acclient.c:868855
void __cdecl _E586_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E790) --------------------------------------------------------  // acclient.c:868868
void __cdecl _E589_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E7C0) --------------------------------------------------------  // acclient.c:868881
void __cdecl _E592_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E7F0) --------------------------------------------------------  // acclient.c:868894
void __cdecl _E595_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E820) --------------------------------------------------------  // acclient.c:868907
void __cdecl _E598_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E850) --------------------------------------------------------  // acclient.c:868920
void __cdecl _E601_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E880) --------------------------------------------------------  // acclient.c:868933
void __cdecl _E604_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E8B0) --------------------------------------------------------  // acclient.c:868946
void __cdecl _E607_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E8E0) --------------------------------------------------------  // acclient.c:868959
void __cdecl _E610_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E910) --------------------------------------------------------  // acclient.c:868972
void __cdecl _E613_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E940) --------------------------------------------------------  // acclient.c:868985
void __cdecl _E616_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E970) --------------------------------------------------------  // acclient.c:868998
void __cdecl _E619_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E9A0) --------------------------------------------------------  // acclient.c:869011
void __cdecl _E622_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074E9D0) --------------------------------------------------------  // acclient.c:869024
void __cdecl _E625_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EA00) --------------------------------------------------------  // acclient.c:869037
void __cdecl _E628_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EA30) --------------------------------------------------------  // acclient.c:869050
void __cdecl _E631_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EA60) --------------------------------------------------------  // acclient.c:869063
void __cdecl _E634_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EA90) --------------------------------------------------------  // acclient.c:869076
void __cdecl _E637_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EAC0) --------------------------------------------------------  // acclient.c:869089
void __cdecl _E640_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EAF0) --------------------------------------------------------  // acclient.c:869102
void __cdecl _E643_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EB20) --------------------------------------------------------  // acclient.c:869115
void __cdecl _E646_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EB50) --------------------------------------------------------  // acclient.c:869128
void __cdecl _E649_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EB80) --------------------------------------------------------  // acclient.c:869141
void __cdecl _E652_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EBB0) --------------------------------------------------------  // acclient.c:869154
void __cdecl _E655_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EBE0) --------------------------------------------------------  // acclient.c:869167
void __cdecl _E658_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EC10) --------------------------------------------------------  // acclient.c:869180
void __cdecl _E661_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EC40) --------------------------------------------------------  // acclient.c:869193
void __cdecl _E664_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EC70) --------------------------------------------------------  // acclient.c:869206
void __cdecl _E667_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ECA0) --------------------------------------------------------  // acclient.c:869219
void __cdecl _E670_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ECD0) --------------------------------------------------------  // acclient.c:869232
void __cdecl _E673_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ED00) --------------------------------------------------------  // acclient.c:869245
void __cdecl _E676_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ED30) --------------------------------------------------------  // acclient.c:869258
void __cdecl _E679_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ED60) --------------------------------------------------------  // acclient.c:869271
void __cdecl _E682_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ED90) --------------------------------------------------------  // acclient.c:869284
void __cdecl _E685_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EDC0) --------------------------------------------------------  // acclient.c:869297
void __cdecl _E688_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EDF0) --------------------------------------------------------  // acclient.c:869310
void __cdecl _E691_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EE20) --------------------------------------------------------  // acclient.c:869323
void __cdecl _E694_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EE50) --------------------------------------------------------  // acclient.c:869336
void __cdecl _E697_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EE80) --------------------------------------------------------  // acclient.c:869349
void __cdecl _E700_9()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EEB0) --------------------------------------------------------  // acclient.c:869362
void __cdecl _E703_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EEE0) --------------------------------------------------------  // acclient.c:869375
void __cdecl _E706_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EF10) --------------------------------------------------------  // acclient.c:869388
void __cdecl _E709_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EF40) --------------------------------------------------------  // acclient.c:869401
void __cdecl _E712_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EF70) --------------------------------------------------------  // acclient.c:869414
void __cdecl _E715_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EFA0) --------------------------------------------------------  // acclient.c:869427
void __cdecl _E718_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074EFD0) --------------------------------------------------------  // acclient.c:869440
void __cdecl _E721_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F000) --------------------------------------------------------  // acclient.c:869453
void __cdecl _E724_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F030) --------------------------------------------------------  // acclient.c:869466
void __cdecl _E727_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F060) --------------------------------------------------------  // acclient.c:869479
void __cdecl _E730_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F090) --------------------------------------------------------  // acclient.c:869492
void __cdecl _E733_9()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F0C0) --------------------------------------------------------  // acclient.c:869505
void __cdecl _E736_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F0F0) --------------------------------------------------------  // acclient.c:869518
void __cdecl _E739_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F120) --------------------------------------------------------  // acclient.c:869531
void __cdecl _E742_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F150) --------------------------------------------------------  // acclient.c:869544
void __cdecl _E745_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F180) --------------------------------------------------------  // acclient.c:869557
void __cdecl _E748_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F1B0) --------------------------------------------------------  // acclient.c:869570
void __cdecl _E751_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F1E0) --------------------------------------------------------  // acclient.c:869583
void __cdecl _E754_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F210) --------------------------------------------------------  // acclient.c:869596
void __cdecl _E757_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F240) --------------------------------------------------------  // acclient.c:869609
void __cdecl _E760_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F270) --------------------------------------------------------  // acclient.c:869622
void __cdecl _E763_9()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F2A0) --------------------------------------------------------  // acclient.c:869635
void __cdecl _E766_9()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F2D0) --------------------------------------------------------  // acclient.c:869648
void __cdecl _E769_9()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F300) --------------------------------------------------------  // acclient.c:869661
void __cdecl _E772_9()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F330) --------------------------------------------------------  // acclient.c:869674
void __cdecl _E775_9()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F360) --------------------------------------------------------  // acclient.c:869687
void __cdecl _E778_9()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F390) --------------------------------------------------------  // acclient.c:869700
void __cdecl _E781_9()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F3C0) --------------------------------------------------------  // acclient.c:869713
void __cdecl _E784_9()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F3F0) --------------------------------------------------------  // acclient.c:869726
void __cdecl _E787_9()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F420) --------------------------------------------------------  // acclient.c:869739
void __cdecl _E790_9()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F450) --------------------------------------------------------  // acclient.c:869752
void __cdecl _E793_9()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F480) --------------------------------------------------------  // acclient.c:869765
void __cdecl _E796_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F4B0) --------------------------------------------------------  // acclient.c:869778
void __cdecl _E799_9()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F4E0) --------------------------------------------------------  // acclient.c:869791
void __cdecl _E802_9()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F510) --------------------------------------------------------  // acclient.c:869804
void __cdecl _E805_9()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F540) --------------------------------------------------------  // acclient.c:869817
void __cdecl _E808_9()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F570) --------------------------------------------------------  // acclient.c:869830
void __cdecl _E811_9()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F5A0) --------------------------------------------------------  // acclient.c:869843
void __cdecl _E814_9()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F5D0) --------------------------------------------------------  // acclient.c:869856
void __cdecl _E817_9()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F600) --------------------------------------------------------  // acclient.c:869869
void __cdecl _E820_9()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F630) --------------------------------------------------------  // acclient.c:869882
void __cdecl _E823_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F660) --------------------------------------------------------  // acclient.c:869895
void __cdecl _E826_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F690) --------------------------------------------------------  // acclient.c:869908
void __cdecl _E829_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F6C0) --------------------------------------------------------  // acclient.c:869921
void __cdecl _E832_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F6F0) --------------------------------------------------------  // acclient.c:869934
void __cdecl _E835_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F720) --------------------------------------------------------  // acclient.c:869947
void __cdecl _E838_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F750) --------------------------------------------------------  // acclient.c:869960
void __cdecl _E841_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F780) --------------------------------------------------------  // acclient.c:869973
void __cdecl _E844_9()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F7B0) --------------------------------------------------------  // acclient.c:869986
void __cdecl _E847_9()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F7E0) --------------------------------------------------------  // acclient.c:869999
void __cdecl _E850_9()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F810) --------------------------------------------------------  // acclient.c:870012
void __cdecl _E853_9()
{
  char *v0; // esi@1

  v0 = &NodeName_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F840) --------------------------------------------------------  // acclient.c:870025
void __cdecl _E856_9()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F870) --------------------------------------------------------  // acclient.c:870038
void __cdecl _E859_9()
{
  char *v0; // esi@1

  v0 = &SamplerName_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F8A0) --------------------------------------------------------  // acclient.c:870051
void __cdecl _E862_9()
{
  char *v0; // esi@1

  v0 = &Texture_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F8D0) --------------------------------------------------------  // acclient.c:870064
void __cdecl _E865_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F900) --------------------------------------------------------  // acclient.c:870077
void __cdecl _E868_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F930) --------------------------------------------------------  // acclient.c:870090
void __cdecl _E871_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F960) --------------------------------------------------------  // acclient.c:870103
void __cdecl _E874_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F990) --------------------------------------------------------  // acclient.c:870116
void __cdecl _E877_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F9C0) --------------------------------------------------------  // acclient.c:870129
void __cdecl _E880_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074F9F0) --------------------------------------------------------  // acclient.c:870142
void __cdecl _E883_9()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FA20) --------------------------------------------------------  // acclient.c:870155
void __cdecl _E886_9()
{
  char *v0; // esi@1

  v0 = &AddressMode_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FA50) --------------------------------------------------------  // acclient.c:870168
void __cdecl _E889_9()
{
  char *v0; // esi@1

  v0 = &TexFilter_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FA80) --------------------------------------------------------  // acclient.c:870181
void __cdecl _E892_9()
{
  char *v0; // esi@1

  v0 = &ColorOp_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FAB0) --------------------------------------------------------  // acclient.c:870194
void __cdecl _E895_9()
{
  char *v0; // esi@1

  v0 = &ColorArg1_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FAE0) --------------------------------------------------------  // acclient.c:870207
void __cdecl _E898_9()
{
  char *v0; // esi@1

  v0 = &ColorArg2_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FB10) --------------------------------------------------------  // acclient.c:870220
void __cdecl _E901_9()
{
  char *v0; // esi@1

  v0 = &AlphaOp_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FB40) --------------------------------------------------------  // acclient.c:870233
void __cdecl _E904_9()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FB70) --------------------------------------------------------  // acclient.c:870246
void __cdecl _E907_9()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FBA0) --------------------------------------------------------  // acclient.c:870259
void __cdecl _E910_9()
{
  char *v0; // esi@1

  v0 = &TexCoord_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FBD0) --------------------------------------------------------  // acclient.c:870272
void __cdecl _E913_9()
{
  char *v0; // esi@1

  v0 = &UseProjection_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FC00) --------------------------------------------------------  // acclient.c:870285
void __cdecl _E916_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FC30) --------------------------------------------------------  // acclient.c:870298
void __cdecl _E919_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FC60) --------------------------------------------------------  // acclient.c:870311
void __cdecl _E922_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FC90) --------------------------------------------------------  // acclient.c:870324
void __cdecl _E925_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FCC0) --------------------------------------------------------  // acclient.c:870337
void __cdecl _E928_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FCF0) --------------------------------------------------------  // acclient.c:870350
void __cdecl _E931_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FD20) --------------------------------------------------------  // acclient.c:870363
void __cdecl _E934_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FD50) --------------------------------------------------------  // acclient.c:870376
void __cdecl _E937_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FD80) --------------------------------------------------------  // acclient.c:870389
void __cdecl _E940_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FDB0) --------------------------------------------------------  // acclient.c:870402
void __cdecl _E943_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FDE0) --------------------------------------------------------  // acclient.c:870415
void __cdecl _E946_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FE10) --------------------------------------------------------  // acclient.c:870428
void __cdecl _E949_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FE40) --------------------------------------------------------  // acclient.c:870441
void __cdecl _E952_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FE70) --------------------------------------------------------  // acclient.c:870454
void __cdecl _E955_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FEA0) --------------------------------------------------------  // acclient.c:870467
void __cdecl _E958_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FED0) --------------------------------------------------------  // acclient.c:870480
void __cdecl _E961_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FF00) --------------------------------------------------------  // acclient.c:870493
void __cdecl _E964_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FF30) --------------------------------------------------------  // acclient.c:870506
void __cdecl _E967_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FF60) --------------------------------------------------------  // acclient.c:870519
void __cdecl _E970_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FF90) --------------------------------------------------------  // acclient.c:870532
void __cdecl _E973_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FFC0) --------------------------------------------------------  // acclient.c:870545
void __cdecl _E976_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074FFF0) --------------------------------------------------------  // acclient.c:870558
void __cdecl _E979_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750020) --------------------------------------------------------  // acclient.c:870571
void __cdecl _E982_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750050) --------------------------------------------------------  // acclient.c:870584
void __cdecl _E985_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750080) --------------------------------------------------------  // acclient.c:870597
void __cdecl _E988_9()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007500B0) --------------------------------------------------------  // acclient.c:870610
void __cdecl _E991_9()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007500E0) --------------------------------------------------------  // acclient.c:870623
void __cdecl _E994_9()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750110) --------------------------------------------------------  // acclient.c:870636
void __cdecl _E997_9()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750140) --------------------------------------------------------  // acclient.c:870649
void __cdecl _E1000_9()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750170) --------------------------------------------------------  // acclient.c:870662
void __cdecl _E1003_9()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007501A0) --------------------------------------------------------  // acclient.c:870675
void __cdecl _E1006_9()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007501D0) --------------------------------------------------------  // acclient.c:870688
void __cdecl _E1009_9()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750200) --------------------------------------------------------  // acclient.c:870701
void __cdecl _E1012_9()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750230) --------------------------------------------------------  // acclient.c:870714
void __cdecl _E1015_9()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750260) --------------------------------------------------------  // acclient.c:870727
void __cdecl _E1018_9()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750290) --------------------------------------------------------  // acclient.c:870740
void __cdecl _E1021_9()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007502C0) --------------------------------------------------------  // acclient.c:870753
void __cdecl _E1024_9()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007502F0) --------------------------------------------------------  // acclient.c:870766
void __cdecl _E1027_9()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750320) --------------------------------------------------------  // acclient.c:870779
void __cdecl _E1030_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750350) --------------------------------------------------------  // acclient.c:870792
void __cdecl _E1033_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750380) --------------------------------------------------------  // acclient.c:870805
void __cdecl _E1036_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007503B0) --------------------------------------------------------  // acclient.c:870818
void __cdecl _E1039_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007503E0) --------------------------------------------------------  // acclient.c:870831
void __cdecl _E1042_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750410) --------------------------------------------------------  // acclient.c:870844
void __cdecl _E1045_9()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750440) --------------------------------------------------------  // acclient.c:870857
void __cdecl _E1048_9()
{
  char *v0; // esi@1

  v0 = &NodeName_65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_65.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750470) --------------------------------------------------------  // acclient.c:870870
void __cdecl _E1051_9()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007504A0) --------------------------------------------------------  // acclient.c:870883
void __cdecl _E1054_9()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007504D0) --------------------------------------------------------  // acclient.c:870896
void __cdecl _E1057_9()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750500) --------------------------------------------------------  // acclient.c:870909
void __cdecl _E1060_9()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750530) --------------------------------------------------------  // acclient.c:870922
void __cdecl _E1063_9()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750560) --------------------------------------------------------  // acclient.c:870935
void __cdecl _E1066_9()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750590) --------------------------------------------------------  // acclient.c:870948
void __cdecl _E1069_9()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007505C0) --------------------------------------------------------  // acclient.c:870961
void __cdecl _E1072_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007505F0) --------------------------------------------------------  // acclient.c:870974
void __cdecl _E1075_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750620) --------------------------------------------------------  // acclient.c:870987
void __cdecl _E1078_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750650) --------------------------------------------------------  // acclient.c:871000
void __cdecl _E1081_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750680) --------------------------------------------------------  // acclient.c:871013
void __cdecl _E1084_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007506B0) --------------------------------------------------------  // acclient.c:871026
void __cdecl _E1087_9()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007506E0) --------------------------------------------------------  // acclient.c:871039
void __cdecl _E1090_9()
{
  char *v0; // esi@1

  v0 = &NodeName_66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_66.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750710) --------------------------------------------------------  // acclient.c:871052
void __cdecl _E1093_9()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750740) --------------------------------------------------------  // acclient.c:871065
void __cdecl _E1096_9()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750770) --------------------------------------------------------  // acclient.c:871078
void __cdecl _E1099_9()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007507A0) --------------------------------------------------------  // acclient.c:871091
void __cdecl _E1102_9()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007507D0) --------------------------------------------------------  // acclient.c:871104
void __cdecl _E1105_9()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750800) --------------------------------------------------------  // acclient.c:871117
void __cdecl _E1108_9()
{
  char *v0; // esi@1

  v0 = &ScaleType_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750830) --------------------------------------------------------  // acclient.c:871130
void __cdecl _E1111_9()
{
  char *v0; // esi@1

  v0 = &WorldSpace_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750860) --------------------------------------------------------  // acclient.c:871143
void __cdecl _E1114_9()
{
  char *v0; // esi@1

  v0 = &ForceDraw_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750890) --------------------------------------------------------  // acclient.c:871156
void __cdecl _E1117_9()
{
  char *v0; // esi@1

  v0 = &NumEmitters_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007508C0) --------------------------------------------------------  // acclient.c:871169
void __cdecl _E1120_9()
{
  char *v0; // esi@1

  v0 = &Material_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007508F0) --------------------------------------------------------  // acclient.c:871182
void __cdecl _E1123_9()
{
  char *v0; // esi@1

  v0 = &Version_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750920) --------------------------------------------------------  // acclient.c:871195
void __cdecl _E1126_9()
{
  char *v0; // esi@1

  v0 = &MaxParticles_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750950) --------------------------------------------------------  // acclient.c:871208
void __cdecl _E1129_9()
{
  char *v0; // esi@1

  v0 = &NodeName_67.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_67.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750980) --------------------------------------------------------  // acclient.c:871221
void __cdecl _E1132_9()
{
  char *v0; // esi@1

  v0 = &Origin_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007509B0) --------------------------------------------------------  // acclient.c:871234
void __cdecl _E1135_9()
{
  char *v0; // esi@1

  v0 = &Shape_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007509E0) --------------------------------------------------------  // acclient.c:871247
void __cdecl _E1138_9()
{
  char *v0; // esi@1

  v0 = &Shape_Point_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750A10) --------------------------------------------------------  // acclient.c:871260
void __cdecl _E1141_9()
{
  char *v0; // esi@1

  v0 = &Shape_Line_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750A40) --------------------------------------------------------  // acclient.c:871273
void __cdecl _E1144_9()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750A70) --------------------------------------------------------  // acclient.c:871286
void __cdecl _E1147_9()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750AA0) --------------------------------------------------------  // acclient.c:871299
void __cdecl _E1150_9()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750AD0) --------------------------------------------------------  // acclient.c:871312
void __cdecl _E1153_9()
{
  char *v0; // esi@1

  v0 = &ParticleShape_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750B00) --------------------------------------------------------  // acclient.c:871325
void __cdecl _E1156_9()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750B30) --------------------------------------------------------  // acclient.c:871338
void __cdecl _E1159_9()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750B60) --------------------------------------------------------  // acclient.c:871351
void __cdecl _E1162_9()
{
  char *v0; // esi@1

  v0 = &Streak_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750B90) --------------------------------------------------------  // acclient.c:871364
void __cdecl _E1165_9()
{
  char *v0; // esi@1

  v0 = &Rotation_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750BC0) --------------------------------------------------------  // acclient.c:871377
void __cdecl _E1168_9()
{
  char *v0; // esi@1

  v0 = &WorldRotation_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750BF0) --------------------------------------------------------  // acclient.c:871390
void __cdecl _E1171_9()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750C20) --------------------------------------------------------  // acclient.c:871403
void __cdecl _E1174_9()
{
  char *v0; // esi@1

  v0 = &ParticleScale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750C50) --------------------------------------------------------  // acclient.c:871416
void __cdecl _E1177_9()
{
  char *v0; // esi@1

  v0 = &Scale_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750C80) --------------------------------------------------------  // acclient.c:871429
void __cdecl _E1180_9()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750CB0) --------------------------------------------------------  // acclient.c:871442
void __cdecl _E1183_9()
{
  char *v0; // esi@1

  v0 = &BirthRate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750CE0) --------------------------------------------------------  // acclient.c:871455
void __cdecl _E1186_9()
{
  char *v0; // esi@1

  v0 = &Lifespan_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750D10) --------------------------------------------------------  // acclient.c:871468
void __cdecl _E1189_9()
{
  char *v0; // esi@1

  v0 = &Velocity_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750D40) --------------------------------------------------------  // acclient.c:871481
void __cdecl _E1192_9()
{
  char *v0; // esi@1

  v0 = &Direction_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750D70) --------------------------------------------------------  // acclient.c:871494
void __cdecl _E1195_9()
{
  char *v0; // esi@1

  v0 = &MinSpread_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750DA0) --------------------------------------------------------  // acclient.c:871507
void __cdecl _E1198_9()
{
  char *v0; // esi@1

  v0 = &MaxSpread_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750DD0) --------------------------------------------------------  // acclient.c:871520
void __cdecl _E1201_9()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750E00) --------------------------------------------------------  // acclient.c:871533
void __cdecl _E1204_9()
{
  char *v0; // esi@1

  v0 = &BlastCount_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750E30) --------------------------------------------------------  // acclient.c:871546
void __cdecl _E1207_9()
{
  char *v0; // esi@1

  v0 = &StartTime_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750E60) --------------------------------------------------------  // acclient.c:871559
void __cdecl _E1210_9()
{
  char *v0; // esi@1

  v0 = &TimeLimit_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750E90) --------------------------------------------------------  // acclient.c:871572
void __cdecl _E1213_9()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750EC0) --------------------------------------------------------  // acclient.c:871585
void __cdecl _E1216_9()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750EF0) --------------------------------------------------------  // acclient.c:871598
void __cdecl _E1219_9()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750F20) --------------------------------------------------------  // acclient.c:871611
void __cdecl _E1222_9()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750F50) --------------------------------------------------------  // acclient.c:871624
void __cdecl _E1225_9()
{
  char *v0; // esi@1

  v0 = &IsActive_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750F80) --------------------------------------------------------  // acclient.c:871637
void __cdecl _E1228_9()
{
  char *v0; // esi@1

  v0 = &FadeIn_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750FB0) --------------------------------------------------------  // acclient.c:871650
void __cdecl _E1231_9()
{
  char *v0; // esi@1

  v0 = &FadeOut_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00750FE0) --------------------------------------------------------  // acclient.c:871663
void __cdecl _E1234_9()
{
  char *v0; // esi@1

  v0 = &ConstrainX_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751010) --------------------------------------------------------  // acclient.c:871676
void __cdecl _E1237_9()
{
  char *v0; // esi@1

  v0 = &ConstrainY_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751040) --------------------------------------------------------  // acclient.c:871689
void __cdecl _E1240_9()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751070) --------------------------------------------------------  // acclient.c:871702
void __cdecl _E1243_9()
{
  char *v0; // esi@1

  v0 = &NodeName_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007510A0) --------------------------------------------------------  // acclient.c:871715
void __cdecl _E1246_9()
{
  char *v0; // esi@1

  v0 = &Time_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007510D0) --------------------------------------------------------  // acclient.c:871728
void __cdecl _E1249_9()
{
  char *v0; // esi@1

  v0 = &Flags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751100) --------------------------------------------------------  // acclient.c:871741
void __cdecl _E1252_9()
{
  char *v0; // esi@1

  v0 = &Flags_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751130) --------------------------------------------------------  // acclient.c:871754
void __cdecl _E1255_9()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751160) --------------------------------------------------------  // acclient.c:871767
void __cdecl _E1258_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751190) --------------------------------------------------------  // acclient.c:871780
void __cdecl _E1261_7()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007511C0) --------------------------------------------------------  // acclient.c:871793
void __cdecl _E1264_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007511F0) --------------------------------------------------------  // acclient.c:871806
void __cdecl _E1267_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751220) --------------------------------------------------------  // acclient.c:871819
void __cdecl _E1270_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751250) --------------------------------------------------------  // acclient.c:871832
void __cdecl _E1273_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751280) --------------------------------------------------------  // acclient.c:871845
void __cdecl _E1276_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007512B0) --------------------------------------------------------  // acclient.c:871858
void __cdecl _E1279_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007512E0) --------------------------------------------------------  // acclient.c:871871
void __cdecl _E1282_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751310) --------------------------------------------------------  // acclient.c:871884
void __cdecl _E1285_7()
{
  char *v0; // esi@1

  v0 = &Scale_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751340) --------------------------------------------------------  // acclient.c:871897
void __cdecl _E1288_7()
{
  char *v0; // esi@1

  v0 = &ScaleX_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751370) --------------------------------------------------------  // acclient.c:871910
void __cdecl _E1291_6()
{
  char *v0; // esi@1

  v0 = &ScaleY_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007513A0) --------------------------------------------------------  // acclient.c:871923
void __cdecl _E1294_7()
{
  char *v0; // esi@1

  v0 = &Color_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007513D0) --------------------------------------------------------  // acclient.c:871936
void __cdecl _E1297_7()
{
  char *v0; // esi@1

  v0 = &Mass_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751400) --------------------------------------------------------  // acclient.c:871949
void __cdecl _E1300_7()
{
  char *v0; // esi@1

  v0 = &PFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751430) --------------------------------------------------------  // acclient.c:871962
void __cdecl _E1303_6()
{
  char *v0; // esi@1

  v0 = &PFlags_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751460) --------------------------------------------------------  // acclient.c:871975
void __cdecl _E1306_5()
{
  char *v0; // esi@1

  v0 = &PCType_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751490) --------------------------------------------------------  // acclient.c:871988
void __cdecl _E1309_5()
{
  char *v0; // esi@1

  v0 = &PCType_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007514C0) --------------------------------------------------------  // acclient.c:872001
void __cdecl _E1312_5()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007514F0) --------------------------------------------------------  // acclient.c:872014
void __cdecl _E1315_3()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751520) --------------------------------------------------------  // acclient.c:872027
void __cdecl _E1318_3()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751550) --------------------------------------------------------  // acclient.c:872040
void __cdecl _E1321_3()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751580) --------------------------------------------------------  // acclient.c:872053
void __cdecl _E1324_3()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007515B0) --------------------------------------------------------  // acclient.c:872066
void __cdecl _E1327_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007515E0) --------------------------------------------------------  // acclient.c:872079
void __cdecl _E1330_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751610) --------------------------------------------------------  // acclient.c:872092
void __cdecl _E1333_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751640) --------------------------------------------------------  // acclient.c:872105
void __cdecl _E1336_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751670) --------------------------------------------------------  // acclient.c:872118
void __cdecl _E1339_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007516A0) --------------------------------------------------------  // acclient.c:872131
void __cdecl _E1342_3()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007516D0) --------------------------------------------------------  // acclient.c:872144
void __cdecl _E1345_3()
{
  char *v0; // esi@1

  v0 = &Position_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751700) --------------------------------------------------------  // acclient.c:872157
void __cdecl _E1348_3()
{
  char *v0; // esi@1

  v0 = &PointList_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751730) --------------------------------------------------------  // acclient.c:872170
void __cdecl _E1351_3()
{
  char *v0; // esi@1

  v0 = &Point_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751760) --------------------------------------------------------  // acclient.c:872183
void __cdecl _E1354_3()
{
  char *v0; // esi@1

  v0 = &DetailLevels_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751790) --------------------------------------------------------  // acclient.c:872196
void __cdecl _E1357_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007517C0) --------------------------------------------------------  // acclient.c:872209
void __cdecl _E1360_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007517F0) --------------------------------------------------------  // acclient.c:872222
void __cdecl _E1363_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751820) --------------------------------------------------------  // acclient.c:872235
void __cdecl _E1366_3()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751850) --------------------------------------------------------  // acclient.c:872248
void __cdecl _E1369_3()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751880) --------------------------------------------------------  // acclient.c:872261
void __cdecl _E1372_3()
{
  char *v0; // esi@1

  v0 = &Point_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007518B0) --------------------------------------------------------  // acclient.c:872274
void __cdecl _E1375_3()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007518E0) --------------------------------------------------------  // acclient.c:872287
void __cdecl _E1378_3()
{
  char *v0; // esi@1

  v0 = &PointTexture_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751910) --------------------------------------------------------  // acclient.c:872300
void __cdecl _E1381_2()
{
  char *v0; // esi@1

  v0 = &PointSize_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751940) --------------------------------------------------------  // acclient.c:872313
void __cdecl _E1384_2()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751970) --------------------------------------------------------  // acclient.c:872326
void __cdecl sub_751970()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007519A0) --------------------------------------------------------  // acclient.c:872339
void __cdecl sub_7519A0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007519D0) --------------------------------------------------------  // acclient.c:872352
void __cdecl sub_7519D0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751A00) --------------------------------------------------------  // acclient.c:872365
void __cdecl sub_751A00()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751A30) --------------------------------------------------------  // acclient.c:872378
void __cdecl sub_751A30()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751A60) --------------------------------------------------------  // acclient.c:872391
void __cdecl sub_751A60()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751A90) --------------------------------------------------------  // acclient.c:872404
void __cdecl _E127_90()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751AC0) --------------------------------------------------------  // acclient.c:872417
void __cdecl _E130_82()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751AF0) --------------------------------------------------------  // acclient.c:872430
void __cdecl _E133_75()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751B20) --------------------------------------------------------  // acclient.c:872443
void __cdecl _E136_59()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751B50) --------------------------------------------------------  // acclient.c:872456
void __cdecl _E139_60()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751B80) --------------------------------------------------------  // acclient.c:872469
void __cdecl _E142_57()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751BB0) --------------------------------------------------------  // acclient.c:872482
void __cdecl _E145_59()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751BE0) --------------------------------------------------------  // acclient.c:872495
void __cdecl _E148_58()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751C10) --------------------------------------------------------  // acclient.c:872508
void __cdecl _E151_56()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751C40) --------------------------------------------------------  // acclient.c:872521
void __cdecl _E154_57()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751C70) --------------------------------------------------------  // acclient.c:872534
void __cdecl _E157_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_12;
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

//----- (00751CB0) --------------------------------------------------------  // acclient.c:872559
void __cdecl _E160_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_12;
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

//----- (00751CF0) --------------------------------------------------------  // acclient.c:872584
void __cdecl _E163_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_12;
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

//----- (00751D30) --------------------------------------------------------  // acclient.c:872609
void __cdecl _E166_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_12;
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

//----- (00751D70) --------------------------------------------------------  // acclient.c:872634
void __cdecl _E169_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_12;
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

//----- (00751DB0) --------------------------------------------------------  // acclient.c:872659
void __cdecl _E172_49()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_22;
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

//----- (00751DF0) --------------------------------------------------------  // acclient.c:872684
void __cdecl _E175_46()
{
  char *v0; // esi@1

  v0 = &waveform_None_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751E20) --------------------------------------------------------  // acclient.c:872697
void __cdecl _E178_46()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751E50) --------------------------------------------------------  // acclient.c:872710
void __cdecl _E181_46()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751E80) --------------------------------------------------------  // acclient.c:872723
void __cdecl _E184_44()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751EB0) --------------------------------------------------------  // acclient.c:872736
void __cdecl _E187_43()
{
  char *v0; // esi@1

  v0 = &waveform_Square_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751EE0) --------------------------------------------------------  // acclient.c:872749
void __cdecl _E190_44()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751F10) --------------------------------------------------------  // acclient.c:872762
void __cdecl _E193_39()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751F40) --------------------------------------------------------  // acclient.c:872775
void __cdecl _E196_46()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751F70) --------------------------------------------------------  // acclient.c:872788
void __cdecl _E199_38()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

