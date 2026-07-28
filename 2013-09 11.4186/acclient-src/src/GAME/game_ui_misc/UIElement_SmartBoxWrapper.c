/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_SmartBoxWrapper
   Object     : GAME\game_ui_misc\UIElement_SmartBoxWrapper.obj
   Functions  : 43
   Addresses  : 004E5120 - 007631C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E5120) --------------------------------------------------------  // acclient.c:275056
void __userpurge UIElement_SmartBoxWrapper::UIElement_SmartBoxWrapper(UIElement_SmartBoxWrapper *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_SmartBoxWrapper *v4; // esi@1
  GlobalEventHandler *v5; // eax@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_SmartBoxWrapper::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&UIElement_SmartBoxWrapper::vftable;
  v4->m_cFlipCount = 0;
  LODWORD(v4->m_timeNextFlip) = 0;
  HIDWORD(v4->m_timeNextFlip) = 0;
  v4->m_iidUnderMouse = 0;
  v4->m_iidSelectedObject = 0;
  v4->m_SearchReason = 0;
  v4->m_fMouseMovementActive = 0;
  v4->m_fMouseMovementInProgress = 0;
  v4->m_CurrentSection = 10;
  v4->m_dropItemID = 0;
  v4->m_targetMode = 0;
  v4->m_dragIcon = 0;
  UIListener::RegisterForGlobalMessage((UIListener *)&v4->vfptr, 3u);
  v5 = GlobalEventHandler::GetGlobalEventHandler();
  v5->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v5, 100007u, (NoticeHandler *)&v4->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0070: using guessed type bool (__thiscall *UIElement_SmartBoxWrapper::vftable)(DBCache *this);
// 7C0318: using guessed type int (__thiscall *UIElement_SmartBoxWrapper::vftable)(void *, char);

//----- (004E51D0) --------------------------------------------------------  // acclient.c:275087
UIElement_SmartBoxWrapper *__thiscall UIElement_SmartBoxWrapper::DynamicCast(UIElement_SmartBoxWrapper *this, unsigned int i_eType)
{
  UIElement_SmartBoxWrapper *result; // eax@1

  result = this;
  if ( i_eType != 268435504 )
    result = (UIElement_SmartBoxWrapper *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E51F0) --------------------------------------------------------  // acclient.c:275098
signed int UIElement_SmartBoxWrapper::GetUIElementType()
{
  return 268435504;
}

//----- (004E5200) --------------------------------------------------------  // acclient.c:275104
void __thiscall UIElement_SmartBoxWrapper::~UIElement_SmartBoxWrapper(UIElement_SmartBoxWrapper *this)
{
  UIElement_Field *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_SmartBoxWrapper::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&UIElement_SmartBoxWrapper::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0070: using guessed type bool (__thiscall *UIElement_SmartBoxWrapper::vftable)(DBCache *this);
// 7C0318: using guessed type int (__thiscall *UIElement_SmartBoxWrapper::vftable)(void *, char);

//----- (004E5250) --------------------------------------------------------  // acclient.c:275127
void __usercall UIElement_SmartBoxWrapper::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_SmartBoxWrapper *v3; // eax@1

  v3 = (UIElement_SmartBoxWrapper *)operator new(0x628u);
  if ( v3 )
    UIElement_SmartBoxWrapper::UIElement_SmartBoxWrapper(v3, a1, _layout, _full_desc);
}

//----- (004E5280) --------------------------------------------------------  // acclient.c:275137
void __userpurge UIElement_SmartBoxWrapper::ResizeTo(UIElement_SmartBoxWrapper *this@<ecx>, int a2@<edi>, const int _width, const int _height)
{
  UIRegion *v4; // esi@1
  int v5; // ST0C_4@1
  int v6; // ST08_4@1
  int v7; // ST04_4@1
  int v8; // eax@1

  v4 = (UIRegion *)this;
  UIElement::ResizeTo((UIElement *)&this->vfptr, a2, _width, _height);
  v5 = UIRegion::GetHeight(v4);
  v6 = UIRegion::GetWidth(v4);
  v7 = UIRegion::GetScreenY0(v4);
  v8 = UIRegion::GetScreenX0(v4);
  SmartBox::SetMode(v8, v7, v6, v5);
}

//----- (004E52D0) --------------------------------------------------------  // acclient.c:275155
void __thiscall UIElement_SmartBoxWrapper::MoveTo(UIElement_SmartBoxWrapper *this, const int _x, const int _y)
{
  UIRegion *v3; // esi@1
  int v4; // ST0C_4@1
  int v5; // ST08_4@1
  int v6; // ST04_4@1
  int v7; // eax@1

  v3 = (UIRegion *)this;
  UIElement::MoveTo((UIElement *)&this->vfptr, _x, _y);
  v4 = UIRegion::GetHeight(v3);
  v5 = UIRegion::GetWidth(v3);
  v6 = UIRegion::GetScreenY0(v3);
  v7 = UIRegion::GetScreenX0(v3);
  SmartBox::SetMode(v7, v6, v5, v4);
}

//----- (004E5320) --------------------------------------------------------  // acclient.c:275173
void __stdcall UIElement_SmartBoxWrapper::ApplyLighting(unsigned int objID, LightingMode lightingMode)
{
  HashBaseData<unsigned long> *v3; // ecx@1

  v3 = CObjectMaint::GetObjectA(CObjectMaint::s_pcInstance, objID);
  if ( v3 )
  {
    if ( lightingMode )
    {
      if ( lightingMode == 1 )
      {
        CPhysicsObj::SetLighting((CPhysicsObj *)v3, 0.0, 0.34999999);
      }
      else if ( lightingMode == 2 )
      {
        CPhysicsObj::SetLighting((CPhysicsObj *)v3, 0.99000001, 1.0);
      }
    }
    else
    {
      CPhysicsObj::RestoreLighting((CPhysicsObj *)v3);
    }
  }
}

//----- (004E5380) --------------------------------------------------------  // acclient.c:275199
void __stdcall UIElement_SmartBoxWrapper::HandleTargetedUseLeftClick(unsigned int _itemID, unsigned int _mode)
{
  ClientUISystem *v3; // eax@3

  if ( _itemID )
  {
    if ( ClientUISystem::GetUISystem() )
    {
      v3 = ClientUISystem::GetUISystem();
      ClientUISystem::ExecuteTargetModeForItem(v3, _itemID, (Target_Mode)_mode);
    }
  }
}

//----- (004E53B0) --------------------------------------------------------  // acclient.c:275214
UIElement_Field *__thiscall UIElement_SmartBoxWrapper::vector_deleting_destructor(UIElement_SmartBoxWrapper *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_SmartBoxWrapper::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&UIElement_SmartBoxWrapper::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
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
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0070: using guessed type bool (__thiscall *UIElement_SmartBoxWrapper::vftable)(DBCache *this);
// 7C0318: using guessed type int (__thiscall *UIElement_SmartBoxWrapper::vftable)(void *, char);

//----- (004E5410) --------------------------------------------------------  // acclient.c:275240
void __cdecl UIElement_SmartBoxWrapper::Register()
{
  UIElement::RegisterElementClass(
    0x10000030u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_SmartBoxWrapper::Create);
}

//----- (004E5430) --------------------------------------------------------  // acclient.c:275248
void __stdcall UIElement_SmartBoxWrapper::FindObject(int i_xWindow, int i_yWindow, bool fAccurate)
{
  UIElement *v4; // ecx@2
  int v5; // eax@3

  if ( UIElementManager::s_pInstance
    && (v4 = UIElementManager::s_pInstance->m_pElementLastOver) != 0
    && (v5 = ((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506)) != 0 )
    SmartBox::set_found_object(*(_DWORD *)(v5 + 1532), 0xFFFFFFFF);
  else
    SmartBox::find_object(i_xWindow, i_yWindow);
}

//----- (004E5480) --------------------------------------------------------  // acclient.c:275262
void __thiscall UIElement_SmartBoxWrapper::HandleDropRelease(UIElement_SmartBoxWrapper *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement_SmartBoxWrapper *v3; // esi@1
  UIElement *v4; // ecx@1
  int v5; // eax@1
  int v6; // edi@6
  int v7; // eax@6
  DropItemFlags dropFlags; // [sp+4h] [bp-8h]@4
  unsigned int dropSpellID; // [sp+8h] [bp-4h]@4

  v2 = i_rMsg->dwParam1;
  v3 = this;
  v4 = *(UIElement **)(v2 + 8);
  v5 = *(_DWORD *)(v2 + 16);
  if ( v4 )
  {
    if ( v5 )
    {
      if ( *(_DWORD *)(v5 + 740) == v3->m_desc.m_elementID )
      {
        UIElement_ItemList::InqDropIconInfo(v4, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
        if ( i_rMsg )
        {
          if ( !(dropFlags & 0xE) )
          {
            v6 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
            v7 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
            v3->m_dropItemID = (unsigned int)i_rMsg;
            v3->m_SearchReason = 5;
            UIElement_SmartBoxWrapper::FindObject(v6, v7, 1);
          }
        }
      }
    }
  }
}

//----- (004E5510) --------------------------------------------------------  // acclient.c:275301
void __thiscall UIElement_SmartBoxWrapper::PostInit(UIElement_SmartBoxWrapper *this)
{
  UIElement_SmartBoxWrapper *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@1
  ElementDesc *v4; // eax@2

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = DBObj::GetByEnum(268435512, 5, 0x23u);
  v3 = v2;
  if ( v2 )
  {
    v4 = UIElementManager::CreateChildElement(
           UIElementManager::s_pInstance,
           (UIElement *)&v1->vfptr,
           (LayoutDesc *)v2,
           0x10000345u);
    v1->m_dragIcon = (UIElement *)v4;
    ((void (__thiscall *)(ElementDesc *, _DWORD))v4->vfptr->HandleNode)(v4, 0);
  }
  ((void (__thiscall *)(UIElement_SmartBoxWrapper *, signed int))v1->vfptr[22].OnLoseFocus)(v1, 1);
  if ( v3 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
}

//----- (004E5570) --------------------------------------------------------  // acclient.c:275328
char __thiscall UIElement_SmartBoxWrapper::InqAvailableProperties(UIElement_SmartBoxWrapper *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement_Field::InqAvailableProperties((UIElement_Field *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0x10000003u, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004E55C0) --------------------------------------------------------  // acclient.c:275356
int __thiscall UIElement_SmartBoxWrapper::ListenToElementMessage(UIElement_SmartBoxWrapper *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement_SmartBoxWrapper *v3; // esi@1
  int result; // eax@2
  int v5; // ST04_4@4
  int v6; // ST00_4@4

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 == 21 )
  {
    UIElementManager::ResetTooltip(UIElementManager::s_pInstance);
    UIElement_SmartBoxWrapper::HandleDropRelease(v3, i_rMsg);
    result = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  else
  {
    if ( v2 == 33 )
    {
      v5 = i_rMsg->ptWindow.y;
      v6 = i_rMsg->ptWindow.x;
      this->m_SearchReason = 6;
      UIElement_SmartBoxWrapper::FindObject(v6, v5, 1);
    }
    result = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  return result;
}

//----- (004E5620) --------------------------------------------------------  // acclient.c:275387
void __thiscall UIElement_SmartBoxWrapper::Global_Loop(UIElement_SmartBoxWrapper *this)
{
  UIElement_SmartBoxWrapper *v1; // esi@1
  unsigned int v2; // ecx@1
  int v3; // eax@3
  int v4; // ecx@3
  CInputManager *v5; // edi@7
  int v6; // ST04_4@9
  int v7; // eax@9

  v1 = this;
  v2 = this->m_cFlipCount;
  if ( v2 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= v1->m_timeNextFlip )
  {
    v3 = v2 + 1;
    v4 = 0;
    v1->m_cFlipCount = v3;
    if ( (unsigned int)v3 < 5 )
    {
      v1->m_timeNextFlip = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.2;
      v4 = ((v3 & 1) != 0) + 1;
    }
    else
    {
      v1->m_cFlipCount = 0;
    }
    UIElement_SmartBoxWrapper::ApplyLighting(v1->m_iidSelectedObject, (LightingMode)v4);
  }
  v5 = ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
  {
    if ( v1->m_SearchReason < 1 )
    {
      v1->m_SearchReason = 1;
      v6 = v5->vfptr->GetMouseY((ICIDM *)v5);
      v7 = v5->vfptr->GetMouseX((ICIDM *)v5);
      UIElement_SmartBoxWrapper::FindObject(v7, v6, 0);
    }
  }
}

//----- (004E56C0) --------------------------------------------------------  // acclient.c:275429
void __thiscall UIElement_SmartBoxWrapper::MouseMove(UIElement_SmartBoxWrapper *this, int i_xWindow, int i_yWindow)
{
  UIElement_SmartBoxWrapper *v3; // esi@1

  v3 = this;
  UIElement::MouseMove((UIElement *)&this->vfptr, i_yWindow, i_xWindow, i_yWindow);
  if ( v3->m_SearchReason < 1 )
  {
    v3->m_SearchReason = 1;
    UIElement_SmartBoxWrapper::FindObject(i_xWindow, i_yWindow, 0);
  }
}

//----- (004E5700) --------------------------------------------------------  // acclient.c:275443
void __thiscall UIElement_SmartBoxWrapper::MouseDown(UIElement_SmartBoxWrapper *this, unsigned int i_xWindow, unsigned int i_yWindow, unsigned int i_button)
{
  UIElement_SmartBoxWrapper *v4; // esi@1

  v4 = this;
  UIElement::MouseDown((UIElement *)&this->vfptr, i_xWindow, i_yWindow, i_button);
  if ( i_button == 7 )
  {
    if ( !((int (__stdcall *)(_DWORD))SmartBox::smartbox->cmdinterp->vfptr[18].__vecDelDtor)(1)
      && v4->m_SearchReason < 2 )
    {
      if ( ClientUISystem::GetUISystem()->targetMode )
      {
        v4->m_SearchReason = 7;
        v4->m_targetMode = ClientUISystem::GetUISystem()->targetMode;
        UIElement_SmartBoxWrapper::FindObject(i_xWindow, i_yWindow, 1);
      }
      else
      {
        v4->m_SearchReason = 2;
        UIElement_SmartBoxWrapper::FindObject(i_xWindow, i_yWindow, 1);
      }
    }
  }
  else if ( i_button == 8 )
  {
    if ( ICIDM::s_cidm->m_UseMouseTurning )
      CameraManager::ToggleMouseLook(SmartBox::smartbox->camera_manager, 8, 1);
  }
  else if ( i_button == 10
         && !((int (*)(void))SmartBox::smartbox->cmdinterp->vfptr[17].OnLoseFocus)()
         && v4->m_SearchReason < 4 )
  {
    v4->m_SearchReason = 4;
    UIElement_SmartBoxWrapper::FindObject(i_xWindow, i_yWindow, 1);
  }
}

//----- (004E5820) --------------------------------------------------------  // acclient.c:275482
void __thiscall UIElement_SmartBoxWrapper::MouseUp(UIElement_SmartBoxWrapper *this, unsigned int i_xWindow, unsigned int i_yWindow, unsigned int i_button)
{
  UIElement_SmartBoxWrapper *v4; // esi@1
  ClientUISystem *v5; // eax@6

  v4 = this;
  UIElement::MouseUp((UIElement *)&this->vfptr, i_xWindow, i_yWindow, i_button);
  if ( i_button == 7 )
  {
    ((void (__stdcall *)(_DWORD))SmartBox::smartbox->cmdinterp->vfptr[18].__vecDelDtor)(0);
  }
  else if ( i_button == 8 )
  {
    if ( v4->m_fMouseMovementActive )
    {
      if ( v4->m_fMouseMovementInProgress )
        v4->m_fMouseMovementInProgress = 0;
      v5 = ClientUISystem::GetUISystem();
      ClientUISystem::UpdateCursorState(v5);
    }
    else if ( ICIDM::s_cidm->m_UseMouseTurning )
    {
      CameraManager::ToggleMouseLook(SmartBox::smartbox->camera_manager, i_xWindow, 0);
    }
    else if ( v4->m_SearchReason < 3 )
    {
      v4->m_SearchReason = 3;
      UIElement_SmartBoxWrapper::FindObject(i_xWindow, i_yWindow, 1);
    }
  }
}

//----- (004E58F0) --------------------------------------------------------  // acclient.c:275515
char __userpurge UIElement_SmartBoxWrapper::PrepareDragIcon@<al>(UIElement_SmartBoxWrapper *this@<ecx>, int a2@<esi>, unsigned int _itemID)
{
  unsigned int v3; // ebp@1
  UIElement_SmartBoxWrapper *v4; // edi@1
  HashBaseData<unsigned long> *v5; // esi@2
  Graphic *v6; // ebp@3
  Graphic *v7; // eax@4
  Graphic *v8; // eax@4
  unsigned int v9; // edx@15
  BasePropertyValue *v10; // ecx@18
  unsigned int v11; // edx@18
  BasePropertyDesc *v12; // ecx@22
  unsigned int v13; // edx@22
  BasePropertyValue *v14; // ecx@26
  unsigned int v15; // edx@26
  char result; // al@28
  int v17; // [sp+0h] [bp-24h]@2
  BaseProperty containerProp; // [sp+14h] [bp-10h]@12
  BaseProperty itemIDProp; // [sp+1Ch] [bp-8h]@10

  v3 = _itemID;
  v4 = this;
  if ( _itemID )
  {
    v17 = a2;
    UIRegion::ClearImage((UIRegion *)&this->m_dragIcon->vfptr);
    v5 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v5 )
    {
      UIRegion::SetBlitMode((UIRegion *)&v4->m_dragIcon->vfptr, Blit_3Alpha);
      v6 = (Graphic *)operator new(0xCu);
      if ( v6 )
      {
        v7 = ACCWeenieObject::GetDragIcon((ACCWeenieObject *)v5);
        Graphic::Graphic(v6, v7);
      }
      else
      {
        v8 = 0;
      }
      UIRegion::SetImage((UIRegion *)&v4->m_dragIcon->vfptr, v8);
      if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v5[21].hash_next)
        && !v5[16].id )
        v5[17].vfptr;
      v3 = _itemID;
    }
    itemIDProp.m_pcPropertyDesc = 0;
    itemIDProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&itemIDProp, 0x1000000Fu);
    if ( itemIDProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&itemIDProp);
      ((void (__stdcall *)(unsigned int))itemIDProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v3);
    }
    ((void (__stdcall *)(BaseProperty *, int))v4->m_dragIcon->vfptr[17].OnLoseFocus)(&itemIDProp, v17);
    containerProp.m_pcPropertyValue = 0;
    itemIDProp.m_pcPropertyDesc = 0;
    BaseProperty::SetPropertyName((BaseProperty *)((char *)&containerProp + 4), 0x10000011u);
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      BaseProperty::CheckCopyOnWrite((BaseProperty *)((char *)&containerProp + 4));
      ((void (__stdcall *)(BasePropertyDesc *))itemIDProp.m_pcPropertyDesc->vfptr[29].__vecDelDtor)(containerProp.m_pcPropertyDesc);
    }
    ((void (__cdecl *)(BasePropertyValue **))v4->m_dragIcon->vfptr[17].OnLoseFocus)(&containerProp.m_pcPropertyValue);
    if ( (_DWORD)containerProp.m_pcPropertyDesc )
    {
      v9 = containerProp.m_pcPropertyDesc->m_cRef - 1;
      containerProp.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(signed int))containerProp.m_pcPropertyDesc->vfptr->__vecDelDtor)(1);
    }
    if ( containerProp.m_pcPropertyValue )
    {
      v10 = containerProp.m_pcPropertyValue;
      v11 = containerProp.m_pcPropertyValue->m_cRef - 1;
      containerProp.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      v12 = itemIDProp.m_pcPropertyDesc;
      v13 = itemIDProp.m_pcPropertyDesc->m_cRef - 1;
      itemIDProp.m_pcPropertyDesc->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      itemIDProp.m_pcPropertyDesc = 0;
    }
    if ( itemIDProp.m_pcPropertyValue )
    {
      v14 = itemIDProp.m_pcPropertyValue;
      v15 = itemIDProp.m_pcPropertyValue->m_cRef - 1;
      itemIDProp.m_pcPropertyValue->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 4E58F0: could not find valid save-restore pair for esi

//----- (004E5AC0) --------------------------------------------------------  // acclient.c:275623
void __thiscall UIElement_SmartBoxWrapper::ListenToGlobalMessage(UIElement_SmartBoxWrapper *this, unsigned int messageID, int data_int)
{
  if ( messageID == 3 )
    UIElement_SmartBoxWrapper::Global_Loop(this);
}

//----- (004E5AD0) --------------------------------------------------------  // acclient.c:275630
void __thiscall UIElement_SmartBoxWrapper::RecvNotice_SmartBoxObjectFound(UIElement_SmartBoxWrapper *this, unsigned int iidObject)
{
  unsigned int v2; // ebp@1
  UIElement_SmartBoxWrapper *v3; // edi@1
  HashBaseData<unsigned long> *v4; // eax@2
  unsigned int v5; // eax@5
  HashBaseData<unsigned long> *v6; // eax@7
  HashBaseData<unsigned long> *v7; // eax@12
  HashSetData<UIElement *> *v8; // eax@14
  double v9; // st7@14
  HashBaseData<unsigned long> *v10; // eax@18
  HashBaseData<unsigned long> *v11; // eax@19
  unsigned int v12; // ecx@20
  ClientUISystem *v13; // eax@25
  HashSetData<UIElement *> *v14; // eax@26
  HashBaseData<unsigned long> *v15; // eax@28
  HashBaseData<unsigned long> *v16; // eax@34
  int v17; // esi@34
  CPlayerSystem *v18; // eax@45
  char v19; // al@45
  char *v20; // eax@47
  CInputManager *v21; // esi@49
  ICIDMVtbl *v22; // edx@50
  int v23; // eax@50
  ICIDMVtbl *v24; // edx@50
  unsigned int v25; // ebp@50
  int v26; // eax@50
  unsigned int v27; // eax@50
  ClientUISystem *v28; // eax@57
  bool fCurrentlyOverObject; // [sp+Eh] [bp-9Ah]@5
  bool fObjectChanged; // [sp+Fh] [bp-99h]@5
  PStringBase<unsigned short> strName; // [sp+10h] [bp-98h]@47
  unsigned int v32; // [sp+14h] [bp-94h]@50
  StringInfo _text; // [sp+18h] [bp-90h]@48

  v2 = iidObject;
  v3 = this;
  if ( !iidObject || (v4 = ClientObjMaintSystem::GetWeenieObject(iidObject)) != 0 && SLOBYTE(v4[21].hash_next) >= 0 )
  {
    v5 = (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2];
    fCurrentlyOverObject = iidObject != 0;
    fObjectChanged = v5 != iidObject;
    if ( v5 != iidObject && v3->m_hashElementsRegisteredWith.vfptr )
    {
      v6 = CObjectMaint::GetObjectA(CObjectMaint::s_pcInstance, v5);
      if ( v6 )
        CPhysicsObj::RestoreLighting((CPhysicsObj *)v6);
      v3->m_hashElementsRegisteredWith.vfptr = 0;
    }
    if ( fCurrentlyOverObject )
    {
      if ( (signed int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] >= 2 )
      {
        v7 = CObjectMaint::GetObjectA(CObjectMaint::s_pcInstance, iidObject);
        if ( v7 )
          CPhysicsObj::SetLighting((CPhysicsObj *)v7, 0.99000001, 1.0);
        v8 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
        v9 = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.2;
        v3->m_hashElementsRegisteredWith.vfptr = (HashSet<UIElement *>Vtbl *)1;
        *(double *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr = v9;
        if ( v8 != (HashSetData<UIElement *> *)5 && v8 != (HashSetData<UIElement *> *)7 )
          ACCWeenieObject::SetSelectedObject(iidObject, 0);
      }
      if ( v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)4 )
      {
        v10 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
        if ( v10 )
        {
          v11 = v10[15].hash_next;
          v12 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
          if ( v11 != (HashBaseData<unsigned long> *)v12 )
            ItemHolder::UseObject(ACCWeenieObject::selectedID, 0, 0);
        }
      }
      if ( v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)3 )
      {
        v13 = ClientUISystem::GetUISystem();
        ClientUISystem::ExamineObject(v13, iidObject);
      }
    }
    v14 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
    if ( v14 == (HashSetData<UIElement *> *)5 )
    {
      if ( !ItemHolder::AttemptPlaceIn3D(
              (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6],
              iidObject != 0 ? iidObject : 0,
              1) )
      {
        v15 = ClientObjMaintSystem::GetWeenieObject((unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]);
        if ( v15 )
          ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v15, 0);
      }
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = 0;
    }
    else if ( v14 == (HashSetData<UIElement *> *)6 )
    {
      if ( iidObject )
      {
        if ( ClientCombatSystem::GetCombatSystem()->combatMode == 1 )
        {
          v16 = ClientObjMaintSystem::GetWeenieObject(iidObject);
          v17 = (int)v16;
          if ( v16 )
          {
            if ( !v16[9].hash_next
              && (!((unsigned int)v16[21].hash_next & 4)
               && !(((int (__thiscall *)(HashBaseData<unsigned long> *))v16->vfptr[6].__vecDelDtor)(v16) & 0x10)
               || iidObject == GetPlayerID())
              && !*(_DWORD *)(v17 + 184)
              && UIElement_SmartBoxWrapper::PrepareDragIcon(
                   (UIElement_SmartBoxWrapper *)((char *)v3 - 1528),
                   v17,
                   iidObject) )
            {
              UIElementManager::StartDragandDrop(
                UIElementManager::s_pInstance,
                (UIElement *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]->m_hashKey,
                16,
                16);
              CM_Item::SendNotice_BeginDrag(iidObject, 0, 0);
            }
          }
        }
      }
    }
    else if ( v14 == (HashSetData<UIElement *> *)7 )
    {
      UIElement_SmartBoxWrapper::HandleTargetedUseLeftClick(
        iidObject,
        (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7]);
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = 0;
    }
    if ( fObjectChanged )
    {
      v18 = CPlayerSystem::GetPlayerSystem();
      v19 = PlayerModule::ShowTooltips((PlayerModule *)&v18->playerModule.vfptr);
      if ( fCurrentlyOverObject && v19 )
      {
        v20 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)iidObject, 2u, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&strName, 0, v20);
        if ( *(_DWORD *)&strName.m_charbuffer[-1].m_data[14] != 1 )
        {
          StringInfo::StringInfo(&_text);
          StringInfo::SetLiteralValue(&_text, &strName, 1);
          UIElement::SetTooltip(
            (UIElement *)&v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9],
            &_text);
          *((_DWORD *)&v3[-1].m_hashElementsRegisteredWith + 52) |= 0x20u;
          if ( UIElementManager::s_pInstance->m_dragElement )
          {
            v21 = ICIDM::s_cidm;
            if ( ICIDM::s_cidm )
            {
              v22 = ICIDM::s_cidm->vfptr;
              v32 = RenderDevice::render_device->m_viewportX;
              v23 = v22->GetMouseX((ICIDM *)ICIDM::s_cidm);
              v24 = v21->vfptr;
              v25 = v23 - v32;
              v32 = RenderDevice::render_device->m_viewportY;
              v26 = v24->GetMouseY((ICIDM *)v21);
              v27 = v26 - v32;
              if ( v25 < RenderDevice::render_device->m_viewportWidth
                && v27 < RenderDevice::render_device->m_viewportHeight )
              {
                UIElementManager::ResetTooltip(UIElementManager::s_pInstance);
                UIElement::StartTooltipAtMouse(
                  (UIElement *)&v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9],
                  0.0);
              }
              v2 = iidObject;
            }
          }
          StringInfo::~StringInfo(&_text);
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
      }
      else
      {
        *((_DWORD *)&v3[-1].m_hashElementsRegisteredWith + 52) = (unsigned int)v3[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[7] & 0xFFFFFFDF;
        UIElement::ClearTooltip((UIElement *)&v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9]);
      }
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = (HashSetData<UIElement *> *)v2;
      v28 = ClientUISystem::GetUISystem();
      ClientUISystem::UpdateCursorState(v28);
    }
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = 0;
  }
  else
  {
    SmartBox::set_found_object(0, 0xFFFFFFFF);
  }
}

//----- (006F63E0) --------------------------------------------------------  // acclient.c:778924
void _E73_80()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840724, PFID_A8R8G8B8);
}

//----- (006F63F0) --------------------------------------------------------  // acclient.c:778930
void sub_6F63F0()
{
  LODWORD(dword_840760) = 1053364187;
}

//----- (006F6400) --------------------------------------------------------  // acclient.c:778936
void _E93_91()
{
  flt_840764 = 1000.0 + 1.0;
}

//----- (006F6420) --------------------------------------------------------  // acclient.c:778942
void _E95_91()
{
  flt_840768 = 24.0 * 8.0;
}

//----- (006F6440) --------------------------------------------------------  // acclient.c:778948
void sub_6F6440()
{
  flt_84076C = 24.0 * 0.5;
}

//----- (006F6460) --------------------------------------------------------  // acclient.c:778954
int _E99_9()
{
  return atexit(nullsub_972);
}

//----- (006F6470) --------------------------------------------------------  // acclient.c:778960
int _E102_10()
{
  return atexit(nullsub_973);
}

//----- (006F6480) --------------------------------------------------------  // acclient.c:778966
int _E105_12()
{
  return atexit(nullsub_974);
}

//----- (006F6490) --------------------------------------------------------  // acclient.c:778972
int _E108_56()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_40, "Misc.TooltipEnable");
  return atexit(sub_763190);
}

//----- (006F64B0) --------------------------------------------------------  // acclient.c:778979
int _E111_32()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_40, "Misc.TooltipDelay");
  return atexit(sub_7631C0);
}

//----- (006F64D0) --------------------------------------------------------  // acclient.c:778986
void _E117_47()
{
  DEFAULT_VIEW_RADIUS_75 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F64F0) --------------------------------------------------------  // acclient.c:778992
void _E119_17()
{
  MIN_QUANTUM_75 = 1.0 / 30.0;
}

//----- (006F6510) --------------------------------------------------------  // acclient.c:778998
void _E121_47()
{
  MAX_QUANTUM_75 = 1.0 / 5.0;
}

//----- (006F6530) --------------------------------------------------------  // acclient.c:779004
void _E124_47()
{
  dword_840790 = 1024;
}

//----- (006F6540) --------------------------------------------------------  // acclient.c:779010
void _E126_22()
{
  dword_840794 = 0x7FFF;
}

//----- (006F6550) --------------------------------------------------------  // acclient.c:779016
int _E128_7()
{
  const int result; // eax@1

  result = dword_840790;
  INITIAL_MAX_DATA_RATE_48 = dword_840790;
  return result;
}

//----- (006F6560) --------------------------------------------------------  // acclient.c:779026
int _E130_35()
{
  return atexit(_E131_41);
}

//----- (006F6570) --------------------------------------------------------  // acclient.c:779032
int sub_6F6570()
{
  return atexit(nullsub_976);
}

//----- (00763190) --------------------------------------------------------  // acclient.c:889886
void __cdecl sub_763190()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007631C0) --------------------------------------------------------  // acclient.c:889899
void __cdecl sub_7631C0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

