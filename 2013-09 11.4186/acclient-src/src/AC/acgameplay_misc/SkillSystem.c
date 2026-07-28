/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SkillSystem
   Object     : AC\acgameplay_misc\SkillSystem.obj
   Functions  : 21
   Addresses  : 005C86E0 - 0070F7D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C86E0) --------------------------------------------------------  // acclient.c:499603
char __cdecl SkillSystem::InqSkillName(unsigned int skill, AC1Legacy::PStringBase<char> *name)
{
  unsigned int v2; // esi@1
  int v4; // eax@3
  int v5; // ebx@3
  SkillBase *v6; // eax@4
  unsigned int v7; // esi@7

  v2 = skill;
  if ( !skill )
    return 0;
  v4 = DBObj::GetByEnum(4, 2, 0x10000004u);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = SkillTable::GetSkillBase((SkillTable *)v4, v2);
  if ( !v6 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    return 0;
  }
  skill = (unsigned int)v6->_name.m_buffer;
  v7 = skill;
  InterlockedIncrement((volatile LONG *)(skill + 4));
  AC1Legacy::PStringBase<unsigned short>::operator=(
    (AC1Legacy::PStringBase<unsigned short> *)name,
    (AC1Legacy::PStringBase<unsigned short> *)&skill);
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v5 + 20))(v5);
  return 1;
}

//----- (005C8770) --------------------------------------------------------  // acclient.c:499640
char __cdecl SkillSystem::InqSkillDescription(unsigned int skill, AC1Legacy::PStringBase<char> *name)
{
  unsigned int v2; // esi@1
  int v4; // eax@3
  int v5; // ebx@3
  SkillBase *v6; // eax@4
  unsigned int v7; // esi@7

  v2 = skill;
  if ( !skill )
    return 0;
  v4 = DBObj::GetByEnum(4, 2, 0x10000004u);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = SkillTable::GetSkillBase((SkillTable *)v4, v2);
  if ( !v6 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    return 0;
  }
  skill = (unsigned int)v6->_description.m_buffer;
  v7 = skill;
  InterlockedIncrement((volatile LONG *)(skill + 4));
  AC1Legacy::PStringBase<unsigned short>::operator=(
    (AC1Legacy::PStringBase<unsigned short> *)name,
    (AC1Legacy::PStringBase<unsigned short> *)&skill);
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v5 + 20))(v5);
  return 1;
}

//----- (005C8800) --------------------------------------------------------  // acclient.c:499677
char __cdecl SkillSystem::InqAttributeName(unsigned int stype, AC1Legacy::PStringBase<char> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(name, "Strength");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(name, "Endurance");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(name, "Quickness");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(name, "Coordination");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(name, "Focus");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(name, "Self");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C88A0) --------------------------------------------------------  // acclient.c:499715
char __cdecl SkillSystem::InqAttribute2ndName(unsigned int stype, AC1Legacy::PStringBase<char> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(name, "Maximum Health");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(name, "Health");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(name, "Maximum Stamina");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(name, "Stamina");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(name, "Maximum Mana");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(name, "Mana");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C8940) --------------------------------------------------------  // acclient.c:499753
char __cdecl SkillSystem::InqSkillName(unsigned int i_skill, PStringBase<unsigned short> *o_strWideName)
{
  char v2; // al@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  char v4; // bl@1
  AC1Legacy::PStringBase<char> strName; // [sp+0h] [bp-4h]@1

  strName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v2 = SkillSystem::InqSkillName(i_skill, &strName);
  v3 = strName.m_buffer;
  v4 = v2;
  if ( v2 )
    PStringBase<unsigned short>::sprintf(o_strWideName, L"%hs", strName.m_buffer->m_data);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return v4;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005C89B0) --------------------------------------------------------  // acclient.c:499774
char __cdecl SkillSystem::InqSkillFormula(unsigned int skill, AC1Legacy::PStringBase<char> *formula)
{
  unsigned int v2; // edi@1
  int v4; // eax@3
  int v5; // esi@3
  SkillBase *v6; // eax@4
  unsigned int v7; // ebp@7
  unsigned int v8; // edx@7
  unsigned int v9; // ecx@7
  unsigned int v10; // eax@7
  signed int v11; // ebx@9
  signed int v12; // edi@13
  AC1Legacy::PStringBase<char> *v13; // esi@18
  AC1Legacy::PSRefBuffer<char> *v14; // edi@21
  int v15; // ebx@21
  int v16; // ebp@25
  int v17; // esi@39
  unsigned int v18; // esi@42
  AC1Legacy::PStringBase<char> attrib; // [sp+4h] [bp-2Ch]@21
  int attribute2Present; // [sp+8h] [bp-28h]@13
  int attribute1Present; // [sp+Ch] [bp-24h]@9
  DBObjGrabber<SkillTable> stable; // [sp+10h] [bp-20h]@3
  SkillFormula skill_formula; // [sp+14h] [bp-1Ch]@7

  v2 = skill;
  if ( !skill )
    return 0;
  v4 = DBObj::GetByEnum(4, 2, 0x10000004u);
  v5 = v4;
  stable.m_object = (SkillTable *)v4;
  if ( !v4 )
    return 0;
  v6 = SkillTable::GetSkillBase((SkillTable *)v4, v2);
  if ( !v6 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    return 0;
  }
  v7 = v6->_formula._x;
  v8 = v6->_formula._y;
  skill_formula._w = v6->_formula._w;
  skill_formula._z = v6->_formula._z;
  v9 = v6->_formula._attr1;
  v10 = v6->_formula._attr2;
  skill_formula._y = v8;
  skill_formula._attr1 = v9;
  skill_formula._attr2 = v10;
  if ( v7 >= 1 && v9 )
  {
    v11 = 1;
    attribute1Present = 1;
  }
  else
  {
    attribute1Present = 0;
    v11 = 0;
  }
  if ( v8 >= 1 && v10 )
  {
    v12 = 1;
    attribute2Present = 1;
  }
  else
  {
    attribute2Present = 0;
    v12 = 0;
  }
  if ( !v11 && !v12 )
  {
    DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&stable);
    return 0;
  }
  v13 = formula;
  AC1Legacy::PStringBase<char>::set(formula, "( ");
  if ( v11 && v12 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&skill, "(");
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&skill);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&skill);
  }
  v14 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  attrib.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  skill = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v15 = attribute1Present;
  if ( !attribute1Present )
  {
    v16 = attribute2Present;
LABEL_28:
    if ( v16 )
    {
      SkillSystem::InqAttributeName(skill_formula._attr2, &attrib);
      if ( skill_formula._y <= 1 )
      {
        AC1Legacy::PStringBase<char>::operator+=(v13, &attrib);
        v14 = attrib.m_buffer;
      }
      else
      {
        v14 = attrib.m_buffer;
        AC1Legacy::PStringBase<char>::sprintf(
          (AC1Legacy::PStringBase<char> *)&skill,
          "(%u x %s)",
          skill_formula._y,
          attrib.m_buffer);
        AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&skill);
      }
    }
    goto LABEL_32;
  }
  SkillSystem::InqAttributeName(skill_formula._attr1, &attrib);
  v14 = attrib.m_buffer;
  if ( v7 <= 1 )
  {
    AC1Legacy::PStringBase<char>::operator+=(v13, &attrib);
  }
  else
  {
    AC1Legacy::PStringBase<char>::sprintf((AC1Legacy::PStringBase<char> *)&skill, "(%u x %s)", v7, attrib.m_buffer);
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&skill);
  }
  v16 = attribute2Present;
  if ( attribute2Present )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&attribute1Present, " + ");
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&attribute1Present);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&attribute1Present);
    goto LABEL_28;
  }
LABEL_32:
  if ( v15 && v16 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&attribute1Present, ")");
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&attribute1Present);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&attribute1Present);
  }
  if ( skill_formula._z != 1 )
  {
    AC1Legacy::PStringBase<char>::sprintf((AC1Legacy::PStringBase<char> *)&skill, " / %u", skill_formula._z);
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&skill);
  }
  if ( skill_formula._w )
  {
    AC1Legacy::PStringBase<char>::sprintf((AC1Legacy::PStringBase<char> *)&skill, "+%u", skill_formula._w);
    AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&skill);
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&attribute1Present, " )");
  AC1Legacy::PStringBase<char>::operator+=(v13, (AC1Legacy::PStringBase<char> *)&attribute1Present);
  v17 = attribute1Present;
  if ( !InterlockedDecrement((volatile LONG *)(attribute1Present + 4)) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  v18 = skill;
  if ( !InterlockedDecrement((volatile LONG *)(skill + 4)) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v14->m_cRef) )
  {
    if ( v14 )
      v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
  }
  ((void (*)(void))stable.m_object->vfptr->Release)();
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005C8CB0) --------------------------------------------------------  // acclient.c:499940
char __cdecl SkillSystem::InqSkillFormula(unsigned int i_skill, PStringBase<unsigned short> *o_strWideFormula)
{
  char v2; // al@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  char v4; // bl@1
  AC1Legacy::PStringBase<char> strFormula; // [sp+0h] [bp-4h]@1

  strFormula.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v2 = SkillSystem::InqSkillFormula(i_skill, &strFormula);
  v3 = strFormula.m_buffer;
  v4 = v2;
  if ( v2 )
    PStringBase<unsigned short>::sprintf(o_strWideFormula, L"%hs", strFormula.m_buffer->m_data);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return v4;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005C8D20) --------------------------------------------------------  // acclient.c:499961
char __cdecl SkillSystem::InqSkillDescription(unsigned int i_skill, PStringBase<unsigned short> *o_strWideName)
{
  char v2; // al@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  char v4; // bl@1
  AC1Legacy::PStringBase<char> strName; // [sp+0h] [bp-4h]@1

  strName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v2 = SkillSystem::InqSkillDescription(i_skill, &strName);
  v3 = strName.m_buffer;
  v4 = v2;
  if ( v2 )
    PStringBase<unsigned short>::sprintf(o_strWideName, L"%hs", strName.m_buffer->m_data);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return v4;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005C8D90) --------------------------------------------------------  // acclient.c:499982
char __cdecl SkillSystem::InqAttributeName(unsigned int stype, PStringBase<unsigned short> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
      PStringBase<unsigned short>::set(name, L"Strength");
      result = 1;
      break;
    case 2u:
      PStringBase<unsigned short>::set(name, L"Endurance");
      result = 1;
      break;
    case 3u:
      PStringBase<unsigned short>::set(name, L"Quickness");
      result = 1;
      break;
    case 4u:
      PStringBase<unsigned short>::set(name, L"Coordination");
      result = 1;
      break;
    case 5u:
      PStringBase<unsigned short>::set(name, L"Focus");
      result = 1;
      break;
    case 6u:
      PStringBase<unsigned short>::set(name, L"Self");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C8E30) --------------------------------------------------------  // acclient.c:500020
char __cdecl SkillSystem::InqAttributeDescription(unsigned int stype, PStringBase<unsigned short> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
      PStringBase<unsigned short>::set(name, L"Measures your character's muscular power.");
      result = 1;
      break;
    case 2u:
      PStringBase<unsigned short>::set(name, L"Measures how healthy your character is.");
      result = 1;
      break;
    case 3u:
      PStringBase<unsigned short>::set(name, L"Measures how fast your character is.");
      result = 1;
      break;
    case 4u:
      PStringBase<unsigned short>::set(name, L"Measures your character's reflexes");
      result = 1;
      break;
    case 5u:
      PStringBase<unsigned short>::set(name, L"Measures your character's mind and senses.");
      result = 1;
      break;
    case 6u:
      PStringBase<unsigned short>::set(name, L"Measures your character's willpower.");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C8ED0) --------------------------------------------------------  // acclient.c:500058
char __cdecl SkillSystem::InqAttribute2ndName(unsigned int stype, PStringBase<unsigned short> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
      PStringBase<unsigned short>::set(name, L"Maximum Health");
      result = 1;
      break;
    case 2u:
      PStringBase<unsigned short>::set(name, L"Health");
      result = 1;
      break;
    case 3u:
      PStringBase<unsigned short>::set(name, L"Maximum Stamina");
      result = 1;
      break;
    case 4u:
      PStringBase<unsigned short>::set(name, L"Stamina");
      result = 1;
      break;
    case 5u:
      PStringBase<unsigned short>::set(name, L"Maximum Mana");
      result = 1;
      break;
    case 6u:
      PStringBase<unsigned short>::set(name, L"Mana");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C8F70) --------------------------------------------------------  // acclient.c:500096
char __cdecl SkillSystem::InqAttribute2ndDescription(unsigned int stype, PStringBase<unsigned short> *name)
{
  char result; // al@2

  switch ( stype )
  {
    case 1u:
    case 2u:
      PStringBase<unsigned short>::set(name, L"(Endurance/2)\nIf you run out of health, you will die!");
      result = 1;
      break;
    case 3u:
    case 4u:
      PStringBase<unsigned short>::set(name, L"(Endurance)\nAffects your actions and movement.");
      result = 1;
      break;
    case 5u:
    case 6u:
      PStringBase<unsigned short>::set(name, L"(Self)\nAffects how much magic you can cast.");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0070F710) --------------------------------------------------------  // acclient.c:802637
int sub_70F710()
{
  return atexit(nullsub_1757);
}

//----- (0070F720) --------------------------------------------------------  // acclient.c:802643
int _E4_14()
{
  return atexit(_E5_14);
}

//----- (0070F730) --------------------------------------------------------  // acclient.c:802649
int _E7_14()
{
  Outside_CellID_14.id = Invalid_CellID_14.id + 1;
  return atexit(_E8_14);
}

//----- (0070F750) --------------------------------------------------------  // acclient.c:802656
int _E10_13()
{
  In_Limbo_CellID_13.id = Outside_CellID_14.id + 1;
  return atexit(_E11_13);
}

//----- (0070F770) --------------------------------------------------------  // acclient.c:802663
int _E13_13()
{
  First_Interior_CellID_13.id = In_Limbo_CellID_13.id + 1;
  return atexit(_E14_13);
}

//----- (0070F790) --------------------------------------------------------  // acclient.c:802670
int _E16_13()
{
  Last_Interior_CellID_13.id = Invalid_CellID_14.id - 1;
  return atexit(_E17_13);
}

//----- (0070F7B0) --------------------------------------------------------  // acclient.c:802677
int _E21_15()
{
  return atexit(_E22_15);
}

//----- (0070F7C0) --------------------------------------------------------  // acclient.c:802683
int _E40_15()
{
  return atexit(_E41_15);
}

//----- (0070F7D0) --------------------------------------------------------  // acclient.c:802689
int _E43_18()
{
  return atexit(_E44_18);
}

