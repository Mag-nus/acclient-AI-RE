/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_UIItem
   Object     : GAME\game_ui_misc\UIElement_UIItem.obj
   Functions  : 49
   Addresses  : 004E0F40 - 00763060 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E0F40) --------------------------------------------------------  // acclient.c:271208
void __userpurge UIElement_UIItem::UIElement_UIItem(UIElement_UIItem *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_UIItem *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_UIItem::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->itemID = 0;
  v4->spellID = 0;
  v4->containerDisplay = 0;
  v4->weenObj = 0;
  v4->effects = 0;
  v4->waiting = 0;
  v4->selected = 0;
  v4->isOpenable = 0;
  v4->isContainer = 0;
  v4->isContainerHolder = 0;
  v4->valid = 0;
  v4->dragOverState = 0;
  v4->unghostable = 0;
  v4->m_sellState = 0;
  v4->m_tradeState = 0;
  v4->m_selectable = 1;
  v4->m_shortcutNum = -1;
  v4->m_delayedShortcutNum = -1;
  v4->m_shortcutGhosted = 0;
  v4->m_quantity = -1;
  v4->openState = 0;
  LODWORD(v4->m_heartbeatInterval) = 0;
  HIDWORD(v4->m_heartbeatInterval) = 1072693248;
  LODWORD(v4->m_lastHeartbeat) = 0;
  HIDWORD(v4->m_lastHeartbeat) = 0;
  v4->m_elem_Icon = 0;
  v4->m_elem_Icon_Overlays = 0;
  v4->m_elem_Icon_Selected = 0;
  v4->m_elem_Icon_Ghosted = 0;
  v4->m_elem_Icon_ShortcutNum = 0;
  v4->m_elem_Icon_SellState = 0;
  v4->m_elem_Icon_TradeState = 0;
  v4->m_elem_Icon_OpenContainer = 0;
  v4->m_elem_Icon_DragAccept = 0;
  v4->m_elem_Icon_CapacityBar = 0;
  v4->m_elem_Icon_StructureBar = 0;
  v4->m_elem_Icon_Quantity = 0;
  v4->m_elem_Text = 0;
  v4->m_dragIcon = 0;
  v4->m_elem_Icon_Cooldown_10 = 0;
  v4->m_elem_Icon_Cooldown_20 = 0;
  v4->m_elem_Icon_Cooldown_30 = 0;
  v4->m_elem_Icon_Cooldown_40 = 0;
  v4->m_elem_Icon_Cooldown_50 = 0;
  v4->m_elem_Icon_Cooldown_60 = 0;
  v4->m_elem_Icon_Cooldown_70 = 0;
  v4->m_elem_Icon_Cooldown_80 = 0;
  v4->m_elem_Icon_Cooldown_90 = 0;
  v4->m_elem_Icon_Cooldown_100 = 0;
  GlobalEventHandler::GetGlobalEventHandler();
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7BF5D0: using guessed type int (__thiscall *UIElement_UIItem::vftable)(void *, char);

//----- (004E10B0) --------------------------------------------------------  // acclient.c:271272
UIElement_UIItem *__thiscall UIElement_UIItem::DynamicCast(UIElement_UIItem *this, unsigned int i_eType)
{
  UIElement_UIItem *result; // eax@1

  result = this;
  if ( i_eType != 268435506 )
    result = (UIElement_UIItem *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E10D0) --------------------------------------------------------  // acclient.c:271283
signed int UIElement_UIItem::GetUIElementType()
{
  return 268435506;
}

//----- (004E10E0) --------------------------------------------------------  // acclient.c:271289
void __usercall UIElement_UIItem::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_UIItem *v3; // eax@1

  v3 = (UIElement_UIItem *)operator new(0x6C8u);
  if ( v3 )
    UIElement_UIItem::UIElement_UIItem(v3, a1, _layout, _full_desc);
}

//----- (004E1110) --------------------------------------------------------  // acclient.c:271299
void __thiscall UIElement_UIItem::Init_UIItem(UIElement_UIItem *this, unsigned int _itemID, int _containerDisplay)
{
  this->itemID = _itemID;
  this->spellID = 0;
  this->containerDisplay = _containerDisplay;
  this->weenObj = 0;
}

//----- (004E1140) --------------------------------------------------------  // acclient.c:271308
void __thiscall UIElement_UIItem::Init_UIItem_Spell_Shortcut(UIElement_UIItem *this, unsigned int _spellID)
{
  this->itemID = 0;
  this->spellID = _spellID;
  this->containerDisplay = 0;
  this->weenObj = 0;
}

//----- (004E1170) --------------------------------------------------------  // acclient.c:271317
void __thiscall UIElement_UIItem::Clear_UIItem(UIElement_UIItem *this)
{
  this->itemID = 0;
  this->spellID = 0;
  this->containerDisplay = 0;
  this->weenObj = 0;
}

//----- (004E1190) --------------------------------------------------------  // acclient.c:271326
UIElement *__thiscall UIElement_UIItem::UIItem_GetState(UIElement_UIItem *this)
{
  UIElement *result; // eax@1

  result = this->m_elem_Icon;
  if ( result )
    result = (UIElement *)result->m_state;
  return result;
}

//----- (004E11B0) --------------------------------------------------------  // acclient.c:271337
void __thiscall UIElement_UIItem::SetWaitingState(UIElement_UIItem *this, int _waiting)
{
  UIElement_UIItem *v2; // esi@1
  ACCWeenieObject *v3; // ecx@1
  int v4; // edx@2
  UIElement *v5; // ecx@3

  v2 = this;
  v3 = this->weenObj;
  if ( v3 )
  {
    ACCWeenieObject::SetWaitingState(v3, _waiting);
    if ( !v2->unghostable )
    {
      v5 = v2->m_elem_Icon_Ghosted;
      if ( v5 )
      {
        LOBYTE(v4) = _waiting != 0;
        ((void (__stdcall *)(int))v5->vfptr[2].__vecDelDtor)(v4);
      }
    }
  }
}

//----- (004E1200) --------------------------------------------------------  // acclient.c:271362
void __thiscall UIElement_UIItem::SetOpenContainerState(UIElement_UIItem *this, int _open)
{
  UIElement_UIItem *v2; // esi@1
  UIElement *v3; // ecx@1

  v2 = this;
  v3 = this->m_elem_Icon_OpenContainer;
  if ( v3 )
  {
    if ( UIElement::IsVisible(v3) != (_BYTE)_open )
      ((void (__stdcall *)(_DWORD))v2->m_elem_Icon_OpenContainer->vfptr[2].__vecDelDtor)(_open);
  }
}

//----- (004E1230) --------------------------------------------------------  // acclient.c:271377
void __thiscall UIElement_UIItem::SetDelayedShortcutNum(UIElement_UIItem *this, int _shortcutNum)
{
  this->m_delayedShortcutNum = _shortcutNum;
}

//----- (004E1240) --------------------------------------------------------  // acclient.c:271383
void __thiscall UIElement_UIItem::SetSelectedState(UIElement_UIItem *this, int _selected)
{
  int v2; // eax@1
  UIElement *v3; // ecx@3

  v2 = _selected;
  if ( !_selected || this->m_selectable )
  {
    this->selected = _selected;
    v3 = this->m_elem_Icon_Selected;
    if ( v3 )
    {
      LOBYTE(v2) = _selected != 0;
      ((void (__stdcall *)(int))v3->vfptr[2].__vecDelDtor)(v2);
    }
  }
}

//----- (004E1280) --------------------------------------------------------  // acclient.c:271402
void __thiscall UIElement_UIItem::SetSelectableState(UIElement_UIItem *this, bool _selectable)
{
  this->m_selectable = _selectable;
}

//----- (004E1290) --------------------------------------------------------  // acclient.c:271408
void __thiscall UIElement_UIItem::SetDragAcceptState(UIElement_UIItem *this, unsigned int _state)
{
  UIElement *v2; // ecx@1

  v2 = this->m_elem_Icon_DragAccept;
  if ( v2 )
  {
    if ( _state != v2->m_state )
      ((void (__stdcall *)(unsigned int))v2->vfptr[13].__vecDelDtor)(_state);
  }
}

//----- (004E12C0) --------------------------------------------------------  // acclient.c:271421
void __thiscall UIElement_UIItem::SetQuantity(UIElement_UIItem *this, int _quantity)
{
  this->m_quantity = _quantity;
}

//----- (004E12D0) --------------------------------------------------------  // acclient.c:271427
void __thiscall UIElement_UIItem::ListenToGlobalMessage(UIElement_UIItem *this, unsigned int i_messageID, int i_data_int)
{
  IInputActionCallbackVtbl *v3; // eax@3

  if ( i_messageID == 3 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_heartbeatInterval + this->m_lastHeartbeat )
  {
    v3 = this->vfptr;
    this->m_lastHeartbeat = *(double *)&Timer::cur_time;
    ((void (*)(void))v3[26].__vecDelDtor)();
  }
}

//----- (004E1310) --------------------------------------------------------  // acclient.c:271440
UIListener *__thiscall UIElement_UIItem::scalar_deleting_destructor(UIElement_UIItem *this, unsigned int a2)
{
  UIListener *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIListener *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_UIItem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  UIListener::UnRegisterForGlobalMessage(v2, 3u);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7BF5D0: using guessed type int (__thiscall *UIElement_UIItem::vftable)(void *, char);

//----- (004E1370) --------------------------------------------------------  // acclient.c:271465
void __cdecl UIElement_UIItem::Register()
{
  UIElement::RegisterElementClass(
    0x10000032u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_UIItem::Create);
}

//----- (004E1390) --------------------------------------------------------  // acclient.c:271473
int __thiscall UIElement_UIItem::ListenToElementMessage(UIElement_UIItem *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement_UIItem *v3; // esi@1
  UIElement *v4; // edi@3
  UIElement *v5; // ecx@4
  int v7; // eax@7
  UIElement_ItemList *v8; // eax@8
  UIElement *v9; // ecx@10
  int v10; // eax@14
  UIElement_ItemList *v11; // eax@15
  ACCWeenieObject *v12; // ecx@18
  UIElement *v13; // ecx@20

  v2 = i_rMsg->idMessage;
  v3 = this;
  switch ( v2 )
  {
    case 0x3Eu:
      if ( i_rMsg->dwParam1 )
      {
        v4 = UIElementManager::s_pInstance->m_dragElement;
        if ( v4 )
        {
          v7 = ((int (*)(void))this->vfptr[13].OnAction)();
          if ( v7 )
          {
            v8 = (UIElement_ItemList *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v7 + 148))(v7, 268435505);
            if ( v8 )
            {
              UIElement_ItemList::ItemList_DragOver(v8, v4, v3);
              return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
            }
          }
        }
        else
        {
          v5 = this->m_elem_Icon_DragAccept;
          if ( v5 && v5->m_state != 268435519 )
          {
            ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(268435519);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          }
        }
      }
      else
      {
        v9 = this->m_elem_Icon_DragAccept;
        if ( v9 && v9->m_state != 268435519 )
        {
          ((void (__stdcall *)(signed int))v9->vfptr[13].__vecDelDtor)(268435519);
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
      }
      break;
    case 0x21u:
      v10 = ((int (*)(void))this->vfptr[13].OnAction)();
      if ( v10 )
      {
        v11 = (UIElement_ItemList *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v10 + 148))(v10, 268435505);
        if ( v11 )
        {
          UIElement_ItemList::ItemList_BeginDrag(v11, i_rMsg->ptWindow.x, i_rMsg->ptWindow.y);
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
      }
      break;
    case 0x15u:
      v12 = this->weenObj;
      if ( v12 )
      {
        ACCWeenieObject::SetWaitingState(v12, 0);
        if ( !v3->unghostable )
        {
          v13 = v3->m_elem_Icon_Ghosted;
          if ( v13 )
            ((void (__stdcall *)(_DWORD))v13->vfptr[2].__vecDelDtor)(0);
        }
      }
      break;
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (004E1500) --------------------------------------------------------  // acclient.c:271558
char __thiscall UIElement_UIItem::UIItem_SetState(UIElement_UIItem *this, unsigned int _state)
{
  UIElement_UIItem *v2; // esi@1
  UIElement *v3; // ecx@1
  char result; // al@2
  UIElement_Text *v5; // ecx@3
  UIElement *v6; // ecx@5
  UIElement *v7; // ecx@8

  v2 = this;
  v3 = this->m_elem_Icon;
  if ( v3 )
  {
    ((void (__stdcall *)(unsigned int))v3->vfptr[13].__vecDelDtor)(_state);
    v5 = v2->m_elem_Text;
    if ( v5 )
      ((void (__stdcall *)(unsigned int))v5->vfptr[13].__vecDelDtor)(_state);
    v6 = v2->m_elem_Icon_Overlays;
    if ( v6 )
      ((void (__stdcall *)(unsigned int))v6->vfptr[13].__vecDelDtor)(_state);
    if ( _state == 268435484 )
    {
      *((_DWORD *)&v2->0 + 41) &= 0xFFFFFFDF;
      v2->isContainer = 0;
      UIElement::ClearTooltip((UIElement *)&v2->vfptr);
      v7 = v2->m_elem_Icon_Selected;
      v2->selected = 0;
      if ( v7 )
        ((void (__stdcall *)(_DWORD))v7->vfptr[2].__vecDelDtor)(0);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004E1590) --------------------------------------------------------  // acclient.c:271598
void __thiscall UIElement_UIItem::SetShortcutNum(UIElement_UIItem *this, int _shortcutNum, bool _ghosted)
{
  UIElement_UIItem *v3; // esi@1
  UIElement *v4; // ecx@1
  int v5; // edi@1
  UIElement *v6; // eax@4
  char v7; // al@6
  BasePropertyDesc *v8; // ecx@18
  unsigned int v9; // edx@18
  BasePropertyValue *v10; // ecx@22
  unsigned int v11; // edx@22
  bool v12; // al@24
  ACCWeenieObject *v13; // ecx@25
  BaseProperty shortcutArrayProp; // [sp+1Ch] [bp-10h]@4
  BaseProperty iconProp; // [sp+24h] [bp-8h]@11

  v3 = this;
  v4 = this->m_elem_Icon_ShortcutNum;
  v5 = _shortcutNum;
  if ( v4 )
  {
    if ( _shortcutNum >= 0 )
    {
      v6 = v3->m_elem_Icon;
      shortcutArrayProp.m_pcPropertyDesc = 0;
      shortcutArrayProp.m_pcPropertyValue = 0;
      if ( v6 && v6->m_state == 268435484 )
      {
        v7 = ((int (__stdcall *)(signed int, BaseProperty *))v4->vfptr[17].OnAction)(268435550, &shortcutArrayProp);
      }
      else if ( _ghosted )
      {
        v7 = ((int (__stdcall *)(signed int, BaseProperty *))v4->vfptr[17].OnAction)(268435523, &shortcutArrayProp);
      }
      else
      {
        v7 = ((int (__stdcall *)(signed int, BaseProperty *))v4->vfptr[17].OnAction)(268435522, &shortcutArrayProp);
      }
      if ( v7 )
      {
        iconProp.m_pcPropertyDesc = 0;
        iconProp.m_pcPropertyValue = 0;
        if ( shortcutArrayProp.m_pcPropertyValue
          && (unsigned __int8)((int (__stdcall *)(int, BaseProperty *))shortcutArrayProp.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                                v5,
                                &iconProp) )
        {
          _shortcutNum = stru_840604.id;
          if ( iconProp.m_pcPropertyValue )
            ((void (__stdcall *)(int *))iconProp.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&_shortcutNum);
          UIElement::SetMediaImage(v3->m_elem_Icon_ShortcutNum, (IDClass<_tagDataID,32,0>)_shortcutNum, 3u);
        }
        ((void (__stdcall *)(signed int))v3->m_elem_Icon_ShortcutNum->vfptr[2].__vecDelDtor)(1);
        BaseProperty::~BaseProperty(&iconProp);
      }
      if ( (_DWORD)shortcutArrayProp.m_pcPropertyDesc )
      {
        v8 = shortcutArrayProp.m_pcPropertyDesc;
        v9 = shortcutArrayProp.m_pcPropertyDesc->m_cRef - 1;
        shortcutArrayProp.m_pcPropertyDesc->m_cRef = v9;
        if ( !v9 )
          ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
        shortcutArrayProp.m_pcPropertyDesc = 0;
      }
      if ( shortcutArrayProp.m_pcPropertyValue )
      {
        v10 = shortcutArrayProp.m_pcPropertyValue;
        v11 = shortcutArrayProp.m_pcPropertyValue->m_cRef - 1;
        shortcutArrayProp.m_pcPropertyValue->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      }
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v4->vfptr[2].__vecDelDtor)(0);
    }
    v12 = _ghosted;
    v3->m_shortcutNum = v5;
    v3->m_shortcutGhosted = v12;
  }
  v13 = v3->weenObj;
  if ( v13 )
    ACCWeenieObject::SetShortcutNum(v13, v5, _ghosted);
}

//----- (004E16E0) --------------------------------------------------------  // acclient.c:271685
void __thiscall UIElement_UIItem::UpdateCapacityDisplay(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIElement_Meter *v2; // ecx@1
  ACCWeenieObject *v3; // eax@2
  signed int v4; // ST20_4@5
  signed int v5; // ST1C_4@5
  UIElement_Meter *v6; // ecx@5
  UIElement *v7; // esi@7
  float _val; // ST14_4@8
  long double curLevel; // [sp+10h] [bp-8h]@5

  v1 = this;
  v2 = this->m_elem_Icon_CapacityBar;
  if ( v2 )
  {
    v3 = v1->weenObj;
    if ( v3 )
    {
      if ( v1->isContainer && v3->pwd._itemsCapacity > 0 )
      {
        v4 = v3->pwd._itemsCapacity;
        v5 = ACCWeenieObject::GetNumContainedItems(v1->weenObj);
        v6 = v1->m_elem_Icon_CapacityBar;
        curLevel = (double)v5 / (double)v4;
        if ( curLevel == 0.0 )
        {
          ((void (__stdcall *)(_DWORD))v6->vfptr[2].__vecDelDtor)(0);
        }
        else
        {
          ((void (__stdcall *)(signed int))v6->vfptr[2].__vecDelDtor)(1);
          v7 = (UIElement *)&v1->m_elem_Icon_CapacityBar->vfptr;
          if ( v7 )
          {
            _val = MathLib::Clamp(curLevel, 0.0, 1.0);
            UIElement::SetAttribute_Float(v7, 0x69u, _val);
          }
        }
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
      }
    }
  }
}

//----- (004E17A0) --------------------------------------------------------  // acclient.c:271734
void __thiscall UIElement_UIItem::UpdateStructureDisplay(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIElement_Meter *v2; // ecx@1
  ACCWeenieObject *v3; // eax@2
  unsigned int v4; // edx@3
  UIElement *v5; // esi@6
  float _val; // ST14_4@7
  long double curLevel; // [sp+Ch] [bp-8h]@4

  v1 = this;
  v2 = this->m_elem_Icon_StructureBar;
  if ( v2 )
  {
    v3 = v1->weenObj;
    if ( v3 )
    {
      v4 = v3->pwd._maxStructure;
      if ( v4 )
      {
        curLevel = (double)v3->pwd._structure / (double)v4;
        if ( curLevel == 1.0 )
        {
          ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
        }
        else
        {
          ((void (__stdcall *)(signed int))v2->vfptr[2].__vecDelDtor)(1);
          v5 = (UIElement *)&v1->m_elem_Icon_StructureBar->vfptr;
          if ( v5 )
          {
            _val = MathLib::Clamp(curLevel, 0.0, 1.0);
            UIElement::SetAttribute_Float(v5, 0x69u, _val);
          }
        }
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
      }
    }
  }
}

//----- (004E1870) --------------------------------------------------------  // acclient.c:271779
void __thiscall UIElement_UIItem::PostInit(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  int v10; // eax@13
  int v11; // ebx@13
  ElementDesc *v12; // eax@14
  BasePropertyDesc *v13; // ecx@21
  unsigned int v14; // esi@21
  BasePropertyValue *v15; // ecx@25
  unsigned int v16; // edx@25
  BasePropertyDesc *v17; // ecx@29
  unsigned int v18; // esi@29
  BasePropertyValue *v19; // ecx@33
  unsigned int v20; // edx@33
  BasePropertyDesc *v21; // ecx@37
  unsigned int v22; // esi@37
  BasePropertyValue *v23; // ecx@41
  unsigned int v24; // edx@41
  BaseProperty dragoutProp; // [sp+24h] [bp-18h]@18
  BaseProperty dragableProp; // [sp+2Ch] [bp-10h]@16
  BaseProperty containerProp; // [sp+34h] [bp-8h]@14

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_elem_Icon = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000033Bu);
  v1->m_elem_Icon_Overlays = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000033Cu);
  v1->m_elem_Icon_Selected = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000342u);
  v1->m_elem_Icon_Ghosted = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000349u);
  v1->m_elem_Icon_ShortcutNum = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000034Au);
  v1->m_elem_Icon_SellState = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000437u);
  v1->m_elem_Icon_TradeState = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000438u);
  v1->m_elem_Icon_OpenContainer = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000450u);
  v1->m_elem_Icon_DragAccept = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000045Au);
  v1->m_elem_Icon_Ghosted = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000349u);
  v1->m_elem_Icon_Cooldown_10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000054Fu);
  v1->m_elem_Icon_Cooldown_20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000550u);
  v1->m_elem_Icon_Cooldown_30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000551u);
  v1->m_elem_Icon_Cooldown_40 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000552u);
  v1->m_elem_Icon_Cooldown_50 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000553u);
  v1->m_elem_Icon_Cooldown_60 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000554u);
  v1->m_elem_Icon_Cooldown_70 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000555u);
  v1->m_elem_Icon_Cooldown_80 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000556u);
  v1->m_elem_Icon_Cooldown_90 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000557u);
  v1->m_elem_Icon_Cooldown_100 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000558u);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000347u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)7);
  else
    v3 = 0;
  v1->m_elem_Icon_CapacityBar = (UIElement_Meter *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000348u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)7);
  else
    v5 = 0;
  v1->m_elem_Icon_StructureBar = (UIElement_Meter *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000344u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
  else
    v7 = 0;
  v1->m_elem_Text = (UIElement_Text *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100004F5u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_elem_Icon_Quantity = (UIElement_Text *)v9;
  v10 = DBObj::GetByEnum(268435512, 5, 0x23u);
  v11 = v10;
  if ( v10 )
  {
    v12 = UIElementManager::CreateChildElement(
            UIElementManager::s_pInstance,
            (UIElement *)&v1->vfptr,
            (LayoutDesc *)v10,
            0x10000345u);
    v1->m_dragIcon = (UIElement *)v12;
    ((void (__thiscall *)(ElementDesc *, _DWORD))v12->vfptr->HandleNode)(v12, 0);
    ((void (__thiscall *)(UIElement_UIItem *, signed int))v1->vfptr[22].OnLoseFocus)(v1, 1);
    containerProp.m_pcPropertyDesc = 0;
    containerProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&containerProp, 0x36u);
    if ( containerProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&containerProp);
      ((void (__stdcall *)(_DWORD))containerProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    ((void (__thiscall *)(UIElement_UIItem *, BaseProperty *))v1->vfptr[17].OnLoseFocus)(v1, &containerProp);
    dragableProp.m_pcPropertyDesc = 0;
    dragableProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&dragableProp, 0x3Au);
    if ( dragableProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&dragableProp);
      ((void (__stdcall *)(_DWORD))dragableProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(0);
    }
    ((void (__thiscall *)(_DWORD, _DWORD))v1->vfptr[17].OnLoseFocus)(v1, &dragableProp);
    dragoutProp.m_pcPropertyDesc = 0;
    dragoutProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&dragoutProp, 0x39u);
    if ( dragoutProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&dragoutProp);
      ((void (__stdcall *)(_DWORD))dragoutProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(0);
    }
    ((void (__thiscall *)(_DWORD, _DWORD))v1->vfptr[17].OnLoseFocus)(v1, &dragoutProp);
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    if ( (_DWORD)dragoutProp.m_pcPropertyDesc )
    {
      v13 = dragoutProp.m_pcPropertyDesc;
      v14 = dragoutProp.m_pcPropertyDesc->m_cRef - 1;
      dragoutProp.m_pcPropertyDesc->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
      dragoutProp.m_pcPropertyDesc = 0;
    }
    if ( dragoutProp.m_pcPropertyValue )
    {
      v15 = dragoutProp.m_pcPropertyValue;
      v16 = dragoutProp.m_pcPropertyValue->m_cRef - 1;
      dragoutProp.m_pcPropertyValue->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
      dragoutProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)dragableProp.m_pcPropertyDesc )
    {
      v17 = dragableProp.m_pcPropertyDesc;
      v18 = dragableProp.m_pcPropertyDesc->m_cRef - 1;
      dragableProp.m_pcPropertyDesc->m_cRef = v18;
      if ( !v18 )
        ((void (__stdcall *)(_DWORD))v17->vfptr->__vecDelDtor)(1);
      dragableProp.m_pcPropertyDesc = 0;
    }
    if ( dragableProp.m_pcPropertyValue )
    {
      v19 = dragableProp.m_pcPropertyValue;
      v20 = dragableProp.m_pcPropertyValue->m_cRef - 1;
      dragableProp.m_pcPropertyValue->m_cRef = v20;
      if ( !v20 )
        ((void (__stdcall *)(_DWORD))v19->vfptr->__vecDelDtor)(1);
      dragableProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)containerProp.m_pcPropertyDesc )
    {
      v21 = containerProp.m_pcPropertyDesc;
      v22 = containerProp.m_pcPropertyDesc->m_cRef - 1;
      containerProp.m_pcPropertyDesc->m_cRef = v22;
      if ( !v22 )
        ((void (__stdcall *)(_DWORD))v21->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyDesc = 0;
    }
    if ( containerProp.m_pcPropertyValue )
    {
      v23 = containerProp.m_pcPropertyValue;
      v24 = containerProp.m_pcPropertyValue->m_cRef - 1;
      containerProp.m_pcPropertyValue->m_cRef = v24;
      if ( !v24 )
        ((void (__stdcall *)(_DWORD))v23->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyValue = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
  }
}

//----- (004E1C70) --------------------------------------------------------  // acclient.c:271954
char __thiscall UIElement_UIItem::InqAvailableProperties(UIElement_UIItem *this, AvailablePropertySet *_set)
{
  char v2; // bl@1
  char result; // al@4

  v2 = 1;
  if ( !UIElement_Field::InqAvailableProperties((UIElement_Field *)&this->vfptr, _set) )
    v2 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  if ( _set )
  {
    ((void (*)(void))_set->m_reqHash.vfptr[5].__vecDelDtor)();
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004E1CB0) --------------------------------------------------------  // acclient.c:271976
void __thiscall UIElement_UIItem::UpdateTooltip(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // edi@1
  unsigned int v2; // eax@1
  HashBaseData<unsigned long> *v3; // eax@2
  HashBaseData<unsigned long> *v4; // esi@2
  signed int v5; // eax@3
  unsigned int v6; // esi@5
  char *v7; // esi@8
  PStringBase<unsigned short> strTooltip; // [sp+4h] [bp-94h]@5
  StringInfo siTooltip; // [sp+8h] [bp-90h]@8

  v1 = this;
  v2 = this->itemID;
  if ( v2 )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(v2);
    v4 = v3;
    if ( v3 )
    {
      v5 = v3[20].id;
      if ( !v5 )
        v5 = 1;
      ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &strTooltip, (NameType)(2 - ((unsigned int)v5 > 1)), 0);
      v6 = v4[20].id;
      if ( v6 && v6 > 1 )
        PStringBase<unsigned short>::sprintf(&strTooltip, L"%d %s", v6, strTooltip.m_charbuffer);
      StringInfo::StringInfo(&siTooltip);
      StringInfo::SetLiteralValue(&siTooltip, &strTooltip, 1);
      UIElement::SetTooltip((UIElement *)&v1->vfptr, &siTooltip);
      *((_DWORD *)&v1->0 + 41) |= 0x20u;
      StringInfo::~StringInfo(&siTooltip);
      v7 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      }
    }
  }
}

//----- (004E1DA0) --------------------------------------------------------  // acclient.c:272019
void __thiscall UIElement_UIItem::UpdateQuantityDisplay(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIElement_Text *v2; // ecx@1
  char *v3; // esi@3
  PStringBase<unsigned short> strQuantity; // [sp+4h] [bp-4h]@1

  strQuantity.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  v2 = this->m_elem_Icon_Quantity;
  if ( v2 )
  {
    if ( v1->m_quantity < 0 )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&strQuantity, 0, L"%d", v1->m_quantity);
      UIElement_Text::SetText(v1->m_elem_Icon_Quantity, &strQuantity);
      ((void (__stdcall *)(signed int))v1->m_elem_Icon_Quantity->vfptr[2].__vecDelDtor)(1);
      v3 = (char *)&strQuantity.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strQuantity.m_charbuffer[-1].m_data[8]) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
    }
  }
}

//----- (004E1E20) --------------------------------------------------------  // acclient.c:272051
void __thiscall UIElement_UIItem::UpdateCooldownDisplay(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // ebx@1
  int v2; // eax@2
  signed int v3; // esi@2
  signed int v4; // ebp@2
  int v5; // edx@3
  int v6; // edi@3
  InterfacePtr<Interface> *v7; // eax@4
  PlayerDesc *v8; // esi@6
  UIElement *v9; // ecx@15
  UIElement *v10; // ecx@21
  UIElement *v11; // ecx@27
  UIElement *v12; // ecx@33
  UIElement *v13; // ecx@39
  UIElement *v14; // ecx@45
  UIElement *v15; // ecx@51
  UIElement *v16; // ecx@57
  UIElement *v17; // ecx@63
  UIElement *v18; // ecx@69
  int cooldown_phase; // [sp+4h] [bp-24h]@2
  long double time_left; // [sp+8h] [bp-20h]@2
  long double cooldown_duration; // [sp+10h] [bp-18h]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+18h] [bp-10h]@4
  InterfacePtr<Interface> result; // [sp+20h] [bp-8h]@4

  v1 = this;
  if ( this->m_elem_Icon_StructureBar )
  {
    v2 = (int)this->weenObj;
    v3 = 0;
    v4 = 0;
    time_left = 0.0;
    cooldown_phase = 0;
    if ( v2 )
    {
      v5 = *(_DWORD *)(v2 + 316);
      v6 = *(_DWORD *)(v2 + 308);
      LODWORD(cooldown_duration) = *(_DWORD *)(v2 + 312);
      HIDWORD(cooldown_duration) = v5;
      if ( v6 > 0 )
      {
        v7 = GetClassObject(&result, &PlayerDesc_ClassType_20);
        InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&spPlayerDesc, v7);
        if ( (_DWORD)result.m_pInterface )
          v2 = ((int (*)(void))result.m_pInterface->vfptr->Release)();
        v8 = spPlayerDesc.m_pInterface;
        if ( (_DWORD)spPlayerDesc.m_pInterface )
        {
          if ( (spPlayerDesc.m_trStatus.m_val & 0x80000000) == 0
            && CACQualities::HasEnchantmentRegistry((CACQualities *)&spPlayerDesc.m_pInterface->vfptr)
            && CEnchantmentRegistry::OnCooldown(v8->_enchantment_reg, v6 + 0x8000, &time_left) )
          {
            if ( cooldown_duration > 0.0 )
              cooldown_phase = (unsigned __int64)(time_left / cooldown_duration * 100.0 * 0.1 + 1.0);
            v4 = 1;
          }
          v2 = v8->vfptr->Release((Interface *)v8);
        }
        v3 = cooldown_phase;
      }
    }
    v9 = v1->m_elem_Icon_Cooldown_10;
    if ( v9 )
    {
      LOBYTE(v2) = v4 && v3 == 1;
      v2 = ((int (__stdcall *)(int))v9->vfptr[2].__vecDelDtor)(v2);
    }
    v10 = v1->m_elem_Icon_Cooldown_20;
    if ( v10 )
    {
      LOBYTE(v2) = v4 && v3 == 2;
      v2 = ((int (__stdcall *)(int))v10->vfptr[2].__vecDelDtor)(v2);
    }
    v11 = v1->m_elem_Icon_Cooldown_30;
    if ( v11 )
    {
      LOBYTE(v2) = v4 && v3 == 3;
      v2 = ((int (__stdcall *)(int))v11->vfptr[2].__vecDelDtor)(v2);
    }
    v12 = v1->m_elem_Icon_Cooldown_40;
    if ( v12 )
    {
      LOBYTE(v2) = v4 && v3 == 4;
      v2 = ((int (__stdcall *)(int))v12->vfptr[2].__vecDelDtor)(v2);
    }
    v13 = v1->m_elem_Icon_Cooldown_50;
    if ( v13 )
    {
      LOBYTE(v2) = v4 && v3 == 5;
      v2 = ((int (__stdcall *)(int))v13->vfptr[2].__vecDelDtor)(v2);
    }
    v14 = v1->m_elem_Icon_Cooldown_60;
    if ( v14 )
    {
      LOBYTE(v2) = v4 && v3 == 6;
      v2 = ((int (__stdcall *)(int))v14->vfptr[2].__vecDelDtor)(v2);
    }
    v15 = v1->m_elem_Icon_Cooldown_70;
    if ( v15 )
    {
      LOBYTE(v2) = v4 && v3 == 7;
      v2 = ((int (__stdcall *)(int))v15->vfptr[2].__vecDelDtor)(v2);
    }
    v16 = v1->m_elem_Icon_Cooldown_80;
    if ( v16 )
    {
      LOBYTE(v2) = v4 && v3 == 8;
      v2 = ((int (__stdcall *)(int))v16->vfptr[2].__vecDelDtor)(v2);
    }
    v17 = v1->m_elem_Icon_Cooldown_90;
    if ( v17 )
    {
      LOBYTE(v2) = v4 && v3 == 9;
      v2 = ((int (__stdcall *)(int))v17->vfptr[2].__vecDelDtor)(v2);
    }
    v18 = v1->m_elem_Icon_Cooldown_100;
    if ( v18 )
    {
      if ( v4 && v3 >= 10 )
      {
        LOBYTE(v2) = 1;
        ((void (__stdcall *)(int))v18->vfptr[2].__vecDelDtor)(v2);
      }
      else
      {
        LOBYTE(v2) = 0;
        ((void (__stdcall *)(int))v18->vfptr[2].__vecDelDtor)(v2);
      }
    }
  }
}

//----- (004E2080) --------------------------------------------------------  // acclient.c:272185
char __thiscall UIElement_UIItem::UIItem_SetIcon(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIRegion *v2; // ecx@1
  ClientMagicSystem *v4; // ebx@4
  Graphic *v5; // edi@6
  Graphic *v6; // eax@7
  Graphic *v7; // eax@8
  AC1Legacy::PStringBase<char> *v8; // eax@12
  PStringBase<unsigned short> *v9; // eax@12
  HashBaseData<unsigned long> *v10; // ebx@13
  Graphic *v11; // edi@14
  Graphic *v12; // eax@15
  Graphic *v13; // eax@15
  PStringBase<unsigned short> v14; // [sp+4h] [bp-8h]@12
  AC1Legacy::PStringBase<char> result; // [sp+8h] [bp-4h]@12

  v1 = this;
  v2 = (UIRegion *)&this->m_elem_Icon->vfptr;
  if ( !v2 )
    return 0;
  if ( v1->spellID )
  {
    UIRegion::ClearImage(v2);
    v4 = ClientMagicSystem::GetMagicSystem();
    if ( !v4 )
      return 0;
    v5 = ClientMagicSystem::GetSpellIcon(v4, v1->spellID);
    if ( v5 )
    {
      UIRegion::SetBlitMode((UIRegion *)&v1->m_elem_Icon->vfptr, Blit_3Alpha);
      v6 = (Graphic *)operator new(0xCu);
      if ( v6 )
        Graphic::Graphic(v6, v5);
      else
        v7 = 0;
      UIRegion::SetImage((UIRegion *)&v1->m_elem_Icon->vfptr, v7);
    }
    if ( v1->m_elem_Text )
    {
      v8 = ClientMagicSystem::GetSpellName(v4, &result, v1->spellID);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v14, 0, v8->m_buffer->m_data);
      UIElement_Text::SetText(v1->m_elem_Text, v9);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v14);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&result);
      return 1;
    }
  }
  else
  {
    v10 = ClientObjMaintSystem::GetWeenieObject(v1->itemID);
    if ( v10 )
    {
      UIRegion::ClearImage((UIRegion *)&v1->m_elem_Icon->vfptr);
      UIRegion::SetBlitMode((UIRegion *)&v1->m_elem_Icon->vfptr, 0);
      v11 = (Graphic *)operator new(0xCu);
      if ( v11 )
      {
        v12 = ACCWeenieObject::GetIcon((ACCWeenieObject *)v10);
        Graphic::Graphic(v11, v12);
      }
      else
      {
        v13 = 0;
      }
      UIRegion::SetImage((UIRegion *)&v1->m_elem_Icon->vfptr, v13);
    }
  }
  return 1;
}

//----- (004E21D0) --------------------------------------------------------  // acclient.c:272257
void __thiscall UIElement_UIItem::UIItem_Update(UIElement_UIItem *this)
{
  UIElement_UIItem *v1; // esi@1
  UIElement *v2; // ecx@5
  UIElement_Text *v3; // ecx@6
  UIElement *v4; // ecx@8
  int v5; // eax@10
  UIElement *v6; // ecx@13
  ACCWeenieObject *v7; // eax@15
  unsigned int v8; // ecx@15
  unsigned int v9; // ecx@22
  ACCWeenieObject *v10; // edx@32
  int v11; // eax@32
  int v12; // ST08_4@33
  int v13; // eax@34
  ACCWeenieObject *v14; // eax@36
  int v15; // ecx@36
  int v16; // eax@39
  UIElement *v17; // ecx@40
  bool v18; // bl@40
  int v19; // eax@43
  UIElement *v20; // ecx@44
  bool v21; // bl@44
  UIElement_UIItem *v22; // [sp+14h] [bp-4h]@1

  v22 = this;
  v1 = this;
  if ( this->itemID )
    this->weenObj = (ACCWeenieObject *)ClientObjMaintSystem::GetWeenieObject(this->itemID);
  else
    this->weenObj = 0;
  if ( v1->weenObj )
  {
    v2 = v1->m_elem_Icon;
    if ( v2 )
    {
      ((void (__stdcall *)(signed int))v2->vfptr[13].__vecDelDtor)(268435485);
      v3 = v1->m_elem_Text;
      if ( v3 )
        ((void (__stdcall *)(signed int))v3->vfptr[13].__vecDelDtor)(268435485);
      v4 = v1->m_elem_Icon_Overlays;
      if ( v4 )
        ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(268435485);
    }
    UIElement_UIItem::UIItem_SetIcon(v1);
    v5 = v1->weenObj->selected;
    if ( v1->selected != v5 )
    {
      v1->selected = v5;
      if ( !v5 || v1->m_selectable )
      {
        v6 = v1->m_elem_Icon_Selected;
        v1->selected = v5;
        if ( v6 )
        {
          LOBYTE(v5) = v5 != 0;
          ((void (__stdcall *)(int))v6->vfptr[2].__vecDelDtor)(v5);
        }
      }
    }
    v7 = v1->weenObj;
    v8 = v7->pwd._effects;
    if ( v1->effects != v8 )
      v1->effects = v8;
    v1->isOpenable = (v7->pwd._bitfield & (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)"
                   || v7->pwd._itemsCapacity
                   || v7->pwd._containersCapacity)
                  && v7->pwd._bitfield & 1
                  || (!SmartBox::smartbox ? (v9 = 0) : (v9 = SmartBox::smartbox->player_id), v1->itemID == v9);
    v1->isContainer = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v7->pwd._bitfield
                   || v7->pwd._itemsCapacity
                   || v7->pwd._containersCapacity;
    v1->isContainerHolder = v7->pwd._containersCapacity != 0;
    UIElement_UIItem::UpdateCapacityDisplay(v1);
    UIElement_UIItem::UpdateStructureDisplay(v1);
    UIElement_UIItem::UpdateQuantityDisplay(v1);
    UIElement_UIItem::UpdateCooldownDisplay(v1);
    v10 = v1->weenObj;
    v11 = v10->waiting;
    if ( v1->waiting != v11 )
    {
      v12 = v10->waiting;
      v1->waiting = v11;
      UIElement_UIItem::SetWaitingState(v1, v12);
    }
    v13 = v1->m_delayedShortcutNum;
    if ( v13 != -1 )
    {
      ACCWeenieObject::SetShortcutNum(v1->weenObj, v13, 0);
      v1->m_delayedShortcutNum = -1;
    }
    v14 = v1->weenObj;
    v15 = v14->shortcutNum;
    if ( v1->m_shortcutNum != v15 || v1->m_shortcutGhosted != v14->m_bShortcutGhosted )
      UIElement_UIItem::SetShortcutNum(v1, v15, v14->m_bShortcutGhosted);
    v16 = v1->weenObj->sellState;
    if ( v1->m_sellState != v16 )
    {
      v17 = v1->m_elem_Icon_SellState;
      v18 = v16 != 0;
      if ( v17 )
      {
        LOBYTE(v22) = v16 != 0;
        ((void (__stdcall *)(UIElement_UIItem *))v17->vfptr[2].__vecDelDtor)(v22);
      }
      v1->m_sellState = v18;
    }
    v19 = v1->weenObj->tradeState;
    if ( v1->m_tradeState != v19 )
    {
      v20 = v1->m_elem_Icon_TradeState;
      v21 = v19 != 0;
      if ( v20 )
      {
        LOBYTE(v22) = v19 != 0;
        ((void (__stdcall *)(UIElement_UIItem *))v20->vfptr[2].__vecDelDtor)(v22);
      }
      v1->m_tradeState = v21;
    }
    UIElement_UIItem::UpdateTooltip(v1);
  }
  else if ( v1->spellID )
  {
    UIElement_UIItem::UIItem_SetState(v1, 0x1000001Du);
    UIElement_UIItem::UIItem_SetIcon(v1);
  }
  else
  {
    UIElement_UIItem::UIItem_SetState(v1, 0x1000001Cu);
    *((_DWORD *)&v1->0 + 41) &= 0xFFFFFFDF;
    UIElement::ClearTooltip((UIElement *)&v1->vfptr);
  }
}

//----- (006F60C0) --------------------------------------------------------  // acclient.c:778708
void sub_6F60C0()
{
  flt_840608 = 1000.0 + 1.0;
}

//----- (006F60E0) --------------------------------------------------------  // acclient.c:778714
void _E93_89()
{
  flt_84060C = 24.0 * 8.0;
}

//----- (006F6100) --------------------------------------------------------  // acclient.c:778720
void _E95_89()
{
  flt_840610 = 24.0 * 0.5;
}

//----- (006F6120) --------------------------------------------------------  // acclient.c:778726
int sub_6F6120()
{
  return atexit(nullsub_984);
}

//----- (006F6130) --------------------------------------------------------  // acclient.c:778732
int sub_6F6130()
{
  return atexit(nullsub_985);
}

//----- (006F6140) --------------------------------------------------------  // acclient.c:778738
int sub_6F6140()
{
  return atexit(nullsub_986);
}

//----- (006F6150) --------------------------------------------------------  // acclient.c:778744
void _E109_43()
{
  DEFAULT_VIEW_RADIUS_73 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6170) --------------------------------------------------------  // acclient.c:778750
void _E111_30()
{
  MIN_QUANTUM_73 = 1.0 / 30.0;
}

//----- (006F6190) --------------------------------------------------------  // acclient.c:778756
void _E113_18()
{
  MAX_QUANTUM_73 = 1.0 / 5.0;
}

//----- (006F61B0) --------------------------------------------------------  // acclient.c:778762
void _E115_47()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840628, PFID_A8R8G8B8);
}

//----- (006F61C0) --------------------------------------------------------  // acclient.c:778768
int _E117_45()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_38, "Misc.TooltipEnable");
  return atexit(sub_763030);
}

//----- (006F61E0) --------------------------------------------------------  // acclient.c:778775
int _E120_37()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_38, "Misc.TooltipDelay");
  return atexit(sub_763060);
}

//----- (006F6200) --------------------------------------------------------  // acclient.c:778782
void _E124_45()
{
  LOWEST_DATA_RATE_98 = 1024;
}

//----- (006F6210) --------------------------------------------------------  // acclient.c:778788
void _E126_20()
{
  HIGHEST_DATA_RATE_98 = 0x7FFF;
}

//----- (006F6220) --------------------------------------------------------  // acclient.c:778794
int _E128_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_98;
  INITIAL_MAX_DATA_RATE_46 = LOWEST_DATA_RATE_98;
  return result;
}

//----- (006F6230) --------------------------------------------------------  // acclient.c:778804
int _E130_33()
{
  return atexit(_E131_39);
}

//----- (006F6240) --------------------------------------------------------  // acclient.c:778810
int sub_6F6240()
{
  return atexit(nullsub_983);
}

//----- (00763030) --------------------------------------------------------  // acclient.c:889834
void __cdecl sub_763030()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763060) --------------------------------------------------------  // acclient.c:889847
void __cdecl sub_763060()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

