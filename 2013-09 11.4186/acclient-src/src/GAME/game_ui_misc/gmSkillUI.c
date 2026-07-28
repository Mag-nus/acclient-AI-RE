/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSkillUI
   Object     : GAME\game_ui_misc\gmSkillUI.obj
   Functions  : 48
   Addresses  : 0049ADB0 - 006EF240 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049ADB0) --------------------------------------------------------  // acclient.c:212606
void __thiscall Skill::Skill(Skill *this)
{
  this->vfptr = (PackObjVtbl *)&Skill::vftable;
  this->_sac = 0;
  this->_pp = 0;
  this->_init_level = 0;
  this->_level_from_pp = 0;
  this->_resistance_of_last_check = 0;
  *(_QWORD *)&this->_last_used_time = 0i64;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (0049ADD0) --------------------------------------------------------  // acclient.c:212619
void __userpurge gmSkillUI::gmSkillUI(gmSkillUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSkillUI *v4; // esi@1

  v4 = this;
  gmStatManagementUI::gmStatManagementUI((gmStatManagementUI *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSkillUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSkillUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmStatManagementUI::vftable;
  v4->m_SelectedSkill = 0;
  v4->m_SelectedIndex = -1;
}
// 7A7420: using guessed type bool (__thiscall *gmSkillUI::vftable)(DBCache *this);
// 7A76C8: using guessed type int (__thiscall *gmSkillUI::vftable)(void *, char);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (0049AE20) --------------------------------------------------------  // acclient.c:212636
gmSkillUI *__thiscall gmSkillUI::DynamicCast(gmSkillUI *this, unsigned int i_eType)
{
  gmSkillUI *result; // eax@1

  result = this;
  if ( i_eType != 268435499 )
    result = (gmSkillUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0049AE40) --------------------------------------------------------  // acclient.c:212647
signed int gmSkillUI::GetUIElementType()
{
  return 268435499;
}

//----- (0049AE50) --------------------------------------------------------  // acclient.c:212653
void __thiscall gmSkillUI::PostInit(gmSkillUI *this)
{
  gmSkillUI *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  gmStatManagementUI::PostInit((gmStatManagementUI *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100097u, (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100097u, 0);
}

//----- (0049AE90) --------------------------------------------------------  // acclient.c:212668
void __usercall gmSkillUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSkillUI *v3; // eax@1

  v3 = (gmSkillUI *)operator new(0x644u);
  if ( v3 )
    gmSkillUI::gmSkillUI(v3, a1, _layout, _full_desc);
}

//----- (0049AEC0) --------------------------------------------------------  // acclient.c:212678
int __thiscall gmSkillUI::GetCostToRaise10(gmSkillUI *this, CACQualities *i_playerDesc)
{
  unsigned int v2; // ST00_4@1
  SKILL_ADVANCEMENT_CLASS v3; // edi@1
  unsigned int v4; // esi@2
  int v5; // eax@4
  int v6; // eax@9
  unsigned int v7; // eax@12
  signed int v8; // ecx@12
  unsigned int v9; // esi@14
  int result; // eax@14
  unsigned int v11; // esi@15
  Skill skill; // [sp+Ch] [bp-20h]@1

  v2 = this->m_SelectedSkill;
  skill.vfptr = (PackObjVtbl *)&Skill::vftable;
  skill._sac = 0;
  skill._pp = 0;
  skill._init_level = 0;
  skill._level_from_pp = 0;
  skill._resistance_of_last_check = 0;
  *(_QWORD *)&skill._last_used_time = 0i64;
  CACQualities::InqSkill(i_playerDesc, v2, &skill);
  v3 = skill._sac;
  if ( skill._sac < 2 )
    return 0;
  v4 = skill._level_from_pp;
  if ( skill._sac == 2 )
  {
    v5 = ExperienceSystem::GetMaxTrainedSkillLevel();
  }
  else
  {
    if ( skill._sac != 3 )
      return 0;
    v5 = ExperienceSystem::GetMaxSpecializedSkillLevel();
  }
  if ( v4 >= v5 )
    return 0;
  if ( v3 == 2 )
  {
    v6 = ExperienceSystem::GetMaxTrainedSkillLevel();
  }
  else if ( v3 == 3 )
  {
    v6 = ExperienceSystem::GetMaxSpecializedSkillLevel();
  }
  else
  {
    v6 = 0;
  }
  v7 = v6 - skill._level_from_pp;
  v8 = 10;
  if ( (signed int)v7 < 10 && (v8 = v7, (signed int)v7 <= 0) )
  {
    v11 = skill._pp;
    result = ExperienceSystem::ExperienceToSkillLevel(v3, skill._level_from_pp + 1) - v11;
  }
  else
  {
    v9 = skill._pp;
    result = ExperienceSystem::ExperienceToSkillLevel(v3, v8 + skill._level_from_pp) - v9;
  }
  return result;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (0049AFA0) --------------------------------------------------------  // acclient.c:212746
BOOL __thiscall gmSkillUI::MessageIsFromSelectedElement(gmSkillUI *this, StatType i_statType, unsigned int i_statEnum)
{
  return this->m_SelectedSkill == i_statEnum;
}

//----- (0049AFC0) --------------------------------------------------------  // acclient.c:212752
PackableHashIterator<unsigned long,SkillBase> *__thiscall PackableHashIterator<unsigned long,SkillBase>::scalar_deleting_destructor(PackableHashIterator<unsigned long,SkillBase> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,SkillBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,SkillBase>Vtbl *)&PackableHashIterator<unsigned long,SkillBase>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7A7830: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SkillBase>::vftable)(void *, char);

//----- (0049AFE0) --------------------------------------------------------  // acclient.c:212765
gmSkillUI *__thiscall gmSkillUI::scalar_deleting_destructor(gmSkillUI *this, unsigned int a2)
{
  gmSkillUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSkillUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSkillUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmStatManagementUI::vftable;
  gmStatManagementUI::~gmStatManagementUI((gmStatManagementUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A7420: using guessed type bool (__thiscall *gmSkillUI::vftable)(DBCache *this);
// 7A76C8: using guessed type int (__thiscall *gmSkillUI::vftable)(void *, char);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (0049B020) --------------------------------------------------------  // acclient.c:212783
void __cdecl gmSkillUI::Register()
{
  UIElement::RegisterElementClass(0x1000002Bu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSkillUI::Create);
}

//----- (0049B040) --------------------------------------------------------  // acclient.c:212789
int __thiscall gmSkillUI::SetSelection(gmSkillUI *this, UIElement *_selectedUI)
{
  gmSkillUI *v2; // edi@1
  int v3; // esi@1
  IInputActionCallbackVtbl *v4; // eax@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  BasePropertyValue *v7; // ecx@11
  unsigned int v8; // edx@11
  IInputActionCallbackVtbl *v9; // eax@15
  BaseProperty infoProperty; // [sp+10h] [bp-8h]@2

  v2 = this;
  v3 = 0;
  if ( _selectedUI )
  {
    v4 = _selectedUI->vfptr;
    infoProperty.m_pcPropertyDesc = 0;
    infoProperty.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v4[17].OnAction)(268435514, &infoProperty) )
    {
      _selectedUI = 0;
      if ( infoProperty.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))infoProperty.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&_selectedUI);
      v3 = ((int (*)(void))v2->m_rgTokens.m_data[(_DWORD)_selectedUI]->vfptr[3].OnQualityChanged)();
    }
    if ( (_DWORD)infoProperty.m_pcPropertyDesc )
    {
      v5 = infoProperty.m_pcPropertyDesc;
      v6 = infoProperty.m_pcPropertyDesc->m_cRef - 1;
      infoProperty.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      infoProperty.m_pcPropertyDesc = 0;
    }
    if ( infoProperty.m_pcPropertyValue )
    {
      v7 = infoProperty.m_pcPropertyValue;
      v8 = infoProperty.m_pcPropertyValue->m_cRef - 1;
      infoProperty.m_pcPropertyValue->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    }
  }
  if ( v2->m_SelectedSkill == v3 )
    v3 = 0;
  v9 = v2->vfptr;
  v2->m_SelectedSkill = v3;
  return ((int (__thiscall *)(gmSkillUI *))v9[28].__vecDelDtor)(v2);
}

//----- (0049B110) --------------------------------------------------------  // acclient.c:212841
char __thiscall gmSkillUI::DisplayDefaultFooter(gmSkillUI *this, CACQualities *i_playerDesc)
{
  gmStatManagementUI *v2; // esi@1
  PStringBase<unsigned short> *v3; // ST04_4@1
  int v4; // eax@1
  char *v5; // ebx@1
  PStringBase<unsigned short> *v6; // ST0C_4@4
  int v7; // eax@4
  char *v8; // ebx@4
  PStringBase<unsigned short> *v9; // ST0C_4@7
  int v10; // eax@7
  char *v11; // ebx@7
  PStringBase<unsigned short> *v12; // ST0C_4@10
  int v13; // eax@10
  char *v14; // ebx@10
  PStringBase<unsigned short> *v15; // ST0C_4@13
  int v16; // eax@13
  char *v17; // esi@13
  PStringBase<unsigned short> result; // [sp+10h] [bp-A0h]@1
  unsigned int skillCredits; // [sp+14h] [bp-9Ch]@7
  unsigned __int64 availableXP; // [sp+18h] [bp-98h]@13
  StringInfo siText; // [sp+20h] [bp-90h]@1

  v2 = (gmStatManagementUI *)this;
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_DefaultSkillTitle, 268435457);
  v3 = StringInfo::GetString(&siText, &result, 0);
  v4 = gmStatManagementUI::GetFooterTitleLabel(v2);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v4, v3, 0, 0);
  v5 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsLabel, 268435457);
  v6 = StringInfo::GetString(&siText, &result, 0);
  v7 = gmStatManagementUI::GetFooterLineOneLabel(v2);
  UIElement_Text::SetText((UIElement_Text *)v7, v6);
  v8 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  skillCredits = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x18u, (int *)&skillCredits, 0, 0);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_SkillCredits, skillCredits);
  v9 = StringInfo::GetString(&siText, &result, 0);
  v10 = gmStatManagementUI::GetFooterLineOneValue(v2);
  UIElement_Text::SetText((UIElement_Text *)v10, v9);
  v11 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceLabel, 268435457);
  v12 = StringInfo::GetString(&siText, &result, 0);
  v13 = gmStatManagementUI::GetFooterLineTwoLabel(v2);
  UIElement_Text::SetText((UIElement_Text *)v13, v12);
  v14 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  availableXP = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 2u, (__int64 *)&availableXP);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_AvailableExperience, availableXP);
  v15 = StringInfo::GetString(&siText, &result, 0);
  v16 = gmStatManagementUI::GetFooterLineTwoValue(v2);
  UIElement_Text::SetText((UIElement_Text *)v16, v15);
  v17 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (0049B350) --------------------------------------------------------  // acclient.c:212912
char __thiscall gmSkillUI::DisplaySelectionFooter_Untrained(gmSkillUI *this, CACQualities *i_playerDesc)
{
  gmSkillUI *v2; // esi@1
  int v3; // eax@1
  PStringBase<unsigned short> *v4; // ST0C_4@1
  int v5; // eax@1
  char *v6; // edi@1
  unsigned int v7; // ebp@4
  PStringBase<unsigned short> *v8; // ST0C_4@4
  int v9; // eax@4
  char *v10; // edi@4
  PStringBase<unsigned short> *v11; // ST0C_4@7
  int v12; // eax@7
  char *v13; // edi@7
  PStringBase<unsigned short> *v14; // ST0C_4@10
  int v15; // eax@10
  char *v16; // edi@10
  int v17; // eax@13
  int v18; // eax@15
  int v19; // eax@16
  char *v20; // esi@17
  PStringBase<unsigned short> result; // [sp+18h] [bp-9Ch]@1
  PStringBase<unsigned short> strLabel; // [sp+1Ch] [bp-98h]@1
  unsigned int availableCredits; // [sp+20h] [bp-94h]@10
  StringInfo siText; // [sp+24h] [bp-90h]@1

  strLabel.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  SkillSystem::InqSkillName(v2->m_SelectedSkill, &strLabel);
  v3 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v3, &strLabel, 0, 0);
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsToRaiseLabel, 268435457);
  v4 = StringInfo::GetString(&siText, &result, 0);
  v5 = gmStatManagementUI::GetFooterLineOneLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v5, v4);
  v6 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = (int)v2->vfptr[29].__vecDelDtor((IInputActionCallback *)v2, (unsigned int)i_playerDesc);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsToRaiseValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_SkillCreditsToRaise, v7);
  v8 = StringInfo::GetString(&siText, &result, 0);
  v9 = gmStatManagementUI::GetFooterLineOneValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v9, v8);
  v10 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsLabel, 268435457);
  v11 = StringInfo::GetString(&siText, &result, 0);
  v12 = gmStatManagementUI::GetFooterLineTwoLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v12, v11);
  v13 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  availableCredits = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x18u, (int *)&availableCredits, 0, 0);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_SkillCredits, availableCredits);
  v14 = StringInfo::GetString(&siText, &result, 0);
  v15 = gmStatManagementUI::GetFooterLineTwoValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v15, v14);
  v16 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  v17 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v17 + 24))(v17, 0);
  if ( v7 && availableCredits >= v7 )
  {
    v18 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v18 + 156))(v18, 1);
  }
  else
  {
    v19 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v19 + 156))(v19, 13);
  }
  StringInfo::~StringInfo(&siText);
  v20 = (char *)&strLabel.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strLabel.m_charbuffer[-1].m_data[8]) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  return 1;
}

//----- (0049B5C0) --------------------------------------------------------  // acclient.c:212998
PackableHashIterator<unsigned long,SkillBase> *__thiscall PackableHashTable<unsigned long,SkillBase>::begin(PackableHashTable<unsigned long,SkillBase> *this, PackableHashIterator<unsigned long,SkillBase> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,SkillBase> **v4; // edi@2
  PackableHashData<unsigned long,SkillBase> **v5; // esi@2
  PackableHashData<unsigned long,SkillBase> **v6; // ecx@5
  PackableHashIterator<unsigned long,SkillBase> *v7; // eax@5
  PackableHashData<unsigned long,SkillBase> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,SkillBase>Vtbl *)&PackableHashIterator<unsigned long,SkillBase>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,SkillBase>Vtbl *)&PackableHashIterator<unsigned long,SkillBase>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7A7830: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SkillBase>::vftable)(void *, char);

//----- (0049B640) --------------------------------------------------------  // acclient.c:213058
SkillBase *__thiscall SkillTable::GetSkillBase(SkillTable *this, unsigned int key)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,SkillBase> **v3; // ecx@2
  PackableHashData<unsigned long,SkillBase> *v4; // edx@3
  SkillBase *result; // eax@6

  v2 = this->_skillBaseHash._table_size;
  if ( v2 && (v3 = this->_skillBaseHash._buckets) != 0 && (v4 = v3[key % v2]) != 0 )
  {
    while ( key != v4->_key )
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

//----- (0049B680) --------------------------------------------------------  // acclient.c:213085
int __thiscall gmSkillUI::GetCostToRaise(gmSkillUI *this, CACQualities *i_playerDesc)
{
  gmSkillUI *v2; // edi@1
  unsigned int v3; // ST04_4@1
  SKILL_ADVANCEMENT_CLASS v4; // ebp@1
  unsigned int v5; // esi@2
  int v6; // eax@4
  unsigned int v7; // esi@7
  int v9; // esi@8
  SkillBase *v10; // eax@9
  unsigned int v11; // edi@12
  Skill skill; // [sp+10h] [bp-20h]@1

  v2 = this;
  v3 = this->m_SelectedSkill;
  skill.vfptr = (PackObjVtbl *)&Skill::vftable;
  skill._sac = 0;
  skill._pp = 0;
  skill._init_level = 0;
  skill._level_from_pp = 0;
  skill._resistance_of_last_check = 0;
  *(_QWORD *)&skill._last_used_time = 0i64;
  CACQualities::InqSkill(i_playerDesc, v3, &skill);
  v4 = skill._sac;
  if ( skill._sac >= 2 )
  {
    v5 = skill._level_from_pp;
    if ( skill._sac == 2 )
    {
      v6 = ExperienceSystem::GetMaxTrainedSkillLevel();
LABEL_6:
      if ( v5 < v6 )
      {
        v7 = skill._pp;
        return ExperienceSystem::ExperienceToSkillLevel(v4, skill._level_from_pp + 1) - v7;
      }
      return 0;
    }
    if ( skill._sac == 3 )
    {
      v6 = ExperienceSystem::GetMaxSpecializedSkillLevel();
      goto LABEL_6;
    }
    return 0;
  }
  v9 = DBObj::GetByEnum(4, 2, 0x10000004u);
  if ( !v9 )
    return 0;
  v10 = SkillTable::GetSkillBase((SkillTable *)v9, v2->m_SelectedSkill);
  if ( !v10 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
    return 0;
  }
  v11 = v10->_trained_cost;
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
  return v11;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (0049B760) --------------------------------------------------------  // acclient.c:213146
char __thiscall gmSkillUI::Raise10Selection(gmSkillUI *this)
{
  gmSkillUI *v1; // esi@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // edi@2
  int v4; // ebp@4
  PlayerDesc *v5; // edi@6
  unsigned int v7; // ST04_4@10
  IInputActionCallbackVtbl *v8; // eax@11
  unsigned int v9; // eax@11
  int v10; // eax@11
  int v11; // [sp-8h] [bp-30h]@2
  Interface *_rpInterface; // [sp+10h] [bp-18h]@2
  SKILL_ADVANCEMENT_CLASS sac; // [sp+14h] [bp-14h]@10
  TResult result; // [sp+18h] [bp-10h]@2
  char v15; // [sp+1Ch] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+20h] [bp-8h]@2

  v1 = this;
  if ( !this->m_SelectedSkill )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_1, &_rpInterface);
  v3 = _rpInterface;
  v11 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v15, v11, 0);
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
  v7 = v1->m_SelectedSkill;
  sac = 0;
  CACQualities::InqSkillAdvancementClass((CACQualities *)&playerDesc.m_pInterface->vfptr, v7, &sac);
  if ( (signed int)sac >= 2 )
  {
    v8 = v1->vfptr;
    v1->m_bAwaitingRaise = 1;
    v9 = ((int (__thiscall *)(gmSkillUI *, PlayerDesc *))v8[29].OnLoseFocus)(v1, v5);
    CM_Train::Event_TrainSkill(v1->m_SelectedSkill, v9);
    v10 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v1->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v10 + 156))(v10, 13);
  }
  v5->vfptr->Release((Interface *)v5);
  return 1;
}

//----- (0049B860) --------------------------------------------------------  // acclient.c:213204
char __thiscall gmSkillUI::DisplaySelectionFooter_Trained(gmSkillUI *this, CACQualities *i_playerDesc)
{
  gmSkillUI *v2; // esi@1
  bool v3; // bp@1
  int v4; // eax@1
  unsigned int v5; // ST0C_4@1
  unsigned int v6; // ST0C_4@1
  int v7; // eax@1
  int v8; // ebx@1
  int v9; // eax@2
  char *v10; // ebp@2
  int v11; // ebx@7
  int v12; // eax@11
  LONG (__stdcall *v13)(volatile LONG *); // ebx@11
  char *v14; // edi@11
  char *v15; // edi@14
  PStringBase<unsigned short> *v16; // ST14_4@18
  int v17; // eax@18
  int v18; // edi@18
  PSRefBufferCharData<unsigned short> *v19; // edi@21
  PStringBase<unsigned short> *v20; // ST14_4@24
  int v21; // eax@24
  int v22; // edi@24
  unsigned int v23; // ST10_4@27
  SKILL_ADVANCEMENT_CLASS v24; // ebx@27
  unsigned int v25; // ebp@27
  int v26; // edi@27
  int v27; // eax@27
  int v28; // eax@30
  PStringBase<unsigned short> *v29; // ST14_4@30
  int v30; // eax@30
  int v31; // edi@30
  PStringBase<unsigned short> *v32; // ST14_4@33
  int v33; // eax@33
  int v34; // edi@33
  int v35; // eax@38
  int v36; // eax@39
  int v37; // eax@40
  int v38; // eax@40
  int v39; // eax@42
  int v40; // eax@43
  char *v41; // esi@44
  char *v42; // esi@47
  float v44; // [sp+14h] [bp-E8h]@28
  int iMod; // [sp+28h] [bp-D4h]@6
  PStringBase<unsigned short> strModText; // [sp+2Ch] [bp-D0h]@2
  PStringBase<unsigned short> strModTypeText; // [sp+30h] [bp-CCh]@7
  int iStatValMod; // [sp+34h] [bp-C8h]@1
  PStringBase<unsigned short> strLabel; // [sp+38h] [bp-C4h]@1
  unsigned __int64 availableXP; // [sp+3Ch] [bp-C0h]@33
  PStringBase<unsigned short> strValueText; // [sp+44h] [bp-B8h]@1
  int iStatValRaw; // [sp+48h] [bp-B4h]@1
  Skill skill; // [sp+4Ch] [bp-B0h]@27
  StringInfo siText; // [sp+6Ch] [bp-90h]@18

  strLabel.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  SkillSystem::InqSkillName(v2->m_SelectedSkill, &strLabel);
  v3 = 0;
  v4 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v4, &strLabel, 0, 0);
  v5 = v2->m_SelectedSkill;
  iStatValRaw = 0;
  CACQualities::InqSkill(i_playerDesc, v5, &iStatValRaw, 1);
  v6 = v2->m_SelectedSkill;
  iStatValMod = 0;
  CACQualities::InqSkill(i_playerDesc, v6, &iStatValMod, 0);
  strValueText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&strValueText, L"%s: %d", strLabel.m_charbuffer, iStatValMod);
  v7 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v7, &strValueText, 0, 0);
  v8 = ((int (__stdcall *)(CACQualities *))v2->m_rgTokens.m_data[v2->m_SelectedIndex]->vfptr[5].OnQualityChanged)(i_playerDesc);
  if ( v8 < 0 )
  {
    strModText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strModText, L" (%d)", v8);
    v9 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
    UIElement_Text::AppendTextWithFont((UIElement_Text *)v9, &strModText, 0, 3);
    v10 = (char *)&strModText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModText.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    v3 = 0;
  }
  iStatValMod -= v8;
  iMod = iStatValMod - iStatValRaw;
  if ( iStatValMod == iStatValRaw )
  {
    v13 = InterlockedDecrement;
  }
  else
  {
    strModTypeText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    v11 = 0;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( iStatValRaw >= iStatValMod )
    {
      if ( iStatValRaw > iStatValMod )
        v11 = 2;
    }
    else
    {
      v11 = 1;
      PStringBase<unsigned short>::set(&strModTypeText, L"+");
    }
    strModText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strModText, L" (%s%d)", strModTypeText.m_charbuffer, iMod);
    v12 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
    UIElement_Text::AppendTextWithFont((UIElement_Text *)v12, &strModText, 0, v11);
    v13 = InterlockedDecrement;
    v14 = (char *)&strModText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModText.m_charbuffer[-1].m_data[8]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    v15 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  }
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseLabel, 268435457);
  v16 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, v3);
  v17 = gmStatManagementUI::GetFooterLineOneLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v17, v16);
  v18 = iMod - 20;
  if ( !v13((volatile LONG *)(iMod - 20 + 4)) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  v19 = (PSRefBufferCharData<unsigned short> *)v2->vfptr[29].__vecDelDtor(
                                                 (IInputActionCallback *)v2,
                                                 (unsigned int)i_playerDesc);
  strModTypeText.m_charbuffer = v19;
  if ( (unsigned int)v19 > 0 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseValue, 268435457);
    StringInfo::AddVariable_Int(&siText, ID_XPToRaise, (unsigned int)v19);
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_XPToLevelMeterInfinity, 268435457);
  }
  v20 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v21 = gmStatManagementUI::GetFooterLineOneValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v21, v20);
  v22 = iMod - 20;
  if ( !v13((volatile LONG *)(iMod - 20 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  v23 = v2->m_SelectedSkill;
  skill.vfptr = (PackObjVtbl *)&Skill::vftable;
  skill._sac = 0;
  skill._pp = 0;
  skill._init_level = 0;
  skill._level_from_pp = 0;
  skill._resistance_of_last_check = 0;
  *(_QWORD *)&skill._last_used_time = 0i64;
  CACQualities::InqSkill(i_playerDesc, v23, &skill);
  v24 = skill._sac;
  v25 = skill._level_from_pp;
  v26 = ExperienceSystem::ExperienceToSkillLevel(skill._sac, skill._level_from_pp);
  v27 = ExperienceSystem::ExperienceToSkillLevel(v24, v25 + 1) - v26;
  if ( v27 )
  {
    iMod = v27;
    v44 = (double)(skill._pp - v26) / (double)(unsigned int)v27;
  }
  else
  {
    v44 = 0.0;
  }
  v28 = gmStatManagementUI::GetFooterMeter((gmStatManagementUI *)&v2->vfptr);
  UIElement::SetAttribute_Float((UIElement *)v28, 0x69u, v44);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceLabel, 268435457);
  v29 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v30 = gmStatManagementUI::GetFooterLineTwoLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v30, v29);
  v31 = iMod - 20;
  if ( !InterlockedDecrement((volatile LONG *)(iMod - 20 + 4)) && v31 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
  availableXP = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 2u, (__int64 *)&availableXP);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_AvailableExperience, availableXP);
  v32 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v33 = gmStatManagementUI::GetFooterLineTwoValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v33, v32);
  v34 = iMod - 20;
  if ( !InterlockedDecrement((volatile LONG *)(iMod - 20 + 4)) && v34 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
  if ( strModTypeText.m_charbuffer && availableXP >= (unsigned int)strModTypeText.m_charbuffer )
  {
    v35 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v35 + 156))(v35, 1);
  }
  else
  {
    v36 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v36 + 156))(v36, 13);
  }
  v37 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
  (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v37 + 24))(v37, 1);
  v38 = ((int (__thiscall *)(gmSkillUI *, CACQualities *))v2->vfptr[29].OnLoseFocus)(v2, i_playerDesc);
  if ( v38 && availableXP >= (unsigned int)v38 )
  {
    v39 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v39 + 156))(v39, 1);
  }
  else
  {
    v40 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v40 + 156))(v40, 13);
  }
  skill.vfptr = (PackObjVtbl *)&PackObj::vftable;
  StringInfo::~StringInfo(&siText);
  v41 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) && v41 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v41)(v41, 1);
  v42 = (char *)&strLabel.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strLabel.m_charbuffer[-1].m_data[8]) && v42 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v42)(v42, 1);
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (0049BDD0) --------------------------------------------------------  // acclient.c:213429
char __thiscall gmSkillUI::AddSortedSkill(gmSkillUI *this, unsigned int i_SkillID, SkillBase *i_SkillBase, UIElement *i_pAfter, UIElement *i_pBefore)
{
  UIElement *v5; // edi@1
  gmSkillUI *v6; // ebx@1
  UIElement_ListBox *v8; // edx@3
  unsigned int v9; // ecx@3
  signed int v10; // eax@3
  UIElement **v11; // esi@4
  unsigned int v12; // esi@9
  UIElement *v13; // ecx@9
  UIElement **v14; // edx@10
  int v15; // edi@16
  UIElement *v16; // eax@17
  IInputActionCallbackVtbl *v17; // edx@18
  int v18; // eax@21
  char *v19; // esi@21
  BasePropertyDesc *v20; // ecx@26
  unsigned int v21; // edx@26
  BasePropertyValue *v22; // ecx@30
  unsigned int v23; // edx@30
  BasePropertyDesc *v24; // ecx@39
  unsigned int v25; // edx@39
  BasePropertyValue *v26; // ecx@43
  unsigned int v27; // esi@43
  SkillInfoRegion *v28; // eax@45
  InfoRegion *v29; // eax@46
  InfoRegion *v30; // edi@46
  int v31; // eax@48
  unsigned int v32; // eax@49
  char v33; // bl@50
  char *v34; // esi@52
  PStringBase<unsigned short> addingSkillName; // [sp+1Ch] [bp-10h]@3
  int arrayIndex; // [sp+20h] [bp-Ch]@1
  BaseProperty infoProperty; // [sp+24h] [bp-8h]@18

  arrayIndex = 0;
  v5 = i_pAfter;
  v6 = this;
  if ( !i_pAfter )
    return 0;
  addingSkillName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  SkillSystem::InqSkillName(i_SkillID, &addingSkillName);
  v8 = v6->m_pListBox;
  v9 = v8->m_listItems.m_num;
  v10 = 0;
  if ( v9 )
  {
    v11 = v8->m_listItems.m_data;
    while ( *v11 != v5 )
    {
      ++v10;
      ++v11;
      if ( v10 >= v9 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v10 = -1;
  }
  if ( i_pBefore )
  {
    v12 = v8->m_listItems.m_num;
    v13 = 0;
    if ( v12 )
    {
      v14 = v8->m_listItems.m_data;
      while ( *v14 != i_pBefore )
      {
        v13 = (UIElement *)((char *)v13 + 1);
        ++v14;
        if ( (unsigned int)v13 >= v12 )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      v13 = (UIElement *)-1;
    }
    i_pBefore = v13;
  }
  else
  {
    i_pBefore = (UIElement *)v8->m_listItems.m_num;
  }
  v15 = v10 + 1;
  if ( v10 + 1 >= (signed int)i_pBefore )
    goto LABEL_45;
  while ( 1 )
  {
    v16 = UIElement_ListBox::GetItem(v6->m_pListBox, v15);
    if ( v16 )
      break;
LABEL_33:
    ++v15;
    if ( v15 >= (signed int)i_pBefore )
      goto LABEL_45;
  }
  v17 = v16->vfptr;
  infoProperty.m_pcPropertyDesc = 0;
  infoProperty.m_pcPropertyValue = 0;
  if ( !(unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v17[17].OnAction)(
                           v16,
                           268435514,
                           &infoProperty) )
  {
LABEL_25:
    if ( (_DWORD)infoProperty.m_pcPropertyDesc )
    {
      v20 = infoProperty.m_pcPropertyDesc;
      v21 = infoProperty.m_pcPropertyDesc->m_cRef - 1;
      infoProperty.m_pcPropertyDesc->m_cRef = v21;
      if ( !v21 )
        ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
      infoProperty.m_pcPropertyDesc = 0;
    }
    if ( infoProperty.m_pcPropertyValue )
    {
      v22 = infoProperty.m_pcPropertyValue;
      v23 = infoProperty.m_pcPropertyValue->m_cRef - 1;
      infoProperty.m_pcPropertyValue->m_cRef = v23;
      if ( !v23 )
        ((void (__stdcall *)(_DWORD))v22->vfptr->__vecDelDtor)(1);
      infoProperty.m_pcPropertyValue = 0;
    }
    goto LABEL_33;
  }
  arrayIndex = 0;
  if ( infoProperty.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))infoProperty.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&arrayIndex);
  i_pAfter = (UIElement *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  ((void (__stdcall *)(UIElement **))v6->m_rgTokens.m_data[arrayIndex]->vfptr[1].OnQualityRemoved)(&i_pAfter);
  v18 = _wcscmp(addingSkillName.m_charbuffer->m_data, (const wchar_t *)i_pAfter);
  v19 = (char *)&i_pAfter[-1].m_hashListeners.m_intrusiveTable.m_numElements;
  if ( v18 >= 0 )
  {
    if ( !InterlockedDecrement((volatile LONG *)v19 + 1) && v19 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    goto LABEL_25;
  }
  if ( !InterlockedDecrement((volatile LONG *)v19 + 1) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  if ( (_DWORD)infoProperty.m_pcPropertyDesc )
  {
    v24 = infoProperty.m_pcPropertyDesc;
    v25 = infoProperty.m_pcPropertyDesc->m_cRef - 1;
    infoProperty.m_pcPropertyDesc->m_cRef = v25;
    if ( !v25 )
      ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
    infoProperty.m_pcPropertyDesc = 0;
  }
  if ( infoProperty.m_pcPropertyValue )
  {
    v26 = infoProperty.m_pcPropertyValue;
    v27 = infoProperty.m_pcPropertyValue->m_cRef - 1;
    infoProperty.m_pcPropertyValue->m_cRef = v27;
    if ( !v27 )
      ((void (__stdcall *)(_DWORD))v26->vfptr->__vecDelDtor)(1);
  }
LABEL_45:
  v28 = (SkillInfoRegion *)operator new(0x1Cu);
  if ( v28 )
  {
    SkillInfoRegion::SkillInfoRegion(v28, v6->m_pListBox, v15, v6->m_rgTokens.m_num, i_SkillID, i_SkillBase->_iconID, 1);
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  v31 = v6->m_rgTokens.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v6->m_rgTokens.m_num < v31
    || (v32 = SmartArray<UIChildFramework *,1>::get_new_size(v31 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v6->m_rgTokens, v32)) )
  {
    v6->m_rgTokens.m_data[v6->m_rgTokens.m_num++] = v30;
    v33 = 1;
  }
  else
  {
    v33 = 0;
  }
  v34 = (char *)&addingSkillName.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&addingSkillName.m_charbuffer[-1].m_data[8]) )
  {
    if ( v34 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
  }
  return v33;
}

//----- (0049C0A0) --------------------------------------------------------  // acclient.c:213625
char __thiscall gmSkillUI::UpdateSelection(gmSkillUI *this)
{
  gmSkillUI *v1; // esi@1
  int v2; // edi@1
  int v3; // eax@2
  QualityChangeHandlerVtbl *v4; // edx@2
  InterfaceSystem *v5; // eax@6
  SKILL_ADVANCEMENT_CLASS v6; // edi@6
  int v7; // ebx@8
  CACQualities *v8; // edi@10
  char v9; // al@13
  unsigned int v10; // eax@14
  int v11; // [sp-8h] [bp-2Ch]@6
  SKILL_ADVANCEMENT_CLASS sac; // [sp+10h] [bp-14h]@6
  TResult result; // [sp+14h] [bp-10h]@6
  char v14; // [sp+18h] [bp-Ch]@8
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@6

  v1 = this;
  v2 = 0;
  if ( this->m_rgTokens.m_num )
  {
    do
    {
      v3 = ((int (*)(void))v1->m_rgTokens.m_data[v2]->vfptr[3].OnQualityChanged)();
      v4 = v1->m_rgTokens.m_data[v2]->vfptr;
      if ( v3 == v1->m_SelectedSkill )
      {
        ((void (__stdcall *)(signed int))v4[5].OnQualityRemoved)(6);
        v1->m_SelectedIndex = v2;
      }
      else
      {
        ((void (__stdcall *)(signed int))v4[5].OnQualityRemoved)(1);
      }
      ++v2;
    }
    while ( v2 < v1->m_rgTokens.m_num );
  }
  sac = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, &result, &PlayerDesc_ClassType_1, (Interface **)&sac);
  v6 = sac;
  v11 = sac;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( sac )
    (*(void (__thiscall **)(SKILL_ADVANCEMENT_CLASS))(*(_DWORD *)sac + 16))(sac);
  v7 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v14, v11, 0);
  if ( v6 )
    (*(void (__thiscall **)(SKILL_ADVANCEMENT_CLASS))(*(_DWORD *)v6 + 20))(v6);
  v8 = (CACQualities *)playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v7 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v10 = v1->m_SelectedSkill;
  if ( v10 )
  {
    sac = 0;
    CACQualities::InqSkillAdvancementClass((CACQualities *)&playerDesc.m_pInterface->vfptr, v10, &sac);
    if ( (signed int)sac < 2 )
    {
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435474u);
      gmSkillUI::DisplaySelectionFooter_Untrained(v1, v8);
      v8->vfptr->Release((Interface *)v8);
      v9 = 1;
    }
    else
    {
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435475u);
      gmSkillUI::DisplaySelectionFooter_Trained(v1, v8);
      v8->vfptr->Release((Interface *)v8);
      v9 = 1;
    }
  }
  else
  {
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435473u);
    gmSkillUI::DisplayDefaultFooter(v1, v8);
    v8->vfptr->Release((Interface *)v8);
    v9 = 1;
  }
  return v9;
}

//----- (0049C210) --------------------------------------------------------  // acclient.c:213715
void __cdecl gmSkillUI::TrainSkillDialogCallback(PropertyCollection *i_rcResults)
{
  PropertyCollection *v1; // esi@1
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  BasePropertyValue *v5; // ecx@6
  unsigned int v6; // edx@9
  HashTableData<unsigned long,BaseProperty> **v7; // eax@9
  HashTableData<unsigned long,BaseProperty> *v8; // eax@9
  unsigned int v9; // edx@16
  HashTableData<unsigned long,BaseProperty> **v10; // eax@16
  HashTableData<unsigned long,BaseProperty> *v11; // eax@16
  BasePropertyDesc *v12; // ecx@27
  unsigned int v13; // edx@27
  int v14; // edx@31
  int v15; // [sp+8h] [bp-10h]@1
  unsigned int costToRaise; // [sp+Ch] [bp-Ch]@16
  BaseProperty p; // [sp+10h] [bp-8h]@1

  v1 = i_rcResults;
  v2 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  BYTE3(v15) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 146 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      v5 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v15 + 3);
        v5 = p.m_pcPropertyValue;
      }
      if ( BYTE3(v15) )
      {
        v6 = 0x10000040 % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v7 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        i_rcResults = 0;
        v8 = v7[v6];
        if ( v8 )
        {
          while ( v8->m_hashKey != 268435520 )
          {
            v8 = v8->m_hashNext;
            if ( !v8 )
              goto LABEL_16;
          }
          if ( v8 )
          {
            BaseProperty::operator=(&p, (int)&v8->m_data);
            v5 = p.m_pcPropertyValue;
            if ( p.m_pcPropertyValue )
            {
              ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&i_rcResults);
              v5 = p.m_pcPropertyValue;
            }
          }
        }
LABEL_16:
        v9 = 0x10000041 % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v10 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        costToRaise = 0;
        v11 = v10[v9];
        if ( v11 )
        {
          while ( v11->m_hashKey != 268435521 )
          {
            v11 = v11->m_hashNext;
            if ( !v11 )
              goto LABEL_23;
          }
          if ( v11 )
          {
            BaseProperty::operator=(&p, (int)&v11->m_data);
            v5 = p.m_pcPropertyValue;
            if ( p.m_pcPropertyValue )
            {
              ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&costToRaise);
              v5 = p.m_pcPropertyValue;
            }
          }
        }
LABEL_23:
        if ( i_rcResults && costToRaise )
        {
          CM_Train::Event_TrainSkillAdvancementClass((unsigned int)i_rcResults, costToRaise);
          v5 = p.m_pcPropertyValue;
        }
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v12 = p.m_pcPropertyDesc;
        v13 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v13;
        if ( !v13 )
          ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
        v5 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v5 )
      {
        v14 = v5->m_cRef - 1;
        v5->m_cRef = v14;
        if ( !v14 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (0049C3A0) --------------------------------------------------------  // acclient.c:213837
char __thiscall gmSkillUI::RebuildSkillList(gmSkillUI *this)
{
  gmSkillUI *v1; // edi@1
  int v2; // eax@1
  PackableHashTable<unsigned long,SkillBase> *v3; // esi@2
  InterfaceSystem *v4; // eax@2
  UIElement *v5; // ebx@2
  int v7; // eax@11
  UIElement_ListBox *v8; // ecx@11
  int v9; // ebx@11
  int v10; // eax@11
  UIElement_ListBox *v11; // ecx@11
  PackableHashData<unsigned long,SkillBase> *v12; // esi@11
  UIElement *v13; // ecx@19
  PackableHashData<unsigned long,SkillBase> *v14; // eax@22
  unsigned int v15; // esi@24
  IInputActionCallbackVtbl *v16; // edx@29
  PlayerDesc *v17; // ST0C_4@29
  char v18; // bl@29
  int v19; // [sp-8h] [bp-60h]@2
  UIElement *v20; // [sp-4h] [bp-5Ch]@19
  UIElement *untrainedHeader; // [sp+10h] [bp-48h]@2
  UIElement *unusableHeader; // [sp+14h] [bp-44h]@4
  DBObjGrabber<SkillTable> stable; // [sp+18h] [bp-40h]@1
  UIElement *specializedHeader; // [sp+1Ch] [bp-3Ch]@2
  InterfacePtr<PlayerDesc> playerDesc; // [sp+20h] [bp-38h]@2
  PackableHashIterator<unsigned long,SkillBase> iter; // [sp+28h] [bp-30h]@11
  Skill skill; // [sp+38h] [bp-20h]@13

  v1 = this;
  gmStatManagementUI::FlushList((gmStatManagementUI *)&this->vfptr);
  v2 = DBObj::GetByEnum(4, 2, 0x10000004u);
  stable.m_object = (SkillTable *)v2;
  if ( !v2 )
    return 0;
  v3 = (PackableHashTable<unsigned long,SkillBase> *)(v2 + 56);
  untrainedHeader = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, (TResult *)&specializedHeader, &PlayerDesc_ClassType_1, (Interface **)&untrainedHeader);
  v19 = (int)untrainedHeader;
  v5 = untrainedHeader;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( untrainedHeader )
    ((void (__thiscall *)(UIElement *))untrainedHeader->vfptr[1].OnAction)(untrainedHeader);
  unusableHeader = *(UIElement **)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&unusableHeader, v19, 0);
  if ( v5 )
    ((void (__thiscall *)(UIElement *))v5->vfptr[1].OnLoseFocus)(v5);
  if ( !(_DWORD)playerDesc.m_pInterface )
  {
LABEL_9:
    ((void (*)(void))stable.m_object->vfptr->Release)();
    return 0;
  }
  if ( (signed int)unusableHeader < 0 )
  {
    ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    goto LABEL_9;
  }
  v7 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pListBox, 1u, 0);
  v8 = v1->m_pListBox;
  specializedHeader = (UIElement *)v7;
  v9 = UIElement_ListBox::AddItemFromTemplateList(v8, 2u, 0);
  v10 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pListBox, 3u, 0);
  v11 = v1->m_pListBox;
  untrainedHeader = (UIElement *)v10;
  unusableHeader = (UIElement *)UIElement_ListBox::AddItemFromTemplateList(v11, 4u, 0);
  PackableHashTable<unsigned long,SkillBase>::begin(v3, &iter);
  v12 = iter._current;
  while ( v12 )
  {
    skill.vfptr = (PackObjVtbl *)&Skill::vftable;
    skill._sac = 0;
    skill._pp = 0;
    skill._init_level = 0;
    skill._level_from_pp = 0;
    skill._resistance_of_last_check = 0;
    *(_QWORD *)&skill._last_used_time = 0i64;
    CACQualities::InqSkill((CACQualities *)&playerDesc.m_pInterface->vfptr, v12->_key, &skill);
    if ( skill._sac == 3 )
    {
      gmSkillUI::AddSortedSkill(v1, v12->_key, &v12->_data, specializedHeader, (UIElement *)v9);
    }
    else if ( skill._sac == 2 )
    {
      gmSkillUI::AddSortedSkill(v1, v12->_key, &v12->_data, (UIElement *)v9, untrainedHeader);
    }
    else
    {
      if ( skill._sac != 1 || v12->_data._min_level > 1 )
      {
        v13 = unusableHeader;
        v20 = 0;
      }
      else
      {
        v13 = untrainedHeader;
        v20 = unusableHeader;
      }
      gmSkillUI::AddSortedSkill(v1, v12->_key, &v12->_data, v13, v20);
    }
    v14 = v12->_next;
    skill.vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( v14 )
    {
      v12 = v14;
    }
    else
    {
      v15 = v12->_hashVal + 1;
      if ( v15 >= iter._table_size )
      {
LABEL_27:
        v12 = 0;
      }
      else
      {
        while ( !iter._buckets[v15] )
        {
          ++v15;
          if ( v15 >= iter._table_size )
            goto LABEL_27;
        }
        v12 = iter._buckets[v15];
      }
    }
  }
  v16 = v1->vfptr;
  v17 = playerDesc.m_pInterface;
  v1->m_SelectedIndex = -1;
  v18 = (int)v16[26].__vecDelDtor((IInputActionCallback *)v1, (unsigned int)v17);
  ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
  ((void (*)(void))stable.m_object->vfptr->Release)();
  return v18;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (0049C5D0) --------------------------------------------------------  // acclient.c:213976
void __thiscall gmSkillUI::RecvNotice_PlayerDescReceived(gmSkillUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmSkillUI::RebuildSkillList((gmSkillUI *)((char *)this - 1528));
}

//----- (0049C5E0) --------------------------------------------------------  // acclient.c:213982
void __thiscall gmSkillUI::RecvNotice_SkillAdvancementClassChanged(gmSkillUI *this)
{
  gmSkillUI::RebuildSkillList((gmSkillUI *)((char *)this - 1528));
}

//----- (0049C5F0) --------------------------------------------------------  // acclient.c:213988
char __thiscall gmSkillUI::TrainSkill(gmSkillUI *this, CACQualities *i_playerDesc)
{
  gmSkillUI *v2; // esi@1
  char result; // al@2
  int v4; // ebx@3
  PStringBase<unsigned short> *v5; // eax@3
  char *v6; // edi@3
  unsigned int v7; // esi@10
  BasePropertyDesc *v8; // ecx@15
  unsigned int v9; // edx@15
  BasePropertyValue *v10; // ecx@19
  unsigned int v11; // esi@19
  AC1Legacy::PSRefBuffer<char> *v12; // esi@22
  AC1Legacy::PSRefBuffer<char> *v13; // esi@25
  BaseProperty p; // [sp+1Ch] [bp-11Ch]@6
  PStringBase<unsigned short> v15; // [sp+24h] [bp-114h]@3
  AC1Legacy::PStringBase<char> strLabel; // [sp+28h] [bp-110h]@3
  AC1Legacy::PStringBase<char> msg; // [sp+2Ch] [bp-10Ch]@3
  PropertyCollection pc; // [sp+30h] [bp-108h]@6
  StringInfo v19; // [sp+A8h] [bp-90h]@3

  v2 = this;
  if ( this->m_SelectedSkill )
  {
    strLabel.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    SkillSystem::InqSkillName(v2->m_SelectedSkill, &strLabel);
    v4 = (int)v2->vfptr[29].__vecDelDtor((IInputActionCallback *)v2, (unsigned int)i_playerDesc);
    msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::sprintf(
      &msg,
      "Are you sure you want to spend %d credits to train %s?",
      v4,
      strLabel.m_buffer->m_data);
    StringInfo::StringInfo(&v19);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, 0, msg.m_buffer->m_data);
    StringInfo::SetLiteralValue(&v19, v5, 1);
    v6 = (char *)&v15.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&v15,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v19);
    }
    v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&v15,
      &p);
    BaseProperty::SetPropertyName(&p, 0x10000040u);
    v7 = v2->m_SelectedSkill;
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v7);
    }
    v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&v15,
      &p);
    BaseProperty::SetPropertyName(&p, 0x10000041u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(int))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v4);
    }
    v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&v15,
      &p);
    DialogFactory::MakeCallbackDialogInCurrentUI(&pc, gmSkillUI::TrainSkillDialogCallback);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v8 = p.m_pcPropertyDesc;
      v9 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v10 = p.m_pcPropertyValue;
      v11 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&v19);
    v12 = msg.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v12 )
      v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
    v13 = strLabel.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strLabel.m_buffer->m_cRef) )
    {
      if ( v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0049C8C0) --------------------------------------------------------  // acclient.c:214118
char __thiscall gmSkillUI::RaiseSelection(gmSkillUI *this)
{
  gmSkillUI *v1; // esi@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // edi@2
  int v4; // ebp@4
  CACQualities *v5; // edi@6
  char v6; // al@9
  unsigned int v7; // ST04_4@10
  IInputActionCallbackVtbl *v8; // eax@11
  unsigned int v9; // eax@11
  int v10; // eax@11
  int v11; // [sp-8h] [bp-30h]@2
  Interface *_rpInterface; // [sp+10h] [bp-18h]@2
  SKILL_ADVANCEMENT_CLASS sac; // [sp+14h] [bp-14h]@10
  TResult result; // [sp+18h] [bp-10h]@2
  char v15; // [sp+1Ch] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+20h] [bp-8h]@2

  v1 = this;
  if ( !this->m_SelectedSkill )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_1, &_rpInterface);
  v3 = _rpInterface;
  v11 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v15, v11, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = (CACQualities *)playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = v1->m_SelectedSkill;
  sac = 0;
  CACQualities::InqSkillAdvancementClass((CACQualities *)&playerDesc.m_pInterface->vfptr, v7, &sac);
  if ( (signed int)sac < 2 )
  {
    gmSkillUI::TrainSkill(v1, v5);
    v5->vfptr->Release((Interface *)v5);
    v6 = 1;
  }
  else
  {
    v8 = v1->vfptr;
    v1->m_bAwaitingRaise = 1;
    v9 = (int)v8[29].__vecDelDtor((IInputActionCallback *)v1, (unsigned int)v5);
    CM_Train::Event_TrainSkill(v1->m_SelectedSkill, v9);
    v10 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v1->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v10 + 156))(v10, 13);
    v5->vfptr->Release((Interface *)v5);
    v6 = 1;
  }
  return v6;
}

//----- (006EEFF0) --------------------------------------------------------  // acclient.c:771105
void _E91_61()
{
  outside_val_53 = 1000.0 + 1.0;
}

//----- (006EF010) --------------------------------------------------------  // acclient.c:771111
void _E93_37()
{
  block_length_53 = 24.0 * 8.0;
}

//----- (006EF030) --------------------------------------------------------  // acclient.c:771117
void _E95_37()
{
  half_square_length_53 = 24.0 * 0.5;
}

//----- (006EF050) --------------------------------------------------------  // acclient.c:771123
int _E97_62()
{
  return atexit(_E98_74);
}

//----- (006EF060) --------------------------------------------------------  // acclient.c:771129
int _E100_55()
{
  return atexit(_E101_92);
}

//----- (006EF070) --------------------------------------------------------  // acclient.c:771135
int _E103_47()
{
  return atexit(_E104_62);
}

//----- (006EF080) --------------------------------------------------------  // acclient.c:771141
unsigned int _E106_37()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_XPToLevelMeterInfinity");
  ID_StatManagement_Header_XPToLevelMeterInfinity = result;
  return result;
}

//----- (006EF0A0) --------------------------------------------------------  // acclient.c:771151
unsigned int _E108_27()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_DefaultSkillTitle");
  ID_StatManagement_Footer_DefaultSkillTitle = result;
  return result;
}

//----- (006EF0C0) --------------------------------------------------------  // acclient.c:771161
unsigned int _E110_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsLabel");
  ID_StatManagement_Footer_SkillCreditsLabel = result;
  return result;
}

//----- (006EF0E0) --------------------------------------------------------  // acclient.c:771171
unsigned int _E112_32()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsValue");
  ID_StatManagement_Footer_SkillCreditsValue = result;
  return result;
}

//----- (006EF100) --------------------------------------------------------  // acclient.c:771181
unsigned int _E114_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_ExperienceLabel");
  ID_StatManagement_Footer_ExperienceLabel = result;
  return result;
}

//----- (006EF120) --------------------------------------------------------  // acclient.c:771191
unsigned int _E116_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_ExperienceValue");
  ID_StatManagement_Footer_ExperienceValue = result;
  return result;
}

//----- (006EF140) --------------------------------------------------------  // acclient.c:771201
unsigned int _E118_29()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_XPToRaiseLabel");
  ID_StatManagement_Footer_XPToRaiseLabel = result;
  return result;
}

//----- (006EF160) --------------------------------------------------------  // acclient.c:771211
unsigned int _E120_19()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_XPToRaiseValue");
  ID_StatManagement_Footer_XPToRaiseValue = result;
  return result;
}

//----- (006EF180) --------------------------------------------------------  // acclient.c:771221
unsigned int _E122_8()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsToRaiseLabel");
  ID_StatManagement_Footer_SkillCreditsToRaiseLabel = result;
  return result;
}

//----- (006EF1A0) --------------------------------------------------------  // acclient.c:771231
unsigned int _E124_30()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsToRaiseValue");
  ID_StatManagement_Footer_SkillCreditsToRaiseValue = result;
  return result;
}

//----- (006EF1C0) --------------------------------------------------------  // acclient.c:771241
unsigned int _E126_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("AVAILABLE_EXPERIENCE");
  ID_AvailableExperience = result;
  return result;
}

//----- (006EF1E0) --------------------------------------------------------  // acclient.c:771251
unsigned int _E128_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("SKILL_CREDITS");
  ID_SkillCredits = result;
  return result;
}

//----- (006EF200) --------------------------------------------------------  // acclient.c:771261
unsigned int _E130_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("XP_TO_RAISE");
  ID_XPToRaise = result;
  return result;
}

//----- (006EF220) --------------------------------------------------------  // acclient.c:771271
unsigned int _E132_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("CREDITS_TO_TRAIN");
  ID_SkillCreditsToRaise = result;
  return result;
}

//----- (006EF240) --------------------------------------------------------  // acclient.c:771281
int sub_6EF240()
{
  return atexit(nullsub_853);
}

