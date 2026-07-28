/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Archive
   Object     : CORE\serialize\Archive.obj
   Functions  : 34
   Addresses  : 0040A570 - 006C39E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040A570) --------------------------------------------------------  // acclient.c:69945
unsigned int __thiscall Archive::GetSizeUsed(Archive *this)
{
  return this->m_currOffset;
}

//----- (0040A580) --------------------------------------------------------  // acclient.c:69951
void __thiscall Archive::SetCurrentPosition(Archive *this, unsigned int i_position)
{
  this->m_currOffset = i_position;
}

//----- (0040A590) --------------------------------------------------------  // acclient.c:69957
unsigned int __thiscall Archive::GetSizeLeft(Archive *this)
{
  return SmartBuffer::GetSize(&this->m_buffer) - this->m_currOffset;
}

//----- (0040A5A0) --------------------------------------------------------  // acclient.c:69963
SmartBuffer *__thiscall Archive::GetSerializedBuffer(Archive *this, SmartBuffer *result)
{
  SmartBuffer::MakeWindow(&this->m_buffer, result, 0, this->m_currOffset);
  return result;
}

//----- (0040A5C0) --------------------------------------------------------  // acclient.c:69970
SmartBuffer *__thiscall Archive::GetRemainingBuffer(Archive *this, SmartBuffer *result)
{
  SmartBuffer::MakeWindow(&this->m_buffer, result, this->m_currOffset);
  return result;
}

//----- (0040A5E0) --------------------------------------------------------  // acclient.c:69977
void __thiscall Archive::InitVersionStack(Archive *this)
{
  if ( this->m_pVersionStack )
    ((void (*)(void))this->m_pVersionStack->vfptr[2].IUnknown_AddRef)();
  else
    ((void (*)(void))this->vfptr->CreateVersionStack)();
}

//----- (0040A600) --------------------------------------------------------  // acclient.c:69986
int __thiscall Archive::GetVersionByToken(Archive *this, unsigned int i_tokVersion)
{
  int result; // eax@2

  if ( this->m_pVersionStack )
    result = ((int (__stdcall *)(_DWORD))this->m_pVersionStack->vfptr[1].IUnknown_QueryInterface)(i_tokVersion);
  else
    result = 0;
  return result;
}

//----- (0040A620) --------------------------------------------------------  // acclient.c:69998
unsigned int __cdecl compute_str_hash<char>(const char *i_pstr)
{
  const char *v1; // edx@1
  const char v2; // cl@1
  unsigned int result; // eax@1

  v1 = i_pstr;
  v2 = *i_pstr;
  result = 0;
  if ( *i_pstr )
  {
    do
    {
      result = v2 + 16 * result;
      if ( result & 0xF0000000 )
        result = (result ^ ((result & 0xF0000000) >> 24)) & 0xFFFFFFF;
      v2 = (v1++)[1];
    }
    while ( v2 );
    if ( result == -1 )
      result = -2;
  }
  return result;
}

//----- (0040A670) --------------------------------------------------------  // acclient.c:70024
void __thiscall Archive::SetCheckpointing(Archive *this, bool _checkpointing)
{
  if ( _checkpointing )
    BYTE1(this->m_flags) |= 0x40u;
  else
    BYTE1(this->m_flags) &= 0xBFu;
}

//----- (0040A690) --------------------------------------------------------  // acclient.c:70033
bool __thiscall Archive::UsingDBLoader(Archive *this)
{
  return (this->m_flags & 0x8000) == 0x8000;
}

//----- (0040A6B0) --------------------------------------------------------  // acclient.c:70039
void __thiscall Archive::SetDBLoader(Archive *this, bool _using_DBLoader)
{
  if ( _using_DBLoader )
    BYTE1(this->m_flags) |= 0x80u;
  else
    BYTE1(this->m_flags) &= 0x7Fu;
}

//----- (0040A6D0) --------------------------------------------------------  // acclient.c:70048
void __thiscall Archive::SetWordAligned(Archive *this, bool _aligned)
{
  if ( _aligned )
    this->m_flags |= 2u;
  else
    this->m_flags &= 0xFFFFFFFD;
}

//----- (0040A6F0) --------------------------------------------------------  // acclient.c:70057
void __thiscall Archive::RaiseError(Archive *this)
{
  this->m_flags |= 4u;
  this->m_hrError.m_val = -2147467259;
}

//----- (0040A700) --------------------------------------------------------  // acclient.c:70064
bool __thiscall Archive::IsWordAligned(Archive *this)
{
  return (this->m_flags & 2) == 2;
}

//----- (0040A710) --------------------------------------------------------  // acclient.c:70070
char __thiscall Archive::SetVersionByToken(Archive *this, unsigned int i_tokVersion, unsigned int i_iVersion)
{
  Archive *v3; // esi@1
  unsigned int v4; // eax@1
  IArchiveVersionStack *v5; // ecx@2

  v3 = this;
  v4 = this->m_flags;
  if ( ~(unsigned __int8)(this->m_flags >> 2) & 1 )
  {
    v5 = this->m_pVersionStack;
    if ( !v5 )
    {
      LOBYTE(v4) = v4 | 4;
      v3->m_hrError.m_val = -2147467259;
      v3->m_flags = v4;
      return 0;
    }
    if ( (unsigned __int8)((int (__stdcall *)(unsigned int, unsigned int))v5->vfptr[1].IUnknown_AddRef)(
                            i_tokVersion,
                            i_iVersion) )
      return 1;
    v3->m_flags |= 4u;
    v3->m_hrError.m_val = -2147467259;
  }
  return 0;
}

//----- (0040A770) --------------------------------------------------------  // acclient.c:70099
IDClass<_tagVersionHandle,32,0> *__thiscall Archive::PushVersionRow(Archive *this, IDClass<_tagVersionHandle,32,0> *result)
{
  Archive *v2; // eax@1
  unsigned int v3; // edx@1
  IArchiveVersionStack *v4; // ecx@2
  IDClass<_tagVersionHandle,32,0> *v5; // eax@3

  v2 = this;
  v3 = this->m_flags;
  if ( ~(unsigned __int8)(this->m_flags >> 2) & 1 )
  {
    v4 = this->m_pVersionStack;
    if ( v4 )
    {
      ((void (__stdcall *)(IDClass<_tagVersionHandle,32,0> *))v4->vfptr[1].QueryInterface)(result);
      v5 = result;
    }
    else
    {
      v2->m_flags = v3 | 4;
      v2->m_hrError.m_val = -2147467259;
      v5 = result;
      result->id = INVALID_VERSIONHANDLE_0.id;
    }
  }
  else
  {
    v5 = result;
    result->id = INVALID_VERSIONHANDLE_0.id;
  }
  return v5;
}

//----- (0040A7D0) --------------------------------------------------------  // acclient.c:70133
IDClass<_tagVersionHandle,32,0> *__thiscall Archive::PushVersionRow(Archive *this, IDClass<_tagVersionHandle,32,0> *result, ArchiveVersionRow *i_rInitialData)
{
  Archive *v3; // eax@1
  unsigned int v4; // edx@1
  IArchiveVersionStack *v5; // ecx@2
  IDClass<_tagVersionHandle,32,0> *v6; // eax@3

  v3 = this;
  v4 = this->m_flags;
  if ( ~(unsigned __int8)(this->m_flags >> 2) & 1 )
  {
    v5 = this->m_pVersionStack;
    if ( v5 )
    {
      ((void (__stdcall *)(IDClass<_tagVersionHandle,32,0> *, ArchiveVersionRow *))v5->vfptr[1].IUnknown_Release)(
        result,
        i_rInitialData);
      v6 = result;
    }
    else
    {
      v3->m_flags = v4 | 4;
      v3->m_hrError.m_val = -2147467259;
      v6 = result;
      result->id = INVALID_VERSIONHANDLE_0.id;
    }
  }
  else
  {
    v6 = result;
    result->id = INVALID_VERSIONHANDLE_0.id;
  }
  return v6;
}

//----- (0040A830) --------------------------------------------------------  // acclient.c:70169
bool __thiscall Archive::GetVersionRowByHandle(Archive *this, IDClass<_tagVersionHandle,32,0> i_hVersion, ArchiveVersionRow **o_pVersionRow)
{
  bool result; // al@2

  if ( this->m_pVersionStack )
    result = ((int (__stdcall *)(unsigned int, ArchiveVersionRow **))this->m_pVersionStack->vfptr[1].Release)(
               i_hVersion.id,
               o_pVersionRow);
  else
    result = 0;
  return result;
}

//----- (0040A850) --------------------------------------------------------  // acclient.c:70183
IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *__thiscall IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // esi@1
  InArchiveVersionStack::VersionRowHolder **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable;
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
// 79442C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable)(void *, char);

//----- (0040A890) --------------------------------------------------------  // acclient.c:70204
char __stdcall Archive::tagSetCurrentCoreVersion::InitializeArchive(Archive *io_rcArchive)
{
  Archive *v2; // esi@1
  char result; // al@2

  v2 = io_rcArchive;
  if ( ~(unsigned __int8)(io_rcArchive->m_flags >> 2) & 1 )
  {
    Archive::PushVersionRow(io_rcArchive, (IDClass<_tagVersionHandle,32,0> *)&io_rcArchive);
    Archive::SetVersionByToken(v2, 0x436F7265u, 2u);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040A8D0) --------------------------------------------------------  // acclient.c:70224
bool __thiscall Archive::SetVersionRow::InitializeArchive(Archive::SetVersionRow *this, Archive *io_rcArchive)
{
  bool result; // al@2

  if ( ~(unsigned __int8)(io_rcArchive->m_flags >> 2) & 1 )
    result = INVALID_VERSIONHANDLE_0.id != Archive::PushVersionRow(
                                             io_rcArchive,
                                             (IDClass<_tagVersionHandle,32,0> *)&io_rcArchive,
                                             this->m_rInitialData)->id;
  else
    result = 0;
  return result;
}

//----- (0040A910) --------------------------------------------------------  // acclient.c:70239
unsigned int __thiscall Archive::PeekBytes(Archive *this, unsigned int i_position, unsigned int i_size)
{
  Archive *v3; // esi@1
  unsigned int v5; // ebx@3
  SmartBuffer *v6; // edi@4

  v3 = this;
  if ( (this->m_flags >> 2) & 1 )
    return 0;
  v5 = i_size + i_position;
  if ( this->m_flags & 1 )
  {
    v6 = &this->m_buffer;
    if ( SmartBuffer::CanGrow(&this->m_buffer) )
    {
      SmartBuffer::ReconfigureAllocation(&v3->m_buffer, v5, 1u);
      return i_position + SmartBuffer::GetBuffer(v6);
    }
  }
  v6 = &v3->m_buffer;
  if ( SmartBuffer::GetSize(&v3->m_buffer) >= v5 )
    return i_position + SmartBuffer::GetBuffer(v6);
  v3->m_flags |= 4u;
  v3->m_hrError.m_val = -2147467259;
  return 0;
}

//----- (0040A990) --------------------------------------------------------  // acclient.c:70267
unsigned int __thiscall Archive::GetBytes(Archive *this, unsigned int i_size)
{
  Archive *v2; // esi@1
  unsigned int result; // eax@1

  v2 = this;
  result = Archive::PeekBytes(this, this->m_currOffset, i_size);
  if ( result )
    v2->m_currOffset += i_size;
  return result;
}

//----- (0040A9B0) --------------------------------------------------------  // acclient.c:70280
void __thiscall Archive::CheckAlignment(Archive *this, unsigned int i_objectSize)
{
  Archive *v2; // ebx@1
  unsigned int v3; // esi@4
  unsigned int v4; // edi@6
  unsigned int v5; // edx@6
  unsigned int v6; // esi@7
  unsigned int v7; // edi@7

  v2 = this;
  if ( this->m_flags & 2 )
  {
    if ( i_objectSize & 3 )
    {
      if ( (i_objectSize & 3) != 2 )
        return;
      v3 = 2;
    }
    else
    {
      v3 = 4;
    }
    v4 = this->m_currOffset;
    v5 = (v4 + SmartBuffer::GetBuffer(&this->m_buffer)) % v3;
    if ( v5 )
    {
      v6 = v3 - v5;
      v7 = Archive::PeekBytes(v2, v4, v6);
      if ( v7 )
      {
        v2->m_currOffset += v6;
        if ( v2->m_flags & 1 )
          memset((void *)v7, 0, v6);
      }
      else
      {
        v2->m_flags |= 4u;
        v2->m_hrError.m_val = -2147467259;
      }
    }
  }
}

//----- (0040AA30) --------------------------------------------------------  // acclient.c:70324
void __thiscall IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>(IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (InArchiveVersionStack::VersionRowHolder **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (InArchiveVersionStack::VersionRowHolder **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79442C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable)(void *, char);

//----- (0040AAD0) --------------------------------------------------------  // acclient.c:70362
void __thiscall InArchiveVersionStack::InArchiveVersionStack(InArchiveVersionStack *this)
{
  InArchiveVersionStack *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&InArchiveVersionStack::vftable;
  v2 = (char *)&this->m_hlVersions;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>(
    &this->m_hlVersions.m_hash,
    0);
  *((_DWORD *)v2 + 28) = 0;
  *((_DWORD *)v2 + 29) = 0;
  v1->m_vrDefaultRow.m_hashKey.id = INVALID_VERSIONHANDLE_0.id;
  v1->m_vrDefaultRow.m_hashNext = 0;
  v1->m_vrDefaultRow.dllist_next = 0;
  v1->m_vrDefaultRow.dllist_prev = 0;
  v1->m_vrDefaultRow.m_VersionRow.vfptr = (ArchiveVersionRowVtbl *)&ArchiveVersionRow::vftable;
  v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_num = 0;
  v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_data = (ArchiveVersionRow::VersionEntry *)v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_aPrimitiveInplaceMemory;
  v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_sizeAndDeallocate = 8;
  v1->m_iLastSerialNumber = 1;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);
// 794434: using guessed type __int32 (__stdcall *InArchiveVersionStack::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0040AB50) --------------------------------------------------------  // acclient.c:70392
LONG __thiscall InArchiveVersionStack::AddRef(InArchiveVersionStack *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0040AB60) --------------------------------------------------------  // acclient.c:70398
unsigned int __thiscall InArchiveVersionStack::Release(InArchiveVersionStack *this)
{
  InArchiveVersionStack *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    InArchiveVersionStack::~InArchiveVersionStack(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (0040AB90) --------------------------------------------------------  // acclient.c:70414
void __thiscall Archive::CreateVersionStack(Archive *this)
{
  Archive *v1; // esi@1
  InArchiveVersionStack *v2; // eax@1
  IArchiveVersionStack *v3; // eax@2

  v1 = this;
  v2 = (InArchiveVersionStack *)operator new(0xE8u);
  if ( v2 )
  {
    InArchiveVersionStack::InArchiveVersionStack(v2);
    v1->m_pVersionStack = v3;
  }
  else
  {
    v1->m_pVersionStack = 0;
  }
}

//----- (0040ABC0) --------------------------------------------------------  // acclient.c:70434
void __thiscall Archive::ReleaseUserData(Archive *this)
{
  Archive *v1; // ebp@1
  HashTable<unsigned long,Interface *,0> *v2; // eax@1
  int v3; // edx@3
  HashTableData<unsigned long,Interface *> **v4; // ecx@4
  int v5; // ecx@5
  HashTableData<unsigned long,Interface *> **v6; // edi@6
  HashTableData<unsigned long,Interface *> *v7; // ecx@6
  HashTableData<unsigned long,Interface *> **v8; // eax@7
  HashTableData<unsigned long,Interface *> *v9; // eax@8
  Interface *v10; // esi@8
  int v11; // edx@8
  HashTableData<unsigned long,Interface *> *v12; // ebx@9

  v1 = this;
  v2 = this->m_pcUserDataHash;
  if ( v2 && v2->m_intrusiveTable.m_numElements )
  {
    do
    {
      v3 = (int)&v2->m_intrusiveTable.m_buckets[v2->m_intrusiveTable.m_numBuckets];
      if ( v2->m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,Interface *> **)v3 )
      {
LABEL_6:
        v6 = 0;
        v7 = 0;
      }
      else
      {
        while ( 1 )
        {
          v4 = v2->m_intrusiveTable.m_firstInterestingBucket;
          if ( *v4 )
            break;
          v5 = (int)(v4 + 1);
          v2->m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,Interface *> **)v5;
          if ( v5 == v3 )
            goto LABEL_6;
        }
        v8 = v2->m_intrusiveTable.m_firstInterestingBucket;
        v7 = *v8;
        v6 = v8;
      }
      v9 = *v6;
      v10 = v7->m_data;
      v11 = (int)&v1->m_pcUserDataHash->m_intrusiveTable;
      if ( *v6 == v7 )
        goto LABEL_16;
      do
      {
        v12 = v9;
        v9 = v9->m_hashNext;
      }
      while ( v9 != v7 );
      if ( v12 )
        v12->m_hashNext = v9->m_hashNext;
      else
LABEL_16:
        *v6 = v9->m_hashNext;
      --*(_DWORD *)(v11 + 108);
      operator delete(v7);
      v10->vfptr->Release(v10);
      v2 = v1->m_pcUserDataHash;
    }
    while ( v2->m_intrusiveTable.m_numElements );
  }
}

//----- (0040AC50) --------------------------------------------------------  // acclient.c:70504
void __thiscall Archive::InitForPacking(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer)
{
  Archive *v3; // esi@1
  int v4; // edi@1
  ArchiveVtbl *v5; // edx@4

  v3 = this;
  v4 = (int)&this->m_buffer;
  if ( SmartBuffer::GetShareCount(&this->m_buffer) != 1 || SmartBuffer::GetSize(i_buffer) )
  {
    Archive::ReleaseUserData(v3);
    SmartBuffer::ReleaseMasterBuffer((SmartBuffer *)v4);
    SmartBuffer::operator=(v4, (int)i_buffer);
  }
  v5 = v3->vfptr;
  v3->m_flags = v3->m_flags & 0xFFFFFFFB | 1;
  v3->m_currOffset = 0;
  v3->m_hrError.m_val = 0;
  v5->InitVersionStack(v3);
  ((void (__stdcall *)(_DWORD))i_rInitializer->vfptr->InitializeArchive)(v3);
}

//----- (0040ACC0) --------------------------------------------------------  // acclient.c:70527
void __thiscall Archive::InitForUnpacking(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer)
{
  Archive *v3; // esi@1
  ArchiveVtbl *v4; // edx@1

  v3 = this;
  Archive::ReleaseUserData(this);
  SmartBuffer::ReleaseMasterBuffer(&v3->m_buffer);
  SmartBuffer::operator=((int)&v3->m_buffer, (int)i_buffer);
  v4 = v3->vfptr;
  v3->m_flags &= 0xFFFFFFFA;
  v3->m_currOffset = 0;
  v3->m_hrError.m_val = 0;
  v4->InitVersionStack(v3);
  ((void (__stdcall *)(_DWORD))i_rInitializer->vfptr->InitializeArchive)(v3);
}

//----- (0040AD00) --------------------------------------------------------  // acclient.c:70545
void __thiscall Archive::~Archive(Archive *this)
{
  Archive *v1; // esi@1
  HashTable<unsigned long,Interface *,0> *v2; // ecx@1
  IArchiveVersionStack *v3; // ecx@3

  v1 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  Archive::ReleaseUserData(this);
  SmartBuffer::ReleaseMasterBuffer(&v1->m_buffer);
  v2 = v1->m_pcUserDataHash;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->m_pVersionStack;
  v1->m_pcUserDataHash = 0;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pVersionStack = 0;
  }
  SmartBuffer::ReleaseMasterBuffer(&v1->m_buffer);
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (006C39E0) --------------------------------------------------------  // acclient.c:732029
int _E21_0()
{
  return atexit(_E22_0);
}

