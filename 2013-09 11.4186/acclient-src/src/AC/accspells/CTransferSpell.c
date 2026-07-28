/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTransferSpell
   Object     : AC\accspells\CTransferSpell.obj
   Functions  : 1
   Addresses  : 00599080 - 00599080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00599080) --------------------------------------------------------  // acclient.c:451285
void __thiscall TransferSpell::TransferSpell(TransferSpell *this)
{
  TransferSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&TransferSpell::vftable;
}
// 7E4E60: using guessed type int (__thiscall *TransferSpell::vftable)(void *, char);

