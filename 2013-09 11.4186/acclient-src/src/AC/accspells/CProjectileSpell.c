/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CProjectileSpell
   Object     : AC\accspells\CProjectileSpell.obj
   Functions  : 7
   Addresses  : 00598DE0 - 00598F00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598DE0) --------------------------------------------------------  // acclient.c:451087
unsigned int __thiscall ProjectileLifeSpell::Pack(ProjectileEnchantmentSpell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  unsigned int v4; // edi@1

  v3 = (Spell *)this;
  v4 = ((int (*)(void))this->vfptr[3].UnPack)();
  if ( size >= v4 && size >= ((int (__thiscall *)(Spell *))v3->vfptr[3].UnPack)(v3) )
    Spell::Pack(v3, addr, size);
  return v4;
}

//----- (00598E20) --------------------------------------------------------  // acclient.c:451100
void __stdcall ProjectileEnchantmentSpell::SetEqual(Spell *dst, Spell *src)
{
  (*(void (__stdcall **)(_DWORD))&dst->vfptr[4].gap4[0])(src);
}

//----- (00598E40) --------------------------------------------------------  // acclient.c:451106
int __thiscall ProjectileEnchantmentSpell::UnPack(ProjectileEnchantmentSpell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  unsigned int v4; // ebx@1
  void *v6; // ebp@4
  void *sizea; // [sp+10h] [bp+8h]@3

  v3 = (Spell *)this;
  v4 = size;
  if ( size < ((int (*)(void))this->vfptr[3].UnPack)() )
    return 0;
  sizea = *addr;
  if ( v4 < ((int (__thiscall *)(Spell *))v3->vfptr[3].UnPack)(v3) )
    goto LABEL_6;
  v6 = *addr;
  if ( !Spell::UnPack(v3, addr, v4) )
  {
    *addr = v6;
LABEL_6:
    *addr = sizea;
    return 0;
  }
  return 1;
}

//----- (00598EA0) --------------------------------------------------------  // acclient.c:451132
int __thiscall ProjectileEnchantmentSpell::BuildEnchantment(ProjectileEnchantmentSpell *this, Enchantment *e)
{
  unsigned int v2; // ecx@1

  v2 = this->_spell_id;
  LOWORD(e->_id) = 0;
  e->_id |= v2;
  return 1;
}

//----- (00598EC0) --------------------------------------------------------  // acclient.c:451143
void __thiscall ProjectileSpell::ProjectileSpell(ProjectileSpell *this)
{
  ProjectileSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&ProjectileSpell::vftable;
}
// 7E4C98: using guessed type int (__thiscall *ProjectileSpell::vftable)(void *, char);

//----- (00598EE0) --------------------------------------------------------  // acclient.c:451154
void __thiscall ProjectileLifeSpell::ProjectileLifeSpell(ProjectileLifeSpell *this)
{
  ProjectileLifeSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&ProjectileLifeSpell::vftable;
}
// 7E4CF0: using guessed type int (__thiscall *ProjectileLifeSpell::vftable)(void *, char);

//----- (00598F00) --------------------------------------------------------  // acclient.c:451165
void __thiscall ProjectileEnchantmentSpell::ProjectileEnchantmentSpell(ProjectileEnchantmentSpell *this)
{
  ProjectileEnchantmentSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&ProjectileEnchantmentSpell::vftable;
}
// 7E4D48: using guessed type int (__thiscall *ProjectileEnchantmentSpell::vftable)(void *, char);

