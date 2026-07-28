/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AttributeCache
   Object     : AC\acqualities\AttributeCache.obj
   Functions  : 13
   Addresses  : 005CC440 - 005CD4D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CC440) --------------------------------------------------------  // acclient.c:504085
void __thiscall AttributeCache::CleanUp(AttributeCache *this)
{
  AttributeCache *v1; // esi@1
  Attribute *v2; // ecx@1
  Attribute *v3; // ecx@3
  Attribute *v4; // ecx@5
  Attribute *v5; // ecx@7
  Attribute *v6; // ecx@9
  Attribute *v7; // ecx@11
  SecondaryAttribute *v8; // ecx@13
  SecondaryAttribute *v9; // ecx@15
  SecondaryAttribute *v10; // ecx@17

  v1 = this;
  v2 = this->_strength;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_strength = 0;
  }
  v3 = v1->_endurance;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->_endurance = 0;
  }
  v4 = v1->_quickness;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->_quickness = 0;
  }
  v5 = v1->_coordination;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->_coordination = 0;
  }
  v6 = v1->_focus;
  if ( v6 )
  {
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v1->_focus = 0;
  }
  v7 = v1->_self;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    v1->_self = 0;
  }
  v8 = v1->_health;
  if ( v8 )
  {
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->_health = 0;
  }
  v9 = v1->_stamina;
  if ( v9 )
  {
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v1->_stamina = 0;
  }
  v10 = v1->_mana;
  if ( v10 )
  {
    ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    v1->_mana = 0;
  }
}

//----- (005CC4E0) --------------------------------------------------------  // acclient.c:504156
int __thiscall AttributeCache::InqAttribute(AttributeCache *this, unsigned int stype, unsigned int *retval)
{
  Attribute *v3; // ecx@2
  int result; // eax@3
  Attribute *v5; // ecx@4
  Attribute *v6; // ecx@6
  Attribute *v7; // ecx@8
  Attribute *v8; // ecx@10
  Attribute *v9; // ecx@12

  switch ( stype )
  {
    case 1u:
      v3 = this->_strength;
      if ( !v3 )
        goto LABEL_14;
      *retval = v3->_level_from_cp + v3->_init_level;
      result = 1;
      break;
    case 2u:
      v5 = this->_endurance;
      if ( !v5 )
        goto LABEL_14;
      *retval = v5->_level_from_cp + v5->_init_level;
      result = 1;
      break;
    case 3u:
      v6 = this->_quickness;
      if ( !v6 )
        goto LABEL_14;
      *retval = v6->_level_from_cp + v6->_init_level;
      result = 1;
      break;
    case 4u:
      v7 = this->_coordination;
      if ( !v7 )
        goto LABEL_14;
      *retval = v7->_level_from_cp + v7->_init_level;
      result = 1;
      break;
    case 5u:
      v8 = this->_focus;
      if ( !v8 )
        goto LABEL_14;
      *retval = v8->_level_from_cp + v8->_init_level;
      result = 1;
      break;
    case 6u:
      v9 = this->_self;
      if ( !v9 )
        goto LABEL_14;
      *retval = v9->_level_from_cp + v9->_init_level;
      result = 1;
      break;
    default:
LABEL_14:
      result = 0;
      break;
  }
  return result;
}

//----- (005CC5D0) --------------------------------------------------------  // acclient.c:504219
int __thiscall AttributeCache::InqAttribute2nd(AttributeCache *this, unsigned int stype, unsigned int *retval)
{
  SecondaryAttribute *v3; // ecx@2
  int result; // eax@3
  SecondaryAttribute *v5; // ecx@4
  SecondaryAttribute *v6; // ecx@7
  SecondaryAttribute *v7; // ecx@9
  SecondaryAttribute *v8; // ecx@11

  switch ( stype )
  {
    case 1u:
      v3 = this->_health;
      if ( !v3 )
        goto LABEL_14;
      *retval = v3->_level_from_cp + v3->_init_level;
      return 1;
    case 2u:
      v5 = this->_health;
      goto LABEL_5;
    case 3u:
      v6 = this->_stamina;
      if ( !v6 )
        goto LABEL_14;
      *retval = v6->_level_from_cp + v6->_init_level;
      return 1;
    case 4u:
      v7 = this->_stamina;
      if ( !v7 )
        goto LABEL_14;
      *retval = v7->_current_level;
      return 1;
    case 5u:
      v8 = this->_mana;
      if ( !v8 )
        goto LABEL_14;
      *retval = v8->_level_from_cp + v8->_init_level;
      return 1;
    case 6u:
      v5 = this->_mana;
LABEL_5:
      if ( !v5 )
        goto LABEL_14;
      *retval = v5->_current_level;
      result = 1;
      break;
    default:
LABEL_14:
      result = 0;
      break;
  }
  return result;
}

//----- (005CC6A0) --------------------------------------------------------  // acclient.c:504274
void __thiscall AttributeCache::AttributeCache(AttributeCache *this)
{
  this->vfptr = (PackObjVtbl *)&AttributeCache::vftable;
  this->_strength = 0;
  this->_endurance = 0;
  this->_quickness = 0;
  this->_coordination = 0;
  this->_focus = 0;
  this->_self = 0;
  this->_health = 0;
  this->_stamina = 0;
  this->_mana = 0;
}
// 7E83C0: using guessed type int (__thiscall *AttributeCache::vftable)(void *, char);

//----- (005CC6D0) --------------------------------------------------------  // acclient.c:504290
int __thiscall AttributeCache::InqAttribute(AttributeCache *this, unsigned int stype, Attribute *retval)
{
  Attribute *v3; // ecx@2
  int result; // eax@4

  switch ( stype )
  {
    case 1u:
      v3 = this->_strength;
      goto LABEL_3;
    case 2u:
      v3 = this->_endurance;
      goto LABEL_3;
    case 3u:
      v3 = this->_quickness;
      goto LABEL_3;
    case 4u:
      v3 = this->_coordination;
      goto LABEL_3;
    case 5u:
      v3 = this->_focus;
      goto LABEL_3;
    case 6u:
      v3 = this->_self;
LABEL_3:
      if ( !v3 )
        goto LABEL_10;
      retval->_level_from_cp = v3->_level_from_cp;
      retval->_init_level = v3->_init_level;
      retval->_cp_spent = v3->_cp_spent;
      result = 1;
      break;
    default:
LABEL_10:
      result = 0;
      break;
  }
  return result;
}

//----- (005CC740) --------------------------------------------------------  // acclient.c:504331
int __thiscall AttributeCache::SetAttribute(AttributeCache *this, unsigned int stype, Attribute *val)
{
  AttributeCache *v3; // esi@1
  Attribute *v4; // eax@2
  Attribute *v5; // eax@3
  Attribute *v6; // eax@4
  int result; // eax@4
  Attribute *v8; // eax@8
  Attribute *v9; // eax@9
  Attribute *v10; // eax@12
  Attribute *v11; // eax@13
  Attribute *v12; // eax@16
  Attribute *v13; // eax@17
  Attribute *v14; // eax@20
  Attribute *v15; // eax@21
  Attribute *v16; // eax@24
  Attribute *v17; // eax@25

  v3 = this;
  switch ( stype )
  {
    case 1u:
      v4 = this->_strength;
      if ( v4 )
        goto LABEL_6;
      v5 = (Attribute *)operator new(0x10u);
      if ( v5 )
      {
        Attribute::Attribute(v5, val);
        v3->_strength = v6;
        result = 1;
      }
      else
      {
        v3->_strength = 0;
        result = 1;
      }
      break;
    case 2u:
      v4 = this->_endurance;
      if ( v4 )
        goto LABEL_6;
      v8 = (Attribute *)operator new(0x10u);
      if ( v8 )
      {
        Attribute::Attribute(v8, val);
        v3->_endurance = v9;
        result = 1;
      }
      else
      {
        v3->_endurance = 0;
        result = 1;
      }
      break;
    case 3u:
      v4 = this->_quickness;
      if ( v4 )
        goto LABEL_6;
      v10 = (Attribute *)operator new(0x10u);
      if ( v10 )
      {
        Attribute::Attribute(v10, val);
        v3->_quickness = v11;
        result = 1;
      }
      else
      {
        v3->_quickness = 0;
        result = 1;
      }
      break;
    case 4u:
      v4 = this->_coordination;
      if ( v4 )
        goto LABEL_6;
      v12 = (Attribute *)operator new(0x10u);
      if ( v12 )
      {
        Attribute::Attribute(v12, val);
        v3->_coordination = v13;
        result = 1;
      }
      else
      {
        v3->_coordination = 0;
        result = 1;
      }
      break;
    case 5u:
      v4 = this->_focus;
      if ( v4 )
        goto LABEL_6;
      v14 = (Attribute *)operator new(0x10u);
      if ( v14 )
      {
        Attribute::Attribute(v14, val);
        v3->_focus = v15;
        result = 1;
      }
      else
      {
        v3->_focus = 0;
        result = 1;
      }
      break;
    case 6u:
      v4 = this->_self;
      if ( v4 )
      {
LABEL_6:
        v4->_level_from_cp = val->_level_from_cp;
        v4->_init_level = val->_init_level;
        v4->_cp_spent = val->_cp_spent;
        result = 1;
      }
      else
      {
        v16 = (Attribute *)operator new(0x10u);
        if ( v16 )
        {
          Attribute::Attribute(v16, val);
          v3->_self = v17;
          result = 1;
        }
        else
        {
          v3->_self = 0;
          result = 1;
        }
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005CC910) --------------------------------------------------------  // acclient.c:504471
int __thiscall AttributeCache::SetAttribute(AttributeCache *this, unsigned int stype, const unsigned int val)
{
  AttributeCache *v3; // edi@1
  void *v4; // eax@3
  int result; // eax@7
  void *v6; // eax@9
  void *v7; // eax@15
  void *v8; // eax@21
  void *v9; // eax@27
  void *v10; // eax@33

  v3 = this;
  switch ( stype )
  {
    case 1u:
      if ( !this->_strength )
      {
        v4 = operator new(0x10u);
        if ( v4 )
        {
          *(_DWORD *)v4 = &Attribute::vftable;
          *((_DWORD *)v4 + 1) = 0;
          *((_DWORD *)v4 + 2) = 0;
          *((_DWORD *)v4 + 3) = 0;
        }
        else
        {
          v4 = 0;
        }
        v3->_strength = (Attribute *)v4;
      }
      v3->_strength->_init_level = val;
      result = 1;
      break;
    case 2u:
      if ( !this->_endurance )
      {
        v6 = operator new(0x10u);
        if ( v6 )
        {
          *(_DWORD *)v6 = &Attribute::vftable;
          *((_DWORD *)v6 + 1) = 0;
          *((_DWORD *)v6 + 2) = 0;
          *((_DWORD *)v6 + 3) = 0;
        }
        else
        {
          v6 = 0;
        }
        v3->_endurance = (Attribute *)v6;
      }
      v3->_endurance->_init_level = val;
      result = 1;
      break;
    case 3u:
      if ( !this->_quickness )
      {
        v7 = operator new(0x10u);
        if ( v7 )
        {
          *(_DWORD *)v7 = &Attribute::vftable;
          *((_DWORD *)v7 + 1) = 0;
          *((_DWORD *)v7 + 2) = 0;
          *((_DWORD *)v7 + 3) = 0;
        }
        else
        {
          v7 = 0;
        }
        v3->_quickness = (Attribute *)v7;
      }
      v3->_quickness->_init_level = val;
      result = 1;
      break;
    case 4u:
      if ( !this->_coordination )
      {
        v8 = operator new(0x10u);
        if ( v8 )
        {
          *(_DWORD *)v8 = &Attribute::vftable;
          *((_DWORD *)v8 + 1) = 0;
          *((_DWORD *)v8 + 2) = 0;
          *((_DWORD *)v8 + 3) = 0;
        }
        else
        {
          v8 = 0;
        }
        v3->_coordination = (Attribute *)v8;
      }
      v3->_coordination->_init_level = val;
      result = 1;
      break;
    case 5u:
      if ( !this->_focus )
      {
        v9 = operator new(0x10u);
        if ( v9 )
        {
          *(_DWORD *)v9 = &Attribute::vftable;
          *((_DWORD *)v9 + 1) = 0;
          *((_DWORD *)v9 + 2) = 0;
          *((_DWORD *)v9 + 3) = 0;
        }
        else
        {
          v9 = 0;
        }
        v3->_focus = (Attribute *)v9;
      }
      v3->_focus->_init_level = val;
      result = 1;
      break;
    case 6u:
      if ( !this->_self )
      {
        v10 = operator new(0x10u);
        if ( v10 )
        {
          *(_DWORD *)v10 = &Attribute::vftable;
          *((_DWORD *)v10 + 1) = 0;
          *((_DWORD *)v10 + 2) = 0;
          *((_DWORD *)v10 + 3) = 0;
        }
        else
        {
          v10 = 0;
        }
        v3->_self = (Attribute *)v10;
      }
      v3->_self->_init_level = val;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);

//----- (005CCAD0) --------------------------------------------------------  // acclient.c:504614
int __thiscall AttributeCache::InqAttribute2nd(AttributeCache *this, unsigned int stype, SecondaryAttribute *retval)
{
  SecondaryAttribute *v3; // eax@2
  int result; // eax@4

  switch ( stype )
  {
    case 1u:
    case 2u:
      v3 = this->_health;
      goto LABEL_3;
    case 3u:
    case 4u:
      v3 = this->_stamina;
      goto LABEL_3;
    case 5u:
    case 6u:
      v3 = this->_mana;
LABEL_3:
      if ( !v3 )
        goto LABEL_7;
      retval->_level_from_cp = v3->_level_from_cp;
      retval->_init_level = v3->_init_level;
      retval->_cp_spent = v3->_cp_spent;
      retval->_current_level = v3->_current_level;
      result = 1;
      break;
    default:
LABEL_7:
      result = 0;
      break;
  }
  return result;
}

//----- (005CCB40) --------------------------------------------------------  // acclient.c:504650
int __thiscall AttributeCache::SetAttribute2nd(AttributeCache *this, unsigned int stype, SecondaryAttribute *val)
{
  AttributeCache *v3; // esi@1
  SecondaryAttribute *v4; // eax@2
  SecondaryAttribute *v5; // eax@3
  SecondaryAttribute *v6; // eax@4
  int result; // eax@4
  SecondaryAttribute *v8; // eax@8
  SecondaryAttribute *v9; // eax@9
  SecondaryAttribute *v10; // eax@12
  SecondaryAttribute *v11; // eax@13

  v3 = this;
  switch ( stype )
  {
    case 1u:
    case 2u:
      v4 = this->_health;
      if ( v4 )
        goto LABEL_6;
      v5 = (SecondaryAttribute *)operator new(0x14u);
      if ( v5 )
      {
        SecondaryAttribute::SecondaryAttribute(v5, val);
        v3->_health = v6;
        result = 1;
      }
      else
      {
        v3->_health = 0;
        result = 1;
      }
      break;
    case 3u:
    case 4u:
      v4 = this->_stamina;
      if ( v4 )
        goto LABEL_6;
      v8 = (SecondaryAttribute *)operator new(0x14u);
      if ( v8 )
      {
        SecondaryAttribute::SecondaryAttribute(v8, val);
        v3->_stamina = v9;
        result = 1;
      }
      else
      {
        v3->_stamina = 0;
        result = 1;
      }
      break;
    case 5u:
    case 6u:
      v4 = this->_mana;
      if ( v4 )
      {
LABEL_6:
        v4->_level_from_cp = val->_level_from_cp;
        v4->_init_level = val->_init_level;
        v4->_cp_spent = val->_cp_spent;
        v4->_current_level = val->_current_level;
        result = 1;
      }
      else
      {
        v10 = (SecondaryAttribute *)operator new(0x14u);
        if ( v10 )
        {
          SecondaryAttribute::SecondaryAttribute(v10, val);
          v3->_mana = v11;
          result = 1;
        }
        else
        {
          v3->_mana = 0;
          result = 1;
        }
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005CCC50) --------------------------------------------------------  // acclient.c:504737
int __thiscall AttributeCache::SetAttribute2nd(AttributeCache *this, unsigned int stype, const unsigned int val)
{
  AttributeCache *v3; // edi@1
  void *v4; // eax@3
  int result; // eax@7
  void *v6; // eax@9
  void *v7; // eax@15
  void *v8; // eax@21
  void *v9; // eax@27
  void *v10; // eax@33

  v3 = this;
  switch ( stype )
  {
    case 1u:
      if ( !this->_health )
      {
        v4 = operator new(0x14u);
        if ( v4 )
        {
          *((_DWORD *)v4 + 1) = 0;
          *((_DWORD *)v4 + 2) = 0;
          *((_DWORD *)v4 + 3) = 0;
          *(_DWORD *)v4 = &SecondaryAttribute::vftable;
          *((_DWORD *)v4 + 4) = 0;
        }
        else
        {
          v4 = 0;
        }
        v3->_health = (SecondaryAttribute *)v4;
      }
      v3->_health->_init_level = val;
      result = 1;
      break;
    case 2u:
      if ( !this->_health )
      {
        v6 = operator new(0x14u);
        if ( v6 )
        {
          *((_DWORD *)v6 + 1) = 0;
          *((_DWORD *)v6 + 2) = 0;
          *((_DWORD *)v6 + 3) = 0;
          *(_DWORD *)v6 = &SecondaryAttribute::vftable;
          *((_DWORD *)v6 + 4) = 0;
        }
        else
        {
          v6 = 0;
        }
        v3->_health = (SecondaryAttribute *)v6;
      }
      v3->_health->_current_level = val;
      result = 1;
      break;
    case 3u:
      if ( !this->_stamina )
      {
        v7 = operator new(0x14u);
        if ( v7 )
        {
          *((_DWORD *)v7 + 1) = 0;
          *((_DWORD *)v7 + 2) = 0;
          *((_DWORD *)v7 + 3) = 0;
          *(_DWORD *)v7 = &SecondaryAttribute::vftable;
          *((_DWORD *)v7 + 4) = 0;
        }
        else
        {
          v7 = 0;
        }
        v3->_stamina = (SecondaryAttribute *)v7;
      }
      v3->_stamina->_init_level = val;
      result = 1;
      break;
    case 4u:
      if ( !this->_stamina )
      {
        v8 = operator new(0x14u);
        if ( v8 )
        {
          *((_DWORD *)v8 + 1) = 0;
          *((_DWORD *)v8 + 2) = 0;
          *((_DWORD *)v8 + 3) = 0;
          *(_DWORD *)v8 = &SecondaryAttribute::vftable;
          *((_DWORD *)v8 + 4) = 0;
        }
        else
        {
          v8 = 0;
        }
        v3->_stamina = (SecondaryAttribute *)v8;
      }
      v3->_stamina->_current_level = val;
      result = 1;
      break;
    case 5u:
      if ( !this->_mana )
      {
        v9 = operator new(0x14u);
        if ( v9 )
        {
          *((_DWORD *)v9 + 1) = 0;
          *((_DWORD *)v9 + 2) = 0;
          *((_DWORD *)v9 + 3) = 0;
          *(_DWORD *)v9 = &SecondaryAttribute::vftable;
          *((_DWORD *)v9 + 4) = 0;
        }
        else
        {
          v9 = 0;
        }
        v3->_mana = (SecondaryAttribute *)v9;
      }
      v3->_mana->_init_level = val;
      result = 1;
      break;
    case 6u:
      if ( !this->_mana )
      {
        v10 = operator new(0x14u);
        if ( v10 )
        {
          *((_DWORD *)v10 + 1) = 0;
          *((_DWORD *)v10 + 2) = 0;
          *((_DWORD *)v10 + 3) = 0;
          *(_DWORD *)v10 = &SecondaryAttribute::vftable;
          *((_DWORD *)v10 + 4) = 0;
        }
        else
        {
          v10 = 0;
        }
        v3->_mana = (SecondaryAttribute *)v10;
      }
      v3->_mana->_current_level = val;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (005CCE20) --------------------------------------------------------  // acclient.c:504886
unsigned int __thiscall AttributeCache::Pack(AttributeCache *this, void **addr, unsigned int size)
{
  AttributeCache *v3; // ebx@1
  Attribute *v4; // ecx@1
  signed int v5; // edi@1
  unsigned int v6; // ebp@1
  Attribute *v7; // ecx@3
  Attribute *v8; // ecx@5
  Attribute *v9; // ecx@7
  Attribute *v10; // ecx@9
  Attribute *v11; // ecx@11
  SecondaryAttribute *v12; // ecx@13
  SecondaryAttribute *v13; // ecx@15
  SecondaryAttribute *v14; // ecx@17
  unsigned int v15; // eax@19
  Attribute *v16; // ecx@20
  Attribute *v17; // ecx@22
  Attribute *v18; // ecx@24
  Attribute *v19; // ecx@26
  Attribute *v20; // ecx@28
  Attribute *v21; // ecx@30
  SecondaryAttribute *v22; // ecx@32
  SecondaryAttribute *v23; // ecx@34
  SecondaryAttribute *v24; // ebx@36

  v3 = this;
  v4 = this->_strength;
  v5 = 0;
  v6 = 4;
  if ( v4 )
  {
    v6 = ((int (__stdcall *)(void **, _DWORD))v4->vfptr->Pack)(addr, 0) + 4;
    v5 = 1;
  }
  v7 = v3->_endurance;
  if ( v7 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v7->vfptr->Pack)(addr, 0);
    v5 |= 2u;
  }
  v8 = v3->_quickness;
  if ( v8 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v8->vfptr->Pack)(addr, 0);
    v5 |= 4u;
  }
  v9 = v3->_coordination;
  if ( v9 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v9->vfptr->Pack)(addr, 0);
    v5 |= 8u;
  }
  v10 = v3->_focus;
  if ( v10 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v10->vfptr->Pack)(addr, 0);
    v5 |= 0x10u;
  }
  v11 = v3->_self;
  if ( v11 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v11->vfptr->Pack)(addr, 0);
    v5 |= 0x20u;
  }
  v12 = v3->_health;
  if ( v12 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v12->vfptr->Pack)(addr, 0);
    v5 |= 0x40u;
  }
  v13 = v3->_stamina;
  if ( v13 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v13->vfptr->Pack)(addr, 0);
    v5 |= 0x80u;
  }
  v14 = v3->_mana;
  if ( v14 )
  {
    v6 += ((int (__stdcall *)(void **, _DWORD))v14->vfptr->Pack)(addr, 0);
    v5 |= 0x100u;
  }
  v15 = size;
  if ( size >= v6 )
  {
    *(_DWORD *)*addr = v5;
    *addr = (char *)*addr + 4;
    v16 = v3->_strength;
    if ( v16 )
    {
      ((void (__stdcall *)(void **, unsigned int))v16->vfptr->Pack)(addr, size);
      v15 = size;
    }
    v17 = v3->_endurance;
    if ( v17 )
    {
      ((void (__stdcall *)(void **, unsigned int))v17->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v18 = v3->_quickness;
    if ( v18 )
    {
      ((void (__stdcall *)(void **, unsigned int))v18->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v19 = v3->_coordination;
    if ( v19 )
    {
      ((void (__stdcall *)(void **, unsigned int))v19->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v20 = v3->_focus;
    if ( v20 )
    {
      ((void (__stdcall *)(void **, unsigned int))v20->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v21 = v3->_self;
    if ( v21 )
    {
      ((void (__stdcall *)(void **, unsigned int))v21->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v22 = v3->_health;
    if ( v22 )
    {
      ((void (__stdcall *)(void **, unsigned int))v22->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v23 = v3->_stamina;
    if ( v23 )
    {
      ((void (__stdcall *)(void **, unsigned int))v23->vfptr->Pack)(addr, v15);
      v15 = size;
    }
    v24 = v3->_mana;
    if ( v24 )
      ((void (__thiscall *)(SecondaryAttribute *, void **, unsigned int))v24->vfptr->Pack)(v24, addr, v15);
  }
  return v6;
}

//----- (005CCFB0) --------------------------------------------------------  // acclient.c:505029
int __thiscall AttributeCache::UnPack(AttributeCache *this, void **addr, unsigned int size)
{
  void **v3; // ebx@1
  AttributeCache *v4; // esi@1
  void *v5; // ecx@1
  unsigned int v6; // ebp@1
  void **v8; // eax@3
  Attribute *v9; // ecx@3
  void *v10; // eax@5
  Attribute *v11; // ecx@12
  void *v12; // eax@14
  Attribute *v13; // ecx@20
  void *v14; // eax@22
  Attribute *v15; // ecx@28
  void *v16; // eax@30
  Attribute *v17; // ecx@36
  void *v18; // eax@38
  Attribute *v19; // ecx@44
  void *v20; // eax@46
  SecondaryAttribute *v21; // ecx@52
  void *v22; // eax@54
  SecondaryAttribute *v23; // ecx@60
  void *v24; // eax@62
  SecondaryAttribute *v25; // ecx@68
  void *v26; // eax@70
  void *v27; // eax@77
  int v28; // [sp+4Ch] [bp-24h]@4
  int v29; // [sp+50h] [bp-20h]@13
  int v30; // [sp+54h] [bp-1Ch]@21
  int v31; // [sp+58h] [bp-18h]@29
  int v32; // [sp+5Ch] [bp-14h]@37
  int v33; // [sp+60h] [bp-10h]@45
  int v34; // [sp+64h] [bp-Ch]@53
  int v35; // [sp+68h] [bp-8h]@61
  void *v36; // [sp+6Ch] [bp-4h]@1
  void **addra; // [sp+74h] [bp+4h]@3
  int addrb; // [sp+74h] [bp+4h]@69

  v3 = addr;
  v4 = this;
  v5 = *addr;
  v6 = 4;
  v36 = *addr;
  if ( size < 4 )
    return 0;
  v8 = *(void ***)v5;
  *addr = (char *)v5 + 4;
  v9 = v4->_strength;
  addra = v8;
  if ( v9 )
  {
    v28 = (unsigned __int8)v8 & 1;
    if ( (unsigned __int8)v8 & 1 )
    {
      v6 = ((int (__stdcall *)(void **, _DWORD))v9->vfptr->Pack)(v3, 0) + 4;
    }
    else
    {
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      v4->_strength = 0;
    }
  }
  else
  {
    v28 = (unsigned __int8)v8 & 1;
    if ( (unsigned __int8)v8 & 1 )
    {
      v10 = operator new(0x10u);
      if ( v10 )
      {
        *(_DWORD *)v10 = &Attribute::vftable;
        *((_DWORD *)v10 + 1) = 0;
        *((_DWORD *)v10 + 2) = 0;
        *((_DWORD *)v10 + 3) = 0;
      }
      else
      {
        v10 = 0;
      }
      v4->_strength = (Attribute *)v10;
      v6 = (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v10 + 12))(v10, v3, 0) + 4;
    }
  }
  v11 = v4->_endurance;
  if ( v11 )
  {
    v29 = (unsigned __int8)addra & 2;
    if ( (unsigned __int8)addra & 2 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v11->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v4->_endurance = 0;
    }
  }
  else
  {
    v29 = (unsigned __int8)addra & 2;
    if ( (unsigned __int8)addra & 2 )
    {
      v12 = operator new(0x10u);
      if ( v12 )
      {
        *(_DWORD *)v12 = &Attribute::vftable;
        *((_DWORD *)v12 + 1) = 0;
        *((_DWORD *)v12 + 2) = 0;
        *((_DWORD *)v12 + 3) = 0;
        v4->_endurance = (Attribute *)v12;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v12 + 12))(v12, v3, 0);
      }
      else
      {
        v4->_endurance = 0;
        v6 += (*(int (__thiscall **)(_DWORD, void **, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v13 = v4->_quickness;
  if ( v13 )
  {
    v30 = (unsigned __int8)addra & 4;
    if ( (unsigned __int8)addra & 4 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v13->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      v4->_quickness = 0;
    }
  }
  else
  {
    v30 = (unsigned __int8)addra & 4;
    if ( (unsigned __int8)addra & 4 )
    {
      v14 = operator new(0x10u);
      if ( v14 )
      {
        *(_DWORD *)v14 = &Attribute::vftable;
        *((_DWORD *)v14 + 1) = 0;
        *((_DWORD *)v14 + 2) = 0;
        *((_DWORD *)v14 + 3) = 0;
        v4->_quickness = (Attribute *)v14;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v14 + 12))(v14, v3, 0);
      }
      else
      {
        v4->_quickness = 0;
        v6 += (*(int (__thiscall **)(_DWORD, void **, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v15 = v4->_coordination;
  if ( v15 )
  {
    v31 = (unsigned __int8)addra & 8;
    if ( (unsigned __int8)addra & 8 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v15->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      v4->_coordination = 0;
    }
  }
  else
  {
    v31 = (unsigned __int8)addra & 8;
    if ( (unsigned __int8)addra & 8 )
    {
      v16 = operator new(0x10u);
      if ( v16 )
      {
        *(_DWORD *)v16 = &Attribute::vftable;
        *((_DWORD *)v16 + 1) = 0;
        *((_DWORD *)v16 + 2) = 0;
        *((_DWORD *)v16 + 3) = 0;
        v4->_coordination = (Attribute *)v16;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v16 + 12))(v16, v3, 0);
      }
      else
      {
        v4->_coordination = 0;
        v6 += (*(int (__thiscall **)(_DWORD, void **, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v17 = v4->_focus;
  if ( v17 )
  {
    v32 = (unsigned __int8)addra & 0x10;
    if ( (unsigned __int8)addra & 0x10 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v17->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      v4->_focus = 0;
    }
  }
  else
  {
    v32 = (unsigned __int8)addra & 0x10;
    if ( (unsigned __int8)addra & 0x10 )
    {
      v18 = operator new(0x10u);
      if ( v18 )
      {
        *(_DWORD *)v18 = &Attribute::vftable;
        *((_DWORD *)v18 + 1) = 0;
        *((_DWORD *)v18 + 2) = 0;
        *((_DWORD *)v18 + 3) = 0;
        v4->_focus = (Attribute *)v18;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v18 + 12))(v18, v3, 0);
      }
      else
      {
        v4->_focus = 0;
        v6 += (*(int (__thiscall **)(_DWORD, void **, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v19 = v4->_self;
  if ( v19 )
  {
    v33 = (unsigned __int8)addra & 0x20;
    if ( (unsigned __int8)addra & 0x20 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v19->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
      v4->_self = 0;
    }
  }
  else
  {
    v33 = (unsigned __int8)addra & 0x20;
    if ( (unsigned __int8)addra & 0x20 )
    {
      v20 = operator new(0x10u);
      if ( v20 )
      {
        *(_DWORD *)v20 = &Attribute::vftable;
        *((_DWORD *)v20 + 1) = 0;
        *((_DWORD *)v20 + 2) = 0;
        *((_DWORD *)v20 + 3) = 0;
        v4->_self = (Attribute *)v20;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v20 + 12))(v20, v3, 0);
      }
      else
      {
        v4->_self = 0;
        v6 += (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v21 = v4->_health;
  if ( v21 )
  {
    v34 = (unsigned __int8)addra & 0x40;
    if ( (unsigned __int8)addra & 0x40 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v21->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
      v4->_health = 0;
    }
  }
  else
  {
    v34 = (unsigned __int8)addra & 0x40;
    if ( (unsigned __int8)addra & 0x40 )
    {
      v22 = operator new(0x14u);
      if ( v22 )
      {
        *((_DWORD *)v22 + 1) = 0;
        *((_DWORD *)v22 + 2) = 0;
        *((_DWORD *)v22 + 3) = 0;
        *(_DWORD *)v22 = &SecondaryAttribute::vftable;
        *((_DWORD *)v22 + 4) = 0;
        v4->_health = (SecondaryAttribute *)v22;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v22 + 12))(v22, v3, 0);
      }
      else
      {
        v4->_health = 0;
        v6 += (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v23 = v4->_stamina;
  if ( v23 )
  {
    v35 = (unsigned __int8)addra & 0x80;
    if ( (unsigned __int8)addra & 0x80 )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v23->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v23->vfptr->__vecDelDtor)(1);
      v4->_stamina = 0;
    }
  }
  else
  {
    v35 = (unsigned __int8)addra & 0x80;
    if ( (unsigned __int8)addra & 0x80 )
    {
      v24 = operator new(0x14u);
      if ( v24 )
      {
        *((_DWORD *)v24 + 1) = 0;
        *((_DWORD *)v24 + 2) = 0;
        *((_DWORD *)v24 + 3) = 0;
        *(_DWORD *)v24 = &SecondaryAttribute::vftable;
        *((_DWORD *)v24 + 4) = 0;
        v4->_stamina = (SecondaryAttribute *)v24;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v24 + 12))(v24, v3, 0);
      }
      else
      {
        v4->_stamina = 0;
        v6 += (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  v25 = v4->_mana;
  if ( v25 )
  {
    addrb = (unsigned __int16)addra & 0x100;
    if ( addrb )
    {
      v6 += ((int (__stdcall *)(void **, _DWORD))v25->vfptr->Pack)(v3, 0);
    }
    else
    {
      ((void (__stdcall *)(signed int))v25->vfptr->__vecDelDtor)(1);
      v4->_mana = 0;
    }
  }
  else
  {
    addrb = (unsigned __int16)addra & 0x100;
    if ( addrb )
    {
      v26 = operator new(0x14u);
      if ( v26 )
      {
        *((_DWORD *)v26 + 1) = 0;
        *((_DWORD *)v26 + 2) = 0;
        *((_DWORD *)v26 + 3) = 0;
        *(_DWORD *)v26 = &SecondaryAttribute::vftable;
        *((_DWORD *)v26 + 4) = 0;
        v4->_mana = (SecondaryAttribute *)v26;
        v6 += (*(int (__thiscall **)(void *, void **, _DWORD))(*(_DWORD *)v26 + 12))(v26, v3, 0);
      }
      else
      {
        v4->_mana = 0;
        v6 += (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(v0 + 12))(0, v3, 0);
      }
    }
  }
  if ( size < v6 )
  {
    v27 = v36;
LABEL_78:
    *v3 = v27;
    return 0;
  }
  if ( v28 )
    ((void (__stdcall *)(void **, unsigned int))v4->_strength->vfptr->UnPack)(v3, size);
  if ( v29 )
    ((void (__stdcall *)(void **, unsigned int))v4->_endurance->vfptr->UnPack)(v3, size);
  if ( v30 )
    ((void (__stdcall *)(void **, unsigned int))v4->_quickness->vfptr->UnPack)(v3, size);
  if ( v31 )
    ((void (__stdcall *)(void **, unsigned int))v4->_coordination->vfptr->UnPack)(v3, size);
  if ( v32 )
    ((void (__stdcall *)(void **, unsigned int))v4->_focus->vfptr->UnPack)(v3, size);
  if ( v33 )
    ((void (__stdcall *)(void **, unsigned int))v4->_self->vfptr->UnPack)(v3, size);
  if ( v34 )
    ((void (__stdcall *)(void **, unsigned int))v4->_health->vfptr->UnPack)(v3, size);
  if ( v35 )
    ((void (__stdcall *)(void **, unsigned int))v4->_stamina->vfptr->UnPack)(v3, size);
  if ( addrb )
    ((void (__thiscall *)(SecondaryAttribute *, void **, unsigned int))v4->_mana->vfptr->UnPack)(v4->_mana, v3, size);
  v27 = v36;
  if ( size < (_BYTE *)*v3 - (_BYTE *)v36 )
    goto LABEL_78;
  return 1;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (005CD4D0) --------------------------------------------------------  // acclient.c:505437
AttributeCache *__thiscall AttributeCache::scalar_deleting_destructor(AttributeCache *this, unsigned int a2)
{
  AttributeCache *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&AttributeCache::vftable;
  AttributeCache::CleanUp(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E83C0: using guessed type int (__thiscall *AttributeCache::vftable)(void *, char);

