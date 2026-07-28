/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CACQualitiesSkills
   Object     : AC\accqualities\CACQualitiesSkills.obj
   Functions  : 39
   Addresses  : 00591960 - 0070AB60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00591960) --------------------------------------------------------  // acclient.c:442788
unsigned int __thiscall SkillFormula::Calculate(SkillFormula *this, unsigned int attr1, unsigned int attr2, unsigned int *retval)
{
  unsigned int result; // eax@1

  result = this->_z;
  if ( result )
  {
    *retval = (unsigned __int64)_floor((double)(this->_w + attr2 * this->_y + attr1 * this->_x) / (double)result + 0.5);
    result = 1;
  }
  return result;
}

//----- (005919D0) --------------------------------------------------------  // acclient.c:442802
BOOL __thiscall CACQualities::InqAttribute(CACQualities *this, unsigned int stype, Attribute *retval)
{
  AttributeCache *v3; // ecx@1

  v3 = this->_attribCache;
  return v3 && AttributeCache::InqAttribute(v3, stype, retval);
}

//----- (00591A00) --------------------------------------------------------  // acclient.c:442811
int __thiscall CACQualities::InqAttribute(CACQualities *this, unsigned int stype, unsigned int *retval, int raw)
{
  CACQualities *v4; // ebx@1
  AttributeCache *v5; // ecx@1
  int result; // eax@3

  v4 = this;
  v5 = this->_attribCache;
  if ( v5 && AttributeCache::InqAttribute(v5, stype, retval) )
  {
    if ( !raw )
      CACQualities::EnchantAttribute(v4, stype, retval);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00591A50) --------------------------------------------------------  // acclient.c:442833
void __thiscall CACQualities::SetAttribute(CACQualities *this, unsigned int stype, Attribute *val)
{
  CACQualities *v3; // esi@1
  AttributeCache *v4; // eax@2
  AttributeCache *v5; // eax@3

  v3 = this;
  if ( this->_attribCache
    || ((v4 = (AttributeCache *)operator new(0x28u)) == 0 ? (v5 = 0) : AttributeCache::AttributeCache(v4),
        (v3->_attribCache = v5) != 0) )
    AttributeCache::SetAttribute(v3->_attribCache, stype, val);
}

//----- (00591AA0) --------------------------------------------------------  // acclient.c:442847
void __thiscall CACQualities::SetAttribute(CACQualities *this, unsigned int stype, unsigned int init_val)
{
  CACQualities *v3; // esi@1
  AttributeCache *v4; // eax@2
  AttributeCache *v5; // eax@3

  v3 = this;
  if ( this->_attribCache
    || ((v4 = (AttributeCache *)operator new(0x28u)) == 0 ? (v5 = 0) : AttributeCache::AttributeCache(v4),
        (v3->_attribCache = v5) != 0) )
    AttributeCache::SetAttribute(v3->_attribCache, stype, init_val);
}

//----- (00591AF0) --------------------------------------------------------  // acclient.c:442861
BOOL __thiscall CACQualities::InqAttribute2nd(CACQualities *this, unsigned int stype, SecondaryAttribute *retval)
{
  AttributeCache *v3; // ecx@1

  v3 = this->_attribCache;
  return v3 && AttributeCache::InqAttribute2nd(v3, stype, retval);
}

//----- (00591B20) --------------------------------------------------------  // acclient.c:442870
int __stdcall CACQualities::InqMaxRunRate(float *rate)
{
  *rate = MovementSystem::GetRunRate(0.0, 9999, 1.0);
  return 1;
}

//----- (00591B50) --------------------------------------------------------  // acclient.c:442877
BOOL __thiscall CACQualities::CanJump(CACQualities *this, float extent)
{
  float load; // [sp+0h] [bp-4h]@1

  load = 0.0;
  return CACQualities::InqLoad((CACQualities *)((char *)this - 56), &load) && load < 2.0;
}

//----- (00591B90) --------------------------------------------------------  // acclient.c:442886
int __thiscall CACQualities::JumpStaminaCost(CACQualities *this, float extent, int *cost)
{
  CBaseQualities *v3; // esi@1
  int v4; // edi@2
  int result; // eax@7
  unsigned int pkstatus; // [sp+4h] [bp-10h]@2
  float load; // [sp+8h] [bp-Ch]@1
  long double timeLastPKAttack; // [sp+Ch] [bp-8h]@4

  v3 = (CBaseQualities *)this;
  load = 0.0;
  if ( CACQualities::InqLoad((CACQualities *)((char *)this - 56), &load) )
  {
    v4 = 0;
    pkstatus = 8;
    CBaseQualities::InqInt(v3, 0x86u, (int *)&pkstatus, 0, 0);
    if ( pkstatus == 4 || pkstatus == 64 )
    {
      if ( CBaseQualities::InqFloat(v3, 0x91u, &timeLastPKAttack, 0) )
      {
        if ( timeLastPKAttack + 20.0 > COERCE_DOUBLE(Timer::cur_time.Cmd) )
          v4 = 1;
      }
    }
    *cost = MovementSystem::JumpStaminaCost(extent, load, v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00591C50) --------------------------------------------------------  // acclient.c:442921
void __thiscall PackableHashTable<unsigned long,Skill>::PackableHashTable<unsigned long,Skill>(PackableHashTable<unsigned long,Skill> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Skill>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E44CC: using guessed type int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char);

//----- (00591C80) --------------------------------------------------------  // acclient.c:442933
Skill *__thiscall PackableHashTable<unsigned long,Skill>::lookup(PackableHashTable<unsigned long,Skill> *this, const unsigned int *key)
{
  unsigned int v2; // edi@1
  PackableHashData<unsigned long,Skill> **v3; // esi@2
  PackableHashData<unsigned long,Skill> *v4; // edx@3
  Skill *result; // eax@6

  v2 = this->_table_size;
  if ( v2 && (v3 = this->_buckets) != 0 && (v4 = v3[*key % v2]) != 0 )
  {
    while ( *key != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00591CC0) --------------------------------------------------------  // acclient.c:442960
void __thiscall PackableHashData<unsigned long,Skill>::PackableHashData<unsigned long,Skill>(PackableHashData<unsigned long,Skill> *this, const unsigned int *key, Skill *data, int highbound)
{
  this->_key = *key;
  this->_data.vfptr = (PackObjVtbl *)&Skill::vftable;
  this->_data._sac = data->_sac;
  this->_data._pp = data->_pp;
  this->_data._init_level = data->_init_level;
  this->_data._level_from_pp = data->_level_from_pp;
  this->_data._resistance_of_last_check = data->_resistance_of_last_check;
  this->_data._last_used_time = data->_last_used_time;
  this->_next = 0;
  this->_hashVal = *key % highbound;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (00591D20) --------------------------------------------------------  // acclient.c:442976
unsigned int __thiscall CACQualities::InqAttribute2ndBaseLevel(CACQualities *this, unsigned int stype, unsigned int *retval, int raw)
{
  int v4; // edi@1
  int v6; // esi@6
  unsigned int v7; // eax@11
  unsigned int v8; // ebx@11
  unsigned int v9; // esi@15
  CACQualities *v10; // [sp+4h] [bp-Ch]@1
  unsigned int attrib2_val; // [sp+8h] [bp-8h]@11
  unsigned int attrib1_val; // [sp+Ch] [bp-4h]@11

  v10 = this;
  v4 = DBObj::GetByEnum(1, 2, 0x10000003u);
  if ( !v4 )
    return 0;
  if ( stype == 1 )
  {
    v6 = v4 + 56;
  }
  else if ( stype == 3 )
  {
    v6 = v4 + 88;
  }
  else
  {
    if ( stype != 5 )
    {
LABEL_10:
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      return 0;
    }
    v6 = v4 + 120;
  }
  if ( !v6 )
    goto LABEL_10;
  attrib1_val = 0;
  attrib2_val = 0;
  v7 = *(_DWORD *)(v6 + 24);
  v8 = *(_DWORD *)(v6 + 28);
  if ( v7 )
    CACQualities::InqAttribute(v10, v7, &attrib1_val, raw);
  if ( v8 )
    CACQualities::InqAttribute(v10, v8, &attrib2_val, raw);
  v9 = SkillFormula::Calculate((SkillFormula *)(v6 + 4), attrib1_val, attrib2_val, retval);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  return v9;
}

//----- (00591DF0) --------------------------------------------------------  // acclient.c:443025
int __thiscall CACQualities::InqSkill(CACQualities *this, unsigned int stype, Skill *retval)
{
  PackableHashTable<unsigned long,Skill> *v3; // ecx@1
  Skill *v4; // eax@2
  int result; // eax@3
  Skill *v6; // ecx@4

  v3 = this->_skillStatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,Skill>::lookup(v3, &stype)) != 0 )
  {
    v6 = retval;
    retval->_sac = v4->_sac;
    v6->_pp = v4->_pp;
    v6->_init_level = v4->_init_level;
    v6->_level_from_pp = v4->_level_from_pp;
    v6->_resistance_of_last_check = v4->_resistance_of_last_check;
    LODWORD(v6->_last_used_time) = LODWORD(v4->_last_used_time);
    HIDWORD(v6->_last_used_time) = HIDWORD(v4->_last_used_time);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00591E40) --------------------------------------------------------  // acclient.c:443053
int __thiscall CACQualities::InqSkillLevel(CACQualities *this, unsigned int stype, int *retval)
{
  PackableHashTable<unsigned long,Skill> *v3; // ecx@1
  Skill *v4; // eax@2
  int result; // eax@3

  v3 = this->_skillStatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,Skill>::lookup(v3, &stype)) != 0 )
  {
    *retval = v4->_init_level + v4->_level_from_pp;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00591E70) --------------------------------------------------------  // acclient.c:443073
int __thiscall CACQualities::InqSkillAdvancementClass(CACQualities *this, unsigned int stype, SKILL_ADVANCEMENT_CLASS *retval)
{
  PackableHashTable<unsigned long,Skill> *v3; // ecx@1
  Skill *v4; // eax@2
  int result; // eax@3

  v3 = this->_skillStatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,Skill>::lookup(v3, &stype)) != 0 )
  {
    *retval = v4->_sac;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00591EA0) --------------------------------------------------------  // acclient.c:443093
int __thiscall PackableHashTable<unsigned long,Skill>::add(PackableHashTable<unsigned long,Skill> *this, const unsigned int *key, Skill *data)
{
  PackableHashTable<unsigned long,Skill> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,Skill> **v5; // ebx@2
  PackableHashData<unsigned long,Skill> *v6; // edx@3
  PackableHashData<unsigned long,Skill> *v7; // eax@8
  int v8; // eax@9
  int v10; // ecx@11

  v3 = this;
  v4 = this->_table_size;
  if ( v4 )
  {
    v5 = this->_buckets;
    if ( v5 )
    {
      v6 = v5[*key % v4];
      if ( v6 )
      {
        while ( *key != v6->_key )
        {
          v6 = v6->_next;
          if ( !v6 )
            goto LABEL_8;
        }
        if ( v6 != (PackableHashData<unsigned long,Skill> *)-8 )
          return 0;
      }
    }
  }
LABEL_8:
  v7 = (PackableHashData<unsigned long,Skill> *)operator new(0x30u);
  if ( !v7 )
    return 0;
  PackableHashData<unsigned long,Skill>::PackableHashData<unsigned long,Skill>(v7, key, data, v3->_table_size);
  if ( !v8 )
    return 0;
  v10 = *(_DWORD *)(v8 + 44);
  *(_DWORD *)(v8 + 40) = v3->_buckets[v10];
  v3->_buckets[v10] = (PackableHashData<unsigned long,Skill> *)v8;
  ++v3->_currNum;
  return 1;
}

//----- (00591F30) --------------------------------------------------------  // acclient.c:443139
signed int __thiscall PackableHashTable<unsigned long,Skill>::Pack(PackableHashTable<unsigned long,Skill> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,Skill> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,Skill> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,Skill>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (00591FC0) --------------------------------------------------------  // acclient.c:443190
signed int __thiscall PackableHashTable<unsigned long,Skill>::pack_size(PackableHashTable<unsigned long,Skill> *this)
{
  PackableHashTable<unsigned long,Skill> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,Skill> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (00592020) --------------------------------------------------------  // acclient.c:443222
unsigned int __thiscall CACQualities::InqAttribute2nd(CACQualities *this, unsigned int stype, unsigned int *retval, int raw)
{
  unsigned int v4; // esi@1
  unsigned int v5; // ebp@1
  CACQualities *v6; // ebx@1
  unsigned int result; // eax@4
  AttributeCache *v8; // ecx@9
  unsigned int *v9; // edi@9
  unsigned int base; // [sp+Ch] [bp-4h]@1

  v4 = stype;
  v5 = 0;
  v6 = this;
  base = 0;
  if ( stype == 1 || stype == 3 || stype == 5 )
  {
    result = CACQualities::InqAttribute2ndBaseLevel(this, stype, &base, raw);
    if ( !result )
      return result;
    v5 = base;
  }
  if ( v4 == 1 )
  {
    stype = 0;
    if ( CBaseQualities::InqInt((CBaseQualities *)&v6->vfptr, 0x17Bu, (int *)&stype, 0, 0) )
      v5 += stype;
  }
  v8 = v6->_attribCache;
  v9 = retval;
  if ( v8 && AttributeCache::InqAttribute2nd(v8, v4, retval) )
  {
    *v9 += v5;
  }
  else
  {
    if ( !v5 )
      return 0;
    *v9 = v5;
  }
  if ( !raw )
    CACQualities::EnchantAttribute2nd(v6, v4, v9);
  return 1;
}

//----- (005920E0) --------------------------------------------------------  // acclient.c:443267
unsigned int __thiscall CACQualities::BoundsCheck(CACQualities *this, unsigned int stype, int *val, unsigned int *max)
{
  unsigned int result; // eax@4

  if ( stype == 2 || stype == 4 || stype == 6 )
  {
    if ( *val >= 0 )
    {
      result = CACQualities::InqAttribute2nd(this, stype - 1, max, 0);
      if ( result )
      {
        if ( *val > *max )
          *val = *max;
        result = 1;
      }
    }
    else
    {
      *val = 0;
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00592140) --------------------------------------------------------  // acclient.c:443297
int __thiscall CACQualities::InqSkillBaseLevel(CACQualities *this, unsigned int stype, int *retval, int raw)
{
  int result; // eax@1
  int v5; // edi@1
  unsigned int v6; // ebx@2
  SkillBase *v7; // esi@2
  PackableHashTable<unsigned long,Skill> *v8; // ecx@4
  signed int v9; // ebp@4
  Skill *v10; // eax@5
  int v11; // ebp@9
  unsigned int v12; // eax@9
  unsigned int v13; // ebx@9
  unsigned int v14; // esi@13
  CACQualities *v15; // [sp+4h] [bp-Ch]@1
  unsigned int attrib2_val; // [sp+8h] [bp-8h]@9
  unsigned int attrib1_val; // [sp+Ch] [bp-4h]@9

  v15 = this;
  result = DBObj::GetByEnum(4, 2, 0x10000004u);
  v5 = result;
  if ( result )
  {
    v6 = stype;
    v7 = SkillTable::GetSkillBase((SkillTable *)result, stype);
    if ( v7 )
    {
      v8 = v15->_skillStatsTable;
      stype = v6;
      v9 = 1;
      if ( v8 )
      {
        v10 = PackableHashTable<unsigned long,Skill>::lookup(v8, &stype);
        if ( v10 )
          v9 = v10->_sac;
      }
      if ( v9 >= v7->_min_level )
      {
        v11 = raw;
        attrib1_val = 0;
        attrib2_val = 0;
        v12 = v7->_formula._attr1;
        v13 = v7->_formula._attr2;
        if ( v12 )
          CACQualities::InqAttribute(v15, v12, &attrib1_val, raw);
        if ( v13 )
          CACQualities::InqAttribute(v15, v13, &attrib2_val, v11);
        v14 = SkillFormula::Calculate(&v7->_formula, attrib1_val, attrib2_val, (unsigned int *)retval);
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
        result = v14;
      }
      else
      {
        *retval = 0;
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
        result = 1;
      }
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
      result = 0;
    }
  }
  return result;
}

//----- (00592240) --------------------------------------------------------  // acclient.c:443364
int __thiscall CACQualities::SetSkill(CACQualities *this, unsigned int stype, Skill *val)
{
  CACQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,Skill> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,Skill> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,Skill> **v9; // edi@8
  PackableHashData<unsigned long,Skill> *v10; // edx@9
  Skill *v11; // ecx@15

  v3 = this;
  if ( this->_skillStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,Skill> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,Skill>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_skillStatsTable = v5) != 0) )
  {
    v7 = v3->_skillStatsTable;
    v8 = v7->_table_size;
    if ( !v8 )
      goto LABEL_18;
    v9 = v7->_buckets;
    if ( !v9 )
      goto LABEL_18;
    v10 = v9[stype % v8];
    if ( !v10 )
      goto LABEL_18;
    while ( stype != v10->_key )
    {
      v10 = v10->_next;
      if ( !v10 )
        return PackableHashTable<unsigned long,Skill>::add(v7, &stype, val);
    }
    if ( v10 != (PackableHashData<unsigned long,Skill> *)-8 )
    {
      v11 = val;
      v10->_data._sac = val->_sac;
      v10->_data._pp = v11->_pp;
      v10->_data._init_level = v11->_init_level;
      v10->_data._level_from_pp = v11->_level_from_pp;
      v10->_data._resistance_of_last_check = v11->_resistance_of_last_check;
      LODWORD(v10->_data._last_used_time) = LODWORD(v11->_last_used_time);
      HIDWORD(v10->_data._last_used_time) = HIDWORD(v11->_last_used_time);
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,Skill>::add(v7, &stype, val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E44CC: using guessed type int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char);

//----- (00592340) --------------------------------------------------------  // acclient.c:443424
int __thiscall CACQualities::SetSkillLevel(CACQualities *this, unsigned int stype, unsigned int val)
{
  CACQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,Skill> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,Skill> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,Skill> **v9; // edi@8
  PackableHashData<unsigned long,Skill> *v10; // edx@9
  Skill new_skill; // [sp+Ch] [bp-20h]@14

  v3 = this;
  if ( this->_skillStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,Skill> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,Skill>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_skillStatsTable = v5) != 0) )
  {
    v7 = v3->_skillStatsTable;
    v8 = v7->_table_size;
    if ( !v8 )
      goto LABEL_14;
    v9 = v7->_buckets;
    if ( !v9 )
      goto LABEL_14;
    v10 = v9[stype % v8];
    if ( !v10 )
      goto LABEL_14;
    while ( stype != v10->_key )
    {
      v10 = v10->_next;
      if ( !v10 )
        goto LABEL_14;
    }
    if ( v10 != (PackableHashData<unsigned long,Skill> *)-8 )
    {
      v10->_data._init_level = val;
      result = 1;
    }
    else
    {
LABEL_14:
      new_skill._init_level = val;
      new_skill.vfptr = (PackObjVtbl *)&Skill::vftable;
      new_skill._sac = 0;
      new_skill._pp = 0;
      new_skill._level_from_pp = 0;
      new_skill._resistance_of_last_check = 0;
      *(_QWORD *)&new_skill._last_used_time = 0i64;
      result = PackableHashTable<unsigned long,Skill>::add(v7, &stype, &new_skill);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);
// 7E44CC: using guessed type int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char);

//----- (00592430) --------------------------------------------------------  // acclient.c:443485
int __thiscall CACQualities::SetSkillAdvancementClass(CACQualities *this, unsigned int stype, SKILL_ADVANCEMENT_CLASS val)
{
  CACQualities *v3; // ebp@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,Skill> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,Skill> *v7; // eax@7
  unsigned int v8; // ecx@7
  PackableHashData<unsigned long,Skill> **v9; // esi@8
  PackableHashData<unsigned long,Skill> *v10; // edx@9
  Skill new_skill; // [sp+Ch] [bp-20h]@14

  v3 = this;
  if ( this->_skillStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,Skill> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,Skill>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_skillStatsTable = v5) != 0) )
  {
    v7 = v3->_skillStatsTable;
    v8 = v7->_table_size;
    if ( !v8 )
      goto LABEL_14;
    v9 = v7->_buckets;
    if ( !v9 )
      goto LABEL_14;
    v10 = v9[stype % v8];
    if ( !v10 )
      goto LABEL_14;
    while ( stype != v10->_key )
    {
      v10 = v10->_next;
      if ( !v10 )
        goto LABEL_14;
    }
    if ( v10 != (PackableHashData<unsigned long,Skill> *)-8 )
    {
      Skill::SetSkillAdvancementClass(&v10->_data, val);
      result = 1;
    }
    else
    {
LABEL_14:
      new_skill.vfptr = (PackObjVtbl *)&Skill::vftable;
      new_skill._sac = 0;
      new_skill._pp = 0;
      new_skill._init_level = 0;
      new_skill._level_from_pp = 0;
      new_skill._resistance_of_last_check = 0;
      *(_QWORD *)&new_skill._last_used_time = 0i64;
      Skill::SetSkillAdvancementClass(&new_skill, val);
      result = PackableHashTable<unsigned long,Skill>::add(v3->_skillStatsTable, &stype, &new_skill);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);
// 7E44CC: using guessed type int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char);

//----- (00592530) --------------------------------------------------------  // acclient.c:443547
void __thiscall CACQualities::SetAttribute2nd(CACQualities *this, unsigned int stype, SecondaryAttribute *val)
{
  CACQualities *v3; // edi@1
  AttributeCache *v4; // eax@2
  AttributeCache *v5; // eax@3
  unsigned int v6; // edx@6
  unsigned int v7; // ecx@6
  unsigned int v8; // edx@6
  SecondaryAttribute bounded_val; // [sp+4h] [bp-14h]@6

  v3 = this;
  if ( this->_attribCache
    || ((v4 = (AttributeCache *)operator new(0x28u)) == 0 ? (v5 = 0) : AttributeCache::AttributeCache(v4),
        (v3->_attribCache = v5) != 0) )
  {
    v6 = val->_init_level;
    bounded_val._level_from_cp = val->_level_from_cp;
    v7 = val->_cp_spent;
    bounded_val._init_level = v6;
    v8 = val->_current_level;
    bounded_val._cp_spent = v7;
    bounded_val.vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
    bounded_val._current_level = v8;
    if ( stype == 2 || stype == 4 || stype == 6 )
    {
      val = 0;
      if ( !CACQualities::InqAttribute2nd(v3, stype - 1, (unsigned int *)&val, 0) )
        return;
      if ( bounded_val._current_level > (unsigned int)val )
        bounded_val._current_level = (unsigned int)val;
    }
    AttributeCache::SetAttribute2nd(v3->_attribCache, stype, &bounded_val);
  }
}
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (005925F0) --------------------------------------------------------  // acclient.c:443584
void __thiscall CACQualities::SetAttribute2nd(CACQualities *this, unsigned int stype, unsigned int val, unsigned int *bounded_val, unsigned int *max)
{
  CACQualities *v5; // esi@1
  AttributeCache *v6; // eax@2
  AttributeCache *v7; // eax@3

  v5 = this;
  if ( this->_attribCache
    || ((v6 = (AttributeCache *)operator new(0x28u)) == 0 ? (v7 = 0) : AttributeCache::AttributeCache(v6),
        (v5->_attribCache = v7) != 0) )
  {
    *bounded_val = val;
    if ( CACQualities::BoundsCheck(v5, stype, (int *)bounded_val, max) )
      AttributeCache::SetAttribute2nd(v5->_attribCache, stype, *bounded_val);
  }
}

//----- (00592660) --------------------------------------------------------  // acclient.c:443602
int __thiscall CACQualities::InqSkill(CACQualities *this, unsigned int stype, int *retval, int raw)
{
  unsigned int v4; // ebp@1
  int *v5; // edi@1
  CACQualities *v6; // ebx@1
  int result; // eax@1
  PackableHashTable<unsigned long,Skill> *v8; // ecx@2
  Skill *v9; // eax@3
  int v10; // esi@18
  PackableHashTable<unsigned long,Skill> *v11; // ecx@19
  Skill *v12; // eax@20
  unsigned int v13; // [sp-14h] [bp-28h]@9
  int *v14; // [sp-10h] [bp-24h]@9
  int lum_aug; // [sp+Ch] [bp-8h]@2
  unsigned int key; // [sp+10h] [bp-4h]@19

  v4 = stype;
  v5 = retval;
  v6 = this;
  result = CACQualities::InqSkillBaseLevel(this, stype, retval, raw);
  if ( result )
  {
    v8 = v6->_skillStatsTable;
    lum_aug = v4;
    if ( v8 )
    {
      v9 = PackableHashTable<unsigned long,Skill>::lookup(v8, (const unsigned int *)&lum_aug);
      if ( v9 )
        *v5 += v9->_init_level + v9->_level_from_pp;
    }
    stype = 0;
    if ( CBaseQualities::InqInt((CBaseQualities *)&v6->vfptr, 0x16Du, (int *)&stype, 0, 0) && (signed int)stype > 0 )
      *v5 += stype;
    retval = 0;
    switch ( v4 )
    {
      case 0x29u:
      case 0x2Cu:
      case 0x2Du:
      case 0x2Eu:
      case 0x31u:
        v14 = (int *)&retval;
        v13 = 300;
        goto LABEL_12;
      case 0x2Fu:
        v14 = (int *)&retval;
        v13 = 301;
        goto LABEL_12;
      case 0x1Fu:
      case 0x20u:
      case 0x21u:
      case 0x22u:
      case 0x2Bu:
        v14 = (int *)&retval;
        v13 = 302;
LABEL_12:
        CBaseQualities::InqInt((CBaseQualities *)&v6->vfptr, v13, v14, 0, 0);
        if ( (signed int)retval > 0 )
          *v5 += 10;
        break;
      default:
        break;
    }
    if ( !raw )
    {
      raw = 0;
      lum_aug = 0;
      CACQualities::EnchantSkill(v6, v4, v5);
      if ( CBaseQualities::InqInt((CBaseQualities *)&v6->vfptr, 0x146u, &raw, 0, 0) && raw > 0 )
        *v5 += 5;
      CBaseQualities::InqInt((CBaseQualities *)&v6->vfptr, 0x158u, &lum_aug, 0, 0);
      v10 = lum_aug;
      if ( lum_aug > 0 )
      {
        v11 = v6->_skillStatsTable;
        key = v4;
        if ( v11 )
        {
          v12 = PackableHashTable<unsigned long,Skill>::lookup(v11, &key);
          if ( v12 )
          {
            if ( v12->_sac == 3 )
              *v5 += 2 * v10;
          }
        }
      }
    }
    result = 1;
  }
  return result;
}

//----- (00592800) --------------------------------------------------------  // acclient.c:443695
int __thiscall CACQualities::InqRunRate(CACQualities *this, float *rate)
{
  char *v2; // esi@1
  int result; // eax@1
  AttributeCache *v4; // ecx@2
  PackableHashTable<unsigned long,Skill> *v5; // ecx@6
  Skill *v6; // eax@7
  unsigned int v7; // edi@15
  PackableHashTable<unsigned long,Skill> *v8; // ecx@16
  Skill *v9; // eax@17
  int runskill; // [sp+8h] [bp-20h]@4
  int retval; // [sp+Ch] [bp-1Ch]@9
  int v12; // [sp+10h] [bp-18h]@12
  unsigned int key; // [sp+14h] [bp-14h]@6
  unsigned int stamina; // [sp+18h] [bp-10h]@3
  float load; // [sp+1Ch] [bp-Ch]@1
  unsigned int v16; // [sp+20h] [bp-8h]@16
  int v17; // [sp+24h] [bp-4h]@12

  v2 = (char *)&this[-1]._iidStatsTable;
  load = 1.0;
  result = CACQualities::InqLoad((CACQualities *)((char *)this - 56), &load);
  if ( result )
  {
    v4 = (AttributeCache *)*((_DWORD *)v2 + 24);
    if ( v4
      && AttributeCache::InqAttribute2nd(v4, 4u, &stamina)
      && (CACQualities::EnchantAttribute2nd((CACQualities *)v2, 4u, &stamina),
          CACQualities::InqSkillBaseLevel((CACQualities *)v2, 0x18u, &runskill, 0)) )
    {
      v5 = (PackableHashTable<unsigned long,Skill> *)*((_DWORD *)v2 + 25);
      key = 24;
      if ( v5 )
      {
        v6 = PackableHashTable<unsigned long,Skill>::lookup(v5, &key);
        if ( v6 )
          runskill += v6->_init_level + v6->_level_from_pp;
      }
      retval = 0;
      if ( CBaseQualities::InqInt((CBaseQualities *)(v2 + 56), 0x16Du, &retval, 0, 0) && retval > 0 )
        runskill += retval;
      v17 = 0;
      v12 = 0;
      key = 0;
      CACQualities::EnchantSkill((CACQualities *)v2, 0x18u, &runskill);
      if ( CBaseQualities::InqInt((CBaseQualities *)(v2 + 56), 0x146u, &v12, 0, 0) && v12 > 0 )
        runskill += 5;
      CBaseQualities::InqInt((CBaseQualities *)(v2 + 56), 0x158u, (int *)&key, 0, 0);
      v7 = key;
      if ( (signed int)key > 0 )
      {
        v8 = (PackableHashTable<unsigned long,Skill> *)*((_DWORD *)v2 + 25);
        v16 = 24;
        if ( v8 )
        {
          v9 = PackableHashTable<unsigned long,Skill>::lookup(v8, &v16);
          if ( v9 )
          {
            if ( v9->_sac == 3 )
              runskill += 2 * v7;
          }
        }
      }
      if ( !stamina )
        runskill = 0;
      *rate = MovementSystem::GetRunRate(load, runskill, 1.0);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00592980) --------------------------------------------------------  // acclient.c:443772
int __thiscall CACQualities::InqJumpVelocity(CACQualities *this, float extent, float *v_z)
{
  char *v3; // esi@1
  int result; // eax@1
  AttributeCache *v5; // ecx@2
  PackableHashTable<unsigned long,Skill> *v6; // ecx@6
  Skill *v7; // eax@7
  unsigned int v8; // edi@15
  PackableHashTable<unsigned long,Skill> *v9; // ecx@16
  Skill *v10; // eax@17
  double v11; // st7@22
  int jumpskill; // [sp+8h] [bp-20h]@1
  unsigned int stamina; // [sp+Ch] [bp-1Ch]@1
  int retval; // [sp+10h] [bp-18h]@9
  int v15; // [sp+14h] [bp-14h]@12
  unsigned int key; // [sp+18h] [bp-10h]@6
  float load; // [sp+1Ch] [bp-Ch]@1
  unsigned int v18; // [sp+20h] [bp-8h]@16
  int v19; // [sp+24h] [bp-4h]@12

  v3 = (char *)&this[-1]._iidStatsTable;
  load = 1.0;
  result = CACQualities::InqLoad((CACQualities *)((char *)this - 56), &load);
  jumpskill = 1;
  stamina = 0;
  if ( result )
  {
    v5 = (AttributeCache *)*((_DWORD *)v3 + 24);
    if ( v5
      && AttributeCache::InqAttribute2nd(v5, 4u, &stamina)
      && (CACQualities::EnchantAttribute2nd((CACQualities *)v3, 4u, &stamina),
          CACQualities::InqSkillBaseLevel((CACQualities *)v3, 0x16u, &jumpskill, 0)) )
    {
      v6 = (PackableHashTable<unsigned long,Skill> *)*((_DWORD *)v3 + 25);
      key = 22;
      if ( v6 )
      {
        v7 = PackableHashTable<unsigned long,Skill>::lookup(v6, &key);
        if ( v7 )
          jumpskill += v7->_init_level + v7->_level_from_pp;
      }
      retval = 0;
      if ( CBaseQualities::InqInt((CBaseQualities *)(v3 + 56), 0x16Du, &retval, 0, 0) && retval > 0 )
        jumpskill += retval;
      v19 = 0;
      v15 = 0;
      key = 0;
      CACQualities::EnchantSkill((CACQualities *)v3, 0x16u, &jumpskill);
      if ( CBaseQualities::InqInt((CBaseQualities *)(v3 + 56), 0x146u, &v15, 0, 0) && v15 > 0 )
        jumpskill += 5;
      CBaseQualities::InqInt((CBaseQualities *)(v3 + 56), 0x158u, (int *)&key, 0, 0);
      v8 = key;
      if ( (signed int)key > 0 )
      {
        v9 = (PackableHashTable<unsigned long,Skill> *)*((_DWORD *)v3 + 25);
        v18 = 22;
        if ( v9 )
        {
          v10 = PackableHashTable<unsigned long,Skill>::lookup(v9, &v18);
          if ( v10 )
          {
            if ( v10->_sac == 3 )
              jumpskill += 2 * v8;
          }
        }
      }
      if ( !stamina )
        jumpskill = 0;
      v11 = MovementSystem::GetJumpHeight(load, jumpskill, extent, 1.0);
      result = 1;
      *v_z = sqrt(v11 * 19.6);
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00592B20) --------------------------------------------------------  // acclient.c:443853
int __thiscall PackableHashTable<unsigned long,Skill>::UnPack(PackableHashTable<unsigned long,Skill> *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  PackableHashTable<unsigned long,Skill> *v4; // ebx@1
  void **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  int v10; // edi@3
  unsigned int v11; // ebp@3
  void *v12; // eax@11
  PackObjVtbl *v13; // edx@11
  void *start_addr; // [sp+8h] [bp-28h]@3
  unsigned int blob_size; // [sp+Ch] [bp-24h]@3
  Skill tempData; // [sp+10h] [bp-20h]@9

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,Skill>::Destroy(this);
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  Skill::Skill(&tempData);
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *v6;
      v13 = tempData.vfptr;
      addr = *(void ***)*v6;
      *v6 = (char *)v12 + 4;
      if ( !((int (__thiscall *)(Skill *, void **, int))v13->UnPack)(&tempData, v6, v10)
        || !PackableHashTable<unsigned long,Skill>::add(v4, (const unsigned int *)&addr, &tempData)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00592C30) --------------------------------------------------------  // acclient.c:443914
void __thiscall PackableHashTable<unsigned long,Skill>::Destroy(PackableHashTable<unsigned long,Skill> *this)
{
  PackableHashTable<unsigned long,Skill> *v1; // esi@1

  v1 = this;
  PackableHashTable<unsigned long,Skill>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
}

//----- (00592C60) --------------------------------------------------------  // acclient.c:443929
void __thiscall PackableHashTable<unsigned long,Skill>::EmptyContents(PackableHashTable<unsigned long,Skill> *this)
{
  PackableHashTable<unsigned long,Skill> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<unsigned long,Skill> *v3; // eax@3
  PackableHashData<unsigned long,Skill> *v4; // esi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00592CC0) --------------------------------------------------------  // acclient.c:443966
PackableHashTable<unsigned long,Skill> *__thiscall PackableHashTable<unsigned long,Skill>::vector_deleting_destructor(PackableHashTable<unsigned long,Skill> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,Skill> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Skill>::vftable;
  PackableHashTable<unsigned long,Skill>::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E44CC: using guessed type int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char);

//----- (00592CF0) --------------------------------------------------------  // acclient.c:443982
void __thiscall CACQualities::SetAttribute2nd(CACQualities *this, unsigned int stype, unsigned int val)
{
  CACQualities::SetAttribute2nd(this, stype, val, &stype, &val);
}

//----- (0070AB00) --------------------------------------------------------  // acclient.c:797906
void sub_70AB00()
{
  flt_870FD0 = 1000.0 + 1.0;
}

//----- (0070AB20) --------------------------------------------------------  // acclient.c:797912
void sub_70AB20()
{
  flt_870FD4 = 24.0 * 8.0;
}

//----- (0070AB40) --------------------------------------------------------  // acclient.c:797918
void sub_70AB40()
{
  flt_870FD8 = 24.0 * 0.5;
}

//----- (0070AB60) --------------------------------------------------------  // acclient.c:797924
int sub_70AB60()
{
  return atexit(nullsub_1419);
}

