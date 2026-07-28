/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCharGenMainUI
   Object     : GAME\game_ui_misc\gmCharGenMainUI.obj
   Functions  : 42
   Addresses  : 004E79F0 - 007634D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E79F0) --------------------------------------------------------  // acclient.c:277436
void gmCharacterManagementUI::RecvNotice_BeginEnterWorld()
{
  UIFramework::QueueUIMode(0x10000008u);
}

//----- (004E7A10) --------------------------------------------------------  // acclient.c:277442
void __userpurge gmCharGenMainUI::SetProgressState(gmCharGenMainUI *this@<ecx>, long double a2@<st0>, gmCharGenMainUI::ECGProgress eState)
{
  gmCharGenMainUI *v3; // esi@1
  int v4; // edi@1
  UIElement_Button *v5; // ecx@1
  int v6; // eax@1
  int v7; // eax@1
  int v8; // eax@4

  v3 = this;
  ((void (__stdcall *)(_DWORD))this->m_pHeritagePage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pProfessionPage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pSkillsPage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pAppearancePage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pTownPage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pSummaryPage->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(signed int))v3->m_pRightButton->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(_DWORD))v3->m_pFinishButton->vfptr[2].__vecDelDtor)(0);
  v4 = v3->m_eProgressState;
  v5 = v3->m_pHeritageButton;
  v3->m_eProgressState = eState;
  ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pProfessionButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pSkillsButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pAppearanceButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pTownButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pSummaryButton->vfptr[13].__vecDelDtor)(1);
  CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
  v7 = *(_DWORD *)(v6 + 212);
  if ( v7 != 12 && v7 != 13 )
  {
    ((void (__stdcall *)(signed int))v3->m_pProfessionButton->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v3->m_pSkillsButton->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v3->m_pTownButton->vfptr[2].__vecDelDtor)(1);
    goto LABEL_14;
  }
  ((void (__stdcall *)(_DWORD))v3->m_pProfessionButton->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pSkillsButton->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v3->m_pTownButton->vfptr[2].__vecDelDtor)(0);
  v8 = v3->m_eProgressState;
  if ( v8 < v4 )
  {
    if ( v8 == 2 || v8 == 3 )
    {
      v3->m_eProgressState = 1;
      goto LABEL_14;
    }
    if ( v8 != 5 )
      goto LABEL_14;
LABEL_12:
    v3->m_eProgressState = 4;
    goto LABEL_14;
  }
  if ( v8 == 2 || v8 == 3 )
    goto LABEL_12;
  if ( v8 == 5 )
    v3->m_eProgressState = 6;
LABEL_14:
  switch ( v3->m_eProgressState )
  {
    case 1:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435493);
      ((void (__stdcall *)(signed int))v3->m_pHeritagePage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pHeritageButton->vfptr[13].__vecDelDtor)(6);
      gmCGHeritagePage::Update(v3->m_pHeritagePage);
      break;
    case 2:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435494);
      ((void (__stdcall *)(signed int))v3->m_pProfessionPage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pProfessionButton->vfptr[13].__vecDelDtor)(6);
      gmCGProfessionPage::Update(v3->m_pProfessionPage);
      break;
    case 3:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435495);
      ((void (__stdcall *)(signed int))v3->m_pSkillsPage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pSkillsButton->vfptr[13].__vecDelDtor)(6);
      gmCGSkillsPage::Update(v3->m_pSkillsPage);
      break;
    case 4:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435496);
      ((void (__stdcall *)(signed int))v3->m_pAppearancePage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pAppearanceButton->vfptr[13].__vecDelDtor)(6);
      gmCGAppearancePage::Update(v3->m_pAppearancePage, a2);
      break;
    case 5:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435497);
      ((void (__stdcall *)(signed int))v3->m_pTownPage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pTownButton->vfptr[13].__vecDelDtor)(6);
      gmCGTownPage::Update(v3->m_pTownPage, v4);
      break;
    case 6:
      ((void (__stdcall *)(signed int))v3->m_pMasterPage->vfptr[13].__vecDelDtor)(268435498);
      ((void (__stdcall *)(signed int))v3->m_pSummaryPage->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pSummaryButton->vfptr[13].__vecDelDtor)(6);
      gmCGSummaryPage::Update(v3->m_pSummaryPage);
      ((void (__stdcall *)(_DWORD))v3->m_pRightButton->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(signed int))v3->m_pFinishButton->vfptr[2].__vecDelDtor)(1);
      break;
    default:
      return;
  }
}

//----- (004E7D70) --------------------------------------------------------  // acclient.c:277546
void __usercall gmCharGenMainUI::DoRandom(gmCharGenMainUI *this@<ecx>, long double a2@<st0>)
{
  gmCharGenMainUI *v2; // esi@1
  CharGenState *v3; // eax@1
  CharGenState *v4; // edi@1
  bool v5; // al@2
  int v6; // eax@9
  bool v7; // al@12
  int v8; // [sp+0h] [bp-8h]@0

  v2 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v4 = v3;
  switch ( v2->m_eProgressState )
  {
    case 1:
      v5 = CPlayerSystem::AccountHasThroneOfDestiny(v2->m_pPlayerSystem);
      CharGenState::RandomizeHeritageGroup(v4, v5);
      gmCGHeritagePage::Update(v2->m_pHeritagePage);
      break;
    case 2:
      CharGenState::RandomizeTemplate(v3);
      gmCGProfessionPage::UpdateToDefaultAttributes(v2->m_pProfessionPage);
      break;
    case 3:
      CharGenState::RandomizeSkills(v3);
      gmCGSkillsPage::Update(v2->m_pSkillsPage);
      break;
    case 4:
      if ( v2->m_pAppearancePage->m_eCurType == 2 )
      {
        CharGenState::RandomizeClothing(v3, 1);
        gmCGAppearancePage::Update(v2->m_pAppearancePage, a2);
      }
      else
      {
        CharGenState::RandomizeAppearance(v3, a2, 0);
        gmCGAppearancePage::Update(v2->m_pAppearancePage, a2);
      }
      break;
    case 5:
      if ( CPlayerSystem::AccountHasThroneOfDestiny(v2->m_pPlayerSystem) )
        v6 = RandInt(4);
      else
        v6 = RandInt(3);
      CharGenState::SetStartArea(v4, v6);
      gmCGTownPage::Update(v2->m_pTownPage, v8);
      break;
    case 6:
      v7 = CPlayerSystem::AccountHasThroneOfDestiny(v2->m_pPlayerSystem);
      CharGenState::RandomizeCharacter(v4, a2, v7);
      gmCGSummaryPage::Update(v2->m_pSummaryPage);
      break;
    default:
      return;
  }
}

//----- (004E7E90) --------------------------------------------------------  // acclient.c:277605
CharacterIdentity *__thiscall CharacterSet::GetIdentity(CharacterSet *this, int indexSigned)
{
  CharacterIdentity *result; // eax@2

  if ( indexSigned >= this->set_.m_num || (result = &this->set_.m_data[indexSigned], !result->gid_) )
    result = 0;
  return result;
}

//----- (004E7EB0) --------------------------------------------------------  // acclient.c:277615
void __usercall gmCharGenMainUI::gmCharGenMainUI(gmCharGenMainUI *this@<ecx>, long double a2@<st0>)
{
  gmCharGenMainUI *v2; // esi@1
  GlobalEventHandler *v3; // eax@1
  int v4; // edi@1
  int v5; // eax@2
  UIElement *v6; // eax@3
  UIElement *v7; // ecx@3
  UIElement *v8; // eax@3
  UIElement *v9; // ecx@3
  UIElement *v10; // eax@3
  int v11; // eax@4
  UIElement *v12; // ecx@6
  UIElement *v13; // eax@6
  int v14; // eax@7
  UIElement *v15; // ecx@9
  UIElement *v16; // eax@9
  int v17; // eax@10
  UIElement *v18; // ecx@12
  UIElement *v19; // eax@12
  int v20; // eax@13
  UIElement *v21; // ecx@15
  UIElement *v22; // eax@15
  int v23; // eax@16
  UIElement *v24; // ecx@18
  UIElement *v25; // eax@18
  int v26; // eax@19
  UIElement *v27; // ecx@21
  UIElement *v28; // eax@21
  int v29; // eax@22
  UIElement *v30; // ecx@24
  UIElement *v31; // eax@24
  int v32; // eax@25
  UIElement *v33; // ecx@27
  UIElement *v34; // eax@27
  int v35; // eax@28
  UIElement *v36; // ecx@30
  UIElement *v37; // eax@30
  int v38; // eax@31
  UIElement *v39; // ecx@33
  UIElement *v40; // eax@33
  int v41; // eax@34
  UIElement *v42; // ecx@36
  UIElement *v43; // eax@36
  int v44; // eax@37
  CPlayerSystem *v45; // eax@39
  bool v46; // ST04_1@39
  CharGenState *v47; // eax@39
  UIElement *v48; // eax@39
  UIElement *v49; // ecx@39
  UIElement *v50; // eax@39
  gmCGHeritagePage *v51; // eax@40
  UIElement *v52; // eax@42
  gmCGProfessionPage *v53; // eax@43
  UIElement *v54; // eax@45
  gmCGSkillsPage *v55; // eax@46
  UIElement *v56; // eax@48
  gmCGAppearancePage *v57; // eax@49
  UIElement *v58; // eax@51
  gmCGTownPage *v59; // eax@52
  UIElement *v60; // eax@54
  gmCGSummaryPage *v61; // eax@55

  v2 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmCharGenMainUI::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&gmCharGenMainUI::vftable;
  v2->m_pPlayerSystem = 0;
  v2->m_rootField = 0;
  v2->m_ProgressBar = 0;
  v2->m_MainMenu = 0;
  v2->m_pMasterPage = 0;
  v2->m_pHeritagePage = 0;
  v2->m_pProfessionPage = 0;
  v2->m_pSkillsPage = 0;
  v2->m_pAppearancePage = 0;
  v2->m_pTownPage = 0;
  v2->m_pSummaryPage = 0;
  v2->m_pLeftButton = 0;
  v2->m_pRightButton = 0;
  v2->m_pHelpButton = 0;
  v2->m_pExitButton = 0;
  v2->m_pRandomButton = 0;
  v2->m_eProgressState = 0;
  v2->m_bAwaitingCharSetForLogin = 0;
  v2->m_uiExitContext = 0;
  v2->m_uiPleaseWaitContext = 0;
  v2->m_uiErrorMessageContext = 0;
  v2->m_uiCreditWarningContext = 0;
  v2->m_uiRandomizeWarningContext = 0;
  v2->m_uiToDRequiredMessage = 0;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  v4 = (int)v3;
  if ( v3 )
  {
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, 100004u, (NoticeHandler *)&v2->vfptr);
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v4 + 4))(v4, &byte_4DD22C, &v2->vfptr);
    (*(void (__thiscall **)(int, char *, NoticeHandlerVtbl **))(*(_DWORD *)v4 + 4))(
      v4,
      (char *)&loc_4DD1E0 + 1,
      &v2->vfptr);
    UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 1u);
    v5 = UIMainFramework::CreateAndAddRootElement((UIMainFramework *)&v2->vfptr, 0x10000039u, 0x100003CCu);
    v2->m_rootField = (UIElement *)v5;
    if ( v5 )
    {
      v6 = UIElement::GetChildRecursive((UIElement *)v5, 0x100003CEu);
      v7 = v2->m_rootField;
      v2->m_ProgressBar = v6;
      v8 = UIElement::GetChildRecursive(v7, 0x100003CFu);
      v9 = v2->m_rootField;
      v2->m_MainMenu = v8;
      v10 = UIElement::GetChildRecursive(v9, 0x100003EFu);
      if ( v10 )
        v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)1);
      else
        v11 = 0;
      v12 = v2->m_rootField;
      v2->m_pHeritageButton = (UIElement_Button *)v11;
      v13 = UIElement::GetChildRecursive(v12, 0x100003F0u);
      if ( v13 )
        v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)1);
      else
        v14 = 0;
      v15 = v2->m_rootField;
      v2->m_pProfessionButton = (UIElement_Button *)v14;
      v16 = UIElement::GetChildRecursive(v15, 0x100003F1u);
      if ( v16 )
        v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)1);
      else
        v17 = 0;
      v18 = v2->m_rootField;
      v2->m_pSkillsButton = (UIElement_Button *)v17;
      v19 = UIElement::GetChildRecursive(v18, 0x100003F2u);
      if ( v19 )
        v20 = v19->vfptr[12].OnAction((IInputActionCallback *)v19, (InputEvent *)1);
      else
        v20 = 0;
      v21 = v2->m_rootField;
      v2->m_pAppearanceButton = (UIElement_Button *)v20;
      v22 = UIElement::GetChildRecursive(v21, 0x100003F3u);
      if ( v22 )
        v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)1);
      else
        v23 = 0;
      v24 = v2->m_rootField;
      v2->m_pTownButton = (UIElement_Button *)v23;
      v25 = UIElement::GetChildRecursive(v24, 0x100003F4u);
      if ( v25 )
        v26 = v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)1);
      else
        v26 = 0;
      v27 = v2->m_rootField;
      v2->m_pSummaryButton = (UIElement_Button *)v26;
      v28 = UIElement::GetChildRecursive(v27, 0x100003C6u);
      if ( v28 )
        v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)1);
      else
        v29 = 0;
      v30 = v2->m_rootField;
      v2->m_pLeftButton = (UIElement_Button *)v29;
      v31 = UIElement::GetChildRecursive(v30, 0x100003C7u);
      if ( v31 )
        v32 = v31->vfptr[12].OnAction((IInputActionCallback *)v31, (InputEvent *)1);
      else
        v32 = 0;
      v33 = v2->m_rootField;
      v2->m_pRightButton = (UIElement_Button *)v32;
      v34 = UIElement::GetChildRecursive(v33, 0x100003C8u);
      if ( v34 )
        v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)1);
      else
        v35 = 0;
      v36 = v2->m_rootField;
      v2->m_pFinishButton = (UIElement_Button *)v35;
      v37 = UIElement::GetChildRecursive(v36, 0x100003C9u);
      if ( v37 )
        v38 = v37->vfptr[12].OnAction((IInputActionCallback *)v37, (InputEvent *)1);
      else
        v38 = 0;
      v39 = v2->m_rootField;
      v2->m_pHelpButton = (UIElement_Button *)v38;
      v40 = UIElement::GetChildRecursive(v39, 0x100003CAu);
      if ( v40 )
        v41 = v40->vfptr[12].OnAction((IInputActionCallback *)v40, (InputEvent *)1);
      else
        v41 = 0;
      v42 = v2->m_rootField;
      v2->m_pExitButton = (UIElement_Button *)v41;
      v43 = UIElement::GetChildRecursive(v42, 0x100003CBu);
      if ( v43 )
        v44 = v43->vfptr[12].OnAction((IInputActionCallback *)v43, (InputEvent *)1);
      else
        v44 = 0;
      v2->m_pRandomButton = (UIElement_Button *)v44;
      v45 = CPlayerSystem::GetPlayerSystem();
      v2->m_pPlayerSystem = v45;
      v46 = CPlayerSystem::AccountHasThroneOfDestiny(v45);
      CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
      CharGenState::RandomizeCharacter(v47, a2, v46);
      v48 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D0u);
      v49 = v2->m_rootField;
      v2->m_pMasterPage = v48;
      v50 = UIElement::GetChildRecursive(v49, 0x100003D1u);
      if ( v50 )
        v51 = (gmCGHeritagePage *)v50->vfptr[12].OnAction((IInputActionCallback *)v50, (InputEvent *)268435513);
      else
        v51 = 0;
      v2->m_pHeritagePage = v51;
      gmCGHeritagePage::InitializePage(v51, v2);
      v52 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D2u);
      if ( v52 )
        v53 = (gmCGProfessionPage *)v52->vfptr[12].OnAction((IInputActionCallback *)v52, (InputEvent *)268435514);
      else
        v53 = 0;
      v2->m_pProfessionPage = v53;
      gmCGProfessionPage::InitializePage(v53, v2);
      v54 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D3u);
      if ( v54 )
        v55 = (gmCGSkillsPage *)v54->vfptr[12].OnAction((IInputActionCallback *)v54, (InputEvent *)268435515);
      else
        v55 = 0;
      v2->m_pSkillsPage = v55;
      gmCGSkillsPage::InitializePage(v55, v2);
      v56 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D4u);
      if ( v56 )
        v57 = (gmCGAppearancePage *)v56->vfptr[12].OnAction((IInputActionCallback *)v56, (InputEvent *)268435516);
      else
        v57 = 0;
      v2->m_pAppearancePage = v57;
      gmCGAppearancePage::InitializePage(v57, a2, v2);
      v58 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D5u);
      if ( v58 )
        v59 = (gmCGTownPage *)v58->vfptr[12].OnAction((IInputActionCallback *)v58, (InputEvent *)268435517);
      else
        v59 = 0;
      v2->m_pTownPage = v59;
      gmCGTownPage::InitializePage(v59, v4, v2);
      v60 = UIElement::GetChildRecursive(v2->m_rootField, 0x100003D6u);
      if ( v60 )
        v61 = (gmCGSummaryPage *)v60->vfptr[12].OnAction((IInputActionCallback *)v60, (InputEvent *)268435518);
      else
        v61 = 0;
      v2->m_pSummaryPage = v61;
      gmCGSummaryPage::InitializePage(v61, v2);
      gmCharGenMainUI::SetProgressState(v2, a2, ECG_HERTAGE);
    }
  }
}
// 4DD22C: using guessed type char byte_4DD22C;
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C1E30: using guessed type bool (__thiscall *gmCharGenMainUI::vftable)(DBCache *this);
// 7C20D8: using guessed type int (__thiscall *gmCharGenMainUI::vftable)(void *, char);

//----- (004E8380) --------------------------------------------------------  // acclient.c:277871
void __thiscall gmCharGenMainUI::~gmCharGenMainUI(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // esi@1
  NoticeHandler *v2; // edi@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCharGenMainUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCharGenMainUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 1u);
  UIMainFramework::RemoveRootElement((UIMainFramework *)&v1->vfptr, &v1->m_rootField);
  v1->m_uiPleaseWaitContext = 0;
  v1->m_uiErrorMessageContext = 0;
  v1->m_uiExitContext = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C1E30: using guessed type bool (__thiscall *gmCharGenMainUI::vftable)(DBCache *this);
// 7C20D8: using guessed type int (__thiscall *gmCharGenMainUI::vftable)(void *, char);

//----- (004E83E0) --------------------------------------------------------  // acclient.c:277894
void __usercall gmCharGenMainUI::Create(long double a1@<st0>)
{
  gmCharGenMainUI *v1; // eax@1

  v1 = (gmCharGenMainUI *)operator new(0x118u);
  if ( v1 )
    gmCharGenMainUI::gmCharGenMainUI(v1, a1);
}

//----- (004E8400) --------------------------------------------------------  // acclient.c:277904
char __userpurge gmCharGenMainUI::CloseRandomizeWarningDialog@<al>(gmCharGenMainUI *this@<ecx>, long double a2@<st0>, bool i_bConfirm)
{
  this->m_uiRandomizeWarningContext = 0;
  if ( i_bConfirm )
    gmCharGenMainUI::DoRandom(this, a2);
  return 1;
}

//----- (004E8420) --------------------------------------------------------  // acclient.c:277913
gmCharGenMainUI *__thiscall gmCharGenMainUI::vector_deleting_destructor(gmCharGenMainUI *this, unsigned int a2)
{
  gmCharGenMainUI *v2; // esi@1

  v2 = this;
  gmCharGenMainUI::~gmCharGenMainUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E8440) --------------------------------------------------------  // acclient.c:277925
void __cdecl gmCharGenMainUI::Register(unsigned int mode)
{
  UIFlow::RegisterFrameworkClass(mode, (UIMainFramework *(__cdecl *)())gmCharGenMainUI::Create);
}

//----- (004E8460) --------------------------------------------------------  // acclient.c:277931
void __thiscall gmCharGenMainUI::Update(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // edi@1
  int v2; // eax@2
  int v3; // eax@2
  int v4; // esi@2
  int v5; // eax@4
  int v6; // ebp@5
  bool v7; // zf@5
  bool v8; // sf@5
  int v9; // edx@9
  int v10; // edi@10
  int v11; // eax@12
  char *v12; // esi@12
  bool v13; // bl@12
  int v14; // eax@17
  unsigned int v15; // edi@19
  char *v16; // esi@21
  bool bFoundCharIdent; // [sp+9h] [bp-15h]@1
  gmCharGenMainUI *v18; // [sp+Ah] [bp-14h]@1
  PStringBase<char> strNewCharacterName; // [sp+Eh] [bp-10h]@2
  int v20; // [sp+12h] [bp-Ch]@6
  PStringBase<char> v21; // [sp+16h] [bp-8h]@12
  int i; // [sp+1Ah] [bp-4h]@5

  v1 = this;
  v18 = this;
  bFoundCharIdent = 0;
  if ( !this->m_bAwaitingCharSetForLogin )
    goto LABEL_28;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  PStringBase<char>::PStringBase<char>(&strNewCharacterName, (const char *)(v2 + 464));
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v4 = 0;
  if ( *(_DWORD *)(v3 + 548) )
    PStringBase<char>::sprintf(&strNewCharacterName, "%c%s", 43, strNewCharacterName.m_charbuffer);
  v5 = UIFramework::GetPersistantData();
  if ( v5 )
  {
    v6 = v5 + 4;
    v7 = *(_DWORD *)(v5 + 24) == 0;
    v8 = *(_DWORD *)(v5 + 24) < 0;
    i = 0;
    if ( !v8 && !v7 )
    {
      v20 = 0;
      do
      {
        if ( !CharacterSet::GetGreyedOutFor((CharacterSet *)v6, v4) )
        {
          if ( (unsigned int)v4 < *(_DWORD *)(v6 + 20) && (v9 = *(_DWORD *)(v6 + 12), *(_DWORD *)(v20 + v9 + 4)) )
            v10 = v9 + v20;
          else
            v10 = 0;
          PStringBase<char>::PStringBase<char>(&v21, (const char *)(*(_DWORD *)(v10 + 8) + 20));
          v11 = __stricmp(strNewCharacterName.m_charbuffer->m_data, v21.m_charbuffer->m_data);
          v12 = &v21.m_charbuffer[-2].m_data[12];
          v13 = v11 == 0;
          if ( !InterlockedDecrement((volatile LONG *)&v21.m_charbuffer[-1]) && v12 )
            (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
          if ( v13 )
          {
            v15 = *(_DWORD *)(v10 + 4);
            if ( v15 )
            {
              bFoundCharIdent = 1;
              CPlayerSystem::LogOnCharacter(v18->m_pPlayerSystem, v15);
            }
            break;
          }
          v4 = i;
        }
        v14 = *(_DWORD *)(v6 + 20);
        ++v4;
        i = v4;
        v20 += 16;
      }
      while ( v4 < v14 );
    }
  }
  v16 = &strNewCharacterName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strNewCharacterName.m_charbuffer[-1]) )
  {
    if ( v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  }
  if ( !bFoundCharIdent )
LABEL_28:
    UIFramework::QueueUIMode(0x1000000Au);
}

//----- (004E85F0) --------------------------------------------------------  // acclient.c:278023
void __thiscall accountID::accountID(accountID *this, accountID *rhs)
{
  accountID *v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = this;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&v2->m_buffer, rhs->m_buffer->m_data);
  AC1Legacy::PStringBase<char>::break_reference((AC1Legacy::PStringBase<char> *)&v2->m_buffer);
  __strlwr(v2->m_buffer->m_data);
  v2->fIsDarkMajestyExpansion_ = rhs->fIsDarkMajestyExpansion_;
  v2->m_fIsThroneOfDestinyExpansion = rhs->m_fIsThroneOfDestinyExpansion;
  v2->m_fPreOrderedThroneOfDestinyExpansion = rhs->m_fPreOrderedThroneOfDestinyExpansion;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004E8650) --------------------------------------------------------  // acclient.c:278042
char __thiscall gmCharGenMainUI::DoExit(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // esi@1
  unsigned int v2; // eax@2
  unsigned __int32 v3; // eax@8
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BasePropertyDesc *v9; // ecx@20
  unsigned int v10; // edx@20
  BasePropertyValue *v11; // ecx@24
  unsigned int v12; // esi@24
  BaseProperty p; // [sp+10h] [bp-114h]@2
  unsigned int _key; // [sp+18h] [bp-10Ch]@4
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@2
  StringInfo siWarning; // [sp+94h] [bp-90h]@2

  v1 = this;
  if ( this->m_uiExitContext )
    return 0;
  StringInfo::StringInfo(&siWarning);
  v2 = compute_str_hash("ID_CharGen_ExitWarning");
  StringInfo::SetStringIDandTableEnum(&siWarning, v2, 268435458);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xACu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&siWarning);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v3 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v1->m_uiExitContext = v3;
  if ( !v3 )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&siWarning);
    return 0;
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v9 = p.m_pcPropertyDesc;
    v10 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v11 = p.m_pcPropertyValue;
    v12 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&siWarning);
  return 1;
}

//----- (004E8870) --------------------------------------------------------  // acclient.c:278152
char __thiscall gmCharGenMainUI::MakeCreditWarningDialog(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // esi@1
  unsigned int v2; // eax@2
  unsigned __int32 v3; // eax@8
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BasePropertyDesc *v9; // ecx@20
  unsigned int v10; // edx@20
  BasePropertyValue *v11; // ecx@24
  unsigned int v12; // esi@24
  BaseProperty p; // [sp+10h] [bp-114h]@2
  unsigned int _key; // [sp+18h] [bp-10Ch]@4
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@2
  StringInfo siWarning; // [sp+94h] [bp-90h]@2

  v1 = this;
  if ( this->m_uiCreditWarningContext )
    return 0;
  StringInfo::StringInfo(&siWarning);
  v2 = compute_str_hash("ID_CharGen_CreditWarning");
  StringInfo::SetStringIDandTableEnum(&siWarning, v2, 268435458);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xACu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&siWarning);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v3 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v1->m_uiCreditWarningContext = v3;
  if ( !v3 )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&siWarning);
    return 0;
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v9 = p.m_pcPropertyDesc;
    v10 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v11 = p.m_pcPropertyValue;
    v12 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&siWarning);
  return 1;
}

//----- (004E8A90) --------------------------------------------------------  // acclient.c:278262
char __thiscall gmCharGenMainUI::MakeRandomizeWarningDialog(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // esi@1
  unsigned int v2; // eax@2
  unsigned __int32 v3; // eax@8
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BasePropertyDesc *v9; // ecx@20
  unsigned int v10; // edx@20
  BasePropertyValue *v11; // ecx@24
  unsigned int v12; // esi@24
  BaseProperty p; // [sp+10h] [bp-114h]@2
  unsigned int _key; // [sp+18h] [bp-10Ch]@4
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@2
  StringInfo siWarning; // [sp+94h] [bp-90h]@2

  v1 = this;
  if ( this->m_uiRandomizeWarningContext )
    return 0;
  StringInfo::StringInfo(&siWarning);
  v2 = compute_str_hash("ID_CharGen_RandomizeWarning");
  StringInfo::SetStringIDandTableEnum(&siWarning, v2, 268435458);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xACu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&siWarning);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v3 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v1->m_uiRandomizeWarningContext = v3;
  if ( !v3 )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&siWarning);
    return 0;
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v9 = p.m_pcPropertyDesc;
    v10 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v11 = p.m_pcPropertyValue;
    v12 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&siWarning);
  return 1;
}

//----- (004E8CB0) --------------------------------------------------------  // acclient.c:278372
char __thiscall gmCharGenMainUI::MakeErrorMessageDialog(gmCharGenMainUI *this, StringInfo *siError)
{
  gmCharGenMainUI *v2; // esi@1
  char result; // al@2
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BaseProperty p; // [sp+10h] [bp-84h]@3
  unsigned int _key; // [sp+18h] [bp-7Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-78h]@3

  v2 = this;
  if ( this->m_uiErrorMessageContext )
  {
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(siError);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v2->m_uiErrorMessageContext = DialogFactory::MakeDialog((UIFramework *)&v2->vfptr, &pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    result = 1;
  }
  return result;
}

//----- (004E8E40) --------------------------------------------------------  // acclient.c:278453
char __thiscall gmCharGenMainUI::MakeToDWarningDialog(gmCharGenMainUI *this)
{
  gmCharGenMainUI *v1; // esi@1
  char result; // al@2
  unsigned int v3; // eax@3
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BaseProperty p; // [sp+10h] [bp-114h]@3
  unsigned int _key; // [sp+18h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@3
  StringInfo info; // [sp+94h] [bp-90h]@3

  v1 = this;
  if ( this->m_uiToDRequiredMessage )
  {
    result = 0;
  }
  else
  {
    StringInfo::StringInfo(&info);
    v3 = compute_str_hash("ID_CharGen_ToDRequiredWarning");
    StringInfo::SetStringIDandTableEnum(&info, v3, 268435458);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_uiToDRequiredMessage = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    result = 1;
  }
  return result;
}

//----- (004E9000) --------------------------------------------------------  // acclient.c:278540
void __thiscall gmCharGenMainUI::ListenToGlobalMessage(gmCharGenMainUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 1 )
  {
    if ( i_data_int == 39 )
    {
      gmCharGenMainUI::DoExit(this);
    }
    else if ( i_data_int == 123 )
    {
      KeyStone::OpenHelp(0, 268435457);
    }
  }
}

//----- (004E9030) --------------------------------------------------------  // acclient.c:278556
void __thiscall gmCharGenMainUI::RecvNotice_CharGenVerificationResponse(gmCharGenMainUI *this, CG_VERIFICATION_RESPONSE i_rsvp)
{
  gmCharGenMainUI *v2; // esi@1
  unsigned int v3; // eax@4
  unsigned int v4; // eax@5
  unsigned int v5; // eax@3
  StringInfo siError; // [sp+4h] [bp-90h]@3

  v2 = this;
  switch ( i_rsvp )
  {
    case 1:
      DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket);
      LOBYTE(v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[22]) = 1;
      return;
    case 3:
      DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket);
      StringInfo::StringInfo(&siError);
      v5 = compute_str_hash("ID_Character_Err_NameReserved");
      goto LABEL_7;
    case 4:
      DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket);
      StringInfo::StringInfo(&siError);
      v3 = compute_str_hash("ID_Character_Err_NameBanned");
      StringInfo::SetStringIDandTableEnum(&siError, v3, 268435458);
      gmCharGenMainUI::MakeErrorMessageDialog((gmCharGenMainUI *)((char *)v2 - 152), &siError);
      break;
    case 7:
      DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket);
      StringInfo::StringInfo(&siError);
      v4 = compute_str_hash("ID_Character_Err_NameAdminDenied");
      StringInfo::SetStringIDandTableEnum(&siError, v4, 268435458);
      gmCharGenMainUI::MakeErrorMessageDialog((gmCharGenMainUI *)((char *)v2 - 152), &siError);
      break;
    default:
      DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket);
      StringInfo::StringInfo(&siError);
      v5 = compute_str_hash("ID_Character_Err_NameDBDown");
LABEL_7:
      StringInfo::SetStringIDandTableEnum(&siError, v5, 268435458);
      gmCharGenMainUI::MakeErrorMessageDialog((gmCharGenMainUI *)((char *)v2 - 152), &siError);
      break;
  }
  StringInfo::~StringInfo(&siError);
}

//----- (004E9170) --------------------------------------------------------  // acclient.c:278603
char __thiscall gmCharGenMainUI::DoFinish(gmCharGenMainUI *this, bool _bCreditCheck)
{
  gmCharGenMainUI *v2; // edi@1
  int v3; // eax@1
  int v4; // esi@1
  int v5; // ecx@1
  CharGenState *v7; // eax@7
  int v8; // eax@7
  CPlayerSystem *v9; // edx@7
  CharGenResult *v10; // ebp@7
  char *v11; // esi@7
  int v12; // edx@9
  unsigned int v13; // eax@11
  ReferenceCountTemplate<1048576,1>Vtbl *v14; // eax@12
  ReferenceCountTemplate<1048576,1>Vtbl *v15; // eax@14
  ReferenceCountTemplate<1048576,1>Vtbl *v16; // eax@16
  BasePropertyDesc *v17; // ecx@18
  unsigned int v18; // edx@18
  ReferenceCountTemplate<1048576,1>Vtbl *v19; // eax@19
  BasePropertyValue *v20; // ecx@22
  unsigned int v21; // esi@22
  ReferenceCountTemplate<1048576,1>Vtbl *v22; // edx@23
  char *v23; // esi@26
  int v24; // edx@28
  accountID v25; // [sp-14h] [bp-13Ch]@7
  int v26; // [sp-4h] [bp-12Ch]@1
  BaseProperty p; // [sp+10h] [bp-118h]@11
  PStringBase<char> nameText; // [sp+18h] [bp-110h]@1
  unsigned int _key; // [sp+1Ch] [bp-10Ch]@13
  PropertyCollection pc; // [sp+20h] [bp-108h]@11
  StringInfo siWarning; // [sp+98h] [bp-90h]@11

  v2 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v4 = v3;
  PStringBase<char>::PStringBase<char>(&nameText, (const char *)(v3 + 464));
  v26 = v5;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v26, "[] ");
  PStringBase<char>::trim(&nameText, 1, 1, (PStringBase<char>)v26);
  CharGenState::SetName((CharGenState *)v4, nameText.m_charbuffer->m_data);
  if ( v2->m_pSummaryPage->m_bNameEntered && *(_DWORD *)&nameText.m_charbuffer[-1].m_data[12] != 1 )
  {
    if ( _bCreditCheck && *(_DWORD *)(v4 + 416) > 0 )
    {
      gmCharGenMainUI::MakeCreditWarningDialog(v2);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nameText);
      return 0;
    }
    if ( CharGenState::GetVerificationState((CharGenState *)v4) == UNDEF_CG_VERIFICATION_RESPONSE )
    {
      CharGenState::SetVerificationState((CharGenState *)v4, CG_VERIFICATION_RESPONSE_PENDING);
      CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
      v8 = CharGenState::GetCharGenResult(v7);
      v9 = v2->m_pPlayerSystem;
      v26 = *(_DWORD *)(v4 + 548);
      v10 = (CharGenResult *)v8;
      accountID::accountID(&v25, &v9->account_);
      Proto_UI::SendCharGenResult(v10, v25);
      v11 = &nameText.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&nameText.m_charbuffer[-1]) )
      {
        if ( v11 )
        {
          v12 = *(_DWORD *)v11;
          v26 = 1;
          (*(void (__thiscall **)(char *, signed int))v12)(v11, 1);
        }
      }
      return 1;
    }
  }
  else
  {
    StringInfo::StringInfo(&siWarning);
    v26 = 268435458;
    v13 = compute_str_hash("ID_CharGen_NoNameWarning");
    StringInfo::SetStringIDandTableEnum(&siWarning, v13, v26);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v14 = p.m_pcPropertyValue->vfptr;
      v26 = 3;
      ((void (__stdcall *)(signed int))v14[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v15 = p.m_pcPropertyValue->vfptr;
      v26 = 1;
      ((void (__stdcall *)(signed int))v15[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v16 = p.m_pcPropertyValue->vfptr;
      v26 = (int)&siWarning;
      ((void (__stdcall *)(StringInfo *))v16[49].__vecDelDtor)(&siWarning);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    DialogFactory::MakeDialogInCurrentUI(&pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v17 = p.m_pcPropertyDesc;
      v18 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v18;
      if ( !v18 )
      {
        v19 = v17->vfptr;
        v26 = 1;
        ((void (__stdcall *)(signed int))v19->__vecDelDtor)(1);
      }
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v20 = p.m_pcPropertyValue;
      v21 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v21;
      if ( !v21 )
      {
        v22 = v20->vfptr;
        v26 = 1;
        ((void (__stdcall *)(signed int))v22->__vecDelDtor)(1);
      }
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&siWarning);
  }
  v23 = &nameText.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&nameText.m_charbuffer[-1]) && v23 )
  {
    v24 = *(_DWORD *)v23;
    v26 = 1;
    (*(void (__thiscall **)(char *, signed int))v24)(v23, 1);
  }
  return 0;
}

//----- (004E9450) --------------------------------------------------------  // acclient.c:278763
UIElementMessageListenResult __userpurge gmCharGenMainUI::ListenToElementMessage@<eax>(gmCharGenMainUI *this@<ecx>, long double a2@<st0>, UIElementMessageInfo *i_rMsg)
{
  unsigned int v3; // eax@1
  gmCharGenMainUI *v4; // esi@1
  UIElementMessageListenResult result; // eax@5
  gmCharGenMainUI::ECGProgress v6; // eax@9
  gmCharGenMainUI::ECGProgress v7; // eax@12
  int v8; // eax@29

  v3 = i_rMsg->idElement;
  v4 = this;
  if ( i_rMsg->idElement > 0x100003F1 )
  {
    if ( v3 > 0x100005A9 )
    {
      switch ( v3 )
      {
        case 0x100005BFu:
        case 0x100005C4u:
        case 0x100005E8u:
          goto $L147759;
        case 0x100005C7u:
        case 0x100005C8u:
          if ( i_rMsg->idMessage == 1 )
          {
            ((void (__stdcall *)(_DWORD))this->m_pProfessionButton->vfptr[2].__vecDelDtor)(0);
            ((void (__stdcall *)(_DWORD))v4->m_pSkillsButton->vfptr[2].__vecDelDtor)(0);
            ((void (__stdcall *)(_DWORD))v4->m_pTownButton->vfptr[2].__vecDelDtor)(0);
          }
          break;
        default:
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      }
    }
    else
    {
      if ( v3 == 268436905 )
        goto $L147759;
      if ( v3 <= 0x100003F4 )
      {
        if ( v3 == 268436468 )
        {
          if ( i_rMsg->idMessage == 1 )
          {
            gmCharGenMainUI::SetProgressState(this, a2, ECG_SUMMARY);
            return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
          }
        }
        else
        {
          v8 = v3 - 268436466;
          if ( v8 )
          {
            if ( v8 == 1 && i_rMsg->idMessage == 1 )
            {
              gmCharGenMainUI::SetProgressState(this, a2, ECG_TOWN);
              return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
            }
          }
          else if ( i_rMsg->idMessage == 1 )
          {
            gmCharGenMainUI::SetProgressState(this, a2, ECG_APPEARANCE);
            return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
          }
        }
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      }
      if ( v3 >= 0x10000590 && v3 <= 0x10000591 )
      {
$L147759:
        if ( i_rMsg->idMessage == 1 )
        {
          ((void (__stdcall *)(signed int))this->m_pProfessionButton->vfptr[2].__vecDelDtor)(1);
          ((void (__stdcall *)(signed int))v4->m_pSkillsButton->vfptr[2].__vecDelDtor)(1);
          ((void (__stdcall *)(signed int))v4->m_pTownButton->vfptr[2].__vecDelDtor)(1);
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        }
      }
    }
  }
  else if ( i_rMsg->idElement == 268436465 )
  {
    if ( i_rMsg->idMessage == 1 )
    {
      gmCharGenMainUI::SetProgressState(this, a2, ECG_SKILLS);
      return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
    }
  }
  else
  {
    switch ( v3 )
    {
      case 0x100003EFu:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        gmCharGenMainUI::SetProgressState(this, a2, ECG_HERTAGE);
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003F0u:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        gmCharGenMainUI::SetProgressState(this, a2, ECG_PROFESSION);
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003C6u:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        v6 = this->m_eProgressState;
        if ( (signed int)v6 <= 1 )
          goto LABEL_22;
        gmCharGenMainUI::SetProgressState(this, a2, (gmCharGenMainUI::ECGProgress)(v6 - 1));
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003C7u:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        v7 = this->m_eProgressState;
        if ( (signed int)v7 >= 6 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        gmCharGenMainUI::SetProgressState(this, a2, (gmCharGenMainUI::ECGProgress)(v7 + 1));
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003CBu:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        if ( this->m_eProgressState == 6 )
        {
          gmCharGenMainUI::MakeRandomizeWarningDialog(this);
          result = UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        }
        else
        {
          gmCharGenMainUI::DoRandom(this, a2);
          result = UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        }
        return result;
      case 0x100003C8u:
        if ( i_rMsg->idMessage != 1 || this->m_eProgressState != 6 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
        gmCharGenMainUI::DoFinish(this, 1);
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003CAu:
        if ( i_rMsg->idMessage != 1 )
          return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
LABEL_22:
        gmCharGenMainUI::DoExit(this);
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
      case 0x100003BFu:
      case 0x100003C1u:
      case 0x100003C2u:
      case 0x100003C3u:
        goto $L147759;
      default:
        return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
    }
  }
  return UIFramework::ListenToElementMessage((UIFramework *)&v4->vfptr, i_rMsg);
}

//----- (004E9780) --------------------------------------------------------  // acclient.c:278919
void __userpurge gmCharGenMainUI::RecvNotice_CloseDialog(gmCharGenMainUI *this@<ecx>, long double a2@<st0>, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v4; // esi@1
  unsigned int v5; // edx@1
  HashTableData<unsigned long,BaseProperty> **v6; // eax@1
  gmCharGenMainUI *v7; // edi@1
  HashTableData<unsigned long,BaseProperty> *v8; // eax@1
  unsigned int v9; // edx@16
  HashTableData<unsigned long,BaseProperty> **v10; // ecx@16
  HashTableData<unsigned long,BaseProperty> *v11; // eax@16
  bool v12; // zf@24
  int v13; // ecx@32
  int v14; // edx@32
  int v15; // ecx@36
  int v16; // edx@36
  BasePropertyDesc *v17; // ecx@39
  unsigned int v18; // edx@39
  BasePropertyValue *v19; // ecx@43
  unsigned int v20; // edx@43
  unsigned int type; // [sp+Ch] [bp-14h]@1
  int v22; // [sp+10h] [bp-10h]@16
  int v23; // [sp+14h] [bp-Ch]@16
  BaseProperty p; // [sp+18h] [bp-8h]@1

  v4 = data;
  v5 = 0x8E % data->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v6 = data->m_hashProperties.m_intrusiveTable.m_buckets;
  type = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v7 = this;
  v8 = v6[v5];
  if ( v8 )
  {
    while ( v8->m_hashKey != 142 )
    {
      v8 = v8->m_hashNext;
      if ( !v8 )
        goto LABEL_8;
    }
    if ( v8 )
    {
      BaseProperty::operator=(&p, (int)&v8->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
    }
  }
LABEL_8:
  if ( type == 1 )
  {
    v9 = 0x92 % v4->m_hashProperties.m_intrusiveTable.m_numBuckets;
    v10 = v4->m_hashProperties.m_intrusiveTable.m_buckets;
    LOBYTE(data) = 0;
    v22 = 0;
    v23 = 0;
    v11 = v10[v9];
    if ( v11 )
    {
      while ( v11->m_hashKey != 146 )
      {
        v11 = v11->m_hashNext;
        if ( !v11 )
          goto LABEL_23;
      }
      if ( v11 )
      {
        BaseProperty::operator=(&v22, (int)&v11->m_data);
        if ( v23 )
          (*(void (__stdcall **)(PropertyCollection **))(*(_DWORD *)v23 + 112))(&data);
      }
    }
LABEL_23:
    if ( v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_buckets == (HashSetData<UIElement *> **)context )
    {
      v12 = (_BYTE)data == 0;
      *((_DWORD *)&v7[-1].m_children + 64) = 0;
      if ( !v12 )
        UIFramework::QueueUIMode(0x1000000Au);
    }
    else if ( v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_numElements == context )
    {
      v12 = (_BYTE)data == 0;
      *((_DWORD *)&v7[-1].m_children + 67) = 0;
      if ( !v12 )
        gmCharGenMainUI::DoFinish((gmCharGenMainUI *)((char *)v7 - 152), 0);
    }
    else if ( v7->m_tsSerialNumberLastListenedTo.m_timestamp == context )
    {
      gmCharGenMainUI::CloseRandomizeWarningDialog((gmCharGenMainUI *)((char *)v7 - 152), a2, (bool)data);
    }
    if ( v22 )
    {
      v13 = v22;
      v14 = *(_DWORD *)(v22 + 4) - 1;
      *(_DWORD *)(v22 + 4) = v14;
      if ( !v14 )
        (**(void (__stdcall ***)(_DWORD))v13)(1);
      v22 = 0;
    }
    if ( v23 )
    {
      v15 = v23;
      v16 = *(_DWORD *)(v23 + 4) - 1;
      *(_DWORD *)(v23 + 4) = v16;
      if ( !v16 )
        (**(void (__stdcall ***)(_DWORD))v15)(1);
    }
  }
  else if ( type == 3 )
  {
    if ( v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket == (HashSetData<UIElement *> **)context )
    {
      v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket = 0;
    }
    else if ( v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_numBuckets == context )
    {
      v7->m_hashElementsRegisteredWith.m_intrusiveTable.m_numBuckets = 0;
    }
    else if ( *(_DWORD *)&v7->m_bCanForceHide == context )
    {
      *(_DWORD *)&v7->m_bCanForceHide = 0;
    }
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v17 = p.m_pcPropertyDesc;
    v18 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v19 = p.m_pcPropertyValue;
    v20 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v20;
    if ( !v20 )
      ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
  }
}

//----- (006F6A60) --------------------------------------------------------  // acclient.c:779372
void sub_6F6A60()
{
  flt_840938 = 1000.0 + 1.0;
}

//----- (006F6A80) --------------------------------------------------------  // acclient.c:779378
void _E93_98()
{
  flt_84093C = 24.0 * 8.0;
}

//----- (006F6AA0) --------------------------------------------------------  // acclient.c:779384
void _E95_98()
{
  flt_840940 = 24.0 * 0.5;
}

//----- (006F6AC0) --------------------------------------------------------  // acclient.c:779390
int sub_6F6AC0()
{
  return atexit(nullsub_530);
}

//----- (006F6AD0) --------------------------------------------------------  // acclient.c:779396
int sub_6F6AD0()
{
  return atexit(nullsub_531);
}

//----- (006F6AE0) --------------------------------------------------------  // acclient.c:779402
int sub_6F6AE0()
{
  return atexit(nullsub_532);
}

//----- (006F6AF0) --------------------------------------------------------  // acclient.c:779408
void _E106_73()
{
  DEFAULT_VIEW_RADIUS_77 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6B10) --------------------------------------------------------  // acclient.c:779414
void _E108_58()
{
  MIN_QUANTUM_77 = 1.0 / 30.0;
}

//----- (006F6B30) --------------------------------------------------------  // acclient.c:779420
void _E110_48()
{
  MAX_QUANTUM_77 = 1.0 / 5.0;
}

//----- (006F6B50) --------------------------------------------------------  // acclient.c:779426
void _E112_65()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840958, PFID_A8R8G8B8);
}

//----- (006F6B60) --------------------------------------------------------  // acclient.c:779432
int _E114_34()
{
  return atexit(nullsub_528);
}

//----- (006F6B70) --------------------------------------------------------  // acclient.c:779438
int _E117_48()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_14, "Display.Resolution");
  return atexit(sub_763440);
}

//----- (006F6B90) --------------------------------------------------------  // acclient.c:779445
int _E120_40()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_14, "Display.FullScreen");
  return atexit(sub_763470);
}

//----- (006F6BB0) --------------------------------------------------------  // acclient.c:779452
int _E123_20()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_14, "Display.RefreshRate");
  return atexit(sub_7634A0);
}

//----- (006F6BD0) --------------------------------------------------------  // acclient.c:779459
int _E126_23()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_14, "Display.SyncToRefresh");
  return atexit(_E127_96);
}

//----- (006F6BF0) --------------------------------------------------------  // acclient.c:779466
int sub_6F6BF0()
{
  return atexit(nullsub_529);
}

//----- (00763440) --------------------------------------------------------  // acclient.c:889938
void __cdecl sub_763440()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763470) --------------------------------------------------------  // acclient.c:889951
void __cdecl sub_763470()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007634A0) --------------------------------------------------------  // acclient.c:889964
void __cdecl sub_7634A0()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007634D0) --------------------------------------------------------  // acclient.c:889977
void __cdecl _E127_96()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

