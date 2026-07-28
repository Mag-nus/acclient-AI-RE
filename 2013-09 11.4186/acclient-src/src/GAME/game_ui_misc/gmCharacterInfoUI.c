/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCharacterInfoUI
   Object     : GAME\game_ui_misc\gmCharacterInfoUI.obj
   Functions  : 61
   Addresses  : 004B86F0 - 006F1FC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004B86F0) --------------------------------------------------------  // acclient.c:236410
void __thiscall gmCharacterInfoUI::PostInit(gmCharacterInfoUI *this)
{
  gmCharacterInfoUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pMainText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000011Du);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    125,
    &v1->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v1 = (gmCharacterInfoUI *)((char *)v1 + 1528);
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v1);
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD21E + 2), (NoticeHandler *)v1);
}

//----- (004B8750) --------------------------------------------------------  // acclient.c:236429
void __thiscall gmCharacterInfoUI::~gmCharacterInfoUI(gmCharacterInfoUI *this)
{
  UIElement_Field *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = (UIElement_Field *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCharacterInfoUI::vftable;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&gmCharacterInfoUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmCharacterInfoUI::vftable;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    125,
    &this->vfptr);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7B1ACC: using guessed type void (__thiscall *gmCharacterInfoUI::vftable[2])(gmCharacterInfoUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B1AD8: using guessed type bool (__thiscall *gmCharacterInfoUI::vftable)(DBCache *this);
// 7B1D80: using guessed type int (__thiscall *gmCharacterInfoUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004B87B0) --------------------------------------------------------  // acclient.c:236457
gmCharacterInfoUI *__thiscall gmCharacterInfoUI::DynamicCast(gmCharacterInfoUI *this, unsigned int i_eType)
{
  gmCharacterInfoUI *result; // eax@1

  result = this;
  if ( i_eType != 268435482 )
    result = (gmCharacterInfoUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004B87D0) --------------------------------------------------------  // acclient.c:236468
signed int gmCharacterInfoUI::GetUIElementType()
{
  return 268435482;
}

//----- (004B87E0) --------------------------------------------------------  // acclient.c:236474
char __thiscall gmCharacterInfoUI::UpdateInnateAttributeInfo(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // edi@1
  Attribute attrib; // [sp+8h] [bp-A0h]@1
  StringInfo siText; // [sp+18h] [bp-90h]@1

  v2 = this;
  attrib.vfptr = (PackObjVtbl *)&Attribute::vftable;
  attrib._level_from_cp = 0;
  *(_QWORD *)&attrib._init_level = 0i64;
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Innates, 268435457);
  CACQualities::InqAttribute(i_playerDesc, 1u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Strength, attrib._init_level);
  CACQualities::InqAttribute(i_playerDesc, 2u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Endurance, attrib._init_level);
  CACQualities::InqAttribute(i_playerDesc, 4u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Coordination, attrib._init_level);
  CACQualities::InqAttribute(i_playerDesc, 3u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Quickness, attrib._init_level);
  CACQualities::InqAttribute(i_playerDesc, 5u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Focus, attrib._init_level);
  CACQualities::InqAttribute(i_playerDesc, 6u, &attrib);
  StringInfo::AddVariable_Int(&siText, ID_Self, attrib._init_level);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  StringInfo::~StringInfo(&siText);
  return 1;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);

//----- (004B8930) --------------------------------------------------------  // acclient.c:236505
char __thiscall gmCharacterInfoUI::UpdateFakeSkills(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // esi@1
  int fishing_skill; // [sp+8h] [bp-98h]@1
  int rank; // [sp+Ch] [bp-94h]@1
  StringInfo siText; // [sp+10h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siText);
  rank = 1400;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0xB5u, &rank, 0, 0);
  StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Chess, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_ChessRank, rank);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  fishing_skill = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0xC0u, &fishing_skill, 0, 0);
  StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Fishing, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_FishingSkill, fishing_skill);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004B8A20) --------------------------------------------------------  // acclient.c:236529
char __thiscall gmCharacterInfoUI::UpdateLoad(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // ebx@1
  int v3; // esi@1
  int v4; // edi@3
  int v5; // esi@3
  __int64 _varValue_4; // ST08_8@5
  int encumb_augmentations; // [sp+14h] [bp-A4h]@1
  int encumb_val; // [sp+18h] [bp-A0h]@1
  float curLoad; // [sp+1Ch] [bp-9Ch]@1
  unsigned int strength; // [sp+20h] [bp-98h]@1
  int v12; // [sp+24h] [bp-94h]@5
  StringInfo siText; // [sp+28h] [bp-90h]@1

  v2 = this;
  CACQualities::InqLoad(i_playerDesc, &curLoad);
  strength = 10;
  CACQualities::InqAttribute(i_playerDesc, 1u, &strength, 0);
  encumb_val = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 5u, &encumb_val, 0, 0);
  encumb_augmentations = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0xE6u, &encumb_augmentations, 0, 0);
  v3 = EncumbranceSystem::EncumbranceCapacity(strength, encumb_augmentations);
  StringInfo::StringInfo(&siText);
  if ( curLoad >= 1.0 )
  {
    v4 = encumb_val - v3;
    v5 = 10 - (unsigned __int64)(EncumbranceSystem::LoadMod(curLoad) * 10.0);
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Load_Burdened, 268435457);
    StringInfo::AddVariable_Int(&siText, ID_Burden, v4);
    StringInfo::AddVariable_Int(&siText, ID_BurdenPenalty, 10 * v5);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Load_None, 268435457);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  if ( encumb_augmentations > 0 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Load_Augmentations, 268435457);
    HIDWORD(_varValue_4) = (unsigned __int64)encumb_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, _varValue_4);
    v12 = 20 * encumb_augmentations;
    StringInfo::AddVariable_Float(&siText, ID_AdditionalLoad, (double)(20 * encumb_augmentations), 0);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004B8BE0) --------------------------------------------------------  // acclient.c:236581
void __userpurge gmCharacterInfoUI::gmCharacterInfoUI(gmCharacterInfoUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCharacterInfoUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCharacterInfoUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmCharacterInfoUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmCharacterInfoUI::vftable;
  v4->m_pMainText = 0;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7B1ACC: using guessed type void (__thiscall *gmCharacterInfoUI::vftable[2])(gmCharacterInfoUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B1AD8: using guessed type bool (__thiscall *gmCharacterInfoUI::vftable)(DBCache *this);
// 7B1D80: using guessed type int (__thiscall *gmCharacterInfoUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004B8C40) --------------------------------------------------------  // acclient.c:236601
gmCharacterInfoUI *__thiscall gmCharacterInfoUI::scalar_deleting_destructor(gmCharacterInfoUI *this, unsigned int a2)
{
  gmCharacterInfoUI *v2; // esi@1

  v2 = this;
  gmCharacterInfoUI::~gmCharacterInfoUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B8C60) --------------------------------------------------------  // acclient.c:236613
void __usercall gmCharacterInfoUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCharacterInfoUI *v3; // eax@1

  v3 = (gmCharacterInfoUI *)operator new(0x604u);
  if ( v3 )
    gmCharacterInfoUI::gmCharacterInfoUI(v3, a1, _layout, _full_desc);
}

//----- (004B8C90) --------------------------------------------------------  // acclient.c:236623
void __cdecl gmCharacterInfoUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000001Au,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCharacterInfoUI::Create);
}

//----- (004B8CB0) --------------------------------------------------------  // acclient.c:236631
char __thiscall gmCharacterInfoUI::UpdatePlayerBirthAgeDeaths(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // ebx@1
  CBaseQualities *v3; // esi@1
  struct tm *v4; // eax@2
  int v5; // ecx@2
  int v6; // esi@5
  volatile LONG *v7; // edi@5
  int v8; // edx@14
  unsigned int v10; // [sp-8h] [bp-540h]@8
  int v11; // [sp-4h] [bp-53Ch]@2
  unsigned int num_deaths; // [sp+Ch] [bp-52Ch]@5
  int age; // [sp+10h] [bp-528h]@3
  int birthDate; // [sp+14h] [bp-524h]@1
  StringInfo siTimesText; // [sp+18h] [bp-520h]@1
  StringInfo siPlayedText; // [sp+A8h] [bp-490h]@4
  char time[1024]; // [sp+138h] [bp-400h]@2

  v2 = this;
  StringInfo::StringInfo(&siTimesText);
  v3 = (CBaseQualities *)&i_playerDesc->vfptr;
  birthDate = 0;
  if ( CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x62u, &birthDate, 0, 0) )
  {
    v4 = _localtime(&birthDate);
    _strftime(time, 0x400u, "%c", v4);
    StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Birth, 268435457);
    v11 = v5;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v11, time);
    StringInfo::AddVariable_String(&siTimesText, ID_BirthDate, (PStringBase<char>)v11);
    v11 = (int)&siTimesText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siTimesText);
  }
  age = 0;
  if ( CBaseQualities::InqInt(v3, 0x7Du, &age, 0, 0) )
  {
    StringInfo::StringInfo(&siPlayedText);
    TimeUtils::QueryDuration(age, &siPlayedText);
    StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Played, 268435457);
    StringInfo::AddVariable_StringInfo(&siTimesText, ID_TimePlayed, &siPlayedText);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siTimesText);
    StringInfo::~StringInfo(&siPlayedText);
  }
  num_deaths = 0;
  CBaseQualities::InqInt(v3, 0x2Bu, (int *)&num_deaths, 0, 0);
  v6 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  v7 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v11 = 268435457;
  if ( num_deaths )
  {
    if ( num_deaths == 1 )
    {
      StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Deaths_One, v11);
    }
    else if ( num_deaths == 2 )
    {
      StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Deaths_Two, v11);
    }
    else
    {
      StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Deaths_Many, v11);
      StringInfo::AddVariable_Int(&siTimesText, ID_NumberOfDeaths, v10);
    }
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siTimesText, ID_CharacterInfo_Deaths_None, v11);
  }
  v11 = (int)&siTimesText;
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siTimesText);
  if ( !InterlockedDecrement(v7) && v6 )
  {
    v8 = *(_DWORD *)v6;
    v11 = 1;
    (*(void (__thiscall **)(int, signed int))v8)(v6, 1);
  }
  StringInfo::~StringInfo(&siTimesText);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004B8EB0) --------------------------------------------------------  // acclient.c:236714
char __thiscall gmCharacterInfoUI::UpdateEnduranceInfo(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // edi@1
  unsigned int v3; // eax@1
  const char *v4; // esi@2
  unsigned int v5; // ecx@11
  unsigned int v6; // eax@11
  const char *v7; // eax@12
  bool v8; // cf@19
  bool v9; // zf@19
  unsigned int v11; // [sp-4h] [bp-A4h]@11
  unsigned int uStrength; // [sp+8h] [bp-98h]@1
  unsigned int uEndurance; // [sp+Ch] [bp-94h]@1
  StringInfo siText; // [sp+10h] [bp-90h]@1

  v2 = this;
  CACQualities::InqAttribute(i_playerDesc, 1u, &uStrength, 1);
  CACQualities::InqAttribute(i_playerDesc, 2u, &uEndurance, 1);
  StringInfo::StringInfo(&siText);
  v3 = uEndurance + uStrength;
  if ( uEndurance + uStrength > 0xC8 )
  {
    if ( v3 > 0x104 )
    {
      if ( v3 > 0x140 )
      {
        if ( v3 > 0x17C )
        {
          v4 = "Resilient";
          if ( v3 > 0x1B8 )
            v4 = "Indomitable";
        }
        else
        {
          v4 = "Hardy";
        }
      }
      else
      {
        v4 = "Mediocre";
      }
    }
    else
    {
      v4 = "Poor";
    }
  }
  else
  {
    v4 = "None";
  }
  StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Resists, 268435457);
  v11 = v5;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v11, v4);
  StringInfo::AddVariable_String(&siText, ID_Resists, (PStringBase<char>)v11);
  v6 = uStrength + 2 * uEndurance;
  if ( v6 > 0xC8 )
  {
    if ( v6 > 0x15A )
    {
      if ( v6 > 0x1D6 )
      {
        if ( v6 > 0x244 )
        {
          v8 = v6 < 0x2B2;
          v9 = v6 == 690;
          v7 = "Resilient";
          if ( !v8 && !v9 )
            v7 = "Indomitable";
        }
        else
        {
          v7 = "Hardy";
        }
      }
      else
      {
        v7 = "Mediocre";
      }
    }
    else
    {
      v7 = "Poor";
    }
  }
  else
  {
    v7 = "None";
  }
  v11 = uStrength;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v11, v7);
  StringInfo::AddVariable_String(&siText, ID_RegenerationBonus, (PStringBase<char>)v11);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004B9000) --------------------------------------------------------  // acclient.c:236812
char __thiscall gmCharacterInfoUI::UpdateAugmentations(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // esi@1
  CBaseQualities *v3; // edi@1
  int v4; // ebx@1
  int v5; // ecx@2
  int v6; // ecx@15
  int v7; // ecx@24
  unsigned int v8; // eax@33
  unsigned int v9; // eax@36
  unsigned int v10; // eax@37
  int v11; // ebx@38
  unsigned int v12; // eax@41
  unsigned int v13; // eax@42
  int v14; // ebx@43
  unsigned int v15; // eax@46
  unsigned int v16; // eax@47
  int v17; // ebx@48
  unsigned int v18; // eax@51
  unsigned int v19; // eax@52
  unsigned int v20; // eax@54
  unsigned int v21; // eax@56
  unsigned int v22; // eax@58
  unsigned int v23; // eax@60
  unsigned int v24; // eax@62
  unsigned int v25; // eax@64
  unsigned int v26; // eax@66
  unsigned int v27; // eax@68
  unsigned int v28; // eax@70
  unsigned int v29; // eax@72
  unsigned int v30; // eax@74
  unsigned int v31; // eax@76
  unsigned int v32; // eax@78
  unsigned int v33; // eax@80
  unsigned int v34; // eax@82
  unsigned int v35; // eax@84
  unsigned int v36; // eax@86
  unsigned int v37; // eax@88
  unsigned int v38; // eax@90
  unsigned int v39; // eax@92
  unsigned int v40; // eax@94
  unsigned int v41; // eax@96
  unsigned int v42; // eax@98
  unsigned int v43; // eax@100
  unsigned int v44; // eax@102
  unsigned int v45; // eax@104
  unsigned int v46; // eax@106
  unsigned int v47; // eax@108
  unsigned int v48; // eax@110
  unsigned int v49; // eax@112
  unsigned int v50; // eax@114
  unsigned int v51; // eax@116
  unsigned int v52; // eax@118
  unsigned int v53; // eax@120
  unsigned int v54; // eax@122
  unsigned int v55; // eax@124
  unsigned int v56; // eax@126
  unsigned int v57; // eax@128
  unsigned int v58; // eax@130
  unsigned int v59; // eax@132
  unsigned int v60; // eax@134
  unsigned int v61; // eax@136
  unsigned int v62; // eax@138
  unsigned int v63; // eax@140
  unsigned int v64; // eax@142
  unsigned int v65; // eax@144
  unsigned int v66; // eax@146
  unsigned int v67; // eax@148
  unsigned int v68; // eax@150
  unsigned int v69; // eax@152
  __int64 v71; // [sp-8h] [bp-B4h]@36
  __int64 v72; // [sp-8h] [bp-B4h]@47
  __int64 v73; // [sp-8h] [bp-B4h]@51
  __int64 v74; // [sp-8h] [bp-B4h]@124
  __int64 v75; // [sp-8h] [bp-B4h]@126
  __int64 v76; // [sp-8h] [bp-B4h]@128
  __int64 v77; // [sp-8h] [bp-B4h]@130
  __int64 v78; // [sp-8h] [bp-B4h]@132
  __int64 v79; // [sp-8h] [bp-B4h]@134
  __int64 v80; // [sp-8h] [bp-B4h]@136
  __int64 v81; // [sp-8h] [bp-B4h]@138
  __int64 v82; // [sp-8h] [bp-B4h]@140
  __int64 v83; // [sp-8h] [bp-B4h]@142
  __int64 v84; // [sp-8h] [bp-B4h]@144
  __int64 v85; // [sp-8h] [bp-B4h]@146
  int num_augmentations; // [sp+10h] [bp-9Ch]@67
  int base_augs; // [sp+14h] [bp-98h]@1
  int mastery; // [sp+18h] [bp-94h]@1
  StringInfo siText; // [sp+1Ch] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siText);
  v3 = (CBaseQualities *)&i_playerDesc->vfptr;
  base_augs = 0;
  v4 = 0;
  mastery = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x162u, &mastery, 0, 0);
  if ( mastery > 0 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Mastery_Melee, 268435457);
    switch ( mastery )
    {
      case 1:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Unarmed Weapons");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 2:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Swords");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 3:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Axes");
        goto LABEL_12;
      case 4:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Maces");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 5:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Spears");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 6:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Daggers");
        goto LABEL_12;
      case 7:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Staves");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 11:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Two Handed Weapons");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      default:
        HIDWORD(v71) = v5;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Unknown");
LABEL_12:
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
    }
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  mastery = 0;
  CBaseQualities::InqInt(v3, 0x163u, &mastery, 0, 0);
  if ( mastery > 0 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Mastery_Ranged, 268435457);
    switch ( mastery )
    {
      case 8:
        HIDWORD(v71) = v6;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Bows");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 9:
        HIDWORD(v71) = v6;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Crossbows");
        goto LABEL_21;
      case 10:
        HIDWORD(v71) = v6;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Thrown Weapons");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      case 12:
        HIDWORD(v71) = v6;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Magical Spells");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
      default:
        HIDWORD(v71) = v6;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Unknown");
LABEL_21:
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
        break;
    }
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  mastery = 0;
  CBaseQualities::InqInt(v3, 0x16Au, &mastery, 0, 0);
  if ( mastery > 0 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_CharacterInfo_Mastery_Summoning, 268435457);
    HIDWORD(v71) = v7;
    if ( mastery != 1 )
    {
      if ( mastery == 2 )
      {
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Necromancer");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
      }
      else
      {
        if ( mastery != 3 )
        {
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Unknown");
LABEL_31:
          StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
          goto LABEL_32;
        }
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Naturalist");
        StringInfo::AddVariable_String(&siText, ID_Mastery, HIDWORD(v71));
      }
LABEL_32:
      UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
      goto LABEL_33;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v71 + 1, "Primalist");
    goto LABEL_31;
  }
LABEL_33:
  HIDWORD(v71) = 268435457;
  v8 = compute_str_hash("ID_CharacterInfo_Luminance_Header");
  StringInfo::SetStringIDandTableEnum(&siText, v8, SHIDWORD(v71));
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x14Du, &base_augs, 0, 0);
  if ( base_augs <= 5 )
  {
    if ( base_augs <= 0 )
      goto LABEL_38;
  }
  else
  {
    v4 = base_augs - 5;
    base_augs = 5;
  }
  HIDWORD(v71) = 268435457;
  v9 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Damage");
  StringInfo::SetStringIDandTableEnum(&siText, v9, SHIDWORD(v71));
  HIDWORD(v71) = (unsigned __int64)base_augs >> 32;
  StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v71);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  if ( v4 > 0 )
  {
    HIDWORD(v71) = 268435457;
    v10 = compute_str_hash("ID_CharacterInfo_Luminance_Spec_Damage");
    StringInfo::SetStringIDandTableEnum(&siText, v10, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v4);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
LABEL_38:
  base_augs = 0;
  v11 = 0;
  CBaseQualities::InqInt(v3, 0x14Eu, &base_augs, 0, 0);
  if ( base_augs <= 5 )
  {
    if ( base_augs <= 0 )
      goto LABEL_43;
  }
  else
  {
    v11 = base_augs - 5;
    base_augs = 5;
  }
  HIDWORD(v71) = 268435457;
  v12 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Reduction");
  StringInfo::SetStringIDandTableEnum(&siText, v12, SHIDWORD(v71));
  StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  if ( v11 > 0 )
  {
    HIDWORD(v71) = 268435457;
    v13 = compute_str_hash("ID_CharacterInfo_Luminance_Spec_Reduction");
    StringInfo::SetStringIDandTableEnum(&siText, v13, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v11);
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
LABEL_43:
  base_augs = 0;
  v14 = 0;
  CBaseQualities::InqInt(v3, 0x14Fu, &base_augs, 0, 0);
  if ( base_augs <= 5 )
  {
    if ( base_augs <= 0 )
      goto LABEL_48;
  }
  else
  {
    v14 = base_augs - 5;
    base_augs = 5;
  }
  HIDWORD(v71) = 268435457;
  v15 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Crit_Damage");
  StringInfo::SetStringIDandTableEnum(&siText, v15, SHIDWORD(v71));
  StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
  HIDWORD(v71) = &siText;
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  if ( v14 > 0 )
  {
    HIDWORD(v71) = 268435457;
    v16 = compute_str_hash("ID_CharacterInfo_Luminance_Spec_Crit_Damage");
    StringInfo::SetStringIDandTableEnum(&siText, v16, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)v14 >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v72);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
LABEL_48:
  base_augs = 0;
  v17 = 0;
  CBaseQualities::InqInt(v3, 0x150u, &base_augs, 0, 0);
  if ( base_augs <= 5 )
  {
    if ( base_augs <= 0 )
      goto LABEL_53;
  }
  else
  {
    v17 = base_augs - 5;
    base_augs = 5;
  }
  HIDWORD(v71) = 268435457;
  v18 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Crit_Reduction");
  StringInfo::SetStringIDandTableEnum(&siText, v18, SHIDWORD(v71));
  HIDWORD(v71) = (unsigned __int64)base_augs >> 32;
  StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v73);
  UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  if ( v17 > 0 )
  {
    HIDWORD(v71) = 268435457;
    v19 = compute_str_hash("ID_CharacterInfo_Luminance_Spec_Crit_Reduction");
    StringInfo::SetStringIDandTableEnum(&siText, v19, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v17);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
LABEL_53:
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x152u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v20 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Surge_Chance");
    StringInfo::SetStringIDandTableEnum(&siText, v20, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x153u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v21 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Mana_Use");
    StringInfo::SetStringIDandTableEnum(&siText, v21, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, 5 * base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x154u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v22 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Mana_Gain");
    StringInfo::SetStringIDandTableEnum(&siText, v22, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, 5 * base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x156u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v23 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Healing");
    StringInfo::SetStringIDandTableEnum(&siText, v23, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x157u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v24 = compute_str_hash("ID_CharacterInfo_Luminance_Base_Skilled_Craft");
    StringInfo::SetStringIDandTableEnum(&siText, v24, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x158u, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v25 = compute_str_hash("ID_CharacterInfo_Luminance_Spec_Skilled_Spec");
    StringInfo::SetStringIDandTableEnum(&siText, v25, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, 2 * base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  base_augs = 0;
  CBaseQualities::InqInt(v3, 0x16Du, &base_augs, 0, 0);
  if ( base_augs > 0 )
  {
    HIDWORD(v71) = 268435457;
    v26 = compute_str_hash("ID_CharacterInfo_Luminance_Base_All_Skills");
    StringInfo::SetStringIDandTableEnum(&siText, v26, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, base_augs);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDAu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v27 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Strength");
    StringInfo::SetStringIDandTableEnum(&siText, v27, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDBu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v28 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Endurance");
    StringInfo::SetStringIDandTableEnum(&siText, v28, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDCu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v29 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Coordination");
    StringInfo::SetStringIDandTableEnum(&siText, v29, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDDu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v30 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Quickness");
    StringInfo::SetStringIDandTableEnum(&siText, v30, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDEu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v31 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Focus");
    StringInfo::SetStringIDandTableEnum(&siText, v31, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xDFu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v32 = compute_str_hash("ID_CharacterInfo_Augmentation_Attribute_Self");
    StringInfo::SetStringIDandTableEnum(&siText, v32, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF0u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v33 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Slash");
    StringInfo::SetStringIDandTableEnum(&siText, v33, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF1u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v34 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Pierce");
    StringInfo::SetStringIDandTableEnum(&siText, v34, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF2u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v35 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Blunt");
    StringInfo::SetStringIDandTableEnum(&siText, v35, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF3u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v36 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Acid");
    StringInfo::SetStringIDandTableEnum(&siText, v36, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x147u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v37 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Nether");
    StringInfo::SetStringIDandTableEnum(&siText, v37, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF4u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v38 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Fire");
    StringInfo::SetStringIDandTableEnum(&siText, v38, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF5u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v39 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Frost");
    StringInfo::SetStringIDandTableEnum(&siText, v39, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xF6u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v40 = compute_str_hash("ID_CharacterInfo_Augmentation_Resist_Lightning");
    StringInfo::SetStringIDandTableEnum(&siText, v40, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE0u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v41 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_Salvaging");
    StringInfo::SetStringIDandTableEnum(&siText, v41, SHIDWORD(v71));
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE1u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v42 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_ItemTinkering");
    StringInfo::SetStringIDandTableEnum(&siText, v42, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE2u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v43 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_ArmorTinkering");
    StringInfo::SetStringIDandTableEnum(&siText, v43, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE3u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v44 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_MagicItemTinkering");
    StringInfo::SetStringIDandTableEnum(&siText, v44, SHIDWORD(v71));
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE4u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v45 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_WeaponTinkering");
    StringInfo::SetStringIDandTableEnum(&siText, v45, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x125u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v46 = compute_str_hash("ID_CharacterInfo_Augmentation_Spec_Gearcraft");
    StringInfo::SetStringIDandTableEnum(&siText, v46, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE5u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v47 = compute_str_hash("ID_CharacterInfo_Augmentation_ExtraPackSlot");
    StringInfo::SetStringIDandTableEnum(&siText, v47, SHIDWORD(v71));
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE6u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v48 = compute_str_hash("ID_CharacterInfo_Augmentation_IncreasedCarryingCapacity");
    StringInfo::SetStringIDandTableEnum(&siText, v48, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE7u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v49 = compute_str_hash("ID_CharacterInfo_Augmentation_LessDeathItemLoss");
    StringInfo::SetStringIDandTableEnum(&siText, v49, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE8u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v50 = compute_str_hash("ID_CharacterInfo_Augmentation_SpellsRemainPastDeath");
    StringInfo::SetStringIDandTableEnum(&siText, v50, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xE9u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v51 = compute_str_hash("ID_CharacterInfo_Augmentation_CriticalDefense");
    StringInfo::SetStringIDandTableEnum(&siText, v51, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xEAu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v52 = compute_str_hash("ID_CharacterInfo_Augmentation_BonusXP");
    StringInfo::SetStringIDandTableEnum(&siText, v52, SHIDWORD(v71));
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xEBu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v53 = compute_str_hash("ID_CharacterInfo_Augmentation_BonusSalvage");
    StringInfo::SetStringIDandTableEnum(&siText, v53, SHIDWORD(v71));
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, num_augmentations);
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xECu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v54 = compute_str_hash("ID_CharacterInfo_Augmentation_BonusImbueChance");
    StringInfo::SetStringIDandTableEnum(&siText, v54, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xEDu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v55 = compute_str_hash("ID_CharacterInfo_Augmentation_FasterRegen");
    StringInfo::SetStringIDandTableEnum(&siText, v55, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v74);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0xEEu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v56 = compute_str_hash("ID_CharacterInfo_Augmentation_IncreasedSpellDuration");
    StringInfo::SetStringIDandTableEnum(&siText, v56, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v75);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x126u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v57 = compute_str_hash("ID_CharacterInfo_Augmentation_Infused_CreatureMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v57, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v76);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x127u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v58 = compute_str_hash("ID_CharacterInfo_Augmentation_Infused_ItemMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v58, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v77);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x128u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v59 = compute_str_hash("ID_CharacterInfo_Augmentation_Infused_LifeMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v59, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v78);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x129u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v60 = compute_str_hash("ID_CharacterInfo_Augmentation_Infused_WarMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v60, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v79);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x148u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v61 = compute_str_hash("ID_CharacterInfo_Augmentation_Infused_VoidMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v61, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v80);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x12Cu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v62 = compute_str_hash("ID_CharacterInfo_Augmentation_SkilledMelee");
    StringInfo::SetStringIDandTableEnum(&siText, v62, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v81);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x12Du, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v63 = compute_str_hash("ID_CharacterInfo_Augmentation_SkilledMissile");
    StringInfo::SetStringIDandTableEnum(&siText, v63, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v82);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x12Eu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v64 = compute_str_hash("ID_CharacterInfo_Augmentation_SkilledMagic");
    StringInfo::SetStringIDandTableEnum(&siText, v64, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v83);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x135u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v65 = compute_str_hash("ID_CharacterInfo_Augmentation_DamageBonus");
    StringInfo::SetStringIDandTableEnum(&siText, v65, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v84);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x136u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v66 = compute_str_hash("ID_CharacterInfo_Augmentation_DamageResist");
    StringInfo::SetStringIDandTableEnum(&siText, v66, SHIDWORD(v71));
    HIDWORD(v71) = (unsigned __int64)num_augmentations >> 32;
    StringInfo::AddVariable_Int(&siText, ID_NumAugmentations, v85);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x12Au, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v67 = compute_str_hash("ID_CharacterInfo_Augmentation_CriticalExpertise");
    StringInfo::SetStringIDandTableEnum(&siText, v67, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x12Bu, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v68 = compute_str_hash("ID_CharacterInfo_Augmentation_CriticalPower");
    StringInfo::SetStringIDandTableEnum(&siText, v68, SHIDWORD(v71));
    HIDWORD(v71) = &siText;
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  num_augmentations = 0;
  CBaseQualities::InqInt(v3, 0x146u, &num_augmentations, 0, 0);
  if ( num_augmentations > 0 )
  {
    HIDWORD(v71) = 268435457;
    v69 = compute_str_hash("ID_CharacterInfo_Augmentation_JackOfAllTrades");
    StringInfo::SetStringIDandTableEnum(&siText, v69, SHIDWORD(v71));
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siText);
  }
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004BA790) --------------------------------------------------------  // acclient.c:237657
char __thiscall gmCharacterInfoUI::Update(gmCharacterInfoUI *this, CACQualities *i_playerDesc)
{
  gmCharacterInfoUI *v2; // esi@1
  char result; // al@2
  char *v4; // edi@3
  PStringBase<unsigned short> *v5; // eax@6
  char *v6; // edi@6
  char *v7; // edi@9
  PStringBase<unsigned short> _value; // [sp+8h] [bp-124h]@3
  StringInfo siSpaceText; // [sp+Ch] [bp-120h]@9
  StringInfo siBlankText; // [sp+9Ch] [bp-90h]@3

  v2 = this;
  if ( (*((_DWORD *)&this->0 + 41) >> 1) & 1 )
  {
    StringInfo::StringInfo(&siBlankText);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, &word_794320);
    StringInfo::SetLiteralValue(&siBlankText, &_value, 1);
    v4 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = StringInfo::GetString(&siBlankText, &_value, 0);
    UIElement_Text::SetText(v2->m_pMainText, v5);
    v6 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    StringInfo::StringInfo(&siSpaceText);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"\n");
    StringInfo::SetLiteralValue(&siSpaceText, &_value, 1);
    v7 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    gmCharacterInfoUI::UpdatePlayerBirthAgeDeaths(v2, i_playerDesc);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siSpaceText);
    gmCharacterInfoUI::UpdateEnduranceInfo(v2, i_playerDesc);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siSpaceText);
    gmCharacterInfoUI::UpdateInnateAttributeInfo(v2, i_playerDesc);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siSpaceText);
    gmCharacterInfoUI::UpdateFakeSkills(v2, i_playerDesc);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siSpaceText);
    gmCharacterInfoUI::UpdateAugmentations(v2, i_playerDesc);
    UIElement_Text::AppendStringInfo(v2->m_pMainText, &siSpaceText);
    gmCharacterInfoUI::UpdateLoad(v2, i_playerDesc);
    StringInfo::~StringInfo(&siSpaceText);
    StringInfo::~StringInfo(&siBlankText);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004BA930) --------------------------------------------------------  // acclient.c:237715
void __thiscall gmCharacterInfoUI::RecvNotice_PlayerDescReceived(gmCharacterInfoUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmCharacterInfoUI::Update((gmCharacterInfoUI *)((char *)this - 1528), i_playerDesc);
}

//----- (004BA950) --------------------------------------------------------  // acclient.c:237721
char __thiscall gmCharacterInfoUI::Update(gmCharacterInfoUI *this)
{
  gmCharacterInfoUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // esi@2
  int v4; // ebx@4
  PlayerDesc *v5; // esi@6
  char v7; // bl@10
  int v8; // [sp-8h] [bp-2Ch]@2
  Interface *_rpInterface; // [sp+10h] [bp-14h]@2
  TResult result; // [sp+14h] [bp-10h]@2
  char v11; // [sp+18h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@2

  v1 = this;
  if ( !((*((_DWORD *)&this->0 + 41) >> 1) & 1) )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_9, &_rpInterface);
  v3 = _rpInterface;
  v8 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = gmCharacterInfoUI::Update(v1, (CACQualities *)&playerDesc.m_pInterface->vfptr);
  v5->vfptr->Release((Interface *)v5);
  return v7;
}

//----- (004BAA00) --------------------------------------------------------  // acclient.c:237764
int __thiscall gmCharacterInfoUI::ListenToElementMessage(gmCharacterInfoUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 24 && (gmCharacterInfoUI *)i_rMsg->pElement == this && i_rMsg->dwParam1 )
    gmCharacterInfoUI::Update(this);
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004BAA30) --------------------------------------------------------  // acclient.c:237775
void __thiscall gmCharacterInfoUI::RecvNotice_LoadChanged(gmCharacterInfoUI *this, float fNewLoad)
{
  gmCharacterInfoUI::Update((gmCharacterInfoUI *)((char *)this - 1528));
}

//----- (004BAA40) --------------------------------------------------------  // acclient.c:237781
void __thiscall gmCharacterInfoUI::OnQualityChanged(gmCharacterInfoUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmCharacterInfoUI::Update((gmCharacterInfoUI *)((char *)this - 1532));
}

//----- (006F1AF0) --------------------------------------------------------  // acclient.c:773979
void _E91_79()
{
  outside_val_71 = 1000.0 + 1.0;
}

//----- (006F1B10) --------------------------------------------------------  // acclient.c:773985
void _E93_55()
{
  block_length_71 = 24.0 * 8.0;
}

//----- (006F1B30) --------------------------------------------------------  // acclient.c:773991
void _E95_55()
{
  half_square_length_71 = 24.0 * 0.5;
}

//----- (006F1B50) --------------------------------------------------------  // acclient.c:773997
int _E97_80()
{
  return atexit(_E98_92);
}

//----- (006F1B60) --------------------------------------------------------  // acclient.c:774003
int _E100_73()
{
  return atexit(nullsub_800);
}

//----- (006F1B70) --------------------------------------------------------  // acclient.c:774009
int _E103_65()
{
  return atexit(_E104_80);
}

//----- (006F1B80) --------------------------------------------------------  // acclient.c:774015
unsigned int _E106_49()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Birth");
  ID_CharacterInfo_Birth = result;
  return result;
}

//----- (006F1BA0) --------------------------------------------------------  // acclient.c:774025
unsigned int _E108_36()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Played");
  ID_CharacterInfo_Played = result;
  return result;
}

//----- (006F1BC0) --------------------------------------------------------  // acclient.c:774035
unsigned int _E110_27()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Deaths_None");
  ID_CharacterInfo_Deaths_None = result;
  return result;
}

//----- (006F1BE0) --------------------------------------------------------  // acclient.c:774045
unsigned int _E112_44()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Deaths_One");
  ID_CharacterInfo_Deaths_One = result;
  return result;
}

//----- (006F1C00) --------------------------------------------------------  // acclient.c:774055
unsigned int _E114_28()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Deaths_Two");
  ID_CharacterInfo_Deaths_Two = result;
  return result;
}

//----- (006F1C20) --------------------------------------------------------  // acclient.c:774065
unsigned int _E116_8()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Deaths_Many");
  ID_CharacterInfo_Deaths_Many = result;
  return result;
}

//----- (006F1C40) --------------------------------------------------------  // acclient.c:774075
unsigned int _E118_38()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Resists");
  ID_CharacterInfo_Resists = result;
  return result;
}

//----- (006F1C60) --------------------------------------------------------  // acclient.c:774085
unsigned int _E120_26()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Innates");
  ID_CharacterInfo_Innates = result;
  return result;
}

//----- (006F1C80) --------------------------------------------------------  // acclient.c:774095
unsigned int _E122_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Chess");
  ID_CharacterInfo_Chess = result;
  return result;
}

//----- (006F1CA0) --------------------------------------------------------  // acclient.c:774105
unsigned int _E124_37()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Fishing");
  ID_CharacterInfo_Fishing = result;
  return result;
}

//----- (006F1CC0) --------------------------------------------------------  // acclient.c:774115
unsigned int _E126_19()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Load_None");
  ID_CharacterInfo_Load_None = result;
  return result;
}

//----- (006F1CE0) --------------------------------------------------------  // acclient.c:774125
unsigned int _E128_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Load_Burdened");
  ID_CharacterInfo_Load_Burdened = result;
  return result;
}

//----- (006F1D00) --------------------------------------------------------  // acclient.c:774135
unsigned int _E130_26()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Load_Augmentations");
  ID_CharacterInfo_Load_Augmentations = result;
  return result;
}

//----- (006F1D20) --------------------------------------------------------  // acclient.c:774145
unsigned int _E132_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("DATE");
  ID_BirthDate = result;
  return result;
}

//----- (006F1D40) --------------------------------------------------------  // acclient.c:774155
unsigned int _E134_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("DURATION");
  ID_TimePlayed = result;
  return result;
}

//----- (006F1D60) --------------------------------------------------------  // acclient.c:774165
unsigned int _E136_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("DEATHS");
  ID_NumberOfDeaths = result;
  return result;
}

//----- (006F1D80) --------------------------------------------------------  // acclient.c:774175
unsigned int _E138_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("RESIST");
  ID_Resists = result;
  return result;
}

//----- (006F1DA0) --------------------------------------------------------  // acclient.c:774185
unsigned int _E140_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("REGEN");
  ID_RegenerationBonus = result;
  return result;
}

//----- (006F1DC0) --------------------------------------------------------  // acclient.c:774195
unsigned int _E142_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("STRENGTH");
  ID_Strength = result;
  return result;
}

//----- (006F1DE0) --------------------------------------------------------  // acclient.c:774205
unsigned int _E144_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ENDURANCE");
  ID_Endurance = result;
  return result;
}

//----- (006F1E00) --------------------------------------------------------  // acclient.c:774215
unsigned int _E146_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("COORDINATION");
  ID_Coordination = result;
  return result;
}

//----- (006F1E20) --------------------------------------------------------  // acclient.c:774225
unsigned int _E148_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("QUICKNESS");
  ID_Quickness = result;
  return result;
}

//----- (006F1E40) --------------------------------------------------------  // acclient.c:774235
unsigned int _E150_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("FOCUS");
  ID_Focus = result;
  return result;
}

//----- (006F1E60) --------------------------------------------------------  // acclient.c:774245
unsigned int _E152_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("SELF");
  ID_Self = result;
  return result;
}

//----- (006F1E80) --------------------------------------------------------  // acclient.c:774255
unsigned int _E154_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("NUM_AUGMENTATIONS");
  ID_NumAugmentations = result;
  return result;
}

//----- (006F1EA0) --------------------------------------------------------  // acclient.c:774265
unsigned int _E156_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("CHESS");
  ID_ChessRank = result;
  return result;
}

//----- (006F1EC0) --------------------------------------------------------  // acclient.c:774275
unsigned int _E158_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("FISHING");
  ID_FishingSkill = result;
  return result;
}

//----- (006F1EE0) --------------------------------------------------------  // acclient.c:774285
unsigned int _E160_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("BURDEN");
  ID_Burden = result;
  return result;
}

//----- (006F1F00) --------------------------------------------------------  // acclient.c:774295
unsigned int _E162_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PENALTY");
  ID_BurdenPenalty = result;
  return result;
}

//----- (006F1F20) --------------------------------------------------------  // acclient.c:774305
unsigned int _E164_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ADDITIONAL_LOAD");
  ID_AdditionalLoad = result;
  return result;
}

//----- (006F1F40) --------------------------------------------------------  // acclient.c:774315
unsigned int _E166_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Mastery_Melee");
  ID_CharacterInfo_Mastery_Melee = result;
  return result;
}

//----- (006F1F60) --------------------------------------------------------  // acclient.c:774325
unsigned int _E168_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Mastery_Ranged");
  ID_CharacterInfo_Mastery_Ranged = result;
  return result;
}

//----- (006F1F80) --------------------------------------------------------  // acclient.c:774335
unsigned int _E170_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterInfo_Mastery_Summoning");
  ID_CharacterInfo_Mastery_Summoning = result;
  return result;
}

//----- (006F1FA0) --------------------------------------------------------  // acclient.c:774345
unsigned int _E172_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("MASTERY");
  ID_Mastery = result;
  return result;
}

//----- (006F1FC0) --------------------------------------------------------  // acclient.c:774355
int sub_6F1FC0()
{
  return atexit(nullsub_798);
}

