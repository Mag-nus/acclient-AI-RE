/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSpellBase
   Object     : AC\accmagic\CSpellBase.obj
   Functions  : 16
   Addresses  : 00596A50 - 0070AD40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00596A50) --------------------------------------------------------  // acclient.c:448599
signed int __thiscall CSpellBase::InqSkillForSpell(CSpellBase *this)
{
  signed int result; // eax@2

  switch ( this->_school )
  {
    case 5u:
      result = 43;
      break;
    case 1u:
      result = 34;
      break;
    case 2u:
      result = 33;
      break;
    case 3u:
      result = 32;
      break;
    case 4u:
      result = 31;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00596AA0) --------------------------------------------------------  // acclient.c:448628
double __thiscall CSpellBase::InqDuration(CSpellBase *this)
{
  MetaSpell *v1; // esi@1
  double result; // st7@2

  v1 = &this->_meta_spell;
  if ( EnumPropertyValue::HasValidData(&this->_meta_spell) )
    result = MetaSpell::InqDuration(v1);
  else
    result = -1.0;
  return result;
}

//----- (00596AD0) --------------------------------------------------------  // acclient.c:448642
int __thiscall CSpellBase::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@5
  int v5; // ebx@6
  int v6; // eax@10

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  v5 = *(_DWORD *)(v2 + 8);
  if ( v5 != *(_DWORD *)(a2 + 8) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v6;
    InterlockedIncrement((volatile LONG *)(v6 + 4));
  }
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  *(float *)(v2 + 36) = *(float *)(a2 + 36);
  *(float *)(v2 + 40) = *(float *)(a2 + 40);
  *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
  *(float *)(v2 + 48) = *(float *)(a2 + 48);
  *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
  *(float *)(v2 + 56) = *(float *)(a2 + 56);
  *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
  *(_DWORD *)(v2 + 88) = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(v2 + 92) = *(_DWORD *)(a2 + 92);
  *(_DWORD *)(v2 + 96) = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(v2 + 100) = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(v2 + 104) = *(_DWORD *)(a2 + 104);
  *(double *)(v2 + 112) = *(double *)(a2 + 112);
  *(float *)(v2 + 120) = *(float *)(a2 + 120);
  *(_DWORD *)(v2 + 124) = *(_DWORD *)(a2 + 124);
  *(_DWORD *)(v2 + 128) = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  MetaSpell::operator=(v2 + 132, a2 + 132);
  return v2;
}

//----- (00596C00) --------------------------------------------------------  // acclient.c:448701
int __thiscall CSpellBase::packed_size(CSpellBase *this)
{
  CSpellBase *v1; // esi@1
  char *v2; // edi@1
  char *v3; // ebx@1
  int v4; // ebp@1
  int v5; // ebp@1
  int v6; // ebp@1
  void *addr; // [sp+10h] [bp-4h]@1

  v1 = this;
  addr = 0;
  v2 = (char *)&this->_meta_spell;
  v3 = (char *)&this->_formula;
  v4 = AC1Legacy::PStringBase<char>::Pack(&this->_desc, &addr, 0);
  v5 = AC1Legacy::PStringBase<char>::Pack(&v1->_name, &addr, 0) + v4;
  v6 = (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v3 + 12))(&v1->_formula, &addr, 0) + v5;
  return (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v2 + 12))(&v1->_meta_spell, &addr, 0) + v6 + 80;
}

//----- (00596C70) --------------------------------------------------------  // acclient.c:448722
int __thiscall CSpellBase::Pack(CSpellBase *this, void **addr, unsigned int size)
{
  CSpellBase *v3; // edi@1
  int v4; // ebp@1
  void **v5; // esi@2
  char *v6; // edx@2
  char *v7; // ecx@2
  char *v8; // eax@2
  char *v9; // edx@2
  char *v10; // ecx@2
  char *v11; // eax@2
  char *v12; // edx@2
  char *v13; // ecx@2
  char *v14; // eax@2
  char *v15; // edx@2
  char *v16; // ebx@2
  char *v17; // edx@2
  char *v18; // ecx@2
  char *v19; // eax@2
  char *v20; // ebx@2
  char *v21; // edx@2
  char *v22; // ecx@2

  v3 = this;
  v4 = CSpellBase::packed_size(this);
  if ( size >= v4 )
  {
    v5 = addr;
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_desc, addr, size);
    *(_DWORD *)*addr = v3->_school;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_iconID.id;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_category;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_bitfield;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_base_mana;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(float *)v10 = v3->_base_range_constant;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(float *)v11 = v3->_base_range_mod;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->_power;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(float *)v13 = v3->_spell_economy_mod;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(_DWORD *)v14 = v3->_formula_version;
    v15 = (char *)*addr + 4;
    *addr = v15;
    *(float *)v15 = v3->_component_loss;
    *v5 = (char *)*v5 + 4;
    ((void (__thiscall *)(int, void **, unsigned int))v3->_meta_spell.vfptr->Pack)(&v3->_meta_spell, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->_formula.vfptr->Pack)(&v3->_formula, addr, size);
    *(_DWORD *)*addr = v3->_caster_effect;
    v16 = (char *)*addr + 4;
    *addr = v16;
    *(_DWORD *)v16 = v3->_target_effect;
    v17 = (char *)*addr + 4;
    *addr = v17;
    *(_DWORD *)v17 = v3->_fizzle_effect;
    v18 = (char *)*addr + 4;
    *addr = v18;
    *(double *)v18 = v3->_recovery_interval;
    v19 = (char *)*addr + 8;
    *addr = v19;
    *(float *)v19 = v3->_recovery_amount;
    v20 = (char *)*addr + 4;
    *addr = v20;
    *(_DWORD *)v20 = v3->_display_order;
    v21 = (char *)*addr + 4;
    *addr = v21;
    *(_DWORD *)v21 = v3->_non_component_target_type;
    v22 = (char *)*addr + 4;
    *addr = v22;
    *(_DWORD *)v22 = v3->_mana_mod;
    *v5 = (char *)*v5 + 4;
  }
  return v4;
}

//----- (00596DD0) --------------------------------------------------------  // acclient.c:448814
void __thiscall CSpellBase::CSpellBase(CSpellBase *this, CSpellBase *from)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&CSpellBase::vftable;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  *(_DWORD *)(v2 + 8) = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  *(_DWORD *)(v2 + 60) = &SpellFormula::vftable;
  memset((void *)(v2 + 64), 0, 0x20u);
  MetaSpell::MetaSpell((MetaSpell *)(v2 + 132));
  CSpellBase::operator=(v2, (int)from);
}
// 7A3A8C: using guessed type int (__thiscall *SpellFormula::vftable)(void *, char);
// 7A3E94: using guessed type int (__thiscall *CSpellBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00596E40) --------------------------------------------------------  // acclient.c:448838
AC1Legacy::PStringBase<char> *__thiscall CSpellBase::InqDescription(CSpellBase *this, AC1Legacy::PStringBase<char> *result)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  char *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  AC1Legacy::PStringBase<char> ret; // [sp+10h] [bp-4h]@1

  ret.m_buffer = this->_desc.m_buffer;
  InterlockedIncrement((volatile LONG *)&ret.m_buffer->m_cRef);
  AC1Legacy::PStringBase<char>::break_reference(&ret);
  v2 = ret.m_buffer;
  v3 = ret.m_buffer->m_data;
  v4 = (AC1Legacy::PSRefBuffer<char> *)((char *)ret.m_buffer + ret.m_buffer->m_len + 19);
  if ( (AC1Legacy::PSRefBuffer<char> *)((char *)ret.m_buffer + 20) != v4 )
  {
    do
    {
      *v3 = 16 * *v3 | ((unsigned __int8)*v3 >> 4);
      ++v3;
    }
    while ( (AC1Legacy::PSRefBuffer<char> *)v3 != v4 );
  }
  result->m_buffer = v2;
  InterlockedIncrement((volatile LONG *)&v2->m_cRef);
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return result;
}

//----- (00596EB0) --------------------------------------------------------  // acclient.c:448868
SpellFormula *__thiscall CSpellBase::InqSpellFormula(CSpellBase *this, SpellFormula *result)
{
  CSpellBase *v2; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  char *v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@3
  char *v7; // ecx@3
  AC1Legacy::PSRefBuffer<char> *v8; // esi@3
  unsigned int v9; // eax@5
  unsigned int v10; // eax@7
  AC1Legacy::PSRefBuffer<char> *v11; // edi@11
  AC1Legacy::PStringBase<char> n; // [sp+Ch] [bp-30h]@1
  AC1Legacy::PStringBase<char> d; // [sp+10h] [bp-2Ch]@1
  unsigned int v15; // [sp+14h] [bp-28h]@7
  SpellFormula ret; // [sp+18h] [bp-24h]@9

  v2 = this;
  n.m_buffer = this->_name.m_buffer;
  InterlockedIncrement((volatile LONG *)&n.m_buffer->m_cRef);
  d.m_buffer = v2->_desc.m_buffer;
  InterlockedIncrement((volatile LONG *)&d.m_buffer->m_cRef);
  AC1Legacy::PStringBase<char>::break_reference(&n);
  v3 = n.m_buffer;
  v4 = n.m_buffer->m_data;
  v5 = (AC1Legacy::PSRefBuffer<char> *)((char *)n.m_buffer + n.m_buffer->m_len + 19);
  if ( (AC1Legacy::PSRefBuffer<char> *)((char *)n.m_buffer + 20) != v5 )
  {
    do
    {
      *v4 = 16 * *v4 | ((unsigned __int8)*v4 >> 4);
      ++v4;
    }
    while ( (AC1Legacy::PSRefBuffer<char> *)v4 != v5 );
  }
  AC1Legacy::PStringBase<char>::break_reference(&d);
  v6 = d.m_buffer;
  v7 = d.m_buffer->m_data;
  v8 = (AC1Legacy::PSRefBuffer<char> *)((char *)d.m_buffer + d.m_buffer->m_len + 19);
  if ( (AC1Legacy::PSRefBuffer<char> *)((char *)d.m_buffer + 20) != v8 )
  {
    do
    {
      *v7 = 16 * *v7 | ((unsigned __int8)*v7 >> 4);
      ++v7;
    }
    while ( (AC1Legacy::PSRefBuffer<char> *)v7 != v8 );
  }
  v9 = v3->m_hash;
  if ( v9 == -1 )
  {
    v9 = AC1Legacy::PStringBase<char>::compute_hash(&n);
    v3->m_hash = v9;
  }
  v15 = v9;
  v10 = v6->m_hash;
  if ( v10 == -1 )
  {
    v10 = AC1Legacy::PStringBase<char>::compute_hash(&d);
    v6->m_hash = v10;
  }
  ret.vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  qmemcpy(ret._comps, v2->_formula._comps, sizeof(ret._comps));
  SpellFormula::Decrypt(&ret, v15 % 0x12107680 + v10 % 0xBEADCF45);
  qmemcpy(result->_comps, ret._comps, sizeof(result->_comps));
  result->vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  ret.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  v11 = n.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&n.m_buffer->m_cRef) )
    v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A3A8C: using guessed type int (__thiscall *SpellFormula::vftable)(void *, char);

//----- (00597000) --------------------------------------------------------  // acclient.c:448946
SpellFormula *__thiscall CSpellBase::InqCustomizedSpellFormula(CSpellBase *this, SpellFormula *result, AC1Legacy::PStringBase<char> *account_name)
{
  CSpellBase *v3; // esi@1
  SpellFormula *v4; // eax@1
  SpellFormula formula; // [sp+8h] [bp-24h]@1

  v3 = this;
  CSpellBase::InqSpellFormula(this, &formula);
  SpellFormula::RandomizeForName(&formula, account_name, v3->_formula_version);
  v4 = result;
  qmemcpy(result->_comps, formula._comps, sizeof(result->_comps));
  result->vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  return v4;
}
// 7A3A8C: using guessed type int (__thiscall *SpellFormula::vftable)(void *, char);

//----- (00597050) --------------------------------------------------------  // acclient.c:448963
SpellFormula *__thiscall CSpellBase::InqScarabOnlyFormula(CSpellBase *this, SpellFormula *result)
{
  int v2; // edi@1
  signed int v3; // esi@1
  unsigned int v4; // eax@4
  signed int v5; // eax@9
  signed int v6; // esi@15
  SpellFormula *v7; // eax@17
  unsigned int uPower; // [sp+8h] [bp-4Ch]@8
  SpellFormula formula; // [sp+Ch] [bp-48h]@1
  SpellFormula formulaOriginal; // [sp+30h] [bp-24h]@1

  CSpellBase::InqSpellFormula(this, &formulaOriginal);
  formula.vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  memset(formula._comps, 0, sizeof(formula._comps));
  v2 = 0;
  v3 = 0;
  do
  {
    if ( v3 < 0 )
      break;
    if ( v3 >= 8 )
      break;
    v4 = formulaOriginal._comps[v3];
    if ( !v4 )
      break;
    switch ( v4 )
    {
      case 1u:
      case 2u:
      case 3u:
      case 4u:
      case 5u:
      case 6u:
      case 0x6Eu:
      case 0x6Fu:
      case 0x70u:
      case 0xC0u:
      case 0xC1u:
        SpellFormula::SetComponent(&formula, v2++, formulaOriginal._comps[v3]);
        break;
      default:
        break;
    }
    ++v3;
  }
  while ( v3 < 8 );
  uPower = 0;
  SpellFormula::FindMostPowerfulPowerComponent(&formula, &uPower);
  switch ( uPower )
  {
    case 1u:
      v5 = 1;
      break;
    case 2u:
      v5 = 2;
      break;
    case 3u:
    case 4u:
    case 7u:
      v5 = 3;
      break;
    case 5u:
    case 6u:
    case 8u:
    case 9u:
    case 0xAu:
      v5 = 4;
      break;
    default:
      v5 = 0;
      break;
  }
  if ( v5 )
  {
    v6 = v5;
    do
    {
      SpellFormula::SetComponent(&formula, v2++, 0xBCu);
      --v6;
    }
    while ( v6 );
  }
  v7 = result;
  qmemcpy(result->_comps, formula._comps, sizeof(result->_comps));
  result->vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  return v7;
}
// 7A3A8C: using guessed type int (__thiscall *SpellFormula::vftable)(void *, char);

//----- (00597230) --------------------------------------------------------  // acclient.c:449054
signed int __thiscall CSpellBase::InqTargetType(CSpellBase *this)
{
  signed int result; // eax@1
  SpellFormula formula; // [sp+0h] [bp-24h]@1

  CSpellBase::InqSpellFormula(this, &formula);
  result = SpellFormula::Complete(&formula);
  if ( result )
    result = SpellFormula::GetTargetingType(&formula);
  return result;
}

//----- (00597260) --------------------------------------------------------  // acclient.c:449067
signed int __thiscall CSpellBase::InqSpellLevelByRoughHeuristic(CSpellBase *this)
{
  SpellFormula *v1; // eax@1
  signed int v2; // eax@1
  SpellFormula result; // [sp+0h] [bp-24h]@1

  v1 = CSpellBase::InqSpellFormula(this, &result);
  v2 = SpellFormula::GetPowerLevelOfPowerComponent(v1);
  if ( (unsigned int)v2 >= 7 )
  {
    if ( (unsigned int)v2 >= 9 )
      v2 -= 2;
    else
      --v2;
  }
  return v2;
}

//----- (00597290) --------------------------------------------------------  // acclient.c:449086
int __thiscall CSpellBase::UnPack(CSpellBase *this, void **addr, unsigned int size)
{
  void *v3; // ebp@1
  CSpellBase *v4; // edi@1
  char *v5; // eax@2
  unsigned int v6; // ecx@2
  char *v7; // edx@2
  char *v8; // ecx@2
  char *v9; // eax@2
  char *v10; // edx@2
  char *v11; // ecx@2
  char *v12; // eax@2
  char *v13; // edx@2
  char *v14; // ecx@2
  char *v15; // eax@2
  char *v16; // edx@2
  char *v17; // ecx@2
  char *v18; // eax@2
  char *v19; // edx@2
  char *v20; // ecx@2
  char *v21; // eax@2
  unsigned int v22; // eax@2

  v3 = *addr;
  v4 = this;
  if ( size < CSpellBase::packed_size(this) )
    return 0;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_name, addr, size);
  AC1Legacy::PStringBase<char>::UnPack(&v4->_desc, addr, size);
  v4->_school = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  v6 = *(_DWORD *)v5;
  *addr = v5 + 4;
  v4->_iconID.id = v6;
  v4->_category = *(_DWORD *)*addr;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v4->_bitfield = *(_DWORD *)v7;
  v8 = (char *)*addr + 4;
  *addr = v8;
  v4->_base_mana = *(_DWORD *)v8;
  v9 = (char *)*addr + 4;
  *addr = v9;
  LODWORD(v4->_base_range_constant) = *(_DWORD *)v9;
  v10 = (char *)*addr + 4;
  *addr = v10;
  LODWORD(v4->_base_range_mod) = *(_DWORD *)v10;
  v11 = (char *)*addr + 4;
  *addr = v11;
  v4->_power = *(_DWORD *)v11;
  v12 = (char *)*addr + 4;
  *addr = v12;
  LODWORD(v4->_spell_economy_mod) = *(_DWORD *)v12;
  v13 = (char *)*addr + 4;
  *addr = v13;
  v4->_formula_version = *(_DWORD *)v13;
  v14 = (char *)*addr + 4;
  *addr = v14;
  LODWORD(v4->_component_loss) = *(_DWORD *)v14;
  *addr = (char *)*addr + 4;
  ((void (__stdcall *)(void **, unsigned int))v4->_meta_spell.vfptr->UnPack)(addr, size);
  ((void (__thiscall *)(int, void **, unsigned int))v4->_formula.vfptr->UnPack)(&v4->_formula, addr, size);
  v4->_caster_effect = *(_DWORD *)*addr;
  v15 = (char *)*addr + 4;
  *addr = v15;
  v4->_target_effect = *(_DWORD *)v15;
  v16 = (char *)*addr + 4;
  *addr = v16;
  v4->_fizzle_effect = *(_DWORD *)v16;
  v17 = (char *)*addr + 4;
  *addr = v17;
  LODWORD(v4->_recovery_interval) = *(_DWORD *)v17;
  HIDWORD(v4->_recovery_interval) = *((_DWORD *)v17 + 1);
  v18 = (char *)*addr + 8;
  *addr = v18;
  LODWORD(v4->_recovery_amount) = *(_DWORD *)v18;
  v19 = (char *)*addr + 4;
  *addr = v19;
  v4->_display_order = *(_DWORD *)v19;
  v20 = (char *)*addr + 4;
  *addr = v20;
  v4->_non_component_target_type = *(_DWORD *)v20;
  v21 = (char *)*addr + 4;
  *addr = v21;
  v4->_mana_mod = *(_DWORD *)v21;
  v22 = (_BYTE *)*addr + 4 - (_BYTE *)v3;
  *addr = (char *)*addr + 4;
  if ( size < v22 )
  {
    *addr = v3;
    return 0;
  }
  return 1;
}

//----- (00597400) --------------------------------------------------------  // acclient.c:449183
AC1Legacy::PStringBase<char> *__cdecl CSpellBase::SchoolEnumToName(AC1Legacy::PStringBase<char> *result, const unsigned int school)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@8
  volatile LONG *v3; // edi@8
  volatile LONG *v4; // ST00_4@8
  AC1Legacy::PStringBase<char> ret; // [sp+10h] [bp-4h]@1

  ret.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  switch ( school )
  {
    case 5u:
      AC1Legacy::PStringBase<char>::set(&ret, "Void Magic");
      break;
    case 1u:
      AC1Legacy::PStringBase<char>::set(&ret, "War Magic");
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(&ret, "Life Magic");
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(&ret, "Item Enchantment");
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(&ret, "Creature Enchantment");
      break;
    default:
      AC1Legacy::PStringBase<char>::set(&ret, "None");
      break;
  }
  v2 = ret.m_buffer;
  v3 = (volatile LONG *)&ret.m_buffer->m_cRef;
  v4 = (volatile LONG *)&ret.m_buffer->m_cRef;
  result->m_buffer = ret.m_buffer;
  InterlockedIncrement(v4);
  if ( !InterlockedDecrement(v3) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005974A0) --------------------------------------------------------  // acclient.c:449225
BOOL __thiscall CSpellBase::IsUntargeted(CSpellBase *this)
{
  SpellFormula result; // [sp+0h] [bp-24h]@1

  CSpellBase::InqSpellFormula(this, &result);
  return SpellFormula::GetTargetingType(&result) == 0;
}

//----- (0070AD40) --------------------------------------------------------  // acclient.c:798032
int sub_70AD40()
{
  return atexit(nullsub_1424);
}

