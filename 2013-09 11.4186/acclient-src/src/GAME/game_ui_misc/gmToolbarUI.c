/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmToolbarUI
   Object     : GAME\game_ui_misc\gmToolbarUI.obj
   Functions  : 65
   Addresses  : 004BD0C0 - 007613C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BD0C0) --------------------------------------------------------  // acclient.c:239815
void __thiscall gmToolbarUI::RecvNotice_UpdateItemMana(gmToolbarUI *this, unsigned int i_iidTarget, float i_fMana, bool i_bSuccess)
{
  gmToolbarUI *v4; // esi@1
  HashSetData<UIElement *> *v5; // ecx@4

  v4 = this;
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11] == (HashSetData<UIElement *> *)i_iidTarget )
  {
    if ( i_bSuccess )
    {
      v5 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7];
      if ( !(((unsigned int)v5[20].m_hashNext >> 1) & 1) )
        ((void (__stdcall *)(signed int))v5->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
      UIElement::SetAttribute_Float(
        (UIElement *)&v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7]->m_hashKey,
        0x69u,
        i_fMana);
    }
    else
    {
      CM_Item::Event_QueryItemMana(0);
    }
  }
}

//----- (004BD110) --------------------------------------------------------  // acclient.c:239841
void __thiscall gmToolbarUI::RecvNotice_UpdateObjectHealth(gmToolbarUI *this, unsigned int i_iidTarget, float i_fHealth)
{
  gmToolbarUI *v3; // esi@1
  HashSetData<UIElement *> *v4; // ecx@2

  v3 = this;
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11] == (HashSetData<UIElement *> *)i_iidTarget )
  {
    v4 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6];
    if ( !(((unsigned int)v4[20].m_hashNext >> 1) & 1) )
      ((void (__stdcall *)(signed int))v4->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
    UIElement::SetAttribute_Float(
      (UIElement *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]->m_hashKey,
      0x69u,
      i_fHealth);
  }
}

//----- (004BD150) --------------------------------------------------------  // acclient.c:239860
char __stdcall gmToolbarUI::OnItemListDragOver(UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && (!(_dropFlags & 0xE) || _dropFlags & 4) )
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
  return 1;
}

//----- (004BD180) --------------------------------------------------------  // acclient.c:239868
void __thiscall gmToolbarUI::HandleInventoryButtonDragOver(gmToolbarUI *this, UIElement *_dragElement)
{
  gmToolbarUI *v2; // esi@1
  DropItemFlags dropFlags; // [sp+4h] [bp-8h]@1
  unsigned int dropSpellID; // [sp+8h] [bp-4h]@1

  v2 = this;
  UIElement_ItemList::InqDropIconInfo(_dragElement, (unsigned int *)&_dragElement, &dropSpellID, &dropFlags);
  if ( _dragElement )
  {
    if ( !(dropFlags & 0xE) )
      ((void (__stdcall *)(signed int))v2->m_pInventoryButtonDragOverlay->vfptr[13].__vecDelDtor)(268435526);
  }
}

//----- (004BD1D0) --------------------------------------------------------  // acclient.c:239884
bool __stdcall gmToolbarUI::IsShortcutEligible(ACCWeenieObject *_weenObj)
{
  unsigned int v2; // esi@6
  bool result; // al@8

  result = 0;
  if ( _weenObj
    && (!(_weenObj->pwd._bitfield & 4)
     || ((int (__thiscall *)(ACCWeenieObject *))_weenObj->vfptr[4].__vecDelDtor)(_weenObj))
    && (!(((int (__thiscall *)(ACCWeenieObject *))_weenObj->vfptr[6].__vecDelDtor)(_weenObj) & 0x10)
     || ((int (__thiscall *)(ACCWeenieObject *))_weenObj->vfptr[4].__vecDelDtor)(_weenObj)) )
  {
    v2 = _weenObj->pwd._containerID;
    if ( !v2 || v2 != ClientUISystem::GetUISystem()->vendorID )
      result = 1;
  }
  return result;
}

//----- (004BD230) --------------------------------------------------------  // acclient.c:239904
IDClass<_tagDataID,32,0> *__cdecl WClassIDToDataID(IDClass<_tagDataID,32,0> *result, unsigned int wcid)
{
  DBObj::GetDIDByEnum(result, wcid, 12);
  return result;
}

//----- (004BD250) --------------------------------------------------------  // acclient.c:239911
bool __thiscall ACCWeenieObject::IsCoinstack(ACCWeenieObject *this)
{
  unsigned int v1; // esi@1

  v1 = this->pwd._wcid.id;
  if ( !(WClassIDHelper::IsCoinstack::_2::local_static_guard & 1) )
  {
    WClassIDHelper::IsCoinstack::_2::local_static_guard |= 1u;
    DBObj::GetDIDByEnum(&WClassIDHelper::IsCoinstack::_2::didCoinstack, 268435458, 12);
    atexit(WClassIDHelper::IsCoinstack::_2::didCoinstack);
  }
  return v1 == WClassIDHelper::IsCoinstack::_2::didCoinstack.id;
}
// 83F41C: using guessed type int WClassIDHelper::IsCoinstack::_2::local_static_guard;

//----- (004BD2A0) --------------------------------------------------------  // acclient.c:239927
void __thiscall gmToolbarUI::RecvNotice_SplitStack(gmToolbarUI *this, unsigned int i_iidItem)
{
  gmToolbarUI *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@2
  unsigned int v4; // eax@3
  HashSetData<UIElement *> *v5; // ecx@5

  v2 = this;
  if ( i_iidItem == ACCWeenieObject::selectedID )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
    if ( v3 )
    {
      v4 = v3[20].id;
      if ( v4 )
      {
        if ( v4 > 1 )
        {
          v5 = v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8];
          if ( v5 )
          {
            ((void (*)(void))v5->m_hashKey->m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[17])();
            ((void (*)(void))v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]->m_hashKey->m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[19])();
            UIElement_Text::SelectAll((UIElement_Text *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]);
          }
        }
      }
    }
  }
}

//----- (004BD300) --------------------------------------------------------  // acclient.c:239959
void __thiscall gmToolbarUI::RecvNotice_SetPanelVisibility(gmToolbarUI *this, unsigned int i_ePanelID, bool i_bVisible)
{
  HashSetData<UIElement *> *v3; // esi@1
  unsigned int v4; // edx@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v5; // eax@2
  void *(__thiscall *v6)(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *, unsigned int); // eax@7
  int v7; // edx@7

  v3 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
  v4 = 0;
  if ( v3 )
  {
    v5 = this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
    while ( !v5->__vecDelDtor
         || v5[1].__vecDelDtor != (void *(__thiscall *)(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *, unsigned int))i_ePanelID )
    {
      ++v4;
      v5 += 2;
      if ( v4 >= (unsigned int)v3 )
        return;
    }
    v6 = v5->__vecDelDtor;
    v7 = *(_DWORD *)v6;
    if ( i_bVisible )
      (*(void (__thiscall **)(void *(__thiscall *)(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *, unsigned int), signed int))(v7 + 156))(
        v6,
        6);
    else
      (*(void (__thiscall **)(void *(__thiscall *)(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *, unsigned int), signed int))(v7 + 156))(
        v6,
        1);
  }
}

//----- (004BD350) --------------------------------------------------------  // acclient.c:239994
void __thiscall gmToolbarUI::UseShortcut(gmToolbarUI *this, int _slot, bool i_bUse)
{
  UIElement_ListBox *v3; // ecx@3
  UIElement *v4; // eax@4
  int v5; // esi@5
  ClientUISystem *v6; // eax@8
  unsigned int v7; // esi@8
  Target_Mode v8; // eax@8
  Target_Mode v9; // ST08_4@9
  ClientUISystem *v10; // eax@9
  ClientUISystem *v11; // eax@10

  if ( _slot >= 0 && _slot < (signed int)this->m_shortcutSlots.m_num )
  {
    v3 = (UIElement_ListBox *)&this->m_shortcutSlots.m_data[_slot]->vfptr;
    if ( v3 )
    {
      v4 = UIElement_ListBox::GetItem(v3, 0);
      if ( v4 )
      {
        v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          if ( ClientUISystem::GetUISystem() && ClientUISystem::GetUISystem()->targetMode )
          {
            v6 = ClientUISystem::GetUISystem();
            v7 = *(_DWORD *)(v5 + 1532);
            v8 = v6->targetMode;
            if ( v7 )
            {
              v9 = v8;
              v10 = ClientUISystem::GetUISystem();
              ClientUISystem::ExecuteTargetModeForItem(v10, v7, v9);
            }
            v11 = ClientUISystem::GetUISystem();
            ClientUISystem::SetTargetMode(v11, 0);
          }
          else if ( i_bUse )
          {
            ItemHolder::UseObject(*(_DWORD *)(v5 + 1532), 0, 0);
          }
          else
          {
            ACCWeenieObject::SetSelectedObject(*(_DWORD *)(v5 + 1532), 0);
          }
        }
      }
    }
  }
}

//----- (004BD420) --------------------------------------------------------  // acclient.c:240046
void __thiscall gmToolbarUI::FlushShortcuts(gmToolbarUI *this)
{
  gmToolbarUI *v1; // edi@1
  unsigned int v2; // esi@1
  UIElement_ItemList *v3; // ecx@2

  v1 = this;
  v2 = 0;
  if ( this->m_shortcutSlots.m_num )
  {
    do
    {
      v3 = v1->m_shortcutSlots.m_data[v2];
      if ( v3 )
        UIElement_ItemList::ItemList_Flush(v3);
      ++v2;
    }
    while ( v2 < v1->m_shortcutSlots.m_num );
  }
}

//----- (004BD450) --------------------------------------------------------  // acclient.c:240068
int __thiscall gmToolbarUI::RemoveShortcut(gmToolbarUI *this, unsigned int _itemID, bool _broadcast)
{
  gmToolbarUI *v3; // ebx@1
  int v4; // edi@1
  UIElement_ItemList *v5; // esi@2
  int result; // eax@5
  HashBaseData<unsigned long> *v7; // eax@6
  CPlayerSystem *v8; // eax@9

  v3 = this;
  v4 = 0;
  if ( this->m_shortcutSlots.m_num )
  {
    while ( 1 )
    {
      v5 = v3->m_shortcutSlots.m_data[v4];
      if ( v5 )
      {
        if ( UIElement_ItemList::ItemList_IsInList(v5, _itemID) )
          break;
      }
      ++v4;
      if ( v4 >= v3->m_shortcutSlots.m_num )
        goto LABEL_5;
    }
    UIElement_ItemList::ItemList_Flush(v5);
    v7 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v7 )
      ACCWeenieObject::SetShortcutNum((ACCWeenieObject *)v7, -1, 0);
    if ( _broadcast )
    {
      CM_Character::Event_RemoveShortCut(v4);
      v8 = CPlayerSystem::GetPlayerSystem();
      PlayerModule::RemoveShortCut((PlayerModule *)&v8->playerModule.vfptr, v4);
    }
    result = v4;
  }
  else
  {
LABEL_5:
    result = -1;
  }
  return result;
}

//----- (004BD4F0) --------------------------------------------------------  // acclient.c:240114
unsigned int __thiscall gmToolbarUI::RemoveShortcutInSlotNum(gmToolbarUI *this, int _slot, bool _broadcast)
{
  gmToolbarUI *v3; // edi@1
  UIElement_ListBox *v4; // ecx@3
  UIElement *v5; // eax@4
  int v6; // eax@5
  unsigned int v7; // esi@6
  unsigned int result; // eax@7

  v3 = this;
  if ( _slot >= 0
    && _slot < (signed int)this->m_shortcutSlots.m_num
    && (v4 = (UIElement_ListBox *)&this->m_shortcutSlots.m_data[_slot]->vfptr) != 0
    && (v5 = UIElement_ListBox::GetItem(v4, 0)) != 0
    && (v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506)) != 0
    && (v7 = *(_DWORD *)(v6 + 1532)) != 0 )
  {
    gmToolbarUI::RemoveShortcut(v3, v7, _broadcast);
    result = v7;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004BD560) --------------------------------------------------------  // acclient.c:240142
unsigned int __thiscall gmToolbarUI::GetFirstEmptyShortcutToTheRightOf(gmToolbarUI *this, unsigned int index)
{
  gmToolbarUI *v2; // esi@1
  unsigned int v3; // edi@1
  UIElement_ItemList *v4; // ecx@2
  UIElement_ItemList *v5; // ecx@7
  unsigned int result; // eax@10

  v2 = this;
  v3 = index + 1;
  if ( index + 1 >= this->m_shortcutSlots.m_num )
  {
LABEL_5:
    v3 = 0;
    do
    {
      if ( v3 >= v2->m_shortcutSlots.m_num )
        break;
      v5 = v2->m_shortcutSlots.m_data[v3];
      if ( v5 && !UIElement_ItemList::GetNumUIItems(v5) )
        goto LABEL_11;
      ++v3;
    }
    while ( v3 <= index );
    result = -1;
  }
  else
  {
    while ( 1 )
    {
      v4 = v2->m_shortcutSlots.m_data[v3];
      if ( v4 )
      {
        if ( !UIElement_ItemList::GetNumUIItems(v4) )
          break;
      }
      ++v3;
      if ( v3 >= v2->m_shortcutSlots.m_num )
        goto LABEL_5;
    }
LABEL_11:
    result = v3;
  }
  return result;
}

//----- (004BD5E0) --------------------------------------------------------  // acclient.c:240189
bool __thiscall gmToolbarUI::IsShortcutSlotAvailable(gmToolbarUI *this, int _slot)
{
  UIElement_ItemList *v2; // ecx@3
  bool result; // al@5

  result = 0;
  if ( _slot >= 0 && _slot < (signed int)this->m_shortcutSlots.m_num )
  {
    v2 = this->m_shortcutSlots.m_data[_slot];
    if ( v2 )
    {
      if ( !UIElement_ItemList::GetNumUIItems(v2) )
        result = 1;
    }
  }
  return result;
}

//----- (004BD610) --------------------------------------------------------  // acclient.c:240208
void __thiscall gmToolbarUI::RecvNotice_SetCombatMode(gmToolbarUI *this, COMBAT_MODE i_eCombatMode)
{
  gmToolbarUI *v2; // esi@1
  int v3; // edi@1
  UIElement_ListBox *v4; // ecx@2
  UIElement *v5; // eax@3
  int v6; // eax@4
  UIElement *v7; // esi@8
  UIElement *v8; // eax@8
  unsigned int v9; // ecx@8
  UIElement *v10; // eax@10
  unsigned int v11; // ecx@10
  UIElement *v12; // eax@12
  unsigned int v13; // ecx@12
  UIElement *v14; // eax@14
  unsigned int v15; // ecx@14

  v2 = this;
  LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[16]) = i_eCombatMode != 8;
  v3 = 0;
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] )
  {
    do
    {
      v4 = (UIElement_ListBox *)*((_DWORD *)&v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]->m_hashKey
                                + v3);
      if ( v4 )
      {
        v5 = UIElement_ListBox::GetItem(v4, 0);
        if ( v5 )
        {
          v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
          if ( v6 )
          {
            if ( *(_DWORD *)(v6 + 1532) )
              UIElement_UIItem::SetShortcutNum(
                (UIElement_UIItem *)v6,
                v3,
                LOBYTE(v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[16]) == 0);
          }
        }
      }
      ++v3;
    }
    while ( (HashSetData<UIElement *> *)v3 < v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] );
  }
  v7 = (UIElement *)&v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18];
  v8 = UIElement::GetChildRecursive(v7, 0x10000192u);
  if ( v8 )
  {
    LOBYTE(v9) = i_eCombatMode == 1;
    v8->vfptr[2].__vecDelDtor((IInputActionCallback *)v8, v9);
  }
  v10 = UIElement::GetChildRecursive(v7, 0x10000193u);
  if ( v10 )
  {
    LOBYTE(v11) = i_eCombatMode == 2;
    v10->vfptr[2].__vecDelDtor((IInputActionCallback *)v10, v11);
  }
  v12 = UIElement::GetChildRecursive(v7, 0x10000194u);
  if ( v12 )
  {
    LOBYTE(v13) = i_eCombatMode == 4;
    v12->vfptr[2].__vecDelDtor((IInputActionCallback *)v12, v13);
  }
  v14 = UIElement::GetChildRecursive(v7, 0x10000195u);
  if ( v14 )
  {
    LOBYTE(v15) = i_eCombatMode == 8;
    v14->vfptr[2].__vecDelDtor((IInputActionCallback *)v14, v15);
  }
}

//----- (004BD710) --------------------------------------------------------  // acclient.c:240282
void __userpurge gmToolbarUI::gmToolbarUI(gmToolbarUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmToolbarUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmToolbarUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmToolbarUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmToolbarUI::vftable;
  v4->m_buttonInfoArray.m_data = 0;
  v4->m_buttonInfoArray.m_sizeAndDeallocate = 0;
  v4->m_buttonInfoArray.m_num = 0;
  v4->m_pUseObjectButton = 0;
  v4->m_pExamineObjectButton = 0;
  v4->m_pSelObjectField = 0;
  v4->m_pSelObjectName = 0;
  v4->m_pSelObjectHealthMeter = 0;
  v4->m_pSelObjectManaMeter = 0;
  v4->m_pStackSizeEntryBox = 0;
  v4->m_pStackSizeSlider = 0;
  v4->m_pInventoryButtonDragOverlay = 0;
  v4->m_iidSelectedObject = 0;
  v4->m_shortcutSlots.m_data = 0;
  v4->m_shortcutSlots.m_sizeAndDeallocate = 0;
  v4->m_shortcutSlots.m_num = 0;
  v4->m_lastShortcutNumDragged = 0;
  v4->m_idAmmoObject = 0;
  v4->m_bToolbarActive = 1;
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B4238: using guessed type bool (__thiscall *gmToolbarUI::vftable)(DBCache *this);
// 7B44E0: using guessed type int (__thiscall *gmToolbarUI::vftable)(void *, char);
// 7BA1AC: using guessed type bool (__thiscall *gmToolbarUI::vftable)(gmToolbarUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BD7D0) --------------------------------------------------------  // acclient.c:240320
gmToolbarUI *__thiscall gmToolbarUI::DynamicCast(gmToolbarUI *this, unsigned int i_eType)
{
  gmToolbarUI *result; // eax@1

  result = this;
  if ( i_eType != 268435463 )
    result = (gmToolbarUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BD7F0) --------------------------------------------------------  // acclient.c:240331
signed int gmToolbarUI::GetUIElementType()
{
  return 268435463;
}

//----- (004BD800) --------------------------------------------------------  // acclient.c:240337
void __thiscall gmToolbarUI::~gmToolbarUI(gmToolbarUI *this)
{
  gmToolbarUI *v1; // esi@1
  unsigned int v2; // eax@1
  NoticeHandler *v3; // ebx@1
  unsigned int v4; // edi@1
  UIElement_ItemList *v5; // ecx@2

  v1 = this;
  v2 = this->m_shortcutSlots.m_num;
  v3 = (NoticeHandler *)&this->vfptr;
  v4 = 0;
  this->vfptr = (IInputActionCallbackVtbl *)&gmToolbarUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmToolbarUI::vftable;
  this->vfptr = (ItemListDragHandlerVtbl *)&gmToolbarUI::vftable;
  if ( v2 )
  {
    do
    {
      v5 = v1->m_shortcutSlots.m_data[v4];
      if ( v5 )
        UIElement_ItemList::UnregisterItemListDragHandler(v5);
      ++v4;
    }
    while ( v4 < v1->m_shortcutSlots.m_num );
  }
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  if ( (v1->m_shortcutSlots.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_shortcutSlots.m_data);
  if ( (v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_buttonInfoArray.m_data);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B4238: using guessed type bool (__thiscall *gmToolbarUI::vftable)(DBCache *this);
// 7B44E0: using guessed type int (__thiscall *gmToolbarUI::vftable)(void *, char);
// 7BA1AC: using guessed type bool (__thiscall *gmToolbarUI::vftable)(gmToolbarUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BD8C0) --------------------------------------------------------  // acclient.c:240378
void __usercall gmToolbarUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmToolbarUI *v3; // eax@1

  v3 = (gmToolbarUI *)operator new(0x64Cu);
  if ( v3 )
    gmToolbarUI::gmToolbarUI(v3, a1, _layout, _full_desc);
}

//----- (004BD8F0) --------------------------------------------------------  // acclient.c:240388
void __thiscall gmToolbarUI::RecvNotice_RemoveShortcut(gmToolbarUI *this, unsigned int i_itemID)
{
  gmToolbarUI::RemoveShortcut((gmToolbarUI *)((char *)this - 1528), i_itemID, 1);
}

//----- (004BD910) --------------------------------------------------------  // acclient.c:240394
void __thiscall gmToolbarUI::RecvNotice_UseShortcut(gmToolbarUI *this, int i_slot)
{
  gmToolbarUI::UseShortcut((gmToolbarUI *)((char *)this - 1528), i_slot, 1);
}

//----- (004BD930) --------------------------------------------------------  // acclient.c:240400
void __thiscall gmToolbarUI::RecvNotice_ItemListBeginDrag(gmToolbarUI *this, UIElement *i_itemList, int i_slotNum)
{
  gmToolbarUI *v3; // esi@1
  HashSetData<UIElement *> *v4; // edi@1
  UIElement_ListBox **v5; // eax@2
  UIElement *v6; // eax@6
  int v7; // eax@7
  unsigned int v8; // eax@8

  v3 = this;
  v4 = 0;
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] )
  {
    v5 = (UIElement_ListBox **)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12];
    while ( (UIElement *)*v5 != i_itemList )
    {
      v4 = (HashSetData<UIElement *> *)((char *)v4 + 1);
      ++v5;
      if ( v4 >= this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] )
        return;
    }
    v6 = UIElement_ListBox::GetItem(*v5, 0);
    if ( v6 )
    {
      v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 1532);
        if ( v8 )
        {
          gmToolbarUI::RemoveShortcut((gmToolbarUI *)((char *)v3 - 1528), v8, 1);
          v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[15] = v4;
        }
      }
    }
  }
}

//----- (004BD9A0) --------------------------------------------------------  // acclient.c:240439
void __thiscall gmToolbarUI::AddShortcut(gmToolbarUI *this, unsigned int _itemID, int _slot, bool _broadcast)
{
  int v4; // ebx@1
  gmToolbarUI *v5; // esi@1
  int v6; // edi@3
  UIElement_ItemList *v7; // ecx@4
  UIElement_ItemList **v8; // ecx@10
  UIElement_ItemList *v9; // esi@10
  UIElement_UIItem *v10; // esi@12
  HashBaseData<unsigned long> *v11; // eax@12
  CPlayerSystem *v12; // eax@17
  CShortCutData data; // [sp+Ch] [bp-10h]@17

  v4 = _slot;
  v5 = this;
  if ( _slot >= 0 && _slot < (signed int)this->m_shortcutSlots.m_num )
    goto LABEL_20;
  v6 = 0;
  if ( this->m_shortcutSlots.m_num )
  {
    while ( 1 )
    {
      v7 = v5->m_shortcutSlots.m_data[v6];
      if ( v7 )
      {
        if ( !UIElement_ItemList::GetNumUIItems(v7) )
          break;
      }
      ++v6;
      if ( v6 >= v5->m_shortcutSlots.m_num )
        goto LABEL_9;
    }
    v4 = v6;
  }
LABEL_9:
  if ( v6 != v5->m_shortcutSlots.m_num )
  {
LABEL_20:
    v8 = v5->m_shortcutSlots.m_data;
    v9 = v8[v4];
    if ( v9 && _itemID )
    {
      UIElement_ItemList::ItemList_Flush(v8[v4]);
      v10 = UIElement_ItemList::ItemList_AddItem(v9, _itemID);
      v11 = ClientObjMaintSystem::GetWeenieObject(_itemID);
      if ( v11 )
      {
        ACCWeenieObject::SetShortcutNum((ACCWeenieObject *)v11, v4, 0);
      }
      else if ( v10 )
      {
        UIElement_UIItem::SetDelayedShortcutNum(v10, v4);
      }
      if ( _broadcast )
      {
        CShortCutData::CShortCutData(&data, v4, _itemID, 0);
        CM_Character::Event_AddShortCut(&data);
        v12 = CPlayerSystem::GetPlayerSystem();
        PlayerModule::AddShortCut((PlayerModule *)&v12->playerModule.vfptr, (ShortCutData *)&data.vfptr);
      }
    }
  }
}

//----- (004BDA80) --------------------------------------------------------  // acclient.c:240504
gmToolbarUI *__thiscall gmToolbarUI::scalar_deleting_destructor(gmToolbarUI *this, unsigned int a2)
{
  gmToolbarUI *v2; // esi@1

  v2 = this;
  gmToolbarUI::~gmToolbarUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BDAA0) --------------------------------------------------------  // acclient.c:240516
void __cdecl gmToolbarUI::Register()
{
  UIElement::RegisterElementClass(0x10000007u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmToolbarUI::Create);
}

//----- (004BDAC0) --------------------------------------------------------  // acclient.c:240522
void __thiscall gmToolbarUI::CreateShortcutToItem(gmToolbarUI *this, unsigned int _itemID, int _shortcutIndex, bool _pickUp, bool _silent)
{
  gmToolbarUI *v5; // esi@1
  HashBaseData<unsigned long> *v6; // eax@2
  ACCWeenieObject *v7; // ebx@2
  PSRefBufferCharData<unsigned short> *v8; // ST0C_4@5
  CPlayerSystem *v9; // eax@10
  unsigned int v10; // eax@12
  unsigned int v11; // edi@12
  UIElement_ListBox *v12; // ecx@13
  UIElement *v13; // eax@14
  int v14; // eax@15
  int v15; // eax@16
  PStringBase<unsigned short> *v16; // eax@24
  PSRefBufferCharData<unsigned short> *v17; // ST0C_4@26
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-9Ch]@5
  bool available; // [sp+Fh] [bp-95h]@12
  PStringBase<unsigned short> result; // [sp+10h] [bp-94h]@5
  StringInfo siError; // [sp+14h] [bp-90h]@6

  v5 = this;
  if ( !_itemID )
    return;
  v6 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v7 = (ACCWeenieObject *)v6;
  if ( !v6 )
    return;
  if ( !gmToolbarUI::IsShortcutEligible((ACCWeenieObject *)v6) )
  {
    if ( !_silent )
    {
      v8 = ACCWeenieObject::GetObjectNameWide(v7, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"You cannot make a shortcut to the %s",
        v8);
      goto LABEL_6;
    }
    return;
  }
  if ( ACCWeenieObject::IsOwnedByPlayer(v7) )
    goto LABEL_11;
  if ( _pickUp )
  {
    v9 = CPlayerSystem::GetPlayerSystem();
    if ( !CPlayerSystem::PlaceInBackpack(v9, _itemID, 0) )
      return;
LABEL_11:
    if ( _shortcutIndex != -1 )
    {
LABEL_27:
      gmToolbarUI::RemoveShortcut(v5, _itemID, 1);
      gmToolbarUI::AddShortcut(v5, _itemID, _shortcutIndex, 1);
      return;
    }
    v10 = v5->m_shortcutSlots.m_num;
    v11 = 0;
    available = 0;
    if ( !v10 )
    {
LABEL_21:
      if ( !_silent )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"There are no free shortcut slots");
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
      return;
    }
    while ( 1 )
    {
      v12 = (UIElement_ListBox *)&v5->m_shortcutSlots.m_data[v11]->vfptr;
      if ( v12 )
      {
        v13 = UIElement_ListBox::GetItem(v12, 0);
        if ( v13 )
        {
          v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)268435506);
          if ( v14 )
          {
            v15 = *(_DWORD *)(v14 + 1532);
            if ( v15 == _itemID )
            {
              if ( _silent )
                return;
              v17 = ACCWeenieObject::GetObjectNameWide(v7, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &errorText,
                0,
                L"There is already a shortcut to the %s",
                v17);
LABEL_6:
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
              StringInfo::StringInfo(&siError);
              StringInfo::SetLiteralValue(&siError, &errorText, 1);
              ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_7:
              StringInfo::~StringInfo(&siError);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
              return;
            }
            if ( !v15 )
              available = 1;
          }
        }
      }
      ++v11;
      if ( v11 >= v5->m_shortcutSlots.m_num )
      {
        if ( available )
          goto LABEL_27;
        goto LABEL_21;
      }
    }
  }
  if ( !_silent )
  {
    v16 = ACCWeenieObject::GetObjectNameWide(v7, &result, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"You are not carrying the %s",
      v16->m_charbuffer);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_7;
  }
}
// 7B4618: using guessed type wchar_t aThereIsAlready[38];

//----- (004BDD50) --------------------------------------------------------  // acclient.c:240659
void __thiscall gmToolbarUI::InitShortcutArray(gmToolbarUI *this)
{
  gmToolbarUI *v1; // ebx@1
  UIElement *v2; // eax@1
  UIElement_ItemList *v3; // edi@2
  ItemListDragHandler *v4; // eax@5
  int v5; // esi@7
  int v6; // eax@7
  unsigned int v7; // eax@8
  UIElement *v8; // eax@10
  UIElement_ItemList *v9; // edi@11
  ItemListDragHandler *v10; // eax@14
  int v11; // eax@16
  unsigned int v12; // eax@17
  UIElement *v13; // eax@19
  UIElement_ItemList *v14; // edi@20
  ItemListDragHandler *v15; // eax@23
  int v16; // eax@25
  unsigned int v17; // eax@26
  UIElement *v18; // eax@28
  UIElement_ItemList *v19; // edi@29
  ItemListDragHandler *v20; // eax@32
  int v21; // eax@34
  unsigned int v22; // eax@35
  UIElement *v23; // eax@37
  UIElement_ItemList *v24; // edi@38
  ItemListDragHandler *v25; // eax@41
  int v26; // eax@43
  unsigned int v27; // eax@44
  UIElement *v28; // eax@46
  UIElement_ItemList *v29; // edi@47
  ItemListDragHandler *v30; // eax@50
  int v31; // eax@52
  unsigned int v32; // eax@53
  UIElement *v33; // eax@55
  UIElement_ItemList *v34; // edi@56
  ItemListDragHandler *v35; // eax@59
  int v36; // eax@61
  unsigned int v37; // eax@62
  UIElement *v38; // eax@64
  UIElement_ItemList *v39; // edi@65
  ItemListDragHandler *v40; // eax@68
  int v41; // eax@70
  unsigned int v42; // eax@71
  UIElement *v43; // eax@73
  UIElement_ItemList *v44; // edi@74
  ItemListDragHandler *v45; // eax@77
  int v46; // eax@79
  unsigned int v47; // eax@80
  UIElement *v48; // eax@82
  UIElement_ItemList *v49; // edi@83
  ItemListDragHandler *v50; // eax@86
  int v51; // eax@88
  unsigned int v52; // eax@89
  UIElement *v53; // eax@91
  UIElement_ItemList *v54; // edi@92
  ItemListDragHandler *v55; // eax@95
  int v56; // eax@97
  unsigned int v57; // eax@98
  UIElement *v58; // eax@100
  UIElement_ItemList *v59; // edi@101
  ItemListDragHandler *v60; // eax@104
  int v61; // eax@106
  unsigned int v62; // eax@107
  UIElement *v63; // eax@109
  UIElement_ItemList *v64; // edi@110
  ItemListDragHandler *v65; // eax@113
  int v66; // eax@115
  unsigned int v67; // eax@116
  UIElement *v68; // eax@118
  UIElement_ItemList *v69; // edi@119
  ItemListDragHandler *v70; // eax@122
  int v71; // eax@124
  unsigned int v72; // eax@125
  UIElement *v73; // eax@127
  UIElement_ItemList *v74; // edi@128
  ItemListDragHandler *v75; // eax@131
  int v76; // eax@133
  unsigned int v77; // eax@134
  UIElement *v78; // eax@136
  UIElement_ItemList *v79; // edi@137
  ItemListDragHandler *v80; // eax@140
  int v81; // eax@142
  unsigned int v82; // eax@143
  UIElement *v83; // eax@145
  UIElement_ItemList *v84; // edi@146
  ItemListDragHandler *v85; // eax@149
  int v86; // eax@151
  unsigned int v87; // eax@152
  UIElement *v88; // eax@154
  UIElement_ItemList *v89; // edi@155
  ItemListDragHandler *v90; // eax@158
  int v91; // eax@160
  unsigned int v92; // eax@161

  v1 = this;
  v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x100001A7u);
  if ( v2 )
    v3 = (UIElement_ItemList *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435505);
  else
    v3 = 0;
  if ( v1 )
    v4 = (ItemListDragHandler *)&v1->vfptr;
  else
    v4 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v3, v4);
  v5 = (int)&v1->m_shortcutSlots;
  v6 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v6
    || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v7)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v3;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001A8u);
  if ( v8 )
    v9 = (UIElement_ItemList *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435505);
  else
    v9 = 0;
  if ( v1 )
    v10 = (ItemListDragHandler *)&v1->vfptr;
  else
    v10 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v9, v10);
  v11 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v11
    || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v12)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v9;
  v13 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001A9u);
  if ( v13 )
    v14 = (UIElement_ItemList *)v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)268435505);
  else
    v14 = 0;
  if ( v1 )
    v15 = (ItemListDragHandler *)&v1->vfptr;
  else
    v15 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v14, v15);
  v16 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v16
    || (v17 = SmartArray<UIChildFramework *,1>::get_new_size(v16 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v17)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v14;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001AAu);
  if ( v18 )
    v19 = (UIElement_ItemList *)v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)268435505);
  else
    v19 = 0;
  if ( v1 )
    v20 = (ItemListDragHandler *)&v1->vfptr;
  else
    v20 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v19, v20);
  v21 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v21
    || (v22 = SmartArray<UIChildFramework *,1>::get_new_size(v21 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v22)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v19;
  v23 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001ABu);
  if ( v23 )
    v24 = (UIElement_ItemList *)v23->vfptr[12].OnAction((IInputActionCallback *)v23, (InputEvent *)268435505);
  else
    v24 = 0;
  if ( v1 )
    v25 = (ItemListDragHandler *)&v1->vfptr;
  else
    v25 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v24, v25);
  v26 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v26
    || (v27 = SmartArray<UIChildFramework *,1>::get_new_size(v26 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v27)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v24;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001ACu);
  if ( v28 )
    v29 = (UIElement_ItemList *)v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)268435505);
  else
    v29 = 0;
  if ( v1 )
    v30 = (ItemListDragHandler *)&v1->vfptr;
  else
    v30 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v29, v30);
  v31 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v31
    || (v32 = SmartArray<UIChildFramework *,1>::get_new_size(v31 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v32)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v29;
  v33 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001ADu);
  if ( v33 )
    v34 = (UIElement_ItemList *)v33->vfptr[12].OnAction((IInputActionCallback *)v33, (InputEvent *)268435505);
  else
    v34 = 0;
  if ( v1 )
    v35 = (ItemListDragHandler *)&v1->vfptr;
  else
    v35 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v34, v35);
  v36 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v36
    || (v37 = SmartArray<UIChildFramework *,1>::get_new_size(v36 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v37)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v34;
  v38 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001AEu);
  if ( v38 )
    v39 = (UIElement_ItemList *)v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)268435505);
  else
    v39 = 0;
  if ( v1 )
    v40 = (ItemListDragHandler *)&v1->vfptr;
  else
    v40 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v39, v40);
  v41 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v41
    || (v42 = SmartArray<UIChildFramework *,1>::get_new_size(v41 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v42)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v39;
  v43 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001AFu);
  if ( v43 )
    v44 = (UIElement_ItemList *)v43->vfptr[12].OnAction((IInputActionCallback *)v43, (InputEvent *)268435505);
  else
    v44 = 0;
  if ( v1 )
    v45 = (ItemListDragHandler *)&v1->vfptr;
  else
    v45 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v44, v45);
  v46 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v46
    || (v47 = SmartArray<UIChildFramework *,1>::get_new_size(v46 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v47)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v44;
  v48 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B7u);
  if ( v48 )
    v49 = (UIElement_ItemList *)v48->vfptr[12].OnAction((IInputActionCallback *)v48, (InputEvent *)268435505);
  else
    v49 = 0;
  if ( v1 )
    v50 = (ItemListDragHandler *)&v1->vfptr;
  else
    v50 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v49, v50);
  v51 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v51
    || (v52 = SmartArray<UIChildFramework *,1>::get_new_size(v51 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v52)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v49;
  v53 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B8u);
  if ( v53 )
    v54 = (UIElement_ItemList *)v53->vfptr[12].OnAction((IInputActionCallback *)v53, (InputEvent *)268435505);
  else
    v54 = 0;
  if ( v1 )
    v55 = (ItemListDragHandler *)&v1->vfptr;
  else
    v55 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v54, v55);
  v56 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v56
    || (v57 = SmartArray<UIChildFramework *,1>::get_new_size(v56 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v57)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v54;
  v58 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B9u);
  if ( v58 )
    v59 = (UIElement_ItemList *)v58->vfptr[12].OnAction((IInputActionCallback *)v58, (InputEvent *)268435505);
  else
    v59 = 0;
  if ( v1 )
    v60 = (ItemListDragHandler *)&v1->vfptr;
  else
    v60 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v59, v60);
  v61 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v61
    || (v62 = SmartArray<UIChildFramework *,1>::get_new_size(v61 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v62)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v59;
  v63 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BAu);
  if ( v63 )
    v64 = (UIElement_ItemList *)v63->vfptr[12].OnAction((IInputActionCallback *)v63, (InputEvent *)268435505);
  else
    v64 = 0;
  if ( v1 )
    v65 = (ItemListDragHandler *)&v1->vfptr;
  else
    v65 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v64, v65);
  v66 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v66
    || (v67 = SmartArray<UIChildFramework *,1>::get_new_size(v66 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v67)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v64;
  v68 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BBu);
  if ( v68 )
    v69 = (UIElement_ItemList *)v68->vfptr[12].OnAction((IInputActionCallback *)v68, (InputEvent *)268435505);
  else
    v69 = 0;
  if ( v1 )
    v70 = (ItemListDragHandler *)&v1->vfptr;
  else
    v70 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v69, v70);
  v71 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v71
    || (v72 = SmartArray<UIChildFramework *,1>::get_new_size(v71 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v72)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v69;
  v73 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BCu);
  if ( v73 )
    v74 = (UIElement_ItemList *)v73->vfptr[12].OnAction((IInputActionCallback *)v73, (InputEvent *)268435505);
  else
    v74 = 0;
  if ( v1 )
    v75 = (ItemListDragHandler *)&v1->vfptr;
  else
    v75 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v74, v75);
  v76 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v76
    || (v77 = SmartArray<UIChildFramework *,1>::get_new_size(v76 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v77)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v74;
  v78 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BDu);
  if ( v78 )
    v79 = (UIElement_ItemList *)v78->vfptr[12].OnAction((IInputActionCallback *)v78, (InputEvent *)268435505);
  else
    v79 = 0;
  if ( v1 )
    v80 = (ItemListDragHandler *)&v1->vfptr;
  else
    v80 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v79, v80);
  v81 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v81
    || (v82 = SmartArray<UIChildFramework *,1>::get_new_size(v81 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v82)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v79;
  v83 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BEu);
  if ( v83 )
    v84 = (UIElement_ItemList *)v83->vfptr[12].OnAction((IInputActionCallback *)v83, (InputEvent *)268435505);
  else
    v84 = 0;
  if ( v1 )
    v85 = (ItemListDragHandler *)&v1->vfptr;
  else
    v85 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v84, v85);
  v86 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v86
    || (v87 = SmartArray<UIChildFramework *,1>::get_new_size(v86 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v87)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v84;
  v88 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006BFu);
  if ( v88 )
    v89 = (UIElement_ItemList *)v88->vfptr[12].OnAction((IInputActionCallback *)v88, (InputEvent *)268435505);
  else
    v89 = 0;
  if ( v1 )
    v90 = (ItemListDragHandler *)&v1->vfptr;
  else
    v90 = 0;
  UIElement_ItemList::RegisterItemListDragHandler(v89, v90);
  v91 = v1->m_shortcutSlots.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_shortcutSlots.m_num < v91
    || (v92 = SmartArray<UIChildFramework *,1>::get_new_size(v91 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_shortcutSlots, v92)) )
    *(_DWORD *)(*(_DWORD *)v5 + 4 * v1->m_shortcutSlots.m_num++) = v89;
  gmToolbarUI::FlushShortcuts(v1);
}

//----- (004BE4E0) --------------------------------------------------------  // acclient.c:241030
void __thiscall gmToolbarUI::ListenToGlobalMessage(gmToolbarUI *this, unsigned int i_messageID, int i_data_int)
{
  gmToolbarUI *v3; // esi@1
  int v4; // eax@2
  PStringBase<unsigned short> *v5; // eax@4
  int v6; // edi@4

  v3 = this;
  if ( i_messageID == 1 )
  {
    LOBYTE(v4) = UIElement::GetHasFocus((UIElement *)&this->m_pStackSizeEntryBox->vfptr);
    if ( (_BYTE)v4 )
    {
      if ( i_data_int == 39 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_data_int,
          0,
          L"%d",
          GenItemHolder::splitSize);
        UIElement_Text::SetText(v3->m_pStackSizeEntryBox, v5);
        v6 = i_data_int - 20;
        if ( !InterlockedDecrement((volatile LONG *)(i_data_int - 20 + 4)) )
        {
          if ( v6 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
        }
        ((void (*)(void))v3->m_pStackSizeEntryBox->vfptr[22].__vecDelDtor)();
      }
    }
    else
    {
      switch ( i_data_int )
      {
        case 268435522:
        case 268435523:
        case 268435524:
        case 268435525:
        case 268435526:
        case 268435527:
        case 268435528:
        case 268435529:
        case 268435530:
        case 268435531:
        case 268435532:
        case 268435533:
          gmToolbarUI::UseShortcut(v3, v4, 1);
          break;
        case 268435762:
          gmToolbarUI::UseShortcut(v3, 12, 1);
          break;
        case 268435763:
          gmToolbarUI::UseShortcut(v3, 13, 1);
          break;
        case 268435764:
          gmToolbarUI::UseShortcut(v3, 14, 1);
          break;
        case 268435765:
          gmToolbarUI::UseShortcut(v3, 15, 1);
          break;
        case 268435766:
          gmToolbarUI::UseShortcut(v3, 16, 1);
          break;
        case 268435767:
          gmToolbarUI::UseShortcut(v3, 17, 1);
          break;
        case 268435534:
        case 268435535:
        case 268435536:
        case 268435537:
        case 268435538:
        case 268435539:
        case 268435540:
        case 268435541:
        case 268435542:
        case 268435543:
        case 268435544:
        case 268435545:
          gmToolbarUI::UseShortcut(v3, i_data_int - 268435534, 0);
          break;
        case 268435768:
          gmToolbarUI::UseShortcut(v3, 12, 0);
          break;
        case 268435769:
          gmToolbarUI::UseShortcut(v3, 13, 0);
          break;
        case 268435770:
          gmToolbarUI::UseShortcut(v3, 14, 0);
          break;
        case 268435771:
          gmToolbarUI::UseShortcut(v3, 15, 0);
          break;
        case 268435772:
          gmToolbarUI::UseShortcut(v3, 16, 0);
          break;
        case 268435773:
          gmToolbarUI::UseShortcut(v3, 17, 0);
          break;
        case 268435725:
          if ( ACCWeenieObject::selectedID )
            gmToolbarUI::CreateShortcutToItem(v3, ACCWeenieObject::selectedID, -1, 1, 0);
          break;
        default:
          return;
      }
    }
  }
}

//----- (004BE7C0) --------------------------------------------------------  // acclient.c:241140
void __thiscall gmToolbarUI::HandleDropRelease(gmToolbarUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  int v3; // ebx@1
  UIElement *v4; // ebp@1
  gmToolbarUI *v5; // esi@1
  HashBaseData<unsigned long> *v6; // eax@5
  ACCWeenieObject *v7; // esi@5
  unsigned int v8; // eax@7
  int v9; // eax@7
  unsigned int v10; // ST0C_4@8
  CPlayerSystem *v11; // eax@8
  unsigned int v12; // edi@11
  unsigned int v13; // ebx@17
  int v14; // eax@19
  unsigned int v15; // ebx@22
  DropItemFlags dropFlags; // [sp+Ch] [bp-8h]@4
  unsigned int dropSpellID; // [sp+10h] [bp-4h]@4

  v2 = i_rMsg->dwParam1;
  v3 = *(_DWORD *)(v2 + 16);
  v4 = *(UIElement **)(v2 + 8);
  v5 = this;
  if ( v4 && v3 )
  {
    if ( *(_DWORD *)(v3 + 740) == 268435889 )
    {
      UIElement_ItemList::InqDropIconInfo(v4, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
      if ( !(dropFlags & 0xE) )
      {
        v6 = ClientObjMaintSystem::GetWeenieObject((unsigned int)i_rMsg);
        v7 = (ACCWeenieObject *)v6;
        if ( v6 )
        {
          if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v6) )
          {
            v10 = (unsigned int)i_rMsg;
            v11 = CPlayerSystem::GetPlayerSystem();
            v9 = (unsigned __int8)CPlayerSystem::PlaceInBackpack(v11, v10, 0);
          }
          else
          {
            v8 = GetPlayerID();
            v9 = ItemHolder::AttemptToPlaceInContainer((unsigned int)i_rMsg, v8, 0, 1, 0);
          }
          if ( !v9 )
            ACCWeenieObject::SetWaitingState(v7, 0);
        }
      }
    }
    else
    {
      v12 = 0;
      if ( this->m_shortcutSlots.m_num )
      {
        do
        {
          if ( UIElement::IsAncestorOfMe((UIElement *)v3, (UIElement *)&v5->m_shortcutSlots.m_data[v12]->vfptr) )
            break;
          ++v12;
        }
        while ( v12 < v5->m_shortcutSlots.m_num );
      }
      if ( v12 != v5->m_shortcutSlots.m_num )
      {
        UIElement_ItemList::InqDropIconInfo(v4, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
        if ( i_rMsg )
        {
          if ( dropFlags & 0xE )
          {
            if ( dropFlags & 4 )
            {
              v15 = gmToolbarUI::RemoveShortcutInSlotNum(v5, v12, 1);
              gmToolbarUI::AddShortcut(v5, (unsigned int)i_rMsg, v12, 1);
              if ( v15 )
              {
                if ( (UIElementMessageInfo *)v15 != i_rMsg
                  && gmToolbarUI::IsShortcutSlotAvailable(v5, v5->m_lastShortcutNumDragged) )
                  gmToolbarUI::AddShortcut(v5, v15, v5->m_lastShortcutNumDragged, 1);
              }
            }
          }
          else
          {
            v13 = gmToolbarUI::RemoveShortcutInSlotNum(v5, v12, 1);
            gmToolbarUI::CreateShortcutToItem(v5, (unsigned int)i_rMsg, v12, 1, 0);
            if ( v13 )
            {
              if ( (UIElementMessageInfo *)v13 != i_rMsg )
              {
                v14 = gmToolbarUI::GetFirstEmptyShortcutToTheRightOf(v5, v12);
                if ( v14 != -1 )
                  gmToolbarUI::AddShortcut(v5, v13, v14, 1);
              }
            }
          }
        }
      }
    }
  }
}

//----- (004BE990) --------------------------------------------------------  // acclient.c:241243
void __thiscall gmToolbarUI::RecvNotice_AddShortcut(gmToolbarUI *this, unsigned int i_itemID, int i_slot)
{
  gmToolbarUI::CreateShortcutToItem((gmToolbarUI *)((char *)this - 1528), i_itemID, i_slot, 0, 1);
}

//----- (004BE9B0) --------------------------------------------------------  // acclient.c:241249
void __thiscall gmToolbarUI::RecvNotice_FullMergingItem(gmToolbarUI *this, unsigned int i_oldObject, unsigned int i_mergeTo)
{
  gmToolbarUI *v3; // esi@1
  int v4; // eax@1

  v3 = (gmToolbarUI *)((char *)this - 1528);
  v4 = gmToolbarUI::RemoveShortcut((gmToolbarUI *)((char *)this - 1528), i_oldObject, 1);
  if ( v4 != -1 )
    gmToolbarUI::CreateShortcutToItem(v3, i_mergeTo, v4, 0, 1);
}

//----- (004BE9E0) --------------------------------------------------------  // acclient.c:241261
void __thiscall gmToolbarUI::UpdateAmmoNumber(gmToolbarUI *this)
{
  gmToolbarUI *v1; // esi@1
  UIElement *v2; // eax@1
  UIElement_Text *v3; // edi@2
  HashBaseData<unsigned long> *v4; // eax@3
  int v5; // eax@4
  char *v6; // esi@7
  PStringBase<unsigned short> strBtnText; // [sp+4h] [bp-4h]@1

  strBtnText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000194u);
  if ( v2 )
  {
    v3 = (UIElement_Text *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1);
    if ( v3 )
    {
      strBtnText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v4 = ClientObjMaintSystem::GetWeenieObject(v1->m_idAmmoObject);
      if ( v4 )
      {
        v5 = v4[20].id;
        if ( !v5 )
          v5 = 1;
        PStringBase<unsigned short>::append_int32(&strBtnText, v5);
      }
      UIElement_Text::SetText(v3, &strBtnText);
      v6 = (char *)&strBtnText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strBtnText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
    }
  }
}

//----- (004BEA80) --------------------------------------------------------  // acclient.c:241301
void __thiscall gmToolbarUI::PostInit(gmToolbarUI *this)
{
  gmToolbarUI *v1; // edi@1
  UIElement *v2; // eax@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  UIElement *v5; // ecx@4
  UIElement *v6; // eax@4
  int v7; // eax@5
  UIElement *v8; // ecx@7
  UIElement *v9; // eax@7
  int v10; // eax@8
  UIElement *v11; // ecx@10
  UIElement *v12; // eax@10
  int v13; // eax@11
  UIElement *v14; // eax@15
  int v15; // eax@16
  int v16; // esi@18
  int v17; // eax@18
  unsigned int v18; // eax@19
  unsigned int v19; // edx@20
  int v20; // eax@20
  int v21; // eax@21
  unsigned int v22; // eax@22
  unsigned int v23; // eax@23
  int v24; // ecx@23
  int v25; // eax@24
  unsigned int v26; // eax@25
  unsigned int v27; // edx@26
  int v28; // eax@26
  int v29; // eax@27
  unsigned int v30; // eax@28
  unsigned int v31; // eax@29
  int v32; // ecx@29
  int v33; // eax@30
  unsigned int v34; // eax@31
  unsigned int v35; // edx@32
  int v36; // eax@32
  int v37; // eax@33
  unsigned int v38; // eax@34
  unsigned int v39; // eax@35
  int v40; // ecx@35
  int v41; // eax@36
  unsigned int v42; // eax@37
  unsigned int v43; // edx@38
  int v44; // eax@38
  PanelButtonInfo social; // [sp+8h] [bp-38h]@18
  PanelButtonInfo spellmanagement; // [sp+10h] [bp-30h]@21
  PanelButtonInfo skillmanagement; // [sp+18h] [bp-28h]@24
  PanelButtonInfo questmanagement; // [sp+20h] [bp-20h]@27
  PanelButtonInfo world; // [sp+28h] [bp-18h]@30
  PanelButtonInfo options; // [sp+30h] [bp-10h]@33
  PanelButtonInfo inventory; // [sp+38h] [bp-8h]@36

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pUseObjectButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000019Du);
  v1->m_pExamineObjectButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001A5u);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000019Eu);
  v1->m_pSelObjectField = v2;
  v3 = UIElement::GetChildRecursive(v2, 0x1000019Fu);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    v4 = 0;
  v5 = v1->m_pSelObjectField;
  v1->m_pSelObjectName = (UIElement_Text *)v4;
  v6 = UIElement::GetChildRecursive(v5, 0x100001A1u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)7);
  else
    v7 = 0;
  v8 = v1->m_pSelObjectField;
  v1->m_pSelObjectHealthMeter = (UIElement_Meter *)v7;
  v9 = UIElement::GetChildRecursive(v8, 0x100001A2u);
  if ( v9 )
    v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)7);
  else
    v10 = 0;
  v11 = v1->m_pSelObjectField;
  v1->m_pSelObjectManaMeter = (UIElement_Meter *)v10;
  v12 = UIElement::GetChildRecursive(v11, 0x100001A3u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v13 = 0;
  v1->m_pStackSizeEntryBox = (UIElement_Text *)v13;
  if ( v13 )
    *(_DWORD *)(v13 + 1696) = NumberInputFilter;
  v14 = UIElement::GetChildRecursive(v1->m_pSelObjectField, 0x100001A4u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)11);
  else
    v15 = 0;
  v1->m_pStackSizeSlider = (UIElement_Scrollbar *)v15;
  social.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000197u);
  UIElement::GetAttribute_Enum(social.button, 0x10000029u, &social.panelID);
  v16 = (int)&v1->m_buttonInfoArray;
  v17 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v17
    || (v18 = SmartArray<UIChildFramework *,1>::get_new_size(v17 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v18)) )
  {
    v19 = v1->m_buttonInfoArray.m_num;
    v20 = *(_DWORD *)v16;
    *(_DWORD *)(v20 + 8 * v19) = social.button;
    *(_DWORD *)(v20 + 8 * v19 + 4) = social.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  spellmanagement.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000198u);
  UIElement::GetAttribute_Enum(spellmanagement.button, 0x10000029u, &spellmanagement.panelID);
  v21 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v21
    || (v22 = SmartArray<UIChildFramework *,1>::get_new_size(v21 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v22)) )
  {
    v23 = v1->m_buttonInfoArray.m_num;
    v24 = *(_DWORD *)v16;
    *(_DWORD *)(v24 + 8 * v23) = spellmanagement.button;
    *(_DWORD *)(v24 + 8 * v23 + 4) = spellmanagement.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  skillmanagement.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000199u);
  UIElement::GetAttribute_Enum(skillmanagement.button, 0x10000029u, &skillmanagement.panelID);
  v25 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v25
    || (v26 = SmartArray<UIChildFramework *,1>::get_new_size(v25 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v26)) )
  {
    v27 = v1->m_buttonInfoArray.m_num;
    v28 = *(_DWORD *)v16;
    *(_DWORD *)(v28 + 8 * v27) = skillmanagement.button;
    *(_DWORD *)(v28 + 8 * v27 + 4) = skillmanagement.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  questmanagement.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000055Au);
  UIElement::GetAttribute_Enum(questmanagement.button, 0x10000029u, &questmanagement.panelID);
  v29 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v29
    || (v30 = SmartArray<UIChildFramework *,1>::get_new_size(v29 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v30)) )
  {
    v31 = v1->m_buttonInfoArray.m_num;
    v32 = *(_DWORD *)v16;
    *(_DWORD *)(v32 + 8 * v31) = questmanagement.button;
    *(_DWORD *)(v32 + 8 * v31 + 4) = questmanagement.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  world.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000019Au);
  UIElement::GetAttribute_Enum(world.button, 0x10000029u, &world.panelID);
  v33 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v33
    || (v34 = SmartArray<UIChildFramework *,1>::get_new_size(v33 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v34)) )
  {
    v35 = v1->m_buttonInfoArray.m_num;
    v36 = *(_DWORD *)v16;
    *(_DWORD *)(v36 + 8 * v35) = world.button;
    *(_DWORD *)(v36 + 8 * v35 + 4) = world.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  options.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000019Bu);
  UIElement::GetAttribute_Enum(options.button, 0x10000029u, &options.panelID);
  v37 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v37
    || (v38 = SmartArray<UIChildFramework *,1>::get_new_size(v37 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v38)) )
  {
    v39 = v1->m_buttonInfoArray.m_num;
    v40 = *(_DWORD *)v16;
    *(_DWORD *)(v40 + 8 * v39) = options.button;
    *(_DWORD *)(v40 + 8 * v39 + 4) = options.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  inventory.button = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001B1u);
  UIElement::GetAttribute_Enum(inventory.button, 0x10000029u, &inventory.panelID);
  v41 = v1->m_buttonInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_buttonInfoArray.m_num < v41
    || (v42 = SmartArray<UIChildFramework *,1>::get_new_size(v41 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_buttonInfoArray, v42)) )
  {
    v43 = v1->m_buttonInfoArray.m_num;
    v44 = *(_DWORD *)v16;
    *(_DWORD *)(v44 + 8 * v43) = inventory.button;
    *(_DWORD *)(v44 + 8 * v43 + 4) = inventory.panelID;
    ++v1->m_buttonInfoArray.m_num;
  }
  v1->m_pInventoryButtonDragOverlay = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000046Cu);
  gmToolbarUI::InitShortcutArray(v1);
  ((void (__stdcall *)(_DWORD))v1->m_pSelObjectHealthMeter->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pSelObjectManaMeter->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pStackSizeEntryBox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pStackSizeSlider->vfptr[2].__vecDelDtor)(0);
}

//----- (004BEE90) --------------------------------------------------------  // acclient.c:241497
int __thiscall gmToolbarUI::ListenToElementMessage(gmToolbarUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // esi@1
  unsigned int v3; // eax@1
  gmToolbarUI *v4; // edi@1
  int result; // eax@4
  int v6; // ebp@5
  PSRefBufferCharData<unsigned short> *v7; // esi@5
  unsigned __int32 v8; // eax@5
  char *v9; // esi@5
  unsigned int v10; // ebx@5
  unsigned int v11; // eax@8
  unsigned int v12; // esi@9
  PStringBase<unsigned short> *v13; // eax@11
  float _val; // ST10_4@13
  unsigned int v15; // esi@20
  PStringBase<unsigned short> *v16; // eax@24
  char *v17; // edi@24
  unsigned int v18; // ecx@28
  ClientCombatSystem *v19; // eax@34
  unsigned int v20; // ST10_4@36
  ClientUISystem *v21; // eax@36
  ClientUISystem *v22; // eax@37
  ClientUISystem *v23; // eax@40

  v2 = i_rMsg;
  v3 = i_rMsg->idElement;
  v4 = this;
  if ( i_rMsg->idElement == 268435875 )
  {
    if ( i_rMsg->idMessage == 47 )
    {
      if ( i_rMsg->dwParam1 )
      {
        ((void (*)(void))this->m_pStackSizeEntryBox->vfptr[21].__vecDelDtor)();
        UIElement_Text::SelectAll(v4->m_pStackSizeEntryBox);
        return 0;
      }
      v6 = GenItemHolder::splitSize;
      v7 = UIElement_Text::GetText(this->m_pStackSizeEntryBox, (PStringBase<unsigned short> *)&i_rMsg)->m_charbuffer;
      *__errno() = 0;
      v8 = _wcstoul(v7->m_data, 0, 0);
      v9 = (char *)&i_rMsg[-1].ptWindow;
      v10 = v8;
      if ( !InterlockedDecrement(&i_rMsg[-1].ptWindow.y) && v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      v11 = GenItemHolder::maxSplitSize;
      if ( v10 <= GenItemHolder::maxSplitSize )
      {
        if ( v10 >= 1 )
        {
          v12 = v10;
LABEL_12:
          GenItemHolder::splitSize = v12;
          if ( v12 != v6 )
          {
            i_rMsg = (UIElementMessageInfo *)v11;
            _val = (double)v12 / (double)v11;
            UIElement::SetAttribute_Float((UIElement *)&v4->m_pStackSizeSlider->vfptr, 0x86u, _val);
            CM_UI::SendNotice_StackSliderChanged(v12, GenItemHolder::maxSplitSize);
          }
          return 0;
        }
        v12 = 1;
      }
      else
      {
        v12 = GenItemHolder::maxSplitSize;
      }
      if ( v10 != v12 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_rMsg, 0, L"%d", v12);
        UIElement_Text::SetText(v4->m_pStackSizeEntryBox, v13);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
        v11 = GenItemHolder::maxSplitSize;
      }
      goto LABEL_12;
    }
    goto LABEL_28;
  }
  if ( v3 != 268435876 || i_rMsg->idMessage != 10 )
  {
LABEL_28:
    v18 = i_rMsg->idMessage;
    if ( v18 == 21 )
    {
      if ( v3 == 268435889 )
        ((void (__stdcall *)(signed int))v4->m_pInventoryButtonDragOverlay->vfptr[13].__vecDelDtor)(268435519);
      gmToolbarUI::HandleDropRelease(v4, v2);
      result = 0;
    }
    else if ( v18 == 1 )
    {
      switch ( v3 )
      {
        case 0x10000192u:
        case 0x10000193u:
        case 0x10000194u:
        case 0x10000195u:
          v19 = ClientCombatSystem::GetCombatSystem();
          ClientCombatSystem::ToggleCombatMode(v19);
          result = 0;
          break;
        case 0x100001A5u:
          if ( ACCWeenieObject::selectedID )
          {
            v20 = ACCWeenieObject::selectedID;
            v21 = ClientUISystem::GetUISystem();
            ClientUISystem::ExamineObject(v21, v20);
            result = 0;
          }
          else
          {
            v22 = ClientUISystem::GetUISystem();
            ClientUISystem::SetTargetMode(v22, TARGET_MODE_EXAMINE);
            result = 0;
          }
          break;
        case 0x1000019Du:
          if ( ACCWeenieObject::selectedID )
          {
            ItemHolder::UseObject(ACCWeenieObject::selectedID, 0, 0);
            result = 0;
          }
          else
          {
            v23 = ClientUISystem::GetUISystem();
            ClientUISystem::SetTargetMode(v23, TARGET_MODE_USE);
            result = 0;
          }
          break;
        default:
          goto LABEL_48;
      }
    }
    else if ( v18 != 62 || v3 != 268435889 )
    {
LABEL_48:
      result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
    }
    else if ( i_rMsg->dwParam1 )
    {
      if ( UIElementManager::s_pInstance->m_dragElement )
      {
        gmToolbarUI::HandleInventoryButtonDragOver(v4, UIElementManager::s_pInstance->m_dragElement);
        result = 0;
      }
      else
      {
        ((void (__stdcall *)(signed int))v4->m_pInventoryButtonDragOverlay->vfptr[13].__vecDelDtor)(268435519);
        result = 0;
      }
    }
    else
    {
      ((void (__stdcall *)(signed int))v4->m_pInventoryButtonDragOverlay->vfptr[13].__vecDelDtor)(268435519);
      result = 0;
    }
    return result;
  }
  v15 = 1 - (unsigned __int64)((double)i_rMsg->dwParam1 * (double)GenItemHolder::maxSplitSize * -0.001);
  if ( v15 <= GenItemHolder::maxSplitSize )
  {
    if ( v15 < 1 )
      v15 = 1;
  }
  else
  {
    v15 = GenItemHolder::maxSplitSize;
  }
  GenItemHolder::splitSize = v15;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_rMsg, 0, L"%d", v15);
  UIElement_Text::SetText(v4->m_pStackSizeEntryBox, v16);
  v17 = (char *)&i_rMsg[-1].ptWindow;
  if ( !InterlockedDecrement(&i_rMsg[-1].ptWindow.y) && v17 )
    (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
  CM_UI::SendNotice_StackSliderChanged(v15, GenItemHolder::maxSplitSize);
  return 0;
}

//----- (004BF210) --------------------------------------------------------  // acclient.c:241678
void __thiscall gmToolbarUI::UpdateAmmoID(gmToolbarUI *this)
{
  gmToolbarUI *v1; // esi@1
  unsigned int v2; // ebp@1
  unsigned int v3; // eax@2
  HashBaseData<unsigned long> *v4; // eax@4
  ACCWeenieObject *v5; // ebx@4
  unsigned int v6; // eax@5
  unsigned int v7; // edi@5
  HashBaseData<unsigned long> *v8; // eax@6

  v1 = this;
  v2 = this->m_idAmmoObject;
  this->m_idAmmoObject = 0;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = ClientObjMaintSystem::GetWeenieObject(v3);
  v5 = (ACCWeenieObject *)v4;
  if ( v4 )
  {
    v6 = (unsigned int)ACCWeenieObject::GetObjectAtLocation((ACCWeenieObject *)v4, 0x400000u, 0);
    v7 = v6;
    if ( v6 )
    {
      v8 = ClientObjMaintSystem::GetWeenieObject(v6);
      if ( v8 )
      {
        if ( v8[21].vfptr > (HashBaseData<unsigned long>Vtbl *)1 )
          v1->m_idAmmoObject = v7;
      }
    }
    if ( !v1->m_idAmmoObject )
      v1->m_idAmmoObject = (unsigned int)ACCWeenieObject::GetObjectAtLocation(
                                           v5,
                                           (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)",
                                           0);
    if ( v1->m_idAmmoObject != v2 )
      gmToolbarUI::UpdateAmmoNumber(v1);
  }
}

//----- (004BF2B0) --------------------------------------------------------  // acclient.c:241722
void __thiscall gmToolbarUI::RecvNotice_ServerSaysMoveItem(gmToolbarUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmToolbarUI *v9; // edi@1
  unsigned int v10; // ecx@2
  unsigned int v11; // eax@6
  int v12; // esi@12
  UIElement_ListBox *v13; // ecx@13
  UIElement *v14; // eax@14
  int v15; // eax@15
  HashBaseData<unsigned long> *v16; // eax@17

  v9 = this;
  if ( SmartBox::smartbox )
    v10 = SmartBox::smartbox->player_id;
  else
    v10 = 0;
  if ( _oldWielder == v10
    || (!SmartBox::smartbox ? (v11 = 0) : (v11 = SmartBox::smartbox->player_id), _newWielder == v11) )
  {
    if ( _oldLocation & 0xC00000 || _newLocation & 0xC00000 )
      gmToolbarUI::UpdateAmmoID((gmToolbarUI *)((char *)v9 - 1528));
  }
  v12 = 0;
  if ( v9->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] )
  {
    while ( 1 )
    {
      v13 = (UIElement_ListBox *)*((_DWORD *)&v9->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]->m_hashKey
                                 + v12);
      if ( v13 )
      {
        v14 = UIElement_ListBox::GetItem(v13, 0);
        if ( v14 )
        {
          v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)268435506);
          if ( v15 )
          {
            if ( *(_DWORD *)(v15 + 1532) == _itemID )
            {
              v16 = ClientObjMaintSystem::GetWeenieObject(_itemID);
              if ( !v16 || !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v16) )
                break;
            }
          }
        }
      }
      ++v12;
      if ( (HashSetData<UIElement *> *)v12 >= v9->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] )
        return;
    }
    gmToolbarUI::RemoveShortcutInSlotNum((gmToolbarUI *)((char *)v9 - 1528), v12, 1);
  }
}

//----- (004BF380) --------------------------------------------------------  // acclient.c:241777
void __usercall gmToolbarUI::HandleSelectionChanged(gmToolbarUI *this@<ecx>, int a2@<ebp>, float a3@<edi>)
{
  _Formatted v3; // ebx@1
  gmToolbarUI *v4; // esi@1
  bool v5; // zf@1
  UIElement_Text *v6; // ecx@2
  unsigned int v7; // eax@7
  HashBaseData<unsigned long> *v8; // eax@9
  HashBaseData<unsigned long> *v9; // edi@9
  InterfacePtr<Interface> *v10; // eax@12
  PlayerDesc *v11; // ebx@14
  unsigned int v12; // ebp@17
  int v13; // ST20_4@17
  char *v14; // eax@17
  PStringBase<unsigned short> *v15; // eax@17
  unsigned int v16; // eax@20
  HashBaseData<unsigned long>Vtbl *v17; // ebx@23
  signed int v18; // eax@25
  PStringBase<unsigned short> *v19; // eax@29
  int v20; // ebp@29
  float v21; // ST28_4@32
  unsigned int v22; // ebp@33
  const char *v23; // eax@33
  PStringBase<unsigned short> *v24; // eax@34
  char *v25; // ebp@34
  PStringBase<unsigned short> *v26; // eax@37
  char *v27; // ebp@37
  int v28; // [sp+24h] [bp-2Ch]@10
  float _val; // [sp+28h] [bp-28h]@9
  int totalValue; // [sp+34h] [bp-1Ch]@12
  unsigned int iidSelObject; // [sp+38h] [bp-18h]@1
  InterfacePtr<PlayerDesc> pPD; // [sp+3Ch] [bp-14h]@12
  ItemUses uses; // [sp+44h] [bp-Ch]@29
  InterfacePtr<Interface> result; // [sp+48h] [bp-8h]@12

  v3 = ACCWeenieObject::selectedID;
  v4 = this;
  v5 = this->m_iidSelectedObject == ACCWeenieObject::selectedID;
  iidSelObject = ACCWeenieObject::selectedID;
  if ( !v5 )
  {
    v6 = this->m_pSelObjectName;
    v4->m_iidSelectedObject = ACCWeenieObject::selectedID;
    UIElement_Text::SetText(v6, &PStringBase<unsigned short>::null_string);
    ((void (__stdcall *)(_DWORD))v4->m_pSelObjectField->vfptr[13].__vecDelDtor)(0);
    if ( (*((_DWORD *)&v4->m_pSelObjectHealthMeter->0 + 41) >> 1) & 1 )
    {
      CM_Combat::Event_QueryHealth(0);
      ((void (__stdcall *)(_DWORD))v4->m_pSelObjectHealthMeter->vfptr[2].__vecDelDtor)(0);
    }
    if ( (*((_DWORD *)&v4->m_pSelObjectManaMeter->0 + 41) >> 1) & 1 )
    {
      CM_Item::Event_QueryItemMana(0);
      ((void (__stdcall *)(_DWORD))v4->m_pSelObjectManaMeter->vfptr[2].__vecDelDtor)(0);
    }
    ((void (__stdcall *)(_DWORD))v4->m_pStackSizeEntryBox->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v4->m_pStackSizeSlider->vfptr[2].__vecDelDtor)(0);
  }
  v7 = v4->m_iidSelectedObject;
  if ( v7 )
  {
    _val = a3;
    v8 = ClientObjMaintSystem::GetWeenieObject(v7);
    v9 = v8;
    if ( v8 )
    {
      v28 = a2;
      if ( ACCWeenieObject::IsCoinstack((ACCWeenieObject *)v8)
        && ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v9) )
      {
        totalValue = 0;
        v10 = GetClassObject(&result, &PlayerDesc_ClassType_11);
        InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&pPD, v10);
        if ( (_DWORD)result.m_pInterface )
          ((void (__cdecl *)(int))result.m_pInterface->vfptr->Release)(a2);
        v11 = pPD.m_pInterface;
        if ( (_DWORD)pPD.m_pInterface && (pPD.m_trStatus.m_val & 0x80000000) == 0 )
          CBaseQualities::InqInt((CBaseQualities *)&pPD.m_pInterface->vfptr, 0x14u, &totalValue, 0, 0);
        v12 = v9[20].id;
        v13 = totalValue;
        v14 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v9, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&pPD,
          0,
          L"%d %hs (of %d)",
          v12,
          v14,
          v13);
        UIElement_Text::SetText(v4->m_pSelObjectName, v15);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&pPD);
        if ( v11 )
          v11->vfptr->Release((Interface *)v11);
        v3 = iidSelObject;
      }
      else
      {
        v22 = v9[20].id;
        v23 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v9, NAME_APPROPRIATE, 0);
        if ( v22 <= 1 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&pPD, 0, v23);
          UIElement_Text::SetText(v4->m_pSelObjectName, v26);
          v27 = (char *)&pPD.m_pInterface[-1]._create_list;
          if ( !InterlockedDecrement((volatile LONG *)&pPD.m_pInterface[-1]._create_list + 1) && v27 )
            (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
        }
        else
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&pPD,
            0,
            L"%d %hs",
            v22,
            v23);
          UIElement_Text::SetText(v4->m_pSelObjectName, v24);
          v25 = (char *)&pPD.m_pInterface[-1]._create_list;
          if ( !InterlockedDecrement((volatile LONG *)&pPD.m_pInterface[-1]._create_list + 1) && v25 )
            (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
        }
      }
      GenItemHolder::splitSize = 1;
      GenItemHolder::maxSplitSize = 1;
      ((void (__stdcall *)(_DWORD, int, float))v4->m_pStackSizeEntryBox->vfptr[2].__vecDelDtor)(0, v28, LODWORD(_val));
      ((void (__stdcall *)(_DWORD))v4->m_pStackSizeSlider->vfptr[2].__vecDelDtor)(0);
      v16 = v9[20].id;
      if ( v16 && v16 > 1 )
      {
        if ( ClientUISystem::GetUISystem()->vendorID
          && (v17 = v9[15].vfptr, v17 == (HashBaseData<unsigned long>Vtbl *)ClientUISystem::GetUISystem()->vendorID)
          && ((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[6].__vecDelDtor)(v9) & 0xDC41CB0
          || (v18 = v9[20].id) == 0 )
          v18 = 1;
        GenItemHolder::splitSize = v18;
        GenItemHolder::maxSplitSize = v9[20].id;
        if ( !GenItemHolder::maxSplitSize )
          GenItemHolder::maxSplitSize = 1;
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&uses, 0, L"%d", v18);
        UIElement_Text::SetText(v4->m_pStackSizeEntryBox, v19);
        v20 = uses._useable_bitfield - 20;
        if ( !InterlockedDecrement((volatile LONG *)(uses._useable_bitfield - 20 + 4)) && v20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
        v21 = (double)(unsigned int)GenItemHolder::splitSize / (double)GenItemHolder::maxSplitSize;
        UIElement::SetAttribute_Float((UIElement *)&v4->m_pStackSizeSlider->vfptr, 0x86u, v21);
        ((void (__cdecl *)(signed int))v4->m_pSelObjectField->vfptr[13].__vecDelDtor)(268435468);
        ((void (__stdcall *)(signed int))v4->m_pStackSizeEntryBox->vfptr[2].__vecDelDtor)(1);
        ((void (__stdcall *)(signed int))v4->m_pStackSizeSlider->vfptr[2].__vecDelDtor)(1);
      }
      else if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[4].__vecDelDtor)(v9)
             || v9[26].id
             || (ClientCombatSystem::GetCombatSystem(), ClientCombatSystem::ObjectIsAttackable(v3)) )
      {
        ((void (__cdecl *)(signed int))v4->m_pSelObjectField->vfptr[13].__vecDelDtor)(268435467);
        CM_Combat::Event_QueryHealth(v4->m_iidSelectedObject);
      }
      else
      {
        ((void (__cdecl *)(signed int))v4->m_pSelObjectField->vfptr[13].__vecDelDtor)(268435467);
        if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v9) )
          CM_Item::Event_QueryItemMana(v4->m_iidSelectedObject);
      }
      ItemUses::ItemUses((ItemUses *)&result, (const unsigned int)v9[18].vfptr);
      if ( v9[19].id
        || ((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[6].__vecDelDtor)(v9) & 4
        || ((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[6].__vecDelDtor)(v9) & 2
        || ((int (__thiscall *)(_DWORD))v9->vfptr[6].__vecDelDtor)(v9) & 8
        || ItemUses::IsUseable((ItemUses *)&result) )
        ((void (__thiscall *)(UIElement *))v4->m_pUseObjectButton->vfptr[13].__vecDelDtor)(v4->m_pUseObjectButton);
      else
        ((void (__cdecl *)(signed int))v4->m_pUseObjectButton->vfptr[13].__vecDelDtor)(13);
    }
  }
  else
  {
    ((void (__stdcall *)(signed int))v4->m_pUseObjectButton->vfptr[13].__vecDelDtor)(1);
  }
}
// 4BF380: could not find valid save-restore pair for ebp
// 4BF380: could not find valid save-restore pair for edi

//----- (004BF810) --------------------------------------------------------  // acclient.c:241957
void __thiscall gmToolbarUI::UpdateFromPlayerDesc(gmToolbarUI *this)
{
  gmToolbarUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  CPlayerModule *v4; // edi@5
  char *v5; // edi@8
  int v6; // esi@8
  int v7; // eax@9
  unsigned int v8; // eax@10
  int v9; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v12; // [sp+18h] [bp-Ch]@3
  InterfacePtr<CPlayerModule> playerModule; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  gmToolbarUI::FlushShortcuts(this);
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &CPlayerModule_ClassType_3, &_rpInterface);
  v9 = (int)_rpInterface;
  v3 = _rpInterface;
  playerModule.m_pInterface = 0;
  playerModule.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  _rpInterface = *(Interface **)InterfacePtr<CPlayerModule>::_QueryInterface(&playerModule, (int)&v12, v9, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = playerModule.m_pInterface;
  if ( (_DWORD)playerModule.m_pInterface
    && (signed int)_rpInterface >= 0
    && CInputManager::GetMouseX((PlayerModule *)&playerModule.m_pInterface->vfptr) )
  {
    v5 = (char *)CInputManager::GetMouseX((PlayerModule *)&v4->vfptr)->shortCuts_;
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)&v5[4 * v6];
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 8);
        if ( v8 )
          gmToolbarUI::AddShortcut(v1, v8, v6, 0);
      }
      ++v6;
    }
    while ( v6 < 18 );
    v4 = playerModule.m_pInterface;
  }
  gmToolbarUI::UpdateAmmoID(v1);
  if ( v4 )
    v4->vfptr->Release((Interface *)v4);
}

//----- (004BF8F0) --------------------------------------------------------  // acclient.c:242014
void __userpurge gmToolbarUI::RecvNotice_ItemAttributesChanged(gmToolbarUI *this@<ecx>, int a2@<ebp>, unsigned int i_target, unsigned int i_attrib)
{
  float v4; // edi@1
  HashBaseData<unsigned long> *v5; // eax@2
  signed int v6; // eax@3
  unsigned int v7; // eax@8

  v4 = *(float *)&this;
  if ( i_target == ACCWeenieObject::selectedID )
  {
    v5 = ClientObjMaintSystem::GetWeenieObject(i_target);
    if ( v5 )
    {
      v6 = v5[20].id;
      if ( !v6 )
        v6 = 1;
      if ( v6 != GenItemHolder::maxSplitSize )
        gmToolbarUI::HandleSelectionChanged((gmToolbarUI *)(LODWORD(v4) - 1528), a2, v4);
    }
  }
  if ( SmartBox::smartbox )
    v7 = SmartBox::smartbox->player_id;
  else
    v7 = 0;
  if ( i_target == v7 )
  {
    gmToolbarUI::UpdateAmmoID((gmToolbarUI *)(LODWORD(v4) - 1528));
  }
  else if ( i_target == *(_DWORD *)(LODWORD(v4) + 80) )
  {
    gmToolbarUI::UpdateAmmoNumber((gmToolbarUI *)(LODWORD(v4) - 1528));
  }
}

//----- (004BF970) --------------------------------------------------------  // acclient.c:242049
void __usercall gmToolbarUI::RecvNotice_SelectionChanged(gmToolbarUI *this@<ecx>, int a2@<ebp>, float a3@<edi>)
{
  gmToolbarUI::HandleSelectionChanged((gmToolbarUI *)((char *)this - 1528), a2, a3);
}

//----- (004BF980) --------------------------------------------------------  // acclient.c:242055
void __thiscall gmToolbarUI::RecvNotice_PlayerDescReceived(gmToolbarUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmToolbarUI::UpdateFromPlayerDesc((gmToolbarUI *)((char *)this - 1528));
}

//----- (006F2440) --------------------------------------------------------  // acclient.c:774683
void _E91_83()
{
  outside_val_75 = 1000.0 + 1.0;
}

//----- (006F2460) --------------------------------------------------------  // acclient.c:774689
void _E93_59()
{
  block_length_75 = 24.0 * 8.0;
}

//----- (006F2480) --------------------------------------------------------  // acclient.c:774695
void _E95_59()
{
  half_square_length_75 = 24.0 * 0.5;
}

//----- (006F24A0) --------------------------------------------------------  // acclient.c:774701
int _E97_84()
{
  return atexit(_E98_96);
}

//----- (006F24B0) --------------------------------------------------------  // acclient.c:774707
int _E100_77()
{
  return atexit(nullsub_776);
}

//----- (006F24C0) --------------------------------------------------------  // acclient.c:774713
int _E103_69()
{
  return atexit(_E104_84);
}

//----- (006F24D0) --------------------------------------------------------  // acclient.c:774719
void _E109_33()
{
  DEFAULT_VIEW_RADIUS_46 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F24F0) --------------------------------------------------------  // acclient.c:774725
void _E111_22()
{
  MIN_QUANTUM_46 = 1.0 / 30.0;
}

//----- (006F2510) --------------------------------------------------------  // acclient.c:774731
void _E113_10()
{
  MAX_QUANTUM_46 = 1.0 / 5.0;
}

//----- (006F2530) --------------------------------------------------------  // acclient.c:774737
void _E115_36()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_81, PFID_A8R8G8B8);
}

//----- (006F2540) --------------------------------------------------------  // acclient.c:774743
void _E118_41()
{
  LOWEST_DATA_RATE_83 = 1024;
}

//----- (006F2550) --------------------------------------------------------  // acclient.c:774749
void _E120_29()
{
  HIGHEST_DATA_RATE_83 = 0x7FFF;
}

//----- (006F2560) --------------------------------------------------------  // acclient.c:774755
int _E122_15()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_83;
  INITIAL_MAX_DATA_RATE_31 = LOWEST_DATA_RATE_83;
  return result;
}

//----- (006F2570) --------------------------------------------------------  // acclient.c:774765
int _E124_38()
{
  return atexit(_E125_44);
}

//----- (006F2580) --------------------------------------------------------  // acclient.c:774771
int _E127_33()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_31, "Misc.TooltipEnable");
  return atexit(_E128_44);
}

//----- (006F25A0) --------------------------------------------------------  // acclient.c:774778
int _E130_27()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_31, "Misc.TooltipDelay");
  return atexit(_E131_34);
}

//----- (006F25C0) --------------------------------------------------------  // acclient.c:774785
unsigned int _E133_23()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Toolbar_TT_Show");
  ID_Toolbar_TT_Show = result;
  return result;
}

//----- (006F25E0) --------------------------------------------------------  // acclient.c:774795
unsigned int _E135_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Toolbar_TT_Hide");
  ID_Toolbar_TT_Hide = result;
  return result;
}

//----- (006F2600) --------------------------------------------------------  // acclient.c:774805
unsigned int _E137_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("value");
  token_value = result;
  return result;
}

//----- (006F2620) --------------------------------------------------------  // acclient.c:774815
int sub_6F2620()
{
  return atexit(nullsub_774);
}

//----- (00761390) --------------------------------------------------------  // acclient.c:888725
void __cdecl _E128_44()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007613C0) --------------------------------------------------------  // acclient.c:888738
void __cdecl _E131_34()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

