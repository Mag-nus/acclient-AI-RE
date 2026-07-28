/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTexMerge
   Object     : PORTAL\cregion\CTexMerge.obj
   Functions  : 31
   Addresses  : 005033D0 - 006FA100 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005033D0) --------------------------------------------------------  // acclient.c:304557
void __stdcall TexMerge::CleanupSurface(CSurface *surf)
{
  if ( surf )
    CSurface::releaseCustomSurface(surf);
}

//----- (005033F0) --------------------------------------------------------  // acclient.c:304564
int __stdcall TexMerge::GetRoadCode(unsigned int pcode, int *road_fill, unsigned int *rcode)
{
  unsigned int v4; // eax@1
  unsigned int v5; // ecx@1
  int result; // eax@10

  v4 = pcode;
  v5 = 0;
  if ( pcode & 0xC000000 )
    v5 = 1;
  if ( pcode & 0x3000000 )
    v5 |= 2u;
  if ( v4 & 0xC00000 )
    v5 |= 4u;
  if ( v4 & 0x300000 )
    v5 |= 8u;
  *road_fill = 0;
  *rcode = 0;
  rcode[1] = 0;
  switch ( v5 )
  {
    case 0xFu:
      *road_fill = 1;
      result = 1;
      break;
    case 0xEu:
      *rcode = 6;
      rcode[1] = 12;
      result = 1;
      break;
    case 0xDu:
      *rcode = 9;
      rcode[1] = 12;
      result = 1;
      break;
    case 0xBu:
      *rcode = 9;
      rcode[1] = 3;
      result = 1;
      break;
    case 7u:
      *rcode = 3;
      rcode[1] = 6;
      result = 1;
      break;
    default:
      *rcode = v5;
      goto $L103784;
    case 0u:
$L103784:
      result = 1;
      break;
  }
  return result;
}

//----- (005034F0) --------------------------------------------------------  // acclient.c:304621
int __cdecl ImgTex::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0xBu);
  return DBObj::Get(v1);
}

//----- (00503510) --------------------------------------------------------  // acclient.c:304631
BOOL __thiscall TerrainTex::InitEnd(TerrainTex *this)
{
  TerrainTex *v1; // esi@1
  QualifiedDataID *v2; // eax@2
  QualifiedDataID v4; // [sp+4h] [bp-8h]@2

  v1 = this;
  if ( this->tex_gid.id != stru_841760.id )
  {
    QualifiedDataID::QualifiedDataID(&v4, this->tex_gid, 0xBu);
    v1->base_texture = (ImgTex *)DBObj::Get(v2);
  }
  return v1->base_texture != 0;
}

//----- (00503550) --------------------------------------------------------  // acclient.c:304647
void __thiscall TexMerge::TexMerge(TexMerge *this)
{
  this->base_tex_size = 16;
  this->corner_terrain_maps.m_data = 0;
  this->corner_terrain_maps.m_size = 0;
  this->corner_terrain_maps.m_num = 0;
  this->side_terrain_maps.m_data = 0;
  this->side_terrain_maps.m_size = 0;
  this->side_terrain_maps.m_num = 0;
  this->road_maps.m_data = 0;
  this->road_maps.m_size = 0;
  this->road_maps.m_num = 0;
  this->terrain_desc.m_data = 0;
  this->terrain_desc.m_size = 0;
  this->terrain_desc.m_num = 0;
}

//----- (00503580) --------------------------------------------------------  // acclient.c:304665
int __stdcall TexMerge::CopyAndTile(char *data, unsigned int tex_size, TerrainTex *terrain_tex)
{
  ImgTex *v4; // eax@1
  QualifiedDataID *v5; // eax@3
  int result; // eax@5
  QualifiedDataID v7; // [sp+4h] [bp-8h]@3

  v4 = terrain_tex->base_texture;
  if ( v4 )
    goto LABEL_9;
  if ( terrain_tex->tex_gid.id != stru_841760.id )
  {
    QualifiedDataID::QualifiedDataID(&v7, terrain_tex->tex_gid, 0xBu);
    terrain_tex->base_texture = (ImgTex *)DBObj::Get(v5);
  }
  v4 = terrain_tex->base_texture;
  if ( v4 )
  {
LABEL_9:
    ImgTex::CopyCSI(data, tex_size, tex_size, v4, terrain_tex->tex_tiling);
    result = 1;
  }
  else
  {
    ImgTex::CopyCSI(data, tex_size, tex_size, 0, 1u);
    result = 0;
  }
  return result;
}

//----- (00503600) --------------------------------------------------------  // acclient.c:304696
int __thiscall TexMerge::FindRoadAlpha(TexMerge *this, unsigned int rcode, RoadAlphaMap **alpha, LandDefs::Rotation *rot, unsigned int pcode)
{
  TexMerge *v5; // edi@1
  unsigned int v6; // ebp@1
  int v7; // ebx@1
  unsigned int v8; // eax@2
  LandDefs::Rotation v9; // ecx@2
  RoadAlphaMap *v11; // esi@9
  IDClass<_tagDataID,32,0> v12; // eax@10
  QualifiedDataID *v13; // eax@11
  QualifiedDataID v14; // [sp+18h] [bp-8h]@11
  unsigned int pcodea; // [sp+30h] [bp+10h]@1

  v5 = this;
  v6 = this->road_maps.m_num;
  pcodea = (unsigned __int64)_floor((double)(1379576222 * pcode - 1372186442) * 2.3283064e-10 * (double)v6);
  v7 = 0;
  if ( v5->road_maps.m_num )
  {
    while ( 2 )
    {
      *alpha = v5->road_maps.m_data[(v7 + pcodea) % v6];
      *rot = 0;
      v8 = (*alpha)->rcode;
      v9 = 0;
      do
      {
        if ( v8 == rcode )
        {
          *rot = v9;
          v11 = *alpha;
          if ( !(*alpha)->texture )
          {
            v12.id = v11->road_tex_gid.id;
            if ( v12.id != stru_841760.id )
            {
              QualifiedDataID::QualifiedDataID(&v14, v12, 0xBu);
              v11->texture = (ImgTex *)DBObj::Get(v13);
            }
          }
          return 1;
        }
        v8 *= 2;
        if ( v8 >= 0x10 )
          v8 -= 15;
        ++v9;
      }
      while ( (unsigned int)v9 < 4 );
      ++v7;
      if ( v7 < v5->road_maps.m_num )
        continue;
      break;
    }
  }
  *alpha = 0;
  return 0;
}

//----- (00503700) --------------------------------------------------------  // acclient.c:304755
int __thiscall TexMerge::FindTerrainAlpha(TexMerge *this, unsigned int tcode, TerrainAlphaMap **alpha, LandDefs::Rotation *rot, unsigned int pcode)
{
  unsigned int v5; // edi@1
  TexMerge *v6; // esi@1
  unsigned int v7; // ecx@5
  TerrainAlphaMap *v8; // eax@7
  TerrainAlphaMap **v9; // edx@7
  LandDefs::Rotation *v10; // esi@7
  unsigned int v11; // eax@7
  unsigned int v12; // ecx@7
  unsigned int v14; // ecx@13
  TerrainAlphaMap *v15; // eax@15
  unsigned int v16; // eax@15
  TerrainAlphaMap *v17; // esi@21
  IDClass<_tagDataID,32,0> v18; // eax@22
  QualifiedDataID *v19; // eax@23
  QualifiedDataID v20; // [sp+10h] [bp-8h]@23
  unsigned int tcodea; // [sp+1Ch] [bp+4h]@5
  unsigned int tcodeb; // [sp+1Ch] [bp+4h]@13

  v5 = tcode;
  v6 = this;
  if ( tcode != 1 && tcode != 2 && tcode != 4 && tcode != 8 )
  {
    *(float *)&tcodeb = (double)this->side_terrain_maps.m_num;
    v14 = (unsigned __int64)_floor((double)(1379576222 * pcode - 1372186442) * 2.3283064e-10 * *(float *)&tcodeb);
    if ( (double)v14 >= *(float *)&tcodeb )
      v14 = 0;
    v15 = v6->side_terrain_maps.m_data[v14];
    v9 = alpha;
    v10 = rot;
    *alpha = v15;
    *rot = 0;
    v16 = (*alpha)->tcode;
    v12 = 0;
    while ( v16 != v5 )
    {
      v16 *= 2;
      if ( v16 >= 0x10 )
        v16 -= 15;
      ++v12;
      if ( v12 >= 4 )
        return 0;
    }
  }
  else
  {
    *(float *)&tcodea = (double)this->corner_terrain_maps.m_num;
    v7 = (unsigned __int64)_floor((double)(1379576222 * pcode - 1372186442) * 2.3283064e-10 * *(float *)&tcodea);
    if ( (double)v7 >= *(float *)&tcodea )
      v7 = 0;
    v8 = v6->corner_terrain_maps.m_data[v7];
    v9 = alpha;
    v10 = rot;
    *alpha = v8;
    *rot = 0;
    v11 = (*alpha)->tcode;
    v12 = 0;
    while ( v11 != v5 )
    {
      v11 *= 2;
      if ( v11 >= 0x10 )
        v11 -= 15;
      ++v12;
      if ( v12 >= 4 )
        return 0;
    }
  }
  *v10 = v12;
  v17 = *v9;
  if ( !(*v9)->texture )
  {
    v18.id = v17->tex_gid.id;
    if ( v18.id != stru_841760.id )
    {
      QualifiedDataID::QualifiedDataID(&v20, v18, 0xBu);
      v17->texture = (ImgTex *)DBObj::Get(v19);
    }
  }
  return 1;
}

//----- (005038C0) --------------------------------------------------------  // acclient.c:304838
int __stdcall TexMerge::Merge(char *data, unsigned int tex_size, ImgTex *texture, LandDefs::Rotation rot, TerrainTex *terrain)
{
  int result; // eax@2
  ImgTex *v7; // eax@3

  if ( texture )
  {
    v7 = terrain->base_texture;
    if ( v7 )
    {
      ImgTex::MergeTexture(data, tex_size, tex_size, v7, terrain->tex_tiling, texture, rot);
      result = 1;
    }
    else if ( TerrainTex::InitEnd(terrain) )
    {
      ImgTex::MergeTexture(data, tex_size, tex_size, terrain->base_texture, terrain->tex_tiling, texture, rot);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00503940) --------------------------------------------------------  // acclient.c:304869
TerrainTex *__thiscall TexMerge::GetTerrainTex(TexMerge *this, unsigned int t1)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  bool v4; // zf@1
  TMTerrainDesc **v5; // edx@2
  TerrainTex *result; // eax@7

  v2 = this->terrain_desc.m_num;
  v3 = 0;
  v4 = v2 == 0;
  if ( v2 )
  {
    v5 = this->terrain_desc.m_data;
    while ( t1 != (*v5)->terrain_type )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
      {
        v4 = v2 == 0;
        goto LABEL_6;
      }
    }
    result = *this->terrain_desc.m_data[v3]->terrain_tex.m_data;
  }
  else
  {
LABEL_6:
    if ( v4 )
      result = 0;
    else
      result = *(*this->terrain_desc.m_data)->terrain_tex.m_data;
  }
  return result;
}

//----- (005039A0) --------------------------------------------------------  // acclient.c:304907
int __thiscall TexMerge::pack_size(TexMerge *this)
{
  unsigned int v1; // edx@1
  int v2; // eax@1
  unsigned int v3; // edx@3
  int v4; // eax@3
  unsigned int v5; // edx@5
  int v6; // eax@5
  unsigned int v7; // ecx@7
  int result; // eax@7

  v1 = this->corner_terrain_maps.m_num;
  v2 = 8;
  if ( v1 )
    v2 = 8 * v1 + 8;
  v3 = this->side_terrain_maps.m_num;
  v4 = v2 + 4;
  if ( v3 )
    v4 += 8 * v3;
  v5 = this->road_maps.m_num;
  v6 = v4 + 4;
  if ( v5 )
    v6 += 8 * v5;
  v7 = this->terrain_desc.m_num;
  result = v6 + 4;
  if ( v7 )
    result += 44 * v7;
  return result;
}

//----- (005039E0) --------------------------------------------------------  // acclient.c:304938
IDClass<_tagDataID,32,0> *__thiscall TexMerge::GetDetailTex(TexMerge *this, IDClass<_tagDataID,32,0> *result, unsigned int terrain_number)
{
  IDClass<_tagDataID,32,0> *v3; // eax@2

  if ( terrain_number >= this->terrain_desc.m_num )
  {
    v3 = result;
    result->id = stru_841760.id;
  }
  else
  {
    v3 = result;
    result->id = (*this->terrain_desc.m_data[terrain_number]->terrain_tex.m_data)->detail_tex_gid.id;
  }
  return v3;
}

//----- (00503A10) --------------------------------------------------------  // acclient.c:304956
unsigned int __thiscall TexMerge::GetDetailTiling(TexMerge *this, unsigned int terrain_number)
{
  unsigned int result; // eax@2

  if ( terrain_number >= this->terrain_desc.m_num )
    result = 0;
  else
    result = (*this->terrain_desc.m_data[terrain_number]->terrain_tex.m_data)->detail_tex_tiling;
  return result;
}

//----- (00503A30) --------------------------------------------------------  // acclient.c:304968
unsigned int __thiscall TerrainTex::Pack(TerrainTex *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int v4; // esi@3
  unsigned int v5; // esi@4
  unsigned int v6; // esi@5
  unsigned int v7; // esi@6
  unsigned int v8; // esi@7
  unsigned int v9; // esi@8
  unsigned int v10; // esi@9
  unsigned int v11; // esi@10

  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->tex_gid.id;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      *(_DWORD *)*addr = this->tex_tiling;
      *addr = (char *)*addr + 4;
      v4 = *size - 4;
      *size = v4;
      if ( v4 >= 4 )
      {
        *(_DWORD *)*addr = this->max_vert_bright;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          *(_DWORD *)*addr = this->min_vert_bright;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            *(_DWORD *)*addr = this->max_vert_saturate;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              *(_DWORD *)*addr = this->min_vert_saturate;
              *addr = (char *)*addr + 4;
              v8 = *size - 4;
              *size = v8;
              if ( v8 >= 4 )
              {
                *(_DWORD *)*addr = this->max_vert_hue;
                *addr = (char *)*addr + 4;
                v9 = *size - 4;
                *size = v9;
                if ( v9 >= 4 )
                {
                  *(_DWORD *)*addr = this->min_vert_hue;
                  *addr = (char *)*addr + 4;
                  v10 = *size - 4;
                  *size = v10;
                  if ( v10 >= 4 )
                  {
                    *(_DWORD *)*addr = this->detail_tex_tiling;
                    *addr = (char *)*addr + 4;
                    v11 = *size - 4;
                    *size = v11;
                    if ( v11 >= 4 )
                    {
                      *(_DWORD *)*addr = this->detail_tex_gid.id;
                      *addr = (char *)*addr + 4;
                      *size -= 4;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return *size;
}

//----- (00503B40) --------------------------------------------------------  // acclient.c:305053
int __thiscall TerrainTex::UnPack(TerrainTex *this, void **addr, unsigned int *size)
{
  unsigned int v3; // edi@2
  unsigned int v4; // esi@3
  unsigned int v5; // esi@4
  unsigned int v6; // esi@5
  unsigned int v7; // esi@6
  unsigned int v8; // esi@7
  unsigned int v9; // esi@8
  unsigned int v10; // esi@9
  unsigned int v11; // esi@10
  unsigned int v12; // edi@11

  if ( *size >= 4 )
  {
    v3 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
    this->tex_gid.id = v3;
    if ( *size >= 4 )
    {
      this->tex_tiling = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v4 = *size - 4;
      *size = v4;
      if ( v4 >= 4 )
      {
        this->max_vert_bright = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          this->min_vert_bright = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            this->max_vert_saturate = *(_DWORD *)*addr;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              this->min_vert_saturate = *(_DWORD *)*addr;
              *addr = (char *)*addr + 4;
              v8 = *size - 4;
              *size = v8;
              if ( v8 >= 4 )
              {
                this->max_vert_hue = *(_DWORD *)*addr;
                *addr = (char *)*addr + 4;
                v9 = *size - 4;
                *size = v9;
                if ( v9 >= 4 )
                {
                  this->min_vert_hue = *(_DWORD *)*addr;
                  *addr = (char *)*addr + 4;
                  v10 = *size - 4;
                  *size = v10;
                  if ( v10 >= 4 )
                  {
                    this->detail_tex_tiling = *(_DWORD *)*addr;
                    *addr = (char *)*addr + 4;
                    v11 = *size - 4;
                    *size = v11;
                    if ( v11 >= 4 )
                    {
                      v12 = *(_DWORD *)*addr;
                      *addr = (char *)*addr + 4;
                      *size -= 4;
                      this->detail_tex_gid.id = v12;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

//----- (00503C50) --------------------------------------------------------  // acclient.c:305140
void __thiscall TMTerrainDesc::~TMTerrainDesc(TMTerrainDesc *this)
{
  TMTerrainDesc *v1; // edi@1
  unsigned int v2; // ebx@1
  TerrainTex *v3; // esi@2
  ImgTex *v4; // ecx@3
  void *v5; // ST04_4@7

  v1 = this;
  v2 = 0;
  if ( this->terrain_tex.m_num )
  {
    do
    {
      v3 = v1->terrain_tex.m_data[v2];
      if ( v3 )
      {
        v4 = v3->base_texture;
        if ( v4 )
        {
          ((void (*)(void))v4->vfptr->Release)();
          v3->base_texture = 0;
        }
        operator delete(v3);
      }
      ++v2;
    }
    while ( v2 < v1->terrain_tex.m_num );
  }
  v5 = v1->terrain_tex.m_data;
  v1->terrain_tex.m_num = 0;
  v1->terrain_tex.m_size = 0;
  operator delete[](v5);
  v1->terrain_tex.m_data = 0;
  operator delete[](0);
}

//----- (00503CB0) --------------------------------------------------------  // acclient.c:305178
void __thiscall TexMerge::GetSubDataIDs(TexMerge *this, QualifiedDataIDArray *id_array)
{
  TexMerge *v2; // esi@1
  unsigned int v3; // ebx@1
  QualifiedDataID *v4; // eax@2
  unsigned int v5; // ebx@3
  QualifiedDataID *v6; // eax@4
  unsigned int v7; // ebx@5
  QualifiedDataID *v8; // eax@6
  unsigned int v9; // ebx@7
  QualifiedDataID *v10; // eax@8
  QualifiedDataID *v11; // eax@8
  TerrainTex *tex; // [sp+10h] [bp-18h]@2
  QualifiedDataID v13; // [sp+18h] [bp-10h]@8
  QualifiedDataID v14; // [sp+20h] [bp-8h]@8

  v2 = this;
  v3 = 0;
  if ( this->corner_terrain_maps.m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&tex, v2->corner_terrain_maps.m_data[v3]->tex_gid, 0);
      QualifiedDataIDArray::AddQDID(id_array, v4, 8u);
      ++v3;
    }
    while ( v3 < v2->corner_terrain_maps.m_num );
  }
  v5 = 0;
  if ( v2->side_terrain_maps.m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&tex, v2->side_terrain_maps.m_data[v5]->tex_gid, 0);
      QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
      ++v5;
    }
    while ( v5 < v2->side_terrain_maps.m_num );
  }
  v7 = 0;
  if ( v2->road_maps.m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&tex, v2->road_maps.m_data[v7]->road_tex_gid, 0);
      QualifiedDataIDArray::AddQDID(id_array, v8, 8u);
      ++v7;
    }
    while ( v7 < v2->road_maps.m_num );
  }
  v9 = 0;
  if ( v2->terrain_desc.m_num )
  {
    do
    {
      tex = *v2->terrain_desc.m_data[v9]->terrain_tex.m_data;
      QualifiedDataID::QualifiedDataID(&v13, tex->tex_gid, 0);
      QualifiedDataIDArray::AddQDID(id_array, v10, 8u);
      QualifiedDataID::QualifiedDataID(&v14, tex->detail_tex_gid, 0);
      QualifiedDataIDArray::AddQDID(id_array, v11, 8u);
      ++v9;
    }
    while ( v9 < v2->terrain_desc.m_num );
  }
}

//----- (00503DC0) --------------------------------------------------------  // acclient.c:305245
int __thiscall TexMerge::GetTerrain(TexMerge *this, unsigned int pcode, TerrainTex **terrain_tex, unsigned int *tcode)
{
  TexMerge *v4; // ebx@1
  unsigned int v5; // ebp@1
  unsigned int v6; // eax@1
  int v7; // edx@2
  int v8; // ecx@2
  unsigned int v9; // edx@6
  unsigned int v10; // eax@6
  bool v11; // zf@6
  TMTerrainDesc **v12; // ecx@7
  TerrainTex *v13; // eax@12
  unsigned int v14; // edi@13
  unsigned int v15; // ecx@13
  unsigned int v16; // eax@13
  bool v17; // zf@13
  TMTerrainDesc **v18; // edx@14
  TerrainTex *v19; // eax@19
  TMTerrainDesc *v20; // eax@20
  unsigned int *v21; // edi@23
  TerrainTex **v22; // ebp@23
  unsigned int v23; // ecx@23
  unsigned int v24; // eax@26
  unsigned int v25; // edx@26
  bool v26; // zf@26
  TMTerrainDesc **v27; // esi@27
  TerrainTex *v28; // eax@32
  unsigned int v30; // eax@40
  bool v31; // zf@40
  unsigned int v32; // esi@42
  unsigned int v33; // eax@42
  bool v34; // zf@42
  TMTerrainDesc **v35; // edx@43
  TerrainTex *v36; // eax@48
  TMTerrainDesc *v37; // ecx@57
  unsigned int v38; // ecx@60
  unsigned int v39; // eax@60
  bool v40; // zf@60
  TMTerrainDesc **v41; // edx@61
  TerrainTex *v42; // eax@66
  TMTerrainDesc *v43; // edx@67
  unsigned int v44; // ecx@70
  unsigned int v45; // eax@70
  bool v46; // zf@70
  TMTerrainDesc **v47; // edx@71
  TerrainTex *v48; // eax@76
  TMTerrainDesc *v49; // edx@77
  unsigned int v50; // ecx@80
  unsigned int v51; // eax@80
  bool v52; // zf@80
  TMTerrainDesc **v53; // edx@81
  TerrainTex *v54; // eax@86
  TMTerrainDesc *v55; // edx@87
  TexMerge *v56; // [sp+10h] [bp-14h]@1
  unsigned int type[4]; // [sp+14h] [bp-10h]@1
  unsigned int pcodea; // [sp+28h] [bp+4h]@13

  v4 = this;
  v5 = (pcode >> 10) & 0x1F;
  type[3] = pcode & 0x1F;
  v56 = this;
  type[0] = (pcode >> 15) & 0x1F;
  type[1] = (pcode >> 10) & 0x1F;
  type[2] = (pcode >> 5) & 0x1F;
  v6 = 0;
  while ( 1 )
  {
    v7 = v6 + 1;
    v8 = v6 + 1;
    if ( v6 < 3 )
      break;
LABEL_5:
    ++v6;
    if ( (unsigned int)v7 >= 4 )
    {
      v9 = v4->terrain_desc.m_num;
      v10 = 0;
      v11 = v9 == 0;
      if ( v9 )
      {
        v12 = v4->terrain_desc.m_data;
        while ( ((pcode >> 15) & 0x1F) != (*v12)->terrain_type )
        {
          ++v10;
          ++v12;
          if ( v10 >= v9 )
          {
            v5 = type[1];
            v11 = v9 == 0;
            goto LABEL_11;
          }
        }
        v37 = v4->terrain_desc.m_data[v10];
        v5 = type[1];
LABEL_59:
        v13 = *v37->terrain_tex.m_data;
      }
      else
      {
LABEL_11:
        if ( !v11 )
        {
          v37 = *v4->terrain_desc.m_data;
          goto LABEL_59;
        }
        v13 = 0;
      }
      *terrain_tex = v13;
      v38 = v4->terrain_desc.m_num;
      v39 = 0;
      v40 = v38 == 0;
      if ( v38 )
      {
        v41 = v4->terrain_desc.m_data;
        while ( v5 != (*v41)->terrain_type )
        {
          ++v39;
          ++v41;
          if ( v39 >= v38 )
          {
            v40 = v38 == 0;
            goto LABEL_65;
          }
        }
        v43 = v4->terrain_desc.m_data[v39];
LABEL_69:
        v42 = *v43->terrain_tex.m_data;
      }
      else
      {
LABEL_65:
        if ( !v40 )
        {
          v43 = *v4->terrain_desc.m_data;
          goto LABEL_69;
        }
        v42 = 0;
      }
      terrain_tex[1] = v42;
      v44 = v4->terrain_desc.m_num;
      v45 = 0;
      v46 = v44 == 0;
      if ( v44 )
      {
        v47 = v4->terrain_desc.m_data;
        while ( type[2] != (*v47)->terrain_type )
        {
          ++v45;
          ++v47;
          if ( v45 >= v44 )
          {
            v46 = v44 == 0;
            goto LABEL_75;
          }
        }
        v49 = v4->terrain_desc.m_data[v45];
LABEL_79:
        v48 = *v49->terrain_tex.m_data;
      }
      else
      {
LABEL_75:
        if ( !v46 )
        {
          v49 = *v4->terrain_desc.m_data;
          goto LABEL_79;
        }
        v48 = 0;
      }
      terrain_tex[2] = v48;
      v50 = v4->terrain_desc.m_num;
      v51 = 0;
      v52 = v50 == 0;
      if ( v50 )
      {
        v53 = v4->terrain_desc.m_data;
        while ( type[3] != (*v53)->terrain_type )
        {
          ++v51;
          ++v53;
          if ( v51 >= v50 )
          {
            v52 = v50 == 0;
            goto LABEL_85;
          }
        }
        v55 = v4->terrain_desc.m_data[v51];
LABEL_89:
        v54 = *v55->terrain_tex.m_data;
      }
      else
      {
LABEL_85:
        if ( !v52 )
        {
          v55 = *v4->terrain_desc.m_data;
          goto LABEL_89;
        }
        v54 = 0;
      }
      terrain_tex[3] = v54;
      *tcode = 2;
      tcode[1] = 4;
      tcode[2] = 8;
      return 1;
    }
  }
  while ( type[v6] != type[v8] )
  {
    ++v8;
    if ( (unsigned int)v8 >= 4 )
      goto LABEL_5;
  }
  v14 = type[v6];
  v15 = v4->terrain_desc.m_num;
  v16 = 0;
  v17 = v15 == 0;
  pcodea = v14;
  if ( v15 )
  {
    v18 = v4->terrain_desc.m_data;
    while ( v14 != (*v18)->terrain_type )
    {
      ++v16;
      ++v18;
      if ( v16 >= v15 )
      {
        v17 = v15 == 0;
        goto LABEL_18;
      }
    }
    v20 = v4->terrain_desc.m_data[v16];
    goto LABEL_22;
  }
LABEL_18:
  if ( !v17 )
  {
    v20 = *v4->terrain_desc.m_data;
LABEL_22:
    v19 = *v20->terrain_tex.m_data;
    goto LABEL_23;
  }
  v19 = 0;
LABEL_23:
  v21 = tcode;
  v22 = terrain_tex;
  v23 = 0;
  *terrain_tex = v19;
  *tcode = 0;
  tcode[1] = 0;
  tcode[2] = 0;
  while ( type[v23] == pcodea )
  {
LABEL_36:
    ++v23;
    if ( v23 >= 4 )
      return 1;
  }
  if ( !*v21 )
  {
    v22 = (TerrainTex **)type[v23];
    v24 = 0;
    *v21 = 1 << v23;
    v25 = v4->terrain_desc.m_num;
    v26 = v25 == 0;
    if ( v25 )
    {
      v27 = v4->terrain_desc.m_data;
      while ( v22 != (TerrainTex **)(*v27)->terrain_type )
      {
        ++v24;
        ++v27;
        if ( v24 >= v25 )
        {
          v4 = v56;
          v21 = tcode;
          v26 = v25 == 0;
          goto LABEL_31;
        }
      }
      v28 = *v4->terrain_desc.m_data[v24]->terrain_tex.m_data;
      v4 = v56;
      v21 = tcode;
    }
    else
    {
LABEL_31:
      if ( v26 )
        v28 = 0;
      else
        v28 = *(*v4->terrain_desc.m_data)->terrain_tex.m_data;
    }
    terrain_tex[1] = v28;
    goto LABEL_36;
  }
  if ( (TerrainTex **)type[v23] != v22 )
    goto LABEL_42;
  if ( v23 == 1 )
  {
    v30 = *v21;
    v31 = *v21 == 1;
    goto LABEL_41;
  }
  if ( v23 != 2 )
  {
    if ( v23 != 3 )
      goto LABEL_42;
    v30 = *v21;
    if ( *v21 != 4 )
      goto LABEL_42;
    goto LABEL_53;
  }
  v30 = *v21;
  v31 = *v21 == 2;
LABEL_41:
  if ( v31 )
  {
LABEL_53:
    *v21 = v30 + (1 << v23);
    return 1;
  }
LABEL_42:
  v32 = v4->terrain_desc.m_num;
  v33 = 0;
  v34 = v32 == 0;
  if ( v32 )
  {
    v35 = v4->terrain_desc.m_data;
    while ( type[v23] != (*v35)->terrain_type )
    {
      ++v33;
      ++v35;
      if ( v33 >= v32 )
      {
        v4 = v56;
        v34 = v32 == 0;
        goto LABEL_47;
      }
    }
    v36 = *v4->terrain_desc.m_data[v33]->terrain_tex.m_data;
  }
  else
  {
LABEL_47:
    if ( v34 )
      v36 = 0;
    else
      v36 = *(*v4->terrain_desc.m_data)->terrain_tex.m_data;
  }
  terrain_tex[2] = v36;
  v21[1] = 1 << v23;
  return 1;
}

//----- (005040E0) --------------------------------------------------------  // acclient.c:305600
unsigned int __thiscall TexMerge::Pack(TexMerge *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  unsigned int v4; // eax@3
  unsigned int v5; // edx@5
  TerrainAlphaMap *v6; // eax@6
  int v7; // ebx@7
  unsigned int v8; // eax@10
  unsigned int v9; // edx@12
  TerrainAlphaMap *v10; // eax@13
  int v11; // ebx@14
  unsigned int v12; // eax@17
  unsigned int v13; // edx@19
  RoadAlphaMap *v14; // eax@20
  int v15; // ebx@21
  unsigned int v16; // ebp@24
  unsigned int v17; // ebx@26
  TMTerrainDesc *v18; // eax@29
  TexMerge *v20; // [sp+10h] [bp-4h]@1
  unsigned int sizea; // [sp+1Ch] [bp+8h]@3
  unsigned int sizeb; // [sp+1Ch] [bp+8h]@10
  unsigned int sizec; // [sp+1Ch] [bp+8h]@17

  v3 = size;
  v20 = this;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->base_tex_size;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v4 = this->corner_terrain_maps.m_num;
  sizea = this->corner_terrain_maps.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v4;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v5 = 0;
  if ( v4 )
  {
    do
    {
      v6 = this->corner_terrain_maps.m_data[v5];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v6->tcode;
        *addr = (char *)*addr + 4;
        v7 = *v3 - 4;
        *v3 = v7;
        if ( (unsigned int)v7 >= 4 )
        {
          *(_DWORD *)*addr = v6->tex_gid.id;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      ++v5;
    }
    while ( v5 < sizea );
  }
  v8 = this->side_terrain_maps.m_num;
  sizeb = this->side_terrain_maps.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v8;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v9 = 0;
  if ( v8 )
  {
    do
    {
      v10 = this->side_terrain_maps.m_data[v9];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v10->tcode;
        *addr = (char *)*addr + 4;
        v11 = *v3 - 4;
        *v3 = v11;
        if ( (unsigned int)v11 >= 4 )
        {
          *(_DWORD *)*addr = v10->tex_gid.id;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      ++v9;
    }
    while ( v9 < sizeb );
  }
  v12 = this->road_maps.m_num;
  sizec = this->road_maps.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v12;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v13 = 0;
  if ( v12 )
  {
    do
    {
      v14 = this->road_maps.m_data[v13];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v14->rcode;
        *addr = (char *)*addr + 4;
        v15 = *v3 - 4;
        *v3 = v15;
        if ( (unsigned int)v15 >= 4 )
        {
          *(_DWORD *)*addr = v14->road_tex_gid.id;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      ++v13;
    }
    while ( v13 < sizec );
  }
  v16 = this->terrain_desc.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v16;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v17 = 0;
  if ( v16 )
  {
    while ( 1 )
    {
      v18 = this->terrain_desc.m_data[v17];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v18->terrain_type;
        *addr = (char *)*addr + 4;
        *v3 -= 4;
      }
      TerrainTex::Pack(*v18->terrain_tex.m_data, addr, v3);
      ++v17;
      if ( v17 >= v16 )
        break;
      this = v20;
    }
  }
  return *v3;
}

//----- (00504260) --------------------------------------------------------  // acclient.c:305754
int __thiscall TMTerrainDesc::UnPack(TMTerrainDesc *this, void **addr, unsigned int *size)
{
  LandDefs::TerrainType v3; // edx@2
  void *v4; // eax@4
  TerrainTex *v5; // ebx@5
  unsigned int v6; // eax@7
  unsigned int v7; // eax@9
  TMTerrainDesc *v9; // [sp+10h] [bp-4h]@1

  v9 = this;
  if ( *size < 4 )
  {
    v3 = (LandDefs::TerrainType)size;
  }
  else
  {
    v3 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  this->terrain_type = v3;
  v4 = operator new(0x30u);
  if ( v4 )
  {
    *(_DWORD *)v4 = stru_841760.id;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 8) = 0;
    *((_DWORD *)v4 + 9) = 0;
    *((_DWORD *)v4 + 10) = 0;
    *((_DWORD *)v4 + 11) = stru_841760.id;
    v5 = (TerrainTex *)v4;
  }
  else
  {
    v5 = 0;
  }
  TerrainTex::UnPack(v5, addr, size);
  v6 = v9->terrain_tex.m_size;
  if ( v9->terrain_tex.m_num < v6
    || (v6 <= 0 ? (v7 = 8) : (v7 = 2 * v6),
        AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v9->terrain_tex, v7)) )
    v9->terrain_tex.m_data[v9->terrain_tex.m_num++] = v5;
  return 1;
}

//----- (00504320) --------------------------------------------------------  // acclient.c:305806
void __thiscall TexMerge::Destroy(TexMerge *this)
{
  TexMerge *v1; // esi@1
  unsigned int v2; // ebx@1
  TerrainAlphaMap *v3; // edi@2
  ImgTex *v4; // ecx@3
  void *v5; // ST00_4@7
  unsigned int i; // ebx@7
  TerrainAlphaMap *v7; // edi@8
  ImgTex *v8; // ecx@9
  void *v9; // ST00_4@13
  unsigned int j; // ebx@13
  RoadAlphaMap *v11; // edi@14
  ImgTex *v12; // ecx@15
  void *v13; // ST00_4@19
  unsigned int k; // ebx@19
  TMTerrainDesc **v15; // ecx@20
  void *v16; // edi@20
  void *v17; // ST00_4@23

  v1 = this;
  v2 = 0;
  if ( this->corner_terrain_maps.m_num )
  {
    do
    {
      v3 = v1->corner_terrain_maps.m_data[v2];
      if ( v3 )
      {
        v4 = v3->texture;
        if ( v4 )
        {
          ((void (*)(void))v4->vfptr->Release)();
          v3->texture = 0;
        }
        operator delete(v3);
      }
      ++v2;
    }
    while ( v2 < v1->corner_terrain_maps.m_num );
  }
  v5 = v1->corner_terrain_maps.m_data;
  v1->corner_terrain_maps.m_num = 0;
  v1->corner_terrain_maps.m_size = 0;
  operator delete[](v5);
  v1->corner_terrain_maps.m_data = 0;
  for ( i = 0; i < v1->side_terrain_maps.m_num; ++i )
  {
    v7 = v1->side_terrain_maps.m_data[i];
    if ( v7 )
    {
      v8 = v7->texture;
      if ( v8 )
      {
        ((void (*)(void))v8->vfptr->Release)();
        v7->texture = 0;
      }
      operator delete(v7);
    }
  }
  v9 = v1->side_terrain_maps.m_data;
  v1->side_terrain_maps.m_num = 0;
  v1->side_terrain_maps.m_size = 0;
  operator delete[](v9);
  v1->side_terrain_maps.m_data = 0;
  for ( j = 0; j < v1->road_maps.m_num; ++j )
  {
    v11 = v1->road_maps.m_data[j];
    if ( v11 )
    {
      v12 = v11->texture;
      if ( v12 )
      {
        ((void (*)(void))v12->vfptr->Release)();
        v11->texture = 0;
      }
      operator delete(v11);
    }
  }
  v13 = v1->road_maps.m_data;
  v1->road_maps.m_num = 0;
  v1->road_maps.m_size = 0;
  operator delete[](v13);
  v1->road_maps.m_data = 0;
  for ( k = 0; k < v1->terrain_desc.m_num; ++k )
  {
    v15 = v1->terrain_desc.m_data;
    v16 = v15[k];
    if ( v16 )
    {
      TMTerrainDesc::~TMTerrainDesc(v15[k]);
      operator delete(v16);
    }
  }
  v17 = v1->terrain_desc.m_data;
  v1->terrain_desc.m_num = 0;
  v1->terrain_desc.m_size = 0;
  operator delete[](v17);
  v1->terrain_desc.m_data = 0;
}

//----- (00504450) --------------------------------------------------------  // acclient.c:305908
int __thiscall TexMerge::FillTempTexBuffer(TexMerge *this, unsigned int pcode, unsigned int tex_size)
{
  TexMerge *v3; // esi@1
  int result; // eax@1
  char *v5; // edi@2
  TerrainTex *v6; // ebx@5
  TerrainAlphaMap *v7; // ebp@5
  unsigned int v8; // ebx@9
  unsigned int v9; // edi@11
  unsigned int v10; // eax@12
  TerrainTex *v11; // ebp@15
  unsigned int v12; // edi@16
  unsigned int v13; // eax@17
  TerrainTex *v14; // [sp-Ch] [bp-40h]@7
  TerrainAlphaMap *alpha; // [sp+8h] [bp-2Ch]@5
  TerrainTex *road_tex; // [sp+Ch] [bp-28h]@5
  unsigned int rcode[2]; // [sp+10h] [bp-24h]@5
  unsigned int tcode[3]; // [sp+18h] [bp-1Ch]@1
  TerrainTex *terrain_tex[4]; // [sp+24h] [bp-10h]@1

  v3 = this;
  result = TexMerge::GetTerrain(this, pcode, terrain_tex, tcode);
  if ( result )
  {
    v5 = TexMerge::tex_data;
    if ( (TexMerge::tex_data
       || (v5 = (char *)operator new[](4 * v3->base_tex_size * v3->base_tex_size), (TexMerge::tex_data = v5) != 0))
      && ((v6 = TexMerge::GetTerrainTex(v3, 0x20u),
           road_tex = v6,
           TexMerge::GetRoadCode(pcode, (int *)&alpha, rcode),
           (v7 = alpha) == 0)
       || !v6 ? (v14 = terrain_tex[0]) : (v14 = v6),
          v8 = tex_size,
          TexMerge::CopyAndTile(v5, tex_size, v14)) )
    {
      if ( !v7 )
      {
        v9 = 0;
        do
        {
          v10 = tcode[v9];
          if ( !v10 )
            break;
          if ( !TexMerge::FindTerrainAlpha(v3, v10, &alpha, (LandDefs::Rotation *)&tex_size, pcode) )
            goto LABEL_4;
          TexMerge::Merge(TexMerge::tex_data, v8, alpha->texture, (LandDefs::Rotation)tex_size, terrain_tex[v9 + 1]);
          ++v9;
        }
        while ( v9 < 3 );
        v11 = road_tex;
        if ( road_tex )
        {
          v12 = 0;
          do
          {
            v13 = rcode[v12];
            if ( !v13 )
              break;
            if ( TexMerge::FindRoadAlpha(v3, v13, (RoadAlphaMap **)&road_tex, (LandDefs::Rotation *)&tex_size, pcode) )
              TexMerge::Merge(TexMerge::tex_data, v8, LODWORD(road_tex->min_slope), (LandDefs::Rotation)tex_size, v11);
            ++v12;
          }
          while ( v12 < 2 );
        }
      }
      result = 1;
    }
    else
    {
LABEL_4:
      result = 0;
    }
  }
  return result;
}

//----- (005045B0) --------------------------------------------------------  // acclient.c:305985
int __thiscall TexMerge::UnPack(TexMerge *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  void **v4; // edi@1
  unsigned int v5; // eax@2
  unsigned int *v6; // ebx@3
  char *v7; // ebp@5
  void *v8; // eax@7
  void *v9; // ebx@7
  unsigned int v10; // ecx@8
  int v11; // eax@10
  int v12; // ecx@11
  unsigned int v13; // eax@12
  unsigned int v14; // eax@14
  unsigned int *v15; // ecx@21
  void *v16; // eax@24
  void *v17; // ebx@24
  unsigned int v18; // edx@25
  int v19; // eax@27
  int v20; // ecx@28
  unsigned int v21; // eax@29
  unsigned int v22; // eax@31
  unsigned int *v23; // ecx@38
  void *v24; // eax@41
  void *v25; // ebx@41
  unsigned int v26; // edx@42
  int v27; // eax@44
  int v28; // ecx@45
  unsigned int v29; // eax@46
  unsigned int v30; // eax@48
  unsigned int *v31; // ecx@54
  TMTerrainDesc *v32; // ebp@55
  int result; // eax@56
  void *v34; // eax@58
  unsigned int v35; // eax@61
  unsigned int v36; // eax@63
  TexMerge *v37; // [sp+10h] [bp-4h]@1
  void **addra; // [sp+18h] [bp+4h]@6
  void **addrb; // [sp+18h] [bp+4h]@23
  void **addrc; // [sp+18h] [bp+4h]@40
  void **addrd; // [sp+18h] [bp+4h]@55

  v3 = size;
  v4 = addr;
  v37 = this;
  if ( *size < 4
    || (this->base_tex_size = *(_DWORD *)*addr, *addr = (char *)*addr + 4, v5 = *size - 4, *size = v5, v5 < 4) )
  {
    v6 = size;
  }
  else
  {
    v6 = *(unsigned int **)*addr;
    *addr = (char *)*addr + 4;
    size = v6;
    *v3 -= 4;
  }
  v7 = (char *)&this->corner_terrain_maps;
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
    (AC1Legacy::SmartArray<Season *> *)&this->corner_terrain_maps,
    (unsigned int)v6);
  if ( v6 )
  {
    addra = (void **)v6;
    do
    {
      v8 = operator new(0xCu);
      v9 = 0;
      if ( v8 )
      {
        *(_DWORD *)v8 = 0;
        v10 = stru_841760.id;
        *((_DWORD *)v8 + 2) = 0;
        *((_DWORD *)v8 + 1) = v10;
        v9 = v8;
      }
      if ( *v3 >= 4 )
      {
        *(_DWORD *)v9 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        v11 = *v3 - 4;
        *v3 = v11;
        if ( (unsigned int)v11 >= 4 )
        {
          v12 = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          *v3 -= 4;
          *((_DWORD *)v9 + 1) = v12;
        }
      }
      v13 = *((_DWORD *)v7 + 1);
      if ( *((_DWORD *)v7 + 2) < v13
        || (!v13 ? (v14 = 8) : (v14 = 2 * v13),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v7, v14)) )
        *(_DWORD *)(*(_DWORD *)v7 + 4 * (*((_DWORD *)v7 + 2))++) = v9;
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
    v6 = size;
  }
  if ( *v3 >= 4 )
  {
    v15 = *(unsigned int **)*v4;
    *v4 = (char *)*v4 + 4;
    size = v15;
    *v3 -= 4;
    v6 = v15;
  }
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
    (AC1Legacy::SmartArray<Season *> *)&v37->side_terrain_maps,
    (unsigned int)v6);
  if ( v6 )
  {
    addrb = (void **)v6;
    do
    {
      v16 = operator new(0xCu);
      v17 = 0;
      if ( v16 )
      {
        *(_DWORD *)v16 = 0;
        v18 = stru_841760.id;
        *((_DWORD *)v16 + 2) = 0;
        *((_DWORD *)v16 + 1) = v18;
        v17 = v16;
      }
      if ( *v3 >= 4 )
      {
        *(_DWORD *)v17 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        v19 = *v3 - 4;
        *v3 = v19;
        if ( (unsigned int)v19 >= 4 )
        {
          v20 = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          *v3 -= 4;
          *((_DWORD *)v17 + 1) = v20;
        }
      }
      v21 = v37->side_terrain_maps.m_size;
      if ( v37->side_terrain_maps.m_num < v21
        || (!v21 ? (v22 = 8) : (v22 = 2 * v21),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v37->side_terrain_maps, v22)) )
        v37->side_terrain_maps.m_data[v37->side_terrain_maps.m_num++] = (TerrainAlphaMap *)v17;
      addrb = (void **)((char *)addrb - 1);
    }
    while ( addrb );
    v6 = size;
  }
  if ( *v3 >= 4 )
  {
    v23 = *(unsigned int **)*v4;
    *v4 = (char *)*v4 + 4;
    size = v23;
    *v3 -= 4;
    v6 = v23;
  }
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v37->road_maps, (unsigned int)v6);
  if ( v6 )
  {
    addrc = (void **)v6;
    do
    {
      v24 = operator new(0xCu);
      v25 = 0;
      if ( v24 )
      {
        *(_DWORD *)v24 = 0;
        v26 = stru_841760.id;
        *((_DWORD *)v24 + 2) = 0;
        *((_DWORD *)v24 + 1) = v26;
        v25 = v24;
      }
      if ( *v3 >= 4 )
      {
        *(_DWORD *)v25 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        v27 = *v3 - 4;
        *v3 = v27;
        if ( (unsigned int)v27 >= 4 )
        {
          v28 = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          *v3 -= 4;
          *((_DWORD *)v25 + 1) = v28;
        }
      }
      v29 = v37->road_maps.m_size;
      if ( v37->road_maps.m_num < v29
        || (!v29 ? (v30 = 8) : (v30 = 2 * v29),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v37->road_maps, v30)) )
        v37->road_maps.m_data[v37->road_maps.m_num++] = (RoadAlphaMap *)v25;
      addrc = (void **)((char *)addrc - 1);
    }
    while ( addrc );
  }
  if ( *v3 >= 4 )
  {
    v31 = *(unsigned int **)*v4;
    *v4 = (char *)*v4 + 4;
    size = v31;
    *v3 -= 4;
  }
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v37->terrain_desc, (unsigned int)size);
  v32 = 0;
  addrd = 0;
  if ( size )
  {
    while ( 1 )
    {
      v34 = operator new(0x10u);
      if ( v34 )
      {
        *(_DWORD *)v34 = 31;
        *((_DWORD *)v34 + 1) = 0;
        *((_DWORD *)v34 + 2) = 0;
        *((_DWORD *)v34 + 3) = 0;
        v32 = (TMTerrainDesc *)v34;
      }
      if ( !TMTerrainDesc::UnPack(v32, v4, v3) )
        break;
      v35 = v37->terrain_desc.m_size;
      if ( v37->terrain_desc.m_num < v35
        || (!v35 ? (v36 = 8) : (v36 = 2 * v35),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v37->terrain_desc, v36)) )
        v37->terrain_desc.m_data[v37->terrain_desc.m_num++] = v32;
      addrd = (void **)((char *)addrd + 1);
      if ( (unsigned int)addrd >= (unsigned int)size )
        return 1;
      v32 = 0;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005048D0) --------------------------------------------------------  // acclient.c:306227
void __thiscall TexMerge::~TexMerge(TexMerge *this)
{
  TexMerge *v1; // esi@1

  v1 = this;
  TexMerge::Destroy(this);
  operator delete[](v1->terrain_desc.m_data);
  operator delete[](v1->road_maps.m_data);
  operator delete[](v1->side_terrain_maps.m_data);
  operator delete[](v1->corner_terrain_maps.m_data);
}

//----- (00504910) --------------------------------------------------------  // acclient.c:306240
char __cdecl TexMerge::RestoreSurface(CSurface *surface)
{
  TexMerge *v1; // edi@1
  unsigned int v2; // ebx@1
  unsigned __int32 v3; // esi@1
  ImgTex *v4; // ecx@3
  ImgTex *v5; // eax@4
  ImgTex *v6; // esi@4

  v1 = *(TexMerge **)(CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info) + 4);
  v2 = surface->m_DID.id;
  v3 = (v1->base_tex_size >> ImageShift[ImgTex::fLandTextureScale]) / (surface->m_DID.id >> 28);
  if ( v3 < ImgTex::min_tex_size )
    v3 = ImgTex::min_tex_size;
  CSurface::ClearSurface(surface);
  if ( TexMerge::FillTempTexBuffer(v1, v2, v3) )
  {
    v5 = ImgTex::CreateLScapeTexture(v4, v2, (int)surface, TexMerge::tex_data, v3, v3);
    v6 = v5;
    if ( v5 )
    {
      if ( CSurface::UseTextureMap(surface, v5, SH_TEXMERGE) )
      {
        v6->vfptr->Release((Interface *)v6);
        return 1;
      }
      v6->vfptr->Release((Interface *)v6);
    }
  }
  return 0;
}
// 81E918: using guessed type unsigned __int32 ImgTex::min_tex_size;
// 845764: using guessed type enum ImageScaleType ImgTex::fLandTextureScale;

//----- (005049B0) --------------------------------------------------------  // acclient.c:306275
CSurface *__userpurge TexMerge::MakeNewSurface@<eax>(TexMerge *this@<ecx>, int a2@<ebx>, unsigned int pcode, unsigned int size)
{
  TexMerge *v4; // ebp@1
  unsigned __int32 v5; // edi@1
  CSurface *v6; // eax@3
  CSurface *v7; // esi@3
  ImgTex *v8; // ecx@4
  ImgTex *v9; // eax@5
  ImgTex *v10; // edi@5

  v4 = this;
  v5 = (this->base_tex_size >> ImageShift[ImgTex::fLandTextureScale]) / size;
  if ( v5 < ImgTex::min_tex_size )
    v5 = ImgTex::min_tex_size;
  CSurface::makeCustomSurface(SH_TEXMERGE);
  v7 = v6;
  if ( v6 )
  {
    ((void (__thiscall *)(CSurface *, unsigned int))v6->vfptr[2].Release)(v6, pcode);
    if ( TexMerge::FillTempTexBuffer(v4, pcode, v5) )
    {
      v9 = ImgTex::CreateLScapeTexture(v8, a2, (int)v4, TexMerge::tex_data, v5, v5);
      v10 = v9;
      if ( v9 )
      {
        CSurface::UseTextureMap(v7, v9, SH_TEXMERGE);
        v10->vfptr->Release((Interface *)v10);
      }
    }
  }
  return v7;
}
// 5049B0: could not find valid save-restore pair for ebx
// 81E918: using guessed type unsigned __int32 ImgTex::min_tex_size;
// 845764: using guessed type enum ImageScaleType ImgTex::fLandTextureScale;

//----- (006FA090) --------------------------------------------------------  // acclient.c:782719
void sub_6FA090()
{
  flt_84171C = 1000.0 + 1.0;
}

//----- (006FA0B0) --------------------------------------------------------  // acclient.c:782725
void sub_6FA0B0()
{
  flt_841720 = 24.0 * 8.0;
}

//----- (006FA0D0) --------------------------------------------------------  // acclient.c:782731
void sub_6FA0D0()
{
  flt_841724 = 24.0 * 0.5;
}

//----- (006FA0F0) --------------------------------------------------------  // acclient.c:782737
void sub_6FA0F0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841728, PFID_A8R8G8B8);
}

//----- (006FA100) --------------------------------------------------------  // acclient.c:782743
int sub_6FA100()
{
  return atexit(nullsub_1041);
}

