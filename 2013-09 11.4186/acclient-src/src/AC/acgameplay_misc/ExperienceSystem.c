/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ExperienceSystem
   Object     : AC\acgameplay_misc\ExperienceSystem.obj
   Functions  : 24
   Addresses  : 005C8100 - 0070F700 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C8100) --------------------------------------------------------  // acclient.c:499190
int __cdecl ExperienceSystem::ItemLevelToTotalXP(int _item_level, unsigned __int64 _base_xp, int _max_level, int _xp_scheme)
{
  int v4; // ebp@1
  int v5; // esi@1
  unsigned __int64 v7; // rax@8
  int v8; // ebx@9
  int v9; // eax@13
  int v10; // ebp@14

  v4 = _item_level;
  v5 = 0;
  if ( _item_level < 1 )
    return 0;
  if ( _item_level > _max_level )
    v4 = _max_level;
  if ( _xp_scheme == 1 )
    return v4 * _base_xp;
  if ( _xp_scheme != 2 )
  {
    if ( _xp_scheme == 3 )
    {
      v5 = _base_xp;
      v9 = _base_xp;
      if ( v4 > 1 )
      {
        v10 = v4 - 1;
        do
        {
          v9 += _base_xp;
          v5 += v9;
          --v10;
        }
        while ( v10 );
      }
    }
    return v5;
  }
  v7 = _base_xp;
  v5 = _base_xp;
  if ( v4 <= 1 )
    return v5;
  v8 = v4 - 1;
  do
  {
    v7 *= 2i64;
    v5 += v7;
    --v8;
  }
  while ( v8 );
  return v5;
}

//----- (005C81B0) --------------------------------------------------------  // acclient.c:499243
int __cdecl ExperienceSystem::ItemTotalXPToLevel(unsigned __int64 _gained_xp, unsigned __int64 _base_xp, int _max_level, int _xp_scheme)
{
  int v4; // esi@1
  unsigned int v5; // edi@4
  unsigned __int64 v6; // rax@4
  unsigned int v7; // ebx@4
  unsigned int v8; // kr00_4@5
  unsigned int v9; // edx@10
  unsigned int v10; // ebx@10
  unsigned int v11; // eax@10
  unsigned int v12; // ecx@10
  int result; // eax@12

  v4 = 0;
  switch ( _xp_scheme )
  {
    case 1:
      v4 = (unsigned __int64)_floor((double)_gained_xp / (double)_base_xp);
      break;
    case 2:
      v5 = HIDWORD(_gained_xp);
      v6 = _base_xp;
      v7 = _gained_xp;
      if ( _gained_xp >= _base_xp )
      {
        do
        {
          do
          {
            ++v4;
            v8 = v7 - v6;
            v5 = (__PAIR__(v5, v7) - v6) >> 32;
            v7 -= v6;
            v6 *= 2i64;
          }
          while ( v5 > HIDWORD(v6) );
        }
        while ( v5 >= HIDWORD(v6) && v8 >= (unsigned int)v6 );
      }
      break;
    case 3:
      v9 = HIDWORD(_gained_xp);
      v10 = _gained_xp;
      v11 = HIDWORD(_base_xp);
      v12 = _base_xp;
      if ( _gained_xp >= _base_xp )
      {
        do
        {
          ++v4;
          v9 = (__PAIR__(v9, v10) - __PAIR__(v11, v12)) >> 32;
          v10 -= v12;
          v11 = (_base_xp + __PAIR__(v11, v12)) >> 32;
          v12 += _base_xp;
        }
        while ( __PAIR__(v9, v10) >= __PAIR__(v11, v12) );
      }
      break;
  }
  result = _max_level;
  if ( v4 <= _max_level )
    result = v4;
  return result;
}
// 5C81B0: could not find valid save-restore pair for ebx
// 5C81B0: could not find valid save-restore pair for ebp

//----- (005C82D0) --------------------------------------------------------  // acclient.c:499311
void __cdecl ExperienceSystem::XPToString(unsigned __int64 _xp, char *_output_str)
{
  _numberfmtA display_format; // [sp+0h] [bp-38h]@1
  char number_str[32]; // [sp+18h] [bp-20h]@1

  display_format.NumDigits = 0;
  display_format.LeadingZero = 0;
  display_format.Grouping = 3;
  display_format.lpDecimalSep = ".";
  display_format.lpThousandSep = ",";
  display_format.NegativeOrder = 1;
  _sprintf(number_str, "%I64d", _xp);
  GetNumberFormatA(0x400u, 0, number_str, &display_format, _output_str, 32);
}

//----- (005C8350) --------------------------------------------------------  // acclient.c:499327
int __cdecl ExperienceSystem::ExperienceToAttributeLevel(unsigned int level)
{
  int result; // eax@1
  int v2; // esi@1
  signed int v3; // edi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v2 = result;
  if ( result )
  {
    v3 = ExperienceTable::GetExperienceForAttributeLevel((ExperienceTable *)result, level);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    result = v3;
  }
  return result;
}

//----- (005C8390) --------------------------------------------------------  // acclient.c:499345
int __cdecl ExperienceSystem::ExperienceToAttribute2ndLevel(unsigned int level)
{
  int result; // eax@1
  int v2; // esi@1
  signed int v3; // edi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v2 = result;
  if ( result )
  {
    v3 = ExperienceTable::GetExperienceForAttribute2ndLevel((ExperienceTable *)result, level);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    result = v3;
  }
  return result;
}

//----- (005C83D0) --------------------------------------------------------  // acclient.c:499363
int __cdecl ExperienceSystem::ExperienceToSkillLevel(SKILL_ADVANCEMENT_CLASS sac, unsigned int level)
{
  int result; // eax@1
  int v3; // esi@1
  signed int v4; // edi@5
  signed int v5; // edi@6

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v3 = result;
  if ( result )
  {
    if ( sac == 2 )
    {
      v5 = ExperienceTable::GetExperienceForTrainedSkillLevel((ExperienceTable *)result, level);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
      result = v5;
    }
    else if ( sac == 3 )
    {
      v4 = ExperienceTable::GetExperienceForSpecializedSkillLevel((ExperienceTable *)result, level);
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3 + 20))(v3);
      result = v4;
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
      result = -1;
    }
  }
  return result;
}

//----- (005C8440) --------------------------------------------------------  // acclient.c:499396
int __cdecl ExperienceSystem::SkillLevelFromExperience(SKILL_ADVANCEMENT_CLASS sac, unsigned int pp)
{
  int result; // eax@1
  int v3; // esi@1
  unsigned int v4; // edi@5
  unsigned int v5; // edi@6

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v3 = result;
  if ( result )
  {
    if ( sac == 2 )
    {
      v5 = ExperienceTable::GetTrainedSkillLevelForExperience((ExperienceTable *)result, pp);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
      result = v5;
    }
    else if ( sac == 3 )
    {
      v4 = ExperienceTable::GetSpecializedSkillLevelForExperience((ExperienceTable *)result, pp);
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3 + 20))(v3);
      result = v4;
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
      result = 0;
    }
  }
  return result;
}

//----- (005C84B0) --------------------------------------------------------  // acclient.c:499429
int __cdecl ExperienceSystem::AttributeLevelFromExperience(unsigned int total_xp)
{
  int result; // eax@1
  int v2; // esi@1
  unsigned int v3; // edi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v2 = result;
  if ( result )
  {
    v3 = ExperienceTable::GetAttributeLevelForExperience((ExperienceTable *)result, total_xp);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    result = v3;
  }
  return result;
}

//----- (005C84F0) --------------------------------------------------------  // acclient.c:499447
int __cdecl ExperienceSystem::Attribute2ndLevelFromExperience(unsigned int total_xp)
{
  int result; // eax@1
  int v2; // esi@1
  unsigned int v3; // edi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v2 = result;
  if ( result )
  {
    v3 = ExperienceTable::GetAttribute2ndLevelForExperience((ExperienceTable *)result, total_xp);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    result = v3;
  }
  return result;
}

//----- (005C8530) --------------------------------------------------------  // acclient.c:499465
int __cdecl ExperienceSystem::ExperienceToLevel(unsigned int level)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // edi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  v2 = result;
  if ( result )
  {
    v3 = ExperienceTable::GetExperienceForLevel((ExperienceTable *)result, level);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    result = v3;
  }
  return result;
}

//----- (005C8570) --------------------------------------------------------  // acclient.c:499483
int __cdecl ExperienceSystem::GetMaxSpecializedSkillLevel()
{
  int result; // eax@1
  int v1; // esi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  if ( result )
  {
    v1 = *(_DWORD *)(result + 80);
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
    result = v1;
  }
  return result;
}

//----- (005C85A0) --------------------------------------------------------  // acclient.c:499499
int __cdecl ExperienceSystem::GetMaxTrainedSkillLevel()
{
  int result; // eax@1
  int v1; // esi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  if ( result )
  {
    v1 = *(_DWORD *)(result + 72);
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
    result = v1;
  }
  return result;
}

//----- (005C85D0) --------------------------------------------------------  // acclient.c:499515
int __cdecl ExperienceSystem::GetMaxAttributeLevel()
{
  int result; // eax@1
  int v1; // esi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  if ( result )
  {
    v1 = *(_DWORD *)(result + 56);
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
    result = v1;
  }
  return result;
}

//----- (005C8600) --------------------------------------------------------  // acclient.c:499531
int __cdecl ExperienceSystem::GetMaxAttribute2ndLevel()
{
  int result; // eax@1
  int v1; // esi@2

  result = DBObj::GetByEnum(3, 2, 0x10000009u);
  if ( result )
  {
    v1 = *(_DWORD *)(result + 64);
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 20))(result);
    result = v1;
  }
  return result;
}

//----- (005C8630) --------------------------------------------------------  // acclient.c:499547
signed __int64 __cdecl ExperienceSystem::ExperienceToRaiseLevel(unsigned int current_level, unsigned int new_level)
{
  signed __int64 result; // rax@2
  int v3; // eax@3
  int v4; // esi@3
  unsigned int v5; // ebp@3
  unsigned __int64 v6; // kr00_8@5
  unsigned __int64 v7; // kr08_8@5
  int v8; // eax@6
  int v9; // esi@6
  unsigned __int64 v10; // rax@8
  __int64 v11; // rcx@8
  int v12; // edi@8
  unsigned int new_xp_cost_4; // [sp+8h] [bp-4h]@4

  if ( new_level > current_level )
  {
    v3 = DBObj::GetByEnum(3, 2, 0x10000009u);
    v4 = v3;
    v5 = 0;
    if ( v3 )
    {
      v6 = ExperienceTable::GetExperienceForLevel((ExperienceTable *)v3, new_level);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      v7 = v6;
      new_xp_cost_4 = v7 >> 32;
      v5 = v7;
    }
    else
    {
      new_xp_cost_4 = 0;
    }
    v8 = DBObj::GetByEnum(3, 2, 0x10000009u);
    v9 = v8;
    if ( v8 )
    {
      v10 = ExperienceTable::GetExperienceForLevel((ExperienceTable *)v8, current_level);
      HIDWORD(v11) = HIDWORD(v10);
      v12 = v10;
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
      LODWORD(v11) = v12;
      result = __PAIR__(new_xp_cost_4, v5) - v11;
    }
    else
    {
      result = __PAIR__(new_xp_cost_4, v5);
    }
  }
  else
  {
    result = 0i64;
  }
  return result;
}

//----- (0070F640) --------------------------------------------------------  // acclient.c:802579
int sub_70F640()
{
  return atexit(nullsub_1748);
}

//----- (0070F650) --------------------------------------------------------  // acclient.c:802585
int _E4_13()
{
  return atexit(_E5_13);
}

//----- (0070F660) --------------------------------------------------------  // acclient.c:802591
int _E7_13()
{
  Outside_CellID_13.id = Invalid_CellID_13.id + 1;
  return atexit(_E8_13);
}

//----- (0070F680) --------------------------------------------------------  // acclient.c:802598
int _E10_12()
{
  In_Limbo_CellID_12.id = Outside_CellID_13.id + 1;
  return atexit(_E11_12);
}

//----- (0070F6A0) --------------------------------------------------------  // acclient.c:802605
int _E13_12()
{
  First_Interior_CellID_12.id = In_Limbo_CellID_12.id + 1;
  return atexit(_E14_12);
}

//----- (0070F6C0) --------------------------------------------------------  // acclient.c:802612
int _E16_12()
{
  Last_Interior_CellID_12.id = Invalid_CellID_13.id - 1;
  return atexit(_E17_12);
}

//----- (0070F6E0) --------------------------------------------------------  // acclient.c:802619
int _E21_14()
{
  return atexit(_E22_14);
}

//----- (0070F6F0) --------------------------------------------------------  // acclient.c:802625
int _E40_14()
{
  return atexit(_E41_14);
}

//----- (0070F700) --------------------------------------------------------  // acclient.c:802631
int _E43_17()
{
  return atexit(_E44_17);
}

