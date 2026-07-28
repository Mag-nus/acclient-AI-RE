/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CharGenState
   Object     : AC\accharacter\CharGenState.obj
   Functions  : 77
   Addresses  : 00487880 - 0070F580 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00487880) --------------------------------------------------------  // acclient.c:195266
void __thiscall List<SkillRecord *>::flush(List<SkillRecord *> *this)
{
  List<SkillRecord *> *i; // esi@1
  ListNode<SkillRecord *> *v2; // ecx@2
  ListNode<SkillRecord *> *v3; // eax@3

  for ( i = this; ; --i->_num_elements )
  {
    v2 = i->_head;
    if ( !v2 )
      break;
    v3 = v2->next;
    i->_head = v3;
    if ( v3 )
      v3->prev = 0;
    else
      i->_tail = 0;
    if ( v2 )
      operator delete(v2);
  }
}

//----- (005C37A0) --------------------------------------------------------  // acclient.c:495057
void __thiscall CharGenState::SetVerificationState(CharGenState *this, CG_VERIFICATION_RESPONSE _verificationState)
{
  this->verificationState = _verificationState;
}

//----- (005C37B0) --------------------------------------------------------  // acclient.c:495063
CG_VERIFICATION_RESPONSE __thiscall CharGenState::GetVerificationState(CharGenState *this)
{
  return this->verificationState;
}

//----- (005C37C0) --------------------------------------------------------  // acclient.c:495069
void __thiscall CharGenState::UpdateRemainingSkillCredits(CharGenState *this)
{
  CharGenState *v1; // esi@1
  int v2; // edi@1
  int v3; // ebx@1
  int v4; // eax@4

  v1 = this;
  v2 = 1;
  v3 = 0;
  if ( this->totalNumSkills > 1u )
  {
    while ( v1->skillLevels[v2] != 2 )
    {
      if ( v1->skillLevels[v2] == 3 )
      {
        v4 = ACCharGenData::GetSkillSpecializedCost(v1->charGenData, v2, v1->mHeritageGroup, v1->mGender);
LABEL_6:
        v3 += v4;
      }
      ++v2;
      if ( (unsigned int)v2 >= v1->totalNumSkills )
        goto LABEL_8;
    }
    v4 = ACCharGenData::GetSkillTrainedCost(v1->charGenData, v2, v1->mHeritageGroup, v1->mGender);
    goto LABEL_6;
  }
LABEL_8:
  v1->remainingSkillCredits = v1->totalSkillCredits - v3;
}

//----- (005C3850) --------------------------------------------------------  // acclient.c:495101
long double __thiscall CharGenState::SetSkinShade(CharGenState *this, long double _skinShade)
{
  CharGenState *v2; // esi@1
  CharGenStateVtbl *v3; // edx@1

  v2 = this;
  v3 = this->vfptr;
  this->skinShade = _skinShade;
  ((void (*)(void))v3->UpdateTrueFacePal)();
  return v2->skinShade;
}

//----- (005C3880) --------------------------------------------------------  // acclient.c:495114
long double __thiscall CharGenState::SetHairShade(CharGenState *this, long double _hairShade)
{
  CharGenState *v2; // esi@1
  CharGenStateVtbl *v3; // edx@1

  v2 = this;
  v3 = this->vfptr;
  this->hairShade = _hairShade;
  ((void (*)(void))v3->UpdateTrueFacePal)();
  return v2->hairShade;
}

//----- (005C38B0) --------------------------------------------------------  // acclient.c:495127
int __thiscall CharGenState::SetHairColor(CharGenState *this, int _hairColor)
{
  CharGenState *v2; // esi@1
  CharGenStateVtbl *v3; // edx@1

  v2 = this;
  v3 = this->vfptr;
  this->hairColor = _hairColor;
  ((void (*)(void))v3->UpdateTrueFacePal)();
  return v2->hairColor;
}

//----- (005C38D0) --------------------------------------------------------  // acclient.c:495140
int __thiscall CharGenState::SetEyeColor(CharGenState *this, int _eyeColor)
{
  CharGenState *v2; // esi@1
  CharGenStateVtbl *v3; // edx@1

  v2 = this;
  v3 = this->vfptr;
  this->eyeColor = _eyeColor;
  ((void (*)(void))v3->UpdateTrueFacePal)();
  return v2->eyeColor;
}

//----- (005C38F0) --------------------------------------------------------  // acclient.c:495153
unsigned int __thiscall CharGenState::GetHeadgearPaletteTemplateID(CharGenState *this, int _num)
{
  unsigned int result; // eax@3

  if ( _num >= this->numHeadgearColors || _num < 0 )
    result = 0;
  else
    result = this->headgearPaletteTemplateIDs[_num];
  return result;
}

//----- (005C3920) --------------------------------------------------------  // acclient.c:495165
unsigned int __thiscall CharGenState::GetShirtPaletteTemplateID(CharGenState *this, int _num)
{
  unsigned int result; // eax@3

  if ( _num >= this->numShirtColors || _num < 0 )
    result = 0;
  else
    result = this->shirtPaletteTemplateIDs[_num];
  return result;
}

//----- (005C3950) --------------------------------------------------------  // acclient.c:495177
unsigned int __thiscall CharGenState::GetTrousersPaletteTemplateID(CharGenState *this, int _num)
{
  unsigned int result; // eax@3

  if ( _num >= this->numTrousersColors || _num < 0 )
    result = 0;
  else
    result = this->trousersPaletteTemplateIDs[_num];
  return result;
}

//----- (005C3980) --------------------------------------------------------  // acclient.c:495189
unsigned int __thiscall CharGenState::GetFootwearPaletteTemplateID(CharGenState *this, int _num)
{
  unsigned int result; // eax@3

  if ( _num >= this->numFootwearColors || _num < 0 )
    result = 0;
  else
    result = this->footwearPaletteTemplateIDs[_num];
  return result;
}

//----- (005C39B0) --------------------------------------------------------  // acclient.c:495201
int __thiscall CharGenState::GetAttribute(CharGenState *this, unsigned int _attr)
{
  int result; // eax@2

  switch ( _attr )
  {
    case 1u:
      result = this->strength;
      break;
    case 2u:
      result = this->endurance;
      break;
    case 3u:
      result = this->quickness;
      break;
    case 4u:
      result = this->coordination;
      break;
    case 5u:
      result = this->focus;
      break;
    case 6u:
      result = this->self;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C3A20) --------------------------------------------------------  // acclient.c:495233
void __stdcall CharGenState::GetAttributeName(unsigned int _attr, char *o_string)
{
  switch ( _attr )
  {
    case 1u:
      *(_DWORD *)o_string = *(_DWORD *)"Strength";
      *((_DWORD *)o_string + 1) = 1752459118;
      o_string[8] = 0;
      break;
    case 2u:
      *(_DWORD *)o_string = *(_DWORD *)"Endurance";
      *((_DWORD *)o_string + 1) = 1668178290;
      *((_WORD *)o_string + 4) = 101;
      break;
    case 3u:
      *(_DWORD *)o_string = *(_DWORD *)"Quickness";
      *((_DWORD *)o_string + 1) = 1936027243;
      *((_WORD *)o_string + 4) = 115;
      break;
    case 4u:
      *(_DWORD *)o_string = *(_DWORD *)"Coordination";
      *((_DWORD *)o_string + 1) = 1634625892;
      *((_DWORD *)o_string + 2) = 1852795252;
      o_string[12] = 0;
      break;
    case 5u:
      *(_DWORD *)o_string = *(_DWORD *)"Focus";
      *((_WORD *)o_string + 2) = 115;
      break;
    case 6u:
      *(_DWORD *)o_string = *(_DWORD *)"Self";
      o_string[4] = 0;
      break;
    default:
      *o_string = 0;
      break;
  }
}

//----- (005C3B20) --------------------------------------------------------  // acclient.c:495273
int __thiscall CharGenState::GetAbsRemainingCredits(CharGenState *this, unsigned int _curAtrb)
{
  int result; // eax@1
  signed int v3; // esi@1
  char *v4; // ebx@1
  int v5; // edx@2

  result = this->totalAtrbCredits;
  v3 = 1;
  v4 = (char *)&this->bAttribLocked[1];
  do
  {
    v5 = 10;
    if ( *(_DWORD *)v4 == 1 || v3 == _curAtrb )
    {
      switch ( v3 )
      {
        case 1:
          v5 = this->strength;
          break;
        case 2:
          v5 = this->endurance;
          break;
        case 3:
          v5 = this->quickness;
          break;
        case 4:
          v5 = this->coordination;
          break;
        case 5:
          v5 = this->focus;
          break;
        case 6:
          v5 = this->self;
          break;
        default:
          break;
      }
    }
    result -= v5;
    ++v3;
    v4 += 4;
  }
  while ( (unsigned int)v3 < 7 );
  return result;
}

//----- (005C3BC0) --------------------------------------------------------  // acclient.c:495321
void __thiscall CharGenState::ResetAttributeLock(CharGenState *this)
{
  memset(&this->bAttribLocked[1], 0, 0x18u);
}

//----- (005C3BE0) --------------------------------------------------------  // acclient.c:495327
void __thiscall CharGenState::LockAttribute(CharGenState *this, unsigned int _attr, int _lock)
{
  if ( _attr )
  {
    if ( _attr < 7 )
      this->bAttribLocked[_attr] = _lock;
  }
}

//----- (005C3C00) --------------------------------------------------------  // acclient.c:495337
SKILL_ADVANCEMENT_CLASS __thiscall CharGenState::GetSkillLevel(CharGenState *this, unsigned int skill)
{
  SKILL_ADVANCEMENT_CLASS result; // eax@2

  if ( skill >= this->totalNumSkills )
    result = 0;
  else
    result = this->skillLevels[skill];
  return result;
}

//----- (005C3C20) --------------------------------------------------------  // acclient.c:495349
int __thiscall CharGenState::SetSkillLevel(CharGenState *this, unsigned int _skillNum, SKILL_ADVANCEMENT_CLASS _skillLevel)
{
  CharGenState *v3; // esi@1
  SKILL_ADVANCEMENT_CLASS v4; // eax@4
  int v5; // edi@4
  int v6; // eax@5
  int v7; // eax@10
  SKILL_ADVANCEMENT_CLASS *v8; // ecx@15

  v3 = this;
  if ( _skillNum >= this->totalNumSkills || (signed int)_skillLevel >= 4 || (signed int)_skillLevel < 1 )
    return 0;
  v4 = this->skillLevels[_skillNum];
  v5 = this->remainingSkillCredits;
  if ( v4 == 2 )
  {
    v6 = ACCharGenData::GetSkillTrainedCost(this->charGenData, _skillNum, this->mHeritageGroup, this->mGender);
  }
  else
  {
    if ( v4 != 3 )
      goto LABEL_9;
    v6 = ACCharGenData::GetSkillSpecializedCost(this->charGenData, _skillNum, this->mHeritageGroup, this->mGender);
  }
  v5 += v6;
LABEL_9:
  if ( _skillLevel == 2 )
  {
    v7 = ACCharGenData::GetSkillTrainedCost(v3->charGenData, _skillNum, v3->mHeritageGroup, v3->mGender);
  }
  else
  {
    if ( _skillLevel != 3 )
      goto LABEL_14;
    v7 = ACCharGenData::GetSkillSpecializedCost(v3->charGenData, _skillNum, v3->mHeritageGroup, v3->mGender);
  }
  v5 -= v7;
LABEL_14:
  if ( v5 >= 0 )
  {
    v8 = v3->skillLevels;
    v3->remainingSkillCredits = v5;
    v8[_skillNum] = _skillLevel;
    return 1;
  }
  return 0;
}

//----- (005C3D10) --------------------------------------------------------  // acclient.c:495398
void __thiscall CharGenState::SetName(CharGenState *this, const char *_name)
{
  const char *v2; // eax@1
  char *v3; // esi@2
  signed int v4; // edx@2
  const char v5; // cl@3

  v2 = _name;
  if ( strlen(_name) <= 0x20 )
  {
    v3 = this->name;
    v4 = this->name - _name;
    do
    {
      v5 = *v2;
      v2[v4] = *v2;
      ++v2;
    }
    while ( v5 );
    ACCharGenData::FormatName(v3);
  }
}

//----- (005C3D60) --------------------------------------------------------  // acclient.c:495422
void __thiscall CharGenState::SetSlot(CharGenState *this, int _slot)
{
  this->slot = _slot;
}

//----- (005C3D70) --------------------------------------------------------  // acclient.c:495428
IDClass<_tagDataID,32,0> *__thiscall CharGenState::GetHeadgearPalSetID(CharGenState *this, IDClass<_tagDataID,32,0> *result, int _num)
{
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v3 = result;
  result->id = this->headgearPalSetIDs[_num].id;
  return v3;
}

//----- (005C3D90) --------------------------------------------------------  // acclient.c:495438
IDClass<_tagDataID,32,0> *__thiscall CharGenState::GetShirtPalSetID(CharGenState *this, IDClass<_tagDataID,32,0> *result, int _num)
{
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v3 = result;
  result->id = this->shirtPalSetIDs[_num].id;
  return v3;
}

//----- (005C3DB0) --------------------------------------------------------  // acclient.c:495448
IDClass<_tagDataID,32,0> *__thiscall CharGenState::GetTrousersPalSetID(CharGenState *this, IDClass<_tagDataID,32,0> *result, int _num)
{
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v3 = result;
  result->id = this->trousersPalSetIDs[_num].id;
  return v3;
}

//----- (005C3DD0) --------------------------------------------------------  // acclient.c:495458
IDClass<_tagDataID,32,0> *__thiscall CharGenState::GetFootwearPalSetID(CharGenState *this, IDClass<_tagDataID,32,0> *result, int _num)
{
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v3 = result;
  result->id = this->footwearPalSetIDs[_num].id;
  return v3;
}

//----- (005C3DF0) --------------------------------------------------------  // acclient.c:495468
void __thiscall CharGenState::BalanceAttributes(CharGenState *this, unsigned int _fixedAtrb)
{
  int v2; // eax@1
  signed int v3; // esi@2
  int v4; // edx@6
  int v5; // edx@12
  int v6; // edx@18
  int v7; // edx@24
  int v8; // edx@30
  int v9; // edx@36

  v2 = this->self
     + this->strength
     + this->endurance
     + this->coordination
     + this->quickness
     + this->focus
     - this->totalAtrbCredits;
  if ( v2 > 0 )
  {
    v3 = 0;
    while ( 1 )
    {
      if ( v3 || startAtrb == 1 )
      {
        v3 = 1;
        if ( _fixedAtrb != 1 )
        {
          v4 = this->strength;
          if ( v4 > 10 && !this->bAttribLocked[1] )
          {
            --v2;
            this->strength = v4 - 1;
            if ( v2 <= 0 )
            {
              startAtrb = 2;
              return;
            }
          }
        }
      }
      if ( v3 || startAtrb == 2 )
      {
        v3 = 1;
        if ( _fixedAtrb != 2 )
        {
          v5 = this->endurance;
          if ( v5 > 10 && !this->bAttribLocked[2] )
          {
            --v2;
            this->endurance = v5 - 1;
            if ( v2 <= 0 )
            {
              startAtrb = 4;
              return;
            }
          }
        }
      }
      if ( v3 || startAtrb == 4 )
      {
        v3 = 1;
        if ( _fixedAtrb != 4 )
        {
          v6 = this->coordination;
          if ( v6 > 10 && !this->bAttribLocked[4] )
          {
            --v2;
            this->coordination = v6 - 1;
            if ( v2 <= 0 )
            {
              startAtrb = 3;
              return;
            }
          }
        }
      }
      if ( v3 || startAtrb == 3 )
      {
        v3 = 1;
        if ( _fixedAtrb != 3 )
        {
          v7 = this->quickness;
          if ( v7 > 10 && !this->bAttribLocked[3] )
          {
            --v2;
            this->quickness = v7 - 1;
            if ( v2 <= 0 )
            {
              startAtrb = 5;
              return;
            }
          }
        }
      }
      if ( v3 || startAtrb == 5 )
      {
        v3 = 1;
        if ( _fixedAtrb != 5 )
        {
          v8 = this->focus;
          if ( v8 > 10 && !this->bAttribLocked[5] )
          {
            --v2;
            this->focus = v8 - 1;
            if ( v2 <= 0 )
              break;
          }
        }
      }
      if ( v3 || startAtrb == 6 )
      {
        v3 = 1;
        if ( _fixedAtrb != 6 )
        {
          v9 = this->self;
          if ( v9 > 10 && !this->bAttribLocked[6] )
          {
            --v2;
            this->self = v9 - 1;
            if ( v2 <= 0 )
            {
              startAtrb = 1;
              return;
            }
          }
        }
      }
    }
    startAtrb = 6;
  }
}

//----- (005C4000) --------------------------------------------------------  // acclient.c:495602
void __thiscall CharGenState::SetStartArea(CharGenState *this, int _startArea)
{
  if ( _startArea < 0 || _startArea >= (signed int)this->charGenData->mStartAreaList.m_num )
    this->startArea = -1;
  else
    this->startArea = _startArea;
}

//----- (005C4030) --------------------------------------------------------  // acclient.c:495611
int __thiscall CharGenState::GetCharGenResult(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // edx@1
  int v5; // eax@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // ecx@1
  int v9; // edx@1
  int v10; // eax@1
  bool v11; // sf@1
  unsigned __int8 v12; // of@1
  unsigned int v13; // eax@3
  long double v14; // st7@5
  int v15; // ecx@5
  int v16; // edx@5
  int v17; // eax@5
  unsigned int v18; // eax@7
  long double v19; // st7@9
  int v20; // ecx@9
  int v21; // edx@9
  int v22; // eax@9
  unsigned int v23; // eax@11
  long double v24; // st7@13
  int v25; // ecx@13
  int v26; // edx@13
  int v27; // eax@13
  unsigned int v28; // eax@15
  long double v29; // st7@17
  int v30; // edx@17
  int v31; // ecx@17
  int v32; // eax@17
  long double v33; // st7@17
  int v34; // eax@17
  int v35; // edx@17
  long double v36; // st7@17
  void *v37; // eax@17
  int v38; // ecx@17
  int v39; // edx@17
  int v40; // eax@19
  void *v41; // eax@20
  int v42; // ecx@20
  unsigned int v43; // eax@20
  AC1Legacy::PSRefBuffer<char> *v44; // edi@22
  int v45; // eax@22
  int v46; // ebx@22
  int v47; // ebx@26
  AC1Legacy::PSRefBuffer<char> *v48; // edi@27
  int v49; // ecx@30
  unsigned int v50; // eax@30
  int v52; // eax@38
  int v53; // eax@41
  int v54; // [sp-Ch] [bp-1Ch]@36
  AC1Legacy::PStringBase<char> v55; // [sp+Ch] [bp-4h]@22

  v1 = this;
  v2 = this->mHeritageGroup;
  v3 = this->mGender;
  v4 = v1->eyesStrip;
  v1->charGenResult.heritageGroup = v2;
  v5 = v1->noseStrip;
  v1->charGenResult.gender = v3;
  v6 = v1->mouthStrip;
  v1->charGenResult.noseStrip = v5;
  v7 = v1->eyeColor;
  v1->charGenResult.mouthStrip = v6;
  v8 = v1->hairStyle;
  v1->charGenResult.eyesStrip = v4;
  v9 = v1->hairColor;
  v1->charGenResult.eyeColor = v7;
  v10 = v1->headgearColor;
  v1->charGenResult.hairStyle = v8;
  v12 = __OFSUB__(v10, v1->numHeadgearColors);
  v11 = v10 - v1->numHeadgearColors < 0;
  v1->charGenResult.hairColor = v9;
  v1->charGenResult.headgearStyle = v1->headgearStyle;
  if ( v11 ^ v12 && v10 >= 0 )
    v13 = v1->headgearPaletteTemplateIDs[v10];
  else
    v13 = 0;
  v14 = v1->headgearShade;
  v15 = v1->numShirtColors;
  v16 = v1->shirtStyle;
  v1->charGenResult.headgearColor = v13;
  v17 = v1->shirtColor;
  v1->charGenResult.headgearShade = v14;
  v1->charGenResult.shirtStyle = v16;
  if ( v17 >= v15 || v17 < 0 )
    v18 = 0;
  else
    v18 = v1->shirtPaletteTemplateIDs[v17];
  v19 = v1->shirtShade;
  v20 = v1->numTrousersColors;
  v21 = v1->trousersStyle;
  v1->charGenResult.shirtColor = v18;
  v22 = v1->trousersColor;
  v1->charGenResult.shirtShade = v19;
  v1->charGenResult.trousersStyle = v21;
  if ( v22 >= v20 || v22 < 0 )
    v23 = 0;
  else
    v23 = v1->trousersPaletteTemplateIDs[v22];
  v24 = v1->trousersShade;
  v25 = v1->numFootwearColors;
  v26 = v1->footwearStyle;
  v1->charGenResult.trousersColor = v23;
  v27 = v1->footwearColor;
  v1->charGenResult.trousersShade = v24;
  v1->charGenResult.footwearStyle = v26;
  if ( v27 >= v25 || v27 < 0 )
    v28 = 0;
  else
    v28 = v1->footwearPaletteTemplateIDs[v27];
  v29 = v1->footwearShade;
  v30 = v1->template_;
  v31 = v1->endurance;
  v1->charGenResult.footwearColor = v28;
  v32 = v1->strength;
  v1->charGenResult.footwearShade = v29;
  v33 = v1->skinShade;
  v1->charGenResult.strength = v32;
  v34 = v1->quickness;
  v1->charGenResult.templateNum = v30;
  v35 = v1->coordination;
  v1->charGenResult.skinShade = v33;
  v36 = v1->hairShade;
  v1->charGenResult.quickness = v34;
  v37 = v1->charGenResult.skillAdvancementClasses;
  v1->charGenResult.endurance = v31;
  v38 = v1->focus;
  v1->charGenResult.coordination = v35;
  v39 = v1->self;
  v1->charGenResult.hairShade = v36;
  v1->charGenResult.focus = v38;
  v1->charGenResult.self = v39;
  if ( v37 )
  {
    operator delete[](v37);
    v1->charGenResult.skillAdvancementClasses = 0;
  }
  v40 = v1->totalNumSkills;
  v1->charGenResult.numSkills = v40;
  if ( v40 > 0 )
  {
    v41 = operator new[](4 * v40);
    v42 = v1->totalNumSkills;
    v1->charGenResult.skillAdvancementClasses = (SKILL_ADVANCEMENT_CLASS *)v41;
    v43 = 0;
    if ( v42 )
    {
      do
      {
        v1->charGenResult.skillAdvancementClasses[v43] = v1->skillLevels[v43];
        ++v43;
      }
      while ( v43 < v1->totalNumSkills );
    }
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v55, v1->name);
  v44 = v1->charGenResult.name.m_buffer;
  v46 = v45;
  if ( v44 != *(AC1Legacy::PSRefBuffer<char> **)v45 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v44->m_cRef) && v44 )
      v44->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v44, 1u);
    v47 = *(_DWORD *)v46;
    v1->charGenResult.name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v47;
    InterlockedIncrement((volatile LONG *)(v47 + 4));
  }
  v48 = v55.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v55.m_buffer->m_cRef) && v48 )
    v48->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v48, 1u);
  v49 = v1->slot;
  v1->charGenResult.startArea = v1->startArea;
  v50 = v1->charGenResult.heritageGroup;
  v1->charGenResult.slot = v49;
  if ( v50 == 12 )
  {
    if ( !v1->createAsAdmin )
    {
      DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v55, 268435600, 12);
      v1->charGenResult.classID.id = (unsigned int)v55.m_buffer;
      return (int)&v1->charGenResult;
    }
    DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v55, 268435602, 12);
    v1->charGenResult.classID.id = (unsigned int)v55.m_buffer;
    goto LABEL_41;
  }
  if ( v50 == 13 )
  {
    if ( !v1->createAsAdmin )
    {
      DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v55, 268435601, 12);
      v1->charGenResult.classID.id = (unsigned int)v55.m_buffer;
      return (int)&v1->charGenResult;
    }
    v54 = 268435603;
    goto LABEL_40;
  }
  DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v55, 268435459, 12);
  v52 = v1->createAsAdmin;
  v1->charGenResult.classID.id = (unsigned int)v55.m_buffer;
  if ( v52 )
  {
    v54 = 268435460;
LABEL_40:
    DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v55, v54, 12);
    v1->charGenResult.classID.id = (unsigned int)v55.m_buffer;
LABEL_41:
    v53 = v1->createAsEnvoy;
    v1->charGenResult.isAdmin = 1;
    if ( v53 )
      v1->charGenResult.isEnvoy = 1;
  }
  return (int)&v1->charGenResult;
}

//----- (005C43B0) --------------------------------------------------------  // acclient.c:495831
void __thiscall CharGenState::ResetSkillLevels(CharGenState *this)
{
  CharGenState *v1; // esi@1
  int v2; // edi@4
  char *v3; // ebp@4
  unsigned int v4; // ebx@5
  int v5; // ecx@6
  int v6; // edx@7
  int v7; // ebx@12
  int v8; // eax@12

  v1 = this;
  this->remainingSkillCredits = this->totalSkillCredits;
  if ( this->skillLevels )
  {
    if ( this->mHeritageGroup )
    {
      if ( this->mGender != -1 )
      {
        v2 = 1;
        v3 = (char *)&this->skillTable->_skillBaseHash;
        if ( this->totalNumSkills > 1 )
        {
          do
          {
            v4 = *((_DWORD *)v3 + 3);
            if ( v4 )
            {
              v5 = *((_DWORD *)v3 + 2);
              if ( v5 )
              {
                v6 = *(_DWORD *)(v5 + 4 * (v2 % v4));
                if ( v6 )
                {
                  while ( v2 != *(_DWORD *)v6 )
                  {
                    v6 = *(_DWORD *)(v6 + 96);
                    if ( !v6 )
                      goto LABEL_19;
                  }
                  if ( v6 != -8 )
                  {
                    v7 = ACCharGenData::GetSkillTrainedCost(v1->charGenData, v2, v1->mHeritageGroup, v1->mGender);
                    v8 = ACCharGenData::GetSkillSpecializedCost(v1->charGenData, v2, v1->mHeritageGroup, v1->mGender);
                    if ( v7 >= 0 && v8 >= 0 )
                    {
                      if ( v7 <= 0 )
                      {
                        if ( v8 <= 0 )
                          v1->skillLevels[v2] = 3;
                        else
                          v1->skillLevels[v2] = 2;
                      }
                      else
                      {
                        v1->skillLevels[v2] = 1;
                      }
                    }
                  }
                }
              }
            }
LABEL_19:
            ++v2;
          }
          while ( v2 < v1->totalNumSkills );
        }
      }
    }
  }
}

//----- (005C44D0) --------------------------------------------------------  // acclient.c:495904
void __stdcall CharGenState::StoreColorInformation(IDClass<_tagDataID,32,0> _clothingTableID, int *_numColors, unsigned int **_paletteTemplateIDs, IDClass<_tagDataID,32,0> **_palSetIDs, Sex_CG *_curSX)
{
  int *v6; // ebp@1
  QualifiedDataID *v7; // eax@5
  int v8; // eax@5
  int v9; // esi@6
  PackableHashTable<unsigned long,CloPaletteTemplate> *v10; // ebx@6
  void *v11; // eax@7
  IDClass<_tagDataID,32,0> *v12; // edi@8
  PackableHashData<unsigned long,CloPaletteTemplate> *v13; // esi@11
  PackableHashData<unsigned long,CloPaletteTemplate> **v14; // ebx@12
  unsigned int v15; // ecx@14
  unsigned int v16; // edi@14
  unsigned int v17; // eax@14
  unsigned int *v18; // edx@15
  CloSubpalEffect *v19; // eax@20
  PackableHashData<unsigned long,CloPaletteTemplate> *v20; // eax@21
  unsigned int v21; // eax@22
  QualifiedDataID v22; // [sp+8h] [bp-28h]@5
  CloPaletteTemplate cpt; // [sp+10h] [bp-20h]@11
  PackableHashIterator<unsigned long,CloPaletteTemplate> cpt_iter; // [sp+20h] [bp-10h]@11
  int *_numColorsa; // [sp+38h] [bp+8h]@5

  v6 = _numColors;
  *_numColors = 0;
  if ( *_paletteTemplateIDs )
    operator delete[](*_paletteTemplateIDs);
  *_paletteTemplateIDs = 0;
  if ( *_palSetIDs )
    operator delete[](&(*_palSetIDs)[-1]);
  *_palSetIDs = 0;
  QualifiedDataID::QualifiedDataID(&v22, _clothingTableID, 0x19u);
  v8 = DBObj::Get(v7);
  _numColorsa = (int *)v8;
  if ( v8 )
  {
    v9 = *(_DWORD *)(v8 + 92);
    v10 = (PackableHashTable<unsigned long,CloPaletteTemplate> *)(v8 + 76);
    if ( v9 > 0 )
    {
      *_paletteTemplateIDs = (unsigned int *)operator new[](4 * v9);
      v11 = operator new[](4 * v9 + 4);
      if ( v11 )
      {
        v12 = (IDClass<_tagDataID,32,0> *)((char *)v11 + 4);
        *(_DWORD *)v11 = v9;
        vector_constructor_iterator(
          (char *)v11 + 4,
          4u,
          v9,
          (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      }
      else
      {
        v12 = 0;
      }
      *_palSetIDs = v12;
    }
    PackableHashTable<unsigned long,CloPaletteTemplate>::begin(v10, &cpt_iter);
    CloPaletteTemplate::CloPaletteTemplate(&cpt);
    v13 = cpt_iter._current;
    if ( cpt_iter._current )
    {
      v14 = cpt_iter._buckets;
      do
      {
        CloPaletteTemplate::operator=((int)&cpt, (int)&v13->_data);
        if ( cpt.numSubpalEffects )
        {
          v15 = _curSX->mClothingColorsList.m_num;
          v16 = v13->_key;
          v17 = 0;
          if ( v15 )
          {
            v18 = _curSX->mClothingColorsList.m_data;
            while ( *v18 != v16 )
            {
              ++v17;
              ++v18;
              if ( v17 >= v15 )
                goto LABEL_21;
            }
            if ( v17 != -1 )
            {
              v19 = cpt.subpalEffects;
              (*_paletteTemplateIDs)[*v6] = v16;
              (*_palSetIDs)[(*v6)++].id = v19->palSet.id;
            }
          }
        }
LABEL_21:
        v20 = v13->_next;
        if ( !v20 )
        {
          v21 = v13->_hashVal + 1;
          if ( v21 >= cpt_iter._table_size )
          {
LABEL_25:
            v20 = 0;
          }
          else
          {
            while ( !v14[v21] )
            {
              ++v21;
              if ( v21 >= cpt_iter._table_size )
                goto LABEL_25;
            }
            v20 = v14[v21];
          }
        }
        v13 = v20;
      }
      while ( v20 );
    }
    (*(void (**)(void))(*_numColorsa + 20))();
    CloPaletteTemplate::~CloPaletteTemplate(&cpt);
  }
}

//----- (005C4660) --------------------------------------------------------  // acclient.c:496025
int __thiscall CharGenState::SetStrength(CharGenState *this, int _strength, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->strength;
  if ( _strength <= v3 || CharGenState::GetAbsRemainingCredits(this, 1u) )
  {
    this->strength = _strength;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 1u);
    result = this->strength;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->self
                               - this->focus
                               - this->quickness
                               - this->coordination
                               - this->endurance
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C46E0) --------------------------------------------------------  // acclient.c:496053
int __thiscall CharGenState::SetEndurance(CharGenState *this, int _endurance, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->endurance;
  if ( _endurance <= v3 || CharGenState::GetAbsRemainingCredits(this, 2u) )
  {
    this->endurance = _endurance;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 2u);
    result = this->endurance;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->self
                               - this->focus
                               - this->quickness
                               - this->coordination
                               - this->strength
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C4760) --------------------------------------------------------  // acclient.c:496081
int __thiscall CharGenState::SetCoordination(CharGenState *this, int _coordination, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->coordination;
  if ( _coordination <= v3 || CharGenState::GetAbsRemainingCredits(this, 4u) )
  {
    this->coordination = _coordination;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 4u);
    result = this->coordination;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->self
                               - this->focus
                               - this->quickness
                               - this->endurance
                               - this->strength
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C47E0) --------------------------------------------------------  // acclient.c:496109
int __thiscall CharGenState::SetQuickness(CharGenState *this, int _quickness, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->quickness;
  if ( _quickness <= v3 || CharGenState::GetAbsRemainingCredits(this, 3u) )
  {
    this->quickness = _quickness;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 3u);
    result = this->quickness;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->self
                               - this->focus
                               - this->coordination
                               - this->endurance
                               - this->strength
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C4860) --------------------------------------------------------  // acclient.c:496137
int __thiscall CharGenState::SetFocus(CharGenState *this, int _focus, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->focus;
  if ( _focus <= v3 || CharGenState::GetAbsRemainingCredits(this, 5u) )
  {
    this->focus = _focus;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 5u);
    result = this->focus;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->self
                               - this->quickness
                               - this->coordination
                               - this->endurance
                               - this->strength
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C48E0) --------------------------------------------------------  // acclient.c:496165
int __thiscall CharGenState::SetSelf(CharGenState *this, int _self, int _balance)
{
  int v3; // esi@1
  int result; // eax@3

  v3 = this->self;
  if ( _self <= v3 || CharGenState::GetAbsRemainingCredits(this, 6u) )
  {
    this->self = _self;
    if ( _balance )
      CharGenState::BalanceAttributes(this, 6u);
    result = this->self;
    this->remainingAtrbCredits = this->totalAtrbCredits
                               - this->focus
                               - this->quickness
                               - this->coordination
                               - this->endurance
                               - this->strength
                               - result;
  }
  else
  {
    result = v3;
  }
  return result;
}

//----- (005C4960) --------------------------------------------------------  // acclient.c:496193
ListNode<SkillRecord *> *__thiscall List<SkillRecord *>::get_node(List<SkillRecord *> *this, unsigned int pos)
{
  ListNode<SkillRecord *> *result; // eax@1
  int v3; // ecx@3

  result = this->_head;
  if ( result && pos < this->_num_elements )
  {
    v3 = 0;
    while ( v3 != pos )
    {
      if ( result )
        result = result->next;
      ++v3;
      if ( !result )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}

//----- (005C4990) --------------------------------------------------------  // acclient.c:496220
void __thiscall CharGenState::ApplyDefaultTemplate(CharGenState *this)
{
  int v1; // eax@3
  int v2; // edx@6
  int v3; // eax@9
  int v4; // edx@12
  int v5; // eax@15
  int v6; // edx@18

  if ( this->strength >= 50 || CharGenState::GetAbsRemainingCredits(this, 1u) )
  {
    v1 = this->totalAtrbCredits - this->self - this->focus - this->quickness - this->coordination - this->endurance - 50;
    this->strength = 50;
    this->remainingAtrbCredits = v1;
  }
  if ( this->endurance >= 50 || CharGenState::GetAbsRemainingCredits(this, 2u) )
  {
    v2 = this->totalAtrbCredits - this->self - this->focus - this->quickness - this->coordination - this->strength - 50;
    this->endurance = 50;
    this->remainingAtrbCredits = v2;
  }
  if ( this->coordination >= 50 || CharGenState::GetAbsRemainingCredits(this, 4u) )
  {
    v3 = this->totalAtrbCredits - this->self - this->focus - this->quickness - this->endurance - this->strength - 50;
    this->coordination = 50;
    this->remainingAtrbCredits = v3;
  }
  if ( this->quickness >= 50 || CharGenState::GetAbsRemainingCredits(this, 3u) )
  {
    v4 = this->totalAtrbCredits - this->self - this->focus - this->coordination - this->endurance - this->strength - 50;
    this->quickness = 50;
    this->remainingAtrbCredits = v4;
  }
  if ( this->focus >= 50 || CharGenState::GetAbsRemainingCredits(this, 5u) )
  {
    v5 = this->totalAtrbCredits
       - this->self
       - this->quickness
       - this->coordination
       - this->endurance
       - this->strength
       - 50;
    this->focus = 50;
    this->remainingAtrbCredits = v5;
  }
  if ( this->self >= 50 || CharGenState::GetAbsRemainingCredits(this, 6u) )
  {
    v6 = this->totalAtrbCredits
       - this->focus
       - this->quickness
       - this->coordination
       - this->endurance
       - this->strength
       - 50;
    this->self = 50;
    this->remainingAtrbCredits = v6;
  }
  CharGenState::ResetSkillLevels(this);
}

//----- (005C4B50) --------------------------------------------------------  // acclient.c:496281
unsigned int __thiscall CharGenState::GetSkillScore(CharGenState *this, unsigned int skill)
{
  CharGenState *v2; // esi@1
  bool v3; // cf@2
  SKILL_ADVANCEMENT_CLASS v4; // edi@3
  unsigned int v5; // ST04_4@6
  unsigned int v6; // edx@6
  CharGenState *v7; // ecx@6
  unsigned int v8; // eax@6
  unsigned int v9; // eax@8
  unsigned int score; // [sp+8h] [bp-78h]@6
  SkillFormula formula; // [sp+Ch] [bp-74h]@2
  SkillBase sbase; // [sp+28h] [bp-58h]@1

  v2 = this;
  SkillBase::SkillBase(&sbase);
  if ( SkillTable::InqSkillBase(v2->skillTable, skill, &sbase) )
  {
    formula._w = sbase._formula._w;
    formula._z = sbase._formula._z;
    v3 = skill < v2->totalNumSkills;
    formula._x = sbase._formula._x;
    formula._y = sbase._formula._y;
    formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
    formula._attr1 = sbase._formula._attr1;
    formula._attr2 = sbase._formula._attr2;
    v4 = v3 ? v2->skillLevels[skill] : 0;
    if ( v4 >= sbase._min_level )
    {
      score = 0;
      v5 = CharGenState::GetAttribute(v2, sbase._formula._attr2);
      v8 = CharGenState::GetAttribute(v7, v6);
      if ( SkillFormula::Calculate(&formula, v8, v5, &score) )
      {
        if ( v4 == 2 )
        {
          v9 = score + 5;
        }
        else
        {
          if ( v4 != 3 )
          {
LABEL_12:
            SkillBase::~SkillBase(&sbase);
            return score;
          }
          v9 = score + 10;
        }
        score = v9;
        goto LABEL_12;
      }
    }
  }
  SkillBase::~SkillBase(&sbase);
  return 0;
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);

//----- (005C4C50) --------------------------------------------------------  // acclient.c:496340
bool __thiscall List<SkillRecord *>::push(List<SkillRecord *> *this, unsigned int pos, SkillRecord *const *val)
{
  List<SkillRecord *> *v3; // esi@1
  bool result; // al@2
  void *v5; // eax@3
  void *v6; // edi@3
  unsigned int v7; // eax@6
  ListNode<SkillRecord *> *v8; // eax@8
  ListNode<SkillRecord *> *v9; // eax@9
  unsigned int v10; // eax@9
  ListNode<SkillRecord *> *v11; // ecx@10
  ListNode<SkillRecord *> *v12; // edx@13

  v3 = this;
  if ( pos > this->_num_elements )
    return 0;
  v5 = operator new(0xCu);
  v6 = v5;
  if ( !v5 )
    return 0;
  *(_DWORD *)v5 = *val;
  *((_DWORD *)v5 + 1) = 0;
  *((_DWORD *)v5 + 2) = 0;
  if ( !v3->_head )
  {
    if ( !pos )
    {
      v7 = v3->_num_elements;
      v3->_head = (ListNode<SkillRecord *> *)v6;
      v3->_tail = (ListNode<SkillRecord *> *)v6;
      v3->_num_elements = v7 + 1;
      return 1;
    }
    return 0;
  }
  v8 = List<SkillRecord *>::get_node(v3, pos);
  if ( v8 )
  {
    v11 = v8->prev;
    if ( v11 )
      v11->next = (ListNode<SkillRecord *> *)v6;
    else
      v3->_head = (ListNode<SkillRecord *> *)v6;
    v12 = v8->prev;
    *((_DWORD *)v6 + 1) = v8;
    *((_DWORD *)v6 + 2) = v12;
    v8->prev = (ListNode<SkillRecord *> *)v6;
    ++v3->_num_elements;
    result = 1;
  }
  else
  {
    v9 = v3->_tail;
    v9->next = (ListNode<SkillRecord *> *)v6;
    *((_DWORD *)v6 + 2) = v9;
    v10 = v3->_num_elements;
    v3->_tail = (ListNode<SkillRecord *> *)v6;
    v3->_num_elements = v10 + 1;
    result = 1;
  }
  return result;
}

//----- (005C4D10) --------------------------------------------------------  // acclient.c:496404
void __thiscall Template_CG::Template_CG(Template_CG *this, Template_CG *__that)
{
  Template_CG *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@1
  int v5; // ecx@1

  v2 = this;
  this->vfptr = (Template_CGVtbl *)&Template_CG::vftable;
  v3 = __that->name.m_charbuffer;
  this->name.m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v2->iconImage.id = __that->iconImage.id;
  v2->titleID = __that->titleID;
  v2->strength = __that->strength;
  v2->endurance = __that->endurance;
  v2->coordination = __that->coordination;
  v2->quickness = __that->quickness;
  v2->focus = __that->focus;
  v2->self = __that->self;
  v4 = (int)&v2->mNormalSkillsList;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)&v2->mNormalSkillsList, (int)&__that->mNormalSkillsList);
  v5 = (int)&v2->mPrimarySkillsList;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)&v2->mPrimarySkillsList, (int)&__that->mPrimarySkillsList);
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (005C4DA0) --------------------------------------------------------  // acclient.c:496438
List<SkillRecord *> *__thiscall List<SkillRecord *>::scalar_deleting_destructor(List<SkillRecord *> *this, unsigned int a2)
{
  List<SkillRecord *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<SkillRecord *>Vtbl *)&List<SkillRecord *>::vftable;
  List<SkillRecord *>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E77F8: using guessed type int (__thiscall *List<SkillRecord *>::vftable)(void *, char);

//----- (005C4DD0) --------------------------------------------------------  // acclient.c:496452
void __thiscall CharGenState::~CharGenState(CharGenState *this)
{
  CharGenState *v1; // esi@1
  SKILL_ADVANCEMENT_CLASS *v2; // eax@1
  ListNode<SkillRecord *> *v3; // ecx@4
  ListNode<SkillRecord *> *v4; // eax@5
  void *v5; // ebx@8
  IDClass<_tagDataID,32,0> *v6; // eax@17
  IDClass<_tagDataID,32,0> *v7; // eax@19
  IDClass<_tagDataID,32,0> *v8; // eax@21
  IDClass<_tagDataID,32,0> *v9; // eax@23
  ACCharGenData *v10; // ecx@25

  v1 = this;
  v2 = this->skillLevels;
  this->vfptr = (CharGenStateVtbl *)&CharGenState::vftable;
  if ( v2 )
    operator delete[](v2);
  ((void (*)(void))v1->skillTable->vfptr->Release)();
  while ( 1 )
  {
    v3 = v1->skillRecordList._head;
    if ( !v3 )
      break;
    v4 = v3->next;
    v1->skillRecordList._head = v4;
    if ( v4 )
      v4->prev = 0;
    else
      v1->skillRecordList._tail = 0;
    v5 = v3->data;
    operator delete(v3);
    --v1->skillRecordList._num_elements;
    operator delete(v5);
  }
  if ( v1->headgearPaletteTemplateIDs )
    operator delete[](v1->headgearPaletteTemplateIDs);
  if ( v1->shirtPaletteTemplateIDs )
    operator delete[](v1->shirtPaletteTemplateIDs);
  if ( v1->trousersPaletteTemplateIDs )
    operator delete[](v1->trousersPaletteTemplateIDs);
  if ( v1->footwearPaletteTemplateIDs )
    operator delete[](v1->footwearPaletteTemplateIDs);
  v6 = v1->headgearPalSetIDs;
  if ( v6 )
    operator delete[](&v6[-1]);
  v7 = v1->shirtPalSetIDs;
  if ( v7 )
    operator delete[](&v7[-1]);
  v8 = v1->trousersPalSetIDs;
  if ( v8 )
    operator delete[](&v8[-1]);
  v9 = v1->footwearPalSetIDs;
  if ( v9 )
    operator delete[](&v9[-1]);
  v10 = v1->charGenData;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr->Release)();
    v1->charGenData = 0;
  }
  v1->skillRecordList.vfptr = (List<SkillRecord *>Vtbl *)&List<SkillRecord *>::vftable;
  List<SkillRecord *>::flush(&v1->skillRecordList);
  ACCharGenResult::~ACCharGenResult(&v1->charGenResult);
}
// 7E77F8: using guessed type int (__thiscall *List<SkillRecord *>::vftable)(void *, char);
// 7E77FC: using guessed type void (__thiscall *CharGenState::vftable)(gmNoticeHandler *this);

//----- (005C4F10) --------------------------------------------------------  // acclient.c:496521
void __userpurge CharGenState::RandomizeAppearance(CharGenState *this@<ecx>, long double a2@<st0>, int restrict_hair)
{
  CharGenState *v3; // esi@1
  unsigned int v4; // edx@1
  unsigned int v5; // ST28_4@3
  HeritageGroup_CG *v6; // eax@3
  CharGenStateVtbl *v7; // eax@9
  CharGenStateVtbl *v8; // eax@9
  int v9; // eax@10
  CharGenStateVtbl *v10; // edx@10
  int v11; // eax@12
  CharGenStateVtbl *v12; // edx@12
  int v13; // eax@15
  int v14; // [sp+28h] [bp-1A4h]@14
  Sex_CG curSX; // [sp+30h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+10Ch] [bp-C0h]@3

  v3 = this;
  v4 = this->mHeritageGroup;
  if ( v4 && this->mGender )
  {
    v5 = this->mGender;
    v6 = ACCharGenData::GetHG(this->charGenData, &result, v4);
    HeritageGroup_CG::GetSX(v6, &curSX, v5);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( curSX.mEyeStripList.m_num )
      v3->eyesStrip = (*((int (__thiscall **)(CharGenState *, unsigned int, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
                        v3,
                        curSX.mEyeStripList.m_num,
                        v3->eyesStrip);
    if ( curSX.mNoseStripList.m_num )
      v3->noseStrip = (*((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
                        v3,
                        curSX.mNoseStripList.m_num,
                        v3->noseStrip);
    if ( curSX.mMouthStripList.m_num )
      v3->mouthStrip = (*((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
                         v3,
                         curSX.mMouthStripList.m_num,
                         v3->mouthStrip);
    v3->vfptr->GetRandomReal(v3);
    v7 = v3->vfptr;
    v3->skinShade = a2;
    v7->UpdateTrueFacePal(v3);
    v3->vfptr->GetRandomReal(v3);
    v8 = v3->vfptr;
    v3->hairShade = a2;
    v8->UpdateTrueFacePal(v3);
    if ( curSX.mHairColorList.m_num )
    {
      v9 = (*((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
             v3,
             curSX.mHairColorList.m_num,
             v3->hairColor);
      v10 = v3->vfptr;
      v3->hairColor = v9;
      v10->UpdateTrueFacePal(v3);
    }
    if ( curSX.mEyeColorList.m_num )
    {
      v11 = (*((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
              v3,
              curSX.mEyeColorList.m_num,
              v3->eyeColor);
      v12 = v3->vfptr;
      v3->eyeColor = v11;
      v12->UpdateTrueFacePal(v3);
    }
    if ( curSX.mHairStyleList.m_num )
    {
      v14 = v3->hairStyle;
      if ( restrict_hair )
        v13 = (*((int (__thiscall **)(_DWORD, signed int, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(v3, 7, v14);
      else
        v13 = (*((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&v3->vfptr->UpdateTrueFacePal + 1))(
                v3,
                curSX.mHairStyleList.m_num,
                v14);
      v3->hairStyle = v13;
    }
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C5080) --------------------------------------------------------  // acclient.c:496606
void __thiscall CharGenState::ApplyTemplate(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // edi@6
  HeritageGroup_CG *v4; // eax@7
  CharGenState *v5; // ecx@7
  CharGenState *v6; // ecx@7
  CharGenState *v7; // ecx@7
  CharGenState *v8; // ecx@7
  CharGenState *v9; // ecx@7
  unsigned int v10; // ebx@7
  unsigned int v11; // edi@7
  unsigned int v12; // ebp@9
  int v13; // edi@10
  SKILL_ADVANCEMENT_CLASS v14; // eax@11
  int v15; // ebx@11
  int v16; // eax@12
  int v17; // ebx@16
  SKILL_ADVANCEMENT_CLASS *v18; // ecx@17
  char *v19; // esi@23
  Template_CG curTM; // [sp+8h] [bp-100h]@7
  HeritageGroup_CG result; // [sp+48h] [bp-C0h]@7

  v1 = this;
  memset(&this->bAttribLocked[1], 0, 0x18u);
  v2 = this->mHeritageGroup;
  if ( v2 == 12 || v2 == 13 )
    this->template_ = 0;
  if ( v2 )
  {
    if ( this->mGender )
    {
      v3 = this->template_;
      if ( v3 != -1 )
      {
        v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
        Template_CG::Template_CG(&curTM, &v4->mTemplateList.m_data[v3]);
        HeritageGroup_CG::~HeritageGroup_CG(&result);
        CharGenState::SetStrength(v1, curTM.strength, 0);
        CharGenState::SetEndurance(v5, curTM.endurance, 0);
        CharGenState::SetCoordination(v6, curTM.coordination, 0);
        CharGenState::SetQuickness(v1, curTM.quickness, 0);
        CharGenState::SetFocus(v7, curTM.focus, 0);
        CharGenState::SetSelf(v8, curTM.self, 0);
        CharGenState::ResetSkillLevels(v9);
        v10 = curTM.mNormalSkillsList.m_num;
        v11 = 0;
        if ( curTM.mNormalSkillsList.m_num )
        {
          do
            CharGenState::SetSkillLevel(v1, curTM.mNormalSkillsList.m_data[v11++], TRAINED_SKILL_ADVANCEMENT_CLASS);
          while ( v11 < v10 );
        }
        v12 = 0;
        if ( curTM.mPrimarySkillsList.m_num )
        {
          while ( 1 )
          {
            v13 = curTM.mPrimarySkillsList.m_data[v12];
            if ( (unsigned int)v13 < v1->totalNumSkills )
              break;
LABEL_18:
            ++v12;
            if ( v12 >= curTM.mPrimarySkillsList.m_num )
              goto LABEL_19;
          }
          v14 = v1->skillLevels[v13];
          v15 = v1->remainingSkillCredits;
          if ( v14 == 2 )
          {
            v16 = ACCharGenData::GetSkillTrainedCost(v1->charGenData, v13, v1->mHeritageGroup, v1->mGender);
          }
          else
          {
            if ( v14 != 3 )
              goto LABEL_16;
            v16 = ACCharGenData::GetSkillSpecializedCost(v1->charGenData, v13, v1->mHeritageGroup, v1->mGender);
          }
          v15 += v16;
LABEL_16:
          v17 = v15 - ACCharGenData::GetSkillSpecializedCost(v1->charGenData, v13, v1->mHeritageGroup, v1->mGender);
          if ( v17 >= 0 )
          {
            v18 = v1->skillLevels;
            v1->remainingSkillCredits = v17;
            v18[v13] = 3;
          }
          goto LABEL_18;
        }
LABEL_19:
        if ( (curTM.mPrimarySkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](curTM.mPrimarySkillsList.m_data);
        if ( (curTM.mNormalSkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](curTM.mNormalSkillsList.m_data);
        v19 = &curTM.name.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&curTM.name.m_charbuffer[-1]) )
        {
          if ( v19 )
            (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
        }
      }
    }
  }
}

//----- (005C52A0) --------------------------------------------------------  // acclient.c:496713
int __thiscall CharGenState::GetBaldState(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ST0C_4@3
  HeritageGroup_CG *v4; // eax@3
  int v5; // eax@3
  int v6; // esi@4
  HairStyle_CG curHS; // [sp+4h] [bp-1D8h]@4
  Sex_CG curSX; // [sp+40h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+11Ch] [bp-C0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    v3 = this->mGender;
    v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v4, &curSX, v3);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    v5 = v1->hairStyle;
    if ( v5 != -1 )
    {
      HairStyle_CG::HairStyle_CG(&curHS, &curSX.mHairStyleList.m_data[v5]);
      v6 = curHS.bald;
      curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
      ObjDesc::~ObjDesc(&curHS.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      return v6;
    }
    Sex_CG::~Sex_CG(&curSX);
  }
  return 0;
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005C5350) --------------------------------------------------------  // acclient.c:496750
int __thiscall CharGenState::SetHeadgearStyle(CharGenState *this, int _headgearStyle)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // eax@1
  int *v4; // edi@1
  unsigned int v5; // ST10_4@3
  HeritageGroup_CG *v6; // eax@3
  int v7; // edi@6
  char *v8; // edi@8
  int v9; // eax@11
  Style_CG curST; // [sp+8h] [bp-1ACh]@4
  Sex_CG curSX; // [sp+18h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+F4h] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  v4 = &this->numHeadgearColors;
  this->numHeadgearColors = 0;
  if ( v3 && this->mGender )
  {
    v5 = this->mGender;
    v6 = ACCharGenData::GetHG(this->charGenData, &result, v3);
    HeritageGroup_CG::GetSX(v6, &curSX, v5);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( _headgearStyle != -1 )
    {
      Style_CG::Style_CG(&curST, &curSX.mHeadgearList.m_data[_headgearStyle]);
      CharGenState::StoreColorInformation(
        curST.clothingTable,
        v4,
        &v2->headgearPaletteTemplateIDs,
        &v2->headgearPalSetIDs,
        &curSX);
      if ( v2->headgearColor < 0 )
        v2->headgearColor = 0;
      v7 = *v4;
      if ( v2->headgearColor >= v7 )
        v2->headgearColor = v7 - 1;
      v8 = &curST.name.m_charbuffer[-2].m_data[12];
      curST.vfptr = (Style_CGVtbl *)&Style_CG::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&curST.name.m_charbuffer[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      }
    }
    Sex_CG::~Sex_CG(&curSX);
    v2->headgearStyle = _headgearStyle;
    v9 = _headgearStyle;
  }
  else
  {
    v9 = _headgearStyle;
    this->headgearStyle = _headgearStyle;
  }
  return v9;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005C5480) --------------------------------------------------------  // acclient.c:496810
int __thiscall CharGenState::SetShirtStyle(CharGenState *this, int _shirtStyle)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // eax@1
  int *v4; // edi@1
  unsigned int v5; // ST10_4@3
  HeritageGroup_CG *v6; // eax@3
  int v7; // edi@4
  char *v8; // edi@6
  int v9; // eax@9
  Style_CG curST; // [sp+8h] [bp-1ACh]@4
  Sex_CG curSX; // [sp+18h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+F4h] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  v4 = &this->numShirtColors;
  this->numShirtColors = 0;
  if ( v3 && this->mGender )
  {
    v5 = this->mGender;
    v6 = ACCharGenData::GetHG(this->charGenData, &result, v3);
    HeritageGroup_CG::GetSX(v6, &curSX, v5);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( _shirtStyle != -1 )
    {
      Style_CG::Style_CG(&curST, &curSX.mShirtList.m_data[_shirtStyle]);
      CharGenState::StoreColorInformation(
        curST.clothingTable,
        v4,
        &v2->shirtPaletteTemplateIDs,
        &v2->shirtPalSetIDs,
        &curSX);
      v7 = *v4;
      if ( v2->shirtColor >= v7 )
        v2->shirtColor = v7 - 1;
      v8 = &curST.name.m_charbuffer[-2].m_data[12];
      curST.vfptr = (Style_CGVtbl *)&Style_CG::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&curST.name.m_charbuffer[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      }
    }
    Sex_CG::~Sex_CG(&curSX);
    v2->shirtStyle = _shirtStyle;
    v9 = _shirtStyle;
  }
  else
  {
    v9 = _shirtStyle;
    this->shirtStyle = _shirtStyle;
  }
  return v9;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005C55A0) --------------------------------------------------------  // acclient.c:496868
int __thiscall CharGenState::SetTrousersStyle(CharGenState *this, int _trousersStyle)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // eax@1
  int *v4; // edi@1
  unsigned int v5; // ST10_4@3
  HeritageGroup_CG *v6; // eax@3
  int v7; // edi@4
  char *v8; // edi@6
  int v9; // eax@9
  Style_CG curST; // [sp+8h] [bp-1ACh]@4
  Sex_CG curSX; // [sp+18h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+F4h] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  v4 = &this->numTrousersColors;
  this->numTrousersColors = 0;
  if ( v3 && this->mGender )
  {
    v5 = this->mGender;
    v6 = ACCharGenData::GetHG(this->charGenData, &result, v3);
    HeritageGroup_CG::GetSX(v6, &curSX, v5);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( _trousersStyle != -1 )
    {
      Style_CG::Style_CG(&curST, &curSX.mPantsList.m_data[_trousersStyle]);
      CharGenState::StoreColorInformation(
        curST.clothingTable,
        v4,
        &v2->trousersPaletteTemplateIDs,
        &v2->trousersPalSetIDs,
        &curSX);
      v7 = *v4;
      if ( v2->trousersColor >= v7 )
        v2->trousersColor = v7 - 1;
      v8 = &curST.name.m_charbuffer[-2].m_data[12];
      curST.vfptr = (Style_CGVtbl *)&Style_CG::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&curST.name.m_charbuffer[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      }
    }
    Sex_CG::~Sex_CG(&curSX);
    v2->trousersStyle = _trousersStyle;
    v9 = _trousersStyle;
  }
  else
  {
    v9 = _trousersStyle;
    this->trousersStyle = _trousersStyle;
  }
  return v9;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005C56C0) --------------------------------------------------------  // acclient.c:496926
int __thiscall CharGenState::SetFootwearStyle(CharGenState *this, int _footwearStyle)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // eax@1
  int *v4; // edi@1
  unsigned int v5; // ST10_4@3
  HeritageGroup_CG *v6; // eax@3
  int v7; // edi@4
  char *v8; // edi@6
  int v9; // eax@9
  Style_CG curST; // [sp+8h] [bp-1ACh]@4
  Sex_CG curSX; // [sp+18h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+F4h] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  v4 = &this->numFootwearColors;
  this->numFootwearColors = 0;
  if ( v3 && this->mGender )
  {
    v5 = this->mGender;
    v6 = ACCharGenData::GetHG(this->charGenData, &result, v3);
    HeritageGroup_CG::GetSX(v6, &curSX, v5);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( _footwearStyle != -1 )
    {
      Style_CG::Style_CG(&curST, &curSX.mFootwearList.m_data[_footwearStyle]);
      CharGenState::StoreColorInformation(
        curST.clothingTable,
        v4,
        &v2->footwearPaletteTemplateIDs,
        &v2->footwearPalSetIDs,
        &curSX);
      v7 = *v4;
      if ( v2->footwearColor >= v7 )
        v2->footwearColor = v7 - 1;
      v8 = &curST.name.m_charbuffer[-2].m_data[12];
      curST.vfptr = (Style_CGVtbl *)&Style_CG::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&curST.name.m_charbuffer[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      }
    }
    Sex_CG::~Sex_CG(&curSX);
    v2->footwearStyle = _footwearStyle;
    v9 = _footwearStyle;
  }
  else
  {
    v9 = _footwearStyle;
    this->footwearStyle = _footwearStyle;
  }
  return v9;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005C57E0) --------------------------------------------------------  // acclient.c:496984
void __thiscall CharGenState::RandomizeSkills(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ST0C_4@3
  HeritageGroup_CG *v4; // eax@3
  unsigned int v5; // ebx@3
  unsigned int v6; // eax@4
  int v7; // ecx@4
  int v8; // ebx@13
  int v9; // edi@14
  int v10; // ecx@15
  int v14; // ebx@19
  SKILL_ADVANCEMENT_CLASS *v15; // eax@20
  int v16; // ebx@23
  int v17; // ebx@23
  SKILL_ADVANCEMENT_CLASS *v18; // ecx@24
  HeritageGroup_CG result; // [sp+4h] [bp-19Ch]@3
  Sex_CG curSX; // [sp+C4h] [bp-DCh]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    v3 = this->mGender;
    v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v4, &curSX, v3);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    CharGenState::ResetSkillLevels(v1);
    v5 = 0;
    do
    {
      v6 = RandInt(v1->totalNumSkills);
      v7 = v1->totalNumSkills;
      if ( v6 < v7 )
      {
        if ( v1->skillLevels[v6] == 1 )
        {
          if ( v5 & 1 )
            CharGenState::SetSkillLevel(v1, v6, TRAINED_SKILL_ADVANCEMENT_CLASS);
        }
        else if ( v6 < v7 && v1->skillLevels[v6] == 2 )
        {
          CharGenState::SetSkillLevel(v1, v6, SPECIALIZED_SKILL_ADVANCEMENT_CLASS);
        }
      }
      if ( !v1->remainingSkillCredits )
        break;
      ++v5;
    }
    while ( v5 < 0x64 );
    v8 = v1->remainingSkillCredits;
    if ( v8 > 0 )
    {
      v9 = 0;
      if ( v1->totalNumSkills )
      {
        do
        {
          v10 = v1->totalNumSkills;
          if ( v9 < (unsigned int)v10 )
          {
            if ( v1->skillLevels[v9] == 1 )
            {
              v14 = v8 - ACCharGenData::GetSkillTrainedCost(v1->charGenData, v9, v1->mHeritageGroup, v1->mGender);
              if ( v14 >= 0 )
              {
                v15 = v1->skillLevels;
                v1->remainingSkillCredits = v14;
                v15[v9] = 2;
              }
            }
            else if ( v9 < (unsigned int)v10 && v1->skillLevels[v9] == 2 )
            {
              v16 = ACCharGenData::GetSkillTrainedCost(v1->charGenData, v9, v1->mHeritageGroup, v1->mGender) + v8;
              v17 = v16 - ACCharGenData::GetSkillSpecializedCost(v1->charGenData, v9, v1->mHeritageGroup, v1->mGender);
              if ( v17 >= 0 )
              {
                v18 = v1->skillLevels;
                v1->remainingSkillCredits = v17;
                v18[v9] = 3;
              }
            }
          }
          v8 = v1->remainingSkillCredits;
          if ( !v8 )
            break;
          ++v9;
        }
        while ( (unsigned int)v9 < v1->totalNumSkills );
      }
    }
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C59E0) --------------------------------------------------------  // acclient.c:497081
void __thiscall CharGenState::RandomizeStartArea(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // eax@3
  unsigned int v4; // eax@3
  HeritageGroup_CG curHG; // [sp+4h] [bp-C0h]@2

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 )
  {
    ACCharGenData::GetHG(this->charGenData, &curHG, v2);
    if ( curHG.mPrimaryStartAreaList.m_num )
    {
      v3 = RandInt(curHG.mPrimaryStartAreaList.m_num, -1);
      v4 = curHG.mPrimaryStartAreaList.m_data[v3];
      if ( (v4 & 0x80000000) == 0 && (signed int)v4 < (signed int)v1->charGenData->mStartAreaList.m_num )
      {
        v1->startArea = v4;
        HeritageGroup_CG::~HeritageGroup_CG(&curHG);
        return;
      }
      v1->startArea = -1;
    }
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}

//----- (005C5A60) --------------------------------------------------------  // acclient.c:497111
int __thiscall CharGenState::SetTemplate(CharGenState *this, int _template, int _apply)
{
  CharGenState *v3; // esi@1

  v3 = this;
  this->template_ = _template;
  if ( _apply && _template != -1 )
    CharGenState::ApplyTemplate(this);
  return v3->template_;
}

//----- (005C5A90) --------------------------------------------------------  // acclient.c:497123
IDClass<_tagDataID,32,0> *__thiscall CharGenState::GetSetupID(CharGenState *this, IDClass<_tagDataID,32,0> *result)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // edx@1
  unsigned int v4; // ST0C_4@3
  HeritageGroup_CG *v5; // eax@3
  int v6; // esi@3
  unsigned int v7; // eax@4
  IDClass<_tagDataID,32,0> *v8; // eax@6
  HairStyle_CG curHS; // [sp+4h] [bp-1D8h]@4
  Sex_CG curSX; // [sp+40h] [bp-19Ch]@3
  HeritageGroup_CG v11; // [sp+11Ch] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  if ( v3 && this->mGender )
  {
    v4 = this->mGender;
    v5 = ACCharGenData::GetHG(this->charGenData, &v11, v3);
    HeritageGroup_CG::GetSX(v5, &curSX, v4);
    HeritageGroup_CG::~HeritageGroup_CG(&v11);
    v6 = v2->hairStyle;
    if ( v6 == -1 )
    {
      result->id = curSX.setup.id;
      Sex_CG::~Sex_CG(&curSX);
      v8 = result;
    }
    else
    {
      HairStyle_CG::HairStyle_CG(&curHS, &curSX.mHairStyleList.m_data[v6]);
      v7 = curHS.alternateSetup.id;
      curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
      if ( curHS.alternateSetup.id == stru_8EF8B4.id )
        v7 = curSX.setup.id;
      result->id = v7;
      ObjDesc::~ObjDesc(&curHS.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      v8 = result;
    }
  }
  else
  {
    v8 = result;
    result->id = this->setupID.id;
  }
  return v8;
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005C5B80) --------------------------------------------------------  // acclient.c:497174
void __thiscall CharGenState::ConstrainAllByGender(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  CharGenStateVtbl *v3; // edx@14
  int v4; // eax@17
  int v5; // eax@21
  int v6; // eax@25
  int v7; // eax@29
  CharGenStateVtbl *v8; // eax@32
  CharGenStateVtbl *v9; // edx@32
  CharGenStateVtbl *v10; // eax@32
  CharGenStateVtbl *v11; // edx@32
  Sex_CG curSX; // [sp+10h] [bp-1A0h]@3
  HeritageGroup_CG curHG; // [sp+F0h] [bp-C0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    ACCharGenData::GetHG(this->charGenData, &curHG, v2);
    HeritageGroup_CG::GetSX(&curHG, &curSX, v1->mGender);
    if ( v1->eyesStrip >= (signed int)curSX.mEyeStripList.m_num )
      v1->eyesStrip = curSX.mEyeStripList.m_num - 1;
    if ( v1->noseStrip >= (signed int)curSX.mNoseStripList.m_num )
      v1->noseStrip = curSX.mNoseStripList.m_num - 1;
    if ( v1->mouthStrip >= (signed int)curSX.mMouthStripList.m_num )
      v1->mouthStrip = curSX.mMouthStripList.m_num - 1;
    if ( v1->hairStyle >= (signed int)curSX.mHairStyleList.m_num )
      v1->hairStyle = curSX.mHairStyleList.m_num - 1;
    if ( v1->eyeColor >= (signed int)curSX.mEyeColorList.m_num )
    {
      v1->eyeColor = curSX.mEyeColorList.m_num - 1;
      v1->vfptr->UpdateTrueFacePal(v1);
    }
    if ( v1->hairColor >= (signed int)curSX.mHairColorList.m_num )
    {
      v3 = v1->vfptr;
      v1->hairColor = curSX.mHairColorList.m_num - 1;
      v3->UpdateTrueFacePal(v1);
    }
    if ( v1->headgearStyle >= (signed int)curSX.mHeadgearList.m_num )
      CharGenState::SetHeadgearStyle(v1, curSX.mHeadgearList.m_num - 1);
    v4 = v1->numHeadgearColors;
    if ( v1->headgearColor >= v4 )
      v1->headgearColor = v4 - 1;
    if ( v1->shirtStyle >= (signed int)curSX.mShirtList.m_num )
      CharGenState::SetShirtStyle(v1, curSX.mShirtList.m_num - 1);
    v5 = v1->numShirtColors;
    if ( v1->shirtColor >= v5 )
      v1->shirtColor = v5 - 1;
    if ( v1->trousersStyle >= (signed int)curSX.mPantsList.m_num )
      CharGenState::SetTrousersStyle(v1, curSX.mPantsList.m_num - 1);
    v6 = v1->numTrousersColors;
    if ( v1->trousersColor >= v6 )
      v1->trousersColor = v6 - 1;
    if ( v1->footwearStyle >= (signed int)curSX.mFootwearList.m_num )
      CharGenState::SetFootwearStyle(v1, curSX.mFootwearList.m_num - 1);
    v7 = v1->numFootwearColors;
    if ( v1->footwearColor >= v7 )
      v1->footwearColor = v7 - 1;
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
  else
  {
    v8 = this->vfptr;
    this->eyesStrip = -1;
    this->noseStrip = -1;
    this->mouthStrip = -1;
    LODWORD(this->skinShade) = 0;
    HIDWORD(this->skinShade) = -1074790400;
    ((void (*)(void))v8->UpdateTrueFacePal)();
    v9 = v1->vfptr;
    LODWORD(v1->hairShade) = 0;
    HIDWORD(v1->hairShade) = -1074790400;
    v9->UpdateTrueFacePal(v1);
    v10 = v1->vfptr;
    v1->hairColor = -1;
    v10->UpdateTrueFacePal(v1);
    v11 = v1->vfptr;
    v1->eyeColor = -1;
    v11->UpdateTrueFacePal(v1);
    v1->hairStyle = -1;
    CharGenState::SetHeadgearStyle(v1, -1);
    v1->headgearColor = -1;
    LODWORD(v1->headgearShade) = 0;
    HIDWORD(v1->headgearShade) = -1074790400;
    CharGenState::SetShirtStyle(v1, -1);
    v1->shirtColor = -1;
    LODWORD(v1->shirtShade) = 0;
    HIDWORD(v1->shirtShade) = -1074790400;
    CharGenState::SetTrousersStyle(v1, -1);
    v1->trousersColor = -1;
    LODWORD(v1->trousersShade) = 0;
    HIDWORD(v1->trousersShade) = -1074790400;
    CharGenState::SetFootwearStyle(v1, -1);
    v1->footwearColor = -1;
    LODWORD(v1->footwearShade) = 0;
    HIDWORD(v1->footwearShade) = -1074790400;
  }
}

//----- (005C5E10) --------------------------------------------------------  // acclient.c:497278
void __thiscall CharGenState::RandomizeHeadgear(CharGenState *this, int _excludeCurrent)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // edx@1
  unsigned int v4; // ST0C_4@3
  HeritageGroup_CG *v5; // eax@3
  int v6; // eax@5
  const int v7; // eax@8
  Sex_CG curSX; // [sp+8h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+E4h] [bp-C0h]@3

  v2 = this;
  v3 = this->mHeritageGroup;
  if ( v3 && this->mGender )
  {
    v4 = this->mGender;
    v5 = ACCharGenData::GetHG(this->charGenData, &result, v3);
    HeritageGroup_CG::GetSX(v5, &curSX, v4);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( curSX.mHeadgearList.m_num )
    {
      if ( _excludeCurrent )
        v6 = RandInt(curSX.mHeadgearList.m_num + 1, v2->headgearStyle + 1);
      else
        v6 = RandInt(curSX.mHeadgearList.m_num + 1);
      CharGenState::SetHeadgearStyle(v2, v6 - 1);
    }
    v7 = v2->numHeadgearColors;
    if ( v7 )
      v2->headgearColor = RandInt(v7, v2->headgearColor);
    v2->headgearShade = (double)_rand() * 0.00003051850947599719;
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C5EF0) --------------------------------------------------------  // acclient.c:497314
void __thiscall CharGenState::RandomizeShirt(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ST0C_4@3
  HeritageGroup_CG *v4; // eax@3
  int v5; // eax@4
  const int v6; // eax@5
  Sex_CG curSX; // [sp+8h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+E4h] [bp-C0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    v3 = this->mGender;
    v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v4, &curSX, v3);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( curSX.mShirtList.m_num )
    {
      v5 = RandInt(curSX.mShirtList.m_num, v1->shirtStyle);
      CharGenState::SetShirtStyle(v1, v5);
    }
    v6 = v1->numShirtColors;
    if ( v6 )
      v1->shirtColor = RandInt(v6, v1->shirtColor);
    v1->shirtShade = (double)_rand() * 0.00003051850947599719;
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C5FB0) --------------------------------------------------------  // acclient.c:497347
void __thiscall CharGenState::RandomizeTrousers(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ST0C_4@3
  HeritageGroup_CG *v4; // eax@3
  int v5; // eax@4
  const int v6; // eax@5
  Sex_CG curSX; // [sp+8h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+E4h] [bp-C0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    v3 = this->mGender;
    v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v4, &curSX, v3);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( curSX.mPantsList.m_num )
    {
      v5 = RandInt(curSX.mPantsList.m_num, v1->trousersStyle);
      CharGenState::SetTrousersStyle(v1, v5);
    }
    v6 = v1->numTrousersColors;
    if ( v6 )
      v1->trousersColor = RandInt(v6, v1->trousersColor);
    v1->trousersShade = (double)_rand() * 0.00003051850947599719;
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C6070) --------------------------------------------------------  // acclient.c:497380
void __thiscall CharGenState::RandomizeFootwear(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ST0C_4@3
  HeritageGroup_CG *v4; // eax@3
  int v5; // eax@4
  const int v6; // eax@5
  Sex_CG curSX; // [sp+8h] [bp-19Ch]@3
  HeritageGroup_CG result; // [sp+E4h] [bp-C0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    v3 = this->mGender;
    v4 = ACCharGenData::GetHG(this->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v4, &curSX, v3);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    if ( curSX.mFootwearList.m_num )
    {
      v5 = RandInt(curSX.mFootwearList.m_num, v1->footwearStyle);
      CharGenState::SetFootwearStyle(v1, v5);
    }
    v6 = v1->numFootwearColors;
    if ( v6 )
      v1->footwearColor = RandInt(v6, v1->footwearColor);
    v1->footwearShade = (double)_rand() * 0.00003051850947599719;
    Sex_CG::~Sex_CG(&curSX);
  }
}

//----- (005C6130) --------------------------------------------------------  // acclient.c:497413
void __thiscall CharGenState::FitTemplateToCharacter(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  int v4; // eax@5
  bool v5; // sf@5
  unsigned __int8 v6; // of@5
  int *v7; // eax@5
  int v8; // eax@7
  int *v9; // edx@7
  int v10; // eax@9
  int *v11; // edx@9
  int v12; // eax@11
  int *v13; // edx@11
  int v14; // eax@13
  int *v15; // edx@13
  int v16; // eax@15
  int v17; // edi@15
  int *v18; // edx@15
  int v19; // ebx@20
  unsigned int v20; // ecx@20
  int v21; // eax@21
  long double v22; // st7@26
  int v23; // ebx@28
  unsigned int v24; // ecx@28
  int v25; // edx@29
  int v26; // eax@30
  SKILL_ADVANCEMENT_CLASS v27; // eax@31
  long double v28; // st7@37
  char *v29; // edi@46
  bool v30; // cf@49
  int curTotal; // [sp+10h] [bp-208h]@5
  int curScore; // [sp+14h] [bp-204h]@15
  long double templateScore; // [sp+18h] [bp-200h]@18
  unsigned int templateNum; // [sp+24h] [bp-1F4h]@3
  unsigned int v35; // [sp+28h] [bp-1F0h]@4
  signed __int64 bestFitTemplateNum; // [sp+2Ch] [bp-1ECh]@1
  int v37; // [sp+34h] [bp-1E4h]@1
  Template_CG curTM; // [sp+38h] [bp-1E0h]@5
  HeritageGroup_CG curHG; // [sp+78h] [bp-1A0h]@3
  Sex_CG curSX; // [sp+138h] [bp-E0h]@3

  v1 = this;
  v2 = this->mHeritageGroup;
  v3 = -1;
  bestFitTemplateNum = 0xFFFFFFFFi64;
  v37 = 0;
  if ( v2 && this->mGender )
  {
    ACCharGenData::GetHG(this->charGenData, &curHG, v2);
    HeritageGroup_CG::GetSX(&curHG, &curSX, v1->mGender);
    templateNum = 1;
    if ( curHG.mTemplateList.m_num > 1 )
    {
      v35 = 64;
      do
      {
        Template_CG::Template_CG(&curTM, &curHG.mTemplateList.m_data[v35 / 0x40]);
        v4 = v1->strength;
        curTotal = v4;
        v6 = __OFSUB__(v4, curTM.strength);
        v5 = v4 - curTM.strength < 0;
        v7 = &curTotal;
        if ( !(v5 ^ v6) )
          v7 = &curTM.strength;
        v8 = *v7;
        curTotal = v1->endurance;
        v9 = &curTotal;
        if ( curTotal >= curTM.endurance )
          v9 = &curTM.endurance;
        v10 = *v9 + v8;
        curTotal = v1->coordination;
        v11 = &curTotal;
        if ( curTotal >= curTM.coordination )
          v11 = &curTM.coordination;
        v12 = *v11 + v10;
        curTotal = v1->quickness;
        v13 = &curTotal;
        if ( curTotal >= curTM.quickness )
          v13 = &curTM.quickness;
        v14 = *v13 + v12;
        curTotal = v1->focus;
        v15 = &curTotal;
        if ( curTotal >= curTM.focus )
          v15 = &curTM.focus;
        v16 = *v15 + v14;
        v17 = v1->self;
        curTotal = curTM.self + curTM.focus + curTM.quickness + curTM.coordination + curTM.endurance + curTM.strength;
        curScore = v17;
        v18 = &curScore;
        if ( v17 >= curTM.self )
          v18 = &curTM.self;
        if ( curTM.self + curTM.focus + curTM.quickness + curTM.coordination + curTM.endurance + curTM.strength <= 0 )
        {
          templateScore = 0.25;
        }
        else
        {
          curScore = v16 + *v18;
          templateScore = pow((double)curScore / (double)curTotal, 2.5) * 0.3333333333333333;
        }
        v19 = 0;
        v20 = 0;
        curScore = 0;
        if ( !curTM.mNormalSkillsList.m_num )
          goto LABEL_57;
        do
        {
          v21 = curTM.mNormalSkillsList.m_data[v20];
          if ( (unsigned int)v21 < v1->totalNumSkills && v1->skillLevels[v21] >= 2 )
            ++v19;
          ++v20;
        }
        while ( v20 < curTM.mNormalSkillsList.m_num );
        curScore = v19;
        if ( (signed int)curTM.mNormalSkillsList.m_num > 0 )
          v22 = pow((double)curScore / (double)(signed int)curTM.mNormalSkillsList.m_num, 3.0) * 0.3333333333333333
              + templateScore;
        else
LABEL_57:
          v22 = templateScore + 0.3;
        templateScore = v22;
        v23 = 0;
        v24 = 0;
        curScore = 0;
        if ( !curTM.mPrimarySkillsList.m_num )
          goto LABEL_58;
        v25 = v1->totalNumSkills;
        curTotal = 2 * curTM.mPrimarySkillsList.m_num;
        do
        {
          v26 = curTM.mPrimarySkillsList.m_data[v24];
          if ( v26 < (unsigned int)v25 )
          {
            v27 = v1->skillLevels[v26];
            if ( v27 == 2 )
            {
              ++v23;
            }
            else if ( v27 == 3 )
            {
              v23 += 2;
            }
          }
          ++v24;
        }
        while ( v24 < curTM.mPrimarySkillsList.m_num );
        curScore = v23;
        if ( curTotal > 0 )
          v28 = pow((double)curScore / (double)curTotal, 3.5) * 0.3333333333333333 + templateScore;
        else
LABEL_58:
          v28 = templateScore + 0.45;
        if ( v28 <= *(double *)((char *)&bestFitTemplateNum + 4) )
        {
          v3 = bestFitTemplateNum;
        }
        else
        {
          v3 = templateNum;
          *(double *)((char *)&bestFitTemplateNum + 4) = v28;
          LODWORD(bestFitTemplateNum) = templateNum;
        }
        curTM.vfptr = (Template_CGVtbl *)&Template_CG::vftable;
        if ( (curTM.mPrimarySkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](curTM.mPrimarySkillsList.m_data);
        if ( (curTM.mNormalSkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](curTM.mNormalSkillsList.m_data);
        v29 = &curTM.name.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&curTM.name.m_charbuffer[-1]) && v29 )
          (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
        v30 = templateNum++ + 1 < curHG.mTemplateList.m_num;
        v35 += 64;
      }
      while ( v30 );
    }
    if ( *(double *)((char *)&bestFitTemplateNum + 4) < 0.75 )
      v3 = 0;
    if ( v3 != v1->template_ )
      v1->template_ = v3;
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (005C64A0) --------------------------------------------------------  // acclient.c:497601
void __thiscall CharGenState::SetGender(CharGenState *this, unsigned int gender)
{
  CharGenState *v2; // esi@1

  v2 = this;
  this->mGender = gender;
  CharGenState::ConstrainAllByGender(this);
  v2->vfptr->UpdateTrueFacePal(v2);
  CharGenState::SetHeadgearStyle(v2, v2->headgearStyle);
  CharGenState::SetShirtStyle(v2, v2->shirtStyle);
  CharGenState::SetTrousersStyle(v2, v2->trousersStyle);
  CharGenState::SetFootwearStyle(v2, v2->footwearStyle);
}

//----- (005C6500) --------------------------------------------------------  // acclient.c:497616
void __thiscall CharGenState::RandomizeTemplate(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // eax@6
  HeritageGroup_CG curHG; // [sp+4h] [bp-C0h]@5

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 && this->mGender )
  {
    if ( v2 == 12 || v2 == 13 )
    {
      this->template_ = 1;
      CharGenState::ApplyTemplate(this);
    }
    else
    {
      ACCharGenData::GetHG(this->charGenData, &curHG, v2);
      if ( curHG.mTemplateList.m_num > 1 )
      {
        v3 = RandInt(curHG.mTemplateList.m_num - 1, v1->template_ - 1) + 1;
        v1->template_ = v3;
        if ( v3 != -1 )
          CharGenState::ApplyTemplate(v1);
      }
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
    }
  }
}

//----- (005C6590) --------------------------------------------------------  // acclient.c:497648
void __thiscall CharGenState::ConstrainAllByHeritage(CharGenState *this)
{
  CharGenState *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // eax@5
  int v4; // edx@11
  HeritageGroup_CG curHG; // [sp+8h] [bp-C0h]@2

  v1 = this;
  v2 = this->mHeritageGroup;
  if ( v2 )
  {
    ACCharGenData::GetHG(this->charGenData, &curHG, v2);
    CharGenState::ConstrainAllByGender(v1);
    if ( v1->template_ >= (signed int)curHG.mTemplateList.m_num )
      v1->template_ = -1;
    if ( v1->totalAtrbCredits > curHG.numAttributeCredits )
    {
      v3 = -(v1->strength + v1->endurance + v1->coordination + v1->quickness + v1->focus + v1->self);
      v1->totalAtrbCredits = 0;
      v1->remainingAtrbCredits = v3;
      CharGenState::SetStrength(v1, 0, 0);
      CharGenState::SetEndurance(v1, v1->totalAtrbCredits / 6, 0);
      CharGenState::SetCoordination(v1, v1->totalAtrbCredits / 6, 0);
      CharGenState::SetQuickness(v1, v1->totalAtrbCredits / 6, 0);
      CharGenState::SetFocus(v1, v1->totalAtrbCredits / 6, 0);
      CharGenState::SetSelf(v1, v1->totalAtrbCredits / 6, 0);
    }
    if ( v1->totalSkillCredits > curHG.numSkillCredits )
      v1->totalSkillCredits = curHG.numSkillCredits;
    CharGenState::UpdateRemainingSkillCredits(v1);
    if ( v1->remainingSkillCredits < 0 )
      CharGenState::ResetSkillLevels(v1);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
  else
  {
    v4 = -(this->strength + this->endurance + this->coordination + this->quickness + this->focus + this->self);
    this->template_ = -1;
    this->totalAtrbCredits = 0;
    this->remainingAtrbCredits = v4;
    this->totalSkillCredits = 0;
    this->remainingSkillCredits = 0;
    CharGenState::SetName(this, &name);
    v1->startArea = -1;
    CharGenState::ApplyDefaultTemplate(v1);
  }
}

//----- (005C6770) --------------------------------------------------------  // acclient.c:497698
void __thiscall CharGenState::RandomizeClothing(CharGenState *this, int _excludeCurrent)
{
  CharGenState *v2; // esi@1

  v2 = this;
  CharGenState::RandomizeHeadgear(this, _excludeCurrent);
  CharGenState::RandomizeShirt(v2);
  CharGenState::RandomizeTrousers(v2);
  CharGenState::RandomizeFootwear(v2);
}

//----- (005C67A0) --------------------------------------------------------  // acclient.c:497710
void __thiscall CharGenState::SetHeritageGroup(CharGenState *this, unsigned int heritageGroup)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // ecx@2
  int v4; // eax@4
  int v5; // edx@4
  int v6; // ecx@4
  int v7; // eax@4
  HeritageGroup_CG curHG; // [sp+4h] [bp-C0h]@2

  v2 = this;
  this->mHeritageGroup = heritageGroup;
  if ( heritageGroup )
  {
    ACCharGenData::GetHG(this->charGenData, &curHG, heritageGroup);
    v3 = curHG.setupID.id;
    if ( curHG.setupID.id != v2->setupID.id )
    {
      v2->setupChanged = 1;
      v2->setupID.id = v3;
    }
    v4 = curHG.numAttributeCredits;
    v5 = v2->self;
    v6 = v2->focus;
    v2->totalAtrbCredits = curHG.numAttributeCredits;
    v2->remainingAtrbCredits = v4 - v5 - v6 - v2->quickness - v2->coordination - v2->endurance - v2->strength;
    v7 = curHG.numSkillCredits;
    v2->totalSkillCredits = curHG.numSkillCredits;
    v2->remainingSkillCredits = v7;
    CharGenState::ApplyTemplate(v2);
    CharGenState::RandomizeStartArea(v2);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
  CharGenState::ConstrainAllByHeritage(v2);
  v2->vfptr->UpdateTrueFacePal(v2);
  CharGenState::SetHeadgearStyle(v2, v2->headgearStyle);
  CharGenState::SetShirtStyle(v2, v2->shirtStyle);
  CharGenState::SetTrousersStyle(v2, v2->trousersStyle);
  CharGenState::SetFootwearStyle(v2, v2->footwearStyle);
}

//----- (005C68A0) --------------------------------------------------------  // acclient.c:497752
void __thiscall CharGenState::Reset(CharGenState *this)
{
  CharGenState *v1; // esi@1
  CharGenStateVtbl *v2; // eax@1
  CharGenStateVtbl *v3; // edx@1
  CharGenStateVtbl *v4; // eax@1
  CharGenStateVtbl *v5; // edx@1

  v1 = this;
  this->verificationState = 0;
  this->heritageGroupFrozen = 0;
  this->sexFrozen = 0;
  this->appearanceFrozen = 0;
  this->clothingFrozen = 0;
  memset(&this->bAttribLocked[1], 0, 0x18u);
  CharGenState::SetHeritageGroup(this, 0);
  CharGenState::SetGender(v1, 0);
  v2 = v1->vfptr;
  v1->eyesStrip = -1;
  v1->noseStrip = -1;
  v1->mouthStrip = -1;
  LODWORD(v1->skinShade) = 0;
  HIDWORD(v1->skinShade) = -1074790400;
  v2->UpdateTrueFacePal(v1);
  v3 = v1->vfptr;
  LODWORD(v1->hairShade) = 0;
  HIDWORD(v1->hairShade) = -1074790400;
  v3->UpdateTrueFacePal(v1);
  v4 = v1->vfptr;
  v1->hairColor = -1;
  v4->UpdateTrueFacePal(v1);
  v5 = v1->vfptr;
  v1->eyeColor = -1;
  v5->UpdateTrueFacePal(v1);
  v1->hairStyle = -1;
  CharGenState::SetHeadgearStyle(v1, -1);
  v1->headgearColor = -1;
  LODWORD(v1->headgearShade) = 0;
  HIDWORD(v1->headgearShade) = -1074790400;
  CharGenState::SetShirtStyle(v1, -1);
  v1->shirtColor = -1;
  LODWORD(v1->shirtShade) = 0;
  HIDWORD(v1->shirtShade) = -1074790400;
  CharGenState::SetTrousersStyle(v1, -1);
  v1->trousersColor = -1;
  LODWORD(v1->trousersShade) = 0;
  HIDWORD(v1->trousersShade) = -1074790400;
  CharGenState::SetFootwearStyle(v1, -1);
  v1->footwearColor = -1;
  LODWORD(v1->footwearShade) = 0;
  HIDWORD(v1->footwearShade) = -1074790400;
  v1->template_ = -1;
  v1->atrbMin = 10;
  v1->atrbMax = 100;
  v1->totalAtrbCredits = 0;
  v1->remainingAtrbCredits = 0;
  v1->totalSkillCredits = 0;
  v1->remainingSkillCredits = 0;
  CharGenState::SetName(v1, &name);
  v1->startArea = -1;
  v1->createAsAdmin = 0;
  v1->createAsEnvoy = 0;
  CharGenState::ApplyDefaultTemplate(v1);
  v1->setupChanged = 0;
  v1->setupID.id = 33554516;
  v1->animID.id = 50331651;
}

//----- (005C6A20) --------------------------------------------------------  // acclient.c:497821
void __thiscall CharGenState::RandomizeHeritageGroup(CharGenState *this, bool hasThroneOfDestiny)
{
  CharGenState *v2; // esi@1
  unsigned int v3; // eax@2

  v2 = this;
  if ( hasThroneOfDestiny )
    v3 = Random::RollDice(1, 4);
  else
    v3 = Random::RollDice(1, 3);
  CharGenState::SetHeritageGroup(v2, v3);
}

//----- (005C6A50) --------------------------------------------------------  // acclient.c:497835
void __thiscall CharGenState::CharGenState(CharGenState *this)
{
  CharGenState *v1; // ebp@1
  int v2; // eax@3
  PackableHashData<unsigned long,SkillBase> *v3; // edi@3
  void *v4; // esi@6
  unsigned int v5; // edi@7
  AC1Legacy::PSRefBuffer<char> *v6; // esi@10
  unsigned int v7; // edi@13
  ListNode<SkillRecord *> *v8; // eax@14
  int v9; // ecx@16
  const char *v10; // eax@21
  PackableHashData<unsigned long,SkillBase> *v11; // ecx@23
  unsigned int v12; // eax@23
  PackableHashData<unsigned long,SkillBase> *v13; // eax@25
  unsigned int v14; // eax@26
  int v15; // eax@31
  void *v16; // eax@32
  int v17; // ecx@32
  unsigned int v18; // eax@32
  int v19; // eax@34
  AC1Legacy::PSRefBuffer<char> *v20; // esi@34
  AC1Legacy::PSRefBuffer<char> *v21; // esi@37
  int v22; // [sp+Ch] [bp-74h]@1
  SkillRecord *newRecord; // [sp+10h] [bp-70h]@7
  AC1Legacy::PSRefBuffer<char> *v24; // [sp+14h] [bp-6Ch]@7
  PackableHashIterator<unsigned long,SkillBase> iter; // [sp+18h] [bp-68h]@3
  SkillBase sbase; // [sp+28h] [bp-58h]@3

  v1 = this;
  v22 = 0;
  this->vfptr = (CharGenStateVtbl *)&CharGenState::vftable;
  ACCharGenResult::ACCharGenResult(&this->charGenResult);
  v1->beginRequest = 1;
  v1->numHeadgearColors = 0;
  v1->numShirtColors = 0;
  v1->numTrousersColors = 0;
  v1->numFootwearColors = 0;
  v1->headgearPaletteTemplateIDs = 0;
  v1->shirtPaletteTemplateIDs = 0;
  v1->trousersPaletteTemplateIDs = 0;
  v1->footwearPaletteTemplateIDs = 0;
  v1->headgearPalSetIDs = 0;
  v1->shirtPalSetIDs = 0;
  v1->trousersPalSetIDs = 0;
  v1->footwearPalSetIDs = 0;
  v1->totalNumSkills = 0;
  v1->skillLevels = 0;
  v1->skillRecordList.vfptr = (List<SkillRecord *>Vtbl *)&List<SkillRecord *>::vftable;
  v1->skillRecordList._head = 0;
  v1->skillRecordList._tail = 0;
  v1->skillRecordList._num_elements = 0;
  v1->skillTable = 0;
  v1->enterChargen = 0;
  v1->charGenData = 0;
  v1->charGenData = (ACCharGenData *)DBCache::GetFromEnumStatic(14, 2, 0x10000002u);
  v1->slot = 0;
  CharGenState::Reset(v1);
  if ( v1->skillLevels )
  {
    operator delete[](v1->skillLevels);
    v1->skillLevels = 0;
  }
  v2 = DBCache::GetFromEnumStatic(4, 2, 0x10000004u);
  v1->skillTable = (SkillTable *)v2;
  PackableHashTable<unsigned long,SkillBase>::begin((PackableHashTable<unsigned long,SkillBase> *)(v2 + 56), &iter);
  SkillBase::SkillBase(&sbase);
  v3 = iter._current;
  if ( iter._current )
  {
    while ( 1 )
    {
      SkillBase::operator=((int)&sbase, (int)&v3->_data);
      v4 = operator new(0x24u);
      if ( v4 )
      {
        v24 = sbase._name.m_buffer;
        v22 |= 1u;
        InterlockedIncrement((volatile LONG *)&sbase._name.m_buffer->m_cRef);
        v5 = v3->_key;
        _strncpy((char *)v4, sbase._name.m_buffer->m_data, 0x1Eu);
        *((_DWORD *)v4 + 8) = v5;
        newRecord = (SkillRecord *)v4;
      }
      else
      {
        newRecord = 0;
      }
      if ( v22 & 1 )
      {
        v22 &= 0xFFFFFFFE;
        v6 = v24;
        if ( !InterlockedDecrement((volatile LONG *)&v24->m_cRef) )
        {
          if ( v6 )
            v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
        }
      }
      v7 = -1;
      do
      {
        v8 = v1->skillRecordList._head;
        ++v7;
        if ( !v8 || v7 >= v1->skillRecordList._num_elements )
          break;
        v9 = 0;
        while ( v9 != v7 )
        {
          v8 = v8->next;
          ++v9;
          if ( !v8 )
            goto LABEL_23;
        }
        if ( !v8 )
          break;
        v10 = v8->data->name;
        if ( !v10 )
          break;
      }
      while ( strcmp(newRecord->name, v10) > 0 );
LABEL_23:
      List<SkillRecord *>::push(&v1->skillRecordList, v7, &newRecord);
      v11 = iter._current;
      v12 = iter._current->_key + 1;
      if ( v12 > v1->totalNumSkills )
        v1->totalNumSkills = v12;
      v13 = v11->_next;
      if ( !v13 )
      {
        v14 = v11->_hashVal + 1;
        if ( v14 >= iter._table_size )
        {
LABEL_29:
          v13 = 0;
        }
        else
        {
          while ( !iter._buckets[v14] )
          {
            ++v14;
            if ( v14 >= iter._table_size )
              goto LABEL_29;
          }
          v13 = iter._buckets[v14];
        }
      }
      iter._current = v13;
      if ( !v13 )
        break;
      v3 = iter._current;
    }
  }
  v15 = v1->totalNumSkills;
  if ( v15 > 0 )
  {
    v16 = operator new[](4 * v15);
    v17 = v1->totalNumSkills;
    v1->skillLevels = (SKILL_ADVANCEMENT_CLASS *)v16;
    v18 = 0;
    if ( (unsigned int)v17 > 0 )
    {
      do
        v1->skillLevels[v18++] = 0;
      while ( v18 < v1->totalNumSkills );
    }
  }
  v19 = DBCache::GetFromEnumStatic(1, 2, 0x10000003u);
  v20 = sbase._name.m_buffer;
  v1->attribute2ndTable = (Attribute2ndTable *)v19;
  memset(&v1->bAttribLocked[1], 0, 0x18u);
  if ( !InterlockedDecrement((volatile LONG *)&v20->m_cRef) && v20 )
    v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
  v21 = sbase._description.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&sbase._description.m_buffer->m_cRef) )
  {
    if ( v21 )
      v21->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v21, 1u);
  }
}
// 7E77F8: using guessed type int (__thiscall *List<SkillRecord *>::vftable)(void *, char);
// 7E77FC: using guessed type void (__thiscall *CharGenState::vftable)(gmNoticeHandler *this);

//----- (005C6D80) --------------------------------------------------------  // acclient.c:498018
void __userpurge CharGenState::RandomizeCharacter(CharGenState *this@<ecx>, long double a2@<st0>, bool hasThroneOfDestiny)
{
  CharGenState *v3; // esi@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@4

  v3 = this;
  CharGenState::Reset(this);
  if ( hasThroneOfDestiny )
    v4 = Random::RollDice(1, 4);
  else
    v4 = Random::RollDice(1, 3);
  CharGenState::SetHeritageGroup(v3, v4);
  v5 = Random::RollDice(1, 2);
  CharGenState::SetGender(v3, v5);
  CharGenState::RandomizeAppearance(v3, a2, 0);
  CharGenState::RandomizeHeadgear(v3, 0);
  CharGenState::RandomizeShirt(v3);
  CharGenState::RandomizeTrousers(v3);
  CharGenState::RandomizeFootwear(v3);
  CharGenState::RandomizeTemplate(v3);
  CharGenState::RandomizeStartArea(v3);
  v3->heritageGroupFrozen = 1;
  v3->sexFrozen = 1;
  v3->appearanceFrozen = 1;
}

//----- (0070F4E0) --------------------------------------------------------  // acclient.c:802483
void sub_70F4E0()
{
  flt_8EF8B8 = 1000.0 + 1.0;
}

//----- (0070F500) --------------------------------------------------------  // acclient.c:802489
void sub_70F500()
{
  flt_8EF8BC = 24.0 * 8.0;
}

//----- (0070F520) --------------------------------------------------------  // acclient.c:802495
void sub_70F520()
{
  flt_8EF8C0 = 24.0 * 0.5;
}

//----- (0070F540) --------------------------------------------------------  // acclient.c:802501
int sub_70F540()
{
  return atexit(nullsub_1705);
}

//----- (0070F550) --------------------------------------------------------  // acclient.c:802507
int sub_70F550()
{
  return atexit(nullsub_1706);
}

//----- (0070F560) --------------------------------------------------------  // acclient.c:802513
int sub_70F560()
{
  return atexit(nullsub_1707);
}

//----- (0070F570) --------------------------------------------------------  // acclient.c:802519
int sub_70F570()
{
  return atexit(nullsub_1708);
}

//----- (0070F580) --------------------------------------------------------  // acclient.c:802525
int sub_70F580()
{
  return atexit(nullsub_1704);
}

