/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SceneTool
   Object     : ENGINE\render_base\SceneTool.obj
   Functions  : 117
   Addresses  : 0043D650 - 0072A140 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043D650) --------------------------------------------------------  // acclient.c:122253
BOOL __cdecl LandDefs::in_bounds(int x, int y)
{
  return x >= 0 && y >= 0 && x < 2040 && y < 2040;
}

//----- (0043D680) --------------------------------------------------------  // acclient.c:122259
int __cdecl LandDefs::blockid_to_lcoord(unsigned int block_id, int *x, int *y)
{
  int v3; // eax@2
  int result; // eax@6

  result = 0;
  if ( block_id )
  {
    *x = (block_id >> 21) & 0x7F8;
    v3 = 8 * (unsigned __int8)(block_id >> 16);
    *y = v3;
    if ( *x >= 0 && !((block_id >> 16) & 0) && *x < 2040 && v3 < 2040 )
      result = 1;
  }
  return result;
}

//----- (0043D6D0) --------------------------------------------------------  // acclient.c:122277
BOOL __cdecl AreFloatEqual(const float _a, const float _b, const float _Epsilon)
{
  return fabs(_a - _b) <= _Epsilon;
}

//----- (0043D6F0) --------------------------------------------------------  // acclient.c:122283
void __thiscall Vector3::operator*=(Vector3 *this, const float _rhs)
{
  this->x = _rhs * this->x;
  this->y = _rhs * this->y;
  this->z = _rhs * this->z;
}

//----- (0043D710) --------------------------------------------------------  // acclient.c:122291
Vector3 *__thiscall Vector3::operator+(Vector3 *this, Vector3 *result, Vector3 *_rhs)
{
  double v3; // st6@1
  Vector3 *v4; // eax@1
  double v5; // st7@1

  v3 = _rhs->y + this->y;
  v4 = result;
  v5 = _rhs->z + this->z;
  result->x = _rhs->x + this->x;
  result->y = v3;
  result->z = v5;
  return v4;
}

//----- (0043D740) --------------------------------------------------------  // acclient.c:122307
Vector3 *__thiscall Vector3::operator-(Vector3 *this, Vector3 *result, Vector3 *_rhs)
{
  double v3; // st6@1
  Vector3 *v4; // eax@1
  double v5; // st7@1

  v3 = this->y - _rhs->y;
  v4 = result;
  v5 = this->z - _rhs->z;
  result->x = this->x - _rhs->x;
  result->y = v3;
  result->z = v5;
  return v4;
}

//----- (0043D770) --------------------------------------------------------  // acclient.c:122323
Vector3 *__thiscall Vector3::operator*(Vector3 *this, Vector3 *result, const float _rhs)
{
  Vector3 *v3; // eax@1
  double v4; // st6@1
  double v5; // st7@1

  v3 = result;
  v4 = _rhs * this->y;
  v5 = _rhs * this->z;
  result->x = _rhs * this->x;
  result->y = v4;
  result->z = v5;
  return v3;
}

//----- (0043D7A0) --------------------------------------------------------  // acclient.c:122339
void __thiscall Matrix4::TransformVector_C(Matrix4 *this, Vector3 *src, Vector3 *dst)
{
  Vector3 *v3; // eax@1
  double v4; // st7@1

  v3 = src;
  v4 = 1.0 / (this->_14 * src->x + this->_34 * src->z + this->_24 * src->y + this->_44);
  dst->x = (this->_31 * src->z + this->_21 * src->y + src->x * this->_11 + this->_41) * v4;
  dst->y = (this->_12 * v3->x + this->_32 * v3->z + this->_22 * v3->y + this->_42) * v4;
  dst->z = (this->_13 * v3->x + this->_33 * v3->z + this->_23 * src->y + this->_43) * v4;
}

//----- (0043D820) --------------------------------------------------------  // acclient.c:122352
void __thiscall Matrix4::Multiply_C(Matrix4 *this, Matrix4 *a, Matrix4 *b)
{
  Matrix4 *v3; // edx@1
  Matrix4 *v4; // eax@1

  v3 = a;
  v4 = b;
  this->_11 = a->_11 * b->_11 + b->_31 * a->_13 + a->_12 * b->_21 + a->_14 * b->_41;
  this->_12 = v4->_32 * v3->_13 + v3->_11 * v4->_12 + v3->_12 * v4->_22 + v4->_42 * v3->_14;
  this->_13 = v3->_11 * v4->_13 + v4->_33 * v3->_13 + v3->_12 * v4->_23 + v4->_43 * v3->_14;
  this->_14 = v3->_12 * v4->_24 + v3->_14 * v4->_44 + v4->_14 * v3->_11 + v4->_34 * v3->_13;
  this->_21 = v3->_22 * v4->_21 + v4->_31 * v3->_23 + v3->_24 * v4->_41 + v3->_21 * v4->_11;
  this->_22 = v3->_21 * v4->_12 + v4->_22 * v3->_22 + v4->_32 * v3->_23 + v4->_42 * v3->_24;
  this->_23 = v3->_22 * v4->_23 + v4->_33 * v3->_23 + v4->_43 * v3->_24 + v3->_21 * v4->_13;
  this->_24 = v3->_21 * v4->_14 + v3->_24 * v4->_44 + v3->_23 * v4->_34 + v3->_22 * v4->_24;
  this->_31 = v3->_32 * v4->_21 + v4->_31 * v3->_33 + v3->_34 * v4->_41 + v3->_31 * v4->_11;
  this->_32 = v3->_31 * v4->_12 + v4->_22 * v3->_32 + v4->_42 * v3->_34 + v4->_32 * v3->_33;
  this->_33 = v3->_32 * v4->_23 + v4->_43 * v3->_34 + v4->_33 * v3->_33 + v3->_31 * v4->_13;
  this->_34 = v3->_31 * v4->_14 + v3->_34 * v4->_44 + v3->_33 * v4->_34 + v3->_32 * v4->_24;
  this->_41 = v3->_42 * v4->_21 + v4->_31 * v3->_43 + v3->_44 * v4->_41 + v3->_41 * v4->_11;
  this->_42 = v3->_41 * v4->_12 + v4->_22 * v3->_42 + v4->_42 * v3->_44 + v4->_32 * v3->_43;
  this->_43 = v3->_42 * v4->_23 + v4->_43 * v3->_44 + v4->_33 * v3->_43 + v3->_41 * v4->_13;
  this->_44 = v3->_41 * v4->_14 + v3->_44 * v4->_44 + v3->_43 * v4->_34 + a->_42 * b->_24;
}

//----- (0043DA40) --------------------------------------------------------  // acclient.c:122378
unsigned int __cdecl RGBAColor::MakeRGBA(float r, float g, float b, float a)
{
  return (((unsigned int)(unsigned __int64)(g * 255.0) | (((unsigned int)(unsigned __int64)(r * 255.0) | ((unsigned int)(unsigned __int64)(a * 255.0) << 8)) << 8)) << 8) | (unsigned __int64)(b * 255.0);
}

//----- (0043DA90) --------------------------------------------------------  // acclient.c:122384
const float *__cdecl _STL::min(const float *__a, const float *__b)
{
  const float *result; // eax@1

  result = __b;
  if ( *__b >= (double)*__a )
    result = __a;
  return result;
}

//----- (0043DAB0) --------------------------------------------------------  // acclient.c:122395
void __thiscall MaterialLayer::SetDiffuse(MaterialLayer *this, RGBAColor *_cColor)
{
  this->m_cDiffuse = *_cColor;
}

//----- (0043DAD0) --------------------------------------------------------  // acclient.c:122401
void __cdecl SceneTool::BeginScene()
{
  int v0; // [sp+0h] [bp-10h]@2
  int v1; // [sp+4h] [bp-Ch]@2
  int v2; // [sp+8h] [bp-8h]@2
  int v3; // [sp+Ch] [bp-4h]@2

  if ( !RenderDevice::render_device->m_bOpenScene )
  {
    ++SceneTool::sceneTimestamp;
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v3 = 1065353216;
    ((void (__stdcall *)(signed int, int *, signed int))RenderDevice::render_device->vfptr->Clear)(7, &v0, 1065353216);
    ((void (__cdecl *)(int, int, int, int))RenderDevice::render_device->vfptr->BeginScene)(v0, v1, v2, v3);
  }
}
// 817C08: using guessed type unsigned __int32 SceneTool::sceneTimestamp;

//----- (0043DB30) --------------------------------------------------------  // acclient.c:122422
void __cdecl SceneTool::ViewportToClip(const int _nX, const int _nY, float *_fClipX, float *_fClipY)
{
  double v4; // st7@1
  double v5; // st6@1

  v4 = 1.0 / (double)(signed int)RenderDevice::render_device->m_viewportWidth;
  v5 = 1.0 / (double)(signed int)RenderDevice::render_device->m_viewportHeight;
  *_fClipX = (double)_nX * v4 + (double)_nX * v4 - 1.0;
  *_fClipY = -((double)_nY * v5 + (double)_nY * v5 - 1.0);
  *_fClipX = *_fClipX - v4;
  *_fClipY = *_fClipY - v5;
}

//----- (0043DB90) --------------------------------------------------------  // acclient.c:122436
char __cdecl SceneTool::BuildCylinderMesh(RenderMesh *pMesh)
{
  long double v1; // st7@3
  unsigned int v2; // eax@3
  int v3; // eax@6
  float v4; // ecx@6
  float v5; // ecx@6
  float v6; // ecx@6
  float v7; // ecx@6
  float v8; // ecx@6
  float v9; // ecx@6
  float v10; // ecx@6
  float v11; // ecx@6
  float v12; // ecx@6
  float v13; // ecx@6
  float v14; // ecx@6
  float v15; // ecx@6
  float v16; // ecx@6
  float v17; // ecx@6
  float v18; // ecx@6
  float v19; // ecx@6
  float v20; // ecx@6
  float v21; // edi@6
  float v22; // ecx@6
  float v23; // ecx@6
  float v24; // edi@6
  float v25; // edi@6
  float v26; // edi@6
  float v27; // edi@6
  float v28; // edi@6
  float v29; // edi@6
  float v30; // edi@6
  float v31; // edi@6
  float v32; // edi@6
  float v33; // edi@6
  float v34; // edi@6
  float v35; // edi@6
  float v36; // edi@6
  float v37; // edi@6
  float v38; // edi@6
  float v39; // edi@6
  float v40; // edi@6
  float v41; // edi@6
  float v42; // edi@6
  float v43; // edi@6
  float v44; // edi@6
  float v45; // edi@6
  float v46; // edi@6
  float v47; // edi@6
  float v48; // edi@6
  float v49; // edi@6
  float v50; // edi@6
  float v51; // edi@6
  float v52; // edi@6
  float v53; // edi@6
  float v54; // edi@6
  float v55; // edi@6
  float v56; // edi@6
  float v57; // edi@6
  float v58; // edi@6
  float v59; // edi@6
  float v60; // edi@6
  float v61; // edi@6
  float v62; // edi@6
  float v63; // edi@6
  float v64; // edi@6
  float v65; // edi@6
  float v66; // edi@6
  float v67; // edi@6
  float v68; // edi@6
  float v69; // edi@6
  float v70; // edi@6
  float v71; // edi@6
  float v72; // edi@6
  float v73; // edi@6
  float v74; // edi@6
  float v75; // edi@6
  float v76; // edi@6
  char result; // al@6
  float v78; // [sp+4h] [bp-58h]@4
  RenderVertexBuffer *pVertexArray; // [sp+8h] [bp-54h]@4
  float circle[10][2]; // [sp+Ch] [bp-50h]@6

  if ( !(_S218_12 & 1) )
  {
    _S218_12 |= 1u;
    *(_QWORD *)&RAD_STEP = 4603834609746899168i64;
  }
  v1 = 0.0;
  v2 = 0;
  do
  {
    ++v2;
    *(&v78 + 2 * v2) = cos(v1);
    *((float *)&pVertexArray + 2 * v2) = sin(v1);
    v1 = v1 + RAD_STEP;
  }
  while ( v2 < 0xA );
  if ( RenderMesh::CreateLODBatch(pMesh, 0, 0, PRIMTYPE_TRIANGLELIST, 0xFFFFFFFF, 0x6Cu, 2u, 1, 1, &pVertexArray) )
  {
    v3 = ((int (__stdcall *)(_DWORD, signed int))pVertexArray->vfptr[3].__vecDelDtor)(0, 108);
    *(_QWORD *)v3 = *(_QWORD *)circle[0];
    v4 = circle[1][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v4;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[1][1]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[2];
    v5 = circle[0][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v5;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v6 = circle[2][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v6;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v7 = circle[3][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v7;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v8 = circle[0][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v8;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v9 = circle[3][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v9;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v10 = circle[4][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v10;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v11 = circle[0][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v11;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v12 = circle[4][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v12;
    v3 += 12;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[4][1]);
    v13 = circle[5][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v13;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[5][1]);
    v14 = circle[0][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v14;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[0][1]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[5];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[6][0]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[6][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[6];
    v15 = circle[7][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v15;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v16 = circle[0][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v16;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v17 = circle[7][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v17;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v18 = circle[8][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v18;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v19 = circle[0][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v19;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v20 = circle[8][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v20;
    v21 = circle[1][0];
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v22 = circle[9][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v22;
    v3 += 12;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[9][1]);
    v23 = circle[2][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v23;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[2][1]);
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v21;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[1][1]);
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[0];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[3][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[2];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[0];
    v24 = circle[4][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v24;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v25 = circle[3][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v25;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v26 = circle[0][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v26;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v27 = circle[5][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v27;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[5][1]);
    v28 = circle[4][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v28;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v29 = circle[0][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v29;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v30 = circle[6][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(float *)(v3 + 12) = v30;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[6][1]);
    v31 = circle[5][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(float *)(v3 + 12) = v31;
    v3 += 12;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[5][1]);
    v32 = circle[0][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v32;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[0][1]);
    v33 = circle[7][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v33;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[7][1]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[6];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[0][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[8][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[7];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[0];
    v34 = circle[9][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v34;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[9][1]);
    v35 = circle[8][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v35;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v36 = circle[0][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v36;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v37 = circle[0][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v37;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v38 = circle[1][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v38;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[1][1]);
    v39 = circle[0][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v39;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v40 = circle[0][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v40;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[0][1]);
    v41 = circle[1][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v41;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[1][1]);
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[1];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[1][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[1][1]);
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[2][0]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[1];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[1];
    v42 = circle[2][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v42;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v43 = circle[2][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v43;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v44 = circle[2][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v44;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v45 = circle[3][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v45;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v46 = circle[2][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v46;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v47 = circle[2][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v47;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[2][1]);
    v48 = circle[3][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(float *)(v3 + 12) = v48;
    v3 += 12;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[3][1]);
    v49 = circle[3][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v49;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[3][1]);
    v50 = circle[3][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v50;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[3][1]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[4];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[3][0]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[3][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[3][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[4];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[4];
    v51 = circle[4][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v51;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v52 = circle[5][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v52;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[5][1]);
    v53 = circle[4][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v53;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v54 = circle[4][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v54;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[4][1]);
    v55 = circle[5][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v55;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[5][1]);
    v56 = circle[5][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(float *)(v3 + 12) = v56;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[5][1]);
    v57 = circle[5][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v57;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[5][1]);
    v58 = circle[6][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v58;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[6][1]);
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[5];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[5][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[5][1]);
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[6][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[6][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[6];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[6];
    v59 = circle[7][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v59;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v60 = circle[6][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v60;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[6][1]);
    v61 = circle[6][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v61;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[6][1]);
    v62 = circle[7][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v62;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v63 = circle[7][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v63;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v64 = circle[7][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v64;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[7][1]);
    v65 = circle[8][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(float *)(v3 + 12) = v65;
    v3 += 12;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[8][1]);
    v66 = circle[7][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v66;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[7][1]);
    v67 = circle[7][0];
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v67;
    *(_DWORD *)(v3 + 8) = -1090519040;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[7][1]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[8];
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[8][0]);
    *(_DWORD *)(v3 + 20) = 1056964608;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v3 += 12;
    *(_DWORD *)(v3 + 12) = LODWORD(circle[8][0]);
    *(_DWORD *)(v3 + 20) = -1090519040;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[9];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(_QWORD *)(v3 + 12) = *(_QWORD *)circle[8];
    v68 = circle[8][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v68;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[8][1]);
    v69 = circle[9][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v69;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[9][1]);
    v70 = circle[9][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v70;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[9][1]);
    v71 = circle[9][0];
    *(_DWORD *)(v3 + 20) = 1056964608;
    v3 += 12;
    *(float *)(v3 + 12) = v71;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[9][1]);
    v72 = circle[0][0];
    *(_DWORD *)(v3 + 20) = -1090519040;
    v3 += 12;
    *(float *)(v3 + 12) = v72;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[0][1]);
    v73 = circle[9][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    *(float *)(v3 + 12) = v73;
    *(_DWORD *)(v3 + 16) = LODWORD(circle[9][1]);
    v74 = circle[9][0];
    v3 += 12;
    *(_DWORD *)(v3 + 8) = 1056964608;
    v3 += 12;
    *(float *)v3 = v74;
    *(_DWORD *)(v3 + 4) = LODWORD(circle[9][1]);
    v75 = circle[0][0];
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(float *)v3 = v75;
    v76 = circle[0][1];
    *(_DWORD *)(v3 + 4) = LODWORD(circle[0][1]);
    *(_DWORD *)(v3 + 8) = -1090519040;
    v3 += 12;
    *(_DWORD *)v3 = LODWORD(circle[0][0]);
    *(float *)(v3 + 4) = v76;
    *(_DWORD *)(v3 + 8) = 1056964608;
    ((void (__stdcall *)(_DWORD, _DWORD))pVertexArray->vfptr[4].__vecDelDtor)(0, 0);
    RenderMesh::UpdateCachedData(pMesh);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0043E4A0) --------------------------------------------------------  // acclient.c:123030
void __cdecl SceneTool::StoreMatrices()
{
  qmemcpy(&SceneTool::m_oldWorldMatrix, &RenderDevice::render_device->m_GState, 0x40u);
  qmemcpy(&SceneTool::m_oldViewMatrix, &RenderDevice::render_device->m_GState.WorldToViewMatrix, 0x40u);
  qmemcpy(&SceneTool::m_oldProjMatrix, &RenderDevice::render_device->m_GState.ViewToClipMatrix, 0x40u);
  g_bMatrixStored = 1;
}

//----- (0043E4F0) --------------------------------------------------------  // acclient.c:123039
void __cdecl SceneTool::PrepareGraphicsDevice()
{
  Render::CheckForLostDevice();
  Render::UpdateFromPreferences();
}

//----- (0043E510) --------------------------------------------------------  // acclient.c:123046
void __cdecl SceneTool::UpdateFPSCounter()
{
  long double v0; // st7@1
  long double v1; // st6@1
  unsigned int v2; // eax@1
  double v3; // st5@1
  double v4; // st5@2
  unsigned int v5; // eax@5

  v0 = Timer::compute_local_time();
  v1 = v0 - SceneTool::m_LastFlipTime;
  v2 = 0;
  v3 = 0.0;
  do
  {
    v4 = v3 + *(float *)&(&SceneTool::m_LastFrameTimes)[v2 / 4];
    v2 += 40;
    v3 = v4
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.blueBitMask + v2)
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.alphaBitMask + v2)
       + *(float *)(&PixelFormatDesc_A8R8G8B8_6.redBitCount + v2)
       + *(float *)(&PixelFormatDesc_A8R8G8B8_6.redBitOffset + v2)
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.redMax + v2)
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.greenMax + v2)
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.blueMax + v2)
       + *(float *)((char *)&PixelFormatDesc_A8R8G8B8_6.alphaMax + v2)
       + flt_8373B4[v2 / 4];
  }
  while ( v2 < 0x50 );
  LODWORD(SceneTool::m_FramesPerSecond) = 0;
  if ( v3 > 0.00019999999 )
    SceneTool::m_FramesPerSecond = 20.0 / v3;
  v5 = (unsigned int)&unk_837404;
  do
  {
    *(_DWORD *)v5 = *(_DWORD *)(v5 - 4);
    v5 -= 4;
  }
  while ( v5 > (unsigned int)&SceneTool::m_LastFrameTimes );
  *(float *)&SceneTool::m_LastFrameTimes = v1;
  SceneTool::m_LastFlipTime = v0;
}
// 8373B4: using guessed type float flt_8373B4[];
// 8373B8: using guessed type float *SceneTool::m_LastFrameTimes;
// 837410: using guessed type double SceneTool::m_LastFlipTime;
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (0043E5C0) --------------------------------------------------------  // acclient.c:123094
void __cdecl SceneTool::PurgeOldGraphicsResources()
{
  long double dTimeNow; // [sp+0h] [bp-8h]@1

  dTimeNow = Timer::local_time;
  if ( Timer::local_time - SceneTool::m_dLastOldResourcePurgeTime > 5.0 )
  {
    if ( RenderDeviceD3D::IsAvailableVideoMemoryLow((RenderDeviceD3D *)RenderDevice::render_device) )
      GraphicsResource::PurgeOldResources(120.0);
    SceneTool::m_dLastOldResourcePurgeTime = dTimeNow;
  }
}
// 837428: using guessed type double SceneTool::m_dLastOldResourcePurgeTime;

//----- (0043E630) --------------------------------------------------------  // acclient.c:123109
AC1Legacy::Vector3 *__cdecl LandDefs::get_block_offset(AC1Legacy::Vector3 *result, unsigned int cell_from, unsigned int cell_to)
{
  unsigned int v3; // eax@1
  AC1Legacy::Vector3 *v4; // eax@2
  unsigned int v5; // ecx@4
  int v6; // edi@4
  unsigned int v7; // eax@7
  unsigned int v8; // edx@7
  double v9; // st7@9

  v3 = cell_from >> 16;
  if ( cell_from >> 16 == cell_to >> 16 )
  {
    v4 = result;
    COERCE_AC1LEGACY__VECTOR3(result->x) = Legacy_Vector3_ZeroVector___8;
  }
  else
  {
    if ( cell_from )
    {
      v5 = (cell_from >> 21) & 0x7F8;
      v6 = 8 * (unsigned __int8)v3;
    }
    else
    {
      v6 = 0;
      v5 = 0;
    }
    if ( cell_to )
    {
      v7 = (cell_to >> 21) & 0x7F8;
      v8 = 8 * ((cell_to >> 16) & 0xFF);
    }
    else
    {
      v8 = cell_from;
      v7 = cell_from;
    }
    v9 = (double)(signed int)(v7 - v5);
    v4 = result;
    LODWORD(result->z) = 0;
    result->x = v9 * 24.0;
    result->y = (double)(signed int)(v8 - v6) * 24.0;
  }
  return v4;
}

//----- (0043E6E0) --------------------------------------------------------  // acclient.c:123157
void __thiscall Vector3::Normalize(Vector3 *this)
{
  long double v1; // st4@1

  v1 = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  this->x = 1.0 / v1 * this->x;
  this->y = 1.0 / v1 * this->y;
  this->z = 1.0 / v1 * this->z;
}

//----- (0043E720) --------------------------------------------------------  // acclient.c:123168
int __thiscall Position::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  Frame::operator=(this + 8, a2 + 8);
  return v2;
}

//----- (0043E740) --------------------------------------------------------  // acclient.c:123179
void __cdecl SceneTool::SetupCamera(Position *position)
{
  unk_817C7C = position->objcell_id;
  Frame::operator=((int)&stru_817C80, (int)&position->frame);
}

//----- (0043E760) --------------------------------------------------------  // acclient.c:123186
void __cdecl SceneTool::SwapMatrixForwardAndUp(Matrix4 *_mMatrix)
{
  double v1; // st7@1
  float v2; // edx@1
  float v3; // ST0C_4@1
  float v4; // ecx@1
  float v5; // ST10_4@1
  float v6; // ST04_4@1
  float v7; // ST40_4@1
  float tempOrigin_4; // ST34_4@1
  float v9; // edx@1

  v1 = _mMatrix->_12;
  v2 = _mMatrix->_22;
  v3 = _mMatrix->_21;
  _mMatrix->_12 = _mMatrix->_13;
  v4 = _mMatrix->_23;
  v5 = v2;
  _mMatrix->_13 = v1;
  v6 = _mMatrix->_32;
  v7 = _mMatrix->_42;
  tempOrigin_4 = _mMatrix->_43;
  v9 = _mMatrix->_33;
  _mMatrix->_21 = _mMatrix->_31;
  _mMatrix->_22 = v9;
  _mMatrix->_23 = v6;
  _mMatrix->_31 = v3;
  _mMatrix->_32 = v4;
  _mMatrix->_33 = v5;
  _mMatrix->_42 = tempOrigin_4;
  _mMatrix->_43 = v7;
}

//----- (0043E7F0) --------------------------------------------------------  // acclient.c:123220
void __cdecl SceneTool::SwapTransposedMatrixForwardAndUp(Matrix4 *_mMatrix)
{
  double v1; // st7@1
  float v2; // edx@1
  float v3; // ST0C_4@1
  float v4; // ecx@1
  float v5; // ST10_4@1
  float v6; // ST04_4@1
  float v7; // ST40_4@1
  float tempOrigin_4; // ST34_4@1
  float v9; // edx@1

  v1 = _mMatrix->_21;
  v2 = _mMatrix->_22;
  v3 = _mMatrix->_12;
  _mMatrix->_21 = _mMatrix->_31;
  v4 = _mMatrix->_32;
  v5 = v2;
  _mMatrix->_31 = v1;
  v6 = _mMatrix->_23;
  v7 = _mMatrix->_42;
  tempOrigin_4 = _mMatrix->_43;
  v9 = _mMatrix->_33;
  _mMatrix->_12 = _mMatrix->_13;
  _mMatrix->_22 = v9;
  _mMatrix->_32 = v6;
  _mMatrix->_13 = v3;
  _mMatrix->_23 = v4;
  _mMatrix->_33 = v5;
  _mMatrix->_42 = tempOrigin_4;
  _mMatrix->_43 = v7;
}

//----- (0043E880) --------------------------------------------------------  // acclient.c:123254
void __cdecl SceneTool::DrawLine(Vector3 *_a, Vector3 *_b, RGBAColor *_color, DepthTestMode _depthTest, bool _depthWrite)
{
  int v5; // eax@1
  MaterialLayer **v6; // edx@1
  MaterialLayer *v7; // esi@1

  v5 = ((int (__stdcall *)(_DWORD, _DWORD))SceneTool::m_pPrimVertexBuffer->vfptr[3].__vecDelDtor)(0, 2);
  *(Vector3 *)v5 = *_a;
  *(Vector3 *)(v5 + 20) = *_b;
  ((void (__stdcall *)(_DWORD, _DWORD))SceneTool::m_pPrimVertexBuffer->vfptr[4].__vecDelDtor)(0, 0);
  v6 = SceneTool::m_pPrimMaterial->layers.m_data;
  v7 = *v6;
  LayerStage::SetTexture(*(*v6)->m_Stages.m_data, 0);
  (*v7->m_Stages.m_data)->m_FFColorOp = 3;
  (*v7->m_Stages.m_data)->m_FFAlphaOp = 3;
  v7->m_SourceBlend = 5;
  v7->m_DestBlend = 6;
  v7->m_DepthWrite = _depthWrite;
  v7->m_DepthTest = _depthTest;
  v7->m_CullMode = 1;
  RenderVertexBuffer::RenderUsingMaterial(
    SceneTool::m_pPrimVertexBuffer,
    PRIMTYPE_LINELIST,
    0,
    1u,
    SceneTool::m_pPrimMaterial,
    SceneTool::m_pPrimMaterial,
    0,
    _color,
    &RGBAColor_Black_9,
    0,
    0);
}

//----- (0043E950) --------------------------------------------------------  // acclient.c:123289
void __cdecl SceneTool::DrawTexturedTriangle(Vector3 *a, Vector3 *b, Vector3 *c, TexCoordPair *_UVa, TexCoordPair *_UVb, TexCoordPair *_UVc, RenderTexture *_pTexture, RGBAColor *color, const bool depthTest, const bool depthWrite, CullModeType cullMode, BlendMode _SourceBlend, BlendMode _DestBlend, const bool _TextureHasAlpha)
{
  int v14; // eax@1
  MaterialLayer *v15; // esi@3

  v14 = ((int (__stdcall *)(_DWORD, _DWORD))SceneTool::m_pPrimVertexBuffer->vfptr[3].__vecDelDtor)(0, 3);
  *(Vector3 *)v14 = *a;
  *(Vector3 *)(v14 + 20) = *b;
  *(Vector3 *)(v14 + 40) = *c;
  if ( _pTexture )
  {
    *(_QWORD *)(v14 + 12) = *_UVa;
    *(_QWORD *)(v14 + 32) = *_UVb;
    *(_QWORD *)(v14 + 52) = *_UVc;
  }
  ((void (__stdcall *)(_DWORD, _DWORD))SceneTool::m_pPrimVertexBuffer->vfptr[4].__vecDelDtor)(0, 0);
  v15 = *SceneTool::m_pPrimMaterial->layers.m_data;
  LayerStage::SetTexture(*v15->m_Stages.m_data, _pTexture);
  (*v15->m_Stages.m_data)->m_FFColorOp = (_pTexture != 0) + 3;
  (*v15->m_Stages.m_data)->m_FFAlphaOp = (_TextureHasAlpha != 0) + 3;
  v15->m_SourceBlend = _SourceBlend;
  v15->m_DestBlend = _DestBlend;
  v15->m_DepthWrite = depthWrite;
  v15->m_CullMode = cullMode;
  v15->m_DepthTest = 4 * (depthTest == 0) + 4;
  RenderVertexBuffer::RenderUsingMaterial(
    SceneTool::m_pPrimVertexBuffer,
    PRIMTYPE_TRIANGLELIST,
    0,
    1u,
    SceneTool::m_pPrimMaterial,
    SceneTool::m_pPrimMaterial,
    0,
    color,
    &RGBAColor_Black_9,
    0,
    0);
}

//----- (0043EA90) --------------------------------------------------------  // acclient.c:123329
void __cdecl SceneTool::DrawTriangle(Vector3 *a, Vector3 *b, Vector3 *c, RGBAColor *color, const bool depthTest, const bool depthWrite, CullModeType cullMode, BlendMode _SourceBlend, BlendMode _DestBlend)
{
  TexCoordPair dummy; // [sp+0h] [bp-8h]@1

  LODWORD(dummy.v) = 0;
  LODWORD(dummy.u) = 0;
  SceneTool::DrawTexturedTriangle(
    a,
    b,
    c,
    &dummy,
    &dummy,
    &dummy,
    0,
    color,
    depthTest,
    depthWrite,
    cullMode,
    _SourceBlend,
    _DestBlend,
    0);
}

//----- (0043EAF0) --------------------------------------------------------  // acclient.c:123353
void __cdecl SceneTool::DrawPolygon(Vector3 *points, const unsigned int numPoints, RGBAColor *color, const bool depthTest, const bool depthWrite, CullModeType cullMode, BlendMode _SourceBlend, BlendMode _DestBlend)
{
  Vector3 *v8; // eax@2
  const unsigned int v9; // edi@2
  int v10; // esi@3
  TexCoordPair _UVa; // [sp+10h] [bp-8h]@2

  if ( (signed int)(numPoints - 1) > 1 )
  {
    LODWORD(_UVa.v) = 0;
    LODWORD(_UVa.u) = 0;
    v8 = points + 1;
    v9 = numPoints - 2;
    do
    {
      v10 = (int)&v8[1];
      SceneTool::DrawTexturedTriangle(
        points,
        v8,
        v8 + 1,
        &_UVa,
        &_UVa,
        &_UVa,
        0,
        color,
        depthTest,
        depthWrite,
        cullMode,
        _SourceBlend,
        _DestBlend,
        0);
      --v9;
      v8 = (Vector3 *)v10;
    }
    while ( v9 );
  }
}

//----- (0043EB70) --------------------------------------------------------  // acclient.c:123392
void __cdecl SceneTool::DrawTexturedPolygon(Vector3 *points, const unsigned int numPoints, TexCoordPair *_pUVPairs, RenderTexture *_pTexture, RGBAColor *color, const bool depthTest, const bool depthWrite, CullModeType cullMode, BlendMode _SourceBlend, BlendMode _DestBlend, const bool _TextureHasAlpha)
{
  Vector3 *v11; // ecx@2
  TexCoordPair *v12; // eax@2
  const unsigned int v13; // ebx@2
  int v14; // esi@3
  int v15; // edi@3

  if ( (signed int)(numPoints - 1) > 1 )
  {
    v11 = points + 1;
    v12 = _pUVPairs + 1;
    v13 = numPoints - 2;
    do
    {
      v14 = (int)&v12[1];
      v15 = (int)&v11[1];
      SceneTool::DrawTexturedTriangle(
        points,
        v11,
        v11 + 1,
        _pUVPairs,
        v12,
        v12 + 1,
        _pTexture,
        color,
        depthTest,
        depthWrite,
        cullMode,
        _SourceBlend,
        _DestBlend,
        _TextureHasAlpha);
      --v13;
      v12 = (TexCoordPair *)v14;
      v11 = (Vector3 *)v15;
    }
    while ( v13 );
  }
}

//----- (0043EBE0) --------------------------------------------------------  // acclient.c:123433
char __cdecl SceneTool::BuildSphereMesh(RenderMesh *pMesh)
{
  unsigned int v1; // eax@1
  signed int v2; // ebp@15
  signed int v3; // edi@15
  unsigned int v4; // esi@16
  void *v5; // ebx@16
  int v6; // eax@17
  int v7; // ecx@17
  double v8; // st7@18
  double v9; // st6@18
  double v10; // rt0@18
  double v11; // st6@18
  long double v12; // st5@18
  float a; // ST34_4@18
  float a_4; // ST38_4@18
  float a_8; // ST3C_4@18
  double v16; // st7@18
  double v17; // st6@18
  double v18; // rt1@18
  double v19; // st6@18
  long double v20; // st5@18
  int v21; // esi@18
  float b; // ST50_4@18
  float b_4; // ST54_4@18
  float b_8; // ST58_4@18
  double v25; // st7@18
  double v26; // st6@18
  double v27; // rt2@18
  double v28; // st6@18
  float c_4; // ST44_4@18
  float c_8; // ST48_4@18
  double v31; // st5@18
  int v32; // edx@18
  int v33; // ebx@18
  long double v34; // st7@18
  float c; // ST40_4@18
  float v36; // ST44_4@18
  float v37; // ST48_4@18
  int v38; // ebx@18
  int v39; // ebx@18
  int v40; // ebx@18
  int v41; // ebx@18
  int v42; // ebp@18
  int v43; // ebp@18
  int v44; // edi@18
  int v45; // edi@18
  int v46; // edi@18
  char result; // al@24
  Vector3 *pPrev; // [sp+18h] [bp-90h]@15
  signed int v49; // [sp+28h] [bp-80h]@17
  RenderVertexBuffer *pVertexArray; // [sp+2Ch] [bp-7Ch]@23
  unsigned int nLevel; // [sp+30h] [bp-78h]@15
  int v52; // [sp+34h] [bp-74h]@18
  float v53; // [sp+38h] [bp-70h]@18
  float v54; // [sp+3Ch] [bp-6Ch]@18
  int v55; // [sp+40h] [bp-68h]@18
  float v56; // [sp+44h] [bp-64h]@18
  float v57; // [sp+48h] [bp-60h]@18
  void *v58; // [sp+4Ch] [bp-5Ch]@16
  unsigned int nNumCurTris; // [sp+50h] [bp-58h]@16
  int v60; // [sp+54h] [bp-54h]@18
  float v61; // [sp+58h] [bp-50h]@18
  float v62; // [sp+5Ch] [bp-4Ch]@18
  int v63; // [sp+60h] [bp-48h]@18
  int v64; // [sp+6Ch] [bp-3Ch]@18
  int v65; // [sp+78h] [bp-30h]@18
  float v66; // [sp+8Ch] [bp-1Ch]@18
  float v67; // [sp+98h] [bp-10h]@18
  float v68; // [sp+A4h] [bp-4h]@18

  v1 = _S219_32;
  if ( !(_S219_32 & 1) )
  {
    v1 = _S219_32 | 1;
    _S219_32 |= 1u;
    LODWORD(XMAX.x) = 1065353216;
    LODWORD(XMAX.y) = 0;
    LODWORD(XMAX.z) = 0;
  }
  if ( !(v1 & 2) )
  {
    v1 |= 2u;
    _S219_32 = v1;
    LODWORD(XMIN.x) = -1082130432;
    LODWORD(XMIN.y) = 0;
    LODWORD(XMIN.z) = 0;
  }
  if ( !(v1 & 4) )
  {
    v1 |= 4u;
    _S219_32 = v1;
    LODWORD(YMAX.x) = 0;
    LODWORD(YMAX.y) = 1065353216;
    LODWORD(YMAX.z) = 0;
  }
  if ( !(v1 & 8) )
  {
    v1 |= 8u;
    _S219_32 = v1;
    LODWORD(YMIN.x) = 0;
    LODWORD(YMIN.y) = -1082130432;
    LODWORD(YMIN.z) = 0;
  }
  if ( !(v1 & 0x10) )
  {
    v1 |= 0x10u;
    _S219_32 = v1;
    LODWORD(ZMAX.x) = 0;
    LODWORD(ZMAX.y) = 0;
    LODWORD(ZMAX.z) = 1065353216;
  }
  if ( !(v1 & 0x20) )
  {
    v1 |= 0x20u;
    _S219_32 = v1;
    LODWORD(ZMIN.x) = 0;
    LODWORD(ZMIN.y) = 0;
    LODWORD(ZMIN.z) = -1082130432;
  }
  if ( !(v1 & 0x40) )
  {
    _S219_32 = v1 | 0x40;
    octahedron[0] = YMAX;
    *(Vector3 *)&dword_837764 = ZMAX;
    *(Vector3 *)&dword_837770 = XMAX;
    *(Vector3 *)&dword_83777C = XMIN;
    *(Vector3 *)&dword_837788 = ZMAX;
    *(Vector3 *)&dword_837794 = YMAX;
    *(Vector3 *)&dword_8377A0 = YMIN;
    *(Vector3 *)&dword_8377AC = ZMAX;
    *(Vector3 *)&dword_8377B8 = XMIN;
    *(Vector3 *)&dword_8377C4 = XMAX;
    *(Vector3 *)&dword_8377D0 = ZMAX;
    *(Vector3 *)&dword_8377DC = YMIN;
    *(Vector3 *)&dword_8377E8 = ZMIN;
    *(Vector3 *)&dword_8377F4 = YMAX;
    *(Vector3 *)&dword_837800 = XMAX;
    *(Vector3 *)&dword_83780C = ZMIN;
    *(Vector3 *)&dword_837818 = XMIN;
    *(Vector3 *)&dword_837824 = YMAX;
    *(Vector3 *)&dword_837830 = ZMIN;
    *(Vector3 *)&dword_83783C = YMIN;
    *(Vector3 *)&dword_837848 = XMIN;
    *(Vector3 *)&dword_837854 = ZMIN;
    *(Vector3 *)&dword_837860 = XMAX;
    *(Vector3 *)&dword_83786C = YMIN;
  }
  v2 = 1;
  pPrev = octahedron;
  v3 = 8;
  nLevel = 1;
  do
  {
    v4 = 4 * v3;
    nNumCurTris = 4 * v3;
    v5 = operator new[](144 * v3);
    v58 = v5;
    if ( v3 )
    {
      v6 = (int)&pPrev[1].y;
      v7 = (int)((char *)v5 + 132);
      v49 = v3;
      do
      {
        v8 = *(float *)(v6 + 8) + *(float *)(v6 - 16);
        v9 = *(float *)(v6 + 12) + *(float *)(v6 - 12);
        v66 = *(float *)(v6 + 16) + *(float *)(v6 - 8);
        v10 = v9;
        *(float *)&v63 = v8 * 0.5;
        v55 = v63;
        v11 = v66 * 0.5;
        v56 = v10 * 0.5;
        v57 = v11;
        v12 = sqrt(v11 * v11 + v10 * 0.5 * (v10 * 0.5) + *(float *)&v63 * *(float *)&v63);
        a = *(float *)&v63 * (1.0 / v12);
        a_4 = v56 * (1.0 / v12);
        a_8 = v57 * (1.0 / v12);
        v16 = *(float *)(v6 - 4) + *(float *)(v6 - 16);
        v17 = *(float *)(v6 - 12) + *(float *)v6;
        v67 = *(float *)(v6 + 4) + *(float *)(v6 - 8);
        v18 = v17;
        *(float *)&v64 = v16 * 0.5;
        v52 = v64;
        v19 = v67 * 0.5;
        v53 = v18 * 0.5;
        v54 = v19;
        v20 = sqrt(*(float *)&v64 * *(float *)&v64 + v19 * v19 + v18 * 0.5 * (v18 * 0.5));
        v21 = *(_DWORD *)(v6 - 16);
        b = *(float *)&v64 * (1.0 / v20);
        b_4 = v53 * (1.0 / v20);
        b_8 = v54 * (1.0 / v20);
        v25 = *(float *)(v6 + 8) + *(float *)(v6 - 4);
        v26 = *(float *)(v6 + 12) + *(float *)v6;
        v68 = *(float *)(v6 + 16) + *(float *)(v6 + 4);
        v27 = v26;
        *(float *)&v65 = v25 * 0.5;
        v60 = v65;
        v28 = v68 * 0.5;
        v61 = v27 * 0.5;
        c_4 = v61;
        v62 = v28;
        c_8 = v62;
        v31 = *(float *)&v65 * *(float *)&v65;
        v32 = v7 - 132;
        *(_DWORD *)v32 = v21;
        *(_DWORD *)(v32 + 4) = *(_DWORD *)(v6 - 12);
        *(_DWORD *)(v32 + 8) = *(_DWORD *)(v6 - 8);
        v33 = v7 - 120;
        *(float *)v33 = b;
        *(float *)(v33 + 4) = b_4;
        *(float *)(v33 + 8) = b_8;
        v34 = 1.0 / sqrt(v31 + v28 * v28 + v27 * 0.5 * (v27 * 0.5));
        c = *(float *)&v65 * v34;
        v36 = c_4 * v34;
        v37 = c_8 * v34;
        v38 = v7 - 108;
        *(float *)v38 = a;
        *(float *)(v38 + 4) = a_4;
        *(float *)(v38 + 8) = a_8;
        v39 = v7 - 96;
        *(float *)v39 = b;
        *(float *)(v39 + 4) = b_4;
        *(float *)(v39 + 8) = b_8;
        v40 = v7 - 84;
        *(_DWORD *)v40 = *(_DWORD *)(v6 - 4);
        *(_DWORD *)(v40 + 4) = *(_DWORD *)v6;
        *(_DWORD *)(v40 + 8) = *(_DWORD *)(v6 + 4);
        v41 = v7 - 72;
        *(float *)v41 = c;
        *(float *)(v41 + 4) = v36;
        *(float *)(v41 + 8) = v37;
        v42 = v7 - 60;
        *(float *)v42 = a;
        *(float *)(v42 + 4) = a_4;
        *(float *)(v42 + 8) = a_8;
        v43 = v7 - 48;
        *(float *)v43 = b;
        *(float *)(v43 + 4) = b_4;
        *(float *)(v43 + 8) = b_8;
        v44 = v7 - 36;
        *(float *)v44 = c;
        *(float *)(v44 + 4) = v36;
        *(float *)(v44 + 8) = v37;
        v45 = v7 - 24;
        *(float *)v45 = a;
        *(float *)(v45 + 4) = a_4;
        *(float *)(v45 + 8) = a_8;
        v46 = v7 - 12;
        *(float *)v46 = c;
        *(float *)(v46 + 4) = v36;
        *(float *)(v46 + 8) = v37;
        *(_DWORD *)v7 = *(_DWORD *)(v6 + 8);
        *(_DWORD *)(v7 + 4) = *(_DWORD *)(v6 + 12);
        *(_DWORD *)(v7 + 8) = *(_DWORD *)(v6 + 16);
        v6 += 36;
        v7 += 144;
        --v49;
      }
      while ( v49 );
      v5 = v58;
      v4 = nNumCurTris;
      v2 = nLevel;
    }
    if ( (unsigned int)v2 > 1 )
      operator delete[](pPrev);
    ++v2;
    pPrev = (Vector3 *)v5;
    v3 = v4;
    nLevel = v2;
  }
  while ( (unsigned int)v2 < 3 );
  if ( RenderMesh::CreateLODBatch(pMesh, 0, 0, PRIMTYPE_TRIANGLELIST, 0xFFFFFFFF, 3 * v4, 2u, 1, 1, &pVertexArray) )
  {
    qmemcpy(
      (void *)((int (__stdcall *)(_DWORD, unsigned int))pVertexArray->vfptr[3].__vecDelDtor)(0, 3 * v4),
      v5,
      4 * (36 * v4 >> 2));
    ((void (__stdcall *)(_DWORD, _DWORD))pVertexArray->vfptr[4].__vecDelDtor)(0, 0);
    operator delete[](v5);
    RenderMesh::UpdateCachedData(pMesh);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 837764: using guessed type int dword_837764;
// 837770: using guessed type int dword_837770;
// 83777C: using guessed type int dword_83777C;
// 837788: using guessed type int dword_837788;
// 837794: using guessed type int dword_837794;
// 8377A0: using guessed type int dword_8377A0;
// 8377AC: using guessed type int dword_8377AC;
// 8377B8: using guessed type int dword_8377B8;
// 8377C4: using guessed type int dword_8377C4;
// 8377D0: using guessed type int dword_8377D0;
// 8377DC: using guessed type int dword_8377DC;
// 8377E8: using guessed type int dword_8377E8;
// 8377F4: using guessed type int dword_8377F4;
// 837800: using guessed type int dword_837800;
// 83780C: using guessed type int dword_83780C;
// 837818: using guessed type int dword_837818;
// 837824: using guessed type int dword_837824;
// 837830: using guessed type int dword_837830;
// 83783C: using guessed type int dword_83783C;
// 837848: using guessed type int dword_837848;
// 837854: using guessed type int dword_837854;
// 837860: using guessed type int dword_837860;
// 83786C: using guessed type int dword_83786C;

//----- (0043F430) --------------------------------------------------------  // acclient.c:123747
void __cdecl SceneTool::IdentityMatrices()
{
  Matrix4 ident; // [sp+8h] [bp-80h]@1
  Matrix4 _mMatrix; // [sp+48h] [bp-40h]@1

  LODWORD(ident._14) = 0;
  LODWORD(ident._13) = 0;
  LODWORD(ident._12) = 0;
  LODWORD(ident._24) = 0;
  LODWORD(ident._23) = 0;
  LODWORD(ident._21) = 0;
  LODWORD(ident._34) = 0;
  LODWORD(ident._32) = 0;
  LODWORD(ident._31) = 0;
  LODWORD(ident._43) = 0;
  LODWORD(ident._42) = 0;
  LODWORD(ident._41) = 0;
  LODWORD(ident._44) = 1065353216;
  LODWORD(ident._33) = 1065353216;
  LODWORD(ident._22) = 1065353216;
  LODWORD(ident._11) = 1065353216;
  qmemcpy(&SceneTool::m_worldMatrix, &ident, sizeof(SceneTool::m_worldMatrix));
  qmemcpy(&_mMatrix, &ident, sizeof(_mMatrix));
  SceneTool::SwapMatrixForwardAndUp(&_mMatrix);
  RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &_mMatrix);
  qmemcpy(&SceneTool::m_viewMatrix, &ident, sizeof(SceneTool::m_viewMatrix));
  qmemcpy(&_mMatrix, &ident, sizeof(_mMatrix));
  SceneTool::SwapTransposedMatrixForwardAndUp(&_mMatrix);
  RenderDeviceD3D::SetWorldToViewMatrix((RenderDeviceD3D *)RenderDevice::render_device, &_mMatrix);
  qmemcpy(&SceneTool::m_projMatrix, &ident, sizeof(SceneTool::m_projMatrix));
  RenderDeviceD3D::SetViewToClipMatrix((RenderDeviceD3D *)RenderDevice::render_device, &SceneTool::m_projMatrix);
}
// 8375B8: using guessed type struct Matrix4 SceneTool::m_worldMatrix;
// 8375F8: using guessed type struct Matrix4 SceneTool::m_viewMatrix;

//----- (0043F560) --------------------------------------------------------  // acclient.c:123783
void __cdecl SceneTool::RestoreMatrices()
{
  Matrix4 _mMatrix; // [sp+8h] [bp-40h]@1

  qmemcpy(&SceneTool::m_worldMatrix, &SceneTool::m_oldWorldMatrix, sizeof(SceneTool::m_worldMatrix));
  g_bMatrixStored = 0;
  qmemcpy(&_mMatrix, &SceneTool::m_oldWorldMatrix, sizeof(_mMatrix));
  SceneTool::SwapMatrixForwardAndUp(&_mMatrix);
  RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &_mMatrix);
  qmemcpy(&SceneTool::m_viewMatrix, &SceneTool::m_oldViewMatrix, sizeof(SceneTool::m_viewMatrix));
  qmemcpy(&_mMatrix, &SceneTool::m_oldViewMatrix, sizeof(_mMatrix));
  SceneTool::SwapTransposedMatrixForwardAndUp(&_mMatrix);
  RenderDeviceD3D::SetWorldToViewMatrix((RenderDeviceD3D *)RenderDevice::render_device, &_mMatrix);
  qmemcpy(&SceneTool::m_projMatrix, &SceneTool::m_oldProjMatrix, sizeof(SceneTool::m_projMatrix));
  RenderDeviceD3D::SetViewToClipMatrix((RenderDeviceD3D *)RenderDevice::render_device, &SceneTool::m_projMatrix);
}
// 8375B8: using guessed type struct Matrix4 SceneTool::m_worldMatrix;
// 8375F8: using guessed type struct Matrix4 SceneTool::m_viewMatrix;

//----- (0043F610) --------------------------------------------------------  // acclient.c:123803
char __cdecl SceneTool::Think()
{
  SceneTool::PurgeOldGraphicsResources();
  if ( SceneTool::m_pDebugConsole )
    DebugConsole::Think(SceneTool::m_pDebugConsole);
  if ( SceneTool::m_pProfilerUI )
    ProfilerUI::Think(SceneTool::m_pProfilerUI);
  s_LastThinkLocalTime = Timer::local_time;
  return 1;
}

//----- (0043F650) --------------------------------------------------------  // acclient.c:123815
void __cdecl SceneTool::RenderDebugHUD()
{
  double v0; // st7@2
  float v1; // ST30_4@2
  float v2; // eax@2
  double v3; // st6@2
  float v4; // ST30_4@2
  double v5; // st7@2
  double v6; // st6@2
  int v7; // esi@2
  int v8; // edi@2
  signed int v9; // ebp@2
  const unsigned int v10; // eax@4
  unsigned __int64 v11; // rax@14
  signed int v12; // ecx@15
  const unsigned int v13; // ebx@22
  PStringBase<char> *v14; // eax@25
  int v15; // ebx@25
  int ShadowY; // [sp+4h] [bp-8Ch]@2
  RGBAColor FPSColor; // [sp+8h] [bp-88h]@15
  RGBAColor color; // [sp+18h] [bp-78h]@2
  float ClipLeft; // [sp+28h] [bp-68h]@2
  float v20; // [sp+2Ch] [bp-64h]@2
  int v21; // [sp+30h] [bp-60h]@17
  int v22; // [sp+34h] [bp-5Ch]@17
  int v23; // [sp+38h] [bp-58h]@17
  int v24; // [sp+3Ch] [bp-54h]@17
  int v25; // [sp+40h] [bp-50h]@15
  int v26; // [sp+44h] [bp-4Ch]@15
  int v27; // [sp+48h] [bp-48h]@15
  int v28; // [sp+4Ch] [bp-44h]@15
  int v29; // [sp+50h] [bp-40h]@19
  int v30; // [sp+54h] [bp-3Ch]@19
  int v31; // [sp+58h] [bp-38h]@19
  int v32; // [sp+5Ch] [bp-34h]@19
  Vector3 ClipPoints[4]; // [sp+60h] [bp-30h]@2

  if ( SceneTool::m_DebugHUDVisible )
  {
    RenderDeviceD3D::SetFillMode((RenderDeviceD3D *)RenderDevice::render_device, FILLMODE_SOLID);
    SceneTool::IdentityMatrices();
    v0 = 1.0 / (double)(signed int)RenderDevice::render_device->m_viewportWidth;
    LODWORD(ClipPoints[0].y) = 0;
    LODWORD(ClipPoints[1].y) = 0;
    LODWORD(ClipPoints[2].y) = 0;
    LODWORD(ClipPoints[3].y) = 0;
    LODWORD(color.r) = 0;
    LODWORD(color.g) = 1031127695;
    LODWORD(color.b) = 1036831949;
    LODWORD(color.a) = 1058642330;
    v1 = v0;
    v2 = RenderDevice::render_device[2].m_GState.PixelFilterTexCoords[2].x;
    v3 = 1.0 / (double)(signed int)RenderDevice::render_device->m_viewportHeight;
    ClipLeft = v1 * 0.0 - 1.0 - v1;
    ClipPoints[0].x = ClipLeft;
    *(float *)&ShadowY = -(0.0 * v3 - 1.0) - v3;
    LODWORD(ClipPoints[0].z) = ShadowY;
    v4 = v0;
    v20 = v3;
    v5 = v4 * 1200.0 - 1.0 - v4;
    ClipPoints[1].x = ClipLeft;
    LODWORD(ClipPoints[3].z) = ShadowY;
    v6 = -((double)(LODWORD(v2) + 3) * v20 + (double)(LODWORD(v2) + 3) * v20 - 1.0) - v20;
    ClipPoints[1].z = v6;
    ClipPoints[2].x = v5;
    ClipPoints[2].z = v6;
    ClipPoints[3].x = v5;
    SceneTool::DrawPolygon(ClipPoints, 4u, &color, 0, 0, CULLMODE_CW, BLEND_SRCALPHA, BLEND_INVSRCALPHA);
    RenderDeviceD3D::BeginRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
    v7 = ShadowY;
    v8 = ShadowY;
    v9 = 8;
    do
    {
      switch ( v9 )
      {
        case 0:
          v7 = 0;
          v8 = 0;
          v10 = -16777216;
          break;
        case 1:
          v7 = 2;
          v8 = 2;
          v10 = -16777216;
          break;
        case 2:
          v7 = 0;
          v8 = 2;
          v10 = -16777216;
          break;
        case 3:
          v7 = 2;
          v8 = 0;
          v10 = -16777216;
          break;
        case 4:
          v7 = 1;
          v8 = 0;
          v10 = -16777216;
          break;
        case 5:
          v7 = 0;
          v8 = 1;
          v10 = -16777216;
          break;
        case 6:
          v7 = 2;
          v8 = 1;
          v10 = -16777216;
          break;
        case 7:
          v7 = 1;
          v8 = 2;
          v10 = -16777216;
          break;
        case 8:
          v7 = 1;
          v8 = 1;
          goto LABEL_13;
        default:
LABEL_13:
          v10 = -5583648;
          break;
      }
      RenderDeviceD3D::RenderDebugText((RenderDeviceD3D *)RenderDevice::render_device, v7, v8, "FPS:", v10);
      v11 = (unsigned __int64)SceneTool::m_FramesPerSecond;
      if ( (signed int)v11 >= 10 )
      {
        if ( (signed int)v11 >= 20 )
        {
          if ( (signed int)v11 >= 30 )
          {
            LODWORD(color.r) = 1062836634;
            LODWORD(color.g) = 1062836634;
            LODWORD(color.b) = 1064514355;
            LODWORD(color.a) = 1065353216;
            LODWORD(FPSColor.r) = 1062836634;
            v12 = 1064514355;
            LODWORD(FPSColor.g) = 1062836634;
          }
          else
          {
            v29 = 1063675494;
            v30 = 1063675494;
            v31 = 1045220557;
            v32 = 1065353216;
            LODWORD(FPSColor.r) = 1063675494;
            v12 = 1045220557;
            LODWORD(FPSColor.g) = 1063675494;
          }
        }
        else
        {
          v21 = 1063675494;
          v22 = 1056964608;
          v23 = 1045220557;
          v24 = 1065353216;
          LODWORD(FPSColor.r) = 1063675494;
          v12 = 1045220557;
          LODWORD(FPSColor.g) = 1056964608;
        }
      }
      else
      {
        v25 = 1065353216;
        v26 = 1045220557;
        v27 = 1045220557;
        v28 = 1065353216;
        LODWORD(FPSColor.r) = 1065353216;
        v12 = 1045220557;
        LODWORD(FPSColor.g) = 1045220557;
      }
      LODWORD(FPSColor.b) = v12;
      LODWORD(FPSColor.a) = 1065353216;
      _sprintf(txt, "%i", v11);
      if ( (unsigned int)v9 >= 8 )
        v13 = (unsigned __int64)(FPSColor.b * 255.0) | (((unsigned int)(unsigned __int64)(FPSColor.g * 255.0) | (((unsigned int)(unsigned __int64)(FPSColor.r * 255.0) | ((unsigned int)(unsigned __int64)(FPSColor.a * 255.0) << 8)) << 8)) << 8);
      else
        v13 = -16777216;
      RenderDeviceD3D::RenderDebugText((RenderDeviceD3D *)RenderDevice::render_device, v7 + 34, v8, txt, v13);
      if ( unk_817C7C )
      {
        v14 = Position::ToDisplayString(&SceneTool::m_CameraPosition, (PStringBase<char> *)&ShadowY);
        _sprintf(txt, "Camera pos: %s", v14->m_charbuffer);
        v15 = ShadowY - 20;
        if ( !InterlockedDecrement((volatile LONG *)(ShadowY - 20 + 4)) )
        {
          if ( v15 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
        }
      }
      else
      {
        _sprintf(txt, "Camera pos: <none>");
      }
      RenderDeviceD3D::RenderDebugText(
        (RenderDeviceD3D *)RenderDevice::render_device,
        v7 + 120,
        v8,
        txt,
        (unsigned int)v9++ < 8 ? -16777216 : -5583648);
    }
    while ( (unsigned int)v9 < 9 );
    RenderDeviceD3D::EndRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
    RenderDeviceD3D::SetFillMode(
      (RenderDeviceD3D *)RenderDevice::render_device,
      (FillModeType)(3 - (RenderDevice::render_device->m_WireframeMode != 0)));
  }
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;
// 837420: using guessed type bool SceneTool::m_DebugHUDVisible;

//----- (0043FB10) --------------------------------------------------------  // acclient.c:124029
void __cdecl SceneTool::DrawLine(Vector3 *a, Vector3 *b, RGBAColor *color, const bool depthTest, const bool depthWrite)
{
  SceneTool::DrawLine(a, b, color, (DepthTestMode)(4 * (depthTest == 0) + 4), depthWrite);
}

//----- (0043FB30) --------------------------------------------------------  // acclient.c:124035
void __usercall SceneTool::EndFrame(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, const bool _bDrawUI, int a6, int a7, int a8, char a9)
{
  int v9; // ST20_4@2
  unsigned int v10; // ebx@2
  int v11; // ST1C_4@2
  int v12; // ST18_4@2
  int v13; // ST14_4@2
  unsigned int v14; // edi@2
  unsigned int width; // ST28_4@2
  RenderDevice *v16; // esi@2
  RenderDeviceVtbl *v17; // ebp@2
  unsigned int height; // ST24_4@2
  unsigned int v19; // ST0C_4@2
  unsigned int v20; // eax@2
  float OldViewportAspect; // [sp+28h] [bp-4h]@2

  if ( RenderDevice::render_device->m_bOpenScene )
  {
    v9 = a1;
    v10 = RenderDevice::render_device->m_viewportY;
    v11 = a2;
    v12 = a4;
    v13 = a3;
    v14 = RenderDevice::render_device->m_viewportX;
    width = RenderDevice::render_device->m_viewportWidth;
    v16 = RenderDevice::render_device;
    v17 = RenderDevice::render_device->vfptr;
    height = RenderDevice::render_device->m_viewportHeight;
    OldViewportAspect = RenderDevice::render_device->m_ViewportAspectRatio;
    v19 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
    v20 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
    ((void (__thiscall *)(RenderDevice *, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, int, int, int, int))v17->SetViewport)(
      v16,
      0,
      0,
      v20,
      v19,
      0,
      v13,
      v12,
      v11,
      v9);
    if ( a9 && SceneTool::m_RenderUIObjects )
    {
      RenderUI::RenderObjects();
      KeyStone::Update();
    }
    if ( SceneTool::m_pProfilerUI )
      ProfilerUI::Render(SceneTool::m_pProfilerUI);
    if ( SceneTool::m_pDebugConsole )
      DebugConsole::Render(SceneTool::m_pDebugConsole);
    SceneTool::RenderDebugHUD();
    ((void (__stdcall *)(unsigned int))RenderDevice::render_device->vfptr->SetViewport)(v14);
    RenderDevice::render_device->m_ViewportAspectRatio = OldViewportAspect;
    ((void (*)(void))RenderDevice::render_device->vfptr->EndScene)();
    ((void (*)(void))RenderDevice::render_device->vfptr->Flip)();
    SceneTool::UpdateFPSCounter();
  }
}
// 43FB30: could not find valid save-restore pair for ebx
// 43FB30: could not find valid save-restore pair for ebp
// 43FB30: could not find valid save-restore pair for edi
// 43FB30: could not find valid save-restore pair for esi
// 817C0C: using guessed type bool SceneTool::m_RenderUIObjects;

//----- (0043FC30) --------------------------------------------------------  // acclient.c:124101
void __thiscall SceneTool::Shutdown(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@2
  char *v2; // esi@5
  char *v3; // esi@8
  ProfilerUI *v4; // ecx@12
  unsigned int v5; // edx@12
  DebugConsole *v6; // ecx@16
  unsigned int v7; // edx@16
  RenderVertexBuffer *v8; // ecx@20
  unsigned int v9; // edx@20
  PStringBase<char> _Name; // [sp+8h] [bp-4h]@1

  _Name.m_charbuffer = this;
  if ( st_init )
  {
    PStringBase<char>::PStringBase<char>(&_Name, "SceneTool.ScreenshotWidthScale");
    GlobalRegistry::UnregisterVariable(&_Name);
    v1 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    PStringBase<char>::PStringBase<char>(&_Name, "SceneTool.ScreenshotHeightScale");
    GlobalRegistry::UnregisterVariable(&_Name);
    v2 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    PStringBase<char>::PStringBase<char>(&_Name, "SceneTool.RenderUIObjects");
    GlobalRegistry::UnregisterVariable(&_Name);
    v3 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    Render::UnlinkRGRCallback((bool (__cdecl *)())DBObj::InitLoad);
    if ( SceneTool::m_pProfilerUI )
    {
      v4 = SceneTool::m_pProfilerUI;
      v5 = SceneTool::m_pProfilerUI->m_cRef - 1;
      SceneTool::m_pProfilerUI->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      SceneTool::m_pProfilerUI = 0;
    }
    if ( SceneTool::m_pDebugConsole )
    {
      v6 = SceneTool::m_pDebugConsole;
      v7 = SceneTool::m_pDebugConsole->m_cRef - 1;
      SceneTool::m_pDebugConsole->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      SceneTool::m_pDebugConsole = 0;
    }
    if ( SceneTool::m_pPrimVertexBuffer )
    {
      v8 = SceneTool::m_pPrimVertexBuffer;
      v9 = SceneTool::m_pPrimVertexBuffer->m_cRef - 1;
      SceneTool::m_pPrimVertexBuffer->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      SceneTool::m_pPrimVertexBuffer = 0;
    }
    if ( SceneTool::m_pCylinderMesh )
    {
      ((void (*)(void))SceneTool::m_pCylinderMesh->vfptr->Release)();
      SceneTool::m_pCylinderMesh = 0;
    }
    if ( SceneTool::m_pSphereMesh )
    {
      ((void (*)(void))SceneTool::m_pSphereMesh->vfptr->Release)();
      SceneTool::m_pSphereMesh = 0;
    }
    if ( SceneTool::m_pDefaultMaterial )
    {
      ((void (*)(void))SceneTool::m_pDefaultMaterial->vfptr->Release)();
      SceneTool::m_pDefaultMaterial = 0;
    }
    if ( SceneTool::m_pPrimMaterial )
    {
      ((void (*)(void))SceneTool::m_pPrimMaterial->vfptr->Release)();
      SceneTool::m_pPrimMaterial = 0;
    }
    if ( SceneTool::m_pPrimObjectMaterial )
    {
      ((void (*)(void))SceneTool::m_pPrimObjectMaterial->vfptr->Release)();
      SceneTool::m_pPrimObjectMaterial = 0;
    }
    if ( SceneTool::m_pScreenShotSurface )
    {
      ((void (*)(void))SceneTool::m_pScreenShotSurface->vfptr->Release)();
      SceneTool::m_pScreenShotSurface = 0;
    }
    st_init = 0;
  }
}
// 837430: using guessed type struct RenderSurface *SceneTool::m_pScreenShotSurface;
// 837460: using guessed type struct RenderMesh *SceneTool::m_pCylinderMesh;
// 837464: using guessed type struct RenderMesh *SceneTool::m_pSphereMesh;

//----- (0043FE00) --------------------------------------------------------  // acclient.c:124198
void __thiscall MaterialLayer::InsertStage(MaterialLayer *this, const unsigned int _Index, LayerStage *_pStage)
{
  SmartArray<LayerStage *,1>::InsertOrderedByIndex(
    (SmartArray<EffectInfoRegion *,1> *)&this->m_Stages,
    (EffectInfoRegion *const *)&_pStage,
    _Index);
}

//----- (0043FE20) --------------------------------------------------------  // acclient.c:124207
void __thiscall RenderMaterial::InsertLayer(RenderMaterial *this, const unsigned int index, MaterialLayer *_pLayer)
{
  SmartArray<LayerStage *,1>::InsertOrderedByIndex(
    (SmartArray<EffectInfoRegion *,1> *)&this->layers,
    (EffectInfoRegion *const *)&_pLayer,
    index);
}

//----- (0043FE40) --------------------------------------------------------  // acclient.c:124216
char __cdecl SceneTool::CreateDefaultMaterial()
{
  RenderMaterial *v0; // eax@7
  RenderMaterial *v1; // eax@8
  MaterialLayer *v2; // eax@9
  int v3; // eax@10
  int v4; // esi@10
  LayerStage *v5; // eax@11
  int v6; // eax@12
  RenderMaterial *v7; // eax@13
  RenderMaterial *v8; // eax@14
  MaterialLayer *v9; // eax@15
  int v10; // eax@16
  int v11; // edi@16
  LayerStage *v12; // eax@17
  EffectInfoRegion *v13; // eax@18
  EffectInfoRegion *v14; // esi@18
  RenderMaterial *v15; // eax@19
  RenderMaterial *v16; // eax@20
  MaterialLayer *v17; // eax@21
  int v18; // eax@22
  int v19; // edi@22
  LayerStage *v20; // eax@23
  EffectInfoRegion *v21; // eax@24
  EffectInfoRegion *v22; // esi@24
  EffectInfoRegion *i_rData; // [sp+10h] [bp-4h]@13

  if ( SceneTool::m_pDefaultMaterial )
  {
    ((void (*)(void))SceneTool::m_pDefaultMaterial->vfptr->Release)();
    SceneTool::m_pDefaultMaterial = 0;
  }
  if ( SceneTool::m_pPrimMaterial )
  {
    ((void (*)(void))SceneTool::m_pPrimMaterial->vfptr->Release)();
    SceneTool::m_pPrimMaterial = 0;
  }
  if ( SceneTool::m_pPrimObjectMaterial )
  {
    ((void (*)(void))SceneTool::m_pPrimObjectMaterial->vfptr->Release)();
    SceneTool::m_pPrimObjectMaterial = 0;
  }
  v0 = (RenderMaterial *)operator new(0x4E0u);
  if ( !v0 )
  {
    SceneTool::m_pDefaultMaterial = 0;
    return 0;
  }
  RenderMaterial::RenderMaterial(v0);
  SceneTool::m_pDefaultMaterial = v1;
  if ( !v1 )
    return 0;
  v2 = (MaterialLayer *)operator new(0xD8u);
  if ( !v2 )
    return 0;
  MaterialLayer::MaterialLayer(v2);
  v4 = v3;
  if ( !v3 )
    return 0;
  v5 = (LayerStage *)operator new(0x48u);
  if ( !v5 )
    return 0;
  LayerStage::LayerStage(v5);
  if ( !v6 )
    return 0;
  *(_DWORD *)(v6 + 40) = 3;
  *(_DWORD *)(v6 + 44) = 2;
  *(_DWORD *)(v6 + 48) = 3;
  *(_DWORD *)(v6 + 52) = 3;
  *(_DWORD *)(v6 + 56) = 2;
  *(_DWORD *)(v6 + 60) = 3;
  i_rData = (EffectInfoRegion *)v6;
  SmartArray<LayerStage *,1>::InsertOrderedByIndex((SmartArray<EffectInfoRegion *,1> *)(v4 + 28), &i_rData, 0);
  *(_DWORD *)(v4 + 52) = 5;
  *(_DWORD *)(v4 + 56) = 6;
  i_rData = (EffectInfoRegion *)v4;
  SmartArray<LayerStage *,1>::InsertOrderedByIndex(
    (SmartArray<EffectInfoRegion *,1> *)&SceneTool::m_pDefaultMaterial->layers,
    &i_rData,
    0);
  RenderMaterial::Optimize(SceneTool::m_pDefaultMaterial);
  v7 = (RenderMaterial *)operator new(0x4E0u);
  if ( !v7 )
  {
    SceneTool::m_pPrimMaterial = 0;
    return 0;
  }
  RenderMaterial::RenderMaterial(v7);
  SceneTool::m_pPrimMaterial = v8;
  if ( !v8 )
    return 0;
  v9 = (MaterialLayer *)operator new(0xD8u);
  if ( !v9 )
    return 0;
  MaterialLayer::MaterialLayer(v9);
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = (LayerStage *)operator new(0x48u);
  if ( !v12 )
    return 0;
  LayerStage::LayerStage(v12);
  v14 = v13;
  if ( !v13 )
    return 0;
  i_rData = v13;
  SmartArray<LayerStage *,1>::InsertOrderedByIndex((SmartArray<EffectInfoRegion *,1> *)(v11 + 28), &i_rData, 0);
  i_rData = (EffectInfoRegion *)v11;
  SmartArray<LayerStage *,1>::InsertOrderedByIndex(
    (SmartArray<EffectInfoRegion *,1> *)&SceneTool::m_pPrimMaterial->layers,
    &i_rData,
    0);
  *(_DWORD *)(v11 + 52) = 5;
  *(_DWORD *)(v11 + 56) = 6;
  MaterialLayer::SetDiffuse((MaterialLayer *)v11, &RGBAColor_White_8);
  v14[1].m_pValueText = (UIElement_Text *)3;
  v14[1].m_Spell = 2;
  v14[2].vfptr = (QualityChangeHandlerVtbl *)3;
  v14[2].m_StatType = 3;
  v14[2].m_pElement = (UIElement *)2;
  v14[2].m_pLabelText = (UIElement_Text *)3;
  RenderMaterial::Optimize(SceneTool::m_pPrimMaterial);
  v15 = (RenderMaterial *)operator new(0x4E0u);
  if ( v15 )
  {
    RenderMaterial::RenderMaterial(v15);
    SceneTool::m_pPrimObjectMaterial = v16;
    if ( v16 )
    {
      v17 = (MaterialLayer *)operator new(0xD8u);
      if ( v17 )
      {
        MaterialLayer::MaterialLayer(v17);
        v19 = v18;
        if ( v18 )
        {
          v20 = (LayerStage *)operator new(0x48u);
          if ( v20 )
          {
            LayerStage::LayerStage(v20);
            v22 = v21;
            if ( v21 )
            {
              i_rData = v21;
              SmartArray<LayerStage *,1>::InsertOrderedByIndex(
                (SmartArray<EffectInfoRegion *,1> *)(v19 + 28),
                &i_rData,
                0);
              i_rData = (EffectInfoRegion *)v19;
              SmartArray<LayerStage *,1>::InsertOrderedByIndex(
                (SmartArray<EffectInfoRegion *,1> *)&SceneTool::m_pPrimObjectMaterial->layers,
                &i_rData,
                0);
              *(_DWORD *)(v19 + 52) = 5;
              *(_DWORD *)(v19 + 56) = 6;
              MaterialLayer::SetDiffuse((MaterialLayer *)v19, &RGBAColor_White_8);
              v22[1].m_pValueText = (UIElement_Text *)3;
              v22[1].m_Spell = 2;
              v22[2].vfptr = (QualityChangeHandlerVtbl *)3;
              v22[2].m_StatType = 3;
              v22[2].m_pElement = (UIElement *)2;
              v22[2].m_pLabelText = (UIElement_Text *)3;
              RenderMaterial::Optimize(SceneTool::m_pPrimObjectMaterial);
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }
  SceneTool::m_pPrimObjectMaterial = 0;
  return 0;
}

//----- (00440130) --------------------------------------------------------  // acclient.c:124392
char __cdecl SceneTool::Startup()
{
  RenderMesh *v0; // eax@2
  struct RenderMesh *v1; // eax@3
  RenderMesh *v2; // eax@6
  struct RenderMesh *v3; // eax@7
  RenderVertexBuffer *v4; // eax@10
  Position *v5; // eax@14
  char v6; // al@18
  PStringBase<char> _Name; // [sp+14h] [bp-50h]@14
  TResult result; // [sp+18h] [bp-4Ch]@12
  Position v9; // [sp+1Ch] [bp-48h]@1

  memset(&SceneTool::m_LastFrameTimes, 0, 0x50u);
  SceneTool::m_pDefaultMaterial = 0;
  SceneTool::m_pPrimMaterial = 0;
  SceneTool::m_pPrimObjectMaterial = 0;
  SceneTool::m_pPrimVertexBuffer = 0;
  LODWORD(SceneTool::m_FramesPerSecond) = 0;
  dword_8375C4 = 0;
  dword_8375C0 = 0;
  dword_8375BC = 0;
  dword_8375D4 = 0;
  dword_8375D0 = 0;
  dword_8375C8 = 0;
  dword_8375E4 = 0;
  dword_8375DC = 0;
  dword_8375D8 = 0;
  dword_8375F0 = 0;
  dword_8375EC = 0;
  dword_8375E8 = 0;
  dword_8375F4 = 1065353216;
  dword_8375E0 = 1065353216;
  dword_8375CC = 1065353216;
  LODWORD(SceneTool::m_worldMatrix._11) = 1065353216;
  dword_837604 = 0;
  dword_837600 = 0;
  dword_8375FC = 0;
  dword_837614 = 0;
  dword_837610 = 0;
  dword_837608 = 0;
  dword_837624 = 0;
  dword_83761C = 0;
  dword_837618 = 0;
  dword_837630 = 0;
  dword_83762C = 0;
  dword_837628 = 0;
  dword_837634 = 1065353216;
  dword_837620 = 1065353216;
  dword_83760C = 1065353216;
  LODWORD(SceneTool::m_viewMatrix._11) = 1065353216;
  LODWORD(SceneTool::m_projMatrix._14) = 0;
  LODWORD(SceneTool::m_projMatrix._13) = 0;
  LODWORD(SceneTool::m_projMatrix._12) = 0;
  LODWORD(SceneTool::m_projMatrix._24) = 0;
  LODWORD(SceneTool::m_projMatrix._23) = 0;
  LODWORD(SceneTool::m_projMatrix._21) = 0;
  LODWORD(SceneTool::m_projMatrix._34) = 0;
  LODWORD(SceneTool::m_projMatrix._32) = 0;
  LODWORD(SceneTool::m_projMatrix._31) = 0;
  LODWORD(SceneTool::m_projMatrix._43) = 0;
  LODWORD(SceneTool::m_projMatrix._42) = 0;
  LODWORD(SceneTool::m_projMatrix._41) = 0;
  LODWORD(SceneTool::m_projMatrix._44) = 1065353216;
  LODWORD(SceneTool::m_projMatrix._33) = 1065353216;
  LODWORD(SceneTool::m_projMatrix._22) = 1065353216;
  LODWORD(SceneTool::m_projMatrix._11) = 1065353216;
  v9.vfptr = (PackObjVtbl *)&Position::vftable;
  v9.objcell_id = 0;
  LODWORD(v9.frame.qw) = 1065353216;
  LODWORD(v9.frame.qx) = 0;
  LODWORD(v9.frame.qy) = 0;
  LODWORD(v9.frame.qz) = 0;
  LODWORD(v9.frame.m_fOrigin.x) = 0;
  LODWORD(v9.frame.m_fOrigin.y) = 0;
  LODWORD(v9.frame.m_fOrigin.z) = 0;
  Frame::cache(&v9.frame);
  dword_817CC4 = 0;
  Frame::operator=((int)&stru_817CC8, (int)&v9.frame);
  if ( SceneTool::CreateDefaultMaterial()
    && ((st_init = 1, (v0 = (RenderMesh *)operator new(0xB0u)) == 0) ? (v1 = 0) : RenderMesh::RenderMesh(v0),
        (SceneTool::m_pCylinderMesh = v1, SceneTool::BuildCylinderMesh(v1))
     && ((v2 = (RenderMesh *)operator new(0xB0u)) == 0 ? (v3 = 0) : RenderMesh::RenderMesh(v2),
         (SceneTool::m_pSphereMesh = v3, SceneTool::BuildSphereMesh(v3))
      && (v4 = (RenderVertexBuffer *)((int (*)(void))RenderDevice::render_device->vfptr->CreateVertexBuffer)(),
          (SceneTool::m_pPrimVertexBuffer = v4) != 0)
      && (unsigned __int8)((int (__thiscall *)(RenderVertexBuffer *, signed int, signed int, _DWORD, _DWORD, signed int))v4->vfptr[1].__vecDelDtor)(
                            v4,
                            3,
                            258,
                            0,
                            0,
                            -1)
      && (DebugConsole::Create(&result, &SceneTool::m_pDebugConsole)->m_val & 0x80000000) == 0
      && (ProfilerUI::Create(&result, &SceneTool::m_pProfilerUI)->m_val & 0x80000000) == 0)) )
  {
    Render::LinkRGRCallback((bool (__cdecl *)())DBObj::InitLoad);
    SceneTool::IdentityMatrices();
    Position::Position(&v9);
    SceneTool::SetupCamera(v5);
    SceneTool::m_ScreenShotWidth = 1;
    SceneTool::m_ScreenShotHeight = 1;
    SceneTool::m_ScreenShotMinX = 0;
    SceneTool::m_ScreenShotMinY = 0;
    SceneTool::m_ScreenShotMaxX = 9;
    SceneTool::m_ScreenShotMaxY = 9;
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&result,
      "Number of horizontal screen shot subdivision frames to capture (for high resolution images)");
    PStringBase<char>::PStringBase<char>(&_Name, "SceneTool.ScreenShotWidthScale");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotWidth,
      GRVDataType_UInt32,
      &_Name,
      (PStringBase<char> *)&result,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::PStringBase<char>(
      &_Name,
      "Number of vertical screen shot subdivision frames to capture (for high resolution images)");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.ScreenShotHeightScale");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotHeight,
      GRVDataType_UInt32,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::PStringBase<char>(
      &_Name,
      "Zero-based index of first horizontal screen shot subdivision frame with the 'width' range to capture");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.ScreenShotMinX");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotMinX,
      GRVDataType_UInt32,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::PStringBase<char>(
      &_Name,
      "Zero-based index of first vertical screen shot subdivision frame with the 'height' range to capture");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.ScreenShotMinY");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotMinY,
      GRVDataType_UInt32,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::PStringBase<char>(
      &_Name,
      "Zero-based index of last horizontal screen shot subdivision frame with the 'width' range to capture");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.ScreenShotMaxX");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotMaxX,
      GRVDataType_UInt32,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::PStringBase<char>(
      &_Name,
      "Zero-based index of last vertical screen shot subdivision frame with the 'height' range to capture");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.ScreenShotMaxY");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_ScreenShotMaxY,
      GRVDataType_UInt32,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    PStringBase<char>::PStringBase<char>(&_Name, "Toggles drawing of UI objects");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "SceneTool.RenderUIObjects");
    GlobalRegistry::RegisterVariableInternal(
      &SceneTool::m_RenderUIObjects,
      GRVDataType_Bool,
      (PStringBase<char> *)&result,
      &_Name,
      0,
      0,
      0,
      0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Name);
    if ( SceneTool::m_ScreenShotWidth > 0xA )
      SceneTool::m_ScreenShotWidth = 10;
    if ( SceneTool::m_ScreenShotHeight > 0xA )
      SceneTool::m_ScreenShotHeight = 10;
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 817C0C: using guessed type bool SceneTool::m_RenderUIObjects;
// 817C10: using guessed type unsigned __int32 SceneTool::m_ScreenShotWidth;
// 817C14: using guessed type unsigned __int32 SceneTool::m_ScreenShotHeight;
// 817C18: using guessed type unsigned __int32 SceneTool::m_ScreenShotMaxX;
// 817C1C: using guessed type unsigned __int32 SceneTool::m_ScreenShotMaxY;
// 817CC4: using guessed type int dword_817CC4;
// 8373B8: using guessed type float *SceneTool::m_LastFrameTimes;
// 837418: using guessed type float SceneTool::m_FramesPerSecond;
// 837438: using guessed type unsigned __int32 SceneTool::m_ScreenShotMinX;
// 83743C: using guessed type unsigned __int32 SceneTool::m_ScreenShotMinY;
// 837460: using guessed type struct RenderMesh *SceneTool::m_pCylinderMesh;
// 837464: using guessed type struct RenderMesh *SceneTool::m_pSphereMesh;
// 8375B8: using guessed type struct Matrix4 SceneTool::m_worldMatrix;
// 8375BC: using guessed type int dword_8375BC;
// 8375C0: using guessed type int dword_8375C0;
// 8375C4: using guessed type int dword_8375C4;
// 8375C8: using guessed type int dword_8375C8;
// 8375CC: using guessed type int dword_8375CC;
// 8375D0: using guessed type int dword_8375D0;
// 8375D4: using guessed type int dword_8375D4;
// 8375D8: using guessed type int dword_8375D8;
// 8375DC: using guessed type int dword_8375DC;
// 8375E0: using guessed type int dword_8375E0;
// 8375E4: using guessed type int dword_8375E4;
// 8375E8: using guessed type int dword_8375E8;
// 8375EC: using guessed type int dword_8375EC;
// 8375F0: using guessed type int dword_8375F0;
// 8375F4: using guessed type int dword_8375F4;
// 8375F8: using guessed type struct Matrix4 SceneTool::m_viewMatrix;
// 8375FC: using guessed type int dword_8375FC;
// 837600: using guessed type int dword_837600;
// 837604: using guessed type int dword_837604;
// 837608: using guessed type int dword_837608;
// 83760C: using guessed type int dword_83760C;
// 837610: using guessed type int dword_837610;
// 837614: using guessed type int dword_837614;
// 837618: using guessed type int dword_837618;
// 83761C: using guessed type int dword_83761C;
// 837620: using guessed type int dword_837620;
// 837624: using guessed type int dword_837624;
// 837628: using guessed type int dword_837628;
// 83762C: using guessed type int dword_83762C;
// 837630: using guessed type int dword_837630;
// 837634: using guessed type int dword_837634;

//----- (006C6AC0) --------------------------------------------------------  // acclient.c:734847
void _E91_10()
{
  outside_val_6 = 1000.0 + 1.0;
}

//----- (006C6AE0) --------------------------------------------------------  // acclient.c:734853
void _E93_1()
{
  block_length_6 = 24.0 * 8.0;
}

//----- (006C6B00) --------------------------------------------------------  // acclient.c:734859
void _E95_1()
{
  half_square_length_6 = 24.0 * 0.5;
}

//----- (006C6B20) --------------------------------------------------------  // acclient.c:734865
int _E97_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_8, "None");
  return atexit(_E98_33);
}

//----- (006C6B40) --------------------------------------------------------  // acclient.c:734872
int _E100_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_8, "Speed");
  return atexit(_E101_61);
}

//----- (006C6B60) --------------------------------------------------------  // acclient.c:734879
int _E103_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_8, "Noise");
  return atexit(_E104_31);
}

//----- (006C6B80) --------------------------------------------------------  // acclient.c:734886
int _E106_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_8, "Sine");
  return atexit(_E107_63);
}

//----- (006C6BA0) --------------------------------------------------------  // acclient.c:734893
int _E109_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_8, "Square");
  return atexit(sub_72A080);
}

//----- (006C6BC0) --------------------------------------------------------  // acclient.c:734900
int _E112_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_8, "Bounce");
  return atexit(_E113_42);
}

//----- (006C6BE0) --------------------------------------------------------  // acclient.c:734907
int _E115_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_8, "Perlin");
  return atexit(_E116_34);
}

//----- (006C6C00) --------------------------------------------------------  // acclient.c:734914
int _E118_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_8, "Fractal");
  return atexit(_E119_59);
}

//----- (006C6C20) --------------------------------------------------------  // acclient.c:734921
int _E121_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_8, "FrameLoop");
  return atexit(_E122_46);
}

//----- (006C6C40) --------------------------------------------------------  // acclient.c:734928
void _E124_8()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_7, PFID_A8R8G8B8);
}

//----- (006C6C50) --------------------------------------------------------  // acclient.c:734934
int _E126_0()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_2, "Render.TextureFiltering");
  return atexit(_E127_81);
}

//----- (006C6C70) --------------------------------------------------------  // acclient.c:734941
int _E129()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_2, "Render.LandscapeDetailTextures");
  return atexit(_E130_73);
}

//----- (006C6C90) --------------------------------------------------------  // acclient.c:734948
int _E132_0()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_2, "Render.BuildingDetailTextures");
  return atexit(_E133_66);
}

//----- (006C6CB0) --------------------------------------------------------  // acclient.c:734955
int _E135()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_2, "Render.FieldOfView");
  return atexit(_E136_50);
}

//----- (006C6CD0) --------------------------------------------------------  // acclient.c:734962
int _E138_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_2, "Render.LandscapeTextureDetail");
  return atexit(_E139_51);
}

//----- (006C6CF0) --------------------------------------------------------  // acclient.c:734969
int _E141_0()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_2, "Render.EnvironmentTextureDetail");
  return atexit(_E142_48);
}

//----- (006C6D10) --------------------------------------------------------  // acclient.c:734976
int _E144_0()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_2, "Render.SceneryDrawDistance");
  return atexit(_E145_50);
}

//----- (006C6D30) --------------------------------------------------------  // acclient.c:734983
int _E147_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_2, "Render.LandscapeDrawDistance");
  return atexit(_E148_49);
}

//----- (006C6D50) --------------------------------------------------------  // acclient.c:734990
int _E150_0()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_2, "Render.ScreenBrightness");
  return atexit(_E151_47);
}

//----- (006C6D70) --------------------------------------------------------  // acclient.c:734997
int _E153_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_2, "Render.AspectRatio");
  return atexit(_E154_48);
}

//----- (006C6D90) --------------------------------------------------------  // acclient.c:735004
int _E156_1()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_2, "Render.DisplayAdapter");
  return atexit(_E157_45);
}

//----- (006C6DB0) --------------------------------------------------------  // acclient.c:735011
int _E159_0()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_2, "Render.MaxHardwareClass");
  return atexit(_E160_48);
}

//----- (006C6DD0) --------------------------------------------------------  // acclient.c:735018
int _E162_1()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_2, "Render.AutomaticDegrades");
  return atexit(_E163_41);
}

//----- (006C6DF0) --------------------------------------------------------  // acclient.c:735025
int _E165_0()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_2, "Render.GraphicsPerformance");
  return atexit(_E166_43);
}

//----- (006C6E10) --------------------------------------------------------  // acclient.c:735032
int _E168_1()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_2, "Render.DegradeDistance");
  return atexit(_E169_42);
}

//----- (006C6E30) --------------------------------------------------------  // acclient.c:735039
int _E171_1()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_2, "Render.MultiPassAlpha");
  return atexit(_E172_40);
}

//----- (006C6E50) --------------------------------------------------------  // acclient.c:735046
int _E174_1()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_2, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83753C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_837540, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_837544, "Anisotropic");
  return atexit(_E175_37);
}

//----- (006C6EA0) --------------------------------------------------------  // acclient.c:735056
int _E177_1()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_2, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83754C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837550, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837554, "High");
  PStringBase<char>::PStringBase<char>(&stru_837558, "VeryHigh");
  return atexit(_E178_37);
}

//----- (006C6F00) --------------------------------------------------------  // acclient.c:735067
int _E180_1()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_2, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837560, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837564, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837568, "High");
  PStringBase<char>::PStringBase<char>(&stru_83756C, "VeryHigh");
  return atexit(_E181_37);
}

//----- (006C6F60) --------------------------------------------------------  // acclient.c:735078
int _E183_1()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_2, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837574, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837578, "High");
  return atexit(_E184_35);
}

//----- (006C6FA0) --------------------------------------------------------  // acclient.c:735087
int _E186_1()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_2, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_837580, "Low");
  PStringBase<char>::PStringBase<char>(&stru_837584, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_837588, "High");
  PStringBase<char>::PStringBase<char>(&stru_83758C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_837590, "Extreme");
  return atexit(_E187_34);
}

//----- (006C7010) --------------------------------------------------------  // acclient.c:735099
int _E189_1()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_2, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_837598, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83759C, "Wide");
  return atexit(_E190_35);
}

//----- (006C7050) --------------------------------------------------------  // acclient.c:735108
void _E192_1()
{
  DEFAULT_VIEW_RADIUS_3 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006C7070) --------------------------------------------------------  // acclient.c:735114
void _E194()
{
  MIN_QUANTUM_3 = 1.0 / 30.0;
}

//----- (006C7090) --------------------------------------------------------  // acclient.c:735120
void _E196_0()
{
  MAX_QUANTUM_3 = 1.0 / 5.0;
}

//----- (006C70B0) --------------------------------------------------------  // acclient.c:735126
int _E198_1()
{
  Frame::cache(&stru_817C80);
  return atexit(_E199_33);
}

//----- (006C70D0) --------------------------------------------------------  // acclient.c:735133
int _E213_0()
{
  Frame::cache(&stru_817CC8);
  return atexit(_E214_35);
}

//----- (006C70F0) --------------------------------------------------------  // acclient.c:735140
int _E216_0()
{
  int result; // eax@1

  result = (signed int)Vector3_ZeroVector___6.x;
  SceneTool::m_vWorldOffset = Vector3_ZeroVector___6;
  return result;
}
// 837738: using guessed type struct Vector3 SceneTool::m_vWorldOffset;

//----- (006C7120) --------------------------------------------------------  // acclient.c:735151
int _E1_29()
{
  return atexit(_E2_29);
}

//----- (00729B20) --------------------------------------------------------  // acclient.c:827722
void __cdecl _E127_81()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729B50) --------------------------------------------------------  // acclient.c:827735
void __cdecl _E130_73()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729B80) --------------------------------------------------------  // acclient.c:827748
void __cdecl _E133_66()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729BB0) --------------------------------------------------------  // acclient.c:827761
void __cdecl _E136_50()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729BE0) --------------------------------------------------------  // acclient.c:827774
void __cdecl _E139_51()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729C10) --------------------------------------------------------  // acclient.c:827787
void __cdecl _E142_48()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729C40) --------------------------------------------------------  // acclient.c:827800
void __cdecl _E145_50()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729C70) --------------------------------------------------------  // acclient.c:827813
void __cdecl _E148_49()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729CA0) --------------------------------------------------------  // acclient.c:827826
void __cdecl _E151_47()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729CD0) --------------------------------------------------------  // acclient.c:827839
void __cdecl _E154_48()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729D00) --------------------------------------------------------  // acclient.c:827852
void __cdecl _E157_45()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729D30) --------------------------------------------------------  // acclient.c:827865
void __cdecl _E160_48()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729D60) --------------------------------------------------------  // acclient.c:827878
void __cdecl _E163_41()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729D90) --------------------------------------------------------  // acclient.c:827891
void __cdecl _E166_43()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729DC0) --------------------------------------------------------  // acclient.c:827904
void __cdecl _E169_42()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729DF0) --------------------------------------------------------  // acclient.c:827917
void __cdecl _E172_40()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729E20) --------------------------------------------------------  // acclient.c:827930
void __cdecl _E175_37()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_2;
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

//----- (00729E60) --------------------------------------------------------  // acclient.c:827955
void __cdecl _E178_37()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_2;
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

//----- (00729EA0) --------------------------------------------------------  // acclient.c:827980
void __cdecl _E181_37()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_2;
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

//----- (00729EE0) --------------------------------------------------------  // acclient.c:828005
void __cdecl _E184_35()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_2;
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

//----- (00729F20) --------------------------------------------------------  // acclient.c:828030
void __cdecl _E187_34()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_2;
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

//----- (00729F60) --------------------------------------------------------  // acclient.c:828055
void __cdecl _E190_35()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &DEFAULT_VIEW_RADIUS_3;
  v1 = 3;
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

//----- (00729FA0) --------------------------------------------------------  // acclient.c:828080
void __cdecl _E199_33()
{
  SceneTool::m_CameraPosition.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00729FB0) --------------------------------------------------------  // acclient.c:828087
void __cdecl _E214_35()
{
  SceneTool::m_WorldPosition.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 817CC0: using guessed type struct Position SceneTool::m_WorldPosition;

//----- (00729FC0) --------------------------------------------------------  // acclient.c:828095
void __cdecl _E98_33()
{
  char *v0; // esi@1

  v0 = &waveform_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729FF0) --------------------------------------------------------  // acclient.c:828108
void __cdecl _E101_61()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A020) --------------------------------------------------------  // acclient.c:828121
void __cdecl _E104_31()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A050) --------------------------------------------------------  // acclient.c:828134
void __cdecl _E107_63()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A080) --------------------------------------------------------  // acclient.c:828147
void __cdecl sub_72A080()
{
  char *v0; // esi@1

  v0 = &waveform_Square_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A0B0) --------------------------------------------------------  // acclient.c:828160
void __cdecl _E113_42()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A0E0) --------------------------------------------------------  // acclient.c:828173
void __cdecl _E116_34()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A110) --------------------------------------------------------  // acclient.c:828186
void __cdecl _E119_59()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0072A140) --------------------------------------------------------  // acclient.c:828199
void __cdecl _E122_46()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

