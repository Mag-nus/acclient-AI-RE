/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BTree
   Object     : ENGINE\diskcon\BTree.obj
   Functions  : 50
   Addresses  : 00671C50 - 00714E10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00671C50) --------------------------------------------------------  // acclient.c:648365
int __stdcall BTree::ExtractEntryShift(BTMemNode *pNode, int index, BTEntry *pOutEntry)
{
  size_t v4; // ST08_4@3

  if ( pOutEntry )
    qmemcpy(pOutEntry, &pNode->node_m.Entry_[index], 0x18u);
  v4 = 24 * (pNode->node_m.NumEntries_-- - 1 - index);
  _memmove(&pNode->node_m.Entry_[index], &pNode->node_m.Entry_[index + 1], v4);
  if ( pNode->node_m.NextNode_[0] )
    _memmove(
      &pNode->node_m.NextNode_[index + 1],
      &pNode->node_m.NextNode_[index + 2],
      4 * (pNode->node_m.NumEntries_ - index));
  pNode->dirty_fm = 1;
  return 0;
}

//----- (00671CE0) --------------------------------------------------------  // acclient.c:648383
void __stdcall BTree::AddLeast(BTMemNode *pNode, BTEntry *newEntry, int newLink)
{
  int v4; // eax@1

  _memmove(&pNode->node_m.Entry_[1], pNode->node_m.Entry_, 0x2D0u);
  v4 = pNode->node_m.NextNode_[0];
  qmemcpy(pNode->node_m.Entry_, newEntry, 0x18u);
  ++pNode->node_m.NumEntries_;
  if ( v4 )
  {
    _memmove(&pNode->node_m.NextNode_[1], &pNode->node_m, 0x7Cu);
    pNode->node_m.NextNode_[0] = newLink;
  }
}

//----- (00671D50) --------------------------------------------------------  // acclient.c:648399
void __thiscall BTEntry::default_constructor_closure(BTEntry *this)
{
  unsigned int v1; // edx@1

  v1 = stru_8F76D8.id;
  *(_DWORD *)this &= 0xFFFF0000;
  *((_WORD *)this + 1) = 0;
  this->GID_.id = v1;
  this->Offset_ = 0;
  this->size_ = 0;
  this->date_ = 0;
  this->iter_ = 0;
}

//----- (00671D80) --------------------------------------------------------  // acclient.c:648414
char __stdcall BTree::HasEntry(IDClass<_tagDataID,32,0> targetGId, BTMemNode *pNode, int *pOutIndex)
{
  int v4; // eax@1
  char result; // al@2
  int v6; // ecx@3
  char v7; // bl@3
  int v8; // esi@3
  int v9; // eax@3
  unsigned int v10; // edx@4

  v4 = pNode->node_m.NumEntries_;
  if ( v4 <= 61 )
  {
    v6 = v4 - 1;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    if ( v6 < 0 )
      goto LABEL_16;
    do
    {
      v9 = (v6 + v8) / 2;
      v10 = pNode->node_m.Entry_[v9].GID_.id;
      if ( targetGId.id == v10 )
      {
        v7 = 1;
        v8 = v6 + 1;
      }
      else if ( targetGId.id >= v10 )
      {
        v8 = v9 + 1;
      }
      else
      {
        v6 = v9 - 1;
      }
    }
    while ( v8 <= v6 );
    if ( !v7 )
    {
LABEL_16:
      if ( targetGId.id > pNode->node_m.Entry_[v9].GID_.id )
        ++v9;
    }
    *pOutIndex = v9;
    result = v7;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00671E00) --------------------------------------------------------  // acclient.c:648469
BTEntry *__stdcall BTree::RemoveLeast(BTEntry *result, BTMemNode *pNode, int *pOutLink)
{
  int v4; // ecx@1
  BTEntry *v5; // eax@3
  BTEntry toReturn; // [sp+Ch] [bp-18h]@1

  qmemcpy(&toReturn, pNode->node_m.Entry_, sizeof(toReturn));
  *pOutLink = pNode->node_m.NextNode_[0];
  v4 = pNode->node_m.NumEntries_ - 1;
  pNode->node_m.NumEntries_ = v4;
  _memmove(pNode->node_m.Entry_, &pNode->node_m.Entry_[1], 24 * v4);
  if ( pNode->node_m.NextNode_[0] )
    _memmove(&pNode->node_m, &pNode->node_m.NextNode_[1], 4 * pNode->node_m.NumEntries_ + 4);
  v5 = result;
  qmemcpy(result, &toReturn, 0x18u);
  return v5;
}

//----- (00671E90) --------------------------------------------------------  // acclient.c:648488
int __thiscall BTree::UpdateNode(BTree *this, BTMemNode *pTarget, BTMemNode *pParent)
{
  BTree *v3; // edi@1
  Cache_Pack_t buffer; // [sp+8h] [bp-14h]@3

  v3 = this;
  if ( pTarget->dirty_fm )
    pTarget->dirty_fm = 0;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  SmartBuffer::Borrow(&buffer.m_buff, (char *)&pTarget->offset_m, 0x6B8u);
  CLBlockAllocator::Update(v3->pBlkMan_, &buffer, pTarget->offset_m);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return 0;
}

//----- (00671F00) --------------------------------------------------------  // acclient.c:648507
void __thiscall BTree::Restamp_Entry(BTree *this, IDClass<_tagDataID,32,0> gid)
{
  if ( this->file_info_pm->use_lru_fm )
    LRU_List::Mark_Used(this->lru_man_pm, gid);
}

//----- (00671F20) --------------------------------------------------------  // acclient.c:648514
void __thiscall BTNode::BTNode(BTNode *this)
{
  char *v1; // edx@1
  signed int v2; // ebx@1
  unsigned int v3; // edi@2

  this->NumEntries_ = 0;
  v1 = (char *)this->Entry_;
  v2 = 61;
  do
  {
    v3 = stru_8F76D8.id;
    *(_DWORD *)v1 &= 0xFFFF0000;
    *((_WORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 1) = v3;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    *((_DWORD *)v1 + 5) = 0;
    v1 += 24;
    --v2;
  }
  while ( v2 );
  this->NextNode_[0] = 0;
}

//----- (00671F70) --------------------------------------------------------  // acclient.c:648541
void __thiscall BTree::BTree(BTree *this, CLBlockAllocator *allocator)
{
  BTree *v2; // esi@1

  v2 = this;
  this->mem_root_node_m.time_stamp_lm = 0;
  this->mem_root_node_m.dirty_fm = 0;
  this->mem_root_node_m.ahead_pm = 0;
  this->mem_root_node_m.behind_pm = 0;
  this->mem_root_node_m.offset_m = 0;
  BTNode::BTNode(&this->mem_root_node_m.node_m);
  v2->pBlkMan_ = allocator;
  v2->mem_nodes_pm = 0;
  v2->nodesInMem_ = 0;
  v2->file_info_pm = 0;
  v2->lru_man_pm = 0;
  v2->_time_stamp = 1;
}

//----- (00671FC0) --------------------------------------------------------  // acclient.c:648561
void __thiscall BTree::~BTree(BTree *this)
{
  BTree *v1; // esi@1
  BTMemNode *v2; // eax@1
  LRU_List *v3; // edi@3

  v1 = this;
  v2 = this->mem_nodes_pm;
  if ( v2 )
    operator delete[](&v2[-1].node_m.Entry_[60].iter_);
  v3 = v1->lru_man_pm;
  v1->mem_nodes_pm = 0;
  if ( v3 )
  {
    LRU_List::~LRU_List(v3);
    operator delete(v3);
  }
  v1->lru_man_pm = 0;
}

//----- (00672010) --------------------------------------------------------  // acclient.c:648582
int __thiscall BTree::CreateTree(BTree *this, DiskFileInfo_t *pHeaderInfo)
{
  BTree *v2; // edi@1
  signed int v3; // ebp@1
  void *v4; // eax@1
  int v5; // esi@2
  DiskFileInfo_t *v6; // eax@4
  DiskFileInfo_t *v7; // eax@6
  int v8; // ecx@6
  int v9; // esi@6
  LRU_List *v10; // eax@8
  LRU_List *v11; // eax@9
  Cache_Pack_t buffer; // [sp+10h] [bp-14h]@6
  DiskFileInfo_t *pHeaderInfoa; // [sp+28h] [bp+4h]@2

  v2 = this;
  v3 = 100;
  this->file_info_pm = pHeaderInfo;
  this->nodesInMem_ = 100;
  v4 = operator new[](0x2A624u);
  if ( v4 )
  {
    *(_DWORD *)v4 = 100;
    pHeaderInfoa = (DiskFileInfo_t *)((char *)v4 + 4);
    v5 = (int)((char *)v4 + 4);
    do
    {
      *(_DWORD *)v5 = 0;
      *(_BYTE *)(v5 + 4) = 0;
      *(_DWORD *)(v5 + 8) = 0;
      *(_DWORD *)(v5 + 12) = 0;
      *(_DWORD *)(v5 + 16) = 0;
      BTNode::BTNode((BTNode *)(v5 + 20));
      v5 += 1736;
      --v3;
    }
    while ( v3 );
    v6 = pHeaderInfoa;
  }
  else
  {
    v6 = 0;
  }
  v2->mem_nodes_pm = (BTMemNode *)v6;
  v7 = v2->file_info_pm;
  v8 = v7->firstFree_;
  v2->mem_root_node_m.offset_m = v8;
  v7->btreeRoot_ = v8;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  SmartBuffer::Borrow(&buffer.m_buff, (char *)&v2->mem_root_node_m.offset_m, 0x6B8u);
  v9 = CLBlockAllocator::Store_Data(v2->pBlkMan_, &buffer, v2->mem_root_node_m.offset_m);
  if ( !v2->file_info_pm->use_lru_fm )
  {
    if ( v9 )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( !v9 )
  {
    v10 = (LRU_List *)operator new(0x104u);
    if ( v10 )
      LRU_List::LRU_List(v10, v2->pBlkMan_, v2->file_info_pm);
    else
      v11 = 0;
    v2->lru_man_pm = v11;
    if ( !LRU_List::Create_List(v11) )
    {
      v9 = -2;
      goto LABEL_15;
    }
LABEL_14:
    v9 = CLBlockAllocator::SaveFileInfo(v2->pBlkMan_);
  }
LABEL_15:
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return v9;
}

//----- (00672150) --------------------------------------------------------  // acclient.c:648664
int __thiscall BTree::LoadTree(BTree *this, DiskFileInfo_t *pHeaderInfo)
{
  BTree *v2; // edi@1
  signed int v3; // ebp@1
  void *v4; // eax@1
  int v5; // esi@2
  DiskFileInfo_t *v6; // eax@4
  DiskFileInfo_t *v7; // ecx@6
  LRU_List *v8; // eax@10
  LRU_List *v9; // eax@11
  int result; // [sp+10h] [bp-18h]@1
  Cache_Pack_t buffer; // [sp+14h] [bp-14h]@6
  DiskFileInfo_t *pHeaderInfoa; // [sp+2Ch] [bp+4h]@2

  v2 = this;
  v3 = 100;
  result = 0;
  this->file_info_pm = pHeaderInfo;
  this->nodesInMem_ = 100;
  v4 = operator new[](0x2A624u);
  if ( v4 )
  {
    *(_DWORD *)v4 = 100;
    pHeaderInfoa = (DiskFileInfo_t *)((char *)v4 + 4);
    v5 = (int)((char *)v4 + 4);
    do
    {
      *(_DWORD *)v5 = 0;
      *(_BYTE *)(v5 + 4) = 0;
      *(_DWORD *)(v5 + 8) = 0;
      *(_DWORD *)(v5 + 12) = 0;
      *(_DWORD *)(v5 + 16) = 0;
      BTNode::BTNode((BTNode *)(v5 + 20));
      v5 += 1736;
      --v3;
    }
    while ( v3 );
    v6 = pHeaderInfoa;
  }
  else
  {
    v6 = 0;
  }
  v7 = v2->file_info_pm;
  v2->mem_nodes_pm = (BTMemNode *)v6;
  v2->mem_root_node_m.offset_m = v7->btreeRoot_;
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  SmartBuffer::Borrow(&buffer.m_buff, (char *)&v2->mem_root_node_m.offset_m, 0x6B8u);
  if ( !CLBlockAllocator::Load_Data(v2->pBlkMan_, &buffer, v2->mem_root_node_m.offset_m, 0) )
    result = -1;
  if ( v2->file_info_pm->use_lru_fm && !result )
  {
    v8 = (LRU_List *)operator new(0x104u);
    if ( v8 )
      LRU_List::LRU_List(v8, v2->pBlkMan_, v2->file_info_pm);
    else
      v9 = 0;
    v2->lru_man_pm = v9;
    if ( !LRU_List::Load_List(v9) )
      result = -1;
  }
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return result;
}

//----- (00672280) --------------------------------------------------------  // acclient.c:648733
int __thiscall BTree::SaveDataToFile(BTree *this)
{
  BTree *v1; // esi@1
  int v2; // ebx@3
  int v3; // edi@4
  int v4; // eax@5
  DiskFileInfo_t *v5; // eax@9
  int v6; // ecx@9
  int v7; // edi@11

  v1 = this;
  if ( this->file_info_pm->use_lru_fm )
    LRU_List::Write_All_Out(this->lru_man_pm);
  v2 = 0;
  if ( v1->nodesInMem_ > 0 )
  {
    v3 = 0;
    do
    {
      v4 = (int)&v1->mem_nodes_pm[v3].time_stamp_lm;
      if ( *(_DWORD *)(v4 + 16) && *(_BYTE *)(v4 + 4) )
        BTree::UpdateNode(v1, (BTMemNode *)v4, 0);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->nodesInMem_ );
  }
  v5 = v1->file_info_pm;
  v6 = v1->mem_root_node_m.offset_m;
  if ( v5->btreeRoot_ != v6 )
    v5->btreeRoot_ = v6;
  v7 = CLBlockAllocator::SaveFileInfo(v1->pBlkMan_);
  CLBlockAllocator::ClearTransaction(v1->pBlkMan_);
  return v7;
}

//----- (00672320) --------------------------------------------------------  // acclient.c:648770
int __thiscall BTree::FindNode(BTree *this, int offset, int *pOutIndex)
{
  BTree *v3; // esi@1
  int result; // eax@1
  int v5; // ebp@1
  int v6; // edi@6
  BTMemNode *v7; // edx@8
  int v8; // ecx@8
  BTMemNode *v9; // edx@16
  int v10; // edi@16
  int v11; // eax@19
  int oldIndex; // [sp+10h] [bp-1Ch]@1
  int v13; // [sp+14h] [bp-18h]@6
  Cache_Pack_t buffer; // [sp+18h] [bp-14h]@20

  v3 = this;
  result = 0;
  v5 = 0;
  oldIndex = 0;
  if ( offset == this->mem_root_node_m.offset_m )
  {
    if ( pOutIndex )
      *pOutIndex = -1;
    result = (int)this;
  }
  else
  {
    v6 = 0;
    v13 = 0;
    while ( v5 < v3->nodesInMem_ )
    {
      v7 = v3->mem_nodes_pm;
      v8 = (int)&v7[v6].time_stamp_lm;
      if ( offset == v7[v6].offset_m )
      {
        *(_DWORD *)v8 = v3->_time_stamp;
        result = (int)&v7[v6].time_stamp_lm;
        ++v3->_time_stamp;
        if ( pOutIndex )
          *pOutIndex = v5;
      }
      else if ( *(_DWORD *)v8 < *(int *)((char *)&v7->time_stamp_lm + v13) )
      {
        oldIndex = v5;
        v13 = v6 * 1736;
      }
      ++v5;
      ++v6;
      if ( result )
        return result;
    }
    if ( !result )
    {
      v9 = v3->mem_nodes_pm;
      v10 = oldIndex;
      if ( v9[oldIndex].dirty_fm )
        BTree::UpdateNode(v3, &v9[oldIndex], 0);
      if ( offset )
      {
        buffer.m_dwOffset = 0;
        buffer.m_iVersion = 0;
        SmartBuffer::SmartBuffer(&buffer.m_buff);
        SmartBuffer::Borrow(&buffer.m_buff, (char *)&v3->mem_nodes_pm[v10].offset_m, 0x6B8u);
        CLBlockAllocator::Load_Data(v3->pBlkMan_, &buffer, offset, 0);
        v3->mem_nodes_pm[v10].offset_m = offset;
        SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
        SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
      }
      else
      {
        v11 = (int)&v3->mem_nodes_pm[v10].time_stamp_lm;
        *(_DWORD *)v11 = 0;
        *(_BYTE *)(v11 + 4) = 0;
        *(_DWORD *)(v11 + 8) = 0;
        *(_DWORD *)(v11 + 12) = 0;
        *(_DWORD *)(v11 + 16) = 0;
        *(_DWORD *)(v11 + 268) = 0;
        *(_DWORD *)(v11 + 20) = 0;
      }
      result = (int)&v3->mem_nodes_pm[v10].time_stamp_lm;
      *(_DWORD *)result = v3->_time_stamp++;
      if ( pOutIndex )
        *pOutIndex = oldIndex;
    }
  }
  return result;
}

//----- (006724B0) --------------------------------------------------------  // acclient.c:648859
int __thiscall BTree::AllocateEmptyNode(BTree *this)
{
  BTree *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@1
  int *v4; // ebx@1
  Cache_Pack_t buffer; // [sp+Ch] [bp-14h]@1

  v1 = this;
  v2 = BTree::FindNode(this, 0, 0);
  v3 = v2;
  *(_DWORD *)(v2 + 268) = 0;
  *(_DWORD *)(v2 + 16) = v1->file_info_pm->firstFree_;
  v4 = (int *)(v2 + 16);
  buffer.m_dwOffset = 0;
  buffer.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&buffer.m_buff);
  SmartBuffer::Borrow(&buffer.m_buff, (char *)(v3 + 16), 0x6B8u);
  CLBlockAllocator::Store_Data(v1->pBlkMan_, &buffer, *v4);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&buffer.m_buff);
  return v3;
}

//----- (00672540) --------------------------------------------------------  // acclient.c:648884
int __thiscall BTree::SplitNodeExec(BTree *this, SplitNodeTransactInfo *pTrIn)
{
  SplitNodeTransactInfo *v2; // esi@1
  int v3; // edi@1
  BTree *v4; // ebp@1
  int v5; // ebx@1
  int v6; // eax@1
  int v7; // eax@2
  int v8; // ecx@8
  int v9; // eax@10
  const void *v10; // edx@10
  void *v11; // edi@11
  int pNode; // [sp+10h] [bp-10h]@1
  int v14; // [sp+14h] [bp-Ch]@10
  int splitIndex; // [sp+18h] [bp-8h]@1

  v2 = pTrIn;
  v3 = pTrIn->m_nSplitIndex;
  v4 = this;
  splitIndex = pTrIn->m_nSplitIndex;
  v5 = BTree::FindNode(this, pTrIn->m_nParentOffset, 0);
  pNode = BTree::FindNode(v4, *(_DWORD *)(v5 + 4 * v3 + 20), 0);
  v6 = pTrIn->m_nFirstFreeBlock;
  if ( v4->file_info_pm->firstFree_ == v6 )
    v7 = BTree::AllocateEmptyNode(v4);
  else
    v7 = BTree::FindNode(v4, v6, 0);
  if ( *(_DWORD *)(v7 + 268) != 30 )
  {
    qmemcpy((void *)(v7 + 272), (const void *)(pNode + 1016), 0x2D0u);
    if ( *(_DWORD *)(pNode + 20) )
      qmemcpy((void *)(v7 + 20), (const void *)(pNode + 144), 0x7Cu);
    *(_DWORD *)(v7 + 268) = 30;
    BTree::UpdateNode(v4, (BTMemNode *)v7, 0);
    v3 = splitIndex;
    v2 = pTrIn;
  }
  v8 = *(_DWORD *)(v5 + 268);
  if ( v8 == v2->m_nParentEntries )
  {
    if ( v8 > v3 )
    {
      v9 = v5 + 4 * v8 + 24;
      v10 = (const void *)(v5 + 24 * v8 + 272);
      v14 = v8 - v3;
      do
      {
        *(_DWORD *)v9 = *(_DWORD *)(v9 - 4);
        v11 = (void *)v10;
        v10 = (char *)v10 - 24;
        qmemcpy(v11, v10, 0x18u);
        v9 -= 4;
        --v14;
      }
      while ( v14 );
      v3 = splitIndex;
      v2 = pTrIn;
    }
    *(_DWORD *)(v5 + 4 * v3 + 24) = v2->m_nFirstFreeBlock;
    qmemcpy((void *)(v5 + 24 * v3 + 272), (const void *)(pNode + 992), 0x18u);
    ++*(_DWORD *)(v5 + 268);
    BTree::UpdateNode(v4, (BTMemNode *)v5, 0);
  }
  if ( *(_DWORD *)(pNode + 268) != 30 )
  {
    *(_DWORD *)(pNode + 268) = 30;
    BTree::UpdateNode(v4, (BTMemNode *)pNode, 0);
  }
  return 0;
}

//----- (006726C0) --------------------------------------------------------  // acclient.c:648956
int __thiscall BTree::InsertEntryExec(BTree *this, AddObjectTransactInfo *pTrIn, Cache_Pack_t *pack_buf)
{
  BTree *v3; // esi@1
  int v4; // edi@1
  int v6; // eax@3
  int v7; // ebp@3
  int v8; // eax@9
  int v9; // edx@10
  void *v10; // edi@12
  const void *v11; // esi@12
  int v12; // eax@13
  BTree *v13; // [sp+0h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  v13 = this;
  if ( pTrIn->m_entry.size_ == -2 )
    return -101;
  v6 = BTree::FindNode(this, pTrIn->m_entry.Offset_, 0);
  v7 = v6;
  if ( !v6 )
    return -1;
  if ( *(_DWORD *)(v6 + 20) )
    return -101;
  if ( pTrIn->m_nNodeEntries == *(_DWORD *)(v6 + 268) )
  {
    SmartBuffer::ReconfigureAllocation(&pack_buf->m_buff, 4u, 1u);
    if ( SmartBuffer::GetBuffer(&pack_buf->m_buff) )
    {
      v8 = *(_DWORD *)(v7 + 268) - 1;
      if ( v8 >= 0 )
      {
        v9 = v7 + 24 * v8 + 272;
        do
        {
          if ( pTrIn->m_entry.GID_.id >= *(_DWORD *)(v9 + 4) )
            break;
          v10 = (void *)(v9 + 24);
          v11 = (const void *)v9;
          --v8;
          v9 -= 24;
          qmemcpy(v10, v11, 0x18u);
        }
        while ( v8 >= 0 );
      }
      v12 = v7 + 8 * (3 * v8 + 3);
      qmemcpy((void *)(v12 + 272), &pTrIn->m_entry, 0x18u);
      *(_DWORD *)(v12 + 280) = pTrIn->m_nFirstFreeBlock;
      *(_DWORD *)(v12 + 284) = Cache_Pack_t::GetDataSize(pack_buf);
      ++*(_DWORD *)(v7 + 268);
      v4 = CLBlockAllocator::Store_Data(v13->pBlkMan_, pack_buf, pTrIn->m_nFirstFreeBlock);
      BTree::UpdateNode(v13, (BTMemNode *)v7, 0);
      if ( v13->file_info_pm->use_lru_fm )
      {
        LRU_List::Write_Added(v13->lru_man_pm, pTrIn->m_entry.GID_);
        return v4;
      }
    }
    else
    {
      v4 = CLBlockAllocator::StoreDataRollback(v3->pBlkMan_, pTrIn->m_entry.size_, pTrIn->m_nFirstFreeBlock);
    }
  }
  return v4;
}

//----- (00672830) --------------------------------------------------------  // acclient.c:649023
int __thiscall BTree::UpdateObjectExec(BTree *this, UpdateObjectTransactInfo *pTrIn, Cache_Pack_t *pack_buf)
{
  UpdateObjectTransactInfo *v3; // ebx@1
  BTree *v4; // edi@1
  int v5; // eax@1
  int v6; // ebp@1
  BTMemNode *v7; // esi@1
  int v8; // eax@4
  unsigned int v9; // eax@5
  int v10; // eax@8
  int v11; // ebx@11
  int v12; // esi@11
  int v13; // eax@14
  BTree *v14; // [sp+10h] [bp-10h]@1
  int result; // [sp+14h] [bp-Ch]@1
  BTMemNode *pNode; // [sp+1Ch] [bp-4h]@1
  int pTrIna; // [sp+24h] [bp+4h]@1

  v3 = pTrIn;
  v4 = this;
  v14 = this;
  result = 0;
  v5 = BTree::FindNode(this, pTrIn->m_entry.Offset_, 0);
  v6 = pTrIn->m_nEntryIndex;
  v7 = (BTMemNode *)v5;
  pNode = (BTMemNode *)v5;
  pTrIna = pTrIn->m_nFirstFreeBlock;
  if ( !v5 )
    return -1;
  if ( v3->m_entry.size_ == -2 )
  {
    *(_DWORD *)(v5 + 8 * (3 * v6 + 36)) = v3->m_entry.date_;
    v10 = v5 + 24 * v6;
    *(_DWORD *)(v10 + 292) = v3->m_entry.iter_;
    *(_WORD *)(v10 + 274) = *((_WORD *)&v3->m_entry + 1);
    goto LABEL_9;
  }
  SmartBuffer::ReconfigureAllocation(&pack_buf->m_buff, 4u, 1u);
  if ( SmartBuffer::GetBuffer(&pack_buf->m_buff) )
  {
    v8 = (int)(&v7->time_stamp_lm + 6 * v6);
    qmemcpy((void *)(v8 + 272), &v3->m_entry, 0x18u);
    *(_DWORD *)(v8 + 280) = pTrIna;
    if ( SmartBuffer::GetSize(&pack_buf->m_buff) <= 4 )
      v9 = 0;
    else
      v9 = SmartBuffer::GetSize(&pack_buf->m_buff) - 4;
    v7->node_m.Entry_[v6].size_ = v9;
    v4 = v14;
    v7 = pNode;
    result = CLBlockAllocator::Store_Data(v14->pBlkMan_, pack_buf, pTrIna);
LABEL_9:
    BTree::UpdateNode(v4, v7, 0);
    if ( v4->file_info_pm->use_lru_fm )
      LRU_List::Mark_Used(v4->lru_man_pm, v3->m_entry.GID_);
  }
  v11 = v3->m_nOldOffset;
  v12 = v7->node_m.Entry_[v6].Offset_;
  if ( v12 == v11 )
  {
    v13 = result;
  }
  else
  {
    if ( pTrIna == v12 )
      pTrIna = v11;
    v13 = CLBlockAllocator::DeleteBlocks(
            v4->pBlkMan_,
            pTrIna,
            v4->file_info_pm->finalFree_,
            v4->file_info_pm->iFreeBlocks_,
            1);
  }
  return v13;
}

//----- (006729C0) --------------------------------------------------------  // acclient.c:649100
int __thiscall BTree::MergeNodesExec(BTree *this, MergeNodesTransactInfo *pTrIn)
{
  MergeNodesTransactInfo *v2; // esi@1
  BTree *v3; // ebp@1
  BTMemNode *v4; // edi@1
  int v5; // ST08_4@1
  int v6; // ebx@1
  int v7; // ST08_4@3
  int v8; // edx@4
  unsigned int v9; // ecx@4
  int v10; // eax@4
  int v11; // eax@7
  int v12; // eax@7
  int mem_right_p; // [sp+10h] [bp-28h]@1
  int rightIndex; // [sp+14h] [bp-24h]@1
  int leftIndex; // [sp+18h] [bp-20h]@1
  BTMemNode *mem_node_p; // [sp+1Ch] [bp-1Ch]@1
  BTEntry entry; // [sp+20h] [bp-18h]@3

  v2 = pTrIn;
  v3 = this;
  rightIndex = -1;
  leftIndex = -1;
  v4 = (BTMemNode *)BTree::FindNode(this, pTrIn->m_nNodeOffset, (int *)&pTrIn);
  v5 = v2->m_nLeftOffset;
  mem_node_p = v4;
  v6 = BTree::FindNode(v3, v5, &leftIndex);
  mem_right_p = BTree::FindNode(v3, v2->m_nRightOffset, &rightIndex);
  pTrIn = (MergeNodesTransactInfo *)(mem_right_p + 20);
  if ( v4 != (BTMemNode *)-20 && v4->node_m.NumEntries_ == v2->m_nNodeEntries )
  {
    entry = 0;
    entry.Offset_ = 0;
    entry.size_ = 0;
    entry.date_ = 0;
    entry.iter_ = 0;
    v7 = v2->m_nIndex;
    entry.GID_.id = stru_8F76D8.id;
    BTree::ExtractEntryShift(v4, v7, &entry);
    if ( pTrIn )
    {
      *(_DWORD *)(v6 + 144) = 0;
      qmemcpy((void *)(v6 + 992), &entry, 0x18u);
      ++*(_DWORD *)(v6 + 268);
      v8 = *(_DWORD *)(v6 + 268);
      v9 = 24 * *(_DWORD *)(mem_right_p + 268);
      pTrIn = (MergeNodesTransactInfo *)(mem_right_p + 20);
      qmemcpy((void *)(v6 + 20 + 24 * v8 + 252), (const void *)(mem_right_p + 272), v9);
      qmemcpy((void *)(v6 + 20 + 4 * *(_DWORD *)(v6 + 268)), pTrIn, 4 * pTrIn[7].m_nIndex + 4);
      *(_DWORD *)(v6 + 268) += pTrIn[7].m_nIndex;
      BTree::UpdateNode(v3, (BTMemNode *)v6, 0);
      CLBlockAllocator::DeleteBlocks(
        v3->pBlkMan_,
        *(_DWORD *)(mem_right_p + 16),
        v3->file_info_pm->finalFree_,
        v3->file_info_pm->iFreeBlocks_,
        0);
      v4 = mem_node_p;
      v10 = (int)&v3->mem_nodes_pm[rightIndex].time_stamp_lm;
      *(_DWORD *)v10 = 0;
      *(_BYTE *)(v10 + 4) = 0;
      *(_DWORD *)(v10 + 8) = 0;
      *(_DWORD *)(v10 + 12) = 0;
      *(_DWORD *)(v10 + 16) = 0;
      *(_DWORD *)(v10 + 268) = 0;
      *(_DWORD *)(v10 + 20) = 0;
    }
    if ( &v4->node_m == &v3->mem_root_node_m.node_m && !v3->mem_root_node_m.node_m.NumEntries_ )
    {
      v3->file_info_pm->btreeRoot_ = *(_DWORD *)(v6 + 16);
      CLBlockAllocator::SaveFileInfo(v3->pBlkMan_);
      CLBlockAllocator::DeleteBlocks(
        v3->pBlkMan_,
        v4->offset_m,
        v3->file_info_pm->finalFree_,
        v3->file_info_pm->iFreeBlocks_,
        0);
      v11 = leftIndex;
      qmemcpy(&v3->mem_root_node_m.node_m, (const void *)(v6 + 20), sizeof(v3->mem_root_node_m.node_m));
      v3->mem_root_node_m.offset_m = *(_DWORD *)(v6 + 16);
      v12 = (int)&v3->mem_nodes_pm[v11].time_stamp_lm;
      *(_DWORD *)v12 = 0;
      *(_BYTE *)(v12 + 4) = 0;
      *(_DWORD *)(v12 + 8) = 0;
      *(_DWORD *)(v12 + 12) = 0;
      *(_DWORD *)(v12 + 16) = 0;
      *(_DWORD *)(v12 + 268) = 0;
      *(_DWORD *)(v12 + 20) = 0;
      return 0;
    }
    BTree::UpdateNode(v3, v4, 0);
  }
  return 0;
}

//----- (00672C20) --------------------------------------------------------  // acclient.c:649196
IDClass<_tagDataID,32,0> *__thiscall BTree::FindMin(BTree *this, IDClass<_tagDataID,32,0> *result, BTMemNode *pNode)
{
  BTMemNode *v3; // eax@1
  BTree *v4; // esi@1
  int i; // ecx@1
  unsigned int v6; // ecx@3
  IDClass<_tagDataID,32,0> *v7; // eax@3

  v3 = pNode;
  v4 = this;
  for ( i = pNode->node_m.NextNode_[0]; i; i = v3->node_m.NextNode_[0] )
    v3 = (BTMemNode *)BTree::FindNode(v4, i, 0);
  v6 = v3->node_m.Entry_[0].GID_.id;
  v7 = result;
  result->id = v6;
  return v7;
}

//----- (00672C60) --------------------------------------------------------  // acclient.c:649215
IDClass<_tagDataID,32,0> *__thiscall BTree::FindMax(BTree *this, IDClass<_tagDataID,32,0> *result, BTMemNode *pNode)
{
  BTMemNode *v3; // eax@1
  BTree *i; // esi@1
  unsigned int v5; // edx@3
  IDClass<_tagDataID,32,0> *v6; // eax@3

  v3 = pNode;
  for ( i = this;
        v3->node_m.NextNode_[0];
        v3 = (BTMemNode *)BTree::FindNode(i, v3->node_m.NextNode_[v3->node_m.NumEntries_], 0) )
    ;
  v5 = v3->node_m.NextNode_[6 * v3->node_m.NumEntries_ + 58];
  v6 = result;
  result->id = v5;
  return v6;
}

//----- (00672CB0) --------------------------------------------------------  // acclient.c:649234
int __thiscall BTree::DeleteLeafExec(BTree *this, DeleteLeafTransactInfo *pTrIn)
{
  BTree *v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@1
  BTMemNode *v5; // edi@1
  unsigned int v6; // ebp@2
  int v7; // ecx@2
  int result; // eax@5

  v2 = this;
  v3 = BTree::FindNode(this, pTrIn->m_nNodeOffset, 0);
  v4 = pTrIn->m_nIndex;
  v5 = (BTMemNode *)v3;
  if ( v3 )
  {
    v6 = pTrIn->m_cObjectDID.id;
    v7 = v3 + 24 * v4;
    if ( v6 == *(_DWORD *)(v7 + 276) )
    {
      if ( v2->file_info_pm->use_lru_fm )
      {
        LRU_List::Mark_Deleted(v2->lru_man_pm, (IDClass<_tagDataID,32,0>)v6);
        v7 = (int)(&v5->time_stamp_lm + 6 * v4);
      }
      CLBlockAllocator::DeleteBlocks(
        v2->pBlkMan_,
        *(_DWORD *)(v7 + 280),
        v2->file_info_pm->finalFree_,
        v2->file_info_pm->iFreeBlocks_,
        1);
      BTree::ExtractEntryShift(v5, v4, 0);
      result = BTree::UpdateNode(v2, v5, 0);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (00672D60) --------------------------------------------------------  // acclient.c:649281
int __thiscall BTree::DeleteInternalExec(BTree *this, DeleteInternalTransactInfo *pTrIn)
{
  DeleteInternalTransactInfo *v2; // ebp@1
  BTree *v3; // ebx@1
  int v4; // eax@1
  int v5; // esi@1
  BTMemNode *v6; // edi@1
  unsigned int v7; // edx@3
  int v8; // ecx@3
  unsigned int v9; // eax@3
  int result; // eax@6
  BTMemNode *pTargetNode; // [sp+10h] [bp-10h]@1
  int nDonorIndex; // [sp+18h] [bp-8h]@1
  DeleteInternalTransactInfo *pTrIna; // [sp+24h] [bp+4h]@3

  v2 = pTrIn;
  v3 = this;
  pTargetNode = (BTMemNode *)BTree::FindNode(this, pTrIn->m_nTargetOffset, 0);
  v4 = BTree::FindNode(v3, pTrIn->m_nDonorOffset, 0);
  v5 = pTrIn->m_nDonorIndex;
  v6 = (BTMemNode *)v4;
  nDonorIndex = pTrIn->m_nDonorIndex;
  if ( pTargetNode && v4 )
  {
    v7 = pTargetNode->node_m.Entry_[pTrIn->m_nTargetIndex].GID_.id;
    v8 = (int)(&pTargetNode->time_stamp_lm + 6 * pTrIn->m_nTargetIndex);
    v9 = pTrIn->m_cTargetDID.id;
    pTrIna = (DeleteInternalTransactInfo *)((char *)pTargetNode + 24 * pTrIn->m_nTargetIndex);
    if ( v9 == v7 )
    {
      if ( v3->file_info_pm->use_lru_fm )
      {
        LRU_List::Mark_Deleted(v3->lru_man_pm, (IDClass<_tagDataID,32,0>)v9);
        v8 = (int)pTrIna;
      }
      CLBlockAllocator::DeleteBlocks(
        v3->pBlkMan_,
        *(_DWORD *)(v8 + 280),
        v3->file_info_pm->finalFree_,
        v3->file_info_pm->iFreeBlocks_,
        1);
      qmemcpy(&pTrIna[7].m_nTargetOffset, &v6->node_m.Entry_[v5], 0x18u);
      result = BTree::UpdateNode(v3, pTargetNode, 0);
      v5 = nDonorIndex;
    }
    else
    {
      result = 0;
    }
    if ( v2->m_cDonorDID.id == v6->node_m.Entry_[v5].GID_.id )
    {
      BTree::ExtractEntryShift(v6, v5, 0);
      result = BTree::UpdateNode(v3, v6, 0);
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (00672E80) --------------------------------------------------------  // acclient.c:649344
int __thiscall BTree::RotateEntryExec(BTree *this, RotateEntryTransactInfo *pTrIn)
{
  RotateEntryTransactInfo *v2; // ebp@1
  int v3; // ebx@1
  BTree *v4; // esi@1
  int v5; // ST04_4@1
  int v6; // edi@1
  int v7; // ST04_4@1
  int v8; // edx@2
  int v9; // ecx@4
  int v10; // eax@6
  int v11; // ecx@6
  BTEntry *v12; // esi@6
  BTEntry *v13; // eax@7
  BTMemNode *v14; // eax@8
  int v15; // edx@11
  BTMemNode *v16; // ebx@11
  char *v17; // edx@11
  int v18; // edx@11
  int v19; // edx@14
  BTree *v21; // [sp+10h] [bp-58h]@1
  int swapOffset; // [sp+14h] [bp-54h]@6
  BTMemNode *pParent; // [sp+18h] [bp-50h]@1
  BTMemNode *pNode; // [sp+1Ch] [bp-4Ch]@1
  BTEntry ParentEntry; // [sp+20h] [bp-48h]@6
  BTEntry SiblingEntry; // [sp+38h] [bp-30h]@8
  BTEntry result; // [sp+50h] [bp-18h]@7
  int pTrIna; // [sp+6Ch] [bp+4h]@2

  v2 = pTrIn;
  v3 = pTrIn->m_nIndex;
  v4 = this;
  v5 = pTrIn->m_nParentOffset;
  v21 = this;
  pNode = 0;
  v6 = BTree::FindNode(this, v5, 0);
  v7 = *(_DWORD *)(v6 + 4 * v3 + 20);
  pParent = (BTMemNode *)v6;
  pNode = (BTMemNode *)BTree::FindNode(v4, v7, 0);
  if ( pTrIn->m_bLeftSibling )
  {
    v8 = BTree::FindNode(v4, *(_DWORD *)(v6 + 4 * v3 + 16), 0);
    pTrIna = v8;
  }
  else
  {
    pTrIna = BTree::FindNode(v4, *(_DWORD *)(v6 + 4 * v3 + 24), 0);
    v8 = pTrIna;
  }
  v9 = *(_DWORD *)(v8 + 268);
  if ( v2->m_nSiblingEntryCount == v9 )
  {
    if ( v2->m_bLeftSibling )
    {
      v10 = *(_DWORD *)(v8 + 4 * v9 + 20);
      v11 = v9 - 1;
      *(_DWORD *)(v8 + 268) = v11;
      qmemcpy(&ParentEntry, (const void *)(v8 + 24 * v11 + 272), sizeof(ParentEntry));
      swapOffset = v10;
      v12 = &ParentEntry;
    }
    else
    {
      v13 = BTree::RemoveLeast(&result, (BTMemNode *)v8, &swapOffset);
      v8 = pTrIna;
      v12 = v13;
    }
    v14 = pParent;
    qmemcpy(&SiblingEntry, v12, sizeof(SiblingEntry));
    if ( v2->m_cEntryDID.id == pParent->node_m.Entry_[v3].GID_.id )
    {
      if ( v2->m_bLeftSibling )
        --v3;
      v15 = 3 * v3;
      v16 = pNode;
      v17 = (char *)&pParent->node_m.Entry_[8 * v15 / 0x18u];
      qmemcpy(&ParentEntry, v17, sizeof(ParentEntry));
      qmemcpy(v17, &SiblingEntry, 0x18u);
      v18 = v16->node_m.NumEntries_;
      if ( v2->m_nNodeEntryCount == v18 )
      {
        if ( v2->m_bLeftSibling )
        {
          BTree::AddLeast(v16, &ParentEntry, swapOffset);
        }
        else
        {
          v16->node_m.NumEntries_ = v18 + 1;
          v19 = swapOffset;
          qmemcpy(&v16->node_m.Entry_[30], &ParentEntry, sizeof(v16->node_m.Entry_[30]));
          v16->node_m.NextNode_[31] = v19;
        }
        BTree::UpdateNode(v21, v16, 0);
        v14 = pParent;
      }
      BTree::UpdateNode(v21, v14, 0);
      v8 = pTrIna;
    }
    BTree::UpdateNode(v21, (BTMemNode *)v8, 0);
  }
  return -1;
}

//----- (00673020) --------------------------------------------------------  // acclient.c:649448
int __thiscall BTree::RecoverTransaction(BTree *this, DiskTransactInfo *pTrIn)
{
  BTree *v2; // edi@1
  signed int v3; // esi@1
  AddObjectTransactInfo *v4; // eax@2
  int v5; // eax@2
  DeleteLeafTransactInfo *v7; // eax@6
  DeleteInternalTransactInfo *v8; // eax@7
  MergeNodesTransactInfo *v9; // eax@8
  UpdateObjectTransactInfo *v10; // eax@9
  SplitNodeTransactInfo *v11; // eax@10
  RotateEntryTransactInfo *v12; // eax@11
  Cache_Pack_t empty_buf; // [sp+8h] [bp-14h]@1

  v2 = this;
  v3 = 0;
  empty_buf.m_dwOffset = 0;
  empty_buf.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&empty_buf.m_buff);
  switch ( pTrIn->m_eTransactType )
  {
    case 1:
      v4 = (AddObjectTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap4[0])();
      v5 = BTree::InsertEntryExec(v2, v4, &empty_buf);
      goto LABEL_3;
    case 0:
      break;
    case 2:
      v7 = (DeleteLeafTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap4[8])();
      v5 = BTree::DeleteLeafExec(v2, v7);
      goto LABEL_3;
    case 3:
      v8 = (DeleteInternalTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap14[0])();
      v5 = BTree::DeleteInternalExec(v2, v8);
      goto LABEL_3;
    case 4:
      v9 = (MergeNodesTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap1C[0])();
      v5 = BTree::MergeNodesExec(v2, v9);
      goto LABEL_3;
    case 5:
      v10 = (UpdateObjectTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap24[0])();
      v5 = BTree::UpdateObjectExec(v2, v10, &empty_buf);
      goto LABEL_3;
    case 6:
      v11 = (SplitNodeTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap2C[0])();
      v5 = BTree::SplitNodeExec(v2, v11);
      goto LABEL_3;
    case 7:
      v12 = (RotateEntryTransactInfo *)(*(int (**)(void))&pTrIn->vfptr->gap34[0])();
      v5 = BTree::RotateEntryExec(v2, v12);
LABEL_3:
      v3 = v5;
      if ( !v5 )
        CLBlockAllocator::ClearTransaction(v2->pBlkMan_);
      break;
    default:
      v3 = -103;
      break;
  }
  SmartBuffer::ReleaseMasterBuffer(&empty_buf.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&empty_buf.m_buff);
  return v3;
}

//----- (00673120) --------------------------------------------------------  // acclient.c:649513
void __thiscall SmartArray<BTEntry,1>::Reset(SmartArray<BTEntry,1> *this)
{
  SmartArray<BTEntry,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // ecx@6
  int v6; // eax@7
  int v7; // edx@7
  void *v8; // edi@8
  int v9; // [sp+8h] [bp-18h]@7
  unsigned int v10; // [sp+Ch] [bp-14h]@8
  int v11; // [sp+10h] [bp-10h]@7
  int v12; // [sp+14h] [bp-Ch]@7
  int v13; // [sp+18h] [bp-8h]@7
  int v14; // [sp+1Ch] [bp-4h]@7

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      operator delete[](&v1->m_data[-1].iter_);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v9 = 0;
      v11 = 0;
      v12 = 0;
      v13 = 0;
      v14 = 0;
      v6 = v4;
      v7 = v5 + 1;
      do
      {
        v8 = &v1->m_data[v6];
        v10 = stru_8F76D8.id;
        --v6;
        --v7;
        qmemcpy(v8, &v9, 0x18u);
      }
      while ( v7 );
    }
  }
}

//----- (006731C0) --------------------------------------------------------  // acclient.c:649568
BTEntry *__thiscall BTree::Search(BTree *this, BTMemNode *pNode, IDClass<_tagDataID,32,0> GId, BTMemNode **ppNode)
{
  BTMemNode **v4; // ebp@1
  BTEntry *result; // eax@1
  BTree *v6; // edi@1
  BTMemNode *v7; // esi@3

  v4 = ppNode;
  result = 0;
  v6 = this;
  if ( ppNode )
    *ppNode = 0;
  v7 = pNode;
  if ( pNode )
  {
    while ( !BTree::HasEntry(GId, v7, (int *)&ppNode) )
    {
      if ( v7->node_m.NextNode_[0] )
      {
        v7 = (BTMemNode *)BTree::FindNode(v6, v7->node_m.NextNode_[(_DWORD)ppNode], 0);
        if ( v7 )
          continue;
      }
      return 0;
    }
    if ( v4 )
      *v4 = v7;
    result = &v7->node_m.Entry_[(_DWORD)ppNode];
  }
  return result;
}

//----- (00673240) --------------------------------------------------------  // acclient.c:649601
int __thiscall BTree::SplitNodeTrans(BTree *this, BTMemNode *pParent, int splitIndex, BTMemNode *pNode)
{
  BTree *v4; // esi@1
  int v5; // edx@1
  DiskFileInfo_t *v6; // ecx@1
  int v7; // edx@1
  CLBlockAllocator *v8; // ecx@1
  SplitNodeTransactInfo TrIn; // [sp+4h] [bp-1Ch]@1

  v4 = this;
  SplitNodeTransactInfo::SplitNodeTransactInfo(&TrIn);
  v5 = pParent->node_m.NumEntries_;
  TrIn.m_nParentOffset = pParent->offset_m;
  v6 = v4->file_info_pm;
  TrIn.m_nSplitIndex = splitIndex;
  TrIn.m_nParentEntries = v5;
  v7 = v6->firstFree_;
  v8 = v4->pBlkMan_;
  TrIn.m_nFirstFreeBlock = v7;
  CLBlockAllocator::SaveTransaction(v8, (DiskTransactInfo *)&TrIn.vfptr);
  BTree::SplitNodeExec(v4, &TrIn);
  return CLBlockAllocator::ClearTransaction(v4->pBlkMan_);
}

//----- (006732B0) --------------------------------------------------------  // acclient.c:649626
int __thiscall BTree::InsertEntryTrans(BTree *this, BTMemNode *pNode, BTEntry *entry, Cache_Pack_t *pack_buf)
{
  BTree *v4; // ebx@1
  DiskFileInfo_t *v5; // eax@1
  int v6; // ecx@1
  int v7; // eax@1
  CLBlockAllocator *v8; // ecx@1
  AddObjectTransactInfo TrIn; // [sp+Ch] [bp-2Ch]@1

  v4 = this;
  AddObjectTransactInfo::AddObjectTransactInfo(&TrIn);
  v5 = v4->file_info_pm;
  qmemcpy(&TrIn.m_entry, entry, sizeof(TrIn.m_entry));
  v6 = v5->firstFree_;
  v7 = pNode->node_m.NumEntries_;
  TrIn.m_nFirstFreeBlock = v6;
  v8 = v4->pBlkMan_;
  TrIn.m_nNodeEntries = v7;
  CLBlockAllocator::SaveTransaction(v8, (DiskTransactInfo *)&TrIn.vfptr);
  BTree::InsertEntryExec(v4, &TrIn, pack_buf);
  return CLBlockAllocator::ClearTransaction(v4->pBlkMan_);
}

//----- (00673320) --------------------------------------------------------  // acclient.c:649650
int __thiscall BTree::Update_Data_Trans(BTree *this, BTMemNode *pNode, BTEntry *entry, Cache_Pack_t *pack_buf)
{
  BTMemNode *v4; // ebp@1
  BTEntry *v5; // esi@1
  BTree *v6; // ebx@1
  DiskFileInfo_t *v7; // ecx@1
  int v8; // edx@1
  CLBlockAllocator *v9; // ecx@1
  UpdateObjectTransactInfo transact; // [sp+10h] [bp-34h]@1

  v4 = pNode;
  v5 = entry;
  v6 = this;
  BTree::HasEntry(entry->GID_, pNode, (int *)&pNode);
  UpdateObjectTransactInfo::UpdateObjectTransactInfo(&transact);
  qmemcpy(&transact.m_entry, v5, sizeof(transact.m_entry));
  v7 = v6->file_info_pm;
  transact.m_nEntryIndex = (int)pNode;
  transact.m_nOldOffset = v4->node_m.Entry_[(_DWORD)pNode].Offset_;
  v8 = v7->firstFree_;
  v9 = v6->pBlkMan_;
  transact.m_nFirstFreeBlock = v8;
  CLBlockAllocator::SaveTransaction(v9, (DiskTransactInfo *)&transact.vfptr);
  BTree::UpdateObjectExec(v6, &transact, pack_buf);
  return CLBlockAllocator::ClearTransaction(v6->pBlkMan_);
}

//----- (006733B0) --------------------------------------------------------  // acclient.c:649678
int __thiscall BTree::DescendToAdd(BTree *this, BTEntry *entry, Cache_Pack_t *pack_buf)
{
  BTree *v3; // ebx@1
  bool v4; // zf@1
  BTEntry *v5; // esi@1
  unsigned int v6; // ecx@1
  BTree *v7; // edi@1
  int v8; // eax@2
  DiskFileInfo_t *v9; // ecx@2
  int v10; // edx@2
  BTMemNode *pNewNode; // ST24_4@2
  int v12; // esi@6
  int v13; // eax@7
  int v14; // eax@10
  int v15; // esi@10
  int v16; // eax@10
  int v17; // edx@11
  DiskFileInfo_t *v18; // eax@11
  unsigned int v19; // eax@17
  int pNode; // [sp+10h] [bp-6F0h]@10
  unsigned int GId; // [sp+14h] [bp-6ECh]@1
  SplitNodeTransactInfo pTrIn; // [sp+1Ch] [bp-6E4h]@11
  BTMemNode temp; // [sp+38h] [bp-6C8h]@2

  v3 = this;
  v4 = this->mem_root_node_m.node_m.NumEntries_ == 61;
  v5 = entry;
  v6 = entry->GID_.id;
  v7 = v3;
  GId = entry->GID_.id;
  if ( v4 )
  {
    v8 = BTree::AllocateEmptyNode(v3);
    qmemcpy(&temp, v3, sizeof(temp));
    qmemcpy(v3, (const void *)v8, 0x6C8u);
    qmemcpy((void *)v8, &temp, 0x6C8u);
    v9 = v3->file_info_pm;
    v10 = v3->mem_root_node_m.offset_m;
    pNewNode = (BTMemNode *)v8;
    v3->mem_root_node_m.node_m.NextNode_[0] = *(_DWORD *)(v8 + 16);
    v9->btreeRoot_ = v10;
    CLBlockAllocator::SaveFileInfo(v3->pBlkMan_);
    BTree::SplitNodeTrans(v3, &v3->mem_root_node_m, 0, pNewNode);
    v6 = GId;
    v5 = entry;
    v7 = v3;
  }
  if ( v3->mem_root_node_m.node_m.NextNode_[0] )
  {
    while ( 1 )
    {
      v12 = v7->mem_root_node_m.node_m.NumEntries_ - 1;
      if ( v12 >= 0 )
      {
        v13 = (int)&v7->mem_root_node_m.node_m.Entry_[v12].GID_;
        do
        {
          if ( v6 >= *(_DWORD *)v13 )
            break;
          --v12;
          v13 -= 24;
        }
        while ( v12 >= 0 );
      }
      v14 = v7->mem_root_node_m.node_m.NextNode_[v12 + 1];
      v15 = v12 + 1;
      v16 = BTree::FindNode(v3, v14, 0);
      pNode = v16;
      if ( *(_DWORD *)(v16 + 268) == 61 )
      {
        SplitNodeTransactInfo::SplitNodeTransactInfo(&pTrIn);
        v17 = v7->mem_root_node_m.node_m.NumEntries_;
        v18 = v3->file_info_pm;
        pTrIn.m_nParentOffset = v7->mem_root_node_m.offset_m;
        pTrIn.m_nParentEntries = v17;
        pTrIn.m_nSplitIndex = v15;
        pTrIn.m_nFirstFreeBlock = v18->firstFree_;
        CLBlockAllocator::SaveTransaction(v3->pBlkMan_, (DiskTransactInfo *)&pTrIn.vfptr);
        BTree::SplitNodeExec(v3, &pTrIn);
        CLBlockAllocator::ClearTransaction(v3->pBlkMan_);
        if ( GId > v7->mem_root_node_m.node_m.Entry_[v15].GID_.id )
          pNode = BTree::FindNode(v3, v7->mem_root_node_m.node_m.NextNode_[v15 + 1], 0);
        v16 = pNode;
      }
      v7 = (BTree *)v16;
      if ( !*(_DWORD *)(v16 + 20) )
        break;
      v6 = GId;
    }
    v5 = entry;
  }
  v5->Offset_ = v7->mem_root_node_m.offset_m;
  if ( SmartBuffer::GetSize(&pack_buf->m_buff) <= 4 )
    v19 = 0;
  else
    v19 = SmartBuffer::GetSize(&pack_buf->m_buff) - 4;
  v5->size_ = v19;
  return BTree::InsertEntryTrans(v3, &v7->mem_root_node_m, v5, pack_buf);
}

//----- (00673560) --------------------------------------------------------  // acclient.c:649779
int __thiscall BTree::MergeNodesTrans(BTree *this, BTMemNode *pNode, BTMemNode *pLeftKid, BTMemNode *pRightKid, int index)
{
  BTree *v5; // esi@1
  int v6; // eax@1
  CLBlockAllocator *v7; // ecx@1
  int result; // eax@1
  MergeNodesTransactInfo transact; // [sp+4h] [bp-20h]@1

  v5 = this;
  MergeNodesTransactInfo::MergeNodesTransactInfo(&transact);
  v6 = pNode->node_m.NumEntries_;
  transact.m_nNodeOffset = pNode->offset_m;
  transact.m_nLeftOffset = pLeftKid->offset_m;
  transact.m_nRightOffset = pRightKid->offset_m;
  v7 = v5->pBlkMan_;
  transact.m_nIndex = index;
  transact.m_nNodeEntries = v6;
  result = CLBlockAllocator::SaveTransaction(v7, (DiskTransactInfo *)&transact.vfptr);
  if ( !result )
  {
    result = BTree::MergeNodesExec(v5, &transact);
    if ( !result )
      result = CLBlockAllocator::ClearTransaction(v5->pBlkMan_);
  }
  return result;
}

//----- (006735E0) --------------------------------------------------------  // acclient.c:649807
int __thiscall BTree::DeleteLeafTrans(BTree *this, BTMemNode *pNode, int index)
{
  BTree *v3; // esi@1
  int v4; // ecx@1
  CLBlockAllocator *v5; // ecx@1
  DeleteLeafTransactInfo transact; // [sp+4h] [bp-18h]@1

  v3 = this;
  DeleteLeafTransactInfo::DeleteLeafTransactInfo(&transact);
  v4 = pNode->offset_m;
  transact.m_cObjectDID.id = pNode->node_m.Entry_[index].GID_.id;
  transact.m_nNodeOffset = v4;
  v5 = v3->pBlkMan_;
  transact.m_nIndex = index;
  CLBlockAllocator::SaveTransaction(v5, (DiskTransactInfo *)&transact.vfptr);
  BTree::DeleteLeafExec(v3, &transact);
  return CLBlockAllocator::ClearTransaction(v3->pBlkMan_);
}

//----- (00673640) --------------------------------------------------------  // acclient.c:649827
int __thiscall BTree::DeleteInternalTrans(BTree *this, IDClass<_tagDataID,32,0> targetGId, IDClass<_tagDataID,32,0> donorGId, int targetOffset, int donorOffset, int targetIndex, int donorIndex)
{
  BTree *v7; // esi@1
  CLBlockAllocator *v8; // ecx@1
  DeleteInternalTransactInfo transact; // [sp+4h] [bp-24h]@1

  v7 = this;
  DeleteInternalTransactInfo::DeleteInternalTransactInfo(&transact);
  transact.m_cTargetDID.id = targetGId.id;
  transact.m_cDonorDID.id = donorGId.id;
  transact.m_nDonorOffset = donorOffset;
  transact.m_nTargetOffset = targetOffset;
  transact.m_nTargetIndex = targetIndex;
  v8 = v7->pBlkMan_;
  transact.m_nDonorIndex = donorIndex;
  CLBlockAllocator::SaveTransaction(v8, (DiskTransactInfo *)&transact.vfptr);
  BTree::DeleteInternalExec(v7, &transact);
  return CLBlockAllocator::ClearTransaction(v7->pBlkMan_);
}

//----- (006736B0) --------------------------------------------------------  // acclient.c:649848
int __thiscall BTree::RotateEntryTrans(BTree *this, BTMemNode *pParent, int index, int nodeEntryCount, int siblingEntryCount, bool fLeftSibling)
{
  BTree *v6; // esi@1
  CLBlockAllocator *v7; // ecx@1
  RotateEntryTransactInfo TrIn; // [sp+4h] [bp-24h]@1

  v6 = this;
  RotateEntryTransactInfo::RotateEntryTransactInfo(&TrIn);
  TrIn.m_nParentOffset = pParent->offset_m;
  TrIn.m_cEntryDID.id = pParent->node_m.Entry_[index].GID_.id;
  TrIn.m_nNodeEntryCount = nodeEntryCount;
  TrIn.m_nIndex = index;
  TrIn.m_bLeftSibling = fLeftSibling;
  v7 = v6->pBlkMan_;
  TrIn.m_nSiblingEntryCount = siblingEntryCount;
  CLBlockAllocator::SaveTransaction(v7, (DiskTransactInfo *)&TrIn.vfptr);
  BTree::RotateEntryExec(v6, &TrIn);
  return CLBlockAllocator::ClearTransaction(v6->pBlkMan_);
}

//----- (00673730) --------------------------------------------------------  // acclient.c:649869
char __thiscall SmartArray<BTEntry,1>::grow(SmartArray<BTEntry,1> *this, unsigned int i_nSize)
{
  SmartArray<BTEntry,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  int v6; // ebp@6
  int v7; // ecx@8
  int v8; // eax@9
  unsigned int v9; // edx@9
  const void *v10; // esi@10
  void *v11; // edi@10

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<BTEntry,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](24 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x18u,
        i_nSize,
        (void *(__thiscall *)(void *))BTEntry::default_constructor_closure);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            v9 = v2->m_num;
            do
            {
              v10 = &v2->m_data[v8];
              v11 = (void *)(v8 * 24 + v6);
              --v8;
              --v9;
              qmemcpy(v11, v10, 0x18u);
            }
            while ( v9 );
            v3 = i_nSize;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              operator delete[](&v2->m_data[-1].iter_);
          }
        }
        v2->m_data = (BTEntry *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00673800) --------------------------------------------------------  // acclient.c:649938
BTEntry *__thiscall BTree::Lookup(BTree *this, IDClass<_tagDataID,32,0> id, BTMemNode **ppNode)
{
  BTEntry *result; // eax@3

  if ( stru_8F76D8.id != id.id && this->mem_root_node_m.node_m.NumEntries_ )
    result = BTree::Search(this, &this->mem_root_node_m, id, ppNode);
  else
    result = 0;
  return result;
}

//----- (00673830) --------------------------------------------------------  // acclient.c:649950
int __thiscall BTree::DescendToDelete(BTree *this, BTMemNode *pStartNode, IDClass<_tagDataID,32,0> targetGId, BTMemNode **ppOutNode, int *pOutIndex)
{
  BTMemNode *v5; // esi@1
  BTree *v6; // ebp@1
  int result; // eax@1
  bool v8; // zf@1
  int v9; // edi@4
  int v10; // ebx@4
  int v11; // edx@6
  int v12; // ecx@6
  BTMemNode *v13; // eax@10
  int v14; // ecx@10
  int v15; // eax@22
  int index; // [sp+8h] [bp-8h]@1
  BTMemNode *mem_right_p; // [sp+Ch] [bp-4h]@1
  BTMemNode *pStartNodea; // [sp+14h] [bp+4h]@1

  v5 = pStartNode;
  v6 = this;
  result = -1;
  v8 = pStartNode == 0;
  pStartNodea = 0;
  mem_right_p = 0;
  index = -1;
  if ( !v8 )
  {
    while ( 1 )
    {
      if ( BTree::HasEntry(targetGId, v5, &index) )
      {
        v15 = index;
        *ppOutNode = v5;
        *pOutIndex = v15;
        return 0;
      }
      if ( !v5->node_m.NextNode_[0] )
      {
        *ppOutNode = 0;
        *pOutIndex = -1;
        return -1;
      }
      v9 = index;
      v10 = BTree::FindNode(v6, v5->node_m.NextNode_[index], 0);
      if ( *(_DWORD *)(v10 + 268) < 31 )
      {
        if ( v9 <= 0 )
        {
          v11 = (int)pStartNodea;
        }
        else
        {
          v11 = BTree::FindNode(v6, *(&v5->offset_m + v9), 0);
          v12 = *(_DWORD *)(v11 + 268);
          pStartNodea = (BTMemNode *)v11;
          if ( v12 >= 31 )
          {
            BTree::RotateEntryTrans(v6, v5, v9, *(_DWORD *)(v10 + 268), v12, 1);
            goto LABEL_20;
          }
        }
        if ( v5->node_m.NumEntries_ <= v9 )
        {
          v13 = mem_right_p;
LABEL_14:
          if ( v13 && v5->node_m.NumEntries_ > v9 )
          {
            BTree::MergeNodesTrans(v6, v5, (BTMemNode *)v10, v13, v9);
          }
          else if ( v11 )
          {
            if ( v9 > 0 )
            {
              BTree::MergeNodesTrans(v6, v5, (BTMemNode *)v11, (BTMemNode *)v10, v9 - 1);
              v10 = (int)pStartNodea;
            }
          }
          goto LABEL_20;
        }
        v13 = (BTMemNode *)BTree::FindNode(v6, v5->node_m.NextNode_[v9 + 1], 0);
        v14 = v13->node_m.NumEntries_;
        mem_right_p = v13;
        if ( v14 < 31 )
        {
          v11 = (int)pStartNodea;
          goto LABEL_14;
        }
        BTree::RotateEntryTrans(v6, v5, v9, *(_DWORD *)(v10 + 268), v14, 0);
      }
LABEL_20:
      v5 = (BTMemNode *)v10;
      if ( !v10 )
        return -1;
    }
  }
  return result;
}

//----- (006739B0) --------------------------------------------------------  // acclient.c:650048
int __thiscall BTree::Delete(BTree *this, IDClass<_tagDataID,32,0> targetGId, BTMemNode *mem_start_p)
{
  BTree *v3; // esi@1
  int v4; // edi@1
  BTMemNode *v5; // edi@2
  int v7; // ebx@4
  int v8; // eax@4
  BTMemNode *v9; // ebp@4
  bool v10; // sf@4
  unsigned __int8 v11; // of@4
  int v12; // eax@6
  BTMemNode *v13; // ebp@6
  int v14; // ST14_4@8
  BTMemNode *v15; // ebx@8
  int proIndex; // [sp+10h] [bp-10h]@1
  BTMemNode *mem_kid_p; // [sp+14h] [bp-Ch]@1
  int index; // [sp+18h] [bp-8h]@1
  BTMemNode *mem_node_p; // [sp+1Ch] [bp-4h]@1

  index = -1;
  proIndex = -1;
  v3 = this;
  mem_node_p = 0;
  mem_kid_p = 0;
  v4 = BTree::DescendToDelete(this, mem_start_p, targetGId, &mem_node_p, &index);
  if ( v4 )
  {
    if ( v3->file_info_pm->use_lru_fm )
      LRU_List::Mark_Deleted(v3->lru_man_pm, targetGId);
  }
  else
  {
    v5 = mem_node_p;
    if ( !mem_node_p->node_m.NextNode_[0] )
      return BTree::DeleteLeafTrans(v3, mem_node_p, index);
    v7 = index;
    v8 = BTree::FindNode(v3, mem_node_p->node_m.NextNode_[index], 0);
    v9 = (BTMemNode *)v8;
    v11 = __OFSUB__(*(_DWORD *)(v8 + 268), 31);
    v10 = *(_DWORD *)(v8 + 268) - 31 < 0;
    mem_start_p = (BTMemNode *)v8;
    if ( !(v10 ^ v11) )
    {
      mem_start_p = (BTMemNode *)BTree::FindMax(v3, (IDClass<_tagDataID,32,0> *)&mem_start_p, (BTMemNode *)v8)->id;
      BTree::DescendToDelete(v3, v9, (IDClass<_tagDataID,32,0>)mem_start_p, &mem_kid_p, &proIndex);
      return BTree::DeleteInternalTrans(
               v3,
               targetGId,
               (IDClass<_tagDataID,32,0>)mem_start_p,
               v5->offset_m,
               mem_kid_p->offset_m,
               v7,
               proIndex);
    }
    v12 = BTree::FindNode(v3, v5->node_m.NextNode_[v7 + 1], 0);
    v13 = (BTMemNode *)v12;
    if ( *(_DWORD *)(v12 + 268) >= 31 )
    {
      mem_start_p = (BTMemNode *)BTree::FindMin(v3, (IDClass<_tagDataID,32,0> *)&mem_start_p, (BTMemNode *)v12)->id;
      BTree::DescendToDelete(v3, v13, (IDClass<_tagDataID,32,0>)mem_start_p, &mem_kid_p, &proIndex);
      return BTree::DeleteInternalTrans(
               v3,
               targetGId,
               (IDClass<_tagDataID,32,0>)mem_start_p,
               v5->offset_m,
               mem_kid_p->offset_m,
               v7,
               proIndex);
    }
    v14 = v7;
    v15 = mem_start_p;
    v4 = BTree::MergeNodesTrans(v3, v5, mem_start_p, (BTMemNode *)v12, v14);
    if ( !v4 )
      return BTree::Delete(v3, targetGId, v15);
  }
  return v4;
}

//----- (00673B50) --------------------------------------------------------  // acclient.c:650127
bool __thiscall BTree::Remove(BTree *this, IDClass<_tagDataID,32,0> target)
{
  return BTree::Delete(this, target, &this->mem_root_node_m) == 0;
}

//----- (00673B70) --------------------------------------------------------  // acclient.c:650133
char __thiscall SmartArray<BTEntry,1>::AddToEnd(SmartArray<BTEntry,1> *this, BTEntry *i_rData)
{
  SmartArray<BTEntry,1> *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1), (result = SmartArray<BTEntry,1>::grow(v2, v4)) != 0) )
  {
    qmemcpy(&v2->m_data[v2->m_num++], i_rData, sizeof(v2->m_data[v2->m_num++]));
    result = 1;
  }
  return result;
}

//----- (00673BD0) --------------------------------------------------------  // acclient.c:650152
bool __thiscall BTree::Try_Delete_Oldest(BTree *this)
{
  BTree *v1; // esi@1
  unsigned int v2; // eax@2
  bool v3; // al@3
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v1 = this;
  if ( this->file_info_pm->use_lru_fm
    && (v2 = LRU_List::Get_Oldest(this->lru_man_pm, &result)->id, stru_8F76D8.id != v2) )
    v3 = BTree::Delete(v1, (IDClass<_tagDataID,32,0>)v2, &v1->mem_root_node_m) == 0;
  else
    v3 = 0;
  return v3;
}

//----- (00673C20) --------------------------------------------------------  // acclient.c:650170
void __thiscall BTree::Build_Id_List(BTree *this, SmartArray<BTEntry,1> *list_r, BTMemNode *pNode, IDClass<_tagDataID,32,0> MinID, IDClass<_tagDataID,32,0> MaxID)
{
  unsigned int v5; // ebx@1
  int v6; // esi@2
  unsigned int v7; // ST04_4@3
  unsigned int v8; // edi@3
  int v9; // eax@4
  unsigned int v10; // ebp@5
  int v11; // eax@10
  int v12; // [sp+4h] [bp-8h]@4
  BTree *v13; // [sp+8h] [bp-4h]@1

  v5 = MinID.id;
  v13 = this;
  if ( MinID.id <= MaxID.id )
  {
    v6 = pNode->node_m.NumEntries_;
    if ( v6 <= 61 )
    {
      v7 = MinID.id;
      MinID.id = 0;
      BTree::HasEntry((IDClass<_tagDataID,32,0>)v7, pNode, (int *)&MinID);
      v8 = MinID.id;
      if ( (signed int)MinID.id <= v6 )
      {
        v9 = (int)&pNode->node_m.Entry_[MinID.id];
        MinID.id = (unsigned int)((char *)&pNode->node_m + 4 * MinID.id);
        v12 = v9;
        do
        {
          v10 = v5;
          if ( (signed int)v8 < v6 )
          {
            v10 = *(_DWORD *)(v9 + 4);
            if ( v10 >= v5 && v10 <= MaxID.id )
              SmartArray<BTEntry,1>::AddToEnd(list_r, (BTEntry *)v9);
          }
          if ( pNode->node_m.NextNode_[0] )
          {
            v11 = BTree::FindNode(v13, *(_DWORD *)MinID.id, 0);
            BTree::Build_Id_List(v13, list_r, (BTMemNode *)v11, (IDClass<_tagDataID,32,0>)v5, MaxID);
          }
          if ( v10 > MaxID.id )
            break;
          MinID.id += 4;
          v6 = pNode->node_m.NumEntries_;
          ++v8;
          v9 = v12 + 24;
          v12 += 24;
        }
        while ( (signed int)v8 <= v6 );
      }
    }
  }
}

//----- (00673D10) --------------------------------------------------------  // acclient.c:650227
void __thiscall BTree::Build_Id_List(BTree *this, SmartArray<BTEntry,1> *list_r, BTMemNode *node_p)
{
  BTMemNode *v3; // ebx@1
  int v4; // eax@1
  BTree *v5; // esi@1
  SmartArray<BTEntry,1> *v6; // ebp@2
  int v7; // eax@4
  unsigned int v8; // eax@5
  int v9; // ecx@7
  bool v10; // sf@7
  unsigned __int8 v11; // of@7
  signed int v12; // edi@10
  int v13; // eax@11
  BTree *v14; // [sp+8h] [bp-8h]@1
  int offset_l; // [sp+Ch] [bp-4h]@2
  SmartArray<BTEntry,1> *list_ra; // [sp+14h] [bp+4h]@3
  BTMemNode *node_pa; // [sp+18h] [bp+8h]@2
  BTMemNode *node_pb; // [sp+18h] [bp+8h]@9

  v3 = node_p;
  v4 = node_p->node_m.NumEntries_;
  v5 = this;
  v14 = this;
  if ( v4 <= 61 )
  {
    v6 = list_r;
    offset_l = node_p->offset_m;
    node_pa = 0;
    if ( v4 > 0 )
    {
      list_ra = (SmartArray<BTEntry,1> *)v3->node_m.Entry_;
      do
      {
        v7 = v6->m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v6->m_num < v7
          || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1), SmartArray<BTEntry,1>::grow(v6, v8)) )
        {
          qmemcpy(&v6->m_data[v6->m_num], list_ra, sizeof(v6->m_data[v6->m_num]));
          v5 = v14;
          ++v6->m_num;
        }
        v9 = v3->node_m.NumEntries_;
        v11 = __OFSUB__((char *)&node_pa->time_stamp_lm + 1, v9);
        v10 = (signed int)((char *)&node_pa->time_stamp_lm + -v9 + 1) < 0;
        node_pa = (BTMemNode *)((char *)node_pa + 1);
        list_ra += 2;
      }
      while ( v10 ^ v11 );
    }
    if ( v3->node_m.NextNode_[0] )
    {
      node_pb = 0;
      if ( v3->node_m.NumEntries_ >= 0 )
      {
        v12 = 5;
        do
        {
          v13 = BTree::FindNode(v5, *(int *)((char *)&v3->time_stamp_lm + v12 * 4), 0);
          BTree::Build_Id_List(v5, v6, (BTMemNode *)v13);
          if ( v3->offset_m != offset_l )
            v3 = (BTMemNode *)BTree::FindNode(v5, offset_l, 0);
          ++v12;
          node_pb = (BTMemNode *)((char *)node_pb + 1);
        }
        while ( (signed int)node_pb <= v3->node_m.NumEntries_ );
      }
    }
  }
}

//----- (00673E20) --------------------------------------------------------  // acclient.c:650298
char __thiscall BTree::Get_Id_List(BTree *this, SmartArray<BTEntry,1> *list_r)
{
  char result; // al@1

  result = 0;
  if ( this->mem_root_node_m.node_m.NumEntries_ )
  {
    BTree::Build_Id_List(this, list_r, &this->mem_root_node_m);
    result = 1;
  }
  return result;
}

//----- (00673E40) --------------------------------------------------------  // acclient.c:650312
bool __thiscall BTree::Get_Id_List_Range(BTree *this, SmartArray<BTEntry,1> *list_r, IDClass<_tagDataID,32,0> MinID, IDClass<_tagDataID,32,0> MaxID)
{
  list_r->m_num = 0;
  if ( this->mem_root_node_m.node_m.NumEntries_ )
    BTree::Build_Id_List(this, list_r, &this->mem_root_node_m, MinID, MaxID);
  return list_r->m_num != 0;
}

//----- (00714DE0) --------------------------------------------------------  // acclient.c:807733
int sub_714DE0()
{
  return atexit(nullsub_64);
}

//----- (00714DF0) --------------------------------------------------------  // acclient.c:807739
int _E76_87()
{
  return atexit(nullsub_65);
}

//----- (00714E00) --------------------------------------------------------  // acclient.c:807745
int _E79_82()
{
  return atexit(_E80_79);
}

//----- (00714E10) --------------------------------------------------------  // acclient.c:807751
int sub_714E10()
{
  return atexit(nullsub_67);
}

