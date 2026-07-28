/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderIndexBuffer
   Object     : ENGINE\render_base\RenderIndexBuffer.obj
   Functions  : 82
   Addresses  : 0044C8A0 - 00746320 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044C8A0) --------------------------------------------------------  // acclient.c:137559
void __thiscall RenderIndexBuffer::Begin(RenderIndexBuffer *this)
{
  this->m_nNumIndices = 0;
  this->m_nActualNumIndices = 0;
  this->indexSize = 2;
  this->indices = 0;
  this->staticData = 0;
  this->m_OnlyWriteOnce = 0;
  this->locked = 0;
  this->needRefresh = 0;
  this->m_bUseIndexCaching = 1;
  this->m_nMinVertexIndex = 0;
  this->m_nMaxVertexIndex = 0;
  this->m_bNeedRecalcMinMax = 0;
}

//----- (0044C8D0) --------------------------------------------------------  // acclient.c:137576
void __thiscall RenderIndexBuffer::End(RenderIndexBuffer *this)
{
  RenderIndexBuffer *v1; // esi@1

  v1 = this;
  if ( this->indices )
  {
    operator delete[](this->indices);
    v1->indices = 0;
  }
  v1->m_nNumIndices = 0;
  v1->m_nActualNumIndices = 0;
}

//----- (0044C900) --------------------------------------------------------  // acclient.c:137591
signed int __thiscall RenderIndexBuffer::Startup(RenderIndexBuffer *this, const unsigned int _nNumIndices, const char _indexSize, const bool _staticData, const bool _OnlyWriteOnce, const bool _bUseIndexCaching)
{
  RenderIndexBuffer *v6; // esi@1
  void *v7; // eax@2
  signed int result; // eax@4

  v6 = this;
  this->staticData = _staticData;
  this->m_nActualNumIndices = _nNumIndices;
  this->m_nNumIndices = _nNumIndices;
  this->indexSize = _indexSize;
  this->m_OnlyWriteOnce = _OnlyWriteOnce;
  if ( _indexSize == 2 )
    v7 = operator new[](2 * _nNumIndices);
  else
    v7 = operator new[](4 * _nNumIndices);
  v6->indices = (char *)v7;
  result = 1;
  v6->locked = 0;
  v6->needRefresh = 0;
  v6->m_nMinVertexIndex = 0;
  v6->m_nMaxVertexIndex = 0;
  v6->m_bNeedRecalcMinMax = 0;
  v6->m_bUseIndexCaching = _bUseIndexCaching;
  return result;
}

//----- (0044C960) --------------------------------------------------------  // acclient.c:137619
void __thiscall RenderIndexBuffer::Shutdown(RenderIndexBuffer *this)
{
  RenderIndexBuffer *v1; // esi@1

  v1 = this;
  if ( this->indices )
  {
    operator delete[](this->indices);
    v1->indices = 0;
  }
  v1->m_nNumIndices = 0;
  v1->m_nActualNumIndices = 0;
  v1->indices = 0;
  v1->staticData = 0;
  v1->m_OnlyWriteOnce = 0;
  v1->locked = 0;
  v1->needRefresh = 0;
  v1->m_nMinVertexIndex = 0;
  v1->m_nMaxVertexIndex = 0;
  v1->m_bNeedRecalcMinMax = 0;
  v1->indexSize = 2;
  v1->m_bUseIndexCaching = 1;
}

//----- (0044C9B0) --------------------------------------------------------  // acclient.c:137644
char *__thiscall RenderIndexBuffer::Lock(RenderIndexBuffer *this)
{
  char *result; // eax@1

  result = this->indices;
  this->locked = 1;
  return result;
}

//----- (0044C9C0) --------------------------------------------------------  // acclient.c:137654
void __thiscall RenderIndexBuffer::Unlock(RenderIndexBuffer *this)
{
  this->locked = 0;
  this->needRefresh = 1;
  this->m_bNeedRecalcMinMax = 1;
}

//----- (0044C9D0) --------------------------------------------------------  // acclient.c:137662
void __thiscall RenderIndexBuffer::RecalculateMinMaxIndices(RenderIndexBuffer *this)
{
  unsigned int *v1; // eax@3
  unsigned int v2; // edx@4
  unsigned int v3; // esi@5
  bool v4; // zf@5
  unsigned int v5; // edx@7
  unsigned int v6; // edx@9

  if ( !this->m_bNeedRecalcMinMax )
    return;
  if ( !this->m_bUseIndexCaching )
    return;
  v1 = (unsigned int *)this->indices;
  this->m_nMaxVertexIndex = 0;
  this->m_nMinVertexIndex = 0;
  if ( !v1 )
    return;
  v2 = this->m_nNumIndices;
  if ( !v2 )
    return;
  v3 = 0;
  v4 = this->indexSize == 2;
  this->m_nMinVertexIndex = -1;
  this->m_nMaxVertexIndex = 0;
  if ( !v4 )
  {
    if ( v2 > 0 )
    {
      do
      {
        if ( *v1 < this->m_nMinVertexIndex )
          this->m_nMinVertexIndex = *v1;
        if ( *v1 > this->m_nMaxVertexIndex )
          this->m_nMaxVertexIndex = *v1;
        ++v3;
        ++v1;
      }
      while ( v3 < this->m_nNumIndices );
    }
    goto LABEL_19;
  }
  if ( v2 <= 0 )
  {
LABEL_19:
    this->m_bNeedRecalcMinMax = 0;
    return;
  }
  do
  {
    v5 = *(_WORD *)v1;
    if ( v5 < this->m_nMinVertexIndex )
      this->m_nMinVertexIndex = v5;
    v6 = *(_WORD *)v1;
    if ( v6 > this->m_nMaxVertexIndex )
      this->m_nMaxVertexIndex = v6;
    ++v3;
    v1 = (unsigned int *)((char *)v1 + 2);
  }
  while ( v3 < this->m_nNumIndices );
  this->m_bNeedRecalcMinMax = 0;
}

//----- (0044CA70) --------------------------------------------------------  // acclient.c:137726
RenderIndexBuffer *__thiscall RenderIndexBuffer::vector_deleting_destructor(RenderIndexBuffer *this, unsigned int a2)
{
  RenderIndexBuffer *v2; // esi@1

  v2 = this;
  this->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
  RenderIndexBuffer::End(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);

//----- (0044CAA0) --------------------------------------------------------  // acclient.c:137740
RenderIndexBuffer *__cdecl RenderIndexBuffer::AllocateIndexBuffer()
{
  RenderIndexBuffer *result; // eax@2

  if ( Render::m_pRenderer )
  {
    result = (RenderIndexBuffer *)((int (*)(void))RenderDevice::render_device->vfptr->CreateIndexBuffer)();
  }
  else
  {
    result = (RenderIndexBuffer *)operator new(0x28u);
    if ( result )
    {
      result->m_nNumIndices = 0;
      result->m_nActualNumIndices = 0;
      result->indices = 0;
      result->staticData = 0;
      result->m_OnlyWriteOnce = 0;
      result->locked = 0;
      result->needRefresh = 0;
      result->m_nMinVertexIndex = 0;
      result->m_nMaxVertexIndex = 0;
      result->m_bNeedRecalcMinMax = 0;
      result->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
      result->indexSize = 2;
      result->m_bUseIndexCaching = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);

//----- (0044CB00) --------------------------------------------------------  // acclient.c:137777
char __thiscall RenderIndexBuffer::SetRenderIndexBuffer(RenderIndexBuffer *this, RenderIndexBuffer *source)
{
  RenderIndexBuffer *v2; // esi@1
  RenderIndexBuffer *v3; // ebx@1
  char result; // al@1
  unsigned int v5; // ecx@2
  unsigned int v6; // edx@2
  void *v7; // edi@4

  v2 = source;
  LOBYTE(source) = source->m_OnlyWriteOnce;
  v3 = this;
  result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->Startup)(
             v2->m_nActualNumIndices,
             v2->indexSize,
             v2->staticData,
             source,
             v2->m_bUseIndexCaching);
  if ( result )
  {
    v5 = v2->m_nNumIndices;
    v6 = v3->m_nActualNumIndices;
    result = 1;
    if ( v5 <= v6 )
    {
      v3->m_nNumIndices = v5;
      v3->m_bNeedRecalcMinMax = 1;
      v3->needRefresh = 1;
    }
    v7 = v3->indices;
    v3->locked = 1;
    if ( v7 )
    {
      qmemcpy(v7, v2->indices, v6 * v3->indexSize);
      v3->locked = 0;
      v3->needRefresh = 1;
      v3->m_bNeedRecalcMinMax = 1;
    }
    else
    {
      v3->vfptr->Shutdown(v3);
      result = 0;
    }
  }
  return result;
}

//----- (0044CBA0) --------------------------------------------------------  // acclient.c:137825
void __thiscall RenderIndexBuffer::Serialize(RenderIndexBuffer *this, Archive *io_archive)
{
  RenderIndexBuffer *v2; // esi@1
  unsigned int v3; // eax@1
  char *v4; // eax@7

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nActualNumIndices;
    else
      v2->m_nActualNumIndices = *(_DWORD *)v3;
  }
  if ( (!(~LOBYTE(io_archive->m_flags) & 1) || v2->vfptr->Startup(v2, v2->m_nActualNumIndices, 2, 1, 1, 1))
    && (v4 = v2->indices, v2->locked = 1, v4) )
  {
    Serializer::SerializeBytes(v4, v2->m_nNumIndices * v2->indexSize, io_archive);
    v2->needRefresh = 1;
    v2->m_bNeedRecalcMinMax = 1;
    v2->locked = 0;
  }
  else
  {
    Archive::RaiseError(io_archive);
  }
}

//----- (0044CC30) --------------------------------------------------------  // acclient.c:137856
RenderIndexBuffer *__thiscall RenderIndexBuffer::Duplicate(RenderIndexBuffer *this)
{
  RenderIndexBuffer *v1; // edi@1
  void *v2; // eax@1
  RenderIndexBuffer *v3; // esi@2
  RenderIndexBuffer *result; // eax@7

  v1 = this;
  v2 = operator new(0x28u);
  if ( v2 )
  {
    *(_DWORD *)v2 = &RenderIndexBuffer::vftable;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    *((_BYTE *)v2 + 12) = 2;
    *((_DWORD *)v2 + 4) = 0;
    *((_BYTE *)v2 + 20) = 0;
    *((_BYTE *)v2 + 21) = 0;
    *((_BYTE *)v2 + 22) = 0;
    *((_BYTE *)v2 + 23) = 0;
    *((_BYTE *)v2 + 24) = 1;
    *((_DWORD *)v2 + 7) = 0;
    *((_DWORD *)v2 + 8) = 0;
    *((_BYTE *)v2 + 36) = 0;
    v3 = (RenderIndexBuffer *)v2;
  }
  else
  {
    v3 = 0;
  }
  if ( RenderIndexBuffer::SetRenderIndexBuffer(v3, v1) )
  {
    result = v3;
  }
  else
  {
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    result = 0;
  }
  return result;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);

//----- (0044CCA0) --------------------------------------------------------  // acclient.c:137901
void __thiscall AutoStoreVersionArchive::AutoStoreVersionArchive(AutoStoreVersionArchive *this)
{
  AutoStoreVersionArchive *v1; // esi@1

  v1 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  this->m_flags = 0;
  this->m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&this->m_buffer);
  v1->m_currOffset = 0;
  v1->m_pcUserDataHash = 0;
  v1->m_pVersionStack = 0;
  v1->vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  v1->m_SerializeVersionRow.vfptr = (ArchiveInitializerVtbl *)&AutoStoreVersionArchive::tagSerializeVersionRow::vftable;
  v1->m_SerializeVersionRow.m_rowInitialData.vfptr = (ArchiveVersionRowVtbl *)&ArchiveVersionRow::vftable;
  v1->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_num = 0;
  v1->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data = (ArchiveVersionRow::VersionEntry *)v1->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_aPrimitiveInplaceMemory;
  v1->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate = 8;
  v1->m_bOnSerializingDoneCalled = 1;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);
// 799A90: using guessed type bool (__thiscall *AutoStoreVersionArchive::tagSerializeVersionRow::vftable)(AutoStoreVersionArchive::tagSerializeVersionRow *this, struct Archive *);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (0044CD00) --------------------------------------------------------  // acclient.c:137927
char __userpurge RenderIndexBuffer::FromFileNode@<al>(RenderIndexBuffer *this@<ecx>, int a2@<edi>, PFileNode *node)
{
  RenderIndexBuffer *v3; // esi@1
  char v4; // al@2
  int v5; // edi@2
  char v6; // bl@6
  char v7; // al@7
  PSRefBufferCharData<char> *v8; // ecx@7
  int v9; // edi@13
  int v10; // eax@14
  PSRefBufferCharData<char> *v11; // ecx@14
  const unsigned int v13; // edi@18
  char *v14; // eax@20
  unsigned int v15; // eax@21
  int v16; // edi@21
  ReferenceCountTemplate<1048576,0>Vtbl *v17; // eax@23
  PFileNode *v18; // eax@23
  PSRefBufferCharData<char> *v19; // ecx@23
  PStringBase<char> v20; // [sp+8h] [bp-ACh]@16
  int Index16; // [sp+1Ch] [bp-98h]@2
  unsigned int vertexIndex; // [sp+20h] [bp-94h]@2
  SmartBuffer buff; // [sp+24h] [bp-90h]@14
  AutoStoreVersionArchive archive; // [sp+30h] [bp-84h]@12

  v3 = this;
  if ( !node )
    return 0;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&vertexIndex, "IndexArray");
  v4 = PFileNode::IsKeyword(node, a2, (PStringBase<char> *)&vertexIndex);
  v5 = vertexIndex - 20;
  LOBYTE(Index16) = v4;
  if ( !InterlockedDecrement((volatile LONG *)(vertexIndex - 20 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( !(_BYTE)Index16 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&vertexIndex, "BinaryIndexArray");
    v7 = PFileNode::IsKeyword(node, v5, (PStringBase<char> *)&vertexIndex);
    v5 = vertexIndex - 20;
    LOBYTE(Index16) = v7;
    if ( !InterlockedDecrement((volatile LONG *)(vertexIndex - 20 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    if ( (_BYTE)Index16 )
    {
      v6 = 0;
      goto LABEL_12;
    }
    v20.m_charbuffer = v8;
    PStringBase<char>::PStringBase<char>(&v20, "unable to parse indices");
    PFileNode::ReportError(v5, node, v20);
    return 0;
  }
  v6 = 1;
LABEL_12:
  AutoStoreVersionArchive::AutoStoreVersionArchive(&archive);
  if ( v6 )
  {
    v9 = (int)&v3->m_nActualNumIndices;
    v3->m_nActualNumIndices = PFileNode::GetNumSubNodes(node);
  }
  else
  {
    SmartBuffer::SmartBuffer(&buff);
    v10 = PFileNode::GetLeaf(node);
    if ( !v10 || !PFileNode::GetNameAsBinary((PFileNode *)v10, v5, &buff) )
    {
      v20.m_charbuffer = v11;
      PStringBase<char>::PStringBase<char>(&v20, "corrupt index data");
      PFileNode::ReportError(v5, node, v20);
      SmartBuffer::ReleaseMasterBuffer(&buff);
      AutoStoreVersionArchive::~AutoStoreVersionArchive(&archive);
      return 0;
    }
    AutoStoreVersionArchive::InitForUnpacking(&archive, &buff);
    v9 = (int)&v3->m_nActualNumIndices;
    Serializer::SerializeObject((CliDatError *)&v3->m_nActualNumIndices, (Archive *)&archive.vfptr);
    SmartBuffer::ReleaseMasterBuffer(&buff);
  }
  v13 = *(_DWORD *)v9;
  if ( v13 )
  {
    if ( !v3->vfptr->Startup(v3, v13, 2, 1, 1, 1) || (v14 = v3->indices, v3->locked = 1, !v14) )
    {
LABEL_27:
      AutoStoreVersionArchive::~AutoStoreVersionArchive(&archive);
      return 0;
    }
    v15 = v3->m_nNumIndices;
    v16 = 0;
    if ( v6 )
    {
      if ( v15 )
      {
        while ( 1 )
        {
          v17 = node->vfptr;
          vertexIndex = 0;
          v18 = (PFileNode *)v17[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)node, v16);
          if ( !PFileNode::GetNameAsUInt32(v18, v16, &vertexIndex) )
            break;
          *(_WORD *)&v3->indices[2 * v16++] = vertexIndex;
          if ( v16 >= v3->m_nNumIndices )
            goto LABEL_30;
        }
        v20.m_charbuffer = v19;
        PStringBase<char>::PStringBase<char>(&v20, "unable to parse indices");
        PFileNode::ReportError(v16, node, v20);
        v3->locked = 0;
        v3->needRefresh = 1;
        v3->m_bNeedRecalcMinMax = 1;
        goto LABEL_27;
      }
    }
    else if ( v15 )
    {
      do
      {
        Serializer::SerializeObject((unsigned __int16 *)&Index16, (Archive *)&archive.vfptr);
        *(_WORD *)&v3->indices[2 * v16++] = Index16;
      }
      while ( v16 < v3->m_nNumIndices );
    }
LABEL_30:
    v3->locked = 0;
    v3->needRefresh = 1;
    v3->m_bNeedRecalcMinMax = 1;
  }
  AutoStoreVersionArchive::OnSerializingDone(&archive);
  archive.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  if ( (archive.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](archive.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive((Archive *)&archive.vfptr);
  return 1;
}
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (006DA720) --------------------------------------------------------  // acclient.c:752211
void _E73_47()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_21, PFID_A8R8G8B8);
}

//----- (006DA730) --------------------------------------------------------  // acclient.c:752217
void _E91_22()
{
  LODWORD(dword_83A9D8) = 1053364187;
}

//----- (006DA740) --------------------------------------------------------  // acclient.c:752223
void _E93_7()
{
  outside_val_16 = 1000.0 + 1.0;
}

//----- (006DA760) --------------------------------------------------------  // acclient.c:752229
void _E95_7()
{
  block_length_16 = 24.0 * 8.0;
}

//----- (006DA780) --------------------------------------------------------  // acclient.c:752235
void _E97_21()
{
  half_square_length_16 = 24.0 * 0.5;
}

//----- (006DA7A0) --------------------------------------------------------  // acclient.c:752241
int _E99_3()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_11, "Render.TextureFiltering");
  return atexit(sub_745D20);
}

//----- (006DA7C0) --------------------------------------------------------  // acclient.c:752248
int _E102_7()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_11, "Render.LandscapeDetailTextures");
  return atexit(sub_745D50);
}

//----- (006DA7E0) --------------------------------------------------------  // acclient.c:752255
int _E105_3()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_11, "Render.BuildingDetailTextures");
  return atexit(sub_745D80);
}

//----- (006DA800) --------------------------------------------------------  // acclient.c:752262
int _E108_6()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_11, "Render.FieldOfView");
  return atexit(sub_745DB0);
}

//----- (006DA820) --------------------------------------------------------  // acclient.c:752269
int _E111_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_11, "Render.LandscapeTextureDetail");
  return atexit(sub_745DE0);
}

//----- (006DA840) --------------------------------------------------------  // acclient.c:752276
int _E114_6()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_11, "Render.EnvironmentTextureDetail");
  return atexit(sub_745E10);
}

//----- (006DA860) --------------------------------------------------------  // acclient.c:752283
int _E117_4()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_11, "Render.SceneryDrawDistance");
  return atexit(sub_745E40);
}

//----- (006DA880) --------------------------------------------------------  // acclient.c:752290
int _E120_7()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_11, "Render.LandscapeDrawDistance");
  return atexit(sub_745E70);
}

//----- (006DA8A0) --------------------------------------------------------  // acclient.c:752297
int _E123_4()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_11, "Render.ScreenBrightness");
  return atexit(_E124_98);
}

//----- (006DA8C0) --------------------------------------------------------  // acclient.c:752304
int _E126_8()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_11, "Render.AspectRatio");
  return atexit(_E127_89);
}

//----- (006DA8E0) --------------------------------------------------------  // acclient.c:752311
int _E129_7()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_11, "Render.DisplayAdapter");
  return atexit(_E130_81);
}

//----- (006DA900) --------------------------------------------------------  // acclient.c:752318
int _E132_8()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_11, "Render.MaxHardwareClass");
  return atexit(_E133_74);
}

//----- (006DA920) --------------------------------------------------------  // acclient.c:752325
int _E135_7()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_11, "Render.AutomaticDegrades");
  return atexit(_E136_58);
}

//----- (006DA940) --------------------------------------------------------  // acclient.c:752332
int _E138_8()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_11, "Render.GraphicsPerformance");
  return atexit(_E139_59);
}

//----- (006DA960) --------------------------------------------------------  // acclient.c:752339
int _E141_8()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_11, "Render.DegradeDistance");
  return atexit(_E142_56);
}

//----- (006DA980) --------------------------------------------------------  // acclient.c:752346
int _E144_8()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_11, "Render.MultiPassAlpha");
  return atexit(_E145_58);
}

//----- (006DA9A0) --------------------------------------------------------  // acclient.c:752353
int _E147_8()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_11, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83AA30, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83AA34, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83AA38, "Anisotropic");
  return atexit(_E148_57);
}

//----- (006DA9F0) --------------------------------------------------------  // acclient.c:752363
int _E150_8()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_11, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83AA40, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83AA44, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83AA48, "High");
  PStringBase<char>::PStringBase<char>(&stru_83AA4C, "VeryHigh");
  return atexit(_E151_55);
}

//----- (006DAA50) --------------------------------------------------------  // acclient.c:752374
int _E153_8()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_11, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83AA54, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83AA58, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83AA5C, "High");
  PStringBase<char>::PStringBase<char>(&stru_83AA60, "VeryHigh");
  return atexit(_E154_56);
}

//----- (006DAAB0) --------------------------------------------------------  // acclient.c:752385
int _E156_9()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_11, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83AA68, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83AA6C, "High");
  return atexit(_E157_53);
}

//----- (006DAAF0) --------------------------------------------------------  // acclient.c:752394
int _E159_8()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_11, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83AA74, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83AA78, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83AA7C, "High");
  PStringBase<char>::PStringBase<char>(&stru_83AA80, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83AA84, "Extreme");
  return atexit(_E160_56);
}

//----- (006DAB60) --------------------------------------------------------  // acclient.c:752406
int _E162_9()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_11, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83AA8C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83AA90, "Wide");
  return atexit(_E163_49);
}

//----- (006DABA0) --------------------------------------------------------  // acclient.c:752415
int _E165_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_18, "None");
  return atexit(_E166_51);
}

//----- (006DABC0) --------------------------------------------------------  // acclient.c:752422
int _E168_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_18, "Speed");
  return atexit(_E169_50);
}

//----- (006DABE0) --------------------------------------------------------  // acclient.c:752429
int _E171_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_18, "Noise");
  return atexit(_E172_48);
}

//----- (006DAC00) --------------------------------------------------------  // acclient.c:752436
int _E174_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_18, "Sine");
  return atexit(_E175_45);
}

//----- (006DAC20) --------------------------------------------------------  // acclient.c:752443
int _E177_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_18, "Square");
  return atexit(_E178_45);
}

//----- (006DAC40) --------------------------------------------------------  // acclient.c:752450
int _E180_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_18, "Bounce");
  return atexit(_E181_45);
}

//----- (006DAC60) --------------------------------------------------------  // acclient.c:752457
int _E183_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_18, "Perlin");
  return atexit(_E184_43);
}

//----- (006DAC80) --------------------------------------------------------  // acclient.c:752464
int _E186_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_18, "Fractal");
  return atexit(_E187_42);
}

//----- (006DACA0) --------------------------------------------------------  // acclient.c:752471
int _E189_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_18, "FrameLoop");
  return atexit(_E190_43);
}

//----- (006DACC0) --------------------------------------------------------  // acclient.c:752478
int _E1_42()
{
  return atexit(_E2_42);
}

//----- (00745D20) --------------------------------------------------------  // acclient.c:859255
void __cdecl sub_745D20()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745D50) --------------------------------------------------------  // acclient.c:859268
void __cdecl sub_745D50()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745D80) --------------------------------------------------------  // acclient.c:859281
void __cdecl sub_745D80()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745DB0) --------------------------------------------------------  // acclient.c:859294
void __cdecl sub_745DB0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745DE0) --------------------------------------------------------  // acclient.c:859307
void __cdecl sub_745DE0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745E10) --------------------------------------------------------  // acclient.c:859320
void __cdecl sub_745E10()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745E40) --------------------------------------------------------  // acclient.c:859333
void __cdecl sub_745E40()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745E70) --------------------------------------------------------  // acclient.c:859346
void __cdecl sub_745E70()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745EA0) --------------------------------------------------------  // acclient.c:859359
void __cdecl _E124_98()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745ED0) --------------------------------------------------------  // acclient.c:859372
void __cdecl _E127_89()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745F00) --------------------------------------------------------  // acclient.c:859385
void __cdecl _E130_81()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745F30) --------------------------------------------------------  // acclient.c:859398
void __cdecl _E133_74()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745F60) --------------------------------------------------------  // acclient.c:859411
void __cdecl _E136_58()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745F90) --------------------------------------------------------  // acclient.c:859424
void __cdecl _E139_59()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745FC0) --------------------------------------------------------  // acclient.c:859437
void __cdecl _E142_56()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745FF0) --------------------------------------------------------  // acclient.c:859450
void __cdecl _E145_58()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746020) --------------------------------------------------------  // acclient.c:859463
void __cdecl _E148_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_11;
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

//----- (00746060) --------------------------------------------------------  // acclient.c:859488
void __cdecl _E151_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_11;
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

//----- (007460A0) --------------------------------------------------------  // acclient.c:859513
void __cdecl _E154_56()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_11;
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

//----- (007460E0) --------------------------------------------------------  // acclient.c:859538
void __cdecl _E157_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_11;
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

//----- (00746120) --------------------------------------------------------  // acclient.c:859563
void __cdecl _E160_56()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_11;
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

//----- (00746160) --------------------------------------------------------  // acclient.c:859588
void __cdecl _E163_49()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_18;
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

//----- (007461A0) --------------------------------------------------------  // acclient.c:859613
void __cdecl _E166_51()
{
  char *v0; // esi@1

  v0 = &waveform_None_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007461D0) --------------------------------------------------------  // acclient.c:859626
void __cdecl _E169_50()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746200) --------------------------------------------------------  // acclient.c:859639
void __cdecl _E172_48()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746230) --------------------------------------------------------  // acclient.c:859652
void __cdecl _E175_45()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746260) --------------------------------------------------------  // acclient.c:859665
void __cdecl _E178_45()
{
  char *v0; // esi@1

  v0 = &waveform_Square_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746290) --------------------------------------------------------  // acclient.c:859678
void __cdecl _E181_45()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007462C0) --------------------------------------------------------  // acclient.c:859691
void __cdecl _E184_43()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007462F0) --------------------------------------------------------  // acclient.c:859704
void __cdecl _E187_42()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746320) --------------------------------------------------------  // acclient.c:859717
void __cdecl _E190_43()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

