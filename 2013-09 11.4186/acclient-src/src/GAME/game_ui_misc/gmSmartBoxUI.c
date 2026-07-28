/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSmartBoxUI
   Object     : GAME\game_ui_misc\gmSmartBoxUI.obj
   Functions  : 123
   Addresses  : 004D60C0 - 00762640 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D60C0) --------------------------------------------------------  // acclient.c:261688
void __userpurge gmSmartBoxUI::gmSmartBoxUI(gmSmartBoxUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSmartBoxUI *v4; // esi@1

  v4 = this;
  UIElement_SmartBoxWrapper::UIElement_SmartBoxWrapper(
    (UIElement_SmartBoxWrapper *)&this->vfptr,
    a2,
    _layout,
    _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSmartBoxUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSmartBoxUI::vftable;
  v4->m_pSmartBox = 0;
  v4->teleportObj = 0;
  LODWORD(v4->gameVDist) = 0;
  HIDWORD(v4->gameVDist) = 0;
  v4->teleportAnimState = 0;
  LODWORD(v4->teleportRotationStartTime) = 0;
  HIDWORD(v4->teleportRotationStartTime) = 0;
  LODWORD(v4->teleportRotationDuration) = 0;
  HIDWORD(v4->teleportRotationDuration) = 0;
  LODWORD(v4->teleportRotationStartAngle) = 0;
  HIDWORD(v4->teleportRotationStartAngle) = 0;
  LODWORD(v4->teleportRotationEndAngle) = 0;
  HIDWORD(v4->teleportRotationEndAngle) = 0;
  LODWORD(v4->teleportTransitionStartTime) = 0;
  HIDWORD(v4->teleportTransitionStartTime) = 0;
  LODWORD(v4->teleportRotationCurAngle) = 0;
  HIDWORD(v4->teleportRotationCurAngle) = 0;
  LODWORD(v4->teleportCurVDist) = 0;
  v4->m_pFPSDisplay = 0;
  v4->m_pPortalSpace = 0;
  VividTargetIndicator::VividTargetIndicator(&v4->m_vti);
  v4->m_eWindowID = 0;
  v4->m_pTopBorder = 0;
  v4->m_pLeftBorder = 0;
  v4->m_pBottomBorder = 0;
  v4->m_pRightBorder = 0;
  v4->m_pTopLeftCorner = 0;
  v4->m_pTopRightCorner = 0;
  v4->m_pBottomLeftCorner = 0;
  v4->m_pBottomRightCorner = 0;
}
// 7BD2A8: using guessed type bool (__thiscall *gmSmartBoxUI::vftable)(DBCache *this);
// 7BD550: using guessed type int (__thiscall *gmSmartBoxUI::vftable)(void *, char);

//----- (004D61B0) --------------------------------------------------------  // acclient.c:261735
gmSmartBoxUI *__thiscall gmSmartBoxUI::DynamicCast(gmSmartBoxUI *this, unsigned int i_eType)
{
  gmSmartBoxUI *result; // eax@1

  result = this;
  if ( i_eType != 268435476 && i_eType != 268435504 )
    result = (gmSmartBoxUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D61E0) --------------------------------------------------------  // acclient.c:261746
signed int gmSmartBoxUI::GetUIElementType()
{
  return 268435476;
}

//----- (004D61F0) --------------------------------------------------------  // acclient.c:261752
void __thiscall gmSmartBoxUI::~gmSmartBoxUI(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // esi@1
  TeleportAnimState v2; // eax@1
  char *v3; // ebx@1
  UIElement_Viewport *v4; // eax@3
  CPhysicsObj *v5; // ecx@5
  SmartBox *v6; // ecx@7
  GlobalEventHandler *v7; // eax@7

  v1 = this;
  v2 = this->teleportAnimState;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSmartBoxUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSmartBoxUI::vftable;
  if ( v2 )
    this->teleportAnimState = 0;
  v4 = this->m_pPortalSpace;
  if ( v4 )
    CreatureMode::RemoveAllObjects((CreatureMode *)&v4->creature_mode_objects);
  v5 = v1->teleportObj;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v6 = v1->m_pSmartBox;
  v1->teleportObj = 0;
  SmartBox::Reset(v6, 1);
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v7 )
    v7->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v7, (NoticeHandler *)v3);
  VividTargetIndicator::~VividTargetIndicator(&v1->m_vti);
  UIElement_SmartBoxWrapper::~UIElement_SmartBoxWrapper((UIElement_SmartBoxWrapper *)&v1->vfptr);
}
// 7BD2A8: using guessed type bool (__thiscall *gmSmartBoxUI::vftable)(DBCache *this);
// 7BD550: using guessed type int (__thiscall *gmSmartBoxUI::vftable)(void *, char);

//----- (004D6280) --------------------------------------------------------  // acclient.c:261788
void __usercall gmSmartBoxUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSmartBoxUI *v3; // eax@1

  v3 = (gmSmartBoxUI *)operator new(0x708u);
  if ( v3 )
    gmSmartBoxUI::gmSmartBoxUI(v3, a1, _layout, _full_desc);
}

//----- (004D62C0) --------------------------------------------------------  // acclient.c:261798
void __thiscall gmSmartBoxUI::RecvNotice_UpdateGameView(gmSmartBoxUI *this, unsigned int i_cxScreen, unsigned int i_cyScreen, unsigned int i_cxWidth, unsigned int i_cyHeight)
{
  RenderDevice *v5; // edi@1
  RenderDeviceVtbl *v6; // ebx@1
  UIRegion *v7; // esi@1
  int v8; // ST0C_4@1
  int v9; // ST08_4@1
  unsigned int v10; // ST04_4@1
  unsigned int v11; // eax@1

  v5 = RenderDevice::render_device;
  v6 = RenderDevice::render_device->vfptr;
  v7 = (UIRegion *)&this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22];
  v8 = UIRegion::GetHeight((UIRegion *)&this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22]);
  v9 = UIRegion::GetWidth(v7);
  v10 = UIRegion::GetScreenY0(v7);
  v11 = UIRegion::GetScreenX0(v7);
  v6->SetViewport(v5, v11, v10, v9, v8, 0);
}

//----- (004D6300) --------------------------------------------------------  // acclient.c:261819
void __thiscall gmSmartBoxUI::BeginTeleportAnimation(gmSmartBoxUI *this, TeleportAnimState _animState)
{
  gmSmartBoxUI *v2; // esi@1
  unsigned int v3; // edx@3
  ClientUISystem *v4; // eax@3
  CSoundTable *v5; // eax@3

  v2 = this;
  if ( this->teleportAnimState == TAS_OFF )
    this->gameVDist = SmartBox::GetOverrideFovDistance(this->m_pSmartBox);
  v2->teleportCurVDist = v2->gameVDist;
  LODWORD(v2->teleportRotationStartTime) = 0;
  HIDWORD(v2->teleportRotationStartTime) = 0;
  LODWORD(v2->teleportRotationDuration) = 0;
  HIDWORD(v2->teleportRotationDuration) = 0;
  LODWORD(v2->teleportRotationStartAngle) = 0;
  HIDWORD(v2->teleportRotationStartAngle) = 0;
  LODWORD(v2->teleportRotationEndAngle) = 0;
  HIDWORD(v2->teleportRotationEndAngle) = 0;
  v2->teleportAnimState = _animState;
  v3 = Timer::cur_time.Param;
  LODWORD(v2->teleportTransitionStartTime) = Timer::cur_time.Cmd;
  HIDWORD(v2->teleportTransitionStartTime) = v3;
  v4 = ClientUISystem::GetUISystem();
  v5 = ClientUISystem::GetUISoundTable(v4);
  SoundManager::PlaySoundFromCenter(Sound_UI_EnterPortal, v5);
}

//----- (004D63A0) --------------------------------------------------------  // acclient.c:261848
void __thiscall gmSmartBoxUI::UpdateFPSMeter(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // esi@1
  double v2; // st7@1
  long double v3; // st7@2
  StringInfo _info; // [sp+10h] [bp-90h]@1

  v1 = this;
  StringInfo::StringInfo(&_info);
  StringInfo::SetStringIDandTableEnum(&_info, ID_SmartBox_FPS, 268435457);
  v2 = Render::GetFramerate();
  StringInfo::AddVariable_Float(&_info, fps_var, v2, 2u);
  if ( Render::auto_update_deg_mul )
    v3 = Render::deg_mul;
  else
    v3 = Render::s_rUserSuppliedDegradeBias;
  StringInfo::AddVariable_Float(&_info, deg_var, v3, 2u);
  UIElement_Text::SetStringInfo(v1->m_pFPSDisplay, &_info);
  StringInfo::~StringInfo(&_info);
}
// 81EC68: using guessed type bool Render::auto_update_deg_mul;
// 866308: using guessed type float Render::s_rUserSuppliedDegradeBias;
// 86630C: using guessed type float Render::deg_mul;

//----- (004D6440) --------------------------------------------------------  // acclient.c:261873
void __thiscall gmSmartBoxUI::UpdateLockedStatus(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // esi@1
  CPlayerSystem *v2; // eax@2

  v1 = this;
  if ( CPlayerSystem::GetPlayerSystem()
    && (v2 = CPlayerSystem::GetPlayerSystem(),
        (unsigned __int8)PlayerModule::LockUI((PlayerModule *)&v2->playerModule.vfptr)) )
  {
    ((void (__stdcall *)(_DWORD))v1->m_pTopBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pLeftBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pRightBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopLeftCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopRightCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomLeftCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomRightCorner->vfptr[2].__vecDelDtor)(0);
  }
  else
  {
    ((void (__stdcall *)(signed int))v1->m_pTopBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pLeftBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pRightBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopLeftCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopRightCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomLeftCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomRightCorner->vfptr[2].__vecDelDtor)(1);
  }
}

//----- (004D6560) --------------------------------------------------------  // acclient.c:261912
gmSmartBoxUI *__thiscall gmSmartBoxUI::scalar_deleting_destructor(gmSmartBoxUI *this, unsigned int a2)
{
  gmSmartBoxUI *v2; // esi@1

  v2 = this;
  gmSmartBoxUI::~gmSmartBoxUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D6580) --------------------------------------------------------  // acclient.c:261924
void __cdecl gmSmartBoxUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000014u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSmartBoxUI::Create);
}

//----- (004D65A0) --------------------------------------------------------  // acclient.c:261932
void __thiscall gmSmartBoxUI::EndTeleportAnimation(gmSmartBoxUI *this)
{
  unsigned int v1; // edx@2

  if ( this->teleportAnimState )
  {
    this->teleportAnimState = 4;
    v1 = Timer::cur_time.Param;
    LODWORD(this->teleportTransitionStartTime) = Timer::cur_time.Cmd;
    HIDWORD(this->teleportTransitionStartTime) = v1;
    SmartBox::SetOverrideFovDistance(this->m_pSmartBox, 0, 0.0);
  }
}

//----- (004D65E0) --------------------------------------------------------  // acclient.c:261947
void __thiscall gmSmartBoxUI::RecvNotice_SetFramerateDisplay(gmSmartBoxUI *this, bool i_fShow)
{
  gmSmartBoxUI *v2; // esi@1
  UIElement *v3; // eax@2
  int v4; // eax@3
  int v5; // ecx@7

  v2 = this;
  if ( i_fShow )
  {
    v3 = UIElement::GetChildRecursive(
           (UIElement *)&this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22],
           0x10000047u);
    if ( v3 )
      v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
    else
      v4 = 0;
    v2->m_box.m_x0 = v4;
    if ( v4 )
    {
      gmSmartBoxUI::UpdateFPSMeter((gmSmartBoxUI *)((char *)v2 - 1528));
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v2->m_box.m_x0 + 24))(1);
    }
  }
  else
  {
    v5 = this->m_box.m_x0;
    if ( v5 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 24))(0);
      v2->m_box.m_x0 = 0;
    }
  }
}

//----- (004D6650) --------------------------------------------------------  // acclient.c:261983
void __thiscall gmSmartBoxUI::ResizeTo(gmSmartBoxUI *this, const int i_width, const int i_height)
{
  const int v3; // edi@1
  gmSmartBoxUI *v4; // esi@1
  unsigned __int64 v5; // rax@1
  char *v6; // edi@5
  int v7; // ebx@5
  PlayerModule *v8; // edi@7
  int v9; // ebx@7
  BasePropertyDesc *v10; // ecx@10
  unsigned int v11; // edx@10
  BasePropertyValue *v12; // ecx@14
  unsigned int v13; // edx@14
  BasePropertyDesc *v14; // ecx@18
  unsigned int v15; // edx@18
  BasePropertyValue *v16; // ecx@22
  unsigned int v17; // edx@22
  BaseProperty propH; // [sp+Ch] [bp-10h]@7
  BaseProperty propW; // [sp+14h] [bp-8h]@5

  v3 = i_width;
  v4 = this;
  v5 = (unsigned __int64)((double)i_height * 0.8);
  if ( i_width < (signed int)v5 )
    v3 = (unsigned __int64)((double)i_height * 0.8);
  UIElement_SmartBoxWrapper::ResizeTo((UIElement_SmartBoxWrapper *)&this->vfptr, v3, v3, i_height);
  if ( v4->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v6 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propW, 0x10000088u);
    v7 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    if ( propW.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propW);
      ((void (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v7);
    }
    v8 = (PlayerModule *)(v6 + 4);
    PlayerModule::SetChatWindowOption(v8, v4->m_eWindowID, &propW);
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propH, 0x10000089u);
    v9 = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    if ( propH.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propH);
      ((void (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v9);
    }
    PlayerModule::SetChatWindowOption(v8, v4->m_eWindowID, &propH);
    if ( (_DWORD)propH.m_pcPropertyDesc )
    {
      v10 = propH.m_pcPropertyDesc;
      v11 = propH.m_pcPropertyDesc->m_cRef - 1;
      propH.m_pcPropertyDesc->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyDesc = 0;
    }
    if ( propH.m_pcPropertyValue )
    {
      v12 = propH.m_pcPropertyValue;
      v13 = propH.m_pcPropertyValue->m_cRef - 1;
      propH.m_pcPropertyValue->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propW.m_pcPropertyDesc )
    {
      v14 = propW.m_pcPropertyDesc;
      v15 = propW.m_pcPropertyDesc->m_cRef - 1;
      propW.m_pcPropertyDesc->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
      propW.m_pcPropertyDesc = 0;
    }
    if ( propW.m_pcPropertyValue )
    {
      v16 = propW.m_pcPropertyValue;
      v17 = propW.m_pcPropertyValue->m_cRef - 1;
      propW.m_pcPropertyValue->m_cRef = v17;
      if ( !v17 )
        ((void (__stdcall *)(_DWORD))v16->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004D67E0) --------------------------------------------------------  // acclient.c:262072
void __thiscall gmSmartBoxUI::MoveTo(gmSmartBoxUI *this, const int i_x, const int i_y)
{
  int v3; // ebx@1
  gmSmartBoxUI *v4; // esi@1
  int v5; // edi@1
  UIRegion *v6; // eax@2
  int v7; // ebp@2
  UIRegion *v8; // eax@3
  int v9; // ebx@3
  UIRegion *v10; // eax@6
  int v11; // ebp@6
  UIRegion *v12; // eax@7
  int v13; // edi@7
  char *v14; // edi@12
  int v15; // ebx@12
  PlayerModule *v16; // edi@14
  int v17; // ebx@14
  BasePropertyDesc *v18; // ecx@17
  unsigned int v19; // edx@17
  BasePropertyValue *v20; // ecx@21
  unsigned int v21; // edx@21
  BasePropertyDesc *v22; // ecx@25
  unsigned int v23; // edx@25
  BasePropertyValue *v24; // ecx@29
  unsigned int v25; // edx@29
  BaseProperty propY; // [sp+10h] [bp-10h]@14
  BaseProperty propX; // [sp+18h] [bp-8h]@12

  v3 = i_x;
  v4 = this;
  v5 = i_y;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v6 = (UIRegion *)((int (__thiscall *)(gmSmartBoxUI *))v4->vfptr[13].OnAction)(v4);
    v7 = UIRegion::GetWidth(v6);
    if ( i_x > v7 - UIRegion::GetWidth((UIRegion *)&v4->vfptr) )
    {
      v8 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v9 = UIRegion::GetWidth(v8);
      v3 = v9 - UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    }
    if ( v3 < 0 )
      v3 = 0;
    v10 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
    v11 = UIRegion::GetHeight(v10);
    if ( i_y > v11 - UIRegion::GetHeight((UIRegion *)&v4->vfptr) )
    {
      v12 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v13 = UIRegion::GetHeight(v12);
      v5 = v13 - UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    }
    if ( v5 < 0 )
      v5 = 0;
  }
  UIElement_SmartBoxWrapper::MoveTo((UIElement_SmartBoxWrapper *)&v4->vfptr, v3, v5);
  if ( v4->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v14 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propX, 0x10000086u);
    v15 = v4->m_box.m_x0;
    if ( propX.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propX);
      ((void (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v15);
    }
    v16 = (PlayerModule *)(v14 + 4);
    PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propX);
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propY, 0x10000087u);
    v17 = v4->m_box.m_y0;
    if ( propY.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propY);
      ((void (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v17);
    }
    PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propY);
    if ( (_DWORD)propY.m_pcPropertyDesc )
    {
      v18 = propY.m_pcPropertyDesc;
      v19 = propY.m_pcPropertyDesc->m_cRef - 1;
      propY.m_pcPropertyDesc->m_cRef = v19;
      if ( !v19 )
        ((void (__stdcall *)(_DWORD))v18->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyDesc = 0;
    }
    if ( propY.m_pcPropertyValue )
    {
      v20 = propY.m_pcPropertyValue;
      v21 = propY.m_pcPropertyValue->m_cRef - 1;
      propY.m_pcPropertyValue->m_cRef = v21;
      if ( !v21 )
        ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propX.m_pcPropertyDesc )
    {
      v22 = propX.m_pcPropertyDesc;
      v23 = propX.m_pcPropertyDesc->m_cRef - 1;
      propX.m_pcPropertyDesc->m_cRef = v23;
      if ( !v23 )
        ((void (__stdcall *)(_DWORD))v22->vfptr->__vecDelDtor)(1);
      propX.m_pcPropertyDesc = 0;
    }
    if ( propX.m_pcPropertyValue )
    {
      v24 = propX.m_pcPropertyValue;
      v25 = propX.m_pcPropertyValue->m_cRef - 1;
      propX.m_pcPropertyValue->m_cRef = v25;
      if ( !v25 )
        ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004D69E0) --------------------------------------------------------  // acclient.c:262190
void __thiscall gmSmartBoxUI::UpdateFromPlayerModule(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // edi@1
  char *v2; // esi@1
  PlayerModule *v3; // esi@4
  unsigned int v4; // ST00_4@4
  unsigned int v5; // ST00_4@11
  int x; // [sp+18h] [bp-28h]@9
  int y; // [sp+1Ch] [bp-24h]@7
  BaseProperty propY; // [sp+20h] [bp-20h]@11
  BaseProperty propX; // [sp+28h] [bp-18h]@11
  BaseProperty propH; // [sp+30h] [bp-10h]@4
  BaseProperty propW; // [sp+38h] [bp-8h]@4

  v1 = this;
  v2 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
  if ( !CPlayerSystem::GetPlayerSystem()->m_layoutFromFile && v1->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v3 = (PlayerModule *)(v2 + 4);
    v4 = v1->m_eWindowID;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    if ( PlayerModule::InqChatWindowOption(v3, v4, 0x10000088u, &propW)
      && PlayerModule::InqChatWindowOption(v3, v1->m_eWindowID, 0x10000089u, &propH)
      && propW.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&y)
      && propH.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&x) )
      ((void (__thiscall *)(gmSmartBoxUI *, int, int))v1->vfptr[4].__vecDelDtor)(v1, y, x);
    v5 = v1->m_eWindowID;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    if ( PlayerModule::InqChatWindowOption(v3, v5, 0x10000086u, &propX)
      && PlayerModule::InqChatWindowOption(v3, v1->m_eWindowID, 0x10000087u, &propY)
      && propX.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&x)
      && propY.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&y) )
      ((void (__thiscall *)(gmSmartBoxUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, x, y);
    BaseProperty::~BaseProperty(&propY);
    BaseProperty::~BaseProperty(&propX);
    BaseProperty::~BaseProperty(&propH);
    BaseProperty::~BaseProperty(&propW);
  }
  gmSmartBoxUI::UpdateLockedStatus(v1);
}

//----- (004D6B60) --------------------------------------------------------  // acclient.c:262242
void __thiscall gmSmartBoxUI::PostInit(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  UIElement *v12; // eax@16
  int v13; // eax@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  UIElement *v16; // eax@22
  int v17; // eax@23
  SmartBox *v18; // ST14_4@25
  ClientUISystem *v19; // eax@25
  UIElement *v20; // eax@25
  int v21; // eax@26
  CreatureMode *v22; // ecx@29
  CreatureMode *v23; // ecx@29
  GlobalEventHandler *v24; // eax@30
  GlobalEventHandler *v25; // edi@30
  IDClass<_tagDataID,32,0> bgDID; // [sp+8h] [bp-10h]@25
  AC1Legacy::Vector3 i_direction; // [sp+Ch] [bp-Ch]@29

  v1 = this;
  UIElement_SmartBoxWrapper::PostInit((UIElement_SmartBoxWrapper *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CBu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)9);
  else
    v3 = 0;
  v1->m_pTopBorder = (UIElement *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CDu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)9);
  else
    v5 = 0;
  v1->m_pLeftBorder = (UIElement *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CFu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)9);
  else
    v7 = 0;
  v1->m_pBottomBorder = (UIElement *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D1u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)9);
  else
    v9 = 0;
  v1->m_pRightBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CAu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CCu);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)9);
  else
    v13 = 0;
  v1->m_pTopRightCorner = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006CEu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D0u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v17;
  v18 = SmartBox::smartbox;
  v1->m_pSmartBox = SmartBox::smartbox;
  v19 = ClientUISystem::GetUISystem();
  ClientUISystem::InitializeCameraSet(v19, v18);
  DBObj::GetDIDByEnum(&bgDID, 268435457, 7);
  v1->teleportObj = CPhysicsObj::makeObject(bgDID, 0, 1);
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000436u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)13);
  else
    v21 = 0;
  v1->m_pPortalSpace = (UIElement_Viewport *)v21;
  if ( v21 )
  {
    CreatureMode::AddObject((CreatureMode *)(v21 + 1520), v1->teleportObj);
    CreatureMode::AddLight((CreatureMode *)&v1->m_pPortalSpace->creature_mode_objects, DISTANT_LIGHT, 2.0);
    v22 = (CreatureMode *)&v1->m_pPortalSpace->creature_mode_objects;
    LODWORD(i_direction.x) = 1050253722;
    LODWORD(i_direction.y) = -1074580685;
    LODWORD(i_direction.z) = 1059481190;
    CreatureMode::SetLightDirection(v22, 0, &i_direction);
    v23 = (CreatureMode *)&v1->m_pPortalSpace->creature_mode_objects;
    LODWORD(i_direction.x) = 1047904911;
    LODWORD(i_direction.y) = -1070805811;
    LODWORD(i_direction.z) = 1063339950;
    CreatureMode::SetCameraPosition(v23, &i_direction);
    CreatureMode::UseSmartboxFOV((CreatureMode *)&v1->m_pPortalSpace->creature_mode_objects);
  }
  v24 = GlobalEventHandler::GetGlobalEventHandler();
  v25 = v24;
  if ( v24 )
  {
    v24->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v24, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
    v25->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v25, 100013u, (NoticeHandler *)&v1->vfptr);
    v25->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v25, (unsigned int)&loc_4DD1FF, (NoticeHandler *)&v1->vfptr);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  VividTargetIndicator::Initialized(&v1->m_vti, v1);
  v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 1u);
  RenderUI::RecalculateClampedPosition();
}

//----- (004D6E30) --------------------------------------------------------  // acclient.c:262367
void __thiscall gmSmartBoxUI::UseTime(gmSmartBoxUI *this)
{
  gmSmartBoxUI *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  CPlayerSystem *v3; // ebp@1
  bool v4; // bl@5
  TeleportAnimState v5; // eax@10
  TeleportAnimState v6; // eax@14
  CreatureMode *v7; // ecx@19
  int v8; // edx@21
  int v9; // eax@21
  int v10; // ecx@21
  int v11; // eax@21
  int v12; // edi@21
  float i_fPercentage; // ST1C_4@25
  UIElement_Viewport *v14; // ecx@26
  TeleportAnimState v15; // eax@27
  AC1Legacy::Vector3 *v16; // eax@29
  float v17; // ST1C_4@31
  SmartBox *v18; // ecx@31
  float v19; // ST1C_4@31
  TeleportAnimState v20; // eax@32
  AC1Legacy::Vector3 *v21; // eax@34
  float v22; // ST1C_4@36
  float v23; // ST1C_4@36
  double v24; // kr00_8@42
  double v25; // kr08_8@45
  double v26; // kr10_8@48
  ClientUISystem *v27; // eax@51
  CSoundTable *v28; // eax@51
  double v29; // kr18_8@51
  SmartBox *v30; // ecx@54
  ClientUISystem *v31; // eax@57
  CameraSet *v32; // eax@57
  double anim_time_left_in_cycle; // [sp+18h] [bp-B0h]@19
  double v34; // [sp+20h] [bp-A8h]@1
  AC1Legacy::Vector3 i_position; // [sp+28h] [bp-A0h]@19
  StringInfo siError; // [sp+38h] [bp-90h]@21

  v1 = this;
  v34 = *(double *)&Timer::cur_time;
  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = v2;
  if ( v2 )
  {
    if ( v2->logOffRequested && v2->logOffRequestTime < v34 )
    {
      gmSmartBoxUI::BeginTeleportAnimation(v1, TAS_WORLD_FADE_OUT);
      CPlayerSystem::SetTeleportInProgress(v3, 1);
      CPlayerSystem::SetLogOffStarted(v3);
    }
    v4 = v3->teleportInProgress;
    if ( (unsigned __int8)SmartBox::teleport_in_progress(v1->m_pSmartBox) != v4 )
    {
      if ( (unsigned __int8)SmartBox::teleport_in_progress(v1->m_pSmartBox) )
      {
        CPlayerSystem::SetTeleportInProgress(v3, 1);
        gmSmartBoxUI::BeginTeleportAnimation(v1, TAS_TUNNEL);
      }
      else if ( v1->teleportAnimState == 3 )
      {
        gmSmartBoxUI::EndTeleportAnimation(v1);
      }
    }
    v5 = v1->teleportAnimState;
    if ( v5 )
    {
      if ( v5 == 1 || v5 == 6 )
        VividTargetIndicator::SetEnabled(&v1->m_vti, 1);
      v6 = v1->teleportAnimState;
      if ( v6 == 2 || v6 == 3 || v6 == 4 || v6 == 5 )
      {
        if ( !UIElement::IsVisible((UIElement *)&v1->m_pPortalSpace->vfptr) )
        {
          VividTargetIndicator::SetEnabled(&v1->m_vti, 0);
          DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&anim_time_left_in_cycle, 268435458, 7);
          CPhysicsObj::set_sequence_animation(v1->teleportObj, LODWORD(anim_time_left_in_cycle), 1, 1u, 40.0);
          v7 = (CreatureMode *)&v1->m_pPortalSpace->creature_mode_objects;
          LODWORD(i_position.x) = 1047904911;
          LODWORD(i_position.y) = -1070805811;
          LODWORD(i_position.z) = 1063339950;
          CreatureMode::SetCameraPosition(v7, &i_position);
          ((void (__stdcall *)(signed int))v1->m_pPortalSpace->vfptr[2].__vecDelDtor)(1);
          SmartBox::Hide(v1->m_pSmartBox);
        }
        if ( v1->teleportRotationDuration + v1->teleportRotationStartTime > v34 )
        {
          i_fPercentage = (v34 - v1->teleportRotationStartTime) / v1->teleportRotationDuration;
          LODWORD(anim_time_left_in_cycle) = UIGlobals::GetAnimLevel(i_fPercentage);
          v1->teleportRotationCurAngle = (v1->teleportRotationEndAngle - v1->teleportRotationStartAngle)
                                       * ((double)SLODWORD(anim_time_left_in_cycle)
                                        * 0.0009765625)
                                       + v1->teleportRotationStartAngle;
        }
        else
        {
          v8 = HIDWORD(v1->teleportRotationEndAngle);
          v9 = LODWORD(v34);
          LODWORD(v1->teleportRotationCurAngle) = LODWORD(v1->teleportRotationEndAngle);
          v10 = HIDWORD(v34);
          HIDWORD(v1->teleportRotationCurAngle) = v8;
          LODWORD(v1->teleportRotationStartTime) = v9;
          HIDWORD(v1->teleportRotationStartTime) = v10;
          v1->teleportRotationDuration = RandDouble(0.6, 1.8);
          v11 = HIDWORD(v1->teleportRotationCurAngle);
          LODWORD(v1->teleportRotationStartAngle) = LODWORD(v1->teleportRotationCurAngle);
          HIDWORD(v1->teleportRotationStartAngle) = v11;
          v1->teleportRotationEndAngle = RandDouble(0.0, 360.0);
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&anim_time_left_in_cycle,
            L"In Portal Space - Please Wait...");
          StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&anim_time_left_in_cycle, 1);
          v12 = LODWORD(anim_time_left_in_cycle) - 20;
          if ( !InterlockedDecrement((volatile LONG *)(LODWORD(anim_time_left_in_cycle) - 20 + 4)) && v12 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          StringInfo::~StringInfo(&siError);
        }
        v14 = v1->m_pPortalSpace;
        i_position.y = v1->teleportRotationCurAngle;
        LODWORD(i_position.x) = 0;
        LODWORD(i_position.z) = 0;
        CreatureMode::SetCameraDirection_Degrees((CreatureMode *)&v14->creature_mode_objects, &i_position);
      }
      v15 = v1->teleportAnimState;
      if ( v15 == 1 || v15 == 5 )
      {
        anim_time_left_in_cycle = 1.0;
        *(double *)&i_position.x = (v34 - v1->teleportTransitionStartTime) / 1.0;
        v16 = &i_position;
        if ( *(double *)&i_position.x >= 1.0 )
          v16 = (AC1Legacy::Vector3 *)&anim_time_left_in_cycle;
        v17 = *(double *)&v16->x;
        LODWORD(anim_time_left_in_cycle) = UIGlobals::GetAnimLevel(v17);
        v18 = v1->m_pSmartBox;
        *(float *)&anim_time_left_in_cycle = (double)SLODWORD(anim_time_left_in_cycle)
                                           * 0.0009765625
                                           * (0.001 - v1->gameVDist)
                                           + v1->gameVDist;
        v19 = anim_time_left_in_cycle;
        v1->teleportCurVDist = anim_time_left_in_cycle;
        SmartBox::SetOverrideFovDistance(v18, 1, v19);
      }
      v20 = v1->teleportAnimState;
      if ( v20 == 2 || v20 == 6 )
      {
        anim_time_left_in_cycle = 1.0;
        *(double *)&i_position.x = (v34 - v1->teleportTransitionStartTime) / 1.0;
        v21 = &i_position;
        if ( *(double *)&i_position.x >= 1.0 )
          v21 = (AC1Legacy::Vector3 *)&anim_time_left_in_cycle;
        v22 = *(double *)&v21->x;
        LODWORD(anim_time_left_in_cycle) = UIGlobals::GetAnimLevel(v22);
        *(float *)&anim_time_left_in_cycle = (double)SLODWORD(anim_time_left_in_cycle)
                                           * 0.0009765625
                                           * (v1->gameVDist - 0.001)
                                           + 0.001;
        v23 = anim_time_left_in_cycle;
        v1->teleportCurVDist = anim_time_left_in_cycle;
        SmartBox::SetOverrideFovDistance(v1->m_pSmartBox, 1, v23);
      }
      if ( v1->teleportAnimState == 4 && v34 - v1->teleportTransitionStartTime >= 2.0 )
      {
        *(float *)&anim_time_left_in_cycle = (double)(120 - CPhysicsObj::get_curr_frame_number(v1->teleportObj)) / 40.0;
        if ( v34 - v1->teleportTransitionStartTime >= 5.0
          || 1.0 + 0.1000000014901161 < (float)anim_time_left_in_cycle
          && 1.0 + 0.300000011920929 > (float)anim_time_left_in_cycle )
        {
          v24 = v34;
          v1->teleportAnimState = 5;
          v1->teleportTransitionStartTime = v24;
        }
      }
      if ( v1->teleportAnimState == 1 && v34 - v1->teleportTransitionStartTime >= 1.0 )
      {
        v25 = v34;
        v1->teleportAnimState = 2;
        v1->teleportTransitionStartTime = v25;
      }
      if ( v1->teleportAnimState == 2 && v34 - v1->teleportTransitionStartTime >= 1.0 )
      {
        v26 = v34;
        v1->teleportAnimState = 3;
        v1->teleportTransitionStartTime = v26;
      }
      if ( v1->teleportAnimState == 5 && v34 - v1->teleportTransitionStartTime >= 1.0 )
      {
        SmartBox::SetOverrideFovDistance(v1->m_pSmartBox, 1, v1->teleportCurVDist);
        ((void (__stdcall *)(_DWORD))v1->m_pPortalSpace->vfptr[2].__vecDelDtor)(0);
        SmartBox::Show(v1->m_pSmartBox);
        CPhysicsObj::clear_sequence_anims(v1->teleportObj);
        v27 = ClientUISystem::GetUISystem();
        v28 = ClientUISystem::GetUISoundTable(v27);
        SoundManager::PlaySoundFromCenter(Sound_UI_ExitPortal, v28);
        v29 = v34;
        v1->teleportAnimState = 6;
        v1->teleportTransitionStartTime = v29;
      }
      if ( v1->teleportAnimState == 6 && v34 - v1->teleportTransitionStartTime >= 1.0 )
      {
        v1->teleportTransitionStartTime = v34 - 1.0;
        CPlayerSystem::SendLoginCompleteNotification(v3);
        CPlayerSystem::SetTeleportInProgress(v3, 0);
        v30 = v1->m_pSmartBox;
        v1->teleportAnimState = 0;
        SmartBox::SetOverrideFovDistance(v30, 0, 0.0);
        SmartBox::teleport_occured(v1->m_pSmartBox);
      }
    }
    else if ( SmartBox::teleport_occured(v1->m_pSmartBox) )
    {
      CPlayerSystem::SendLoginCompleteNotification(v3);
    }
  }
  v31 = ClientUISystem::GetUISystem();
  v32 = ClientUISystem::AccessCameraSet(v31);
  if ( v32 )
    CameraSet::UpdateCamera(v32);
  if ( v1->m_pFPSDisplay )
    gmSmartBoxUI::UpdateFPSMeter(v1);
}

//----- (004D74E0) --------------------------------------------------------  // acclient.c:262591
void __thiscall gmSmartBoxUI::ListenToGlobalMessage(gmSmartBoxUI *this, unsigned int i_messageID, int i_data_int)
{
  UIElement_SmartBoxWrapper *v3; // esi@1

  v3 = (UIElement_SmartBoxWrapper *)this;
  if ( i_messageID == 3 )
  {
    gmSmartBoxUI::UseTime(this);
  }
  else if ( i_messageID == 13 )
  {
    gmSmartBoxUI::UpdateLockedStatus(this);
    UIElement_SmartBoxWrapper::ListenToGlobalMessage(v3, 0xDu, i_data_int);
    return;
  }
  UIElement_SmartBoxWrapper::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (006F48B0) --------------------------------------------------------  // acclient.c:777178
void sub_6F48B0()
{
  flt_8400E0 = 1000.0 + 1.0;
}

//----- (006F48D0) --------------------------------------------------------  // acclient.c:777184
void _E93_84()
{
  flt_8400E4 = 24.0 * 8.0;
}

//----- (006F48F0) --------------------------------------------------------  // acclient.c:777190
void _E95_84()
{
  flt_8400E8 = 24.0 * 0.5;
}

//----- (006F4910) --------------------------------------------------------  // acclient.c:777196
int sub_6F4910()
{
  return atexit(nullsub_642);
}

//----- (006F4920) --------------------------------------------------------  // acclient.c:777202
int sub_6F4920()
{
  return atexit(nullsub_643);
}

//----- (006F4930) --------------------------------------------------------  // acclient.c:777208
int _E103_94()
{
  return atexit(nullsub_644);
}

//----- (006F4940) --------------------------------------------------------  // acclient.c:777214
void _E106_67()
{
  LOWEST_DATA_RATE_94 = 1024;
}

//----- (006F4950) --------------------------------------------------------  // acclient.c:777220
void _E108_53()
{
  HIGHEST_DATA_RATE_94 = 0x7FFF;
}

//----- (006F4960) --------------------------------------------------------  // acclient.c:777226
int _E110_44()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_94;
  INITIAL_MAX_DATA_RATE_42 = LOWEST_DATA_RATE_94;
  return result;
}

//----- (006F4970) --------------------------------------------------------  // acclient.c:777236
void _E112_60()
{
  DEFAULT_VIEW_RADIUS_68 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F4990) --------------------------------------------------------  // acclient.c:777242
void _E114_31()
{
  MIN_QUANTUM_68 = 1.0 / 30.0;
}

//----- (006F49B0) --------------------------------------------------------  // acclient.c:777248
void _E116_11()
{
  MAX_QUANTUM_68 = 1.0 / 5.0;
}

//----- (006F49D0) --------------------------------------------------------  // acclient.c:777254
void _E118_47()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840110, PFID_A8R8G8B8);
}

//----- (006F49E0) --------------------------------------------------------  // acclient.c:777260
int _E120_35()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_36, "Misc.TooltipEnable");
  return atexit(sub_761E20);
}

//----- (006F4A00) --------------------------------------------------------  // acclient.c:777267
int _E123_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_36, "Misc.TooltipDelay");
  return atexit(sub_761E50);
}

//----- (006F4A20) --------------------------------------------------------  // acclient.c:777274
int _E129_19()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_5, "Sound.SoundDisabled");
  return atexit(_E130_88);
}

//----- (006F4A40) --------------------------------------------------------  // acclient.c:777281
int _E132_19()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_5, "Sound.SoundVolume");
  return atexit(_E133_81);
}

//----- (006F4A60) --------------------------------------------------------  // acclient.c:777288
int _E135_19()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_5, "Sound.AmbientSoundDisabled");
  return atexit(_E136_65);
}

//----- (006F4A80) --------------------------------------------------------  // acclient.c:777295
int _E138_17()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_5, "Sound.AmbientSoundVolume");
  return atexit(_E139_66);
}

//----- (006F4AA0) --------------------------------------------------------  // acclient.c:777302
int _E141_18()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_5, "Sound.InterfaceSoundDisabled");
  return atexit(_E142_62);
}

//----- (006F4AC0) --------------------------------------------------------  // acclient.c:777309
int _E144_16()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_5, "Sound.InterfaceSoundVolume");
  return atexit(_E145_64);
}

//----- (006F4AE0) --------------------------------------------------------  // acclient.c:777316
int _E147_16()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_5, "Sound.SoundFeatures");
  return atexit(_E148_62);
}

//----- (006F4B00) --------------------------------------------------------  // acclient.c:777323
int _E150_16()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_5, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E151_60);
}

//----- (006F4B20) --------------------------------------------------------  // acclient.c:777330
int _E153_16()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_5, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_840174, "Mono");
  return atexit(_E154_61);
}

//----- (006F4B50) --------------------------------------------------------  // acclient.c:777338
void _E156_18()
{
  VOL_MIN_DIST_SQ_3 = 5.0 * 5.0;
}

//----- (006F4B70) --------------------------------------------------------  // acclient.c:777344
void _E158_4()
{
  INV_LOG_OF_2_3 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006F4B90) --------------------------------------------------------  // acclient.c:777350
int _E160_19()
{
  return atexit(_E161_20);
}

//----- (006F4BA0) --------------------------------------------------------  // acclient.c:777356
int _E164_4()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_18, "Render.TextureFiltering");
  return atexit(_E165_45);
}

//----- (006F4BC0) --------------------------------------------------------  // acclient.c:777363
int _E167_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_18, "Render.LandscapeDetailTextures");
  return atexit(_E168_46);
}

//----- (006F4BE0) --------------------------------------------------------  // acclient.c:777370
int _E170_2()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_18, "Render.BuildingDetailTextures");
  return atexit(_E171_45);
}

//----- (006F4C00) --------------------------------------------------------  // acclient.c:777377
int _E173_0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_18, "Render.FieldOfView");
  return atexit(_E174_47);
}

//----- (006F4C20) --------------------------------------------------------  // acclient.c:777384
int _E176_1()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_18, "Render.LandscapeTextureDetail");
  return atexit(_E177_44);
}

//----- (006F4C40) --------------------------------------------------------  // acclient.c:777391
int _E179_1()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_18, "Render.EnvironmentTextureDetail");
  return atexit(_E180_45);
}

//----- (006F4C60) --------------------------------------------------------  // acclient.c:777398
int _E182_1()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_18, "Render.SceneryDrawDistance");
  return atexit(_E183_44);
}

//----- (006F4C80) --------------------------------------------------------  // acclient.c:777405
int _E185_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_18, "Render.LandscapeDrawDistance");
  return atexit(_E186_44);
}

//----- (006F4CA0) --------------------------------------------------------  // acclient.c:777412
int _E188_1()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_18, "Render.ScreenBrightness");
  return atexit(_E189_43);
}

//----- (006F4CC0) --------------------------------------------------------  // acclient.c:777419
int _E191_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_18, "Render.AspectRatio");
  return atexit(_E192_33);
}

//----- (006F4CE0) --------------------------------------------------------  // acclient.c:777426
int _E194_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_18, "Render.DisplayAdapter");
  return atexit(_E195_24);
}

//----- (006F4D00) --------------------------------------------------------  // acclient.c:777433
int _E197()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_18, "Render.MaxHardwareClass");
  return atexit(_E198_30);
}

//----- (006F4D20) --------------------------------------------------------  // acclient.c:777440
int _E200_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_18, "Render.AutomaticDegrades");
  return atexit(_E201_23);
}

//----- (006F4D40) --------------------------------------------------------  // acclient.c:777447
int _E203_0()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_18, "Render.GraphicsPerformance");
  return atexit(_E204_18);
}

//----- (006F4D60) --------------------------------------------------------  // acclient.c:777454
int _E206_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_18, "Render.DegradeDistance");
  return atexit(_E207_14);
}

//----- (006F4D80) --------------------------------------------------------  // acclient.c:777461
int _E209()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_18, "Render.MultiPassAlpha");
  return atexit(_E210_18);
}

//----- (006F4DA0) --------------------------------------------------------  // acclient.c:777468
int _E212_2()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_18, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8401CC, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8401D0, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8401D4, "Anisotropic");
  return atexit(_E213_13);
}

//----- (006F4DF0) --------------------------------------------------------  // acclient.c:777478
int _E215()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_18, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8401DC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8401E0, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8401E4, "High");
  PStringBase<char>::PStringBase<char>(&stru_8401E8, "VeryHigh");
  return atexit(_E216_14);
}

//----- (006F4E50) --------------------------------------------------------  // acclient.c:777489
int _E218()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_18, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8401F0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8401F4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8401F8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8401FC, "VeryHigh");
  return atexit(_E219_11);
}

//----- (006F4EB0) --------------------------------------------------------  // acclient.c:777500
int _E221()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_18, "Low");
  PStringBase<char>::PStringBase<char>(&stru_840204, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_840208, "High");
  return atexit(_E222_10);
}

//----- (006F4EF0) --------------------------------------------------------  // acclient.c:777509
int _E224()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_18, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_840210, "Low");
  PStringBase<char>::PStringBase<char>(&stru_840214, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_840218, "High");
  PStringBase<char>::PStringBase<char>(&stru_84021C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_840220, "Extreme");
  return atexit(_E225_7);
}

//----- (006F4F60) --------------------------------------------------------  // acclient.c:777521
int _E227()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_18, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_840228, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_84022C, "Wide");
  return atexit(_E228_7);
}

//----- (006F4FA0) --------------------------------------------------------  // acclient.c:777530
int _E230()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_37, "None");
  return atexit(_E231_7);
}

//----- (006F4FC0) --------------------------------------------------------  // acclient.c:777537
int _E233()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_37, "Speed");
  return atexit(_E234_6);
}

//----- (006F4FE0) --------------------------------------------------------  // acclient.c:777544
int _E236()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_37, "Noise");
  return atexit(_E237_7);
}

//----- (006F5000) --------------------------------------------------------  // acclient.c:777551
int _E239()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_37, "Sine");
  return atexit(_E240_6);
}

//----- (006F5020) --------------------------------------------------------  // acclient.c:777558
int _E242()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_37, "Square");
  return atexit(_E243_6);
}

//----- (006F5040) --------------------------------------------------------  // acclient.c:777565
int _E245()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_37, "Bounce");
  return atexit(_E246_6);
}

//----- (006F5060) --------------------------------------------------------  // acclient.c:777572
int _E248()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_37, "Perlin");
  return atexit(_E249_6);
}

//----- (006F5080) --------------------------------------------------------  // acclient.c:777579
int _E251()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_37, "Fractal");
  return atexit(_E252_6);
}

//----- (006F50A0) --------------------------------------------------------  // acclient.c:777586
int _E254_0()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_37, "FrameLoop");
  return atexit(_E255_4);
}

//----- (006F50C0) --------------------------------------------------------  // acclient.c:777593
unsigned int _E257()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SmartBox_FPS");
  ID_SmartBox_FPS = result;
  return result;
}

//----- (006F50E0) --------------------------------------------------------  // acclient.c:777603
unsigned int _E259_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("fps");
  fps_var = result;
  return result;
}

//----- (006F5100) --------------------------------------------------------  // acclient.c:777613
unsigned int _E261_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("deg");
  deg_var = result;
  return result;
}

//----- (006F5120) --------------------------------------------------------  // acclient.c:777623
int sub_6F5120()
{
  return atexit(nullsub_641);
}

//----- (00761E20) --------------------------------------------------------  // acclient.c:888944
void __cdecl sub_761E20()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761E50) --------------------------------------------------------  // acclient.c:888957
void __cdecl sub_761E50()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761E80) --------------------------------------------------------  // acclient.c:888970
void __cdecl _E130_88()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761EB0) --------------------------------------------------------  // acclient.c:888983
void __cdecl _E133_81()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761EE0) --------------------------------------------------------  // acclient.c:888996
void __cdecl _E136_65()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761F10) --------------------------------------------------------  // acclient.c:889009
void __cdecl _E139_66()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761F40) --------------------------------------------------------  // acclient.c:889022
void __cdecl _E142_62()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761F70) --------------------------------------------------------  // acclient.c:889035
void __cdecl _E145_64()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761FA0) --------------------------------------------------------  // acclient.c:889048
void __cdecl _E148_62()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761FD0) --------------------------------------------------------  // acclient.c:889061
void __cdecl _E151_60()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762000) --------------------------------------------------------  // acclient.c:889074
void __cdecl _E154_61()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_3;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00762040) --------------------------------------------------------  // acclient.c:889099
void __cdecl _E165_45()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762070) --------------------------------------------------------  // acclient.c:889112
void __cdecl _E168_46()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007620A0) --------------------------------------------------------  // acclient.c:889125
void __cdecl _E171_45()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007620D0) --------------------------------------------------------  // acclient.c:889138
void __cdecl _E174_47()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762100) --------------------------------------------------------  // acclient.c:889151
void __cdecl _E177_44()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762130) --------------------------------------------------------  // acclient.c:889164
void __cdecl _E180_45()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762160) --------------------------------------------------------  // acclient.c:889177
void __cdecl _E183_44()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762190) --------------------------------------------------------  // acclient.c:889190
void __cdecl _E186_44()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007621C0) --------------------------------------------------------  // acclient.c:889203
void __cdecl _E189_43()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007621F0) --------------------------------------------------------  // acclient.c:889216
void __cdecl _E192_33()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762220) --------------------------------------------------------  // acclient.c:889229
void __cdecl _E195_24()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762250) --------------------------------------------------------  // acclient.c:889242
void __cdecl _E198_30()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762280) --------------------------------------------------------  // acclient.c:889255
void __cdecl _E201_23()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007622B0) --------------------------------------------------------  // acclient.c:889268
void __cdecl _E204_18()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007622E0) --------------------------------------------------------  // acclient.c:889281
void __cdecl _E207_14()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762310) --------------------------------------------------------  // acclient.c:889294
void __cdecl _E210_18()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762340) --------------------------------------------------------  // acclient.c:889307
void __cdecl _E213_13()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_18;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00762380) --------------------------------------------------------  // acclient.c:889332
void __cdecl _E216_14()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_18;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007623C0) --------------------------------------------------------  // acclient.c:889357
void __cdecl _E219_11()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_18;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00762400) --------------------------------------------------------  // acclient.c:889382
void __cdecl _E222_10()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_18;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00762440) --------------------------------------------------------  // acclient.c:889407
void __cdecl _E225_7()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_18;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00762480) --------------------------------------------------------  // acclient.c:889432
void __cdecl _E228_7()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_37;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007624C0) --------------------------------------------------------  // acclient.c:889457
void __cdecl _E231_7()
{
  char *v0; // esi@1

  v0 = &waveform_None_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007624F0) --------------------------------------------------------  // acclient.c:889470
void __cdecl _E234_6()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762520) --------------------------------------------------------  // acclient.c:889483
void __cdecl _E237_7()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762550) --------------------------------------------------------  // acclient.c:889496
void __cdecl _E240_6()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762580) --------------------------------------------------------  // acclient.c:889509
void __cdecl _E243_6()
{
  char *v0; // esi@1

  v0 = &waveform_Square_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007625B0) --------------------------------------------------------  // acclient.c:889522
void __cdecl _E246_6()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007625E0) --------------------------------------------------------  // acclient.c:889535
void __cdecl _E249_6()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762610) --------------------------------------------------------  // acclient.c:889548
void __cdecl _E252_6()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762640) --------------------------------------------------------  // acclient.c:889561
void __cdecl _E255_4()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

