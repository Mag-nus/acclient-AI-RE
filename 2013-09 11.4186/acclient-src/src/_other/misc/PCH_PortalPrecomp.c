/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PCH_PortalPrecomp
   Object     : _other\misc\PCH_PortalPrecomp.obj
   Functions  : 9
   Addresses  : 006C2B70 - 006C2C30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C2B70) --------------------------------------------------------  // acclient.c:731212
int _E1()
{
  return atexit(_E2);
}

//----- (006C2B80) --------------------------------------------------------  // acclient.c:731218
int _E4()
{
  return atexit(_E5);
}

//----- (006C2B90) --------------------------------------------------------  // acclient.c:731224
int _E7()
{
  Outside_CellID.id = Invalid_CellID.id + 1;
  return atexit(_E8);
}

//----- (006C2BB0) --------------------------------------------------------  // acclient.c:731231
int _E10()
{
  In_Limbo_CellID.id = Outside_CellID.id + 1;
  return atexit(_E11);
}

//----- (006C2BD0) --------------------------------------------------------  // acclient.c:731238
int _E13()
{
  First_Interior_CellID.id = In_Limbo_CellID.id + 1;
  return atexit(_E14);
}

//----- (006C2BF0) --------------------------------------------------------  // acclient.c:731245
int _E16()
{
  Last_Interior_CellID.id = Invalid_CellID.id - 1;
  return atexit(_E17);
}

//----- (006C2C10) --------------------------------------------------------  // acclient.c:731252
int _E21()
{
  return atexit(_E22);
}

//----- (006C2C20) --------------------------------------------------------  // acclient.c:731258
int _E40()
{
  return atexit(_E41);
}

//----- (006C2C30) --------------------------------------------------------  // acclient.c:731264
int _E43()
{
  return atexit(_E44);
}

