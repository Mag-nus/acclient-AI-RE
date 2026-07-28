/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : d3dxvec4
   Object     : _runtime\msvcrt\d3dxvec4.obj
   Functions  : 1
   Addresses  : 00608000 - 00608000 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00608000) --------------------------------------------------------  // acclient.c:560683
void __stdcall AMDSSE_D3DXVec4TransformArray(unsigned int pOut, unsigned int OutStride, unsigned int pV, unsigned int VStride, unsigned int pM, unsigned int n)
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
  __m128 v16; // xmm3@3
  unsigned __int8 v17; // of@3

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
      v16 = _mm_shuffle_ps((__m128)*(_DWORD *)(v8 + 12), (__m128)*(_DWORD *)(v8 + 12), 0);
      v8 += VStride;
      *(_OWORD *)v7 = _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v13, v9), _mm_mul_ps(v14, v10)),
                        _mm_add_ps(_mm_mul_ps(v15, v11), _mm_mul_ps(v16, v12)));
      v7 += OutStride;
      v17 = __OFSUB__(v6--, 1);
    }
    while ( !((unsigned __int8)(((v6 & 0x80000000) != 0) ^ v17) | (v6 == 0)) );
  }
}

