/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CreatureAppraisalProfile
   Object     : AC\acappraisal\CreatureAppraisalProfile.obj
   Functions  : 8
   Addresses  : 005B5D20 - 005B6190 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B5D20) --------------------------------------------------------  // acclient.c:480544
int __thiscall CreatureAppraisalProfile::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
  }
  return result;
}

//----- (005B5D80) --------------------------------------------------------  // acclient.c:480569
int __thiscall CreatureAppraisalProfile::InqAttribute(CreatureAppraisalProfile *this, unsigned int stype, unsigned int *retval)
{
  int result; // eax@2
  unsigned int v4; // edx@3

  switch ( stype )
  {
    case 1u:
      *retval = this->strength;
      return *retval != 0;
    case 2u:
      v4 = this->endurance;
      goto LABEL_8;
    case 3u:
      *retval = this->quickness;
      return *retval != 0;
    case 4u:
      v4 = this->coordination;
      goto LABEL_8;
    case 5u:
      *retval = this->focus;
      result = *retval != 0;
      break;
    case 6u:
      v4 = this->self;
LABEL_8:
      *retval = v4;
      result = v4 != 0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B5E20) --------------------------------------------------------  // acclient.c:480606
int __thiscall CreatureAppraisalProfile::InqAttribute2nd(CreatureAppraisalProfile *this, unsigned int stype, unsigned int *retval)
{
  int result; // eax@2
  unsigned int v4; // edx@3

  switch ( stype )
  {
    case 2u:
      *retval = this->health;
      return *retval != 0;
    case 4u:
      v4 = this->stamina;
      goto LABEL_8;
    case 6u:
      *retval = this->mana;
      return *retval != 0;
    case 1u:
      v4 = this->max_health;
      goto LABEL_8;
    case 3u:
      *retval = this->max_stamina;
      result = *retval != 0;
      break;
    case 5u:
      v4 = this->max_mana;
LABEL_8:
      *retval = v4;
      result = v4 != 0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B5EC0) --------------------------------------------------------  // acclient.c:480643
int __thiscall CreatureAppraisalProfile::InqAttributeEnchantmentMod(CreatureAppraisalProfile *this, unsigned int stype, int *raised)
{
  unsigned int v3; // eax@2
  int result; // eax@3
  unsigned int v5; // eax@4
  unsigned int v6; // eax@6
  unsigned int v7; // eax@8
  unsigned int v8; // eax@10
  unsigned int v9; // eax@12

  switch ( stype )
  {
    case 1u:
      v3 = this->enchantment_bitfield;
      if ( !(v3 & 1) )
        goto LABEL_14;
      *raised = v3 & 0x10000;
      result = 1;
      break;
    case 2u:
      v5 = this->enchantment_bitfield;
      if ( !(v5 & 2) )
        goto LABEL_14;
      *raised = v5 & 0x20000;
      result = 1;
      break;
    case 3u:
      v6 = this->enchantment_bitfield;
      if ( !(v6 & 4) )
        goto LABEL_14;
      *raised = v6 & 0x40000;
      result = 1;
      break;
    case 4u:
      v7 = this->enchantment_bitfield;
      if ( !(v7 & 8) )
        goto LABEL_14;
      *raised = v7 & 0x80000;
      result = 1;
      break;
    case 5u:
      v8 = this->enchantment_bitfield;
      if ( !(v8 & 0x10) )
        goto LABEL_14;
      *raised = v8 & 0x100000;
      result = 1;
      break;
    case 6u:
      v9 = this->enchantment_bitfield;
      if ( !(v9 & 0x20) )
        goto LABEL_14;
      *raised = v9 & 0x200000;
      result = 1;
      break;
    default:
LABEL_14:
      result = 0;
      break;
  }
  return result;
}

//----- (005B5FB0) --------------------------------------------------------  // acclient.c:480706
int __thiscall CreatureAppraisalProfile::InqAttribute2ndEnchantmentMod(CreatureAppraisalProfile *this, unsigned int stype, int *raised)
{
  unsigned int v3; // eax@4
  unsigned int v5; // eax@6
  unsigned int v6; // eax@8

  switch ( stype )
  {
    case 1u:
      v6 = this->enchantment_bitfield;
      if ( v6 & 0x40 )
      {
        *raised = v6 & 0x400000;
        return 1;
      }
      break;
    case 3u:
      v5 = this->enchantment_bitfield;
      if ( (v5 & 0x80u) != 0 )
      {
        *raised = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v5;
        return 1;
      }
      break;
    case 5u:
      v3 = this->enchantment_bitfield;
      if ( BYTE1(v3) & 1 )
      {
        *raised = v3 & 0x1000000;
        return 1;
      }
      break;
  }
  return 0;
}

//----- (005B6020) --------------------------------------------------------  // acclient.c:480743
void __thiscall CreatureAppraisalProfile::CreatureAppraisalProfile(CreatureAppraisalProfile *this)
{
  this->vfptr = (PackObjVtbl *)&CreatureAppraisalProfile::vftable;
  this->strength = 0;
  this->endurance = 0;
  this->quickness = 0;
  this->coordination = 0;
  this->focus = 0;
  this->self = 0;
  this->health = 0;
  this->stamina = 0;
  this->mana = 0;
  this->max_health = 0;
  this->max_stamina = 0;
  this->max_mana = 0;
  this->enchantment_bitfield = 0;
}
// 7E6CC4: using guessed type int (__thiscall *CreatureAppraisalProfile::vftable)(void *, char);

//----- (005B6060) --------------------------------------------------------  // acclient.c:480763
unsigned int __thiscall CreatureAppraisalProfile::Pack(CreatureAppraisalProfile *this, void **addr, unsigned int size)
{
  unsigned int result; // eax@1
  unsigned int v4; // esi@6
  unsigned int v5; // ebp@8
  signed int v6; // ebx@11
  char *v7; // edi@15
  char *v8; // esi@15
  char *v9; // ebp@15
  char *v10; // esi@15
  char *v11; // esi@16
  char *v12; // ebp@16
  char *v13; // edi@16
  char *v14; // esi@16
  char *v15; // ebp@16
  char *v16; // edi@16
  char *v17; // esi@16
  char *v18; // ebp@16
  char *v19; // edi@16

  result = 12;
  if ( *addr )
  {
    v4 = this->enchantment_bitfield;
    if ( v4 )
      result = 16;
    v5 = this->max_stamina;
    if ( v5 )
      result += 40;
    if ( size >= result )
    {
      v6 = 0;
      if ( v4 )
        v6 = 1;
      if ( v5 )
        v6 |= 8u;
      *(_DWORD *)*addr = v6;
      v7 = (char *)*addr + 4;
      *addr = v7;
      *(_DWORD *)v7 = this->health;
      v8 = (char *)*addr + 4;
      *addr = v8;
      *(_DWORD *)v8 = this->max_health;
      v9 = (char *)*addr + 4;
      *addr = v9;
      v10 = v9;
      if ( v6 & 8 )
      {
        *(_DWORD *)v9 = this->strength;
        v11 = (char *)*addr + 4;
        *addr = v11;
        *(_DWORD *)v11 = this->endurance;
        v12 = (char *)*addr + 4;
        *addr = v12;
        *(_DWORD *)v12 = this->quickness;
        v13 = (char *)*addr + 4;
        *addr = v13;
        *(_DWORD *)v13 = this->coordination;
        v14 = (char *)*addr + 4;
        *addr = v14;
        *(_DWORD *)v14 = this->focus;
        v15 = (char *)*addr + 4;
        *addr = v15;
        *(_DWORD *)v15 = this->self;
        v16 = (char *)*addr + 4;
        *addr = v16;
        *(_DWORD *)v16 = this->stamina;
        v17 = (char *)*addr + 4;
        *addr = v17;
        *(_DWORD *)v17 = this->mana;
        v18 = (char *)*addr + 4;
        *addr = v18;
        *(_DWORD *)v18 = this->max_stamina;
        v19 = (char *)*addr + 4;
        *addr = v19;
        *(_DWORD *)v19 = this->max_mana;
        v10 = (char *)*addr + 4;
        *addr = v10;
      }
      if ( v6 & 1 )
      {
        *(_DWORD *)v10 = this->enchantment_bitfield;
        *addr = (char *)*addr + 4;
      }
    }
  }
  else
  {
    if ( this->enchantment_bitfield )
      result = 16;
    if ( this->max_stamina )
      result += 40;
  }
  return result;
}

//----- (005B6190) --------------------------------------------------------  // acclient.c:480860
int __thiscall CreatureAppraisalProfile::UnPack(CreatureAppraisalProfile *this, void **addr, unsigned int size)
{
  unsigned int v3; // eax@1
  int result; // eax@6
  void *v5; // edi@7
  int v6; // ebx@7
  char *v7; // edx@7
  char *v8; // edx@7
  char *v9; // esi@7
  char *v10; // esi@8
  char *v11; // edx@8
  char *v12; // esi@8
  char *v13; // edx@8
  char *v14; // esi@8
  char *v15; // edx@8
  char *v16; // esi@8
  char *v17; // edx@8
  char *v18; // esi@8

  v3 = 12;
  if ( this->enchantment_bitfield )
    v3 = 16;
  if ( this->max_stamina )
    v3 += 40;
  if ( size >= v3 )
  {
    v5 = *addr;
    v6 = *(_DWORD *)*addr;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->health = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->max_health = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    if ( v6 & 8 )
    {
      this->strength = *(_DWORD *)v9;
      v10 = (char *)*addr + 4;
      *addr = v10;
      this->endurance = *(_DWORD *)v10;
      v11 = (char *)*addr + 4;
      *addr = v11;
      this->quickness = *(_DWORD *)v11;
      v12 = (char *)*addr + 4;
      *addr = v12;
      this->coordination = *(_DWORD *)v12;
      v13 = (char *)*addr + 4;
      *addr = v13;
      this->focus = *(_DWORD *)v13;
      v14 = (char *)*addr + 4;
      *addr = v14;
      this->self = *(_DWORD *)v14;
      v15 = (char *)*addr + 4;
      *addr = v15;
      this->stamina = *(_DWORD *)v15;
      v16 = (char *)*addr + 4;
      *addr = v16;
      this->mana = *(_DWORD *)v16;
      v17 = (char *)*addr + 4;
      *addr = v17;
      this->max_stamina = *(_DWORD *)v17;
      v18 = (char *)*addr + 4;
      *addr = v18;
      this->max_mana = *(_DWORD *)v18;
      *addr = (char *)*addr + 4;
    }
    else
    {
      this->strength = 0;
      this->endurance = 0;
      this->quickness = 0;
      this->coordination = 0;
      this->focus = 0;
      this->self = 0;
      this->stamina = 0;
      this->mana = 0;
      this->max_stamina = 0;
      this->max_mana = 0;
    }
    if ( v6 & 1 )
    {
      this->enchantment_bitfield = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
    }
    else
    {
      this->enchantment_bitfield = 0;
    }
    if ( size >= (_BYTE *)*addr - (_BYTE *)v5 )
    {
      result = 1;
    }
    else
    {
      *addr = v5;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

