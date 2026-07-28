/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPortalSendingSpell
   Object     : AC\accspells\CPortalSendingSpell.obj
   Functions  : 8
   Addresses  : 00598A90 - 0070AE30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598A90) --------------------------------------------------------  // acclient.c:450849
int __thiscall BoostSpell::UnPack(PortalSendingSpell *this, void **addr, unsigned int size)
{
  Spell *v3; // edi@1
  int result; // eax@2
  void *v5; // ebx@3

  v3 = (Spell *)this;
  if ( size >= ((int (*)(void))this->vfptr[3].UnPack)() )
  {
    v5 = *addr;
    result = Spell::UnPack(v3, addr, size);
    if ( result )
      result = 1;
    else
      *addr = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00598AD0) --------------------------------------------------------  // acclient.c:450873
void __thiscall PortalSendingSpell::PortalSendingSpell(PortalSendingSpell *this)
{
  PortalSendingSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&PortalSendingSpell::vftable;
}
// 7E4E00: using guessed type int (__thiscall *PortalSendingSpell::vftable)(void *, char);

//----- (00598AF0) --------------------------------------------------------  // acclient.c:450884
void __thiscall FellowshipPortalSendingSpell::FellowshipPortalSendingSpell(FellowshipPortalSendingSpell *this)
{
  FellowshipPortalSendingSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&FellowshipPortalSendingSpell::vftable;
}
// 7E4AD8: using guessed type int (__thiscall *FellowshipPortalSendingSpell::vftable)(void *, char);

//----- (00599020) --------------------------------------------------------  // acclient.c:451259
void __stdcall PortalRecallSpell::SetEqual(Spell *dst, Spell *src)
{
  if ( dst )
  {
    if ( src )
      Spell::operator=((int)dst, (int)src);
  }
}

//----- (0070ADD0) --------------------------------------------------------  // acclient.c:798068
void sub_70ADD0()
{
  flt_8710BC = 1000.0 + 1.0;
}

//----- (0070ADF0) --------------------------------------------------------  // acclient.c:798074
void sub_70ADF0()
{
  flt_8710C0 = 24.0 * 8.0;
}

//----- (0070AE10) --------------------------------------------------------  // acclient.c:798080
void sub_70AE10()
{
  flt_8710C4 = 24.0 * 0.5;
}

//----- (0070AE30) --------------------------------------------------------  // acclient.c:798086
int sub_70AE30()
{
  return atexit(nullsub_1427);
}

