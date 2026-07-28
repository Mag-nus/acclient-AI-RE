/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DiskCon
   Object     : ENGINE\diskcon\DiskCon.obj
   Functions  : 42
   Addresses  : 00670330 - 0077EE90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00670330) --------------------------------------------------------  // acclient.c:646913
void __thiscall DiskFileInfo_t::ClearData(DiskFileInfo_t *this)
{
  this->iBlockSize_ = 0;
  this->fileSize_ = 0;
  this->data_set_lm = 0;
  this->data_subset_lm = 0;
  this->firstFree_ = 0;
  this->finalFree_ = 0;
  this->iFreeBlocks_ = 0;
  this->btreeRoot_ = 0;
  this->young_lru_lm = 0;
  this->old_lru_lm = 0;
  this->use_lru_fm = 0;
  this->magic_ = 21570;
  this->master_map_id_m.id = stru_8F76B4.id;
  this->eng_pack_vnum = -1;
  this->game_pack_vnum = -1;
  DatIDStamp::Clear(&this->id_vnum);
}

//----- (00670380) --------------------------------------------------------  // acclient.c:646934
DatIDStamp *__stdcall DiskConBase::GetDatIDStamp(DatIDStamp *result)
{
  DatIDStamp::DatIDStamp(result);
  return result;
}

//----- (006703A0) --------------------------------------------------------  // acclient.c:646941
DiskConBase *__thiscall DiskConBase::vector_deleting_destructor(DiskConBase *this, unsigned int a2)
{
  DiskConBase *v2; // esi@1

  v2 = this;
  this->vfptr = (DiskConBaseVtbl *)&DiskConBase::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7FDB48: using guessed type int (__thiscall *DiskConBase::vftable)(void *, char);

//----- (006703C0) --------------------------------------------------------  // acclient.c:646954
bool __thiscall DiskController::Close(DiskController *this)
{
  DiskController *v1; // esi@1
  bool result; // al@1
  bool v3; // bl@4

  v1 = this;
  result = 0;
  if ( this->initialized_fm )
  {
    if ( !this->read_only_fm )
      BTree::SaveDataToFile(&this->did_tree_m);
    v3 = CLBlockAllocator::Close_Data_File(&v1->block_man_m) == 0;
    BTree::~BTree(&v1->did_tree_m);
    result = v3;
    v1->initialized_fm = 0;
  }
  return result;
}

//----- (00670400) --------------------------------------------------------  // acclient.c:646975
char __thiscall DiskController::GetMembers(DiskController *this, SmartArray<BTEntry,1> *o_aMembers)
{
  return BTree::Get_Id_List(&this->did_tree_m, o_aMembers);
}

//----- (00670410) --------------------------------------------------------  // acclient.c:646981
void __thiscall DiskController::SetDatIDStamp(DiskController *this, DatIDStamp *stamp)
{
  DiskController *v2; // esi@1

  v2 = this;
  if ( !this->read_only_fm )
  {
    DatIDStamp::DatIDStamp(&this->file_info_m.id_vnum, stamp);
    if ( v2->initialized_fm )
      BTree::SaveDataToFile(&v2->did_tree_m);
  }
}

//----- (00670440) --------------------------------------------------------  // acclient.c:646995
void __thiscall DiskFileInfo_t::DiskFileInfo_t(DiskFileInfo_t *this)
{
  DiskFileInfo_t *v1; // esi@1
  DatIDStamp *v2; // edi@1

  v1 = this;
  v2 = &this->id_vnum;
  DatIDStamp::DatIDStamp(&this->id_vnum);
  v1->iBlockSize_ = 0;
  v1->fileSize_ = 0;
  v1->data_set_lm = 0;
  v1->data_subset_lm = 0;
  v1->firstFree_ = 0;
  v1->finalFree_ = 0;
  v1->iFreeBlocks_ = 0;
  v1->btreeRoot_ = 0;
  v1->young_lru_lm = 0;
  v1->old_lru_lm = 0;
  v1->use_lru_fm = 0;
  v1->magic_ = 21570;
  v1->master_map_id_m.id = stru_8F76B4.id;
  v1->eng_pack_vnum = -1;
  v1->game_pack_vnum = -1;
  DatIDStamp::Clear(v2);
}

//----- (006704A0) --------------------------------------------------------  // acclient.c:647022
void __thiscall Cache_Pack_t::UpdatePackedSize(Cache_Pack_t *this, SmartBuffer *i_buff)
{
  int v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@2
  int v6; // eax@2
  SmartBuffer result; // [sp+Ch] [bp-Ch]@2

  v2 = (int)&this->m_buff;
  v3 = SmartBuffer::GetBuffer(&this->m_buff) + 4;
  if ( SmartBuffer::GetBuffer(i_buff) == v3 )
  {
    v4 = SmartBuffer::GetSize(i_buff);
    SmartBuffer::ReconfigureAllocation((SmartBuffer *)v2, v4 + 4, 1u);
    v5 = SmartBuffer::GetSize(i_buff);
    v6 = (int)SmartBuffer::MakeWindow((SmartBuffer *)v2, &result, 0, v5 + 4);
    SmartBuffer::operator=(v2, v6);
    SmartBuffer::ReleaseMasterBuffer(&result);
  }
}

//----- (00670510) --------------------------------------------------------  // acclient.c:647045
bool __stdcall DiskConBase::SaveData(IDClass<_tagDataID,32,0> id, Cache_Pack_t *buffer, int idIter)
{
  return 0;
}

//----- (00670520) --------------------------------------------------------  // acclient.c:647051
IDClass<_tagDataID,32,0> *__stdcall DiskConBase::GetMasterMapDID(IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = stru_8F76B4.id;
  return v2;
}

//----- (00670530) --------------------------------------------------------  // acclient.c:647061
IDClass<_tagDataID,32,0> *__stdcall DiskConBase::SetMasterMapDID(IDClass<_tagDataID,32,0> *result, IDClass<_tagDataID,32,0> map_id)
{
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v3 = result;
  result->id = stru_8F76B4.id;
  return v3;
}

//----- (00670540) --------------------------------------------------------  // acclient.c:647071
int __thiscall DiskController::SaveData(DiskController *this, IDClass<_tagDataID,32,0> id, Cache_Pack_t *buffer, int idIteration)
{
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.GID_.id = id.id;
  ent = (BTEntry)(buffer->m_iVersion << 16);
  ent.iter_ = idIteration;
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[1].HowmuchFreeSpace)(&ent, buffer, 1);
}

//----- (00670590) --------------------------------------------------------  // acclient.c:647085
int __thiscall DiskController::SaveAndCompressData(DiskController *this, IDClass<_tagDataID,32,0> id, Cache_Pack_t *buffer, int idIteration)
{
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.GID_.id = id.id;
  ent = (BTEntry)(buffer->m_iVersion << 16);
  ent.iter_ = idIteration;
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[1].HowmuchFreeSpace)(&ent, buffer, 2);
}

//----- (006705E0) --------------------------------------------------------  // acclient.c:647099
int __thiscall DiskController::SavePreCompressedData(DiskController *this, IDClass<_tagDataID,32,0> id, Cache_Pack_t *buffer, int idIteration)
{
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.GID_.id = id.id;
  ent = (BTEntry)(buffer->m_iVersion << 16);
  ent.iter_ = idIteration;
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[1].HowmuchFreeSpace)(&ent, buffer, 3);
}

//----- (00670630) --------------------------------------------------------  // acclient.c:647113
char __stdcall DiskController::AttemptToCompress(Cache_Pack_t *i_cpUncompressed, Cache_Pack_t *o_cpCompressed)
{
  SmartBuffer *v3; // edi@1
  char v4; // al@3
  unsigned int v5; // eax@5
  Cache_Pack_t *v6; // ebp@7
  SmartBuffer *v7; // esi@7
  unsigned int v8; // ebx@7
  unsigned int v9; // eax@8
  unsigned int v10; // eax@11
  unsigned int v11; // ST0C_4@13
  unsigned int v12; // eax@13
  unsigned int v13; // eax@15
  SmartBuffer result; // [sp+4h] [bp-18h]@17
  SmartBuffer wrap; // [sp+10h] [bp-Ch]@17

  v3 = &i_cpUncompressed->m_buff;
  if ( SmartBuffer::GetSize(&i_cpUncompressed->m_buff) > 4 && SmartBuffer::GetSize(v3) - 4 > 0x10 )
  {
    if ( SmartBuffer::GetSize(v3) <= 4 )
      v5 = 0;
    else
      v5 = SmartBuffer::GetSize(v3) - 4;
    v6 = o_cpCompressed;
    v7 = &o_cpCompressed->m_buff;
    SmartBuffer::ReconfigureAllocation(&o_cpCompressed->m_buff, v5 + 4, 1u);
    SmartBuffer::GetSize(v7);
    SmartBuffer::ReconfigureAllocation(v7, 4u, 1u);
    v8 = SmartBuffer::GetBuffer(v7) + 4;
    if ( SmartBuffer::GetSize(v7) <= 4 )
      v9 = 0;
    else
      v9 = SmartBuffer::GetSize(v7) - 4;
    i_cpUncompressed = (Cache_Pack_t *)(v9 - 4);
    if ( SmartBuffer::GetSize(v3) <= 4 )
      v10 = 0;
    else
      v10 = SmartBuffer::GetSize(v3) - 4;
    v11 = v10;
    v12 = SmartBuffer::GetBuffer(v3);
    if ( compress2(v8 + 4, &i_cpUncompressed, v12 + 4, v11, 9) )
    {
      v4 = 0;
    }
    else
    {
      if ( SmartBuffer::GetSize(v3) <= 4 )
        v13 = 0;
      else
        v13 = SmartBuffer::GetSize(v3) - 4;
      *(_DWORD *)v8 = v13;
      SmartBuffer::ReconfigureAllocation(v7, 4u, 1u);
      SmartBuffer::MakeWindow(v7, &result, 4u);
      SmartBuffer::MakeWindow(&result, &wrap, 0, (unsigned int)&i_cpUncompressed->m_iVersion);
      SmartBuffer::ReleaseMasterBuffer(&result);
      Cache_Pack_t::UpdatePackedSize(v6, &wrap);
      SmartBuffer::ReleaseMasterBuffer(&wrap);
      v4 = 1;
    }
  }
  else
  {
    v4 = 0;
  }
  return v4;
}
// 6B9B10: using guessed type int __cdecl compress2(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00670790) --------------------------------------------------------  // acclient.c:647182
char __thiscall DiskController::CheckRoom(DiskController *this, int size_l)
{
  DiskController *v2; // esi@1
  int v3; // edi@1

  v2 = this;
  v3 = size_l / (this->file_info_m.iBlockSize_ - 4) + 51;
  if ( this->file_info_m.iFreeBlocks_ <= v3 )
  {
    do
    {
      if ( v2->expandable_fm )
        CLBlockAllocator::ExpandFile(&v2->block_man_m, 0x100000);
      else
        BTree::Try_Delete_Oldest(&v2->did_tree_m);
    }
    while ( v2->file_info_m.iFreeBlocks_ <= v3 );
  }
  return 1;
}

//----- (006707E0) --------------------------------------------------------  // acclient.c:647204
int __thiscall DiskController::GetDatestamp(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  char v2; // al@1
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.GID_.id = stru_8F76B4.id;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  v2 = ((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))this->vfptr[1].DeleteDataByMask)(
         did.id,
         &g_DummyCachePack,
         &ent,
         2);
  return v2 != 0 ? ent.date_ : 0;
}

//----- (00670830) --------------------------------------------------------  // acclient.c:647224
unsigned int __thiscall DiskController::GetVersion(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  DiskConBaseVtbl *v2; // edx@1
  unsigned int result; // eax@2
  BTEntry ent; // [sp+10h] [bp-18h]@1

  v2 = this->vfptr;
  ent.GID_.id = stru_8F76B4.id;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))v2[1].DeleteDataByMask)(
                          did.id,
                          &g_DummyCachePack,
                          &ent,
                          2) )
    result = *(unsigned int *)&ent >> 16;
  else
    result = 0;
  return result;
}

//----- (00670890) --------------------------------------------------------  // acclient.c:647249
bool __thiscall DiskController::GetIsCompressed(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  DiskConBaseVtbl *v2; // edx@1
  bool result; // al@2
  BTEntry ent; // [sp+10h] [bp-18h]@1

  v2 = this->vfptr;
  ent.GID_.id = stru_8F76B4.id;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))v2[1].DeleteDataByMask)(
                          did.id,
                          &g_DummyCachePack,
                          &ent,
                          2) )
    result = *(_BYTE *)&ent & 1;
  else
    result = 0;
  return result;
}

//----- (006708F0) --------------------------------------------------------  // acclient.c:647274
int __thiscall DiskController::GetIteration(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  char v2; // al@1
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.GID_.id = stru_8F76B4.id;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  v2 = ((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))this->vfptr[1].DeleteDataByMask)(
         did.id,
         &g_DummyCachePack,
         &ent,
         2);
  return v2 != 0 ? ent.iter_ : 0;
}

//----- (00670940) --------------------------------------------------------  // acclient.c:647294
unsigned int __thiscall DiskController::GetDataSize(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  unsigned int result; // eax@2
  BTEntry ent; // [sp+4h] [bp-18h]@1

  ent.GID_.id = stru_8F76B4.id;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))this->vfptr[1].DeleteDataByMask)(
                          did.id,
                          &g_DummyCachePack,
                          &ent,
                          2) )
    result = ent.size_;
  else
    result = -1;
  return result;
}

//----- (00670990) --------------------------------------------------------  // acclient.c:647317
unsigned int __thiscall DiskController::GetUncompressedDataSize(DiskController *this, IDClass<_tagDataID,32,0> did)
{
  DiskController *v2; // esi@1
  DiskConBaseVtbl *v3; // edx@1
  int v5; // esi@5
  Cache_Pack_t bufHeader; // [sp+18h] [bp-2Ch]@4
  BTEntry ent; // [sp+2Ch] [bp-18h]@1

  ent.GID_.id = stru_8F76B4.id;
  v2 = this;
  v3 = this->vfptr;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, _UNKNOWN *, BTEntry *, signed int))v3[1].DeleteDataByMask)(
                          did.id,
                          &g_DummyCachePack,
                          &ent,
                          2) )
  {
    if ( !(*(_BYTE *)&ent & 1) )
      return ent.size_;
    bufHeader.m_dwOffset = 0;
    bufHeader.m_iVersion = 0;
    SmartBuffer::SmartBuffer(&bufHeader.m_buff);
    SmartBuffer::ReconfigureAllocation(&bufHeader.m_buff, 8u, 1u);
    SmartBuffer::GetSize(&bufHeader.m_buff);
    if ( (unsigned __int8)((int (__thiscall *)(DiskController *, unsigned int, Cache_Pack_t *, BTEntry *, signed int))v2->vfptr[1].DeleteDataByMask)(
                            v2,
                            did.id,
                            &bufHeader,
                            &ent,
                            5) )
    {
      SmartBuffer::ReconfigureAllocation(&bufHeader.m_buff, 4u, 1u);
      v5 = *(_DWORD *)(SmartBuffer::GetBuffer(&bufHeader.m_buff) + 4);
      SmartBuffer::ReleaseMasterBuffer(&bufHeader.m_buff);
      SmartBuffer::ReleaseMasterBuffer(&bufHeader.m_buff);
      return v5;
    }
    SmartBuffer::ReleaseMasterBuffer(&bufHeader.m_buff);
    SmartBuffer::ReleaseMasterBuffer(&bufHeader.m_buff);
  }
  return -1;
}

//----- (00670A80) --------------------------------------------------------  // acclient.c:647366
char __stdcall DiskController::Decompress(Cache_Pack_t *i_cpCompressed, Cache_Pack_t *o_cpUncompressed)
{
  SmartBuffer *v3; // esi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // eax@3
  Cache_Pack_t *v6; // edi@3
  int v7; // esi@3
  unsigned int v8; // eax@3
  Cache_Pack_t *v9; // eax@4
  Cache_Pack_t cpUncompressed; // [sp+8h] [bp-14h]@3

  v3 = &i_cpCompressed->m_buff;
  if ( SmartBuffer::GetSize(&i_cpCompressed->m_buff) > 4 )
  {
    v4 = SmartBuffer::GetSize(v3) - 4;
    if ( v4 >= 0x10 )
    {
      v5 = SmartBuffer::GetBuffer(v3);
      v6 = *(Cache_Pack_t **)(v5 + 4);
      v7 = v5 + 4;
      SmartBuffer::SmartBuffer(&cpUncompressed.m_buff);
      SmartBuffer::ReconfigureAllocation(&cpUncompressed.m_buff, (unsigned int)&v6->m_iVersion, 1u);
      SmartBuffer::GetSize(&cpUncompressed.m_buff);
      i_cpCompressed = v6;
      SmartBuffer::ReconfigureAllocation(&cpUncompressed.m_buff, 4u, 1u);
      v8 = SmartBuffer::GetBuffer(&cpUncompressed.m_buff);
      if ( !uncompress(v8 + 4, &i_cpCompressed, v7 + 4, v4 - 4) )
      {
        v9 = o_cpUncompressed;
        o_cpUncompressed->m_dwOffset = 0;
        v9->m_iVersion = 0;
        SmartBuffer::operator=((int)&v9->m_buff, (int)&cpUncompressed.m_buff);
        SmartBuffer::ReleaseMasterBuffer(&cpUncompressed.m_buff);
        SmartBuffer::ReleaseMasterBuffer(&cpUncompressed.m_buff);
        return 1;
      }
      SmartBuffer::ReleaseMasterBuffer(&cpUncompressed.m_buff);
      SmartBuffer::ReleaseMasterBuffer(&cpUncompressed.m_buff);
    }
  }
  return 0;
}
// 6B9B16: using guessed type int __cdecl uncompress(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00670B80) --------------------------------------------------------  // acclient.c:647411
int __thiscall DiskController::LoadData(DiskController *this, IDClass<_tagDataID,32,0> gid, Cache_Pack_t *buf_out)
{
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  ent.GID_.id = stru_8F76B4.id;
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr[1].DeleteDataByMask)(gid.id, buf_out, &ent, 0);
}

//----- (00670BC0) --------------------------------------------------------  // acclient.c:647425
char __thiscall DiskController::LoadDataEx(DiskController *this, IDClass<_tagDataID,32,0> did, Cache_Pack_t *buf_out, BTEntry *ent_out, unsigned int dwFlags)
{
  BTEntry *v5; // eax@1
  unsigned int v7; // ecx@4
  DiskController *v8; // edi@6
  BTMemNode *pNode; // [sp+0h] [bp-20h]@1
  int offset; // [sp+4h] [bp-1Ch]@4
  DiskController *v11; // [sp+8h] [bp-18h]@1
  Cache_Pack_t cpUncomp; // [sp+Ch] [bp-14h]@14

  v11 = this;
  pNode = 0;
  v5 = BTree::Lookup(&this->did_tree_m, did, &pNode);
  if ( !v5 )
    return 0;
  qmemcpy(ent_out, v5, 0x18u);
  if ( dwFlags & 2 )
    return 1;
  v7 = *((_WORD *)ent_out + 1);
  offset = ent_out->Offset_;
  buf_out->m_iVersion = v7;
  if ( (dwFlags & 5) != 5 )
  {
    SmartBuffer::ReconfigureAllocation(&buf_out->m_buff, ent_out->size_ + 4, 1u);
    SmartBuffer::GetSize(&buf_out->m_buff);
  }
  v8 = v11;
  if ( !CLBlockAllocator::Load_Data(&v11->block_man_m, buf_out, offset, (dwFlags & 5) == 5) )
  {
    SmartBuffer::ReleaseMasterBuffer(&buf_out->m_buff);
    return 0;
  }
  if ( v8->file_info_m.use_lru_fm && !v8->read_only_fm )
    BTree::Restamp_Entry(&v8->did_tree_m, did);
  if ( !(*(_BYTE *)ent_out & 1) || dwFlags & 1 || (dwFlags & 5) == 5 )
    return 1;
  Cache_Pack_t::Cache_Pack_t(&cpUncomp);
  if ( (unsigned __int8)((int (__thiscall *)(DiskController *, Cache_Pack_t *, Cache_Pack_t *))v8->vfptr[1].SaveIterationList)(
                          v8,
                          buf_out,
                          &cpUncomp) )
  {
    Cache_Pack_t::operator=((int)buf_out, (int)&cpUncomp);
    SmartBuffer::ReleaseMasterBuffer(&cpUncomp.m_buff);
    SmartBuffer::ReleaseMasterBuffer(&cpUncomp.m_buff);
    return 1;
  }
  SmartBuffer::ReleaseMasterBuffer(&cpUncomp.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&cpUncomp.m_buff);
  return 0;
}

//----- (00670D10) --------------------------------------------------------  // acclient.c:647478
int __thiscall DiskController::IsMember(DiskController *this, IDClass<_tagDataID,32,0> did, BTEntry *o_pMember)
{
  BTEntry *v3; // edx@1
  BTEntry ent; // [sp+0h] [bp-18h]@1

  ent.GID_.id = stru_8F76B4.id;
  v3 = o_pMember;
  ent = 0;
  ent.Offset_ = 0;
  ent.size_ = 0;
  ent.date_ = 0;
  ent.iter_ = 0;
  if ( !o_pMember )
    v3 = &ent;
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr[1].DeleteDataByMask)(
           did.id,
           &g_DummyCachePack,
           v3,
           2);
}

//----- (00670D60) --------------------------------------------------------  // acclient.c:647500
bool __thiscall DiskController::DeleteData(DiskController *this, IDClass<_tagDataID,32,0> did, int idIter)
{
  BTree *v3; // esi@2
  BTEntry *v4; // eax@2
  bool result; // al@5

  if ( this->read_only_fm
    || (v3 = &this->did_tree_m, (v4 = BTree::Lookup(&this->did_tree_m, did, 0)) == 0)
    || idIter && v4->iter_ > idIter )
    result = 0;
  else
    result = BTree::Remove(v3, did);
  return result;
}

//----- (00670DA0) --------------------------------------------------------  // acclient.c:647516
IDClass<_tagDataID,32,0> *__thiscall DiskController::SetMasterMapDID(DiskController *this, IDClass<_tagDataID,32,0> *result, IDClass<_tagDataID,32,0> map_id)
{
  unsigned int v3; // esi@2
  IDClass<_tagDataID,32,0> *v4; // eax@4

  if ( this->read_only_fm )
  {
    v4 = result;
    result->id = stru_8F76B4.id;
  }
  else
  {
    v3 = this->file_info_m.master_map_id_m.id;
    this->file_info_m.master_map_id_m.id = map_id.id;
    if ( this->initialized_fm )
      BTree::SaveDataToFile(&this->did_tree_m);
    v4 = result;
    result->id = v3;
  }
  return v4;
}

//----- (00670DE0) --------------------------------------------------------  // acclient.c:647539
char __thiscall DiskController::LoadIterationList(DiskController *this, CMostlyConsecutiveIntSet *Iters)
{
  DiskController *v2; // edi@1
  char v3; // bl@3
  char v4; // al@3
  SmartBuffer result; // [sp+8h] [bp-44h]@3
  Cache_Pack_t RawData; // [sp+14h] [bp-38h]@1
  TransientArchive cArchive; // [sp+28h] [bp-24h]@3

  v2 = this;
  RawData.m_dwOffset = 0;
  RawData.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&RawData.m_buff);
  if ( (unsigned __int8)((int (__thiscall *)(DiskController *, unsigned int, Cache_Pack_t *))v2->vfptr->LoadData)(
                          v2,
                          stru_8333B8.id,
                          &RawData)
    && RawData.m_iVersion == 1 )
  {
    SmartBuffer::ReconfigureAllocation(&RawData.m_buff, 4u, 1u);
    SmartBuffer::MakeWindow(&RawData.m_buff, &result, 4u);
    cArchive.vfptr = (ArchiveVtbl *)&Archive::vftable;
    cArchive.m_flags = 0;
    cArchive.m_hrError.m_val = 0;
    SmartBuffer::SmartBuffer(&cArchive.m_buffer);
    cArchive.m_currOffset = 0;
    cArchive.m_pcUserDataHash = 0;
    cArchive.m_pVersionStack = 0;
    cArchive.vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
    Archive::InitForUnpacking((Archive *)&cArchive.vfptr, &Archive::SetCurrentCoreVersion, &result);
    SmartBuffer::ReleaseMasterBuffer(&result);
    ((void (__stdcall *)(TransientArchive *))Iters->vfptr->Serialize)(&cArchive);
    v3 = ~(unsigned __int8)(cArchive.m_flags >> 2) & 1;
    Archive::~Archive((Archive *)&cArchive.vfptr);
    SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
    SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
    v4 = v3;
  }
  else
  {
    SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
    SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
    v4 = 0;
  }
  return v4;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (00670EE0) --------------------------------------------------------  // acclient.c:647589
char __thiscall DiskController::SaveIterationList(DiskController *this, CMostlyConsecutiveIntSet *Iters)
{
  DiskController *v2; // edi@1
  SmartBuffer *v3; // eax@1
  char v4; // bl@1
  SmartBuffer result; // [sp+Ch] [bp-44h]@1
  Cache_Pack_t RawData; // [sp+18h] [bp-38h]@1
  TransientArchive cArchive; // [sp+2Ch] [bp-24h]@1

  v2 = this;
  RawData.m_dwOffset = 0;
  RawData.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&RawData.m_buff);
  cArchive.vfptr = (ArchiveVtbl *)&Archive::vftable;
  cArchive.m_flags = 0;
  cArchive.m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&cArchive.m_buffer);
  cArchive.m_currOffset = 0;
  cArchive.m_pcUserDataHash = 0;
  cArchive.m_pVersionStack = 0;
  cArchive.vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
  SmartBuffer::ReconfigureAllocation(&RawData.m_buff, 4u, 1u);
  SmartBuffer::MakeWindow(&RawData.m_buff, &result, 4u);
  Archive::InitForPacking((Archive *)&cArchive.vfptr, &Archive::SetCurrentCoreVersion, &result);
  SmartBuffer::ReleaseMasterBuffer(&result);
  ((void (__stdcall *)(TransientArchive *))Iters->vfptr->Serialize)(&cArchive);
  RawData.m_iVersion = 1;
  v3 = Archive::GetSerializedBuffer((Archive *)&cArchive.vfptr, &result);
  Cache_Pack_t::UpdatePackedSize(&RawData, v3);
  SmartBuffer::ReleaseMasterBuffer(&result);
  v4 = ((int (__thiscall *)(DiskController *, unsigned int, Cache_Pack_t *, signed int))v2->vfptr->SaveData)(
         v2,
         stru_8333B8.id,
         &RawData,
         1);
  Archive::~Archive((Archive *)&cArchive.vfptr);
  SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&RawData.m_buff);
  return v4;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (00670FE0) --------------------------------------------------------  // acclient.c:647633
void __thiscall DiskController::DiskController(DiskController *this)
{
  DiskController *v1; // esi@1
  CLBlockAllocator *v2; // edi@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  v2 = &this->block_man_m;
  this->initialized_fm = 0;
  this->read_only_fm = 0;
  this->expandable_fm = 0;
  this->data_set_lm = 0;
  this->data_subset_lm = 0;
  this->vfptr = (DiskConBaseVtbl *)&DiskController::vftable;
  CLBlockAllocator::CLBlockAllocator(&this->block_man_m);
  BTree::BTree(&v1->did_tree_m, v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->filename_m.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  DiskFileInfo_t::DiskFileInfo_t(&v1->file_info_m);
}
// 7FDBA8: using guessed type int (__thiscall *DiskController::vftable)(void *, char);

//----- (00671040) --------------------------------------------------------  // acclient.c:647657
void __thiscall DiskController::~DiskController(DiskController *this)
{
  DiskController *v1; // esi@1
  bool v2; // al@1
  int v3; // edi@5

  v1 = this;
  v2 = this->initialized_fm;
  this->vfptr = (DiskConBaseVtbl *)&DiskController::vftable;
  if ( v2 )
  {
    if ( !this->read_only_fm )
      BTree::SaveDataToFile(&this->did_tree_m);
    CLBlockAllocator::Close_Data_File(&v1->block_man_m);
    BTree::~BTree(&v1->did_tree_m);
    v1->initialized_fm = 0;
  }
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v1->file_info_m.id_vnum);
  v3 = (int)&v1->filename_m.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  BTree::~BTree(&v1->did_tree_m);
  CLBlockAllocator::~CLBlockAllocator(&v1->block_man_m);
  v1->vfptr = (DiskConBaseVtbl *)&DiskConBase::vftable;
}
// 7FDB48: using guessed type int (__thiscall *DiskConBase::vftable)(void *, char);
// 7FDBA8: using guessed type int (__thiscall *DiskController::vftable)(void *, char);

//----- (006710C0) --------------------------------------------------------  // acclient.c:647686
bool __thiscall DiskController::SaveDataEx(DiskController *this, BTEntry *io_entNew, Cache_Pack_t *i_cpUser, unsigned int dwFlags)
{
  BTEntry *v4; // esi@1
  bool v5; // bl@1
  unsigned int v6; // edx@1
  unsigned int v7; // edi@1
  int v8; // eax@4
  unsigned int v9; // edi@12
  BTree *v10; // edi@18
  BTEntry *v11; // eax@18
  int v12; // ecx@21
  BTMemNode *v13; // ST00_4@24
  int v14; // eax@24
  DiskController *v16; // [sp+10h] [bp-20h]@1
  unsigned int id; // [sp+14h] [bp-1Ch]@1
  BTMemNode *node_p; // [sp+18h] [bp-18h]@1
  Cache_Pack_t cpDisk; // [sp+1Ch] [bp-14h]@1
  bool io_entNewa; // [sp+34h] [bp+4h]@1

  v4 = io_entNew;
  id = io_entNew->GID_.id;
  v16 = this;
  v5 = 0;
  node_p = 0;
  cpDisk.m_dwOffset = 0;
  cpDisk.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&cpDisk.m_buff);
  v6 = i_cpUser->m_iVersion;
  cpDisk.m_dwOffset = i_cpUser->m_dwOffset;
  cpDisk.m_iVersion = v6;
  SmartBuffer::operator=((int)&cpDisk.m_buff, (int)&i_cpUser->m_buff);
  v7 = dwFlags & 7;
  io_entNewa = v7 == 5;
  if ( !v16->read_only_fm && stru_8F76B4.id != id && *((_WORD *)v4 + 1) )
  {
    v8 = v4->date_;
    *(_DWORD *)v4 &= 0xFFFFFFFE;
    if ( !v8 )
      v4->date_ = Timer::get_real_time();
    switch ( v7 )
    {
      case 2u:
        SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
        if ( (unsigned __int8)((int (__stdcall *)(Cache_Pack_t *, Cache_Pack_t *))v16->vfptr[1].LoadIterationList)(
                                i_cpUser,
                                &cpDisk) )
          goto $L82966;
        Cache_Pack_t::operator=((int)&cpDisk, (int)i_cpUser);
        break;
      case 3u:
$L82966:
        *(_DWORD *)v4 |= 1u;
        break;
      case 4u:
        SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
        if ( !(unsigned __int8)((int (__stdcall *)(Cache_Pack_t *, Cache_Pack_t *))v16->vfptr[1].SaveIterationList)(
                                 i_cpUser,
                                 &cpDisk) )
          goto LABEL_28;
        break;
      case 1u:
      case 5u:
        break;
      default:
        goto LABEL_28;
    }
    v4->size_ = Cache_Pack_t::GetDataSize(&cpDisk);
    if ( !(*(_BYTE *)v4 & 1)
      || (v9 = *(_DWORD *)Cache_Pack_t::GetPackBufferPtr(&cpDisk), Cache_Pack_t::GetDataSize(&cpDisk) >= 0x10)
      && v9 >= Cache_Pack_t::GetDataSize(&cpDisk) )
    {
      if ( !io_entNewa )
      {
        if ( dwFlags & 8 )
        {
          Cache_Pack_t::operator=((int)i_cpUser, (int)&cpDisk);
          i_cpUser->m_iVersion = *((_WORD *)v4 + 1);
        }
        if ( !DiskController::CheckRoom(v16, v4->size_) )
          goto LABEL_27;
      }
      v10 = &v16->did_tree_m;
      v11 = BTree::Lookup(&v16->did_tree_m, (IDClass<_tagDataID,32,0>)id, &node_p);
      if ( io_entNewa )
        v4->size_ = -2;
      if ( v11 )
      {
        v12 = v4->iter_;
        if ( v12 && v11->iter_ > v12 )
        {
          v5 = 1;
LABEL_27:
          SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
          SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
          return v5;
        }
        v13 = node_p;
        v4->Offset_ = node_p->offset_m;
        v14 = BTree::Update_Data_Trans(v10, v13, v4, &cpDisk);
      }
      else
      {
        v14 = BTree::DescendToAdd(v10, v4, &cpDisk);
      }
      v5 = v14 == 0;
      goto LABEL_27;
    }
  }
LABEL_28:
  SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&cpDisk.m_buff);
  return 0;
}

//----- (006712F0) --------------------------------------------------------  // acclient.c:647801
DiskController *__thiscall DiskController::vector_deleting_destructor(DiskController *this, unsigned int a2)
{
  DiskController *v2; // esi@1

  v2 = this;
  DiskController::~DiskController(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00671310) --------------------------------------------------------  // acclient.c:647813
char __thiscall DiskController::DeleteDataByMask(DiskController *this, IDClass<_tagDataID,32,0> MatchID, IDClass<_tagDataID,32,0> MatchMask)
{
  unsigned int v3; // edi@2
  int v4; // esi@2
  char v5; // bl@3
  unsigned int v6; // ecx@4
  unsigned int v7; // edx@4
  unsigned int v8; // ebp@9
  unsigned int v9; // ebx@12
  char result; // al@19
  DiskController *v11; // [sp+8h] [bp-10h]@1
  SmartArray<BTEntry,1> AllIDs; // [sp+Ch] [bp-Ch]@3
  char MatchMaska; // [sp+20h] [bp+8h]@12

  v11 = this;
  if ( this->read_only_fm )
  {
    result = 0;
  }
  else
  {
    v3 = MatchMask.id;
    v4 = 0;
    if ( MatchMask.id )
    {
      AllIDs.m_data = 0;
      AllIDs.m_sizeAndDeallocate = 0;
      AllIDs.m_num = 0;
      v5 = 1;
      if ( (MatchMask.id & 0x80000000) != 0 )
      {
        v6 = stru_8F76B4.id;
        v7 = MatchMask.id;
        do
        {
          if ( v6 && !(MatchMask.id & 1) )
            v5 = 0;
          v7 >>= 1;
          v6 = MatchMask.id & 1;
        }
        while ( v7 );
      }
      v8 = MatchMask.id & MatchID.id;
      if ( v5 )
        BTree::Get_Id_List_Range(
          &v11->did_tree_m,
          &AllIDs,
          (IDClass<_tagDataID,32,0>)(MatchMask.id & MatchID.id),
          (IDClass<_tagDataID,32,0>)(v8 | ~MatchMask.id));
      else
        BTree::Get_Id_List(&v11->did_tree_m, &AllIDs);
      v9 = 0;
      for ( MatchMaska = 0; v9 < AllIDs.m_num; ++v4 )
      {
        if ( (v3 & AllIDs.m_data[v4].GID_.id) == v8 )
        {
          ((void (__stdcall *)(unsigned int, _DWORD))v11->vfptr->DeleteData)(AllIDs.m_data[v4].GID_.id, 0);
          MatchMaska = 1;
        }
        ++v9;
      }
      if ( (AllIDs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      {
        if ( (_DWORD)AllIDs.m_data )
          operator delete[](&AllIDs.m_data[-1].iter_);
      }
      result = MatchMaska;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

//----- (00671430) --------------------------------------------------------  // acclient.c:647890
bool __thiscall DiskController::InitFile(DiskController *this, DiskConInitInfo *info_r)
{
  DiskController *v2; // esi@1
  DiskConInitInfo *v3; // edi@2
  unsigned int v4; // eax@2
  unsigned int v5; // eax@3
  int v6; // ebp@3
  int v7; // eax@4
  int v8; // eax@6
  DATFILE_TYPE v9; // eax@23
  bool result; // al@23
  bool fCreateIfNeeded; // [sp+7h] [bp-19h]@3
  DiskTransactInfo *pTranInfo; // [sp+8h] [bp-18h]@3
  CMostlyConsecutiveIntSet Iterations; // [sp+Ch] [bp-14h]@19
  bool info_ra; // [sp+24h] [bp+4h]@2

  v2 = this;
  if ( !this->initialized_fm )
  {
    v3 = info_r;
    this->read_only_fm = (info_r->open_flags_lm & 4) == 4;
    this->expandable_fm = (info_r->open_flags_lm & 2) == 2;
    v4 = info_r->open_flags_lm;
    info_ra = (info_r->open_flags_lm & 8) == 8;
    if ( info_ra )
      goto LABEL_16;
    pTranInfo = 0;
    v5 = CLBlockAllocator::OpenDataFile(&this->block_man_m, &this->file_info_m, &v3->file, &v3->path, v4, &pTranInfo);
    v2->file_info_m.use_lru_fm = 0;
    v6 = v5;
    fCreateIfNeeded = (v3->open_flags_lm & 0x10) == 16;
    if ( !v5 )
    {
      v3->data_set_lm = v2->file_info_m.data_set_lm;
      v3->data_subset_lm = v2->file_info_m.data_subset_lm;
      v7 = v3->eng_pack_vnum;
      if ( (v7 < 0 || v7 == v2->file_info_m.eng_pack_vnum)
        && ((v8 = v3->game_pack_vnum, v8 < 0) || v3->eng_only || v8 == v2->file_info_m.game_pack_vnum) )
      {
        v6 = BTree::LoadTree(&v2->did_tree_m, &v2->file_info_m);
        if ( !v6 )
        {
          if ( !pTranInfo )
            goto LABEL_15;
          v6 = BTree::RecoverTransaction(&v2->did_tree_m, pTranInfo);
          if ( !v6 )
            goto LABEL_15;
        }
      }
      else
      {
        v6 = -6;
      }
    }
    if ( fCreateIfNeeded )
      info_ra = 1;
LABEL_15:
    operator delete(pTranInfo);
    if ( !info_ra )
    {
      if ( !v6 )
      {
LABEL_23:
        v9 = v2->file_info_m.data_set_lm;
        v2->data_subset_lm = v2->file_info_m.data_subset_lm;
        v2->data_set_lm = v9;
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)&v2->filename_m,
          (const unsigned __int16 *)v3);
        result = v6 == 0;
        v2->initialized_fm = v6 == 0;
        return result;
      }
LABEL_22:
      CLBlockAllocator::Close_Data_File(&v2->block_man_m);
      goto LABEL_23;
    }
LABEL_16:
    DiskFileInfo_t::ClearData(&v2->file_info_m);
    v2->file_info_m.iBlockSize_ = v3->block_size_lm;
    v2->file_info_m.fileSize_ = v3->file_size_lm;
    v2->file_info_m.data_set_lm = v3->data_set_lm;
    v2->file_info_m.data_subset_lm = v3->data_subset_lm;
    v2->file_info_m.use_lru_fm = 0;
    v2->file_info_m.eng_pack_vnum = v3->eng_pack_vnum;
    v2->file_info_m.game_pack_vnum = v3->game_pack_vnum;
    v6 = CLBlockAllocator::CreateDataFile(
           &v2->block_man_m,
           &v2->file_info_m,
           &v3->file,
           &v3->path,
           v3->open_flags_lm | 8);
    if ( !v6 )
    {
      v6 = BTree::CreateTree(&v2->did_tree_m, &v2->file_info_m);
      if ( !v6 )
      {
        v6 = CLBlockAllocator::SaveFileInfo(&v2->block_man_m);
        if ( !v6 )
        {
          CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&Iterations);
          v2->vfptr->SaveIterationList((DiskConBase *)v2, &Iterations);
          if ( (Iterations.m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
            operator delete[](Iterations.m_Ints.m_data);
          goto LABEL_23;
        }
      }
    }
    goto LABEL_22;
  }
  return 0;
}

//----- (00714D00) --------------------------------------------------------  // acclient.c:807654
int sub_714D00()
{
  return atexit(nullsub_72);
}

//----- (00714D10) --------------------------------------------------------  // acclient.c:807660
int _E76_84()
{
  return atexit(nullsub_73);
}

//----- (00714D20) --------------------------------------------------------  // acclient.c:807666
int _E79_79()
{
  return atexit(_E80_76);
}

//----- (00714D30) --------------------------------------------------------  // acclient.c:807672
int _E82_53()
{
  SmartBuffer::SmartBuffer(&stru_8F76C0);
  return atexit(_E83_51);
}

//----- (00714D50) --------------------------------------------------------  // acclient.c:807679
int sub_714D50()
{
  return atexit(nullsub_75);
}

//----- (0077EE90) --------------------------------------------------------  // acclient.c:918005
void __cdecl _E83_51()
{
  SmartBuffer::ReleaseMasterBuffer(&stru_8F76C0);
  SmartBuffer::ReleaseMasterBuffer(&stru_8F76C0);
}

