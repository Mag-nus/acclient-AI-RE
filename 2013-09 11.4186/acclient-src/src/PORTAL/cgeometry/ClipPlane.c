/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClipPlane
   Object     : PORTAL\cgeometry\ClipPlane.obj
   Functions  : 2
   Addresses  : 00534D40 - 00534D50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00534D40) --------------------------------------------------------  // acclient.c:356950
void __thiscall ClipPlane::ClipPlane(ClipPlane *this)
{
  this->plane = 0;
}

//----- (00534D50) --------------------------------------------------------  // acclient.c:356956
void __thiscall ClipPlane::ClipPlane(ClipPlane *this, Plane *_plane, Sidedness _side)
{
  this->plane = _plane;
  this->side = _side;
}

