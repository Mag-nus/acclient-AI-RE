/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Matrix4
   Object     : CORE\mathlib\Matrix4.obj
   Functions  : 10
   Addresses  : 0065CE70 - 0065D760 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065CE70) --------------------------------------------------------  // acclient.c:626923
double __thiscall Matrix4::CalcDeterminant(Matrix4 *this)
{
  float v1; // ST0C_4@1
  float v2; // ST08_4@1
  float v3; // ST18_4@1
  float v4; // ST14_4@1
  float v5; // ST1C_4@1
  float v6; // ST10_4@1
  float v7; // ST20_4@1
  float v8; // ST24_4@1
  float v9; // ST2C_4@1
  float v10; // ST30_4@1
  float v11; // ST34_4@1
  float v12; // ST28_4@1
  double v13; // st3@1
  double v14; // st2@1

  v1 = this->_34;
  v2 = this->_44;
  v3 = this->_33;
  v4 = this->_43;
  v5 = this->_41;
  v6 = this->_31;
  v7 = this->_44;
  v8 = this->_34;
  v9 = this->_42;
  v10 = this->_32;
  v11 = this->_41;
  v12 = this->_31;
  v13 = ((this->_33 * this->_44 - this->_43 * this->_34) * this->_22
       - (this->_32 * this->_44 - this->_42 * this->_34) * this->_23
       + (this->_32 * this->_43 - this->_42 * this->_33) * this->_24)
      * this->_11;
  v14 = ((this->_32 * this->_43 - this->_42 * this->_33) * this->_21
       - (this->_31 * this->_43 - this->_41 * this->_33) * this->_22
       + (this->_31 * this->_42 - this->_32 * this->_41) * this->_23)
      * this->_14;
  return v13
       - ((v3 * v2 - v4 * v1) * this->_21 - (v6 * v2 - v5 * v1) * this->_23 + (v6 * v4 - v3 * v5) * this->_24)
       * this->_12
       + ((v10 * v7 - v9 * v8) * this->_21 - (v12 * v7 - v11 * v8) * this->_22 + (v12 * v9 - v10 * v11) * this->_24)
       * this->_13
       - v14;
}

//----- (0065D030) --------------------------------------------------------  // acclient.c:626969
void __thiscall Matrix4::Translate(Matrix4 *this, float x, float y, float z)
{
  LODWORD(this->_14) = 0;
  LODWORD(this->_13) = 0;
  LODWORD(this->_12) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_23) = 0;
  LODWORD(this->_21) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_32) = 0;
  LODWORD(this->_31) = 0;
  LODWORD(this->_44) = 1065353216;
  LODWORD(this->_33) = 1065353216;
  LODWORD(this->_22) = 1065353216;
  LODWORD(this->_11) = 1065353216;
  this->_41 = x;
  this->_42 = y;
  this->_43 = z;
}

//----- (0065D080) --------------------------------------------------------  // acclient.c:626990
void __thiscall Matrix4::Translate3(Matrix4 *this, float x, float y)
{
  LODWORD(this->_14) = 0;
  LODWORD(this->_13) = 0;
  LODWORD(this->_12) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_23) = 0;
  LODWORD(this->_21) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_43) = 0;
  LODWORD(this->_42) = 0;
  LODWORD(this->_41) = 0;
  LODWORD(this->_44) = 1065353216;
  LODWORD(this->_33) = 1065353216;
  LODWORD(this->_22) = 1065353216;
  LODWORD(this->_11) = 1065353216;
  this->_31 = x;
  this->_32 = y;
}

//----- (0065D0D0) --------------------------------------------------------  // acclient.c:627011
void __thiscall Matrix4::RotateX(Matrix4 *this, float radians)
{
  long double v2; // st7@1
  long double v3; // st6@1

  v2 = cos(radians);
  LODWORD(this->_14) = 0;
  LODWORD(this->_13) = 0;
  LODWORD(this->_12) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_21) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_31) = 0;
  LODWORD(this->_43) = 0;
  LODWORD(this->_42) = 0;
  LODWORD(this->_41) = 0;
  LODWORD(this->_44) = 1065353216;
  LODWORD(this->_11) = 1065353216;
  v3 = sin(radians);
  this->_22 = v2;
  this->_23 = v3;
  this->_32 = -v3;
  this->_33 = v2;
}

//----- (0065D120) --------------------------------------------------------  // acclient.c:627037
void __thiscall Matrix4::RotateY(Matrix4 *this, float radians)
{
  long double v2; // st7@1
  long double v3; // st6@1

  v2 = cos(radians);
  LODWORD(this->_14) = 0;
  LODWORD(this->_12) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_23) = 0;
  LODWORD(this->_21) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_32) = 0;
  LODWORD(this->_43) = 0;
  LODWORD(this->_42) = 0;
  LODWORD(this->_41) = 0;
  LODWORD(this->_44) = 1065353216;
  LODWORD(this->_22) = 1065353216;
  v3 = sin(radians);
  this->_11 = v2;
  this->_13 = -v3;
  this->_31 = v3;
  this->_33 = v2;
}

//----- (0065D170) --------------------------------------------------------  // acclient.c:627063
void __thiscall Matrix4::RotateZ(Matrix4 *this, float radians)
{
  long double v2; // st7@1
  long double v3; // st6@1

  v2 = cos(radians);
  LODWORD(this->_14) = 0;
  LODWORD(this->_13) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_23) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_32) = 0;
  LODWORD(this->_31) = 0;
  LODWORD(this->_43) = 0;
  LODWORD(this->_42) = 0;
  LODWORD(this->_41) = 0;
  LODWORD(this->_44) = 1065353216;
  LODWORD(this->_33) = 1065353216;
  v3 = sin(radians);
  this->_11 = v2;
  this->_12 = v3;
  this->_21 = -v3;
  this->_22 = v2;
}

//----- (0065D1C0) --------------------------------------------------------  // acclient.c:627089
void __thiscall Matrix4::Scale(Matrix4 *this, float x, float y, float z)
{
  LODWORD(this->_14) = 0;
  LODWORD(this->_13) = 0;
  LODWORD(this->_12) = 0;
  LODWORD(this->_24) = 0;
  LODWORD(this->_23) = 0;
  LODWORD(this->_21) = 0;
  LODWORD(this->_34) = 0;
  LODWORD(this->_32) = 0;
  LODWORD(this->_31) = 0;
  LODWORD(this->_43) = 0;
  LODWORD(this->_42) = 0;
  LODWORD(this->_41) = 0;
  this->_11 = x;
  LODWORD(this->_44) = 1065353216;
  this->_22 = y;
  this->_33 = z;
}

//----- (0065D210) --------------------------------------------------------  // acclient.c:627110
void __thiscall Matrix4::Adjoint(Matrix4 *this, Matrix4 *src)
{
  Matrix4 *v2; // eax@1
  double v3; // st7@1
  double v4; // st6@1
  float c2; // ST00_4@1
  double v6; // st5@1
  double v7; // st4@1
  double v8; // st3@1
  double v9; // st2@1
  float a3; // ST20_4@1
  float b3; // ST1C_4@1
  float c3; // ST18_4@1
  float d3; // ST14_4@1
  float a4; // ST10_4@1
  float b4; // ST0C_4@1
  float v16; // edx@1
  float v17; // eax@1
  float v18; // ST24_4@1
  float v19; // ST28_4@1
  float v20; // ST30_4@1
  float v21; // ST2C_4@1
  float v22; // ST34_4@1
  float v23; // ST38_4@1
  float v24; // ST38_4@1
  float v25; // ST34_4@1
  float v26; // ST2C_4@1
  float v27; // ST30_4@1
  float v28; // ST28_4@1
  float v29; // ST38_4@1
  float v30; // ST38_4@1
  float v31; // ST34_4@1
  float v32; // ST30_4@1
  float v33; // ST2C_4@1
  float v34; // ST38_4@1
  float srca; // [sp+40h] [bp+4h]@1
  Matrix4 *srcb; // [sp+40h] [bp+4h]@1

  v2 = src;
  v3 = src->_11;
  v4 = src->_12;
  c2 = src->_23;
  v6 = src->_13;
  v7 = src->_14;
  srca = src->_24;
  v8 = v2->_21;
  v9 = v2->_22;
  a3 = v2->_31;
  b3 = v2->_32;
  c3 = v2->_33;
  d3 = v2->_34;
  a4 = v2->_41;
  b4 = v2->_42;
  v16 = v2->_43;
  v17 = v2->_44;
  v18 = v17 * c3 - v16 * d3;
  v19 = v17 * b3 - b4 * d3;
  v20 = v16 * b3 - b4 * c3;
  this->_11 = v18 * v9 - v19 * c2 + v20 * srca;
  v21 = v17 * a3 - a4 * d3;
  v22 = v16 * a3 - a4 * c3;
  this->_21 = -(v18 * v8 - v21 * c2 + v22 * srca);
  v23 = b4 * a3 - a4 * b3;
  this->_31 = v19 * v8 - v21 * v9 + v23 * srca;
  this->_41 = -(v20 * v8 - v22 * v9 + v23 * c2);
  this->_12 = -(v18 * v4 - v19 * v6 + v20 * v7);
  this->_22 = v18 * v3 - v21 * v6 + v22 * v7;
  this->_32 = -(v19 * v3 - v21 * v4 + v23 * v7);
  this->_42 = v20 * v3 - v22 * v4 + v23 * v6;
  v24 = v17 * c2 - v16 * srca;
  v25 = v17 * v9 - b4 * srca;
  v26 = v16 * v9 - b4 * c2;
  this->_13 = v24 * v4 - v25 * v6 + v26 * v7;
  v27 = v17 * v8 - a4 * srca;
  v28 = v16 * v8 - a4 * c2;
  this->_23 = -(v24 * v3 - v27 * v6 + v28 * v7);
  v29 = b4 * v8 - a4 * v9;
  this->_33 = v25 * v3 - v27 * v4 + v29 * v7;
  this->_43 = -(v26 * v3 - v28 * v4 + v29 * v6);
  v30 = d3 * c2 - c3 * srca;
  v31 = d3 * v9 - b3 * srca;
  v32 = c3 * v9 - b3 * c2;
  this->_14 = -(v30 * v4 - v31 * v6 + v32 * v7);
  *(float *)&srcb = d3 * v8 - a3 * srca;
  v33 = c3 * v8 - a3 * c2;
  this->_24 = v30 * v3 - *(float *)&srcb * v6 + v33 * v7;
  v34 = b3 * v8 - a3 * v9;
  this->_34 = -(v31 * v3 - *(float *)&srcb * v4 + v34 * v7);
  this->_44 = v32 * v3 - v33 * v4 + v34 * v6;
}

//----- (0065D5A0) --------------------------------------------------------  // acclient.c:627202
BOOL __cdecl Matrix4::AreEqual(Matrix4 *_mA, Matrix4 *_mB)
{
  return fabs(_mA->_11 - _mB->_11) <= 0.00019999999
      && fabs(_mA->_21 - _mB->_21) <= 0.00019999999
      && fabs(_mA->_31 - _mB->_31) <= 0.00019999999
      && fabs(_mA->_41 - _mB->_41) <= 0.00019999999
      && fabs(_mA->_12 - _mB->_12) <= 0.00019999999
      && (unsigned __int8)AreFloatEqual(_mA->_22, _mB->_22, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_32, _mB->_32, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_42, _mB->_42, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_13, _mB->_13, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_23, _mB->_23, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_33, _mB->_33, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_43, _mB->_43, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_14, _mB->_14, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_24, _mB->_24, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_34, _mB->_34, 0.00019999999)
      && (unsigned __int8)AreFloatEqual(_mA->_44, _mB->_44, 0.00019999999);
}

//----- (0065D760) --------------------------------------------------------  // acclient.c:627223
double __thiscall Matrix4::Inverse(Matrix4 *this, Matrix4 *src)
{
  Matrix4 *v2; // ecx@1
  int v3; // ecx@1
  double result; // st7@1
  double v5; // st6@3
  int v6; // eax@3
  signed int v7; // ecx@3

  Matrix4::Adjoint(this, src);
  result = Matrix4::CalcDeterminant(v2);
  if ( fabs(result) >= 0.00019999999 )
  {
    v5 = 1.0 / result;
    v6 = v3 + 8;
    v7 = 4;
    do
    {
      v6 += 16;
      --v7;
      *(float *)(v6 - 24) = v5 * *(float *)(v6 - 24);
      *(float *)(v6 - 20) = v5 * *(float *)(v6 - 20);
      *(float *)(v6 - 16) = v5 * *(float *)(v6 - 16);
      *(float *)(v6 - 12) = v5 * *(float *)(v6 - 12);
    }
    while ( v7 );
  }
  else
  {
    result = 0.0;
  }
  return result;
}

