/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCLCache
   Object     : GAME\game_cdatabase\gmCLCache.obj
   Functions  : 23
   Addresses  : 0058A860 - 0070A080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0058A860) --------------------------------------------------------  // acclient.c:435118
void __cdecl ACCharGenData::Allocator()
{
  ACCharGenData *v0; // eax@1

  v0 = (ACCharGenData *)operator new(0xB0u);
  if ( v0 )
    ACCharGenData::ACCharGenData(v0);
}

//----- (0058A880) --------------------------------------------------------  // acclient.c:435128
void __cdecl Attribute2ndTable::Allocator()
{
  Attribute2ndTable *v0; // eax@1

  v0 = (Attribute2ndTable *)operator new(0x98u);
  if ( v0 )
    Attribute2ndTable::Attribute2ndTable(v0, did);
}

//----- (0058A8B0) --------------------------------------------------------  // acclient.c:435138
void __cdecl SkillTable::Allocator()
{
  SkillTable *v0; // eax@1

  v0 = (SkillTable *)operator new(0x50u);
  if ( v0 )
    SkillTable::SkillTable(v0, did);
}

//----- (0058A8D0) --------------------------------------------------------  // acclient.c:435148
void __cdecl CSpellTable::Allocator()
{
  CSpellTable *v0; // eax@1

  v0 = (CSpellTable *)operator new(0xC8u);
  if ( v0 )
    CSpellTable::CSpellTable(v0, did);
}

//----- (0058A900) --------------------------------------------------------  // acclient.c:435158
void __cdecl SpellComponentTable::Allocator()
{
  SpellComponentTable *v0; // eax@1

  v0 = (SpellComponentTable *)operator new(0x50u);
  if ( v0 )
    SpellComponentTable::SpellComponentTable(v0, did);
}

//----- (0058A920) --------------------------------------------------------  // acclient.c:435168
void __cdecl ExperienceTable::Allocator()
{
  ExperienceTable *v0; // eax@1

  v0 = (ExperienceTable *)operator new(0x68u);
  if ( v0 )
    ExperienceTable::ExperienceTable(v0, did);
}

//----- (0058A940) --------------------------------------------------------  // acclient.c:435178
void __cdecl CQuestDefDB::Allocator()
{
  CQuestDefDB *v0; // eax@1

  v0 = (CQuestDefDB *)operator new(0x50u);
  if ( v0 )
    CQuestDefDB::CQuestDefDB(v0);
}

//----- (0058A960) --------------------------------------------------------  // acclient.c:435188
void __cdecl ACQualityFilter::Allocator()
{
  ACQualityFilter *v0; // eax@1

  v0 = (ACQualityFilter *)operator new(0x68u);
  if ( v0 )
    ACQualityFilter::ACQualityFilter(v0, did);
}

//----- (0058A980) --------------------------------------------------------  // acclient.c:435198
void __cdecl CombatManeuverTable::Allocator()
{
  CombatManeuverTable *v0; // eax@1

  v0 = (CombatManeuverTable *)operator new(0x40u);
  if ( v0 )
    CombatManeuverTable::CombatManeuverTable(v0, did);
}

//----- (0058A9A0) --------------------------------------------------------  // acclient.c:435208
void __cdecl CContractTable::Allocator()
{
  CContractTable *v0; // eax@1

  v0 = (CContractTable *)operator new(0x50u);
  if ( v0 )
    CContractTable::CContractTable(v0, did);
}

//----- (0058A9C0) --------------------------------------------------------  // acclient.c:435218
void __thiscall gmCLCache::gmCLCache(gmCLCache *this)
{
  gmCLCache *v1; // esi@1

  v1 = this;
  CLCache::CLCache((CLCache *)&this->vfptr);
  v1->vfptr = (InterfaceVtbl *)&gmCLCache::vftable;
  v1->vfptr = (AsyncCacheVtbl *)&gmCLCache::vftable;
  v1->vfptr = (PortalThreadVtbl *)&gmCLCache::vftable;
}
// 7C5BD0: using guessed type DBObj *(__thiscall *gmCLCache::vftable)(CLCache *this, unsigned __int32 type, QualifiedDataID *qdid);
// 7E321C: using guessed type void *gmCLCache::vftable;
// 7E3230: using guessed type __int32 (__stdcall *gmCLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0058A9F0) --------------------------------------------------------  // acclient.c:435233
gmCLCache *__thiscall gmCLCache::vector_deleting_destructor(gmCLCache *this, unsigned int a2)
{
  return gmCLCache::scalar_deleting_destructor((gmCLCache *)((char *)this - 304), a2);
}

//----- (0058AA00) --------------------------------------------------------  // acclient.c:435239
gmCLCache *__thiscall gmCLCache::scalar_deleting_destructor(gmCLCache *this, unsigned int a2)
{
  gmCLCache *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&gmCLCache::vftable;
  this->vfptr = (AsyncCacheVtbl *)&gmCLCache::vftable;
  this->vfptr = (PortalThreadVtbl *)&gmCLCache::vftable;
  CLCache::~CLCache((CLCache *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C5BD0: using guessed type DBObj *(__thiscall *gmCLCache::vftable)(CLCache *this, unsigned __int32 type, QualifiedDataID *qdid);
// 7E321C: using guessed type void *gmCLCache::vftable;
// 7E3230: using guessed type __int32 (__stdcall *gmCLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0058AA40) --------------------------------------------------------  // acclient.c:435257
char __thiscall gmCLCache::Init(gmCLCache *this, PStringBase<char> *data_file, bool read_only_f, bool cell_lru_f, bool portal_lru_f, bool engine_only_f, unsigned int local_lang_i, int region_i)
{
  CLCache *v8; // esi@1
  MasterDBMap *v9; // eax@1
  char result; // al@4

  v8 = (CLCache *)this;
  v9 = (MasterDBMap *)operator new(4u);
  if ( v9 )
    v9->vfptr = (MasterDBMapVtbl *)&gmMasterDBMap::vftable;
  else
    v9 = 0;
  result = MasterDBMap::Init(v9);
  if ( result )
  {
    DBCache::s_GameDataPackVer = 0;
    DBCache::s_GameCellPackVer = 0;
    DBCache::s_GameDidPackVer = 0;
    result = CLCache::Init(v8, data_file, read_only_f, cell_lru_f, portal_lru_f, 0, local_lang_i, region_i);
  }
  return result;
}
// 7E32AC: using guessed type bool (__thiscall *gmMasterDBMap::vftable)(gmMasterDBMap *__hidden this);
// 8175F4: using guessed type __int32 DBCache::s_GameCellPackVer;
// 8175F8: using guessed type __int32 DBCache::s_GameDidPackVer;

//----- (0058AAC0) --------------------------------------------------------  // acclient.c:435284
void gmCLCache::Init_Internal()
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

  CLCache::Init_Internal();
  v1 = (CLOCache *)operator new(0x114u);
  if ( v1 )
  {
    CLOCache::CLOCache(v1, (DBObj *(__cdecl *)())ACCharGenData::Allocator, 0x10000002u);
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
    *(_DWORD *)v4 = 268435458;
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
    CLOCache::CLOCache(v6, (DBObj *(__cdecl *)())Attribute2ndTable::Allocator, 0x10000003u);
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
    *(_DWORD *)v9 = 268435459;
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
    CLOCache::CLOCache(v11, (DBObj *(__cdecl *)())SkillTable::Allocator, 0x10000004u);
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
    *(_DWORD *)v14 = 268435460;
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
    CLOCache::CLOCache(v16, (DBObj *(__cdecl *)())CSpellTable::Allocator, 0x10000005u);
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
    *(_DWORD *)v19 = 268435461;
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
    CLOCache::CLOCache(v21, (DBObj *(__cdecl *)())SpellComponentTable::Allocator, 0x10000006u);
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
    *(_DWORD *)v24 = 268435462;
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
    CLOCache::CLOCache(v26, (DBObj *(__cdecl *)())ExperienceTable::Allocator, 0x10000009u);
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
    *(_DWORD *)v29 = 268435465;
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
    CLOCache::CLOCache(v31, (DBObj *(__cdecl *)())CQuestDefDB::Allocator, 0x1000000Au);
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
    *(_DWORD *)v34 = 268435466;
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
    CLOCache::CLOCache(v36, (DBObj *(__cdecl *)())ACQualityFilter::Allocator, 0x1000000Cu);
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
    *(_DWORD *)v39 = 268435468;
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
    CLOCache::CLOCache(v41, (DBObj *(__cdecl *)())CombatManeuverTable::Allocator, 0x1000000Du);
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
    *(_DWORD *)v44 = 268435469;
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
    CLOCache::CLOCache(v46, (DBObj *(__cdecl *)())CContractTable::Allocator, 0x10000010u);
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
    *(_DWORD *)v49 = 268435472;
    *((_DWORD *)v49 + 1) = 0;
    v50 = v49;
  }
  else
  {
    v50 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v50) )
  {
    if ( v50 )
      operator delete(v50);
  }
}

//----- (00709FE0) --------------------------------------------------------  // acclient.c:797264
int sub_709FE0()
{
  return atexit(_E74_83);
}

//----- (00709FF0) --------------------------------------------------------  // acclient.c:797270
int _E76_67()
{
  return atexit(_E77_95);
}

//----- (0070A000) --------------------------------------------------------  // acclient.c:797276
int _E79_61()
{
  return atexit(_E80_60);
}

//----- (0070A010) --------------------------------------------------------  // acclient.c:797282
void _E98_17()
{
  LODWORD(dword_870C74) = 1053364187;
}

//----- (0070A020) --------------------------------------------------------  // acclient.c:797288
void sub_70A020()
{
  flt_870C78 = 1000.0 + 1.0;
}

//----- (0070A040) --------------------------------------------------------  // acclient.c:797294
void _E102_33()
{
  flt_870C7C = 24.0 * 8.0;
}

//----- (0070A060) --------------------------------------------------------  // acclient.c:797300
void _E104_17()
{
  flt_870C80 = 24.0 * 0.5;
}

//----- (0070A080) --------------------------------------------------------  // acclient.c:797306
int sub_70A080()
{
  return atexit(nullsub_1400);
}

