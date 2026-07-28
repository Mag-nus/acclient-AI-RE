/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CShadowObj
   Object     : PORTAL\cphysobj\CShadowObj.obj
   Functions  : 9
   Addresses  : 0051BB30 - 006FCAB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051BB30) --------------------------------------------------------  // acclient.c:329718
void __thiscall CShadowObj::set_physobj(CShadowObj *this, CPhysicsObj *_physobj)
{
  this->physobj = _physobj;
  this->id = _physobj->id;
}

//----- (006FC9E0) --------------------------------------------------------  // acclient.c:784959
int _E77_2()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_9;
  INITIAL_MAX_DATA_RATE_76 = LOWEST_DATA_RATE_9;
  return result;
}

//----- (006FC9F0) --------------------------------------------------------  // acclient.c:784969
void sub_6FC9F0()
{
  flt_844180 = 1000.0 + 1.0;
}

//----- (006FCA10) --------------------------------------------------------  // acclient.c:784975
void _E99_18()
{
  flt_844184 = 24.0 * 8.0;
}

//----- (006FCA30) --------------------------------------------------------  // acclient.c:784981
void _E101_15()
{
  flt_844188 = 24.0 * 0.5;
}

//----- (006FCA50) --------------------------------------------------------  // acclient.c:784987
void sub_6FCA50()
{
  flt_844190 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FCA70) --------------------------------------------------------  // acclient.c:784993
void _E105_22()
{
  dbl_844198 = 1.0 / 30.0;
}

//----- (006FCA90) --------------------------------------------------------  // acclient.c:784999
void _E107_17()
{
  dbl_8441A0 = 1.0 / 5.0;
}

//----- (006FCAB0) --------------------------------------------------------  // acclient.c:785005
int sub_6FCAB0()
{
  return atexit(nullsub_1097);
}

