/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCombatUI
   Object     : GAME\game_ui_misc\gmCombatUI.obj
   Functions  : 25
   Addresses  : 004CC000 - 006F31B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CC000) --------------------------------------------------------  // acclient.c:253394
gmCombatUI *__thiscall gmCombatUI::DynamicCast(gmCombatUI *this, unsigned int i_eType)
{
  gmCombatUI *result; // eax@1

  result = this;
  if ( i_eType != 268435468 )
    result = (gmCombatUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CC030) --------------------------------------------------------  // acclient.c:253411
UIElement *__usercall gmCombatUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x600u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmCombatUI::vftable;
    *((_DWORD *)v3 + 382) = &gmCombatUI::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7B8360: using guessed type bool (__thiscall *gmCombatUI::vftable)(DBCache *this);
// 7B8608: using guessed type int (__thiscall *gmCombatUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CC080) --------------------------------------------------------  // acclient.c:253436
void __thiscall gmCombatUI::RecvNotice_AttackHeightChanged(gmCombatUI *this, ATTACK_HEIGHT i_newHeight)
{
  UIElement *v2; // ecx@1

  v2 = UIElement::GetChildRecursive((UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable, 0x10000056u);
  if ( v2 )
  {
    switch ( i_newHeight )
    {
      case 1:
        UIElement::SetAttribute_Enum(v2, 0xB1u, 0x10000057u);
        break;
      case 2:
        UIElement::SetAttribute_Enum(v2, 0xB1u, 0x10000058u);
        break;
      case 3:
        UIElement::SetAttribute_Enum(v2, 0xB1u, 0x10000059u);
        break;
    }
  }
}

//----- (004CC0E0) --------------------------------------------------------  // acclient.c:253459
void __thiscall gmCombatUI::RecvNotice_SetPowerbarLevel(gmCombatUI *this, PowerBarMode i_pbm, float i_fLevel)
{
  UIElement *v3; // eax@2

  if ( i_pbm == 1 )
  {
    v3 = UIElement::GetChildRecursive((UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable, 0x10000050u);
    if ( v3 )
      UIElement::SetAttribute_Float(v3, 0x69u, i_fLevel);
  }
}

//----- (004CC110) --------------------------------------------------------  // acclient.c:253472
void __thiscall gmCombatUI::RecvNotice_DesiredAttackPowerChanged(gmCombatUI *this, float i_fLevel)
{
  UIElement *v2; // eax@1

  v2 = UIElement::GetChildRecursive((UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable, 0x1000004Fu);
  if ( v2 )
    UIElement::SetAttribute_Float(v2, 0x85u, i_fLevel);
}

//----- (004CC140) --------------------------------------------------------  // acclient.c:253482
UIElement_Field *__thiscall gmCombatUI::scalar_deleting_destructor(gmCombatUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCombatUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCombatUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7B8360: using guessed type bool (__thiscall *gmCombatUI::vftable)(DBCache *this);
// 7B8608: using guessed type int (__thiscall *gmCombatUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CC1A0) --------------------------------------------------------  // acclient.c:253507
void __thiscall gmCombatUI::PostInit(gmCombatUI *this)
{
  gmCombatUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@6
  int v5; // eax@9
  int v6; // eax@12
  UIElement *v7; // eax@15
  int v8; // eax@16
  UIElement *v9; // eax@18
  int v10; // eax@19
  int v11; // edi@20
  unsigned int v12; // eax@22
  unsigned int v13; // eax@22
  UIElement *v14; // eax@22
  int v15; // eax@23
  int v16; // edi@24
  unsigned int v17; // eax@26
  unsigned int v18; // eax@26
  UIElement *v19; // eax@26
  int v20; // eax@27
  int v21; // esi@28
  unsigned int v22; // eax@30
  unsigned int v23; // eax@30
  StringInfo _info; // [sp+30h] [bp-90h]@15

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1F9 + 2),
      (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1F9 + 3),
      (NoticeHandler *)v4);
    if ( v1 )
      v5 = (int)&v1->vfptr;
    else
      v5 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100105u, (NoticeHandler *)v5);
    if ( v1 )
      v6 = (int)&v1->vfptr;
    else
      v6 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1E5 + 1),
      (NoticeHandler *)v6);
  }
  StringInfo::StringInfo(&_info);
  v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005EFu);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)3);
  else
    v8 = 0;
  v1->m_RecklessnessField = (UIElement_Field *)v8;
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 24))(v8, 0);
  v9 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000053u);
  if ( v9 && (v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)268435509)) != 0 )
    v11 = v10 - 32;
  else
    v11 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v11, 0);
  v12 = compute_str_hash("ID_CombatPanelOption_AutoRepeatAttack");
  StringInfo::SetStringIDandTableEnum(&_info, v12, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v11 + 32), &_info);
  v13 = compute_str_hash("ID_PlayerOption_AutoRepeatAttack_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v13, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v11 + 692))(v11, &_info);
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000054u);
  if ( v14 && (v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)268435509)) != 0 )
    v16 = v15 - 32;
  else
    v16 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v16, AutoTarget_PlayerOption);
  v17 = compute_str_hash("ID_CombatPanelOption_AutoTarget");
  StringInfo::SetStringIDandTableEnum(&_info, v17, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v16 + 32), &_info);
  v18 = compute_str_hash("ID_PlayerOption_AutoTarget_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v18, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v16 + 692))(v16, &_info);
  v19 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000055u);
  if ( v19 && (v20 = v19->vfptr[12].OnAction((IInputActionCallback *)v19, (InputEvent *)268435509)) != 0 )
    v21 = v20 - 32;
  else
    v21 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v21, ViewCombatTarget_PlayerOption);
  v22 = compute_str_hash("ID_CombatPanelOption_ViewCombatTarget");
  StringInfo::SetStringIDandTableEnum(&_info, v22, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v21 + 32), &_info);
  v23 = compute_str_hash("ID_PlayerOption_ViewCombatTarget_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v23, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v21 + 692))(v21, &_info);
  StringInfo::~StringInfo(&_info);
}

//----- (004CC410) --------------------------------------------------------  // acclient.c:253617
void __cdecl gmCombatUI::Register()
{
  UIElement::RegisterElementClass(0x1000000Cu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCombatUI::Create);
}

//----- (004CC430) --------------------------------------------------------  // acclient.c:253623
int __thiscall gmCombatUI::ListenToElementMessage(gmCombatUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebp@1
  gmCombatUI *v3; // ebx@1
  ClientCombatSystem *v4; // eax@7
  ClientCombatSystem *v6; // eax@8
  ClientCombatSystem *v7; // eax@9
  InterfaceSystem *v8; // eax@10
  UIElementMessageInfo *v9; // esi@10
  PlayerDesc *v10; // esi@14
  UIElement_Field *v11; // ecx@14
  double v12; // st7@17
  ClientCombatSystem *v13; // eax@29
  int v14; // [sp-8h] [bp-2Ch]@10
  ATTACK_HEIGHT v15; // [sp-8h] [bp-2Ch]@26
  float v16; // [sp-4h] [bp-28h]@26
  SKILL_ADVANCEMENT_CLASS sac; // [sp+10h] [bp-14h]@14
  TResult result; // [sp+14h] [bp-10h]@10
  char v19; // [sp+18h] [bp-Ch]@12
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@10

  v2 = i_rMsg;
  v3 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268435543 )
    {
      v16 = USE_POWER_BAR_LEVEL;
      v15 = 1;
    }
    else if ( i_rMsg->idElement == 268435544 )
    {
      v16 = USE_POWER_BAR_LEVEL;
      v15 = 2;
    }
    else
    {
      if ( i_rMsg->idElement != 268435545 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      v16 = USE_POWER_BAR_LEVEL;
      v15 = 3;
    }
    v13 = ClientCombatSystem::GetCombatSystem();
    ClientCombatSystem::EndAttackRequest(v13, v15, v16);
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
  }
  if ( i_rMsg->idMessage == 10 )
  {
    *(float *)&i_rMsg = 0.0;
    v8 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v8, &result, &PlayerDesc_ClassType_15, (Interface **)&i_rMsg);
    v14 = (int)i_rMsg;
    v9 = i_rMsg;
    playerDesc.m_pInterface = 0;
    playerDesc.m_trStatus.m_val = 0;
    if ( *(float *)&i_rMsg != 0.0 )
      (*(void (__thiscall **)(UIElementMessageInfo *))(i_rMsg->idElement + 16))(i_rMsg);
    InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v19, v14, 0);
    if ( v9 )
      (*(void (__thiscall **)(UIElementMessageInfo *))(v9->idElement + 20))(v9);
    v10 = playerDesc.m_pInterface;
    CACQualities::InqSkillAdvancementClass((CACQualities *)&playerDesc.m_pInterface->vfptr, 0x32u, &sac);
    v11 = v3->m_RecklessnessField;
    if ( (signed int)sac < 2 )
      ((void (__stdcall *)(_DWORD))v11->vfptr[2].__vecDelDtor)(0);
    else
      ((void (__stdcall *)(signed int))v11->vfptr[2].__vecDelDtor)(1);
    v12 = (double)v2->dwParam1 * 0.001;
    *(float *)&i_rMsg = v12;
    if ( v12 <= 1.0 )
    {
      if ( *(float *)&i_rMsg < 0.0 )
        *(float *)&i_rMsg = 0.0;
    }
    else
    {
      *(float *)&i_rMsg = 1.0;
    }
    ClientCombatSystem::GetCombatSystem()->m_rUIRequestedPower = *(float *)&i_rMsg;
    if ( v10 )
    {
      v10->vfptr->Release((Interface *)v10);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
    }
  }
  else if ( i_rMsg->idMessage == 28 )
  {
    if ( i_rMsg->idElement == 268435543 )
    {
      v7 = ClientCombatSystem::GetCombatSystem();
      ClientCombatSystem::SetRequestedAttackHeight(v7, HIGH_ATTACK_HEIGHT);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
    }
    if ( i_rMsg->idElement == 268435544 )
    {
      v6 = ClientCombatSystem::GetCombatSystem();
      ClientCombatSystem::SetRequestedAttackHeight(v6, MEDIUM_ATTACK_HEIGHT);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
    }
    if ( i_rMsg->idElement == 268435545 )
    {
      v4 = ClientCombatSystem::GetCombatSystem();
      ClientCombatSystem::SetRequestedAttackHeight(v4, LOW_ATTACK_HEIGHT);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
}

//----- (004CC620) --------------------------------------------------------  // acclient.c:253733
void __thiscall gmCombatUI::RecvNotice_SetCombatMode(gmCombatUI *this, COMBAT_MODE i_eCombatMode)
{
  gmCombatUI *v2; // edi@1
  CPlayerSystem *v3; // eax@1
  InterfaceSystem *v4; // eax@3
  COMBAT_MODE v5; // ebx@3
  PlayerDesc *v6; // ebx@7
  HashSet<UIElement *>Vtbl *v7; // ecx@7
  int v8; // [sp-8h] [bp-28h]@3
  SKILL_ADVANCEMENT_CLASS sac; // [sp+Ch] [bp-14h]@7
  TResult result; // [sp+10h] [bp-10h]@3
  char v11; // [sp+14h] [bp-Ch]@5
  InterfacePtr<PlayerDesc> playerDesc; // [sp+18h] [bp-8h]@3

  v2 = this;
  v3 = CPlayerSystem::GetPlayerSystem();
  if ( (unsigned __int8)PlayerModule::AdvancedCombatUI((PlayerModule *)&v3->playerModule.vfptr) )
  {
LABEL_14:
    v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[6].__vecDelDtor(
      &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
      0);
    return;
  }
  if ( i_eCombatMode != 2 )
  {
    if ( i_eCombatMode == 4 )
    {
      v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[39].__vecDelDtor(
        &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
        268435460u);
      v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[6].__vecDelDtor(
        &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
        1u);
      return;
    }
    goto LABEL_14;
  }
  v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[39].__vecDelDtor(
    &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
    268435459u);
  v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[6].__vecDelDtor(
    &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
    1u);
  i_eCombatMode = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_15, (Interface **)&i_eCombatMode);
  v8 = i_eCombatMode;
  v5 = i_eCombatMode;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( i_eCombatMode )
    (*(void (__thiscall **)(COMBAT_MODE))(*(_DWORD *)i_eCombatMode + 16))(i_eCombatMode);
  InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v5 )
    (*(void (__thiscall **)(COMBAT_MODE))(*(_DWORD *)v5 + 20))(v5);
  v6 = playerDesc.m_pInterface;
  CACQualities::InqSkillAdvancementClass((CACQualities *)&playerDesc.m_pInterface->vfptr, 0x32u, &sac);
  v7 = v2->m_hashElementsRegisteredWith.vfptr;
  if ( (signed int)sac < 2 )
    (*((void (__stdcall **)(_DWORD))v7->__vecDelDtor + 6))(0);
  else
    (*((void (__stdcall **)(signed int))v7->__vecDelDtor + 6))(1);
  if ( v6 )
    v6->vfptr->Release((Interface *)v6);
}

//----- (006F3070) --------------------------------------------------------  // acclient.c:775547
void _E91_92()
{
  outside_val_84 = 1000.0 + 1.0;
}

//----- (006F3090) --------------------------------------------------------  // acclient.c:775553
void _E93_68()
{
  block_length_84 = 24.0 * 8.0;
}

//----- (006F30B0) --------------------------------------------------------  // acclient.c:775559
void _E95_68()
{
  half_square_length_84 = 24.0 * 0.5;
}

//----- (006F30D0) --------------------------------------------------------  // acclient.c:775565
int _E97_93()
{
  return atexit(nullsub_731);
}

//----- (006F30E0) --------------------------------------------------------  // acclient.c:775571
int _E100_86()
{
  return atexit(nullsub_732);
}

//----- (006F30F0) --------------------------------------------------------  // acclient.c:775577
int _E103_78()
{
  return atexit(_E104_93);
}

//----- (006F3100) --------------------------------------------------------  // acclient.c:775583
void _E106_52()
{
  DEFAULT_VIEW_RADIUS_53 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3120) --------------------------------------------------------  // acclient.c:775589
void _E108_39()
{
  MIN_QUANTUM_53 = 1.0 / 30.0;
}

//----- (006F3140) --------------------------------------------------------  // acclient.c:775595
void _E110_30()
{
  MAX_QUANTUM_53 = 1.0 / 5.0;
}

//----- (006F3160) --------------------------------------------------------  // acclient.c:775601
void _E112_46()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_88, PFID_A8R8G8B8);
}

//----- (006F3170) --------------------------------------------------------  // acclient.c:775607
void _E115_43()
{
  LOWEST_DATA_RATE_90 = 1024;
}

//----- (006F3180) --------------------------------------------------------  // acclient.c:775613
void _E117_31()
{
  HIGHEST_DATA_RATE_90 = 0x7FFF;
}

//----- (006F3190) --------------------------------------------------------  // acclient.c:775619
int _E119_15()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_90;
  INITIAL_MAX_DATA_RATE_38 = LOWEST_DATA_RATE_90;
  return result;
}

//----- (006F31A0) --------------------------------------------------------  // acclient.c:775629
int _E121_42()
{
  return atexit(_E122_75);
}

//----- (006F31B0) --------------------------------------------------------  // acclient.c:775635
int sub_6F31B0()
{
  return atexit(nullsub_730);
}

