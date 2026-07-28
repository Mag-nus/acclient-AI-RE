/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEnchantmentSpell
   Object     : AC\accspells\CEnchantmentSpell.obj
   Functions  : 9
   Addresses  : 00598B10 - 00598D60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598B10) --------------------------------------------------------  // acclient.c:450895
int __thiscall EnchantmentSpell::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  Spell::operator=(this, a2);
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
  return v2;
}

//----- (00598BA0) --------------------------------------------------------  // acclient.c:450924
int __thiscall EnchantmentSpell::BuildEnchantment(EnchantmentSpell *this, Enchantment *e)
{
  unsigned int v2; // edx@1

  v2 = this->_spell_id;
  LOWORD(e->_id) = 0;
  e->_id |= v2;
  e->_degrade_modifier = this->_degrade_modifier;
  e->_degrade_limit = this->_degrade_limit;
  e->_duration = this->_duration;
  return 1;
}

//----- (00598BE0) --------------------------------------------------------  // acclient.c:450938
int EnchantmentSpell::pack_size()
{
  return EtherealHook::pack_size() + 16;
}

//----- (00598BF0) --------------------------------------------------------  // acclient.c:450944
void __thiscall EnchantmentSpell::EnchantmentSpell(EnchantmentSpell *this)
{
  EnchantmentSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  LODWORD(v1->_duration) = 0;
  v1->vfptr = (PackObjVtbl *)&EnchantmentSpell::vftable;
  HIDWORD(v1->_duration) = -1074790400;
  LODWORD(v1->_degrade_modifier) = 0;
  v1->_degrade_limit = INVALID_ENCHANTMENT_DEGRADE_LIMIT;
}
// 7E4B38: using guessed type int (__thiscall *EnchantmentSpell::vftable)(void *, char);

//----- (00598C40) --------------------------------------------------------  // acclient.c:450965
int __thiscall EnchantmentSpell::SetDuration(EnchantmentSpell *this, const long double d)
{
  this->_duration = d;
  return 1;
}

//----- (00598C60) --------------------------------------------------------  // acclient.c:450972
void __stdcall EnchantmentSpell::SetEqual(Spell *dst, Spell *src)
{
  EnchantmentSpell::operator=((int)dst, (int)src);
}

//----- (00598C80) --------------------------------------------------------  // acclient.c:450978
unsigned int __thiscall EnchantmentSpell::Pack(EnchantmentSpell *this, void **addr, unsigned int size)
{
  EnchantmentSpell *v3; // edi@1
  unsigned int v4; // ebx@1
  char *v5; // edx@2
  char *v6; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr[3].UnPack)();
  if ( size >= v4 )
  {
    Spell::Pack((Spell *)&v3->vfptr, addr, size);
    *(double *)*addr = v3->_duration;
    v5 = (char *)*addr + 8;
    *addr = v5;
    *(float *)v5 = v3->_degrade_modifier;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->_degrade_limit;
    *addr = (char *)*addr + 4;
  }
  return v4;
}

//----- (00598CD0) --------------------------------------------------------  // acclient.c:451003
int __thiscall EnchantmentSpell::UnPack(EnchantmentSpell *this, void **addr, unsigned int size)
{
  EnchantmentSpell *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  int result; // eax@2
  void *v6; // ebx@3
  void *v7; // ecx@5
  char *v8; // edx@5
  char *v9; // ecx@5

  v3 = this;
  LODWORD(this->_duration) = 0;
  v4 = this->vfptr;
  HIDWORD(this->_duration) = -1074790400;
  LODWORD(this->_degrade_modifier) = 0;
  this->_degrade_limit = INVALID_ENCHANTMENT_DEGRADE_LIMIT;
  if ( size >= ((int (*)(void))v4[3].UnPack)() )
  {
    v6 = *addr;
    result = Spell::UnPack((Spell *)&v3->vfptr, addr, size);
    if ( result )
    {
      v7 = *addr;
      LODWORD(v3->_duration) = *(_DWORD *)*addr;
      HIDWORD(v3->_duration) = *((_DWORD *)v7 + 1);
      v8 = (char *)*addr + 8;
      *addr = v8;
      LODWORD(v3->_degrade_modifier) = *(_DWORD *)v8;
      v9 = (char *)*addr + 4;
      *addr = v9;
      LODWORD(v3->_degrade_limit) = *(_DWORD *)v9;
      *addr = (char *)*addr + 4;
      result = 1;
    }
    else
    {
      *addr = v6;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00598D60) --------------------------------------------------------  // acclient.c:451050
void __thiscall FellowshipEnchantmentSpell::FellowshipEnchantmentSpell(FellowshipEnchantmentSpell *this)
{
  FellowshipEnchantmentSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  LODWORD(v1->_duration) = 0;
  HIDWORD(v1->_duration) = -1074790400;
  LODWORD(v1->_degrade_modifier) = 0;
  v1->_degrade_limit = INVALID_ENCHANTMENT_DEGRADE_LIMIT;
  v1->vfptr = (PackObjVtbl *)&FellowshipEnchantmentSpell::vftable;
}
// 7E4B88: using guessed type int (__thiscall *FellowshipEnchantmentSpell::vftable)(void *, char);

