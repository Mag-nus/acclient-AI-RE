/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSpell
   Object     : AC\accspells\CSpell.obj
   Functions  : 19
   Addresses  : 00423E90 - 0070ADC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00423E90) --------------------------------------------------------  // acclient.c:95825
BOOL __thiscall EnumPropertyValue::HasValidData(MetaSpell *this)
{
  return this->_spell != 0;
}

//----- (004F0EA0) --------------------------------------------------------  // acclient.c:285129
int __stdcall InfoRegion::GetVitaeModifier(Enchantment *e)
{
  return 0;
}

//----- (005985A0) --------------------------------------------------------  // acclient.c:450477
void __cdecl Spell::BuildSpell(SpellType sp_type)
{
  EnchantmentSpell *v1; // eax@2
  ProjectileSpell *v2; // eax@4
  BoostSpell *v3; // eax@6
  TransferSpell *v4; // eax@8
  PortalSendingSpell *v5; // eax@10
  PortalSendingSpell *v6; // eax@12
  PortalSummonSpell *v7; // eax@14
  PortalSendingSpell *v8; // eax@16
  DispelSpell *v9; // eax@18
  ProjectileLifeSpell *v10; // eax@20
  ProjectileEnchantmentSpell *v11; // eax@22
  FellowshipBoostSpell *v12; // eax@24
  FellowshipEnchantmentSpell *v13; // eax@26
  FellowshipPortalSendingSpell *v14; // eax@28
  FellowshipDispelSpell *v15; // eax@30

  switch ( sp_type )
  {
    case 1:
      v1 = (EnchantmentSpell *)operator new(0x58u);
      if ( v1 )
        EnchantmentSpell::EnchantmentSpell(v1);
      break;
    case 2:
      v2 = (ProjectileSpell *)operator new(8u);
      if ( v2 )
        ProjectileSpell::ProjectileSpell(v2);
      break;
    case 3:
      v3 = (BoostSpell *)operator new(8u);
      if ( v3 )
        BoostSpell::BoostSpell(v3);
      break;
    case 4:
      v4 = (TransferSpell *)operator new(8u);
      if ( v4 )
        TransferSpell::TransferSpell(v4);
      break;
    case 5:
      v5 = (PortalSendingSpell *)operator new(8u);
      if ( v5 )
        PortalSendingSpell::PortalSendingSpell(v5);
      break;
    case 6:
      v6 = (PortalSendingSpell *)operator new(8u);
      if ( v6 )
        PortalSendingSpell::PortalSendingSpell(v6);
      break;
    case 7:
      v7 = (PortalSummonSpell *)operator new(0x10u);
      if ( v7 )
        PortalSummonSpell::PortalSummonSpell(v7);
      break;
    case 8:
      v8 = (PortalSendingSpell *)operator new(8u);
      if ( v8 )
        PortalSendingSpell::PortalSendingSpell(v8);
      break;
    case 9:
      v9 = (DispelSpell *)operator new(8u);
      if ( v9 )
        DispelSpell::DispelSpell(v9);
      break;
    case 10:
      v10 = (ProjectileLifeSpell *)operator new(8u);
      if ( v10 )
        ProjectileLifeSpell::ProjectileLifeSpell(v10);
      break;
    case 15:
      v11 = (ProjectileEnchantmentSpell *)operator new(8u);
      if ( v11 )
        ProjectileEnchantmentSpell::ProjectileEnchantmentSpell(v11);
      break;
    case 11:
      v12 = (FellowshipBoostSpell *)operator new(8u);
      if ( v12 )
        FellowshipBoostSpell::FellowshipBoostSpell(v12);
      break;
    case 12:
      v13 = (FellowshipEnchantmentSpell *)operator new(0x58u);
      if ( v13 )
        FellowshipEnchantmentSpell::FellowshipEnchantmentSpell(v13);
      break;
    case 13:
      v14 = (FellowshipPortalSendingSpell *)operator new(8u);
      if ( v14 )
        FellowshipPortalSendingSpell::FellowshipPortalSendingSpell(v14);
      break;
    case 14:
      v15 = (FellowshipDispelSpell *)operator new(8u);
      if ( v15 )
        FellowshipDispelSpell::FellowshipDispelSpell(v15);
      break;
    default:
      return;
  }
}

//----- (00598760) --------------------------------------------------------  // acclient.c:450578
int __thiscall Spell::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  return result;
}

//----- (00598770) --------------------------------------------------------  // acclient.c:450588
void __thiscall MetaSpell::MetaSpell(MetaSpell *this)
{
  this->vfptr = (PackObjVtbl *)&MetaSpell::vftable;
  this->_sp_type = 0;
  this->_spell = 0;
}
// 7E4988: using guessed type int (__thiscall *MetaSpell::vftable)(void *, char);

//----- (00598790) --------------------------------------------------------  // acclient.c:450597
double __thiscall MetaSpell::InqDuration(MetaSpell *this)
{
  Spell *v1; // ecx@1
  double result; // st7@3

  v1 = this->_spell;
  if ( v1 )
    ((void (*)(void))v1->vfptr[1].GetPackSize)();
  else
    result = -1.0;
  return result;
}

//----- (005987B0) --------------------------------------------------------  // acclient.c:450611
int __thiscall MetaSpell::Pack(MetaSpell *this, void **addr, unsigned int size)
{
  MetaSpell *v3; // edi@1
  Spell *v4; // ecx@1
  int v5; // eax@2
  int v6; // esi@4
  Spell *v7; // ecx@5
  MetaSpell *v9; // [sp+0h] [bp-4h]@1

  v9 = this;
  v3 = this;
  v4 = this->_spell;
  v9 = 0;
  if ( v4 )
    v5 = ((int (__stdcall *)(int *, _DWORD))v4->vfptr->Pack)(&v9, 0);
  else
    v5 = 0;
  v6 = v5 + 4;
  if ( size >= v5 + 4 )
  {
    *(_DWORD *)*addr = v3->_sp_type;
    *addr = (char *)*addr + 4;
    v7 = v3->_spell;
    if ( v7 )
      ((void (__stdcall *)(void **, unsigned int))v7->vfptr->Pack)(addr, size);
  }
  return v6;
}

//----- (00598810) --------------------------------------------------------  // acclient.c:450641
void __thiscall MetaSpell::UnPack(MetaSpell *this, void **addr, unsigned int size)
{
  MetaSpell *v3; // esi@1
  Spell *v4; // ecx@2
  Spell *v5; // eax@4

  v3 = this;
  if ( size >= 4 )
  {
    v4 = this->_spell;
    if ( v4 )
    {
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      v3->_spell = 0;
    }
    v3->_sp_type = 0;
    v3->_sp_type = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    Spell::BuildSpell(v3->_sp_type);
    v3->_spell = v5;
    if ( v5 )
      ((void (__thiscall *)(Spell *, void **, unsigned int))v5->vfptr->UnPack)(v5, addr, size - 4);
  }
}

//----- (00598880) --------------------------------------------------------  // acclient.c:450667
void __thiscall Spell::Spell(Spell *this)
{
  this->vfptr = (PackObjVtbl *)&Spell::vftable;
  this->_spell_id = 0;
}
// 7E49A0: using guessed type int (__thiscall *Spell::vftable)(void *, char);

//----- (00598890) --------------------------------------------------------  // acclient.c:450675
double Spell::InqDuration()
{
  return -1.0;
}

//----- (005988A0) --------------------------------------------------------  // acclient.c:450681
unsigned int __thiscall Spell::Pack(Spell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  unsigned int result; // eax@1

  v3 = this;
  result = ((int (*)(void))this->vfptr[3].UnPack)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_spell_id;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (005988C0) --------------------------------------------------------  // acclient.c:450697
int __thiscall Spell::UnPack(Spell *this, void **addr, unsigned int size)
{
  Spell *v3; // esi@1
  int result; // eax@2

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr[3].UnPack)() )
  {
    v3->_spell_id = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005988F0) --------------------------------------------------------  // acclient.c:450717
void __thiscall MetaSpell::~MetaSpell(MetaSpell *this)
{
  MetaSpell *v1; // esi@1
  Spell *v2; // ecx@1

  v1 = this;
  v2 = this->_spell;
  v1->vfptr = (PackObjVtbl *)&MetaSpell::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_spell = 0;
  }
  v1->_sp_type = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4988: using guessed type int (__thiscall *MetaSpell::vftable)(void *, char);

//----- (00598920) --------------------------------------------------------  // acclient.c:450737
int __thiscall MetaSpell::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@1
  SpellType v4; // eax@3
  int v5; // eax@4
  int result; // eax@4

  v2 = this;
  v3 = *(_DWORD *)(this + 8);
  if ( v3 )
  {
    (**(void (__stdcall ***)(_DWORD))v3)(1);
    *(_DWORD *)(v2 + 8) = 0;
  }
  *(_DWORD *)(v2 + 4) = 0;
  v4 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v2 + 4) = v4;
  if ( v4 )
  {
    Spell::BuildSpell(v4);
    *(_DWORD *)(v2 + 8) = v5;
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v5 + 24))(v5, v5, *(_DWORD *)(a2 + 8));
    result = v2;
  }
  else
  {
    *(_DWORD *)(v2 + 8) = 0;
    result = v2;
  }
  return result;
}

//----- (00598980) --------------------------------------------------------  // acclient.c:450771
MetaSpell *__thiscall MetaSpell::vector_deleting_destructor(MetaSpell *this, unsigned int a2)
{
  MetaSpell *v2; // esi@1
  Spell *v3; // ecx@1

  v2 = this;
  v3 = this->_spell;
  v2->vfptr = (PackObjVtbl *)&MetaSpell::vftable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->_spell = 0;
  }
  v2->_sp_type = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4988: using guessed type int (__thiscall *MetaSpell::vftable)(void *, char);

//----- (0070AD60) --------------------------------------------------------  // acclient.c:798044
void sub_70AD60()
{
  flt_87109C = 1000.0 + 1.0;
}

//----- (0070AD80) --------------------------------------------------------  // acclient.c:798050
void sub_70AD80()
{
  flt_8710A0 = 24.0 * 8.0;
}

//----- (0070ADA0) --------------------------------------------------------  // acclient.c:798056
void sub_70ADA0()
{
  flt_8710A4 = 24.0 * 0.5;
}

//----- (0070ADC0) --------------------------------------------------------  // acclient.c:798062
int sub_70ADC0()
{
  return atexit(nullsub_1426);
}

