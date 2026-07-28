/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LandDefs
   Object     : PORTAL\geometry\LandDefs.obj
   Functions  : 10
   Addresses  : 005A9980 - 0070D900 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A9980) --------------------------------------------------------  // acclient.c:467308
void __cdecl LandDefs::get_vars(int *_height, int *_width, float *_cell_size, int *_cells_per_block, int *_cell_sub_divide, float *_max_obj_height, float *_sky_height, float *_road_width)
{
  *_height = 255;
  *_width = 255;
  *_cell_size = 24.0;
  *_cells_per_block = 8;
  *_cell_sub_divide = 1;
  *_max_obj_height = 200.0;
  *_sky_height = 1000.0;
  *_road_width = 5.0;
}

//----- (005A99E0) --------------------------------------------------------  // acclient.c:467321
int __cdecl LandDefs::set_height_table(float *height_table)
{
  float *v1; // ecx@1
  unsigned int v2; // edx@1

  v1 = height_table;
  v2 = 0;
  while ( *v1 >= 0.0 && 1000.0 - 200.0 >= *v1 )
  {
    *(_DWORD *)((char *)v1 + (char *)&LandDefs::Land_Height_Table - (char *)height_table) = *(_DWORD *)v1;
    ++v2;
    ++v1;
    if ( v2 >= 0x100 )
      return 1;
  }
  return 0;
}
// 8EDA28: using guessed type float *LandDefs::Land_Height_Table;

//----- (005A9A30) --------------------------------------------------------  // acclient.c:467341
double __cdecl LandDefs::heading(LandDefs::Direction dir)
{
  double result; // st7@2

  switch ( dir )
  {
    case 2:
      result = 3.1415927;
      break;
    case 3:
      result = 1.5707964;
      break;
    case 4:
      result = 4.712389;
      break;
    case 7:
      result = 0.78539819;
      break;
    case 8:
      result = 2.3561945;
      break;
    case 6:
      result = 3.9269907;
      break;
    case 5:
      result = 5.497787;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

//----- (005A9AA0) --------------------------------------------------------  // acclient.c:467376
int __cdecl LandDefs::get_dir(int ix, int iy)
{
  int result; // eax@3

  if ( ix >= 0 )
  {
    if ( ix <= 0 )
    {
      if ( iy >= 0 )
        result = iy > 0;
      else
        result = 2;
    }
    else if ( iy >= 0 )
    {
      result = 4 * (iy > 0) + 3;
    }
    else
    {
      result = 8;
    }
  }
  else if ( iy >= 0 )
  {
    result = (iy > 0) + 4;
  }
  else
  {
    result = 6;
  }
  return result;
}

//----- (005A9B00) --------------------------------------------------------  // acclient.c:467410
int __cdecl LandDefs::get_outside_lcoord(unsigned int cell_id, AC1Legacy::Vector3 *loc, int *x, int *y)
{
  int v4; // ecx@6
  int result; // eax@10

  if ( ((unsigned __int16)cell_id < 1u || (unsigned __int16)cell_id > 0x40u)
    && ((unsigned __int16)cell_id < 0x100u || (unsigned __int16)cell_id > 0xFFFDu)
    && (unsigned __int16)cell_id != 0xFFFF )
  {
    result = 0;
  }
  else
  {
    LandDefs::blockid_to_lcoord(cell_id, x, y);
    *x += (unsigned __int64)_floor(loc->x / 24.0);
    v4 = (unsigned __int64)_floor(loc->y / 24.0) + *y;
    *y = v4;
    result = *x >= 0 && v4 >= 0 && *x < 2040 && v4 < 2040;
  }
  return result;
}

//----- (005A9BC0) --------------------------------------------------------  // acclient.c:467433
int __cdecl LandDefs::adjust_to_outside(unsigned int *cell_id, AC1Legacy::Vector3 *loc)
{
  int v2; // ecx@0
  unsigned int *v3; // edi@1
  unsigned int v4; // eax@1
  AC1Legacy::Vector3 *v5; // esi@6
  double v6; // st7@11
  int result; // eax@11
  int x; // [sp+10h] [bp-4h]@1

  x = v2;
  v3 = cell_id;
  v4 = *cell_id & 0xFFFF;
  if ( (v4 < 1 || v4 > 0x40) && (v4 < 0x100 || v4 > 0xFFFD) && v4 != 0xFFFF )
    goto LABEL_15;
  v5 = loc;
  if ( fabs(loc->x) < 0.00019999999 )
    LODWORD(loc->x) = 0;
  if ( fabs(v5->y) < 0.00019999999 )
    LODWORD(v5->y) = 0;
  if ( LandDefs::get_outside_lcoord(*v3, v5, &x, (int *)&cell_id) )
  {
    *v3 = LandDefs::lcoord_to_gid(x, (int)cell_id);
    v5->x = v5->x - _floor(v5->x / flt_8EDE44) * flt_8EDE44;
    v6 = _floor(v5->y / flt_8EDE44);
    result = 1;
    v5->y = v5->y - v6 * flt_8EDE44;
  }
  else
  {
LABEL_15:
    *v3 = 0;
    result = 0;
  }
  return result;
}

//----- (005A9CB0) --------------------------------------------------------  // acclient.c:467471
AC1Legacy::PStringBase<char> *__cdecl LandDefs::CellidToCoordinateString(AC1Legacy::PStringBase<char> *result, const unsigned int cellID)
{
  long double v2; // st7@1
  long double v3; // st6@1
  char *v4; // ecx@2
  char *v5; // eax@6
  unsigned __int64 v6; // st7@9
  AC1Legacy::PSRefBuffer<char> *v7; // edi@9
  volatile LONG *v8; // esi@9
  volatile LONG *v9; // ST1C_4@9
  AC1Legacy::PStringBase<char> coordString; // [sp+28h] [bp-Ch]@1
  int worldLocY; // [sp+2Ch] [bp-8h]@1
  int worldLocX; // [sp+30h] [bp-4h]@1

  coordString.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  LandDefs::gid_to_lcoord(cellID, &worldLocX, &worldLocY);
  worldLocY -= 1024;
  worldLocX -= 1024;
  v2 = (double)worldLocY * 0.1 + 0.5;
  v3 = (double)worldLocX * 0.1 + 0.5;
  if ( v3 >= 0.0 )
  {
    v4 = "E";
    if ( v3 <= 0.0 )
      v4 = &name;
  }
  else
  {
    v4 = "W";
  }
  if ( v2 >= 0.0 )
  {
    v5 = "N";
    if ( v2 <= 0.0 )
      v5 = &name;
  }
  else
  {
    v5 = "S";
  }
  *(double *)&v6 = fabs(v2);
  AC1Legacy::PStringBase<char>::sprintf(&coordString, "%.1f%s, %.1f%s", v6, v6 >> 32, v5, fabs(v3), v4);
  v7 = coordString.m_buffer;
  v8 = (volatile LONG *)&coordString.m_buffer->m_cRef;
  v9 = (volatile LONG *)&coordString.m_buffer->m_cRef;
  result->m_buffer = coordString.m_buffer;
  InterlockedIncrement(v9);
  if ( !InterlockedDecrement(v8) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070D8C0) --------------------------------------------------------  // acclient.c:800509
void sub_70D8C0()
{
  flt_8EDE40 = 1000.0 + 1.0;
}

//----- (0070D8E0) --------------------------------------------------------  // acclient.c:800515
void sub_70D8E0()
{
  flt_8EDE44 = 24.0 * 8.0;
}

//----- (0070D900) --------------------------------------------------------  // acclient.c:800521
void sub_70D900()
{
  flt_8EDE48 = 24.0 * 0.5;
}

