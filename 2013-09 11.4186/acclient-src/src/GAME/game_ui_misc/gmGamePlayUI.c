/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmGamePlayUI
   Object     : GAME\game_ui_misc\gmGamePlayUI.obj
   Functions  : 80
   Addresses  : 004E9C60 - 00763A00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E9C60) --------------------------------------------------------  // acclient.c:279242
void __thiscall gmGamePlayUI::Show(gmGamePlayUI *this, int shown)
{
  gmGamePlayUI *v2; // esi@1

  v2 = this;
  if ( (_BYTE)shown != (unsigned __int8)((int (*)(void))this->vfptr[3].OnAction)() )
  {
    v2->m_bCurrentlyTogglingUIVisibility = 1;
    if ( UIElementManager::s_pInstance )
    {
      UIElementManager::SetVisible(UIElementManager::s_pInstance, shown);
      if ( v2->m_waitContext || v2->m_endingSession )
      {
        UIFramework::Show((UIFramework *)&v2->vfptr, 1);
        v2->m_bCurrentlyTogglingUIVisibility = 0;
      }
      else
      {
        UIFramework::Show((UIFramework *)&v2->vfptr, shown);
        v2->m_bCurrentlyTogglingUIVisibility = 0;
      }
    }
  }
}

//----- (004E9CD0) --------------------------------------------------------  // acclient.c:279268
void gmGamePlayUI::Update()
{
  UIFramework::QueueUIMode(0x1000000Au);
}

//----- (004E9CE0) --------------------------------------------------------  // acclient.c:279274
signed int __thiscall gmGamePlayUI::ListenToElementMessage(gmGamePlayUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIFramework *v3; // edi@1
  UIElement *v4; // ecx@4
  unsigned int v6; // eax@7

  v2 = i_rMsg->idMessage;
  v3 = (UIFramework *)this;
  if ( v2 == 24 )
  {
    v6 = i_rMsg->idElement;
    if ( i_rMsg->idElement == 268436741 || v6 > 0x1000050D && v6 <= 0x10000510 )
      CM_UI::SendNotice_SetPanelVisibility(v6, (*((_DWORD *)&i_rMsg->pElement->0 + 41) >> 1) & 0xFFFFFF01);
  }
  else if ( v2 == 28 )
  {
    if ( UIElementManager::s_pInstance )
    {
      v4 = UIElementManager::s_pInstance->m_focusElement;
      if ( v4 )
      {
        if ( v4 != i_rMsg->pElement )
        {
          ((void (*)(void))v4->vfptr[22].__vecDelDtor)();
          return UIFramework::ListenToElementMessage(v3, i_rMsg);
        }
      }
    }
  }
  return UIFramework::ListenToElementMessage(v3, i_rMsg);
}

//----- (004E9D70) --------------------------------------------------------  // acclient.c:279308
void __thiscall gmGamePlayUI::RecvNotice_AbortConfirmationRequest(gmGamePlayUI *this, int confirmationType, unsigned int context)
{
  gmGamePlayUI *v3; // esi@1

  v3 = this;
  if ( (HashSetData<UIElement *> *)confirmationType == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]
    && (HashSetData<UIElement *> *)context == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] )
  {
    DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5]);
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5] = 0;
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = 0;
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = 0;
  }
}

//----- (004E9DA0) --------------------------------------------------------  // acclient.c:279324
void __thiscall gmGamePlayUI::RecvNotice_PlayerOptionChanged(gmGamePlayUI *this, PlayerOption i_eOption)
{
  gmGamePlayUI *v2; // esi@1
  CPlayerSystem *v3; // eax@2
  bool v4; // zf@2
  UIElement *v5; // eax@2

  v2 = this;
  if ( i_eOption == 19 )
  {
    v3 = CPlayerSystem::GetPlayerSystem();
    v4 = (unsigned __int8)PlayerModule::SideBySideVitals((PlayerModule *)&v3->playerModule.vfptr) == 0;
    v5 = v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]->m_hashKey;
    if ( v4 )
    {
      ((void (__stdcall *)(signed int))v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
      ((void (__stdcall *)(_DWORD))v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(0);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(0);
      ((void (__stdcall *)(signed int))v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
    }
  }
}

//----- (004E9DF0) --------------------------------------------------------  // acclient.c:279351
void __thiscall gmGamePlayUI::HandleKeyPress(gmGamePlayUI *this, int i_nInputAction)
{
  gmGamePlayUI *v2; // esi@1
  IInputActionCallbackVtbl *v3; // edi@6
  int v4; // eax@6

  v2 = this;
  CPlayerSystem::GetPlayerSystem();
  if ( i_nInputAction > 268435494 )
  {
    if ( i_nInputAction == 268435495 )
    {
      v2->m_shouldQuitOnLogout = 1;
      v2->m_bLogoutConfirmed = 1;
      v2->m_doEndSession = 1;
    }
  }
  else
  {
    switch ( i_nInputAction )
    {
      case 268435494:
        v2->m_shouldQuitOnLogout = 0;
        v2->m_bLogoutConfirmed = 1;
        v2->m_doEndSession = 1;
        break;
      case 84:
        v3 = v2->vfptr;
        v4 = ((int (__thiscall *)(gmGamePlayUI *))v2->vfptr[3].OnAction)(v2);
        LOBYTE(v4) = (_BYTE)v4 == 0;
        v3[3].__vecDelDtor((IInputActionCallback *)v2, v4);
        break;
      case 123:
        KeyStone::OpenHelp(0, 268435457);
        break;
    }
  }
}

//----- (004E9E80) --------------------------------------------------------  // acclient.c:279391
signed int __thiscall gmGamePlayUI::CloseGameplayConfirmationDialog(gmGamePlayUI *this, bool confirm)
{
  gmGamePlayUI *v2; // esi@1
  signed int result; // eax@1

  v2 = this;
  CM_Character::Event_ConfirmationResponse(
    this->m_gameplayConfirmationType,
    this->m_gameplayConfirmationContextServer,
    confirm);
  result = 1;
  v2->m_gameplayConfirmationContext = 0;
  v2->m_gameplayConfirmationType = 0;
  v2->m_gameplayConfirmationContextServer = 0;
  return result;
}

//----- (004E9EC0) --------------------------------------------------------  // acclient.c:279409
void __thiscall gmGamePlayUI::SetupChildren(gmGamePlayUI *this)
{
  gmGamePlayUI *v1; // esi@1
  UIElement *v2; // eax@1
  UIElement *v3; // eax@2
  UIElement *v4; // ecx@2
  UIElement *v5; // eax@2
  UIElement *v6; // ecx@2
  UIElement *v7; // eax@2
  UIElement *v8; // ecx@2
  unsigned int v9; // edi@2
  UIElement *v10; // eax@3
  int v11; // eax@4
  unsigned int rgFloatingChatWindows[4]; // [sp+8h] [bp-B0h]@2
  unsigned int rgTitleTokens[4]; // [sp+18h] [bp-A0h]@2
  StringInfo siDefaultWindowTitle; // [sp+28h] [bp-90h]@2

  v1 = this;
  v2 = (UIElement *)((int (__stdcall *)(_DWORD, _DWORD))this->vfptr[2].__vecDelDtor)(268435462, 268436629);
  v1->m_pGameplayUI = v2;
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive(v2, 0x1000049Au);
    v4 = v1->m_pGameplayUI;
    v1->m_pSmartBoxUI = v3;
    v5 = UIElement::GetChildRecursive(v4, 0x100006D2u);
    v6 = v1->m_pGameplayUI;
    v1->m_pSmartBoxRadar = v5;
    v7 = UIElement::GetChildRecursive(v6, 0x100005FAu);
    v8 = v1->m_pGameplayUI;
    v1->m_pStackedVitals = v7;
    v1->m_pSideBySideVitals = UIElement::GetChildRecursive(v8, 0x100006D5u);
    rgFloatingChatWindows[0] = 268436741;
    rgFloatingChatWindows[1] = 268436750;
    rgFloatingChatWindows[2] = 268436751;
    rgFloatingChatWindows[3] = 268436752;
    rgTitleTokens[0] = compute_str_hash("ID_Chat_Chat1_DefaultTitle");
    rgTitleTokens[1] = compute_str_hash("ID_Chat_Chat2_DefaultTitle");
    rgTitleTokens[2] = compute_str_hash("ID_Chat_Chat3_DefaultTitle");
    rgTitleTokens[3] = compute_str_hash("ID_Chat_Chat4_DefaultTitle");
    StringInfo::StringInfo(&siDefaultWindowTitle);
    v9 = 0;
    do
    {
      StringInfo::SetStringIDandTableEnum(&siDefaultWindowTitle, rgTitleTokens[v9], 268435457);
      v10 = UIElement::GetChildRecursive(v1->m_pGameplayUI, rgFloatingChatWindows[v9]);
      if ( v10 )
      {
        v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)268435520);
        if ( v11 )
        {
          if ( v11 != 4 )
            (*(void (__stdcall **)(StringInfo *))(*(_DWORD *)(v11 - 4) + 684))(&siDefaultWindowTitle);
        }
      }
      ++v9;
    }
    while ( v9 < 4 );
    StringInfo::~StringInfo(&siDefaultWindowTitle);
  }
}

//----- (004EA010) --------------------------------------------------------  // acclient.c:279472
void __thiscall gmGamePlayUI::gmGamePlayUI(gmGamePlayUI *this)
{
  gmGamePlayUI *v1; // esi@1
  GlobalEventHandler *v2; // eax@1
  GlobalEventHandler *v3; // edi@1

  v1 = this;
  GamePlayUI::GamePlayUI((GamePlayUI *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmGamePlayUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmGamePlayUI::vftable;
  v1->m_pGameplayUI = 0;
  v1->m_pSmartBoxUI = 0;
  v1->m_pSmartBoxRadar = 0;
  v1->m_waitContext = 0;
  v1->m_logoutContext = 0;
  v1->m_gameplayConfirmationContext = 0;
  v1->m_gameplayConfirmationType = 0;
  v1->m_gameplayConfirmationContextServer = 0;
  v1->m_endingSession = 0;
  v1->m_doEndSession = 0;
  v1->m_shouldQuitOnLogout = 0;
  v1->m_bLogoutConfirmed = 0;
  v1->m_bCurrentlyTogglingUIVisibility = 0;
  Device::ForceDisplayResolution(0, 0x320u, 0x258u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xEu);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = v2;
  if ( v2 )
  {
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD207 + 2),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD207 + 3),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD207 + 4),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, (unsigned int)&loc_4DD20C, (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD20C + 1),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD279 + 1),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD1E0 + 2),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, (unsigned int)&loc_4DD1E3, (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD21E + 1),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD27F + 4),
      (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD27F + 5),
      (NoticeHandler *)&v1->vfptr);
  }
  gmGamePlayUI::SetupChildren(v1);
  gmGamePlayUI::Show(v1, 1);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C26D0: using guessed type bool (__thiscall *gmGamePlayUI::vftable)(DBCache *this);
// 7C2978: using guessed type int (__thiscall *gmGamePlayUI::vftable)(void *, char);

//----- (004EA190) --------------------------------------------------------  // acclient.c:279553
void __cdecl gmGamePlayUI::Create()
{
  gmGamePlayUI *v0; // eax@1

  v0 = (gmGamePlayUI *)operator new(0xCCu);
  if ( v0 )
    gmGamePlayUI::gmGamePlayUI(v0);
}

//----- (004EA1B0) --------------------------------------------------------  // acclient.c:279563
char __thiscall gmGamePlayUI::EndSession(gmGamePlayUI *this, bool requested)
{
  CPhysicsObj *v3; // eax@9
  CPlayerSystem *v4; // eax@11
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@13
  StringInfo siError; // [sp+4h] [bp-90h]@13

  if ( this->m_endingSession )
    return 0;
  this->m_endingSession = 1;
  if ( requested && !this->m_bLogoutConfirmed )
    return 0;
  if ( this->m_shouldQuitOnLogout && requested )
  {
    UIFramework::QueueUIMode(0x10000009u);
    return 1;
  }
  if ( SmartBox::smartbox )
  {
    v3 = SmartBox::smartbox->player;
    if ( v3 )
    {
      if ( v3->transient_state & 1 )
      {
        v4 = CPlayerSystem::GetPlayerSystem();
        if ( v4 )
        {
          CPlayerSystem::LogOffCharacter(v4, 0);
          return 1;
        }
      }
      else
      {
        this->m_endingSession = 0;
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Cannot log off while in mid-air.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
  }
  return 1;
}

//----- (004EA2A0) --------------------------------------------------------  // acclient.c:279610
void __thiscall gmGamePlayUI::~gmGamePlayUI(gmGamePlayUI *this)
{
  gmGamePlayUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmGamePlayUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmGamePlayUI::vftable;
  gmGamePlayUI::EndSession(this, 0);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  DialogFactory::CloseDialog(v1->m_waitContext);
  v1->m_waitContext = 0;
  DialogFactory::CloseDialog(v1->m_logoutContext);
  v1->m_logoutContext = 0;
  DialogFactory::CloseDialog(v1->m_gameplayConfirmationContext);
  v1->m_gameplayConfirmationContext = 0;
  ((void (__thiscall *)(gmGamePlayUI *, int))v1->vfptr[2].OnLoseFocus)(v1, &v1->m_pGameplayUI);
  UIQueueManager::OnEndCharacterSession(IQueuedUIEventDeliverer::s_pInstance);
  if ( !Device::m_bIsDone )
    Device::ForceDisplayResolution(1, 0x320u, 0x258u);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  GamePlayUI::~GamePlayUI((GamePlayUI *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C26D0: using guessed type bool (__thiscall *gmGamePlayUI::vftable)(DBCache *this);
// 7C2978: using guessed type int (__thiscall *gmGamePlayUI::vftable)(void *, char);
// 837194: using guessed type bool Device::m_bIsDone;

//----- (004EA380) --------------------------------------------------------  // acclient.c:279646
void __cdecl gmGamePlayUI::Register(unsigned int i_modeID)
{
  UIFlow::RegisterFrameworkClass(i_modeID, (UIMainFramework *(__cdecl *)())gmGamePlayUI::Create);
}

//----- (004EA3A0) --------------------------------------------------------  // acclient.c:279652
void __thiscall gmGamePlayUI::UseTime(gmGamePlayUI *this)
{
  gmGamePlayUI *v1; // esi@1
  ClientUISystem *v2; // eax@1
  ClientUISystem *v3; // eax@2
  CameraSet *v4; // eax@2
  bool v5; // al@5
  CPhysicsObj *v6; // eax@9
  CPlayerSystem *v7; // eax@11
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@13
  StringInfo i_si; // [sp+8h] [bp-90h]@13

  v1 = this;
  v2 = ClientUISystem::GetUISystem();
  if ( ClientUISystem::AccessCameraSet(v2) )
  {
    v3 = ClientUISystem::GetUISystem();
    v4 = ClientUISystem::AccessCameraSet(v3);
    CameraSet::SetScale(v4, 1.1);
  }
  if ( v1->m_doEndSession )
  {
    if ( !v1->m_endingSession )
    {
      v5 = v1->m_bLogoutConfirmed;
      v1->m_endingSession = 1;
      if ( v5 )
      {
        if ( v1->m_shouldQuitOnLogout )
        {
          UIFramework::QueueUIMode(0x10000009u);
          v1->m_doEndSession = 0;
          return;
        }
        if ( SmartBox::smartbox )
        {
          v6 = SmartBox::smartbox->player;
          if ( v6 )
          {
            if ( v6->transient_state & 1 )
            {
              v7 = CPlayerSystem::GetPlayerSystem();
              if ( v7 )
              {
                CPlayerSystem::LogOffCharacter(v7, 0);
                v1->m_doEndSession = 0;
                return;
              }
            }
            else
            {
              v1->m_endingSession = 0;
              StringInfo::StringInfo(&i_si);
              PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Cannot log off while in mid-air.");
              StringInfo::SetLiteralValue(&i_si, &_value, 1);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
              ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &i_si);
              StringInfo::~StringInfo(&i_si);
            }
          }
        }
      }
    }
    v1->m_doEndSession = 0;
  }
}

//----- (004EA4D0) --------------------------------------------------------  // acclient.c:279720
gmGamePlayUI *__thiscall gmGamePlayUI::vector_deleting_destructor(gmGamePlayUI *this, unsigned int a2)
{
  gmGamePlayUI *v2; // esi@1

  v2 = this;
  gmGamePlayUI::~gmGamePlayUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004EA4F0) --------------------------------------------------------  // acclient.c:279732
void __thiscall gmGamePlayUI::RecvNotice_CloseDialog(gmGamePlayUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmGamePlayUI *v6; // edi@1
  HashTableData<unsigned long,BaseProperty> *v7; // eax@1
  unsigned int v8; // edx@9
  HashTableData<unsigned long,BaseProperty> **v9; // eax@9
  int v10; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v11; // eax@9
  bool v12; // zf@17
  int v13; // ecx@23
  int v14; // edx@23
  int v15; // edx@27
  BasePropertyDesc *v16; // ecx@30
  unsigned int v17; // edx@30
  BasePropertyValue *v18; // ecx@34
  unsigned int v19; // edx@34
  unsigned int type; // [sp+Ch] [bp-14h]@1
  int v21; // [sp+10h] [bp-10h]@9
  int v22; // [sp+14h] [bp-Ch]@9
  BaseProperty p; // [sp+18h] [bp-8h]@1

  v3 = data;
  v4 = 0x8E % data->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v5 = data->m_hashProperties.m_intrusiveTable.m_buckets;
  type = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v6 = this;
  v7 = v5[v4];
  if ( v7 )
  {
    while ( v7->m_hashKey != 142 )
    {
      v7 = v7->m_hashNext;
      if ( !v7 )
        goto LABEL_8;
    }
    if ( v7 )
    {
      BaseProperty::operator=(&p, (int)&v7->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
    }
  }
LABEL_8:
  if ( type == 1 )
  {
    v8 = 0x92 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
    v9 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
    v10 = 0;
    LOBYTE(data) = 0;
    v21 = 0;
    v22 = 0;
    v11 = v9[v8];
    if ( v11 )
    {
      while ( v11->m_hashKey != 146 )
      {
        v11 = v11->m_hashNext;
        if ( !v11 )
          goto LABEL_16;
      }
      if ( v11 )
      {
        BaseProperty::operator=(&v21, (int)&v11->m_data);
        v10 = v22;
        if ( v22 )
        {
          (*(void (__stdcall **)(PropertyCollection **))(*(_DWORD *)v22 + 112))(&data);
          v10 = v22;
        }
      }
    }
LABEL_16:
    if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] == (HashSetData<UIElement *> *)context )
    {
      v12 = (_BYTE)data == 0;
      LOBYTE(v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 0;
      if ( !v12 )
      {
        BYTE3(v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
        BYTE1(v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
      }
      v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] = 0;
    }
    else if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5] == (HashSetData<UIElement *> *)context )
    {
      gmGamePlayUI::CloseGameplayConfirmationDialog((gmGamePlayUI *)((char *)v6 - 152), (bool)data);
      v10 = v22;
    }
    if ( v21 )
    {
      v13 = v21;
      v14 = *(_DWORD *)(v21 + 4) - 1;
      *(_DWORD *)(v21 + 4) = v14;
      if ( !v14 )
        (**(void (__stdcall ***)(_DWORD))v13)(1);
      v10 = v22;
      v21 = 0;
    }
    if ( v10 )
    {
      v15 = *(_DWORD *)(v10 + 4) - 1;
      *(_DWORD *)(v10 + 4) = v15;
      if ( !v15 )
        (**(void (__stdcall ***)(_DWORD))v10)(1);
    }
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v16 = p.m_pcPropertyDesc;
    v17 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v17;
    if ( !v17 )
      ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v18 = p.m_pcPropertyValue;
    v19 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v19;
    if ( !v19 )
      ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
  }
}

//----- (004EA690) --------------------------------------------------------  // acclient.c:279863
void __thiscall gmGamePlayUI::CreateScreenLayoutPath(gmGamePlayUI *this, PStringBase<char> i_file_name, PStringBase<char> *o_file_path)
{
  PSRefBufferCharData<char> *v3; // eax@1
  gmGamePlayUI *v4; // ebp@1
  LONG (__stdcall *v5)(volatile LONG *); // edi@1
  int v6; // esi@2
  volatile LONG *v7; // ST18_4@5
  char *v8; // esi@6
  unsigned int v9; // eax@11
  char *v10; // eax@13
  gmClient *v11; // eax@13
  PSRefBufferCharData<unsigned short> **v12; // eax@13
  PSRefBufferCharData<unsigned short> *v13; // edi@13
  volatile LONG *v14; // ST18_4@13
  PSRefBufferCharData<char> *v15; // esi@13
  PSRefBufferCharData<char> *v16; // ebx@13
  int v17; // ST18_4@13
  int v18; // eax@13
  PSRefBufferCharData<char> *v19; // ST10_4@13
  PSRefBufferCharData<char> *v20; // esi@13
  int v21; // esi@13
  int v22; // edi@16
  char *v23; // esi@19
  char *v24; // esi@23
  char *v25; // esi@26
  char *v26; // esi@29
  bool v27; // [sp+13h] [bp-15h]@6
  PStringBase<char> strDirectory; // [sp+14h] [bp-14h]@6
  PStringBase<char> character_name; // [sp+18h] [bp-10h]@6
  PStringBase<char> strPreferenceFile; // [sp+1Ch] [bp-Ch]@6
  PStringBase<unsigned short> wp_world_name; // [sp+20h] [bp-8h]@13
  PStringBase<char> world_name; // [sp+24h] [bp-4h]@13

  v3 = o_file_path->m_charbuffer;
  v4 = this;
  v5 = InterlockedDecrement;
  if ( o_file_path->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    o_file_path->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
  strDirectory.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::get_directory(&strDirectory, &strPreferenceFile);
  PStringBase<char>::PStringBase<char>(&character_name, "#auto");
  v27 = PStringBase<char>::operator==(&i_file_name, &character_name);
  v8 = &character_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&character_name.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v27 )
  {
    if ( SmartBox::smartbox )
      v9 = SmartBox::smartbox->player_id;
    else
      v9 = 0;
    v10 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v9, 0, 0);
    PStringBase<char>::PStringBase<char>(&character_name, v10);
    v11 = Client::GetInstance();
    v12 = (PSRefBufferCharData<unsigned short> **)((int (__thiscall *)(gmClient *))v11->vfptr[3].QueryInterface)(v11);
    v13 = *v12;
    v14 = (volatile LONG *)&(*v12)[-1].m_data[8];
    wp_world_name.m_charbuffer = *v12;
    InterlockedIncrement(v14);
    PStringBase<unsigned short>::to_spstring(&wp_world_name, &world_name, 0);
    v15 = character_name.m_charbuffer;
    v16 = strDirectory.m_charbuffer;
    v17 = UIRegion::GetHeight((UIRegion *)&v4->m_pGameplayUI->vfptr);
    v18 = UIRegion::GetWidth((UIRegion *)&v4->m_pGameplayUI->vfptr);
    v19 = v15;
    v20 = world_name.m_charbuffer;
    PStringBase<char>::sprintf(o_file_path, "%sUI-%s-%s-%d-%d.txt", v16, world_name.m_charbuffer, v19, v18, v17);
    v21 = (int)&v20[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v21 + 4)) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    v22 = (int)&v13[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
    v23 = &character_name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&character_name.m_charbuffer[-1]) && v23 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
    v5 = InterlockedDecrement;
  }
  else if ( *(_DWORD *)&i_file_name.m_charbuffer[-1].m_data[12] == 1 )
  {
    PStringBase<char>::sprintf(o_file_path, "%sUI-Default.txt", strDirectory.m_charbuffer);
  }
  else
  {
    PStringBase<char>::sprintf(o_file_path, "%s%s.txt", strDirectory.m_charbuffer, i_file_name.m_charbuffer);
  }
  v24 = &strDirectory.m_charbuffer[-2].m_data[12];
  if ( !v5((volatile LONG *)&strDirectory.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
  v25 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
  if ( !v5((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
  v26 = &i_file_name.m_charbuffer[-2].m_data[12];
  if ( !v5((volatile LONG *)&i_file_name.m_charbuffer[-1]) )
  {
    if ( v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  }
}

//----- (004EA8F0) --------------------------------------------------------  // acclient.c:279974
int __thiscall gmGamePlayUI::LoadScreenLayout(gmGamePlayUI *this, PStringBase<char> file_name)
{
  gmGamePlayUI *v2; // ebx@1
  PSRefBufferCharData<char> *v3; // edi@1
  FILE *v4; // eax@1
  FILE *v5; // ebp@1
  char *v6; // esi@5
  UIElement *v8; // eax@15
  UIElement *v9; // esi@46
  char *v10; // esi@52
  int xCoord; // [sp+10h] [bp-86Ch]@1
  int yCoord; // [sp+14h] [bp-868h]@1
  int width; // [sp+18h] [bp-864h]@1
  int height; // [sp+1Ch] [bp-860h]@1
  PStringBase<char> file_path; // [sp+20h] [bp-85Ch]@1
  char tag_buffer[32]; // [sp+24h] [bp-858h]@13
  PStringBase<char> token_string; // [sp+44h] [bp-838h]@1
  char line_buffer[2100]; // [sp+48h] [bp-834h]@12

  file_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)&file_name.m_charbuffer[-1]);
  gmGamePlayUI::CreateScreenLayoutPath(v2, file_name, &file_path);
  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  token_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  xCoord = 0;
  yCoord = 0;
  height = 0;
  width = 0;
  v4 = _fopen(file_path.m_charbuffer->m_data, "r");
  v5 = v4;
  if ( !v4 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
    v6 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    if ( !InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1])
      && file_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&file_name.m_charbuffer[-2].m_data[12])(
        &file_name.m_charbuffer[-2].m_data[12],
        1);
    return 0;
  }
  if ( _fgets(line_buffer, 2100, v4) )
  {
    while ( 1 )
    {
      if ( _sscanf(line_buffer, "%s X:%d Y: %d W: %d H: %d", tag_buffer, &xCoord, &yCoord, &width, &height) == 5 )
      {
        if ( !memcmp(tag_buffer, "<SBOX>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000049Au);
LABEL_46:
          v9 = v8;
          ((void (__thiscall *)(UIElement *, int, int))v8->vfptr[4].__vecDelDtor)(v8, width, height);
          ((void (__thiscall *)(UIElement *, int, int))v9->vfptr[3].OnLoseFocus)(v9, xCoord, yCoord);
          goto LABEL_47;
        }
        if ( !memcmp(tag_buffer, "<CHAT>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000601u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<FCH1>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000505u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<FCH2>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000050Eu);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<FCH3>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000050Fu);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<FCH4>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000510u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<EXAM>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005F7u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<VITS>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FAu);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<SVIT>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006D5u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<ENVP>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FDu);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<PANS>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FFu);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<TBAR>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000603u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<INDI>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000611u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<PBAR>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000613u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<COMB>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006B5u);
          goto LABEL_46;
        }
        if ( !memcmp(tag_buffer, "<RADA>", 7) )
        {
          v8 = UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006D2u);
          goto LABEL_46;
        }
      }
LABEL_47:
      if ( !_fgets(line_buffer, 2100, v5) )
      {
        v3 = token_string.m_charbuffer;
        break;
      }
    }
  }
  _fclose(v5);
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
  v10 = &file_path.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  if ( !InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1])
    && file_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&file_name.m_charbuffer[-2].m_data[12])(
      &file_name.m_charbuffer[-2].m_data[12],
      1);
  return 1;
}

//----- (004EAD50) --------------------------------------------------------  // acclient.c:280135
void __thiscall gmGamePlayUI::SaveScreenLayout(gmGamePlayUI *this, PStringBase<char> file_name)
{
  gmGamePlayUI *v2; // edi@1
  char *v3; // ebx@1
  FILE *v4; // esi@1
  char *v5; // esi@9
  UIRegion *v6; // ebx@15
  unsigned int v7; // ebp@15
  int v8; // eax@15
  UIRegion *v9; // ebp@15
  int v10; // eax@15
  UIRegion *v11; // ebp@15
  int v12; // eax@15
  UIRegion *v13; // ebp@15
  int v14; // eax@15
  UIRegion *v15; // ebp@15
  int v16; // eax@15
  UIRegion *v17; // ebp@15
  int v18; // eax@15
  UIRegion *v19; // ebp@15
  int v20; // eax@15
  UIRegion *v21; // ebp@15
  int v22; // eax@15
  UIRegion *v23; // ebp@15
  int v24; // eax@15
  UIRegion *v25; // ebp@15
  int v26; // eax@15
  UIRegion *v27; // ebp@15
  int v28; // eax@15
  UIRegion *v29; // ebp@15
  int v30; // eax@15
  UIRegion *v31; // ebp@15
  int v32; // eax@15
  UIRegion *v33; // ebp@15
  int v34; // eax@15
  UIRegion *v35; // ebp@15
  int v36; // eax@15
  UIRegion *v37; // edi@15
  unsigned int v38; // ebp@15
  int v39; // eax@15
  char *v40; // edi@15
  char *v41; // edi@18
  char *v42; // edi@21
  PStringBase<char> line_to_write; // [sp+10h] [bp-18h]@1
  int height; // [sp+14h] [bp-14h]@15
  int yCoord; // [sp+18h] [bp-10h]@15
  int xCoord; // [sp+1Ch] [bp-Ch]@15
  PStringBase<char> file_path; // [sp+20h] [bp-8h]@1
  char *v48; // [sp+24h] [bp-4h]@1

  file_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  line_to_write.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = &PStringBase<char>::s_NullBuffer.m_charbuffer[-2].m_data[12];
  v48 = &PStringBase<char>::s_NullBuffer.m_charbuffer[-2].m_data[12];
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)&file_name.m_charbuffer[-1]);
  gmGamePlayUI::CreateScreenLayoutPath(v2, file_name, &file_path);
  v4 = _fopen(file_path.m_charbuffer->m_data, "w");
  if ( v4 || (v4 = _fopen(file_path.m_charbuffer->m_data, "w+")) != 0 )
  {
    v6 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000049Au);
    v7 = UIRegion::GetScreenX0(v6);
    yCoord = UIRegion::GetScreenY0(v6);
    height = UIRegion::GetHeight(v6);
    v8 = UIRegion::GetWidth(v6);
    PStringBase<char>::sprintf(&line_to_write, "<SBOX> X:%d Y: %d W: %d H: %d\n", v7, yCoord, v8, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v9 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000601u);
    xCoord = UIRegion::GetScreenX0(v9);
    yCoord = UIRegion::GetScreenY0(v9);
    height = UIRegion::GetHeight(v9);
    v10 = UIRegion::GetWidth(v9);
    PStringBase<char>::sprintf(&line_to_write, "<CHAT> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v10, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v11 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000505u);
    xCoord = UIRegion::GetScreenX0(v11);
    yCoord = UIRegion::GetScreenY0(v11);
    height = UIRegion::GetHeight(v11);
    v12 = UIRegion::GetWidth(v11);
    PStringBase<char>::sprintf(&line_to_write, "<FCH1> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v12, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v13 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000050Eu);
    xCoord = UIRegion::GetScreenX0(v13);
    yCoord = UIRegion::GetScreenY0(v13);
    height = UIRegion::GetHeight(v13);
    v14 = UIRegion::GetWidth(v13);
    PStringBase<char>::sprintf(&line_to_write, "<FCH2> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v14, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v15 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x1000050Fu);
    xCoord = UIRegion::GetScreenX0(v15);
    yCoord = UIRegion::GetScreenY0(v15);
    height = UIRegion::GetHeight(v15);
    v16 = UIRegion::GetWidth(v15);
    PStringBase<char>::sprintf(&line_to_write, "<FCH3> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v16, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v17 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000510u);
    xCoord = UIRegion::GetScreenX0(v17);
    yCoord = UIRegion::GetScreenY0(v17);
    height = UIRegion::GetHeight(v17);
    v18 = UIRegion::GetWidth(v17);
    PStringBase<char>::sprintf(&line_to_write, "<FCH4> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v18, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v19 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005F7u);
    xCoord = UIRegion::GetScreenX0(v19);
    yCoord = UIRegion::GetScreenY0(v19);
    height = UIRegion::GetHeight(v19);
    v20 = UIRegion::GetWidth(v19);
    PStringBase<char>::sprintf(&line_to_write, "<EXAM> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v20, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v21 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FAu);
    xCoord = UIRegion::GetScreenX0(v21);
    yCoord = UIRegion::GetScreenY0(v21);
    height = UIRegion::GetHeight(v21);
    v22 = UIRegion::GetWidth(v21);
    PStringBase<char>::sprintf(&line_to_write, "<VITS> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v22, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v23 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006D5u);
    xCoord = UIRegion::GetScreenX0(v23);
    yCoord = UIRegion::GetScreenY0(v23);
    height = UIRegion::GetHeight(v23);
    v24 = UIRegion::GetWidth(v23);
    PStringBase<char>::sprintf(&line_to_write, "<SVIT> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v24, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v25 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FDu);
    xCoord = UIRegion::GetScreenX0(v25);
    yCoord = UIRegion::GetScreenY0(v25);
    height = UIRegion::GetHeight(v25);
    v26 = UIRegion::GetWidth(v25);
    PStringBase<char>::sprintf(&line_to_write, "<ENVP> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v26, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v27 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100005FFu);
    xCoord = UIRegion::GetScreenX0(v27);
    yCoord = UIRegion::GetScreenY0(v27);
    height = UIRegion::GetHeight(v27);
    v28 = UIRegion::GetWidth(v27);
    PStringBase<char>::sprintf(&line_to_write, "<PANS> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v28, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v29 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000603u);
    xCoord = UIRegion::GetScreenX0(v29);
    yCoord = UIRegion::GetScreenY0(v29);
    height = UIRegion::GetHeight(v29);
    v30 = UIRegion::GetWidth(v29);
    PStringBase<char>::sprintf(&line_to_write, "<TBAR> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v30, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v31 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000611u);
    xCoord = UIRegion::GetScreenX0(v31);
    yCoord = UIRegion::GetScreenY0(v31);
    height = UIRegion::GetHeight(v31);
    v32 = UIRegion::GetWidth(v31);
    PStringBase<char>::sprintf(&line_to_write, "<INDI> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v32, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v33 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x10000613u);
    xCoord = UIRegion::GetScreenX0(v33);
    yCoord = UIRegion::GetScreenY0(v33);
    height = UIRegion::GetHeight(v33);
    v34 = UIRegion::GetWidth(v33);
    PStringBase<char>::sprintf(&line_to_write, "<PBAR> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v34, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v35 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006B5u);
    xCoord = UIRegion::GetScreenX0(v35);
    yCoord = UIRegion::GetScreenY0(v35);
    height = UIRegion::GetHeight(v35);
    v36 = UIRegion::GetWidth(v35);
    PStringBase<char>::sprintf(&line_to_write, "<COMB> X:%d Y: %d W: %d H: %d\n", xCoord, yCoord, v36, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    v37 = (UIRegion *)UIElement::GetChildRecursive(v2->m_pGameplayUI, 0x100006D2u);
    v38 = UIRegion::GetScreenX0(v37);
    yCoord = UIRegion::GetScreenY0(v37);
    height = UIRegion::GetHeight(v37);
    v39 = UIRegion::GetWidth(v37);
    PStringBase<char>::sprintf(&line_to_write, "<RADA> X:%d Y: %d W: %d H: %d\n", v38, yCoord, v39, height);
    _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v4);
    _fclose(v4);
    v40 = v48;
    if ( !InterlockedDecrement((volatile LONG *)v48 + 1) && v40 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v40)(v40, 1);
    v41 = &line_to_write.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&line_to_write.m_charbuffer[-1]) && v41 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v41)(v41, 1);
    v42 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v42 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v42)(v42, 1);
    if ( !InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1])
      && file_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&file_name.m_charbuffer[-2].m_data[12])(
        &file_name.m_charbuffer[-2].m_data[12],
        1);
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    if ( !InterlockedDecrement((volatile LONG *)&line_to_write.m_charbuffer[-1])
      && line_to_write.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&line_to_write.m_charbuffer[-2].m_data[12])(
        &line_to_write.m_charbuffer[-2].m_data[12],
        1);
    v5 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    if ( !InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1])
      && file_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&file_name.m_charbuffer[-2].m_data[12])(
        &file_name.m_charbuffer[-2].m_data[12],
        1);
  }
}

//----- (004EB5A0) --------------------------------------------------------  // acclient.c:280347
void __thiscall gmGamePlayUI::ListenToGlobalMessage(gmGamePlayUI *this, unsigned int i_messageID, int i_data_int)
{
  gmGamePlayUI *v3; // esi@1
  PStringBase<char> v4; // [sp-4h] [bp-8h]@5

  v3 = this;
  if ( i_messageID == 1 )
  {
    gmGamePlayUI::HandleKeyPress(this, i_data_int);
  }
  else if ( i_messageID == 3 )
  {
    gmGamePlayUI::UseTime(this);
  }
  else if ( i_messageID == 14 && !this->m_endingSession )
  {
    v4.m_charbuffer = (PSRefBufferCharData<char> *)this;
    PStringBase<char>::PStringBase<char>(&v4, "#auto");
    gmGamePlayUI::LoadScreenLayout(v3, v4);
  }
}

//----- (004EB600) --------------------------------------------------------  // acclient.c:280370
void __thiscall gmGamePlayUI::RecvNotice_SaveUI(gmGamePlayUI *this, PStringBase<char> *file_name)
{
  gmGamePlayUI *v2; // esi@1
  PStringBase<char> v3; // ST04_4@1

  v2 = this;
  v3.m_charbuffer = file_name->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&file_name->m_charbuffer[-1]);
  gmGamePlayUI::SaveScreenLayout((gmGamePlayUI *)((char *)v2 - 152), v3);
}

//----- (004EB630) --------------------------------------------------------  // acclient.c:280382
void __thiscall gmGamePlayUI::RecvNotice_LoadUI(gmGamePlayUI *this, PStringBase<char> *file_name)
{
  gmGamePlayUI *v2; // esi@1
  PStringBase<char> v3; // ST04_4@1

  v2 = this;
  v3.m_charbuffer = file_name->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&file_name->m_charbuffer[-1]);
  gmGamePlayUI::LoadScreenLayout((gmGamePlayUI *)((char *)v2 - 152), v3);
}

//----- (004EB660) --------------------------------------------------------  // acclient.c:280394
void __thiscall gmGamePlayUI::RecvNotice_PlayerDescReceived(gmGamePlayUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmGamePlayUI *v3; // edi@1
  PSRefBufferCharData<char> *v4; // ecx@1
  CPlayerSystem *v5; // esi@1
  PStringBase<char> v6; // [sp-4h] [bp-Ch]@2

  v3 = this;
  v5 = CPlayerSystem::GetPlayerSystem();
  if ( v5 )
  {
    v6.m_charbuffer = v4;
    PStringBase<char>::PStringBase<char>(&v6, "#auto");
    v5->m_layoutFromFile = gmGamePlayUI::LoadScreenLayout((gmGamePlayUI *)((char *)v3 - 152), v6) != 0;
  }
}

//----- (004EB6A0) --------------------------------------------------------  // acclient.c:280412
char __thiscall gmGamePlayUI::MakeLogoutConfirmationDialog(gmGamePlayUI *this, StringInfo *msg)
{
  gmGamePlayUI *v2; // esi@1
  IInputActionCallbackVtbl *v3; // eax@2
  unsigned __int32 v4; // eax@8
  BasePropertyDesc *v5; // ecx@10
  unsigned int v6; // esi@10
  BasePropertyValue *v7; // ecx@14
  unsigned int v8; // edx@14
  BasePropertyDesc *v10; // ecx@19
  unsigned int v11; // esi@19
  BasePropertyValue *v12; // ecx@23
  unsigned int v13; // edx@23
  BaseProperty p; // [sp+14h] [bp-84h]@2
  unsigned int _key; // [sp+1Ch] [bp-7Ch]@4
  PropertyCollection pc; // [sp+20h] [bp-78h]@2

  v2 = this;
  if ( this->m_logoutContext )
    return 0;
  v3 = this->vfptr;
  this->m_bLogoutConfirmed = 0;
  ((void (__stdcall *)(signed int))v3[3].__vecDelDtor)(1);
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
  BaseProperty::SetPropertyName(&p, 0xC3u);
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
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(msg);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v4 = DialogFactory::MakeDialog((UIFramework *)&v2->vfptr, &pc);
  v2->m_logoutContext = v4;
  if ( !v4 )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v10 = p.m_pcPropertyDesc;
      v11 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v12 = p.m_pcPropertyValue;
      v13 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    return 0;
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v5 = p.m_pcPropertyDesc;
    v6 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v7 = p.m_pcPropertyValue;
    v8 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v8;
    if ( !v8 )
      ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  return 1;
}

//----- (004EB890) --------------------------------------------------------  // acclient.c:280519
char __thiscall gmGamePlayUI::MakeGameplayConfirmationDialog(gmGamePlayUI *this, StringInfo *msg)
{
  gmGamePlayUI *v2; // esi@1
  unsigned __int32 v3; // eax@8
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BasePropertyDesc *v9; // ecx@20
  unsigned int v10; // edx@20
  BasePropertyValue *v11; // ecx@24
  unsigned int v12; // esi@24
  BaseProperty p; // [sp+10h] [bp-84h]@2
  unsigned int _key; // [sp+18h] [bp-7Ch]@4
  PropertyCollection pc; // [sp+1Ch] [bp-78h]@2

  v2 = this;
  if ( this->m_gameplayConfirmationContext )
    return 0;
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
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(msg);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v3 = DialogFactory::MakeDialog((UIFramework *)&v2->vfptr, &pc);
  v2->m_gameplayConfirmationContext = v3;
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
  return 1;
}

//----- (004EBA70) --------------------------------------------------------  // acclient.c:280622
void __thiscall gmGamePlayUI::RecvNotice_AlterSkill_ConfirmationRequest(gmGamePlayUI *this, AC1Legacy::PStringBase<char> *userData, unsigned int context)
{
  gmGamePlayUI *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // edi@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // esi@4
  AC1Legacy::PStringBase<char> msg; // [sp+10h] [bp-98h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-94h]@1
  StringInfo info; // [sp+18h] [bp-90h]@4

  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)context;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)2;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, " Continue?");
  AC1Legacy::PStringBase<char>::operator+(userData, &msg, &rhs);
  v4 = rhs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  StringInfo::StringInfo(&info);
  v5 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&msg, 0, msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&info, v6, 1);
  v7 = (char *)&msg.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  gmGamePlayUI::MakeGameplayConfirmationDialog((gmGamePlayUI *)((char *)v3 - 152), &info);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}

//----- (004EBB50) --------------------------------------------------------  // acclient.c:280658
void __thiscall gmGamePlayUI::RecvNotice_AlterAttribute_ConfirmationRequest(gmGamePlayUI *this, AC1Legacy::PStringBase<char> *userData, unsigned int context)
{
  gmGamePlayUI *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // edi@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // esi@4
  AC1Legacy::PStringBase<char> msg; // [sp+10h] [bp-98h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-94h]@1
  StringInfo info; // [sp+18h] [bp-90h]@4

  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)context;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)3;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, " Continue?");
  AC1Legacy::PStringBase<char>::operator+(userData, &msg, &rhs);
  v4 = rhs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  StringInfo::StringInfo(&info);
  v5 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&msg, 0, msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&info, v6, 1);
  v7 = (char *)&msg.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  gmGamePlayUI::MakeGameplayConfirmationDialog((gmGamePlayUI *)((char *)v3 - 152), &info);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}

//----- (004EBC30) --------------------------------------------------------  // acclient.c:280694
void __thiscall gmGamePlayUI::RecvNotice_Augmentation_ConfirmationRequest(gmGamePlayUI *this, AC1Legacy::PStringBase<char> *userData, unsigned int context)
{
  gmGamePlayUI *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // edi@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // esi@4
  AC1Legacy::PStringBase<char> msg; // [sp+10h] [bp-98h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-94h]@1
  StringInfo info; // [sp+18h] [bp-90h]@4

  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)context;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)6;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, " Continue?");
  AC1Legacy::PStringBase<char>::operator+(userData, &msg, &rhs);
  v4 = rhs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  StringInfo::StringInfo(&info);
  v5 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&msg, 0, msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&info, v6, 1);
  v7 = (char *)&msg.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  gmGamePlayUI::MakeGameplayConfirmationDialog((gmGamePlayUI *)((char *)v3 - 152), &info);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}

//----- (004EBD10) --------------------------------------------------------  // acclient.c:280730
void __thiscall gmGamePlayUI::RecvNotice_YesNo_ConfirmationRequest(gmGamePlayUI *this, AC1Legacy::PStringBase<char> *userData, unsigned int context)
{
  gmGamePlayUI *v3; // edi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  volatile LONG *v5; // ebp@1
  PStringBase<unsigned short> *v6; // eax@1
  char *v7; // ebx@1
  PStringBase<unsigned short> v8; // [sp+10h] [bp-94h]@1
  StringInfo info; // [sp+14h] [bp-90h]@1

  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)context;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)7;
  v4 = userData->m_buffer;
  v5 = (volatile LONG *)&userData->m_buffer->m_cRef;
  InterlockedIncrement(v5);
  StringInfo::StringInfo(&info);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v8, 0, v4->m_data);
  StringInfo::SetLiteralValue(&info, v6, 1);
  v7 = (char *)&v8.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v8.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  gmGamePlayUI::MakeGameplayConfirmationDialog((gmGamePlayUI *)((char *)v3 - 152), &info);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement(v5) )
  {
    if ( v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  }
}

//----- (004EBDC0) --------------------------------------------------------  // acclient.c:280762
void __thiscall gmGamePlayUI::RecvNotice_CraftInteraction_ConfirmationRequest(gmGamePlayUI *this, AC1Legacy::PStringBase<char> *userData, unsigned int context)
{
  gmGamePlayUI *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // edi@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // esi@4
  AC1Legacy::PStringBase<char> msg; // [sp+10h] [bp-98h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-94h]@1
  StringInfo info; // [sp+18h] [bp-90h]@4

  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)context;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)5;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, " Continue?");
  AC1Legacy::PStringBase<char>::operator+(userData, &msg, &rhs);
  v4 = rhs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  StringInfo::StringInfo(&info);
  v5 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&msg, 0, msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&info, v6, 1);
  v7 = (char *)&msg.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  gmGamePlayUI::MakeGameplayConfirmationDialog((gmGamePlayUI *)((char *)v3 - 152), &info);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}

//----- (004EBEA0) --------------------------------------------------------  // acclient.c:280798
void __thiscall gmGamePlayUI::RecvNotice_EndCharacterSession(gmGamePlayUI *this, int confirm)
{
  gmGamePlayUI *v2; // esi@1
  StringInfo info; // [sp+4h] [bp-90h]@2

  v2 = this;
  if ( confirm )
  {
    BYTE1(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
    BYTE2(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 0;
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_Client_EndCharacterSessionConfirm, 268435457);
    gmGamePlayUI::MakeLogoutConfirmationDialog((gmGamePlayUI *)((char *)v2 - 152), &info);
    StringInfo::~StringInfo(&info);
  }
  else
  {
    BYTE3(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
    BYTE1(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
    BYTE2(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
  }
}

//----- (004EBF10) --------------------------------------------------------  // acclient.c:280822
void __thiscall gmGamePlayUI::RecvNotice_Logoff(gmGamePlayUI *this)
{
  gmGamePlayUI *v1; // esi@1
  StringInfo info; // [sp+4h] [bp-90h]@1

  v1 = this;
  BYTE1(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
  BYTE2(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableEnum(&info, ID_Client_LogoffConfirm, 268435457);
  gmGamePlayUI::MakeLogoutConfirmationDialog((gmGamePlayUI *)((char *)v1 - 152), &info);
  StringInfo::~StringInfo(&info);
}

//----- (006F6EF0) --------------------------------------------------------  // acclient.c:779664
void sub_6F6EF0()
{
  flt_840A98 = 1000.0 + 1.0;
}

//----- (006F6F10) --------------------------------------------------------  // acclient.c:779670
void sub_6F6F10()
{
  flt_840A9C = 24.0 * 8.0;
}

//----- (006F6F30) --------------------------------------------------------  // acclient.c:779676
void sub_6F6F30()
{
  flt_840AA0 = 24.0 * 0.5;
}

//----- (006F6F50) --------------------------------------------------------  // acclient.c:779682
int sub_6F6F50()
{
  return atexit(nullsub_623);
}

//----- (006F6F60) --------------------------------------------------------  // acclient.c:779688
int sub_6F6F60()
{
  return atexit(nullsub_624);
}

//----- (006F6F70) --------------------------------------------------------  // acclient.c:779694
int sub_6F6F70()
{
  return atexit(nullsub_625);
}

//----- (006F6F80) --------------------------------------------------------  // acclient.c:779700
void _E106_76()
{
  DEFAULT_VIEW_RADIUS_79 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6FA0) --------------------------------------------------------  // acclient.c:779706
void _E108_59()
{
  MIN_QUANTUM_79 = 1.0 / 30.0;
}

//----- (006F6FC0) --------------------------------------------------------  // acclient.c:779712
void _E110_49()
{
  MAX_QUANTUM_79 = 1.0 / 5.0;
}

//----- (006F6FE0) --------------------------------------------------------  // acclient.c:779718
void _E112_68()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840AB8, PFID_A8R8G8B8);
}

//----- (006F6FF0) --------------------------------------------------------  // acclient.c:779724
void _E114_35()
{
  dword_840AF0 = 1024;
}

//----- (006F7000) --------------------------------------------------------  // acclient.c:779730
void _E116_13()
{
  dword_840AF4 = 0x7FFF;
}

//----- (006F7010) --------------------------------------------------------  // acclient.c:779736
int _E118_52()
{
  const int result; // eax@1

  result = dword_840AF0;
  INITIAL_MAX_DATA_RATE_51 = dword_840AF0;
  return result;
}

//----- (006F7020) --------------------------------------------------------  // acclient.c:779746
int _E120_42()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_17, "Display.Resolution");
  return atexit(sub_763760);
}

//----- (006F7040) --------------------------------------------------------  // acclient.c:779753
int _E123_21()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_17, "Display.FullScreen");
  return atexit(sub_763790);
}

//----- (006F7060) --------------------------------------------------------  // acclient.c:779760
int _E126_25()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_17, "Display.RefreshRate");
  return atexit(_E127_97);
}

//----- (006F7080) --------------------------------------------------------  // acclient.c:779767
int _E129_20()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_17, "Display.SyncToRefresh");
  return atexit(_E130_89);
}

//----- (006F70A0) --------------------------------------------------------  // acclient.c:779774
int _E133_27()
{
  return atexit(_E134_31);
}

//----- (006F70B0) --------------------------------------------------------  // acclient.c:779780
int _E136_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_42, "Misc.TooltipEnable");
  return atexit(_E137_30);
}

//----- (006F70D0) --------------------------------------------------------  // acclient.c:779787
int _E139_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_42, "Misc.TooltipDelay");
  return atexit(_E140_25);
}

//----- (006F70F0) --------------------------------------------------------  // acclient.c:779794
int _E145_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_40, "None");
  return atexit(_E146_26);
}

//----- (006F7110) --------------------------------------------------------  // acclient.c:779801
int _E148_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_40, "Speed");
  return atexit(_E149_26);
}

//----- (006F7130) --------------------------------------------------------  // acclient.c:779808
int _E151_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_40, "Noise");
  return atexit(_E152_24);
}

//----- (006F7150) --------------------------------------------------------  // acclient.c:779815
int _E154_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_40, "Sine");
  return atexit(_E155_21);
}

//----- (006F7170) --------------------------------------------------------  // acclient.c:779822
int _E157_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_40, "Square");
  return atexit(_E158_23);
}

//----- (006F7190) --------------------------------------------------------  // acclient.c:779829
int _E160_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_40, "Bounce");
  return atexit(_E161_22);
}

//----- (006F71B0) --------------------------------------------------------  // acclient.c:779836
int _E163_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_40, "Perlin");
  return atexit(_E164_24);
}

//----- (006F71D0) --------------------------------------------------------  // acclient.c:779843
int _E166_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_40, "Fractal");
  return atexit(_E167_20);
}

//----- (006F71F0) --------------------------------------------------------  // acclient.c:779850
int _E169_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_40, "FrameLoop");
  return atexit(_E170_19);
}

//----- (006F7210) --------------------------------------------------------  // acclient.c:779857
unsigned int _E172_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Wait_PleaseWait");
  ID_Wait_PleaseWait_0 = result;
  return result;
}

//----- (006F7230) --------------------------------------------------------  // acclient.c:779867
unsigned int _E174_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Client_EndCharacterSessionConfirm");
  ID_Client_EndCharacterSessionConfirm = result;
  return result;
}

//----- (006F7250) --------------------------------------------------------  // acclient.c:779877
unsigned int _E176_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Client_LogoffConfirm");
  ID_Client_LogoffConfirm = result;
  return result;
}

//----- (006F7270) --------------------------------------------------------  // acclient.c:779887
int sub_6F7270()
{
  return atexit(nullsub_622);
}

//----- (00763760) --------------------------------------------------------  // acclient.c:890094
void __cdecl sub_763760()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763790) --------------------------------------------------------  // acclient.c:890107
void __cdecl sub_763790()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007637C0) --------------------------------------------------------  // acclient.c:890120
void __cdecl _E127_97()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007637F0) --------------------------------------------------------  // acclient.c:890133
void __cdecl _E130_89()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763820) --------------------------------------------------------  // acclient.c:890146
void __cdecl _E137_30()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763850) --------------------------------------------------------  // acclient.c:890159
void __cdecl _E140_25()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763880) --------------------------------------------------------  // acclient.c:890172
void __cdecl _E146_26()
{
  char *v0; // esi@1

  v0 = &waveform_None_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007638B0) --------------------------------------------------------  // acclient.c:890185
void __cdecl _E149_26()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007638E0) --------------------------------------------------------  // acclient.c:890198
void __cdecl _E152_24()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763910) --------------------------------------------------------  // acclient.c:890211
void __cdecl _E155_21()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763940) --------------------------------------------------------  // acclient.c:890224
void __cdecl _E158_23()
{
  char *v0; // esi@1

  v0 = &waveform_Square_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763970) --------------------------------------------------------  // acclient.c:890237
void __cdecl _E161_22()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007639A0) --------------------------------------------------------  // acclient.c:890250
void __cdecl _E164_24()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007639D0) --------------------------------------------------------  // acclient.c:890263
void __cdecl _E167_20()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763A00) --------------------------------------------------------  // acclient.c:890276
void __cdecl _E170_19()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

