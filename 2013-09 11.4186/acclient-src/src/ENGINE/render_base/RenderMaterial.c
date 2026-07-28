/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderMaterial
   Object     : ENGINE\render_base\RenderMaterial.obj
   Functions  : 830
   Addresses  : 004492E0 - 0073B630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004492E0) --------------------------------------------------------  // acclient.c:133924
char __thiscall RenderMaterial::CheckOutputField(RenderMaterial *this, PStringBase<char> *propString, RMFieldType fieldType, RMDataType dataType, const unsigned int index1, const unsigned int index2)
{
  unsigned int v6; // eax@1
  MaterialProperty **v7; // ebx@2
  MaterialProperty *v8; // edi@3
  unsigned int v9; // esi@3
  unsigned int v10; // ecx@3
  MaterialField **v11; // edx@4
  MaterialField *v12; // eax@5
  char result; // al@11
  PSRefBufferCharData<char> *v14; // eax@12
  int v15; // esi@13
  PSRefBufferCharData<char> *v16; // eax@16
  unsigned int v17; // [sp+10h] [bp-8h]@1
  unsigned int v18; // [sp+14h] [bp-4h]@1

  v6 = this->properties.properties.m_num;
  v17 = 0;
  v18 = this->properties.properties.m_num;
  if ( v6 )
  {
    v7 = this->properties.properties.m_data;
    while ( 1 )
    {
      v8 = *v7;
      v9 = (*v7)->fields.m_num;
      v10 = 0;
      if ( v9 )
        break;
LABEL_10:
      ++v7;
      ++v17;
      if ( v17 >= v6 )
        goto LABEL_11;
    }
    v11 = v8->fields.m_data;
    while ( 1 )
    {
      v12 = *v11;
      if ( (*v11)->fieldType == fieldType && v12->layerIndex == index1 && v12->tcIndex == index2 )
        break;
      ++v10;
      ++v11;
      if ( v10 >= v9 )
      {
        v6 = v18;
        goto LABEL_10;
      }
    }
    v14 = propString->m_charbuffer;
    if ( propString->m_charbuffer != v8->name.m_charbuffer )
    {
      v15 = (int)&v14[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v14[-1]) )
      {
        if ( v15 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      }
      v16 = v8->name.m_charbuffer;
      propString->m_charbuffer = v8->name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v16[-1]);
    }
    result = 1;
  }
  else
  {
LABEL_11:
    result = 0;
  }
  return result;
}

//----- (004493A0) --------------------------------------------------------  // acclient.c:133997
void __thiscall RenderMaterial::Optimize(RenderMaterial *this)
{
  RenderMaterial *v1; // ebp@1
  bool v2; // dl@1
  unsigned int v3; // ebx@1
  MaterialLayer *v4; // edi@2
  RenderPassType v5; // esi@2
  int v6; // edx@22
  unsigned int v7; // ebx@23
  unsigned int v8; // ecx@23
  unsigned int v9; // eax@23
  unsigned int v10; // edx@23
  char v11; // cl@23
  char v12; // al@23
  unsigned int v13; // edx@40
  int v14; // ecx@40
  unsigned int v15; // eax@40
  bool v16; // al@52
  char HaveHighDetail; // [sp+Ch] [bp-1Ch]@23
  bool LayerMeetsConditions; // [sp+Dh] [bp-1Bh]@23
  bool FoundMultiPassLayer; // [sp+Eh] [bp-1Ah]@1
  bool FoundLitLayer; // [sp+Fh] [bp-19h]@1
  bool FoundCombinedAmbientPassLayer; // [sp+10h] [bp-18h]@1
  bool FoundGlowingLayer; // [sp+11h] [bp-17h]@1
  bool FoundAlphaBlendLayer; // [sp+12h] [bp-16h]@1
  bool FoundVideoPostLayer; // [sp+13h] [bp-15h]@1
  unsigned int ConditionIndex; // [sp+14h] [bp-14h]@22
  unsigned int il; // [sp+18h] [bp-10h]@1
  float MaterialOpacity; // [sp+1Ch] [bp-Ch]@1
  RenderPassType Pass; // [sp+24h] [bp-4h]@2

  v1 = this;
  v2 = 0;
  memset(this->m_LayerIndices, 0xFFu, sizeof(this->m_LayerIndices));
  v3 = 0;
  FoundLitLayer = 0;
  FoundMultiPassLayer = 0;
  FoundCombinedAmbientPassLayer = 0;
  FoundGlowingLayer = 0;
  FoundAlphaBlendLayer = 0;
  FoundVideoPostLayer = 0;
  MaterialOpacity = 1.0;
  il = 0;
  if ( this->layers.m_num )
  {
    do
    {
      v4 = v1->layers.m_data[v3];
      v5 = v4->m_RenderPass;
      Pass = v4->m_RenderPass;
      if ( v4->m_Options & 0x82 || v5 == 1 || v5 == 2 )
        FoundLitLayer = 1;
      if ( v5 == 1 || v5 == 2 )
        FoundMultiPassLayer = 1;
      if ( v5 == 4 || v5 == 5 )
        FoundCombinedAmbientPassLayer = 1;
      if ( v5 == 7 || v5 == 8 )
        FoundGlowingLayer = 1;
      if ( v5 == 10 )
        FoundAlphaBlendLayer = 1;
      if ( v4->m_TrueFlags & 3 )
        FoundVideoPostLayer = 1;
      if ( v4->m_cDiffuse.a < (double)MaterialOpacity )
        MaterialOpacity = v4->m_cDiffuse.a;
      if ( DBCache::IsRunTime() )
      {
        v6 = 0;
        ConditionIndex = 0;
        do
        {
          v7 = v4->m_FalseFlags;
          HaveHighDetail = v6 & 1;
          v8 = v6;
          v9 = v6;
          v10 = v4->m_TrueFlags;
          v11 = (v8 >> 2) & 1;
          v12 = (v9 >> 1) & 1;
          LayerMeetsConditions = 1;
          if ( v10 )
          {
            if ( v10 & 1 && v12 != 1
              || v10 & 2 && v11 != 1
              || v10 & 4 && (v7 = v4->m_FalseFlags, HaveHighDetail != 1)
              || v10 & 8 )
              LayerMeetsConditions = 0;
          }
          if ( v7 && (v7 & 1 && v12 == 1 || v7 & 2 && v11 == 1 || v7 & 4 && HaveHighDetail == 1)
            || !LayerMeetsConditions )
          {
            v13 = ConditionIndex;
          }
          else
          {
            v13 = ConditionIndex;
            v14 = 3 * (ConditionIndex + 8 * v5 + 56);
            v15 = 0;
            while ( *((_BYTE *)&v1->vfptr + v14 + v15) != -1 )
            {
              ++v15;
              if ( v15 >= 3 )
              {
                v5 = Pass;
                goto LABEL_46;
              }
            }
            v5 = Pass;
            *((_BYTE *)&v1->vfptr + v15 + v14) = il;
          }
LABEL_46:
          v6 = v13 + 1;
          ConditionIndex = v6;
        }
        while ( (unsigned int)v6 < 8 );
        v3 = il;
      }
      ++v3;
      il = v3;
    }
    while ( v3 < v1->layers.m_num );
    v2 = FoundMultiPassLayer;
  }
  v1->m_SupportsLighting = FoundLitLayer;
  v1->m_SupportsMultiPassLighting = v2;
  v16 = v2 && FoundCombinedAmbientPassLayer;
  v1->m_SupportsCombinedAmbientPass = v16;
  v1->m_SupportsGlowing = FoundGlowingLayer;
  v1->m_NeedsAlphaBlendPass = FoundAlphaBlendLayer;
  v1->m_UsesVideoPost = FoundVideoPostLayer;
  v1->m_Opacity = MaterialOpacity;
  v1->m_IsOptimized = 1;
}

//----- (004495D0) --------------------------------------------------------  // acclient.c:134130
void __thiscall RenderMaterial::GetSubDataIDs(RenderMaterial *this, QualifiedDataIDArray *id_array)
{
  RenderMaterial *v2; // edi@1
  unsigned int v3; // esi@1
  MaterialProperty *v4; // eax@2
  IDClass<_tagDataID,32,0> v5; // eax@3
  QualifiedDataID *v6; // eax@4
  unsigned int v7; // ebx@6
  int v8; // eax@7
  unsigned int v9; // esi@8
  IDClass<_tagDataID,32,0> v10; // eax@9
  QualifiedDataID *v11; // eax@10
  QualifiedDataID v12; // [sp+10h] [bp-8h]@4

  v2 = this;
  v3 = 0;
  if ( this->properties.properties.m_num )
  {
    do
    {
      v4 = v2->properties.properties.m_data[v3];
      if ( v4->dataType == 3000 )
      {
        v5.id = *(_DWORD *)v4->data;
        if ( v5.id != INVALID_DID_38.id )
        {
          QualifiedDataID::QualifiedDataID(&v12, v5, 0);
          QualifiedDataIDArray::AddQDID(id_array, v6, 0);
        }
      }
      ++v3;
    }
    while ( v3 < v2->properties.properties.m_num );
  }
  v7 = 0;
  if ( v2->layers.m_num )
  {
    do
    {
      v8 = (int)&v2->layers.m_data[v7];
      if ( *(_DWORD *)v8 )
      {
        v9 = 0;
        if ( *(_DWORD *)(*(_DWORD *)v8 + 36) )
        {
          do
          {
            v10.id = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v8 + 28) + 4 * v9) + 8);
            if ( v10.id != INVALID_DID_38.id )
            {
              QualifiedDataID::QualifiedDataID(&v12, v10, 0);
              QualifiedDataIDArray::AddQDID(id_array, v11, 0);
            }
            v8 = (int)&v2->layers.m_data[v7];
            ++v9;
          }
          while ( v9 < *(_DWORD *)(*(_DWORD *)v8 + 36) );
        }
      }
      ++v7;
    }
    while ( v7 < v2->layers.m_num );
  }
}

//----- (004496A0) --------------------------------------------------------  // acclient.c:134196
void __thiscall RenderMaterial::RenderMaterial(RenderMaterial *this)
{
  RenderMaterial *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_38);
  v1->vfptr = (InterfaceVtbl *)&RenderMaterial::vftable;
  MaterialModifier::MaterialModifier(&v1->properties);
  v1->layers.m_data = 0;
  v1->layers.m_sizeAndDeallocate = 0;
  v1->layers.m_num = 0;
  v1->m_MaterialShaderConstantNames.m_data = 0;
  v1->m_MaterialShaderConstantNames.m_sizeAndDeallocate = 0;
  v1->m_MaterialShaderConstantNames.m_num = 0;
  v1->m_MaterialShaderConstants.m_data = 0;
  v1->m_MaterialShaderConstants.m_sizeAndDeallocate = 0;
  v1->m_MaterialShaderConstants.m_num = 0;
  v1->m_IsInstance = 0;
  v1->m_IsOptimized = 0;
  v1->m_SupportsLighting = 0;
  v1->m_SupportsMultiPassLighting = 0;
  v1->m_SupportsCombinedAmbientPass = 0;
  v1->m_SupportsGlowing = 0;
  v1->m_NeedsAlphaBlendPass = 0;
  v1->m_UsesVideoPost = 0;
  LODWORD(v1->m_Opacity) = 1065353216;
  memset(v1->m_LayerIndices, 0xFFu, sizeof(v1->m_LayerIndices));
}
// 79B0B8: using guessed type __int32 (__stdcall *RenderMaterial::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00449740) --------------------------------------------------------  // acclient.c:134227
signed int RenderMaterial::GetDBOType()
{
  return 31;
}

//----- (00449750) --------------------------------------------------------  // acclient.c:134233
bool __thiscall RenderMaterial::ReleaseSubObjects(RenderMaterial *this)
{
  RenderMaterial *v1; // esi@1
  unsigned int v2; // edi@2
  MaterialLayer *v3; // ecx@3
  unsigned int i; // edi@7
  BasePropertyValue *v5; // ecx@8
  bool v6; // zf@9
  bool retval; // [sp+5h] [bp-1h]@1

  v1 = this;
  retval = 1;
  if ( !DBCache::IsRunTime() )
    return retval;
  v2 = 0;
  if ( !v1->layers.m_num )
  {
LABEL_7:
    SmartArray<PStringBase<char>,1>::Reset(&v1->m_MaterialShaderConstantNames);
    for ( i = 0; i < v1->m_MaterialShaderConstants.m_num; ++i )
    {
      v5 = v1->m_MaterialShaderConstants.m_data[i].m_pPropertyValue;
      if ( v5 )
      {
        v6 = v5->m_cRef-- == 1;
        if ( v6 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
        v1->m_MaterialShaderConstants.m_data[i].m_pPropertyValue = 0;
      }
    }
    SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_MaterialShaderConstants);
    return retval;
  }
  while ( 1 )
  {
    v3 = v1->layers.m_data[v2];
    if ( !v3 )
      return 0;
    if ( !MaterialLayer::ReleaseSubObjects(v3) )
      retval = 0;
    ++v2;
    if ( v2 >= v1->layers.m_num )
      goto LABEL_7;
  }
}

//----- (00449810) --------------------------------------------------------  // acclient.c:134280
void __cdecl RenderMaterial::Allocator()
{
  RenderMaterial *v0; // eax@1

  v0 = (RenderMaterial *)operator new(0x4E0u);
  if ( v0 )
    RenderMaterial::RenderMaterial(v0);
}

//----- (00449830) --------------------------------------------------------  // acclient.c:134290
void __thiscall RenderMaterial::End(RenderMaterial *this)
{
  RenderMaterial *v1; // esi@1
  unsigned int v2; // ebx@1
  MaterialLayer **v3; // eax@2
  void *v4; // edi@2
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  int i; // eax@8
  unsigned int j; // edi@10
  BasePropertyValue *v9; // ecx@11
  bool v10; // zf@12

  v1 = this;
  RenderMaterial::ReleaseSubObjects(this);
  v2 = 0;
  if ( v1->layers.m_num )
  {
    do
    {
      v3 = v1->layers.m_data;
      v4 = v3[v2];
      if ( v4 )
      {
        MaterialLayer::~MaterialLayer(v3[v2]);
        operator delete(v4);
      }
      ++v2;
    }
    while ( v2 < v1->layers.m_num );
  }
  v5 = v1->layers.m_sizeAndDeallocate;
  v6 = v1->layers.m_sizeAndDeallocate & 0x80000000;
  v1->layers.m_num = 0;
  if ( v6 == 0x80000000 )
  {
    operator delete[](v1->layers.m_data);
    v1->layers.m_data = 0;
    v1->layers.m_sizeAndDeallocate = 0;
  }
  else if ( v1->layers.m_data )
  {
    for ( i = (v5 & 0x7FFFFFFF) - 1; i >= 0; v1->layers.m_data[i + 1] = 0 )
      --i;
  }
  ((void (__thiscall *)(int))v1->properties.vfptr[2].QueryInterface)(&v1->properties);
  SmartArray<PStringBase<char>,1>::Reset(&v1->m_MaterialShaderConstantNames);
  for ( j = 0; j < v1->m_MaterialShaderConstants.m_num; ++j )
  {
    v9 = v1->m_MaterialShaderConstants.m_data[j].m_pPropertyValue;
    if ( v9 )
    {
      v10 = v9->m_cRef-- == 1;
      if ( v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      v1->m_MaterialShaderConstants.m_data[j].m_pPropertyValue = 0;
    }
  }
  SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_MaterialShaderConstants);
}

//----- (00449920) --------------------------------------------------------  // acclient.c:134352
char __thiscall RenderMaterial::CopyInto(RenderMaterial *this, DBObj *retval)
{
  const bool *v2; // esi@1
  DBObj *v3; // ebp@1
  char result; // al@2
  unsigned int v5; // ebx@6
  SmartArray<LOAD_WEIGHTS,1> *v6; // esi@7
  MaterialShaderConstant *v7; // eax@8
  unsigned int v8; // ebp@8
  unsigned int v9; // eax@8
  unsigned int v10; // edx@9
  unsigned int v11; // ST1C_4@14
  int v17; // edx@17
  LOAD_WEIGHTS *v18; // eax@17
  int v19; // eax@20
  MaterialLayer *v20; // ecx@23
  unsigned int v21; // ebx@24
  int v22; // eax@24
  unsigned int v23; // edx@25
  RenderMaterial *target; // ST20_4@30
  RenderMaterial *v26; // [sp+8h] [bp-18h]@1
  unsigned int il; // [sp+10h] [bp-10h]@20
  int ConstantCopy_4; // [sp+1Ch] [bp-4h]@8

  v2 = (const bool *)&retval[1];
  v26 = this;
  v3 = retval;
  if ( !LOBYTE(retval[1].vfptr) )
  {
    result = ((int (__thiscall *)(MaterialModifier *, bool *))this->properties.vfptr[2].IUnknown_Release)(
               &this->properties,
               &retval[1].m_bLoaded);
    if ( !result )
      return result;
    this = v26;
  }
  if ( !*v2 )
  {
    SmartArray<PStringBase<char>,1>::operator=(
      (SmartArray<PStringBase<char>,1> *)&retval[2].m_numLinks,
      (int)&this->m_MaterialShaderConstantNames);
    this = v26;
  }
  v5 = 0;
  if ( this->m_MaterialShaderConstants.m_num )
  {
    v6 = (SmartArray<LOAD_WEIGHTS,1> *)&retval[3];
    do
    {
      v7 = this->m_MaterialShaderConstants.m_data;
      v8 = v7[v5].m_PropertyType;
      ConstantCopy_4 = ((int (__thiscall *)(BasePropertyValue *))v7[v5].m_pPropertyValue->vfptr[1].__vecDelDtor)(v7[v5].m_pPropertyValue);
      v9 = retval[3].m_dataCategory & 0x7FFFFFFF;
      if ( *(_DWORD *)&retval[3].m_bLoaded < v9 )
        goto LABEL_39;
      v10 = v9 + 1;
      if ( v9 + 1 > 8 )
      {
        if ( v10 <= 0x4000 )
        {
          v11 = v9 + 1;
          __asm { bsr     this, [esp+28h+il] }
          if ( v10 > 1 << _EAX )
            v10 = 2 * (1 << _EAX);
        }
        else if ( v10 & 0x3FFF )
        {
          v10 += 0x4000 - (v10 & 0x3FFF);
        }
      }
      else
      {
        v10 = 8;
      }
      if ( SmartArray<LOAD_UVPAIR,1>::grow(v6, v10) )
      {
LABEL_39:
        v17 = *(_DWORD *)&retval[3].m_bLoaded;
        v18 = v6->m_data;
        v18[v17].matrix_index = v8;
        LODWORD(v18[v17].matrix_weight) = ConstantCopy_4;
        ++*(_DWORD *)&retval[3].m_bLoaded;
      }
      this = v26;
      ++v5;
    }
    while ( v5 < v26->m_MaterialShaderConstants.m_num );
    v3 = retval;
    v2 = (const bool *)&retval[1];
  }
  v19 = 0;
  il = 0;
  if ( this->layers.m_num )
  {
    while ( 1 )
    {
      v20 = this->layers.m_data[v19];
      if ( !v20 )
        break;
      v21 = MaterialLayer::Copy(v20, *v2);
      v22 = (unsigned int)v3[2].m_pLast & 0x7FFFFFFF;
      if ( v3[2].m_pMaintainer < (DBOCache *)v22 )
        goto LABEL_40;
      v23 = v22 + 1;
      if ( (unsigned int)(v22 + 1) > 8 )
      {
        if ( v23 <= 0x4000 )
        {
          target = (RenderMaterial *)(v22 + 1);
          __asm { bsr     this, [esp+28h+target] }
          if ( v23 > 1 << _EAX )
            v23 = 2 * (1 << _EAX);
        }
        else if ( v23 & 0x3FFF )
        {
          v23 += 0x4000 - (v23 & 0x3FFF);
        }
      }
      else
      {
        v23 = 8;
      }
      if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3[2].m_pNext, v23) )
LABEL_40:
        *((_DWORD *)&v3[2].m_pNext->vfptr + (unsigned int)v3[2].m_pMaintainer++) = v21;
      this = v26;
      v19 = il++ + 1;
      if ( il >= v26->layers.m_num )
        goto LABEL_21;
      v2 = (const bool *)&retval[1];
    }
    result = 0;
  }
  else
  {
LABEL_21:
    *(&v3[3].m_bLoaded + 4) = this->m_IsOptimized;
    *(&v3[3].m_bLoaded + 5) = v26->m_SupportsLighting;
    *(&v3[3].m_bLoaded + 6) = v26->m_SupportsMultiPassLighting;
    *(&v3[3].m_bLoaded + 7) = v26->m_SupportsCombinedAmbientPass;
    LOBYTE(v3[3].m_timeStamp) = v26->m_SupportsGlowing;
    BYTE1(v3[3].m_timeStamp) = v26->m_NeedsAlphaBlendPass;
    BYTE2(v3[3].m_timeStamp) = v26->m_UsesVideoPost;
    HIDWORD(v3[3].m_timeStamp) = LODWORD(v26->m_Opacity);
    qmemcpy(&v3[3].m_pNext, v26->m_LayerIndices, 0x438u);
    result = 1;
  }
  return result;
}

//----- (00449BB0) --------------------------------------------------------  // acclient.c:134503
void __thiscall RenderMaterial::Destroy(RenderMaterial *this)
{
  RenderMaterial *v1; // esi@1

  v1 = this;
  RenderMaterial::End(this);
  v1->m_IsInstance = 0;
  v1->m_IsOptimized = 0;
  v1->m_SupportsLighting = 0;
  v1->m_SupportsMultiPassLighting = 0;
  v1->m_SupportsCombinedAmbientPass = 0;
  v1->m_SupportsGlowing = 0;
  v1->m_NeedsAlphaBlendPass = 0;
  v1->m_UsesVideoPost = 0;
  LODWORD(v1->m_Opacity) = 1065353216;
  memset(v1->m_LayerIndices, 0xFFu, sizeof(v1->m_LayerIndices));
}

//----- (00449C10) --------------------------------------------------------  // acclient.c:134522
void __thiscall RenderMaterial::Serialize(RenderMaterial *this, Archive *io_archive)
{
  Archive *v2; // edi@1
  RenderMaterial *v3; // ebx@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@1
  int v6; // eax@5
  MaterialLayer *v7; // eax@7
  MaterialLayer *v8; // eax@8
  MaterialLayer *v9; // ebp@8
  int v10; // eax@12
  unsigned int v11; // eax@13
  unsigned int il; // [sp+4h] [bp-4h]@5
  Archive *io_archivea; // [sp+Ch] [bp+4h]@1

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  ((void (__thiscall *)(int, Archive *))v3->properties.vfptr[1].IUnknown_AddRef)(&v3->properties, io_archive);
  v4 = v3->layers.m_num;
  io_archivea = (Archive *)v3->layers.m_num;
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      io_archivea = *(Archive **)v5;
  }
  v6 = 0;
  il = 0;
  if ( io_archivea )
  {
    do
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v7 = (MaterialLayer *)operator new(0xD8u);
        if ( v7 )
        {
          MaterialLayer::MaterialLayer(v7);
          v9 = v8;
        }
        else
        {
          v9 = 0;
        }
      }
      else
      {
        v9 = v3->layers.m_data[v6];
      }
      MaterialLayer::Serialize(v9, v2);
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v10 = v3->layers.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v3->layers.m_num < v10
          || (v11 = SmartArray<UIChildFramework *,1>::get_new_size(v10 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3->layers, v11)) )
          v3->layers.m_data[v3->layers.m_num++] = v9;
      }
      v6 = il++ + 1;
    }
    while ( il < (unsigned int)io_archivea );
  }
}

//----- (00449D10) --------------------------------------------------------  // acclient.c:134591
void __thiscall RenderMaterial::~RenderMaterial(RenderMaterial *this)
{
  RenderMaterial *v1; // esi@1
  PStringBase<char> *v2; // ecx@4

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&RenderMaterial::vftable;
  RenderMaterial::Destroy(this);
  if ( (v1->m_MaterialShaderConstants.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_MaterialShaderConstants.m_data);
  if ( (v1->m_MaterialShaderConstantNames.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = v1->m_MaterialShaderConstantNames.m_data;
    if ( v2 )
      PStringBase<unsigned short>::vector_deleting_destructor(v2, 3u);
  }
  if ( (v1->layers.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->layers.m_data);
  MaterialModifier::~MaterialModifier(&v1->properties);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79B0B8: using guessed type __int32 (__stdcall *RenderMaterial::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00449D90) --------------------------------------------------------  // acclient.c:134615
bool __thiscall RenderMaterial::GetSubObjects(RenderMaterial *this)
{
  RenderMaterial *v1; // eax@2
  unsigned int v2; // ebp@2
  MaterialLayer **v3; // ecx@3
  void *v4; // esi@3
  unsigned int v5; // ecx@6
  int v6; // edx@6
  int v7; // eax@7
  int v8; // edi@7
  int v9; // ecx@7
  unsigned int v10; // edx@12
  int v11; // ecx@12
  BasePropertyValue *v12; // esi@13
  unsigned int v13; // ebx@13
  MaterialProperty *v14; // ebp@14
  RMDataType v15; // eax@16
  void *v16; // eax@18
  void *v17; // eax@21
  int v18; // eax@25
  unsigned int v19; // edx@26
  unsigned int v25; // edx@34
  MaterialShaderConstant *v26; // eax@34
  char *v27; // edi@35
  unsigned int v28; // edx@39
  unsigned int v29; // esi@40
  MaterialLayer *v30; // ecx@41
  unsigned int v31; // esi@45
  MaterialProperty *v32; // ST14_4@46
  bool retval; // [sp+Dh] [bp-55h]@1
  RenderMaterial *material; // [sp+Eh] [bp-54h]@1
  PStringBase<char> ConstantName; // [sp+12h] [bp-50h]@15
  unsigned int v37; // [sp+16h] [bp-4Ch]@12
  MaterialShaderConstant NewConstant; // [sp+1Ah] [bp-48h]@13
  MaterialModifier originalProps; // [sp+22h] [bp-40h]@2

  material = this;
  retval = 1;
  if ( !DBCache::IsRunTime() )
  {
LABEL_48:
    RenderMaterial::Optimize(material);
    return retval;
  }
  MaterialModifier::MaterialModifier(&originalProps);
  ((void (__thiscall *)(int, MaterialModifier *))material->properties.vfptr[2].IUnknown_Release)(
    &material->properties,
    &originalProps);
  v1 = material;
  v2 = 0;
  if ( material->layers.m_num )
  {
    do
    {
      v3 = v1->layers.m_data;
      v4 = v3[v2];
      if ( *(_BYTE *)v4 & 1 )
      {
        if ( v4 )
        {
          MaterialLayer::~MaterialLayer(v3[v2]);
          operator delete(v4);
          v1 = material;
        }
        v5 = v1->layers.m_num;
        v6 = (int)&v1->layers;
        if ( v2 < v5 )
        {
          v7 = v5 - 1;
          v8 = *(_DWORD *)v6 + 4 * v2;
          v9 = *(_DWORD *)v6 + 4 * (v5 - 1);
          *(_DWORD *)(v6 + 8) = v7;
          if ( v8 < (unsigned int)v9 )
            qmemcpy((void *)v8, (const void *)(v8 + 4), 4 * (((unsigned int)(v9 - v8 - 1) >> 2) + 1));
          *(_DWORD *)(*(_DWORD *)v6 + 4 * *(_DWORD *)(v6 + 8)) = 0;
          v1 = material;
        }
      }
      else
      {
        ++v2;
      }
    }
    while ( v2 < v1->layers.m_num );
  }
  v10 = v1->properties.properties.m_num;
  v11 = 0;
  v37 = 0;
  if ( v10 )
  {
    v12 = NewConstant.m_pPropertyValue;
    v13 = NewConstant.m_PropertyType;
    do
    {
      v14 = v1->properties.properties.m_data[v11];
      if ( v14->m_IsShaderConstant )
      {
        ConstantName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( EnumMapper::GetString(6u, v14->nameID, &ConstantName) )
        {
          SmartArray<PStringBase<char>,1>::AddToEnd(&material->m_MaterialShaderConstantNames, &ConstantName);
          v15 = v14->dataType;
          if ( v15 == 1000 )
          {
            v13 = 11;
            v17 = operator new(0x34u);
            v12 = (BasePropertyValue *)v17;
            if ( v17 )
            {
              *((_DWORD *)v17 + 1) = 1;
              *(_DWORD *)v17 = &WaveformPropertyValue::vftable;
              Waveform::Waveform((Waveform *)((char *)v17 + 8));
              Waveform::SetDefaults((Waveform *)&v12[1]);
            }
            else
            {
              v12 = 0;
            }
            v12->vfptr[47].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v12, (unsigned int)v14->data);
          }
          else if ( v15 == 2000 )
          {
            v13 = 6;
            v16 = operator new(0x18u);
            if ( v16 )
            {
              *((_DWORD *)v16 + 1) = 1;
              *(_DWORD *)v16 = &ColorPropertyValue::vftable;
              *(_OWORD *)((char *)v16 + 8) = RGBAColor_Black_19;
              v12 = (BasePropertyValue *)v16;
              (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v16 + 156))(v16, v14->data);
            }
            else
            {
              v12 = 0;
              (*(void (__thiscall **)(_DWORD, void *))(v0 + 156))(0, v14->data);
            }
          }
          v18 = material->m_MaterialShaderConstants.m_sizeAndDeallocate & 0x7FFFFFFF;
          if ( material->m_MaterialShaderConstants.m_num < v18 )
            goto LABEL_52;
          v19 = v18 + 1;
          if ( (unsigned int)(v18 + 1) > 8 )
          {
            if ( v19 <= 0x4000 )
            {
              NewConstant.m_PropertyType = v18 + 1;
              __asm { bsr     this, [esp+68h+NewConstant.m_PropertyType] }
              if ( v19 > 1 << _EAX )
                v19 = 2 * (1 << _EAX);
            }
            else if ( v19 & 0x3FFF )
            {
              v19 += 0x4000 - (v19 & 0x3FFF);
            }
          }
          else
          {
            v19 = 8;
          }
          if ( SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&material->m_MaterialShaderConstants, v19) )
          {
LABEL_52:
            v25 = material->m_MaterialShaderConstants.m_num;
            v26 = material->m_MaterialShaderConstants.m_data;
            v26[v25].m_PropertyType = v13;
            v26[v25].m_pPropertyValue = v12;
            ++material->m_MaterialShaderConstants.m_num;
          }
        }
        v27 = &ConstantName.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&ConstantName.m_charbuffer[-1]) && v27 )
          (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
        v1 = material;
      }
      v28 = v1->properties.properties.m_num;
      v11 = v37++ + 1;
    }
    while ( v37 < v28 );
  }
  v29 = 0;
  if ( !v1->layers.m_num )
  {
LABEL_45:
    v31 = 0;
    if ( v1->properties.properties.m_num )
    {
      do
      {
        v32 = v1->properties.properties.m_data[v31];
        MaterialProperty::Apply(v32, v1, v32);
        v1 = material;
        ++v31;
      }
      while ( v31 < material->properties.properties.m_num );
    }
    MaterialModifier::~MaterialModifier(&originalProps);
    goto LABEL_48;
  }
  while ( 1 )
  {
    v30 = v1->layers.m_data[v29];
    if ( !v30 )
      break;
    if ( !MaterialLayer::GetSubObjects(v30, &v1->m_MaterialShaderConstantNames) )
      retval = 0;
    v1 = material;
    ++v29;
    if ( v29 >= material->layers.m_num )
      goto LABEL_45;
  }
  MaterialModifier::~MaterialModifier(&originalProps);
  return 0;
}
// 796048: using guessed type int (__thiscall *ColorPropertyValue::vftable)(void *, char);
// 796F88: using guessed type int (__thiscall *WaveformPropertyValue::vftable)(void *, char);

//----- (0044A0C0) --------------------------------------------------------  // acclient.c:134834
char __thiscall RenderMaterial::CheckParseField(RenderMaterial *this, PStringBase<char> *test, RMFieldType fieldType, RMDataType dataType, const unsigned int index1, const unsigned int index2)
{
  RenderMaterial *v6; // ebx@1
  PStringBase<char> *v7; // ecx@1
  PSRefBufferCharData<char> *v8; // eax@1
  bool v9; // zf@1
  PStringBase<char> *v10; // eax@2
  unsigned int v11; // edi@5
  MaterialProperty *v12; // esi@6
  int v13; // esi@10
  int v14; // edx@12
  RMDataType v16; // eax@14
  RMDataType v17; // edx@14
  const unsigned int v18; // ecx@14
  const unsigned int v19; // edx@14
  PStringBase<char> *v20; // esi@14
  PSRefBufferCharData<char> *v21; // eax@16
  PStringBase<char> v22; // [sp-4h] [bp-14h]@5

  test = (PStringBase<char> *)test->m_charbuffer;
  v6 = this;
  InterlockedIncrement((volatile LONG *)&test[-4]);
  v7 = test;
  v8 = test[-1].m_charbuffer;
  v9 = v8 == 0;
  if ( !v8 )
    goto LABEL_10;
  v10 = (PStringBase<char> *)((char *)test + (_DWORD)v8 - 1);
  if ( !v9 )
    v10 = test;
  if ( LOBYTE(v10->m_charbuffer) != 36 )
    goto LABEL_10;
  v22.m_charbuffer = (PSRefBufferCharData<char> *)test;
  PStringBase<char>::allocate_ref_buffer(&v22, 1u);
  v22.m_charbuffer->m_data[0] = 36;
  v22.m_charbuffer->m_data[1] = 0;
  PStringBase<char>::trim((PStringBase<char> *)&test, 1, 0, v22);
  v11 = 0;
  if ( !v6->properties.properties.m_num )
  {
LABEL_9:
    v7 = test;
LABEL_10:
    v13 = (int)&v7[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v7[-4]) )
    {
      if ( v13 )
      {
        v14 = *(_DWORD *)v13;
        v22.m_charbuffer = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(int, signed int))v14)(v13, 1);
      }
    }
    return 0;
  }
  while ( 1 )
  {
    v12 = v6->properties.properties.m_data[v11];
    if ( !__stricmp((const char *)test, v12->name.m_charbuffer->m_data) && dataType == v12->dataType )
      break;
    ++v11;
    if ( v11 >= v6->properties.properties.m_num )
      goto LABEL_9;
  }
  v16 = (RMDataType)operator new(0x10u);
  v17 = dataType;
  *(_DWORD *)v16 = fieldType;
  v18 = index1;
  *(_DWORD *)(v16 + 4) = v17;
  v19 = index2;
  *(_DWORD *)(v16 + 8) = v18;
  *(_DWORD *)(v16 + 12) = v19;
  dataType = v16;
  SmartArray<LayerStage *,1>::InsertOrderedByIndex(
    (SmartArray<EffectInfoRegion *,1> *)&v12->fields,
    (EffectInfoRegion *const *)&dataType,
    v12->fields.m_num);
  v20 = test - 5;
  if ( !InterlockedDecrement((volatile LONG *)&test[-4]) && v20 )
  {
    v21 = v20->m_charbuffer;
    v22.m_charbuffer = (PSRefBufferCharData<char> *)1;
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v21->m_data[0])(v20, 1);
  }
  return 1;
}

//----- (0044A1E0) --------------------------------------------------------  // acclient.c:134922
RenderMaterial *__thiscall RenderMaterial::scalar_deleting_destructor(RenderMaterial *this, unsigned int a2)
{
  RenderMaterial *v2; // esi@1

  v2 = this;
  RenderMaterial::~RenderMaterial(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006D0160) --------------------------------------------------------  // acclient.c:742994
int _E73_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_15, "None");
  return atexit(_E74_34);
}

//----- (006D0180) --------------------------------------------------------  // acclient.c:743001
int _E76_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_15, "Speed");
  return atexit(_E77_49);
}

//----- (006D01A0) --------------------------------------------------------  // acclient.c:743008
int _E79_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_15, "Noise");
  return atexit(_E80_23);
}

//----- (006D01C0) --------------------------------------------------------  // acclient.c:743015
int _E82_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_15, "Sine");
  return atexit(_E83_13);
}

//----- (006D01E0) --------------------------------------------------------  // acclient.c:743022
int _E85_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_15, "Square");
  return atexit(_E86_10);
}

//----- (006D0200) --------------------------------------------------------  // acclient.c:743029
int _E88_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_15, "Bounce");
  return atexit(_E89_21);
}

//----- (006D0220) --------------------------------------------------------  // acclient.c:743036
int _E91_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_15, "Perlin");
  return atexit(_E92_21);
}

//----- (006D0240) --------------------------------------------------------  // acclient.c:743043
int _E94_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_15, "Fractal");
  return atexit(sub_736BC0);
}

//----- (006D0260) --------------------------------------------------------  // acclient.c:743050
int _E97_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_15, "FrameLoop");
  return atexit(_E98_36);
}

//----- (006D0280) --------------------------------------------------------  // acclient.c:743057
void _E100_15()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_17, PFID_A8R8G8B8);
}

//----- (006D0290) --------------------------------------------------------  // acclient.c:743063
int _E118_10()
{
  PStringBase<char>::PStringBase<char>(&PHeader_1, "PREPROC_HEADER");
  return atexit(_E119_60);
}

//----- (006D02B0) --------------------------------------------------------  // acclient.c:743070
int _E121_8()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_1, "VertexArray");
  return atexit(_E122_47);
}

//----- (006D02D0) --------------------------------------------------------  // acclient.c:743077
int _E124_10()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_1, "BinaryVertexArray");
  return atexit(_E125_22);
}

//----- (006D02F0) --------------------------------------------------------  // acclient.c:743084
int _E127_7()
{
  PStringBase<char>::PStringBase<char>(&VertexType_2, "VertexType");
  return atexit(_E128_23);
}

//----- (006D0310) --------------------------------------------------------  // acclient.c:743091
int _E130_8()
{
  PStringBase<char>::PStringBase<char>(&VertexData_1, "VertexData");
  return atexit(_E131_19);
}

//----- (006D0330) --------------------------------------------------------  // acclient.c:743098
int _E133_7()
{
  PStringBase<char>::PStringBase<char>(&Vertex_1, "Vertex");
  return atexit(_E134_18);
}

//----- (006D0350) --------------------------------------------------------  // acclient.c:743105
int _E136_6()
{
  PStringBase<char>::PStringBase<char>(&Index_3, "Index");
  return atexit(_E137_18);
}

//----- (006D0370) --------------------------------------------------------  // acclient.c:743112
int _E139_5()
{
  PStringBase<char>::PStringBase<char>(&Origin_3, "P");
  return atexit(_E140_13);
}

//----- (006D0390) --------------------------------------------------------  // acclient.c:743119
int _E142_5()
{
  PStringBase<char>::PStringBase<char>(&Normal_1, "N");
  return atexit(_E143_14);
}

//----- (006D03B0) --------------------------------------------------------  // acclient.c:743126
int _E145_4()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_3, "Diffuse");
  return atexit(_E146_13);
}

//----- (006D03D0) --------------------------------------------------------  // acclient.c:743133
int _E148_4()
{
  PStringBase<char>::PStringBase<char>(&Specular_3, "Specular");
  return atexit(_E149_13);
}

//----- (006D03F0) --------------------------------------------------------  // acclient.c:743140
int _E151_4()
{
  PStringBase<char>::PStringBase<char>(&UVS_1, "UVS");
  return atexit(_E152_12);
}

//----- (006D0410) --------------------------------------------------------  // acclient.c:743147
int _E154_5()
{
  PStringBase<char>::PStringBase<char>(&VectorS_1, "VectorS");
  return atexit(_E155_10);
}

//----- (006D0430) --------------------------------------------------------  // acclient.c:743154
int _E157_4()
{
  PStringBase<char>::PStringBase<char>(&VectorT_1, "VectorT");
  return atexit(_E158_13);
}

//----- (006D0450) --------------------------------------------------------  // acclient.c:743161
int _E160_5()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_1, "VectorSxT");
  return atexit(_E161_10);
}

//----- (006D0470) --------------------------------------------------------  // acclient.c:743168
int _E163_3()
{
  PStringBase<char>::PStringBase<char>(&Weights_1, "Weights");
  return atexit(_E164_13);
}

//----- (006D0490) --------------------------------------------------------  // acclient.c:743175
int _E166_4()
{
  PStringBase<char>::PStringBase<char>(&Importance_1, "Importance");
  return atexit(_E167_9);
}

//----- (006D04B0) --------------------------------------------------------  // acclient.c:743182
int _E169_2()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_1, "PhysMtl");
  return atexit(_E170_8);
}

//----- (006D04D0) --------------------------------------------------------  // acclient.c:743189
int _E172_2()
{
  PStringBase<char>::PStringBase<char>(&Material_8, "Material");
  return atexit(_E173_7);
}

//----- (006D04F0) --------------------------------------------------------  // acclient.c:743196
int _E175_2()
{
  PStringBase<char>::PStringBase<char>(&ID_4, "ID");
  return atexit(_E176_8);
}

//----- (006D0510) --------------------------------------------------------  // acclient.c:743203
int _E178_2()
{
  PStringBase<char>::PStringBase<char>(&FileName_1, "FileName");
  return atexit(_E179_7);
}

//----- (006D0530) --------------------------------------------------------  // acclient.c:743210
int _E181_2()
{
  PStringBase<char>::PStringBase<char>(&Polygon_3, "Polygon");
  return atexit(_E182_7);
}

//----- (006D0550) --------------------------------------------------------  // acclient.c:743217
int _E184_0()
{
  PStringBase<char>::PStringBase<char>(&ID_5, "ID");
  return atexit(_E185_4);
}

//----- (006D0570) --------------------------------------------------------  // acclient.c:743224
int _E187_0()
{
  PStringBase<char>::PStringBase<char>(&Indices_3, "INDICES");
  return atexit(_E188_5);
}

//----- (006D0590) --------------------------------------------------------  // acclient.c:743231
int _E190_0()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_1, "MaterialID");
  return atexit(_E191_4);
}

//----- (006D05B0) --------------------------------------------------------  // acclient.c:743238
int _E193_0()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_1, "PhysMaterialID");
  return atexit(_E194_11);
}

//----- (006D05D0) --------------------------------------------------------  // acclient.c:743245
int _E196_2()
{
  PStringBase<char>::PStringBase<char>(&Markings_1, "Markings");
  return atexit(_E197_2);
}

//----- (006D05F0) --------------------------------------------------------  // acclient.c:743252
int _E199_0()
{
  PStringBase<char>::PStringBase<char>(&Material_9, "Material");
  return atexit(_E200_7);
}

//----- (006D0610) --------------------------------------------------------  // acclient.c:743259
int _E202_0()
{
  PStringBase<char>::PStringBase<char>(&Index_4, "Index");
  return atexit(_E203_6);
}

//----- (006D0630) --------------------------------------------------------  // acclient.c:743266
int _E205_1()
{
  PStringBase<char>::PStringBase<char>(&Filename_1, "Filename");
  return atexit(_E206_9);
}

//----- (006D0650) --------------------------------------------------------  // acclient.c:743273
int _E208_2()
{
  PStringBase<char>::PStringBase<char>(&Surface_1, "Surface");
  return atexit(_E209_4);
}

//----- (006D0670) --------------------------------------------------------  // acclient.c:743280
int _E211_1()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_1, "CellPoly");
  return atexit(_E212_7);
}

//----- (006D0690) --------------------------------------------------------  // acclient.c:743287
int _E214_1()
{
  PStringBase<char>::PStringBase<char>(&Sphere_2, "Sphere");
  return atexit(_E215_3);
}

//----- (006D06B0) --------------------------------------------------------  // acclient.c:743294
int _E217_1()
{
  PStringBase<char>::PStringBase<char>(&Side_1, "Side");
  return atexit(_E218_4);
}

//----- (006D06D0) --------------------------------------------------------  // acclient.c:743301
int _E220_1()
{
  PStringBase<char>::PStringBase<char>(&Positive_1, "Positive");
  return atexit(_E221_4);
}

//----- (006D06F0) --------------------------------------------------------  // acclient.c:743308
int _E223_1()
{
  PStringBase<char>::PStringBase<char>(&Negative_1, "Negative");
  return atexit(_E224_4);
}

//----- (006D0710) --------------------------------------------------------  // acclient.c:743315
int _E226_1()
{
  PStringBase<char>::PStringBase<char>(&Polygon_4, "PolygonIndex");
  return atexit(_E227_4);
}

//----- (006D0730) --------------------------------------------------------  // acclient.c:743322
int _E229_1()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_3, "OtherCellMeshIndex");
  return atexit(_E230_4);
}

//----- (006D0750) --------------------------------------------------------  // acclient.c:743329
int _E232_1()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_1, "CellPortal");
  return atexit(_E233_3);
}

//----- (006D0770) --------------------------------------------------------  // acclient.c:743336
int _E235_1()
{
  PStringBase<char>::PStringBase<char>(&Portal_2, "PortalIndex");
  return atexit(_E236_3);
}

//----- (006D0790) --------------------------------------------------------  // acclient.c:743343
int _E238_1()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_4, "OtherCellID");
  return atexit(_E239_4);
}

//----- (006D07B0) --------------------------------------------------------  // acclient.c:743350
int _E241_1()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_1, "OtherPortalIndex");
  return atexit(_E242_4);
}

//----- (006D07D0) --------------------------------------------------------  // acclient.c:743357
int _E244_1()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_1, "ExactMatch");
  return atexit(_E245_3);
}

//----- (006D07F0) --------------------------------------------------------  // acclient.c:743364
int _E247_1()
{
  PStringBase<char>::PStringBase<char>(&StabList_1, "StabList");
  return atexit(_E248_3);
}

//----- (006D0810) --------------------------------------------------------  // acclient.c:743371
int _E250_1()
{
  PStringBase<char>::PStringBase<char>(&Period_1, "Period");
  return atexit(_E251_3);
}

//----- (006D0830) --------------------------------------------------------  // acclient.c:743378
int _E253_1()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_1, "GrannyAnimation");
  return atexit(_E254_4);
}

//----- (006D0850) --------------------------------------------------------  // acclient.c:743385
int _E256_1()
{
  PStringBase<char>::PStringBase<char>(&Transform_1, "Transform");
  return atexit(_E257_2);
}

//----- (006D0870) --------------------------------------------------------  // acclient.c:743392
int _E259_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_5, "Scale");
  return atexit(_E260_3);
}

//----- (006D0890) --------------------------------------------------------  // acclient.c:743399
int _E262_1()
{
  PStringBase<char>::PStringBase<char>(&Weight_1, "Weight");
  return atexit(_E263_1);
}

//----- (006D08B0) --------------------------------------------------------  // acclient.c:743406
int _E265_1()
{
  PStringBase<char>::PStringBase<char>(&Offset_1, "Offset");
  return atexit(_E266_1);
}

//----- (006D08D0) --------------------------------------------------------  // acclient.c:743413
int _E268_1()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_2, "Quaternion");
  return atexit(_E269_1);
}

//----- (006D08F0) --------------------------------------------------------  // acclient.c:743420
int _E271_0()
{
  PStringBase<char>::PStringBase<char>(&Rotation_3, "Rotation");
  return atexit(_E272_0);
}

//----- (006D0910) --------------------------------------------------------  // acclient.c:743427
int _E274_0()
{
  PStringBase<char>::PStringBase<char>(&STime_1, "STime");
  return atexit(_E275_0);
}

//----- (006D0930) --------------------------------------------------------  // acclient.c:743434
int _E277_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_1, "PhysicsSplines");
  return atexit(_E278_0);
}

//----- (006D0950) --------------------------------------------------------  // acclient.c:743441
int _E280_0()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_1, "BoneOpacities");
  return atexit(_E281_1);
}

//----- (006D0970) --------------------------------------------------------  // acclient.c:743448
int _E283_0()
{
  PStringBase<char>::PStringBase<char>(&LowPt_1, "LowPoint");
  return atexit(_E284_0);
}

//----- (006D0990) --------------------------------------------------------  // acclient.c:743455
int _E286_0()
{
  PStringBase<char>::PStringBase<char>(&Radius_1, "Radius");
  return atexit(_E287_1);
}

//----- (006D09B0) --------------------------------------------------------  // acclient.c:743462
int _E289_0()
{
  PStringBase<char>::PStringBase<char>(&Height_1, "Height");
  return atexit(_E290_1);
}

//----- (006D09D0) --------------------------------------------------------  // acclient.c:743469
int _E292_0()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_1, "Texture2D");
  return atexit(_E293_0);
}

//----- (006D09F0) --------------------------------------------------------  // acclient.c:743476
int _E295_0()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_1, "Texture3D");
  return atexit(_E296_1);
}

//----- (006D0A10) --------------------------------------------------------  // acclient.c:743483
int _E298_0()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_1, "TextureCube");
  return atexit(_E299);
}

//----- (006D0A30) --------------------------------------------------------  // acclient.c:743490
int _E301()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_1, "TextureMovie2D");
  return atexit(_E302_0);
}

//----- (006D0A50) --------------------------------------------------------  // acclient.c:743497
int _E304()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_1, "MovieFile");
  return atexit(_E305);
}

//----- (006D0A70) --------------------------------------------------------  // acclient.c:743504
int _E307()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_1, "MovieFPS");
  return atexit(_E308_0);
}

//----- (006D0A90) --------------------------------------------------------  // acclient.c:743511
int _E310()
{
  PStringBase<char>::PStringBase<char>(&Levels_1, "Levels");
  return atexit(_E311);
}

//----- (006D0AB0) --------------------------------------------------------  // acclient.c:743518
int _E313()
{
  PStringBase<char>::PStringBase<char>(&NodeName_19, "Instance");
  return atexit(_E314_0);
}

//----- (006D0AD0) --------------------------------------------------------  // acclient.c:743525
int _E316()
{
  PStringBase<char>::PStringBase<char>(&Material_10, "Material");
  return atexit(_E317);
}

//----- (006D0AF0) --------------------------------------------------------  // acclient.c:743532
int _E319()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_1, "MaterialType");
  return atexit(_E320_0);
}

//----- (006D0B10) --------------------------------------------------------  // acclient.c:743539
int _E322()
{
  PStringBase<char>::PStringBase<char>(&Modifier_1, "Modifier");
  return atexit(_E323);
}

//----- (006D0B30) --------------------------------------------------------  // acclient.c:743546
int _E325()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_1, "AllowStencilShadows");
  return atexit(_E326_0);
}

//----- (006D0B50) --------------------------------------------------------  // acclient.c:743553
int _E328()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_1, "DiscardGeometry");
  return atexit(_E329);
}

//----- (006D0B70) --------------------------------------------------------  // acclient.c:743560
int _E331()
{
  PStringBase<char>::PStringBase<char>(&NodeName_20, "Material");
  return atexit(_E332_0);
}

//----- (006D0B90) --------------------------------------------------------  // acclient.c:743567
int _E334()
{
  PStringBase<char>::PStringBase<char>(&SortMode_1, "SortMode");
  return atexit(_E335);
}

//----- (006D0BB0) --------------------------------------------------------  // acclient.c:743574
int _E337()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_1, "None");
  return atexit(_E338);
}

//----- (006D0BD0) --------------------------------------------------------  // acclient.c:743581
int _E340()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_1, "Triangle");
  return atexit(_E341);
}

//----- (006D0BF0) --------------------------------------------------------  // acclient.c:743588
int _E343()
{
  PStringBase<char>::PStringBase<char>(&NodeName_21, "Modifier");
  return atexit(_E344);
}

//----- (006D0C10) --------------------------------------------------------  // acclient.c:743595
int _E346()
{
  PStringBase<char>::PStringBase<char>(&NodeName_22, "Property");
  return atexit(_E347);
}

//----- (006D0C30) --------------------------------------------------------  // acclient.c:743602
int _E349()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_1, "Data");
  return atexit(_E350);
}

//----- (006D0C50) --------------------------------------------------------  // acclient.c:743609
int _E352()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_1, "Waveform");
  return atexit(_E353);
}

//----- (006D0C70) --------------------------------------------------------  // acclient.c:743616
int _E355()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_1, "Color");
  return atexit(_E356);
}

//----- (006D0C90) --------------------------------------------------------  // acclient.c:743623
int _E358()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_1, "Texture");
  return atexit(_E359);
}

//----- (006D0CB0) --------------------------------------------------------  // acclient.c:743630
int _E361()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_1, "Bool");
  return atexit(_E362);
}

//----- (006D0CD0) --------------------------------------------------------  // acclient.c:743637
int _E364()
{
  PStringBase<char>::PStringBase<char>(&NodeName_23, "Layer");
  return atexit(_E365);
}

//----- (006D0CF0) --------------------------------------------------------  // acclient.c:743644
int _E367()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_1, "UVTranslate");
  return atexit(_E368);
}

//----- (006D0D10) --------------------------------------------------------  // acclient.c:743651
int _E370()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_1, "UVRotate");
  return atexit(_E371);
}

//----- (006D0D30) --------------------------------------------------------  // acclient.c:743658
int _E373()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_1, "UVScale");
  return atexit(_E374);
}

//----- (006D0D50) --------------------------------------------------------  // acclient.c:743665
int _E376()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_1, "UVTransform");
  return atexit(_E377);
}

//----- (006D0D70) --------------------------------------------------------  // acclient.c:743672
int _E379()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_1, "TrueFlags");
  return atexit(_E380);
}

//----- (006D0D90) --------------------------------------------------------  // acclient.c:743679
int _E382()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_1, "FalseFlags");
  return atexit(_E383);
}

//----- (006D0DB0) --------------------------------------------------------  // acclient.c:743686
int _E385()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_1, "RenderPass");
  return atexit(_E386);
}

//----- (006D0DD0) --------------------------------------------------------  // acclient.c:743693
int _E388()
{
  PStringBase<char>::PStringBase<char>(&Blend_1, "Blend");
  return atexit(_E389);
}

//----- (006D0DF0) --------------------------------------------------------  // acclient.c:743700
int _E391()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_1, "DepthTest");
  return atexit(_E392);
}

//----- (006D0E10) --------------------------------------------------------  // acclient.c:743707
int _E394()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_1, "DepthWrite");
  return atexit(_E395);
}

//----- (006D0E30) --------------------------------------------------------  // acclient.c:743714
int _E397()
{
  PStringBase<char>::PStringBase<char>(&CullMode_1, "CullMode");
  return atexit(_E398);
}

//----- (006D0E50) --------------------------------------------------------  // acclient.c:743721
int _E400()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_1, "DepthFog");
  return atexit(_E401);
}

//----- (006D0E70) --------------------------------------------------------  // acclient.c:743728
int _E403()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_1, "AlphaTestMode");
  return atexit(_E404);
}

//----- (006D0E90) --------------------------------------------------------  // acclient.c:743735
int _E406()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_1, "AlphaTestRef");
  return atexit(_E407);
}

//----- (006D0EB0) --------------------------------------------------------  // acclient.c:743742
int _E409()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_1, "FFUseLighting");
  return atexit(_E410);
}

//----- (006D0ED0) --------------------------------------------------------  // acclient.c:743749
int _E412()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_1, "FFUseDyeColorInTFactor");
  return atexit(_E413);
}

//----- (006D0EF0) --------------------------------------------------------  // acclient.c:743756
int _E415()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_1, "FFUseSpecularLighting");
  return atexit(_E416);
}

//----- (006D0F10) --------------------------------------------------------  // acclient.c:743763
int _E418()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_1, "FFUseDistanceFog");
  return atexit(_E419);
}

//----- (006D0F30) --------------------------------------------------------  // acclient.c:743770
int _E421()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_1, "FFUseVertexDiffuse");
  return atexit(_E422);
}

//----- (006D0F50) --------------------------------------------------------  // acclient.c:743777
int _E424()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_1, "FFUseVertexSpecular");
  return atexit(_E425);
}

//----- (006D0F70) --------------------------------------------------------  // acclient.c:743784
int _E427()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_1, "ShaderSupportsDynamicLights");
  return atexit(_E428);
}

//----- (006D0F90) --------------------------------------------------------  // acclient.c:743791
int _E430()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_1, "UsesTransparency");
  return atexit(_E431);
}

//----- (006D0FB0) --------------------------------------------------------  // acclient.c:743798
int _E433()
{
  PStringBase<char>::PStringBase<char>(&Ambient_1, "Ambient");
  return atexit(_E434);
}

//----- (006D0FD0) --------------------------------------------------------  // acclient.c:743805
int _E436()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_4, "Diffuse");
  return atexit(_E437);
}

//----- (006D0FF0) --------------------------------------------------------  // acclient.c:743812
int _E439()
{
  PStringBase<char>::PStringBase<char>(&Specular_4, "Specular");
  return atexit(_E440);
}

//----- (006D1010) --------------------------------------------------------  // acclient.c:743819
int _E442()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_1, "SpecularPower");
  return atexit(_E443);
}

//----- (006D1030) --------------------------------------------------------  // acclient.c:743826
int _E445()
{
  PStringBase<char>::PStringBase<char>(&Dye_1, "Dye");
  return atexit(_E446);
}

//----- (006D1050) --------------------------------------------------------  // acclient.c:743833
int _E448()
{
  PStringBase<char>::PStringBase<char>(&Emissive_1, "Emissive");
  return atexit(_E449);
}

//----- (006D1070) --------------------------------------------------------  // acclient.c:743840
int _E451()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_1, "VertexFormat");
  return atexit(_E452);
}

//----- (006D1090) --------------------------------------------------------  // acclient.c:743847
int _E454()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_1, "VertexShader");
  return atexit(_E455);
}

//----- (006D10B0) --------------------------------------------------------  // acclient.c:743854
int _E457()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_1, "PixelShader");
  return atexit(_E458);
}

//----- (006D10D0) --------------------------------------------------------  // acclient.c:743861
int _E460()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_1, "None");
  return atexit(_E461);
}

//----- (006D10F0) --------------------------------------------------------  // acclient.c:743868
int _E463()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_1, "Reflections");
  return atexit(_E464);
}

//----- (006D1110) --------------------------------------------------------  // acclient.c:743875
int _E466()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_1, "VideoPost");
  return atexit(_E467);
}

//----- (006D1130) --------------------------------------------------------  // acclient.c:743882
int _E469()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_1, "HighDetail");
  return atexit(_E470);
}

//----- (006D1150) --------------------------------------------------------  // acclient.c:743889
int _E472()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_1, "Specular");
  return atexit(_E473);
}

//----- (006D1170) --------------------------------------------------------  // acclient.c:743896
int _E475()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_1, "Class1");
  return atexit(_E476);
}

//----- (006D1190) --------------------------------------------------------  // acclient.c:743903
int _E478()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_1, "Class2");
  return atexit(_E479);
}

//----- (006D11B0) --------------------------------------------------------  // acclient.c:743910
int _E481()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_1, "Class3");
  return atexit(_E482);
}

//----- (006D11D0) --------------------------------------------------------  // acclient.c:743917
int _E484()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_1, "Default");
  return atexit(_E485);
}

//----- (006D11F0) --------------------------------------------------------  // acclient.c:743924
int _E487()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_1,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E488);
}

//----- (006D1210) --------------------------------------------------------  // acclient.c:743933
int _E490()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_1, "PointLightDiffuseAndSpecular");
  return atexit(_E491);
}

//----- (006D1230) --------------------------------------------------------  // acclient.c:743940
int _E493()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_1,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E494);
}

//----- (006D1250) --------------------------------------------------------  // acclient.c:743949
int _E496()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_1,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E497);
}

//----- (006D1270) --------------------------------------------------------  // acclient.c:743958
int _E499()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_1,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E500);
}

//----- (006D1290) --------------------------------------------------------  // acclient.c:743967
int _E502()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_1, "DistanceFog");
  return atexit(_E503);
}

//----- (006D12B0) --------------------------------------------------------  // acclient.c:743974
int _E505()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_1, "FFGlow");
  return atexit(_E506);
}

//----- (006D12D0) --------------------------------------------------------  // acclient.c:743981
int _E508()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_1, "ShaderGlow");
  return atexit(_E509);
}

//----- (006D12F0) --------------------------------------------------------  // acclient.c:743988
int _E511()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_1, "LandscapeShadowMap");
  return atexit(_E512);
}

//----- (006D1310) --------------------------------------------------------  // acclient.c:743995
int _E514()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_1, "AlphaBlend");
  return atexit(_E515);
}

//----- (006D1330) --------------------------------------------------------  // acclient.c:744002
int _E517()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_1, "AL_0DL_0PL");
  return atexit(_E518);
}

//----- (006D1350) --------------------------------------------------------  // acclient.c:744009
int _E520()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_1, "AL_0DL_1PL");
  return atexit(_E521);
}

//----- (006D1370) --------------------------------------------------------  // acclient.c:744016
int _E523()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_1, "AL_0DL_2PL");
  return atexit(_E524);
}

//----- (006D1390) --------------------------------------------------------  // acclient.c:744023
int _E526()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_1, "AL_0DL_3PL");
  return atexit(_E527);
}

//----- (006D13B0) --------------------------------------------------------  // acclient.c:744030
int _E529()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_1, "AL_0DL_4PL");
  return atexit(_E530);
}

//----- (006D13D0) --------------------------------------------------------  // acclient.c:744037
int _E532()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_1, "AL_0DL_5PL");
  return atexit(_E533);
}

//----- (006D13F0) --------------------------------------------------------  // acclient.c:744044
int _E535()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_1, "AL_0DL_6PL");
  return atexit(_E536);
}

//----- (006D1410) --------------------------------------------------------  // acclient.c:744051
int _E538()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_1, "AL_0DL_7PL");
  return atexit(_E539);
}

//----- (006D1430) --------------------------------------------------------  // acclient.c:744058
int _E541()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_1, "AL_0DL_8PL");
  return atexit(_E542);
}

//----- (006D1450) --------------------------------------------------------  // acclient.c:744065
int _E544()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_1, "AL_1DL_0PL");
  return atexit(_E545);
}

//----- (006D1470) --------------------------------------------------------  // acclient.c:744072
int _E547()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_1, "AL_1DL_1PL");
  return atexit(_E548);
}

//----- (006D1490) --------------------------------------------------------  // acclient.c:744079
int _E550()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_1, "AL_1DL_2PL");
  return atexit(_E551);
}

//----- (006D14B0) --------------------------------------------------------  // acclient.c:744086
int _E553()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_1, "AL_1DL_3PL");
  return atexit(_E554);
}

//----- (006D14D0) --------------------------------------------------------  // acclient.c:744093
int _E556()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_1, "AL_1DL_4PL");
  return atexit(_E557);
}

//----- (006D14F0) --------------------------------------------------------  // acclient.c:744100
int _E559()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_1, "AL_1DL_5PL");
  return atexit(_E560);
}

//----- (006D1510) --------------------------------------------------------  // acclient.c:744107
int _E562()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_1, "AL_1DL_6PL");
  return atexit(_E563);
}

//----- (006D1530) --------------------------------------------------------  // acclient.c:744114
int _E565()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_1, "AL_1DL_7PL");
  return atexit(_E566);
}

//----- (006D1550) --------------------------------------------------------  // acclient.c:744121
int _E568()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_1, "AL_0DL_0PL_Fog");
  return atexit(_E569);
}

//----- (006D1570) --------------------------------------------------------  // acclient.c:744128
int _E571()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_1, "AL_0DL_1PL_Fog");
  return atexit(_E572);
}

//----- (006D1590) --------------------------------------------------------  // acclient.c:744135
int _E574()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_1, "AL_0DL_2PL_Fog");
  return atexit(_E575);
}

//----- (006D15B0) --------------------------------------------------------  // acclient.c:744142
int _E577()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_1, "AL_0DL_3PL_Fog");
  return atexit(_E578);
}

//----- (006D15D0) --------------------------------------------------------  // acclient.c:744149
int _E580()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_1, "AL_0DL_4PL_Fog");
  return atexit(_E581);
}

//----- (006D15F0) --------------------------------------------------------  // acclient.c:744156
int _E583()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_1, "AL_0DL_5PL_Fog");
  return atexit(_E584);
}

//----- (006D1610) --------------------------------------------------------  // acclient.c:744163
int _E586()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_1, "AL_0DL_6PL_Fog");
  return atexit(_E587);
}

//----- (006D1630) --------------------------------------------------------  // acclient.c:744170
int _E589()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_1, "AL_0DL_7PL_Fog");
  return atexit(_E590);
}

//----- (006D1650) --------------------------------------------------------  // acclient.c:744177
int _E592()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_1, "AL_0DL_8PL_Fog");
  return atexit(_E593);
}

//----- (006D1670) --------------------------------------------------------  // acclient.c:744184
int _E595()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_1, "AL_1DL_0PL_Fog");
  return atexit(_E596);
}

//----- (006D1690) --------------------------------------------------------  // acclient.c:744191
int _E598()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_1, "AL_1DL_1PL_Fog");
  return atexit(_E599);
}

//----- (006D16B0) --------------------------------------------------------  // acclient.c:744198
int _E601()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_1, "AL_1DL_2PL_Fog");
  return atexit(_E602);
}

//----- (006D16D0) --------------------------------------------------------  // acclient.c:744205
int _E604()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_1, "AL_1DL_3PL_Fog");
  return atexit(_E605);
}

//----- (006D16F0) --------------------------------------------------------  // acclient.c:744212
int _E607()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_1, "AL_1DL_4PL_Fog");
  return atexit(_E608);
}

//----- (006D1710) --------------------------------------------------------  // acclient.c:744219
int _E610()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_1, "AL_1DL_5PL_Fog");
  return atexit(_E611);
}

//----- (006D1730) --------------------------------------------------------  // acclient.c:744226
int _E613()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_1, "AL_1DL_6PL_Fog");
  return atexit(_E614);
}

//----- (006D1750) --------------------------------------------------------  // acclient.c:744233
int _E616()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_1, "AL_1DL_7PL_Fog");
  return atexit(_E617);
}

//----- (006D1770) --------------------------------------------------------  // acclient.c:744240
int _E619()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_1, "Zero");
  return atexit(_E620);
}

//----- (006D1790) --------------------------------------------------------  // acclient.c:744247
int _E622()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_1, "One");
  return atexit(_E623);
}

//----- (006D17B0) --------------------------------------------------------  // acclient.c:744254
int _E625()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_1, "SrcColor");
  return atexit(_E626);
}

//----- (006D17D0) --------------------------------------------------------  // acclient.c:744261
int _E628()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_1, "InvSrcColor");
  return atexit(_E629);
}

//----- (006D17F0) --------------------------------------------------------  // acclient.c:744268
int _E631()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_1, "SrcAlpha");
  return atexit(_E632);
}

//----- (006D1810) --------------------------------------------------------  // acclient.c:744275
int _E634()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_1, "InvSrcAlpha");
  return atexit(_E635);
}

//----- (006D1830) --------------------------------------------------------  // acclient.c:744282
int _E637()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_1, "DstAlpha");
  return atexit(_E638);
}

//----- (006D1850) --------------------------------------------------------  // acclient.c:744289
int _E640()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_1, "InvDstAlpha");
  return atexit(_E641);
}

//----- (006D1870) --------------------------------------------------------  // acclient.c:744296
int _E643()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_1, "DstColor");
  return atexit(_E644);
}

//----- (006D1890) --------------------------------------------------------  // acclient.c:744303
int _E646()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_1, "InvDstColor");
  return atexit(_E647);
}

//----- (006D18B0) --------------------------------------------------------  // acclient.c:744310
int _E649()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_1, "SrcAlphaSat");
  return atexit(_E650);
}

//----- (006D18D0) --------------------------------------------------------  // acclient.c:744317
int _E652()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_1, "Less");
  return atexit(_E653);
}

//----- (006D18F0) --------------------------------------------------------  // acclient.c:744324
int _E655()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_1, "Equal");
  return atexit(_E656);
}

//----- (006D1910) --------------------------------------------------------  // acclient.c:744331
int _E658()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_1, "LessEqual");
  return atexit(_E659);
}

//----- (006D1930) --------------------------------------------------------  // acclient.c:744338
int _E661()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_1, "Greater");
  return atexit(_E662);
}

//----- (006D1950) --------------------------------------------------------  // acclient.c:744345
int _E664()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_1, "NotEqual");
  return atexit(_E665);
}

//----- (006D1970) --------------------------------------------------------  // acclient.c:744352
int _E667()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_1, "GreaterEqual");
  return atexit(_E668);
}

//----- (006D1990) --------------------------------------------------------  // acclient.c:744359
int _E670()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_1, "Always");
  return atexit(_E671);
}

//----- (006D19B0) --------------------------------------------------------  // acclient.c:744366
int _E673()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_1, "On");
  return atexit(_E674);
}

//----- (006D19D0) --------------------------------------------------------  // acclient.c:744373
int _E676()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_1, "Off");
  return atexit(_E677);
}

//----- (006D19F0) --------------------------------------------------------  // acclient.c:744380
int _E679()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_1, "LayerDiffuse");
  return atexit(_E680);
}

//----- (006D1A10) --------------------------------------------------------  // acclient.c:744387
int _E682()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_1, "LayerSpecular");
  return atexit(_E683);
}

//----- (006D1A30) --------------------------------------------------------  // acclient.c:744394
int _E685()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_1, "VertexDiffuse");
  return atexit(_E686);
}

//----- (006D1A50) --------------------------------------------------------  // acclient.c:744401
int _E688()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_1, "VertexSpecular");
  return atexit(_E689);
}

//----- (006D1A70) --------------------------------------------------------  // acclient.c:744408
int _E691()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_1, "None");
  return atexit(_E692);
}

//----- (006D1A90) --------------------------------------------------------  // acclient.c:744415
int _E694()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_1, "CW");
  return atexit(_E695);
}

//----- (006D1AB0) --------------------------------------------------------  // acclient.c:744422
int _E697()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_1, "CCW");
  return atexit(_E698);
}

//----- (006D1AD0) --------------------------------------------------------  // acclient.c:744429
int _E700()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_1, "None");
  return atexit(_E701);
}

//----- (006D1AF0) --------------------------------------------------------  // acclient.c:744436
int _E703()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_1, "Simple");
  return atexit(_E704);
}

//----- (006D1B10) --------------------------------------------------------  // acclient.c:744443
int _E706()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_1, "Diffuse");
  return atexit(_E707);
}

//----- (006D1B30) --------------------------------------------------------  // acclient.c:744450
int _E709()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_1, "Specular");
  return atexit(_E710);
}

//----- (006D1B50) --------------------------------------------------------  // acclient.c:744457
int _E712()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_1, "Off");
  return atexit(_E713);
}

//----- (006D1B70) --------------------------------------------------------  // acclient.c:744464
int _E715()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_1, "On");
  return atexit(_E716);
}

//----- (006D1B90) --------------------------------------------------------  // acclient.c:744471
int _E718()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_1, "Off");
  return atexit(_E719);
}

//----- (006D1BB0) --------------------------------------------------------  // acclient.c:744478
int _E721()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_1, "On");
  return atexit(_E722);
}

//----- (006D1BD0) --------------------------------------------------------  // acclient.c:744485
int _E724()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_1, "Origin");
  return atexit(_E725);
}

//----- (006D1BF0) --------------------------------------------------------  // acclient.c:744492
int _E727()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_1, "Normal");
  return atexit(_E728);
}

//----- (006D1C10) --------------------------------------------------------  // acclient.c:744499
int _E730()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_1, "PointSize");
  return atexit(_E731);
}

//----- (006D1C30) --------------------------------------------------------  // acclient.c:744506
int _E733()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_1, "Diffuse");
  return atexit(_E734);
}

//----- (006D1C50) --------------------------------------------------------  // acclient.c:744513
int _E736()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_1, "Specular");
  return atexit(_E737);
}

//----- (006D1C70) --------------------------------------------------------  // acclient.c:744520
int _E739()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_1, "TCPairX1");
  return atexit(_E740);
}

//----- (006D1C90) --------------------------------------------------------  // acclient.c:744527
int _E742()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_1, "TCPairX2");
  return atexit(_E743);
}

//----- (006D1CB0) --------------------------------------------------------  // acclient.c:744534
int _E745()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_1, "TCPairX3");
  return atexit(_E746);
}

//----- (006D1CD0) --------------------------------------------------------  // acclient.c:744541
int _E748()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_1, "TCPairX4");
  return atexit(_E749);
}

//----- (006D1CF0) --------------------------------------------------------  // acclient.c:744548
int _E751()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_1, "TCPairX5");
  return atexit(_E752);
}

//----- (006D1D10) --------------------------------------------------------  // acclient.c:744555
int _E754()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_1, "TCPairX6");
  return atexit(_E755);
}

//----- (006D1D30) --------------------------------------------------------  // acclient.c:744562
int _E757()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_1, "TCPairX7");
  return atexit(_E758);
}

//----- (006D1D50) --------------------------------------------------------  // acclient.c:744569
int _E760()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_1, "TCPairX8");
  return atexit(_E761);
}

//----- (006D1D70) --------------------------------------------------------  // acclient.c:744576
int _E763()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_1, "VectorS");
  return atexit(_E764);
}

//----- (006D1D90) --------------------------------------------------------  // acclient.c:744583
int _E766()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_1, "VectorT");
  return atexit(_E767);
}

//----- (006D1DB0) --------------------------------------------------------  // acclient.c:744590
int _E769()
{
  PStringBase<char>::PStringBase<char>(&NodeName_24, "Stage");
  return atexit(_E770);
}

//----- (006D1DD0) --------------------------------------------------------  // acclient.c:744597
int _E772()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_1, "Sampler");
  return atexit(_E773);
}

//----- (006D1DF0) --------------------------------------------------------  // acclient.c:744604
int _E775()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_1, "SamplerName");
  return atexit(_E776);
}

//----- (006D1E10) --------------------------------------------------------  // acclient.c:744611
int _E778()
{
  PStringBase<char>::PStringBase<char>(&Texture_1, "Texture");
  return atexit(_E779);
}

//----- (006D1E30) --------------------------------------------------------  // acclient.c:744618
int _E781()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_1, "!FrameBuffer");
  return atexit(_E782);
}

//----- (006D1E50) --------------------------------------------------------  // acclient.c:744625
int _E784()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_1, "!Distortion");
  return atexit(_E785);
}

//----- (006D1E70) --------------------------------------------------------  // acclient.c:744632
int _E787()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_1, "!Reflection");
  return atexit(_E788);
}

//----- (006D1E90) --------------------------------------------------------  // acclient.c:744639
int _E790()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_1, "!NormalizeCube");
  return atexit(_E791);
}

//----- (006D1EB0) --------------------------------------------------------  // acclient.c:744646
int _E793()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_1, "!LightProjectorCube");
  return atexit(_E794);
}

//----- (006D1ED0) --------------------------------------------------------  // acclient.c:744653
int _E796()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_1, "!EnvironmentCube");
  return atexit(_E797);
}

//----- (006D1EF0) --------------------------------------------------------  // acclient.c:744660
int _E799()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_1, "!LandscapeShadows");
  return atexit(_E800);
}

//----- (006D1F10) --------------------------------------------------------  // acclient.c:744667
int _E802()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_1, "AddressMode");
  return atexit(_E803);
}

//----- (006D1F30) --------------------------------------------------------  // acclient.c:744674
int _E805()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_1, "FilterMode");
  return atexit(_E806);
}

//----- (006D1F50) --------------------------------------------------------  // acclient.c:744681
int _E808()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_1, "FFColorOp");
  return atexit(_E809);
}

//----- (006D1F70) --------------------------------------------------------  // acclient.c:744688
int _E811()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_1, "FFColorArg1");
  return atexit(_E812);
}

//----- (006D1F90) --------------------------------------------------------  // acclient.c:744695
int _E814()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_1, "FFColorArg2");
  return atexit(_E815);
}

//----- (006D1FB0) --------------------------------------------------------  // acclient.c:744702
int _E817()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_1, "FFAlphaOp");
  return atexit(_E818);
}

//----- (006D1FD0) --------------------------------------------------------  // acclient.c:744709
int _E820()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_1, "FFAlphaArg1");
  return atexit(_E821);
}

//----- (006D1FF0) --------------------------------------------------------  // acclient.c:744716
int _E823()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_1, "FFAlphaArg2");
  return atexit(_E824);
}

//----- (006D2010) --------------------------------------------------------  // acclient.c:744723
int _E826()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_1, "FFTexCoordIndex");
  return atexit(_E827);
}

//----- (006D2030) --------------------------------------------------------  // acclient.c:744730
int _E829()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_1, "FFUseProjection");
  return atexit(_E830);
}

//----- (006D2050) --------------------------------------------------------  // acclient.c:744737
int _E832()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_1, "SelectArg1");
  return atexit(_E833);
}

//----- (006D2070) --------------------------------------------------------  // acclient.c:744744
int _E835()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_1, "SelectArg2");
  return atexit(_E836);
}

//----- (006D2090) --------------------------------------------------------  // acclient.c:744751
int _E838()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_1, "Modulate");
  return atexit(_E839);
}

//----- (006D20B0) --------------------------------------------------------  // acclient.c:744758
int _E841()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_1, "Modulate2X");
  return atexit(_E842);
}

//----- (006D20D0) --------------------------------------------------------  // acclient.c:744765
int _E844()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_1, "Modulate4X");
  return atexit(_E845);
}

//----- (006D20F0) --------------------------------------------------------  // acclient.c:744772
int _E847()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_1, "Add");
  return atexit(_E848);
}

//----- (006D2110) --------------------------------------------------------  // acclient.c:744779
int _E850()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_1, "AddSigned");
  return atexit(_E851);
}

//----- (006D2130) --------------------------------------------------------  // acclient.c:744786
int _E853()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_1, "AddSigned2X");
  return atexit(_E854);
}

//----- (006D2150) --------------------------------------------------------  // acclient.c:744793
int _E856()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_1, "Subtract");
  return atexit(_E857);
}

//----- (006D2170) --------------------------------------------------------  // acclient.c:744800
int _E859()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_1, "AddSmooth");
  return atexit(_E860);
}

//----- (006D2190) --------------------------------------------------------  // acclient.c:744807
int _E862()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_1, "BlendDiffuseAlpha");
  return atexit(_E863);
}

//----- (006D21B0) --------------------------------------------------------  // acclient.c:744814
int _E865()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_1, "BlendTextureAlpha");
  return atexit(_E866);
}

//----- (006D21D0) --------------------------------------------------------  // acclient.c:744821
int _E868()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_1, "BlendFactorAlpha");
  return atexit(_E869);
}

//----- (006D21F0) --------------------------------------------------------  // acclient.c:744828
int _E871()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_1, "BlendTextureAlphaPM");
  return atexit(_E872);
}

//----- (006D2210) --------------------------------------------------------  // acclient.c:744835
int _E874()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_1, "BlendCurrentAlpha");
  return atexit(_E875);
}

//----- (006D2230) --------------------------------------------------------  // acclient.c:744842
int _E877()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_1, "Premodulate");
  return atexit(_E878);
}

//----- (006D2250) --------------------------------------------------------  // acclient.c:744849
int _E880()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_1, "ModulateAlphaAddColor");
  return atexit(_E881);
}

//----- (006D2270) --------------------------------------------------------  // acclient.c:744856
int _E883()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_1, "ModulateColorAddAlpha");
  return atexit(_E884);
}

//----- (006D2290) --------------------------------------------------------  // acclient.c:744863
int _E886()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_1, "ModulateInvAlphaAddColor");
  return atexit(_E887);
}

//----- (006D22B0) --------------------------------------------------------  // acclient.c:744870
int _E889()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_1, "ModulateInvColorAddAlpha");
  return atexit(_E890);
}

//----- (006D22D0) --------------------------------------------------------  // acclient.c:744877
int _E892()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_1, "BumpEnvMap");
  return atexit(_E893);
}

//----- (006D22F0) --------------------------------------------------------  // acclient.c:744884
int _E895()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_1, "BumpEnvMapLuminance");
  return atexit(_E896);
}

//----- (006D2310) --------------------------------------------------------  // acclient.c:744891
int _E898()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_1, "DotProduct3");
  return atexit(_E899);
}

//----- (006D2330) --------------------------------------------------------  // acclient.c:744898
int _E901()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_1, "MultiplyAdd");
  return atexit(_E902);
}

//----- (006D2350) --------------------------------------------------------  // acclient.c:744905
int _E904()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_1, "Lerp");
  return atexit(_E905);
}

//----- (006D2370) --------------------------------------------------------  // acclient.c:744912
int _E907()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_1, "Diffuse");
  return atexit(_E908);
}

//----- (006D2390) --------------------------------------------------------  // acclient.c:744919
int _E910()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_1, "Specular");
  return atexit(_E911);
}

//----- (006D23B0) --------------------------------------------------------  // acclient.c:744926
int _E913()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_1, "Current");
  return atexit(_E914);
}

//----- (006D23D0) --------------------------------------------------------  // acclient.c:744933
int _E916()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_1, "Texture");
  return atexit(_E917);
}

//----- (006D23F0) --------------------------------------------------------  // acclient.c:744940
int _E919()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_1, "TFactor");
  return atexit(_E920);
}

//----- (006D2410) --------------------------------------------------------  // acclient.c:744947
int _E922()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_1, "Wrap");
  return atexit(_E923);
}

//----- (006D2430) --------------------------------------------------------  // acclient.c:744954
int _E925()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_1, "Mirror");
  return atexit(_E926);
}

//----- (006D2450) --------------------------------------------------------  // acclient.c:744961
int _E928()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_1, "Clamp");
  return atexit(_E929);
}

//----- (006D2470) --------------------------------------------------------  // acclient.c:744968
int _E931()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_1, "Border");
  return atexit(_E932);
}

//----- (006D2490) --------------------------------------------------------  // acclient.c:744975
int _E934()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_1, "None");
  return atexit(_E935);
}

//----- (006D24B0) --------------------------------------------------------  // acclient.c:744982
int _E937()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_1, "Point");
  return atexit(_E938);
}

//----- (006D24D0) --------------------------------------------------------  // acclient.c:744989
int _E940()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_1, "Linear");
  return atexit(_E941);
}

//----- (006D24F0) --------------------------------------------------------  // acclient.c:744996
int _E943()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_1, "Anisotropic");
  return atexit(_E944);
}

//----- (006D2510) --------------------------------------------------------  // acclient.c:745003
int _E946()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_1, "ReflectionVector");
  return atexit(_E947);
}

//----- (006D2530) --------------------------------------------------------  // acclient.c:745010
int _E949()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_1, "ViewNormal");
  return atexit(_E950);
}

//----- (006D2550) --------------------------------------------------------  // acclient.c:745017
int _E952()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_1, "ViewOrigin");
  return atexit(_E953);
}

//----- (006D2570) --------------------------------------------------------  // acclient.c:745024
int _E955()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_1, "SphereMap");
  return atexit(_E956);
}

//----- (006D2590) --------------------------------------------------------  // acclient.c:745031
int _E958()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_1, "CubeMapReflection");
  return atexit(_E959);
}

//----- (006D25B0) --------------------------------------------------------  // acclient.c:745038
int _E961()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_1, "CubeMapFakeLight");
  return atexit(_E962);
}

//----- (006D25D0) --------------------------------------------------------  // acclient.c:745045
int _E964()
{
  PStringBase<char>::PStringBase<char>(&NodeName_25, "FFModifier");
  return atexit(_E965);
}

//----- (006D25F0) --------------------------------------------------------  // acclient.c:745052
int _E967()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_1, "Origin");
  return atexit(_E968);
}

//----- (006D2610) --------------------------------------------------------  // acclient.c:745059
int _E970()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_1, "Normal");
  return atexit(_E971);
}

//----- (006D2630) --------------------------------------------------------  // acclient.c:745066
int _E973()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_1, "Diffuse");
  return atexit(_E974);
}

//----- (006D2650) --------------------------------------------------------  // acclient.c:745073
int _E976()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_1, "UVTranslate");
  return atexit(_E977);
}

//----- (006D2670) --------------------------------------------------------  // acclient.c:745080
int _E979()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_1, "UVRotate");
  return atexit(_E980);
}

//----- (006D2690) --------------------------------------------------------  // acclient.c:745087
int _E982()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_1, "UVScale");
  return atexit(_E983);
}

//----- (006D26B0) --------------------------------------------------------  // acclient.c:745094
int _E985()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_1, "UVTransform");
  return atexit(_E986);
}

//----- (006D26D0) --------------------------------------------------------  // acclient.c:745101
int _E988()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_1, "TexCoordIndex");
  return atexit(_E989);
}

//----- (006D26F0) --------------------------------------------------------  // acclient.c:745108
int _E991()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_1, "Translate");
  return atexit(_E992);
}

//----- (006D2710) --------------------------------------------------------  // acclient.c:745115
int _E994()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_1, "TexCoordIndex");
  return atexit(_E995);
}

//----- (006D2730) --------------------------------------------------------  // acclient.c:745122
int _E997()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_1, "Rotate");
  return atexit(_E998);
}

//----- (006D2750) --------------------------------------------------------  // acclient.c:745129
int _E1000()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_1, "TexCoordIndex");
  return atexit(_E1001);
}

//----- (006D2770) --------------------------------------------------------  // acclient.c:745136
int _E1003()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_1, "Scale");
  return atexit(_E1004);
}

//----- (006D2790) --------------------------------------------------------  // acclient.c:745143
int _E1006()
{
  PStringBase<char>::PStringBase<char>(&NodeName_26, "PSDesc");
  return atexit(_E1007);
}

//----- (006D27B0) --------------------------------------------------------  // acclient.c:745150
int _E1009()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_1, "PhysicsTimeStep");
  return atexit(_E1010);
}

//----- (006D27D0) --------------------------------------------------------  // acclient.c:745157
int _E1012()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_1, "FastForwardTime");
  return atexit(_E1013);
}

//----- (006D27F0) --------------------------------------------------------  // acclient.c:745164
int _E1015()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_1, "StartFadeDistance");
  return atexit(_E1016);
}

//----- (006D2810) --------------------------------------------------------  // acclient.c:745171
int _E1018()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_1, "StopFadeDistance");
  return atexit(_E1019);
}

//----- (006D2830) --------------------------------------------------------  // acclient.c:745178
int _E1021()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_1, "PhysicsDuration");
  return atexit(_E1022);
}

//----- (006D2850) --------------------------------------------------------  // acclient.c:745185
int _E1024()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_1, "ScaleType");
  return atexit(_E1025);
}

//----- (006D2870) --------------------------------------------------------  // acclient.c:745192
int _E1027()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_1, "WorldSpace");
  return atexit(_E1028);
}

//----- (006D2890) --------------------------------------------------------  // acclient.c:745199
int _E1030()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_1, "ForceDraw");
  return atexit(_E1031);
}

//----- (006D28B0) --------------------------------------------------------  // acclient.c:745206
int _E1033()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_1, "NumEmitters");
  return atexit(_E1034);
}

//----- (006D28D0) --------------------------------------------------------  // acclient.c:745213
int _E1036()
{
  PStringBase<char>::PStringBase<char>(&Material_11, "Material");
  return atexit(_E1037);
}

//----- (006D28F0) --------------------------------------------------------  // acclient.c:745220
int _E1039()
{
  PStringBase<char>::PStringBase<char>(&Version_1, "Version");
  return atexit(_E1040);
}

//----- (006D2910) --------------------------------------------------------  // acclient.c:745227
int _E1042()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_1, "MaxParticles");
  return atexit(_E1043);
}

//----- (006D2930) --------------------------------------------------------  // acclient.c:745234
int _E1045()
{
  PStringBase<char>::PStringBase<char>(&NodeName_27, "Emitter");
  return atexit(_E1046);
}

//----- (006D2950) --------------------------------------------------------  // acclient.c:745241
int _E1048()
{
  PStringBase<char>::PStringBase<char>(&Origin_4, "Origin");
  return atexit(_E1049);
}

//----- (006D2970) --------------------------------------------------------  // acclient.c:745248
int _E1051()
{
  PStringBase<char>::PStringBase<char>(&Shape_1, "Shape");
  return atexit(_E1052);
}

//----- (006D2990) --------------------------------------------------------  // acclient.c:745255
int _E1054()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_1, "Point");
  return atexit(_E1055);
}

//----- (006D29B0) --------------------------------------------------------  // acclient.c:745262
int _E1057()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_1, "Line");
  return atexit(_E1058);
}

//----- (006D29D0) --------------------------------------------------------  // acclient.c:745269
int _E1060()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_1, "Quad");
  return atexit(_E1061);
}

//----- (006D29F0) --------------------------------------------------------  // acclient.c:745276
int _E1063()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_1, "Disc");
  return atexit(_E1064);
}

//----- (006D2A10) --------------------------------------------------------  // acclient.c:745283
int _E1066()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_1, "Sphere");
  return atexit(_E1067);
}

//----- (006D2A30) --------------------------------------------------------  // acclient.c:745290
int _E1069()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_1, "ParticleShape");
  return atexit(_E1070);
}

//----- (006D2A50) --------------------------------------------------------  // acclient.c:745297
int _E1072()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_1, "Triangle");
  return atexit(_E1073);
}

//----- (006D2A70) --------------------------------------------------------  // acclient.c:745304
int _E1075()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_1, "Quad");
  return atexit(_E1076);
}

//----- (006D2A90) --------------------------------------------------------  // acclient.c:745311
int _E1078()
{
  PStringBase<char>::PStringBase<char>(&Streak_1, "Streak");
  return atexit(_E1079);
}

//----- (006D2AB0) --------------------------------------------------------  // acclient.c:745318
int _E1081()
{
  PStringBase<char>::PStringBase<char>(&Rotation_4, "Rotation");
  return atexit(_E1082);
}

//----- (006D2AD0) --------------------------------------------------------  // acclient.c:745325
int _E1084()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_1, "WorldRotation");
  return atexit(_E1085);
}

//----- (006D2AF0) --------------------------------------------------------  // acclient.c:745332
int _E1087()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_1, "RotateVelocity");
  return atexit(_E1088);
}

//----- (006D2B10) --------------------------------------------------------  // acclient.c:745339
int _E1090()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_1, "ParticleScale");
  return atexit(_E1091);
}

//----- (006D2B30) --------------------------------------------------------  // acclient.c:745346
int _E1093()
{
  PStringBase<char>::PStringBase<char>(&Scale_6, "Scale");
  return atexit(_E1094);
}

//----- (006D2B50) --------------------------------------------------------  // acclient.c:745353
int _E1096()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_1, "ExplodingDir");
  return atexit(_E1097);
}

//----- (006D2B70) --------------------------------------------------------  // acclient.c:745360
int _E1099()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_1, "BirthRate");
  return atexit(_E1100);
}

//----- (006D2B90) --------------------------------------------------------  // acclient.c:745367
int _E1102()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_1, "Lifespan");
  return atexit(_E1103);
}

//----- (006D2BB0) --------------------------------------------------------  // acclient.c:745374
int _E1105()
{
  PStringBase<char>::PStringBase<char>(&Velocity_1, "Velocity");
  return atexit(_E1106);
}

//----- (006D2BD0) --------------------------------------------------------  // acclient.c:745381
int _E1108()
{
  PStringBase<char>::PStringBase<char>(&Direction_1, "Direction");
  return atexit(_E1109);
}

//----- (006D2BF0) --------------------------------------------------------  // acclient.c:745388
int _E1111()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_1, "MinSpread");
  return atexit(_E1112);
}

//----- (006D2C10) --------------------------------------------------------  // acclient.c:745395
int _E1114()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_1, "MaxSpread");
  return atexit(_E1115);
}

//----- (006D2C30) --------------------------------------------------------  // acclient.c:745402
int _E1117()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_1, "EmissionLimit");
  return atexit(_E1118);
}

//----- (006D2C50) --------------------------------------------------------  // acclient.c:745409
int _E1120()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_1, "BlastCount");
  return atexit(_E1121);
}

//----- (006D2C70) --------------------------------------------------------  // acclient.c:745416
int _E1123()
{
  PStringBase<char>::PStringBase<char>(&StartTime_1, "StartTime");
  return atexit(_E1124);
}

//----- (006D2C90) --------------------------------------------------------  // acclient.c:745423
int _E1126()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_1, "TimeLimit");
  return atexit(_E1127);
}

//----- (006D2CB0) --------------------------------------------------------  // acclient.c:745430
int _E1129()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_1, "EmissionDistance");
  return atexit(_E1130);
}

//----- (006D2CD0) --------------------------------------------------------  // acclient.c:745437
int _E1132()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_1, "ParticleSnap");
  return atexit(_E1133);
}

//----- (006D2CF0) --------------------------------------------------------  // acclient.c:745444
int _E1135()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_1, "InclusiveShape");
  return atexit(_E1136);
}

//----- (006D2D10) --------------------------------------------------------  // acclient.c:745451
int _E1138()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_1, "NumKeyframes");
  return atexit(_E1139);
}

//----- (006D2D30) --------------------------------------------------------  // acclient.c:745458
int _E1141()
{
  PStringBase<char>::PStringBase<char>(&IsActive_1, "IsActive");
  return atexit(_E1142);
}

//----- (006D2D50) --------------------------------------------------------  // acclient.c:745465
int _E1144()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_1, "FadeIn");
  return atexit(_E1145);
}

//----- (006D2D70) --------------------------------------------------------  // acclient.c:745472
int _E1147()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_1, "FadeOut");
  return atexit(_E1148);
}

//----- (006D2D90) --------------------------------------------------------  // acclient.c:745479
int _E1150()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_1, "ConstrainX");
  return atexit(_E1151);
}

//----- (006D2DB0) --------------------------------------------------------  // acclient.c:745486
int _E1153()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_1, "ConstrainY");
  return atexit(_E1154);
}

//----- (006D2DD0) --------------------------------------------------------  // acclient.c:745493
int _E1156()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_1, "ConstrainZ");
  return atexit(_E1157);
}

//----- (006D2DF0) --------------------------------------------------------  // acclient.c:745500
int _E1159()
{
  PStringBase<char>::PStringBase<char>(&NodeName_28, "Keyframe");
  return atexit(_E1160);
}

//----- (006D2E10) --------------------------------------------------------  // acclient.c:745507
int _E1162()
{
  PStringBase<char>::PStringBase<char>(&Time_1, "Time");
  return atexit(_E1163);
}

//----- (006D2E30) --------------------------------------------------------  // acclient.c:745514
int _E1165()
{
  PStringBase<char>::PStringBase<char>(&Flags_1, "Flags");
  return atexit(_E1166);
}

//----- (006D2E50) --------------------------------------------------------  // acclient.c:745521
int _E1168()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_1, "None");
  return atexit(_E1169);
}

//----- (006D2E70) --------------------------------------------------------  // acclient.c:745528
int _E1171()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_1, "BlendScale");
  return atexit(_E1172);
}

//----- (006D2E90) --------------------------------------------------------  // acclient.c:745535
int _E1174()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_1, "BlendColor");
  return atexit(_E1175);
}

//----- (006D2EB0) --------------------------------------------------------  // acclient.c:745542
int _E1177()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_1, "BlendMass");
  return atexit(_E1178);
}

//----- (006D2ED0) --------------------------------------------------------  // acclient.c:745549
int _E1180()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_1, "SetScale");
  return atexit(_E1181);
}

//----- (006D2EF0) --------------------------------------------------------  // acclient.c:745556
int _E1183()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_1, "SetColor");
  return atexit(_E1184);
}

//----- (006D2F10) --------------------------------------------------------  // acclient.c:745563
int _E1186()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_1, "SetMass");
  return atexit(_E1187);
}

//----- (006D2F30) --------------------------------------------------------  // acclient.c:745570
int _E1189()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_1, "SetParticleFlags");
  return atexit(_E1190);
}

//----- (006D2F50) --------------------------------------------------------  // acclient.c:745577
int _E1192()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_1, "SetControllerType");
  return atexit(_E1193);
}

//----- (006D2F70) --------------------------------------------------------  // acclient.c:745584
int _E1195()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_1, "SetPhysicsFlags");
  return atexit(_E1196);
}

//----- (006D2F90) --------------------------------------------------------  // acclient.c:745591
int _E1198()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_1, "SetParams");
  return atexit(_E1199);
}

//----- (006D2FB0) --------------------------------------------------------  // acclient.c:745598
int _E1201()
{
  PStringBase<char>::PStringBase<char>(&Scale_7, "Scale");
  return atexit(_E1202);
}

//----- (006D2FD0) --------------------------------------------------------  // acclient.c:745605
int _E1204()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_1, "ScaleX");
  return atexit(_E1205);
}

//----- (006D2FF0) --------------------------------------------------------  // acclient.c:745612
int _E1207()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_1, "ScaleY");
  return atexit(_E1208);
}

//----- (006D3010) --------------------------------------------------------  // acclient.c:745619
int _E1210()
{
  PStringBase<char>::PStringBase<char>(&Color_1, "Color");
  return atexit(_E1211);
}

//----- (006D3030) --------------------------------------------------------  // acclient.c:745626
int _E1213()
{
  PStringBase<char>::PStringBase<char>(&Mass_1, "Mass");
  return atexit(_E1214);
}

//----- (006D3050) --------------------------------------------------------  // acclient.c:745633
int _E1216()
{
  PStringBase<char>::PStringBase<char>(&PFlags_1, "ParticleFlags");
  return atexit(_E1217);
}

//----- (006D3070) --------------------------------------------------------  // acclient.c:745640
int _E1219()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_1, "None");
  return atexit(_E1220);
}

//----- (006D3090) --------------------------------------------------------  // acclient.c:745647
int _E1222()
{
  PStringBase<char>::PStringBase<char>(&PCType_1, "ControllerType");
  return atexit(_E1223);
}

//----- (006D30B0) --------------------------------------------------------  // acclient.c:745654
int _E1225()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_1, "None");
  return atexit(_E1226);
}

//----- (006D30D0) --------------------------------------------------------  // acclient.c:745661
int _E1228()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_1, "Physics");
  return atexit(_E1229);
}

//----- (006D30F0) --------------------------------------------------------  // acclient.c:745668
int _E1231()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_1, "Parametric");
  return atexit(_E1232);
}

//----- (006D3110) --------------------------------------------------------  // acclient.c:745675
int _E1234()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_1, "AttractRepulse");
  return atexit(_E1235);
}

//----- (006D3130) --------------------------------------------------------  // acclient.c:745682
int _E1237()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_1, "PointFile");
  return atexit(_E1238);
}

//----- (006D3150) --------------------------------------------------------  // acclient.c:745689
int _E1240()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_1, "PointFileLerp");
  return atexit(_E1241);
}

//----- (006D3170) --------------------------------------------------------  // acclient.c:745696
int _E1243()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_1, "PhysicsFlags");
  return atexit(_E1244);
}

//----- (006D3190) --------------------------------------------------------  // acclient.c:745703
int _E1246()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_1, "None");
  return atexit(_E1247);
}

//----- (006D31B0) --------------------------------------------------------  // acclient.c:745710
int _E1249()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_1, "Gravity");
  return atexit(_E1250);
}

//----- (006D31D0) --------------------------------------------------------  // acclient.c:745717
int _E1252()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_1, "Wind");
  return atexit(_E1253);
}

//----- (006D31F0) --------------------------------------------------------  // acclient.c:745724
int _E1255()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_1, "Momentum");
  return atexit(_E1256);
}

//----- (006D3210) --------------------------------------------------------  // acclient.c:745731
int _E1258()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_1, "RandomPoint");
  return atexit(_E1259);
}

//----- (006D3230) --------------------------------------------------------  // acclient.c:745738
int _E1261()
{
  PStringBase<char>::PStringBase<char>(&Position_2, "Position");
  return atexit(_E1262);
}

//----- (006D3250) --------------------------------------------------------  // acclient.c:745745
int _E1264()
{
  PStringBase<char>::PStringBase<char>(&PointList_1, "PointList");
  return atexit(_E1265);
}

//----- (006D3270) --------------------------------------------------------  // acclient.c:745752
int _E1267()
{
  PStringBase<char>::PStringBase<char>(&Point_4, "pt");
  return atexit(_E1268);
}

//----- (006D3290) --------------------------------------------------------  // acclient.c:745759
int _E1270()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_1, "DetailLevels");
  return atexit(_E1271);
}

//----- (006D32B0) --------------------------------------------------------  // acclient.c:745766
int _E1273()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_1, "Low");
  return atexit(_E1274);
}

//----- (006D32D0) --------------------------------------------------------  // acclient.c:745773
int _E1276()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_1, "Medium");
  return atexit(_E1277);
}

//----- (006D32F0) --------------------------------------------------------  // acclient.c:745780
int _E1279()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_1, "High");
  return atexit(_E1280_0);
}

//----- (006D3310) --------------------------------------------------------  // acclient.c:745787
int _E1282()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_1, "FadeSpeed");
  return atexit(_E1283);
}

//----- (006D3330) --------------------------------------------------------  // acclient.c:745794
int _E1285()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_1, "MaxOpacity");
  return atexit(_E1286);
}

//----- (006D3350) --------------------------------------------------------  // acclient.c:745801
int _E1288()
{
  PStringBase<char>::PStringBase<char>(&Point_5, "Point");
  return atexit(_E1289);
}

//----- (006D3370) --------------------------------------------------------  // acclient.c:745808
int _E1291()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_1, "AxisPos");
  return atexit(_E1292_0);
}

//----- (006D3390) --------------------------------------------------------  // acclient.c:745815
int _E1294()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_1, "Texture");
  return atexit(_E1295);
}

//----- (006D33B0) --------------------------------------------------------  // acclient.c:745822
int _E1297()
{
  PStringBase<char>::PStringBase<char>(&PointSize_1, "Size");
  return atexit(_E1298);
}

//----- (006D33D0) --------------------------------------------------------  // acclient.c:745829
int _E1300()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_1, "UseOcclusion");
  return atexit(_E1301);
}

//----- (006D33F0) --------------------------------------------------------  // acclient.c:745836
int _E1303()
{
  return atexit(_E1304);
}

//----- (006D3400) --------------------------------------------------------  // acclient.c:745842
int _E1306()
{
  return atexit(_E1307);
}

//----- (006D3410) --------------------------------------------------------  // acclient.c:745848
int _E1309()
{
  return atexit(_E1310);
}

//----- (006D3420) --------------------------------------------------------  // acclient.c:745854
int _E1312()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_1, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_8399E0, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_8399E4, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_8399E8, "PREPROC_OPTIONS");
  return atexit(_E1313);
}

//----- (006D3470) --------------------------------------------------------  // acclient.c:745864
int _E1_38()
{
  return atexit(_E2_38);
}

//----- (00736A70) --------------------------------------------------------  // acclient.c:842347
void __cdecl _E74_34()
{
  char *v0; // esi@1

  v0 = &waveform_None_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736AA0) --------------------------------------------------------  // acclient.c:842360
void __cdecl _E77_49()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736AD0) --------------------------------------------------------  // acclient.c:842373
void __cdecl _E80_23()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736B00) --------------------------------------------------------  // acclient.c:842386
void __cdecl _E83_13()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736B30) --------------------------------------------------------  // acclient.c:842399
void __cdecl _E86_10()
{
  char *v0; // esi@1

  v0 = &waveform_Square_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736B60) --------------------------------------------------------  // acclient.c:842412
void __cdecl _E89_21()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736B90) --------------------------------------------------------  // acclient.c:842425
void __cdecl _E92_21()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736BC0) --------------------------------------------------------  // acclient.c:842438
void __cdecl sub_736BC0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736BF0) --------------------------------------------------------  // acclient.c:842451
void __cdecl _E98_36()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736C20) --------------------------------------------------------  // acclient.c:842464
void __cdecl _E119_60()
{
  char *v0; // esi@1

  v0 = &PHeader_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736C50) --------------------------------------------------------  // acclient.c:842477
void __cdecl _E122_47()
{
  char *v0; // esi@1

  v0 = &VertexArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736C80) --------------------------------------------------------  // acclient.c:842490
void __cdecl _E125_22()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736CB0) --------------------------------------------------------  // acclient.c:842503
void __cdecl _E128_23()
{
  char *v0; // esi@1

  v0 = &VertexType_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736CE0) --------------------------------------------------------  // acclient.c:842516
void __cdecl _E131_19()
{
  char *v0; // esi@1

  v0 = &VertexData_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736D10) --------------------------------------------------------  // acclient.c:842529
void __cdecl _E134_18()
{
  char *v0; // esi@1

  v0 = &Vertex_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736D40) --------------------------------------------------------  // acclient.c:842542
void __cdecl _E137_18()
{
  char *v0; // esi@1

  v0 = &Index_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736D70) --------------------------------------------------------  // acclient.c:842555
void __cdecl _E140_13()
{
  char *v0; // esi@1

  v0 = &Origin_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736DA0) --------------------------------------------------------  // acclient.c:842568
void __cdecl _E143_14()
{
  char *v0; // esi@1

  v0 = &Normal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736DD0) --------------------------------------------------------  // acclient.c:842581
void __cdecl _E146_13()
{
  char *v0; // esi@1

  v0 = &Diffuse_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736E00) --------------------------------------------------------  // acclient.c:842594
void __cdecl _E149_13()
{
  char *v0; // esi@1

  v0 = &Specular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736E30) --------------------------------------------------------  // acclient.c:842607
void __cdecl _E152_12()
{
  char *v0; // esi@1

  v0 = &UVS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736E60) --------------------------------------------------------  // acclient.c:842620
void __cdecl _E155_10()
{
  char *v0; // esi@1

  v0 = &VectorS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736E90) --------------------------------------------------------  // acclient.c:842633
void __cdecl _E158_13()
{
  char *v0; // esi@1

  v0 = &VectorT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736EC0) --------------------------------------------------------  // acclient.c:842646
void __cdecl _E161_10()
{
  char *v0; // esi@1

  v0 = &VectorSxT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736EF0) --------------------------------------------------------  // acclient.c:842659
void __cdecl _E164_13()
{
  char *v0; // esi@1

  v0 = &Weights_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736F20) --------------------------------------------------------  // acclient.c:842672
void __cdecl _E167_9()
{
  char *v0; // esi@1

  v0 = &Importance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736F50) --------------------------------------------------------  // acclient.c:842685
void __cdecl _E170_8()
{
  char *v0; // esi@1

  v0 = &PhysMtl_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736F80) --------------------------------------------------------  // acclient.c:842698
void __cdecl _E173_7()
{
  char *v0; // esi@1

  v0 = &Material_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736FB0) --------------------------------------------------------  // acclient.c:842711
void __cdecl _E176_8()
{
  char *v0; // esi@1

  v0 = &ID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736FE0) --------------------------------------------------------  // acclient.c:842724
void __cdecl _E179_7()
{
  char *v0; // esi@1

  v0 = &FileName_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737010) --------------------------------------------------------  // acclient.c:842737
void __cdecl _E182_7()
{
  char *v0; // esi@1

  v0 = &Polygon_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737040) --------------------------------------------------------  // acclient.c:842750
void __cdecl _E185_4()
{
  char *v0; // esi@1

  v0 = &ID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737070) --------------------------------------------------------  // acclient.c:842763
void __cdecl _E188_5()
{
  char *v0; // esi@1

  v0 = &Indices_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007370A0) --------------------------------------------------------  // acclient.c:842776
void __cdecl _E191_4()
{
  char *v0; // esi@1

  v0 = &MaterialID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007370D0) --------------------------------------------------------  // acclient.c:842789
void __cdecl _E194_11()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737100) --------------------------------------------------------  // acclient.c:842802
void __cdecl _E197_2()
{
  char *v0; // esi@1

  v0 = &Markings_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737130) --------------------------------------------------------  // acclient.c:842815
void __cdecl _E200_7()
{
  char *v0; // esi@1

  v0 = &Material_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737160) --------------------------------------------------------  // acclient.c:842828
void __cdecl _E203_6()
{
  char *v0; // esi@1

  v0 = &Index_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737190) --------------------------------------------------------  // acclient.c:842841
void __cdecl _E206_9()
{
  char *v0; // esi@1

  v0 = &Filename_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007371C0) --------------------------------------------------------  // acclient.c:842854
void __cdecl _E209_4()
{
  char *v0; // esi@1

  v0 = &Surface_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007371F0) --------------------------------------------------------  // acclient.c:842867
void __cdecl _E212_7()
{
  char *v0; // esi@1

  v0 = &CellPoly_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737220) --------------------------------------------------------  // acclient.c:842880
void __cdecl _E215_3()
{
  char *v0; // esi@1

  v0 = &Sphere_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737250) --------------------------------------------------------  // acclient.c:842893
void __cdecl _E218_4()
{
  char *v0; // esi@1

  v0 = &Side_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737280) --------------------------------------------------------  // acclient.c:842906
void __cdecl _E221_4()
{
  char *v0; // esi@1

  v0 = &Positive_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007372B0) --------------------------------------------------------  // acclient.c:842919
void __cdecl _E224_4()
{
  char *v0; // esi@1

  v0 = &Negative_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007372E0) --------------------------------------------------------  // acclient.c:842932
void __cdecl _E227_4()
{
  char *v0; // esi@1

  v0 = &Polygon_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737310) --------------------------------------------------------  // acclient.c:842945
void __cdecl _E230_4()
{
  char *v0; // esi@1

  v0 = &OtherCell_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737340) --------------------------------------------------------  // acclient.c:842958
void __cdecl _E233_3()
{
  char *v0; // esi@1

  v0 = &CellPortal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737370) --------------------------------------------------------  // acclient.c:842971
void __cdecl _E236_3()
{
  char *v0; // esi@1

  v0 = &Portal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007373A0) --------------------------------------------------------  // acclient.c:842984
void __cdecl _E239_4()
{
  char *v0; // esi@1

  v0 = &OtherCell_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007373D0) --------------------------------------------------------  // acclient.c:842997
void __cdecl _E242_4()
{
  char *v0; // esi@1

  v0 = &OtherPortal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737400) --------------------------------------------------------  // acclient.c:843010
void __cdecl _E245_3()
{
  char *v0; // esi@1

  v0 = &ExactMatch_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737430) --------------------------------------------------------  // acclient.c:843023
void __cdecl _E248_3()
{
  char *v0; // esi@1

  v0 = &StabList_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737460) --------------------------------------------------------  // acclient.c:843036
void __cdecl _E251_3()
{
  char *v0; // esi@1

  v0 = &Period_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737490) --------------------------------------------------------  // acclient.c:843049
void __cdecl _E254_4()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007374C0) --------------------------------------------------------  // acclient.c:843062
void __cdecl _E257_2()
{
  char *v0; // esi@1

  v0 = &Transform_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007374F0) --------------------------------------------------------  // acclient.c:843075
void __cdecl _E260_3()
{
  char *v0; // esi@1

  v0 = &Scale_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737520) --------------------------------------------------------  // acclient.c:843088
void __cdecl _E263_1()
{
  char *v0; // esi@1

  v0 = &Weight_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737550) --------------------------------------------------------  // acclient.c:843101
void __cdecl _E266_1()
{
  char *v0; // esi@1

  v0 = &Offset_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737580) --------------------------------------------------------  // acclient.c:843114
void __cdecl _E269_1()
{
  char *v0; // esi@1

  v0 = &Quaternion_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007375B0) --------------------------------------------------------  // acclient.c:843127
void __cdecl _E272_0()
{
  char *v0; // esi@1

  v0 = &Rotation_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007375E0) --------------------------------------------------------  // acclient.c:843140
void __cdecl _E275_0()
{
  char *v0; // esi@1

  v0 = &STime_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737610) --------------------------------------------------------  // acclient.c:843153
void __cdecl _E278_0()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737640) --------------------------------------------------------  // acclient.c:843166
void __cdecl _E281_1()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737670) --------------------------------------------------------  // acclient.c:843179
void __cdecl _E284_0()
{
  char *v0; // esi@1

  v0 = &LowPt_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007376A0) --------------------------------------------------------  // acclient.c:843192
void __cdecl _E287_1()
{
  char *v0; // esi@1

  v0 = &Radius_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007376D0) --------------------------------------------------------  // acclient.c:843205
void __cdecl _E290_1()
{
  char *v0; // esi@1

  v0 = &Height_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737700) --------------------------------------------------------  // acclient.c:843218
void __cdecl _E293_0()
{
  char *v0; // esi@1

  v0 = &Texture2D_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737730) --------------------------------------------------------  // acclient.c:843231
void __cdecl _E296_1()
{
  char *v0; // esi@1

  v0 = &Texture3D_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737760) --------------------------------------------------------  // acclient.c:843244
void __cdecl _E299()
{
  char *v0; // esi@1

  v0 = &TextureCube_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737790) --------------------------------------------------------  // acclient.c:843257
void __cdecl _E302_0()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007377C0) --------------------------------------------------------  // acclient.c:843270
void __cdecl _E305()
{
  char *v0; // esi@1

  v0 = &MovieFileName_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007377F0) --------------------------------------------------------  // acclient.c:843283
void __cdecl _E308_0()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737820) --------------------------------------------------------  // acclient.c:843296
void __cdecl _E311()
{
  char *v0; // esi@1

  v0 = &Levels_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737850) --------------------------------------------------------  // acclient.c:843309
void __cdecl _E314_0()
{
  char *v0; // esi@1

  v0 = &NodeName_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737880) --------------------------------------------------------  // acclient.c:843322
void __cdecl _E317()
{
  char *v0; // esi@1

  v0 = &Material_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007378B0) --------------------------------------------------------  // acclient.c:843335
void __cdecl _E320_0()
{
  char *v0; // esi@1

  v0 = &MaterialType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007378E0) --------------------------------------------------------  // acclient.c:843348
void __cdecl _E323()
{
  char *v0; // esi@1

  v0 = &Modifier_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737910) --------------------------------------------------------  // acclient.c:843361
void __cdecl _E326_0()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737940) --------------------------------------------------------  // acclient.c:843374
void __cdecl _E329()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737970) --------------------------------------------------------  // acclient.c:843387
void __cdecl _E332_0()
{
  char *v0; // esi@1

  v0 = &NodeName_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007379A0) --------------------------------------------------------  // acclient.c:843400
void __cdecl _E335()
{
  char *v0; // esi@1

  v0 = &SortMode_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007379D0) --------------------------------------------------------  // acclient.c:843413
void __cdecl _E338()
{
  char *v0; // esi@1

  v0 = &SortMode_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737A00) --------------------------------------------------------  // acclient.c:843426
void __cdecl _E341()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737A30) --------------------------------------------------------  // acclient.c:843439
void __cdecl _E344()
{
  char *v0; // esi@1

  v0 = &NodeName_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737A60) --------------------------------------------------------  // acclient.c:843452
void __cdecl _E347()
{
  char *v0; // esi@1

  v0 = &NodeName_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737A90) --------------------------------------------------------  // acclient.c:843465
void __cdecl _E350()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737AC0) --------------------------------------------------------  // acclient.c:843478
void __cdecl _E353()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737AF0) --------------------------------------------------------  // acclient.c:843491
void __cdecl _E356()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737B20) --------------------------------------------------------  // acclient.c:843504
void __cdecl _E359()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737B50) --------------------------------------------------------  // acclient.c:843517
void __cdecl _E362()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737B80) --------------------------------------------------------  // acclient.c:843530
void __cdecl _E365()
{
  char *v0; // esi@1

  v0 = &NodeName_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737BB0) --------------------------------------------------------  // acclient.c:843543
void __cdecl _E368()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737BE0) --------------------------------------------------------  // acclient.c:843556
void __cdecl _E371()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737C10) --------------------------------------------------------  // acclient.c:843569
void __cdecl _E374()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737C40) --------------------------------------------------------  // acclient.c:843582
void __cdecl _E377()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737C70) --------------------------------------------------------  // acclient.c:843595
void __cdecl _E380()
{
  char *v0; // esi@1

  v0 = &TrueFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737CA0) --------------------------------------------------------  // acclient.c:843608
void __cdecl _E383()
{
  char *v0; // esi@1

  v0 = &FalseFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737CD0) --------------------------------------------------------  // acclient.c:843621
void __cdecl _E386()
{
  char *v0; // esi@1

  v0 = &RenderPass_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737D00) --------------------------------------------------------  // acclient.c:843634
void __cdecl _E389()
{
  char *v0; // esi@1

  v0 = &Blend_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737D30) --------------------------------------------------------  // acclient.c:843647
void __cdecl _E392()
{
  char *v0; // esi@1

  v0 = &DepthTest_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737D60) --------------------------------------------------------  // acclient.c:843660
void __cdecl _E395()
{
  char *v0; // esi@1

  v0 = &DepthWrite_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737D90) --------------------------------------------------------  // acclient.c:843673
void __cdecl _E398()
{
  char *v0; // esi@1

  v0 = &CullMode_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737DC0) --------------------------------------------------------  // acclient.c:843686
void __cdecl _E401()
{
  char *v0; // esi@1

  v0 = &DepthFog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737DF0) --------------------------------------------------------  // acclient.c:843699
void __cdecl _E404()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737E20) --------------------------------------------------------  // acclient.c:843712
void __cdecl _E407()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737E50) --------------------------------------------------------  // acclient.c:843725
void __cdecl _E410()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737E80) --------------------------------------------------------  // acclient.c:843738
void __cdecl _E413()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737EB0) --------------------------------------------------------  // acclient.c:843751
void __cdecl _E416()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737EE0) --------------------------------------------------------  // acclient.c:843764
void __cdecl _E419()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737F10) --------------------------------------------------------  // acclient.c:843777
void __cdecl _E422()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737F40) --------------------------------------------------------  // acclient.c:843790
void __cdecl _E425()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737F70) --------------------------------------------------------  // acclient.c:843803
void __cdecl _E428()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737FA0) --------------------------------------------------------  // acclient.c:843816
void __cdecl _E431()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00737FD0) --------------------------------------------------------  // acclient.c:843829
void __cdecl _E434()
{
  char *v0; // esi@1

  v0 = &Ambient_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738000) --------------------------------------------------------  // acclient.c:843842
void __cdecl _E437()
{
  char *v0; // esi@1

  v0 = &Diffuse_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738030) --------------------------------------------------------  // acclient.c:843855
void __cdecl _E440()
{
  char *v0; // esi@1

  v0 = &Specular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738060) --------------------------------------------------------  // acclient.c:843868
void __cdecl _E443()
{
  char *v0; // esi@1

  v0 = &SpecularPower_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738090) --------------------------------------------------------  // acclient.c:843881
void __cdecl _E446()
{
  char *v0; // esi@1

  v0 = &Dye_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007380C0) --------------------------------------------------------  // acclient.c:843894
void __cdecl _E449()
{
  char *v0; // esi@1

  v0 = &Emissive_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007380F0) --------------------------------------------------------  // acclient.c:843907
void __cdecl _E452()
{
  char *v0; // esi@1

  v0 = &VertexFormat_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738120) --------------------------------------------------------  // acclient.c:843920
void __cdecl _E455()
{
  char *v0; // esi@1

  v0 = &VertexShader_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738150) --------------------------------------------------------  // acclient.c:843933
void __cdecl _E458()
{
  char *v0; // esi@1

  v0 = &PixelShader_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738180) --------------------------------------------------------  // acclient.c:843946
void __cdecl _E461()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007381B0) --------------------------------------------------------  // acclient.c:843959
void __cdecl _E464()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007381E0) --------------------------------------------------------  // acclient.c:843972
void __cdecl _E467()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738210) --------------------------------------------------------  // acclient.c:843985
void __cdecl _E470()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738240) --------------------------------------------------------  // acclient.c:843998
void __cdecl _E473()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738270) --------------------------------------------------------  // acclient.c:844011
void __cdecl _E476()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007382A0) --------------------------------------------------------  // acclient.c:844024
void __cdecl _E479()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007382D0) --------------------------------------------------------  // acclient.c:844037
void __cdecl _E482()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738300) --------------------------------------------------------  // acclient.c:844050
void __cdecl _E485()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738330) --------------------------------------------------------  // acclient.c:844063
void __cdecl _E488()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738360) --------------------------------------------------------  // acclient.c:844076
void __cdecl _E491()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738390) --------------------------------------------------------  // acclient.c:844089
void __cdecl _E494()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007383C0) --------------------------------------------------------  // acclient.c:844102
void __cdecl _E497()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007383F0) --------------------------------------------------------  // acclient.c:844115
void __cdecl _E500()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738420) --------------------------------------------------------  // acclient.c:844128
void __cdecl _E503()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738450) --------------------------------------------------------  // acclient.c:844141
void __cdecl _E506()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738480) --------------------------------------------------------  // acclient.c:844154
void __cdecl _E509()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007384B0) --------------------------------------------------------  // acclient.c:844167
void __cdecl _E512()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007384E0) --------------------------------------------------------  // acclient.c:844180
void __cdecl _E515()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738510) --------------------------------------------------------  // acclient.c:844193
void __cdecl _E518()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738540) --------------------------------------------------------  // acclient.c:844206
void __cdecl _E521()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738570) --------------------------------------------------------  // acclient.c:844219
void __cdecl _E524()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007385A0) --------------------------------------------------------  // acclient.c:844232
void __cdecl _E527()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007385D0) --------------------------------------------------------  // acclient.c:844245
void __cdecl _E530()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738600) --------------------------------------------------------  // acclient.c:844258
void __cdecl _E533()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738630) --------------------------------------------------------  // acclient.c:844271
void __cdecl _E536()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738660) --------------------------------------------------------  // acclient.c:844284
void __cdecl _E539()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738690) --------------------------------------------------------  // acclient.c:844297
void __cdecl _E542()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007386C0) --------------------------------------------------------  // acclient.c:844310
void __cdecl _E545()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007386F0) --------------------------------------------------------  // acclient.c:844323
void __cdecl _E548()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738720) --------------------------------------------------------  // acclient.c:844336
void __cdecl _E551()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738750) --------------------------------------------------------  // acclient.c:844349
void __cdecl _E554()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738780) --------------------------------------------------------  // acclient.c:844362
void __cdecl _E557()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007387B0) --------------------------------------------------------  // acclient.c:844375
void __cdecl _E560()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007387E0) --------------------------------------------------------  // acclient.c:844388
void __cdecl _E563()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738810) --------------------------------------------------------  // acclient.c:844401
void __cdecl _E566()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738840) --------------------------------------------------------  // acclient.c:844414
void __cdecl _E569()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738870) --------------------------------------------------------  // acclient.c:844427
void __cdecl _E572()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007388A0) --------------------------------------------------------  // acclient.c:844440
void __cdecl _E575()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007388D0) --------------------------------------------------------  // acclient.c:844453
void __cdecl _E578()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738900) --------------------------------------------------------  // acclient.c:844466
void __cdecl _E581()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738930) --------------------------------------------------------  // acclient.c:844479
void __cdecl _E584()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738960) --------------------------------------------------------  // acclient.c:844492
void __cdecl _E587()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738990) --------------------------------------------------------  // acclient.c:844505
void __cdecl _E590()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007389C0) --------------------------------------------------------  // acclient.c:844518
void __cdecl _E593()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007389F0) --------------------------------------------------------  // acclient.c:844531
void __cdecl _E596()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738A20) --------------------------------------------------------  // acclient.c:844544
void __cdecl _E599()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738A50) --------------------------------------------------------  // acclient.c:844557
void __cdecl _E602()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738A80) --------------------------------------------------------  // acclient.c:844570
void __cdecl _E605()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738AB0) --------------------------------------------------------  // acclient.c:844583
void __cdecl _E608()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738AE0) --------------------------------------------------------  // acclient.c:844596
void __cdecl _E611()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738B10) --------------------------------------------------------  // acclient.c:844609
void __cdecl _E614()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738B40) --------------------------------------------------------  // acclient.c:844622
void __cdecl _E617()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738B70) --------------------------------------------------------  // acclient.c:844635
void __cdecl _E620()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738BA0) --------------------------------------------------------  // acclient.c:844648
void __cdecl _E623()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738BD0) --------------------------------------------------------  // acclient.c:844661
void __cdecl _E626()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738C00) --------------------------------------------------------  // acclient.c:844674
void __cdecl _E629()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738C30) --------------------------------------------------------  // acclient.c:844687
void __cdecl _E632()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738C60) --------------------------------------------------------  // acclient.c:844700
void __cdecl _E635()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738C90) --------------------------------------------------------  // acclient.c:844713
void __cdecl _E638()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738CC0) --------------------------------------------------------  // acclient.c:844726
void __cdecl _E641()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738CF0) --------------------------------------------------------  // acclient.c:844739
void __cdecl _E644()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738D20) --------------------------------------------------------  // acclient.c:844752
void __cdecl _E647()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738D50) --------------------------------------------------------  // acclient.c:844765
void __cdecl _E650()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738D80) --------------------------------------------------------  // acclient.c:844778
void __cdecl _E653()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738DB0) --------------------------------------------------------  // acclient.c:844791
void __cdecl _E656()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738DE0) --------------------------------------------------------  // acclient.c:844804
void __cdecl _E659()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738E10) --------------------------------------------------------  // acclient.c:844817
void __cdecl _E662()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738E40) --------------------------------------------------------  // acclient.c:844830
void __cdecl _E665()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738E70) --------------------------------------------------------  // acclient.c:844843
void __cdecl _E668()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738EA0) --------------------------------------------------------  // acclient.c:844856
void __cdecl _E671()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738ED0) --------------------------------------------------------  // acclient.c:844869
void __cdecl _E674()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738F00) --------------------------------------------------------  // acclient.c:844882
void __cdecl _E677()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738F30) --------------------------------------------------------  // acclient.c:844895
void __cdecl _E680()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738F60) --------------------------------------------------------  // acclient.c:844908
void __cdecl _E683()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738F90) --------------------------------------------------------  // acclient.c:844921
void __cdecl _E686()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738FC0) --------------------------------------------------------  // acclient.c:844934
void __cdecl _E689()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00738FF0) --------------------------------------------------------  // acclient.c:844947
void __cdecl _E692()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739020) --------------------------------------------------------  // acclient.c:844960
void __cdecl _E695()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739050) --------------------------------------------------------  // acclient.c:844973
void __cdecl _E698()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739080) --------------------------------------------------------  // acclient.c:844986
void __cdecl _E701()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007390B0) --------------------------------------------------------  // acclient.c:844999
void __cdecl _E704()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007390E0) --------------------------------------------------------  // acclient.c:845012
void __cdecl _E707()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739110) --------------------------------------------------------  // acclient.c:845025
void __cdecl _E710()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739140) --------------------------------------------------------  // acclient.c:845038
void __cdecl _E713()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739170) --------------------------------------------------------  // acclient.c:845051
void __cdecl _E716()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007391A0) --------------------------------------------------------  // acclient.c:845064
void __cdecl _E719()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007391D0) --------------------------------------------------------  // acclient.c:845077
void __cdecl _E722()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739200) --------------------------------------------------------  // acclient.c:845090
void __cdecl _E725()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739230) --------------------------------------------------------  // acclient.c:845103
void __cdecl _E728()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739260) --------------------------------------------------------  // acclient.c:845116
void __cdecl _E731()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739290) --------------------------------------------------------  // acclient.c:845129
void __cdecl _E734()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007392C0) --------------------------------------------------------  // acclient.c:845142
void __cdecl _E737()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007392F0) --------------------------------------------------------  // acclient.c:845155
void __cdecl _E740()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739320) --------------------------------------------------------  // acclient.c:845168
void __cdecl _E743()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739350) --------------------------------------------------------  // acclient.c:845181
void __cdecl _E746()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739380) --------------------------------------------------------  // acclient.c:845194
void __cdecl _E749()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007393B0) --------------------------------------------------------  // acclient.c:845207
void __cdecl _E752()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007393E0) --------------------------------------------------------  // acclient.c:845220
void __cdecl _E755()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739410) --------------------------------------------------------  // acclient.c:845233
void __cdecl _E758()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739440) --------------------------------------------------------  // acclient.c:845246
void __cdecl _E761()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739470) --------------------------------------------------------  // acclient.c:845259
void __cdecl _E764()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007394A0) --------------------------------------------------------  // acclient.c:845272
void __cdecl _E767()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007394D0) --------------------------------------------------------  // acclient.c:845285
void __cdecl _E770()
{
  char *v0; // esi@1

  v0 = &NodeName_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739500) --------------------------------------------------------  // acclient.c:845298
void __cdecl _E773()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739530) --------------------------------------------------------  // acclient.c:845311
void __cdecl _E776()
{
  char *v0; // esi@1

  v0 = &SamplerName_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739560) --------------------------------------------------------  // acclient.c:845324
void __cdecl _E779()
{
  char *v0; // esi@1

  v0 = &Texture_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739590) --------------------------------------------------------  // acclient.c:845337
void __cdecl _E782()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007395C0) --------------------------------------------------------  // acclient.c:845350
void __cdecl _E785()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007395F0) --------------------------------------------------------  // acclient.c:845363
void __cdecl _E788()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739620) --------------------------------------------------------  // acclient.c:845376
void __cdecl _E791()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739650) --------------------------------------------------------  // acclient.c:845389
void __cdecl _E794()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739680) --------------------------------------------------------  // acclient.c:845402
void __cdecl _E797()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007396B0) --------------------------------------------------------  // acclient.c:845415
void __cdecl _E800()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007396E0) --------------------------------------------------------  // acclient.c:845428
void __cdecl _E803()
{
  char *v0; // esi@1

  v0 = &AddressMode_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739710) --------------------------------------------------------  // acclient.c:845441
void __cdecl _E806()
{
  char *v0; // esi@1

  v0 = &TexFilter_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739740) --------------------------------------------------------  // acclient.c:845454
void __cdecl _E809()
{
  char *v0; // esi@1

  v0 = &ColorOp_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739770) --------------------------------------------------------  // acclient.c:845467
void __cdecl _E812()
{
  char *v0; // esi@1

  v0 = &ColorArg1_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007397A0) --------------------------------------------------------  // acclient.c:845480
void __cdecl _E815()
{
  char *v0; // esi@1

  v0 = &ColorArg2_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007397D0) --------------------------------------------------------  // acclient.c:845493
void __cdecl _E818()
{
  char *v0; // esi@1

  v0 = &AlphaOp_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739800) --------------------------------------------------------  // acclient.c:845506
void __cdecl _E821()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739830) --------------------------------------------------------  // acclient.c:845519
void __cdecl _E824()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739860) --------------------------------------------------------  // acclient.c:845532
void __cdecl _E827()
{
  char *v0; // esi@1

  v0 = &TexCoord_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739890) --------------------------------------------------------  // acclient.c:845545
void __cdecl _E830()
{
  char *v0; // esi@1

  v0 = &UseProjection_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007398C0) --------------------------------------------------------  // acclient.c:845558
void __cdecl _E833()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007398F0) --------------------------------------------------------  // acclient.c:845571
void __cdecl _E836()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739920) --------------------------------------------------------  // acclient.c:845584
void __cdecl _E839()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739950) --------------------------------------------------------  // acclient.c:845597
void __cdecl _E842()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739980) --------------------------------------------------------  // acclient.c:845610
void __cdecl _E845()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007399B0) --------------------------------------------------------  // acclient.c:845623
void __cdecl _E848()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007399E0) --------------------------------------------------------  // acclient.c:845636
void __cdecl _E851()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739A10) --------------------------------------------------------  // acclient.c:845649
void __cdecl _E854()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739A40) --------------------------------------------------------  // acclient.c:845662
void __cdecl _E857()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739A70) --------------------------------------------------------  // acclient.c:845675
void __cdecl _E860()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739AA0) --------------------------------------------------------  // acclient.c:845688
void __cdecl _E863()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739AD0) --------------------------------------------------------  // acclient.c:845701
void __cdecl _E866()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739B00) --------------------------------------------------------  // acclient.c:845714
void __cdecl _E869()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739B30) --------------------------------------------------------  // acclient.c:845727
void __cdecl _E872()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739B60) --------------------------------------------------------  // acclient.c:845740
void __cdecl _E875()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739B90) --------------------------------------------------------  // acclient.c:845753
void __cdecl _E878()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739BC0) --------------------------------------------------------  // acclient.c:845766
void __cdecl _E881()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739BF0) --------------------------------------------------------  // acclient.c:845779
void __cdecl _E884()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739C20) --------------------------------------------------------  // acclient.c:845792
void __cdecl _E887()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739C50) --------------------------------------------------------  // acclient.c:845805
void __cdecl _E890()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739C80) --------------------------------------------------------  // acclient.c:845818
void __cdecl _E893()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739CB0) --------------------------------------------------------  // acclient.c:845831
void __cdecl _E896()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739CE0) --------------------------------------------------------  // acclient.c:845844
void __cdecl _E899()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739D10) --------------------------------------------------------  // acclient.c:845857
void __cdecl _E902()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739D40) --------------------------------------------------------  // acclient.c:845870
void __cdecl _E905()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739D70) --------------------------------------------------------  // acclient.c:845883
void __cdecl _E908()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739DA0) --------------------------------------------------------  // acclient.c:845896
void __cdecl _E911()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739DD0) --------------------------------------------------------  // acclient.c:845909
void __cdecl _E914()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739E00) --------------------------------------------------------  // acclient.c:845922
void __cdecl _E917()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739E30) --------------------------------------------------------  // acclient.c:845935
void __cdecl _E920()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739E60) --------------------------------------------------------  // acclient.c:845948
void __cdecl _E923()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739E90) --------------------------------------------------------  // acclient.c:845961
void __cdecl _E926()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739EC0) --------------------------------------------------------  // acclient.c:845974
void __cdecl _E929()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739EF0) --------------------------------------------------------  // acclient.c:845987
void __cdecl _E932()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739F20) --------------------------------------------------------  // acclient.c:846000
void __cdecl _E935()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739F50) --------------------------------------------------------  // acclient.c:846013
void __cdecl _E938()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739F80) --------------------------------------------------------  // acclient.c:846026
void __cdecl _E941()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739FB0) --------------------------------------------------------  // acclient.c:846039
void __cdecl _E944()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00739FE0) --------------------------------------------------------  // acclient.c:846052
void __cdecl _E947()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A010) --------------------------------------------------------  // acclient.c:846065
void __cdecl _E950()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A040) --------------------------------------------------------  // acclient.c:846078
void __cdecl _E953()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A070) --------------------------------------------------------  // acclient.c:846091
void __cdecl _E956()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A0A0) --------------------------------------------------------  // acclient.c:846104
void __cdecl _E959()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A0D0) --------------------------------------------------------  // acclient.c:846117
void __cdecl _E962()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A100) --------------------------------------------------------  // acclient.c:846130
void __cdecl _E965()
{
  char *v0; // esi@1

  v0 = &NodeName_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A130) --------------------------------------------------------  // acclient.c:846143
void __cdecl _E968()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A160) --------------------------------------------------------  // acclient.c:846156
void __cdecl _E971()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A190) --------------------------------------------------------  // acclient.c:846169
void __cdecl _E974()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A1C0) --------------------------------------------------------  // acclient.c:846182
void __cdecl _E977()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A1F0) --------------------------------------------------------  // acclient.c:846195
void __cdecl _E980()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A220) --------------------------------------------------------  // acclient.c:846208
void __cdecl _E983()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A250) --------------------------------------------------------  // acclient.c:846221
void __cdecl _E986()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A280) --------------------------------------------------------  // acclient.c:846234
void __cdecl _E989()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A2B0) --------------------------------------------------------  // acclient.c:846247
void __cdecl _E992()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A2E0) --------------------------------------------------------  // acclient.c:846260
void __cdecl _E995()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A310) --------------------------------------------------------  // acclient.c:846273
void __cdecl _E998()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A340) --------------------------------------------------------  // acclient.c:846286
void __cdecl _E1001()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A370) --------------------------------------------------------  // acclient.c:846299
void __cdecl _E1004()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A3A0) --------------------------------------------------------  // acclient.c:846312
void __cdecl _E1007()
{
  char *v0; // esi@1

  v0 = &NodeName_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A3D0) --------------------------------------------------------  // acclient.c:846325
void __cdecl _E1010()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A400) --------------------------------------------------------  // acclient.c:846338
void __cdecl _E1013()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A430) --------------------------------------------------------  // acclient.c:846351
void __cdecl _E1016()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A460) --------------------------------------------------------  // acclient.c:846364
void __cdecl _E1019()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A490) --------------------------------------------------------  // acclient.c:846377
void __cdecl _E1022()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A4C0) --------------------------------------------------------  // acclient.c:846390
void __cdecl _E1025()
{
  char *v0; // esi@1

  v0 = &ScaleType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A4F0) --------------------------------------------------------  // acclient.c:846403
void __cdecl _E1028()
{
  char *v0; // esi@1

  v0 = &WorldSpace_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A520) --------------------------------------------------------  // acclient.c:846416
void __cdecl _E1031()
{
  char *v0; // esi@1

  v0 = &ForceDraw_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A550) --------------------------------------------------------  // acclient.c:846429
void __cdecl _E1034()
{
  char *v0; // esi@1

  v0 = &NumEmitters_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A580) --------------------------------------------------------  // acclient.c:846442
void __cdecl _E1037()
{
  char *v0; // esi@1

  v0 = &Material_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A5B0) --------------------------------------------------------  // acclient.c:846455
void __cdecl _E1040()
{
  char *v0; // esi@1

  v0 = &Version_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A5E0) --------------------------------------------------------  // acclient.c:846468
void __cdecl _E1043()
{
  char *v0; // esi@1

  v0 = &MaxParticles_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A610) --------------------------------------------------------  // acclient.c:846481
void __cdecl _E1046()
{
  char *v0; // esi@1

  v0 = &NodeName_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A640) --------------------------------------------------------  // acclient.c:846494
void __cdecl _E1049()
{
  char *v0; // esi@1

  v0 = &Origin_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A670) --------------------------------------------------------  // acclient.c:846507
void __cdecl _E1052()
{
  char *v0; // esi@1

  v0 = &Shape_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A6A0) --------------------------------------------------------  // acclient.c:846520
void __cdecl _E1055()
{
  char *v0; // esi@1

  v0 = &Shape_Point_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A6D0) --------------------------------------------------------  // acclient.c:846533
void __cdecl _E1058()
{
  char *v0; // esi@1

  v0 = &Shape_Line_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A700) --------------------------------------------------------  // acclient.c:846546
void __cdecl _E1061()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A730) --------------------------------------------------------  // acclient.c:846559
void __cdecl _E1064()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A760) --------------------------------------------------------  // acclient.c:846572
void __cdecl _E1067()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A790) --------------------------------------------------------  // acclient.c:846585
void __cdecl _E1070()
{
  char *v0; // esi@1

  v0 = &ParticleShape_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A7C0) --------------------------------------------------------  // acclient.c:846598
void __cdecl _E1073()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A7F0) --------------------------------------------------------  // acclient.c:846611
void __cdecl _E1076()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A820) --------------------------------------------------------  // acclient.c:846624
void __cdecl _E1079()
{
  char *v0; // esi@1

  v0 = &Streak_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A850) --------------------------------------------------------  // acclient.c:846637
void __cdecl _E1082()
{
  char *v0; // esi@1

  v0 = &Rotation_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A880) --------------------------------------------------------  // acclient.c:846650
void __cdecl _E1085()
{
  char *v0; // esi@1

  v0 = &WorldRotation_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A8B0) --------------------------------------------------------  // acclient.c:846663
void __cdecl _E1088()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A8E0) --------------------------------------------------------  // acclient.c:846676
void __cdecl _E1091()
{
  char *v0; // esi@1

  v0 = &ParticleScale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A910) --------------------------------------------------------  // acclient.c:846689
void __cdecl _E1094()
{
  char *v0; // esi@1

  v0 = &Scale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A940) --------------------------------------------------------  // acclient.c:846702
void __cdecl _E1097()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A970) --------------------------------------------------------  // acclient.c:846715
void __cdecl _E1100()
{
  char *v0; // esi@1

  v0 = &BirthRate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A9A0) --------------------------------------------------------  // acclient.c:846728
void __cdecl _E1103()
{
  char *v0; // esi@1

  v0 = &Lifespan_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073A9D0) --------------------------------------------------------  // acclient.c:846741
void __cdecl _E1106()
{
  char *v0; // esi@1

  v0 = &Velocity_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AA00) --------------------------------------------------------  // acclient.c:846754
void __cdecl _E1109()
{
  char *v0; // esi@1

  v0 = &Direction_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AA30) --------------------------------------------------------  // acclient.c:846767
void __cdecl _E1112()
{
  char *v0; // esi@1

  v0 = &MinSpread_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AA60) --------------------------------------------------------  // acclient.c:846780
void __cdecl _E1115()
{
  char *v0; // esi@1

  v0 = &MaxSpread_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AA90) --------------------------------------------------------  // acclient.c:846793
void __cdecl _E1118()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AAC0) --------------------------------------------------------  // acclient.c:846806
void __cdecl _E1121()
{
  char *v0; // esi@1

  v0 = &BlastCount_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AAF0) --------------------------------------------------------  // acclient.c:846819
void __cdecl _E1124()
{
  char *v0; // esi@1

  v0 = &StartTime_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AB20) --------------------------------------------------------  // acclient.c:846832
void __cdecl _E1127()
{
  char *v0; // esi@1

  v0 = &TimeLimit_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AB50) --------------------------------------------------------  // acclient.c:846845
void __cdecl _E1130()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AB80) --------------------------------------------------------  // acclient.c:846858
void __cdecl _E1133()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ABB0) --------------------------------------------------------  // acclient.c:846871
void __cdecl _E1136()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ABE0) --------------------------------------------------------  // acclient.c:846884
void __cdecl _E1139()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AC10) --------------------------------------------------------  // acclient.c:846897
void __cdecl _E1142()
{
  char *v0; // esi@1

  v0 = &IsActive_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AC40) --------------------------------------------------------  // acclient.c:846910
void __cdecl _E1145()
{
  char *v0; // esi@1

  v0 = &FadeIn_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AC70) --------------------------------------------------------  // acclient.c:846923
void __cdecl _E1148()
{
  char *v0; // esi@1

  v0 = &FadeOut_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ACA0) --------------------------------------------------------  // acclient.c:846936
void __cdecl _E1151()
{
  char *v0; // esi@1

  v0 = &ConstrainX_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ACD0) --------------------------------------------------------  // acclient.c:846949
void __cdecl _E1154()
{
  char *v0; // esi@1

  v0 = &ConstrainY_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AD00) --------------------------------------------------------  // acclient.c:846962
void __cdecl _E1157()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AD30) --------------------------------------------------------  // acclient.c:846975
void __cdecl _E1160()
{
  char *v0; // esi@1

  v0 = &NodeName_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AD60) --------------------------------------------------------  // acclient.c:846988
void __cdecl _E1163()
{
  char *v0; // esi@1

  v0 = &Time_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AD90) --------------------------------------------------------  // acclient.c:847001
void __cdecl _E1166()
{
  char *v0; // esi@1

  v0 = &Flags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ADC0) --------------------------------------------------------  // acclient.c:847014
void __cdecl _E1169()
{
  char *v0; // esi@1

  v0 = &Flags_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073ADF0) --------------------------------------------------------  // acclient.c:847027
void __cdecl _E1172()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AE20) --------------------------------------------------------  // acclient.c:847040
void __cdecl _E1175()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AE50) --------------------------------------------------------  // acclient.c:847053
void __cdecl _E1178()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AE80) --------------------------------------------------------  // acclient.c:847066
void __cdecl _E1181()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AEB0) --------------------------------------------------------  // acclient.c:847079
void __cdecl _E1184()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AEE0) --------------------------------------------------------  // acclient.c:847092
void __cdecl _E1187()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AF10) --------------------------------------------------------  // acclient.c:847105
void __cdecl _E1190()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AF40) --------------------------------------------------------  // acclient.c:847118
void __cdecl _E1193()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AF70) --------------------------------------------------------  // acclient.c:847131
void __cdecl _E1196()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AFA0) --------------------------------------------------------  // acclient.c:847144
void __cdecl _E1199()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073AFD0) --------------------------------------------------------  // acclient.c:847157
void __cdecl _E1202()
{
  char *v0; // esi@1

  v0 = &Scale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B000) --------------------------------------------------------  // acclient.c:847170
void __cdecl _E1205()
{
  char *v0; // esi@1

  v0 = &ScaleX_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B030) --------------------------------------------------------  // acclient.c:847183
void __cdecl _E1208()
{
  char *v0; // esi@1

  v0 = &ScaleY_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B060) --------------------------------------------------------  // acclient.c:847196
void __cdecl _E1211()
{
  char *v0; // esi@1

  v0 = &Color_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B090) --------------------------------------------------------  // acclient.c:847209
void __cdecl _E1214()
{
  char *v0; // esi@1

  v0 = &Mass_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B0C0) --------------------------------------------------------  // acclient.c:847222
void __cdecl _E1217()
{
  char *v0; // esi@1

  v0 = &PFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B0F0) --------------------------------------------------------  // acclient.c:847235
void __cdecl _E1220()
{
  char *v0; // esi@1

  v0 = &PFlags_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B120) --------------------------------------------------------  // acclient.c:847248
void __cdecl _E1223()
{
  char *v0; // esi@1

  v0 = &PCType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B150) --------------------------------------------------------  // acclient.c:847261
void __cdecl _E1226()
{
  char *v0; // esi@1

  v0 = &PCType_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B180) --------------------------------------------------------  // acclient.c:847274
void __cdecl _E1229()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B1B0) --------------------------------------------------------  // acclient.c:847287
void __cdecl _E1232()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B1E0) --------------------------------------------------------  // acclient.c:847300
void __cdecl _E1235()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B210) --------------------------------------------------------  // acclient.c:847313
void __cdecl _E1238()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B240) --------------------------------------------------------  // acclient.c:847326
void __cdecl _E1241()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B270) --------------------------------------------------------  // acclient.c:847339
void __cdecl _E1244()
{
  char *v0; // esi@1

  v0 = &PhysFlags_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B2A0) --------------------------------------------------------  // acclient.c:847352
void __cdecl _E1247()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B2D0) --------------------------------------------------------  // acclient.c:847365
void __cdecl _E1250()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B300) --------------------------------------------------------  // acclient.c:847378
void __cdecl _E1253()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B330) --------------------------------------------------------  // acclient.c:847391
void __cdecl _E1256()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B360) --------------------------------------------------------  // acclient.c:847404
void __cdecl _E1259()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B390) --------------------------------------------------------  // acclient.c:847417
void __cdecl _E1262()
{
  char *v0; // esi@1

  v0 = &Position_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B3C0) --------------------------------------------------------  // acclient.c:847430
void __cdecl _E1265()
{
  char *v0; // esi@1

  v0 = &PointList_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B3F0) --------------------------------------------------------  // acclient.c:847443
void __cdecl _E1268()
{
  char *v0; // esi@1

  v0 = &Point_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B420) --------------------------------------------------------  // acclient.c:847456
void __cdecl _E1271()
{
  char *v0; // esi@1

  v0 = &DetailLevels_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B450) --------------------------------------------------------  // acclient.c:847469
void __cdecl _E1274()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B480) --------------------------------------------------------  // acclient.c:847482
void __cdecl _E1277()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B4B0) --------------------------------------------------------  // acclient.c:847495
void __cdecl _E1280_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B4E0) --------------------------------------------------------  // acclient.c:847508
void __cdecl _E1283()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B510) --------------------------------------------------------  // acclient.c:847521
void __cdecl _E1286()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B540) --------------------------------------------------------  // acclient.c:847534
void __cdecl _E1289()
{
  char *v0; // esi@1

  v0 = &Point_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B570) --------------------------------------------------------  // acclient.c:847547
void __cdecl _E1292_0()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B5A0) --------------------------------------------------------  // acclient.c:847560
void __cdecl _E1295()
{
  char *v0; // esi@1

  v0 = &PointTexture_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B5D0) --------------------------------------------------------  // acclient.c:847573
void __cdecl _E1298()
{
  char *v0; // esi@1

  v0 = &PointSize_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B600) --------------------------------------------------------  // acclient.c:847586
void __cdecl _E1301()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0073B630) --------------------------------------------------------  // acclient.c:847599
void __cdecl _E1313()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_8399EC;
  v1 = 4;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
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

