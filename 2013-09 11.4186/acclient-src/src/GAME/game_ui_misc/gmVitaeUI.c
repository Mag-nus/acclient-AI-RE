/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmVitaeUI
   Object     : GAME\game_ui_misc\gmVitaeUI.obj
   Functions  : 26
   Addresses  : 004A7240 - 006F12C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A7240) --------------------------------------------------------  // acclient.c:222844
void __thiscall gmVitaeUI::PostInit(gmVitaeUI *this)
{
  gmVitaeUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pMainText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001C3u);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  v2->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v2,
    (unsigned int)((char *)&loc_4DD213 + 2),
    (NoticeHandler *)&v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    129,
    &v1->vfptr);
}

//----- (004A72A0) --------------------------------------------------------  // acclient.c:222865
void __thiscall gmVitaeUI::~gmVitaeUI(gmVitaeUI *this)
{
  UIElement_Field *v1; // esi@1
  NoticeHandler *v2; // edi@1
  char *v3; // ebx@1
  GlobalEventHandler *v4; // eax@1

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmVitaeUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmVitaeUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmVitaeUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v2);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    129,
    v3);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7AD20C: using guessed type void (__thiscall *gmVitaeUI::vftable[2])(gmVitaeUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7AD218: using guessed type bool (__thiscall *gmVitaeUI::vftable)(DBCache *this);
// 7AD4C0: using guessed type int (__thiscall *gmVitaeUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7300) --------------------------------------------------------  // acclient.c:222895
gmVitaeUI *__thiscall gmVitaeUI::DynamicCast(gmVitaeUI *this, unsigned int i_eType)
{
  gmVitaeUI *result; // eax@1

  result = this;
  if ( i_eType != 268435488 )
    result = (gmVitaeUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A7320) --------------------------------------------------------  // acclient.c:222906
signed int gmVitaeUI::GetUIElementType()
{
  return 268435488;
}

//----- (004A7330) --------------------------------------------------------  // acclient.c:222912
void __userpurge gmVitaeUI::gmVitaeUI(gmVitaeUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVitaeUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmVitaeUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmVitaeUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmVitaeUI::vftable;
  v4->m_pMainText = 0;
  LODWORD(v4->m_currentVitae) = 1065353216;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7AD20C: using guessed type void (__thiscall *gmVitaeUI::vftable[2])(gmVitaeUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7AD218: using guessed type bool (__thiscall *gmVitaeUI::vftable)(DBCache *this);
// 7AD4C0: using guessed type int (__thiscall *gmVitaeUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7390) --------------------------------------------------------  // acclient.c:222933
gmVitaeUI *__thiscall gmVitaeUI::vector_deleting_destructor(gmVitaeUI *this, unsigned int a2)
{
  gmVitaeUI *v2; // esi@1

  v2 = this;
  gmVitaeUI::~gmVitaeUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A73B0) --------------------------------------------------------  // acclient.c:222945
void __usercall gmVitaeUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVitaeUI *v3; // eax@1

  v3 = (gmVitaeUI *)operator new(0x608u);
  if ( v3 )
    gmVitaeUI::gmVitaeUI(v3, a1, _layout, _full_desc);
}

//----- (004A73E0) --------------------------------------------------------  // acclient.c:222955
void __cdecl gmVitaeUI::Register()
{
  UIElement::RegisterElementClass(0x10000020u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmVitaeUI::Create);
}

//----- (004A7400) --------------------------------------------------------  // acclient.c:222961
char __thiscall gmVitaeUI::Update(gmVitaeUI *this)
{
  gmVitaeUI *v1; // esi@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // ebx@2
  int v4; // ebp@4
  int v6; // ebx@10
  PStringBase<unsigned short> *v7; // eax@11
  Interface *v8; // esi@11
  StringInfo *v9; // ecx@14
  CBaseQualities *v10; // ebp@15
  int v11; // eax@17
  PStringBase<unsigned short> *v12; // eax@17
  Interface *v13; // edi@17
  int v14; // [sp-8h] [bp-274h]@2
  Interface *_rpInterface; // [sp+10h] [bp-25Ch]@2
  int level; // [sp+14h] [bp-258h]@15
  InterfacePtr<PlayerDesc> playerDesc; // [sp+18h] [bp-254h]@2
  int cpPool; // [sp+20h] [bp-24Ch]@15
  int cpLeft; // [sp+24h] [bp-248h]@2
  char v20; // [sp+28h] [bp-244h]@4
  StringInfo siSkillsText; // [sp+2Ch] [bp-240h]@20
  StringInfo siVitaeText; // [sp+BCh] [bp-1B0h]@17
  StringInfo siExperienceText; // [sp+14Ch] [bp-120h]@20
  StringInfo siFullText; // [sp+1DCh] [bp-90h]@11

  v1 = this;
  if ( !((*((_DWORD *)&this->0 + 41) >> 1) & 1) )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, (TResult *)&cpLeft, &PlayerDesc_ClassType_6, &_rpInterface);
  v3 = _rpInterface;
  v14 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v20, v14, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    return 0;
  }
  v6 = 100 - (unsigned __int64)(v1->m_currentVitae * 100.0 + 0.5);
  if ( v6 > 0 )
  {
    v10 = (CBaseQualities *)&playerDesc.m_pInterface->vfptr;
    cpPool = 0;
    CBaseQualities::InqInt((CBaseQualities *)&playerDesc.m_pInterface->vfptr, 0x81u, &cpPool, 0, 0);
    level = 0;
    if ( !CBaseQualities::InqInt(v10, 0x8Bu, &level, 0, 0) )
      CBaseQualities::InqInt(v10, 0x19u, &level, 0, 0);
    v11 = VitaeSystem::VitaeCPPoolThreshold(v1->m_currentVitae, level);
    cpLeft = v11 - cpPool;
    StringInfo::StringInfo(&siVitaeText);
    StringInfo::SetStringIDandTableEnum(&siVitaeText, ID_Vitae_Text_Vitae, 268435457);
    StringInfo::AddVariable_Int(&siVitaeText, ID_Percentage, v6);
    v12 = StringInfo::GetString(&siVitaeText, (PStringBase<unsigned short> *)&_rpInterface, 0);
    UIElement_Text::SetText(v1->m_pMainText, v12);
    v13 = _rpInterface - 5;
    if ( !InterlockedDecrement((volatile LONG *)&_rpInterface[-4]) && v13 )
      ((void (__thiscall *)(Interface *, signed int))v13->vfptr->IUnknown_QueryInterface)(v13, 1);
    StringInfo::StringInfo(&siSkillsText);
    StringInfo::SetStringIDandTableEnum(&siSkillsText, ID_Vitae_Text_Skills, 268435457);
    StringInfo::AddVariable_Int(&siSkillsText, ID_Percentage, v6);
    UIElement_Text::AppendStringInfo(v1->m_pMainText, &siSkillsText);
    StringInfo::StringInfo(&siExperienceText);
    StringInfo::SetStringIDandTableEnum(&siExperienceText, ID_Vitae_Text_Experience, 268435457);
    StringInfo::AddVariable_Int(&siExperienceText, ID_Experience_0, cpLeft);
    UIElement_Text::AppendStringInfo(v1->m_pMainText, &siExperienceText);
    StringInfo::~StringInfo(&siExperienceText);
    StringInfo::~StringInfo(&siSkillsText);
    v9 = &siVitaeText;
  }
  else
  {
    StringInfo::StringInfo(&siFullText);
    StringInfo::SetStringIDandTableEnum(&siFullText, ID_Vitae_Text_Full, 268435457);
    v7 = StringInfo::GetString(&siFullText, (PStringBase<unsigned short> *)&_rpInterface, 0);
    UIElement_Text::SetText(v1->m_pMainText, v7);
    v8 = _rpInterface - 5;
    if ( !InterlockedDecrement((volatile LONG *)&_rpInterface[-4]) )
    {
      if ( v8 )
        ((void (__thiscall *)(Interface *, signed int))v8->vfptr->IUnknown_QueryInterface)(v8, 1);
    }
    v9 = &siFullText;
  }
  StringInfo::~StringInfo(v9);
  ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
  return 1;
}

//----- (004A76D0) --------------------------------------------------------  // acclient.c:223060
int __thiscall gmVitaeUI::ListenToElementMessage(gmVitaeUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 24 && (gmVitaeUI *)i_rMsg->pElement == this && i_rMsg->dwParam1 )
    gmVitaeUI::Update(this);
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004A7700) --------------------------------------------------------  // acclient.c:223071
void __thiscall gmVitaeUI::RecvNotice_PlayerDescReceived(gmVitaeUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmVitaeUI *v3; // esi@1

  v3 = this;
  *(float *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] = CACQualities::GetVitaeValue(i_playerDesc);
  gmVitaeUI::Update((gmVitaeUI *)((char *)v3 - 1528));
}

//----- (004A7720) --------------------------------------------------------  // acclient.c:223081
void __thiscall gmVitaeUI::RecvNotice_VitaeChanged(gmVitaeUI *this)
{
  gmVitaeUI *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
  PlayerDesc *v5; // esi@5
  double v6; // st7@8
  int v7; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v10; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_6, &_rpInterface);
  v7 = (int)_rpInterface;
  v3 = _rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v10, v7, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v4 >= 0 )
    {
      v6 = CACQualities::GetVitaeValue((CACQualities *)&playerDesc.m_pInterface->vfptr);
      if ( ((unsigned int)v1[-1].m_children.m_ihlIntrusive.m_hash.vfptr >> 1) & 1
        || v6 >= *(float *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] )
      {
        *(float *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] = v6;
        gmVitaeUI::Update((gmVitaeUI *)((char *)v1 - 1528));
        v5->vfptr->Release((Interface *)v5);
      }
      else
      {
        *(float *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] = v6;
        CM_UI::SendNotice_SetPanelVisibility(0xFu, 1);
        v5->vfptr->Release((Interface *)v5);
      }
    }
    else
    {
      playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    }
  }
}

//----- (004A7800) --------------------------------------------------------  // acclient.c:223136
void __thiscall gmVitaeUI::OnQualityRemoved(gmVitaeUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmVitaeUI::Update((gmVitaeUI *)((char *)this - 1532));
}

//----- (006F1170) --------------------------------------------------------  // acclient.c:773287
void _E91_73()
{
  outside_val_65 = 1000.0 + 1.0;
}

//----- (006F1190) --------------------------------------------------------  // acclient.c:773293
void _E93_49()
{
  block_length_65 = 24.0 * 8.0;
}

//----- (006F11B0) --------------------------------------------------------  // acclient.c:773299
void _E95_49()
{
  half_square_length_65 = 24.0 * 0.5;
}

//----- (006F11D0) --------------------------------------------------------  // acclient.c:773305
int _E97_74()
{
  return atexit(_E98_86);
}

//----- (006F11E0) --------------------------------------------------------  // acclient.c:773311
int _E100_67()
{
  return atexit(nullsub_829);
}

//----- (006F11F0) --------------------------------------------------------  // acclient.c:773317
int _E103_59()
{
  return atexit(_E104_74);
}

//----- (006F1200) --------------------------------------------------------  // acclient.c:773323
unsigned int _E106_45()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Vitae_Text_Vitae");
  ID_Vitae_Text_Vitae = result;
  return result;
}

//----- (006F1220) --------------------------------------------------------  // acclient.c:773333
unsigned int _E108_32()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Vitae_Text_Skills");
  ID_Vitae_Text_Skills = result;
  return result;
}

//----- (006F1240) --------------------------------------------------------  // acclient.c:773343
unsigned int _E110_23()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Vitae_Text_Experience");
  ID_Vitae_Text_Experience = result;
  return result;
}

//----- (006F1260) --------------------------------------------------------  // acclient.c:773353
unsigned int _E112_40()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Vitae_Text_Full");
  ID_Vitae_Text_Full = result;
  return result;
}

//----- (006F1280) --------------------------------------------------------  // acclient.c:773363
unsigned int _E114_26()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PERCENT");
  ID_Percentage = result;
  return result;
}

//----- (006F12A0) --------------------------------------------------------  // acclient.c:773373
unsigned int _E116_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("EXPERIENCE");
  ID_Experience_0 = result;
  return result;
}

//----- (006F12C0) --------------------------------------------------------  // acclient.c:773383
int sub_6F12C0()
{
  return atexit(nullsub_827);
}

