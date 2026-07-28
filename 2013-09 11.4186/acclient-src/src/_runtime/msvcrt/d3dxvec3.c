/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : d3dxvec3
   Object     : _runtime\msvcrt\d3dxvec3.obj
   Functions  : 3
   Addresses  : 0060A000 - 0060A3C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0060A000) --------------------------------------------------------  // acclient.c:561050
void __stdcall AMDSSE_D3DXVec3TransformArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  unsigned int v7; // eax@1
  unsigned int v8; // ebx@1
  __m128 v9; // xmm4@2
  __m128 v10; // xmm5@2
  __m128 v11; // xmm6@2
  __m128 v12; // xmm7@2
  __m128 v13; // xmm0@3
  __m128 v14; // xmm1@3
  __m128 v15; // xmm2@3
  unsigned __int8 v16; // of@3

  v6 = n;
  v7 = pOut;
  v8 = pV;
  if ( (signed int)n > 0 )
  {
    v9 = *(__m128 *)pM;
    v10 = *(__m128 *)(pM + 16);
    v11 = *(__m128 *)(pM + 32);
    v12 = *(__m128 *)(pM + 48);
    do
    {
      v13 = _mm_shuffle_ps((__m128)*(_DWORD *)v8, (__m128)*(_DWORD *)v8, 0);
      v14 = _mm_shuffle_ps((__m128)*(_DWORD *)(v8 + 4), (__m128)*(_DWORD *)(v8 + 4), 0);
      v15 = _mm_shuffle_ps((__m128)*(_DWORD *)(v8 + 8), (__m128)*(_DWORD *)(v8 + 8), 0);
      v8 += VStride;
      *(_OWORD *)v7 = _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v13, v9), _mm_mul_ps(v14, v10)),
                        _mm_add_ps(_mm_mul_ps(v15, v11), v12));
      v7 += OutStride;
      v16 = __OFSUB__(v6--, 1);
    }
    while ( !((unsigned __int8)(((v6 & 0x80000000) != 0) ^ v16) | (v6 == 0)) );
  }
}

//----- (0060A0A0) --------------------------------------------------------  // acclient.c:561090
void __stdcall AMDSSE_D3DXVec3TransformCoordArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  unsigned int v7; // eax@1
  unsigned int v8; // edx@1
  unsigned int v9; // esi@2
  bool j; // zf@2
  unsigned int v11; // edx@5
  unsigned int v12; // esi@5
  unsigned int i; // edi@5
  __m128 v14; // xmm0@7
  __m128 v15; // xmm1@7
  __m128 v16; // xmm2@7
  __m128 v17; // xmm3@7
  int v18; // edx@7
  __m128 v19; // xmm0@7
  __m128 v20; // xmm4@7
  __m128 v21; // xmm1@7
  __m128 v22; // xmm2@7
  __m128 v23; // xmm0@7
  __m128 v24; // xmm4@7
  __m128 v25; // xmm1@7
  __m128 v26; // xmm3@7
  __m128 v27; // xmm5@7
  __m128 v28; // xmm0@7
  __m128 v29; // xmm1@7
  __m128 v30; // xmm3@7
  __m128 v31; // xmm5@7
  __m128 v32; // xmm4@7
  __m128 v33; // xmm4@7
  __m128 v34; // xmm0@7
  __m128 v35; // xmm1@7
  __m128 v36; // xmm3@7
  __m128 v37; // xmm2@7
  __m128 v38; // xmm0@7
  __m128 v39; // xmm2@7
  __m128 v40; // xmm3@7
  __m128 v41; // xmm3@7
  int v42; // eax@7
  int v43; // ecx@9
  __m128 v44; // [sp+Ch] [bp-10Ch]@5
  __m128 v45; // [sp+1Ch] [bp-FCh]@5
  __m128 v46; // [sp+2Ch] [bp-ECh]@5
  __m128 v47; // [sp+3Ch] [bp-DCh]@5
  __m128 v48; // [sp+4Ch] [bp-CCh]@5
  __m128 v49; // [sp+5Ch] [bp-BCh]@5
  __m128 v50; // [sp+6Ch] [bp-ACh]@5
  __m128 v51; // [sp+7Ch] [bp-9Ch]@5
  __m128 v52; // [sp+8Ch] [bp-8Ch]@5
  __m128 v53; // [sp+9Ch] [bp-7Ch]@5
  __m128 v54; // [sp+ACh] [bp-6Ch]@5
  __m128 v55; // [sp+BCh] [bp-5Ch]@5
  __m128 v56; // [sp+CCh] [bp-4Ch]@5
  __m128 v57; // [sp+DCh] [bp-3Ch]@5
  __m128 v58; // [sp+ECh] [bp-2Ch]@5
  __m128 v59; // [sp+FCh] [bp-1Ch]@5

  v6 = n;
  v7 = pOut;
  v8 = pM;
  if ( (signed int)n >= 4 )
  {
    v44 = _mm_shuffle_ps((__m128)*(_DWORD *)pM, (__m128)*(_DWORD *)pM, 0);
    v45 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 4), (__m128)*(_DWORD *)(pM + 4), 0);
    v46 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 8), (__m128)*(_DWORD *)(pM + 8), 0);
    v47 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 12), (__m128)*(_DWORD *)(pM + 12), 0);
    v48 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 16), (__m128)*(_DWORD *)(pM + 16), 0);
    v49 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 20), (__m128)*(_DWORD *)(pM + 20), 0);
    v50 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 24), (__m128)*(_DWORD *)(pM + 24), 0);
    v51 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 28), (__m128)*(_DWORD *)(pM + 28), 0);
    v52 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 32), (__m128)*(_DWORD *)(pM + 32), 0);
    v53 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 36), (__m128)*(_DWORD *)(pM + 36), 0);
    v54 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 40), (__m128)*(_DWORD *)(pM + 40), 0);
    v55 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 44), (__m128)*(_DWORD *)(pM + 44), 0);
    v56 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 48), (__m128)*(_DWORD *)(pM + 48), 0);
    v57 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 52), (__m128)*(_DWORD *)(pM + 52), 0);
    v58 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 56), (__m128)*(_DWORD *)(pM + 56), 0);
    v59 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 60), (__m128)*(_DWORD *)(pM + 60), 0);
    v11 = pV;
    v12 = VStride;
    for ( i = OutStride; ; i = OutStride )
    {
      while ( (signed int)v6 >= 4 )
      {
        v14 = _mm_loadl_ps((const double *)v11);
        v15 = _mm_loadl_ps((const double *)(v12 + v11));
        v16 = (__m128)*(_DWORD *)(v11 + 8);
        v17 = (__m128)*(_DWORD *)(v12 + v11 + 8);
        v18 = v11 + 2 * v12;
        v19 = _mm_unpacklo_ps(v14, v15);
        v20 = _mm_unpacklo_ps(_mm_loadl_ps((const double *)v18), _mm_loadl_ps((const double *)(v12 + v18)));
        v21 = v19;
        v22 = _mm_movelh_ps(
                _mm_unpacklo_ps(v16, v17),
                _mm_unpacklo_ps((__m128)*(_DWORD *)(v18 + 8), (__m128)*(_DWORD *)(v12 + v18 + 8)));
        v23 = _mm_movelh_ps(v19, v20);
        v24 = _mm_movehl_ps(v20, v21);
        v11 = v18 + 2 * v12;
        v25 = v23;
        v26 = v23;
        v27 = v23;
        v28 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, v44), _mm_mul_ps(v24, v48)), _mm_mul_ps(v22, v52)), v56);
        v29 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v45), _mm_mul_ps(v24, v49)), _mm_mul_ps(v22, v53)), v57);
        v30 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v46), _mm_mul_ps(v24, v50)), _mm_mul_ps(v22, v54)), v58);
        v31 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, v47), _mm_mul_ps(v24, v51)), _mm_mul_ps(v22, v55)), v59);
        v32 = _mm_rcp_ps(v31);
        v33 = _mm_mul_ps(v32, _mm_sub_ps(*(__m128 *)&AMDSSE_two_0, _mm_mul_ps(v31, v32)));
        v34 = _mm_mul_ps(v28, v33);
        v35 = _mm_mul_ps(v29, v33);
        v36 = _mm_mul_ps(v30, v33);
        v37 = v34;
        v38 = _mm_unpacklo_ps(v34, v35);
        v39 = _mm_unpackhi_ps(v37, v35);
        _mm_storel_ps((double *)v7, v38);
        *(_DWORD *)(v7 + 8) = (_DWORD)v36.m128_f32[0];
        v40 = _mm_shuffle_ps(v36, v36, -7);
        _mm_storel_ps((double *)(i + v7), _mm_movehl_ps(v38, v38));
        *(_DWORD *)(i + v7 + 8) = (_DWORD)v40.m128_f32[0];
        v41 = v40;
        v42 = v7 + 2 * i;
        _mm_storel_ps((double *)v42, v39);
        *(_DWORD *)(v42 + 8) = (_DWORD)v41.m128_f32[0];
        _mm_storel_ps((double *)(i + v42), _mm_movehl_ps(v39, v39));
        *(_DWORD *)(i + v42 + 8) = (unsigned __int128)_mm_shuffle_ps(v41, v41, -7);
        v7 = v42 + 2 * i;
        v6 -= 4;
      }
      if ( !v6 )
        break;
      v43 = v6 - 4;
      v11 += v43 * v12;
      v7 += v43 * i;
      v6 = 4;
      v12 = VStride;
    }
  }
  else
  {
    v9 = pV;
    for ( j = n == 0; !j; j = n-- == 1 )
    {
      v7 = (unsigned int)((char *)x3d_D3DXVec3TransformCoord(
                                    (struct D3DXVECTOR3 *)v7,
                                    (const struct D3DXVECTOR3 *)v9,
                                    (const struct D3DXMATRIX *)v8)
                        + OutStride);
      v9 = VStride + pV;
      pV += VStride;
    }
  }
}

//----- (0060A3C0) --------------------------------------------------------  // acclient.c:561243
void __stdcall AMDSSE_D3DXVec3TransformNormalArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  int v9; // esi@2
  bool j; // zf@2
  unsigned int v11; // edx@5
  unsigned int v12; // esi@5
  unsigned int i; // edi@5
  __m128 v14; // xmm0@7
  __m128 v15; // xmm1@7
  __m128 v16; // xmm2@7
  __m128 v17; // xmm3@7
  int v18; // edx@7
  __m128 v19; // xmm0@7
  __m128 v20; // xmm4@7
  __m128 v21; // xmm1@7
  __m128 v22; // xmm2@7
  __m128 v23; // xmm0@7
  __m128 v24; // xmm4@7
  __m128 v25; // xmm1@7
  __m128 v26; // xmm3@7
  __m128 v27; // xmm0@7
  __m128 v28; // xmm1@7
  __m128 v29; // xmm3@7
  __m128 v30; // xmm2@7
  __m128 v31; // xmm0@7
  __m128 v32; // xmm2@7
  __m128 v33; // xmm3@7
  __m128 v34; // xmm3@7
  int v35; // eax@7
  int v36; // ecx@9
  __m128 v37; // [sp+Ch] [bp-10Ch]@5
  __m128 v38; // [sp+1Ch] [bp-FCh]@5
  __m128 v39; // [sp+2Ch] [bp-ECh]@5
  __m128 v40; // [sp+4Ch] [bp-CCh]@5
  __m128 v41; // [sp+5Ch] [bp-BCh]@5
  __m128 v42; // [sp+6Ch] [bp-ACh]@5
  __m128 v43; // [sp+8Ch] [bp-8Ch]@5
  __m128 v44; // [sp+9Ch] [bp-7Ch]@5
  __m128 v45; // [sp+ACh] [bp-6Ch]@5

  v6 = n;
  v7 = pOut;
  v8 = pM;
  if ( (signed int)n >= 4 )
  {
    v37 = _mm_shuffle_ps((__m128)*(_DWORD *)pM, (__m128)*(_DWORD *)pM, 0);
    v38 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 4), (__m128)*(_DWORD *)(pM + 4), 0);
    v39 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 8), (__m128)*(_DWORD *)(pM + 8), 0);
    v40 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 16), (__m128)*(_DWORD *)(pM + 16), 0);
    v41 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 20), (__m128)*(_DWORD *)(pM + 20), 0);
    v42 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 24), (__m128)*(_DWORD *)(pM + 24), 0);
    v43 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 32), (__m128)*(_DWORD *)(pM + 32), 0);
    v44 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 36), (__m128)*(_DWORD *)(pM + 36), 0);
    v45 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 40), (__m128)*(_DWORD *)(pM + 40), 0);
    v11 = pV;
    v12 = VStride;
    for ( i = OutStride; ; i = OutStride )
    {
      while ( (signed int)v6 >= 4 )
      {
        v14 = _mm_loadl_ps((const double *)v11);
        v15 = _mm_loadl_ps((const double *)(v12 + v11));
        v16 = (__m128)*(_DWORD *)(v11 + 8);
        v17 = (__m128)*(_DWORD *)(v12 + v11 + 8);
        v18 = v11 + 2 * v12;
        v19 = _mm_unpacklo_ps(v14, v15);
        v20 = _mm_unpacklo_ps(_mm_loadl_ps((const double *)v18), _mm_loadl_ps((const double *)(v12 + v18)));
        v21 = v19;
        v22 = _mm_movelh_ps(
                _mm_unpacklo_ps(v16, v17),
                _mm_unpacklo_ps((__m128)*(_DWORD *)(v18 + 8), (__m128)*(_DWORD *)(v12 + v18 + 8)));
        v23 = _mm_movelh_ps(v19, v20);
        v24 = _mm_movehl_ps(v20, v21);
        v11 = v18 + 2 * v12;
        v25 = v23;
        v26 = v23;
        v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, v37), _mm_mul_ps(v24, v40)), _mm_mul_ps(v22, v43));
        v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v38), _mm_mul_ps(v24, v41)), _mm_mul_ps(v22, v44));
        v29 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v39), _mm_mul_ps(v24, v42)), _mm_mul_ps(v22, v45));
        v30 = v27;
        v31 = _mm_unpacklo_ps(v27, v28);
        v32 = _mm_unpackhi_ps(v30, v28);
        _mm_storel_ps((double *)v7, v31);
        *(_DWORD *)(v7 + 8) = (_DWORD)v29.m128_f32[0];
        v33 = _mm_shuffle_ps(v29, v29, -7);
        _mm_storel_ps((double *)(i + v7), _mm_movehl_ps(v31, v31));
        *(_DWORD *)(i + v7 + 8) = (_DWORD)v33.m128_f32[0];
        v34 = v33;
        v35 = v7 + 2 * i;
        _mm_storel_ps((double *)v35, v32);
        *(_DWORD *)(v35 + 8) = (_DWORD)v34.m128_f32[0];
        _mm_storel_ps((double *)(i + v35), _mm_movehl_ps(v32, v32));
        *(_DWORD *)(i + v35 + 8) = (unsigned __int128)_mm_shuffle_ps(v34, v34, -7);
        v7 = v35 + 2 * i;
        v6 -= 4;
      }
      if ( !v6 )
        break;
      v36 = v6 - 4;
      v11 += v36 * v12;
      v7 += v36 * i;
      v6 = 4;
      v12 = VStride;
    }
  }
  else
  {
    v9 = pV;
    for ( j = n == 0; !j; j = n-- == 1 )
    {
      v7 = OutStride + x3d_D3DXVec3TransformNormal(v7, v9, v8);
      v9 = VStride + pV;
      pV += VStride;
    }
  }
}

