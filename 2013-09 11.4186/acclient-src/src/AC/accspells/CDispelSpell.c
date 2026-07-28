/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CDispelSpell
   Object     : AC\accspells\CDispelSpell.obj
   Functions  : 5
   Addresses  : 005989D0 - 00598A70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005989D0) --------------------------------------------------------  // acclient.c:450794
unsigned int __thiscall DispelSpell::Pack(DispelSpell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  unsigned int v4; // edi@1

  v3 = (Spell *)this;
  v4 = ((int (*)(void))this->vfptr[3].UnPack)();
  if ( size >= v4 )
    Spell::Pack(v3, addr, size);
  return v4;
}

//----- (00598A00) --------------------------------------------------------  // acclient.c:450807
int __thiscall DispelSpell::UnPack(DispelSpell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  int result; // eax@2

  v3 = (Spell *)this;
  if ( size >= ((int (*)(void))this->vfptr[3].UnPack)() )
    result = Spell::UnPack(v3, addr, size) != 0;
  else
    result = 0;
  return result;
}

//----- (00598A30) --------------------------------------------------------  // acclient.c:450821
void __thiscall DispelSpell::DispelSpell(DispelSpell *this)
{
  DispelSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&DispelSpell::vftable;
}
// 7E49F8: using guessed type int (__thiscall *DispelSpell::vftable)(void *, char);

//----- (00598A50) --------------------------------------------------------  // acclient.c:450832
void __stdcall DispelSpell::SetEqual(Spell *dst, Spell *src)
{
  Spell::operator=((int)dst, (int)src);
}

//----- (00598A70) --------------------------------------------------------  // acclient.c:450838
void __thiscall FellowshipDispelSpell::FellowshipDispelSpell(FellowshipDispelSpell *this)
{
  FellowshipDispelSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&FellowshipDispelSpell::vftable;
}
// 7E4A48: using guessed type int (__thiscall *FellowshipDispelSpell::vftable)(void *, char);

