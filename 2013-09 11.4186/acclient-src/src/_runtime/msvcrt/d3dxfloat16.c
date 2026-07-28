/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : d3dxfloat16
   Object     : _runtime\msvcrt\d3dxfloat16.obj
   Functions  : 2
   Addresses  : 00611000 - 00611140 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00611000) --------------------------------------------------------  // acclient.c:566413
void __stdcall AMDX3D_D3DXFloat16To32Array(unsigned int pOut, unsigned int pIn, unsigned int n)
{
  unsigned int v3; // ecx@1
  unsigned int v4; // eax@1
  unsigned int v5; // edx@1
  __m64 v6; // mm3@5
  __m64 v7; // mm5@5
  __m64 v8; // mm0@5
  __m64 v9; // mm1@5
  __m64 v10; // mm2@5
  __m64 v11; // mm4@5
  __m64 v12; // mm5@5
  int v13; // ecx@7

  v3 = n;
  v4 = pOut;
  v5 = pIn;
  if ( (signed int)n >= 4 )
  {
    while ( 1 )
    {
      while ( (signed int)v3 >= 4 )
      {
        v6 = _m_punpcklwd(_mm_cvtsi32_si64(*(_DWORD *)v5), 0i64);
        v7 = _m_punpcklwd(_mm_cvtsi32_si64(*(_DWORD *)(v5 + 4)), 0i64);
        v8 = _m_pcmpeqd(_m_pand(v6, *(__m64 *)&AMDX3D_MaskExponentF16), 0i64);
        v9 = _m_pcmpeqd(_m_pand(v7, *(__m64 *)&AMDX3D_MaskExponentF16), 0i64);
        v10 = _m_pand(v6, *(__m64 *)&AMDX3D_MaskSignF16);
        v11 = _m_pand(v7, *(__m64 *)&AMDX3D_MaskSignF16);
        v12 = _m_por(
                _m_pfsub(
                  _m_pslld(
                    _m_paddd(
                      _m_paddd(_m_pxor(v7, v11), *(__m64 *)&AMDX3D_F16toF32ExpBias),
                      _m_pand(v9, *(__m64 *)&AMDX3D_ExpIncF16)),
                    0xDu),
                  _m_pand(v9, *(__m64 *)&AMDX3D_NormalizeF16)),
                _m_pslld(v11, 0x10u));
        *(_QWORD *)v4 = _m_por(
                          _m_pfsub(
                            _m_pslld(
                              _m_paddd(
                                _m_paddd(_m_pxor(v6, v10), *(__m64 *)&AMDX3D_F16toF32ExpBias),
                                _m_pand(v8, *(__m64 *)&AMDX3D_ExpIncF16)),
                              0xDu),
                            _m_pand(v8, *(__m64 *)&AMDX3D_NormalizeF16)),
                          _m_pslld(v10, 0x10u));
        *(_QWORD *)(v4 + 8) = v12;
        v4 += 16;
        v5 += 8;
        v3 -= 4;
      }
      if ( !v3 )
        break;
      v13 = v3 - 4;
      v5 += 2 * v13;
      v4 += 4 * v13;
      v3 = 4;
    }
  }
  else if ( n )
  {
    c_D3DXFloat16To32Array((float *)pOut, (const struct D3DXFLOAT16 *)pIn, n);
  }
  _m_femms();
}

//----- (00611140) --------------------------------------------------------  // acclient.c:566481
void __stdcall AMDX3D_D3DXFloat32To16Array(unsigned int pOut, unsigned int pIn, unsigned int n)
{
  unsigned int v3; // ecx@1
  unsigned int v4; // eax@1
  unsigned int v5; // edx@1
  __m64 v6; // mm1@5
  __m64 v7; // ST0C_8@5
  __m64 v8; // mm6@5
  __m64 v9; // mm7@5
  __m64 v10; // mm3@5
  __m64 v11; // mm0@5
  __m64 v12; // mm5@5
  __m64 v13; // mm1@5
  __m64 v14; // mm4@5
  __m64 v15; // mm5@5
  int v16; // ecx@7

  v3 = n;
  v4 = pOut;
  v5 = pIn;
  if ( (signed int)n >= 4 )
  {
    while ( 1 )
    {
      while ( (signed int)v3 >= 4 )
      {
        v6 = *(__m64 *)(v5 + 8);
        v7 = _m_pslld(
               _m_packssdw(
                 _m_psrld(_m_pand(*(__m64 *)&AMDX3D_MaskSignF32, *(__m64 *)v5), 0x12u),
                 _m_psrld(_m_pand(*(__m64 *)&AMDX3D_MaskSignF32, v6), 0x12u)),
               2u);
        v8 = _m_pand(*(__m64 *)v5, *(__m64 *)&AMDX3D_Mask32);
        v9 = _m_pand(v6, *(__m64 *)&AMDX3D_Mask32);
        v10 = _m_pfcmpge(*(__m64 *)&AMDX3D_MaskSmallest16, v8);
        v11 = _m_psubd(
                _m_pfadd(v8, _m_pand(v10, *(__m64 *)&AMDX3D_MaskSmallest16)),
                _m_pand(v10, *(__m64 *)&AMDX3D_OneShift23));
        v12 = _m_pfcmpge(*(__m64 *)&AMDX3D_MaskSmallest16, v9);
        v13 = _m_psubd(
                _m_pfadd(v9, _m_pand(v12, *(__m64 *)&AMDX3D_MaskSmallest16)),
                _m_pand(v12, *(__m64 *)&AMDX3D_OneShift23));
        v14 = _m_pfcmpgt(*(__m64 *)&AMDX3D_MaskLargest16, v8);
        v15 = _m_pfcmpgt(*(__m64 *)&AMDX3D_MaskLargest16, v9);
        *(_QWORD *)v4 = _m_por(
                          _m_packssdw(
                            _m_por(
                              _m_pand(
                                _m_psrld(
                                  _m_paddd(
                                    _m_paddd(_m_pand(_m_psrld(v11, 0xDu), *(__m64 *)&AMDX3D_One16), v11),
                                    *(__m64 *)&AMDX3D_BiasDiff),
                                  0xDu),
                                v14),
                              _m_pandn(v14, *(__m64 *)&AMDX3D_Inf16)),
                            _m_por(
                              _m_pand(
                                _m_psrld(
                                  _m_paddd(
                                    _m_paddd(_m_pand(_m_psrld(v13, 0xDu), *(__m64 *)&AMDX3D_One16), v13),
                                    *(__m64 *)&AMDX3D_BiasDiff),
                                  0xDu),
                                v15),
                              _m_pandn(v15, *(__m64 *)&AMDX3D_Inf16))),
                          v7);
        v4 += 8;
        v5 += 16;
        v3 -= 4;
      }
      if ( !v3 )
        break;
      v16 = v3 - 4;
      v5 += 4 * v16;
      v4 += 2 * v16;
      v3 = 4;
    }
  }
  else if ( n )
  {
    c_D3DXFloat32To16Array((struct D3DXFLOAT16 *)pOut, (const float *)pIn, n);
  }
  _m_femms();
}

