/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BlkAlloc
   Object     : ENGINE\diskcon\BlkAlloc.obj
   Functions  : 20
   Addresses  : 00673E80 - 00714E50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00673E80) --------------------------------------------------------  // acclient.c:650321
void __thiscall CLBlockAllocator::CLBlockAllocator(CLBlockAllocator *this)
{
  CLBlockAllocator *v1; // esi@1

  v1 = this;
  this->file_info_mp = 0;
  ActionState::SingleKeyInfo::SingleKeyInfo((ActionState::SingleKeyInfo *)&this->file_man_m);
  v1->expandable_mf = 0;
}

//----- (00673EA0) --------------------------------------------------------  // acclient.c:650332
void __thiscall CLBlockAllocator::~CLBlockAllocator(CLBlockAllocator *this)
{
  DiskDev::~DiskDev(&this->file_man_m);
}

//----- (00673EB0) --------------------------------------------------------  // acclient.c:650338
int __thiscall CLBlockAllocator::Close_Data_File(CLBlockAllocator *this)
{
  CLBlockAllocator *v1; // esi@1
  int result; // eax@1

  v1 = this;
  result = DiskDev::Close(&this->file_man_m);
  v1->file_info_mp = 0;
  return result;
}

//----- (00673ED0) --------------------------------------------------------  // acclient.c:650350
int __thiscall CLBlockAllocator::SaveFileInfo(CLBlockAllocator *this)
{
  return DiskDev::SyncWrite(&this->file_man_m, this->file_info_mp, 0x50u, 320);
}

//----- (00673EF0) --------------------------------------------------------  // acclient.c:650356
int __thiscall CLBlockAllocator::StoreDataRollback(CLBlockAllocator *this, unsigned int dataSize, int startOffset)
{
  int v3; // esi@1
  void **v4; // ebp@1
  DiskDev *v5; // edi@1
  signed int v6; // ebx@1
  int result; // eax@1
  int v8; // ecx@1
  int nextOffset; // [sp+10h] [bp-4h]@1

  v3 = startOffset;
  v4 = (void **)this;
  v5 = &this->file_man_m;
  v6 = 1;
  result = DiskDev::SyncRead(&this->file_man_m, &nextOffset, 4u, startOffset);
  v8 = nextOffset;
  if ( nextOffset < 0 )
  {
LABEL_6:
    if ( !result && startOffset != *((_DWORD *)*v4 + 5) )
    {
      *((_DWORD *)*v4 + 5) = startOffset;
      *((_DWORD *)*v4 + 7) += v6;
      result = DiskDev::SyncWrite(v5, *v4, 0x50u, 320);
    }
  }
  else
  {
    while ( !result )
    {
      if ( !v8 )
      {
        v8 = *((_DWORD *)*v4 + 5);
        --v6;
      }
      nextOffset = v8 | 0x80000000;
      DiskDev::SyncWrite(v5, &nextOffset, 4u, v3);
      v3 = nextOffset & 0x7FFFFFFF;
      ++v6;
      result = DiskDev::SyncRead(v5, &nextOffset, 4u, nextOffset & 0x7FFFFFFF);
      v8 = nextOffset;
      if ( nextOffset < 0 )
        goto LABEL_6;
    }
  }
  return result;
}

//----- (00673FB0) --------------------------------------------------------  // acclient.c:650405
int __thiscall CLBlockAllocator::DeleteBlocks(CLBlockAllocator *this, int startOffset, int finalOffset, int oldFreeCount, bool fRefree)
{
  int v5; // ebx@1
  int result; // eax@1
  void **v7; // ebp@1
  int v8; // ecx@1
  int v9; // edi@1
  int v10; // edx@11
  int iCount; // [sp+10h] [bp-4h]@1

  v5 = startOffset;
  result = 0;
  v7 = (void **)this;
  v8 = startOffset;
  v9 = startOffset;
  iCount = 0;
  if ( startOffset )
  {
    while ( !result )
    {
      v9 = v8;
      result = DiskDev::SyncRead((DiskDev *)v7 + 1, &startOffset, 4u, v8);
      v8 = startOffset;
      if ( !result )
      {
        if ( fRefree || startOffset >= 0 )
        {
          startOffset |= 0x80000000;
          result = DiskDev::SyncWrite((DiskDev *)v7 + 1, &startOffset, 4u, v9);
          v8 = startOffset & 0x7FFFFFFF;
          startOffset &= 0x7FFFFFFFu;
          ++iCount;
        }
        else
        {
          result = -101;
        }
      }
      if ( !v8 )
      {
        if ( result )
          return result;
        goto LABEL_10;
      }
    }
  }
  else
  {
LABEL_10:
    startOffset = v5 | 0x80000000;
    result = DiskDev::SyncWrite((DiskDev *)v7 + 1, &startOffset, 4u, finalOffset);
    if ( !result )
    {
      v10 = oldFreeCount;
      *((_DWORD *)*v7 + 6) = v9;
      *((_DWORD *)*v7 + 7) = v10 + iCount;
      result = DiskDev::SyncWrite((DiskDev *)v7 + 1, *v7, 0x50u, 320);
    }
  }
  return result;
}

//----- (006740A0) --------------------------------------------------------  // acclient.c:650468
int __thiscall CLBlockAllocator::ExpandFile(CLBlockAllocator *this, int size_l)
{
  CLBlockAllocator *v2; // ebp@1
  DiskFileInfo_t *v3; // ecx@1
  signed int v4; // ebx@1
  unsigned int v5; // ST08_4@1
  void *v6; // esi@1
  int v7; // edi@1
  int v8; // ebp@1
  int v9; // ST08_4@2
  DiskDev *v10; // ebx@4
  void *v11; // eax@4
  int v12; // ecx@4
  void **v14; // [sp+10h] [bp-Ch]@1
  int iCount; // [sp+14h] [bp-8h]@1

  v2 = this;
  v3 = this->file_info_mp;
  v4 = v3->iBlockSize_;
  v5 = v3->iBlockSize_;
  v14 = (void **)v2;
  iCount = size_l / v4;
  v3->iFreeBlocks_ += size_l / v4;
  v6 = operator new[](v5);
  memset(v6, 0, v4);
  v7 = v2->file_info_mp->fileSize_;
  v8 = v2->file_info_mp->fileSize_;
  size_l = 0;
  if ( iCount <= 0 )
  {
LABEL_4:
    v10 = (DiskDev *)(v14 + 1);
    *(_DWORD *)v6 = 2147483648;
    DiskDev::SyncWrite((DiskDev *)v14 + 1, v6, 4u, v7);
    v11 = *v14;
    v12 = *((_DWORD *)*v14 + 6);
    size_l = *((_DWORD *)*v14 + 2) | 0x80000000;
    *((_DWORD *)v11 + 2) = v8;
    *((_DWORD *)*v14 + 6) = v7;
    DiskDev::SyncWrite((DiskDev *)v14 + 1, &size_l, 4u, v12);
  }
  else
  {
    while ( 1 )
    {
      v7 = v8;
      v9 = v8;
      v8 += v4;
      *(_DWORD *)v6 = v8 | 0x80000000;
      if ( DiskDev::SyncWrite((DiskDev *)v14 + 1, v6, v4, v9) )
        break;
      ++size_l;
      if ( size_l >= iCount )
        goto LABEL_4;
    }
    v10 = (DiskDev *)(v14 + 1);
  }
  operator delete[](v6);
  return DiskDev::SyncWrite(v10, *v14, 0x50u, 320);
}

//----- (006741B0) --------------------------------------------------------  // acclient.c:650530
int __thiscall CLBlockAllocator::Store_Data(CLBlockAllocator *this, Cache_Pack_t *pack_buf, int startOffset)
{
  int v3; // ebp@1
  CLBlockAllocator *v4; // edi@1
  SmartBuffer *v5; // ebx@1
  unsigned int v6; // esi@2
  int v7; // eax@4
  int result; // eax@4
  int v9; // ebp@4
  int iBlocksUsed; // [sp+10h] [bp-14h]@4
  int chunkSize; // [sp+14h] [bp-10h]@4
  int blockSize; // [sp+18h] [bp-Ch]@4
  int iCurrent; // [sp+1Ch] [bp-8h]@1
  int save_offset; // [sp+20h] [bp-4h]@8
  Cache_Pack_t *pack_bufa; // [sp+28h] [bp+4h]@4

  v3 = startOffset;
  v4 = this;
  v5 = &pack_buf->m_buff;
  iCurrent = startOffset;
  if ( SmartBuffer::GetSize(&pack_buf->m_buff) <= 4 )
    v6 = 0;
  else
    v6 = SmartBuffer::GetSize(v5) - 4;
  SmartBuffer::ReconfigureAllocation(v5, 4u, 1u);
  pack_bufa = (Cache_Pack_t *)SmartBuffer::GetBuffer(v5);
  v7 = v4->file_info_mp->iBlockSize_;
  blockSize = v7;
  chunkSize = v7 - 4;
  iBlocksUsed = 1;
  result = DiskDev::SyncRead(&v4->file_man_m, &startOffset, 4u, v3);
  v9 = startOffset & 0x7FFFFFFF;
  startOffset &= 0x7FFFFFFFu;
  if ( v6 )
  {
    while ( !result )
    {
      save_offset = pack_bufa->m_dwOffset;
      if ( v6 <= chunkSize )
      {
        blockSize = v6 + 4;
        v4->file_info_mp->iFreeBlocks_ -= iBlocksUsed;
        v4->file_info_mp->firstFree_ = startOffset;
        v9 = 0;
        chunkSize = v6;
        DiskDev::SyncWrite(&v4->file_man_m, v4->file_info_mp, 0x50u, 320);
      }
      else
      {
        DiskDev::SyncRead(&v4->file_man_m, &startOffset, 4u, v9);
        startOffset &= 0x7FFFFFFFu;
        ++iBlocksUsed;
      }
      pack_bufa->m_dwOffset = v9;
      result = DiskDev::SyncWrite(&v4->file_man_m, pack_bufa, blockSize, iCurrent);
      if ( !result )
      {
        pack_bufa->m_dwOffset = save_offset;
        v6 -= chunkSize;
        iCurrent = v9;
        pack_bufa = (Cache_Pack_t *)((char *)pack_bufa + chunkSize);
      }
      if ( !v6 )
        break;
      v9 = startOffset;
    }
  }
  return result;
}

//----- (00674300) --------------------------------------------------------  // acclient.c:650601
int __thiscall CLBlockAllocator::Update(CLBlockAllocator *this, Cache_Pack_t *pack_buf, int inOffset)
{
  CLBlockAllocator *v3; // esi@1
  SmartBuffer *v4; // edi@1
  int v5; // ebp@1
  unsigned int v6; // eax@4
  int v7; // edi@4
  int *v8; // ebx@4
  int v9; // eax@4
  char v10; // al@4
  DiskFileInfo_t *v11; // eax@10
  DiskFileInfo_t *v12; // eax@10
  DiskFileInfo_t *v13; // edx@12
  DiskFileInfo_t *v14; // eax@12
  int v15; // ST0C_4@14
  int v16; // ST08_4@14
  int iNext; // [sp+10h] [bp-18h]@1
  int iCurrent; // [sp+14h] [bp-14h]@1
  int buf; // [sp+18h] [bp-10h]@10
  int chunkSize; // [sp+1Ch] [bp-Ch]@4
  int blockSize; // [sp+20h] [bp-8h]@4
  int save_offset; // [sp+24h] [bp-4h]@8
  Cache_Pack_t *pack_bufa; // [sp+2Ch] [bp+4h]@2
  char data_size; // [sp+30h] [bp+8h]@4

  v3 = this;
  v4 = &pack_buf->m_buff;
  v5 = 0;
  iCurrent = inOffset;
  iNext = 0;
  if ( SmartBuffer::GetSize(&pack_buf->m_buff) <= 4 )
    pack_bufa = 0;
  else
    pack_bufa = (Cache_Pack_t *)(SmartBuffer::GetSize(v4) - 4);
  SmartBuffer::ReconfigureAllocation(v4, 4u, 1u);
  v6 = SmartBuffer::GetBuffer(v4);
  v7 = (int)pack_bufa;
  v8 = (int *)v6;
  v9 = v3->file_info_mp->iBlockSize_;
  blockSize = v9;
  chunkSize = v9 - 4;
  v10 = 0;
  data_size = 0;
  if ( pack_bufa )
  {
    while ( !v5 )
    {
      save_offset = *v8;
      if ( v7 <= (unsigned int)chunkSize )
      {
        if ( !v10 )
        {
          DiskDev::SyncRead(&v3->file_man_m, &iNext, 4u, iCurrent);
          if ( iNext )
            CLBlockAllocator::DeleteBlocks(v3, iNext, v3->file_info_mp->finalFree_, v3->file_info_mp->iFreeBlocks_, 0);
        }
        iNext = 0;
        chunkSize = v7;
        blockSize = v7 + 4;
      }
      else if ( v10 )
      {
        v11 = v3->file_info_mp;
        buf = 0;
        DiskDev::SyncRead(&v3->file_man_m, &buf, 4u, v11->firstFree_);
        v12 = v3->file_info_mp;
        buf &= 0x7FFFFFFFu;
        iNext = v12->firstFree_;
        v12->firstFree_ = buf;
        --v3->file_info_mp->iFreeBlocks_;
      }
      else
      {
        DiskDev::SyncRead(&v3->file_man_m, &iNext, 4u, iCurrent);
        if ( !iNext )
        {
          v13 = v3->file_info_mp;
          buf = 0;
          data_size = 1;
          DiskDev::SyncRead(&v3->file_man_m, &buf, 4u, v13->firstFree_);
          v14 = v3->file_info_mp;
          buf &= 0x7FFFFFFFu;
          iNext = v14->firstFree_;
          v14->firstFree_ = buf;
          --v3->file_info_mp->iFreeBlocks_;
        }
        v7 = (int)pack_bufa;
      }
      v15 = iCurrent;
      v16 = blockSize;
      *v8 = iNext;
      v5 = DiskDev::SyncWrite(&v3->file_man_m, v8, v16, v15);
      if ( !v5 )
      {
        *v8 = save_offset;
        iCurrent = iNext;
        v7 -= chunkSize;
        pack_bufa = (Cache_Pack_t *)v7;
        v8 = (int *)((char *)v8 + chunkSize);
      }
      if ( !v7 )
        break;
      v10 = data_size;
    }
  }
  return v5;
}

//----- (006744E0) --------------------------------------------------------  // acclient.c:650710
char __thiscall CLBlockAllocator::Load_Data(CLBlockAllocator *this, Cache_Pack_t *buf_out, int offset, bool bShortRead)
{
  CLBlockAllocator *v4; // ebx@1
  void *v5; // esi@1
  unsigned int v6; // edi@2
  int v7; // ebp@4
  int v8; // ebx@4
  char result; // al@6
  bool result_f; // [sp+13h] [bp-5h]@1
  CLBlockAllocator *v11; // [sp+14h] [bp-4h]@1
  unsigned int buf_outa; // [sp+1Ch] [bp+4h]@4
  int blockSize; // [sp+20h] [bp+8h]@7

  v4 = this;
  v11 = this;
  result_f = 1;
  SmartBuffer::ReconfigureAllocation(&buf_out->m_buff, 4u, 1u);
  v5 = (void *)SmartBuffer::GetBuffer(&buf_out->m_buff);
  if ( SmartBuffer::GetSize(&buf_out->m_buff) <= 4 )
    v6 = 0;
  else
    v6 = SmartBuffer::GetSize(&buf_out->m_buff) - 4;
  v7 = offset;
  buf_outa = v4->file_info_mp->iBlockSize_;
  v8 = buf_outa - 4;
  if ( !v6 )
  {
    result = 1;
    goto LABEL_17;
  }
  while ( v7 )
  {
    result = result_f;
    if ( !result_f )
      return result;
    blockSize = *(_DWORD *)v5;
    if ( v8 > (signed int)v6 )
    {
      v8 = v6;
      buf_outa = v6 + 4;
    }
    if ( DiskDev::SyncRead(&v11->file_man_m, v5, buf_outa, v7) )
      goto LABEL_12;
    v7 = *(_DWORD *)v5;
    *(_DWORD *)v5 = blockSize;
    v6 -= v8;
    v5 = (char *)v5 + v8;
    if ( v7 < 0 )
    {
      v7 &= 0x7FFFFFFFu;
LABEL_12:
      result_f = 0;
    }
    if ( !v6 )
      break;
  }
  result = result_f;
  if ( result_f )
  {
LABEL_17:
    if ( (v7 || v6) && !bShortRead )
      result = 0;
  }
  return result;
}

//----- (006745C0) --------------------------------------------------------  // acclient.c:650777
void __cdecl SB_TypeAlloc<DiskTransactInfoResolver,SB_Default>::Serialize(const int *_class, DiskTransactInfo **_obj, Archive *_arc)
{
  Archive *v3; // esi@1
  DiskTransactType v4; // ebx@2
  Archive *v5; // ecx@4
  unsigned int v6; // eax@4
  DiskTransactInfo *v7; // eax@11
  unsigned __int8 _arca; // [sp+18h] [bp+Ch]@4

  v3 = _arc;
  if ( _arc->m_flags & 1 )
    v4 = (*_obj)->m_eTransactType;
  else
    v4 = (DiskTransactType)_arc;
  v5 = _arc;
  _arca = v4;
  Archive::CheckAlignment(v5, 1u);
  v6 = Archive::GetBytes(v3, 1u);
  if ( v6 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v6 = v4;
    else
      _arca = *(_BYTE *)v6;
  }
  if ( !(v3->m_flags & 5) )
    v4 = _arca;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    DiskTransactInfo::CreateTransactInfo(v4);
    *_obj = v7;
  }
  if ( *_obj )
    ((void (__stdcall *)(_DWORD))(*_obj)->vfptr->Serialize)(v3);
}

//----- (00674640) --------------------------------------------------------  // acclient.c:650814
int __thiscall CLBlockAllocator::SaveTransaction(CLBlockAllocator *this, DiskTransactInfo *pTransInfo)
{
  CLBlockAllocator *v2; // esi@1
  unsigned int v3; // ST04_4@2
  unsigned int v4; // eax@2
  int v5; // esi@2
  int result; // eax@2
  int dummy; // [sp+4h] [bp-34h]@1
  SmartBuffer cBuffer; // [sp+8h] [bp-30h]@1
  TransientArchive cArchive; // [sp+14h] [bp-24h]@1

  v2 = this;
  TransientArchive::TransientArchive(&cArchive, 0);
  SB_TypeAlloc<DiskTransactInfoResolver,SB_Default>::Serialize(&dummy, &pTransInfo, (Archive *)&cArchive.vfptr);
  Archive::GetSerializedBuffer((Archive *)&cArchive.vfptr, &cBuffer);
  if ( SmartBuffer::GetSize(&cBuffer) > 0x40 )
  {
    SmartBuffer::ReleaseMasterBuffer(&cBuffer);
    Archive::~Archive((Archive *)&cArchive.vfptr);
    result = -101;
  }
  else
  {
    v3 = SmartBuffer::GetSize(&cBuffer);
    v4 = SmartBuffer::GetBuffer(&cBuffer);
    v5 = DiskDev::SyncWrite(&v2->file_man_m, (void *)v4, v3, 256);
    SmartBuffer::ReleaseMasterBuffer(&cBuffer);
    Archive::~Archive((Archive *)&cArchive.vfptr);
    result = v5;
  }
  return result;
}

//----- (006746E0) --------------------------------------------------------  // acclient.c:650848
int __thiscall CLBlockAllocator::ClearTransaction(CLBlockAllocator *this)
{
  CLBlockAllocator *v1; // esi@1
  DiskTransactInfo transInfo; // [sp+4h] [bp-Ch]@1

  v1 = this;
  DiskTransactInfo::DiskTransactInfo(&transInfo);
  return CLBlockAllocator::SaveTransaction(v1, &transInfo);
}

//----- (00674700) --------------------------------------------------------  // acclient.c:650859
int __thiscall CLBlockAllocator::ReadTransaction(CLBlockAllocator *this, DiskTransactInfo **pTranInfo)
{
  CLBlockAllocator *v2; // esi@1
  unsigned int v3; // ST04_4@1
  unsigned int v4; // eax@1
  int v5; // esi@1
  DiskTransactInfo **v6; // edi@2
  SmartBuffer cBuffer; // [sp+8h] [bp-30h]@1
  TransientArchive cArchive; // [sp+14h] [bp-24h]@2

  v2 = this;
  SmartBuffer::SmartBuffer(&cBuffer);
  SmartBuffer::ReconfigureAllocation(&cBuffer, 0x40u, 1u);
  v3 = SmartBuffer::GetSize(&cBuffer);
  v4 = SmartBuffer::GetBuffer(&cBuffer);
  v5 = DiskDev::SyncRead(&v2->file_man_m, (void *)v4, v3, 256);
  if ( !v5 )
  {
    cArchive.vfptr = (ArchiveVtbl *)&Archive::vftable;
    cArchive.m_flags = 0;
    cArchive.m_hrError.m_val = 0;
    SmartBuffer::SmartBuffer(&cArchive.m_buffer);
    cArchive.m_currOffset = 0;
    cArchive.m_pcUserDataHash = 0;
    cArchive.m_pVersionStack = 0;
    cArchive.vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
    Archive::InitForUnpacking((Archive *)&cArchive.vfptr, &Archive::SetCurrentCoreVersion, &cBuffer);
    v6 = pTranInfo;
    SB_TypeAlloc<DiskTransactInfoResolver,SB_Default>::Serialize(
      (const int *)&pTranInfo,
      pTranInfo,
      (Archive *)&cArchive.vfptr);
    if ( (cArchive.m_flags >> 2) & 1 || (*v6)->m_nMagicNumber != 19536 )
      v5 = -101;
    Archive::~Archive((Archive *)&cArchive.vfptr);
  }
  SmartBuffer::ReleaseMasterBuffer(&cBuffer);
  return v5;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (006747E0) --------------------------------------------------------  // acclient.c:650902
int __thiscall CLBlockAllocator::CreateDataFile(CLBlockAllocator *this, DiskFileInfo_t *file_info_p, PStringBase<char> *file_name_cp, PStringBase<unsigned short> *path_cp, unsigned int open_flags_l)
{
  CLBlockAllocator *v5; // ebp@1
  unsigned int v6; // ST10_4@1
  PStringBase<unsigned short> *v7; // ST08_4@1
  PStringBase<char> *v8; // ecx@1
  PStringBase<unsigned short> *v9; // eax@1
  int v10; // eax@1
  char *v11; // esi@1
  int v12; // edi@1
  int result; // eax@5
  DiskFileInfo_t *v14; // ecx@6
  signed int v15; // ebx@6
  int v16; // eax@6
  unsigned int v17; // ST0C_4@6
  void *v18; // esi@6
  int v19; // eax@6
  signed int v20; // edi@6
  int v21; // ST0C_4@7
  DiskFileInfo_t *v22; // eax@10
  DiskFileInfo_t *v23; // edx@10
  DiskTransactInfo pTransInfo; // [sp+Ch] [bp-Ch]@12

  v5 = this;
  this->file_info_mp = file_info_p;
  v6 = open_flags_l;
  v7 = path_cp;
  v8 = file_name_cp;
  v5->expandable_mf = (open_flags_l & 2) == 2;
  v9 = PStringBase<char>::to_wpstring(v8, (PStringBase<unsigned short> *)&file_info_p, 0);
  v10 = DiskDev::Open_File(&v5->file_man_m, v9, v7, 0, v6);
  v11 = (char *)&file_info_p[-1].id_vnum;
  v12 = v10;
  if ( !InterlockedDecrement((volatile LONG *)&file_info_p[-1].id_vnum._maj_vnum.Data2) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  if ( v12 )
  {
    result = v12;
  }
  else
  {
    v14 = v5->file_info_mp;
    v15 = v5->file_info_mp->iBlockSize_;
    v16 = (signed int)(v5->file_info_mp->fileSize_ - 1024) / v15;
    v17 = v5->file_info_mp->iBlockSize_;
    path_cp = (PStringBase<unsigned short> *)v16;
    v14->iFreeBlocks_ = v16;
    v18 = operator new[](v17);
    memset(v18, 0, v15);
    v19 = 1024;
    v5->file_info_mp->firstFree_ = 1024;
    v20 = 1024;
    open_flags_l = 0;
    if ( (signed int)path_cp <= 0 )
    {
LABEL_10:
      v5->file_info_mp->finalFree_ = v19;
      *(_DWORD *)v18 = 2147483648;
      v22 = (DiskFileInfo_t *)DiskDev::SyncWrite(&v5->file_man_m, v18, 4u, v19);
      v23 = v5->file_info_mp;
      file_info_p = v22;
      v23->fileSize_ = v20;
      operator delete[](v18);
      result = (int)file_info_p;
      if ( !file_info_p )
      {
        result = DiskDev::SyncWrite(&v5->file_man_m, v5->file_info_mp, 0x50u, 320);
        if ( !result )
        {
          DiskTransactInfo::DiskTransactInfo(&pTransInfo);
          CLBlockAllocator::SaveTransaction(v5, &pTransInfo);
          result = 0;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v21 = v20;
        v20 += v15;
        file_name_cp = (PStringBase<char> *)v21;
        *(_DWORD *)v18 = v20 | 0x80000000;
        file_info_p = (DiskFileInfo_t *)DiskDev::SyncWrite(&v5->file_man_m, v18, v15, v21);
        if ( file_info_p )
          break;
        ++open_flags_l;
        if ( (signed int)open_flags_l >= (signed int)path_cp )
        {
          v19 = (int)file_name_cp;
          goto LABEL_10;
        }
      }
      operator delete[](v18);
      result = (int)file_info_p;
    }
  }
  return result;
}

//----- (00674980) --------------------------------------------------------  // acclient.c:651003
unsigned int __thiscall CLBlockAllocator::OpenDataFile(CLBlockAllocator *this, DiskFileInfo_t *pFileInfo, PStringBase<char> *pFileName, PStringBase<unsigned short> *pcPathToUse, unsigned int open_flags_l, DiskTransactInfo **pTranInfo)
{
  DiskFileInfo_t *v6; // ebp@1
  CLBlockAllocator *v7; // esi@1
  unsigned int v8; // ST10_4@1
  PStringBase<unsigned short> *v9; // ST08_4@1
  bool v10; // dl@1
  PStringBase<char> *v11; // ecx@1
  PStringBase<unsigned short> *v12; // eax@1
  unsigned int v13; // eax@1
  char *v14; // edi@1
  unsigned int result; // eax@4

  v6 = pFileInfo;
  v7 = this;
  v8 = open_flags_l;
  v9 = pcPathToUse;
  v10 = (open_flags_l & 2) == 2;
  v11 = pFileName;
  v7->file_info_mp = pFileInfo;
  v7->expandable_mf = v10;
  v12 = PStringBase<char>::to_wpstring(v11, (PStringBase<unsigned short> *)&pFileInfo, 0);
  v13 = DiskDev::Open_File(&v7->file_man_m, v12, v9, 0, v8);
  v14 = (char *)&pFileInfo[-1].id_vnum;
  open_flags_l = v13;
  if ( !InterlockedDecrement((volatile LONG *)&pFileInfo[-1].id_vnum._maj_vnum.Data2) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  result = open_flags_l;
  if ( !open_flags_l )
  {
    result = DiskDev::SyncRead(&v7->file_man_m, v6, 0x50u, 320);
    if ( v6->magic_ != 21570 )
    {
      DiskDev::Close(&v7->file_man_m);
      result = -102;
    }
    if ( !result )
      result = CLBlockAllocator::ReadTransaction(v7, pTranInfo);
  }
  return result;
}

//----- (00714E20) --------------------------------------------------------  // acclient.c:807757
int sub_714E20()
{
  return atexit(nullsub_61);
}

//----- (00714E30) --------------------------------------------------------  // acclient.c:807763
int _E76_88()
{
  return atexit(nullsub_62);
}

//----- (00714E40) --------------------------------------------------------  // acclient.c:807769
int _E79_83()
{
  return atexit(_E80_80);
}

//----- (00714E50) --------------------------------------------------------  // acclient.c:807775
int sub_714E50()
{
  return atexit(nullsub_60);
}

