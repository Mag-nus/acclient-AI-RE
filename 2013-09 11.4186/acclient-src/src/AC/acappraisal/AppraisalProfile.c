/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AppraisalProfile
   Object     : AC\acappraisal\AppraisalProfile.obj
   Functions  : 41
   Addresses  : 00525C70 - 005B4100 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00525C70) --------------------------------------------------------  // acclient.c:341009
BOOL __thiscall AnimSequenceNode::has_anim(AppraisalProfile *this)
{
  return this->hook_profile != 0;
}

//----- (005B2B00) --------------------------------------------------------  // acclient.c:477348
void __thiscall AppraisalProfile::Clear(AppraisalProfile *this)
{
  AppraisalProfile *v1; // esi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  PackableHashTable<unsigned long,__int64> *v3; // ecx@3
  PackableHashTable<unsigned long,int> *v4; // ecx@5
  PackableHashTable<unsigned long,double> *v5; // ecx@7
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v6; // ecx@9
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v7; // ecx@11
  PSmartArray<unsigned long> *v8; // ecx@13
  CreatureAppraisalProfile *v9; // ecx@15
  WeaponProfile *v10; // ecx@17
  ArmorProfile *v11; // ecx@19
  HookAppraisalProfile *v12; // ecx@21

  v1 = this;
  v2 = this->_intStatsTable;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->_int64StatsTable;
  v1->_intStatsTable = 0;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->_boolStatsTable;
  v1->_int64StatsTable = 0;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->_floatStatsTable;
  v1->_boolStatsTable = 0;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v6 = v1->_strStatsTable;
  v1->_floatStatsTable = 0;
  if ( v6 )
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  v7 = v1->_didStatsTable;
  v1->_strStatsTable = 0;
  if ( v7 )
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
  v8 = v1->_spellBook;
  v1->_didStatsTable = 0;
  if ( v8 )
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
  v9 = v1->creature_profile;
  v1->_spellBook = 0;
  if ( v9 )
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
  v10 = v1->weapon_profile;
  v1->creature_profile = 0;
  if ( v10 )
    ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
  v11 = v1->armor_profile;
  v1->weapon_profile = 0;
  if ( v11 )
    ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
  v12 = v1->hook_profile;
  v1->armor_profile = 0;
  if ( v12 )
    ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
  v1->hook_profile = 0;
  v1->armor_ench_bitfield = 0;
  v1->weapon_ench_bitfield = 0;
  v1->resist_ench_bitfield = 0;
  v1->base_armor_head = 0;
  v1->base_armor_chest = 0;
  v1->base_armor_groin = 0;
  v1->base_armor_bicep = 0;
  v1->base_armor_wrist = 0;
  v1->base_armor_hand = 0;
  v1->base_armor_thigh = 0;
  v1->base_armor_shin = 0;
  v1->base_armor_foot = 0;
  v1->success_flag = 1;
}

//----- (005B2BF0) --------------------------------------------------------  // acclient.c:477424
int __thiscall AppraisalProfile::InqCreature(AppraisalProfile *this, CreatureAppraisalProfile *cap)
{
  int result; // eax@1

  result = (int)this->creature_profile;
  if ( result )
  {
    CreatureAppraisalProfile::operator=((int)cap, result);
    result = 1;
  }
  return result;
}

//----- (005B2C10) --------------------------------------------------------  // acclient.c:477438
int __thiscall AppraisalProfile::InqIntEnchantmentMod(AppraisalProfile *this, unsigned int stype, int *raised)
{
  unsigned int v3; // eax@4
  signed int v4; // edx@4
  signed int v5; // ecx@4

  *raised = 0;
  if ( stype == 28 )
  {
    v3 = this->armor_ench_bitfield;
    v4 = 1;
    v5 = 0x10000;
  }
  else if ( stype == 44 )
  {
    v3 = this->weapon_ench_bitfield;
    v4 = 8;
    v5 = 0x80000;
  }
  else
  {
    if ( stype != 49 )
      return 0;
    v3 = this->weapon_ench_bitfield;
    v4 = 4;
    v5 = 0x40000;
  }
  if ( v3 & v4 )
  {
    *raised = v5 & v3;
    return 1;
  }
  return 0;
}

//----- (005B2C70) --------------------------------------------------------  // acclient.c:477474
int __thiscall AppraisalProfile::InqFloatEnchantmentMod(AppraisalProfile *this, unsigned int stype, int *raised)
{
  unsigned int v3; // eax@2
  signed int v4; // edx@2
  signed int v5; // ecx@2
  int result; // eax@30

  *raised = 0;
  switch ( stype )
  {
    case 0xDu:
      v3 = this->armor_ench_bitfield;
      v4 = 2;
      v5 = 0x20000;
      goto LABEL_29;
    case 0xEu:
      v3 = this->armor_ench_bitfield;
      v4 = 4;
      v5 = 0x40000;
      goto LABEL_29;
    case 0xFu:
      v3 = this->armor_ench_bitfield;
      v4 = 8;
      v5 = 0x80000;
      goto LABEL_29;
    case 0x10u:
      v3 = this->armor_ench_bitfield;
      v4 = 16;
      v5 = 0x100000;
      goto LABEL_29;
    case 0x11u:
      v3 = this->armor_ench_bitfield;
      v4 = 32;
      v5 = 0x200000;
      goto LABEL_29;
    case 0x12u:
      v3 = this->armor_ench_bitfield;
      v4 = 64;
      v5 = 0x400000;
      goto LABEL_29;
    case 0x13u:
      v3 = this->armor_ench_bitfield;
      v4 = 128;
      v5 = (signed int)"activation type (%s) with '%s' because of its toggle type (%s)";
      goto LABEL_29;
    case 0xA5u:
      v3 = this->armor_ench_bitfield;
      v4 = 256;
      v5 = 0x1000000;
      goto LABEL_29;
    case 0x3Eu:
      v3 = this->weapon_ench_bitfield;
      v4 = 1;
      v5 = 0x10000;
      goto LABEL_29;
    case 0x1Du:
      v3 = this->weapon_ench_bitfield;
      v4 = 2;
      v5 = 0x20000;
      goto LABEL_29;
    case 0x16u:
      v3 = this->weapon_ench_bitfield;
      v4 = 16;
      v5 = 0x100000;
      goto LABEL_29;
    case 0x3Fu:
      v3 = this->weapon_ench_bitfield;
      v4 = 32;
      v5 = 0x200000;
      goto LABEL_29;
    case 0x40u:
      v3 = this->resist_ench_bitfield;
      v4 = 1;
      v5 = 0x10000;
      goto LABEL_29;
    case 0x41u:
      v3 = this->resist_ench_bitfield;
      v4 = 2;
      v5 = 0x20000;
      goto LABEL_29;
    case 0x42u:
      v3 = this->resist_ench_bitfield;
      v4 = 4;
      v5 = 0x40000;
      goto LABEL_29;
    case 0x43u:
      v3 = this->resist_ench_bitfield;
      v4 = 8;
      v5 = 0x80000;
      goto LABEL_29;
    case 0x44u:
      v3 = this->resist_ench_bitfield;
      v4 = 16;
      v5 = 0x100000;
      goto LABEL_29;
    case 0x45u:
      v3 = this->resist_ench_bitfield;
      v4 = 32;
      v5 = 0x200000;
      goto LABEL_29;
    case 0x46u:
      v3 = this->resist_ench_bitfield;
      v4 = 64;
      v5 = 0x400000;
      goto LABEL_29;
    case 0xA6u:
      v3 = this->resist_ench_bitfield;
      v4 = 0x4000;
      v5 = 0x40000000;
      goto LABEL_29;
    case 0x47u:
      v3 = this->resist_ench_bitfield;
      v4 = 128;
      v5 = (signed int)"activation type (%s) with '%s' because of its toggle type (%s)";
      goto LABEL_29;
    case 0x48u:
      v3 = this->resist_ench_bitfield;
      v4 = 256;
      v5 = 0x1000000;
      goto LABEL_29;
    case 0x49u:
      v3 = this->resist_ench_bitfield;
      v4 = 512;
      v5 = 0x2000000;
      goto LABEL_29;
    case 0x4Au:
      v3 = this->resist_ench_bitfield;
      v4 = 1024;
      v5 = 0x4000000;
      goto LABEL_29;
    case 0x4Bu:
      v3 = this->resist_ench_bitfield;
      v4 = 2048;
      v5 = 0x8000000;
      goto LABEL_29;
    case 0x90u:
      v3 = this->resist_ench_bitfield;
      v4 = 4096;
      v5 = 0x10000000;
      goto LABEL_29;
    case 0x98u:
      v3 = this->resist_ench_bitfield;
      v4 = 0x2000;
      v5 = 0x20000000;
LABEL_29:
      if ( !(v3 & v4) )
        goto LABEL_31;
      *raised = v5 & v3;
      result = 1;
      break;
    default:
LABEL_31:
      result = 0;
      break;
  }
  return result;
}

//----- (005B2F90) --------------------------------------------------------  // acclient.c:477633
unsigned int __thiscall AppraisalProfile::IsHookedItemInscribable(AppraisalProfile *this)
{
  HookAppraisalProfile *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->hook_profile;
  if ( v1 )
    result = HookAppraisalProfile::IsInscribable(v1);
  else
    result = 0;
  return result;
}

//----- (005B2FA0) --------------------------------------------------------  // acclient.c:477647
unsigned int __thiscall AppraisalProfile::IsHookedItemHealer(AppraisalProfile *this)
{
  HookAppraisalProfile *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->hook_profile;
  if ( v1 )
    result = HookAppraisalProfile::IsHealer(v1);
  else
    result = 0;
  return result;
}

//----- (005B2FB0) --------------------------------------------------------  // acclient.c:477661
unsigned int __thiscall AppraisalProfile::IsHookedItemLockpick(AppraisalProfile *this)
{
  HookAppraisalProfile *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->hook_profile;
  if ( v1 )
    result = HookAppraisalProfile::IsLockpick(v1);
  else
    result = 0;
  return result;
}

//----- (005B2FC0) --------------------------------------------------------  // acclient.c:477675
int __thiscall AppraisalProfile::GetHookedItemValidLocations(AppraisalProfile *this)
{
  HookAppraisalProfile *v1; // ecx@1
  int result; // eax@2

  v1 = this->hook_profile;
  if ( v1 )
    result = HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)v1);
  else
    result = 0;
  return result;
}

//----- (005B2FD0) --------------------------------------------------------  // acclient.c:477689
unsigned int __thiscall AppraisalProfile::GetHookedItemAmmoType(AppraisalProfile *this)
{
  HookAppraisalProfile *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->hook_profile;
  if ( v1 )
    result = ChatRoomTracker::GetGlobalTradeRoomID((ChatRoomTracker *)v1);
  else
    result = 0;
  return result;
}

//----- (005B2FE0) --------------------------------------------------------  // acclient.c:477703
void __thiscall AppraisalProfile::SetPackHeader(AppraisalProfile *this, unsigned int *bitfield)
{
  if ( this->_intStatsTable )
    *bitfield |= 1u;
  if ( this->_int64StatsTable )
    *bitfield |= 0x2000u;
  if ( this->_boolStatsTable )
    *bitfield |= 2u;
  if ( this->_floatStatsTable )
    *bitfield |= 4u;
  if ( this->_strStatsTable )
    *bitfield |= 8u;
  if ( this->_didStatsTable )
    *bitfield |= 0x1000u;
  if ( this->_spellBook )
    *bitfield |= 0x10u;
  if ( this->creature_profile )
    *bitfield |= 0x100u;
  if ( this->hook_profile )
    *bitfield |= 0x40u;
  if ( this->weapon_profile )
    *bitfield |= 0x20u;
  if ( this->armor_profile )
    *bitfield |= 0x80u;
  if ( this->armor_ench_bitfield )
    *bitfield |= 0x200u;
  if ( this->weapon_ench_bitfield )
    *bitfield |= 0x800u;
  if ( this->resist_ench_bitfield )
    *bitfield |= 0x400u;
  if ( this->base_armor_head
    || this->base_armor_chest
    || this->base_armor_groin
    || this->base_armor_bicep
    || this->base_armor_wrist
    || this->base_armor_hand
    || this->base_armor_thigh
    || this->base_armor_shin
    || this->base_armor_foot )
    *bitfield |= 0x4000u;
}

//----- (005B30D0) --------------------------------------------------------  // acclient.c:477746
int __thiscall AppraisalProfile::pack_size(AppraisalProfile *this)
{
  AppraisalProfile *v1; // esi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  int v3; // edi@1
  PackableHashTable<unsigned long,__int64> *v4; // ecx@3
  PackableHashTable<unsigned long,int> *v5; // ecx@5
  PackableHashTable<unsigned long,double> *v6; // ecx@7
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v7; // ecx@9
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v8; // ecx@11
  PSmartArray<unsigned long> *v9; // ecx@13
  CreatureAppraisalProfile *v10; // ecx@15
  HookAppraisalProfile *v11; // ecx@17
  WeaponProfile *v12; // ecx@19
  ArmorProfile *v13; // ecx@21
  void *mem; // [sp+50h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = this->_intStatsTable;
  mem = 0;
  v3 = 8;
  if ( v2 )
    v3 = ((int (__stdcall *)(void **, _DWORD))v2->vfptr->Pack)(&mem, 0) + 8;
  v4 = v1->_int64StatsTable;
  if ( v4 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v4->vfptr->Pack)(&mem, 0);
  v5 = v1->_boolStatsTable;
  if ( v5 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v5->vfptr->Pack)(&mem, 0);
  v6 = v1->_floatStatsTable;
  if ( v6 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v6->vfptr->Pack)(&mem, 0);
  v7 = v1->_strStatsTable;
  if ( v7 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v7->vfptr->Pack)(&mem, 0);
  v8 = v1->_didStatsTable;
  if ( v8 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v8->vfptr->Pack)(&mem, 0);
  v9 = v1->_spellBook;
  if ( v9 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v9->vfptr->Pack)(&mem, 0);
  v10 = v1->creature_profile;
  if ( v10 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v10->vfptr->Pack)(&mem, 0);
  v11 = v1->hook_profile;
  if ( v11 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v11->vfptr->Pack)(&mem, 0);
  v12 = v1->weapon_profile;
  if ( v12 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v12->vfptr->Pack)(&mem, 0);
  v13 = v1->armor_profile;
  if ( v13 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v13->vfptr->Pack)(&mem, 0);
  if ( v1->armor_ench_bitfield )
    v3 += 4;
  if ( v1->weapon_ench_bitfield )
    v3 += 4;
  if ( v1->resist_ench_bitfield )
    v3 += 4;
  if ( v1->base_armor_head
    || v1->base_armor_chest
    || v1->base_armor_groin
    || v1->base_armor_bicep
    || v1->base_armor_wrist
    || v1->base_armor_hand
    || v1->base_armor_thigh
    || v1->base_armor_shin
    || v1->base_armor_foot )
    v3 += 36;
  return v3;
}

//----- (005B3240) --------------------------------------------------------  // acclient.c:477820
void __cdecl CopyTheFucker(CreatureAppraisalProfile **mine, CreatureAppraisalProfile *theirs)
{
  CreatureAppraisalProfile *v2; // eax@5
  int v3; // eax@6

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = (CreatureAppraisalProfile *)operator new(0x38u);
      if ( v2 )
      {
        CreatureAppraisalProfile::CreatureAppraisalProfile(v2);
        *mine = (CreatureAppraisalProfile *)v3;
        CreatureAppraisalProfile::operator=(v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    CreatureAppraisalProfile::operator=((int)*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}

//----- (005B32A0) --------------------------------------------------------  // acclient.c:477849
void __thiscall AppraisalProfile::AppraisalProfile(AppraisalProfile *this)
{
  this->vfptr = (PackObjVtbl *)&AppraisalProfile::vftable;
  this->creature_profile = 0;
  this->hook_profile = 0;
  this->weapon_profile = 0;
  this->armor_profile = 0;
  this->_intStatsTable = 0;
  this->_int64StatsTable = 0;
  this->_boolStatsTable = 0;
  this->_floatStatsTable = 0;
  this->_strStatsTable = 0;
  this->_didStatsTable = 0;
  this->_spellBook = 0;
  AppraisalProfile::Clear(this);
}
// 7E6590: using guessed type int (__thiscall *AppraisalProfile::vftable)(void *, char);

//----- (005B32E0) --------------------------------------------------------  // acclient.c:477868
void __thiscall AppraisalProfile::~AppraisalProfile(AppraisalProfile *this)
{
  AppraisalProfile *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AppraisalProfile::vftable;
  AppraisalProfile::Clear(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6590: using guessed type int (__thiscall *AppraisalProfile::vftable)(void *, char);

//----- (005B3300) --------------------------------------------------------  // acclient.c:477881
int __thiscall WeaponProfile::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(this + 60) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(this + 64) = *(_DWORD *)(a2 + 64);
  return result;
}

//----- (005B3370) --------------------------------------------------------  // acclient.c:477905
int __thiscall AppraisalProfile::InqArmor(AppraisalProfile *this, ArmorProfile *aap)
{
  int result; // eax@1

  result = (int)this->armor_profile;
  if ( result )
  {
    LODWORD(aap->mod_vs_slash) = *(_DWORD *)(result + 4);
    LODWORD(aap->mod_vs_pierce) = *(_DWORD *)(result + 8);
    LODWORD(aap->mod_vs_bludgeon) = *(_DWORD *)(result + 12);
    LODWORD(aap->mod_vs_cold) = *(_DWORD *)(result + 16);
    LODWORD(aap->mod_vs_fire) = *(_DWORD *)(result + 20);
    LODWORD(aap->mod_vs_acid) = *(_DWORD *)(result + 24);
    LODWORD(aap->mod_vs_electric) = *(_DWORD *)(result + 28);
    LODWORD(aap->mod_vs_nether) = *(_DWORD *)(result + 32);
    result = 1;
  }
  return result;
}

//----- (005B33C0) --------------------------------------------------------  // acclient.c:477926
int __thiscall AppraisalProfile::Pack(AppraisalProfile *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  AppraisalProfile *v4; // edi@1
  int result; // eax@2
  int v6; // eax@3
  unsigned int v7; // ebp@3
  __int16 v8; // bx@4
  int v9; // edx@4
  PackableHashTable<unsigned long,long> *v10; // ecx@4
  PackableHashTable<unsigned long,__int64> *v11; // ecx@6
  PackableHashTable<unsigned long,int> *v12; // ecx@8
  PackableHashTable<unsigned long,double> *v13; // ecx@10
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v14; // ecx@12
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v15; // ecx@14
  PSmartArray<unsigned long> *v16; // ecx@16
  int v17; // ebx@33
  int v18; // edx@33
  int v19; // ecx@33
  int v20; // eax@33
  int v21; // ebp@33
  int v22; // ebx@33
  int v23; // edx@33
  int v24; // ecx@33
  unsigned int retVal; // [sp+58h] [bp-4h]@3

  v3 = addr;
  v4 = this;
  if ( *addr )
  {
    v6 = AppraisalProfile::pack_size(this);
    v7 = size;
    retVal = v6;
    if ( size >= v6 )
    {
      addr = 0;
      AppraisalProfile::SetPackHeader(v4, (unsigned int *)&addr);
      v8 = (signed __int16)addr;
      *(_DWORD *)*v3 = addr;
      v9 = (int)((char *)*v3 + 4);
      *v3 = (void *)v9;
      *(_DWORD *)v9 = v4->success_flag;
      *v3 = (char *)*v3 + 4;
      v10 = v4->_intStatsTable;
      if ( v10 )
        ((void (__stdcall *)(void **, unsigned int))v10->vfptr->Pack)(v3, v7);
      v11 = v4->_int64StatsTable;
      if ( v11 )
        ((void (__stdcall *)(void **, unsigned int))v11->vfptr->Pack)(v3, v7);
      v12 = v4->_boolStatsTable;
      if ( v12 )
        ((void (__stdcall *)(void **, unsigned int))v12->vfptr->Pack)(v3, v7);
      v13 = v4->_floatStatsTable;
      if ( v13 )
        ((void (__stdcall *)(void **, unsigned int))v13->vfptr->Pack)(v3, v7);
      v14 = v4->_strStatsTable;
      if ( v14 )
        ((void (__stdcall *)(void **, unsigned int))v14->vfptr->Pack)(v3, v7);
      v15 = v4->_didStatsTable;
      if ( v15 )
        ((void (__stdcall *)(void **, unsigned int))v15->vfptr->Pack)(v3, v7);
      v16 = v4->_spellBook;
      if ( v16 )
        ((void (__stdcall *)(void **, unsigned int))v16->vfptr->Pack)(v3, v7);
      if ( (char)v8 < 0 )
        ((void (__stdcall *)(void **, unsigned int))v4->armor_profile->vfptr->Pack)(v3, v7);
      if ( HIBYTE(v8) & 1 )
        ((void (__stdcall *)(void **, unsigned int))v4->creature_profile->vfptr->Pack)(v3, v7);
      if ( v8 & 0x20 )
        ((void (__stdcall *)(void **, unsigned int))v4->weapon_profile->vfptr->Pack)(v3, v7);
      if ( v8 & 0x40 )
        ((void (__stdcall *)(void **, unsigned int))v4->hook_profile->vfptr->Pack)(v3, v7);
      if ( HIBYTE(v8) & 2 )
      {
        *(_DWORD *)*v3 = v4->armor_ench_bitfield;
        *v3 = (char *)*v3 + 4;
      }
      if ( HIBYTE(v8) & 8 )
      {
        *(_DWORD *)*v3 = v4->weapon_ench_bitfield;
        *v3 = (char *)*v3 + 4;
      }
      if ( HIBYTE(v8) & 4 )
      {
        *(_DWORD *)*v3 = v4->resist_ench_bitfield;
        *v3 = (char *)*v3 + 4;
      }
      if ( HIBYTE(v8) & 0x40 )
      {
        *(_DWORD *)*v3 = v4->base_armor_head;
        v17 = (int)((char *)*v3 + 4);
        *v3 = (void *)v17;
        *(_DWORD *)v17 = v4->base_armor_chest;
        v18 = (int)((char *)*v3 + 4);
        *v3 = (void *)v18;
        *(_DWORD *)v18 = v4->base_armor_groin;
        v19 = (int)((char *)*v3 + 4);
        *v3 = (void *)v19;
        *(_DWORD *)v19 = v4->base_armor_bicep;
        v20 = (int)((char *)*v3 + 4);
        *v3 = (void *)v20;
        *(_DWORD *)v20 = v4->base_armor_wrist;
        v21 = (int)((char *)*v3 + 4);
        *v3 = (void *)v21;
        *(_DWORD *)v21 = v4->base_armor_hand;
        v22 = (int)((char *)*v3 + 4);
        *v3 = (void *)v22;
        *(_DWORD *)v22 = v4->base_armor_thigh;
        v23 = (int)((char *)*v3 + 4);
        *v3 = (void *)v23;
        *(_DWORD *)v23 = v4->base_armor_shin;
        v24 = (int)((char *)*v3 + 4);
        *v3 = (void *)v24;
        *(_DWORD *)v24 = v4->base_armor_foot;
        *v3 = (char *)*v3 + 4;
      }
    }
    result = retVal;
  }
  else
  {
    result = AppraisalProfile::pack_size(this);
  }
  return result;
}

//----- (005B3570) --------------------------------------------------------  // acclient.c:478053
void __cdecl CopyTheFucker(WeaponProfile **mine, WeaponProfile *theirs)
{
  WeaponProfile *v2; // eax@5
  int v3; // eax@6

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = (WeaponProfile *)operator new(0x48u);
      if ( v2 )
      {
        WeaponProfile::WeaponProfile(v2);
        *mine = (WeaponProfile *)v3;
        WeaponProfile::operator=(v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    WeaponProfile::operator=((int)*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}

//----- (005B35D0) --------------------------------------------------------  // acclient.c:478082
void __cdecl CopyTheFucker(ArmorProfile **mine, ArmorProfile *theirs)
{
  void *v2; // eax@5
  ArmorProfile *v3; // eax@9

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x24u);
      if ( v2 )
      {
        *(_DWORD *)v2 = &ArmorProfile::vftable;
        *((_DWORD *)v2 + 1) = 1065353216;
        *((_DWORD *)v2 + 2) = 1065353216;
        *((_DWORD *)v2 + 3) = 1065353216;
        *((_DWORD *)v2 + 4) = 1065353216;
        *((_DWORD *)v2 + 5) = 1065353216;
        *((_DWORD *)v2 + 6) = 1065353216;
        *((_DWORD *)v2 + 7) = 1065353216;
        *((_DWORD *)v2 + 8) = 1065353216;
      }
      else
      {
        v2 = 0;
      }
      *mine = (ArmorProfile *)v2;
    }
    v3 = *mine;
    v3->mod_vs_slash = theirs->mod_vs_slash;
    v3->mod_vs_pierce = theirs->mod_vs_pierce;
    v3->mod_vs_bludgeon = theirs->mod_vs_bludgeon;
    v3->mod_vs_cold = theirs->mod_vs_cold;
    v3->mod_vs_fire = theirs->mod_vs_fire;
    v3->mod_vs_acid = theirs->mod_vs_acid;
    v3->mod_vs_electric = theirs->mod_vs_electric;
    v3->mod_vs_nether = theirs->mod_vs_nether;
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = 0;
  }
}
// 7AF2FC: using guessed type int (__thiscall *ArmorProfile::vftable)(void *, char);

//----- (005B3670) --------------------------------------------------------  // acclient.c:478129
void __cdecl CopyTheFucker(HookAppraisalProfile **mine, HookAppraisalProfile *theirs)
{
  HookAppraisalProfile *v2; // eax@5
  int v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = (HookAppraisalProfile *)operator new(0x10u);
      v3 = (int)v2;
      if ( v2 )
      {
        v2->vfptr = (PackObjVtbl *)&HookAppraisalProfile::vftable;
        HookAppraisalProfile::Clear(v2);
        *mine = (HookAppraisalProfile *)v3;
        GeneratorQueueNode::operator=(v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    GeneratorQueueNode::operator=((int)*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E657C: using guessed type int (__thiscall *HookAppraisalProfile::vftable)(void *, char);

//----- (005B36E0) --------------------------------------------------------  // acclient.c:478161
AC1Legacy::SmartArray<Season *> *__thiscall AC1Legacy::SmartArray<unsigned long>::operator=(AC1Legacy::SmartArray<Season *> *this, int a2)
{
  AC1Legacy::SmartArray<Season *> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  Season **v5; // ecx@3

  v2 = this;
  if ( this->m_size >= *(_DWORD *)(a2 + 4)
    || (this->m_num = 0, AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(this, *(_DWORD *)(a2 + 4))) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 4 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        *v5 = *(Season **)v3;
        v3 += 4;
        ++v5;
      }
      while ( v3 < v4 );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (005B3740) --------------------------------------------------------  // acclient.c:478191
int __thiscall PSmartArray<unsigned long>::StreamPack(PSmartArray<unsigned long> *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  unsigned int *v4; // ebp@1
  PSmartArray<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@3
  unsigned int v7; // ST0C_4@3
  unsigned int v8; // ebp@3
  unsigned int v9; // edi@5
  unsigned int arraySize; // [sp+10h] [bp-4h]@1

  v4 = size;
  v5 = this;
  arraySize = this->m_num;
  if ( !STREAMPACK(op, &arraySize, addr, size) )
    return 0;
  if ( op == 2 )
  {
    v6 = arraySize;
    v7 = arraySize;
    v5->m_num = 0;
    v8 = v6;
    if ( !AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v5->m_data, v7) )
      return 0;
    v5->m_num = v8;
    v4 = size;
  }
  v9 = 0;
  if ( !v5->m_num )
    return 1;
  while ( STREAMPACK(op, &v5->m_data[v9], addr, v4) )
  {
    ++v9;
    if ( v9 >= v5->m_num )
      return 1;
  }
  return 0;
}

//----- (005B37E0) --------------------------------------------------------  // acclient.c:478230
AppraisalProfile *__thiscall AppraisalProfile::scalar_deleting_destructor(AppraisalProfile *this, unsigned int a2)
{
  AppraisalProfile *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&AppraisalProfile::vftable;
  AppraisalProfile::Clear(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6590: using guessed type int (__thiscall *AppraisalProfile::vftable)(void *, char);

//----- (005B3810) --------------------------------------------------------  // acclient.c:478246
int __thiscall AppraisalProfile::InqWeapon(AppraisalProfile *this, WeaponProfile *wap)
{
  int result; // eax@1

  result = (int)this->weapon_profile;
  if ( result )
  {
    WeaponProfile::operator=((int)wap, result);
    result = 1;
  }
  return result;
}

//----- (005B3830) --------------------------------------------------------  // acclient.c:478260
int __thiscall AppraisalProfile::InqInt(AppraisalProfile *this, unsigned int stype, int *retval)
{
  PackableHashTable<unsigned long,long> *v3; // ecx@1
  int *v4; // eax@2
  int result; // eax@3

  v3 = this->_intStatsTable;
  if ( v3
    && (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    *retval = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B3860) --------------------------------------------------------  // acclient.c:478283
int __thiscall AppraisalProfile::InqInt64(AppraisalProfile *this, unsigned int stype, __int64 *retval)
{
  PackableHashTable<unsigned long,double> *v3; // ecx@1
  long double *v4; // eax@2
  __int64 *v5; // ecx@3
  int result; // eax@3

  v3 = (PackableHashTable<unsigned long,double> *)this->_int64StatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,double>::lookup(v3, &stype)) != 0 )
  {
    v5 = retval;
    *(_DWORD *)retval = *(_DWORD *)v4;
    *((_DWORD *)v5 + 1) = *((_DWORD *)v4 + 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B3890) --------------------------------------------------------  // acclient.c:478306
int __thiscall AppraisalProfile::InqBool(AppraisalProfile *this, unsigned int stype, int *retval)
{
  PackableHashTable<unsigned long,int> *v3; // ecx@1
  int *v4; // eax@2
  int result; // eax@3

  v3 = this->_boolStatsTable;
  if ( v3
    && (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    *retval = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B38C0) --------------------------------------------------------  // acclient.c:478329
int __thiscall AppraisalProfile::InqFloat(AppraisalProfile *this, unsigned int stype, long double *retval)
{
  PackableHashTable<unsigned long,double> *v3; // ecx@1
  long double *v4; // eax@2
  long double *v5; // ecx@3
  int result; // eax@3

  v3 = this->_floatStatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,double>::lookup(v3, &stype)) != 0 )
  {
    v5 = retval;
    *(_DWORD *)retval = *(_DWORD *)v4;
    *((_DWORD *)v5 + 1) = *((_DWORD *)v4 + 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B38F0) --------------------------------------------------------  // acclient.c:478352
int __thiscall AppraisalProfile::InqDataID(AppraisalProfile *this, unsigned int stype, IDClass<_tagDataID,32,0> *retval)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v3; // ecx@1
  unsigned int *v4; // eax@2
  int result; // eax@3

  v3 = (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this->_didStatsTable;
  if ( v3
    && (v4 = (unsigned int *)PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                               v3,
                               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    retval->id = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B3920) --------------------------------------------------------  // acclient.c:478375
PSmartArray<unsigned long> *__thiscall PSmartArray<unsigned long>::vector_deleting_destructor(PSmartArray<unsigned long> *this, unsigned int a2)
{
  PSmartArray<unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  operator delete[](this->m_data);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005B3950) --------------------------------------------------------  // acclient.c:478389
int __thiscall AppraisalProfile::InqString(AppraisalProfile *this, unsigned int stype, AC1Legacy::PStringBase<char> *retval)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // ecx@1
  AC1Legacy::PStringBase<unsigned short> *v4; // eax@2
  int result; // eax@3

  v3 = this->_strStatsTable;
  if ( v3
    && (v4 = (AC1Legacy::PStringBase<unsigned short> *)PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                                                         (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
                                                         (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)retval, v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B3980) --------------------------------------------------------  // acclient.c:478412
int __thiscall AppraisalProfile::UnPack(AppraisalProfile *this, void **addr, unsigned int size)
{
  AppraisalProfile *v3; // edi@1
  void **v4; // esi@1
  void **v5; // ecx@1
  char *v6; // eax@1
  char *v7; // edx@1
  void *v8; // eax@2
  void *v9; // ebp@2
  PackableHashTable<unsigned long,long> *v10; // ecx@3
  void *v11; // eax@7
  void *v12; // ebp@7
  PackableHashTable<unsigned long,__int64> *v13; // ecx@8
  void *v14; // eax@12
  void *v15; // ebp@12
  PackableHashTable<unsigned long,int> *v16; // ecx@13
  void *v17; // eax@17
  void *v18; // ebp@17
  PackableHashTable<unsigned long,double> *v19; // ecx@18
  void *v20; // eax@22
  void *v21; // ebp@22
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v22; // ecx@23
  void *v23; // eax@27
  void *v24; // ebp@27
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v25; // ecx@28
  void *v26; // eax@32
  void *v27; // ebp@32
  int v28; // ecx@33
  PSmartArray<unsigned long> *v29; // ecx@33
  void *v30; // eax@37
  unsigned int v31; // ebp@40
  CreatureAppraisalProfile *v32; // eax@43
  CreatureAppraisalProfile *v33; // eax@44
  WeaponProfile *v34; // eax@48
  WeaponProfile *v35; // eax@49
  HookAppraisalProfile *v36; // eax@53
  HookAppraisalProfile *v37; // ebp@53
  HookAppraisalProfile *v38; // ecx@54
  int v39; // ebx@64
  int v40; // edx@64
  int v41; // ecx@64
  int v42; // eax@64
  int v43; // ebp@64
  int v44; // ebx@64
  int v45; // edx@64
  int v46; // ecx@64
  int result; // eax@66
  void *v48; // [sp+50h] [bp-4h]@1
  void **addra; // [sp+58h] [bp+4h]@1

  v3 = this;
  AppraisalProfile::Clear(this);
  v4 = addr;
  v5 = *(void ***)*addr;
  v48 = *addr;
  v6 = (char *)*addr + 4;
  *addr = v6;
  v3->success_flag = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  addra = v5;
  *v4 = v7;
  if ( (unsigned __int8)v5 & 1 )
  {
    v8 = operator new(0x14u);
    v9 = v8;
    if ( v8 )
    {
      *(_DWORD *)v8 = &PackableHashTable<unsigned long,long>::vftable;
      *((_DWORD *)v8 + 1) = 0;
      *((_DWORD *)v8 + 2) = 0;
      *((_DWORD *)v8 + 3) = 16;
      *((_DWORD *)v8 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v8);
      v10 = (PackableHashTable<unsigned long,long> *)v9;
    }
    else
    {
      v10 = 0;
    }
    v3->_intStatsTable = v10;
    ((void (__stdcall *)(void **, unsigned int))v10->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( BYTE1(v5) & 0x20 )
  {
    v11 = operator new(0x14u);
    v12 = v11;
    if ( v11 )
    {
      *(_DWORD *)v11 = &PackableHashTable<unsigned long,__int64>::vftable;
      *((_DWORD *)v11 + 1) = 0;
      *((_DWORD *)v11 + 2) = 0;
      *((_DWORD *)v11 + 3) = 8;
      *((_DWORD *)v11 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v11);
      v13 = (PackableHashTable<unsigned long,__int64> *)v12;
    }
    else
    {
      v13 = 0;
    }
    v3->_int64StatsTable = v13;
    ((void (__stdcall *)(void **, unsigned int))v13->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 2 )
  {
    v14 = operator new(0x14u);
    v15 = v14;
    if ( v14 )
    {
      *(_DWORD *)v14 = &PackableHashTable<unsigned long,int>::vftable;
      *((_DWORD *)v14 + 1) = 0;
      *((_DWORD *)v14 + 2) = 0;
      *((_DWORD *)v14 + 3) = 8;
      *((_DWORD *)v14 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v14);
      v16 = (PackableHashTable<unsigned long,int> *)v15;
    }
    else
    {
      v16 = 0;
    }
    v3->_boolStatsTable = v16;
    ((void (__stdcall *)(void **, unsigned int))v16->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 4 )
  {
    v17 = operator new(0x14u);
    v18 = v17;
    if ( v17 )
    {
      *(_DWORD *)v17 = &PackableHashTable<unsigned long,double>::vftable;
      *((_DWORD *)v17 + 1) = 0;
      *((_DWORD *)v17 + 2) = 0;
      *((_DWORD *)v17 + 3) = 8;
      *((_DWORD *)v17 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v17);
      v19 = (PackableHashTable<unsigned long,double> *)v18;
    }
    else
    {
      v19 = 0;
    }
    v3->_floatStatsTable = v19;
    ((void (__stdcall *)(void **, unsigned int))v19->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 8 )
  {
    v20 = operator new(0x14u);
    v21 = v20;
    if ( v20 )
    {
      *(_DWORD *)v20 = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable;
      *((_DWORD *)v20 + 1) = 0;
      *((_DWORD *)v20 + 2) = 0;
      *((_DWORD *)v20 + 3) = 8;
      *((_DWORD *)v20 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v20);
      v22 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)v21;
    }
    else
    {
      v22 = 0;
    }
    v3->_strStatsTable = v22;
    ((void (__stdcall *)(void **, unsigned int))v22->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( BYTE1(v5) & 0x10 )
  {
    v23 = operator new(0x14u);
    v24 = v23;
    if ( v23 )
    {
      *(_DWORD *)v23 = &PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable;
      *((_DWORD *)v23 + 1) = 0;
      *((_DWORD *)v23 + 2) = 0;
      *((_DWORD *)v23 + 3) = 8;
      *((_DWORD *)v23 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v23);
      v25 = (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v24;
    }
    else
    {
      v25 = 0;
    }
    v3->_didStatsTable = v25;
    ((void (__stdcall *)(void **, unsigned int))v25->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 0x10 )
  {
    v26 = operator new(0x10u);
    v27 = v26;
    if ( v26 )
    {
      v28 = (int)((char *)v26 + 4);
      *(_DWORD *)v28 = 0;
      *(_DWORD *)(v28 + 4) = 0;
      *(_DWORD *)(v28 + 8) = 0;
      AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)((char *)v26 + 4), 8u);
      *(_DWORD *)v27 = &PSmartArray<unsigned long>::vftable;
      v29 = (PSmartArray<unsigned long> *)v27;
    }
    else
    {
      v29 = 0;
    }
    v3->_spellBook = v29;
    ((void (__stdcall *)(void **, unsigned int))v29->vfptr->UnPack)(v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (char)v5 >= 0 )
  {
    v31 = size;
  }
  else
  {
    v30 = operator new(0x24u);
    if ( v30 )
    {
      *(_DWORD *)v30 = &ArmorProfile::vftable;
      *((_DWORD *)v30 + 1) = 1065353216;
      *((_DWORD *)v30 + 2) = 1065353216;
      *((_DWORD *)v30 + 3) = 1065353216;
      *((_DWORD *)v30 + 4) = 1065353216;
      *((_DWORD *)v30 + 5) = 1065353216;
      *((_DWORD *)v30 + 6) = 1065353216;
      *((_DWORD *)v30 + 7) = 1065353216;
      *((_DWORD *)v30 + 8) = 1065353216;
    }
    else
    {
      v30 = 0;
    }
    v31 = size;
    v3->armor_profile = (ArmorProfile *)v30;
    (*(void (__thiscall **)(void *, void **, unsigned int))(*(_DWORD *)v30 + 16))(v30, v4, size);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( BYTE1(v5) & 1 )
  {
    v32 = (CreatureAppraisalProfile *)operator new(0x38u);
    if ( v32 )
      CreatureAppraisalProfile::CreatureAppraisalProfile(v32);
    else
      v33 = 0;
    v3->creature_profile = v33;
    ((void (__thiscall *)(CreatureAppraisalProfile *, void **, unsigned int))v33->vfptr->UnPack)(v33, v4, v31);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 0x20 )
  {
    v34 = (WeaponProfile *)operator new(0x48u);
    if ( v34 )
      WeaponProfile::WeaponProfile(v34);
    else
      v35 = 0;
    v3->weapon_profile = v35;
    ((void (__thiscall *)(WeaponProfile *, void **, unsigned int))v35->vfptr->UnPack)(v35, v4, v31);
    LOWORD(v5) = (_WORD)addra;
  }
  if ( (unsigned __int8)v5 & 0x40 )
  {
    v36 = (HookAppraisalProfile *)operator new(0x10u);
    v37 = v36;
    if ( v36 )
    {
      v36->vfptr = (PackObjVtbl *)&HookAppraisalProfile::vftable;
      HookAppraisalProfile::Clear(v36);
      v38 = v37;
    }
    else
    {
      v38 = 0;
    }
    v3->hook_profile = v38;
    ((void (__stdcall *)(void **, unsigned int))v38->vfptr->UnPack)(v4, size);
    BYTE1(v5) = BYTE1(addra);
  }
  if ( BYTE1(v5) & 2 )
  {
    v3->armor_ench_bitfield = *(_DWORD *)*v4;
    *v4 = (char *)*v4 + 4;
  }
  if ( BYTE1(v5) & 8 )
  {
    v3->weapon_ench_bitfield = *(_DWORD *)*v4;
    *v4 = (char *)*v4 + 4;
  }
  if ( BYTE1(v5) & 4 )
  {
    v3->resist_ench_bitfield = *(_DWORD *)*v4;
    *v4 = (char *)*v4 + 4;
  }
  if ( BYTE1(v5) & 0x40 )
  {
    v3->base_armor_head = *(_DWORD *)*v4;
    v39 = (int)((char *)*v4 + 4);
    *v4 = (void *)v39;
    v3->base_armor_chest = *(_DWORD *)v39;
    v40 = (int)((char *)*v4 + 4);
    *v4 = (void *)v40;
    v3->base_armor_groin = *(_DWORD *)v40;
    v41 = (int)((char *)*v4 + 4);
    *v4 = (void *)v41;
    v3->base_armor_bicep = *(_DWORD *)v41;
    v42 = (int)((char *)*v4 + 4);
    *v4 = (void *)v42;
    v3->base_armor_wrist = *(_DWORD *)v42;
    v43 = (int)((char *)*v4 + 4);
    *v4 = (void *)v43;
    v3->base_armor_hand = *(_DWORD *)v43;
    v44 = (int)((char *)*v4 + 4);
    *v4 = (void *)v44;
    v3->base_armor_thigh = *(_DWORD *)v44;
    v45 = (int)((char *)*v4 + 4);
    *v4 = (void *)v45;
    v3->base_armor_shin = *(_DWORD *)v45;
    v46 = (int)((char *)*v4 + 4);
    *v4 = (void *)v46;
    v3->base_armor_foot = *(_DWORD *)v46;
    *v4 = (char *)*v4 + 4;
  }
  if ( size >= (_BYTE *)*v4 - (_BYTE *)v48 )
  {
    result = 1;
  }
  else
  {
    *v4 = v48;
    result = 0;
  }
  return result;
}
// 7AF2FC: using guessed type int (__thiscall *ArmorProfile::vftable)(void *, char);
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);
// 7E441C: using guessed type int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char);
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);
// 7E4458: using guessed type int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char);
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);
// 7E657C: using guessed type int (__thiscall *HookAppraisalProfile::vftable)(void *, char);
// 7E65A4: using guessed type int (__thiscall *PSmartArray<unsigned long>::vftable)(void *, char);

//----- (005B3D80) --------------------------------------------------------  // acclient.c:478761
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,long> **mine, PackableHashTable<unsigned long,long> *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,long> *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,long> *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,long>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
          (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
          (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
      (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)*mine,
      (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);

//----- (005B3E00) --------------------------------------------------------  // acclient.c:478801
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,__int64> **mine, PackableHashTable<unsigned long,__int64> *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,__int64> *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,__int64> *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,__int64>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,__int64>::operator=((PackableHashTable<unsigned long,double> *)v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,__int64>::operator=((PackableHashTable<unsigned long,double> *)*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E441C: using guessed type int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char);

//----- (005B3E80) --------------------------------------------------------  // acclient.c:478837
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,int> **mine, PackableHashTable<unsigned long,int> *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,int> *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,int> *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,int>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
          (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
          (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
      (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)*mine,
      (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);

//----- (005B3F00) --------------------------------------------------------  // acclient.c:478877
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,double> **mine, PackableHashTable<unsigned long,double> *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,double> *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,double> *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,double>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,__int64>::operator=(v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,__int64>::operator=(*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);

//----- (005B3F80) --------------------------------------------------------  // acclient.c:478913
void __cdecl CopyTheFucker(PSmartArray<unsigned long> **mine, PSmartArray<unsigned long> *theirs)
{
  void *v2; // eax@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x10u);
      if ( v2 )
      {
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 0;
        *(_DWORD *)v2 = &PSmartArray<unsigned long>::vftable;
        *mine = (PSmartArray<unsigned long> *)v2;
        AC1Legacy::SmartArray<unsigned long>::operator=(
          (AC1Legacy::SmartArray<Season *> *)((char *)v2 + 4),
          (int)&theirs->m_data);
        return;
      }
      *mine = 0;
    }
    AC1Legacy::SmartArray<unsigned long>::operator=(
      (AC1Legacy::SmartArray<Season *> *)&(*mine)->m_data,
      (int)&theirs->m_data);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E65A4: using guessed type int (__thiscall *PSmartArray<unsigned long>::vftable)(void *, char);

//----- (005B4000) --------------------------------------------------------  // acclient.c:478949
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > **mine, PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
          (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
          (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
      (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)*mine,
      (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E4458: using guessed type int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (005B4080) --------------------------------------------------------  // acclient.c:478989
void __cdecl CopyTheFucker(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > **mine, PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *theirs)
{
  void *v2; // eax@5
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // esi@5

  if ( theirs )
  {
    if ( !*mine )
    {
      v2 = operator new(0x14u);
      v3 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)v2;
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 32;
        *((_DWORD *)v2 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
        *mine = v3;
        PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::operator=(v3, (int)theirs);
        return;
      }
      *mine = 0;
    }
    PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::operator=(*mine, (int)theirs);
  }
  else if ( *mine )
  {
    ((void (__stdcall *)(_DWORD))(*mine)->vfptr->__vecDelDtor)(1);
    *mine = theirs;
  }
}
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (005B4100) --------------------------------------------------------  // acclient.c:479025
int __thiscall AppraisalProfile::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( this != a2 )
  {
    CopyTheFucker(
      (PackableHashTable<unsigned long,long> **)(this + 24),
      *(PackableHashTable<unsigned long,long> **)(a2 + 24));
    CopyTheFucker(
      (PackableHashTable<unsigned long,__int64> **)(v2 + 28),
      *(PackableHashTable<unsigned long,__int64> **)(a2 + 28));
    CopyTheFucker(
      (PackableHashTable<unsigned long,int> **)(v2 + 32),
      *(PackableHashTable<unsigned long,int> **)(a2 + 32));
    CopyTheFucker(
      (PackableHashTable<unsigned long,double> **)(v2 + 36),
      *(PackableHashTable<unsigned long,double> **)(a2 + 36));
    CopyTheFucker(
      (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > **)(v2 + 40),
      *(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > **)(a2 + 40));
    CopyTheFucker(
      (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > **)(v2 + 44),
      *(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > **)(a2 + 44));
    CopyTheFucker((PSmartArray<unsigned long> **)(v2 + 48), *(PSmartArray<unsigned long> **)(a2 + 48));
    CopyTheFucker((CreatureAppraisalProfile **)(v2 + 8), *(CreatureAppraisalProfile **)(a2 + 8));
    CopyTheFucker((WeaponProfile **)(v2 + 16), *(WeaponProfile **)(a2 + 16));
    CopyTheFucker((ArmorProfile **)(v2 + 20), *(ArmorProfile **)(a2 + 20));
    CopyTheFucker((HookAppraisalProfile **)(v2 + 12), *(HookAppraisalProfile **)(a2 + 12));
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(v2 + 60) = *(_DWORD *)(a2 + 60);
    *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
    *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
    *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
    *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(v2 + 88) = *(_DWORD *)(a2 + 88);
    *(_DWORD *)(v2 + 92) = *(_DWORD *)(a2 + 92);
    *(_DWORD *)(v2 + 96) = *(_DWORD *)(a2 + 96);
  }
  return v2;
}

