/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Random
   Object     : PORTAL\random\Random.obj
   Functions  : 5
   Addresses  : 0042C450 - 0042C600 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042C450) --------------------------------------------------------  // acclient.c:105430
void __cdecl Random::Seed(int seed)
{
  int v1; // ecx@1
  signed int v2; // esi@3

  v1 = seed;
  if ( !seed )
    v1 = 1;
  Random::_idum2 = v1;
  v2 = (signed int)&KW_STRINGCOMMENT;
  do
  {
    v1 = 40014 * v1 - 2147483563 * (v1 / 53668) + ((char)-(40014 * v1 - 2147483563 * (v1 / 53668) < 0) & 0x7FFFFFAB);
    if ( v2 < (signed int)&Random::_iy )
      *(_DWORD *)v2 = v1;
    v2 -= 4;
  }
  while ( v2 >= (signed int)&Random::_iv );
  Random::_iy = (__int32)Random::_iv;
  Random::_seed = v1;
}
// 8179E8: using guessed type __int32 Random::_seed;
// 8179EC: using guessed type __int32 Random::_idum2;
// 836EA0: using guessed type __int32 *Random::_iv;
// 836F20: using guessed type __int32 Random::_iy;

//----- (0042C4C0) --------------------------------------------------------  // acclient.c:105457
double __cdecl Random::rand()
{
  __int32 v0; // edx@1
  bool v1; // sf@1
  __int32 v2; // edi@1
  __int32 v3; // edx@3
  __int32 v4; // esi@3
  signed int v5; // eax@5
  double result; // st7@7

  v0 = 2147483563 * (Random::_seed / 53668);
  v1 = 40014 * Random::_seed - v0 < 0;
  v2 = 40014 * Random::_seed - v0;
  Random::_seed = 40014 * Random::_seed - v0;
  if ( v1 )
  {
    v2 += 2147483563;
    Random::_seed = v2;
  }
  v3 = 2147483399 * (Random::_idum2 / 52774);
  v1 = 40692 * Random::_idum2 - v3 < 0;
  v4 = 40692 * Random::_idum2 - v3;
  Random::_idum2 = 40692 * Random::_idum2 - v3;
  if ( v1 )
  {
    v4 += 2147483399;
    Random::_idum2 = v4;
  }
  v5 = (signed int)((char *)(&Random::_iv)[Random::_iy / 67108862] - v4);
  (&Random::_iv)[Random::_iy / 67108862] = (__int32 *)v2;
  Random::_iy = v5;
  if ( v5 < 1 )
    Random::_iy = v5 + 2147483562;
  result = (double)Random::_iy * 4.656613057391769e-10;
  if ( result > 0.99999988 )
    result = 0.99999988;
  return result;
}
// 8179E8: using guessed type __int32 Random::_seed;
// 8179EC: using guessed type __int32 Random::_idum2;
// 836EA0: using guessed type __int32 *Random::_iv;
// 836F20: using guessed type __int32 Random::_iy;

//----- (0042C5A0) --------------------------------------------------------  // acclient.c:105501
void __cdecl Random::Seed()
{
  Random::_seed = _time(0);
  Random::Seed(Random::_seed);
}
// 8179E8: using guessed type __int32 Random::_seed;

//----- (0042C5C0) --------------------------------------------------------  // acclient.c:105509
int __cdecl Random::RollDice(const int lower_bound, const int upper_bound)
{
  const int result; // eax@1
  const int v3; // esi@2
  const int v4; // edi@2

  result = lower_bound;
  if ( upper_bound != lower_bound )
  {
    v3 = upper_bound;
    v4 = lower_bound;
    if ( upper_bound < lower_bound )
    {
      v3 = lower_bound;
      v4 = upper_bound;
    }
    result = v4 + (unsigned __int64)(Random::rand() * (double)(unsigned int)(v3 - v4 + 1));
  }
  return result;
}

//----- (0042C600) --------------------------------------------------------  // acclient.c:105531
double __cdecl Random::RollDice(const float lower_bound, const float upper_bound)
{
  double result; // st7@2
  const float realLower; // [sp+0h] [bp-8h]@3
  const float realUpper; // [sp+4h] [bp-4h]@3

  if ( lower_bound == upper_bound )
  {
    result = lower_bound;
  }
  else
  {
    realUpper = upper_bound;
    realLower = lower_bound;
    if ( upper_bound < (double)lower_bound )
    {
      realUpper = lower_bound;
      realLower = upper_bound;
    }
    result = Random::rand() * (realUpper - realLower) + realLower;
  }
  return result;
}

