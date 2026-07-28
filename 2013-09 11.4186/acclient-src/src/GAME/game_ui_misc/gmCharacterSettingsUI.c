/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCharacterSettingsUI
   Object     : GAME\game_ui_misc\gmCharacterSettingsUI.obj
   Functions  : 20
   Addresses  : 004A01A0 - 006F0960 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A01A0) --------------------------------------------------------  // acclient.c:217202
signed int __thiscall gmCharacterSettingsUI::DynamicCast(gmCharacterSettingsUI *this, unsigned int i_eType)
{
  return i_eType != 268435495 ? 0 : (unsigned int)this;
}

//----- (004A01C0) --------------------------------------------------------  // acclient.c:217208
signed int gmCharacterSettingsUI::GetUIElementType()
{
  return 268435495;
}

//----- (004A01D0) --------------------------------------------------------  // acclient.c:217214
UIElement *__usercall gmCharacterSettingsUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x608u);
  if ( v3 )
  {
    PlayerOptionPage::PlayerOptionPage((PlayerOptionPage *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 385) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmCharacterSettingsUI::vftable;
    *((_DWORD *)v3 + 380) = &gmConfigUI::vftable;
    *((_DWORD *)v3 + 385) = &ClientHousingSystem::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A93F0: using guessed type int (__thiscall *gmCharacterSettingsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);

//----- (004A0230) --------------------------------------------------------  // acclient.c:217240
gmCharacterSettingsUI *__thiscall gmCharacterSettingsUI::vector_deleting_destructor(gmCharacterSettingsUI *this, unsigned int a2)
{
  gmCharacterSettingsUI *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmCharacterSettingsUI::vftable;
  v2->vfptr = (IOptionChangeHandlerVtbl *)&gmConfigUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  PlayerOptionPage::~PlayerOptionPage((PlayerOptionPage *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A93F0: using guessed type int (__thiscall *gmCharacterSettingsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);

//----- (004A0280) --------------------------------------------------------  // acclient.c:217262
void __thiscall gmCharacterSettingsUI::PostInit(gmCharacterSettingsUI *this)
{
  gmCharacterSettingsUI *v1; // esi@1
  UIElement *v2; // eax@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001FAu);
  if ( v2 )
    v1->m_pOptionBox = (UIElement_ListBox *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  ((void (__thiscall *)(gmCharacterSettingsUI *))v1->vfptr[27].__vecDelDtor)(v1);
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
}

//----- (004A02D0) --------------------------------------------------------  // acclient.c:217277
void __cdecl gmCharacterSettingsUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000027u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCharacterSettingsUI::Create);
}

//----- (004A02F0) --------------------------------------------------------  // acclient.c:217285
void __thiscall gmCharacterSettingsUI::InitOptions(gmCharacterSettingsUI *this)
{
  PlayerOptionPage *v1; // esi@1
  unsigned int v2; // ebx@1
  UIOption_Checkbox *v3; // eax@5
  unsigned int v4; // ebx@5
  UIOption_Checkbox *v5; // eax@9
  unsigned int v6; // ebx@9
  UIOption_Checkbox *v7; // eax@13
  unsigned int v8; // ebx@13
  UIOption_Checkbox *v9; // eax@17
  unsigned int v10; // edi@17
  UIOption_Checkbox *v11; // eax@21
  unsigned int v12; // edi@21
  UIOption_Checkbox *v13; // eax@25
  unsigned int v14; // edi@25
  UIOption_Checkbox *v15; // eax@29
  unsigned int v16; // edi@29
  UIOption_Checkbox *v17; // eax@33
  unsigned int v18; // edi@33
  UIOption_Checkbox *v19; // eax@37
  unsigned int v20; // edi@37
  UIOption_Checkbox *v21; // eax@41
  unsigned int v22; // edi@41
  UIOption_Checkbox *v23; // eax@45
  unsigned int v24; // edi@45
  UIOption_Checkbox *v25; // eax@49
  unsigned int v26; // edi@49
  UIOption_Checkbox *v27; // eax@53
  unsigned int v28; // edi@53
  UIOption_Checkbox *v29; // eax@57
  unsigned int v30; // edi@57
  UIOption_Checkbox *v31; // eax@61
  unsigned int v32; // edi@61
  UIOption_Checkbox *v33; // eax@65
  unsigned int v34; // ebx@65
  UIOption_Checkbox *v35; // eax@69
  unsigned int v36; // ebx@69
  UIOption_Checkbox *v37; // eax@73
  unsigned int v38; // ebx@73
  UIOption_Checkbox *v39; // eax@77
  unsigned int v40; // ebx@77
  UIOption_Checkbox *v41; // eax@81
  unsigned int v42; // edi@81
  UIOption_Checkbox *v43; // eax@85
  unsigned int v44; // edi@85
  UIOption_Checkbox *v45; // eax@89
  unsigned int v46; // edi@89
  UIOption_Checkbox *v47; // eax@93
  unsigned int v48; // edi@93
  UIOption_Checkbox *v49; // eax@97
  unsigned int v50; // edi@97
  UIOption_Checkbox *v51; // eax@101
  unsigned int v52; // edi@101
  UIOption_Checkbox *v53; // eax@105
  unsigned int v54; // edi@105
  UIOption_Checkbox *v55; // eax@109
  unsigned int v56; // edi@109
  UIOption_Checkbox *v57; // eax@113
  unsigned int v58; // edi@113
  UIOption_Checkbox *v59; // eax@117
  unsigned int v60; // edi@117
  UIOption_Checkbox *v61; // eax@121
  unsigned int v62; // edi@121
  UIOption_Checkbox *v63; // eax@125
  unsigned int v64; // edi@125
  UIOption_Checkbox *v65; // eax@129
  unsigned int v66; // ebx@129
  UIOption_Checkbox *v67; // eax@133
  unsigned int v68; // ebx@133
  UIOption_Checkbox *v69; // eax@137
  unsigned int v70; // ebx@137
  UIOption_Checkbox *v71; // eax@141
  unsigned int v72; // ebx@141
  UIOption_Checkbox *v73; // eax@145
  unsigned int v74; // edi@145
  UIOption_Checkbox *v75; // eax@149
  unsigned int v76; // edi@149
  UIOption_Checkbox *v77; // eax@153
  unsigned int v78; // edi@153
  UIOption_Checkbox *v79; // eax@157
  unsigned int v80; // edi@157
  UIOption_Checkbox *v81; // eax@161
  unsigned int v82; // edi@161
  UIOption_Checkbox *v83; // eax@165
  unsigned int v84; // edi@165
  UIOption_Checkbox *v85; // eax@169
  unsigned int v86; // edi@169
  UIOption_Checkbox *v87; // eax@173
  unsigned int v88; // edi@173
  UIOption_Checkbox *v89; // eax@177
  unsigned int v90; // edi@177
  UIOption_Checkbox *v91; // eax@181
  unsigned int v92; // edi@181
  UIOption_Checkbox *v93; // eax@185
  unsigned int v94; // edi@185
  UIOption_Checkbox *v95; // eax@189
  unsigned int v96; // edi@189
  UIOption_Checkbox *v97; // eax@193
  unsigned int v98; // ebx@193
  UIOption_Checkbox *v99; // eax@197

  v1 = (PlayerOptionPage *)this;
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&this->vfptr, ID_CharacterOption_UIBehavior_Section);
  v2 = _S118_53;
  if ( !(_S118_53 & 1) )
  {
    v2 = _S118_53 | 1;
    _S118_53 |= 1u;
    ID_PlayerOption_ViewCombatTarget = compute_str_hash("ID_PlayerOption_ViewCombatTarget");
  }
  if ( !(v2 & 2) )
  {
    _S118_53 = v2 | 2;
    ID_PlayerOption_ViewCombatTarget_Help = compute_str_hash("ID_PlayerOption_ViewCombatTarget_Help");
  }
  v3 = PlayerOptionPage::AddToggleOption(v1, ViewCombatTarget_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v3, ID_PlayerOption_ViewCombatTarget, ID_PlayerOption_ViewCombatTarget_Help);
  v4 = _S118_53;
  if ( !(_S118_53 & 4) )
  {
    v4 = _S118_53 | 4;
    _S118_53 |= 4u;
    ID_PlayerOption_SalvageMultiple = compute_str_hash("ID_PlayerOption_SalvageMultiple");
  }
  if ( !(v4 & 8) )
  {
    _S118_53 = v4 | 8;
    ID_PlayerOption_SalvageMultiple_Help = compute_str_hash("ID_PlayerOption_SalvageMultiple_Help");
  }
  v5 = PlayerOptionPage::AddToggleOption(v1, SalvageMultiple_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v5, ID_PlayerOption_SalvageMultiple, ID_PlayerOption_SalvageMultiple_Help);
  v6 = _S118_53;
  if ( !(_S118_53 & 0x10) )
  {
    v6 = _S118_53 | 0x10;
    _S118_53 |= 0x10u;
    ID_PlayerOption_MainPackPreferred = compute_str_hash("ID_PlayerOption_MainPackPreferred");
  }
  if ( !(v6 & 0x20) )
  {
    _S118_53 = v6 | 0x20;
    ID_PlayerOption_MainPackPreferred_Help = compute_str_hash("ID_PlayerOption_MainPackPreferred_Help");
  }
  v7 = PlayerOptionPage::AddToggleOption(v1, MainPackPreferred_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v7, ID_PlayerOption_MainPackPreferred, ID_PlayerOption_MainPackPreferred_Help);
  PlayerOptionPage::AddSeperator(v1);
  PlayerOptionPage::AddHeader(v1, ID_CharacterOption_UIDisplay_Section);
  v8 = _S118_53;
  if ( !(_S118_53 & 0x40) )
  {
    v8 = _S118_53 | 0x40;
    _S118_53 |= 0x40u;
    ID_PlayerOption_VividTargetingIndicator = compute_str_hash("ID_PlayerOption_VividTargetingIndicator");
  }
  if ( (v8 & 0x80u) == 0 )
  {
    _S118_53 = v8 | 0x80;
    ID_PlayerOption_VividTargetingIndicator_Help = compute_str_hash("ID_PlayerOption_VividTargetingIndicator_Help");
  }
  v9 = PlayerOptionPage::AddToggleOption(v1, VividTargetingIndicator_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v9,
    ID_PlayerOption_VividTargetingIndicator,
    ID_PlayerOption_VividTargetingIndicator_Help);
  v10 = _S118_53;
  if ( !(_S118_53 & 0x100) )
  {
    v10 = _S118_53 | 0x100;
    _S118_53 |= 0x100u;
    ID_PlayerOption_ShowTooltips = compute_str_hash("ID_PlayerOption_ShowTooltips");
  }
  if ( !(v10 & 0x200) )
  {
    _S118_53 = v10 | 0x200;
    ID_PlayerOption_ShowTooltips_Help = compute_str_hash("ID_PlayerOption_ShowTooltips_Help");
  }
  v11 = PlayerOptionPage::AddToggleOption(v1, ShowTooltips_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v11, ID_PlayerOption_ShowTooltips, ID_PlayerOption_ShowTooltips_Help);
  v12 = _S118_53;
  if ( !(_S118_53 & 0x400) )
  {
    v12 = _S118_53 | 0x400;
    _S118_53 |= 0x400u;
    ID_PlayerOption_CoordinatesOnRadar = compute_str_hash("ID_PlayerOption_CoordinatesOnRadar");
  }
  if ( !(v12 & 0x800) )
  {
    _S118_53 = v12 | 0x800;
    ID_PlayerOption_CoordinatesOnRadar_Help = compute_str_hash("ID_PlayerOption_CoordinatesOnRadar_Help");
  }
  v13 = PlayerOptionPage::AddToggleOption(v1, CoordinatesOnRadar_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v13, ID_PlayerOption_CoordinatesOnRadar, ID_PlayerOption_CoordinatesOnRadar_Help);
  v14 = _S118_53;
  if ( !(_S118_53 & 0x1000) )
  {
    v14 = _S118_53 | 0x1000;
    _S118_53 |= 0x1000u;
    ID_PlayerOption_SideBySideVitals = compute_str_hash("ID_PlayerOption_SideBySideVitals");
  }
  if ( !(v14 & 0x2000) )
  {
    _S118_53 = v14 | 0x2000;
    ID_PlayerOption_SideBySideVitals_Help = compute_str_hash("ID_PlayerOption_SideBySideVitals_Help");
  }
  v15 = PlayerOptionPage::AddToggleOption(v1, SideBySideVitals_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v15, ID_PlayerOption_SideBySideVitals, ID_PlayerOption_SideBySideVitals_Help);
  v16 = _S118_53;
  if ( !(_S118_53 & 0x4000) )
  {
    v16 = _S118_53 | 0x4000;
    _S118_53 |= 0x4000u;
    ID_PlayerOption_SpellDuration = compute_str_hash("ID_PlayerOption_SpellDuration");
  }
  if ( !(v16 & 0x8000) )
  {
    _S118_53 = v16 | 0x8000;
    ID_PlayerOption_SpellDuration_Help = compute_str_hash("ID_PlayerOption_SpellDuration_Help");
  }
  v17 = PlayerOptionPage::AddToggleOption(v1, SpellDuration_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v17, ID_PlayerOption_SpellDuration, ID_PlayerOption_SpellDuration_Help);
  v18 = _S118_53;
  if ( !(_S118_53 & 0x10000) )
  {
    v18 = _S118_53 | 0x10000;
    _S118_53 |= 0x10000u;
    ID_PlayerOption_DisableMostWeatherEffects = compute_str_hash("ID_PlayerOption_DisableMostWeatherEffects");
  }
  if ( !(v18 & 0x20000) )
  {
    _S118_53 = v18 | 0x20000;
    ID_PlayerOption_DisableMostWeatherEffects_Help = compute_str_hash("ID_PlayerOption_DisableMostWeatherEffects_Help");
  }
  v19 = PlayerOptionPage::AddToggleOption(v1, DisableMostWeatherEffects_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v19,
    ID_PlayerOption_DisableMostWeatherEffects,
    ID_PlayerOption_DisableMostWeatherEffects_Help);
  v20 = _S118_53;
  if ( !(_S118_53 & 0x40000) )
  {
    v20 = _S118_53 | 0x40000;
    _S118_53 |= 0x40000u;
    ID_PlayerOption_DisableDistanceFog = compute_str_hash("ID_PlayerOption_DisableDistanceFog");
  }
  if ( !(v20 & 0x80000) )
  {
    _S118_53 = v20 | 0x80000;
    ID_PlayerOption_DisableDistanceFog_Help = compute_str_hash("ID_PlayerOption_DisableDistanceFog_Help");
  }
  v21 = PlayerOptionPage::AddToggleOption(v1, DisableDistanceFog_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v21, ID_PlayerOption_DisableDistanceFog, ID_PlayerOption_DisableDistanceFog_Help);
  v22 = _S118_53;
  if ( !(_S118_53 & 0x100000) )
  {
    v22 = _S118_53 | 0x100000;
    _S118_53 |= 0x100000u;
    ID_PlayerOption_PersistentAtDay = compute_str_hash("ID_PlayerOption_PersistentAtDay");
  }
  if ( !(v22 & 0x200000) )
  {
    _S118_53 = v22 | 0x200000;
    ID_PlayerOption_PersistentAtDay_Help = compute_str_hash("ID_PlayerOption_PersistentAtDay_Help");
  }
  v23 = PlayerOptionPage::AddToggleOption(v1, PersistentAtDay_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v23, ID_PlayerOption_PersistentAtDay, ID_PlayerOption_PersistentAtDay_Help);
  v24 = _S118_53;
  if ( !(_S118_53 & 0x400000) )
  {
    v24 = _S118_53 | 0x400000;
    _S118_53 |= 0x400000u;
    ID_PlayerOption_DisableHouseRestrictionEffects = compute_str_hash("ID_PlayerOption_DisableHouseRestrictionEffects");
  }
  if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v24) )
  {
    _S118_53 = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | v24;
    ID_PlayerOption_DisableHouseRestrictionEffects_Help = compute_str_hash("ID_PlayerOption_DisableHouseRestrictionEffects_Help");
  }
  v25 = PlayerOptionPage::AddToggleOption(v1, DisableHouseRestrictionEffects_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v25,
    ID_PlayerOption_DisableHouseRestrictionEffects,
    ID_PlayerOption_DisableHouseRestrictionEffects_Help);
  v26 = _S118_53;
  if ( !(_S118_53 & 0x1000000) )
  {
    v26 = _S118_53 | 0x1000000;
    _S118_53 |= 0x1000000u;
    ID_PlayerOption_UseCraftSuccessDialog = compute_str_hash("ID_PlayerOption_UseCraftSuccessDialog");
  }
  if ( !(v26 & 0x2000000) )
  {
    _S118_53 = v26 | 0x2000000;
    ID_PlayerOption_UseCraftSuccessDialog_Help = compute_str_hash("ID_PlayerOption_UseCraftSuccessDialog_Help");
  }
  v27 = PlayerOptionPage::AddToggleOption(v1, UseCraftSuccessDialog_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v27,
    ID_PlayerOption_UseCraftSuccessDialog,
    ID_PlayerOption_UseCraftSuccessDialog_Help);
  v28 = _S118_53;
  if ( !(_S118_53 & 0x4000000) )
  {
    v28 = _S118_53 | 0x4000000;
    _S118_53 |= 0x4000000u;
    ID_PlayerOption_ConfirmVolatileRareUse = compute_str_hash("ID_PlayerOption_ConfirmVolatileRareUse");
  }
  if ( !(v28 & 0x8000000) )
  {
    _S118_53 = v28 | 0x8000000;
    ID_PlayerOption_ConfirmVolatileRareUse_Help = compute_str_hash("ID_PlayerOption_ConfirmVolatileRareUse_Help");
  }
  v29 = PlayerOptionPage::AddToggleOption(v1, ConfirmVolatileRareUse_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v29,
    ID_PlayerOption_ConfirmVolatileRareUse,
    ID_PlayerOption_ConfirmVolatileRareUse_Help);
  v30 = _S118_53;
  if ( !(_S118_53 & 0x10000000) )
  {
    v30 = _S118_53 | 0x10000000;
    _S118_53 |= 0x10000000u;
    ID_PlayerOption_DisplayTimeStamps = compute_str_hash("ID_PlayerOption_DisplayTimeStamps");
  }
  if ( !(v30 & 0x20000000) )
  {
    _S118_53 = v30 | 0x20000000;
    ID_PlayerOption_DisplayTimeStamps_Help = compute_str_hash("ID_PlayerOption_DisplayTimeStamps_Help");
  }
  v31 = PlayerOptionPage::AddToggleOption(v1, DisplayTimeStamps_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v31, ID_PlayerOption_DisplayTimeStamps, ID_PlayerOption_DisplayTimeStamps_Help);
  v32 = _S118_53;
  if ( !(_S118_53 & 0x40000000) )
  {
    v32 = _S118_53 | 0x40000000;
    _S118_53 |= 0x40000000u;
    ID_PlayerOption_FilterLanguage = compute_str_hash("ID_PlayerOption_FilterLanguage");
  }
  if ( (v32 & 0x80000000) == 0 )
  {
    _S118_53 = v32 | 0x80000000;
    ID_PlayerOption_FilterLanguage_Help = compute_str_hash("ID_PlayerOption_FilterLanguage_Help");
  }
  v33 = PlayerOptionPage::AddToggleOption(v1, FilterLanguage_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v33, ID_PlayerOption_FilterLanguage, ID_PlayerOption_FilterLanguage_Help);
  v34 = dword_83E9A8;
  if ( !(dword_83E9A8 & 1) )
  {
    v34 = dword_83E9A8 | 1;
    dword_83E9A8 |= 1u;
    ID_PlayerOption_ShowHelm = compute_str_hash("ID_PlayerOption_ShowHelm");
  }
  if ( !(v34 & 2) )
  {
    dword_83E9A8 = v34 | 2;
    ID_PlayerOption_ShowHelm_Help = compute_str_hash("ID_PlayerOption_ShowHelm_Help");
  }
  v35 = PlayerOptionPage::AddToggleOption(v1, ShowHelm_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v35, ID_PlayerOption_ShowHelm, ID_PlayerOption_ShowHelm_Help);
  v36 = dword_83E9A8;
  if ( !(dword_83E9A8 & 4) )
  {
    v36 = dword_83E9A8 | 4;
    dword_83E9A8 |= 4u;
    ID_PlayerOption_ShowCloak = compute_str_hash("ID_PlayerOption_ShowCloak");
  }
  if ( !(v36 & 8) )
  {
    dword_83E9A8 = v36 | 8;
    ID_PlayerOption_ShowCloak_Help = compute_str_hash("ID_PlayerOption_ShowCloak_Help");
  }
  v37 = PlayerOptionPage::AddToggleOption(v1, ShowCloak_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v37, ID_PlayerOption_ShowCloak, ID_PlayerOption_ShowCloak_Help);
  PlayerOptionPage::AddSeperator(v1);
  PlayerOptionPage::AddHeader(v1, ID_CharacterOption_Grouping_Section);
  v38 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x10) )
  {
    v38 = dword_83E9A8 | 0x10;
    dword_83E9A8 |= 0x10u;
    ID_PlayerOption_IgnoreAllegianceRequests = compute_str_hash("ID_PlayerOption_IgnoreAllegianceRequests");
  }
  if ( !(v38 & 0x20) )
  {
    dword_83E9A8 = v38 | 0x20;
    ID_PlayerOption_IgnoreAllegianceRequests_Help = compute_str_hash("ID_PlayerOption_IgnoreAllegianceRequests_Help");
  }
  v39 = PlayerOptionPage::AddToggleOption(v1, IgnoreAllegianceRequests_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v39,
    ID_PlayerOption_IgnoreAllegianceRequests,
    ID_PlayerOption_IgnoreAllegianceRequests_Help);
  v40 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x40) )
  {
    v40 = dword_83E9A8 | 0x40;
    dword_83E9A8 |= 0x40u;
    ID_PlayerOption_IgnoreFellowshipRequests = compute_str_hash("ID_PlayerOption_IgnoreFellowshipRequests");
  }
  if ( (v40 & 0x80u) == 0 )
  {
    dword_83E9A8 = v40 | 0x80;
    ID_PlayerOption_IgnoreFellowshipRequests_Help = compute_str_hash("ID_PlayerOption_IgnoreFellowshipRequests_Help");
  }
  v41 = PlayerOptionPage::AddToggleOption(v1, IgnoreFellowshipRequests_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v41,
    ID_PlayerOption_IgnoreFellowshipRequests,
    ID_PlayerOption_IgnoreFellowshipRequests_Help);
  v42 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x100) )
  {
    v42 = dword_83E9A8 | 0x100;
    dword_83E9A8 |= 0x100u;
    ID_PlayerOption_DisplayAllegianceLogonNotifications = compute_str_hash("ID_PlayerOption_DisplayAllegianceLogonNotifications");
  }
  if ( !(v42 & 0x200) )
  {
    dword_83E9A8 = v42 | 0x200;
    ID_PlayerOption_DisplayAllegianceLogonNotifications_Help = compute_str_hash("ID_PlayerOption_DisplayAllegianceLogonNotifications_Help");
  }
  v43 = PlayerOptionPage::AddToggleOption(v1, DisplayAllegianceLogonNotifications_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v43,
    ID_PlayerOption_DisplayAllegianceLogonNotifications,
    ID_PlayerOption_DisplayAllegianceLogonNotifications_Help);
  v44 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x400) )
  {
    v44 = dword_83E9A8 | 0x400;
    dword_83E9A8 |= 0x400u;
    ID_PlayerOption_FellowshipShareXP = compute_str_hash("ID_PlayerOption_FellowshipShareXP");
  }
  if ( !(v44 & 0x800) )
  {
    dword_83E9A8 = v44 | 0x800;
    ID_PlayerOption_FellowshipShareXP_Help = compute_str_hash("ID_PlayerOption_FellowshipShareXP_Help");
  }
  v45 = PlayerOptionPage::AddToggleOption(v1, FellowshipShareXP_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v45, ID_PlayerOption_FellowshipShareXP, ID_PlayerOption_FellowshipShareXP_Help);
  v46 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x1000) )
  {
    v46 = dword_83E9A8 | 0x1000;
    dword_83E9A8 |= 0x1000u;
    ID_PlayerOption_FellowshipShareLoot = compute_str_hash("ID_PlayerOption_FellowshipShareLoot");
  }
  if ( !(v46 & 0x2000) )
  {
    dword_83E9A8 = v46 | 0x2000;
    ID_PlayerOption_FellowshipShareLoot_Help = compute_str_hash("ID_PlayerOption_FellowshipShareLoot_Help");
  }
  v47 = PlayerOptionPage::AddToggleOption(v1, FellowshipShareLoot_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v47, ID_PlayerOption_FellowshipShareLoot, ID_PlayerOption_FellowshipShareLoot_Help);
  v48 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x4000) )
  {
    v48 = dword_83E9A8 | 0x4000;
    dword_83E9A8 |= 0x4000u;
    ID_PlayerOption_FellowshipAutoAcceptRequests = compute_str_hash("ID_PlayerOption_FellowshipAutoAcceptRequests");
  }
  if ( !(v48 & 0x8000) )
  {
    dword_83E9A8 = v48 | 0x8000;
    ID_PlayerOption_FellowshipAutoAcceptRequests_Help = compute_str_hash("ID_PlayerOption_FellowshipAutoAcceptRequests_Help");
  }
  v49 = PlayerOptionPage::AddToggleOption(v1, FellowshipAutoAcceptRequests_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v49,
    ID_PlayerOption_FellowshipAutoAcceptRequests,
    ID_PlayerOption_FellowshipAutoAcceptRequests_Help);
  PlayerOptionPage::AddSeperator(v1);
  PlayerOptionPage::AddHeader(v1, ID_CharacterOption_OtherPlayers_Section);
  v50 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x10000) )
  {
    v50 = dword_83E9A8 | 0x10000;
    dword_83E9A8 |= 0x10000u;
    ID_PlayerOption_AcceptLootPermits = compute_str_hash("ID_PlayerOption_AcceptLootPermits");
  }
  if ( !(v50 & 0x20000) )
  {
    dword_83E9A8 = v50 | 0x20000;
    ID_PlayerOption_AcceptLootPermits_Help = compute_str_hash("ID_PlayerOption_AcceptLootPermits_Help");
  }
  v51 = PlayerOptionPage::AddToggleOption(v1, AcceptLootPermits_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v51, ID_PlayerOption_AcceptLootPermits, ID_PlayerOption_AcceptLootPermits_Help);
  v52 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x40000) )
  {
    v52 = dword_83E9A8 | 0x40000;
    dword_83E9A8 |= 0x40000u;
    ID_PlayerOption_UseDeception = compute_str_hash("ID_PlayerOption_UseDeception");
  }
  if ( !(v52 & 0x80000) )
  {
    dword_83E9A8 = v52 | 0x80000;
    ID_PlayerOption_UseDeception_Help = compute_str_hash("ID_PlayerOption_UseDeception_Help");
  }
  v53 = PlayerOptionPage::AddToggleOption(v1, UseDeception_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v53, ID_PlayerOption_UseDeception, ID_PlayerOption_UseDeception_Help);
  v54 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x100000) )
  {
    v54 = dword_83E9A8 | 0x100000;
    dword_83E9A8 |= 0x100000u;
    ID_PlayerOption_AllowGive = compute_str_hash("ID_PlayerOption_AllowGive");
  }
  if ( !(v54 & 0x200000) )
  {
    dword_83E9A8 = v54 | 0x200000;
    ID_PlayerOption_AllowGive_Help = compute_str_hash("ID_PlayerOption_AllowGive_Help");
  }
  v55 = PlayerOptionPage::AddToggleOption(v1, AllowGive_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v55, ID_PlayerOption_AllowGive, ID_PlayerOption_AllowGive_Help);
  v56 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x400000) )
  {
    v56 = dword_83E9A8 | 0x400000;
    dword_83E9A8 |= 0x400000u;
    ID_PlayerOption_IgnoreTradeRequests = compute_str_hash("ID_PlayerOption_IgnoreTradeRequests");
  }
  if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v56) )
  {
    dword_83E9A8 = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | v56;
    ID_PlayerOption_IgnoreTradeRequests_Help = compute_str_hash("ID_PlayerOption_IgnoreTradeRequests_Help");
  }
  v57 = PlayerOptionPage::AddToggleOption(v1, IgnoreTradeRequests_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v57, ID_PlayerOption_IgnoreTradeRequests, ID_PlayerOption_IgnoreTradeRequests_Help);
  v58 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x1000000) )
  {
    v58 = dword_83E9A8 | 0x1000000;
    dword_83E9A8 |= 0x1000000u;
    ID_PlayerOption_DragItemOnPlayerOpensSecureTrade = compute_str_hash("ID_PlayerOption_DragItemOnPlayerOpensSecureTrade");
  }
  if ( !(v58 & 0x2000000) )
  {
    dword_83E9A8 = v58 | 0x2000000;
    ID_PlayerOption_DragItemOnPlayerOpensSecureTrade_Help = compute_str_hash("ID_PlayerOption_DragItemOnPlayerOpensSecureTrade_Help");
  }
  v59 = PlayerOptionPage::AddToggleOption(v1, DragItemOnPlayerOpensSecureTrade_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v59,
    ID_PlayerOption_DragItemOnPlayerOpensSecureTrade,
    ID_PlayerOption_DragItemOnPlayerOpensSecureTrade_Help);
  v60 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x4000000) )
  {
    v60 = dword_83E9A8 | 0x4000000;
    dword_83E9A8 |= 0x4000000u;
    ID_PlayerOption_DisplayDateOfBirth = compute_str_hash("ID_PlayerOption_DisplayDateOfBirth");
  }
  if ( !(v60 & 0x8000000) )
  {
    dword_83E9A8 = v60 | 0x8000000;
    ID_PlayerOption_DisplayDateOfBirth_Help = compute_str_hash("ID_PlayerOption_DisplayDateOfBirth_Help");
  }
  v61 = PlayerOptionPage::AddToggleOption(v1, DisplayDateOfBirth_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v61, ID_PlayerOption_DisplayDateOfBirth, ID_PlayerOption_DisplayDateOfBirth_Help);
  v62 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x10000000) )
  {
    v62 = dword_83E9A8 | 0x10000000;
    dword_83E9A8 |= 0x10000000u;
    ID_PlayerOption_DisplayAge = compute_str_hash("ID_PlayerOption_DisplayAge");
  }
  if ( !(v62 & 0x20000000) )
  {
    dword_83E9A8 = v62 | 0x20000000;
    ID_PlayerOption_DisplayAge_Help = compute_str_hash("ID_PlayerOption_DisplayAge_Help");
  }
  v63 = PlayerOptionPage::AddToggleOption(v1, DisplayAge_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v63, ID_PlayerOption_DisplayAge, ID_PlayerOption_DisplayAge_Help);
  v64 = dword_83E9A8;
  if ( !(dword_83E9A8 & 0x40000000) )
  {
    v64 = dword_83E9A8 | 0x40000000;
    dword_83E9A8 |= 0x40000000u;
    ID_PlayerOption_DisplayChessRank = compute_str_hash("ID_PlayerOption_DisplayChessRank");
  }
  if ( (v64 & 0x80000000) == 0 )
  {
    dword_83E9A8 = v64 | 0x80000000;
    ID_PlayerOption_DisplayChessRank_Help = compute_str_hash("ID_PlayerOption_DisplayChessRank_Help");
  }
  v65 = PlayerOptionPage::AddToggleOption(v1, DisplayChessRank_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v65, ID_PlayerOption_DisplayChessRank, ID_PlayerOption_DisplayChessRank_Help);
  v66 = dword_83E924;
  if ( !(dword_83E924 & 1) )
  {
    v66 = dword_83E924 | 1;
    dword_83E924 |= 1u;
    ID_PlayerOption_DisplayFishingSkill = compute_str_hash("ID_PlayerOption_DisplayFishingSkill");
  }
  if ( !(v66 & 2) )
  {
    dword_83E924 = v66 | 2;
    ID_PlayerOption_DisplayFishingSkill_Help = compute_str_hash("ID_PlayerOption_DisplayFishingSkill_Help");
  }
  v67 = PlayerOptionPage::AddToggleOption(v1, DisplayFishingSkill_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v67, ID_PlayerOption_DisplayFishingSkill, ID_PlayerOption_DisplayFishingSkill_Help);
  v68 = dword_83E924;
  if ( !(dword_83E924 & 4) )
  {
    v68 = dword_83E924 | 4;
    dword_83E924 |= 4u;
    ID_PlayerOption_DisplayNumberDeaths = compute_str_hash("ID_PlayerOption_DisplayNumberDeaths");
  }
  if ( !(v68 & 8) )
  {
    dword_83E924 = v68 | 8;
    ID_PlayerOption_DisplayNumberDeaths_Help = compute_str_hash("ID_PlayerOption_DisplayNumberDeaths_Help");
  }
  v69 = PlayerOptionPage::AddToggleOption(v1, DisplayNumberDeaths_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v69, ID_PlayerOption_DisplayNumberDeaths, ID_PlayerOption_DisplayNumberDeaths_Help);
  v70 = dword_83E924;
  if ( !(dword_83E924 & 0x10) )
  {
    v70 = dword_83E924 | 0x10;
    dword_83E924 |= 0x10u;
    ID_PlayerOption_DisplayNumberCharacterTitles = compute_str_hash("ID_PlayerOption_DisplayNumberCharacterTitles");
  }
  if ( !(v70 & 0x20) )
  {
    dword_83E924 = v70 | 0x20;
    ID_PlayerOption_DisplayNumberCharacterTitles_Help = compute_str_hash("ID_PlayerOption_DisplayNumberCharacterTitles_Help");
  }
  v71 = PlayerOptionPage::AddToggleOption(v1, DisplayNumberCharacterTitles_PlayerOption);
  PlayerOptionPage::SetToggleLabel(
    v71,
    ID_PlayerOption_DisplayNumberCharacterTitles,
    ID_PlayerOption_DisplayNumberCharacterTitles_Help);
  PlayerOptionPage::AddSeperator(v1);
  PlayerOptionPage::AddHeader(v1, ID_CharacterOption_CharacterBehavior_Section);
  v72 = dword_83E924;
  if ( !(dword_83E924 & 0x40) )
  {
    v72 = dword_83E924 | 0x40;
    dword_83E924 |= 0x40u;
    ID_PlayerOption_ToggleRun = compute_str_hash("ID_PlayerOption_ToggleRun");
  }
  if ( (v72 & 0x80u) == 0 )
  {
    dword_83E924 = v72 | 0x80;
    ID_PlayerOption_ToggleRun_Help = compute_str_hash("ID_PlayerOption_ToggleRun_Help");
  }
  v73 = PlayerOptionPage::AddToggleOption(v1, ToggleRun_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v73, ID_PlayerOption_ToggleRun, ID_PlayerOption_ToggleRun_Help);
  v74 = dword_83E924;
  if ( !(dword_83E924 & 0x100) )
  {
    v74 = dword_83E924 | 0x100;
    dword_83E924 |= 0x100u;
    ID_PlayerOption_AdvancedCombatUI = compute_str_hash("ID_PlayerOption_AdvancedCombatUI");
  }
  if ( !(v74 & 0x200) )
  {
    dword_83E924 = v74 | 0x200;
    ID_PlayerOption_AdvancedCombatUI_Help = compute_str_hash("ID_PlayerOption_AdvancedCombatUI_Help");
  }
  v75 = PlayerOptionPage::AddToggleOption(v1, AdvancedCombatUI_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v75, ID_PlayerOption_AdvancedCombatUI, ID_PlayerOption_AdvancedCombatUI_Help);
  v76 = dword_83E924;
  if ( !(dword_83E924 & 0x400) )
  {
    v76 = dword_83E924 | 0x400;
    dword_83E924 |= 0x400u;
    ID_PlayerOption_AutoTarget = compute_str_hash("ID_PlayerOption_AutoTarget");
  }
  if ( !(v76 & 0x800) )
  {
    dword_83E924 = v76 | 0x800;
    ID_PlayerOption_AutoTarget_Help = compute_str_hash("ID_PlayerOption_AutoTarget_Help");
  }
  v77 = PlayerOptionPage::AddToggleOption(v1, AutoTarget_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v77, ID_PlayerOption_AutoTarget, ID_PlayerOption_AutoTarget_Help);
  v78 = dword_83E924;
  if ( !(dword_83E924 & 0x1000) )
  {
    v78 = dword_83E924 | 0x1000;
    dword_83E924 |= 0x1000u;
    ID_PlayerOption_AutoRepeatAttack = compute_str_hash("ID_PlayerOption_AutoRepeatAttack");
  }
  if ( !(v78 & 0x2000) )
  {
    dword_83E924 = v78 | 0x2000;
    ID_PlayerOption_AutoRepeatAttack_Help = compute_str_hash("ID_PlayerOption_AutoRepeatAttack_Help");
  }
  v79 = PlayerOptionPage::AddToggleOption(v1, 0);
  PlayerOptionPage::SetToggleLabel(v79, ID_PlayerOption_AutoRepeatAttack, ID_PlayerOption_AutoRepeatAttack_Help);
  v80 = dword_83E924;
  if ( !(dword_83E924 & 0x4000) )
  {
    v80 = dword_83E924 | 0x4000;
    dword_83E924 |= 0x4000u;
    ID_PlayerOption_UseChargeAttack = compute_str_hash("ID_PlayerOption_UseChargeAttack");
  }
  if ( !(v80 & 0x8000) )
  {
    dword_83E924 = v80 | 0x8000;
    ID_PlayerOption_UseChargeAttack_Help = compute_str_hash("ID_PlayerOption_UseChargeAttack_Help");
  }
  v81 = PlayerOptionPage::AddToggleOption(v1, UseChargeAttack_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v81, ID_PlayerOption_UseChargeAttack, ID_PlayerOption_UseChargeAttack_Help);
  v82 = dword_83E924;
  if ( !(dword_83E924 & 0x10000) )
  {
    v82 = dword_83E924 | 0x10000;
    dword_83E924 |= 0x10000u;
    ID_PlayerOption_LeadMissileTargets = compute_str_hash("ID_PlayerOption_LeadMissileTargets");
  }
  if ( !(v82 & 0x20000) )
  {
    dword_83E924 = v82 | 0x20000;
    ID_PlayerOption_LeadMissileTargets_Help = compute_str_hash("ID_PlayerOption_LeadMissileTargets_Help");
  }
  v83 = PlayerOptionPage::AddToggleOption(v1, LeadMissileTargets_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v83, ID_PlayerOption_LeadMissileTargets, ID_PlayerOption_LeadMissileTargets_Help);
  v84 = dword_83E924;
  if ( !(dword_83E924 & 0x40000) )
  {
    v84 = dword_83E924 | 0x40000;
    dword_83E924 |= 0x40000u;
    ID_PlayerOption_UseFastMissiles = compute_str_hash("ID_PlayerOption_UseFastMissiles");
  }
  if ( !(v84 & 0x80000) )
  {
    dword_83E924 = v84 | 0x80000;
    ID_PlayerOption_UseFastMissiles_Help = compute_str_hash("ID_PlayerOption_UseFastMissiles_Help");
  }
  v85 = PlayerOptionPage::AddToggleOption(v1, UseFastMissiles_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v85, ID_PlayerOption_UseFastMissiles, ID_PlayerOption_UseFastMissiles_Help);
  PlayerOptionPage::AddSeperator(v1);
  PlayerOptionPage::AddHeader(v1, ID_CharacterOption_Chat_Section);
  v86 = dword_83E924;
  if ( !(dword_83E924 & 0x100000) )
  {
    v86 = dword_83E924 | 0x100000;
    dword_83E924 |= 0x100000u;
    ID_PlayerOption_StayInChatMode = compute_str_hash("ID_PlayerOption_StayInChatMode");
  }
  if ( !(v86 & 0x200000) )
  {
    dword_83E924 = v86 | 0x200000;
    ID_PlayerOption_StayInChatMode_Help = compute_str_hash("ID_PlayerOption_StayInChatMode_Help");
  }
  v87 = PlayerOptionPage::AddToggleOption(v1, StayInChatMode_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v87, ID_PlayerOption_StayInChatMode, ID_PlayerOption_StayInChatMode_Help);
  v88 = dword_83E924;
  if ( !(dword_83E924 & 0x400000) )
  {
    v88 = dword_83E924 | 0x400000;
    dword_83E924 |= 0x400000u;
    ID_PlayerOption_HearAllegianceChat = compute_str_hash("ID_PlayerOption_HearAllegianceChat");
  }
  if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v88) )
  {
    dword_83E924 = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | v88;
    ID_PlayerOption_HearAllegianceChat_Help = compute_str_hash("ID_PlayerOption_HearAllegianceChat_Help");
  }
  v89 = PlayerOptionPage::AddToggleOption(v1, HearAllegianceChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v89, ID_PlayerOption_HearAllegianceChat, ID_PlayerOption_HearAllegianceChat_Help);
  v90 = dword_83E924;
  if ( !(dword_83E924 & 0x1000000) )
  {
    v90 = dword_83E924 | 0x1000000;
    dword_83E924 |= 0x1000000u;
    ID_PlayerOption_HearGeneralChat = compute_str_hash("ID_PlayerOption_HearGeneralChat");
  }
  if ( !(v90 & 0x2000000) )
  {
    dword_83E924 = v90 | 0x2000000;
    ID_PlayerOption_HearGeneralChat_Help = compute_str_hash("ID_PlayerOption_HearGeneralChat_Help");
  }
  v91 = PlayerOptionPage::AddToggleOption(v1, HearGeneralChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v91, ID_PlayerOption_HearGeneralChat, ID_PlayerOption_HearGeneralChat_Help);
  v92 = dword_83E924;
  if ( !(dword_83E924 & 0x4000000) )
  {
    v92 = dword_83E924 | 0x4000000;
    dword_83E924 |= 0x4000000u;
    ID_PlayerOption_HearTradeChat = compute_str_hash("ID_PlayerOption_HearTradeChat");
  }
  if ( !(v92 & 0x8000000) )
  {
    dword_83E924 = v92 | 0x8000000;
    ID_PlayerOption_HearTradeChat_Help = compute_str_hash("ID_PlayerOption_HearTradeChat_Help");
  }
  v93 = PlayerOptionPage::AddToggleOption(v1, HearTradeChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v93, ID_PlayerOption_HearTradeChat, ID_PlayerOption_HearTradeChat_Help);
  v94 = dword_83E924;
  if ( !(dword_83E924 & 0x10000000) )
  {
    v94 = dword_83E924 | 0x10000000;
    dword_83E924 |= 0x10000000u;
    ID_PlayerOption_HearLFGChat = compute_str_hash("ID_PlayerOption_HearLFGChat");
  }
  if ( !(v94 & 0x20000000) )
  {
    dword_83E924 = v94 | 0x20000000;
    ID_PlayerOption_HearLFGChat_Help = compute_str_hash("ID_PlayerOption_HearLFGChat_Help");
  }
  v95 = PlayerOptionPage::AddToggleOption(v1, HearLFGChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v95, ID_PlayerOption_HearLFGChat, ID_PlayerOption_HearLFGChat_Help);
  v96 = dword_83E924;
  if ( !(dword_83E924 & 0x40000000) )
  {
    v96 = dword_83E924 | 0x40000000;
    dword_83E924 |= 0x40000000u;
    ID_PlayerOption_HearRoleplayChat = compute_str_hash("ID_PlayerOption_HearRoleplayChat");
  }
  if ( (v96 & 0x80000000) == 0 )
  {
    dword_83E924 = v96 | 0x80000000;
    ID_PlayerOption_HearRoleplayChat_Help = compute_str_hash("ID_PlayerOption_HearRoleplayChat_Help");
  }
  v97 = PlayerOptionPage::AddToggleOption(v1, HearRoleplayChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v97, ID_PlayerOption_HearRoleplayChat, ID_PlayerOption_HearRoleplayChat_Help);
  v98 = _S121_37;
  if ( !(_S121_37 & 1) )
  {
    v98 = _S121_37 | 1;
    _S121_37 |= 1u;
    ID_PlayerOption_HearSocietyChat = compute_str_hash("ID_PlayerOption_HearSocietyChat");
  }
  if ( !(v98 & 2) )
  {
    _S121_37 = v98 | 2;
    ID_PlayerOption_HearSocietyChat_Help = compute_str_hash("ID_PlayerOption_HearSocietyChat_Help");
  }
  v99 = PlayerOptionPage::AddToggleOption(v1, HearSocietyChat_PlayerOption);
  PlayerOptionPage::SetToggleLabel(v99, ID_PlayerOption_HearSocietyChat, ID_PlayerOption_HearSocietyChat_Help);
  PlayerOptionPage::AddSeperator(v1);
}

//----- (006F0810) --------------------------------------------------------  // acclient.c:772665
void _E91_66()
{
  outside_val_58 = 1000.0 + 1.0;
}

//----- (006F0830) --------------------------------------------------------  // acclient.c:772671
void _E93_42()
{
  block_length_58 = 24.0 * 8.0;
}

//----- (006F0850) --------------------------------------------------------  // acclient.c:772677
void _E95_42()
{
  half_square_length_58 = 24.0 * 0.5;
}

//----- (006F0870) --------------------------------------------------------  // acclient.c:772683
int _E97_67()
{
  return atexit(_E98_79);
}

//----- (006F0880) --------------------------------------------------------  // acclient.c:772689
int _E100_60()
{
  return atexit(_E101_97);
}

//----- (006F0890) --------------------------------------------------------  // acclient.c:772695
int _E103_52()
{
  return atexit(_E104_67);
}

//----- (006F08A0) --------------------------------------------------------  // acclient.c:772701
unsigned int _E106_42()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_UIBehavior_Section");
  ID_CharacterOption_UIBehavior_Section = result;
  return result;
}

//----- (006F08C0) --------------------------------------------------------  // acclient.c:772711
unsigned int _E108_30()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_UIDisplay_Section");
  ID_CharacterOption_UIDisplay_Section = result;
  return result;
}

//----- (006F08E0) --------------------------------------------------------  // acclient.c:772721
unsigned int _E110_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_Grouping_Section");
  ID_CharacterOption_Grouping_Section = result;
  return result;
}

//----- (006F0900) --------------------------------------------------------  // acclient.c:772731
unsigned int _E112_37()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_OtherPlayers_Section");
  ID_CharacterOption_OtherPlayers_Section = result;
  return result;
}

//----- (006F0920) --------------------------------------------------------  // acclient.c:772741
unsigned int _E114_24()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_CharacterBehavior_Section");
  ID_CharacterOption_CharacterBehavior_Section = result;
  return result;
}

//----- (006F0940) --------------------------------------------------------  // acclient.c:772751
unsigned int _E116_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterOption_Chat_Section");
  ID_CharacterOption_Chat_Section = result;
  return result;
}

//----- (006F0960) --------------------------------------------------------  // acclient.c:772761
int sub_6F0960()
{
  return atexit(nullsub_924);
}

