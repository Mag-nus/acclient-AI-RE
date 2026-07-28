/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Utils
   Object     : ENGINE\engine_utils\Utils.obj
   Functions  : 4
   Addresses  : 006843D0 - 00684460 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006843D0) --------------------------------------------------------  // acclient.c:667643
long double __cdecl RandDouble(const long double _min, const long double _max)
{
  return (double)_rand() * 0.00003051850947599719 * (_max - _min) + _min;
}

//----- (00684400) --------------------------------------------------------  // acclient.c:667649
int __cdecl RandInt(const int _range)
{
  return _range * _rand() / 0x8000;
}

//----- (00684420) --------------------------------------------------------  // acclient.c:667655
int __cdecl RandInt(const int _range, const int _exclude)
{
  int result; // eax@2

  if ( _range > 1 )
  {
    do
      result = _range * _rand() / 0x8000;
    while ( result == _exclude );
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00684460) --------------------------------------------------------  // acclient.c:667673
int __cdecl LowestSetBit(unsigned int _num)
{
  int result; // eax@1

  result = 0;
  while ( !((1 << result) & _num) )
  {
    ++result;
    if ( result >= 32 )
      return -1;
  }
  return result;
}

