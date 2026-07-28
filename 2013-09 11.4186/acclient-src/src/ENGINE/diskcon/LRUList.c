/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LRUList
   Object     : ENGINE\diskcon\LRUList.obj
   Functions  : 36
   Addresses  : 00674A30 - 00714E90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00674A30) --------------------------------------------------------  // acclient.c:651046
void __thiscall LRUB_Mem_t::LRUB_Mem_t(LRUB_Mem_t *this, LRUB_Mem_t *source)
{
  LRUB_Mem_t *v2; // ebx@1
  int v3; // eax@2
  void *v4; // eax@3
  unsigned int v5; // edx@3
  char *v6; // eax@3

  v2 = this;
  this->info_pm = 0;
  this->DIds_pm = 0;
  this->buffer_cpm = 0;
  this->offset_lm = source->offset_lm;
  this->size_lm = source->size_lm;
  this->max_lm = source->max_lm;
  this->above_lm = source->above_lm;
  this->below_lm = source->below_lm;
  if ( source->buffer_cpm )
  {
    v3 = this->size_lm;
    if ( v3 )
    {
      v4 = operator new[](v3);
      v5 = v2->size_lm;
      v2->buffer_cpm = (char *)v4;
      qmemcpy(v4, source->buffer_cpm, v5);
      v6 = v2->buffer_cpm;
      v2->info_pm = (LRUB_Info_t *)v6;
      v2->DIds_pm = (IDClass<_tagDataID,32,0> *)(v6 + 16);
    }
  }
}

//----- (00674AB0) --------------------------------------------------------  // acclient.c:651080
void __thiscall LRUB_Mem_t::Make_Buffer(LRUB_Mem_t *this, int size_l)
{
  LRUB_Mem_t *v2; // esi@1
  void *v3; // eax@3

  v2 = this;
  if ( !this->buffer_cpm && size_l > 0 )
  {
    this->size_lm = size_l;
    this->max_lm = (unsigned int)(size_l - 16) >> 2;
    v3 = operator new[](size_l);
    v2->buffer_cpm = (char *)v3;
    v2->info_pm = (LRUB_Info_t *)v3;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    v2->DIds_pm = (IDClass<_tagDataID,32,0> *)(v2->buffer_cpm + 16);
  }
}

//----- (00674B10) --------------------------------------------------------  // acclient.c:651102
char __thiscall LRU_List::Create_List(LRU_List *this)
{
  char result; // al@1
  DiskFileInfo_t *v2; // edx@4

  result = 0;
  if ( !this->initialized_fm && !this->young_pm && !this->old_pm )
  {
    v2 = this->file_info_pm;
    if ( !v2->young_lru_lm && !v2->old_lru_lm )
    {
      if ( v2->use_lru_fm )
      {
        result = 1;
        this->initialized_fm = 1;
        this->empty_fm = 1;
      }
    }
  }
  return result;
}

//----- (00674B60) --------------------------------------------------------  // acclient.c:651125
void __thiscall LRUB_Mem_t::LRUB_Mem_t(LRUB_Mem_t *this, int block_size_l)
{
  this->buffer_cpm = 0;
  this->offset_lm = 0;
  this->size_lm = 0;
  this->max_lm = 0;
  this->above_lm = 0;
  this->below_lm = -1;
  this->info_pm = 0;
  this->DIds_pm = 0;
  if ( block_size_l > 0 )
    LRUB_Mem_t::Make_Buffer(this, block_size_l);
}

//----- (00674BA0) --------------------------------------------------------  // acclient.c:651140
IDClass<_tagDataID,32,0> *__thiscall LRUB_Mem_t::Remove_Below(LRUB_Mem_t *this, IDClass<_tagDataID,32,0> *result)
{
  unsigned int v2; // esi@1
  unsigned int v3; // edx@1
  IDClass<_tagDataID,32,0> *v4; // eax@5
  int v5; // eax@5
  IDClass<_tagDataID,32,0> *v6; // eax@6

  v2 = stru_8F76E0.id;
  v3 = stru_8F76E0.id;
  if ( this->below_lm >= 0 )
  {
    while ( v2 == v3 )
    {
      v4 = &this->DIds_pm[this->below_lm];
      v3 = v4->id;
      v4->id = v2;
      v5 = this->below_lm - 1;
      this->below_lm = v5;
      if ( v5 < 0 )
        break;
      v2 = stru_8F76E0.id;
    }
  }
  v6 = result;
  result->id = v3;
  return v6;
}

//----- (00674BE0) --------------------------------------------------------  // acclient.c:651170
IDClass<_tagDataID,32,0> *__thiscall LRUB_Mem_t::Remove_Above(LRUB_Mem_t *this, IDClass<_tagDataID,32,0> *result)
{
  unsigned int v2; // esi@1
  unsigned int v3; // edx@1
  IDClass<_tagDataID,32,0> *v4; // eax@5
  int v5; // ebx@5
  IDClass<_tagDataID,32,0> *v6; // eax@6

  v2 = stru_8F76E0.id;
  v3 = stru_8F76E0.id;
  if ( this->above_lm < this->info_pm->used_lm )
  {
    while ( v2 == v3 )
    {
      v4 = &this->DIds_pm[this->above_lm];
      v3 = v4->id;
      v4->id = v2;
      v5 = this->above_lm + 1;
      this->above_lm = v5;
      if ( v5 >= this->info_pm->used_lm )
        break;
      v2 = stru_8F76E0.id;
    }
  }
  v6 = result;
  result->id = v3;
  return v6;
}

//----- (00674C30) --------------------------------------------------------  // acclient.c:651200
IDClass<_tagDataID,32,0> *__thiscall LRUB_Mem_t::Peek_Above(LRUB_Mem_t *this, IDClass<_tagDataID,32,0> *result)
{
  LRUB_Info_t *v2; // esi@1
  unsigned int v3; // edi@1
  IDClass<_tagDataID,32,0> *v4; // edx@2
  int v5; // eax@3
  int v6; // eax@5
  IDClass<_tagDataID,32,0> *v7; // eax@6

  v2 = this->info_pm;
  v3 = stru_8F76E0.id;
  if ( this->above_lm < v2->used_lm )
  {
    v4 = this->DIds_pm;
    do
    {
      v5 = this->above_lm;
      if ( stru_8F76E0.id != v4[v5].id )
        break;
      this->above_lm = v5 + 1;
    }
    while ( this->above_lm < this->info_pm->used_lm );
  }
  v6 = this->above_lm;
  if ( v6 >= v2->used_lm )
  {
    v7 = result;
    result->id = v3;
  }
  else
  {
    result->id = this->DIds_pm[v6].id;
    v7 = result;
  }
  return v7;
}

//----- (00674CA0) --------------------------------------------------------  // acclient.c:651238
bool __thiscall LRU_List::Load_List(LRU_List *this)
{
  LRU_List *v1; // esi@1
  LRUB_Mem_t *v2; // eax@5
  LRUB_Mem_t *v3; // eax@6
  DiskFileInfo_t *v4; // ecx@8
  DiskFileInfo_t *v5; // eax@8
  LRUB_Mem_t *v6; // eax@9
  LRUB_Mem_t *v7; // eax@10
  DiskFileInfo_t *v8; // edx@12
  bool v9; // bl@16
  Cache_Pack_t buffer; // [sp+8h] [bp-14h]@1

  v1 = this;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  if ( v1->initialized_fm || v1->young_pm || v1->old_pm )
  {
    v1->initialized_fm = 0;
    goto LABEL_16;
  }
  if ( !v1->file_info_pm->young_lru_lm )
    goto LABEL_14;
  v2 = (LRUB_Mem_t *)operator new(0x20u);
  if ( v2 )
    LRUB_Mem_t::LRUB_Mem_t(v2, v1->file_info_pm->iBlockSize_);
  else
    v3 = 0;
  v4 = v1->file_info_pm;
  v1->young_pm = v3;
  v3->offset_lm = v4->young_lru_lm;
  SmartBuffer::Borrow(&buffer.m_buff, v1->young_pm->buffer_cpm, v1->young_pm->size_lm);
  CLBlockAllocator::Load_Data(v1->block_man_pm, &buffer, v1->young_pm->offset_lm, 0);
  v5 = v1->file_info_pm;
  v1->empty_fm = 0;
  if ( v5->young_lru_lm == v5->old_lru_lm )
  {
    v1->old_pm = v1->young_pm;
LABEL_14:
    v1->initialized_fm = 1;
    goto LABEL_16;
  }
  v6 = (LRUB_Mem_t *)operator new(0x20u);
  if ( v6 )
    LRUB_Mem_t::LRUB_Mem_t(v6, v1->file_info_pm->iBlockSize_);
  else
    v7 = 0;
  v8 = v1->file_info_pm;
  v1->old_pm = v7;
  v7->offset_lm = v8->old_lru_lm;
  SmartBuffer::Borrow(&buffer.m_buff, v1->old_pm->buffer_cpm, v1->old_pm->size_lm);
  CLBlockAllocator::Load_Data(v1->block_man_pm, &buffer, v1->old_pm->offset_lm, 0);
  v1->initialized_fm = 1;
LABEL_16:
  v9 = v1->initialized_fm;
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return v9;
}

//----- (00674E00) --------------------------------------------------------  // acclient.c:651300
char __thiscall LRU_List::Add_Exec(LRU_List *this, IDClass<_tagDataID,32,0> target_did)
{
  LRU_List *v2; // esi@1
  LRUB_Mem_t *v3; // eax@1
  LRUB_Info_t *v4; // ecx@1
  IDClass<_tagDataID,32,0> *v5; // edx@2
  int v6; // ecx@3
  Cache_Pack_t buffer; // [sp+8h] [bp-14h]@1

  v2 = this;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  v3 = v2->young_pm;
  v4 = v3->info_pm;
  if ( v4 )
  {
    v5 = v3->DIds_pm;
    if ( v5 )
    {
      v6 = v4->used_lm;
      if ( v6 < v3->max_lm )
      {
        v5[v6].id = target_did.id;
        ++v3->info_pm->used_lm;
      }
    }
  }
  SmartBuffer::Borrow(&buffer.m_buff, v2->young_pm->buffer_cpm, v2->young_pm->size_lm);
  CLBlockAllocator::Update(v2->block_man_pm, &buffer, v2->young_pm->offset_lm);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return 1;
}

//----- (00674E90) --------------------------------------------------------  // acclient.c:651336
bool __thiscall LRU_List::Expand_Exec(LRU_List *this, LRUExpandTransactInfo *pTrIn)
{
  LRU_List *v2; // esi@1
  LRUB_Mem_t *v3; // eax@1
  DiskFileInfo_t *v4; // eax@4
  int v5; // ecx@4
  LRUB_Mem_t *v6; // eax@5
  LRUB_Info_t *v7; // eax@6
  LRUB_Mem_t *v8; // eax@7
  LRUB_Info_t *v9; // ecx@7
  IDClass<_tagDataID,32,0> *v10; // edx@8
  int v11; // ecx@9
  Cache_Pack_t buffer; // [sp+Ch] [bp-14h]@1

  v2 = this;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  v3 = v2->young_pm;
  if ( v3->offset_lm && pTrIn->m_nYoungOffset == v3->offset_lm )
  {
    v3->info_pm->younger_lm = pTrIn->m_nFirstFreeBlock;
    SmartBuffer::Borrow(&buffer.m_buff, v2->young_pm->buffer_cpm, v2->young_pm->size_lm);
    CLBlockAllocator::Update(v2->block_man_pm, &buffer, v2->young_pm->offset_lm);
  }
  v4 = v2->file_info_pm;
  v5 = pTrIn->m_nFirstFreeBlock;
  if ( v4->firstFree_ == v5 )
  {
    v4->young_lru_lm = v5;
    v6 = v2->young_pm;
    if ( v6->buffer_cpm )
    {
      v6->offset_lm = 0;
      v6->above_lm = 0;
      v6->below_lm = -1;
      v7 = v6->info_pm;
      v7->link_padding_lm = 0;
      v7->younger_lm = 0;
      v7->older_lm = 0;
      v7->used_lm = 0;
    }
    v8 = v2->young_pm;
    v9 = v8->info_pm;
    if ( v9 )
    {
      v10 = v8->DIds_pm;
      if ( v10 )
      {
        v11 = v9->used_lm;
        if ( v11 < v8->max_lm )
        {
          v10[v11].id = pTrIn->m_cTargetDID.id;
          ++v8->info_pm->used_lm;
        }
      }
    }
    v2->young_pm->info_pm->older_lm = pTrIn->m_nYoungOffset;
    v2->young_pm->offset_lm = pTrIn->m_nFirstFreeBlock;
    SmartBuffer::Borrow(&buffer.m_buff, v2->young_pm->buffer_cpm, v2->young_pm->size_lm);
    CLBlockAllocator::Store_Data(v2->block_man_pm, &buffer, v2->young_pm->offset_lm);
  }
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return 0;
}

//----- (00674FD0) --------------------------------------------------------  // acclient.c:651404
bool __thiscall LRU_List::Delete_Exec(LRU_List *this, LRUDeleteTransactInfo *pTrIn)
{
  LRU_List *v2; // edi@1
  LRUB_Info_t *v3; // ebp@1
  int v4; // eax@1
  int v5; // ebx@3
  DiskFileInfo_t *v6; // eax@6
  int v7; // ebx@8
  DiskFileInfo_t *v8; // eax@11
  bool v9; // bl@13
  Cache_Pack_t buffer; // [sp+10h] [bp-34h]@1
  LRUB_Mem_t block; // [sp+24h] [bp-20h]@1

  v2 = this;
  v3 = 0;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  v4 = v2->file_info_pm->iBlockSize_;
  block.buffer_cpm = 0;
  block.offset_lm = 0;
  block.size_lm = 0;
  block.max_lm = 0;
  block.above_lm = 0;
  block.below_lm = -1;
  block.info_pm = 0;
  block.DIds_pm = 0;
  if ( v4 > 0 )
  {
    LRUB_Mem_t::Make_Buffer(&block, v4);
    v3 = block.info_pm;
  }
  SmartBuffer::Borrow(&buffer.m_buff, block.buffer_cpm, block.size_lm);
  v5 = pTrIn->m_nOldOffset;
  if ( v5 )
  {
    CLBlockAllocator::Load_Data(v2->block_man_pm, &buffer, v5, 0);
    if ( pTrIn->m_nBlockOffset == v3->younger_lm )
    {
      v3->younger_lm = pTrIn->m_nYoungOffset;
      CLBlockAllocator::Update(v2->block_man_pm, &buffer, v5);
    }
  }
  else
  {
    v6 = v2->file_info_pm;
    if ( pTrIn->m_nBlockOffset == v6->old_lru_lm )
      v6->old_lru_lm = pTrIn->m_nYoungOffset;
  }
  v7 = pTrIn->m_nYoungOffset;
  if ( v7 )
  {
    CLBlockAllocator::Load_Data(v2->block_man_pm, &buffer, v7, 0);
    if ( pTrIn->m_nBlockOffset == v3->older_lm )
    {
      v3->older_lm = pTrIn->m_nOldOffset;
      CLBlockAllocator::Update(v2->block_man_pm, &buffer, v7);
    }
  }
  else
  {
    v8 = v2->file_info_pm;
    if ( pTrIn->m_nBlockOffset == v8->young_lru_lm )
      v8->young_lru_lm = pTrIn->m_nOldOffset;
  }
  v9 = CLBlockAllocator::DeleteBlocks(
         v2->block_man_pm,
         pTrIn->m_nBlockOffset,
         v2->file_info_pm->finalFree_,
         v2->file_info_pm->iFreeBlocks_,
         1) == 0;
  if ( block.buffer_cpm )
    operator delete[](block.buffer_cpm);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return v9;
}

//----- (00675140) --------------------------------------------------------  // acclient.c:651483
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FDC4C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable)(void *, char);

//----- (00675180) --------------------------------------------------------  // acclient.c:651504
bool __thiscall LRU_List::Expand_Trans(LRU_List *this, IDClass<_tagDataID,32,0> target_did, bool clear_f)
{
  LRU_List *v3; // edi@1
  LRUB_Mem_t *v4; // eax@1
  void *v5; // esi@2
  int v6; // eax@3
  DiskFileInfo_t *v7; // eax@6
  LRUB_Mem_t *v8; // eax@8
  int v9; // eax@9
  DiskFileInfo_t *v10; // ecx@11
  DiskFileInfo_t *v11; // eax@12
  CLBlockAllocator *v12; // ecx@12
  LRUExpandTransactInfo TrIn; // [sp+8h] [bp-18h]@12

  v3 = this;
  v4 = this->old_pm;
  if ( v4 )
  {
    if ( v4 == this->young_pm )
    {
      v8 = (LRUB_Mem_t *)operator new(0x20u);
      if ( v8 )
        LRUB_Mem_t::LRUB_Mem_t(v8, v3->young_pm);
      else
        v9 = 0;
      v10 = v3->file_info_pm;
      v3->old_pm = (LRUB_Mem_t *)v9;
      *(_DWORD *)(*(_DWORD *)(v9 + 20) + 4) = v10->firstFree_;
    }
  }
  else
  {
    v5 = operator new(0x20u);
    if ( v5 )
    {
      v6 = v3->file_info_pm->iBlockSize_;
      *((_DWORD *)v5 + 7) = 0;
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = -1;
      *((_DWORD *)v5 + 5) = 0;
      *((_DWORD *)v5 + 6) = 0;
      if ( v6 > 0 )
        LRUB_Mem_t::Make_Buffer((LRUB_Mem_t *)v5, v6);
    }
    else
    {
      v5 = 0;
    }
    v7 = v3->file_info_pm;
    v3->young_pm = (LRUB_Mem_t *)v5;
    v3->old_pm = (LRUB_Mem_t *)v5;
    v7->old_lru_lm = v7->firstFree_;
    v3->empty_fm = 0;
  }
  LRUExpandTransactInfo::LRUExpandTransactInfo(&TrIn);
  v11 = v3->file_info_pm;
  TrIn.m_nYoungOffset = v3->young_pm->offset_lm;
  TrIn.m_nFirstFreeBlock = v11->firstFree_;
  v12 = v3->block_man_pm;
  TrIn.m_cTargetDID.id = target_did.id;
  CLBlockAllocator::SaveTransaction(v12, (DiskTransactInfo *)&TrIn.vfptr);
  LRU_List::Expand_Exec(v3, &TrIn);
  if ( clear_f )
    CLBlockAllocator::ClearTransaction(v3->block_man_pm);
  return 0;
}

//----- (006752A0) --------------------------------------------------------  // acclient.c:651575
bool __thiscall LRU_List::Delete_Trans(LRU_List *this, LRUB_Mem_t *block_p, bool clear_f)
{
  LRU_List *v3; // esi@1
  LRUB_Info_t *v4; // eax@1
  CLBlockAllocator *v5; // ecx@1
  LRUB_Info_t *v6; // eax@3
  int v7; // ecx@3
  LRUB_Mem_t *v8; // edi@5
  void *v9; // eax@6
  LRUB_Mem_t *v10; // eax@10
  LRUB_Info_t *v11; // eax@11
  LRUB_Mem_t *v12; // eax@14
  LRUB_Info_t *v13; // eax@15
  LRUB_Mem_t *v14; // eax@17
  LRUB_Mem_t *v15; // edi@18
  void *v16; // eax@20
  LRUB_Mem_t *v17; // eax@23
  Cache_Pack_t buffer; // [sp+10h] [bp-2Ch]@1
  LRUDeleteTransactInfo TrIn; // [sp+24h] [bp-18h]@1

  v3 = this;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  LRUDeleteTransactInfo::LRUDeleteTransactInfo(&TrIn);
  TrIn.m_nBlockOffset = block_p->offset_lm;
  v4 = block_p->info_pm;
  TrIn.m_nOldOffset = v4->older_lm;
  v5 = v3->block_man_pm;
  TrIn.m_nYoungOffset = v4->younger_lm;
  CLBlockAllocator::SaveTransaction(v5, (DiskTransactInfo *)&TrIn.vfptr);
  LRU_List::Delete_Exec(v3, &TrIn);
  if ( clear_f )
    CLBlockAllocator::ClearTransaction(v3->block_man_pm);
  v6 = block_p->info_pm;
  v7 = v6->younger_lm;
  if ( v6->older_lm )
  {
    if ( !v7 )
    {
      v12 = v3->young_pm;
      if ( v12->buffer_cpm )
      {
        v12->offset_lm = 0;
        v12->above_lm = 0;
        v12->below_lm = -1;
        v13 = v12->info_pm;
        v13->link_padding_lm = 0;
        v13->younger_lm = 0;
        v13->older_lm = 0;
        v13->used_lm = 0;
      }
      v3->young_pm->offset_lm = v3->file_info_pm->young_lru_lm;
      SmartBuffer::Borrow(&buffer.m_buff, v3->young_pm->buffer_cpm, v3->young_pm->size_lm);
      CLBlockAllocator::Load_Data(v3->block_man_pm, &buffer, v3->young_pm->offset_lm, 0);
    }
  }
  else if ( v7 )
  {
    v10 = v3->old_pm;
    if ( v10->buffer_cpm )
    {
      v10->offset_lm = 0;
      v10->above_lm = 0;
      v10->below_lm = -1;
      v11 = v10->info_pm;
      v11->link_padding_lm = 0;
      v11->younger_lm = 0;
      v11->older_lm = 0;
      v11->used_lm = 0;
    }
    v3->old_pm->offset_lm = v3->file_info_pm->old_lru_lm;
    SmartBuffer::Borrow(&buffer.m_buff, v3->old_pm->buffer_cpm, v3->old_pm->size_lm);
    CLBlockAllocator::Load_Data(v3->block_man_pm, &buffer, v3->old_pm->offset_lm, 0);
  }
  else
  {
    v8 = v3->old_pm;
    if ( v8 )
    {
      v9 = v8->buffer_cpm;
      v8->offset_lm = 0;
      v8->size_lm = 0;
      v8->max_lm = 0;
      v8->above_lm = 0;
      v8->below_lm = -1;
      v8->info_pm = 0;
      v8->DIds_pm = 0;
      if ( v9 )
      {
        operator delete[](v9);
        v8->buffer_cpm = 0;
      }
      operator delete(v8);
    }
    v3->old_pm = 0;
    v3->young_pm = 0;
  }
  v14 = v3->young_pm;
  if ( v14 )
  {
    v15 = v3->old_pm;
    if ( v14->offset_lm == v15->offset_lm )
    {
      if ( v15 )
      {
        v16 = v15->buffer_cpm;
        v15->offset_lm = 0;
        v15->size_lm = 0;
        v15->max_lm = 0;
        v15->above_lm = 0;
        v15->below_lm = -1;
        v15->info_pm = 0;
        v15->DIds_pm = 0;
        if ( v16 )
        {
          operator delete[](v16);
          v15->buffer_cpm = 0;
        }
        operator delete(v15);
      }
      v17 = v3->young_pm;
      v3->old_pm = v17;
      v17->info_pm->younger_lm = 0;
      v3->old_pm->info_pm->older_lm = 0;
    }
  }
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return 0;
}

//----- (006754C0) --------------------------------------------------------  // acclient.c:651708
IDClass<_tagDataID,32,0> *__thiscall LRU_List::Get_Oldest(LRU_List *this, IDClass<_tagDataID,32,0> *result)
{
  LRU_List *v2; // esi@1
  unsigned int v3; // edi@1
  char v4; // bl@1
  LRUB_Mem_t *v5; // ecx@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v6; // eax@7
  HashSetData<IDClass<_tagDataID,32,0> > *v7; // eax@10
  unsigned int v8; // edi@15
  LRUB_Mem_t *v9; // eax@15
  LRUB_Info_t *v10; // ecx@15
  LRUB_Info_t *v11; // ecx@19
  IDClass<_tagDataID,32,0> *v12; // edx@20
  int v13; // ecx@21
  IDClass<_tagDataID,32,0> v15; // [sp+Ch] [bp-20h]@3
  IDClass<_tagDataID,32,0> v16; // [sp+10h] [bp-1Ch]@15
  IDClass<_tagDataID,32,0> v17; // [sp+14h] [bp-18h]@25
  Cache_Pack_t buffer; // [sp+18h] [bp-14h]@1

  v2 = this;
  v3 = stru_8F76E0.id;
  v4 = 0;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  v5 = v2->old_pm;
  if ( !v5 )
    goto LABEL_30;
  while ( stru_8F76E0.id == v3 )
  {
    v3 = LRUB_Mem_t::Peek_Above(v5, &v15)->id;
    if ( stru_8F76E0.id == v3 )
    {
      if ( v4 )
      {
        SmartBuffer::Borrow(&buffer.m_buff, v2->young_pm->buffer_cpm, v2->young_pm->size_lm);
        CLBlockAllocator::Update(v2->block_man_pm, &buffer, v2->young_pm->offset_lm);
        v4 = 0;
      }
      LRU_List::Delete_Trans(v2, v2->old_pm, 1);
    }
    else
    {
      v6 = v2->used_table_m.m_ihlIntrusive.m_hash.m_buckets[v3 % v2->used_table_m.m_ihlIntrusive.m_hash.m_numBuckets];
      if ( !v6 )
        goto LABEL_10;
      while ( v6->m_hashKey.id != v3 )
      {
        v6 = v6->m_hashNext;
        if ( !v6 )
          goto LABEL_10;
      }
      if ( v6 )
      {
        v8 = LRUB_Mem_t::Remove_Above(v2->old_pm, &v16)->id;
        v9 = v2->young_pm;
        v10 = v9->info_pm;
        if ( v10 && v9->DIds_pm && v10->used_lm < v9->max_lm )
        {
          v11 = v9->info_pm;
          if ( v11 )
          {
            v12 = v9->DIds_pm;
            if ( v12 )
            {
              v13 = v11->used_lm;
              if ( v13 < v9->max_lm )
              {
                v12[v13].id = v8;
                ++v9->info_pm->used_lm;
              }
            }
          }
          v4 = 1;
        }
        else
        {
          LRU_List::Expand_Trans(v2, (IDClass<_tagDataID,32,0>)v8, 0);
          v4 = 0;
        }
      }
      else
      {
LABEL_10:
        v7 = v2->dead_table_m.m_intrusiveTable.m_buckets[v3 % v2->dead_table_m.m_intrusiveTable.m_numBuckets];
        if ( !v7 )
          goto LABEL_27;
        while ( v7->m_hashKey.id != v3 )
        {
          v7 = v7->m_hashNext;
          if ( !v7 )
            goto LABEL_27;
        }
        if ( !v7 )
          goto LABEL_27;
        LRUB_Mem_t::Remove_Above(v2->old_pm, &v17);
      }
      v3 = stru_8F76E0.id;
    }
LABEL_27:
    v5 = v2->old_pm;
    if ( !v5 )
      break;
  }
  if ( v4 )
  {
    SmartBuffer::Borrow(&buffer.m_buff, v2->young_pm->buffer_cpm, v2->young_pm->size_lm);
    CLBlockAllocator::Update(v2->block_man_pm, &buffer, v2->young_pm->offset_lm);
  }
LABEL_30:
  result->id = v3;
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return result;
}

//----- (006756A0) --------------------------------------------------------  // acclient.c:651825
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FDC4C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable)(void *, char);

//----- (00675730) --------------------------------------------------------  // acclient.c:651858
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v8; // edi@7
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v9; // ecx@7
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v10; // eax@9
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v11; // edx@10
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v12; // eax@17
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v13; // edi@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::add_internal(
          v2,
          v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00675800) --------------------------------------------------------  // acclient.c:651955
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::grow(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00675850) --------------------------------------------------------  // acclient.c:651975
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::add_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey.id % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (00675890) --------------------------------------------------------  // acclient.c:651992
bool __thiscall LRU_List::Write_Added(LRU_List *this, IDClass<_tagDataID,32,0> target_did)
{
  LRU_List *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1
  LRUB_Mem_t *v4; // eax@3
  LRUB_Info_t *v5; // ecx@4
  bool result; // al@7

  v2 = this;
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         &this->dead_table_m.m_intrusiveTable,
         &target_did);
  if ( v3 )
    operator delete(v3);
  v4 = v2->young_pm;
  if ( v4 && (v5 = v4->info_pm) != 0 && v4->DIds_pm && v5->used_lm < v4->max_lm )
  {
    LRU_List::Add_Exec(v2, target_did);
    result = 0;
  }
  else
  {
    LRU_List::Expand_Trans(v2, target_did, 0);
    result = 0;
  }
  return result;
}

//----- (00675900) --------------------------------------------------------  // acclient.c:652021
void __thiscall LRU_List::Purge_Duplicates(LRU_List *this, int was_offset_l, int was_index_l)
{
  LRU_List *v3; // ebp@1
  int v4; // eax@1
  int v5; // eax@3
  LRUB_Mem_t *v6; // esi@5
  LRUB_Mem_t *v7; // edi@5
  int v8; // ebx@5
  int *v9; // eax@5
  unsigned int v10; // ecx@5
  bool v11; // zf@5
  HashSetData<IDClass<_tagDataID,32,0> > *v12; // eax@6
  int v13; // eax@11
  IDClass<_tagDataID,32,0> *v14; // edx@12
  int v15; // eax@12
  int v16; // eax@20
  char *v17; // ecx@21
  int v18; // eax@21
  int v19; // edx@24
  int v20; // eax@26
  IDClass<_tagDataID,32,0> *v21; // ecx@26
  int v22; // ecx@26
  LRUB_Mem_t *spare_p; // [sp+10h] [bp-58h]@5
  Cache_Pack_t buffer; // [sp+14h] [bp-54h]@5
  LRUB_Mem_t block_1; // [sp+28h] [bp-40h]@1
  LRUB_Mem_t block_2; // [sp+48h] [bp-20h]@3

  v3 = this;
  v4 = this->file_info_pm->iBlockSize_;
  block_1.buffer_cpm = 0;
  block_1.offset_lm = 0;
  block_1.size_lm = 0;
  block_1.max_lm = 0;
  block_1.above_lm = 0;
  block_1.below_lm = -1;
  block_1.info_pm = 0;
  block_1.DIds_pm = 0;
  if ( v4 > 0 )
    LRUB_Mem_t::Make_Buffer(&block_1, v4);
  v5 = v3->file_info_pm->iBlockSize_;
  block_2.buffer_cpm = 0;
  block_2.offset_lm = 0;
  block_2.size_lm = 0;
  block_2.max_lm = 0;
  block_2.above_lm = 0;
  block_2.below_lm = -1;
  block_2.info_pm = 0;
  block_2.DIds_pm = 0;
  if ( v5 > 0 )
    LRUB_Mem_t::Make_Buffer(&block_2, v5);
  v6 = &block_1;
  v7 = &block_1;
  spare_p = &block_2;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  v8 = was_offset_l;
  block_1.offset_lm = was_offset_l;
  SmartBuffer::Borrow(&buffer.m_buff, block_1.buffer_cpm, block_1.size_lm);
  CLBlockAllocator::Load_Data(v3->block_man_pm, &buffer, v8, 0);
  block_1.above_lm = was_index_l;
  block_1.below_lm = was_index_l - 1;
  v9 = (int *)LRUB_Mem_t::Remove_Below(&block_1, (IDClass<_tagDataID,32,0> *)&was_offset_l);
  v10 = *v9;
  v11 = stru_8F76E0.id == *v9;
  was_offset_l = *v9;
  if ( !v11 )
  {
    do
    {
      v12 = v3->dead_table_m.m_intrusiveTable.m_buckets[v10 % v3->dead_table_m.m_intrusiveTable.m_numBuckets];
      if ( !v12 )
        goto LABEL_11;
      while ( v12->m_hashKey.id != v10 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
          goto LABEL_11;
      }
      if ( !v12 )
      {
LABEL_11:
        v13 = v7->above_lm;
        if ( v13 > 0 )
        {
          v14 = v7->DIds_pm;
          v15 = v13 - 1;
          v7->above_lm = v15;
          v14[v15].id = v10;
        }
        HashSet<IDClass<_tagDataID,32,0>>::add(&v3->dead_table_m, (IDClass<_tagDataID,32,0> *)&was_offset_l);
      }
      if ( v7->above_lm <= 0 )
      {
        SmartBuffer::Borrow(&buffer.m_buff, v7->buffer_cpm, v7->size_lm);
        CLBlockAllocator::Update(v3->block_man_pm, &buffer, v7->offset_lm);
      }
      if ( v6->below_lm < 0 )
      {
        if ( v6 == v7 )
        {
          v6 = spare_p;
          spare_p = 0;
        }
        else
        {
          v7->info_pm->older_lm = v6->info_pm->older_lm;
          LRU_List::Delete_Trans(v3, v6, 1);
        }
        v16 = v7->info_pm->older_lm;
        if ( v16 )
        {
          v17 = v6->buffer_cpm;
          v6->offset_lm = v16;
          SmartBuffer::Borrow(&buffer.m_buff, v17, v6->size_lm);
          CLBlockAllocator::Load_Data(v3->block_man_pm, &buffer, v6->offset_lm, 0);
          v18 = v6->info_pm->used_lm;
          v6->below_lm = v18 - 1;
          v6->above_lm = v18;
        }
      }
      if ( v7->above_lm <= 0 )
      {
        spare_p = v7;
        v7 = v6;
      }
      v19 = stru_8F76E0.id;
      if ( v6->below_lm >= 0 )
      {
        do
        {
          if ( stru_8F76E0.id != v19 )
            break;
          v20 = v6->below_lm;
          v21 = v6->DIds_pm;
          v19 = v21[v20].id;
          v22 = (int)&v21[v20--];
          *(_DWORD *)v22 = stru_8F76E0.id;
          v6->below_lm = v20;
        }
        while ( v20 >= 0 );
      }
      v10 = v19;
      was_offset_l = v19;
    }
    while ( stru_8F76E0.id != v19 );
  }
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  if ( block_2.buffer_cpm )
    operator delete[](block_2.buffer_cpm);
  if ( block_1.buffer_cpm )
    operator delete[](block_1.buffer_cpm);
}

//----- (00675B80) --------------------------------------------------------  // acclient.c:652177
char __thiscall HashList<IDClass<_tagDataID,32,0>,bool,1>::pop_tail(HashList<IDClass<_tagDataID,32,0>,bool,1> *this)
{
  HashList<IDClass<_tagDataID,32,0>,bool,1> *v1; // edi@1
  DLListBase *v2; // ecx@2
  DLListData *v3; // esi@2
  IDClass<_tagDataID,32,0> *v4; // esi@4
  char result; // al@8

  v1 = this;
  if ( this->m_ihlIntrusive.m_hash.m_numElements )
  {
    v2 = &this->m_ihlIntrusive.m_list;
    v3 = v1->m_ihlIntrusive.m_list.tail_;
    if ( v3 && (DLListBase::Remove(v2, v1->m_ihlIntrusive.m_list.tail_), v3) )
      v4 = (IDClass<_tagDataID,32,0> *)&v3[-1];
    else
      v4 = 0;
    IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
      (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)v1,
      v4);
    if ( v4 )
      operator delete(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00675BD0) --------------------------------------------------------  // acclient.c:652209
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::add(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != data->m_hashKey.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00675C50) --------------------------------------------------------  // acclient.c:652253
char __thiscall IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::place_at_head(IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *pMoving)
{
  IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v3; // eax@1
  char *v4; // eax@5
  DLListData *v5; // ecx@5
  char result; // al@6

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey.id % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != pMoving->m_hashKey.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  v4 = (char *)&pMoving->dllist_next;
  pMoving->dllist_next = v2->m_list.head_;
  v5 = v2->m_list.head_;
  if ( v5 )
  {
    v5->dllist_prev = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  else
  {
    v2->m_list.tail_ = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  return result;
}

//----- (00675CD0) --------------------------------------------------------  // acclient.c:652299
void __thiscall LRU_List::LRU_List(LRU_List *this, CLBlockAllocator *block_man_p, DiskFileInfo_t *file_info_p)
{
  LRU_List *v3; // esi@1
  char *v4; // edi@1

  v3 = this;
  v4 = (char *)&this->used_table_m;
  this->initialized_fm = 0;
  this->empty_fm = 1;
  this->used_count_lm = 0;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>(
    &this->used_table_m.m_ihlIntrusive.m_hash,
    0x400u);
  *((_DWORD *)v4 + 28) = 0;
  *((_DWORD *)v4 + 29) = 0;
  v3->dead_table_m.vfptr = (HashSet<IDClass<_tagDataID,32,0> >Vtbl *)&HashSet<IDClass<_tagDataID,32,0>>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>(
    &v3->dead_table_m.m_intrusiveTable,
    0x400u);
  v3->block_man_pm = block_man_p;
  v3->young_pm = 0;
  v3->old_pm = 0;
  v3->file_info_pm = file_info_p;
}
// 7E1EF8: using guessed type int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (00675D40) --------------------------------------------------------  // acclient.c:652326
void __thiscall LRU_List::~LRU_List(LRU_List *this)
{
  LRU_List *v1; // edi@1
  LRUB_Mem_t *v2; // esi@1
  void *v3; // eax@2
  LRUB_Mem_t *v4; // esi@5
  void *v5; // eax@6
  void *v6; // eax@9
  void *v7; // eax@11

  v1 = this;
  v2 = this->young_pm;
  this->initialized_fm = 0;
  if ( v2 )
  {
    v3 = v2->buffer_cpm;
    v2->offset_lm = 0;
    v2->size_lm = 0;
    v2->max_lm = 0;
    v2->above_lm = 0;
    v2->below_lm = -1;
    v2->info_pm = 0;
    v2->DIds_pm = 0;
    if ( v3 )
    {
      operator delete[](v3);
      v2->buffer_cpm = 0;
    }
    operator delete(v2);
  }
  v4 = v1->old_pm;
  v1->young_pm = 0;
  if ( v4 )
  {
    v5 = v4->buffer_cpm;
    v4->offset_lm = 0;
    v4->size_lm = 0;
    v4->max_lm = 0;
    v4->above_lm = 0;
    v4->below_lm = -1;
    v4->info_pm = 0;
    v4->DIds_pm = 0;
    if ( v5 )
    {
      operator delete[](v5);
      v4->buffer_cpm = 0;
    }
    operator delete(v4);
  }
  v1->old_pm = 0;
  v1->block_man_pm = 0;
  v1->file_info_pm = 0;
  v1->dead_table_m.vfptr = (HashSet<IDClass<_tagDataID,32,0> >Vtbl *)&HashSet<IDClass<_tagDataID,32,0>>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->dead_table_m.m_intrusiveTable);
  v6 = v1->dead_table_m.m_intrusiveTable.m_buckets;
  v1->dead_table_m.m_intrusiveTable.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable;
  if ( v6 != v1->dead_table_m.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v6);
  v1->dead_table_m.m_intrusiveTable.m_buckets = 0;
  v1->dead_table_m.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->dead_table_m.m_intrusiveTable.m_numBuckets = 0;
  v1->dead_table_m.m_intrusiveTable.m_numElements = 0;
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&v1->used_table_m);
  v7 = v1->used_table_m.m_ihlIntrusive.m_hash.m_buckets;
  v1->used_table_m.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable;
  if ( v7 != v1->used_table_m.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](v7);
  v1->used_table_m.m_ihlIntrusive.m_hash.m_buckets = 0;
  v1->used_table_m.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  v1->used_table_m.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  v1->used_table_m.m_ihlIntrusive.m_hash.m_numElements = 0;
}
// 7E1EF4: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char);
// 7E1EF8: using guessed type int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char);
// 7FDC4C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable)(void *, char);

//----- (00675E50) --------------------------------------------------------  // acclient.c:652403
void __thiscall LRU_List::Mark_Deleted(LRU_List *this, IDClass<_tagDataID,32,0> target_did)
{
  LRU_List *v2; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::remove(
         (IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *)&this->used_table_m,
         (UIObject *const *)&target_did);
  if ( v3 )
    operator delete(v3);
  HashSet<IDClass<_tagDataID,32,0>>::add(&v2->dead_table_m, &target_did);
}

//----- (00675E90) --------------------------------------------------------  // acclient.c:652418
bool __thiscall LRU_List::Write_All_Out(LRU_List *this)
{
  LRU_List *v1; // edi@1
  LRUB_Mem_t *v2; // eax@1
  unsigned int *v3; // ebx@1
  int v4; // ecx@2
  int v5; // eax@2
  DLListData *v6; // eax@4
  DLListData *v7; // ecx@5
  DLListData *v8; // ecx@7
  DLListData *v9; // ecx@11
  int v10; // edx@15
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData **v11; // eax@15
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v12; // ecx@15
  int v13; // ebp@15
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v14; // eax@15
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v15; // edx@21
  IDClass<_tagDataID,32,0> v16; // esi@26
  LRUB_Mem_t *v17; // eax@26
  LRUB_Info_t *v18; // ecx@26
  LRUB_Info_t *v19; // ecx@30
  IDClass<_tagDataID,32,0> *v20; // edx@31
  int v21; // ecx@32
  IDClass<_tagDataID,32,0> removed_did; // [sp+8h] [bp-Ch]@26
  int index_was_l; // [sp+Ch] [bp-8h]@2
  int offset_was_l; // [sp+10h] [bp-4h]@2

  v1 = this;
  v2 = this->young_pm;
  v3 = 0;
  if ( v2 )
  {
    v4 = v2->offset_lm;
    v5 = v2->info_pm->used_lm;
    offset_was_l = v4;
    index_was_l = v5;
    while ( v1->used_table_m.m_ihlIntrusive.m_hash.m_numElements > 0 )
    {
      v6 = v1->used_table_m.m_ihlIntrusive.m_list.tail_;
      if ( v6 )
      {
        v7 = v6->dllist_prev;
        if ( v7 )
        {
          v7->dllist_next = v6->dllist_next;
        }
        else
        {
          v8 = v1->used_table_m.m_ihlIntrusive.m_list.head_->dllist_next;
          v1->used_table_m.m_ihlIntrusive.m_list.head_ = v8;
          if ( v8 )
            v8->dllist_prev = 0;
        }
        if ( v6->dllist_next )
        {
          v6->dllist_next->dllist_prev = v6->dllist_prev;
        }
        else
        {
          v9 = v1->used_table_m.m_ihlIntrusive.m_list.tail_->dllist_prev;
          v1->used_table_m.m_ihlIntrusive.m_list.tail_ = v9;
          if ( v9 )
            v9->dllist_next = 0;
        }
        v6->dllist_next = 0;
        v6->dllist_prev = 0;
        if ( v6 )
          v3 = (unsigned int *)&v6[-1];
      }
      v10 = *v3 % v1->used_table_m.m_ihlIntrusive.m_hash.m_numBuckets;
      v11 = v1->used_table_m.m_ihlIntrusive.m_hash.m_buckets;
      v12 = v11[v10];
      v13 = (int)&v11[v10];
      v14 = v11[v10];
      if ( v14 )
      {
        while ( v14->m_hashKey.id != *v3 )
        {
          v14 = v14->m_hashNext;
          if ( !v14 )
            goto LABEL_26;
        }
        if ( v14 )
        {
          if ( v12 == v14 )
            goto LABEL_39;
          do
          {
            v15 = v12;
            v12 = v12->m_hashNext;
          }
          while ( v12 != v14 );
          if ( v15 )
            v15->m_hashNext = v12->m_hashNext;
          else
LABEL_39:
            *(_DWORD *)v13 = v12->m_hashNext;
          --v1->used_table_m.m_ihlIntrusive.m_hash.m_numElements;
        }
      }
LABEL_26:
      v16.id = *v3;
      removed_did.id = *v3;
      operator delete(v3);
      v17 = v1->young_pm;
      v18 = v17->info_pm;
      if ( v18 && v17->DIds_pm && v18->used_lm < v17->max_lm )
      {
        v19 = v17->info_pm;
        if ( v19 )
        {
          v20 = v17->DIds_pm;
          if ( v20 )
          {
            v21 = v19->used_lm;
            if ( v21 < v17->max_lm )
            {
              v20[v21].id = v16.id;
              ++v17->info_pm->used_lm;
            }
          }
        }
      }
      else
      {
        LRU_List::Expand_Trans(v1, v16, 0);
      }
      HashSet<IDClass<_tagDataID,32,0>>::add(&v1->dead_table_m, &removed_did);
      v3 = 0;
    }
    LRU_List::Purge_Duplicates(v1, offset_was_l, index_was_l);
  }
  return 0;
}

//----- (00675FF0) --------------------------------------------------------  // acclient.c:652554
char __thiscall HashList<IDClass<_tagDataID,32,0>,bool,1>::move_to_head(HashList<IDClass<_tagDataID,32,0>,bool,1> *this, IDClass<_tagDataID,32,0> *keyToMove)
{
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[keyToMove->id % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey.id != keyToMove->id )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::place_at_head(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (00676040) --------------------------------------------------------  // acclient.c:652579
char __thiscall IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::push_head(IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *this, HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *val)
{
  IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1> *v2; // esi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v3; // eax@1
  char *v4; // eax@4
  DLListData *v5; // ecx@4
  char result; // al@5

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey.id % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != val->m_hashKey.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    v4 = (char *)&val->dllist_next;
    val->dllist_next = v2->m_list.head_;
    v5 = v2->m_list.head_;
    if ( v5 )
    {
      v5->dllist_prev = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
    else
    {
      v2->m_list.tail_ = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
  }
  return result;
}

//----- (006760C0) --------------------------------------------------------  // acclient.c:652629
char __thiscall HashList<IDClass<_tagDataID,32,0>,bool,1>::push_head(HashList<IDClass<_tagDataID,32,0>,bool,1> *this, IDClass<_tagDataID,32,0> *key, const bool *val)
{
  HashList<IDClass<_tagDataID,32,0>,bool,1> *v3; // edi@1
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[key->id % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != key->id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<IDClass<_tagDataID,32,0>,bool,1>::move_to_head(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = key->id;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_BYTE *)v5 + 16) = *val;
      v6 = (HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::push_head(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (00676160) --------------------------------------------------------  // acclient.c:652683
void __thiscall LRU_List::Mark_Used(LRU_List *this, IDClass<_tagDataID,32,0> target_did)
{
  LRU_List *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1
  LRU_List *v4; // [sp-2h] [bp-4h]@1

  v4 = this;
  v2 = this;
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         &this->dead_table_m.m_intrusiveTable,
         &target_did);
  if ( v3 )
    operator delete(v3);
  BYTE3(v4) = 1;
  HashList<IDClass<_tagDataID,32,0>,bool,1>::push_head(&v2->used_table_m, &target_did, (const bool *)&v4 + 3);
  if ( v2->used_table_m.m_ihlIntrusive.m_hash.m_numElements >= 0x1000 )
    HashList<IDClass<_tagDataID,32,0>,bool,1>::pop_tail(&v2->used_table_m);
}

//----- (00714E60) --------------------------------------------------------  // acclient.c:807781
int sub_714E60()
{
  return atexit(nullsub_84);
}

//----- (00714E70) --------------------------------------------------------  // acclient.c:807787
int _E76_89()
{
  return atexit(nullsub_85);
}

//----- (00714E80) --------------------------------------------------------  // acclient.c:807793
int _E79_84()
{
  return atexit(_E80_81);
}

//----- (00714E90) --------------------------------------------------------  // acclient.c:807799
int sub_714E90()
{
  return atexit(nullsub_87);
}

