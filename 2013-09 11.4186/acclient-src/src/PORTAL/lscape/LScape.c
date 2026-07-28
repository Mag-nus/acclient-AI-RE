/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LScape
   Object     : PORTAL\lscape\LScape.obj
   Functions  : 138
   Addresses  : 00504A40 - 00766150 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00504A40) --------------------------------------------------------  // acclient.c:306312
void __thiscall Position::adjust_to_outside(Position *this)
{
  LandDefs::adjust_to_outside(&this->objcell_id, &this->frame.m_fOrigin);
}

//----- (00504A60) --------------------------------------------------------  // acclient.c:306318
int __stdcall LScape::get_block_shift(unsigned int cell_id1, unsigned int cell_id2, int *x_shift, int *y_shift)
{
  int result; // eax@2
  unsigned int v6; // eax@4
  int v7; // esi@4

  if ( cell_id1 )
  {
    if ( cell_id2 )
    {
      v6 = (cell_id2 >> 21) & 0x7F8;
      v7 = 8 * BYTE2(cell_id2);
    }
    else
    {
      v7 = 0;
      v6 = 0;
    }
    *x_shift = (signed int)(v6 - ((cell_id1 >> 21) & 0x7F8)) / 8;
    *y_shift = (v7 - 8 * (unsigned __int8)(cell_id1 >> 16)) / 8;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00504AE0) --------------------------------------------------------  // acclient.c:306348
void __thiscall LScape::CleanupDetailSurfaces(LScape *this)
{
  LScape *v1; // esi@1

  v1 = this;
  Render::SetLandscapeDetailSurface(0);
  if ( v1->landscape_detail_surface )
  {
    CSurface::releaseCustomSurface(v1->landscape_detail_surface);
    v1->landscape_detail_surface = 0;
  }
  Render::SetEnvironmentDetailSurface(0);
  if ( v1->environment_detail_surface )
  {
    CSurface::releaseCustomSurface(v1->environment_detail_surface);
    v1->environment_detail_surface = 0;
  }
  Render::SetBuildingDetailSurface(0);
  if ( v1->building_detail_surface )
  {
    CSurface::releaseCustomSurface(v1->building_detail_surface);
    v1->building_detail_surface = 0;
  }
  Render::SetObjectDetailSurface(0);
  if ( v1->object_detail_surface )
  {
    CSurface::releaseCustomSurface(v1->object_detail_surface);
    v1->object_detail_surface = 0;
  }
}

//----- (00504B60) --------------------------------------------------------  // acclient.c:306380
void __thiscall LScape::release_all(LScape *this)
{
  LScape *v1; // esi@1
  int v2; // ebx@2
  int i; // edi@3
  CLandBlock *v4; // ecx@4
  GameSky *v5; // ecx@12

  v1 = this;
  if ( this->land_blocks )
  {
    v2 = 0;
    if ( this->mid_width > 0 )
    {
      do
      {
        for ( i = 0; i < v1->mid_width; ++i )
        {
          v4 = v1->land_blocks[i + v2 * v1->mid_width];
          if ( v4 )
          {
            CLandBlock::release_all(v4);
            v1->land_blocks[i + v2 * v1->mid_width] = 0;
          }
        }
        ++v2;
      }
      while ( v2 < v1->mid_width );
    }
  }
  if ( v1->land_blocks )
  {
    operator delete[](v1->land_blocks);
    v1->land_blocks = 0;
  }
  if ( v1->block_draw_list )
  {
    operator delete[](v1->block_draw_list);
    v1->block_draw_list = 0;
  }
  v5 = v1->sky;
  if ( v5 )
    GameSky::SetInactive(v5);
  v1->loaded_cell_id = 0;
  v1->viewer_cell_id = 0;
}

//----- (00504C00) --------------------------------------------------------  // acclient.c:306428
int __thiscall LScape::SetMidRadius(LScape *this, int radius)
{
  int result; // eax@3

  if ( radius < 1 || this->land_blocks )
  {
    result = 0;
  }
  else
  {
    this->mid_radius = radius;
    this->mid_width = 2 * radius + 1;
    result = 1;
  }
  return result;
}

//----- (00504C30) --------------------------------------------------------  // acclient.c:306446
void __thiscall LScape::set_sky_position(LScape *this, Position *p)
{
  GameSky *v2; // ecx@2

  if ( this->loaded_cell_id )
  {
    v2 = this->sky;
    if ( v2 )
      GameSky::UpdatePosition(v2, p);
  }
}

//----- (00504C50) --------------------------------------------------------  // acclient.c:306459
void __thiscall LScape::get_block_order(LScape *this)
{
  LScape *v1; // esi@1
  int v2; // eax@3
  int v3; // ecx@3
  int v4; // edx@3
  signed int v5; // edi@3
  signed int v6; // ebx@9
  signed int v7; // eax@10
  int v8; // ecx@11
  int v9; // edx@11
  int v10; // ebp@11
  int v11; // ecx@16
  int v12; // edx@16
  int v13; // ebp@16
  int v14; // ecx@21
  int v15; // edx@21
  int v16; // ebp@21
  int v17; // ecx@26
  int v18; // edx@26
  int v19; // ebp@26
  int cnt; // [sp+8h] [bp-8h]@3
  int max_iq; // [sp+Ch] [bp-4h]@8

  v1 = this;
  if ( !this->block_draw_list )
    this->block_draw_list = (CLandBlock **)operator new[](4 * this->mid_width * this->mid_width);
  *v1->block_draw_list = v1->land_blocks[v1->viewer_b_yoff + v1->mid_width * v1->viewer_b_xoff];
  v2 = v1->viewer_b_yoff;
  v3 = v1->viewer_b_xoff;
  v4 = v1->mid_width;
  v5 = 1;
  cnt = 1;
  if ( v3 <= v2 )
  {
    v3 = v4 - v3 - 1;
    if ( v2 > v3 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v2 = v4 - v2 - 1;
  if ( v3 > v2 )
LABEL_7:
    v2 = v3;
LABEL_8:
  max_iq = v2;
  if ( v2 >= 1 )
  {
    do
    {
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          v7 = 0;
          do
          {
            v8 = v1->viewer_b_xoff + xoffarr[v7] + v5 * ixarr[v7] + v6 * jxarr[v7];
            v9 = v1->viewer_b_yoff + yoffarr[v7] + v5 * iyarr[v7] + v6 * jyarr[v7];
            v10 = v1->mid_width;
            if ( v8 < v10 && v9 < v10 && v8 >= 0 && v9 >= 0 )
              v1->block_draw_list[cnt++] = v1->land_blocks[v9 + v8 * v10];
            v11 = v1->viewer_b_xoff + dword_81CCD0[v7] + v5 * dword_81CCF0[v7] + v6 * dword_81CD10[v7];
            v12 = v1->viewer_b_yoff + dword_81CC70[v7] + v5 * dword_81CCB0[v7] + v6 * dword_81CC90[v7];
            v13 = v1->mid_width;
            if ( v11 < v13 && v12 < v13 && v11 >= 0 && v12 >= 0 )
              v1->block_draw_list[cnt++] = v1->land_blocks[v12 + v11 * v13];
            v14 = v1->viewer_b_xoff + dword_81CCD4[v7] + v5 * dword_81CCF4[v7] + v6 * dword_81CD14[v7];
            v15 = v1->viewer_b_yoff + dword_81CC74[v7] + v5 * dword_81CCB4[v7] + v6 * dword_81CC94[v7];
            v16 = v1->mid_width;
            if ( v14 < v16 && v15 < v16 && v14 >= 0 && v15 >= 0 )
              v1->block_draw_list[cnt++] = v1->land_blocks[v15 + v14 * v16];
            v17 = v1->viewer_b_xoff + dword_81CCD8[v7] + v5 * dword_81CCF8[v7] + v6 * dword_81CD18[v7];
            v18 = v1->viewer_b_yoff + dword_81CC78[v7] + v5 * dword_81CCB8[v7] + v6 * dword_81CC98[v7];
            v19 = v1->mid_width;
            if ( v17 < v19 && v18 < v19 && v17 >= 0 && v18 >= 0 )
              v1->block_draw_list[cnt++] = v1->land_blocks[v18 + v17 * v19];
            v7 += 4;
          }
          while ( v7 < 8 );
          ++v6;
        }
        while ( v6 < v5 );
        v2 = max_iq;
      }
      ++v5;
    }
    while ( v5 <= v2 );
  }
}
// 81CC70: using guessed type int dword_81CC70[];
// 81CC74: using guessed type int dword_81CC74[];
// 81CC78: using guessed type int dword_81CC78[];
// 81CC90: using guessed type int dword_81CC90[];
// 81CC94: using guessed type int dword_81CC94[];
// 81CC98: using guessed type int dword_81CC98[];
// 81CCB0: using guessed type int dword_81CCB0[];
// 81CCB4: using guessed type int dword_81CCB4[];
// 81CCB8: using guessed type int dword_81CCB8[];
// 81CCD0: using guessed type int dword_81CCD0[];
// 81CCD4: using guessed type int dword_81CCD4[];
// 81CCD8: using guessed type int dword_81CCD8[];
// 81CCF0: using guessed type int dword_81CCF0[];
// 81CCF4: using guessed type int dword_81CCF4[];
// 81CCF8: using guessed type int dword_81CCF8[];
// 81CD10: using guessed type int dword_81CD10[];
// 81CD14: using guessed type int dword_81CD14[];
// 81CD18: using guessed type int dword_81CD18[];

//----- (00504EC0) --------------------------------------------------------  // acclient.c:306570
void __thiscall LScape::grab_visible_cells(LScape *this)
{
  LScape *v1; // esi@1
  int v2; // eax@1
  unsigned int v3; // ebp@1
  unsigned int v4; // ebx@2
  CLandBlock **v5; // ecx@3
  int v6; // eax@3
  CLandBlock *v7; // edi@3
  int v8; // eax@7
  unsigned int v9; // ebp@7
  unsigned int v10; // ebx@8
  CLandBlock *v11; // edi@9

  v1 = this;
  v2 = this->mid_width;
  v3 = 0;
  if ( v2 )
  {
    do
    {
      v4 = 0;
      if ( v2 )
      {
        do
        {
          v5 = v1->land_blocks;
          v6 = v4 + v3 * v2;
          v7 = v5[v6];
          if ( v7 )
          {
            CLandBlock::init_buildings(v5[v6]);
            CLandBlock::grab_visible_cells(v7);
          }
          v2 = v1->mid_width;
          ++v4;
        }
        while ( v4 < v2 );
      }
      v2 = v1->mid_width;
      ++v3;
    }
    while ( v3 < v2 );
  }
  v8 = v1->mid_width;
  v9 = 0;
  if ( v8 )
  {
    do
    {
      v10 = 0;
      if ( v8 )
      {
        do
        {
          v11 = v1->land_blocks[v10 + v9 * v8];
          if ( v11 )
          {
            CLandBlock::init_static_objs(v11, 0);
            CLandBlock::init_dyn_objs(v11);
          }
          v8 = v1->mid_width;
          ++v10;
        }
        while ( v10 < v8 );
      }
      v8 = v1->mid_width;
      ++v9;
    }
    while ( v9 < v8 );
  }
}

//----- (00504F50) --------------------------------------------------------  // acclient.c:306644
void __thiscall LScape::release_visible_cells(LScape *this)
{
  LScape *v1; // edi@1
  int v2; // eax@1
  unsigned int v3; // ebx@1
  unsigned int v4; // esi@2
  CLandBlock *v5; // eax@3

  v1 = this;
  v2 = this->mid_width;
  v3 = 0;
  if ( v2 )
  {
    do
    {
      v4 = 0;
      if ( v2 )
      {
        do
        {
          v5 = v1->land_blocks[v4 + v3 * v2];
          if ( v5 )
            CLandBlock::release_visible_cells(v5);
          v2 = v1->mid_width;
          ++v4;
        }
        while ( v4 < v2 );
      }
      v2 = v1->mid_width;
      ++v3;
    }
    while ( v3 < v2 );
  }
}

//----- (00504F90) --------------------------------------------------------  // acclient.c:306680
void __thiscall LScape::get_block_orient(LScape *this, int ix, int iy, int *size, LandDefs::Direction *dir)
{
  int v5; // esi@1
  int v6; // edi@1
  signed int v7; // ecx@1
  signed int v8; // eax@1
  signed int v9; // eax@4
  int v10; // ecx@14

  v5 = iy - this->mid_radius;
  v6 = ix - this->mid_radius;
  v7 = abs(iy - this->mid_radius);
  v8 = abs(v6);
  if ( v8 <= v7 )
    v8 = v7;
  if ( v8 > 1 )
  {
    if ( v8 > 2 )
    {
      if ( v8 > 4 )
      {
        *size = 8;
        *dir = 0;
        return;
      }
      *size = 4;
      v9 = 4;
    }
    else
    {
      *size = 2;
      v9 = 2;
    }
  }
  else
  {
    *size = 1;
    v9 = 1;
  }
  if ( v6 == v9 )
  {
    if ( v5 == v9 )
      *dir = 7;
    else
      *dir = v5 != -v9 ? 3 : 8;
  }
  else
  {
    v10 = -v9;
    if ( v6 == -v9 )
    {
      if ( v5 == v9 )
        *dir = 5;
      else
        *dir = 2 * (v5 == v10) + 4;
    }
    else if ( v5 == v9 )
    {
      *dir = 1;
    }
    else
    {
      *dir = v5 != v10 ? 0 : 2;
    }
  }
}

//----- (005050A0) --------------------------------------------------------  // acclient.c:306748
void __stdcall LScape::landcell_check(CLandBlock *block)
{
  CLandBlock *v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@2
  int v5; // edx@3
  int v6; // ecx@7
  int v7; // edx@8
  void *v8; // esp@11
  float v9; // ecx@11
  float v10; // edx@11
  ViewIntervalType *v11; // ebx@11
  int v12; // edi@11
  float y; // ST10_4@12
  int v14; // eax@13
  int i; // ebx@13
  int v16; // edi@14
  int v17; // eax@14
  int v18; // ecx@15
  float v19; // ST10_4@17
  float x; // ST0C_4@17
  int v21; // eax@18
  int j; // edi@18
  CLandCell *v23; // ecx@19
  int v24; // eax@19
  bool v25; // zf@19
  int v26; // eax@19
  float v27; // ecx@21
  int v28; // eax@21
  ViewIntervalType *v29; // ecx@21
  ViewIntervalType *v30; // eax@21
  int v31; // [sp+Ch] [bp-928h]@11
  float max_height; // [sp+918h] [bp-1Ch]@21
  float min_height; // [sp+91Ch] [bp-18h]@21
  int v34; // [sp+920h] [bp-14h]@15
  float v35; // [sp+924h] [bp-10h]@15
  float block_x; // [sp+928h] [bp-Ch]@11
  float block_y; // [sp+92Ch] [bp-8h]@11
  ViewIntervalType *cell_interval; // [sp+930h] [bp-4h]@11
  CLandCell *cell; // [sp+93Ch] [bp+8h]@11
  CLandCell *cella; // [sp+93Ch] [bp+8h]@14
  CLandCell *cellb; // [sp+93Ch] [bp+8h]@19

  v2 = block;
  v3 = block->side_cell_count;
  if ( v3 == 8 )
  {
    if ( block->in_view == 2 )
    {
      v6 = 0;
      if ( block->side_cell_count * block->side_cell_count > 0 )
      {
        v7 = 0;
        do
        {
          block->lcell[v7].in_view = 2;
          ++v6;
          ++v7;
        }
        while ( v6 < block->side_cell_count * block->side_cell_count );
      }
    }
    else
    {
      v8 = alloca(2304);
      v9 = block->block_frame.m_fOrigin.x;
      v10 = block->block_frame.m_fOrigin.y;
      v11 = (ViewIntervalType *)&v31;
      v12 = 0;
      cell_interval = (ViewIntervalType *)&v31;
      block_x = v9;
      block_y = v10;
      cell = 0;
      do
      {
        y = (double)(signed int)cell * 24.0 + block_y;
        Render::get_clip_height(block_x, y, v11);
        ++v12;
        ++v11;
        cell = (CLandCell *)v12;
      }
      while ( v12 < v2->side_cell_count + 1 );
      v14 = v2->side_cell_count;
      for ( i = 0; i < v14; ++i )
      {
        v16 = 0;
        v17 = v14 + 1;
        cella = 0;
        if ( v17 > 0 )
        {
          v18 = ((_BYTE)i - 1) & 1;
          LODWORD(v35) = i - 1 + 2;
          v34 = ((_BYTE)i - 1) & 1;
          v35 = (double)SLODWORD(v35);
          while ( 1 )
          {
            v19 = (double)(signed int)cella * 24.0 + block_y;
            x = v35 * 24.0 + block_x;
            Render::get_clip_height(x, v19, &cell_interval[v16++ + v17 * v18]);
            v17 = v2->side_cell_count + 1;
            cella = (CLandCell *)v16;
            if ( v16 >= v17 )
              break;
            v18 = v34;
          }
        }
        v21 = v2->side_cell_count;
        for ( j = 0; j < v21; ++j )
        {
          v23 = v2->lcell;
          v24 = j + i * v21;
          v25 = &v23[v24] == 0;
          v26 = (int)&v23[v24];
          cellb = (CLandCell *)v26;
          if ( !v25 && !(*(int (__thiscall **)(int))(*(_DWORD *)v26 + 104))(v26) )
          {
            v27 = v2->max_zval;
            min_height = v2->min_zval;
            v28 = v2->side_cell_count + 1;
            max_height = v27;
            v29 = &cell_interval[j + v28 * (((unsigned __int8)i - 1) & 1)];
            v30 = &cell_interval[j + v28 * (i & 1)];
            cellb->in_view = Render::block_check(v30, v30 + 1, v29, v29 + 1, max_height, min_height);
          }
          v21 = v2->side_cell_count;
        }
        v14 = v2->side_cell_count;
      }
    }
  }
  else
  {
    v4 = 0;
    if ( v3 * v3 > 0 )
    {
      v5 = 0;
      do
      {
        block->lcell[v5].in_view = 1;
        ++v4;
        ++v5;
      }
      while ( v4 < block->side_cell_count * block->side_cell_count );
    }
  }
}

//----- (005052E0) --------------------------------------------------------  // acclient.c:306896
void __cdecl LScape::SetDay(int on)
{
  LScape::m_fAlwaysDaylight = on != 0;
  *(_QWORD *)&LScape::next_tick = 0i64;
  *(_QWORD *)&LScape::next_light_tick = 0i64;
}
// 841788: using guessed type double LScape::next_tick;
// 841790: using guessed type double LScape::next_light_tick;
// 841798: using guessed type bool LScape::m_fAlwaysDaylight;

//----- (00505320) --------------------------------------------------------  // acclient.c:306907
IDClass<_tagDataID,32,0> *__cdecl LandDefs::get_block_did(IDClass<_tagDataID,32,0> *result, int x, int y)
{
  IDClass<_tagDataID,32,0> *v3; // eax@5

  if ( x < 0 || y < 0 || x >= 2040 || y >= 2040 )
  {
    v3 = result;
    result->id = 0;
  }
  else
  {
    result->id = (((y >> 3) | 32 * (x & 0xFFFFFFF8)) << 16) | 0xFFFF;
    v3 = result;
  }
  return v3;
}

//----- (00505370) --------------------------------------------------------  // acclient.c:306925
void __thiscall LScape::LScape(LScape *this)
{
  LScape *v1; // esi@1
  GameSky *v2; // eax@1
  GameSky *v3; // eax@2

  v1 = this;
  this->land_blocks = 0;
  this->block_draw_list = 0;
  this->loaded_cell_id = 0;
  this->viewer_cell_id = 0;
  this->viewer_b_xoff = 0;
  this->viewer_b_yoff = 0;
  this->landscape_detail_surface = 0;
  this->environment_detail_surface = 0;
  this->building_detail_surface = 0;
  this->object_detail_surface = 0;
  this->mid_radius = 5;
  this->mid_width = 11;
  LODWORD(LScape::ambient_level) = 1053609165;
  LODWORD(LScape::sunlight.x) = 1067030938;
  LODWORD(LScape::sunlight.y) = 0;
  LODWORD(LScape::sunlight.z) = 1056964608;
  CLandBlock::init();
  v2 = (GameSky *)operator new(0x2Cu);
  if ( v2 )
  {
    GameSky::GameSky(v2);
    v1->sky = v3;
  }
  else
  {
    v1->sky = 0;
  }
}

//----- (00505410) --------------------------------------------------------  // acclient.c:306962
void __thiscall LScape::~LScape(LScape *this)
{
  LScape *v1; // edi@1
  void *v2; // esi@3

  v1 = this;
  LScape::release_all(this);
  if ( block_interval )
  {
    operator delete[](block_interval);
    block_interval = 0;
  }
  v2 = v1->sky;
  if ( v2 )
  {
    GameSky::~GameSky(v1->sky);
    operator delete(v2);
    v1->sky = 0;
  }
  LScape::CleanupDetailSurfaces(v1);
}

//----- (00505460) --------------------------------------------------------  // acclient.c:306985
void __thiscall LScape::calc_frame(LScape *this, CLandBlock *block, int ix, int iy)
{
  char *v4; // eax@1
  float v5; // ST00_4@1
  double v6; // st7@1
  float v7; // ST04_4@1

  v4 = (char *)&block->block_frame.m_fOrigin;
  v5 = (double)(ix - this->viewer_b_xoff) * flt_841814;
  v6 = (double)(iy - this->viewer_b_yoff);
  *(float *)v4 = v5;
  v7 = v6 * flt_841814;
  *((float *)v4 + 1) = v7;
  *((_DWORD *)v4 + 2) = 0;
}

//----- (005054D0) --------------------------------------------------------  // acclient.c:307002
void __thiscall LScape::set_landscape_lighting(LScape *this, float _ambient_level, RGBAUnion _ambient_color, AC1Legacy::Vector3 *_sunlight, RGBAUnion _sunlight_color)
{
  LScape *v5; // edi@1
  float intensity; // ST0C_4@7
  int v7; // eax@9
  int i; // ebx@9
  int j; // esi@10
  CLandBlock *v10; // eax@11
  RGBColor v11; // [sp+Ch] [bp-Ch]@6

  LScape::ambient_level = _ambient_level;
  v5 = this;
  LScape::ambient_color.color = _ambient_color.color;
  if ( LScape::m_fAlwaysDaylight )
  {
    if ( CRegionDesc::GetLighting(
           0.5,
           &LScape::ambient_level,
           &LScape::ambient_color,
           &LScape::sunlight,
           &LScape::sunlight_color)
      && LScape::ambient_level < (double)LScape::min_ambient )
      LScape::ambient_level = LScape::min_ambient;
  }
  else
  {
    LScape::sunlight.x = _sunlight->x;
    LScape::sunlight.y = _sunlight->y;
    LScape::sunlight.z = _sunlight->z;
    LScape::sunlight_color.color = _sunlight_color.color;
  }
  v11 = (RGBColor)LScape::sunlight;
  Render::world_lights.sunlight = LScape::sunlight;
  RGBColor::SetColor32(&v11, LScape::sunlight_color.color);
  Render::world_lights.sunlight_color.g = v11.g;
  LODWORD(Render::world_lights.sunlight_color.r) = (_DWORD)v11.r;
  Render::world_lights.sunlight_color.b = v11.b;
  Render::world_lights.m_bSunlightValid = 0;
  if ( SmartBox::smartbox )
  {
    intensity = sqrt(LScape::sunlight.z * LScape::sunlight.z + LScape::sunlight.y * LScape::sunlight.y + LScape::sunlight.x * LScape::sunlight.x)
              * 0.2
              + LScape::ambient_level;
    SmartBox::SetWorldAmbientLight(SmartBox::smartbox, intensity, LScape::ambient_color.color);
  }
  if ( v5->land_blocks )
  {
    v7 = v5->mid_width;
    for ( i = 0; i < v7; ++i )
    {
      for ( j = 0; j < v7; ++j )
      {
        v10 = v5->land_blocks[j + i * v7];
        if ( v10 )
          CLandBlockStruct::calc_lighting((CLandBlockStruct *)&v10->vertex_lighting);
        v7 = v5->mid_width;
      }
      v7 = v5->mid_width;
    }
  }
}
// 841798: using guessed type bool LScape::m_fAlwaysDaylight;
// 84194C: using guessed type float LScape::min_ambient;

//----- (00505660) --------------------------------------------------------  // acclient.c:307067
int __thiscall LScape::PreFetchCells(LScape *this, IDClass<_tagDataID,32,0> block_id, unsigned int *num_waiting_elements)
{
  LScape *v3; // esi@1
  int v4; // eax@3
  int v5; // edx@3
  char *v6; // ecx@4
  signed int v7; // edi@6
  unsigned int v8; // esi@11
  QualifiedDataID *v9; // eax@14
  CACHE_OBJECT_CODES v10; // eax@14
  QualifiedDataID *v11; // eax@18
  int v12; // eax@18
  int v13; // edi@18
  QualifiedDataID *v14; // eax@22
  bool v15; // zf@24
  bool v16; // sf@24
  unsigned __int8 v17; // of@24
  int retval; // [sp+Ch] [bp-34h]@1
  int v20; // [sp+10h] [bp-30h]@6
  char *v21; // [sp+14h] [bp-2Ch]@4
  int jj; // [sp+18h] [bp-28h]@5
  int ii; // [sp+1Ch] [bp-24h]@3
  int blocky; // [sp+20h] [bp-20h]@0
  int blockx; // [sp+24h] [bp-1Ch]@1
  QualifiedDataID v26; // [sp+28h] [bp-18h]@14
  QualifiedDataID v27; // [sp+30h] [bp-10h]@18
  QualifiedDataID v28; // [sp+38h] [bp-8h]@22

  v3 = this;
  blockx = (int)this;
  retval = 1;
  if ( block_id.id )
  {
    this = (LScape *)((block_id.id >> 21) & 0x7F8);
    blocky = 8 * (unsigned __int8)(block_id.id >> 16);
  }
  *num_waiting_elements = 0;
  v4 = v3->mid_radius;
  v5 = -v3->mid_radius;
  ii = -v3->mid_radius;
  if ( v5 <= v3->mid_radius )
  {
    v6 = (char *)this - 8 * v3->mid_radius;
    v21 = v6;
    while ( 1 )
    {
      jj = -v4;
      if ( -v4 > v4 )
        goto LABEL_26;
      v7 = blocky + -8 * v4;
      v20 = blocky + -8 * v4;
      do
      {
        if ( (signed int)v6 < 0 || v7 < 0 || (signed int)v6 >= 2040 || v7 >= 2040 )
          v8 = 0;
        else
          v8 = (((v7 >> 3) | 32 * ((unsigned int)v6 & 0xFFFFFFF8)) << 16) | 0xFFFF;
        if ( v8 != stru_84181C.id )
        {
          QualifiedDataID::QualifiedDataID(&v26, (IDClass<_tagDataID,32,0>)v8, 1u);
          v10 = DBObj::PreFetch(v9);
          if ( v10 != 2 && v10 != 1 )
          {
            retval = 0;
            if ( v10 != -1 )
              goto LABEL_24;
            goto LABEL_23;
          }
          QualifiedDataID::QualifiedDataID(&v27, (IDClass<_tagDataID,32,0>)v8, 1u);
          v12 = DBObj::Get(v11);
          v13 = v12;
          if ( !v12 )
          {
            QualifiedDataID::QualifiedDataID(&v28, (IDClass<_tagDataID,32,0>)(v8 & 0xFFFFFFFE | 0xFFFE), 2u);
            DBObj::PreFetch(v14);
            v7 = v20;
            retval = 0;
LABEL_23:
            ++*num_waiting_elements;
            goto LABEL_24;
          }
          if ( !CLandBlock::PreFetchCells((CLandBlock *)v12) )
            retval = 0;
          (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 20))(v13);
          v7 = v20;
        }
LABEL_24:
        v3 = (LScape *)blockx;
        v7 += 8;
        v17 = __OFSUB__(jj + 1, *(_DWORD *)blockx);
        v15 = jj + 1 == *(_DWORD *)blockx;
        v16 = jj + 1 - *(_DWORD *)blockx < 0;
        v6 = v21;
        ++jj;
        v20 = v7;
      }
      while ( (unsigned __int8)(v16 ^ v17) | v15 );
      v5 = ii;
LABEL_26:
      v4 = v3->mid_radius;
      ++v5;
      v6 += 8;
      ii = v5;
      v21 = v6;
      if ( v5 > v3->mid_radius )
        return retval;
    }
  }
  return 1;
}

//----- (00505810) --------------------------------------------------------  // acclient.c:307179
void __thiscall LScape::add_ambient_sounds(LScape *this, Ambient *ambient_sounds)
{
  LScape *v2; // ebx@1
  int v3; // esi@1
  int v4; // ebp@1
  int v5; // edi@2
  CLandBlock *v6; // ecx@4
  int size; // [sp+Ch] [bp-8h]@3
  LandDefs::Direction dir; // [sp+10h] [bp-4h]@3

  v2 = this;
  v3 = this->mid_width;
  v4 = 0;
  if ( v3 )
  {
    do
    {
      v5 = 0;
      if ( v3 )
      {
        do
        {
          LScape::get_block_orient(v2, v4, v5, &size, &dir);
          if ( size == 1 )
          {
            v6 = v2->land_blocks[v5 + v4 * v3];
            if ( v6 )
              CLandBlock::add_ambient_sounds(v6, ambient_sounds);
          }
          v3 = v2->mid_width;
          ++v5;
        }
        while ( v5 < (unsigned int)v3 );
      }
      v3 = v2->mid_width;
      ++v4;
    }
    while ( v4 < (unsigned int)v3 );
  }
}

//----- (00505880) --------------------------------------------------------  // acclient.c:307221
void __thiscall LScape::UseTime(LScape *this)
{
  LScape *v1; // esi@1
  GameSky *v2; // ecx@2
  unsigned __int8 v4; // c0@4
  unsigned __int8 v5; // c2@4
  double v6; // st6@7
  float v7; // edi@9
  unsigned int ST20_4_15; // ST20_4@15
  long double v9; // st7@19
  unsigned int v10; // eax@25
  RGBAUnion ST20_4_26; // ST20_4@26
  float max; // [sp+10h] [bp-24h]@10
  RGBAUnion color; // [sp+14h] [bp-20h]@10
  float min; // [sp+18h] [bp-1Ch]@9
  RGBAUnion sunlight_color; // [sp+1Ch] [bp-18h]@10
  long double time; // [sp+20h] [bp-14h]@4
  AC1Legacy::Vector3 sunlight_vec; // [sp+28h] [bp-Ch]@10

  v1 = this;
  if ( this->loaded_cell_id )
  {
    v2 = this->sky;
    if ( v2 )
      GameSky::UseTime(v2);
    time = *(double *)&Timer::cur_time;
    if ( !(v4 | v5) && CRegionDesc::current_region )
    {
      LScape::next_tick = CRegionDesc::current_region->sky_info->tick_size + COERCE_DOUBLE(Timer::cur_time.Cmd);
      if ( GameTime::current_game_time )
        v6 = GameTime::current_game_time->present_time_of_day;
      else
        v6 = 0.0;
      min = v6;
      v7 = min;
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) > LScape::next_light_tick )
      {
        if ( CRegionDesc::GetLighting(min, &max, &color, &sunlight_vec, &sunlight_color) )
        {
          if ( max < (double)LScape::min_ambient )
            max = LScape::min_ambient;
          if ( LScape::m_override_enabled )
          {
            if ( LScape::m_override_transition >= 1.0 )
            {
              max = LScape::m_override_ambient_level;
              color.color = LScape::m_override_ambient_color.color;
            }
            else
            {
              LODWORD(min) = (unsigned __int8)color.r - (unsigned __int8)(LScape::m_override_ambient_color.color >> 16);
              BYTE2(ST20_4_15) = (unsigned __int64)((double)(unsigned __int8)color.r
                                                  - (double)SLODWORD(min) * LScape::m_override_transition);
              LODWORD(min) = (unsigned __int8)color.g - (unsigned __int8)LScape::m_override_ambient_color.g;
              BYTE1(ST20_4_15) = (unsigned __int64)((double)BYTE1(color.color)
                                                  - (double)SLODWORD(min) * LScape::m_override_transition);
              LODWORD(min) = (unsigned __int8)color.b - (unsigned __int8)LScape::m_override_ambient_color.b;
              LOBYTE(ST20_4_15) = (unsigned __int64)((double)(unsigned __int8)color.color
                                                   - (double)SLODWORD(min) * LScape::m_override_transition);
              LODWORD(min) = (unsigned __int8)color.a - (unsigned __int8)LScape::m_override_ambient_color.a;
              BYTE3(ST20_4_15) = (unsigned __int64)((double)(unsigned __int8)color.a
                                                  - (double)SLODWORD(min) * LScape::m_override_transition);
              color.color = ST20_4_15;
              max = max - (max - LScape::m_override_ambient_level) * LScape::m_override_transition;
              LScape::m_override_transition = LScape::m_override_transition + 0.039999999;
            }
          }
          LScape::set_landscape_lighting(v1, max, color, &sunlight_vec, sunlight_color);
        }
        if ( CRegionDesc::current_region )
          v9 = CRegionDesc::current_region->sky_info->light_tick_size;
        else
          v9 = 3.0;
        LScape::next_light_tick = v9 + time;
      }
      RenderDeviceD3D::SetFFFogUserDisabled((RenderDeviceD3D *)RenderDevice::render_device, LScape::m_fFogEnabled == 0);
      if ( LScape::m_fFogEnabled )
      {
        RenderDeviceD3D::SetFFFogEnable((RenderDeviceD3D *)RenderDevice::render_device, LScape::m_fFogEnabled);
        if ( CRegionDesc::GetWorldFog(v7, &min, &max, &color) )
        {
          if ( LScape::m_override_enabled )
          {
            v10 = LScape::m_override_fog_color.color;
            if ( LScape::m_override_transition >= 1.0 )
            {
              min = LScape::m_override_fog_min;
              max = LScape::m_override_fog_max;
            }
            else
            {
              sunlight_color.color = (unsigned __int8)color.r
                                   - (unsigned __int8)(LScape::m_override_fog_color.color >> 16);
              ST20_4_26.r = (unsigned __int64)((double)(unsigned __int8)color.r
                                             - (double)(signed int)sunlight_color.color * LScape::m_override_transition);
              sunlight_color.color = (unsigned __int8)color.g - (unsigned __int8)LScape::m_override_fog_color.g;
              ST20_4_26.g = (unsigned __int64)((double)BYTE1(color.color)
                                             - (double)(signed int)sunlight_color.color * LScape::m_override_transition);
              sunlight_color.color = (unsigned __int8)color.b - (unsigned __int8)LScape::m_override_fog_color.b;
              ST20_4_26.b = (unsigned __int64)((double)(unsigned __int8)color.color
                                             - (double)(signed int)sunlight_color.color * LScape::m_override_transition);
              sunlight_color.color = (unsigned __int8)color.a - (unsigned __int8)LScape::m_override_fog_color.a;
              ST20_4_26.a = (unsigned __int64)((double)(unsigned __int8)color.a
                                             - (double)(signed int)sunlight_color.color * LScape::m_override_transition);
              v10 = ST20_4_26.color;
              min = min - (min - LScape::m_override_fog_min) * LScape::m_override_transition;
              max = max - (max - LScape::m_override_fog_max) * LScape::m_override_transition;
              LScape::m_override_transition = LScape::m_override_transition + 0.039999999;
            }
            color.color = v10;
          }
          RenderDeviceD3D::SetFFFogProperties((RenderDeviceD3D *)RenderDevice::render_device, &color, min, max);
        }
      }
    }
  }
}
// 81CBE8: using guessed type bool LScape::m_fFogEnabled;
// 841774: using guessed type struct RGBAUnion LScape::m_override_fog_color;
// 841778: using guessed type struct RGBAUnion LScape::m_override_ambient_color;
// 841788: using guessed type double LScape::next_tick;
// 841790: using guessed type double LScape::next_light_tick;
// 841799: using guessed type bool LScape::m_override_enabled;
// 84179C: using guessed type float LScape::m_override_ambient_level;
// 8417A0: using guessed type float LScape::m_override_fog_min;
// 8417A4: using guessed type float LScape::m_override_fog_max;
// 8417A8: using guessed type float LScape::m_override_transition;
// 84194C: using guessed type float LScape::min_ambient;

//----- (00505C70) --------------------------------------------------------  // acclient.c:307351
void __thiscall LScape::calc_draw_order(LScape *this, unsigned int cell_id, int calc_block_order)
{
  LScape *v3; // esi@1
  unsigned __int32 v4; // edi@3
  LandDefs::Direction v5; // ebx@3
  int v6; // edx@5
  int v7; // ecx@5
  char v8; // di@5
  int v9; // eax@5
  char v10; // bl@5
  int v11; // ecx@5
  __int32 v12; // eax@5
  int v13; // ecx@11
  int v14; // eax@11
  int i; // edi@12
  CLandBlock *v16; // ebx@13
  int v17; // ecx@16
  int ix; // [sp+10h] [bp-10h]@2
  LandDefs::Direction vdir; // [sp+14h] [bp-Ch]@4
  SqCoord offset_coord; // [sp+18h] [bp-8h]@11

  v3 = this;
  if ( cell_id )
  {
    ix = this->loaded_cell_id;
    if ( ix )
    {
      v4 = ((unsigned int)ix >> 21) & 0x7F8;
      v5 = 8 * (unsigned __int8)((unsigned int)ix >> 16);
    }
    else
    {
      v5 = vdir;
      v4 = vdir;
    }
    LandDefs::gid_to_lcoord(cell_id, &ix, (int *)&vdir);
    v6 = v3->mid_width;
    v7 = 8 * v3->mid_radius - v4;
    v8 = ix;
    v9 = 8 * v3->mid_radius - v5;
    v10 = vdir;
    v11 = (ix + v7) >> 3;
    v12 = (vdir + v9) >> 3;
    v3->viewer_b_xoff = v11;
    v3->viewer_b_yoff = v12;
    if ( v11 >= v6 || v12 >= v6 || v11 < 0 || v12 < 0 )
    {
      LScape::update_viewpoint(v3, 0);
    }
    else
    {
      if ( calc_block_order )
        LScape::get_block_order(v3);
      v13 = v3->mid_width;
      v14 = 0;
      offset_coord.x = v8 & 7;
      offset_coord.y = v10 & 7;
      ix = 0;
      if ( v13 > 0 )
      {
        do
        {
          for ( i = 0; i < v3->mid_width; ++i )
          {
            v16 = v3->land_blocks[i + v14 * v3->mid_width];
            if ( v16 )
            {
              vdir = LandDefs::get_dir(v14 - v3->viewer_b_xoff, i - v3->viewer_b_yoff);
              LScape::calc_frame(v3, v16, ix, i);
              CLandBlock::calc_draw_order(v16, vdir, &offset_coord);
              v14 = ix;
            }
          }
          v17 = v3->mid_width;
          ++v14;
          ix = v14;
        }
        while ( v14 < v17 );
      }
    }
  }
}

//----- (00505DD0) --------------------------------------------------------  // acclient.c:307435
int __stdcall LScape::get_all(IDClass<_tagDataID,32,0> gid)
{
  QualifiedDataID *v2; // eax@1
  int result; // eax@1
  QualifiedDataID v4; // [sp+4h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v4, gid, 1u);
  result = DBObj::Get(v2);
  if ( result )
  {
    if ( gid.id )
    {
      *(_DWORD *)(result + 152) = (gid.id >> 21) & 0x7F8;
      *(_DWORD *)(result + 156) = 8 * BYTE2(gid.id);
    }
    else
    {
      *(_DWORD *)(result + 152) = 0;
      *(_DWORD *)(result + 156) = 0;
    }
  }
  return result;
}

//----- (00505E40) --------------------------------------------------------  // acclient.c:307460
unsigned int __thiscall LScape::get_landblock(LScape *this, unsigned int cell_id)
{
  LScape *v2; // esi@1
  CLandBlock **v3; // ebx@1
  unsigned int result; // eax@2
  unsigned int v5; // edi@3
  signed int v6; // ecx@5
  int v7; // eax@5
  int v8; // edx@7
  CLandBlock *v9; // edx@9
  int x; // [sp+8h] [bp-Ch]@5
  int vy; // [sp+Ch] [bp-8h]@5
  int y; // [sp+10h] [bp-4h]@5

  v2 = this;
  v3 = this->land_blocks;
  if ( v3 )
  {
    v5 = cell_id;
    if ( LandDefs::inbound_valid_cellid(cell_id)
      && (unsigned __int16)v5 < 0x100u
      && (LandDefs::blockid_to_lcoord(v2->loaded_cell_id, (int *)&cell_id, &vy),
          LandDefs::gid_to_lcoord(v5, &x, &y),
          v6 = (signed int)(x + 8 * v2->mid_radius - cell_id) >> 3,
          v7 = (y + 8 * v2->mid_radius - vy) >> 3,
          v6 >= 0)
      && v7 >= 0
      && (v8 = v2->mid_width, v6 < v8)
      && v7 < v8 )
    {
      v9 = v3[v7 + v6 * v8];
      result = 0;
      if ( v9 )
      {
        LOBYTE(result) = v9->side_cell_count != 8;
        result = (unsigned int)v9 & (result - 1);
      }
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

//----- (00505F10) --------------------------------------------------------  // acclient.c:307511
unsigned int __thiscall LScape::get_landcell(LScape *this, unsigned int cell_id)
{
  unsigned int v2; // edi@1
  unsigned int result; // eax@1
  CLandCell *v4; // esi@1
  int y; // [sp+0h] [bp-4h]@1

  y = (int)this;
  v2 = cell_id;
  result = LScape::get_landblock(this, cell_id);
  v4 = (CLandCell *)result;
  if ( result )
  {
    LandDefs::gid_to_lcoord(v2, (int *)&cell_id, &y);
    result = LODWORD(v4->pos.frame.m_fOrigin.x)
           + 264 * (y % 8 + (signed int)cell_id % 8 * v4->shadow_part_list.next_available);
  }
  return result;
}

//----- (00505F80) --------------------------------------------------------  // acclient.c:307532
void __thiscall LScape::draw_check_blocks(LScape *this)
{
  LScape *v1; // edi@1
  int v2; // eax@1
  int v3; // esi@1
  int i; // ebx@2
  CLandBlock *v5; // eax@3
  int v6; // edx@3
  int v7; // esi@5
  int v8; // ebp@10
  ViewIntervalType *v9; // eax@13
  int v10; // ecx@13
  struct portal_view_type *v11; // eax@14
  int v12; // esi@15
  int v13; // esi@22
  int v14; // ebx@23
  float y; // ST10_4@24
  float x; // ST0C_4@24
  int v17; // eax@25
  int v18; // ebx@25
  int v19; // esi@26
  int v20; // eax@26
  float v21; // ST10_4@27
  float v22; // ST0C_4@27
  int v23; // eax@28
  int j; // ebp@28
  CLandBlock *v25; // esi@29
  int v26; // eax@30
  ViewIntervalType *v27; // ecx@30
  ViewIntervalType *v28; // eax@30
  signed int v29; // eax@30
  int vlistlen; // [sp+1Ch] [bp-18h]@15
  int vdone; // [sp+20h] [bp-14h]@1
  int vdonea; // [sp+20h] [bp-14h]@14
  int vnum; // [sp+24h] [bp-10h]@14

  v1 = this;
  v2 = this->mid_width;
  v3 = 0;
  for ( vdone = 0; v3 < v2; vdone = v3 )
  {
    for ( i = 0; i < v2; ++i )
    {
      v5 = this->land_blocks[i + v3 * v2];
      v6 = 0;
      if ( v5 )
      {
        v5->in_view = 0;
        if ( v5->side_cell_count * v5->side_cell_count > 0 )
        {
          v7 = 0;
          do
          {
            v5->lcell[v7].in_view = 0;
            ++v6;
            ++v7;
          }
          while ( v6 < v5->side_cell_count * v5->side_cell_count );
          v3 = vdone;
        }
      }
      v2 = this->mid_width;
    }
    v2 = this->mid_width;
    ++v3;
  }
  v8 = 0;
  if ( block_interval )
  {
    if ( block_int_size == this->mid_width )
      goto LABEL_14;
    operator delete[](block_interval);
  }
  v9 = (ViewIntervalType *)operator new[]((v1->mid_width + 1) << 8);
  v10 = v1->mid_width;
  block_interval = v9;
  block_int_size = v10;
LABEL_14:
  v11 = Render::PortalList;
  vdonea = 0;
  vnum = 0;
  if ( Render::PortalList )
  {
    vlistlen = Render::PortalList->view_count;
    goto LABEL_18;
  }
  v12 = 0;
  for ( vlistlen = 0; ; v12 = vlistlen )
  {
    if ( !v12 || (Render::set_view(&v11->view, v8), ++v8, vnum = v8, v8 == v12) )
      vdonea = 1;
    v13 = 0;
    if ( v1->mid_width + 1 > 0 )
    {
      v14 = 0;
      do
      {
        y = (double)(v13 - v1->viewer_b_yoff) * flt_841814;
        x = (double)-v1->viewer_b_xoff * flt_841814;
        Render::get_clip_height(x, y, &block_interval[v14]);
        ++v13;
        ++v14;
      }
      while ( v13 < v1->mid_width + 1 );
    }
    v17 = v1->mid_width;
    v18 = 0;
    if ( v17 > 0 )
    {
      do
      {
        v19 = 0;
        v20 = v17 + 1;
        if ( v20 > 0 )
        {
          do
          {
            v21 = (double)(v19 - v1->viewer_b_yoff) * flt_841814;
            v22 = (double)(v18 - v1->viewer_b_xoff + 1) * flt_841814;
            Render::get_clip_height(v22, v21, &block_interval[v19++ + v20 * (((unsigned __int8)v18 - 1) & 1)]);
            v20 = v1->mid_width + 1;
          }
          while ( v19 < v20 );
        }
        v23 = v1->mid_width;
        for ( j = 0; j < v23; ++j )
        {
          v25 = v1->land_blocks[j + v18 * v23];
          if ( v25 )
          {
            v26 = v23 + 1;
            v27 = &block_interval[j + v26 * (((unsigned __int8)v18 - 1) & 1)];
            v28 = &block_interval[j + v26 * (v18 & 1)];
            v29 = Render::block_check(v28, v28 + 1, v27, v27 + 1, v25->max_zval, v25->min_zval);
            if ( v29 )
            {
              v25->in_view = v29;
              LScape::landcell_check(v25);
            }
          }
          v23 = v1->mid_width;
        }
        v17 = v1->mid_width;
        ++v18;
      }
      while ( v18 < v17 );
      v8 = vnum;
    }
    if ( vdonea )
      break;
    v11 = Render::PortalList;
LABEL_18:
    ;
  }
}
// 866320: using guessed type struct portal_view_type *Render::PortalList;

//----- (00506230) --------------------------------------------------------  // acclient.c:307690
int __stdcall LScape::GenerateDetailSurface(unsigned int terrain_number)
{
  unsigned int v2; // ST08_4@1
  LandSurf *v3; // eax@1
  int v5; // eax@3
  int v6; // esi@3
  QualifiedDataID *v7; // eax@4
  int v8; // eax@4
  QualifiedDataID v9; // [sp+0h] [bp-8h]@4

  v2 = terrain_number;
  v3 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
  LandSurf::GetDetailTex(v3, (IDClass<_tagDataID,32,0> *)&terrain_number, v2);
  if ( terrain_number == stru_84181C.id )
    return 0;
  CSurface::makeCustomSurface(SH_CUSTOMDB);
  v6 = v5;
  if ( v5 )
  {
    QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)terrain_number, 0xBu);
    v8 = DBObj::Get(v7);
    if ( v8 )
    {
      CSurface::UseTextureMap((CSurface *)v6, (ImgTex *)v8, SH_CUSTOMDB);
      *(_DWORD *)(v6 + 88) |= 0x20000u;
      return v6;
    }
    CSurface::releaseCustomSurface((CSurface *)v6);
    v6 = 0;
  }
  return v6;
}

//----- (005062D0) --------------------------------------------------------  // acclient.c:307724
void __thiscall LScape::update_viewpoint(LScape *this, unsigned int cell_id)
{
  LScape *v2; // esi@1
  unsigned int v3; // eax@3
  CLandBlock **v4; // eax@5

  v2 = this;
  if ( cell_id && this->loaded_cell_id )
  {
    v3 = this->viewer_cell_id;
    if ( cell_id != v3 )
    {
      this->viewer_cell_id = cell_id;
      LScape::calc_draw_order(this, cell_id, ((cell_id ^ v3) & 0xFFFF0000) != 0);
    }
  }
  else
  {
    v4 = this->block_draw_list;
    this->viewer_cell_id = 0;
    if ( v4 )
    {
      operator delete[](v4);
      v2->block_draw_list = 0;
    }
  }
}

//----- (00506330) --------------------------------------------------------  // acclient.c:307753
void __thiscall LScape::draw(LScape *this)
{
  LScape *v1; // edi@1
  GameSky *v2; // ecx@1
  int i; // esi@4
  CLandBlock *v4; // eax@5
  GameSky *v5; // ecx@9

  v1 = this;
  v2 = this->sky;
  if ( v2 )
    GameSky::Draw(v2, 0);
  if ( v1->block_draw_list )
  {
    LScape::draw_check_blocks(v1);
    for ( i = v1->mid_width * v1->mid_width - 1; i >= 0; --i )
    {
      v4 = v1->block_draw_list[i];
      if ( v4 && v4->in_view )
        ((void (__stdcall *)(_DWORD))RenderDevice::render_device->vfptr->DrawBlock)(v1->block_draw_list[i]);
    }
    v5 = v1->sky;
    if ( v5 )
    {
      if ( LScape::weather_enabled )
        GameSky::Draw(v5, 1);
    }
  }
}
// 81CBE9: using guessed type bool LScape::weather_enabled;

//----- (005063A0) --------------------------------------------------------  // acclient.c:307785
void __thiscall LScape::update_block(LScape *this, unsigned int cell_id, int x_shift, int y_shift, int refresh)
{
  LScape *v5; // esi@1
  int v6; // eax@1
  unsigned int v7; // ecx@1
  int v8; // ebx@1
  CLandBlock **v9; // eax@1
  int v10; // ebp@1
  int v11; // eax@3
  bool v12; // sf@8
  int v13; // ebp@11
  int v14; // edi@13
  int v15; // ebx@13
  IDClass<_tagDataID,32,0> *v16; // eax@15
  int v17; // eax@17
  int v18; // ecx@18
  unsigned __int8 v19; // of@18
  int v20; // ebx@25
  CLandBlock *v21; // ecx@29
  int v22; // edi@31
  IDClass<_tagDataID,32,0> *v23; // eax@35
  int v24; // eax@37
  int v25; // ebp@40
  int v26; // ebx@42
  CLandBlock *v27; // ecx@46
  int v28; // edi@48
  IDClass<_tagDataID,32,0> *v29; // eax@52
  int v30; // eax@55
  int v31; // ebp@57
  int v32; // ebx@60
  int v33; // eax@62
  int v34; // edi@62
  CLandBlock *v35; // eax@64
  int v36; // eax@67
  IDClass<_tagDataID,32,0> *v37; // eax@70
  int v38; // edi@70
  int v39; // eax@72
  int v40; // ebx@77
  int v41; // eax@79
  int v42; // edi@79
  CLandBlock *v43; // eax@81
  IDClass<_tagDataID,32,0> *v44; // eax@87
  int v45; // edi@87
  bool v46; // zf@94
  int v47; // ebp@96
  signed int v48; // ebx@97
  unsigned int v49; // edi@102
  QualifiedDataID *v50; // eax@102
  int v51; // eax@102
  int v52; // ecx@104
  int v53; // ecx@110
  int v54; // ecx@111
  int v55; // eax@111
  int i; // ebx@112
  CLandBlock *v57; // edi@113
  int v58; // ecx@121
  int x; // [sp+10h] [bp-10h]@0
  int xa; // [sp+10h] [bp-10h]@24
  unsigned int xb; // [sp+10h] [bp-10h]@43
  int xc; // [sp+10h] [bp-10h]@76
  int base_x; // [sp+14h] [bp-Ch]@1
  IDClass<_tagDataID,32,0> result; // [sp+18h] [bp-8h]@35

  v5 = this;
  LandDefs::gid_to_lcoord(cell_id, &base_x, (int *)&cell_id);
  v6 = 8 * v5->mid_radius;
  v7 = cell_id - v6;
  v8 = base_x - v6;
  v9 = v5->land_blocks;
  v10 = 0;
  cell_id = v7;
  if ( !v9 || refresh || (v11 = v5->mid_width, x_shift >= v11) || y_shift >= v11 || x_shift <= -v11 || y_shift <= -v11 )
  {
    LScape::release_all(v5);
    if ( !v5->land_blocks )
      v5->land_blocks = (CLandBlock **)operator new[](4 * v5->mid_width * v5->mid_width);
    v46 = v5->mid_width == 0;
    v12 = v5->mid_width < 0;
    y_shift = 0;
    if ( !v12 && !v46 )
    {
      x_shift = v8;
      do
      {
        v47 = 0;
        if ( v5->mid_width > 0 )
        {
          v48 = cell_id;
          do
          {
            if ( x_shift < 0 || v48 < 0 || x_shift >= 2040 || v48 >= 2040 )
            {
              v5->land_blocks[v47 + y_shift * v5->mid_width] = 0;
            }
            else
            {
              v49 = (((v48 >> 3) | 32 * (x_shift & 0xFFFFFFF8)) << 16) | 0xFFFF;
              refresh = (((v48 >> 3) | 32 * (x_shift & 0xFFFFFFF8)) << 16) | 0xFFFF;
              QualifiedDataID::QualifiedDataID((QualifiedDataID *)&result, (IDClass<_tagDataID,32,0>)v49, 1u);
              v51 = DBObj::Get(v50);
              if ( v51 )
              {
                if ( v49 )
                {
                  v52 = 8 * BYTE2(refresh);
                  x = (v49 >> 21) & 0x7F8;
                  base_x = 8 * BYTE2(refresh);
                }
                else
                {
                  v52 = base_x;
                }
                *(_DWORD *)(v51 + 152) = x;
                *(_DWORD *)(v51 + 156) = v52;
              }
              v5->land_blocks[v47 + y_shift * v5->mid_width] = (CLandBlock *)v51;
            }
            ++v47;
            v48 += 8;
          }
          while ( v47 < v5->mid_width );
        }
        v53 = v5->mid_width;
        v19 = __OFSUB__(y_shift + 1, v53);
        v12 = y_shift++ + 1 - v53 < 0;
        x_shift += 8;
      }
      while ( v12 ^ v19 );
    }
  }
  else
  {
    if ( !x_shift )
    {
      v12 = y_shift < 0;
      if ( !y_shift )
      {
        y_shift = 0;
        if ( v11 > 0 )
        {
          refresh = v8;
          do
          {
            v13 = 0;
            if ( v5->mid_width > 0 )
            {
              x_shift = cell_id;
              do
              {
                v14 = y_shift * v5->mid_width + v13;
                v15 = (int)&v5->land_blocks[v14];
                if ( !*(_DWORD *)v15 )
                {
                  if ( LandDefs::in_bounds(refresh, x_shift) )
                  {
                    v16 = LandDefs::get_block_did((IDClass<_tagDataID,32,0> *)&base_x, refresh, x_shift);
                    v5->land_blocks[v14] = (CLandBlock *)LScape::get_all((IDClass<_tagDataID,32,0>)v16->id);
                  }
                  else
                  {
                    *(_DWORD *)v15 = 0;
                  }
                }
                v17 = v5->mid_width;
                ++v13;
                x_shift += 8;
              }
              while ( v13 < v17 );
            }
            v18 = v5->mid_width;
            v19 = __OFSUB__(y_shift + 1, v18);
            v12 = y_shift++ + 1 - v18 < 0;
            refresh += 8;
          }
          while ( v12 ^ v19 );
        }
        goto LABEL_111;
      }
      goto LABEL_22;
    }
    if ( x_shift >= 0 )
    {
      v12 = y_shift < 0;
LABEL_22:
      if ( v12 )
      {
        v25 = 0;
        if ( v11 > 0 )
        {
          base_x = v8;
          do
          {
            v26 = v5->mid_width - 1;
            if ( v26 >= 0 )
            {
              refresh = v26 + y_shift;
              xb = cell_id + 8 * v26;
              do
              {
                if ( v25 < x_shift || v26 >= y_shift + v5->mid_width )
                {
                  v27 = v5->land_blocks[v26 + v25 * v5->mid_width];
                  if ( v27 )
                    CLandBlock::release_all(v27);
                }
                v28 = v5->mid_width;
                if ( v25 + x_shift >= v28 || refresh < 0 )
                {
                  if ( LandDefs::in_bounds(base_x, xb) )
                  {
                    v29 = LandDefs::get_block_did(&result, base_x, xb);
                    v5->land_blocks[v26 + v25 * v28] = (CLandBlock *)LScape::get_all((IDClass<_tagDataID,32,0>)v29->id);
                  }
                  else
                  {
                    v5->land_blocks[v26 + v25 * v28] = 0;
                  }
                }
                else
                {
                  v5->land_blocks[v26 + v25 * v28] = v5->land_blocks[refresh + (v25 + x_shift) * v5->mid_width];
                }
                --v26;
                --refresh;
                xb -= 8;
              }
              while ( v26 >= 0 );
            }
            v30 = v5->mid_width;
            ++v25;
            base_x += 8;
          }
          while ( v25 < v30 );
        }
      }
      else if ( v11 > 0 )
      {
        xa = v8;
        do
        {
          v20 = 0;
          if ( v5->mid_width > 0 )
          {
            refresh = cell_id;
            do
            {
              if ( v10 < x_shift || v20 < y_shift )
              {
                v21 = v5->land_blocks[v20 + v10 * v5->mid_width];
                if ( v21 )
                  CLandBlock::release_all(v21);
              }
              v22 = v5->mid_width;
              base_x = v10 + x_shift;
              if ( v10 + x_shift >= v22 || v20 + y_shift >= v22 )
              {
                if ( LandDefs::in_bounds(xa, refresh) )
                {
                  v23 = LandDefs::get_block_did(&result, xa, refresh);
                  v5->land_blocks[v20 + v10 * v22] = (CLandBlock *)LScape::get_all((IDClass<_tagDataID,32,0>)v23->id);
                }
                else
                {
                  v5->land_blocks[v20 + v10 * v22] = 0;
                }
              }
              else
              {
                v5->land_blocks[v20 + v10 * v22] = v5->land_blocks[v20 + y_shift + base_x * v22];
              }
              v24 = v5->mid_width;
              ++v20;
              refresh += 8;
            }
            while ( v20 < v24 );
          }
          ++v10;
          xa += 8;
        }
        while ( v10 < v5->mid_width );
      }
      goto LABEL_111;
    }
    v31 = v11 - 1;
    if ( y_shift < 0 )
    {
      if ( v31 >= 0 )
      {
        xc = v8 + 8 * v31;
        do
        {
          v40 = v5->mid_width - 1;
          if ( v40 >= 0 )
          {
            refresh = v40 + y_shift;
            base_x = cell_id + 8 * v40;
            do
            {
              v41 = v5->mid_width;
              v42 = x_shift;
              if ( v31 >= v41 + x_shift || v40 >= v41 + y_shift )
              {
                v43 = v5->land_blocks[v40 + v31 * v41];
                if ( v43 )
                  CLandBlock::release_all(v43);
              }
              if ( v42 + v31 < 0 || refresh < 0 )
              {
                if ( LandDefs::in_bounds(xc, base_x) )
                {
                  v44 = LandDefs::get_block_did(&result, xc, base_x);
                  v45 = v40 + v31 * v5->mid_width;
                  v5->land_blocks[v45] = (CLandBlock *)LScape::get_all((IDClass<_tagDataID,32,0>)v44->id);
                }
                else
                {
                  v5->land_blocks[v40 + v31 * v5->mid_width] = 0;
                }
              }
              else
              {
                v5->land_blocks[v40 + v31 * v5->mid_width] = v5->land_blocks[refresh + (v42 + v31) * v5->mid_width];
              }
              --v40;
              --refresh;
              base_x -= 8;
            }
            while ( v40 >= 0 );
          }
          --v31;
          xc -= 8;
        }
        while ( v31 >= 0 );
      }
    }
    else if ( v31 >= 0 )
    {
      base_x = v8 + 8 * v31;
      do
      {
        v32 = 0;
        if ( v5->mid_width > 0 )
        {
          refresh = cell_id;
          do
          {
            v33 = v5->mid_width;
            v34 = x_shift;
            if ( v31 >= v33 + x_shift || v32 < y_shift )
            {
              v35 = v5->land_blocks[v32 + v31 * v33];
              if ( v35 )
                CLandBlock::release_all(v35);
            }
            if ( v34 + v31 < 0 || (v36 = v5->mid_width, v32 + y_shift >= v36) )
            {
              if ( LandDefs::in_bounds(base_x, refresh) )
              {
                v37 = LandDefs::get_block_did(&result, base_x, refresh);
                v38 = v32 + v31 * v5->mid_width;
                v5->land_blocks[v38] = (CLandBlock *)LScape::get_all((IDClass<_tagDataID,32,0>)v37->id);
              }
              else
              {
                v5->land_blocks[v32 + v31 * v5->mid_width] = 0;
              }
            }
            else
            {
              v5->land_blocks[v32 + v31 * v36] = v5->land_blocks[v32 + y_shift + (v34 + v31) * v5->mid_width];
            }
            v39 = v5->mid_width;
            ++v32;
            refresh += 8;
          }
          while ( v32 < v39 );
        }
        --v31;
        base_x -= 8;
      }
      while ( v31 >= 0 );
    }
  }
LABEL_111:
  v54 = v5->mid_width;
  v55 = 0;
  y_shift = 0;
  if ( v54 > 0 )
  {
    do
    {
      for ( i = 0; i < v5->mid_width; ++i )
      {
        v57 = v5->land_blocks[i + v55 * v5->mid_width];
        if ( v57 )
        {
          LScape::get_block_orient(v5, v55, i, &x_shift, (LandDefs::Direction *)&cell_id);
          if ( v57->side_cell_count == 8 && 8 / x_shift != 8 )
            CLandBlock::notify_change_size(v57);
          if ( CLandBlockStruct::generate(
                 (CLandBlockStruct *)&v57->vertex_lighting,
                 v57->m_DID.id,
                 x_shift,
                 (LandDefs::Direction)cell_id) )
          {
            v57->closest.x = -1;
            v57->closest.y = -1;
            CLandBlock::init_lcell_ptrs(v57);
            CLandBlockStruct::calc_lighting((CLandBlockStruct *)&v57->vertex_lighting);
            CLandBlock::get_land_limits(v57);
          }
          v55 = y_shift;
        }
      }
      v58 = v5->mid_width;
      ++v55;
      y_shift = v55;
    }
    while ( v55 < v58 );
  }
}

//----- (00506B40) --------------------------------------------------------  // acclient.c:308208
char __thiscall LScape::SetDetailTexturing(LScape *this, int landscape, int building, int environment, int object)
{
  LScape *v5; // esi@1
  char result; // al@2
  LandSurf *v7; // eax@3
  float tiling; // ST00_4@3
  LandSurf *v9; // eax@3
  float v10; // ST00_4@3
  LandSurf *v11; // eax@3
  float v12; // ST00_4@3
  LandSurf *v13; // eax@3
  float v14; // ST00_4@3
  int v15; // eax@4
  int v16; // eax@6
  int v17; // eax@8
  int v18; // eax@10

  v5 = this;
  if ( CRegionDesc::current_region )
  {
    LScape::CleanupDetailSurfaces(this);
    v7 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
    tiling = (double)LandSurf::GetDetailTiling(v7, 0);
    Render::SetLandscapeDetailTiling(tiling);
    v9 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
    v10 = (double)LandSurf::GetDetailTiling(v9, 2u);
    Render::SetEnvironmentDetailTiling(v10);
    v11 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
    v12 = (double)LandSurf::GetDetailTiling(v11, 1u);
    Render::SetBuildingDetailTiling(v12);
    v13 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
    v14 = (double)LandSurf::GetDetailTiling(v13, 3u);
    Render::SetObjectDetailTiling(v14);
    if ( landscape )
    {
      v15 = LScape::GenerateDetailSurface(0);
      v5->landscape_detail_surface = (CSurface *)v15;
      Render::SetLandscapeDetailSurface((CSurface *)v15);
    }
    if ( environment )
    {
      v16 = LScape::GenerateDetailSurface(2u);
      v5->environment_detail_surface = (CSurface *)v16;
      Render::SetEnvironmentDetailSurface((CSurface *)v16);
    }
    if ( building )
    {
      v17 = LScape::GenerateDetailSurface(1u);
      v5->building_detail_surface = (CSurface *)v17;
      Render::SetBuildingDetailSurface((CSurface *)v17);
    }
    if ( object )
    {
      v18 = LScape::GenerateDetailSurface(3u);
      v5->object_detail_surface = (CSurface *)v18;
      Render::SetObjectDetailSurface((CSurface *)v18);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00506CB0) --------------------------------------------------------  // acclient.c:308275
void __thiscall LScape::ChangeRegion(LScape *this)
{
  LScape::SetDetailTexturing(this, 0, (unsigned __int8)byte_81EF95, (unsigned __int8)byte_81EF95, 0);
}
// 81EF95: using guessed type char byte_81EF95;

//----- (00506CD0) --------------------------------------------------------  // acclient.c:308282
void __thiscall LScape::update_loadpoint(LScape *this, unsigned int cell_id)
{
  unsigned int v2; // ebp@1
  int v3; // ebx@1
  LScape *v4; // esi@1
  int v5; // eax@3
  CLandBlock **v6; // edx@3
  int v7; // edi@3
  int v8; // eax@4
  int v9; // ebp@5
  int v10; // eax@6
  CLandBlock **v11; // ecx@6
  unsigned int v12; // ST08_4@21
  int check_loading; // [sp+Ch] [bp-Ch]@3
  int x_shift; // [sp+10h] [bp-8h]@3
  int y_shift; // [sp+14h] [bp-4h]@3

  v2 = cell_id;
  v3 = 0;
  v4 = this;
  if ( cell_id )
  {
    v5 = LScape::get_block_shift(this->loaded_cell_id, cell_id, &x_shift, &y_shift);
    v6 = v4->land_blocks;
    v7 = v5 == 0;
    check_loading = 0;
    if ( v6 )
    {
      v8 = v4->mid_width;
      if ( v8 > 0 )
      {
        v9 = 4 * v8;
        while ( 2 )
        {
          v10 = 0;
          v11 = v6;
          do
          {
            if ( !*v11 )
            {
              check_loading = 1;
              goto LABEL_12;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v4->mid_width );
          ++v3;
          v6 = (CLandBlock **)((char *)v6 + v9);
          if ( v3 < v4->mid_width )
            continue;
          break;
        }
LABEL_12:
        v2 = cell_id;
      }
    }
    if ( x_shift || y_shift || !v4->land_blocks || v7 || check_loading )
    {
      LScape::update_block(v4, v2, x_shift, y_shift, v7);
      if ( (v2 ^ v4->loaded_cell_id) & 0xFFFF0000 )
        v7 = 1;
      v12 = v4->viewer_cell_id;
      v4->loaded_cell_id = v2;
      LScape::calc_draw_order(v4, v12, v7);
    }
    else
    {
      v4->loaded_cell_id = v2;
    }
  }
  else
  {
    LScape::release_all(this);
  }
}

//----- (006FA110) --------------------------------------------------------  // acclient.c:782749
int _E73_86()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_20, "Display.Resolution");
  return atexit(_E74_65);
}

//----- (006FA130) --------------------------------------------------------  // acclient.c:782756
int _E76_51()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_20, "Display.FullScreen");
  return atexit(_E77_79);
}

//----- (006FA150) --------------------------------------------------------  // acclient.c:782763
int _E79_44()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_20, "Display.RefreshRate");
  return atexit(_E80_43);
}

//----- (006FA170) --------------------------------------------------------  // acclient.c:782770
int _E82_27()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_20, "Display.SyncToRefresh");
  return atexit(_E83_27);
}

//----- (006FA190) --------------------------------------------------------  // acclient.c:782777
void _E101_5()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8417D4, PFID_A8R8G8B8);
}

//----- (006FA1A0) --------------------------------------------------------  // acclient.c:782783
void sub_6FA1A0()
{
  LODWORD(dword_84180C) = 1053364187;
}

//----- (006FA1B0) --------------------------------------------------------  // acclient.c:782789
void _E105_13()
{
  flt_841810 = 1000.0 + 1.0;
}

//----- (006FA1D0) --------------------------------------------------------  // acclient.c:782795
void _E107_7()
{
  flt_841814 = 24.0 * 8.0;
}

//----- (006FA1F0) --------------------------------------------------------  // acclient.c:782801
void _E109_56()
{
  flt_841818 = 24.0 * 0.5;
}

//----- (006FA210) --------------------------------------------------------  // acclient.c:782807
int _E111_35()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_20, "Render.TextureFiltering");
  return atexit(sub_765B50);
}

//----- (006FA230) --------------------------------------------------------  // acclient.c:782814
int _E114_41()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_20, "Render.LandscapeDetailTextures");
  return atexit(sub_765B80);
}

//----- (006FA250) --------------------------------------------------------  // acclient.c:782821
int _E117_53()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_20, "Render.BuildingDetailTextures");
  return atexit(sub_765BB0);
}

//----- (006FA270) --------------------------------------------------------  // acclient.c:782828
int _E120_48()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_20, "Render.FieldOfView");
  return atexit(sub_765BE0);
}

//----- (006FA290) --------------------------------------------------------  // acclient.c:782835
int _E123_25()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_20, "Render.LandscapeTextureDetail");
  return atexit(sub_765C10);
}

//----- (006FA2B0) --------------------------------------------------------  // acclient.c:782842
int _E126_30()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_20, "Render.EnvironmentTextureDetail");
  return atexit(sub_765C40);
}

//----- (006FA2D0) --------------------------------------------------------  // acclient.c:782849
int _E129_23()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_20, "Render.SceneryDrawDistance");
  return atexit(_E130_91);
}

//----- (006FA2F0) --------------------------------------------------------  // acclient.c:782856
int _E132_25()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_20, "Render.LandscapeDrawDistance");
  return atexit(_E133_84);
}

//----- (006FA310) --------------------------------------------------------  // acclient.c:782863
int _E135_28()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_20, "Render.ScreenBrightness");
  return atexit(_E136_67);
}

//----- (006FA330) --------------------------------------------------------  // acclient.c:782870
int _E138_21()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_20, "Render.AspectRatio");
  return atexit(_E139_68);
}

//----- (006FA350) --------------------------------------------------------  // acclient.c:782877
int _E141_21()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_20, "Render.DisplayAdapter");
  return atexit(_E142_63);
}

//----- (006FA370) --------------------------------------------------------  // acclient.c:782884
int _E144_20()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_20, "Render.MaxHardwareClass");
  return atexit(_E145_65);
}

//----- (006FA390) --------------------------------------------------------  // acclient.c:782891
int _E147_17()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_20, "Render.AutomaticDegrades");
  return atexit(_E148_63);
}

//----- (006FA3B0) --------------------------------------------------------  // acclient.c:782898
int _E150_20()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_20, "Render.GraphicsPerformance");
  return atexit(_E151_61);
}

//----- (006FA3D0) --------------------------------------------------------  // acclient.c:782905
int _E153_18()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_20, "Render.DegradeDistance");
  return atexit(_E154_62);
}

//----- (006FA3F0) --------------------------------------------------------  // acclient.c:782912
int _E156_20()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_20, "Render.MultiPassAlpha");
  return atexit(_E157_58);
}

//----- (006FA410) --------------------------------------------------------  // acclient.c:782919
int _E159_18()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_20, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_841864, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_841868, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_84186C, "Anisotropic");
  return atexit(_E160_61);
}

//----- (006FA460) --------------------------------------------------------  // acclient.c:782929
int _E162_20()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_20, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_841874, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841878, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_84187C, "High");
  PStringBase<char>::PStringBase<char>(&stru_841880, "VeryHigh");
  return atexit(_E163_54);
}

//----- (006FA4C0) --------------------------------------------------------  // acclient.c:782940
int _E165_16()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_20, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_841888, "Low");
  PStringBase<char>::PStringBase<char>(&stru_84188C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841890, "High");
  PStringBase<char>::PStringBase<char>(&stru_841894, "VeryHigh");
  return atexit(_E166_56);
}

//----- (006FA520) --------------------------------------------------------  // acclient.c:782951
int _E168_17()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_20, "Low");
  PStringBase<char>::PStringBase<char>(&stru_84189C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8418A0, "High");
  return atexit(_E169_55);
}

//----- (006FA560) --------------------------------------------------------  // acclient.c:782960
int _E171_16()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_20, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8418A8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8418AC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8418B0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8418B4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8418B8, "Extreme");
  return atexit(_E172_53);
}

//----- (006FA5D0) --------------------------------------------------------  // acclient.c:782972
int _E174_17()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_20, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8418C0, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8418C4, "Wide");
  return atexit(_E175_50);
}

//----- (006FA610) --------------------------------------------------------  // acclient.c:782981
int _E177_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_44, "None");
  return atexit(_E178_50);
}

//----- (006FA630) --------------------------------------------------------  // acclient.c:782988
int _E180_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_44, "Speed");
  return atexit(_E181_50);
}

//----- (006FA650) --------------------------------------------------------  // acclient.c:782995
int _E183_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_44, "Noise");
  return atexit(_E184_47);
}

//----- (006FA670) --------------------------------------------------------  // acclient.c:783002
int _E186_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_44, "Sine");
  return atexit(_E187_46);
}

//----- (006FA690) --------------------------------------------------------  // acclient.c:783009
int _E189_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_44, "Square");
  return atexit(_E190_47);
}

//----- (006FA6B0) --------------------------------------------------------  // acclient.c:783016
int _E192_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_44, "Bounce");
  return atexit(_E193_42);
}

//----- (006FA6D0) --------------------------------------------------------  // acclient.c:783023
int _E195_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_44, "Perlin");
  return atexit(_E196_49);
}

//----- (006FA6F0) --------------------------------------------------------  // acclient.c:783030
int _E198_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_44, "Fractal");
  return atexit(_E199_41);
}

//----- (006FA710) --------------------------------------------------------  // acclient.c:783037
int _E201_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_44, "FrameLoop");
  return atexit(_E202_42);
}

//----- (006FA730) --------------------------------------------------------  // acclient.c:783044
void _E204_7()
{
  DEFAULT_VIEW_RADIUS_90 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FA750) --------------------------------------------------------  // acclient.c:783050
void _E206_4()
{
  MIN_QUANTUM_90 = 1.0 / 30.0;
}

//----- (006FA770) --------------------------------------------------------  // acclient.c:783056
void _E208_16()
{
  MAX_QUANTUM_90 = 1.0 / 5.0;
}

//----- (006FA790) --------------------------------------------------------  // acclient.c:783062
int _E210_7()
{
  return atexit(_E211_37);
}

//----- (006FA7A0) --------------------------------------------------------  // acclient.c:783068
int _E213_5()
{
  return atexit(_E214_40);
}

//----- (006FA7B0) --------------------------------------------------------  // acclient.c:783074
int _E216_7()
{
  return atexit(_E217_37);
}

//----- (006FA7C0) --------------------------------------------------------  // acclient.c:783080
void _E219_4()
{
  dword_841900 = 1024;
}

//----- (006FA7D0) --------------------------------------------------------  // acclient.c:783086
void _E221_0()
{
  dword_841904 = 0x7FFF;
}

//----- (006FA7E0) --------------------------------------------------------  // acclient.c:783092
int _E223_12()
{
  const int result; // eax@1

  result = dword_841900;
  INITIAL_MAX_DATA_RATE_62 = dword_841900;
  return result;
}

//----- (006FA7F0) --------------------------------------------------------  // acclient.c:783102
int _E225_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_12, "Sound.SoundDisabled");
  return atexit(_E226_23);
}

//----- (006FA810) --------------------------------------------------------  // acclient.c:783109
int _E228_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_12, "Sound.SoundVolume");
  return atexit(_E229_23);
}

//----- (006FA830) --------------------------------------------------------  // acclient.c:783116
int _E231_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_12, "Sound.AmbientSoundDisabled");
  return atexit(_E232_23);
}

//----- (006FA850) --------------------------------------------------------  // acclient.c:783123
int _E234_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_12, "Sound.AmbientSoundVolume");
  return atexit(_E235_23);
}

//----- (006FA870) --------------------------------------------------------  // acclient.c:783130
int _E237_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_12, "Sound.InterfaceSoundDisabled");
  return atexit(_E238_21);
}

//----- (006FA890) --------------------------------------------------------  // acclient.c:783137
int _E240_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_12, "Sound.InterfaceSoundVolume");
  return atexit(_E241_21);
}

//----- (006FA8B0) --------------------------------------------------------  // acclient.c:783144
int _E243_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_12, "Sound.SoundFeatures");
  return atexit(_E244_21);
}

//----- (006FA8D0) --------------------------------------------------------  // acclient.c:783151
int _E246_4()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_12, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E247_20);
}

//----- (006FA8F0) --------------------------------------------------------  // acclient.c:783158
int _E249_4()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_12, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_841930, "Mono");
  return atexit(_E250_20);
}

//----- (006FA920) --------------------------------------------------------  // acclient.c:783166
void _E252_4()
{
  VOL_MIN_DIST_SQ_9 = 5.0 * 5.0;
}

//----- (006FA940) --------------------------------------------------------  // acclient.c:783172
void _E254_1()
{
  INV_LOG_OF_2_9 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006FA960) --------------------------------------------------------  // acclient.c:783178
float _E258_3()
{
  const float result; // eax@1

  result = LSCAPE_LIGHT_MINIMUM;
  LScape::min_ambient = LSCAPE_LIGHT_MINIMUM;
  return result;
}
// 84194C: using guessed type float LScape::min_ambient;

//----- (006FA970) --------------------------------------------------------  // acclient.c:783189
int sub_6FA970()
{
  return atexit(nullsub_1068);
}

//----- (007658D0) --------------------------------------------------------  // acclient.c:892108
void __cdecl _E226_23()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765900) --------------------------------------------------------  // acclient.c:892121
void __cdecl _E229_23()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765930) --------------------------------------------------------  // acclient.c:892134
void __cdecl _E232_23()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765960) --------------------------------------------------------  // acclient.c:892147
void __cdecl _E235_23()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765990) --------------------------------------------------------  // acclient.c:892160
void __cdecl _E238_21()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007659C0) --------------------------------------------------------  // acclient.c:892173
void __cdecl _E241_21()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007659F0) --------------------------------------------------------  // acclient.c:892186
void __cdecl _E244_21()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765A20) --------------------------------------------------------  // acclient.c:892199
void __cdecl _E247_20()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765A50) --------------------------------------------------------  // acclient.c:892212
void __cdecl _E250_20()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_9;
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

//----- (00765A90) --------------------------------------------------------  // acclient.c:892237
void __cdecl _E74_65()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765AC0) --------------------------------------------------------  // acclient.c:892250
void __cdecl _E77_79()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765AF0) --------------------------------------------------------  // acclient.c:892263
void __cdecl _E80_43()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765B20) --------------------------------------------------------  // acclient.c:892276
void __cdecl _E83_27()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765B50) --------------------------------------------------------  // acclient.c:892289
void __cdecl sub_765B50()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765B80) --------------------------------------------------------  // acclient.c:892302
void __cdecl sub_765B80()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765BB0) --------------------------------------------------------  // acclient.c:892315
void __cdecl sub_765BB0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765BE0) --------------------------------------------------------  // acclient.c:892328
void __cdecl sub_765BE0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765C10) --------------------------------------------------------  // acclient.c:892341
void __cdecl sub_765C10()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765C40) --------------------------------------------------------  // acclient.c:892354
void __cdecl sub_765C40()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765C70) --------------------------------------------------------  // acclient.c:892367
void __cdecl _E130_91()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765CA0) --------------------------------------------------------  // acclient.c:892380
void __cdecl _E133_84()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765CD0) --------------------------------------------------------  // acclient.c:892393
void __cdecl _E136_67()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765D00) --------------------------------------------------------  // acclient.c:892406
void __cdecl _E139_68()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765D30) --------------------------------------------------------  // acclient.c:892419
void __cdecl _E142_63()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765D60) --------------------------------------------------------  // acclient.c:892432
void __cdecl _E145_65()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765D90) --------------------------------------------------------  // acclient.c:892445
void __cdecl _E148_63()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765DC0) --------------------------------------------------------  // acclient.c:892458
void __cdecl _E151_61()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765DF0) --------------------------------------------------------  // acclient.c:892471
void __cdecl _E154_62()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765E20) --------------------------------------------------------  // acclient.c:892484
void __cdecl _E157_58()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765E50) --------------------------------------------------------  // acclient.c:892497
void __cdecl _E160_61()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_20;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00765E90) --------------------------------------------------------  // acclient.c:892522
void __cdecl _E163_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_20;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00765ED0) --------------------------------------------------------  // acclient.c:892547
void __cdecl _E166_56()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_20;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00765F10) --------------------------------------------------------  // acclient.c:892572
void __cdecl _E169_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_20;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00765F50) --------------------------------------------------------  // acclient.c:892597
void __cdecl _E172_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_20;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00765F90) --------------------------------------------------------  // acclient.c:892622
void __cdecl _E175_50()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_44;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00765FD0) --------------------------------------------------------  // acclient.c:892647
void __cdecl _E178_50()
{
  char *v0; // esi@1

  v0 = &waveform_None_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766000) --------------------------------------------------------  // acclient.c:892660
void __cdecl _E181_50()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766030) --------------------------------------------------------  // acclient.c:892673
void __cdecl _E184_47()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766060) --------------------------------------------------------  // acclient.c:892686
void __cdecl _E187_46()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766090) --------------------------------------------------------  // acclient.c:892699
void __cdecl _E190_47()
{
  char *v0; // esi@1

  v0 = &waveform_Square_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007660C0) --------------------------------------------------------  // acclient.c:892712
void __cdecl _E193_42()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007660F0) --------------------------------------------------------  // acclient.c:892725
void __cdecl _E196_49()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766120) --------------------------------------------------------  // acclient.c:892738
void __cdecl _E199_41()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766150) --------------------------------------------------------  // acclient.c:892751
void __cdecl _E202_42()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

