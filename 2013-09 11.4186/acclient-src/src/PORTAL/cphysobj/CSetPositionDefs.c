/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSetPositionDefs
   Object     : PORTAL\cphysobj\CSetPositionDefs.obj
   Functions  : 7
   Addresses  : 0051BB40 - 006FCB20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051BB40) --------------------------------------------------------  // acclient.c:329725
void __thiscall SetPositionStruct::SetFlags(SetPositionStruct *this, const unsigned int new_flags)
{
  this->flags = new_flags;
}

//----- (0051BB50) --------------------------------------------------------  // acclient.c:329731
void __thiscall SetPositionStruct::SetPositionStruct(SetPositionStruct *this)
{
  SetPositionStruct *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->pos.frame;
  v1->pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->flags = 0;
  LODWORD(v1->line.x) = 0;
  LODWORD(v1->line.y) = 0;
  LODWORD(v1->line.z) = 0;
  LODWORD(v1->xrad) = 0;
  LODWORD(v1->yrad) = 0;
  v1->num_tries = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0051BBA0) --------------------------------------------------------  // acclient.c:329759
void __thiscall SetPositionStruct::SetPosition(SetPositionStruct *this, Position *new_pos)
{
  this->pos.objcell_id = new_pos->objcell_id;
  Frame::operator=((int)&this->pos.frame, (int)&new_pos->frame);
}

//----- (006FCAC0) --------------------------------------------------------  // acclient.c:785011
void sub_6FCAC0()
{
  flt_8441B8 = 1000.0 + 1.0;
}

//----- (006FCAE0) --------------------------------------------------------  // acclient.c:785017
void sub_6FCAE0()
{
  flt_8441BC = 24.0 * 8.0;
}

//----- (006FCB00) --------------------------------------------------------  // acclient.c:785023
void sub_6FCB00()
{
  flt_8441C0 = 24.0 * 0.5;
}

//----- (006FCB20) --------------------------------------------------------  // acclient.c:785029
int sub_6FCB20()
{
  return atexit(nullsub_1106);
}

