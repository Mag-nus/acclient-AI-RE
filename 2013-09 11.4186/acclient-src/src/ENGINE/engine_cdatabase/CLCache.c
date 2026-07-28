/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLCache
   Object     : ENGINE\engine_cdatabase\CLCache.obj
   Functions  : 181
   Addresses  : 004180E0 - 00764DD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004180E0) --------------------------------------------------------  // acclient.c:84964
IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *__thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *this, IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *result, QualifiedDataID *_key)
{
  unsigned int v3; // esi@1
  HashTableData<QualifiedDataID,MissingIteration *> **v4; // ebx@1
  HashTableData<QualifiedDataID,MissingIteration *> *i; // edx@1
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *v6; // eax@5

  v3 = _key->ID.id;
  v4 = &this->m_buckets[(_key->Type + v3) % this->m_numBuckets];
  for ( i = *v4; i; i = i->m_hashNext )
  {
    if ( i->m_hashKey.Type == _key->Type && i->m_hashKey.ID.id == v3 )
      break;
  }
  v6 = result;
  result->m_currBucket = v4;
  result->m_currHashTable = this;
  result->m_currElement = i;
  return v6;
}

//----- (004371C0) --------------------------------------------------------  // acclient.c:116388
void __thiscall _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(DiskConInitInfo *this)
{
  DiskConInitInfo *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4

  v1 = this;
  v2 = (char *)&this->path.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->file.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (00444890) --------------------------------------------------------  // acclient.c:128716
void __cdecl Serializer::SerializeObject(CliDatError *io_object, Archive *io_archive)
{
  CliDatError *v2; // eax@1

  Archive::CheckAlignment(io_archive, 4u);
  v2 = (CliDatError *)Archive::GetBytes(io_archive, 4u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (0044B580) --------------------------------------------------------  // acclient.c:136151
char __thiscall SmartArray<FontReference,1>::grow(SmartArray<QualifiedDataID,1> *this, unsigned int i_nSize)
{
  SmartArray<QualifiedDataID,1> *v2; // esi@1
  void *v4; // eax@5
  int v5; // edi@6
  int i; // eax@8
  QualifiedDataID *v7; // edx@9

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<QualifiedDataID,1>::Reset(this);
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
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          for ( i = v2->m_num - 1; i >= 0; *(_DWORD *)(v5 + 8 * i + 12) = v7[i + 1].ID.id )
          {
            --i;
            v7 = v2->m_data;
            *(_DWORD *)(v5 + 8 * i + 8) = v2->m_data[i + 1].Type;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              operator delete[](&v2->m_data[-1].ID);
          }
        }
        v2->m_data = (QualifiedDataID *)v5;
        v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00493250) --------------------------------------------------------  // acclient.c:206078
void __thiscall LookFile::~LookFile(LookFile *this)
{
  LookFile *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4
  int v4; // esi@7

  v1 = this;
  v2 = &this->_key.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->_key_path.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->_path.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (004F6E10) --------------------------------------------------------  // acclient.c:290160
void __cdecl CLandBlockInfo::Allocator()
{
  CLandBlockInfo *v0; // eax@1

  v0 = (CLandBlockInfo *)operator new(0x60u);
  if ( v0 )
    CLandBlockInfo::CLandBlockInfo(v0);
}

//----- (004F6E30) --------------------------------------------------------  // acclient.c:290170
void __cdecl CLandBlock::Allocator()
{
  CLandBlock *v0; // eax@1

  v0 = (CLandBlock *)operator new(0x130u);
  if ( v0 )
    CLandBlock::CLandBlock(v0);
}

//----- (004F6E50) --------------------------------------------------------  // acclient.c:290180
void __thiscall TransientArchive::TransientArchive(TransientArchive *this, Archive::tagUnpacking __formal, void *addr, unsigned int size)
{
  TransientArchive *v4; // esi@1
  SmartBuffer *v5; // eax@1
  SmartBuffer v6; // [sp+8h] [bp-Ch]@1

  v4 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  this->m_flags = 0;
  this->m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&this->m_buffer);
  v4->m_currOffset = 0;
  v4->m_pcUserDataHash = 0;
  v4->m_pVersionStack = 0;
  v4->vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
  SmartBuffer::SmartBuffer(&v6, addr, size);
  Archive::InitForUnpacking((Archive *)&v4->vfptr, &Archive::SetCurrentCoreVersion, v5);
  SmartBuffer::ReleaseMasterBuffer(&v6);
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (004F6EB0) --------------------------------------------------------  // acclient.c:290203
void __cdecl CEnvCell::Allocator()
{
  CEnvCell *v0; // eax@1

  v0 = (CEnvCell *)operator new(0x148u);
  if ( v0 )
    CEnvCell::CEnvCell(v0);
}

//----- (004F6ED0) --------------------------------------------------------  // acclient.c:290213
void __cdecl CGfxObj::Allocator()
{
  CGfxObj *v0; // eax@1

  v0 = (CGfxObj *)operator new(0xB8u);
  if ( v0 )
    CGfxObj::CGfxObj(v0);
}

//----- (004F6EF0) --------------------------------------------------------  // acclient.c:290223
void __cdecl CAnimation::Allocator()
{
  CAnimation *v0; // eax@1

  v0 = (CAnimation *)operator new(0x50u);
  if ( v0 )
    CAnimation::CAnimation(v0);
}

//----- (004F6F10) --------------------------------------------------------  // acclient.c:290233
void __cdecl CSetup::Allocator()
{
  CSetup *v0; // eax@1

  v0 = (CSetup *)operator new(0xD8u);
  if ( v0 )
    CSetup::CSetup(v0);
}

//----- (004F6F30) --------------------------------------------------------  // acclient.c:290243
void __cdecl Palette::Allocator()
{
  Palette *v0; // eax@1

  v0 = (Palette *)operator new(0x48u);
  if ( v0 )
    Palette::Palette(v0, 2048);
}

//----- (004F6F50) --------------------------------------------------------  // acclient.c:290253
void __usercall ImgTex::Allocator(int a1@<ebx>, int a2@<ebp>)
{
  ImgTex *v2; // eax@1

  v2 = (ImgTex *)operator new(0x88u);
  if ( v2 )
    ImgTex::ImgTex(v2, a1, a2, 0);
}

//----- (004F6F70) --------------------------------------------------------  // acclient.c:290263
void __cdecl CSurface::Allocator()
{
  CSurface *v0; // eax@1

  v0 = (CSurface *)operator new(0x90u);
  if ( v0 )
    CSurface::CSurface(v0);
}

//----- (004F6F90) --------------------------------------------------------  // acclient.c:290273
void __cdecl DBWave::Allocator()
{
  DBWave *v0; // eax@1

  v0 = (DBWave *)operator new(0xA0u);
  if ( v0 )
    DBWave::DBWave(v0, id);
}

//----- (004F6FC0) --------------------------------------------------------  // acclient.c:290283
void __cdecl CEnvironment::Allocator()
{
  CEnvironment *v0; // eax@1

  v0 = (CEnvironment *)operator new(0x40u);
  if ( v0 )
    CEnvironment::CEnvironment(v0);
}

//----- (004F6FE0) --------------------------------------------------------  // acclient.c:290293
void __cdecl ChatPoseTable::Allocator()
{
  ChatPoseTable *v0; // eax@1

  v0 = (ChatPoseTable *)operator new(0x60u);
  if ( v0 )
    ChatPoseTable::ChatPoseTable(v0, id);
}

//----- (004F7000) --------------------------------------------------------  // acclient.c:290303
void __cdecl cWObjHierRootNode::Allocator()
{
  cWObjHierRootNode *v0; // eax@1

  v0 = (cWObjHierRootNode *)operator new(0x50u);
  if ( v0 )
    cWObjHierRootNode::cWObjHierRootNode(v0, id);
}

//----- (004F7020) --------------------------------------------------------  // acclient.c:290313
void __cdecl BadData::Allocator()
{
  BadData *v0; // eax@1

  v0 = (BadData *)operator new(0x50u);
  if ( v0 )
    BadData::BadData(v0, id);
}

//----- (004F7040) --------------------------------------------------------  // acclient.c:290323
void __cdecl TabooTable::Allocator()
{
  TabooTable *v0; // eax@1

  v0 = (TabooTable *)operator new(0xA8u);
  if ( v0 )
    TabooTable::TabooTable(v0);
}

//----- (004F7060) --------------------------------------------------------  // acclient.c:290333
DBObj *DBFile2IDTable::Allocate()
{
  void *v1; // esi@1
  DBObj *result; // eax@2

  v1 = operator new(0x120u);
  if ( v1 )
  {
    DBObj::DBObj((DBObj *)v1, id);
    TFile2IDTable::TFile2IDTable((TFile2IDTable *)((char *)v1 + 48), 0);
    *((_DWORD *)v1 + 12) = &DBFile2IDTable::vftable;
    *(_DWORD *)v1 = &DBFile2IDTable::vftable;
    result = (DBObj *)v1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7C5808: using guessed type __int32 (__stdcall *DBFile2IDTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C5860: using guessed type int (__stdcall *DBFile2IDTable::vftable)(IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, PStringBase<char> FileNameCopy);

//----- (004F70C0) --------------------------------------------------------  // acclient.c:290363
DBFile2IDTable *__thiscall DBFile2IDTable::vector_deleting_destructor(DBFile2IDTable *this, unsigned int a2)
{
  DBFile2IDTable *v2; // esi@1

  v2 = this;
  DBFile2IDTable::~DBFile2IDTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F70E0) --------------------------------------------------------  // acclient.c:290375
void __thiscall DBFile2IDTable::~DBFile2IDTable(DBFile2IDTable *this)
{
  DBObj *v1; // esi@1
  TFile2IDTable *v2; // ecx@1

  v1 = (DBObj *)this;
  v2 = (TFile2IDTable *)&this->vfptr;
  v1->vfptr = (InterfaceVtbl *)&DBFile2IDTable::vftable;
  v2->vfptr = (TReadOnlyFile2IDTableVtbl *)&DBFile2IDTable::vftable;
  TFile2IDTable::~TFile2IDTable(v2);
  DBObj::~DBObj(v1);
}
// 7C5808: using guessed type __int32 (__stdcall *DBFile2IDTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C5860: using guessed type int (__stdcall *DBFile2IDTable::vftable)(IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, PStringBase<char> FileNameCopy);

//----- (004F7100) --------------------------------------------------------  // acclient.c:290391
void __cdecl NameFilterTable::Allocator()
{
  NameFilterTable *v0; // eax@1

  v0 = (NameFilterTable *)operator new(0xA8u);
  if ( v0 )
    NameFilterTable::NameFilterTable(v0);
}

//----- (004F7120) --------------------------------------------------------  // acclient.c:290401
void __cdecl PalSet::Allocator()
{
  PalSet *v0; // eax@1

  v0 = (PalSet *)operator new(0x40u);
  if ( v0 )
    PalSet::PalSet(v0, id);
}

//----- (004F7140) --------------------------------------------------------  // acclient.c:290411
void __cdecl ClothingTable::Allocator()
{
  ClothingTable *v0; // eax@1

  v0 = (ClothingTable *)operator new(0x60u);
  if ( v0 )
    ClothingTable::ClothingTable(v0, id);
}

//----- (004F7160) --------------------------------------------------------  // acclient.c:290421
void __cdecl GfxObjDegradeInfo::Allocator()
{
  GfxObjDegradeInfo *v0; // eax@1

  v0 = (GfxObjDegradeInfo *)operator new(0x40u);
  if ( v0 )
    GfxObjDegradeInfo::GfxObjDegradeInfo(v0);
}

//----- (004F7180) --------------------------------------------------------  // acclient.c:290431
void __cdecl Scene::Allocator()
{
  Scene *v0; // eax@1

  v0 = (Scene *)operator new(0x48u);
  if ( v0 )
    Scene::Scene(v0, id);
}

//----- (004F71A0) --------------------------------------------------------  // acclient.c:290441
void __cdecl CRegionDesc::Allocator()
{
  CRegionDesc *v0; // eax@1

  v0 = (CRegionDesc *)operator new(0x78u);
  if ( v0 )
    CRegionDesc::CRegionDesc(v0, id);
}

//----- (004F71C0) --------------------------------------------------------  // acclient.c:290451
void __cdecl CMasterInputMap::Allocator()
{
  CMasterInputMap *v0; // eax@1

  v0 = (CMasterInputMap *)operator new(0x148u);
  if ( v0 )
    CMasterInputMap::CMasterInputMap(v0);
}

//----- (004F71E0) --------------------------------------------------------  // acclient.c:290461
void __cdecl CSoundTable::Allocator()
{
  CSoundTable *v0; // eax@1

  v0 = (CSoundTable *)operator new(0xC0u);
  if ( v0 )
    CSoundTable::CSoundTable(v0, id);
}

//----- (004F7210) --------------------------------------------------------  // acclient.c:290471
void __cdecl ActionMap::Allocator()
{
  ActionMap *v0; // eax@1

  v0 = (ActionMap *)operator new(0x120u);
  if ( v0 )
    ActionMap::ActionMap(v0);
}

//----- (004F7230) --------------------------------------------------------  // acclient.c:290481
void __cdecl String::Allocator()
{
  String *v0; // eax@1

  v0 = (String *)operator new(0x38u);
  if ( v0 )
    String::String(v0, id);
}

//----- (004F7250) --------------------------------------------------------  // acclient.c:290491
void __cdecl ParticleEmitterInfo::Allocator()
{
  ParticleEmitterInfo *v0; // eax@1

  v0 = (ParticleEmitterInfo *)operator new(0xF8u);
  if ( v0 )
    ParticleEmitterInfo::ParticleEmitterInfo(v0);
}

//----- (004F7270) --------------------------------------------------------  // acclient.c:290501
void __cdecl PhysicsScript::Allocator()
{
  PhysicsScript *v0; // eax@1

  v0 = (PhysicsScript *)operator new(0x50u);
  if ( v0 )
    PhysicsScript::PhysicsScript(v0);
}

//----- (004F7290) --------------------------------------------------------  // acclient.c:290511
void __cdecl PhysicsScriptTable::Allocator()
{
  PhysicsScriptTable *v0; // eax@1

  v0 = (PhysicsScriptTable *)operator new(0xB0u);
  if ( v0 )
    PhysicsScriptTable::PhysicsScriptTable(v0);
}

//----- (004F72B0) --------------------------------------------------------  // acclient.c:290521
DBObj *__cdecl DBPropertyCollection::Allocator()
{
  DBPropertyCollection *v0; // eax@1
  int v1; // eax@2
  DBObj *result; // eax@3

  v0 = (DBPropertyCollection *)operator new(0xA8u);
  if ( v0 && (DBPropertyCollection::DBPropertyCollection(v0), v1) )
    result = (DBObj *)(v1 + 120);
  else
    result = 0;
  return result;
}

//----- (004F72E0) --------------------------------------------------------  // acclient.c:290536
unsigned int __thiscall DDD_DataMessage::GetCompressedSize(DDD_DataMessage *this)
{
  SmartBuffer *v1; // esi@1
  unsigned int result; // eax@2

  v1 = &this->m_cpData.m_buff;
  if ( SmartBuffer::GetSize(&this->m_cpData.m_buff) <= 4 )
    result = 0;
  else
    result = SmartBuffer::GetSize(v1) - 4;
  return result;
}

//----- (004F7300) --------------------------------------------------------  // acclient.c:290550
void __thiscall CLCache::ResetCache(CLCache *this)
{
  this->m_DDDState = 0;
  DBCache::ResetCache((DBCache *)&this->vfptr);
}

//----- (004F7330) --------------------------------------------------------  // acclient.c:290557
void __thiscall CLCache::SetNetQueue(CLCache *this, NIList<NetBlob *> *pQueue)
{
  this->m_pNetQueue = pQueue;
}

//----- (004F7340) --------------------------------------------------------  // acclient.c:290563
void __thiscall CLCache::WorkerExecuteRequest(CLCache *this, AsyncCache::CAsyncRequest *pReq)
{
  if ( pReq->Op == 3 )
    ((void (__stdcall *)(_DWORD))this->vfptr[4].Release)(pReq);
  else
    ThreadedCache::WorkerExecuteRequest((ThreadedCache *)&this->vfptr, pReq);
}

//----- (004F7360) --------------------------------------------------------  // acclient.c:290572
void __thiscall CLCache::OnRequestFinished(CLCache *this, AsyncCache::CAsyncRequest *pReq)
{
  if ( pReq->Op == 3 )
    (*(void (__thiscall **)(_DWORD, _DWORD))&this[-1].m_strDatFilePath.m_charbuffer[3].m_data[12])(
      &this[-1].m_strDatFilePath,
      pReq);
  else
    AsyncCache::OnRequestFinished((AsyncCache *)this, pReq);
}

//----- (004F7380) --------------------------------------------------------  // acclient.c:290583
void __thiscall HashBase<unsigned long>::~HashBase<unsigned long>(HashBase<unsigned long> *this)
{
  int v1; // eax@1

  v1 = this->fPlacementNew_;
  this->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v1 )
    operator delete[](this->buckets);
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (004F73A0) --------------------------------------------------------  // acclient.c:290595
void __thiscall HashBase<unsigned long>::InternalInit(HashBase<unsigned long> *this, unsigned int _table_size)
{
  signed int v2; // eax@1
  unsigned int v3; // edi@2
  unsigned int v4; // eax@3

  v2 = 1;
  this->table_size = _table_size;
  this->key_shift = 8;
  this->table_mask = 0;
  if ( _table_size > 1 )
  {
    do
    {
      v3 = v2 | this->table_mask;
      v2 *= 2;
      this->table_mask = v3;
    }
    while ( (v2 | v3) < this->table_size );
  }
  v4 = 0;
  if ( _table_size )
  {
    do
      this->buckets[v4++] = 0;
    while ( v4 < this->table_size );
  }
}

//----- (004F7400) --------------------------------------------------------  // acclient.c:290625
void __thiscall HashBaseIter<unsigned long>::DeleteCurrent(HashBaseIter<unsigned long> *this)
{
  HashBaseIter<unsigned long> *v1; // esi@1
  HashBaseData<unsigned long> *v2; // eax@2
  HashBaseData<unsigned long> *v3; // ecx@2
  HashBaseData<unsigned long> *v4; // edi@3
  HashBaseData<unsigned long> *v5; // ecx@5
  HashBase<unsigned long> *v6; // ecx@8
  int v7; // edi@9

  v1 = this;
  if ( !this->fEnd_ )
  {
    v2 = this->lastThisChain_;
    v3 = this->curPtr_;
    if ( v2 )
    {
      v2->hash_next = v3->hash_next;
      v4 = v1->lastThisChain_->hash_next;
    }
    else
    {
      v1->myHash_->buckets[v1->curBucket_] = v3->hash_next;
      v4 = v1->myHash_->buckets[v1->curBucket_];
    }
    v5 = v1->curPtr_;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    if ( v4 )
    {
LABEL_11:
      v1->curPtr_ = v4;
    }
    else
    {
      v6 = v1->myHash_;
      while ( 1 )
      {
        v7 = v1->curBucket_ + 1;
        v1->lastThisChain_ = 0;
        v1->curBucket_ = v7;
        if ( v7 >= v6->table_size )
          break;
        v4 = v6->buckets[v7];
        if ( v4 )
          goto LABEL_11;
      }
      v1->fEnd_ = 1;
      v1->curPtr_ = 0;
    }
  }
}

//----- (004F7490) --------------------------------------------------------  // acclient.c:290679
void __thiscall SerializeUsingPackDBObj::Serialize(SerializeUsingPackDBObj *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  SerializeUsingPackDBObj *v3; // ebx@1
  PackObjVtbl *v4; // eax@2
  int v5; // edi@2
  unsigned int v6; // ebx@2
  unsigned int v7; // edi@4
  unsigned int v8; // eax@4
  unsigned int v9; // eax@4
  PackObjVtbl *v10; // edx@4
  unsigned int v11; // ebp@4
  void *pCurrent; // [sp+8h] [bp-4h]@1

  pCurrent = this;
  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  if ( v2->m_flags & 1 )
  {
    v4 = v3->vfptr;
    v5 = (int)&v3->vfptr;
    io_archive = 0;
    v6 = ((int (__thiscall *)(int, Archive **, _DWORD))v4->Pack)(&v3->vfptr, &io_archive, 0);
    pCurrent = (void *)Archive::GetBytes(v2, v6);
    if ( pCurrent )
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, &pCurrent, v6);
  }
  else
  {
    v7 = Archive::GetSizeLeft(v2);
    v8 = Archive::GetSizeUsed(v2);
    v9 = Archive::PeekBytes(v2, v8, v7);
    v10 = v3->vfptr;
    v11 = v9;
    io_archive = (Archive *)v9;
    if ( ((int (__thiscall *)(int, Archive **, unsigned int))v10->UnPack)(&v3->vfptr, &io_archive, v7) )
      Archive::GetBytes(v2, (unsigned int)((char *)io_archive - v11));
    else
      Archive::RaiseError(v2);
  }
}

//----- (004F7540) --------------------------------------------------------  // acclient.c:290723
SerializeUsingPackDBObj *__thiscall SerializeUsingPackDBObj::vector_deleting_destructor(SerializeUsingPackDBObj *this, unsigned int a2)
{
  return SerializeUsingPackDBObj::scalar_deleting_destructor((SerializeUsingPackDBObj *)((char *)this - 48), a2);
}

//----- (004F7550) --------------------------------------------------------  // acclient.c:290729
void __thiscall SerializeUsingPackDBObj::~SerializeUsingPackDBObj(SerializeUsingPackDBObj *this)
{
  if ( this )
  {
    this->vfptr = (PackObjVtbl *)&PackObj::vftable;
    DBObj::~DBObj((DBObj *)&this->vfptr);
  }
  else
  {
    v0 = (size_t)&PackObj::vftable;
    DBObj::~DBObj(0);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004F7570) --------------------------------------------------------  // acclient.c:290745
void __thiscall Font::Font(Font *this)
{
  Font *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, id);
  v1->vfptr = (InterfaceVtbl *)&Font::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_ForegroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_BackgroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  Font::Begin(v1);
}
// 7C5938: using guessed type __int32 (__stdcall *Font::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004F75C0) --------------------------------------------------------  // acclient.c:290765
signed int Font::GetDBOType()
{
  return 46;
}

//----- (004F75D0) --------------------------------------------------------  // acclient.c:290771
void __thiscall Font::~Font(Font *this)
{
  Font *v1; // edi@1
  int v2; // esi@1
  int v3; // esi@4

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&Font::vftable;
  Font::End(this);
  v2 = (int)&v1->m_BackgroundSurfaceFileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_ForegroundSurfaceFileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 7C5938: using guessed type __int32 (__stdcall *Font::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004F7630) --------------------------------------------------------  // acclient.c:290791
void Font::Allocator()
{
  Font *v1; // eax@1

  v1 = (Font *)operator new(0x70u);
  if ( v1 )
    Font::Font(v1);
}

//----- (004F7650) --------------------------------------------------------  // acclient.c:290801
void __thiscall FontLocal::FontLocal(FontLocal *this)
{
  FontLocal *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, id);
  v1->vfptr = (InterfaceVtbl *)&Font::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_ForegroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_BackgroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  Font::Begin((Font *)&v1->vfptr);
  v1->vfptr = (InterfaceVtbl *)&FontLocal::vftable;
}
// 7C5938: using guessed type __int32 (__stdcall *Font::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C5990: using guessed type __int32 (__stdcall *FontLocal::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004F76A0) --------------------------------------------------------  // acclient.c:290823
signed int FontLocal::GetDBOType()
{
  return 47;
}

//----- (004F76B0) --------------------------------------------------------  // acclient.c:290829
void __thiscall FakeMessageData::Serialize(FakeMessageData *this, Archive *io_archive)
{
  FakeMessageData *v2; // edi@1
  unsigned int v3; // eax@2

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
}

//----- (004F76F0) --------------------------------------------------------  // acclient.c:290850
void __thiscall DDD_DataMessage::DDD_DataMessage(DDD_DataMessage *this)
{
  this->m_et = 63458;
  this->vfptr = (FakeMessageDataVtbl *)&DDD_DataMessage::vftable;
  this->m_cpData.m_dwOffset = 0;
  this->m_cpData.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&this->m_cpData.m_buff);
}
// 7C59E8: using guessed type void (__thiscall *DDD_DataMessage::vftable)(DDD_DataMessage *this, struct Archive *);

//----- (004F7720) --------------------------------------------------------  // acclient.c:290861
TResult *__thiscall CLCache::QueryInterface(CLCache *this, TResult *result, Turbine_GUID *i_rInterfaceType, void **o_ppOutInterface)
{
  Turbine_GUID *v4; // eax@1
  unsigned int v5; // edi@1
  QIOffset *v6; // edx@1
  TResult *v7; // eax@7
  void **v8; // edi@8
  int v9; // esi@9
  int v10; // edx@9
  char *v11; // esi@9
  QIOffset Offsets[2]; // [sp+Ch] [bp-10h]@1

  v4 = &CLCache_InterfaceType_13;
  v5 = i_rInterfaceType->m_data1;
  Offsets[0].key = (_GUID *)&CLCache_InterfaceType_13;
  Offsets[0].ofs = 0;
  Offsets[1].key = 0;
  Offsets[1].ofs = 0;
  v6 = Offsets;
  while ( v4->m_data1 != v5
       || *(_DWORD *)&v4->m_data2 != *(_DWORD *)&i_rInterfaceType->m_data2
       || *(_DWORD *)&v4->m_data4[0] != *(_DWORD *)&i_rInterfaceType->m_data4[0]
       || *(_DWORD *)&v4->m_data4[4] != *(_DWORD *)&i_rInterfaceType->m_data4[4] )
  {
    v4 = (Turbine_GUID *)v6[1].key;
    ++v6;
    if ( !v4 )
    {
      result->m_val = DBCache::QueryInterface(
                        (DBCache *)&this->vfptr,
                        (TResult *)&o_ppOutInterface,
                        i_rInterfaceType,
                        o_ppOutInterface)->m_val;
      return result;
    }
  }
  v8 = o_ppOutInterface;
  if ( o_ppOutInterface )
  {
    v9 = v6->ofs;
    v10 = *(int *)((char *)&this->vfptr + v9);
    v11 = (char *)this + v9;
    (*(void (__thiscall **)(char *))(v10 + 16))(v11);
    *v8 = v11;
  }
  v7 = result;
  result->m_val = 0;
  return v7;
}

//----- (004F77D0) --------------------------------------------------------  // acclient.c:290912
void __thiscall CLCache::WorkerExecuteBeginDDDRequest(CLCache *this, CLCache::CAsyncBeginDDDRequest *pReq)
{
  CLCache *v2; // ebx@1
  int v3; // eax@1
  MissingIteration *v4; // ecx@3
  int v5; // ebp@3
  int v6; // ecx@3
  unsigned int v7; // esi@3
  int v8; // edx@4
  MissingIteration *v9; // eax@9
  int v10; // edi@10
  QualifiedDataID *v11; // eax@12
  int v12; // esi@12
  int v13; // ecx@12
  int v14; // eax@13
  bool v15; // cf@17
  int v16; // [sp-10h] [bp-30h]@12
  int v17; // [sp-8h] [bp-28h]@12
  int v18; // [sp+Ch] [bp-14h]@2
  unsigned int idxPurge; // [sp+10h] [bp-10h]@9
  unsigned int idxIter; // [sp+14h] [bp-Ch]@1
  int idDatFile_4; // [sp+1Ch] [bp-4h]@3

  v2 = this;
  v3 = 0;
  idxIter = 0;
  if ( this->m_MissingIters.m_num )
  {
    v18 = 0;
    while ( 1 )
    {
      v4 = v2->m_MissingIters.m_data;
      v5 = *(_DWORD *)((char *)&v4->idDatFile + v3);
      v6 = *(_DWORD *)((char *)&v4->idDatFile + v3 + 4);
      v7 = 0;
      idDatFile_4 = v6;
      if ( v2->m_DatFiles.m_num )
      {
        do
        {
          if ( v5 == ((int (*)(void))v2->m_DatFiles.m_data[v7]->vfptr->GetDatFileID)() && idDatFile_4 == v8 )
            break;
          ++v7;
        }
        while ( v7 < v2->m_DatFiles.m_num );
        if ( v7 >= 4 )
          goto LABEL_17;
        v6 = idDatFile_4;
      }
      v9 = v2->m_MissingIters.m_data;
      idxPurge = 0;
      if ( v9[v18].IDsToPurge.m_num )
      {
        v10 = (int)&v2->vfptr;
        while ( 1 )
        {
          v11 = v9[v18].IDsToPurge.m_data;
          v12 = (int)&v11[idxPurge];
          v17 = v6;
          v13 = (int)&v2->vfptr;
          v16 = (int)&v11[idxPurge];
          if ( *(_DWORD *)v12 == 1 )
          {
            v14 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v10 + 152))(v13, v16, v5, v17);
            if ( v14 )
              (*(void (__thiscall **)(int, _DWORD, signed int))(*(_DWORD *)v14 + 24))(v14, *(_DWORD *)(v12 + 4), -65536);
          }
          else
          {
            (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v10 + 164))(v13, v16, v5, v17);
          }
          v9 = v2->m_MissingIters.m_data;
          ++idxPurge;
          if ( idxPurge >= v9[v18].IDsToPurge.m_num )
            break;
          v6 = idDatFile_4;
        }
      }
LABEL_17:
      v3 = v18 * 48 + 48;
      v15 = idxIter++ + 1 < v2->m_MissingIters.m_num;
      ++v18;
      if ( !v15 )
      {
        pReq->Result = 1;
        return;
      }
    }
  }
  pReq->Result = 1;
}

//----- (004F7910) --------------------------------------------------------  // acclient.c:291005
char __thiscall CLCache::InqDatIDStamp(CLCache *this, DatIDStamp *id_vstamp)
{
  DiskController *v2; // ecx@1
  DatIDStamp *v3; // eax@2
  char result; // al@2
  char v5; // [sp+4h] [bp-14h]@2

  v2 = *this->m_DatFiles.m_data;
  if ( v2 )
  {
    v3 = (DatIDStamp *)((int (__stdcall *)(char *))v2->vfptr->GetDatIDStamp)(&v5);
    DatIDStamp::DatIDStamp(id_vstamp, v3);
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F7950) --------------------------------------------------------  // acclient.c:291028
TResult *__stdcall CLCache::AdoptAndDeliverMessage(TResult *result, FakeMessageData *i_FMD)
{
  int v3; // ST04_4@2
  unsigned int v4; // eax@2
  SmartBuffer sb; // [sp+4h] [bp-30h]@2
  TransientArchive ar; // [sp+10h] [bp-24h]@1

  TransientArchive::TransientArchive(&ar, 0);
  ((void (__stdcall *)(TransientArchive *))i_FMD->vfptr->Serialize)(&ar);
  if ( !((ar.m_flags >> 2) & 1) )
  {
    Archive::GetSerializedBuffer((Archive *)&ar.vfptr, &sb);
    v3 = SmartBuffer::GetSize(&sb);
    v4 = SmartBuffer::GetBuffer(&sb);
    if ( Proto_UI::SendToDatabase((char *)v4, v3) )
    {
      SmartBuffer::Orphan(&sb);
      result->m_val = 0;
      SmartBuffer::ReleaseMasterBuffer(&sb);
      Archive::~Archive((Archive *)&ar.vfptr);
      return result;
    }
    SmartBuffer::ReleaseMasterBuffer(&sb);
  }
  result->m_val = -2147467259;
  Archive::~Archive((Archive *)&ar.vfptr);
  return result;
}

//----- (004F7A00) --------------------------------------------------------  // acclient.c:291058
IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *__thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *v2; // esi@1
  HashTableData<QualifiedDataID,MissingIteration *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable;
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
// 7C59F4: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable[4])(void *, char);

//----- (004F7A40) --------------------------------------------------------  // acclient.c:291079
IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0> *v2; // esi@1
  HashTableData<unsigned __int64,DiskController *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable;
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
// 7C59F8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable[3])(void *, char);

//----- (004F7A80) --------------------------------------------------------  // acclient.c:291100
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable;
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
// 7C59FC: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable[2])(void *, char);

//----- (004F7AC0) --------------------------------------------------------  // acclient.c:291121
void __thiscall DiskConInitInfo::DiskConInitInfo(DiskConInitInfo *this, PStringBase<char> *f, PStringBase<unsigned short> *p, DATFILE_TYPE ds_l, unsigned int dss_l, unsigned int open_flags, int fs_l, int bs_l, int dat_eng_pack_version_number, int dat_game_pack_version_number, bool engine_only)
{
  PSRefBufferCharData<char> *v11; // eax@1
  DiskConInitInfo *v12; // esi@1
  PSRefBufferCharData<unsigned short> *v13; // eax@1

  v11 = f->m_charbuffer;
  v12 = this;
  this->file.m_charbuffer = f->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1]);
  v13 = p->m_charbuffer;
  v12->path.m_charbuffer = p->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v13[-1].m_data[8]);
  v12->data_subset_lm = dss_l;
  v12->data_set_lm = ds_l;
  v12->block_size_lm = bs_l;
  v12->open_flags_lm = open_flags;
  v12->file_size_lm = fs_l;
  v12->eng_only = engine_only;
  v12->eng_pack_vnum = dat_eng_pack_version_number;
  v12->game_pack_vnum = dat_game_pack_version_number;
}

//----- (004F7B30) --------------------------------------------------------  // acclient.c:291145
CLCache::CAsyncBeginDDDRequest *__thiscall CLCache::CAsyncBeginDDDRequest::scalar_deleting_destructor(CLCache::CAsyncBeginDDDRequest *this, unsigned int a2)
{
  CLCache::CAsyncBeginDDDRequest *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CLCache::CAsyncBeginDDDRequest::vftable;
  AsyncCache::CAsyncRequest::~CAsyncRequest((AsyncCache::CAsyncRequest *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C5A00: using guessed type int (__thiscall *CLCache::CAsyncBeginDDDRequest::vftable)(void *, char);

//----- (004F7B60) --------------------------------------------------------  // acclient.c:291159
SerializeUsingPackDBObj *__thiscall SerializeUsingPackDBObj::scalar_deleting_destructor(SerializeUsingPackDBObj *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1
  char *v3; // eax@2

  v2 = this;
  if ( this )
    v3 = (char *)&this->vfptr;
  else
    v3 = 0;
  *(_DWORD *)v3 = &PackObj::vftable;
  DBObj::~DBObj((DBObj *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004F7BA0) --------------------------------------------------------  // acclient.c:291178
void FontLocal::Allocate()
{
  FontLocal *v1; // eax@1

  v1 = (FontLocal *)operator new(0x70u);
  if ( v1 )
    FontLocal::FontLocal(v1);
}

//----- (004F7BC0) --------------------------------------------------------  // acclient.c:291188
FontLocal *__thiscall Font::scalar_deleting_destructor(FontLocal *this, unsigned int a2)
{
  FontLocal *v2; // esi@1

  v2 = this;
  Font::~Font((Font *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F7BE0) --------------------------------------------------------  // acclient.c:291200
void __thiscall DDD_DataMessage::Serialize(DDD_DataMessage *this, Archive *io_archive)
{
  DDD_DataMessage *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@6

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Serializer::SerializePrimitive((long double *)&v2->m_idDatFile, io_archive);
  Archive::CheckAlignment(io_archive, 8u);
  v4 = Archive::GetBytes(io_archive, 8u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v4 = v2->m_qdid.Type;
      *(_DWORD *)(v4 + 4) = v2->m_qdid.ID.id;
    }
    else
    {
      v2->m_qdid.Type = *(_DWORD *)v4;
      v2->m_qdid.ID.id = *(_DWORD *)(v4 + 4);
    }
  }
  Serializer::SerializeObject((CliDatError *)&v2->m_idIteration, io_archive);
  Serializer::SerializeObject(&v2->m_bCompressed, io_archive);
  Cache_Pack_t::SerializeOrWindow(&v2->m_cpData, io_archive);
}

//----- (004F7C80) --------------------------------------------------------  // acclient.c:291241
void __thiscall Cache_Pack_t::SerializeOrWindow(Cache_Pack_t *this, Archive *io_rcArchive)
{
  Archive *v2; // esi@1
  Cache_Pack_t *v3; // edi@1
  unsigned int v4; // eax@1
  SmartBuffer *v5; // edi@6
  unsigned int v6; // ST10_4@7
  unsigned int v7; // eax@7
  unsigned int v8; // ebx@8
  unsigned int v9; // eax@8
  unsigned int v10; // ebp@10
  int v11; // edi@14
  SmartBuffer *v12; // eax@14
  int v13; // eax@14
  SmartBuffer v14; // [sp+8h] [bp-18h]@14
  SmartBuffer result; // [sp+14h] [bp-Ch]@14

  v2 = io_rcArchive;
  v3 = this;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_iVersion;
    else
      v3->m_iVersion = *(_DWORD *)v4;
  }
  if ( v2->m_flags & 1 )
  {
    v5 = &v3->m_buff;
    io_rcArchive = (Archive *)SmartBuffer::GetSize(v5);
    Serializer::SerializeObject((CliDatError *)&io_rcArchive, v2);
    if ( SmartBuffer::GetSize(v5) >= 4 )
    {
      v6 = SmartBuffer::GetSize(v5) - 4;
      v7 = SmartBuffer::GetBuffer(v5);
      Serializer::SerializeBytes((char *)(v7 + 4), v6, v2);
    }
  }
  else
  {
    v8 = Archive::GetSizeUsed(v2);
    Archive::CheckAlignment(v2, 4u);
    v9 = Archive::GetBytes(v2, 4u);
    if ( v9 )
    {
      if ( v2->m_flags & 1 )
      {
        v10 = (unsigned int)io_rcArchive;
        *(_DWORD *)v9 = io_rcArchive;
      }
      else
      {
        v10 = *(_DWORD *)v9;
      }
    }
    else
    {
      v10 = (unsigned int)io_rcArchive;
    }
    if ( ~(unsigned __int8)(v2->m_flags >> 2) & 1 )
    {
      Archive::SetCurrentPosition(v2, v8);
      v11 = (int)&v3->m_buff;
      v12 = Archive::GetRemainingBuffer(v2, &result);
      v13 = (int)SmartBuffer::MakeWindow(v12, &v14, 0, v10);
      SmartBuffer::operator=(v11, v13);
      SmartBuffer::ReleaseMasterBuffer(&v14);
      SmartBuffer::ReleaseMasterBuffer(&result);
      Archive::GetBytes(v2, v10);
      *(_DWORD *)SmartBuffer::GetBuffer((SmartBuffer *)v11) = 0;
    }
  }
}

//----- (004F7DB0) --------------------------------------------------------  // acclient.c:291318
void __thiscall DDD_RequestDataMessage::Serialize(DDD_RequestDataMessage *this, Archive *io_archive)
{
  DDD_RequestDataMessage *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@6

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Archive::CheckAlignment(io_archive, 8u);
  v4 = Archive::GetBytes(io_archive, 8u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v4 = v2->m_qdid.Type;
      *(_DWORD *)(v4 + 4) = v2->m_qdid.ID.id;
    }
    else
    {
      v2->m_qdid.Type = *(_DWORD *)v4;
      v2->m_qdid.ID.id = *(_DWORD *)(v4 + 4);
    }
  }
}

//----- (004F7E30) --------------------------------------------------------  // acclient.c:291355
void __thiscall DDD_ErrorMessage::Serialize(DDD_ErrorMessage *this, Archive *io_archive)
{
  DDD_ErrorMessage *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@6

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Archive::CheckAlignment(io_archive, 8u);
  v4 = Archive::GetBytes(io_archive, 8u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v4 = v2->m_qdid.Type;
      *(_DWORD *)(v4 + 4) = v2->m_qdid.ID.id;
      Serializer::SerializeObject(&v2->m_eError, io_archive);
      return;
    }
    v2->m_qdid.Type = *(_DWORD *)v4;
    v2->m_qdid.ID.id = *(_DWORD *)(v4 + 4);
  }
  Serializer::SerializeObject(&v2->m_eError, io_archive);
}

//----- (004F7EC0) --------------------------------------------------------  // acclient.c:291392
char __thiscall CThreadsafeDiskController::LoadDataEx(CThreadsafeDiskController *this, IDClass<_tagDataID,32,0> gid, Cache_Pack_t *buf_out, BTEntry *ent_out, unsigned int dwFlags)
{
  DiskController *v5; // edi@1
  SharedCriticalSection *v6; // esi@1
  char v7; // bl@1

  v5 = (DiskController *)this;
  v6 = &this->m_DiskLock;
  this->m_DiskLock.vfptr->EnterCriticalSection(&this->m_DiskLock);
  v7 = DiskController::LoadDataEx(v5, gid, buf_out, ent_out, dwFlags);
  SharedCriticalSection::LeaveCriticalSection(v6);
  return v7;
}

//----- (004F7F10) --------------------------------------------------------  // acclient.c:291407
bool __thiscall CThreadsafeDiskController::SaveDataEx(CThreadsafeDiskController *this, BTEntry *io_entry, Cache_Pack_t *buffer, unsigned int dwFlags)
{
  DiskController *v4; // edi@1
  SharedCriticalSection *v5; // esi@1
  bool v6; // bl@1

  v4 = (DiskController *)this;
  v5 = &this->m_DiskLock;
  this->m_DiskLock.vfptr->EnterCriticalSection(&this->m_DiskLock);
  v6 = DiskController::SaveDataEx(v4, io_entry, buffer, dwFlags);
  SharedCriticalSection::LeaveCriticalSection(v5);
  return v6;
}

//----- (004F7F50) --------------------------------------------------------  // acclient.c:291422
bool __thiscall CThreadsafeDiskController::DeleteData(CThreadsafeDiskController *this, IDClass<_tagDataID,32,0> gid, int idIter)
{
  DiskController *v3; // edi@1
  SharedCriticalSection *v4; // esi@1
  bool v5; // bl@1

  v3 = (DiskController *)this;
  v4 = &this->m_DiskLock;
  this->m_DiskLock.vfptr->EnterCriticalSection(&this->m_DiskLock);
  v5 = DiskController::DeleteData(v3, gid, idIter);
  SharedCriticalSection::LeaveCriticalSection(v4);
  return v5;
}

//----- (004F7F90) --------------------------------------------------------  // acclient.c:291437
char __thiscall CThreadsafeDiskController::DeleteDataByMask(CThreadsafeDiskController *this, IDClass<_tagDataID,32,0> MatchID, IDClass<_tagDataID,32,0> MatchMask)
{
  DiskController *v3; // edi@1
  SharedCriticalSection *v4; // esi@1
  char v5; // bl@1

  v3 = (DiskController *)this;
  v4 = &this->m_DiskLock;
  this->m_DiskLock.vfptr->EnterCriticalSection(&this->m_DiskLock);
  v5 = DiskController::DeleteDataByMask(v3, MatchID, MatchMask);
  SharedCriticalSection::LeaveCriticalSection(v4);
  return v5;
}

//----- (004F7FD0) --------------------------------------------------------  // acclient.c:291452
void __thiscall CMostlyConsecutiveIntSet::~CMostlyConsecutiveIntSet(CMostlyConsecutiveIntSet *this)
{
  if ( (this->m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_Ints.m_data);
}

//----- (004F7FF0) --------------------------------------------------------  // acclient.c:291459
void __thiscall DDD_InterrogationMessage::~DDD_InterrogationMessage(DDD_InterrogationMessage *this)
{
  if ( (this->m_SupportedLanguages.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_SupportedLanguages.m_data);
}

//----- (004F8010) --------------------------------------------------------  // acclient.c:291466
bool __stdcall CLCache::AsyncGetFromOtherSources(QualifiedDataID *qdid, DBOCache *pObjCache)
{
  unsigned int v3; // edx@2
  bool result; // al@2
  FakeMessageData i_FMD; // [sp+4h] [bp-10h]@2
  unsigned int v6; // [sp+Ch] [bp-8h]@2
  unsigned int v7; // [sp+10h] [bp-4h]@2

  if ( PacketController::Instance() )
  {
    v3 = qdid->ID.id;
    v6 = qdid->Type;
    i_FMD.m_et = 63459;
    i_FMD.vfptr = (FakeMessageDataVtbl *)&DDD_RequestDataMessage::vftable;
    v7 = v3;
    CLCache::AdoptAndDeliverMessage((TResult *)&qdid, &i_FMD);
    result = (signed int)qdid >= 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7C59EC: using guessed type void (__thiscall *DDD_RequestDataMessage::vftable)(DDD_RequestDataMessage *this, struct Archive *);

//----- (004F8070) --------------------------------------------------------  // acclient.c:291493
void __thiscall CLCache::NotifyDDDEvent(CLCache *this, DDDEvent EventNum, unsigned int nBytes)
{
  CLCache *v3; // edi@1
  unsigned int i; // esi@1

  v3 = this;
  for ( i = this->m_Plugins.m_num; i; --i )
    ((void (__stdcall *)(DDDEvent, unsigned int))v3->m_Plugins.m_data[i - 1]->vfptr[1].__vecDelDtor)(EventNum, nBytes);
}

//----- (004F80F0) --------------------------------------------------------  // acclient.c:291521
void __thiscall SmartArray<QualifiedDataID,1>::Reset(SmartArray<QualifiedDataID,1> *this)
{
  SmartArray<QualifiedDataID,1> *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int v3; // eax@1
  int v4; // edi@6
  int v5; // eax@7
  QualifiedDataID *v6; // ecx@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  this->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( this->m_data )
      operator delete[](&this->m_data[-1].ID);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( this->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
      do
      {
        --v4;
        v6 = v1->m_data;
        v6[v4 + 1].Type = *(_DWORD *)v5;
        v6[v4 + 1].ID.id = *(_DWORD *)(v5 + 4);
      }
      while ( v4 >= 0 );
    }
  }
}

//----- (004F8170) --------------------------------------------------------  // acclient.c:291560
void __thiscall MissingIteration::MissingIteration(MissingIteration *this)
{
  this->vfptr = (MissingIterationVtbl *)&MissingIteration::vftable;
  this->IDsToDownload.m_data = 0;
  this->IDsToDownload.m_sizeAndDeallocate = 0;
  this->IDsToDownload.m_num = 0;
  this->IDsToPurge.m_data = 0;
  this->IDsToPurge.m_sizeAndDeallocate = 0;
  this->IDsToPurge.m_num = 0;
}
// 7C5A1C: using guessed type void (__thiscall *MissingIteration::vftable)(MissingIteration *this, struct Archive *);

//----- (004F8190) --------------------------------------------------------  // acclient.c:291573
void __thiscall MissingIteration::~MissingIteration(MissingIteration *this)
{
  MissingIteration *v1; // esi@1
  QualifiedDataID *v2; // eax@2
  QualifiedDataID *v3; // esi@5

  v1 = this;
  if ( (this->IDsToPurge.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = this->IDsToPurge.m_data;
    if ( v2 )
      operator delete[](&v2[-1].ID);
  }
  if ( (v1->IDsToDownload.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v3 = v1->IDsToDownload.m_data;
    if ( v3 )
      operator delete[](&v3[-1].ID);
  }
}

//----- (004F81E0) --------------------------------------------------------  // acclient.c:291595
void __thiscall CThreadsafeDiskController::CThreadsafeDiskController(CThreadsafeDiskController *this)
{
  CThreadsafeDiskController *v1; // esi@1

  v1 = this;
  DiskController::DiskController((DiskController *)&this->vfptr);
  v1->vfptr = (DiskConBaseVtbl *)&CThreadsafeDiskController::vftable;
  SharedCriticalSection::SharedCriticalSection(&v1->m_DiskLock);
  CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&v1->m_Iters);
}
// 7C5A20: using guessed type int (__thiscall *CThreadsafeDiskController::vftable)(void *, char);

//----- (004F8210) --------------------------------------------------------  // acclient.c:291608
unsigned int __thiscall DiskConBase::GetDatFileID(DiskConBase *this)
{
  DATFILE_TYPE v1; // edx@1

  v1 = this->data_set_lm;
  return this->data_subset_lm;
}

//----- (004F8230) --------------------------------------------------------  // acclient.c:291617
bool __thiscall DiskConBase::IsInitialized(DiskConBase *this)
{
  return this->initialized_fm;
}

//----- (004F8240) --------------------------------------------------------  // acclient.c:291623
bool __thiscall DiskConBase::IsReadOnly(DiskConBase *this)
{
  return this->read_only_fm;
}

//----- (004F8250) --------------------------------------------------------  // acclient.c:291629
bool __thiscall DiskConBase::IsExpandable(DiskConBase *this)
{
  return this->expandable_fm;
}

//----- (004F8260) --------------------------------------------------------  // acclient.c:291635
int __thiscall DiskController::HowmuchFreeSpace(DiskController *this)
{
  return this->file_info_m.iBlockSize_ * this->file_info_m.iFreeBlocks_;
}

//----- (004F8270) --------------------------------------------------------  // acclient.c:291641
DatIDStamp *__thiscall DiskController::GetDatIDStamp(DiskController *this, DatIDStamp *result)
{
  DatIDStamp::DatIDStamp(result, &this->file_info_m.id_vnum);
  return result;
}

//----- (004F8290) --------------------------------------------------------  // acclient.c:291648
PStringBase<char> *__thiscall DiskController::GetFilename(DiskController *this)
{
  return &this->filename_m;
}

//----- (004F82A0) --------------------------------------------------------  // acclient.c:291654
IDClass<_tagDataID,32,0> *__thiscall DiskController::GetMasterMapDID(DiskController *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->file_info_m.master_map_id_m.id;
  return v2;
}

//----- (004F82B0) --------------------------------------------------------  // acclient.c:291664
CThreadsafeDiskController *__thiscall CThreadsafeDiskController::scalar_deleting_destructor(CThreadsafeDiskController *this, unsigned int a2)
{
  CThreadsafeDiskController *v2; // esi@1

  v2 = this;
  CMostlyConsecutiveIntSet::~CMostlyConsecutiveIntSet(&this->m_Iters);
  SharedCriticalSection::~SharedCriticalSection(&v2->m_DiskLock);
  DiskController::~DiskController((DiskController *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F82F0) --------------------------------------------------------  // acclient.c:291678
AsyncContext *__thiscall CLCache::AsyncSaveDDDMessage(CLCache *this, AsyncContext *result, DDD_DataMessage *pEvent)
{
  CLCache *v3; // ebp@1
  void *v4; // eax@1
  void *v5; // esi@1
  bool v6; // cf@4
  AsyncContext *v7; // eax@5
  AsyncContext hContext; // [sp+10h] [bp-4h]@1

  v3 = this;
  hContext.m_id = INVALID_ASYNCCONTEXT_6.m_id;
  v4 = operator new(0x58u);
  v5 = v4;
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 1;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 8) = 0;
    *((_DWORD *)v4 + 9) = 0;
    *(_DWORD *)v4 = &CAsyncSaveRequest::vftable;
    *((_DWORD *)v4 + 10) = 0;
    *((_DWORD *)v4 + 11) = 0;
    SmartBuffer::SmartBuffer((SmartBuffer *)v4 + 4);
  }
  else
  {
    v5 = 0;
  }
  *((_DWORD *)v5 + 3) = 2;
  *((_DWORD *)v5 + 4) = pEvent->m_qdid.Type;
  *((_DWORD *)v5 + 5) = pEvent->m_qdid.ID.id;
  *((_DWORD *)v5 + 10) = pEvent->m_cpData.m_dwOffset;
  *((_DWORD *)v5 + 11) = pEvent->m_cpData.m_iVersion;
  SmartBuffer::operator=((int)((char *)v5 + 48), (int)&pEvent->m_cpData.m_buff);
  *((_QWORD *)v5 + 8) = pEvent->m_idDatFile;
  v6 = pEvent->m_bCompressed != 0;
  *((_DWORD *)v5 + 20) = 0;
  *((_DWORD *)v5 + 18) = v6 ? 12 : 1;
  *((_DWORD *)v5 + 19) = pEvent->m_idIteration;
  ((void (__stdcall *)(void *))v3->vfptr->EnqueueAsyncRequest)(v5);
  if ( InterlockedDecrement((volatile LONG *)v5 + 1) )
  {
    v7 = result;
    result->m_id = hContext.m_id;
  }
  else
  {
    (**(void (__thiscall ***)(void *, signed int))v5)(v5, 1);
    v7 = result;
    result->m_id = hContext.m_id;
  }
  return v7;
}
// 795394: using guessed type int (__thiscall *CAsyncSaveRequest::vftable)(void *, char);

//----- (004F83E0) --------------------------------------------------------  // acclient.c:291736
void *__thiscall MissingIteration::vector_deleting_destructor(MissingIteration *this, unsigned int a2)
{
  char v2; // bl@1
  MissingIteration *v3; // esi@1
  int v4; // eax@2
  char *v5; // ebp@2
  MissingIteration *v6; // ecx@2
  int v7; // eax@2
  int v8; // edi@3
  int v9; // ebx@3
  int v10; // eax@4
  void *v11; // eax@5
  void *v12; // esi@6
  void *v13; // eax@8
  void *v14; // esi@9
  void *result; // eax@14

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = *((_DWORD *)&this[-1].IDsToPurge + 3);
    v5 = (char *)(&this[-1].IDsToPurge + 1);
    v6 = &this[v4];
    v7 = v4 - 1;
    if ( v7 >= 0 )
    {
      v8 = (int)&v6->IDsToDownload.m_sizeAndDeallocate;
      v9 = v7 + 1;
      do
      {
        v10 = *(_DWORD *)(v8 - 36);
        v8 -= 48;
        if ( (v10 & 0x80000000) == 0x80000000 )
        {
          v11 = *(void **)(v8 + 8);
          if ( v11 )
          {
            v12 = (char *)v11 - 4;
            vector_destructor_iterator(
              v11,
              8u,
              *((_DWORD *)v11 - 1),
              (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
            operator delete[](v12);
          }
        }
        if ( (*(_DWORD *)v8 & 0x80000000) == 0x80000000 )
        {
          v13 = *(void **)(v8 - 4);
          if ( v13 )
          {
            v14 = (char *)v13 - 4;
            vector_destructor_iterator(
              v13,
              8u,
              *((_DWORD *)v13 - 1),
              (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
            operator delete[](v14);
          }
        }
        --v9;
      }
      while ( v9 );
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    MissingIteration::~MissingIteration(this);
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}

//----- (004F84C0) --------------------------------------------------------  // acclient.c:291817
void *__thiscall CAllIterationList::PTaggedIterationList::vector_deleting_destructor(CAllIterationList::PTaggedIterationList *this, unsigned int a2)
{
  CAllIterationList::PTaggedIterationList *v2; // esi@1
  int v3; // eax@2
  char *v4; // edi@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@2
  void **v8; // esi@3
  int v9; // ebp@3
  int v10; // edx@4
  void *result; // eax@9

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = *((_DWORD *)&this[-1].List + 5);
    v4 = (char *)(&this[-1].List + 1);
    v5 = 5 * v3;
    v6 = v3 - 1;
    v7 = (int)&v2[8 * v5 / 0x28u];
    if ( v6 >= 0 )
    {
      v8 = (void **)(v7 + 20);
      v9 = v6 + 1;
      do
      {
        v10 = (int)*(v8 - 9);
        v8 -= 10;
        if ( (v10 & 0x80000000) == 0x80000000 )
          operator delete[](*v8);
        --v9;
      }
      while ( v9 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    if ( (this->List.m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](this->List.m_Ints.m_data);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004F8550) --------------------------------------------------------  // acclient.c:291868
SmartArray<QualifiedDataID,1> *__thiscall SmartArray<QualifiedDataID,1>::operator=(SmartArray<QualifiedDataID,1> *this, int a2)
{
  SmartArray<QualifiedDataID,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  QualifiedDataID *v5; // ecx@3
  unsigned int v6; // edi@5
  int v7; // eax@6
  QualifiedDataID *v8; // edx@7

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<FontReference,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        v5->Type = *(_DWORD *)v3;
        v5->ID.id = *(_DWORD *)(v3 + 4);
        v3 += 8;
        ++v5;
      }
      while ( v3 < v4 );
    }
    v6 = *(_DWORD *)(a2 + 8);
    if ( v6 < v2->m_num )
    {
      DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
      do
      {
        v8 = v2->m_data;
        v8[v6].Type = *(_DWORD *)v7;
        v8[v6++].ID.id = *(_DWORD *)(v7 + 4);
      }
      while ( v6 < v2->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (004F85F0) --------------------------------------------------------  // acclient.c:291914
void __thiscall DDD_InterrogationMessage::Serialize(DDD_InterrogationMessage *this, Archive *io_archive)
{
  DDD_InterrogationMessage *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@6
  unsigned int v5; // eax@10
  unsigned int v6; // eax@14

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_dwServersRegion;
    else
      v2->m_dwServersRegion = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_NameRuleLanguage;
    else
      v2->m_NameRuleLanguage = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v6 = Archive::GetBytes(io_archive, 4u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v6 = v2->m_dwProductID;
      SmartArray<unsigned long,1>::Serialize(&v2->m_SupportedLanguages, io_archive);
      return;
    }
    v2->m_dwProductID = *(_DWORD *)v6;
  }
  SmartArray<unsigned long,1>::Serialize(&v2->m_SupportedLanguages, io_archive);
}

//----- (004F86C0) --------------------------------------------------------  // acclient.c:291969
char __thiscall CThreadsafeDiskController::InitFile(CThreadsafeDiskController *this, DiskConInitInfo *info_r)
{
  DiskController *v2; // esi@1
  char v3; // bl@1
  PSRefBufferCharData<unsigned short> *v4; // ecx@2
  PSRefBufferCharData<unsigned short> *v5; // ecx@3
  PSRefBufferCharData<unsigned short> *v6; // ecx@3
  PStringBase<unsigned short> v8; // [sp-10h] [bp-1Ch]@3
  PStringBase<unsigned short> v9; // [sp-Ch] [bp-18h]@3
  PStringBase<unsigned short> v10; // [sp-8h] [bp-14h]@3
  PlatformString::DisplayStringMode v11; // [sp-4h] [bp-10h]@3

  v2 = (DiskController *)this;
  v3 = DiskController::InitFile((DiskController *)&this->vfptr, info_r);
  if ( v3 )
  {
    v3 &= v2->vfptr->LoadIterationList(
            (DiskConBase *)v2,
            (CMostlyConsecutiveIntSet *)&v2[1].did_tree_m.mem_root_node_m.ahead_pm);
    if ( !v3 )
    {
      v11 = 0;
      v10.m_charbuffer = v4;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, &word_794320);
      v9.m_charbuffer = v5;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v9, &word_794320);
      v8.m_charbuffer = v6;
      PStringBase<char>::to_wpstring(&info_r->file, &v8, 0);
      PlatformString::DisplayString(0xCEu, v8, v9, v10, v11);
      DiskController::Close(v2);
    }
  }
  return v3;
}

//----- (004F8730) --------------------------------------------------------  // acclient.c:292005
char __thiscall CLCache::SetRegion(CLCache *this, unsigned int rid)
{
  CLCache *v2; // edi@1
  int v3; // ecx@2
  DiskController **v4; // eax@4
  PStringBase<char> *v5; // eax@4
  char *v6; // esi@4
  char *v7; // esi@7
  char *v8; // esi@10
  PSRefBufferCharData<unsigned short> *v9; // eax@13
  PSRefBufferCharData<unsigned short> *v10; // ecx@13
  char v11; // al@13
  int v12; // ebx@13
  unsigned int v13; // ebx@14
  PSRefBufferCharData<char> *v14; // ebp@16
  DiskController *v15; // eax@16
  DiskController *v16; // esi@16
  int v17; // edx@19
  int v18; // ebp@20
  int v19; // edx@22
  char *v20; // esi@23
  int v21; // edx@25
  int v23; // ebp@27
  int v24; // edx@29
  char *v25; // esi@30
  int v26; // edx@32
  PStringBase<unsigned short> v27; // [sp-8h] [bp-6Ch]@13
  PStringBase<unsigned short> v28; // [sp-4h] [bp-68h]@13
  DiskConInitInfo *v29; // [sp+0h] [bp-64h]@4
  int v30; // [sp+14h] [bp-50h]@16
  PStringBase<char> region_s; // [sp+18h] [bp-4Ch]@4
  unsigned int CurRegion; // [sp+1Ch] [bp-48h]@1
  PStringBase<char> result; // [sp+20h] [bp-44h]@4
  PStringBase<char> rhs; // [sp+24h] [bp-40h]@4
  PStringBase<char> cell_file_s; // [sp+28h] [bp-3Ch]@7
  PStringBase<char> v36; // [sp+2Ch] [bp-38h]@4
  LookFile find_data; // [sp+30h] [bp-34h]@13
  DiskConInitInfo init_info; // [sp+3Ch] [bp-28h]@16

  v2 = this;
  CurRegion = 0;
  DBCache::GetCurrentRegion(&CurRegion);
  if ( CurRegion == rid )
    return 1;
  v3 = *((_DWORD *)v2->m_DatFiles.m_data + 2);
  if ( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = v2->m_DatFiles.m_data;
  v29 = (DiskConInitInfo *)"_";
  v4[2] = 0;
  PStringBase<char>::PStringBase<char>(&region_s, (const char *)v29);
  PStringBase<char>::append_uint32(&region_s, rid);
  PStringBase<char>::PStringBase<char>(&rhs, ".dat");
  PStringBase<char>::PStringBase<char>(&v36, "client_cell");
  PStringBase<char>::operator+(v5, &result, &region_s);
  v6 = &v36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v36.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  PStringBase<char>::operator+(&result, &cell_file_s, &rhs);
  v7 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  v8 = &rhs.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  find_data._path.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  find_data._key_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  find_data._key.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v9 = v2->m_strDatFilePath.m_charbuffer;
  v29 = 0;
  v28.m_charbuffer = v9;
  InterlockedIncrement((volatile LONG *)&v9[-1].m_data[8]);
  v27.m_charbuffer = v10;
  PStringBase<char>::to_wpstring(&cell_file_s, &v27, 0);
  v11 = LookFile::LookForFile(&find_data, v27, v28, (bool)v29);
  v12 = 4 * (v2->m_fReadOnly != 0) + 3;
  if ( v11 )
    v13 = v12 & 0xFFFFFFF7;
  else
    v13 = v12 | 8;
  v14 = cell_file_s.m_charbuffer;
  LOBYTE(v30) = v2->m_fEngineOnly;
  rhs.m_charbuffer = (PSRefBufferCharData<char> *)DBCache::s_GameCellPackVer;
  v36.m_charbuffer = (PSRefBufferCharData<char> *)DBCache::s_EngCellPackVer;
  init_info.file.m_charbuffer = cell_file_s.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&cell_file_s.m_charbuffer[-1]);
  init_info.path.m_charbuffer = v2->m_strDatFilePath.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&init_info.path.m_charbuffer[-1].m_data[8]);
  init_info.data_subset_lm = rid;
  init_info.data_set_lm = 2;
  init_info.open_flags_lm = v13;
  init_info.file_size_lm = 0x100000;
  init_info.block_size_lm = 256;
  init_info.eng_pack_vnum = (int)v36.m_charbuffer;
  init_info.game_pack_vnum = (int)rhs.m_charbuffer;
  init_info.eng_only = v30;
  v15 = (DiskController *)operator new(0x788u);
  v16 = v15;
  if ( v15 )
  {
    DiskController::DiskController(v15);
    v16->vfptr = (DiskConBaseVtbl *)&CThreadsafeDiskController::vftable;
    SharedCriticalSection::SharedCriticalSection((SharedCriticalSection *)&v16[1]);
    CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet((CMostlyConsecutiveIntSet *)&v16[1].did_tree_m.mem_root_node_m.ahead_pm);
  }
  else
  {
    v16 = 0;
  }
  *((_DWORD *)v2->m_DatFiles.m_data + 2) = v16;
  v17 = **((_DWORD **)v2->m_DatFiles.m_data + 2);
  v29 = &init_info;
  if ( (unsigned __int8)(*(int (__stdcall **)(DiskConInitInfo *))(v17 + 4))(&init_info) )
  {
    DBCache::SetRegion((DBCache *)&v2->vfptr, rid);
    CLCache::NotifyDDDEvent(v2, DDD_RegionSet, rid);
    _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&init_info);
    LookFile::~LookFile(&find_data);
    v23 = (int)&v14[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v23 + 4)) && v23 )
    {
      v24 = *(_DWORD *)v23;
      v29 = (DiskConInitInfo *)1;
      (*(void (__thiscall **)(int, signed int))v24)(v23, 1);
    }
    v25 = &region_s.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&region_s.m_charbuffer[-1]) && v25 )
    {
      v26 = *(_DWORD *)v25;
      v29 = (DiskConInitInfo *)1;
      (*(void (__thiscall **)(char *, signed int))v26)(v25, 1);
    }
    return 1;
  }
  _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&init_info);
  LookFile::~LookFile(&find_data);
  v18 = (int)&v14[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
  {
    v19 = *(_DWORD *)v18;
    v29 = (DiskConInitInfo *)1;
    (*(void (__thiscall **)(int, signed int))v19)(v18, 1);
  }
  v20 = &region_s.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&region_s.m_charbuffer[-1]) )
  {
    if ( v20 )
    {
      v21 = *(_DWORD *)v20;
      v29 = (DiskConInitInfo *)1;
      (*(void (__thiscall **)(char *, signed int))v21)(v20, 1);
    }
  }
  return 0;
}
// 7C5A20: using guessed type int (__thiscall *CThreadsafeDiskController::vftable)(void *, char);
// 8175EC: using guessed type __int32 DBCache::s_EngCellPackVer;
// 8175F4: using guessed type __int32 DBCache::s_GameCellPackVer;

//----- (004F8A50) --------------------------------------------------------  // acclient.c:292168
char __thiscall CLCache::SetLanguageInternal(CLCache *this, unsigned int language_l, bool engine_only)
{
  PSRefBufferCharData<char> *v3; // esi@1
  int v4; // ebx@1
  int v5; // ecx@1
  int v6; // ecx@2
  PSRefBufferCharData<unsigned short> *v7; // ecx@2
  LONG (__stdcall *v8)(volatile LONG *); // edi@2
  int v9; // eax@3
  PStringBase<char> *v10; // eax@3
  PStringBase<char> *v11; // ST14_4@3
  PStringBase<char> *v12; // eax@3
  PStringBase<char> *v13; // ST0C_4@3
  PStringBase<char> *v14; // eax@3
  PStringBase<char> *v15; // eax@3
  PStringBase<char> *v16; // eax@3
  PStringBase<char> *v17; // eax@3
  PStringBase<char> *v18; // ebp@3
  PSRefBufferCharData<char> *v19; // ebx@7
  char *v20; // esi@8
  char *v21; // esi@11
  char *v22; // esi@14
  char *v23; // esi@17
  char *v24; // esi@20
  char *v25; // esi@23
  char *v26; // esi@26
  char *v27; // esi@29
  PSRefBufferCharData<unsigned short> *v28; // ebp@32
  int v29; // eax@32
  int v30; // ecx@32
  char v31; // al@32
  int v32; // ecx@32
  int v33; // ecx@33
  PSRefBufferCharData<unsigned short> *v34; // ecx@33
  void (__thiscall **v35)(_DWORD, _DWORD); // eax@35
  char *v36; // esi@36
  int v37; // edx@38
  char v38; // al@38
  char v39; // cl@39
  unsigned int v40; // ST10_4@39
  PStringBase<unsigned short> *v41; // eax@39
  char *v42; // esi@39
  int v43; // edx@41
  const unsigned __int16 *v44; // eax@42
  char *v45; // esi@42
  int v46; // edx@44
  int v47; // eax@45
  int v48; // ecx@45
  int v49; // edx@46
  int v50; // eax@47
  CThreadsafeDiskController *v51; // eax@47
  int v52; // eax@48
  int v53; // ecx@50
  void (__thiscall **v54)(_DWORD, _DWORD); // edx@54
  char *v55; // esi@55
  int v56; // edx@57
  int v57; // eax@59
  PStringBase<unsigned short> v58; // [sp+14h] [bp-80h]@2
  int v59; // [sp+18h] [bp-7Ch]@2
  int v60; // [sp+1Ch] [bp-78h]@2
  int v61; // [sp+20h] [bp-74h]@2
  PStringBase<char> local_file_s; // [sp+34h] [bp-60h]@1
  PStringBase<char> language_s; // [sp+38h] [bp-5Ch]@1
  PStringBase<char> v64; // [sp+3Ch] [bp-58h]@3
  PStringBase<char> v65; // [sp+40h] [bp-54h]@3
  PStringBase<char> v66; // [sp+44h] [bp-50h]@3
  PStringBase<char> result; // [sp+48h] [bp-4Ch]@3
  PStringBase<char> v68; // [sp+4Ch] [bp-48h]@3
  PStringBase<char> v69; // [sp+50h] [bp-44h]@3
  PStringBase<char> v70; // [sp+54h] [bp-40h]@3
  PStringBase<char> v71; // [sp+58h] [bp-3Ch]@3
  PStringBase<unsigned short> v72; // [sp+5Ch] [bp-38h]@1
  LookFile find_data; // [sp+60h] [bp-34h]@1
  DiskConInitInfo local_file_info; // [sp+6Ch] [bp-28h]@39

  language_s.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v72.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = (int)&PStringBase<char>::s_NullBuffer.m_charbuffer[-2].m_data[12];
  local_file_s.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  find_data._path.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  find_data._key_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  find_data._key.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !EnumMapper::GetString(0xCu, language_l, &language_s) )
  {
    v61 = 0;
    v60 = v5;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v60, &word_794320);
    v59 = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v59, &word_794320);
    v58.m_charbuffer = v7;
    PStringBase<char>::to_wpstring(&local_file_s, &v58, 0);
    PlatformString::DisplayString(
      0xCAu,
      v58,
      (PStringBase<unsigned short>)v59,
      (PStringBase<unsigned short>)v60,
      (PlatformString::DisplayStringMode)v61);
    LookFile::~LookFile(&find_data);
    v8 = InterlockedDecrement;
    v61 = v4 + 4;
    goto LABEL_52;
  }
  PStringBase<char>::PStringBase<char>(&v71, ".dat");
  v61 = v9;
  PStringBase<char>::PStringBase<char>(&v70, "_");
  v11 = v10;
  PStringBase<char>::PStringBase<char>(&v69, "local");
  v13 = v12;
  PStringBase<char>::PStringBase<char>(&v68, "client_");
  v15 = PStringBase<char>::operator+(v14, &result, v13);
  v16 = PStringBase<char>::operator+(v15, &v66, v11);
  v17 = PStringBase<char>::operator+(v16, &v65, &language_s);
  v18 = PStringBase<char>::operator+(v17, &v64, (PStringBase<char> *)v61);
  if ( v3 != v18->m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v19 = v18->m_charbuffer;
    local_file_s.m_charbuffer = v19;
    v4 = (int)&v19[-2].m_data[12];
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  v20 = &v64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v64.m_charbuffer[-1]) && v20 )
    (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
  v21 = &v65.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v65.m_charbuffer[-1]) && v21 )
    (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
  v22 = &v66.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v66.m_charbuffer[-1]) && v22 )
    (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
  v23 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v23 )
    (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
  v24 = &v68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v68.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
  v25 = &v69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v69.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
  v26 = &v70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v70.m_charbuffer[-1]) && v26 )
    (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
  v27 = &v71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v71.m_charbuffer[-1]) && v27 )
    (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
  v28 = v72.m_charbuffer;
  v29 = *(_DWORD *)&v72.m_charbuffer[24].m_data[2];
  v61 = 0;
  v60 = v29;
  InterlockedIncrement((volatile LONG *)(v29 - 16));
  v59 = v30;
  PStringBase<char>::to_wpstring(&local_file_s, (PStringBase<unsigned short> *)&v59, 0);
  v31 = LookFile::LookForFile(&find_data, (PStringBase<unsigned short>)v59, (PStringBase<unsigned short>)v60, v61);
  v61 = 0;
  if ( !v31 )
  {
    v60 = v32;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v60, &word_794320);
    v59 = v33;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v59, &word_794320);
    v58.m_charbuffer = v34;
    PStringBase<char>::to_wpstring(&local_file_s, &v58, 0);
    PlatformString::DisplayString(
      0xCAu,
      v58,
      (PStringBase<unsigned short>)v59,
      (PStringBase<unsigned short>)v60,
      (PlatformString::DisplayStringMode)v61);
    LookFile::~LookFile(&find_data);
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    {
      v35 = *(void (__thiscall ***)(_DWORD, _DWORD))v4;
      v61 = 1;
      (*v35)(v4, 1);
    }
    v36 = &language_s.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&language_s.m_charbuffer[-1]) && v36 )
    {
      v37 = *(_DWORD *)v36;
      v61 = 1;
      (*(void (__thiscall **)(char *, signed int))v37)(v36, 1);
      return 0;
    }
    return 0;
  }
  v39 = LOBYTE(v28[15].m_data[6]);
  v60 = -1;
  v59 = -1;
  v40 = 4 * (v39 != 0) + 3;
  v41 = LookFile::GetFoundPath(&find_data, &v72);
  DiskConInitInfo::DiskConInitInfo(
    &local_file_info,
    &local_file_s,
    v41,
    LOCAL_DATFILE,
    language_l,
    v40,
    0,
    0,
    v59,
    v60,
    v61);
  v8 = InterlockedDecrement;
  v42 = (char *)&v72.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v72.m_charbuffer[-1].m_data[8]) && v42 )
  {
    v43 = *(_DWORD *)v42;
    v61 = 1;
    (*(void (__thiscall **)(char *, signed int))v43)(v42, 1);
  }
  v44 = (const unsigned __int16 *)LookFile::GetFoundPath(&find_data, &v72);
  PStringBase<unsigned short>::operator=(&local_file_info.path, v44);
  v45 = (char *)&v72.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v72.m_charbuffer[-1].m_data[8]) && v45 )
  {
    v46 = *(_DWORD *)v45;
    v61 = 1;
    (*(void (__thiscall **)(char *, signed int))v46)(v45, 1);
  }
  local_file_info.eng_pack_vnum = DBCache::s_EngDataPackVer;
  v47 = *(_DWORD *)&v28[15].m_data[0];
  local_file_info.game_pack_vnum = DBCache::s_GameDataPackVer;
  local_file_info.eng_only = engine_only;
  v48 = *(_DWORD *)(v47 + 4);
  if ( v48 )
  {
    v49 = *(_DWORD *)v48;
    v61 = 1;
    (*(void (__stdcall **)(signed int))v49)(1);
  }
  v50 = *(_DWORD *)&v28[15].m_data[0];
  v61 = 1928;
  *(_DWORD *)(v50 + 4) = 0;
  v51 = (CThreadsafeDiskController *)operator new(v61);
  if ( v51 )
    CThreadsafeDiskController::CThreadsafeDiskController(v51);
  else
    v52 = 0;
  *(_DWORD *)(*(_DWORD *)&v28[15].m_data[0] + 4) = v52;
  v53 = *(_DWORD *)(*(_DWORD *)&v28[15].m_data[0] + 4);
  if ( !v53 )
  {
    _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&local_file_info);
    LookFile::~LookFile(&find_data);
    v61 = v4 + 4;
LABEL_52:
    if ( !v8((volatile LONG *)v61) && v4 )
    {
      v54 = *(void (__thiscall ***)(_DWORD, _DWORD))v4;
      v61 = 1;
      (*v54)(v4, 1);
    }
    v55 = &language_s.m_charbuffer[-2].m_data[12];
    if ( !v8((volatile LONG *)&language_s.m_charbuffer[-1]) )
    {
      if ( v55 )
      {
        v56 = *(_DWORD *)v55;
        v61 = 1;
        (*(void (__thiscall **)(char *, signed int))v56)(v55, 1);
      }
    }
    return 0;
  }
  v57 = *(_DWORD *)v53;
  v61 = (int)&local_file_info;
  if ( (unsigned __int8)(*(int (__stdcall **)(DiskConInitInfo *))(v57 + 4))(&local_file_info) )
  {
    *(_DWORD *)&v28[9].m_data[2] = language_l;
    _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&local_file_info);
    LookFile::~LookFile(&find_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&local_file_s);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&language_s);
    v38 = 1;
  }
  else
  {
    _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&local_file_info);
    LookFile::~LookFile(&find_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&local_file_s);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&language_s);
    v38 = 0;
  }
  return v38;
}

//----- (004F8F40) --------------------------------------------------------  // acclient.c:292462
int __thiscall MissingIteration::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(this + 20), a2 + 20);
  SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v2 + 32), a2 + 32);
  return v2;
}

//----- (004F8F80) --------------------------------------------------------  // acclient.c:292476
void __thiscall DDD_BeginDDDMessage::~DDD_BeginDDDMessage(DDD_BeginDDDMessage *this)
{
  MissingIteration *v1; // ecx@2

  if ( (this->m_MissingIterations.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_MissingIterations.m_data;
    if ( v1 )
      MissingIteration::vector_deleting_destructor(v1, 3u);
  }
}

//----- (004F8FA0) --------------------------------------------------------  // acclient.c:292489
DiskController *__thiscall CLCache::GetDiskController(CLCache *this, QualifiedDataID *qdid, unsigned __int64 idRequestedDatFile)
{
  CLCache *v3; // esi@1
  DiskController *v4; // eax@3
  const unsigned int v5; // edi@4
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@2

  v3 = this;
  if ( idRequestedDatFile
    && (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
          (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_DatFileByIDTable,
          &result,
          &idRequestedDatFile),
        result.m_currElement) )
  {
    v4 = (DiskController *)LODWORD(result.m_currElement->m_data);
  }
  else
  {
    v5 = qdid->Type;
    if ( !qdid->Type )
      v5 = MasterDBMap::DivineType(qdid->ID);
    if ( MasterDBMap::IsPortalType(v5) )
    {
      if ( (unsigned __int8)(*(int (__stdcall **)(unsigned int, _DWORD))(**(_DWORD **)(v3->m_Plugins.m_num + 12) + 28))(
                              qdid->ID.id,
                              0) )
        v4 = *(DiskController **)(v3->m_Plugins.m_num + 12);
      else
        v4 = *(DiskController **)v3->m_Plugins.m_num;
    }
    else if ( MasterDBMap::IsCellType(v5) )
    {
      v4 = *(DiskController **)(v3->m_Plugins.m_num + 8);
    }
    else if ( MasterDBMap::IsLocalType(v5) )
    {
      v4 = *(DiskController **)(v3->m_Plugins.m_num + 4);
    }
    else
    {
      v4 = 0;
    }
  }
  return v4;
}

//----- (004F9090) --------------------------------------------------------  // acclient.c:292537
bool __thiscall CLCache::IsDatFileLoaded(CLCache *this, unsigned __int64 idDatFile)
{
  bool v2; // al@2
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_DatFileByIDTable,
    &result,
    &idDatFile);
  if ( result.m_currElement )
    v2 = (*(int (**)(void))(*LODWORD(result.m_currElement->m_data) + 60))();
  else
    v2 = 0;
  return v2;
}

//----- (004F90D0) --------------------------------------------------------  // acclient.c:292554
LongNIValHash<unsigned long> *__thiscall LongNIValHash<unsigned long>::vector_deleting_destructor(LongNIValHash<unsigned long> *this, unsigned int a2)
{
  LongNIValHash<unsigned long> *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)LongNIValHash<unsigned long>::vftable;
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)this);
  v3 = v2->fPlacementNew_;
  v2->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](v2->buckets);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C5A14: using guessed type int (__thiscall *LongNIValHash<unsigned long>::vftable[2])(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (004F9110) --------------------------------------------------------  // acclient.c:292574
LongNIValHash<LongHash<MotionData> *> *__thiscall LongNIValHash<LongHash<MotionData> *>::vector_deleting_destructor(LongNIValHash<LongHash<MotionData> *> *this, unsigned int a2)
{
  LongNIValHash<LongHash<MotionData> *> *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<LongHash<MotionData> *>::vftable;
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)this);
  v3 = v2->fPlacementNew_;
  v2->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](v2->buckets);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C5A18: using guessed type int (__thiscall *LongNIValHash<LongHash<MotionData> *>::vftable)(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (004F9150) --------------------------------------------------------  // acclient.c:292594
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned __int64,DiskController *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned __int64,DiskController *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C59F8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable[3])(void *, char);

//----- (004F91E0) --------------------------------------------------------  // acclient.c:292627
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C59FC: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable[2])(void *, char);

//----- (004F9270) --------------------------------------------------------  // acclient.c:292660
void __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<QualifiedDataID,MissingIteration *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<QualifiedDataID,MissingIteration *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C59F4: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable[4])(void *, char);

//----- (004F9300) --------------------------------------------------------  // acclient.c:292693
void __thiscall SmartArray<MissingIteration,1>::Reset(SmartArray<MissingIteration,1> *this)
{
  SmartArray<MissingIteration,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // ebx@7
  int v6; // ecx@8
  int v7; // eax@8
  int v8; // esi@8
  int v9; // [sp+8h] [bp-34h]@7
  MissingIteration v10; // [sp+Ch] [bp-30h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      MissingIteration::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v9 = v4 + 1;
      do
      {
        v6 = v10.idIteration;
        v7 = HIDWORD(v10.idDatFile);
        v8 = (int)&v1->m_data[v5];
        *(_DWORD *)(v8 + 8) = LODWORD(v10.idDatFile);
        *(_DWORD *)(v8 + 16) = v6;
        v10.vfptr = (MissingIterationVtbl *)&MissingIteration::vftable;
        v10.IDsToDownload.m_data = 0;
        v10.IDsToDownload.m_sizeAndDeallocate = 0;
        v10.IDsToDownload.m_num = 0;
        v10.IDsToPurge.m_data = 0;
        v10.IDsToPurge.m_sizeAndDeallocate = 0;
        v10.IDsToPurge.m_num = 0;
        *(_DWORD *)(v8 + 12) = v7;
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 20), (int)&v10.IDsToDownload);
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 32), (int)&v10.IDsToPurge);
        MissingIteration::~MissingIteration(&v10);
        --v5;
        --v9;
      }
      while ( v9 );
    }
  }
}
// 7C5A1C: using guessed type void (__thiscall *MissingIteration::vftable)(MissingIteration *this, struct Archive *);

//----- (004F93E0) --------------------------------------------------------  // acclient.c:292752
List<AsyncCache::CAsyncRequest *> *__thiscall List<AsyncCache::CAsyncRequest *>::scalar_deleting_destructor(List<AsyncCache::CAsyncRequest *> *this, unsigned int a2)
{
  List<AsyncCache::CAsyncRequest *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<AsyncCache::CAsyncRequest *>Vtbl *)&List<AsyncCache::CAsyncRequest *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C5AD8: using guessed type int (__thiscall *List<AsyncCache::CAsyncRequest *>::vftable)(void *, char);

//----- (004F9410) --------------------------------------------------------  // acclient.c:292766
char __thiscall SmartArray<MissingIteration,1>::grow(SmartArray<MissingIteration,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<MissingIteration,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<MissingIteration,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](48 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x30u,
        i_nSize,
        (void *(__thiscall *)(void *))MissingIteration::MissingIteration);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              MissingIteration::operator=(v8 * 48 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              MissingIteration::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (MissingIteration *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (004F94E0) --------------------------------------------------------  // acclient.c:292830
void __thiscall CMotionTable::CMotionTable(CMotionTable *this)
{
  CMotionTable *v1; // esi@1
  signed int v2; // eax@1
  int v3; // edx@2
  unsigned int v4; // eax@3
  signed int v5; // eax@5
  int v6; // edx@6
  unsigned int v7; // eax@7
  signed int v8; // eax@9
  int v9; // edx@10
  unsigned int v10; // eax@11
  signed int v11; // eax@13
  int v12; // edx@14
  unsigned int v13; // eax@15

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, id);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&CMotionTable::vftable;
  v1->vfptr = (PackObjVtbl *)&CMotionTable::vftable;
  v1->style_defaults.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->style_defaults.fPlacementNew_ = 0;
  v1->style_defaults.buckets = (HashBaseData<unsigned long> **)operator new[](0x100u);
  v1->style_defaults.table_size = 64;
  v1->style_defaults.key_shift = 8;
  v1->style_defaults.table_mask = 0;
  v2 = 1;
  do
  {
    v3 = v2 | v1->style_defaults.table_mask;
    v2 *= 2;
    v1->style_defaults.table_mask = v3;
  }
  while ( (v2 | (unsigned int)v3) < v1->style_defaults.table_size );
  v4 = 0;
  do
    v1->style_defaults.buckets[v4++] = 0;
  while ( v4 < v1->style_defaults.table_size );
  v1->style_defaults.vfptr = (HashBase<unsigned long>Vtbl *)LongNIValHash<unsigned long>::vftable;
  v1->cycles.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->cycles.fPlacementNew_ = 0;
  v1->cycles.buckets = (HashBaseData<unsigned long> **)operator new[](0x100u);
  v1->cycles.table_size = 64;
  v1->cycles.key_shift = 8;
  v1->cycles.table_mask = 0;
  v5 = 1;
  do
  {
    v6 = v5 | v1->cycles.table_mask;
    v5 *= 2;
    v1->cycles.table_mask = v6;
  }
  while ( (v5 | (unsigned int)v6) < v1->cycles.table_size );
  v7 = 0;
  do
    v1->cycles.buckets[v7++] = 0;
  while ( v7 < v1->cycles.table_size );
  v1->cycles.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->modifiers.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->modifiers.fPlacementNew_ = 0;
  v1->modifiers.buckets = (HashBaseData<unsigned long> **)operator new[](0x40u);
  v1->modifiers.table_size = 16;
  v1->modifiers.key_shift = 8;
  v1->modifiers.table_mask = 0;
  v8 = 1;
  do
  {
    v9 = v8 | v1->modifiers.table_mask;
    v8 *= 2;
    v1->modifiers.table_mask = v9;
  }
  while ( (v8 | (unsigned int)v9) < v1->modifiers.table_size );
  v10 = 0;
  do
    v1->modifiers.buckets[v10++] = 0;
  while ( v10 < v1->modifiers.table_size );
  v1->modifiers.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->links.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->links.fPlacementNew_ = 0;
  v1->links.buckets = (HashBaseData<unsigned long> **)operator new[](0x100u);
  v1->links.table_size = 64;
  v1->links.key_shift = 8;
  v1->links.table_mask = 0;
  v11 = 1;
  do
  {
    v12 = v11 | v1->links.table_mask;
    v11 *= 2;
    v1->links.table_mask = v12;
  }
  while ( (v11 | (unsigned int)v12) < v1->links.table_size );
  v13 = 0;
  do
    v1->links.buckets[v13++] = 0;
  while ( v13 < v1->links.table_size );
  v1->links.vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<LongHash<MotionData> *>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5A14: using guessed type int (__thiscall *LongNIValHash<unsigned long>::vftable[2])(void *, char);
// 7C5A18: using guessed type int (__thiscall *LongNIValHash<LongHash<MotionData> *>::vftable)(void *, char);
// 7C5ADC: using guessed type int (__stdcall *CMotionTable::vftable)(int);
// 7C5AF0: using guessed type __int32 (__stdcall *CMotionTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (004F96B0) --------------------------------------------------------  // acclient.c:292936
CMotionTable *__thiscall CMotionTable::vector_deleting_destructor(CMotionTable *this, unsigned int a2)
{
  CMotionTable *v2; // esi@1

  v2 = this;
  CMotionTable::~CMotionTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F96D0) --------------------------------------------------------  // acclient.c:292948
CMotionTable *__thiscall CMotionTable::vector_deleting_destructor(CMotionTable *this, unsigned int a2)
{
  return CMotionTable::vector_deleting_destructor((CMotionTable *)((char *)this - 48), a2);
}

//----- (004F96E0) --------------------------------------------------------  // acclient.c:292954
void CMotionTable::Allocator()
{
  CMotionTable *v1; // eax@1

  v1 = (CMotionTable *)operator new(0xA0u);
  if ( v1 )
    CMotionTable::CMotionTable(v1);
}

//----- (004F9700) --------------------------------------------------------  // acclient.c:292964
void __thiscall DDD_InterrogationResponseMessage::Serialize(DDD_InterrogationResponseMessage *this, Archive *io_archive)
{
  DDD_InterrogationResponseMessage *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@6
  unsigned int v5; // eax@10

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_ClientLanguage;
    else
      v2->m_ClientLanguage = *(_DWORD *)v4;
  }
  v2->m_ItersWithKeys.vfptr->Serialize(&v2->m_ItersWithKeys, io_archive);
  v2->m_ItersWithoutKeys.vfptr->Serialize(&v2->m_ItersWithoutKeys, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_dwFlags;
    else
      v2->m_dwFlags = *(_DWORD *)v5;
  }
}

//----- (004F97B0) --------------------------------------------------------  // acclient.c:293007
char __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::resize_internal(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<QualifiedDataID,MissingIteration *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<QualifiedDataID,MissingIteration *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<QualifiedDataID,MissingIteration *> **v9; // ebx@7
  HashTableData<QualifiedDataID,MissingIteration *> *v10; // ecx@7
  HashTableData<QualifiedDataID,MissingIteration *> *v11; // eax@9
  HashTableData<QualifiedDataID,MissingIteration *> *v12; // edx@10
  HashTableData<QualifiedDataID,MissingIteration *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned int v16; // edx@23
  HashTableData<QualifiedDataID,MissingIteration *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<QualifiedDataID,MissingIteration *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<QualifiedDataID,MissingIteration *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<QualifiedDataID,MissingIteration *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = (v5->m_hashKey.Type + v5->m_hashKey.ID.id) % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<QualifiedDataID,MissingIteration *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<QualifiedDataID,MissingIteration *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004F98F0) --------------------------------------------------------  // acclient.c:293125
SmartArray<MissingIteration,1> *__thiscall SmartArray<MissingIteration,1>::operator=(SmartArray<MissingIteration,1> *this, int a2)
{
  int v2; // ebx@1
  SmartArray<MissingIteration,1> *v3; // edi@1
  unsigned int v4; // esi@3
  int v5; // ebx@4
  unsigned int v6; // ebx@7
  int v7; // eax@8
  int v8; // esi@10
  int v10; // [sp+Ch] [bp-34h]@3
  int i; // [sp+Ch] [bp-34h]@8
  int v12; // [sp+18h] [bp-28h]@0
  int v13; // [sp+1Ch] [bp-24h]@0
  int v14; // [sp+20h] [bp-20h]@0
  int v15; // [sp+24h] [bp-1Ch]@10
  int v16; // [sp+28h] [bp-18h]@10
  int v17; // [sp+2Ch] [bp-14h]@10
  int v18; // [sp+30h] [bp-10h]@10
  int v19; // [sp+34h] [bp-Ch]@10
  int v20; // [sp+38h] [bp-8h]@10

  v2 = a2;
  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<MissingIteration,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v10 = *(_DWORD *)a2 + 48 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v10 )
    {
      v5 = (int)&v3->m_data->idIteration;
      do
      {
        *(_DWORD *)(v5 - 8) = *(_DWORD *)(v4 + 8);
        *(_DWORD *)(v5 - 4) = *(_DWORD *)(v4 + 12);
        *(_DWORD *)v5 = *(_DWORD *)(v4 + 16);
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v5 + 4), v4 + 20);
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v5 + 16), v4 + 32);
        v4 += 48;
        v5 += 48;
      }
      while ( v4 < v10 );
      v2 = a2;
    }
    v6 = *(_DWORD *)(v2 + 8);
    if ( v6 < v3->m_num )
    {
      v7 = 48 * v6;
      for ( i = 48 * v6; ; v7 = i )
      {
        v8 = (int)((char *)v3->m_data + v7);
        *(_DWORD *)(v8 + 8) = v12;
        *(_DWORD *)(v8 + 16) = v14;
        v15 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v20 = 0;
        *(_DWORD *)(v8 + 12) = v13;
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 20), (int)&v15);
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 32), (int)&v18);
        ++v6;
        i += 48;
        if ( v6 >= v3->m_num )
          break;
      }
    }
    v3->m_num = *(_DWORD *)(a2 + 8);
  }
  return v3;
}

//----- (004F9A20) --------------------------------------------------------  // acclient.c:293199
void __thiscall ThreadedCache::~ThreadedCache(ThreadedCache *this)
{
  ThreadedCache *v1; // esi@1

  v1 = this;
  PortalEvent::~PortalEvent(&this->m_evtWorkerHasJobs);
  operator delete[](v1->m_WorkerThreadReplyQueue.buckets_);
  v1->m_WorkerThreadReplyQueue.buckets_ = 0;
  SharedCriticalSection::~SharedCriticalSection(&v1->m_WorkerThreadReplyQueue.m_backupListCritSec);
  v1->m_WorkerThreadReplyQueue.m_backupList.vfptr = (List<AsyncCache::CAsyncRequest *>Vtbl *)&List<AsyncCache::CAsyncRequest *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_WorkerThreadReplyQueue.m_backupList);
  operator delete[](v1->m_WorkerThreadJobQueue.buckets_);
  v1->m_WorkerThreadJobQueue.buckets_ = 0;
  SharedCriticalSection::~SharedCriticalSection(&v1->m_WorkerThreadJobQueue.m_backupListCritSec);
  v1->m_WorkerThreadJobQueue.m_backupList.vfptr = (List<AsyncCache::CAsyncRequest *>Vtbl *)&List<AsyncCache::CAsyncRequest *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_WorkerThreadJobQueue.m_backupList);
  if ( v1 )
  {
    PortalThread::~PortalThread((PortalThread *)&v1->vfptr);
    DBCache::~DBCache((DBCache *)&v1->vfptr);
  }
  else
  {
    PortalThread::~PortalThread(0);
    DBCache::~DBCache(0);
  }
}
// 7C5AD8: using guessed type int (__thiscall *List<AsyncCache::CAsyncRequest *>::vftable)(void *, char);

//----- (004F9AC0) --------------------------------------------------------  // acclient.c:293229
void __thiscall CLCache::OnBeginDDD(CLCache *this, DDD_BeginDDDMessage *pEvent)
{
  CLCache *v2; // esi@1
  void *v3; // eax@3

  v2 = this;
  this->m_DDDState = 2;
  SmartArray<MissingIteration,1>::operator=(&this->m_MissingIters, (int)&pEvent->m_MissingIterations);
  if ( pEvent->m_cbDataExpected != v2->m_cbEarlySaves )
    CLCache::NotifyDDDEvent(v2, DDD_PatchtimeBegin, pEvent->m_cbDataExpected - v2->m_cbEarlySaves);
  v3 = operator new(0x28u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 1;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    *(_DWORD *)v3 = &CLCache::CAsyncBeginDDDRequest::vftable;
    *((_DWORD *)v3 + 3) = 3;
  }
  else
  {
    v3 = 0;
  }
  v2->vfptr->EnqueueAsyncRequest((AsyncCache *)&v2->vfptr, (AsyncCache::CAsyncRequest *)v3);
}
// 7C5A00: using guessed type int (__thiscall *CLCache::CAsyncBeginDDDRequest::vftable)(void *, char);

//----- (004F9B40) --------------------------------------------------------  // acclient.c:293260
void __thiscall DDD_BeginDDDMessage::Serialize(DDD_BeginDDDMessage *this, Archive *io_archive)
{
  DDD_BeginDDDMessage *v2; // edi@1
  unsigned int v3; // eax@2

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = v2->m_et;
      else
        v2->m_et = *(_DWORD *)v3;
    }
  }
  Serializer::SerializeObject((CliDatError *)&v2->m_cbDataExpected, io_archive);
  SmartArray<MissingIteration,1>::Serialize(&v2->m_MissingIterations, io_archive);
}

//----- (004F9BA0) --------------------------------------------------------  // acclient.c:293283
void __thiscall SmartArray<MissingIteration,1>::Serialize(SmartArray<MissingIteration,1> *this, Archive *io_rcArchive)
{
  SmartArray<MissingIteration,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  int v5; // ebp@1
  unsigned int i; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  v5 = 0;
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<MissingIteration,1>::SetNElements(v2, v3, 1);
  }
  for ( i = 0; i < v2->m_num; ++v5 )
  {
    v2->m_data[v5].vfptr->Serialize(&v2->m_data[v5], io_rcArchive);
    ++i;
  }
}

//----- (004F9C30) --------------------------------------------------------  // acclient.c:293321
char __thiscall SmartArray<MissingIteration,1>::SetNElements(SmartArray<MissingIteration,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<MissingIteration,1> *v3; // ebx@1
  const unsigned int v4; // ebp@1
  unsigned int v5; // eax@3
  char result; // al@5
  const unsigned int v7; // ebp@8
  int v8; // esi@9
  int v9; // [sp+10h] [bp-28h]@0
  int v10; // [sp+14h] [bp-24h]@0
  int v11; // [sp+18h] [bp-20h]@0
  int v12; // [sp+1Ch] [bp-1Ch]@9
  int v13; // [sp+20h] [bp-18h]@9
  int v14; // [sp+24h] [bp-14h]@9
  int v15; // [sp+28h] [bp-10h]@9
  int v16; // [sp+2Ch] [bp-Ch]@9
  int v17; // [sp+30h] [bp-8h]@9
  const unsigned int i_bGrowExactlya; // [sp+40h] [bp+8h]@7

  v3 = this;
  v4 = i_nSize;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    i_bGrowExactlya = i_nSize;
    if ( i_nSize < this->m_num )
    {
      v7 = i_nSize;
      do
      {
        v8 = (int)&v3->m_data[v7];
        *(_DWORD *)(v8 + 8) = v9;
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        v16 = 0;
        v17 = 0;
        *(_DWORD *)(v8 + 12) = v10;
        *(_DWORD *)(v8 + 16) = v11;
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 20), (int)&v12);
        SmartArray<QualifiedDataID,1>::operator=((SmartArray<QualifiedDataID,1> *)(v8 + 32), (int)&v15);
        ++v7;
        ++i_bGrowExactlya;
      }
      while ( i_bGrowExactlya < v3->m_num );
      v4 = i_nSize;
    }
    goto LABEL_11;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<MissingIteration,1>::grow(v3, v5);
  if ( result )
  {
LABEL_11:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}

//----- (004F9D10) --------------------------------------------------------  // acclient.c:293385
char __thiscall CLCache::Init(CLCache *this, PStringBase<char> *data_filename, bool read_only_f, bool cell_lru_f, bool portal_lru_f, int engine_only_f, unsigned int local_lang_i, int region_i)
{
  signed int v8; // eax@4
  DBCache *v9; // ecx@7
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v10; // eax@7
  PStringBase<char> v11; // ST14_4@9
  PStringBase<char> v12; // ST10_4@9
  PStringBase<unsigned short> *v13; // ebp@9
  PSRefBufferCharData<unsigned short> *v14; // eax@9
  int v15; // edi@10
  PSRefBufferCharData<unsigned short> *v16; // ebp@13
  unsigned int v17; // ebx@14
  int v18; // ecx@17
  unsigned int v19; // ecx@18
  bool v20; // bl@20
  int v21; // ebp@20
  int v22; // edi@20
  char *v23; // esi@20
  LONG (__stdcall *v24)(volatile LONG *); // edi@20
  DiskController *v25; // eax@24
  unsigned int v26; // esi@24
  unsigned int v27; // ecx@27
  DiskController *v28; // eax@29
  unsigned int v29; // esi@29
  unsigned int v30; // esi@32
  IDClass<_tagDataID,32,0> *v31; // eax@33
  signed int v32; // ebx@38
  int v33; // ecx@39
  __int64 v34; // rax@40
  int v35; // ebp@41
  int v36; // edx@41
  int v37; // edi@41
  int v38; // esi@41
  void *v39; // eax@41
  void *v40; // edi@42
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v41; // ecx@44
  unsigned int v42; // eax@44
  char *v43; // esi@56
  char *v44; // esi@59
  char *v45; // esi@62
  char *v46; // esi@65
  char *v47; // esi@68
  char v49; // [sp+2Fh] [bp-45h]@9
  DBCache *v50; // [sp+30h] [bp-44h]@1
  unsigned int dwOpenFlags; // [sp+34h] [bp-40h]@9
  IDClass<_tagDataID,32,0> v52; // [sp+38h] [bp-3Ch]@20
  PStringBase<unsigned short> result; // [sp+3Ch] [bp-38h]@20
  LookFile find_data; // [sp+40h] [bp-34h]@9
  DiskConInitInfo dciInfo; // [sp+4Ch] [bp-28h]@20

  v50 = (DBCache *)this;
  DBCache::Init(0, &PStringBase<char>::null_string);
  LOBYTE(v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[7]) = read_only_f;
  BYTE1(v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[7]) = engine_only_f;
  if ( ((unsigned int)v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[5] & 0x7FFFFFFF) >= 4 )
  {
    v8 = 4;
    if ( v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[6] > (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)4 )
    {
      do
        *(&v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id + v8++) = 0;
      while ( (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)v8 < v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[6] );
    }
    goto LABEL_6;
  }
  if ( SmartArray<int,1>::grow(
         (SmartArray<QuickButton *,1> *)&v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4],
         4u) )
LABEL_6:
    v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[6] = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)4;
  v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[9] = 0;
  v9 = v50;
  v10 = 0;
  if ( v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[6] )
  {
    do
    {
      *(&v9[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id + (_DWORD)v10) = 0;
      v9 = v50;
      v10 = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)((char *)v10 + 1);
    }
    while ( v10 < v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[6] );
  }
  find_data._path.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  find_data._key_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  find_data._key.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v11.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
  v12.m_charbuffer = data_filename->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&data_filename->m_charbuffer[-1]);
  v49 = LookFile::LookForFile(&find_data, v12, v11, 1);
  v13 = LookFile::GetFoundPath(&find_data, (PStringBase<unsigned short> *)&dwOpenFlags);
  v14 = (PSRefBufferCharData<unsigned short> *)v50[2].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[1];
  if ( v14 != v13->m_charbuffer )
  {
    v15 = (int)&v14[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v14[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    v16 = v13->m_charbuffer;
    v50[2].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[1] = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)v16;
    InterlockedIncrement((volatile LONG *)&v16[-1].m_data[8]);
  }
  v17 = dwOpenFlags - 20;
  if ( !InterlockedDecrement((volatile LONG *)(dwOpenFlags - 20 + 4)) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  v18 = (portal_lru_f != 0) + 2;
  if ( LOBYTE(v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[7]) )
    v19 = v18 | 4;
  else
    v19 = v18 & 0xFFFFFFFB;
  v20 = BYTE1(v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[7]);
  v21 = DBCache::s_GameDataPackVer;
  v22 = DBCache::s_EngDataPackVer;
  dwOpenFlags = v19;
  v52.id = (unsigned int)LookFile::GetFoundPath(&find_data, &result);
  dciInfo.file.m_charbuffer = data_filename->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&dciInfo.file.m_charbuffer[-1]);
  dciInfo.path.m_charbuffer = *(PSRefBufferCharData<unsigned short> **)v52.id;
  InterlockedIncrement((volatile LONG *)&dciInfo.path.m_charbuffer[-1].m_data[8]);
  v23 = (char *)&result.m_charbuffer[-1].m_data[6];
  dciInfo.eng_pack_vnum = v22;
  v24 = InterlockedDecrement;
  dciInfo.data_set_lm = 1;
  dciInfo.data_subset_lm = 0;
  dciInfo.open_flags_lm = dwOpenFlags;
  dciInfo.file_size_lm = 0;
  dciInfo.block_size_lm = 0;
  dciInfo.game_pack_vnum = v21;
  dciInfo.eng_only = v20;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v23 )
    (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
  if ( v49 )
  {
    v25 = (DiskController *)operator new(0x788u);
    v26 = (unsigned int)v25;
    if ( v25 )
    {
      DiskController::DiskController(v25);
      *(_DWORD *)v26 = &CThreadsafeDiskController::vftable;
      SharedCriticalSection::SharedCriticalSection((SharedCriticalSection *)(v26 + 1872));
      CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet((CMostlyConsecutiveIntSet *)(v26 + 1908));
    }
    else
    {
      v26 = 0;
    }
    v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id = v26;
    v27 = v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id;
    v49 = v27 != 0;
    if ( v27 )
    {
      v49 = (*(int (__stdcall **)(DiskConInitInfo *))(*(_DWORD *)v27 + 4))(&dciInfo);
      if ( v49 )
      {
        v28 = (DiskController *)operator new(0x788u);
        v29 = (unsigned int)v28;
        if ( v28 )
        {
          DiskController::DiskController(v28);
          *(_DWORD *)v29 = &CThreadsafeDiskController::vftable;
          SharedCriticalSection::SharedCriticalSection((SharedCriticalSection *)(v29 + 1872));
          CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet((CMostlyConsecutiveIntSet *)(v29 + 1908));
        }
        else
        {
          v29 = 0;
        }
        v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4][1].m_hashKey.m_id = v29;
        v30 = v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4][1].m_hashKey.m_id;
        v49 = v30 != 0;
        if ( v30 )
        {
          v31 = (IDClass<_tagDataID,32,0> *)(*(int (__stdcall **)(PStringBase<unsigned short> *))(*(_DWORD *)v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id
                                                                                                + 72))(&result);
          DBCache::SetMasterMapDID(v50, &v52, (IDClass<_tagDataID,32,0>)v31->id);
          ((void (*)(void))v50->vfptr[4].QueryInterface)();
          if ( region_i )
            v49 = ((int (__stdcall *)(int))v50->vfptr[2].AddRef)(region_i);
          if ( v49 && local_lang_i )
            v49 = ((int (__stdcall *)(unsigned int, int))v50->vfptr[3].IUnknown_AddRef)(local_lang_i, engine_only_f);
        }
      }
    }
  }
  v32 = 0;
  dwOpenFlags = 0;
  do
  {
    v33 = *(unsigned int *)((char *)&v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id + v32);
    if ( v33 )
    {
      LODWORD(v34) = (*(int (**)(void))(*(_DWORD *)v33 + 56))();
      if ( v34 )
      {
        v35 = (*(int (**)(void))(**(_DWORD **)((char *)&v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4]->m_hashKey.m_id
                                             + v32)
                               + 56))();
        v37 = v36;
        v38 = (int)((char *)v50[1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[4] + v32);
        v39 = operator new(0x18u);
        if ( v39 )
        {
          *((_DWORD *)v39 + 1) = v37;
          *(_DWORD *)v39 = v35;
          *((_DWORD *)v39 + 2) = 0;
          *((_DWORD *)v39 + 4) = *(_DWORD *)v38;
          v40 = v39;
        }
        else
        {
          v40 = 0;
        }
        v41 = (HashTableData<QualifiedDataID,CAsyncGetRequest *> *)((char *)v50[2].m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[20]
                                                                  + 4
                                                                  * (*(_QWORD *)v40
                                                                   % (unsigned __int64)v50[2].m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[22]));
        v42 = v41->m_hashKey.Type;
        if ( !v41->m_hashKey.Type )
          goto LABEL_50;
        while ( *(_DWORD *)v42 != *(_DWORD *)v40 || *(_DWORD *)(v42 + 4) != *((_DWORD *)v40 + 1) )
        {
          v42 = *(_DWORD *)(v42 + 8);
          if ( !v42 )
            goto LABEL_50;
        }
        if ( v42 )
        {
          operator delete(v40);
        }
        else
        {
LABEL_50:
          *((_DWORD *)v40 + 2) = v41->m_hashKey.Type;
          v41->m_hashKey.Type = (unsigned int)v40;
          if ( v41 < v50[2].m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[21] )
            v50[2].m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[21] = v41;
          ++v50[2].m_PendingGets.m_intrusiveTable.m_buckets;
        }
        v32 = dwOpenFlags;
        v24 = InterlockedDecrement;
      }
    }
    v32 += 4;
    dwOpenFlags = v32;
  }
  while ( v32 < 16 );
  DBCache::s_bCacheInitialized = v49;
  PortalThread::Resume((PortalThread *)&v50[1]);
  v43 = (char *)&dciInfo.path.m_charbuffer[-1].m_data[6];
  if ( !v24((volatile LONG *)&dciInfo.path.m_charbuffer[-1].m_data[8]) && v43 )
    (**(void (__thiscall ***)(char *, signed int))v43)(v43, 1);
  v44 = &dciInfo.file.m_charbuffer[-2].m_data[12];
  if ( !v24((volatile LONG *)&dciInfo.file.m_charbuffer[-1]) && v44 )
    (**(void (__thiscall ***)(char *, signed int))v44)(v44, 1);
  v45 = &find_data._key.m_charbuffer[-2].m_data[12];
  if ( !v24((volatile LONG *)&find_data._key.m_charbuffer[-1]) && v45 )
    (**(void (__thiscall ***)(char *, signed int))v45)(v45, 1);
  v46 = &find_data._key_path.m_charbuffer[-2].m_data[12];
  if ( !v24((volatile LONG *)&find_data._key_path.m_charbuffer[-1]) && v46 )
    (**(void (__thiscall ***)(char *, signed int))v46)(v46, 1);
  v47 = (char *)&find_data._path.m_charbuffer[-1].m_data[6];
  if ( !v24((volatile LONG *)&find_data._path.m_charbuffer[-1].m_data[8]) && v47 )
    (**(void (__thiscall ***)(char *, signed int))v47)(v47, 1);
  return v49;
}
// 7C5A20: using guessed type int (__thiscall *CThreadsafeDiskController::vftable)(void *, char);
// 836BA8: using guessed type bool DBCache::s_bCacheInitialized;

//----- (004FA250) --------------------------------------------------------  // acclient.c:293657
void __thiscall CLCache::LoadHighResDat(CLCache *this)
{
  CLCache *v1; // edi@1
  int v2; // eax@2
  int v3; // ecx@2
  int v4; // eax@3
  unsigned int v5; // ST10_4@3
  PStringBase<unsigned short> *v6; // eax@3
  char *v7; // esi@3
  int v8; // eax@5
  int v9; // edx@6
  int v10; // edx@7
  char *v11; // esi@9
  int v12; // eax@11
  int v13; // [sp-Ch] [bp-58h]@2
  int v14; // [sp-8h] [bp-54h]@2
  int v15; // [sp-4h] [bp-50h]@2
  PStringBase<char> data_filename; // [sp+Ch] [bp-40h]@2
  PStringBase<unsigned short> result; // [sp+10h] [bp-3Ch]@3
  int v18; // [sp+14h] [bp-38h]@7
  LookFile find_data; // [sp+18h] [bp-34h]@2
  DiskConInitInfo dciInfo; // [sp+24h] [bp-28h]@3

  v1 = this;
  if ( *((_DWORD *)this->m_DatFiles.m_data + 3) )
  {
    PStringBase<char>::PStringBase<char>(&data_filename, "client_highres.dat");
    find_data._path.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    find_data._key_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    find_data._key.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v2 = (int)v1->m_strDatFilePath.m_charbuffer;
    v15 = 0;
    v14 = v2;
    InterlockedIncrement((volatile LONG *)(v2 - 16));
    v13 = v3;
    PStringBase<char>::to_wpstring(&data_filename, (PStringBase<unsigned short> *)&v13, 0);
    if ( LookFile::LookForFile(&find_data, (PStringBase<unsigned short>)v13, (PStringBase<unsigned short>)v14, v15) )
    {
      v4 = 4 * (v1->m_fReadOnly != 0) + 2;
      v15 = v1->m_fEngineOnly;
      v14 = DBCache::s_GameDataPackVer;
      v13 = DBCache::s_EngDataPackVer;
      v5 = v4;
      v6 = LookFile::GetFoundPath(&find_data, &result);
      DiskConInitInfo::DiskConInitInfo(
        &dciInfo,
        &data_filename,
        v6,
        PORTAL_DATFILE,
        0x69466948u,
        v5,
        0,
        0,
        v13,
        v14,
        v15);
      v7 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v7 )
      {
        v8 = *(_DWORD *)v7;
        v15 = 1;
        (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
      }
      v9 = **((_DWORD **)v1->m_DatFiles.m_data + 3);
      v15 = (int)&dciInfo;
      if ( (unsigned __int8)(*(int (__stdcall **)(DiskConInitInfo *))(v9 + 4))(&dciInfo) )
      {
        result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)(*(int (**)(void))(**((_DWORD **)v1->m_DatFiles.m_data
                                                                                         + 3)
                                                                                      + 56))();
        v15 = (int)(v1->m_DatFiles.m_data + 3);
        v18 = v10;
        HashTable<unsigned __int64,DiskController *,0>::add(
          &v1->m_DatFileByIDTable,
          (const unsigned __int64 *)&result,
          (DiskController *const *)v15);
      }
      _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>(&dciInfo);
    }
    LookFile::~LookFile(&find_data);
    v11 = &data_filename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&data_filename.m_charbuffer[-1]) )
    {
      if ( v11 )
      {
        v12 = *(_DWORD *)v11;
        v15 = 1;
        (*(void (__thiscall **)(char *, signed int))v12)(v11, 1);
      }
    }
  }
}

//----- (004FA3E0) --------------------------------------------------------  // acclient.c:293754
void __thiscall CLCache::OnServerInterrogation(CLCache *this, DDD_InterrogationMessage *pEvent)
{
  DDD_InterrogationMessage *v2; // ebp@1
  CLCache *v3; // esi@1
  unsigned int v4; // edi@1
  InterfaceVtbl *v5; // edx@3
  PSRefBufferCharData<unsigned short> *v6; // ecx@3
  char v7; // bl@3
  unsigned int v8; // eax@4
  unsigned __int64 v9; // rax@6
  int v10; // eax@6
  int v11; // eax@13
  char *v12; // ebx@13
  int v13; // edx@13
  int v14; // eax@13
  void **v15; // esi@14
  int v16; // edi@14
  int v17; // eax@21
  char *v18; // ebx@21
  int v19; // edx@21
  int v20; // eax@21
  void **v21; // esi@22
  int v22; // edi@22
  PSRefBufferCharData<unsigned short> *v23; // ecx@27
  PSRefBufferCharData<unsigned short> *v24; // ecx@27
  PStringBase<unsigned short> v25; // [sp-10h] [bp-50h]@27
  PStringBase<unsigned short> v26; // [sp-Ch] [bp-4Ch]@27
  PStringBase<unsigned short> v27; // [sp-8h] [bp-48h]@27
  PlatformString::DisplayStringMode v28; // [sp-4h] [bp-44h]@27
  DDD_InterrogationResponseMessage response; // [sp+10h] [bp-30h]@4

  v2 = pEvent;
  v3 = this;
  v4 = 0;
  this->m_DDDState = 1;
  this->m_EarlySaves.m_num = 0;
  this->m_cbEarlySaves = 0;
  if ( v2->m_dwProductID & 4 )
    CLCache::LoadHighResDat(this);
  v5 = v3->vfptr;
  v3->m_ridDDDRegion = v2->m_dwServersRegion;
  v7 = ((int (__thiscall *)(CLCache *, unsigned int))v5[2].AddRef)(v3, v2->m_dwServersRegion);
  if ( v7 )
  {
    response.m_ItersWithKeys.vfptr = (CAllIterationListVtbl *)&CAllIterationList::vftable;
    response.m_ItersWithoutKeys.vfptr = (CAllIterationListVtbl *)&CAllIterationList::vftable;
    v8 = v3->m_DatFiles.m_num;
    response.m_et = 63462;
    response.vfptr = (FakeMessageDataVtbl *)&DDD_InterrogationResponseMessage::vftable;
    response.m_ItersWithKeys.m_Lists.m_data = 0;
    response.m_ItersWithKeys.m_Lists.m_sizeAndDeallocate = 0;
    response.m_ItersWithKeys.m_Lists.m_num = 0;
    response.m_ItersWithoutKeys.m_Lists.m_data = 0;
    response.m_ItersWithoutKeys.m_Lists.m_sizeAndDeallocate = 0;
    response.m_ItersWithoutKeys.m_Lists.m_num = 0;
    response.m_dwFlags = 0;
    if ( v8 )
    {
      do
      {
        if ( (unsigned __int8)((int (*)(void))v3->m_DatFiles.m_data[v4]->vfptr->IsInitialized)() )
        {
          LODWORD(v9) = ((int (*)(void))v3->m_DatFiles.m_data[v4]->vfptr->GetDatFileID)();
          v10 = CAllIterationList::AddIterationList(&response.m_ItersWithKeys, v9);
          if ( !(unsigned __int8)((int (__stdcall *)(int))v3->m_DatFiles.m_data[v4]->vfptr->LoadIterationList)(v10) )
            v7 = 0;
        }
        ++v4;
      }
      while ( v4 < v3->m_DatFiles.m_num );
    }
    response.m_ClientLanguage = DBCache::GetLocalLanguage();
    v3->m_eNameRuleLanguage = v2->m_NameRuleLanguage;
    if ( v7 )
      CLCache::AdoptAndDeliverMessage((TResult *)&pEvent, (FakeMessageData *)&response.vfptr);
    if ( (response.m_ItersWithoutKeys.m_Lists.m_sizeAndDeallocate & 0x80000000) == 0x80000000
      && response.m_ItersWithoutKeys.m_Lists.m_data )
    {
      v11 = *((_DWORD *)&response.m_ItersWithoutKeys.m_Lists.m_data[-1].List + 5);
      v12 = (char *)(&response.m_ItersWithoutKeys.m_Lists.m_data[-1].List + 1);
      v13 = 5 * v11;
      v14 = v11 - 1;
      if ( v14 >= 0 )
      {
        v15 = (void **)&response.m_ItersWithoutKeys.m_Lists.m_data[8 * v13 / 0x28u].List.m_Ints.m_data;
        v16 = v14 + 1;
        do
        {
          v15 -= 10;
          if ( (unsigned __int8)SmartArray<int,1>::ShouldDeallocate_((SmartArray<int,1> *)v15) )
            operator delete[](*v15);
          --v16;
        }
        while ( v16 );
      }
      operator delete[](v12);
    }
    if ( (response.m_ItersWithKeys.m_Lists.m_sizeAndDeallocate & 0x80000000) == 0x80000000
      && response.m_ItersWithKeys.m_Lists.m_data )
    {
      v17 = *((_DWORD *)&response.m_ItersWithKeys.m_Lists.m_data[-1].List + 5);
      v18 = (char *)(&response.m_ItersWithKeys.m_Lists.m_data[-1].List + 1);
      v19 = 5 * v17;
      v20 = v17 - 1;
      if ( v20 >= 0 )
      {
        v21 = (void **)&response.m_ItersWithKeys.m_Lists.m_data[8 * v19 / 0x28u].List.m_Ints.m_data;
        v22 = v20 + 1;
        do
        {
          v21 -= 10;
          if ( (unsigned __int8)SmartArray<int,1>::ShouldDeallocate_((SmartArray<int,1> *)v21) )
            operator delete[](*v21);
          --v22;
        }
        while ( v22 );
      }
      operator delete[](v18);
    }
  }
  else
  {
    v28 = 0;
    v27.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v27, &word_794320);
    v26.m_charbuffer = v23;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v26, &word_794320);
    v25.m_charbuffer = v24;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v25, &word_794320);
    PlatformString::DisplayString(0xC9u, v25, v26, v27, v28);
    Turbine::Debug::Abort();
  }
}
// 7C5AD0: using guessed type void (__thiscall *CAllIterationList::vftable)(CAllIterationList *this, struct Archive *);
// 7C5B48: using guessed type void (__thiscall *DDD_InterrogationResponseMessage::vftable)(DDD_InterrogationResponseMessage *this, struct Archive *);

//----- (004FA5F0) --------------------------------------------------------  // acclient.c:293891
void __thiscall HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::~HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>(HashTable<IDClass<_tagDataID,32,0>,unsigned long,0> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7C59FC: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable[2])(void *, char);
// 7C5B50: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable)(void *, char);

//----- (004FA630) --------------------------------------------------------  // acclient.c:293912
HashTable<unsigned __int64,DiskController *,0> *__thiscall HashTable<unsigned __int64,DiskController *,0>::vector_deleting_destructor(HashTable<unsigned __int64,DiskController *,0> *this, unsigned int a2)
{
  HashTable<unsigned __int64,DiskController *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned __int64,DiskController *,0>Vtbl *)HashTable<unsigned __int64,DiskController *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C59F8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable[3])(void *, char);
// 7C5B4C: using guessed type int (__thiscall *HashTable<unsigned __int64,DiskController *,0>::vftable[2])(void *, char);

//----- (004FA690) --------------------------------------------------------  // acclient.c:293938
HashTable<IDClass<_tagDataID,32,0>,unsigned long,0> *__thiscall HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vector_deleting_destructor(HashTable<IDClass<_tagDataID,32,0>,unsigned long,0> *this, unsigned int a2)
{
  HashTable<IDClass<_tagDataID,32,0>,unsigned long,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C59FC: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable[2])(void *, char);
// 7C5B50: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable)(void *, char);

//----- (004FA6F0) --------------------------------------------------------  // acclient.c:293964
char __thiscall CLCache::RemovePendingDownload(CLCache *this, QualifiedDataID *qdid)
{
  QualifiedDataID *v2; // ebp@1
  void *v3; // edi@1
  MissingIteration *v4; // esi@2
  unsigned int v5; // edx@2
  unsigned int v6; // eax@2
  int v7; // ecx@3
  unsigned int v8; // edx@8
  int v9; // edx@9
  QualifiedDataID *v10; // ecx@10
  unsigned int v11; // eax@10
  QualifiedDataID *v12; // ecx@10
  int v13; // edi@12
  int v14; // edx@12
  unsigned int v15; // esi@13
  unsigned int v16; // ebp@13
  unsigned int v17; // edx@13
  int v18; // eax@13
  int v19; // ecx@13
  int v20; // ebx@13
  int v21; // eax@13
  int v22; // edx@20
  char v23; // al@27
  FakeMessageData i_FMD; // [sp+10h] [bp-14h]@1
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+18h] [bp-Ch]@1

  v2 = qdid;
  v3 = this;
  i_FMD.vfptr = (FakeMessageDataVtbl *)this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    &this->m_PendingDownloads.m_intrusiveTable,
    &result,
    qdid);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->m_data;
    v5 = v4->IDsToDownload.m_num;
    v6 = 0;
    if ( v5 )
    {
      v7 = (int)&v4->IDsToDownload.m_data->ID;
      while ( *(_DWORD *)v7 != v2->ID.id )
      {
        ++v6;
        v7 += 8;
        if ( v6 >= v5 )
          goto LABEL_13;
      }
      if ( v6 != -1 )
      {
        v8 = v4->IDsToDownload.m_num;
        if ( v6 < v8 )
        {
          v9 = v8 - 1;
          v4->IDsToDownload.m_num = v9;
          if ( v6 != v9 )
          {
            v10 = v4->IDsToDownload.m_data;
            v10[v6].Type = v10[v9].Type;
            v10[v6].ID.id = v10[v9].ID.id;
            v11 = v4->IDsToDownload.m_num;
            v12 = v4->IDsToDownload.m_data;
            v12[v11].Type = (unsigned int)i_FMD.vfptr;
            v12[v11].ID.id = i_FMD.m_et;
          }
        }
        if ( !v4->IDsToDownload.m_num )
        {
          v13 = (*(int (__thiscall **)(int, QualifiedDataID *, _DWORD, _DWORD))(*((_DWORD *)v3 + 1) + 152))(
                  (char *)v3 + 4,
                  v2,
                  LODWORD(v4->idDatFile),
                  HIDWORD(v4->idDatFile));
          v14 = *(_DWORD *)(v13 + 1872);
          qdid = (QualifiedDataID *)v4->idIteration;
          (*(void (__thiscall **)(int))(v14 + 4))(v13 + 1872);
          CMostlyConsecutiveIntSet::Add((CMostlyConsecutiveIntSet *)(v13 + 1908), (int)qdid);
          CMostlyConsecutiveIntSet::Sort((CMostlyConsecutiveIntSet *)(v13 + 1908));
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v13 + 44))(v13, v13 + 1908);
          SharedCriticalSection::LeaveCriticalSection((SharedCriticalSection *)(v13 + 1872));
          v3 = i_FMD.vfptr;
        }
      }
    }
LABEL_13:
    v15 = v2->ID.id;
    v16 = v2->Type;
    v17 = (v15 + v16) % *((_DWORD *)v3 + 156);
    v18 = *((_DWORD *)v3 + 154);
    v19 = *(_DWORD *)(v18 + 4 * v17);
    v20 = v18 + 4 * v17;
    v21 = *(_DWORD *)(v18 + 4 * v17);
    if ( v21 )
    {
      while ( *(_DWORD *)v21 != v16 || *(_DWORD *)(v21 + 4) != v15 )
      {
        v21 = *(_DWORD *)(v21 + 8);
        if ( !v21 )
          goto LABEL_25;
      }
      if ( v21 )
      {
        if ( v19 == v21 )
          goto LABEL_31;
        do
        {
          v22 = v19;
          v19 = *(_DWORD *)(v19 + 8);
        }
        while ( v19 != v21 );
        if ( v22 )
          *(_DWORD *)(v22 + 8) = *(_DWORD *)(v19 + 8);
        else
LABEL_31:
          *(_DWORD *)v20 = *(_DWORD *)(v19 + 8);
        --*((_DWORD *)v3 + 157);
        operator delete((void *)v21);
      }
    }
LABEL_25:
    if ( !*((_DWORD *)v3 + 157) )
    {
      *((_DWORD *)v3 + 125) = 3;
      i_FMD.m_et = 63466;
      i_FMD.vfptr = (FakeMessageDataVtbl *)&DDD_EndDDDMessage::vftable;
      CLCache::AdoptAndDeliverMessage((TResult *)&qdid, &i_FMD);
    }
    v23 = 1;
  }
  else
  {
    v23 = 0;
  }
  return v23;
}
// 7C58C8: using guessed type void (__thiscall *DDD_EndDDDMessage::vftable)(FakeMessageData *this, struct Archive *);

//----- (004FA8B0) --------------------------------------------------------  // acclient.c:294103
void __thiscall CLCache::OnEndDDD(CLCache *this)
{
  CLCache *v1; // esi@1
  unsigned int CurRegion; // [sp+4h] [bp-10h]@3
  TResult result; // [sp+8h] [bp-Ch]@2
  FakeMessageData i_FMD; // [sp+Ch] [bp-8h]@2

  v1 = this;
  SmartArray<MissingIteration,1>::Reset(&this->m_MissingIters);
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_PendingDownloads.m_intrusiveTable);
  SmartArray<QualifiedDataID,1>::Reset(&v1->m_EarlySaves);
  if ( v1->m_DDDState == 1 )
  {
    v1->m_DDDState = 3;
    i_FMD.m_et = 63466;
    i_FMD.vfptr = (FakeMessageDataVtbl *)&DDD_EndDDDMessage::vftable;
    CLCache::AdoptAndDeliverMessage(&result, &i_FMD);
  }
  v1->m_DDDState = 4;
  CurRegion = 0;
  DBCache::GetCurrentRegion(&CurRegion);
  CLCache::NotifyDDDEvent(v1, DDD_PatchtimeEnd, CurRegion);
}
// 7C58C8: using guessed type void (__thiscall *DDD_EndDDDMessage::vftable)(FakeMessageData *this, struct Archive *);

//----- (004FA940) --------------------------------------------------------  // acclient.c:294129
void __thiscall CLCache::OnBeginDDDRequestFinished(CLCache *this, CLCache::CAsyncBeginDDDRequest *pReq)
{
  CLCache *v2; // ebp@1
  unsigned int v3; // eax@1
  int v4; // ebx@1
  unsigned int v5; // esi@3
  int v6; // eax@4
  int v7; // edx@4
  MissingIteration *v8; // ecx@4
  int v9; // eax@8
  int v10; // ecx@8
  DiskController *v11; // esi@9
  MissingIteration *v12; // eax@11
  int v13; // esi@11
  int v14; // edi@11
  void *v15; // eax@11
  int v16; // edx@12
  void *v17; // esi@12
  int v18; // ecx@14
  int v19; // edi@14
  unsigned int v20; // ebx@14
  unsigned int v21; // edx@14
  HashTableData<QualifiedDataID,MissingIteration *> **v22; // eax@14
  HashTableData<QualifiedDataID,MissingIteration *> *v23; // edx@14
  int v24; // edi@20
  int v25; // ebx@21
  signed int v26; // edi@21
  int v27; // ebp@22
  unsigned int *v28; // eax@29
  unsigned int v29; // eax@32
  bool v30; // cf@37
  unsigned int v31; // esi@40
  int v32; // [sp+Ch] [bp-24h]@2
  void *v33; // [sp+10h] [bp-20h]@12
  unsigned int idxID; // [sp+14h] [bp-1Ch]@10
  int NewInt; // [sp+18h] [bp-18h]@9
  unsigned int idxIter; // [sp+1Ch] [bp-14h]@1
  unsigned int *__first; // [sp+20h] [bp-10h]@21
  unsigned int __y; // [sp+24h] [bp-Ch]@14
  int v39; // [sp+28h] [bp-8h]@39
  TResult result; // [sp+2Ch] [bp-4h]@1

  v2 = this;
  v3 = this->m_MissingIters.m_num;
  v4 = 0;
  result.m_val = (unsigned int)this;
  idxIter = 0;
  if ( v3 )
  {
    v32 = 0;
    do
    {
      v5 = 0;
      if ( !v2->m_DatFiles.m_num )
        goto LABEL_44;
      do
      {
        v6 = ((int (*)(void))v2->m_DatFiles.m_data[v5]->vfptr->GetDatFileID)();
        v8 = v2->m_MissingIters.m_data;
        if ( *(_DWORD *)((char *)&v8->idDatFile + v4) == v6 && *(_DWORD *)((char *)&v8->idDatFile + v4 + 4) == v7 )
          break;
        ++v5;
      }
      while ( v5 < v2->m_DatFiles.m_num );
      if ( v5 < 4 )
      {
LABEL_44:
        v9 = (int)((char *)v2->m_MissingIters.m_data + v4);
        v10 = *(_DWORD *)(v9 + 28);
        if ( v10 )
        {
          idxID = 0;
          if ( v10 )
          {
            do
            {
              v12 = v2->m_MissingIters.m_data;
              v13 = (int)((char *)v12 + v4);
              v14 = (int)&(*(QualifiedDataID **)((char *)&v12->IDsToDownload.m_data + v4))[idxID];
              v15 = operator new(0x10u);
              if ( v15 )
              {
                *(_DWORD *)v15 = *(_DWORD *)v14;
                v16 = *(_DWORD *)(v14 + 4);
                *((_DWORD *)v15 + 3) = v13;
                v17 = v15;
                *((_DWORD *)v15 + 1) = v16;
                *((_DWORD *)v15 + 2) = 0;
                v33 = v15;
              }
              else
              {
                v33 = 0;
                v17 = 0;
              }
              v18 = *((_DWORD *)v17 + 1);
              v19 = *(_DWORD *)v17;
              v20 = v2->m_PendingDownloads.m_intrusiveTable.m_numBuckets;
              v21 = (*(_DWORD *)v17 + v18) % v20;
              v22 = v2->m_PendingDownloads.m_intrusiveTable.m_buckets;
              __y = v2->m_PendingDownloads.m_intrusiveTable.m_numBuckets;
              v23 = v22[v21];
              if ( !v23 )
                goto LABEL_20;
              while ( v23->m_hashKey.Type != v19 || v23->m_hashKey.ID.id != v18 )
              {
                v23 = v23->m_hashNext;
                if ( !v23 )
                  goto LABEL_20;
              }
              if ( v23 )
              {
                operator delete(v17);
                v4 = v32;
              }
              else
              {
LABEL_20:
                v24 = (int)&v2->m_PendingDownloads.m_intrusiveTable;
                if ( (signed int)(2 * v20) < (signed int)(v2->m_PendingDownloads.m_intrusiveTable.m_numElements + 1) )
                {
                  v25 = (int)g_bucketSizesBegin;
                  NewInt = (int)g_bucketSizesEnd;
                  __first = g_bucketSizesBegin;
                  v26 = _STL::distance((const unsigned int *const *)&__first, (const unsigned int *const *)&NewInt);
                  if ( v26 > 0 )
                  {
                    do
                    {
                      NewInt = v25;
                      _STL::advance((const unsigned int **)&NewInt, v26 >> 1);
                      v27 = NewInt;
                      if ( (unsigned __int8)_STL::__less_2<unsigned long,unsigned long>::operator()(
                                              (const unsigned int *)NewInt,
                                              __y) )
                      {
                        v25 = v27 + 4;
                        v26 += -1 - (v26 >> 1);
                      }
                      else
                      {
                        v26 >>= 1;
                      }
                    }
                    while ( v26 > 0 );
                    v2 = (CLCache *)result.m_val;
                    v17 = v33;
                  }
                  if ( (unsigned int *)v25 == g_bucketSizesEnd )
                    v25 -= 4;
                  v28 = (unsigned int *)v25;
                  if ( (unsigned int *)v25 != g_bucketSizesEnd )
                    v28 = (unsigned int *)(v25 + 4);
                  v24 = (int)&v2->m_PendingDownloads.m_intrusiveTable;
                  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::resize_internal(
                    &v2->m_PendingDownloads.m_intrusiveTable,
                    *v28);
                }
                v4 = v32;
                v29 = *(_DWORD *)(v24 + 96)
                    + 4 * ((unsigned int)(*((_DWORD *)v17 + 1) + *(_DWORD *)v17) % *(_DWORD *)(v24 + 104));
                *((_DWORD *)v17 + 2) = *(_DWORD *)v29;
                *(_DWORD *)v29 = v17;
                if ( v29 < *(_DWORD *)(v24 + 100) )
                  *(_DWORD *)(v24 + 100) = v29;
                ++*(_DWORD *)(v24 + 108);
              }
              ++idxID;
            }
            while ( idxID < *(unsigned int *)((char *)&v2->m_MissingIters.m_data->IDsToDownload.m_num + v4) );
          }
        }
        else
        {
          v11 = v2->m_DatFiles.m_data[v5];
          NewInt = *(_DWORD *)(v9 + 16);
          (*(void (__thiscall **)(int))&v11[1].vfptr->gap4[0])(&v11[1]);
          CMostlyConsecutiveIntSet::Add((CMostlyConsecutiveIntSet *)&v11[1].did_tree_m.mem_root_node_m.ahead_pm, NewInt);
          CMostlyConsecutiveIntSet::Sort((CMostlyConsecutiveIntSet *)&v11[1].did_tree_m.mem_root_node_m.ahead_pm);
          v11->vfptr->SaveIterationList(
            (DiskConBase *)v11,
            (CMostlyConsecutiveIntSet *)&v11[1].did_tree_m.mem_root_node_m.ahead_pm);
          SharedCriticalSection::LeaveCriticalSection((SharedCriticalSection *)&v11[1]);
        }
      }
      v4 += 48;
      v30 = idxIter++ + 1 < v2->m_MissingIters.m_num;
      v32 = v4;
    }
    while ( v30 );
  }
  if ( v2->m_PendingDownloads.m_intrusiveTable.m_numElements )
  {
    v31 = 0;
    if ( v2->m_EarlySaves.m_num )
    {
      do
        CLCache::RemovePendingDownload(v2, &v2->m_EarlySaves.m_data[v31++]);
      while ( v31 < v2->m_EarlySaves.m_num );
    }
  }
  else
  {
    v2->m_DDDState = 3;
    v39 = 63466;
    __y = (unsigned int)&DDD_EndDDDMessage::vftable;
    CLCache::AdoptAndDeliverMessage(&result, (FakeMessageData *)&__y);
  }
}
// 7C58C8: using guessed type void (__thiscall *DDD_EndDDDMessage::vftable)(FakeMessageData *this, struct Archive *);

//----- (004FAC40) --------------------------------------------------------  // acclient.c:294341
EnumIDMap *DualEnumIDMap::Allocate()
{
  EnumIDMap *v1; // eax@1
  EnumIDMap *v2; // esi@1
  EnumIDMap *result; // eax@2

  v1 = (EnumIDMap *)operator new(0x278u);
  v2 = v1;
  if ( v1 )
  {
    EnumIDMap::EnumIDMap(v1);
    v2->vfptr = (InterfaceVtbl *)&DualEnumIDMap::vftable;
    v2[1].vfptr = (InterfaceVtbl *)&HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable;
    IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>(
      (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0> *)&v2[1].m_dataCategory,
      0x17u);
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7C5B50: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable)(void *, char);
// 7C5B68: using guessed type __int32 (__stdcall *DualEnumIDMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004FAC80) --------------------------------------------------------  // acclient.c:294369
EnumIDMap *__thiscall DualEnumIDMap::scalar_deleting_destructor(DualEnumIDMap *this, unsigned int a2)
{
  EnumIDMap *v2; // esi@1

  v2 = (EnumIDMap *)this;
  HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::~HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>(&this->m_IDToEnum);
  EnumIDMap::~EnumIDMap(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004FACB0) --------------------------------------------------------  // acclient.c:294382
void CLCache::Init_Internal()
{
  CLOCache *v1; // eax@1
  int v2; // eax@2
  int v3; // esi@2
  void *v4; // eax@4
  void *v5; // esi@5
  CLOCache *v6; // eax@10
  int v7; // eax@11
  int v8; // esi@11
  void *v9; // eax@13
  void *v10; // esi@14
  CLOCache *v11; // eax@19
  int v12; // eax@20
  int v13; // esi@20
  void *v14; // eax@22
  void *v15; // esi@23
  CLOCache *v16; // eax@28
  int v17; // eax@29
  int v18; // esi@29
  void *v19; // eax@31
  void *v20; // esi@32
  CLOCache *v21; // eax@37
  int v22; // eax@38
  int v23; // esi@38
  void *v24; // eax@40
  void *v25; // esi@41
  CLOCache *v26; // eax@46
  int v27; // eax@47
  int v28; // esi@47
  void *v29; // eax@49
  void *v30; // esi@50
  CLOCache *v31; // eax@55
  int v32; // eax@56
  int v33; // esi@56
  void *v34; // eax@58
  void *v35; // esi@59
  CLOCache *v36; // eax@64
  int v37; // eax@65
  int v38; // esi@65
  void *v39; // eax@67
  void *v40; // esi@68
  CLOCache *v41; // eax@73
  int v42; // eax@74
  int v43; // esi@74
  void *v44; // eax@76
  void *v45; // esi@77
  CLOCache *v46; // eax@82
  int v47; // eax@83
  int v48; // esi@83
  void *v49; // eax@85
  void *v50; // esi@86
  CLOCache *v51; // eax@91
  int v52; // eax@92
  int v53; // esi@92
  void *v54; // eax@94
  void *v55; // esi@95
  CLOCache *v56; // eax@100
  int v57; // eax@101
  int v58; // esi@101
  void *v59; // eax@103
  void *v60; // esi@104
  CLOCache *v61; // eax@109
  int v62; // eax@110
  int v63; // esi@110
  void *v64; // eax@112
  void *v65; // esi@113
  CLOCache *v66; // eax@118
  int v67; // eax@119
  int v68; // esi@119
  void *v69; // eax@121
  void *v70; // esi@122
  CLOCache *v71; // eax@127
  int v72; // eax@128
  int v73; // esi@128
  void *v74; // eax@130
  void *v75; // esi@131
  CLOCache *v76; // eax@136
  int v77; // eax@137
  int v78; // esi@137
  void *v79; // eax@139
  void *v80; // esi@140
  CLOCache *v81; // eax@145
  int v82; // eax@146
  int v83; // esi@146
  void *v84; // eax@148
  void *v85; // esi@149
  CLOCache *v86; // eax@154
  int v87; // eax@155
  int v88; // esi@155
  void *v89; // eax@157
  void *v90; // esi@158
  CLOCache *v91; // eax@163
  int v92; // eax@164
  int v93; // esi@164
  void *v94; // eax@166
  void *v95; // esi@167
  CLOCache *v96; // eax@172
  int v97; // eax@173
  int v98; // esi@173
  void *v99; // eax@175
  void *v100; // esi@176
  CLOCache *v101; // eax@181
  int v102; // eax@182
  int v103; // esi@182
  void *v104; // eax@184
  void *v105; // esi@185
  CLOCache *v106; // eax@190
  int v107; // eax@191
  int v108; // esi@191
  void *v109; // eax@193
  void *v110; // esi@194
  CLOCache *v111; // eax@199
  int v112; // eax@200
  int v113; // esi@200
  void *v114; // eax@202
  void *v115; // esi@203
  CLOCache *v116; // eax@208
  int v117; // eax@209
  int v118; // esi@209
  void *v119; // eax@211
  void *v120; // esi@212
  CLOCache *v121; // eax@217
  int v122; // eax@218
  int v123; // esi@218
  void *v124; // eax@220
  void *v125; // esi@221
  CLOCache *v126; // eax@226
  int v127; // eax@227
  int v128; // esi@227
  void *v129; // eax@229
  void *v130; // esi@230
  CLOCache *v131; // eax@235
  int v132; // eax@236
  int v133; // esi@236
  void *v134; // eax@238
  void *v135; // esi@239
  CLOCache *v136; // eax@244
  int v137; // eax@245
  int v138; // esi@245
  void *v139; // eax@247
  void *v140; // esi@248
  CLOCache *v141; // eax@253
  int v142; // eax@254
  int v143; // esi@254
  void *v144; // eax@256
  void *v145; // esi@257
  CLOCache *v146; // eax@262
  int v147; // eax@263
  int v148; // esi@263
  void *v149; // eax@265
  void *v150; // esi@266
  CLOCache *v151; // eax@271
  int v152; // eax@272
  int v153; // esi@272
  void *v154; // eax@274
  void *v155; // esi@275
  CLOCache *v156; // eax@280
  int v157; // eax@281
  int v158; // esi@281
  void *v159; // eax@283
  void *v160; // esi@284
  CLOCache *v161; // eax@289
  int v162; // eax@290
  int v163; // esi@290
  void *v164; // eax@292
  void *v165; // esi@293
  CLOCache *v166; // eax@298
  int v167; // eax@299
  int v168; // esi@299
  void *v169; // eax@301
  void *v170; // esi@302
  CLOCache *v171; // eax@307
  int v172; // eax@308
  int v173; // esi@308
  void *v174; // eax@310
  void *v175; // esi@311
  CLOCache *v176; // eax@316
  int v177; // eax@317
  int v178; // esi@317
  void *v179; // eax@319
  void *v180; // esi@320
  CLOCache *v181; // eax@325
  int v182; // eax@326
  int v183; // esi@326
  void *v184; // eax@328
  void *v185; // esi@329
  CLOCache *v186; // eax@334
  int v187; // eax@335
  int v188; // esi@335
  void *v189; // eax@337
  void *v190; // esi@338
  CLOCache *v191; // eax@343
  int v192; // eax@344
  int v193; // esi@344
  void *v194; // eax@346
  void *v195; // esi@347
  CLOCache *v196; // eax@352
  int v197; // eax@353
  int v198; // esi@353
  void *v199; // eax@355
  void *v200; // esi@356
  CLOCache *v201; // eax@361
  int v202; // eax@362
  int v203; // esi@362
  void *v204; // eax@364
  void *v205; // esi@365
  CLOCache *v206; // eax@370
  int v207; // eax@371
  int v208; // esi@371
  void *v209; // eax@373
  void *v210; // esi@374
  CLOCache *v211; // eax@379
  int v212; // eax@380
  int v213; // esi@380
  void *v214; // eax@382
  void *v215; // esi@383
  CLOCache *v216; // eax@388
  int v217; // eax@389
  int v218; // esi@389
  void *v219; // eax@391
  void *v220; // esi@392
  CLOCache *v221; // eax@397
  int v222; // eax@398
  int v223; // esi@398
  void *v224; // eax@400
  void *v225; // esi@401
  CLOCache *v226; // eax@406
  int v227; // eax@407
  int v228; // esi@407
  void *v229; // eax@409
  void *v230; // esi@410

  v1 = (CLOCache *)operator new(0x114u);
  if ( v1 )
  {
    CLOCache::CLOCache(v1, (DBObj *(__cdecl *)())CLandBlock::Allocator, 1u);
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *((_DWORD *)v4 + 2) = v3;
    *(_DWORD *)v4 = 1;
    *((_DWORD *)v4 + 1) = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5)
    && v5 )
    operator delete(v5);
  v6 = (CLOCache *)operator new(0x114u);
  if ( v6 )
  {
    CLOCache::CLOCache(v6, (DBObj *(__cdecl *)())CLandBlockInfo::Allocator, 2u);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = operator new(0xCu);
  if ( v9 )
  {
    *((_DWORD *)v9 + 2) = v8;
    *(_DWORD *)v9 = 2;
    *((_DWORD *)v9 + 1) = 0;
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v10)
    && v10 )
    operator delete(v10);
  v11 = (CLOCache *)operator new(0x114u);
  if ( v11 )
  {
    CLOCache::CLOCache(v11, (DBObj *(__cdecl *)())CEnvCell::Allocator, 3u);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = operator new(0xCu);
  if ( v14 )
  {
    *((_DWORD *)v14 + 2) = v13;
    *(_DWORD *)v14 = 3;
    *((_DWORD *)v14 + 1) = 0;
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v15)
    && v15 )
    operator delete(v15);
  v16 = (CLOCache *)operator new(0x114u);
  if ( v16 )
  {
    CLOCache::CLOCache(v16, (DBObj *(__cdecl *)())CGfxObj::Allocator, 6u);
    v18 = v17;
  }
  else
  {
    v18 = 0;
  }
  v19 = operator new(0xCu);
  if ( v19 )
  {
    *((_DWORD *)v19 + 2) = v18;
    *(_DWORD *)v19 = 6;
    *((_DWORD *)v19 + 1) = 0;
    v20 = v19;
  }
  else
  {
    v20 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v20)
    && v20 )
    operator delete(v20);
  v21 = (CLOCache *)operator new(0x114u);
  if ( v21 )
  {
    CLOCache::CLOCache(v21, (DBObj *(__cdecl *)())CSetup::Allocator, 7u);
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  v24 = operator new(0xCu);
  if ( v24 )
  {
    *((_DWORD *)v24 + 2) = v23;
    *(_DWORD *)v24 = 7;
    *((_DWORD *)v24 + 1) = 0;
    v25 = v24;
  }
  else
  {
    v25 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v25)
    && v25 )
    operator delete(v25);
  v26 = (CLOCache *)operator new(0x114u);
  if ( v26 )
  {
    CLOCache::CLOCache(v26, (DBObj *(__cdecl *)())CAnimation::Allocator, 8u);
    v28 = v27;
  }
  else
  {
    v28 = 0;
  }
  v29 = operator new(0xCu);
  if ( v29 )
  {
    *((_DWORD *)v29 + 2) = v28;
    *(_DWORD *)v29 = 8;
    *((_DWORD *)v29 + 1) = 0;
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v30)
    && v30 )
    operator delete(v30);
  v31 = (CLOCache *)operator new(0x114u);
  if ( v31 )
  {
    CLOCache::CLOCache(v31, (DBObj *(__cdecl *)())Palette::Allocator, 0xAu);
    v33 = v32;
  }
  else
  {
    v33 = 0;
  }
  v34 = operator new(0xCu);
  if ( v34 )
  {
    *((_DWORD *)v34 + 2) = v33;
    *(_DWORD *)v34 = 10;
    *((_DWORD *)v34 + 1) = 0;
    v35 = v34;
  }
  else
  {
    v35 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v35)
    && v35 )
    operator delete(v35);
  v36 = (CLOCache *)operator new(0x114u);
  if ( v36 )
  {
    CLOCache::CLOCache(v36, (DBObj *(__cdecl *)())ImgTex::Allocator, 0xBu);
    v38 = v37;
  }
  else
  {
    v38 = 0;
  }
  v39 = operator new(0xCu);
  if ( v39 )
  {
    *((_DWORD *)v39 + 2) = v38;
    *(_DWORD *)v39 = 11;
    *((_DWORD *)v39 + 1) = 0;
    v40 = v39;
  }
  else
  {
    v40 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v40)
    && v40 )
    operator delete(v40);
  v41 = (CLOCache *)operator new(0x114u);
  if ( v41 )
  {
    CLOCache::CLOCache(v41, (DBObj *(__cdecl *)())RenderSurface::Allocator, 0xCu);
    v43 = v42;
  }
  else
  {
    v43 = 0;
  }
  v44 = operator new(0xCu);
  if ( v44 )
  {
    *((_DWORD *)v44 + 2) = v43;
    *(_DWORD *)v44 = 12;
    *((_DWORD *)v44 + 1) = 0;
    v45 = v44;
  }
  else
  {
    v45 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v45)
    && v45 )
    operator delete(v45);
  v46 = (CLOCache *)operator new(0x114u);
  if ( v46 )
  {
    CLOCache::CLOCache(v46, (DBObj *(__cdecl *)())CSurface::Allocator, 0xDu);
    v48 = v47;
  }
  else
  {
    v48 = 0;
  }
  v49 = operator new(0xCu);
  if ( v49 )
  {
    *((_DWORD *)v49 + 2) = v48;
    *(_DWORD *)v49 = 13;
    *((_DWORD *)v49 + 1) = 0;
    v50 = v49;
  }
  else
  {
    v50 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v50)
    && v50 )
    operator delete(v50);
  v51 = (CLOCache *)operator new(0x114u);
  if ( v51 )
  {
    CLOCache::CLOCache(v51, (DBObj *(__cdecl *)())CMotionTable::Allocator, 0xEu);
    v53 = v52;
  }
  else
  {
    v53 = 0;
  }
  v54 = operator new(0xCu);
  if ( v54 )
  {
    *((_DWORD *)v54 + 2) = v53;
    *(_DWORD *)v54 = 14;
    *((_DWORD *)v54 + 1) = 0;
    v55 = v54;
  }
  else
  {
    v55 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v55)
    && v55 )
    operator delete(v55);
  v56 = (CLOCache *)operator new(0x114u);
  if ( v56 )
  {
    CLOCache::CLOCache(v56, (DBObj *(__cdecl *)())DBWave::Allocator, 0xFu);
    v58 = v57;
  }
  else
  {
    v58 = 0;
  }
  v59 = operator new(0xCu);
  if ( v59 )
  {
    *((_DWORD *)v59 + 2) = v58;
    *(_DWORD *)v59 = 15;
    *((_DWORD *)v59 + 1) = 0;
    v60 = v59;
  }
  else
  {
    v60 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v60)
    && v60 )
    operator delete(v60);
  v61 = (CLOCache *)operator new(0x114u);
  if ( v61 )
  {
    CLOCache::CLOCache(v61, (DBObj *(__cdecl *)())CEnvironment::Allocator, 0x10u);
    v63 = v62;
  }
  else
  {
    v63 = 0;
  }
  v64 = operator new(0xCu);
  if ( v64 )
  {
    *((_DWORD *)v64 + 2) = v63;
    *(_DWORD *)v64 = 16;
    *((_DWORD *)v64 + 1) = 0;
    v65 = v64;
  }
  else
  {
    v65 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v65)
    && v65 )
    operator delete(v65);
  v66 = (CLOCache *)operator new(0x114u);
  if ( v66 )
  {
    CLOCache::CLOCache(v66, (DBObj *(__cdecl *)())ChatPoseTable::Allocator, 0x11u);
    v68 = v67;
  }
  else
  {
    v68 = 0;
  }
  v69 = operator new(0xCu);
  if ( v69 )
  {
    *((_DWORD *)v69 + 2) = v68;
    *(_DWORD *)v69 = 17;
    *((_DWORD *)v69 + 1) = 0;
    v70 = v69;
  }
  else
  {
    v70 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v70)
    && v70 )
    operator delete(v70);
  v71 = (CLOCache *)operator new(0x114u);
  if ( v71 )
  {
    CLOCache::CLOCache(v71, (DBObj *(__cdecl *)())cWObjHierRootNode::Allocator, 0x12u);
    v73 = v72;
  }
  else
  {
    v73 = 0;
  }
  v74 = operator new(0xCu);
  if ( v74 )
  {
    *((_DWORD *)v74 + 2) = v73;
    *(_DWORD *)v74 = 18;
    *((_DWORD *)v74 + 1) = 0;
    v75 = v74;
  }
  else
  {
    v75 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v75)
    && v75 )
    operator delete(v75);
  v76 = (CLOCache *)operator new(0x114u);
  if ( v76 )
  {
    CLOCache::CLOCache(v76, (DBObj *(__cdecl *)())BadData::Allocator, 0x13u);
    v78 = v77;
  }
  else
  {
    v78 = 0;
  }
  v79 = operator new(0xCu);
  if ( v79 )
  {
    *((_DWORD *)v79 + 2) = v78;
    *(_DWORD *)v79 = 19;
    *((_DWORD *)v79 + 1) = 0;
    v80 = v79;
  }
  else
  {
    v80 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v80)
    && v80 )
    operator delete(v80);
  v81 = (CLOCache *)operator new(0x114u);
  if ( v81 )
  {
    CLOCache::CLOCache(v81, (DBObj *(__cdecl *)())TabooTable::Allocator, 0x14u);
    v83 = v82;
  }
  else
  {
    v83 = 0;
  }
  v84 = operator new(0xCu);
  if ( v84 )
  {
    *((_DWORD *)v84 + 2) = v83;
    *(_DWORD *)v84 = 20;
    *((_DWORD *)v84 + 1) = 0;
    v85 = v84;
  }
  else
  {
    v85 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v85)
    && v85 )
    operator delete(v85);
  v86 = (CLOCache *)operator new(0x114u);
  if ( v86 )
  {
    CLOCache::CLOCache(v86, DBFile2IDTable::Allocate, 0x15u);
    v88 = v87;
  }
  else
  {
    v88 = 0;
  }
  v89 = operator new(0xCu);
  if ( v89 )
  {
    *((_DWORD *)v89 + 2) = v88;
    *(_DWORD *)v89 = 21;
    *((_DWORD *)v89 + 1) = 0;
    v90 = v89;
  }
  else
  {
    v90 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v90)
    && v90 )
    operator delete(v90);
  v91 = (CLOCache *)operator new(0x114u);
  if ( v91 )
  {
    CLOCache::CLOCache(v91, (DBObj *(__cdecl *)())NameFilterTable::Allocator, 0x16u);
    v93 = v92;
  }
  else
  {
    v93 = 0;
  }
  v94 = operator new(0xCu);
  if ( v94 )
  {
    *((_DWORD *)v94 + 2) = v93;
    *(_DWORD *)v94 = 22;
    *((_DWORD *)v94 + 1) = 0;
    v95 = v94;
  }
  else
  {
    v95 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v95)
    && v95 )
    operator delete(v95);
  v96 = (CLOCache *)operator new(0x114u);
  if ( v96 )
  {
    CLOCache::CLOCache(v96, (DBObj *(__cdecl *)())PalSet::Allocator, 0x18u);
    v98 = v97;
  }
  else
  {
    v98 = 0;
  }
  v99 = operator new(0xCu);
  if ( v99 )
  {
    *((_DWORD *)v99 + 2) = v98;
    *(_DWORD *)v99 = 24;
    *((_DWORD *)v99 + 1) = 0;
    v100 = v99;
  }
  else
  {
    v100 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v100)
    && v100 )
    operator delete(v100);
  v101 = (CLOCache *)operator new(0x114u);
  if ( v101 )
  {
    CLOCache::CLOCache(v101, (DBObj *(__cdecl *)())ClothingTable::Allocator, 0x19u);
    v103 = v102;
  }
  else
  {
    v103 = 0;
  }
  v104 = operator new(0xCu);
  if ( v104 )
  {
    *((_DWORD *)v104 + 2) = v103;
    *(_DWORD *)v104 = 25;
    *((_DWORD *)v104 + 1) = 0;
    v105 = v104;
  }
  else
  {
    v105 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v105)
    && v105 )
    operator delete(v105);
  v106 = (CLOCache *)operator new(0x114u);
  if ( v106 )
  {
    CLOCache::CLOCache(v106, (DBObj *(__cdecl *)())GfxObjDegradeInfo::Allocator, 0x1Au);
    v108 = v107;
  }
  else
  {
    v108 = 0;
  }
  v109 = operator new(0xCu);
  if ( v109 )
  {
    *((_DWORD *)v109 + 2) = v108;
    *(_DWORD *)v109 = 26;
    *((_DWORD *)v109 + 1) = 0;
    v110 = v109;
  }
  else
  {
    v110 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v110)
    && v110 )
    operator delete(v110);
  v111 = (CLOCache *)operator new(0x114u);
  if ( v111 )
  {
    CLOCache::CLOCache(v111, (DBObj *(__cdecl *)())Scene::Allocator, 0x1Bu);
    v113 = v112;
  }
  else
  {
    v113 = 0;
  }
  v114 = operator new(0xCu);
  if ( v114 )
  {
    *((_DWORD *)v114 + 2) = v113;
    *(_DWORD *)v114 = 27;
    *((_DWORD *)v114 + 1) = 0;
    v115 = v114;
  }
  else
  {
    v115 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v115)
    && v115 )
    operator delete(v115);
  v116 = (CLOCache *)operator new(0x114u);
  if ( v116 )
  {
    CLOCache::CLOCache(v116, (DBObj *(__cdecl *)())CRegionDesc::Allocator, 0x1Cu);
    v118 = v117;
  }
  else
  {
    v118 = 0;
  }
  v119 = operator new(0xCu);
  if ( v119 )
  {
    *((_DWORD *)v119 + 2) = v118;
    *(_DWORD *)v119 = 28;
    *((_DWORD *)v119 + 1) = 0;
    v120 = v119;
  }
  else
  {
    v120 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v120)
    && v120 )
    operator delete(v120);
  v121 = (CLOCache *)operator new(0x114u);
  if ( v121 )
  {
    CLOCache::CLOCache(v121, (DBObj *(__cdecl *)())CMasterInputMap::Allocator, 0x1Du);
    v123 = v122;
  }
  else
  {
    v123 = 0;
  }
  v124 = operator new(0xCu);
  if ( v124 )
  {
    *((_DWORD *)v124 + 2) = v123;
    *(_DWORD *)v124 = 29;
    *((_DWORD *)v124 + 1) = 0;
    v125 = v124;
  }
  else
  {
    v125 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v125)
    && v125 )
    operator delete(v125);
  v126 = (CLOCache *)operator new(0x114u);
  if ( v126 )
  {
    CLOCache::CLOCache(v126, (DBObj *(__cdecl *)())RenderTexture::Allocate, 0x1Eu);
    v128 = v127;
  }
  else
  {
    v128 = 0;
  }
  v129 = operator new(0xCu);
  if ( v129 )
  {
    *((_DWORD *)v129 + 2) = v128;
    *(_DWORD *)v129 = 30;
    *((_DWORD *)v129 + 1) = 0;
    v130 = v129;
  }
  else
  {
    v130 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v130)
    && v130 )
    operator delete(v130);
  v131 = (CLOCache *)operator new(0x114u);
  if ( v131 )
  {
    CLOCache::CLOCache(v131, (DBObj *(__cdecl *)())RenderMaterial::Allocator, 0x1Fu);
    v133 = v132;
  }
  else
  {
    v133 = 0;
  }
  v134 = operator new(0xCu);
  if ( v134 )
  {
    *((_DWORD *)v134 + 2) = v133;
    *(_DWORD *)v134 = 31;
    *((_DWORD *)v134 + 1) = 0;
    v135 = v134;
  }
  else
  {
    v135 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v135)
    && v135 )
    operator delete(v135);
  v136 = (CLOCache *)operator new(0x114u);
  if ( v136 )
  {
    CLOCache::CLOCache(v136, MaterialModifier::Allocator, 0x20u);
    v138 = v137;
  }
  else
  {
    v138 = 0;
  }
  v139 = operator new(0xCu);
  if ( v139 )
  {
    *((_DWORD *)v139 + 2) = v138;
    *(_DWORD *)v139 = 32;
    *((_DWORD *)v139 + 1) = 0;
    v140 = v139;
  }
  else
  {
    v140 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v140)
    && v140 )
    operator delete(v140);
  v141 = (CLOCache *)operator new(0x114u);
  if ( v141 )
  {
    CLOCache::CLOCache(v141, (DBObj *(__cdecl *)())MaterialInstance::Allocator, 0x21u);
    v143 = v142;
  }
  else
  {
    v143 = 0;
  }
  v144 = operator new(0xCu);
  if ( v144 )
  {
    *((_DWORD *)v144 + 2) = v143;
    *(_DWORD *)v144 = 33;
    *((_DWORD *)v144 + 1) = 0;
    v145 = v144;
  }
  else
  {
    v145 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v145)
    && v145 )
    operator delete(v145);
  v146 = (CLOCache *)operator new(0x114u);
  if ( v146 )
  {
    CLOCache::CLOCache(v146, (DBObj *(__cdecl *)())RenderMesh::Allocator, 0x43u);
    v148 = v147;
  }
  else
  {
    v148 = 0;
  }
  v149 = operator new(0xCu);
  if ( v149 )
  {
    *((_DWORD *)v149 + 2) = v148;
    *(_DWORD *)v149 = 67;
    *((_DWORD *)v149 + 1) = 0;
    v150 = v149;
  }
  else
  {
    v150 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v150)
    && v150 )
    operator delete(v150);
  v151 = (CLOCache *)operator new(0x114u);
  if ( v151 )
  {
    CLOCache::CLOCache(v151, (DBObj *(__cdecl *)())CSoundTable::Allocator, 0x22u);
    v153 = v152;
  }
  else
  {
    v153 = 0;
  }
  v154 = operator new(0xCu);
  if ( v154 )
  {
    *((_DWORD *)v154 + 2) = v153;
    *(_DWORD *)v154 = 34;
    *((_DWORD *)v154 + 1) = 0;
    v155 = v154;
  }
  else
  {
    v155 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v155)
    && v155 )
    operator delete(v155);
  v156 = (CLOCache *)operator new(0x114u);
  if ( v156 )
  {
    CLOCache::CLOCache(v156, (DBObj *(__cdecl *)())LayoutDesc::Allocator, 0x23u);
    v158 = v157;
  }
  else
  {
    v158 = 0;
  }
  v159 = operator new(0xCu);
  if ( v159 )
  {
    *((_DWORD *)v159 + 2) = v158;
    *(_DWORD *)v159 = 35;
    *((_DWORD *)v159 + 1) = 0;
    v160 = v159;
  }
  else
  {
    v160 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v160)
    && v160 )
    operator delete(v160);
  v161 = (CLOCache *)operator new(0x114u);
  if ( v161 )
  {
    CLOCache::CLOCache(v161, (DBObj *(__cdecl *)())EnumMapper::Allocator, 0x24u);
    v163 = v162;
  }
  else
  {
    v163 = 0;
  }
  v164 = operator new(0xCu);
  if ( v164 )
  {
    *((_DWORD *)v164 + 2) = v163;
    *(_DWORD *)v164 = 36;
    *((_DWORD *)v164 + 1) = 0;
    v165 = v164;
  }
  else
  {
    v165 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v165)
    && v165 )
    operator delete(v165);
  v166 = (CLOCache *)operator new(0x114u);
  if ( v166 )
  {
    CLOCache::CLOCache(v166, (DBObj *(__cdecl *)())StringTable::Allocator, 0x25u);
    v168 = v167;
  }
  else
  {
    v168 = 0;
  }
  v169 = operator new(0xCu);
  if ( v169 )
  {
    *((_DWORD *)v169 + 2) = v168;
    *(_DWORD *)v169 = 37;
    *((_DWORD *)v169 + 1) = 0;
    v170 = v169;
  }
  else
  {
    v170 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v170)
    && v170 )
    operator delete(v170);
  v171 = (CLOCache *)operator new(0x114u);
  if ( v171 )
  {
    CLOCache::CLOCache(v171, (DBObj *(__cdecl *)())EnumIDMap::Allocator, 0x26u);
    v173 = v172;
  }
  else
  {
    v173 = 0;
  }
  v174 = operator new(0xCu);
  if ( v174 )
  {
    *((_DWORD *)v174 + 2) = v173;
    *(_DWORD *)v174 = 38;
    *((_DWORD *)v174 + 1) = 0;
    v175 = v174;
  }
  else
  {
    v175 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v175)
    && v175 )
    operator delete(v175);
  v176 = (CLOCache *)operator new(0x114u);
  if ( v176 )
  {
    CLOCache::CLOCache(v176, (DBObj *(__cdecl *)())ActionMap::Allocator, 0x27u);
    v178 = v177;
  }
  else
  {
    v178 = 0;
  }
  v179 = operator new(0xCu);
  if ( v179 )
  {
    *((_DWORD *)v179 + 2) = v178;
    *(_DWORD *)v179 = 39;
    *((_DWORD *)v179 + 1) = 0;
    v180 = v179;
  }
  else
  {
    v180 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v180)
    && v180 )
    operator delete(v180);
  v181 = (CLOCache *)operator new(0x114u);
  if ( v181 )
  {
    CLOCache::CLOCache(v181, (DBObj *(__cdecl *)())DualEnumIDMap::Allocate, 0x28u);
    v183 = v182;
  }
  else
  {
    v183 = 0;
  }
  v184 = operator new(0xCu);
  if ( v184 )
  {
    *((_DWORD *)v184 + 2) = v183;
    *(_DWORD *)v184 = 40;
    *((_DWORD *)v184 + 1) = 0;
    v185 = v184;
  }
  else
  {
    v185 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v185)
    && v185 )
    operator delete(v185);
  v186 = (CLOCache *)operator new(0x114u);
  if ( v186 )
  {
    CLOCache::CLOCache(v186, (DBObj *(__cdecl *)())String::Allocator, 0x29u);
    v188 = v187;
  }
  else
  {
    v188 = 0;
  }
  v189 = operator new(0xCu);
  if ( v189 )
  {
    *((_DWORD *)v189 + 2) = v188;
    *(_DWORD *)v189 = 41;
    *((_DWORD *)v189 + 1) = 0;
    v190 = v189;
  }
  else
  {
    v190 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v190)
    && v190 )
    operator delete(v190);
  v191 = (CLOCache *)operator new(0x114u);
  if ( v191 )
  {
    CLOCache::CLOCache(v191, (DBObj *(__cdecl *)())ParticleEmitterInfo::Allocator, 0x2Au);
    v193 = v192;
  }
  else
  {
    v193 = 0;
  }
  v194 = operator new(0xCu);
  if ( v194 )
  {
    *((_DWORD *)v194 + 2) = v193;
    *(_DWORD *)v194 = 42;
    *((_DWORD *)v194 + 1) = 0;
    v195 = v194;
  }
  else
  {
    v195 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v195)
    && v195 )
    operator delete(v195);
  v196 = (CLOCache *)operator new(0x114u);
  if ( v196 )
  {
    CLOCache::CLOCache(v196, (DBObj *(__cdecl *)())PhysicsScript::Allocator, 0x2Bu);
    v198 = v197;
  }
  else
  {
    v198 = 0;
  }
  v199 = operator new(0xCu);
  if ( v199 )
  {
    *((_DWORD *)v199 + 2) = v198;
    *(_DWORD *)v199 = 43;
    *((_DWORD *)v199 + 1) = 0;
    v200 = v199;
  }
  else
  {
    v200 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v200)
    && v200 )
    operator delete(v200);
  v201 = (CLOCache *)operator new(0x114u);
  if ( v201 )
  {
    CLOCache::CLOCache(v201, (DBObj *(__cdecl *)())PhysicsScriptTable::Allocator, 0x2Cu);
    v203 = v202;
  }
  else
  {
    v203 = 0;
  }
  v204 = operator new(0xCu);
  if ( v204 )
  {
    *((_DWORD *)v204 + 2) = v203;
    *(_DWORD *)v204 = 44;
    *((_DWORD *)v204 + 1) = 0;
    v205 = v204;
  }
  else
  {
    v205 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v205)
    && v205 )
    operator delete(v205);
  v206 = (CLOCache *)operator new(0x114u);
  if ( v206 )
  {
    CLOCache::CLOCache(v206, MasterProperty::Allocator, 0x2Du);
    v208 = v207;
  }
  else
  {
    v208 = 0;
  }
  v209 = operator new(0xCu);
  if ( v209 )
  {
    *((_DWORD *)v209 + 2) = v208;
    *(_DWORD *)v209 = 45;
    *((_DWORD *)v209 + 1) = 0;
    v210 = v209;
  }
  else
  {
    v210 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v210)
    && v210 )
    operator delete(v210);
  v211 = (CLOCache *)operator new(0x114u);
  if ( v211 )
  {
    CLOCache::CLOCache(v211, (DBObj *(__cdecl *)())Font::Allocator, 0x2Eu);
    v213 = v212;
  }
  else
  {
    v213 = 0;
  }
  v214 = operator new(0xCu);
  if ( v214 )
  {
    *((_DWORD *)v214 + 2) = v213;
    *(_DWORD *)v214 = 46;
    *((_DWORD *)v214 + 1) = 0;
    v215 = v214;
  }
  else
  {
    v215 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v215)
    && v215 )
    operator delete(v215);
  v216 = (CLOCache *)operator new(0x114u);
  if ( v216 )
  {
    CLOCache::CLOCache(v216, (DBObj *(__cdecl *)())FontLocal::Allocate, 0x2Fu);
    v218 = v217;
  }
  else
  {
    v218 = 0;
  }
  v219 = operator new(0xCu);
  if ( v219 )
  {
    *((_DWORD *)v219 + 2) = v218;
    *(_DWORD *)v219 = 47;
    *((_DWORD *)v219 + 1) = 0;
    v220 = v219;
  }
  else
  {
    v220 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v220)
    && v220 )
    operator delete(v220);
  v221 = (CLOCache *)operator new(0x114u);
  if ( v221 )
  {
    CLOCache::CLOCache(v221, (DBObj *(__cdecl *)())CLanguageInfo::Allocator, 0x30u);
    v223 = v222;
  }
  else
  {
    v223 = 0;
  }
  v224 = operator new(0xCu);
  if ( v224 )
  {
    *((_DWORD *)v224 + 2) = v223;
    *(_DWORD *)v224 = 48;
    *((_DWORD *)v224 + 1) = 0;
    v225 = v224;
  }
  else
  {
    v225 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v225)
    && v225 )
    operator delete(v225);
  v226 = (CLOCache *)operator new(0x114u);
  if ( v226 )
  {
    CLOCache::CLOCache(v226, DBPropertyCollection::Allocator, 0x31u);
    v228 = v227;
  }
  else
  {
    v228 = 0;
  }
  v229 = operator new(0xCu);
  if ( v229 )
  {
    *((_DWORD *)v229 + 2) = v228;
    *(_DWORD *)v229 = 49;
    *((_DWORD *)v229 + 1) = 0;
    v230 = v229;
  }
  else
  {
    v230 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v230) )
  {
    if ( v230 )
      operator delete(v230);
  }
}

//----- (004FBE30) --------------------------------------------------------  // acclient.c:295862
void __thiscall CLCache::~CLCache(CLCache *this)
{
  CLCache *v1; // esi@1
  unsigned int v2; // edi@1
  DiskController *v3; // ecx@2
  int v4; // edi@5
  QualifiedDataID *v5; // eax@9
  void *v6; // eax@11
  void *v7; // eax@13
  MissingIteration *v8; // ecx@16
  unsigned int i; // eax@20
  unsigned int v10; // eax@22

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&CLCache::vftable;
  this->vfptr = (AsyncCacheVtbl *)&gmCLCache::vftable;
  this->vfptr = (PortalThreadVtbl *)&CLCache::vftable;
  DBCache::DestroyObjectCaches((DBCache *)&this->vfptr);
  v2 = 0;
  if ( v1->m_DatFiles.m_num )
  {
    do
    {
      v3 = v1->m_DatFiles.m_data[v2];
      if ( v3 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      v1->m_DatFiles.m_data[v2++] = 0;
    }
    while ( v2 < v1->m_DatFiles.m_num );
  }
  v4 = (int)&v1->m_strDatFilePath.m_charbuffer[-1].m_data[6];
  v1->m_DatFiles.m_num = 0;
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( (v1->m_EarlySaves.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v5 = v1->m_EarlySaves.m_data;
    if ( v5 )
      operator delete[](&v5[-1].ID);
  }
  v1->m_DatFileByIDTable.vfptr = (HashTable<unsigned __int64,DiskController *,0>Vtbl *)HashTable<unsigned __int64,DiskController *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_DatFileByIDTable.m_intrusiveTable);
  v6 = v1->m_DatFileByIDTable.m_intrusiveTable.m_buckets;
  v1->m_DatFileByIDTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable;
  if ( v6 != v1->m_DatFileByIDTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v6);
  v1->m_DatFileByIDTable.m_intrusiveTable.m_buckets = 0;
  v1->m_DatFileByIDTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_DatFileByIDTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_DatFileByIDTable.m_intrusiveTable.m_numElements = 0;
  v1->m_PendingDownloads.vfptr = (HashTable<QualifiedDataID,MissingIteration *,1>Vtbl *)HashTable<QualifiedDataID,MissingIteration *,1>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_PendingDownloads.m_intrusiveTable);
  v7 = v1->m_PendingDownloads.m_intrusiveTable.m_buckets;
  v1->m_PendingDownloads.m_intrusiveTable.vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable;
  if ( v7 != v1->m_PendingDownloads.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_PendingDownloads.m_intrusiveTable.m_buckets = 0;
  v1->m_PendingDownloads.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_PendingDownloads.m_intrusiveTable.m_numBuckets = 0;
  v1->m_PendingDownloads.m_intrusiveTable.m_numElements = 0;
  if ( (v1->m_MissingIters.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v8 = v1->m_MissingIters.m_data;
    if ( v8 )
      MissingIteration::vector_deleting_destructor(v8, 3u);
  }
  if ( (v1->m_DatFiles.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_DatFiles.m_data);
  for ( i = 0; i < v1->m_Plugins.m_num; ++i )
    v1->m_Plugins.m_data[i]->m_pManager = 0;
  v10 = v1->m_Plugins.m_sizeAndDeallocate & 0x80000000;
  v1->m_Plugins.m_num = 0;
  if ( v10 == 0x80000000 )
    operator delete[](v1->m_Plugins.m_data);
  ThreadedCache::~ThreadedCache((ThreadedCache *)&v1->vfptr);
}
// 7C59F4: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable[4])(void *, char);
// 7C59F8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable[3])(void *, char);
// 7C5B4C: using guessed type int (__thiscall *HashTable<unsigned __int64,DiskController *,0>::vftable[2])(void *, char);
// 7C5BC0: using guessed type void *CLCache::vftable;
// 7C5BD0: using guessed type DBObj *(__thiscall *gmCLCache::vftable)(CLCache *this, unsigned __int32 type, QualifiedDataID *qdid);
// 7C5C78: using guessed type __int32 (__stdcall *CLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C5CF4: using guessed type int (__thiscall *HashTable<QualifiedDataID,MissingIteration *,1>::vftable[2])(void *, char);

//----- (004FBFF0) --------------------------------------------------------  // acclient.c:295947
void __thiscall PortalThread::SetShouldExit(PortalThread *this, bool fExit)
{
  this->m_fShouldExit = fExit;
  if ( fExit )
    ((void (*)(void))this->vfptr->WakeForTheReaper)();
}

//----- (004FC010) --------------------------------------------------------  // acclient.c:295955
CLCache *__thiscall CLCache::vector_deleting_destructor(CLCache *this, unsigned int a2)
{
  return CLCache::scalar_deleting_destructor((CLCache *)((char *)this - 304), a2);
}

//----- (004FC040) --------------------------------------------------------  // acclient.c:295961
void __thiscall CLCache::UseTime(CLCache *this)
{
  CLCache *v1; // edi@1
  unsigned int v2; // eax@1
  int v3; // ecx@2
  int v4; // esi@3
  int v5; // edx@4
  int v6; // esi@8
  unsigned int v7; // eax@8
  unsigned int v8; // eax@16
  char v9; // [sp+8h] [bp-60h]@16
  DDD_PatchPendingMessage event; // [sp+Ch] [bp-5Ch]@13
  int v11; // [sp+18h] [bp-50h]@23
  QualifiedDataID _data; // [sp+1Ch] [bp-4Ch]@15
  int v13; // [sp+24h] [bp-44h]@20
  int v14; // [sp+28h] [bp-40h]@20
  SmartBuffer v15; // [sp+2Ch] [bp-3Ch]@17
  TransientArchive archive; // [sp+44h] [bp-24h]@8

  v1 = this;
  ThreadedCache::UseTime((ThreadedCache *)&this->vfptr);
  v2 = v1->m_eNameRuleLanguage;
  if ( v2 )
  {
    v3 = *(_DWORD *)v2;
    if ( *(_DWORD *)v2 )
    {
      v5 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)v2 = v5;
      if ( !v5 )
        *(_DWORD *)(v2 + 4) = 0;
      v4 = *(_DWORD *)v3;
      operator delete((void *)v3);
    }
    else
    {
      v4 = 0;
    }
    if ( v4 )
    {
      TransientArchive::TransientArchive(&archive, 0, *(void **)(v4 + 44), *(_DWORD *)(v4 + 48));
      v6 = 0;
      Archive::CheckAlignment((Archive *)&archive.vfptr, 4u);
      v7 = Archive::GetBytes((Archive *)&archive.vfptr, 4u);
      if ( v7 )
      {
        if ( archive.m_flags & 1 )
          *(_DWORD *)v7 = 0;
        else
          v6 = *(_DWORD *)v7;
      }
      switch ( v6 )
      {
        case 63458:
          DDD_DataMessage::DDD_DataMessage((DDD_DataMessage *)&event);
          event.vfptr->Serialize(&event, &archive);
          if ( !((archive.m_flags >> 2) & 1) )
          {
            if ( v1->m_ridDDDRegion == 1 )
            {
              SmartArray<BaseInfo,1>::add(
                (SmartArray<QualifiedDataID,1> *)&v1->m_DatFileByIDTable.m_intrusiveTable.m_numElements,
                &_data);
              v1->m_EarlySaves.m_num += DDD_DataMessage::GetCompressedSize((DDD_DataMessage *)&event);
            }
            (*(void (__thiscall **)(int, char *, DDD_PatchPendingMessage *))&v1[-1].m_strDatFilePath.m_charbuffer[3].m_data[8])(
              &v1[-1].m_strDatFilePath,
              &v9,
              &event);
            v8 = DDD_DataMessage::GetCompressedSize((DDD_DataMessage *)&event);
            CLCache::NotifyDDDEvent((CLCache *)((char *)v1 - 4), DDD_DataDownloaded, v8);
          }
          SmartBuffer::ReleaseMasterBuffer(&v15);
          SmartBuffer::ReleaseMasterBuffer(&v15);
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
        case 63460:
          event.m_et = 63460;
          event.vfptr = (FakeMessageDataVtbl *)&DDD_ErrorMessage::vftable;
          DDD_ErrorMessage::vftable(&event, &archive);
          if ( (archive.m_flags >> 2) & 1 )
            goto LABEL_29;
          MasterDBMap::IsCellType(event.m_nLinePosition);
          ((void (__thiscall *)(CLCache *, unsigned int *))v1->vfptr[6].IUnknown_QueryInterface)(
            v1,
            &event.m_nLinePosition);
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
        case 63461:
          event.m_et = 63461;
          event.vfptr = (FakeMessageDataVtbl *)&DDD_InterrogationMessage::vftable;
          _data.ID.id = 0;
          v13 = 0;
          v14 = 0;
          DDD_InterrogationMessage::vftable(&event, &archive);
          if ( !((archive.m_flags >> 2) & 1) )
            CLCache::OnServerInterrogation((CLCache *)((char *)v1 - 4), (DDD_InterrogationMessage *)&event);
          DDD_InterrogationMessage::~DDD_InterrogationMessage((DDD_InterrogationMessage *)&event);
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
        case 63463:
          event.m_et = 63463;
          event.vfptr = (FakeMessageDataVtbl *)&DDD_BeginDDDMessage::vftable;
          v11 = 0;
          _data.Type = 0;
          _data.ID.id = 0;
          DDD_BeginDDDMessage::vftable(&event, &archive);
          if ( !((archive.m_flags >> 2) & 1) )
            CLCache::OnBeginDDD((CLCache *)((char *)v1 - 4), (DDD_BeginDDDMessage *)&event);
          DDD_BeginDDDMessage::~DDD_BeginDDDMessage((DDD_BeginDDDMessage *)&event);
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
        case 63466:
          CLCache::OnEndDDD((CLCache *)((char *)v1 - 4));
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
        case 63467:
          event.m_et = 63467;
          event.vfptr = (FakeMessageDataVtbl *)&DDD_EndDDDMessage::vftable;
          DDD_EndDDDMessage::vftable((FakeMessageData *)&event.vfptr, (struct Archive *)&archive.vfptr);
          if ( !((archive.m_flags >> 2) & 1) )
            CLCache::NotifyDDDEvent((CLCache *)((char *)v1 - 4), DDD_PatchtimePending, event.m_nLinePosition);
          goto LABEL_29;
        default:
LABEL_29:
          Archive::~Archive((Archive *)&archive.vfptr);
          break;
      }
    }
  }
}
// 7C58C8: using guessed type void (__thiscall *DDD_EndDDDMessage::vftable)(FakeMessageData *this, struct Archive *);
// 7C59F0: using guessed type int (__thiscall *DDD_ErrorMessage::vftable)(_DWORD, _DWORD);
// 7C5A10: using guessed type int (__thiscall *DDD_InterrogationMessage::vftable)(_DWORD, _DWORD);
// 7C5AD4: using guessed type int (__thiscall *DDD_BeginDDDMessage::vftable)(_DWORD, _DWORD);

//----- (004FC310) --------------------------------------------------------  // acclient.c:296098
void __thiscall CLCache::OnSaveRequestFinished(CLCache *this, CAsyncSaveRequest *pSaveReq)
{
  AsyncCache *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // ecx@2
  PSRefBufferCharData<unsigned short> *v4; // ecx@2
  PStringBase<unsigned short> v5; // [sp-10h] [bp-18h]@2
  PStringBase<unsigned short> v6; // [sp-Ch] [bp-14h]@2
  PStringBase<unsigned short> v7; // [sp-8h] [bp-10h]@2
  PlatformString::DisplayStringMode v8; // [sp-4h] [bp-Ch]@2

  v2 = (AsyncCache *)this;
  if ( pSaveReq->Result == 1 )
  {
    if ( this->m_ridDDDRegion == 2 )
      CLCache::RemovePendingDownload((CLCache *)((char *)this - 4), &pSaveReq->qdid);
    AsyncCache::OnSaveRequestFinished(v2, pSaveReq);
  }
  else
  {
    v8 = 0;
    v7.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v7, &word_794320);
    v6.m_charbuffer = v3;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v6, &word_794320);
    v5.m_charbuffer = v4;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, &word_794320);
    PlatformString::DisplayString(0xCFu, v5, v6, v7, v8);
    Turbine::Debug::Abort();
    AsyncCache::OnSaveRequestFinished(v2, pSaveReq);
  }
}

//----- (004FC390) --------------------------------------------------------  // acclient.c:296131
AutoGrowHashTable<QualifiedDataID,MissingIteration *> *__thiscall AutoGrowHashTable<QualifiedDataID,MissingIteration *>::scalar_deleting_destructor(AutoGrowHashTable<QualifiedDataID,MissingIteration *> *this, unsigned int a2)
{
  AutoGrowHashTable<QualifiedDataID,MissingIteration *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<QualifiedDataID,MissingIteration *,1>Vtbl *)HashTable<QualifiedDataID,MissingIteration *,1>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C59F4: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable[4])(void *, char);
// 7C5CF4: using guessed type int (__thiscall *HashTable<QualifiedDataID,MissingIteration *,1>::vftable[2])(void *, char);

//----- (004FC3F0) --------------------------------------------------------  // acclient.c:296157
void __thiscall CLCache::CLCache(CLCache *this)
{
  CLCache *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  ThreadedCache::ThreadedCache((ThreadedCache *)&this->vfptr);
  v1->m_Plugins.m_data = 0;
  v1->m_Plugins.m_sizeAndDeallocate = 0;
  v1->m_Plugins.m_num = 0;
  v1->vfptr = (InterfaceVtbl *)&CLCache::vftable;
  v1->vfptr = (AsyncCacheVtbl *)&gmCLCache::vftable;
  v1->vfptr = (PortalThreadVtbl *)&CLCache::vftable;
  v1->m_DatFiles.m_data = 0;
  v1->m_DatFiles.m_sizeAndDeallocate = 0;
  v1->m_DatFiles.m_num = 0;
  v1->m_fReadOnly = 1;
  v1->m_ridDDDRegion = 0;
  v1->m_MissingIters.m_data = 0;
  v1->m_MissingIters.m_sizeAndDeallocate = 0;
  v1->m_MissingIters.m_num = 0;
  v1->m_PendingDownloads.vfptr = (HashTable<QualifiedDataID,MissingIteration *,1>Vtbl *)HashTable<QualifiedDataID,MissingIteration *,1>::vftable;
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>(
    &v1->m_PendingDownloads.m_intrusiveTable,
    0);
  v1->m_PendingDownloads.vfptr = (HashTable<QualifiedDataID,MissingIteration *,1>Vtbl *)HashTable<QualifiedDataID,MissingIteration *,1>::vftable;
  v1->m_DatFileByIDTable.vfptr = (HashTable<unsigned __int64,DiskController *,0>Vtbl *)HashTable<unsigned __int64,DiskController *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>(
    &v1->m_DatFileByIDTable.m_intrusiveTable,
    0x17u);
  v1->m_EarlySaves.m_data = 0;
  v1->m_EarlySaves.m_sizeAndDeallocate = 0;
  v1->m_EarlySaves.m_num = 0;
  v1->m_eNameRuleLanguage = 1;
  v1->m_pNetQueue = 0;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_strDatFilePath.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->m_bIsClient = 1;
}
// 7C5B4C: using guessed type int (__thiscall *HashTable<unsigned __int64,DiskController *,0>::vftable[2])(void *, char);
// 7C5BC0: using guessed type void *CLCache::vftable;
// 7C5BD0: using guessed type DBObj *(__thiscall *gmCLCache::vftable)(CLCache *this, unsigned __int32 type, QualifiedDataID *qdid);
// 7C5C78: using guessed type __int32 (__stdcall *CLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C5CF4: using guessed type int (__thiscall *HashTable<QualifiedDataID,MissingIteration *,1>::vftable[2])(void *, char);

//----- (004FC4E0) --------------------------------------------------------  // acclient.c:296204
CLCache *__thiscall CLCache::scalar_deleting_destructor(CLCache *this, unsigned int a2)
{
  CLCache *v2; // esi@1

  v2 = this;
  CLCache::~CLCache(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00693570) --------------------------------------------------------  // acclient.c:683222
char __thiscall HashTable<unsigned __int64,DiskController *,0>::add(HashTable<unsigned __int64,DiskController *,0> *this, const unsigned __int64 *_key, DiskController *const *_data)
{
  HashTable<unsigned __int64,DiskController *,0> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0x18u);
  if ( v4 )
  {
    *(_QWORD *)v4 = *_key;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 4) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::add(
         (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned __int64,unsigned __int64> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00699AF0) --------------------------------------------------------  // acclient.c:689646
char __thiscall SmartArray<BaseInfo,1>::add(SmartArray<QualifiedDataID,1> *this, QualifiedDataID *_data)
{
  SmartArray<QualifiedDataID,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2
  unsigned int v6; // ecx@3
  QualifiedDataID *v7; // edx@3

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<FontReference,1>::grow(v2, v4)) != 0) )
  {
    v6 = v2->m_num;
    v7 = v2->m_data;
    v7[v6].Type = _data->Type;
    v7[v6].ID.id = _data->ID.id;
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (006F91D0) --------------------------------------------------------  // acclient.c:781830
int _E73_82()
{
  return atexit(_E74_62);
}

//----- (006F91E0) --------------------------------------------------------  // acclient.c:781836
int _E76_48()
{
  return atexit(_E77_76);
}

//----- (006F91F0) --------------------------------------------------------  // acclient.c:781842
int _E79_41()
{
  return atexit(_E80_40);
}

//----- (006F9200) --------------------------------------------------------  // acclient.c:781848
void _E98_3()
{
  LODWORD(dword_8413A8) = 1053364187;
}

//----- (006F9210) --------------------------------------------------------  // acclient.c:781854
void sub_6F9210()
{
  flt_8413AC = 1000.0 + 1.0;
}

//----- (006F9230) --------------------------------------------------------  // acclient.c:781860
void _E102_11()
{
  flt_8413B0 = 24.0 * 8.0;
}

//----- (006F9250) --------------------------------------------------------  // acclient.c:781866
void _E104_5()
{
  flt_8413B4 = 24.0 * 0.5;
}

//----- (006F9270) --------------------------------------------------------  // acclient.c:781872
void _E106_85()
{
  DEFAULT_VIEW_RADIUS_89 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F9290) --------------------------------------------------------  // acclient.c:781878
void _E108_66()
{
  MIN_QUANTUM_89 = 1.0 / 30.0;
}

//----- (006F92B0) --------------------------------------------------------  // acclient.c:781884
void _E110_56()
{
  MAX_QUANTUM_89 = 1.0 / 5.0;
}

//----- (006F92D0) --------------------------------------------------------  // acclient.c:781890
void _E112_77()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8413D0, PFID_A8R8G8B8);
}

//----- (006F92E0) --------------------------------------------------------  // acclient.c:781896
int _E114_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_43, "None");
  return atexit(sub_764C50);
}

//----- (006F9300) --------------------------------------------------------  // acclient.c:781903
int _E117_52()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_43, "Speed");
  return atexit(sub_764C80);
}

//----- (006F9320) --------------------------------------------------------  // acclient.c:781910
int _E120_47()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_43, "Noise");
  return atexit(sub_764CB0);
}

//----- (006F9340) --------------------------------------------------------  // acclient.c:781917
int _E123_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_43, "Sine");
  return atexit(sub_764CE0);
}

//----- (006F9360) --------------------------------------------------------  // acclient.c:781924
int _E126_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_43, "Square");
  return atexit(sub_764D10);
}

//----- (006F9380) --------------------------------------------------------  // acclient.c:781931
int _E129_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_43, "Bounce");
  return atexit(_E130_90);
}

//----- (006F93A0) --------------------------------------------------------  // acclient.c:781938
int _E132_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_43, "Perlin");
  return atexit(_E133_83);
}

//----- (006F93C0) --------------------------------------------------------  // acclient.c:781945
int _E135_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_43, "Fractal");
  return atexit(_E136_66);
}

//----- (006F93E0) --------------------------------------------------------  // acclient.c:781952
int _E138_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_43, "FrameLoop");
  return atexit(_E139_67);
}

//----- (006F9400) --------------------------------------------------------  // acclient.c:781959
void _E141_20()
{
  dword_84142C = 1024;
}

//----- (006F9410) --------------------------------------------------------  // acclient.c:781965
void _E143_5()
{
  dword_841430 = 0x7FFF;
}

//----- (006F9420) --------------------------------------------------------  // acclient.c:781971
int _E145_24()
{
  const int result; // eax@1

  result = dword_84142C;
  INITIAL_MAX_DATA_RATE_60 = dword_84142C;
  return result;
}

//----- (006F9430) --------------------------------------------------------  // acclient.c:781981
int sub_6F9430()
{
  return atexit(nullsub_1031);
}

//----- (00764C50) --------------------------------------------------------  // acclient.c:891346
void __cdecl sub_764C50()
{
  char *v0; // esi@1

  v0 = &waveform_None_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764C80) --------------------------------------------------------  // acclient.c:891359
void __cdecl sub_764C80()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764CB0) --------------------------------------------------------  // acclient.c:891372
void __cdecl sub_764CB0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764CE0) --------------------------------------------------------  // acclient.c:891385
void __cdecl sub_764CE0()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764D10) --------------------------------------------------------  // acclient.c:891398
void __cdecl sub_764D10()
{
  char *v0; // esi@1

  v0 = &waveform_Square_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764D40) --------------------------------------------------------  // acclient.c:891411
void __cdecl _E130_90()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764D70) --------------------------------------------------------  // acclient.c:891424
void __cdecl _E133_83()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764DA0) --------------------------------------------------------  // acclient.c:891437
void __cdecl _E136_66()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764DD0) --------------------------------------------------------  // acclient.c:891450
void __cdecl _E139_67()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

