/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SoftwareBlit
   Object     : _other\misc\SoftwareBlit.obj
   Functions  : 117
   Addresses  : 00660220 - 0066FEA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00660220) --------------------------------------------------------  // acclient.c:630615
bool __cdecl IsSSEAvailable()
{
  if ( !s_CheckedForSSE )
  {
    s_CheckedForSSE = 1;
    s_bUseSSE = 1;
    _m_femms();
  }
  return s_bUseSSE;
}

//----- (006602A0) --------------------------------------------------------  // acclient.c:630627
void __cdecl AlphaConvert<ACvtFormat_A,ACvtFormat_A>(AlphaConvertArgs *i_rCvtArgs)
{
  AlphaConvertArgs *v1; // eax@1
  unsigned int v2; // ecx@1
  char *v3; // edx@1
  char *v4; // ebx@1
  unsigned int v5; // eax@2
  unsigned int v6; // [sp+4h] [bp-8h]@2
  unsigned int v7; // [sp+8h] [bp-4h]@2
  unsigned int i_rCvtArgsa; // [sp+10h] [bp+4h]@2

  v1 = i_rCvtArgs;
  v2 = i_rCvtArgs->nHeight;
  v3 = i_rCvtArgs->cSrcArgs.pDstBuf;
  v4 = i_rCvtArgs->cDstArgs.pDstBuf;
  if ( (signed int)v2 > 0 )
  {
    i_rCvtArgsa = i_rCvtArgs->nWidth;
    v7 = v1->cDstArgs.iStride;
    v6 = v1->cSrcArgs.iStride;
    v5 = v2;
    do
    {
      qmemcpy(v4, v3, i_rCvtArgsa);
      v3 += v6;
      v4 += v7;
      --v5;
    }
    while ( v5 );
  }
}

//----- (00660300) --------------------------------------------------------  // acclient.c:630660
void __cdecl SoftwareBlitAndColor(BlitArgs *i_rBlitArgs, ColorArgs *i_pColorArgs)
{
  void (__cdecl *v2)(BlitArgs *); // eax@3
  BlitDataFormat v3; // ebx@7
  void (__cdecl *v4)(BlitArgs *); // ebp@7
  char v5; // dl@8
  char v6; // dl@8
  unsigned int v7; // ecx@8
  unsigned int v8; // edx@8
  char *v9; // ecx@9
  unsigned int v10; // eax@9
  char v11; // cl@10
  BlitArgs cColorBlitArgs; // [sp+8h] [bp-28h]@8

  if ( i_rBlitArgs->cSrcArgs.pDstBuf )
  {
    if ( i_rBlitArgs->eMode != 7 )
    {
      v2 = g_aBlitFunctions[0][0][i_rBlitArgs->cDstArgs.eBlitFormat
                                + 3 * (i_rBlitArgs->cSrcArgs.eBlitFormat + 3 * i_rBlitArgs->eMode)];
      if ( v2 )
        v2(i_rBlitArgs);
    }
  }
  if ( i_pColorArgs )
  {
    if ( i_pColorArgs->eMode != 7 )
    {
      v3 = i_pColorArgs->cMaskArgs.eBlitFormat;
      v4 = g_aColoringFunctions[0][0][i_rBlitArgs->cDstArgs.eBlitFormat
                                    + 3 * (i_pColorArgs->eMode + v3 + 2 * i_pColorArgs->eMode)];
      if ( v4 )
      {
        v5 = i_pColorArgs->r;
        g_SourceColor.g = i_pColorArgs->g;
        g_SourceColor.r = v5;
        v6 = i_pColorArgs->b;
        qmemcpy(&cColorBlitArgs, i_rBlitArgs, sizeof(cColorBlitArgs));
        v7 = i_pColorArgs->nWidth;
        g_SourceColor.b = v6;
        v8 = i_pColorArgs->nHeight;
        cColorBlitArgs.nWidth = v7;
        cColorBlitArgs.nHeight = v8;
        if ( v3 )
        {
          v9 = i_pColorArgs->cMaskArgs.pDstBuf;
          v10 = i_pColorArgs->cMaskArgs.iStride;
          cColorBlitArgs.i8AlphaModifier = i_pColorArgs->strength;
          g_SourceColor.a = 0;
          cColorBlitArgs.cSrcArgs.pDstBuf = v9;
          cColorBlitArgs.cSrcArgs.iStride = v10;
          v4(&cColorBlitArgs);
        }
        else
        {
          v11 = i_pColorArgs->strength;
          cColorBlitArgs.i8AlphaModifier = -1;
          g_SourceColor.a = v11;
          v4(&cColorBlitArgs);
        }
      }
    }
  }
}

//----- (00660400) --------------------------------------------------------  // acclient.c:630726
void __cdecl AlphaConvert(AlphaConvertArgs *i_rCvtArgs)
{
  void (*v1)(void); // eax@1

  v1 = (void (*)(void))g_aAlphaConvertFunctions[0][i_rCvtArgs->cDstArgs.eBlitFormat
                                                 + 3 * i_rCvtArgs->cSrcArgs.eBlitFormat];
  if ( v1 )
    v1();
}

//----- (00660420) --------------------------------------------------------  // acclient.c:630737
void __cdecl BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_ARGB_BlitFormat_XRGB__BlitFormat_ARGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  char *v1; // ebx@1
  char *v2; // esi@1
  unsigned int v3; // edi@3
  int v4; // eax@5
  unsigned int v5; // edx@5
  int v6; // ebp@6
  unsigned int v7; // [sp+8h] [bp-8h]@3
  unsigned int v8; // [sp+Ch] [bp-4h]@3
  unsigned int i_argsa; // [sp+14h] [bp+4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v7 = i_args->cSrcArgs.iStride;
      v8 = i_args->cDstArgs.iStride;
      i_argsa = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v2[4 * v3];
          v5 = v3;
          do
          {
            v6 = *(_DWORD *)(v1 - v2 + v4 - 4);
            v4 -= 4;
            --v5;
            *(_DWORD *)v4 = v6;
          }
          while ( v5 );
        }
        v1 += v7;
        v2 += v8;
        --i_argsa;
      }
      while ( i_argsa );
    }
    _m_femms();
  }
}

//----- (00660490) --------------------------------------------------------  // acclient.c:630785
void __cdecl BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  char *v2; // edi@1
  unsigned int v3; // ecx@2
  unsigned int v4; // ebx@3
  unsigned int v5; // eax@3
  unsigned int v6; // ebp@3
  unsigned int v7; // ecx@4
  int v8; // eax@5
  unsigned int v9; // edx@6
  unsigned int v10; // [sp+Ch] [bp-4h]@3
  unsigned int i_argsa; // [sp+14h] [bp+4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->nHeight;
    if ( v3 )
    {
      v4 = i_args->cSrcArgs.iStride;
      v5 = i_args->cDstArgs.iStride;
      i_argsa = i_args->nWidth;
      v10 = v5;
      v6 = v3;
      do
      {
        v7 = i_argsa;
        if ( i_argsa )
        {
          v8 = (int)(&v2[2 * i_argsa + 2] + i_argsa);
          do
          {
            v9 = *(_DWORD *)&v1[4 * v7-- - 4];
            v8 -= 3;
            *(_BYTE *)(v8 - 2) = v9;
            *(_BYTE *)(v8 - 1) = BYTE1(v9);
            *(_BYTE *)v8 = v9 >> 16;
          }
          while ( v7 );
        }
        v1 += v4;
        v2 += v10;
        --v6;
      }
      while ( v6 );
    }
    _m_femms();
  }
}

//----- (00660510) --------------------------------------------------------  // acclient.c:630838
void __cdecl BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_XRGB__BlitFormat_XRGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  char *v1; // ebp@1
  char *v2; // esi@1
  unsigned int v3; // edi@3
  int v4; // eax@5
  unsigned int v5; // edx@5
  BlitArgs *v6; // ebx@6
  unsigned int v7; // [sp+8h] [bp-Ch]@3
  unsigned int v8; // [sp+Ch] [bp-8h]@3
  unsigned int v9; // [sp+10h] [bp-4h]@3
  BlitArgs *i_argsa; // [sp+18h] [bp+4h]@6

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v8 = i_args->cSrcArgs.iStride;
      v9 = i_args->cDstArgs.iStride;
      v7 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v2[4 * v3];
          v5 = v3;
          do
          {
            v6 = *(BlitArgs **)(v1 - v2 + v4 - 4);
            v4 -= 4;
            --v5;
            i_argsa = v6;
            BYTE3(i_argsa) = -1;
            *(_DWORD *)v4 = i_argsa;
          }
          while ( v5 );
        }
        v1 += v8;
        v2 += v9;
        --v7;
      }
      while ( v7 );
    }
    _m_femms();
  }
}

//----- (00660590) --------------------------------------------------------  // acclient.c:630889
void __cdecl BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_RGB_BlitFormat_XRGB__BlitFormat_RGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  char *v2; // edi@1
  unsigned int v3; // edx@3
  unsigned int v4; // ebp@3
  unsigned int v5; // eax@4
  int v6; // ecx@5
  char v7; // bl@6
  unsigned int v8; // [sp+8h] [bp-8h]@3
  unsigned int v9; // [sp+Ch] [bp-4h]@3
  BlitArgs *i_argsa; // [sp+14h] [bp+4h]@5

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    if ( i_args->nHeight )
    {
      v8 = i_args->nWidth;
      v3 = i_args->cSrcArgs.iStride;
      v9 = i_args->cDstArgs.iStride;
      v4 = i_args->nHeight;
      do
      {
        v5 = v8;
        if ( v8 )
        {
          BYTE3(i_argsa) = -1;
          v6 = (int)(&v2[2 * v8 + 2] + v8);
          do
          {
            v7 = *(_BYTE *)(v6 - 5);
            v6 -= 3;
            LOBYTE(i_argsa) = v7;
            BYTE1(i_argsa) = *(_BYTE *)(v6 - 1);
            --v5;
            BYTE2(i_argsa) = *(_BYTE *)v6;
            *(_DWORD *)&v1[4 * v5] = i_argsa;
          }
          while ( v5 );
        }
        v2 += v3;
        v1 += v9;
        --v4;
      }
      while ( v4 );
    }
    _m_femms();
  }
}

//----- (00660610) --------------------------------------------------------  // acclient.c:630942
void __cdecl BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  BlitArgs *v1; // eax@1
  char v2; // cl@1
  char *v3; // edx@1
  char *v4; // esi@1
  unsigned int v5; // ebp@3
  int v6; // ecx@5
  int v7; // eax@5
  int v8; // esi@5
  unsigned int v9; // edi@5
  char v10; // bl@6
  char v11; // dl@6
  char pixSrc_1; // ST19_1@6
  char v13; // bl@6
  bool v14; // zf@8
  char *pDst; // [sp+4h] [bp-14h]@1
  unsigned int v16; // [sp+8h] [bp-10h]@3
  unsigned int v17; // [sp+10h] [bp-8h]@3
  unsigned int v18; // [sp+14h] [bp-4h]@3
  char *i_argsa; // [sp+1Ch] [bp+4h]@1

  v1 = i_args;
  v2 = i_args->i8AlphaModifier;
  v3 = i_args->cSrcArgs.pDstBuf;
  v4 = i_args->cDstArgs.pDstBuf;
  i_argsa = i_args->cSrcArgs.pDstBuf;
  pDst = v4;
  if ( v2 )
  {
    if ( v1->nHeight )
    {
      v5 = v1->nWidth;
      v17 = v1->cSrcArgs.iStride;
      v18 = v1->cDstArgs.iStride;
      v16 = v1->nHeight;
      do
      {
        if ( v5 )
        {
          v6 = (int)&v4[3 * v5];
          v7 = (int)&v3[3 * v5 + 2];
          v8 = v4 - v3;
          v9 = v5;
          do
          {
            v10 = *(_BYTE *)(v7 - 4);
            v11 = *(_BYTE *)(v7 - 5);
            v7 -= 3;
            v6 -= 3;
            --v9;
            pixSrc_1 = v10;
            v13 = *(_BYTE *)v7;
            *(_BYTE *)v6 = v11;
            *(_BYTE *)(v6 + 1) = pixSrc_1;
            *(_BYTE *)(v8 + v7) = v13;
          }
          while ( v9 );
          v4 = pDst;
          v3 = i_argsa;
        }
        v3 += v17;
        v4 += v18;
        v14 = v16 == 1;
        i_argsa = v3;
        pDst = v4;
        --v16;
      }
      while ( !v14 );
    }
    _m_femms();
  }
}

//----- (006606C0) --------------------------------------------------------  // acclient.c:631017
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  int v4; // ecx@5
  int v5; // edi@5
  unsigned int v6; // esi@6
  unsigned int v7; // eax@6
  unsigned int v8; // edx@9
  unsigned int v9; // eax@9
  __m64 v10; // mm2@11
  __m64 v11; // mm0@11
  __m64 v12; // mm3@11
  __m64 v13; // mm4@11
  __m64 v14; // mm3@11
  bool v15; // zf@14
  char *v16; // [sp+Ch] [bp-24h]@1
  unsigned int v17; // [sp+10h] [bp-20h]@5
  char *v18; // [sp+14h] [bp-1Ch]@1
  unsigned int v19; // [sp+18h] [bp-18h]@3
  int v20; // [sp+20h] [bp-10h]@2
  unsigned int v21; // [sp+24h] [bp-Ch]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v16 = i_args->cSrcArgs.pDstBuf;
  v18 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v20 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v5 = v16 - v1;
          v17 = v3;
          do
          {
            v6 = *(_DWORD *)(v5 + v4 - 4);
            v4 -= 4;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = *(_DWORD *)v4;
              v9 = v7 + 1;
              if ( v9 == 256 )
              {
                *(_DWORD *)v4 = v8 ^ (v6 ^ v8) & 0xFFFFFF;
              }
              else
              {
                v2 = v20;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v12 = _mm_cvtsi32_si64(v9);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                *(_DWORD *)v4 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
            }
            --v17;
          }
          while ( v17 );
          v1 = v18;
          v3 = v21;
        }
        v1 += v23;
        v15 = v19 == 1;
        v16 += v22;
        v18 = v1;
        --v19;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (00660820) --------------------------------------------------------  // acclient.c:631109
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // edi@6
  unsigned int v6; // eax@6
  unsigned int v7; // eax@9
  int v8; // eax@10
  __m64 v9; // mm2@11
  __m64 v10; // mm0@11
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  unsigned int v14; // ST10_4@11
  bool v15; // zf@13
  unsigned int v16; // [sp+10h] [bp-20h]@9
  char *v17; // [sp+14h] [bp-1Ch]@1
  char *v18; // [sp+18h] [bp-18h]@1
  unsigned int v19; // [sp+1Ch] [bp-14h]@3
  unsigned int v20; // [sp+20h] [bp-10h]@3
  unsigned int v21; // [sp+28h] [bp-8h]@3
  unsigned int v22; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v17 = i_args->cSrcArgs.pDstBuf;
  v18 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v21 = i_args->cSrcArgs.iStride;
      v22 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        v3 = v20;
        if ( v20 )
        {
          v4 = (int)(&v1[2 * v20 + 2] + v20);
          do
          {
            v5 = *(_DWORD *)&v17[4 * v3-- - 4];
            v4 -= 3;
            v6 = v5 >> 24;
            if ( v2 != 256 )
              v6 = (signed int)(v2 * v6) / 256;
            if ( v6 )
            {
              LOBYTE(v16) = *(_BYTE *)(v4 - 2);
              v7 = v6 + 1;
              BYTE1(v16) = *(_BYTE *)(v4 - 1);
              BYTE2(v16) = *(_BYTE *)v4;
              BYTE3(v16) = -1;
              if ( v7 == 256 )
              {
                v8 = v16 ^ (v5 ^ v16) & 0xFFFFFF;
                *(_BYTE *)(v4 - 2) = v16 ^ v5 ^ v16;
                *(_BYTE *)(v4 - 1) = BYTE1(v8);
                *(_BYTE *)v4 = (unsigned int)v8 >> 16;
              }
              else
              {
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v16), 0i64);
                v11 = _mm_cvtsi32_si64(v7);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
                *(_BYTE *)(v4 - 2) = v14;
                *(_BYTE *)(v4 - 1) = BYTE1(v14);
                *(_BYTE *)v4 = v14 >> 16;
              }
            }
          }
          while ( v3 );
        }
        v17 += v21;
        v1 = &v18[v22];
        v15 = v19 == 1;
        v18 += v22;
        --v19;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (006609B0) --------------------------------------------------------  // acclient.c:631202
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // edi@2
  unsigned int v3; // ebx@3
  int v4; // ecx@5
  int v5; // esi@5
  unsigned int v6; // edx@6
  int v7; // eax@6
  unsigned int v8; // edx@8
  unsigned int v9; // eax@8
  __m64 v10; // mm2@10
  __m64 v11; // mm0@10
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@13
  unsigned int v16; // [sp+10h] [bp-20h]@6
  char *v17; // [sp+14h] [bp-1Ch]@1
  unsigned int v18; // [sp+18h] [bp-18h]@5
  char *v19; // [sp+1Ch] [bp-14h]@1
  unsigned int v20; // [sp+20h] [bp-10h]@3
  unsigned int v21; // [sp+24h] [bp-Ch]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v17 = i_args->cSrcArgs.pDstBuf;
  v19 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v5 = v17 - v1;
          v18 = v3;
          do
          {
            v6 = *(_DWORD *)(v5 + v4 - 4);
            v4 -= 4;
            v16 = v6;
            BYTE3(v16) = -1;
            v7 = 255;
            if ( v2 == 256 || (v7 = 255 * v2 / 256) != 0 )
            {
              v8 = *(_DWORD *)v4;
              v9 = v7 + 1;
              if ( v9 == 256 )
              {
                *(_DWORD *)v4 = v8 ^ (v16 ^ v8) & 0xFFFFFF;
              }
              else
              {
                v3 = v21;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v12 = _mm_cvtsi32_si64(v9);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                *(_DWORD *)v4 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v16), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
            }
            --v18;
          }
          while ( v18 );
          v1 = v19;
        }
        v1 += v23;
        v15 = v20 == 1;
        v17 += v22;
        v19 = v1;
        --v20;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (00660B20) --------------------------------------------------------  // acclient.c:631292
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  unsigned int v6; // edx@6
  int v7; // eax@6
  unsigned int v8; // eax@8
  int v9; // ST10_4@9
  __m64 v10; // mm2@10
  __m64 v11; // mm0@10
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  unsigned int v15; // ST0C_4@10
  bool v16; // zf@12
  unsigned int v17; // [sp+Ch] [bp-1Ch]@8
  unsigned int v18; // [sp+10h] [bp-18h]@6
  char *v19; // [sp+14h] [bp-14h]@1
  unsigned int v20; // [sp+18h] [bp-10h]@3
  unsigned int v21; // [sp+1Ch] [bp-Ch]@3
  unsigned int v22; // [sp+20h] [bp-8h]@3
  unsigned int v23; // [sp+24h] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  v19 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        v4 = v21;
        if ( v21 )
        {
          v5 = (int)(&v1[2 * v21 + 2] + v21);
          do
          {
            v6 = *(_DWORD *)&v2[4 * v4-- - 4];
            v5 -= 3;
            v18 = v6;
            BYTE3(v18) = -1;
            v7 = 255;
            if ( v3 != 256 )
            {
              v7 = 255 * v3 / 256;
              if ( !v7 )
                continue;
            }
            LOBYTE(v17) = *(_BYTE *)(v5 - 2);
            v8 = v7 + 1;
            BYTE1(v17) = *(_BYTE *)(v5 - 1);
            BYTE2(v17) = *(_BYTE *)v5;
            BYTE3(v17) = -1;
            if ( v8 == 256 )
            {
              v9 = v17 ^ (v18 ^ v17) & 0xFFFFFF;
              *(_BYTE *)(v5 - 2) = v9;
              *(_BYTE *)(v5 - 1) = BYTE1(v9);
              *(_BYTE *)v5 = (unsigned int)v9 >> 16;
            }
            else
            {
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v17), 0i64);
              v12 = _mm_cvtsi32_si64(v8);
              v13 = _m_punpcklwd(v12, v12);
              v14 = _m_punpcklwd(v13, v13);
              v15 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              *(_BYTE *)(v5 - 2) = v15;
              *(_BYTE *)(v5 - 1) = BYTE1(v15);
              *(_BYTE *)v5 = v15 >> 16;
            }
          }
          while ( v4 );
        }
        v2 += v22;
        v1 = &v19[v23];
        v16 = v20 == 1;
        v19 += v23;
        --v20;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (00660CB0) --------------------------------------------------------  // acclient.c:631389
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // edi@1
  int v3; // ebx@2
  unsigned int v4; // ecx@4
  int v5; // esi@5
  char v6; // al@6
  char v7; // dl@6
  int v8; // eax@6
  unsigned int v9; // edx@8
  unsigned int v10; // eax@8
  __m64 v11; // mm2@10
  __m64 v12; // mm0@10
  __m64 v13; // mm3@10
  __m64 v14; // mm4@10
  __m64 v15; // mm3@10
  bool v16; // zf@12
  unsigned int v17; // [sp+Ch] [bp-1Ch]@5
  char *v18; // [sp+10h] [bp-18h]@1
  unsigned int v19; // [sp+14h] [bp-14h]@3
  unsigned int v20; // [sp+18h] [bp-10h]@3
  int v21; // [sp+1Ch] [bp-Ch]@2
  unsigned int v22; // [sp+20h] [bp-8h]@3
  unsigned int v23; // [sp+24h] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  v18 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    v21 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        v4 = v20;
        if ( v20 )
        {
          BYTE3(v17) = -1;
          v5 = (int)(&v1[2 * v20 + 2] + v20);
          do
          {
            v6 = *(_BYTE *)(v5 - 5);
            v7 = *(_BYTE *)(v5 - 4);
            v5 -= 3;
            LOBYTE(v17) = v6;
            --v4;
            BYTE2(v17) = *(_BYTE *)v5;
            BYTE1(v17) = v7;
            v8 = 255;
            if ( v3 != 256 )
            {
              v8 = 255 * v3 / 256;
              if ( !v8 )
                continue;
            }
            v9 = *(_DWORD *)&v2[4 * v4];
            v10 = v8 + 1;
            if ( v10 == 256 )
            {
              *(_DWORD *)&v2[4 * v4] = v9 ^ (v17 ^ v9) & 0xFFFFFF;
            }
            else
            {
              v3 = v21;
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v12 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
              v13 = _mm_cvtsi32_si64(v10);
              v14 = _m_punpcklwd(v13, v13);
              v15 = _m_punpcklwd(v14, v14);
              *(_DWORD *)&v2[4 * v4] = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v15), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v17), 0i64), v11), _m_pandn(v11, v12)), v15), 8u))), 0i64));
            }
          }
          while ( v4 );
        }
        v1 = &v18[v22];
        v2 += v23;
        v16 = v19 == 1;
        v18 += v22;
        --v19;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (00660E20) --------------------------------------------------------  // acclient.c:631483
void __cdecl BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  int v2; // ebx@2
  unsigned int v3; // edx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // esi@5
  char v7; // dl@6
  char v8; // al@6
  int v9; // eax@6
  unsigned int v10; // eax@8
  int v11; // eax@9
  __m64 v12; // mm2@10
  __m64 v13; // mm0@10
  __m64 v14; // mm3@10
  __m64 v15; // mm4@10
  __m64 v16; // mm3@10
  unsigned int v17; // ST10_4@10
  bool v18; // zf@13
  unsigned int v19; // [sp+10h] [bp-28h]@8
  unsigned int v20; // [sp+14h] [bp-24h]@5
  char *v21; // [sp+18h] [bp-20h]@1
  unsigned int v22; // [sp+1Ch] [bp-1Ch]@5
  char *v23; // [sp+20h] [bp-18h]@1
  unsigned int v24; // [sp+24h] [bp-14h]@3
  unsigned int v25; // [sp+2Ch] [bp-Ch]@3
  unsigned int v26; // [sp+30h] [bp-8h]@3
  unsigned int v27; // [sp+34h] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v23 = i_args->cSrcArgs.pDstBuf;
  v21 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v25 = i_args->nWidth;
      v26 = i_args->cSrcArgs.iStride;
      v27 = i_args->cDstArgs.iStride;
      v24 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[3 * v3];
          v5 = (int)&v21[3 * v3 + 2];
          BYTE3(v20) = -1;
          v6 = v1 - v21;
          v22 = v3;
          do
          {
            v7 = *(_BYTE *)(v4 - 3);
            v8 = *(_BYTE *)(v6 + v5 - 4);
            v4 -= 3;
            v5 -= 3;
            LOBYTE(v20) = v7;
            BYTE1(v20) = v8;
            BYTE2(v20) = *(_BYTE *)(v6 + v5);
            v9 = 255;
            if ( v2 == 256 || (v9 = 255 * v2 / 256) != 0 )
            {
              LOBYTE(v19) = *(_BYTE *)(v5 - 2);
              v10 = v9 + 1;
              BYTE1(v19) = *(_BYTE *)(v5 - 1);
              BYTE2(v19) = *(_BYTE *)v5;
              BYTE3(v19) = -1;
              if ( v10 == 256 )
              {
                v11 = v19 ^ (v20 ^ v19) & 0xFFFFFF;
                *(_BYTE *)(v5 - 2) = v19 ^ v20 ^ v19;
                *(_BYTE *)(v5 - 1) = BYTE1(v11);
                *(_BYTE *)v5 = (unsigned int)v11 >> 16;
              }
              else
              {
                v12 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v13 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
                v14 = _mm_cvtsi32_si64(v10);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v13, _m_psubw(_m_psrlw(_m_pmullw(v13, v16), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v20), 0i64), v12), _m_pandn(v12, v13)), v16), 8u))), 0i64));
                *(_BYTE *)(v5 - 2) = v17;
                *(_BYTE *)(v5 - 1) = BYTE1(v17);
                *(_BYTE *)v5 = v17 >> 16;
              }
            }
            --v22;
          }
          while ( v22 );
          v1 = v23;
          v3 = v25;
        }
        v1 += v26;
        v18 = v24 == 1;
        v23 = v1;
        v21 += v27;
        --v24;
      }
      while ( !v18 );
    }
    _m_femms();
  }
}

//----- (00660FE0) --------------------------------------------------------  // acclient.c:631591
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ecx@1
  char *v2; // edi@1
  int v3; // ebp@2
  unsigned int v4; // edx@3
  int v5; // edi@5
  int v6; // esi@5
  unsigned int v7; // ecx@6
  unsigned int v8; // ebx@6
  int v9; // edx@6
  int v10; // eax@6
  BlitArgs *v11; // eax@9
  int v12; // edi@9
  int v13; // esi@9
  int v14; // ecx@9
  signed int v15; // ebx@9
  int v16; // esi@9
  int v17; // edi@9
  int v18; // edx@9
  signed int v19; // esi@18
  int v20; // ebp@18
  signed int v21; // ebp@19
  int v22; // ecx@20
  int v23; // ecx@26
  int v24; // ebx@33
  int v25; // ebp@33
  signed int v26; // esi@33
  int v27; // edi@33
  int v28; // eax@33
  int v29; // ebx@48
  int v30; // ebp@48
  signed int v31; // esi@48
  int v32; // edi@48
  int v33; // eax@48
  __int64 v34; // rax@60
  bool v35; // zf@64
  int v36; // [sp+8h] [bp-58h]@0
  int v37; // [sp+Ch] [bp-54h]@0
  int v38; // [sp+10h] [bp-50h]@0
  int v39; // [sp+14h] [bp-4Ch]@0
  int v40; // [sp+18h] [bp-48h]@0
  int v41; // [sp+1Ch] [bp-44h]@0
  int v42; // [sp+20h] [bp-40h]@6
  int v43; // [sp+24h] [bp-3Ch]@6
  unsigned int v44; // [sp+28h] [bp-38h]@5
  char *pSrc; // [sp+2Ch] [bp-34h]@1
  char *pDst; // [sp+30h] [bp-30h]@1
  unsigned int v47; // [sp+34h] [bp-2Ch]@3
  int v48; // [sp+44h] [bp-1Ch]@5
  int iModifier; // [sp+48h] [bp-18h]@2
  unsigned int idxX; // [sp+4Ch] [bp-14h]@3
  unsigned int v51; // [sp+50h] [bp-10h]@3
  unsigned int v52; // [sp+54h] [bp-Ch]@3
  BlitArgs *i_argsa; // [sp+64h] [bp+4h]@9

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v4 = i_args->nWidth;
      idxX = i_args->nWidth;
      v51 = i_args->cSrcArgs.iStride;
      v52 = i_args->cDstArgs.iStride;
      v47 = i_args->nHeight;
      do
      {
        if ( v4 )
        {
          v5 = v2 - v1;
          v6 = (int)&v1[4 * v4];
          v48 = v5;
          v44 = v4;
          do
          {
            v7 = *(_DWORD *)(v5 + v6 - 4);
            v6 -= 4;
            v8 = v7 >> 16;
            v9 = BYTE1(v8) != 0;
            v43 = v6;
            v10 = v9 + BYTE1(v8);
            v42 = v9 + BYTE1(v8);
            if ( v3 != 256 )
            {
              v10 = v3 * v10 / 256;
              v42 = v10;
            }
            if ( v10 )
            {
              v11 = *(BlitArgs **)v6;
              v12 = (unsigned __int8)v7;
              v13 = BYTE1(v7);
              i_argsa = v11;
              v14 = ((unsigned __int8)v8 != 0) + (unsigned __int8)v8;
              v15 = v14;
              v16 = (v13 != 0) + v13;
              v17 = (v12 != 0) + v12;
              v18 = v14;
              if ( v16 <= v14 )
              {
                if ( v16 < v14 )
                  v18 = v16;
              }
              else
              {
                v15 = v16;
              }
              if ( v17 <= v15 )
              {
                if ( v17 < v18 )
                  v18 = v17;
              }
              else
              {
                v15 = v17;
              }
              if ( v15 == v18 )
              {
                v19 = 0;
                v20 = 0;
              }
              else
              {
                v21 = 0;
                if ( v14 == v15 )
                {
                  v22 = v16 - v17;
                  if ( v16 - v17 < 0 )
                    v21 = 24576;
                }
                else if ( v16 == v15 )
                {
                  v22 = v17 - v14;
                  v21 = 0x2000;
                }
                else
                {
                  v22 = v14 - v16;
                  v21 = 0x4000;
                }
                v19 = v21 + (v22 << 12) / (v15 - v18);
                v20 = ((v15 - v18) << 8) / v15;
              }
              v23 = (BYTE2(v11) != 0) + BYTE2(v11);
              if ( (BYTE1(i_argsa) != 0) + BYTE1(i_argsa) > v23 )
                v23 = (BYTE1(i_argsa) != 0) + BYTE1(i_argsa);
              if ( ((unsigned __int8)v11 != 0) + (unsigned __int8)v11 > v23 )
                v23 = ((unsigned __int8)v11 != 0) + (unsigned __int8)v11;
              if ( v42 == 256 )
              {
                if ( v20 )
                {
                  v24 = v19 / 4096;
                  v25 = v20 * v23 / 256;
                  v26 = v25 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v27 = v23 - v25;
                  v28 = v26 / 4096;
                  if ( v26 % 4096 < -2048 )
                    --v28;
                  if ( v26 % 4096 > 2048 )
                    ++v28;
                  switch ( v24 )
                  {
                    case 0:
                      v36 = v23 - v25;
                      v38 = v28 + v27;
                      goto LABEL_44;
                    case 1:
                      v36 = v23 - v25;
                      v38 = v23;
                      v37 = v27 - v28;
                      break;
                    case 2:
                      v37 = v23 - v25;
                      v38 = v23;
                      v36 = v28 + v27;
                      break;
                    case 3:
                      v37 = v23 - v25;
                      v36 = v23;
                      v38 = v27 - v28;
                      break;
                    case 4:
                      v38 = v23 - v25;
                      v36 = v23;
                      v37 = v28 + v27;
                      break;
                    case 5:
                      v38 = v23 - v25;
                      v36 = v27 - v28;
                      goto LABEL_44;
                    default:
                      break;
                  }
                }
                else
                {
                  v38 = v23;
                  v36 = v23;
LABEL_44:
                  v37 = v23;
                }
                v37 -= v37 != 0;
                BYTE2(i_argsa) = v37;
                v38 -= v38 != 0;
                BYTE1(i_argsa) = v38;
                v36 -= v36 != 0;
                LOBYTE(i_argsa) = v36;
              }
              else
              {
                if ( v20 )
                {
                  v29 = v19 / 4096;
                  v30 = v20 * v23 / 256;
                  v31 = v30 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v32 = v23 - v30;
                  v33 = v31 / 4096;
                  if ( v31 % 4096 < -2048 )
                    --v33;
                  if ( v31 % 4096 > 2048 )
                    ++v33;
                  switch ( v29 )
                  {
                    case 0:
                      v41 = v23 - v30;
                      v40 = v33 + v32;
                      goto LABEL_59;
                    case 1:
                      v41 = v23 - v30;
                      v40 = v23;
                      v39 = v32 - v33;
                      break;
                    case 2:
                      v39 = v23 - v30;
                      v40 = v23;
                      v41 = v33 + v32;
                      break;
                    case 3:
                      v39 = v23 - v30;
                      v41 = v23;
                      v40 = v32 - v33;
                      break;
                    case 4:
                      v40 = v23 - v30;
                      v41 = v23;
                      v39 = v33 + v32;
                      break;
                    case 5:
                      v40 = v23 - v30;
                      v41 = v32 - v33;
                      goto LABEL_59;
                    default:
                      break;
                  }
                }
                else
                {
                  v40 = v23;
                  v41 = v23;
LABEL_59:
                  v39 = v23;
                }
                v39 -= v39 != 0;
                v40 -= v40 != 0;
                BYTE2(i_argsa) -= v42 * (BYTE2(i_argsa) - v39) / 256;
                BYTE1(i_argsa) -= v42 * (BYTE1(i_argsa) - v40) / 256;
                v34 = v42 * ((unsigned __int8)i_argsa - (v41 - (v41 != 0)));
                v41 -= v41 != 0;
                LOBYTE(i_argsa) = (_BYTE)i_argsa - ((unsigned __int16)(BYTE4(v34) + (_WORD)v34) >> 8);
              }
              v5 = v48;
              v3 = iModifier;
              *(_DWORD *)v43 = i_argsa;
              v6 = v43;
            }
            --v44;
          }
          while ( v44 );
          v1 = pDst;
          v4 = idxX;
        }
        v2 = &pSrc[v51];
        v1 += v52;
        v35 = v47 == 1;
        pSrc += v51;
        pDst = v1;
        --v47;
      }
      while ( !v35 );
    }
    _m_femms();
  }
}

//----- (006614A0) --------------------------------------------------------  // acclient.c:631893
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // edx@2
  unsigned int v2; // edi@4
  int v3; // esi@5
  unsigned int v4; // ecx@6
  unsigned int v5; // ebx@6
  int v6; // eax@6
  int v7; // ebp@6
  signed int v8; // kr00_4@7
  unsigned __int8 v9; // al@9
  unsigned __int8 v10; // dl@9
  int v11; // edi@9
  int v12; // esi@9
  int v13; // ecx@9
  signed int v14; // ebp@9
  int v15; // esi@9
  int v16; // edx@9
  int v17; // edi@9
  signed int v18; // esi@18
  int v19; // ebp@18
  signed int v20; // ebx@19
  int v21; // ecx@20
  int v22; // ecx@26
  int v23; // ebx@33
  int v24; // ebp@33
  signed int v25; // esi@33
  int v26; // edi@33
  int v27; // eax@33
  char v28; // cl@45
  int v29; // ebx@45
  char v30; // al@45
  char v31; // bl@45
  int v32; // ebx@48
  int v33; // ebp@48
  signed int v34; // esi@48
  int v35; // edi@48
  int v36; // eax@48
  int v37; // edx@60
  bool v38; // zf@63
  int v39; // [sp+0h] [bp-54h]@0
  int v40; // [sp+4h] [bp-50h]@0
  int v41; // [sp+8h] [bp-4Ch]@0
  int v42; // [sp+Ch] [bp-48h]@0
  int v43; // [sp+10h] [bp-44h]@0
  unsigned __int8 v44; // [sp+14h] [bp-40h]@9
  unsigned __int8 v45; // [sp+15h] [bp-3Fh]@9
  unsigned __int8 v46; // [sp+16h] [bp-3Eh]@9
  int v47; // [sp+18h] [bp-3Ch]@6
  char *pSrc; // [sp+1Ch] [bp-38h]@1
  char *pDst; // [sp+20h] [bp-34h]@1
  signed int v50; // [sp+24h] [bp-30h]@17
  int v51; // [sp+28h] [bp-2Ch]@6
  int iModifier; // [sp+2Ch] [bp-28h]@2
  unsigned int v53; // [sp+30h] [bp-24h]@3
  unsigned int v54; // [sp+34h] [bp-20h]@3
  unsigned int idxX; // [sp+40h] [bp-14h]@6
  unsigned int v56; // [sp+44h] [bp-10h]@3
  unsigned int v57; // [sp+48h] [bp-Ch]@3

  pDst = i_args->cDstArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v1 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v54 = i_args->nWidth;
      v56 = i_args->cSrcArgs.iStride;
      v57 = i_args->cDstArgs.iStride;
      v53 = i_args->nHeight;
      do
      {
        v2 = v54;
        if ( v54 )
        {
          v3 = (int)(&pDst[2 * v54 + 2] + v54);
          do
          {
            v4 = *(_DWORD *)&pSrc[4 * v2-- - 4];
            v5 = v4 >> 16;
            v3 -= 3;
            v6 = BYTE1(v5) != 0;
            idxX = v2;
            v51 = v3;
            v7 = v6 + BYTE1(v5);
            v47 = v6 + BYTE1(v5);
            if ( v1 != 256 )
            {
              v8 = v1 * v7;
              v1 = iModifier;
              v47 = v8 / 256;
              v7 = v8 / 256;
            }
            if ( v7 )
            {
              v9 = *(_BYTE *)(v3 - 1);
              v44 = *(_BYTE *)(v3 - 2);
              v10 = *(_BYTE *)v3;
              v11 = (unsigned __int8)v4;
              v12 = BYTE1(v4);
              v45 = v9;
              v46 = v10;
              v13 = ((unsigned __int8)v5 != 0) + (unsigned __int8)v5;
              v14 = v13;
              v15 = (v12 != 0) + v12;
              v16 = ((unsigned __int8)v5 != 0) + (unsigned __int8)v5;
              v17 = (v11 != 0) + v11;
              if ( v15 <= v13 )
              {
                if ( v15 < v13 )
                  v16 = v15;
              }
              else
              {
                v14 = v15;
              }
              if ( v17 <= v14 )
              {
                if ( v17 < v16 )
                  v16 = v17;
              }
              else
              {
                v14 = v17;
              }
              v50 = v14 - v16;
              if ( v14 == v16 )
              {
                v18 = 0;
                v19 = 0;
              }
              else
              {
                v20 = 0;
                if ( v13 == v14 )
                {
                  v21 = v15 - v17;
                  if ( v15 - v17 < 0 )
                    v20 = 24576;
                }
                else if ( v15 == v14 )
                {
                  v21 = v17 - v13;
                  v20 = 0x2000;
                }
                else
                {
                  v21 = v13 - v15;
                  v20 = 0x4000;
                }
                v19 = ((v14 - v16) << 8) / v14;
                v18 = v20 + (v21 << 12) / v50;
              }
              v22 = (v46 != 0) + v46;
              if ( (v9 != 0) + v9 > v22 )
                v22 = (v9 != 0) + v9;
              if ( (v44 != 0) + v44 > v22 )
                v22 = (v44 != 0) + v44;
              if ( v47 == 256 )
              {
                if ( v19 )
                {
                  v23 = v18 / 4096;
                  v24 = v19 * v22 / 256;
                  v25 = v24 * (v18 - ((v18 / 4096 + 1) / 2 << 13));
                  v26 = v22 - v24;
                  v27 = v25 / 4096;
                  if ( v25 % 4096 < -2048 )
                    --v27;
                  if ( v25 % 4096 > 2048 )
                    ++v27;
                  switch ( v23 )
                  {
                    case 0:
                      i_args = (BlitArgs *)(v22 - v24);
                      v40 = v27 + v26;
                      goto LABEL_44;
                    case 1:
                      i_args = (BlitArgs *)(v22 - v24);
                      v40 = v22;
                      v39 = v26 - v27;
                      break;
                    case 2:
                      v39 = v22 - v24;
                      v40 = v22;
                      i_args = (BlitArgs *)(v27 + v26);
                      break;
                    case 3:
                      v39 = v22 - v24;
                      i_args = (BlitArgs *)v22;
                      v40 = v26 - v27;
                      break;
                    case 4:
                      v40 = v22 - v24;
                      i_args = (BlitArgs *)v22;
                      v39 = v27 + v26;
                      break;
                    case 5:
                      v40 = v22 - v24;
                      i_args = (BlitArgs *)(v26 - v27);
                      goto LABEL_44;
                    default:
                      break;
                  }
                }
                else
                {
                  v40 = v22;
                  i_args = (BlitArgs *)v22;
LABEL_44:
                  v39 = v22;
                }
                v28 = v39 - (v39 != 0);
                v39 -= v39 != 0;
                v29 = i_args != 0;
                v40 -= v40 != 0;
                v30 = (_BYTE)i_args - v29;
                i_args = (BlitArgs *)((char *)i_args - v29);
                v31 = v40;
              }
              else
              {
                if ( v19 )
                {
                  v32 = v18 / 4096;
                  v33 = v19 * v22 / 256;
                  v34 = v33 * (v18 - ((v18 / 4096 + 1) / 2 << 13));
                  v35 = v22 - v33;
                  v36 = v34 / 4096;
                  if ( v34 % 4096 < -2048 )
                    --v36;
                  if ( v34 % 4096 > 2048 )
                    ++v36;
                  switch ( v32 )
                  {
                    case 0:
                      v43 = v22 - v33;
                      v42 = v36 + v35;
                      goto LABEL_59;
                    case 1:
                      v43 = v22 - v33;
                      v42 = v22;
                      v41 = v35 - v36;
                      break;
                    case 2:
                      v41 = v22 - v33;
                      v42 = v22;
                      v43 = v36 + v35;
                      break;
                    case 3:
                      v41 = v22 - v33;
                      v43 = v22;
                      v42 = v35 - v36;
                      break;
                    case 4:
                      v42 = v22 - v33;
                      v43 = v22;
                      v41 = v36 + v35;
                      break;
                    case 5:
                      v42 = v22 - v33;
                      v43 = v35 - v36;
                      goto LABEL_59;
                    default:
                      break;
                  }
                }
                else
                {
                  v42 = v22;
                  v43 = v22;
LABEL_59:
                  v41 = v22;
                }
                v41 -= v41 != 0;
                v42 -= v42 != 0;
                v28 = v46 - v47 * (v46 - v41) / 256;
                v31 = v45 - v47 * (v45 - v42) / 256;
                v37 = v47 * (v44 - (v43 - (v43 != 0))) / 256;
                v43 -= v43 != 0;
                v30 = v44 - v37;
              }
              v3 = v51;
              v2 = idxX;
              v1 = iModifier;
              *(_BYTE *)(v51 - 2) = v30;
              *(_BYTE *)(v51 - 1) = v31;
              *(_BYTE *)v51 = v28;
            }
          }
          while ( v2 );
        }
        v38 = v53 == 1;
        pSrc += v56;
        pDst += v57;
        --v53;
      }
      while ( !v38 );
    }
    _m_femms();
  }
}

//----- (00661960) --------------------------------------------------------  // acclient.c:632199
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // edi@1
  int v3; // ebx@2
  unsigned int v4; // ebp@3
  int v5; // edi@5
  int v6; // esi@5
  unsigned int v7; // ecx@6
  BlitArgs *v8; // edx@8
  int v9; // edi@8
  int v10; // esi@8
  int v11; // ecx@8
  signed int v12; // ebx@8
  int v13; // esi@8
  int v14; // edx@8
  int v15; // edi@8
  signed int v16; // esi@17
  int v17; // ebp@17
  signed int v18; // ebp@18
  int v19; // ecx@19
  int v20; // ecx@25
  int v21; // ebx@32
  int v22; // ebp@32
  signed int v23; // esi@32
  int v24; // edi@32
  int v25; // eax@32
  int v26; // ebx@47
  int v27; // ebp@47
  signed int v28; // esi@47
  int v29; // edi@47
  int v30; // eax@47
  __int64 v31; // rax@59
  bool v32; // zf@63
  int v33; // [sp+8h] [bp-50h]@0
  int v34; // [sp+Ch] [bp-4Ch]@0
  int v35; // [sp+10h] [bp-48h]@0
  int v36; // [sp+14h] [bp-44h]@0
  int v37; // [sp+18h] [bp-40h]@0
  int v38; // [sp+1Ch] [bp-3Ch]@0
  int v39; // [sp+20h] [bp-38h]@6
  int v40; // [sp+24h] [bp-34h]@6
  unsigned int v41; // [sp+28h] [bp-30h]@5
  char *pSrc; // [sp+2Ch] [bp-2Ch]@1
  char *pDst; // [sp+30h] [bp-28h]@1
  unsigned int v44; // [sp+34h] [bp-24h]@3
  unsigned int pixSrc; // [sp+38h] [bp-20h]@6
  int v46; // [sp+44h] [bp-14h]@5
  unsigned int idxX; // [sp+48h] [bp-10h]@3
  int iModifier; // [sp+4Ch] [bp-Ch]@2
  unsigned int v49; // [sp+50h] [bp-8h]@3
  unsigned int v50; // [sp+54h] [bp-4h]@3
  BlitArgs *i_argsa; // [sp+5Ch] [bp+4h]@8

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v4 = i_args->nWidth;
      idxX = i_args->nWidth;
      v49 = i_args->cSrcArgs.iStride;
      v50 = i_args->cDstArgs.iStride;
      v44 = i_args->nHeight;
      do
      {
        if ( v4 )
        {
          v5 = v2 - v1;
          v6 = (int)&v1[4 * v4];
          v46 = v5;
          v41 = v4;
          do
          {
            v7 = *(_DWORD *)(v5 + v6 - 4);
            v6 -= 4;
            v40 = v6;
            pixSrc = v7;
            v39 = 256;
            if ( v3 == 256 || (v39 = (v3 << 8) / 256) != 0 )
            {
              v8 = *(BlitArgs **)v6;
              v9 = (unsigned __int8)v7;
              v10 = BYTE1(v7);
              i_argsa = v8;
              v11 = ((unsigned __int8)(v7 >> 16) != 0) + (unsigned __int8)(v7 >> 16);
              v12 = v11;
              v13 = (v10 != 0) + v10;
              v14 = ((unsigned __int8)(pixSrc >> 16) != 0) + (unsigned __int8)(pixSrc >> 16);
              v15 = (v9 != 0) + v9;
              if ( v13 <= v11 )
              {
                if ( v13 < v11 )
                  v14 = v13;
              }
              else
              {
                v12 = v13;
              }
              if ( v15 <= v12 )
              {
                if ( v15 < v14 )
                  v14 = v15;
              }
              else
              {
                v12 = v15;
              }
              if ( v12 == v14 )
              {
                v16 = 0;
                v17 = 0;
              }
              else
              {
                v18 = 0;
                if ( v11 == v12 )
                {
                  v19 = v13 - v15;
                  if ( v13 - v15 < 0 )
                    v18 = 24576;
                }
                else if ( v13 == v12 )
                {
                  v19 = v15 - v11;
                  v18 = 0x2000;
                }
                else
                {
                  v19 = v11 - v13;
                  v18 = 0x4000;
                }
                v16 = v18 + (v19 << 12) / (v12 - v14);
                v17 = ((v12 - v14) << 8) / v12;
              }
              v20 = (BYTE2(i_argsa) != 0) + BYTE2(i_argsa);
              if ( (BYTE1(i_argsa) != 0) + BYTE1(i_argsa) > v20 )
                v20 = (BYTE1(i_argsa) != 0) + BYTE1(i_argsa);
              if ( ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa > v20 )
                v20 = ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa;
              if ( v39 == 256 )
              {
                if ( v17 )
                {
                  v21 = v16 / 4096;
                  v22 = v17 * v20 / 256;
                  v23 = v22 * (v16 - ((v16 / 4096 + 1) / 2 << 13));
                  v24 = v20 - v22;
                  v25 = v23 / 4096;
                  if ( v23 % 4096 < -2048 )
                    --v25;
                  if ( v23 % 4096 > 2048 )
                    ++v25;
                  switch ( v21 )
                  {
                    case 0:
                      v33 = v20 - v22;
                      v35 = v25 + v24;
                      goto LABEL_43;
                    case 1:
                      v33 = v20 - v22;
                      v35 = v20;
                      v34 = v24 - v25;
                      break;
                    case 2:
                      v34 = v20 - v22;
                      v35 = v20;
                      v33 = v25 + v24;
                      break;
                    case 3:
                      v34 = v20 - v22;
                      v33 = v20;
                      v35 = v24 - v25;
                      break;
                    case 4:
                      v35 = v20 - v22;
                      v33 = v20;
                      v34 = v25 + v24;
                      break;
                    case 5:
                      v35 = v20 - v22;
                      v33 = v24 - v25;
                      goto LABEL_43;
                    default:
                      break;
                  }
                }
                else
                {
                  v35 = v20;
                  v33 = v20;
LABEL_43:
                  v34 = v20;
                }
                v34 -= v34 != 0;
                BYTE2(i_argsa) = v34;
                v35 -= v35 != 0;
                BYTE1(i_argsa) = v35;
                v33 -= v33 != 0;
                LOBYTE(i_argsa) = v33;
              }
              else
              {
                if ( v17 )
                {
                  v26 = v16 / 4096;
                  v27 = v17 * v20 / 256;
                  v28 = v27 * (v16 - ((v16 / 4096 + 1) / 2 << 13));
                  v29 = v20 - v27;
                  v30 = v28 / 4096;
                  if ( v28 % 4096 < -2048 )
                    --v30;
                  if ( v28 % 4096 > 2048 )
                    ++v30;
                  switch ( v26 )
                  {
                    case 0:
                      v38 = v20 - v27;
                      v37 = v30 + v29;
                      goto LABEL_58;
                    case 1:
                      v38 = v20 - v27;
                      v37 = v20;
                      v36 = v29 - v30;
                      break;
                    case 2:
                      v36 = v20 - v27;
                      v37 = v20;
                      v38 = v30 + v29;
                      break;
                    case 3:
                      v36 = v20 - v27;
                      v38 = v20;
                      v37 = v29 - v30;
                      break;
                    case 4:
                      v37 = v20 - v27;
                      v38 = v20;
                      v36 = v30 + v29;
                      break;
                    case 5:
                      v37 = v20 - v27;
                      v38 = v29 - v30;
                      goto LABEL_58;
                    default:
                      break;
                  }
                }
                else
                {
                  v37 = v20;
                  v38 = v20;
LABEL_58:
                  v36 = v20;
                }
                v36 -= v36 != 0;
                v37 -= v37 != 0;
                BYTE2(i_argsa) -= v39 * (BYTE2(i_argsa) - v36) / 256;
                BYTE1(i_argsa) -= v39 * (BYTE1(i_argsa) - v37) / 256;
                v31 = v39 * ((unsigned __int8)i_argsa - (v38 - (v38 != 0)));
                v38 -= v38 != 0;
                LOBYTE(i_argsa) = (_BYTE)i_argsa - ((unsigned __int16)(BYTE4(v31) + (_WORD)v31) >> 8);
              }
              v5 = v46;
              v4 = idxX;
              v3 = iModifier;
              *(_DWORD *)v40 = i_argsa;
              v6 = v40;
            }
            --v41;
          }
          while ( v41 );
          v1 = pDst;
        }
        v2 = &pSrc[v49];
        v1 += v50;
        v32 = v44 == 1;
        pSrc += v49;
        pDst = v1;
        --v44;
      }
      while ( !v32 );
    }
    _m_femms();
  }
}

//----- (00661E20) --------------------------------------------------------  // acclient.c:632492
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  unsigned int v5; // ecx@6
  unsigned __int8 v6; // dl@8
  int v7; // edi@8
  unsigned __int8 v8; // al@8
  int v9; // esi@8
  int v10; // ecx@8
  signed int v11; // ebp@8
  int v12; // esi@8
  int v13; // edi@8
  int v14; // edx@8
  signed int v15; // esi@17
  int v16; // ebp@17
  signed int v17; // ebx@18
  int v18; // ecx@19
  int v19; // ecx@25
  int v20; // ebx@32
  int v21; // ebp@32
  signed int v22; // esi@32
  int v23; // edi@32
  int v24; // eax@32
  char v25; // cl@44
  int v26; // ebx@44
  char v27; // al@44
  char v28; // bl@44
  int v29; // ebx@47
  int v30; // ebp@47
  signed int v31; // esi@47
  int v32; // edi@47
  int v33; // eax@47
  int v34; // edx@59
  bool v35; // zf@62
  int v36; // [sp+4h] [bp-4Ch]@0
  int v37; // [sp+8h] [bp-48h]@0
  int v38; // [sp+Ch] [bp-44h]@0
  int v39; // [sp+10h] [bp-40h]@0
  int v40; // [sp+14h] [bp-3Ch]@0
  unsigned __int8 v41; // [sp+18h] [bp-38h]@8
  unsigned __int8 v42; // [sp+19h] [bp-37h]@8
  unsigned __int8 v43; // [sp+1Ah] [bp-36h]@8
  int v44; // [sp+1Ch] [bp-34h]@6
  char *pSrc; // [sp+20h] [bp-30h]@1
  unsigned int pixSrc; // [sp+24h] [bp-2Ch]@6
  signed int pixSrca; // [sp+24h] [bp-2Ch]@16
  int v48; // [sp+28h] [bp-28h]@6
  char *pDst; // [sp+2Ch] [bp-24h]@1
  unsigned int v50; // [sp+30h] [bp-20h]@3
  unsigned int v51; // [sp+34h] [bp-1Ch]@3
  int iModifier; // [sp+40h] [bp-10h]@2
  unsigned int idxX; // [sp+44h] [bp-Ch]@6
  unsigned int v54; // [sp+48h] [bp-8h]@3
  unsigned int v55; // [sp+4Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v51 = i_args->nWidth;
      v54 = i_args->cSrcArgs.iStride;
      v55 = i_args->cDstArgs.iStride;
      v50 = i_args->nHeight;
      do
      {
        v3 = v51;
        if ( v51 )
        {
          v4 = (int)(&v1[2 * v51 + 2] + v51);
          do
          {
            v5 = *(_DWORD *)&pSrc[4 * v3-- - 4];
            v4 -= 3;
            idxX = v3;
            v48 = v4;
            pixSrc = v5;
            v44 = 256;
            if ( v2 != 256 )
            {
              v44 = (v2 << 8) / 256;
              if ( !v44 )
                continue;
            }
            v6 = *(_BYTE *)(v4 - 1);
            v7 = (unsigned __int8)v5;
            v41 = *(_BYTE *)(v4 - 2);
            v8 = *(_BYTE *)v4;
            v9 = BYTE1(v5);
            v42 = v6;
            v43 = v8;
            v10 = ((unsigned __int8)(v5 >> 16) != 0) + (unsigned __int8)(v5 >> 16);
            v11 = v10;
            v12 = (v9 != 0) + v9;
            v13 = (v7 != 0) + v7;
            v14 = ((unsigned __int8)(pixSrc >> 16) != 0) + (unsigned __int8)(pixSrc >> 16);
            if ( v12 <= v10 )
            {
              if ( v12 < v10 )
                v14 = v12;
            }
            else
            {
              v11 = v12;
            }
            if ( v13 <= v11 )
            {
              if ( v13 < v14 )
                v14 = v13;
            }
            else
            {
              v11 = v13;
            }
            pixSrca = v11 - v14;
            if ( v11 == v14 )
            {
              v15 = 0;
              v16 = 0;
            }
            else
            {
              v17 = 0;
              if ( v10 == v11 )
              {
                v18 = v12 - v13;
                if ( v12 - v13 < 0 )
                  v17 = 24576;
              }
              else if ( v12 == v11 )
              {
                v18 = v13 - v10;
                v17 = 0x2000;
              }
              else
              {
                v18 = v10 - v12;
                v17 = 0x4000;
              }
              v16 = ((v11 - v14) << 8) / v11;
              v15 = v17 + (v18 << 12) / pixSrca;
            }
            v19 = (v8 != 0) + v8;
            if ( (v42 != 0) + v42 > v19 )
              v19 = (v42 != 0) + v42;
            if ( (v41 != 0) + v41 > v19 )
              v19 = (v41 != 0) + v41;
            if ( v44 == 256 )
            {
              if ( v16 )
              {
                v20 = v15 / 4096;
                v21 = v16 * v19 / 256;
                v22 = v21 * (v15 - ((v15 / 4096 + 1) / 2 << 13));
                v23 = v19 - v21;
                v24 = v22 / 4096;
                if ( v22 % 4096 < -2048 )
                  --v24;
                if ( v22 % 4096 > 2048 )
                  ++v24;
                switch ( v20 )
                {
                  case 0:
                    i_args = (BlitArgs *)(v19 - v21);
                    v37 = v24 + v23;
                    goto LABEL_43;
                  case 1:
                    i_args = (BlitArgs *)(v19 - v21);
                    v37 = v19;
                    v36 = v23 - v24;
                    break;
                  case 2:
                    v36 = v19 - v21;
                    v37 = v19;
                    i_args = (BlitArgs *)(v24 + v23);
                    break;
                  case 3:
                    v36 = v19 - v21;
                    i_args = (BlitArgs *)v19;
                    v37 = v23 - v24;
                    break;
                  case 4:
                    v37 = v19 - v21;
                    i_args = (BlitArgs *)v19;
                    v36 = v24 + v23;
                    break;
                  case 5:
                    v37 = v19 - v21;
                    i_args = (BlitArgs *)(v23 - v24);
                    goto LABEL_43;
                  default:
                    break;
                }
              }
              else
              {
                v37 = v19;
                i_args = (BlitArgs *)v19;
LABEL_43:
                v36 = v19;
              }
              v25 = v36 - (v36 != 0);
              v36 -= v36 != 0;
              v26 = i_args != 0;
              v37 -= v37 != 0;
              v27 = (_BYTE)i_args - v26;
              i_args = (BlitArgs *)((char *)i_args - v26);
              v28 = v37;
            }
            else
            {
              if ( v16 )
              {
                v29 = v15 / 4096;
                v30 = v16 * v19 / 256;
                v31 = v30 * (v15 - ((v15 / 4096 + 1) / 2 << 13));
                v32 = v19 - v30;
                v33 = v31 / 4096;
                if ( v31 % 4096 < -2048 )
                  --v33;
                if ( v31 % 4096 > 2048 )
                  ++v33;
                switch ( v29 )
                {
                  case 0:
                    v40 = v19 - v30;
                    v39 = v33 + v32;
                    goto LABEL_58;
                  case 1:
                    v40 = v19 - v30;
                    v39 = v19;
                    v38 = v32 - v33;
                    break;
                  case 2:
                    v38 = v19 - v30;
                    v39 = v19;
                    v40 = v33 + v32;
                    break;
                  case 3:
                    v38 = v19 - v30;
                    v40 = v19;
                    v39 = v32 - v33;
                    break;
                  case 4:
                    v39 = v19 - v30;
                    v40 = v19;
                    v38 = v33 + v32;
                    break;
                  case 5:
                    v39 = v19 - v30;
                    v40 = v32 - v33;
                    goto LABEL_58;
                  default:
                    break;
                }
              }
              else
              {
                v39 = v19;
                v40 = v19;
LABEL_58:
                v38 = v19;
              }
              v38 -= v38 != 0;
              v39 -= v39 != 0;
              v25 = v43 - v44 * (v43 - v38) / 256;
              v28 = v42 - v44 * (v42 - v39) / 256;
              v34 = v44 * (v41 - (v40 - (v40 != 0))) / 256;
              v40 -= v40 != 0;
              v27 = v41 - v34;
            }
            v4 = v48;
            v3 = idxX;
            *(_BYTE *)(v48 - 1) = v28;
            v2 = iModifier;
            *(_BYTE *)(v48 - 2) = v27;
            *(_BYTE *)v48 = v25;
          }
          while ( v3 );
        }
        pSrc += v54;
        v1 = &pDst[v55];
        v35 = v50 == 1;
        pDst += v55;
        --v50;
      }
      while ( !v35 );
    }
    _m_femms();
  }
}

//----- (006622D0) --------------------------------------------------------  // acclient.c:632792
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // edi@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned __int8 v5; // dl@6
  unsigned __int8 v6; // al@6
  unsigned __int8 v7; // bl@6
  int v8; // edi@8
  int v9; // ecx@8
  signed int v10; // ebx@8
  int v11; // esi@8
  int v12; // edx@8
  int v13; // edi@8
  signed int v14; // esi@17
  int v15; // ebp@17
  signed int v16; // ebp@18
  int v17; // ecx@19
  int v18; // ecx@25
  int v19; // ebx@32
  int v20; // ebp@32
  signed int v21; // esi@32
  int v22; // edi@32
  int v23; // eax@32
  int v24; // ebx@47
  int v25; // ebp@47
  signed int v26; // esi@47
  int v27; // edi@47
  int v28; // eax@47
  __int64 v29; // rax@59
  bool v30; // zf@62
  int v31; // [sp+4h] [bp-50h]@0
  int v32; // [sp+8h] [bp-4Ch]@0
  int v33; // [sp+Ch] [bp-48h]@0
  int v34; // [sp+10h] [bp-44h]@0
  int v35; // [sp+14h] [bp-40h]@0
  int v36; // [sp+18h] [bp-3Ch]@0
  int v37; // [sp+1Ch] [bp-38h]@6
  char *pDst; // [sp+20h] [bp-34h]@1
  unsigned __int8 pixSrc_1; // [sp+25h] [bp-2Fh]@6
  unsigned int idxX; // [sp+28h] [bp-2Ch]@6
  char *pSrc; // [sp+2Ch] [bp-28h]@1
  unsigned int v42; // [sp+30h] [bp-24h]@3
  unsigned int v43; // [sp+34h] [bp-20h]@3
  int v44; // [sp+44h] [bp-10h]@6
  int iModifier; // [sp+48h] [bp-Ch]@2
  unsigned int v46; // [sp+4Ch] [bp-8h]@3
  unsigned int v47; // [sp+50h] [bp-4h]@3
  BlitArgs *i_argsa; // [sp+58h] [bp+4h]@8

  v1 = i_args->cSrcArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v43 = i_args->nWidth;
      v46 = i_args->cSrcArgs.iStride;
      v47 = i_args->cDstArgs.iStride;
      v42 = i_args->nHeight;
      do
      {
        v3 = v43;
        if ( v43 )
        {
          v4 = (int)(&v1[2 * v43 + 2] + v43);
          do
          {
            v5 = *(_BYTE *)(v4 - 4);
            v6 = *(_BYTE *)(v4 - 3);
            v7 = *(_BYTE *)(v4 - 5);
            v4 -= 3;
            --v3;
            idxX = v3;
            v44 = v4;
            pixSrc_1 = v5;
            v37 = 256;
            if ( v2 != 256 )
            {
              v37 = (v2 << 8) / 256;
              if ( !v37 )
                continue;
            }
            i_argsa = *(BlitArgs **)&pDst[4 * v3];
            v8 = v7;
            v9 = (v6 != 0) + v6;
            v10 = v9;
            v11 = (v5 != 0) + v5;
            v12 = (v6 != 0) + v6;
            v13 = (v8 != 0) + v8;
            if ( v11 <= v9 )
            {
              if ( v11 < v9 )
                v12 = (pixSrc_1 != 0) + pixSrc_1;
            }
            else
            {
              v10 = (pixSrc_1 != 0) + pixSrc_1;
            }
            if ( v13 <= v10 )
            {
              if ( v13 < v12 )
                v12 = v13;
            }
            else
            {
              v10 = v13;
            }
            if ( v10 == v12 )
            {
              v14 = 0;
              v15 = 0;
            }
            else
            {
              v16 = 0;
              if ( v9 == v10 )
              {
                v17 = v11 - v13;
                if ( v11 - v13 < 0 )
                  v16 = 24576;
              }
              else if ( v11 == v10 )
              {
                v17 = v13 - v9;
                v16 = 0x2000;
              }
              else
              {
                v17 = v9 - v11;
                v16 = 0x4000;
              }
              v14 = v16 + (v17 << 12) / (v10 - v12);
              v15 = ((v10 - v12) << 8) / v10;
            }
            v18 = (BYTE2(i_argsa) != 0) + BYTE2(i_argsa);
            if ( (BYTE1(i_argsa) != 0) + BYTE1(i_argsa) > v18 )
              v18 = (BYTE1(i_argsa) != 0) + BYTE1(i_argsa);
            if ( ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa > v18 )
              v18 = ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa;
            if ( v37 == 256 )
            {
              if ( v15 )
              {
                v19 = v14 / 4096;
                v20 = v15 * v18 / 256;
                v21 = v20 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                v22 = v18 - v20;
                v23 = v21 / 4096;
                if ( v21 % 4096 < -2048 )
                  --v23;
                if ( v21 % 4096 > 2048 )
                  ++v23;
                switch ( v19 )
                {
                  case 0:
                    v31 = v18 - v20;
                    v33 = v23 + v22;
                    goto LABEL_43;
                  case 1:
                    v31 = v18 - v20;
                    v33 = v18;
                    v32 = v22 - v23;
                    break;
                  case 2:
                    v32 = v18 - v20;
                    v33 = v18;
                    v31 = v23 + v22;
                    break;
                  case 3:
                    v32 = v18 - v20;
                    v31 = v18;
                    v33 = v22 - v23;
                    break;
                  case 4:
                    v33 = v18 - v20;
                    v31 = v18;
                    v32 = v23 + v22;
                    break;
                  case 5:
                    v33 = v18 - v20;
                    v31 = v22 - v23;
                    goto LABEL_43;
                  default:
                    break;
                }
              }
              else
              {
                v33 = v18;
                v31 = v18;
LABEL_43:
                v32 = v18;
              }
              v32 -= v32 != 0;
              BYTE2(i_argsa) = v32;
              v33 -= v33 != 0;
              BYTE1(i_argsa) = v33;
              v31 -= v31 != 0;
              LOBYTE(i_argsa) = v31;
            }
            else
            {
              if ( v15 )
              {
                v24 = v14 / 4096;
                v25 = v15 * v18 / 256;
                v26 = v25 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                v27 = v18 - v25;
                v28 = v26 / 4096;
                if ( v26 % 4096 < -2048 )
                  --v28;
                if ( v26 % 4096 > 2048 )
                  ++v28;
                switch ( v24 )
                {
                  case 0:
                    v36 = v18 - v25;
                    v35 = v28 + v27;
                    goto LABEL_58;
                  case 1:
                    v36 = v18 - v25;
                    v35 = v18;
                    v34 = v27 - v28;
                    break;
                  case 2:
                    v34 = v18 - v25;
                    v35 = v18;
                    v36 = v28 + v27;
                    break;
                  case 3:
                    v34 = v18 - v25;
                    v36 = v18;
                    v35 = v27 - v28;
                    break;
                  case 4:
                    v35 = v18 - v25;
                    v36 = v18;
                    v34 = v28 + v27;
                    break;
                  case 5:
                    v35 = v18 - v25;
                    v36 = v27 - v28;
                    goto LABEL_58;
                  default:
                    break;
                }
              }
              else
              {
                v35 = v18;
                v36 = v18;
LABEL_58:
                v34 = v18;
              }
              v34 -= v34 != 0;
              v35 -= v35 != 0;
              BYTE2(i_argsa) -= v37 * (BYTE2(i_argsa) - v34) / 256;
              BYTE1(i_argsa) -= v37 * (BYTE1(i_argsa) - v35) / 256;
              v29 = v37 * ((unsigned __int8)i_argsa - (v36 - (v36 != 0)));
              v36 -= v36 != 0;
              LOBYTE(i_argsa) = (_BYTE)i_argsa - ((unsigned __int16)(BYTE4(v29) + (_WORD)v29) >> 8);
            }
            v2 = iModifier;
            *(_DWORD *)&pDst[4 * idxX] = i_argsa;
            v4 = v44;
            v3 = idxX;
          }
          while ( v3 );
        }
        v1 = &pSrc[v46];
        v30 = v42 == 1;
        pSrc += v46;
        pDst += v47;
        --v42;
      }
      while ( !v30 );
    }
    _m_femms();
  }
}

//----- (00662790) --------------------------------------------------------  // acclient.c:633079
void __cdecl BlitLoopNoScale__BlitOp_Colorize_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // esi@1
  int v3; // ebp@2
  unsigned int v4; // eax@3
  int v5; // edi@5
  int v6; // esi@5
  int v7; // ecx@5
  unsigned __int8 v8; // dl@6
  unsigned __int8 v9; // al@6
  unsigned __int8 v10; // bl@6
  int v11; // ecx@8
  int v12; // eax@8
  signed int v13; // ebp@8
  int v14; // esi@8
  int v15; // edi@8
  int v16; // edx@8
  signed int v17; // esi@17
  int v18; // ebp@17
  signed int v19; // ebx@18
  int v20; // ecx@19
  int v21; // ecx@25
  int v22; // ebx@32
  int v23; // ebp@32
  signed int v24; // esi@32
  int v25; // edi@32
  int v26; // eax@32
  char v27; // cl@44
  int v28; // ebx@44
  char v29; // al@44
  char v30; // bl@44
  int v31; // ebx@47
  int v32; // ebp@47
  signed int v33; // esi@47
  int v34; // edi@47
  int v35; // eax@47
  int v36; // edx@59
  bool v37; // zf@63
  int v38; // [sp+8h] [bp-58h]@0
  int v39; // [sp+Ch] [bp-54h]@0
  int v40; // [sp+10h] [bp-50h]@0
  int v41; // [sp+14h] [bp-4Ch]@0
  int v42; // [sp+18h] [bp-48h]@0
  unsigned __int8 v43; // [sp+1Ch] [bp-44h]@8
  unsigned __int8 v44; // [sp+1Dh] [bp-43h]@8
  unsigned __int8 v45; // [sp+1Eh] [bp-42h]@8
  int v46; // [sp+20h] [bp-40h]@6
  unsigned __int8 pixSrc_1; // [sp+25h] [bp-3Bh]@6
  unsigned __int8 pixSrc_2; // [sp+26h] [bp-3Ah]@6
  signed int v49; // [sp+28h] [bp-38h]@16
  int v50; // [sp+2Ch] [bp-34h]@6
  unsigned int v51; // [sp+30h] [bp-30h]@5
  char *pSrc; // [sp+34h] [bp-2Ch]@1
  char *pDst; // [sp+38h] [bp-28h]@1
  unsigned int v54; // [sp+3Ch] [bp-24h]@3
  int iModifier; // [sp+48h] [bp-18h]@2
  int v56; // [sp+4Ch] [bp-14h]@6
  int v57; // [sp+50h] [bp-10h]@5
  unsigned int idxX; // [sp+54h] [bp-Ch]@3
  unsigned int v59; // [sp+58h] [bp-8h]@3
  unsigned int v60; // [sp+5Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    iModifier = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v4 = i_args->nWidth;
      idxX = i_args->nWidth;
      v59 = i_args->cSrcArgs.iStride;
      v60 = i_args->cDstArgs.iStride;
      v54 = i_args->nHeight;
      do
      {
        if ( v4 )
        {
          v5 = (int)&v2[3 * v4];
          v6 = v2 - v1;
          v7 = (int)&v1[3 * v4 + 2];
          v57 = v6;
          v51 = v4;
          do
          {
            v8 = *(_BYTE *)(v6 + v7 - 4);
            v9 = *(_BYTE *)(v6 + v7 - 3);
            v10 = *(_BYTE *)(v5 - 3);
            v7 -= 3;
            v5 -= 3;
            v56 = v5;
            v50 = v7;
            pixSrc_1 = v8;
            pixSrc_2 = v9;
            v46 = 256;
            if ( v3 == 256 || (v46 = (v3 << 8) / 256) != 0 )
            {
              v43 = *(_BYTE *)(v7 - 2);
              v45 = *(_BYTE *)v7;
              v44 = *(_BYTE *)(v7 - 1);
              v11 = (v9 != 0) + v9;
              v12 = v8 != 0;
              v13 = v11;
              v14 = v12 + v8;
              v15 = (v10 != 0) + v10;
              v16 = (pixSrc_2 != 0) + pixSrc_2;
              if ( v14 <= v11 )
              {
                if ( v14 < v11 )
                  v16 = v12 + pixSrc_1;
              }
              else
              {
                v13 = v12 + pixSrc_1;
              }
              if ( v15 <= v13 )
              {
                if ( v15 < v16 )
                  v16 = (v10 != 0) + v10;
              }
              else
              {
                v13 = (v10 != 0) + v10;
              }
              v49 = v13 - v16;
              if ( v13 == v16 )
              {
                v17 = 0;
                v18 = 0;
              }
              else
              {
                v19 = 0;
                if ( v11 == v13 )
                {
                  v20 = v14 - v15;
                  if ( v14 - v15 < 0 )
                    v19 = 24576;
                }
                else if ( v14 == v13 )
                {
                  v20 = v15 - v11;
                  v19 = 0x2000;
                }
                else
                {
                  v20 = v11 - v14;
                  v19 = 0x4000;
                }
                v18 = ((v13 - v16) << 8) / v13;
                v17 = v19 + (v20 << 12) / v49;
              }
              v21 = (v45 != 0) + v45;
              if ( (v44 != 0) + v44 > v21 )
                v21 = (v44 != 0) + v44;
              if ( (v43 != 0) + v43 > v21 )
                v21 = (v43 != 0) + v43;
              if ( v46 == 256 )
              {
                if ( v18 )
                {
                  v22 = v17 / 4096;
                  v23 = v18 * v21 / 256;
                  v24 = v23 * (v17 - ((v17 / 4096 + 1) / 2 << 13));
                  v25 = v21 - v23;
                  v26 = v24 / 4096;
                  if ( v24 % 4096 < -2048 )
                    --v26;
                  if ( v24 % 4096 > 2048 )
                    ++v26;
                  switch ( v22 )
                  {
                    case 0:
                      i_args = (BlitArgs *)(v21 - v23);
                      v39 = v26 + v25;
                      goto LABEL_43;
                    case 1:
                      i_args = (BlitArgs *)(v21 - v23);
                      v39 = v21;
                      v38 = v25 - v26;
                      break;
                    case 2:
                      v38 = v21 - v23;
                      v39 = v21;
                      i_args = (BlitArgs *)(v26 + v25);
                      break;
                    case 3:
                      v38 = v21 - v23;
                      i_args = (BlitArgs *)v21;
                      v39 = v25 - v26;
                      break;
                    case 4:
                      v39 = v21 - v23;
                      i_args = (BlitArgs *)v21;
                      v38 = v26 + v25;
                      break;
                    case 5:
                      v39 = v21 - v23;
                      i_args = (BlitArgs *)(v25 - v26);
                      goto LABEL_43;
                    default:
                      break;
                  }
                }
                else
                {
                  v39 = v21;
                  i_args = (BlitArgs *)v21;
LABEL_43:
                  v38 = v21;
                }
                v27 = v38 - (v38 != 0);
                v38 -= v38 != 0;
                v28 = i_args != 0;
                v39 -= v39 != 0;
                v29 = (_BYTE)i_args - v28;
                i_args = (BlitArgs *)((char *)i_args - v28);
                v30 = v39;
              }
              else
              {
                if ( v18 )
                {
                  v31 = v17 / 4096;
                  v32 = v18 * v21 / 256;
                  v33 = v32 * (v17 - ((v17 / 4096 + 1) / 2 << 13));
                  v34 = v21 - v32;
                  v35 = v33 / 4096;
                  if ( v33 % 4096 < -2048 )
                    --v35;
                  if ( v33 % 4096 > 2048 )
                    ++v35;
                  switch ( v31 )
                  {
                    case 0:
                      v42 = v21 - v32;
                      v41 = v35 + v34;
                      goto LABEL_58;
                    case 1:
                      v42 = v21 - v32;
                      v41 = v21;
                      v40 = v34 - v35;
                      break;
                    case 2:
                      v40 = v21 - v32;
                      v41 = v21;
                      v42 = v35 + v34;
                      break;
                    case 3:
                      v40 = v21 - v32;
                      v42 = v21;
                      v41 = v34 - v35;
                      break;
                    case 4:
                      v41 = v21 - v32;
                      v42 = v21;
                      v40 = v35 + v34;
                      break;
                    case 5:
                      v41 = v21 - v32;
                      v42 = v34 - v35;
                      goto LABEL_58;
                    default:
                      break;
                  }
                }
                else
                {
                  v41 = v21;
                  v42 = v21;
LABEL_58:
                  v40 = v21;
                }
                v40 -= v40 != 0;
                v41 -= v41 != 0;
                v27 = v45 - v46 * (v45 - v40) / 256;
                v30 = v44 - v46 * (v44 - v41) / 256;
                v36 = v46 * (v43 - (v42 - (v42 != 0))) / 256;
                v42 -= v42 != 0;
                v29 = v43 - v36;
              }
              v3 = iModifier;
              v5 = v56;
              *(_BYTE *)v50 = v27;
              *(_BYTE *)(v50 - 2) = v29;
              *(_BYTE *)(v50 - 1) = v30;
              v7 = v50;
              v6 = v57;
            }
            --v51;
          }
          while ( v51 );
          v1 = pDst;
          v4 = idxX;
          v2 = pSrc;
        }
        v2 += v59;
        v1 += v60;
        v37 = v54 == 1;
        pSrc = v2;
        pDst = v1;
        --v54;
      }
      while ( !v37 );
    }
    _m_femms();
  }
}

//----- (00662C60) --------------------------------------------------------  // acclient.c:633393
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  unsigned int *v4; // ecx@5
  unsigned int v5; // esi@6
  int v6; // eax@6
  __m64 v7; // mm3@9
  __m64 v8; // mm0@9
  __m64 v9; // mm1@9
  __m64 v10; // mm1@9
  __m64 v11; // mm0@10
  __m64 v12; // mm3@11
  __m64 v13; // mm4@11
  __m64 v14; // mm3@11
  bool v15; // zf@15
  char *v16; // [sp+10h] [bp-20h]@1
  unsigned int v17; // [sp+14h] [bp-1Ch]@5
  char *v18; // [sp+18h] [bp-18h]@1
  unsigned int v19; // [sp+1Ch] [bp-14h]@3
  unsigned int v20; // [sp+24h] [bp-Ch]@3
  unsigned int v21; // [sp+28h] [bp-8h]@3
  unsigned int v22; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v16 = i_args->cSrcArgs.pDstBuf;
  v18 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v20 = i_args->nWidth;
      v21 = i_args->cSrcArgs.iStride;
      v22 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v17 = v3;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v16 - v1 - 4);
            --v4;
            v6 = (v5 >> 24 != 0) + (v5 >> 24);
            if ( v2 != 256 )
              v6 = v2 * v6 / 256;
            if ( v6 )
            {
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
              v10 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u), v7),
                      _m_pandn(v7, v8));
              if ( v6 == 256 )
              {
                v11 = v10;
              }
              else
              {
                v12 = _mm_cvtsi32_si64(v6);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v11 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v14), 8u), _m_psrlw(_m_pmullw(v10, v14), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v11, 0i64));
            }
            --v17;
          }
          while ( v17 );
          v1 = v18;
          v3 = v20;
        }
        v1 += v22;
        v15 = v19 == 1;
        v16 += v21;
        v18 = v1;
        --v19;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (00662DC0) --------------------------------------------------------  // acclient.c:633484
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // edi@6
  int v6; // eax@6
  unsigned int v7; // ST10_4@9
  __m64 v8; // mm3@9
  __m64 v9; // mm0@9
  __m64 v10; // mm1@9
  __m64 v11; // mm1@9
  __m64 v12; // mm0@10
  __m64 v13; // mm3@11
  __m64 v14; // mm4@11
  __m64 v15; // mm3@11
  unsigned int v16; // ST10_4@12
  bool v17; // zf@14
  char *v18; // [sp+14h] [bp-1Ch]@1
  char *v19; // [sp+18h] [bp-18h]@1
  unsigned int v20; // [sp+1Ch] [bp-14h]@3
  unsigned int v21; // [sp+20h] [bp-10h]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v18 = i_args->cSrcArgs.pDstBuf;
  v19 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        v3 = v21;
        if ( v21 )
        {
          v4 = (int)(&v1[2 * v21 + 2] + v21);
          do
          {
            v5 = *(_DWORD *)&v18[4 * v3-- - 4];
            v4 -= 3;
            v6 = (v5 >> 24 != 0) + (v5 >> 24);
            if ( v2 != 256 )
              v6 = v2 * v6 / 256;
            if ( v6 )
            {
              LOBYTE(v7) = *(_BYTE *)(v4 - 2);
              BYTE1(v7) = *(_BYTE *)(v4 - 1);
              BYTE2(v7) = *(_BYTE *)v4;
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v7) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
              v11 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v10, _m_pcmpgtw(v10, 0i64)), v9), 8u), v8),
                      _m_pandn(v8, v9));
              if ( v6 == 256 )
              {
                v12 = v11;
              }
              else
              {
                v13 = _mm_cvtsi32_si64(v6);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                v12 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v15), 8u), _m_psrlw(_m_pmullw(v11, v15), 8u)));
              }
              v16 = _mm_cvtsi64_si32(_m_packuswb(v12, 0i64));
              *(_BYTE *)(v4 - 2) = v16;
              *(_BYTE *)(v4 - 1) = BYTE1(v16);
              *(_BYTE *)v4 = v16 >> 16;
            }
          }
          while ( v3 );
        }
        v18 += v22;
        v1 = &v19[v23];
        v17 = v20 == 1;
        v19 += v23;
        --v20;
      }
      while ( !v17 );
    }
    _m_femms();
  }
}

//----- (00662F50) --------------------------------------------------------  // acclient.c:633579
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ebx@1
  int v2; // edi@2
  unsigned int v3; // edx@3
  unsigned int *v4; // ecx@5
  unsigned int v5; // edx@6
  int v6; // eax@6
  __m64 v7; // mm3@8
  __m64 v8; // mm0@8
  __m64 v9; // mm1@8
  __m64 v10; // mm1@8
  __m64 v11; // mm0@9
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@14
  char *v16; // [sp+Ch] [bp-1Ch]@1
  unsigned int v17; // [sp+10h] [bp-18h]@6
  unsigned int v18; // [sp+14h] [bp-14h]@5
  unsigned int v19; // [sp+18h] [bp-10h]@3
  unsigned int v20; // [sp+1Ch] [bp-Ch]@3
  unsigned int v21; // [sp+20h] [bp-8h]@3
  unsigned int v22; // [sp+24h] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v16 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v20 = i_args->nWidth;
      v21 = i_args->cSrcArgs.iStride;
      v22 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v18 = v3;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v16 - v1 - 4);
            --v4;
            v6 = 256;
            v17 = v5;
            BYTE3(v17) = -1;
            if ( v2 == 256 || (v6 = (v2 << 8) / 256) != 0 )
            {
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v17), 0i64);
              v10 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u), v7),
                      _m_pandn(v7, v8));
              if ( v6 == 256 )
              {
                v11 = v10;
              }
              else
              {
                v12 = _mm_cvtsi32_si64(v6);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v11 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v14), 8u), _m_psrlw(_m_pmullw(v10, v14), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v11, 0i64));
            }
            --v18;
          }
          while ( v18 );
          v3 = v20;
        }
        v1 += v22;
        v15 = v19 == 1;
        v16 += v21;
        --v19;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (006630A0) --------------------------------------------------------  // acclient.c:633667
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  unsigned int v6; // edx@6
  int v7; // eax@6
  unsigned int v8; // ST0C_4@8
  __m64 v9; // mm3@8
  __m64 v10; // mm0@8
  __m64 v11; // mm1@8
  __m64 v12; // mm1@8
  __m64 v13; // mm0@9
  __m64 v14; // mm3@10
  __m64 v15; // mm4@10
  __m64 v16; // mm3@10
  unsigned int v17; // ST0C_4@11
  bool v18; // zf@13
  unsigned int v19; // [sp+10h] [bp-18h]@6
  char *v20; // [sp+14h] [bp-14h]@1
  unsigned int v21; // [sp+18h] [bp-10h]@3
  unsigned int v22; // [sp+1Ch] [bp-Ch]@3
  unsigned int v23; // [sp+20h] [bp-8h]@3
  unsigned int v24; // [sp+24h] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  v20 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v22 = i_args->nWidth;
      v23 = i_args->cSrcArgs.iStride;
      v24 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        v4 = v22;
        if ( v22 )
        {
          v5 = (int)(&v1[2 * v22 + 2] + v22);
          do
          {
            v6 = *(_DWORD *)&v2[4 * v4-- - 4];
            v7 = 256;
            v5 -= 3;
            v19 = v6;
            BYTE3(v19) = -1;
            if ( v3 != 256 )
            {
              v7 = (v3 << 8) / 256;
              if ( !v7 )
                continue;
            }
            LOBYTE(v8) = *(_BYTE *)(v5 - 2);
            BYTE1(v8) = *(_BYTE *)(v5 - 1);
            BYTE2(v8) = *(_BYTE *)v5;
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            BYTE3(v8) = -1;
            v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
            v11 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
            v12 = _m_por(
                    _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u), v9),
                    _m_pandn(v9, v10));
            if ( v7 == 256 )
            {
              v13 = v12;
            }
            else
            {
              v14 = _mm_cvtsi32_si64(v7);
              v15 = _m_punpcklwd(v14, v14);
              v16 = _m_punpcklwd(v15, v15);
              v13 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
            }
            v17 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
            *(_BYTE *)(v5 - 2) = v17;
            *(_BYTE *)(v5 - 1) = BYTE1(v17);
            *(_BYTE *)v5 = v17 >> 16;
          }
          while ( v4 );
        }
        v2 += v23;
        v1 = &v20[v24];
        v18 = v21 == 1;
        v20 += v24;
        --v21;
      }
      while ( !v18 );
    }
    _m_femms();
  }
}

//----- (00663220) --------------------------------------------------------  // acclient.c:633766
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // ecx@4
  int v5; // esi@5
  char v6; // al@6
  char v7; // dl@6
  int v8; // eax@6
  __m64 v9; // mm3@8
  __m64 v10; // mm0@8
  __m64 v11; // mm1@8
  __m64 v12; // mm1@8
  __m64 v13; // mm0@9
  __m64 v14; // mm3@10
  __m64 v15; // mm4@10
  __m64 v16; // mm3@10
  bool v17; // zf@13
  unsigned int v18; // [sp+10h] [bp-18h]@5
  char *v19; // [sp+14h] [bp-14h]@1
  unsigned int v20; // [sp+18h] [bp-10h]@3
  unsigned int v21; // [sp+1Ch] [bp-Ch]@3
  unsigned int v22; // [sp+20h] [bp-8h]@3
  unsigned int v23; // [sp+24h] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  v19 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        v4 = v21;
        if ( v21 )
        {
          BYTE3(v18) = -1;
          v5 = (int)(&v1[2 * v21 + 2] + v21);
          do
          {
            v6 = *(_BYTE *)(v5 - 5);
            v7 = *(_BYTE *)(v5 - 4);
            v5 -= 3;
            LOBYTE(v18) = v6;
            BYTE2(v18) = *(_BYTE *)v5;
            v8 = 256;
            --v4;
            BYTE1(v18) = v7;
            if ( v3 != 256 )
            {
              v8 = (v3 << 8) / 256;
              if ( !v8 )
                continue;
            }
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v10 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v2[4 * v4]), 0i64);
            v11 = _m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64);
            v12 = _m_por(
                    _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u), v9),
                    _m_pandn(v9, v10));
            if ( v8 == 256 )
            {
              v13 = v12;
            }
            else
            {
              v14 = _mm_cvtsi32_si64(v8);
              v15 = _m_punpcklwd(v14, v14);
              v16 = _m_punpcklwd(v15, v15);
              v13 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
            }
            *(_DWORD *)&v2[4 * v4] = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
          }
          while ( v4 );
        }
        v1 = &v19[v22];
        v2 += v23;
        v17 = v20 == 1;
        v19 += v22;
        --v20;
      }
      while ( !v17 );
    }
    _m_femms();
  }
}

//----- (00663380) --------------------------------------------------------  // acclient.c:633861
void __cdecl BlitLoopNoScale__BlitOp_Multiply_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  int v2; // ebx@2
  unsigned int v3; // edx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // esi@5
  char v7; // al@6
  char v8; // dl@6
  int v9; // eax@6
  unsigned int v10; // ST0C_4@8
  __m64 v11; // mm3@8
  __m64 v12; // mm0@8
  __m64 v13; // mm1@8
  __m64 v14; // mm1@8
  __m64 v15; // mm0@9
  __m64 v16; // mm3@10
  __m64 v17; // mm4@10
  __m64 v18; // mm3@10
  unsigned int v19; // ST0C_4@11
  bool v20; // zf@14
  unsigned int v21; // [sp+10h] [bp-20h]@5
  char *v22; // [sp+14h] [bp-1Ch]@1
  unsigned int v23; // [sp+18h] [bp-18h]@5
  char *v24; // [sp+1Ch] [bp-14h]@1
  unsigned int v25; // [sp+20h] [bp-10h]@3
  unsigned int v26; // [sp+24h] [bp-Ch]@3
  unsigned int v27; // [sp+28h] [bp-8h]@3
  unsigned int v28; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v24 = i_args->cSrcArgs.pDstBuf;
  v22 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v26 = i_args->nWidth;
      v27 = i_args->cSrcArgs.iStride;
      v28 = i_args->cDstArgs.iStride;
      v25 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[3 * v3];
          v5 = (int)&v22[3 * v3 + 2];
          BYTE3(v21) = -1;
          v6 = v1 - v22;
          v23 = v3;
          do
          {
            v7 = *(_BYTE *)(v6 + v5 - 4);
            v8 = *(_BYTE *)(v4 - 3);
            v5 -= 3;
            v4 -= 3;
            BYTE1(v21) = v7;
            LOBYTE(v21) = v8;
            v9 = 256;
            if ( v2 == 256 || (v9 = (v2 << 8) / 256) != 0 )
            {
              LOBYTE(v10) = *(_BYTE *)(v5 - 2);
              BYTE1(v10) = *(_BYTE *)(v5 - 1);
              BYTE2(v10) = *(_BYTE *)v5;
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v10) = -1;
              v12 = _m_punpcklbw(_mm_cvtsi32_si64(v10), 0i64);
              BYTE2(v21) = *(_BYTE *)(v6 + v5);
              v13 = _m_punpcklbw(_mm_cvtsi32_si64(v21), 0i64);
              v14 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v13, _m_pcmpgtw(v13, 0i64)), v12), 8u), v11),
                      _m_pandn(v11, v12));
              if ( v9 == 256 )
              {
                v15 = v14;
              }
              else
              {
                v16 = _mm_cvtsi32_si64(v9);
                v17 = _m_punpcklwd(v16, v16);
                v18 = _m_punpcklwd(v17, v17);
                v15 = _m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v18), 8u), _m_psrlw(_m_pmullw(v14, v18), 8u)));
              }
              v19 = _mm_cvtsi64_si32(_m_packuswb(v15, 0i64));
              *(_BYTE *)(v5 - 2) = v19;
              *(_BYTE *)(v5 - 1) = BYTE1(v19);
              *(_BYTE *)v5 = v19 >> 16;
            }
            --v23;
          }
          while ( v23 );
          v3 = v26;
          v1 = v24;
        }
        v1 += v27;
        v20 = v25 == 1;
        v24 = v1;
        v22 += v28;
        --v25;
      }
      while ( !v20 );
    }
    _m_femms();
  }
}

//----- (00663520) --------------------------------------------------------  // acclient.c:633971
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  unsigned int *v4; // ecx@5
  unsigned int v5; // esi@6
  unsigned int v6; // eax@6
  __m64 v7; // mm3@9
  __m64 v8; // mm0@9
  __m64 v9; // mm1@9
  unsigned int v10; // eax@9
  __m64 v11; // mm1@9
  __m64 v12; // mm0@10
  __m64 v13; // mm3@11
  __m64 v14; // mm4@11
  __m64 v15; // mm3@11
  bool v16; // zf@15
  char *v17; // [sp+10h] [bp-20h]@1
  unsigned int v18; // [sp+14h] [bp-1Ch]@5
  char *v19; // [sp+18h] [bp-18h]@1
  unsigned int v20; // [sp+1Ch] [bp-14h]@3
  unsigned int v21; // [sp+24h] [bp-Ch]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v17 = i_args->cSrcArgs.pDstBuf;
  v19 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v18 = v3;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v17 - v1 - 4);
            --v4;
            v6 = v5 >> 24;
            if ( v2 != 256 )
              v6 = (signed int)(v2 * v6) / 256;
            if ( v6 )
            {
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
              v10 = v6 + 1;
              v11 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v8, v9), _m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u)),
                        v7),
                      _m_pandn(v7, v8));
              if ( v10 == 256 )
              {
                v12 = v11;
              }
              else
              {
                v13 = _mm_cvtsi32_si64(v10);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                v12 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v15), 8u), _m_psrlw(_m_pmullw(v11, v15), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v12, 0i64));
            }
            --v18;
          }
          while ( v18 );
          v3 = v21;
          v1 = v19;
        }
        v1 += v23;
        v16 = v20 == 1;
        v17 += v22;
        v19 = v1;
        --v20;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (00663680) --------------------------------------------------------  // acclient.c:634066
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // edi@6
  unsigned int v6; // eax@6
  unsigned int v7; // ST10_4@9
  __m64 v8; // mm3@9
  __m64 v9; // mm0@9
  __m64 v10; // mm1@9
  unsigned int v11; // eax@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  unsigned int v17; // ST10_4@12
  bool v18; // zf@14
  char *v19; // [sp+14h] [bp-1Ch]@1
  char *v20; // [sp+18h] [bp-18h]@1
  unsigned int v21; // [sp+1Ch] [bp-14h]@3
  unsigned int v22; // [sp+20h] [bp-10h]@3
  unsigned int v23; // [sp+28h] [bp-8h]@3
  unsigned int v24; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v19 = i_args->cSrcArgs.pDstBuf;
  v20 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v22 = i_args->nWidth;
      v23 = i_args->cSrcArgs.iStride;
      v24 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        v3 = v22;
        if ( v22 )
        {
          v4 = (int)(&v1[2 * v22 + 2] + v22);
          do
          {
            v5 = *(_DWORD *)&v19[4 * v3-- - 4];
            v4 -= 3;
            v6 = v5 >> 24;
            if ( v2 != 256 )
              v6 = (signed int)(v2 * v6) / 256;
            if ( v6 )
            {
              LOBYTE(v7) = *(_BYTE *)(v4 - 2);
              BYTE1(v7) = *(_BYTE *)(v4 - 1);
              BYTE2(v7) = *(_BYTE *)v4;
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v7) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
              v11 = v6 + 1;
              v12 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v9, v10), _m_psrlw(_m_pmullw(_m_psubw(v10, _m_pcmpgtw(v10, 0i64)), v9), 8u)),
                        v8),
                      _m_pandn(v8, v9));
              if ( v11 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v11);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              v17 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
              *(_BYTE *)(v4 - 2) = v17;
              *(_BYTE *)(v4 - 1) = BYTE1(v17);
              *(_BYTE *)v4 = v17 >> 16;
            }
          }
          while ( v3 );
        }
        v19 += v23;
        v1 = &v20[v24];
        v18 = v21 == 1;
        v20 += v24;
        --v21;
      }
      while ( !v18 );
    }
    _m_femms();
  }
}

//----- (00663810) --------------------------------------------------------  // acclient.c:634165
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ebx@1
  int v2; // edi@2
  unsigned int v3; // edx@3
  unsigned int *v4; // ecx@5
  unsigned int v5; // edx@6
  int v6; // eax@6
  __m64 v7; // mm3@8
  __m64 v8; // mm0@8
  __m64 v9; // mm1@8
  unsigned int v10; // eax@8
  __m64 v11; // mm1@8
  __m64 v12; // mm0@9
  __m64 v13; // mm3@10
  __m64 v14; // mm4@10
  __m64 v15; // mm3@10
  bool v16; // zf@14
  char *v17; // [sp+Ch] [bp-1Ch]@1
  unsigned int v18; // [sp+10h] [bp-18h]@6
  unsigned int v19; // [sp+14h] [bp-14h]@5
  unsigned int v20; // [sp+18h] [bp-10h]@3
  unsigned int v21; // [sp+1Ch] [bp-Ch]@3
  unsigned int v22; // [sp+20h] [bp-8h]@3
  unsigned int v23; // [sp+24h] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v17 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v19 = v3;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v17 - v1 - 4);
            --v4;
            v18 = v5;
            BYTE3(v18) = -1;
            v6 = 255;
            if ( v2 == 256 || (v6 = 255 * v2 / 256) != 0 )
            {
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64);
              v10 = v6 + 1;
              v11 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v8, v9), _m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u)),
                        v7),
                      _m_pandn(v7, v8));
              if ( v10 == 256 )
              {
                v12 = v11;
              }
              else
              {
                v13 = _mm_cvtsi32_si64(v10);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                v12 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v15), 8u), _m_psrlw(_m_pmullw(v11, v15), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v12, 0i64));
            }
            --v19;
          }
          while ( v19 );
          v3 = v21;
        }
        v1 += v23;
        v16 = v20 == 1;
        v17 += v22;
        --v20;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (00663980) --------------------------------------------------------  // acclient.c:634257
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  unsigned int v6; // edx@6
  int v7; // eax@6
  unsigned int v8; // ST0C_4@8
  __m64 v9; // mm3@8
  __m64 v10; // mm0@8
  __m64 v11; // mm1@8
  unsigned int v12; // eax@8
  __m64 v13; // mm1@8
  __m64 v14; // mm0@9
  __m64 v15; // mm3@10
  __m64 v16; // mm4@10
  __m64 v17; // mm3@10
  unsigned int v18; // ST0C_4@11
  bool v19; // zf@13
  unsigned int v20; // [sp+10h] [bp-18h]@6
  char *v21; // [sp+14h] [bp-14h]@1
  unsigned int v22; // [sp+18h] [bp-10h]@3
  unsigned int v23; // [sp+1Ch] [bp-Ch]@3
  unsigned int v24; // [sp+20h] [bp-8h]@3
  unsigned int v25; // [sp+24h] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  v21 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v23 = i_args->nWidth;
      v24 = i_args->cSrcArgs.iStride;
      v25 = i_args->cDstArgs.iStride;
      v22 = i_args->nHeight;
      do
      {
        v4 = v23;
        if ( v23 )
        {
          v5 = (int)(&v1[2 * v23 + 2] + v23);
          do
          {
            v6 = *(_DWORD *)&v2[4 * v4-- - 4];
            v5 -= 3;
            v20 = v6;
            BYTE3(v20) = -1;
            v7 = 255;
            if ( v3 != 256 )
            {
              v7 = 255 * v3 / 256;
              if ( !v7 )
                continue;
            }
            LOBYTE(v8) = *(_BYTE *)(v5 - 2);
            BYTE1(v8) = *(_BYTE *)(v5 - 1);
            BYTE2(v8) = *(_BYTE *)v5;
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            BYTE3(v8) = -1;
            v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
            v11 = _m_punpcklbw(_mm_cvtsi32_si64(v20), 0i64);
            v12 = v7 + 1;
            v13 = _m_por(
                    _m_pand(
                      _m_psubw(_m_paddw(v10, v11), _m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u)),
                      v9),
                    _m_pandn(v9, v10));
            if ( v12 == 256 )
            {
              v14 = v13;
            }
            else
            {
              v15 = _mm_cvtsi32_si64(v12);
              v16 = _m_punpcklwd(v15, v15);
              v17 = _m_punpcklwd(v16, v16);
              v14 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v17), 8u), _m_psrlw(_m_pmullw(v13, v17), 8u)));
            }
            v18 = _mm_cvtsi64_si32(_m_packuswb(v14, 0i64));
            *(_BYTE *)(v5 - 2) = v18;
            *(_BYTE *)(v5 - 1) = BYTE1(v18);
            *(_BYTE *)v5 = v18 >> 16;
          }
          while ( v4 );
        }
        v2 += v24;
        v1 = &v21[v25];
        v19 = v22 == 1;
        v21 += v25;
        --v22;
      }
      while ( !v19 );
    }
    _m_femms();
  }
}

//----- (00663B10) --------------------------------------------------------  // acclient.c:634360
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  char v6; // dl@6
  char v7; // al@6
  int v8; // eax@6
  __m64 v9; // mm3@8
  __m64 v10; // mm0@8
  __m64 v11; // mm1@8
  unsigned int v12; // eax@8
  __m64 v13; // mm1@8
  __m64 v14; // mm0@9
  __m64 v15; // mm3@10
  __m64 v16; // mm4@10
  __m64 v17; // mm3@10
  bool v18; // zf@13
  unsigned int v19; // [sp+10h] [bp-18h]@5
  char *v20; // [sp+14h] [bp-14h]@1
  unsigned int v21; // [sp+18h] [bp-10h]@3
  unsigned int v22; // [sp+1Ch] [bp-Ch]@3
  unsigned int v23; // [sp+20h] [bp-8h]@3
  unsigned int v24; // [sp+24h] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  v20 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v22 = i_args->nWidth;
      v23 = i_args->cSrcArgs.iStride;
      v24 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        v4 = v22;
        if ( v22 )
        {
          BYTE3(v19) = -1;
          v5 = (int)(&v1[2 * v22 + 2] + v22);
          do
          {
            v6 = *(_BYTE *)(v5 - 5);
            v7 = *(_BYTE *)(v5 - 4);
            v5 -= 3;
            LOBYTE(v19) = v6;
            --v4;
            BYTE1(v19) = v7;
            v8 = 255;
            if ( v3 != 256 )
            {
              v8 = 255 * v3 / 256;
              if ( !v8 )
                continue;
            }
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v10 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v2[4 * v4]), 0i64);
            BYTE2(v19) = *(_BYTE *)v5;
            v11 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
            v12 = v8 + 1;
            v13 = _m_por(
                    _m_pand(
                      _m_psubw(_m_paddw(v10, v11), _m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u)),
                      v9),
                    _m_pandn(v9, v10));
            if ( v12 == 256 )
            {
              v14 = v13;
            }
            else
            {
              v15 = _mm_cvtsi32_si64(v12);
              v16 = _m_punpcklwd(v15, v15);
              v17 = _m_punpcklwd(v16, v16);
              v14 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v17), 8u), _m_psrlw(_m_pmullw(v13, v17), 8u)));
            }
            *(_DWORD *)&v2[4 * v4] = _mm_cvtsi64_si32(_m_packuswb(v14, 0i64));
          }
          while ( v4 );
        }
        v1 = &v20[v23];
        v2 += v24;
        v18 = v21 == 1;
        v20 += v23;
        --v21;
      }
      while ( !v18 );
    }
    _m_femms();
  }
}

//----- (00663C90) --------------------------------------------------------  // acclient.c:634459
void __cdecl BlitLoopNoScale__BlitOp_Screen_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  int v2; // ebx@2
  unsigned int v3; // edx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // esi@5
  char v7; // dl@6
  char v8; // al@6
  int v9; // eax@6
  unsigned int v10; // ST0C_4@8
  __m64 v11; // mm3@8
  __m64 v12; // mm0@8
  __m64 v13; // mm1@8
  unsigned int v14; // eax@8
  __m64 v15; // mm1@8
  __m64 v16; // mm0@9
  __m64 v17; // mm3@10
  __m64 v18; // mm4@10
  __m64 v19; // mm3@10
  unsigned int v20; // ST0C_4@11
  bool v21; // zf@14
  unsigned int v22; // [sp+10h] [bp-20h]@5
  char *v23; // [sp+14h] [bp-1Ch]@1
  unsigned int v24; // [sp+18h] [bp-18h]@5
  char *v25; // [sp+1Ch] [bp-14h]@1
  unsigned int v26; // [sp+20h] [bp-10h]@3
  unsigned int v27; // [sp+24h] [bp-Ch]@3
  unsigned int v28; // [sp+28h] [bp-8h]@3
  unsigned int v29; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v25 = i_args->cSrcArgs.pDstBuf;
  v23 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v27 = i_args->nWidth;
      v28 = i_args->cSrcArgs.iStride;
      v29 = i_args->cDstArgs.iStride;
      v26 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[3 * v3];
          v5 = (int)&v23[3 * v3 + 2];
          BYTE3(v22) = -1;
          v6 = v1 - v23;
          v24 = v3;
          do
          {
            v7 = *(_BYTE *)(v4 - 3);
            v8 = *(_BYTE *)(v6 + v5 - 4);
            v4 -= 3;
            v5 -= 3;
            LOBYTE(v22) = v7;
            BYTE1(v22) = v8;
            v9 = 255;
            if ( v2 == 256 || (v9 = 255 * v2 / 256) != 0 )
            {
              LOBYTE(v10) = *(_BYTE *)(v5 - 2);
              BYTE1(v10) = *(_BYTE *)(v5 - 1);
              BYTE2(v10) = *(_BYTE *)v5;
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v10) = -1;
              v12 = _m_punpcklbw(_mm_cvtsi32_si64(v10), 0i64);
              BYTE2(v22) = *(_BYTE *)(v6 + v5);
              v13 = _m_punpcklbw(_mm_cvtsi32_si64(v22), 0i64);
              v14 = v9 + 1;
              v15 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v12, v13), _m_psrlw(_m_pmullw(_m_psubw(v13, _m_pcmpgtw(v13, 0i64)), v12), 8u)),
                        v11),
                      _m_pandn(v11, v12));
              if ( v14 == 256 )
              {
                v16 = v15;
              }
              else
              {
                v17 = _mm_cvtsi32_si64(v14);
                v18 = _m_punpcklwd(v17, v17);
                v19 = _m_punpcklwd(v18, v18);
                v16 = _m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v19), 8u), _m_psrlw(_m_pmullw(v15, v19), 8u)));
              }
              v20 = _mm_cvtsi64_si32(_m_packuswb(v16, 0i64));
              *(_BYTE *)(v5 - 2) = v20;
              *(_BYTE *)(v5 - 1) = BYTE1(v20);
              *(_BYTE *)v5 = v20 >> 16;
            }
            --v24;
          }
          while ( v24 );
          v3 = v27;
          v1 = v25;
        }
        v1 += v28;
        v21 = v26 == 1;
        v25 = v1;
        v23 += v29;
        --v26;
      }
      while ( !v21 );
    }
    _m_femms();
  }
}

//----- (00663E50) --------------------------------------------------------  // acclient.c:634573
void __cdecl ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  BlitArgs *v1; // eax@1
  char *v2; // edx@1
  unsigned int v3; // ebx@3
  unsigned int v4; // eax@3
  unsigned int v5; // esi@3
  unsigned int v6; // edi@3
  unsigned int i; // ecx@4
  unsigned int v8; // ecx@8
  unsigned int v9; // ebx@9
  unsigned int v10; // eax@9
  unsigned int v11; // edi@9
  unsigned int j; // ecx@10
  unsigned int i_argsa; // [sp+10h] [bp+4h]@8

  v1 = i_args;
  v2 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v4 = i_args->cDstArgs.iStride;
      v5 = g_SourceColor.u;
      v6 = i_args->nHeight;
      do
      {
        for ( i = v3; i; *(_DWORD *)&v2[4 * i] = v5 )
          --i;
        v2 += v4;
        --v6;
      }
      while ( v6 );
    }
  }
  else
  {
    i_argsa = g_SourceColor.u;
    BYTE3(i_argsa) = v1->i8AlphaModifier;
    v8 = v1->nHeight;
    if ( v8 )
    {
      v9 = v1->nWidth;
      v10 = v1->cDstArgs.iStride;
      v11 = v8;
      do
      {
        for ( j = v9; j; *(_DWORD *)&v2[4 * j] = i_argsa )
          --j;
        v2 -= v10;
        --v11;
      }
      while ( v11 );
    }
  }
  _m_femms();
}

//----- (00663ED0) --------------------------------------------------------  // acclient.c:634633
void __cdecl ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // ebx@2
  unsigned int v2; // edi@3
  char v3; // dl@3
  unsigned int v4; // ebp@3
  __int16 v5; // cx@3
  int v6; // eax@5
  unsigned int v7; // esi@5
  unsigned int v8; // edx@9
  __int16 v9; // cx@9
  char *v10; // ebp@9
  unsigned int v11; // edi@10
  int v12; // eax@12
  unsigned int v13; // esi@12
  char pixSrc_2; // [sp+12h] [bp-2h]@9
  unsigned int i_argsa; // [sp+18h] [bp+4h]@3
  unsigned int i_argsb; // [sp+18h] [bp+4h]@10

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v2 = i_args->nWidth;
      v3 = g_SourceColor.r;
      v4 = i_args->nHeight;
      v5 = *(_WORD *)&g_SourceColor;
      i_argsa = i_args->cDstArgs.iStride;
      do
      {
        if ( v2 )
        {
          v6 = (int)(&v1[2 * v2 + 2] + v2);
          v7 = v2;
          do
          {
            v6 -= 3;
            --v7;
            *(_BYTE *)(v6 - 2) = v5;
            *(_BYTE *)(v6 - 1) = HIBYTE(v5);
            *(_BYTE *)v6 = v3;
          }
          while ( v7 );
        }
        v1 += i_argsa;
        --v4;
      }
      while ( v4 );
    }
  }
  else
  {
    v8 = i_args->nHeight;
    v9 = *(_WORD *)&g_SourceColor;
    v10 = i_args->cDstArgs.pDstBuf;
    pixSrc_2 = g_SourceColor.r;
    if ( v8 )
    {
      v11 = i_args->nWidth;
      i_argsb = i_args->cDstArgs.iStride;
      do
      {
        if ( v11 )
        {
          v12 = (int)(&v10[2 * v11 + 2] + v11);
          v13 = v11;
          do
          {
            v12 -= 3;
            --v13;
            *(_BYTE *)(v12 - 2) = v9;
            *(_BYTE *)(v12 - 1) = HIBYTE(v9);
            *(_BYTE *)v12 = pixSrc_2;
          }
          while ( v13 );
        }
        v10 -= i_argsb;
        --v8;
      }
      while ( v8 );
    }
  }
  _m_femms();
}

//----- (00663F80) --------------------------------------------------------  // acclient.c:634720
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_(BlitArgs *i_args)
{
  BlitArgs *v1; // ecx@1
  unsigned int v2; // edx@1
  char *v3; // ebp@1
  char *v4; // edi@1
  unsigned int v5; // eax@2
  unsigned int v6; // ebx@2
  int v7; // eax@2
  unsigned int v8; // edx@2
  unsigned int v9; // esi@3
  int v10; // ecx@4
  int v11; // eax@5
  unsigned int v12; // ebp@5
  unsigned int v13; // ebp@5
  int v14; // ebp@8
  bool v15; // zf@10
  int nTrailing; // [sp+8h] [bp-10h]@2
  unsigned int v17; // [sp+Ch] [bp-Ch]@2
  unsigned int v18; // [sp+10h] [bp-8h]@2
  unsigned int v19; // [sp+14h] [bp-4h]@2
  char *i_argsa; // [sp+1Ch] [bp+4h]@1

  v1 = i_args;
  v2 = i_args->nHeight;
  v3 = i_args->cDstArgs.pDstBuf;
  v4 = i_args->cSrcArgs.pDstBuf;
  i_argsa = i_args->cDstArgs.pDstBuf;
  if ( v2 )
  {
    v5 = v1->nWidth;
    v6 = v5 >> 2;
    v7 = v5 & 3;
    v17 = v2;
    v8 = g_SourceColor.u;
    nTrailing = v7;
    v18 = v1->cSrcArgs.iStride;
    v19 = v1->cDstArgs.iStride;
    do
    {
      v9 = v6;
      if ( v6 )
      {
        v10 = (int)&v3[16 * v6];
        do
        {
          v11 = *(_DWORD *)&v4[4 * v9-- - 4];
          v12 = v8 | v11 & 0xFF000000;
          v10 -= 16;
          v11 <<= 8;
          *(_DWORD *)(v10 + 12) = v12;
          v13 = v8 | v11 & 0xFF000000;
          v11 <<= 8;
          *(_DWORD *)(v10 + 8) = v13;
          *(_DWORD *)(v10 + 4) = v8 | v11 & 0xFF000000;
          *(_DWORD *)v10 = v8 | ((v11 & 0xFFFF0000) << 8);
        }
        while ( v9 );
        v7 = nTrailing;
      }
      if ( v7 )
      {
        do
        {
          v14 = (unsigned __int8)*(&v4[4 * v6 - 1] + v7--);
          *((_DWORD *)&i_argsa[16 * v6] + v7) = v8 | (v14 << 24);
        }
        while ( v7 );
        v7 = nTrailing;
      }
      v4 += v18;
      v3 = &i_argsa[v19];
      v15 = v17 == 1;
      i_argsa += v19;
      --v17;
    }
    while ( !v15 );
  }
  _m_femms();
}

//----- (00664080) --------------------------------------------------------  // acclient.c:634802
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // ebp@1
  unsigned int v2; // ecx@2
  unsigned int v3; // ebx@2
  int v4; // ecx@2
  unsigned int v5; // esi@2
  unsigned int v6; // edi@3
  int v7; // eax@4
  int v8; // ecx@5
  unsigned int v9; // edx@5
  unsigned int v10; // edx@5
  unsigned int v11; // edx@5
  int v12; // edx@8
  int v13; // ecx@9
  int v14; // eax@10
  bool v15; // zf@12
  char *pDst; // [sp+4h] [bp-14h]@1
  int nTrailing; // [sp+8h] [bp-10h]@2
  unsigned int v18; // [sp+Ch] [bp-Ch]@2
  unsigned int v19; // [sp+10h] [bp-8h]@2
  unsigned int v20; // [sp+14h] [bp-4h]@2
  unsigned int i_argsa; // [sp+1Ch] [bp+4h]@5
  int i_argsb; // [sp+1Ch] [bp+4h]@10

  v1 = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth;
    v3 = v2 >> 2;
    v4 = v2 & 3;
    v19 = i_args->cSrcArgs.iStride;
    v5 = g_SourceColor.u;
    nTrailing = v4;
    v20 = i_args->cDstArgs.iStride;
    v18 = i_args->nHeight;
    do
    {
      v6 = v3;
      if ( v3 )
      {
        v7 = (int)&pDst[12 * v3 + 11];
        do
        {
          v8 = *(_DWORD *)&v1[4 * v6 - 4];
          v7 -= 12;
          v9 = v5 | *(_DWORD *)&v1[4 * v6-- - 4] & 0xFF000000;
          *(_BYTE *)(v7 - 2) = v9;
          *(_BYTE *)(v7 - 1) = BYTE1(v9);
          *(_BYTE *)v7 = v9 >> 16;
          v8 <<= 8;
          v10 = v5 | v8 & 0xFF000000;
          *(_BYTE *)(v7 - 5) = v5;
          *(_BYTE *)(v7 - 4) = BYTE1(v10);
          v8 <<= 8;
          *(_BYTE *)(v7 - 3) = v10 >> 16;
          v11 = v5 | v8 & 0xFF000000;
          *(_BYTE *)(v7 - 8) = v5;
          *(_BYTE *)(v7 - 7) = BYTE1(v11);
          i_argsa = v5 | ((v8 & 0xFFFF0000) << 8);
          *(_BYTE *)(v7 - 11) = v5;
          *(_BYTE *)(v7 - 10) = BYTE1(i_argsa);
          *(_BYTE *)(v7 - 6) = v11 >> 16;
          *(_BYTE *)(v7 - 9) = i_argsa >> 16;
        }
        while ( v6 );
        v4 = nTrailing;
      }
      if ( v4 )
      {
        v12 = v4;
        if ( v4 )
        {
          v13 = (int)(&pDst[12 * v3 + 2] + 2 * v4 + v4);
          do
          {
            v14 = (unsigned __int8)*(&v1[4 * v3 - 1] + v12--);
            v13 -= 3;
            i_argsb = v5 | (v14 << 24);
            *(_BYTE *)(v13 - 2) = v5;
            *(_BYTE *)(v13 - 1) = BYTE1(i_argsb);
            *(_BYTE *)v13 = (unsigned int)i_argsb >> 16;
          }
          while ( v12 );
          v4 = nTrailing;
        }
      }
      v1 += v19;
      v15 = v18 == 1;
      pDst += v20;
      --v18;
    }
    while ( !v15 );
  }
  _m_femms();
}

//----- (006641E0) --------------------------------------------------------  // acclient.c:634901
void __cdecl ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  BlitArgs *v1; // eax@1
  char *v2; // esi@2
  char *v3; // ebx@2
  unsigned int v4; // edi@3
  int v5; // eax@5
  unsigned int v6; // edx@5
  int v7; // ebp@6
  char *v8; // edx@9
  unsigned int v9; // ecx@9
  unsigned int v10; // ebx@10
  unsigned int v11; // eax@10
  unsigned int v12; // edi@10
  unsigned int i; // ecx@11
  unsigned int v14; // [sp+Ch] [bp-8h]@3
  unsigned int v15; // [sp+10h] [bp-4h]@3
  unsigned int i_argsa; // [sp+18h] [bp+4h]@3
  unsigned int i_argsb; // [sp+18h] [bp+4h]@9

  v1 = i_args;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v2 = i_args->cDstArgs.pDstBuf;
    v3 = i_args->cSrcArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v4 = i_args->nWidth;
      v14 = i_args->cSrcArgs.iStride;
      v15 = i_args->cDstArgs.iStride;
      i_argsa = i_args->nHeight;
      do
      {
        if ( v4 )
        {
          v5 = (int)&v2[4 * v4];
          v6 = v4;
          do
          {
            v7 = *(_DWORD *)(v3 - v2 + v5 - 4);
            v5 -= 4;
            --v6;
            *(_DWORD *)v5 = g_SourceColor.u | v7 & 0xFF000000;
          }
          while ( v6 );
        }
        v3 += v14;
        v2 += v15;
        --i_argsa;
      }
      while ( i_argsa );
    }
  }
  else
  {
    v8 = i_args->cDstArgs.pDstBuf;
    i_argsb = g_SourceColor.u;
    BYTE3(i_argsb) = v1->i8AlphaModifier;
    v9 = v1->nHeight;
    if ( v9 )
    {
      v10 = v1->nWidth;
      v11 = v1->cDstArgs.iStride;
      v12 = v9;
      do
      {
        for ( i = v10; i; *(_DWORD *)&v8[4 * i] = i_argsb )
          --i;
        v8 -= v11;
        --v12;
      }
      while ( v12 );
    }
  }
  _m_femms();
}

//----- (006642B0) --------------------------------------------------------  // acclient.c:634979
void __cdecl ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // ebp@1
  char *v2; // esi@1
  unsigned int v3; // ecx@2
  unsigned int v4; // edi@3
  unsigned int v5; // ebx@3
  unsigned int v6; // edx@4
  int v7; // ecx@5
  int v8; // eax@6
  unsigned int v9; // ST14_4@6
  unsigned int v10; // edx@9
  __int16 v11; // cx@9
  unsigned int v12; // edi@10
  int v13; // eax@12
  unsigned int v14; // esi@12
  unsigned int v15; // [sp+10h] [bp-Ch]@3
  unsigned int pixSrc; // [sp+18h] [bp-4h]@3
  char pixSrc_2; // [sp+1Ah] [bp-2h]@9
  unsigned int i_argsa; // [sp+20h] [bp+4h]@3
  unsigned int i_argsb; // [sp+20h] [bp+4h]@10

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  if ( v2 )
  {
    v3 = i_args->nHeight;
    if ( v3 )
    {
      v4 = g_SourceColor.u;
      v15 = i_args->nWidth;
      pixSrc = i_args->cSrcArgs.iStride;
      i_argsa = i_args->cDstArgs.iStride;
      v5 = v3;
      do
      {
        v6 = v15;
        if ( v15 )
        {
          v7 = (int)(&v1[2 * v15 + 2] + v15);
          do
          {
            v8 = *(_DWORD *)&v2[4 * v6-- - 4];
            v7 -= 3;
            v9 = v4 | v8 & 0xFF000000;
            *(_BYTE *)(v7 - 2) = v4;
            *(_BYTE *)(v7 - 1) = BYTE1(v9);
            *(_BYTE *)v7 = v9 >> 16;
          }
          while ( v6 );
        }
        v2 += pixSrc;
        v1 += i_argsa;
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    v10 = i_args->nHeight;
    v11 = *(_WORD *)&g_SourceColor;
    pixSrc_2 = g_SourceColor.r;
    if ( v10 )
    {
      v12 = i_args->nWidth;
      i_argsb = i_args->cDstArgs.iStride;
      do
      {
        if ( v12 )
        {
          v13 = (int)(&v1[2 * v12 + 2] + v12);
          v14 = v12;
          do
          {
            v13 -= 3;
            --v14;
            *(_BYTE *)(v13 - 2) = v11;
            *(_BYTE *)(v13 - 1) = HIBYTE(v11);
            *(_BYTE *)v13 = pixSrc_2;
          }
          while ( v14 );
        }
        v1 -= i_argsb;
        --v10;
      }
      while ( v10 );
    }
  }
  _m_femms();
}

//----- (00664380) --------------------------------------------------------  // acclient.c:635072
void __cdecl ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // esi@1
  int v2; // ebx@2
  unsigned int v3; // edi@3
  unsigned int v4; // ecx@4
  int v5; // eax@6
  unsigned int v6; // edx@9
  unsigned int v7; // eax@9
  __m64 v8; // mm2@11
  __m64 v9; // mm0@11
  __m64 v10; // mm3@11
  __m64 v11; // mm4@11
  __m64 v12; // mm3@11
  unsigned int v13; // eax@17
  unsigned int v14; // edx@20
  __m64 v15; // mm2@22
  __m64 v16; // mm0@22
  __m64 v17; // mm3@22
  __m64 v18; // mm4@22
  __m64 v19; // mm3@22
  unsigned int v20; // [sp+Ch] [bp-14h]@3
  unsigned int v21; // [sp+Ch] [bp-14h]@16
  unsigned int v22; // [sp+10h] [bp-10h]@3
  unsigned int v23; // [sp+10h] [bp-10h]@15
  unsigned int v24; // [sp+14h] [bp-Ch]@3
  unsigned int v25; // [sp+14h] [bp-Ch]@16
  int v26; // [sp+18h] [bp-8h]@5
  unsigned int v27; // [sp+18h] [bp-8h]@16
  int v28; // [sp+1Ch] [bp-4h]@2
  unsigned int v29; // [sp+1Ch] [bp-4h]@18

  v1 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    v28 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = g_SourceColor.u;
      v20 = i_args->nWidth;
      v24 = i_args->cDstArgs.iStride;
      v22 = i_args->nHeight;
      do
      {
        v4 = v20;
        if ( v20 )
        {
          v26 = BYTE3(g_SourceColor.u);
          do
          {
            v5 = v26;
            --v4;
            if ( v2 != 256 )
              v5 = v2 * v26 / 256;
            if ( v5 )
            {
              v6 = *(_DWORD *)&v1[4 * v4];
              v7 = v5 + 1;
              if ( v7 == 256 )
              {
                *(_DWORD *)&v1[4 * v4] = v6 ^ (v6 ^ v3) & 0xFFFFFF;
              }
              else
              {
                v2 = v28;
                v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
                v10 = _mm_cvtsi32_si64(v7);
                v11 = _m_punpcklwd(v10, v10);
                v12 = _m_punpcklwd(v11, v11);
                *(_DWORD *)&v1[4 * v4] = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v12), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v3), 0i64), v8), _m_pandn(v8, v9)), v12), 8u))), 0i64));
              }
            }
          }
          while ( v4 );
        }
        v1 += v24;
        --v22;
      }
      while ( v22 );
    }
  }
  else
  {
    v23 = g_SourceColor.u;
    BYTE3(v23) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v25 = i_args->cDstArgs.iStride;
      v27 = i_args->nHeight;
      do
      {
        v13 = v21;
        if ( v21 )
        {
          v29 = v23 >> 24;
          do
          {
            --v13;
            if ( v29 )
            {
              v14 = *(_DWORD *)&v1[4 * v13];
              if ( v29 == 255 )
              {
                *(_DWORD *)&v1[4 * v13] = v14 ^ (v23 ^ v14) & 0xFFFFFF;
              }
              else
              {
                v15 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v16 = _m_punpcklbw(_mm_cvtsi32_si64(v14), 0i64);
                v17 = _mm_cvtsi32_si64(v29 + 1);
                v18 = _m_punpcklwd(v17, v17);
                v19 = _m_punpcklwd(v18, v18);
                *(_DWORD *)&v1[4 * v13] = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v16, _m_psubw(_m_psrlw(_m_pmullw(v16, v19), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64), v15), _m_pandn(v15, v16)), v19), 8u))), 0i64));
              }
            }
          }
          while ( v13 );
        }
        v1 -= v25;
        --v27;
      }
      while ( v27 );
    }
  }
  _m_femms();
}

//----- (006645B0) --------------------------------------------------------  // acclient.c:635203
void __cdecl ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // esi@2
  unsigned int v2; // edx@3
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // eax@9
  int v8; // eax@10
  __m64 v9; // mm2@11
  __m64 v10; // mm0@11
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  unsigned int v14; // ST0C_4@11
  bool v15; // zf@14
  char *v16; // edx@16
  unsigned int v17; // ebx@17
  unsigned int v18; // edi@19
  int v19; // eax@19
  int v20; // ecx@22
  __m64 v21; // mm2@23
  __m64 v22; // mm0@23
  __m64 v23; // mm3@23
  __m64 v24; // mm4@23
  __m64 v25; // mm3@23
  unsigned int v26; // ST0C_4@23
  unsigned int v27; // [sp+Ch] [bp-1Ch]@9
  unsigned int v28; // [sp+Ch] [bp-1Ch]@21
  char *v29; // [sp+10h] [bp-18h]@2
  unsigned int v30; // [sp+10h] [bp-18h]@16
  unsigned int v31; // [sp+14h] [bp-14h]@3
  unsigned int v32; // [sp+14h] [bp-14h]@17
  unsigned int v33; // [sp+18h] [bp-10h]@5
  char *v34; // [sp+18h] [bp-10h]@16
  unsigned int v35; // [sp+1Ch] [bp-Ch]@3
  unsigned int v36; // [sp+1Ch] [bp-Ch]@19
  unsigned int v37; // [sp+20h] [bp-8h]@17
  unsigned int v38; // [sp+24h] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v29 = i_args->cDstArgs.pDstBuf;
    v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v2 = i_args->nWidth;
      v3 = g_SourceColor.u;
      v38 = i_args->nWidth;
      v31 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        if ( v2 )
        {
          v4 = BYTE3(g_SourceColor.u);
          v5 = (int)(&v29[2 * v2 + 2] + v2);
          v33 = v2;
          do
          {
            v5 -= 3;
            v6 = v4;
            if ( v1 != 256 )
              v6 = v1 * v4 / 256;
            if ( v6 )
            {
              LOBYTE(v27) = *(_BYTE *)(v5 - 2);
              v7 = v6 + 1;
              BYTE1(v27) = *(_BYTE *)(v5 - 1);
              BYTE2(v27) = *(_BYTE *)v5;
              BYTE3(v27) = -1;
              if ( v7 == 256 )
              {
                v8 = v27 ^ (v27 ^ v3) & 0xFFFFFF;
                *(_BYTE *)(v5 - 2) = v27 ^ v27 ^ v3;
                *(_BYTE *)(v5 - 1) = BYTE1(v8);
                *(_BYTE *)v5 = (unsigned int)v8 >> 16;
              }
              else
              {
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v27), 0i64);
                v11 = _mm_cvtsi32_si64(v7);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v3), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
                *(_BYTE *)(v5 - 2) = v14;
                *(_BYTE *)(v5 - 1) = BYTE1(v14);
                *(_BYTE *)v5 = v14 >> 16;
              }
            }
            --v33;
          }
          while ( v33 );
          v2 = v38;
        }
        v15 = v35 == 1;
        v29 += v31;
        --v35;
      }
      while ( !v15 );
    }
  }
  else
  {
    v16 = i_args->cDstArgs.pDstBuf;
    v30 = g_SourceColor.u;
    BYTE3(v30) = i_args->i8AlphaModifier;
    v34 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v17 = i_args->nWidth;
      v32 = i_args->cDstArgs.iStride;
      v37 = i_args->nHeight;
      do
      {
        if ( v17 )
        {
          v18 = v30 >> 24;
          v19 = (int)(&v16[2 * v17 + 2] + v17);
          v36 = v17;
          do
          {
            v19 -= 3;
            if ( v18 )
            {
              LOBYTE(v28) = *(_BYTE *)(v19 - 2);
              BYTE1(v28) = *(_BYTE *)(v19 - 1);
              BYTE2(v28) = *(_BYTE *)v19;
              BYTE3(v28) = -1;
              if ( v18 == 255 )
              {
                v20 = v28 ^ (v30 ^ v28) & 0xFFFFFF;
                *(_BYTE *)(v19 - 2) = v28 ^ v30 ^ v28;
                *(_BYTE *)(v19 - 1) = BYTE1(v20);
                *(_BYTE *)v19 = (unsigned int)v20 >> 16;
              }
              else
              {
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v22 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
                v23 = _mm_cvtsi32_si64(v18 + 1);
                v24 = _m_punpcklwd(v23, v23);
                v25 = _m_punpcklwd(v24, v24);
                v26 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v22, _m_psubw(_m_psrlw(_m_pmullw(v22, v25), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v30), 0i64), v21), _m_pandn(v21, v22)), v25), 8u))), 0i64));
                *(_BYTE *)(v19 - 2) = v26;
                *(_BYTE *)(v19 - 1) = BYTE1(v26);
                *(_BYTE *)v19 = v26 >> 16;
              }
            }
            --v36;
          }
          while ( v36 );
        }
        v16 = &v34[-v32];
        v15 = v37 == 1;
        v34 -= v32;
        --v37;
      }
      while ( !v15 );
    }
  }
  _m_femms();
}

//----- (00664880) --------------------------------------------------------  // acclient.c:635370
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_(BlitArgs *i_args)
{
  int v1; // ebx@1
  unsigned int v2; // ecx@2
  unsigned int v3; // edi@2
  int v4; // ecx@2
  int v5; // eax@3
  int v6; // edi@4
  int v7; // ecx@5
  signed int v8; // esi@5
  unsigned int v9; // ecx@6
  unsigned int v10; // eax@6
  unsigned int v11; // edx@9
  unsigned int v12; // eax@9
  __m64 v13; // mm2@11
  __m64 v14; // mm0@11
  __m64 v15; // mm3@11
  __m64 v16; // mm4@11
  __m64 v17; // mm3@11
  int v18; // eax@16
  int v19; // edi@16
  int v20; // esi@16
  int v21; // ecx@17
  unsigned int v22; // ecx@17
  unsigned int v23; // eax@17
  unsigned int v24; // edx@20
  unsigned int v25; // eax@20
  __m64 v26; // mm2@22
  __m64 v27; // mm0@22
  __m64 v28; // mm3@22
  __m64 v29; // mm4@22
  __m64 v30; // mm3@22
  bool v31; // zf@26
  char *v32; // [sp+Ch] [bp-2Ch]@1
  char *v33; // [sp+10h] [bp-28h]@1
  unsigned int v34; // [sp+18h] [bp-20h]@2
  int v35; // [sp+1Ch] [bp-1Ch]@5
  int v36; // [sp+20h] [bp-18h]@1
  int v37; // [sp+24h] [bp-14h]@2
  unsigned int v38; // [sp+28h] [bp-10h]@2
  int v39; // [sp+2Ch] [bp-Ch]@5
  int v40; // [sp+2Ch] [bp-Ch]@16
  unsigned int v41; // [sp+30h] [bp-8h]@2
  unsigned int v42; // [sp+34h] [bp-4h]@2

  v32 = i_args->cSrcArgs.pDstBuf;
  v33 = i_args->cDstArgs.pDstBuf;
  v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  v36 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth;
    v3 = v2 >> 2;
    v4 = v2 & 3;
    v34 = v3;
    v37 = v4;
    v41 = i_args->cSrcArgs.iStride;
    v42 = i_args->cDstArgs.iStride;
    v38 = i_args->nHeight;
    do
    {
      v5 = v3;
      if ( v3 )
      {
        v6 = (int)&v33[16 * v3];
        do
        {
          v7 = *(_DWORD *)&v32[4 * v5 - 4];
          v39 = v5 - 1;
          v6 -= 16;
          v35 = *(_DWORD *)&v32[4 * v5 - 4];
          v8 = 3;
          do
          {
            v9 = g_SourceColor.u | v7 & 0xFF000000;
            v10 = v9 >> 24;
            if ( v1 != 256 )
              v10 = (signed int)(v1 * v10) / 256;
            if ( v10 )
            {
              v11 = *(_DWORD *)(v6 + 4 * v8);
              v12 = v10 + 1;
              if ( v12 == 256 )
              {
                *(_DWORD *)(v6 + 4 * v8) = v11 ^ (v9 ^ v11) & 0xFFFFFF;
              }
              else
              {
                v1 = v36;
                v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v14 = _m_punpcklbw(_mm_cvtsi32_si64(v11), 0i64);
                v15 = _mm_cvtsi32_si64(v12);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _m_punpcklwd(v16, v16);
                *(_DWORD *)(v6 + 4 * v8) = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
              }
            }
            v7 = v35 << 8;
            --v8;
            v35 <<= 8;
          }
          while ( v8 >= 0 );
          v5 = v39;
        }
        while ( v39 );
        v3 = v34;
        v4 = v37;
      }
      if ( v4 )
      {
        v18 = (int)&v32[4 * v3];
        v19 = (int)&v33[16 * v3];
        v40 = v18;
        v20 = v4;
        if ( v4 )
        {
          do
          {
            v21 = *(_BYTE *)(v20-- + v40 - 1);
            v22 = g_SourceColor.u | (v21 << 24);
            v23 = v22 >> 24;
            if ( v1 != 256 )
              v23 = (signed int)(v1 * v23) / 256;
            if ( v23 )
            {
              v24 = *(_DWORD *)(v19 + 4 * v20);
              v25 = v23 + 1;
              if ( v25 == 256 )
              {
                *(_DWORD *)(v19 + 4 * v20) = v24 ^ (v22 ^ v24) & 0xFFFFFF;
              }
              else
              {
                v1 = v36;
                v26 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v27 = _m_punpcklbw(_mm_cvtsi32_si64(v24), 0i64);
                v28 = _mm_cvtsi32_si64(v25);
                v29 = _m_punpcklwd(v28, v28);
                v30 = _m_punpcklwd(v29, v29);
                *(_DWORD *)(v19 + 4 * v20) = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v27, _m_psubw(_m_psrlw(_m_pmullw(v27, v30), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v22), 0i64), v26), _m_pandn(v26, v27)), v30), 8u))), 0i64));
              }
            }
          }
          while ( v20 );
          v4 = v37;
        }
        v3 = v34;
      }
      v31 = v38 == 1;
      v32 += v41;
      v33 += v42;
      --v38;
    }
    while ( !v31 );
  }
  _m_femms();
}

//----- (00664B10) --------------------------------------------------------  // acclient.c:635529
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edi@1
  unsigned int v2; // ecx@2
  unsigned int v3; // esi@2
  int v4; // ecx@2
  int v5; // eax@3
  int v6; // ecx@4
  int v7; // edi@6
  int v8; // ecx@6
  signed int v9; // ebx@6
  unsigned int v10; // esi@7
  unsigned int v11; // eax@7
  unsigned int v12; // eax@10
  int v13; // eax@11
  __m64 v14; // mm2@12
  __m64 v15; // mm0@12
  __m64 v16; // mm3@12
  __m64 v17; // mm4@12
  __m64 v18; // mm3@12
  unsigned int v19; // ST0C_4@12
  int v20; // ebx@17
  int v21; // edi@17
  int v22; // ecx@18
  int v23; // esi@19
  unsigned int v24; // esi@19
  unsigned int v25; // eax@19
  unsigned int v26; // eax@22
  int v27; // eax@23
  __m64 v28; // mm2@24
  __m64 v29; // mm0@24
  __m64 v30; // mm3@24
  __m64 v31; // mm4@24
  __m64 v32; // mm3@24
  unsigned int v33; // ST10_4@24
  bool v34; // zf@27
  unsigned int v35; // [sp+Ch] [bp-34h]@10
  unsigned int v36; // [sp+10h] [bp-30h]@22
  char *v37; // [sp+14h] [bp-2Ch]@1
  char *v38; // [sp+1Ch] [bp-24h]@1
  int v39; // [sp+20h] [bp-20h]@6
  int v40; // [sp+24h] [bp-1Ch]@1
  int v41; // [sp+28h] [bp-18h]@2
  unsigned int v42; // [sp+2Ch] [bp-14h]@2
  unsigned int v43; // [sp+30h] [bp-10h]@2
  int v44; // [sp+34h] [bp-Ch]@6
  unsigned int v45; // [sp+38h] [bp-8h]@2
  unsigned int v46; // [sp+3Ch] [bp-4h]@2

  v37 = i_args->cSrcArgs.pDstBuf;
  v1 = i_args->cDstArgs.pDstBuf;
  v38 = i_args->cDstArgs.pDstBuf;
  v40 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth;
    v3 = v2 >> 2;
    v4 = v2 & 3;
    v42 = v3;
    v41 = v4;
    v45 = i_args->cSrcArgs.iStride;
    v46 = i_args->cDstArgs.iStride;
    v43 = i_args->nHeight;
    do
    {
      v5 = v3;
      if ( v3 )
      {
        v6 = (int)&v1[12 * v3 + 11];
        while ( 1 )
        {
          v7 = *(_DWORD *)&v37[4 * v5 - 4];
          v8 = v6 - 12;
          v39 = v5 - 1;
          v44 = v8;
          v9 = 4;
          do
          {
            v10 = g_SourceColor.u | v7 & 0xFF000000;
            v11 = (g_SourceColor.u | v7 & 0xFF000000) >> 24;
            if ( v40 != 256 )
              v11 = (signed int)(v40 * v11) / 256;
            if ( v11 )
            {
              LOBYTE(v35) = *(_BYTE *)(v8 - 2);
              v12 = v11 + 1;
              BYTE1(v35) = *(_BYTE *)(v8 - 1);
              BYTE2(v35) = *(_BYTE *)v8;
              BYTE3(v35) = -1;
              if ( v12 == 256 )
              {
                v13 = v35 ^ (v10 ^ v35) & 0xFFFFFF;
                *(_BYTE *)(v8 - 2) = v35 ^ g_SourceColor.b ^ v35;
                *(_BYTE *)(v8 - 1) = BYTE1(v13);
                *(_BYTE *)v8 = (unsigned int)v13 >> 16;
              }
              else
              {
                v14 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v15 = _m_punpcklbw(_mm_cvtsi32_si64(v35), 0i64);
                v16 = _mm_cvtsi32_si64(v12);
                v17 = _m_punpcklwd(v16, v16);
                v18 = _m_punpcklwd(v17, v17);
                v19 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v15, _m_psubw(_m_psrlw(_m_pmullw(v15, v18), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v10), 0i64), v14), _m_pandn(v14, v15)), v18), 8u))), 0i64));
                *(_BYTE *)(v8 - 2) = v19;
                *(_BYTE *)(v8 - 1) = BYTE1(v19);
                *(_BYTE *)v8 = v19 >> 16;
              }
            }
            v7 <<= 8;
            v8 -= 3;
            --v9;
          }
          while ( v9 );
          if ( !v39 )
            break;
          v6 = v44;
          v5 = v39;
        }
        v4 = v41;
        v3 = v42;
      }
      if ( v4 )
      {
        v20 = (int)&v37[4 * v3];
        v21 = v4;
        if ( v4 )
        {
          v22 = (int)(&v38[12 * v3 + 2] + 2 * v4 + v4);
          do
          {
            v23 = *(_BYTE *)(v21-- + v20 - 1);
            v24 = g_SourceColor.u | (v23 << 24);
            v22 -= 3;
            v25 = v24 >> 24;
            if ( v40 != 256 )
              v25 = (signed int)(v40 * v25) / 256;
            if ( v25 )
            {
              LOBYTE(v36) = *(_BYTE *)(v22 - 2);
              v26 = v25 + 1;
              BYTE1(v36) = *(_BYTE *)(v22 - 1);
              BYTE2(v36) = *(_BYTE *)v22;
              BYTE3(v36) = -1;
              if ( v26 == 256 )
              {
                v27 = v36 ^ (v24 ^ v36) & 0xFFFFFF;
                *(_BYTE *)(v22 - 2) = v36 ^ v24 ^ v36;
                *(_BYTE *)(v22 - 1) = BYTE1(v27);
                *(_BYTE *)v22 = (unsigned int)v27 >> 16;
              }
              else
              {
                v28 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v29 = _m_punpcklbw(_mm_cvtsi32_si64(v36), 0i64);
                v30 = _mm_cvtsi32_si64(v26);
                v31 = _m_punpcklwd(v30, v30);
                v32 = _m_punpcklwd(v31, v31);
                v33 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v29, _m_psubw(_m_psrlw(_m_pmullw(v29, v32), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v24), 0i64), v28), _m_pandn(v28, v29)), v32), 8u))), 0i64));
                *(_BYTE *)(v22 - 2) = v33;
                *(_BYTE *)(v22 - 1) = BYTE1(v33);
                *(_BYTE *)v22 = v33 >> 16;
              }
            }
          }
          while ( v21 );
          v4 = v41;
          v3 = v42;
        }
      }
      v37 += v45;
      v1 = &v38[v46];
      v34 = v43 == 1;
      v38 += v46;
      --v43;
    }
    while ( !v34 );
  }
  _m_femms();
}

//----- (00664E30) --------------------------------------------------------  // acclient.c:635711
void __cdecl ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@2
  int v2; // ebx@2
  unsigned int v3; // esi@3
  int v4; // esi@5
  int v5; // edi@5
  int v6; // ecx@6
  unsigned int v7; // ecx@6
  unsigned int v8; // eax@6
  unsigned int v9; // edx@9
  unsigned int v10; // eax@9
  __m64 v11; // mm2@11
  __m64 v12; // mm0@11
  __m64 v13; // mm3@11
  __m64 v14; // mm4@11
  __m64 v15; // mm3@11
  bool v16; // zf@14
  char *v17; // esi@16
  unsigned int v18; // eax@18
  unsigned int v19; // edx@21
  __m64 v20; // mm2@23
  __m64 v21; // mm0@23
  __m64 v22; // mm3@23
  __m64 v23; // mm4@23
  __m64 v24; // mm3@23
  char *v25; // [sp+Ch] [bp-24h]@2
  unsigned int v26; // [sp+Ch] [bp-24h]@16
  unsigned int v27; // [sp+10h] [bp-20h]@3
  unsigned int v28; // [sp+10h] [bp-20h]@17
  unsigned int v29; // [sp+14h] [bp-1Ch]@5
  unsigned int v30; // [sp+18h] [bp-18h]@3
  char *v31; // [sp+1Ch] [bp-14h]@2
  unsigned int v32; // [sp+20h] [bp-10h]@3
  unsigned int v33; // [sp+20h] [bp-10h]@17
  int v34; // [sp+28h] [bp-8h]@2
  unsigned int v35; // [sp+28h] [bp-8h]@19
  unsigned int v36; // [sp+2Ch] [bp-4h]@3
  unsigned int v37; // [sp+2Ch] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v25 = i_args->cSrcArgs.pDstBuf;
    v31 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    v34 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v30 = i_args->nWidth;
      v36 = i_args->cSrcArgs.iStride;
      v27 = i_args->cDstArgs.iStride;
      v32 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v5 = v25 - v1;
          v29 = v30;
          do
          {
            v6 = *(_DWORD *)(v5 + v4 - 4);
            v4 -= 4;
            v7 = g_SourceColor.u | v6 & 0xFF000000;
            v8 = v7 >> 24;
            if ( v2 != 256 )
              v8 = (signed int)(v2 * v8) / 256;
            if ( v8 )
            {
              v9 = *(_DWORD *)v4;
              v10 = v8 + 1;
              if ( v10 == 256 )
              {
                *(_DWORD *)v4 = v9 ^ (v7 ^ v9) & 0xFFFFFF;
              }
              else
              {
                v2 = v34;
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v12 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                v13 = _mm_cvtsi32_si64(v10);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                *(_DWORD *)v4 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v15), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64), v11), _m_pandn(v11, v12)), v15), 8u))), 0i64));
              }
            }
            --v29;
          }
          while ( v29 );
          v1 = v31;
          v3 = v30;
        }
        v1 += v27;
        v16 = v32 == 1;
        v25 += v36;
        v31 = v1;
        --v32;
      }
      while ( !v16 );
    }
  }
  else
  {
    v17 = i_args->cDstArgs.pDstBuf;
    v26 = g_SourceColor.u;
    BYTE3(v26) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v37 = i_args->nWidth;
      v28 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        v18 = v37;
        if ( v37 )
        {
          v35 = v26 >> 24;
          do
          {
            --v18;
            if ( v35 )
            {
              v19 = *(_DWORD *)&v17[4 * v18];
              if ( v35 == 255 )
              {
                *(_DWORD *)&v17[4 * v18] = v19 ^ (v26 ^ v19) & 0xFFFFFF;
              }
              else
              {
                v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
                v22 = _mm_cvtsi32_si64(v35 + 1);
                v23 = _m_punpcklwd(v22, v22);
                v24 = _m_punpcklwd(v23, v23);
                *(_DWORD *)&v17[4 * v18] = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v24), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), v20), _m_pandn(v20, v21)), v24), 8u))), 0i64));
              }
            }
          }
          while ( v18 );
        }
        v17 -= v28;
        --v33;
      }
      while ( v33 );
    }
  }
  _m_femms();
}

//----- (006650B0) --------------------------------------------------------  // acclient.c:635863
void __cdecl ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // ecx@5
  int v5; // esi@6
  unsigned int v6; // esi@6
  unsigned int v7; // eax@6
  unsigned int v8; // eax@9
  int v9; // eax@10
  __m64 v10; // mm2@11
  __m64 v11; // mm0@11
  __m64 v12; // mm3@11
  __m64 v13; // mm4@11
  __m64 v14; // mm3@11
  unsigned int v15; // ST10_4@11
  bool v16; // zf@13
  char *v17; // edx@15
  unsigned int v18; // ebx@16
  unsigned int v19; // edi@18
  int v20; // eax@18
  int v21; // ecx@21
  __m64 v22; // mm2@22
  __m64 v23; // mm0@22
  __m64 v24; // mm3@22
  __m64 v25; // mm4@22
  __m64 v26; // mm3@22
  unsigned int v27; // ST10_4@22
  unsigned int v28; // [sp+10h] [bp-20h]@9
  unsigned int v29; // [sp+10h] [bp-20h]@20
  char *v30; // [sp+14h] [bp-1Ch]@2
  unsigned int v31; // [sp+14h] [bp-1Ch]@15
  unsigned int v32; // [sp+18h] [bp-18h]@3
  unsigned int v33; // [sp+18h] [bp-18h]@16
  char *v34; // [sp+1Ch] [bp-14h]@2
  char *v35; // [sp+1Ch] [bp-14h]@15
  unsigned int v36; // [sp+20h] [bp-10h]@3
  unsigned int v37; // [sp+20h] [bp-10h]@18
  unsigned int v38; // [sp+24h] [bp-Ch]@3
  unsigned int v39; // [sp+24h] [bp-Ch]@16
  unsigned int v40; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v30 = i_args->cSrcArgs.pDstBuf;
    v34 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v38 = i_args->nWidth;
      v40 = i_args->cSrcArgs.iStride;
      v32 = i_args->cDstArgs.iStride;
      v36 = i_args->nHeight;
      do
      {
        v3 = v38;
        if ( v38 )
        {
          v4 = (int)(&v1[2 * v38 + 2] + v38);
          do
          {
            v5 = *(_DWORD *)&v30[4 * v3-- - 4];
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v4 -= 3;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              LOBYTE(v28) = *(_BYTE *)(v4 - 2);
              v8 = v7 + 1;
              BYTE1(v28) = *(_BYTE *)(v4 - 1);
              BYTE2(v28) = *(_BYTE *)v4;
              BYTE3(v28) = -1;
              if ( v8 == 256 )
              {
                v9 = v28 ^ (v6 ^ v28) & 0xFFFFFF;
                *(_BYTE *)(v4 - 2) = v28 ^ v6 ^ v28;
                *(_BYTE *)(v4 - 1) = BYTE1(v9);
                *(_BYTE *)v4 = (unsigned int)v9 >> 16;
              }
              else
              {
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
                v12 = _mm_cvtsi32_si64(v8);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
                *(_BYTE *)(v4 - 2) = v15;
                *(_BYTE *)(v4 - 1) = BYTE1(v15);
                *(_BYTE *)v4 = v15 >> 16;
              }
            }
          }
          while ( v3 );
        }
        v1 = &v34[v32];
        v16 = v36 == 1;
        v30 += v40;
        v34 += v32;
        --v36;
      }
      while ( !v16 );
    }
  }
  else
  {
    v17 = i_args->cDstArgs.pDstBuf;
    v31 = g_SourceColor.u;
    BYTE3(v31) = i_args->i8AlphaModifier;
    v35 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v18 = i_args->nWidth;
      v33 = i_args->cDstArgs.iStride;
      v39 = i_args->nHeight;
      do
      {
        if ( v18 )
        {
          v19 = v31 >> 24;
          v20 = (int)(&v17[2 * v18 + 2] + v18);
          v37 = v18;
          do
          {
            v20 -= 3;
            if ( v19 )
            {
              LOBYTE(v29) = *(_BYTE *)(v20 - 2);
              BYTE1(v29) = *(_BYTE *)(v20 - 1);
              BYTE2(v29) = *(_BYTE *)v20;
              BYTE3(v29) = -1;
              if ( v19 == 255 )
              {
                v21 = v29 ^ (v31 ^ v29) & 0xFFFFFF;
                *(_BYTE *)(v20 - 2) = v29 ^ v31 ^ v29;
                *(_BYTE *)(v20 - 1) = BYTE1(v21);
                *(_BYTE *)v20 = (unsigned int)v21 >> 16;
              }
              else
              {
                v22 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                v23 = _m_punpcklbw(_mm_cvtsi32_si64(v29), 0i64);
                v24 = _mm_cvtsi32_si64(v19 + 1);
                v25 = _m_punpcklwd(v24, v24);
                v26 = _m_punpcklwd(v25, v25);
                v27 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v23, _m_psubw(_m_psrlw(_m_pmullw(v23, v26), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v31), 0i64), v22), _m_pandn(v22, v23)), v26), 8u))), 0i64));
                *(_BYTE *)(v20 - 2) = v27;
                *(_BYTE *)(v20 - 1) = BYTE1(v27);
                *(_BYTE *)v20 = v27 >> 16;
              }
            }
            --v37;
          }
          while ( v37 );
        }
        v17 = &v35[-v33];
        v16 = v39 == 1;
        v35 -= v33;
        --v39;
      }
      while ( !v16 );
    }
  }
  _m_femms();
}

//----- (006653A0) --------------------------------------------------------  // acclient.c:636034
void __cdecl ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  int v1; // esi@2
  __int16 v2; // bx@3
  unsigned int v3; // ecx@4
  int v4; // eax@6
  int v5; // ebp@6
  int v6; // esi@9
  int v7; // edi@9
  int v8; // ecx@9
  int v9; // eax@9
  signed int v10; // ebx@9
  int v11; // esi@9
  int v12; // eax@9
  int v13; // edi@9
  signed int v14; // esi@18
  int v15; // ebx@18
  signed int v16; // ebp@19
  int v17; // ecx@20
  int v18; // ecx@26
  int v19; // edx@33
  int v20; // ebx@35
  int v21; // ebp@35
  signed int v22; // esi@35
  int v23; // edi@35
  int v24; // eax@35
  int v25; // edx@48
  int v26; // esi@48
  bool v27; // zf@52
  int v28; // ebx@54
  int v29; // ebp@54
  signed int v30; // esi@54
  int v31; // edi@54
  int v32; // eax@54
  unsigned int v33; // eax@67
  int v34; // ecx@69
  int v35; // edx@69
  signed int v36; // ebx@69
  int v37; // esi@69
  int v38; // edi@69
  int v39; // eax@69
  signed int v40; // esi@78
  int v41; // ebp@78
  signed int v42; // ebp@79
  int v43; // ecx@80
  int v44; // ecx@86
  int v45; // edx@93
  int v46; // ebx@95
  int v47; // ebp@95
  signed int v48; // esi@95
  int v49; // edi@95
  int v50; // eax@95
  int v51; // esi@108
  int v52; // edx@108
  int v53; // ebx@114
  int v54; // ebp@114
  signed int v55; // esi@114
  int v56; // edi@114
  int v57; // eax@114
  int v58; // [sp+10h] [bp-48h]@0
  int pixSrc; // [sp+14h] [bp-44h]@18
  BlitPixel pixSrca; // [sp+14h] [bp-44h]@65
  char *pDst; // [sp+18h] [bp-40h]@2
  int pDsta; // [sp+18h] [bp-40h]@78
  int v63; // [sp+1Ch] [bp-3Ch]@0
  char *v64; // [sp+1Ch] [bp-3Ch]@65
  int v65; // [sp+20h] [bp-38h]@0
  int v66; // [sp+24h] [bp-34h]@0
  int v67; // [sp+28h] [bp-30h]@0
  int v68; // [sp+2Ch] [bp-2Ch]@0
  int v69; // [sp+30h] [bp-28h]@0
  int v70; // [sp+30h] [bp-28h]@6
  unsigned int v71; // [sp+34h] [bp-24h]@3
  unsigned int v72; // [sp+34h] [bp-24h]@66
  unsigned int v73; // [sp+38h] [bp-20h]@3
  unsigned int v74; // [sp+38h] [bp-20h]@66
  signed int v75; // [sp+3Ch] [bp-1Ch]@17
  unsigned int v76; // [sp+3Ch] [bp-1Ch]@68
  unsigned int idxX; // [sp+40h] [bp-18h]@6
  unsigned int idxXa; // [sp+40h] [bp-18h]@68
  unsigned int v79; // [sp+44h] [bp-14h]@3
  signed int v80; // [sp+44h] [bp-14h]@77
  int v81; // [sp+48h] [bp-10h]@5
  unsigned int v82; // [sp+48h] [bp-10h]@66
  int iModifier; // [sp+54h] [bp-4h]@2
  BlitArgs *i_argsa; // [sp+5Ch] [bp+4h]@9
  BlitArgs *i_argsb; // [sp+5Ch] [bp+4h]@69

  if ( i_args->cSrcArgs.pDstBuf )
  {
    pDst = i_args->cDstArgs.pDstBuf;
    v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    iModifier = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v2 = *(_WORD *)&g_SourceColor;
      v71 = i_args->nWidth;
      v73 = i_args->cDstArgs.iStride;
      v79 = i_args->nHeight;
      do
      {
        v3 = v71;
        if ( v71 )
        {
          v81 = BYTE3(g_SourceColor.u);
          do
          {
            --v3;
            v4 = v81 != 0;
            idxX = v3;
            v5 = v4 + v81;
            v70 = v4 + v81;
            if ( v1 != 256 )
            {
              v5 = v1 * v5 / 256;
              v70 = v5;
            }
            if ( v5 )
            {
              v6 = HIBYTE(v2);
              i_argsa = *(BlitArgs **)&pDst[4 * v3];
              v7 = (unsigned __int8)v2;
              v8 = (g_SourceColor.r != 0) + (unsigned __int8)g_SourceColor.r;
              v9 = HIBYTE(v2) != 0;
              v10 = v8;
              v11 = v9 + v6;
              v12 = (g_SourceColor.r != 0) + (unsigned __int8)g_SourceColor.r;
              v13 = (v7 != 0) + v7;
              if ( v11 <= v8 )
              {
                if ( v11 < v8 )
                  v12 = v11;
              }
              else
              {
                v10 = v11;
              }
              if ( v13 <= v10 )
              {
                if ( v13 < v12 )
                  v12 = v13;
              }
              else
              {
                v10 = v13;
              }
              v75 = v10 - v12;
              if ( v10 == v12 )
              {
                v14 = 0;
                v15 = 0;
                pixSrc = 0;
              }
              else
              {
                v16 = 0;
                pixSrc = (v75 << 8) / v10;
                if ( v8 == v10 )
                {
                  v17 = v11 - v13;
                  if ( v11 - v13 < 0 )
                    v16 = 24576;
                }
                else if ( v11 == v10 )
                {
                  v17 = v13 - v8;
                  v16 = 0x2000;
                }
                else
                {
                  v17 = v8 - v11;
                  v16 = 0x4000;
                }
                v15 = (v75 << 8) / v10;
                v14 = v16 + (v17 << 12) / v75;
                v5 = v70;
              }
              v18 = BYTE2(i_argsa) + (BYTE2(i_argsa) != 0);
              if ( (BYTE1(i_argsa) != 0) + BYTE1(i_argsa) > v18 )
                v18 = (BYTE1(i_argsa) != 0) + BYTE1(i_argsa);
              if ( ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa > v18 )
                v18 = ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa;
              if ( v5 == 256 )
              {
                if ( v15 )
                {
                  v20 = v14 / 4096;
                  v21 = pixSrc * v18 / 256;
                  v22 = v21 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                  v23 = v18 - v21;
                  v24 = v22 / 4096;
                  if ( v22 % 4096 < -2048 )
                    --v24;
                  if ( v22 % 4096 > 2048 )
                    ++v24;
                  switch ( v20 )
                  {
                    case 0:
                      v19 = v18;
                      v58 = v18 - v21;
                      v18 = v23 + v24;
                      break;
                    case 1:
                      v58 = v18 - v21;
                      v19 = v23 - v24;
                      break;
                    case 2:
                      v19 = v18 - v21;
                      v58 = v24 + v23;
                      break;
                    case 3:
                      v19 = v18 - v21;
                      v58 = v18;
                      v18 = v23 - v24;
                      break;
                    case 4:
                      v58 = v18;
                      v18 -= v21;
                      v19 = v23 + v24;
                      break;
                    case 5:
                      v19 = v18;
                      v18 -= v21;
                      v58 = v23 - v24;
                      break;
                    default:
                      goto LABEL_33;
                  }
                }
                else
                {
                  v63 = v18;
                  v65 = v18;
                  v58 = v18;
LABEL_33:
                  v19 = v63;
                  v18 = v65;
                }
                v63 = v19 - (v19 != 0);
                BYTE2(i_argsa) = v19 - (v19 != 0);
                v65 = v18 - (v18 != 0);
                BYTE1(i_argsa) = v18 - (v18 != 0);
                v58 -= v58 != 0;
                LOBYTE(i_argsa) = v58;
              }
              else
              {
                if ( v15 )
                {
                  v28 = v14 / 4096;
                  v29 = pixSrc * v18 / 256;
                  v30 = v29 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                  v31 = v18 - v29;
                  v32 = v30 / 4096;
                  if ( v30 % 4096 < -2048 )
                    --v32;
                  if ( v30 % 4096 > 2048 )
                    ++v32;
                  switch ( v28 )
                  {
                    case 0:
                      v25 = v18;
                      v26 = v18 - v29;
                      v18 = v31 + v32;
                      break;
                    case 1:
                      v26 = v18 - v29;
                      v25 = v31 - v32;
                      break;
                    case 2:
                      v25 = v18 - v29;
                      v26 = v31 + v32;
                      break;
                    case 3:
                      v25 = v18 - v29;
                      v26 = v18;
                      v18 = v31 - v32;
                      break;
                    case 4:
                      v26 = v18;
                      v18 -= v29;
                      v25 = v31 + v32;
                      break;
                    case 5:
                      v25 = v18;
                      v18 -= v29;
                      v26 = v31 - v32;
                      break;
                    default:
                      goto LABEL_48;
                  }
                }
                else
                {
                  v66 = v18;
                  v67 = v18;
                  v68 = v18;
LABEL_48:
                  v25 = v66;
                  v18 = v67;
                  v26 = v68;
                }
                v66 = v25 - (v25 != 0);
                v67 = v18 - (v18 != 0);
                BYTE2(i_argsa) -= v70 * (BYTE2(i_argsa) - v66) / 256;
                v68 = v26 - (v26 != 0);
                BYTE1(i_argsa) -= v70 * (BYTE1(i_argsa) - v67) / 256;
                LOBYTE(i_argsa) = (_BYTE)i_argsa - v70 * ((unsigned __int8)i_argsa - v68) / 256;
              }
              v1 = iModifier;
              v2 = *(_WORD *)&g_SourceColor;
              *(_DWORD *)&pDst[4 * idxX] = i_argsa;
              v3 = idxX;
            }
          }
          while ( v3 );
        }
        v27 = v79 == 1;
        pDst += v73;
        --v79;
      }
      while ( !v27 );
    }
  }
  else
  {
    pixSrca = g_SourceColor;
    v64 = i_args->cDstArgs.pDstBuf;
    pixSrca.a = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v72 = i_args->nWidth;
      v74 = i_args->cDstArgs.iStride;
      v82 = i_args->nHeight;
      do
      {
        v33 = v72;
        while ( v33 )
        {
          --v33;
          v76 = v33;
          idxXa = (pixSrca.u >> 24 != 0) + (pixSrca.u >> 24);
          if ( idxXa )
          {
            i_argsb = *(BlitArgs **)&v64[4 * v33];
            v34 = (pixSrca.r != 0) + (unsigned __int8)pixSrca.r;
            v35 = pixSrca.g != 0;
            v36 = v34;
            v37 = v35 + (unsigned __int8)pixSrca.g;
            v38 = (pixSrca.b != 0) + (unsigned __int8)pixSrca.b;
            v39 = (pixSrca.r != 0) + (unsigned __int8)pixSrca.r;
            if ( v37 <= v34 )
            {
              if ( v37 < v34 )
                v39 = v35 + (unsigned __int8)pixSrca.g;
            }
            else
            {
              v36 = v35 + (unsigned __int8)pixSrca.g;
            }
            if ( v38 <= v36 )
            {
              if ( v38 < v39 )
                v39 = (pixSrca.b != 0) + (unsigned __int8)pixSrca.b;
            }
            else
            {
              v36 = (pixSrca.b != 0) + (unsigned __int8)pixSrca.b;
            }
            v80 = v36 - v39;
            if ( v36 == v39 )
            {
              v40 = 0;
              v41 = 0;
              pDsta = 0;
            }
            else
            {
              v42 = 0;
              pDsta = (v80 << 8) / v36;
              if ( v34 == v36 )
              {
                v43 = v37 - v38;
                if ( v37 - v38 < 0 )
                  v42 = 24576;
              }
              else if ( v37 == v36 )
              {
                v43 = v38 - v34;
                v42 = 0x2000;
              }
              else
              {
                v43 = v34 - v37;
                v42 = 0x4000;
              }
              v40 = v42 + (v43 << 12) / v80;
              v41 = (v80 << 8) / v36;
            }
            v44 = BYTE2(i_argsb) + (BYTE2(i_argsb) != 0);
            if ( (BYTE1(i_argsb) != 0) + BYTE1(i_argsb) > v44 )
              v44 = (BYTE1(i_argsb) != 0) + BYTE1(i_argsb);
            if ( ((unsigned __int8)i_argsb != 0) + (unsigned __int8)i_argsb > v44 )
              v44 = ((unsigned __int8)i_argsb != 0) + (unsigned __int8)i_argsb;
            if ( idxXa == 256 )
            {
              if ( v41 )
              {
                v46 = v40 / 4096;
                v47 = pDsta * v44 / 256;
                v48 = v47 * (v40 - ((v40 / 4096 + 1) / 2 << 13));
                v49 = v44 - v47;
                v50 = v48 / 4096;
                if ( v48 % 4096 < -2048 )
                  --v50;
                if ( v48 % 4096 > 2048 )
                  ++v50;
                switch ( v46 )
                {
                  case 0:
                    v45 = v44;
                    v58 = v44 - v47;
                    v44 = v49 + v50;
                    break;
                  case 1:
                    v58 = v44 - v47;
                    v45 = v49 - v50;
                    break;
                  case 2:
                    v45 = v44 - v47;
                    v58 = v50 + v49;
                    break;
                  case 3:
                    v45 = v44 - v47;
                    v58 = v44;
                    v44 = v49 - v50;
                    break;
                  case 4:
                    v58 = v44;
                    v44 -= v47;
                    v45 = v49 + v50;
                    break;
                  case 5:
                    v45 = v44;
                    v44 -= v47;
                    v58 = v49 - v50;
                    break;
                  default:
                    goto LABEL_93;
                }
              }
              else
              {
                v69 = v44;
                v68 = v44;
                v58 = v44;
LABEL_93:
                v45 = v69;
                v44 = v68;
              }
              v69 = v45 - (v45 != 0);
              BYTE2(i_argsb) = v45 - (v45 != 0);
              v68 = v44 - (v44 != 0);
              BYTE1(i_argsb) = v44 - (v44 != 0);
              v58 -= v58 != 0;
              LOBYTE(i_argsb) = v58;
            }
            else
            {
              if ( v41 )
              {
                v53 = v40 / 4096;
                v54 = pDsta * v44 / 256;
                v55 = v54 * (v40 - ((v40 / 4096 + 1) / 2 << 13));
                v56 = v44 - v54;
                v57 = v55 / 4096;
                if ( v55 % 4096 < -2048 )
                  --v57;
                if ( v55 % 4096 > 2048 )
                  ++v57;
                switch ( v53 )
                {
                  case 0:
                    v52 = v44;
                    v51 = v44 - v54;
                    v44 = v56 + v57;
                    break;
                  case 1:
                    v51 = v44 - v54;
                    v52 = v56 - v57;
                    break;
                  case 2:
                    v52 = v44 - v54;
                    v51 = v56 + v57;
                    break;
                  case 3:
                    v52 = v44 - v54;
                    v51 = v44;
                    v44 = v56 - v57;
                    break;
                  case 4:
                    v51 = v44;
                    v44 -= v54;
                    v52 = v56 + v57;
                    break;
                  case 5:
                    v52 = v44;
                    v44 -= v54;
                    v51 = v56 - v57;
                    break;
                  default:
                    goto LABEL_108;
                }
              }
              else
              {
                v67 = v44;
                v66 = v44;
                v65 = v44;
LABEL_108:
                v51 = v65;
                v44 = v66;
                v52 = v67;
              }
              v67 = v52 - (v52 != 0);
              v66 = v44 - (v44 != 0);
              BYTE2(i_argsb) -= (signed int)(idxXa * (BYTE2(i_argsb) - v67)) / 256;
              v65 = v51 - (v51 != 0);
              BYTE1(i_argsb) -= (signed int)(idxXa * (BYTE1(i_argsb) - v66)) / 256;
              LOBYTE(i_argsb) = (_BYTE)i_argsb - (signed int)(idxXa * ((unsigned __int8)i_argsb - v65)) / 256;
            }
            v33 = v76;
            *(_DWORD *)&v64[4 * v76] = i_argsb;
          }
        }
        v27 = v82 == 1;
        v64 -= v74;
        --v82;
      }
      while ( !v27 );
    }
  }
  _m_femms();
}

//----- (00665CB0) --------------------------------------------------------  // acclient.c:636580
void __cdecl ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@2
  int v2; // edi@2
  unsigned int v3; // ebp@3
  __int16 v4; // bx@3
  int v5; // ecx@5
  int v6; // eax@6
  int v7; // esi@6
  int v8; // ecx@9
  signed int v9; // ebp@9
  int v10; // esi@9
  int v11; // edx@9
  int v12; // eax@9
  int v13; // edi@9
  signed int v14; // esi@18
  int v15; // ebp@18
  signed int v16; // ebx@19
  int v17; // ecx@20
  int v18; // ecx@26
  int v19; // edx@33
  int v20; // edx@34
  int v21; // ecx@34
  char v22; // bl@34
  char v23; // cl@34
  int v24; // ebx@35
  int v25; // ebp@35
  signed int v26; // esi@35
  int v27; // edi@35
  int v28; // eax@35
  int v29; // esi@48
  int v30; // ecx@49
  bool v31; // zf@52
  int v32; // ebx@54
  int v33; // ebp@54
  signed int v34; // esi@54
  int v35; // edi@54
  int v36; // eax@54
  char *v37; // esi@65
  unsigned int v38; // ecx@66
  int v39; // eax@68
  int v40; // edx@69
  int v41; // ebx@69
  int v42; // ecx@70
  signed int v43; // ebp@70
  int v44; // esi@70
  int v45; // edx@70
  int v46; // eax@70
  int v47; // edi@70
  signed int v48; // esi@79
  int v49; // ebp@79
  signed int v50; // ebx@80
  int v51; // ecx@81
  int v52; // ecx@87
  int v53; // edx@94
  int v54; // ebx@94
  int v55; // edx@95
  int v56; // ebx@95
  char v57; // cl@95
  char v58; // dl@95
  char v59; // bl@95
  int v60; // ebx@96
  int v61; // ebp@96
  signed int v62; // esi@96
  int v63; // edi@96
  int v64; // eax@96
  int v65; // ebp@109
  int v66; // esi@109
  int v67; // edx@109
  int v68; // edx@110
  int v69; // ebx@115
  int v70; // ebp@115
  signed int v71; // esi@115
  int v72; // edi@115
  int v73; // eax@115
  unsigned __int8 v74; // [sp+10h] [bp-50h]@9
  unsigned __int8 v75; // [sp+10h] [bp-50h]@70
  unsigned __int8 v76; // [sp+11h] [bp-4Fh]@9
  unsigned __int8 v77; // [sp+11h] [bp-4Fh]@70
  unsigned __int8 v78; // [sp+12h] [bp-4Eh]@9
  unsigned __int8 v79; // [sp+12h] [bp-4Eh]@70
  int pixSrc; // [sp+14h] [bp-4Ch]@18
  BlitPixel pixSrca; // [sp+14h] [bp-4Ch]@65
  int v82; // [sp+18h] [bp-48h]@0
  int v83; // [sp+18h] [bp-48h]@79
  int v84; // [sp+1Ch] [bp-44h]@0
  int v85; // [sp+20h] [bp-40h]@0
  int v86; // [sp+24h] [bp-3Ch]@0
  int v87; // [sp+28h] [bp-38h]@0
  int v88; // [sp+2Ch] [bp-34h]@0
  int v89; // [sp+2Ch] [bp-34h]@6
  unsigned int v90; // [sp+30h] [bp-30h]@3
  unsigned int v91; // [sp+30h] [bp-30h]@66
  signed int v92; // [sp+34h] [bp-2Ch]@17
  char *v93; // [sp+34h] [bp-2Ch]@65
  int v94; // [sp+38h] [bp-28h]@6
  unsigned int v95; // [sp+38h] [bp-28h]@68
  unsigned int v96; // [sp+3Ch] [bp-24h]@5
  int v97; // [sp+3Ch] [bp-24h]@69
  char *pDst; // [sp+40h] [bp-20h]@2
  char *pDsta; // [sp+40h] [bp-20h]@69
  unsigned int v100; // [sp+44h] [bp-1Ch]@3
  signed int v101; // [sp+44h] [bp-1Ch]@78
  int v102; // [sp+48h] [bp-18h]@5
  unsigned int v103; // [sp+48h] [bp-18h]@66
  int iModifier; // [sp+54h] [bp-Ch]@2
  unsigned int idxX; // [sp+58h] [bp-8h]@3
  unsigned int idxXa; // [sp+58h] [bp-8h]@68
  unsigned int v107; // [sp+5Ch] [bp-4h]@66

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    pDst = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    iModifier = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v4 = *(_WORD *)&g_SourceColor;
      idxX = i_args->nWidth;
      v90 = i_args->cDstArgs.iStride;
      v100 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v102 = BYTE3(g_SourceColor.u);
          v5 = (int)(&v1[2 * v3 + 2] + v3);
          v96 = v3;
          do
          {
            v5 -= 3;
            v6 = v102 != 0;
            v94 = v5;
            v7 = v6 + v102;
            v89 = v6 + v102;
            if ( v2 != 256 )
            {
              v7 = v2 * v7 / 256;
              v89 = v7;
            }
            if ( v7 )
            {
              v78 = *(_BYTE *)v5;
              v74 = *(_BYTE *)(v5 - 2);
              v76 = *(_BYTE *)(v5 - 1);
              v8 = (g_SourceColor.r != 0) + (unsigned __int8)g_SourceColor.r;
              v9 = v8;
              v10 = (HIBYTE(v4) != 0) + HIBYTE(v4);
              v11 = (unsigned __int8)v4 != 0;
              v12 = (g_SourceColor.r != 0) + (unsigned __int8)g_SourceColor.r;
              v13 = v11 + (unsigned __int8)v4;
              if ( v10 <= v8 )
              {
                if ( v10 < v8 )
                  v12 = (HIBYTE(v4) != 0) + HIBYTE(v4);
              }
              else
              {
                v9 = (HIBYTE(v4) != 0) + HIBYTE(v4);
              }
              if ( v13 <= v9 )
              {
                if ( v13 < v12 )
                  v12 = v11 + (unsigned __int8)v4;
              }
              else
              {
                v9 = v11 + (unsigned __int8)v4;
              }
              v92 = v9 - v12;
              if ( v9 == v12 )
              {
                v14 = 0;
                v15 = 0;
                pixSrc = 0;
              }
              else
              {
                v16 = 0;
                pixSrc = (v92 << 8) / v9;
                if ( v8 == v9 )
                {
                  v17 = v10 - v13;
                  if ( v10 - v13 < 0 )
                    v16 = 24576;
                }
                else if ( v10 == v9 )
                {
                  v17 = v13 - v8;
                  v16 = 0x2000;
                }
                else
                {
                  v17 = v8 - v10;
                  v16 = 0x4000;
                }
                v15 = (v92 << 8) / v9;
                v14 = v16 + (v17 << 12) / v92;
              }
              v18 = v78 + (v78 != 0);
              if ( (v76 != 0) + v76 > v18 )
                v18 = (v76 != 0) + v76;
              if ( (v74 != 0) + v74 > v18 )
                v18 = (v74 != 0) + v74;
              if ( v89 == 256 )
              {
                if ( v15 )
                {
                  v24 = v14 / 4096;
                  v25 = pixSrc * v18 / 256;
                  v26 = v25 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                  v27 = v18 - v25;
                  v28 = v26 / 4096;
                  if ( v26 % 4096 < -2048 )
                    --v28;
                  if ( v26 % 4096 > 2048 )
                    ++v28;
                  switch ( v24 )
                  {
                    case 0:
                      v19 = v18;
                      i_args = (BlitArgs *)(v18 - v25);
                      v18 = v27 + v28;
                      break;
                    case 1:
                      i_args = (BlitArgs *)(v18 - v25);
                      v19 = v27 - v28;
                      break;
                    case 2:
                      v19 = v18 - v25;
                      i_args = (BlitArgs *)(v28 + v27);
                      break;
                    case 3:
                      v19 = v18 - v25;
                      i_args = (BlitArgs *)v18;
                      v18 = v27 - v28;
                      break;
                    case 4:
                      i_args = (BlitArgs *)v18;
                      v18 -= v25;
                      v19 = v27 + v28;
                      break;
                    case 5:
                      v19 = v18;
                      v18 -= v25;
                      i_args = (BlitArgs *)(v27 - v28);
                      break;
                    default:
                      goto LABEL_33;
                  }
                }
                else
                {
                  v82 = v18;
                  v84 = v18;
                  i_args = (BlitArgs *)v18;
LABEL_33:
                  v18 = v84;
                  v19 = v82;
                }
                v20 = v19 - (v19 != 0);
                v82 = v20;
                v21 = v18 - (v18 != 0);
                v84 = v21;
                v22 = v21;
                i_args = (BlitArgs *)((char *)i_args - (i_args != 0));
                v23 = (char)i_args;
              }
              else
              {
                if ( v15 )
                {
                  v32 = v14 / 4096;
                  v33 = pixSrc * v18 / 256;
                  v34 = v33 * (v14 - ((v14 / 4096 + 1) / 2 << 13));
                  v35 = v18 - v33;
                  v36 = v34 / 4096;
                  if ( v34 % 4096 < -2048 )
                    --v36;
                  if ( v34 % 4096 > 2048 )
                    ++v36;
                  switch ( v32 )
                  {
                    case 0:
                      v20 = v18;
                      v29 = v18 - v33;
                      v18 = v35 + v36;
                      break;
                    case 1:
                      v29 = v18 - v33;
                      v20 = v35 - v36;
                      break;
                    case 2:
                      v20 = v18 - v33;
                      v29 = v35 + v36;
                      break;
                    case 3:
                      v20 = v18 - v33;
                      v29 = v18;
                      v18 = v35 - v36;
                      break;
                    case 4:
                      v29 = v18;
                      v18 -= v33;
                      v20 = v35 + v36;
                      break;
                    case 5:
                      v20 = v18;
                      v18 -= v33;
                      v29 = v35 - v36;
                      break;
                    default:
                      goto LABEL_48;
                  }
                }
                else
                {
                  v85 = v18;
                  v86 = v18;
                  v87 = v18;
LABEL_48:
                  v20 = v85;
                  v18 = v86;
                  v29 = v87;
                }
                v85 = v20 - (v20 != 0);
                v30 = v18 - (v18 != 0);
                v86 = v30;
                v22 = v76 - v89 * (v76 - v30) / 256;
                LOBYTE(v20) = v78 - v89 * (v78 - v85) / 256;
                v87 = v29 - (v29 != 0);
                v23 = v74 - v89 * (v74 - v87) / 256;
              }
              v2 = iModifier;
              v3 = idxX;
              *(_BYTE *)(v94 - 2) = v23;
              *(_BYTE *)(v94 - 1) = v22;
              v4 = *(_WORD *)&g_SourceColor;
              *(_BYTE *)v94 = v20;
              v5 = v94;
            }
            --v96;
          }
          while ( v96 );
        }
        v1 = &pDst[v90];
        v31 = v100 == 1;
        pDst += v90;
        --v100;
      }
      while ( !v31 );
    }
  }
  else
  {
    v37 = i_args->cDstArgs.pDstBuf;
    pixSrca = g_SourceColor;
    pixSrca.a = i_args->i8AlphaModifier;
    v93 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v38 = i_args->nWidth;
      v107 = i_args->nWidth;
      v91 = i_args->cDstArgs.iStride;
      v103 = i_args->nHeight;
      do
      {
        if ( v38 )
        {
          idxXa = pixSrca.u >> 24;
          v39 = (int)(&v37[2 * v38 + 2] + v38);
          v95 = v38;
          do
          {
            v39 -= 3;
            v40 = idxXa != 0;
            v97 = v39;
            v41 = v40 + idxXa;
            pDsta = (char *)(v40 + idxXa);
            if ( v40 + idxXa )
            {
              v75 = *(_BYTE *)(v39 - 2);
              v77 = *(_BYTE *)(v39 - 1);
              v79 = *(_BYTE *)v39;
              v42 = (pixSrca.r != 0) + (unsigned __int8)pixSrca.r;
              v43 = v42;
              v44 = (pixSrca.g != 0) + (unsigned __int8)pixSrca.g;
              v45 = pixSrca.b != 0;
              v46 = (pixSrca.r != 0) + (unsigned __int8)pixSrca.r;
              v47 = v45 + (unsigned __int8)pixSrca.b;
              if ( v44 <= v42 )
              {
                if ( v44 < v42 )
                  v46 = (pixSrca.g != 0) + (unsigned __int8)pixSrca.g;
              }
              else
              {
                v43 = (pixSrca.g != 0) + (unsigned __int8)pixSrca.g;
              }
              if ( v47 <= v43 )
              {
                if ( v47 < v46 )
                  v46 = v45 + (unsigned __int8)pixSrca.b;
              }
              else
              {
                v43 = v45 + (unsigned __int8)pixSrca.b;
              }
              v101 = v43 - v46;
              if ( v43 == v46 )
              {
                v48 = 0;
                v49 = 0;
                v83 = 0;
              }
              else
              {
                v50 = 0;
                v83 = (v101 << 8) / v43;
                if ( v42 == v43 )
                {
                  v51 = v44 - v47;
                  if ( v44 - v47 < 0 )
                    v50 = 24576;
                }
                else if ( v44 == v43 )
                {
                  v51 = v47 - v42;
                  v50 = 0x2000;
                }
                else
                {
                  v51 = v42 - v44;
                  v50 = 0x4000;
                }
                v49 = (v101 << 8) / v43;
                v48 = v50 + (v51 << 12) / v101;
                v41 = (int)pDsta;
              }
              v52 = v79 + (v79 != 0);
              if ( (v77 != 0) + v77 > v52 )
                v52 = (v77 != 0) + v77;
              if ( (v75 != 0) + v75 > v52 )
                v52 = (v75 != 0) + v75;
              if ( v41 == 256 )
              {
                if ( v49 )
                {
                  v60 = v48 / 4096;
                  v61 = v83 * v52 / 256;
                  v62 = v61 * (v48 - ((v48 / 4096 + 1) / 2 << 13));
                  v63 = v52 - v61;
                  v64 = v62 / 4096;
                  if ( v62 % 4096 < -2048 )
                    --v64;
                  if ( v62 % 4096 > 2048 )
                    ++v64;
                  switch ( v60 )
                  {
                    case 0:
                      v53 = v52;
                      i_args = (BlitArgs *)(v52 - v61);
                      v54 = v63 + v64;
                      break;
                    case 1:
                      i_args = (BlitArgs *)(v52 - v61);
                      v54 = v52;
                      v53 = v63 - v64;
                      break;
                    case 2:
                      v53 = v52 - v61;
                      v54 = v52;
                      i_args = (BlitArgs *)(v64 + v63);
                      break;
                    case 3:
                      v53 = v52 - v61;
                      i_args = (BlitArgs *)v52;
                      v54 = v63 - v64;
                      break;
                    case 4:
                      i_args = (BlitArgs *)v52;
                      v54 = v52 - v61;
                      v53 = v63 + v64;
                      break;
                    case 5:
                      v54 = v52 - v61;
                      v53 = v52;
                      i_args = (BlitArgs *)(v63 - v64);
                      break;
                    default:
                      goto LABEL_94;
                  }
                }
                else
                {
                  v88 = v52;
                  v87 = v52;
                  i_args = (BlitArgs *)v52;
LABEL_94:
                  v53 = v88;
                  v54 = v87;
                }
                v55 = v53 - (v53 != 0);
                v88 = v55;
                v56 = v54 - (v54 != 0);
                v87 = v56;
                v57 = v55;
                v58 = v56;
                i_args = (BlitArgs *)((char *)i_args - (i_args != 0));
                v59 = (char)i_args;
              }
              else
              {
                if ( v49 )
                {
                  v69 = v48 / 4096;
                  v70 = v83 * v52 / 256;
                  v71 = v70 * (v48 - ((v48 / 4096 + 1) / 2 << 13));
                  v72 = v52 - v70;
                  v73 = v71 / 4096;
                  if ( v71 % 4096 < -2048 )
                    --v73;
                  if ( v71 % 4096 > 2048 )
                    ++v73;
                  switch ( v69 )
                  {
                    case 0:
                      v67 = v52;
                      v65 = v52 - v70;
                      v66 = v72 + v73;
                      break;
                    case 1:
                      v65 = v52 - v70;
                      v66 = v52;
                      v67 = v72 - v73;
                      break;
                    case 2:
                      v66 = v52;
                      v67 = v52 - v70;
                      v65 = v72 + v73;
                      break;
                    case 3:
                      v67 = v52 - v70;
                      v65 = v52;
                      v66 = v72 - v73;
                      break;
                    case 4:
                      v65 = v52;
                      v66 = v72;
                      v67 = v72 + v73;
                      break;
                    case 5:
                      v66 = v52 - v70;
                      v67 = v52;
                      v65 = v72 - v73;
                      break;
                    default:
                      goto LABEL_109;
                  }
                }
                else
                {
                  v86 = v52;
                  v85 = v52;
                  v84 = v52;
LABEL_109:
                  v65 = v84;
                  v66 = v85;
                  v67 = v86;
                }
                v68 = v67 - (v67 != 0);
                v86 = v68;
                v85 = v66 - (v66 != 0);
                v57 = v79 - (signed int)pDsta * (v79 - v68) / 256;
                v58 = v77 - (signed int)pDsta * (v77 - v85) / 256;
                v84 = v65 - (v65 != 0);
                v59 = v75 - (signed int)pDsta * (v75 - v84) / 256;
              }
              v39 = v97;
              *(_BYTE *)v97 = v57;
              v38 = v107;
              *(_BYTE *)(v97 - 2) = v59;
              *(_BYTE *)(v97 - 1) = v58;
            }
            --v95;
          }
          while ( v95 );
        }
        v37 = &v93[-v91];
        v31 = v103 == 1;
        v93 -= v91;
        --v103;
      }
      while ( !v31 );
    }
  }
  _m_femms();
}

//----- (006665E0) --------------------------------------------------------  // acclient.c:637182
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_(BlitArgs *i_args)
{
  int v1; // edi@1
  unsigned int v2; // ecx@2
  unsigned int v3; // esi@2
  const char *v4; // eax@4
  int v5; // esi@5
  unsigned int v6; // ecx@6
  unsigned int v7; // ecx@7
  unsigned int v8; // ebx@7
  int v9; // edx@7
  int v10; // ebp@7
  int v11; // edx@10
  int v12; // edi@10
  int v13; // esi@10
  int v14; // ecx@10
  signed int v15; // ebx@10
  int v16; // esi@10
  int v17; // edi@10
  int v18; // eax@10
  signed int v19; // esi@19
  int v20; // ebx@19
  signed int v21; // ebp@20
  int v22; // ecx@21
  int v23; // edx@27
  int v24; // ecx@27
  int v25; // edx@34
  int v26; // ebx@36
  int v27; // ebp@36
  signed int v28; // esi@36
  int v29; // edi@36
  int v30; // eax@36
  int v31; // esi@49
  int v32; // edx@49
  bool v33; // sf@52
  int v34; // ebx@55
  unsigned int v35; // esi@55
  int v36; // ecx@56
  unsigned int v37; // ecx@56
  int v38; // edx@56
  int v39; // ebp@56
  int v40; // eax@59
  int v41; // edi@59
  int v42; // esi@59
  int v43; // ecx@59
  signed int v44; // ebx@59
  int v45; // esi@59
  int v46; // eax@59
  int v47; // edi@59
  int v48; // ebx@61
  int v49; // ebp@61
  signed int v50; // esi@61
  int v51; // edi@61
  int v52; // eax@61
  signed int v53; // esi@79
  int v54; // ebx@79
  signed int v55; // ebp@80
  int v56; // ecx@81
  int v57; // ecx@87
  int v58; // edx@94
  int v59; // ebx@96
  int v60; // ebp@96
  signed int v61; // esi@96
  int v62; // edi@96
  int v63; // eax@96
  int v64; // esi@109
  int v65; // edx@109
  int v66; // ebx@115
  int v67; // ebp@115
  signed int v68; // esi@115
  int v69; // edi@115
  int v70; // eax@115
  int v71; // [sp+4h] [bp-80h]@10
  int v72; // [sp+4h] [bp-80h]@59
  int v73; // [sp+8h] [bp-7Ch]@0
  int v74; // [sp+Ch] [bp-78h]@0
  int v75; // [sp+10h] [bp-74h]@19
  int i; // [sp+14h] [bp-70h]@6
  int ia; // [sp+14h] [bp-70h]@79
  char *pSrc; // [sp+18h] [bp-6Ch]@1
  char *pDst; // [sp+1Ch] [bp-68h]@1
  int v80; // [sp+20h] [bp-64h]@0
  int v81; // [sp+24h] [bp-60h]@0
  int v82; // [sp+28h] [bp-5Ch]@0
  int v83; // [sp+2Ch] [bp-58h]@0
  int v84; // [sp+30h] [bp-54h]@0
  int v85; // [sp+34h] [bp-50h]@7
  int v86; // [sp+34h] [bp-50h]@56
  int v87; // [sp+38h] [bp-4Ch]@0
  int v88; // [sp+3Ch] [bp-48h]@0
  int v89; // [sp+40h] [bp-44h]@0
  int v90; // [sp+44h] [bp-40h]@0
  int v91; // [sp+48h] [bp-3Ch]@0
  unsigned int idxY; // [sp+4Ch] [bp-38h]@1
  signed int idxX; // [sp+50h] [bp-34h]@18
  unsigned int idxXa; // [sp+50h] [bp-34h]@56
  char *pTrailingDst; // [sp+54h] [bp-30h]@6
  unsigned int dw4Pix; // [sp+58h] [bp-2Ch]@6
  signed int dw4Pixa; // [sp+58h] [bp-2Ch]@78
  int nInts; // [sp+5Ch] [bp-28h]@2
  int nTrailing; // [sp+60h] [bp-24h]@2
  int iModifier; // [sp+64h] [bp-20h]@1
  const char *pTrailingSrc; // [sp+70h] [bp-14h]@6
  unsigned int v102; // [sp+74h] [bp-10h]@2
  unsigned int v103; // [sp+78h] [bp-Ch]@2
  unsigned int pixSrc; // [sp+7Ch] [bp-8h]@56

  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  iModifier = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  idxY = i_args->nHeight;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth;
    v3 = v2 >> 2;
    nInts = v2 >> 2;
    nTrailing = v2 & 3;
    v102 = i_args->cSrcArgs.iStride;
    v103 = i_args->cDstArgs.iStride;
    while ( 1 )
    {
      --idxY;
      v4 = (const char *)v3;
      if ( v3 )
      {
        v5 = (int)&pDst[16 * v3];
        do
        {
          v6 = *(_DWORD *)&pSrc[4 * (_DWORD)v4 - 4];
          v5 -= 16;
          pTrailingSrc = v4 - 1;
          pTrailingDst = (char *)v5;
          dw4Pix = *(_DWORD *)&pSrc[4 * (_DWORD)v4 - 4];
          i = 3;
          do
          {
            v7 = g_SourceColor.u | v6 & 0xFF000000;
            v8 = v7 >> 16;
            v9 = BYTE1(v8) != 0;
            v10 = v9 + BYTE1(v8);
            v85 = v9 + BYTE1(v8);
            if ( v1 != 256 )
            {
              v10 = v1 * v10 / 256;
              v85 = v10;
            }
            if ( v10 )
            {
              v11 = *(_DWORD *)(v5 + 4 * i);
              v12 = (unsigned __int8)v7;
              v13 = BYTE1(v7);
              v71 = v11;
              v14 = ((unsigned __int8)v8 != 0) + (unsigned __int8)v8;
              v15 = v14;
              v16 = (v13 != 0) + v13;
              v17 = (v12 != 0) + v12;
              v18 = v14;
              if ( v16 <= v14 )
              {
                if ( v16 < v14 )
                  v18 = v16;
              }
              else
              {
                v15 = v16;
              }
              if ( v17 <= v15 )
              {
                if ( v17 < v18 )
                  v18 = v17;
              }
              else
              {
                v15 = v17;
              }
              idxX = v15 - v18;
              if ( v15 == v18 )
              {
                v19 = 0;
                v20 = 0;
                v75 = 0;
              }
              else
              {
                v21 = 0;
                v75 = (idxX << 8) / v15;
                if ( v14 == v15 )
                {
                  v22 = v16 - v17;
                  if ( v16 - v17 < 0 )
                    v21 = 24576;
                }
                else if ( v16 == v15 )
                {
                  v22 = v17 - v14;
                  v21 = 0x2000;
                }
                else
                {
                  v22 = v14 - v16;
                  v21 = 0x4000;
                }
                v20 = (idxX << 8) / v15;
                v19 = v21 + (v22 << 12) / idxX;
                v10 = v85;
              }
              v23 = ((unsigned __int8)v11 != 0) + (unsigned __int8)v11;
              v24 = BYTE2(v71) + (BYTE2(v71) != 0);
              if ( (BYTE1(v71) != 0) + BYTE1(v71) > v24 )
                v24 = (BYTE1(v71) != 0) + BYTE1(v71);
              if ( v23 > v24 )
                v24 = ((unsigned __int8)v71 != 0) + (unsigned __int8)v71;
              if ( v10 == 256 )
              {
                if ( v20 )
                {
                  v26 = v19 / 4096;
                  v27 = v75 * v24 / 256;
                  v28 = v27 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v29 = v24 - v27;
                  v30 = v28 / 4096;
                  if ( v28 % 4096 < -2048 )
                    --v30;
                  if ( v28 % 4096 > 2048 )
                    ++v30;
                  switch ( v26 )
                  {
                    case 0:
                      v25 = v24;
                      v73 = v24 - v27;
                      v24 = v29 + v30;
                      break;
                    case 1:
                      v73 = v24 - v27;
                      v25 = v29 - v30;
                      break;
                    case 2:
                      v25 = v24 - v27;
                      v73 = v30 + v29;
                      break;
                    case 3:
                      v25 = v24 - v27;
                      v73 = v24;
                      v24 = v29 - v30;
                      break;
                    case 4:
                      v73 = v24;
                      v24 -= v27;
                      v25 = v29 + v30;
                      break;
                    case 5:
                      v25 = v24;
                      v24 -= v27;
                      v73 = v29 - v30;
                      break;
                    default:
                      goto LABEL_34;
                  }
                }
                else
                {
                  v80 = v24;
                  v81 = v24;
                  v73 = v24;
LABEL_34:
                  v25 = v80;
                  v24 = v81;
                }
                v80 = v25 - (v25 != 0);
                BYTE2(v71) = v25 - (v25 != 0);
                v81 = v24 - (v24 != 0);
                BYTE1(v71) = v24 - (v24 != 0);
                v73 -= v73 != 0;
                LOBYTE(v71) = v73;
              }
              else
              {
                if ( v20 )
                {
                  v48 = v19 / 4096;
                  v49 = v75 * v24 / 256;
                  v50 = v49 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v51 = v24 - v49;
                  v52 = v50 / 4096;
                  if ( v50 % 4096 < -2048 )
                    --v52;
                  if ( v50 % 4096 > 2048 )
                    ++v52;
                  switch ( v48 )
                  {
                    case 0:
                      v32 = v24;
                      v31 = v24 - v49;
                      v24 = v51 + v52;
                      break;
                    case 1:
                      v31 = v24 - v49;
                      v32 = v51 - v52;
                      break;
                    case 2:
                      v32 = v24 - v49;
                      v31 = v51 + v52;
                      break;
                    case 3:
                      v32 = v24 - v49;
                      v31 = v24;
                      v24 = v51 - v52;
                      break;
                    case 4:
                      v31 = v24;
                      v24 -= v49;
                      v32 = v51 + v52;
                      break;
                    case 5:
                      v32 = v24;
                      v24 -= v49;
                      v31 = v51 - v52;
                      break;
                    default:
                      goto LABEL_49;
                  }
                }
                else
                {
                  v82 = v24;
                  v83 = v24;
                  v84 = v24;
LABEL_49:
                  v31 = v84;
                  v24 = v83;
                  v32 = v82;
                }
                v82 = v32 - (v32 != 0);
                v83 = v24 - (v24 != 0);
                BYTE2(v71) -= v85 * (BYTE2(v71) - v82) / 256;
                BYTE1(v71) -= v85 * (BYTE1(v71) - v83) / 256;
                v84 = v31 - (v31 != 0);
                LOBYTE(v71) = v71 - v85 * ((unsigned __int8)v71 - v84) / 256;
              }
              v1 = iModifier;
              *(_DWORD *)&pTrailingDst[4 * i] = v71;
              v5 = (int)pTrailingDst;
            }
            v6 = dw4Pix << 8;
            v33 = i - 1 < 0;
            dw4Pix <<= 8;
            --i;
          }
          while ( !v33 );
          v4 = pTrailingSrc;
        }
        while ( pTrailingSrc );
      }
      if ( nTrailing )
      {
        v34 = (int)&pDst[16 * nInts];
        v35 = nTrailing;
        if ( nTrailing )
        {
          do
          {
            v36 = (unsigned __int8)*(&pSrc[4 * nInts - 1] + v35--);
            v37 = g_SourceColor.u | (v36 << 24);
            v38 = v37 >> 24 != 0;
            idxXa = v35;
            pixSrc = v37;
            v39 = v38 + (v37 >> 24);
            v86 = v38 + (v37 >> 24);
            if ( v1 != 256 )
            {
              v39 = v1 * v39 / 256;
              v86 = v39;
            }
            if ( v39 )
            {
              v40 = *(_DWORD *)(v34 + 4 * v35);
              v41 = (unsigned __int8)v37;
              v42 = BYTE1(v37);
              v72 = v40;
              v43 = ((unsigned __int8)(v37 >> 16) != 0) + (unsigned __int8)(v37 >> 16);
              v44 = v43;
              v45 = (v42 != 0) + v42;
              v46 = ((unsigned __int8)(pixSrc >> 16) != 0) + (unsigned __int8)(pixSrc >> 16);
              v47 = (v41 != 0) + v41;
              if ( v45 <= v43 )
              {
                if ( v45 < v43 )
                  v46 = v45;
              }
              else
              {
                v44 = v45;
              }
              if ( v47 <= v44 )
              {
                if ( v47 < v46 )
                  v46 = v47;
              }
              else
              {
                v44 = v47;
              }
              dw4Pixa = v44 - v46;
              if ( v44 == v46 )
              {
                v53 = 0;
                v54 = 0;
                ia = 0;
              }
              else
              {
                v55 = 0;
                ia = (dw4Pixa << 8) / v44;
                if ( v43 == v44 )
                {
                  v56 = v45 - v47;
                  if ( v45 - v47 < 0 )
                    v55 = 24576;
                }
                else if ( v45 == v44 )
                {
                  v56 = v47 - v43;
                  v55 = 0x2000;
                }
                else
                {
                  v56 = v43 - v45;
                  v55 = 0x4000;
                }
                v54 = (dw4Pixa << 8) / v44;
                v53 = v55 + (v56 << 12) / dw4Pixa;
                v39 = v86;
              }
              v57 = BYTE2(v72) + (BYTE2(v72) != 0);
              if ( (BYTE1(v72) != 0) + BYTE1(v72) > v57 )
                v57 = (BYTE1(v72) != 0) + BYTE1(v72);
              if ( ((unsigned __int8)v72 != 0) + (unsigned __int8)v72 > v57 )
                v57 = ((unsigned __int8)v72 != 0) + (unsigned __int8)v72;
              if ( v39 == 256 )
              {
                if ( v54 )
                {
                  v59 = v53 / 4096;
                  v60 = ia * v57 / 256;
                  v61 = v60 * (v53 - ((v53 / 4096 + 1) / 2 << 13));
                  v62 = v57 - v60;
                  v63 = v61 / 4096;
                  if ( v61 % 4096 < -2048 )
                    --v63;
                  if ( v61 % 4096 > 2048 )
                    ++v63;
                  switch ( v59 )
                  {
                    case 0:
                      v58 = v57;
                      v74 = v57 - v60;
                      v57 = v62 + v63;
                      break;
                    case 1:
                      v74 = v57 - v60;
                      v58 = v62 - v63;
                      break;
                    case 2:
                      v58 = v57 - v60;
                      v74 = v63 + v62;
                      break;
                    case 3:
                      v58 = v57 - v60;
                      v74 = v57;
                      v57 = v62 - v63;
                      break;
                    case 4:
                      v74 = v57;
                      v57 -= v60;
                      v58 = v62 + v63;
                      break;
                    case 5:
                      v58 = v57;
                      v57 -= v60;
                      v74 = v62 - v63;
                      break;
                    default:
                      goto LABEL_94;
                  }
                }
                else
                {
                  v87 = v57;
                  v88 = v57;
                  v74 = v57;
LABEL_94:
                  v58 = v87;
                  v57 = v88;
                }
                v87 = v58 - (v58 != 0);
                BYTE2(v72) = v58 - (v58 != 0);
                v88 = v57 - (v57 != 0);
                BYTE1(v72) = v57 - (v57 != 0);
                v74 -= v74 != 0;
                LOBYTE(v72) = v74;
              }
              else
              {
                if ( v54 )
                {
                  v66 = v53 / 4096;
                  v67 = ia * v57 / 256;
                  v68 = v67 * (v53 - ((v53 / 4096 + 1) / 2 << 13));
                  v69 = v57 - v67;
                  v70 = v68 / 4096;
                  if ( v68 % 4096 < -2048 )
                    --v70;
                  if ( v68 % 4096 > 2048 )
                    ++v70;
                  switch ( v66 )
                  {
                    case 0:
                      v65 = v57;
                      v64 = v57 - v67;
                      v57 = v69 + v70;
                      break;
                    case 1:
                      v64 = v57 - v67;
                      v65 = v69 - v70;
                      break;
                    case 2:
                      v65 = v57 - v67;
                      v64 = v69 + v70;
                      break;
                    case 3:
                      v65 = v57 - v67;
                      v64 = v57;
                      v57 = v69 - v70;
                      break;
                    case 4:
                      v64 = v57;
                      v57 -= v67;
                      v65 = v69 + v70;
                      break;
                    case 5:
                      v65 = v57;
                      v57 -= v67;
                      v64 = v69 - v70;
                      break;
                    default:
                      goto LABEL_109;
                  }
                }
                else
                {
                  v89 = v57;
                  v90 = v57;
                  v91 = v57;
LABEL_109:
                  v64 = v91;
                  v57 = v90;
                  v65 = v89;
                }
                v89 = v65 - (v65 != 0);
                v90 = v57 - (v57 != 0);
                BYTE2(v72) -= v86 * (BYTE2(v72) - v89) / 256;
                v91 = v64 - (v64 != 0);
                BYTE1(v72) -= v86 * (BYTE1(v72) - v90) / 256;
                LOBYTE(v72) = v72 - v86 * ((unsigned __int8)v72 - v91) / 256;
              }
              v1 = iModifier;
              *((_DWORD *)&pDst[16 * nInts] + idxXa) = v72;
              v34 = (int)&pDst[16 * nInts];
              v35 = idxXa;
            }
          }
          while ( v35 );
        }
      }
      pSrc += v102;
      pDst += v103;
      if ( !idxY )
        break;
      v3 = nInts;
    }
  }
  _m_femms();
}

//----- (00666F80) --------------------------------------------------------  // acclient.c:637768
void __cdecl ColoringLoopNoScale_FromA8__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // ebp@1
  unsigned int v2; // eax@2
  unsigned int v3; // ecx@4
  int i; // esi@5
  int v5; // ecx@7
  unsigned int v6; // ecx@7
  int v7; // esi@7
  unsigned int v8; // ecx@8
  unsigned int v9; // ebx@8
  int v10; // eax@8
  int v11; // edi@8
  unsigned __int8 v12; // al@11
  unsigned __int8 v13; // dl@11
  int v14; // edi@11
  int v15; // esi@11
  int v16; // ecx@11
  signed int v17; // ebp@11
  int v18; // esi@11
  int v19; // edi@11
  int v20; // eax@11
  signed int v21; // esi@20
  int v22; // ebp@20
  signed int v23; // ebx@21
  int v24; // ecx@22
  int v25; // ecx@28
  int v26; // edx@35
  int v27; // ebx@35
  int v28; // edx@36
  int v29; // ebx@36
  char v30; // cl@36
  char v31; // dl@36
  char v32; // bl@36
  int v33; // ebx@37
  int v34; // ebp@37
  signed int v35; // esi@37
  int v36; // edi@37
  int v37; // eax@37
  int v38; // ebp@50
  int v39; // esi@50
  int v40; // edx@50
  int v41; // edx@51
  bool v42; // zf@53
  unsigned int v43; // edi@56
  int v44; // esi@57
  int v45; // ecx@58
  unsigned int v46; // ecx@58
  unsigned int v47; // ebx@58
  int v48; // edx@58
  int v49; // ebp@58
  unsigned __int8 v50; // dl@61
  unsigned __int8 v51; // al@61
  int v52; // edi@61
  int v53; // esi@61
  int v54; // ecx@61
  signed int v55; // ebp@61
  int v56; // esi@61
  int v57; // eax@61
  int v58; // edi@61
  int v59; // ebx@63
  int v60; // ebp@63
  signed int v61; // esi@63
  int v62; // edi@63
  int v63; // eax@63
  signed int v64; // esi@81
  int v65; // ebp@81
  signed int v66; // ebx@82
  int v67; // ecx@83
  int v68; // ecx@89
  int v69; // edx@96
  int v70; // ebx@96
  int v71; // edx@97
  int v72; // ebx@97
  char v73; // cl@97
  char v74; // dl@97
  char v75; // bl@97
  int v76; // ebx@98
  int v77; // ebp@98
  signed int v78; // esi@98
  int v79; // edi@98
  int v80; // eax@98
  int v81; // ebp@111
  int v82; // esi@111
  int v83; // edx@111
  int v84; // edx@112
  int v85; // ebx@117
  int v86; // ebp@117
  signed int v87; // esi@117
  int v88; // edi@117
  int v89; // eax@117
  int v90; // [sp+4h] [bp-88h]@20
  int v91; // [sp+4h] [bp-88h]@81
  int v92; // [sp+8h] [bp-84h]@0
  int v93; // [sp+Ch] [bp-80h]@0
  int v94; // [sp+10h] [bp-7Ch]@8
  int v95; // [sp+10h] [bp-7Ch]@58
  unsigned __int8 v96; // [sp+14h] [bp-78h]@61
  unsigned __int8 v97; // [sp+16h] [bp-76h]@61
  unsigned __int8 v98; // [sp+18h] [bp-74h]@11
  unsigned __int8 v99; // [sp+19h] [bp-73h]@11
  unsigned __int8 v100; // [sp+1Ah] [bp-72h]@11
  signed int idxX; // [sp+1Ch] [bp-70h]@19
  unsigned int idxXa; // [sp+1Ch] [bp-70h]@58
  unsigned int dw4Pix; // [sp+20h] [bp-6Ch]@7
  unsigned int dw4Pixa; // [sp+20h] [bp-6Ch]@58
  signed int v105; // [sp+24h] [bp-68h]@7
  signed int v106; // [sp+24h] [bp-68h]@80
  int iModifier; // [sp+28h] [bp-64h]@1
  char *pDst; // [sp+2Ch] [bp-60h]@1
  char *pSrc; // [sp+30h] [bp-5Ch]@1
  int v110; // [sp+34h] [bp-58h]@0
  int v111; // [sp+38h] [bp-54h]@0
  int v112; // [sp+3Ch] [bp-50h]@0
  int v113; // [sp+40h] [bp-4Ch]@7
  int v114; // [sp+44h] [bp-48h]@0
  int v115; // [sp+48h] [bp-44h]@0
  int nTrailing; // [sp+4Ch] [bp-40h]@2
  const char *pTrailingSrc; // [sp+50h] [bp-3Ch]@7
  int v118; // [sp+54h] [bp-38h]@0
  int v119; // [sp+58h] [bp-34h]@0
  int v120; // [sp+5Ch] [bp-30h]@0
  int v121; // [sp+60h] [bp-2Ch]@0
  int v122; // [sp+64h] [bp-28h]@7
  unsigned int idxY; // [sp+68h] [bp-24h]@1
  int v124; // [sp+6Ch] [bp-20h]@89
  int v125; // [sp+70h] [bp-1Ch]@0
  int nInts; // [sp+78h] [bp-14h]@2
  unsigned int v127; // [sp+84h] [bp-8h]@2
  unsigned int v128; // [sp+88h] [bp-4h]@2

  pSrc = i_args->cSrcArgs.pDstBuf;
  pDst = i_args->cDstArgs.pDstBuf;
  v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  iModifier = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  idxY = i_args->nHeight;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth >> 2;
    nTrailing = i_args->nWidth & 3;
    nInts = i_args->nWidth >> 2;
    v128 = i_args->cSrcArgs.iStride;
    v127 = i_args->cDstArgs.iStride;
    while ( 1 )
    {
      --idxY;
      v3 = v2;
      if ( v2 )
      {
        for ( i = (int)&pDst[12 * v2 + 11]; ; i = v122 )
        {
          v5 = v3 - 1;
          pTrailingSrc = (const char *)v5;
          v6 = *(_DWORD *)&pSrc[4 * v5];
          v7 = i - 12;
          v122 = v7;
          dw4Pix = v6;
          v113 = v7;
          v105 = 4;
          do
          {
            v8 = g_SourceColor.u | v6 & 0xFF000000;
            v9 = v8 >> 16;
            v10 = BYTE1(v9) != 0;
            v11 = v10 + BYTE1(v9);
            v94 = v10 + BYTE1(v9);
            if ( v1 != 256 )
            {
              v11 = v1 * v11 / 256;
              v94 = v11;
            }
            if ( v11 )
            {
              v12 = *(_BYTE *)(v7 - 1);
              v98 = *(_BYTE *)(v7 - 2);
              v13 = *(_BYTE *)v7;
              v14 = (unsigned __int8)v8;
              v15 = BYTE1(v8);
              v99 = v12;
              v100 = v13;
              v16 = ((unsigned __int8)v9 != 0) + (unsigned __int8)v9;
              v17 = v16;
              v18 = (v15 != 0) + v15;
              v19 = (v14 != 0) + v14;
              v20 = ((unsigned __int8)v9 != 0) + (unsigned __int8)v9;
              if ( v18 <= v16 )
              {
                if ( v18 < v16 )
                  v20 = v18;
              }
              else
              {
                v17 = v18;
              }
              if ( v19 <= v17 )
              {
                if ( v19 < v20 )
                  v20 = v19;
              }
              else
              {
                v17 = v19;
              }
              idxX = v17 - v20;
              if ( v17 == v20 )
              {
                v21 = 0;
                v22 = 0;
                v90 = 0;
              }
              else
              {
                v23 = 0;
                v90 = (idxX << 8) / v17;
                if ( v16 == v17 )
                {
                  v24 = v18 - v19;
                  if ( v18 - v19 < 0 )
                    v23 = 24576;
                }
                else if ( v18 == v17 )
                {
                  v24 = v19 - v16;
                  v23 = 0x2000;
                }
                else
                {
                  v24 = v16 - v18;
                  v23 = 0x4000;
                }
                v22 = (idxX << 8) / v17;
                v21 = v23 + (v24 << 12) / idxX;
              }
              v25 = v13 + (v13 != 0);
              if ( (v99 != 0) + v99 > v25 )
                v25 = (v99 != 0) + v99;
              if ( (v98 != 0) + v98 > v25 )
                v25 = (v98 != 0) + v98;
              if ( v94 == 256 )
              {
                if ( v22 )
                {
                  v33 = v21 / 4096;
                  v34 = v90 * v25 / 256;
                  v35 = v34 * (v21 - ((v21 / 4096 + 1) / 2 << 13));
                  v36 = v25 - v34;
                  v37 = v35 / 4096;
                  if ( v35 % 4096 < -2048 )
                    --v37;
                  if ( v35 % 4096 > 2048 )
                    ++v37;
                  switch ( v33 )
                  {
                    case 0:
                      v26 = v25;
                      v93 = v25 - v34;
                      v27 = v36 + v37;
                      break;
                    case 1:
                      v93 = v25 - v34;
                      v27 = v25;
                      v26 = v36 - v37;
                      break;
                    case 2:
                      v26 = v25 - v34;
                      v27 = v25;
                      v93 = v37 + v36;
                      break;
                    case 3:
                      v26 = v25 - v34;
                      v93 = v25;
                      v27 = v36 - v37;
                      break;
                    case 4:
                      v93 = v25;
                      v27 = v25 - v34;
                      v26 = v36 + v37;
                      break;
                    case 5:
                      v27 = v25 - v34;
                      v26 = v25;
                      v93 = v36 - v37;
                      break;
                    default:
                      goto LABEL_35;
                  }
                }
                else
                {
                  v115 = v25;
                  v111 = v25;
                  v93 = v25;
LABEL_35:
                  v26 = v115;
                  v27 = v111;
                }
                v28 = v26 - (v26 != 0);
                v115 = v28;
                v29 = v27 - (v27 != 0);
                v111 = v29;
                v30 = v28;
                v31 = v29;
                v93 -= v93 != 0;
                v32 = v93;
              }
              else
              {
                if ( v22 )
                {
                  v59 = v21 / 4096;
                  v60 = v90 * v25 / 256;
                  v61 = v60 * (v21 - ((v21 / 4096 + 1) / 2 << 13));
                  v62 = v25 - v60;
                  v63 = v61 / 4096;
                  if ( v61 % 4096 < -2048 )
                    --v63;
                  if ( v61 % 4096 > 2048 )
                    ++v63;
                  switch ( v59 )
                  {
                    case 0:
                      v40 = v25;
                      v38 = v25 - v60;
                      v39 = v62 + v63;
                      break;
                    case 1:
                      v38 = v25 - v60;
                      v39 = v25;
                      v40 = v62 - v63;
                      break;
                    case 2:
                      v39 = v25;
                      v40 = v25 - v60;
                      v38 = v62 + v63;
                      break;
                    case 3:
                      v40 = v25 - v60;
                      v38 = v25;
                      v39 = v62 - v63;
                      break;
                    case 4:
                      v38 = v25;
                      v39 = v62;
                      v40 = v62 + v63;
                      break;
                    case 5:
                      v39 = v25 - v60;
                      v40 = v25;
                      v38 = v62 - v63;
                      break;
                    default:
                      goto LABEL_50;
                  }
                }
                else
                {
                  v112 = v25;
                  v114 = v25;
                  v121 = v25;
LABEL_50:
                  v38 = v121;
                  v39 = v114;
                  v40 = v112;
                }
                v41 = v40 - (v40 != 0);
                v112 = v41;
                v114 = v39 - (v39 != 0);
                v30 = v100 - v94 * (v100 - v41) / 256;
                v31 = v99 - v94 * (v99 - v114) / 256;
                v121 = v38 - (v38 != 0);
                v32 = v98 - v94 * (v98 - v121) / 256;
              }
              v1 = iModifier;
              *(_BYTE *)(v113 - 2) = v32;
              *(_BYTE *)(v113 - 1) = v31;
              *(_BYTE *)v113 = v30;
              v7 = v113;
            }
            v6 = dw4Pix << 8;
            v7 -= 3;
            v42 = v105 == 1;
            dw4Pix <<= 8;
            v113 = v7;
            --v105;
          }
          while ( !v42 );
          v3 = (unsigned int)pTrailingSrc;
          if ( !pTrailingSrc )
            break;
        }
      }
      if ( nTrailing )
      {
        v43 = nTrailing;
        if ( nTrailing )
        {
          v44 = (int)(&pDst[12 * nInts + 2] + 2 * nTrailing + nTrailing);
          do
          {
            v45 = (unsigned __int8)*(&pSrc[4 * nInts - 1] + v43--);
            v46 = g_SourceColor.u | (v45 << 24);
            v47 = v46 >> 16;
            v44 -= 3;
            v48 = BYTE1(v47) != 0;
            idxXa = v43;
            dw4Pixa = v44;
            v49 = v48 + BYTE1(v47);
            v95 = v48 + BYTE1(v47);
            if ( iModifier != 256 )
            {
              v95 = iModifier * v49 / 256;
              v49 = iModifier * v49 / 256;
            }
            if ( v49 )
            {
              v50 = *(_BYTE *)(v44 - 1);
              v96 = *(_BYTE *)(v44 - 2);
              v51 = *(_BYTE *)v44;
              v52 = (unsigned __int8)v46;
              v53 = BYTE1(v46);
              v97 = v51;
              v54 = ((unsigned __int8)v47 != 0) + (unsigned __int8)v47;
              v55 = v54;
              v56 = (v53 != 0) + v53;
              v57 = ((unsigned __int8)v47 != 0) + (unsigned __int8)v47;
              v58 = (v52 != 0) + v52;
              if ( v56 <= v54 )
              {
                if ( v56 < v54 )
                  v57 = v56;
              }
              else
              {
                v55 = v56;
              }
              if ( v58 <= v55 )
              {
                if ( v58 < v57 )
                  v57 = v58;
              }
              else
              {
                v55 = v58;
              }
              v106 = v55 - v57;
              if ( v55 == v57 )
              {
                v64 = 0;
                v65 = 0;
                v91 = 0;
              }
              else
              {
                v66 = 0;
                v91 = (v106 << 8) / v55;
                if ( v54 == v55 )
                {
                  v67 = v56 - v58;
                  if ( v56 - v58 < 0 )
                    v66 = 24576;
                }
                else if ( v56 == v55 )
                {
                  v67 = v58 - v54;
                  v66 = 0x2000;
                }
                else
                {
                  v67 = v54 - v56;
                  v66 = 0x4000;
                }
                v65 = (v106 << 8) / v55;
                v64 = v66 + (v67 << 12) / v106;
              }
              v124 = v50;
              v68 = v97 + (v97 != 0);
              if ( (v50 != 0) + v50 > v68 )
                v68 = (v50 != 0) + v50;
              if ( (v96 != 0) + v96 > v68 )
                v68 = (v96 != 0) + v96;
              if ( v95 == 256 )
              {
                if ( v65 )
                {
                  v76 = v64 / 4096;
                  v77 = v91 * v68 / 256;
                  v78 = v77 * (v64 - ((v64 / 4096 + 1) / 2 << 13));
                  v79 = v68 - v77;
                  v80 = v78 / 4096;
                  if ( v78 % 4096 < -2048 )
                    --v80;
                  if ( v78 % 4096 > 2048 )
                    ++v80;
                  switch ( v76 )
                  {
                    case 0:
                      v69 = v68;
                      v92 = v68 - v77;
                      v70 = v79 + v80;
                      break;
                    case 1:
                      v92 = v68 - v77;
                      v70 = v68;
                      v69 = v79 - v80;
                      break;
                    case 2:
                      v69 = v68 - v77;
                      v70 = v68;
                      v92 = v80 + v79;
                      break;
                    case 3:
                      v69 = v68 - v77;
                      v92 = v68;
                      v70 = v79 - v80;
                      break;
                    case 4:
                      v92 = v68;
                      v70 = v68 - v77;
                      v69 = v79 + v80;
                      break;
                    case 5:
                      v70 = v68 - v77;
                      v69 = v68;
                      v92 = v79 - v80;
                      break;
                    default:
                      goto LABEL_96;
                  }
                }
                else
                {
                  v110 = v68;
                  v118 = v68;
                  v92 = v68;
LABEL_96:
                  v69 = v110;
                  v70 = v118;
                }
                v71 = v69 - (v69 != 0);
                v110 = v71;
                v72 = v70 - (v70 != 0);
                v118 = v72;
                v73 = v71;
                v74 = v72;
                v92 -= v92 != 0;
                v75 = v92;
              }
              else
              {
                if ( v65 )
                {
                  v85 = v64 / 4096;
                  v86 = v91 * v68 / 256;
                  v87 = v86 * (v64 - ((v64 / 4096 + 1) / 2 << 13));
                  v88 = v68 - v86;
                  v89 = v87 / 4096;
                  if ( v87 % 4096 < -2048 )
                    --v89;
                  if ( v87 % 4096 > 2048 )
                    ++v89;
                  switch ( v85 )
                  {
                    case 0:
                      v83 = v68;
                      v81 = v68 - v86;
                      v82 = v88 + v89;
                      break;
                    case 1:
                      v81 = v68 - v86;
                      v82 = v68;
                      v83 = v88 - v89;
                      break;
                    case 2:
                      v82 = v68;
                      v83 = v68 - v86;
                      v81 = v88 + v89;
                      break;
                    case 3:
                      v83 = v68 - v86;
                      v81 = v68;
                      v82 = v88 - v89;
                      break;
                    case 4:
                      v81 = v68;
                      v82 = v88;
                      v83 = v88 + v89;
                      break;
                    case 5:
                      v82 = v68 - v86;
                      v83 = v68;
                      v81 = v88 - v89;
                      break;
                    default:
                      goto LABEL_111;
                  }
                }
                else
                {
                  v120 = v68;
                  v125 = v68;
                  v119 = v68;
LABEL_111:
                  v81 = v119;
                  v82 = v125;
                  v83 = v120;
                }
                v84 = v83 - (v83 != 0);
                v120 = v84;
                v125 = v82 - (v82 != 0);
                v73 = v97 - v95 * (v97 - v84) / 256;
                v74 = v124 - v95 * (v124 - v125) / 256;
                v119 = v81 - (v81 != 0);
                v75 = v96 - v95 * (v96 - v119) / 256;
              }
              v43 = idxXa;
              *(_BYTE *)(dw4Pixa - 2) = v75;
              *(_BYTE *)(dw4Pixa - 1) = v74;
              *(_BYTE *)dw4Pixa = v73;
              v44 = dw4Pixa;
            }
          }
          while ( v43 );
        }
      }
      pSrc += v128;
      pDst += v127;
      if ( !idxY )
        break;
      v1 = iModifier;
      v2 = nInts;
    }
  }
  _m_femms();
}

//----- (00667970) --------------------------------------------------------  // acclient.c:638404
void __cdecl ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@2
  char *v2; // edi@2
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // esi@5
  int v6; // ecx@6
  unsigned int v7; // ecx@6
  unsigned int v8; // ebx@6
  int v9; // edx@6
  int v10; // ebp@6
  BlitArgs *v11; // eax@9
  int v12; // edi@9
  int v13; // esi@9
  int v14; // ecx@9
  signed int v15; // ebx@9
  int v16; // esi@9
  int v17; // eax@9
  int v18; // edi@9
  signed int v19; // esi@18
  int v20; // ebx@18
  signed int v21; // ebp@19
  int v22; // ecx@20
  int v23; // ecx@26
  int v24; // edx@33
  int v25; // ebx@35
  int v26; // ebp@35
  signed int v27; // esi@35
  int v28; // edi@35
  int v29; // eax@35
  int v30; // edx@48
  int v31; // esi@48
  bool v32; // zf@53
  int v33; // ebx@55
  int v34; // ebp@55
  signed int v35; // esi@55
  int v36; // edi@55
  int v37; // eax@55
  unsigned int v38; // eax@68
  int v39; // ecx@70
  int v40; // edx@70
  signed int v41; // ebx@70
  int v42; // esi@70
  int v43; // edi@70
  int v44; // eax@70
  signed int v45; // esi@79
  int v46; // ebp@79
  signed int v47; // ebp@80
  int v48; // ecx@81
  int v49; // ecx@87
  int v50; // edx@94
  int v51; // ebx@96
  int v52; // ebp@96
  signed int v53; // esi@96
  int v54; // edi@96
  int v55; // eax@96
  int v56; // esi@109
  int v57; // edx@109
  int v58; // ebx@115
  int v59; // ebp@115
  signed int v60; // esi@115
  int v61; // edi@115
  int v62; // eax@115
  int v63; // [sp+10h] [bp-5Ch]@0
  int v64; // [sp+14h] [bp-58h]@18
  unsigned int v65; // [sp+14h] [bp-58h]@66
  int v66; // [sp+18h] [bp-54h]@0
  int v67; // [sp+18h] [bp-54h]@79
  int v68; // [sp+1Ch] [bp-50h]@0
  char *v69; // [sp+1Ch] [bp-50h]@66
  int v70; // [sp+20h] [bp-4Ch]@0
  int v71; // [sp+24h] [bp-48h]@0
  int v72; // [sp+28h] [bp-44h]@0
  int v73; // [sp+2Ch] [bp-40h]@0
  int v74; // [sp+2Ch] [bp-40h]@6
  int iModifier; // [sp+30h] [bp-3Ch]@0
  int iModifiera; // [sp+30h] [bp-3Ch]@2
  unsigned int v77; // [sp+34h] [bp-38h]@3
  unsigned int v78; // [sp+34h] [bp-38h]@67
  signed int v79; // [sp+38h] [bp-34h]@17
  int v80; // [sp+3Ch] [bp-30h]@6
  unsigned int v81; // [sp+40h] [bp-2Ch]@5
  unsigned int v82; // [sp+40h] [bp-2Ch]@67
  char *pSrc; // [sp+44h] [bp-28h]@2
  const char *pSrca; // [sp+44h] [bp-28h]@69
  char *pDst; // [sp+48h] [bp-24h]@2
  char *pDsta; // [sp+48h] [bp-24h]@69
  unsigned int v87; // [sp+4Ch] [bp-20h]@3
  signed int v88; // [sp+4Ch] [bp-20h]@78
  int v89; // [sp+58h] [bp-14h]@5
  unsigned int idxX; // [sp+5Ch] [bp-10h]@3
  unsigned int v91; // [sp+60h] [bp-Ch]@3
  unsigned int v92; // [sp+60h] [bp-Ch]@67
  BlitArgs *i_argsa; // [sp+70h] [bp+4h]@9
  BlitArgs *i_argsb; // [sp+70h] [bp+4h]@70

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = i_args->cSrcArgs.pDstBuf;
    pSrc = i_args->cSrcArgs.pDstBuf;
    pDst = i_args->cDstArgs.pDstBuf;
    iModifiera = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      idxX = i_args->nWidth;
      v91 = i_args->cSrcArgs.iStride;
      v77 = i_args->cDstArgs.iStride;
      v87 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = v2 - v1;
          v5 = (int)&v1[4 * v3];
          v89 = v4;
          v81 = v3;
          do
          {
            v6 = *(_DWORD *)(v4 + v5 - 4);
            v5 -= 4;
            v7 = g_SourceColor.u | v6 & 0xFF000000;
            v8 = v7 >> 16;
            v9 = BYTE1(v8) != 0;
            v80 = v5;
            v10 = v9 + BYTE1(v8);
            v74 = v9 + BYTE1(v8);
            if ( iModifiera != 256 )
            {
              v10 = iModifiera * v10 / 256;
              v74 = v10;
            }
            if ( v10 )
            {
              v11 = *(BlitArgs **)v5;
              v12 = (unsigned __int8)v7;
              v13 = BYTE1(v7);
              i_argsa = v11;
              v14 = ((unsigned __int8)v8 != 0) + (unsigned __int8)v8;
              v15 = v14;
              v16 = (v13 != 0) + v13;
              v17 = v14;
              v18 = (v12 != 0) + v12;
              if ( v16 <= v14 )
              {
                if ( v16 < v14 )
                  v17 = v16;
              }
              else
              {
                v15 = v16;
              }
              if ( v18 <= v15 )
              {
                if ( v18 < v17 )
                  v17 = v18;
              }
              else
              {
                v15 = v18;
              }
              v79 = v15 - v17;
              if ( v15 == v17 )
              {
                v19 = 0;
                v20 = 0;
                v64 = 0;
              }
              else
              {
                v21 = 0;
                v64 = (v79 << 8) / v15;
                if ( v14 == v15 )
                {
                  v22 = v16 - v18;
                  if ( v16 - v18 < 0 )
                    v21 = 24576;
                }
                else if ( v16 == v15 )
                {
                  v22 = v18 - v14;
                  v21 = 0x2000;
                }
                else
                {
                  v22 = v14 - v16;
                  v21 = 0x4000;
                }
                v20 = (v79 << 8) / v15;
                v19 = v21 + (v22 << 12) / v79;
                v10 = v74;
              }
              v23 = BYTE2(i_argsa) + (BYTE2(i_argsa) != 0);
              if ( (BYTE1(i_argsa) != 0) + BYTE1(i_argsa) > v23 )
                v23 = (BYTE1(i_argsa) != 0) + BYTE1(i_argsa);
              if ( ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa > v23 )
                v23 = ((unsigned __int8)i_argsa != 0) + (unsigned __int8)i_argsa;
              if ( v10 == 256 )
              {
                if ( v20 )
                {
                  v25 = v19 / 4096;
                  v26 = v64 * v23 / 256;
                  v27 = v26 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v28 = v23 - v26;
                  v29 = v27 / 4096;
                  if ( v27 % 4096 < -2048 )
                    --v29;
                  if ( v27 % 4096 > 2048 )
                    ++v29;
                  switch ( v25 )
                  {
                    case 0:
                      v24 = v23;
                      v63 = v23 - v26;
                      v23 = v28 + v29;
                      break;
                    case 1:
                      v63 = v23 - v26;
                      v24 = v28 - v29;
                      break;
                    case 2:
                      v24 = v23 - v26;
                      v63 = v29 + v28;
                      break;
                    case 3:
                      v24 = v23 - v26;
                      v63 = v23;
                      v23 = v28 - v29;
                      break;
                    case 4:
                      v63 = v23;
                      v23 -= v26;
                      v24 = v28 + v29;
                      break;
                    case 5:
                      v24 = v23;
                      v23 -= v26;
                      v63 = v28 - v29;
                      break;
                    default:
                      goto LABEL_33;
                  }
                }
                else
                {
                  v68 = v23;
                  v66 = v23;
                  v63 = v23;
LABEL_33:
                  v24 = v68;
                  v23 = v66;
                }
                v68 = v24 - (v24 != 0);
                BYTE2(i_argsa) = v24 - (v24 != 0);
                v66 = v23 - (v23 != 0);
                BYTE1(i_argsa) = v23 - (v23 != 0);
                v63 -= v63 != 0;
                LOBYTE(i_argsa) = v63;
              }
              else
              {
                if ( v20 )
                {
                  v33 = v19 / 4096;
                  v34 = v64 * v23 / 256;
                  v35 = v34 * (v19 - ((v19 / 4096 + 1) / 2 << 13));
                  v36 = v23 - v34;
                  v37 = v35 / 4096;
                  if ( v35 % 4096 < -2048 )
                    --v37;
                  if ( v35 % 4096 > 2048 )
                    ++v37;
                  switch ( v33 )
                  {
                    case 0:
                      v30 = v23;
                      v31 = v23 - v34;
                      v23 = v36 + v37;
                      break;
                    case 1:
                      v31 = v23 - v34;
                      v30 = v36 - v37;
                      break;
                    case 2:
                      v30 = v23 - v34;
                      v31 = v36 + v37;
                      break;
                    case 3:
                      v30 = v23 - v34;
                      v31 = v23;
                      v23 = v36 - v37;
                      break;
                    case 4:
                      v31 = v23;
                      v23 -= v34;
                      v30 = v36 + v37;
                      break;
                    case 5:
                      v30 = v23;
                      v23 -= v34;
                      v31 = v36 - v37;
                      break;
                    default:
                      goto LABEL_48;
                  }
                }
                else
                {
                  v70 = v23;
                  v71 = v23;
                  v72 = v23;
LABEL_48:
                  v30 = v70;
                  v23 = v71;
                  v31 = v72;
                }
                v70 = v30 - (v30 != 0);
                v71 = v23 - (v23 != 0);
                BYTE2(i_argsa) -= v74 * (BYTE2(i_argsa) - v70) / 256;
                v72 = v31 - (v31 != 0);
                BYTE1(i_argsa) -= v74 * (BYTE1(i_argsa) - v71) / 256;
                LOBYTE(i_argsa) = (_BYTE)i_argsa - v74 * ((unsigned __int8)i_argsa - v72) / 256;
              }
              v4 = v89;
              *(_DWORD *)v80 = i_argsa;
              v5 = v80;
            }
            --v81;
          }
          while ( v81 );
          v1 = pDst;
          v3 = idxX;
        }
        v2 = &pSrc[v91];
        v1 += v77;
        v32 = v87 == 1;
        pSrc += v91;
        pDst = v1;
        --v87;
      }
      while ( !v32 );
    }
  }
  else
  {
    v69 = i_args->cDstArgs.pDstBuf;
    v65 = g_SourceColor.u;
    BYTE3(v65) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v92 = i_args->nWidth;
      v78 = i_args->cDstArgs.iStride;
      v82 = i_args->nHeight;
      do
      {
        v38 = v92;
        while ( v38 )
        {
          --v38;
          pSrca = (const char *)v38;
          pDsta = (char *)((v65 >> 24 != 0) + (v65 >> 24));
          if ( pDsta )
          {
            i_argsb = *(BlitArgs **)&v69[4 * v38];
            v39 = (BYTE2(v65) != 0) + BYTE2(v65);
            v40 = BYTE1(v65) != 0;
            v41 = v39;
            v42 = v40 + BYTE1(v65);
            v43 = ((unsigned __int8)v65 != 0) + (unsigned __int8)v65;
            v44 = (BYTE2(v65) != 0) + BYTE2(v65);
            if ( v42 <= v39 )
            {
              if ( v42 < v39 )
                v44 = v40 + BYTE1(v65);
            }
            else
            {
              v41 = v40 + BYTE1(v65);
            }
            if ( v43 <= v41 )
            {
              if ( v43 < v44 )
                v44 = ((unsigned __int8)v65 != 0) + (unsigned __int8)v65;
            }
            else
            {
              v41 = ((unsigned __int8)v65 != 0) + (unsigned __int8)v65;
            }
            v88 = v41 - v44;
            if ( v41 == v44 )
            {
              v45 = 0;
              v46 = 0;
              v67 = 0;
            }
            else
            {
              v47 = 0;
              v67 = (v88 << 8) / v41;
              if ( v39 == v41 )
              {
                v48 = v42 - v43;
                if ( v42 - v43 < 0 )
                  v47 = 24576;
              }
              else if ( v42 == v41 )
              {
                v48 = v43 - v39;
                v47 = 0x2000;
              }
              else
              {
                v48 = v39 - v42;
                v47 = 0x4000;
              }
              v45 = v47 + (v48 << 12) / v88;
              v46 = (v88 << 8) / v41;
            }
            v49 = BYTE2(i_argsb) + (BYTE2(i_argsb) != 0);
            if ( (BYTE1(i_argsb) != 0) + BYTE1(i_argsb) > v49 )
              v49 = (BYTE1(i_argsb) != 0) + BYTE1(i_argsb);
            if ( ((unsigned __int8)i_argsb != 0) + (unsigned __int8)i_argsb > v49 )
              v49 = ((unsigned __int8)i_argsb != 0) + (unsigned __int8)i_argsb;
            if ( pDsta == (char *)256 )
            {
              if ( v46 )
              {
                v51 = v45 / 4096;
                v52 = v67 * v49 / 256;
                v53 = v52 * (v45 - ((v45 / 4096 + 1) / 2 << 13));
                v54 = v49 - v52;
                v55 = v53 / 4096;
                if ( v53 % 4096 < -2048 )
                  --v55;
                if ( v53 % 4096 > 2048 )
                  ++v55;
                switch ( v51 )
                {
                  case 0:
                    v50 = v49;
                    v63 = v49 - v52;
                    v49 = v54 + v55;
                    break;
                  case 1:
                    v63 = v49 - v52;
                    v50 = v54 - v55;
                    break;
                  case 2:
                    v50 = v49 - v52;
                    v63 = v55 + v54;
                    break;
                  case 3:
                    v50 = v49 - v52;
                    v63 = v49;
                    v49 = v54 - v55;
                    break;
                  case 4:
                    v63 = v49;
                    v49 -= v52;
                    v50 = v54 + v55;
                    break;
                  case 5:
                    v50 = v49;
                    v49 -= v52;
                    v63 = v54 - v55;
                    break;
                  default:
                    goto LABEL_94;
                }
              }
              else
              {
                v73 = v49;
                v72 = v49;
                v63 = v49;
LABEL_94:
                v50 = v73;
                v49 = v72;
              }
              v73 = v50 - (v50 != 0);
              BYTE2(i_argsb) = v50 - (v50 != 0);
              v72 = v49 - (v49 != 0);
              BYTE1(i_argsb) = v49 - (v49 != 0);
              v63 -= v63 != 0;
              LOBYTE(i_argsb) = v63;
            }
            else
            {
              if ( v46 )
              {
                v58 = v45 / 4096;
                v59 = v67 * v49 / 256;
                v60 = v59 * (v45 - ((v45 / 4096 + 1) / 2 << 13));
                v61 = v49 - v59;
                v62 = v60 / 4096;
                if ( v60 % 4096 < -2048 )
                  --v62;
                if ( v60 % 4096 > 2048 )
                  ++v62;
                switch ( v58 )
                {
                  case 0:
                    v57 = v49;
                    v56 = v49 - v59;
                    v49 = v61 + v62;
                    break;
                  case 1:
                    v56 = v49 - v59;
                    v57 = v61 - v62;
                    break;
                  case 2:
                    v57 = v49 - v59;
                    v56 = v61 + v62;
                    break;
                  case 3:
                    v57 = v49 - v59;
                    v56 = v49;
                    v49 = v61 - v62;
                    break;
                  case 4:
                    v56 = v49;
                    v49 -= v59;
                    v57 = v61 + v62;
                    break;
                  case 5:
                    v57 = v49;
                    v49 -= v59;
                    v56 = v61 - v62;
                    break;
                  default:
                    goto LABEL_109;
                }
              }
              else
              {
                v71 = v49;
                v70 = v49;
                iModifier = v49;
LABEL_109:
                v56 = iModifier;
                v49 = v70;
                v57 = v71;
              }
              v71 = v57 - (v57 != 0);
              v70 = v49 - (v49 != 0);
              BYTE2(i_argsb) -= (signed int)pDsta * (BYTE2(i_argsb) - v71) / 256;
              iModifier = v56 - (v56 != 0);
              BYTE1(i_argsb) -= (signed int)pDsta * (BYTE1(i_argsb) - v70) / 256;
              LOBYTE(i_argsb) = (_BYTE)i_argsb - (signed int)pDsta * ((unsigned __int8)i_argsb - iModifier) / 256;
            }
            v38 = (unsigned int)pSrca;
            *(_DWORD *)&v69[4 * (_DWORD)pSrca] = i_argsb;
          }
        }
        v32 = v82 == 1;
        v69 -= v78;
        --v82;
      }
      while ( !v32 );
    }
  }
  _m_femms();
}

//----- (006682A0) --------------------------------------------------------  // acclient.c:638972
void __cdecl ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // esi@1
  unsigned int v2; // edi@4
  int v3; // esi@5
  int v4; // ecx@6
  unsigned int v5; // ecx@6
  unsigned int v6; // ebx@6
  int v7; // eax@6
  int v8; // ebp@6
  unsigned __int8 v9; // al@9
  unsigned __int8 v10; // dl@9
  int v11; // edi@9
  int v12; // esi@9
  int v13; // ecx@9
  signed int v14; // ebp@9
  int v15; // esi@9
  int v16; // edi@9
  int v17; // eax@9
  signed int v18; // esi@18
  int v19; // ebp@18
  signed int v20; // ebx@19
  int v21; // ecx@20
  int v22; // ecx@26
  int v23; // edx@33
  int v24; // edx@34
  int v25; // ecx@34
  char v26; // bl@34
  char v27; // cl@34
  int v28; // ebx@35
  int v29; // ebp@35
  signed int v30; // esi@35
  int v31; // edi@35
  int v32; // eax@35
  int v33; // esi@48
  int v34; // ecx@49
  bool v35; // zf@52
  int v36; // ebx@54
  int v37; // ebp@54
  signed int v38; // esi@54
  int v39; // edi@54
  int v40; // eax@54
  unsigned int v41; // ecx@66
  int v42; // eax@68
  int v43; // edx@69
  int v44; // ebx@69
  int v45; // ecx@70
  signed int v46; // ebp@70
  int v47; // esi@70
  int v48; // edx@70
  int v49; // eax@70
  int v50; // edi@70
  signed int v51; // esi@79
  int v52; // ebp@79
  signed int v53; // ebx@80
  int v54; // ecx@81
  int v55; // ecx@87
  int v56; // edx@94
  int v57; // ebx@94
  int v58; // edx@95
  int v59; // ebx@95
  char v60; // cl@95
  char v61; // dl@95
  char v62; // bl@95
  int v63; // ebx@96
  int v64; // ebp@96
  signed int v65; // esi@96
  int v66; // edi@96
  int v67; // eax@96
  int v68; // ebp@109
  int v69; // esi@109
  int v70; // edx@109
  int v71; // edx@110
  int v72; // ebx@115
  int v73; // ebp@115
  signed int v74; // esi@115
  int v75; // edi@115
  int v76; // eax@115
  unsigned __int8 v77; // [sp+10h] [bp-58h]@9
  unsigned __int8 v78; // [sp+10h] [bp-58h]@70
  unsigned __int8 v79; // [sp+11h] [bp-57h]@9
  unsigned __int8 v80; // [sp+11h] [bp-57h]@70
  unsigned __int8 v81; // [sp+12h] [bp-56h]@9
  unsigned __int8 v82; // [sp+12h] [bp-56h]@70
  int v83; // [sp+14h] [bp-54h]@18
  unsigned int v84; // [sp+14h] [bp-54h]@65
  int v85; // [sp+18h] [bp-50h]@0
  int v86; // [sp+18h] [bp-50h]@79
  int v87; // [sp+1Ch] [bp-4Ch]@0
  unsigned int v88; // [sp+1Ch] [bp-4Ch]@66
  int v89; // [sp+20h] [bp-48h]@0
  int v90; // [sp+24h] [bp-44h]@0
  int v91; // [sp+28h] [bp-40h]@0
  int v92; // [sp+2Ch] [bp-3Ch]@0
  int v93; // [sp+2Ch] [bp-3Ch]@6
  const char *pSrc; // [sp+30h] [bp-38h]@0
  char *pSrca; // [sp+30h] [bp-38h]@2
  unsigned int v96; // [sp+34h] [bp-34h]@3
  unsigned int v97; // [sp+34h] [bp-34h]@66
  int iModifier; // [sp+38h] [bp-30h]@2
  int iModifiera; // [sp+38h] [bp-30h]@65
  signed int v100; // [sp+3Ch] [bp-2Ch]@17
  unsigned int v101; // [sp+3Ch] [bp-2Ch]@68
  int v102; // [sp+40h] [bp-28h]@6
  int v103; // [sp+40h] [bp-28h]@69
  char *pDst; // [sp+44h] [bp-24h]@2
  char *pDsta; // [sp+44h] [bp-24h]@69
  unsigned int v106; // [sp+48h] [bp-20h]@3
  signed int v107; // [sp+48h] [bp-20h]@78
  unsigned int v108; // [sp+4Ch] [bp-1Ch]@3
  unsigned int v109; // [sp+4Ch] [bp-1Ch]@66
  unsigned int idxX; // [sp+58h] [bp-10h]@6
  unsigned int v111; // [sp+5Ch] [bp-Ch]@3
  unsigned int v112; // [sp+5Ch] [bp-Ch]@68

  v1 = (int)i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    pSrca = i_args->cSrcArgs.pDstBuf;
    pDst = i_args->cDstArgs.pDstBuf;
    iModifier = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v108 = i_args->nWidth;
      v111 = i_args->cSrcArgs.iStride;
      v96 = i_args->cDstArgs.iStride;
      v106 = i_args->nHeight;
      do
      {
        v2 = v108;
        if ( v108 )
        {
          v3 = v108 + v1 + 2 * v108 + 2;
          do
          {
            v4 = *(_DWORD *)&pSrca[4 * v2-- - 4];
            v5 = g_SourceColor.u | v4 & 0xFF000000;
            v6 = v5 >> 16;
            v3 -= 3;
            v7 = BYTE1(v6) != 0;
            idxX = v2;
            v102 = v3;
            v8 = v7 + BYTE1(v6);
            v93 = v7 + BYTE1(v6);
            if ( iModifier != 256 )
            {
              v8 = iModifier * v8 / 256;
              v93 = v8;
            }
            if ( v8 )
            {
              v9 = *(_BYTE *)(v3 - 1);
              v77 = *(_BYTE *)(v3 - 2);
              v10 = *(_BYTE *)v3;
              v11 = (unsigned __int8)v5;
              v12 = BYTE1(v5);
              v79 = v9;
              v81 = v10;
              v13 = ((unsigned __int8)v6 != 0) + (unsigned __int8)v6;
              v14 = v13;
              v15 = (v12 != 0) + v12;
              v16 = (v11 != 0) + v11;
              v17 = ((unsigned __int8)v6 != 0) + (unsigned __int8)v6;
              if ( v15 <= v13 )
              {
                if ( v15 < v13 )
                  v17 = v15;
              }
              else
              {
                v14 = v15;
              }
              if ( v16 <= v14 )
              {
                if ( v16 < v17 )
                  v17 = v16;
              }
              else
              {
                v14 = v16;
              }
              v100 = v14 - v17;
              if ( v14 == v17 )
              {
                v18 = 0;
                v19 = 0;
                v83 = 0;
              }
              else
              {
                v20 = 0;
                v83 = (v100 << 8) / v14;
                if ( v13 == v14 )
                {
                  v21 = v15 - v16;
                  if ( v15 - v16 < 0 )
                    v20 = 24576;
                }
                else if ( v15 == v14 )
                {
                  v21 = v16 - v13;
                  v20 = 0x2000;
                }
                else
                {
                  v21 = v13 - v15;
                  v20 = 0x4000;
                }
                v19 = (v100 << 8) / v14;
                v18 = v20 + (v21 << 12) / v100;
              }
              v22 = v10 + (v10 != 0);
              if ( (v79 != 0) + v79 > v22 )
                v22 = (v79 != 0) + v79;
              if ( (v77 != 0) + v77 > v22 )
                v22 = (v77 != 0) + v77;
              if ( v93 == 256 )
              {
                if ( v19 )
                {
                  v28 = v18 / 4096;
                  v29 = v83 * v22 / 256;
                  v30 = v29 * (v18 - ((v18 / 4096 + 1) / 2 << 13));
                  v31 = v22 - v29;
                  v32 = v30 / 4096;
                  if ( v30 % 4096 < -2048 )
                    --v32;
                  if ( v30 % 4096 > 2048 )
                    ++v32;
                  switch ( v28 )
                  {
                    case 0:
                      v23 = v22;
                      i_args = (BlitArgs *)(v22 - v29);
                      v22 = v31 + v32;
                      break;
                    case 1:
                      i_args = (BlitArgs *)(v22 - v29);
                      v23 = v31 - v32;
                      break;
                    case 2:
                      v23 = v22 - v29;
                      i_args = (BlitArgs *)(v32 + v31);
                      break;
                    case 3:
                      v23 = v22 - v29;
                      i_args = (BlitArgs *)v22;
                      v22 = v31 - v32;
                      break;
                    case 4:
                      i_args = (BlitArgs *)v22;
                      v22 -= v29;
                      v23 = v31 + v32;
                      break;
                    case 5:
                      v23 = v22;
                      v22 -= v29;
                      i_args = (BlitArgs *)(v31 - v32);
                      break;
                    default:
                      goto LABEL_33;
                  }
                }
                else
                {
                  v85 = v22;
                  v87 = v22;
                  i_args = (BlitArgs *)v22;
LABEL_33:
                  v22 = v87;
                  v23 = v85;
                }
                v24 = v23 - (v23 != 0);
                v85 = v24;
                v25 = v22 - (v22 != 0);
                v87 = v25;
                v26 = v25;
                i_args = (BlitArgs *)((char *)i_args - (i_args != 0));
                v27 = (char)i_args;
              }
              else
              {
                if ( v19 )
                {
                  v36 = v18 / 4096;
                  v37 = v83 * v22 / 256;
                  v38 = v37 * (v18 - ((v18 / 4096 + 1) / 2 << 13));
                  v39 = v22 - v37;
                  v40 = v38 / 4096;
                  if ( v38 % 4096 < -2048 )
                    --v40;
                  if ( v38 % 4096 > 2048 )
                    ++v40;
                  switch ( v36 )
                  {
                    case 0:
                      v24 = v22;
                      v33 = v22 - v37;
                      v22 = v39 + v40;
                      break;
                    case 1:
                      v33 = v22 - v37;
                      v24 = v39 - v40;
                      break;
                    case 2:
                      v24 = v22 - v37;
                      v33 = v39 + v40;
                      break;
                    case 3:
                      v24 = v22 - v37;
                      v33 = v22;
                      v22 = v39 - v40;
                      break;
                    case 4:
                      v33 = v22;
                      v22 -= v37;
                      v24 = v39 + v40;
                      break;
                    case 5:
                      v24 = v22;
                      v22 -= v37;
                      v33 = v39 - v40;
                      break;
                    default:
                      goto LABEL_48;
                  }
                }
                else
                {
                  v89 = v22;
                  v90 = v22;
                  v91 = v22;
LABEL_48:
                  v24 = v89;
                  v22 = v90;
                  v33 = v91;
                }
                v89 = v24 - (v24 != 0);
                v34 = v22 - (v22 != 0);
                v90 = v34;
                v26 = v79 - v93 * (v79 - v34) / 256;
                LOBYTE(v24) = v81 - v93 * (v81 - v89) / 256;
                v91 = v33 - (v33 != 0);
                v27 = v77 - v93 * (v77 - v91) / 256;
              }
              v2 = idxX;
              *(_BYTE *)(v102 - 2) = v27;
              *(_BYTE *)(v102 - 1) = v26;
              *(_BYTE *)v102 = v24;
              v3 = v102;
            }
          }
          while ( v2 );
        }
        v1 = (int)&pDst[v96];
        v35 = v106 == 1;
        pSrca += v111;
        pDst += v96;
        --v106;
      }
      while ( !v35 );
    }
  }
  else
  {
    v84 = g_SourceColor.u;
    iModifiera = (int)i_args->cDstArgs.pDstBuf;
    BYTE3(v84) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v41 = i_args->nWidth;
      v109 = i_args->nWidth;
      v97 = i_args->cDstArgs.iStride;
      v88 = i_args->nHeight;
      do
      {
        if ( v41 )
        {
          v112 = v84 >> 24;
          v42 = v41 + v1 + 2 * v41 + 2;
          v101 = v41;
          do
          {
            v42 -= 3;
            v43 = v112 != 0;
            v103 = v42;
            v44 = v43 + v112;
            pDsta = (char *)(v43 + v112);
            if ( v43 + v112 )
            {
              v78 = *(_BYTE *)(v42 - 2);
              v80 = *(_BYTE *)(v42 - 1);
              v82 = *(_BYTE *)v42;
              v45 = (BYTE2(v84) != 0) + BYTE2(v84);
              v46 = v45;
              v47 = (BYTE1(v84) != 0) + BYTE1(v84);
              v48 = (unsigned __int8)v84 != 0;
              v49 = (BYTE2(v84) != 0) + BYTE2(v84);
              v50 = v48 + (unsigned __int8)v84;
              if ( v47 <= v45 )
              {
                if ( v47 < v45 )
                  v49 = (BYTE1(v84) != 0) + BYTE1(v84);
              }
              else
              {
                v46 = (BYTE1(v84) != 0) + BYTE1(v84);
              }
              if ( v50 <= v46 )
              {
                if ( v50 < v49 )
                  v49 = v48 + (unsigned __int8)v84;
              }
              else
              {
                v46 = v48 + (unsigned __int8)v84;
              }
              v107 = v46 - v49;
              if ( v46 == v49 )
              {
                v51 = 0;
                v52 = 0;
                v86 = 0;
              }
              else
              {
                v53 = 0;
                v86 = (v107 << 8) / v46;
                if ( v45 == v46 )
                {
                  v54 = v47 - v50;
                  if ( v47 - v50 < 0 )
                    v53 = 24576;
                }
                else if ( v47 == v46 )
                {
                  v54 = v50 - v45;
                  v53 = 0x2000;
                }
                else
                {
                  v54 = v45 - v47;
                  v53 = 0x4000;
                }
                v52 = (v107 << 8) / v46;
                v51 = v53 + (v54 << 12) / v107;
                v44 = (int)pDsta;
              }
              v55 = v82 + (v82 != 0);
              if ( (v80 != 0) + v80 > v55 )
                v55 = (v80 != 0) + v80;
              if ( (v78 != 0) + v78 > v55 )
                v55 = (v78 != 0) + v78;
              if ( v44 == 256 )
              {
                if ( v52 )
                {
                  v63 = v51 / 4096;
                  v64 = v86 * v55 / 256;
                  v65 = v64 * (v51 - ((v51 / 4096 + 1) / 2 << 13));
                  v66 = v55 - v64;
                  v67 = v65 / 4096;
                  if ( v65 % 4096 < -2048 )
                    --v67;
                  if ( v65 % 4096 > 2048 )
                    ++v67;
                  switch ( v63 )
                  {
                    case 0:
                      v56 = v55;
                      i_args = (BlitArgs *)(v55 - v64);
                      v57 = v66 + v67;
                      break;
                    case 1:
                      i_args = (BlitArgs *)(v55 - v64);
                      v57 = v55;
                      v56 = v66 - v67;
                      break;
                    case 2:
                      v56 = v55 - v64;
                      v57 = v55;
                      i_args = (BlitArgs *)(v67 + v66);
                      break;
                    case 3:
                      v56 = v55 - v64;
                      i_args = (BlitArgs *)v55;
                      v57 = v66 - v67;
                      break;
                    case 4:
                      i_args = (BlitArgs *)v55;
                      v57 = v55 - v64;
                      v56 = v66 + v67;
                      break;
                    case 5:
                      v57 = v55 - v64;
                      v56 = v55;
                      i_args = (BlitArgs *)(v66 - v67);
                      break;
                    default:
                      goto LABEL_94;
                  }
                }
                else
                {
                  pSrc = (const char *)v55;
                  v92 = v55;
                  i_args = (BlitArgs *)v55;
LABEL_94:
                  v56 = (int)pSrc;
                  v57 = v92;
                }
                v58 = v56 - (v56 != 0);
                pSrc = (const char *)v58;
                v59 = v57 - (v57 != 0);
                v92 = v59;
                v60 = v58;
                v61 = v59;
                i_args = (BlitArgs *)((char *)i_args - (i_args != 0));
                v62 = (char)i_args;
              }
              else
              {
                if ( v52 )
                {
                  v72 = v51 / 4096;
                  v73 = v86 * v55 / 256;
                  v74 = v73 * (v51 - ((v51 / 4096 + 1) / 2 << 13));
                  v75 = v55 - v73;
                  v76 = v74 / 4096;
                  if ( v74 % 4096 < -2048 )
                    --v76;
                  if ( v74 % 4096 > 2048 )
                    ++v76;
                  switch ( v72 )
                  {
                    case 0:
                      v70 = v55;
                      v68 = v55 - v73;
                      v69 = v75 + v76;
                      break;
                    case 1:
                      v68 = v55 - v73;
                      v69 = v55;
                      v70 = v75 - v76;
                      break;
                    case 2:
                      v69 = v55;
                      v70 = v55 - v73;
                      v68 = v75 + v76;
                      break;
                    case 3:
                      v70 = v55 - v73;
                      v68 = v55;
                      v69 = v75 - v76;
                      break;
                    case 4:
                      v68 = v55;
                      v69 = v75;
                      v70 = v75 + v76;
                      break;
                    case 5:
                      v69 = v55 - v73;
                      v70 = v55;
                      v68 = v75 - v76;
                      break;
                    default:
                      goto LABEL_109;
                  }
                }
                else
                {
                  v91 = v55;
                  v90 = v55;
                  v89 = v55;
LABEL_109:
                  v68 = v89;
                  v69 = v90;
                  v70 = v91;
                }
                v71 = v70 - (v70 != 0);
                v91 = v71;
                v90 = v69 - (v69 != 0);
                v60 = v82 - (signed int)pDsta * (v82 - v71) / 256;
                v61 = v80 - (signed int)pDsta * (v80 - v90) / 256;
                v89 = v68 - (v68 != 0);
                v62 = v78 - (signed int)pDsta * (v78 - v89) / 256;
              }
              v42 = v103;
              *(_BYTE *)v103 = v60;
              v41 = v109;
              *(_BYTE *)(v103 - 2) = v62;
              *(_BYTE *)(v103 - 1) = v61;
            }
            --v101;
          }
          while ( v101 );
        }
        v1 = iModifiera - v97;
        v35 = v88 == 1;
        iModifiera -= v97;
        --v88;
      }
      while ( !v35 );
    }
  }
  _m_femms();
}

//----- (00668C00) --------------------------------------------------------  // acclient.c:639581
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edi@2
  int v2; // esi@2
  unsigned int v3; // ecx@4
  int v4; // ebx@5
  int v5; // eax@6
  __m64 v6; // mm3@9
  __m64 v7; // mm0@9
  __m64 v8; // mm1@9
  __m64 v9; // mm1@9
  __m64 v10; // mm0@10
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  char *v14; // esi@16
  unsigned int v15; // ecx@18
  unsigned int v16; // eax@19
  __m64 v17; // mm3@20
  __m64 v18; // mm0@20
  __m64 v19; // mm1@20
  __m64 v20; // mm1@20
  __m64 v21; // mm0@21
  __m64 v22; // mm3@22
  __m64 v23; // mm4@22
  __m64 v24; // mm3@22
  unsigned int v25; // [sp+10h] [bp-10h]@3
  unsigned int v26; // [sp+10h] [bp-10h]@17
  unsigned int v27; // [sp+14h] [bp-Ch]@3
  unsigned int v28; // [sp+14h] [bp-Ch]@16
  unsigned int v29; // [sp+18h] [bp-8h]@3
  unsigned int v30; // [sp+18h] [bp-8h]@17
  unsigned int v31; // [sp+1Ch] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v25 = i_args->nWidth;
      v29 = i_args->cDstArgs.iStride;
      v27 = i_args->nHeight;
      do
      {
        v3 = v25;
        if ( v25 )
        {
          v4 = BYTE3(g_SourceColor.u);
          do
          {
            --v3;
            v5 = (v4 != 0) + v4;
            if ( v2 != 256 )
              v5 = v2 * v5 / 256;
            if ( v5 )
            {
              v6 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v3]), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64);
              v9 = _m_por(
                     _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v8, _m_pcmpgtw(v8, 0i64)), v7), 8u), v6),
                     _m_pandn(v6, v7));
              if ( v5 == 256 )
              {
                v10 = v9;
              }
              else
              {
                v11 = _mm_cvtsi32_si64(v5);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v10 = _m_psubw(v7, _m_psubw(_m_psrlw(_m_pmullw(v7, v13), 8u), _m_psrlw(_m_pmullw(v9, v13), 8u)));
              }
              *(_DWORD *)&v1[4 * v3] = _mm_cvtsi64_si32(_m_packuswb(v10, 0i64));
            }
          }
          while ( v3 );
        }
        v1 += v29;
        --v27;
      }
      while ( v27 );
    }
  }
  else
  {
    v14 = i_args->cDstArgs.pDstBuf;
    v28 = g_SourceColor.u;
    BYTE3(v28) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v26 = i_args->nWidth;
      v30 = i_args->cDstArgs.iStride;
      v31 = i_args->nHeight;
      do
      {
        v15 = v26;
        while ( v15 )
        {
          --v15;
          v16 = (v28 >> 24 != 0) + (v28 >> 24);
          if ( v16 )
          {
            v17 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v18 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v14[4 * v15]), 0i64);
            v19 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
            v20 = _m_por(
                    _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v19, _m_pcmpgtw(v19, 0i64)), v18), 8u), v17),
                    _m_pandn(v17, v18));
            if ( v16 == 256 )
            {
              v21 = v20;
            }
            else
            {
              v22 = _mm_cvtsi32_si64(v16);
              v23 = _m_punpcklwd(v22, v22);
              v24 = _m_punpcklwd(v23, v23);
              v21 = _m_psubw(v18, _m_psubw(_m_psrlw(_m_pmullw(v18, v24), 8u), _m_psrlw(_m_pmullw(v20, v24), 8u)));
            }
            *(_DWORD *)&v14[4 * v15] = _mm_cvtsi64_si32(_m_packuswb(v21, 0i64));
          }
        }
        v14 -= v30;
        --v31;
      }
      while ( v31 );
    }
  }
  _m_femms();
}

//----- (00668E30) --------------------------------------------------------  // acclient.c:639715
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@2
  int v2; // esi@2
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // ST10_4@9
  __m64 v8; // mm3@9
  __m64 v9; // mm0@9
  __m64 v10; // mm1@9
  __m64 v11; // mm1@9
  __m64 v12; // mm0@10
  __m64 v13; // mm3@11
  __m64 v14; // mm4@11
  __m64 v15; // mm3@11
  unsigned int v16; // ST10_4@12
  bool v17; // zf@14
  char *v18; // ebx@16
  unsigned int v19; // edi@17
  int v20; // eax@19
  unsigned int v21; // ecx@20
  unsigned int v22; // ST10_4@21
  __m64 v23; // mm3@21
  __m64 v24; // mm0@21
  __m64 v25; // mm1@21
  __m64 v26; // mm1@21
  __m64 v27; // mm0@22
  __m64 v28; // mm3@23
  __m64 v29; // mm4@23
  __m64 v30; // mm3@23
  unsigned int v31; // ST10_4@24
  unsigned int v32; // [sp+14h] [bp-14h]@5
  unsigned int v33; // [sp+14h] [bp-14h]@16
  unsigned int v34; // [sp+18h] [bp-10h]@3
  unsigned int v35; // [sp+18h] [bp-10h]@17
  char *v36; // [sp+1Ch] [bp-Ch]@2
  char *v37; // [sp+1Ch] [bp-Ch]@16
  unsigned int v38; // [sp+20h] [bp-8h]@3
  unsigned int v39; // [sp+20h] [bp-8h]@19
  unsigned int v40; // [sp+24h] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v36 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v34 = i_args->cDstArgs.iStride;
      v38 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = BYTE3(g_SourceColor.u);
          v5 = (int)(&v1[2 * v3 + 2] + v3);
          v32 = v3;
          do
          {
            v5 -= 3;
            v6 = (v4 != 0) + v4;
            if ( v2 != 256 )
              v6 = v2 * v6 / 256;
            if ( v6 )
            {
              LOBYTE(v7) = *(_BYTE *)(v5 - 2);
              BYTE1(v7) = *(_BYTE *)(v5 - 1);
              BYTE2(v7) = *(_BYTE *)v5;
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v7) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64);
              v11 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v10, _m_pcmpgtw(v10, 0i64)), v9), 8u), v8),
                      _m_pandn(v8, v9));
              if ( v6 == 256 )
              {
                v12 = v11;
              }
              else
              {
                v13 = _mm_cvtsi32_si64(v6);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                v12 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v15), 8u), _m_psrlw(_m_pmullw(v11, v15), 8u)));
              }
              v16 = _mm_cvtsi64_si32(_m_packuswb(v12, 0i64));
              *(_BYTE *)(v5 - 2) = v16;
              *(_BYTE *)(v5 - 1) = BYTE1(v16);
              *(_BYTE *)v5 = v16 >> 16;
            }
            --v32;
          }
          while ( v32 );
        }
        v1 = &v36[v34];
        v17 = v38 == 1;
        v36 += v34;
        --v38;
      }
      while ( !v17 );
    }
  }
  else
  {
    v18 = i_args->cDstArgs.pDstBuf;
    v33 = g_SourceColor.u;
    v37 = i_args->cDstArgs.pDstBuf;
    BYTE3(v33) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v19 = i_args->nWidth;
      v35 = i_args->cDstArgs.iStride;
      v40 = i_args->nHeight;
      do
      {
        if ( v19 )
        {
          v20 = (int)(&v18[2 * v19 + 2] + v19);
          v39 = v19;
          do
          {
            v20 -= 3;
            v21 = (v33 >> 24 != 0) + (v33 >> 24);
            if ( v21 )
            {
              LOBYTE(v22) = *(_BYTE *)(v20 - 2);
              BYTE1(v22) = *(_BYTE *)(v20 - 1);
              BYTE2(v22) = *(_BYTE *)v20;
              v23 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v22) = -1;
              v24 = _m_punpcklbw(_mm_cvtsi32_si64(v22), 0i64);
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(v33), 0i64);
              v26 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v25, _m_pcmpgtw(v25, 0i64)), v24), 8u), v23),
                      _m_pandn(v23, v24));
              if ( v21 == 256 )
              {
                v27 = v26;
              }
              else
              {
                v28 = _mm_cvtsi32_si64(v21);
                v29 = _m_punpcklwd(v28, v28);
                v30 = _m_punpcklwd(v29, v29);
                v27 = _m_psubw(v24, _m_psubw(_m_psrlw(_m_pmullw(v24, v30), 8u), _m_psrlw(_m_pmullw(v26, v30), 8u)));
              }
              v31 = _mm_cvtsi64_si32(_m_packuswb(v27, 0i64));
              *(_BYTE *)(v20 - 2) = v31;
              *(_BYTE *)(v20 - 1) = BYTE1(v31);
              *(_BYTE *)v20 = v31 >> 16;
            }
            --v39;
          }
          while ( v39 );
        }
        v18 = &v37[-v35];
        v17 = v40 == 1;
        v37 -= v35;
        --v40;
      }
      while ( !v17 );
    }
  }
  _m_femms();
}

//----- (006690E0) --------------------------------------------------------  // acclient.c:639886
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ebx@2
  int v2; // edi@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // ecx@5
  int v6; // eax@5
  __m64 v7; // mm3@8
  __m64 v8; // mm0@8
  __m64 v9; // mm1@8
  __m64 v10; // mm1@8
  __m64 v11; // mm0@9
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@13
  char *v16; // esi@15
  unsigned int v17; // ecx@17
  unsigned int v18; // eax@18
  __m64 v19; // mm3@19
  __m64 v20; // mm0@19
  __m64 v21; // mm1@19
  __m64 v22; // mm1@19
  __m64 v23; // mm0@20
  __m64 v24; // mm3@21
  __m64 v25; // mm4@21
  __m64 v26; // mm3@21
  char *v27; // [sp+10h] [bp-18h]@2
  unsigned int v28; // [sp+10h] [bp-18h]@15
  unsigned int v29; // [sp+14h] [bp-14h]@3
  unsigned int v30; // [sp+14h] [bp-14h]@16
  unsigned int v31; // [sp+18h] [bp-10h]@3
  unsigned int v32; // [sp+18h] [bp-10h]@16
  unsigned int v33; // [sp+1Ch] [bp-Ch]@3
  unsigned int v34; // [sp+1Ch] [bp-Ch]@16
  unsigned int v35; // [sp+24h] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cSrcArgs.pDstBuf;
    v27 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v29 = i_args->nWidth;
      v35 = i_args->cSrcArgs.iStride;
      v31 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        v3 = v29;
        while ( v3 )
        {
          v4 = (unsigned __int8)v1[v3-- - 1];
          v5 = g_SourceColor.u | (v4 << 24);
          v6 = (v5 >> 24 != 0) + (v5 >> 24);
          if ( v2 != 256 )
            v6 = v2 * v6 / 256;
          if ( v6 )
          {
            v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v8 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v27[4 * v3]), 0i64);
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
            v10 = _m_por(_m_pand(_m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u), v7), _m_pandn(v7, v8));
            if ( v6 == 256 )
            {
              v11 = v10;
            }
            else
            {
              v12 = _mm_cvtsi32_si64(v6);
              v13 = _m_punpcklwd(v12, v12);
              v14 = _m_punpcklwd(v13, v13);
              v11 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v14), 8u), _m_psrlw(_m_pmullw(v10, v14), 8u)));
            }
            *(_DWORD *)&v27[4 * v3] = _mm_cvtsi64_si32(_m_packuswb(v11, 0i64));
          }
        }
        v1 += v35;
        v15 = v33 == 1;
        v27 += v31;
        --v33;
      }
      while ( !v15 );
    }
  }
  else
  {
    v16 = i_args->cDstArgs.pDstBuf;
    v28 = g_SourceColor.u;
    BYTE3(v28) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v30 = i_args->nWidth;
      v32 = i_args->cDstArgs.iStride;
      v34 = i_args->nHeight;
      do
      {
        v17 = v30;
        while ( v17 )
        {
          --v17;
          v18 = (v28 >> 24 != 0) + (v28 >> 24);
          if ( v18 )
          {
            v19 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v20 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v16[4 * v17]), 0i64);
            v21 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
            v22 = _m_por(
                    _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v21, _m_pcmpgtw(v21, 0i64)), v20), 8u), v19),
                    _m_pandn(v19, v20));
            if ( v18 == 256 )
            {
              v23 = v22;
            }
            else
            {
              v24 = _mm_cvtsi32_si64(v18);
              v25 = _m_punpcklwd(v24, v24);
              v26 = _m_punpcklwd(v25, v25);
              v23 = _m_psubw(v20, _m_psubw(_m_psrlw(_m_pmullw(v20, v26), 8u), _m_psrlw(_m_pmullw(v22, v26), 8u)));
            }
            *(_DWORD *)&v16[4 * v17] = _mm_cvtsi64_si32(_m_packuswb(v23, 0i64));
          }
        }
        v16 -= v32;
        --v34;
      }
      while ( v34 );
    }
  }
  _m_femms();
}

//----- (00669340) --------------------------------------------------------  // acclient.c:640022
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  int v7; // eax@6
  unsigned int v8; // ST10_4@9
  __m64 v9; // mm3@9
  __m64 v10; // mm0@9
  __m64 v11; // mm1@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  unsigned int v17; // ST10_4@12
  bool v18; // zf@14
  char *v19; // ebx@16
  unsigned int v20; // edi@17
  int v21; // eax@19
  unsigned int v22; // ecx@20
  unsigned int v23; // ST10_4@21
  __m64 v24; // mm3@21
  __m64 v25; // mm0@21
  __m64 v26; // mm1@21
  __m64 v27; // mm1@21
  __m64 v28; // mm0@22
  __m64 v29; // mm3@23
  __m64 v30; // mm4@23
  __m64 v31; // mm3@23
  unsigned int v32; // ST10_4@24
  char *v33; // [sp+14h] [bp-1Ch]@2
  unsigned int v34; // [sp+14h] [bp-1Ch]@16
  unsigned int v35; // [sp+18h] [bp-18h]@3
  unsigned int v36; // [sp+18h] [bp-18h]@17
  char *v37; // [sp+1Ch] [bp-14h]@2
  char *v38; // [sp+1Ch] [bp-14h]@16
  unsigned int v39; // [sp+20h] [bp-10h]@3
  unsigned int v40; // [sp+20h] [bp-10h]@19
  unsigned int v41; // [sp+24h] [bp-Ch]@3
  unsigned int v42; // [sp+24h] [bp-Ch]@17
  unsigned int v43; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v33 = i_args->cSrcArgs.pDstBuf;
    v37 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v41 = i_args->nWidth;
      v43 = i_args->cSrcArgs.iStride;
      v35 = i_args->cDstArgs.iStride;
      v39 = i_args->nHeight;
      do
      {
        v3 = v41;
        if ( v41 )
        {
          v4 = (int)(&v1[2 * v41 + 2] + v41);
          do
          {
            v5 = (unsigned __int8)v33[v3-- - 1];
            v6 = g_SourceColor.u | (v5 << 24);
            v4 -= 3;
            v7 = (v6 >> 24 != 0) + (v6 >> 24);
            if ( v2 != 256 )
              v7 = v2 * v7 / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v4 - 2);
              BYTE1(v8) = *(_BYTE *)(v4 - 1);
              BYTE2(v8) = *(_BYTE *)v4;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v8) = -1;
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
              v12 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u), v9),
                      _m_pandn(v9, v10));
              if ( v7 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v7);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              v17 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
              *(_BYTE *)(v4 - 2) = v17;
              *(_BYTE *)(v4 - 1) = BYTE1(v17);
              *(_BYTE *)v4 = v17 >> 16;
            }
          }
          while ( v3 );
        }
        v1 = &v37[v35];
        v18 = v39 == 1;
        v33 += v43;
        v37 += v35;
        --v39;
      }
      while ( !v18 );
    }
  }
  else
  {
    v19 = i_args->cDstArgs.pDstBuf;
    v34 = g_SourceColor.u;
    BYTE3(v34) = i_args->i8AlphaModifier;
    v38 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v36 = i_args->cDstArgs.iStride;
      v42 = i_args->nHeight;
      do
      {
        if ( v20 )
        {
          v21 = (int)(&v19[2 * v20 + 2] + v20);
          v40 = v20;
          do
          {
            v21 -= 3;
            v22 = (v34 >> 24 != 0) + (v34 >> 24);
            if ( v22 )
            {
              LOBYTE(v23) = *(_BYTE *)(v21 - 2);
              BYTE1(v23) = *(_BYTE *)(v21 - 1);
              BYTE2(v23) = *(_BYTE *)v21;
              v24 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v23) = -1;
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64);
              v26 = _m_punpcklbw(_mm_cvtsi32_si64(v34), 0i64);
              v27 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v26, _m_pcmpgtw(v26, 0i64)), v25), 8u), v24),
                      _m_pandn(v24, v25));
              if ( v22 == 256 )
              {
                v28 = v27;
              }
              else
              {
                v29 = _mm_cvtsi32_si64(v22);
                v30 = _m_punpcklwd(v29, v29);
                v31 = _m_punpcklwd(v30, v30);
                v28 = _m_psubw(v25, _m_psubw(_m_psrlw(_m_pmullw(v25, v31), 8u), _m_psrlw(_m_pmullw(v27, v31), 8u)));
              }
              v32 = _mm_cvtsi64_si32(_m_packuswb(v28, 0i64));
              *(_BYTE *)(v21 - 2) = v32;
              *(_BYTE *)(v21 - 1) = BYTE1(v32);
              *(_BYTE *)v21 = v32 >> 16;
            }
            --v40;
          }
          while ( v40 );
        }
        v19 = &v38[-v36];
        v18 = v42 == 1;
        v38 -= v36;
        --v42;
      }
      while ( !v18 );
    }
  }
  _m_femms();
}

//----- (00669620) --------------------------------------------------------  // acclient.c:640199
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ecx@2
  int v2; // ebx@2
  unsigned int v3; // edx@3
  unsigned int *v4; // esi@5
  int v5; // edi@5
  int v6; // ecx@6
  unsigned int v7; // ecx@6
  int v8; // eax@6
  __m64 v9; // mm3@9
  __m64 v10; // mm0@9
  __m64 v11; // mm1@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  bool v17; // zf@15
  char *v18; // esi@17
  unsigned int v19; // ecx@19
  unsigned int v20; // eax@20
  __m64 v21; // mm3@21
  __m64 v22; // mm0@21
  __m64 v23; // mm1@21
  __m64 v24; // mm1@21
  __m64 v25; // mm0@22
  __m64 v26; // mm3@23
  __m64 v27; // mm4@23
  __m64 v28; // mm3@23
  char *v29; // [sp+10h] [bp-20h]@2
  unsigned int v30; // [sp+10h] [bp-20h]@17
  unsigned int v31; // [sp+14h] [bp-1Ch]@3
  unsigned int v32; // [sp+14h] [bp-1Ch]@18
  unsigned int v33; // [sp+18h] [bp-18h]@5
  char *v34; // [sp+1Ch] [bp-14h]@2
  unsigned int v35; // [sp+20h] [bp-10h]@3
  unsigned int v36; // [sp+20h] [bp-10h]@18
  unsigned int v37; // [sp+28h] [bp-8h]@3
  unsigned int v38; // [sp+2Ch] [bp-4h]@3
  unsigned int v39; // [sp+2Ch] [bp-4h]@18

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v29 = i_args->cSrcArgs.pDstBuf;
    v1 = i_args->cDstArgs.pDstBuf;
    v34 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v37 = i_args->nWidth;
      v38 = i_args->cSrcArgs.iStride;
      v31 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v5 = v29 - v1;
          v33 = v3;
          do
          {
            v6 = *(unsigned int *)((char *)v4 + v5 - 4);
            --v4;
            v7 = g_SourceColor.u | v6 & 0xFF000000;
            v8 = (v7 >> 24 != 0) + (v7 >> 24);
            if ( v2 != 256 )
              v8 = v2 * v8 / 256;
            if ( v8 )
            {
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v12 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u), v9),
                      _m_pandn(v9, v10));
              if ( v8 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v8);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
            }
            --v33;
          }
          while ( v33 );
          v1 = v34;
          v3 = v37;
        }
        v1 += v31;
        v17 = v35 == 1;
        v29 += v38;
        v34 = v1;
        --v35;
      }
      while ( !v17 );
    }
  }
  else
  {
    v18 = i_args->cDstArgs.pDstBuf;
    v30 = g_SourceColor.u;
    BYTE3(v30) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v39 = i_args->nWidth;
      v32 = i_args->cDstArgs.iStride;
      v36 = i_args->nHeight;
      do
      {
        v19 = v39;
        while ( v19 )
        {
          --v19;
          v20 = (v30 >> 24 != 0) + (v30 >> 24);
          if ( v20 )
          {
            v21 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v22 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v18[4 * v19]), 0i64);
            v23 = _m_punpcklbw(_mm_cvtsi32_si64(v30), 0i64);
            v24 = _m_por(
                    _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v23, _m_pcmpgtw(v23, 0i64)), v22), 8u), v21),
                    _m_pandn(v21, v22));
            if ( v20 == 256 )
            {
              v25 = v24;
            }
            else
            {
              v26 = _mm_cvtsi32_si64(v20);
              v27 = _m_punpcklwd(v26, v26);
              v28 = _m_punpcklwd(v27, v27);
              v25 = _m_psubw(v22, _m_psubw(_m_psrlw(_m_pmullw(v22, v28), 8u), _m_psrlw(_m_pmullw(v24, v28), 8u)));
            }
            *(_DWORD *)&v18[4 * v19] = _mm_cvtsi64_si32(_m_packuswb(v25, 0i64));
          }
        }
        v18 -= v32;
        --v36;
      }
      while ( v36 );
    }
  }
  _m_femms();
}

//----- (00669890) --------------------------------------------------------  // acclient.c:640354
void __cdecl ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  int v7; // eax@6
  unsigned int v8; // ST10_4@9
  __m64 v9; // mm3@9
  __m64 v10; // mm0@9
  __m64 v11; // mm1@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  unsigned int v17; // ST10_4@12
  bool v18; // zf@14
  char *v19; // ebx@16
  unsigned int v20; // edi@17
  int v21; // eax@19
  unsigned int v22; // ecx@20
  unsigned int v23; // ST10_4@21
  __m64 v24; // mm3@21
  __m64 v25; // mm0@21
  __m64 v26; // mm1@21
  __m64 v27; // mm1@21
  __m64 v28; // mm0@22
  __m64 v29; // mm3@23
  __m64 v30; // mm4@23
  __m64 v31; // mm3@23
  unsigned int v32; // ST10_4@24
  char *v33; // [sp+14h] [bp-1Ch]@2
  unsigned int v34; // [sp+14h] [bp-1Ch]@16
  unsigned int v35; // [sp+18h] [bp-18h]@3
  unsigned int v36; // [sp+18h] [bp-18h]@17
  char *v37; // [sp+1Ch] [bp-14h]@2
  char *v38; // [sp+1Ch] [bp-14h]@16
  unsigned int v39; // [sp+20h] [bp-10h]@3
  unsigned int v40; // [sp+20h] [bp-10h]@19
  unsigned int v41; // [sp+24h] [bp-Ch]@3
  unsigned int v42; // [sp+24h] [bp-Ch]@17
  unsigned int v43; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v33 = i_args->cSrcArgs.pDstBuf;
    v37 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v41 = i_args->nWidth;
      v43 = i_args->cSrcArgs.iStride;
      v35 = i_args->cDstArgs.iStride;
      v39 = i_args->nHeight;
      do
      {
        v3 = v41;
        if ( v41 )
        {
          v4 = (int)(&v1[2 * v41 + 2] + v41);
          do
          {
            v5 = *(_DWORD *)&v33[4 * v3-- - 4];
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v4 -= 3;
            v7 = (v6 >> 24 != 0) + (v6 >> 24);
            if ( v2 != 256 )
              v7 = v2 * v7 / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v4 - 2);
              BYTE1(v8) = *(_BYTE *)(v4 - 1);
              BYTE2(v8) = *(_BYTE *)v4;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v8) = -1;
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
              v12 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u), v9),
                      _m_pandn(v9, v10));
              if ( v7 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v7);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              v17 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
              *(_BYTE *)(v4 - 2) = v17;
              *(_BYTE *)(v4 - 1) = BYTE1(v17);
              *(_BYTE *)v4 = v17 >> 16;
            }
          }
          while ( v3 );
        }
        v1 = &v37[v35];
        v18 = v39 == 1;
        v33 += v43;
        v37 += v35;
        --v39;
      }
      while ( !v18 );
    }
  }
  else
  {
    v19 = i_args->cDstArgs.pDstBuf;
    v34 = g_SourceColor.u;
    BYTE3(v34) = i_args->i8AlphaModifier;
    v38 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v36 = i_args->cDstArgs.iStride;
      v42 = i_args->nHeight;
      do
      {
        if ( v20 )
        {
          v21 = (int)(&v19[2 * v20 + 2] + v20);
          v40 = v20;
          do
          {
            v21 -= 3;
            v22 = (v34 >> 24 != 0) + (v34 >> 24);
            if ( v22 )
            {
              LOBYTE(v23) = *(_BYTE *)(v21 - 2);
              BYTE1(v23) = *(_BYTE *)(v21 - 1);
              BYTE2(v23) = *(_BYTE *)v21;
              v24 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v23) = -1;
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64);
              v26 = _m_punpcklbw(_mm_cvtsi32_si64(v34), 0i64);
              v27 = _m_por(
                      _m_pand(_m_psrlw(_m_pmullw(_m_psubw(v26, _m_pcmpgtw(v26, 0i64)), v25), 8u), v24),
                      _m_pandn(v24, v25));
              if ( v22 == 256 )
              {
                v28 = v27;
              }
              else
              {
                v29 = _mm_cvtsi32_si64(v22);
                v30 = _m_punpcklwd(v29, v29);
                v31 = _m_punpcklwd(v30, v30);
                v28 = _m_psubw(v25, _m_psubw(_m_psrlw(_m_pmullw(v25, v31), 8u), _m_psrlw(_m_pmullw(v27, v31), 8u)));
              }
              v32 = _mm_cvtsi64_si32(_m_packuswb(v28, 0i64));
              *(_BYTE *)(v21 - 2) = v32;
              *(_BYTE *)(v21 - 1) = BYTE1(v32);
              *(_BYTE *)v21 = v32 >> 16;
            }
            --v40;
          }
          while ( v40 );
        }
        v19 = &v38[-v36];
        v18 = v42 == 1;
        v38 -= v36;
        --v42;
      }
      while ( !v18 );
    }
  }
  _m_femms();
}

//----- (00669B70) --------------------------------------------------------  // acclient.c:640531
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edi@2
  int v2; // esi@2
  unsigned int v3; // ecx@4
  int v4; // ebx@5
  int v5; // eax@6
  __m64 v6; // mm3@9
  __m64 v7; // mm0@9
  __m64 v8; // mm1@9
  unsigned int v9; // eax@9
  __m64 v10; // mm1@9
  __m64 v11; // mm0@10
  __m64 v12; // mm3@11
  __m64 v13; // mm4@11
  __m64 v14; // mm3@11
  char *v15; // edx@16
  unsigned int v16; // ecx@18
  unsigned int v17; // esi@19
  __m64 v18; // mm3@21
  __m64 v19; // mm0@21
  __m64 v20; // mm1@21
  __m64 v21; // mm1@21
  __m64 v22; // mm0@22
  __m64 v23; // mm3@23
  __m64 v24; // mm4@23
  __m64 v25; // mm3@23
  unsigned int v26; // [sp+10h] [bp-10h]@3
  unsigned int v27; // [sp+10h] [bp-10h]@17
  unsigned int v28; // [sp+14h] [bp-Ch]@3
  unsigned int v29; // [sp+14h] [bp-Ch]@16
  unsigned int v30; // [sp+18h] [bp-8h]@3
  unsigned int v31; // [sp+18h] [bp-8h]@17
  unsigned int v32; // [sp+1Ch] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v26 = i_args->nWidth;
      v30 = i_args->cDstArgs.iStride;
      v28 = i_args->nHeight;
      do
      {
        v3 = v26;
        if ( v26 )
        {
          v4 = BYTE3(g_SourceColor.u);
          do
          {
            --v3;
            v5 = v4;
            if ( v2 != 256 )
              v5 = v2 * v4 / 256;
            if ( v5 )
            {
              v6 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v3]), 0i64);
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64);
              v9 = v5 + 1;
              v10 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v7, v8), _m_psrlw(_m_pmullw(_m_psubw(v8, _m_pcmpgtw(v8, 0i64)), v7), 8u)),
                        v6),
                      _m_pandn(v6, v7));
              if ( v9 == 256 )
              {
                v11 = v10;
              }
              else
              {
                v12 = _mm_cvtsi32_si64(v9);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v11 = _m_psubw(v7, _m_psubw(_m_psrlw(_m_pmullw(v7, v14), 8u), _m_psrlw(_m_pmullw(v10, v14), 8u)));
              }
              *(_DWORD *)&v1[4 * v3] = _mm_cvtsi64_si32(_m_packuswb(v11, 0i64));
            }
          }
          while ( v3 );
        }
        v1 += v30;
        --v28;
      }
      while ( v28 );
    }
  }
  else
  {
    v15 = i_args->cDstArgs.pDstBuf;
    v29 = g_SourceColor.u;
    BYTE3(v29) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v27 = i_args->nWidth;
      v31 = i_args->cDstArgs.iStride;
      v32 = i_args->nHeight;
      do
      {
        v16 = v27;
        if ( v27 )
        {
          v17 = v29 >> 24;
          do
          {
            --v16;
            if ( v17 )
            {
              v18 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v19 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v15[4 * v16]), 0i64);
              v20 = _m_punpcklbw(_mm_cvtsi32_si64(v29), 0i64);
              v21 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v19, v20), _m_psrlw(_m_pmullw(_m_psubw(v20, _m_pcmpgtw(v20, 0i64)), v19), 8u)),
                        v18),
                      _m_pandn(v18, v19));
              if ( v17 == 255 )
              {
                v22 = v21;
              }
              else
              {
                v23 = _mm_cvtsi32_si64(v17 + 1);
                v24 = _m_punpcklwd(v23, v23);
                v25 = _m_punpcklwd(v24, v24);
                v22 = _m_psubw(v19, _m_psubw(_m_psrlw(_m_pmullw(v19, v25), 8u), _m_psrlw(_m_pmullw(v21, v25), 8u)));
              }
              *(_DWORD *)&v15[4 * v16] = _mm_cvtsi64_si32(_m_packuswb(v22, 0i64));
            }
          }
          while ( v16 );
        }
        v15 -= v31;
        --v32;
      }
      while ( v32 );
    }
  }
  _m_femms();
}

//----- (00669DB0) --------------------------------------------------------  // acclient.c:640675
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // edx@2
  int v2; // esi@2
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // ST10_4@9
  __m64 v8; // mm3@9
  __m64 v9; // mm0@9
  __m64 v10; // mm1@9
  unsigned int v11; // eax@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  unsigned int v17; // ST10_4@12
  bool v18; // zf@14
  char *v19; // ebx@16
  unsigned int v20; // edi@17
  unsigned int v21; // esi@19
  int v22; // eax@19
  unsigned int v23; // ST10_4@21
  __m64 v24; // mm3@21
  __m64 v25; // mm0@21
  __m64 v26; // mm1@21
  __m64 v27; // mm1@21
  __m64 v28; // mm0@22
  __m64 v29; // mm3@23
  __m64 v30; // mm4@23
  __m64 v31; // mm3@23
  unsigned int v32; // ST10_4@24
  unsigned int v33; // [sp+14h] [bp-14h]@5
  unsigned int v34; // [sp+14h] [bp-14h]@16
  unsigned int v35; // [sp+18h] [bp-10h]@3
  unsigned int v36; // [sp+18h] [bp-10h]@17
  char *v37; // [sp+1Ch] [bp-Ch]@2
  char *v38; // [sp+1Ch] [bp-Ch]@16
  unsigned int v39; // [sp+20h] [bp-8h]@3
  unsigned int v40; // [sp+20h] [bp-8h]@19
  unsigned int v41; // [sp+24h] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v37 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v35 = i_args->cDstArgs.iStride;
      v39 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = BYTE3(g_SourceColor.u);
          v5 = (int)(&v1[2 * v3 + 2] + v3);
          v33 = v3;
          do
          {
            v5 -= 3;
            v6 = v4;
            if ( v2 != 256 )
              v6 = v2 * v4 / 256;
            if ( v6 )
            {
              LOBYTE(v7) = *(_BYTE *)(v5 - 2);
              BYTE1(v7) = *(_BYTE *)(v5 - 1);
              BYTE2(v7) = *(_BYTE *)v5;
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v7) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64);
              v11 = v6 + 1;
              v12 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v9, v10), _m_psrlw(_m_pmullw(_m_psubw(v10, _m_pcmpgtw(v10, 0i64)), v9), 8u)),
                        v8),
                      _m_pandn(v8, v9));
              if ( v11 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v11);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              v17 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
              *(_BYTE *)(v5 - 2) = v17;
              *(_BYTE *)(v5 - 1) = BYTE1(v17);
              *(_BYTE *)v5 = v17 >> 16;
            }
            --v33;
          }
          while ( v33 );
        }
        v1 = &v37[v35];
        v18 = v39 == 1;
        v37 += v35;
        --v39;
      }
      while ( !v18 );
    }
  }
  else
  {
    v19 = i_args->cDstArgs.pDstBuf;
    v34 = g_SourceColor.u;
    v38 = i_args->cDstArgs.pDstBuf;
    BYTE3(v34) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v36 = i_args->cDstArgs.iStride;
      v41 = i_args->nHeight;
      do
      {
        if ( v20 )
        {
          v21 = v34 >> 24;
          v22 = (int)(&v19[2 * v20 + 2] + v20);
          v40 = v20;
          do
          {
            v22 -= 3;
            if ( v21 )
            {
              LOBYTE(v23) = *(_BYTE *)(v22 - 2);
              BYTE1(v23) = *(_BYTE *)(v22 - 1);
              BYTE2(v23) = *(_BYTE *)v22;
              v24 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v23) = -1;
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64);
              v26 = _m_punpcklbw(_mm_cvtsi32_si64(v34), 0i64);
              v27 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v25, v26), _m_psrlw(_m_pmullw(_m_psubw(v26, _m_pcmpgtw(v26, 0i64)), v25), 8u)),
                        v24),
                      _m_pandn(v24, v25));
              if ( v21 == 255 )
              {
                v28 = v27;
              }
              else
              {
                v29 = _mm_cvtsi32_si64(v21 + 1);
                v30 = _m_punpcklwd(v29, v29);
                v31 = _m_punpcklwd(v30, v30);
                v28 = _m_psubw(v25, _m_psubw(_m_psrlw(_m_pmullw(v25, v31), 8u), _m_psrlw(_m_pmullw(v27, v31), 8u)));
              }
              v32 = _mm_cvtsi64_si32(_m_packuswb(v28, 0i64));
              *(_BYTE *)(v22 - 2) = v32;
              *(_BYTE *)(v22 - 1) = BYTE1(v32);
              *(_BYTE *)v22 = v32 >> 16;
            }
            --v40;
          }
          while ( v40 );
        }
        v19 = &v38[-v36];
        v18 = v41 == 1;
        v38 -= v36;
        --v41;
      }
      while ( !v18 );
    }
  }
  _m_femms();
}

//----- (0066A070) --------------------------------------------------------  // acclient.c:640852
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // ebx@2
  int v2; // edi@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // ecx@5
  unsigned int v6; // eax@5
  __m64 v7; // mm3@8
  __m64 v8; // mm0@8
  __m64 v9; // mm1@8
  unsigned int v10; // eax@8
  __m64 v11; // mm1@8
  __m64 v12; // mm0@9
  __m64 v13; // mm3@10
  __m64 v14; // mm4@10
  __m64 v15; // mm3@10
  bool v16; // zf@13
  char *v17; // edx@15
  unsigned int v18; // ecx@17
  unsigned int v19; // esi@18
  __m64 v20; // mm3@20
  __m64 v21; // mm0@20
  __m64 v22; // mm1@20
  __m64 v23; // mm1@20
  __m64 v24; // mm0@21
  __m64 v25; // mm3@22
  __m64 v26; // mm4@22
  __m64 v27; // mm3@22
  char *v28; // [sp+10h] [bp-18h]@2
  unsigned int v29; // [sp+10h] [bp-18h]@15
  unsigned int v30; // [sp+14h] [bp-14h]@3
  unsigned int v31; // [sp+14h] [bp-14h]@16
  unsigned int v32; // [sp+18h] [bp-10h]@3
  unsigned int v33; // [sp+18h] [bp-10h]@16
  unsigned int v34; // [sp+1Ch] [bp-Ch]@3
  unsigned int v35; // [sp+1Ch] [bp-Ch]@16
  unsigned int v36; // [sp+24h] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v28 = i_args->cSrcArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v30 = i_args->nWidth;
      v36 = i_args->cSrcArgs.iStride;
      v32 = i_args->cDstArgs.iStride;
      v34 = i_args->nHeight;
      do
      {
        v3 = v30;
        while ( v3 )
        {
          v4 = (unsigned __int8)v28[v3-- - 1];
          v5 = g_SourceColor.u | (v4 << 24);
          v6 = v5 >> 24;
          if ( v2 != 256 )
            v6 = (signed int)(v2 * v6) / 256;
          if ( v6 )
          {
            v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v8 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v3]), 0i64);
            v9 = _m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64);
            v10 = v6 + 1;
            v11 = _m_por(
                    _m_pand(
                      _m_psubw(_m_paddw(v8, v9), _m_psrlw(_m_pmullw(_m_psubw(v9, _m_pcmpgtw(v9, 0i64)), v8), 8u)),
                      v7),
                    _m_pandn(v7, v8));
            if ( v10 == 256 )
            {
              v12 = v11;
            }
            else
            {
              v13 = _mm_cvtsi32_si64(v10);
              v14 = _m_punpcklwd(v13, v13);
              v15 = _m_punpcklwd(v14, v14);
              v12 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v15), 8u), _m_psrlw(_m_pmullw(v11, v15), 8u)));
            }
            *(_DWORD *)&v1[4 * v3] = _mm_cvtsi64_si32(_m_packuswb(v12, 0i64));
          }
        }
        v1 += v32;
        v16 = v34 == 1;
        v28 += v36;
        --v34;
      }
      while ( !v16 );
    }
  }
  else
  {
    v17 = i_args->cDstArgs.pDstBuf;
    v29 = g_SourceColor.u;
    BYTE3(v29) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v31 = i_args->nWidth;
      v33 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        v18 = v31;
        if ( v31 )
        {
          v19 = v29 >> 24;
          do
          {
            --v18;
            if ( v19 )
            {
              v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v21 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v17[4 * v18]), 0i64);
              v22 = _m_punpcklbw(_mm_cvtsi32_si64(v29), 0i64);
              v23 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v21, v22), _m_psrlw(_m_pmullw(_m_psubw(v22, _m_pcmpgtw(v22, 0i64)), v21), 8u)),
                        v20),
                      _m_pandn(v20, v21));
              if ( v19 == 255 )
              {
                v24 = v23;
              }
              else
              {
                v25 = _mm_cvtsi32_si64(v19 + 1);
                v26 = _m_punpcklwd(v25, v25);
                v27 = _m_punpcklwd(v26, v26);
                v24 = _m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v27), 8u), _m_psrlw(_m_pmullw(v23, v27), 8u)));
              }
              *(_DWORD *)&v17[4 * v18] = _mm_cvtsi64_si32(_m_packuswb(v24, 0i64));
            }
          }
          while ( v18 );
        }
        v17 -= v33;
        --v35;
      }
      while ( v35 );
    }
  }
  _m_femms();
}

//----- (0066A2D0) --------------------------------------------------------  // acclient.c:641000
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  unsigned int v7; // eax@6
  unsigned int v8; // ST10_4@9
  __m64 v9; // mm3@9
  __m64 v10; // mm0@9
  __m64 v11; // mm1@9
  unsigned int v12; // eax@9
  __m64 v13; // mm1@9
  __m64 v14; // mm0@10
  __m64 v15; // mm3@11
  __m64 v16; // mm4@11
  __m64 v17; // mm3@11
  unsigned int v18; // ST10_4@12
  bool v19; // zf@14
  char *v20; // ebx@16
  unsigned int v21; // edi@17
  unsigned int v22; // esi@19
  int v23; // eax@19
  unsigned int v24; // ST10_4@21
  __m64 v25; // mm3@21
  __m64 v26; // mm0@21
  __m64 v27; // mm1@21
  __m64 v28; // mm1@21
  __m64 v29; // mm0@22
  __m64 v30; // mm3@23
  __m64 v31; // mm4@23
  __m64 v32; // mm3@23
  unsigned int v33; // ST10_4@24
  char *v34; // [sp+14h] [bp-1Ch]@2
  unsigned int v35; // [sp+14h] [bp-1Ch]@16
  unsigned int v36; // [sp+18h] [bp-18h]@3
  unsigned int v37; // [sp+18h] [bp-18h]@17
  char *v38; // [sp+1Ch] [bp-14h]@2
  char *v39; // [sp+1Ch] [bp-14h]@16
  unsigned int v40; // [sp+20h] [bp-10h]@3
  unsigned int v41; // [sp+20h] [bp-10h]@19
  unsigned int v42; // [sp+24h] [bp-Ch]@3
  unsigned int v43; // [sp+24h] [bp-Ch]@17
  unsigned int v44; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v34 = i_args->cSrcArgs.pDstBuf;
    v38 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v42 = i_args->nWidth;
      v44 = i_args->cSrcArgs.iStride;
      v36 = i_args->cDstArgs.iStride;
      v40 = i_args->nHeight;
      do
      {
        v3 = v42;
        if ( v42 )
        {
          v4 = (int)(&v1[2 * v42 + 2] + v42);
          do
          {
            v5 = (unsigned __int8)v34[v3-- - 1];
            v6 = g_SourceColor.u | (v5 << 24);
            v4 -= 3;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v4 - 2);
              BYTE1(v8) = *(_BYTE *)(v4 - 1);
              BYTE2(v8) = *(_BYTE *)v4;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v8) = -1;
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
              v12 = v7 + 1;
              v13 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v10, v11), _m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u)),
                        v9),
                      _m_pandn(v9, v10));
              if ( v12 == 256 )
              {
                v14 = v13;
              }
              else
              {
                v15 = _mm_cvtsi32_si64(v12);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _m_punpcklwd(v16, v16);
                v14 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v17), 8u), _m_psrlw(_m_pmullw(v13, v17), 8u)));
              }
              v18 = _mm_cvtsi64_si32(_m_packuswb(v14, 0i64));
              *(_BYTE *)(v4 - 2) = v18;
              *(_BYTE *)(v4 - 1) = BYTE1(v18);
              *(_BYTE *)v4 = v18 >> 16;
            }
          }
          while ( v3 );
        }
        v1 = &v38[v36];
        v19 = v40 == 1;
        v34 += v44;
        v38 += v36;
        --v40;
      }
      while ( !v19 );
    }
  }
  else
  {
    v20 = i_args->cDstArgs.pDstBuf;
    v35 = g_SourceColor.u;
    BYTE3(v35) = i_args->i8AlphaModifier;
    v39 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v37 = i_args->cDstArgs.iStride;
      v43 = i_args->nHeight;
      do
      {
        if ( v21 )
        {
          v22 = v35 >> 24;
          v23 = (int)(&v20[2 * v21 + 2] + v21);
          v41 = v21;
          do
          {
            v23 -= 3;
            if ( v22 )
            {
              LOBYTE(v24) = *(_BYTE *)(v23 - 2);
              BYTE1(v24) = *(_BYTE *)(v23 - 1);
              BYTE2(v24) = *(_BYTE *)v23;
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v24) = -1;
              v26 = _m_punpcklbw(_mm_cvtsi32_si64(v24), 0i64);
              v27 = _m_punpcklbw(_mm_cvtsi32_si64(v35), 0i64);
              v28 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v26, v27), _m_psrlw(_m_pmullw(_m_psubw(v27, _m_pcmpgtw(v27, 0i64)), v26), 8u)),
                        v25),
                      _m_pandn(v25, v26));
              if ( v22 == 255 )
              {
                v29 = v28;
              }
              else
              {
                v30 = _mm_cvtsi32_si64(v22 + 1);
                v31 = _m_punpcklwd(v30, v30);
                v32 = _m_punpcklwd(v31, v31);
                v29 = _m_psubw(v26, _m_psubw(_m_psrlw(_m_pmullw(v26, v32), 8u), _m_psrlw(_m_pmullw(v28, v32), 8u)));
              }
              v33 = _mm_cvtsi64_si32(_m_packuswb(v29, 0i64));
              *(_BYTE *)(v23 - 2) = v33;
              *(_BYTE *)(v23 - 1) = BYTE1(v33);
              *(_BYTE *)v23 = v33 >> 16;
            }
            --v41;
          }
          while ( v41 );
        }
        v20 = &v39[-v37];
        v19 = v43 == 1;
        v39 -= v37;
        --v43;
      }
      while ( !v19 );
    }
  }
  _m_femms();
}

//----- (0066A5D0) --------------------------------------------------------  // acclient.c:641183
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  unsigned int *v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  unsigned int v7; // eax@6
  __m64 v8; // mm3@9
  __m64 v9; // mm0@9
  __m64 v10; // mm1@9
  unsigned int v11; // eax@9
  __m64 v12; // mm1@9
  __m64 v13; // mm0@10
  __m64 v14; // mm3@11
  __m64 v15; // mm4@11
  __m64 v16; // mm3@11
  bool v17; // zf@15
  unsigned int v18; // ecx@19
  unsigned int v19; // esi@20
  __m64 v20; // mm3@22
  __m64 v21; // mm0@22
  __m64 v22; // mm1@22
  __m64 v23; // mm1@22
  __m64 v24; // mm0@23
  __m64 v25; // mm3@24
  __m64 v26; // mm4@24
  __m64 v27; // mm3@24
  char *v28; // [sp+10h] [bp-20h]@2
  unsigned int v29; // [sp+10h] [bp-20h]@17
  unsigned int v30; // [sp+14h] [bp-1Ch]@3
  unsigned int v31; // [sp+14h] [bp-1Ch]@18
  unsigned int v32; // [sp+18h] [bp-18h]@5
  unsigned int v33; // [sp+1Ch] [bp-14h]@3
  char *v34; // [sp+20h] [bp-10h]@2
  unsigned int v35; // [sp+24h] [bp-Ch]@3
  unsigned int v36; // [sp+24h] [bp-Ch]@18
  unsigned int v37; // [sp+2Ch] [bp-4h]@3
  unsigned int v38; // [sp+2Ch] [bp-4h]@18

  v1 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v28 = i_args->cSrcArgs.pDstBuf;
    v34 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v33 = i_args->nWidth;
      v37 = i_args->cSrcArgs.iStride;
      v30 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (unsigned int *)&v1[4 * v3];
          v32 = v33;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v28 - v1 - 4);
            --v4;
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
              v11 = v7 + 1;
              v12 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v9, v10), _m_psrlw(_m_pmullw(_m_psubw(v10, _m_pcmpgtw(v10, 0i64)), v9), 8u)),
                        v8),
                      _m_pandn(v8, v9));
              if ( v11 == 256 )
              {
                v13 = v12;
              }
              else
              {
                v14 = _mm_cvtsi32_si64(v11);
                v15 = _m_punpcklwd(v14, v14);
                v16 = _m_punpcklwd(v15, v15);
                v13 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v16), 8u), _m_psrlw(_m_pmullw(v12, v16), 8u)));
              }
              *v4 = _mm_cvtsi64_si32(_m_packuswb(v13, 0i64));
            }
            --v32;
          }
          while ( v32 );
          v1 = v34;
          v3 = v33;
        }
        v1 += v30;
        v17 = v35 == 1;
        v28 += v37;
        v34 = v1;
        --v35;
      }
      while ( !v17 );
    }
  }
  else
  {
    v29 = g_SourceColor.u;
    BYTE3(v29) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v38 = i_args->nWidth;
      v31 = i_args->cDstArgs.iStride;
      v36 = i_args->nHeight;
      do
      {
        v18 = v38;
        if ( v38 )
        {
          v19 = v29 >> 24;
          do
          {
            --v18;
            if ( v19 )
            {
              v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v21 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v18]), 0i64);
              v22 = _m_punpcklbw(_mm_cvtsi32_si64(v29), 0i64);
              v23 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v21, v22), _m_psrlw(_m_pmullw(_m_psubw(v22, _m_pcmpgtw(v22, 0i64)), v21), 8u)),
                        v20),
                      _m_pandn(v20, v21));
              if ( v19 == 255 )
              {
                v24 = v23;
              }
              else
              {
                v25 = _mm_cvtsi32_si64(v19 + 1);
                v26 = _m_punpcklwd(v25, v25);
                v27 = _m_punpcklwd(v26, v26);
                v24 = _m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v27), 8u), _m_psrlw(_m_pmullw(v23, v27), 8u)));
              }
              *(_DWORD *)&v1[4 * v18] = _mm_cvtsi64_si32(_m_packuswb(v24, 0i64));
            }
          }
          while ( v18 );
        }
        v1 -= v31;
        --v36;
      }
      while ( v36 );
    }
  }
  _m_femms();
}

//----- (0066A840) --------------------------------------------------------  // acclient.c:641344
void __cdecl ColoringLoopNoScale__BlitOp_Screen_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  unsigned int v7; // eax@6
  unsigned int v8; // ST10_4@9
  __m64 v9; // mm3@9
  __m64 v10; // mm0@9
  __m64 v11; // mm1@9
  unsigned int v12; // eax@9
  __m64 v13; // mm1@9
  __m64 v14; // mm0@10
  __m64 v15; // mm3@11
  __m64 v16; // mm4@11
  __m64 v17; // mm3@11
  unsigned int v18; // ST10_4@12
  bool v19; // zf@14
  char *v20; // ebx@16
  unsigned int v21; // edi@17
  unsigned int v22; // esi@19
  int v23; // eax@19
  unsigned int v24; // ST10_4@21
  __m64 v25; // mm3@21
  __m64 v26; // mm0@21
  __m64 v27; // mm1@21
  __m64 v28; // mm1@21
  __m64 v29; // mm0@22
  __m64 v30; // mm3@23
  __m64 v31; // mm4@23
  __m64 v32; // mm3@23
  unsigned int v33; // ST10_4@24
  char *v34; // [sp+14h] [bp-1Ch]@2
  unsigned int v35; // [sp+14h] [bp-1Ch]@16
  unsigned int v36; // [sp+18h] [bp-18h]@3
  unsigned int v37; // [sp+18h] [bp-18h]@17
  char *v38; // [sp+1Ch] [bp-14h]@2
  char *v39; // [sp+1Ch] [bp-14h]@16
  unsigned int v40; // [sp+20h] [bp-10h]@3
  unsigned int v41; // [sp+20h] [bp-10h]@19
  unsigned int v42; // [sp+24h] [bp-Ch]@3
  unsigned int v43; // [sp+24h] [bp-Ch]@17
  unsigned int v44; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v34 = i_args->cSrcArgs.pDstBuf;
    v38 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v42 = i_args->nWidth;
      v44 = i_args->cSrcArgs.iStride;
      v36 = i_args->cDstArgs.iStride;
      v40 = i_args->nHeight;
      do
      {
        v3 = v42;
        if ( v42 )
        {
          v4 = (int)(&v1[2 * v42 + 2] + v42);
          do
          {
            v5 = *(_DWORD *)&v34[4 * v3-- - 4];
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v4 -= 3;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v4 - 2);
              BYTE1(v8) = *(_BYTE *)(v4 - 1);
              BYTE2(v8) = *(_BYTE *)v4;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v8) = -1;
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64);
              v12 = v7 + 1;
              v13 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v10, v11), _m_psrlw(_m_pmullw(_m_psubw(v11, _m_pcmpgtw(v11, 0i64)), v10), 8u)),
                        v9),
                      _m_pandn(v9, v10));
              if ( v12 == 256 )
              {
                v14 = v13;
              }
              else
              {
                v15 = _mm_cvtsi32_si64(v12);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _m_punpcklwd(v16, v16);
                v14 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v17), 8u), _m_psrlw(_m_pmullw(v13, v17), 8u)));
              }
              v18 = _mm_cvtsi64_si32(_m_packuswb(v14, 0i64));
              *(_BYTE *)(v4 - 2) = v18;
              *(_BYTE *)(v4 - 1) = BYTE1(v18);
              *(_BYTE *)v4 = v18 >> 16;
            }
          }
          while ( v3 );
        }
        v1 = &v38[v36];
        v19 = v40 == 1;
        v34 += v44;
        v38 += v36;
        --v40;
      }
      while ( !v19 );
    }
  }
  else
  {
    v20 = i_args->cDstArgs.pDstBuf;
    v35 = g_SourceColor.u;
    BYTE3(v35) = i_args->i8AlphaModifier;
    v39 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v37 = i_args->cDstArgs.iStride;
      v43 = i_args->nHeight;
      do
      {
        if ( v21 )
        {
          v22 = v35 >> 24;
          v23 = (int)(&v20[2 * v21 + 2] + v21);
          v41 = v21;
          do
          {
            v23 -= 3;
            if ( v22 )
            {
              LOBYTE(v24) = *(_BYTE *)(v23 - 2);
              BYTE1(v24) = *(_BYTE *)(v23 - 1);
              BYTE2(v24) = *(_BYTE *)v23;
              v25 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v24) = -1;
              v26 = _m_punpcklbw(_mm_cvtsi32_si64(v24), 0i64);
              v27 = _m_punpcklbw(_mm_cvtsi32_si64(v35), 0i64);
              v28 = _m_por(
                      _m_pand(
                        _m_psubw(_m_paddw(v26, v27), _m_psrlw(_m_pmullw(_m_psubw(v27, _m_pcmpgtw(v27, 0i64)), v26), 8u)),
                        v25),
                      _m_pandn(v25, v26));
              if ( v22 == 255 )
              {
                v29 = v28;
              }
              else
              {
                v30 = _mm_cvtsi32_si64(v22 + 1);
                v31 = _m_punpcklwd(v30, v30);
                v32 = _m_punpcklwd(v31, v31);
                v29 = _m_psubw(v26, _m_psubw(_m_psrlw(_m_pmullw(v26, v32), 8u), _m_psrlw(_m_pmullw(v28, v32), 8u)));
              }
              v33 = _mm_cvtsi64_si32(_m_packuswb(v29, 0i64));
              *(_BYTE *)(v23 - 2) = v33;
              *(_BYTE *)(v23 - 1) = BYTE1(v33);
              *(_BYTE *)v23 = v33 >> 16;
            }
            --v41;
          }
          while ( v41 );
        }
        v20 = &v39[-v37];
        v19 = v43 == 1;
        v39 -= v37;
        --v43;
      }
      while ( !v19 );
    }
  }
  _m_femms();
}

//----- (0066AB30) --------------------------------------------------------  // acclient.c:641527
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edi@2
  int v2; // esi@2
  unsigned int v3; // ecx@4
  int v4; // ebx@5
  int v5; // eax@6
  __m64 v6; // mm2@9
  __m64 v7; // mm1@9
  __m64 v8; // mm0@9
  __m64 v9; // mm3@9
  __m64 v10; // mm4@9
  __m64 v11; // mm0@9
  __m64 v12; // mm4@9
  __m64 v13; // mm3@9
  __m64 v14; // mm4@9
  unsigned int v15; // eax@9
  __m64 v16; // mm0@9
  __m64 v17; // mm2@10
  __m64 v18; // mm3@10
  __m64 v19; // mm2@10
  char *v20; // edx@15
  unsigned int v21; // edi@16
  unsigned int v22; // ecx@17
  __m64 v23; // mm2@19
  __m64 v24; // mm1@19
  __m64 v25; // mm0@19
  __m64 v26; // mm3@19
  __m64 v27; // mm4@19
  __m64 v28; // mm0@19
  __m64 v29; // mm4@19
  __m64 v30; // mm3@19
  __m64 v31; // mm4@19
  __m64 v32; // mm0@19
  __m64 v33; // mm2@20
  __m64 v34; // mm3@20
  __m64 v35; // mm2@20
  unsigned int v36; // [sp+Ch] [bp-Ch]@3
  unsigned int v37; // [sp+Ch] [bp-Ch]@16
  unsigned int v38; // [sp+10h] [bp-8h]@3
  unsigned int v39; // [sp+10h] [bp-8h]@16
  unsigned int v40; // [sp+14h] [bp-4h]@3
  char v41; // [sp+17h] [bp-1h]@15

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v36 = i_args->nWidth;
      v38 = i_args->cDstArgs.iStride;
      v40 = i_args->nHeight;
      do
      {
        v3 = v36;
        if ( v36 )
        {
          v4 = BYTE3(g_SourceColor.u);
          do
          {
            --v3;
            v5 = v4;
            if ( v2 != 256 )
              v5 = v2 * v4 / 256;
            if ( v5 )
            {
              v6 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v7 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v3]), 0i64);
              v8 = _m_pand(v7, v6);
              v9 = _m_psllq(v8, 0x10u);
              v10 = _m_pcmpgtw(v8, v9);
              v11 = _m_por(_m_pand(v8, v10), _m_pandn(v10, v9));
              v12 = _m_por(_m_psllq(v11, 0x20u), _m_psrlq(v11, 0x20u));
              v13 = v12;
              v14 = _m_pcmpgtw(v11, v12);
              v15 = v5 + 1;
              v16 = _m_por(_m_pand(_m_por(_m_pand(v11, v14), _m_pandn(v14, v13)), v6), _m_pandn(v6, v7));
              if ( v15 != 256 )
              {
                v17 = _mm_cvtsi32_si64(v15);
                v18 = _m_punpcklwd(v17, v17);
                v19 = _m_punpcklwd(v18, v18);
                v16 = _m_psubw(v7, _m_psubw(_m_psrlw(_m_pmullw(v7, v19), 8u), _m_psrlw(_m_pmullw(v16, v19), 8u)));
              }
              *(_DWORD *)&v1[4 * v3] = _mm_cvtsi64_si32(_m_packuswb(v16, 0i64));
            }
          }
          while ( v3 );
        }
        v1 += v38;
        --v40;
      }
      while ( v40 );
    }
  }
  else
  {
    v20 = i_args->cDstArgs.pDstBuf;
    v41 = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v37 = i_args->nWidth;
      v39 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        v22 = v37;
        while ( v22 )
        {
          --v22;
          if ( v41 )
          {
            v23 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v24 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v20[4 * v22]), 0i64);
            v25 = _m_pand(v24, v23);
            v26 = _m_psllq(v25, 0x10u);
            v27 = _m_pcmpgtw(v25, v26);
            v28 = _m_por(_m_pand(v25, v27), _m_pandn(v27, v26));
            v29 = _m_por(_m_psllq(v28, 0x20u), _m_psrlq(v28, 0x20u));
            v30 = v29;
            v31 = _m_pcmpgtw(v28, v29);
            v32 = _m_por(_m_pand(_m_por(_m_pand(v28, v31), _m_pandn(v31, v30)), v23), _m_pandn(v23, v24));
            if ( (unsigned __int8)v41 != 255 )
            {
              v33 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v41 + 1);
              v34 = _m_punpcklwd(v33, v33);
              v35 = _m_punpcklwd(v34, v34);
              v32 = _m_psubw(v24, _m_psubw(_m_psrlw(_m_pmullw(v24, v35), 8u), _m_psrlw(_m_pmullw(v32, v35), 8u)));
            }
            *(_DWORD *)&v20[4 * v22] = _mm_cvtsi64_si32(_m_packuswb(v32, 0i64));
          }
        }
        v20 -= v39;
        --v21;
      }
      while ( v21 );
    }
  }
  _m_femms();
}

//----- (0066ADA0) --------------------------------------------------------  // acclient.c:641670
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // edx@1
  int v2; // esi@2
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // ST0C_4@9
  __m64 v8; // mm2@9
  __m64 v9; // mm1@9
  __m64 v10; // mm0@9
  __m64 v11; // mm3@9
  __m64 v12; // mm4@9
  __m64 v13; // mm0@9
  __m64 v14; // mm4@9
  __m64 v15; // mm3@9
  __m64 v16; // mm4@9
  unsigned int v17; // eax@9
  __m64 v18; // mm0@9
  __m64 v19; // mm2@10
  __m64 v20; // mm3@10
  __m64 v21; // mm2@10
  unsigned int v22; // ST0C_4@11
  bool v23; // zf@13
  unsigned int v24; // edi@16
  int v25; // eax@18
  unsigned int v26; // edx@18
  unsigned int v27; // ST0C_4@20
  __m64 v28; // mm2@20
  __m64 v29; // mm1@20
  __m64 v30; // mm0@20
  __m64 v31; // mm3@20
  __m64 v32; // mm4@20
  __m64 v33; // mm0@20
  __m64 v34; // mm4@20
  __m64 v35; // mm3@20
  __m64 v36; // mm4@20
  __m64 v37; // mm0@20
  __m64 v38; // mm2@21
  __m64 v39; // mm3@21
  __m64 v40; // mm2@21
  unsigned int v41; // ST0C_4@22
  unsigned int v42; // [sp+10h] [bp-10h]@3
  unsigned int v43; // [sp+10h] [bp-10h]@16
  unsigned int v44; // [sp+14h] [bp-Ch]@5
  char v45; // [sp+17h] [bp-9h]@15
  char *v46; // [sp+18h] [bp-8h]@2
  unsigned int v47; // [sp+18h] [bp-8h]@16
  unsigned int v48; // [sp+1Ch] [bp-4h]@3
  char *v49; // [sp+1Ch] [bp-4h]@15

  v1 = (int)i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v46 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v42 = i_args->cDstArgs.iStride;
      v48 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = BYTE3(g_SourceColor.u);
          v5 = v3 + v1 + 2 * v3 + 2;
          v44 = v3;
          do
          {
            v5 -= 3;
            v6 = v4;
            if ( v2 != 256 )
              v6 = v2 * v4 / 256;
            if ( v6 )
            {
              LOBYTE(v7) = *(_BYTE *)(v5 - 2);
              BYTE1(v7) = *(_BYTE *)(v5 - 1);
              BYTE2(v7) = *(_BYTE *)v5;
              BYTE3(v7) = -1;
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64);
              v10 = _m_pand(v9, v8);
              v11 = _m_psllq(v10, 0x10u);
              v12 = _m_pcmpgtw(v10, v11);
              v13 = _m_por(_m_pand(v10, v12), _m_pandn(v12, v11));
              v14 = _m_por(_m_psllq(v13, 0x20u), _m_psrlq(v13, 0x20u));
              v15 = v14;
              v16 = _m_pcmpgtw(v13, v14);
              v17 = v6 + 1;
              v18 = _m_por(_m_pand(_m_por(_m_pand(v13, v16), _m_pandn(v16, v15)), v8), _m_pandn(v8, v9));
              if ( v17 != 256 )
              {
                v19 = _mm_cvtsi32_si64(v17);
                v20 = _m_punpcklwd(v19, v19);
                v21 = _m_punpcklwd(v20, v20);
                v18 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v21), 8u), _m_psrlw(_m_pmullw(v18, v21), 8u)));
              }
              v22 = _mm_cvtsi64_si32(_m_packuswb(v18, 0i64));
              *(_BYTE *)(v5 - 2) = v22;
              *(_BYTE *)(v5 - 1) = BYTE1(v22);
              *(_BYTE *)v5 = v22 >> 16;
            }
            --v44;
          }
          while ( v44 );
        }
        v1 = (int)&v46[v42];
        v23 = v48 == 1;
        v46 += v42;
        --v48;
      }
      while ( !v23 );
    }
  }
  else
  {
    v45 = i_args->i8AlphaModifier;
    v49 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v24 = i_args->nWidth;
      v43 = i_args->cDstArgs.iStride;
      v47 = i_args->nHeight;
      do
      {
        if ( v24 )
        {
          v25 = v24 + v1 + 2 * v24 + 2;
          v26 = v24;
          do
          {
            v25 -= 3;
            if ( v45 )
            {
              LOBYTE(v27) = *(_BYTE *)(v25 - 2);
              BYTE1(v27) = *(_BYTE *)(v25 - 1);
              BYTE2(v27) = *(_BYTE *)v25;
              BYTE3(v27) = -1;
              v28 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v29 = _m_punpcklbw(_mm_cvtsi32_si64(v27), 0i64);
              v30 = _m_pand(v29, v28);
              v31 = _m_psllq(v30, 0x10u);
              v32 = _m_pcmpgtw(v30, v31);
              v33 = _m_por(_m_pand(v30, v32), _m_pandn(v32, v31));
              v34 = _m_por(_m_psllq(v33, 0x20u), _m_psrlq(v33, 0x20u));
              v35 = v34;
              v36 = _m_pcmpgtw(v33, v34);
              v37 = _m_por(_m_pand(_m_por(_m_pand(v33, v36), _m_pandn(v36, v35)), v28), _m_pandn(v28, v29));
              if ( (unsigned __int8)v45 != 255 )
              {
                v38 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v45 + 1);
                v39 = _m_punpcklwd(v38, v38);
                v40 = _m_punpcklwd(v39, v39);
                v37 = _m_psubw(v29, _m_psubw(_m_psrlw(_m_pmullw(v29, v40), 8u), _m_psrlw(_m_pmullw(v37, v40), 8u)));
              }
              v41 = _mm_cvtsi64_si32(_m_packuswb(v37, 0i64));
              *(_BYTE *)(v25 - 2) = v41;
              *(_BYTE *)(v25 - 1) = BYTE1(v41);
              *(_BYTE *)v25 = v41 >> 16;
            }
            --v26;
          }
          while ( v26 );
        }
        v1 = (int)&v49[-v43];
        v23 = v47 == 1;
        v49 -= v43;
        --v47;
      }
      while ( !v23 );
    }
  }
  _m_femms();
}

//----- (0066B080) --------------------------------------------------------  // acclient.c:641848
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edi@2
  char *v2; // ebx@2
  int v3; // esi@2
  unsigned int v4; // ecx@4
  int v5; // edx@5
  unsigned int v6; // eax@5
  __m64 v7; // mm2@8
  __m64 v8; // mm1@8
  __m64 v9; // mm0@8
  __m64 v10; // mm3@8
  __m64 v11; // mm4@8
  __m64 v12; // mm0@8
  __m64 v13; // mm4@8
  __m64 v14; // mm3@8
  __m64 v15; // mm4@8
  unsigned int v16; // eax@8
  __m64 v17; // mm0@8
  __m64 v18; // mm2@9
  __m64 v19; // mm3@9
  __m64 v20; // mm2@9
  char *v21; // edx@14
  unsigned int v22; // edi@15
  unsigned int v23; // ecx@16
  __m64 v24; // mm2@18
  __m64 v25; // mm1@18
  __m64 v26; // mm0@18
  __m64 v27; // mm3@18
  __m64 v28; // mm4@18
  __m64 v29; // mm0@18
  __m64 v30; // mm4@18
  __m64 v31; // mm3@18
  __m64 v32; // mm4@18
  __m64 v33; // mm0@18
  __m64 v34; // mm2@19
  __m64 v35; // mm3@19
  __m64 v36; // mm2@19
  unsigned int v37; // [sp+Ch] [bp-14h]@3
  unsigned int v38; // [sp+Ch] [bp-14h]@15
  unsigned int v39; // [sp+10h] [bp-10h]@3
  unsigned int v40; // [sp+10h] [bp-10h]@15
  unsigned int v41; // [sp+14h] [bp-Ch]@3
  unsigned int v42; // [sp+1Ch] [bp-4h]@3
  char v43; // [sp+1Fh] [bp-1h]@14

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = i_args->cSrcArgs.pDstBuf;
    v3 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v37 = i_args->nWidth;
      v42 = i_args->cSrcArgs.iStride;
      v39 = i_args->cDstArgs.iStride;
      v41 = i_args->nHeight;
      do
      {
        v4 = v37;
        while ( v4 )
        {
          v5 = (unsigned __int8)v2[v4-- - 1];
          v6 = (g_SourceColor.u | (v5 << 24)) >> 24;
          if ( v3 != 256 )
            v6 = (signed int)(v3 * v6) / 256;
          if ( v6 )
          {
            v7 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v8 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v4]), 0i64);
            v9 = _m_pand(v8, v7);
            v10 = _m_psllq(v9, 0x10u);
            v11 = _m_pcmpgtw(v9, v10);
            v12 = _m_por(_m_pand(v9, v11), _m_pandn(v11, v10));
            v13 = _m_por(_m_psllq(v12, 0x20u), _m_psrlq(v12, 0x20u));
            v14 = v13;
            v15 = _m_pcmpgtw(v12, v13);
            v16 = v6 + 1;
            v17 = _m_por(_m_pand(_m_por(_m_pand(v12, v15), _m_pandn(v15, v14)), v7), _m_pandn(v7, v8));
            if ( v16 != 256 )
            {
              v18 = _mm_cvtsi32_si64(v16);
              v19 = _m_punpcklwd(v18, v18);
              v20 = _m_punpcklwd(v19, v19);
              v17 = _m_psubw(v8, _m_psubw(_m_psrlw(_m_pmullw(v8, v20), 8u), _m_psrlw(_m_pmullw(v17, v20), 8u)));
            }
            *(_DWORD *)&v1[4 * v4] = _mm_cvtsi64_si32(_m_packuswb(v17, 0i64));
          }
        }
        v2 += v42;
        v1 += v39;
        --v41;
      }
      while ( v41 );
    }
  }
  else
  {
    v21 = i_args->cDstArgs.pDstBuf;
    v43 = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v38 = i_args->nWidth;
      v40 = i_args->cDstArgs.iStride;
      v22 = i_args->nHeight;
      do
      {
        v23 = v38;
        while ( v23 )
        {
          --v23;
          if ( v43 )
          {
            v24 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v25 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v21[4 * v23]), 0i64);
            v26 = _m_pand(v25, v24);
            v27 = _m_psllq(v26, 0x10u);
            v28 = _m_pcmpgtw(v26, v27);
            v29 = _m_por(_m_pand(v26, v28), _m_pandn(v28, v27));
            v30 = _m_por(_m_psllq(v29, 0x20u), _m_psrlq(v29, 0x20u));
            v31 = v30;
            v32 = _m_pcmpgtw(v29, v30);
            v33 = _m_por(_m_pand(_m_por(_m_pand(v29, v32), _m_pandn(v32, v31)), v24), _m_pandn(v24, v25));
            if ( (unsigned __int8)v43 != 255 )
            {
              v34 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v43 + 1);
              v35 = _m_punpcklwd(v34, v34);
              v36 = _m_punpcklwd(v35, v35);
              v33 = _m_psubw(v25, _m_psubw(_m_psrlw(_m_pmullw(v25, v36), 8u), _m_psrlw(_m_pmullw(v33, v36), 8u)));
            }
            *(_DWORD *)&v21[4 * v23] = _mm_cvtsi64_si32(_m_packuswb(v33, 0i64));
          }
        }
        v21 -= v40;
        --v22;
      }
      while ( v22 );
    }
  }
  _m_femms();
}

//----- (0066B300) --------------------------------------------------------  // acclient.c:641991
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // edx@1
  char *v2; // ebx@2
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  int v6; // edx@6
  unsigned int v7; // eax@6
  unsigned int v8; // ST0C_4@9
  __m64 v9; // mm2@9
  __m64 v10; // mm1@9
  __m64 v11; // mm0@9
  __m64 v12; // mm3@9
  __m64 v13; // mm4@9
  __m64 v14; // mm0@9
  __m64 v15; // mm4@9
  __m64 v16; // mm3@9
  __m64 v17; // mm4@9
  unsigned int v18; // eax@9
  __m64 v19; // mm0@9
  __m64 v20; // mm2@10
  __m64 v21; // mm3@10
  __m64 v22; // mm2@10
  unsigned int v23; // ST0C_4@11
  bool v24; // zf@13
  unsigned int v25; // edi@16
  int v26; // eax@18
  unsigned int v27; // edx@18
  unsigned int v28; // ST0C_4@20
  __m64 v29; // mm2@20
  __m64 v30; // mm1@20
  __m64 v31; // mm0@20
  __m64 v32; // mm3@20
  __m64 v33; // mm4@20
  __m64 v34; // mm0@20
  __m64 v35; // mm4@20
  __m64 v36; // mm3@20
  __m64 v37; // mm4@20
  __m64 v38; // mm0@20
  __m64 v39; // mm2@21
  __m64 v40; // mm3@21
  __m64 v41; // mm2@21
  unsigned int v42; // ST0C_4@22
  unsigned int v43; // [sp+10h] [bp-18h]@3
  unsigned int v44; // [sp+10h] [bp-18h]@16
  char *v45; // [sp+14h] [bp-14h]@2
  unsigned int v46; // [sp+14h] [bp-14h]@16
  unsigned int v47; // [sp+18h] [bp-10h]@3
  char *v48; // [sp+18h] [bp-10h]@15
  unsigned int v49; // [sp+1Ch] [bp-Ch]@3
  unsigned int v50; // [sp+24h] [bp-4h]@3
  char v51; // [sp+27h] [bp-1h]@15

  v1 = (int)i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v2 = i_args->cSrcArgs.pDstBuf;
    v45 = i_args->cDstArgs.pDstBuf;
    v3 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v49 = i_args->nWidth;
      v50 = i_args->cSrcArgs.iStride;
      v43 = i_args->cDstArgs.iStride;
      v47 = i_args->nHeight;
      do
      {
        v4 = v49;
        if ( v49 )
        {
          v5 = v49 + v1 + 2 * v49 + 2;
          do
          {
            v6 = (unsigned __int8)v2[v4-- - 1];
            v5 -= 3;
            v7 = (g_SourceColor.u | (v6 << 24)) >> 24;
            if ( v3 != 256 )
              v7 = (signed int)(v3 * v7) / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v5 - 2);
              BYTE1(v8) = *(_BYTE *)(v5 - 1);
              BYTE2(v8) = *(_BYTE *)v5;
              BYTE3(v8) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_pand(v10, v9);
              v12 = _m_psllq(v11, 0x10u);
              v13 = _m_pcmpgtw(v11, v12);
              v14 = _m_por(_m_pand(v11, v13), _m_pandn(v13, v12));
              v15 = _m_por(_m_psllq(v14, 0x20u), _m_psrlq(v14, 0x20u));
              v16 = v15;
              v17 = _m_pcmpgtw(v14, v15);
              v18 = v7 + 1;
              v19 = _m_por(_m_pand(_m_por(_m_pand(v14, v17), _m_pandn(v17, v16)), v9), _m_pandn(v9, v10));
              if ( v18 != 256 )
              {
                v20 = _mm_cvtsi32_si64(v18);
                v21 = _m_punpcklwd(v20, v20);
                v22 = _m_punpcklwd(v21, v21);
                v19 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v22), 8u), _m_psrlw(_m_pmullw(v19, v22), 8u)));
              }
              v23 = _mm_cvtsi64_si32(_m_packuswb(v19, 0i64));
              *(_BYTE *)(v5 - 2) = v23;
              *(_BYTE *)(v5 - 1) = BYTE1(v23);
              *(_BYTE *)v5 = v23 >> 16;
            }
          }
          while ( v4 );
        }
        v2 += v50;
        v1 = (int)&v45[v43];
        v24 = v47 == 1;
        v45 += v43;
        --v47;
      }
      while ( !v24 );
    }
  }
  else
  {
    v51 = i_args->i8AlphaModifier;
    v48 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v25 = i_args->nWidth;
      v44 = i_args->cDstArgs.iStride;
      v46 = i_args->nHeight;
      do
      {
        if ( v25 )
        {
          v26 = v25 + v1 + 2 * v25 + 2;
          v27 = v25;
          do
          {
            v26 -= 3;
            if ( v51 )
            {
              LOBYTE(v28) = *(_BYTE *)(v26 - 2);
              BYTE1(v28) = *(_BYTE *)(v26 - 1);
              BYTE2(v28) = *(_BYTE *)v26;
              BYTE3(v28) = -1;
              v29 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v30 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
              v31 = _m_pand(v30, v29);
              v32 = _m_psllq(v31, 0x10u);
              v33 = _m_pcmpgtw(v31, v32);
              v34 = _m_por(_m_pand(v31, v33), _m_pandn(v33, v32));
              v35 = _m_por(_m_psllq(v34, 0x20u), _m_psrlq(v34, 0x20u));
              v36 = v35;
              v37 = _m_pcmpgtw(v34, v35);
              v38 = _m_por(_m_pand(_m_por(_m_pand(v34, v37), _m_pandn(v37, v36)), v29), _m_pandn(v29, v30));
              if ( (unsigned __int8)v51 != 255 )
              {
                v39 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v51 + 1);
                v40 = _m_punpcklwd(v39, v39);
                v41 = _m_punpcklwd(v40, v40);
                v38 = _m_psubw(v30, _m_psubw(_m_psrlw(_m_pmullw(v30, v41), 8u), _m_psrlw(_m_pmullw(v38, v41), 8u)));
              }
              v42 = _mm_cvtsi64_si32(_m_packuswb(v38, 0i64));
              *(_BYTE *)(v26 - 2) = v42;
              *(_BYTE *)(v26 - 1) = BYTE1(v42);
              *(_BYTE *)v26 = v42 >> 16;
            }
            --v27;
          }
          while ( v27 );
        }
        v1 = (int)&v48[-v44];
        v24 = v46 == 1;
        v48 -= v44;
        --v46;
      }
      while ( !v24 );
    }
  }
  _m_femms();
}

//----- (0066B610) --------------------------------------------------------  // acclient.c:642173
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  char *v1; // edx@1
  int v2; // edi@2
  unsigned int v3; // esi@3
  unsigned int v4; // ebx@3
  unsigned int *v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // eax@6
  __m64 v8; // mm2@9
  __m64 v9; // mm1@9
  __m64 v10; // mm0@9
  __m64 v11; // mm3@9
  __m64 v12; // mm4@9
  __m64 v13; // mm0@9
  __m64 v14; // mm4@9
  __m64 v15; // mm3@9
  __m64 v16; // mm4@9
  unsigned int v17; // eax@9
  __m64 v18; // mm0@9
  __m64 v19; // mm2@10
  __m64 v20; // mm3@10
  __m64 v21; // mm2@10
  bool v22; // zf@14
  unsigned int v23; // edi@17
  unsigned int v24; // ecx@18
  __m64 v25; // mm2@20
  __m64 v26; // mm1@20
  __m64 v27; // mm0@20
  __m64 v28; // mm3@20
  __m64 v29; // mm4@20
  __m64 v30; // mm0@20
  __m64 v31; // mm4@20
  __m64 v32; // mm3@20
  __m64 v33; // mm4@20
  __m64 v34; // mm0@20
  __m64 v35; // mm2@21
  __m64 v36; // mm3@21
  __m64 v37; // mm2@21
  char *v38; // [sp+10h] [bp-20h]@2
  unsigned int v39; // [sp+14h] [bp-1Ch]@3
  unsigned int v40; // [sp+14h] [bp-1Ch]@17
  unsigned int v41; // [sp+18h] [bp-18h]@5
  unsigned int v42; // [sp+1Ch] [bp-14h]@3
  char *v43; // [sp+20h] [bp-10h]@2
  unsigned int v44; // [sp+24h] [bp-Ch]@3
  char v45; // [sp+2Bh] [bp-5h]@16
  unsigned int v46; // [sp+2Ch] [bp-4h]@3
  unsigned int v47; // [sp+2Ch] [bp-4h]@17

  v1 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v38 = i_args->cSrcArgs.pDstBuf;
    v43 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v46 = i_args->cSrcArgs.iStride;
      v4 = g_SourceColor.u;
      v42 = i_args->nWidth;
      v39 = i_args->cDstArgs.iStride;
      v44 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v5 = (unsigned int *)&v1[4 * v3];
          v41 = v42;
          do
          {
            v6 = *(unsigned int *)((char *)v5 + v38 - v1 - 4);
            --v5;
            v7 = (v4 | v6 & 0xFF000000) >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(*v5), 0i64);
              v10 = _m_pand(v9, v8);
              v11 = _m_psllq(v10, 0x10u);
              v12 = _m_pcmpgtw(v10, v11);
              v13 = _m_por(_m_pand(v10, v12), _m_pandn(v12, v11));
              v14 = _m_por(_m_psllq(v13, 0x20u), _m_psrlq(v13, 0x20u));
              v15 = v14;
              v16 = _m_pcmpgtw(v13, v14);
              v17 = v7 + 1;
              v18 = _m_por(_m_pand(_m_por(_m_pand(v13, v16), _m_pandn(v16, v15)), v8), _m_pandn(v8, v9));
              if ( v17 != 256 )
              {
                v19 = _mm_cvtsi32_si64(v17);
                v20 = _m_punpcklwd(v19, v19);
                v21 = _m_punpcklwd(v20, v20);
                v18 = _m_psubw(v9, _m_psubw(_m_psrlw(_m_pmullw(v9, v21), 8u), _m_psrlw(_m_pmullw(v18, v21), 8u)));
              }
              *v5 = _mm_cvtsi64_si32(_m_packuswb(v18, 0i64));
            }
            --v41;
          }
          while ( v41 );
          v1 = v43;
          v3 = v42;
        }
        v38 += v46;
        v1 += v39;
        v22 = v44 == 1;
        v43 = v1;
        --v44;
      }
      while ( !v22 );
    }
  }
  else
  {
    v45 = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v47 = i_args->nWidth;
      v40 = i_args->cDstArgs.iStride;
      v23 = i_args->nHeight;
      do
      {
        v24 = v47;
        while ( v24 )
        {
          --v24;
          if ( v45 )
          {
            v25 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
            v26 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v1[4 * v24]), 0i64);
            v27 = _m_pand(v26, v25);
            v28 = _m_psllq(v27, 0x10u);
            v29 = _m_pcmpgtw(v27, v28);
            v30 = _m_por(_m_pand(v27, v29), _m_pandn(v29, v28));
            v31 = _m_por(_m_psllq(v30, 0x20u), _m_psrlq(v30, 0x20u));
            v32 = v31;
            v33 = _m_pcmpgtw(v30, v31);
            v34 = _m_por(_m_pand(_m_por(_m_pand(v30, v33), _m_pandn(v33, v32)), v25), _m_pandn(v25, v26));
            if ( (unsigned __int8)v45 != 255 )
            {
              v35 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v45 + 1);
              v36 = _m_punpcklwd(v35, v35);
              v37 = _m_punpcklwd(v36, v36);
              v34 = _m_psubw(v26, _m_psubw(_m_psrlw(_m_pmullw(v26, v37), 8u), _m_psrlw(_m_pmullw(v34, v37), 8u)));
            }
            *(_DWORD *)&v1[4 * v24] = _mm_cvtsi64_si32(_m_packuswb(v34, 0i64));
          }
        }
        v1 -= v40;
        --v23;
      }
      while ( v23 );
    }
  }
  _m_femms();
}

//----- (0066B8C0) --------------------------------------------------------  // acclient.c:642333
void __cdecl ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  int v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  int v6; // edx@6
  unsigned int v7; // eax@6
  unsigned int v8; // ST0C_4@9
  __m64 v9; // mm2@9
  __m64 v10; // mm1@9
  __m64 v11; // mm0@9
  __m64 v12; // mm3@9
  __m64 v13; // mm4@9
  __m64 v14; // mm0@9
  __m64 v15; // mm4@9
  __m64 v16; // mm3@9
  __m64 v17; // mm4@9
  unsigned int v18; // eax@9
  __m64 v19; // mm0@9
  __m64 v20; // mm2@10
  __m64 v21; // mm3@10
  __m64 v22; // mm2@10
  unsigned int v23; // ST0C_4@11
  bool v24; // zf@13
  unsigned int v25; // edi@16
  int v26; // eax@18
  unsigned int v27; // edx@18
  unsigned int v28; // ST0C_4@20
  __m64 v29; // mm2@20
  __m64 v30; // mm1@20
  __m64 v31; // mm0@20
  __m64 v32; // mm3@20
  __m64 v33; // mm4@20
  __m64 v34; // mm0@20
  __m64 v35; // mm4@20
  __m64 v36; // mm3@20
  __m64 v37; // mm4@20
  __m64 v38; // mm0@20
  __m64 v39; // mm2@21
  __m64 v40; // mm3@21
  __m64 v41; // mm2@21
  unsigned int v42; // ST0C_4@22
  unsigned int v43; // [sp+10h] [bp-18h]@3
  unsigned int v44; // [sp+10h] [bp-18h]@16
  char *v45; // [sp+14h] [bp-14h]@2
  unsigned int v46; // [sp+14h] [bp-14h]@16
  unsigned int v47; // [sp+18h] [bp-10h]@3
  char *v48; // [sp+18h] [bp-10h]@15
  unsigned int v49; // [sp+1Ch] [bp-Ch]@3
  unsigned int v50; // [sp+24h] [bp-4h]@3
  char v51; // [sp+27h] [bp-1h]@15

  v1 = (int)i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  if ( v2 )
  {
    v45 = i_args->cDstArgs.pDstBuf;
    v3 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v49 = i_args->nWidth;
      v50 = i_args->cSrcArgs.iStride;
      v43 = i_args->cDstArgs.iStride;
      v47 = i_args->nHeight;
      do
      {
        v4 = v49;
        if ( v49 )
        {
          v5 = v49 + v1 + 2 * v49 + 2;
          do
          {
            v6 = *(_DWORD *)&v2[4 * v4-- - 4];
            v5 -= 3;
            v7 = (g_SourceColor.u | v6 & 0xFF000000) >> 24;
            if ( v3 != 256 )
              v7 = (signed int)(v3 * v7) / 256;
            if ( v7 )
            {
              LOBYTE(v8) = *(_BYTE *)(v5 - 2);
              BYTE1(v8) = *(_BYTE *)(v5 - 1);
              BYTE2(v8) = *(_BYTE *)v5;
              BYTE3(v8) = -1;
              v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
              v11 = _m_pand(v10, v9);
              v12 = _m_psllq(v11, 0x10u);
              v13 = _m_pcmpgtw(v11, v12);
              v14 = _m_por(_m_pand(v11, v13), _m_pandn(v13, v12));
              v15 = _m_por(_m_psllq(v14, 0x20u), _m_psrlq(v14, 0x20u));
              v16 = v15;
              v17 = _m_pcmpgtw(v14, v15);
              v18 = v7 + 1;
              v19 = _m_por(_m_pand(_m_por(_m_pand(v14, v17), _m_pandn(v17, v16)), v9), _m_pandn(v9, v10));
              if ( v18 != 256 )
              {
                v20 = _mm_cvtsi32_si64(v18);
                v21 = _m_punpcklwd(v20, v20);
                v22 = _m_punpcklwd(v21, v21);
                v19 = _m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v22), 8u), _m_psrlw(_m_pmullw(v19, v22), 8u)));
              }
              v23 = _mm_cvtsi64_si32(_m_packuswb(v19, 0i64));
              *(_BYTE *)(v5 - 2) = v23;
              *(_BYTE *)(v5 - 1) = BYTE1(v23);
              *(_BYTE *)v5 = v23 >> 16;
            }
          }
          while ( v4 );
        }
        v2 += v50;
        v1 = (int)&v45[v43];
        v24 = v47 == 1;
        v45 += v43;
        --v47;
      }
      while ( !v24 );
    }
  }
  else
  {
    v51 = i_args->i8AlphaModifier;
    v48 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v25 = i_args->nWidth;
      v44 = i_args->cDstArgs.iStride;
      v46 = i_args->nHeight;
      do
      {
        if ( v25 )
        {
          v26 = v25 + v1 + 2 * v25 + 2;
          v27 = v25;
          do
          {
            v26 -= 3;
            if ( v51 )
            {
              LOBYTE(v28) = *(_BYTE *)(v26 - 2);
              BYTE1(v28) = *(_BYTE *)(v26 - 1);
              BYTE2(v28) = *(_BYTE *)v26;
              BYTE3(v28) = -1;
              v29 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              v30 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
              v31 = _m_pand(v30, v29);
              v32 = _m_psllq(v31, 0x10u);
              v33 = _m_pcmpgtw(v31, v32);
              v34 = _m_por(_m_pand(v31, v33), _m_pandn(v33, v32));
              v35 = _m_por(_m_psllq(v34, 0x20u), _m_psrlq(v34, 0x20u));
              v36 = v35;
              v37 = _m_pcmpgtw(v34, v35);
              v38 = _m_por(_m_pand(_m_por(_m_pand(v34, v37), _m_pandn(v37, v36)), v29), _m_pandn(v29, v30));
              if ( (unsigned __int8)v51 != 255 )
              {
                v39 = _mm_cvtsi32_si64((unsigned int)(unsigned __int8)v51 + 1);
                v40 = _m_punpcklwd(v39, v39);
                v41 = _m_punpcklwd(v40, v40);
                v38 = _m_psubw(v30, _m_psubw(_m_psrlw(_m_pmullw(v30, v41), 8u), _m_psrlw(_m_pmullw(v38, v41), 8u)));
              }
              v42 = _mm_cvtsi64_si32(_m_packuswb(v38, 0i64));
              *(_BYTE *)(v26 - 2) = v42;
              *(_BYTE *)(v26 - 1) = BYTE1(v42);
              *(_BYTE *)v26 = v42 >> 16;
            }
            --v27;
          }
          while ( v27 );
        }
        v1 = (int)&v48[-v44];
        v24 = v46 == 1;
        v48 -= v44;
        --v46;
      }
      while ( !v24 );
    }
  }
  _m_femms();
}

//----- (0066BBC0) --------------------------------------------------------  // acclient.c:642515
void __cdecl AlphaConvert<ACvtFormat_Fill,ACvtFormat_A>(AlphaConvertArgs *i_rCvtArgs)
{
  unsigned int v1; // edx@1
  char *v2; // ecx@1
  char *v3; // esi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // ebp@2
  unsigned int v6; // edi@2
  unsigned int v7; // eax@3
  char v8; // dl@4
  unsigned int i_rCvtArgsa; // [sp+8h] [bp+4h]@2

  v1 = i_rCvtArgs->nHeight;
  v2 = i_rCvtArgs->cDstArgs.pDstBuf;
  v3 = i_rCvtArgs->cSrcArgs.pDstBuf;
  if ( (signed int)v1 > 0 )
  {
    v4 = i_rCvtArgs->cSrcArgs.iStride;
    v5 = i_rCvtArgs->cDstArgs.iStride;
    i_rCvtArgsa = i_rCvtArgs->nWidth;
    v6 = v1;
    do
    {
      v7 = i_rCvtArgsa;
      if ( (signed int)i_rCvtArgsa > 0 )
      {
        v8 = *v3;
        do
        {
          --v7;
          v2[v7] = v8;
        }
        while ( (signed int)v7 > 0 );
      }
      v3 += v4;
      v2 += v5;
      --v6;
    }
    while ( v6 );
  }
}

//----- (0066BC10) --------------------------------------------------------  // acclient.c:642558
void __cdecl AlphaConvert<ACvtFormat_Fill,ACvtFormat_AXXX>(AlphaConvertArgs *i_rCvtArgs)
{
  unsigned int v1; // edx@1
  char *v2; // ecx@1
  char *v3; // esi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // ebp@2
  unsigned int v6; // edi@2
  unsigned int v7; // eax@3
  char v8; // dl@4
  unsigned int i_rCvtArgsa; // [sp+8h] [bp+4h]@2

  v1 = i_rCvtArgs->nHeight;
  v2 = i_rCvtArgs->cDstArgs.pDstBuf + 3;
  v3 = i_rCvtArgs->cSrcArgs.pDstBuf;
  if ( (signed int)v1 > 0 )
  {
    v4 = i_rCvtArgs->cSrcArgs.iStride;
    v5 = i_rCvtArgs->cDstArgs.iStride;
    i_rCvtArgsa = i_rCvtArgs->nWidth;
    v6 = v1;
    do
    {
      v7 = i_rCvtArgsa;
      if ( (signed int)i_rCvtArgsa > 0 )
      {
        v8 = *v3;
        do
        {
          --v7;
          v2[4 * v7] = v8;
        }
        while ( (signed int)v7 > 0 );
      }
      v3 += v4;
      v2 += v5;
      --v6;
    }
    while ( v6 );
  }
}

//----- (0066BC60) --------------------------------------------------------  // acclient.c:642601
void __cdecl AlphaConvert<ACvtFormat_A,ACvtFormat_AXXX>(AlphaConvertArgs *i_rCvtArgs)
{
  unsigned int v1; // edx@1
  char *v2; // ecx@1
  char *v3; // esi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // ebp@2
  unsigned int v6; // edi@2
  unsigned int i; // eax@3
  char v8; // dl@4
  unsigned int i_rCvtArgsa; // [sp+8h] [bp+4h]@2

  v1 = i_rCvtArgs->nHeight;
  v2 = i_rCvtArgs->cDstArgs.pDstBuf + 3;
  v3 = i_rCvtArgs->cSrcArgs.pDstBuf;
  if ( (signed int)v1 > 0 )
  {
    v4 = i_rCvtArgs->cDstArgs.iStride;
    v5 = i_rCvtArgs->cSrcArgs.iStride;
    i_rCvtArgsa = i_rCvtArgs->nWidth;
    v6 = v1;
    do
    {
      for ( i = i_rCvtArgsa; (signed int)i > 0; v2[4 * i] = v8 )
        v8 = v3[i-- - 1];
      v3 += v5;
      v2 += v4;
      --v6;
    }
    while ( v6 );
  }
}

//----- (0066BCB0) --------------------------------------------------------  // acclient.c:642635
void __cdecl AlphaConvert<ACvtFormat_AXXX,ACvtFormat_A>(AlphaConvertArgs *i_rCvtArgs)
{
  unsigned int v1; // edx@1
  char *v2; // ecx@1
  char *v3; // esi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // ebp@2
  unsigned int v6; // edi@2
  unsigned int i; // eax@3
  char v8; // dl@4
  unsigned int i_rCvtArgsa; // [sp+8h] [bp+4h]@2

  v1 = i_rCvtArgs->nHeight;
  v2 = i_rCvtArgs->cSrcArgs.pDstBuf + 3;
  v3 = i_rCvtArgs->cDstArgs.pDstBuf;
  if ( (signed int)v1 > 0 )
  {
    v4 = i_rCvtArgs->cDstArgs.iStride;
    v5 = i_rCvtArgs->cSrcArgs.iStride;
    i_rCvtArgsa = i_rCvtArgs->nWidth;
    v6 = v1;
    do
    {
      for ( i = i_rCvtArgsa; (signed int)i > 0; v3[i] = v8 )
        v8 = v2[4 * i-- - 4];
      v2 += v5;
      v3 += v4;
      --v6;
    }
    while ( v6 );
  }
}

//----- (0066BD00) --------------------------------------------------------  // acclient.c:642669
void __cdecl AlphaConvert<ACvtFormat_AXXX,ACvtFormat_AXXX>(AlphaConvertArgs *i_rCvtArgs)
{
  char *v1; // ebp@1
  char *v2; // esi@1
  unsigned int v3; // edx@2
  int v4; // eax@4
  unsigned int v5; // edi@4
  char v6; // bl@5
  unsigned int v7; // [sp+8h] [bp-8h]@2
  unsigned int v8; // [sp+Ch] [bp-4h]@2
  unsigned int i_rCvtArgsa; // [sp+14h] [bp+4h]@2

  v1 = i_rCvtArgs->cSrcArgs.pDstBuf + 3;
  v2 = i_rCvtArgs->cDstArgs.pDstBuf + 3;
  if ( (signed int)i_rCvtArgs->nHeight > 0 )
  {
    v3 = i_rCvtArgs->nWidth;
    v7 = i_rCvtArgs->cSrcArgs.iStride;
    v8 = i_rCvtArgs->cDstArgs.iStride;
    i_rCvtArgsa = i_rCvtArgs->nHeight;
    do
    {
      if ( (signed int)v3 > 0 )
      {
        v4 = (int)&v2[4 * v3];
        v5 = v3;
        do
        {
          v6 = *(_BYTE *)(v1 - v2 + v4 - 4);
          v4 -= 4;
          --v5;
          *(_BYTE *)v4 = v6;
        }
        while ( v5 );
      }
      v1 += v7;
      v2 += v8;
      --i_rCvtArgsa;
    }
    while ( i_rCvtArgsa );
  }
}

//----- (0066BD70) --------------------------------------------------------  // acclient.c:642713
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_1__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@1
  int v2; // edx@2
  unsigned int v3; // edi@3
  __m128 v4; // xmm2@3
  __m128 v5; // xmm3@3
  int v6; // ebx@5
  int v7; // ecx@5
  int v8; // edi@6
  unsigned int v9; // esi@6
  signed int v10; // kr00_4@7
  unsigned int v11; // esi@9
  unsigned int v12; // ebx@10
  __m64 v13; // mm2@12
  __m64 v14; // mm0@12
  __m64 v15; // mm3@12
  __m64 v16; // mm4@12
  __m64 v17; // mm3@12
  __m128 v18; // xmm0@13
  int v19; // ecx@13
  __m128 v20; // xmm0@13
  int v21; // ST14_4@13
  bool v22; // zf@17
  unsigned int v23; // [sp+14h] [bp-3Ch]@10
  char *v24; // [sp+18h] [bp-38h]@1
  int v25; // [sp+1Ch] [bp-34h]@2
  unsigned int v26; // [sp+20h] [bp-30h]@5
  char *v27; // [sp+24h] [bp-2Ch]@1
  unsigned int v28; // [sp+28h] [bp-28h]@3
  int v29; // [sp+2Ch] [bp-24h]@6
  int v30; // [sp+30h] [bp-20h]@5
  unsigned int v31; // [sp+34h] [bp-1Ch]@3
  unsigned int v32; // [sp+38h] [bp-18h]@3
  unsigned int v33; // [sp+3Ch] [bp-14h]@3
  __m128 v34; // [sp+40h] [bp-10h]@0

  v1 = i_args->cDstArgs.pDstBuf;
  v24 = i_args->cSrcArgs.pDstBuf;
  v27 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v25 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v4 = v34;
      v5 = v34;
      v31 = i_args->nWidth;
      v32 = i_args->cSrcArgs.iStride;
      v33 = i_args->cDstArgs.iStride;
      v28 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v6 = v24 - v1;
          v7 = (int)&v1[4 * v3];
          v30 = v24 - v1;
          v26 = v3;
          do
          {
            v8 = *(_DWORD *)(v6 + v7 - 4);
            v7 -= 4;
            v9 = (unsigned int)v8 >> 24;
            v29 = v7;
            if ( v2 != 256 )
            {
              v10 = v2 * v9;
              v2 = v25;
              v9 = v10 / 256;
            }
            if ( v9 )
            {
              v11 = v9 + 1;
              if ( v11 != 256 )
              {
                v12 = *(_DWORD *)v7;
                v23 = *(_DWORD *)v7;
                if ( *(_DWORD *)v7 >> 24 )
                {
                  if ( BYTE3(v23) == -1 )
                  {
                    v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                    v15 = _mm_cvtsi32_si64(v11);
                    v16 = _m_punpcklwd(v15, v15);
                    v17 = _m_punpcklwd(v16, v16);
                    v8 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
                  }
                  else
                  {
                    v18 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64), 0i64));
                    v4.m128_f32[0] = (float)(signed int)v11;
                    v19 = v11 - (signed int)(v11 * (BYTE3(v23) + 1)) / 256 + BYTE3(v23) + 1;
                    v5.m128_f32[0] = (float)v19;
                    v4 = _mm_shuffle_ps(v4, v4, 0);
                    v5 = _mm_shuffle_ps(v5, v5, 0);
                    v20 = _mm_sub_ps(
                            v18,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v18,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64), 0i64))),
                                v4),
                              v5));
                    v21 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v20), _mm_cvt_ps2pi(_mm_movehl_ps(v20, v20))), 0i64));
                    BYTE3(v21) = v19 - 1;
                    v8 = v21;
                    v7 = v29;
                  }
                }
              }
              v6 = v30;
              v2 = v25;
              *(_DWORD *)v7 = v8;
            }
            --v26;
          }
          while ( v26 );
          v1 = v27;
          v3 = v31;
        }
        v1 += v33;
        v22 = v28 == 1;
        v24 += v32;
        v27 = v1;
        --v28;
      }
      while ( !v22 );
    }
    _m_femms();
  }
}

//----- (0066BFB0) --------------------------------------------------------  // acclient.c:642851
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_0__BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@1
  int v2; // edx@2
  unsigned int v3; // ebx@3
  int v4; // ecx@5
  unsigned int *v5; // edi@5
  unsigned int v6; // ebx@6
  unsigned int v7; // esi@6
  unsigned int v8; // esi@9
  int v9; // eax@10
  __m64 v10; // mm2@14
  __m64 v11; // mm0@14
  __m64 v12; // mm3@14
  __m64 v13; // mm4@14
  __m64 v14; // mm3@14
  signed int v15; // ecx@15
  bool v16; // zf@19
  unsigned int v17; // [sp+Ch] [bp-34h]@11
  char *v18; // [sp+14h] [bp-2Ch]@1
  unsigned int v19; // [sp+18h] [bp-28h]@5
  int v20; // [sp+1Ch] [bp-24h]@2
  char *v21; // [sp+20h] [bp-20h]@1
  unsigned int v22; // [sp+24h] [bp-1Ch]@3
  int v23; // [sp+30h] [bp-10h]@5
  unsigned int v24; // [sp+34h] [bp-Ch]@3
  unsigned int v25; // [sp+38h] [bp-8h]@3
  unsigned int v26; // [sp+3Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v18 = i_args->cSrcArgs.pDstBuf;
  v21 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v20 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v24 = i_args->nWidth;
      v25 = i_args->cSrcArgs.iStride;
      v26 = i_args->cDstArgs.iStride;
      v22 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = v18 - v1;
          v5 = (unsigned int *)&v1[4 * v3];
          v23 = v18 - v1;
          v19 = v3;
          do
          {
            v6 = *(unsigned int *)((char *)v5 + v4 - 4);
            --v5;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 == 256 )
              {
                v9 = v6;
              }
              else
              {
                v17 = *v5;
                if ( *v5 >> 24 )
                {
                  if ( BYTE3(v17) == -1 )
                  {
                    v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v11 = _m_punpcklbw(_mm_cvtsi32_si64(*v5), 0i64);
                    v12 = _mm_cvtsi32_si64(v8);
                    v13 = _m_punpcklwd(v12, v12);
                    v14 = _m_punpcklwd(v13, v13);
                    v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
                  }
                  else
                  {
                    v15 = v8 - (signed int)(v8 * (BYTE3(v17) + 1)) / 256 + BYTE3(v17) + 1;
                    BYTE2(v17) -= (signed int)(v8 * (BYTE2(v17) - BYTE2(v6))) / v15;
                    BYTE1(v17) -= (signed int)(v8 * (BYTE1(v17) - BYTE1(v6))) / v15;
                    LOBYTE(v17) = v17
                                - (unsigned int)((signed int)(v8 * ((unsigned __int8)v17 - (unsigned __int8)v6)) / v15);
                    BYTE3(v17) = v15 - 1;
                    v9 = v17;
                  }
                }
                else
                {
                  v9 = v6;
                }
              }
              v4 = v23;
              *v5 = v9;
            }
            v2 = v20;
            --v19;
          }
          while ( v19 );
          v1 = v21;
          v3 = v24;
        }
        v1 += v26;
        v16 = v22 == 1;
        v18 += v25;
        v21 = v1;
        --v22;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (0066C1B0) --------------------------------------------------------  // acclient.c:642969
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_XRGB_0__BlitFormat_ARGB_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  int v4; // ecx@5
  int v5; // esi@6
  unsigned int v6; // eax@6
  unsigned int v7; // eax@9
  unsigned int v8; // ST14_4@10
  __m64 v9; // mm2@10
  __m64 v10; // mm0@10
  __m64 v11; // mm3@10
  __m64 v12; // mm4@10
  __m64 v13; // mm3@10
  bool v14; // zf@14
  char *v15; // [sp+10h] [bp-20h]@1
  unsigned int v16; // [sp+18h] [bp-18h]@5
  char *v17; // [sp+1Ch] [bp-14h]@1
  unsigned int v18; // [sp+20h] [bp-10h]@3
  unsigned int v19; // [sp+24h] [bp-Ch]@3
  unsigned int v20; // [sp+28h] [bp-8h]@3
  unsigned int v21; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v15 = i_args->cSrcArgs.pDstBuf;
  v17 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v19 = i_args->nWidth;
      v20 = i_args->cSrcArgs.iStride;
      v21 = i_args->cDstArgs.iStride;
      v18 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v16 = v3;
          do
          {
            v5 = *(_DWORD *)(v15 - v1 + v4 - 4);
            v4 -= 4;
            v6 = (unsigned int)v5 >> 24;
            if ( v2 != 256 )
              v6 = (signed int)(v2 * v6) / 256;
            if ( v6 )
            {
              v7 = v6 + 1;
              if ( v7 != 256 )
              {
                v8 = *(_DWORD *)v4;
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v8) = -1;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v11 = _mm_cvtsi32_si64(v7);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v5 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
              }
              *(_DWORD *)v4 = v5;
            }
            --v16;
          }
          while ( v16 );
          v3 = v19;
          v1 = v17;
        }
        v1 += v21;
        v14 = v18 == 1;
        v15 += v20;
        v17 = v1;
        --v18;
      }
      while ( !v14 );
    }
    _m_femms();
  }
}

//----- (0066C300) --------------------------------------------------------  // acclient.c:643054
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB_0__BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@4
  int v4; // ecx@5
  unsigned int v5; // edi@6
  unsigned int v6; // eax@6
  unsigned int v7; // eax@9
  unsigned int v8; // ST10_4@11
  __m64 v9; // mm2@11
  __m64 v10; // mm0@11
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  bool v14; // zf@14
  unsigned int v15; // [sp+10h] [bp-20h]@10
  char *v16; // [sp+14h] [bp-1Ch]@1
  char *v17; // [sp+18h] [bp-18h]@1
  unsigned int v18; // [sp+1Ch] [bp-14h]@3
  unsigned int v19; // [sp+20h] [bp-10h]@3
  unsigned int v20; // [sp+28h] [bp-8h]@3
  unsigned int v21; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v16 = i_args->cSrcArgs.pDstBuf;
  v17 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v19 = i_args->nWidth;
      v20 = i_args->cSrcArgs.iStride;
      v21 = i_args->cDstArgs.iStride;
      v18 = i_args->nHeight;
      do
      {
        v3 = v19;
        if ( v19 )
        {
          v4 = (int)(&v1[2 * v19 + 2] + v19);
          do
          {
            v5 = *(_DWORD *)&v16[4 * v3-- - 4];
            v4 -= 3;
            v6 = v5 >> 24;
            if ( v2 != 256 )
              v6 = (signed int)(v2 * v6) / 256;
            if ( v6 )
            {
              v7 = v6 + 1;
              if ( v7 == 256 )
              {
                v15 = v5;
              }
              else
              {
                LOBYTE(v8) = *(_BYTE *)(v4 - 2);
                BYTE1(v8) = *(_BYTE *)(v4 - 1);
                BYTE2(v8) = *(_BYTE *)v4;
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v8) = -1;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v11 = _mm_cvtsi32_si64(v7);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v15 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v5), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
              }
              *(_BYTE *)(v4 - 2) = v15;
              *(_BYTE *)(v4 - 1) = BYTE1(v15);
              *(_BYTE *)v4 = v15 >> 16;
            }
          }
          while ( v3 );
        }
        v16 += v20;
        v1 = &v17[v21];
        v14 = v18 == 1;
        v17 += v21;
        --v18;
      }
      while ( !v14 );
    }
    _m_femms();
  }
}

//----- (0066C480) --------------------------------------------------------  // acclient.c:643143
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_1__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@1
  int v2; // edi@2
  unsigned int v3; // ecx@3
  __m128 v4; // xmm2@3
  __m128 v5; // xmm3@3
  int v6; // ebx@5
  int v7; // ecx@5
  unsigned int v8; // eax@6
  int v9; // esi@6
  unsigned int v10; // esi@8
  int v11; // eax@9
  unsigned int v12; // edi@10
  __m64 v13; // mm2@13
  __m64 v14; // mm0@13
  __m64 v15; // mm3@13
  __m64 v16; // mm4@13
  __m64 v17; // mm3@13
  __m128 v18; // xmm0@14
  int v19; // ecx@14
  __m128 v20; // xmm0@14
  int v21; // ST18_4@14
  bool v22; // zf@18
  unsigned int v23; // [sp+14h] [bp-3Ch]@6
  unsigned int v24; // [sp+18h] [bp-38h]@10
  char *v25; // [sp+1Ch] [bp-34h]@1
  unsigned int v26; // [sp+20h] [bp-30h]@5
  unsigned int v27; // [sp+24h] [bp-2Ch]@3
  char *v28; // [sp+28h] [bp-28h]@1
  unsigned int v29; // [sp+2Ch] [bp-24h]@3
  int v30; // [sp+30h] [bp-20h]@5
  int v31; // [sp+34h] [bp-1Ch]@2
  unsigned int v32; // [sp+38h] [bp-18h]@3
  unsigned int v33; // [sp+3Ch] [bp-14h]@3
  __m128 v34; // [sp+40h] [bp-10h]@0

  v1 = i_args->cDstArgs.pDstBuf;
  v25 = i_args->cSrcArgs.pDstBuf;
  v28 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v31 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v4 = v34;
      v5 = v34;
      v27 = i_args->nWidth;
      v32 = i_args->cSrcArgs.iStride;
      v33 = i_args->cDstArgs.iStride;
      v29 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v6 = (int)&v1[4 * v3];
          v7 = v25 - v1;
          v30 = v25 - v1;
          v26 = v27;
          do
          {
            v8 = *(_DWORD *)(v7 + v6 - 4);
            v6 -= 4;
            v23 = v8;
            BYTE3(v23) = -1;
            v9 = 255;
            if ( v2 == 256 || (v9 = 255 * v2 / 256) != 0 )
            {
              v10 = v9 + 1;
              if ( v10 == 256 )
              {
                v11 = v23;
              }
              else
              {
                v12 = *(_DWORD *)v6;
                v24 = *(_DWORD *)v6;
                if ( *(_DWORD *)v6 >> 24 )
                {
                  if ( BYTE3(v24) == -1 )
                  {
                    v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                    v15 = _mm_cvtsi32_si64(v10);
                    v16 = _m_punpcklwd(v15, v15);
                    v17 = _m_punpcklwd(v16, v16);
                    v11 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
                  }
                  else
                  {
                    v18 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64), 0i64));
                    v4.m128_f32[0] = (float)(signed int)v10;
                    v19 = v10 - (signed int)(v10 * (BYTE3(v24) + 1)) / 256 + BYTE3(v24) + 1;
                    v5.m128_f32[0] = (float)v19;
                    v4 = _mm_shuffle_ps(v4, v4, 0);
                    v5 = _mm_shuffle_ps(v5, v5, 0);
                    v20 = _mm_sub_ps(
                            v18,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v18,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64), 0i64))),
                                v4),
                              v5));
                    v21 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v20), _mm_cvt_ps2pi(_mm_movehl_ps(v20, v20))), 0i64));
                    BYTE3(v21) = v19 - 1;
                    v11 = v21;
                    v7 = v30;
                  }
                }
                else
                {
                  v11 = v23;
                }
              }
              v2 = v31;
              *(_DWORD *)v6 = v11;
            }
            --v26;
          }
          while ( v26 );
          v1 = v28;
          v3 = v27;
        }
        v1 += v33;
        v22 = v29 == 1;
        v25 += v32;
        v28 = v1;
        --v29;
      }
      while ( !v22 );
    }
    _m_femms();
  }
}

//----- (0066C6C0) --------------------------------------------------------  // acclient.c:643283
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_0__BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@1
  int v2; // edx@2
  unsigned int v3; // edi@3
  int v4; // ebx@5
  unsigned int *v5; // edi@5
  unsigned int v6; // eax@6
  int v7; // esi@6
  unsigned int v8; // esi@8
  int v9; // eax@9
  __m64 v10; // mm2@13
  __m64 v11; // mm0@13
  __m64 v12; // mm3@13
  __m64 v13; // mm4@13
  __m64 v14; // mm3@13
  signed int v15; // ecx@14
  bool v16; // zf@18
  unsigned int v17; // [sp+Ch] [bp-34h]@10
  unsigned int v18; // [sp+10h] [bp-30h]@6
  char *v19; // [sp+14h] [bp-2Ch]@1
  unsigned int v20; // [sp+18h] [bp-28h]@5
  int v21; // [sp+1Ch] [bp-24h]@2
  unsigned int v22; // [sp+20h] [bp-20h]@3
  char *v23; // [sp+24h] [bp-1Ch]@1
  unsigned int v24; // [sp+28h] [bp-18h]@3
  int v25; // [sp+34h] [bp-Ch]@5
  unsigned int v26; // [sp+38h] [bp-8h]@3
  unsigned int v27; // [sp+3Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v19 = i_args->cSrcArgs.pDstBuf;
  v23 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v21 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v22 = i_args->nWidth;
      v26 = i_args->cSrcArgs.iStride;
      v27 = i_args->cDstArgs.iStride;
      v24 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = v19 - v1;
          v5 = (unsigned int *)&v1[4 * v3];
          v25 = v19 - v1;
          v20 = v22;
          do
          {
            v6 = *(unsigned int *)((char *)v5 + v4 - 4);
            --v5;
            v18 = v6;
            BYTE3(v18) = -1;
            v7 = 255;
            if ( v2 == 256 || (v7 = 255 * v2 / 256) != 0 )
            {
              v8 = v7 + 1;
              if ( v8 == 256 )
              {
                v9 = v18;
              }
              else
              {
                v17 = *v5;
                if ( *v5 >> 24 )
                {
                  if ( BYTE3(v17) == -1 )
                  {
                    v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v11 = _m_punpcklbw(_mm_cvtsi32_si64(*v5), 0i64);
                    v12 = _mm_cvtsi32_si64(v8);
                    v13 = _m_punpcklwd(v12, v12);
                    v14 = _m_punpcklwd(v13, v13);
                    v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
                  }
                  else
                  {
                    v15 = v8 - (signed int)(v8 * (BYTE3(v17) + 1)) / 256 + BYTE3(v17) + 1;
                    BYTE2(v17) -= (signed int)(v8 * (BYTE2(v17) - BYTE2(v6))) / v15;
                    BYTE1(v17) -= (signed int)(v8 * (BYTE1(v17) - BYTE1(v18))) / v15;
                    LOBYTE(v17) = v17
                                - (unsigned int)((signed int)(v8 * ((unsigned __int8)v17 - (unsigned __int8)v6)) / v15);
                    v4 = v25;
                    BYTE3(v17) = v15 - 1;
                    v9 = v17;
                  }
                }
                else
                {
                  v9 = v18;
                }
              }
              *v5 = v9;
            }
            v2 = v21;
            --v20;
          }
          while ( v20 );
          v1 = v23;
          v3 = v22;
        }
        v1 += v27;
        v16 = v24 == 1;
        v19 += v26;
        v23 = v1;
        --v24;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (0066C8D0) --------------------------------------------------------  // acclient.c:643402
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_XRGB_0__BlitFormat_XRGB_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // edi@2
  unsigned int v3; // esi@3
  int v4; // ecx@5
  unsigned int v5; // eax@6
  int v6; // eax@6
  unsigned int v7; // eax@8
  int v8; // eax@9
  unsigned int v9; // ST14_4@10
  __m64 v10; // mm2@10
  __m64 v11; // mm0@10
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@14
  unsigned int v16; // [sp+Ch] [bp-24h]@6
  char *v17; // [sp+10h] [bp-20h]@1
  unsigned int v18; // [sp+18h] [bp-18h]@5
  unsigned int v19; // [sp+1Ch] [bp-14h]@3
  char *v20; // [sp+20h] [bp-10h]@1
  unsigned int v21; // [sp+24h] [bp-Ch]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v17 = i_args->cSrcArgs.pDstBuf;
  v20 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v19 = i_args->nWidth;
      v23 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v18 = v19;
          do
          {
            v5 = *(_DWORD *)(v17 - v1 + v4 - 4);
            v4 -= 4;
            v16 = v5;
            BYTE3(v16) = -1;
            v6 = 255;
            if ( v2 == 256 || (v6 = 255 * v2 / 256) != 0 )
            {
              v7 = v6 + 1;
              if ( v7 == 256 )
              {
                v8 = v16;
              }
              else
              {
                v9 = *(_DWORD *)v4;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v9) = -1;
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                v12 = _mm_cvtsi32_si64(v7);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v8 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v16), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
              *(_DWORD *)v4 = v8;
            }
            --v18;
          }
          while ( v18 );
          v1 = v20;
          v3 = v19;
        }
        v17 += v22;
        v1 += v23;
        v15 = v21 == 1;
        v20 = v1;
        --v21;
      }
      while ( !v15 );
    }
    _m_femms();
  }
}

//----- (0066CA30) --------------------------------------------------------  // acclient.c:643493
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB_0__BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // esi@4
  int v5; // ecx@5
  unsigned int v6; // edx@6
  int v7; // eax@6
  unsigned int v8; // eax@8
  unsigned int v9; // eax@9
  unsigned int v10; // ST14_4@10
  __m64 v11; // mm2@10
  __m64 v12; // mm0@10
  __m64 v13; // mm3@10
  __m64 v14; // mm4@10
  __m64 v15; // mm3@10
  bool v16; // zf@13
  unsigned int v17; // [sp+18h] [bp-18h]@6
  char *v18; // [sp+1Ch] [bp-14h]@1
  unsigned int v19; // [sp+20h] [bp-10h]@3
  unsigned int v20; // [sp+24h] [bp-Ch]@3
  unsigned int v21; // [sp+28h] [bp-8h]@3
  unsigned int v22; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cDstArgs.pDstBuf;
  v2 = i_args->cSrcArgs.pDstBuf;
  v18 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v20 = i_args->nWidth;
      v21 = i_args->cSrcArgs.iStride;
      v22 = i_args->cDstArgs.iStride;
      v19 = i_args->nHeight;
      do
      {
        v4 = v20;
        if ( v20 )
        {
          v5 = (int)(&v1[2 * v20 + 2] + v20);
          do
          {
            v6 = *(_DWORD *)&v2[4 * v4-- - 4];
            v5 -= 3;
            v17 = v6;
            BYTE3(v17) = -1;
            v7 = 255;
            if ( v3 != 256 )
            {
              v7 = 255 * v3 / 256;
              if ( !v7 )
                continue;
            }
            v8 = v7 + 1;
            if ( v8 == 256 )
            {
              v9 = v17;
            }
            else
            {
              LOBYTE(v10) = *(_BYTE *)(v5 - 2);
              BYTE1(v10) = *(_BYTE *)(v5 - 1);
              BYTE2(v10) = *(_BYTE *)v5;
              v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v10) = -1;
              v12 = _m_punpcklbw(_mm_cvtsi32_si64(v10), 0i64);
              v13 = _mm_cvtsi32_si64(v8);
              v14 = _m_punpcklwd(v13, v13);
              v15 = _m_punpcklwd(v14, v14);
              v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v15), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v17), 0i64), v11), _m_pandn(v11, v12)), v15), 8u))), 0i64));
            }
            *(_BYTE *)(v5 - 2) = v9;
            *(_BYTE *)(v5 - 1) = BYTE1(v9);
            *(_BYTE *)v5 = v9 >> 16;
          }
          while ( v4 );
        }
        v2 += v21;
        v1 = &v18[v22];
        v16 = v19 == 1;
        v18 += v22;
        --v19;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (0066CBA0) --------------------------------------------------------  // acclient.c:643586
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_1__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  __m128 v3; // xmm2@3
  __m128 v4; // xmm3@3
  unsigned int v5; // ecx@4
  int v6; // edi@5
  char v7; // al@6
  char v8; // dl@6
  int v9; // esi@6
  unsigned int v10; // esi@8
  int v11; // eax@9
  unsigned int v12; // ebx@10
  __m64 v13; // mm2@13
  __m64 v14; // mm0@13
  __m64 v15; // mm3@13
  __m64 v16; // mm4@13
  __m64 v17; // mm3@13
  __m128 v18; // xmm0@14
  int v19; // ecx@14
  __m128 v20; // xmm0@14
  int v21; // ST1C_4@14
  bool v22; // zf@17
  unsigned int v23; // [sp+18h] [bp-38h]@5
  int v24; // [sp+1Ch] [bp-34h]@10
  char *v25; // [sp+20h] [bp-30h]@1
  char *v26; // [sp+24h] [bp-2Ch]@1
  unsigned int v27; // [sp+28h] [bp-28h]@3
  unsigned int v28; // [sp+2Ch] [bp-24h]@3
  unsigned int v29; // [sp+30h] [bp-20h]@6
  int v30; // [sp+34h] [bp-1Ch]@2
  unsigned int v31; // [sp+38h] [bp-18h]@3
  unsigned int v32; // [sp+3Ch] [bp-14h]@3
  __m128 v33; // [sp+40h] [bp-10h]@0

  v1 = i_args->cSrcArgs.pDstBuf;
  v26 = i_args->cSrcArgs.pDstBuf;
  v25 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v30 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = v33;
      v4 = v33;
      v28 = i_args->nWidth;
      v31 = i_args->cSrcArgs.iStride;
      v32 = i_args->cDstArgs.iStride;
      v27 = i_args->nHeight;
      do
      {
        v5 = v28;
        if ( v28 )
        {
          BYTE3(v23) = -1;
          v6 = (int)(&v1[2 * v28 + 2] + v28);
          do
          {
            v7 = *(_BYTE *)(v6 - 5);
            v8 = *(_BYTE *)(v6 - 4);
            v6 -= 3;
            --v5;
            LOBYTE(v23) = v7;
            v29 = v5;
            BYTE1(v23) = v8;
            BYTE2(v23) = *(_BYTE *)v6;
            v9 = 255;
            if ( v2 != 256 )
            {
              v9 = 255 * v2 / 256;
              if ( !v9 )
                continue;
            }
            v10 = v9 + 1;
            if ( v10 == 256 )
            {
              v11 = v23;
            }
            else
            {
              v12 = *(_DWORD *)&v25[4 * v5];
              v24 = *(_DWORD *)&v25[4 * v5];
              if ( BYTE3(v24) )
              {
                if ( BYTE3(v24) == -1 )
                {
                  v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                  v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                  v15 = _mm_cvtsi32_si64(v10);
                  v16 = _m_punpcklwd(v15, v15);
                  v17 = _m_punpcklwd(v16, v16);
                  v11 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
                }
                else
                {
                  v18 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64), 0i64));
                  v3.m128_f32[0] = (float)(signed int)v10;
                  v19 = v10 - (signed int)(v10 * (BYTE3(v24) + 1)) / 256 + BYTE3(v24) + 1;
                  v4.m128_f32[0] = (float)v19;
                  v3 = _mm_shuffle_ps(v3, v3, 0);
                  v4 = _mm_shuffle_ps(v4, v4, 0);
                  v20 = _mm_sub_ps(
                          v18,
                          _mm_div_ps(
                            _mm_mul_ps(
                              _mm_sub_ps(
                                v18,
                                _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v23), 0i64), 0i64))),
                              v3),
                            v4));
                  v21 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v20), _mm_cvt_ps2pi(_mm_movehl_ps(v20, v20))), 0i64));
                  BYTE3(v21) = v19 - 1;
                  v11 = v21;
                  v5 = v29;
                }
              }
              else
              {
                v11 = v23;
              }
            }
            v2 = v30;
            *(_DWORD *)&v25[4 * v5] = v11;
          }
          while ( v5 );
        }
        v1 = &v26[v31];
        v22 = v27 == 1;
        v26 += v31;
        v25 += v32;
        --v27;
      }
      while ( !v22 );
    }
    _m_femms();
  }
}

//----- (0066CDF0) --------------------------------------------------------  // acclient.c:643727
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_0__BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // ecx@4
  int v4; // edi@5
  unsigned __int8 v5; // al@6
  unsigned __int8 v6; // dl@6
  int v7; // esi@6
  unsigned int v8; // esi@8
  int v9; // eax@9
  __m64 v10; // mm2@13
  __m64 v11; // mm0@13
  __m64 v12; // mm3@13
  __m64 v13; // mm4@13
  __m64 v14; // mm3@13
  signed int v15; // ecx@14
  bool v16; // zf@17
  unsigned int v17; // [sp+10h] [bp-30h]@5
  int v18; // [sp+14h] [bp-2Ch]@10
  char *v19; // [sp+18h] [bp-28h]@1
  char *v20; // [sp+1Ch] [bp-24h]@1
  unsigned int v21; // [sp+20h] [bp-20h]@3
  unsigned int v22; // [sp+24h] [bp-1Ch]@3
  unsigned int v23; // [sp+30h] [bp-10h]@6
  int v24; // [sp+34h] [bp-Ch]@2
  unsigned int v25; // [sp+38h] [bp-8h]@3
  unsigned int v26; // [sp+3Ch] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v20 = i_args->cSrcArgs.pDstBuf;
  v19 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    v24 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v22 = i_args->nWidth;
      v25 = i_args->cSrcArgs.iStride;
      v26 = i_args->cDstArgs.iStride;
      v21 = i_args->nHeight;
      do
      {
        v3 = v22;
        if ( v22 )
        {
          BYTE3(v17) = -1;
          v4 = (int)(&v1[2 * v22 + 2] + v22);
          do
          {
            v5 = *(_BYTE *)(v4 - 5);
            v6 = *(_BYTE *)(v4 - 4);
            v4 -= 3;
            --v3;
            LOBYTE(v17) = v5;
            v23 = v3;
            BYTE1(v17) = v6;
            BYTE2(v17) = *(_BYTE *)v4;
            v7 = 255;
            if ( v2 != 256 )
            {
              v7 = 255 * v2 / 256;
              if ( !v7 )
                continue;
            }
            v8 = v7 + 1;
            if ( v8 == 256 )
            {
              v9 = v17;
            }
            else
            {
              v18 = *(_DWORD *)&v19[4 * v3];
              if ( BYTE3(v18) )
              {
                if ( BYTE3(v18) == -1 )
                {
                  v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                  v11 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v19[4 * v3]), 0i64);
                  v12 = _mm_cvtsi32_si64(v8);
                  v13 = _m_punpcklwd(v12, v12);
                  v14 = _m_punpcklwd(v13, v13);
                  v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v17), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
                }
                else
                {
                  v15 = v8 - (signed int)(v8 * (BYTE3(v18) + 1)) / 256 + BYTE3(v18) + 1;
                  BYTE2(v18) -= (signed int)(v8 * (BYTE2(v18) - BYTE2(v17))) / v15;
                  BYTE1(v18) -= (signed int)(v8 * (BYTE1(v18) - v6)) / v15;
                  LOBYTE(v18) = v18 - (unsigned int)((signed int)(v8 * ((unsigned __int8)v18 - v5)) / v15);
                  v2 = v24;
                  BYTE3(v18) = v15 - 1;
                  v9 = v18;
                  v3 = v23;
                }
              }
              else
              {
                v9 = v17;
              }
            }
            *(_DWORD *)&v19[4 * v3] = v9;
          }
          while ( v3 );
        }
        v1 = &v20[v25];
        v16 = v21 == 1;
        v20 += v25;
        v19 += v26;
        --v21;
      }
      while ( !v16 );
    }
    _m_femms();
  }
}

//----- (0066D010) --------------------------------------------------------  // acclient.c:643846
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_XRGB_0__BlitFormat_RGB_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  char *v2; // ebx@1
  int v3; // edi@2
  unsigned int v4; // ecx@4
  int v5; // esi@5
  char v6; // al@6
  char v7; // dl@6
  int v8; // eax@6
  unsigned int v9; // eax@8
  int v10; // eax@9
  unsigned int v11; // ST18_4@10
  __m64 v12; // mm2@10
  __m64 v13; // mm0@10
  __m64 v14; // mm3@10
  __m64 v15; // mm4@10
  __m64 v16; // mm3@10
  bool v17; // zf@13
  unsigned int v18; // [sp+14h] [bp-1Ch]@5
  char *v19; // [sp+1Ch] [bp-14h]@1
  unsigned int v20; // [sp+20h] [bp-10h]@3
  unsigned int v21; // [sp+24h] [bp-Ch]@3
  unsigned int v22; // [sp+28h] [bp-8h]@3
  unsigned int v23; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v2 = i_args->cDstArgs.pDstBuf;
  v19 = i_args->cSrcArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v3 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v21 = i_args->nWidth;
      v22 = i_args->cSrcArgs.iStride;
      v23 = i_args->cDstArgs.iStride;
      v20 = i_args->nHeight;
      do
      {
        v4 = v21;
        if ( v21 )
        {
          BYTE3(v18) = -1;
          v5 = (int)(&v1[2 * v21 + 2] + v21);
          do
          {
            v6 = *(_BYTE *)(v5 - 5);
            v7 = *(_BYTE *)(v5 - 4);
            v5 -= 3;
            LOBYTE(v18) = v6;
            --v4;
            BYTE2(v18) = *(_BYTE *)v5;
            BYTE1(v18) = v7;
            v8 = 255;
            if ( v3 != 256 )
            {
              v8 = 255 * v3 / 256;
              if ( !v8 )
                continue;
            }
            v9 = v8 + 1;
            if ( v9 == 256 )
            {
              v10 = v18;
            }
            else
            {
              v11 = *(_DWORD *)&v2[4 * v4];
              v12 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
              BYTE3(v11) = -1;
              v13 = _m_punpcklbw(_mm_cvtsi32_si64(v11), 0i64);
              v14 = _mm_cvtsi32_si64(v9);
              v15 = _m_punpcklwd(v14, v14);
              v16 = _m_punpcklwd(v15, v15);
              v10 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v13, _m_psubw(_m_psrlw(_m_pmullw(v13, v16), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64), v12), _m_pandn(v12, v13)), v16), 8u))), 0i64));
            }
            *(_DWORD *)&v2[4 * v4] = v10;
          }
          while ( v4 );
        }
        v1 = &v19[v22];
        v2 += v23;
        v17 = v20 == 1;
        v19 += v22;
        --v20;
      }
      while ( !v17 );
    }
    _m_femms();
  }
}

//----- (0066D170) --------------------------------------------------------  // acclient.c:643940
void __usercall BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_RGB_0__BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@1
  int v2; // ebx@2
  unsigned int v3; // edx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // esi@5
  char v7; // dl@6
  char v8; // al@6
  int v9; // eax@6
  unsigned int v10; // eax@8
  unsigned int v11; // eax@9
  unsigned int v12; // ST0C_4@10
  __m64 v13; // mm2@10
  __m64 v14; // mm0@10
  __m64 v15; // mm3@10
  __m64 v16; // mm4@10
  __m64 v17; // mm3@10
  bool v18; // zf@14
  unsigned int v19; // [sp+10h] [bp-20h]@5
  char *v20; // [sp+14h] [bp-1Ch]@1
  unsigned int v21; // [sp+18h] [bp-18h]@5
  char *v22; // [sp+1Ch] [bp-14h]@1
  unsigned int v23; // [sp+20h] [bp-10h]@3
  unsigned int v24; // [sp+24h] [bp-Ch]@3
  unsigned int v25; // [sp+28h] [bp-8h]@3
  unsigned int v26; // [sp+2Ch] [bp-4h]@3

  v1 = i_args->cSrcArgs.pDstBuf;
  v22 = i_args->cSrcArgs.pDstBuf;
  v20 = i_args->cDstArgs.pDstBuf;
  if ( i_args->i8AlphaModifier )
  {
    v2 = i_args->i8AlphaModifier + 1;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v24 = i_args->nWidth;
      v25 = i_args->cSrcArgs.iStride;
      v26 = i_args->cDstArgs.iStride;
      v23 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[3 * v3];
          v5 = (int)&v20[3 * v3 + 2];
          BYTE3(v19) = -1;
          v6 = v1 - v20;
          v21 = v3;
          do
          {
            v7 = *(_BYTE *)(v4 - 3);
            v8 = *(_BYTE *)(v6 + v5 - 4);
            v4 -= 3;
            v5 -= 3;
            LOBYTE(v19) = v7;
            BYTE1(v19) = v8;
            BYTE2(v19) = *(_BYTE *)(v6 + v5);
            v9 = 255;
            if ( v2 == 256 || (v9 = 255 * v2 / 256) != 0 )
            {
              v10 = v9 + 1;
              if ( v10 == 256 )
              {
                v11 = v19;
              }
              else
              {
                LOBYTE(v12) = *(_BYTE *)(v5 - 2);
                BYTE1(v12) = *(_BYTE *)(v5 - 1);
                BYTE2(v12) = *(_BYTE *)v5;
                v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v12) = -1;
                v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                v15 = _mm_cvtsi32_si64(v10);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _m_punpcklwd(v16, v16);
                v11 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
              }
              *(_BYTE *)(v5 - 2) = v11;
              *(_BYTE *)(v5 - 1) = BYTE1(v11);
              *(_BYTE *)v5 = v11 >> 16;
            }
            --v21;
          }
          while ( v21 );
          v3 = v24;
          v1 = v22;
        }
        v1 += v25;
        v18 = v23 == 1;
        v22 = v1;
        v20 += v26;
        --v23;
      }
      while ( !v18 );
    }
    _m_femms();
  }
}

//----- (0066D310) --------------------------------------------------------  // acclient.c:644044
void __usercall ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_1__BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  __m128 v1; // xmm2@2
  __m128 v2; // xmm3@2
  unsigned int v3; // esi@2
  unsigned int v4; // edi@2
  unsigned int v5; // eax@3
  int v6; // ebx@4
  int v7; // edi@5
  signed int v8; // ecx@5
  int v9; // edi@6
  unsigned int v10; // esi@6
  unsigned int v11; // esi@9
  unsigned int v12; // ebx@10
  __m64 v13; // mm2@12
  __m64 v14; // mm0@12
  __m64 v15; // mm3@12
  __m64 v16; // mm4@12
  __m64 v17; // mm3@12
  __m128 v18; // xmm0@13
  int v19; // ecx@13
  __m128 v20; // xmm0@13
  int v21; // ST0C_4@13
  int v22; // ebx@19
  unsigned int v23; // ecx@19
  int v24; // edi@20
  int v25; // edi@20
  unsigned int v26; // esi@20
  unsigned int v27; // esi@23
  unsigned int v28; // ebx@24
  __m64 v29; // mm2@26
  __m64 v30; // mm0@26
  __m64 v31; // mm3@26
  __m64 v32; // mm4@26
  __m64 v33; // mm3@26
  __m128 v34; // xmm4@27
  __m128 v35; // xmm6@27
  int v36; // ecx@27
  __m128 v37; // xmm7@27
  __m128 v38; // xmm4@27
  int v39; // ST0C_4@27
  bool v40; // zf@32
  char *v41; // [sp+10h] [bp-50h]@1
  char *v42; // [sp+14h] [bp-4Ch]@1
  int v43; // [sp+18h] [bp-48h]@5
  int v44; // [sp+18h] [bp-48h]@19
  signed int v45; // [sp+1Ch] [bp-44h]@5
  int v46; // [sp+20h] [bp-40h]@1
  unsigned int v47; // [sp+24h] [bp-3Ch]@2
  unsigned int v48; // [sp+28h] [bp-38h]@2
  unsigned int v49; // [sp+2Ch] [bp-34h]@2
  int v50; // [sp+30h] [bp-30h]@5
  unsigned int v51; // [sp+30h] [bp-30h]@20
  int v52; // [sp+34h] [bp-2Ch]@5
  int v53; // [sp+34h] [bp-2Ch]@19
  unsigned int v54; // [sp+38h] [bp-28h]@2
  unsigned int v55; // [sp+3Ch] [bp-24h]@2
  __m128 v56; // [sp+40h] [bp-20h]@0
  __m128 v57; // [sp+50h] [bp-10h]@0

  v41 = i_args->cSrcArgs.pDstBuf;
  v42 = i_args->cDstArgs.pDstBuf;
  v46 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v1 = v57;
    v2 = v57;
    v3 = i_args->nWidth >> 2;
    v4 = i_args->nWidth & 3;
    v48 = i_args->nWidth >> 2;
    v47 = i_args->nWidth & 3;
    v54 = i_args->cSrcArgs.iStride;
    v55 = i_args->cDstArgs.iStride;
    v49 = i_args->nHeight;
    do
    {
      v5 = v3;
      if ( v3 )
      {
        v6 = (int)&v42[16 * v3];
        do
        {
          v7 = *(_DWORD *)&v41[4 * v5 - 4];
          v6 -= 16;
          v8 = 3;
          v52 = v5 - 1;
          v50 = v6;
          v43 = *(_DWORD *)&v41[4 * v5 - 4];
          v45 = 3;
          do
          {
            v9 = g_SourceColor.u | v7 & 0xFF000000;
            v10 = (unsigned int)v9 >> 24;
            if ( v46 != 256 )
              v10 = (signed int)(v46 * v10) / 256;
            if ( v10 )
            {
              v11 = v10 + 1;
              if ( v11 != 256 )
              {
                v12 = *(_DWORD *)(v6 + 4 * v8);
                if ( BYTE3(v12) )
                {
                  if ( BYTE3(v12) == -1 )
                  {
                    v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                    v15 = _mm_cvtsi32_si64(v11);
                    v16 = _m_punpcklwd(v15, v15);
                    v17 = _m_punpcklwd(v16, v16);
                    v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
                  }
                  else
                  {
                    v18 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64), 0i64));
                    v1.m128_f32[0] = (float)(signed int)v11;
                    v19 = v11 - (signed int)(v11 * (BYTE3(v12) + 1)) / 256 + BYTE3(v12) + 1;
                    v2.m128_f32[0] = (float)v19;
                    v1 = _mm_shuffle_ps(v1, v1, 0);
                    v2 = _mm_shuffle_ps(v2, v2, 0);
                    v20 = _mm_sub_ps(
                            v18,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v18,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), 0i64))),
                                v1),
                              v2));
                    v21 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v20), _mm_cvt_ps2pi(_mm_movehl_ps(v20, v20))), 0i64));
                    BYTE3(v21) = v19 - 1;
                    v9 = v21;
                    v8 = v45;
                  }
                }
              }
              v6 = v50;
              *(_DWORD *)(v50 + 4 * v8) = v9;
            }
            v7 = v43 << 8;
            --v8;
            v43 <<= 8;
            v45 = v8;
          }
          while ( v8 >= 0 );
          --v5;
        }
        while ( v52 );
        v4 = v47;
        v3 = v48;
      }
      if ( v4 )
      {
        v22 = (int)&v42[16 * v3];
        v53 = (int)&v41[4 * v3];
        v44 = (int)&v42[16 * v3];
        v23 = v4;
        if ( v4 )
        {
          do
          {
            v24 = *(_BYTE *)(v23-- + v53 - 1);
            v25 = g_SourceColor.u | (v24 << 24);
            v26 = (unsigned int)v25 >> 24;
            v51 = v23;
            if ( v46 != 256 )
              v26 = (signed int)(v46 * v26) / 256;
            if ( v26 )
            {
              v27 = v26 + 1;
              if ( v27 != 256 )
              {
                v28 = *(_DWORD *)(v22 + 4 * v23);
                if ( BYTE3(v28) )
                {
                  if ( BYTE3(v28) == -1 )
                  {
                    v29 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v30 = _m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64);
                    v31 = _mm_cvtsi32_si64(v27);
                    v32 = _m_punpcklwd(v31, v31);
                    v33 = _m_punpcklwd(v32, v32);
                    v25 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v30, _m_psubw(_m_psrlw(_m_pmullw(v30, v33), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v25), 0i64), v29), _m_pandn(v29, v30)), v33), 8u))), 0i64));
                  }
                  else
                  {
                    v34 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64), 0i64));
                    v35 = v56;
                    v35.m128_f32[0] = (float)(signed int)v27;
                    v36 = v27 - (signed int)(v27 * (BYTE3(v28) + 1)) / 256 + BYTE3(v28) + 1;
                    v56 = _mm_shuffle_ps(v35, v35, 0);
                    v37 = v57;
                    v37.m128_f32[0] = (float)v36;
                    v57 = _mm_shuffle_ps(v37, v37, 0);
                    v38 = _mm_sub_ps(
                            v34,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v34,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v25), 0i64), 0i64))),
                                v56),
                              v57));
                    v39 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v38), _mm_cvt_ps2pi(_mm_movehl_ps(v38, v38))), 0i64));
                    BYTE3(v39) = v36 - 1;
                    v25 = v39;
                    v23 = v51;
                  }
                }
                v22 = v44;
              }
              *(_DWORD *)(v22 + 4 * v23) = v25;
            }
          }
          while ( v23 );
          v4 = v47;
          v3 = v48;
        }
      }
      v41 += v54;
      v40 = v49 == 1;
      v42 += v55;
      --v49;
    }
    while ( !v40 );
  }
  _m_femms();
}

//----- (0066D780) --------------------------------------------------------  // acclient.c:644274
void __usercall ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_0__BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  unsigned int v1; // esi@2
  unsigned int v2; // ebx@2
  unsigned int v3; // eax@3
  int v4; // edx@4
  int v5; // edi@5
  int v6; // ebx@6
  unsigned int v7; // esi@6
  unsigned int v8; // esi@9
  __m64 v9; // mm2@12
  __m64 v10; // mm0@12
  __m64 v11; // mm3@12
  __m64 v12; // mm4@12
  __m64 v13; // mm3@12
  signed int v14; // ecx@13
  int v15; // ecx@19
  unsigned int v16; // edi@19
  int v17; // ebx@20
  int v18; // ebx@20
  unsigned int v19; // esi@20
  unsigned int v20; // esi@23
  __m64 v21; // mm2@26
  __m64 v22; // mm0@26
  __m64 v23; // mm3@26
  __m64 v24; // mm4@26
  __m64 v25; // mm3@26
  signed int v26; // ecx@27
  int v27; // eax@27
  bool v28; // zf@31
  int v29; // [sp+10h] [bp-40h]@10
  int v30; // [sp+10h] [bp-40h]@24
  signed int v31; // [sp+18h] [bp-38h]@5
  char *v32; // [sp+1Ch] [bp-34h]@1
  char *v33; // [sp+20h] [bp-30h]@1
  int v34; // [sp+24h] [bp-2Ch]@19
  int v35; // [sp+28h] [bp-28h]@5
  int v36; // [sp+2Ch] [bp-24h]@1
  unsigned int v37; // [sp+30h] [bp-20h]@2
  unsigned int v38; // [sp+34h] [bp-1Ch]@2
  unsigned int v39; // [sp+38h] [bp-18h]@2
  int v40; // [sp+44h] [bp-Ch]@5
  int v41; // [sp+44h] [bp-Ch]@19
  unsigned int v42; // [sp+48h] [bp-8h]@2
  unsigned int v43; // [sp+4Ch] [bp-4h]@2

  v32 = i_args->cSrcArgs.pDstBuf;
  v33 = i_args->cDstArgs.pDstBuf;
  v36 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v1 = i_args->nWidth >> 2;
    v2 = i_args->nWidth & 3;
    v38 = i_args->nWidth >> 2;
    v37 = i_args->nWidth & 3;
    v42 = i_args->cSrcArgs.iStride;
    v43 = i_args->cDstArgs.iStride;
    v39 = i_args->nHeight;
    do
    {
      v3 = v1;
      if ( v1 )
      {
        v4 = (int)&v33[16 * v1];
        do
        {
          v5 = *(_DWORD *)&v32[4 * v3 - 4];
          v4 -= 16;
          v40 = v3 - 1;
          v35 = v4;
          v31 = 3;
          do
          {
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v7 = (g_SourceColor.u | v5 & 0xFF000000) >> 24;
            if ( v36 != 256 )
            {
              v4 = v35;
              v7 = (signed int)(v36 * v7) / 256;
            }
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 != 256 )
              {
                v29 = *(_DWORD *)(v4 + 4 * v31);
                if ( BYTE3(v29) )
                {
                  if ( BYTE3(v29) == -1 )
                  {
                    v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v10 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)(v4 + 4 * v31)), 0i64);
                    v11 = _mm_cvtsi32_si64(v8);
                    v12 = _m_punpcklwd(v11, v11);
                    v13 = _m_punpcklwd(v12, v12);
                    v6 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
                  }
                  else
                  {
                    v14 = v8 - (signed int)(v8 * (BYTE3(v29) + 1)) / 256 + BYTE3(v29) + 1;
                    BYTE2(v29) -= (signed int)(v8
                                             * (BYTE2(v29) - (unsigned __int8)((g_SourceColor.u | v5 & 0xFF000000) >> 16)))
                                / v14;
                    BYTE1(v29) -= (signed int)(v8 * (BYTE1(v29) - BYTE1(v6))) / v14;
                    v4 = v35;
                    LOBYTE(v29) = v29
                                - (unsigned int)((signed int)(v8 * ((unsigned __int8)v29 - (unsigned __int8)v6)) / v14);
                    BYTE3(v29) = v14 - 1;
                    v6 = v29;
                  }
                }
              }
              *(_DWORD *)(v4 + 4 * v31) = v6;
            }
            v5 <<= 8;
            --v31;
          }
          while ( v31 >= 0 );
          --v3;
        }
        while ( v40 );
        v2 = v37;
        v1 = v38;
      }
      if ( v2 )
      {
        v41 = (int)&v32[4 * v1];
        v15 = (int)&v33[16 * v1];
        v34 = (int)&v33[16 * v1];
        v16 = v2;
        if ( v2 )
        {
          do
          {
            v17 = *(_BYTE *)(v16-- + v41 - 1);
            v18 = g_SourceColor.u | (v17 << 24);
            v19 = (unsigned int)v18 >> 24;
            if ( v36 != 256 )
              v19 = (signed int)(v36 * v19) / 256;
            if ( v19 )
            {
              v20 = v19 + 1;
              if ( v20 != 256 )
              {
                v30 = *(_DWORD *)(v15 + 4 * v16);
                if ( BYTE3(v30) )
                {
                  if ( BYTE3(v30) == -1 )
                  {
                    v21 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v22 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)(v15 + 4 * v16)), 0i64);
                    v23 = _mm_cvtsi32_si64(v20);
                    v24 = _m_punpcklwd(v23, v23);
                    v25 = _m_punpcklwd(v24, v24);
                    v18 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v22, _m_psubw(_m_psrlw(_m_pmullw(v22, v25), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64), v21), _m_pandn(v21, v22)), v25), 8u))), 0i64));
                  }
                  else
                  {
                    v26 = v20 - (signed int)(v20 * (BYTE3(v30) + 1)) / 256 + BYTE3(v30) + 1;
                    BYTE2(v30) -= (signed int)(v20 * (BYTE2(v30) - BYTE2(v18))) / v26;
                    BYTE1(v30) -= (signed int)(v20 * (BYTE1(v30) - BYTE1(v18))) / v26;
                    v27 = (signed int)(v20 * ((unsigned __int8)v30 - (unsigned __int8)v18)) / v26;
                    BYTE3(v30) = v26 - 1;
                    v15 = v34;
                    LOBYTE(v30) = v30 - v27;
                    v18 = v30;
                  }
                }
              }
              *(_DWORD *)(v15 + 4 * v16) = v18;
            }
          }
          while ( v16 );
          v2 = v37;
          v1 = v38;
        }
      }
      v28 = v39 == 1;
      v32 += v42;
      v33 += v43;
      --v39;
    }
    while ( !v28 );
  }
  _m_femms();
}

//----- (0066DB60) --------------------------------------------------------  // acclient.c:644462
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_1__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edi@2
  int v2; // ecx@2
  __m128 v3; // xmm2@3
  __m128 v4; // xmm3@3
  unsigned int v5; // ebx@4
  int v6; // esi@6
  unsigned int v7; // esi@9
  unsigned int v8; // eax@10
  unsigned int v9; // edi@11
  __m64 v10; // mm2@14
  __m64 v11; // mm0@14
  __m64 v12; // mm3@14
  __m64 v13; // mm4@14
  __m64 v14; // mm3@14
  __m128 v15; // xmm0@15
  int v16; // ecx@15
  __m128 v17; // xmm0@15
  int v18; // ST14_4@15
  bool v19; // zf@18
  char *v20; // edx@20
  __m128 v21; // xmm2@21
  __m128 v22; // xmm3@21
  unsigned int v23; // ebx@22
  unsigned int v24; // esi@25
  int v25; // eax@26
  unsigned int v26; // edi@27
  __m64 v27; // mm2@30
  __m64 v28; // mm0@30
  __m64 v29; // mm3@30
  __m64 v30; // mm4@30
  __m64 v31; // mm3@30
  __m128 v32; // xmm0@31
  int v33; // ecx@31
  __m128 v34; // xmm0@31
  int v35; // ST18_4@31
  unsigned int v36; // [sp+14h] [bp-2Ch]@20
  char *v37; // [sp+18h] [bp-28h]@2
  int v38; // [sp+18h] [bp-28h]@27
  unsigned int v39; // [sp+1Ch] [bp-24h]@3
  unsigned int v40; // [sp+1Ch] [bp-24h]@21
  unsigned int v41; // [sp+20h] [bp-20h]@3
  unsigned int v42; // [sp+20h] [bp-20h]@21
  unsigned int v43; // [sp+24h] [bp-1Ch]@3
  char *v44; // [sp+24h] [bp-1Ch]@20
  int v45; // [sp+28h] [bp-18h]@5
  unsigned int v46; // [sp+28h] [bp-18h]@21
  int v47; // [sp+2Ch] [bp-14h]@2
  unsigned int v48; // [sp+2Ch] [bp-14h]@23
  __m128 v49; // [sp+30h] [bp-10h]@0

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v37 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    v47 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = v49;
      v4 = v49;
      v39 = i_args->nWidth;
      v41 = i_args->cDstArgs.iStride;
      v43 = i_args->nHeight;
      do
      {
        v5 = v39;
        if ( v39 )
        {
          v45 = BYTE3(g_SourceColor.u);
          do
          {
            v6 = v45;
            --v5;
            if ( v2 != 256 )
              v6 = v2 * v45 / 256;
            if ( v6 )
            {
              v7 = v6 + 1;
              if ( v7 == 256 )
              {
                v8 = g_SourceColor.u;
              }
              else
              {
                v9 = *(_DWORD *)&v1[4 * v5];
                if ( BYTE3(v9) )
                {
                  if ( BYTE3(v9) == -1 )
                  {
                    v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v11 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                    v12 = _mm_cvtsi32_si64(v7);
                    v13 = _m_punpcklwd(v12, v12);
                    v14 = _m_punpcklwd(v13, v13);
                    v8 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
                  }
                  else
                  {
                    v15 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), 0i64));
                    v3.m128_f32[0] = (float)(signed int)v7;
                    v16 = v7 - (signed int)(v7 * (BYTE3(v9) + 1)) / 256 + BYTE3(v9) + 1;
                    v4.m128_f32[0] = (float)v16;
                    v3 = _mm_shuffle_ps(v3, v3, 0);
                    v4 = _mm_shuffle_ps(v4, v4, 0);
                    v17 = _mm_sub_ps(
                            v15,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v15,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64), 0i64))),
                                v3),
                              v4));
                    v18 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v17), _mm_cvt_ps2pi(_mm_movehl_ps(v17, v17))), 0i64));
                    BYTE3(v18) = v16 - 1;
                    v8 = v18;
                    v2 = v47;
                  }
                }
                else
                {
                  v8 = g_SourceColor.u;
                }
              }
              v1 = v37;
              *(_DWORD *)&v37[4 * v5] = v8;
            }
          }
          while ( v5 );
        }
        v1 += v41;
        v19 = v43 == 1;
        v37 = v1;
        --v43;
      }
      while ( !v19 );
    }
  }
  else
  {
    v20 = i_args->cDstArgs.pDstBuf;
    v36 = g_SourceColor.u;
    BYTE3(v36) = i_args->i8AlphaModifier;
    v44 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v21 = v49;
      v22 = v49;
      v40 = i_args->nWidth;
      v42 = i_args->cDstArgs.iStride;
      v46 = i_args->nHeight;
      do
      {
        v23 = v40;
        if ( v40 )
        {
          v48 = v36 >> 24;
          do
          {
            --v23;
            if ( v48 )
            {
              v24 = v48 + 1;
              if ( v48 == 255 )
              {
                v25 = v36;
              }
              else
              {
                v26 = *(_DWORD *)&v20[4 * v23];
                v38 = *(_DWORD *)&v20[4 * v23];
                if ( BYTE3(v38) )
                {
                  if ( BYTE3(v38) == -1 )
                  {
                    v27 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v28 = _m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64);
                    v29 = _mm_cvtsi32_si64(v24);
                    v30 = _m_punpcklwd(v29, v29);
                    v31 = _m_punpcklwd(v30, v30);
                    v25 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v28, _m_psubw(_m_psrlw(_m_pmullw(v28, v31), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v36), 0i64), v27), _m_pandn(v27, v28)), v31), 8u))), 0i64));
                  }
                  else
                  {
                    v32 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), 0i64));
                    v21.m128_f32[0] = (float)(signed int)v24;
                    v33 = v24 - (signed int)(v24 * (BYTE3(v38) + 1)) / 256 + BYTE3(v38) + 1;
                    v20 = v44;
                    v21 = _mm_shuffle_ps(v21, v21, 0);
                    v22.m128_f32[0] = (float)v33;
                    v22 = _mm_shuffle_ps(v22, v22, 0);
                    v34 = _mm_sub_ps(
                            v32,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v32,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v36), 0i64), 0i64))),
                                v21),
                              v22));
                    v35 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v34), _mm_cvt_ps2pi(_mm_movehl_ps(v34, v34))), 0i64));
                    BYTE3(v35) = v33 - 1;
                    v25 = v35;
                  }
                }
                else
                {
                  v25 = v36;
                }
              }
              *(_DWORD *)&v20[4 * v23] = v25;
            }
          }
          while ( v23 );
        }
        v20 -= v42;
        v19 = v46 == 1;
        v44 = v20;
        --v46;
      }
      while ( !v19 );
    }
  }
  _m_femms();
}

//----- (0066DF70) --------------------------------------------------------  // acclient.c:644691
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_0__BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  int v1; // ebx@2
  unsigned int v2; // edi@4
  int v3; // esi@5
  unsigned int v4; // esi@8
  unsigned int v5; // eax@9
  __m64 v6; // mm2@13
  __m64 v7; // mm0@13
  __m64 v8; // mm3@13
  __m64 v9; // mm4@13
  __m64 v10; // mm3@13
  signed int v11; // ecx@14
  bool v12; // zf@17
  char *v13; // edx@19
  unsigned int v14; // edi@21
  unsigned int v15; // esi@24
  int v16; // eax@25
  __m64 v17; // mm2@29
  __m64 v18; // mm0@29
  __m64 v19; // mm3@29
  __m64 v20; // mm4@29
  __m64 v21; // mm3@29
  signed int v22; // ecx@30
  unsigned int v23; // [sp+Ch] [bp-24h]@10
  int v24; // [sp+Ch] [bp-24h]@26
  char *v25; // [sp+10h] [bp-20h]@2
  unsigned int v26; // [sp+10h] [bp-20h]@19
  unsigned int v27; // [sp+14h] [bp-1Ch]@3
  unsigned int v28; // [sp+14h] [bp-1Ch]@20
  unsigned int v29; // [sp+18h] [bp-18h]@3
  unsigned int v30; // [sp+18h] [bp-18h]@20
  unsigned int v31; // [sp+1Ch] [bp-14h]@3
  char *v32; // [sp+1Ch] [bp-14h]@19
  unsigned int v33; // [sp+20h] [bp-10h]@20
  int v34; // [sp+28h] [bp-8h]@2
  unsigned int v35; // [sp+28h] [bp-8h]@22

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v25 = i_args->cDstArgs.pDstBuf;
    v1 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    v34 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v27 = i_args->nWidth;
      v29 = i_args->cDstArgs.iStride;
      v31 = i_args->nHeight;
      do
      {
        v2 = v27;
        while ( v2 )
        {
          v3 = BYTE3(g_SourceColor.u);
          --v2;
          if ( v1 != 256 )
            v3 = v1 * (unsigned __int8)g_SourceColor.a / 256;
          if ( v3 )
          {
            v4 = v3 + 1;
            if ( v4 == 256 )
            {
              v5 = g_SourceColor.u;
            }
            else
            {
              v23 = *(_DWORD *)&v25[4 * v2];
              if ( BYTE3(v23) )
              {
                if ( BYTE3(v23) == -1 )
                {
                  v6 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                  v7 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v25[4 * v2]), 0i64);
                  v8 = _mm_cvtsi32_si64(v4);
                  v9 = _m_punpcklwd(v8, v8);
                  v10 = _m_punpcklwd(v9, v9);
                  v5 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v7, _m_psubw(_m_psrlw(_m_pmullw(v7, v10), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64), v6), _m_pandn(v6, v7)), v10), 8u))), 0i64));
                }
                else
                {
                  v11 = v4 - (signed int)(v4 * (BYTE3(v23) + 1)) / 256 + BYTE3(v23) + 1;
                  BYTE2(v23) -= (signed int)(v4 * (BYTE2(v23) - (unsigned __int8)g_SourceColor.r)) / v11;
                  BYTE1(v23) -= (signed int)(v4 * (BYTE1(v23) - (unsigned __int8)g_SourceColor.g)) / v11;
                  LOBYTE(v23) = v23
                              - (unsigned int)((signed int)(v4
                                                          * ((unsigned __int8)v23 - (unsigned __int8)g_SourceColor.b))
                                             / v11);
                  v1 = v34;
                  BYTE3(v23) = v11 - 1;
                  v5 = v23;
                }
              }
              else
              {
                v5 = g_SourceColor.u;
              }
            }
            *(_DWORD *)&v25[4 * v2] = v5;
          }
        }
        v12 = v31 == 1;
        v25 += v29;
        --v31;
      }
      while ( !v12 );
    }
  }
  else
  {
    v13 = i_args->cDstArgs.pDstBuf;
    v26 = g_SourceColor.u;
    BYTE3(v26) = i_args->i8AlphaModifier;
    v32 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v28 = i_args->nWidth;
      v30 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        v14 = v28;
        if ( v28 )
        {
          v35 = v26 >> 24;
          do
          {
            --v14;
            if ( v35 )
            {
              v15 = v35 + 1;
              if ( v35 == 255 )
              {
                v16 = v26;
              }
              else
              {
                v24 = *(_DWORD *)&v13[4 * v14];
                if ( BYTE3(v24) )
                {
                  if ( BYTE3(v24) == -1 )
                  {
                    v17 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v18 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v13[4 * v14]), 0i64);
                    v19 = _mm_cvtsi32_si64(v15);
                    v20 = _m_punpcklwd(v19, v19);
                    v21 = _m_punpcklwd(v20, v20);
                    v16 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v18, _m_psubw(_m_psrlw(_m_pmullw(v18, v21), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), v17), _m_pandn(v17, v18)), v21), 8u))), 0i64));
                  }
                  else
                  {
                    v22 = v15 - (signed int)(v15 * (BYTE3(v24) + 1)) / 256 + BYTE3(v24) + 1;
                    BYTE2(v24) -= (signed int)(v15 * (BYTE2(v24) - BYTE2(v26))) / v22;
                    BYTE1(v24) -= (signed int)(v15 * (BYTE1(v24) - BYTE1(v26))) / v22;
                    v13 = v32;
                    LOBYTE(v24) = v24
                                - (unsigned int)((signed int)(v15 * ((unsigned __int8)v24 - (unsigned __int8)v26)) / v22);
                    BYTE3(v24) = v22 - 1;
                    v16 = v24;
                  }
                }
                else
                {
                  v16 = v26;
                }
              }
              *(_DWORD *)&v13[4 * v14] = v16;
            }
          }
          while ( v14 );
        }
        v13 -= v30;
        v12 = v33 == 1;
        v32 = v13;
        --v33;
      }
      while ( !v12 );
    }
  }
  _m_femms();
}

//----- (0066E300) --------------------------------------------------------  // acclient.c:644873
void __usercall ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_0__BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // ebx@1
  unsigned int v2; // edx@2
  unsigned int v3; // eax@3
  int v4; // edi@4
  int v5; // ebx@6
  signed int v6; // esi@6
  int v7; // ecx@7
  unsigned int v8; // eax@7
  unsigned int v9; // eax@10
  unsigned int v10; // ST18_4@11
  __m64 v11; // mm2@11
  __m64 v12; // mm0@11
  __m64 v13; // mm3@11
  __m64 v14; // mm4@11
  __m64 v15; // mm3@11
  unsigned int v16; // esi@16
  int v17; // edi@17
  int v18; // ecx@18
  int v19; // ecx@18
  unsigned int v20; // eax@18
  unsigned int v21; // eax@21
  unsigned int v22; // ST20_4@22
  __m64 v23; // mm2@22
  __m64 v24; // mm0@22
  __m64 v25; // mm3@22
  __m64 v26; // mm4@22
  __m64 v27; // mm3@22
  bool v28; // zf@25
  char *v29; // [sp+14h] [bp-2Ch]@1
  char *v30; // [sp+1Ch] [bp-24h]@1
  int v31; // [sp+20h] [bp-20h]@6
  int v32; // [sp+24h] [bp-1Ch]@1
  unsigned int v33; // [sp+28h] [bp-18h]@2
  unsigned int v34; // [sp+2Ch] [bp-14h]@2
  unsigned int v35; // [sp+30h] [bp-10h]@2
  int v36; // [sp+34h] [bp-Ch]@17
  unsigned int v37; // [sp+38h] [bp-8h]@2
  unsigned int v38; // [sp+3Ch] [bp-4h]@2

  v29 = i_args->cSrcArgs.pDstBuf;
  v1 = i_args->cDstArgs.pDstBuf;
  v30 = i_args->cDstArgs.pDstBuf;
  v32 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth >> 2;
    v35 = i_args->nWidth & 3;
    v33 = i_args->nWidth >> 2;
    v37 = i_args->cSrcArgs.iStride;
    v38 = i_args->cDstArgs.iStride;
    v34 = i_args->nHeight;
    do
    {
      v3 = v2;
      if ( v2 )
      {
        v4 = (int)&v1[16 * v2];
        while ( 1 )
        {
          v5 = *(_DWORD *)&v29[4 * v3 - 4];
          v31 = v3 - 1;
          v4 -= 16;
          v6 = 3;
          do
          {
            v7 = g_SourceColor.u | v5 & 0xFF000000;
            v8 = (g_SourceColor.u | v5 & 0xFF000000) >> 24;
            if ( v32 != 256 )
              v8 = (signed int)(v32 * v8) / 256;
            if ( v8 )
            {
              v9 = v8 + 1;
              if ( v9 != 256 )
              {
                v10 = *(_DWORD *)(v4 + 4 * v6);
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v10) = -1;
                v12 = _m_punpcklbw(_mm_cvtsi32_si64(v10), 0i64);
                v13 = _mm_cvtsi32_si64(v9);
                v14 = _m_punpcklwd(v13, v13);
                v15 = _m_punpcklwd(v14, v14);
                v7 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v12, _m_psubw(_m_psrlw(_m_pmullw(v12, v15), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v7), 0i64), v11), _m_pandn(v11, v12)), v15), 8u))), 0i64));
              }
              *(_DWORD *)(v4 + 4 * v6) = v7;
            }
            v5 <<= 8;
            --v6;
          }
          while ( v6 >= 0 );
          if ( !v31 )
            break;
          v3 = v31;
        }
        v2 = v33;
      }
      v16 = v35;
      if ( v35 )
      {
        v36 = (int)&v29[4 * v2];
        v17 = (int)&v30[16 * v2];
        if ( v35 )
        {
          do
          {
            v18 = *(_BYTE *)(v16-- + v36 - 1);
            v19 = g_SourceColor.u | (v18 << 24);
            v20 = (unsigned int)v19 >> 24;
            if ( v32 != 256 )
            {
              v2 = v33;
              v20 = (signed int)(v32 * v20) / 256;
            }
            if ( v20 )
            {
              v21 = v20 + 1;
              if ( v21 != 256 )
              {
                v22 = *(_DWORD *)(v17 + 4 * v16);
                v23 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v22) = -1;
                v24 = _m_punpcklbw(_mm_cvtsi32_si64(v22), 0i64);
                v25 = _mm_cvtsi32_si64(v21);
                v26 = _m_punpcklwd(v25, v25);
                v27 = _m_punpcklwd(v26, v26);
                v19 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v24, _m_psubw(_m_psrlw(_m_pmullw(v24, v27), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64), v23), _m_pandn(v23, v24)), v27), 8u))), 0i64));
              }
              *(_DWORD *)(v17 + 4 * v16) = v19;
            }
          }
          while ( v16 );
        }
      }
      v1 = &v30[v38];
      v28 = v34 == 1;
      v29 += v37;
      v30 += v38;
      --v34;
    }
    while ( !v28 );
  }
  _m_femms();
}

//----- (0066E570) --------------------------------------------------------  // acclient.c:645019
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_XRGB_0__BlitFormat_Fill_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@2
  int v2; // edi@2
  unsigned int v3; // ebx@3
  unsigned int v4; // ecx@4
  int v5; // eax@6
  unsigned int v6; // eax@9
  int v7; // eax@10
  unsigned int v8; // ST10_4@11
  __m64 v9; // mm2@11
  __m64 v10; // mm0@11
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  char *v14; // edx@16
  unsigned int v15; // ecx@18
  unsigned int v16; // edi@19
  int v17; // eax@22
  unsigned int v18; // ST18_4@23
  __m64 v19; // mm2@23
  __m64 v20; // mm0@23
  __m64 v21; // mm3@23
  __m64 v22; // mm4@23
  __m64 v23; // mm3@23
  unsigned int v24; // [sp+Ch] [bp-14h]@3
  unsigned int v25; // [sp+Ch] [bp-14h]@17
  unsigned int v26; // [sp+10h] [bp-10h]@16
  unsigned int v27; // [sp+14h] [bp-Ch]@3
  unsigned int v28; // [sp+14h] [bp-Ch]@17
  unsigned int v29; // [sp+18h] [bp-8h]@3
  int v30; // [sp+1Ch] [bp-4h]@5
  unsigned int v31; // [sp+1Ch] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = g_SourceColor.u;
      v24 = i_args->nWidth;
      v27 = i_args->cDstArgs.iStride;
      v29 = i_args->nHeight;
      do
      {
        v4 = v24;
        if ( v24 )
        {
          v30 = BYTE3(g_SourceColor.u);
          do
          {
            v5 = v30;
            --v4;
            if ( v2 != 256 )
              v5 = v2 * v30 / 256;
            if ( v5 )
            {
              v6 = v5 + 1;
              if ( v6 == 256 )
              {
                v7 = v3;
              }
              else
              {
                v8 = *(_DWORD *)&v1[4 * v4];
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v8) = -1;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v11 = _mm_cvtsi32_si64(v6);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v7 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v3), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
              }
              *(_DWORD *)&v1[4 * v4] = v7;
            }
          }
          while ( v4 );
        }
        v1 += v27;
        --v29;
      }
      while ( v29 );
    }
  }
  else
  {
    v14 = i_args->cDstArgs.pDstBuf;
    v26 = g_SourceColor.u;
    BYTE3(v26) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v25 = i_args->nWidth;
      v28 = i_args->cDstArgs.iStride;
      v31 = i_args->nHeight;
      do
      {
        v15 = v25;
        if ( v25 )
        {
          v16 = v26 >> 24;
          do
          {
            --v15;
            if ( v16 )
            {
              if ( v16 == 255 )
              {
                v17 = v26;
              }
              else
              {
                v18 = *(_DWORD *)&v14[4 * v15];
                v19 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v18) = -1;
                v20 = _m_punpcklbw(_mm_cvtsi32_si64(v18), 0i64);
                v21 = _mm_cvtsi32_si64(v16 + 1);
                v22 = _m_punpcklwd(v21, v21);
                v23 = _m_punpcklwd(v22, v22);
                v17 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v20, _m_psubw(_m_psrlw(_m_pmullw(v20, v23), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), v19), _m_pandn(v19, v20)), v23), 8u))), 0i64));
              }
              *(_DWORD *)&v14[4 * v15] = v17;
            }
          }
          while ( v15 );
        }
        v14 -= v28;
        --v31;
      }
      while ( v31 );
    }
  }
  _m_femms();
}

//----- (0066E790) --------------------------------------------------------  // acclient.c:645155
void __usercall ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_0__BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edi@1
  unsigned int v2; // ecx@2
  unsigned int v3; // esi@2
  int v4; // ecx@2
  int v5; // eax@3
  int v6; // esi@4
  int v7; // edi@6
  int v8; // esi@6
  signed int v9; // ebx@6
  unsigned int v10; // eax@7
  unsigned int v11; // eax@10
  unsigned int v12; // ST0C_4@12
  __m64 v13; // mm2@12
  __m64 v14; // mm0@12
  __m64 v15; // mm3@12
  __m64 v16; // mm4@12
  __m64 v17; // mm3@12
  int v18; // ebx@18
  int v19; // edi@18
  int v20; // esi@19
  int v21; // ecx@20
  unsigned int v22; // ecx@20
  unsigned int v23; // eax@20
  unsigned int v24; // eax@23
  unsigned int v25; // ST10_4@25
  __m64 v26; // mm2@25
  __m64 v27; // mm0@25
  __m64 v28; // mm3@25
  __m64 v29; // mm4@25
  __m64 v30; // mm3@25
  bool v31; // zf@29
  unsigned int v32; // [sp+Ch] [bp-34h]@11
  unsigned int v33; // [sp+10h] [bp-30h]@24
  char *v34; // [sp+14h] [bp-2Ch]@1
  char *v35; // [sp+1Ch] [bp-24h]@1
  int v36; // [sp+20h] [bp-20h]@6
  int v37; // [sp+24h] [bp-1Ch]@1
  unsigned int v38; // [sp+28h] [bp-18h]@2
  int v39; // [sp+2Ch] [bp-14h]@2
  unsigned int v40; // [sp+30h] [bp-10h]@2
  int v41; // [sp+34h] [bp-Ch]@6
  unsigned int v42; // [sp+38h] [bp-8h]@2
  unsigned int v43; // [sp+3Ch] [bp-4h]@2

  v34 = i_args->cSrcArgs.pDstBuf;
  v1 = i_args->cDstArgs.pDstBuf;
  v35 = i_args->cDstArgs.pDstBuf;
  v37 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
  if ( i_args->nHeight )
  {
    v2 = i_args->nWidth;
    v3 = v2 >> 2;
    v4 = v2 & 3;
    v38 = v3;
    v39 = v4;
    v42 = i_args->cSrcArgs.iStride;
    v43 = i_args->cDstArgs.iStride;
    v40 = i_args->nHeight;
    do
    {
      v5 = v3;
      if ( v3 )
      {
        v6 = (int)&v1[12 * v3 + 11];
        while ( 1 )
        {
          v7 = *(_DWORD *)&v34[4 * v5 - 4];
          v8 = v6 - 12;
          v36 = v5 - 1;
          v41 = v8;
          v9 = 4;
          do
          {
            v10 = (g_SourceColor.u | v7 & 0xFF000000) >> 24;
            if ( v37 != 256 )
              v10 = (signed int)(v37 * v10) / 256;
            if ( v10 )
            {
              v11 = v10 + 1;
              if ( v11 == 256 )
              {
                v32 = g_SourceColor.u | v7 & 0xFF000000;
              }
              else
              {
                LOBYTE(v12) = *(_BYTE *)(v8 - 2);
                BYTE1(v12) = *(_BYTE *)(v8 - 1);
                BYTE2(v12) = *(_BYTE *)v8;
                v13 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v12) = -1;
                v14 = _m_punpcklbw(_mm_cvtsi32_si64(v12), 0i64);
                v15 = _mm_cvtsi32_si64(v11);
                v16 = _m_punpcklwd(v15, v15);
                v17 = _m_punpcklwd(v16, v16);
                v32 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v14, _m_psubw(_m_psrlw(_m_pmullw(v14, v17), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u | v7 & 0xFF000000), 0i64), v13), _m_pandn(v13, v14)), v17), 8u))), 0i64));
              }
              *(_BYTE *)(v8 - 2) = v32;
              *(_BYTE *)(v8 - 1) = BYTE1(v32);
              *(_BYTE *)v8 = v32 >> 16;
            }
            v7 <<= 8;
            v8 -= 3;
            --v9;
          }
          while ( v9 );
          if ( !v36 )
            break;
          v6 = v41;
          v5 = v36;
        }
        v3 = v38;
        v4 = v39;
      }
      if ( v4 )
      {
        v18 = (int)&v34[4 * v3];
        v19 = v4;
        if ( v4 )
        {
          v20 = (int)(&v35[12 * v3 + 2] + 2 * v4 + v4);
          do
          {
            v21 = *(_BYTE *)(v19-- + v18 - 1);
            v22 = g_SourceColor.u | (v21 << 24);
            v20 -= 3;
            v23 = v22 >> 24;
            if ( v37 != 256 )
              v23 = (signed int)(v37 * v23) / 256;
            if ( v23 )
            {
              v24 = v23 + 1;
              if ( v24 == 256 )
              {
                v33 = v22;
              }
              else
              {
                LOBYTE(v25) = *(_BYTE *)(v20 - 2);
                BYTE1(v25) = *(_BYTE *)(v20 - 1);
                BYTE2(v25) = *(_BYTE *)v20;
                v26 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v25) = -1;
                v27 = _m_punpcklbw(_mm_cvtsi32_si64(v25), 0i64);
                v28 = _mm_cvtsi32_si64(v24);
                v29 = _m_punpcklwd(v28, v28);
                v30 = _m_punpcklwd(v29, v29);
                v33 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v27, _m_psubw(_m_psrlw(_m_pmullw(v27, v30), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v22), 0i64), v26), _m_pandn(v26, v27)), v30), 8u))), 0i64));
              }
              *(_BYTE *)(v20 - 2) = v33;
              *(_BYTE *)(v20 - 1) = BYTE1(v33);
              *(_BYTE *)v20 = v33 >> 16;
            }
          }
          while ( v19 );
          v3 = v38;
          v4 = v39;
        }
      }
      v34 += v42;
      v1 = &v35[v43];
      v31 = v40 == 1;
      v35 += v43;
      --v40;
    }
    while ( !v31 );
  }
  _m_femms();
}

//----- (0066EA90) --------------------------------------------------------  // acclient.c:645327
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_RGB_0__BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@2
  int v2; // esi@2
  unsigned int v3; // ebx@3
  int v4; // edi@5
  int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // eax@9
  unsigned int v8; // ST18_4@11
  __m64 v9; // mm2@11
  __m64 v10; // mm0@11
  __m64 v11; // mm3@11
  __m64 v12; // mm4@11
  __m64 v13; // mm3@11
  bool v14; // zf@14
  char *v15; // ebx@16
  unsigned int v16; // edi@17
  unsigned int v17; // esi@19
  int v18; // eax@19
  unsigned int v19; // ST18_4@23
  __m64 v20; // mm2@23
  __m64 v21; // mm0@23
  __m64 v22; // mm3@23
  __m64 v23; // mm4@23
  __m64 v24; // mm3@23
  unsigned int v25; // [sp+18h] [bp-18h]@10
  unsigned int v26; // [sp+18h] [bp-18h]@22
  unsigned int v27; // [sp+1Ch] [bp-14h]@5
  unsigned int v28; // [sp+1Ch] [bp-14h]@16
  unsigned int v29; // [sp+20h] [bp-10h]@3
  unsigned int v30; // [sp+20h] [bp-10h]@17
  char *v31; // [sp+24h] [bp-Ch]@2
  char *v32; // [sp+24h] [bp-Ch]@16
  unsigned int v33; // [sp+28h] [bp-8h]@3
  unsigned int v34; // [sp+28h] [bp-8h]@19
  unsigned int v35; // [sp+2Ch] [bp-4h]@17

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v31 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v29 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = BYTE3(g_SourceColor.u);
          v5 = (int)(&v1[2 * v3 + 2] + v3);
          v27 = v3;
          do
          {
            v5 -= 3;
            v6 = v4;
            if ( v2 != 256 )
              v6 = v2 * v4 / 256;
            if ( v6 )
            {
              v7 = v6 + 1;
              if ( v7 == 256 )
              {
                v25 = g_SourceColor.u;
              }
              else
              {
                LOBYTE(v8) = *(_BYTE *)(v5 - 2);
                BYTE1(v8) = *(_BYTE *)(v5 - 1);
                BYTE2(v8) = *(_BYTE *)v5;
                v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v8) = -1;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(v8), 0i64);
                v11 = _mm_cvtsi32_si64(v7);
                v12 = _m_punpcklwd(v11, v11);
                v13 = _m_punpcklwd(v12, v12);
                v25 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(g_SourceColor.u), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
              }
              *(_BYTE *)(v5 - 2) = v25;
              *(_BYTE *)(v5 - 1) = BYTE1(v25);
              *(_BYTE *)v5 = v25 >> 16;
            }
            --v27;
          }
          while ( v27 );
        }
        v1 = &v31[v29];
        v14 = v33 == 1;
        v31 += v29;
        --v33;
      }
      while ( !v14 );
    }
  }
  else
  {
    v15 = i_args->cDstArgs.pDstBuf;
    v28 = g_SourceColor.u;
    v32 = i_args->cDstArgs.pDstBuf;
    BYTE3(v28) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v16 = i_args->nWidth;
      v30 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        if ( v16 )
        {
          v17 = v28 >> 24;
          v18 = (int)(&v15[2 * v16 + 2] + v16);
          v34 = v16;
          do
          {
            v18 -= 3;
            if ( v17 )
            {
              if ( v17 == 255 )
              {
                v26 = v28;
              }
              else
              {
                LOBYTE(v19) = *(_BYTE *)(v18 - 2);
                BYTE1(v19) = *(_BYTE *)(v18 - 1);
                BYTE2(v19) = *(_BYTE *)v18;
                v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v19) = -1;
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
                v22 = _mm_cvtsi32_si64(v17 + 1);
                v23 = _m_punpcklwd(v22, v22);
                v24 = _m_punpcklwd(v23, v23);
                v26 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v24), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v28), 0i64), v20), _m_pandn(v20, v21)), v24), 8u))), 0i64));
              }
              *(_BYTE *)(v18 - 2) = v26;
              *(_BYTE *)(v18 - 1) = BYTE1(v26);
              *(_BYTE *)v18 = v26 >> 16;
            }
            --v34;
          }
          while ( v34 );
        }
        v15 = &v32[-v30];
        v14 = v35 == 1;
        v32 -= v30;
        --v35;
      }
      while ( !v14 );
    }
  }
  _m_femms();
}

//----- (0066ED30) --------------------------------------------------------  // acclient.c:645484
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_1__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@2
  int v2; // edx@2
  unsigned int v3; // edi@3
  __m128 v4; // xmm2@3
  __m128 v5; // xmm3@3
  int v6; // ebx@5
  int v7; // ecx@5
  int v8; // esi@6
  int v9; // esi@6
  unsigned int v10; // edi@6
  signed int v11; // kr00_4@7
  unsigned int v12; // edi@9
  unsigned int v13; // ebx@10
  __m64 v14; // mm2@12
  __m64 v15; // mm0@12
  __m64 v16; // mm3@12
  __m64 v17; // mm4@12
  __m64 v18; // mm3@12
  __m128 v19; // xmm0@13
  int v20; // ecx@13
  __m128 v21; // xmm0@13
  int v22; // ST14_4@13
  bool v23; // zf@17
  char *v24; // edx@19
  __m128 v25; // xmm2@20
  __m128 v26; // xmm3@20
  unsigned int v27; // ebx@21
  unsigned int v28; // esi@24
  int v29; // eax@25
  unsigned int v30; // edi@26
  __m64 v31; // mm2@29
  __m64 v32; // mm0@29
  __m64 v33; // mm3@29
  __m64 v34; // mm4@29
  __m64 v35; // mm3@29
  __m128 v36; // xmm0@30
  int v37; // ecx@30
  __m128 v38; // xmm0@30
  int v39; // ST18_4@30
  unsigned int v40; // [sp+14h] [bp-3Ch]@10
  unsigned int v41; // [sp+14h] [bp-3Ch]@19
  char *v42; // [sp+18h] [bp-38h]@2
  int v43; // [sp+18h] [bp-38h]@26
  unsigned int v44; // [sp+1Ch] [bp-34h]@3
  unsigned int v45; // [sp+1Ch] [bp-34h]@20
  int v46; // [sp+20h] [bp-30h]@2
  unsigned int v47; // [sp+24h] [bp-2Ch]@5
  char *v48; // [sp+28h] [bp-28h]@2
  unsigned int v49; // [sp+28h] [bp-28h]@20
  unsigned int v50; // [sp+2Ch] [bp-24h]@3
  char *v51; // [sp+2Ch] [bp-24h]@19
  int v52; // [sp+30h] [bp-20h]@6
  int v53; // [sp+34h] [bp-1Ch]@5
  unsigned int v54; // [sp+38h] [bp-18h]@3
  unsigned int v55; // [sp+38h] [bp-18h]@22
  unsigned int v56; // [sp+3Ch] [bp-14h]@3
  unsigned int v57; // [sp+3Ch] [bp-14h]@20
  __m128 v58; // [sp+40h] [bp-10h]@0

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v42 = i_args->cSrcArgs.pDstBuf;
    v48 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    v46 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v4 = v58;
      v5 = v58;
      v54 = i_args->nWidth;
      v56 = i_args->cSrcArgs.iStride;
      v44 = i_args->cDstArgs.iStride;
      v50 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v6 = v42 - v1;
          v7 = (int)&v1[4 * v3];
          v53 = v42 - v1;
          v47 = v3;
          do
          {
            v8 = *(_DWORD *)(v7 + v6 - 4);
            v7 -= 4;
            v9 = g_SourceColor.u | v8 & 0xFF000000;
            v10 = (unsigned int)v9 >> 24;
            v52 = v7;
            if ( v2 != 256 )
            {
              v11 = v2 * v10;
              v2 = v46;
              v10 = v11 / 256;
            }
            if ( v10 )
            {
              v12 = v10 + 1;
              if ( v12 != 256 )
              {
                v13 = *(_DWORD *)v7;
                v40 = *(_DWORD *)v7;
                if ( *(_DWORD *)v7 >> 24 )
                {
                  if ( BYTE3(v40) == -1 )
                  {
                    v14 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v15 = _m_punpcklbw(_mm_cvtsi32_si64(v13), 0i64);
                    v16 = _mm_cvtsi32_si64(v12);
                    v17 = _m_punpcklwd(v16, v16);
                    v18 = _m_punpcklwd(v17, v17);
                    v9 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v15, _m_psubw(_m_psrlw(_m_pmullw(v15, v18), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), v14), _m_pandn(v14, v15)), v18), 8u))), 0i64));
                  }
                  else
                  {
                    v19 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v13), 0i64), 0i64));
                    v4.m128_f32[0] = (float)(signed int)v12;
                    v20 = v12 - (signed int)(v12 * (BYTE3(v40) + 1)) / 256 + BYTE3(v40) + 1;
                    v5.m128_f32[0] = (float)v20;
                    v4 = _mm_shuffle_ps(v4, v4, 0);
                    v5 = _mm_shuffle_ps(v5, v5, 0);
                    v21 = _mm_sub_ps(
                            v19,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v19,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64), 0i64))),
                                v4),
                              v5));
                    v22 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v21), _mm_cvt_ps2pi(_mm_movehl_ps(v21, v21))), 0i64));
                    BYTE3(v22) = v20 - 1;
                    v9 = v22;
                    v7 = v52;
                  }
                }
              }
              v6 = v53;
              v2 = v46;
              *(_DWORD *)v7 = v9;
            }
            --v47;
          }
          while ( v47 );
          v1 = v48;
          v3 = v54;
        }
        v1 += v44;
        v23 = v50 == 1;
        v42 += v56;
        v48 = v1;
        --v50;
      }
      while ( !v23 );
    }
  }
  else
  {
    v24 = i_args->cDstArgs.pDstBuf;
    v41 = g_SourceColor.u;
    BYTE3(v41) = i_args->i8AlphaModifier;
    v51 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v25 = v58;
      v26 = v58;
      v57 = i_args->nWidth;
      v45 = i_args->cDstArgs.iStride;
      v49 = i_args->nHeight;
      do
      {
        v27 = v57;
        if ( v57 )
        {
          v55 = v41 >> 24;
          do
          {
            --v27;
            if ( v55 )
            {
              v28 = v55 + 1;
              if ( v55 == 255 )
              {
                v29 = v41;
              }
              else
              {
                v30 = *(_DWORD *)&v24[4 * v27];
                v43 = *(_DWORD *)&v24[4 * v27];
                if ( BYTE3(v43) )
                {
                  if ( BYTE3(v43) == -1 )
                  {
                    v31 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v32 = _m_punpcklbw(_mm_cvtsi32_si64(v30), 0i64);
                    v33 = _mm_cvtsi32_si64(v28);
                    v34 = _m_punpcklwd(v33, v33);
                    v35 = _m_punpcklwd(v34, v34);
                    v29 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v32, _m_psubw(_m_psrlw(_m_pmullw(v32, v35), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v41), 0i64), v31), _m_pandn(v31, v32)), v35), 8u))), 0i64));
                  }
                  else
                  {
                    v36 = _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v30), 0i64), 0i64));
                    v25.m128_f32[0] = (float)(signed int)v28;
                    v37 = v28 - (signed int)(v28 * (BYTE3(v43) + 1)) / 256 + BYTE3(v43) + 1;
                    v24 = v51;
                    v25 = _mm_shuffle_ps(v25, v25, 0);
                    v26.m128_f32[0] = (float)v37;
                    v26 = _mm_shuffle_ps(v26, v26, 0);
                    v38 = _mm_sub_ps(
                            v36,
                            _mm_div_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(
                                  v36,
                                  _mm_cvt_pi32ps(_m_punpcklwd(_m_punpcklbw(_mm_cvtsi32_si64(v41), 0i64), 0i64))),
                                v25),
                              v26));
                    v39 = _mm_cvtsi64_si32(_m_packuswb(_m_packssdw(_mm_cvt_ps2pi(v38), _mm_cvt_ps2pi(_mm_movehl_ps(v38, v38))), 0i64));
                    BYTE3(v39) = v37 - 1;
                    v29 = v39;
                  }
                }
                else
                {
                  v29 = v41;
                }
              }
              *(_DWORD *)&v24[4 * v27] = v29;
            }
          }
          while ( v27 );
        }
        v24 -= v45;
        v23 = v49 == 1;
        v51 = v24;
        --v49;
      }
      while ( !v23 );
    }
  }
  _m_femms();
}

//----- (0066F170) --------------------------------------------------------  // acclient.c:645732
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_0__BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@2
  unsigned int v2; // ebx@3
  int v3; // ecx@5
  unsigned int *v4; // edi@5
  int v5; // ebx@6
  int v6; // ebx@6
  unsigned int v7; // esi@6
  unsigned int v8; // esi@9
  __m64 v9; // mm2@12
  __m64 v10; // mm0@12
  __m64 v11; // mm3@12
  __m64 v12; // mm4@12
  __m64 v13; // mm3@12
  signed int v14; // ecx@13
  int v15; // eax@13
  bool v16; // zf@17
  char *v17; // edx@19
  unsigned int v18; // edi@21
  unsigned int v19; // esi@24
  int v20; // eax@25
  __m64 v21; // mm2@29
  __m64 v22; // mm0@29
  __m64 v23; // mm3@29
  __m64 v24; // mm4@29
  __m64 v25; // mm3@29
  signed int v26; // ecx@30
  unsigned int v27; // [sp+18h] [bp-38h]@10
  int v28; // [sp+18h] [bp-38h]@26
  char *v29; // [sp+1Ch] [bp-34h]@2
  unsigned int v30; // [sp+1Ch] [bp-34h]@19
  unsigned int v31; // [sp+20h] [bp-30h]@3
  unsigned int v32; // [sp+20h] [bp-30h]@20
  unsigned int v33; // [sp+2Ch] [bp-24h]@5
  char *v34; // [sp+30h] [bp-20h]@2
  unsigned int v35; // [sp+30h] [bp-20h]@20
  unsigned int v36; // [sp+34h] [bp-1Ch]@3
  char *v37; // [sp+34h] [bp-1Ch]@19
  int v38; // [sp+38h] [bp-18h]@2
  int v39; // [sp+44h] [bp-Ch]@5
  unsigned int v40; // [sp+48h] [bp-8h]@3
  unsigned int v41; // [sp+48h] [bp-8h]@22
  unsigned int v42; // [sp+4Ch] [bp-4h]@3
  unsigned int v43; // [sp+4Ch] [bp-4h]@20

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v29 = i_args->cSrcArgs.pDstBuf;
    v34 = i_args->cDstArgs.pDstBuf;
    v38 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v2 = i_args->nWidth;
      v40 = i_args->nWidth;
      v42 = i_args->cSrcArgs.iStride;
      v31 = i_args->cDstArgs.iStride;
      v36 = i_args->nHeight;
      do
      {
        if ( v2 )
        {
          v3 = v29 - v1;
          v4 = (unsigned int *)&v1[4 * v2];
          v39 = v29 - v1;
          v33 = v2;
          do
          {
            v5 = *(unsigned int *)((char *)v4 + v3 - 4);
            --v4;
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v7 = (unsigned int)v6 >> 24;
            if ( v38 != 256 )
              v7 = (signed int)(v38 * v7) / 256;
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 != 256 )
              {
                v27 = *v4;
                if ( *v4 >> 24 )
                {
                  if ( BYTE3(v27) == -1 )
                  {
                    v9 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v10 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), 0i64);
                    v11 = _mm_cvtsi32_si64(v8);
                    v12 = _m_punpcklwd(v11, v11);
                    v13 = _m_punpcklwd(v12, v12);
                    v6 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v10, _m_psubw(_m_psrlw(_m_pmullw(v10, v13), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v9), _m_pandn(v9, v10)), v13), 8u))), 0i64));
                  }
                  else
                  {
                    v14 = v8 - (signed int)(v8 * (BYTE3(v27) + 1)) / 256 + BYTE3(v27) + 1;
                    BYTE2(v27) -= (signed int)(v8 * (BYTE2(v27) - BYTE2(v6))) / v14;
                    BYTE1(v27) -= (signed int)(v8 * (BYTE1(v27) - BYTE1(v6))) / v14;
                    v15 = (signed int)(v8 * ((unsigned __int8)v27 - (unsigned __int8)v6)) / v14;
                    BYTE3(v27) = v14 - 1;
                    v3 = v39;
                    LOBYTE(v27) = v27 - v15;
                    v6 = v27;
                  }
                }
              }
              *v4 = v6;
            }
            --v33;
          }
          while ( v33 );
          v1 = v34;
          v2 = v40;
        }
        v1 += v31;
        v16 = v36 == 1;
        v29 += v42;
        v34 = v1;
        --v36;
      }
      while ( !v16 );
    }
  }
  else
  {
    v17 = i_args->cDstArgs.pDstBuf;
    v30 = g_SourceColor.u;
    BYTE3(v30) = i_args->i8AlphaModifier;
    v37 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v43 = i_args->nWidth;
      v32 = i_args->cDstArgs.iStride;
      v35 = i_args->nHeight;
      do
      {
        v18 = v43;
        if ( v43 )
        {
          v41 = v30 >> 24;
          do
          {
            --v18;
            if ( v41 )
            {
              v19 = v41 + 1;
              if ( v41 == 255 )
              {
                v20 = v30;
              }
              else
              {
                v28 = *(_DWORD *)&v17[4 * v18];
                if ( BYTE3(v28) )
                {
                  if ( BYTE3(v28) == -1 )
                  {
                    v21 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                    v22 = _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)&v17[4 * v18]), 0i64);
                    v23 = _mm_cvtsi32_si64(v19);
                    v24 = _m_punpcklwd(v23, v23);
                    v25 = _m_punpcklwd(v24, v24);
                    v20 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v22, _m_psubw(_m_psrlw(_m_pmullw(v22, v25), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v30), 0i64), v21), _m_pandn(v21, v22)), v25), 8u))), 0i64));
                  }
                  else
                  {
                    v26 = v19 - (signed int)(v19 * (BYTE3(v28) + 1)) / 256 + BYTE3(v28) + 1;
                    BYTE2(v28) -= (signed int)(v19 * (BYTE2(v28) - BYTE2(v30))) / v26;
                    BYTE1(v28) -= (signed int)(v19 * (BYTE1(v28) - BYTE1(v30))) / v26;
                    v17 = v37;
                    LOBYTE(v28) = v28
                                - (unsigned int)((signed int)(v19 * ((unsigned __int8)v28 - (unsigned __int8)v30)) / v26);
                    BYTE3(v28) = v26 - 1;
                    v20 = v28;
                  }
                }
                else
                {
                  v20 = v30;
                }
              }
              *(_DWORD *)&v17[4 * v18] = v20;
            }
          }
          while ( v18 );
        }
        v17 -= v32;
        v16 = v35 == 1;
        v37 = v17;
        --v35;
      }
      while ( !v16 );
    }
  }
  _m_femms();
}

//----- (0066F520) --------------------------------------------------------  // acclient.c:645929
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_1__BlitFormat_AXXX_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  int v4; // esi@5
  int v5; // ecx@6
  int v6; // ecx@6
  unsigned int v7; // eax@6
  unsigned int v8; // eax@9
  unsigned int v9; // ST18_4@10
  __m64 v10; // mm2@10
  __m64 v11; // mm0@10
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@14
  unsigned int v16; // ecx@18
  unsigned int v17; // edi@19
  int v18; // eax@22
  unsigned int v19; // ST28_4@23
  __m64 v20; // mm2@23
  __m64 v21; // mm0@23
  __m64 v22; // mm3@23
  __m64 v23; // mm4@23
  __m64 v24; // mm3@23
  char *v25; // [sp+10h] [bp-20h]@2
  unsigned int v26; // [sp+10h] [bp-20h]@16
  unsigned int v27; // [sp+14h] [bp-1Ch]@3
  unsigned int v28; // [sp+14h] [bp-1Ch]@17
  unsigned int v29; // [sp+1Ch] [bp-14h]@5
  unsigned int v30; // [sp+20h] [bp-10h]@3
  char *v31; // [sp+24h] [bp-Ch]@2
  unsigned int v32; // [sp+24h] [bp-Ch]@17
  unsigned int v33; // [sp+28h] [bp-8h]@3
  unsigned int v34; // [sp+2Ch] [bp-4h]@3
  unsigned int v35; // [sp+2Ch] [bp-4h]@17

  v1 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v25 = i_args->cSrcArgs.pDstBuf;
    v31 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v30 = i_args->nWidth;
      v34 = i_args->cSrcArgs.iStride;
      v27 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v29 = v30;
          do
          {
            v5 = *(_DWORD *)(v4 + v25 - v1 - 4);
            v4 -= 4;
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v7 = (unsigned int)v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 != 256 )
              {
                v9 = *(_DWORD *)v4;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v9) = -1;
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                v12 = _mm_cvtsi32_si64(v8);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v6 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
              *(_DWORD *)v4 = v6;
            }
            --v29;
          }
          while ( v29 );
          v1 = v31;
          v3 = v30;
        }
        v1 += v27;
        v15 = v33 == 1;
        v25 += v34;
        v31 = v1;
        --v33;
      }
      while ( !v15 );
    }
  }
  else
  {
    v26 = g_SourceColor.u;
    BYTE3(v26) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v35 = i_args->nWidth;
      v28 = i_args->cDstArgs.iStride;
      v32 = i_args->nHeight;
      do
      {
        v16 = v35;
        if ( v35 )
        {
          v17 = v26 >> 24;
          do
          {
            --v16;
            if ( v17 )
            {
              if ( v17 == 255 )
              {
                v18 = v26;
              }
              else
              {
                v19 = *(_DWORD *)&v1[4 * v16];
                v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v19) = -1;
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
                v22 = _mm_cvtsi32_si64(v17 + 1);
                v23 = _m_punpcklwd(v22, v22);
                v24 = _m_punpcklwd(v23, v23);
                v18 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v24), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), v20), _m_pandn(v20, v21)), v24), 8u))), 0i64));
              }
              *(_DWORD *)&v1[4 * v16] = v18;
            }
          }
          while ( v16 );
        }
        v1 -= v28;
        --v32;
      }
      while ( v32 );
    }
  }
  _m_femms();
}

//----- (0066F770) --------------------------------------------------------  // acclient.c:646075
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_0__BlitFormat_AXXX_BlitFormat_XRGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // edx@1
  int v2; // ebx@2
  unsigned int v3; // esi@3
  int v4; // esi@5
  int v5; // ecx@6
  int v6; // ecx@6
  unsigned int v7; // eax@6
  unsigned int v8; // eax@9
  unsigned int v9; // ST18_4@10
  __m64 v10; // mm2@10
  __m64 v11; // mm0@10
  __m64 v12; // mm3@10
  __m64 v13; // mm4@10
  __m64 v14; // mm3@10
  bool v15; // zf@14
  unsigned int v16; // ecx@18
  unsigned int v17; // edi@19
  int v18; // eax@22
  unsigned int v19; // ST28_4@23
  __m64 v20; // mm2@23
  __m64 v21; // mm0@23
  __m64 v22; // mm3@23
  __m64 v23; // mm4@23
  __m64 v24; // mm3@23
  char *v25; // [sp+10h] [bp-20h]@2
  unsigned int v26; // [sp+10h] [bp-20h]@16
  unsigned int v27; // [sp+14h] [bp-1Ch]@3
  unsigned int v28; // [sp+14h] [bp-1Ch]@17
  unsigned int v29; // [sp+1Ch] [bp-14h]@5
  unsigned int v30; // [sp+20h] [bp-10h]@3
  char *v31; // [sp+24h] [bp-Ch]@2
  unsigned int v32; // [sp+24h] [bp-Ch]@17
  unsigned int v33; // [sp+28h] [bp-8h]@3
  unsigned int v34; // [sp+2Ch] [bp-4h]@3
  unsigned int v35; // [sp+2Ch] [bp-4h]@17

  v1 = i_args->cDstArgs.pDstBuf;
  if ( i_args->cSrcArgs.pDstBuf )
  {
    v25 = i_args->cSrcArgs.pDstBuf;
    v31 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v3 = i_args->nWidth;
      v30 = i_args->nWidth;
      v34 = i_args->cSrcArgs.iStride;
      v27 = i_args->cDstArgs.iStride;
      v33 = i_args->nHeight;
      do
      {
        if ( v3 )
        {
          v4 = (int)&v1[4 * v3];
          v29 = v30;
          do
          {
            v5 = *(_DWORD *)(v25 - v1 + v4 - 4);
            v4 -= 4;
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v7 = (unsigned int)v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 != 256 )
              {
                v9 = *(_DWORD *)v4;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v9) = -1;
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                v12 = _mm_cvtsi32_si64(v8);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v6 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
              *(_DWORD *)v4 = v6;
            }
            --v29;
          }
          while ( v29 );
          v1 = v31;
          v3 = v30;
        }
        v1 += v27;
        v15 = v33 == 1;
        v25 += v34;
        v31 = v1;
        --v33;
      }
      while ( !v15 );
    }
  }
  else
  {
    v26 = g_SourceColor.u;
    BYTE3(v26) = i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v35 = i_args->nWidth;
      v28 = i_args->cDstArgs.iStride;
      v32 = i_args->nHeight;
      do
      {
        v16 = v35;
        if ( v35 )
        {
          v17 = v26 >> 24;
          do
          {
            --v16;
            if ( v17 )
            {
              if ( v17 == 255 )
              {
                v18 = v26;
              }
              else
              {
                v19 = *(_DWORD *)&v1[4 * v16];
                v20 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v19) = -1;
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(v19), 0i64);
                v22 = _mm_cvtsi32_si64(v17 + 1);
                v23 = _m_punpcklwd(v22, v22);
                v24 = _m_punpcklwd(v23, v23);
                v18 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v21, _m_psubw(_m_psrlw(_m_pmullw(v21, v24), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v26), 0i64), v20), _m_pandn(v20, v21)), v24), 8u))), 0i64));
              }
              *(_DWORD *)&v1[4 * v16] = v18;
            }
          }
          while ( v16 );
        }
        v1 -= v28;
        --v32;
      }
      while ( v32 );
    }
  }
  _m_femms();
}

//----- (0066F9C0) --------------------------------------------------------  // acclient.c:646221
void __usercall ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_0__BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args@<eax>)
{
  char *v1; // esi@2
  int v2; // ebx@2
  unsigned int v3; // edi@4
  int v4; // esi@5
  int v5; // ecx@6
  unsigned int v6; // ecx@6
  unsigned int v7; // eax@6
  unsigned int v8; // eax@9
  unsigned int v9; // ST10_4@11
  __m64 v10; // mm2@11
  __m64 v11; // mm0@11
  __m64 v12; // mm3@11
  __m64 v13; // mm4@11
  __m64 v14; // mm3@11
  bool v15; // zf@14
  char *v16; // ebx@16
  unsigned int v17; // edi@17
  unsigned int v18; // esi@19
  int v19; // eax@19
  unsigned int v20; // ST10_4@23
  __m64 v21; // mm2@23
  __m64 v22; // mm0@23
  __m64 v23; // mm3@23
  __m64 v24; // mm4@23
  __m64 v25; // mm3@23
  unsigned int v26; // [sp+10h] [bp-20h]@10
  unsigned int v27; // [sp+10h] [bp-20h]@22
  char *v28; // [sp+14h] [bp-1Ch]@2
  unsigned int v29; // [sp+14h] [bp-1Ch]@16
  unsigned int v30; // [sp+18h] [bp-18h]@3
  unsigned int v31; // [sp+18h] [bp-18h]@17
  char *v32; // [sp+1Ch] [bp-14h]@2
  char *v33; // [sp+1Ch] [bp-14h]@16
  unsigned int v34; // [sp+20h] [bp-10h]@3
  unsigned int v35; // [sp+20h] [bp-10h]@19
  unsigned int v36; // [sp+24h] [bp-Ch]@3
  unsigned int v37; // [sp+24h] [bp-Ch]@17
  unsigned int v38; // [sp+2Ch] [bp-4h]@3

  if ( i_args->cSrcArgs.pDstBuf )
  {
    v1 = i_args->cDstArgs.pDstBuf;
    v28 = i_args->cSrcArgs.pDstBuf;
    v32 = i_args->cDstArgs.pDstBuf;
    v2 = (i_args->i8AlphaModifier != 0) + i_args->i8AlphaModifier;
    if ( i_args->nHeight )
    {
      v36 = i_args->nWidth;
      v38 = i_args->cSrcArgs.iStride;
      v30 = i_args->cDstArgs.iStride;
      v34 = i_args->nHeight;
      do
      {
        v3 = v36;
        if ( v36 )
        {
          v4 = (int)(&v1[2 * v36 + 2] + v36);
          do
          {
            v5 = *(_DWORD *)&v28[4 * v3-- - 4];
            v6 = g_SourceColor.u | v5 & 0xFF000000;
            v4 -= 3;
            v7 = v6 >> 24;
            if ( v2 != 256 )
              v7 = (signed int)(v2 * v7) / 256;
            if ( v7 )
            {
              v8 = v7 + 1;
              if ( v8 == 256 )
              {
                v26 = v6;
              }
              else
              {
                LOBYTE(v9) = *(_BYTE *)(v4 - 2);
                BYTE1(v9) = *(_BYTE *)(v4 - 1);
                BYTE2(v9) = *(_BYTE *)v4;
                v10 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v9) = -1;
                v11 = _m_punpcklbw(_mm_cvtsi32_si64(v9), 0i64);
                v12 = _mm_cvtsi32_si64(v8);
                v13 = _m_punpcklwd(v12, v12);
                v14 = _m_punpcklwd(v13, v13);
                v26 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v11, _m_psubw(_m_psrlw(_m_pmullw(v11, v14), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v6), 0i64), v10), _m_pandn(v10, v11)), v14), 8u))), 0i64));
              }
              *(_BYTE *)(v4 - 2) = v26;
              *(_BYTE *)(v4 - 1) = BYTE1(v26);
              *(_BYTE *)v4 = v26 >> 16;
            }
          }
          while ( v3 );
        }
        v1 = &v32[v30];
        v15 = v34 == 1;
        v28 += v38;
        v32 += v30;
        --v34;
      }
      while ( !v15 );
    }
  }
  else
  {
    v16 = i_args->cDstArgs.pDstBuf;
    v29 = g_SourceColor.u;
    BYTE3(v29) = i_args->i8AlphaModifier;
    v33 = i_args->cDstArgs.pDstBuf;
    if ( i_args->nHeight )
    {
      v17 = i_args->nWidth;
      v31 = i_args->cDstArgs.iStride;
      v37 = i_args->nHeight;
      do
      {
        if ( v17 )
        {
          v18 = v29 >> 24;
          v19 = (int)(&v16[2 * v17 + 2] + v17);
          v35 = v17;
          do
          {
            v19 -= 3;
            if ( v18 )
            {
              if ( v18 == 255 )
              {
                v27 = v29;
              }
              else
              {
                LOBYTE(v20) = *(_BYTE *)(v19 - 2);
                BYTE1(v20) = *(_BYTE *)(v19 - 1);
                BYTE2(v20) = *(_BYTE *)v19;
                v21 = _m_punpcklbw(_mm_cvtsi32_si64(0xFFFFFFu), 0i64);
                BYTE3(v20) = -1;
                v22 = _m_punpcklbw(_mm_cvtsi32_si64(v20), 0i64);
                v23 = _mm_cvtsi32_si64(v18 + 1);
                v24 = _m_punpcklwd(v23, v23);
                v25 = _m_punpcklwd(v24, v24);
                v27 = _mm_cvtsi64_si32(_m_packuswb(_m_psubw(v22, _m_psubw(_m_psrlw(_m_pmullw(v22, v25), 8u), _m_psrlw(_m_pmullw(_m_por(_m_pand(_m_punpcklbw(_mm_cvtsi32_si64(v29), 0i64), v21), _m_pandn(v21, v22)), v25), 8u))), 0i64));
              }
              *(_BYTE *)(v19 - 2) = v27;
              *(_BYTE *)(v19 - 1) = BYTE1(v27);
              *(_BYTE *)v19 = v27 >> 16;
            }
            --v35;
          }
          while ( v35 );
        }
        v16 = &v33[-v31];
        v15 = v37 == 1;
        v33 -= v31;
        --v37;
      }
      while ( !v15 );
    }
  }
  _m_femms();
}

//----- (0066FC80) --------------------------------------------------------  // acclient.c:646384
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_1__BlitFormat_ARGB_BlitFormat_ARGB_(i_args);
  else
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_0__BlitFormat_ARGB_BlitFormat_ARGB_(i_args);
}

//----- (0066FCA0) --------------------------------------------------------  // acclient.c:646393
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_XRGB_0__BlitFormat_ARGB_BlitFormat_XRGB_(i_args);
}

//----- (0066FCC0) --------------------------------------------------------  // acclient.c:646402
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB_0__BlitFormat_ARGB_BlitFormat_RGB_(i_args);
}

//----- (0066FCE0) --------------------------------------------------------  // acclient.c:646411
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_1__BlitFormat_XRGB_BlitFormat_ARGB_(i_args);
  else
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_0__BlitFormat_XRGB_BlitFormat_ARGB_(i_args);
}

//----- (0066FD00) --------------------------------------------------------  // acclient.c:646420
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_XRGB_0__BlitFormat_XRGB_BlitFormat_XRGB_(i_args);
}

//----- (0066FD20) --------------------------------------------------------  // acclient.c:646429
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB_0__BlitFormat_XRGB_BlitFormat_RGB_(i_args);
}

//----- (0066FD40) --------------------------------------------------------  // acclient.c:646438
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_1__BlitFormat_RGB_BlitFormat_ARGB_(i_args);
  else
    BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_0__BlitFormat_RGB_BlitFormat_ARGB_(i_args);
}

//----- (0066FD60) --------------------------------------------------------  // acclient.c:646447
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_XRGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_XRGB_0__BlitFormat_RGB_BlitFormat_XRGB_(i_args);
}

//----- (0066FD80) --------------------------------------------------------  // acclient.c:646456
void __cdecl BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  BlitLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_RGB_BlitFormat_RGB_0__BlitFormat_RGB_BlitFormat_RGB_(i_args);
}

//----- (0066FDA0) --------------------------------------------------------  // acclient.c:646465
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_1__BlitFormat_Fill_BlitFormat_ARGB_(i_args);
  else
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_0__BlitFormat_Fill_BlitFormat_ARGB_(i_args);
}

//----- (0066FDC0) --------------------------------------------------------  // acclient.c:646474
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_XRGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_XRGB_0__BlitFormat_Fill_BlitFormat_XRGB_(i_args);
}

//----- (0066FDE0) --------------------------------------------------------  // acclient.c:646483
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_Fill_BlitFormat_RGB_0__BlitFormat_Fill_BlitFormat_RGB_(i_args);
}

//----- (0066FE00) --------------------------------------------------------  // acclient.c:646492
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_1__BlitFormat_ARGB_(i_args);
  else
    ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_0__BlitFormat_ARGB_(i_args);
}

//----- (0066FE20) --------------------------------------------------------  // acclient.c:646501
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_XRGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_0__BlitFormat_XRGB_(i_args);
}

//----- (0066FE40) --------------------------------------------------------  // acclient.c:646510
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  ColoringLoopNoScale_FromA8__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_0__BlitFormat_RGB_(i_args);
}

//----- (0066FE60) --------------------------------------------------------  // acclient.c:646519
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_1__BlitFormat_AXXX_BlitFormat_ARGB_(i_args);
  else
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_0__BlitFormat_AXXX_BlitFormat_ARGB_(i_args);
}

//----- (0066FE80) --------------------------------------------------------  // acclient.c:646528
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_(BlitArgs *i_args)
{
  if ( IsSSEAvailable() )
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_1__BlitFormat_AXXX_BlitFormat_XRGB_(i_args);
  else
    ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_0__BlitFormat_AXXX_BlitFormat_XRGB_(i_args);
}

//----- (0066FEA0) --------------------------------------------------------  // acclient.c:646537
void __cdecl ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_(BlitArgs *i_args)
{
  bool v1; // zf@1

  v1 = IsSSEAvailable() == 0;
  ColoringLoopNoScale__BlitOp_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_0__BlitFormat_AXXX_BlitFormat_RGB_(i_args);
}

