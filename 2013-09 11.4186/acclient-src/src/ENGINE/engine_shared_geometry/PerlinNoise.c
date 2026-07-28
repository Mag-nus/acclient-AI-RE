/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PerlinNoise
   Object     : ENGINE\engine_shared_geometry\PerlinNoise.obj
   Functions  : 3
   Addresses  : 005B2820 - 005B2960 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B2820) --------------------------------------------------------  // acclient.c:477215
void PerlinNoise::Init()
{
  int v1; // esi@1
  int i; // esi@3
  int v3; // edi@4
  int v4; // eax@4

  _srand(0);
  v1 = 0;
  do
  {
    p[v1] = v1;
    ++v1;
    flt_8EE1CC[v1] = (double)(_rand() % 512 - 256) * 0.00390625;
  }
  while ( v1 < 256 );
  for ( i = v1 - 1; i; p[v4] = v3 )
  {
    v3 = p[i];
    v4 = _rand() % 256;
    --i;
    p[i + 1] = p[v4];
  }
  qmemcpy(&g1[256], g1, 0x408u);
  qmemcpy(&p[256], p, 0x408u);
}
// 8EE1CC: using guessed type float flt_8EE1CC[];

//----- (005B28D0) --------------------------------------------------------  // acclient.c:477244
double __stdcall PerlinNoise::Noise(long double arg)
{
  double v2; // st7@3
  unsigned __int64 v3; // rax@3
  double v4; // st7@3
  float u; // [sp+4h] [bp+4h]@1
  float ua; // [sp+4h] [bp+4h]@3

  u = arg;
  if ( start )
  {
    start = 0;
    PerlinNoise::Init();
  }
  v2 = u + 10000.0;
  v3 = (unsigned __int64)v2;
  v4 = v2 - (double)(signed int)(unsigned __int64)v2;
  LODWORD(v3) = (unsigned __int8)v3;
  ua = v4 * g1[p[(signed int)v3]];
  return ((v4 - 1.0) * g1[p[(unsigned __int8)(v3 + 1)]] - ua) * ((3.0 - (v4 + v4)) * (v4 * v4)) + ua;
}

//----- (005B2960) --------------------------------------------------------  // acclient.c:477267
double __stdcall PerlinNoise::fBm1(long double point, long double H, long double lacunarity, long double octaves)
{
  signed int v5; // esi@3
  double result; // st7@6
  signed int v7; // esi@6
  long double v8; // st7@7
  long double value; // [sp+10h] [bp-10h]@3
  double valuea; // [sp+10h] [bp-10h]@6
  double remainder; // [sp+18h] [bp-8h]@8

  if ( first || H != lastH )
  {
    lastH = H;
    v5 = 0;
    value = 1.0;
    if ( octaves >= 0.0 )
    {
      do
      {
        exponent_array[v5++] = pow(value, -H);
        value = value * lacunarity;
      }
      while ( (double)v5 <= octaves );
    }
    first = 0;
  }
  result = 0.0;
  v7 = 0;
  valuea = 0.0;
  if ( octaves > 0.0 )
  {
    do
    {
      v8 = PerlinNoise::Noise(point) * exponent_array[v7++];
      result = v8 + valuea;
      valuea = result;
      point = point * lacunarity;
    }
    while ( (double)v7 < octaves );
  }
  remainder = octaves - (double)(signed int)(unsigned __int64)octaves;
  if ( remainder != 0.0 )
    result = PerlinNoise::Noise(point) * exponent_array[v7] * remainder + valuea;
  return result;
}

