/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ShortCutData
   Object     : AC\acplayermod\ShortCutData.obj
   Functions  : 5
   Addresses  : 005C9830 - 005D5620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C9830) --------------------------------------------------------  // acclient.c:500635
ShortCutData *__thiscall PackObj::scalar_deleting_destructor(ShortCutData *this, unsigned int a2)
{
  ShortCutData *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005CABB0) --------------------------------------------------------  // acclient.c:502276
signed int __thiscall InventoryPlacement::Pack(ShortCutData *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2

  if ( size >= 0xC )
  {
    *(_DWORD *)*addr = this->index_;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->objectID_;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->spellID_;
    *addr = (char *)*addr + 4;
  }
  return 12;
}

//----- (005D55E0) --------------------------------------------------------  // acclient.c:513983
void __thiscall ShortCutData::ShortCutData(ShortCutData *this, int index, unsigned int objectID, unsigned int spellID)
{
  this->index_ = index;
  this->vfptr = (PackObjVtbl *)&CShortCutData::vftable;
  this->objectID_ = objectID;
  this->spellID_ = spellID;
}
// 7E8A7C: using guessed type int (__thiscall *CShortCutData::vftable)(void *, char);

//----- (005D5600) --------------------------------------------------------  // acclient.c:513993
void __thiscall ShortCutData::ShortCutData(ShortCutData *this)
{
  this->vfptr = (PackObjVtbl *)&CShortCutData::vftable;
  this->index_ = 0;
  this->objectID_ = 0;
  this->spellID_ = 0;
}
// 7E8A7C: using guessed type int (__thiscall *CShortCutData::vftable)(void *, char);

//----- (005D5620) --------------------------------------------------------  // acclient.c:514003
int __thiscall StatMod::UnPack(ShortCutData *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // edx@3

  if ( size >= 0xC )
  {
    this->index_ = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    this->objectID_ = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->spellID_ = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

