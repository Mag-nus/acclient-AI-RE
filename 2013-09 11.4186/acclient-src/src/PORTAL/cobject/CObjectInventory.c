/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CObjectInventory
   Object     : PORTAL\cobject\CObjectInventory.obj
   Functions  : 3
   Addresses  : 006B4C80 - 006B4D20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B4C80) --------------------------------------------------------  // acclient.c:718594
void __thiscall CObjectInventory::CObjectInventory(CObjectInventory *this, unsigned int _objectID)
{
  CObjectInventory *v2; // esi@1

  v2 = this;
  this->hash_next = 0;
  this->id = _objectID;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&CObjectInventory::vftable;
  IDList::IDList(&this->_itemsList);
  IDList::IDList(&v2->_containersList);
  v2->_invPlacement.head = 0;
  v2->_invPlacement.tail = 0;
  v2->_invPlacement.curNum = 0;
  v2->_invPlacement.vfptr = (PackObjVtbl *)&PackableList<InventoryPlacement>::vftable;
}
// 7CC790: using guessed type int (__thiscall *PackableList<InventoryPlacement>::vftable)(void *, char);
// 8061FC: using guessed type int (__thiscall *CObjectInventory::vftable)(void *, char);

//----- (006B4CC0) --------------------------------------------------------  // acclient.c:718613
void __thiscall CObjectInventory::~CObjectInventory(CObjectInventory *this)
{
  CObjectInventory *v1; // esi@1
  IDList *v2; // ebx@1
  int v3; // edi@1

  v1 = this;
  v2 = &this->_itemsList;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&CObjectInventory::vftable;
  IDList::Clear(&this->_itemsList);
  IDList::Clear(&v1->_containersList);
  v3 = (int)&v1->_invPlacement;
  PackableList<InventoryPlacement>::Flush(&v1->_invPlacement);
  *(_DWORD *)v3 = &PackableList<InventoryPlacement>::vftable;
  PackableList<InventoryPlacement>::Flush(&v1->_invPlacement);
  *(_DWORD *)v3 = &PackObj::vftable;
  IDList::~IDList(&v1->_containersList);
  IDList::~IDList(v2);
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  v1->hash_next = 0;
  v1->id = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7CC790: using guessed type int (__thiscall *PackableList<InventoryPlacement>::vftable)(void *, char);
// 8061FC: using guessed type int (__thiscall *CObjectInventory::vftable)(void *, char);

//----- (006B4D20) --------------------------------------------------------  // acclient.c:718641
CObjectInventory *__thiscall CObjectInventory::vector_deleting_destructor(CObjectInventory *this, unsigned int a2)
{
  CObjectInventory *v2; // esi@1

  v2 = this;
  CObjectInventory::~CObjectInventory(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

