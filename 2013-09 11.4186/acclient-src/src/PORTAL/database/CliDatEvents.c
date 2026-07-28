/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CliDatEvents
   Object     : PORTAL\database\CliDatEvents.obj
   Functions  : 5
   Addresses  : 005563B0 - 0070D330 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005563B0) --------------------------------------------------------  // acclient.c:389609
CCliDatEvent *__thiscall CCliDatEvent::vector_deleting_destructor(CCliDatEvent *this, unsigned int a2)
{
  CCliDatEvent *v2; // esi@1

  v2 = this;
  NetBlob::~NetBlob((NetBlob *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005A71E0) --------------------------------------------------------  // acclient.c:464241
void __thiscall CCliDatEvent::CCliDatEvent(CCliDatEvent *this, char *pData, int DataLen)
{
  CCliDatEvent *v3; // esi@1

  v3 = this;
  NetBlob::NetBlob((NetBlob *)&this->vfptr, pData, DataLen, 5);
  v3->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)CChatEvent::vftable;
  v3->vfptr = (PackObjVtbl *)&CChatEvent::vftable;
  v3->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&CChatEvent::vftable;
}
// 7E5A10: using guessed type void *CChatEvent::vftable;
// 7E5A14: using guessed type void *CChatEvent::vftable;
// 7E5A28: using guessed type int (__thiscall *CChatEvent::vftable[4])(void *, char);

//----- (005A7210) --------------------------------------------------------  // acclient.c:464256
CCliDatEvent *__thiscall CChatEvent::vector_deleting_destructor(CCliDatEvent *this, unsigned int a2)
{
  return CCliDatEvent::vector_deleting_destructor((CCliDatEvent *)((char *)this - 8), a2);
}

//----- (005A7220) --------------------------------------------------------  // acclient.c:464262
CCliDatEvent *__thiscall CCliDatEvent::vector_deleting_destructor(CCliDatEvent *this, unsigned int a2)
{
  return CCliDatEvent::vector_deleting_destructor((CCliDatEvent *)((char *)this - 16), a2);
}

//----- (0070D330) --------------------------------------------------------  // acclient.c:800019
int _E77_20()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_42;
  dword_8ED9BC = LOWEST_DATA_RATE_42;
  return result;
}

