/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : adler32
   Object     : _runtime\msvcrt\adler32.obj
   Functions  : 1
   Addresses  : 00611C77 - 00611C77 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00611C77) --------------------------------------------------------  // acclient.c:567232
int __stdcall d3dx_adler32(unsigned int adler, const char *buf, unsigned int len)
{
  const char *v3; // ecx@1
  unsigned int v4; // esi@1
  unsigned int v5; // edi@1
  int result; // eax@2
  unsigned int v7; // edx@4
  unsigned int v8; // eax@7
  int v9; // esi@8
  int v10; // edi@8
  int v11; // esi@8
  int v12; // edi@8
  int v13; // esi@8
  int v14; // edi@8
  int v15; // esi@8
  int v16; // edi@8
  int v17; // esi@8
  int v18; // edi@8
  int v19; // esi@8
  int v20; // edi@8
  int v21; // esi@8
  int v22; // edi@8
  int v23; // esi@8
  int v24; // edi@8
  int v25; // esi@8
  int v26; // edi@8
  int v27; // esi@8
  int v28; // edi@8
  int v29; // esi@8
  int v30; // edi@8
  int v31; // esi@8
  int v32; // edi@8
  int v33; // esi@8
  int v34; // edi@8
  int v35; // esi@8
  int v36; // edi@8
  int v37; // esi@8
  int v38; // edi@8

  v3 = buf;
  v4 = (unsigned __int16)adler;
  v5 = adler >> 16;
  if ( buf )
  {
    for ( ; len; v5 %= 0xFFF1u )
    {
      v7 = 5552;
      if ( len < 0x15B0 )
        v7 = len;
      len -= v7;
      if ( (signed int)v7 >= 16 )
      {
        v8 = v7 >> 4;
        v7 += -16 * (v7 >> 4);
        do
        {
          v9 = *v3 + v4;
          v10 = v9 + v5;
          v11 = v3[1] + v9;
          v12 = v11 + v10;
          v13 = v3[2] + v11;
          v14 = v13 + v12;
          v15 = v3[3] + v13;
          v16 = v15 + v14;
          v17 = v3[4] + v15;
          v18 = v17 + v16;
          v19 = v3[5] + v17;
          v20 = v19 + v18;
          v21 = v3[6] + v19;
          v22 = v21 + v20;
          v23 = v3[7] + v21;
          v24 = v23 + v22;
          v25 = v3[8] + v23;
          v26 = v25 + v24;
          v27 = v3[9] + v25;
          v28 = v27 + v26;
          v29 = v3[10] + v27;
          v30 = v29 + v28;
          v31 = v3[11] + v29;
          v32 = v31 + v30;
          v33 = v3[12] + v31;
          v34 = v33 + v32;
          v35 = v3[13] + v33;
          v36 = v35 + v34;
          v37 = v3[14] + v35;
          v38 = v37 + v36;
          v4 = v3[15] + v37;
          v5 = v4 + v38;
          v3 += 16;
          --v8;
        }
        while ( v8 );
      }
      for ( ; v7; --v7 )
      {
        v4 += *v3++;
        v5 += v4;
      }
      v4 %= 0xFFF1u;
    }
    result = v4 | (v5 << 16);
  }
  else
  {
    result = 1;
  }
  return result;
}

