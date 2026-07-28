/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTriangleStrip
   Object     : PORTAL\ctristrip\CTriangleStrip.obj
   Functions  : 1
   Addresses  : 00534D30 - 00534D30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00534D30) --------------------------------------------------------  // acclient.c:356944
void __thiscall CTriangleStrip::~CTriangleStrip(CTriangleStrip *this)
{
  operator delete[](this->indices);
}

