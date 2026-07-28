/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BBox
   Object     : ENGINE\engine_shared_geometry\BBox.obj
   Functions  : 28
   Addresses  : 005B1CA0 - 00777AF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B1CA0) --------------------------------------------------------  // acclient.c:476742
BOOL __cdecl IsFloatValid(const float _f)
{
  return !__isnan(_f) && __finite(_f);
}

//----- (005B1CE0) --------------------------------------------------------  // acclient.c:476748
int __cdecl Vector3Math::IsValid(Vector3 *_V)
{
  Vector3 *v1; // esi@1
  int result; // eax@6
  float _Va; // [sp+18h] [bp+4h]@1
  float _Vb; // [sp+18h] [bp+4h]@3

  v1 = _V;
  _Va = _V->x;
  result = 0;
  if ( !__isnan(_Va) )
  {
    if ( __finite(_Va) )
    {
      _Vb = v1->y;
      if ( !__isnan(_Vb) && __finite(_Vb) && (unsigned __int8)IsFloatValid(v1->z) )
        result = 1;
    }
  }
  return result;
}

//----- (005B1D70) --------------------------------------------------------  // acclient.c:476771
void __thiscall BBox::BuildBoundingBox(BBox *this, BBox *bbox)
{
  if ( this->m_vMin.x < (double)bbox->m_vMin.x )
    bbox->m_vMin.x = this->m_vMin.x;
  if ( this->m_vMin.y < (double)bbox->m_vMin.y )
    bbox->m_vMin.y = this->m_vMin.y;
  if ( this->m_vMin.z < (double)bbox->m_vMin.z )
    bbox->m_vMin.z = this->m_vMin.z;
  if ( this->m_vMax.x > (double)bbox->m_vMax.x )
    bbox->m_vMax.x = this->m_vMax.x;
  if ( this->m_vMax.y > (double)bbox->m_vMax.y )
    bbox->m_vMax.y = this->m_vMax.y;
  if ( this->m_vMax.z > (double)bbox->m_vMax.z )
    bbox->m_vMax.z = this->m_vMax.z;
}

//----- (005B1DF0) --------------------------------------------------------  // acclient.c:476788
void __thiscall BBox::InitForAdjustment(BBox *this)
{
  char *v1; // ecx@1

  LODWORD(this->m_vMin.x) = 2139095039;
  LODWORD(this->m_vMin.y) = 2139095039;
  LODWORD(this->m_vMin.z) = 2139095039;
  v1 = (char *)&this->m_vMax;
  *(_DWORD *)v1 = -8388609;
  *((_DWORD *)v1 + 1) = -8388609;
  *((_DWORD *)v1 + 2) = -8388609;
}

//----- (005B1E60) --------------------------------------------------------  // acclient.c:476802
void __thiscall BBox::LocalToLocal(BBox *this, BBox *from_box, Position *from_pos, Position *to_pos)
{
  float v4; // edx@1
  BBox *v5; // edi@1
  float v6; // ecx@1
  int v7; // eax@1
  float v8; // ecx@1
  float v9; // ecx@1
  int v10; // edx@1
  float v11; // edx@1
  float v12; // eax@1
  double v13; // st7@1
  float v14; // edx@1
  double v15; // st7@1
  float v16; // ecx@1
  float v17; // edx@1
  double v18; // st7@1
  double v19; // st7@1
  float v20; // edx@1
  double v21; // st7@1
  float v22; // ecx@1
  float v23; // edx@1
  double v24; // st7@1
  Vector3 vc; // [sp+10h] [bp-24h]@1
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-18h]@1
  AC1Legacy::Vector3 v; // [sp+28h] [bp-Ch]@1

  v4 = from_box->m_vMin.z;
  v5 = this;
  v6 = from_box->m_vMin.y;
  vc.x = from_box->m_vMin.x;
  vc.y = v6;
  vc.z = v4;
  Position::localtolocal(to_pos, &result, from_pos, (AC1Legacy::Vector3 *)&vc);
  vc = result.0;
  v7 = (signed int)result.x;
  v8 = result.y;
  LODWORD(v5->m_vMin.x) = (_DWORD)result.x;
  v5->m_vMin.y = v8;
  v9 = vc.z;
  v5->m_vMin.z = vc.z;
  v10 = (int)&v5->m_vMax;
  *(_DWORD *)v10 = v7;
  *(_DWORD *)(v10 + 4) = LODWORD(vc.y);
  *(float *)(v10 + 8) = v9;
  v11 = from_box->m_vMax.y;
  v12 = from_box->m_vMax.z;
  result.x = from_box->m_vMax.x;
  result.y = v11;
  result.z = v12;
  Position::localtolocal(to_pos, &v, from_pos, &result);
  vc = v.0;
  BBox::AdjustBBox(v5, &vc);
  v13 = from_box->m_vMax.y;
  v14 = from_box->m_vMin.z;
  v.x = from_box->m_vMax.x;
  result.z = v14;
  v.y = v13;
  v.z = v14;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v15 = from_box->m_vMin.y;
  v16 = from_box->m_vMax.z;
  v.x = from_box->m_vMax.x;
  result.z = v16;
  v.y = v15;
  v.z = v16;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v17 = from_box->m_vMax.z;
  v18 = from_box->m_vMax.y;
  v.x = from_box->m_vMin.x;
  result.z = v17;
  v.y = v18;
  v.z = v17;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v19 = from_box->m_vMax.y;
  v20 = from_box->m_vMin.z;
  v.x = from_box->m_vMin.x;
  result.z = v20;
  v.y = v19;
  v.z = v20;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v21 = from_box->m_vMin.y;
  v22 = from_box->m_vMin.z;
  v.x = from_box->m_vMax.x;
  result.z = v22;
  v.y = v21;
  v.z = v22;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v23 = from_box->m_vMax.z;
  v24 = from_box->m_vMin.y;
  v.x = from_box->m_vMin.x;
  result.z = v23;
  v.y = v24;
  v.z = v23;
  Position::localtolocal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
}

//----- (005B2120) --------------------------------------------------------  // acclient.c:476912
void __thiscall BBox::LocalToGlobal(BBox *this, BBox *from_box, Position *from_pos, Position *to_pos)
{
  float v4; // edx@1
  BBox *v5; // edi@1
  float v6; // ecx@1
  int v7; // eax@1
  float v8; // ecx@1
  float v9; // ecx@1
  int v10; // edx@1
  float v11; // edx@1
  float v12; // eax@1
  double v13; // st7@1
  float v14; // edx@1
  double v15; // st7@1
  float v16; // ecx@1
  float v17; // edx@1
  double v18; // st7@1
  double v19; // st7@1
  float v20; // edx@1
  double v21; // st7@1
  float v22; // ecx@1
  float v23; // edx@1
  double v24; // st7@1
  Vector3 vc; // [sp+10h] [bp-24h]@1
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-18h]@1
  AC1Legacy::Vector3 v; // [sp+28h] [bp-Ch]@1

  v4 = from_box->m_vMin.z;
  v5 = this;
  v6 = from_box->m_vMin.y;
  vc.x = from_box->m_vMin.x;
  vc.y = v6;
  vc.z = v4;
  Position::localtoglobal(to_pos, &result, from_pos, (AC1Legacy::Vector3 *)&vc);
  vc = result.0;
  v7 = (signed int)result.x;
  v8 = result.y;
  LODWORD(v5->m_vMin.x) = (_DWORD)result.x;
  v5->m_vMin.y = v8;
  v9 = vc.z;
  v5->m_vMin.z = vc.z;
  v10 = (int)&v5->m_vMax;
  *(_DWORD *)v10 = v7;
  *(_DWORD *)(v10 + 4) = LODWORD(vc.y);
  *(float *)(v10 + 8) = v9;
  v11 = from_box->m_vMax.y;
  v12 = from_box->m_vMax.z;
  result.x = from_box->m_vMax.x;
  result.y = v11;
  result.z = v12;
  Position::localtoglobal(to_pos, &v, from_pos, &result);
  vc = v.0;
  BBox::AdjustBBox(v5, &vc);
  v13 = from_box->m_vMax.y;
  v14 = from_box->m_vMin.z;
  v.x = from_box->m_vMax.x;
  result.z = v14;
  v.y = v13;
  v.z = v14;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v15 = from_box->m_vMin.y;
  v16 = from_box->m_vMax.z;
  v.x = from_box->m_vMax.x;
  result.z = v16;
  v.y = v15;
  v.z = v16;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v17 = from_box->m_vMax.z;
  v18 = from_box->m_vMax.y;
  v.x = from_box->m_vMin.x;
  result.z = v17;
  v.y = v18;
  v.z = v17;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v19 = from_box->m_vMax.y;
  v20 = from_box->m_vMin.z;
  v.x = from_box->m_vMin.x;
  result.z = v20;
  v.y = v19;
  v.z = v20;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v21 = from_box->m_vMin.y;
  v22 = from_box->m_vMin.z;
  v.x = from_box->m_vMax.x;
  result.z = v22;
  v.y = v21;
  v.z = v22;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
  v23 = from_box->m_vMax.z;
  v24 = from_box->m_vMin.y;
  v.x = from_box->m_vMin.x;
  result.z = v23;
  v.y = v24;
  v.z = v23;
  Position::localtoglobal(to_pos, &result, from_pos, &v);
  vc = result.0;
  BBox::AdjustBBox(v5, &vc);
}

//----- (005B23E0) --------------------------------------------------------  // acclient.c:477022
void __thiscall BBox::ConvertToGlobal(BBox *this, Position *i_rcOriginPos)
{
  Position *v2; // esi@1
  BBox *v3; // edi@1
  double v4; // st7@1
  float v5; // eax@1
  float v6; // ecx@1
  double v7; // st6@1
  float v8; // edx@1
  double v9; // st5@1
  double v10; // st4@1
  float v11; // eax@1
  double v12; // st3@1
  float v13; // ecx@1
  double v14; // st2@1
  float v15; // eax@1
  float v16; // ecx@1
  double v17; // st6@1
  float v18; // edx@1
  double v19; // st6@1
  double v20; // st5@1
  double v21; // st5@1
  double v22; // st5@1
  double v23; // st4@1
  Vector3 cTrans; // [sp+Ch] [bp-30h]@1
  Vector3 cMin; // [sp+18h] [bp-24h]@1
  Vector3 cMax; // [sp+24h] [bp-18h]@1
  float v27; // [sp+30h] [bp-Ch]@1
  float v28; // [sp+34h] [bp-8h]@1
  float v29; // [sp+38h] [bp-4h]@1

  v2 = i_rcOriginPos;
  v3 = this;
  v4 = this->m_vMax.y;
  v5 = this->m_vMin.x;
  cMax.y = this->m_vMax.y;
  v6 = this->m_vMin.y;
  v7 = v3->m_vMin.x;
  v8 = v3->m_vMin.z;
  v9 = v3->m_vMin.y;
  cMin.x = v5;
  v10 = v3->m_vMin.z;
  v11 = v3->m_vMax.x;
  cMin.y = v6;
  v12 = v9 * i_rcOriginPos->frame.m_fl2gv[3];
  v13 = v3->m_vMax.z;
  cMax.x = v11;
  v14 = v10 * i_rcOriginPos->frame.m_fl2gv[6];
  cMin.z = v8;
  cMax.z = v13;
  cTrans.x = v12 + v14 + v7 * i_rcOriginPos->frame.m_fl2gv[0] + i_rcOriginPos->frame.m_fOrigin.x;
  v15 = cTrans.x;
  cTrans.y = v9 * i_rcOriginPos->frame.m_fl2gv[4]
           + v10 * i_rcOriginPos->frame.m_fl2gv[7]
           + v7 * i_rcOriginPos->frame.m_fl2gv[1]
           + i_rcOriginPos->frame.m_fOrigin.y;
  v16 = cTrans.y;
  v17 = v9 * i_rcOriginPos->frame.m_fl2gv[5]
      + v10 * i_rcOriginPos->frame.m_fl2gv[8]
      + v7 * i_rcOriginPos->frame.m_fl2gv[2]
      + i_rcOriginPos->frame.m_fOrigin.z;
  LODWORD(v3->m_vMin.x) = (_DWORD)cTrans.x;
  v3->m_vMax.x = v15;
  v3->m_vMin.y = v16;
  v3->m_vMax.y = v16;
  cTrans.z = v17;
  v18 = cTrans.z;
  v19 = cMin.z;
  v20 = cMin.z;
  v3->m_vMin.z = cTrans.z;
  v3->m_vMax.z = v18;
  v27 = v20 * v2->frame.m_fl2gv[6] + v4 * v2->frame.m_fl2gv[3] + cMax.x * v2->frame.m_fl2gv[0] + v2->frame.m_fOrigin.x;
  v21 = v19 * v2->frame.m_fl2gv[7]
      + v4 * v2->frame.m_fl2gv[4]
      + cMax.x * i_rcOriginPos->frame.m_fl2gv[1]
      + v2->frame.m_fOrigin.y;
  cTrans = *(Vector3 *)&v27;
  v28 = v21;
  v29 = v19 * i_rcOriginPos->frame.m_fl2gv[8]
      + v4 * i_rcOriginPos->frame.m_fl2gv[5]
      + cMax.x * i_rcOriginPos->frame.m_fl2gv[2]
      + i_rcOriginPos->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
  v27 = cMax.z * v2->frame.m_fl2gv[6]
      + cMin.y * v2->frame.m_fl2gv[3]
      + cMax.x * v2->frame.m_fl2gv[0]
      + v2->frame.m_fOrigin.x;
  cTrans = *(Vector3 *)&v27;
  v28 = cMax.z * v2->frame.m_fl2gv[7]
      + cMin.y * v2->frame.m_fl2gv[4]
      + cMax.x * v2->frame.m_fl2gv[1]
      + v2->frame.m_fOrigin.y;
  v29 = cMax.z * i_rcOriginPos->frame.m_fl2gv[8]
      + cMin.y * v2->frame.m_fl2gv[5]
      + cMax.x * v2->frame.m_fl2gv[2]
      + v2->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
  v27 = cMax.z * v2->frame.m_fl2gv[6]
      + cMax.y * v2->frame.m_fl2gv[3]
      + cMin.x * v2->frame.m_fl2gv[0]
      + v2->frame.m_fOrigin.x;
  v22 = cMax.z * i_rcOriginPos->frame.m_fl2gv[7];
  v23 = cMax.y * i_rcOriginPos->frame.m_fl2gv[4];
  cTrans = *(Vector3 *)&v27;
  v28 = v22 + v23 + cMin.x * v2->frame.m_fl2gv[1] + v2->frame.m_fOrigin.y;
  v29 = cMax.z * i_rcOriginPos->frame.m_fl2gv[8]
      + cMax.y * v2->frame.m_fl2gv[5]
      + cMin.x * v2->frame.m_fl2gv[2]
      + v2->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
  v27 = cMin.z * v2->frame.m_fl2gv[6]
      + cMax.y * v2->frame.m_fl2gv[3]
      + cMin.x * v2->frame.m_fl2gv[0]
      + v2->frame.m_fOrigin.x;
  cTrans = *(Vector3 *)&v27;
  v28 = cMin.z * v2->frame.m_fl2gv[7]
      + cMax.y * v2->frame.m_fl2gv[4]
      + cMin.x * v2->frame.m_fl2gv[1]
      + v2->frame.m_fOrigin.y;
  v29 = cMin.z * i_rcOriginPos->frame.m_fl2gv[8]
      + cMax.y * v2->frame.m_fl2gv[5]
      + cMin.x * v2->frame.m_fl2gv[2]
      + v2->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
  v27 = cMin.z * v2->frame.m_fl2gv[6]
      + cMin.y * v2->frame.m_fl2gv[3]
      + cMax.x * v2->frame.m_fl2gv[0]
      + v2->frame.m_fOrigin.x;
  cTrans = *(Vector3 *)&v27;
  v28 = cMin.z * v2->frame.m_fl2gv[7]
      + cMin.y * v2->frame.m_fl2gv[4]
      + cMax.x * v2->frame.m_fl2gv[1]
      + v2->frame.m_fOrigin.y;
  v29 = cMin.z * i_rcOriginPos->frame.m_fl2gv[8]
      + cMin.y * v2->frame.m_fl2gv[5]
      + cMax.x * v2->frame.m_fl2gv[2]
      + v2->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
  v27 = cMax.z * v2->frame.m_fl2gv[6]
      + cMin.y * v2->frame.m_fl2gv[3]
      + cMin.x * v2->frame.m_fl2gv[0]
      + v2->frame.m_fOrigin.x;
  cTrans = *(Vector3 *)&v27;
  v28 = cMax.z * v2->frame.m_fl2gv[7]
      + cMin.y * v2->frame.m_fl2gv[4]
      + cMin.x * v2->frame.m_fl2gv[1]
      + v2->frame.m_fOrigin.y;
  v29 = cMax.z * i_rcOriginPos->frame.m_fl2gv[8]
      + cMin.y * v2->frame.m_fl2gv[5]
      + cMin.x * v2->frame.m_fl2gv[2]
      + v2->frame.m_fOrigin.z;
  BBox::AdjustBBox(v3, &cTrans);
}

//----- (005B2790) --------------------------------------------------------  // acclient.c:477177
Vector3 *__thiscall BBox::GetCenter(BBox *this, Vector3 *result)
{
  Vector3 *v2; // eax@1
  double v3; // st7@1
  double v4; // st6@1

  v2 = result;
  v3 = (this->m_vMax.z + this->m_vMin.z) * 0.5;
  v4 = (this->m_vMax.y + this->m_vMin.y) * 0.5;
  result->x = (this->m_vMax.x + this->m_vMin.x) * 0.5;
  result->y = v4;
  result->z = v3;
  return v2;
}

//----- (0070E450) --------------------------------------------------------  // acclient.c:801277
void sub_70E450()
{
  flt_8EE194 = 1000.0 + 1.0;
}

//----- (0070E470) --------------------------------------------------------  // acclient.c:801283
void sub_70E470()
{
  flt_8EE198 = 24.0 * 8.0;
}

//----- (0070E490) --------------------------------------------------------  // acclient.c:801289
void sub_70E490()
{
  flt_8EE19C = 24.0 * 0.5;
}

//----- (0070E4B0) --------------------------------------------------------  // acclient.c:801295
int sub_70E4B0()
{
  KW_NULL_2.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_7779D0);
}

//----- (0070E4D0) --------------------------------------------------------  // acclient.c:801303
int sub_70E4D0()
{
  PStringBase<char>::PStringBase<char>(&KW_MIN, "Min");
  return atexit(sub_777A00);
}

//----- (0070E4F0) --------------------------------------------------------  // acclient.c:801310
int sub_70E4F0()
{
  PStringBase<char>::PStringBase<char>(&KW_MAX, "Max");
  return atexit(sub_777A30);
}

//----- (0070E510) --------------------------------------------------------  // acclient.c:801317
int sub_70E510()
{
  PStringBase<char>::PStringBase<char>(&KW_BBOX, "BBox");
  return atexit(sub_777A60);
}

//----- (0070E530) --------------------------------------------------------  // acclient.c:801324
int _E109_84()
{
  PStringBase<char>::PStringBase<char>(&KW_TRANSFORM, "Transform");
  return atexit(sub_777A90);
}

//----- (0070E550) --------------------------------------------------------  // acclient.c:801331
int sub_70E550()
{
  PStringBase<char>::PStringBase<char>(&KW_HALF_BOX_EXTENT, "HalfBoxExtent");
  return atexit(_E113_71);
}

//----- (0070E570) --------------------------------------------------------  // acclient.c:801338
int _E115_90()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAME, "Frame");
  return atexit(_E116_63);
}

//----- (0070E590) --------------------------------------------------------  // acclient.c:801345
int _E118_81()
{
  return atexit(_E119_89);
}

//----- (0070E5A0) --------------------------------------------------------  // acclient.c:801351
int _E43_6()
{
  return atexit(_E44_6);
}

//----- (0070E5B0) --------------------------------------------------------  // acclient.c:801357
int sub_70E5B0()
{
  return atexit(nullsub_1547);
}

//----- (007779D0) --------------------------------------------------------  // acclient.c:911268
void __cdecl sub_7779D0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777A00) --------------------------------------------------------  // acclient.c:911281
void __cdecl sub_777A00()
{
  char *v0; // esi@1

  v0 = &KW_MIN.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MIN.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777A30) --------------------------------------------------------  // acclient.c:911294
void __cdecl sub_777A30()
{
  char *v0; // esi@1

  v0 = &KW_MAX.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAX.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777A60) --------------------------------------------------------  // acclient.c:911307
void __cdecl sub_777A60()
{
  char *v0; // esi@1

  v0 = &KW_BBOX.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BBOX.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777A90) --------------------------------------------------------  // acclient.c:911320
void __cdecl sub_777A90()
{
  char *v0; // esi@1

  v0 = &KW_TRANSFORM.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TRANSFORM.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777AC0) --------------------------------------------------------  // acclient.c:911333
void __cdecl _E113_71()
{
  char *v0; // esi@1

  v0 = &KW_HALF_BOX_EXTENT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HALF_BOX_EXTENT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777AF0) --------------------------------------------------------  // acclient.c:911346
void __cdecl _E116_63()
{
  char *v0; // esi@1

  v0 = &KW_FRAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

