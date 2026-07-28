/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Enchantment
   Object     : AC\acqualities\Enchantment.obj
   Functions  : 12
   Addresses  : 005CACE0 - 0070FFD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CACE0) --------------------------------------------------------  // acclient.c:502374
BOOL __thiscall Enchantment::Duel(Enchantment *this, Enchantment *challenger)
{
  int v2; // edx@1
  int v3; // eax@1

  v2 = this->_power_level;
  v3 = challenger->_power_level;
  return v2 > v3 || v2 == v3 && challenger->_start_time < this->_start_time;
}

//----- (005CAD10) --------------------------------------------------------  // acclient.c:502385
int __thiscall Enchantment::Enchant(Enchantment *this, float *value)
{
  unsigned int v2; // eax@1
  int result; // eax@2

  v2 = this->_smod.type;
  if ( SBYTE1(v2) >= 0 )
  {
    if ( BYTE1(v2) & 0x40 )
    {
      *value = this->_smod.val * *value;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    *value = this->_smod.val + *value;
    result = 1;
  }
  return result;
}

//----- (005CAD50) --------------------------------------------------------  // acclient.c:502412
int __thiscall Enchantment::Enchant(Enchantment *this, EnchantedQualityDetails *value)
{
  double v2; // st7@1
  unsigned int v3; // ecx@1
  int result; // eax@3

  v2 = this->_smod.val;
  v3 = this->_smod.type;
  if ( SBYTE1(v3) >= 0 )
  {
    if ( BYTE1(v3) & 0x40 )
    {
      if ( v2 <= 1.0 )
      {
        value->rValueDecreasingMultiplier = v2 * value->rValueDecreasingMultiplier;
        result = 1;
      }
      else
      {
        value->rValueIncreasingMultiplier = v2 * value->rValueIncreasingMultiplier;
        result = 1;
      }
    }
    else
    {
      result = 0;
    }
  }
  else if ( v2 <= 0.0 )
  {
    value->rValueDecreasingAdditive = v2 + value->rValueDecreasingAdditive;
    result = 1;
  }
  else
  {
    value->rValueIncreasingAdditive = v2 + value->rValueIncreasingAdditive;
    result = 1;
  }
  return result;
}

//----- (005CADC0) --------------------------------------------------------  // acclient.c:502454
int __thiscall Enchantment::GetPackSize(Enchantment *this)
{
  PackObjVtbl *v1; // eax@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this->_smod.vfptr;
  dummy = 0;
  return ((int (__thiscall *)(StatMod *, void **, _DWORD))v1->Pack)(&this->_smod, &dummy, 0) + 52;
}

//----- (005CADE0) --------------------------------------------------------  // acclient.c:502466
int __thiscall Enchantment::AffectsAttackSkills(Enchantment *this, unsigned int key)
{
  int result; // eax@3

  if ( BYTE2(this->_smod.type) & 1 )
  {
    switch ( key )
    {
      case 0x21u:
      case 0x22u:
      case 0x29u:
      case 0x2Bu:
      case 0x2Cu:
      case 0x2Du:
      case 0x2Eu:
      case 0x2Fu:
      case 0x31u:
        result = 1;
        break;
      default:
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (005CAE30) --------------------------------------------------------  // acclient.c:502498
int __thiscall Enchantment::AffectsDefenseSkills(Enchantment *this, unsigned int key)
{
  int result; // eax@3

  if ( this->_smod.type & 0x20000 )
  {
    switch ( key )
    {
      case 6u:
      case 7u:
      case 0xFu:
      case 0x30u:
        result = 1;
        break;
      default:
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (005CAEA0) --------------------------------------------------------  // acclient.c:502525
void __thiscall Enchantment::Enchantment(Enchantment *this)
{
  LODWORD(this->_start_time) = 0;
  LODWORD(this->_duration) = 0;
  this->_degrade_limit = INVALID_ENCHANTMENT_DEGRADE_LIMIT_0;
  HIDWORD(this->_start_time) = -1074790400;
  HIDWORD(this->_duration) = -1074790400;
  HIDWORD(this->_last_time_degraded) = -1074790400;
  this->vfptr = (PackObjVtbl *)&Enchantment::vftable;
  this->_id = 0;
  this->m_SpellSetID = 0;
  this->_spell_category = 0;
  this->_power_level = 0;
  this->_caster = 0;
  LODWORD(this->_degrade_modifier) = 0;
  LODWORD(this->_last_time_degraded) = 0;
  this->_smod.vfptr = (PackObjVtbl *)&StatMod::vftable;
  this->_smod.type = 0;
  this->_smod.key = 0;
  LODWORD(this->_smod.val) = 0;
}
// 7B19B8: using guessed type int (__thiscall *StatMod::vftable)(void *, char);
// 7B19CC: using guessed type int (__thiscall *Enchantment::vftable)(void *, char);

//----- (005CAF00) --------------------------------------------------------  // acclient.c:502550
void __thiscall Enchantment::Enchantment(Enchantment *this, const unsigned int spid)
{
  LODWORD(this->_start_time) = 0;
  LODWORD(this->_duration) = 0;
  this->_id = spid;
  this->_degrade_limit = INVALID_ENCHANTMENT_DEGRADE_LIMIT_0;
  HIDWORD(this->_start_time) = -1074790400;
  HIDWORD(this->_duration) = -1074790400;
  HIDWORD(this->_last_time_degraded) = -1074790400;
  this->vfptr = (PackObjVtbl *)&Enchantment::vftable;
  this->m_SpellSetID = 0;
  this->_spell_category = 0;
  this->_power_level = 0;
  this->_caster = 0;
  LODWORD(this->_degrade_modifier) = 0;
  LODWORD(this->_last_time_degraded) = 0;
  this->_smod.vfptr = (PackObjVtbl *)&StatMod::vftable;
  this->_smod.type = 0;
  this->_smod.key = 0;
  LODWORD(this->_smod.val) = 0;
}
// 7B19B8: using guessed type int (__thiscall *StatMod::vftable)(void *, char);
// 7B19CC: using guessed type int (__thiscall *Enchantment::vftable)(void *, char);

//----- (005CAF70) --------------------------------------------------------  // acclient.c:502575
unsigned int __thiscall Enchantment::Pack(Enchantment *this, void **addr, unsigned int size)
{
  Enchantment *v3; // edi@1
  unsigned int v4; // ebx@1
  char *v5; // eax@2
  char *v6; // ecx@2
  char *v7; // eax@2
  char *v8; // ecx@2
  char *v9; // eax@2
  char *v10; // ecx@2
  char *v11; // eax@2
  char *v12; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_spell_category & 0xFFFF | 0x10000;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_power_level;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(double *)v7 = v3->_start_time - COERCE_DOUBLE(Timer::cur_time.Cmd);
    v8 = (char *)*addr + 8;
    *addr = v8;
    *(double *)v8 = v3->_duration;
    v9 = (char *)*addr + 8;
    *addr = v9;
    *(_DWORD *)v9 = v3->_caster;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(float *)v10 = v3->_degrade_modifier;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(float *)v11 = v3->_degrade_limit;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(double *)v12 = v3->_last_time_degraded - COERCE_DOUBLE(Timer::cur_time.Cmd);
    *addr = (char *)*addr + 8;
    ((void (__stdcall *)(void **, unsigned int))v3->_smod.vfptr->Pack)(addr, size);
    *(_DWORD *)*addr = v3->m_SpellSetID;
    *addr = (char *)*addr + 4;
  }
  return v4;
}

//----- (005CB040) --------------------------------------------------------  // acclient.c:502626
int __thiscall Enchantment::UnPack(Enchantment *this, void **addr, unsigned int size)
{
  Enchantment *v3; // edi@1
  int result; // eax@2
  void **v5; // esi@3
  char *v6; // ebx@3
  char *v7; // eax@3
  unsigned int v8; // ebx@3
  char *v9; // eax@3
  void *v10; // ecx@3
  char *v11; // eax@3
  char *v12; // ecx@3
  char *v13; // eax@3
  char *v14; // ecx@3

  v3 = this;
  if ( size >= 0x30 )
  {
    v5 = addr;
    this->_id = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v7 = v6;
    v8 = *(_DWORD *)v6;
    *addr = v7 + 4;
    this->_spell_category = (unsigned __int16)v8;
    this->_power_level = *(_DWORD *)*addr;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_QWORD *)&this->_start_time = *(_QWORD *)v9;
    *v5 = (char *)*v5 + 8;
    this->_start_time = COERCE_DOUBLE(Timer::cur_time.Cmd) + this->_start_time;
    v10 = *addr;
    LODWORD(v3->_duration) = *(_DWORD *)*addr;
    HIDWORD(v3->_duration) = *((_DWORD *)v10 + 1);
    v11 = (char *)*addr + 8;
    *addr = v11;
    v3->_caster = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    LODWORD(v3->_degrade_modifier) = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    LODWORD(v3->_degrade_limit) = *(_DWORD *)v13;
    v14 = (char *)*addr + 4;
    *addr = v14;
    LODWORD(v3->_last_time_degraded) = *(_DWORD *)v14;
    HIDWORD(v3->_last_time_degraded) = *((_DWORD *)v14 + 1);
    *v5 = (char *)*v5 + 8;
    v3->_last_time_degraded = COERCE_DOUBLE(Timer::cur_time.Cmd) + v3->_last_time_degraded;
    result = ((int (__stdcall *)(void **, unsigned int))v3->_smod.vfptr->UnPack)(addr, size);
    if ( result )
    {
      if ( (signed int)(v8 >> 16) >= 1 )
      {
        v3->m_SpellSetID = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006AFEB0) --------------------------------------------------------  // acclient.c:713264
BOOL __thiscall ContentProfile::operator==(Enchantment *this, Enchantment *rhs)
{
  return this->_id == rhs->_id;
}

//----- (0070FFD0) --------------------------------------------------------  // acclient.c:803259
int sub_70FFD0()
{
  return atexit(nullsub_1833);
}

