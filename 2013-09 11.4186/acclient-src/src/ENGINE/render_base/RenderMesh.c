/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderMesh
   Object     : ENGINE\render_base\RenderMesh.obj
   Functions  : 1063
   Addresses  : 004446A0 - 00730C90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004446A0) --------------------------------------------------------  // acclient.c:128559
void __thiscall FileNodeName_Binary::FileNodeName_Binary(FileNodeName_Binary *this)
{
  this->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Binary::vftable;
  SmartBuffer::SmartBuffer(&this->m_name);
}
// 799750: using guessed type int (__thiscall *FileNodeName_Binary::vftable)(void *, char);

//----- (004446C0) --------------------------------------------------------  // acclient.c:128567
IFileNodeName *__thiscall FileNodeName_Binary::Clone(FileNodeName_Binary *this)
{
  FileNodeName_Binary *v1; // edi@1
  void *v2; // eax@1
  IFileNodeName *v3; // esi@1
  IFileNodeName *result; // eax@2

  v1 = this;
  v2 = operator new(0x10u);
  v3 = (IFileNodeName *)v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = &FileNodeName_Binary::vftable;
    SmartBuffer::SmartBuffer((SmartBuffer *)((char *)v2 + 4), &v1->m_name);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 799750: using guessed type int (__thiscall *FileNodeName_Binary::vftable)(void *, char);

//----- (004446F0) --------------------------------------------------------  // acclient.c:128592
FileNodeName_Binary *__thiscall FileNodeName_Binary::vector_deleting_destructor(FileNodeName_Binary *this, unsigned int a2)
{
  FileNodeName_Binary *v2; // esi@1

  v2 = this;
  this->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Binary::vftable;
  SmartBuffer::ReleaseMasterBuffer(&this->m_name);
  v2->vfptr = (IFileNodeNameVtbl *)&IFileNodeName::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79602C: using guessed type int (__thiscall *IFileNodeName::vftable)(void *, char);
// 799750: using guessed type int (__thiscall *FileNodeName_Binary::vftable)(void *, char);

//----- (00444720) --------------------------------------------------------  // acclient.c:128608
signed int __thiscall Plane::which_side(Plane *this, AC1Legacy::Vector3 *v, float epsilon)
{
  double v3; // st7@1
  signed int result; // eax@2

  v3 = v->z * this->N.z + v->y * this->N.y + v->x * this->N.x + this->d;
  if ( v3 <= epsilon )
  {
    result = 1;
    if ( v3 >= -epsilon )
      result = 2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00444770) --------------------------------------------------------  // acclient.c:128628
void __thiscall _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>(_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *this)
{
  this->second = 0;
}

//----- (00444780) --------------------------------------------------------  // acclient.c:128634
void __thiscall FileNodeName_Binary::Serialize(FileNodeName_Binary *this, Archive *io_archive)
{
  Serializer::SerializeObject(&this->m_name, io_archive);
}

//----- (004447A0) --------------------------------------------------------  // acclient.c:128640
void __cdecl Serializer::SerializeObject(SmartBuffer *io_object, Archive *io_archive)
{
  Archive *v2; // ebx@1
  unsigned int v3; // eax@4
  unsigned int v4; // eax@5
  unsigned int v5; // esi@9
  unsigned int v6; // edi@9
  unsigned int v7; // eax@9
  unsigned int v8; // ecx@10
  const void *v9; // esi@11
  void *v10; // edi@11
  char v11; // al@11
  unsigned int v12; // ecx@11
  int v13; // edi@11
  int v14; // esi@11
  char v15; // cl@11
  char v16; // dl@12
  unsigned int v17; // ecx@12
  int v18; // eax@14
  SmartBuffer result; // [sp+8h] [bp-Ch]@14

  v2 = io_archive;
  if ( (io_archive->m_flags & 5) == 1 )
    io_archive = (Archive *)SmartBuffer::GetSize(io_object);
  Serializer::SerializeObject((CliDatError *)&io_archive, v2);
  if ( !(v2->m_flags & 5) )
  {
    v3 = Archive::GetSizeLeft(v2);
    if ( (unsigned int)io_archive > v3 )
    {
LABEL_7:
      Archive::RaiseError(v2);
      return;
    }
    v4 = SmartBuffer::GetSize(io_object);
    if ( v4 < (unsigned int)io_archive )
    {
      if ( !SmartBuffer::CanGrow(io_object) )
        goto LABEL_7;
      SmartBuffer::ReconfigureAllocation(io_object, (unsigned int)io_archive, 1u);
    }
  }
  v5 = (unsigned int)io_archive;
  v6 = SmartBuffer::GetBuffer(io_object);
  v7 = Archive::GetBytes(v2, v5);
  if ( v7 )
  {
    v8 = v5;
    if ( v2->m_flags & 1 )
    {
      v9 = (const void *)v6;
      v10 = (void *)v7;
      v11 = v8;
      v12 = v8 >> 2;
      qmemcpy(v10, v9, 4 * v12);
      v14 = (int)((char *)v9 + 4 * v12);
      v13 = (int)((char *)v10 + 4 * v12);
      v15 = v11;
    }
    else
    {
      v16 = v5;
      v17 = v5 >> 2;
      qmemcpy((void *)v6, (const void *)v7, 4 * (v5 >> 2));
      v14 = v7 + 4 * (v5 >> 2);
      v13 = v6 + 4 * v17;
      v15 = v16;
    }
    qmemcpy((void *)v13, (const void *)v14, v15 & 3);
  }
  v18 = (int)SmartBuffer::MakeWindow(io_object, &result, 0, (unsigned int)io_archive);
  SmartBuffer::operator=((int)io_object, v18);
  SmartBuffer::ReleaseMasterBuffer(&result);
}

//----- (004448D0) --------------------------------------------------------  // acclient.c:128732
char __thiscall RenderMesh::GetMaterialsFromDatabase(RenderMesh *this)
{
  RenderMeshMaterialArray *v1; // eax@1
  unsigned int v2; // ebp@2
  int v3; // esi@3
  QualifiedDataID *v4; // eax@4
  int v5; // edi@4
  int v6; // ecx@6
  char result; // al@10
  bool RetVal; // [sp+Bh] [bp-Dh]@1
  RenderMesh *v9; // [sp+Ch] [bp-Ch]@1
  QualifiedDataID v10; // [sp+10h] [bp-8h]@4

  v1 = this->m_pMaterialArray;
  v9 = this;
  RetVal = 1;
  if ( v1 && (v2 = 0, v1->m_Materials.m_num > 0) )
  {
    do
    {
      v3 = (int)&v1->m_Materials.m_data[v2];
      if ( *(_DWORD *)v3 != INVALID_DID_34.id )
      {
        QualifiedDataID::QualifiedDataID(&v10, *(IDClass<_tagDataID,32,0> *)v3, 0x21u);
        v5 = DBObj::Get(v4);
        if ( v5 )
        {
          v6 = *(_DWORD *)(v3 + 4);
          if ( v6 )
          {
            (*(void (**)(void))(*(_DWORD *)v6 + 20))();
            *(_DWORD *)(v3 + 4) = 0;
          }
          *(_DWORD *)(v3 + 4) = v5;
        }
        else
        {
          RetVal = 0;
        }
      }
      v1 = v9->m_pMaterialArray;
      ++v2;
    }
    while ( v2 < v1->m_Materials.m_num );
    result = RetVal;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00444960) --------------------------------------------------------  // acclient.c:128786
char __thiscall RenderMesh::ReleaseSubObjects(RenderMesh *this)
{
  RenderMesh *v1; // ebx@1
  RenderMeshMaterialArray *v2; // eax@1
  unsigned int v3; // edi@2
  _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *v4; // eax@3
  MaterialInstance *v5; // ecx@3
  int v6; // esi@3

  v1 = this;
  v2 = this->m_pMaterialArray;
  if ( v2 )
  {
    v3 = 0;
    if ( v2->m_Materials.m_num )
    {
      do
      {
        v4 = v2->m_Materials.m_data;
        v5 = v4[v3].second;
        v6 = (int)&v4[v3];
        if ( v5 )
        {
          ((void (*)(void))v5->vfptr->Release)();
          *(_DWORD *)(v6 + 4) = 0;
        }
        v2 = v1->m_pMaterialArray;
        ++v3;
      }
      while ( v3 < v2->m_Materials.m_num );
    }
  }
  return 1;
}

//----- (004449A0) --------------------------------------------------------  // acclient.c:128822
void __thiscall RenderMesh::CacheHasSkeletalData(RenderMesh *this)
{
  unsigned int v1; // eax@1
  unsigned int *v2; // ebx@2
  RenderMeshFragment *v3; // edx@3
  unsigned int v4; // edi@3
  unsigned int v5; // eax@3
  RenderMeshBatch **v6; // esi@4
  unsigned int LODIndex; // [sp+0h] [bp-4h]@1

  v1 = this->m_RenderLODFragmentIndices.m_num;
  this->m_CachedHasSkeletalData = 0;
  LODIndex = 0;
  if ( v1 )
  {
    v2 = this->m_RenderLODFragmentIndices.m_data;
    while ( 1 )
    {
      v3 = this->m_Fragments.m_data[*v2];
      v4 = v3->m_MaterialBatches.m_num;
      v5 = 0;
      if ( v4 )
        break;
LABEL_7:
      ++v2;
      ++LODIndex;
      if ( LODIndex >= this->m_RenderLODFragmentIndices.m_num )
        return;
    }
    v6 = v3->m_MaterialBatches.m_data;
    while ( !(*v6)->m_pContainerMesh->m_pVerticesArray->m_VertexArrays.m_data[(*v6)->m_VertexArrayIndex]->vertexFormat.numMatrices )
    {
      ++v5;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_7;
    }
    this->m_CachedHasSkeletalData = 1;
  }
}

//----- (00444A20) --------------------------------------------------------  // acclient.c:128864
void __thiscall RenderMesh::CacheRenderBoundingBox(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  BBox *v2; // ebx@3
  RenderMeshFragment *v3; // edi@3
  unsigned int v4; // esi@3
  RenderMeshBatch *v5; // eax@4

  v1 = this;
  if ( this->m_RenderLODFragmentIndices.m_num )
  {
    v2 = &this->m_CachedRenderBoundingBox;
    BBox::InitForAdjustment(&this->m_CachedRenderBoundingBox);
    v3 = v1->m_Fragments.m_data[*v1->m_RenderLODFragmentIndices.m_data];
    v4 = 0;
    if ( v3->m_MaterialBatches.m_num )
    {
      do
      {
        v5 = v3->m_MaterialBatches.m_data[v4];
        BBox::BuildBoundingBox(
          &v5->m_pContainerMesh->m_pVerticesArray->m_VertexArrays.m_data[v5->m_VertexArrayIndex]->m_BoundingBox,
          v2);
        ++v4;
      }
      while ( v4 < v3->m_MaterialBatches.m_num );
    }
  }
  else
  {
    qmemcpy(&this->m_CachedRenderBoundingBox, &BBox::s_cZeroAABB, sizeof(this->m_CachedRenderBoundingBox));
  }
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (00444A90) --------------------------------------------------------  // acclient.c:128900
bool __thiscall RenderMesh::DrawSubset(RenderMesh *this, const unsigned int _AttribID)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  RenderMeshFragment **v4; // esi@2
  RenderMeshFragment **v5; // ecx@2
  RenderMeshFragment *v7; // edi@6
  unsigned int v8; // ecx@8
  unsigned int v9; // eax@8
  RenderMeshBatch *v10; // esi@9
  RenderVertexBuffer *v11; // ebx@9
  unsigned int v12; // eax@9
  RenderIndexBuffer *v13; // edi@10
  unsigned int v14; // ebp@10
  char v15; // al@10
  unsigned int v16; // ecx@16
  bool WasAnythingRendered; // [sp+2Dh] [bp-11h]@1
  unsigned int BaseVertexIndex; // [sp+2Eh] [bp-10h]@9
  RenderMeshFragment *pFragment; // [sp+32h] [bp-Ch]@6
  unsigned int BatchIndex; // [sp+36h] [bp-8h]@8
  unsigned int v21; // [sp+3Ah] [bp-4h]@10

  v2 = this->m_Fragments.m_num;
  v3 = 0;
  WasAnythingRendered = 0;
  if ( !v2 )
    return 0;
  v4 = this->m_Fragments.m_data;
  v5 = this->m_Fragments.m_data;
  while ( (*v5)->m_AttribID != _AttribID )
  {
    ++v3;
    ++v5;
    if ( v3 >= v2 )
      return 0;
  }
  pFragment = v4[v3];
  v7 = pFragment;
  if ( !pFragment )
    return 0;
  v8 = pFragment->m_MaterialBatches.m_num;
  v9 = 0;
  BatchIndex = 0;
  if ( v8 )
  {
    do
    {
      v10 = v7->m_MaterialBatches.m_data[v9];
      v11 = v10->m_pContainerMesh->m_pVerticesArray->m_VertexArrays.m_data[v10->m_VertexArrayIndex];
      _AttribID = v10->m_IBTrickStreamFrameID;
      BaseVertexIndex = v10->m_IBTrickBaseVertexIndex;
      v12 = v10->m_IndexArrayIndex;
      if ( v12 == -1 )
      {
        if ( (unsigned __int8)((int (__thiscall *)(RenderVertexBuffer *, PrimType, _DWORD, unsigned int, const unsigned int *, unsigned int *))v11->vfptr[6].__vecDelDtor)(
                                v11,
                                v10->m_PrimitivesType,
                                0,
                                v10->m_NumPrimitives,
                                &_AttribID,
                                &BaseVertexIndex) )
        {
          WasAnythingRendered = 1;
          goto LABEL_15;
        }
      }
      else
      {
        v13 = v10->m_pContainerMesh->m_pIndicesArray->m_IndexArrays.m_data[v12];
        RenderIndexBuffer::RecalculateMinMaxIndices(v13);
        v14 = v13->m_nMaxVertexIndex;
        RenderIndexBuffer::RecalculateMinMaxIndices(v13);
        v21 = v13->m_nMinVertexIndex;
        RenderIndexBuffer::RecalculateMinMaxIndices(v13);
        v15 = ((int (__thiscall *)(RenderVertexBuffer *, PrimType, unsigned int, unsigned int, unsigned int, int, _DWORD, RenderIndexBuffer *, _DWORD, const unsigned int *, unsigned int *, signed int))v11->vfptr[5].__vecDelDtor)(
                v11,
                v10->m_PrimitivesType,
                v10->m_FirstIndex,
                v10->m_NumPrimitives,
                v13->m_nMinVertexIndex,
                v14 - v21 + 1,
                0,
                v13,
                0,
                &_AttribID,
                &BaseVertexIndex,
                1);
        v7 = pFragment;
        if ( v15 )
        {
          WasAnythingRendered = 1;
LABEL_15:
          v10->m_pIBTrickUserObjectPointer = 0;
          v10->m_IBTrickVertexSkinningID = 0;
          v10->m_IBTrickStreamFrameID = _AttribID;
          v10->m_IBTrickBaseVertexIndex = BaseVertexIndex;
          goto LABEL_16;
        }
      }
      if ( WasAnythingRendered )
        goto LABEL_15;
LABEL_16:
      v16 = v7->m_MaterialBatches.m_num;
      v9 = BatchIndex++ + 1;
    }
    while ( BatchIndex < v16 );
  }
  return WasAnythingRendered;
}

//----- (00444BF0) --------------------------------------------------------  // acclient.c:129011
void __thiscall RenderMesh::GenerateTopologyForFragments(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  unsigned int v2; // edi@1
  RenderMeshFragment *v3; // ecx@2

  v1 = this;
  RenderMesh::GetMaterialsFromDatabase(this);
  v2 = 0;
  if ( v1->m_RenderLODFragmentIndices.m_num )
  {
    do
    {
      v3 = v1->m_Fragments.m_data[v1->m_RenderLODFragmentIndices.m_data[v2]];
      if ( !v3->m_pTopology )
        RenderMeshFragment::GenerateTopology(v3);
      ++v2;
    }
    while ( v2 < v1->m_RenderLODFragmentIndices.m_num );
  }
}

//----- (00444C30) --------------------------------------------------------  // acclient.c:129034
void __thiscall RenderMesh::OrganizeFragmentBatches(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  RenderMesh::GetMaterialsFromDatabase(this);
  v2 = 0;
  if ( v1->m_RenderLODFragmentIndices.m_num )
  {
    do
      RenderMeshFragment::OrganizeMaterialBatches(v1->m_Fragments.m_data[v1->m_RenderLODFragmentIndices.m_data[v2++]]);
    while ( v2 < v1->m_RenderLODFragmentIndices.m_num );
  }
}

//----- (00444C60) --------------------------------------------------------  // acclient.c:129051
void __thiscall SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::Reset(SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *this)
{
  SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@6
  _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *v5; // edi@7
  unsigned int v6; // [sp+8h] [bp-8h]@0

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      operator delete[](&v1->m_data[-1].second);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v5[i + 1].second = 0 )
    {
      --i;
      v5 = v1->m_data;
      v5[i + 1].first.id = v6;
    }
  }
}

//----- (00444CD0) --------------------------------------------------------  // acclient.c:129083
char __thiscall SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::grow(SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *this, unsigned int i_nSize)
{
  SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *v2; // esi@1
  void *v4; // eax@5
  int v5; // edi@6
  int i; // eax@8
  _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *v7; // edx@9

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = i_nSize;
      vector_constructor_iterator(
        (char *)v4 + 4,
        8u,
        i_nSize,
        (void *(__thiscall *)(void *))_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          for ( i = v2->m_num - 1; i >= 0; *(_DWORD *)(v5 + 8 * i + 12) = v7[i + 1].second )
          {
            --i;
            v7 = v2->m_data;
            *(_DWORD *)(v5 + 8 * i + 8) = v2->m_data[i + 1].first.id;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              operator delete[](&v2->m_data[-1].second);
          }
        }
        v2->m_data = (_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *)v5;
        v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00444DA0) --------------------------------------------------------  // acclient.c:129137
char __userpurge PFileNode::GetNameAsBinary@<al>(PFileNode *this@<ecx>, int a2@<edi>, SmartBuffer *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  IFileNodeName *v10; // edi@4
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
    if ( v6 == 9 )
    {
      SmartBuffer::operator=((int)o_name, (int)&v7[1]);
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(0x10u);
    v10 = (IFileNodeName *)v9;
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Binary::vftable;
      SmartBuffer::SmartBuffer((SmartBuffer *)((char *)v9 + 4));
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)((int (__thiscall *)(IFileNodeName *))v10->vfptr->FromPString)(v10) )
    {
      SmartBuffer::operator=((int)o_name, (int)&v10[1]);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = v10;
      v5 = 1;
    }
    else
    {
      v10->vfptr->__vecDelDtor(v10, 1u);
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
// 799750: using guessed type int (__thiscall *FileNodeName_Binary::vftable)(void *, char);

//----- (00444E70) --------------------------------------------------------  // acclient.c:129200
void __thiscall RenderMeshMaterialArray::~RenderMeshMaterialArray(RenderMeshMaterialArray *this)
{
  RenderMeshMaterialArray *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@1
  MaterialInstance *v4; // ecx@2
  _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> *v5; // edi@6

  v1 = this;
  v2 = this->m_Materials.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)RenderMeshMaterialArray::vftable;
  if ( v2 )
  {
    do
    {
      v4 = v1->m_Materials.m_data[v3].second;
      if ( v4 )
      {
        ((void (*)(void))v4->vfptr->Release)();
        v1->m_Materials.m_data[v3].second = 0;
      }
      ++v3;
    }
    while ( v3 < v1->m_Materials.m_num );
  }
  SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::Reset(&v1->m_Materials);
  if ( (v1->m_Materials.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v5 = v1->m_Materials.m_data;
    if ( v5 )
      operator delete[](&v5[-1].second);
  }
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 799770: using guessed type int (__thiscall *RenderMeshMaterialArray::vftable[3])(void *, char);

//----- (00444EE0) --------------------------------------------------------  // acclient.c:129239
void __thiscall RenderMeshVerticesArray::~RenderMeshVerticesArray(RenderMeshVerticesArray *this)
{
  RenderMeshVerticesArray *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@1
  RenderVertexBuffer *v4; // ecx@2
  bool v5; // zf@3
  unsigned int v6; // eax@7
  unsigned int v7; // ecx@7
  int i; // eax@10

  v1 = this;
  v2 = this->m_VertexArrays.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)RenderMeshVerticesArray::vftable;
  if ( v2 )
  {
    do
    {
      v4 = v1->m_VertexArrays.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_cRef-- == 1;
        if ( v5 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
        v1->m_VertexArrays.m_data[v3] = 0;
      }
      ++v3;
    }
    while ( v3 < v1->m_VertexArrays.m_num );
  }
  v6 = v1->m_VertexArrays.m_sizeAndDeallocate;
  v7 = v1->m_VertexArrays.m_sizeAndDeallocate & 0x80000000;
  v1->m_VertexArrays.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_VertexArrays.m_data);
    v1->m_VertexArrays.m_data = 0;
    v1->m_VertexArrays.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_VertexArrays.m_data )
  {
    for ( i = (v6 & 0x7FFFFFFF) - 1; i >= 0; v1->m_VertexArrays.m_data[i + 1] = 0 )
      --i;
  }
  if ( (v1->m_VertexArrays.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_VertexArrays.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 799774: using guessed type int (__thiscall *RenderMeshVerticesArray::vftable[2])(void *, char);

//----- (00444FA0) --------------------------------------------------------  // acclient.c:129292
void __thiscall RenderMeshIndicesArray::~RenderMeshIndicesArray(RenderMeshIndicesArray *this)
{
  RenderMeshIndicesArray *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@1
  RenderIndexBuffer *v4; // ecx@2
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  int i; // eax@8

  v1 = this;
  v2 = this->m_IndexArrays.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&RenderMeshIndicesArray::vftable;
  if ( v2 )
  {
    do
    {
      v4 = v1->m_IndexArrays.m_data[v3];
      if ( v4 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      v1->m_IndexArrays.m_data[v3++] = 0;
    }
    while ( v3 < v1->m_IndexArrays.m_num );
  }
  v5 = v1->m_IndexArrays.m_sizeAndDeallocate;
  v6 = v1->m_IndexArrays.m_sizeAndDeallocate & 0x80000000;
  v1->m_IndexArrays.m_num = 0;
  if ( v6 == 0x80000000 )
  {
    operator delete[](v1->m_IndexArrays.m_data);
    v1->m_IndexArrays.m_data = 0;
    v1->m_IndexArrays.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_IndexArrays.m_data )
  {
    for ( i = (v5 & 0x7FFFFFFF) - 1; i >= 0; v1->m_IndexArrays.m_data[i + 1] = 0 )
      --i;
  }
  if ( (v1->m_IndexArrays.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_IndexArrays.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 799778: using guessed type int (__thiscall *RenderMeshIndicesArray::vftable)(void *, char);

//----- (00445060) --------------------------------------------------------  // acclient.c:129339
void __thiscall RenderMesh::RenderMesh(RenderMesh *this)
{
  RenderMesh *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_34);
  v1->vfptr = (InterfaceVtbl *)&RenderMesh::vftable;
  v1->m_InstanceFlags = 7;
  v1->m_MeshAppearanceType = 0;
  v1->m_pMaterialArray = 0;
  v1->m_pVerticesArray = 0;
  v1->m_pIndicesArray = 0;
  v1->m_Fragments.m_data = 0;
  v1->m_Fragments.m_sizeAndDeallocate = 0;
  v1->m_Fragments.m_num = 0;
  v1->m_RenderLODFragmentIndices.m_data = 0;
  v1->m_RenderLODFragmentIndices.m_sizeAndDeallocate = 0;
  v1->m_RenderLODFragmentIndices.m_num = 0;
  v1->m_OccluderFragmentIndices.m_data = 0;
  v1->m_OccluderFragmentIndices.m_sizeAndDeallocate = 0;
  v1->m_OccluderFragmentIndices.m_num = 0;
  v1->m_CachedSupportsLighting = 0;
  v1->m_CachedSupportsMultiPassLighting = 0;
  v1->m_CachedSupportsCombinedAmbientPass = 0;
  v1->m_CachedIsGlowing = 0;
  v1->m_CachedNeedAlphaBlendPass = 0;
  v1->m_CachedHasSkeletalData = 0;
  v1->m_CachedAllSkeletalLODsWereBlended = 0;
  v1->m_ShadowLODFragmentIndex = -1;
  v1->m_CachedSkeletalRenderLODIndex = -1;
  v1->m_CachedSkeletalShadowVolumeLODIndex = -1;
  v1->m_CachedRenderBoundingBox = BBox::s_cZeroAABB;
  v1->m_CachedSkinnedBoundingBox = BBox::s_cZeroAABB;
  v1->m_IsSkinnedBoundingBoxValid = 0;
}
// 799780: using guessed type __int32 (__stdcall *RenderMesh::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (00445160) --------------------------------------------------------  // acclient.c:129378
signed int RenderMesh::GetDBOType()
{
  return 67;
}

//----- (00445170) --------------------------------------------------------  // acclient.c:129384
void __thiscall RenderMesh::ReleaseFragments(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@1
  RenderMeshFragment *v4; // ecx@2
  bool v5; // zf@3
  unsigned int v6; // eax@7
  unsigned int v7; // ecx@7
  int i; // eax@10
  unsigned int v9; // eax@12
  unsigned int v10; // edx@12
  int j; // eax@15
  unsigned int v12; // eax@17
  unsigned int v13; // edx@17
  int k; // eax@20

  v1 = this;
  v2 = this->m_Fragments.m_num;
  v3 = 0;
  this->m_InstanceFlags = 7;
  if ( v2 )
  {
    do
    {
      v4 = v1->m_Fragments.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_cRef-- == 1;
        if ( v5 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
        v1->m_Fragments.m_data[v3] = 0;
      }
      ++v3;
    }
    while ( v3 < v1->m_Fragments.m_num );
  }
  v6 = v1->m_Fragments.m_sizeAndDeallocate;
  v7 = v1->m_Fragments.m_sizeAndDeallocate & 0x80000000;
  v1->m_Fragments.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_Fragments.m_data);
    v1->m_Fragments.m_data = 0;
    v1->m_Fragments.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_Fragments.m_data )
  {
    for ( i = (v6 & 0x7FFFFFFF) - 1; i >= 0; v1->m_Fragments.m_data[i + 1] = 0 )
      --i;
  }
  v9 = v1->m_RenderLODFragmentIndices.m_sizeAndDeallocate;
  v10 = v1->m_RenderLODFragmentIndices.m_sizeAndDeallocate & 0x80000000;
  v1->m_RenderLODFragmentIndices.m_num = 0;
  if ( v10 == 0x80000000 )
  {
    operator delete[](v1->m_RenderLODFragmentIndices.m_data);
    v1->m_RenderLODFragmentIndices.m_data = 0;
    v1->m_RenderLODFragmentIndices.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_RenderLODFragmentIndices.m_data )
  {
    for ( j = (v9 & 0x7FFFFFFF) - 1; j >= 0; v1->m_RenderLODFragmentIndices.m_data[j + 1] = 0 )
      --j;
  }
  v12 = v1->m_OccluderFragmentIndices.m_sizeAndDeallocate;
  v13 = v1->m_OccluderFragmentIndices.m_sizeAndDeallocate & 0x80000000;
  v1->m_OccluderFragmentIndices.m_num = 0;
  if ( v13 == 0x80000000 )
  {
    operator delete[](v1->m_OccluderFragmentIndices.m_data);
    v1->m_OccluderFragmentIndices.m_data = 0;
    v1->m_OccluderFragmentIndices.m_sizeAndDeallocate = 0;
    v1->m_ShadowLODFragmentIndex = -1;
  }
  else
  {
    if ( v1->m_OccluderFragmentIndices.m_data )
    {
      for ( k = (v12 & 0x7FFFFFFF) - 1; k >= 0; v1->m_OccluderFragmentIndices.m_data[k + 1] = 0 )
        --k;
    }
    v1->m_ShadowLODFragmentIndex = -1;
  }
}

//----- (00445290) --------------------------------------------------------  // acclient.c:129471
void __thiscall RenderMesh::Destroy(RenderMesh *this)
{
  RenderMesh *v1; // ebp@1
  RenderMeshMaterialArray *v2; // ecx@1
  bool v3; // zf@2
  RenderMeshVerticesArray *v4; // ecx@5
  RenderMeshIndicesArray *v5; // ecx@9

  v1 = this;
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&this->m_RenderLODFragmentIndices);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_OccluderFragmentIndices);
  v1->m_ShadowLODFragmentIndex = -1;
  RenderMesh::ReleaseFragments(v1);
  v1->m_InstanceFlags |= 1u;
  v2 = v1->m_pMaterialArray;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pMaterialArray = 0;
  }
  v1->m_InstanceFlags |= 2u;
  v4 = v1->m_pVerticesArray;
  if ( v4 )
  {
    v3 = v4->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_pVerticesArray = 0;
  }
  v1->m_InstanceFlags |= 4u;
  v5 = v1->m_pIndicesArray;
  if ( v5 )
  {
    v3 = v5->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->m_pIndicesArray = 0;
  }
  v1->m_CachedSkeletalRenderLODIndex = -1;
  v1->m_CachedSkeletalShadowVolumeLODIndex = -1;
  v1->m_MeshAppearanceType = 0;
  v1->m_CachedSupportsLighting = 0;
  v1->m_CachedSupportsMultiPassLighting = 0;
  v1->m_CachedSupportsCombinedAmbientPass = 0;
  v1->m_CachedIsGlowing = 0;
  v1->m_CachedNeedAlphaBlendPass = 0;
  v1->m_CachedHasSkeletalData = 0;
  v1->m_CachedAllSkeletalLODsWereBlended = 0;
  qmemcpy(&v1->m_CachedRenderBoundingBox, &BBox::s_cZeroAABB, sizeof(v1->m_CachedRenderBoundingBox));
  qmemcpy(&v1->m_CachedSkinnedBoundingBox, &BBox::s_cZeroAABB, sizeof(v1->m_CachedSkinnedBoundingBox));
  v1->m_IsSkinnedBoundingBoxValid = 0;
}
// 8EE170: using guessed type const struct BBox BBox::s_cZeroAABB;

//----- (00445350) --------------------------------------------------------  // acclient.c:129528
void __thiscall RenderMesh::GetSubDataIDs(RenderMesh *this, QualifiedDataIDArray *id_array)
{
  RenderMesh *v2; // edi@1
  RenderMeshMaterialArray *v3; // eax@1
  unsigned int v4; // esi@2
  IDClass<_tagDataID,32,0> v5; // eax@3
  QualifiedDataID *v6; // eax@4
  QualifiedDataID v7; // [sp+4h] [bp-8h]@4

  v2 = this;
  v3 = this->m_pMaterialArray;
  if ( v3 )
  {
    v4 = 0;
    if ( v3->m_Materials.m_num )
    {
      do
      {
        v5.id = v3->m_Materials.m_data[v4].first.id;
        if ( v5.id != INVALID_DID_34.id )
        {
          QualifiedDataID::QualifiedDataID(&v7, v5, 0);
          QualifiedDataIDArray::AddQDID(id_array, v6, 0);
        }
        v3 = v2->m_pMaterialArray;
        ++v4;
      }
      while ( v4 < v3->m_Materials.m_num );
    }
  }
}

//----- (004453C0) --------------------------------------------------------  // acclient.c:129561
void __cdecl RenderMesh::Allocator()
{
  RenderMesh *v0; // eax@1

  v0 = (RenderMesh *)operator new(0xB0u);
  if ( v0 )
    RenderMesh::RenderMesh(v0);
}

//----- (004453E0) --------------------------------------------------------  // acclient.c:129571
RenderMeshMaterialArray *__thiscall RenderMeshMaterialArray::scalar_deleting_destructor(RenderMeshMaterialArray *this, unsigned int a2)
{
  RenderMeshMaterialArray *v2; // esi@1

  v2 = this;
  RenderMeshMaterialArray::~RenderMeshMaterialArray(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00445400) --------------------------------------------------------  // acclient.c:129583
RenderMeshVerticesArray *__thiscall RenderMeshVerticesArray::scalar_deleting_destructor(RenderMeshVerticesArray *this, unsigned int a2)
{
  RenderMeshVerticesArray *v2; // esi@1

  v2 = this;
  RenderMeshVerticesArray::~RenderMeshVerticesArray(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00445420) --------------------------------------------------------  // acclient.c:129595
RenderMeshIndicesArray *__thiscall RenderMeshIndicesArray::scalar_deleting_destructor(RenderMeshIndicesArray *this, unsigned int a2)
{
  RenderMeshIndicesArray *v2; // esi@1

  v2 = this;
  RenderMeshIndicesArray::~RenderMeshIndicesArray(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00445440) --------------------------------------------------------  // acclient.c:129607
void __thiscall RenderMesh::~RenderMesh(RenderMesh *this)
{
  RenderMesh *v1; // esi@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&RenderMesh::vftable;
  RenderMesh::Destroy(this);
  if ( (v1->m_OccluderFragmentIndices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_OccluderFragmentIndices.m_data);
  if ( (v1->m_RenderLODFragmentIndices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_RenderLODFragmentIndices.m_data);
  if ( (v1->m_Fragments.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_Fragments.m_data);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 799780: using guessed type __int32 (__stdcall *RenderMesh::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004454B0) --------------------------------------------------------  // acclient.c:129625
RenderMesh *__thiscall RenderMesh::vector_deleting_destructor(RenderMesh *this, unsigned int a2)
{
  RenderMesh *v2; // esi@1

  v2 = this;
  RenderMesh::~RenderMesh(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004454D0) --------------------------------------------------------  // acclient.c:129637
unsigned int __thiscall RenderMesh::AddMaterial(RenderMesh *this, _STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *> _Material)
{
  RenderMesh *v2; // esi@1
  void *v3; // eax@2
  RenderMeshMaterialArray *v4; // eax@6
  unsigned int v5; // edi@6
  unsigned int v6; // ecx@6
  int v7; // esi@6
  int v8; // eax@6
  unsigned int v9; // eax@7
  int v10; // eax@8
  int v11; // ecx@8

  v2 = this;
  if ( !this->m_pMaterialArray )
  {
    v3 = operator new(0x14u);
    if ( v3 )
    {
      *((_DWORD *)v3 + 1) = 1;
      *(_DWORD *)v3 = RenderMeshMaterialArray::vftable;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 4) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->m_pMaterialArray = (RenderMeshMaterialArray *)v3;
  }
  v4 = v2->m_pMaterialArray;
  v5 = v4->m_Materials.m_num;
  v6 = v4->m_Materials.m_num;
  v7 = (int)&v4->m_Materials;
  v8 = v4->m_Materials.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v6 < v8
    || (v9 = SmartArray<UIChildFramework *,1>::get_new_size(v8 + 1),
        SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::grow(
          (SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *)v7,
          v9)) )
  {
    v10 = *(_DWORD *)(v7 + 8);
    v11 = *(_DWORD *)v7;
    *(_DWORD *)(v11 + 8 * v10) = _Material.first.id;
    *(_DWORD *)(v11 + 8 * v10 + 4) = _Material.second;
    ++*(_DWORD *)(v7 + 8);
  }
  return v5;
}
// 799770: using guessed type int (__thiscall *RenderMeshMaterialArray::vftable[3])(void *, char);

//----- (00445560) --------------------------------------------------------  // acclient.c:129690
unsigned int __thiscall RenderMesh::AddVertexArray(RenderMesh *this, RenderVertexBuffer *_pVertexArray)
{
  RenderMesh *v2; // esi@1
  void *v3; // eax@2
  RenderMeshVerticesArray *v4; // eax@6
  unsigned int v5; // edi@6
  unsigned int v6; // ecx@6
  int v7; // esi@6
  int v8; // eax@6
  unsigned int v9; // eax@7

  v2 = this;
  if ( !this->m_pVerticesArray )
  {
    v3 = operator new(0x14u);
    if ( v3 )
    {
      *((_DWORD *)v3 + 1) = 1;
      *(_DWORD *)v3 = RenderMeshVerticesArray::vftable;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 4) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->m_pVerticesArray = (RenderMeshVerticesArray *)v3;
  }
  v4 = v2->m_pVerticesArray;
  v5 = v4->m_VertexArrays.m_num;
  v6 = v4->m_VertexArrays.m_num;
  v7 = (int)&v4->m_VertexArrays;
  v8 = v4->m_VertexArrays.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v6 < v8
    || (v9 = SmartArray<UIChildFramework *,1>::get_new_size(v8 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v7, v9)) )
    *(_DWORD *)(*(_DWORD *)v7 + 4 * (*(_DWORD *)(v7 + 8))++) = _pVertexArray;
  return v5;
}
// 799774: using guessed type int (__thiscall *RenderMeshVerticesArray::vftable[2])(void *, char);

//----- (004455E0) --------------------------------------------------------  // acclient.c:129733
unsigned int __thiscall RenderMesh::AddIndexArray(RenderMesh *this, RenderIndexBuffer *_pIndexArray)
{
  RenderMesh *v2; // esi@1
  void *v3; // eax@2
  RenderMeshIndicesArray *v4; // eax@6
  unsigned int v5; // edi@6
  unsigned int v6; // ecx@6
  int v7; // esi@6
  int v8; // eax@6
  unsigned int v9; // eax@7

  v2 = this;
  if ( !this->m_pIndicesArray )
  {
    v3 = operator new(0x14u);
    if ( v3 )
    {
      *((_DWORD *)v3 + 1) = 1;
      *(_DWORD *)v3 = &RenderMeshIndicesArray::vftable;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 4) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->m_pIndicesArray = (RenderMeshIndicesArray *)v3;
  }
  v4 = v2->m_pIndicesArray;
  v5 = v4->m_IndexArrays.m_num;
  v6 = v4->m_IndexArrays.m_num;
  v7 = (int)&v4->m_IndexArrays;
  v8 = v4->m_IndexArrays.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v6 < v8
    || (v9 = SmartArray<UIChildFramework *,1>::get_new_size(v8 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v7, v9)) )
    *(_DWORD *)(*(_DWORD *)v7 + 4 * (*(_DWORD *)(v7 + 8))++) = _pIndexArray;
  return v5;
}
// 799778: using guessed type int (__thiscall *RenderMeshIndicesArray::vftable)(void *, char);

//----- (00445660) --------------------------------------------------------  // acclient.c:129776
void __thiscall RenderMesh::Serialize(RenderMesh *this, Archive *io_archive)
{
  bool v2; // bl@1
  int v3; // esi@5
  DBObj *v4; // ecx@6
  int v5; // eax@14
  unsigned int v6; // esi@14
  unsigned int *v7; // eax@16
  RenderVertexBuffer *v8; // eax@20
  unsigned int v9; // edi@23
  char *v10; // esi@25
  int v11; // eax@27
  unsigned int v12; // esi@28
  int v13; // edx@30
  unsigned int v14; // eax@33
  void *v15; // eax@39
  int v16; // esi@43
  int v17; // eax@43
  unsigned int v18; // ecx@43
  int v19; // esi@43
  int v20; // eax@43
  unsigned int v21; // eax@44
  int v22; // ecx@45
  int v23; // edx@45
  int v24; // eax@47
  unsigned int v25; // esi@47
  unsigned int *v26; // eax@49
  unsigned int v27; // ebp@53
  RenderVertexBuffer *v28; // eax@55
  void *v29; // eax@56
  int v30; // esi@60
  int v31; // eax@60
  unsigned int v32; // ecx@60
  int v33; // esi@60
  int v34; // eax@60
  unsigned int v35; // edx@61
  int v41; // ecx@70
  int v42; // eax@71
  unsigned int v43; // esi@71
  unsigned int *v44; // eax@73
  RenderIndexBuffer *v45; // ebp@79
  void *v46; // eax@80
  int v47; // esi@84
  int v48; // eax@84
  unsigned int v49; // ecx@84
  int v50; // esi@84
  int v51; // eax@84
  unsigned int v52; // edx@85
  int v54; // eax@94
  unsigned int v55; // esi@94
  DBObj *v56; // esi@95
  unsigned int *v57; // eax@95
  unsigned int v58; // ebx@99
  RenderMeshFragment *v59; // eax@101
  int v60; // eax@102
  int v61; // ebp@102
  char *v62; // edi@104
  unsigned int v63; // eax@104
  unsigned int v64; // edx@105
  int v66; // edx@114
  PStringBase<char> v67; // [sp-4h] [bp-30h]@7
  bool bDBLoader; // [sp+13h] [bp-19h]@1
  DBObj *v69; // [sp+14h] [bp-18h]@1
  IDClass<_tagDataID,32,0> result; // [sp+18h] [bp-14h]@25
  PStringBase<char> strMaterialName; // [sp+1Ch] [bp-10h]@6
  RenderVertexBuffer *pNewVertexArray; // [sp+20h] [bp-Ch]@20
  unsigned int NumIndexArrays; // [sp+24h] [bp-8h]@14
  unsigned int NumFragments; // [sp+28h] [bp-4h]@28

  v69 = (DBObj *)this;
  v2 = Archive::UsingDBLoader(io_archive);
  bDBLoader = v2;
  if ( !v2 )
    DBObj::Serialize(v69, io_archive);
  if ( (unsigned int)Archive::GetVersionByToken(io_archive, 0x524D5654u) <= 1 )
  {
    if ( v2 )
    {
      v3 = DBObj::GetByEnum(8, 1, 0x24u);
      if ( ~LOBYTE(io_archive->m_flags) & 1 )
      {
        strMaterialName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PStringBase<char>::Serialize(&strMaterialName, io_archive);
        v4 = v69;
        v69[1].m_dataCategory = 0;
        if ( v3 )
        {
          v67.m_charbuffer = (PSRefBufferCharData<char> *)v4;
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (CaseInsensitiveStringBase<PStringBase<char> > *)&v67,
            &strMaterialName);
          v69[1].m_dataCategory = EnumMapper::GetEnum((PStringBase<char>)v3, v67);
        }
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&strMaterialName, &name);
        if ( v3 )
          EnumMapper::GetString(v3, (PStringBase<char> *)v69[1].m_dataCategory, &strMaterialName);
        PStringBase<char>::Serialize(&strMaterialName, io_archive);
      }
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strMaterialName);
      if ( v3 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
    }
    else
    {
      Serializer::SerializeObject((CliDatError *)&v69[1].m_dataCategory, io_archive);
    }
    v5 = *(_DWORD *)&v69[1].m_bLoaded;
    v6 = 0;
    NumIndexArrays = 0;
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 16);
      NumIndexArrays = *(_DWORD *)(v5 + 16);
    }
    Archive::CheckAlignment(io_archive, 4u);
    v7 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
    if ( v7 )
    {
      if ( io_archive->m_flags & 1 )
      {
        *v7 = v6;
      }
      else
      {
        v6 = *v7;
        NumIndexArrays = *v7;
      }
    }
    v8 = 0;
    pNewVertexArray = 0;
    if ( v6 )
    {
      while ( 1 )
      {
        v9 = INVALID_DID_34.id;
        if ( bDBLoader )
        {
          if ( ~LOBYTE(io_archive->m_flags) & 1 )
          {
            strMaterialName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PStringBase<char>::Serialize(&strMaterialName, io_archive);
            v9 = FileArray::GetDID(&result, &strMaterialName, 0x21u)->id;
            v10 = &strMaterialName.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&strMaterialName.m_charbuffer[-1]) && v10 )
            {
              v11 = *(_DWORD *)v10;
              v67.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
            }
          }
          else
          {
            v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v69[1].m_bLoaded + 8) + 8 * (_DWORD)v8);
            v67.m_charbuffer = (PSRefBufferCharData<char> *)33;
            FileArray::GetRelativeFilePath((PStringBase<char> *)&NumFragments);
            PStringBase<char>::Serialize((PStringBase<char> *)&NumFragments, io_archive);
            v12 = NumFragments - 20;
            if ( !InterlockedDecrement((volatile LONG *)(NumFragments - 20 + 4)) && v12 )
            {
              v13 = *(_DWORD *)v12;
              v67.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(unsigned int, signed int))v13)(v12, 1);
            }
          }
        }
        else
        {
          if ( !(~LOBYTE(io_archive->m_flags) & 1) )
            v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v69[1].m_bLoaded + 8) + 8 * (_DWORD)v8);
          Archive::CheckAlignment(io_archive, 4u);
          v14 = Archive::GetBytes(io_archive, 4u);
          if ( v14 )
          {
            if ( io_archive->m_flags & 1 )
              *(_DWORD *)v14 = v9;
            else
              v9 = *(_DWORD *)v14;
          }
        }
        if ( ~LOBYTE(io_archive->m_flags) & 1 )
        {
          if ( !*(_DWORD *)&v69[1].m_bLoaded )
          {
            v15 = operator new(0x14u);
            if ( v15 )
            {
              *((_DWORD *)v15 + 1) = 1;
              *(_DWORD *)v15 = RenderMeshMaterialArray::vftable;
              *((_DWORD *)v15 + 2) = 0;
              *((_DWORD *)v15 + 3) = 0;
              *((_DWORD *)v15 + 4) = 0;
            }
            else
            {
              v15 = 0;
            }
            *(_DWORD *)&v69[1].m_bLoaded = v15;
          }
          v16 = *(_DWORD *)&v69[1].m_bLoaded;
          v17 = *(_DWORD *)(v16 + 12);
          v18 = *(_DWORD *)(v16 + 16);
          v19 = v16 + 8;
          v20 = v17 & 0x7FFFFFFF;
          if ( v18 < v20
            || (v21 = SmartArray<UIChildFramework *,1>::get_new_size(v20 + 1),
                SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1>::grow(
                  (SmartArray<_STL::pair<IDClass<_tagDataID,32,0>,MaterialInstance *>,1> *)v19,
                  v21)) )
          {
            v22 = *(_DWORD *)(v19 + 8);
            v23 = *(_DWORD *)v19;
            *(_DWORD *)(v23 + 8 * v22) = v9;
            *(_DWORD *)(v23 + 8 * v22 + 4) = 0;
            ++*(_DWORD *)(v19 + 8);
          }
        }
        pNewVertexArray = (RenderVertexBuffer *)((char *)pNewVertexArray + 1);
        if ( (unsigned int)pNewVertexArray >= NumIndexArrays )
          break;
        v8 = pNewVertexArray;
      }
    }
    v24 = *((_DWORD *)&v69[1].m_bLoaded + 1);
    v25 = 0;
    NumIndexArrays = 0;
    if ( v24 )
    {
      v25 = *(_DWORD *)(v24 + 16);
      NumIndexArrays = *(_DWORD *)(v24 + 16);
    }
    Archive::CheckAlignment(io_archive, 4u);
    v26 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
    if ( v26 )
    {
      if ( io_archive->m_flags & 1 )
      {
        *v26 = v25;
      }
      else
      {
        v25 = *v26;
        NumIndexArrays = *v26;
      }
    }
    v27 = 0;
    if ( v25 )
    {
      do
      {
        if ( ~LOBYTE(io_archive->m_flags) & 1 )
        {
          RenderVertexBuffer::AllocateVertexBuffer();
          pNewVertexArray = v28;
          if ( !*((_DWORD *)&v69[1].m_bLoaded + 1) )
          {
            v29 = operator new(0x14u);
            if ( v29 )
            {
              *((_DWORD *)v29 + 1) = 1;
              *(_DWORD *)v29 = RenderMeshVerticesArray::vftable;
              *((_DWORD *)v29 + 2) = 0;
              *((_DWORD *)v29 + 3) = 0;
              *((_DWORD *)v29 + 4) = 0;
            }
            else
            {
              v29 = 0;
            }
            *((_DWORD *)&v69[1].m_bLoaded + 1) = v29;
          }
          v30 = *((_DWORD *)&v69[1].m_bLoaded + 1);
          v31 = *(_DWORD *)(v30 + 12);
          v32 = *(_DWORD *)(v30 + 16);
          v33 = v30 + 8;
          v34 = v31 & 0x7FFFFFFF;
          if ( v32 < v34 )
            goto LABEL_117;
          v35 = v34 + 1;
          if ( (unsigned int)(v34 + 1) > 8 )
          {
            if ( v35 <= 0x4000 )
            {
              NumFragments = v34 + 1;
              __asm { bsr     this, [esp+2Ch+NumFragments] }
              if ( v35 > 1 << _EAX )
                v35 = 2 * (1 << _EAX);
            }
            else if ( v35 & 0x3FFF )
            {
              v35 += 0x4000 - (v35 & 0x3FFF);
            }
          }
          else
          {
            v35 = 8;
          }
          if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v33, v35) )
LABEL_117:
            *(_DWORD *)(*(_DWORD *)v33 + 4 * (*(_DWORD *)(v33 + 8))++) = pNewVertexArray;
        }
        v41 = *((_DWORD *)&v69[1].m_bLoaded + 1);
        v67.m_charbuffer = (PSRefBufferCharData<char> *)io_archive;
        VertexArray::Serialize(*(VertexArray **)(*(_DWORD *)(v41 + 8) + 4 * v27++), io_archive);
      }
      while ( v27 < NumIndexArrays );
    }
    v42 = LODWORD(v69[1].m_timeStamp);
    v43 = 0;
    NumIndexArrays = 0;
    if ( v42 )
    {
      v43 = *(_DWORD *)(v42 + 16);
      NumIndexArrays = *(_DWORD *)(v42 + 16);
    }
    Archive::CheckAlignment(io_archive, 4u);
    v44 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
    if ( v44 )
    {
      if ( io_archive->m_flags & 1 )
      {
        *v44 = v43;
      }
      else
      {
        v43 = *v44;
        NumIndexArrays = *v44;
      }
    }
    NumFragments = 0;
    if ( v43 )
    {
      do
      {
        if ( ~LOBYTE(io_archive->m_flags) & 1 )
        {
          v45 = RenderIndexBuffer::AllocateIndexBuffer();
          if ( !LODWORD(v69[1].m_timeStamp) )
          {
            v46 = operator new(0x14u);
            if ( v46 )
            {
              *((_DWORD *)v46 + 1) = 1;
              *(_DWORD *)v46 = &RenderMeshIndicesArray::vftable;
              *((_DWORD *)v46 + 2) = 0;
              *((_DWORD *)v46 + 3) = 0;
              *((_DWORD *)v46 + 4) = 0;
            }
            else
            {
              v46 = 0;
            }
            LODWORD(v69[1].m_timeStamp) = v46;
          }
          v47 = LODWORD(v69[1].m_timeStamp);
          v48 = *(_DWORD *)(v47 + 12);
          v49 = *(_DWORD *)(v47 + 16);
          v50 = v47 + 8;
          v51 = v48 & 0x7FFFFFFF;
          if ( v49 < v51 )
            goto LABEL_118;
          v52 = v51 + 1;
          if ( (unsigned int)(v51 + 1) > 8 )
          {
            if ( v52 <= 0x4000 )
            {
              pNewVertexArray = (RenderVertexBuffer *)(v51 + 1);
              __asm { bsr     this, [esp+2Ch+pNewVertexArray] }
              if ( v52 > 1 << _EAX )
                v52 = 2 * (1 << _EAX);
            }
            else if ( v52 & 0x3FFF )
            {
              v52 += 0x4000 - (v52 & 0x3FFF);
            }
          }
          else
          {
            v52 = 8;
          }
          if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v50, v52) )
LABEL_118:
            *(_DWORD *)(*(_DWORD *)v50 + 4 * (*(_DWORD *)(v50 + 8))++) = v45;
        }
        v54 = LODWORD(v69[1].m_timeStamp);
        v55 = NumFragments;
        v67.m_charbuffer = (PSRefBufferCharData<char> *)io_archive;
        RenderIndexBuffer::Serialize(*(RenderIndexBuffer **)(*(_DWORD *)(v54 + 8) + 4 * NumFragments), io_archive);
        NumFragments = v55 + 1;
      }
      while ( v55 + 1 < NumIndexArrays );
    }
    v56 = v69[1].m_pLast;
    NumFragments = (unsigned int)v69[1].m_pLast;
    Archive::CheckAlignment(io_archive, 4u);
    v57 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
    if ( v57 )
    {
      if ( io_archive->m_flags & 1 )
      {
        *v57 = (unsigned int)v56;
      }
      else
      {
        v56 = (DBObj *)*v57;
        NumFragments = *v57;
      }
    }
    v58 = 0;
    if ( v56 )
    {
      do
      {
        if ( ~LOBYTE(io_archive->m_flags) & 1 )
        {
          v59 = (RenderMeshFragment *)operator new(0x20u);
          if ( v59 )
          {
            RenderMeshFragment::RenderMeshFragment(v59);
            v61 = v60;
          }
          else
          {
            v61 = 0;
          }
          v62 = (char *)&v69[1].m_timeStamp + 4;
          v63 = (unsigned int)v69[1].m_pNext & 0x7FFFFFFF;
          if ( v69[1].m_pLast < (DBObj *)v63 )
            goto LABEL_119;
          v64 = v63 + 1;
          if ( v63 + 1 > 8 )
          {
            if ( v64 <= 0x4000 )
            {
              NumIndexArrays = v63 + 1;
              __asm { bsr     this, [esp+2Ch+NumIndexArrays] }
              if ( v64 > 1 << _EAX )
                v64 = 2 * (1 << _EAX);
            }
            else if ( v64 & 0x3FFF )
            {
              v64 += 0x4000 - (v64 & 0x3FFF);
            }
          }
          else
          {
            v64 = 8;
          }
          if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)((char *)&v69[1].m_timeStamp + 4), v64) )
LABEL_119:
            *(_DWORD *)(*(_DWORD *)v62 + 4 * (*((_DWORD *)v62 + 2))++) = v61;
        }
        v66 = HIDWORD(v69[1].m_timeStamp);
        v67.m_charbuffer = (PSRefBufferCharData<char> *)v69;
        RenderMeshFragment::Serialize(*(RenderMeshFragment **)(v66 + 4 * v58++), io_archive, (RenderMesh *)v69);
      }
      while ( v58 < NumFragments );
    }
  }
}
// 799770: using guessed type int (__thiscall *RenderMeshMaterialArray::vftable[3])(void *, char);
// 799774: using guessed type int (__thiscall *RenderMeshVerticesArray::vftable[2])(void *, char);
// 799778: using guessed type int (__thiscall *RenderMeshIndicesArray::vftable)(void *, char);

//----- (00445D40) --------------------------------------------------------  // acclient.c:130245
char __thiscall RenderMesh::ParseFromFileNode(RenderMesh *this, PFileNode *_node)
{
  RenderMesh *v2; // ebp@1
  PFileNode *v3; // edi@2
  void *v4; // esi@4
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // edx@4
  PFileNode *v6; // eax@4
  int v7; // ecx@6
  int v8; // esi@7
  int v9; // edx@9
  RenderMeshFragment *v10; // eax@11
  int v11; // eax@12
  int v12; // esi@12
  int v13; // ecx@14
  int v14; // ecx@19
  int v16; // esi@23
  int v17; // edx@25
  bool v18; // zf@29
  int v19; // eax@30
  int v20; // [sp-4h] [bp-20h]@4
  PFileNodeIter iter; // [sp+10h] [bp-Ch]@2

  v2 = this;
  if ( !_node )
    return 0;
  PFileNodeIter::PFileNodeIter(&iter, _node);
  v3 = PFileNodeIter::Curr(&iter);
  if ( !v3 )
  {
LABEL_22:
    PFileNodeIter::~PFileNodeIter(&iter);
    return 1;
  }
  while ( PFileNode::IsKeyword(v3, (int)v3, &MeshAppearanceType) )
  {
    v4 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v5 = v3->vfptr;
    v20 = 0;
    v6 = (PFileNode *)v5[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 0);
    if ( v6 )
    {
      PFileNode::GetNameAsPString(v6, (int)v3, (PStringBase<char> *)&_node);
      v4 = _node;
    }
    v20 = (int)&v2->m_MeshAppearanceType;
    InterlockedIncrement((volatile LONG *)v4 - 4);
    if ( !EnumMapper::GetEnum(8u, (PStringBase<char>)v4, (unsigned int *)v20) )
    {
      v20 = v7;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "Invalid mesh appearance type name");
      PFileNode::ReportError((int)v3, v3, (PStringBase<char>)v20);
      v16 = (int)((char *)v4 - 20);
      if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
      {
        v17 = *(_DWORD *)v16;
        v20 = 1;
        (*(void (__thiscall **)(int, signed int))v17)(v16, 1);
      }
      goto LABEL_26;
    }
    v8 = (int)((char *)v4 - 20);
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
    {
      if ( v8 )
      {
        v9 = *(_DWORD *)v8;
        v20 = 1;
        (*(void (__thiscall **)(int, signed int))v9)(v8, 1);
      }
    }
LABEL_21:
    v3 = (PFileNode *)PFileNodeIter::Next(&iter);
    if ( !v3 )
      goto LABEL_22;
  }
  if ( !PFileNode::IsKeyword(v3, (int)v3, &Fragment) )
  {
    if ( PFileNode::IsKeyword(v3, (int)v3, &ExportMeshAppearanceType)
      || PFileNode::IsKeyword(v3, (int)v3, &BinaryVertexArray)
      || PFileNode::IsKeyword(v3, (int)v3, &VertexArray)
      || PFileNode::IsKeyword(v3, (int)v3, &Render) )
      goto LABEL_26;
    v20 = v14;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "Unrecognized keyword in mesh file");
    PFileNode::ReportWarning((int)v3, v3, (PStringBase<char>)v20);
    goto LABEL_21;
  }
  v10 = (RenderMeshFragment *)operator new(0x20u);
  if ( v10 )
  {
    RenderMeshFragment::RenderMeshFragment(v10);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  _node = (PFileNode *)v12;
  if ( RenderMeshFragment::ParseFromFileNode((RenderMeshFragment *)v12, (int)v3, v3, v2) )
  {
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v2->m_Fragments, (BSPNODE *const *)&_node);
    goto LABEL_21;
  }
  v20 = v13;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "Error parsing mesh fragment");
  PFileNode::ReportError((int)v3, v3, (PStringBase<char>)v20);
  if ( v12 )
  {
    v18 = (*(_DWORD *)(v12 + 4))-- == 1;
    if ( v18 )
    {
      v19 = *(_DWORD *)v12;
      v20 = 1;
      (*(void (__thiscall **)(int, signed int))v19)(v12, 1);
    }
  }
LABEL_26:
  PFileNodeIter::~PFileNodeIter(&iter);
  return 0;
}

//----- (00445F60) --------------------------------------------------------  // acclient.c:130369
void __thiscall RenderMesh::GenerateFragmentIndexLists(RenderMesh *this)
{
  RenderMesh *v1; // ebx@1
  char *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ebp@1
  unsigned int v5; // eax@2
  int v6; // eax@3
  unsigned int v7; // eax@4
  int v8; // eax@7
  unsigned int v9; // eax@8

  v1 = this;
  v2 = (char *)&this->m_RenderLODFragmentIndices;
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&this->m_RenderLODFragmentIndices);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_OccluderFragmentIndices);
  v3 = v1->m_Fragments.m_num;
  v4 = 0;
  v1->m_ShadowLODFragmentIndex = -1;
  if ( v3 )
  {
    do
    {
      v5 = v1->m_Fragments.m_data[v4]->m_Type;
      switch ( v5 )
      {
        case 1u:
          v6 = *((_DWORD *)v2 + 1) & 0x7FFFFFFF;
          if ( *((_DWORD *)v2 + 2) < (unsigned int)v6
            || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
                SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v7)) )
            *(_DWORD *)(*(_DWORD *)v2 + 4 * (*((_DWORD *)v2 + 2))++) = v4;
          break;
        case 2u:
          v8 = v1->m_OccluderFragmentIndices.m_sizeAndDeallocate & 0x7FFFFFFF;
          if ( v1->m_OccluderFragmentIndices.m_num < v8
            || (v9 = SmartArray<UIChildFramework *,1>::get_new_size(v8 + 1),
                SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_OccluderFragmentIndices, v9)) )
            v1->m_OccluderFragmentIndices.m_data[v1->m_OccluderFragmentIndices.m_num++] = v4;
          break;
        case 4u:
          v1->m_ShadowLODFragmentIndex = v4;
          break;
      }
      ++v4;
    }
    while ( v4 < v1->m_Fragments.m_num );
  }
}

//----- (00446020) --------------------------------------------------------  // acclient.c:130420
char __thiscall RenderMesh::AddBatchToRenderLOD(RenderMesh *this, const unsigned int _LODIndex, RenderMeshBatch *_pNewBatch)
{
  RenderMesh *v3; // esi@1
  unsigned int v4; // eax@1
  const unsigned int v5; // edi@1
  RenderMeshFragment *v6; // eax@3
  const unsigned int v7; // eax@4
  BSPNODE *i_rData; // [sp+0h] [bp-4h]@1

  i_rData = (BSPNODE *)this;
  v3 = this;
  v4 = this->m_RenderLODFragmentIndices.m_num;
  v5 = _LODIndex;
  if ( _LODIndex < v4 )
  {
LABEL_7:
    RenderMeshFragment::AddMaterialBatch(v3->m_Fragments.m_data[v3->m_RenderLODFragmentIndices.m_data[v5]], _pNewBatch);
    return 1;
  }
  if ( _LODIndex == v4 )
  {
    v6 = (RenderMeshFragment *)operator new(0x20u);
    if ( v6 )
      RenderMeshFragment::RenderMeshFragment(v6);
    else
      v7 = 0;
    _LODIndex = v7;
    *(_DWORD *)(v7 + 8) = 1;
    i_rData = (BSPNODE *)v3->m_Fragments.m_num;
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v3->m_RenderLODFragmentIndices, &i_rData);
    SmartArray<UIElement_Button *,1>::AddToEnd(
      (SmartArray<BSPNODE *,1> *)&v3->m_Fragments,
      (BSPNODE *const *)&_LODIndex);
    goto LABEL_7;
  }
  return 0;
}

//----- (004460A0) --------------------------------------------------------  // acclient.c:130459
void __thiscall RenderMesh::CacheMaterialAttributes(RenderMesh *this)
{
  RenderMesh *v1; // ebp@1
  unsigned int v2; // ecx@1
  unsigned int v3; // eax@1
  char v4; // dl@1
  RenderMeshFragment *v5; // esi@2
  unsigned int v6; // ecx@2
  unsigned int v7; // edi@2
  RenderMeshBatch *v8; // eax@3
  unsigned int v9; // ecx@3
  MaterialInstance *v10; // eax@4
  RenderMaterial *v11; // esi@5
  bool v12; // cl@5
  bool v13; // al@5
  PSRefBufferCharData<char> **v14; // edi@8
  char *v15; // esi@9
  char *v16; // esi@13
  char *v17; // esi@20
  char *v18; // esi@23
  PSRefBufferCharData<char> **v19; // edi@30
  char *v20; // esi@31
  char *v21; // esi@35
  char *v22; // esi@42
  char *v23; // esi@45
  RenderMaterial *v24; // eax@50
  unsigned int v25; // eax@58
  unsigned int v26; // ecx@60
  bool v27; // [sp+20h] [bp-26h]@5
  bool v28; // [sp+21h] [bp-25h]@5
  PStringBase<char> MeshFileName; // [sp+22h] [bp-24h]@7
  PStringBase<char> ErrorString; // [sp+26h] [bp-20h]@20
  PStringBase<char> v31; // [sp+2Ah] [bp-1Ch]@42
  RenderMaterial *pRefMaterialTemplate; // [sp+2Eh] [bp-18h]@5
  unsigned int BatchIndex; // [sp+32h] [bp-14h]@2
  unsigned int LODIndex; // [sp+36h] [bp-10h]@1
  PStringBase<char> result; // [sp+3Ah] [bp-Ch]@8
  PStringBase<char> v36; // [sp+3Eh] [bp-8h]@30
  RenderMeshFragment *pLODFragment; // [sp+42h] [bp-4h]@2

  v1 = this;
  v2 = this->m_RenderLODFragmentIndices.m_num;
  v3 = 0;
  v4 = 0;
  v1->m_CachedSupportsLighting = 0;
  v1->m_CachedSupportsMultiPassLighting = 0;
  v1->m_CachedIsGlowing = 0;
  v1->m_CachedNeedAlphaBlendPass = 0;
  v1->m_CachedSupportsCombinedAmbientPass = 1;
  LODIndex = 0;
  if ( v2 )
  {
    do
    {
      v5 = v1->m_Fragments.m_data[v1->m_RenderLODFragmentIndices.m_data[v3]];
      v6 = v5->m_MaterialBatches.m_num;
      v7 = 0;
      pLODFragment = v1->m_Fragments.m_data[v1->m_RenderLODFragmentIndices.m_data[v3]];
      BatchIndex = 0;
      if ( v6 )
      {
        do
        {
          v8 = v5->m_MaterialBatches.m_data[v7];
          v9 = v8->m_MaterialIndex;
          if ( v9 != -1 )
          {
            v10 = v8->m_pContainerMesh->m_pMaterialArray->m_Materials.m_data[v9].second;
            if ( v10 )
            {
              v11 = v10->m_pMaterial;
              v12 = v11->m_SupportsLighting;
              v13 = v11->m_SupportsMultiPassLighting;
              pRefMaterialTemplate = v11;
              v27 = v12;
              v28 = v13;
              if ( v4 )
              {
                if ( v1->m_CachedSupportsMultiPassLighting != v13 )
                {
                  MeshFileName.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
                  if ( *(_DWORD *)&MeshFileName.m_charbuffer[-1].m_data[12] == 1 )
                  {
                    v14 = (PSRefBufferCharData<char> **)FileArray::GetFileNameForDummies(&result, v1->m_DID);
                    if ( MeshFileName.m_charbuffer != *v14 )
                    {
                      v15 = &MeshFileName.m_charbuffer[-2].m_data[12];
                      if ( !InterlockedDecrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]) && v15 )
                        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
                      MeshFileName.m_charbuffer = *v14;
                      InterlockedIncrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]);
                    }
                    v16 = &result.m_charbuffer[-2].m_data[12];
                    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v16 )
                      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
                    if ( *(_DWORD *)&MeshFileName.m_charbuffer[-1].m_data[12] == 1 )
                    {
                      if ( v1->m_DID.id == INVALID_DID_34.id )
                        PStringBase<char>::set(&MeshFileName, "Unknown");
                      else
                        PStringBase<char>::sprintf(&MeshFileName, "DataID:0x%08X", v1->m_DID.id);
                    }
                  }
                  ErrorString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
                  PStringBase<char>::sprintf(
                    &ErrorString,
                    "Mesh [%s] is assigned to materials that contradict each other!  At least one of the materials is designed for multi-pass lighting, but another material only works with vertex lighting.  This is not allowed!",
                    PStringBase<char>::null_string.m_charbuffer);
                  v17 = &ErrorString.m_charbuffer[-2].m_data[12];
                  if ( !InterlockedDecrement((volatile LONG *)&ErrorString.m_charbuffer[-1]) && v17 )
                    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
                  v18 = &MeshFileName.m_charbuffer[-2].m_data[12];
                  if ( !InterlockedDecrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]) && v18 )
                    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
                }
                if ( (v1->m_CachedSupportsMultiPassLighting || v28) && v1->m_CachedSupportsLighting != v27 )
                {
                  MeshFileName.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
                  if ( *(_DWORD *)&MeshFileName.m_charbuffer[-1].m_data[12] == 1 )
                  {
                    v19 = (PSRefBufferCharData<char> **)FileArray::GetFileNameForDummies(&v36, v1->m_DID);
                    if ( MeshFileName.m_charbuffer != *v19 )
                    {
                      v20 = &MeshFileName.m_charbuffer[-2].m_data[12];
                      if ( !InterlockedDecrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]) && v20 )
                        (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
                      MeshFileName.m_charbuffer = *v19;
                      InterlockedIncrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]);
                    }
                    v21 = &v36.m_charbuffer[-2].m_data[12];
                    if ( !InterlockedDecrement((volatile LONG *)&v36.m_charbuffer[-1]) && v21 )
                      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
                    if ( *(_DWORD *)&MeshFileName.m_charbuffer[-1].m_data[12] == 1 )
                    {
                      if ( v1->m_DID.id == INVALID_DID_34.id )
                        PStringBase<char>::set(&MeshFileName, "Unknown");
                      else
                        PStringBase<char>::sprintf(&MeshFileName, "DataID:0x%08X", v1->m_DID.id);
                    }
                  }
                  v31.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
                  PStringBase<char>::sprintf(
                    &v31,
                    "All materials used within a mesh must be either LIT or UNLIT materials, but not BOTH.  Mesh [%s] is breaking this rule!  Also keep in mind that all meshes within an object must be either LIT or UNLIT, but not BOTH.  Note that this limitation does not apply to 'SIMPLE LIT' materials -- those can be freely mixed with UNLIT materials within a mesh or entity.",
                    MeshFileName.m_charbuffer);
                  v22 = &v31.m_charbuffer[-2].m_data[12];
                  if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v22 )
                    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
                  v23 = &MeshFileName.m_charbuffer[-2].m_data[12];
                  if ( !InterlockedDecrement((volatile LONG *)&MeshFileName.m_charbuffer[-1]) && v23 )
                    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
                }
              }
              if ( v27 )
                v1->m_CachedSupportsLighting = 1;
              v24 = pRefMaterialTemplate;
              if ( v28 )
              {
                v1->m_CachedSupportsMultiPassLighting = 1;
                if ( !v24->m_SupportsCombinedAmbientPass )
                  v1->m_CachedSupportsCombinedAmbientPass = 0;
              }
              if ( v24->m_SupportsGlowing )
                v1->m_CachedIsGlowing = 1;
              if ( v24->m_NeedsAlphaBlendPass )
                v1->m_CachedNeedAlphaBlendPass = 1;
              v5 = pLODFragment;
              v7 = BatchIndex;
              v4 = 1;
            }
          }
          v25 = v5->m_MaterialBatches.m_num;
          ++v7;
          BatchIndex = v7;
        }
        while ( v7 < v25 );
        v3 = LODIndex;
      }
      v26 = v1->m_RenderLODFragmentIndices.m_num;
      ++v3;
      LODIndex = v3;
    }
    while ( v3 < v26 );
  }
}

//----- (00446430) --------------------------------------------------------  // acclient.c:130650
void __thiscall RenderMesh::UpdateCachedData(RenderMesh *this)
{
  RenderMesh *v1; // esi@1

  v1 = this;
  RenderMesh::CacheMaterialAttributes(this);
  RenderMesh::CacheHasSkeletalData(v1);
  RenderMesh::CacheRenderBoundingBox(v1);
}

//----- (00446450) --------------------------------------------------------  // acclient.c:130661
char __thiscall RenderMesh::GetSubObjects(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  char result; // al@1

  v1 = this;
  result = RenderMesh::GetMaterialsFromDatabase(this);
  if ( result )
  {
    if ( DBCache::IsRunTime() )
      RenderMesh::CacheMaterialAttributes(v1);
    result = 1;
  }
  return result;
}

//----- (00446480) --------------------------------------------------------  // acclient.c:130678
char __thiscall RenderMesh::Refresh(RenderMesh *this, IDClass<_tagDataID,32,0> _SubDataID)
{
  RenderMesh *v2; // esi@1

  v2 = this;
  RenderMesh::CacheMaterialAttributes(this);
  RenderMesh::CacheHasSkeletalData(v2);
  RenderMesh::CacheRenderBoundingBox(v2);
  return 1;
}

//----- (004464A0) --------------------------------------------------------  // acclient.c:130690
char __thiscall RenderMesh::CreateLODBatch(RenderMesh *this, const unsigned int _LODIndex, MaterialInstance *_pMaterial, PrimType _PrimitivesType, const unsigned int _ExistingVertexArrayIndex, const unsigned int _NumVertices, const unsigned int _VertexFormat, int _UseStaticVertices, int _OnlyWriteVerticesOnce, RenderVertexBuffer **_pNewVertexArray)
{
  RenderMesh *v10; // edi@1
  RenderMeshBatch *v11; // eax@1
  int v12; // eax@2
  int v13; // esi@2
  int v14; // eax@5
  int v15; // eax@6
  bool v17; // zf@9
  int v18; // eax@10

  v10 = this;
  v11 = (RenderMeshBatch *)operator new(0x34u);
  if ( v11 )
  {
    RenderMeshBatch::RenderMeshBatch(v11);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  *(_DWORD *)(v13 + 12) = v10;
  if ( !RenderMeshBatch::InitRenderBatch(
          (RenderMeshBatch *)v13,
          _pMaterial,
          _PrimitivesType,
          _ExistingVertexArrayIndex,
          _NumVertices,
          _VertexFormat,
          _UseStaticVertices,
          _OnlyWriteVerticesOnce,
          _pNewVertexArray) )
  {
    v14 = *(_DWORD *)(v13 + 4);
LABEL_6:
    v15 = v14 - 1;
    *(_DWORD *)(v13 + 4) = v15;
    if ( !v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    return 0;
  }
  v17 = RenderMesh::AddBatchToRenderLOD(v10, _LODIndex, (RenderMeshBatch *)v13) == 0;
  v14 = *(_DWORD *)(v13 + 4);
  if ( v17 )
    goto LABEL_6;
  v18 = v14 - 1;
  *(_DWORD *)(v13 + 4) = v18;
  if ( !v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  return 1;
}

//----- (00446540) --------------------------------------------------------  // acclient.c:130744
void __thiscall AutoStoreVersionArchive::~AutoStoreVersionArchive(AutoStoreVersionArchive *this)
{
  Archive *v1; // esi@1

  v1 = (Archive *)this;
  this->vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  if ( (this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive(v1);
}
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (00446570) --------------------------------------------------------  // acclient.c:130757
void __thiscall AutoStoreVersionArchive::InitForPacking(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer)
{
  this->m_bOnSerializingDoneCalled = 0;
  Archive::InitForPacking((Archive *)&this->vfptr, i_rInitializer, i_buffer);
}

//----- (00446580) --------------------------------------------------------  // acclient.c:130764
void __thiscall AutoStoreVersionArchive::InitForUnpacking(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer)
{
  this->m_bOnSerializingDoneCalled = 0;
  Archive::InitForUnpacking((Archive *)&this->vfptr, i_rInitializer, i_buffer);
}

//----- (00446590) --------------------------------------------------------  // acclient.c:130771
void __thiscall AutoStoreVersionArchive::InitForPacking(AutoStoreVersionArchive *this, SmartBuffer *i_buffer)
{
  AutoStoreVersionArchive *v2; // esi@1
  void *v3; // [sp+8h] [bp-4Ch]@1
  int v4; // [sp+Ch] [bp-48h]@1
  int v5; // [sp+10h] [bp-44h]@1
  char v6; // [sp+14h] [bp-40h]@1

  v2 = this;
  v3 = &v6;
  v4 = 8;
  v5 = 0;
  SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
    (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data,
    (int)&v3);
  if ( (v4 & 0x80000000) == 0x80000000 )
    operator delete[](v3);
  ArchiveVersionRow::SetVersion(&v2->m_SerializeVersionRow.m_rowInitialData, 0x436F7265u, g_TurbineCorePackVersion);
  Archive::InitForPacking((Archive *)&v2->vfptr, (ArchiveInitializer *)&v2->m_SerializeVersionRow.vfptr, i_buffer);
}

//----- (00446610) --------------------------------------------------------  // acclient.c:130793
void __thiscall AutoStoreVersionArchive::InitForUnpacking(AutoStoreVersionArchive *this, SmartBuffer *i_buffer)
{
  AutoStoreVersionArchive *v2; // esi@1
  void *v3; // [sp+8h] [bp-4Ch]@1
  int v4; // [sp+Ch] [bp-48h]@1
  int v5; // [sp+10h] [bp-44h]@1
  char v6; // [sp+14h] [bp-40h]@1

  v2 = this;
  v3 = &v6;
  v4 = 8;
  v5 = 0;
  SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
    (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data,
    (int)&v3);
  if ( (v4 & 0x80000000) == 0x80000000 )
    operator delete[](v3);
  Archive::InitForUnpacking((Archive *)&v2->vfptr, (ArchiveInitializer *)&v2->m_SerializeVersionRow.vfptr, i_buffer);
}

//----- (00446680) --------------------------------------------------------  // acclient.c:130814
void __thiscall AutoStoreVersionArchive::InitForPacking(AutoStoreVersionArchive *this, unsigned int i_iCoreVersion, SmartBuffer *i_buffer)
{
  AutoStoreVersionArchive *v3; // esi@1
  void *v4; // [sp+8h] [bp-4Ch]@1
  int v5; // [sp+Ch] [bp-48h]@1
  int v6; // [sp+10h] [bp-44h]@1
  char v7; // [sp+14h] [bp-40h]@1

  v3 = this;
  v4 = &v7;
  v5 = 8;
  v6 = 0;
  SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
    (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data,
    (int)&v4);
  if ( (v5 & 0x80000000) == 0x80000000 )
    operator delete[](v4);
  ArchiveVersionRow::SetVersion(&v3->m_SerializeVersionRow.m_rowInitialData, 0x436F7265u, i_iCoreVersion);
  Archive::InitForPacking((Archive *)&v3->vfptr, (ArchiveInitializer *)&v3->m_SerializeVersionRow.vfptr, i_buffer);
}

//----- (00446700) --------------------------------------------------------  // acclient.c:130836
void __thiscall AutoStoreVersionArchive::InitForPacking(AutoStoreVersionArchive *this, ArchiveVersionRow *i_rowInitialData, SmartBuffer *i_buffer)
{
  AutoStoreVersionArchive *v3; // esi@1

  v3 = this;
  SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
    (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&this->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data,
    (int)&i_rowInitialData->m_aVersions);
  Archive::InitForPacking((Archive *)&v3->vfptr, (ArchiveInitializer *)&v3->m_SerializeVersionRow.vfptr, i_buffer);
}

//----- (00446730) --------------------------------------------------------  // acclient.c:130848
char __thiscall RenderMesh::InitLoad(RenderMesh *this)
{
  RenderMesh *v1; // esi@1
  char result; // al@4

  v1 = this;
  RenderMesh::GenerateFragmentIndexLists(this);
  if ( v1->m_RenderLODFragmentIndices.m_num )
  {
    RenderMesh::OrganizeFragmentBatches(v1);
    RenderMesh::CacheMaterialAttributes(v1);
    RenderMesh::CacheHasSkeletalData(v1);
    RenderMesh::CacheRenderBoundingBox(v1);
    if ( !DBCache::IsRunTime() )
      RenderMesh::GenerateTopologyForFragments(v1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00446780) --------------------------------------------------------  // acclient.c:130873
void __thiscall AutoStoreVersionArchive::AutoStoreVersionArchive(AutoStoreVersionArchive *this, Archive::tagUnpacking __formal, SmartBuffer *buff)
{
  AutoStoreVersionArchive *v3; // esi@1

  v3 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  this->m_flags = 0;
  this->m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&this->m_buffer);
  v3->m_currOffset = 0;
  v3->m_pcUserDataHash = 0;
  v3->m_pVersionStack = 0;
  v3->vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  v3->m_SerializeVersionRow.vfptr = (ArchiveInitializerVtbl *)&AutoStoreVersionArchive::tagSerializeVersionRow::vftable;
  v3->m_SerializeVersionRow.m_rowInitialData.vfptr = (ArchiveVersionRowVtbl *)&ArchiveVersionRow::vftable;
  v3->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data = (ArchiveVersionRow::VersionEntry *)v3->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_aPrimitiveInplaceMemory;
  v3->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate = 8;
  v3->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_num = 0;
  v3->m_bOnSerializingDoneCalled = 1;
  AutoStoreVersionArchive::InitForUnpacking(v3, buff);
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);
// 799A90: using guessed type bool (__thiscall *AutoStoreVersionArchive::tagSerializeVersionRow::vftable)(AutoStoreVersionArchive::tagSerializeVersionRow *this, struct Archive *);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (004467F0) --------------------------------------------------------  // acclient.c:130900
char __thiscall RenderMesh::ParseFromVersionedFileNode(RenderMesh *this, PFileNode *_node)
{
  RenderMesh *v2; // esi@1
  PSRefBufferCharData<char> *v3; // ecx@1
  int v4; // edi@1
  char result; // al@2
  PSRefBufferCharData<char> *v6; // ecx@3
  char v7; // bl@5
  PStringBase<char> v8; // [sp-4h] [bp-A0h]@2
  SmartBuffer buffer; // [sp+Ch] [bp-90h]@3
  AutoStoreVersionArchive archive; // [sp+18h] [bp-84h]@5

  v2 = this;
  v4 = PFileNode::GetLeaf(_node);
  if ( v4 )
  {
    SmartBuffer::SmartBuffer(&buffer);
    if ( PFileNode::GetNameAsBinary((PFileNode *)v4, v4, &buffer) )
    {
      AutoStoreVersionArchive::AutoStoreVersionArchive(&archive, 0, &buffer);
      Archive::SetDBLoader((Archive *)&archive.vfptr, 1);
      ((void (__thiscall *)(RenderMesh *, AutoStoreVersionArchive *))v2->vfptr[1].IUnknown_AddRef)(v2, &archive);
      AutoStoreVersionArchive::OnSerializingDone(&archive);
      v7 = ~(unsigned __int8)(archive.m_flags >> 2) & 1;
      archive.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
      if ( (archive.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](archive.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
      Archive::~Archive((Archive *)&archive.vfptr);
      SmartBuffer::ReleaseMasterBuffer(&buffer);
      result = v7;
    }
    else
    {
      v8.m_charbuffer = v6;
      PStringBase<char>::PStringBase<char>(&v8, "Failed retrieving binary mesh data");
      PFileNode::ReportError(v4, _node, v8);
      SmartBuffer::ReleaseMasterBuffer(&buffer);
      result = 0;
    }
  }
  else
  {
    v8.m_charbuffer = v3;
    PStringBase<char>::PStringBase<char>(&v8, "Expected binary mesh data, got nothing!");
    PFileNode::ReportError(0, _node, v8);
    result = 0;
  }
  return result;
}
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (00446900) --------------------------------------------------------  // acclient.c:130952
char __thiscall RenderMesh::FromFileNode(RenderMesh *this, PFileNode *_pBaseNode)
{
  int v2; // edi@1
  PFileNode *i; // esi@2
  PSRefBufferCharData<char> *v5; // ecx@8
  unsigned int v6; // esi@14
  PStringBase<char> v7; // [sp-4h] [bp-18h]@11
  PFileNodeIter iter; // [sp+8h] [bp-Ch]@2

  v2 = (int)this;
  if ( !_pBaseNode )
    return 0;
  PFileNodeIter::PFileNodeIter(&iter, _pBaseNode);
  for ( i = PFileNodeIter::Curr(&iter); i; i = (PFileNode *)PFileNodeIter::Next(&iter) )
  {
    if ( !PFileNode::IsKeyword(i, v2, &PreprocHeader) )
    {
      if ( PFileNode::IsKeyword(i, v2, &RenderMesh) )
      {
        if ( !RenderMesh::ParseFromFileNode((RenderMesh *)v2, i) )
          goto LABEL_6;
      }
      else if ( PFileNode::IsKeyword(i, v2, &RenderMeshVersion) )
      {
        if ( !RenderMesh::ParseFromVersionedFileNode((RenderMesh *)v2, i) )
          goto LABEL_6;
      }
      else
      {
        v7.m_charbuffer = v5;
        PStringBase<char>::PStringBase<char>(&v7, "Unknown keyword in mesh");
        PFileNode::ReportWarning(v2, i, v7);
      }
    }
  }
  RenderMesh::GenerateFragmentIndexLists((RenderMesh *)v2);
  if ( !*(_DWORD *)(v2 + 88) )
  {
LABEL_6:
    PFileNodeIter::~PFileNodeIter(&iter);
    return 0;
  }
  RenderMesh::GetMaterialsFromDatabase((RenderMesh *)v2);
  v6 = 0;
  if ( *(_DWORD *)(v2 + 88) )
  {
    do
      RenderMeshFragment::OrganizeMaterialBatches(*(RenderMeshFragment **)(*(_DWORD *)(v2 + 68)
                                                                         + 4
                                                                         * *(_DWORD *)(*(_DWORD *)(v2 + 80) + 4 * v6++)));
    while ( v6 < *(_DWORD *)(v2 + 88) );
  }
  RenderMesh::CacheMaterialAttributes((RenderMesh *)v2);
  RenderMesh::CacheHasSkeletalData((RenderMesh *)v2);
  RenderMesh::CacheRenderBoundingBox((RenderMesh *)v2);
  if ( !DBCache::IsRunTime() )
    RenderMesh::GenerateTopologyForFragments((RenderMesh *)v2);
  PFileNodeIter::~PFileNodeIter(&iter);
  return 1;
}

//----- (006C7D70) --------------------------------------------------------  // acclient.c:735769
void _E73_37()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_12, PFID_A8R8G8B8);
}

//----- (006C7D80) --------------------------------------------------------  // acclient.c:735775
void _E91_14()
{
  LODWORD(dword_838048) = 1053364187;
}

//----- (006C7D90) --------------------------------------------------------  // acclient.c:735781
void _E93_4()
{
  outside_val_10 = 1000.0 + 1.0;
}

//----- (006C7DB0) --------------------------------------------------------  // acclient.c:735787
void _E95_4()
{
  block_length_10 = 24.0 * 8.0;
}

//----- (006C7DD0) --------------------------------------------------------  // acclient.c:735793
void _E97_14()
{
  half_square_length_10 = 24.0 * 0.5;
}

//----- (006C7DF0) --------------------------------------------------------  // acclient.c:735799
int _E99_0()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_5, "Render.TextureFiltering");
  return atexit(sub_730690);
}

//----- (006C7E10) --------------------------------------------------------  // acclient.c:735806
int _E102_4()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_5, "Render.LandscapeDetailTextures");
  return atexit(sub_7306C0);
}

//----- (006C7E30) --------------------------------------------------------  // acclient.c:735813
int _E105_0()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_5, "Render.BuildingDetailTextures");
  return atexit(sub_7306F0);
}

//----- (006C7E50) --------------------------------------------------------  // acclient.c:735820
int _E108_3()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_5, "Render.FieldOfView");
  return atexit(sub_730720);
}

//----- (006C7E70) --------------------------------------------------------  // acclient.c:735827
int _E111_1()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_5, "Render.LandscapeTextureDetail");
  return atexit(sub_730750);
}

//----- (006C7E90) --------------------------------------------------------  // acclient.c:735834
int _E114_3()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_5, "Render.EnvironmentTextureDetail");
  return atexit(sub_730780);
}

//----- (006C7EB0) --------------------------------------------------------  // acclient.c:735841
int _E117_1()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_5, "Render.SceneryDrawDistance");
  return atexit(sub_7307B0);
}

//----- (006C7ED0) --------------------------------------------------------  // acclient.c:735848
int _E120_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_5, "Render.LandscapeDrawDistance");
  return atexit(sub_7307E0);
}

//----- (006C7EF0) --------------------------------------------------------  // acclient.c:735855
int _E123_1()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_5, "Render.ScreenBrightness");
  return atexit(_E124_95);
}

//----- (006C7F10) --------------------------------------------------------  // acclient.c:735862
int _E126_3()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_5, "Render.AspectRatio");
  return atexit(_E127_84);
}

//----- (006C7F30) --------------------------------------------------------  // acclient.c:735869
int _E129_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_5, "Render.DisplayAdapter");
  return atexit(_E130_76);
}

//----- (006C7F50) --------------------------------------------------------  // acclient.c:735876
int _E132_3()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_5, "Render.MaxHardwareClass");
  return atexit(_E133_69);
}

//----- (006C7F70) --------------------------------------------------------  // acclient.c:735883
int _E135_2()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_5, "Render.AutomaticDegrades");
  return atexit(_E136_53);
}

//----- (006C7F90) --------------------------------------------------------  // acclient.c:735890
int _E138_3()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_5, "Render.GraphicsPerformance");
  return atexit(_E139_54);
}

//----- (006C7FB0) --------------------------------------------------------  // acclient.c:735897
int _E141_3()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_5, "Render.DegradeDistance");
  return atexit(_E142_51);
}

//----- (006C7FD0) --------------------------------------------------------  // acclient.c:735904
int _E144_3()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_5, "Render.MultiPassAlpha");
  return atexit(_E145_53);
}

//----- (006C7FF0) --------------------------------------------------------  // acclient.c:735911
int _E147_3()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_5, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8380A0, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8380A4, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8380A8, "Anisotropic");
  return atexit(_E148_52);
}

//----- (006C8040) --------------------------------------------------------  // acclient.c:735921
int _E150_3()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_5, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8380B0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8380B4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8380B8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8380BC, "VeryHigh");
  return atexit(_E151_50);
}

//----- (006C80A0) --------------------------------------------------------  // acclient.c:735932
int _E153_3()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_5, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8380C4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8380C8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8380CC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8380D0, "VeryHigh");
  return atexit(_E154_51);
}

//----- (006C8100) --------------------------------------------------------  // acclient.c:735943
int _E156_4()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_5, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8380D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8380DC, "High");
  return atexit(_E157_48);
}

//----- (006C8140) --------------------------------------------------------  // acclient.c:735952
int _E159_3()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_5, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8380E4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8380E8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8380EC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8380F0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8380F4, "Extreme");
  return atexit(_E160_51);
}

//----- (006C81B0) --------------------------------------------------------  // acclient.c:735964
int _E162_4()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_5, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8380FC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_838100, "Wide");
  return atexit(_E163_44);
}

//----- (006C81F0) --------------------------------------------------------  // acclient.c:735973
int _E165_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_11, "None");
  return atexit(_E166_46);
}

//----- (006C8210) --------------------------------------------------------  // acclient.c:735980
int _E168_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_11, "Speed");
  return atexit(_E169_45);
}

//----- (006C8230) --------------------------------------------------------  // acclient.c:735987
int _E171_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_11, "Noise");
  return atexit(_E172_43);
}

//----- (006C8250) --------------------------------------------------------  // acclient.c:735994
int _E174_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_11, "Sine");
  return atexit(_E175_40);
}

//----- (006C8270) --------------------------------------------------------  // acclient.c:736001
int _E177_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_11, "Square");
  return atexit(_E178_40);
}

//----- (006C8290) --------------------------------------------------------  // acclient.c:736008
int _E180_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_11, "Bounce");
  return atexit(_E181_40);
}

//----- (006C82B0) --------------------------------------------------------  // acclient.c:736015
int _E183_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_11, "Perlin");
  return atexit(_E184_38);
}

//----- (006C82D0) --------------------------------------------------------  // acclient.c:736022
int _E186_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_11, "Fractal");
  return atexit(_E187_37);
}

//----- (006C82F0) --------------------------------------------------------  // acclient.c:736029
int _E189_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_11, "FrameLoop");
  return atexit(_E190_38);
}

//----- (006C8310) --------------------------------------------------------  // acclient.c:736036
int _E192_3()
{
  return atexit(_E193_35);
}

//----- (006C8320) --------------------------------------------------------  // acclient.c:736042
int _E195_2()
{
  return atexit(_E196_43);
}

//----- (006C8330) --------------------------------------------------------  // acclient.c:736048
int _E198_3()
{
  return atexit(_E199_35);
}

//----- (006C8340) --------------------------------------------------------  // acclient.c:736054
int _E201_1()
{
  PStringBase<char>::PStringBase<char>(&PHeader, "PREPROC_HEADER");
  return atexit(_E202_36);
}

//----- (006C8360) --------------------------------------------------------  // acclient.c:736061
int _E204_0()
{
  PStringBase<char>::PStringBase<char>(&VertexArray, "VertexArray");
  return atexit(_E205_33);
}

//----- (006C8380) --------------------------------------------------------  // acclient.c:736068
int _E207()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray, "BinaryVertexArray");
  return atexit(_E208_37);
}

//----- (006C83A0) --------------------------------------------------------  // acclient.c:736075
int _E210_0()
{
  PStringBase<char>::PStringBase<char>(&VertexType_0, "VertexType");
  return atexit(_E211_33);
}

//----- (006C83C0) --------------------------------------------------------  // acclient.c:736082
int _E213_1()
{
  PStringBase<char>::PStringBase<char>(&VertexData, "VertexData");
  return atexit(_E214_36);
}

//----- (006C83E0) --------------------------------------------------------  // acclient.c:736089
int _E216_1()
{
  PStringBase<char>::PStringBase<char>(&Vertex, "Vertex");
  return atexit(_E217_32);
}

//----- (006C8400) --------------------------------------------------------  // acclient.c:736096
int _E219()
{
  PStringBase<char>::PStringBase<char>(&Index, "Index");
  return atexit(_E220_32);
}

//----- (006C8420) --------------------------------------------------------  // acclient.c:736103
int _E222()
{
  PStringBase<char>::PStringBase<char>(&Origin, "P");
  return atexit(_E223_32);
}

//----- (006C8440) --------------------------------------------------------  // acclient.c:736110
int _E225()
{
  PStringBase<char>::PStringBase<char>(&Normal, "N");
  return atexit(_E226_18);
}

//----- (006C8460) --------------------------------------------------------  // acclient.c:736117
int _E228()
{
  PStringBase<char>::PStringBase<char>(&Diffuse, "Diffuse");
  return atexit(_E229_18);
}

//----- (006C8480) --------------------------------------------------------  // acclient.c:736124
int _E231()
{
  PStringBase<char>::PStringBase<char>(&Specular, "Specular");
  return atexit(_E232_18);
}

//----- (006C84A0) --------------------------------------------------------  // acclient.c:736131
int _E234()
{
  PStringBase<char>::PStringBase<char>(&UVS, "UVS");
  return atexit(_E235_18);
}

//----- (006C84C0) --------------------------------------------------------  // acclient.c:736138
int _E237()
{
  PStringBase<char>::PStringBase<char>(&VectorS, "VectorS");
  return atexit(_E238_16);
}

//----- (006C84E0) --------------------------------------------------------  // acclient.c:736145
int _E240()
{
  PStringBase<char>::PStringBase<char>(&VectorT, "VectorT");
  return atexit(_E241_16);
}

//----- (006C8500) --------------------------------------------------------  // acclient.c:736152
int _E243()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT, "VectorSxT");
  return atexit(_E244_16);
}

//----- (006C8520) --------------------------------------------------------  // acclient.c:736159
int _E246()
{
  PStringBase<char>::PStringBase<char>(&Weights, "Weights");
  return atexit(_E247_15);
}

//----- (006C8540) --------------------------------------------------------  // acclient.c:736166
int _E249()
{
  PStringBase<char>::PStringBase<char>(&Importance, "Importance");
  return atexit(_E250_15);
}

//----- (006C8560) --------------------------------------------------------  // acclient.c:736173
int _E252()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl, "PhysMtl");
  return atexit(_E253_15);
}

//----- (006C8580) --------------------------------------------------------  // acclient.c:736180
int _E255()
{
  PStringBase<char>::PStringBase<char>(&Material, "Material");
  return atexit(_E256_15);
}

//----- (006C85A0) --------------------------------------------------------  // acclient.c:736187
int _E258()
{
  PStringBase<char>::PStringBase<char>(&ID, "ID");
  return atexit(_E259_16);
}

//----- (006C85C0) --------------------------------------------------------  // acclient.c:736194
int _E261()
{
  PStringBase<char>::PStringBase<char>(&FileName, "FileName");
  return atexit(_E262_16);
}

//----- (006C85E0) --------------------------------------------------------  // acclient.c:736201
int _E264()
{
  PStringBase<char>::PStringBase<char>(&Polygon, "Polygon");
  return atexit(_E265_16);
}

//----- (006C8600) --------------------------------------------------------  // acclient.c:736208
int _E267()
{
  PStringBase<char>::PStringBase<char>(&ID_0, "ID");
  return atexit(_E268_15);
}

//----- (006C8620) --------------------------------------------------------  // acclient.c:736215
int _E270()
{
  PStringBase<char>::PStringBase<char>(&Indices, "INDICES");
  return atexit(_E271_14);
}

//----- (006C8640) --------------------------------------------------------  // acclient.c:736222
int _E273()
{
  PStringBase<char>::PStringBase<char>(&MaterialID, "MaterialID");
  return atexit(_E274_14);
}

//----- (006C8660) --------------------------------------------------------  // acclient.c:736229
int _E276()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID, "PhysMaterialID");
  return atexit(_E277_14);
}

//----- (006C8680) --------------------------------------------------------  // acclient.c:736236
int _E279()
{
  PStringBase<char>::PStringBase<char>(&Markings, "Markings");
  return atexit(_E280_13);
}

//----- (006C86A0) --------------------------------------------------------  // acclient.c:736243
int _E282()
{
  PStringBase<char>::PStringBase<char>(&Material_0, "Material");
  return atexit(_E283_13);
}

//----- (006C86C0) --------------------------------------------------------  // acclient.c:736250
int _E285()
{
  PStringBase<char>::PStringBase<char>(&Index_0, "Index");
  return atexit(_E286_12);
}

//----- (006C86E0) --------------------------------------------------------  // acclient.c:736257
int _E288()
{
  PStringBase<char>::PStringBase<char>(&Filename, "Filename");
  return atexit(_E289_11);
}

//----- (006C8700) --------------------------------------------------------  // acclient.c:736264
int _E291()
{
  PStringBase<char>::PStringBase<char>(&Surface, "Surface");
  return atexit(_E292_12);
}

//----- (006C8720) --------------------------------------------------------  // acclient.c:736271
int _E294()
{
  PStringBase<char>::PStringBase<char>(&CellPoly, "CellPoly");
  return atexit(_E295_11);
}

//----- (006C8740) --------------------------------------------------------  // acclient.c:736278
int _E297()
{
  PStringBase<char>::PStringBase<char>(&Sphere, "Sphere");
  return atexit(_E298_12);
}

//----- (006C8760) --------------------------------------------------------  // acclient.c:736285
int _E300()
{
  PStringBase<char>::PStringBase<char>(&Side, "Side");
  return atexit(_E301_10);
}

//----- (006C8780) --------------------------------------------------------  // acclient.c:736292
int _E303()
{
  PStringBase<char>::PStringBase<char>(&Positive, "Positive");
  return atexit(_E304_11);
}

//----- (006C87A0) --------------------------------------------------------  // acclient.c:736299
int _E306()
{
  PStringBase<char>::PStringBase<char>(&Negative, "Negative");
  return atexit(_E307_10);
}

//----- (006C87C0) --------------------------------------------------------  // acclient.c:736306
int _E309()
{
  PStringBase<char>::PStringBase<char>(&Polygon_0, "PolygonIndex");
  return atexit(_E310_11);
}

//----- (006C87E0) --------------------------------------------------------  // acclient.c:736313
int _E312()
{
  PStringBase<char>::PStringBase<char>(&OtherCell, "OtherCellMeshIndex");
  return atexit(_E313_10);
}

//----- (006C8800) --------------------------------------------------------  // acclient.c:736320
int _E315()
{
  PStringBase<char>::PStringBase<char>(&CellPortal, "CellPortal");
  return atexit(_E316_11);
}

//----- (006C8820) --------------------------------------------------------  // acclient.c:736327
int _E318()
{
  PStringBase<char>::PStringBase<char>(&Portal, "PortalIndex");
  return atexit(_E319_10);
}

//----- (006C8840) --------------------------------------------------------  // acclient.c:736334
int _E321()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_0, "OtherCellID");
  return atexit(_E322_10);
}

//----- (006C8860) --------------------------------------------------------  // acclient.c:736341
int _E324()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal, "OtherPortalIndex");
  return atexit(_E325_9);
}

//----- (006C8880) --------------------------------------------------------  // acclient.c:736348
int _E327()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch, "ExactMatch");
  return atexit(_E328_10);
}

//----- (006C88A0) --------------------------------------------------------  // acclient.c:736355
int _E330()
{
  PStringBase<char>::PStringBase<char>(&StabList, "StabList");
  return atexit(_E331_9);
}

//----- (006C88C0) --------------------------------------------------------  // acclient.c:736362
int _E333()
{
  PStringBase<char>::PStringBase<char>(&Period, "Period");
  return atexit(_E334_9);
}

//----- (006C88E0) --------------------------------------------------------  // acclient.c:736369
int _E336()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation, "GrannyAnimation");
  return atexit(_E337_9);
}

//----- (006C8900) --------------------------------------------------------  // acclient.c:736376
int _E339()
{
  PStringBase<char>::PStringBase<char>(&Transform, "Transform");
  return atexit(_E340_9);
}

//----- (006C8920) --------------------------------------------------------  // acclient.c:736383
int _E342()
{
  PStringBase<char>::PStringBase<char>(&Scale, "Scale");
  return atexit(_E343_6);
}

//----- (006C8940) --------------------------------------------------------  // acclient.c:736390
int _E345()
{
  PStringBase<char>::PStringBase<char>(&Weight, "Weight");
  return atexit(_E346_6);
}

//----- (006C8960) --------------------------------------------------------  // acclient.c:736397
int _E348()
{
  PStringBase<char>::PStringBase<char>(&Offset, "Offset");
  return atexit(_E349_6);
}

//----- (006C8980) --------------------------------------------------------  // acclient.c:736404
int _E351()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_0, "Quaternion");
  return atexit(_E352_6);
}

//----- (006C89A0) --------------------------------------------------------  // acclient.c:736411
int _E354()
{
  PStringBase<char>::PStringBase<char>(&Rotation, "Rotation");
  return atexit(_E355_6);
}

//----- (006C89C0) --------------------------------------------------------  // acclient.c:736418
int _E357()
{
  PStringBase<char>::PStringBase<char>(&STime, "STime");
  return atexit(_E358_6);
}

//----- (006C89E0) --------------------------------------------------------  // acclient.c:736425
int _E360()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines, "PhysicsSplines");
  return atexit(_E361_6);
}

//----- (006C8A00) --------------------------------------------------------  // acclient.c:736432
int _E363()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities, "BoneOpacities");
  return atexit(_E364_6);
}

//----- (006C8A20) --------------------------------------------------------  // acclient.c:736439
int _E366()
{
  PStringBase<char>::PStringBase<char>(&LowPt, "LowPoint");
  return atexit(_E367_6);
}

//----- (006C8A40) --------------------------------------------------------  // acclient.c:736446
int _E369()
{
  PStringBase<char>::PStringBase<char>(&Radius, "Radius");
  return atexit(_E370_6);
}

//----- (006C8A60) --------------------------------------------------------  // acclient.c:736453
int _E372()
{
  PStringBase<char>::PStringBase<char>(&Height, "Height");
  return atexit(_E373_6);
}

//----- (006C8A80) --------------------------------------------------------  // acclient.c:736460
int _E375()
{
  PStringBase<char>::PStringBase<char>(&Texture2D, "Texture2D");
  return atexit(_E376_6);
}

//----- (006C8AA0) --------------------------------------------------------  // acclient.c:736467
int _E378()
{
  PStringBase<char>::PStringBase<char>(&Texture3D, "Texture3D");
  return atexit(_E379_6);
}

//----- (006C8AC0) --------------------------------------------------------  // acclient.c:736474
int _E381()
{
  PStringBase<char>::PStringBase<char>(&TextureCube, "TextureCube");
  return atexit(_E382_6);
}

//----- (006C8AE0) --------------------------------------------------------  // acclient.c:736481
int _E384()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D, "TextureMovie2D");
  return atexit(_E385_6);
}

//----- (006C8B00) --------------------------------------------------------  // acclient.c:736488
int _E387()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName, "MovieFile");
  return atexit(_E388_6);
}

//----- (006C8B20) --------------------------------------------------------  // acclient.c:736495
int _E390()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond, "MovieFPS");
  return atexit(_E391_6);
}

//----- (006C8B40) --------------------------------------------------------  // acclient.c:736502
int _E393()
{
  PStringBase<char>::PStringBase<char>(&Levels, "Levels");
  return atexit(_E394_6);
}

//----- (006C8B60) --------------------------------------------------------  // acclient.c:736509
int _E396()
{
  PStringBase<char>::PStringBase<char>(&NodeName, "Instance");
  return atexit(_E397_6);
}

//----- (006C8B80) --------------------------------------------------------  // acclient.c:736516
int _E399()
{
  PStringBase<char>::PStringBase<char>(&Material_1, "Material");
  return atexit(_E400_6);
}

//----- (006C8BA0) --------------------------------------------------------  // acclient.c:736523
int _E402()
{
  PStringBase<char>::PStringBase<char>(&MaterialType, "MaterialType");
  return atexit(_E403_6);
}

//----- (006C8BC0) --------------------------------------------------------  // acclient.c:736530
int _E405()
{
  PStringBase<char>::PStringBase<char>(&Modifier, "Modifier");
  return atexit(_E406_6);
}

//----- (006C8BE0) --------------------------------------------------------  // acclient.c:736537
int _E408()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows, "AllowStencilShadows");
  return atexit(_E409_6);
}

//----- (006C8C00) --------------------------------------------------------  // acclient.c:736544
int _E411()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry, "DiscardGeometry");
  return atexit(_E412_6);
}

//----- (006C8C20) --------------------------------------------------------  // acclient.c:736551
int _E414()
{
  PStringBase<char>::PStringBase<char>(&NodeName_0, "Material");
  return atexit(_E415_6);
}

//----- (006C8C40) --------------------------------------------------------  // acclient.c:736558
int _E417()
{
  PStringBase<char>::PStringBase<char>(&SortMode, "SortMode");
  return atexit(_E418_6);
}

//----- (006C8C60) --------------------------------------------------------  // acclient.c:736565
int _E420()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None, "None");
  return atexit(_E421_6);
}

//----- (006C8C80) --------------------------------------------------------  // acclient.c:736572
int _E423()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle, "Triangle");
  return atexit(_E424_6);
}

//----- (006C8CA0) --------------------------------------------------------  // acclient.c:736579
int _E426()
{
  PStringBase<char>::PStringBase<char>(&NodeName_1, "Modifier");
  return atexit(_E427_6);
}

//----- (006C8CC0) --------------------------------------------------------  // acclient.c:736586
int _E429()
{
  PStringBase<char>::PStringBase<char>(&NodeName_2, "Property");
  return atexit(_E430_6);
}

//----- (006C8CE0) --------------------------------------------------------  // acclient.c:736593
int _E432()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA, "Data");
  return atexit(_E433_6);
}

//----- (006C8D00) --------------------------------------------------------  // acclient.c:736600
int _E435()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM, "Waveform");
  return atexit(_E436_6);
}

//----- (006C8D20) --------------------------------------------------------  // acclient.c:736607
int _E438()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR, "Color");
  return atexit(_E439_6);
}

//----- (006C8D40) --------------------------------------------------------  // acclient.c:736614
int _E441()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE, "Texture");
  return atexit(_E442_6);
}

//----- (006C8D60) --------------------------------------------------------  // acclient.c:736621
int _E444()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL, "Bool");
  return atexit(_E445_6);
}

//----- (006C8D80) --------------------------------------------------------  // acclient.c:736628
int _E447()
{
  PStringBase<char>::PStringBase<char>(&NodeName_3, "Layer");
  return atexit(_E448_6);
}

//----- (006C8DA0) --------------------------------------------------------  // acclient.c:736635
int _E450()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate, "UVTranslate");
  return atexit(_E451_6);
}

//----- (006C8DC0) --------------------------------------------------------  // acclient.c:736642
int _E453()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate, "UVRotate");
  return atexit(_E454_6);
}

//----- (006C8DE0) --------------------------------------------------------  // acclient.c:736649
int _E456()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale, "UVScale");
  return atexit(_E457_6);
}

//----- (006C8E00) --------------------------------------------------------  // acclient.c:736656
int _E459()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform, "UVTransform");
  return atexit(_E460_6);
}

//----- (006C8E20) --------------------------------------------------------  // acclient.c:736663
int _E462()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags, "TrueFlags");
  return atexit(_E463_6);
}

//----- (006C8E40) --------------------------------------------------------  // acclient.c:736670
int _E465()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags, "FalseFlags");
  return atexit(_E466_6);
}

//----- (006C8E60) --------------------------------------------------------  // acclient.c:736677
int _E468()
{
  PStringBase<char>::PStringBase<char>(&RenderPass, "RenderPass");
  return atexit(_E469_6);
}

//----- (006C8E80) --------------------------------------------------------  // acclient.c:736684
int _E471()
{
  PStringBase<char>::PStringBase<char>(&Blend, "Blend");
  return atexit(_E472_6);
}

//----- (006C8EA0) --------------------------------------------------------  // acclient.c:736691
int _E474()
{
  PStringBase<char>::PStringBase<char>(&DepthTest, "DepthTest");
  return atexit(_E475_6);
}

//----- (006C8EC0) --------------------------------------------------------  // acclient.c:736698
int _E477()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite, "DepthWrite");
  return atexit(_E478_6);
}

//----- (006C8EE0) --------------------------------------------------------  // acclient.c:736705
int _E480()
{
  PStringBase<char>::PStringBase<char>(&CullMode, "CullMode");
  return atexit(_E481_6);
}

//----- (006C8F00) --------------------------------------------------------  // acclient.c:736712
int _E483()
{
  PStringBase<char>::PStringBase<char>(&DepthFog, "DepthFog");
  return atexit(_E484_6);
}

//----- (006C8F20) --------------------------------------------------------  // acclient.c:736719
int _E486()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode, "AlphaTestMode");
  return atexit(_E487_6);
}

//----- (006C8F40) --------------------------------------------------------  // acclient.c:736726
int _E489()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef, "AlphaTestRef");
  return atexit(_E490_6);
}

//----- (006C8F60) --------------------------------------------------------  // acclient.c:736733
int _E492()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting, "FFUseLighting");
  return atexit(_E493_6);
}

//----- (006C8F80) --------------------------------------------------------  // acclient.c:736740
int _E495()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor, "FFUseDyeColorInTFactor");
  return atexit(_E496_6);
}

//----- (006C8FA0) --------------------------------------------------------  // acclient.c:736747
int _E498()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting, "FFUseSpecularLighting");
  return atexit(_E499_6);
}

//----- (006C8FC0) --------------------------------------------------------  // acclient.c:736754
int _E501()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog, "FFUseDistanceFog");
  return atexit(_E502_6);
}

//----- (006C8FE0) --------------------------------------------------------  // acclient.c:736761
int _E504()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse, "FFUseVertexDiffuse");
  return atexit(_E505_6);
}

//----- (006C9000) --------------------------------------------------------  // acclient.c:736768
int _E507()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular, "FFUseVertexSpecular");
  return atexit(_E508_6);
}

//----- (006C9020) --------------------------------------------------------  // acclient.c:736775
int _E510()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights, "ShaderSupportsDynamicLights");
  return atexit(_E511_6);
}

//----- (006C9040) --------------------------------------------------------  // acclient.c:736782
int _E513()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency, "UsesTransparency");
  return atexit(_E514_6);
}

//----- (006C9060) --------------------------------------------------------  // acclient.c:736789
int _E516()
{
  PStringBase<char>::PStringBase<char>(&Ambient, "Ambient");
  return atexit(_E517_6);
}

//----- (006C9080) --------------------------------------------------------  // acclient.c:736796
int _E519()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_0, "Diffuse");
  return atexit(_E520_6);
}

//----- (006C90A0) --------------------------------------------------------  // acclient.c:736803
int _E522()
{
  PStringBase<char>::PStringBase<char>(&Specular_0, "Specular");
  return atexit(_E523_6);
}

//----- (006C90C0) --------------------------------------------------------  // acclient.c:736810
int _E525()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower, "SpecularPower");
  return atexit(_E526_6);
}

//----- (006C90E0) --------------------------------------------------------  // acclient.c:736817
int _E528()
{
  PStringBase<char>::PStringBase<char>(&Dye, "Dye");
  return atexit(_E529_6);
}

//----- (006C9100) --------------------------------------------------------  // acclient.c:736824
int _E531()
{
  PStringBase<char>::PStringBase<char>(&Emissive, "Emissive");
  return atexit(_E532_6);
}

//----- (006C9120) --------------------------------------------------------  // acclient.c:736831
int _E534()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat, "VertexFormat");
  return atexit(_E535_6);
}

//----- (006C9140) --------------------------------------------------------  // acclient.c:736838
int _E537()
{
  PStringBase<char>::PStringBase<char>(&VertexShader, "VertexShader");
  return atexit(_E538_6);
}

//----- (006C9160) --------------------------------------------------------  // acclient.c:736845
int _E540()
{
  PStringBase<char>::PStringBase<char>(&PixelShader, "PixelShader");
  return atexit(_E541_6);
}

//----- (006C9180) --------------------------------------------------------  // acclient.c:736852
int _E543()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE, "None");
  return atexit(_E544_6);
}

//----- (006C91A0) --------------------------------------------------------  // acclient.c:736859
int _E546()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS, "Reflections");
  return atexit(_E547_6);
}

//----- (006C91C0) --------------------------------------------------------  // acclient.c:736866
int _E549()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST, "VideoPost");
  return atexit(_E550_6);
}

//----- (006C91E0) --------------------------------------------------------  // acclient.c:736873
int _E552()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL, "HighDetail");
  return atexit(_E553_6);
}

//----- (006C9200) --------------------------------------------------------  // acclient.c:736880
int _E555()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR, "Specular");
  return atexit(_E556_6);
}

//----- (006C9220) --------------------------------------------------------  // acclient.c:736887
int _E558()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1, "Class1");
  return atexit(_E559_6);
}

//----- (006C9240) --------------------------------------------------------  // acclient.c:736894
int _E561()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2, "Class2");
  return atexit(_E562_6);
}

//----- (006C9260) --------------------------------------------------------  // acclient.c:736901
int _E564()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3, "Class3");
  return atexit(_E565_6);
}

//----- (006C9280) --------------------------------------------------------  // acclient.c:736908
int _E567()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default, "Default");
  return atexit(_E568_6);
}

//----- (006C92A0) --------------------------------------------------------  // acclient.c:736915
int _E570()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E571_6);
}

//----- (006C92C0) --------------------------------------------------------  // acclient.c:736924
int _E573()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular, "PointLightDiffuseAndSpecular");
  return atexit(_E574_6);
}

//----- (006C92E0) --------------------------------------------------------  // acclient.c:736931
int _E576()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E577_6);
}

//----- (006C9300) --------------------------------------------------------  // acclient.c:736940
int _E579()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E580_6);
}

//----- (006C9320) --------------------------------------------------------  // acclient.c:736949
int _E582()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E583_6);
}

//----- (006C9340) --------------------------------------------------------  // acclient.c:736958
int _E585()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog, "DistanceFog");
  return atexit(_E586_6);
}

//----- (006C9360) --------------------------------------------------------  // acclient.c:736965
int _E588()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow, "FFGlow");
  return atexit(_E589_6);
}

//----- (006C9380) --------------------------------------------------------  // acclient.c:736972
int _E591()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow, "ShaderGlow");
  return atexit(_E592_6);
}

//----- (006C93A0) --------------------------------------------------------  // acclient.c:736979
int _E594()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap, "LandscapeShadowMap");
  return atexit(_E595_6);
}

//----- (006C93C0) --------------------------------------------------------  // acclient.c:736986
int _E597()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend, "AlphaBlend");
  return atexit(_E598_6);
}

//----- (006C93E0) --------------------------------------------------------  // acclient.c:736993
int _E600()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL, "AL_0DL_0PL");
  return atexit(_E601_6);
}

//----- (006C9400) --------------------------------------------------------  // acclient.c:737000
int _E603()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL, "AL_0DL_1PL");
  return atexit(_E604_6);
}

//----- (006C9420) --------------------------------------------------------  // acclient.c:737007
int _E606()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL, "AL_0DL_2PL");
  return atexit(_E607_6);
}

//----- (006C9440) --------------------------------------------------------  // acclient.c:737014
int _E609()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL, "AL_0DL_3PL");
  return atexit(_E610_6);
}

//----- (006C9460) --------------------------------------------------------  // acclient.c:737021
int _E612()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL, "AL_0DL_4PL");
  return atexit(_E613_6);
}

//----- (006C9480) --------------------------------------------------------  // acclient.c:737028
int _E615()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL, "AL_0DL_5PL");
  return atexit(_E616_6);
}

//----- (006C94A0) --------------------------------------------------------  // acclient.c:737035
int _E618()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL, "AL_0DL_6PL");
  return atexit(_E619_6);
}

//----- (006C94C0) --------------------------------------------------------  // acclient.c:737042
int _E621()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL, "AL_0DL_7PL");
  return atexit(_E622_6);
}

//----- (006C94E0) --------------------------------------------------------  // acclient.c:737049
int _E624()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL, "AL_0DL_8PL");
  return atexit(_E625_6);
}

//----- (006C9500) --------------------------------------------------------  // acclient.c:737056
int _E627()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL, "AL_1DL_0PL");
  return atexit(_E628_6);
}

//----- (006C9520) --------------------------------------------------------  // acclient.c:737063
int _E630()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL, "AL_1DL_1PL");
  return atexit(_E631_6);
}

//----- (006C9540) --------------------------------------------------------  // acclient.c:737070
int _E633()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL, "AL_1DL_2PL");
  return atexit(_E634_6);
}

//----- (006C9560) --------------------------------------------------------  // acclient.c:737077
int _E636()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL, "AL_1DL_3PL");
  return atexit(_E637_6);
}

//----- (006C9580) --------------------------------------------------------  // acclient.c:737084
int _E639()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL, "AL_1DL_4PL");
  return atexit(_E640_6);
}

//----- (006C95A0) --------------------------------------------------------  // acclient.c:737091
int _E642()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL, "AL_1DL_5PL");
  return atexit(_E643_6);
}

//----- (006C95C0) --------------------------------------------------------  // acclient.c:737098
int _E645()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL, "AL_1DL_6PL");
  return atexit(_E646_6);
}

//----- (006C95E0) --------------------------------------------------------  // acclient.c:737105
int _E648()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL, "AL_1DL_7PL");
  return atexit(_E649_6);
}

//----- (006C9600) --------------------------------------------------------  // acclient.c:737112
int _E651()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog, "AL_0DL_0PL_Fog");
  return atexit(_E652_6);
}

//----- (006C9620) --------------------------------------------------------  // acclient.c:737119
int _E654()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog, "AL_0DL_1PL_Fog");
  return atexit(_E655_6);
}

//----- (006C9640) --------------------------------------------------------  // acclient.c:737126
int _E657()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog, "AL_0DL_2PL_Fog");
  return atexit(_E658_6);
}

//----- (006C9660) --------------------------------------------------------  // acclient.c:737133
int _E660()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog, "AL_0DL_3PL_Fog");
  return atexit(_E661_6);
}

//----- (006C9680) --------------------------------------------------------  // acclient.c:737140
int _E663()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog, "AL_0DL_4PL_Fog");
  return atexit(_E664_6);
}

//----- (006C96A0) --------------------------------------------------------  // acclient.c:737147
int _E666()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog, "AL_0DL_5PL_Fog");
  return atexit(_E667_6);
}

//----- (006C96C0) --------------------------------------------------------  // acclient.c:737154
int _E669()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog, "AL_0DL_6PL_Fog");
  return atexit(_E670_6);
}

//----- (006C96E0) --------------------------------------------------------  // acclient.c:737161
int _E672()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog, "AL_0DL_7PL_Fog");
  return atexit(_E673_6);
}

//----- (006C9700) --------------------------------------------------------  // acclient.c:737168
int _E675()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog, "AL_0DL_8PL_Fog");
  return atexit(_E676_6);
}

//----- (006C9720) --------------------------------------------------------  // acclient.c:737175
int _E678()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog, "AL_1DL_0PL_Fog");
  return atexit(_E679_6);
}

//----- (006C9740) --------------------------------------------------------  // acclient.c:737182
int _E681()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog, "AL_1DL_1PL_Fog");
  return atexit(_E682_6);
}

//----- (006C9760) --------------------------------------------------------  // acclient.c:737189
int _E684()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog, "AL_1DL_2PL_Fog");
  return atexit(_E685_6);
}

//----- (006C9780) --------------------------------------------------------  // acclient.c:737196
int _E687()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog, "AL_1DL_3PL_Fog");
  return atexit(_E688_6);
}

//----- (006C97A0) --------------------------------------------------------  // acclient.c:737203
int _E690()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog, "AL_1DL_4PL_Fog");
  return atexit(_E691_6);
}

//----- (006C97C0) --------------------------------------------------------  // acclient.c:737210
int _E693()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog, "AL_1DL_5PL_Fog");
  return atexit(_E694_6);
}

//----- (006C97E0) --------------------------------------------------------  // acclient.c:737217
int _E696()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog, "AL_1DL_6PL_Fog");
  return atexit(_E697_6);
}

//----- (006C9800) --------------------------------------------------------  // acclient.c:737224
int _E699()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog, "AL_1DL_7PL_Fog");
  return atexit(_E700_6);
}

//----- (006C9820) --------------------------------------------------------  // acclient.c:737231
int _E702()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO, "Zero");
  return atexit(_E703_6);
}

//----- (006C9840) --------------------------------------------------------  // acclient.c:737238
int _E705()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE, "One");
  return atexit(_E706_6);
}

//----- (006C9860) --------------------------------------------------------  // acclient.c:737245
int _E708()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR, "SrcColor");
  return atexit(_E709_6);
}

//----- (006C9880) --------------------------------------------------------  // acclient.c:737252
int _E711()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR, "InvSrcColor");
  return atexit(_E712_6);
}

//----- (006C98A0) --------------------------------------------------------  // acclient.c:737259
int _E714()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA, "SrcAlpha");
  return atexit(_E715_6);
}

//----- (006C98C0) --------------------------------------------------------  // acclient.c:737266
int _E717()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA, "InvSrcAlpha");
  return atexit(_E718_6);
}

//----- (006C98E0) --------------------------------------------------------  // acclient.c:737273
int _E720()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA, "DstAlpha");
  return atexit(_E721_6);
}

//----- (006C9900) --------------------------------------------------------  // acclient.c:737280
int _E723()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA, "InvDstAlpha");
  return atexit(_E724_6);
}

//----- (006C9920) --------------------------------------------------------  // acclient.c:737287
int _E726()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR, "DstColor");
  return atexit(_E727_6);
}

//----- (006C9940) --------------------------------------------------------  // acclient.c:737294
int _E729()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR, "InvDstColor");
  return atexit(_E730_6);
}

//----- (006C9960) --------------------------------------------------------  // acclient.c:737301
int _E732()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT, "SrcAlphaSat");
  return atexit(_E733_6);
}

//----- (006C9980) --------------------------------------------------------  // acclient.c:737308
int _E735()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS, "Less");
  return atexit(_E736_6);
}

//----- (006C99A0) --------------------------------------------------------  // acclient.c:737315
int _E738()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL, "Equal");
  return atexit(_E739_6);
}

//----- (006C99C0) --------------------------------------------------------  // acclient.c:737322
int _E741()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL, "LessEqual");
  return atexit(_E742_6);
}

//----- (006C99E0) --------------------------------------------------------  // acclient.c:737329
int _E744()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER, "Greater");
  return atexit(_E745_6);
}

//----- (006C9A00) --------------------------------------------------------  // acclient.c:737336
int _E747()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL, "NotEqual");
  return atexit(_E748_6);
}

//----- (006C9A20) --------------------------------------------------------  // acclient.c:737343
int _E750()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL, "GreaterEqual");
  return atexit(_E751_6);
}

//----- (006C9A40) --------------------------------------------------------  // acclient.c:737350
int _E753()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS, "Always");
  return atexit(_E754_6);
}

//----- (006C9A60) --------------------------------------------------------  // acclient.c:737357
int _E756()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON, "On");
  return atexit(_E757_6);
}

//----- (006C9A80) --------------------------------------------------------  // acclient.c:737364
int _E759()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF, "Off");
  return atexit(_E760_6);
}

//----- (006C9AA0) --------------------------------------------------------  // acclient.c:737371
int _E762()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE, "LayerDiffuse");
  return atexit(_E763_6);
}

//----- (006C9AC0) --------------------------------------------------------  // acclient.c:737378
int _E765()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR, "LayerSpecular");
  return atexit(_E766_6);
}

//----- (006C9AE0) --------------------------------------------------------  // acclient.c:737385
int _E768()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE, "VertexDiffuse");
  return atexit(_E769_6);
}

//----- (006C9B00) --------------------------------------------------------  // acclient.c:737392
int _E771()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR, "VertexSpecular");
  return atexit(_E772_6);
}

//----- (006C9B20) --------------------------------------------------------  // acclient.c:737399
int _E774()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE, "None");
  return atexit(_E775_6);
}

//----- (006C9B40) --------------------------------------------------------  // acclient.c:737406
int _E777()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW, "CW");
  return atexit(_E778_6);
}

//----- (006C9B60) --------------------------------------------------------  // acclient.c:737413
int _E780()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW, "CCW");
  return atexit(_E781_6);
}

//----- (006C9B80) --------------------------------------------------------  // acclient.c:737420
int _E783()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE, "None");
  return atexit(_E784_6);
}

//----- (006C9BA0) --------------------------------------------------------  // acclient.c:737427
int _E786()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE, "Simple");
  return atexit(_E787_6);
}

//----- (006C9BC0) --------------------------------------------------------  // acclient.c:737434
int _E789()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE, "Diffuse");
  return atexit(_E790_6);
}

//----- (006C9BE0) --------------------------------------------------------  // acclient.c:737441
int _E792()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR, "Specular");
  return atexit(_E793_6);
}

//----- (006C9C00) --------------------------------------------------------  // acclient.c:737448
int _E795()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF, "Off");
  return atexit(_E796_6);
}

//----- (006C9C20) --------------------------------------------------------  // acclient.c:737455
int _E798()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON, "On");
  return atexit(_E799_6);
}

//----- (006C9C40) --------------------------------------------------------  // acclient.c:737462
int _E801()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF, "Off");
  return atexit(_E802_6);
}

//----- (006C9C60) --------------------------------------------------------  // acclient.c:737469
int _E804()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON, "On");
  return atexit(_E805_6);
}

//----- (006C9C80) --------------------------------------------------------  // acclient.c:737476
int _E807()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN, "Origin");
  return atexit(_E808_6);
}

//----- (006C9CA0) --------------------------------------------------------  // acclient.c:737483
int _E810()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL, "Normal");
  return atexit(_E811_6);
}

//----- (006C9CC0) --------------------------------------------------------  // acclient.c:737490
int _E813()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE, "PointSize");
  return atexit(_E814_6);
}

//----- (006C9CE0) --------------------------------------------------------  // acclient.c:737497
int _E816()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE, "Diffuse");
  return atexit(_E817_6);
}

//----- (006C9D00) --------------------------------------------------------  // acclient.c:737504
int _E819()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR, "Specular");
  return atexit(_E820_6);
}

//----- (006C9D20) --------------------------------------------------------  // acclient.c:737511
int _E822()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1, "TCPairX1");
  return atexit(_E823_6);
}

//----- (006C9D40) --------------------------------------------------------  // acclient.c:737518
int _E825()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2, "TCPairX2");
  return atexit(_E826_6);
}

//----- (006C9D60) --------------------------------------------------------  // acclient.c:737525
int _E828()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3, "TCPairX3");
  return atexit(_E829_6);
}

//----- (006C9D80) --------------------------------------------------------  // acclient.c:737532
int _E831()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4, "TCPairX4");
  return atexit(_E832_6);
}

//----- (006C9DA0) --------------------------------------------------------  // acclient.c:737539
int _E834()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5, "TCPairX5");
  return atexit(_E835_6);
}

//----- (006C9DC0) --------------------------------------------------------  // acclient.c:737546
int _E837()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6, "TCPairX6");
  return atexit(_E838_6);
}

//----- (006C9DE0) --------------------------------------------------------  // acclient.c:737553
int _E840()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7, "TCPairX7");
  return atexit(_E841_6);
}

//----- (006C9E00) --------------------------------------------------------  // acclient.c:737560
int _E843()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8, "TCPairX8");
  return atexit(_E844_6);
}

//----- (006C9E20) --------------------------------------------------------  // acclient.c:737567
int _E846()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S, "VectorS");
  return atexit(_E847_6);
}

//----- (006C9E40) --------------------------------------------------------  // acclient.c:737574
int _E849()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T, "VectorT");
  return atexit(_E850_6);
}

//----- (006C9E60) --------------------------------------------------------  // acclient.c:737581
int _E852()
{
  PStringBase<char>::PStringBase<char>(&NodeName_4, "Stage");
  return atexit(_E853_6);
}

//----- (006C9E80) --------------------------------------------------------  // acclient.c:737588
int _E855()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName, "Sampler");
  return atexit(_E856_6);
}

//----- (006C9EA0) --------------------------------------------------------  // acclient.c:737595
int _E858()
{
  PStringBase<char>::PStringBase<char>(&SamplerName, "SamplerName");
  return atexit(_E859_6);
}

//----- (006C9EC0) --------------------------------------------------------  // acclient.c:737602
int _E861()
{
  PStringBase<char>::PStringBase<char>(&Texture, "Texture");
  return atexit(_E862_6);
}

//----- (006C9EE0) --------------------------------------------------------  // acclient.c:737609
int _E864()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer, "!FrameBuffer");
  return atexit(_E865_6);
}

//----- (006C9F00) --------------------------------------------------------  // acclient.c:737616
int _E867()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion, "!Distortion");
  return atexit(_E868_6);
}

//----- (006C9F20) --------------------------------------------------------  // acclient.c:737623
int _E870()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection, "!Reflection");
  return atexit(_E871_6);
}

//----- (006C9F40) --------------------------------------------------------  // acclient.c:737630
int _E873()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube, "!NormalizeCube");
  return atexit(_E874_6);
}

//----- (006C9F60) --------------------------------------------------------  // acclient.c:737637
int _E876()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube, "!LightProjectorCube");
  return atexit(_E877_6);
}

//----- (006C9F80) --------------------------------------------------------  // acclient.c:737644
int _E879()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube, "!EnvironmentCube");
  return atexit(_E880_6);
}

//----- (006C9FA0) --------------------------------------------------------  // acclient.c:737651
int _E882()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows, "!LandscapeShadows");
  return atexit(_E883_6);
}

//----- (006C9FC0) --------------------------------------------------------  // acclient.c:737658
int _E885()
{
  PStringBase<char>::PStringBase<char>(&AddressMode, "AddressMode");
  return atexit(_E886_6);
}

//----- (006C9FE0) --------------------------------------------------------  // acclient.c:737665
int _E888()
{
  PStringBase<char>::PStringBase<char>(&TexFilter, "FilterMode");
  return atexit(_E889_6);
}

//----- (006CA000) --------------------------------------------------------  // acclient.c:737672
int _E891()
{
  PStringBase<char>::PStringBase<char>(&ColorOp, "FFColorOp");
  return atexit(_E892_6);
}

//----- (006CA020) --------------------------------------------------------  // acclient.c:737679
int _E894()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1, "FFColorArg1");
  return atexit(_E895_6);
}

//----- (006CA040) --------------------------------------------------------  // acclient.c:737686
int _E897()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2, "FFColorArg2");
  return atexit(_E898_6);
}

//----- (006CA060) --------------------------------------------------------  // acclient.c:737693
int _E900()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp, "FFAlphaOp");
  return atexit(_E901_6);
}

//----- (006CA080) --------------------------------------------------------  // acclient.c:737700
int _E903()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1, "FFAlphaArg1");
  return atexit(_E904_6);
}

//----- (006CA0A0) --------------------------------------------------------  // acclient.c:737707
int _E906()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2, "FFAlphaArg2");
  return atexit(_E907_6);
}

//----- (006CA0C0) --------------------------------------------------------  // acclient.c:737714
int _E909()
{
  PStringBase<char>::PStringBase<char>(&TexCoord, "FFTexCoordIndex");
  return atexit(_E910_6);
}

//----- (006CA0E0) --------------------------------------------------------  // acclient.c:737721
int _E912()
{
  PStringBase<char>::PStringBase<char>(&UseProjection, "FFUseProjection");
  return atexit(_E913_6);
}

//----- (006CA100) --------------------------------------------------------  // acclient.c:737728
int _E915()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1, "SelectArg1");
  return atexit(_E916_6);
}

//----- (006CA120) --------------------------------------------------------  // acclient.c:737735
int _E918()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2, "SelectArg2");
  return atexit(_E919_6);
}

//----- (006CA140) --------------------------------------------------------  // acclient.c:737742
int _E921()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE, "Modulate");
  return atexit(_E922_6);
}

//----- (006CA160) --------------------------------------------------------  // acclient.c:737749
int _E924()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X, "Modulate2X");
  return atexit(_E925_6);
}

//----- (006CA180) --------------------------------------------------------  // acclient.c:737756
int _E927()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X, "Modulate4X");
  return atexit(_E928_6);
}

//----- (006CA1A0) --------------------------------------------------------  // acclient.c:737763
int _E930()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD, "Add");
  return atexit(_E931_6);
}

//----- (006CA1C0) --------------------------------------------------------  // acclient.c:737770
int _E933()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED, "AddSigned");
  return atexit(_E934_6);
}

//----- (006CA1E0) --------------------------------------------------------  // acclient.c:737777
int _E936()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X, "AddSigned2X");
  return atexit(_E937_6);
}

//----- (006CA200) --------------------------------------------------------  // acclient.c:737784
int _E939()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT, "Subtract");
  return atexit(_E940_6);
}

//----- (006CA220) --------------------------------------------------------  // acclient.c:737791
int _E942()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH, "AddSmooth");
  return atexit(_E943_6);
}

//----- (006CA240) --------------------------------------------------------  // acclient.c:737798
int _E945()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA, "BlendDiffuseAlpha");
  return atexit(_E946_6);
}

//----- (006CA260) --------------------------------------------------------  // acclient.c:737805
int _E948()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA, "BlendTextureAlpha");
  return atexit(_E949_6);
}

//----- (006CA280) --------------------------------------------------------  // acclient.c:737812
int _E951()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA, "BlendFactorAlpha");
  return atexit(_E952_6);
}

//----- (006CA2A0) --------------------------------------------------------  // acclient.c:737819
int _E954()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM, "BlendTextureAlphaPM");
  return atexit(_E955_6);
}

//----- (006CA2C0) --------------------------------------------------------  // acclient.c:737826
int _E957()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA, "BlendCurrentAlpha");
  return atexit(_E958_6);
}

//----- (006CA2E0) --------------------------------------------------------  // acclient.c:737833
int _E960()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE, "Premodulate");
  return atexit(_E961_6);
}

//----- (006CA300) --------------------------------------------------------  // acclient.c:737840
int _E963()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR, "ModulateAlphaAddColor");
  return atexit(_E964_6);
}

//----- (006CA320) --------------------------------------------------------  // acclient.c:737847
int _E966()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA, "ModulateColorAddAlpha");
  return atexit(_E967_6);
}

//----- (006CA340) --------------------------------------------------------  // acclient.c:737854
int _E969()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR, "ModulateInvAlphaAddColor");
  return atexit(_E970_6);
}

//----- (006CA360) --------------------------------------------------------  // acclient.c:737861
int _E972()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA, "ModulateInvColorAddAlpha");
  return atexit(_E973_6);
}

//----- (006CA380) --------------------------------------------------------  // acclient.c:737868
int _E975()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP, "BumpEnvMap");
  return atexit(_E976_6);
}

//----- (006CA3A0) --------------------------------------------------------  // acclient.c:737875
int _E978()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE, "BumpEnvMapLuminance");
  return atexit(_E979_6);
}

//----- (006CA3C0) --------------------------------------------------------  // acclient.c:737882
int _E981()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3, "DotProduct3");
  return atexit(_E982_6);
}

//----- (006CA3E0) --------------------------------------------------------  // acclient.c:737889
int _E984()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD, "MultiplyAdd");
  return atexit(_E985_6);
}

//----- (006CA400) --------------------------------------------------------  // acclient.c:737896
int _E987()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP, "Lerp");
  return atexit(_E988_6);
}

//----- (006CA420) --------------------------------------------------------  // acclient.c:737903
int _E990()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE, "Diffuse");
  return atexit(_E991_6);
}

//----- (006CA440) --------------------------------------------------------  // acclient.c:737910
int _E993()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR, "Specular");
  return atexit(_E994_6);
}

//----- (006CA460) --------------------------------------------------------  // acclient.c:737917
int _E996()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT, "Current");
  return atexit(_E997_6);
}

//----- (006CA480) --------------------------------------------------------  // acclient.c:737924
int _E999()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE, "Texture");
  return atexit(_E1000_6);
}

//----- (006CA4A0) --------------------------------------------------------  // acclient.c:737931
int _E1002()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR, "TFactor");
  return atexit(_E1003_6);
}

//----- (006CA4C0) --------------------------------------------------------  // acclient.c:737938
int _E1005()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP, "Wrap");
  return atexit(_E1006_6);
}

//----- (006CA4E0) --------------------------------------------------------  // acclient.c:737945
int _E1008()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR, "Mirror");
  return atexit(_E1009_6);
}

//----- (006CA500) --------------------------------------------------------  // acclient.c:737952
int _E1011()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP, "Clamp");
  return atexit(_E1012_6);
}

//----- (006CA520) --------------------------------------------------------  // acclient.c:737959
int _E1014()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER, "Border");
  return atexit(_E1015_6);
}

//----- (006CA540) --------------------------------------------------------  // acclient.c:737966
int _E1017()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE, "None");
  return atexit(_E1018_6);
}

//----- (006CA560) --------------------------------------------------------  // acclient.c:737973
int _E1020()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT, "Point");
  return atexit(_E1021_6);
}

//----- (006CA580) --------------------------------------------------------  // acclient.c:737980
int _E1023()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR, "Linear");
  return atexit(_E1024_6);
}

//----- (006CA5A0) --------------------------------------------------------  // acclient.c:737987
int _E1026()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC, "Anisotropic");
  return atexit(_E1027_6);
}

//----- (006CA5C0) --------------------------------------------------------  // acclient.c:737994
int _E1029()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector, "ReflectionVector");
  return atexit(_E1030_6);
}

//----- (006CA5E0) --------------------------------------------------------  // acclient.c:738001
int _E1032()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal, "ViewNormal");
  return atexit(_E1033_6);
}

//----- (006CA600) --------------------------------------------------------  // acclient.c:738008
int _E1035()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin, "ViewOrigin");
  return atexit(_E1036_6);
}

//----- (006CA620) --------------------------------------------------------  // acclient.c:738015
int _E1038()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap, "SphereMap");
  return atexit(_E1039_6);
}

//----- (006CA640) --------------------------------------------------------  // acclient.c:738022
int _E1041()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection, "CubeMapReflection");
  return atexit(_E1042_6);
}

//----- (006CA660) --------------------------------------------------------  // acclient.c:738029
int _E1044()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight, "CubeMapFakeLight");
  return atexit(_E1045_6);
}

//----- (006CA680) --------------------------------------------------------  // acclient.c:738036
int _E1047()
{
  PStringBase<char>::PStringBase<char>(&NodeName_5, "FFModifier");
  return atexit(_E1048_6);
}

//----- (006CA6A0) --------------------------------------------------------  // acclient.c:738043
int _E1050()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin, "Origin");
  return atexit(_E1051_6);
}

//----- (006CA6C0) --------------------------------------------------------  // acclient.c:738050
int _E1053()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal, "Normal");
  return atexit(_E1054_6);
}

//----- (006CA6E0) --------------------------------------------------------  // acclient.c:738057
int _E1056()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse, "Diffuse");
  return atexit(_E1057_6);
}

//----- (006CA700) --------------------------------------------------------  // acclient.c:738064
int _E1059()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate, "UVTranslate");
  return atexit(_E1060_6);
}

//----- (006CA720) --------------------------------------------------------  // acclient.c:738071
int _E1062()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate, "UVRotate");
  return atexit(_E1063_6);
}

//----- (006CA740) --------------------------------------------------------  // acclient.c:738078
int _E1065()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale, "UVScale");
  return atexit(_E1066_6);
}

//----- (006CA760) --------------------------------------------------------  // acclient.c:738085
int _E1068()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform, "UVTransform");
  return atexit(_E1069_6);
}

//----- (006CA780) --------------------------------------------------------  // acclient.c:738092
int _E1071()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex, "TexCoordIndex");
  return atexit(_E1072_6);
}

//----- (006CA7A0) --------------------------------------------------------  // acclient.c:738099
int _E1074()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate, "Translate");
  return atexit(_E1075_6);
}

//----- (006CA7C0) --------------------------------------------------------  // acclient.c:738106
int _E1077()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex, "TexCoordIndex");
  return atexit(_E1078_6);
}

//----- (006CA7E0) --------------------------------------------------------  // acclient.c:738113
int _E1080()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate, "Rotate");
  return atexit(_E1081_6);
}

//----- (006CA800) --------------------------------------------------------  // acclient.c:738120
int _E1083()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex, "TexCoordIndex");
  return atexit(_E1084_6);
}

//----- (006CA820) --------------------------------------------------------  // acclient.c:738127
int _E1086()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale, "Scale");
  return atexit(_E1087_6);
}

//----- (006CA840) --------------------------------------------------------  // acclient.c:738134
int _E1089()
{
  PStringBase<char>::PStringBase<char>(&NodeName_6, "PSDesc");
  return atexit(_E1090_6);
}

//----- (006CA860) --------------------------------------------------------  // acclient.c:738141
int _E1092()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep, "PhysicsTimeStep");
  return atexit(_E1093_6);
}

//----- (006CA880) --------------------------------------------------------  // acclient.c:738148
int _E1095()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime, "FastForwardTime");
  return atexit(_E1096_6);
}

//----- (006CA8A0) --------------------------------------------------------  // acclient.c:738155
int _E1098()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance, "StartFadeDistance");
  return atexit(_E1099_6);
}

//----- (006CA8C0) --------------------------------------------------------  // acclient.c:738162
int _E1101()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance, "StopFadeDistance");
  return atexit(_E1102_6);
}

//----- (006CA8E0) --------------------------------------------------------  // acclient.c:738169
int _E1104()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration, "PhysicsDuration");
  return atexit(_E1105_6);
}

//----- (006CA900) --------------------------------------------------------  // acclient.c:738176
int _E1107()
{
  PStringBase<char>::PStringBase<char>(&ScaleType, "ScaleType");
  return atexit(_E1108_6);
}

//----- (006CA920) --------------------------------------------------------  // acclient.c:738183
int _E1110()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace, "WorldSpace");
  return atexit(_E1111_6);
}

//----- (006CA940) --------------------------------------------------------  // acclient.c:738190
int _E1113()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw, "ForceDraw");
  return atexit(_E1114_6);
}

//----- (006CA960) --------------------------------------------------------  // acclient.c:738197
int _E1116()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters, "NumEmitters");
  return atexit(_E1117_6);
}

//----- (006CA980) --------------------------------------------------------  // acclient.c:738204
int _E1119()
{
  PStringBase<char>::PStringBase<char>(&Material_2, "Material");
  return atexit(_E1120_6);
}

//----- (006CA9A0) --------------------------------------------------------  // acclient.c:738211
int _E1122()
{
  PStringBase<char>::PStringBase<char>(&Version, "Version");
  return atexit(_E1123_6);
}

//----- (006CA9C0) --------------------------------------------------------  // acclient.c:738218
int _E1125()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles, "MaxParticles");
  return atexit(_E1126_6);
}

//----- (006CA9E0) --------------------------------------------------------  // acclient.c:738225
int _E1128()
{
  PStringBase<char>::PStringBase<char>(&NodeName_7, "Emitter");
  return atexit(_E1129_6);
}

//----- (006CAA00) --------------------------------------------------------  // acclient.c:738232
int _E1131()
{
  PStringBase<char>::PStringBase<char>(&Origin_0, "Origin");
  return atexit(_E1132_6);
}

//----- (006CAA20) --------------------------------------------------------  // acclient.c:738239
int _E1134()
{
  PStringBase<char>::PStringBase<char>(&Shape, "Shape");
  return atexit(_E1135_6);
}

//----- (006CAA40) --------------------------------------------------------  // acclient.c:738246
int _E1137()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point, "Point");
  return atexit(_E1138_6);
}

//----- (006CAA60) --------------------------------------------------------  // acclient.c:738253
int _E1140()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line, "Line");
  return atexit(_E1141_6);
}

//----- (006CAA80) --------------------------------------------------------  // acclient.c:738260
int _E1143()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad, "Quad");
  return atexit(_E1144_6);
}

//----- (006CAAA0) --------------------------------------------------------  // acclient.c:738267
int _E1146()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc, "Disc");
  return atexit(_E1147_6);
}

//----- (006CAAC0) --------------------------------------------------------  // acclient.c:738274
int _E1149()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere, "Sphere");
  return atexit(_E1150_6);
}

//----- (006CAAE0) --------------------------------------------------------  // acclient.c:738281
int _E1152()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape, "ParticleShape");
  return atexit(_E1153_6);
}

//----- (006CAB00) --------------------------------------------------------  // acclient.c:738288
int _E1155()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle, "Triangle");
  return atexit(_E1156_6);
}

//----- (006CAB20) --------------------------------------------------------  // acclient.c:738295
int _E1158()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad, "Quad");
  return atexit(_E1159_6);
}

//----- (006CAB40) --------------------------------------------------------  // acclient.c:738302
int _E1161()
{
  PStringBase<char>::PStringBase<char>(&Streak, "Streak");
  return atexit(_E1162_6);
}

//----- (006CAB60) --------------------------------------------------------  // acclient.c:738309
int _E1164()
{
  PStringBase<char>::PStringBase<char>(&Rotation_0, "Rotation");
  return atexit(_E1165_6);
}

//----- (006CAB80) --------------------------------------------------------  // acclient.c:738316
int _E1167()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation, "WorldRotation");
  return atexit(_E1168_6);
}

//----- (006CABA0) --------------------------------------------------------  // acclient.c:738323
int _E1170()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity, "RotateVelocity");
  return atexit(_E1171_6);
}

//----- (006CABC0) --------------------------------------------------------  // acclient.c:738330
int _E1173()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale, "ParticleScale");
  return atexit(_E1174_6);
}

//----- (006CABE0) --------------------------------------------------------  // acclient.c:738337
int _E1176()
{
  PStringBase<char>::PStringBase<char>(&Scale_0, "Scale");
  return atexit(_E1177_6);
}

//----- (006CAC00) --------------------------------------------------------  // acclient.c:738344
int _E1179()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir, "ExplodingDir");
  return atexit(_E1180_6);
}

//----- (006CAC20) --------------------------------------------------------  // acclient.c:738351
int _E1182()
{
  PStringBase<char>::PStringBase<char>(&BirthRate, "BirthRate");
  return atexit(_E1183_6);
}

//----- (006CAC40) --------------------------------------------------------  // acclient.c:738358
int _E1185()
{
  PStringBase<char>::PStringBase<char>(&Lifespan, "Lifespan");
  return atexit(_E1186_6);
}

//----- (006CAC60) --------------------------------------------------------  // acclient.c:738365
int _E1188()
{
  PStringBase<char>::PStringBase<char>(&Velocity, "Velocity");
  return atexit(_E1189_6);
}

//----- (006CAC80) --------------------------------------------------------  // acclient.c:738372
int _E1191()
{
  PStringBase<char>::PStringBase<char>(&Direction, "Direction");
  return atexit(_E1192_6);
}

//----- (006CACA0) --------------------------------------------------------  // acclient.c:738379
int _E1194()
{
  PStringBase<char>::PStringBase<char>(&MinSpread, "MinSpread");
  return atexit(_E1195_6);
}

//----- (006CACC0) --------------------------------------------------------  // acclient.c:738386
int _E1197()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread, "MaxSpread");
  return atexit(_E1198_6);
}

//----- (006CACE0) --------------------------------------------------------  // acclient.c:738393
int _E1200()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit, "EmissionLimit");
  return atexit(_E1201_6);
}

//----- (006CAD00) --------------------------------------------------------  // acclient.c:738400
int _E1203()
{
  PStringBase<char>::PStringBase<char>(&BlastCount, "BlastCount");
  return atexit(_E1204_6);
}

//----- (006CAD20) --------------------------------------------------------  // acclient.c:738407
int _E1206()
{
  PStringBase<char>::PStringBase<char>(&StartTime, "StartTime");
  return atexit(_E1207_6);
}

//----- (006CAD40) --------------------------------------------------------  // acclient.c:738414
int _E1209()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit, "TimeLimit");
  return atexit(_E1210_6);
}

//----- (006CAD60) --------------------------------------------------------  // acclient.c:738421
int _E1212()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance, "EmissionDistance");
  return atexit(_E1213_6);
}

//----- (006CAD80) --------------------------------------------------------  // acclient.c:738428
int _E1215()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap, "ParticleSnap");
  return atexit(_E1216_6);
}

//----- (006CADA0) --------------------------------------------------------  // acclient.c:738435
int _E1218()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape, "InclusiveShape");
  return atexit(_E1219_6);
}

//----- (006CADC0) --------------------------------------------------------  // acclient.c:738442
int _E1221()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes, "NumKeyframes");
  return atexit(_E1222_6);
}

//----- (006CADE0) --------------------------------------------------------  // acclient.c:738449
int _E1224()
{
  PStringBase<char>::PStringBase<char>(&IsActive, "IsActive");
  return atexit(_E1225_6);
}

//----- (006CAE00) --------------------------------------------------------  // acclient.c:738456
int _E1227()
{
  PStringBase<char>::PStringBase<char>(&FadeIn, "FadeIn");
  return atexit(_E1228_6);
}

//----- (006CAE20) --------------------------------------------------------  // acclient.c:738463
int _E1230()
{
  PStringBase<char>::PStringBase<char>(&FadeOut, "FadeOut");
  return atexit(_E1231_6);
}

//----- (006CAE40) --------------------------------------------------------  // acclient.c:738470
int _E1233()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX, "ConstrainX");
  return atexit(_E1234_6);
}

//----- (006CAE60) --------------------------------------------------------  // acclient.c:738477
int _E1236()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY, "ConstrainY");
  return atexit(_E1237_6);
}

//----- (006CAE80) --------------------------------------------------------  // acclient.c:738484
int _E1239()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ, "ConstrainZ");
  return atexit(_E1240_6);
}

//----- (006CAEA0) --------------------------------------------------------  // acclient.c:738491
int _E1242()
{
  PStringBase<char>::PStringBase<char>(&NodeName_8, "Keyframe");
  return atexit(_E1243_6);
}

//----- (006CAEC0) --------------------------------------------------------  // acclient.c:738498
int _E1245()
{
  PStringBase<char>::PStringBase<char>(&Time, "Time");
  return atexit(_E1246_6);
}

//----- (006CAEE0) --------------------------------------------------------  // acclient.c:738505
int _E1248()
{
  PStringBase<char>::PStringBase<char>(&Flags, "Flags");
  return atexit(_E1249_6);
}

//----- (006CAF00) --------------------------------------------------------  // acclient.c:738512
int _E1251()
{
  PStringBase<char>::PStringBase<char>(&Flags_None, "None");
  return atexit(_E1252_6);
}

//----- (006CAF20) --------------------------------------------------------  // acclient.c:738519
int _E1254()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale, "BlendScale");
  return atexit(_E1255_6);
}

//----- (006CAF40) --------------------------------------------------------  // acclient.c:738526
int _E1257()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor, "BlendColor");
  return atexit(_E1258_5);
}

//----- (006CAF60) --------------------------------------------------------  // acclient.c:738533
int _E1260()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass, "BlendMass");
  return atexit(_E1261_4);
}

//----- (006CAF80) --------------------------------------------------------  // acclient.c:738540
int _E1263()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale, "SetScale");
  return atexit(_E1264_4);
}

//----- (006CAFA0) --------------------------------------------------------  // acclient.c:738547
int _E1266()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor, "SetColor");
  return atexit(_E1267_4);
}

//----- (006CAFC0) --------------------------------------------------------  // acclient.c:738554
int _E1269()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass, "SetMass");
  return atexit(_E1270_4);
}

//----- (006CAFE0) --------------------------------------------------------  // acclient.c:738561
int _E1272()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags, "SetParticleFlags");
  return atexit(_E1273_4);
}

//----- (006CB000) --------------------------------------------------------  // acclient.c:738568
int _E1275()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType, "SetControllerType");
  return atexit(_E1276_5);
}

//----- (006CB020) --------------------------------------------------------  // acclient.c:738575
int _E1278()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags, "SetPhysicsFlags");
  return atexit(_E1279_4);
}

//----- (006CB040) --------------------------------------------------------  // acclient.c:738582
int _E1281()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams, "SetParams");
  return atexit(_E1282_5);
}

//----- (006CB060) --------------------------------------------------------  // acclient.c:738589
int _E1284()
{
  PStringBase<char>::PStringBase<char>(&Scale_1, "Scale");
  return atexit(_E1285_4);
}

//----- (006CB080) --------------------------------------------------------  // acclient.c:738596
int _E1287()
{
  PStringBase<char>::PStringBase<char>(&ScaleX, "ScaleX");
  return atexit(_E1288_4);
}

//----- (006CB0A0) --------------------------------------------------------  // acclient.c:738603
int _E1290()
{
  PStringBase<char>::PStringBase<char>(&ScaleY, "ScaleY");
  return atexit(_E1291_3);
}

//----- (006CB0C0) --------------------------------------------------------  // acclient.c:738610
int _E1293()
{
  PStringBase<char>::PStringBase<char>(&Color, "Color");
  return atexit(_E1294_4);
}

//----- (006CB0E0) --------------------------------------------------------  // acclient.c:738617
int _E1296()
{
  PStringBase<char>::PStringBase<char>(&Mass, "Mass");
  return atexit(_E1297_3);
}

//----- (006CB100) --------------------------------------------------------  // acclient.c:738624
int _E1299()
{
  PStringBase<char>::PStringBase<char>(&PFlags, "ParticleFlags");
  return atexit(_E1300_3);
}

//----- (006CB120) --------------------------------------------------------  // acclient.c:738631
int _E1302()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None, "None");
  return atexit(_E1303_2);
}

//----- (006CB140) --------------------------------------------------------  // acclient.c:738638
int _E1305()
{
  PStringBase<char>::PStringBase<char>(&PCType, "ControllerType");
  return atexit(_E1306_1);
}

//----- (006CB160) --------------------------------------------------------  // acclient.c:738645
int _E1308()
{
  PStringBase<char>::PStringBase<char>(&PCType_None, "None");
  return atexit(_E1309_1);
}

//----- (006CB180) --------------------------------------------------------  // acclient.c:738652
int _E1311()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics, "Physics");
  return atexit(_E1312_1);
}

//----- (006CB1A0) --------------------------------------------------------  // acclient.c:738659
int _E1314()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric, "Parametric");
  return atexit(_E1315);
}

//----- (006CB1C0) --------------------------------------------------------  // acclient.c:738666
int _E1317()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse, "AttractRepulse");
  return atexit(_E1318);
}

//----- (006CB1E0) --------------------------------------------------------  // acclient.c:738673
int _E1320()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile, "PointFile");
  return atexit(_E1321);
}

//----- (006CB200) --------------------------------------------------------  // acclient.c:738680
int _E1323()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp, "PointFileLerp");
  return atexit(_E1324);
}

//----- (006CB220) --------------------------------------------------------  // acclient.c:738687
int _E1326()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags, "PhysicsFlags");
  return atexit(_E1327);
}

//----- (006CB240) --------------------------------------------------------  // acclient.c:738694
int _E1329()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None, "None");
  return atexit(_E1330);
}

//----- (006CB260) --------------------------------------------------------  // acclient.c:738701
int _E1332()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity, "Gravity");
  return atexit(_E1333);
}

//----- (006CB280) --------------------------------------------------------  // acclient.c:738708
int _E1335()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind, "Wind");
  return atexit(_E1336);
}

//----- (006CB2A0) --------------------------------------------------------  // acclient.c:738715
int _E1338()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum, "Momentum");
  return atexit(_E1339);
}

//----- (006CB2C0) --------------------------------------------------------  // acclient.c:738722
int _E1341()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint, "RandomPoint");
  return atexit(_E1342);
}

//----- (006CB2E0) --------------------------------------------------------  // acclient.c:738729
int _E1344()
{
  PStringBase<char>::PStringBase<char>(&Position_0, "Position");
  return atexit(_E1345);
}

//----- (006CB300) --------------------------------------------------------  // acclient.c:738736
int _E1347()
{
  PStringBase<char>::PStringBase<char>(&PointList, "PointList");
  return atexit(_E1348);
}

//----- (006CB320) --------------------------------------------------------  // acclient.c:738743
int _E1350()
{
  PStringBase<char>::PStringBase<char>(&Point_0, "pt");
  return atexit(_E1351);
}

//----- (006CB340) --------------------------------------------------------  // acclient.c:738750
int _E1353()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels, "DetailLevels");
  return atexit(_E1354);
}

//----- (006CB360) --------------------------------------------------------  // acclient.c:738757
int _E1356()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low, "Low");
  return atexit(_E1357);
}

//----- (006CB380) --------------------------------------------------------  // acclient.c:738764
int _E1359()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium, "Medium");
  return atexit(_E1360);
}

//----- (006CB3A0) --------------------------------------------------------  // acclient.c:738771
int _E1362()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High, "High");
  return atexit(_E1363);
}

//----- (006CB3C0) --------------------------------------------------------  // acclient.c:738778
int _E1365()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed, "FadeSpeed");
  return atexit(_E1366);
}

//----- (006CB3E0) --------------------------------------------------------  // acclient.c:738785
int _E1368()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity, "MaxOpacity");
  return atexit(_E1369);
}

//----- (006CB400) --------------------------------------------------------  // acclient.c:738792
int _E1371()
{
  PStringBase<char>::PStringBase<char>(&Point_1, "Point");
  return atexit(_E1372);
}

//----- (006CB420) --------------------------------------------------------  // acclient.c:738799
int _E1374()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos, "AxisPos");
  return atexit(_E1375);
}

//----- (006CB440) --------------------------------------------------------  // acclient.c:738806
int _E1377()
{
  PStringBase<char>::PStringBase<char>(&PointTexture, "Texture");
  return atexit(_E1378);
}

//----- (006CB460) --------------------------------------------------------  // acclient.c:738813
int _E1380()
{
  PStringBase<char>::PStringBase<char>(&PointSize, "Size");
  return atexit(_E1381);
}

//----- (006CB480) --------------------------------------------------------  // acclient.c:738820
int _E1383()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion, "UseOcclusion");
  return atexit(_E1384);
}

//----- (006CB4A0) --------------------------------------------------------  // acclient.c:738827
int _E1386()
{
  PStringBase<char>::PStringBase<char>(&PreprocHeader, "PREPROC_HEADER");
  return atexit(_E1387);
}

//----- (006CB4C0) --------------------------------------------------------  // acclient.c:738834
int _E1389()
{
  PStringBase<char>::PStringBase<char>(&MeshAppearanceType, "MeshAppearanceType");
  return atexit(_E1390);
}

//----- (006CB4E0) --------------------------------------------------------  // acclient.c:738841
int _E1392()
{
  PStringBase<char>::PStringBase<char>(&Fragment, "Fragment");
  return atexit(_E1393);
}

//----- (006CB500) --------------------------------------------------------  // acclient.c:738848
int _E1395()
{
  PStringBase<char>::PStringBase<char>(&FragmentType, "FragmentType");
  return atexit(_E1396);
}

//----- (006CB520) --------------------------------------------------------  // acclient.c:738855
int _E1398()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_LevelOfDetailModel, "LevelOfDetailModel");
  return atexit(_E1399);
}

//----- (006CB540) --------------------------------------------------------  // acclient.c:738862
int _E1401()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_OccludeModel, "OccludeModel");
  return atexit(_E1402);
}

//----- (006CB560) --------------------------------------------------------  // acclient.c:738869
int _E1404()
{
  PStringBase<char>::PStringBase<char>(&FragmentType_ShadowLODModel, "ShadowLODModel");
  return atexit(_E1405);
}

//----- (006CB580) --------------------------------------------------------  // acclient.c:738876
int _E1407()
{
  PStringBase<char>::PStringBase<char>(&FragmentTopology, "FragmentTopology");
  return atexit(_E1408);
}

//----- (006CB5A0) --------------------------------------------------------  // acclient.c:738883
int _E1410()
{
  PStringBase<char>::PStringBase<char>(&FragmentMOPP, "FragmentMOPP");
  return atexit(_E1411);
}

//----- (006CB5C0) --------------------------------------------------------  // acclient.c:738890
int _E1413()
{
  PStringBase<char>::PStringBase<char>(&MaterialBatch, "MaterialBatch");
  return atexit(_E1414);
}

//----- (006CB5E0) --------------------------------------------------------  // acclient.c:738897
int _E1416()
{
  PStringBase<char>::PStringBase<char>(&FragmentBatch, "FragmentBatch");
  return atexit(_E1417);
}

//----- (006CB600) --------------------------------------------------------  // acclient.c:738904
int _E1419()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType, "PrimitivesType");
  return atexit(_E1420);
}

//----- (006CB620) --------------------------------------------------------  // acclient.c:738911
int _E1422()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_PointList, "PointList");
  return atexit(_E1423);
}

//----- (006CB640) --------------------------------------------------------  // acclient.c:738918
int _E1425()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineList, "LineList");
  return atexit(_E1426);
}

//----- (006CB660) --------------------------------------------------------  // acclient.c:738925
int _E1428()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_LineStrip, "LineStrip");
  return atexit(_E1429);
}

//----- (006CB680) --------------------------------------------------------  // acclient.c:738932
int _E1431()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleList, "TriangleList");
  return atexit(_E1432);
}

//----- (006CB6A0) --------------------------------------------------------  // acclient.c:738939
int _E1434()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleStrip, "TriangleStrip");
  return atexit(_E1435);
}

//----- (006CB6C0) --------------------------------------------------------  // acclient.c:738946
int _E1437()
{
  PStringBase<char>::PStringBase<char>(&PrimitivesType_TriangleFan, "TriangleFan");
  return atexit(_E1438);
}

//----- (006CB6E0) --------------------------------------------------------  // acclient.c:738953
int _E1440()
{
  PStringBase<char>::PStringBase<char>(&Material_3, "Material");
  return atexit(_E1441);
}

//----- (006CB700) --------------------------------------------------------  // acclient.c:738960
int _E1443()
{
  PStringBase<char>::PStringBase<char>(&Vertices, "Vertices");
  return atexit(_E1444);
}

//----- (006CB720) --------------------------------------------------------  // acclient.c:738967
int _E1446()
{
  PStringBase<char>::PStringBase<char>(&Indices_0, "Indices");
  return atexit(_E1447);
}

//----- (006CB740) --------------------------------------------------------  // acclient.c:738974
int _E1449()
{
  PStringBase<char>::PStringBase<char>(&ExportMeshAppearanceType, "MeshType");
  return atexit(_E1450);
}

//----- (006CB760) --------------------------------------------------------  // acclient.c:738981
int _E1452()
{
  PStringBase<char>::PStringBase<char>(&MeshDegradeType, "MeshDegradeType");
  return atexit(_E1453);
}

//----- (006CB780) --------------------------------------------------------  // acclient.c:738988
int _E1455()
{
  PStringBase<char>::PStringBase<char>(&DegradeLevel, "DegLevel");
  return atexit(_E1456);
}

//----- (006CB7A0) --------------------------------------------------------  // acclient.c:738995
int _E1458()
{
  PStringBase<char>::PStringBase<char>(&NumDegradeLevels, "NumDegrades");
  return atexit(_E1459);
}

//----- (006CB7C0) --------------------------------------------------------  // acclient.c:739002
int _E1461()
{
  PStringBase<char>::PStringBase<char>(&CellMesh, "CellMesh");
  return atexit(_E1462);
}

//----- (006CB7E0) --------------------------------------------------------  // acclient.c:739009
int _E1464()
{
  PStringBase<char>::PStringBase<char>(&MaterialArray, "MaterialArray");
  return atexit(_E1465);
}

//----- (006CB800) --------------------------------------------------------  // acclient.c:739016
int _E1467()
{
  PStringBase<char>::PStringBase<char>(&Render, "Render");
  return atexit(_E1468);
}

//----- (006CB820) --------------------------------------------------------  // acclient.c:739023
int _E1470()
{
  PStringBase<char>::PStringBase<char>(&RenderMesh, "RenderMesh");
  return atexit(_E1471);
}

//----- (006CB840) --------------------------------------------------------  // acclient.c:739030
int _E1473()
{
  PStringBase<char>::PStringBase<char>(&RenderMeshVersion, "RenderMeshVersioned");
  return atexit(_E1474);
}

//----- (006CB860) --------------------------------------------------------  // acclient.c:739037
int _E1476()
{
  PStringBase<char>::PStringBase<char>(&Sphere_0, "Sphere");
  return atexit(_E1477);
}

//----- (006CB880) --------------------------------------------------------  // acclient.c:739044
int _E1479()
{
  PStringBase<char>::PStringBase<char>(&DetailedBSP, "DetailedBSP");
  return atexit(_E1480);
}

//----- (006CB8A0) --------------------------------------------------------  // acclient.c:739051
int _E1482()
{
  PStringBase<char>::PStringBase<char>(&PolygonArray, "PolygonArray");
  return atexit(_E1483);
}

//----- (006CB8C0) --------------------------------------------------------  // acclient.c:739058
int _E1485()
{
  PStringBase<char>::PStringBase<char>(&BinaryPolygonArray, "BinaryPolygonArray");
  return atexit(_E1486);
}

//----- (006CB8E0) --------------------------------------------------------  // acclient.c:739065
int _E1488()
{
  PStringBase<char>::PStringBase<char>(&Physics, "Physics");
  return atexit(_E1489);
}

//----- (006CB900) --------------------------------------------------------  // acclient.c:739072
int _E1491()
{
  PStringBase<char>::PStringBase<char>(&BSPTree, "BSPTree");
  return atexit(_E1492);
}

//----- (006CB920) --------------------------------------------------------  // acclient.c:739079
int _E1494()
{
  PStringBase<char>::PStringBase<char>(&BinaryBSPTree, "BinaryBSPTree");
  return atexit(_E1495);
}

//----- (006CB940) --------------------------------------------------------  // acclient.c:739086
int _E1497()
{
  PStringBase<char>::PStringBase<char>(&Cell, "Cell");
  return atexit(_E1498);
}

//----- (006CB960) --------------------------------------------------------  // acclient.c:739093
int _E1500()
{
  PStringBase<char>::PStringBase<char>(&CellBSP, "CellBSP");
  return atexit(_E1501);
}

//----- (006CB980) --------------------------------------------------------  // acclient.c:739100
int _E1503()
{
  PStringBase<char>::PStringBase<char>(&Portals, "Portals");
  return atexit(_E1504);
}

//----- (006CB9A0) --------------------------------------------------------  // acclient.c:739107
int _E1506()
{
  PStringBase<char>::PStringBase<char>(&Portal_0, "Portal");
  return atexit(_E1507);
}

//----- (006CB9C0) --------------------------------------------------------  // acclient.c:739114
int _E1509()
{
  PStringBase<char>::PStringBase<char>(&NonPortals, "NonPortals");
  return atexit(_E1510);
}

//----- (006CB9E0) --------------------------------------------------------  // acclient.c:739121
int _E1512()
{
  PStringBase<char>::PStringBase<char>(&NonPortal, "NonPortal");
  return atexit(_E1513);
}

//----- (006CBA00) --------------------------------------------------------  // acclient.c:739128
int _E1515()
{
  PStringBase<char>::PStringBase<char>(&Info, "Info");
  return atexit(_E1516);
}

//----- (006CBA20) --------------------------------------------------------  // acclient.c:739135
int _E1518()
{
  PStringBase<char>::PStringBase<char>(&CellVolumeInfo, "CellVolumeInfo");
  return atexit(_E1519);
}

//----- (006CBA40) --------------------------------------------------------  // acclient.c:739142
int _E1521()
{
  PStringBase<char>::PStringBase<char>(&CellStructure, "CellStructure ");
  return atexit(_E1522);
}

//----- (006CBA60) --------------------------------------------------------  // acclient.c:739149
int _E1524()
{
  PStringBase<char>::PStringBase<char>(&CellRotation, "Rotation");
  return atexit(_E1525);
}

//----- (006CBA80) --------------------------------------------------------  // acclient.c:739156
int _E1527()
{
  PStringBase<char>::PStringBase<char>(&CellGridSize, "GridSize");
  return atexit(_E1528);
}

//----- (006CBAA0) --------------------------------------------------------  // acclient.c:739163
int _E1530()
{
  PStringBase<char>::PStringBase<char>(&CellNeverCull, "CellNeverCull");
  return atexit(_E1531);
}

//----- (006CBAC0) --------------------------------------------------------  // acclient.c:739170
int _E1533()
{
  PStringBase<char>::PStringBase<char>(&CellDrawSky, "CellDrawSky");
  return atexit(_E1534);
}

//----- (006CBAE0) --------------------------------------------------------  // acclient.c:739177
int _E1536()
{
  PStringBase<char>::PStringBase<char>(&DegradeArray, "Degrades");
  return atexit(_E1537);
}

//----- (006CBB00) --------------------------------------------------------  // acclient.c:739184
int _E1539()
{
  PStringBase<char>::PStringBase<char>(&OccludeMeshArray, "OccludeMeshes");
  return atexit(_E1540);
}

//----- (006CBB20) --------------------------------------------------------  // acclient.c:739191
int _E1542()
{
  PStringBase<char>::PStringBase<char>(&DegradeMesh, "DegradeMesh");
  return atexit(_E1543);
}

//----- (006CBB40) --------------------------------------------------------  // acclient.c:739198
int _E1545()
{
  PStringBase<char>::PStringBase<char>(&BSP, "BSP");
  return atexit(_E1546);
}

//----- (006CBB60) --------------------------------------------------------  // acclient.c:739205
int _E1548()
{
  PStringBase<char>::PStringBase<char>(&BumpMap, "BumpMap");
  return atexit(_E1549);
}

//----- (006CBB80) --------------------------------------------------------  // acclient.c:739212
int _E1551()
{
  PStringBase<char>::PStringBase<char>(&UVSets, "UVSets");
  return atexit(_E1552);
}

//----- (006CBBA0) --------------------------------------------------------  // acclient.c:739219
int _E1554()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMesh, "PhysicsMesh");
  return atexit(_E1555);
}

//----- (006CBBC0) --------------------------------------------------------  // acclient.c:739226
int _E1557()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterials, "PhysicsMaterials");
  return atexit(_E1558);
}

//----- (006CBBE0) --------------------------------------------------------  // acclient.c:739233
int _E1560()
{
  PStringBase<char>::PStringBase<char>(&PhysicsMaterialArray, "PhysicsMaterialArray");
  return atexit(_E1561);
}

//----- (006CBC00) --------------------------------------------------------  // acclient.c:739240
int _E1563()
{
  PStringBase<char>::PStringBase<char>(&PathMapMeshArray, "PathMapMeshes");
  return atexit(_E1564);
}

//----- (006CBC20) --------------------------------------------------------  // acclient.c:739247
int _E1566()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygonArray, "PathMapPolygonArray");
  return atexit(_E1567);
}

//----- (006CBC40) --------------------------------------------------------  // acclient.c:739254
int _E1569()
{
  PStringBase<char>::PStringBase<char>(&PathMapPolygon, "PathMapPolygon");
  return atexit(_E1570);
}

//----- (006CBC60) --------------------------------------------------------  // acclient.c:739261
int _E1572()
{
  PStringBase<char>::PStringBase<char>(&VertexSetArray, "VertexSetArray");
  return atexit(_E1573);
}

//----- (006CBC80) --------------------------------------------------------  // acclient.c:739268
int _E1575()
{
  PStringBase<char>::PStringBase<char>(&VertexSets, "VertexSets");
  return atexit(_E1576);
}

//----- (006CBCA0) --------------------------------------------------------  // acclient.c:739275
int _E1578()
{
  PStringBase<char>::PStringBase<char>(&VertexSet, "VertexSet");
  return atexit(_E1579);
}

//----- (006CBCC0) --------------------------------------------------------  // acclient.c:739282
int _E1581()
{
  PStringBase<char>::PStringBase<char>(&Set, "Set");
  return atexit(_E1582);
}

//----- (006CBCE0) --------------------------------------------------------  // acclient.c:739289
int _E1584()
{
  PStringBase<char>::PStringBase<char>(&ID_1, "ID");
  return atexit(_E1585);
}

//----- (006CBD00) --------------------------------------------------------  // acclient.c:739296
int _E1587()
{
  PStringBase<char>::PStringBase<char>(&Name, "Name");
  return atexit(_E1588);
}

//----- (006CBD20) --------------------------------------------------------  // acclient.c:739303
int _E1590()
{
  PStringBase<char>::PStringBase<char>(&Indices_1, "Indices");
  return atexit(_E1591);
}

//----- (006CBD40) --------------------------------------------------------  // acclient.c:739310
int _E1593()
{
  PStringBase<char>::PStringBase<char>(&MorphMeshArray, "MorphMeshArray");
  return atexit(_E1594);
}

//----- (006CBD60) --------------------------------------------------------  // acclient.c:739317
int _E1596()
{
  PStringBase<char>::PStringBase<char>(&MorphMesh, "MorphMesh");
  return atexit(_E1597);
}

//----- (006CBD80) --------------------------------------------------------  // acclient.c:739324
int _E1599()
{
  PStringBase<char>::PStringBase<char>(&MorphTargets, "MorphTargets");
  return atexit(_E1600);
}

//----- (006CBDA0) --------------------------------------------------------  // acclient.c:739331
int _E1602()
{
  PStringBase<char>::PStringBase<char>(&Target, "Target");
  return atexit(_E1603);
}

//----- (006CBDC0) --------------------------------------------------------  // acclient.c:739338
int _E1605()
{
  PStringBase<char>::PStringBase<char>(&Name_0, "Name");
  return atexit(_E1606);
}

//----- (006CBDE0) --------------------------------------------------------  // acclient.c:739345
int _E1_34()
{
  return atexit(_E2_34);
}

//----- (0072AEA0) --------------------------------------------------------  // acclient.c:829169
void __cdecl _E202_36()
{
  char *v0; // esi@1

  v0 = &PHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AED0) --------------------------------------------------------  // acclient.c:829182
void __cdecl _E205_33()
{
  char *v0; // esi@1

  v0 = &VertexArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AF00) --------------------------------------------------------  // acclient.c:829195
void __cdecl _E208_37()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AF30) --------------------------------------------------------  // acclient.c:829208
void __cdecl _E211_33()
{
  char *v0; // esi@1

  v0 = &VertexType_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AF60) --------------------------------------------------------  // acclient.c:829221
void __cdecl _E214_36()
{
  char *v0; // esi@1

  v0 = &VertexData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AF90) --------------------------------------------------------  // acclient.c:829234
void __cdecl _E217_32()
{
  char *v0; // esi@1

  v0 = &Vertex.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AFC0) --------------------------------------------------------  // acclient.c:829247
void __cdecl _E220_32()
{
  char *v0; // esi@1

  v0 = &Index.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072AFF0) --------------------------------------------------------  // acclient.c:829260
void __cdecl _E223_32()
{
  char *v0; // esi@1

  v0 = &Origin.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B020) --------------------------------------------------------  // acclient.c:829273
void __cdecl _E226_18()
{
  char *v0; // esi@1

  v0 = &Normal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B050) --------------------------------------------------------  // acclient.c:829286
void __cdecl _E229_18()
{
  char *v0; // esi@1

  v0 = &Diffuse.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B080) --------------------------------------------------------  // acclient.c:829299
void __cdecl _E232_18()
{
  char *v0; // esi@1

  v0 = &Specular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B0B0) --------------------------------------------------------  // acclient.c:829312
void __cdecl _E235_18()
{
  char *v0; // esi@1

  v0 = &UVS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B0E0) --------------------------------------------------------  // acclient.c:829325
void __cdecl _E238_16()
{
  char *v0; // esi@1

  v0 = &VectorS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B110) --------------------------------------------------------  // acclient.c:829338
void __cdecl _E241_16()
{
  char *v0; // esi@1

  v0 = &VectorT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B140) --------------------------------------------------------  // acclient.c:829351
void __cdecl _E244_16()
{
  char *v0; // esi@1

  v0 = &VectorSxT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B170) --------------------------------------------------------  // acclient.c:829364
void __cdecl _E247_15()
{
  char *v0; // esi@1

  v0 = &Weights.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B1A0) --------------------------------------------------------  // acclient.c:829377
void __cdecl _E250_15()
{
  char *v0; // esi@1

  v0 = &Importance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B1D0) --------------------------------------------------------  // acclient.c:829390
void __cdecl _E253_15()
{
  char *v0; // esi@1

  v0 = &PhysMtl.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B200) --------------------------------------------------------  // acclient.c:829403
void __cdecl _E256_15()
{
  char *v0; // esi@1

  v0 = &Material.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B230) --------------------------------------------------------  // acclient.c:829416
void __cdecl _E259_16()
{
  char *v0; // esi@1

  v0 = &ID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B260) --------------------------------------------------------  // acclient.c:829429
void __cdecl _E262_16()
{
  char *v0; // esi@1

  v0 = &FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B290) --------------------------------------------------------  // acclient.c:829442
void __cdecl _E265_16()
{
  char *v0; // esi@1

  v0 = &Polygon.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B2C0) --------------------------------------------------------  // acclient.c:829455
void __cdecl _E268_15()
{
  char *v0; // esi@1

  v0 = &ID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B2F0) --------------------------------------------------------  // acclient.c:829468
void __cdecl _E271_14()
{
  char *v0; // esi@1

  v0 = &Indices.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B320) --------------------------------------------------------  // acclient.c:829481
void __cdecl _E274_14()
{
  char *v0; // esi@1

  v0 = &MaterialID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B350) --------------------------------------------------------  // acclient.c:829494
void __cdecl _E277_14()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B380) --------------------------------------------------------  // acclient.c:829507
void __cdecl _E280_13()
{
  char *v0; // esi@1

  v0 = &Markings.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B3B0) --------------------------------------------------------  // acclient.c:829520
void __cdecl _E283_13()
{
  char *v0; // esi@1

  v0 = &Material_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B3E0) --------------------------------------------------------  // acclient.c:829533
void __cdecl _E286_12()
{
  char *v0; // esi@1

  v0 = &Index_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B410) --------------------------------------------------------  // acclient.c:829546
void __cdecl _E289_11()
{
  char *v0; // esi@1

  v0 = &Filename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B440) --------------------------------------------------------  // acclient.c:829559
void __cdecl _E292_12()
{
  char *v0; // esi@1

  v0 = &Surface.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B470) --------------------------------------------------------  // acclient.c:829572
void __cdecl _E295_11()
{
  char *v0; // esi@1

  v0 = &CellPoly.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B4A0) --------------------------------------------------------  // acclient.c:829585
void __cdecl _E298_12()
{
  char *v0; // esi@1

  v0 = &Sphere.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B4D0) --------------------------------------------------------  // acclient.c:829598
void __cdecl _E301_10()
{
  char *v0; // esi@1

  v0 = &Side.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B500) --------------------------------------------------------  // acclient.c:829611
void __cdecl _E304_11()
{
  char *v0; // esi@1

  v0 = &Positive.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B530) --------------------------------------------------------  // acclient.c:829624
void __cdecl _E307_10()
{
  char *v0; // esi@1

  v0 = &Negative.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B560) --------------------------------------------------------  // acclient.c:829637
void __cdecl _E310_11()
{
  char *v0; // esi@1

  v0 = &Polygon_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B590) --------------------------------------------------------  // acclient.c:829650
void __cdecl _E313_10()
{
  char *v0; // esi@1

  v0 = &OtherCell.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B5C0) --------------------------------------------------------  // acclient.c:829663
void __cdecl _E316_11()
{
  char *v0; // esi@1

  v0 = &CellPortal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B5F0) --------------------------------------------------------  // acclient.c:829676
void __cdecl _E319_10()
{
  char *v0; // esi@1

  v0 = &Portal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B620) --------------------------------------------------------  // acclient.c:829689
void __cdecl _E322_10()
{
  char *v0; // esi@1

  v0 = &OtherCell_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B650) --------------------------------------------------------  // acclient.c:829702
void __cdecl _E325_9()
{
  char *v0; // esi@1

  v0 = &OtherPortal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B680) --------------------------------------------------------  // acclient.c:829715
void __cdecl _E328_10()
{
  char *v0; // esi@1

  v0 = &ExactMatch.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B6B0) --------------------------------------------------------  // acclient.c:829728
void __cdecl _E331_9()
{
  char *v0; // esi@1

  v0 = &StabList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B6E0) --------------------------------------------------------  // acclient.c:829741
void __cdecl _E334_9()
{
  char *v0; // esi@1

  v0 = &Period.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B710) --------------------------------------------------------  // acclient.c:829754
void __cdecl _E337_9()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B740) --------------------------------------------------------  // acclient.c:829767
void __cdecl _E340_9()
{
  char *v0; // esi@1

  v0 = &Transform.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B770) --------------------------------------------------------  // acclient.c:829780
void __cdecl _E343_6()
{
  char *v0; // esi@1

  v0 = &Scale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B7A0) --------------------------------------------------------  // acclient.c:829793
void __cdecl _E346_6()
{
  char *v0; // esi@1

  v0 = &Weight.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B7D0) --------------------------------------------------------  // acclient.c:829806
void __cdecl _E349_6()
{
  char *v0; // esi@1

  v0 = &Offset.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B800) --------------------------------------------------------  // acclient.c:829819
void __cdecl _E352_6()
{
  char *v0; // esi@1

  v0 = &Quaternion_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B830) --------------------------------------------------------  // acclient.c:829832
void __cdecl _E355_6()
{
  char *v0; // esi@1

  v0 = &Rotation.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B860) --------------------------------------------------------  // acclient.c:829845
void __cdecl _E358_6()
{
  char *v0; // esi@1

  v0 = &STime.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B890) --------------------------------------------------------  // acclient.c:829858
void __cdecl _E361_6()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B8C0) --------------------------------------------------------  // acclient.c:829871
void __cdecl _E364_6()
{
  char *v0; // esi@1

  v0 = &BoneOpacities.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B8F0) --------------------------------------------------------  // acclient.c:829884
void __cdecl _E367_6()
{
  char *v0; // esi@1

  v0 = &LowPt.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B920) --------------------------------------------------------  // acclient.c:829897
void __cdecl _E370_6()
{
  char *v0; // esi@1

  v0 = &Radius.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B950) --------------------------------------------------------  // acclient.c:829910
void __cdecl _E373_6()
{
  char *v0; // esi@1

  v0 = &Height.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B980) --------------------------------------------------------  // acclient.c:829923
void __cdecl _E376_6()
{
  char *v0; // esi@1

  v0 = &Texture2D.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B9B0) --------------------------------------------------------  // acclient.c:829936
void __cdecl _E379_6()
{
  char *v0; // esi@1

  v0 = &Texture3D.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072B9E0) --------------------------------------------------------  // acclient.c:829949
void __cdecl _E382_6()
{
  char *v0; // esi@1

  v0 = &TextureCube.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BA10) --------------------------------------------------------  // acclient.c:829962
void __cdecl _E385_6()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BA40) --------------------------------------------------------  // acclient.c:829975
void __cdecl _E388_6()
{
  char *v0; // esi@1

  v0 = &MovieFileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BA70) --------------------------------------------------------  // acclient.c:829988
void __cdecl _E391_6()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BAA0) --------------------------------------------------------  // acclient.c:830001
void __cdecl _E394_6()
{
  char *v0; // esi@1

  v0 = &Levels.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BAD0) --------------------------------------------------------  // acclient.c:830014
void __cdecl _E397_6()
{
  char *v0; // esi@1

  v0 = &NodeName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BB00) --------------------------------------------------------  // acclient.c:830027
void __cdecl _E400_6()
{
  char *v0; // esi@1

  v0 = &Material_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BB30) --------------------------------------------------------  // acclient.c:830040
void __cdecl _E403_6()
{
  char *v0; // esi@1

  v0 = &MaterialType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BB60) --------------------------------------------------------  // acclient.c:830053
void __cdecl _E406_6()
{
  char *v0; // esi@1

  v0 = &Modifier.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BB90) --------------------------------------------------------  // acclient.c:830066
void __cdecl _E409_6()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BBC0) --------------------------------------------------------  // acclient.c:830079
void __cdecl _E412_6()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BBF0) --------------------------------------------------------  // acclient.c:830092
void __cdecl _E415_6()
{
  char *v0; // esi@1

  v0 = &NodeName_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BC20) --------------------------------------------------------  // acclient.c:830105
void __cdecl _E418_6()
{
  char *v0; // esi@1

  v0 = &SortMode.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BC50) --------------------------------------------------------  // acclient.c:830118
void __cdecl _E421_6()
{
  char *v0; // esi@1

  v0 = &SortMode_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BC80) --------------------------------------------------------  // acclient.c:830131
void __cdecl _E424_6()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BCB0) --------------------------------------------------------  // acclient.c:830144
void __cdecl _E427_6()
{
  char *v0; // esi@1

  v0 = &NodeName_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BCE0) --------------------------------------------------------  // acclient.c:830157
void __cdecl _E430_6()
{
  char *v0; // esi@1

  v0 = &NodeName_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BD10) --------------------------------------------------------  // acclient.c:830170
void __cdecl _E433_6()
{
  char *v0; // esi@1

  v0 = &DataType_DATA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BD40) --------------------------------------------------------  // acclient.c:830183
void __cdecl _E436_6()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BD70) --------------------------------------------------------  // acclient.c:830196
void __cdecl _E439_6()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BDA0) --------------------------------------------------------  // acclient.c:830209
void __cdecl _E442_6()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BDD0) --------------------------------------------------------  // acclient.c:830222
void __cdecl _E445_6()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BE00) --------------------------------------------------------  // acclient.c:830235
void __cdecl _E448_6()
{
  char *v0; // esi@1

  v0 = &NodeName_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BE30) --------------------------------------------------------  // acclient.c:830248
void __cdecl _E451_6()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BE60) --------------------------------------------------------  // acclient.c:830261
void __cdecl _E454_6()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BE90) --------------------------------------------------------  // acclient.c:830274
void __cdecl _E457_6()
{
  char *v0; // esi@1

  v0 = &modType_UVScale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BEC0) --------------------------------------------------------  // acclient.c:830287
void __cdecl _E460_6()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BEF0) --------------------------------------------------------  // acclient.c:830300
void __cdecl _E463_6()
{
  char *v0; // esi@1

  v0 = &TrueFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BF20) --------------------------------------------------------  // acclient.c:830313
void __cdecl _E466_6()
{
  char *v0; // esi@1

  v0 = &FalseFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BF50) --------------------------------------------------------  // acclient.c:830326
void __cdecl _E469_6()
{
  char *v0; // esi@1

  v0 = &RenderPass.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BF80) --------------------------------------------------------  // acclient.c:830339
void __cdecl _E472_6()
{
  char *v0; // esi@1

  v0 = &Blend.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BFB0) --------------------------------------------------------  // acclient.c:830352
void __cdecl _E475_6()
{
  char *v0; // esi@1

  v0 = &DepthTest.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072BFE0) --------------------------------------------------------  // acclient.c:830365
void __cdecl _E478_6()
{
  char *v0; // esi@1

  v0 = &DepthWrite.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C010) --------------------------------------------------------  // acclient.c:830378
void __cdecl _E481_6()
{
  char *v0; // esi@1

  v0 = &CullMode.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C040) --------------------------------------------------------  // acclient.c:830391
void __cdecl _E484_6()
{
  char *v0; // esi@1

  v0 = &DepthFog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C070) --------------------------------------------------------  // acclient.c:830404
void __cdecl _E487_6()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C0A0) --------------------------------------------------------  // acclient.c:830417
void __cdecl _E490_6()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C0D0) --------------------------------------------------------  // acclient.c:830430
void __cdecl _E493_6()
{
  char *v0; // esi@1

  v0 = &FFUseLighting.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C100) --------------------------------------------------------  // acclient.c:830443
void __cdecl _E496_6()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C130) --------------------------------------------------------  // acclient.c:830456
void __cdecl _E499_6()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C160) --------------------------------------------------------  // acclient.c:830469
void __cdecl _E502_6()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C190) --------------------------------------------------------  // acclient.c:830482
void __cdecl _E505_6()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C1C0) --------------------------------------------------------  // acclient.c:830495
void __cdecl _E508_6()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C1F0) --------------------------------------------------------  // acclient.c:830508
void __cdecl _E511_6()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C220) --------------------------------------------------------  // acclient.c:830521
void __cdecl _E514_6()
{
  char *v0; // esi@1

  v0 = &UsesTransparency.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C250) --------------------------------------------------------  // acclient.c:830534
void __cdecl _E517_6()
{
  char *v0; // esi@1

  v0 = &Ambient.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C280) --------------------------------------------------------  // acclient.c:830547
void __cdecl _E520_6()
{
  char *v0; // esi@1

  v0 = &Diffuse_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C2B0) --------------------------------------------------------  // acclient.c:830560
void __cdecl _E523_6()
{
  char *v0; // esi@1

  v0 = &Specular_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C2E0) --------------------------------------------------------  // acclient.c:830573
void __cdecl _E526_6()
{
  char *v0; // esi@1

  v0 = &SpecularPower.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C310) --------------------------------------------------------  // acclient.c:830586
void __cdecl _E529_6()
{
  char *v0; // esi@1

  v0 = &Dye.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C340) --------------------------------------------------------  // acclient.c:830599
void __cdecl _E532_6()
{
  char *v0; // esi@1

  v0 = &Emissive.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C370) --------------------------------------------------------  // acclient.c:830612
void __cdecl _E535_6()
{
  char *v0; // esi@1

  v0 = &VertexFormat.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C3A0) --------------------------------------------------------  // acclient.c:830625
void __cdecl _E538_6()
{
  char *v0; // esi@1

  v0 = &VertexShader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C3D0) --------------------------------------------------------  // acclient.c:830638
void __cdecl _E541_6()
{
  char *v0; // esi@1

  v0 = &PixelShader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C400) --------------------------------------------------------  // acclient.c:830651
void __cdecl _E544_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C430) --------------------------------------------------------  // acclient.c:830664
void __cdecl _E547_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C460) --------------------------------------------------------  // acclient.c:830677
void __cdecl _E550_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C490) --------------------------------------------------------  // acclient.c:830690
void __cdecl _E553_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C4C0) --------------------------------------------------------  // acclient.c:830703
void __cdecl _E556_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C4F0) --------------------------------------------------------  // acclient.c:830716
void __cdecl _E559_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C520) --------------------------------------------------------  // acclient.c:830729
void __cdecl _E562_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C550) --------------------------------------------------------  // acclient.c:830742
void __cdecl _E565_6()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C580) --------------------------------------------------------  // acclient.c:830755
void __cdecl _E568_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C5B0) --------------------------------------------------------  // acclient.c:830768
void __cdecl _E571_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C5E0) --------------------------------------------------------  // acclient.c:830781
void __cdecl _E574_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C610) --------------------------------------------------------  // acclient.c:830794
void __cdecl _E577_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C640) --------------------------------------------------------  // acclient.c:830807
void __cdecl _E580_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C670) --------------------------------------------------------  // acclient.c:830820
void __cdecl _E583_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C6A0) --------------------------------------------------------  // acclient.c:830833
void __cdecl _E586_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C6D0) --------------------------------------------------------  // acclient.c:830846
void __cdecl _E589_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C700) --------------------------------------------------------  // acclient.c:830859
void __cdecl _E592_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C730) --------------------------------------------------------  // acclient.c:830872
void __cdecl _E595_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C760) --------------------------------------------------------  // acclient.c:830885
void __cdecl _E598_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C790) --------------------------------------------------------  // acclient.c:830898
void __cdecl _E601_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C7C0) --------------------------------------------------------  // acclient.c:830911
void __cdecl _E604_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C7F0) --------------------------------------------------------  // acclient.c:830924
void __cdecl _E607_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C820) --------------------------------------------------------  // acclient.c:830937
void __cdecl _E610_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C850) --------------------------------------------------------  // acclient.c:830950
void __cdecl _E613_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C880) --------------------------------------------------------  // acclient.c:830963
void __cdecl _E616_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C8B0) --------------------------------------------------------  // acclient.c:830976
void __cdecl _E619_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C8E0) --------------------------------------------------------  // acclient.c:830989
void __cdecl _E622_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C910) --------------------------------------------------------  // acclient.c:831002
void __cdecl _E625_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C940) --------------------------------------------------------  // acclient.c:831015
void __cdecl _E628_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C970) --------------------------------------------------------  // acclient.c:831028
void __cdecl _E631_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C9A0) --------------------------------------------------------  // acclient.c:831041
void __cdecl _E634_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072C9D0) --------------------------------------------------------  // acclient.c:831054
void __cdecl _E637_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CA00) --------------------------------------------------------  // acclient.c:831067
void __cdecl _E640_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CA30) --------------------------------------------------------  // acclient.c:831080
void __cdecl _E643_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CA60) --------------------------------------------------------  // acclient.c:831093
void __cdecl _E646_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CA90) --------------------------------------------------------  // acclient.c:831106
void __cdecl _E649_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CAC0) --------------------------------------------------------  // acclient.c:831119
void __cdecl _E652_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CAF0) --------------------------------------------------------  // acclient.c:831132
void __cdecl _E655_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CB20) --------------------------------------------------------  // acclient.c:831145
void __cdecl _E658_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CB50) --------------------------------------------------------  // acclient.c:831158
void __cdecl _E661_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CB80) --------------------------------------------------------  // acclient.c:831171
void __cdecl _E664_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CBB0) --------------------------------------------------------  // acclient.c:831184
void __cdecl _E667_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CBE0) --------------------------------------------------------  // acclient.c:831197
void __cdecl _E670_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CC10) --------------------------------------------------------  // acclient.c:831210
void __cdecl _E673_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CC40) --------------------------------------------------------  // acclient.c:831223
void __cdecl _E676_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CC70) --------------------------------------------------------  // acclient.c:831236
void __cdecl _E679_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CCA0) --------------------------------------------------------  // acclient.c:831249
void __cdecl _E682_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CCD0) --------------------------------------------------------  // acclient.c:831262
void __cdecl _E685_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CD00) --------------------------------------------------------  // acclient.c:831275
void __cdecl _E688_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CD30) --------------------------------------------------------  // acclient.c:831288
void __cdecl _E691_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CD60) --------------------------------------------------------  // acclient.c:831301
void __cdecl _E694_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CD90) --------------------------------------------------------  // acclient.c:831314
void __cdecl _E697_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CDC0) --------------------------------------------------------  // acclient.c:831327
void __cdecl _E700_6()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CDF0) --------------------------------------------------------  // acclient.c:831340
void __cdecl _E703_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CE20) --------------------------------------------------------  // acclient.c:831353
void __cdecl _E706_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CE50) --------------------------------------------------------  // acclient.c:831366
void __cdecl _E709_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CE80) --------------------------------------------------------  // acclient.c:831379
void __cdecl _E712_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CEB0) --------------------------------------------------------  // acclient.c:831392
void __cdecl _E715_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CEE0) --------------------------------------------------------  // acclient.c:831405
void __cdecl _E718_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CF10) --------------------------------------------------------  // acclient.c:831418
void __cdecl _E721_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CF40) --------------------------------------------------------  // acclient.c:831431
void __cdecl _E724_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CF70) --------------------------------------------------------  // acclient.c:831444
void __cdecl _E727_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CFA0) --------------------------------------------------------  // acclient.c:831457
void __cdecl _E730_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072CFD0) --------------------------------------------------------  // acclient.c:831470
void __cdecl _E733_6()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D000) --------------------------------------------------------  // acclient.c:831483
void __cdecl _E736_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D030) --------------------------------------------------------  // acclient.c:831496
void __cdecl _E739_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D060) --------------------------------------------------------  // acclient.c:831509
void __cdecl _E742_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D090) --------------------------------------------------------  // acclient.c:831522
void __cdecl _E745_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D0C0) --------------------------------------------------------  // acclient.c:831535
void __cdecl _E748_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D0F0) --------------------------------------------------------  // acclient.c:831548
void __cdecl _E751_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D120) --------------------------------------------------------  // acclient.c:831561
void __cdecl _E754_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D150) --------------------------------------------------------  // acclient.c:831574
void __cdecl _E757_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D180) --------------------------------------------------------  // acclient.c:831587
void __cdecl _E760_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D1B0) --------------------------------------------------------  // acclient.c:831600
void __cdecl _E763_6()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D1E0) --------------------------------------------------------  // acclient.c:831613
void __cdecl _E766_6()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D210) --------------------------------------------------------  // acclient.c:831626
void __cdecl _E769_6()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D240) --------------------------------------------------------  // acclient.c:831639
void __cdecl _E772_6()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D270) --------------------------------------------------------  // acclient.c:831652
void __cdecl _E775_6()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D2A0) --------------------------------------------------------  // acclient.c:831665
void __cdecl _E778_6()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D2D0) --------------------------------------------------------  // acclient.c:831678
void __cdecl _E781_6()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D300) --------------------------------------------------------  // acclient.c:831691
void __cdecl _E784_6()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D330) --------------------------------------------------------  // acclient.c:831704
void __cdecl _E787_6()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D360) --------------------------------------------------------  // acclient.c:831717
void __cdecl _E790_6()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D390) --------------------------------------------------------  // acclient.c:831730
void __cdecl _E793_6()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D3C0) --------------------------------------------------------  // acclient.c:831743
void __cdecl _E796_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D3F0) --------------------------------------------------------  // acclient.c:831756
void __cdecl _E799_6()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D420) --------------------------------------------------------  // acclient.c:831769
void __cdecl _E802_6()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D450) --------------------------------------------------------  // acclient.c:831782
void __cdecl _E805_6()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D480) --------------------------------------------------------  // acclient.c:831795
void __cdecl _E808_6()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D4B0) --------------------------------------------------------  // acclient.c:831808
void __cdecl _E811_6()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D4E0) --------------------------------------------------------  // acclient.c:831821
void __cdecl _E814_6()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D510) --------------------------------------------------------  // acclient.c:831834
void __cdecl _E817_6()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D540) --------------------------------------------------------  // acclient.c:831847
void __cdecl _E820_6()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D570) --------------------------------------------------------  // acclient.c:831860
void __cdecl _E823_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D5A0) --------------------------------------------------------  // acclient.c:831873
void __cdecl _E826_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D5D0) --------------------------------------------------------  // acclient.c:831886
void __cdecl _E829_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D600) --------------------------------------------------------  // acclient.c:831899
void __cdecl _E832_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D630) --------------------------------------------------------  // acclient.c:831912
void __cdecl _E835_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D660) --------------------------------------------------------  // acclient.c:831925
void __cdecl _E838_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D690) --------------------------------------------------------  // acclient.c:831938
void __cdecl _E841_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D6C0) --------------------------------------------------------  // acclient.c:831951
void __cdecl _E844_6()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D6F0) --------------------------------------------------------  // acclient.c:831964
void __cdecl _E847_6()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D720) --------------------------------------------------------  // acclient.c:831977
void __cdecl _E850_6()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D750) --------------------------------------------------------  // acclient.c:831990
void __cdecl _E853_6()
{
  char *v0; // esi@1

  v0 = &NodeName_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D780) --------------------------------------------------------  // acclient.c:832003
void __cdecl _E856_6()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D7B0) --------------------------------------------------------  // acclient.c:832016
void __cdecl _E859_6()
{
  char *v0; // esi@1

  v0 = &SamplerName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D7E0) --------------------------------------------------------  // acclient.c:832029
void __cdecl _E862_6()
{
  char *v0; // esi@1

  v0 = &Texture.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D810) --------------------------------------------------------  // acclient.c:832042
void __cdecl _E865_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D840) --------------------------------------------------------  // acclient.c:832055
void __cdecl _E868_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D870) --------------------------------------------------------  // acclient.c:832068
void __cdecl _E871_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D8A0) --------------------------------------------------------  // acclient.c:832081
void __cdecl _E874_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D8D0) --------------------------------------------------------  // acclient.c:832094
void __cdecl _E877_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D900) --------------------------------------------------------  // acclient.c:832107
void __cdecl _E880_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D930) --------------------------------------------------------  // acclient.c:832120
void __cdecl _E883_6()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D960) --------------------------------------------------------  // acclient.c:832133
void __cdecl _E886_6()
{
  char *v0; // esi@1

  v0 = &AddressMode.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D990) --------------------------------------------------------  // acclient.c:832146
void __cdecl _E889_6()
{
  char *v0; // esi@1

  v0 = &TexFilter.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D9C0) --------------------------------------------------------  // acclient.c:832159
void __cdecl _E892_6()
{
  char *v0; // esi@1

  v0 = &ColorOp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072D9F0) --------------------------------------------------------  // acclient.c:832172
void __cdecl _E895_6()
{
  char *v0; // esi@1

  v0 = &ColorArg1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DA20) --------------------------------------------------------  // acclient.c:832185
void __cdecl _E898_6()
{
  char *v0; // esi@1

  v0 = &ColorArg2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DA50) --------------------------------------------------------  // acclient.c:832198
void __cdecl _E901_6()
{
  char *v0; // esi@1

  v0 = &AlphaOp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DA80) --------------------------------------------------------  // acclient.c:832211
void __cdecl _E904_6()
{
  char *v0; // esi@1

  v0 = &AlphaArg1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DAB0) --------------------------------------------------------  // acclient.c:832224
void __cdecl _E907_6()
{
  char *v0; // esi@1

  v0 = &AlphaArg2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DAE0) --------------------------------------------------------  // acclient.c:832237
void __cdecl _E910_6()
{
  char *v0; // esi@1

  v0 = &TexCoord.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DB10) --------------------------------------------------------  // acclient.c:832250
void __cdecl _E913_6()
{
  char *v0; // esi@1

  v0 = &UseProjection.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DB40) --------------------------------------------------------  // acclient.c:832263
void __cdecl _E916_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DB70) --------------------------------------------------------  // acclient.c:832276
void __cdecl _E919_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DBA0) --------------------------------------------------------  // acclient.c:832289
void __cdecl _E922_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DBD0) --------------------------------------------------------  // acclient.c:832302
void __cdecl _E925_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DC00) --------------------------------------------------------  // acclient.c:832315
void __cdecl _E928_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DC30) --------------------------------------------------------  // acclient.c:832328
void __cdecl _E931_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DC60) --------------------------------------------------------  // acclient.c:832341
void __cdecl _E934_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DC90) --------------------------------------------------------  // acclient.c:832354
void __cdecl _E937_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DCC0) --------------------------------------------------------  // acclient.c:832367
void __cdecl _E940_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DCF0) --------------------------------------------------------  // acclient.c:832380
void __cdecl _E943_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DD20) --------------------------------------------------------  // acclient.c:832393
void __cdecl _E946_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DD50) --------------------------------------------------------  // acclient.c:832406
void __cdecl _E949_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DD80) --------------------------------------------------------  // acclient.c:832419
void __cdecl _E952_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DDB0) --------------------------------------------------------  // acclient.c:832432
void __cdecl _E955_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DDE0) --------------------------------------------------------  // acclient.c:832445
void __cdecl _E958_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DE10) --------------------------------------------------------  // acclient.c:832458
void __cdecl _E961_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DE40) --------------------------------------------------------  // acclient.c:832471
void __cdecl _E964_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DE70) --------------------------------------------------------  // acclient.c:832484
void __cdecl _E967_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DEA0) --------------------------------------------------------  // acclient.c:832497
void __cdecl _E970_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DED0) --------------------------------------------------------  // acclient.c:832510
void __cdecl _E973_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DF00) --------------------------------------------------------  // acclient.c:832523
void __cdecl _E976_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DF30) --------------------------------------------------------  // acclient.c:832536
void __cdecl _E979_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DF60) --------------------------------------------------------  // acclient.c:832549
void __cdecl _E982_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DF90) --------------------------------------------------------  // acclient.c:832562
void __cdecl _E985_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DFC0) --------------------------------------------------------  // acclient.c:832575
void __cdecl _E988_6()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072DFF0) --------------------------------------------------------  // acclient.c:832588
void __cdecl _E991_6()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E020) --------------------------------------------------------  // acclient.c:832601
void __cdecl _E994_6()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E050) --------------------------------------------------------  // acclient.c:832614
void __cdecl _E997_6()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E080) --------------------------------------------------------  // acclient.c:832627
void __cdecl _E1000_6()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E0B0) --------------------------------------------------------  // acclient.c:832640
void __cdecl _E1003_6()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E0E0) --------------------------------------------------------  // acclient.c:832653
void __cdecl _E1006_6()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E110) --------------------------------------------------------  // acclient.c:832666
void __cdecl _E1009_6()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E140) --------------------------------------------------------  // acclient.c:832679
void __cdecl _E1012_6()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E170) --------------------------------------------------------  // acclient.c:832692
void __cdecl _E1015_6()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E1A0) --------------------------------------------------------  // acclient.c:832705
void __cdecl _E1018_6()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E1D0) --------------------------------------------------------  // acclient.c:832718
void __cdecl _E1021_6()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E200) --------------------------------------------------------  // acclient.c:832731
void __cdecl _E1024_6()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E230) --------------------------------------------------------  // acclient.c:832744
void __cdecl _E1027_6()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E260) --------------------------------------------------------  // acclient.c:832757
void __cdecl _E1030_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E290) --------------------------------------------------------  // acclient.c:832770
void __cdecl _E1033_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E2C0) --------------------------------------------------------  // acclient.c:832783
void __cdecl _E1036_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E2F0) --------------------------------------------------------  // acclient.c:832796
void __cdecl _E1039_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E320) --------------------------------------------------------  // acclient.c:832809
void __cdecl _E1042_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E350) --------------------------------------------------------  // acclient.c:832822
void __cdecl _E1045_6()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E380) --------------------------------------------------------  // acclient.c:832835
void __cdecl _E1048_6()
{
  char *v0; // esi@1

  v0 = &NodeName_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E3B0) --------------------------------------------------------  // acclient.c:832848
void __cdecl _E1051_6()
{
  char *v0; // esi@1

  v0 = &ModType_Origin.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E3E0) --------------------------------------------------------  // acclient.c:832861
void __cdecl _E1054_6()
{
  char *v0; // esi@1

  v0 = &ModType_Normal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E410) --------------------------------------------------------  // acclient.c:832874
void __cdecl _E1057_6()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E440) --------------------------------------------------------  // acclient.c:832887
void __cdecl _E1060_6()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E470) --------------------------------------------------------  // acclient.c:832900
void __cdecl _E1063_6()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E4A0) --------------------------------------------------------  // acclient.c:832913
void __cdecl _E1066_6()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E4D0) --------------------------------------------------------  // acclient.c:832926
void __cdecl _E1069_6()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E500) --------------------------------------------------------  // acclient.c:832939
void __cdecl _E1072_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E530) --------------------------------------------------------  // acclient.c:832952
void __cdecl _E1075_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E560) --------------------------------------------------------  // acclient.c:832965
void __cdecl _E1078_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E590) --------------------------------------------------------  // acclient.c:832978
void __cdecl _E1081_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E5C0) --------------------------------------------------------  // acclient.c:832991
void __cdecl _E1084_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E5F0) --------------------------------------------------------  // acclient.c:833004
void __cdecl _E1087_6()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E620) --------------------------------------------------------  // acclient.c:833017
void __cdecl _E1090_6()
{
  char *v0; // esi@1

  v0 = &NodeName_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E650) --------------------------------------------------------  // acclient.c:833030
void __cdecl _E1093_6()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E680) --------------------------------------------------------  // acclient.c:833043
void __cdecl _E1096_6()
{
  char *v0; // esi@1

  v0 = &FastForwardTime.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E6B0) --------------------------------------------------------  // acclient.c:833056
void __cdecl _E1099_6()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E6E0) --------------------------------------------------------  // acclient.c:833069
void __cdecl _E1102_6()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E710) --------------------------------------------------------  // acclient.c:833082
void __cdecl _E1105_6()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E740) --------------------------------------------------------  // acclient.c:833095
void __cdecl _E1108_6()
{
  char *v0; // esi@1

  v0 = &ScaleType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E770) --------------------------------------------------------  // acclient.c:833108
void __cdecl _E1111_6()
{
  char *v0; // esi@1

  v0 = &WorldSpace.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E7A0) --------------------------------------------------------  // acclient.c:833121
void __cdecl _E1114_6()
{
  char *v0; // esi@1

  v0 = &ForceDraw.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E7D0) --------------------------------------------------------  // acclient.c:833134
void __cdecl _E1117_6()
{
  char *v0; // esi@1

  v0 = &NumEmitters.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E800) --------------------------------------------------------  // acclient.c:833147
void __cdecl _E1120_6()
{
  char *v0; // esi@1

  v0 = &Material_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E830) --------------------------------------------------------  // acclient.c:833160
void __cdecl _E1123_6()
{
  char *v0; // esi@1

  v0 = &Version.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E860) --------------------------------------------------------  // acclient.c:833173
void __cdecl _E1126_6()
{
  char *v0; // esi@1

  v0 = &MaxParticles.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E890) --------------------------------------------------------  // acclient.c:833186
void __cdecl _E1129_6()
{
  char *v0; // esi@1

  v0 = &NodeName_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E8C0) --------------------------------------------------------  // acclient.c:833199
void __cdecl _E1132_6()
{
  char *v0; // esi@1

  v0 = &Origin_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E8F0) --------------------------------------------------------  // acclient.c:833212
void __cdecl _E1135_6()
{
  char *v0; // esi@1

  v0 = &Shape.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E920) --------------------------------------------------------  // acclient.c:833225
void __cdecl _E1138_6()
{
  char *v0; // esi@1

  v0 = &Shape_Point.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E950) --------------------------------------------------------  // acclient.c:833238
void __cdecl _E1141_6()
{
  char *v0; // esi@1

  v0 = &Shape_Line.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E980) --------------------------------------------------------  // acclient.c:833251
void __cdecl _E1144_6()
{
  char *v0; // esi@1

  v0 = &Shape_Quad.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E9B0) --------------------------------------------------------  // acclient.c:833264
void __cdecl _E1147_6()
{
  char *v0; // esi@1

  v0 = &Shape_Disc.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072E9E0) --------------------------------------------------------  // acclient.c:833277
void __cdecl _E1150_6()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EA10) --------------------------------------------------------  // acclient.c:833290
void __cdecl _E1153_6()
{
  char *v0; // esi@1

  v0 = &ParticleShape.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EA40) --------------------------------------------------------  // acclient.c:833303
void __cdecl _E1156_6()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EA70) --------------------------------------------------------  // acclient.c:833316
void __cdecl _E1159_6()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EAA0) --------------------------------------------------------  // acclient.c:833329
void __cdecl _E1162_6()
{
  char *v0; // esi@1

  v0 = &Streak.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EAD0) --------------------------------------------------------  // acclient.c:833342
void __cdecl _E1165_6()
{
  char *v0; // esi@1

  v0 = &Rotation_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EB00) --------------------------------------------------------  // acclient.c:833355
void __cdecl _E1168_6()
{
  char *v0; // esi@1

  v0 = &WorldRotation.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EB30) --------------------------------------------------------  // acclient.c:833368
void __cdecl _E1171_6()
{
  char *v0; // esi@1

  v0 = &RotateVelocity.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EB60) --------------------------------------------------------  // acclient.c:833381
void __cdecl _E1174_6()
{
  char *v0; // esi@1

  v0 = &ParticleScale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EB90) --------------------------------------------------------  // acclient.c:833394
void __cdecl _E1177_6()
{
  char *v0; // esi@1

  v0 = &Scale_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EBC0) --------------------------------------------------------  // acclient.c:833407
void __cdecl _E1180_6()
{
  char *v0; // esi@1

  v0 = &ExplodingDir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EBF0) --------------------------------------------------------  // acclient.c:833420
void __cdecl _E1183_6()
{
  char *v0; // esi@1

  v0 = &BirthRate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EC20) --------------------------------------------------------  // acclient.c:833433
void __cdecl _E1186_6()
{
  char *v0; // esi@1

  v0 = &Lifespan.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EC50) --------------------------------------------------------  // acclient.c:833446
void __cdecl _E1189_6()
{
  char *v0; // esi@1

  v0 = &Velocity.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EC80) --------------------------------------------------------  // acclient.c:833459
void __cdecl _E1192_6()
{
  char *v0; // esi@1

  v0 = &Direction.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ECB0) --------------------------------------------------------  // acclient.c:833472
void __cdecl _E1195_6()
{
  char *v0; // esi@1

  v0 = &MinSpread.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ECE0) --------------------------------------------------------  // acclient.c:833485
void __cdecl _E1198_6()
{
  char *v0; // esi@1

  v0 = &MaxSpread.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ED10) --------------------------------------------------------  // acclient.c:833498
void __cdecl _E1201_6()
{
  char *v0; // esi@1

  v0 = &EmissionLimit.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ED40) --------------------------------------------------------  // acclient.c:833511
void __cdecl _E1204_6()
{
  char *v0; // esi@1

  v0 = &BlastCount.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072ED70) --------------------------------------------------------  // acclient.c:833524
void __cdecl _E1207_6()
{
  char *v0; // esi@1

  v0 = &StartTime.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EDA0) --------------------------------------------------------  // acclient.c:833537
void __cdecl _E1210_6()
{
  char *v0; // esi@1

  v0 = &TimeLimit.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EDD0) --------------------------------------------------------  // acclient.c:833550
void __cdecl _E1213_6()
{
  char *v0; // esi@1

  v0 = &EmissionDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EE00) --------------------------------------------------------  // acclient.c:833563
void __cdecl _E1216_6()
{
  char *v0; // esi@1

  v0 = &ParticleSnap.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EE30) --------------------------------------------------------  // acclient.c:833576
void __cdecl _E1219_6()
{
  char *v0; // esi@1

  v0 = &InclusiveShape.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EE60) --------------------------------------------------------  // acclient.c:833589
void __cdecl _E1222_6()
{
  char *v0; // esi@1

  v0 = &NumKeyframes.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EE90) --------------------------------------------------------  // acclient.c:833602
void __cdecl _E1225_6()
{
  char *v0; // esi@1

  v0 = &IsActive.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EEC0) --------------------------------------------------------  // acclient.c:833615
void __cdecl _E1228_6()
{
  char *v0; // esi@1

  v0 = &FadeIn.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EEF0) --------------------------------------------------------  // acclient.c:833628
void __cdecl _E1231_6()
{
  char *v0; // esi@1

  v0 = &FadeOut.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EF20) --------------------------------------------------------  // acclient.c:833641
void __cdecl _E1234_6()
{
  char *v0; // esi@1

  v0 = &ConstrainX.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EF50) --------------------------------------------------------  // acclient.c:833654
void __cdecl _E1237_6()
{
  char *v0; // esi@1

  v0 = &ConstrainY.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EF80) --------------------------------------------------------  // acclient.c:833667
void __cdecl _E1240_6()
{
  char *v0; // esi@1

  v0 = &ConstrainZ.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EFB0) --------------------------------------------------------  // acclient.c:833680
void __cdecl _E1243_6()
{
  char *v0; // esi@1

  v0 = &NodeName_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072EFE0) --------------------------------------------------------  // acclient.c:833693
void __cdecl _E1246_6()
{
  char *v0; // esi@1

  v0 = &Time.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F010) --------------------------------------------------------  // acclient.c:833706
void __cdecl _E1249_6()
{
  char *v0; // esi@1

  v0 = &Flags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F040) --------------------------------------------------------  // acclient.c:833719
void __cdecl _E1252_6()
{
  char *v0; // esi@1

  v0 = &Flags_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F070) --------------------------------------------------------  // acclient.c:833732
void __cdecl _E1255_6()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F0A0) --------------------------------------------------------  // acclient.c:833745
void __cdecl _E1258_5()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F0D0) --------------------------------------------------------  // acclient.c:833758
void __cdecl _E1261_4()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F100) --------------------------------------------------------  // acclient.c:833771
void __cdecl _E1264_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F130) --------------------------------------------------------  // acclient.c:833784
void __cdecl _E1267_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F160) --------------------------------------------------------  // acclient.c:833797
void __cdecl _E1270_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F190) --------------------------------------------------------  // acclient.c:833810
void __cdecl _E1273_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F1C0) --------------------------------------------------------  // acclient.c:833823
void __cdecl _E1276_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F1F0) --------------------------------------------------------  // acclient.c:833836
void __cdecl _E1279_4()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F220) --------------------------------------------------------  // acclient.c:833849
void __cdecl _E1282_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F250) --------------------------------------------------------  // acclient.c:833862
void __cdecl _E1285_4()
{
  char *v0; // esi@1

  v0 = &Scale_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F280) --------------------------------------------------------  // acclient.c:833875
void __cdecl _E1288_4()
{
  char *v0; // esi@1

  v0 = &ScaleX.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F2B0) --------------------------------------------------------  // acclient.c:833888
void __cdecl _E1291_3()
{
  char *v0; // esi@1

  v0 = &ScaleY.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F2E0) --------------------------------------------------------  // acclient.c:833901
void __cdecl _E1294_4()
{
  char *v0; // esi@1

  v0 = &Color.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F310) --------------------------------------------------------  // acclient.c:833914
void __cdecl _E1297_3()
{
  char *v0; // esi@1

  v0 = &Mass.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F340) --------------------------------------------------------  // acclient.c:833927
void __cdecl _E1300_3()
{
  char *v0; // esi@1

  v0 = &PFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F370) --------------------------------------------------------  // acclient.c:833940
void __cdecl _E1303_2()
{
  char *v0; // esi@1

  v0 = &PFlags_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F3A0) --------------------------------------------------------  // acclient.c:833953
void __cdecl _E1306_1()
{
  char *v0; // esi@1

  v0 = &PCType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F3D0) --------------------------------------------------------  // acclient.c:833966
void __cdecl _E1309_1()
{
  char *v0; // esi@1

  v0 = &PCType_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F400) --------------------------------------------------------  // acclient.c:833979
void __cdecl _E1312_1()
{
  char *v0; // esi@1

  v0 = &PCType_Physics.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F430) --------------------------------------------------------  // acclient.c:833992
void __cdecl _E1315()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F460) --------------------------------------------------------  // acclient.c:834005
void __cdecl _E1318()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F490) --------------------------------------------------------  // acclient.c:834018
void __cdecl _E1321()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F4C0) --------------------------------------------------------  // acclient.c:834031
void __cdecl _E1324()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F4F0) --------------------------------------------------------  // acclient.c:834044
void __cdecl _E1327()
{
  char *v0; // esi@1

  v0 = &PhysFlags.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F520) --------------------------------------------------------  // acclient.c:834057
void __cdecl _E1330()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F550) --------------------------------------------------------  // acclient.c:834070
void __cdecl _E1333()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F580) --------------------------------------------------------  // acclient.c:834083
void __cdecl _E1336()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F5B0) --------------------------------------------------------  // acclient.c:834096
void __cdecl _E1339()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F5E0) --------------------------------------------------------  // acclient.c:834109
void __cdecl _E1342()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F610) --------------------------------------------------------  // acclient.c:834122
void __cdecl _E1345()
{
  char *v0; // esi@1

  v0 = &Position_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F640) --------------------------------------------------------  // acclient.c:834135
void __cdecl _E1348()
{
  char *v0; // esi@1

  v0 = &PointList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F670) --------------------------------------------------------  // acclient.c:834148
void __cdecl _E1351()
{
  char *v0; // esi@1

  v0 = &Point_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F6A0) --------------------------------------------------------  // acclient.c:834161
void __cdecl _E1354()
{
  char *v0; // esi@1

  v0 = &DetailLevels.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F6D0) --------------------------------------------------------  // acclient.c:834174
void __cdecl _E1357()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F700) --------------------------------------------------------  // acclient.c:834187
void __cdecl _E1360()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F730) --------------------------------------------------------  // acclient.c:834200
void __cdecl _E1363()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F760) --------------------------------------------------------  // acclient.c:834213
void __cdecl _E1366()
{
  char *v0; // esi@1

  v0 = &FadeSpeed.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F790) --------------------------------------------------------  // acclient.c:834226
void __cdecl _E1369()
{
  char *v0; // esi@1

  v0 = &MaxOpacity.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F7C0) --------------------------------------------------------  // acclient.c:834239
void __cdecl _E1372()
{
  char *v0; // esi@1

  v0 = &Point_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F7F0) --------------------------------------------------------  // acclient.c:834252
void __cdecl _E1375()
{
  char *v0; // esi@1

  v0 = &PointAxisPos.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F820) --------------------------------------------------------  // acclient.c:834265
void __cdecl _E1378()
{
  char *v0; // esi@1

  v0 = &PointTexture.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F850) --------------------------------------------------------  // acclient.c:834278
void __cdecl _E1381()
{
  char *v0; // esi@1

  v0 = &PointSize.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F880) --------------------------------------------------------  // acclient.c:834291
void __cdecl _E1384()
{
  char *v0; // esi@1

  v0 = &UseOcclusion.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F8B0) --------------------------------------------------------  // acclient.c:834304
void __cdecl _E1387()
{
  char *v0; // esi@1

  v0 = &PreprocHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PreprocHeader.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F8E0) --------------------------------------------------------  // acclient.c:834317
void __cdecl _E1390()
{
  char *v0; // esi@1

  v0 = &MeshAppearanceType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshAppearanceType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F910) --------------------------------------------------------  // acclient.c:834330
void __cdecl _E1393()
{
  char *v0; // esi@1

  v0 = &Fragment.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Fragment.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F940) --------------------------------------------------------  // acclient.c:834343
void __cdecl _E1396()
{
  char *v0; // esi@1

  v0 = &FragmentType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F970) --------------------------------------------------------  // acclient.c:834356
void __cdecl _E1399()
{
  char *v0; // esi@1

  v0 = &FragmentType_LevelOfDetailModel.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_LevelOfDetailModel.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F9A0) --------------------------------------------------------  // acclient.c:834369
void __cdecl _E1402()
{
  char *v0; // esi@1

  v0 = &FragmentType_OccludeModel.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_OccludeModel.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072F9D0) --------------------------------------------------------  // acclient.c:834382
void __cdecl _E1405()
{
  char *v0; // esi@1

  v0 = &FragmentType_ShadowLODModel.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentType_ShadowLODModel.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FA00) --------------------------------------------------------  // acclient.c:834395
void __cdecl _E1408()
{
  char *v0; // esi@1

  v0 = &FragmentTopology.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentTopology.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FA30) --------------------------------------------------------  // acclient.c:834408
void __cdecl _E1411()
{
  char *v0; // esi@1

  v0 = &FragmentMOPP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentMOPP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FA60) --------------------------------------------------------  // acclient.c:834421
void __cdecl _E1414()
{
  char *v0; // esi@1

  v0 = &MaterialBatch.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialBatch.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FA90) --------------------------------------------------------  // acclient.c:834434
void __cdecl _E1417()
{
  char *v0; // esi@1

  v0 = &FragmentBatch.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FragmentBatch.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FAC0) --------------------------------------------------------  // acclient.c:834447
void __cdecl _E1420()
{
  char *v0; // esi@1

  v0 = &PrimitivesType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FAF0) --------------------------------------------------------  // acclient.c:834460
void __cdecl _E1423()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_PointList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_PointList.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FB20) --------------------------------------------------------  // acclient.c:834473
void __cdecl _E1426()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineList.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FB50) --------------------------------------------------------  // acclient.c:834486
void __cdecl _E1429()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_LineStrip.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_LineStrip.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FB80) --------------------------------------------------------  // acclient.c:834499
void __cdecl _E1432()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleList.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FBB0) --------------------------------------------------------  // acclient.c:834512
void __cdecl _E1435()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleStrip.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleStrip.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FBE0) --------------------------------------------------------  // acclient.c:834525
void __cdecl _E1438()
{
  char *v0; // esi@1

  v0 = &PrimitivesType_TriangleFan.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PrimitivesType_TriangleFan.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FC10) --------------------------------------------------------  // acclient.c:834538
void __cdecl _E1441()
{
  char *v0; // esi@1

  v0 = &Material_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FC40) --------------------------------------------------------  // acclient.c:834551
void __cdecl _E1444()
{
  char *v0; // esi@1

  v0 = &Vertices.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertices.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FC70) --------------------------------------------------------  // acclient.c:834564
void __cdecl _E1447()
{
  char *v0; // esi@1

  v0 = &Indices_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FCA0) --------------------------------------------------------  // acclient.c:834577
void __cdecl _E1450()
{
  char *v0; // esi@1

  v0 = &ExportMeshAppearanceType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExportMeshAppearanceType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FCD0) --------------------------------------------------------  // acclient.c:834590
void __cdecl _E1453()
{
  char *v0; // esi@1

  v0 = &MeshDegradeType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MeshDegradeType.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FD00) --------------------------------------------------------  // acclient.c:834603
void __cdecl _E1456()
{
  char *v0; // esi@1

  v0 = &DegradeLevel.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeLevel.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FD30) --------------------------------------------------------  // acclient.c:834616
void __cdecl _E1459()
{
  char *v0; // esi@1

  v0 = &NumDegradeLevels.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumDegradeLevels.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FD60) --------------------------------------------------------  // acclient.c:834629
void __cdecl _E1462()
{
  char *v0; // esi@1

  v0 = &CellMesh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellMesh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FD90) --------------------------------------------------------  // acclient.c:834642
void __cdecl _E1465()
{
  char *v0; // esi@1

  v0 = &MaterialArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FDC0) --------------------------------------------------------  // acclient.c:834655
void __cdecl _E1468()
{
  char *v0; // esi@1

  v0 = &Render.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FDF0) --------------------------------------------------------  // acclient.c:834668
void __cdecl _E1471()
{
  char *v0; // esi@1

  v0 = &RenderMesh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMesh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FE20) --------------------------------------------------------  // acclient.c:834681
void __cdecl _E1474()
{
  char *v0; // esi@1

  v0 = &RenderMeshVersion.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderMeshVersion.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FE50) --------------------------------------------------------  // acclient.c:834694
void __cdecl _E1477()
{
  char *v0; // esi@1

  v0 = &Sphere_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FE80) --------------------------------------------------------  // acclient.c:834707
void __cdecl _E1480()
{
  char *v0; // esi@1

  v0 = &DetailedBSP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailedBSP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FEB0) --------------------------------------------------------  // acclient.c:834720
void __cdecl _E1483()
{
  char *v0; // esi@1

  v0 = &PolygonArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PolygonArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FEE0) --------------------------------------------------------  // acclient.c:834733
void __cdecl _E1486()
{
  char *v0; // esi@1

  v0 = &BinaryPolygonArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryPolygonArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FF10) --------------------------------------------------------  // acclient.c:834746
void __cdecl _E1489()
{
  char *v0; // esi@1

  v0 = &Physics.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Physics.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FF40) --------------------------------------------------------  // acclient.c:834759
void __cdecl _E1492()
{
  char *v0; // esi@1

  v0 = &BSPTree.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSPTree.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FF70) --------------------------------------------------------  // acclient.c:834772
void __cdecl _E1495()
{
  char *v0; // esi@1

  v0 = &BinaryBSPTree.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryBSPTree.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FFA0) --------------------------------------------------------  // acclient.c:834785
void __cdecl _E1498()
{
  char *v0; // esi@1

  v0 = &Cell.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Cell.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072FFD0) --------------------------------------------------------  // acclient.c:834798
void __cdecl _E1501()
{
  char *v0; // esi@1

  v0 = &CellBSP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellBSP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730000) --------------------------------------------------------  // acclient.c:834811
void __cdecl _E1504()
{
  char *v0; // esi@1

  v0 = &Portals.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portals.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730030) --------------------------------------------------------  // acclient.c:834824
void __cdecl _E1507()
{
  char *v0; // esi@1

  v0 = &Portal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730060) --------------------------------------------------------  // acclient.c:834837
void __cdecl _E1510()
{
  char *v0; // esi@1

  v0 = &NonPortals.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortals.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730090) --------------------------------------------------------  // acclient.c:834850
void __cdecl _E1513()
{
  char *v0; // esi@1

  v0 = &NonPortal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NonPortal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007300C0) --------------------------------------------------------  // acclient.c:834863
void __cdecl _E1516()
{
  char *v0; // esi@1

  v0 = &Info.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Info.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007300F0) --------------------------------------------------------  // acclient.c:834876
void __cdecl _E1519()
{
  char *v0; // esi@1

  v0 = &CellVolumeInfo.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellVolumeInfo.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730120) --------------------------------------------------------  // acclient.c:834889
void __cdecl _E1522()
{
  char *v0; // esi@1

  v0 = &CellStructure.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellStructure.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730150) --------------------------------------------------------  // acclient.c:834902
void __cdecl _E1525()
{
  char *v0; // esi@1

  v0 = &CellRotation.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellRotation.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730180) --------------------------------------------------------  // acclient.c:834915
void __cdecl _E1528()
{
  char *v0; // esi@1

  v0 = &CellGridSize.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellGridSize.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007301B0) --------------------------------------------------------  // acclient.c:834928
void __cdecl _E1531()
{
  char *v0; // esi@1

  v0 = &CellNeverCull.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellNeverCull.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007301E0) --------------------------------------------------------  // acclient.c:834941
void __cdecl _E1534()
{
  char *v0; // esi@1

  v0 = &CellDrawSky.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellDrawSky.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730210) --------------------------------------------------------  // acclient.c:834954
void __cdecl _E1537()
{
  char *v0; // esi@1

  v0 = &DegradeArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730240) --------------------------------------------------------  // acclient.c:834967
void __cdecl _E1540()
{
  char *v0; // esi@1

  v0 = &OccludeMeshArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OccludeMeshArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730270) --------------------------------------------------------  // acclient.c:834980
void __cdecl _E1543()
{
  char *v0; // esi@1

  v0 = &DegradeMesh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DegradeMesh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007302A0) --------------------------------------------------------  // acclient.c:834993
void __cdecl _E1546()
{
  char *v0; // esi@1

  v0 = &BSP.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BSP.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007302D0) --------------------------------------------------------  // acclient.c:835006
void __cdecl _E1549()
{
  char *v0; // esi@1

  v0 = &BumpMap.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BumpMap.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730300) --------------------------------------------------------  // acclient.c:835019
void __cdecl _E1552()
{
  char *v0; // esi@1

  v0 = &UVSets.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVSets.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730330) --------------------------------------------------------  // acclient.c:835032
void __cdecl _E1555()
{
  char *v0; // esi@1

  v0 = &PhysicsMesh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMesh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730360) --------------------------------------------------------  // acclient.c:835045
void __cdecl _E1558()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterials.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterials.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730390) --------------------------------------------------------  // acclient.c:835058
void __cdecl _E1561()
{
  char *v0; // esi@1

  v0 = &PhysicsMaterialArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsMaterialArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007303C0) --------------------------------------------------------  // acclient.c:835071
void __cdecl _E1564()
{
  char *v0; // esi@1

  v0 = &PathMapMeshArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapMeshArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007303F0) --------------------------------------------------------  // acclient.c:835084
void __cdecl _E1567()
{
  char *v0; // esi@1

  v0 = &PathMapPolygonArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygonArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730420) --------------------------------------------------------  // acclient.c:835097
void __cdecl _E1570()
{
  char *v0; // esi@1

  v0 = &PathMapPolygon.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathMapPolygon.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730450) --------------------------------------------------------  // acclient.c:835110
void __cdecl _E1573()
{
  char *v0; // esi@1

  v0 = &VertexSetArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSetArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730480) --------------------------------------------------------  // acclient.c:835123
void __cdecl _E1576()
{
  char *v0; // esi@1

  v0 = &VertexSets.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSets.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007304B0) --------------------------------------------------------  // acclient.c:835136
void __cdecl _E1579()
{
  char *v0; // esi@1

  v0 = &VertexSet.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexSet.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007304E0) --------------------------------------------------------  // acclient.c:835149
void __cdecl _E1582()
{
  char *v0; // esi@1

  v0 = &Set.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Set.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730510) --------------------------------------------------------  // acclient.c:835162
void __cdecl _E1585()
{
  char *v0; // esi@1

  v0 = &ID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730540) --------------------------------------------------------  // acclient.c:835175
void __cdecl _E1588()
{
  char *v0; // esi@1

  v0 = &Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730570) --------------------------------------------------------  // acclient.c:835188
void __cdecl _E1591()
{
  char *v0; // esi@1

  v0 = &Indices_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007305A0) --------------------------------------------------------  // acclient.c:835201
void __cdecl _E1594()
{
  char *v0; // esi@1

  v0 = &MorphMeshArray.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMeshArray.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007305D0) --------------------------------------------------------  // acclient.c:835214
void __cdecl _E1597()
{
  char *v0; // esi@1

  v0 = &MorphMesh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphMesh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730600) --------------------------------------------------------  // acclient.c:835227
void __cdecl _E1600()
{
  char *v0; // esi@1

  v0 = &MorphTargets.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MorphTargets.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730630) --------------------------------------------------------  // acclient.c:835240
void __cdecl _E1603()
{
  char *v0; // esi@1

  v0 = &Target.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Target.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730660) --------------------------------------------------------  // acclient.c:835253
void __cdecl _E1606()
{
  char *v0; // esi@1

  v0 = &Name_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Name_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730690) --------------------------------------------------------  // acclient.c:835266
void __cdecl sub_730690()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007306C0) --------------------------------------------------------  // acclient.c:835279
void __cdecl sub_7306C0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007306F0) --------------------------------------------------------  // acclient.c:835292
void __cdecl sub_7306F0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730720) --------------------------------------------------------  // acclient.c:835305
void __cdecl sub_730720()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730750) --------------------------------------------------------  // acclient.c:835318
void __cdecl sub_730750()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730780) --------------------------------------------------------  // acclient.c:835331
void __cdecl sub_730780()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007307B0) --------------------------------------------------------  // acclient.c:835344
void __cdecl sub_7307B0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007307E0) --------------------------------------------------------  // acclient.c:835357
void __cdecl sub_7307E0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730810) --------------------------------------------------------  // acclient.c:835370
void __cdecl _E124_95()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730840) --------------------------------------------------------  // acclient.c:835383
void __cdecl _E127_84()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730870) --------------------------------------------------------  // acclient.c:835396
void __cdecl _E130_76()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007308A0) --------------------------------------------------------  // acclient.c:835409
void __cdecl _E133_69()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007308D0) --------------------------------------------------------  // acclient.c:835422
void __cdecl _E136_53()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730900) --------------------------------------------------------  // acclient.c:835435
void __cdecl _E139_54()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730930) --------------------------------------------------------  // acclient.c:835448
void __cdecl _E142_51()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730960) --------------------------------------------------------  // acclient.c:835461
void __cdecl _E145_53()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730990) --------------------------------------------------------  // acclient.c:835474
void __cdecl _E148_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_5;
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

//----- (007309D0) --------------------------------------------------------  // acclient.c:835499
void __cdecl _E151_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_5;
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

//----- (00730A10) --------------------------------------------------------  // acclient.c:835524
void __cdecl _E154_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_5;
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

//----- (00730A50) --------------------------------------------------------  // acclient.c:835549
void __cdecl _E157_48()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_5;
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

//----- (00730A90) --------------------------------------------------------  // acclient.c:835574
void __cdecl _E160_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_5;
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

//----- (00730AD0) --------------------------------------------------------  // acclient.c:835599
void __cdecl _E163_44()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_11;
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

//----- (00730B10) --------------------------------------------------------  // acclient.c:835624
void __cdecl _E166_46()
{
  char *v0; // esi@1

  v0 = &waveform_None_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730B40) --------------------------------------------------------  // acclient.c:835637
void __cdecl _E169_45()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730B70) --------------------------------------------------------  // acclient.c:835650
void __cdecl _E172_43()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730BA0) --------------------------------------------------------  // acclient.c:835663
void __cdecl _E175_40()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730BD0) --------------------------------------------------------  // acclient.c:835676
void __cdecl _E178_40()
{
  char *v0; // esi@1

  v0 = &waveform_Square_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730C00) --------------------------------------------------------  // acclient.c:835689
void __cdecl _E181_40()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730C30) --------------------------------------------------------  // acclient.c:835702
void __cdecl _E184_38()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730C60) --------------------------------------------------------  // acclient.c:835715
void __cdecl _E187_37()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00730C90) --------------------------------------------------------  // acclient.c:835728
void __cdecl _E190_38()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

