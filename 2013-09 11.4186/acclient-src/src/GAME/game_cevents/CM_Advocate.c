/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Advocate
   Object     : GAME\game_cevents\CM_Advocate.obj
   Functions  : 5
   Addresses  : 006A83C0 - 00722190 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A83C0) --------------------------------------------------------  // acclient.c:705092
bool __cdecl CM_Advocate::Event_Teleport(AC1Legacy::PStringBase<char> *i_target, Position *i_dest)
{
  int v2; // esi@1
  int v3; // esi@1
  int v4; // esi@1
  char *v5; // ebx@1
  unsigned int v6; // ST04_4@1
  bool v7; // bl@1
  void *buf; // [sp+10h] [bp-Ch]@1
  OrderHdr hdr; // [sp+14h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_target, &buf, 0);
  v3 = ((int (__thiscall *)(Position *, void **, _DWORD))i_dest->vfptr->Pack)(i_dest, &buf, 0) + v2;
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v4);
  v5 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 214;
  v6 = v4 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_target, &buf, v6);
  ((void (__thiscall *)(Position *, void **, int))i_dest->vfptr->Pack)(i_dest, &buf, v4 + v5 - (_BYTE *)buf);
  v7 = Proto_UI::SendToWeenie(v5, v4);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (00722130) --------------------------------------------------------  // acclient.c:819861
void sub_722130()
{
  flt_8FA0A8 = 1000.0 + 1.0;
}

//----- (00722150) --------------------------------------------------------  // acclient.c:819867
void sub_722150()
{
  flt_8FA0AC = 24.0 * 8.0;
}

//----- (00722170) --------------------------------------------------------  // acclient.c:819873
void sub_722170()
{
  flt_8FA0B0 = 24.0 * 0.5;
}

//----- (00722190) --------------------------------------------------------  // acclient.c:819879
int sub_722190()
{
  return atexit(nullsub_371);
}

