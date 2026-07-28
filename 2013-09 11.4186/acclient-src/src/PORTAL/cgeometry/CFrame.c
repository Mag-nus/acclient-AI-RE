/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CFrame
   Object     : PORTAL\cgeometry\CFrame.obj
   Functions  : 20
   Addresses  : 00534D70 - 00535E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00534D70) --------------------------------------------------------  // acclient.c:356963
void __cdecl EulGetOrd(int _order, int *i, int *j, int *k, int *h, int *n, int *s, int *f)
{
  int v8; // eax@1
  int v9; // eax@1

  *f = _order & 1;
  *s = ((unsigned int)_order >> 1) & 1;
  *n = ((unsigned int)_order >> 2) & 1;
  v8 = byte_7C96C4[((unsigned int)_order >> 3) & 3];
  *i = v8;
  *j = *(&byte_7C96BC[*n] + v8);
  v9 = byte_7C96BD[*i - *n];
  *k = v9;
  if ( *s )
    *h = v9;
  else
    *h = *i;
}

//----- (00534DF0) --------------------------------------------------------  // acclient.c:356983
void __thiscall Frame::cache(Frame *this)
{
  long double b2; // ST08_8@1
  long double c2; // ST00_8@1
  double v3; // st7@1
  long double v4; // st6@1
  long double v5; // st5@1
  double v6; // st4@1
  long double v7; // st3@1
  long double v8; // st2@1
  long double bd2; // ST10_8@1
  long double cc2; // ST20_8@1
  long double v11; // ST00_8@1
  long double v12; // ST08_8@1
  long double v13; // ST18_8@1

  b2 = this->qx + this->qx;
  c2 = this->qy + this->qy;
  v3 = this->qz + this->qz;
  v4 = this->qw * b2;
  v5 = this->qw * c2;
  v6 = this->qw * v3;
  v7 = this->qx * b2;
  v8 = this->qx * c2;
  bd2 = this->qx * v3;
  cc2 = this->qy * c2;
  v11 = this->qy * v3;
  v12 = this->qz * v3;
  this->m_fl2gv[0] = 1.0 - cc2 - v12;
  this->m_fl2gv[1] = v8 + v6;
  this->m_fl2gv[2] = bd2 - v5;
  this->m_fl2gv[3] = v8 - v6;
  v13 = 1.0 - v7;
  this->m_fl2gv[4] = v13 - v12;
  this->m_fl2gv[5] = v11 + v4;
  this->m_fl2gv[6] = bd2 + v5;
  this->m_fl2gv[7] = v11 - v4;
  this->m_fl2gv[8] = v13 - cc2;
}

//----- (00534ED0) --------------------------------------------------------  // acclient.c:357024
int __thiscall Frame::IsValid(Frame *this)
{
  Frame *v1; // esi@1
  signed int v2; // ebx@1
  int result; // eax@11
  float norm; // [sp+14h] [bp-4h]@9

  v1 = this;
  v2 = 1;
  if ( __isnan(this->m_fOrigin.x)
    || __isnan(v1->m_fOrigin.y)
    || __isnan(v1->m_fOrigin.z)
    || __isnan(v1->qw)
    || __isnan(v1->qx)
    || __isnan(v1->qy)
    || __isnan(v1->qz) )
    v2 = 0;
  norm = v1->qz * v1->qz + v1->qy * v1->qy + v1->qx * v1->qx + v1->qw * v1->qw;
  if ( __isnan(norm) || 0.00019999999 * 5.0 < fabs(norm - 1.0) )
    result = 0;
  else
    result = v2;
  return result;
}

//----- (00534FE0) --------------------------------------------------------  // acclient.c:357050
BOOL __thiscall Frame::IsValidExceptForHeading(Frame *this)
{
  Frame *v1; // esi@1

  v1 = this;
  return !__isnan(this->m_fOrigin.x)
      && !__isnan(v1->m_fOrigin.y)
      && !__isnan(v1->m_fOrigin.z)
      && (__isnan(v1->qw) || __isnan(v1->qx) || __isnan(v1->qy) || __isnan(v1->qz));
}

//----- (00535080) --------------------------------------------------------  // acclient.c:357062
void __thiscall Frame::set_rotate(Frame *this, float new_qw, float new_qx, float new_qy, float new_qz)
{
  Frame *v5; // esi@1
  long double v6; // st7@1
  float oldqw; // [sp+0h] [bp-10h]@1
  float oldqx; // [sp+4h] [bp-Ch]@1
  float oldqy; // [sp+8h] [bp-8h]@1
  float oldqz; // [sp+Ch] [bp-4h]@1

  v5 = this;
  oldqw = this->qw;
  oldqx = this->qx;
  oldqy = this->qy;
  oldqz = this->qz;
  v6 = 1.0 / sqrt(new_qw * new_qw + new_qx * new_qx + new_qy * new_qy + new_qz * new_qz);
  this->qw = new_qw * v6;
  this->qx = new_qx * v6;
  this->qy = new_qy * v6;
  this->qz = v6 * new_qz;
  if ( Frame::IsValid(this) )
  {
    Frame::cache(v5);
  }
  else
  {
    v5->qw = oldqw;
    v5->qx = oldqx;
    v5->qy = oldqy;
    v5->qz = oldqz;
  }
}

//----- (00535130) --------------------------------------------------------  // acclient.c:357095
signed int __thiscall Frame::Pack(Frame *this, void **addr, unsigned int size)
{
  char *v3; // edx@3
  char *v4; // esi@3
  char *v5; // edx@4
  char *v6; // esi@4
  char *v7; // edx@4

  if ( size >= 0x1C )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(this->m_fOrigin.x);
      v3 = (char *)*addr + 4;
      *addr = v3;
      *(float *)v3 = this->m_fOrigin.y;
      v4 = (char *)*addr + 4;
      *addr = v4;
      *(float *)v4 = this->m_fOrigin.z;
      *addr = (char *)*addr + 4;
    }
    *(_DWORD *)*addr = LODWORD(this->qw);
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->qx;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = this->qy;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = this->qz;
    *addr = (char *)*addr + 4;
  }
  return 28;
}

//----- (005351A0) --------------------------------------------------------  // acclient.c:357132
int __thiscall Frame::UnPack(Frame *this, void **addr, unsigned int size)
{
  Frame *v3; // esi@1
  char *v4; // ecx@3
  char *v5; // edx@3
  char *v6; // ecx@3
  char *v7; // ecx@3
  char *v8; // edx@3
  char *v9; // ecx@3
  int result; // eax@4

  v3 = this;
  if ( size >= 0x1C
    && size >= 0xC
    && (LODWORD(this->m_fOrigin.x) = *(_DWORD *)*addr,
        v4 = (char *)*addr + 4,
        *addr = v4,
        LODWORD(v3->m_fOrigin.y) = *(_DWORD *)v4,
        v5 = (char *)*addr + 4,
        *addr = v5,
        LODWORD(v3->m_fOrigin.z) = *(_DWORD *)v5,
        v6 = (char *)*addr + 4,
        *addr = v6,
        LODWORD(v3->qw) = *(_DWORD *)v6,
        v7 = (char *)*addr + 4,
        *addr = v7,
        LODWORD(v3->qx) = *(_DWORD *)v7,
        v8 = (char *)*addr + 4,
        *addr = v8,
        LODWORD(v3->qy) = *(_DWORD *)v8,
        v9 = (char *)*addr + 4,
        *addr = v9,
        LODWORD(v3->qz) = *(_DWORD *)v9,
        *addr = (char *)*addr + 4,
        Frame::IsValid(v3)) )
  {
    Frame::cache(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00535230) --------------------------------------------------------  // acclient.c:357179
void __thiscall Frame::Serialize(Frame *this, Archive *io_archive)
{
  Frame *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13

  v2 = this;
  QualifiedControl::Serialize(&this->m_fOrigin, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = LODWORD(v2->qw);
    else
      LODWORD(v2->qw) = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = LODWORD(v2->qx);
    else
      LODWORD(v2->qx) = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = LODWORD(v2->qy);
    else
      LODWORD(v2->qy) = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v6 = Archive::GetBytes(io_archive, 4u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v6 = LODWORD(v2->qz);
    else
      LODWORD(v2->qz) = *(_DWORD *)v6;
  }
}

//----- (005352F0) --------------------------------------------------------  // acclient.c:357228
void __thiscall Frame::interpolate_origin(Frame *this, Frame *from, Frame *to, float t)
{
  char *v4; // ecx@1
  float v5; // ST10_4@1
  float v6; // ST14_4@1
  double v7; // st6@1
  float v8; // ST00_4@1
  float v9; // ST04_4@1
  float v10; // ST08_4@1
  float v11; // ST14_4@1
  float v12; // ST00_4@1
  float v13; // ST04_4@1

  v4 = (char *)&this->m_fOrigin;
  v5 = t * to->m_fOrigin.y;
  v6 = t * to->m_fOrigin.z;
  v7 = 1.0 - t;
  v8 = v7 * from->m_fOrigin.x;
  v9 = v7 * from->m_fOrigin.y;
  v10 = v7 * from->m_fOrigin.z;
  v11 = v10 + v6;
  v12 = t * to->m_fOrigin.x + v8;
  *(float *)v4 = v12;
  v13 = v9 + v5;
  *((float *)v4 + 1) = v13;
  *((float *)v4 + 2) = v11;
}

//----- (00535390) --------------------------------------------------------  // acclient.c:357257
void __thiscall Frame::interpolate_rotation(Frame *this, Frame *from, Frame *to, float t)
{
  double v4; // st7@1
  unsigned __int8 v6; // c0@1
  unsigned __int8 v7; // c2@1
  long double v8; // st7@5
  long double omega; // ST20_8@5
  long double v10; // st6@5
  double v11; // st7@5
  long double v12; // st6@5
  float new_qz; // ST0C_4@12
  float new_qy; // ST08_4@12
  float new_qx; // ST04_4@12
  float new_qw; // ST00_4@12
  double cosom; // [sp+18h] [bp-28h]@1
  double cosoma; // [sp+18h] [bp-28h]@5
  float to1; // [sp+30h] [bp-10h]@2
  float to1_4; // [sp+34h] [bp-Ch]@2
  float to1_8; // [sp+38h] [bp-8h]@2
  float to1_12; // [sp+3Ch] [bp-4h]@2

  v4 = from->qy * to->qy + from->qw * to->qw + from->qx * to->qx + from->qz * to->qz;
  cosom = v4;
  if ( v6 | v7 )
  {
    v4 = -v4;
    cosom = v4;
    to1 = -to->qw;
    to1_4 = -to->qx;
    to1_8 = -to->qy;
    to1_12 = -to->qz;
  }
  else
  {
    to1 = to->qw;
    to1_4 = to->qx;
    to1_8 = to->qy;
    to1_12 = to->qz;
  }
  if ( 1.0 - v4 <= 0.00019999999 )
  {
    v11 = 1.0 - t;
    goto LABEL_11;
  }
  v8 = acos(cosom);
  omega = v8;
  cosoma = 1.0 - t;
  v10 = 1.0 / sin(v8);
  v11 = v10 * sin(v8 * cosoma);
  v12 = sin(t * omega) * v10;
  if ( v11 < 0.0 || v11 > 1.0 || v12 < 0.0 || v12 > 1.0 )
  {
    v11 = cosoma;
LABEL_11:
    v12 = t;
  }
  new_qz = to1_12 * v12 + from->qz * v11;
  new_qy = from->qy * v11 + to1_8 * v12;
  new_qx = from->qx * v11 + to1_4 * v12;
  new_qw = v11 * from->qw + to1 * v12;
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
}

//----- (00535520) --------------------------------------------------------  // acclient.c:357321
void __thiscall Frame::subtract1(Frame *this, Frame *_f1, AFrame *_f2)
{
  Frame *v3; // ebx@1
  float new_qz; // ST0C_4@1
  float new_qy; // ST08_4@1
  float new_qx; // ST04_4@1
  float new_qw; // ST00_4@1
  double v8; // st7@1
  double v9; // st6@1
  double v10; // st5@1
  float v11; // ST1C_4@1
  double v12; // st4@1
  float v13; // ST20_4@1
  double v14; // st5@1
  double v15; // st7@1
  float v16; // ST30_4@1
  float v17; // ST1C_4@1
  float v18; // ST20_4@1

  v3 = this;
  new_qz = _f1->qz * _f2->qw - (_f1->qw * _f2->qz + _f2->qy * _f1->qx) + _f1->qy * _f2->qx;
  new_qy = _f1->qy * _f2->qw - _f1->qw * _f2->qy + _f2->qz * _f1->qx - _f2->qx * _f1->qz;
  new_qx = _f1->qx * _f2->qw - _f2->qx * _f1->qw - _f1->qy * _f2->qz + _f1->qz * _f2->qy;
  new_qw = _f1->qy * _f2->qy + _f2->qx * _f1->qx + _f1->qw * _f2->qw + _f2->qz * _f1->qz;
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
  v8 = -_f2->m_fOrigin.x;
  v9 = -_f2->m_fOrigin.y;
  v10 = -_f2->m_fOrigin.z;
  v11 = v10 * v3->m_fl2gv[6] + v8 * v3->m_fl2gv[0] + v9 * v3->m_fl2gv[3];
  v12 = v10 * v3->m_fl2gv[7] + v8 * v3->m_fl2gv[1];
  v3 = (Frame *)((char *)v3 + 52);
  v13 = v12 + v9 * v3[-1].m_fl2gv[7];
  v14 = v10 * v3[-1].m_fOrigin.z + v8 * v3[-1].m_fl2gv[5] + v9 * v3[-1].m_fl2gv[8];
  v15 = v13 + _f1->m_fOrigin.y;
  v16 = v14 + _f1->m_fOrigin.z;
  v17 = v11 + _f1->m_fOrigin.x;
  v3->qw = v17;
  v18 = v15;
  v3->qx = v18;
  v3->qy = v16;
}

//----- (00535650) --------------------------------------------------------  // acclient.c:357364
void __thiscall Frame::subtract2(Frame *this, Frame *_f1, Frame *_f2)
{
  Frame *v3; // esi@1
  Frame *v4; // edi@1
  Frame *v5; // ebx@1
  AC1Legacy::Vector3 *v6; // eax@1
  int v7; // edx@1
  float new_qz; // ST0C_4@1
  float new_qy; // ST08_4@1
  float new_qx; // ST04_4@1
  float new_qw; // ST00_4@1
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-Ch]@1

  v3 = _f1;
  v4 = _f2;
  v5 = this;
  v6 = Frame::globaltolocal(_f2, &result, &_f1->m_fOrigin);
  v7 = (int)&v5->m_fOrigin;
  *(_DWORD *)v7 = LODWORD(v6->x);
  *(_DWORD *)(v7 + 4) = LODWORD(v6->y);
  *(_DWORD *)(v7 + 8) = LODWORD(v6->z);
  new_qz = v3->qz * v4->qw - v3->qy * v4->qx + v3->qx * v4->qy - v3->qw * v4->qz;
  new_qy = v3->qz * v4->qx + v4->qw * v3->qy - v4->qy * v3->qw - v3->qx * v4->qz;
  new_qx = v3->qx * v4->qw - v3->qw * v4->qx - v4->qy * v3->qz + v3->qy * v4->qz;
  new_qw = v3->qw * v4->qw + v4->qy * v3->qy + v3->qx * v4->qx + v3->qz * v4->qz;
  Frame::set_rotate(v5, new_qw, new_qx, new_qy, new_qz);
}

//----- (00535720) --------------------------------------------------------  // acclient.c:357393
AC1Legacy::Vector3 *__thiscall Frame::get_vector_heading(Frame *this, AC1Legacy::Vector3 *result)
{
  AC1Legacy::Vector3 *v2; // eax@1
  double v3; // st6@1
  double v4; // st7@1

  v2 = result;
  v3 = (this->m_fl2gv[7] + this->m_fl2gv[1]) * 0.0 + this->m_fl2gv[4];
  v4 = (this->m_fl2gv[8] + this->m_fl2gv[2]) * 0.0 + this->m_fl2gv[5];
  result->x = (this->m_fl2gv[6] + this->m_fl2gv[0]) * 0.0 + this->m_fl2gv[3];
  result->y = v3;
  result->z = v4;
  return v2;
}

//----- (00535760) --------------------------------------------------------  // acclient.c:357409
double __thiscall Frame::get_heading(Frame *this)
{
  return fmod(
           450.0
         - atan2(
             (this->m_fl2gv[6] + this->m_fl2gv[0]) * 0.0 + this->m_fl2gv[3],
             (this->m_fl2gv[7] + this->m_fl2gv[1]) * 0.0 + this->m_fl2gv[4])
         * 57.29577951308232,
           360.0);
}

//----- (005357A0) --------------------------------------------------------  // acclient.c:357421
void __thiscall Frame::grotate(Frame *this, AC1Legacy::Vector3 *w)
{
  AC1Legacy::Vector3 *v2; // edx@1
  long double v3; // st4@1
  long double v4; // st7@2
  float thetainv; // ST18_4@2
  long double v6; // st7@2
  long double v7; // rt0@2
  float f; // ST10_4@2
  float g; // ST14_4@2
  long double v10; // st7@2
  float new_qz; // ST0C_4@2
  float new_qy; // ST08_4@2
  float new_qx; // ST04_4@2
  float new_qw; // ST00_4@2
  AC1Legacy::Vector3 *wa; // [sp+20h] [bp+4h]@2

  v2 = w;
  v3 = w->x * w->x + w->y * w->y + w->z * w->z;
  if ( v3 >= 0.00019999999 * 0.00019999999 )
  {
    v4 = sqrt(v3);
    thetainv = 1.0 / v4;
    v6 = v4 * 0.5;
    v7 = sin(v6);
    *(float *)&wa = cos(v6);
    f = v7 * v2->x * thetainv;
    g = thetainv * v7 * v2->y;
    v10 = v7 * thetainv * v2->z;
    new_qz = f * this->qy + *(float *)&wa * this->qz - g * this->qx + v10 * this->qw;
    new_qy = *(float *)&wa * this->qy - f * this->qz + v10 * this->qx + g * this->qw;
    new_qx = *(float *)&wa * this->qx + g * this->qz + f * this->qw - v10 * this->qy;
    new_qw = *(float *)&wa * this->qw - f * this->qx - g * this->qy - v10 * this->qz;
    Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
  }
}

//----- (005358D0) --------------------------------------------------------  // acclient.c:357459
void __thiscall Frame::cache_quaternion(Frame *this)
{
  long double v1; // st7@1
  long double v2; // st7@2
  long double v3; // st7@2
  signed int v4; // edx@3
  double v5; // st7@3
  bool v6; // c0@3
  bool v7; // c3@3
  int v8; // esi@7
  int v9; // edi@7
  double v10; // st7@7
  float new_qz; // ST0C_4@10
  float new_qy; // ST08_4@10
  float new_qx; // ST04_4@10
  float new_qw; // ST00_4@10
  int nxt[3]; // [sp+10h] [bp-2Ch]@3
  long double q[4]; // [sp+1Ch] [bp-20h]@2

  v1 = this->m_fl2gv[0] + this->m_fl2gv[4] + this->m_fl2gv[8] + 1.0;
  if ( v1 <= 0.00019999999 )
  {
    v4 = 0;
    v5 = this->m_fl2gv[4];
    nxt[0] = 1;
    v6 = v5 < this->m_fl2gv[0];
    v7 = v5 == this->m_fl2gv[0];
    nxt[1] = 2;
    nxt[2] = 0;
    if ( !v6 && !v7 )
      v4 = 1;
    if ( this->m_fl2gv[8] > (double)*(&this->qw + 4 * (v4 + 1)) )
      v4 = 2;
    v8 = nxt[v4];
    v9 = nxt[v8];
    v10 = sqrt(*(&this->qw + 4 * (v4 + 1)) - (*(&this->qw + 4 * (v9 + 1)) + *(&this->qw + 4 * (v8 + 1))) + 1.0);
    q[v4] = 0.5 * v10;
    if ( v10 > 0.00019999999 )
      v10 = 0.5 / v10;
    q[3] = (this->m_fl2gv[3 * v8 + v9] - this->m_fl2gv[v8 + 3 * v9]) * v10;
    q[v8] = (this->m_fl2gv[3 * v4 + v8] - this->m_fl2gv[v4 + 3 * v8]) * v10;
    q[v9] = (this->m_fl2gv[v9 + 3 * v4] - this->m_fl2gv[v4 + 3 * v9]) * v10;
    v3 = q[2];
  }
  else
  {
    v2 = 0.5 / sqrt(v1);
    q[3] = 0.25 / v2;
    q[0] = (this->m_fl2gv[5] - this->m_fl2gv[7]) * v2;
    q[1] = (this->m_fl2gv[6] - this->m_fl2gv[2]) * v2;
    v3 = v2 * (this->m_fl2gv[1] - this->m_fl2gv[3]);
  }
  new_qz = v3;
  new_qy = q[1];
  new_qx = q[0];
  new_qw = q[3];
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
}

//----- (00535A40) --------------------------------------------------------  // acclient.c:357519
void __thiscall Frame::rotate_around_axis_to_vector(Frame *this, int axis_num, AC1Legacy::Vector3 *dir)
{
  Frame *v3; // esi@1
  double v4; // st7@1
  float v5; // ecx@1
  double v6; // st7@1
  double v7; // st7@1
  double v8; // st6@1
  double v9; // st7@1
  int v10; // eax@2
  float v11; // edx@2
  int v12; // eax@4
  double v13; // st7@4
  int v14; // eax@4
  int v15; // ecx@4
  double v16; // st7@4
  AC1Legacy::Vector3 normal; // [sp+8h] [bp-30h]@1
  AC1Legacy::Vector3 m_axis; // [sp+14h] [bp-24h]@1
  AC1Legacy::Vector3 other_axis; // [sp+20h] [bp-18h]@1
  int prev[3]; // [sp+2Ch] [bp-Ch]@1

  v3 = this;
  v4 = this->m_fl2gv[3 * axis_num + 1];
  v5 = this->m_fl2gv[3 * axis_num];
  m_axis.y = v4;
  v6 = *(&v3->qw + 3 * axis_num + 6);
  m_axis.x = v5;
  m_axis.z = v6;
  v7 = m_axis.z * dir->z;
  prev[0] = 2;
  prev[1] = 0;
  v8 = m_axis.y * dir->y;
  prev[2] = 1;
  v9 = v7 + v8 + v5 * dir->x;
  other_axis.y = m_axis.y * v9;
  other_axis.z = m_axis.z * v9;
  normal.x = dir->x - v5 * v9;
  normal.y = dir->y - other_axis.y;
  normal.z = dir->z - other_axis.z;
  if ( AC1Legacy::Vector3::normalize_check_small(&normal) )
  {
    v10 = prev[axis_num];
    v11 = v3->m_fl2gv[3 * v10];
    other_axis.y = v3->m_fl2gv[3 * v10 + 1];
    other_axis.z = *(&v3->qw + 3 * v10 + 6);
    other_axis.x = v11;
    normal.x = v11;
    normal.y = other_axis.y;
    normal.z = other_axis.z;
  }
  if ( 0.00019999999 * 5.0 >= fabs(normal.z * m_axis.z + normal.y * m_axis.y + normal.x * m_axis.x) )
  {
    v12 = prev[axis_num];
    v13 = normal.z;
    LODWORD(v3->m_fl2gv[3 * v12]) = (_DWORD)normal.x;
    v3->m_fl2gv[3 * v12 + 1] = normal.y;
    *(&v3->qw + 3 * v12 + 6) = v13;
    v14 = prev[v12];
    v15 = (int)((char *)v3 + 12 * v14);
    other_axis.z = m_axis.y * normal.x - normal.y * m_axis.x;
    v16 = normal.z * m_axis.x - m_axis.z * normal.x;
    *(float *)(v15 + 16) = normal.y * m_axis.z - normal.z * m_axis.y;
    *(float *)(v15 + 20) = v16;
    *(&v3->qw + 3 * v14 + 6) = other_axis.z;
    Frame::cache_quaternion(v3);
  }
}

//----- (00535BF0) --------------------------------------------------------  // acclient.c:357588
void __thiscall Frame::euler_set_rotate(Frame *this, float x, float y, float z, int _order)
{
  Frame *v5; // esi@1
  double v6; // st7@2
  int v7; // ecx@4
  long double v8; // st6@6
  int v9; // edi@6
  double v10; // st5@6
  long double v11; // st7@6
  long double v12; // st7@6
  long double v13; // st6@6
  double v14; // st6@6
  float *v15; // eax@7
  int h; // [sp+4h] [bp-24h]@1
  int n; // [sp+8h] [bp-20h]@1
  int i; // [sp+Ch] [bp-1Ch]@1
  int j; // [sp+10h] [bp-18h]@1
  int k; // [sp+14h] [bp-14h]@1
  int s; // [sp+18h] [bp-10h]@1
  float a[3]; // [sp+1Ch] [bp-Ch]@7
  float xa; // [sp+2Ch] [bp+4h]@6
  float xb; // [sp+2Ch] [bp+4h]@7
  float wa; // [sp+30h] [bp+8h]@6
  float w; // [sp+30h] [bp+8h]@6
  float tha; // [sp+34h] [bp+Ch]@6
  float th; // [sp+34h] [bp+Ch]@6

  v5 = this;
  EulGetOrd(_order, &i, &j, &k, &h, &n, &s, &_order);
  if ( _order == 1 )
  {
    v6 = x;
    x = z;
  }
  else
  {
    v6 = z;
  }
  v7 = n;
  if ( n == 1 )
    y = -y;
  v8 = x * 0.5;
  v9 = k;
  v10 = v6;
  v11 = y * 0.5;
  wa = v10 * 0.5;
  tha = cos(v8);
  xa = cos(v11);
  *(float *)&_order = cos(wa);
  *(float *)&n = sin(v8);
  v12 = sin(v11);
  v13 = sin(wa);
  *(float *)&h = *(float *)&_order * tha;
  w = tha * v13;
  th = *(float *)&n * *(float *)&_order;
  *(float *)&_order = v13 * *(float *)&n;
  v14 = th;
  if ( s == 1 )
  {
    a[i] = (v14 + w) * xa;
    v15 = &a[j];
    *v15 = (*(float *)&_order + *(float *)&h) * v12;
    a[v9] = (w - th) * v12;
    xb = (*(float *)&h - *(float *)&_order) * xa;
  }
  else
  {
    a[i] = v14 * xa - w * v12;
    v15 = &a[j];
    *v15 = *(float *)&h * v12 + *(float *)&_order * xa;
    a[v9] = w * xa - th * v12;
    xb = *(float *)&_order * v12 + *(float *)&h * xa;
  }
  if ( v7 == 1 )
    *v15 = -*v15;
  Frame::set_rotate(v5, xb, a[0], a[1], a[2]);
}

//----- (00535DB0) --------------------------------------------------------  // acclient.c:357667
void __thiscall Frame::set_vector_heading(Frame *this, AC1Legacy::Vector3 *heading)
{
  float v2; // edx@1
  Frame *v3; // esi@1
  float v4; // eax@1
  float z; // ST08_4@2
  float x; // ST00_4@2
  AC1Legacy::Vector3 normalized; // [sp+14h] [bp-Ch]@1

  v2 = heading->y;
  v3 = this;
  v4 = heading->z;
  normalized.x = heading->x;
  normalized.y = v2;
  normalized.z = v4;
  if ( !AC1Legacy::Vector3::normalize_check_small(&normalized) )
  {
    z = -fmod(450.0 - atan2(normalized.x, normalized.y) * 57.29577951308232, 360.0) * 0.0174532925199433;
    x = asin(normalized.z) * 57.29577951308232 * 0.0174532925199433;
    Frame::euler_set_rotate(v3, x, 0.0, z, 0);
  }
}

//----- (00535E40) --------------------------------------------------------  // acclient.c:357691
void __thiscall Frame::set_heading(Frame *this, float degrees)
{
  long double v2; // st7@1
  AC1Legacy::Vector3 direction; // [sp+0h] [bp-Ch]@1

  direction.z = (this->m_fl2gv[8] + this->m_fl2gv[2]) * 0.0 + this->m_fl2gv[5];
  v2 = degrees * 0.0174532925199433;
  direction.x = sin(v2);
  direction.y = cos(v2);
  Frame::set_vector_heading(this, &direction);
}

