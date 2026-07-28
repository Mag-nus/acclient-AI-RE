/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Skill
   Object     : AC\acqualities\Skill.obj
   Functions  : 12
   Addresses  : 005CA940 - 0070FFC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CA940) --------------------------------------------------------  // acclient.c:502095
void __thiscall Skill::SetSkillAdvancementClass(Skill *this, SKILL_ADVANCEMENT_CLASS sac)
{
  unsigned int v2; // ST04_4@1

  v2 = this->_pp;
  this->_sac = sac;
  this->_level_from_pp = ExperienceSystem::SkillLevelFromExperience(sac, v2);
}

//----- (005CA960) --------------------------------------------------------  // acclient.c:502105
BOOL __thiscall Skill::AdjPP(Skill *this, unsigned int *amount)
{
  Skill *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // edi@1
  SKILL_ADVANCEMENT_CLASS v6; // ecx@2
  SKILL_ADVANCEMENT_CLASS v7; // edx@3
  int v8; // eax@2

  v2 = this;
  v3 = *amount + this->_pp;
  v4 = this->_pp;
  v5 = v2->_level_from_pp;
  if ( v3 >= v4 )
  {
    v7 = v2->_sac;
    v2->_pp = v3;
    v8 = ExperienceSystem::SkillLevelFromExperience(v7, v3);
  }
  else
  {
    *amount = -1 - v4;
    v6 = v2->_sac;
    v2->_pp = -1;
    v8 = ExperienceSystem::SkillLevelFromExperience(v6, 0xFFFFFFFF);
  }
  v2->_level_from_pp = v8;
  return v5 != v2->_level_from_pp;
}

//----- (005CA9C0) --------------------------------------------------------  // acclient.c:502137
int __thiscall Skill::SanityCheck(Skill *this)
{
  Skill *v1; // esi@1
  SKILL_ADVANCEMENT_CLASS v2; // eax@1
  signed int v3; // edi@1
  unsigned int v4; // ST04_4@4
  int v5; // eax@5
  int result; // eax@6

  v1 = this;
  v2 = this->_sac;
  v3 = 1;
  if ( v2 != 1 && v2 != 2 && v2 != 3 )
  {
    v4 = this->_pp;
    this->_sac = 1;
    this->_level_from_pp = ExperienceSystem::SkillLevelFromExperience(UNTRAINED_SKILL_ADVANCEMENT_CLASS, v4);
    v3 = 0;
  }
  v5 = ExperienceSystem::SkillLevelFromExperience(v1->_sac, v1->_pp);
  if ( v5 == v1->_level_from_pp )
  {
    result = v3;
  }
  else
  {
    v1->_level_from_pp = v5;
    result = 0;
  }
  return result;
}

//----- (005CAA20) --------------------------------------------------------  // acclient.c:502170
signed int __thiscall Skill::Pack(Skill *this, void **addr, unsigned int size)
{
  Skill *v3; // edi@1
  char *v4; // eax@2
  char *v5; // edx@2
  char *v6; // ecx@2
  char *v7; // eax@2
  long double v8; // st7@3

  v3 = this;
  if ( size >= 0x1C )
  {
    *(_DWORD *)*addr = this->_level_from_pp & 0xFFFF | 0x10000;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->_sac;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->_pp;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_init_level;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_resistance_of_last_check;
    *addr = (char *)*addr + 4;
    if ( DBCache::IsRunTime() )
      v8 = COERCE_DOUBLE(Timer::cur_time.Cmd) - v3->_last_used_time;
    else
      v8 = 0.0;
    *(long double *)*addr = v8;
    *addr = (char *)*addr + 8;
  }
  return 28;
}

//----- (005CAAC0) --------------------------------------------------------  // acclient.c:502207
int __thiscall Skill::UnPack(Skill *this, void **addr, unsigned int size)
{
  SKILL_ADVANCEMENT_CLASS **v3; // esi@1
  void *v4; // eax@1
  Skill *v5; // edi@1
  int v6; // eax@2
  int v7; // ebx@2
  unsigned int *v8; // edx@2
  int v9; // ecx@2
  int v10; // ebp@2
  int v11; // eax@2
  int v12; // edx@2
  double v13; // st7@2
  void **addra; // [sp+Ch] [bp+4h]@1

  v3 = (SKILL_ADVANCEMENT_CLASS **)addr;
  v4 = *addr;
  v5 = this;
  addra = (void **)*addr;
  if ( size < 0x1C )
    return 0;
  v6 = (int)((char *)v4 + 4);
  v7 = *(_DWORD *)(v6 - 4);
  *v3 = (SKILL_ADVANCEMENT_CLASS *)v6;
  this->_level_from_pp = (unsigned __int16)v7;
  this->_sac = **v3;
  v8 = (unsigned int *)(*v3 + 1);
  *v3 = (SKILL_ADVANCEMENT_CLASS *)v8;
  this->_pp = *v8;
  v9 = (int)(*v3 + 1);
  *v3 = (SKILL_ADVANCEMENT_CLASS *)v9;
  v5->_init_level = *(_DWORD *)v9;
  v10 = (int)&v5->_init_level;
  v11 = (int)(*v3 + 1);
  *v3 = (SKILL_ADVANCEMENT_CLASS *)v11;
  v5->_resistance_of_last_check = *(_DWORD *)v11;
  v12 = (int)(*v3 + 1);
  *v3 = (SKILL_ADVANCEMENT_CLASS *)v12;
  v13 = *(double *)v12;
  *v3 = (SKILL_ADVANCEMENT_CLASS *)(v12 + 8);
  v5->_last_used_time = COERCE_DOUBLE(Timer::cur_time.Cmd) - v13;
  Skill::SanityCheck(v5);
  if ( (v7 & 0xFFFF0000) < 0x10000 )
  {
    if ( *(_DWORD *)v10 )
      Skill::AdjPP(v5, &v5->_init_level);
    *(_DWORD *)v10 = 0;
  }
  if ( size < (char *)*v3 - (char *)addra )
  {
    *v3 = (SKILL_ADVANCEMENT_CLASS *)addra;
    return 0;
  }
  return 1;
}

//----- (0070FF30) --------------------------------------------------------  // acclient.c:803217
void sub_70FF30()
{
  flt_8EFE7C = 1000.0 + 1.0;
}

//----- (0070FF50) --------------------------------------------------------  // acclient.c:803223
void sub_70FF50()
{
  flt_8EFE80 = 24.0 * 8.0;
}

//----- (0070FF70) --------------------------------------------------------  // acclient.c:803229
void sub_70FF70()
{
  flt_8EFE84 = 24.0 * 0.5;
}

//----- (0070FF90) --------------------------------------------------------  // acclient.c:803235
int sub_70FF90()
{
  return atexit(nullsub_1828);
}

//----- (0070FFA0) --------------------------------------------------------  // acclient.c:803241
int sub_70FFA0()
{
  return atexit(nullsub_1829);
}

//----- (0070FFB0) --------------------------------------------------------  // acclient.c:803247
int sub_70FFB0()
{
  return atexit(nullsub_1830);
}

//----- (0070FFC0) --------------------------------------------------------  // acclient.c:803253
int sub_70FFC0()
{
  return atexit(nullsub_1827);
}

