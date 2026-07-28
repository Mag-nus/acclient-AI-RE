/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIFlow
   Object     : GAME\game_ui_misc\gmUIFlow.obj
   Functions  : 54
   Addresses  : 0047A460 - 0075EFD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0047A460) --------------------------------------------------------  // acclient.c:183653
void __cdecl gmUIHelper::RegisterElements()
{
  gmUIElement_BurdenIndicator::Register();
  gmUIElement_EffectsIndicator::Register();
  gmUIElement_LinkStatusIndicator::Register();
  gmUIElement_MiniGameIndicator::Register();
  gmUIElement_PortalStormIndicator::Register();
  gmUIElement_VitaeIndicator::Register();
  UIElement_SmartBoxWrapper::Register();
  UIElement_ItemList::Register();
  UIElement_UIItem::Register();
  gmBarberUI::Register();
  gmKeyboardUI::Register();
  gmPowerbarUI::Register();
  gmRadarUI::Register();
  gmSmartBoxUI::Register();
  gmSpewBoxUI::Register();
  gmFloatyCombatPanelUI::Register();
  gmFloatyEnvPanelUI::Register();
  gmFloatyExaminationUI::Register();
  gmFloatyIndicatorsUI::Register();
  gmFloatyMainChatUI::Register();
  gmFloatyPanelUI::Register();
  gmFloatyPowerBarUI::Register();
  gmFloatySideVitalsUI::Register();
  gmFloatyToolbarUI::Register();
  gmFloatyVitalsUI::Register();
  gmFloatyChatUI::Register();
  gmMainChatUI::Register();
  gmAdminQualitiesUI::Register();
  gmEnvPanelUI::Register();
  gmCombatUI::Register();
  gmExternalContainerUI::Register();
  gmSalvageUI::Register();
  gmSecureTradeUI::Register();
  gmSlumlordUI::Register();
  gmSpellcastingUI::Register();
  gmVendorUI::Register();
  gmVitalsUI::Register();
  gmIndicatorsUI::Register();
  gmToolbarUI::Register();
  gmPanelUI::Register();
  gmAbuseUI::Register();
  gmBookUI::Register();
  gmCharacterInfoUI::Register();
  gmEffectsUI::Register();
  gmExaminationUI::Register();
  gmLinkStatusUI::Register();
  gmMiniGameUI::Register();
  gmUrgentAssistanceUI::Register();
  gmVitaeUI::Register();
  gm3DItemsUI::Register();
  gmBackpackUI::Register();
  gmInventoryUI::Register();
  gmPaperDollUI::Register();
  gmHouseUI::Register();
  gmMapUI::Register();
  gmCharacterSettingsUI::Register();
  gmChatOptionsUI::Register();
  gmConfigUI::Register();
  gmGameplayOptionsUI::Register();
  gmAttributeUI::Register();
  gmSkillUI::Register();
  gmCharacterTitleUI::Register();
  gmContractsUI::Register();
  gmJournalUI::Register();
  gmPageListUI::Register();
  gmAllegianceUI::Register();
  gmFellowshipUI::Register();
  gmFriendsUI::Register();
  gmSquelchUI::Register();
  gmSpellbookUI::Register();
  gmSpellComponentUI::Register();
  UIOption_ActionKeyMap::Register();
  UIOption_Checkbox::Register();
  UIOption_CheckboxBitfield::Register();
  UIOption_CheckboxBitfield64::Register();
  UIOption_Slider::Register();
  UIOption_CheckboxSlider::Register();
  UIOption_Menu::Register();
  gmCGHeritagePage::Register();
  gmCGProfessionPage::Register();
  gmCGSkillsPage::Register();
  gmCGAppearancePage::Register();
  gmCGTownPage::Register();
  gmCGSummaryPage::Register();
}

//----- (0047A610) --------------------------------------------------------  // acclient.c:183742
void __thiscall gmUIFlow::gmUIFlow(gmUIFlow *this)
{
  gmUIFlow *v1; // esi@1
  GlobalEventHandler *v2; // eax@1
  GlobalEventHandler *v3; // edi@1
  IDClass<_tagDataID,32,0> pointerID; // [sp+10h] [bp-4h]@1

  v1 = this;
  UIFlow::UIFlow((UIFlow *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (InterfaceVtbl *)&gmUIFlow::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmUIFlow::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmUIFlow::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmUIFlow::vftable;
  UIGlobals::Init();
  gmUIHelper::RegisterElements();
  gmDataPatchUI::Register(0x10000003u);
  gmIntroUI::Register(0x10000001u);
  gmCharacterManagementUI::Register(0x1000000Au);
  gmGamePlayUI::Register(0x10000008u);
  gmEpilogueUI::Register(0x10000009u);
  gmDisconnectedUI::Register(0x10000002u);
  gmCharGenMainUI::Register(0x1000000Bu);
  gmCreditsUI::Register(0x10000005u);
  UIFlow::QueueUIMode((UIFlow *)&v1->vfptr, 0x10000003u);
  DBObj::GetDIDByEnum(&pointerID, 1, 6);
  UIElementManager::SetCursor(UIElementManager::s_pInstance, pointerID, 0, 0, 1);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = v2;
  if ( v2 )
  {
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100001u, (NoticeHandler *)&v1->vfptr);
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, 100000u, (NoticeHandler *)&v1->vfptr);
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(14, &v1->vfptr, 4000);
  }
}
// 79E20C: using guessed type __int32 (__stdcall *gmUIFlow::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 79E528: using guessed type bool (__thiscall *gmUIFlow::vftable)(DBCache *this);
// 79E7D0: using guessed type int (__stdcall *gmUIFlow::vftable)(char);
// 79E7E8: using guessed type bool (__thiscall *gmUIFlow::vftable)(DBObj *this);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047A720) --------------------------------------------------------  // acclient.c:183786
void __thiscall gmUIFlow::~gmUIFlow(gmUIFlow *this)
{
  UIFlow *v1; // esi@1
  char *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  NoticeHandler *v4; // ecx@3

  v1 = (UIFlow *)this;
  v2 = (char *)&this->_nextText.m_strEnglish;
  this[-1]._nextText.m_strComment.m_charbuffer = (PSRefBufferCharData<char> *)&gmUIFlow::vftable;
  this[-1].vfptr = (NoticeHandlerVtbl *)&gmUIFlow::vftable;
  this->vfptr = (InterfaceVtbl *)&gmUIFlow::vftable;
  this->_nextText.m_strEnglish.m_charbuffer = (PSRefBufferCharData<char> *)&gmUIFlow::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
  {
    v3->vfptr->UnRegisterAllNoticeHandlers(
      (NoticeRegistrar *)v3,
      (NoticeHandler *)(v1 != (UIFlow *)8 ? (unsigned int)v2 : 0));
    UIGlobals::Cleanup();
  }
  v4 = (NoticeHandler *)(v1 != (UIFlow *)8 ? (unsigned int)v2 : 0);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v4);
  UIFlow::~UIFlow(v1);
}
// 79E20C: using guessed type __int32 (__stdcall *gmUIFlow::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 79E528: using guessed type bool (__thiscall *gmUIFlow::vftable)(DBCache *this);
// 79E7D0: using guessed type int (__stdcall *gmUIFlow::vftable)(char);
// 79E7E8: using guessed type bool (__thiscall *gmUIFlow::vftable)(DBObj *this);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047A790) --------------------------------------------------------  // acclient.c:183819
int __thiscall gmUIFlow::vector_deleting_destructor(gmUIFlow *this, char a2)
{
  gmUIFlow *v2; // esi@1
  int result; // eax@1

  v2 = this;
  gmUIFlow::~gmUIFlow(this);
  result = (int)&v2[-1]._nextText.m_strComment;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1]._nextText.m_strComment);
    result = (int)&v2[-1]._nextText.m_strComment;
  }
  return result;
}

//----- (0047A7C0) --------------------------------------------------------  // acclient.c:183836
void __thiscall gmUIFlow::RecvNotice_CharacterError(gmUIFlow *this, charError _error)
{
  gmUIFlow *v2; // esi@1
  signed int v3; // eax@2
  unsigned int v4; // eax@10
  StringInfo info; // [sp+8h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&info);
  StringInfo::SetTableEnum(&info, 268435458);
  switch ( _error )
  {
    case 1:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_LOGON");
      v3 = 268435458;
      goto LABEL_23;
    case 3:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_ACCOUNT_LOGON");
      v3 = 268435458;
      goto LABEL_23;
    case 4:
    case 8:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_SERVER_CRASH");
      v3 = 268435458;
      goto LABEL_23;
    case 9:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_ACCOUNT_INVALID");
      v3 = 268435458;
      goto LABEL_23;
    case 10:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_ACCOUNT_DOESNT_EXIST");
      v3 = 268435458;
      goto LABEL_23;
    case 14:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_ENTER_GAME_PLAYER_ACCOUNT_MISSING");
      v3 = 268435458;
      goto LABEL_23;
    case 21:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_LOGON_SERVER_FULL");
      v3 = 268435458;
      goto LABEL_23;
    case 24:
      info.m_stringID = Tokenize("ID_CHAR_ERROR_SUBSCRIPTION_EXPIRED");
      v3 = 268435458;
      goto LABEL_23;
    case 6:
      v4 = Tokenize("ID_CHAR_ERROR_DELETE");
      goto LABEL_22;
    case 5:
      v4 = Tokenize("ID_CHAR_ERROR_LOGOFF");
      goto LABEL_22;
    case 23:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_CHARACTER_LOCKED");
      goto LABEL_22;
    case 20:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_COULDNT_PLACE_CHARACTER");
      goto LABEL_22;
    case 15:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_CHARACTER_NOT_OWNED");
      goto LABEL_22;
    case 16:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_CHARACTER_IN_WORLD_SERVER");
      goto LABEL_22;
    case 17:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_OLD_CHARACTER");
      goto LABEL_22;
    case 18:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_CORRUPT_CHARACTER");
      goto LABEL_22;
    case 19:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_START_SERVER_DOWN");
      goto LABEL_22;
    case 11:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_GENERIC");
      goto LABEL_22;
    case 12:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_STRESS_ACCOUNT");
      goto LABEL_22;
    case 13:
      v4 = Tokenize("ID_CHAR_ERROR_ENTER_GAME_CHARACTER_IN_WORLD");
LABEL_22:
      info.m_stringID = v4;
      v3 = 268435466;
LABEL_23:
      ((void (__thiscall *)(int, signed int, StringInfo *))v2[-1].vfptr->RecvNotice_CharacterError)(
        &v2[-1].vfptr,
        v3,
        &info);
      break;
    default:
      break;
  }
  StringInfo::~StringInfo(&info);
}

//----- (0047A9A0) --------------------------------------------------------  // acclient.c:183932
void __thiscall gmUIFlow::RecvNotice_ServerDied(gmUIFlow *this)
{
  gmUIFlow *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ecx@1
  StringInfo info; // [sp+8h] [bp-90h]@1

  v1 = this;
  StringInfo::StringInfo(&info);
  v2 = compute_str_hash("ID_NetErr_ConnectionLost");
  StringInfo::SetStringIDandTableEnum(&info, v2, 268435458);
  v3 = (int)&v1[-1].vfptr;
  if ( v1->m_cTurbineRefCount.m_cRef != 268435458 && *(_DWORD *)(v3 + 144) != 268435458 )
    (*(void (__stdcall **)(signed int, StringInfo *))(*(_DWORD *)v3 + 32))(268435458, &info);
  StringInfo::~StringInfo(&info);
}

//----- (0047AA10) --------------------------------------------------------  // acclient.c:183950
void __thiscall gmUIFlow::RecvNotice_CharacterError(void *this, charError a2)
{
  gmUIFlow::RecvNotice_CharacterError((gmUIFlow *)((char *)this - 296), a2);
}

//----- (0047AA20) --------------------------------------------------------  // acclient.c:183956
void __thiscall gmUIFlow::RecvNotice_ServerDied(gmUIFlow *this)
{
  gmUIFlow::RecvNotice_ServerDied((gmUIFlow *)((char *)this - 296));
}

//----- (0047AA30) --------------------------------------------------------  // acclient.c:183962
TResult *__thiscall ClassFactoryForceUIFlow_ClassType::QueryInterface(ClassFactoryForceUIFlow_ClassType *this, TResult *result, Turbine_GUID *_rInterfaceType, void **_ppOutInterface)
{
  ClassFactoryForceUIFlow_ClassType *v4; // esi@1
  TResult *v5; // eax@10

  v4 = this;
  if ( (_rInterfaceType->m_data1 == 1244181156
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&IObjectFactory_InterfaceType_13.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&IObjectFactory_InterfaceType_13.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&IObjectFactory_InterfaceType_13.m_data4[4]
     || _rInterfaceType->m_data1 == -559038737
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&Interface_InterfaceType_29.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_29.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_29.m_data4[4])
    && this )
  {
    this->vfptr->AddRef((Interface *)this);
    *_ppOutInterface = v4;
    v5 = result;
    result->m_val = 0;
  }
  else
  {
    v5 = result;
    result->m_val = -2147467262;
  }
  return v5;
}

//----- (0047AAC0) --------------------------------------------------------  // acclient.c:183992
int __thiscall ClassFactoryForceClient_ClassType::Release(ClassFactoryForceUIFlow_ClassType *this)
{
  ClassFactoryForceUIFlow_ClassType *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@2

  v1 = this;
  v2 = (char *)&this->m_cTurbineRefCount.m_cRef;
  if ( InterlockedDecrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef) )
  {
    v3 = *(_DWORD *)v2;
    if ( v3 )
      return v3;
  }
  else
  {
    v3 = 0;
  }
  if ( v1 )
  {
    v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
    operator delete(v1);
  }
  return v3;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);

//----- (0047AB00) --------------------------------------------------------  // acclient.c:184020
TResult *__stdcall ClassFactoryForceUIFlow_ClassType::CreateInstance(TResult *result, Interface *_pOuterInterface, Turbine_GUID *_rInterfaceType, void **_ppvObject)
{
  TResult *v5; // eax@2
  gmUIFlow *v6; // eax@3
  int v7; // eax@4
  Interface *v8; // ecx@6
  void **v9; // ST08_4@7
  Interface *v10; // ecx@7
  bool v11; // zf@7
  TResult *v12; // esi@7
  int v13; // [sp+8h] [bp-Ch]@6
  InterfacePtr<Interface> spInterface; // [sp+Ch] [bp-8h]@6

  if ( _pOuterInterface )
  {
    v5 = result;
    result->m_val = -2147221232;
    return v5;
  }
  v6 = (gmUIFlow *)operator new(0x130u);
  if ( v6 )
    gmUIFlow::gmUIFlow(v6);
  else
    v7 = 0;
  spInterface.m_pInterface = 0;
  spInterface.m_trStatus.m_val = 0;
  spInterface.m_trStatus.m_val = *(_DWORD *)InterfacePtr<Interface>::_QueryInterface(&spInterface, (int)&v13, v7);
  v8 = spInterface.m_pInterface;
  if ( _ppvObject )
  {
    v9 = _ppvObject;
    *_ppvObject = 0;
    ((void (__stdcall *)(Interface **, Turbine_GUID *, void **))v8->vfptr->QueryInterface)(
      &_pOuterInterface,
      _rInterfaceType,
      v9);
    ((void (*)(void))spInterface.m_pInterface->vfptr->Release)();
    v10 = spInterface.m_pInterface;
    v11 = (_DWORD)spInterface.m_pInterface == 0;
    v12 = result;
    result->m_val = (unsigned int)_pOuterInterface;
    if ( !v11 )
    {
      ((void (*)(void))v10->vfptr->Release)();
      return result;
    }
  }
  else
  {
    v12 = result;
    result->m_val = -2147467261;
    if ( v8 )
      ((void (*)(void))v8->vfptr->Release)();
  }
  return v12;
}

//----- (0047ABD0) --------------------------------------------------------  // acclient.c:184078
int __thiscall InterfacePtr<Interface>::_QueryInterface(InterfacePtr<Interface> *this, int a2, int a3)
{
  InterfacePtr<Interface> *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  Interface *v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  InterfacePtr<Interface> *v9; // [sp+4h] [bp-4h]@1

  v9 = this;
  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(int *, Turbine_GUID *, int *))(v4 + 12))(
                      &v9,
                      &Interface_InterfaceType_29,
                      &a3);
    v6 = v3->m_pInterface;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = (Interface *)v8;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = 0;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    InterfacePtr<Interface>::operator=(this, 0);
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (006A0230) --------------------------------------------------------  // acclient.c:696576
bool DBCache::IsLoader()
{
  return 0;
}

//----- (006EC630) --------------------------------------------------------  // acclient.c:768250
void _E91_37()
{
  outside_val_29 = 1000.0 + 1.0;
}

//----- (006EC650) --------------------------------------------------------  // acclient.c:768256
void _E93_13()
{
  block_length_29 = 24.0 * 8.0;
}

//----- (006EC670) --------------------------------------------------------  // acclient.c:768262
void _E95_13()
{
  half_square_length_29 = 24.0 * 0.5;
}

//----- (006EC690) --------------------------------------------------------  // acclient.c:768268
int _E97_38()
{
  return atexit(_E98_50);
}

//----- (006EC6A0) --------------------------------------------------------  // acclient.c:768274
int _E100_31()
{
  return atexit(_E101_68);
}

//----- (006EC6B0) --------------------------------------------------------  // acclient.c:768280
int _E103_23()
{
  return atexit(_E104_38);
}

//----- (006EC6C0) --------------------------------------------------------  // acclient.c:768286
int _E106_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_15, "Misc.TooltipEnable");
  return atexit(_E107_69);
}

//----- (006EC6E0) --------------------------------------------------------  // acclient.c:768293
int _E109_18()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_15, "Misc.TooltipDelay");
  return atexit(sub_75EF10);
}

//----- (006EC700) --------------------------------------------------------  // acclient.c:768300
void _E115_13()
{
  DEFAULT_VIEW_RADIUS_13 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EC720) --------------------------------------------------------  // acclient.c:768306
void _E117_12()
{
  MIN_QUANTUM_13 = 1.0 / 30.0;
}

//----- (006EC740) --------------------------------------------------------  // acclient.c:768312
void _E119_1()
{
  MAX_QUANTUM_13 = 1.0 / 5.0;
}

//----- (006EC760) --------------------------------------------------------  // acclient.c:768318
void _E121_21()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_48, PFID_A8R8G8B8);
}

//----- (006EC770) --------------------------------------------------------  // acclient.c:768324
int _E123_12()
{
  return atexit(nullsub_475);
}

//----- (006EC780) --------------------------------------------------------  // acclient.c:768330
int _E146_0()
{
  RGBAColor_RadarDefault = RGBAColor_RadarWhite;
  return LODWORD(RGBAColor_RadarWhite.a);
}

//----- (006EC7B0) --------------------------------------------------------  // acclient.c:768337
int _E148_13()
{
  RGBAColor_RadarAdmin = RGBAColor_RadarCyan;
  return LODWORD(RGBAColor_RadarCyan.a);
}

//----- (006EC7E0) --------------------------------------------------------  // acclient.c:768344
int _E150_13()
{
  RGBAColor_RadarAdvocate = RGBAColor_RadarPink;
  return LODWORD(RGBAColor_RadarPink.a);
}

//----- (006EC810) --------------------------------------------------------  // acclient.c:768351
int _E152_0()
{
  RGBAColor_RadarCreature = RGBAColor_RadarGold;
  return LODWORD(RGBAColor_RadarGold.a);
}

//----- (006EC840) --------------------------------------------------------  // acclient.c:768358
int _E154_14()
{
  RGBAColor_RadarLifeStone = RGBAColor_RadarBlue;
  return LODWORD(RGBAColor_RadarBlue.a);
}

//----- (006EC870) --------------------------------------------------------  // acclient.c:768365
int _E156_15()
{
  RGBAColor_RadarNPC = RGBAColor_RadarYellow;
  return LODWORD(RGBAColor_RadarYellow.a);
}

//----- (006EC8A0) --------------------------------------------------------  // acclient.c:768372
int _E158_1()
{
  RGBAColor_RadarPlayerKiller = RGBAColor_RadarRed;
  return LODWORD(RGBAColor_RadarRed.a);
}

//----- (006EC8D0) --------------------------------------------------------  // acclient.c:768379
int _E160_14()
{
  RGBAColor_RadarPortal = RGBAColor_RadarPurple;
  return LODWORD(RGBAColor_RadarPurple.a);
}

//----- (006EC900) --------------------------------------------------------  // acclient.c:768386
int _E162_15()
{
  RGBAColor_RadarSentinel = RGBAColor_RadarCyan;
  return LODWORD(RGBAColor_RadarCyan.a);
}

//----- (006EC930) --------------------------------------------------------  // acclient.c:768393
int _E164_1()
{
  RGBAColor_RadarVendor = RGBAColor_RadarYellow;
  return LODWORD(RGBAColor_RadarYellow.a);
}

//----- (006EC960) --------------------------------------------------------  // acclient.c:768400
int _E166_12()
{
  RGBAColor_RadarFellowship = RGBAColor_RadarBrightGreen;
  return LODWORD(RGBAColor_RadarBrightGreen.a);
}

//----- (006EC990) --------------------------------------------------------  // acclient.c:768407
int _E168_14()
{
  RGBAColor_RadarFellowshipLeader = RGBAColor_RadarBrightGreen;
  return LODWORD(RGBAColor_RadarBrightGreen.a);
}

//----- (006EC9C0) --------------------------------------------------------  // acclient.c:768414
int _E170()
{
  RGBAColor_RadarPKLite = RGBAColor_RadarPink;
  return LODWORD(RGBAColor_RadarPink.a);
}

//----- (006EC9F0) --------------------------------------------------------  // acclient.c:768421
void _E172_10()
{
  LOWEST_DATA_RATE_58 = 1024;
}

//----- (006ECA00) --------------------------------------------------------  // acclient.c:768427
void _E174_14()
{
  HIGHEST_DATA_RATE_58 = 0x7FFF;
}

//----- (006ECA10) --------------------------------------------------------  // acclient.c:768433
int _E176()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_58;
  INITIAL_MAX_DATA_RATE_6 = LOWEST_DATA_RATE_58;
  return result;
}

//----- (006ECA20) --------------------------------------------------------  // acclient.c:768443
int _E179()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_12, "Display.Resolution");
  return atexit(_E180_44);
}

//----- (006ECA40) --------------------------------------------------------  // acclient.c:768450
int _E182()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_12, "Display.FullScreen");
  return atexit(_E183_43);
}

//----- (006ECA60) --------------------------------------------------------  // acclient.c:768457
int _E185()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_12, "Display.RefreshRate");
  return atexit(_E186_43);
}

//----- (006ECA80) --------------------------------------------------------  // acclient.c:768464
int _E188()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_12, "Display.SyncToRefresh");
  return atexit(_E189_42);
}

//----- (006ECAA0) --------------------------------------------------------  // acclient.c:768471
int __thiscall _E191(unsigned int this)
{
  int v1; // eax@1
  int v2; // esi@1
  Interface *v3; // ST08_4@2
  InterfaceSystem *v4; // eax@2
  TResult result; // [sp+0h] [bp-4h]@1

  result.m_val = this;
  v1 = (int)operator new(0xCu);
  v2 = v1;
  if ( v1 )
  {
    v3 = (Interface *)v1;
    *(_DWORD *)v1 = &ClassFactoryForceUIFlow_ClassType::vftable;
    *(_DWORD *)(v1 + 8) = 1;
    *(_DWORD *)(v1 + 4) = &ReferenceCountTemplate<1048576,2>::vftable;
    v4 = InterfaceSystem::GetInstance();
    InterfaceSystem::RegisterClassA(v4, &result, &UIFlow_ClassType_1, v3, 0);
    v1 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
  }
  return v1;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79EB54: using guessed type __int32 (__stdcall *ClassFactoryForceUIFlow_ClassType::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006ECAF0) --------------------------------------------------------  // acclient.c:768498
int _E1_89()
{
  return atexit(_E2_89);
}

//----- (0075EEE0) --------------------------------------------------------  // acclient.c:887068
void __cdecl _E107_69()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EF10) --------------------------------------------------------  // acclient.c:887081
void __cdecl sub_75EF10()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EF40) --------------------------------------------------------  // acclient.c:887094
void __cdecl _E180_44()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EF70) --------------------------------------------------------  // acclient.c:887107
void __cdecl _E183_43()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EFA0) --------------------------------------------------------  // acclient.c:887120
void __cdecl _E186_43()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EFD0) --------------------------------------------------------  // acclient.c:887133
void __cdecl _E189_42()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

