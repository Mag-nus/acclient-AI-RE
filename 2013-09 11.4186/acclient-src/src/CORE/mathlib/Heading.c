/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Heading
   Object     : CORE\mathlib\Heading.obj
   Functions  : 2
   Addresses  : 00714C40 - 00714CA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00714C40) --------------------------------------------------------  // acclient.c:807614
int sub_714C40()
{
  long double v0; // st7@1
  double v1; // st7@2

  v0 = fmod(0.0, 360.0);
  Heading::ZERO.m_degrees = v0;
  if ( v0 < 0.0 )
  {
    v1 = Heading::ZERO.m_degrees + 360.0;
    Heading::ZERO.m_degrees = v1;
    if ( v1 >= 360.0 )
      COERCE_CONST_STRUCT_HEADING(Heading::ZERO.m_degrees) = 0;
  }
  return atexit(nullsub_41);
}
// 795344: using guessed type float FLOAT_0_0;
// 8F76A4: using guessed type const struct Heading Heading::ZERO;

//----- (00714CA0) --------------------------------------------------------  // acclient.c:807634
int _E76_83()
{
  long double v0; // st7@1
  double v1; // st7@2

  v0 = fmod(0.01145915574689432, 360.0);
  Heading::EPSILON.m_degrees = v0;
  if ( v0 < 0.0 )
  {
    v1 = Heading::EPSILON.m_degrees + 360.0;
    Heading::EPSILON.m_degrees = v1;
    if ( v1 >= 360.0 )
      COERCE_CONST_STRUCT_HEADING(Heading::EPSILON.m_degrees) = 0;
  }
  return atexit(nullsub_42);
}
// 795344: using guessed type float FLOAT_0_0;
// 8F76A8: using guessed type const struct Heading Heading::EPSILON;

