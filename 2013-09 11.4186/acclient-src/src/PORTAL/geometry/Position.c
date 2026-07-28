/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Position
   Object     : PORTAL\geometry\Position.obj
   Functions  : 21
   Addresses  : 00526850 - 0070D8B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526850) --------------------------------------------------------  // acclient.c:342041
signed int NoDrawHook::GetType()
{
  return 16;
}

//----- (005A9330) --------------------------------------------------------  // acclient.c:466942
char *__thiscall Position::ToString(Position *this, char *buf, const unsigned int size)
{
  char *result; // eax@1

  result = buf;
  if ( buf )
    result = (char *)__snprintf(
                       buf,
                       size,
                       "0x%08X [%f %f %f] %f %f %f %f",
                       this->objcell_id,
                       this->frame.m_fOrigin.x,
                       this->frame.m_fOrigin.y,
                       this->frame.m_fOrigin.z,
                       this->frame.qw,
                       this->frame.qx,
                       this->frame.qy,
                       this->frame.qz);
  return result;
}

//----- (005A93B0) --------------------------------------------------------  // acclient.c:466964
int __thiscall Position::FromString(Position *this, const char *const buf)
{
  Position *v2; // esi@1
  int v3; // eax@2
  int result; // eax@4
  Frame *v5; // esi@5
  Frame *v6; // esi@6
  float f4; // [sp+4h] [bp-Ch]@2
  float f3; // [sp+8h] [bp-8h]@2
  float f2; // [sp+Ch] [bp-4h]@2

  v2 = this;
  if ( !buf )
    return 0;
  v3 = _sscanf(
         buf,
         "0x%08X [%f %f %f] %f %f %f %f",
         &this->objcell_id,
         &this->frame.m_fOrigin,
         &this->frame.m_fOrigin.y,
         &this->frame.m_fOrigin.z,
         &buf,
         &f2,
         &f3,
         &f4);
  if ( v3 == 5 )
  {
    v6 = &v2->frame;
    Frame::set_heading(v6, *(float *)&buf);
    Frame::cache(v6);
    result = 1;
  }
  else
  {
    if ( v3 != 8 )
      return 0;
    v5 = &v2->frame;
    Frame::set_rotate(v5, *(float *)&buf, f2, f3, f4);
    Frame::cache(v5);
    result = 1;
  }
  return result;
}

//----- (005A9460) --------------------------------------------------------  // acclient.c:467009
int __thiscall Position::pack_size(Position *this)
{
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = 0;
  return Frame::Pack(&this->frame, &dummy, 0) + 4;
}

//----- (005A9480) --------------------------------------------------------  // acclient.c:467018
int __thiscall Position::IsValid(Position *this)
{
  Position *v1; // esi@1
  int result; // eax@1

  v1 = this;
  result = LandDefs::inbound_valid_cellid(this->objcell_id);
  if ( result )
    result = Frame::IsValid(&v1->frame) != 0;
  return result;
}

//----- (005A94B0) --------------------------------------------------------  // acclient.c:467031
double __thiscall Position::distance(Position *this, Position *p)
{
  AC1Legacy::Vector3 *v2; // eax@1
  AC1Legacy::Vector3 result; // [sp+0h] [bp-Ch]@1

  v2 = Position::get_offset(this, &result, p);
  return sqrt(v2->x * v2->x + v2->y * v2->y + v2->z * v2->z);
}

//----- (005A94F0) --------------------------------------------------------  // acclient.c:467041
double __thiscall Position::xy_distance(Position *this, Position *p)
{
  AC1Legacy::Vector3 v; // [sp+0h] [bp-Ch]@1

  Position::get_offset(this, &v, p);
  return sqrt(v.y * v.y + v.x * v.x);
}

//----- (005A9520) --------------------------------------------------------  // acclient.c:467050
double __thiscall Position::heading(Position *this, Position *p)
{
  double result; // st7@2
  AC1Legacy::Vector3 direction; // [sp+0h] [bp-Ch]@1

  Position::get_offset(this, &direction, p);
  LODWORD(direction.z) = 0;
  if ( AC1Legacy::Vector3::normalize_check_small(&direction) )
    result = 0.0;
  else
    result = fmod(450.0 - atan2(direction.x, direction.y) * 57.29577951308232, 360.0);
  return result;
}

//----- (005A9580) --------------------------------------------------------  // acclient.c:467065
int __thiscall Position::determine_quadrant(Position *this, float height, Position *p)
{
  signed int v3; // ecx@1
  int v4; // ecx@4
  int result; // eax@7
  AC1Legacy::Vector3 hitpoint; // [sp+0h] [bp-18h]@1
  AC1Legacy::Vector3 v; // [sp+Ch] [bp-Ch]@1

  LODWORD(v.x) = 0;
  LODWORD(v.y) = 0;
  LODWORD(v.z) = 0;
  Position::localtolocal(this, &hitpoint, p, &v);
  v3 = 8;
  if ( hitpoint.x >= 0.0 )
    v3 = 16;
  if ( hitpoint.y >= 0.0 )
    v4 = v3 | 0x20;
  else
    v4 = v3 | 0x40;
  if ( height * 0.333333333 <= hitpoint.z )
  {
    if ( height * 0.66666667 <= hitpoint.z )
      result = v4 | 1;
    else
      result = v4 | 2;
  }
  else
  {
    result = v4 | 4;
  }
  return result;
}

//----- (005A9640) --------------------------------------------------------  // acclient.c:467099
unsigned int __thiscall Position::Pack(Position *this, void **addr, unsigned int size)
{
  Position *v3; // edi@1
  Frame *v4; // ebx@1
  unsigned int v5; // esi@1
  void *v7; // [sp+0h] [bp-4h]@1

  v3 = this;
  v4 = &this->frame;
  v7 = 0;
  v5 = Frame::Pack(&this->frame, &v7, 0) + 4;
  if ( size >= v5 )
  {
    *(_DWORD *)*addr = v3->objcell_id;
    *addr = (char *)*addr + 4;
    Frame::Pack(v4, addr, size);
  }
  return v5;
}

//----- (005A9690) --------------------------------------------------------  // acclient.c:467120
int __thiscall Position::UnPack(Position *this, void **addr, unsigned int size)
{
  Position *v3; // esi@1
  Frame *v4; // edi@1
  int result; // eax@2
  void *v6; // [sp+0h] [bp-4h]@1

  v3 = this;
  v4 = &this->frame;
  v6 = 0;
  if ( size >= Frame::Pack(&this->frame, &v6, 0) + 4 )
  {
    v3->objcell_id = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = Frame::UnPack(v4, addr, size);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A96F0) --------------------------------------------------------  // acclient.c:467144
void __thiscall Position::Serialize(Position *this, Archive *io_archive)
{
  Position *v2; // esi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v3 = v2->objcell_id;
      Frame::Serialize(&v2->frame, io_archive);
      return;
    }
    v2->objcell_id = *(_DWORD *)v3;
  }
  Frame::Serialize(&v2->frame, io_archive);
}

//----- (005A9740) --------------------------------------------------------  // acclient.c:467166
signed int __thiscall Position::PackOrigin(Position *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@3
  char *v5; // edx@3

  if ( size >= 0x10 )
  {
    *(_DWORD *)*addr = this->objcell_id;
    v3 = (char *)*addr + 4;
    *addr = v3;
    if ( size >= 0xC )
    {
      *(_DWORD *)v3 = LODWORD(this->frame.m_fOrigin.x);
      v4 = (char *)*addr + 4;
      *addr = v4;
      *(float *)v4 = this->frame.m_fOrigin.y;
      v5 = (char *)*addr + 4;
      *addr = v5;
      *(float *)v5 = this->frame.m_fOrigin.z;
      *addr = (char *)*addr + 4;
    }
  }
  return 16;
}

//----- (005A9790) --------------------------------------------------------  // acclient.c:467193
int __thiscall Position::UnPackOrigin(Position *this, void **addr, unsigned int size)
{
  float *v3; // edx@2
  int result; // eax@3
  char *v5; // esi@4
  char *v6; // edx@4

  if ( size >= 0x10 && (this->objcell_id = *(_DWORD *)*addr, v3 = (float *)((char *)*addr + 4), *addr = v3, size >= 0xC) )
  {
    LODWORD(this->frame.m_fOrigin.x) = *(_DWORD *)v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->frame.m_fOrigin.y) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(this->frame.m_fOrigin.z) = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A97F0) --------------------------------------------------------  // acclient.c:467220
double __cdecl Position::cylinder_distance(float r1, float h1, Position *p1, float r2, float h2, Position *p2)
{
  Position *v6; // esi@1
  AC1Legacy::Vector3 *v7; // eax@1
  double v8; // st7@1
  double v9; // st6@1
  double v10; // st6@2
  double v11; // st7@4
  __int16 v12; // fps@4
  char v13; // ah@4
  bool v14; // c0@4
  bool v15; // c3@4
  AC1Legacy::Vector3 result; // [sp+8h] [bp-Ch]@1
  float p2a; // [sp+2Ch] [bp+18h]@1

  v6 = p2;
  v7 = Position::get_offset(p1, &result, p2);
  p2a = sqrt(v7->x * v7->x + v7->y * v7->y + v7->z * v7->z) - (r1 + r2);
  v8 = p1->frame.m_fOrigin.z;
  v9 = v6->frame.m_fOrigin.z;
  if ( v8 <= v9 )
  {
    v8 = v6->frame.m_fOrigin.z;
    v10 = p1->frame.m_fOrigin.z + h1;
  }
  else
  {
    v10 = v9 + h2;
  }
  v11 = v8 - v10;
  v13 = HIBYTE(v12);
  v14 = p2a < 0.0;
  v15 = p2a == 0.0;
  if ( v13 & 0x41 )
  {
    if ( v14 || v15 )
      v11 = -sqrt(v11 * v11 + p2a * p2a);
    else
      v11 = p2a;
  }
  else if ( !v14 && !v15 )
  {
    v11 = sqrt(v11 * v11 + p2a * p2a);
  }
  return v11;
}

//----- (005A98B0) --------------------------------------------------------  // acclient.c:467268
double __cdecl Position::cylinder_distance_no_z(float r1, Position *p1, float r2, Position *p2)
{
  AC1Legacy::Vector3 *v4; // eax@1
  AC1Legacy::Vector3 result; // [sp+0h] [bp-Ch]@1

  v4 = Position::get_offset(p1, &result, p2);
  return sqrt(v4->x * v4->x + v4->y * v4->y + v4->z * v4->z) - (r1 + r2);
}

//----- (005A9900) --------------------------------------------------------  // acclient.c:467278
PStringBase<char> *__thiscall Position::ToDisplayString(Position *this, PStringBase<char> *result)
{
  Position *v2; // esi@1
  double v3; // ST28_8@1
  PSRefBufferCharData<char> *v4; // eax@1
  char *v5; // esi@1
  PStringBase<char> strResult; // [sp+28h] [bp-4h]@1

  strResult.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v2 = this;
  v3 = Frame::get_heading(&this->frame);
  PStringBase<char>::PStringBase<char>(
    &strResult,
    0,
    "0x%08X [%0.2f %0.2f %0.2f] %0.2f",
    v2->objcell_id,
    v2->frame.m_fOrigin.x,
    v2->frame.m_fOrigin.y,
    v2->frame.m_fOrigin.z,
    v3);
  v4 = strResult.m_charbuffer;
  result->m_charbuffer = strResult.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v4[-1]);
  v5 = &strResult.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strResult.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return result;
}

//----- (0070D850) --------------------------------------------------------  // acclient.c:800485
void sub_70D850()
{
  flt_8EDA14 = 1000.0 + 1.0;
}

//----- (0070D870) --------------------------------------------------------  // acclient.c:800491
void sub_70D870()
{
  flt_8EDA18 = 24.0 * 8.0;
}

//----- (0070D890) --------------------------------------------------------  // acclient.c:800497
void sub_70D890()
{
  flt_8EDA1C = 24.0 * 0.5;
}

//----- (0070D8B0) --------------------------------------------------------  // acclient.c:800503
int sub_70D8B0()
{
  return atexit(nullsub_1533);
}

