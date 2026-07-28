/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : amdmath
   Object     : _runtime\msvcrt\amdmath.obj
   Functions  : 19
   Addresses  : 00614000 - 00614AC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00614000) --------------------------------------------------------  // acclient.c:568896
void a_atan()
{
  ;
}

//----- (006140C0) --------------------------------------------------------  // acclient.c:568902
void a_atan2()
{
  ;
}

//----- (006141C0) --------------------------------------------------------  // acclient.c:568908
void a_acos()
{
  ;
}

//----- (006142C0) --------------------------------------------------------  // acclient.c:568914
void a_asin()
{
  ;
}

//----- (006143C0) --------------------------------------------------------  // acclient.c:568920
void a_log()
{
  ;
}

//----- (006144C0) --------------------------------------------------------  // acclient.c:568926
void a_log10()
{
  a_log();
}

//----- (006144E0) --------------------------------------------------------  // acclient.c:568932
void a_exp()
{
  ;
}

//----- (006145C0) --------------------------------------------------------  // acclient.c:568938
void a_sqrt()
{
  ;
}

//----- (006145E0) --------------------------------------------------------  // acclient.c:568944
void a_fabs()
{
  ;
}

//----- (00614600) --------------------------------------------------------  // acclient.c:568950
void a_ceil()
{
  ;
}

//----- (00614640) --------------------------------------------------------  // acclient.c:568956
void a_floor()
{
  ;
}

//----- (00614680) --------------------------------------------------------  // acclient.c:568962
void a_frexp()
{
  ;
}

//----- (006146C0) --------------------------------------------------------  // acclient.c:568968
unsigned int __usercall a_ldexp@<eax>(__m64 a1@<mm0>, __m64 a2@<mm1>)
{
  return _mm_cvtsi64_si32(_m_paddd(_m_psrld(_m_pand(a1, (__m64)sign_mask), 0x17u), a2)) & 0xFFFFFF00;
}

//----- (00614720) --------------------------------------------------------  // acclient.c:568974
void a_modf()
{
  ;
}

//----- (00614740) --------------------------------------------------------  // acclient.c:568980
int __usercall a_fmod@<eax>(__m64 a1@<mm1>)
{
  return _mm_cvtsi64_si32(a1);
}

//----- (006147A0) --------------------------------------------------------  // acclient.c:568986
unsigned int __usercall a_cos@<eax>(__m64 a1@<mm0>)
{
  int v1; // eax@1

  v1 = _mm_cvtsi64_si32(a1);
  return v1 & 0x80000000 ^ v1;
}

//----- (006148A0) --------------------------------------------------------  // acclient.c:568995
unsigned int __usercall a_sin@<eax>(__m64 a1@<mm0>)
{
  int v1; // eax@1

  v1 = _mm_cvtsi64_si32(a1);
  return v1 & 0x80000000 ^ v1;
}

//----- (006149A0) --------------------------------------------------------  // acclient.c:569004
unsigned int __usercall a_tan@<eax>(__m64 a1@<mm0>)
{
  int v1; // eax@1

  v1 = _mm_cvtsi64_si32(a1);
  return v1 & 0x80000000 ^ v1;
}

//----- (00614AC0) --------------------------------------------------------  // acclient.c:569013
void a_pow()
{
  ;
}

