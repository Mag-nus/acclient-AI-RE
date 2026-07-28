/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBoostSpell
   Object     : AC\accspells\CBoostSpell.obj
   Functions  : 4
   Addresses  : 00598DA0 - 00599060 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598DA0) --------------------------------------------------------  // acclient.c:451065
void __thiscall BoostSpell::BoostSpell(BoostSpell *this)
{
  BoostSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&BoostSpell::vftable;
}
// 7E4BE0: using guessed type int (__thiscall *BoostSpell::vftable)(void *, char);

//----- (00598DC0) --------------------------------------------------------  // acclient.c:451076
void __thiscall FellowshipBoostSpell::FellowshipBoostSpell(FellowshipBoostSpell *this)
{
  FellowshipBoostSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&FellowshipBoostSpell::vftable;
}
// 7E4C38: using guessed type int (__thiscall *FellowshipBoostSpell::vftable)(void *, char);

//----- (00599040) --------------------------------------------------------  // acclient.c:451269
void __stdcall BoostSpell::SetEqual(Spell *dst, Spell *src)
{
  ((void (__stdcall *)(_DWORD))dst->vfptr[4].__vecDelDtor)(src);
}

//----- (00599060) --------------------------------------------------------  // acclient.c:451275
int __thiscall TransferSpell::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  Spell::operator=(this, a2);
  return v2;
}

