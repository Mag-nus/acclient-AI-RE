/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WeaponProfile
   Object     : AC\acappraisal\WeaponProfile.obj
   Functions  : 3
   Addresses  : 005B62C0 - 005B63C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B62C0) --------------------------------------------------------  // acclient.c:480968
void __thiscall WeaponProfile::WeaponProfile(WeaponProfile *this)
{
  this->vfptr = (PackObjVtbl *)&WeaponProfile::vftable;
  this->damage_type = 0;
  this->weapon_skill = 0;
  this->weapon_time = 0;
  this->weapon_damage = 0;
  LODWORD(this->damage_variance) = 0;
  HIDWORD(this->damage_variance) = 1070596096;
  LODWORD(this->damage_mod) = 0;
  HIDWORD(this->damage_mod) = 1072693248;
  *(_QWORD *)&this->weapon_length = 0i64;
  *(_QWORD *)&this->max_velocity = 0i64;
  LODWORD(this->weapon_offense) = 0;
  HIDWORD(this->weapon_offense) = 1072693248;
  this->max_velocity_estimated = 0;
}
// 7E6CDC: using guessed type int (__thiscall *WeaponProfile::vftable)(void *, char);

//----- (005B6310) --------------------------------------------------------  // acclient.c:480988
signed int __thiscall WeaponProfile::Pack(WeaponProfile *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2
  char *v6; // esi@2
  char *v7; // edx@2
  char *v8; // esi@2
  char *v9; // edx@2
  char *v10; // esi@2
  char *v11; // edx@2

  if ( size >= 0x3C )
  {
    *(_DWORD *)*addr = this->damage_type;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->weapon_time;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->weapon_skill;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->weapon_damage;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(double *)v6 = this->damage_variance;
    v7 = (char *)*addr + 8;
    *addr = v7;
    *(double *)v7 = this->damage_mod;
    v8 = (char *)*addr + 8;
    *addr = v8;
    *(double *)v8 = this->weapon_length;
    v9 = (char *)*addr + 8;
    *addr = v9;
    *(double *)v9 = this->max_velocity;
    v10 = (char *)*addr + 8;
    *addr = v10;
    *(double *)v10 = this->weapon_offense;
    v11 = (char *)*addr + 8;
    *addr = v11;
    *(_DWORD *)v11 = this->max_velocity_estimated;
    *addr = (char *)*addr + 4;
  }
  PackObj::ALIGN_PTR(addr, &size);
  return 60;
}

//----- (005B63C0) --------------------------------------------------------  // acclient.c:481037
int __thiscall WeaponProfile::UnPack(WeaponProfile *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // esi@3
  char *v6; // edx@3
  char *v7; // esi@3
  char *v8; // edx@3
  char *v9; // esi@3
  char *v10; // edx@3
  char *v11; // esi@3
  char *v12; // edx@3

  if ( size >= 0x3C )
  {
    this->damage_type = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    this->weapon_time = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->weapon_skill = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->weapon_damage = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_QWORD *)&this->damage_variance = *(_QWORD *)v7;
    v8 = (char *)*addr + 8;
    *addr = v8;
    *(_QWORD *)&this->damage_mod = *(_QWORD *)v8;
    v9 = (char *)*addr + 8;
    *addr = v9;
    *(_QWORD *)&this->weapon_length = *(_QWORD *)v9;
    v10 = (char *)*addr + 8;
    *addr = v10;
    *(_QWORD *)&this->max_velocity = *(_QWORD *)v10;
    v11 = (char *)*addr + 8;
    *addr = v11;
    *(_QWORD *)&this->weapon_offense = *(_QWORD *)v11;
    v12 = (char *)*addr + 8;
    *addr = v12;
    this->max_velocity_estimated = *(_DWORD *)v12;
    *addr = (char *)*addr + 4;
    PackObj::ALIGN_PTR(addr, &size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

