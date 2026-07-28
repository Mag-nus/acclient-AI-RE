/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MasterDBMapMain
   Object     : ENGINE\filedb_core\MasterDBMapMain.obj
   Functions  : 26
   Addresses  : 0041BE00 - 00727100 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0041BE00) --------------------------------------------------------  // acclient.c:89316
bool __cdecl MasterDBMap::Init(MasterDBMap *_mapper)
{
  bool result; // al@3

  if ( !_mapper || MasterDBMap::sm_mmap )
  {
    result = 0;
  }
  else
  {
    MasterDBMap::sm_mmap = _mapper;
    result = ((int (*)(void))_mapper->vfptr->InitDBTypeDef_Internal)();
  }
  return result;
}

//----- (0041BE20) --------------------------------------------------------  // acclient.c:89333
char __cdecl MasterDBMap::Cleanup()
{
  operator delete(MasterDBMap::sm_mmap);
  MasterDBMap::sm_mmap = 0;
  return 1;
}

//----- (0041BE40) --------------------------------------------------------  // acclient.c:89341
int __cdecl MasterDBMap::DivineType(PStringBase<char> *_filename)
{
  int result; // eax@2

  if ( MasterDBMap::sm_mmap )
    result = (*(int (__stdcall **)(PStringBase<char> *))(*(_DWORD *)MasterDBMap::sm_mmap + 4))(_filename);
  else
    result = 0;
  return result;
}

//----- (0041BE60) --------------------------------------------------------  // acclient.c:89353
int __cdecl MasterDBMap::DivineType(IDClass<_tagDataID,32,0> _did)
{
  int result; // eax@2

  if ( MasterDBMap::sm_mmap )
    result = (*(int (__stdcall **)(unsigned int))(*(_DWORD *)MasterDBMap::sm_mmap + 8))(_did.id);
  else
    result = 0;
  return result;
}

//----- (0041BE80) --------------------------------------------------------  // acclient.c:89365
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *v2; // esi@1
  HashTableData<unsigned long,DBTypeDef> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable;
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
// 7954D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable[2])(void *, char);

//----- (0041BEC0) --------------------------------------------------------  // acclient.c:89386
void __cdecl MasterDBMap::SetGameDataDir(PStringBase<char> *_dir)
{
  char *v1; // esi@2

  if ( MasterDBMap::sm_game_data_dir.m_charbuffer != _dir->m_charbuffer )
  {
    v1 = &MasterDBMap::sm_game_data_dir.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&MasterDBMap::sm_game_data_dir.m_charbuffer[-1]) && v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    MasterDBMap::sm_game_data_dir.m_charbuffer = _dir->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&MasterDBMap::sm_game_data_dir.m_charbuffer[-1]);
  }
  PSUtils::cleanup_directory_name(&MasterDBMap::sm_game_data_dir, 0);
}

//----- (0041BF10) --------------------------------------------------------  // acclient.c:89402
void __cdecl MasterDBMap::SetEngineDataDir(PStringBase<char> *_dir)
{
  char *v1; // esi@2

  if ( MasterDBMap::sm_engine_data_dir.m_charbuffer != _dir->m_charbuffer )
  {
    v1 = &MasterDBMap::sm_engine_data_dir.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&MasterDBMap::sm_engine_data_dir.m_charbuffer[-1]) && v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    MasterDBMap::sm_engine_data_dir.m_charbuffer = _dir->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&MasterDBMap::sm_engine_data_dir.m_charbuffer[-1]);
  }
  PSUtils::cleanup_directory_name(&MasterDBMap::sm_engine_data_dir, 0);
}

//----- (0041BF60) --------------------------------------------------------  // acclient.c:89418
void __thiscall DBTypeDef::DBTypeDef(DBTypeDef *this)
{
  DBTypeDef *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->m_base_did.id = INVALID_DID_12.id;
  this->m_top_did.id = INVALID_DID_12.id;
  this->m_extensions.m_data = 0;
  this->m_extensions.m_sizeAndDeallocate = 0;
  this->m_extensions.m_num = 0;
  this->m_packVersion = 0;
  this->m_updateType = 0;
  this->m_bHasFile = 0;
  this->m_bIsPortalType = 0;
  this->m_bIsCellType = 0;
  this->m_bIsLocalType = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_strDataDir.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->m_bIsClientType = 0;
  v1->m_bIsServerType = 0;
  v1->m_bIsEngineType = 0;
  v1->m_bIsDIDPackedToDats = 0;
  v1->m_bIsWBEditable = 0;
  v1->m_bIsCategorized = 0;
  v1->m_bForceExpire = 0;
  v1->m_freelistDef.m_bRecycle = 0;
  v1->m_freelistDef.m_bShrink = 0;
  v1->m_freelistDef.m_nIdealSize = 16;
  v1->m_freelistDef.m_nMaxSize = 16;
}

//----- (0041BFE0) --------------------------------------------------------  // acclient.c:89452
DBTypeDef *__cdecl MasterDBMap::GetDBTypeDef(const unsigned int _dbtype)
{
  HashTableData<unsigned long,DBTypeDef> *v1; // eax@3
  DBTypeDef *result; // eax@6

  if ( !(_S82_1 & 1) )
  {
    _S82_1 |= 1u;
    DBTypeDef::DBTypeDef(&INVALID_DBTypeDef);
    atexit(_E83_3);
  }
  v1 = stru_8177AC.m_buckets[_dbtype % stru_8177AC.m_numBuckets];
  if ( !v1 )
    goto LABEL_12;
  while ( v1->m_hashKey != _dbtype )
  {
    v1 = v1->m_hashNext;
    if ( !v1 )
      return &INVALID_DBTypeDef;
  }
  if ( !v1 || (result = &v1->m_data) == 0 )
LABEL_12:
    result = &INVALID_DBTypeDef;
  return result;
}

//----- (0041C060) --------------------------------------------------------  // acclient.c:89479
bool __cdecl MasterDBMap::IsPortalType(const unsigned int _dbtype)
{
  return MasterDBMap::GetDBTypeDef(_dbtype)->m_bIsPortalType;
}

//----- (0041C080) --------------------------------------------------------  // acclient.c:89485
bool __cdecl MasterDBMap::IsCellType(const unsigned int _dbtype)
{
  return MasterDBMap::GetDBTypeDef(_dbtype)->m_bIsCellType;
}

//----- (0041C0A0) --------------------------------------------------------  // acclient.c:89491
bool __cdecl MasterDBMap::IsLocalType(const unsigned int _dbtype)
{
  return MasterDBMap::GetDBTypeDef(_dbtype)->m_bIsLocalType;
}

//----- (0041C0C0) --------------------------------------------------------  // acclient.c:89497
bool __cdecl MasterDBMap::IsCategorized(const unsigned int _dbtype)
{
  return MasterDBMap::GetDBTypeDef(_dbtype)->m_bIsCategorized;
}

//----- (0041C0E0) --------------------------------------------------------  // acclient.c:89503
FreelistDef *__cdecl MasterDBMap::GetFreelistDef(const unsigned int _dbtype)
{
  return &MasterDBMap::GetDBTypeDef(_dbtype)->m_freelistDef;
}

//----- (0041C100) --------------------------------------------------------  // acclient.c:89509
char __cdecl MasterDBMap::VerifyDirectory(PStringBase<char> _strFileName, unsigned int _dbType)
{
  DBTypeDef *v2; // eax@1
  PStringBase<char> *v3; // ecx@1
  PSRefBufferCharData<char> *v4; // eax@1
  PSRefBufferCharData<char> *v5; // ebx@2
  DBTypeDef *v6; // eax@4
  PStringBase<char> *v7; // ecx@4
  PSRefBufferCharData<char> *v8; // eax@4
  PSRefBufferCharData<char> *v9; // ebp@5
  char *v10; // esi@10
  char v12; // [sp+13h] [bp-9h]@8
  PStringBase<char> testpath; // [sp+14h] [bp-8h]@7
  PStringBase<char> engine; // [sp+18h] [bp-4h]@2

  v2 = MasterDBMap::GetDBTypeDef(_dbType);
  v3 = &v2->m_strDataDir;
  v4 = v2->m_strDataDir.m_charbuffer;
  if ( *(_DWORD *)&v4[-1].m_data[12] == 1 )
  {
    v5 = v4;
    InterlockedIncrement((volatile LONG *)&v4[-1]);
  }
  else
  {
    PStringBase<char>::operator+(&MasterDBMap::sm_game_data_dir, &engine, v3);
    v5 = engine.m_charbuffer;
  }
  v6 = MasterDBMap::GetDBTypeDef(_dbType);
  v7 = &v6->m_strDataDir;
  v8 = v6->m_strDataDir.m_charbuffer;
  if ( *(_DWORD *)&v8[-1].m_data[12] == 1 )
  {
    v9 = v8;
    InterlockedIncrement((volatile LONG *)&v8[-1]);
  }
  else
  {
    PStringBase<char>::operator+(&MasterDBMap::sm_engine_data_dir, &engine, v7);
    v9 = engine.m_charbuffer;
  }
  testpath.m_charbuffer = _strFileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_strFileName.m_charbuffer[-1]);
  PSUtils::cleanup_directory_name(&testpath, 0);
  if ( !__strnicmp(v5->m_data, testpath.m_charbuffer->m_data, *(_DWORD *)&v5[-1].m_data[12] - 1)
    || (v12 = 0, !__strnicmp(v9->m_data, testpath.m_charbuffer->m_data, *(_DWORD *)&v9[-1].m_data[12] - 1)) )
    v12 = 1;
  v10 = &testpath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&testpath.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
  if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
  if ( !InterlockedDecrement((volatile LONG *)&_strFileName.m_charbuffer[-1])
    && _strFileName.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&_strFileName.m_charbuffer[-2].m_data[12])(
      &_strFileName.m_charbuffer[-2].m_data[12],
      1);
  return v12;
}

//----- (0041C250) --------------------------------------------------------  // acclient.c:89572
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,DBTypeDef> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,DBTypeDef> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7954D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable[2])(void *, char);

//----- (0041C2E0) --------------------------------------------------------  // acclient.c:89605
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> *v1; // ebp@1
  int v2; // ecx@2
  HashTableData<unsigned long,DBTypeDef> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,DBTypeDef> **v5; // edx@5
  HashTableData<unsigned long,DBTypeDef> *v6; // ebx@5
  HashTableData<unsigned long,DBTypeDef> *v7; // eax@7
  HashTableData<unsigned long,DBTypeDef> *v8; // ecx@8
  int v9; // esi@13
  PStringBase<char> *v10; // ecx@17
  PSRefBufferCharData<char> *v11; // eax@18
  void *v12; // edx@18
  int v13; // edi@18
  int v14; // eax@18
  int v15; // esi@20
  int v16; // esi@20
  int v17; // [sp+8h] [bp-8h]@19
  int v18; // [sp+Ch] [bp-4h]@18

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,DBTypeDef> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,DBTypeDef> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_30;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_30:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = (int)&v6->m_data.m_strDataDir.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( (v6->m_data.m_extensions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      {
        v10 = v6->m_data.m_extensions.m_data;
        if ( v10 )
        {
          v11 = v10[-1].m_charbuffer;
          v12 = &v10[-1];
          v13 = (int)&v10[(_DWORD)v11];
          v14 = (int)&v11[-1].m_data[15];
          v18 = (int)&v10[-1];
          if ( v14 >= 0 )
          {
            v17 = v14 + 1;
            do
            {
              v15 = *(_DWORD *)(v13 - 4);
              v13 -= 4;
              v16 = v15 - 20;
              if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) )
              {
                if ( v16 )
                  (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
              }
              --v17;
            }
            while ( v17 );
            v12 = (void *)v18;
          }
          operator delete[](v12);
        }
      }
      operator delete(v6);
    }
  }
}

//----- (0041C400) --------------------------------------------------------  // acclient.c:89708
HashTable<unsigned long,DBTypeDef,0> *__thiscall HashTable<unsigned long,DBTypeDef,0>::vector_deleting_destructor(HashTable<unsigned long,DBTypeDef,0> *this, unsigned int a2)
{
  HashTable<unsigned long,DBTypeDef,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,DBTypeDef,0>Vtbl *)&HashTable<unsigned long,DBTypeDef,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable;
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
// 7954D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable[2])(void *, char);
// 7954D4: using guessed type int (__thiscall *HashTable<unsigned long,DBTypeDef,0>::vftable)(void *, char);

//----- (006C4A50) --------------------------------------------------------  // acclient.c:732996
int _E73_16()
{
  PStringBase<char>::PStringBase<char>(&MasterDBMap::sm_game_data_dir, &name);
  return atexit(_E74_19);
}

//----- (006C4A70) --------------------------------------------------------  // acclient.c:733003
int _E76_10()
{
  PStringBase<char>::PStringBase<char>(&MasterDBMap::sm_engine_data_dir, &name);
  return atexit(_E77_38);
}

//----- (006C4A90) --------------------------------------------------------  // acclient.c:733010
int _E79_10()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>(
    &stru_8177AC,
    0x80u);
  return atexit(_E80_12);
}

//----- (006C4AB0) --------------------------------------------------------  // acclient.c:733019
int _E1_12()
{
  return atexit(_E2_12);
}

//----- (00727050) --------------------------------------------------------  // acclient.c:824842
void __cdecl _E74_19()
{
  char *v0; // esi@1

  v0 = &MasterDBMap::sm_game_data_dir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MasterDBMap::sm_game_data_dir.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727080) --------------------------------------------------------  // acclient.c:824855
void __cdecl _E77_38()
{
  char *v0; // esi@1

  v0 = &MasterDBMap::sm_engine_data_dir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MasterDBMap::sm_engine_data_dir.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007270B0) --------------------------------------------------------  // acclient.c:824868
void __cdecl _E83_3()
{
  char *v0; // esi@1

  v0 = &INVALID_DBTypeDef.m_strDataDir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&INVALID_DBTypeDef.m_strDataDir.m_charbuffer[-1]) && v0 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  if ( (INVALID_DBTypeDef.m_extensions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( INVALID_DBTypeDef.m_extensions.m_data )
      PStringBase<unsigned short>::vector_deleting_destructor(INVALID_DBTypeDef.m_extensions.m_data, 3u);
  }
}

//----- (00727100) --------------------------------------------------------  // acclient.c:824883
void __cdecl _E80_12()
{
  MasterDBMap::sm_DBTypeDefHash.vfptr = (HashTable<unsigned long,DBTypeDef,0>Vtbl *)&HashTable<unsigned long,DBTypeDef,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::delete_contents(&stru_8177AC);
  stru_8177AC.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable;
  if ( (HashTableData<unsigned long,DBTypeDef> **)stru_8177AC.m_buckets != stru_8177AC.m_aInplaceBuckets )
    operator delete[](stru_8177AC.m_buckets);
  stru_8177AC.m_buckets = 0;
  stru_8177AC.m_firstInterestingBucket = 0;
  stru_8177AC.m_numBuckets = 0;
  stru_8177AC.m_numElements = 0;
}
// 7954D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable[2])(void *, char);
// 7954D4: using guessed type int (__thiscall *HashTable<unsigned long,DBTypeDef,0>::vftable)(void *, char);

