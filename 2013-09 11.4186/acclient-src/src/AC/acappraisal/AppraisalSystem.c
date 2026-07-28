/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AppraisalSystem
   Object     : AC\acappraisal\AppraisalSystem.obj
   Functions  : 15
   Addresses  : 005B4200 - 005B5AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B4200) --------------------------------------------------------  // acclient.c:479073
unsigned int __cdecl AppraisalSystem::DamageTypeToString(DAMAGE_TYPE dtype, char *buf, const unsigned int size)
{
  DAMAGE_TYPE v3; // edx@1
  const unsigned int result; // eax@1
  signed int v5; // ecx@1
  __int32 v6; // esi@1
  int v7; // ebx@7
  signed int v8; // edx@36
  char *v9; // edi@41
  char v10; // cl@42
  char *v11; // edi@47
  char v12; // cl@48
  char *v13; // edi@53
  char v14; // cl@54
  char *v15; // edi@59
  char v16; // cl@60
  char *v17; // edi@65
  char v18; // cl@66
  char *v19; // edi@71
  char v20; // cl@72
  char *v21; // edi@77
  char v22; // cl@78
  char *v23; // edi@83
  char v24; // cl@84
  int v25; // [sp+10h] [bp-18h]@11
  int v26; // [sp+14h] [bp-14h]@15
  int v27; // [sp+18h] [bp-10h]@19
  int v28; // [sp+1Ch] [bp-Ch]@23
  int v29; // [sp+20h] [bp-8h]@27
  int v30; // [sp+24h] [bp-4h]@31
  __int32 dtypea; // [sp+2Ch] [bp+4h]@3

  v3 = dtype;
  result = 1;
  v5 = 0;
  v6 = dtype & 1;
  *buf = 0;
  if ( dtype & 1 )
  {
    v5 = 1;
    result = 9;
  }
  dtypea = dtype & 2;
  if ( v3 & 2 )
  {
    if ( v5 )
    {
      result += 9;
    }
    else
    {
      v5 = 1;
      result += 8;
    }
  }
  v7 = v3 & 4;
  if ( v3 & 4 )
  {
    if ( v5 )
    {
      result += 12;
    }
    else
    {
      v5 = 1;
      result += 11;
    }
  }
  v25 = v3 & 8;
  if ( v3 & 8 )
  {
    if ( v5 )
    {
      result += 5;
    }
    else
    {
      v5 = 1;
      result += 4;
    }
  }
  v26 = v3 & 0x10;
  if ( v3 & 0x10 )
  {
    if ( v5 )
    {
      result += 5;
    }
    else
    {
      v5 = 1;
      result += 4;
    }
  }
  v27 = v3 & 0x20;
  if ( v3 & 0x20 )
  {
    if ( v5 )
    {
      result += 5;
    }
    else
    {
      v5 = 1;
      result += 4;
    }
  }
  v28 = v3 & 0x40;
  if ( v3 & 0x40 )
  {
    if ( v5 )
    {
      result += 11;
    }
    else
    {
      v5 = 1;
      result += 10;
    }
  }
  v29 = v3 & 0x400;
  if ( v3 & 0x400 )
  {
    if ( v5 )
    {
      result += 7;
    }
    else
    {
      v5 = 1;
      result += 6;
    }
  }
  v30 = v3 & 0x10000000;
  if ( v3 & 0x10000000 )
  {
    if ( v5 )
      result += 10;
    else
      result += 9;
  }
  if ( size >= result )
  {
    v8 = 0;
    if ( v6 )
    {
      *(_DWORD *)buf = *(_DWORD *)"Slashing";
      *((_DWORD *)buf + 1) = 1735289192;
      buf[8] = 0;
      v8 = 1;
    }
    if ( dtypea )
    {
      if ( v8 )
      {
        v9 = buf - 1;
        do
          v10 = (v9++)[1];
        while ( v10 );
        *(_DWORD *)v9 = *(_DWORD *)"/Piercing";
        *((_DWORD *)v9 + 1) = 1852400498;
        *((_WORD *)v9 + 4) = 103;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Piercing";
        *((_DWORD *)buf + 1) = 1735289187;
        buf[8] = 0;
        v8 = 1;
      }
    }
    if ( v7 )
    {
      if ( v8 )
      {
        v11 = buf - 1;
        do
          v12 = (v11++)[1];
        while ( v12 );
        *(_DWORD *)v11 = *(_DWORD *)"/Bludgeoning";
        *((_DWORD *)v11 + 1) = 1868916580;
        *((_DWORD *)v11 + 2) = 1735289198;
        v11[12] = 0;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Bludgeoning";
        *((_DWORD *)buf + 1) = 1852794215;
        v8 = 1;
        *((_DWORD *)buf + 2) = 6778473;
      }
    }
    if ( v25 )
    {
      if ( v8 )
      {
        v13 = buf - 1;
        do
          v14 = (v13++)[1];
        while ( v14 );
        *(_DWORD *)v13 = *(_DWORD *)"/Cold";
        *((_WORD *)v13 + 2) = 100;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Cold";
        v8 = 1;
        buf[4] = 0;
      }
    }
    if ( v26 )
    {
      if ( v8 )
      {
        v15 = buf - 1;
        do
          v16 = (v15++)[1];
        while ( v16 );
        *(_DWORD *)v15 = *(_DWORD *)"/Fire";
        *((_WORD *)v15 + 2) = 101;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Fire";
        v8 = 1;
        buf[4] = 0;
      }
    }
    if ( v27 )
    {
      if ( v8 )
      {
        v17 = buf - 1;
        do
          v18 = (v17++)[1];
        while ( v18 );
        *(_DWORD *)v17 = *(_DWORD *)"/Acid";
        *((_WORD *)v17 + 2) = 100;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Acid";
        v8 = 1;
        buf[4] = 0;
      }
    }
    if ( v28 )
    {
      if ( v8 )
      {
        v19 = buf - 1;
        do
          v20 = (v19++)[1];
        while ( v20 );
        *(_DWORD *)v19 = *(_DWORD *)"/Electrical";
        *((_DWORD *)v19 + 1) = 1769108579;
        *((_DWORD *)v19 + 2) = 7102819;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Electrical";
        *((_DWORD *)buf + 1) = 1667854964;
        *((_WORD *)buf + 4) = 27745;
        v8 = 1;
        buf[10] = 0;
      }
    }
    if ( v29 )
    {
      if ( v8 )
      {
        v21 = buf - 1;
        do
          v22 = (v21++)[1];
        while ( v22 );
        *(_DWORD *)v21 = *(_DWORD *)"/Nether";
        *((_DWORD *)v21 + 1) = 7497064;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Nether";
        *((_WORD *)buf + 2) = 29285;
        v8 = 1;
        buf[6] = 0;
      }
    }
    if ( v30 )
    {
      if ( v8 )
      {
        v23 = buf - 1;
        do
          v24 = (v23++)[1];
        while ( v24 );
        *(_DWORD *)v23 = *(_DWORD *)"/Prismatic";
        *((_DWORD *)v23 + 1) = 1952542067;
        *((_WORD *)v23 + 4) = 25449;
        v23[10] = 0;
      }
      else
      {
        *(_DWORD *)buf = *(_DWORD *)"Prismatic";
        *((_DWORD *)buf + 1) = 1769234797;
        *((_WORD *)buf + 4) = 99;
      }
    }
  }
  return result;
}

//----- (005B45E0) --------------------------------------------------------  // acclient.c:479384
int __cdecl AppraisalSystem::InqMaterialName(unsigned int mat_type, PStringBase<char> *material)
{
  return (unsigned __int8)MaterialTypeEnumMapper::MaterialTypeToString(mat_type, material);
}

//----- (005B4600) --------------------------------------------------------  // acclient.c:479390
int __cdecl AppraisalSystem::LockpickSuccessPercentToString(const int lr, AC1Legacy::PStringBase<char> *ps)
{
  if ( lr < 0 )
    return 0;
  if ( !lr )
  {
    AC1Legacy::PStringBase<char>::set(ps, "impossible");
    return 1;
  }
  if ( lr > 0 )
  {
    if ( lr < 5 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "ridiculously difficult");
      return 1;
    }
LABEL_9:
    if ( lr < 15 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "extremely difficult");
      return 1;
    }
LABEL_12:
    if ( lr < 35 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "quite difficult");
      return 1;
    }
LABEL_15:
    if ( lr < 50 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "difficult");
      return 1;
    }
LABEL_18:
    if ( lr < 70 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "challenging");
      return 1;
    }
LABEL_21:
    if ( lr < 85 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "mildly challenging");
      return 1;
    }
LABEL_24:
    if ( lr < 95 )
    {
      AC1Legacy::PStringBase<char>::set(ps, "easy");
      return 1;
    }
    goto LABEL_27;
  }
  if ( lr >= 5 )
    goto LABEL_9;
  if ( lr >= 15 )
    goto LABEL_12;
  if ( lr >= 35 )
    goto LABEL_15;
  if ( lr >= 50 )
    goto LABEL_18;
  if ( lr >= 70 )
    goto LABEL_21;
  if ( lr >= 85 )
    goto LABEL_24;
  if ( lr >= 95 )
LABEL_27:
    AC1Legacy::PStringBase<char>::set(ps, "trivial");
  return 1;
}

//----- (005B4710) --------------------------------------------------------  // acclient.c:479463
int __cdecl AppraisalSystem::InqHeritageGroupDisplayName(unsigned int type, AC1Legacy::PStringBase<char> *strName)
{
  unsigned int v2; // esi@1
  int result; // eax@2

  v2 = type;
  switch ( type )
  {
    case 2u:
      AC1Legacy::PStringBase<char>::set(strName, "Gharu'ndim");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(strName, "Umbraen");
      result = 1;
      break;
    case 0xDu:
      AC1Legacy::PStringBase<char>::set(strName, "Olthoi");
      result = 1;
      break;
    default:
      type = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      if ( EnumMapper::GetString(0x10000002u, v2, (PStringBase<char> *)&type) )
      {
        AC1Legacy::PStringBase<char>::set(strName, (const char *)type);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&type);
        result = 1;
      }
      else
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&type);
        result = 0;
      }
      break;
  }
  return result;
}

//----- (005B47C0) --------------------------------------------------------  // acclient.c:479503
int __cdecl AppraisalSystem::InqGenderDisplayName(unsigned int type, AC1Legacy::PStringBase<char> *strName)
{
  char *v2; // esi@2
  int result; // eax@5
  char *v4; // esi@6
  PStringBase<char> typeStr; // [sp+0h] [bp-4h]@1

  typeStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( EnumMapper::GetString(0x10000001u, type, &typeStr) )
  {
    AC1Legacy::PStringBase<char>::set(strName, typeStr.m_charbuffer->m_data);
    v4 = &typeStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    result = 1;
  }
  else
  {
    v2 = &typeStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
    }
    result = 0;
  }
  return result;
}

//----- (005B4850) --------------------------------------------------------  // acclient.c:479534
int __cdecl AppraisalSystem::AttunedStatusToString(AttunedStatusEnum attuned, AC1Legacy::PStringBase<char> *label)
{
  int result; // eax@3

  if ( (signed int)attuned <= 0 || (signed int)attuned > 2 )
  {
    result = 0;
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(label, "Attuned");
    result = 1;
  }
  return result;
}

//----- (005B4880) --------------------------------------------------------  // acclient.c:479551
int __cdecl AppraisalSystem::BondedStatusToString(BondedStatusEnum bonded, AC1Legacy::PStringBase<char> *label)
{
  int result; // eax@4

  switch ( bonded )
  {
    case 0xFFFFFFFE:
      AC1Legacy::PStringBase<char>::set(label, "Destroyed on Death");
      result = 1;
      break;
    case 0xFFFFFFFF:
      AC1Legacy::PStringBase<char>::set(label, "Dropped on Death");
      result = 1;
      break;
    case 1u:
      AC1Legacy::PStringBase<char>::set(label, "Bonded");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B48E0) --------------------------------------------------------  // acclient.c:479577
int __cdecl AppraisalSystem::InqWorkmanshipAdjective(unsigned int wlevel, AC1Legacy::PStringBase<char> *workmanship, int gem)
{
  unsigned int v3; // esi@1
  AC1Legacy::PStringBase<char> *v4; // edi@3
  const char *v5; // eax@4
  unsigned int v6; // esi@6
  int v7; // eax@6

  v3 = wlevel;
  if ( wlevel >= 0xB )
    v3 = 10;
  v4 = workmanship;
  AC1Legacy::PStringBase<char>::set(workmanship, (&rgWorkmanshipStrings)[4 * v3]);
  if ( v3 <= 4 )
  {
    v5 = "cut";
    if ( !gem )
      v5 = "crafted";
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wlevel, v5);
    v6 = wlevel;
    v7 = *(_DWORD *)(wlevel + 8);
    if ( v7 != 1 && wlevel != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v4, (const char *)(wlevel + 20), v7 - 1);
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B4970) --------------------------------------------------------  // acclient.c:479608
void __cdecl AppraisalSystem::WeaponTimeToString(const int wtime, AC1Legacy::PStringBase<char> *ps)
{
  const int v2; // esi@3
  int v3; // eax@3

  if ( wtime >= 11 )
  {
    if ( wtime >= 31 )
    {
      if ( wtime >= 50 )
      {
        if ( wtime >= 80 )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wtime, "Very Slow");
          AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&wtime);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&wtime);
        }
        else
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wtime, "Slow");
          AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&wtime);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&wtime);
        }
        return;
      }
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wtime, "Average");
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wtime, "Fast");
    }
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&wtime, "Very Fast");
  }
  v2 = wtime;
  v3 = *(_DWORD *)(wtime + 8);
  if ( v3 != 1 && wtime != AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(ps, (const char *)(wtime + 20), v3 - 1);
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) )
    (**(void (__thiscall ***)(const int, signed int))v2)(v2, 1);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B4A30) --------------------------------------------------------  // acclient.c:479654
int __cdecl AppraisalSystem::SkillToString(unsigned int stype, AC1Legacy::PStringBase<char> *ps)
{
  int result; // eax@56

  switch ( stype )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Axe");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 2u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Bow");
      goto LABEL_55;
    case 3u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Crossbow");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 4u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Dagger");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 5u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Mace");
      goto LABEL_55;
    case 8u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Sling");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 9u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Spear");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0xAu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Staff");
      goto LABEL_55;
    case 0xBu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Sword");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0xCu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Thrown Weapon");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0xDu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Unarmed Combat");
      goto LABEL_55;
    case 0x29u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Two Handed Combat");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 6u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Melee Defense");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 7u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Missile Defense");
      goto LABEL_55;
    case 0xEu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Arcane Lore");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0xFu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Magic Defense");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x10u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Mana Conversion");
      goto LABEL_55;
    case 0x11u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Spellcraft");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x12u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Item Tinkering");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x13u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Person Appraisal");
      goto LABEL_55;
    case 0x14u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Deception");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x15u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Healing");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x16u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Jump");
      goto LABEL_55;
    case 0x17u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Lockpick");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x18u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Run");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x19u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Awareness");
      goto LABEL_55;
    case 0x1Au:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Armor Repair");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x1Bu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Creature Appraisal");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x1Cu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Weapon Tinkering");
      goto LABEL_55;
    case 0x1Du:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Armor Tinkering");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x1Eu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Magic Item Tinkering");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x1Fu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Creature Enchantment");
      goto LABEL_55;
    case 0x20u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Item Enchantment");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x21u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Life Magic");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x22u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "War Magic");
      goto LABEL_55;
    case 0x2Bu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Void Magic");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x23u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Leadership");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x24u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Loyalty");
      goto LABEL_55;
    case 0x25u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Fletching");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x26u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Alchemy");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x27u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Cooking");
      goto LABEL_55;
    case 0x28u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Salvaging");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x2Au:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Gearcraft");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x2Cu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Heavy Weapons");
      goto LABEL_55;
    case 0x2Du:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Light Weapons");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x2Eu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Finesse Weapons");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x2Fu:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Missile Weapons");
      goto LABEL_55;
    case 0x31u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Dual Wield");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x32u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Recklessness");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x33u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Sneak Attack");
      goto LABEL_55;
    case 0x34u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Dirty Fighting");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x35u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Challenge");
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
      goto LABEL_56;
    case 0x36u:
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&stype, "Summoning");
LABEL_55:
      AC1Legacy::PStringBase<char>::operator+=(ps, (AC1Legacy::PStringBase<char> *)&stype);
LABEL_56:
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&stype);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B4F30) --------------------------------------------------------  // acclient.c:479867
int __cdecl AppraisalSystem::ClothingPriorityToString(unsigned int priority, AC1Legacy::PStringBase<char> *ps)
{
  AC1Legacy::PStringBase<char> *v2; // edi@1
  signed int v3; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@2
  unsigned int v5; // eax@2
  AC1Legacy::PSRefBuffer<char> *v6; // esi@11
  unsigned int v7; // eax@11
  AC1Legacy::PSRefBuffer<char> *v8; // esi@17
  unsigned int v9; // eax@17
  AC1Legacy::PSRefBuffer<char> *v10; // esi@25
  unsigned int v11; // eax@25
  AC1Legacy::PSRefBuffer<char> *v12; // esi@31
  unsigned int v13; // eax@31
  AC1Legacy::PSRefBuffer<char> *v14; // esi@39
  unsigned int v15; // eax@39
  AC1Legacy::PSRefBuffer<char> *v16; // esi@45
  unsigned int v17; // eax@45
  AC1Legacy::PSRefBuffer<char> *v18; // esi@53
  unsigned int v19; // eax@53
  AC1Legacy::PSRefBuffer<char> *v20; // esi@59
  unsigned int v21; // eax@59
  AC1Legacy::PSRefBuffer<char> *v22; // esi@66
  unsigned int v23; // eax@66
  AC1Legacy::PSRefBuffer<char> *v24; // esi@72
  unsigned int v25; // eax@72
  AC1Legacy::PSRefBuffer<char> *v26; // esi@80
  unsigned int v27; // eax@80
  AC1Legacy::PSRefBuffer<char> *v28; // esi@86
  unsigned int v29; // eax@86
  AC1Legacy::PSRefBuffer<char> *v30; // esi@94
  unsigned int v31; // eax@94
  AC1Legacy::PSRefBuffer<char> *v32; // esi@100
  unsigned int v33; // eax@100
  unsigned int v34; // esi@107
  int v35; // eax@107
  unsigned int v36; // esi@113
  int v37; // eax@113
  AC1Legacy::PStringBase<char> v39; // [sp+1Ch] [bp-4h]@2

  v2 = ps;
  AC1Legacy::PStringBase<char>::set(ps, "Covers ");
  v3 = 0;
  if ( BYTE1(priority) & 0x40 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Head");
    v4 = v39.m_buffer;
    v5 = v39.m_buffer->m_len;
    if ( v5 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v5 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    v3 = 1;
  }
  if ( priority & 8 || BYTE1(priority) & 4 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v6 = v39.m_buffer;
      v7 = v39.m_buffer->m_len;
      if ( v7 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v7 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Chest");
    v8 = v39.m_buffer;
    v9 = v39.m_buffer->m_len;
    if ( v9 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v9 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  }
  if ( priority & 0x10 || BYTE1(priority) & 8 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v10 = v39.m_buffer;
      v11 = v39.m_buffer->m_len;
      if ( v11 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v11 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Abdomen");
    v12 = v39.m_buffer;
    v13 = v39.m_buffer->m_len;
    if ( v13 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v13 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v12->m_cRef) )
      v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  }
  if ( priority & 0x20 || BYTE1(priority) & 0x10 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v14 = v39.m_buffer;
      v15 = v39.m_buffer->m_len;
      if ( v15 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v15 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v14->m_cRef) )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Upper Arms");
    v16 = v39.m_buffer;
    v17 = v39.m_buffer->m_len;
    if ( v17 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v17 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v16->m_cRef) )
      v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
  }
  if ( priority & 0x40 || BYTE1(priority) & 0x20 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v18 = v39.m_buffer;
      v19 = v39.m_buffer->m_len;
      if ( v19 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v19 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v18->m_cRef) )
        v18->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v18, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Lower Arms");
    v20 = v39.m_buffer;
    v21 = v39.m_buffer->m_len;
    if ( v21 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v21 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v20->m_cRef) )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
  }
  if ( SBYTE1(priority) < 0 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v22 = v39.m_buffer;
      v23 = v39.m_buffer->m_len;
      if ( v23 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v23 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v22->m_cRef) )
        v22->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v22, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Hands");
    v24 = v39.m_buffer;
    v25 = v39.m_buffer->m_len;
    if ( v25 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v25 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v24->m_cRef) )
      v24->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v24, 1u);
  }
  if ( priority & 2 || BYTE1(priority) & 1 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v26 = v39.m_buffer;
      v27 = v39.m_buffer->m_len;
      if ( v27 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v27 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v26->m_cRef) )
        v26->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v26, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Upper Legs");
    v28 = v39.m_buffer;
    v29 = v39.m_buffer->m_len;
    if ( v29 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v29 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v28->m_cRef) )
      v28->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v28, 1u);
  }
  if ( priority & 4 || BYTE1(priority) & 2 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, ", ");
      v30 = v39.m_buffer;
      v31 = v39.m_buffer->m_len;
      if ( v31 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v31 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v30->m_cRef) )
        v30->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v30, 1u);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v39, "Lower Legs");
    v32 = v39.m_buffer;
    v33 = v39.m_buffer->m_len;
    if ( v33 != 1 && v39.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v39.m_buffer->m_data, v33 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v32->m_cRef) )
      v32->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v32, 1u);
  }
  if ( priority & 0x10000 )
  {
    if ( v3 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&priority, ", ");
      v34 = priority;
      v35 = *(_DWORD *)(priority + 8);
      if ( v35 != 1 && priority != AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)(priority + 20), v35 - 1);
      if ( !InterlockedDecrement((volatile LONG *)(v34 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
    }
    else
    {
      v3 = 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&priority, "Feet");
    v36 = priority;
    v37 = *(_DWORD *)(priority + 8);
    if ( v37 != 1 && priority != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)(priority + 20), v37 - 1);
    if ( !InterlockedDecrement((volatile LONG *)(v36 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
  }
  return v3;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B5490) --------------------------------------------------------  // acclient.c:480118
int __cdecl AppraisalSystem::DamageResistanceToString(DAMAGE_TYPE dtype, const int al, float modifier, AC1Legacy::PStringBase<char> *ps)
{
  DAMAGE_TYPE v4; // ebx@1
  AC1Legacy::PStringBase<char> *v6; // edi@16
  DAMAGE_TYPE v7; // esi@18
  int v8; // eax@18
  DAMAGE_TYPE v9; // esi@60
  int v10; // eax@60
  const char *v11; // [sp+Ch] [bp-Ch]@4

  v4 = dtype;
  if ( (signed int)dtype > 16 )
  {
    if ( dtype == 32 )
    {
      v11 = "Acid: ";
    }
    else if ( dtype == 64 )
    {
      v11 = "Electric: ";
    }
    else
    {
      if ( dtype != 1024 )
        return 0;
      v11 = "Nether: ";
    }
  }
  else
  {
    if ( dtype != 16 )
    {
      switch ( dtype )
      {
        case 1:
          v11 = "Slashing: ";
          goto LABEL_16;
        case 2:
          v11 = "Piercing: ";
          goto LABEL_16;
        case 4:
          v11 = "Bludgeoning: ";
          goto LABEL_16;
        case 8:
          v11 = "Cold: ";
          goto LABEL_16;
        default:
          return 0;
      }
      return 0;
    }
    v11 = "Fire: ";
  }
LABEL_16:
  v6 = ps;
  AC1Legacy::PStringBase<char>::set(ps, v11);
  if ( -0.00019999999 > modifier )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, &name);
    goto LABEL_18;
  }
  if ( fabs(modifier) > 0.00019999999 )
  {
    if ( modifier <= 0.0 || modifier > 0.4 )
    {
      if ( modifier <= 0.4 || modifier > 0.8 )
      {
        if ( modifier <= 0.8 || modifier >= 1.2 )
        {
          if ( modifier >= 1.2 && modifier < 1.6 )
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Above Average");
            AC1Legacy::PStringBase<char>::operator+=(v6, (AC1Legacy::PStringBase<char> *)&dtype);
            goto LABEL_43;
          }
          if ( modifier >= 1.6 && modifier < 2.0 )
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Excellent");
            AC1Legacy::PStringBase<char>::operator+=(v6, (AC1Legacy::PStringBase<char> *)&dtype);
            goto LABEL_43;
          }
          if ( modifier < 2.0 )
            goto LABEL_44;
          modifier = 2.0;
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Unparalleled");
        }
        else
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Average");
        }
        AC1Legacy::PStringBase<char>::operator+=(v6, (AC1Legacy::PStringBase<char> *)&dtype);
        goto LABEL_43;
      }
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Below Average");
      AC1Legacy::PStringBase<char>::operator+=(v6, (AC1Legacy::PStringBase<char> *)&dtype);
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "Poor");
      AC1Legacy::PStringBase<char>::operator+=(v6, (AC1Legacy::PStringBase<char> *)&dtype);
    }
LABEL_43:
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&dtype);
    goto LABEL_44;
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&dtype, "No");
LABEL_18:
  v7 = dtype;
  v8 = *(_DWORD *)(dtype + 8);
  if ( v8 != 1 && dtype != AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(dtype + 20), v8 - 1);
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
    (**(void (__thiscall ***)(DAMAGE_TYPE, signed int))v7)(v7, 1);
LABEL_44:
  if ( -0.00019999999 > modifier )
  {
    if ( (signed int)v4 > 16 )
    {
      if ( v4 == 32 )
      {
        AC1Legacy::PStringBase<char>::set(v6, "Your armor itches and burns your skin.");
      }
      else if ( v4 == 64 )
      {
        AC1Legacy::PStringBase<char>::set(v6, "Your armor is extremely conductive.");
      }
      else
      {
        if ( v4 != 1024 )
          return 0;
        AC1Legacy::PStringBase<char>::set(v6, "Your armor is infused with shadow.");
      }
    }
    else
    {
      if ( v4 != 16 )
      {
        switch ( v4 )
        {
          case 1:
            AC1Legacy::PStringBase<char>::set(v6, "Your armor will rend and slash you if hit.");
            goto LABEL_60;
          case 2:
            AC1Legacy::PStringBase<char>::set(v6, "Your armor will cave in and pierce you if hit.");
            goto LABEL_60;
          case 4:
            AC1Legacy::PStringBase<char>::set(v6, "Your armor will shatter and bruise you if hit.");
            goto LABEL_60;
          case 8:
            AC1Legacy::PStringBase<char>::set(v6, "Your armor is unnaturally cold.");
            goto LABEL_60;
          default:
            return 0;
        }
        return 0;
      }
      AC1Legacy::PStringBase<char>::set(v6, "Your armor is flammable.");
    }
  }
LABEL_60:
  dtype = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::sprintf((AC1Legacy::PStringBase<char> *)&dtype, "  (%.0f)", (double)al * modifier);
  v9 = dtype;
  v10 = *(_DWORD *)(dtype + 8);
  if ( v10 != 1 && dtype != AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(dtype + 20), v10 - 1);
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
    (**(void (__thiscall ***)(DAMAGE_TYPE, signed int))v9)(v9, 1);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B5800) --------------------------------------------------------  // acclient.c:480292
int __cdecl AppraisalSystem::InqPluralizedGemName(unsigned int gem_type, PStringBase<char> *gemname)
{
  unsigned int v2; // esi@1
  const unsigned __int16 *v4; // eax@17
  PStringBase<char> *v5; // eax@20
  PStringBase<char> *v6; // eax@20
  PStringBase<char> *v7; // ebx@20
  PSRefBufferCharData<char> **v8; // edi@20
  PSRefBufferCharData<char> *v9; // eax@20
  int v10; // esi@21
  PSRefBufferCharData<char> *v11; // eax@24
  char *v12; // esi@25
  char *v13; // esi@28
  unsigned int v14; // esi@31
  PStringBase<char> rhs; // [sp+8h] [bp-8h]@17
  PStringBase<char> result; // [sp+Ch] [bp-4h]@17

  v2 = gem_type;
  if ( gem_type == 38 )
  {
    PStringBase<char>::set(gemname, "Rubies");
    return 1;
  }
  gem_type = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  MaterialTypeEnumMapper::MaterialTypeToString(v2, (PStringBase<char> *)&gem_type);
  if ( v2 == 11
    || v2 == 24
    || v2 == 27
    || v2 == 29
    || v2 == 32
    || v2 == 37
    || v2 == 40
    || v2 == 46
    || v2 == 36
    || v2 == 45 )
  {
    PStringBase<char>::PStringBase<char>(&rhs, "pieces of ");
    v6 = PStringBase<char>::operator+(v5, &result, (PStringBase<char> *)&gem_type);
    v7 = gemname;
    v8 = (PSRefBufferCharData<char> **)v6;
    v9 = gemname->m_charbuffer;
    if ( gemname->m_charbuffer != *v8 )
    {
      v10 = (int)&v9[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      v11 = *v8;
      v7->m_charbuffer = *v8;
      InterlockedIncrement((volatile LONG *)&v11[-1]);
    }
    v12 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    v13 = &rhs.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    goto LABEL_31;
  }
  if ( v2 == 26 || v2 == 49 )
  {
    PStringBase<char>::PStringBase<char>(&rhs, "es");
    v4 = (const unsigned __int16 *)PStringBase<char>::operator+((PStringBase<char> *)&gem_type, &result, &rhs);
    goto LABEL_18;
  }
  if ( v2 != 28 )
  {
    PStringBase<char>::PStringBase<char>(&rhs, "s");
    v4 = (const unsigned __int16 *)PStringBase<char>::operator+((PStringBase<char> *)&gem_type, &result, &rhs);
LABEL_18:
    PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)gemname, v4);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
    goto LABEL_31;
  }
  PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)gemname, (const unsigned __int16 *)&gem_type);
LABEL_31:
  v14 = gem_type - 20;
  if ( !InterlockedDecrement((volatile LONG *)(gem_type - 20 + 4)) )
  {
    if ( v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  }
  return 1;
}

//----- (005B59E0) --------------------------------------------------------  // acclient.c:480379
int __cdecl AppraisalSystem::InqCreatureDisplayName(unsigned int type, AC1Legacy::PStringBase<char> *strName)
{
  char *v2; // esi@2
  int result; // eax@5
  AC1Legacy::PSRefBuffer<char> *v4; // esi@6
  AC1Legacy::PSRefBuffer<char> *v5; // esi@9
  char *v6; // esi@12
  PStringBase<char> typeStr; // [sp+8h] [bp-Ch]@1
  AC1Legacy::PStringBase<char> search; // [sp+Ch] [bp-8h]@6
  AC1Legacy::PStringBase<char> str; // [sp+10h] [bp-4h]@6

  typeStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( EnumMapper::GetString(0x10000005u, type, &typeStr) )
  {
    AC1Legacy::PStringBase<char>::set(strName, typeStr.m_charbuffer->m_data);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&str, " ");
    AC1Legacy::PStringBase<char>::PStringBase<char>(&search, "_");
    AC1Legacy::PStringBase<char>::replace(strName, &search, &str);
    v4 = search.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&search.m_buffer->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    v5 = str.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&str.m_buffer->m_cRef) && v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
    v6 = &typeStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    result = 1;
  }
  else
  {
    v2 = &typeStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
    }
    result = 0;
  }
  return result;
}

//----- (005B5AE0) --------------------------------------------------------  // acclient.c:480423
int __cdecl AppraisalSystem::InqGenderHeritageDisplay(unsigned int gender, unsigned int heritage, unsigned int creature, AC1Legacy::PStringBase<char> *strName)
{
  AC1Legacy::PStringBase<char> *v4; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@1
  volatile LONG *v6; // ST04_4@5
  signed int v7; // ebp@6
  int v8; // eax@7
  AC1Legacy::PStringBase<char> *v9; // esi@7
  int v10; // eax@14
  AC1Legacy::PStringBase<char> *v11; // edi@14
  AC1Legacy::PStringBase<char> *v12; // esi@16
  AC1Legacy::PSRefBuffer<char> *v13; // eax@16
  AC1Legacy::PStringBase<char> *v14; // esi@21
  AC1Legacy::PSRefBuffer<char> *v15; // eax@21
  int v16; // esi@25
  int v17; // eax@27
  AC1Legacy::PSRefBuffer<char> *v18; // eax@30
  LONG v19; // eax@24
  int retval; // [sp+10h] [bp-4h]@1

  v4 = strName;
  v5 = strName->m_buffer;
  retval = 1;
  if ( strName->m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
    v6 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v4->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v6);
  }
  v7 = 0;
  if ( gender )
  {
    strName = (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v8 = AppraisalSystem::InqGenderDisplayName(gender, (AC1Legacy::PStringBase<char> *)&strName);
    v9 = strName;
    if ( v8 )
    {
      AC1Legacy::PStringBase<char>::set(v4, (const char *)&strName[5]);
      v7 = 1;
    }
    else
    {
      retval = 0;
    }
    if ( !InterlockedDecrement((volatile LONG *)&v9[1]) && v9 )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v9->m_buffer->vfptr)(v9, 1);
  }
  if ( heritage )
  {
    strName = (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v10 = AppraisalSystem::InqHeritageGroupDisplayName(heritage, (AC1Legacy::PStringBase<char> *)&strName);
    v11 = strName;
    if ( v10 )
    {
      if ( v7 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&strName, " ");
        v12 = strName;
        v13 = strName[2].m_buffer;
        if ( v13 != (AC1Legacy::PSRefBuffer<char> *)1
          && strName != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
          AC1Legacy::PStringBase<char>::append_n_chars(v4, (const char *)&strName[5], (unsigned int)&v13[-1].m_data[3]);
        if ( !InterlockedDecrement((volatile LONG *)&v12[1]) )
          ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v12->m_buffer->vfptr)(v12, 1);
      }
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&strName, (const char *)&v11[5]);
      v14 = strName;
      v15 = strName[2].m_buffer;
      if ( v15 != (AC1Legacy::PSRefBuffer<char> *)1
        && strName != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v4, (const char *)&strName[5], (unsigned int)&v15[-1].m_data[3]);
      v19 = InterlockedDecrement((volatile LONG *)&v14[1]);
LABEL_34:
      if ( !v19 )
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v14->m_buffer->vfptr)(v14, 1);
      v16 = retval;
      goto LABEL_37;
    }
  }
  else
  {
    if ( !creature )
      return retval;
    strName = (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v17 = AppraisalSystem::InqCreatureDisplayName(creature, (AC1Legacy::PStringBase<char> *)&strName);
    v11 = strName;
    if ( v17 )
    {
      if ( v7 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&strName, " ");
        AC1Legacy::PStringBase<char>::operator+=(v4, (AC1Legacy::PStringBase<char> *)&strName);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&strName);
      }
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&strName, (const char *)&v11[5]);
      v14 = strName;
      v18 = strName[2].m_buffer;
      if ( v18 != (AC1Legacy::PSRefBuffer<char> *)1
        && strName != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v4, (const char *)&strName[5], (unsigned int)&v18[-1].m_data[3]);
      v19 = InterlockedDecrement((volatile LONG *)&v14[1]);
      goto LABEL_34;
    }
  }
  v16 = 0;
LABEL_37:
  if ( !InterlockedDecrement((volatile LONG *)&v11[1]) )
  {
    if ( v11 )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v11->m_buffer->vfptr)(v11, 1);
  }
  return v16;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

