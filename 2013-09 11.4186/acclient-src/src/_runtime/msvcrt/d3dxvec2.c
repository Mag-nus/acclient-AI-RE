/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : d3dxvec2
   Object     : _runtime\msvcrt\d3dxvec2.obj
   Functions  : 3
   Addresses  : 00609000 - 006094C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00609000) --------------------------------------------------------  // acclient.c:560725
void __stdcall AMDSSE_D3DXVec2TransformArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  unsigned int v9; // esi@2
  bool j; // zf@2
  unsigned int v11; // edx@5
  unsigned int v12; // esi@5
  unsigned int i; // edi@5
  __m128 v14; // xmm0@7
  __m128 v15; // xmm1@7
  const double *v16; // edx@7
  __m128 v17; // xmm0@7
  __m128 v18; // xmm4@7
  __m128 v19; // xmm1@7
  __m128 v20; // xmm0@7
  __m128 v21; // xmm4@7
  __m128 v22; // xmm1@7
  __m128 v23; // xmm3@7
  __m128 v24; // xmm5@7
  __m128 v25; // xmm0@7
  __m128 v26; // xmm1@7
  __m128 v27; // xmm3@7
  __m128 v28; // xmm5@7
  __m128 v29; // xmm2@7
  __m128 v30; // xmm0@7
  __m128 v31; // xmm4@7
  __m128 v32; // xmm3@7
  __m128 v33; // xmm4@7
  __m128 v34; // xmm2@7
  int v35; // eax@7
  int v36; // ecx@9
  __m128 v37; // [sp+Ch] [bp-10Ch]@5
  __m128 v38; // [sp+1Ch] [bp-FCh]@5
  __m128 v39; // [sp+2Ch] [bp-ECh]@5
  __m128 v40; // [sp+3Ch] [bp-DCh]@5
  __m128 v41; // [sp+4Ch] [bp-CCh]@5
  __m128 v42; // [sp+5Ch] [bp-BCh]@5
  __m128 v43; // [sp+6Ch] [bp-ACh]@5
  __m128 v44; // [sp+7Ch] [bp-9Ch]@5
  __m128 v45; // [sp+CCh] [bp-4Ch]@5
  __m128 v46; // [sp+DCh] [bp-3Ch]@5
  __m128 v47; // [sp+ECh] [bp-2Ch]@5
  __m128 v48; // [sp+FCh] [bp-1Ch]@5

  v6 = n;
  v7 = pOut;
  v8 = pM;
  if ( (signed int)n >= 4 )
  {
    v37 = _mm_shuffle_ps((__m128)*(_DWORD *)pM, (__m128)*(_DWORD *)pM, 0);
    v38 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 4), (__m128)*(_DWORD *)(pM + 4), 0);
    v39 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 8), (__m128)*(_DWORD *)(pM + 8), 0);
    v40 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 12), (__m128)*(_DWORD *)(pM + 12), 0);
    v41 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 16), (__m128)*(_DWORD *)(pM + 16), 0);
    v42 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 20), (__m128)*(_DWORD *)(pM + 20), 0);
    v43 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 24), (__m128)*(_DWORD *)(pM + 24), 0);
    v44 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 28), (__m128)*(_DWORD *)(pM + 28), 0);
    v45 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 48), (__m128)*(_DWORD *)(pM + 48), 0);
    v46 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 52), (__m128)*(_DWORD *)(pM + 52), 0);
    v47 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 56), (__m128)*(_DWORD *)(pM + 56), 0);
    v48 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 60), (__m128)*(_DWORD *)(pM + 60), 0);
    v11 = pV;
    v12 = VStride;
    for ( i = OutStride; ; i = OutStride )
    {
      while ( (signed int)v6 >= 4 )
      {
        v14 = _mm_loadl_ps((const double *)v11);
        v15 = _mm_loadl_ps((const double *)(v12 + v11));
        v16 = (const double *)(v11 + 2 * v12);
        v17 = _mm_unpacklo_ps(v14, v15);
        v18 = _mm_unpacklo_ps(_mm_loadl_ps(v16), _mm_loadl_ps((const double *)((char *)v16 + v12)));
        v19 = v17;
        v20 = _mm_movelh_ps(v17, v18);
        v21 = _mm_movehl_ps(v18, v19);
        v11 = (unsigned int)((char *)v16 + 2 * v12);
        v22 = v20;
        v23 = v20;
        v24 = v20;
        v25 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, v37), _mm_mul_ps(v21, v41)), v45);
        v26 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v22, v38), _mm_mul_ps(v21, v42)), v46);
        v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, v39), _mm_mul_ps(v21, v43)), v47);
        v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v24, v40), _mm_mul_ps(v21, v44)), v48);
        v29 = v25;
        v30 = _mm_unpacklo_ps(v25, v26);
        v31 = v27;
        v32 = _mm_unpacklo_ps(v27, v28);
        v33 = _mm_unpackhi_ps(v31, v28);
        v34 = _mm_unpackhi_ps(v29, v26);
        *(_OWORD *)v7 = _mm_movelh_ps(v30, v32);
        *(_OWORD *)(i + v7) = _mm_movehl_ps(v32, v30);
        v35 = v7 + 2 * i;
        *(_OWORD *)v35 = _mm_movelh_ps(v34, v33);
        *(_OWORD *)(i + v35) = _mm_movehl_ps(v33, v34);
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
      v7 = OutStride + x3d_D3DXVec2Transform(v7, (__m64 *)v9, v8);
      v9 = VStride + pV;
      pV += VStride;
    }
  }
}

//----- (00609260) --------------------------------------------------------  // acclient.c:560846
void __stdcall AMDSSE_D3DXVec2TransformCoordArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  unsigned int v9; // esi@2
  bool j; // zf@2
  unsigned int v11; // edx@5
  unsigned int v12; // esi@5
  unsigned int i; // edi@5
  __m128 v14; // xmm0@7
  __m128 v15; // xmm1@7
  const double *v16; // edx@7
  __m128 v17; // xmm0@7
  __m128 v18; // xmm4@7
  __m128 v19; // xmm1@7
  __m128 v20; // xmm0@7
  __m128 v21; // xmm4@7
  __m128 v22; // xmm1@7
  __m128 v23; // xmm5@7
  __m128 v24; // xmm0@7
  __m128 v25; // xmm1@7
  __m128 v26; // xmm5@7
  __m128 v27; // xmm4@7
  __m128 v28; // xmm4@7
  __m128 v29; // xmm0@7
  __m128 v30; // xmm1@7
  __m128 v31; // xmm2@7
  __m128 v32; // xmm0@7
  __m128 v33; // xmm2@7
  double *v34; // eax@7
  int v35; // ecx@9
  __m128 v36; // [sp+Ch] [bp-10Ch]@5
  __m128 v37; // [sp+1Ch] [bp-FCh]@5
  __m128 v38; // [sp+3Ch] [bp-DCh]@5
  __m128 v39; // [sp+4Ch] [bp-CCh]@5
  __m128 v40; // [sp+5Ch] [bp-BCh]@5
  __m128 v41; // [sp+7Ch] [bp-9Ch]@5
  __m128 v42; // [sp+CCh] [bp-4Ch]@5
  __m128 v43; // [sp+DCh] [bp-3Ch]@5
  __m128 v44; // [sp+FCh] [bp-1Ch]@5

  v6 = n;
  v7 = pOut;
  v8 = pM;
  if ( (signed int)n >= 4 )
  {
    v36 = _mm_shuffle_ps((__m128)*(_DWORD *)pM, (__m128)*(_DWORD *)pM, 0);
    v37 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 4), (__m128)*(_DWORD *)(pM + 4), 0);
    v38 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 12), (__m128)*(_DWORD *)(pM + 12), 0);
    v39 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 16), (__m128)*(_DWORD *)(pM + 16), 0);
    v40 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 20), (__m128)*(_DWORD *)(pM + 20), 0);
    v41 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 28), (__m128)*(_DWORD *)(pM + 28), 0);
    v42 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 48), (__m128)*(_DWORD *)(pM + 48), 0);
    v43 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 52), (__m128)*(_DWORD *)(pM + 52), 0);
    v44 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 60), (__m128)*(_DWORD *)(pM + 60), 0);
    v11 = pV;
    v12 = VStride;
    for ( i = OutStride; ; i = OutStride )
    {
      while ( (signed int)v6 >= 4 )
      {
        v14 = _mm_loadl_ps((const double *)v11);
        v15 = _mm_loadl_ps((const double *)(v12 + v11));
        v16 = (const double *)(v11 + 2 * v12);
        v17 = _mm_unpacklo_ps(v14, v15);
        v18 = _mm_unpacklo_ps(_mm_loadl_ps(v16), _mm_loadl_ps((const double *)((char *)v16 + v12)));
        v19 = v17;
        v20 = _mm_movelh_ps(v17, v18);
        v21 = _mm_movehl_ps(v18, v19);
        v11 = (unsigned int)((char *)v16 + 2 * v12);
        v22 = v20;
        v23 = v20;
        v24 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, v36), _mm_mul_ps(v21, v39)), v42);
        v25 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v22, v37), _mm_mul_ps(v21, v40)), v43);
        v26 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, v38), _mm_mul_ps(v21, v41)), v44);
        v27 = _mm_rcp_ps(v26);
        v28 = _mm_mul_ps(v27, _mm_sub_ps(*(__m128 *)&AMDSSE_two, _mm_mul_ps(v26, v27)));
        v29 = _mm_mul_ps(v24, v28);
        v30 = _mm_mul_ps(v25, v28);
        v31 = v29;
        v32 = _mm_unpacklo_ps(v29, v30);
        v33 = _mm_unpackhi_ps(v31, v30);
        _mm_storel_ps((double *)v7, v32);
        _mm_storel_ps((double *)(i + v7), _mm_movehl_ps(v32, v32));
        v34 = (double *)(v7 + 2 * i);
        _mm_storel_ps(v34, v33);
        _mm_storel_ps((double *)((char *)v34 + i), _mm_movehl_ps(v33, v33));
        v7 = (int)((char *)v34 + 2 * i);
        v6 -= 4;
      }
      if ( !v6 )
        break;
      v35 = v6 - 4;
      v11 += v35 * v12;
      v7 += v35 * i;
      v6 = 4;
      v12 = VStride;
    }
  }
  else
  {
    v9 = pV;
    for ( j = n == 0; !j; j = n-- == 1 )
    {
      v7 = OutStride + x3d_D3DXVec2TransformCoord(v7, (__m64 *)v9, v8);
      v9 = VStride + pV;
      pV += VStride;
    }
  }
}

//----- (006094C0) --------------------------------------------------------  // acclient.c:560959
void __stdcall AMDSSE_D3DXVec2TransformNormalArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
{
  unsigned int v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  unsigned int v9; // esi@2
  bool j; // zf@2
  unsigned int v11; // edx@5
  unsigned int v12; // esi@5
  unsigned int i; // edi@5
  __m128 v14; // xmm0@7
  __m128 v15; // xmm1@7
  const double *v16; // edx@7
  __m128 v17; // xmm0@7
  __m128 v18; // xmm4@7
  __m128 v19; // xmm1@7
  __m128 v20; // xmm0@7
  __m128 v21; // xmm4@7
  __m128 v22; // xmm1@7
  __m128 v23; // xmm0@7
  __m128 v24; // xmm1@7
  __m128 v25; // xmm2@7
  __m128 v26; // xmm0@7
  __m128 v27; // xmm2@7
  double *v28; // eax@7
  int v29; // ecx@9
  __m128 v30; // [sp+Ch] [bp-10Ch]@5
  __m128 v31; // [sp+1Ch] [bp-FCh]@5
  __m128 v32; // [sp+4Ch] [bp-CCh]@5
  __m128 v33; // [sp+5Ch] [bp-BCh]@5

  v6 = n;
  v7 = pOut;
  v8 = pM;
  if ( (signed int)n >= 4 )
  {
    v30 = _mm_shuffle_ps((__m128)*(_DWORD *)pM, (__m128)*(_DWORD *)pM, 0);
    v31 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 4), (__m128)*(_DWORD *)(pM + 4), 0);
    v32 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 16), (__m128)*(_DWORD *)(pM + 16), 0);
    v33 = _mm_shuffle_ps((__m128)*(_DWORD *)(pM + 20), (__m128)*(_DWORD *)(pM + 20), 0);
    v11 = pV;
    v12 = VStride;
    for ( i = OutStride; ; i = OutStride )
    {
      while ( (signed int)v6 >= 4 )
      {
        v14 = _mm_loadl_ps((const double *)v11);
        v15 = _mm_loadl_ps((const double *)(v12 + v11));
        v16 = (const double *)(v11 + 2 * v12);
        v17 = _mm_unpacklo_ps(v14, v15);
        v18 = _mm_unpacklo_ps(_mm_loadl_ps(v16), _mm_loadl_ps((const double *)((char *)v16 + v12)));
        v19 = v17;
        v20 = _mm_movelh_ps(v17, v18);
        v21 = _mm_movehl_ps(v18, v19);
        v11 = (unsigned int)((char *)v16 + 2 * v12);
        v22 = v20;
        v23 = _mm_add_ps(_mm_mul_ps(v20, v30), _mm_mul_ps(v21, v32));
        v24 = _mm_add_ps(_mm_mul_ps(v22, v31), _mm_mul_ps(v21, v33));
        v25 = v23;
        v26 = _mm_unpacklo_ps(v23, v24);
        v27 = _mm_unpackhi_ps(v25, v24);
        _mm_storel_ps((double *)v7, v26);
        _mm_storel_ps((double *)(i + v7), _mm_movehl_ps(v26, v26));
        v28 = (double *)(v7 + 2 * i);
        _mm_storel_ps(v28, v27);
        _mm_storel_ps((double *)((char *)v28 + i), _mm_movehl_ps(v27, v27));
        v7 = (int)((char *)v28 + 2 * i);
        v6 -= 4;
      }
      if ( !v6 )
        break;
      v29 = v6 - 4;
      v11 += v29 * v12;
      v7 += v29 * i;
      v6 = 4;
      v12 = VStride;
    }
  }
  else
  {
    v9 = pV;
    for ( j = n == 0; !j; j = n-- == 1 )
    {
      v7 = OutStride + x3d_D3DXVec2TransformNormal(v7, (__m64 *)v9, v8);
      v9 = VStride + pV;
      pV += VStride;
    }
  }
}

