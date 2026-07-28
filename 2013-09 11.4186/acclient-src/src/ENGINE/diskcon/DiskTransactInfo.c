/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DiskTransactInfo
   Object     : ENGINE\diskcon\DiskTransactInfo.obj
   Functions  : 23
   Addresses  : 006761C0 - 00714ED0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006761C0) --------------------------------------------------------  // acclient.c:652703
void __thiscall DiskTransactInfo::DiskTransactInfo(DiskTransactInfo *this)
{
  this->vfptr = (DiskTransactInfoVtbl *)&DiskTransactInfo::vftable;
  this->m_eTransactType = 0;
  this->m_nMagicNumber = 19536;
}
// 7FDC50: using guessed type void (__thiscall *DiskTransactInfo::vftable)(DiskTransactInfo *this, struct Archive *);

//----- (006761E0) --------------------------------------------------------  // acclient.c:652712
void __thiscall MergeNodesTransactInfo::MergeNodesTransactInfo(MergeNodesTransactInfo *this)
{
  this->m_eTransactType = 4;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&MergeNodesTransactInfo::vftable;
  this->m_nNodeOffset = 0;
  this->m_nLeftOffset = 0;
  this->m_nRightOffset = 0;
  this->m_nIndex = 0;
  this->m_nNodeEntries = 0;
}
// 7FDCA0: using guessed type void (__thiscall *MergeNodesTransactInfo::vftable)(MergeNodesTransactInfo *this, struct Archive *);

//----- (00676210) --------------------------------------------------------  // acclient.c:652726
void __thiscall SplitNodeTransactInfo::SplitNodeTransactInfo(SplitNodeTransactInfo *this)
{
  this->m_eTransactType = 6;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&SplitNodeTransactInfo::vftable;
  this->m_nParentOffset = 0;
  this->m_nParentEntries = 0;
  this->m_nSplitIndex = 0;
  this->m_nFirstFreeBlock = 0;
}
// 7FDCF0: using guessed type void (__thiscall *SplitNodeTransactInfo::vftable)(SplitNodeTransactInfo *this, struct Archive *);

//----- (00676240) --------------------------------------------------------  // acclient.c:652739
void __thiscall LRUDeleteTransactInfo::LRUDeleteTransactInfo(LRUDeleteTransactInfo *this)
{
  this->m_eTransactType = 9;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&LRUDeleteTransactInfo::vftable;
  this->m_nBlockOffset = 0;
  this->m_nOldOffset = 0;
  this->m_nYoungOffset = 0;
}
// 7FDD40: using guessed type void (__thiscall *LRUDeleteTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *);

//----- (00676270) --------------------------------------------------------  // acclient.c:652751
void __thiscall DiskTransactInfo::Serialize(DiskTransactInfo *this, Archive *io_rcArchive)
{
  DiskTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
}

//----- (006762B0) --------------------------------------------------------  // acclient.c:652769
void __thiscall AddObjectTransactInfo::Serialize(AddObjectTransactInfo *this, Archive *io_rcArchive)
{
  AddObjectTransactInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  void *v4; // edi@5
  unsigned int v5; // eax@5
  const void *v6; // esi@7
  unsigned int v7; // eax@10
  unsigned int v8; // eax@14

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  v4 = &v2->m_entry;
  Archive::CheckAlignment(io_rcArchive, 0x18u);
  v5 = Archive::GetBytes(io_rcArchive, 0x18u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
    {
      v6 = &v2->m_entry;
      v4 = (void *)v5;
    }
    else
    {
      v6 = (const void *)v5;
    }
    qmemcpy(v4, v6, 0x18u);
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v7 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v7 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_nFirstFreeBlock;
    else
      v2->m_nFirstFreeBlock = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v8 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v8 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v8 = v2->m_nNodeEntries;
    else
      v2->m_nNodeEntries = *(_DWORD *)v8;
  }
}

//----- (00676370) --------------------------------------------------------  // acclient.c:652826
void __thiscall DeleteLeafTransactInfo::DeleteLeafTransactInfo(DeleteLeafTransactInfo *this)
{
  this->m_eTransactType = 2;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&DeleteLeafTransactInfo::vftable;
  this->m_cObjectDID.id = stru_8F76E4.id;
  this->m_nNodeOffset = 0;
  this->m_nIndex = 0;
}
// 7FDD90: using guessed type void (__thiscall *DeleteLeafTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *);

//----- (006763A0) --------------------------------------------------------  // acclient.c:652838
void __thiscall DeleteInternalTransactInfo::DeleteInternalTransactInfo(DeleteInternalTransactInfo *this)
{
  this->m_eTransactType = 3;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&DeleteInternalTransactInfo::vftable;
  this->m_cTargetDID.id = stru_8F76E4.id;
  this->m_cDonorDID.id = stru_8F76E4.id;
  this->m_nTargetOffset = 0;
  this->m_nDonorOffset = 0;
  this->m_nTargetIndex = 0;
  this->m_nDonorIndex = 0;
}
// 7FDDE0: using guessed type void (__thiscall *DeleteInternalTransactInfo::vftable)(DeleteInternalTransactInfo *this, struct Archive *);

//----- (006763E0) --------------------------------------------------------  // acclient.c:652853
void __thiscall DeleteInternalTransactInfo::Serialize(DeleteInternalTransactInfo *this, Archive *io_rcArchive)
{
  DeleteInternalTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13
  unsigned int v7; // eax@17
  unsigned int v8; // eax@21
  unsigned int v9; // eax@25

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_cTargetDID.id;
    else
      v2->m_cTargetDID.id = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_cDonorDID.id;
    else
      v2->m_cDonorDID.id = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v6 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v6 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_nTargetOffset;
    else
      v2->m_nTargetOffset = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v7 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v7 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_nDonorOffset;
    else
      v2->m_nDonorOffset = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v8 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v8 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v8 = v2->m_nTargetIndex;
    else
      v2->m_nTargetIndex = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v9 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v9 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v9 = v2->m_nDonorIndex;
    else
      v2->m_nDonorIndex = *(_DWORD *)v9;
  }
}

//----- (00676510) --------------------------------------------------------  // acclient.c:652931
void __thiscall MergeNodesTransactInfo::Serialize(MergeNodesTransactInfo *this, Archive *io_rcArchive)
{
  MergeNodesTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13
  unsigned int v7; // eax@17
  unsigned int v8; // eax@21

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_nNodeOffset;
    else
      v2->m_nNodeOffset = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_nLeftOffset;
    else
      v2->m_nLeftOffset = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v6 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v6 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_nRightOffset;
    else
      v2->m_nRightOffset = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v7 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v7 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_nIndex;
    else
      v2->m_nIndex = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v8 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v8 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v8 = v2->m_nNodeEntries;
    else
      v2->m_nNodeEntries = *(_DWORD *)v8;
  }
}

//----- (00676610) --------------------------------------------------------  // acclient.c:652999
void __thiscall UpdateObjectTransactInfo::Serialize(UpdateObjectTransactInfo *this, Archive *io_rcArchive)
{
  UpdateObjectTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  AddObjectTransactInfo::Serialize((AddObjectTransactInfo *)&this->vfptr, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nEntryIndex;
    else
      v2->m_nEntryIndex = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_nOldOffset;
    else
      v2->m_nOldOffset = *(_DWORD *)v4;
  }
}

//----- (00676680) --------------------------------------------------------  // acclient.c:653028
void __thiscall SplitNodeTransactInfo::Serialize(SplitNodeTransactInfo *this, Archive *io_rcArchive)
{
  SplitNodeTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13
  unsigned int v7; // eax@17

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_nParentOffset;
    else
      v2->m_nParentOffset = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_nParentEntries;
    else
      v2->m_nParentEntries = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v6 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v6 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_nSplitIndex;
    else
      v2->m_nSplitIndex = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v7 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v7 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_nFirstFreeBlock;
    else
      v2->m_nFirstFreeBlock = *(_DWORD *)v7;
  }
}

//----- (00676760) --------------------------------------------------------  // acclient.c:653086
void __thiscall RotateEntryTransactInfo::RotateEntryTransactInfo(RotateEntryTransactInfo *this)
{
  this->m_eTransactType = 7;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&RotateEntryTransactInfo::vftable;
  this->m_nParentOffset = 0;
  this->m_cEntryDID.id = stru_8F76E4.id;
  this->m_nIndex = 0;
  this->m_nNodeEntryCount = 0;
  this->m_nSiblingEntryCount = 0;
  this->m_bLeftSibling = 0;
}
// 7FDE30: using guessed type void (__thiscall *RotateEntryTransactInfo::vftable)(RotateEntryTransactInfo *this, struct Archive *);

//----- (006767A0) --------------------------------------------------------  // acclient.c:653101
void __thiscall RotateEntryTransactInfo::Serialize(RotateEntryTransactInfo *this, Archive *io_rcArchive)
{
  RotateEntryTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13
  unsigned int v7; // eax@17
  unsigned int v8; // eax@21

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_nParentOffset;
    else
      v2->m_nParentOffset = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_cEntryDID.id;
    else
      v2->m_cEntryDID.id = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v6 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v6 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_nIndex;
    else
      v2->m_nIndex = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v7 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v7 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_nNodeEntryCount;
    else
      v2->m_nNodeEntryCount = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v8 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v8 )
  {
    if ( io_rcArchive->m_flags & 1 )
    {
      *(_DWORD *)v8 = v2->m_nSiblingEntryCount;
      Serializer::SerializeObject(&v2->m_bLeftSibling, io_rcArchive);
      return;
    }
    v2->m_nSiblingEntryCount = *(_DWORD *)v8;
  }
  Serializer::SerializeObject(&v2->m_bLeftSibling, io_rcArchive);
}

//----- (006768C0) --------------------------------------------------------  // acclient.c:653173
void __thiscall LRUExpandTransactInfo::LRUExpandTransactInfo(LRUExpandTransactInfo *this)
{
  this->m_eTransactType = 8;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&LRUExpandTransactInfo::vftable;
  this->m_nYoungOffset = 0;
  this->m_nFirstFreeBlock = 0;
  this->m_cTargetDID.id = stru_8F76E4.id;
}
// 7FDE80: using guessed type void (__thiscall *LRUExpandTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *);

//----- (006768F0) --------------------------------------------------------  // acclient.c:653185
void __thiscall LRUDeleteTransactInfo::Serialize(LRUDeleteTransactInfo *this, Archive *io_rcArchive)
{
  LRUDeleteTransactInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13

  v2 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v3 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_nMagicNumber;
    else
      v2->m_nMagicNumber = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_nBlockOffset;
    else
      v2->m_nBlockOffset = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_nOldOffset;
    else
      v2->m_nOldOffset = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_rcArchive, 4u);
  v6 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v6 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_nYoungOffset;
    else
      v2->m_nYoungOffset = *(_DWORD *)v6;
  }
}

//----- (006769B0) --------------------------------------------------------  // acclient.c:653233
void __thiscall AddObjectTransactInfo::AddObjectTransactInfo(AddObjectTransactInfo *this)
{
  unsigned int v1; // edx@1

  this->m_eTransactType = 1;
  this->m_nMagicNumber = 19536;
  this->vfptr = (DiskTransactInfoVtbl *)&AddObjectTransactInfo::vftable;
  v1 = stru_8F76E4.id;
  *(_DWORD *)&this->m_entry &= 0xFFFF0000;
  *((_WORD *)&this->m_entry + 1) = 0;
  this->m_entry.GID_.id = v1;
  this->m_entry.Offset_ = 0;
  this->m_entry.size_ = 0;
  this->m_entry.date_ = 0;
  this->m_entry.iter_ = 0;
  this->m_nFirstFreeBlock = 0;
  this->m_nNodeEntries = 0;
}
// 7FDED0: using guessed type void (__thiscall *AddObjectTransactInfo::vftable)(AddObjectTransactInfo *this, struct Archive *);

//----- (006769F0) --------------------------------------------------------  // acclient.c:653254
void __thiscall UpdateObjectTransactInfo::UpdateObjectTransactInfo(UpdateObjectTransactInfo *this)
{
  unsigned int v1; // edx@1

  this->m_eTransactType = 1;
  this->vfptr = (DiskTransactInfoVtbl *)&AddObjectTransactInfo::vftable;
  this->m_nMagicNumber = 19536;
  v1 = stru_8F76E4.id;
  *(_DWORD *)&this->m_entry &= 0xFFFF0000;
  *((_WORD *)&this->m_entry + 1) = 0;
  this->m_entry.GID_.id = v1;
  this->m_entry.Offset_ = 0;
  this->m_entry.size_ = 0;
  this->m_entry.date_ = 0;
  this->m_entry.iter_ = 0;
  this->m_nFirstFreeBlock = 0;
  this->m_nNodeEntries = 0;
  this->vfptr = (DiskTransactInfoVtbl *)&UpdateObjectTransactInfo::vftable;
  this->m_nEntryIndex = 0;
  this->m_nOldOffset = 0;
  this->m_eTransactType = 5;
}
// 7FDED0: using guessed type void (__thiscall *AddObjectTransactInfo::vftable)(AddObjectTransactInfo *this, struct Archive *);
// 7FDF20: using guessed type void (__thiscall *UpdateObjectTransactInfo::vftable)(UpdateObjectTransactInfo *this, struct Archive *);

//----- (00676A50) --------------------------------------------------------  // acclient.c:653280
void __cdecl DiskTransactInfo::CreateTransactInfo(DiskTransactType i_eType)
{
  void *v1; // eax@2
  AddObjectTransactInfo *v2; // eax@4
  DeleteLeafTransactInfo *v3; // eax@6
  DeleteInternalTransactInfo *v4; // eax@8
  MergeNodesTransactInfo *v5; // eax@10
  UpdateObjectTransactInfo *v6; // eax@12
  SplitNodeTransactInfo *v7; // eax@14
  RotateEntryTransactInfo *v8; // eax@16
  LRUExpandTransactInfo *v9; // eax@18
  LRUDeleteTransactInfo *v10; // eax@20

  switch ( i_eType )
  {
    case 0:
      v1 = operator new(0xCu);
      if ( v1 )
      {
        *(_DWORD *)v1 = &DiskTransactInfo::vftable;
        *((_DWORD *)v1 + 1) = 0;
        *((_DWORD *)v1 + 2) = 19536;
      }
      break;
    case 1:
      v2 = (AddObjectTransactInfo *)operator new(0x2Cu);
      if ( v2 )
        AddObjectTransactInfo::AddObjectTransactInfo(v2);
      break;
    case 2:
      v3 = (DeleteLeafTransactInfo *)operator new(0x18u);
      if ( v3 )
        DeleteLeafTransactInfo::DeleteLeafTransactInfo(v3);
      break;
    case 3:
      v4 = (DeleteInternalTransactInfo *)operator new(0x24u);
      if ( v4 )
        DeleteInternalTransactInfo::DeleteInternalTransactInfo(v4);
      break;
    case 4:
      v5 = (MergeNodesTransactInfo *)operator new(0x20u);
      if ( v5 )
        MergeNodesTransactInfo::MergeNodesTransactInfo(v5);
      break;
    case 5:
      v6 = (UpdateObjectTransactInfo *)operator new(0x34u);
      if ( v6 )
        UpdateObjectTransactInfo::UpdateObjectTransactInfo(v6);
      break;
    case 6:
      v7 = (SplitNodeTransactInfo *)operator new(0x1Cu);
      if ( v7 )
        SplitNodeTransactInfo::SplitNodeTransactInfo(v7);
      break;
    case 7:
      v8 = (RotateEntryTransactInfo *)operator new(0x24u);
      if ( v8 )
        RotateEntryTransactInfo::RotateEntryTransactInfo(v8);
      break;
    case 8:
      v9 = (LRUExpandTransactInfo *)operator new(0x18u);
      if ( v9 )
        LRUExpandTransactInfo::LRUExpandTransactInfo(v9);
      break;
    case 9:
      v10 = (LRUDeleteTransactInfo *)operator new(0x18u);
      if ( v10 )
        LRUDeleteTransactInfo::LRUDeleteTransactInfo(v10);
      break;
    default:
      return;
  }
}
// 7FDC50: using guessed type void (__thiscall *DiskTransactInfo::vftable)(DiskTransactInfo *this, struct Archive *);

//----- (00714EA0) --------------------------------------------------------  // acclient.c:807805
int sub_714EA0()
{
  return atexit(nullsub_88);
}

//----- (00714EB0) --------------------------------------------------------  // acclient.c:807811
int _E76_90()
{
  return atexit(nullsub_89);
}

//----- (00714EC0) --------------------------------------------------------  // acclient.c:807817
int _E79_85()
{
  return atexit(_E80_82);
}

//----- (00714ED0) --------------------------------------------------------  // acclient.c:807823
int sub_714ED0()
{
  return atexit(nullsub_91);
}

