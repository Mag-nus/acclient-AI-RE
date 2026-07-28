/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmAttributeUI
   Object     : GAME\game_ui_misc\gmAttributeUI.obj
   Functions  : 34
   Addresses  : 0049C9D0 - 006EF440 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049C9D0) --------------------------------------------------------  // acclient.c:214184
gmAttributeUI *__thiscall gmAttributeUI::DynamicCast(gmAttributeUI *this, unsigned int i_eType)
{
  gmAttributeUI *result; // eax@1

  result = this;
  if ( i_eType != 268435498 )
    result = (gmAttributeUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0049C9F0) --------------------------------------------------------  // acclient.c:214195
signed int gmAttributeUI::GetUIElementType()
{
  return 268435498;
}

//----- (0049CA00) --------------------------------------------------------  // acclient.c:214201
UIElement *__usercall gmAttributeUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x640u);
  if ( v3 )
  {
    gmStatManagementUI::gmStatManagementUI((gmStatManagementUI *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &gmAttributeUI::vftable;
    *((_DWORD *)v3 + 382) = &gmAttributeUI::vftable;
    *((_DWORD *)v3 + 383) = gmStatManagementUI::vftable;
    *((_DWORD *)v3 + 399) = -1;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7B50: using guessed type bool (__thiscall *gmAttributeUI::vftable)(DBCache *this);
// 7A7DF8: using guessed type int (__thiscall *gmAttributeUI::vftable)(void *, char);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (0049CA60) --------------------------------------------------------  // acclient.c:214227
gmAttributeUI *__thiscall gmAttributeUI::scalar_deleting_destructor(gmAttributeUI *this, unsigned int a2)
{
  gmAttributeUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmAttributeUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmAttributeUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmStatManagementUI::vftable;
  gmStatManagementUI::~gmStatManagementUI((gmStatManagementUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A7B50: using guessed type bool (__thiscall *gmAttributeUI::vftable)(DBCache *this);
// 7A7DF8: using guessed type int (__thiscall *gmAttributeUI::vftable)(void *, char);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (0049CAA0) --------------------------------------------------------  // acclient.c:214245
void __cdecl gmAttributeUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000002Au,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmAttributeUI::Create);
}

//----- (0049CAC0) --------------------------------------------------------  // acclient.c:214253
int __thiscall gmAttributeUI::SetSelection(gmAttributeUI *this, UIElement *_selectedUI)
{
  gmAttributeUI *v2; // edi@1
  IInputActionCallbackVtbl *v3; // eax@2
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@5
  unsigned int v6; // edx@5
  bool v7; // zf@9
  int v8; // eax@11
  int index; // [sp+14h] [bp-Ch]@1
  BaseProperty infoProperty; // [sp+18h] [bp-8h]@2

  v2 = this;
  index = -1;
  if ( _selectedUI )
  {
    v3 = _selectedUI->vfptr;
    infoProperty.m_pcPropertyDesc = 0;
    infoProperty.m_pcPropertyValue = 0;
    ((void (__stdcall *)(signed int, BaseProperty *))v3[17].OnAction)(268435514, &infoProperty);
    v4 = infoProperty.m_pcPropertyValue;
    if ( infoProperty.m_pcPropertyValue )
    {
      ((void (__stdcall *)(_DWORD))infoProperty.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&index);
      v4 = infoProperty.m_pcPropertyValue;
    }
    if ( (_DWORD)infoProperty.m_pcPropertyDesc )
    {
      v5 = infoProperty.m_pcPropertyDesc;
      v6 = infoProperty.m_pcPropertyDesc->m_cRef - 1;
      infoProperty.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      v4 = infoProperty.m_pcPropertyValue;
      infoProperty.m_pcPropertyDesc = 0;
    }
    if ( v4 )
    {
      v7 = v4->m_cRef-- == 1;
      if ( v7 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    }
  }
  v8 = index;
  if ( v2->m_SelectedIndex == index )
  {
    v8 = -1;
    index = -1;
  }
  v2->m_SelectedIndex = v8;
  return ((int (__thiscall *)(gmAttributeUI *))v2->vfptr[28].__vecDelDtor)(v2);
}

//----- (0049CB80) --------------------------------------------------------  // acclient.c:214307
int __thiscall gmAttributeUI::GetCostToRaise(gmAttributeUI *this, CACQualities *i_playerDesc)
{
  gmAttributeUI *v2; // esi@1
  InfoRegion **v3; // ecx@2
  int v4; // eax@2
  unsigned int v5; // eax@2
  unsigned int v6; // esi@2
  int result; // eax@3
  unsigned int v8; // esi@4
  int v9; // edx@5
  InfoRegion **v10; // eax@5
  unsigned int v11; // eax@5
  unsigned int v12; // esi@5
  unsigned int v13; // esi@6
  SecondaryAttribute attribute2; // [sp+4h] [bp-14h]@2

  v2 = this;
  if ( ((int (*)(void))this->m_rgTokens.m_data[this->m_SelectedIndex]->vfptr[2].OnQualityRemoved)() == 8 )
  {
    v3 = v2->m_rgTokens.m_data;
    attribute2._level_from_cp = 0;
    attribute2._init_level = 0;
    attribute2._cp_spent = 0;
    v4 = v2->m_SelectedIndex;
    attribute2.vfptr = (PackObjVtbl *)&Attribute::vftable;
    v5 = ((int (*)(void))v3[v4]->vfptr[3].OnQualityChanged)();
    CACQualities::InqAttribute(i_playerDesc, v5, (Attribute *)&attribute2.vfptr);
    v6 = attribute2._level_from_cp;
    if ( v6 >= ExperienceSystem::GetMaxAttributeLevel() )
      return 0;
    v8 = attribute2._cp_spent;
    result = ExperienceSystem::ExperienceToAttributeLevel(attribute2._level_from_cp + 1) - v8;
  }
  else
  {
    v9 = v2->m_SelectedIndex;
    attribute2._level_from_cp = 0;
    attribute2._init_level = 0;
    attribute2._cp_spent = 0;
    attribute2._current_level = 0;
    v10 = v2->m_rgTokens.m_data;
    attribute2.vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
    v11 = ((int (*)(void))v10[v9]->vfptr[3].OnQualityChanged)();
    CACQualities::InqAttribute2nd(i_playerDesc, v11, &attribute2);
    v12 = attribute2._level_from_cp;
    if ( v12 >= ExperienceSystem::GetMaxAttribute2ndLevel() )
      return 0;
    v13 = attribute2._cp_spent;
    result = ExperienceSystem::ExperienceToAttribute2ndLevel(attribute2._level_from_cp + 1) - v13;
  }
  return result;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (0049CC70) --------------------------------------------------------  // acclient.c:214363
int __thiscall gmAttributeUI::GetCostToRaise10(gmAttributeUI *this, CACQualities *i_playerDesc)
{
  gmAttributeUI *v2; // esi@1
  int v3; // eax@1
  InfoRegion **v4; // ecx@1
  bool v5; // zf@1
  int v6; // eax@1
  unsigned int v7; // eax@2
  unsigned int v8; // esi@2
  unsigned int v9; // esi@3
  int v10; // eax@3
  signed int v11; // ecx@3
  unsigned int v12; // esi@5
  unsigned int v14; // eax@6
  unsigned int v15; // esi@6
  unsigned int v16; // esi@7
  int v17; // eax@7
  signed int v18; // ecx@7
  unsigned int v19; // esi@9
  SecondaryAttribute attribute2; // [sp+8h] [bp-14h]@1

  v2 = this;
  v3 = ((int (*)(void))this->m_rgTokens.m_data[this->m_SelectedIndex]->vfptr[2].OnQualityRemoved)();
  v4 = v2->m_rgTokens.m_data;
  v5 = v3 == 8;
  v6 = v2->m_SelectedIndex;
  attribute2._cp_spent = 0;
  attribute2._init_level = 0;
  attribute2._level_from_cp = 0;
  if ( v5 )
  {
    attribute2.vfptr = (PackObjVtbl *)&Attribute::vftable;
    v7 = ((int (*)(void))v4[v6]->vfptr[3].OnQualityChanged)();
    CACQualities::InqAttribute(i_playerDesc, v7, (Attribute *)&attribute2.vfptr);
    v8 = attribute2._level_from_cp;
    if ( v8 < ExperienceSystem::GetMaxAttributeLevel() )
    {
      v9 = attribute2._level_from_cp;
      v10 = ExperienceSystem::GetMaxAttributeLevel() - v9;
      v11 = 10;
      if ( v10 >= 10 || (v11 = v10, v10 > 0) )
      {
        v12 = attribute2._cp_spent;
        return ExperienceSystem::ExperienceToAttributeLevel(v11 + attribute2._level_from_cp) - v12;
      }
    }
  }
  else
  {
    attribute2.vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
    attribute2._current_level = 0;
    v14 = ((int (*)(void))v4[v6]->vfptr[3].OnQualityChanged)();
    CACQualities::InqAttribute2nd(i_playerDesc, v14, &attribute2);
    v15 = attribute2._level_from_cp;
    if ( v15 < ExperienceSystem::GetMaxAttribute2ndLevel() )
    {
      v16 = attribute2._level_from_cp;
      v17 = ExperienceSystem::GetMaxAttribute2ndLevel() - v16;
      v18 = 10;
      if ( v17 >= 10 || (v18 = v17, v17 > 0) )
      {
        v19 = attribute2._cp_spent;
        return ExperienceSystem::ExperienceToAttribute2ndLevel(v18 + attribute2._level_from_cp) - v19;
      }
    }
  }
  return 0;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (0049CD90) --------------------------------------------------------  // acclient.c:214435
BOOL __thiscall gmAttributeUI::MessageIsFromSelectedElement(gmAttributeUI *this, StatType i_statType, unsigned int i_statEnum)
{
  gmAttributeUI *v3; // esi@1
  int v4; // eax@1

  v3 = this;
  v4 = this->m_SelectedIndex;
  return v4 != -1
      && ((int (*)(void))this->m_rgTokens.m_data[v4]->vfptr[2].OnQualityRemoved)() == i_statType
      && ((int (*)(void))v3->m_rgTokens.m_data[v3->m_SelectedIndex]->vfptr[3].OnQualityChanged)() == i_statEnum;
}

//----- (0049CDE0) --------------------------------------------------------  // acclient.c:214448
char __thiscall gmAttributeUI::DisplayDefaultFooter(gmAttributeUI *this, CACQualities *i_playerDesc)
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
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_DefaultAttributeTitle, 268435457);
  v3 = StringInfo::GetString(&siText, &result, 0);
  v4 = gmStatManagementUI::GetFooterTitleLabel(v2);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v4, v3, 0, 0);
  v5 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsLabel_0, 268435457);
  v6 = StringInfo::GetString(&siText, &result, 0);
  v7 = gmStatManagementUI::GetFooterLineOneLabel(v2);
  UIElement_Text::SetText((UIElement_Text *)v7, v6);
  v8 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  skillCredits = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x18u, (int *)&skillCredits, 0, 0);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_SkillCreditsValue_0, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_SkillCredits_0, skillCredits);
  v9 = StringInfo::GetString(&siText, &result, 0);
  v10 = gmStatManagementUI::GetFooterLineOneValue(v2);
  UIElement_Text::SetText((UIElement_Text *)v10, v9);
  v11 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceLabel_0, 268435457);
  v12 = StringInfo::GetString(&siText, &result, 0);
  v13 = gmStatManagementUI::GetFooterLineTwoLabel(v2);
  UIElement_Text::SetText((UIElement_Text *)v13, v12);
  v14 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  availableXP = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 2u, (__int64 *)&availableXP);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceValue_0, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_AvailableExperience_0, availableXP);
  v15 = StringInfo::GetString(&siText, &result, 0);
  v16 = gmStatManagementUI::GetFooterLineTwoValue(v2);
  UIElement_Text::SetText((UIElement_Text *)v16, v15);
  v17 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (0049D020) --------------------------------------------------------  // acclient.c:214519
char __thiscall gmAttributeUI::RaiseSelection(gmAttributeUI *this)
{
  gmStatManagementUI *v1; // esi@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // edi@2
  int v4; // ebp@4
  unsigned int v5; // edi@6
  int v7; // eax@10
  InfoRegion *v8; // ebx@11
  int v9; // eax@11
  unsigned int v10; // eax@11
  InfoRegion *v11; // ebx@12
  int v12; // eax@12
  unsigned int v13; // eax@12
  int v14; // eax@13
  int v15; // [sp-8h] [bp-2Ch]@2
  int v16; // [sp+0h] [bp-24h]@0
  Interface *_rpInterface; // [sp+10h] [bp-14h]@2
  TResult result; // [sp+14h] [bp-10h]@2
  char v19; // [sp+18h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@2

  v1 = (gmStatManagementUI *)this;
  if ( this->m_SelectedIndex == -1 )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_2, &_rpInterface);
  v3 = _rpInterface;
  v15 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v19, v15, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = (unsigned int)playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = ((int (__stdcall *)(int))v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr]->vfptr[2].OnQualityRemoved)(v16);
  v1->m_bAwaitingRaise = 1;
  if ( v7 == 8 )
  {
    v8 = v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr];
    v9 = ((int (__thiscall *)(gmStatManagementUI *))v1->vfptr[29].__vecDelDtor)(v1);
    v10 = ((int (__thiscall *)(InfoRegion *, int))v8->vfptr[3].OnQualityChanged)(v8, v9);
    CM_Train::Event_TrainAttribute(v10, v5);
  }
  else
  {
    v11 = v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr];
    v12 = ((int (__thiscall *)(gmStatManagementUI *))v1->vfptr[29].__vecDelDtor)(v1);
    v13 = ((int (__thiscall *)(InfoRegion *, int))v11->vfptr[3].OnQualityChanged)(v11, v12);
    CM_Train::Event_TrainAttribute2nd(v13, v5);
  }
  v14 = gmStatManagementUI::GetFooterButton(v1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 156))(v14);
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 20))(v5);
  return 1;
}

//----- (0049D150) --------------------------------------------------------  // acclient.c:214587
char __thiscall gmAttributeUI::Raise10Selection(gmAttributeUI *this)
{
  gmStatManagementUI *v1; // esi@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // edi@2
  int v4; // ebp@4
  unsigned int v5; // edi@6
  int v7; // eax@10
  InfoRegion *v8; // ebx@11
  int v9; // eax@11
  unsigned int v10; // eax@11
  InfoRegion *v11; // ebx@12
  int v12; // eax@12
  unsigned int v13; // eax@12
  int v14; // eax@13
  int v15; // [sp-8h] [bp-2Ch]@2
  int v16; // [sp+0h] [bp-24h]@0
  Interface *_rpInterface; // [sp+10h] [bp-14h]@2
  TResult result; // [sp+14h] [bp-10h]@2
  char v19; // [sp+18h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@2

  v1 = (gmStatManagementUI *)this;
  if ( this->m_SelectedIndex == -1 )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_2, &_rpInterface);
  v3 = _rpInterface;
  v15 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v19, v15, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = (unsigned int)playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = ((int (__stdcall *)(int))v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr]->vfptr[2].OnQualityRemoved)(v16);
  v1->m_bAwaitingRaise = 1;
  if ( v7 == 8 )
  {
    v8 = v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr];
    v9 = ((int (__thiscall *)(gmStatManagementUI *))v1->vfptr[29].OnLoseFocus)(v1);
    v10 = ((int (__thiscall *)(InfoRegion *, int))v8->vfptr[3].OnQualityChanged)(v8, v9);
    CM_Train::Event_TrainAttribute(v10, v5);
  }
  else
  {
    v11 = v1->m_rgTokens.m_data[(unsigned int)v1[1].vfptr];
    v12 = ((int (__thiscall *)(gmStatManagementUI *))v1->vfptr[29].OnLoseFocus)(v1);
    v13 = ((int (__thiscall *)(InfoRegion *, int))v11->vfptr[3].OnQualityChanged)(v11, v12);
    CM_Train::Event_TrainAttribute2nd(v13, v5);
  }
  v14 = gmStatManagementUI::GetFooter10Button(v1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 156))(v14);
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 20))(v5);
  return 1;
}

//----- (0049D280) --------------------------------------------------------  // acclient.c:214655
char __thiscall gmAttributeUI::DisplaySelectionFooter_Attribute(gmAttributeUI *this, CACQualities *i_playerDesc)
{
  gmAttributeUI *v2; // esi@1
  InfoRegion **v3; // edx@1
  int v4; // ecx@1
  unsigned int v5; // eax@1
  CACQualities *v6; // ebp@1
  int v7; // eax@1
  InfoRegion **v8; // ecx@1
  unsigned int v9; // eax@1
  int v10; // eax@1
  unsigned int v11; // edi@1
  int v12; // ebp@2
  int v13; // eax@6
  LONG (__stdcall *v14)(volatile LONG *); // ebx@6
  char *v15; // edi@6
  char *v16; // edi@9
  PStringBase<unsigned short> *v17; // ST0C_4@13
  int v18; // eax@13
  char *v19; // edi@13
  PSRefBufferCharData<unsigned short> *v20; // edi@16
  PStringBase<unsigned short> *v21; // ST0C_4@20
  int v22; // eax@20
  char *v23; // edi@20
  PStringBase<unsigned short> *v24; // ST0C_4@23
  int v25; // eax@23
  char *v26; // edi@23
  PStringBase<unsigned short> *v27; // ST0C_4@26
  int v28; // eax@26
  char *v29; // edi@26
  int v30; // eax@31
  int v31; // eax@32
  int v32; // eax@33
  int v33; // eax@35
  int v34; // eax@36
  char *v35; // esi@37
  char *v36; // esi@40
  PStringBase<unsigned short> strModTypeText; // [sp+1Ch] [bp-B0h]@2
  PStringBase<unsigned short> strModText; // [sp+20h] [bp-ACh]@6
  unsigned int uStatValMod; // [sp+24h] [bp-A8h]@1
  unsigned __int64 availableXP; // [sp+28h] [bp-A4h]@26
  PStringBase<unsigned short> strValueText; // [sp+30h] [bp-9Ch]@1
  unsigned int uStatValRaw; // [sp+34h] [bp-98h]@1
  PStringBase<unsigned short> strLabel; // [sp+38h] [bp-94h]@1
  StringInfo siText; // [sp+3Ch] [bp-90h]@13

  strLabel.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  ((void (__stdcall *)(PStringBase<unsigned short> *))v2->m_rgTokens.m_data[v2->m_SelectedIndex]->vfptr[1].OnQualityRemoved)(&strLabel);
  v3 = v2->m_rgTokens.m_data;
  v4 = v2->m_SelectedIndex;
  uStatValRaw = 0;
  v5 = ((int (*)(void))v3[v4]->vfptr[3].OnQualityChanged)();
  v6 = i_playerDesc;
  CACQualities::InqAttribute(i_playerDesc, v5, &uStatValRaw, 1);
  v7 = v2->m_SelectedIndex;
  v8 = v2->m_rgTokens.m_data;
  uStatValMod = 0;
  v9 = ((int (*)(void))v8[v7]->vfptr[3].OnQualityChanged)();
  CACQualities::InqAttribute(i_playerDesc, v9, &uStatValMod, 0);
  strValueText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&strValueText, L"%s: %d", strLabel.m_charbuffer, uStatValMod);
  v10 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v10, &strValueText, 0, 0);
  v11 = uStatValMod - uStatValRaw;
  if ( uStatValMod == uStatValRaw )
  {
    v14 = InterlockedDecrement;
  }
  else
  {
    strModTypeText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    v12 = 0;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( uStatValRaw >= uStatValMod )
    {
      if ( uStatValRaw > uStatValMod )
        v12 = 2;
    }
    else
    {
      v12 = 1;
      PStringBase<unsigned short>::set(&strModTypeText, L"+");
    }
    strModText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strModText, L" (%s%d)", strModTypeText.m_charbuffer, v11);
    v13 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v2->vfptr);
    UIElement_Text::AppendTextWithFont((UIElement_Text *)v13, &strModText, 0, v12);
    v14 = InterlockedDecrement;
    v15 = (char *)&strModText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModText.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    v16 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    v6 = i_playerDesc;
  }
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseLabel_0, 268435457);
  v17 = StringInfo::GetString(&siText, &strModTypeText, 0);
  v18 = gmStatManagementUI::GetFooterLineOneLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v18, v17);
  v19 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  v20 = (PSRefBufferCharData<unsigned short> *)v2->vfptr[29].__vecDelDtor((IInputActionCallback *)v2, (unsigned int)v6);
  strModText.m_charbuffer = v20;
  if ( v20 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseValue_0, 268435457);
    StringInfo::AddVariable_Int(&siText, ID_XPToRaise_0, (unsigned int)v20);
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_XPToLevelMeterInfinity_0, 268435457);
  }
  v21 = StringInfo::GetString(&siText, &strModTypeText, 0);
  v22 = gmStatManagementUI::GetFooterLineOneValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v22, v21);
  v23 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceLabel_0, 268435457);
  v24 = StringInfo::GetString(&siText, &strModTypeText, 0);
  v25 = gmStatManagementUI::GetFooterLineTwoLabel((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v25, v24);
  v26 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v26 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  availableXP = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&v6->vfptr, 2u, (__int64 *)&availableXP);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceValue_0, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_AvailableExperience_0, availableXP);
  v27 = StringInfo::GetString(&siText, &strModTypeText, 0);
  v28 = gmStatManagementUI::GetFooterLineTwoValue((gmStatManagementUI *)&v2->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v28, v27);
  v29 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v29 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
  if ( strModText.m_charbuffer && availableXP >= (unsigned int)strModText.m_charbuffer )
  {
    v30 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v30 + 156))(v30, 1);
  }
  else
  {
    v31 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v31 + 156))(v31, 13);
  }
  v32 = ((int (__thiscall *)(gmAttributeUI *, CACQualities *))v2->vfptr[29].OnLoseFocus)(v2, v6);
  if ( v32 && availableXP >= (unsigned int)v32 )
  {
    v33 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v33 + 156))(v33, 1);
  }
  else
  {
    v34 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v2->vfptr);
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v34 + 156))(v34, 13);
  }
  StringInfo::~StringInfo(&siText);
  v35 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) && v35 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v35)(v35, 1);
  v36 = (char *)&strLabel.m_charbuffer[-1].m_data[6];
  if ( !v14((volatile LONG *)&strLabel.m_charbuffer[-1].m_data[8]) && v36 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
  return 1;
}

//----- (0049D6B0) --------------------------------------------------------  // acclient.c:214829
char __userpurge gmAttributeUI::DisplaySelectionFooter_Vital@<al>(gmAttributeUI *this@<ecx>, CACQualities *i_playerDesc, CACQualities *a3)
{
  gmAttributeUI *v3; // esi@1
  InfoRegion **v4; // edx@1
  int v5; // ecx@1
  unsigned int v6; // eax@1
  int v7; // eax@1
  InfoRegion **v8; // ecx@1
  unsigned int v9; // eax@1
  InfoRegion **v10; // edx@1
  int v11; // ecx@1
  int v12; // eax@1
  int v13; // eax@1
  int v14; // ebx@1
  int v15; // eax@2
  int v16; // ebx@6
  int v17; // eax@10
  LONG (__stdcall *v18)(volatile LONG *); // ebx@10
  char *v19; // edi@10
  char *v20; // edi@13
  PStringBase<unsigned short> *v21; // ST0C_4@17
  int v22; // eax@17
  int v23; // edi@17
  PSRefBufferCharData<unsigned short> *v24; // edi@20
  PStringBase<unsigned short> *v25; // ST0C_4@23
  int v26; // eax@23
  int v27; // edi@23
  PStringBase<unsigned short> *v28; // ST0C_4@26
  int v29; // eax@26
  int v30; // edi@26
  PStringBase<unsigned short> *v31; // ST0C_4@29
  int v32; // eax@29
  int v33; // edi@29
  int v34; // eax@34
  int v35; // eax@34
  int v36; // eax@35
  char *v37; // esi@36
  char *v38; // esi@39
  int v40; // [sp+Ch] [bp-C8h]@0
  int v41; // [sp+Ch] [bp-C8h]@1
  int iMod; // [sp+1Ch] [bp-B8h]@5
  PStringBase<unsigned short> strModText; // [sp+20h] [bp-B4h]@2
  PStringBase<unsigned short> strModTypeText; // [sp+24h] [bp-B0h]@2
  unsigned int uStatValMod; // [sp+28h] [bp-ACh]@5
  PStringBase<unsigned short> strValueText; // [sp+2Ch] [bp-A8h]@1
  unsigned int uStatValRaw; // [sp+30h] [bp-A4h]@1
  PStringBase<unsigned short> strLabel; // [sp+34h] [bp-A0h]@1
  unsigned __int64 availableXP; // [sp+38h] [bp-9Ch]@1
  StringInfo siText; // [sp+44h] [bp-90h]@1

  strLabel.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  ((void (*)(void))v3->m_rgTokens.m_data[v3->m_SelectedIndex]->vfptr[1].OnQualityRemoved)();
  v4 = v3->m_rgTokens.m_data;
  v5 = v3->m_SelectedIndex;
  strValueText.m_charbuffer = 0;
  v6 = ((int (__stdcall *)(PStringBase<unsigned short> *, signed int))v4[v5]->vfptr[3].OnQualityChanged)(
         &strValueText,
         1);
  CACQualities::InqAttribute2nd(a3, v6, (unsigned int *)&strLabel, v40);
  v7 = v3->m_SelectedIndex;
  v8 = v3->m_rgTokens.m_data;
  strValueText.m_charbuffer = 0;
  v9 = ((int (*)(void))v8[v7]->vfptr[3].OnQualityChanged)();
  CACQualities::InqAttribute2nd(a3, v9, (unsigned int *)&strValueText, 0);
  v10 = v3->m_rgTokens.m_data;
  v11 = v3->m_SelectedIndex;
  siText.m_strToken.m_charbuffer = 0;
  v12 = ((int (*)(void))v10[v11]->vfptr[3].OnQualityChanged)();
  CACQualities::InqAttribute2nd(a3, v12 + 1, (unsigned int *)&siText, 0);
  uStatValRaw = (unsigned int)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(
    (PStringBase<unsigned short> *)&uStatValRaw,
    L"%s: %d/%d",
    availableXP,
    siText.m_strToken.m_charbuffer,
    strValueText.m_charbuffer);
  v13 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v3->vfptr);
  UIElement_Text::SetTextWithFont((UIElement_Text *)v13, (PStringBase<unsigned short> *)&uStatValRaw, 0, 0);
  v14 = ((int (__cdecl *)(CACQualities *))v3->m_rgTokens.m_data[v3->m_SelectedIndex]->vfptr[5].OnQualityChanged)(a3);
  if ( v14 < 0 )
  {
    strModText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strModText, L" (%d)", v14);
    v15 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v3->vfptr);
    UIElement_Text::AppendTextWithFont((UIElement_Text *)v15, &strModText, 0, 3);
    strModTypeText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)strModText.m_charbuffer - 20);
    if ( !InterlockedDecrement((volatile LONG *)&strModText.m_charbuffer[-1].m_data[8]) )
    {
      if ( strModTypeText.m_charbuffer )
        (**(void (__stdcall ***)(_DWORD))&strModTypeText.m_charbuffer->m_data[0])(1);
    }
  }
  uStatValMod -= v14;
  iMod = uStatValMod - uStatValRaw;
  if ( uStatValMod == uStatValRaw )
  {
    v18 = InterlockedDecrement;
  }
  else
  {
    strModTypeText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    v16 = 0;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( uStatValRaw >= uStatValMod )
    {
      if ( uStatValRaw > uStatValMod )
        v16 = 2;
    }
    else
    {
      v16 = 1;
      PStringBase<unsigned short>::set(&strModTypeText, L"+");
    }
    strModText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strModText, L" (%s%d)", strModTypeText.m_charbuffer, iMod);
    v17 = gmStatManagementUI::GetFooterTitleLabel((gmStatManagementUI *)&v3->vfptr);
    UIElement_Text::AppendTextWithFont((UIElement_Text *)v17, &strModText, 0, v16);
    v18 = InterlockedDecrement;
    v19 = (char *)&strModText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModText.m_charbuffer[-1].m_data[8]) && v19 )
      (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
    v20 = (char *)&strModTypeText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strModTypeText.m_charbuffer[-1].m_data[8]) && v20 )
      (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
  }
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseLabel_0, 268435457);
  v21 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v22 = gmStatManagementUI::GetFooterLineOneLabel((gmStatManagementUI *)&v3->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v22, v21);
  v23 = iMod - 20;
  if ( !v18((volatile LONG *)(iMod - 20 + 4)) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  v24 = (PSRefBufferCharData<unsigned short> *)v3->vfptr[29].__vecDelDtor((IInputActionCallback *)v3, (unsigned int)a3);
  strModTypeText.m_charbuffer = v24;
  if ( v24 )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_XPToRaiseValue_0, 268435457);
    StringInfo::AddVariable_Int(&siText, ID_XPToRaise_0, (unsigned int)v24);
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_XPToLevelMeterInfinity_0, 268435457);
  }
  v25 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v26 = gmStatManagementUI::GetFooterLineOneValue((gmStatManagementUI *)&v3->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v26, v25);
  v27 = iMod - 20;
  if ( !v18((volatile LONG *)(iMod - 20 + 4)) && v27 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceLabel_0, 268435457);
  v28 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v29 = gmStatManagementUI::GetFooterLineTwoLabel((gmStatManagementUI *)&v3->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v29, v28);
  v30 = iMod - 20;
  if ( !v18((volatile LONG *)(iMod - 20 + 4)) && v30 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
  availableXP = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&a3->vfptr, 2u, (__int64 *)&availableXP);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Footer_ExperienceValue_0, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_AvailableExperience_0, availableXP);
  v31 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&iMod, 0);
  v32 = gmStatManagementUI::GetFooterLineTwoValue((gmStatManagementUI *)&v3->vfptr);
  UIElement_Text::SetText((UIElement_Text *)v32, v31);
  v33 = iMod - 20;
  if ( !v18((volatile LONG *)(iMod - 20 + 4)) && v33 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
  if ( strModTypeText.m_charbuffer && availableXP >= (unsigned int)strModTypeText.m_charbuffer )
  {
    v34 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v3->vfptr);
    (*(void (__thiscall **)(int, signed int, int))(*(_DWORD *)v34 + 156))(v34, 1, v41);
    v35 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v3->vfptr);
  }
  else
  {
    v36 = gmStatManagementUI::GetFooterButton((gmStatManagementUI *)&v3->vfptr);
    (*(void (__thiscall **)(int, signed int, int))(*(_DWORD *)v36 + 156))(v36, 13, v41);
    v35 = gmStatManagementUI::GetFooter10Button((gmStatManagementUI *)&v3->vfptr);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v35 + 156))(v35);
  StringInfo::~StringInfo(&siText);
  v37 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
  if ( !v18((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) && v37 )
    (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
  v38 = (char *)&strLabel.m_charbuffer[-1].m_data[6];
  if ( !v18((volatile LONG *)&strLabel.m_charbuffer[-1].m_data[8]) && v38 )
    (**(void (__thiscall ***)(char *, signed int))v38)(v38, 1);
  return 1;
}

//----- (0049DB70) --------------------------------------------------------  // acclient.c:215025
void __thiscall gmAttributeUI::PostInit(gmAttributeUI *this)
{
  gmAttributeUI *v1; // esi@1
  AttributeInfoRegion *v2; // eax@3
  BSPNODE *v3; // eax@4
  AttributeInfoRegion *v4; // eax@6
  BSPNODE *v5; // eax@7
  AttributeInfoRegion *v6; // eax@9
  BSPNODE *v7; // eax@10
  AttributeInfoRegion *v8; // eax@12
  BSPNODE *v9; // eax@13
  AttributeInfoRegion *v10; // eax@15
  BSPNODE *v11; // eax@16
  AttributeInfoRegion *v12; // eax@18
  BSPNODE *v13; // eax@19
  Attribute2ndInfoRegion *v14; // eax@21
  BSPNODE *v15; // eax@22
  Attribute2ndInfoRegion *v16; // eax@24
  BSPNODE *v17; // eax@25
  Attribute2ndInfoRegion *v18; // eax@27
  BSPNODE *v19; // eax@28
  IDClass<_tagDataID,32,0> iconID; // [sp+8h] [bp-8h]@3
  BSPNODE *i_rData; // [sp+Ch] [bp-4h]@4

  v1 = this;
  gmStatManagementUI::PostInit((gmStatManagementUI *)&this->vfptr);
  if ( !v1->m_rgTokens.m_num && v1->m_pListBox )
  {
    DBObj::GetDIDByEnum(&iconID, 1, 268435458);
    v2 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v2 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v2, v1->m_pListBox, v1->m_rgTokens.m_num, 1u, iconID, 1);
      i_rData = v3;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 2, 268435458)->id;
    v4 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v4 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v4, v1->m_pListBox, v1->m_rgTokens.m_num, 2u, iconID, 1);
      i_rData = v5;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 4, 268435458)->id;
    v6 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v6 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v6, v1->m_pListBox, v1->m_rgTokens.m_num, 4u, iconID, 1);
      i_rData = v7;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 3, 268435458)->id;
    v8 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v8 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v8, v1->m_pListBox, v1->m_rgTokens.m_num, 3u, iconID, 1);
      i_rData = v9;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 5, 268435458)->id;
    v10 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v10 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v10, v1->m_pListBox, v1->m_rgTokens.m_num, 5u, iconID, 1);
      i_rData = v11;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 6, 268435458)->id;
    v12 = (AttributeInfoRegion *)operator new(0x18u);
    if ( v12 )
    {
      AttributeInfoRegion::AttributeInfoRegion(v12, v1->m_pListBox, v1->m_rgTokens.m_num, 6u, iconID, 1);
      i_rData = v13;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 2, 268435459)->id;
    v14 = (Attribute2ndInfoRegion *)operator new(0x20u);
    if ( v14 )
    {
      Attribute2ndInfoRegion::Attribute2ndInfoRegion(v14, v1->m_pListBox, v1->m_rgTokens.m_num, 2u, 0, iconID, 1);
      i_rData = v15;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 4, 268435459)->id;
    v16 = (Attribute2ndInfoRegion *)operator new(0x20u);
    if ( v16 )
    {
      Attribute2ndInfoRegion::Attribute2ndInfoRegion(v16, v1->m_pListBox, v1->m_rgTokens.m_num, 4u, 0, iconID, 1);
      i_rData = v17;
    }
    else
    {
      i_rData = 0;
    }
    SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    iconID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&i_rData, 6, 268435459)->id;
    v18 = (Attribute2ndInfoRegion *)operator new(0x20u);
    if ( v18 )
    {
      Attribute2ndInfoRegion::Attribute2ndInfoRegion(v18, v1->m_pListBox, v1->m_rgTokens.m_num, 6u, 0, iconID, 1);
      i_rData = v19;
      SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    }
    else
    {
      i_rData = 0;
      SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)&v1->m_rgTokens, &i_rData);
    }
  }
}

//----- (0049DEE0) --------------------------------------------------------  // acclient.c:215166
char __thiscall gmAttributeUI::UpdateSelection(gmAttributeUI *this)
{
  gmAttributeUI *v1; // esi@1
  unsigned int v2; // edi@1
  QualityChangeHandlerVtbl *v3; // edx@2
  InterfaceSystem *v4; // eax@6
  Interface *v5; // edi@6
  int v6; // ebx@8
  CACQualities *v7; // edi@10
  char v8; // al@13
  int v9; // [sp-8h] [bp-2Ch]@6
  CACQualities *v10; // [sp+0h] [bp-24h]@0
  Interface *_rpInterface; // [sp+10h] [bp-14h]@6
  TResult result; // [sp+14h] [bp-10h]@6
  char v13; // [sp+18h] [bp-Ch]@8
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@6

  v1 = this;
  v2 = 0;
  if ( this->m_rgTokens.m_num )
  {
    do
    {
      v3 = v1->m_rgTokens.m_data[v2]->vfptr;
      if ( v2 == v1->m_SelectedIndex )
        ((void (__stdcall *)(signed int))v3[5].OnQualityRemoved)(6);
      else
        ((void (__stdcall *)(signed int))v3[5].OnQualityRemoved)(1);
      ++v2;
    }
    while ( v2 < v1->m_rgTokens.m_num );
  }
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_2, &_rpInterface);
  v5 = _rpInterface;
  v9 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v6 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v13, v9, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v7 = (CACQualities *)playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v6 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  if ( v1->m_SelectedIndex == -1 )
  {
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435473u);
    gmAttributeUI::DisplayDefaultFooter(v1, v7);
    v7->vfptr->Release((Interface *)v7);
    v8 = 1;
  }
  else
  {
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435474u);
    if ( ((int (*)(void))v1->m_rgTokens.m_data[v1->m_SelectedIndex]->vfptr[2].OnQualityRemoved)() == 8 )
    {
      gmAttributeUI::DisplaySelectionFooter_Attribute(v1, v7);
      v7->vfptr->Release((Interface *)v7);
      v8 = 1;
    }
    else
    {
      gmAttributeUI::DisplaySelectionFooter_Vital(v1, v7, v10);
      v7->vfptr->Release((Interface *)v7);
      v8 = 1;
    }
  }
  return v8;
}

//----- (006EF250) --------------------------------------------------------  // acclient.c:771287
void _E91_62()
{
  outside_val_54 = 1000.0 + 1.0;
}

//----- (006EF270) --------------------------------------------------------  // acclient.c:771293
void _E93_38()
{
  block_length_54 = 24.0 * 8.0;
}

//----- (006EF290) --------------------------------------------------------  // acclient.c:771299
void _E95_38()
{
  half_square_length_54 = 24.0 * 0.5;
}

//----- (006EF2B0) --------------------------------------------------------  // acclient.c:771305
int _E97_63()
{
  return atexit(_E98_75);
}

//----- (006EF2C0) --------------------------------------------------------  // acclient.c:771311
int _E100_56()
{
  return atexit(_E101_93);
}

//----- (006EF2D0) --------------------------------------------------------  // acclient.c:771317
int _E103_48()
{
  return atexit(_E104_63);
}

//----- (006EF2E0) --------------------------------------------------------  // acclient.c:771323
unsigned int _E106_38()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_XPToLevelMeterInfinity");
  ID_StatManagement_Header_XPToLevelMeterInfinity_0 = result;
  return result;
}

//----- (006EF300) --------------------------------------------------------  // acclient.c:771333
unsigned int _E108_28()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_DefaultAttributeTitle");
  ID_StatManagement_Footer_DefaultAttributeTitle = result;
  return result;
}

//----- (006EF320) --------------------------------------------------------  // acclient.c:771343
unsigned int _E110_19()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsLabel");
  ID_StatManagement_Footer_SkillCreditsLabel_0 = result;
  return result;
}

//----- (006EF340) --------------------------------------------------------  // acclient.c:771353
unsigned int _E112_33()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_SkillCreditsValue");
  ID_StatManagement_Footer_SkillCreditsValue_0 = result;
  return result;
}

//----- (006EF360) --------------------------------------------------------  // acclient.c:771363
unsigned int _E114_22()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_ExperienceLabel");
  ID_StatManagement_Footer_ExperienceLabel_0 = result;
  return result;
}

//----- (006EF380) --------------------------------------------------------  // acclient.c:771373
unsigned int _E116_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_ExperienceValue");
  ID_StatManagement_Footer_ExperienceValue_0 = result;
  return result;
}

//----- (006EF3A0) --------------------------------------------------------  // acclient.c:771383
unsigned int _E118_30()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_XPToRaiseLabel");
  ID_StatManagement_Footer_XPToRaiseLabel_0 = result;
  return result;
}

//----- (006EF3C0) --------------------------------------------------------  // acclient.c:771393
unsigned int _E120_20()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Footer_XPToRaiseValue");
  ID_StatManagement_Footer_XPToRaiseValue_0 = result;
  return result;
}

//----- (006EF3E0) --------------------------------------------------------  // acclient.c:771403
unsigned int _E122_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("AVAILABLE_EXPERIENCE");
  ID_AvailableExperience_0 = result;
  return result;
}

//----- (006EF400) --------------------------------------------------------  // acclient.c:771413
unsigned int _E124_31()
{
  unsigned int result; // eax@1

  result = compute_str_hash("SKILL_CREDITS");
  ID_SkillCredits_0 = result;
  return result;
}

//----- (006EF420) --------------------------------------------------------  // acclient.c:771423
unsigned int _E126_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("XP_TO_RAISE");
  ID_XPToRaise_0 = result;
  return result;
}

//----- (006EF440) --------------------------------------------------------  // acclient.c:771433
int sub_6EF440()
{
  return atexit(nullsub_849);
}

