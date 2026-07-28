/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CRegionDesc
   Object     : PORTAL\cregion\CRegionDesc.obj
   Functions  : 50
   Addresses  : 004FC5E0 - 00765000 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FC5E0) --------------------------------------------------------  // acclient.c:296266
int __cdecl PackObj::UNPACK_TYPE(int *data_r, void **buffer_vpr, unsigned int *size_r)
{
  int result; // eax@2

  if ( *size_r >= 4 )
  {
    *data_r = *(_DWORD *)*buffer_vpr;
    *buffer_vpr = (char *)*buffer_vpr + 4;
    *size_r -= 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FE8F0) --------------------------------------------------------  // acclient.c:298892
char __cdecl CRegionDesc::SetRegion(unsigned int region_num)
{
  int v1; // esi@1
  char result; // al@2

  v1 = DBObj::GetByEnum(region_num, 11, 0x1Cu);
  if ( v1 )
  {
    if ( CRegionDesc::current_region )
      ((void (*)(void))CRegionDesc::current_region->vfptr->Release)();
    CRegionDesc::current_region = (CRegionDesc *)v1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FE930) --------------------------------------------------------  // acclient.c:298913
void __cdecl CRegionDesc::RemoveCurrentRegion()
{
  if ( CRegionDesc::current_region )
  {
    DBCache::FlushFreeObjects(1u);
    ((void (*)(void))CRegionDesc::current_region->vfptr->Release)();
  }
  CRegionDesc::current_region = 0;
}

//----- (004FE960) --------------------------------------------------------  // acclient.c:298924
unsigned int __thiscall CRegionDesc::NumSceneType(CRegionDesc *this, unsigned int terrain_id)
{
  return CTerrainDesc::NumSceneType(this->terrain_info, terrain_id);
}

//----- (004FE970) --------------------------------------------------------  // acclient.c:298930
unsigned int __thiscall CRegionDesc::SceneCount(CRegionDesc *this, unsigned int terrain_id, unsigned int scene_type_id)
{
  return CTerrainDesc::SceneCount(this->terrain_info, terrain_id, scene_type_id);
}

//----- (004FE980) --------------------------------------------------------  // acclient.c:298936
BOOL __thiscall CRegionDesc::IsPalShifted(CRegionDesc *this)
{
  return *(_DWORD *)CommandList::GetHead((ChatDisplayInfo *)this->terrain_info) != 0;
}

//----- (004FE9A0) --------------------------------------------------------  // acclient.c:298942
void __cdecl CRegionDesc::CalcDayGroup()
{
  SkyDesc *v0; // ecx@2

  if ( CRegionDesc::current_region )
  {
    v0 = CRegionDesc::current_region->sky_info;
    if ( v0 )
      SkyDesc::CalcPresentDayGroup(v0);
  }
}

//----- (004FE9C0) --------------------------------------------------------  // acclient.c:298955
int __cdecl CRegionDesc::GetLighting(float time_of_day, float *ambient, RGBAUnion *amb_color, AC1Legacy::Vector3 *directional, RGBAUnion *dir_color)
{
  SkyDesc *v5; // ecx@2
  int result; // eax@3

  if ( CRegionDesc::current_region && (v5 = CRegionDesc::current_region->sky_info) != 0 )
  {
    SkyDesc::GetLighting(v5, time_of_day, ambient, amb_color, directional, dir_color);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FEA00) --------------------------------------------------------  // acclient.c:298973
int __cdecl CRegionDesc::GetWorldFog(float time_of_day, float *min, float *max, RGBAUnion *color)
{
  SkyDesc *v4; // ecx@2
  int result; // eax@3

  if ( CRegionDesc::current_region && (v4 = CRegionDesc::current_region->sky_info) != 0 )
    result = SkyDesc::GetWorldFog(v4, time_of_day, min, max, color);
  else
    result = 0;
  return result;
}

//----- (004FEA30) --------------------------------------------------------  // acclient.c:298986
int __cdecl CRegionDesc::GetSky(float time_of_day, AC1Legacy::SmartArray<CelestialPosition> *sky_pos)
{
  SkyDesc *v2; // ecx@2
  int result; // eax@3

  if ( CRegionDesc::current_region && (v2 = CRegionDesc::current_region->sky_info) != 0 )
    result = SkyDesc::GetSky(v2, time_of_day, sky_pos);
  else
    result = 0;
  return result;
}

//----- (004FEA60) --------------------------------------------------------  // acclient.c:298999
int __thiscall AmbientSTBDesc::InitSoundTable(AmbientSTBDesc *this)
{
  AmbientSTBDesc *v1; // esi@1
  QualifiedDataID *v2; // eax@3
  int v3; // eax@3
  QualifiedDataID v5; // [sp+4h] [bp-8h]@3

  v1 = this;
  if ( this->stb_not_found || this->stb_id.id == stru_841488.id )
    return 0;
  QualifiedDataID::QualifiedDataID(&v5, this->stb_id, 0x22u);
  v3 = DBObj::Get(v2);
  v1->sound_table = (CSoundTable *)v3;
  if ( !v3 )
  {
    v1->stb_not_found = 1;
    return 0;
  }
  return 1;
}

//----- (004FEAB0) --------------------------------------------------------  // acclient.c:299021
AmbientSTBDesc *__thiscall CRegionDesc::GetSTBDesc(CRegionDesc *this, unsigned int terrain_id, unsigned int scene_type_id)
{
  AmbientSTBDesc *v3; // eax@1
  AmbientSTBDesc *v4; // esi@1
  AmbientSTBDesc *result; // eax@4

  v3 = CTerrainDesc::GetSTBDesc(this->terrain_info, terrain_id, scene_type_id);
  v4 = v3;
  if ( v3 && (v3->sound_table || AmbientSTBDesc::InitSoundTable(v3)) )
    result = v4;
  else
    result = 0;
  return result;
}

//----- (004FEAF0) --------------------------------------------------------  // acclient.c:299037
IDClass<_tagDataID,32,0> *__thiscall CRegionDesc::GetScene(CRegionDesc *this, IDClass<_tagDataID,32,0> *result, unsigned int terrain_id, unsigned int scene_type_id, unsigned int scene_index)
{
  CTerrainDesc::GetScene(this->terrain_info, result, terrain_id, scene_type_id, scene_index);
  return result;
}

//----- (004FEB20) --------------------------------------------------------  // acclient.c:299044
unsigned int __thiscall RegionMisc::Pack(RegionMisc *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int v4; // esi@3
  unsigned int v5; // esi@4
  unsigned int v6; // esi@5
  unsigned int v7; // esi@6

  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->version;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      *(_DWORD *)*addr = this->game_map.id;
      *addr = (char *)*addr + 4;
      v4 = *size - 4;
      *size = v4;
      if ( v4 >= 4 )
      {
        *(_DWORD *)*addr = this->autotest_map.id;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          *(_DWORD *)*addr = this->autotest_map_size;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            *(_DWORD *)*addr = this->clear_cell.id;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              *(_DWORD *)*addr = this->clear_monster.id;
              *addr = (char *)*addr + 4;
              *size -= 4;
            }
          }
        }
      }
    }
  }
  return *size;
}

//----- (004FEBC0) --------------------------------------------------------  // acclient.c:299097
int __thiscall RegionMisc::UnPack(RegionMisc *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int v4; // edi@3
  unsigned int v5; // edi@4
  unsigned int v6; // esi@5
  unsigned int v7; // edi@6
  unsigned int v8; // edi@7

  if ( *size >= 4 )
  {
    this->version = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      v4 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      *size -= 4;
      this->game_map.id = v4;
      if ( *size >= 4 )
      {
        v5 = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        *size -= 4;
        this->autotest_map.id = v5;
        if ( *size >= 4 )
        {
          this->autotest_map_size = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            v7 = *(_DWORD *)*addr;
            *addr = (char *)*addr + 4;
            *size -= 4;
            this->clear_cell.id = v7;
            if ( *size >= 4 )
            {
              v8 = *(_DWORD *)*addr;
              *addr = (char *)*addr + 4;
              *size -= 4;
              this->clear_monster.id = v8;
            }
          }
        }
      }
    }
  }
  return 1;
}

//----- (004FEC60) --------------------------------------------------------  // acclient.c:299152
void __thiscall CRegionDesc::CRegionDesc(CRegionDesc *this, IDClass<_tagDataID,32,0> gid)
{
  CRegionDesc *v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&CRegionDesc::vftable;
  v2->vfptr = (PackObjVtbl *)&CRegionDesc::vftable;
  v2->region_number = 0;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v2->region_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v2->parts_mask = 0;
  v2->file_info = 0;
  v2->sky_info = 0;
  v2->sound_info = 0;
  v2->scene_info = 0;
  v2->terrain_info = 0;
  v2->encounter_info = 0;
  v2->water_info = 0;
  v2->fog_info = 0;
  v2->dist_fog_info = 0;
  v2->region_map_info = 0;
  v2->region_misc = 0;
  v2->version = -1;
  v2->minimize_pal = 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5FE8: using guessed type void *CRegionDesc::vftable;
// 7C6000: using guessed type __int32 (__stdcall *CRegionDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FECE0) --------------------------------------------------------  // acclient.c:299187
CRegionDesc *__thiscall CRegionDesc::vector_deleting_destructor(CRegionDesc *this, unsigned int a2)
{
  return CRegionDesc::scalar_deleting_destructor((CRegionDesc *)((char *)this - 48), a2);
}

//----- (004FECF0) --------------------------------------------------------  // acclient.c:299193
void __thiscall CRegionDesc::Destroy(CRegionDesc *this)
{
  CRegionDesc *v1; // esi@1
  FileNameDesc *v2; // edi@1
  void *v3; // edi@3
  void *v4; // edi@5
  void *v5; // edi@7
  void *v6; // edi@11
  void *v7; // edi@13

  v1 = this;
  v2 = this->file_info;
  this->version = -1;
  if ( v2 )
  {
    FileNameDesc::~FileNameDesc(v2);
    operator delete(v2);
    v1->file_info = 0;
  }
  v3 = v1->sky_info;
  if ( v3 )
  {
    SkyDesc::~SkyDesc(v1->sky_info);
    operator delete(v3);
    v1->sky_info = 0;
  }
  v4 = v1->scene_info;
  if ( v4 )
  {
    CSceneDesc::~CSceneDesc(v1->scene_info);
    operator delete(v4);
    v1->scene_info = 0;
  }
  v5 = v1->terrain_info;
  if ( v5 )
  {
    CTerrainDesc::~CTerrainDesc(v1->terrain_info);
    operator delete(v5);
    v1->terrain_info = 0;
  }
  if ( v1->region_misc )
  {
    operator delete(v1->region_misc);
    v1->region_misc = 0;
  }
  v6 = v1->sound_info;
  if ( v6 )
  {
    CSoundDesc::~CSoundDesc(v1->sound_info);
    operator delete(v6);
    v1->sound_info = 0;
  }
  v7 = v1->encounter_info;
  if ( v7 )
  {
    CEncounterDesc::~CEncounterDesc(v1->encounter_info);
    operator delete(v7);
    v1->encounter_info = 0;
  }
}

//----- (004FEDC0) --------------------------------------------------------  // acclient.c:299255
void __thiscall CRegionDesc::GetSubDataIDs(CRegionDesc *this, QualifiedDataIDArray *id_array)
{
  CRegionDesc *v2; // esi@1
  SkyDesc *v3; // ecx@1
  CSoundDesc *v4; // ecx@3
  CSceneDesc *v5; // ecx@5
  CTerrainDesc *v6; // ecx@7
  RegionMisc *v7; // esi@9
  QualifiedDataID *v8; // eax@10
  QualifiedDataID *v9; // eax@10
  QualifiedDataID v10; // [sp+8h] [bp-8h]@10

  v2 = this;
  v3 = this->sky_info;
  if ( v3 )
    SkyDesc::GetSubDataIDs(v3, id_array);
  v4 = v2->sound_info;
  if ( v4 )
    CSoundDesc::GetSubDataIDs(v4, id_array);
  v5 = v2->scene_info;
  if ( v5 )
    CSceneDesc::GetSubDataIDs(v5, id_array);
  v6 = v2->terrain_info;
  if ( v6 )
    CTerrainDesc::GetSubDataIDs(v6, id_array);
  v7 = v2->region_misc;
  if ( v7 )
  {
    QualifiedDataID::QualifiedDataID(&v10, v7->game_map, 0);
    QualifiedDataIDArray::AddQDID(id_array, v8, 8u);
    QualifiedDataID::QualifiedDataID(&v10, v7->autotest_map, 0);
    QualifiedDataIDArray::AddQDID(id_array, v9, 8u);
  }
}

//----- (004FEE50) --------------------------------------------------------  // acclient.c:299291
int __thiscall CRegionDesc::pack_size(CRegionDesc *this)
{
  CRegionDesc *v1; // edi@1
  unsigned int v2; // eax@1
  signed int v3; // ecx@1
  int v4; // edx@3
  int v5; // ecx@3
  int v6; // eax@4
  int v7; // esi@6
  unsigned int v8; // eax@16

  v1 = this;
  v2 = this->region_name.m_buffer->m_len - 1;
  v3 = 0;
  if ( v2 >= 0xFFFF )
    v3 = 4;
  v4 = v3 + v2 + 2;
  v5 = ((_BYTE)v3 + (_BYTE)v2 + 2) & 3;
  if ( v5 )
    v6 = 4 - v5;
  else
    v6 = 0;
  v7 = v6 + v4 + 1068;
  if ( GameTime::current_game_time )
    v7 += GameTime::pack_size(GameTime::current_game_time);
  if ( v1->parts_mask & 0x10 )
    v7 += SkyDesc::pack_size(v1->sky_info);
  if ( v1->parts_mask & 1 )
    v7 += CSoundDesc::pack_size(v1->sound_info);
  if ( v1->parts_mask & 2 )
    v7 += CSceneDesc::pack_size(v1->scene_info);
  if ( v1->parts_mask & 4 )
    v7 += CTerrainDesc::pack_size(v1->terrain_info);
  v8 = v1->parts_mask;
  if ( BYTE1(v8) & 2 )
    v7 += 24;
  return v7;
}

//----- (004FEEF0) --------------------------------------------------------  // acclient.c:299331
unsigned int __thiscall CRegionDesc::Pack(CRegionDesc *this, void **addr, unsigned int size)
{
  CRegionDesc *v3; // ebx@1
  int v4; // ecx@1
  unsigned int v5; // eax@1
  unsigned int result; // eax@2
  void **v7; // esi@3
  char *v8; // eax@4
  char *v9; // ecx@4
  int v10; // eax@6
  unsigned int v11; // ecx@7
  char *v12; // eax@7
  bool v13; // cf@7
  unsigned int v14; // ecx@8
  char *v15; // eax@8
  unsigned int v16; // ecx@9
  char *v17; // eax@9
  unsigned int v18; // ecx@10
  char *v19; // eax@10
  unsigned int v20; // ecx@11
  char *v21; // eax@11
  unsigned int v22; // ecx@12
  char *v23; // eax@12
  unsigned int v24; // ecx@13
  char *v25; // eax@13
  unsigned int v26; // eax@14
  unsigned int v27; // eax@15
  unsigned int v28; // edx@17
  char *v29; // ecx@17
  unsigned int v30; // edx@18
  char *v31; // ecx@18
  unsigned int v32; // edx@19
  char *v33; // ecx@19
  unsigned int v34; // edx@20
  char *v35; // ecx@20
  unsigned int v36; // edx@21
  char *v37; // ecx@21
  unsigned int v38; // edx@22
  char *v39; // ecx@22
  unsigned int v40; // edx@23
  char *v41; // ecx@23
  unsigned int v42; // ecx@24
  unsigned int v43; // eax@29
  unsigned int v44; // ebp@35
  unsigned int v45; // eax@36
  unsigned int v46; // ebx@37
  int v47; // edi@38
  unsigned int v48; // ecx@40
  int v49; // edx@41
  unsigned int v50; // ecx@41
  unsigned int v51; // eax@41
  int v52; // edx@42
  unsigned int v53; // eax@47
  int v54; // ecx@50
  int v55; // eax@50
  unsigned int v56; // ecx@51
  unsigned int v57; // edi@52
  int v58; // ebx@53
  int v59; // eax@53
  unsigned int v60; // eax@54
  int v61; // eax@55
  unsigned int v62; // ecx@56
  unsigned int v63; // ebp@57
  int v64; // edi@58
  unsigned int v65; // ecx@60
  unsigned int v66; // edx@61
  unsigned int v67; // ecx@61
  unsigned int v68; // eax@61
  int v69; // edx@62
  unsigned int v70; // eax@67
  DBObj *v71; // eax@72
  CRegionDesc *v72; // [sp+4h] [bp-30h]@1
  int _height; // [sp+8h] [bp-2Ch]@6
  int _width; // [sp+Ch] [bp-28h]@6
  float _cell_size; // [sp+10h] [bp-24h]@6
  int _cells_per_block; // [sp+14h] [bp-20h]@6
  int _cell_sub_divide; // [sp+18h] [bp-1Ch]@6
  float _max_obj_height; // [sp+1Ch] [bp-18h]@6
  float _sky_height; // [sp+20h] [bp-14h]@6
  float _road_width; // [sp+24h] [bp-10h]@6
  unsigned int num_stypes; // [sp+28h] [bp-Ch]@55
  unsigned int num_terrain; // [sp+2Ch] [bp-8h]@50
  unsigned int retval; // [sp+30h] [bp-4h]@1
  void **addra; // [sp+38h] [bp+4h]@52

  v3 = this;
  v72 = this;
  v4 = CRegionDesc::pack_size((CRegionDesc *)((char *)this - 48));
  v5 = size;
  retval = v4;
  if ( size >= v4 )
  {
    v7 = addr;
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = *(_DWORD *)&v3->m_bLoaded;
      v8 = (char *)*addr + 4;
      *addr = v8;
      v9 = v8;
      v5 = size - 4;
      size -= 4;
      if ( size >= 4 )
      {
        *(_DWORD *)v9 = LODWORD(v3->m_timeStamp);
        v5 = size - 4;
        *addr = (char *)*addr + 4;
        size = v5;
      }
    }
    v10 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&v3->m_bLoaded + 1, addr, v5);
    size -= v10;
    LandDefs::get_vars(
      &_height,
      &_width,
      &_cell_size,
      &_cells_per_block,
      &_cell_sub_divide,
      &_max_obj_height,
      &_sky_height,
      &_road_width);
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = _height;
      v11 = size - 4;
      v12 = (char *)*addr + 4;
      v13 = size - 4 < 4;
      *addr = v12;
      size = v11;
      if ( !v13 )
      {
        *(_DWORD *)v12 = _width;
        v14 = size - 4;
        v15 = (char *)*addr + 4;
        v13 = size - 4 < 4;
        *addr = v15;
        size = v14;
        if ( !v13 )
        {
          *(float *)v15 = _cell_size;
          v16 = size - 4;
          v17 = (char *)*addr + 4;
          v13 = size - 4 < 4;
          *addr = v17;
          size = v16;
          if ( !v13 )
          {
            *(_DWORD *)v17 = _cells_per_block;
            v18 = size - 4;
            v19 = (char *)*addr + 4;
            v13 = size - 4 < 4;
            *addr = v19;
            size = v18;
            if ( !v13 )
            {
              *(_DWORD *)v19 = _cell_sub_divide;
              v20 = size - 4;
              v21 = (char *)*addr + 4;
              v13 = size - 4 < 4;
              *addr = v21;
              size = v20;
              if ( !v13 )
              {
                *(float *)v21 = _max_obj_height;
                v22 = size - 4;
                v23 = (char *)*addr + 4;
                v13 = size - 4 < 4;
                *addr = v23;
                size = v22;
                if ( !v13 )
                {
                  *(float *)v23 = _sky_height;
                  v24 = size - 4;
                  v25 = (char *)*addr + 4;
                  v13 = size - 4 < 4;
                  *addr = v25;
                  size = v24;
                  if ( !v13 )
                  {
                    *(float *)v25 = _road_width;
                    v26 = size - 4;
                    *addr = (char *)*addr + 4;
                    size = v26;
                  }
                }
              }
            }
          }
        }
      }
    }
    v27 = 0;
    do
    {
      if ( size >= 4 )
      {
        *(float *)*addr = *(float *)&(&LandDefs::Land_Height_Table)[v27];
        v28 = size - 4;
        v29 = (char *)*addr + 4;
        v13 = size - 4 < 4;
        *addr = v29;
        size = v28;
        if ( !v13 )
        {
          *(float *)v29 = flt_8EDA2C[v27];
          v30 = size - 4;
          v31 = (char *)*addr + 4;
          v13 = size - 4 < 4;
          *addr = v31;
          size = v30;
          if ( !v13 )
          {
            *(float *)v31 = flt_8EDA30[v27];
            v32 = size - 4;
            v33 = (char *)*addr + 4;
            v13 = size - 4 < 4;
            *addr = v33;
            size = v32;
            if ( !v13 )
            {
              *(float *)v33 = flt_8EDA34[v27];
              v34 = size - 4;
              v35 = (char *)*addr + 4;
              v13 = size - 4 < 4;
              *addr = v35;
              size = v34;
              if ( !v13 )
              {
                *(float *)v35 = flt_8EDA38[v27];
                v36 = size - 4;
                v37 = (char *)*addr + 4;
                v13 = size - 4 < 4;
                *addr = v37;
                size = v36;
                if ( !v13 )
                {
                  *(float *)v37 = flt_8EDA3C[v27];
                  v38 = size - 4;
                  v39 = (char *)*addr + 4;
                  v13 = size - 4 < 4;
                  *addr = v39;
                  size = v38;
                  if ( !v13 )
                  {
                    *(float *)v39 = flt_8EDA40[v27];
                    v40 = size - 4;
                    v41 = (char *)*addr + 4;
                    v13 = size - 4 < 4;
                    *addr = v41;
                    size = v40;
                    if ( !v13 )
                    {
                      *(float *)v41 = flt_8EDA44[v27];
                      v42 = size - 4;
                      *addr = (char *)*addr + 4;
                      size = v42;
                    }
                  }
                }
              }
            }
          }
        }
      }
      v27 += 8;
    }
    while ( v27 < 256 );
    if ( GameTime::current_game_time )
      GameTime::Pack(GameTime::current_game_time, addr, &size);
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->m_pNext;
      v43 = size - 4;
      *addr = (char *)*addr + 4;
      size = v43;
    }
    if ( (unsigned int)v3->m_pNext & 0x10 )
      SkyDesc::Pack((SkyDesc *)v3->m_pMaintainer, addr, &size);
    if ( (unsigned int)v3->m_pNext & 1 )
      CSoundDesc::Pack((CSoundDesc *)v3->m_numLinks, addr, &size);
    if ( (unsigned int)v3->m_pNext & 2 )
    {
      v44 = *(_DWORD *)(v3->m_DID.id + 8);
      if ( size >= 4 )
      {
        *(_DWORD *)*addr = v44;
        v45 = size - 4;
        *addr = (char *)*addr + 4;
        size = v45;
      }
      v46 = 0;
      if ( v44 )
      {
        do
        {
          v47 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v72->m_DID.id + 4 * v46) + 16);
          if ( v47 )
          {
            v49 = v72->m_numLinks;
            v50 = *(_DWORD *)(v49 + 8);
            v51 = 0;
            if ( v50 )
            {
              v52 = *(_DWORD *)v49;
              while ( v47 != *(_DWORD *)v52 )
              {
                ++v51;
                v52 += 4;
                if ( v51 >= v50 )
                  goto LABEL_48;
              }
              if ( size >= 4 )
              {
                *(_DWORD *)*addr = v51;
                v53 = size - 4;
                *addr = (char *)*addr + 4;
                size = v53;
              }
            }
          }
          else if ( size >= 4 )
          {
            *(_DWORD *)*addr = -1;
            v48 = size - 4;
            *addr = (char *)*addr + 4;
            size = v48;
          }
LABEL_48:
          CSceneType::pack(*(CSceneType **)(*(_DWORD *)v72->m_DID.id + 4 * v46++), addr, &size);
        }
        while ( v46 < v44 );
      }
      v3 = v72;
    }
    CSceneDesc::pack_size((CSceneDesc *)v3->m_DID.id);
    v54 = *(_DWORD *)&v3->m_AllowedInFreeList;
    v55 = *(_DWORD *)(v54 + 12);
    num_terrain = *(_DWORD *)(v54 + 12);
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v55;
      v56 = size - 4;
      *addr = (char *)*addr + 4;
      size = v56;
    }
    v57 = 0;
    addra = 0;
    if ( v55 )
    {
      do
      {
        v58 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v3->m_AllowedInFreeList + 4) + 4 * v57);
        v59 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)v58, v7, size);
        size -= v59;
        if ( size >= 4 )
        {
          *(_DWORD *)*v7 = *(_DWORD *)(v58 + 4);
          v60 = size - 4;
          *v7 = (char *)*v7 + 4;
          size = v60;
        }
        v61 = *(_DWORD *)(v58 + 16);
        num_stypes = *(_DWORD *)(v58 + 16);
        if ( size >= 4 )
        {
          *(_DWORD *)*v7 = v61;
          v62 = size - 4;
          *v7 = (char *)*v7 + 4;
          size = v62;
        }
        v63 = 0;
        if ( v61 )
        {
          do
          {
            v64 = *(_DWORD *)(*(_DWORD *)(v58 + 8) + 4 * v63);
            if ( v64 )
            {
              v66 = v72->m_DID.id;
              v67 = *(_DWORD *)(v66 + 8);
              v68 = 0;
              if ( v67 )
              {
                v69 = *(_DWORD *)v66;
                while ( v64 != *(_DWORD *)v69 )
                {
                  ++v68;
                  v69 += 4;
                  if ( v68 >= v67 )
                    goto LABEL_68;
                }
                if ( size >= 4 )
                {
                  *(_DWORD *)*v7 = v68;
                  v70 = size - 4;
                  *v7 = (char *)*v7 + 4;
                  size = v70;
                }
              }
            }
            else if ( size >= 4 )
            {
              *(_DWORD *)*v7 = -1;
              v65 = size - 4;
              *v7 = (char *)*v7 + 4;
              size = v65;
            }
LABEL_68:
            ++v63;
          }
          while ( v63 < num_stypes );
          v57 = (unsigned int)addra;
        }
        v3 = v72;
        ++v57;
        addra = (void **)v57;
      }
      while ( v57 < num_terrain );
    }
    result = LandSurf::Pack(**(LandSurf ***)&v3->m_AllowedInFreeList, v7, &size);
    if ( result )
    {
      CTerrainDesc::pack_size(*(CTerrainDesc **)&v3->m_AllowedInFreeList);
      v71 = v3->m_pNext;
      if ( BYTE1(v71) & 2 )
        RegionMisc::Pack((RegionMisc *)v3->minimize_pal, v7, &size);
      result = retval;
    }
  }
  else
  {
    result = v4;
  }
  return result;
}
// 8EDA28: using guessed type float *LandDefs::Land_Height_Table;
// 8EDA2C: using guessed type float flt_8EDA2C[];
// 8EDA30: using guessed type float flt_8EDA30[];
// 8EDA34: using guessed type float flt_8EDA34[];
// 8EDA38: using guessed type float flt_8EDA38[];
// 8EDA3C: using guessed type float flt_8EDA3C[];
// 8EDA40: using guessed type float flt_8EDA40[];
// 8EDA44: using guessed type float flt_8EDA44[];

//----- (004FF440) --------------------------------------------------------  // acclient.c:299775
void **__thiscall CRegionDesc::UnPack(CRegionDesc *this, void **addr, unsigned int size)
{
  CRegionDesc *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@1
  void **v6; // esi@1
  char *v7; // ecx@2
  unsigned int v8; // ecx@4
  void **result; // eax@6
  int v10; // eax@10
  signed int v11; // ecx@10
  int v12; // edx@12
  int v13; // eax@12
  int v14; // ecx@13
  int v15; // ecx@15
  unsigned int v16; // edi@15
  char *v17; // eax@16
  void *v18; // eax@17
  void *v19; // eax@18
  void *v20; // eax@19
  void *v21; // eax@20
  void *v22; // eax@21
  int v23; // eax@22
  void *v24; // esp@24
  unsigned int v25; // eax@24
  GameTime *v26; // eax@28
  GameTime *v27; // eax@29
  GameTime *v28; // edi@29
  GameTime *v29; // ebx@32
  unsigned int v30; // ecx@35
  SkyDesc *v31; // eax@37
  SkyDesc *v32; // eax@38
  TurbineChatBlob *v33; // eax@43
  CSoundDesc *v34; // eax@44
  TurbineChatBlob *v35; // eax@49
  unsigned int v36; // eax@50
  unsigned int v37; // edi@53
  unsigned int v38; // ebx@56
  CSceneType *v39; // eax@57
  int v40; // eax@58
  int v41; // edi@58
  CTerrainDesc *v42; // eax@69
  int v43; // eax@70
  unsigned int v44; // edi@73
  CTerrainType *v45; // eax@76
  CTerrainType *v46; // eax@77
  CTerrainType *v47; // ebx@77
  int v48; // eax@80
  signed int v49; // ecx@80
  int v50; // edx@82
  int v51; // eax@82
  int v52; // ecx@83
  unsigned int v53; // ecx@86
  int v54; // eax@86
  bool v55; // cf@86
  unsigned int v56; // ecx@87
  int v57; // edi@88
  unsigned int v58; // edx@91
  int v59; // ebx@93
  unsigned int v60; // eax@95
  unsigned int v61; // eax@97
  LandSurf *v62; // eax@105
  int v63; // eax@106
  void *v64; // eax@109
  DBObj *v65; // edi@112
  int v66; // [sp-400h] [bp-42Ch]@26
  unsigned int *v67; // [sp+Ch] [bp-20h]@1
  unsigned int num_terrain; // [sp+10h] [bp-1Ch]@73
  CTerrainType *ttype; // [sp+14h] [bp-18h]@79
  unsigned int v70; // [sp+18h] [bp-14h]@89
  unsigned int scene_index; // [sp+1Ch] [bp-10h]@91
  unsigned int num_stypes; // [sp+20h] [bp-Ch]@53
  unsigned int iq; // [sp+24h] [bp-8h]@55
  CRegionDesc *v74; // [sp+28h] [bp-4h]@1

  v3 = this;
  v4 = this[-1].parts_mask;
  v74 = this;
  v67 = &this[-1].parts_mask;
  (*(void (**)(void))(v4 + 60))();
  v5 = size;
  v6 = addr;
  if ( size >= 4 )
  {
    *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)*addr;
    v5 -= 4;
    v7 = (char *)*addr + 4;
    *addr = v7;
    size = v5;
    if ( v5 >= 4 )
    {
      LODWORD(v3->m_timeStamp) = *(_DWORD *)v7;
      v5 -= 4;
      *addr = (char *)*addr + 4;
      size = v5;
    }
  }
  v8 = LODWORD(v3->m_timeStamp);
  if ( v8 != 3 )
  {
    if ( v8 > 3 )
    {
      PopupError("Error: The data files have a more recent verion than the executable. You will need to update in order to run\n");
      return 0;
    }
    PopupError("Error: The executable has a more recent verion than the data files. You will need to update in order to run\n");
    return 0;
  }
  if ( !AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&v3->m_bLoaded + 1, addr, v5) )
    return 0;
  v10 = *(_DWORD *)(*((_DWORD *)&v3->m_bLoaded + 1) + 8) - 1;
  v11 = 0;
  if ( (unsigned int)v10 >= 0xFFFF )
    v11 = 4;
  v12 = v11 + v10 + 2;
  v13 = ((_BYTE)v11 + (_BYTE)v10 + 2) & 3;
  if ( v13 )
    v14 = 4 - v13;
  else
    v14 = 0;
  v15 = v12 + v14;
  v16 = size - v15;
  size -= v15;
  if ( size >= 4 )
  {
    v16 -= 4;
    v17 = (char *)*addr + 4;
    *addr = v17;
    size = v16;
    if ( v16 >= 4 )
    {
      v16 -= 4;
      v18 = v17 + 4;
      *addr = v18;
      size = v16;
      if ( v16 >= 4 )
      {
        v16 -= 4;
        v19 = (char *)v18 + 4;
        *addr = v19;
        size = v16;
        if ( v16 >= 4 )
        {
          v16 -= 4;
          v20 = (char *)v19 + 4;
          *addr = v20;
          size = v16;
          if ( v16 >= 4 )
          {
            v16 -= 4;
            v21 = (char *)v20 + 4;
            *addr = v21;
            size = v16;
            if ( v16 >= 4 )
            {
              v16 -= 4;
              v22 = (char *)v21 + 4;
              *addr = v22;
              size = v16;
              if ( v16 >= 4 )
              {
                v16 -= 4;
                v23 = (int)((char *)v22 + 4);
                *addr = (void *)v23;
                size = v16;
                if ( v16 >= 4 )
                {
                  v16 -= 4;
                  *addr = (void *)(v23 + 4);
                  size = v16;
                }
              }
            }
          }
        }
      }
    }
  }
  v24 = alloca(1024);
  v25 = 0;
  do
  {
    if ( v16 >= 4 )
    {
      *(&v66 + v25) = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v16 = size - 4;
      size -= 4;
    }
    ++v25;
  }
  while ( v25 < 0x100 );
  LandDefs::set_height_table((float *)&v66);
  v26 = (GameTime *)operator new(0x88u);
  if ( v26 )
  {
    GameTime::GameTime(v26);
    v28 = v27;
    if ( v27 )
    {
      if ( GameTime::UnPack(v27, addr, &size) )
      {
        if ( GameTime::current_game_time )
        {
          v29 = GameTime::current_game_time;
          GameTime::~GameTime(GameTime::current_game_time);
          operator delete(v29);
          v3 = v74;
        }
        GameTime::current_game_time = v28;
      }
    }
  }
  if ( size >= 4 )
  {
    v30 = size;
    v3->m_pNext = *(DBObj **)*addr;
    *addr = (char *)*addr + 4;
    size = v30 - 4;
  }
  if ( (unsigned int)v3->m_pNext & 0x10 )
  {
    v31 = (SkyDesc *)operator new(0x28u);
    if ( v31 )
      SkyDesc::SkyDesc(v31);
    else
      v32 = 0;
    v3->m_pMaintainer = (DBOCache *)v32;
    addr = (void **)SkyDesc::UnPack(v32, addr, &size);
  }
  if ( (unsigned int)v3->m_pNext & 1 && addr )
  {
    v33 = (TurbineChatBlob *)operator new(0xCu);
    if ( v33 )
      CSceneDesc::CSceneDesc(v33);
    else
      v34 = 0;
    v3->m_numLinks = (int)v34;
    addr = (void **)CSoundDesc::UnPack(v34, v6, &size);
  }
  if ( (unsigned int)v3->m_pNext & 2 )
  {
    if ( !addr )
      goto LABEL_109;
    v35 = (TurbineChatBlob *)operator new(0xCu);
    if ( v35 )
      CSceneDesc::CSceneDesc(v35);
    else
      v36 = 0;
    v3->m_DID.id = v36;
    if ( size < 4 )
    {
      v37 = num_stypes;
    }
    else
    {
      v37 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      num_stypes = v37;
      size -= 4;
    }
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v3->m_DID.id, v37);
    iq = 0;
    if ( v37 )
    {
      v38 = size;
      while ( 1 )
      {
        v39 = (CSceneType *)operator new(0x14u);
        if ( v39 )
        {
          CSceneType::CSceneType(v39);
          v41 = v40;
        }
        else
        {
          v41 = 0;
        }
        if ( size >= 4 )
        {
          v38 = *(_DWORD *)*v6;
          *v6 = (char *)*v6 + 4;
          size -= 4;
        }
        *(_DWORD *)(v41 + 16) = v38 == -1 ? 0 : *(_DWORD *)(*(_DWORD *)v74->m_numLinks + 4 * v38);
        if ( !CSceneType::unpack((CSceneType *)v41, v6, &size) )
          return 0;
        CSceneDesc::Add((CSceneDesc *)v74->m_DID.id, (CSceneType *)v41);
        ++iq;
        if ( iq >= num_stypes )
        {
          v3 = v74;
          break;
        }
      }
    }
  }
  if ( addr )
  {
    v42 = (CTerrainDesc *)operator new(0x10u);
    if ( v42 )
      Box2D::Box2D(v42);
    else
      v43 = 0;
    *(_DWORD *)&v3->m_AllowedInFreeList = v43;
    if ( size < 4 )
    {
      v44 = num_terrain;
    }
    else
    {
      v44 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      num_terrain = v44;
      size -= 4;
    }
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
      (AC1Legacy::SmartArray<Season *> *)(*(_DWORD *)&v3->m_AllowedInFreeList + 4),
      v44);
    iq = 0;
    if ( v44 )
    {
      while ( 1 )
      {
        v45 = (CTerrainType *)operator new(0x14u);
        if ( v45 )
        {
          CTerrainType::CTerrainType(v45);
          v47 = v46;
        }
        else
        {
          v47 = 0;
        }
        ttype = v47;
        if ( !AC1Legacy::PStringBase<char>::UnPack(&v47->terrain_name, v6, size) )
          return 0;
        v48 = v47->terrain_name.m_buffer->m_len - 1;
        v49 = 0;
        if ( (unsigned int)v48 >= 0xFFFF )
          v49 = 4;
        v50 = v49 + v48 + 2;
        v51 = ((_BYTE)v49 + (_BYTE)v48 + 2) & 3;
        if ( v51 )
          v52 = 4 - v51;
        else
          v52 = 0;
        size -= v50 + v52;
        if ( size >= 4 )
        {
          v47->terrain_color.color = *(_DWORD *)*v6;
          v53 = size - 4;
          v54 = (int)((char *)*v6 + 4);
          v55 = size - 4 < 4;
          *v6 = (void *)v54;
          size = v53;
          if ( !v55 )
          {
            v56 = *(_DWORD *)v54;
            *v6 = (void *)(v54 + 4);
            num_stypes = v56;
            size -= 4;
          }
        }
        v57 = (int)&v47->scene_types;
        AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v47->scene_types, num_stypes);
        if ( num_stypes )
        {
          v70 = num_stypes;
          do
          {
            if ( size >= 4 )
            {
              v58 = *(_DWORD *)*v6;
              *v6 = (char *)*v6 + 4;
              scene_index = v58;
              size -= 4;
            }
            if ( scene_index == -1 )
              v59 = 0;
            else
              v59 = *(_DWORD *)(*(_DWORD *)v74->m_DID.id + 4 * scene_index);
            v60 = *(_DWORD *)(v57 + 4);
            if ( *(_DWORD *)(v57 + 8) < v60
              || (!v60 ? (v61 = 8) : (v61 = 2 * v60),
                  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v57, v61)) )
              *(_DWORD *)(*(_DWORD *)v57 + 4 * (*(_DWORD *)(v57 + 8))++) = v59;
            --v70;
          }
          while ( v70 );
          v47 = ttype;
        }
        CTerrainDesc::Add(*(CTerrainDesc **)&v74->m_AllowedInFreeList, v47);
        ++iq;
        if ( iq >= num_terrain )
        {
          v3 = v74;
          break;
        }
      }
    }
    v62 = (LandSurf *)operator new(0x2Cu);
    if ( v62 )
      LandSurf::LandSurf(v62);
    else
      v63 = 0;
    **(_DWORD **)&v3->m_AllowedInFreeList = v63;
    if ( !LandSurf::UnPack(**(LandSurf ***)&v3->m_AllowedInFreeList, v6, &size) )
      return 0;
  }
LABEL_109:
  v64 = operator new(0x18u);
  if ( v64 )
  {
    *(_DWORD *)v64 = 0;
    *((_DWORD *)v64 + 1) = 100668029;
    *((_DWORD *)v64 + 2) = 100663905;
    *((_DWORD *)v64 + 3) = 4;
    *((_DWORD *)v64 + 4) = 0;
    *((_DWORD *)v64 + 5) = 0;
  }
  else
  {
    v64 = 0;
  }
  v65 = v3->m_pNext;
  v3->minimize_pal = (int)v64;
  if ( (unsigned __int16)v65 & 0x200 && addr )
  {
    RegionMisc::UnPack((RegionMisc *)v64, v6, &size);
    result = addr;
  }
  else
  {
    v67[18] |= 0x200u;
    result = addr;
  }
  return result;
}

//----- (004FF9E0) --------------------------------------------------------  // acclient.c:300216
CRegionDesc *__thiscall CRegionDesc::scalar_deleting_destructor(CRegionDesc *this, unsigned int a2)
{
  CRegionDesc *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CRegionDesc::vftable;
  this->vfptr = (PackObjVtbl *)&CRegionDesc::vftable;
  CRegionDesc::Destroy(this);
  v3 = v2->region_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5FE8: using guessed type void *CRegionDesc::vftable;
// 7C6000: using guessed type __int32 (__stdcall *CRegionDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006F9490) --------------------------------------------------------  // acclient.c:782021
void sub_6F9490()
{
  flt_84147C = 1000.0 + 1.0;
}

//----- (006F94B0) --------------------------------------------------------  // acclient.c:782027
void sub_6F94B0()
{
  flt_841480 = 24.0 * 8.0;
}

//----- (006F94D0) --------------------------------------------------------  // acclient.c:782033
void sub_6F94D0()
{
  flt_841484 = 24.0 * 0.5;
}

//----- (006F94F0) --------------------------------------------------------  // acclient.c:782039
int sub_6F94F0()
{
  return atexit(nullsub_1057);
}

//----- (006F9500) --------------------------------------------------------  // acclient.c:782045
int sub_6F9500()
{
  return atexit(nullsub_1058);
}

//----- (006F9510) --------------------------------------------------------  // acclient.c:782051
int sub_6F9510()
{
  return atexit(nullsub_1059);
}

//----- (006F9520) --------------------------------------------------------  // acclient.c:782057
int _E106_86()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_7, "Sound.SoundDisabled");
  return atexit(_E107_81);
}

//----- (006F9540) --------------------------------------------------------  // acclient.c:782064
int _E109_51()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_7, "Sound.SoundVolume");
  return atexit(sub_764EB0);
}

//----- (006F9560) --------------------------------------------------------  // acclient.c:782071
int _E112_78()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_7, "Sound.AmbientSoundDisabled");
  return atexit(_E113_56);
}

//----- (006F9580) --------------------------------------------------------  // acclient.c:782078
int _E115_57()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_7, "Sound.AmbientSoundVolume");
  return atexit(_E116_49);
}

//----- (006F95A0) --------------------------------------------------------  // acclient.c:782085
int _E118_58()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_7, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_78);
}

//----- (006F95C0) --------------------------------------------------------  // acclient.c:782092
int _E121_52()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_7, "Sound.InterfaceSoundVolume");
  return atexit(_E122_81);
}

//----- (006F95E0) --------------------------------------------------------  // acclient.c:782099
int _E124_54()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_7, "Sound.SoundFeatures");
  return atexit(_E125_53);
}

//----- (006F9600) --------------------------------------------------------  // acclient.c:782106
int _E127_43()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_7, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_52);
}

//----- (006F9620) --------------------------------------------------------  // acclient.c:782113
int _E130_41()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_7, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_8414B0, "Mono");
  return atexit(_E131_44);
}

//----- (006F9650) --------------------------------------------------------  // acclient.c:782121
void _E133_31()
{
  VOL_MIN_DIST_SQ_4 = 5.0 * 5.0;
}

//----- (006F9670) --------------------------------------------------------  // acclient.c:782127
void _E135_23()
{
  INV_LOG_OF_2_4 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006F9690) --------------------------------------------------------  // acclient.c:782133
int sub_6F9690()
{
  return atexit(nullsub_1056);
}

//----- (00764E80) --------------------------------------------------------  // acclient.c:891463
void __cdecl _E107_81()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764EB0) --------------------------------------------------------  // acclient.c:891476
void __cdecl sub_764EB0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764EE0) --------------------------------------------------------  // acclient.c:891489
void __cdecl _E113_56()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764F10) --------------------------------------------------------  // acclient.c:891502
void __cdecl _E116_49()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764F40) --------------------------------------------------------  // acclient.c:891515
void __cdecl _E119_78()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764F70) --------------------------------------------------------  // acclient.c:891528
void __cdecl _E122_81()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764FA0) --------------------------------------------------------  // acclient.c:891541
void __cdecl _E125_53()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764FD0) --------------------------------------------------------  // acclient.c:891554
void __cdecl _E128_52()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765000) --------------------------------------------------------  // acclient.c:891567
void __cdecl _E131_44()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_4;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

