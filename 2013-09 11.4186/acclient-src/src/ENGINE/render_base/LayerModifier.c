/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LayerModifier
   Object     : ENGINE\render_base\LayerModifier.obj
   Functions  : 834
   Addresses  : 004507A0 - 0075B740 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004507A0) --------------------------------------------------------  // acclient.c:141856
void __thiscall LM_UVTranslate::LM_UVTranslate(LM_UVTranslate *this)
{
  LM_UVTranslate *v1; // esi@1
  Waveform *v2; // edi@1

  v1 = this;
  v2 = &this->uTranslate;
  this->vfptr = (LayerModifierVtbl *)&LM_UVTranslate::vftable;
  Waveform::Waveform(&this->uTranslate);
  Waveform::Waveform(&v1->vTranslate);
  v1->texCoordIndex = 0;
  Waveform::SetDefaults(v2);
  Waveform::SetDefaults(&v1->vTranslate);
}
// 79B4B4: using guessed type int (__thiscall *LM_UVTranslate::vftable)(ProjectileSpell *__hidden this);

//----- (004507E0) --------------------------------------------------------  // acclient.c:141873
signed int LM_UVTranslate::GetSize()
{
  return 96;
}

//----- (004507F0) --------------------------------------------------------  // acclient.c:141879
void __thiscall LM_UVTranslate::ApplyTextureTransform(LM_UVTranslate *this, Matrix4 *_mTextureMatrix)
{
  LM_UVTranslate *v2; // esi@1
  long double time; // ST14_8@1
  float x_4; // ST08_4@1
  float x; // ST04_4@1
  Matrix4 mTranslate; // [sp+18h] [bp-80h]@1
  Matrix4 mFinal; // [sp+58h] [bp-40h]@1

  v2 = this;
  time = Timer::local_time;
  x_4 = Waveform::GetValue(&this->vTranslate, Timer::local_time);
  x = Waveform::GetValue(&v2->uTranslate, time);
  Matrix4::Translate3(&mTranslate, x, x_4);
  Matrix4::Multiply_C(&mFinal, _mTextureMatrix, &mTranslate);
  qmemcpy(_mTextureMatrix, &mFinal, 0x40u);
}

//----- (00450870) --------------------------------------------------------  // acclient.c:141898
void __thiscall LM_UVRotate::LM_UVRotate(LM_UVRotate *this)
{
  LM_UVRotate *v1; // esi@1
  Waveform *v2; // edi@1

  v1 = this;
  v2 = &this->rotate;
  this->vfptr = (LayerModifierVtbl *)&LM_UVRotate::vftable;
  Waveform::Waveform(&this->rotate);
  v1->texCoordIndex = 0;
  Waveform::SetDefaults(v2);
}
// 79B4DC: using guessed type unsigned __int32 (__thiscall *LM_UVRotate::vftable)(CLandBlockInfo *__hidden this);

//----- (004508A0) --------------------------------------------------------  // acclient.c:141913
signed int LM_UVRotate::GetSize()
{
  return 52;
}

//----- (004508B0) --------------------------------------------------------  // acclient.c:141919
void __thiscall LM_UVRotate::ApplyTextureTransform(LM_UVRotate *this, Matrix4 *_mTextureMatrix)
{
  float radians; // ST04_4@1
  Matrix4 mRotate; // [sp+Ch] [bp-80h]@1
  Matrix4 mFinal; // [sp+4Ch] [bp-40h]@1

  radians = Waveform::GetValue(&this->rotate, Timer::local_time) * 0.017453292;
  Matrix4::RotateZ(&mRotate, radians);
  Matrix4::Multiply_C(&mFinal, _mTextureMatrix, &mRotate);
  qmemcpy(_mTextureMatrix, &mFinal, 0x40u);
}

//----- (00450910) --------------------------------------------------------  // acclient.c:141932
void __thiscall LM_UVScale::LM_UVScale(LM_UVScale *this)
{
  LM_UVScale *v1; // esi@1
  Waveform *v2; // edi@1

  v1 = this;
  v2 = &this->uScale;
  this->vfptr = (LayerModifierVtbl *)&LM_UVScale::vftable;
  Waveform::Waveform(&this->uScale);
  Waveform::Waveform(&v1->vScale);
  v1->texCoordIndex = 0;
  Waveform::SetDefaults(v2);
  LODWORD(v1->uScale.base) = 1065353216;
  Waveform::SetDefaults(&v1->vScale);
  LODWORD(v1->vScale.base) = 1065353216;
}
// 79B508: using guessed type enum NodeNameType (__thiscall *LM_UVScale::vftable)(FileNodeName_Double *__hidden this);

//----- (00450960) --------------------------------------------------------  // acclient.c:141951
void __thiscall LM_UVScale::ApplyTextureTransform(LM_UVScale *this, Matrix4 *_mTextureMatrix)
{
  LM_UVScale *v2; // esi@1
  long double time; // ST18_8@1
  float x_4; // ST08_4@1
  float x; // ST04_4@1
  Matrix4 mScale; // [sp+1Ch] [bp-80h]@1
  Matrix4 mFinal; // [sp+5Ch] [bp-40h]@1

  v2 = this;
  time = Timer::local_time;
  x_4 = Waveform::GetValue(&this->vScale, Timer::local_time);
  x = Waveform::GetValue(&v2->uScale, time);
  Matrix4::Scale(&mScale, x, x_4, 1.0);
  Matrix4::Multiply_C(&mFinal, _mTextureMatrix, &mScale);
  qmemcpy(_mTextureMatrix, &mFinal, 0x40u);
}

//----- (004509E0) --------------------------------------------------------  // acclient.c:141970
void __thiscall LM_UVTransform::LM_UVTransform(LM_UVTransform *this)
{
  this->vfptr = (LayerModifierVtbl *)&LM_UVTransform::vftable;
  this->m_nStageIndex = 0;
  LODWORD(this->m_mTransform._14) = 0;
  LODWORD(this->m_mTransform._13) = 0;
  LODWORD(this->m_mTransform._12) = 0;
  LODWORD(this->m_mTransform._24) = 0;
  LODWORD(this->m_mTransform._23) = 0;
  LODWORD(this->m_mTransform._21) = 0;
  LODWORD(this->m_mTransform._34) = 0;
  LODWORD(this->m_mTransform._32) = 0;
  LODWORD(this->m_mTransform._31) = 0;
  LODWORD(this->m_mTransform._43) = 0;
  LODWORD(this->m_mTransform._42) = 0;
  LODWORD(this->m_mTransform._41) = 0;
  LODWORD(this->m_mTransform._44) = 1065353216;
  LODWORD(this->m_mTransform._33) = 1065353216;
  LODWORD(this->m_mTransform._22) = 1065353216;
  LODWORD(this->m_mTransform._11) = 1065353216;
}
// 79B530: using guessed type unsigned int (__thiscall *LM_UVTransform::vftable)(EtherealHook *__hidden this);

//----- (00450A30) --------------------------------------------------------  // acclient.c:141994
signed int LM_UVTransform::GetSize()
{
  return 72;
}

//----- (00450A40) --------------------------------------------------------  // acclient.c:142000
void __thiscall LM_UVTransform::ApplyTextureTransform(LM_UVTransform *this, Matrix4 *_mTextureMatrix)
{
  Matrix4 mFinal; // [sp+8h] [bp-40h]@1

  Matrix4::Multiply_C(&mFinal, _mTextureMatrix, &this->m_mTransform);
  qmemcpy(_mTextureMatrix, &mFinal, 0x40u);
}

//----- (00450A70) --------------------------------------------------------  // acclient.c:142009
int __thiscall LM_UVScale::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(this + 60) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(this + 64) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(this + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(this + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(this + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(this + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(this + 84) = *(_DWORD *)(a2 + 84);
  *(_DWORD *)(this + 88) = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(this + 92) = *(_DWORD *)(a2 + 92);
  return result;
}

//----- (00450B10) --------------------------------------------------------  // acclient.c:142041
int __thiscall LM_UVRotate::Copy(LM_UVRotate *this)
{
  int v1; // ebx@1
  void *v2; // eax@1
  int v3; // esi@1
  int result; // eax@2

  v1 = (int)this;
  v2 = operator new(0x34u);
  v3 = (int)v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = &LM_UVRotate::vftable;
    Waveform::Waveform((Waveform *)((char *)v2 + 8));
    *(_DWORD *)(v3 + 4) = 0;
    Waveform::SetDefaults((Waveform *)(v3 + 8));
    LM_UVRotate::operator=(v3, v1);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79B4DC: using guessed type unsigned __int32 (__thiscall *LM_UVRotate::vftable)(CLandBlockInfo *__hidden this);

//----- (00450B60) --------------------------------------------------------  // acclient.c:142069
LayerModifier *__thiscall LM_UVScale::Copy(LM_UVScale *this)
{
  int v1; // edi@1
  LM_UVScale *v2; // eax@1
  int v3; // eax@2
  LayerModifier *v4; // esi@2
  LayerModifier *result; // eax@3

  v1 = (int)this;
  v2 = (LM_UVScale *)operator new(0x60u);
  if ( v2 && (LM_UVScale::LM_UVScale(v2), (v4 = (LayerModifier *)v3) != 0) )
  {
    LM_UVScale::operator=(v3, v1);
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00450BA0) --------------------------------------------------------  // acclient.c:142092
LayerModifier *__thiscall LM_UVTransform::Copy(LM_UVTransform *this)
{
  LM_UVTransform *v1; // esi@1
  LayerModifier *result; // eax@1
  LayerModifier *v3; // edi@2

  v1 = this;
  result = (LayerModifier *)operator new(0x48u);
  if ( result )
  {
    result[1].vfptr = 0;
    result->vfptr = (LayerModifierVtbl *)&LM_UVTransform::vftable;
    v3 = result + 2;
    v3[3].vfptr = 0;
    v3[2].vfptr = 0;
    v3[1].vfptr = 0;
    v3[7].vfptr = 0;
    v3[6].vfptr = 0;
    v3[4].vfptr = 0;
    v3[11].vfptr = 0;
    v3[9].vfptr = 0;
    v3[8].vfptr = 0;
    v3[14].vfptr = 0;
    v3[13].vfptr = 0;
    v3[12].vfptr = 0;
    v3[15].vfptr = (LayerModifierVtbl *)1065353216;
    v3[10].vfptr = (LayerModifierVtbl *)1065353216;
    v3[5].vfptr = (LayerModifierVtbl *)1065353216;
    v3->vfptr = (LayerModifierVtbl *)1065353216;
    result[1].vfptr = (LayerModifierVtbl *)v1->m_nStageIndex;
    qmemcpy(&result[2], &v1->m_mTransform, 0x40u);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79B530: using guessed type unsigned int (__thiscall *LM_UVTransform::vftable)(EtherealHook *__hidden this);

//----- (00450C10) --------------------------------------------------------  // acclient.c:142133
int __thiscall LM_UVTranslate::Copy(LM_UVTranslate *this)
{
  int v1; // ebp@1
  void *v2; // eax@1
  int v3; // esi@1
  int result; // eax@2

  v1 = (int)this;
  v2 = operator new(0x60u);
  v3 = (int)v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = &LM_UVTranslate::vftable;
    Waveform::Waveform((Waveform *)((char *)v2 + 8));
    Waveform::Waveform((Waveform *)(v3 + 52));
    *(_DWORD *)(v3 + 4) = 0;
    Waveform::SetDefaults((Waveform *)(v3 + 8));
    Waveform::SetDefaults((Waveform *)(v3 + 52));
    LM_UVScale::operator=(v3, v1);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79B4B4: using guessed type int (__thiscall *LM_UVTranslate::vftable)(ProjectileSpell *__hidden this);

//----- (00450C70) --------------------------------------------------------  // acclient.c:142163
char __thiscall LM_UVTranslate::SaveToFileNode(LM_UVTranslate *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  int v5; // eax@1
  PStringBase<char> v6; // ebx@1
  volatile LONG *v7; // ebp@1
  PFileNode *v8; // edi@1
  int v9; // ebx@1
  int v10; // eax@4
  PStringBase<char> v11; // ebp@4
  PFileNode *v12; // ebx@4
  int v13; // ebp@4
  int v14; // ebx@7
  int v15; // ecx@7
  unsigned int v16; // ebp@7
  void *v17; // eax@9
  int v18; // eax@12
  PStringBase<char> v19; // ebx@12
  volatile LONG *v20; // ebp@12
  PFileNode *v21; // edi@12
  int v22; // ebx@12
  int v23; // eax@16
  PStringBase<char> v24; // ebx@16
  volatile LONG *v25; // ebp@16
  int v26; // ebx@16
  int v27; // eax@21
  PStringBase<char> v28; // edi@21
  volatile LONG *v29; // ebx@21
  PFileNode *v30; // ebp@21
  int v31; // edi@21
  char *v32; // esi@25
  PStringBase<char> propString; // [sp+10h] [bp-8h]@1
  LM_UVTranslate *v35; // [sp+14h] [bp-4h]@1
  PFileNode *baseNodea; // [sp+1Ch] [bp+4h]@4
  PFileNode *baseNodeb; // [sp+1Ch] [bp+4h]@16

  propString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v35 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = ((int (*)(void))baseNode->vfptr[1].__vecDelDtor)();
  v6.m_charbuffer = ModType_UVTranslate_7.m_charbuffer;
  v7 = (volatile LONG *)&ModType_UVTranslate_7.m_charbuffer[-1];
  v8 = (PFileNode *)v5;
  InterlockedIncrement((volatile LONG *)&ModType_UVTranslate_7.m_charbuffer[-1]);
  InterlockedIncrement(v7);
  PFileNode::SetNameAsPString(v8, v6);
  v9 = (int)&v6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v11.m_charbuffer = Mod_UVTranslate_texCoordIndex_7.m_charbuffer;
  v12 = (PFileNode *)v10;
  baseNodea = (PFileNode *)&Mod_UVTranslate_texCoordIndex_7.m_charbuffer[-1];
  InterlockedIncrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_7.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)baseNodea);
  PFileNode::SetNameAsPString(v12, v11);
  v13 = (int)&v11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = ((int (__thiscall *)(PFileNode *))v12->vfptr[1].__vecDelDtor)(v12);
  v15 = *(_DWORD *)(v14 + 8);
  v16 = v35->texCoordIndex;
  if ( v15 )
    (**(void (__stdcall ***)(_DWORD))v15)(1);
  *(_DWORD *)(v14 + 8) = 0;
  v17 = operator new(8u);
  if ( v17 )
  {
    *(_DWORD *)v17 = &FileNodeName_UInt32::vftable;
    *((_DWORD *)v17 + 1) = v16;
  }
  else
  {
    v17 = 0;
  }
  *(_DWORD *)(v14 + 8) = v17;
  v18 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v19.m_charbuffer = Mod_UVTranslate_translate_7.m_charbuffer;
  v20 = (volatile LONG *)&Mod_UVTranslate_translate_7.m_charbuffer[-1];
  v21 = (PFileNode *)v18;
  InterlockedIncrement((volatile LONG *)&Mod_UVTranslate_translate_7.m_charbuffer[-1]);
  InterlockedIncrement(v20);
  PFileNode::SetNameAsPString(v21, v19);
  v22 = (int)&v19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  if ( RenderMaterial::CheckOutputField(
         owner,
         &propString,
         RMFIELD_LAYER_MOD_UVTRANSLATE_UTRANSLATE,
         RMDATA_WAVEFORM,
         layerIndex,
         modIndex) )
  {
    v23 = ((int (__thiscall *)(PFileNode *))v21->vfptr[1].__vecDelDtor)(v21);
    v24.m_charbuffer = propString.m_charbuffer;
    v25 = (volatile LONG *)&propString.m_charbuffer[-1];
    baseNodeb = (PFileNode *)v23;
    InterlockedIncrement((volatile LONG *)&propString.m_charbuffer[-1]);
    InterlockedIncrement(v25);
    PFileNode::SetNameAsPString(baseNodeb, v24);
    v26 = (int)&v24.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) && v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  }
  else
  {
    Waveform::Output(&v35->uTranslate, v21);
  }
  if ( RenderMaterial::CheckOutputField(
         owner,
         &propString,
         RMFIELD_LAYER_MOD_UVTRANSLATE_VTRANSLATE,
         RMDATA_WAVEFORM,
         layerIndex,
         modIndex) )
  {
    v27 = ((int (__thiscall *)(PFileNode *))v21->vfptr[1].__vecDelDtor)(v21);
    v28.m_charbuffer = propString.m_charbuffer;
    v29 = (volatile LONG *)&propString.m_charbuffer[-1];
    v30 = (PFileNode *)v27;
    InterlockedIncrement((volatile LONG *)&propString.m_charbuffer[-1]);
    InterlockedIncrement(v29);
    PFileNode::SetNameAsPString(v30, v28);
    v31 = (int)&v28.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v31 + 4)) && v31 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
  }
  else
  {
    Waveform::Output(&v35->vTranslate, v21);
  }
  v32 = &propString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&propString.m_charbuffer[-1]) && v32 )
    (**(void (__thiscall ***)(char *, signed int))v32)(v32, 1);
  return 1;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (00450EC0) --------------------------------------------------------  // acclient.c:142302
void __thiscall LM_UVRotate::Serialize(LM_UVRotate *this, Archive *io_archive)
{
  LM_UVRotate *v2; // edi@1
  char v3; // bl@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@4

  v2 = this;
  v3 = ((int (*)(void))this->vfptr->GetType)();
  Archive::CheckAlignment(io_archive, 1u);
  v4 = Archive::GetBytes(io_archive, 1u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v4 = v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v5 = v2->texCoordIndex;
      Waveform::Serialize(&v2->rotate, io_archive);
      return;
    }
    v2->texCoordIndex = *(_DWORD *)v5;
  }
  Waveform::Serialize(&v2->rotate, io_archive);
}

//----- (00450F40) --------------------------------------------------------  // acclient.c:142334
char __thiscall LM_UVRotate::SaveToFileNode(LM_UVRotate *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  int v5; // eax@1
  PStringBase<char> v6; // ebx@1
  volatile LONG *v7; // ebp@1
  PFileNode *v8; // edi@1
  int v9; // ebx@1
  int v10; // eax@4
  PStringBase<char> v11; // ebp@4
  PFileNode *v12; // ebx@4
  int v13; // ebp@4
  int v14; // ebx@7
  int v15; // ecx@7
  unsigned int v16; // ebp@7
  void *v17; // eax@9
  int v18; // eax@12
  PStringBase<char> v19; // ebx@12
  volatile LONG *v20; // ebp@12
  PFileNode *v21; // edi@12
  int v22; // ebx@12
  int v23; // eax@16
  PStringBase<char> v24; // edi@16
  volatile LONG *v25; // ebx@16
  PFileNode *v26; // ebp@16
  char *v27; // esi@20
  PStringBase<char> propString; // [sp+10h] [bp-8h]@1
  LM_UVRotate *v30; // [sp+14h] [bp-4h]@1
  PFileNode *baseNodea; // [sp+1Ch] [bp+4h]@4

  propString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v30 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = ((int (*)(void))baseNode->vfptr[1].__vecDelDtor)();
  v6.m_charbuffer = ModType_UVRotate_7.m_charbuffer;
  v7 = (volatile LONG *)&ModType_UVRotate_7.m_charbuffer[-1];
  v8 = (PFileNode *)v5;
  InterlockedIncrement((volatile LONG *)&ModType_UVRotate_7.m_charbuffer[-1]);
  InterlockedIncrement(v7);
  PFileNode::SetNameAsPString(v8, v6);
  v9 = (int)&v6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v11.m_charbuffer = Mod_UVRotate_texCoordIndex_7.m_charbuffer;
  v12 = (PFileNode *)v10;
  baseNodea = (PFileNode *)&Mod_UVRotate_texCoordIndex_7.m_charbuffer[-1];
  InterlockedIncrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_7.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)baseNodea);
  PFileNode::SetNameAsPString(v12, v11);
  v13 = (int)&v11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = ((int (__thiscall *)(PFileNode *))v12->vfptr[1].__vecDelDtor)(v12);
  v15 = *(_DWORD *)(v14 + 8);
  v16 = v30->texCoordIndex;
  if ( v15 )
    (**(void (__stdcall ***)(_DWORD))v15)(1);
  *(_DWORD *)(v14 + 8) = 0;
  v17 = operator new(8u);
  if ( v17 )
  {
    *(_DWORD *)v17 = &FileNodeName_UInt32::vftable;
    *((_DWORD *)v17 + 1) = v16;
  }
  else
  {
    v17 = 0;
  }
  *(_DWORD *)(v14 + 8) = v17;
  v18 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v19.m_charbuffer = Mod_UVRotate_rotate_7.m_charbuffer;
  v20 = (volatile LONG *)&Mod_UVRotate_rotate_7.m_charbuffer[-1];
  v21 = (PFileNode *)v18;
  InterlockedIncrement((volatile LONG *)&Mod_UVRotate_rotate_7.m_charbuffer[-1]);
  InterlockedIncrement(v20);
  PFileNode::SetNameAsPString(v21, v19);
  v22 = (int)&v19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  if ( RenderMaterial::CheckOutputField(
         owner,
         &propString,
         RMFIELD_LAYER_MOD_UVROTATE_ROTATE,
         RMDATA_WAVEFORM,
         layerIndex,
         modIndex) )
  {
    v23 = ((int (__thiscall *)(PFileNode *))v21->vfptr[1].__vecDelDtor)(v21);
    v24.m_charbuffer = propString.m_charbuffer;
    v25 = (volatile LONG *)&propString.m_charbuffer[-1];
    v26 = (PFileNode *)v23;
    InterlockedIncrement((volatile LONG *)&propString.m_charbuffer[-1]);
    InterlockedIncrement(v25);
    PFileNode::SetNameAsPString(v26, v24);
    if ( !InterlockedDecrement((volatile LONG *)&v24.m_charbuffer[-1])
      && v24.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v24.m_charbuffer[-2].m_data[12])(
        &v24.m_charbuffer[-2].m_data[12],
        1);
  }
  else
  {
    Waveform::Output(&v30->rotate, v21);
  }
  v27 = &propString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&propString.m_charbuffer[-1]) && v27 )
    (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
  return 1;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (00451110) --------------------------------------------------------  // acclient.c:142446
void __thiscall LM_UVTranslate::Serialize(LM_UVScale *this, Archive *io_archive)
{
  LM_UVScale *v2; // edi@1
  char v3; // bl@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@4

  v2 = this;
  v3 = ((int (*)(void))this->vfptr->GetType)();
  Archive::CheckAlignment(io_archive, 1u);
  v4 = Archive::GetBytes(io_archive, 1u);
  if ( v4 && io_archive->m_flags & 1 )
    *(_BYTE *)v4 = v3;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->texCoordIndex;
    else
      v2->texCoordIndex = *(_DWORD *)v5;
  }
  Waveform::Serialize(&v2->uScale, io_archive);
  Waveform::Serialize(&v2->vScale, io_archive);
}

//----- (00451180) --------------------------------------------------------  // acclient.c:142473
char __thiscall LM_UVScale::SaveToFileNode(LM_UVScale *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  int v5; // eax@1
  PStringBase<char> v6; // ebx@1
  volatile LONG *v7; // ebp@1
  PFileNode *v8; // edi@1
  int v9; // ebx@1
  int v10; // eax@4
  PStringBase<char> v11; // ebp@4
  PFileNode *v12; // ebx@4
  int v13; // ebp@4
  int v14; // ebx@7
  int v15; // ecx@7
  unsigned int v16; // ebp@7
  void *v17; // eax@9
  int v18; // eax@12
  PStringBase<char> v19; // ebx@12
  volatile LONG *v20; // ebp@12
  PFileNode *v21; // edi@12
  int v22; // ebx@12
  int v23; // eax@16
  PStringBase<char> v24; // ebx@16
  volatile LONG *v25; // ebp@16
  int v26; // ebx@16
  int v27; // eax@21
  PStringBase<char> v28; // edi@21
  volatile LONG *v29; // ebx@21
  PFileNode *v30; // ebp@21
  int v31; // edi@21
  char *v32; // esi@25
  PStringBase<char> propString; // [sp+10h] [bp-8h]@1
  LM_UVScale *v35; // [sp+14h] [bp-4h]@1
  PFileNode *baseNodea; // [sp+1Ch] [bp+4h]@4
  PFileNode *baseNodeb; // [sp+1Ch] [bp+4h]@16

  propString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v35 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = ((int (*)(void))baseNode->vfptr[1].__vecDelDtor)();
  v6.m_charbuffer = ModType_UVScale_7.m_charbuffer;
  v7 = (volatile LONG *)&ModType_UVScale_7.m_charbuffer[-1];
  v8 = (PFileNode *)v5;
  InterlockedIncrement((volatile LONG *)&ModType_UVScale_7.m_charbuffer[-1]);
  InterlockedIncrement(v7);
  PFileNode::SetNameAsPString(v8, v6);
  v9 = (int)&v6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v11.m_charbuffer = Mod_UVScale_texCoordIndex_7.m_charbuffer;
  v12 = (PFileNode *)v10;
  baseNodea = (PFileNode *)&Mod_UVScale_texCoordIndex_7.m_charbuffer[-1];
  InterlockedIncrement((volatile LONG *)&Mod_UVScale_texCoordIndex_7.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)baseNodea);
  PFileNode::SetNameAsPString(v12, v11);
  v13 = (int)&v11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = ((int (__thiscall *)(PFileNode *))v12->vfptr[1].__vecDelDtor)(v12);
  v15 = *(_DWORD *)(v14 + 8);
  v16 = v35->texCoordIndex;
  if ( v15 )
    (**(void (__stdcall ***)(_DWORD))v15)(1);
  *(_DWORD *)(v14 + 8) = 0;
  v17 = operator new(8u);
  if ( v17 )
  {
    *(_DWORD *)v17 = &FileNodeName_UInt32::vftable;
    *((_DWORD *)v17 + 1) = v16;
  }
  else
  {
    v17 = 0;
  }
  *(_DWORD *)(v14 + 8) = v17;
  v18 = ((int (__thiscall *)(PFileNode *))v8->vfptr[1].__vecDelDtor)(v8);
  v19.m_charbuffer = Mod_UVScale_scale_7.m_charbuffer;
  v20 = (volatile LONG *)&Mod_UVScale_scale_7.m_charbuffer[-1];
  v21 = (PFileNode *)v18;
  InterlockedIncrement((volatile LONG *)&Mod_UVScale_scale_7.m_charbuffer[-1]);
  InterlockedIncrement(v20);
  PFileNode::SetNameAsPString(v21, v19);
  v22 = (int)&v19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  if ( RenderMaterial::CheckOutputField(
         owner,
         &propString,
         RMFIELD_LAYER_MOD_UVSCALE_USCALE,
         RMDATA_WAVEFORM,
         layerIndex,
         modIndex) )
  {
    v23 = ((int (__thiscall *)(PFileNode *))v21->vfptr[1].__vecDelDtor)(v21);
    v24.m_charbuffer = propString.m_charbuffer;
    v25 = (volatile LONG *)&propString.m_charbuffer[-1];
    baseNodeb = (PFileNode *)v23;
    InterlockedIncrement((volatile LONG *)&propString.m_charbuffer[-1]);
    InterlockedIncrement(v25);
    PFileNode::SetNameAsPString(baseNodeb, v24);
    v26 = (int)&v24.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) && v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  }
  else
  {
    Waveform::Output(&v35->uScale, v21);
  }
  if ( RenderMaterial::CheckOutputField(
         owner,
         &propString,
         RMFIELD_LAYER_MOD_UVSCALE_VSCALE,
         RMDATA_WAVEFORM,
         layerIndex,
         modIndex) )
  {
    v27 = ((int (__thiscall *)(PFileNode *))v21->vfptr[1].__vecDelDtor)(v21);
    v28.m_charbuffer = propString.m_charbuffer;
    v29 = (volatile LONG *)&propString.m_charbuffer[-1];
    v30 = (PFileNode *)v27;
    InterlockedIncrement((volatile LONG *)&propString.m_charbuffer[-1]);
    InterlockedIncrement(v29);
    PFileNode::SetNameAsPString(v30, v28);
    v31 = (int)&v28.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v31 + 4)) && v31 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
  }
  else
  {
    Waveform::Output(&v35->vScale, v21);
  }
  v32 = &propString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&propString.m_charbuffer[-1]) && v32 )
    (**(void (__thiscall ***)(char *, signed int))v32)(v32, 1);
  return 1;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (004513D0) --------------------------------------------------------  // acclient.c:142612
void __thiscall LM_UVTransform::Serialize(LM_UVTransform *this, Archive *io_archive)
{
  LM_UVTransform *v2; // edi@1
  char v3; // bl@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@4
  const void *v6; // edi@8
  unsigned int v7; // eax@8

  v2 = this;
  v3 = ((int (*)(void))this->vfptr->GetType)();
  Archive::CheckAlignment(io_archive, 1u);
  v4 = Archive::GetBytes(io_archive, 1u);
  if ( v4 && io_archive->m_flags & 1 )
    *(_BYTE *)v4 = v3;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_nStageIndex;
    else
      v2->m_nStageIndex = *(_DWORD *)v5;
  }
  v6 = &v2->m_mTransform;
  Archive::CheckAlignment(io_archive, 0x40u);
  v7 = Archive::GetBytes(io_archive, 0x40u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      qmemcpy((void *)v7, v6, 0x40u);
    else
      qmemcpy((void *)v6, (const void *)v7, 0x40u);
  }
}

//----- (00451460) --------------------------------------------------------  // acclient.c:142649
bool __thiscall LM_UVTranslate::LoadFromFileNode(LM_UVTranslate *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  int v5; // edi@2
  PFileNode *v6; // esi@2
  const unsigned int v7; // ebp@3
  const unsigned int v8; // ebx@3
  ReferenceCountTemplate<1048576,0>Vtbl *v9; // edx@5
  PFileNode *v10; // esi@5
  PSRefBufferCharData<char> *v11; // ecx@6
  ReferenceCountTemplate<1048576,0>Vtbl *v12; // edx@7
  ReferenceCountTemplate<1048576,0>Vtbl *v13; // eax@9
  PFileNode *v14; // esi@9
  char *v15; // esi@11
  int v16; // edx@13
  const unsigned int v17; // esi@15
  int v18; // edx@17
  int v19; // edx@22
  bool result; // al@23
  PStringBase<char> v21; // [sp-4h] [bp-2Ch]@5
  int v22; // [sp+10h] [bp-18h]@1
  PStringBase<char> paramText; // [sp+14h] [bp-14h]@2
  LM_UVTranslate *v24; // [sp+18h] [bp-10h]@1
  PFileNodeIter iter; // [sp+1Ch] [bp-Ch]@2

  v24 = this;
  BYTE3(v22) = 1;
  if ( baseNode )
  {
    PFileNodeIter::PFileNodeIter(&iter, baseNode);
    v5 = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    paramText.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v6 = PFileNodeIter::Curr(&iter);
    if ( v6 )
    {
      v7 = modIndex;
      v8 = layerIndex;
      do
      {
        modIndex = (const unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PFileNode::GetNameAsPString(v6, v5, (PStringBase<char> *)&modIndex);
        if ( PFileNode::IsKeyword(v6, v5, &Mod_UVTranslate_texCoordIndex_7) )
        {
          v9 = v6->vfptr;
          v21.m_charbuffer = 0;
          v10 = (PFileNode *)v9[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString(v10, v5, &paramText);
          PFileNode::GetNameAsUInt32(v10, v5, &v24->texCoordIndex);
        }
        else if ( PFileNode::IsKeyword(v6, v5, &Mod_UVTranslate_translate_7) )
        {
          v12 = v6->vfptr;
          v21.m_charbuffer = 0;
          v5 = (int)v12[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString((PFileNode *)v5, v5, &paramText);
          baseNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PFileNode::GetNameAsPString((PFileNode *)v5, v5, (PStringBase<char> *)&baseNode);
          if ( !RenderMaterial::CheckParseField(
                  owner,
                  (PStringBase<char> *)&baseNode,
                  RMFIELD_LAYER_MOD_UVTRANSLATE_UTRANSLATE,
                  RMDATA_WAVEFORM,
                  v8,
                  v7) )
            Waveform::Parse(&v24->uTranslate, (PFileNode *)v5);
          v13 = v6->vfptr;
          v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
          v14 = (PFileNode *)v13[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
          PFileNode::GetNameAsPString(v14, v5, &paramText);
          PFileNode::GetNameAsPString(v14, v5, (PStringBase<char> *)&baseNode);
          if ( !RenderMaterial::CheckParseField(
                  owner,
                  (PStringBase<char> *)&baseNode,
                  RMFIELD_LAYER_MOD_UVTRANSLATE_VTRANSLATE,
                  RMDATA_WAVEFORM,
                  v8,
                  v7) )
            Waveform::Parse(&v24->vTranslate, v14);
          v15 = (char *)&baseNode[-1].sub_nodes.m_num;
          if ( !InterlockedDecrement((volatile LONG *)&baseNode[-1].m_bProcessed) && v15 )
          {
            v16 = *(_DWORD *)v15;
            v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
            (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
          }
        }
        else
        {
          v21.m_charbuffer = v11;
          PStringBase<char>::PStringBase<char>(&v21, "Invalid UVTranslate keyword");
          PFileNode::ReportError(v5, v6, v21);
          BYTE3(v22) = 0;
        }
        v17 = modIndex - 20;
        if ( !InterlockedDecrement((volatile LONG *)(modIndex - 20 + 4)) && v17 )
        {
          v18 = *(_DWORD *)v17;
          v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
          (*(void (__thiscall **)(const unsigned int, signed int))v18)(v17, 1);
        }
        v6 = (PFileNode *)PFileNodeIter::Next(&iter);
      }
      while ( v6 );
      v5 = (int)paramText.m_charbuffer;
    }
    if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v5 != 20 )
    {
      v19 = *(_DWORD *)(v5 - 20);
      v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(int, signed int))v19)(v5 - 20, 1);
    }
    PFileNodeIter::~PFileNodeIter(&iter);
    result = BYTE3(v22);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00451690) --------------------------------------------------------  // acclient.c:142773
bool __thiscall LM_UVRotate::LoadFromFileNode(LM_UVRotate *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  PSRefBufferCharData<char> *v5; // ebx@2
  PFileNode *v6; // esi@2
  const unsigned int v7; // ebp@3
  const unsigned int v8; // ebx@3
  ReferenceCountTemplate<1048576,0>Vtbl *v9; // edx@5
  PFileNode *v10; // esi@5
  PSRefBufferCharData<char> *v11; // ecx@6
  ReferenceCountTemplate<1048576,0>Vtbl *v12; // edx@7
  PFileNode *v13; // esi@7
  char *v14; // esi@9
  int v15; // edx@11
  int v16; // edx@17
  bool result; // al@18
  PStringBase<char> v18; // [sp-4h] [bp-2Ch]@5
  bool retval; // [sp+13h] [bp-15h]@1
  PStringBase<char> paramText; // [sp+14h] [bp-14h]@2
  LM_UVRotate *v21; // [sp+18h] [bp-10h]@1
  PFileNodeIter iter; // [sp+1Ch] [bp-Ch]@2

  v21 = this;
  retval = 1;
  if ( baseNode )
  {
    PFileNodeIter::PFileNodeIter(&iter, baseNode);
    v5 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    paramText.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v6 = PFileNodeIter::Curr(&iter);
    if ( v6 )
    {
      v7 = modIndex;
      v8 = layerIndex;
      do
      {
        if ( PFileNode::IsKeyword(v6, (int)InterlockedIncrement, &Mod_UVRotate_texCoordIndex_7) )
        {
          v9 = v6->vfptr;
          v18.m_charbuffer = 0;
          v10 = (PFileNode *)v9[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString(v10, (int)InterlockedIncrement, &paramText);
          PFileNode::GetNameAsUInt32(v10, (int)InterlockedIncrement, &v21->texCoordIndex);
        }
        else if ( PFileNode::IsKeyword(v6, (int)InterlockedIncrement, &Mod_UVRotate_rotate_7) )
        {
          v12 = v6->vfptr;
          v18.m_charbuffer = 0;
          v13 = (PFileNode *)v12[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString(v13, (int)InterlockedIncrement, &paramText);
          baseNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PFileNode::GetNameAsPString(v13, (int)InterlockedIncrement, (PStringBase<char> *)&baseNode);
          if ( !RenderMaterial::CheckParseField(
                  owner,
                  (PStringBase<char> *)&baseNode,
                  RMFIELD_LAYER_MOD_UVROTATE_ROTATE,
                  RMDATA_WAVEFORM,
                  v8,
                  v7) )
            Waveform::Parse(&v21->rotate, v13);
          v14 = (char *)&baseNode[-1].sub_nodes.m_num;
          if ( !InterlockedDecrement((volatile LONG *)&baseNode[-1].m_bProcessed) && v14 )
          {
            v15 = *(_DWORD *)v14;
            v18.m_charbuffer = (PSRefBufferCharData<char> *)1;
            (*(void (__thiscall **)(char *, signed int))v15)(v14, 1);
          }
        }
        else
        {
          v18.m_charbuffer = v11;
          PStringBase<char>::PStringBase<char>(&v18, "Invalid UVRotate keyword");
          PFileNode::ReportError((int)InterlockedIncrement, v6, v18);
          retval = 0;
        }
        v6 = (PFileNode *)PFileNodeIter::Next(&iter);
      }
      while ( v6 );
      v5 = paramText.m_charbuffer;
    }
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
    {
      v16 = *(_DWORD *)&v5[-2].m_data[12];
      v18.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v16)(&v5[-2].m_data[12], 1);
    }
    PFileNodeIter::~PFileNodeIter(&iter);
    result = retval;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00451830) --------------------------------------------------------  // acclient.c:142871
bool __thiscall LM_UVScale::LoadFromFileNode(LM_UVScale *this, PFileNode *baseNode, RenderMaterial *owner, const unsigned int layerIndex, const unsigned int modIndex)
{
  int v5; // edi@2
  PFileNode *v6; // esi@2
  const unsigned int v7; // ebp@3
  const unsigned int v8; // ebx@3
  ReferenceCountTemplate<1048576,0>Vtbl *v9; // edx@5
  PFileNode *v10; // esi@5
  PSRefBufferCharData<char> *v11; // ecx@6
  ReferenceCountTemplate<1048576,0>Vtbl *v12; // edx@7
  ReferenceCountTemplate<1048576,0>Vtbl *v13; // eax@9
  PFileNode *v14; // esi@9
  char *v15; // esi@11
  int v16; // edx@13
  int v17; // edx@19
  bool result; // al@20
  PStringBase<char> v19; // [sp-4h] [bp-2Ch]@5
  int v20; // [sp+10h] [bp-18h]@1
  PStringBase<char> paramText; // [sp+14h] [bp-14h]@2
  LM_UVScale *v22; // [sp+18h] [bp-10h]@1
  PFileNodeIter iter; // [sp+1Ch] [bp-Ch]@2

  v22 = this;
  BYTE3(v20) = 1;
  if ( baseNode )
  {
    PFileNodeIter::PFileNodeIter(&iter, baseNode);
    v5 = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    paramText.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v6 = PFileNodeIter::Curr(&iter);
    if ( v6 )
    {
      v7 = modIndex;
      v8 = layerIndex;
      do
      {
        if ( PFileNode::IsKeyword(v6, v5, &Mod_UVScale_texCoordIndex_7) )
        {
          v9 = v6->vfptr;
          v19.m_charbuffer = 0;
          v10 = (PFileNode *)v9[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString(v10, v5, &paramText);
          PFileNode::GetNameAsUInt32(v10, v5, &v22->texCoordIndex);
        }
        else if ( PFileNode::IsKeyword(v6, v5, &Mod_UVScale_scale_7) )
        {
          v12 = v6->vfptr;
          v19.m_charbuffer = 0;
          v5 = (int)v12[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
          PFileNode::GetNameAsPString((PFileNode *)v5, v5, &paramText);
          baseNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PFileNode::GetNameAsPString((PFileNode *)v5, v5, (PStringBase<char> *)&baseNode);
          if ( !RenderMaterial::CheckParseField(
                  owner,
                  (PStringBase<char> *)&baseNode,
                  RMFIELD_LAYER_MOD_UVSCALE_USCALE,
                  RMDATA_WAVEFORM,
                  v8,
                  v7) )
            Waveform::Parse(&v22->uScale, (PFileNode *)v5);
          v13 = v6->vfptr;
          v19.m_charbuffer = (PSRefBufferCharData<char> *)1;
          v14 = (PFileNode *)v13[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
          PFileNode::GetNameAsPString(v14, v5, &paramText);
          PFileNode::GetNameAsPString(v14, v5, (PStringBase<char> *)&baseNode);
          if ( !RenderMaterial::CheckParseField(
                  owner,
                  (PStringBase<char> *)&baseNode,
                  RMFIELD_LAYER_MOD_UVSCALE_VSCALE,
                  RMDATA_WAVEFORM,
                  v8,
                  v7) )
            Waveform::Parse(&v22->vScale, v14);
          v15 = (char *)&baseNode[-1].sub_nodes.m_num;
          if ( !InterlockedDecrement((volatile LONG *)&baseNode[-1].m_bProcessed) && v15 )
          {
            v16 = *(_DWORD *)v15;
            v19.m_charbuffer = (PSRefBufferCharData<char> *)1;
            (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
          }
        }
        else
        {
          v19.m_charbuffer = v11;
          PStringBase<char>::PStringBase<char>(&v19, "Invalid UVScale keyword");
          PFileNode::ReportError(v5, v6, v19);
          BYTE3(v20) = 0;
        }
        v6 = (PFileNode *)PFileNodeIter::Next(&iter);
      }
      while ( v6 );
      v5 = (int)paramText.m_charbuffer;
    }
    if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v5 != 20 )
    {
      v17 = *(_DWORD *)(v5 - 20);
      v19.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(int, signed int))v17)(v5 - 20, 1);
    }
    PFileNodeIter::~PFileNodeIter(&iter);
    result = BYTE3(v20);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006E5F50) --------------------------------------------------------  // acclient.c:762476
int _E73_53()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_24, "None");
  return atexit(_E74_41);
}

//----- (006E5F70) --------------------------------------------------------  // acclient.c:762483
int _E76_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_24, "Speed");
  return atexit(_E77_55);
}

//----- (006E5F90) --------------------------------------------------------  // acclient.c:762490
int _E79_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_24, "Noise");
  return atexit(_E80_29);
}

//----- (006E5FB0) --------------------------------------------------------  // acclient.c:762497
int _E82_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_24, "Sine");
  return atexit(_E83_18);
}

//----- (006E5FD0) --------------------------------------------------------  // acclient.c:762504
int _E85_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_24, "Square");
  return atexit(_E86_15);
}

//----- (006E5FF0) --------------------------------------------------------  // acclient.c:762511
int _E88_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_24, "Bounce");
  return atexit(_E89_26);
}

//----- (006E6010) --------------------------------------------------------  // acclient.c:762518
int _E91_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_24, "Perlin");
  return atexit(_E92_28);
}

//----- (006E6030) --------------------------------------------------------  // acclient.c:762525
int _E94_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_24, "Fractal");
  return atexit(sub_756D00);
}

//----- (006E6050) --------------------------------------------------------  // acclient.c:762532
int _E97_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_24, "FrameLoop");
  return atexit(_E98_43);
}

//----- (006E6070) --------------------------------------------------------  // acclient.c:762539
void _E100_23()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_27, PFID_A8R8G8B8);
}

//----- (006E6080) --------------------------------------------------------  // acclient.c:762545
int _E118_17()
{
  PStringBase<char>::PStringBase<char>(&PHeader_9, "PREPROC_HEADER");
  return atexit(_E119_66);
}

//----- (006E60A0) --------------------------------------------------------  // acclient.c:762552
int _E121_14()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_7, "VertexArray");
  return atexit(_E122_53);
}

//----- (006E60C0) --------------------------------------------------------  // acclient.c:762559
int _E124_17()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_7, "BinaryVertexArray");
  return atexit(_E125_28);
}

//----- (006E60E0) --------------------------------------------------------  // acclient.c:762566
int _E127_13()
{
  PStringBase<char>::PStringBase<char>(&VertexType_8, "VertexType");
  return atexit(_E128_29);
}

//----- (006E6100) --------------------------------------------------------  // acclient.c:762573
int _E130_14()
{
  PStringBase<char>::PStringBase<char>(&VertexData_7, "VertexData");
  return atexit(_E131_25);
}

//----- (006E6120) --------------------------------------------------------  // acclient.c:762580
int _E133_13()
{
  PStringBase<char>::PStringBase<char>(&Vertex_7, "Vertex");
  return atexit(_E134_24);
}

//----- (006E6140) --------------------------------------------------------  // acclient.c:762587
int _E136_12()
{
  PStringBase<char>::PStringBase<char>(&Index_15, "Index");
  return atexit(_E137_24);
}

//----- (006E6160) --------------------------------------------------------  // acclient.c:762594
int _E139_11()
{
  PStringBase<char>::PStringBase<char>(&Origin_15, "P");
  return atexit(_E140_19);
}

//----- (006E6180) --------------------------------------------------------  // acclient.c:762601
int _E142_11()
{
  PStringBase<char>::PStringBase<char>(&Normal_7, "N");
  return atexit(_E143_20);
}

//----- (006E61A0) --------------------------------------------------------  // acclient.c:762608
int _E145_10()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_15, "Diffuse");
  return atexit(_E146_19);
}

//----- (006E61C0) --------------------------------------------------------  // acclient.c:762615
int _E148_10()
{
  PStringBase<char>::PStringBase<char>(&Specular_15, "Specular");
  return atexit(_E149_19);
}

//----- (006E61E0) --------------------------------------------------------  // acclient.c:762622
int _E151_10()
{
  PStringBase<char>::PStringBase<char>(&UVS_7, "UVS");
  return atexit(_E152_18);
}

//----- (006E6200) --------------------------------------------------------  // acclient.c:762629
int _E154_11()
{
  PStringBase<char>::PStringBase<char>(&VectorS_7, "VectorS");
  return atexit(_E155_16);
}

//----- (006E6220) --------------------------------------------------------  // acclient.c:762636
int _E157_10()
{
  PStringBase<char>::PStringBase<char>(&VectorT_7, "VectorT");
  return atexit(_E158_19);
}

//----- (006E6240) --------------------------------------------------------  // acclient.c:762643
int _E160_11()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_7, "VectorSxT");
  return atexit(_E161_16);
}

//----- (006E6260) --------------------------------------------------------  // acclient.c:762650
int _E163_9()
{
  PStringBase<char>::PStringBase<char>(&Weights_7, "Weights");
  return atexit(_E164_19);
}

//----- (006E6280) --------------------------------------------------------  // acclient.c:762657
int _E166_10()
{
  PStringBase<char>::PStringBase<char>(&Importance_7, "Importance");
  return atexit(_E167_15);
}

//----- (006E62A0) --------------------------------------------------------  // acclient.c:762664
int _E169_8()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_7, "PhysMtl");
  return atexit(_E170_14);
}

//----- (006E62C0) --------------------------------------------------------  // acclient.c:762671
int _E172_8()
{
  PStringBase<char>::PStringBase<char>(&Material_34, "Material");
  return atexit(_E173_13);
}

//----- (006E62E0) --------------------------------------------------------  // acclient.c:762678
int _E175_8()
{
  PStringBase<char>::PStringBase<char>(&ID_18, "ID");
  return atexit(_E176_14);
}

//----- (006E6300) --------------------------------------------------------  // acclient.c:762685
int _E178_8()
{
  PStringBase<char>::PStringBase<char>(&FileName_7, "FileName");
  return atexit(_E179_13);
}

//----- (006E6320) --------------------------------------------------------  // acclient.c:762692
int _E181_8()
{
  PStringBase<char>::PStringBase<char>(&Polygon_15, "Polygon");
  return atexit(_E182_13);
}

//----- (006E6340) --------------------------------------------------------  // acclient.c:762699
int _E184_6()
{
  PStringBase<char>::PStringBase<char>(&ID_19, "ID");
  return atexit(_E185_10);
}

//----- (006E6360) --------------------------------------------------------  // acclient.c:762706
int _E187_6()
{
  PStringBase<char>::PStringBase<char>(&Indices_13, "INDICES");
  return atexit(_E188_11);
}

//----- (006E6380) --------------------------------------------------------  // acclient.c:762713
int _E190_6()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_7, "MaterialID");
  return atexit(_E191_10);
}

//----- (006E63A0) --------------------------------------------------------  // acclient.c:762720
int _E193_6()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_7, "PhysMaterialID");
  return atexit(_E194_17);
}

//----- (006E63C0) --------------------------------------------------------  // acclient.c:762727
int _E196_8()
{
  PStringBase<char>::PStringBase<char>(&Markings_7, "Markings");
  return atexit(_E197_8);
}

//----- (006E63E0) --------------------------------------------------------  // acclient.c:762734
int _E199_6()
{
  PStringBase<char>::PStringBase<char>(&Material_35, "Material");
  return atexit(_E200_13);
}

//----- (006E6400) --------------------------------------------------------  // acclient.c:762741
int _E202_6()
{
  PStringBase<char>::PStringBase<char>(&Index_16, "Index");
  return atexit(_E203_12);
}

//----- (006E6420) --------------------------------------------------------  // acclient.c:762748
int _E205_7()
{
  PStringBase<char>::PStringBase<char>(&Filename_7, "Filename");
  return atexit(_E206_15);
}

//----- (006E6440) --------------------------------------------------------  // acclient.c:762755
int _E208_8()
{
  PStringBase<char>::PStringBase<char>(&Surface_7, "Surface");
  return atexit(_E209_10);
}

//----- (006E6460) --------------------------------------------------------  // acclient.c:762762
int _E211_7()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_7, "CellPoly");
  return atexit(_E212_13);
}

//----- (006E6480) --------------------------------------------------------  // acclient.c:762769
int _E214_7()
{
  PStringBase<char>::PStringBase<char>(&Sphere_10, "Sphere");
  return atexit(_E215_9);
}

//----- (006E64A0) --------------------------------------------------------  // acclient.c:762776
int _E217_7()
{
  PStringBase<char>::PStringBase<char>(&Side_7, "Side");
  return atexit(_E218_10);
}

//----- (006E64C0) --------------------------------------------------------  // acclient.c:762783
int _E220_7()
{
  PStringBase<char>::PStringBase<char>(&Positive_7, "Positive");
  return atexit(_E221_10);
}

//----- (006E64E0) --------------------------------------------------------  // acclient.c:762790
int _E223_7()
{
  PStringBase<char>::PStringBase<char>(&Negative_7, "Negative");
  return atexit(_E224_10);
}

//----- (006E6500) --------------------------------------------------------  // acclient.c:762797
int _E226_7()
{
  PStringBase<char>::PStringBase<char>(&Polygon_16, "PolygonIndex");
  return atexit(_E227_10);
}

//----- (006E6520) --------------------------------------------------------  // acclient.c:762804
int _E229_7()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_15, "OtherCellMeshIndex");
  return atexit(_E230_10);
}

//----- (006E6540) --------------------------------------------------------  // acclient.c:762811
int _E232_7()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_7, "CellPortal");
  return atexit(_E233_9);
}

//----- (006E6560) --------------------------------------------------------  // acclient.c:762818
int _E235_7()
{
  PStringBase<char>::PStringBase<char>(&Portal_10, "PortalIndex");
  return atexit(_E236_9);
}

//----- (006E6580) --------------------------------------------------------  // acclient.c:762825
int _E238_7()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_16, "OtherCellID");
  return atexit(_E239_10);
}

//----- (006E65A0) --------------------------------------------------------  // acclient.c:762832
int _E241_7()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_7, "OtherPortalIndex");
  return atexit(_E242_10);
}

//----- (006E65C0) --------------------------------------------------------  // acclient.c:762839
int _E244_7()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_7, "ExactMatch");
  return atexit(_E245_9);
}

//----- (006E65E0) --------------------------------------------------------  // acclient.c:762846
int _E247_7()
{
  PStringBase<char>::PStringBase<char>(&StabList_7, "StabList");
  return atexit(_E248_9);
}

//----- (006E6600) --------------------------------------------------------  // acclient.c:762853
int _E250_7()
{
  PStringBase<char>::PStringBase<char>(&Period_7, "Period");
  return atexit(_E251_9);
}

//----- (006E6620) --------------------------------------------------------  // acclient.c:762860
int _E253_7()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_7, "GrannyAnimation");
  return atexit(_E254_10);
}

//----- (006E6640) --------------------------------------------------------  // acclient.c:762867
int _E256_7()
{
  PStringBase<char>::PStringBase<char>(&Transform_7, "Transform");
  return atexit(_E257_8);
}

//----- (006E6660) --------------------------------------------------------  // acclient.c:762874
int _E259_7()
{
  PStringBase<char>::PStringBase<char>(&Scale_23, "Scale");
  return atexit(_E260_9);
}

//----- (006E6680) --------------------------------------------------------  // acclient.c:762881
int _E262_7()
{
  PStringBase<char>::PStringBase<char>(&Weight_7, "Weight");
  return atexit(_E263_7);
}

//----- (006E66A0) --------------------------------------------------------  // acclient.c:762888
int _E265_7()
{
  PStringBase<char>::PStringBase<char>(&Offset_7, "Offset");
  return atexit(_E266_7);
}

//----- (006E66C0) --------------------------------------------------------  // acclient.c:762895
int _E268_7()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_8, "Quaternion");
  return atexit(_E269_7);
}

//----- (006E66E0) --------------------------------------------------------  // acclient.c:762902
int _E271_6()
{
  PStringBase<char>::PStringBase<char>(&Rotation_15, "Rotation");
  return atexit(_E272_6);
}

//----- (006E6700) --------------------------------------------------------  // acclient.c:762909
int _E274_6()
{
  PStringBase<char>::PStringBase<char>(&STime_7, "STime");
  return atexit(_E275_6);
}

//----- (006E6720) --------------------------------------------------------  // acclient.c:762916
int _E277_6()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_7, "PhysicsSplines");
  return atexit(_E278_6);
}

//----- (006E6740) --------------------------------------------------------  // acclient.c:762923
int _E280_6()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_7, "BoneOpacities");
  return atexit(_E281_7);
}

//----- (006E6760) --------------------------------------------------------  // acclient.c:762930
int _E283_6()
{
  PStringBase<char>::PStringBase<char>(&LowPt_7, "LowPoint");
  return atexit(_E284_6);
}

//----- (006E6780) --------------------------------------------------------  // acclient.c:762937
int _E286_6()
{
  PStringBase<char>::PStringBase<char>(&Radius_7, "Radius");
  return atexit(_E287_7);
}

//----- (006E67A0) --------------------------------------------------------  // acclient.c:762944
int _E289_6()
{
  PStringBase<char>::PStringBase<char>(&Height_7, "Height");
  return atexit(_E290_7);
}

//----- (006E67C0) --------------------------------------------------------  // acclient.c:762951
int _E292_6()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_7, "Texture2D");
  return atexit(_E293_6);
}

//----- (006E67E0) --------------------------------------------------------  // acclient.c:762958
int _E295_6()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_7, "Texture3D");
  return atexit(_E296_7);
}

//----- (006E6800) --------------------------------------------------------  // acclient.c:762965
int _E298_6()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_7, "TextureCube");
  return atexit(_E299_5);
}

//----- (006E6820) --------------------------------------------------------  // acclient.c:762972
int _E301_5()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_7, "TextureMovie2D");
  return atexit(_E302_6);
}

//----- (006E6840) --------------------------------------------------------  // acclient.c:762979
int _E304_5()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_7, "MovieFile");
  return atexit(_E305_5);
}

//----- (006E6860) --------------------------------------------------------  // acclient.c:762986
int _E307_5()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_7, "MovieFPS");
  return atexit(_E308_6);
}

//----- (006E6880) --------------------------------------------------------  // acclient.c:762993
int _E310_5()
{
  PStringBase<char>::PStringBase<char>(&Levels_7, "Levels");
  return atexit(_E311_5);
}

//----- (006E68A0) --------------------------------------------------------  // acclient.c:763000
int _E313_5()
{
  PStringBase<char>::PStringBase<char>(&NodeName_79, "Instance");
  return atexit(_E314_6);
}

//----- (006E68C0) --------------------------------------------------------  // acclient.c:763007
int _E316_5()
{
  PStringBase<char>::PStringBase<char>(&Material_36, "Material");
  return atexit(_E317_5);
}

//----- (006E68E0) --------------------------------------------------------  // acclient.c:763014
int _E319_5()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_7, "MaterialType");
  return atexit(_E320_6);
}

//----- (006E6900) --------------------------------------------------------  // acclient.c:763021
int _E322_5()
{
  PStringBase<char>::PStringBase<char>(&Modifier_7, "Modifier");
  return atexit(_E323_5);
}

//----- (006E6920) --------------------------------------------------------  // acclient.c:763028
int _E325_5()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_7, "AllowStencilShadows");
  return atexit(_E326_6);
}

//----- (006E6940) --------------------------------------------------------  // acclient.c:763035
int _E328_5()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_7, "DiscardGeometry");
  return atexit(_E329_5);
}

//----- (006E6960) --------------------------------------------------------  // acclient.c:763042
int _E331_5()
{
  PStringBase<char>::PStringBase<char>(&NodeName_80, "Material");
  return atexit(_E332_6);
}

//----- (006E6980) --------------------------------------------------------  // acclient.c:763049
int _E334_5()
{
  PStringBase<char>::PStringBase<char>(&SortMode_7, "SortMode");
  return atexit(_E335_5);
}

//----- (006E69A0) --------------------------------------------------------  // acclient.c:763056
int _E337_5()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_7, "None");
  return atexit(_E338_5);
}

//----- (006E69C0) --------------------------------------------------------  // acclient.c:763063
int _E340_5()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_7, "Triangle");
  return atexit(_E341_5);
}

//----- (006E69E0) --------------------------------------------------------  // acclient.c:763070
int _E343_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_81, "Modifier");
  return atexit(_E344_3);
}

//----- (006E6A00) --------------------------------------------------------  // acclient.c:763077
int _E346_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_82, "Property");
  return atexit(_E347_3);
}

//----- (006E6A20) --------------------------------------------------------  // acclient.c:763084
int _E349_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_7, "Data");
  return atexit(_E350_3);
}

//----- (006E6A40) --------------------------------------------------------  // acclient.c:763091
int _E352_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_7, "Waveform");
  return atexit(_E353_3);
}

//----- (006E6A60) --------------------------------------------------------  // acclient.c:763098
int _E355_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_7, "Color");
  return atexit(_E356_3);
}

//----- (006E6A80) --------------------------------------------------------  // acclient.c:763105
int _E358_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_7, "Texture");
  return atexit(_E359_3);
}

//----- (006E6AA0) --------------------------------------------------------  // acclient.c:763112
int _E361_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_7, "Bool");
  return atexit(_E362_3);
}

//----- (006E6AC0) --------------------------------------------------------  // acclient.c:763119
int _E364_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_83, "Layer");
  return atexit(_E365_3);
}

//----- (006E6AE0) --------------------------------------------------------  // acclient.c:763126
int _E367_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_7, "UVTranslate");
  return atexit(_E368_3);
}

//----- (006E6B00) --------------------------------------------------------  // acclient.c:763133
int _E370_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_7, "UVRotate");
  return atexit(_E371_3);
}

//----- (006E6B20) --------------------------------------------------------  // acclient.c:763140
int _E373_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_7, "UVScale");
  return atexit(_E374_3);
}

//----- (006E6B40) --------------------------------------------------------  // acclient.c:763147
int _E376_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_7, "UVTransform");
  return atexit(_E377_3);
}

//----- (006E6B60) --------------------------------------------------------  // acclient.c:763154
int _E379_3()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_7, "TrueFlags");
  return atexit(_E380_3);
}

//----- (006E6B80) --------------------------------------------------------  // acclient.c:763161
int _E382_3()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_7, "FalseFlags");
  return atexit(_E383_3);
}

//----- (006E6BA0) --------------------------------------------------------  // acclient.c:763168
int _E385_3()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_7, "RenderPass");
  return atexit(_E386_3);
}

//----- (006E6BC0) --------------------------------------------------------  // acclient.c:763175
int _E388_3()
{
  PStringBase<char>::PStringBase<char>(&Blend_7, "Blend");
  return atexit(_E389_3);
}

//----- (006E6BE0) --------------------------------------------------------  // acclient.c:763182
int _E391_3()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_7, "DepthTest");
  return atexit(_E392_3);
}

//----- (006E6C00) --------------------------------------------------------  // acclient.c:763189
int _E394_3()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_7, "DepthWrite");
  return atexit(_E395_3);
}

//----- (006E6C20) --------------------------------------------------------  // acclient.c:763196
int _E397_3()
{
  PStringBase<char>::PStringBase<char>(&CullMode_7, "CullMode");
  return atexit(_E398_3);
}

//----- (006E6C40) --------------------------------------------------------  // acclient.c:763203
int _E400_3()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_7, "DepthFog");
  return atexit(_E401_3);
}

//----- (006E6C60) --------------------------------------------------------  // acclient.c:763210
int _E403_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_7, "AlphaTestMode");
  return atexit(_E404_3);
}

//----- (006E6C80) --------------------------------------------------------  // acclient.c:763217
int _E406_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_7, "AlphaTestRef");
  return atexit(_E407_3);
}

//----- (006E6CA0) --------------------------------------------------------  // acclient.c:763224
int _E409_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_7, "FFUseLighting");
  return atexit(_E410_3);
}

//----- (006E6CC0) --------------------------------------------------------  // acclient.c:763231
int _E412_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_7, "FFUseDyeColorInTFactor");
  return atexit(_E413_3);
}

//----- (006E6CE0) --------------------------------------------------------  // acclient.c:763238
int _E415_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_7, "FFUseSpecularLighting");
  return atexit(_E416_3);
}

//----- (006E6D00) --------------------------------------------------------  // acclient.c:763245
int _E418_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_7, "FFUseDistanceFog");
  return atexit(_E419_3);
}

//----- (006E6D20) --------------------------------------------------------  // acclient.c:763252
int _E421_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_7, "FFUseVertexDiffuse");
  return atexit(_E422_3);
}

//----- (006E6D40) --------------------------------------------------------  // acclient.c:763259
int _E424_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_7, "FFUseVertexSpecular");
  return atexit(_E425_3);
}

//----- (006E6D60) --------------------------------------------------------  // acclient.c:763266
int _E427_3()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_7, "ShaderSupportsDynamicLights");
  return atexit(_E428_3);
}

//----- (006E6D80) --------------------------------------------------------  // acclient.c:763273
int _E430_3()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_7, "UsesTransparency");
  return atexit(_E431_3);
}

//----- (006E6DA0) --------------------------------------------------------  // acclient.c:763280
int _E433_3()
{
  PStringBase<char>::PStringBase<char>(&Ambient_7, "Ambient");
  return atexit(_E434_3);
}

//----- (006E6DC0) --------------------------------------------------------  // acclient.c:763287
int _E436_3()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_16, "Diffuse");
  return atexit(_E437_3);
}

//----- (006E6DE0) --------------------------------------------------------  // acclient.c:763294
int _E439_3()
{
  PStringBase<char>::PStringBase<char>(&Specular_16, "Specular");
  return atexit(_E440_3);
}

//----- (006E6E00) --------------------------------------------------------  // acclient.c:763301
int _E442_3()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_7, "SpecularPower");
  return atexit(_E443_3);
}

//----- (006E6E20) --------------------------------------------------------  // acclient.c:763308
int _E445_3()
{
  PStringBase<char>::PStringBase<char>(&Dye_7, "Dye");
  return atexit(_E446_3);
}

//----- (006E6E40) --------------------------------------------------------  // acclient.c:763315
int _E448_3()
{
  PStringBase<char>::PStringBase<char>(&Emissive_7, "Emissive");
  return atexit(_E449_3);
}

//----- (006E6E60) --------------------------------------------------------  // acclient.c:763322
int _E451_3()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_7, "VertexFormat");
  return atexit(_E452_3);
}

//----- (006E6E80) --------------------------------------------------------  // acclient.c:763329
int _E454_3()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_7, "VertexShader");
  return atexit(_E455_3);
}

//----- (006E6EA0) --------------------------------------------------------  // acclient.c:763336
int _E457_3()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_7, "PixelShader");
  return atexit(_E458_3);
}

//----- (006E6EC0) --------------------------------------------------------  // acclient.c:763343
int _E460_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_7, "None");
  return atexit(_E461_3);
}

//----- (006E6EE0) --------------------------------------------------------  // acclient.c:763350
int _E463_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_7, "Reflections");
  return atexit(_E464_3);
}

//----- (006E6F00) --------------------------------------------------------  // acclient.c:763357
int _E466_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_7, "VideoPost");
  return atexit(_E467_3);
}

//----- (006E6F20) --------------------------------------------------------  // acclient.c:763364
int _E469_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_7, "HighDetail");
  return atexit(_E470_3);
}

//----- (006E6F40) --------------------------------------------------------  // acclient.c:763371
int _E472_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_7, "Specular");
  return atexit(_E473_3);
}

//----- (006E6F60) --------------------------------------------------------  // acclient.c:763378
int _E475_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_7, "Class1");
  return atexit(_E476_3);
}

//----- (006E6F80) --------------------------------------------------------  // acclient.c:763385
int _E478_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_7, "Class2");
  return atexit(_E479_3);
}

//----- (006E6FA0) --------------------------------------------------------  // acclient.c:763392
int _E481_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_7, "Class3");
  return atexit(_E482_3);
}

//----- (006E6FC0) --------------------------------------------------------  // acclient.c:763399
int _E484_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_7, "Default");
  return atexit(_E485_3);
}

//----- (006E6FE0) --------------------------------------------------------  // acclient.c:763406
int _E487_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_7,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E488_3);
}

//----- (006E7000) --------------------------------------------------------  // acclient.c:763415
int _E490_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_7, "PointLightDiffuseAndSpecular");
  return atexit(_E491_3);
}

//----- (006E7020) --------------------------------------------------------  // acclient.c:763422
int _E493_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_7,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E494_3);
}

//----- (006E7040) --------------------------------------------------------  // acclient.c:763431
int _E496_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_7,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E497_3);
}

//----- (006E7060) --------------------------------------------------------  // acclient.c:763440
int _E499_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_7,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E500_3);
}

//----- (006E7080) --------------------------------------------------------  // acclient.c:763449
int _E502_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_7, "DistanceFog");
  return atexit(_E503_3);
}

//----- (006E70A0) --------------------------------------------------------  // acclient.c:763456
int _E505_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_7, "FFGlow");
  return atexit(_E506_3);
}

//----- (006E70C0) --------------------------------------------------------  // acclient.c:763463
int _E508_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_7, "ShaderGlow");
  return atexit(_E509_3);
}

//----- (006E70E0) --------------------------------------------------------  // acclient.c:763470
int _E511_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_7, "LandscapeShadowMap");
  return atexit(_E512_3);
}

//----- (006E7100) --------------------------------------------------------  // acclient.c:763477
int _E514_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_7, "AlphaBlend");
  return atexit(_E515_3);
}

//----- (006E7120) --------------------------------------------------------  // acclient.c:763484
int _E517_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_7, "AL_0DL_0PL");
  return atexit(_E518_3);
}

//----- (006E7140) --------------------------------------------------------  // acclient.c:763491
int _E520_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_7, "AL_0DL_1PL");
  return atexit(_E521_3);
}

//----- (006E7160) --------------------------------------------------------  // acclient.c:763498
int _E523_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_7, "AL_0DL_2PL");
  return atexit(_E524_3);
}

//----- (006E7180) --------------------------------------------------------  // acclient.c:763505
int _E526_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_7, "AL_0DL_3PL");
  return atexit(_E527_3);
}

//----- (006E71A0) --------------------------------------------------------  // acclient.c:763512
int _E529_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_7, "AL_0DL_4PL");
  return atexit(_E530_3);
}

//----- (006E71C0) --------------------------------------------------------  // acclient.c:763519
int _E532_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_7, "AL_0DL_5PL");
  return atexit(_E533_3);
}

//----- (006E71E0) --------------------------------------------------------  // acclient.c:763526
int _E535_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_7, "AL_0DL_6PL");
  return atexit(_E536_3);
}

//----- (006E7200) --------------------------------------------------------  // acclient.c:763533
int _E538_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_7, "AL_0DL_7PL");
  return atexit(_E539_3);
}

//----- (006E7220) --------------------------------------------------------  // acclient.c:763540
int _E541_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_7, "AL_0DL_8PL");
  return atexit(_E542_3);
}

//----- (006E7240) --------------------------------------------------------  // acclient.c:763547
int _E544_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_7, "AL_1DL_0PL");
  return atexit(_E545_3);
}

//----- (006E7260) --------------------------------------------------------  // acclient.c:763554
int _E547_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_7, "AL_1DL_1PL");
  return atexit(_E548_3);
}

//----- (006E7280) --------------------------------------------------------  // acclient.c:763561
int _E550_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_7, "AL_1DL_2PL");
  return atexit(_E551_3);
}

//----- (006E72A0) --------------------------------------------------------  // acclient.c:763568
int _E553_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_7, "AL_1DL_3PL");
  return atexit(_E554_3);
}

//----- (006E72C0) --------------------------------------------------------  // acclient.c:763575
int _E556_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_7, "AL_1DL_4PL");
  return atexit(_E557_3);
}

//----- (006E72E0) --------------------------------------------------------  // acclient.c:763582
int _E559_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_7, "AL_1DL_5PL");
  return atexit(_E560_3);
}

//----- (006E7300) --------------------------------------------------------  // acclient.c:763589
int _E562_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_7, "AL_1DL_6PL");
  return atexit(_E563_3);
}

//----- (006E7320) --------------------------------------------------------  // acclient.c:763596
int _E565_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_7, "AL_1DL_7PL");
  return atexit(_E566_3);
}

//----- (006E7340) --------------------------------------------------------  // acclient.c:763603
int _E568_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_7, "AL_0DL_0PL_Fog");
  return atexit(_E569_3);
}

//----- (006E7360) --------------------------------------------------------  // acclient.c:763610
int _E571_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_7, "AL_0DL_1PL_Fog");
  return atexit(_E572_3);
}

//----- (006E7380) --------------------------------------------------------  // acclient.c:763617
int _E574_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_7, "AL_0DL_2PL_Fog");
  return atexit(_E575_3);
}

//----- (006E73A0) --------------------------------------------------------  // acclient.c:763624
int _E577_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_7, "AL_0DL_3PL_Fog");
  return atexit(_E578_3);
}

//----- (006E73C0) --------------------------------------------------------  // acclient.c:763631
int _E580_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_7, "AL_0DL_4PL_Fog");
  return atexit(_E581_3);
}

//----- (006E73E0) --------------------------------------------------------  // acclient.c:763638
int _E583_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_7, "AL_0DL_5PL_Fog");
  return atexit(_E584_3);
}

//----- (006E7400) --------------------------------------------------------  // acclient.c:763645
int _E586_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_7, "AL_0DL_6PL_Fog");
  return atexit(_E587_3);
}

//----- (006E7420) --------------------------------------------------------  // acclient.c:763652
int _E589_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_7, "AL_0DL_7PL_Fog");
  return atexit(_E590_3);
}

//----- (006E7440) --------------------------------------------------------  // acclient.c:763659
int _E592_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_7, "AL_0DL_8PL_Fog");
  return atexit(_E593_3);
}

//----- (006E7460) --------------------------------------------------------  // acclient.c:763666
int _E595_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_7, "AL_1DL_0PL_Fog");
  return atexit(_E596_3);
}

//----- (006E7480) --------------------------------------------------------  // acclient.c:763673
int _E598_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_7, "AL_1DL_1PL_Fog");
  return atexit(_E599_3);
}

//----- (006E74A0) --------------------------------------------------------  // acclient.c:763680
int _E601_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_7, "AL_1DL_2PL_Fog");
  return atexit(_E602_3);
}

//----- (006E74C0) --------------------------------------------------------  // acclient.c:763687
int _E604_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_7, "AL_1DL_3PL_Fog");
  return atexit(_E605_3);
}

//----- (006E74E0) --------------------------------------------------------  // acclient.c:763694
int _E607_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_7, "AL_1DL_4PL_Fog");
  return atexit(_E608_3);
}

//----- (006E7500) --------------------------------------------------------  // acclient.c:763701
int _E610_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_7, "AL_1DL_5PL_Fog");
  return atexit(_E611_3);
}

//----- (006E7520) --------------------------------------------------------  // acclient.c:763708
int _E613_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_7, "AL_1DL_6PL_Fog");
  return atexit(_E614_3);
}

//----- (006E7540) --------------------------------------------------------  // acclient.c:763715
int _E616_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_7, "AL_1DL_7PL_Fog");
  return atexit(_E617_3);
}

//----- (006E7560) --------------------------------------------------------  // acclient.c:763722
int _E619_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_7, "Zero");
  return atexit(_E620_3);
}

//----- (006E7580) --------------------------------------------------------  // acclient.c:763729
int _E622_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_7, "One");
  return atexit(_E623_3);
}

//----- (006E75A0) --------------------------------------------------------  // acclient.c:763736
int _E625_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_7, "SrcColor");
  return atexit(_E626_3);
}

//----- (006E75C0) --------------------------------------------------------  // acclient.c:763743
int _E628_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_7, "InvSrcColor");
  return atexit(_E629_3);
}

//----- (006E75E0) --------------------------------------------------------  // acclient.c:763750
int _E631_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_7, "SrcAlpha");
  return atexit(_E632_3);
}

//----- (006E7600) --------------------------------------------------------  // acclient.c:763757
int _E634_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_7, "InvSrcAlpha");
  return atexit(_E635_3);
}

//----- (006E7620) --------------------------------------------------------  // acclient.c:763764
int _E637_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_7, "DstAlpha");
  return atexit(_E638_3);
}

//----- (006E7640) --------------------------------------------------------  // acclient.c:763771
int _E640_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_7, "InvDstAlpha");
  return atexit(_E641_3);
}

//----- (006E7660) --------------------------------------------------------  // acclient.c:763778
int _E643_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_7, "DstColor");
  return atexit(_E644_3);
}

//----- (006E7680) --------------------------------------------------------  // acclient.c:763785
int _E646_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_7, "InvDstColor");
  return atexit(_E647_3);
}

//----- (006E76A0) --------------------------------------------------------  // acclient.c:763792
int _E649_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_7, "SrcAlphaSat");
  return atexit(_E650_3);
}

//----- (006E76C0) --------------------------------------------------------  // acclient.c:763799
int _E652_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_7, "Less");
  return atexit(_E653_3);
}

//----- (006E76E0) --------------------------------------------------------  // acclient.c:763806
int _E655_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_7, "Equal");
  return atexit(_E656_3);
}

//----- (006E7700) --------------------------------------------------------  // acclient.c:763813
int _E658_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_7, "LessEqual");
  return atexit(_E659_3);
}

//----- (006E7720) --------------------------------------------------------  // acclient.c:763820
int _E661_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_7, "Greater");
  return atexit(_E662_3);
}

//----- (006E7740) --------------------------------------------------------  // acclient.c:763827
int _E664_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_7, "NotEqual");
  return atexit(_E665_3);
}

//----- (006E7760) --------------------------------------------------------  // acclient.c:763834
int _E667_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_7, "GreaterEqual");
  return atexit(_E668_3);
}

//----- (006E7780) --------------------------------------------------------  // acclient.c:763841
int _E670_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_7, "Always");
  return atexit(_E671_3);
}

//----- (006E77A0) --------------------------------------------------------  // acclient.c:763848
int _E673_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_7, "On");
  return atexit(_E674_3);
}

//----- (006E77C0) --------------------------------------------------------  // acclient.c:763855
int _E676_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_7, "Off");
  return atexit(_E677_3);
}

//----- (006E77E0) --------------------------------------------------------  // acclient.c:763862
int _E679_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_7, "LayerDiffuse");
  return atexit(_E680_3);
}

//----- (006E7800) --------------------------------------------------------  // acclient.c:763869
int _E682_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_7, "LayerSpecular");
  return atexit(_E683_3);
}

//----- (006E7820) --------------------------------------------------------  // acclient.c:763876
int _E685_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_7, "VertexDiffuse");
  return atexit(_E686_3);
}

//----- (006E7840) --------------------------------------------------------  // acclient.c:763883
int _E688_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_7, "VertexSpecular");
  return atexit(_E689_3);
}

//----- (006E7860) --------------------------------------------------------  // acclient.c:763890
int _E691_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_7, "None");
  return atexit(_E692_3);
}

//----- (006E7880) --------------------------------------------------------  // acclient.c:763897
int _E694_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_7, "CW");
  return atexit(_E695_3);
}

//----- (006E78A0) --------------------------------------------------------  // acclient.c:763904
int _E697_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_7, "CCW");
  return atexit(_E698_3);
}

//----- (006E78C0) --------------------------------------------------------  // acclient.c:763911
int _E700_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_7, "None");
  return atexit(_E701_3);
}

//----- (006E78E0) --------------------------------------------------------  // acclient.c:763918
int _E703_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_7, "Simple");
  return atexit(_E704_3);
}

//----- (006E7900) --------------------------------------------------------  // acclient.c:763925
int _E706_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_7, "Diffuse");
  return atexit(_E707_3);
}

//----- (006E7920) --------------------------------------------------------  // acclient.c:763932
int _E709_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_7, "Specular");
  return atexit(_E710_3);
}

//----- (006E7940) --------------------------------------------------------  // acclient.c:763939
int _E712_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_7, "Off");
  return atexit(_E713_3);
}

//----- (006E7960) --------------------------------------------------------  // acclient.c:763946
int _E715_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_7, "On");
  return atexit(_E716_3);
}

//----- (006E7980) --------------------------------------------------------  // acclient.c:763953
int _E718_3()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_7, "Off");
  return atexit(_E719_3);
}

//----- (006E79A0) --------------------------------------------------------  // acclient.c:763960
int _E721_3()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_7, "On");
  return atexit(_E722_3);
}

//----- (006E79C0) --------------------------------------------------------  // acclient.c:763967
int _E724_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_7, "Origin");
  return atexit(_E725_3);
}

//----- (006E79E0) --------------------------------------------------------  // acclient.c:763974
int _E727_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_7, "Normal");
  return atexit(_E728_3);
}

//----- (006E7A00) --------------------------------------------------------  // acclient.c:763981
int _E730_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_7, "PointSize");
  return atexit(_E731_3);
}

//----- (006E7A20) --------------------------------------------------------  // acclient.c:763988
int _E733_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_7, "Diffuse");
  return atexit(_E734_3);
}

//----- (006E7A40) --------------------------------------------------------  // acclient.c:763995
int _E736_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_7, "Specular");
  return atexit(_E737_3);
}

//----- (006E7A60) --------------------------------------------------------  // acclient.c:764002
int _E739_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_7, "TCPairX1");
  return atexit(_E740_3);
}

//----- (006E7A80) --------------------------------------------------------  // acclient.c:764009
int _E742_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_7, "TCPairX2");
  return atexit(_E743_3);
}

//----- (006E7AA0) --------------------------------------------------------  // acclient.c:764016
int _E745_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_7, "TCPairX3");
  return atexit(_E746_3);
}

//----- (006E7AC0) --------------------------------------------------------  // acclient.c:764023
int _E748_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_7, "TCPairX4");
  return atexit(_E749_3);
}

//----- (006E7AE0) --------------------------------------------------------  // acclient.c:764030
int _E751_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_7, "TCPairX5");
  return atexit(_E752_3);
}

//----- (006E7B00) --------------------------------------------------------  // acclient.c:764037
int _E754_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_7, "TCPairX6");
  return atexit(_E755_3);
}

//----- (006E7B20) --------------------------------------------------------  // acclient.c:764044
int _E757_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_7, "TCPairX7");
  return atexit(_E758_3);
}

//----- (006E7B40) --------------------------------------------------------  // acclient.c:764051
int _E760_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_7, "TCPairX8");
  return atexit(_E761_3);
}

//----- (006E7B60) --------------------------------------------------------  // acclient.c:764058
int _E763_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_7, "VectorS");
  return atexit(_E764_3);
}

//----- (006E7B80) --------------------------------------------------------  // acclient.c:764065
int _E766_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_7, "VectorT");
  return atexit(_E767_3);
}

//----- (006E7BA0) --------------------------------------------------------  // acclient.c:764072
int _E769_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_84, "Stage");
  return atexit(_E770_3);
}

//----- (006E7BC0) --------------------------------------------------------  // acclient.c:764079
int _E772_3()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_7, "Sampler");
  return atexit(_E773_3);
}

//----- (006E7BE0) --------------------------------------------------------  // acclient.c:764086
int _E775_3()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_7, "SamplerName");
  return atexit(_E776_3);
}

//----- (006E7C00) --------------------------------------------------------  // acclient.c:764093
int _E778_3()
{
  PStringBase<char>::PStringBase<char>(&Texture_7, "Texture");
  return atexit(_E779_3);
}

//----- (006E7C20) --------------------------------------------------------  // acclient.c:764100
int _E781_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_7, "!FrameBuffer");
  return atexit(_E782_3);
}

//----- (006E7C40) --------------------------------------------------------  // acclient.c:764107
int _E784_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_7, "!Distortion");
  return atexit(_E785_3);
}

//----- (006E7C60) --------------------------------------------------------  // acclient.c:764114
int _E787_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_7, "!Reflection");
  return atexit(_E788_3);
}

//----- (006E7C80) --------------------------------------------------------  // acclient.c:764121
int _E790_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_7, "!NormalizeCube");
  return atexit(_E791_3);
}

//----- (006E7CA0) --------------------------------------------------------  // acclient.c:764128
int _E793_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_7, "!LightProjectorCube");
  return atexit(_E794_3);
}

//----- (006E7CC0) --------------------------------------------------------  // acclient.c:764135
int _E796_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_7, "!EnvironmentCube");
  return atexit(_E797_3);
}

//----- (006E7CE0) --------------------------------------------------------  // acclient.c:764142
int _E799_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_7, "!LandscapeShadows");
  return atexit(_E800_3);
}

//----- (006E7D00) --------------------------------------------------------  // acclient.c:764149
int _E802_3()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_7, "AddressMode");
  return atexit(_E803_3);
}

//----- (006E7D20) --------------------------------------------------------  // acclient.c:764156
int _E805_3()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_7, "FilterMode");
  return atexit(_E806_3);
}

//----- (006E7D40) --------------------------------------------------------  // acclient.c:764163
int _E808_3()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_7, "FFColorOp");
  return atexit(_E809_3);
}

//----- (006E7D60) --------------------------------------------------------  // acclient.c:764170
int _E811_3()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_7, "FFColorArg1");
  return atexit(_E812_3);
}

//----- (006E7D80) --------------------------------------------------------  // acclient.c:764177
int _E814_3()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_7, "FFColorArg2");
  return atexit(_E815_3);
}

//----- (006E7DA0) --------------------------------------------------------  // acclient.c:764184
int _E817_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_7, "FFAlphaOp");
  return atexit(_E818_3);
}

//----- (006E7DC0) --------------------------------------------------------  // acclient.c:764191
int _E820_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_7, "FFAlphaArg1");
  return atexit(_E821_3);
}

//----- (006E7DE0) --------------------------------------------------------  // acclient.c:764198
int _E823_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_7, "FFAlphaArg2");
  return atexit(_E824_3);
}

//----- (006E7E00) --------------------------------------------------------  // acclient.c:764205
int _E826_3()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_7, "FFTexCoordIndex");
  return atexit(_E827_3);
}

//----- (006E7E20) --------------------------------------------------------  // acclient.c:764212
int _E829_3()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_7, "FFUseProjection");
  return atexit(_E830_3);
}

//----- (006E7E40) --------------------------------------------------------  // acclient.c:764219
int _E832_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_7, "SelectArg1");
  return atexit(_E833_3);
}

//----- (006E7E60) --------------------------------------------------------  // acclient.c:764226
int _E835_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_7, "SelectArg2");
  return atexit(_E836_3);
}

//----- (006E7E80) --------------------------------------------------------  // acclient.c:764233
int _E838_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_7, "Modulate");
  return atexit(_E839_3);
}

//----- (006E7EA0) --------------------------------------------------------  // acclient.c:764240
int _E841_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_7, "Modulate2X");
  return atexit(_E842_3);
}

//----- (006E7EC0) --------------------------------------------------------  // acclient.c:764247
int _E844_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_7, "Modulate4X");
  return atexit(_E845_3);
}

//----- (006E7EE0) --------------------------------------------------------  // acclient.c:764254
int _E847_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_7, "Add");
  return atexit(_E848_3);
}

//----- (006E7F00) --------------------------------------------------------  // acclient.c:764261
int _E850_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_7, "AddSigned");
  return atexit(_E851_3);
}

//----- (006E7F20) --------------------------------------------------------  // acclient.c:764268
int _E853_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_7, "AddSigned2X");
  return atexit(_E854_3);
}

//----- (006E7F40) --------------------------------------------------------  // acclient.c:764275
int _E856_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_7, "Subtract");
  return atexit(_E857_3);
}

//----- (006E7F60) --------------------------------------------------------  // acclient.c:764282
int _E859_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_7, "AddSmooth");
  return atexit(_E860_3);
}

//----- (006E7F80) --------------------------------------------------------  // acclient.c:764289
int _E862_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_7, "BlendDiffuseAlpha");
  return atexit(_E863_3);
}

//----- (006E7FA0) --------------------------------------------------------  // acclient.c:764296
int _E865_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_7, "BlendTextureAlpha");
  return atexit(_E866_3);
}

//----- (006E7FC0) --------------------------------------------------------  // acclient.c:764303
int _E868_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_7, "BlendFactorAlpha");
  return atexit(_E869_3);
}

//----- (006E7FE0) --------------------------------------------------------  // acclient.c:764310
int _E871_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_7, "BlendTextureAlphaPM");
  return atexit(_E872_3);
}

//----- (006E8000) --------------------------------------------------------  // acclient.c:764317
int _E874_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_7, "BlendCurrentAlpha");
  return atexit(_E875_3);
}

//----- (006E8020) --------------------------------------------------------  // acclient.c:764324
int _E877_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_7, "Premodulate");
  return atexit(_E878_3);
}

//----- (006E8040) --------------------------------------------------------  // acclient.c:764331
int _E880_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_7, "ModulateAlphaAddColor");
  return atexit(_E881_3);
}

//----- (006E8060) --------------------------------------------------------  // acclient.c:764338
int _E883_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_7, "ModulateColorAddAlpha");
  return atexit(_E884_3);
}

//----- (006E8080) --------------------------------------------------------  // acclient.c:764345
int _E886_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_7, "ModulateInvAlphaAddColor");
  return atexit(_E887_3);
}

//----- (006E80A0) --------------------------------------------------------  // acclient.c:764352
int _E889_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_7, "ModulateInvColorAddAlpha");
  return atexit(_E890_3);
}

//----- (006E80C0) --------------------------------------------------------  // acclient.c:764359
int _E892_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_7, "BumpEnvMap");
  return atexit(_E893_3);
}

//----- (006E80E0) --------------------------------------------------------  // acclient.c:764366
int _E895_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_7, "BumpEnvMapLuminance");
  return atexit(_E896_3);
}

//----- (006E8100) --------------------------------------------------------  // acclient.c:764373
int _E898_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_7, "DotProduct3");
  return atexit(_E899_3);
}

//----- (006E8120) --------------------------------------------------------  // acclient.c:764380
int _E901_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_7, "MultiplyAdd");
  return atexit(_E902_3);
}

//----- (006E8140) --------------------------------------------------------  // acclient.c:764387
int _E904_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_7, "Lerp");
  return atexit(_E905_3);
}

//----- (006E8160) --------------------------------------------------------  // acclient.c:764394
int _E907_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_7, "Diffuse");
  return atexit(_E908_3);
}

//----- (006E8180) --------------------------------------------------------  // acclient.c:764401
int _E910_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_7, "Specular");
  return atexit(_E911_3);
}

//----- (006E81A0) --------------------------------------------------------  // acclient.c:764408
int _E913_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_7, "Current");
  return atexit(_E914_3);
}

//----- (006E81C0) --------------------------------------------------------  // acclient.c:764415
int _E916_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_7, "Texture");
  return atexit(_E917_3);
}

//----- (006E81E0) --------------------------------------------------------  // acclient.c:764422
int _E919_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_7, "TFactor");
  return atexit(_E920_3);
}

//----- (006E8200) --------------------------------------------------------  // acclient.c:764429
int _E922_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_7, "Wrap");
  return atexit(_E923_3);
}

//----- (006E8220) --------------------------------------------------------  // acclient.c:764436
int _E925_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_7, "Mirror");
  return atexit(_E926_3);
}

//----- (006E8240) --------------------------------------------------------  // acclient.c:764443
int _E928_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_7, "Clamp");
  return atexit(_E929_3);
}

//----- (006E8260) --------------------------------------------------------  // acclient.c:764450
int _E931_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_7, "Border");
  return atexit(_E932_3);
}

//----- (006E8280) --------------------------------------------------------  // acclient.c:764457
int _E934_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_7, "None");
  return atexit(_E935_3);
}

//----- (006E82A0) --------------------------------------------------------  // acclient.c:764464
int _E937_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_7, "Point");
  return atexit(_E938_3);
}

//----- (006E82C0) --------------------------------------------------------  // acclient.c:764471
int _E940_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_7, "Linear");
  return atexit(_E941_3);
}

//----- (006E82E0) --------------------------------------------------------  // acclient.c:764478
int _E943_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_7, "Anisotropic");
  return atexit(_E944_3);
}

//----- (006E8300) --------------------------------------------------------  // acclient.c:764485
int _E946_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_7, "ReflectionVector");
  return atexit(_E947_3);
}

//----- (006E8320) --------------------------------------------------------  // acclient.c:764492
int _E949_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_7, "ViewNormal");
  return atexit(_E950_3);
}

//----- (006E8340) --------------------------------------------------------  // acclient.c:764499
int _E952_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_7, "ViewOrigin");
  return atexit(_E953_3);
}

//----- (006E8360) --------------------------------------------------------  // acclient.c:764506
int _E955_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_7, "SphereMap");
  return atexit(_E956_3);
}

//----- (006E8380) --------------------------------------------------------  // acclient.c:764513
int _E958_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_7, "CubeMapReflection");
  return atexit(_E959_3);
}

//----- (006E83A0) --------------------------------------------------------  // acclient.c:764520
int _E961_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_7, "CubeMapFakeLight");
  return atexit(_E962_3);
}

//----- (006E83C0) --------------------------------------------------------  // acclient.c:764527
int _E964_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_85, "FFModifier");
  return atexit(_E965_3);
}

//----- (006E83E0) --------------------------------------------------------  // acclient.c:764534
int _E967_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_7, "Origin");
  return atexit(_E968_3);
}

//----- (006E8400) --------------------------------------------------------  // acclient.c:764541
int _E970_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_7, "Normal");
  return atexit(_E971_3);
}

//----- (006E8420) --------------------------------------------------------  // acclient.c:764548
int _E973_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_7, "Diffuse");
  return atexit(_E974_3);
}

//----- (006E8440) --------------------------------------------------------  // acclient.c:764555
int _E976_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_7, "UVTranslate");
  return atexit(_E977_3);
}

//----- (006E8460) --------------------------------------------------------  // acclient.c:764562
int _E979_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_7, "UVRotate");
  return atexit(_E980_3);
}

//----- (006E8480) --------------------------------------------------------  // acclient.c:764569
int _E982_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_7, "UVScale");
  return atexit(_E983_3);
}

//----- (006E84A0) --------------------------------------------------------  // acclient.c:764576
int _E985_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_7, "UVTransform");
  return atexit(_E986_3);
}

//----- (006E84C0) --------------------------------------------------------  // acclient.c:764583
int _E988_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_7, "TexCoordIndex");
  return atexit(_E989_3);
}

//----- (006E84E0) --------------------------------------------------------  // acclient.c:764590
int _E991_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_7, "Translate");
  return atexit(_E992_3);
}

//----- (006E8500) --------------------------------------------------------  // acclient.c:764597
int _E994_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_7, "TexCoordIndex");
  return atexit(_E995_3);
}

//----- (006E8520) --------------------------------------------------------  // acclient.c:764604
int _E997_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_7, "Rotate");
  return atexit(_E998_3);
}

//----- (006E8540) --------------------------------------------------------  // acclient.c:764611
int _E1000_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_7, "TexCoordIndex");
  return atexit(_E1001_3);
}

//----- (006E8560) --------------------------------------------------------  // acclient.c:764618
int _E1003_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_7, "Scale");
  return atexit(_E1004_3);
}

//----- (006E8580) --------------------------------------------------------  // acclient.c:764625
int _E1006_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_86, "PSDesc");
  return atexit(_E1007_3);
}

//----- (006E85A0) --------------------------------------------------------  // acclient.c:764632
int _E1009_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_7, "PhysicsTimeStep");
  return atexit(_E1010_3);
}

//----- (006E85C0) --------------------------------------------------------  // acclient.c:764639
int _E1012_3()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_7, "FastForwardTime");
  return atexit(_E1013_3);
}

//----- (006E85E0) --------------------------------------------------------  // acclient.c:764646
int _E1015_3()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_7, "StartFadeDistance");
  return atexit(_E1016_3);
}

//----- (006E8600) --------------------------------------------------------  // acclient.c:764653
int _E1018_3()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_7, "StopFadeDistance");
  return atexit(_E1019_3);
}

//----- (006E8620) --------------------------------------------------------  // acclient.c:764660
int _E1021_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_7, "PhysicsDuration");
  return atexit(_E1022_3);
}

//----- (006E8640) --------------------------------------------------------  // acclient.c:764667
int _E1024_3()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_7, "ScaleType");
  return atexit(_E1025_3);
}

//----- (006E8660) --------------------------------------------------------  // acclient.c:764674
int _E1027_3()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_7, "WorldSpace");
  return atexit(_E1028_3);
}

//----- (006E8680) --------------------------------------------------------  // acclient.c:764681
int _E1030_3()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_7, "ForceDraw");
  return atexit(_E1031_3);
}

//----- (006E86A0) --------------------------------------------------------  // acclient.c:764688
int _E1033_3()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_7, "NumEmitters");
  return atexit(_E1034_3);
}

//----- (006E86C0) --------------------------------------------------------  // acclient.c:764695
int _E1036_3()
{
  PStringBase<char>::PStringBase<char>(&Material_37, "Material");
  return atexit(_E1037_3);
}

//----- (006E86E0) --------------------------------------------------------  // acclient.c:764702
int _E1039_3()
{
  PStringBase<char>::PStringBase<char>(&Version_7, "Version");
  return atexit(_E1040_3);
}

//----- (006E8700) --------------------------------------------------------  // acclient.c:764709
int _E1042_3()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_7, "MaxParticles");
  return atexit(_E1043_3);
}

//----- (006E8720) --------------------------------------------------------  // acclient.c:764716
int _E1045_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_87, "Emitter");
  return atexit(_E1046_3);
}

//----- (006E8740) --------------------------------------------------------  // acclient.c:764723
int _E1048_3()
{
  PStringBase<char>::PStringBase<char>(&Origin_16, "Origin");
  return atexit(_E1049_3);
}

//----- (006E8760) --------------------------------------------------------  // acclient.c:764730
int _E1051_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_7, "Shape");
  return atexit(_E1052_3);
}

//----- (006E8780) --------------------------------------------------------  // acclient.c:764737
int _E1054_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_7, "Point");
  return atexit(_E1055_3);
}

//----- (006E87A0) --------------------------------------------------------  // acclient.c:764744
int _E1057_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_7, "Line");
  return atexit(_E1058_3);
}

//----- (006E87C0) --------------------------------------------------------  // acclient.c:764751
int _E1060_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_7, "Quad");
  return atexit(_E1061_3);
}

//----- (006E87E0) --------------------------------------------------------  // acclient.c:764758
int _E1063_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_7, "Disc");
  return atexit(_E1064_3);
}

//----- (006E8800) --------------------------------------------------------  // acclient.c:764765
int _E1066_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_7, "Sphere");
  return atexit(_E1067_3);
}

//----- (006E8820) --------------------------------------------------------  // acclient.c:764772
int _E1069_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_7, "ParticleShape");
  return atexit(_E1070_3);
}

//----- (006E8840) --------------------------------------------------------  // acclient.c:764779
int _E1072_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_7, "Triangle");
  return atexit(_E1073_3);
}

//----- (006E8860) --------------------------------------------------------  // acclient.c:764786
int _E1075_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_7, "Quad");
  return atexit(_E1076_3);
}

//----- (006E8880) --------------------------------------------------------  // acclient.c:764793
int _E1078_3()
{
  PStringBase<char>::PStringBase<char>(&Streak_7, "Streak");
  return atexit(_E1079_3);
}

//----- (006E88A0) --------------------------------------------------------  // acclient.c:764800
int _E1081_3()
{
  PStringBase<char>::PStringBase<char>(&Rotation_16, "Rotation");
  return atexit(_E1082_3);
}

//----- (006E88C0) --------------------------------------------------------  // acclient.c:764807
int _E1084_3()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_7, "WorldRotation");
  return atexit(_E1085_3);
}

//----- (006E88E0) --------------------------------------------------------  // acclient.c:764814
int _E1087_3()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_7, "RotateVelocity");
  return atexit(_E1088_3);
}

//----- (006E8900) --------------------------------------------------------  // acclient.c:764821
int _E1090_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_7, "ParticleScale");
  return atexit(_E1091_3);
}

//----- (006E8920) --------------------------------------------------------  // acclient.c:764828
int _E1093_3()
{
  PStringBase<char>::PStringBase<char>(&Scale_24, "Scale");
  return atexit(_E1094_3);
}

//----- (006E8940) --------------------------------------------------------  // acclient.c:764835
int _E1096_3()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_7, "ExplodingDir");
  return atexit(_E1097_3);
}

//----- (006E8960) --------------------------------------------------------  // acclient.c:764842
int _E1099_3()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_7, "BirthRate");
  return atexit(_E1100_3);
}

//----- (006E8980) --------------------------------------------------------  // acclient.c:764849
int _E1102_3()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_7, "Lifespan");
  return atexit(_E1103_3);
}

//----- (006E89A0) --------------------------------------------------------  // acclient.c:764856
int _E1105_3()
{
  PStringBase<char>::PStringBase<char>(&Velocity_7, "Velocity");
  return atexit(_E1106_3);
}

//----- (006E89C0) --------------------------------------------------------  // acclient.c:764863
int _E1108_3()
{
  PStringBase<char>::PStringBase<char>(&Direction_7, "Direction");
  return atexit(_E1109_3);
}

//----- (006E89E0) --------------------------------------------------------  // acclient.c:764870
int _E1111_3()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_7, "MinSpread");
  return atexit(_E1112_3);
}

//----- (006E8A00) --------------------------------------------------------  // acclient.c:764877
int _E1114_3()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_7, "MaxSpread");
  return atexit(_E1115_3);
}

//----- (006E8A20) --------------------------------------------------------  // acclient.c:764884
int _E1117_3()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_7, "EmissionLimit");
  return atexit(_E1118_3);
}

//----- (006E8A40) --------------------------------------------------------  // acclient.c:764891
int _E1120_3()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_7, "BlastCount");
  return atexit(_E1121_3);
}

//----- (006E8A60) --------------------------------------------------------  // acclient.c:764898
int _E1123_3()
{
  PStringBase<char>::PStringBase<char>(&StartTime_7, "StartTime");
  return atexit(_E1124_3);
}

//----- (006E8A80) --------------------------------------------------------  // acclient.c:764905
int _E1126_3()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_7, "TimeLimit");
  return atexit(_E1127_3);
}

//----- (006E8AA0) --------------------------------------------------------  // acclient.c:764912
int _E1129_3()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_7, "EmissionDistance");
  return atexit(_E1130_3);
}

//----- (006E8AC0) --------------------------------------------------------  // acclient.c:764919
int _E1132_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_7, "ParticleSnap");
  return atexit(_E1133_3);
}

//----- (006E8AE0) --------------------------------------------------------  // acclient.c:764926
int _E1135_3()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_7, "InclusiveShape");
  return atexit(_E1136_3);
}

//----- (006E8B00) --------------------------------------------------------  // acclient.c:764933
int _E1138_3()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_7, "NumKeyframes");
  return atexit(_E1139_3);
}

//----- (006E8B20) --------------------------------------------------------  // acclient.c:764940
int _E1141_3()
{
  PStringBase<char>::PStringBase<char>(&IsActive_7, "IsActive");
  return atexit(_E1142_3);
}

//----- (006E8B40) --------------------------------------------------------  // acclient.c:764947
int _E1144_3()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_7, "FadeIn");
  return atexit(_E1145_3);
}

//----- (006E8B60) --------------------------------------------------------  // acclient.c:764954
int _E1147_3()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_7, "FadeOut");
  return atexit(_E1148_3);
}

//----- (006E8B80) --------------------------------------------------------  // acclient.c:764961
int _E1150_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_7, "ConstrainX");
  return atexit(_E1151_3);
}

//----- (006E8BA0) --------------------------------------------------------  // acclient.c:764968
int _E1153_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_7, "ConstrainY");
  return atexit(_E1154_3);
}

//----- (006E8BC0) --------------------------------------------------------  // acclient.c:764975
int _E1156_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_7, "ConstrainZ");
  return atexit(_E1157_3);
}

//----- (006E8BE0) --------------------------------------------------------  // acclient.c:764982
int _E1159_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_88, "Keyframe");
  return atexit(_E1160_3);
}

//----- (006E8C00) --------------------------------------------------------  // acclient.c:764989
int _E1162_3()
{
  PStringBase<char>::PStringBase<char>(&Time_7, "Time");
  return atexit(_E1163_3);
}

//----- (006E8C20) --------------------------------------------------------  // acclient.c:764996
int _E1165_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_7, "Flags");
  return atexit(_E1166_3);
}

//----- (006E8C40) --------------------------------------------------------  // acclient.c:765003
int _E1168_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_7, "None");
  return atexit(_E1169_3);
}

//----- (006E8C60) --------------------------------------------------------  // acclient.c:765010
int _E1171_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_7, "BlendScale");
  return atexit(_E1172_3);
}

//----- (006E8C80) --------------------------------------------------------  // acclient.c:765017
int _E1174_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_7, "BlendColor");
  return atexit(_E1175_3);
}

//----- (006E8CA0) --------------------------------------------------------  // acclient.c:765024
int _E1177_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_7, "BlendMass");
  return atexit(_E1178_3);
}

//----- (006E8CC0) --------------------------------------------------------  // acclient.c:765031
int _E1180_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_7, "SetScale");
  return atexit(_E1181_3);
}

//----- (006E8CE0) --------------------------------------------------------  // acclient.c:765038
int _E1183_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_7, "SetColor");
  return atexit(_E1184_3);
}

//----- (006E8D00) --------------------------------------------------------  // acclient.c:765045
int _E1186_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_7, "SetMass");
  return atexit(_E1187_3);
}

//----- (006E8D20) --------------------------------------------------------  // acclient.c:765052
int _E1189_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_7, "SetParticleFlags");
  return atexit(_E1190_3);
}

//----- (006E8D40) --------------------------------------------------------  // acclient.c:765059
int _E1192_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_7, "SetControllerType");
  return atexit(_E1193_3);
}

//----- (006E8D60) --------------------------------------------------------  // acclient.c:765066
int _E1195_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_7, "SetPhysicsFlags");
  return atexit(_E1196_3);
}

//----- (006E8D80) --------------------------------------------------------  // acclient.c:765073
int _E1198_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_7, "SetParams");
  return atexit(_E1199_3);
}

//----- (006E8DA0) --------------------------------------------------------  // acclient.c:765080
int _E1201_3()
{
  PStringBase<char>::PStringBase<char>(&Scale_25, "Scale");
  return atexit(_E1202_3);
}

//----- (006E8DC0) --------------------------------------------------------  // acclient.c:765087
int _E1204_3()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_7, "ScaleX");
  return atexit(_E1205_3);
}

//----- (006E8DE0) --------------------------------------------------------  // acclient.c:765094
int _E1207_3()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_7, "ScaleY");
  return atexit(_E1208_3);
}

//----- (006E8E00) --------------------------------------------------------  // acclient.c:765101
int _E1210_3()
{
  PStringBase<char>::PStringBase<char>(&Color_7, "Color");
  return atexit(_E1211_3);
}

//----- (006E8E20) --------------------------------------------------------  // acclient.c:765108
int _E1213_3()
{
  PStringBase<char>::PStringBase<char>(&Mass_7, "Mass");
  return atexit(_E1214_3);
}

//----- (006E8E40) --------------------------------------------------------  // acclient.c:765115
int _E1216_3()
{
  PStringBase<char>::PStringBase<char>(&PFlags_7, "ParticleFlags");
  return atexit(_E1217_3);
}

//----- (006E8E60) --------------------------------------------------------  // acclient.c:765122
int _E1219_3()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_7, "None");
  return atexit(_E1220_3);
}

//----- (006E8E80) --------------------------------------------------------  // acclient.c:765129
int _E1222_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_7, "ControllerType");
  return atexit(_E1223_3);
}

//----- (006E8EA0) --------------------------------------------------------  // acclient.c:765136
int _E1225_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_7, "None");
  return atexit(_E1226_3);
}

//----- (006E8EC0) --------------------------------------------------------  // acclient.c:765143
int _E1228_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_7, "Physics");
  return atexit(_E1229_3);
}

//----- (006E8EE0) --------------------------------------------------------  // acclient.c:765150
int _E1231_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_7, "Parametric");
  return atexit(_E1232_3);
}

//----- (006E8F00) --------------------------------------------------------  // acclient.c:765157
int _E1234_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_7, "AttractRepulse");
  return atexit(_E1235_3);
}

//----- (006E8F20) --------------------------------------------------------  // acclient.c:765164
int _E1237_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_7, "PointFile");
  return atexit(_E1238_3);
}

//----- (006E8F40) --------------------------------------------------------  // acclient.c:765171
int _E1240_3()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_7, "PointFileLerp");
  return atexit(_E1241_3);
}

//----- (006E8F60) --------------------------------------------------------  // acclient.c:765178
int _E1243_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_7, "PhysicsFlags");
  return atexit(_E1244_3);
}

//----- (006E8F80) --------------------------------------------------------  // acclient.c:765185
int _E1246_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_7, "None");
  return atexit(_E1247_3);
}

//----- (006E8FA0) --------------------------------------------------------  // acclient.c:765192
int _E1249_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_7, "Gravity");
  return atexit(_E1250_3);
}

//----- (006E8FC0) --------------------------------------------------------  // acclient.c:765199
int _E1252_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_7, "Wind");
  return atexit(_E1253_3);
}

//----- (006E8FE0) --------------------------------------------------------  // acclient.c:765206
int _E1255_3()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_7, "Momentum");
  return atexit(_E1256_3);
}

//----- (006E9000) --------------------------------------------------------  // acclient.c:765213
int _E1258_3()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_7, "RandomPoint");
  return atexit(_E1259_3);
}

//----- (006E9020) --------------------------------------------------------  // acclient.c:765220
int _E1261_3()
{
  PStringBase<char>::PStringBase<char>(&Position_8, "Position");
  return atexit(_E1262_3);
}

//----- (006E9040) --------------------------------------------------------  // acclient.c:765227
int _E1264_3()
{
  PStringBase<char>::PStringBase<char>(&PointList_7, "PointList");
  return atexit(_E1265_3);
}

//----- (006E9060) --------------------------------------------------------  // acclient.c:765234
int _E1267_3()
{
  PStringBase<char>::PStringBase<char>(&Point_16, "pt");
  return atexit(_E1268_3);
}

//----- (006E9080) --------------------------------------------------------  // acclient.c:765241
int _E1270_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_7, "DetailLevels");
  return atexit(_E1271_3);
}

//----- (006E90A0) --------------------------------------------------------  // acclient.c:765248
int _E1273_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_7, "Low");
  return atexit(_E1274_3);
}

//----- (006E90C0) --------------------------------------------------------  // acclient.c:765255
int _E1276_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_7, "Medium");
  return atexit(_E1277_3);
}

//----- (006E90E0) --------------------------------------------------------  // acclient.c:765262
int _E1279_3()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_7, "High");
  return atexit(_E1280_4);
}

//----- (006E9100) --------------------------------------------------------  // acclient.c:765269
int _E1282_3()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_7, "FadeSpeed");
  return atexit(_E1283_3);
}

//----- (006E9120) --------------------------------------------------------  // acclient.c:765276
int _E1285_3()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_7, "MaxOpacity");
  return atexit(_E1286_3);
}

//----- (006E9140) --------------------------------------------------------  // acclient.c:765283
int _E1288_3()
{
  PStringBase<char>::PStringBase<char>(&Point_17, "Point");
  return atexit(_E1289_2);
}

//----- (006E9160) --------------------------------------------------------  // acclient.c:765290
int _E1291_2()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_7, "AxisPos");
  return atexit(_E1292_3);
}

//----- (006E9180) --------------------------------------------------------  // acclient.c:765297
int _E1294_3()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_7, "Texture");
  return atexit(_E1295_2);
}

//----- (006E91A0) --------------------------------------------------------  // acclient.c:765304
int _E1297_2()
{
  PStringBase<char>::PStringBase<char>(&PointSize_7, "Size");
  return atexit(_E1298_2);
}

//----- (006E91C0) --------------------------------------------------------  // acclient.c:765311
int _E1300_2()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_7, "UseOcclusion");
  return atexit(_E1301_2);
}

//----- (00756BB0) --------------------------------------------------------  // acclient.c:878078
void __cdecl _E74_41()
{
  char *v0; // esi@1

  v0 = &waveform_None_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756BE0) --------------------------------------------------------  // acclient.c:878091
void __cdecl _E77_55()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756C10) --------------------------------------------------------  // acclient.c:878104
void __cdecl _E80_29()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756C40) --------------------------------------------------------  // acclient.c:878117
void __cdecl _E83_18()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756C70) --------------------------------------------------------  // acclient.c:878130
void __cdecl _E86_15()
{
  char *v0; // esi@1

  v0 = &waveform_Square_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756CA0) --------------------------------------------------------  // acclient.c:878143
void __cdecl _E89_26()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756CD0) --------------------------------------------------------  // acclient.c:878156
void __cdecl _E92_28()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756D00) --------------------------------------------------------  // acclient.c:878169
void __cdecl sub_756D00()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756D30) --------------------------------------------------------  // acclient.c:878182
void __cdecl _E98_43()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756D60) --------------------------------------------------------  // acclient.c:878195
void __cdecl _E119_66()
{
  char *v0; // esi@1

  v0 = &PHeader_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756D90) --------------------------------------------------------  // acclient.c:878208
void __cdecl _E122_53()
{
  char *v0; // esi@1

  v0 = &VertexArray_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756DC0) --------------------------------------------------------  // acclient.c:878221
void __cdecl _E125_28()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756DF0) --------------------------------------------------------  // acclient.c:878234
void __cdecl _E128_29()
{
  char *v0; // esi@1

  v0 = &VertexType_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756E20) --------------------------------------------------------  // acclient.c:878247
void __cdecl _E131_25()
{
  char *v0; // esi@1

  v0 = &VertexData_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756E50) --------------------------------------------------------  // acclient.c:878260
void __cdecl _E134_24()
{
  char *v0; // esi@1

  v0 = &Vertex_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756E80) --------------------------------------------------------  // acclient.c:878273
void __cdecl _E137_24()
{
  char *v0; // esi@1

  v0 = &Index_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756EB0) --------------------------------------------------------  // acclient.c:878286
void __cdecl _E140_19()
{
  char *v0; // esi@1

  v0 = &Origin_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756EE0) --------------------------------------------------------  // acclient.c:878299
void __cdecl _E143_20()
{
  char *v0; // esi@1

  v0 = &Normal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756F10) --------------------------------------------------------  // acclient.c:878312
void __cdecl _E146_19()
{
  char *v0; // esi@1

  v0 = &Diffuse_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756F40) --------------------------------------------------------  // acclient.c:878325
void __cdecl _E149_19()
{
  char *v0; // esi@1

  v0 = &Specular_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756F70) --------------------------------------------------------  // acclient.c:878338
void __cdecl _E152_18()
{
  char *v0; // esi@1

  v0 = &UVS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756FA0) --------------------------------------------------------  // acclient.c:878351
void __cdecl _E155_16()
{
  char *v0; // esi@1

  v0 = &VectorS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756FD0) --------------------------------------------------------  // acclient.c:878364
void __cdecl _E158_19()
{
  char *v0; // esi@1

  v0 = &VectorT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757000) --------------------------------------------------------  // acclient.c:878377
void __cdecl _E161_16()
{
  char *v0; // esi@1

  v0 = &VectorSxT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757030) --------------------------------------------------------  // acclient.c:878390
void __cdecl _E164_19()
{
  char *v0; // esi@1

  v0 = &Weights_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757060) --------------------------------------------------------  // acclient.c:878403
void __cdecl _E167_15()
{
  char *v0; // esi@1

  v0 = &Importance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757090) --------------------------------------------------------  // acclient.c:878416
void __cdecl _E170_14()
{
  char *v0; // esi@1

  v0 = &PhysMtl_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007570C0) --------------------------------------------------------  // acclient.c:878429
void __cdecl _E173_13()
{
  char *v0; // esi@1

  v0 = &Material_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007570F0) --------------------------------------------------------  // acclient.c:878442
void __cdecl _E176_14()
{
  char *v0; // esi@1

  v0 = &ID_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757120) --------------------------------------------------------  // acclient.c:878455
void __cdecl _E179_13()
{
  char *v0; // esi@1

  v0 = &FileName_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757150) --------------------------------------------------------  // acclient.c:878468
void __cdecl _E182_13()
{
  char *v0; // esi@1

  v0 = &Polygon_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757180) --------------------------------------------------------  // acclient.c:878481
void __cdecl _E185_10()
{
  char *v0; // esi@1

  v0 = &ID_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007571B0) --------------------------------------------------------  // acclient.c:878494
void __cdecl _E188_11()
{
  char *v0; // esi@1

  v0 = &Indices_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007571E0) --------------------------------------------------------  // acclient.c:878507
void __cdecl _E191_10()
{
  char *v0; // esi@1

  v0 = &MaterialID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757210) --------------------------------------------------------  // acclient.c:878520
void __cdecl _E194_17()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757240) --------------------------------------------------------  // acclient.c:878533
void __cdecl _E197_8()
{
  char *v0; // esi@1

  v0 = &Markings_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757270) --------------------------------------------------------  // acclient.c:878546
void __cdecl _E200_13()
{
  char *v0; // esi@1

  v0 = &Material_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007572A0) --------------------------------------------------------  // acclient.c:878559
void __cdecl _E203_12()
{
  char *v0; // esi@1

  v0 = &Index_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007572D0) --------------------------------------------------------  // acclient.c:878572
void __cdecl _E206_15()
{
  char *v0; // esi@1

  v0 = &Filename_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757300) --------------------------------------------------------  // acclient.c:878585
void __cdecl _E209_10()
{
  char *v0; // esi@1

  v0 = &Surface_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757330) --------------------------------------------------------  // acclient.c:878598
void __cdecl _E212_13()
{
  char *v0; // esi@1

  v0 = &CellPoly_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757360) --------------------------------------------------------  // acclient.c:878611
void __cdecl _E215_9()
{
  char *v0; // esi@1

  v0 = &Sphere_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757390) --------------------------------------------------------  // acclient.c:878624
void __cdecl _E218_10()
{
  char *v0; // esi@1

  v0 = &Side_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007573C0) --------------------------------------------------------  // acclient.c:878637
void __cdecl _E221_10()
{
  char *v0; // esi@1

  v0 = &Positive_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007573F0) --------------------------------------------------------  // acclient.c:878650
void __cdecl _E224_10()
{
  char *v0; // esi@1

  v0 = &Negative_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757420) --------------------------------------------------------  // acclient.c:878663
void __cdecl _E227_10()
{
  char *v0; // esi@1

  v0 = &Polygon_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757450) --------------------------------------------------------  // acclient.c:878676
void __cdecl _E230_10()
{
  char *v0; // esi@1

  v0 = &OtherCell_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757480) --------------------------------------------------------  // acclient.c:878689
void __cdecl _E233_9()
{
  char *v0; // esi@1

  v0 = &CellPortal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007574B0) --------------------------------------------------------  // acclient.c:878702
void __cdecl _E236_9()
{
  char *v0; // esi@1

  v0 = &Portal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007574E0) --------------------------------------------------------  // acclient.c:878715
void __cdecl _E239_10()
{
  char *v0; // esi@1

  v0 = &OtherCell_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757510) --------------------------------------------------------  // acclient.c:878728
void __cdecl _E242_10()
{
  char *v0; // esi@1

  v0 = &OtherPortal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757540) --------------------------------------------------------  // acclient.c:878741
void __cdecl _E245_9()
{
  char *v0; // esi@1

  v0 = &ExactMatch_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757570) --------------------------------------------------------  // acclient.c:878754
void __cdecl _E248_9()
{
  char *v0; // esi@1

  v0 = &StabList_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007575A0) --------------------------------------------------------  // acclient.c:878767
void __cdecl _E251_9()
{
  char *v0; // esi@1

  v0 = &Period_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007575D0) --------------------------------------------------------  // acclient.c:878780
void __cdecl _E254_10()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757600) --------------------------------------------------------  // acclient.c:878793
void __cdecl _E257_8()
{
  char *v0; // esi@1

  v0 = &Transform_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757630) --------------------------------------------------------  // acclient.c:878806
void __cdecl _E260_9()
{
  char *v0; // esi@1

  v0 = &Scale_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757660) --------------------------------------------------------  // acclient.c:878819
void __cdecl _E263_7()
{
  char *v0; // esi@1

  v0 = &Weight_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757690) --------------------------------------------------------  // acclient.c:878832
void __cdecl _E266_7()
{
  char *v0; // esi@1

  v0 = &Offset_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007576C0) --------------------------------------------------------  // acclient.c:878845
void __cdecl _E269_7()
{
  char *v0; // esi@1

  v0 = &Quaternion_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007576F0) --------------------------------------------------------  // acclient.c:878858
void __cdecl _E272_6()
{
  char *v0; // esi@1

  v0 = &Rotation_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757720) --------------------------------------------------------  // acclient.c:878871
void __cdecl _E275_6()
{
  char *v0; // esi@1

  v0 = &STime_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757750) --------------------------------------------------------  // acclient.c:878884
void __cdecl _E278_6()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757780) --------------------------------------------------------  // acclient.c:878897
void __cdecl _E281_7()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007577B0) --------------------------------------------------------  // acclient.c:878910
void __cdecl _E284_6()
{
  char *v0; // esi@1

  v0 = &LowPt_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007577E0) --------------------------------------------------------  // acclient.c:878923
void __cdecl _E287_7()
{
  char *v0; // esi@1

  v0 = &Radius_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757810) --------------------------------------------------------  // acclient.c:878936
void __cdecl _E290_7()
{
  char *v0; // esi@1

  v0 = &Height_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757840) --------------------------------------------------------  // acclient.c:878949
void __cdecl _E293_6()
{
  char *v0; // esi@1

  v0 = &Texture2D_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757870) --------------------------------------------------------  // acclient.c:878962
void __cdecl _E296_7()
{
  char *v0; // esi@1

  v0 = &Texture3D_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007578A0) --------------------------------------------------------  // acclient.c:878975
void __cdecl _E299_5()
{
  char *v0; // esi@1

  v0 = &TextureCube_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007578D0) --------------------------------------------------------  // acclient.c:878988
void __cdecl _E302_6()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757900) --------------------------------------------------------  // acclient.c:879001
void __cdecl _E305_5()
{
  char *v0; // esi@1

  v0 = &MovieFileName_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757930) --------------------------------------------------------  // acclient.c:879014
void __cdecl _E308_6()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757960) --------------------------------------------------------  // acclient.c:879027
void __cdecl _E311_5()
{
  char *v0; // esi@1

  v0 = &Levels_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757990) --------------------------------------------------------  // acclient.c:879040
void __cdecl _E314_6()
{
  char *v0; // esi@1

  v0 = &NodeName_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007579C0) --------------------------------------------------------  // acclient.c:879053
void __cdecl _E317_5()
{
  char *v0; // esi@1

  v0 = &Material_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007579F0) --------------------------------------------------------  // acclient.c:879066
void __cdecl _E320_6()
{
  char *v0; // esi@1

  v0 = &MaterialType_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757A20) --------------------------------------------------------  // acclient.c:879079
void __cdecl _E323_5()
{
  char *v0; // esi@1

  v0 = &Modifier_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757A50) --------------------------------------------------------  // acclient.c:879092
void __cdecl _E326_6()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757A80) --------------------------------------------------------  // acclient.c:879105
void __cdecl _E329_5()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757AB0) --------------------------------------------------------  // acclient.c:879118
void __cdecl _E332_6()
{
  char *v0; // esi@1

  v0 = &NodeName_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757AE0) --------------------------------------------------------  // acclient.c:879131
void __cdecl _E335_5()
{
  char *v0; // esi@1

  v0 = &SortMode_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757B10) --------------------------------------------------------  // acclient.c:879144
void __cdecl _E338_5()
{
  char *v0; // esi@1

  v0 = &SortMode_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757B40) --------------------------------------------------------  // acclient.c:879157
void __cdecl _E341_5()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757B70) --------------------------------------------------------  // acclient.c:879170
void __cdecl _E344_3()
{
  char *v0; // esi@1

  v0 = &NodeName_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757BA0) --------------------------------------------------------  // acclient.c:879183
void __cdecl _E347_3()
{
  char *v0; // esi@1

  v0 = &NodeName_82.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_82.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757BD0) --------------------------------------------------------  // acclient.c:879196
void __cdecl _E350_3()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757C00) --------------------------------------------------------  // acclient.c:879209
void __cdecl _E353_3()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757C30) --------------------------------------------------------  // acclient.c:879222
void __cdecl _E356_3()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757C60) --------------------------------------------------------  // acclient.c:879235
void __cdecl _E359_3()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757C90) --------------------------------------------------------  // acclient.c:879248
void __cdecl _E362_3()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757CC0) --------------------------------------------------------  // acclient.c:879261
void __cdecl _E365_3()
{
  char *v0; // esi@1

  v0 = &NodeName_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757CF0) --------------------------------------------------------  // acclient.c:879274
void __cdecl _E368_3()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757D20) --------------------------------------------------------  // acclient.c:879287
void __cdecl _E371_3()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757D50) --------------------------------------------------------  // acclient.c:879300
void __cdecl _E374_3()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757D80) --------------------------------------------------------  // acclient.c:879313
void __cdecl _E377_3()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757DB0) --------------------------------------------------------  // acclient.c:879326
void __cdecl _E380_3()
{
  char *v0; // esi@1

  v0 = &TrueFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757DE0) --------------------------------------------------------  // acclient.c:879339
void __cdecl _E383_3()
{
  char *v0; // esi@1

  v0 = &FalseFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757E10) --------------------------------------------------------  // acclient.c:879352
void __cdecl _E386_3()
{
  char *v0; // esi@1

  v0 = &RenderPass_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757E40) --------------------------------------------------------  // acclient.c:879365
void __cdecl _E389_3()
{
  char *v0; // esi@1

  v0 = &Blend_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757E70) --------------------------------------------------------  // acclient.c:879378
void __cdecl _E392_3()
{
  char *v0; // esi@1

  v0 = &DepthTest_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757EA0) --------------------------------------------------------  // acclient.c:879391
void __cdecl _E395_3()
{
  char *v0; // esi@1

  v0 = &DepthWrite_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757ED0) --------------------------------------------------------  // acclient.c:879404
void __cdecl _E398_3()
{
  char *v0; // esi@1

  v0 = &CullMode_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757F00) --------------------------------------------------------  // acclient.c:879417
void __cdecl _E401_3()
{
  char *v0; // esi@1

  v0 = &DepthFog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757F30) --------------------------------------------------------  // acclient.c:879430
void __cdecl _E404_3()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757F60) --------------------------------------------------------  // acclient.c:879443
void __cdecl _E407_3()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757F90) --------------------------------------------------------  // acclient.c:879456
void __cdecl _E410_3()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757FC0) --------------------------------------------------------  // acclient.c:879469
void __cdecl _E413_3()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00757FF0) --------------------------------------------------------  // acclient.c:879482
void __cdecl _E416_3()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758020) --------------------------------------------------------  // acclient.c:879495
void __cdecl _E419_3()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758050) --------------------------------------------------------  // acclient.c:879508
void __cdecl _E422_3()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758080) --------------------------------------------------------  // acclient.c:879521
void __cdecl _E425_3()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007580B0) --------------------------------------------------------  // acclient.c:879534
void __cdecl _E428_3()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007580E0) --------------------------------------------------------  // acclient.c:879547
void __cdecl _E431_3()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758110) --------------------------------------------------------  // acclient.c:879560
void __cdecl _E434_3()
{
  char *v0; // esi@1

  v0 = &Ambient_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758140) --------------------------------------------------------  // acclient.c:879573
void __cdecl _E437_3()
{
  char *v0; // esi@1

  v0 = &Diffuse_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758170) --------------------------------------------------------  // acclient.c:879586
void __cdecl _E440_3()
{
  char *v0; // esi@1

  v0 = &Specular_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007581A0) --------------------------------------------------------  // acclient.c:879599
void __cdecl _E443_3()
{
  char *v0; // esi@1

  v0 = &SpecularPower_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007581D0) --------------------------------------------------------  // acclient.c:879612
void __cdecl _E446_3()
{
  char *v0; // esi@1

  v0 = &Dye_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758200) --------------------------------------------------------  // acclient.c:879625
void __cdecl _E449_3()
{
  char *v0; // esi@1

  v0 = &Emissive_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758230) --------------------------------------------------------  // acclient.c:879638
void __cdecl _E452_3()
{
  char *v0; // esi@1

  v0 = &VertexFormat_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758260) --------------------------------------------------------  // acclient.c:879651
void __cdecl _E455_3()
{
  char *v0; // esi@1

  v0 = &VertexShader_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758290) --------------------------------------------------------  // acclient.c:879664
void __cdecl _E458_3()
{
  char *v0; // esi@1

  v0 = &PixelShader_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007582C0) --------------------------------------------------------  // acclient.c:879677
void __cdecl _E461_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007582F0) --------------------------------------------------------  // acclient.c:879690
void __cdecl _E464_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758320) --------------------------------------------------------  // acclient.c:879703
void __cdecl _E467_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758350) --------------------------------------------------------  // acclient.c:879716
void __cdecl _E470_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758380) --------------------------------------------------------  // acclient.c:879729
void __cdecl _E473_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007583B0) --------------------------------------------------------  // acclient.c:879742
void __cdecl _E476_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007583E0) --------------------------------------------------------  // acclient.c:879755
void __cdecl _E479_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758410) --------------------------------------------------------  // acclient.c:879768
void __cdecl _E482_3()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758440) --------------------------------------------------------  // acclient.c:879781
void __cdecl _E485_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758470) --------------------------------------------------------  // acclient.c:879794
void __cdecl _E488_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007584A0) --------------------------------------------------------  // acclient.c:879807
void __cdecl _E491_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007584D0) --------------------------------------------------------  // acclient.c:879820
void __cdecl _E494_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758500) --------------------------------------------------------  // acclient.c:879833
void __cdecl _E497_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758530) --------------------------------------------------------  // acclient.c:879846
void __cdecl _E500_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758560) --------------------------------------------------------  // acclient.c:879859
void __cdecl _E503_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758590) --------------------------------------------------------  // acclient.c:879872
void __cdecl _E506_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007585C0) --------------------------------------------------------  // acclient.c:879885
void __cdecl _E509_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007585F0) --------------------------------------------------------  // acclient.c:879898
void __cdecl _E512_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758620) --------------------------------------------------------  // acclient.c:879911
void __cdecl _E515_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758650) --------------------------------------------------------  // acclient.c:879924
void __cdecl _E518_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758680) --------------------------------------------------------  // acclient.c:879937
void __cdecl _E521_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007586B0) --------------------------------------------------------  // acclient.c:879950
void __cdecl _E524_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007586E0) --------------------------------------------------------  // acclient.c:879963
void __cdecl _E527_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758710) --------------------------------------------------------  // acclient.c:879976
void __cdecl _E530_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758740) --------------------------------------------------------  // acclient.c:879989
void __cdecl _E533_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758770) --------------------------------------------------------  // acclient.c:880002
void __cdecl _E536_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007587A0) --------------------------------------------------------  // acclient.c:880015
void __cdecl _E539_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007587D0) --------------------------------------------------------  // acclient.c:880028
void __cdecl _E542_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758800) --------------------------------------------------------  // acclient.c:880041
void __cdecl _E545_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758830) --------------------------------------------------------  // acclient.c:880054
void __cdecl _E548_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758860) --------------------------------------------------------  // acclient.c:880067
void __cdecl _E551_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758890) --------------------------------------------------------  // acclient.c:880080
void __cdecl _E554_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007588C0) --------------------------------------------------------  // acclient.c:880093
void __cdecl _E557_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007588F0) --------------------------------------------------------  // acclient.c:880106
void __cdecl _E560_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758920) --------------------------------------------------------  // acclient.c:880119
void __cdecl _E563_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758950) --------------------------------------------------------  // acclient.c:880132
void __cdecl _E566_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758980) --------------------------------------------------------  // acclient.c:880145
void __cdecl _E569_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007589B0) --------------------------------------------------------  // acclient.c:880158
void __cdecl _E572_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007589E0) --------------------------------------------------------  // acclient.c:880171
void __cdecl _E575_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758A10) --------------------------------------------------------  // acclient.c:880184
void __cdecl _E578_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758A40) --------------------------------------------------------  // acclient.c:880197
void __cdecl _E581_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758A70) --------------------------------------------------------  // acclient.c:880210
void __cdecl _E584_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758AA0) --------------------------------------------------------  // acclient.c:880223
void __cdecl _E587_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758AD0) --------------------------------------------------------  // acclient.c:880236
void __cdecl _E590_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758B00) --------------------------------------------------------  // acclient.c:880249
void __cdecl _E593_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758B30) --------------------------------------------------------  // acclient.c:880262
void __cdecl _E596_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758B60) --------------------------------------------------------  // acclient.c:880275
void __cdecl _E599_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758B90) --------------------------------------------------------  // acclient.c:880288
void __cdecl _E602_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758BC0) --------------------------------------------------------  // acclient.c:880301
void __cdecl _E605_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758BF0) --------------------------------------------------------  // acclient.c:880314
void __cdecl _E608_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758C20) --------------------------------------------------------  // acclient.c:880327
void __cdecl _E611_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758C50) --------------------------------------------------------  // acclient.c:880340
void __cdecl _E614_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758C80) --------------------------------------------------------  // acclient.c:880353
void __cdecl _E617_3()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758CB0) --------------------------------------------------------  // acclient.c:880366
void __cdecl _E620_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758CE0) --------------------------------------------------------  // acclient.c:880379
void __cdecl _E623_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758D10) --------------------------------------------------------  // acclient.c:880392
void __cdecl _E626_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758D40) --------------------------------------------------------  // acclient.c:880405
void __cdecl _E629_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758D70) --------------------------------------------------------  // acclient.c:880418
void __cdecl _E632_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758DA0) --------------------------------------------------------  // acclient.c:880431
void __cdecl _E635_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758DD0) --------------------------------------------------------  // acclient.c:880444
void __cdecl _E638_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758E00) --------------------------------------------------------  // acclient.c:880457
void __cdecl _E641_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758E30) --------------------------------------------------------  // acclient.c:880470
void __cdecl _E644_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758E60) --------------------------------------------------------  // acclient.c:880483
void __cdecl _E647_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758E90) --------------------------------------------------------  // acclient.c:880496
void __cdecl _E650_3()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758EC0) --------------------------------------------------------  // acclient.c:880509
void __cdecl _E653_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758EF0) --------------------------------------------------------  // acclient.c:880522
void __cdecl _E656_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758F20) --------------------------------------------------------  // acclient.c:880535
void __cdecl _E659_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758F50) --------------------------------------------------------  // acclient.c:880548
void __cdecl _E662_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758F80) --------------------------------------------------------  // acclient.c:880561
void __cdecl _E665_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758FB0) --------------------------------------------------------  // acclient.c:880574
void __cdecl _E668_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00758FE0) --------------------------------------------------------  // acclient.c:880587
void __cdecl _E671_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759010) --------------------------------------------------------  // acclient.c:880600
void __cdecl _E674_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759040) --------------------------------------------------------  // acclient.c:880613
void __cdecl _E677_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759070) --------------------------------------------------------  // acclient.c:880626
void __cdecl _E680_3()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007590A0) --------------------------------------------------------  // acclient.c:880639
void __cdecl _E683_3()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007590D0) --------------------------------------------------------  // acclient.c:880652
void __cdecl _E686_3()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759100) --------------------------------------------------------  // acclient.c:880665
void __cdecl _E689_3()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759130) --------------------------------------------------------  // acclient.c:880678
void __cdecl _E692_3()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759160) --------------------------------------------------------  // acclient.c:880691
void __cdecl _E695_3()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759190) --------------------------------------------------------  // acclient.c:880704
void __cdecl _E698_3()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007591C0) --------------------------------------------------------  // acclient.c:880717
void __cdecl _E701_3()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007591F0) --------------------------------------------------------  // acclient.c:880730
void __cdecl _E704_3()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759220) --------------------------------------------------------  // acclient.c:880743
void __cdecl _E707_3()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759250) --------------------------------------------------------  // acclient.c:880756
void __cdecl _E710_3()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759280) --------------------------------------------------------  // acclient.c:880769
void __cdecl _E713_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007592B0) --------------------------------------------------------  // acclient.c:880782
void __cdecl _E716_3()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007592E0) --------------------------------------------------------  // acclient.c:880795
void __cdecl _E719_3()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759310) --------------------------------------------------------  // acclient.c:880808
void __cdecl _E722_3()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759340) --------------------------------------------------------  // acclient.c:880821
void __cdecl _E725_3()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759370) --------------------------------------------------------  // acclient.c:880834
void __cdecl _E728_3()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007593A0) --------------------------------------------------------  // acclient.c:880847
void __cdecl _E731_3()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007593D0) --------------------------------------------------------  // acclient.c:880860
void __cdecl _E734_3()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759400) --------------------------------------------------------  // acclient.c:880873
void __cdecl _E737_3()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759430) --------------------------------------------------------  // acclient.c:880886
void __cdecl _E740_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759460) --------------------------------------------------------  // acclient.c:880899
void __cdecl _E743_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759490) --------------------------------------------------------  // acclient.c:880912
void __cdecl _E746_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007594C0) --------------------------------------------------------  // acclient.c:880925
void __cdecl _E749_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007594F0) --------------------------------------------------------  // acclient.c:880938
void __cdecl _E752_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759520) --------------------------------------------------------  // acclient.c:880951
void __cdecl _E755_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759550) --------------------------------------------------------  // acclient.c:880964
void __cdecl _E758_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759580) --------------------------------------------------------  // acclient.c:880977
void __cdecl _E761_3()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007595B0) --------------------------------------------------------  // acclient.c:880990
void __cdecl _E764_3()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007595E0) --------------------------------------------------------  // acclient.c:881003
void __cdecl _E767_3()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759610) --------------------------------------------------------  // acclient.c:881016
void __cdecl _E770_3()
{
  char *v0; // esi@1

  v0 = &NodeName_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759640) --------------------------------------------------------  // acclient.c:881029
void __cdecl _E773_3()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759670) --------------------------------------------------------  // acclient.c:881042
void __cdecl _E776_3()
{
  char *v0; // esi@1

  v0 = &SamplerName_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007596A0) --------------------------------------------------------  // acclient.c:881055
void __cdecl _E779_3()
{
  char *v0; // esi@1

  v0 = &Texture_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007596D0) --------------------------------------------------------  // acclient.c:881068
void __cdecl _E782_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759700) --------------------------------------------------------  // acclient.c:881081
void __cdecl _E785_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759730) --------------------------------------------------------  // acclient.c:881094
void __cdecl _E788_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759760) --------------------------------------------------------  // acclient.c:881107
void __cdecl _E791_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759790) --------------------------------------------------------  // acclient.c:881120
void __cdecl _E794_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007597C0) --------------------------------------------------------  // acclient.c:881133
void __cdecl _E797_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007597F0) --------------------------------------------------------  // acclient.c:881146
void __cdecl _E800_3()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759820) --------------------------------------------------------  // acclient.c:881159
void __cdecl _E803_3()
{
  char *v0; // esi@1

  v0 = &AddressMode_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759850) --------------------------------------------------------  // acclient.c:881172
void __cdecl _E806_3()
{
  char *v0; // esi@1

  v0 = &TexFilter_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759880) --------------------------------------------------------  // acclient.c:881185
void __cdecl _E809_3()
{
  char *v0; // esi@1

  v0 = &ColorOp_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007598B0) --------------------------------------------------------  // acclient.c:881198
void __cdecl _E812_3()
{
  char *v0; // esi@1

  v0 = &ColorArg1_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007598E0) --------------------------------------------------------  // acclient.c:881211
void __cdecl _E815_3()
{
  char *v0; // esi@1

  v0 = &ColorArg2_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759910) --------------------------------------------------------  // acclient.c:881224
void __cdecl _E818_3()
{
  char *v0; // esi@1

  v0 = &AlphaOp_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759940) --------------------------------------------------------  // acclient.c:881237
void __cdecl _E821_3()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759970) --------------------------------------------------------  // acclient.c:881250
void __cdecl _E824_3()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007599A0) --------------------------------------------------------  // acclient.c:881263
void __cdecl _E827_3()
{
  char *v0; // esi@1

  v0 = &TexCoord_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007599D0) --------------------------------------------------------  // acclient.c:881276
void __cdecl _E830_3()
{
  char *v0; // esi@1

  v0 = &UseProjection_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759A00) --------------------------------------------------------  // acclient.c:881289
void __cdecl _E833_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759A30) --------------------------------------------------------  // acclient.c:881302
void __cdecl _E836_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759A60) --------------------------------------------------------  // acclient.c:881315
void __cdecl _E839_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759A90) --------------------------------------------------------  // acclient.c:881328
void __cdecl _E842_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759AC0) --------------------------------------------------------  // acclient.c:881341
void __cdecl _E845_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759AF0) --------------------------------------------------------  // acclient.c:881354
void __cdecl _E848_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759B20) --------------------------------------------------------  // acclient.c:881367
void __cdecl _E851_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759B50) --------------------------------------------------------  // acclient.c:881380
void __cdecl _E854_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759B80) --------------------------------------------------------  // acclient.c:881393
void __cdecl _E857_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759BB0) --------------------------------------------------------  // acclient.c:881406
void __cdecl _E860_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759BE0) --------------------------------------------------------  // acclient.c:881419
void __cdecl _E863_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759C10) --------------------------------------------------------  // acclient.c:881432
void __cdecl _E866_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759C40) --------------------------------------------------------  // acclient.c:881445
void __cdecl _E869_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759C70) --------------------------------------------------------  // acclient.c:881458
void __cdecl _E872_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759CA0) --------------------------------------------------------  // acclient.c:881471
void __cdecl _E875_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759CD0) --------------------------------------------------------  // acclient.c:881484
void __cdecl _E878_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759D00) --------------------------------------------------------  // acclient.c:881497
void __cdecl _E881_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759D30) --------------------------------------------------------  // acclient.c:881510
void __cdecl _E884_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759D60) --------------------------------------------------------  // acclient.c:881523
void __cdecl _E887_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759D90) --------------------------------------------------------  // acclient.c:881536
void __cdecl _E890_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759DC0) --------------------------------------------------------  // acclient.c:881549
void __cdecl _E893_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759DF0) --------------------------------------------------------  // acclient.c:881562
void __cdecl _E896_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759E20) --------------------------------------------------------  // acclient.c:881575
void __cdecl _E899_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759E50) --------------------------------------------------------  // acclient.c:881588
void __cdecl _E902_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759E80) --------------------------------------------------------  // acclient.c:881601
void __cdecl _E905_3()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759EB0) --------------------------------------------------------  // acclient.c:881614
void __cdecl _E908_3()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759EE0) --------------------------------------------------------  // acclient.c:881627
void __cdecl _E911_3()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759F10) --------------------------------------------------------  // acclient.c:881640
void __cdecl _E914_3()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759F40) --------------------------------------------------------  // acclient.c:881653
void __cdecl _E917_3()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759F70) --------------------------------------------------------  // acclient.c:881666
void __cdecl _E920_3()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759FA0) --------------------------------------------------------  // acclient.c:881679
void __cdecl _E923_3()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00759FD0) --------------------------------------------------------  // acclient.c:881692
void __cdecl _E926_3()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A000) --------------------------------------------------------  // acclient.c:881705
void __cdecl _E929_3()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A030) --------------------------------------------------------  // acclient.c:881718
void __cdecl _E932_3()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A060) --------------------------------------------------------  // acclient.c:881731
void __cdecl _E935_3()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A090) --------------------------------------------------------  // acclient.c:881744
void __cdecl _E938_3()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A0C0) --------------------------------------------------------  // acclient.c:881757
void __cdecl _E941_3()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A0F0) --------------------------------------------------------  // acclient.c:881770
void __cdecl _E944_3()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A120) --------------------------------------------------------  // acclient.c:881783
void __cdecl _E947_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A150) --------------------------------------------------------  // acclient.c:881796
void __cdecl _E950_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A180) --------------------------------------------------------  // acclient.c:881809
void __cdecl _E953_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A1B0) --------------------------------------------------------  // acclient.c:881822
void __cdecl _E956_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A1E0) --------------------------------------------------------  // acclient.c:881835
void __cdecl _E959_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A210) --------------------------------------------------------  // acclient.c:881848
void __cdecl _E962_3()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A240) --------------------------------------------------------  // acclient.c:881861
void __cdecl _E965_3()
{
  char *v0; // esi@1

  v0 = &NodeName_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A270) --------------------------------------------------------  // acclient.c:881874
void __cdecl _E968_3()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A2A0) --------------------------------------------------------  // acclient.c:881887
void __cdecl _E971_3()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A2D0) --------------------------------------------------------  // acclient.c:881900
void __cdecl _E974_3()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A300) --------------------------------------------------------  // acclient.c:881913
void __cdecl _E977_3()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A330) --------------------------------------------------------  // acclient.c:881926
void __cdecl _E980_3()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A360) --------------------------------------------------------  // acclient.c:881939
void __cdecl _E983_3()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A390) --------------------------------------------------------  // acclient.c:881952
void __cdecl _E986_3()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A3C0) --------------------------------------------------------  // acclient.c:881965
void __cdecl _E989_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A3F0) --------------------------------------------------------  // acclient.c:881978
void __cdecl _E992_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A420) --------------------------------------------------------  // acclient.c:881991
void __cdecl _E995_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A450) --------------------------------------------------------  // acclient.c:882004
void __cdecl _E998_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A480) --------------------------------------------------------  // acclient.c:882017
void __cdecl _E1001_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A4B0) --------------------------------------------------------  // acclient.c:882030
void __cdecl _E1004_3()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A4E0) --------------------------------------------------------  // acclient.c:882043
void __cdecl _E1007_3()
{
  char *v0; // esi@1

  v0 = &NodeName_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A510) --------------------------------------------------------  // acclient.c:882056
void __cdecl _E1010_3()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A540) --------------------------------------------------------  // acclient.c:882069
void __cdecl _E1013_3()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A570) --------------------------------------------------------  // acclient.c:882082
void __cdecl _E1016_3()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A5A0) --------------------------------------------------------  // acclient.c:882095
void __cdecl _E1019_3()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A5D0) --------------------------------------------------------  // acclient.c:882108
void __cdecl _E1022_3()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A600) --------------------------------------------------------  // acclient.c:882121
void __cdecl _E1025_3()
{
  char *v0; // esi@1

  v0 = &ScaleType_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A630) --------------------------------------------------------  // acclient.c:882134
void __cdecl _E1028_3()
{
  char *v0; // esi@1

  v0 = &WorldSpace_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A660) --------------------------------------------------------  // acclient.c:882147
void __cdecl _E1031_3()
{
  char *v0; // esi@1

  v0 = &ForceDraw_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A690) --------------------------------------------------------  // acclient.c:882160
void __cdecl _E1034_3()
{
  char *v0; // esi@1

  v0 = &NumEmitters_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A6C0) --------------------------------------------------------  // acclient.c:882173
void __cdecl _E1037_3()
{
  char *v0; // esi@1

  v0 = &Material_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A6F0) --------------------------------------------------------  // acclient.c:882186
void __cdecl _E1040_3()
{
  char *v0; // esi@1

  v0 = &Version_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A720) --------------------------------------------------------  // acclient.c:882199
void __cdecl _E1043_3()
{
  char *v0; // esi@1

  v0 = &MaxParticles_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A750) --------------------------------------------------------  // acclient.c:882212
void __cdecl _E1046_3()
{
  char *v0; // esi@1

  v0 = &NodeName_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A780) --------------------------------------------------------  // acclient.c:882225
void __cdecl _E1049_3()
{
  char *v0; // esi@1

  v0 = &Origin_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A7B0) --------------------------------------------------------  // acclient.c:882238
void __cdecl _E1052_3()
{
  char *v0; // esi@1

  v0 = &Shape_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A7E0) --------------------------------------------------------  // acclient.c:882251
void __cdecl _E1055_3()
{
  char *v0; // esi@1

  v0 = &Shape_Point_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A810) --------------------------------------------------------  // acclient.c:882264
void __cdecl _E1058_3()
{
  char *v0; // esi@1

  v0 = &Shape_Line_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A840) --------------------------------------------------------  // acclient.c:882277
void __cdecl _E1061_3()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A870) --------------------------------------------------------  // acclient.c:882290
void __cdecl _E1064_3()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A8A0) --------------------------------------------------------  // acclient.c:882303
void __cdecl _E1067_3()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A8D0) --------------------------------------------------------  // acclient.c:882316
void __cdecl _E1070_3()
{
  char *v0; // esi@1

  v0 = &ParticleShape_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A900) --------------------------------------------------------  // acclient.c:882329
void __cdecl _E1073_3()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A930) --------------------------------------------------------  // acclient.c:882342
void __cdecl _E1076_3()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A960) --------------------------------------------------------  // acclient.c:882355
void __cdecl _E1079_3()
{
  char *v0; // esi@1

  v0 = &Streak_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A990) --------------------------------------------------------  // acclient.c:882368
void __cdecl _E1082_3()
{
  char *v0; // esi@1

  v0 = &Rotation_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A9C0) --------------------------------------------------------  // acclient.c:882381
void __cdecl _E1085_3()
{
  char *v0; // esi@1

  v0 = &WorldRotation_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075A9F0) --------------------------------------------------------  // acclient.c:882394
void __cdecl _E1088_3()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AA20) --------------------------------------------------------  // acclient.c:882407
void __cdecl _E1091_3()
{
  char *v0; // esi@1

  v0 = &ParticleScale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AA50) --------------------------------------------------------  // acclient.c:882420
void __cdecl _E1094_3()
{
  char *v0; // esi@1

  v0 = &Scale_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AA80) --------------------------------------------------------  // acclient.c:882433
void __cdecl _E1097_3()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AAB0) --------------------------------------------------------  // acclient.c:882446
void __cdecl _E1100_3()
{
  char *v0; // esi@1

  v0 = &BirthRate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AAE0) --------------------------------------------------------  // acclient.c:882459
void __cdecl _E1103_3()
{
  char *v0; // esi@1

  v0 = &Lifespan_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AB10) --------------------------------------------------------  // acclient.c:882472
void __cdecl _E1106_3()
{
  char *v0; // esi@1

  v0 = &Velocity_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AB40) --------------------------------------------------------  // acclient.c:882485
void __cdecl _E1109_3()
{
  char *v0; // esi@1

  v0 = &Direction_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AB70) --------------------------------------------------------  // acclient.c:882498
void __cdecl _E1112_3()
{
  char *v0; // esi@1

  v0 = &MinSpread_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ABA0) --------------------------------------------------------  // acclient.c:882511
void __cdecl _E1115_3()
{
  char *v0; // esi@1

  v0 = &MaxSpread_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ABD0) --------------------------------------------------------  // acclient.c:882524
void __cdecl _E1118_3()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AC00) --------------------------------------------------------  // acclient.c:882537
void __cdecl _E1121_3()
{
  char *v0; // esi@1

  v0 = &BlastCount_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AC30) --------------------------------------------------------  // acclient.c:882550
void __cdecl _E1124_3()
{
  char *v0; // esi@1

  v0 = &StartTime_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AC60) --------------------------------------------------------  // acclient.c:882563
void __cdecl _E1127_3()
{
  char *v0; // esi@1

  v0 = &TimeLimit_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AC90) --------------------------------------------------------  // acclient.c:882576
void __cdecl _E1130_3()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ACC0) --------------------------------------------------------  // acclient.c:882589
void __cdecl _E1133_3()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ACF0) --------------------------------------------------------  // acclient.c:882602
void __cdecl _E1136_3()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AD20) --------------------------------------------------------  // acclient.c:882615
void __cdecl _E1139_3()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AD50) --------------------------------------------------------  // acclient.c:882628
void __cdecl _E1142_3()
{
  char *v0; // esi@1

  v0 = &IsActive_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AD80) --------------------------------------------------------  // acclient.c:882641
void __cdecl _E1145_3()
{
  char *v0; // esi@1

  v0 = &FadeIn_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ADB0) --------------------------------------------------------  // acclient.c:882654
void __cdecl _E1148_3()
{
  char *v0; // esi@1

  v0 = &FadeOut_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075ADE0) --------------------------------------------------------  // acclient.c:882667
void __cdecl _E1151_3()
{
  char *v0; // esi@1

  v0 = &ConstrainX_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AE10) --------------------------------------------------------  // acclient.c:882680
void __cdecl _E1154_3()
{
  char *v0; // esi@1

  v0 = &ConstrainY_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AE40) --------------------------------------------------------  // acclient.c:882693
void __cdecl _E1157_3()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AE70) --------------------------------------------------------  // acclient.c:882706
void __cdecl _E1160_3()
{
  char *v0; // esi@1

  v0 = &NodeName_88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AEA0) --------------------------------------------------------  // acclient.c:882719
void __cdecl _E1163_3()
{
  char *v0; // esi@1

  v0 = &Time_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AED0) --------------------------------------------------------  // acclient.c:882732
void __cdecl _E1166_3()
{
  char *v0; // esi@1

  v0 = &Flags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AF00) --------------------------------------------------------  // acclient.c:882745
void __cdecl _E1169_3()
{
  char *v0; // esi@1

  v0 = &Flags_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AF30) --------------------------------------------------------  // acclient.c:882758
void __cdecl _E1172_3()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AF60) --------------------------------------------------------  // acclient.c:882771
void __cdecl _E1175_3()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AF90) --------------------------------------------------------  // acclient.c:882784
void __cdecl _E1178_3()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AFC0) --------------------------------------------------------  // acclient.c:882797
void __cdecl _E1181_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075AFF0) --------------------------------------------------------  // acclient.c:882810
void __cdecl _E1184_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B020) --------------------------------------------------------  // acclient.c:882823
void __cdecl _E1187_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B050) --------------------------------------------------------  // acclient.c:882836
void __cdecl _E1190_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B080) --------------------------------------------------------  // acclient.c:882849
void __cdecl _E1193_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B0B0) --------------------------------------------------------  // acclient.c:882862
void __cdecl _E1196_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B0E0) --------------------------------------------------------  // acclient.c:882875
void __cdecl _E1199_3()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B110) --------------------------------------------------------  // acclient.c:882888
void __cdecl _E1202_3()
{
  char *v0; // esi@1

  v0 = &Scale_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B140) --------------------------------------------------------  // acclient.c:882901
void __cdecl _E1205_3()
{
  char *v0; // esi@1

  v0 = &ScaleX_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B170) --------------------------------------------------------  // acclient.c:882914
void __cdecl _E1208_3()
{
  char *v0; // esi@1

  v0 = &ScaleY_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B1A0) --------------------------------------------------------  // acclient.c:882927
void __cdecl _E1211_3()
{
  char *v0; // esi@1

  v0 = &Color_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B1D0) --------------------------------------------------------  // acclient.c:882940
void __cdecl _E1214_3()
{
  char *v0; // esi@1

  v0 = &Mass_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B200) --------------------------------------------------------  // acclient.c:882953
void __cdecl _E1217_3()
{
  char *v0; // esi@1

  v0 = &PFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B230) --------------------------------------------------------  // acclient.c:882966
void __cdecl _E1220_3()
{
  char *v0; // esi@1

  v0 = &PFlags_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B260) --------------------------------------------------------  // acclient.c:882979
void __cdecl _E1223_3()
{
  char *v0; // esi@1

  v0 = &PCType_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B290) --------------------------------------------------------  // acclient.c:882992
void __cdecl _E1226_3()
{
  char *v0; // esi@1

  v0 = &PCType_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B2C0) --------------------------------------------------------  // acclient.c:883005
void __cdecl _E1229_3()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B2F0) --------------------------------------------------------  // acclient.c:883018
void __cdecl _E1232_3()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B320) --------------------------------------------------------  // acclient.c:883031
void __cdecl _E1235_3()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B350) --------------------------------------------------------  // acclient.c:883044
void __cdecl _E1238_3()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B380) --------------------------------------------------------  // acclient.c:883057
void __cdecl _E1241_3()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B3B0) --------------------------------------------------------  // acclient.c:883070
void __cdecl _E1244_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B3E0) --------------------------------------------------------  // acclient.c:883083
void __cdecl _E1247_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B410) --------------------------------------------------------  // acclient.c:883096
void __cdecl _E1250_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B440) --------------------------------------------------------  // acclient.c:883109
void __cdecl _E1253_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B470) --------------------------------------------------------  // acclient.c:883122
void __cdecl _E1256_3()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B4A0) --------------------------------------------------------  // acclient.c:883135
void __cdecl _E1259_3()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B4D0) --------------------------------------------------------  // acclient.c:883148
void __cdecl _E1262_3()
{
  char *v0; // esi@1

  v0 = &Position_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B500) --------------------------------------------------------  // acclient.c:883161
void __cdecl _E1265_3()
{
  char *v0; // esi@1

  v0 = &PointList_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B530) --------------------------------------------------------  // acclient.c:883174
void __cdecl _E1268_3()
{
  char *v0; // esi@1

  v0 = &Point_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B560) --------------------------------------------------------  // acclient.c:883187
void __cdecl _E1271_3()
{
  char *v0; // esi@1

  v0 = &DetailLevels_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B590) --------------------------------------------------------  // acclient.c:883200
void __cdecl _E1274_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B5C0) --------------------------------------------------------  // acclient.c:883213
void __cdecl _E1277_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B5F0) --------------------------------------------------------  // acclient.c:883226
void __cdecl _E1280_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B620) --------------------------------------------------------  // acclient.c:883239
void __cdecl _E1283_3()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B650) --------------------------------------------------------  // acclient.c:883252
void __cdecl _E1286_3()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B680) --------------------------------------------------------  // acclient.c:883265
void __cdecl _E1289_2()
{
  char *v0; // esi@1

  v0 = &Point_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B6B0) --------------------------------------------------------  // acclient.c:883278
void __cdecl _E1292_3()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B6E0) --------------------------------------------------------  // acclient.c:883291
void __cdecl _E1295_2()
{
  char *v0; // esi@1

  v0 = &PointTexture_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B710) --------------------------------------------------------  // acclient.c:883304
void __cdecl _E1298_2()
{
  char *v0; // esi@1

  v0 = &PointSize_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B740) --------------------------------------------------------  // acclient.c:883317
void __cdecl _E1301_2()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

