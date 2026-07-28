/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceNode
   Object     : AC\acallegiance\AllegianceNode.obj
   Functions  : 4
   Addresses  : 005B8FF0 - 005B9040 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B8FF0) --------------------------------------------------------  // acclient.c:483735
int __thiscall AllegianceNode::Pack(AllegianceNode *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(_DWORD, _DWORD))this->_data.vfptr->Pack)(addr, size);
}

//----- (005B9000) --------------------------------------------------------  // acclient.c:483741
int __thiscall AllegianceNode::UnPack(AllegianceNode *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(void **, unsigned int))this->_data.vfptr->UnPack)(addr, size);
}

//----- (005B9010) --------------------------------------------------------  // acclient.c:483747
void __thiscall AllegianceNode::AllegianceNode(AllegianceNode *this, AllegianceData *data)
{
  this->_patron = 0;
  this->_peer = 0;
  this->_vassal = 0;
  this->vfptr = (PackObjVtbl *)&AllegianceNode::vftable;
  AllegianceData::AllegianceData(&this->_data, data);
}
// 7E71CC: using guessed type int (__thiscall *AllegianceNode::vftable)(void *, char);

//----- (005B9040) --------------------------------------------------------  // acclient.c:483758
AllegianceNode *__thiscall AllegianceNode::scalar_deleting_destructor(AllegianceNode *this, unsigned int a2)
{
  AllegianceNode *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&AllegianceNode::vftable;
  AllegianceData::~AllegianceData(&this->_data);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E71CC: using guessed type int (__thiscall *AllegianceNode::vftable)(void *, char);

