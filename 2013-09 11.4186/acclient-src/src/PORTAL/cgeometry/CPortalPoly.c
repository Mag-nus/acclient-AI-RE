/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPortalPoly
   Object     : PORTAL\cgeometry\CPortalPoly.obj
   Functions  : 2
   Addresses  : 0053DF70 - 0053DF80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053DF70) --------------------------------------------------------  // acclient.c:364954
void __thiscall CPortalPoly::CPortalPoly(CPortalPoly *this)
{
  this->portal_index = -1;
  this->portal = 0;
}

//----- (0053DF80) --------------------------------------------------------  // acclient.c:364961
void __thiscall CPortalPoly::~CPortalPoly(CPortalPoly *this)
{
  this->portal = 0;
  this->portal_index = -1;
}

