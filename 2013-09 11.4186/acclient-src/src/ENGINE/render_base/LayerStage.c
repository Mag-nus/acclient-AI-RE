/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LayerStage
   Object     : ENGINE\render_base\LayerStage.obj
   Functions  : 871
   Addresses  : 00447E00 - 00736380 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00447E00) --------------------------------------------------------  // acclient.c:132341
char __thiscall LayerStage::ReleaseSubObjects(LayerStage *this)
{
  Render::SafelyStopUsingAndReleaseTexture(&this->m_pTexture);
  return 1;
}

//----- (00447E10) --------------------------------------------------------  // acclient.c:132348
void __thiscall LayerStage::Begin(LayerStage *this)
{
  LayerStage *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10

  v1 = this;
  v2 = this->m_SamplerName.m_charbuffer;
  if ( this->m_SamplerName.m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_SamplerName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v5 = v1->m_TextureFileName.m_charbuffer;
  if ( v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_TextureFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  v1->m_TextureDID.id = INVALID_DID_36.id;
  v1->m_AddressModeU = 1;
  v1->m_AddressModeV = 1;
  v1->m_pTexture = 0;
  v1->m_SpecialTexture = 0;
  v1->m_FFColorArg2 = 0;
  v1->m_FFAlphaArg2 = 0;
  v1->m_FFTexCoordIndex = 0;
  v1->m_FFUseProjection = 0;
  v1->m_MinFilterMode = 2;
  v1->m_MagFilterMode = 2;
  v1->m_MipFilterMode = 2;
  v1->m_FFColorOp = 3;
  v1->m_FFColorArg1 = 2;
  v1->m_FFAlphaOp = 3;
  v1->m_FFAlphaArg1 = 2;
}

//----- (00447EE0) --------------------------------------------------------  // acclient.c:132398
char __thiscall LayerStage::CopyInto(LayerStage *this, const bool _IsInstance, LayerStage *target)
{
  LayerStage *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@2
  int v5; // ebx@3
  PSRefBufferCharData<char> *v6; // eax@6
  PSRefBufferCharData<char> *v7; // ebx@7
  int v8; // ebx@8
  PSRefBufferCharData<char> *v9; // eax@11
  RenderTexture *v10; // ecx@12
  DiskSpace *v11; // ecx@13

  v3 = this;
  if ( !_IsInstance )
  {
    v4 = target->m_SamplerName.m_charbuffer;
    if ( target->m_SamplerName.m_charbuffer != this->m_SamplerName.m_charbuffer )
    {
      v5 = (int)&v4[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = v3->m_SamplerName.m_charbuffer;
      target->m_SamplerName.m_charbuffer = v3->m_SamplerName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v6[-1]);
    }
    v7 = target->m_TextureFileName.m_charbuffer;
    if ( v7 != v3->m_TextureFileName.m_charbuffer )
    {
      v8 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = v3->m_TextureFileName.m_charbuffer;
      target->m_TextureFileName.m_charbuffer = v9;
      InterlockedIncrement((volatile LONG *)&v9[-1]);
    }
  }
  target->m_TextureDID.id = v3->m_TextureDID.id;
  target->m_pTexture = 0;
  v10 = v3->m_pTexture;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr->AddRef)();
    target->m_pTexture = v3->m_pTexture;
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v11);
  }
  target->m_SpecialTexture = v3->m_SpecialTexture;
  target->m_AddressModeU = v3->m_AddressModeU;
  target->m_AddressModeV = v3->m_AddressModeV;
  target->m_MinFilterMode = v3->m_MinFilterMode;
  target->m_MagFilterMode = v3->m_MagFilterMode;
  target->m_MipFilterMode = v3->m_MipFilterMode;
  target->m_FFColorOp = v3->m_FFColorOp;
  target->m_FFColorArg1 = v3->m_FFColorArg1;
  target->m_FFColorArg2 = v3->m_FFColorArg2;
  target->m_FFAlphaOp = v3->m_FFAlphaOp;
  target->m_FFAlphaArg1 = v3->m_FFAlphaArg1;
  target->m_FFAlphaArg2 = v3->m_FFAlphaArg2;
  target->m_FFTexCoordIndex = v3->m_FFTexCoordIndex;
  target->m_FFUseProjection = v3->m_FFUseProjection;
  return 1;
}

//----- (00447FE0) --------------------------------------------------------  // acclient.c:132461
char __thiscall LayerStage::SetTexture(LayerStage *this, PStringBase<char> *_TextureFileName, IDClass<_tagDataID,32,0> _TextureID)
{
  LayerStage *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // edi@2
  PSRefBufferCharData<char> *v6; // eax@5
  unsigned int v7; // ecx@6
  int v8; // edi@9
  QualifiedDataID *v9; // eax@10
  DiskSpace *v10; // ecx@10
  RenderTexture **v11; // esi@12
  QualifiedDataID v13; // [sp+Ch] [bp-8h]@10

  v3 = this;
  v4 = this->m_TextureFileName.m_charbuffer;
  if ( v4 != _TextureFileName->m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = _TextureFileName->m_charbuffer;
    v3->m_TextureFileName.m_charbuffer = _TextureFileName->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
  }
  v7 = v3->m_TextureDID.id;
  if ( v7 == _TextureID.id && (v7 == INVALID_DID_36.id || v3->m_pTexture) )
    return 1;
  v3->m_TextureDID.id = _TextureID.id;
  v8 = 0;
  if ( _TextureID.id == INVALID_DID_36.id )
  {
LABEL_12:
    v11 = &v3->m_pTexture;
    Render::SafelyStopUsingAndReleaseTexture(v11);
    if ( v8 )
      *v11 = (RenderTexture *)v8;
    return 1;
  }
  QualifiedDataID::QualifiedDataID(&v13, _TextureID, 0x1Eu);
  v8 = DBObj::Get(v9);
  if ( v8 )
  {
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v10);
    goto LABEL_12;
  }
  return 0;
}

//----- (004480A0) --------------------------------------------------------  // acclient.c:132510
char __thiscall LayerStage::SetTexture(LayerStage *this, RenderTexture *_pNewTexture)
{
  LayerStage *v2; // esi@1
  DiskSpace *v3; // ecx@2
  PSRefBufferCharData<char> *v4; // eax@4
  int v5; // ebx@5
  volatile LONG *v6; // ST00_4@8

  v2 = this;
  if ( _pNewTexture )
  {
    _pNewTexture->vfptr->AddRef((Interface *)_pNewTexture);
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v3);
    v2->m_TextureDID.id = _pNewTexture->m_DID.id;
  }
  else
  {
    this->m_TextureDID.id = INVALID_DID_36.id;
  }
  Render::SafelyStopUsingAndReleaseTexture(&v2->m_pTexture);
  v4 = v2->m_TextureFileName.m_charbuffer;
  if ( v4 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v2->m_TextureFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v6);
  }
  v2->m_pTexture = _pNewTexture;
  return 1;
}

//----- (00448130) --------------------------------------------------------  // acclient.c:132545
char __userpurge PFileNode::GetNameAsUInt32@<al>(PFileNode *this@<ecx>, int a2@<edi>, unsigned int *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 1 )
    {
      *o_name = (unsigned int)v7[1].vfptr;
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_UInt32::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *o_name = *((_DWORD *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (004481F0) --------------------------------------------------------  // acclient.c:132607
void __thiscall LayerStage::LayerStage(LayerStage *this)
{
  LayerStage *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_SamplerName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_TextureFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  LayerStage::Begin(v1);
}

//----- (00448230) --------------------------------------------------------  // acclient.c:132624
void __thiscall LayerStage::~LayerStage(LayerStage *this)
{
  LayerStage *v1; // edi@1
  int v2; // esi@1
  int v3; // edi@4

  v1 = this;
  Render::SafelyStopUsingAndReleaseTexture(&this->m_pTexture);
  LayerStage::Begin(v1);
  v2 = (int)&v1->m_TextureFileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_SamplerName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (00448290) --------------------------------------------------------  // acclient.c:132645
unsigned int __thiscall LayerStage::Copy(LayerStage *this, const bool _IsInstance)
{
  LayerStage *v2; // ebx@1
  void *v3; // esi@1
  volatile LONG *v4; // ST04_4@2
  volatile LONG *v5; // ST04_4@2
  unsigned int result; // eax@2

  v2 = this;
  v3 = operator new(0x48u);
  if ( v3 )
  {
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *(_DWORD *)v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
    v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *((_DWORD *)v3 + 1) = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v5);
    LayerStage::Begin((LayerStage *)v3);
    result = LayerStage::CopyInto(v2, _IsInstance, (LayerStage *)v3) != 0 ? (unsigned int)v3 : 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00448300) --------------------------------------------------------  // acclient.c:132674
char __thiscall LayerStage::GetSubObjects(LayerStage *this)
{
  LayerStage *v1; // esi@1
  PSRefBufferCharData<char> *v2; // edi@2
  char v3; // al@2
  int v4; // esi@2
  PStringBase<char> name; // [sp+0h] [bp-4h]@1

  name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  if ( this->m_TextureDID.id == INVALID_DID_36.id )
    return 1;
  name.m_charbuffer = this->m_TextureFileName.m_charbuffer;
  v2 = name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&name.m_charbuffer[-1]);
  v3 = LayerStage::SetTexture(v1, &name, v1->m_TextureDID);
  v4 = (int)&v2[-2].m_data[12];
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v2 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(&v2[-2].m_data[12], 1);
    return 1;
  }
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v2 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(&v2[-2].m_data[12], 1);
  return 0;
}

//----- (00448380) --------------------------------------------------------  // acclient.c:132703
void __thiscall LayerStage::Serialize(LayerStage *this, Archive *io_archive)
{
  LayerStage *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned __int8 v5; // bl@9
  unsigned int v6; // eax@9
  unsigned __int8 v7; // bl@15
  unsigned int v8; // eax@15
  unsigned __int8 v9; // bl@21
  unsigned int v10; // eax@21
  unsigned __int8 v11; // bl@27
  unsigned int v12; // eax@27
  unsigned __int8 v13; // bl@33
  unsigned int v14; // eax@33
  unsigned __int8 v15; // bl@39
  unsigned int v16; // eax@39
  unsigned int v17; // eax@45
  unsigned int v18; // eax@49
  unsigned __int8 v19; // bl@53
  unsigned int v20; // eax@53
  unsigned int v21; // eax@59
  unsigned int v22; // eax@63
  unsigned int v23; // eax@67

  v2 = this;
  PStringBase<char>::Serialize(&this->m_SamplerName, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_TextureDID.id;
    else
      v2->m_TextureDID.id = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_SpecialTexture;
    else
      v2->m_SpecialTexture = *(_DWORD *)v4;
  }
  v5 = LOBYTE(v2->m_AddressModeU);
  Archive::CheckAlignment(io_archive, 1u);
  v6 = Archive::GetBytes(io_archive, 1u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v6 = v5;
    else
      v5 = *(_BYTE *)v6;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_AddressModeU = v5;
  v7 = LOBYTE(v2->m_AddressModeV);
  Archive::CheckAlignment(io_archive, 1u);
  v8 = Archive::GetBytes(io_archive, 1u);
  if ( v8 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      v7 = *(_BYTE *)v8;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_AddressModeV = v7;
  v9 = LOBYTE(v2->m_MinFilterMode);
  Archive::CheckAlignment(io_archive, 1u);
  v10 = Archive::GetBytes(io_archive, 1u);
  if ( v10 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v10 = v9;
    else
      v9 = *(_BYTE *)v10;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_MinFilterMode = v9;
  v11 = LOBYTE(v2->m_MagFilterMode);
  Archive::CheckAlignment(io_archive, 1u);
  v12 = Archive::GetBytes(io_archive, 1u);
  if ( v12 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v12 = v11;
    else
      v11 = *(_BYTE *)v12;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_MagFilterMode = v11;
  v13 = LOBYTE(v2->m_MipFilterMode);
  Archive::CheckAlignment(io_archive, 1u);
  v14 = Archive::GetBytes(io_archive, 1u);
  if ( v14 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v14 = v13;
    else
      v13 = *(_BYTE *)v14;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_MipFilterMode = v13;
  v15 = LOBYTE(v2->m_FFColorOp);
  Archive::CheckAlignment(io_archive, 1u);
  v16 = Archive::GetBytes(io_archive, 1u);
  if ( v16 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v16 = v15;
    else
      v15 = *(_BYTE *)v16;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_FFColorOp = v15;
  Archive::CheckAlignment(io_archive, 4u);
  v17 = Archive::GetBytes(io_archive, 4u);
  if ( v17 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v17 = v2->m_FFColorArg1;
    else
      v2->m_FFColorArg1 = *(_DWORD *)v17;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v18 = Archive::GetBytes(io_archive, 4u);
  if ( v18 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v18 = v2->m_FFColorArg2;
    else
      v2->m_FFColorArg2 = *(_DWORD *)v18;
  }
  v19 = LOBYTE(v2->m_FFAlphaOp);
  Archive::CheckAlignment(io_archive, 1u);
  v20 = Archive::GetBytes(io_archive, 1u);
  if ( v20 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v20 = v19;
    else
      v19 = *(_BYTE *)v20;
  }
  if ( !(io_archive->m_flags & 5) )
    v2->m_FFAlphaOp = v19;
  Archive::CheckAlignment(io_archive, 4u);
  v21 = Archive::GetBytes(io_archive, 4u);
  if ( v21 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v21 = v2->m_FFAlphaArg1;
    else
      v2->m_FFAlphaArg1 = *(_DWORD *)v21;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v22 = Archive::GetBytes(io_archive, 4u);
  if ( v22 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v22 = v2->m_FFAlphaArg2;
    else
      v2->m_FFAlphaArg2 = *(_DWORD *)v22;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v23 = Archive::GetBytes(io_archive, 4u);
  if ( v23 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v23 = v2->m_FFTexCoordIndex;
      Serializer::SerializeObject(&v2->m_FFUseProjection, io_archive);
      return;
    }
    v2->m_FFTexCoordIndex = *(_DWORD *)v23;
  }
  Serializer::SerializeObject(&v2->m_FFUseProjection, io_archive);
}

//----- (006CC420) --------------------------------------------------------  // acclient.c:739654
void _E73_40()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_15, PFID_A8R8G8B8);
}

//----- (006CC430) --------------------------------------------------------  // acclient.c:739660
void _E91_17()
{
  LODWORD(dword_838A6C) = 1053364187;
}

//----- (006CC440) --------------------------------------------------------  // acclient.c:739666
void _E93_5()
{
  outside_val_12 = 1000.0 + 1.0;
}

//----- (006CC460) --------------------------------------------------------  // acclient.c:739672
void _E95_5()
{
  block_length_12 = 24.0 * 8.0;
}

//----- (006CC480) --------------------------------------------------------  // acclient.c:739678
void _E97_16()
{
  half_square_length_12 = 24.0 * 0.5;
}

//----- (006CC4A0) --------------------------------------------------------  // acclient.c:739684
int _E99_1()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_7, "Render.TextureFiltering");
  return atexit(sub_735D80);
}

//----- (006CC4C0) --------------------------------------------------------  // acclient.c:739691
int _E102_5()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_7, "Render.LandscapeDetailTextures");
  return atexit(sub_735DB0);
}

//----- (006CC4E0) --------------------------------------------------------  // acclient.c:739698
int _E105_1()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_7, "Render.BuildingDetailTextures");
  return atexit(sub_735DE0);
}

//----- (006CC500) --------------------------------------------------------  // acclient.c:739705
int _E108_4()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_7, "Render.FieldOfView");
  return atexit(sub_735E10);
}

//----- (006CC520) --------------------------------------------------------  // acclient.c:739712
int _E111_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_7, "Render.LandscapeTextureDetail");
  return atexit(sub_735E40);
}

//----- (006CC540) --------------------------------------------------------  // acclient.c:739719
int _E114_4()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_7, "Render.EnvironmentTextureDetail");
  return atexit(sub_735E70);
}

//----- (006CC560) --------------------------------------------------------  // acclient.c:739726
int _E117_2()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_7, "Render.SceneryDrawDistance");
  return atexit(sub_735EA0);
}

//----- (006CC580) --------------------------------------------------------  // acclient.c:739733
int _E120_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_7, "Render.LandscapeDrawDistance");
  return atexit(sub_735ED0);
}

//----- (006CC5A0) --------------------------------------------------------  // acclient.c:739740
int _E123_2()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_7, "Render.ScreenBrightness");
  return atexit(_E124_96);
}

//----- (006CC5C0) --------------------------------------------------------  // acclient.c:739747
int _E126_5()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_7, "Render.AspectRatio");
  return atexit(_E127_86);
}

//----- (006CC5E0) --------------------------------------------------------  // acclient.c:739754
int _E129_4()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_7, "Render.DisplayAdapter");
  return atexit(_E130_78);
}

//----- (006CC600) --------------------------------------------------------  // acclient.c:739761
int _E132_5()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_7, "Render.MaxHardwareClass");
  return atexit(_E133_71);
}

//----- (006CC620) --------------------------------------------------------  // acclient.c:739768
int _E135_4()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_7, "Render.AutomaticDegrades");
  return atexit(_E136_55);
}

//----- (006CC640) --------------------------------------------------------  // acclient.c:739775
int _E138_5()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_7, "Render.GraphicsPerformance");
  return atexit(_E139_56);
}

//----- (006CC660) --------------------------------------------------------  // acclient.c:739782
int _E141_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_7, "Render.DegradeDistance");
  return atexit(_E142_53);
}

//----- (006CC680) --------------------------------------------------------  // acclient.c:739789
int _E144_5()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_7, "Render.MultiPassAlpha");
  return atexit(_E145_55);
}

//----- (006CC6A0) --------------------------------------------------------  // acclient.c:739796
int _E147_5()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_7, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_838AC4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_838AC8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_838ACC, "Anisotropic");
  return atexit(_E148_54);
}

//----- (006CC6F0) --------------------------------------------------------  // acclient.c:739806
int _E150_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_7, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_838AD4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_838AD8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_838ADC, "High");
  PStringBase<char>::PStringBase<char>(&stru_838AE0, "VeryHigh");
  return atexit(_E151_52);
}

//----- (006CC750) --------------------------------------------------------  // acclient.c:739817
int _E153_5()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_7, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_838AE8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_838AEC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_838AF0, "High");
  PStringBase<char>::PStringBase<char>(&stru_838AF4, "VeryHigh");
  return atexit(_E154_53);
}

//----- (006CC7B0) --------------------------------------------------------  // acclient.c:739828
int _E156_6()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_7, "Low");
  PStringBase<char>::PStringBase<char>(&stru_838AFC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_838B00, "High");
  return atexit(_E157_50);
}

//----- (006CC7F0) --------------------------------------------------------  // acclient.c:739837
int _E159_5()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_7, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_838B08, "Low");
  PStringBase<char>::PStringBase<char>(&stru_838B0C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_838B10, "High");
  PStringBase<char>::PStringBase<char>(&stru_838B14, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_838B18, "Extreme");
  return atexit(_E160_53);
}

//----- (006CC860) --------------------------------------------------------  // acclient.c:739849
int _E162_6()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_7, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_838B20, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_838B24, "Wide");
  return atexit(_E163_46);
}

//----- (006CC8A0) --------------------------------------------------------  // acclient.c:739858
int _E165_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_13, "None");
  return atexit(_E166_48);
}

//----- (006CC8C0) --------------------------------------------------------  // acclient.c:739865
int _E168_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_13, "Speed");
  return atexit(_E169_47);
}

//----- (006CC8E0) --------------------------------------------------------  // acclient.c:739872
int _E171_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_13, "Noise");
  return atexit(_E172_45);
}

//----- (006CC900) --------------------------------------------------------  // acclient.c:739879
int _E174_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_13, "Sine");
  return atexit(_E175_42);
}

//----- (006CC920) --------------------------------------------------------  // acclient.c:739886
int _E177_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_13, "Square");
  return atexit(_E178_42);
}

//----- (006CC940) --------------------------------------------------------  // acclient.c:739893
int _E180_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_13, "Bounce");
  return atexit(_E181_42);
}

//----- (006CC960) --------------------------------------------------------  // acclient.c:739900
int _E183_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_13, "Perlin");
  return atexit(_E184_40);
}

//----- (006CC980) --------------------------------------------------------  // acclient.c:739907
int _E186_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_13, "Fractal");
  return atexit(_E187_39);
}

//----- (006CC9A0) --------------------------------------------------------  // acclient.c:739914
int _E189_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_13, "FrameLoop");
  return atexit(_E190_40);
}

//----- (006CC9C0) --------------------------------------------------------  // acclient.c:739921
int _E192_5()
{
  PStringBase<char>::PStringBase<char>(&PHeader_0, "PREPROC_HEADER");
  return atexit(_E193_36);
}

//----- (006CC9E0) --------------------------------------------------------  // acclient.c:739928
int _E195_3()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_0, "VertexArray");
  return atexit(_E196_44);
}

//----- (006CCA00) --------------------------------------------------------  // acclient.c:739935
int _E198_4()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_0, "BinaryVertexArray");
  return atexit(_E199_36);
}

//----- (006CCA20) --------------------------------------------------------  // acclient.c:739942
int _E201_2()
{
  PStringBase<char>::PStringBase<char>(&VertexType_1, "VertexType");
  return atexit(_E202_37);
}

//----- (006CCA40) --------------------------------------------------------  // acclient.c:739949
int _E204_1()
{
  PStringBase<char>::PStringBase<char>(&VertexData_0, "VertexData");
  return atexit(_E205_34);
}

//----- (006CCA60) --------------------------------------------------------  // acclient.c:739956
int _E207_0()
{
  PStringBase<char>::PStringBase<char>(&Vertex_0, "Vertex");
  return atexit(_E208_38);
}

//----- (006CCA80) --------------------------------------------------------  // acclient.c:739963
int _E210_1()
{
  PStringBase<char>::PStringBase<char>(&Index_1, "Index");
  return atexit(_E211_34);
}

//----- (006CCAA0) --------------------------------------------------------  // acclient.c:739970
int _E213_2()
{
  PStringBase<char>::PStringBase<char>(&Origin_1, "P");
  return atexit(_E214_37);
}

//----- (006CCAC0) --------------------------------------------------------  // acclient.c:739977
int _E216_2()
{
  PStringBase<char>::PStringBase<char>(&Normal_0, "N");
  return atexit(_E217_33);
}

//----- (006CCAE0) --------------------------------------------------------  // acclient.c:739984
int _E219_0()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_1, "Diffuse");
  return atexit(_E220_33);
}

//----- (006CCB00) --------------------------------------------------------  // acclient.c:739991
int _E222_0()
{
  PStringBase<char>::PStringBase<char>(&Specular_1, "Specular");
  return atexit(_E223_33);
}

//----- (006CCB20) --------------------------------------------------------  // acclient.c:739998
int _E225_0()
{
  PStringBase<char>::PStringBase<char>(&UVS_0, "UVS");
  return atexit(_E226_19);
}

//----- (006CCB40) --------------------------------------------------------  // acclient.c:740005
int _E228_0()
{
  PStringBase<char>::PStringBase<char>(&VectorS_0, "VectorS");
  return atexit(_E229_19);
}

//----- (006CCB60) --------------------------------------------------------  // acclient.c:740012
int _E231_0()
{
  PStringBase<char>::PStringBase<char>(&VectorT_0, "VectorT");
  return atexit(_E232_19);
}

//----- (006CCB80) --------------------------------------------------------  // acclient.c:740019
int _E234_0()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_0, "VectorSxT");
  return atexit(_E235_19);
}

//----- (006CCBA0) --------------------------------------------------------  // acclient.c:740026
int _E237_0()
{
  PStringBase<char>::PStringBase<char>(&Weights_0, "Weights");
  return atexit(_E238_17);
}

//----- (006CCBC0) --------------------------------------------------------  // acclient.c:740033
int _E240_0()
{
  PStringBase<char>::PStringBase<char>(&Importance_0, "Importance");
  return atexit(_E241_17);
}

//----- (006CCBE0) --------------------------------------------------------  // acclient.c:740040
int _E243_0()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_0, "PhysMtl");
  return atexit(_E244_17);
}

//----- (006CCC00) --------------------------------------------------------  // acclient.c:740047
int _E246_0()
{
  PStringBase<char>::PStringBase<char>(&Material_4, "Material");
  return atexit(_E247_16);
}

//----- (006CCC20) --------------------------------------------------------  // acclient.c:740054
int _E249_0()
{
  PStringBase<char>::PStringBase<char>(&ID_2, "ID");
  return atexit(_E250_16);
}

//----- (006CCC40) --------------------------------------------------------  // acclient.c:740061
int _E252_0()
{
  PStringBase<char>::PStringBase<char>(&FileName_0, "FileName");
  return atexit(_E253_16);
}

//----- (006CCC60) --------------------------------------------------------  // acclient.c:740068
int _E255_0()
{
  PStringBase<char>::PStringBase<char>(&Polygon_1, "Polygon");
  return atexit(_E256_16);
}

//----- (006CCC80) --------------------------------------------------------  // acclient.c:740075
int _E258_0()
{
  PStringBase<char>::PStringBase<char>(&ID_3, "ID");
  return atexit(_E259_17);
}

//----- (006CCCA0) --------------------------------------------------------  // acclient.c:740082
int _E261_0()
{
  PStringBase<char>::PStringBase<char>(&Indices_2, "INDICES");
  return atexit(_E262_17);
}

//----- (006CCCC0) --------------------------------------------------------  // acclient.c:740089
int _E264_0()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_0, "MaterialID");
  return atexit(_E265_17);
}

//----- (006CCCE0) --------------------------------------------------------  // acclient.c:740096
int _E267_0()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_0, "PhysMaterialID");
  return atexit(_E268_16);
}

//----- (006CCD00) --------------------------------------------------------  // acclient.c:740103
int _E270_0()
{
  PStringBase<char>::PStringBase<char>(&Markings_0, "Markings");
  return atexit(_E271_15);
}

//----- (006CCD20) --------------------------------------------------------  // acclient.c:740110
int _E273_0()
{
  PStringBase<char>::PStringBase<char>(&Material_5, "Material");
  return atexit(_E274_15);
}

//----- (006CCD40) --------------------------------------------------------  // acclient.c:740117
int _E276_0()
{
  PStringBase<char>::PStringBase<char>(&Index_2, "Index");
  return atexit(_E277_15);
}

//----- (006CCD60) --------------------------------------------------------  // acclient.c:740124
int _E279_0()
{
  PStringBase<char>::PStringBase<char>(&Filename_0, "Filename");
  return atexit(_E280_14);
}

//----- (006CCD80) --------------------------------------------------------  // acclient.c:740131
int _E282_0()
{
  PStringBase<char>::PStringBase<char>(&Surface_0, "Surface");
  return atexit(_E283_14);
}

//----- (006CCDA0) --------------------------------------------------------  // acclient.c:740138
int _E285_0()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_0, "CellPoly");
  return atexit(_E286_13);
}

//----- (006CCDC0) --------------------------------------------------------  // acclient.c:740145
int _E288_0()
{
  PStringBase<char>::PStringBase<char>(&Sphere_1, "Sphere");
  return atexit(_E289_12);
}

//----- (006CCDE0) --------------------------------------------------------  // acclient.c:740152
int _E291_0()
{
  PStringBase<char>::PStringBase<char>(&Side_0, "Side");
  return atexit(_E292_13);
}

//----- (006CCE00) --------------------------------------------------------  // acclient.c:740159
int _E294_0()
{
  PStringBase<char>::PStringBase<char>(&Positive_0, "Positive");
  return atexit(_E295_12);
}

//----- (006CCE20) --------------------------------------------------------  // acclient.c:740166
int _E297_0()
{
  PStringBase<char>::PStringBase<char>(&Negative_0, "Negative");
  return atexit(_E298_13);
}

//----- (006CCE40) --------------------------------------------------------  // acclient.c:740173
int _E300_0()
{
  PStringBase<char>::PStringBase<char>(&Polygon_2, "PolygonIndex");
  return atexit(_E301_11);
}

//----- (006CCE60) --------------------------------------------------------  // acclient.c:740180
int _E303_0()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_1, "OtherCellMeshIndex");
  return atexit(_E304_12);
}

//----- (006CCE80) --------------------------------------------------------  // acclient.c:740187
int _E306_0()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_0, "CellPortal");
  return atexit(_E307_11);
}

//----- (006CCEA0) --------------------------------------------------------  // acclient.c:740194
int _E309_0()
{
  PStringBase<char>::PStringBase<char>(&Portal_1, "PortalIndex");
  return atexit(_E310_12);
}

//----- (006CCEC0) --------------------------------------------------------  // acclient.c:740201
int _E312_0()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_2, "OtherCellID");
  return atexit(_E313_11);
}

//----- (006CCEE0) --------------------------------------------------------  // acclient.c:740208
int _E315_0()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_0, "OtherPortalIndex");
  return atexit(_E316_12);
}

//----- (006CCF00) --------------------------------------------------------  // acclient.c:740215
int _E318_0()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_0, "ExactMatch");
  return atexit(_E319_11);
}

//----- (006CCF20) --------------------------------------------------------  // acclient.c:740222
int _E321_0()
{
  PStringBase<char>::PStringBase<char>(&StabList_0, "StabList");
  return atexit(_E322_11);
}

//----- (006CCF40) --------------------------------------------------------  // acclient.c:740229
int _E324_0()
{
  PStringBase<char>::PStringBase<char>(&Period_0, "Period");
  return atexit(_E325_10);
}

//----- (006CCF60) --------------------------------------------------------  // acclient.c:740236
int _E327_0()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_0, "GrannyAnimation");
  return atexit(_E328_11);
}

//----- (006CCF80) --------------------------------------------------------  // acclient.c:740243
int _E330_0()
{
  PStringBase<char>::PStringBase<char>(&Transform_0, "Transform");
  return atexit(_E331_10);
}

//----- (006CCFA0) --------------------------------------------------------  // acclient.c:740250
int _E333_0()
{
  PStringBase<char>::PStringBase<char>(&Scale_2, "Scale");
  return atexit(_E334_10);
}

//----- (006CCFC0) --------------------------------------------------------  // acclient.c:740257
int _E336_0()
{
  PStringBase<char>::PStringBase<char>(&Weight_0, "Weight");
  return atexit(_E337_10);
}

//----- (006CCFE0) --------------------------------------------------------  // acclient.c:740264
int _E339_0()
{
  PStringBase<char>::PStringBase<char>(&Offset_0, "Offset");
  return atexit(_E340_10);
}

//----- (006CD000) --------------------------------------------------------  // acclient.c:740271
int _E342_0()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_1, "Quaternion");
  return atexit(_E343_7);
}

//----- (006CD020) --------------------------------------------------------  // acclient.c:740278
int _E345_0()
{
  PStringBase<char>::PStringBase<char>(&Rotation_1, "Rotation");
  return atexit(_E346_7);
}

//----- (006CD040) --------------------------------------------------------  // acclient.c:740285
int _E348_0()
{
  PStringBase<char>::PStringBase<char>(&STime_0, "STime");
  return atexit(_E349_7);
}

//----- (006CD060) --------------------------------------------------------  // acclient.c:740292
int _E351_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_0, "PhysicsSplines");
  return atexit(_E352_7);
}

//----- (006CD080) --------------------------------------------------------  // acclient.c:740299
int _E354_0()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_0, "BoneOpacities");
  return atexit(_E355_7);
}

//----- (006CD0A0) --------------------------------------------------------  // acclient.c:740306
int _E357_0()
{
  PStringBase<char>::PStringBase<char>(&LowPt_0, "LowPoint");
  return atexit(_E358_7);
}

//----- (006CD0C0) --------------------------------------------------------  // acclient.c:740313
int _E360_0()
{
  PStringBase<char>::PStringBase<char>(&Radius_0, "Radius");
  return atexit(_E361_7);
}

//----- (006CD0E0) --------------------------------------------------------  // acclient.c:740320
int _E363_0()
{
  PStringBase<char>::PStringBase<char>(&Height_0, "Height");
  return atexit(_E364_7);
}

//----- (006CD100) --------------------------------------------------------  // acclient.c:740327
int _E366_0()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_0, "Texture2D");
  return atexit(_E367_7);
}

//----- (006CD120) --------------------------------------------------------  // acclient.c:740334
int _E369_0()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_0, "Texture3D");
  return atexit(_E370_7);
}

//----- (006CD140) --------------------------------------------------------  // acclient.c:740341
int _E372_0()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_0, "TextureCube");
  return atexit(_E373_7);
}

//----- (006CD160) --------------------------------------------------------  // acclient.c:740348
int _E375_0()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_0, "TextureMovie2D");
  return atexit(_E376_7);
}

//----- (006CD180) --------------------------------------------------------  // acclient.c:740355
int _E378_0()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_0, "MovieFile");
  return atexit(_E379_7);
}

//----- (006CD1A0) --------------------------------------------------------  // acclient.c:740362
int _E381_0()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_0, "MovieFPS");
  return atexit(_E382_7);
}

//----- (006CD1C0) --------------------------------------------------------  // acclient.c:740369
int _E384_0()
{
  PStringBase<char>::PStringBase<char>(&Levels_0, "Levels");
  return atexit(_E385_7);
}

//----- (006CD1E0) --------------------------------------------------------  // acclient.c:740376
int _E387_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_9, "Instance");
  return atexit(_E388_7);
}

//----- (006CD200) --------------------------------------------------------  // acclient.c:740383
int _E390_0()
{
  PStringBase<char>::PStringBase<char>(&Material_6, "Material");
  return atexit(_E391_7);
}

//----- (006CD220) --------------------------------------------------------  // acclient.c:740390
int _E393_0()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_0, "MaterialType");
  return atexit(_E394_7);
}

//----- (006CD240) --------------------------------------------------------  // acclient.c:740397
int _E396_0()
{
  PStringBase<char>::PStringBase<char>(&Modifier_0, "Modifier");
  return atexit(_E397_7);
}

//----- (006CD260) --------------------------------------------------------  // acclient.c:740404
int _E399_0()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_0, "AllowStencilShadows");
  return atexit(_E400_7);
}

//----- (006CD280) --------------------------------------------------------  // acclient.c:740411
int _E402_0()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_0, "DiscardGeometry");
  return atexit(_E403_7);
}

//----- (006CD2A0) --------------------------------------------------------  // acclient.c:740418
int _E405_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_10, "Material");
  return atexit(_E406_7);
}

//----- (006CD2C0) --------------------------------------------------------  // acclient.c:740425
int _E408_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_0, "SortMode");
  return atexit(_E409_7);
}

//----- (006CD2E0) --------------------------------------------------------  // acclient.c:740432
int _E411_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_0, "None");
  return atexit(_E412_7);
}

//----- (006CD300) --------------------------------------------------------  // acclient.c:740439
int _E414_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_0, "Triangle");
  return atexit(_E415_7);
}

//----- (006CD320) --------------------------------------------------------  // acclient.c:740446
int _E417_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_11, "Modifier");
  return atexit(_E418_7);
}

//----- (006CD340) --------------------------------------------------------  // acclient.c:740453
int _E420_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_12, "Property");
  return atexit(_E421_7);
}

//----- (006CD360) --------------------------------------------------------  // acclient.c:740460
int _E423_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_0, "Data");
  return atexit(_E424_7);
}

//----- (006CD380) --------------------------------------------------------  // acclient.c:740467
int _E426_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_0, "Waveform");
  return atexit(_E427_7);
}

//----- (006CD3A0) --------------------------------------------------------  // acclient.c:740474
int _E429_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_0, "Color");
  return atexit(_E430_7);
}

//----- (006CD3C0) --------------------------------------------------------  // acclient.c:740481
int _E432_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_0, "Texture");
  return atexit(_E433_7);
}

//----- (006CD3E0) --------------------------------------------------------  // acclient.c:740488
int _E435_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_0, "Bool");
  return atexit(_E436_7);
}

//----- (006CD400) --------------------------------------------------------  // acclient.c:740495
int _E438_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_13, "Layer");
  return atexit(_E439_7);
}

//----- (006CD420) --------------------------------------------------------  // acclient.c:740502
int _E441_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_0, "UVTranslate");
  return atexit(_E442_7);
}

//----- (006CD440) --------------------------------------------------------  // acclient.c:740509
int _E444_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_0, "UVRotate");
  return atexit(_E445_7);
}

//----- (006CD460) --------------------------------------------------------  // acclient.c:740516
int _E447_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_0, "UVScale");
  return atexit(_E448_7);
}

//----- (006CD480) --------------------------------------------------------  // acclient.c:740523
int _E450_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_0, "UVTransform");
  return atexit(_E451_7);
}

//----- (006CD4A0) --------------------------------------------------------  // acclient.c:740530
int _E453_0()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_0, "TrueFlags");
  return atexit(_E454_7);
}

//----- (006CD4C0) --------------------------------------------------------  // acclient.c:740537
int _E456_0()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_0, "FalseFlags");
  return atexit(_E457_7);
}

//----- (006CD4E0) --------------------------------------------------------  // acclient.c:740544
int _E459_0()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_0, "RenderPass");
  return atexit(_E460_7);
}

//----- (006CD500) --------------------------------------------------------  // acclient.c:740551
int _E462_0()
{
  PStringBase<char>::PStringBase<char>(&Blend_0, "Blend");
  return atexit(_E463_7);
}

//----- (006CD520) --------------------------------------------------------  // acclient.c:740558
int _E465_0()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_0, "DepthTest");
  return atexit(_E466_7);
}

//----- (006CD540) --------------------------------------------------------  // acclient.c:740565
int _E468_0()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_0, "DepthWrite");
  return atexit(_E469_7);
}

//----- (006CD560) --------------------------------------------------------  // acclient.c:740572
int _E471_0()
{
  PStringBase<char>::PStringBase<char>(&CullMode_0, "CullMode");
  return atexit(_E472_7);
}

//----- (006CD580) --------------------------------------------------------  // acclient.c:740579
int _E474_0()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_0, "DepthFog");
  return atexit(_E475_7);
}

//----- (006CD5A0) --------------------------------------------------------  // acclient.c:740586
int _E477_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_0, "AlphaTestMode");
  return atexit(_E478_7);
}

//----- (006CD5C0) --------------------------------------------------------  // acclient.c:740593
int _E480_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_0, "AlphaTestRef");
  return atexit(_E481_7);
}

//----- (006CD5E0) --------------------------------------------------------  // acclient.c:740600
int _E483_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_0, "FFUseLighting");
  return atexit(_E484_7);
}

//----- (006CD600) --------------------------------------------------------  // acclient.c:740607
int _E486_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_0, "FFUseDyeColorInTFactor");
  return atexit(_E487_7);
}

//----- (006CD620) --------------------------------------------------------  // acclient.c:740614
int _E489_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_0, "FFUseSpecularLighting");
  return atexit(_E490_7);
}

//----- (006CD640) --------------------------------------------------------  // acclient.c:740621
int _E492_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_0, "FFUseDistanceFog");
  return atexit(_E493_7);
}

//----- (006CD660) --------------------------------------------------------  // acclient.c:740628
int _E495_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_0, "FFUseVertexDiffuse");
  return atexit(_E496_7);
}

//----- (006CD680) --------------------------------------------------------  // acclient.c:740635
int _E498_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_0, "FFUseVertexSpecular");
  return atexit(_E499_7);
}

//----- (006CD6A0) --------------------------------------------------------  // acclient.c:740642
int _E501_0()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_0, "ShaderSupportsDynamicLights");
  return atexit(_E502_7);
}

//----- (006CD6C0) --------------------------------------------------------  // acclient.c:740649
int _E504_0()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_0, "UsesTransparency");
  return atexit(_E505_7);
}

//----- (006CD6E0) --------------------------------------------------------  // acclient.c:740656
int _E507_0()
{
  PStringBase<char>::PStringBase<char>(&Ambient_0, "Ambient");
  return atexit(_E508_7);
}

//----- (006CD700) --------------------------------------------------------  // acclient.c:740663
int _E510_0()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_2, "Diffuse");
  return atexit(_E511_7);
}

//----- (006CD720) --------------------------------------------------------  // acclient.c:740670
int _E513_0()
{
  PStringBase<char>::PStringBase<char>(&Specular_2, "Specular");
  return atexit(_E514_7);
}

//----- (006CD740) --------------------------------------------------------  // acclient.c:740677
int _E516_0()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_0, "SpecularPower");
  return atexit(_E517_7);
}

//----- (006CD760) --------------------------------------------------------  // acclient.c:740684
int _E519_0()
{
  PStringBase<char>::PStringBase<char>(&Dye_0, "Dye");
  return atexit(_E520_7);
}

//----- (006CD780) --------------------------------------------------------  // acclient.c:740691
int _E522_0()
{
  PStringBase<char>::PStringBase<char>(&Emissive_0, "Emissive");
  return atexit(_E523_7);
}

//----- (006CD7A0) --------------------------------------------------------  // acclient.c:740698
int _E525_0()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_0, "VertexFormat");
  return atexit(_E526_7);
}

//----- (006CD7C0) --------------------------------------------------------  // acclient.c:740705
int _E528_0()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_0, "VertexShader");
  return atexit(_E529_7);
}

//----- (006CD7E0) --------------------------------------------------------  // acclient.c:740712
int _E531_0()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_0, "PixelShader");
  return atexit(_E532_7);
}

//----- (006CD800) --------------------------------------------------------  // acclient.c:740719
int _E534_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_0, "None");
  return atexit(_E535_7);
}

//----- (006CD820) --------------------------------------------------------  // acclient.c:740726
int _E537_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_0, "Reflections");
  return atexit(_E538_7);
}

//----- (006CD840) --------------------------------------------------------  // acclient.c:740733
int _E540_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_0, "VideoPost");
  return atexit(_E541_7);
}

//----- (006CD860) --------------------------------------------------------  // acclient.c:740740
int _E543_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_0, "HighDetail");
  return atexit(_E544_7);
}

//----- (006CD880) --------------------------------------------------------  // acclient.c:740747
int _E546_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_0, "Specular");
  return atexit(_E547_7);
}

//----- (006CD8A0) --------------------------------------------------------  // acclient.c:740754
int _E549_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_0, "Class1");
  return atexit(_E550_7);
}

//----- (006CD8C0) --------------------------------------------------------  // acclient.c:740761
int _E552_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_0, "Class2");
  return atexit(_E553_7);
}

//----- (006CD8E0) --------------------------------------------------------  // acclient.c:740768
int _E555_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_0, "Class3");
  return atexit(_E556_7);
}

//----- (006CD900) --------------------------------------------------------  // acclient.c:740775
int _E558_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_0, "Default");
  return atexit(_E559_7);
}

//----- (006CD920) --------------------------------------------------------  // acclient.c:740782
int _E561_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_0,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E562_7);
}

//----- (006CD940) --------------------------------------------------------  // acclient.c:740791
int _E564_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_0, "PointLightDiffuseAndSpecular");
  return atexit(_E565_7);
}

//----- (006CD960) --------------------------------------------------------  // acclient.c:740798
int _E567_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_0,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E568_7);
}

//----- (006CD980) --------------------------------------------------------  // acclient.c:740807
int _E570_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_0,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E571_7);
}

//----- (006CD9A0) --------------------------------------------------------  // acclient.c:740816
int _E573_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_0,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E574_7);
}

//----- (006CD9C0) --------------------------------------------------------  // acclient.c:740825
int _E576_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_0, "DistanceFog");
  return atexit(_E577_7);
}

//----- (006CD9E0) --------------------------------------------------------  // acclient.c:740832
int _E579_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_0, "FFGlow");
  return atexit(_E580_7);
}

//----- (006CDA00) --------------------------------------------------------  // acclient.c:740839
int _E582_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_0, "ShaderGlow");
  return atexit(_E583_7);
}

//----- (006CDA20) --------------------------------------------------------  // acclient.c:740846
int _E585_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_0, "LandscapeShadowMap");
  return atexit(_E586_7);
}

//----- (006CDA40) --------------------------------------------------------  // acclient.c:740853
int _E588_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_0, "AlphaBlend");
  return atexit(_E589_7);
}

//----- (006CDA60) --------------------------------------------------------  // acclient.c:740860
int _E591_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_0, "AL_0DL_0PL");
  return atexit(_E592_7);
}

//----- (006CDA80) --------------------------------------------------------  // acclient.c:740867
int _E594_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_0, "AL_0DL_1PL");
  return atexit(_E595_7);
}

//----- (006CDAA0) --------------------------------------------------------  // acclient.c:740874
int _E597_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_0, "AL_0DL_2PL");
  return atexit(_E598_7);
}

//----- (006CDAC0) --------------------------------------------------------  // acclient.c:740881
int _E600_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_0, "AL_0DL_3PL");
  return atexit(_E601_7);
}

//----- (006CDAE0) --------------------------------------------------------  // acclient.c:740888
int _E603_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_0, "AL_0DL_4PL");
  return atexit(_E604_7);
}

//----- (006CDB00) --------------------------------------------------------  // acclient.c:740895
int _E606_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_0, "AL_0DL_5PL");
  return atexit(_E607_7);
}

//----- (006CDB20) --------------------------------------------------------  // acclient.c:740902
int _E609_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_0, "AL_0DL_6PL");
  return atexit(_E610_7);
}

//----- (006CDB40) --------------------------------------------------------  // acclient.c:740909
int _E612_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_0, "AL_0DL_7PL");
  return atexit(_E613_7);
}

//----- (006CDB60) --------------------------------------------------------  // acclient.c:740916
int _E615_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_0, "AL_0DL_8PL");
  return atexit(_E616_7);
}

//----- (006CDB80) --------------------------------------------------------  // acclient.c:740923
int _E618_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_0, "AL_1DL_0PL");
  return atexit(_E619_7);
}

//----- (006CDBA0) --------------------------------------------------------  // acclient.c:740930
int _E621_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_0, "AL_1DL_1PL");
  return atexit(_E622_7);
}

//----- (006CDBC0) --------------------------------------------------------  // acclient.c:740937
int _E624_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_0, "AL_1DL_2PL");
  return atexit(_E625_7);
}

//----- (006CDBE0) --------------------------------------------------------  // acclient.c:740944
int _E627_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_0, "AL_1DL_3PL");
  return atexit(_E628_7);
}

//----- (006CDC00) --------------------------------------------------------  // acclient.c:740951
int _E630_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_0, "AL_1DL_4PL");
  return atexit(_E631_7);
}

//----- (006CDC20) --------------------------------------------------------  // acclient.c:740958
int _E633_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_0, "AL_1DL_5PL");
  return atexit(_E634_7);
}

//----- (006CDC40) --------------------------------------------------------  // acclient.c:740965
int _E636_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_0, "AL_1DL_6PL");
  return atexit(_E637_7);
}

//----- (006CDC60) --------------------------------------------------------  // acclient.c:740972
int _E639_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_0, "AL_1DL_7PL");
  return atexit(_E640_7);
}

//----- (006CDC80) --------------------------------------------------------  // acclient.c:740979
int _E642_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_0, "AL_0DL_0PL_Fog");
  return atexit(_E643_7);
}

//----- (006CDCA0) --------------------------------------------------------  // acclient.c:740986
int _E645_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_0, "AL_0DL_1PL_Fog");
  return atexit(_E646_7);
}

//----- (006CDCC0) --------------------------------------------------------  // acclient.c:740993
int _E648_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_0, "AL_0DL_2PL_Fog");
  return atexit(_E649_7);
}

//----- (006CDCE0) --------------------------------------------------------  // acclient.c:741000
int _E651_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_0, "AL_0DL_3PL_Fog");
  return atexit(_E652_7);
}

//----- (006CDD00) --------------------------------------------------------  // acclient.c:741007
int _E654_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_0, "AL_0DL_4PL_Fog");
  return atexit(_E655_7);
}

//----- (006CDD20) --------------------------------------------------------  // acclient.c:741014
int _E657_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_0, "AL_0DL_5PL_Fog");
  return atexit(_E658_7);
}

//----- (006CDD40) --------------------------------------------------------  // acclient.c:741021
int _E660_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_0, "AL_0DL_6PL_Fog");
  return atexit(_E661_7);
}

//----- (006CDD60) --------------------------------------------------------  // acclient.c:741028
int _E663_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_0, "AL_0DL_7PL_Fog");
  return atexit(_E664_7);
}

//----- (006CDD80) --------------------------------------------------------  // acclient.c:741035
int _E666_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_0, "AL_0DL_8PL_Fog");
  return atexit(_E667_7);
}

//----- (006CDDA0) --------------------------------------------------------  // acclient.c:741042
int _E669_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_0, "AL_1DL_0PL_Fog");
  return atexit(_E670_7);
}

//----- (006CDDC0) --------------------------------------------------------  // acclient.c:741049
int _E672_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_0, "AL_1DL_1PL_Fog");
  return atexit(_E673_7);
}

//----- (006CDDE0) --------------------------------------------------------  // acclient.c:741056
int _E675_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_0, "AL_1DL_2PL_Fog");
  return atexit(_E676_7);
}

//----- (006CDE00) --------------------------------------------------------  // acclient.c:741063
int _E678_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_0, "AL_1DL_3PL_Fog");
  return atexit(_E679_7);
}

//----- (006CDE20) --------------------------------------------------------  // acclient.c:741070
int _E681_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_0, "AL_1DL_4PL_Fog");
  return atexit(_E682_7);
}

//----- (006CDE40) --------------------------------------------------------  // acclient.c:741077
int _E684_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_0, "AL_1DL_5PL_Fog");
  return atexit(_E685_7);
}

//----- (006CDE60) --------------------------------------------------------  // acclient.c:741084
int _E687_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_0, "AL_1DL_6PL_Fog");
  return atexit(_E688_7);
}

//----- (006CDE80) --------------------------------------------------------  // acclient.c:741091
int _E690_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_0, "AL_1DL_7PL_Fog");
  return atexit(_E691_7);
}

//----- (006CDEA0) --------------------------------------------------------  // acclient.c:741098
int _E693_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_0, "Zero");
  return atexit(_E694_7);
}

//----- (006CDEC0) --------------------------------------------------------  // acclient.c:741105
int _E696_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_0, "One");
  return atexit(_E697_7);
}

//----- (006CDEE0) --------------------------------------------------------  // acclient.c:741112
int _E699_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_0, "SrcColor");
  return atexit(_E700_7);
}

//----- (006CDF00) --------------------------------------------------------  // acclient.c:741119
int _E702_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_0, "InvSrcColor");
  return atexit(_E703_7);
}

//----- (006CDF20) --------------------------------------------------------  // acclient.c:741126
int _E705_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_0, "SrcAlpha");
  return atexit(_E706_7);
}

//----- (006CDF40) --------------------------------------------------------  // acclient.c:741133
int _E708_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_0, "InvSrcAlpha");
  return atexit(_E709_7);
}

//----- (006CDF60) --------------------------------------------------------  // acclient.c:741140
int _E711_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_0, "DstAlpha");
  return atexit(_E712_7);
}

//----- (006CDF80) --------------------------------------------------------  // acclient.c:741147
int _E714_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_0, "InvDstAlpha");
  return atexit(_E715_7);
}

//----- (006CDFA0) --------------------------------------------------------  // acclient.c:741154
int _E717_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_0, "DstColor");
  return atexit(_E718_7);
}

//----- (006CDFC0) --------------------------------------------------------  // acclient.c:741161
int _E720_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_0, "InvDstColor");
  return atexit(_E721_7);
}

//----- (006CDFE0) --------------------------------------------------------  // acclient.c:741168
int _E723_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_0, "SrcAlphaSat");
  return atexit(_E724_7);
}

//----- (006CE000) --------------------------------------------------------  // acclient.c:741175
int _E726_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_0, "Less");
  return atexit(_E727_7);
}

//----- (006CE020) --------------------------------------------------------  // acclient.c:741182
int _E729_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_0, "Equal");
  return atexit(_E730_7);
}

//----- (006CE040) --------------------------------------------------------  // acclient.c:741189
int _E732_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_0, "LessEqual");
  return atexit(_E733_7);
}

//----- (006CE060) --------------------------------------------------------  // acclient.c:741196
int _E735_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_0, "Greater");
  return atexit(_E736_7);
}

//----- (006CE080) --------------------------------------------------------  // acclient.c:741203
int _E738_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_0, "NotEqual");
  return atexit(_E739_7);
}

//----- (006CE0A0) --------------------------------------------------------  // acclient.c:741210
int _E741_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_0, "GreaterEqual");
  return atexit(_E742_7);
}

//----- (006CE0C0) --------------------------------------------------------  // acclient.c:741217
int _E744_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_0, "Always");
  return atexit(_E745_7);
}

//----- (006CE0E0) --------------------------------------------------------  // acclient.c:741224
int _E747_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_0, "On");
  return atexit(_E748_7);
}

//----- (006CE100) --------------------------------------------------------  // acclient.c:741231
int _E750_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_0, "Off");
  return atexit(_E751_7);
}

//----- (006CE120) --------------------------------------------------------  // acclient.c:741238
int _E753_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_0, "LayerDiffuse");
  return atexit(_E754_7);
}

//----- (006CE140) --------------------------------------------------------  // acclient.c:741245
int _E756_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_0, "LayerSpecular");
  return atexit(_E757_7);
}

//----- (006CE160) --------------------------------------------------------  // acclient.c:741252
int _E759_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_0, "VertexDiffuse");
  return atexit(_E760_7);
}

//----- (006CE180) --------------------------------------------------------  // acclient.c:741259
int _E762_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_0, "VertexSpecular");
  return atexit(_E763_7);
}

//----- (006CE1A0) --------------------------------------------------------  // acclient.c:741266
int _E765_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_0, "None");
  return atexit(_E766_7);
}

//----- (006CE1C0) --------------------------------------------------------  // acclient.c:741273
int _E768_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_0, "CW");
  return atexit(_E769_7);
}

//----- (006CE1E0) --------------------------------------------------------  // acclient.c:741280
int _E771_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_0, "CCW");
  return atexit(_E772_7);
}

//----- (006CE200) --------------------------------------------------------  // acclient.c:741287
int _E774_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_0, "None");
  return atexit(_E775_7);
}

//----- (006CE220) --------------------------------------------------------  // acclient.c:741294
int _E777_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_0, "Simple");
  return atexit(_E778_7);
}

//----- (006CE240) --------------------------------------------------------  // acclient.c:741301
int _E780_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_0, "Diffuse");
  return atexit(_E781_7);
}

//----- (006CE260) --------------------------------------------------------  // acclient.c:741308
int _E783_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_0, "Specular");
  return atexit(_E784_7);
}

//----- (006CE280) --------------------------------------------------------  // acclient.c:741315
int _E786_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_0, "Off");
  return atexit(_E787_7);
}

//----- (006CE2A0) --------------------------------------------------------  // acclient.c:741322
int _E789_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_0, "On");
  return atexit(_E790_7);
}

//----- (006CE2C0) --------------------------------------------------------  // acclient.c:741329
int _E792_0()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_0, "Off");
  return atexit(_E793_7);
}

//----- (006CE2E0) --------------------------------------------------------  // acclient.c:741336
int _E795_0()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_0, "On");
  return atexit(_E796_7);
}

//----- (006CE300) --------------------------------------------------------  // acclient.c:741343
int _E798_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_0, "Origin");
  return atexit(_E799_7);
}

//----- (006CE320) --------------------------------------------------------  // acclient.c:741350
int _E801_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_0, "Normal");
  return atexit(_E802_7);
}

//----- (006CE340) --------------------------------------------------------  // acclient.c:741357
int _E804_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_0, "PointSize");
  return atexit(_E805_7);
}

//----- (006CE360) --------------------------------------------------------  // acclient.c:741364
int _E807_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_0, "Diffuse");
  return atexit(_E808_7);
}

//----- (006CE380) --------------------------------------------------------  // acclient.c:741371
int _E810_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_0, "Specular");
  return atexit(_E811_7);
}

//----- (006CE3A0) --------------------------------------------------------  // acclient.c:741378
int _E813_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_0, "TCPairX1");
  return atexit(_E814_7);
}

//----- (006CE3C0) --------------------------------------------------------  // acclient.c:741385
int _E816_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_0, "TCPairX2");
  return atexit(_E817_7);
}

//----- (006CE3E0) --------------------------------------------------------  // acclient.c:741392
int _E819_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_0, "TCPairX3");
  return atexit(_E820_7);
}

//----- (006CE400) --------------------------------------------------------  // acclient.c:741399
int _E822_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_0, "TCPairX4");
  return atexit(_E823_7);
}

//----- (006CE420) --------------------------------------------------------  // acclient.c:741406
int _E825_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_0, "TCPairX5");
  return atexit(_E826_7);
}

//----- (006CE440) --------------------------------------------------------  // acclient.c:741413
int _E828_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_0, "TCPairX6");
  return atexit(_E829_7);
}

//----- (006CE460) --------------------------------------------------------  // acclient.c:741420
int _E831_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_0, "TCPairX7");
  return atexit(_E832_7);
}

//----- (006CE480) --------------------------------------------------------  // acclient.c:741427
int _E834_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_0, "TCPairX8");
  return atexit(_E835_7);
}

//----- (006CE4A0) --------------------------------------------------------  // acclient.c:741434
int _E837_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_0, "VectorS");
  return atexit(_E838_7);
}

//----- (006CE4C0) --------------------------------------------------------  // acclient.c:741441
int _E840_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_0, "VectorT");
  return atexit(_E841_7);
}

//----- (006CE4E0) --------------------------------------------------------  // acclient.c:741448
int _E843_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_14, "Stage");
  return atexit(_E844_7);
}

//----- (006CE500) --------------------------------------------------------  // acclient.c:741455
int _E846_0()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_0, "Sampler");
  return atexit(_E847_7);
}

//----- (006CE520) --------------------------------------------------------  // acclient.c:741462
int _E849_0()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_0, "SamplerName");
  return atexit(_E850_7);
}

//----- (006CE540) --------------------------------------------------------  // acclient.c:741469
int _E852_0()
{
  PStringBase<char>::PStringBase<char>(&Texture_0, "Texture");
  return atexit(_E853_7);
}

//----- (006CE560) --------------------------------------------------------  // acclient.c:741476
int _E855_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_0, "!FrameBuffer");
  return atexit(_E856_7);
}

//----- (006CE580) --------------------------------------------------------  // acclient.c:741483
int _E858_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_0, "!Distortion");
  return atexit(_E859_7);
}

//----- (006CE5A0) --------------------------------------------------------  // acclient.c:741490
int _E861_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_0, "!Reflection");
  return atexit(_E862_7);
}

//----- (006CE5C0) --------------------------------------------------------  // acclient.c:741497
int _E864_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_0, "!NormalizeCube");
  return atexit(_E865_7);
}

//----- (006CE5E0) --------------------------------------------------------  // acclient.c:741504
int _E867_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_0, "!LightProjectorCube");
  return atexit(_E868_7);
}

//----- (006CE600) --------------------------------------------------------  // acclient.c:741511
int _E870_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_0, "!EnvironmentCube");
  return atexit(_E871_7);
}

//----- (006CE620) --------------------------------------------------------  // acclient.c:741518
int _E873_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_0, "!LandscapeShadows");
  return atexit(_E874_7);
}

//----- (006CE640) --------------------------------------------------------  // acclient.c:741525
int _E876_0()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_0, "AddressMode");
  return atexit(_E877_7);
}

//----- (006CE660) --------------------------------------------------------  // acclient.c:741532
int _E879_0()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_0, "FilterMode");
  return atexit(_E880_7);
}

//----- (006CE680) --------------------------------------------------------  // acclient.c:741539
int _E882_0()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_0, "FFColorOp");
  return atexit(_E883_7);
}

//----- (006CE6A0) --------------------------------------------------------  // acclient.c:741546
int _E885_0()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_0, "FFColorArg1");
  return atexit(_E886_7);
}

//----- (006CE6C0) --------------------------------------------------------  // acclient.c:741553
int _E888_0()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_0, "FFColorArg2");
  return atexit(_E889_7);
}

//----- (006CE6E0) --------------------------------------------------------  // acclient.c:741560
int _E891_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_0, "FFAlphaOp");
  return atexit(_E892_7);
}

//----- (006CE700) --------------------------------------------------------  // acclient.c:741567
int _E894_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_0, "FFAlphaArg1");
  return atexit(_E895_7);
}

//----- (006CE720) --------------------------------------------------------  // acclient.c:741574
int _E897_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_0, "FFAlphaArg2");
  return atexit(_E898_7);
}

//----- (006CE740) --------------------------------------------------------  // acclient.c:741581
int _E900_0()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_0, "FFTexCoordIndex");
  return atexit(_E901_7);
}

//----- (006CE760) --------------------------------------------------------  // acclient.c:741588
int _E903_0()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_0, "FFUseProjection");
  return atexit(_E904_7);
}

//----- (006CE780) --------------------------------------------------------  // acclient.c:741595
int _E906_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_0, "SelectArg1");
  return atexit(_E907_7);
}

//----- (006CE7A0) --------------------------------------------------------  // acclient.c:741602
int _E909_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_0, "SelectArg2");
  return atexit(_E910_7);
}

//----- (006CE7C0) --------------------------------------------------------  // acclient.c:741609
int _E912_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_0, "Modulate");
  return atexit(_E913_7);
}

//----- (006CE7E0) --------------------------------------------------------  // acclient.c:741616
int _E915_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_0, "Modulate2X");
  return atexit(_E916_7);
}

//----- (006CE800) --------------------------------------------------------  // acclient.c:741623
int _E918_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_0, "Modulate4X");
  return atexit(_E919_7);
}

//----- (006CE820) --------------------------------------------------------  // acclient.c:741630
int _E921_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_0, "Add");
  return atexit(_E922_7);
}

//----- (006CE840) --------------------------------------------------------  // acclient.c:741637
int _E924_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_0, "AddSigned");
  return atexit(_E925_7);
}

//----- (006CE860) --------------------------------------------------------  // acclient.c:741644
int _E927_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_0, "AddSigned2X");
  return atexit(_E928_7);
}

//----- (006CE880) --------------------------------------------------------  // acclient.c:741651
int _E930_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_0, "Subtract");
  return atexit(_E931_7);
}

//----- (006CE8A0) --------------------------------------------------------  // acclient.c:741658
int _E933_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_0, "AddSmooth");
  return atexit(_E934_7);
}

//----- (006CE8C0) --------------------------------------------------------  // acclient.c:741665
int _E936_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_0, "BlendDiffuseAlpha");
  return atexit(_E937_7);
}

//----- (006CE8E0) --------------------------------------------------------  // acclient.c:741672
int _E939_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_0, "BlendTextureAlpha");
  return atexit(_E940_7);
}

//----- (006CE900) --------------------------------------------------------  // acclient.c:741679
int _E942_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_0, "BlendFactorAlpha");
  return atexit(_E943_7);
}

//----- (006CE920) --------------------------------------------------------  // acclient.c:741686
int _E945_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_0, "BlendTextureAlphaPM");
  return atexit(_E946_7);
}

//----- (006CE940) --------------------------------------------------------  // acclient.c:741693
int _E948_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_0, "BlendCurrentAlpha");
  return atexit(_E949_7);
}

//----- (006CE960) --------------------------------------------------------  // acclient.c:741700
int _E951_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_0, "Premodulate");
  return atexit(_E952_7);
}

//----- (006CE980) --------------------------------------------------------  // acclient.c:741707
int _E954_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_0, "ModulateAlphaAddColor");
  return atexit(_E955_7);
}

//----- (006CE9A0) --------------------------------------------------------  // acclient.c:741714
int _E957_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_0, "ModulateColorAddAlpha");
  return atexit(_E958_7);
}

//----- (006CE9C0) --------------------------------------------------------  // acclient.c:741721
int _E960_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_0, "ModulateInvAlphaAddColor");
  return atexit(_E961_7);
}

//----- (006CE9E0) --------------------------------------------------------  // acclient.c:741728
int _E963_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_0, "ModulateInvColorAddAlpha");
  return atexit(_E964_7);
}

//----- (006CEA00) --------------------------------------------------------  // acclient.c:741735
int _E966_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_0, "BumpEnvMap");
  return atexit(_E967_7);
}

//----- (006CEA20) --------------------------------------------------------  // acclient.c:741742
int _E969_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_0, "BumpEnvMapLuminance");
  return atexit(_E970_7);
}

//----- (006CEA40) --------------------------------------------------------  // acclient.c:741749
int _E972_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_0, "DotProduct3");
  return atexit(_E973_7);
}

//----- (006CEA60) --------------------------------------------------------  // acclient.c:741756
int _E975_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_0, "MultiplyAdd");
  return atexit(_E976_7);
}

//----- (006CEA80) --------------------------------------------------------  // acclient.c:741763
int _E978_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_0, "Lerp");
  return atexit(_E979_7);
}

//----- (006CEAA0) --------------------------------------------------------  // acclient.c:741770
int _E981_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_0, "Diffuse");
  return atexit(_E982_7);
}

//----- (006CEAC0) --------------------------------------------------------  // acclient.c:741777
int _E984_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_0, "Specular");
  return atexit(_E985_7);
}

//----- (006CEAE0) --------------------------------------------------------  // acclient.c:741784
int _E987_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_0, "Current");
  return atexit(_E988_7);
}

//----- (006CEB00) --------------------------------------------------------  // acclient.c:741791
int _E990_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_0, "Texture");
  return atexit(_E991_7);
}

//----- (006CEB20) --------------------------------------------------------  // acclient.c:741798
int _E993_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_0, "TFactor");
  return atexit(_E994_7);
}

//----- (006CEB40) --------------------------------------------------------  // acclient.c:741805
int _E996_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_0, "Wrap");
  return atexit(_E997_7);
}

//----- (006CEB60) --------------------------------------------------------  // acclient.c:741812
int _E999_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_0, "Mirror");
  return atexit(_E1000_7);
}

//----- (006CEB80) --------------------------------------------------------  // acclient.c:741819
int _E1002_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_0, "Clamp");
  return atexit(_E1003_7);
}

//----- (006CEBA0) --------------------------------------------------------  // acclient.c:741826
int _E1005_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_0, "Border");
  return atexit(_E1006_7);
}

//----- (006CEBC0) --------------------------------------------------------  // acclient.c:741833
int _E1008_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_0, "None");
  return atexit(_E1009_7);
}

//----- (006CEBE0) --------------------------------------------------------  // acclient.c:741840
int _E1011_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_0, "Point");
  return atexit(_E1012_7);
}

//----- (006CEC00) --------------------------------------------------------  // acclient.c:741847
int _E1014_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_0, "Linear");
  return atexit(_E1015_7);
}

//----- (006CEC20) --------------------------------------------------------  // acclient.c:741854
int _E1017_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_0, "Anisotropic");
  return atexit(_E1018_7);
}

//----- (006CEC40) --------------------------------------------------------  // acclient.c:741861
int _E1020_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_0, "ReflectionVector");
  return atexit(_E1021_7);
}

//----- (006CEC60) --------------------------------------------------------  // acclient.c:741868
int _E1023_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_0, "ViewNormal");
  return atexit(_E1024_7);
}

//----- (006CEC80) --------------------------------------------------------  // acclient.c:741875
int _E1026_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_0, "ViewOrigin");
  return atexit(_E1027_7);
}

//----- (006CECA0) --------------------------------------------------------  // acclient.c:741882
int _E1029_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_0, "SphereMap");
  return atexit(_E1030_7);
}

//----- (006CECC0) --------------------------------------------------------  // acclient.c:741889
int _E1032_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_0, "CubeMapReflection");
  return atexit(_E1033_7);
}

//----- (006CECE0) --------------------------------------------------------  // acclient.c:741896
int _E1035_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_0, "CubeMapFakeLight");
  return atexit(_E1036_7);
}

//----- (006CED00) --------------------------------------------------------  // acclient.c:741903
int _E1038_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_15, "FFModifier");
  return atexit(_E1039_7);
}

//----- (006CED20) --------------------------------------------------------  // acclient.c:741910
int _E1041_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_0, "Origin");
  return atexit(_E1042_7);
}

//----- (006CED40) --------------------------------------------------------  // acclient.c:741917
int _E1044_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_0, "Normal");
  return atexit(_E1045_7);
}

//----- (006CED60) --------------------------------------------------------  // acclient.c:741924
int _E1047_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_0, "Diffuse");
  return atexit(_E1048_7);
}

//----- (006CED80) --------------------------------------------------------  // acclient.c:741931
int _E1050_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_0, "UVTranslate");
  return atexit(_E1051_7);
}

//----- (006CEDA0) --------------------------------------------------------  // acclient.c:741938
int _E1053_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_0, "UVRotate");
  return atexit(_E1054_7);
}

//----- (006CEDC0) --------------------------------------------------------  // acclient.c:741945
int _E1056_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_0, "UVScale");
  return atexit(_E1057_7);
}

//----- (006CEDE0) --------------------------------------------------------  // acclient.c:741952
int _E1059_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_0, "UVTransform");
  return atexit(_E1060_7);
}

//----- (006CEE00) --------------------------------------------------------  // acclient.c:741959
int _E1062_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_0, "TexCoordIndex");
  return atexit(_E1063_7);
}

//----- (006CEE20) --------------------------------------------------------  // acclient.c:741966
int _E1065_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_0, "Translate");
  return atexit(_E1066_7);
}

//----- (006CEE40) --------------------------------------------------------  // acclient.c:741973
int _E1068_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_0, "TexCoordIndex");
  return atexit(_E1069_7);
}

//----- (006CEE60) --------------------------------------------------------  // acclient.c:741980
int _E1071_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_0, "Rotate");
  return atexit(_E1072_7);
}

//----- (006CEE80) --------------------------------------------------------  // acclient.c:741987
int _E1074_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_0, "TexCoordIndex");
  return atexit(_E1075_7);
}

//----- (006CEEA0) --------------------------------------------------------  // acclient.c:741994
int _E1077_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_0, "Scale");
  return atexit(_E1078_7);
}

//----- (006CEEC0) --------------------------------------------------------  // acclient.c:742001
int _E1080_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_16, "PSDesc");
  return atexit(_E1081_7);
}

//----- (006CEEE0) --------------------------------------------------------  // acclient.c:742008
int _E1083_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_0, "PhysicsTimeStep");
  return atexit(_E1084_7);
}

//----- (006CEF00) --------------------------------------------------------  // acclient.c:742015
int _E1086_0()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_0, "FastForwardTime");
  return atexit(_E1087_7);
}

//----- (006CEF20) --------------------------------------------------------  // acclient.c:742022
int _E1089_0()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_0, "StartFadeDistance");
  return atexit(_E1090_7);
}

//----- (006CEF40) --------------------------------------------------------  // acclient.c:742029
int _E1092_0()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_0, "StopFadeDistance");
  return atexit(_E1093_7);
}

//----- (006CEF60) --------------------------------------------------------  // acclient.c:742036
int _E1095_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_0, "PhysicsDuration");
  return atexit(_E1096_7);
}

//----- (006CEF80) --------------------------------------------------------  // acclient.c:742043
int _E1098_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_0, "ScaleType");
  return atexit(_E1099_7);
}

//----- (006CEFA0) --------------------------------------------------------  // acclient.c:742050
int _E1101_0()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_0, "WorldSpace");
  return atexit(_E1102_7);
}

//----- (006CEFC0) --------------------------------------------------------  // acclient.c:742057
int _E1104_0()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_0, "ForceDraw");
  return atexit(_E1105_7);
}

//----- (006CEFE0) --------------------------------------------------------  // acclient.c:742064
int _E1107_0()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_0, "NumEmitters");
  return atexit(_E1108_7);
}

//----- (006CF000) --------------------------------------------------------  // acclient.c:742071
int _E1110_0()
{
  PStringBase<char>::PStringBase<char>(&Material_7, "Material");
  return atexit(_E1111_7);
}

//----- (006CF020) --------------------------------------------------------  // acclient.c:742078
int _E1113_0()
{
  PStringBase<char>::PStringBase<char>(&Version_0, "Version");
  return atexit(_E1114_7);
}

//----- (006CF040) --------------------------------------------------------  // acclient.c:742085
int _E1116_0()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_0, "MaxParticles");
  return atexit(_E1117_7);
}

//----- (006CF060) --------------------------------------------------------  // acclient.c:742092
int _E1119_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_17, "Emitter");
  return atexit(_E1120_7);
}

//----- (006CF080) --------------------------------------------------------  // acclient.c:742099
int _E1122_0()
{
  PStringBase<char>::PStringBase<char>(&Origin_2, "Origin");
  return atexit(_E1123_7);
}

//----- (006CF0A0) --------------------------------------------------------  // acclient.c:742106
int _E1125_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_0, "Shape");
  return atexit(_E1126_7);
}

//----- (006CF0C0) --------------------------------------------------------  // acclient.c:742113
int _E1128_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_0, "Point");
  return atexit(_E1129_7);
}

//----- (006CF0E0) --------------------------------------------------------  // acclient.c:742120
int _E1131_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_0, "Line");
  return atexit(_E1132_7);
}

//----- (006CF100) --------------------------------------------------------  // acclient.c:742127
int _E1134_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_0, "Quad");
  return atexit(_E1135_7);
}

//----- (006CF120) --------------------------------------------------------  // acclient.c:742134
int _E1137_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_0, "Disc");
  return atexit(_E1138_7);
}

//----- (006CF140) --------------------------------------------------------  // acclient.c:742141
int _E1140_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_0, "Sphere");
  return atexit(_E1141_7);
}

//----- (006CF160) --------------------------------------------------------  // acclient.c:742148
int _E1143_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_0, "ParticleShape");
  return atexit(_E1144_7);
}

//----- (006CF180) --------------------------------------------------------  // acclient.c:742155
int _E1146_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_0, "Triangle");
  return atexit(_E1147_7);
}

//----- (006CF1A0) --------------------------------------------------------  // acclient.c:742162
int _E1149_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_0, "Quad");
  return atexit(_E1150_7);
}

//----- (006CF1C0) --------------------------------------------------------  // acclient.c:742169
int _E1152_0()
{
  PStringBase<char>::PStringBase<char>(&Streak_0, "Streak");
  return atexit(_E1153_7);
}

//----- (006CF1E0) --------------------------------------------------------  // acclient.c:742176
int _E1155_0()
{
  PStringBase<char>::PStringBase<char>(&Rotation_2, "Rotation");
  return atexit(_E1156_7);
}

//----- (006CF200) --------------------------------------------------------  // acclient.c:742183
int _E1158_0()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_0, "WorldRotation");
  return atexit(_E1159_7);
}

//----- (006CF220) --------------------------------------------------------  // acclient.c:742190
int _E1161_0()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_0, "RotateVelocity");
  return atexit(_E1162_7);
}

//----- (006CF240) --------------------------------------------------------  // acclient.c:742197
int _E1164_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_0, "ParticleScale");
  return atexit(_E1165_7);
}

//----- (006CF260) --------------------------------------------------------  // acclient.c:742204
int _E1167_0()
{
  PStringBase<char>::PStringBase<char>(&Scale_3, "Scale");
  return atexit(_E1168_7);
}

//----- (006CF280) --------------------------------------------------------  // acclient.c:742211
int _E1170_0()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_0, "ExplodingDir");
  return atexit(_E1171_7);
}

//----- (006CF2A0) --------------------------------------------------------  // acclient.c:742218
int _E1173_0()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_0, "BirthRate");
  return atexit(_E1174_7);
}

//----- (006CF2C0) --------------------------------------------------------  // acclient.c:742225
int _E1176_0()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_0, "Lifespan");
  return atexit(_E1177_7);
}

//----- (006CF2E0) --------------------------------------------------------  // acclient.c:742232
int _E1179_0()
{
  PStringBase<char>::PStringBase<char>(&Velocity_0, "Velocity");
  return atexit(_E1180_7);
}

//----- (006CF300) --------------------------------------------------------  // acclient.c:742239
int _E1182_0()
{
  PStringBase<char>::PStringBase<char>(&Direction_0, "Direction");
  return atexit(_E1183_7);
}

//----- (006CF320) --------------------------------------------------------  // acclient.c:742246
int _E1185_0()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_0, "MinSpread");
  return atexit(_E1186_7);
}

//----- (006CF340) --------------------------------------------------------  // acclient.c:742253
int _E1188_0()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_0, "MaxSpread");
  return atexit(_E1189_7);
}

//----- (006CF360) --------------------------------------------------------  // acclient.c:742260
int _E1191_0()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_0, "EmissionLimit");
  return atexit(_E1192_7);
}

//----- (006CF380) --------------------------------------------------------  // acclient.c:742267
int _E1194_0()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_0, "BlastCount");
  return atexit(_E1195_7);
}

//----- (006CF3A0) --------------------------------------------------------  // acclient.c:742274
int _E1197_0()
{
  PStringBase<char>::PStringBase<char>(&StartTime_0, "StartTime");
  return atexit(_E1198_7);
}

//----- (006CF3C0) --------------------------------------------------------  // acclient.c:742281
int _E1200_0()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_0, "TimeLimit");
  return atexit(_E1201_7);
}

//----- (006CF3E0) --------------------------------------------------------  // acclient.c:742288
int _E1203_0()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_0, "EmissionDistance");
  return atexit(_E1204_7);
}

//----- (006CF400) --------------------------------------------------------  // acclient.c:742295
int _E1206_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_0, "ParticleSnap");
  return atexit(_E1207_7);
}

//----- (006CF420) --------------------------------------------------------  // acclient.c:742302
int _E1209_0()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_0, "InclusiveShape");
  return atexit(_E1210_7);
}

//----- (006CF440) --------------------------------------------------------  // acclient.c:742309
int _E1212_0()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_0, "NumKeyframes");
  return atexit(_E1213_7);
}

//----- (006CF460) --------------------------------------------------------  // acclient.c:742316
int _E1215_0()
{
  PStringBase<char>::PStringBase<char>(&IsActive_0, "IsActive");
  return atexit(_E1216_7);
}

//----- (006CF480) --------------------------------------------------------  // acclient.c:742323
int _E1218_0()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_0, "FadeIn");
  return atexit(_E1219_7);
}

//----- (006CF4A0) --------------------------------------------------------  // acclient.c:742330
int _E1221_0()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_0, "FadeOut");
  return atexit(_E1222_7);
}

//----- (006CF4C0) --------------------------------------------------------  // acclient.c:742337
int _E1224_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_0, "ConstrainX");
  return atexit(_E1225_7);
}

//----- (006CF4E0) --------------------------------------------------------  // acclient.c:742344
int _E1227_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_0, "ConstrainY");
  return atexit(_E1228_7);
}

//----- (006CF500) --------------------------------------------------------  // acclient.c:742351
int _E1230_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_0, "ConstrainZ");
  return atexit(_E1231_7);
}

//----- (006CF520) --------------------------------------------------------  // acclient.c:742358
int _E1233_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_18, "Keyframe");
  return atexit(_E1234_7);
}

//----- (006CF540) --------------------------------------------------------  // acclient.c:742365
int _E1236_0()
{
  PStringBase<char>::PStringBase<char>(&Time_0, "Time");
  return atexit(_E1237_7);
}

//----- (006CF560) --------------------------------------------------------  // acclient.c:742372
int _E1239_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_0, "Flags");
  return atexit(_E1240_7);
}

//----- (006CF580) --------------------------------------------------------  // acclient.c:742379
int _E1242_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_0, "None");
  return atexit(_E1243_7);
}

//----- (006CF5A0) --------------------------------------------------------  // acclient.c:742386
int _E1245_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_0, "BlendScale");
  return atexit(_E1246_7);
}

//----- (006CF5C0) --------------------------------------------------------  // acclient.c:742393
int _E1248_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_0, "BlendColor");
  return atexit(_E1249_7);
}

//----- (006CF5E0) --------------------------------------------------------  // acclient.c:742400
int _E1251_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_0, "BlendMass");
  return atexit(_E1252_7);
}

//----- (006CF600) --------------------------------------------------------  // acclient.c:742407
int _E1254_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_0, "SetScale");
  return atexit(_E1255_7);
}

//----- (006CF620) --------------------------------------------------------  // acclient.c:742414
int _E1257_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_0, "SetColor");
  return atexit(_E1258_6);
}

//----- (006CF640) --------------------------------------------------------  // acclient.c:742421
int _E1260_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_0, "SetMass");
  return atexit(_E1261_5);
}

//----- (006CF660) --------------------------------------------------------  // acclient.c:742428
int _E1263_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_0, "SetParticleFlags");
  return atexit(_E1264_5);
}

//----- (006CF680) --------------------------------------------------------  // acclient.c:742435
int _E1266_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_0, "SetControllerType");
  return atexit(_E1267_5);
}

//----- (006CF6A0) --------------------------------------------------------  // acclient.c:742442
int _E1269_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_0, "SetPhysicsFlags");
  return atexit(_E1270_5);
}

//----- (006CF6C0) --------------------------------------------------------  // acclient.c:742449
int _E1272_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_0, "SetParams");
  return atexit(_E1273_5);
}

//----- (006CF6E0) --------------------------------------------------------  // acclient.c:742456
int _E1275_0()
{
  PStringBase<char>::PStringBase<char>(&Scale_4, "Scale");
  return atexit(_E1276_6);
}

//----- (006CF700) --------------------------------------------------------  // acclient.c:742463
int _E1278_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_0, "ScaleX");
  return atexit(_E1279_5);
}

//----- (006CF720) --------------------------------------------------------  // acclient.c:742470
int _E1281_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_0, "ScaleY");
  return atexit(_E1282_6);
}

//----- (006CF740) --------------------------------------------------------  // acclient.c:742477
int _E1284_0()
{
  PStringBase<char>::PStringBase<char>(&Color_0, "Color");
  return atexit(_E1285_5);
}

//----- (006CF760) --------------------------------------------------------  // acclient.c:742484
int _E1287_0()
{
  PStringBase<char>::PStringBase<char>(&Mass_0, "Mass");
  return atexit(_E1288_5);
}

//----- (006CF780) --------------------------------------------------------  // acclient.c:742491
int _E1290_0()
{
  PStringBase<char>::PStringBase<char>(&PFlags_0, "ParticleFlags");
  return atexit(_E1291_4);
}

//----- (006CF7A0) --------------------------------------------------------  // acclient.c:742498
int _E1293_0()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_0, "None");
  return atexit(_E1294_5);
}

//----- (006CF7C0) --------------------------------------------------------  // acclient.c:742505
int _E1296_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_0, "ControllerType");
  return atexit(_E1297_4);
}

//----- (006CF7E0) --------------------------------------------------------  // acclient.c:742512
int _E1299_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_0, "None");
  return atexit(_E1300_4);
}

//----- (006CF800) --------------------------------------------------------  // acclient.c:742519
int _E1302_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_0, "Physics");
  return atexit(_E1303_3);
}

//----- (006CF820) --------------------------------------------------------  // acclient.c:742526
int _E1305_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_0, "Parametric");
  return atexit(_E1306_2);
}

//----- (006CF840) --------------------------------------------------------  // acclient.c:742533
int _E1308_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_0, "AttractRepulse");
  return atexit(_E1309_2);
}

//----- (006CF860) --------------------------------------------------------  // acclient.c:742540
int _E1311_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_0, "PointFile");
  return atexit(_E1312_2);
}

//----- (006CF880) --------------------------------------------------------  // acclient.c:742547
int _E1314_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_0, "PointFileLerp");
  return atexit(_E1315_0);
}

//----- (006CF8A0) --------------------------------------------------------  // acclient.c:742554
int _E1317_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_0, "PhysicsFlags");
  return atexit(_E1318_0);
}

//----- (006CF8C0) --------------------------------------------------------  // acclient.c:742561
int _E1320_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_0, "None");
  return atexit(_E1321_0);
}

//----- (006CF8E0) --------------------------------------------------------  // acclient.c:742568
int _E1323_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_0, "Gravity");
  return atexit(_E1324_0);
}

//----- (006CF900) --------------------------------------------------------  // acclient.c:742575
int _E1326_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_0, "Wind");
  return atexit(_E1327_0);
}

//----- (006CF920) --------------------------------------------------------  // acclient.c:742582
int _E1329_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_0, "Momentum");
  return atexit(_E1330_0);
}

//----- (006CF940) --------------------------------------------------------  // acclient.c:742589
int _E1332_0()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_0, "RandomPoint");
  return atexit(_E1333_0);
}

//----- (006CF960) --------------------------------------------------------  // acclient.c:742596
int _E1335_0()
{
  PStringBase<char>::PStringBase<char>(&Position_1, "Position");
  return atexit(_E1336_0);
}

//----- (006CF980) --------------------------------------------------------  // acclient.c:742603
int _E1338_0()
{
  PStringBase<char>::PStringBase<char>(&PointList_0, "PointList");
  return atexit(_E1339_0);
}

//----- (006CF9A0) --------------------------------------------------------  // acclient.c:742610
int _E1341_0()
{
  PStringBase<char>::PStringBase<char>(&Point_2, "pt");
  return atexit(_E1342_0);
}

//----- (006CF9C0) --------------------------------------------------------  // acclient.c:742617
int _E1344_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_0, "DetailLevels");
  return atexit(_E1345_0);
}

//----- (006CF9E0) --------------------------------------------------------  // acclient.c:742624
int _E1347_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_0, "Low");
  return atexit(_E1348_0);
}

//----- (006CFA00) --------------------------------------------------------  // acclient.c:742631
int _E1350_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_0, "Medium");
  return atexit(_E1351_0);
}

//----- (006CFA20) --------------------------------------------------------  // acclient.c:742638
int _E1353_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_0, "High");
  return atexit(_E1354_0);
}

//----- (006CFA40) --------------------------------------------------------  // acclient.c:742645
int _E1356_0()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_0, "FadeSpeed");
  return atexit(_E1357_0);
}

//----- (006CFA60) --------------------------------------------------------  // acclient.c:742652
int _E1359_0()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_0, "MaxOpacity");
  return atexit(_E1360_0);
}

//----- (006CFA80) --------------------------------------------------------  // acclient.c:742659
int _E1362_0()
{
  PStringBase<char>::PStringBase<char>(&Point_3, "Point");
  return atexit(_E1363_0);
}

//----- (006CFAA0) --------------------------------------------------------  // acclient.c:742666
int _E1365_0()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_0, "AxisPos");
  return atexit(_E1366_0);
}

//----- (006CFAC0) --------------------------------------------------------  // acclient.c:742673
int _E1368_0()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_0, "Texture");
  return atexit(_E1369_0);
}

//----- (006CFAE0) --------------------------------------------------------  // acclient.c:742680
int _E1371_0()
{
  PStringBase<char>::PStringBase<char>(&PointSize_0, "Size");
  return atexit(_E1372_0);
}

//----- (006CFB00) --------------------------------------------------------  // acclient.c:742687
int _E1374_0()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_0, "UseOcclusion");
  return atexit(_E1375_0);
}

//----- (006CFB20) --------------------------------------------------------  // acclient.c:742694
int _E1377_0()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_0, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83917C, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_839180, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_839184, "PREPROC_OPTIONS");
  return atexit(_E1378_0);
}

//----- (006CFB70) --------------------------------------------------------  // acclient.c:742704
int _E1_36()
{
  return atexit(_E2_36);
}

//----- (00731330) --------------------------------------------------------  // acclient.c:836223
void __cdecl _E193_36()
{
  char *v0; // esi@1

  v0 = &PHeader_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731360) --------------------------------------------------------  // acclient.c:836236
void __cdecl _E196_44()
{
  char *v0; // esi@1

  v0 = &VertexArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731390) --------------------------------------------------------  // acclient.c:836249
void __cdecl _E199_36()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007313C0) --------------------------------------------------------  // acclient.c:836262
void __cdecl _E202_37()
{
  char *v0; // esi@1

  v0 = &VertexType_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007313F0) --------------------------------------------------------  // acclient.c:836275
void __cdecl _E205_34()
{
  char *v0; // esi@1

  v0 = &VertexData_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731420) --------------------------------------------------------  // acclient.c:836288
void __cdecl _E208_38()
{
  char *v0; // esi@1

  v0 = &Vertex_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731450) --------------------------------------------------------  // acclient.c:836301
void __cdecl _E211_34()
{
  char *v0; // esi@1

  v0 = &Index_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731480) --------------------------------------------------------  // acclient.c:836314
void __cdecl _E214_37()
{
  char *v0; // esi@1

  v0 = &Origin_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007314B0) --------------------------------------------------------  // acclient.c:836327
void __cdecl _E217_33()
{
  char *v0; // esi@1

  v0 = &Normal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007314E0) --------------------------------------------------------  // acclient.c:836340
void __cdecl _E220_33()
{
  char *v0; // esi@1

  v0 = &Diffuse_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731510) --------------------------------------------------------  // acclient.c:836353
void __cdecl _E223_33()
{
  char *v0; // esi@1

  v0 = &Specular_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731540) --------------------------------------------------------  // acclient.c:836366
void __cdecl _E226_19()
{
  char *v0; // esi@1

  v0 = &UVS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731570) --------------------------------------------------------  // acclient.c:836379
void __cdecl _E229_19()
{
  char *v0; // esi@1

  v0 = &VectorS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007315A0) --------------------------------------------------------  // acclient.c:836392
void __cdecl _E232_19()
{
  char *v0; // esi@1

  v0 = &VectorT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007315D0) --------------------------------------------------------  // acclient.c:836405
void __cdecl _E235_19()
{
  char *v0; // esi@1

  v0 = &VectorSxT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731600) --------------------------------------------------------  // acclient.c:836418
void __cdecl _E238_17()
{
  char *v0; // esi@1

  v0 = &Weights_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731630) --------------------------------------------------------  // acclient.c:836431
void __cdecl _E241_17()
{
  char *v0; // esi@1

  v0 = &Importance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731660) --------------------------------------------------------  // acclient.c:836444
void __cdecl _E244_17()
{
  char *v0; // esi@1

  v0 = &PhysMtl_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731690) --------------------------------------------------------  // acclient.c:836457
void __cdecl _E247_16()
{
  char *v0; // esi@1

  v0 = &Material_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007316C0) --------------------------------------------------------  // acclient.c:836470
void __cdecl _E250_16()
{
  char *v0; // esi@1

  v0 = &ID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007316F0) --------------------------------------------------------  // acclient.c:836483
void __cdecl _E253_16()
{
  char *v0; // esi@1

  v0 = &FileName_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731720) --------------------------------------------------------  // acclient.c:836496
void __cdecl _E256_16()
{
  char *v0; // esi@1

  v0 = &Polygon_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731750) --------------------------------------------------------  // acclient.c:836509
void __cdecl _E259_17()
{
  char *v0; // esi@1

  v0 = &ID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731780) --------------------------------------------------------  // acclient.c:836522
void __cdecl _E262_17()
{
  char *v0; // esi@1

  v0 = &Indices_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007317B0) --------------------------------------------------------  // acclient.c:836535
void __cdecl _E265_17()
{
  char *v0; // esi@1

  v0 = &MaterialID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007317E0) --------------------------------------------------------  // acclient.c:836548
void __cdecl _E268_16()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731810) --------------------------------------------------------  // acclient.c:836561
void __cdecl _E271_15()
{
  char *v0; // esi@1

  v0 = &Markings_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731840) --------------------------------------------------------  // acclient.c:836574
void __cdecl _E274_15()
{
  char *v0; // esi@1

  v0 = &Material_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731870) --------------------------------------------------------  // acclient.c:836587
void __cdecl _E277_15()
{
  char *v0; // esi@1

  v0 = &Index_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007318A0) --------------------------------------------------------  // acclient.c:836600
void __cdecl _E280_14()
{
  char *v0; // esi@1

  v0 = &Filename_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007318D0) --------------------------------------------------------  // acclient.c:836613
void __cdecl _E283_14()
{
  char *v0; // esi@1

  v0 = &Surface_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731900) --------------------------------------------------------  // acclient.c:836626
void __cdecl _E286_13()
{
  char *v0; // esi@1

  v0 = &CellPoly_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731930) --------------------------------------------------------  // acclient.c:836639
void __cdecl _E289_12()
{
  char *v0; // esi@1

  v0 = &Sphere_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731960) --------------------------------------------------------  // acclient.c:836652
void __cdecl _E292_13()
{
  char *v0; // esi@1

  v0 = &Side_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731990) --------------------------------------------------------  // acclient.c:836665
void __cdecl _E295_12()
{
  char *v0; // esi@1

  v0 = &Positive_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007319C0) --------------------------------------------------------  // acclient.c:836678
void __cdecl _E298_13()
{
  char *v0; // esi@1

  v0 = &Negative_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007319F0) --------------------------------------------------------  // acclient.c:836691
void __cdecl _E301_11()
{
  char *v0; // esi@1

  v0 = &Polygon_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731A20) --------------------------------------------------------  // acclient.c:836704
void __cdecl _E304_12()
{
  char *v0; // esi@1

  v0 = &OtherCell_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731A50) --------------------------------------------------------  // acclient.c:836717
void __cdecl _E307_11()
{
  char *v0; // esi@1

  v0 = &CellPortal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731A80) --------------------------------------------------------  // acclient.c:836730
void __cdecl _E310_12()
{
  char *v0; // esi@1

  v0 = &Portal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731AB0) --------------------------------------------------------  // acclient.c:836743
void __cdecl _E313_11()
{
  char *v0; // esi@1

  v0 = &OtherCell_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731AE0) --------------------------------------------------------  // acclient.c:836756
void __cdecl _E316_12()
{
  char *v0; // esi@1

  v0 = &OtherPortal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731B10) --------------------------------------------------------  // acclient.c:836769
void __cdecl _E319_11()
{
  char *v0; // esi@1

  v0 = &ExactMatch_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731B40) --------------------------------------------------------  // acclient.c:836782
void __cdecl _E322_11()
{
  char *v0; // esi@1

  v0 = &StabList_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731B70) --------------------------------------------------------  // acclient.c:836795
void __cdecl _E325_10()
{
  char *v0; // esi@1

  v0 = &Period_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731BA0) --------------------------------------------------------  // acclient.c:836808
void __cdecl _E328_11()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731BD0) --------------------------------------------------------  // acclient.c:836821
void __cdecl _E331_10()
{
  char *v0; // esi@1

  v0 = &Transform_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731C00) --------------------------------------------------------  // acclient.c:836834
void __cdecl _E334_10()
{
  char *v0; // esi@1

  v0 = &Scale_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731C30) --------------------------------------------------------  // acclient.c:836847
void __cdecl _E337_10()
{
  char *v0; // esi@1

  v0 = &Weight_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731C60) --------------------------------------------------------  // acclient.c:836860
void __cdecl _E340_10()
{
  char *v0; // esi@1

  v0 = &Offset_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731C90) --------------------------------------------------------  // acclient.c:836873
void __cdecl _E343_7()
{
  char *v0; // esi@1

  v0 = &Quaternion_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731CC0) --------------------------------------------------------  // acclient.c:836886
void __cdecl _E346_7()
{
  char *v0; // esi@1

  v0 = &Rotation_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731CF0) --------------------------------------------------------  // acclient.c:836899
void __cdecl _E349_7()
{
  char *v0; // esi@1

  v0 = &STime_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731D20) --------------------------------------------------------  // acclient.c:836912
void __cdecl _E352_7()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731D50) --------------------------------------------------------  // acclient.c:836925
void __cdecl _E355_7()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731D80) --------------------------------------------------------  // acclient.c:836938
void __cdecl _E358_7()
{
  char *v0; // esi@1

  v0 = &LowPt_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731DB0) --------------------------------------------------------  // acclient.c:836951
void __cdecl _E361_7()
{
  char *v0; // esi@1

  v0 = &Radius_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731DE0) --------------------------------------------------------  // acclient.c:836964
void __cdecl _E364_7()
{
  char *v0; // esi@1

  v0 = &Height_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731E10) --------------------------------------------------------  // acclient.c:836977
void __cdecl _E367_7()
{
  char *v0; // esi@1

  v0 = &Texture2D_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731E40) --------------------------------------------------------  // acclient.c:836990
void __cdecl _E370_7()
{
  char *v0; // esi@1

  v0 = &Texture3D_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731E70) --------------------------------------------------------  // acclient.c:837003
void __cdecl _E373_7()
{
  char *v0; // esi@1

  v0 = &TextureCube_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731EA0) --------------------------------------------------------  // acclient.c:837016
void __cdecl _E376_7()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731ED0) --------------------------------------------------------  // acclient.c:837029
void __cdecl _E379_7()
{
  char *v0; // esi@1

  v0 = &MovieFileName_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731F00) --------------------------------------------------------  // acclient.c:837042
void __cdecl _E382_7()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731F30) --------------------------------------------------------  // acclient.c:837055
void __cdecl _E385_7()
{
  char *v0; // esi@1

  v0 = &Levels_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731F60) --------------------------------------------------------  // acclient.c:837068
void __cdecl _E388_7()
{
  char *v0; // esi@1

  v0 = &NodeName_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731F90) --------------------------------------------------------  // acclient.c:837081
void __cdecl _E391_7()
{
  char *v0; // esi@1

  v0 = &Material_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731FC0) --------------------------------------------------------  // acclient.c:837094
void __cdecl _E394_7()
{
  char *v0; // esi@1

  v0 = &MaterialType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00731FF0) --------------------------------------------------------  // acclient.c:837107
void __cdecl _E397_7()
{
  char *v0; // esi@1

  v0 = &Modifier_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732020) --------------------------------------------------------  // acclient.c:837120
void __cdecl _E400_7()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732050) --------------------------------------------------------  // acclient.c:837133
void __cdecl _E403_7()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732080) --------------------------------------------------------  // acclient.c:837146
void __cdecl _E406_7()
{
  char *v0; // esi@1

  v0 = &NodeName_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007320B0) --------------------------------------------------------  // acclient.c:837159
void __cdecl _E409_7()
{
  char *v0; // esi@1

  v0 = &SortMode_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007320E0) --------------------------------------------------------  // acclient.c:837172
void __cdecl _E412_7()
{
  char *v0; // esi@1

  v0 = &SortMode_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732110) --------------------------------------------------------  // acclient.c:837185
void __cdecl _E415_7()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732140) --------------------------------------------------------  // acclient.c:837198
void __cdecl _E418_7()
{
  char *v0; // esi@1

  v0 = &NodeName_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732170) --------------------------------------------------------  // acclient.c:837211
void __cdecl _E421_7()
{
  char *v0; // esi@1

  v0 = &NodeName_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007321A0) --------------------------------------------------------  // acclient.c:837224
void __cdecl _E424_7()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007321D0) --------------------------------------------------------  // acclient.c:837237
void __cdecl _E427_7()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732200) --------------------------------------------------------  // acclient.c:837250
void __cdecl _E430_7()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732230) --------------------------------------------------------  // acclient.c:837263
void __cdecl _E433_7()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732260) --------------------------------------------------------  // acclient.c:837276
void __cdecl _E436_7()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732290) --------------------------------------------------------  // acclient.c:837289
void __cdecl _E439_7()
{
  char *v0; // esi@1

  v0 = &NodeName_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007322C0) --------------------------------------------------------  // acclient.c:837302
void __cdecl _E442_7()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007322F0) --------------------------------------------------------  // acclient.c:837315
void __cdecl _E445_7()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732320) --------------------------------------------------------  // acclient.c:837328
void __cdecl _E448_7()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732350) --------------------------------------------------------  // acclient.c:837341
void __cdecl _E451_7()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732380) --------------------------------------------------------  // acclient.c:837354
void __cdecl _E454_7()
{
  char *v0; // esi@1

  v0 = &TrueFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007323B0) --------------------------------------------------------  // acclient.c:837367
void __cdecl _E457_7()
{
  char *v0; // esi@1

  v0 = &FalseFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007323E0) --------------------------------------------------------  // acclient.c:837380
void __cdecl _E460_7()
{
  char *v0; // esi@1

  v0 = &RenderPass_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732410) --------------------------------------------------------  // acclient.c:837393
void __cdecl _E463_7()
{
  char *v0; // esi@1

  v0 = &Blend_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732440) --------------------------------------------------------  // acclient.c:837406
void __cdecl _E466_7()
{
  char *v0; // esi@1

  v0 = &DepthTest_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732470) --------------------------------------------------------  // acclient.c:837419
void __cdecl _E469_7()
{
  char *v0; // esi@1

  v0 = &DepthWrite_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007324A0) --------------------------------------------------------  // acclient.c:837432
void __cdecl _E472_7()
{
  char *v0; // esi@1

  v0 = &CullMode_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007324D0) --------------------------------------------------------  // acclient.c:837445
void __cdecl _E475_7()
{
  char *v0; // esi@1

  v0 = &DepthFog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732500) --------------------------------------------------------  // acclient.c:837458
void __cdecl _E478_7()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732530) --------------------------------------------------------  // acclient.c:837471
void __cdecl _E481_7()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732560) --------------------------------------------------------  // acclient.c:837484
void __cdecl _E484_7()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732590) --------------------------------------------------------  // acclient.c:837497
void __cdecl _E487_7()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007325C0) --------------------------------------------------------  // acclient.c:837510
void __cdecl _E490_7()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007325F0) --------------------------------------------------------  // acclient.c:837523
void __cdecl _E493_7()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732620) --------------------------------------------------------  // acclient.c:837536
void __cdecl _E496_7()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732650) --------------------------------------------------------  // acclient.c:837549
void __cdecl _E499_7()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732680) --------------------------------------------------------  // acclient.c:837562
void __cdecl _E502_7()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007326B0) --------------------------------------------------------  // acclient.c:837575
void __cdecl _E505_7()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007326E0) --------------------------------------------------------  // acclient.c:837588
void __cdecl _E508_7()
{
  char *v0; // esi@1

  v0 = &Ambient_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732710) --------------------------------------------------------  // acclient.c:837601
void __cdecl _E511_7()
{
  char *v0; // esi@1

  v0 = &Diffuse_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732740) --------------------------------------------------------  // acclient.c:837614
void __cdecl _E514_7()
{
  char *v0; // esi@1

  v0 = &Specular_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732770) --------------------------------------------------------  // acclient.c:837627
void __cdecl _E517_7()
{
  char *v0; // esi@1

  v0 = &SpecularPower_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007327A0) --------------------------------------------------------  // acclient.c:837640
void __cdecl _E520_7()
{
  char *v0; // esi@1

  v0 = &Dye_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007327D0) --------------------------------------------------------  // acclient.c:837653
void __cdecl _E523_7()
{
  char *v0; // esi@1

  v0 = &Emissive_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732800) --------------------------------------------------------  // acclient.c:837666
void __cdecl _E526_7()
{
  char *v0; // esi@1

  v0 = &VertexFormat_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732830) --------------------------------------------------------  // acclient.c:837679
void __cdecl _E529_7()
{
  char *v0; // esi@1

  v0 = &VertexShader_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732860) --------------------------------------------------------  // acclient.c:837692
void __cdecl _E532_7()
{
  char *v0; // esi@1

  v0 = &PixelShader_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732890) --------------------------------------------------------  // acclient.c:837705
void __cdecl _E535_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007328C0) --------------------------------------------------------  // acclient.c:837718
void __cdecl _E538_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007328F0) --------------------------------------------------------  // acclient.c:837731
void __cdecl _E541_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732920) --------------------------------------------------------  // acclient.c:837744
void __cdecl _E544_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732950) --------------------------------------------------------  // acclient.c:837757
void __cdecl _E547_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732980) --------------------------------------------------------  // acclient.c:837770
void __cdecl _E550_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007329B0) --------------------------------------------------------  // acclient.c:837783
void __cdecl _E553_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007329E0) --------------------------------------------------------  // acclient.c:837796
void __cdecl _E556_7()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732A10) --------------------------------------------------------  // acclient.c:837809
void __cdecl _E559_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732A40) --------------------------------------------------------  // acclient.c:837822
void __cdecl _E562_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732A70) --------------------------------------------------------  // acclient.c:837835
void __cdecl _E565_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732AA0) --------------------------------------------------------  // acclient.c:837848
void __cdecl _E568_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732AD0) --------------------------------------------------------  // acclient.c:837861
void __cdecl _E571_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732B00) --------------------------------------------------------  // acclient.c:837874
void __cdecl _E574_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732B30) --------------------------------------------------------  // acclient.c:837887
void __cdecl _E577_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732B60) --------------------------------------------------------  // acclient.c:837900
void __cdecl _E580_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732B90) --------------------------------------------------------  // acclient.c:837913
void __cdecl _E583_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732BC0) --------------------------------------------------------  // acclient.c:837926
void __cdecl _E586_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732BF0) --------------------------------------------------------  // acclient.c:837939
void __cdecl _E589_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732C20) --------------------------------------------------------  // acclient.c:837952
void __cdecl _E592_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732C50) --------------------------------------------------------  // acclient.c:837965
void __cdecl _E595_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732C80) --------------------------------------------------------  // acclient.c:837978
void __cdecl _E598_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732CB0) --------------------------------------------------------  // acclient.c:837991
void __cdecl _E601_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732CE0) --------------------------------------------------------  // acclient.c:838004
void __cdecl _E604_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732D10) --------------------------------------------------------  // acclient.c:838017
void __cdecl _E607_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732D40) --------------------------------------------------------  // acclient.c:838030
void __cdecl _E610_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732D70) --------------------------------------------------------  // acclient.c:838043
void __cdecl _E613_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732DA0) --------------------------------------------------------  // acclient.c:838056
void __cdecl _E616_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732DD0) --------------------------------------------------------  // acclient.c:838069
void __cdecl _E619_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732E00) --------------------------------------------------------  // acclient.c:838082
void __cdecl _E622_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732E30) --------------------------------------------------------  // acclient.c:838095
void __cdecl _E625_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732E60) --------------------------------------------------------  // acclient.c:838108
void __cdecl _E628_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732E90) --------------------------------------------------------  // acclient.c:838121
void __cdecl _E631_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732EC0) --------------------------------------------------------  // acclient.c:838134
void __cdecl _E634_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732EF0) --------------------------------------------------------  // acclient.c:838147
void __cdecl _E637_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732F20) --------------------------------------------------------  // acclient.c:838160
void __cdecl _E640_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732F50) --------------------------------------------------------  // acclient.c:838173
void __cdecl _E643_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732F80) --------------------------------------------------------  // acclient.c:838186
void __cdecl _E646_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732FB0) --------------------------------------------------------  // acclient.c:838199
void __cdecl _E649_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00732FE0) --------------------------------------------------------  // acclient.c:838212
void __cdecl _E652_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733010) --------------------------------------------------------  // acclient.c:838225
void __cdecl _E655_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733040) --------------------------------------------------------  // acclient.c:838238
void __cdecl _E658_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733070) --------------------------------------------------------  // acclient.c:838251
void __cdecl _E661_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007330A0) --------------------------------------------------------  // acclient.c:838264
void __cdecl _E664_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007330D0) --------------------------------------------------------  // acclient.c:838277
void __cdecl _E667_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733100) --------------------------------------------------------  // acclient.c:838290
void __cdecl _E670_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733130) --------------------------------------------------------  // acclient.c:838303
void __cdecl _E673_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733160) --------------------------------------------------------  // acclient.c:838316
void __cdecl _E676_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733190) --------------------------------------------------------  // acclient.c:838329
void __cdecl _E679_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007331C0) --------------------------------------------------------  // acclient.c:838342
void __cdecl _E682_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007331F0) --------------------------------------------------------  // acclient.c:838355
void __cdecl _E685_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733220) --------------------------------------------------------  // acclient.c:838368
void __cdecl _E688_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733250) --------------------------------------------------------  // acclient.c:838381
void __cdecl _E691_7()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733280) --------------------------------------------------------  // acclient.c:838394
void __cdecl _E694_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007332B0) --------------------------------------------------------  // acclient.c:838407
void __cdecl _E697_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007332E0) --------------------------------------------------------  // acclient.c:838420
void __cdecl _E700_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733310) --------------------------------------------------------  // acclient.c:838433
void __cdecl _E703_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733340) --------------------------------------------------------  // acclient.c:838446
void __cdecl _E706_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733370) --------------------------------------------------------  // acclient.c:838459
void __cdecl _E709_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007333A0) --------------------------------------------------------  // acclient.c:838472
void __cdecl _E712_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007333D0) --------------------------------------------------------  // acclient.c:838485
void __cdecl _E715_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733400) --------------------------------------------------------  // acclient.c:838498
void __cdecl _E718_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733430) --------------------------------------------------------  // acclient.c:838511
void __cdecl _E721_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733460) --------------------------------------------------------  // acclient.c:838524
void __cdecl _E724_7()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733490) --------------------------------------------------------  // acclient.c:838537
void __cdecl _E727_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007334C0) --------------------------------------------------------  // acclient.c:838550
void __cdecl _E730_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007334F0) --------------------------------------------------------  // acclient.c:838563
void __cdecl _E733_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733520) --------------------------------------------------------  // acclient.c:838576
void __cdecl _E736_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733550) --------------------------------------------------------  // acclient.c:838589
void __cdecl _E739_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733580) --------------------------------------------------------  // acclient.c:838602
void __cdecl _E742_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007335B0) --------------------------------------------------------  // acclient.c:838615
void __cdecl _E745_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007335E0) --------------------------------------------------------  // acclient.c:838628
void __cdecl _E748_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733610) --------------------------------------------------------  // acclient.c:838641
void __cdecl _E751_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733640) --------------------------------------------------------  // acclient.c:838654
void __cdecl _E754_7()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733670) --------------------------------------------------------  // acclient.c:838667
void __cdecl _E757_7()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007336A0) --------------------------------------------------------  // acclient.c:838680
void __cdecl _E760_7()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007336D0) --------------------------------------------------------  // acclient.c:838693
void __cdecl _E763_7()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733700) --------------------------------------------------------  // acclient.c:838706
void __cdecl _E766_7()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733730) --------------------------------------------------------  // acclient.c:838719
void __cdecl _E769_7()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733760) --------------------------------------------------------  // acclient.c:838732
void __cdecl _E772_7()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733790) --------------------------------------------------------  // acclient.c:838745
void __cdecl _E775_7()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007337C0) --------------------------------------------------------  // acclient.c:838758
void __cdecl _E778_7()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007337F0) --------------------------------------------------------  // acclient.c:838771
void __cdecl _E781_7()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733820) --------------------------------------------------------  // acclient.c:838784
void __cdecl _E784_7()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733850) --------------------------------------------------------  // acclient.c:838797
void __cdecl _E787_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733880) --------------------------------------------------------  // acclient.c:838810
void __cdecl _E790_7()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007338B0) --------------------------------------------------------  // acclient.c:838823
void __cdecl _E793_7()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007338E0) --------------------------------------------------------  // acclient.c:838836
void __cdecl _E796_7()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733910) --------------------------------------------------------  // acclient.c:838849
void __cdecl _E799_7()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733940) --------------------------------------------------------  // acclient.c:838862
void __cdecl _E802_7()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733970) --------------------------------------------------------  // acclient.c:838875
void __cdecl _E805_7()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007339A0) --------------------------------------------------------  // acclient.c:838888
void __cdecl _E808_7()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007339D0) --------------------------------------------------------  // acclient.c:838901
void __cdecl _E811_7()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733A00) --------------------------------------------------------  // acclient.c:838914
void __cdecl _E814_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733A30) --------------------------------------------------------  // acclient.c:838927
void __cdecl _E817_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733A60) --------------------------------------------------------  // acclient.c:838940
void __cdecl _E820_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733A90) --------------------------------------------------------  // acclient.c:838953
void __cdecl _E823_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733AC0) --------------------------------------------------------  // acclient.c:838966
void __cdecl _E826_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733AF0) --------------------------------------------------------  // acclient.c:838979
void __cdecl _E829_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733B20) --------------------------------------------------------  // acclient.c:838992
void __cdecl _E832_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733B50) --------------------------------------------------------  // acclient.c:839005
void __cdecl _E835_7()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733B80) --------------------------------------------------------  // acclient.c:839018
void __cdecl _E838_7()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733BB0) --------------------------------------------------------  // acclient.c:839031
void __cdecl _E841_7()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733BE0) --------------------------------------------------------  // acclient.c:839044
void __cdecl _E844_7()
{
  char *v0; // esi@1

  v0 = &NodeName_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733C10) --------------------------------------------------------  // acclient.c:839057
void __cdecl _E847_7()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733C40) --------------------------------------------------------  // acclient.c:839070
void __cdecl _E850_7()
{
  char *v0; // esi@1

  v0 = &SamplerName_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733C70) --------------------------------------------------------  // acclient.c:839083
void __cdecl _E853_7()
{
  char *v0; // esi@1

  v0 = &Texture_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733CA0) --------------------------------------------------------  // acclient.c:839096
void __cdecl _E856_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733CD0) --------------------------------------------------------  // acclient.c:839109
void __cdecl _E859_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733D00) --------------------------------------------------------  // acclient.c:839122
void __cdecl _E862_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733D30) --------------------------------------------------------  // acclient.c:839135
void __cdecl _E865_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733D60) --------------------------------------------------------  // acclient.c:839148
void __cdecl _E868_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733D90) --------------------------------------------------------  // acclient.c:839161
void __cdecl _E871_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733DC0) --------------------------------------------------------  // acclient.c:839174
void __cdecl _E874_7()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733DF0) --------------------------------------------------------  // acclient.c:839187
void __cdecl _E877_7()
{
  char *v0; // esi@1

  v0 = &AddressMode_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733E20) --------------------------------------------------------  // acclient.c:839200
void __cdecl _E880_7()
{
  char *v0; // esi@1

  v0 = &TexFilter_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733E50) --------------------------------------------------------  // acclient.c:839213
void __cdecl _E883_7()
{
  char *v0; // esi@1

  v0 = &ColorOp_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733E80) --------------------------------------------------------  // acclient.c:839226
void __cdecl _E886_7()
{
  char *v0; // esi@1

  v0 = &ColorArg1_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733EB0) --------------------------------------------------------  // acclient.c:839239
void __cdecl _E889_7()
{
  char *v0; // esi@1

  v0 = &ColorArg2_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733EE0) --------------------------------------------------------  // acclient.c:839252
void __cdecl _E892_7()
{
  char *v0; // esi@1

  v0 = &AlphaOp_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733F10) --------------------------------------------------------  // acclient.c:839265
void __cdecl _E895_7()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733F40) --------------------------------------------------------  // acclient.c:839278
void __cdecl _E898_7()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733F70) --------------------------------------------------------  // acclient.c:839291
void __cdecl _E901_7()
{
  char *v0; // esi@1

  v0 = &TexCoord_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733FA0) --------------------------------------------------------  // acclient.c:839304
void __cdecl _E904_7()
{
  char *v0; // esi@1

  v0 = &UseProjection_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00733FD0) --------------------------------------------------------  // acclient.c:839317
void __cdecl _E907_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734000) --------------------------------------------------------  // acclient.c:839330
void __cdecl _E910_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734030) --------------------------------------------------------  // acclient.c:839343
void __cdecl _E913_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734060) --------------------------------------------------------  // acclient.c:839356
void __cdecl _E916_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734090) --------------------------------------------------------  // acclient.c:839369
void __cdecl _E919_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007340C0) --------------------------------------------------------  // acclient.c:839382
void __cdecl _E922_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007340F0) --------------------------------------------------------  // acclient.c:839395
void __cdecl _E925_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734120) --------------------------------------------------------  // acclient.c:839408
void __cdecl _E928_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734150) --------------------------------------------------------  // acclient.c:839421
void __cdecl _E931_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734180) --------------------------------------------------------  // acclient.c:839434
void __cdecl _E934_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007341B0) --------------------------------------------------------  // acclient.c:839447
void __cdecl _E937_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007341E0) --------------------------------------------------------  // acclient.c:839460
void __cdecl _E940_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734210) --------------------------------------------------------  // acclient.c:839473
void __cdecl _E943_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734240) --------------------------------------------------------  // acclient.c:839486
void __cdecl _E946_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734270) --------------------------------------------------------  // acclient.c:839499
void __cdecl _E949_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007342A0) --------------------------------------------------------  // acclient.c:839512
void __cdecl _E952_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007342D0) --------------------------------------------------------  // acclient.c:839525
void __cdecl _E955_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734300) --------------------------------------------------------  // acclient.c:839538
void __cdecl _E958_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734330) --------------------------------------------------------  // acclient.c:839551
void __cdecl _E961_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734360) --------------------------------------------------------  // acclient.c:839564
void __cdecl _E964_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734390) --------------------------------------------------------  // acclient.c:839577
void __cdecl _E967_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007343C0) --------------------------------------------------------  // acclient.c:839590
void __cdecl _E970_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007343F0) --------------------------------------------------------  // acclient.c:839603
void __cdecl _E973_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734420) --------------------------------------------------------  // acclient.c:839616
void __cdecl _E976_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734450) --------------------------------------------------------  // acclient.c:839629
void __cdecl _E979_7()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734480) --------------------------------------------------------  // acclient.c:839642
void __cdecl _E982_7()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007344B0) --------------------------------------------------------  // acclient.c:839655
void __cdecl _E985_7()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007344E0) --------------------------------------------------------  // acclient.c:839668
void __cdecl _E988_7()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734510) --------------------------------------------------------  // acclient.c:839681
void __cdecl _E991_7()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734540) --------------------------------------------------------  // acclient.c:839694
void __cdecl _E994_7()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734570) --------------------------------------------------------  // acclient.c:839707
void __cdecl _E997_7()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007345A0) --------------------------------------------------------  // acclient.c:839720
void __cdecl _E1000_7()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007345D0) --------------------------------------------------------  // acclient.c:839733
void __cdecl _E1003_7()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734600) --------------------------------------------------------  // acclient.c:839746
void __cdecl _E1006_7()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734630) --------------------------------------------------------  // acclient.c:839759
void __cdecl _E1009_7()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734660) --------------------------------------------------------  // acclient.c:839772
void __cdecl _E1012_7()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734690) --------------------------------------------------------  // acclient.c:839785
void __cdecl _E1015_7()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007346C0) --------------------------------------------------------  // acclient.c:839798
void __cdecl _E1018_7()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007346F0) --------------------------------------------------------  // acclient.c:839811
void __cdecl _E1021_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734720) --------------------------------------------------------  // acclient.c:839824
void __cdecl _E1024_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734750) --------------------------------------------------------  // acclient.c:839837
void __cdecl _E1027_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734780) --------------------------------------------------------  // acclient.c:839850
void __cdecl _E1030_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007347B0) --------------------------------------------------------  // acclient.c:839863
void __cdecl _E1033_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007347E0) --------------------------------------------------------  // acclient.c:839876
void __cdecl _E1036_7()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734810) --------------------------------------------------------  // acclient.c:839889
void __cdecl _E1039_7()
{
  char *v0; // esi@1

  v0 = &NodeName_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734840) --------------------------------------------------------  // acclient.c:839902
void __cdecl _E1042_7()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734870) --------------------------------------------------------  // acclient.c:839915
void __cdecl _E1045_7()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007348A0) --------------------------------------------------------  // acclient.c:839928
void __cdecl _E1048_7()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007348D0) --------------------------------------------------------  // acclient.c:839941
void __cdecl _E1051_7()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734900) --------------------------------------------------------  // acclient.c:839954
void __cdecl _E1054_7()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734930) --------------------------------------------------------  // acclient.c:839967
void __cdecl _E1057_7()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734960) --------------------------------------------------------  // acclient.c:839980
void __cdecl _E1060_7()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734990) --------------------------------------------------------  // acclient.c:839993
void __cdecl _E1063_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007349C0) --------------------------------------------------------  // acclient.c:840006
void __cdecl _E1066_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007349F0) --------------------------------------------------------  // acclient.c:840019
void __cdecl _E1069_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734A20) --------------------------------------------------------  // acclient.c:840032
void __cdecl _E1072_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734A50) --------------------------------------------------------  // acclient.c:840045
void __cdecl _E1075_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734A80) --------------------------------------------------------  // acclient.c:840058
void __cdecl _E1078_7()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734AB0) --------------------------------------------------------  // acclient.c:840071
void __cdecl _E1081_7()
{
  char *v0; // esi@1

  v0 = &NodeName_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734AE0) --------------------------------------------------------  // acclient.c:840084
void __cdecl _E1084_7()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734B10) --------------------------------------------------------  // acclient.c:840097
void __cdecl _E1087_7()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734B40) --------------------------------------------------------  // acclient.c:840110
void __cdecl _E1090_7()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734B70) --------------------------------------------------------  // acclient.c:840123
void __cdecl _E1093_7()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734BA0) --------------------------------------------------------  // acclient.c:840136
void __cdecl _E1096_7()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734BD0) --------------------------------------------------------  // acclient.c:840149
void __cdecl _E1099_7()
{
  char *v0; // esi@1

  v0 = &ScaleType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734C00) --------------------------------------------------------  // acclient.c:840162
void __cdecl _E1102_7()
{
  char *v0; // esi@1

  v0 = &WorldSpace_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734C30) --------------------------------------------------------  // acclient.c:840175
void __cdecl _E1105_7()
{
  char *v0; // esi@1

  v0 = &ForceDraw_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734C60) --------------------------------------------------------  // acclient.c:840188
void __cdecl _E1108_7()
{
  char *v0; // esi@1

  v0 = &NumEmitters_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734C90) --------------------------------------------------------  // acclient.c:840201
void __cdecl _E1111_7()
{
  char *v0; // esi@1

  v0 = &Material_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734CC0) --------------------------------------------------------  // acclient.c:840214
void __cdecl _E1114_7()
{
  char *v0; // esi@1

  v0 = &Version_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734CF0) --------------------------------------------------------  // acclient.c:840227
void __cdecl _E1117_7()
{
  char *v0; // esi@1

  v0 = &MaxParticles_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734D20) --------------------------------------------------------  // acclient.c:840240
void __cdecl _E1120_7()
{
  char *v0; // esi@1

  v0 = &NodeName_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734D50) --------------------------------------------------------  // acclient.c:840253
void __cdecl _E1123_7()
{
  char *v0; // esi@1

  v0 = &Origin_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734D80) --------------------------------------------------------  // acclient.c:840266
void __cdecl _E1126_7()
{
  char *v0; // esi@1

  v0 = &Shape_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734DB0) --------------------------------------------------------  // acclient.c:840279
void __cdecl _E1129_7()
{
  char *v0; // esi@1

  v0 = &Shape_Point_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734DE0) --------------------------------------------------------  // acclient.c:840292
void __cdecl _E1132_7()
{
  char *v0; // esi@1

  v0 = &Shape_Line_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734E10) --------------------------------------------------------  // acclient.c:840305
void __cdecl _E1135_7()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734E40) --------------------------------------------------------  // acclient.c:840318
void __cdecl _E1138_7()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734E70) --------------------------------------------------------  // acclient.c:840331
void __cdecl _E1141_7()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734EA0) --------------------------------------------------------  // acclient.c:840344
void __cdecl _E1144_7()
{
  char *v0; // esi@1

  v0 = &ParticleShape_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734ED0) --------------------------------------------------------  // acclient.c:840357
void __cdecl _E1147_7()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734F00) --------------------------------------------------------  // acclient.c:840370
void __cdecl _E1150_7()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734F30) --------------------------------------------------------  // acclient.c:840383
void __cdecl _E1153_7()
{
  char *v0; // esi@1

  v0 = &Streak_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734F60) --------------------------------------------------------  // acclient.c:840396
void __cdecl _E1156_7()
{
  char *v0; // esi@1

  v0 = &Rotation_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734F90) --------------------------------------------------------  // acclient.c:840409
void __cdecl _E1159_7()
{
  char *v0; // esi@1

  v0 = &WorldRotation_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734FC0) --------------------------------------------------------  // acclient.c:840422
void __cdecl _E1162_7()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00734FF0) --------------------------------------------------------  // acclient.c:840435
void __cdecl _E1165_7()
{
  char *v0; // esi@1

  v0 = &ParticleScale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735020) --------------------------------------------------------  // acclient.c:840448
void __cdecl _E1168_7()
{
  char *v0; // esi@1

  v0 = &Scale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735050) --------------------------------------------------------  // acclient.c:840461
void __cdecl _E1171_7()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735080) --------------------------------------------------------  // acclient.c:840474
void __cdecl _E1174_7()
{
  char *v0; // esi@1

  v0 = &BirthRate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007350B0) --------------------------------------------------------  // acclient.c:840487
void __cdecl _E1177_7()
{
  char *v0; // esi@1

  v0 = &Lifespan_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007350E0) --------------------------------------------------------  // acclient.c:840500
void __cdecl _E1180_7()
{
  char *v0; // esi@1

  v0 = &Velocity_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735110) --------------------------------------------------------  // acclient.c:840513
void __cdecl _E1183_7()
{
  char *v0; // esi@1

  v0 = &Direction_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735140) --------------------------------------------------------  // acclient.c:840526
void __cdecl _E1186_7()
{
  char *v0; // esi@1

  v0 = &MinSpread_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735170) --------------------------------------------------------  // acclient.c:840539
void __cdecl _E1189_7()
{
  char *v0; // esi@1

  v0 = &MaxSpread_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007351A0) --------------------------------------------------------  // acclient.c:840552
void __cdecl _E1192_7()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007351D0) --------------------------------------------------------  // acclient.c:840565
void __cdecl _E1195_7()
{
  char *v0; // esi@1

  v0 = &BlastCount_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735200) --------------------------------------------------------  // acclient.c:840578
void __cdecl _E1198_7()
{
  char *v0; // esi@1

  v0 = &StartTime_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735230) --------------------------------------------------------  // acclient.c:840591
void __cdecl _E1201_7()
{
  char *v0; // esi@1

  v0 = &TimeLimit_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735260) --------------------------------------------------------  // acclient.c:840604
void __cdecl _E1204_7()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735290) --------------------------------------------------------  // acclient.c:840617
void __cdecl _E1207_7()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007352C0) --------------------------------------------------------  // acclient.c:840630
void __cdecl _E1210_7()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007352F0) --------------------------------------------------------  // acclient.c:840643
void __cdecl _E1213_7()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735320) --------------------------------------------------------  // acclient.c:840656
void __cdecl _E1216_7()
{
  char *v0; // esi@1

  v0 = &IsActive_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735350) --------------------------------------------------------  // acclient.c:840669
void __cdecl _E1219_7()
{
  char *v0; // esi@1

  v0 = &FadeIn_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735380) --------------------------------------------------------  // acclient.c:840682
void __cdecl _E1222_7()
{
  char *v0; // esi@1

  v0 = &FadeOut_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007353B0) --------------------------------------------------------  // acclient.c:840695
void __cdecl _E1225_7()
{
  char *v0; // esi@1

  v0 = &ConstrainX_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007353E0) --------------------------------------------------------  // acclient.c:840708
void __cdecl _E1228_7()
{
  char *v0; // esi@1

  v0 = &ConstrainY_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735410) --------------------------------------------------------  // acclient.c:840721
void __cdecl _E1231_7()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735440) --------------------------------------------------------  // acclient.c:840734
void __cdecl _E1234_7()
{
  char *v0; // esi@1

  v0 = &NodeName_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735470) --------------------------------------------------------  // acclient.c:840747
void __cdecl _E1237_7()
{
  char *v0; // esi@1

  v0 = &Time_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007354A0) --------------------------------------------------------  // acclient.c:840760
void __cdecl _E1240_7()
{
  char *v0; // esi@1

  v0 = &Flags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007354D0) --------------------------------------------------------  // acclient.c:840773
void __cdecl _E1243_7()
{
  char *v0; // esi@1

  v0 = &Flags_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735500) --------------------------------------------------------  // acclient.c:840786
void __cdecl _E1246_7()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735530) --------------------------------------------------------  // acclient.c:840799
void __cdecl _E1249_7()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735560) --------------------------------------------------------  // acclient.c:840812
void __cdecl _E1252_7()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735590) --------------------------------------------------------  // acclient.c:840825
void __cdecl _E1255_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007355C0) --------------------------------------------------------  // acclient.c:840838
void __cdecl _E1258_6()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007355F0) --------------------------------------------------------  // acclient.c:840851
void __cdecl _E1261_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735620) --------------------------------------------------------  // acclient.c:840864
void __cdecl _E1264_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735650) --------------------------------------------------------  // acclient.c:840877
void __cdecl _E1267_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735680) --------------------------------------------------------  // acclient.c:840890
void __cdecl _E1270_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007356B0) --------------------------------------------------------  // acclient.c:840903
void __cdecl _E1273_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007356E0) --------------------------------------------------------  // acclient.c:840916
void __cdecl _E1276_6()
{
  char *v0; // esi@1

  v0 = &Scale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735710) --------------------------------------------------------  // acclient.c:840929
void __cdecl _E1279_5()
{
  char *v0; // esi@1

  v0 = &ScaleX_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735740) --------------------------------------------------------  // acclient.c:840942
void __cdecl _E1282_6()
{
  char *v0; // esi@1

  v0 = &ScaleY_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735770) --------------------------------------------------------  // acclient.c:840955
void __cdecl _E1285_5()
{
  char *v0; // esi@1

  v0 = &Color_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007357A0) --------------------------------------------------------  // acclient.c:840968
void __cdecl _E1288_5()
{
  char *v0; // esi@1

  v0 = &Mass_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007357D0) --------------------------------------------------------  // acclient.c:840981
void __cdecl _E1291_4()
{
  char *v0; // esi@1

  v0 = &PFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735800) --------------------------------------------------------  // acclient.c:840994
void __cdecl _E1294_5()
{
  char *v0; // esi@1

  v0 = &PFlags_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735830) --------------------------------------------------------  // acclient.c:841007
void __cdecl _E1297_4()
{
  char *v0; // esi@1

  v0 = &PCType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735860) --------------------------------------------------------  // acclient.c:841020
void __cdecl _E1300_4()
{
  char *v0; // esi@1

  v0 = &PCType_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735890) --------------------------------------------------------  // acclient.c:841033
void __cdecl _E1303_3()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007358C0) --------------------------------------------------------  // acclient.c:841046
void __cdecl _E1306_2()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007358F0) --------------------------------------------------------  // acclient.c:841059
void __cdecl _E1309_2()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735920) --------------------------------------------------------  // acclient.c:841072
void __cdecl _E1312_2()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735950) --------------------------------------------------------  // acclient.c:841085
void __cdecl _E1315_0()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735980) --------------------------------------------------------  // acclient.c:841098
void __cdecl _E1318_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007359B0) --------------------------------------------------------  // acclient.c:841111
void __cdecl _E1321_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007359E0) --------------------------------------------------------  // acclient.c:841124
void __cdecl _E1324_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735A10) --------------------------------------------------------  // acclient.c:841137
void __cdecl _E1327_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735A40) --------------------------------------------------------  // acclient.c:841150
void __cdecl _E1330_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735A70) --------------------------------------------------------  // acclient.c:841163
void __cdecl _E1333_0()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735AA0) --------------------------------------------------------  // acclient.c:841176
void __cdecl _E1336_0()
{
  char *v0; // esi@1

  v0 = &Position_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735AD0) --------------------------------------------------------  // acclient.c:841189
void __cdecl _E1339_0()
{
  char *v0; // esi@1

  v0 = &PointList_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735B00) --------------------------------------------------------  // acclient.c:841202
void __cdecl _E1342_0()
{
  char *v0; // esi@1

  v0 = &Point_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735B30) --------------------------------------------------------  // acclient.c:841215
void __cdecl _E1345_0()
{
  char *v0; // esi@1

  v0 = &DetailLevels_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735B60) --------------------------------------------------------  // acclient.c:841228
void __cdecl _E1348_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735B90) --------------------------------------------------------  // acclient.c:841241
void __cdecl _E1351_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735BC0) --------------------------------------------------------  // acclient.c:841254
void __cdecl _E1354_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735BF0) --------------------------------------------------------  // acclient.c:841267
void __cdecl _E1357_0()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735C20) --------------------------------------------------------  // acclient.c:841280
void __cdecl _E1360_0()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735C50) --------------------------------------------------------  // acclient.c:841293
void __cdecl _E1363_0()
{
  char *v0; // esi@1

  v0 = &Point_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735C80) --------------------------------------------------------  // acclient.c:841306
void __cdecl _E1366_0()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735CB0) --------------------------------------------------------  // acclient.c:841319
void __cdecl _E1369_0()
{
  char *v0; // esi@1

  v0 = &PointTexture_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735CE0) --------------------------------------------------------  // acclient.c:841332
void __cdecl _E1372_0()
{
  char *v0; // esi@1

  v0 = &PointSize_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735D10) --------------------------------------------------------  // acclient.c:841345
void __cdecl _E1375_0()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735D40) --------------------------------------------------------  // acclient.c:841358
void __cdecl _E1378_0()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_839188;
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

//----- (00735D80) --------------------------------------------------------  // acclient.c:841383
void __cdecl sub_735D80()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735DB0) --------------------------------------------------------  // acclient.c:841396
void __cdecl sub_735DB0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735DE0) --------------------------------------------------------  // acclient.c:841409
void __cdecl sub_735DE0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735E10) --------------------------------------------------------  // acclient.c:841422
void __cdecl sub_735E10()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735E40) --------------------------------------------------------  // acclient.c:841435
void __cdecl sub_735E40()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735E70) --------------------------------------------------------  // acclient.c:841448
void __cdecl sub_735E70()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735EA0) --------------------------------------------------------  // acclient.c:841461
void __cdecl sub_735EA0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735ED0) --------------------------------------------------------  // acclient.c:841474
void __cdecl sub_735ED0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735F00) --------------------------------------------------------  // acclient.c:841487
void __cdecl _E124_96()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735F30) --------------------------------------------------------  // acclient.c:841500
void __cdecl _E127_86()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735F60) --------------------------------------------------------  // acclient.c:841513
void __cdecl _E130_78()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735F90) --------------------------------------------------------  // acclient.c:841526
void __cdecl _E133_71()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735FC0) --------------------------------------------------------  // acclient.c:841539
void __cdecl _E136_55()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00735FF0) --------------------------------------------------------  // acclient.c:841552
void __cdecl _E139_56()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736020) --------------------------------------------------------  // acclient.c:841565
void __cdecl _E142_53()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736050) --------------------------------------------------------  // acclient.c:841578
void __cdecl _E145_55()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736080) --------------------------------------------------------  // acclient.c:841591
void __cdecl _E148_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_7;
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

//----- (007360C0) --------------------------------------------------------  // acclient.c:841616
void __cdecl _E151_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_7;
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

//----- (00736100) --------------------------------------------------------  // acclient.c:841641
void __cdecl _E154_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_7;
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

//----- (00736140) --------------------------------------------------------  // acclient.c:841666
void __cdecl _E157_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_7;
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

//----- (00736180) --------------------------------------------------------  // acclient.c:841691
void __cdecl _E160_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_7;
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

//----- (007361C0) --------------------------------------------------------  // acclient.c:841716
void __cdecl _E163_46()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_13;
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

//----- (00736200) --------------------------------------------------------  // acclient.c:841741
void __cdecl _E166_48()
{
  char *v0; // esi@1

  v0 = &waveform_None_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736230) --------------------------------------------------------  // acclient.c:841754
void __cdecl _E169_47()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736260) --------------------------------------------------------  // acclient.c:841767
void __cdecl _E172_45()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736290) --------------------------------------------------------  // acclient.c:841780
void __cdecl _E175_42()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007362C0) --------------------------------------------------------  // acclient.c:841793
void __cdecl _E178_42()
{
  char *v0; // esi@1

  v0 = &waveform_Square_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007362F0) --------------------------------------------------------  // acclient.c:841806
void __cdecl _E181_42()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736320) --------------------------------------------------------  // acclient.c:841819
void __cdecl _E184_40()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736350) --------------------------------------------------------  // acclient.c:841832
void __cdecl _E187_39()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736380) --------------------------------------------------------  // acclient.c:841845
void __cdecl _E190_40()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

