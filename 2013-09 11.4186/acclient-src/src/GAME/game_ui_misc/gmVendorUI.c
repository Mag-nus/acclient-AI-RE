/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmVendorUI
   Object     : GAME\game_ui_misc\gmVendorUI.obj
   Functions  : 113
   Addresses  : 004C0210 - 007614F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C0210) --------------------------------------------------------  // acclient.c:242494
unsigned int __thiscall VendorSubUI::GetShopVendorID(VendorSubUI *this)
{
  return this->m_parent->shopVendorID;
}

//----- (004C0220) --------------------------------------------------------  // acclient.c:242500
void __stdcall gmVendorUI::SendShopEvent(unsigned int _vendorID, PackableList<ItemProfile> *_itemList, IDClass<_tagDataID,32,0> _altCurrencyID, ShopEvent _event)
{
  unsigned int v5; // esi@3
  ClientUISystem *v6; // eax@5

  if ( _event )
  {
    if ( _event != 1 )
      return;
    v5 = _vendorID;
    CM_Vendor::Event_Sell(_vendorID, _itemList);
  }
  else
  {
    v5 = _vendorID;
    CM_Vendor::Event_Buy(_vendorID, _itemList, _altCurrencyID);
  }
  ACCWeenieObject::RecordRequest(v5, IR_SHOP_EVENT);
  v6 = ClientUISystem::GetUISystem();
  ClientUISystem::IncrementBusyCount(v6);
}

//----- (004C0280) --------------------------------------------------------  // acclient.c:242523
void __thiscall gmVendorUI::RecvNotice_SetSelectedItem(gmVendorUI *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  gmVendorUI *v3; // esi@1

  v3 = this;
  ((void (__stdcall *)(_DWORD, _DWORD))this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr)(
    _oldSelectedID,
    _selectedID);
  ((void (__stdcall *)(unsigned int, unsigned int))v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr)(
    _oldSelectedID,
    _selectedID);
  ((void (__stdcall *)(unsigned int, unsigned int))v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13]->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr)(
    _oldSelectedID,
    _selectedID);
}

//----- (004C02C0) --------------------------------------------------------  // acclient.c:242540
void __thiscall gmVendorUI::RecvNotice_CloseVendor(gmVendorUI *this, bool i_bUpdating)
{
  if ( !i_bUpdating )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[17][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[17],
      0);
}

//----- (004C02F0) --------------------------------------------------------  // acclient.c:242549
void __thiscall gmVendorUI::OnObjectRangeExit(gmVendorUI *this, unsigned int _objectID)
{
  if ( (IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *)_objectID == this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[15][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[15],
      0);
}

//----- (004C0320) --------------------------------------------------------  // acclient.c:242558
void __stdcall gmVendorUI::VendorItemSetSellState(unsigned int _itemID, int _state)
{
  HashBaseData<unsigned long> *v3; // eax@1

  v3 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  if ( v3 )
    ACCWeenieObject::SetSellState((ACCWeenieObject *)v3, _state);
}

//----- (004C0340) --------------------------------------------------------  // acclient.c:242568
void __stdcall gmVendorUI::DeleteItem(UIElement_ItemList *_uiItemList, unsigned int _itemID, int _broadcast)
{
  HashBaseData<unsigned long> *v4; // eax@3

  if ( _uiItemList )
  {
    if ( UIElement_ItemList::ItemList_GetItem(_uiItemList, _itemID) )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
      if ( v4 )
      {
        if ( _uiItemList->m_desc.m_elementID == 268435662 )
          ACCWeenieObject::SetSellState((ACCWeenieObject *)v4, 0);
        UIElement_ItemList::ItemList_DeleteItem(_uiItemList, _itemID);
      }
    }
  }
}

//----- (004C0390) --------------------------------------------------------  // acclient.c:242588
void __thiscall gmVendorUI::OpenTab(gmVendorUI *this, unsigned int _tabID)
{
  gmVendorUI *v2; // eax@1
  UIElement_Panel *v3; // ecx@1

  v2 = this;
  v3 = this->m_vendorPanel;
  if ( v3 )
  {
    v2->m_last_sale = 0;
    UIElement_Panel::OpenTab(v3, _tabID);
  }
}

//----- (004C03B0) --------------------------------------------------------  // acclient.c:242603
void __thiscall gmVendorUI::UpdateDragOver(gmVendorUI *this)
{
  gmVendorUI *v1; // esi@1
  signed int v2; // edi@4
  signed int v3; // ebx@4

  v1 = this;
  if ( UIElement::IsVisible((UIElement *)&this->vfptr) )
  {
    if ( v1->m_vendorPanel->m_OpenPageToken != 268435661 )
    {
      if ( UIElementManager::s_pInstance->m_dragElement )
      {
        v2 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
        v3 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
        if ( v2 > (signed int)UIRegion::GetScreenX0((UIRegion *)&v1->vfptr)
          && v2 < (signed int)UIRegion::GetScreenX1((UIRegion *)&v1->vfptr)
          && v3 > (signed int)UIRegion::GetScreenY0((UIRegion *)&v1->vfptr)
          && v3 < (signed int)UIRegion::GetScreenY1((UIRegion *)&v1->vfptr) )
          gmVendorUI::OpenTab(v1, 0x100000BBu);
      }
    }
  }
}

//----- (004C0440) --------------------------------------------------------  // acclient.c:242629
void __thiscall VendorBuyUI::CloseVendor(VendorBuyUI *this)
{
  UIElement_ItemList::ItemList_Flush(this->m_buyShopList);
}

//----- (004C0450) --------------------------------------------------------  // acclient.c:242635
void __thiscall VendorSellUI::CloseVendor(VendorSellUI *this)
{
  UIElement_ItemList::ItemList_Flush(this->m_sellShopList);
}

//----- (004C0460) --------------------------------------------------------  // acclient.c:242641
PackableHashIterator<IDClass<_tagDataID,32,0>,long> *__thiscall PackableHashIterator<IDClass<_tagDataID,32,0>,long>::scalar_deleting_destructor(PackableHashIterator<IDClass<_tagDataID,32,0>,long> *this, unsigned int a2)
{
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7B4FBC: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (004C0480) --------------------------------------------------------  // acclient.c:242654
void __thiscall gmVendorUI::ListenToGlobalMessage(gmVendorUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 )
    gmVendorUI::UpdateDragOver(this);
}

//----- (004C0490) --------------------------------------------------------  // acclient.c:242661
void __stdcall VendorSubUI::SetObjectStackSize(ACCWeenieObject *_weenObj, int _stackSize)
{
  unsigned int v3; // esi@1

  v3 = _weenObj->pwd._stackSize;
  if ( !_weenObj->pwd._stackSize )
    v3 = 1;
  _weenObj->pwd._value = _stackSize * (_weenObj->pwd._value / v3);
  _weenObj->pwd._stackSize = _stackSize;
}

//----- (004C04D0) --------------------------------------------------------  // acclient.c:242673
void __thiscall VendorItemsUI::VendorItemsUI(VendorItemsUI *this, gmVendorUI *_parentElement)
{
  VendorItemsUI *v2; // esi@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  UIElement *v5; // ecx@4
  UIElement *v6; // eax@4
  int v7; // eax@5
  UIElement *v8; // ecx@7
  UIElement *v9; // eax@7
  UIElement *v10; // ecx@7
  UIElement *v11; // eax@7
  UIElement *v12; // ecx@7
  UIElement *v13; // eax@7
  UIElement *v14; // ecx@7

  v2 = this;
  this->m_parent = _parentElement;
  this->vfptr = (VendorSubUIVtbl *)&VendorItemsUI::vftable;
  this->m_shopList = 0;
  this->m_itemTypeMenu = 0;
  this->m_itemNameText = 0;
  this->m_itemCostText = 0;
  this->m_buyButton = 0;
  this->m_addButton = 0;
  this->m_numTypeFilters = 0;
  v3 = UIElement::GetChildRecursive((UIElement *)&_parentElement->vfptr, 0x100000BDu);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)268435505);
  else
    v4 = 0;
  v5 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_shopList = (UIElement_ItemList *)v4;
  v6 = UIElement::GetChildRecursive(v5, 0x100000BFu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)6);
  else
    v7 = 0;
  v8 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_itemTypeMenu = (UIElement_Menu *)v7;
  v9 = UIElement::GetChildRecursive(v8, 0x100000C0u);
  v10 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_itemNameText = (UIElement_Text *)v9;
  v11 = UIElement::GetChildRecursive(v10, 0x100000C1u);
  v12 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_itemCostText = (UIElement_Text *)v11;
  v13 = UIElement::GetChildRecursive(v12, 0x100000C2u);
  v14 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyButton = v13;
  v2->m_addButton = UIElement::GetChildRecursive(v14, 0x100000C3u);
}
// 7B4FC0: using guessed type void (__thiscall *VendorItemsUI::vftable)(VendorItemsUI *this, bool _updating);

//----- (004C0590) --------------------------------------------------------  // acclient.c:242727
void __thiscall VendorItemsUI::CloseVendor(VendorItemsUI *this)
{
  VendorItemsUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@1

  v1 = this;
  UIElement_ItemList::ItemList_Flush(this->m_shopList);
  v2 = v1->m_shopList;
  if ( v2->m_listItems.m_num )
    UIElement_ListBox::ScrollToShow((UIElement_ListBox *)&v2->vfptr, 0);
  UIElement_Menu::Flush(v1->m_itemTypeMenu);
}

//----- (004C05C0) --------------------------------------------------------  // acclient.c:242741
void __thiscall VendorItemsUI::AddTypeFilter(VendorItemsUI *this, StringInfo *_text, unsigned int _filter)
{
  VendorItemsUI *v3; // esi@1
  UIElement_Menu *v4; // ecx@1
  UIElement_Text *v5; // edi@2
  BasePropertyDesc *v6; // eax@5
  bool v7; // zf@5
  unsigned int v8; // esi@6
  BasePropertyValue *v9; // ecx@10
  unsigned int v10; // edx@10
  BaseProperty filterProp; // [sp+Ch] [bp-8h]@3

  v3 = this;
  v4 = this->m_itemTypeMenu;
  if ( v4 )
  {
    v5 = UIElement_Menu::InsertTextItem(v4, _text, v3->m_numTypeFilters);
    if ( v5 )
    {
      filterProp.m_pcPropertyDesc = 0;
      filterProp.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&filterProp, 0x10000039u);
      if ( filterProp.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&filterProp);
        ((void (__stdcall *)(_DWORD))filterProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(_filter);
      }
      ((void (__thiscall *)(UIElement_Text *, BaseProperty *))v5->vfptr[17].OnLoseFocus)(v5, &filterProp);
      v6 = filterProp.m_pcPropertyDesc;
      v7 = (_DWORD)filterProp.m_pcPropertyDesc == 0;
      ++v3->m_numTypeFilters;
      if ( !v7 )
      {
        v8 = v6->m_cRef;
        v6->m_cRef = v8 - 1;
        if ( v8 == 1 )
          ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
        filterProp.m_pcPropertyDesc = 0;
      }
      if ( filterProp.m_pcPropertyValue )
      {
        v9 = filterProp.m_pcPropertyValue;
        v10 = filterProp.m_pcPropertyValue->m_cRef - 1;
        filterProp.m_pcPropertyValue->m_cRef = v10;
        if ( !v10 )
          ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (004C0690) --------------------------------------------------------  // acclient.c:242793
void __thiscall VendorBuyUI::VendorBuyUI(VendorBuyUI *this, gmVendorUI *_parentElement)
{
  VendorBuyUI *v2; // esi@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  UIElement *v5; // ecx@4
  UIElement *v6; // eax@4
  UIElement *v7; // ecx@4
  UIElement *v8; // eax@4
  UIElement *v9; // ecx@4
  UIElement *v10; // eax@4
  UIElement *v11; // ecx@4
  UIElement *v12; // eax@4
  UIElement *v13; // ecx@4
  UIElement *v14; // eax@4
  UIElement *v15; // ecx@4

  v2 = this;
  this->m_parent = _parentElement;
  this->vfptr = (VendorSubUIVtbl *)&VendorBuyUI::vftable;
  this->m_buyShopList = 0;
  this->m_buyListText = 0;
  this->m_buyPurseText = 0;
  this->m_buyItemButton = 0;
  this->m_buyAllButton = 0;
  this->m_buyClearItemButton = 0;
  this->m_buyClearListButton = 0;
  this->m_transactionValue = 0;
  v3 = UIElement::GetChildRecursive((UIElement *)&_parentElement->vfptr, 0x100000C5u);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)268435505);
  else
    v4 = 0;
  v5 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyShopList = (UIElement_ItemList *)v4;
  v6 = UIElement::GetChildRecursive(v5, 0x100000C7u);
  v7 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyListText = (UIElement_Text *)v6;
  v8 = UIElement::GetChildRecursive(v7, 0x100000C8u);
  v9 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyPurseText = (UIElement_Text *)v8;
  v10 = UIElement::GetChildRecursive(v9, 0x100000C9u);
  v11 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyItemButton = v10;
  v12 = UIElement::GetChildRecursive(v11, 0x100000CAu);
  v13 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyAllButton = v12;
  v14 = UIElement::GetChildRecursive(v13, 0x100000CBu);
  v15 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_buyClearItemButton = v14;
  v2->m_buyClearListButton = UIElement::GetChildRecursive(v15, 0x100000CCu);
}
// 7B4FCC: using guessed type void (__thiscall *VendorBuyUI::vftable)(VendorBuyUI *this, bool _updating);

//----- (004C0750) --------------------------------------------------------  // acclient.c:242848
void __thiscall VendorSellUI::VendorSellUI(VendorSellUI *this, gmVendorUI *_parentElement)
{
  VendorSellUI *v2; // esi@1
  ItemListDragHandler *v3; // ebx@1
  UIElement *v4; // ecx@1
  UIElement *v5; // eax@1
  UIElement_ItemList *v6; // eax@2
  UIElement *v7; // eax@6
  UIElement *v8; // ecx@6
  UIElement *v9; // eax@6
  UIElement *v10; // ecx@6
  UIElement *v11; // eax@6
  UIElement *v12; // ecx@6
  UIElement *v13; // eax@6
  UIElement *v14; // ecx@6
  UIElement *v15; // eax@6
  UIElement *v16; // ecx@6

  v2 = this;
  this->m_parent = _parentElement;
  this->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v3 = (ItemListDragHandler *)&this->vfptr;
  this->vfptr = (VendorSubUIVtbl *)&VendorSellUI::vftable;
  this->vfptr = (ItemListDragHandlerVtbl *)&VendorSellUI::vftable;
  this->m_sellShopList = 0;
  this->m_sellListText = 0;
  this->m_sellPurseText = 0;
  this->m_sellItemButton = 0;
  this->m_sellAllButton = 0;
  this->m_sellClearItemButton = 0;
  this->m_sellClearListButton = 0;
  this->m_transactionValue = 0;
  this->m_splitItem = 0;
  this->m_splitItemClassID.id = stru_83F540.id;
  v4 = (UIElement *)&this->m_parent->vfptr;
  v2->m_splitItemStackSize = -1;
  v5 = UIElement::GetChildRecursive(v4, 0x100000CEu);
  if ( v5 )
    v6 = (UIElement_ItemList *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435505);
  else
    v6 = 0;
  v2->m_sellShopList = v6;
  if ( v6 )
    UIElement_ItemList::RegisterItemListDragHandler(v6, v3);
  v7 = UIElement::GetChildRecursive((UIElement *)&v2->m_parent->vfptr, 0x100000D0u);
  v8 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_sellListText = (UIElement_Text *)v7;
  v9 = UIElement::GetChildRecursive(v8, 0x100000D1u);
  v10 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_sellPurseText = (UIElement_Text *)v9;
  v11 = UIElement::GetChildRecursive(v10, 0x100000D2u);
  v12 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_sellItemButton = v11;
  v13 = UIElement::GetChildRecursive(v12, 0x100000D3u);
  v14 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_sellAllButton = v13;
  v15 = UIElement::GetChildRecursive(v14, 0x100000D4u);
  v16 = (UIElement *)&v2->m_parent->vfptr;
  v2->m_sellClearItemButton = v15;
  v2->m_sellClearListButton = UIElement::GetChildRecursive(v16, 0x100000D5u);
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B4F98: using guessed type bool (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B4F9C: using guessed type void (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, bool _updating);

//----- (004C0840) --------------------------------------------------------  // acclient.c:242914
void __thiscall PackableList<ItemProfile>::InsertHead(PackableList<ItemProfile> *this, ItemProfile *val)
{
  PackableList<ItemProfile> *v2; // esi@1
  void *v3; // edi@1
  PackableLLNode<ItemProfile> *v4; // eax@4
  unsigned int v5; // eax@5
  unsigned int v6; // eax@6

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    ItemProfile::ItemProfile((ItemProfile *)v3, val);
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
  }
  else
  {
    v3 = 0;
  }
  v4 = v2->head;
  if ( v4 )
  {
    v4->prev = (PackableLLNode<ItemProfile> *)v3;
    *((_DWORD *)v3 + 4) = v4;
    v6 = v2->curNum;
    v2->head = (PackableLLNode<ItemProfile> *)v3;
    v2->curNum = v6 + 1;
  }
  else
  {
    v5 = v2->curNum;
    v2->tail = (PackableLLNode<ItemProfile> *)v3;
    v2->head = (PackableLLNode<ItemProfile> *)v3;
    v2->curNum = v5 + 1;
  }
}

//----- (004C08A0) --------------------------------------------------------  // acclient.c:242953
int __thiscall PackableList<ItemProfile>::InsertTail(PackableList<ItemProfile> *this, ItemProfile *val)
{
  PackableList<ItemProfile> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<ItemProfile> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    ItemProfile::ItemProfile((ItemProfile *)v3, val);
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<ItemProfile> *)v3;
    *((_DWORD *)v3 + 5) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<ItemProfile> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<ItemProfile> *)v3;
    v2->tail = (PackableLLNode<ItemProfile> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (004C09A0) --------------------------------------------------------  // acclient.c:243040
void __thiscall gmVendorUI::PostInit(gmVendorUI *this)
{
  gmVendorUI *v1; // edi@1
  VendorItemsUI *v2; // eax@1
  VendorItemsUI *v3; // eax@2
  VendorBuyUI *v4; // eax@4
  VendorBuyUI *v5; // eax@5
  VendorSellUI *v6; // eax@7
  VendorSellUI *v7; // eax@8
  GlobalEventHandler *v8; // eax@10
  GlobalEventHandler *v9; // esi@10
  UIElement *v10; // eax@12

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = (VendorItemsUI *)operator new(0x24u);
  if ( v2 )
    VendorItemsUI::VendorItemsUI(v2, v1);
  else
    v3 = 0;
  v1->m_itemsUI = v3;
  v4 = (VendorBuyUI *)operator new(0x28u);
  if ( v4 )
    VendorBuyUI::VendorBuyUI(v4, v1);
  else
    v5 = 0;
  v1->m_buyUI = v5;
  v6 = (VendorSellUI *)operator new(0x38u);
  if ( v6 )
    VendorSellUI::VendorSellUI(v6, v1);
  else
    v7 = 0;
  v1->m_sellUI = v7;
  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = v8;
  if ( v8 )
  {
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD20C + 2),
      (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, (unsigned int)&loc_4DD218, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 100010u, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 100011u, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100118u, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 100008u, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100115u, (NoticeHandler *)&v1->vfptr);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100121u, (NoticeHandler *)&v1->vfptr);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    20,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    5,
    &v1->vfptr);
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000B8u);
  if ( v10 )
    v1->m_vendorPanel = (UIElement_Panel *)v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)8);
  else
    v1->m_vendorPanel = 0;
}

//----- (004C0AF0) --------------------------------------------------------  // acclient.c:243106
int __thiscall VendorProfile::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@1
  int v4; // edi@5

  v2 = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  v3 = *(_DWORD *)(this + 36);
  if ( v3 != *(_DWORD *)(a2 + 36) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(v2 + 36) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  return v2;
}

//----- (004C0B70) --------------------------------------------------------  // acclient.c:243134
char __thiscall gmVendorUI::ShopHasItem(gmVendorUI *this, IDClass<_tagDataID,32,0> wcidRequestedItem, int *amount_to_buy, unsigned int *retval)
{
  PackableLLNode<ItemProfile> *i; // esi@1
  HashBaseData<unsigned long> *v5; // eax@3
  int v6; // eax@6

  for ( i = this->shopItemProfileList->head; ; i = i->next )
  {
    if ( !i )
      return 0;
    v5 = ClientObjMaintSystem::GetWeenieObject(i->data.iid);
    if ( v5 )
    {
      if ( v5[13].id == wcidRequestedItem.id )
        break;
    }
  }
  v6 = i->data.amount;
  if ( v6 != -1 && v6 < *amount_to_buy )
    *amount_to_buy = v6;
  *retval = i->data.iid;
  return 1;
}

//----- (004C0BD0) --------------------------------------------------------  // acclient.c:243159
void __stdcall gmVendorUI::FlushSellListSellState(PackableList<ItemProfile> *_list)
{
  PackableLLNode<ItemProfile> *i; // esi@1
  HashBaseData<unsigned long> *v3; // eax@2

  for ( i = _list->head; i; i = i->next )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(i->data.iid);
    if ( v3 )
      ACCWeenieObject::SetSellState((ACCWeenieObject *)v3, 0);
  }
}

//----- (004C0C10) --------------------------------------------------------  // acclient.c:243173
void __stdcall gmVendorUI::InqListSlotCount(PackableList<ItemProfile> *_list, unsigned int *_itemCount, unsigned int *_containerCount)
{
  PackableLLNode<ItemProfile> *i; // esi@1
  HashBaseData<unsigned long> *v5; // eax@2
  HashBaseData<unsigned long> *v6; // ecx@3

  *_itemCount = 0;
  *_containerCount = 0;
  for ( i = _list->head; i; i = i->next )
  {
    v5 = ClientObjMaintSystem::GetWeenieObject(i->data.iid);
    if ( v5 )
    {
      v6 = v5[21].hash_next;
      if ( v5[21].vfptr <= (HashBaseData<unsigned long>Vtbl *)1 )
      {
        if ( (unsigned int)v6 & (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)"
          || v5[16].id
          || v5[17].vfptr )
          *_containerCount += i->data.amount;
        else
          *_itemCount += i->data.amount;
      }
      else if ( (unsigned int)v6 & (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)"
             || v5[16].id
             || v5[17].vfptr )
      {
        ++*_containerCount;
      }
      else
      {
        ++*_itemCount;
      }
    }
  }
}

//----- (004C0CC0) --------------------------------------------------------  // acclient.c:243211
void __thiscall VendorItemsUI::UpdateQuantityOverlay(VendorItemsUI *this)
{
  _Formatted v1; // ebp@1
  VendorItemsUI *v2; // ebx@1
  UIElement_ItemList *v3; // ecx@2
  unsigned int v4; // esi@2
  UIElement *v5; // eax@3
  int v6; // eax@4
  UIElement_UIItem *v7; // edi@4
  int v8; // eax@8
  ItemProfile curProfile; // [sp+8h] [bp-10h]@8

  v1 = ACCWeenieObject::selectedID;
  v2 = this;
  if ( ACCWeenieObject::selectedID )
  {
    v3 = this->m_shopList;
    v4 = 0;
    if ( (signed int)v3->m_listItems.m_num > 0 )
    {
      while ( 1 )
      {
        v5 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v3->vfptr, v4);
        if ( v5 )
        {
          v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
          v7 = (UIElement_UIItem *)v6;
          if ( v6 )
          {
            if ( *(_DWORD *)(v6 + 1532) == v1 )
              break;
          }
        }
        v3 = v2->m_shopList;
        ++v4;
        if ( (signed int)v4 >= (signed int)v3->m_listItems.m_num )
          return;
      }
      ItemProfile::ItemProfile(&curProfile);
      v8 = (int)v2->m_parent->shopItemProfileList->head;
      if ( v8 )
      {
        while ( *(_DWORD *)(v8 + 8) != v1 )
        {
          v8 = *(_DWORD *)(v8 + 16);
          if ( !v8 )
            goto LABEL_13;
        }
        ItemProfile::operator=((int)&curProfile, v8);
      }
LABEL_13:
      if ( curProfile.amount <= 0 )
        UIElement_UIItem::SetQuantity(v7, -1);
      else
        UIElement_UIItem::SetQuantity(v7, curProfile.amount);
      UIElement_UIItem::UIItem_Update(v7);
      ItemProfile::~ItemProfile(&curProfile);
    }
  }
}

//----- (004C0D90) --------------------------------------------------------  // acclient.c:243273
char __stdcall VendorItemsUI::ListContainsType(PackableList<ItemProfile> *_list, int _types)
{
  int v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@2
  char result; // al@6
  ItemProfile profile; // [sp+8h] [bp-10h]@1

  ItemProfile::ItemProfile(&profile);
  v3 = (int)_list->head;
  if ( v3 )
  {
    while ( 1 )
    {
      ItemProfile::operator=((int)&profile, v3);
      v4 = ClientObjMaintSystem::GetWeenieObject(profile.iid);
      if ( v4 )
      {
        if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[6].__vecDelDtor)(v4) & _types )
          break;
      }
      if ( v3 )
      {
        v3 = *(_DWORD *)(v3 + 16);
        if ( v3 )
          continue;
      }
      goto LABEL_6;
    }
    ItemProfile::~ItemProfile(&profile);
    result = 1;
  }
  else
  {
LABEL_6:
    ItemProfile::~ItemProfile(&profile);
    result = 0;
  }
  return result;
}

//----- (004C0E10) --------------------------------------------------------  // acclient.c:243314
void __thiscall VendorBuyUI::UpdateBuyUI(VendorBuyUI *this)
{
  VendorBuyUI *v1; // esi@1
  int v2; // eax@1
  bool v3; // sf@1
  unsigned __int8 v4; // of@1
  IInputActionCallbackVtbl *v5; // eax@1
  PackableLLNode<ItemProfile> *v6; // eax@4
  char v7; // al@7
  signed int v8; // edi@8
  int v9; // [sp+0h] [bp-8h]@0

  v1 = this;
  v2 = UIElement_ItemList::GetNumUIItems(this->m_buyShopList);
  v4 = __OFSUB__(v2, 1);
  v3 = v2 - 1 < 0;
  v5 = v1->m_buyClearListButton->vfptr;
  if ( v3 ^ v4 )
  {
    ((void (__stdcall *)(signed int, int))v5[13].__vecDelDtor)(13, v9);
    ((void (__cdecl *)(signed int))v1->m_buyAllButton->vfptr[13].__vecDelDtor)(13);
  }
  else
  {
    ((void (__stdcall *)(signed int, int))v5[13].__vecDelDtor)(1, v9);
    ((void (__cdecl *)(signed int))v1->m_buyAllButton->vfptr[13].__vecDelDtor)(1);
  }
  v6 = v1->m_parent->m_buyList.head;
  if ( v6 )
  {
    while ( v6->data.iid != ACCWeenieObject::selectedID )
    {
      v6 = v6->next;
      if ( !v6 )
        goto LABEL_7;
    }
    v7 = 1;
  }
  else
  {
LABEL_7:
    v7 = 0;
  }
  v8 = v7 != 0 ? 1 : 13;
  ((void (__stdcall *)(signed int))v1->m_buyClearItemButton->vfptr[13].__vecDelDtor)(v8);
  ((void (__stdcall *)(signed int))v1->m_buyItemButton->vfptr[13].__vecDelDtor)(v8);
}

//----- (004C0EA0) --------------------------------------------------------  // acclient.c:243363
void __thiscall VendorBuyUI::HandleSetSelectedItem(VendorBuyUI *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  if ( _oldSelectedID != _selectedID )
    VendorBuyUI::UpdateBuyUI(this);
}

//----- (004C0EC0) --------------------------------------------------------  // acclient.c:243370
void __thiscall VendorSellUI::UpdateSellUI(VendorSellUI *this)
{
  VendorSellUI *v1; // esi@1
  int v2; // eax@1
  bool v3; // sf@1
  unsigned __int8 v4; // of@1
  IInputActionCallbackVtbl *v5; // eax@1
  PackableLLNode<ItemProfile> *v6; // eax@4
  char v7; // al@7
  signed int v8; // edi@8
  int v9; // [sp+0h] [bp-8h]@0

  v1 = this;
  v2 = UIElement_ItemList::GetNumUIItems(this->m_sellShopList);
  v4 = __OFSUB__(v2, 1);
  v3 = v2 - 1 < 0;
  v5 = v1->m_sellClearListButton->vfptr;
  if ( v3 ^ v4 )
  {
    ((void (__stdcall *)(signed int, int))v5[13].__vecDelDtor)(13, v9);
    ((void (__cdecl *)(signed int))v1->m_sellAllButton->vfptr[13].__vecDelDtor)(13);
  }
  else
  {
    ((void (__stdcall *)(signed int, int))v5[13].__vecDelDtor)(1, v9);
    ((void (__cdecl *)(signed int))v1->m_sellAllButton->vfptr[13].__vecDelDtor)(1);
  }
  v6 = v1->m_parent->m_sellList.head;
  if ( v6 )
  {
    while ( v6->data.iid != ACCWeenieObject::selectedID )
    {
      v6 = v6->next;
      if ( !v6 )
        goto LABEL_7;
    }
    v7 = 1;
  }
  else
  {
LABEL_7:
    v7 = 0;
  }
  v8 = v7 != 0 ? 1 : 13;
  ((void (__stdcall *)(signed int))v1->m_sellClearItemButton->vfptr[13].__vecDelDtor)(v8);
  ((void (__stdcall *)(signed int))v1->m_sellItemButton->vfptr[13].__vecDelDtor)(v8);
}

//----- (004C0F50) --------------------------------------------------------  // acclient.c:243419
void __thiscall VendorSellUI::HandleSetSelectedItem(VendorSellUI *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  if ( VendorSubUI::GetShopVendorID )
  {
    if ( _oldSelectedID != _selectedID )
      VendorSellUI::UpdateSellUI(this);
  }
}

//----- (004C0F70) --------------------------------------------------------  // acclient.c:243429
int __thiscall PackableList<ItemProfile>::RemoveTail(PackableList<ItemProfile> *this, ItemProfile *retVal)
{
  PackableList<ItemProfile> *v2; // esi@1
  int result; // eax@2
  int v4; // edi@3
  int v5; // eax@3

  v2 = this;
  if ( this->head )
  {
    v4 = (int)this->tail;
    v5 = *(_DWORD *)(v4 + 20);
    this->tail = (PackableLLNode<ItemProfile> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 16) = 0;
    else
      this->head = 0;
    ItemProfile::operator=((int)retVal, v4);
    if ( v4 )
    {
      ItemProfile::~ItemProfile((ItemProfile *)v4);
      operator delete((void *)v4);
    }
    --v2->curNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C0FD0) --------------------------------------------------------  // acclient.c:243463
int __thiscall PackableList<ItemProfile>::Remove(PackableList<ItemProfile> *this, ItemProfile *val)
{
  PackableList<ItemProfile> *v2; // edi@1
  ItemProfile *v3; // ecx@1
  int result; // eax@2
  ItemProfile *v5; // esi@3
  PackableLLNode<ItemProfile> *v6; // eax@4
  PackObjVtbl *v7; // ebx@14
  int (__cdecl *v8)(PackObj *, sockaddr_in *, void **, unsigned int); // eax@14

  v2 = this;
  v3 = &this->head->data;
  if ( v3 )
  {
    v5 = v3;
    if ( ItemProfile::operator==(v3, val) )
    {
      ItemProfile::operator=((int)val, (int)v2->head);
      v6 = v2->head->next;
      v2->head = v6;
      if ( v6 )
        v6->prev = 0;
      else
        v2->tail = 0;
      if ( v5 )
      {
        ItemProfile::~ItemProfile(v5);
        operator delete(v5);
      }
      --v2->curNum;
      result = 1;
    }
    else if ( v5[1].vfptr )
    {
      while ( !ItemProfile::operator==((ItemProfile *)v5[1].vfptr, val) )
      {
        v5 = (ItemProfile *)v5[1].vfptr;
        if ( !v5[1].vfptr )
          goto LABEL_13;
      }
      ItemProfile::operator=((int)val, (int)v5[1].vfptr);
      v7 = v5[1].vfptr;
      v8 = v7->UnPack;
      v5[1].vfptr = (PackObjVtbl *)v8;
      if ( v8 )
        *((_DWORD *)v8 + 5) = v5;
      else
        v2->tail = (PackableLLNode<ItemProfile> *)v5;
      ItemProfile::~ItemProfile((ItemProfile *)v7);
      operator delete(v7);
      --v2->curNum;
      result = 1;
    }
    else
    {
LABEL_13:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C10B0) --------------------------------------------------------  // acclient.c:243530
void __thiscall PackableList<ItemProfile>::Flush(PackableList<ItemProfile> *this)
{
  PackableList<ItemProfile> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  ItemProfile dummyData; // [sp+8h] [bp-10h]@1

  v1 = this;
  ItemProfile::ItemProfile(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 16);
      v1->head = (PackableLLNode<ItemProfile> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 20) = 0;
      else
        v1->tail = 0;
      ItemProfile::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        ItemProfile::~ItemProfile((ItemProfile *)v2);
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
  ItemProfile::~ItemProfile(&dummyData);
}

//----- (004C1120) --------------------------------------------------------  // acclient.c:243563
int __thiscall PackableList<ItemProfile>::UnPack(PackableList<ItemProfile> *this, void **addr, unsigned int size)
{
  PackableList<ItemProfile> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  ItemProfile temp; // [sp+8h] [bp-10h]@2

  v3 = this;
  PackableList<ItemProfile>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    ItemProfile::ItemProfile(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      ItemProfile::~ItemProfile(&temp);
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(ItemProfile *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<ItemProfile>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      ItemProfile::~ItemProfile(&temp);
      result = 0;
    }
  }
  return result;
}

//----- (004C11B0) --------------------------------------------------------  // acclient.c:243606
int __thiscall InterfacePtr<ClientObjMaintSystem>::_QueryInterface(void *this, int a2, int a3, int a4)
{
  int v4; // edi@1
  void *v5; // esi@1
  int v6; // eax@2
  signed int v7; // ebx@2
  int v8; // ecx@2
  int v10; // ebp@6
  int v11; // ecx@9
  char v12; // [sp+10h] [bp-4h]@2

  v4 = a3;
  v5 = this;
  if ( a3 )
  {
    v6 = *(_DWORD *)a3;
    a3 = 0;
    v7 = *(_DWORD *)(*(int (__thiscall **)(int, char *, Turbine_GUID *, int *))(v6 + 12))(
                      v4,
                      &v12,
                      &ClientObjMaintSystem_InterfaceType_31,
                      &a3);
    v8 = *(_DWORD *)v5;
    if ( v7 < 0 )
    {
      if ( v8 )
        (*(void (**)(void))(*(_DWORD *)v8 + 20))();
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)a2 = v7;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      return a2;
    }
    v10 = a3;
    if ( v8 )
      (*(void (**)(void))(*(_DWORD *)v8 + 20))();
    *(_DWORD *)v5 = v10;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v11 = *(_DWORD *)this;
    if ( *(_DWORD *)v5 )
    {
      *(_DWORD *)v5 = 0;
      (*(void (**)(void))(*(_DWORD *)v11 + 20))();
      *((_DWORD *)v5 + 1) = 0;
    }
    v7 = -2147467262;
  }
  *(_DWORD *)a2 = v7;
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  return a2;
}

//----- (004C1260) --------------------------------------------------------  // acclient.c:243663
char __stdcall gmVendorUI::RemoveProfileFromList(PackableList<ItemProfile> *_list, unsigned int _id, int _amount)
{
  int v4; // esi@1
  char result; // al@5
  ItemProfile curProfile; // [sp+Ch] [bp-10h]@1

  ItemProfile::ItemProfile(&curProfile);
  v4 = (int)_list->head;
  if ( v4 )
  {
    while ( 1 )
    {
      ItemProfile::operator=((int)&curProfile, v4);
      if ( curProfile.iid == _id )
        break;
      if ( v4 )
      {
        v4 = *(_DWORD *)(v4 + 16);
        if ( v4 )
          continue;
      }
      goto LABEL_5;
    }
    if ( _amount == -1 || _amount >= curProfile.amount )
    {
      PackableList<ItemProfile>::Remove(_list, &curProfile);
      ItemProfile::~ItemProfile(&curProfile);
      result = 1;
    }
    else
    {
      curProfile.amount -= _amount;
      ItemProfile::operator=(v4, (int)&curProfile);
      ItemProfile::~ItemProfile(&curProfile);
      result = 1;
    }
  }
  else
  {
LABEL_5:
    ItemProfile::~ItemProfile(&curProfile);
    result = 0;
  }
  return result;
}

//----- (004C1310) --------------------------------------------------------  // acclient.c:243710
bool __stdcall gmVendorUI::RecordContents(UIElement_ItemList *_uiItemList, PackableList<ItemProfile> *_list, int _combineDuplicates, const int _setAmountAsStackSize)
{
  PackableList<ItemProfile> *v5; // ebx@1
  UIElement_ListBox *v6; // ecx@1
  unsigned int v7; // eax@1
  UIElement *v8; // eax@2
  int v9; // eax@3
  unsigned int v10; // eax@4
  signed int v11; // ebp@5
  unsigned int v12; // eax@6
  int v13; // edi@10
  int v14; // esi@10
  int v15; // ecx@12
  int v16; // eax@13
  ItemProfile *v17; // eax@23
  ItemProfile *v18; // esi@23
  PackableLLNode<ItemProfile> *v19; // eax@28
  int v20; // eax@29
  bool duplicateFound; // [sp+7h] [bp-19h]@1
  unsigned int curID; // [sp+8h] [bp-18h]@4
  int i; // [sp+Ch] [bp-14h]@1
  ItemProfile profile; // [sp+10h] [bp-10h]@1
  char _lista; // [sp+28h] [bp+8h]@1

  v5 = _list;
  PackableList<ItemProfile>::Flush(_list);
  ItemProfile::ItemProfile(&profile);
  v6 = (UIElement_ListBox *)_uiItemList;
  v7 = 0;
  _lista = 0;
  duplicateFound = 0;
  for ( i = 0; i < (signed int)_uiItemList->m_listItems.m_num; v7 = i++ + 1 )
  {
    v8 = UIElement_ListBox::GetItem(v6, v7);
    if ( v8 )
    {
      v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 1532);
        curID = v10;
        if ( v10 )
        {
          v11 = 1;
          if ( _setAmountAsStackSize )
          {
            v12 = ClientObjMaintSystem::GetWeenieObject(v10)[20].id;
            if ( v12 )
            {
              if ( v12 > 1 )
                v11 = v12;
            }
          }
          if ( _combineDuplicates )
          {
            v13 = (int)v5->head;
            v14 = 0;
            _lista = 0;
            if ( !v13 )
              goto LABEL_23;
            do
            {
              ItemProfile::operator=((int)&profile, v13);
              if ( profile.iid == curID )
              {
                profile.amount += v11;
                v15 = (int)v5->head;
                _lista = 1;
                if ( v14 > 0 )
                {
                  v16 = v14;
                  do
                  {
                    if ( v15 )
                      v15 = *(_DWORD *)(v15 + 16);
                    --v16;
                  }
                  while ( v16 );
                }
                if ( v15 )
                  ItemProfile::operator=(v15, (int)&profile);
              }
              ++v14;
              if ( !v13 )
                break;
              v13 = *(_DWORD *)(v13 + 16);
            }
            while ( v13 );
          }
          if ( !_lista )
          {
LABEL_23:
            profile.iid = curID;
            profile.amount = v11;
            profile.pwd = 0;
            v17 = (ItemProfile *)operator new(0x18u);
            v18 = v17;
            if ( v17 )
            {
              ItemProfile::ItemProfile(v17, &profile);
              v18[1].vfptr = 0;
              v18[1].amount = 0;
            }
            else
            {
              v18 = 0;
            }
            if ( v5->head )
            {
              v19 = v5->tail;
              v19->next = (PackableLLNode<ItemProfile> *)v18;
              v18[1].amount = (int)v19;
            }
            else
            {
              v5->head = (PackableLLNode<ItemProfile> *)v18;
            }
            v20 = v5->curNum + 1;
            v5->tail = (PackableLLNode<ItemProfile> *)v18;
            v5->curNum = v20;
            goto LABEL_30;
          }
          duplicateFound = 1;
        }
      }
    }
LABEL_30:
    v6 = (UIElement_ListBox *)_uiItemList;
  }
  ItemProfile::~ItemProfile(&profile);
  return duplicateFound;
}

//----- (004C14B0) --------------------------------------------------------  // acclient.c:243844
int __thiscall gmVendorUI::AddItem(gmVendorUI *this, UIElement_ItemList *_uiItemList, unsigned int _itemID, int _position, int _removeDuplicates, int _addContents, int _excludeIfUnacceptable, int _broadcast, int _quantityDisp)
{
  int v9; // eax@1
  int v10; // eax@3
  int v11; // ebp@4
  HashBaseData<unsigned long> *v12; // ebx@8
  PStringBase<unsigned short> *v13; // eax@19
  char *v14; // esi@19
  IDList *v15; // eax@22
  IDList *v16; // esi@22
  int i; // ebx@23
  unsigned int v18; // eax@24
  int v19; // eax@24
  char *v20; // esi@27
  int placedPosition; // [sp+8h] [bp-A0h]@1
  gmVendorUI *v22; // [sp+Ch] [bp-9Ch]@1
  PStringBase<unsigned short> errorText; // [sp+10h] [bp-98h]@19
  PStringBase<unsigned short> result; // [sp+14h] [bp-94h]@19
  StringInfo siError; // [sp+18h] [bp-90h]@22

  v9 = -1;
  v22 = this;
  placedPosition = -1;
  if ( _uiItemList )
  {
    if ( _removeDuplicates && (v10 = UIElement_ItemList::ItemList_GetItem(_uiItemList, _itemID)) != 0 )
    {
      v11 = _position;
      if ( (signed int)UIElement_ListBox::WhatNum((UIElement_ListBox *)&_uiItemList->vfptr, (UIElement *)v10) < _position )
        v11 = _position - 1;
      gmVendorUI::DeleteItem(_uiItemList, _itemID, 1);
    }
    else
    {
      v11 = _position;
    }
    v12 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( !_excludeIfUnacceptable
      || VendorProfile::IsAcceptable(v22->shopVendorProfile, (PublicWeenieDesc *)&v12[12].id)
      || ((int (__thiscall *)(HashBaseData<unsigned long> *))v12->vfptr[4].__vecDelDtor)(v12) )
    {
      if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v12)
        && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v12) )
      {
        if ( _uiItemList->m_desc.m_elementID == 268435662 )
          ACCWeenieObject::SetSellState((ACCWeenieObject *)v12, 1);
        UIElement_ItemList::ItemList_InsertItem(_uiItemList, _itemID, v11);
        placedPosition = v11;
      }
      if ( _addContents && ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v12) > 0 )
      {
        v13 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v12, &result, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &errorText,
          0,
          L"Selling contents of %s",
          v13->m_charbuffer);
        v14 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v14 )
          (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        v15 = ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v12);
        v16 = v15;
        if ( v15 )
        {
          IDList::SetCurToNum(v15, 0);
          for ( i = 0; i < v16->numIDs; ++i )
          {
            v18 = IDList::GetCurID(v16);
            v19 = gmVendorUI::AddItem(v22, _uiItemList, v18, v11, _removeDuplicates, 0, 1, 1, -1);
            if ( v19 != -1 )
              v11 = v19 + 1;
            IDList::SetCurToNext(v16);
          }
        }
        StringInfo::~StringInfo(&siError);
        v20 = (char *)&errorText.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
        {
          if ( v20 )
            (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
        }
      }
      v9 = placedPosition;
    }
    else
    {
      v9 = -1;
    }
  }
  return v9;
}

//----- (004C16D0) --------------------------------------------------------  // acclient.c:243940
void __thiscall VendorItemsUI::OpenVendor(VendorItemsUI *this, bool _updating)
{
  VendorItemsUI *v2; // esi@1
  gmVendorUI *v3; // edx@1
  char *v4; // edi@2
  char *v5; // edi@7
  char *v6; // edi@12
  char *v7; // edi@17
  char *v8; // edi@22
  char *v9; // edi@27
  char *v10; // edi@32
  char *v11; // edi@37
  char *v12; // edi@42
  char *v13; // edi@47
  char *v14; // edi@52
  char *v15; // edi@57
  char *v16; // edi@62
  char *v17; // edi@67
  char *v18; // edi@72
  char *v19; // edi@77
  char *v20; // edi@82
  char *v21; // edi@87
  UIElement_Menu *v22; // ecx@91
  PSRefBufferCharData<unsigned short> *v23; // eax@91
  bool v24; // sf@91
  unsigned __int8 v25; // of@91
  int *v26; // eax@91
  UIElement *v27; // eax@95
  PStringBase<unsigned short> _value; // [sp+48h] [bp-A0h]@2
  int itemTypeSelected; // [sp+4Ch] [bp-9Ch]@1
  int v30; // [sp+50h] [bp-98h]@91
  int iScrollableX; // [sp+54h] [bp-94h]@1
  StringInfo siEntry; // [sp+58h] [bp-90h]@1

  v2 = this;
  iScrollableX = this->m_shopList->m_iScrollableX;
  itemTypeSelected = UIElement_Menu::GetSelectedIndex(this->m_itemTypeMenu);
  StringInfo::StringInfo(&siEntry);
  UIElement_ItemList::ItemList_Flush(v2->m_shopList);
  UIElement_Menu::Flush(v2->m_itemTypeMenu);
  v3 = v2->m_parent;
  v2->m_numTypeFilters = 0;
  if ( VendorItemsUI::ListContainsType(v3->shopItemProfileList, 2) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Armor");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v4 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 2u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x2000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Books, Paper");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x2000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 4) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Clothing");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v6 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 4u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 512) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Containers");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v7 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x200u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 32) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Food");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v8 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x20u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 2048) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Gems");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v9 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x800u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 8) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Jewelry");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v10 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 8u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 536887296) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Keys, Tools");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v11 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x20004000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 1168) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Miscellaneous");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v12 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x490u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x100000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Services");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v13 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x100000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 4096) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Spell Components");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v14 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x1000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x40000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Trade Notes");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v15 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x40000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 257) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Weapons");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v16 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x101u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x80000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Mana Stones");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v17 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v17 )
      (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x80000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x8000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Magic Items");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v18 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x8000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 75497472) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Alchemical Items");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v19 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v19 )
      (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x4800000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 0x400000) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Cooking Items");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v20 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v20 )
      (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x400000u);
  }
  if ( VendorItemsUI::ListContainsType(v2->m_parent->shopItemProfileList, 150994944) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Fletching Items");
    StringInfo::SetLiteralValue(&siEntry, &_value, 1);
    v21 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v21 )
      (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
    VendorItemsUI::AddTypeFilter(v2, &siEntry, 0x9000000u);
  }
  v22 = v2->m_itemTypeMenu;
  v30 = 0;
  v23 = (PSRefBufferCharData<unsigned short> *)(UIElement_Menu::GetNumItems(v22) - 1);
  _value.m_charbuffer = v23;
  v25 = __OFSUB__(itemTypeSelected, v23);
  v24 = itemTypeSelected - (signed int)v23 < 0;
  v26 = &itemTypeSelected;
  if ( !(v24 ^ v25) )
    v26 = (int *)&_value;
  if ( *v26 < 0 )
    v26 = &v30;
  v27 = UIElement_Menu::GetItem(v2->m_itemTypeMenu, *v26);
  UIElement_Menu::SetSelectedItem(v2->m_itemTypeMenu, v27, 1);
  UIElement_ListBox::ScrollToX((UIElement_ListBox *)&v2->m_shopList->vfptr, iScrollableX);
  StringInfo::~StringInfo(&siEntry);
}

//----- (004C1EA0) --------------------------------------------------------  // acclient.c:244162
void __thiscall VendorItemsUI::UpdateItemsList(VendorItemsUI *this, int item_type, bool _selectFirst)
{
  VendorItemsUI *v3; // ebx@1
  UIElement_ItemList *v4; // ecx@1
  UIElement *v5; // eax@3
  IInputActionCallbackVtbl *v6; // edx@4
  int v7; // ebp@8
  HashBaseData<unsigned long> *v8; // eax@11
  HashBaseData<unsigned long> *v9; // edi@11
  int v10; // eax@12
  unsigned int v11; // ecx@13
  int v12; // esi@15
  int v13; // eax@18
  unsigned int v14; // eax@24
  UIElement_ItemList *v15; // esi@31
  unsigned int v16; // ebp@31
  HashBaseData<unsigned long> *v17; // edi@32
  UIElement_ItemList *v18; // ecx@43
  int types; // [sp+8h] [bp-30h]@2
  unsigned int firstItemID; // [sp+Ch] [bp-2Ch]@1
  BaseProperty filterProp; // [sp+10h] [bp-28h]@4
  ItemProfile profile; // [sp+18h] [bp-20h]@8
  ItemProfile buyProfile; // [sp+28h] [bp-10h]@8

  v3 = this;
  v4 = this->m_shopList;
  firstItemID = 0;
  UIElement_ItemList::ItemList_Flush(v4);
  if ( v3->m_parent->shopVendorID )
  {
    types = 0;
    if ( item_type )
    {
      types = item_type;
    }
    else
    {
      v5 = UIElement_Menu::GetSelectedItem(v3->m_itemTypeMenu);
      if ( v5 )
      {
        v6 = v5->vfptr;
        filterProp.m_pcPropertyDesc = 0;
        filterProp.m_pcPropertyValue = 0;
        ((void (__thiscall *)(UIElement *, signed int, BaseProperty *))v6[17].OnAction)(v5, 268435513, &filterProp);
        if ( filterProp.m_pcPropertyValue )
          ((void (__stdcall *)(_DWORD))filterProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&types);
        BaseProperty::~BaseProperty(&filterProp);
      }
    }
    ItemProfile::ItemProfile(&profile);
    ItemProfile::ItemProfile(&buyProfile);
    filterProp.m_pcPropertyValue = (BasePropertyValue *)v3->m_parent->shopItemProfileList->head;
    v7 = (int)filterProp.m_pcPropertyValue;
    if ( filterProp.m_pcPropertyValue )
    {
      while ( 1 )
      {
        ItemProfile::operator=((int)&profile, v7);
        v8 = ClientObjMaintSystem::GetWeenieObject(profile.iid);
        v9 = v8;
        if ( !v8 )
          goto LABEL_38;
        v10 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v8->vfptr[6].__vecDelDtor)(v8);
        if ( !(v10 & types) )
          goto LABEL_38;
        v11 = profile.iid;
        if ( !firstItemID )
          firstItemID = profile.iid;
        v12 = profile.amount;
        if ( profile.amount == -1 )
          break;
        v13 = (int)v3->m_parent->m_buyList.head;
        if ( !v13 )
          goto LABEL_24;
        while ( *(_DWORD *)(v13 + 8) != profile.iid )
        {
          v13 = *(_DWORD *)(v13 + 16);
          if ( !v13 )
            goto LABEL_24;
        }
        ItemProfile::operator=((int)&buyProfile, v13);
        v12 -= buyProfile.amount;
        if ( v12 > 0 )
        {
          v11 = profile.iid;
LABEL_24:
          v14 = (unsigned int)v9[21].vfptr;
          if ( v14 > 1 )
          {
            if ( v12 > (signed int)v14 )
              v12 = (int)v9[21].vfptr;
            VendorSubUI::SetObjectStackSize((ACCWeenieObject *)v9, v12);
LABEL_28:
            v11 = profile.iid;
          }
LABEL_29:
          if ( ACCWeenieObject::selectedID == v11 )
          {
            GenItemHolder::ItemAttributesChanged_s(v11, 0);
            v11 = profile.iid;
          }
          v15 = v3->m_shopList;
          v16 = v11;
          if ( v15 )
          {
            v17 = ClientObjMaintSystem::GetWeenieObject(v11);
            if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v17)
              && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v17) )
            {
              if ( v15->m_desc.m_elementID == 268435662 )
                ACCWeenieObject::SetSellState((ACCWeenieObject *)v17, 1);
              UIElement_ItemList::ItemList_InsertItem(v15, v16, -1);
            }
          }
          v7 = (int)filterProp.m_pcPropertyValue;
        }
LABEL_38:
        if ( !v7 )
          goto LABEL_40;
        filterProp.m_pcPropertyValue = *(BasePropertyValue **)(v7 + 16);
        if ( !filterProp.m_pcPropertyValue )
          goto LABEL_40;
        v7 = (int)filterProp.m_pcPropertyValue;
      }
      if ( v9[21].vfptr > (HashBaseData<unsigned long>Vtbl *)1 )
      {
        VendorSubUI::SetObjectStackSize((ACCWeenieObject *)v9, (int)v9[21].vfptr);
        goto LABEL_28;
      }
      goto LABEL_29;
    }
LABEL_40:
    ItemProfile::~ItemProfile(&buyProfile);
    ItemProfile::~ItemProfile(&profile);
  }
  if ( _selectFirst )
    ACCWeenieObject::SetSelectedObject(firstItemID, 0);
  v18 = v3->m_shopList;
  if ( v18->m_listItems.m_num )
    UIElement_ListBox::ScrollToShow((UIElement_ListBox *)&v18->vfptr, 0);
}

//----- (004C20C0) --------------------------------------------------------  // acclient.c:244305
char __thiscall VendorSellUI::DragItemAcceptable(VendorSellUI *this, unsigned int _itemID, bool _silent)
{
  VendorSellUI *v3; // edi@1
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  char *v6; // esi@4
  int v8; // eax@10
  PStringBase<unsigned short> *v9; // ecx@14
  PStringBase<unsigned short> _value; // [sp+8h] [bp-A4h]@4
  PStringBase<unsigned short> v11; // [sp+Ch] [bp-A0h]@15
  PStringBase<unsigned short> v12; // [sp+10h] [bp-9Ch]@16
  PStringBase<unsigned short> v13; // [sp+14h] [bp-98h]@17
  PStringBase<unsigned short> v14; // [sp+18h] [bp-94h]@14
  StringInfo siError; // [sp+1Ch] [bp-90h]@4

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v5 = v4;
  if ( !v4 )
    return 0;
  if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v5) > 0 )
      return 1;
    v8 = VendorProfile::InqAcceptability(v3->m_parent->shopVendorProfile, (PublicWeenieDesc *)&v5[12].id);
    if ( !v8 )
      return 1;
    if ( !_silent )
    {
      switch ( v8 )
      {
        case 1:
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"That item cannot be sold here");
          StringInfo::SetLiteralValue(&siError, &_value, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          break;
        case 2:
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v14, L"That item has no value and cannot be sold");
          StringInfo::SetLiteralValue(&siError, &v14, 1);
          v9 = &v14;
          goto LABEL_18;
        case 3:
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v11, L"That item is too cheap to sell here");
          StringInfo::SetLiteralValue(&siError, &v11, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v11);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          break;
        case 4:
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v12, L"That item is too valuable to sell here");
          StringInfo::SetLiteralValue(&siError, &v12, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v12);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          break;
        default:
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v13, L"You cannot sell that here");
          StringInfo::SetLiteralValue(&siError, &v13, 1);
          v9 = &v13;
LABEL_18:
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v9);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          break;
      }
      StringInfo::~StringInfo(&siError);
    }
    return 0;
  }
  if ( !_silent )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can only sell items you are carrying");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v6 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
  }
  return 0;
}

//----- (004C2300) --------------------------------------------------------  // acclient.c:244395
char __thiscall VendorSellUI::OnItemListDragOver(VendorSellUI *this, UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && !(_dropFlags & 0xE) )
  {
    if ( VendorSellUI::DragItemAcceptable((VendorSellUI *)((char *)this - 8), _dropItemID, 1) )
    {
      UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
      return 1;
    }
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000041u);
  }
  return 1;
}

//----- (004C2340) --------------------------------------------------------  // acclient.c:244410
PackableList<ItemProfile> *__thiscall PackableList<ItemProfile>::operator=(PackableList<ItemProfile> *this, int a2)
{
  PackableList<ItemProfile> *v2; // edi@1
  int i; // ebx@1
  ItemProfile *v4; // eax@2
  ItemProfile *v5; // esi@2
  int v6; // eax@7
  int v7; // ecx@8

  v2 = this;
  PackableList<ItemProfile>::Flush(this);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 16) )
  {
    v4 = (ItemProfile *)operator new(0x18u);
    v5 = v4;
    if ( v4 )
    {
      ItemProfile::ItemProfile(v4, (ItemProfile *)i);
      v5[1].vfptr = 0;
      v5[1].amount = 0;
    }
    else
    {
      v5 = 0;
    }
    if ( v2->head )
    {
      v6 = (int)v2->tail;
      *(_DWORD *)(v6 + 16) = v5;
      v5[1].amount = v6;
    }
    else
    {
      v2->head = (PackableLLNode<ItemProfile> *)v5;
    }
    v7 = v2->curNum + 1;
    v2->tail = (PackableLLNode<ItemProfile> *)v5;
    v2->curNum = v7;
    if ( !i )
      break;
  }
  return v2;
}

//----- (004C23B0) --------------------------------------------------------  // acclient.c:244455
PackableList<ItemProfile> *__thiscall PackableList<ItemProfile>::scalar_deleting_destructor(PackableList<ItemProfile> *this, unsigned int a2)
{
  PackableList<ItemProfile> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);

//----- (004C23E0) --------------------------------------------------------  // acclient.c:244471
void __thiscall InterfacePtr<ClientObjMaintSystem>::InterfacePtr<ClientObjMaintSystem>(InterfacePtr<ClientObjMaintSystem> *this, InterfacePtr<Interface> *_ptr)
{
  InterfacePtr<Interface> *v2; // edx@1
  InterfacePtr<ClientObjMaintSystem> *v3; // esi@1
  int v4; // [sp-8h] [bp-Ch]@1

  v2 = _ptr;
  v3 = this;
  this->m_pInterface = 0;
  this->m_trStatus.m_val = 0;
  v4 = (int)v2->m_pInterface;
  if ( v2->m_pInterface )
    v2->m_pInterface->vfptr->AddRef(v2->m_pInterface);
  v3->m_trStatus.m_val = *(_DWORD *)InterfacePtr<ClientObjMaintSystem>::_QueryInterface(v3, (int)&_ptr, v4, 0);
}

//----- (004C2420) --------------------------------------------------------  // acclient.c:244488
void __thiscall ClientSystem::AddTextToScroll(ClientSystem *this, PStringBase<char> *i_text, unsigned int i_ltt, bool i_sendToAPI, unsigned int i_nOverrideDestination)
{
  unsigned int v5; // ST10_4@1
  ClientSystem *v6; // esi@1
  PStringBase<unsigned short> *v7; // eax@1
  unsigned int v8; // esi@1

  v5 = i_nOverrideDestination;
  v6 = this;
  v7 = PStringBase<char>::to_wpstring(i_text, (PStringBase<unsigned short> *)&i_nOverrideDestination, 0);
  ClientSystem::AddTextToScroll(v6, v7, i_ltt, i_sendToAPI, v5);
  v8 = i_nOverrideDestination - 20;
  if ( !InterlockedDecrement((volatile LONG *)(i_nOverrideDestination - 20 + 4)) )
  {
    if ( v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
}

//----- (004C2470) --------------------------------------------------------  // acclient.c:244508
void __userpurge gmVendorUI::gmVendorUI(gmVendorUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVendorUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v4->m_vendorPanel = 0;
  v4->shopVendorID = 0;
  v4->shopVendorProfile = 0;
  v4->shopItemProfileList = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmVendorUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmVendorUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmVendorUI::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&gmVendorUI::vftable;
  v4->m_buyList.head = 0;
  v4->m_buyList.tail = 0;
  v4->m_buyList.curNum = 0;
  v4->m_buyList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  v4->m_sellList.head = 0;
  v4->m_sellList.tail = 0;
  v4->m_sellList.curNum = 0;
  v4->m_sellList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  v4->m_itemsUI = 0;
  v4->m_buyUI = 0;
  v4->m_sellUI = 0;
  v4->m_totalValue = 0;
  v4->m_last_sale = 0;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);
// 7B535C: using guessed type void (__thiscall *gmVendorUI::vftable)(gmVendorUI *this, unsigned __int32);
// 7B5364: using guessed type void (__thiscall *gmVendorUI::vftable[2])(gmVendorUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B5370: using guessed type bool (__thiscall *gmVendorUI::vftable)(DBCache *this);
// 7B5618: using guessed type int (__thiscall *gmVendorUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C2540) --------------------------------------------------------  // acclient.c:244549
gmVendorUI *__thiscall gmVendorUI::DynamicCast(gmVendorUI *this, unsigned int i_eType)
{
  gmVendorUI *result; // eax@1

  result = this;
  if ( i_eType != 268435479 )
    result = (gmVendorUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004C2560) --------------------------------------------------------  // acclient.c:244560
signed int gmVendorUI::GetUIElementType()
{
  return 268435479;
}

//----- (004C2570) --------------------------------------------------------  // acclient.c:244566
void __thiscall gmVendorUI::~gmVendorUI(gmVendorUI *this)
{
  gmVendorUI *v1; // esi@1
  VendorItemsUI *v2; // eax@1
  NoticeHandler *v3; // ebx@1
  char *v4; // ebp@1
  void *v5; // eax@3
  VendorSellUI *v6; // edi@5
  UIElement_ItemList *v7; // ecx@6
  CPlayerSystem *v8; // eax@9
  GlobalEventHandler *v9; // eax@9

  v1 = this;
  v2 = this->m_itemsUI;
  v3 = (NoticeHandler *)&this->vfptr;
  v4 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmVendorUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmVendorUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmVendorUI::vftable;
  this->vfptr = (ObjectRangeHandlerVtbl *)&gmVendorUI::vftable;
  if ( v2 )
  {
    v2->vfptr = (VendorSubUIVtbl *)&VendorSubUI::vftable;
    operator delete(v2);
  }
  v5 = v1->m_buyUI;
  v1->m_itemsUI = 0;
  if ( v5 )
  {
    *(_DWORD *)v5 = &VendorSubUI::vftable;
    operator delete(v5);
  }
  v1->m_buyUI = 0;
  v6 = v1->m_sellUI;
  if ( v6 )
  {
    v7 = v6->m_sellShopList;
    v6->vfptr = (VendorSubUIVtbl *)&VendorSellUI::vftable;
    v6->vfptr = (ItemListDragHandlerVtbl *)&VendorSellUI::vftable;
    if ( v7 )
      UIElement_ItemList::UnregisterItemListDragHandler(v7);
    v6->vfptr = (VendorSubUIVtbl *)&VendorSubUI::vftable;
    operator delete(v6);
  }
  v1->m_sellUI = 0;
  v8 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UnregisterAllObjectRangeHandlers(v8, (ObjectRangeHandler *)&v1->vfptr);
  (*(void (__stdcall **)(char *))&QualityRegistrar::s_pQR->vfptr->gap14[0])(v4);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  v9 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v9 )
    v9->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v9, v3);
  v1->m_sellList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(&v1->m_sellList);
  v1->m_sellList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_buyList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(&v1->m_buyList);
  v1->m_buyList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B4F8C: using guessed type void (__thiscall *VendorSubUI::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7B4F98: using guessed type bool (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B4F9C: using guessed type void (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, bool _updating);
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);
// 7B535C: using guessed type void (__thiscall *gmVendorUI::vftable)(gmVendorUI *this, unsigned __int32);
// 7B5364: using guessed type void (__thiscall *gmVendorUI::vftable[2])(gmVendorUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B5370: using guessed type bool (__thiscall *gmVendorUI::vftable)(DBCache *this);
// 7B5618: using guessed type int (__thiscall *gmVendorUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C26A0) --------------------------------------------------------  // acclient.c:244640
void __usercall gmVendorUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVendorUI *v3; // eax@1

  v3 = (gmVendorUI *)operator new(0x648u);
  if ( v3 )
    gmVendorUI::gmVendorUI(v3, a1, _layout, _full_desc);
}

//----- (004C26D0) --------------------------------------------------------  // acclient.c:244650
void __thiscall gmVendorUI::ResetShopState(gmVendorUI *this, bool _updating)
{
  gmVendorUI *v2; // edi@1
  InterfaceSystem *v3; // eax@3
  int v4; // esi@3
  PackableLLNode<ItemProfile> *i; // esi@7
  HashBaseData<unsigned long> *v6; // eax@8
  PackableLLNode<ItemProfile> *v7; // esi@11
  ClientObjMaintSystem *j; // ebp@11
  HashBaseData<unsigned long> *v9; // eax@12
  VendorProfile *v10; // ecx@18
  PackableList<ItemProfile> *v11; // ecx@20
  int v12; // [sp-8h] [bp-28h]@3
  TResult result; // [sp+10h] [bp-10h]@3
  char v14; // [sp+14h] [bp-Ch]@5
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+18h] [bp-8h]@3

  v2 = this;
  if ( this->shopVendorID )
  {
    if ( !_updating )
    {
      *(_DWORD *)&_updating = 0;
      v3 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v3, &result, &ClientObjMaintSystem_ClassType, (Interface **)&_updating);
      v12 = _updating;
      v4 = _updating;
      spObjMaint.m_pInterface = 0;
      spObjMaint.m_trStatus.m_val = 0;
      if ( _updating )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)_updating + 16))(_updating);
      InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v14, v12, 0);
      if ( v4 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      for ( i = v2->m_sellList.head; i; i = i->next )
      {
        v6 = ClientObjMaintSystem::GetWeenieObject(i->data.iid);
        if ( v6 )
          ACCWeenieObject::SetSellState((ACCWeenieObject *)v6, 0);
      }
      v7 = v2->shopItemProfileList->head;
      for ( j = spObjMaint.m_pInterface; v7; v7 = v7->next )
      {
        v9 = ClientObjMaintSystem::GetWeenieObject(v7->data.iid);
        if ( v9 && v9[15].vfptr == (HashBaseData<unsigned long>Vtbl *)v2->shopVendorID )
          ((void (__thiscall *)(int, unsigned int))j->vfptr[1].IUnknown_AddRef)(&j->vfptr, v7->data.iid);
      }
      PackableList<ItemProfile>::Flush(&v2->m_sellList);
      PackableList<ItemProfile>::Flush(&v2->m_buyList);
      if ( j )
        j->vfptr->Release((Interface *)j);
    }
    v10 = v2->shopVendorProfile;
    v2->shopVendorID = 0;
    if ( v10 )
      ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
    v11 = v2->shopItemProfileList;
    v2->shopVendorProfile = 0;
    if ( v11 )
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
    v2->shopItemProfileList = 0;
  }
}

//----- (004C2820) --------------------------------------------------------  // acclient.c:244715
char __thiscall gmVendorUI::BuySingleItem(gmVendorUI *this, unsigned int _ID)
{
  gmVendorUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // esi@1
  unsigned int v6; // eax@3
  int v7; // eax@7
  VendorProfile *v8; // ecx@7
  int v9; // ebp@7
  int v10; // esi@9
  int v11; // esi@15
  unsigned int v12; // eax@20
  HashBaseData<unsigned long> *v13; // ebx@22
  HashBaseData<unsigned long>Vtbl *v14; // ebp@25
  unsigned int v15; // esi@30
  int v16; // esi@31
  IDClass<_tagDataID,32,0> *v17; // eax@37
  unsigned int v18; // esi@37
  ClientUISystem *v19; // eax@37
  int amountBuyingNow; // [sp+8h] [bp-BCh]@5
  int transactionValue; // [sp+Ch] [bp-B8h]@7
  IDClass<_tagDataID,32,0> trade_id; // [sp+10h] [bp-B4h]@7
  PackableList<ItemProfile> singleItemList; // [sp+14h] [bp-B0h]@35
  ItemProfile buyItem; // [sp+24h] [bp-A0h]@35
  StringInfo siError; // [sp+34h] [bp-90h]@9

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(_ID);
  v4 = v3;
  if ( !v3 )
    return 0;
  v6 = v3[20].id;
  if ( v6 && v6 > 1 )
    amountBuyingNow = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v4);
  else
    amountBuyingNow = 1;
  v7 = VendorProfile::VendorSellPrice(v2->shopVendorProfile, (PublicWeenieDesc *)&v4[12].id, amountBuyingNow);
  v8 = v2->shopVendorProfile;
  v9 = v7;
  transactionValue = v7;
  VendorProfile::VendorTradeCurrency(v8, &trade_id);
  if ( trade_id.id == stru_83F540.id )
  {
    if ( v9 > v2->m_totalValue )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&amountBuyingNow,
        L"You don't have enough money");
      StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&amountBuyingNow, 1);
      v10 = amountBuyingNow - 20;
      if ( !InterlockedDecrement((volatile LONG *)(amountBuyingNow - 20 + 4)) )
      {
        if ( v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_13:
      StringInfo::~StringInfo(&siError);
      return 0;
    }
  }
  else if ( v9 > v2->shopVendorProfile->trade_num - v2->m_last_sale )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&amountBuyingNow,
      L"You don't have enough money");
    StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&amountBuyingNow, 1);
    v11 = amountBuyingNow - 20;
    if ( !InterlockedDecrement((volatile LONG *)(amountBuyingNow - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  if ( SmartBox::smartbox )
    v12 = SmartBox::smartbox->player_id;
  else
    v12 = 0;
  v13 = ClientObjMaintSystem::GetWeenieObject(v12);
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v4[21].hash_next
    || v4[16].id
    || v4[17].vfptr )
  {
    v14 = v13[17].vfptr;
    if ( (HashBaseData<unsigned long>Vtbl *)ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v13) == v14 )
    {
LABEL_31:
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&amountBuyingNow,
        L"You must empty some slots in your backpack first");
      StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&amountBuyingNow, 1);
      v16 = amountBuyingNow - 20;
      if ( !InterlockedDecrement((volatile LONG *)(amountBuyingNow - 20 + 4)) && v16 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_13;
    }
    v9 = transactionValue;
  }
  if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v4[21].hash_next)
    && !v4[16].id
    && !v4[17].vfptr )
  {
    v15 = v13[16].id;
    if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v13) == v15 )
      goto LABEL_31;
  }
  ItemProfile::ItemProfile(&buyItem);
  buyItem.amount = amountBuyingNow;
  buyItem.iid = _ID;
  singleItemList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  singleItemList.head = 0;
  singleItemList.tail = 0;
  singleItemList.curNum = 0;
  PackableList<ItemProfile>::InsertHead(&singleItemList, &buyItem);
  if ( trade_id.id != stru_83F540.id )
    v2->m_last_sale = v9;
  v17 = VendorProfile::VendorTradeCurrency(v2->shopVendorProfile, (IDClass<_tagDataID,32,0> *)&transactionValue);
  v18 = v2->shopVendorID;
  CM_Vendor::Event_Buy(v2->shopVendorID, &singleItemList, (IDClass<_tagDataID,32,0>)v17->id);
  ACCWeenieObject::RecordRequest(v18, IR_SHOP_EVENT);
  v19 = ClientUISystem::GetUISystem();
  ClientUISystem::IncrementBusyCount(v19);
  singleItemList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(&singleItemList);
  singleItemList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  ItemProfile::~ItemProfile(&buyItem);
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);

//----- (004C2B40) --------------------------------------------------------  // acclient.c:244851
char __thiscall gmVendorUI::SellSingleItem(gmVendorUI *this, unsigned int _ID)
{
  gmVendorUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // esi@1
  char *v5; // esi@7
  unsigned int v6; // esi@10
  VendorProfile *v8; // ecx@16
  unsigned int v9; // esi@16
  ClientUISystem *v10; // eax@16
  PStringBase<unsigned short> _value; // [sp+10h] [bp-B4h]@7
  PackableList<ItemProfile> singleItemList; // [sp+14h] [bp-B0h]@16
  ItemProfile sellItem; // [sp+24h] [bp-A0h]@16
  StringInfo siError; // [sp+34h] [bp-90h]@7

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(_ID);
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( ((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v3[21].hash_next
     || v3[16].id
     || v3[17].vfptr)
    && (ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v3)
     || ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v4)) )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Cannot sell container that isn't empty");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    goto LABEL_14;
  }
  v6 = v4[20].id;
  if ( v6 && v6 > 1 && GenItemHolder::splitSize < GenItemHolder::maxSplitSize )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Cannot sell part of a stack");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
LABEL_14:
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  ItemProfile::ItemProfile(&sellItem);
  sellItem.iid = _ID;
  sellItem.amount = 1;
  singleItemList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  singleItemList.head = 0;
  singleItemList.tail = 0;
  singleItemList.curNum = 0;
  PackableList<ItemProfile>::InsertHead(&singleItemList, &sellItem);
  v8 = v2->shopVendorProfile;
  v2->m_last_sale = 0;
  VendorProfile::VendorTradeCurrency(v8, (IDClass<_tagDataID,32,0> *)&_value);
  v9 = v2->shopVendorID;
  CM_Vendor::Event_Sell(v2->shopVendorID, &singleItemList);
  ACCWeenieObject::RecordRequest(v9, IR_SHOP_EVENT);
  v10 = ClientUISystem::GetUISystem();
  ClientUISystem::IncrementBusyCount(v10);
  singleItemList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(&singleItemList);
  singleItemList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  ItemProfile::~ItemProfile(&sellItem);
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);

//----- (004C2D00) --------------------------------------------------------  // acclient.c:244926
void __stdcall gmVendorUI::AdoptAsContents(UIElement_ItemList *_uiItemList, PackableList<ItemProfile> *_itemList, const bool _setStackSizeAsAmount)
{
  HashBaseData<unsigned long> *v4; // ecx@3
  unsigned int v5; // esi@3
  int v6; // edi@4
  unsigned int v7; // eax@4
  unsigned int v8; // eax@6
  unsigned int v9; // edi@8
  HashBaseData<unsigned long> *v10; // esi@9
  int i; // ebx@14
  unsigned int v12; // edi@15
  HashBaseData<unsigned long> *v13; // esi@16
  int begin_4; // [sp+8h] [bp-14h]@1
  ItemProfile profile; // [sp+Ch] [bp-10h]@1

  UIElement_ItemList::ItemList_Flush(_uiItemList);
  ItemProfile::ItemProfile(&profile);
  for ( begin_4 = (int)_itemList->head; begin_4; begin_4 = *(_DWORD *)(begin_4 + 16) )
  {
    ItemProfile::operator=((int)&profile, begin_4);
    if ( _setStackSizeAsAmount
      && (v4 = ClientObjMaintSystem::GetWeenieObject(profile.iid),
          v5 = 1,
          v4[21].vfptr > (HashBaseData<unsigned long>Vtbl *)1) )
    {
      v6 = profile.amount;
      v7 = v4[17].id;
      if ( v4[20].id )
        v5 = v4[20].id;
      v4[20].id = profile.amount;
      v4[17].id = v6 * (v7 / v5);
      v8 = profile.iid;
      if ( ACCWeenieObject::selectedID == profile.iid )
      {
        GenItemHolder::ItemAttributesChanged_s(profile.iid, 0);
        v8 = profile.iid;
      }
      v9 = v8;
      if ( _uiItemList )
      {
        v10 = ClientObjMaintSystem::GetWeenieObject(v8);
        if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v10)
          && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v10) )
        {
          if ( _uiItemList->m_desc.m_elementID == 268435662 )
            ACCWeenieObject::SetSellState((ACCWeenieObject *)v10, 1);
          UIElement_ItemList::ItemList_InsertItem(_uiItemList, v9, -1);
        }
      }
    }
    else
    {
      for ( i = 0; i < profile.amount; ++i )
      {
        v12 = profile.iid;
        if ( _uiItemList )
        {
          v13 = ClientObjMaintSystem::GetWeenieObject(profile.iid);
          if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v13)
            && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v13) )
          {
            if ( _uiItemList->m_desc.m_elementID == 268435662 )
              ACCWeenieObject::SetSellState((ACCWeenieObject *)v13, 1);
            UIElement_ItemList::ItemList_InsertItem(_uiItemList, v12, -1);
          }
        }
      }
    }
    if ( !begin_4 )
      break;
  }
  ItemProfile::~ItemProfile(&profile);
}

//----- (004C2E90) --------------------------------------------------------  // acclient.c:245001
void __stdcall gmVendorUI::AddMissingComp(IDClass<_tagDataID,32,0> wcid, PStringBase<char> *strResult)
{
  CPlayerSystem *v3; // eax@1
  ComponentTracker *v4; // eax@1
  PStringBase<char> *v5; // ebx@1
  unsigned int v6; // eax@2
  int v7; // ecx@2
  int v8; // esi@4
  unsigned int v9; // eax@5
  int v10; // ecx@5
  unsigned int v11; // ecx@11
  int v12; // eax@11
  int v13; // esi@13
  AC1Legacy::PSRefBuffer<char> *v14; // esi@16
  int v15; // [sp-8h] [bp-14h]@4
  AC1Legacy::PStringBase<char> comp_name; // [sp+8h] [bp-4h]@1

  comp_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v3 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::GetComponentTracker(v3);
  ComponentTracker::GetCompNameFromWCID(v4, wcid, &comp_name);
  v5 = strResult;
  if ( *(_DWORD *)&strResult->m_charbuffer[-1].m_data[12] == 1 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&wcid, "There was not enough: ");
    v6 = wcid.id;
    v7 = *(_DWORD *)(wcid.id - 4);
    if ( v7 != 1 )
    {
      PStringBase<char>::append_n_chars(v5, (const char *)wcid.id, v7 - 1);
      v6 = wcid.id;
    }
    v8 = v6 - 20;
    v15 = v6 - 20 + 4;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&wcid, ", ");
    v9 = wcid.id;
    v10 = *(_DWORD *)(wcid.id - 4);
    if ( v10 != 1 )
    {
      PStringBase<char>::append_n_chars(v5, (const char *)wcid.id, v10 - 1);
      v9 = wcid.id;
    }
    v8 = v9 - 20;
    v15 = v9 - 20 + 4;
  }
  if ( !InterlockedDecrement((volatile LONG *)v15) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&wcid, comp_name.m_buffer->m_data);
  v11 = wcid.id;
  v12 = *(_DWORD *)(wcid.id - 4);
  if ( v12 != 1 )
  {
    PStringBase<char>::append_n_chars(v5, (const char *)wcid.id, v12 - 1);
    v11 = wcid.id;
  }
  v13 = v11 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v11 - 20 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = comp_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&comp_name.m_buffer->m_cRef) )
  {
    if ( v14 )
      v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C2FB0) --------------------------------------------------------  // acclient.c:245073
void __thiscall VendorSellUI::OpenVendor(VendorSellUI *this, bool _updating)
{
  VendorSellUI *v2; // esi@1

  v2 = this;
  gmVendorUI::AdoptAsContents(this->m_sellShopList, &this->m_parent->m_sellList, 0);
  VendorSellUI::UpdateSellUI(v2);
}

//----- (004C2FE0) --------------------------------------------------------  // acclient.c:245083
gmVendorUI *__thiscall gmVendorUI::scalar_deleting_destructor(gmVendorUI *this, unsigned int a2)
{
  gmVendorUI *v2; // esi@1

  v2 = this;
  gmVendorUI::~gmVendorUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004C3000) --------------------------------------------------------  // acclient.c:245095
void __cdecl gmVendorUI::Register()
{
  UIElement::RegisterElementClass(0x10000017u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmVendorUI::Create);
}

//----- (004C3020) --------------------------------------------------------  // acclient.c:245101
void __thiscall gmVendorUI::CloseVendor(gmVendorUI *this, bool _updating)
{
  gmVendorUI *v2; // esi@1
  unsigned int v3; // ST04_4@4
  CPlayerSystem *v4; // eax@4

  v2 = this;
  if ( !_updating )
  {
    ((void (*)(void))this->m_itemsUI->vfptr->CloseVendor)();
    ((void (*)(void))v2->m_sellUI->vfptr->CloseVendor)();
    ((void (*)(void))v2->m_buyUI->vfptr->CloseVendor)();
  }
  if ( v2->shopVendorID )
  {
    v3 = v2->shopVendorID;
    v4 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::UnregisterObjectRangeHandler(v4, (ObjectRangeHandler *)&v2->vfptr, v3);
  }
  gmVendorUI::ResetShopState(v2, _updating);
}

//----- (004C3080) --------------------------------------------------------  // acclient.c:245124
void __cdecl gmVendorUI::CloseVendorDialogCallback(PropertyCollection *i_rcResults)
{
  unsigned int v1; // edx@1
  HashTableData<unsigned long,BaseProperty> **v2; // eax@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  BasePropertyValue *v4; // ecx@6
  BasePropertyDesc *v5; // ecx@11
  unsigned int v6; // edx@11
  int v7; // edx@15
  bool confirm; // [sp+7h] [bp-9h]@1
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v2 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  confirm = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = v2[v1];
  if ( v3 )
  {
    while ( v3->m_hashKey != 146 )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      BaseProperty::operator=(&p, (int)&v3->m_data);
      v4 = p.m_pcPropertyValue;
      gmVendorUI::m_curDialogContext = 0;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&confirm);
        v4 = p.m_pcPropertyValue;
      }
      if ( confirm )
      {
        CM_Vendor::SendNotice_CloseVendor(0);
        v4 = p.m_pcPropertyValue;
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v5 = p.m_pcPropertyDesc;
        v6 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v6;
        if ( !v6 )
          ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
        v4 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v4 )
      {
        v7 = v4->m_cRef - 1;
        v4->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (004C3150) --------------------------------------------------------  // acclient.c:245187
void __thiscall VendorBuyUI::UpdateTransactionValue(VendorBuyUI *this)
{
  VendorBuyUI *v1; // esi@1
  UIElement_ItemList *v2; // eax@1
  AC1Legacy::PSRefBuffer<char> *v3; // ebp@1
  unsigned int v4; // ecx@1
  unsigned int v5; // edi@1
  UIElement *v6; // eax@2
  int v7; // eax@3
  unsigned int v8; // eax@4
  HashBaseData<unsigned long> *v9; // eax@5
  unsigned int v10; // ecx@6
  signed int v11; // edx@6
  unsigned int v12; // edx@8
  int v13; // edi@14
  int v14; // ebx@14
  volatile LONG *v15; // ST24_4@15
  LONG (__stdcall *v16)(volatile LONG *); // ebx@15
  int v17; // eax@20
  AC1Legacy::PSRefBuffer<char> *v18; // edi@22
  PStringBase<unsigned short> *v19; // eax@22
  int v20; // esi@22
  AC1Legacy::PSRefBuffer<char> *v21; // edi@28
  int v22; // eax@28
  AC1Legacy::PSRefBuffer<char> *v23; // ebx@30
  PStringBase<unsigned short> *v24; // eax@30
  int v25; // esi@30
  AC1Legacy::PStringBase<char> valStr; // [sp+10h] [bp-10h]@14
  AC1Legacy::PStringBase<char> purchase_string; // [sp+14h] [bp-Ch]@1
  IDClass<_tagDataID,32,0> trade_id; // [sp+18h] [bp-8h]@13
  int num; // [sp+1Ch] [bp-4h]@14

  v1 = this;
  v2 = this->m_buyShopList;
  v3 = 0;
  this->m_transactionValue = 0;
  v4 = v2->m_listItems.m_num;
  v5 = 0;
  purchase_string.m_buffer = 0;
  if ( (signed int)v4 > 0 )
  {
    do
    {
      v6 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_buyShopList->vfptr, v5);
      if ( v6 )
      {
        v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 1532);
          if ( v8 )
          {
            v9 = ClientObjMaintSystem::GetWeenieObject(v8);
            if ( v9 )
            {
              v10 = v9[20].id;
              v11 = v9[20].id;
              if ( !v10 )
                v11 = 1;
              v3 = (AC1Legacy::PSRefBuffer<char> *)((char *)v3 + v11);
              v12 = v9[20].id;
              if ( !v10 )
                v12 = 1;
              v1->m_transactionValue += VendorProfile::VendorSellPrice(
                                          v1->m_parent->shopVendorProfile,
                                          (PublicWeenieDesc *)&v9[12].id,
                                          v12);
            }
          }
        }
      }
      ++v5;
    }
    while ( (signed int)v5 < (signed int)v1->m_buyShopList->m_listItems.m_num );
    purchase_string.m_buffer = v3;
  }
  VendorProfile::VendorTradeCurrency(v1->m_parent->shopVendorProfile, &trade_id);
  if ( trade_id.id == stru_83F540.id )
  {
    v13 = AC1Legacy::PStringBase<char>::s_NullBuffer;
    v14 = AC1Legacy::PStringBase<char>::s_NullBuffer + 4;
    valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    num = v1->m_transactionValue;
    if ( v13 == AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      v16 = InterlockedDecrement;
    }
    else
    {
      v15 = (volatile LONG *)v14;
      v16 = InterlockedDecrement;
      if ( !InterlockedDecrement(v15) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    }
    AC1Legacy::PStringBase<char>::append_int32(&valStr, num);
    AC1Legacy::PStringBase<char>::InsertCommas(&valStr);
    v17 = (int)L"item";
    if ( purchase_string.m_buffer != (AC1Legacy::PSRefBuffer<char> *)1 )
      v17 = (int)L"items";
    v18 = valStr.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&num,
      0,
      L"Buying %d %s worth %hsp",
      purchase_string.m_buffer,
      v17,
      valStr.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_buyListText, v19);
    v20 = num - 20;
    if ( !v16((volatile LONG *)(num - 20 + 4)) && v20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
    if ( !v16((volatile LONG *)&v18->m_cRef) )
    {
      if ( v18 )
        v18->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v18, 1u);
    }
  }
  else
  {
    v21 = v1->m_parent->shopVendorProfile->trade_name.m_buffer;
    InterlockedIncrement((volatile LONG *)&v21->m_cRef);
    purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v22 = (int)"item";
    if ( v3 != (AC1Legacy::PSRefBuffer<char> *)1 )
      v22 = (int)"items";
    AC1Legacy::PStringBase<char>::sprintf(
      &purchase_string,
      "Buying %d %s worth %d %s.",
      v3,
      v22,
      v1->m_transactionValue,
      v21->m_data);
    v23 = purchase_string.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&num,
      0,
      L"%hs",
      purchase_string.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_buyListText, v24);
    v25 = num - 20;
    if ( !InterlockedDecrement((volatile LONG *)(num - 20 + 4)) && v25 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v23->m_cRef) && v23 )
      v23->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v23, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v21->m_cRef) && v21 )
      v21->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v21, 1u);
  }
}
// 7B58EC: using guessed type wchar_t aItems_2[6];
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C33D0) --------------------------------------------------------  // acclient.c:245343
void __thiscall VendorBuyUI::UpdateTotalValue(VendorBuyUI *this)
{
  VendorBuyUI *v1; // esi@1
  VendorProfile *v2; // ecx@1
  int v3; // edi@3
  volatile LONG *v4; // ebp@3
  AC1Legacy::PSRefBuffer<char> *v5; // edi@9
  PStringBase<unsigned short> *v6; // eax@9
  unsigned int v7; // esi@9
  AC1Legacy::PSRefBuffer<char> *v8; // edi@12
  AC1Legacy::PSRefBuffer<char> *v9; // ebx@12
  PStringBase<unsigned short> *v10; // eax@12
  unsigned int v11; // esi@12
  AC1Legacy::PStringBase<char> valStr; // [sp+10h] [bp-Ch]@3
  AC1Legacy::PStringBase<char> purchase_string; // [sp+14h] [bp-8h]@1
  IDClass<_tagDataID,32,0> result; // [sp+18h] [bp-4h]@2

  v1 = this;
  purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)stru_83F540.id;
  v2 = this->m_parent->shopVendorProfile;
  if ( v2 )
    purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)VendorProfile::VendorTradeCurrency(v2, &result)->id;
  v3 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  result.id = v1->m_parent->m_totalValue;
  if ( v3 != AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement(v4) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  }
  AC1Legacy::PStringBase<char>::append_int32(&valStr, result.id);
  AC1Legacy::PStringBase<char>::InsertCommas(&valStr);
  if ( purchase_string.m_buffer == (AC1Legacy::PSRefBuffer<char> *)stru_83F540.id )
  {
    v5 = valStr.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&result,
      0,
      L"You have %hsp",
      valStr.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_buyPurseText, v6);
    v7 = result.id - 20;
    if ( !InterlockedDecrement((volatile LONG *)(result.id - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  else
  {
    v8 = v1->m_parent->shopVendorProfile->trade_name.m_buffer;
    InterlockedIncrement((volatile LONG *)&v8->m_cRef);
    purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::sprintf(
      &purchase_string,
      "You have %d %s.",
      v1->m_parent->shopVendorProfile->trade_num - v1->m_parent->m_last_sale,
      v8->m_data);
    v9 = purchase_string.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&result,
      0,
      L"%hs",
      purchase_string.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_buyPurseText, v10);
    v11 = result.id - 20;
    if ( !InterlockedDecrement((volatile LONG *)(result.id - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v5 = valStr.m_buffer;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C35B0) --------------------------------------------------------  // acclient.c:245428
void __thiscall VendorSellUI::UpdateTransactionValue(VendorSellUI *this)
{
  VendorSellUI *v1; // esi@1
  gmVendorUI *v2; // eax@1
  unsigned int v3; // edi@1
  int v4; // ebp@1
  unsigned int v5; // ST14_4@1
  HashBaseData<unsigned long> *v6; // ebx@1
  UIElement *v7; // eax@3
  int v8; // eax@4
  unsigned int v9; // eax@5
  HashBaseData<unsigned long> *v10; // eax@6
  signed int v11; // ecx@7
  int v12; // edi@12
  int v13; // ebx@12
  volatile LONG *v14; // ST14_4@13
  LONG (__stdcall *v15)(volatile LONG *); // ebx@13
  int v16; // eax@18
  AC1Legacy::PSRefBuffer<char> *v17; // edi@20
  PStringBase<unsigned short> *v18; // eax@20
  int v19; // esi@20
  AC1Legacy::PStringBase<char> valStr; // [sp+10h] [bp-Ch]@12
  int numAcceptableItems; // [sp+14h] [bp-8h]@1
  int num; // [sp+18h] [bp-4h]@12

  v1 = this;
  v2 = this->m_parent;
  v3 = 0;
  this->m_transactionValue = 0;
  v4 = 0;
  v5 = v2->shopVendorID;
  numAcceptableItems = 0;
  v6 = ClientObjMaintSystem::GetWeenieObject(v5);
  if ( v6 )
  {
    if ( (signed int)v1->m_sellShopList->m_listItems.m_num > 0 )
    {
      do
      {
        v7 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_sellShopList->vfptr, v3);
        if ( v7 )
        {
          v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435506);
          if ( v8 )
          {
            v9 = *(_DWORD *)(v8 + 1532);
            if ( v9 )
            {
              v10 = ClientObjMaintSystem::GetWeenieObject(v9);
              if ( v10 )
              {
                v11 = v10[20].id;
                if ( !v11 )
                  v11 = 1;
                v4 += v11;
                v1->m_transactionValue += VendorProfile::VendorBuyPrice(
                                            v1->m_parent->shopVendorProfile,
                                            (PublicWeenieDesc *)&v6[12].id,
                                            (PublicWeenieDesc *)&v10[12].id);
              }
            }
          }
        }
        ++v3;
      }
      while ( (signed int)v3 < (signed int)v1->m_sellShopList->m_listItems.m_num );
      numAcceptableItems = v4;
    }
    v12 = AC1Legacy::PStringBase<char>::s_NullBuffer;
    v13 = AC1Legacy::PStringBase<char>::s_NullBuffer + 4;
    valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    num = v1->m_transactionValue;
    if ( v12 == AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      v15 = InterlockedDecrement;
    }
    else
    {
      v14 = (volatile LONG *)v13;
      v15 = InterlockedDecrement;
      if ( !InterlockedDecrement(v14) && v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
      valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    }
    AC1Legacy::PStringBase<char>::append_int32(&valStr, num);
    AC1Legacy::PStringBase<char>::InsertCommas(&valStr);
    v16 = (int)L"item";
    if ( numAcceptableItems != 1 )
      v16 = (int)L"items";
    v17 = valStr.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&num,
      0,
      L"Selling %d %s worth %hsp",
      numAcceptableItems,
      v16,
      valStr.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_sellListText, v18);
    v19 = num - 20;
    if ( !v15((volatile LONG *)(num - 20 + 4)) && v19 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    if ( !v15((volatile LONG *)&v17->m_cRef) )
    {
      if ( v17 )
        v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
    }
  }
}
// 7B58EC: using guessed type wchar_t aItems_2[6];
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C3750) --------------------------------------------------------  // acclient.c:245542
void __thiscall VendorSellUI::UpdateTotalValue(VendorSellUI *this)
{
  int v1; // esi@1
  volatile LONG *v2; // ebx@1
  VendorSellUI *v3; // edi@1
  int v4; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v5; // ebx@6
  PStringBase<unsigned short> *v6; // eax@6
  char *v7; // esi@6
  AC1Legacy::PStringBase<char> valStr; // [sp+10h] [bp-4h]@1

  v1 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v3 = this;
  valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v4 = v3->m_parent->m_totalValue;
  if ( v1 != AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement(v2) && v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    valStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  }
  AC1Legacy::PStringBase<char>::append_int32(&valStr, v4);
  AC1Legacy::PStringBase<char>::InsertCommas(&valStr);
  v5 = valStr.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&valStr,
    0,
    L"You have %hsp",
    valStr.m_buffer->m_data);
  UIElement_Text::SetText(v3->m_sellPurseText, v6);
  v7 = (char *)&valStr.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&valStr.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C3820) --------------------------------------------------------  // acclient.c:245587
void __thiscall gmVendorUI::OnVisibilityChanged(gmVendorUI *this, bool i_bVisible)
{
  gmVendorUI *v2; // esi@1
  unsigned int v3; // ST04_4@4
  CPlayerSystem *v4; // eax@4
  ClientUISystem *v5; // eax@5
  GlobalEventHandler *v6; // eax@5

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 && !i_bVisible )
  {
    ((void (*)(void))v2->m_itemsUI->vfptr->CloseVendor)();
    ((void (*)(void))v2->m_sellUI->vfptr->CloseVendor)();
    ((void (*)(void))v2->m_buyUI->vfptr->CloseVendor)();
    if ( v2->shopVendorID )
    {
      v3 = v2->shopVendorID;
      v4 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::UnregisterObjectRangeHandler(v4, (ObjectRangeHandler *)&v2->vfptr, v3);
    }
    gmVendorUI::ResetShopState(v2, 0);
    v5 = ClientUISystem::GetUISystem();
    ClientUISystem::CloseVendor(v5, 0);
    v6 = GlobalEventHandler::GetGlobalEventHandler();
    v6->vfptr->UnRegisterNoticeHandler((NoticeRegistrar *)v6, (unsigned int)&loc_4DD264, (NoticeHandler *)&v2->vfptr);
    if ( gmVendorUI::m_curDialogContext )
    {
      DialogFactory::CloseDialog(gmVendorUI::m_curDialogContext);
      gmVendorUI::m_curDialogContext = 0;
    }
  }
}

//----- (004C38E0) --------------------------------------------------------  // acclient.c:245622
void __thiscall VendorItemsUI::UpdateItemsUI(VendorItemsUI *this)
{
  VendorItemsUI *v1; // esi@1
  unsigned int v2; // ebx@1
  UIElement_ItemList *v3; // ecx@2
  unsigned int v4; // edi@2
  UIElement *v5; // eax@3
  int v6; // eax@4
  HashBaseData<unsigned long> *v7; // eax@9
  HashBaseData<unsigned long> *v8; // edi@9
  char *v9; // ST24_4@11
  unsigned int v10; // eax@11
  PStringBase<unsigned short> *v11; // eax@11
  int v12; // ebx@11
  const char *v13; // eax@12
  PStringBase<unsigned short> *v14; // eax@12
  LONG v15; // eax@11
  int v16; // ebp@16
  unsigned int v17; // eax@16
  int v18; // ebp@21
  unsigned int v19; // eax@27
  bool v20; // cf@27
  bool v21; // zf@27
  int v22; // eax@27
  AC1Legacy::PSRefBuffer<char> *v23; // ebx@29
  AC1Legacy::PSRefBuffer<char> *v24; // ebp@29
  PStringBase<unsigned short> *v25; // eax@29
  int v26; // edi@29
  AC1Legacy::PSRefBuffer<char> *v27; // edi@32
  PStringBase<unsigned short> *v28; // eax@32
  int v29; // ebx@32
  AC1Legacy::PSRefBuffer<char> *v30; // ebx@35
  AC1Legacy::PStringBase<char> valueStr; // [sp+1Ch] [bp-24h]@21
  AC1Legacy::PStringBase<char> sStatVal; // [sp+20h] [bp-20h]@16
  AC1Legacy::PStringBase<char> purchase_string; // [sp+24h] [bp-1Ch]@21
  int sellPrice; // [sp+28h] [bp-18h]@11
  IDClass<_tagDataID,32,0> trade_id; // [sp+2Ch] [bp-14h]@26
  ItemProfile profile; // [sp+30h] [bp-10h]@1

  v1 = this;
  ItemProfile::ItemProfile(&profile);
  v2 = ACCWeenieObject::selectedID;
  if ( ACCWeenieObject::selectedID == Formatted || (v3 = v1->m_shopList, v4 = 0, (signed int)v3->m_listItems.m_num <= 0) )
  {
LABEL_7:
    UIElement_Text::ClearAllText(v1->m_itemNameText);
    UIElement_Text::ClearAllText(v1->m_itemCostText);
    ((void (__stdcall *)(signed int))v1->m_buyButton->vfptr[13].__vecDelDtor)(13);
    ((void (__stdcall *)(signed int))v1->m_addButton->vfptr[13].__vecDelDtor)(13);
LABEL_8:
    ItemProfile::~ItemProfile(&profile);
    return;
  }
  while ( 1 )
  {
    v5 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v3->vfptr, v4);
    if ( v5 )
    {
      v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
      if ( v6 )
      {
        if ( *(_DWORD *)(v6 + 1532) == v2 )
          break;
      }
    }
    v3 = v1->m_shopList;
    ++v4;
    if ( (signed int)v4 >= (signed int)v3->m_listItems.m_num )
      goto LABEL_7;
  }
  v7 = ClientObjMaintSystem::GetWeenieObject(v2);
  v8 = v7;
  if ( !v7 )
    goto LABEL_8;
  if ( ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v7) <= 1 )
  {
    v13 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v8, 0, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&sellPrice, 0, v13);
    UIElement_Text::SetText(v1->m_itemNameText, v14);
    v12 = sellPrice - 20;
    v15 = InterlockedDecrement((volatile LONG *)(sellPrice - 20 + 4));
  }
  else
  {
    v9 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v8, NAME_PLURAL, 0);
    v10 = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v8);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&sellPrice,
      0,
      L"%d %hs",
      v10,
      v9);
    UIElement_Text::SetText(v1->m_itemNameText, v11);
    v12 = sellPrice - 20;
    v15 = InterlockedDecrement((volatile LONG *)(sellPrice - 20 + 4));
  }
  if ( !v15 && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v16 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  sStatVal.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  sellPrice = (int)v1->m_parent->shopVendorProfile;
  v17 = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v8);
  sellPrice = VendorProfile::VendorSellPrice((VendorProfile *)sellPrice, (PublicWeenieDesc *)&v8[12].id, v17);
  if ( v16 != AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    sStatVal.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  }
  AC1Legacy::PStringBase<char>::append_int32(&sStatVal, sellPrice);
  AC1Legacy::PStringBase<char>::InsertCommas(&sStatVal);
  v18 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  valueStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v1->m_parent->m_totalValue;
  if ( v18 != AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    valueStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  }
  AC1Legacy::PStringBase<char>::append_int32(&valueStr, (int)purchase_string.m_buffer);
  AC1Legacy::PStringBase<char>::InsertCommas(&valueStr);
  VendorProfile::VendorTradeCurrency(v1->m_parent->shopVendorProfile, &trade_id);
  if ( trade_id.id == stru_83F540.id )
  {
    v19 = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v8);
    v20 = v19 < 1;
    v21 = v19 == 1;
    v22 = (int)L"cost";
    if ( v20 || v21 )
      v22 = (int)L"costs";
    v23 = valueStr.m_buffer;
    v24 = sStatVal.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&sellPrice,
      0,
      L"%s %hsp (you have %hsp)",
      v22,
      sStatVal.m_buffer->m_data,
      valueStr.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_itemCostText, v25);
    v26 = sellPrice - 20;
    if ( !InterlockedDecrement((volatile LONG *)(sellPrice - 20 + 4)) && v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  }
  else
  {
    v27 = v1->m_parent->shopVendorProfile->trade_name.m_buffer;
    InterlockedIncrement((volatile LONG *)&v27->m_cRef);
    purchase_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::sprintf(
      &purchase_string,
      "This item costs %d %s. You have %d %s.",
      sellPrice,
      v27->m_data,
      v1->m_parent->shopVendorProfile->trade_num - v1->m_parent->m_last_sale,
      v27->m_data);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&sellPrice,
      0,
      L"%hs",
      purchase_string.m_buffer->m_data);
    UIElement_Text::SetText(v1->m_itemCostText, v28);
    v29 = sellPrice - 20;
    if ( !InterlockedDecrement((volatile LONG *)(sellPrice - 20 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
    v30 = purchase_string.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&purchase_string.m_buffer->m_cRef) && v30 )
      v30->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v30, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v27->m_cRef) && v27 )
      v27->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v27, 1u);
    v23 = valueStr.m_buffer;
    v24 = sStatVal.m_buffer;
  }
  ((void (__stdcall *)(signed int))v1->m_buyButton->vfptr[13].__vecDelDtor)(1);
  v1->m_addButton->vfptr[13].__vecDelDtor((IInputActionCallback *)v1->m_addButton, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&v23->m_cRef) && v23 )
    v23->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v23, 1u);
  if ( InterlockedDecrement((volatile LONG *)&v24->m_cRef) || !v24 )
    goto LABEL_8;
  v24->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v24, 1u);
  ItemProfile::~ItemProfile(&profile);
}
// 7B59BC: using guessed type wchar_t aCosts[6];
// 7B59C8: using guessed type wchar_t aCost[5];
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C3CE0) --------------------------------------------------------  // acclient.c:245815
void __thiscall VendorItemsUI::RemoveFromShop(VendorItemsUI *this, ACCWeenieObject *_weenObj, int _amountBought)
{
  VendorItemsUI *v3; // edi@1
  int v4; // eax@1
  int v5; // eax@7
  gmVendorUI *v6; // ecx@8
  unsigned int v7; // ecx@9
  unsigned int v8; // ecx@12
  unsigned int v9; // esi@15
  ItemProfile curProfile; // [sp+8h] [bp-10h]@1

  v3 = this;
  ItemProfile::ItemProfile(&curProfile);
  v4 = (int)v3->m_parent->shopItemProfileList->head;
  if ( v4 )
  {
    while ( *(_DWORD *)(v4 + 8) != _weenObj->id )
    {
      v4 = *(_DWORD *)(v4 + 16);
      if ( !v4 )
        goto LABEL_6;
    }
    ItemProfile::operator=((int)&curProfile, v4);
  }
LABEL_6:
  if ( curProfile.amount != -1 )
  {
    v5 = curProfile.amount - _amountBought;
    if ( curProfile.amount - _amountBought <= 0 )
    {
      v6 = v3->m_parent;
      gmVendorUI::DeleteItem(v3->m_shopList, _weenObj->id, 1);
      ACCWeenieObject::SetSelectedObject(0, 0);
      ItemProfile::~ItemProfile(&curProfile);
      return;
    }
    v7 = _weenObj->pwd._maxStackSize;
    if ( v7 > 1 )
    {
      if ( v5 > (signed int)v7 )
        v5 = _weenObj->pwd._maxStackSize;
      v8 = _weenObj->pwd._stackSize;
      if ( !v8 )
        v8 = 1;
      if ( v8 != v5 )
      {
        VendorSubUI::SetObjectStackSize(_weenObj, v5);
        v9 = _weenObj->id;
        if ( ACCWeenieObject::selectedID == v9 )
          GenItemHolder::ItemAttributesChanged_s(v9, 0);
        VendorItemsUI::UpdateItemsUI(v3);
      }
    }
  }
  ItemProfile::~ItemProfile(&curProfile);
}

//----- (004C3DC0) --------------------------------------------------------  // acclient.c:245873
void __thiscall VendorItemsUI::AddToBuyList(VendorItemsUI *this, ACCWeenieObject *weenObj, int amountBuyingNow)
{
  VendorItemsUI *v3; // ebp@1
  int v4; // edi@1
  int v5; // esi@1
  gmVendorUI *v6; // esi@5
  int v7; // esi@5
  void *v8; // edi@5
  gmVendorUI *v9; // edx@8
  int v10; // ecx@8
  int v11; // eax@14
  unsigned int v12; // eax@15
  char *v13; // esi@15
  int v14; // eax@22
  PStringBase<unsigned short> _value; // [sp+Ch] [bp-A4h]@15
  ItemProfile curProfile; // [sp+10h] [bp-A0h]@1
  StringInfo siError; // [sp+20h] [bp-90h]@15

  v3 = this;
  v4 = 0;
  ItemProfile::ItemProfile(&curProfile);
  v5 = (int)v3->m_parent->m_buyList.head;
  if ( !v5 )
  {
LABEL_5:
    v6 = v3->m_parent;
    curProfile.iid = weenObj->id;
    curProfile.amount = amountBuyingNow;
    curProfile.pwd = 0;
    v7 = (int)&v6->m_buyList;
    v8 = operator new(0x18u);
    if ( v8 )
    {
      ItemProfile::ItemProfile((ItemProfile *)v8, &curProfile);
      *((_DWORD *)v8 + 4) = 0;
      *((_DWORD *)v8 + 5) = 0;
    }
    else
    {
      v8 = 0;
    }
    if ( *(_DWORD *)(v7 + 4) )
    {
      v14 = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(v14 + 16) = v8;
      *((_DWORD *)v8 + 5) = v14;
    }
    else
    {
      *(_DWORD *)(v7 + 4) = v8;
    }
    ++*(_DWORD *)(v7 + 12);
    v11 = amountBuyingNow;
    *(_DWORD *)(v7 + 8) = v8;
LABEL_24:
    VendorItemsUI::RemoveFromShop(v3, weenObj, v11);
    goto LABEL_25;
  }
  while ( 1 )
  {
    ItemProfile::operator=((int)&curProfile, v5);
    if ( curProfile.iid == weenObj->id )
      break;
    ++v4;
    if ( v5 )
    {
      v5 = *(_DWORD *)(v5 + 16);
      if ( v5 )
        continue;
    }
    goto LABEL_5;
  }
  if ( curProfile.amount + amountBuyingNow <= 5000 )
  {
    v9 = v3->m_parent;
    curProfile.amount += amountBuyingNow;
    v10 = (int)v9->m_buyList.head;
    if ( v4 > 0 )
    {
      do
      {
        if ( v10 )
          v10 = *(_DWORD *)(v10 + 16);
        --v4;
      }
      while ( v4 );
    }
    if ( v10 )
      ItemProfile::operator=(v10, (int)&curProfile);
    v11 = curProfile.amount;
    goto LABEL_24;
  }
  StringInfo::StringInfo(&siError);
  v12 = _wcslen(L"I can't possibly sell you that much! Please be a little more reasonable.");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v12);
  _wcscpy(_value.m_charbuffer->m_data, L"I can't possibly sell you that much! Please be a little more reasonable.");
  StringInfo::SetLiteralValue(&siError, &_value, 1);
  v13 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  StringInfo::~StringInfo(&siError);
LABEL_25:
  ItemProfile::~ItemProfile(&curProfile);
}

//----- (004C3F70) --------------------------------------------------------  // acclient.c:245980
void __thiscall VendorBuyUI::Update(VendorBuyUI *this)
{
  VendorBuyUI *v1; // esi@1

  v1 = this;
  gmVendorUI::AdoptAsContents(this->m_buyShopList, &this->m_parent->m_buyList, 1);
  VendorBuyUI::UpdateBuyUI(v1);
  VendorBuyUI::UpdateTransactionValue(v1);
  VendorBuyUI::UpdateTotalValue(v1);
}

//----- (004C3FA0) --------------------------------------------------------  // acclient.c:245992
void __thiscall VendorSellUI::Update(VendorSellUI *this)
{
  VendorSellUI *v1; // esi@1

  v1 = this;
  gmVendorUI::AdoptAsContents(this->m_sellShopList, &this->m_parent->m_sellList, 1);
  VendorSellUI::UpdateSellUI(v1);
  VendorSellUI::UpdateTransactionValue(v1);
  VendorSellUI::UpdateTotalValue(v1);
}

//----- (004C3FD0) --------------------------------------------------------  // acclient.c:246004
void __thiscall VendorSellUI::ItemAttributesChanged(VendorSellUI *this, unsigned int _itemID, int _flags)
{
  VendorSellUI *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@3
  unsigned int v5; // eax@5
  UIElement_ItemList *v6; // edi@8
  int v7; // ebp@8
  HashBaseData<unsigned long> *v8; // ebx@9
  gmVendorUI *v9; // ecx@14
  PackableList<ItemProfile> *v10; // ST04_4@14
  UIElement_ItemList *v11; // ST00_4@14

  v3 = this;
  if ( this->m_splitItem )
  {
    if ( _flags & 1 )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
      if ( v4 )
      {
        if ( v4[13].id == v3->m_splitItemClassID.id )
        {
          v5 = v4[20].id;
          if ( !v5 )
            LOWORD(v5) = 1;
          if ( (_WORD)v5 == v3->m_splitItemStackSize )
          {
            v6 = v3->m_sellShopList;
            v7 = UIElement_ListBox::WhatNum(
                   (UIElement_ListBox *)&v3->m_sellShopList->vfptr,
                   (UIElement *)&v3->m_splitItem->vfptr);
            if ( v6 )
            {
              v8 = ClientObjMaintSystem::GetWeenieObject(_itemID);
              if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v8)
                && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v8) )
              {
                if ( v6->m_desc.m_elementID == 268435662 )
                  ACCWeenieObject::SetSellState((ACCWeenieObject *)v8, 1);
                UIElement_ItemList::ItemList_InsertItem(v6, _itemID, v7);
              }
            }
            v9 = v3->m_parent;
            gmVendorUI::DeleteItem(v3->m_sellShopList, v3->m_splitItem->itemID, 1);
            v10 = &v3->m_parent->m_sellList;
            v11 = v3->m_sellShopList;
            v3->m_splitItem = 0;
            gmVendorUI::RecordContents(v11, v10, 0, 1);
            VendorSellUI::Update(v3);
          }
        }
      }
    }
  }
}

//----- (004C40D0) --------------------------------------------------------  // acclient.c:246061
void __thiscall gmVendorUI::HandleMousePresses(gmVendorUI *this, UIElementMessageInfo *i_rMsg)
{
  gmVendorUI *v2; // esi@1
  UIElement *v3; // eax@1
  UIElement *v4; // eax@3
  int v5; // eax@4
  unsigned int v6; // eax@6
  UIElement *v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  int v10; // edi@11
  HashBaseData<unsigned long> *v11; // eax@14
  PStringBase<unsigned short> *v12; // eax@15
  VendorSellUI *v13; // edx@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  int v16; // edi@20
  HashBaseData<unsigned long> *v17; // eax@23
  PStringBase<unsigned short> *v18; // eax@24
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@15
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@15
  StringInfo siError; // [sp+10h] [bp-90h]@15

  v2 = this;
  v3 = (UIElement *)&this->m_itemsUI->m_shopList->vfptr;
  if ( v3 && UIElement::IsAncestorOfMe(i_rMsg->pElement, v3) )
  {
    v4 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v2->m_itemsUI->m_shopList->vfptr);
    if ( v4 )
    {
      v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
      if ( v5 )
      {
        if ( i_rMsg->dwParam1 == 10 )
        {
          v6 = *(_DWORD *)(v5 + 1532);
          if ( v6 )
            gmVendorUI::BuySingleItem(v2, v6);
        }
      }
    }
  }
  else
  {
    v7 = (UIElement *)&v2->m_buyUI->m_buyShopList->vfptr;
    if ( v7 && UIElement::IsAncestorOfMe(i_rMsg->pElement, v7) )
    {
      v8 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v2->m_buyUI->m_buyShopList->vfptr);
      if ( v8 )
      {
        v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506);
        v10 = v9;
        if ( v9 )
        {
          if ( i_rMsg->dwParam1 == 10 && *(_DWORD *)(v9 + 1532) )
          {
            v11 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v9 + 1532));
            if ( v11 )
            {
              v12 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &result, NAME_APPROPRIATE, 0);
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &errorText,
                0,
                L"Removing %s from shopping list",
                v12->m_charbuffer);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
              StringInfo::StringInfo(&siError);
              StringInfo::SetLiteralValue(&siError, &errorText, 1);
              ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
              StringInfo::~StringInfo(&siError);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
            }
            gmVendorUI::RemoveProfileFromList(&v2->m_buyList, *(_DWORD *)(v10 + 1532), 1);
            VendorBuyUI::Update(v2->m_buyUI);
          }
        }
      }
    }
    else
    {
      v13 = v2->m_sellUI;
      if ( v13->m_sellShopList )
      {
        if ( UIElement::IsAncestorOfMe(i_rMsg->pElement, (UIElement *)&v13->m_sellShopList->vfptr) )
        {
          v14 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v2->m_sellUI->m_sellShopList->vfptr);
          if ( v14 )
          {
            v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)268435506);
            v16 = v15;
            if ( v15 )
            {
              if ( i_rMsg->dwParam1 == 10 && *(_DWORD *)(v15 + 1532) )
              {
                v17 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v15 + 1532));
                if ( v17 )
                {
                  v18 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v17, &result, NAME_APPROPRIATE, 0);
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &errorText,
                    0,
                    L"Removing %s from shopping list",
                    v18->m_charbuffer);
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
                  StringInfo::StringInfo(&siError);
                  StringInfo::SetLiteralValue(&siError, &errorText, 1);
                  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
                  StringInfo::~StringInfo(&siError);
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
                }
                gmVendorUI::VendorItemSetSellState(*(_DWORD *)(v16 + 1532), 0);
                gmVendorUI::RemoveProfileFromList(&v2->m_sellList, *(_DWORD *)(v16 + 1532), -1);
                VendorSellUI::Update(v2->m_sellUI);
              }
            }
          }
        }
      }
    }
  }
}

//----- (004C4380) --------------------------------------------------------  // acclient.c:246184
void __thiscall gmVendorUI::RecvNotice_ItemListBeginDrag(gmVendorUI *this, UIElement *i_itemList, int i_slotNum)
{
  gmVendorUI *v3; // edi@1
  HashSetData<UIElement *> *v4; // eax@1
  UIElement_ListBox *v5; // eax@2
  UIElement *v6; // eax@3
  int v7; // eax@4
  int v8; // esi@4
  HashBaseData<unsigned long> *v9; // eax@6
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@9
  StringInfo siError; // [sp+8h] [bp-90h]@9

  v3 = this;
  v4 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14];
  if ( v4 )
  {
    v5 = (UIElement_ListBox *)v4[1].m_hashNext;
    if ( (UIElement *)v5 == i_itemList )
    {
      v6 = UIElement_ListBox::GetItem(v5, i_slotNum);
      if ( v6 )
      {
        v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
        v8 = v7;
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 1532) )
          {
            ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v7 + 1532));
            v9 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v8 + 1532));
            if ( v9 )
              ACCWeenieObject::SetSellState((ACCWeenieObject *)v9, 0);
            gmVendorUI::RemoveProfileFromList(
              (PackableList<ItemProfile> *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8],
              *(_DWORD *)(v8 + 1532),
              -1);
            VendorSellUI::Update((VendorSellUI *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]);
            if ( GenItemHolder::splitSize < GenItemHolder::maxSplitSize )
            {
              StringInfo::StringInfo(&siError);
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &_value,
                L"You cannot split items from this panel");
              StringInfo::SetLiteralValue(&siError, &_value, 1);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
              ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
              GenItemHolder::splitSize = GenItemHolder::maxSplitSize;
              CM_UI::SendNotice_UpdateToolbarSelectionDisplay();
              StringInfo::~StringInfo(&siError);
            }
          }
        }
      }
    }
  }
}

//----- (004C44A0) --------------------------------------------------------  // acclient.c:246242
void __thiscall gmVendorUI::RecvNotice_ServerSaysMoveItem(gmVendorUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmVendorUI *v9; // esi@1
  HashBaseData<unsigned long> *v10; // eax@2

  v9 = this;
  if ( UIElement_ItemList::ItemList_IsInList(
         (UIElement_ItemList *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14][1].m_hashNext,
         _itemID) )
  {
    v10 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v10 )
    {
      if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v10) )
      {
        gmVendorUI::RemoveProfileFromList(
          (PackableList<ItemProfile> *)&v9->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8],
          _itemID,
          -1);
        VendorSellUI::Update((VendorSellUI *)v9->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]);
      }
    }
  }
}

//----- (004C44F0) --------------------------------------------------------  // acclient.c:246268
void __thiscall gmVendorUI::RecvNotice_ItemAttributesChanged(gmVendorUI *this, unsigned int i_target, unsigned int i_attrib)
{
  VendorSellUI::ItemAttributesChanged(
    (VendorSellUI *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14],
    i_target,
    i_attrib);
}

//----- (004C4500) --------------------------------------------------------  // acclient.c:246277
void __thiscall gmVendorUI::RecvNotice_StackSliderChanged(gmVendorUI *this, unsigned int i_splitSize, unsigned int i_maxSplitSize)
{
  gmVendorUI *v3; // esi@1
  HashSetData<UIElement *> *v4; // eax@2

  v3 = this;
  if ( UIElement::IsVisible((UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[17]) )
  {
    v4 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12];
    if ( v4 )
    {
      if ( ACCWeenieObject::selectedID )
      {
        if ( UIElement_ItemList::ItemList_IsInList((UIElement_ItemList *)v4[1].m_hashKey, ACCWeenieObject::selectedID) )
          VendorItemsUI::UpdateItemsUI((VendorItemsUI *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]);
      }
    }
  }
}

//----- (004C4540) --------------------------------------------------------  // acclient.c:246298
void __thiscall gmVendorUI::FillComponentList(gmVendorUI *this, SpellComponentCategory sp_cat, int max_to_spend)
{
  gmVendorUI *v3; // ebp@1
  ClientSystem *v4; // esi@2
  int v5; // esi@2
  LONG v6; // eax@2
  CPlayerSystem *v7; // eax@3
  ComponentTracker *v8; // eax@3
  ComponentTracker *v9; // ebx@3
  CPlayerSystem *v10; // eax@3
  CPlayerSystem *v11; // eax@3
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v12; // eax@3
  IDClass<_tagDataID,32,0> v13; // edi@6
  int v14; // esi@6
  IDClass<_tagDataID,32,0> v15; // ST0C_4@6
  int v16; // esi@9
  int v17; // eax@10
  int v18; // ebx@15
  HashBaseData<unsigned long> *v19; // eax@17
  HashBaseData<unsigned long> *v20; // edi@17
  int v21; // eax@18
  unsigned int v22; // eax@22
  LONG (__stdcall *v23)(volatile LONG *); // edi@27
  ClientSystem *v24; // esi@29
  PStringBase<unsigned short> *v25; // eax@29
  int v26; // esi@29
  ClientSystem *v27; // esi@32
  int v28; // esi@32
  VendorBuyUI *v29; // esi@35
  UIElement_Panel *v30; // ecx@35
  ClientSystem *v31; // esi@43
  int v32; // esi@43
  PStringBase<char> unfilled_comps; // [sp+8h] [bp-48h]@3
  int cTotalCost; // [sp+Ch] [bp-44h]@3
  int current_amount; // [sp+10h] [bp-40h]@6
  int cAvailableInShop; // [sp+14h] [bp-3Ch]@9
  unsigned int iid; // [sp+18h] [bp-38h]@9
  ComponentTracker *tracker; // [sp+1Ch] [bp-34h]@3
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> comp_iter; // [sp+20h] [bp-30h]@3
  ItemProfile curProfile; // [sp+30h] [bp-20h]@10
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> comp_iter_end; // [sp+40h] [bp-10h]@3

  v3 = this;
  if ( this->shopVendorID )
  {
    VendorItemsUI::UpdateItemsList(this->m_itemsUI, 4096, 0);
    v7 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::GetComponentTracker(v7);
    v9 = v8;
    tracker = v8;
    v10 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::GetDesiredCompHashStart((PlayerModule *)&v10->playerModule.vfptr, &comp_iter);
    v11 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::GetDesiredCompHashEnd((PlayerModule *)&v11->playerModule.vfptr, &comp_iter_end);
    unfilled_comps.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    cTotalCost = 0;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v12 = comp_iter._current;
    if ( comp_iter_end._current == comp_iter._current )
    {
LABEL_27:
      v23 = InterlockedDecrement;
    }
    else
    {
      while ( cTotalCost < max_to_spend || !max_to_spend )
      {
        v13.id = v12->_key.id;
        v14 = v12->_data;
        v15.id = v12->_key.id;
        current_amount = 0;
        ComponentTracker::GetNumComponent(v9, v15, &current_amount);
        if ( (ComponentTracker::DetermineComponentCategory(v9, v13) == sp_cat || sp_cat == 8) && current_amount < v14 )
        {
          v16 = v14 - current_amount;
          cAvailableInShop = v16;
          if ( gmVendorUI::ShopHasItem(v3, v13, &cAvailableInShop, &iid) )
          {
            ItemProfile::ItemProfile(&curProfile);
            v17 = (int)v3->m_buyList.head;
            if ( v17 )
            {
              while ( *(_DWORD *)(v17 + 8) != iid )
              {
                v17 = *(_DWORD *)(v17 + 16);
                if ( !v17 )
                  goto LABEL_15;
              }
              ItemProfile::operator=((int)&curProfile, v17);
              v16 -= curProfile.amount;
            }
LABEL_15:
            v18 = cAvailableInShop;
            if ( cAvailableInShop < v16 )
            {
              gmVendorUI::AddMissingComp(v13, &unfilled_comps);
              v16 = v18;
            }
            v19 = ClientObjMaintSystem::GetWeenieObject(iid);
            v20 = v19;
            if ( v19 )
            {
              VendorItemsUI::AddToBuyList(v3->m_itemsUI, (ACCWeenieObject *)v19, v16);
              v21 = VendorProfile::VendorSellPrice(v3->shopVendorProfile, (PublicWeenieDesc *)&v20[12].id, v16);
              cTotalCost += v21;
            }
            ItemProfile::~ItemProfile(&curProfile);
            v9 = tracker;
          }
          else
          {
            gmVendorUI::AddMissingComp(v13, &unfilled_comps);
          }
        }
        v12 = comp_iter._current->_next;
        if ( !v12 )
        {
          v22 = comp_iter._current->_hashVal + 1;
          if ( v22 >= comp_iter._table_size )
          {
LABEL_25:
            v12 = 0;
          }
          else
          {
            while ( !comp_iter._buckets[v22] )
            {
              ++v22;
              if ( v22 >= comp_iter._table_size )
                goto LABEL_25;
            }
            v12 = comp_iter._buckets[v22];
          }
        }
        comp_iter._current = v12;
        if ( comp_iter_end._current == v12 )
          goto LABEL_27;
      }
      ItemProfile::ItemProfile(&curProfile);
      PackableList<ItemProfile>::RemoveTail(&v3->m_buyList, &curProfile);
      v31 = (ClientSystem *)ClientUISystem::GetUISystem();
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&max_to_spend,
        0,
        "Buying aborted; max price reached.\n");
      ClientSystem::AddTextToScroll(v31, (PStringBase<unsigned short> *)&max_to_spend, 0, 1, 0);
      v23 = InterlockedDecrement;
      v32 = max_to_spend - 20;
      if ( !InterlockedDecrement((volatile LONG *)(max_to_spend - 20 + 4)) && v32 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
      ItemProfile::~ItemProfile(&curProfile);
    }
    if ( *(_DWORD *)&unfilled_comps.m_charbuffer[-1].m_data[12] != 1 )
    {
      v24 = (ClientSystem *)ClientUISystem::GetUISystem();
      v25 = PStringBase<char>::to_wpstring(&unfilled_comps, (PStringBase<unsigned short> *)&max_to_spend, 0);
      ClientSystem::AddTextToScroll(v24, v25, 0, 1, 0);
      v26 = max_to_spend - 20;
      if ( !v23((volatile LONG *)(max_to_spend - 20 + 4)) && v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
      v27 = (ClientSystem *)ClientUISystem::GetUISystem();
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&max_to_spend, 0, "\n");
      ClientSystem::AddTextToScroll(v27, (PStringBase<unsigned short> *)&max_to_spend, 0, 1, 0);
      v28 = max_to_spend - 20;
      if ( !v23((volatile LONG *)(max_to_spend - 20 + 4)) && v28 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
    }
    v29 = v3->m_buyUI;
    gmVendorUI::AdoptAsContents(v29->m_buyShopList, &v29->m_parent->m_buyList, 1);
    VendorBuyUI::UpdateBuyUI(v29);
    VendorBuyUI::UpdateTransactionValue(v29);
    VendorBuyUI::UpdateTotalValue(v29);
    v30 = v3->m_vendorPanel;
    if ( v30 )
    {
      v3->m_last_sale = 0;
      UIElement_Panel::OpenTab(v30, 0x100000BAu);
    }
    v5 = (int)&unfilled_comps.m_charbuffer[-2].m_data[12];
    v6 = v23((volatile LONG *)&unfilled_comps.m_charbuffer[-1]);
  }
  else
  {
    v4 = (ClientSystem *)ClientUISystem::GetUISystem();
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&max_to_spend,
      0,
      "You need an open vendor.");
    ClientSystem::AddTextToScroll(v4, (PStringBase<unsigned short> *)&max_to_spend, 0x1Au, 1, 0);
    v5 = max_to_spend - 20;
    v6 = InterlockedDecrement((volatile LONG *)(max_to_spend - 20 + 4));
  }
  if ( !v6 )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (004C48E0) --------------------------------------------------------  // acclient.c:246498
void __thiscall gmVendorUI::UpdateTotalValue(gmVendorUI *this)
{
  gmVendorUI *v1; // esi@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // ebx@1
  int v4; // ebp@3
  PlayerDesc *v5; // ebx@5
  int v6; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v9; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_13, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v9, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface && v4 >= 0 )
    CBaseQualities::InqInt((CBaseQualities *)&playerDesc.m_pInterface->vfptr, 0x14u, &v1->m_totalValue, 0, 0);
  else
    v1->m_totalValue = 0;
  VendorItemsUI::UpdateItemsUI(v1->m_itemsUI);
  VendorBuyUI::UpdateTotalValue(v1->m_buyUI);
  VendorSellUI::UpdateTotalValue(v1->m_sellUI);
  if ( v5 )
    v5->vfptr->Release((Interface *)v5);
}

//----- (004C49B0) --------------------------------------------------------  // acclient.c:246537
void __thiscall VendorItemsUI::HandleSetSelectedItem(VendorItemsUI *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  VendorItemsUI *v3; // esi@1

  v3 = this;
  VendorItemsUI::UpdateItemsUI(this);
  VendorItemsUI::UpdateQuantityOverlay(v3);
}

//----- (004C49D0) --------------------------------------------------------  // acclient.c:246547
void __thiscall VendorBuyUI::OpenVendor(VendorBuyUI *this, bool _updating)
{
  VendorBuyUI *v2; // esi@1

  v2 = this;
  if ( _updating )
  {
    gmVendorUI::AdoptAsContents(this->m_buyShopList, &this->m_parent->m_buyList, 1);
    VendorBuyUI::UpdateBuyUI(v2);
    VendorBuyUI::UpdateTransactionValue(v2);
    VendorBuyUI::UpdateTotalValue(v2);
  }
  else
  {
    UIElement_ItemList::ItemList_Flush(this->m_buyShopList);
  }
}

//----- (004C4A20) --------------------------------------------------------  // acclient.c:246566
void __thiscall VendorSellUI::AddItemToSell(VendorSellUI *this, unsigned int _itemID)
{
  VendorSellUI *v2; // esi@1
  gmVendorUI *v3; // eax@1
  UIElement_Panel *v4; // ecx@1

  v2 = this;
  v3 = this->m_parent;
  v4 = v3->m_vendorPanel;
  if ( v4 )
  {
    v3->m_last_sale = 0;
    UIElement_Panel::OpenTab(v4, 0x100000BBu);
  }
  ACCWeenieObject::SetSelectedObject(_itemID, 0);
  gmVendorUI::AddItem(v2->m_parent, v2->m_sellShopList, _itemID, -1, 1, 1, 0, 1, -1);
  gmVendorUI::RecordContents(v2->m_sellShopList, &v2->m_parent->m_sellList, 0, 1);
  gmVendorUI::AdoptAsContents(v2->m_sellShopList, &v2->m_parent->m_sellList, 1);
  VendorSellUI::UpdateSellUI(v2);
  VendorSellUI::UpdateTransactionValue(v2);
  VendorSellUI::UpdateTotalValue(v2);
}

//----- (004C4AC0) --------------------------------------------------------  // acclient.c:246590
void __thiscall gmVendorUI::RecvNotice_AddItemToSell(gmVendorUI *this, unsigned int i_itemID)
{
  VendorSellUI::AddItemToSell(
    (VendorSellUI *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14],
    i_itemID);
}

//----- (004C4AD0) --------------------------------------------------------  // acclient.c:246598
void __thiscall gmVendorUI::RecvNotice_FillComponentBuyList(gmVendorUI *this, SpellComponentCategory i_sp_cat, int i_max_to_buy)
{
  gmVendorUI::FillComponentList((gmVendorUI *)((char *)this - 1528), i_sp_cat, i_max_to_buy);
}

//----- (004C4AE0) --------------------------------------------------------  // acclient.c:246604
void __thiscall gmVendorUI::OnQualityChanged(gmVendorUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  unsigned int v4; // esi@1
  gmVendorUI *v5; // edi@1
  VendorProfile *v6; // ecx@3
  unsigned int v7; // esi@5
  HashBaseData<unsigned long> *v8; // eax@6

  v4 = senum;
  v5 = this;
  if ( senum == 20 )
  {
    gmVendorUI::UpdateTotalValue((gmVendorUI *)((char *)this - 1532));
  }
  else
  {
    v6 = (VendorProfile *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
    if ( v6 )
    {
      VendorProfile::VendorTradeCurrency(v6, (IDClass<_tagDataID,32,0> *)&senum);
      if ( v4 == 5 )
      {
        v7 = stru_83F540.id;
        if ( senum != stru_83F540.id )
        {
          v8 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
          if ( v8 )
            v7 = v8[13].id;
          if ( v7 == senum )
            ((void (__thiscall *)(int, _DWORD))v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[16][3].m_hashKey)(
              &v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[16],
              0);
        }
      }
    }
  }
}

//----- (004C4B60) --------------------------------------------------------  // acclient.c:246643
void __thiscall gmVendorUI::OnQualityRemoved(gmVendorUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  unsigned int v4; // edi@1
  gmVendorUI *v5; // esi@1
  VendorProfile *v6; // ecx@2

  v4 = senum;
  v5 = this;
  if ( senum == 20
    || (v6 = (VendorProfile *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]) != 0
    && (VendorProfile::VendorTradeCurrency(v6, (IDClass<_tagDataID,32,0> *)&senum), v4 == 5)
    && senum != stru_83F540.id )
    gmVendorUI::UpdateTotalValue((gmVendorUI *)((char *)v5 - 1532));
}

//----- (004C4BA0) --------------------------------------------------------  // acclient.c:246659
void __thiscall gmVendorUI::OpenVendor(gmVendorUI *this, unsigned int _vendorID, VendorProfile *_vendorProfile, PackableList<ItemProfile> *_itemProfileList, ShopMode _startMode)
{
  gmVendorUI *v5; // esi@1
  unsigned int v6; // edi@1
  unsigned int v7; // eax@4
  int v8; // ebx@4
  HashBaseData<unsigned long> *v9; // eax@6
  long double _range; // ST08_8@7
  unsigned int v11; // ST04_4@7
  CPlayerSystem *v12; // eax@7
  VendorProfile *v13; // eax@8
  int v14; // eax@9
  int v15; // ST24_4@11
  void *v16; // eax@11
  int v17; // ST24_4@14
  InterfaceSystem *v18; // eax@14
  unsigned int v19; // edi@14
  PackableLLNode<ItemProfile> *v20; // edi@18
  HashBaseData<unsigned long> *v21; // eax@20
  HashBaseData<unsigned long> *v22; // ebx@20
  int v23; // ebx@24
  PackableLLNode<ItemProfile> *v24; // eax@25
  int v25; // ecx@25
  PackableLLNode<ItemProfile> *v26; // edi@32
  int v27; // eax@33
  UIElement_Panel *v28; // ecx@41
  GlobalEventHandler *v29; // eax@46
  int v30; // [sp+18h] [bp-44h]@14
  unsigned int v31; // [sp+1Ch] [bp-40h]@42
  int updating; // [sp+30h] [bp-2Ch]@4
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+34h] [bp-28h]@14
  ItemProfile profile; // [sp+3Ch] [bp-20h]@33
  ItemProfile val; // [sp+4Ch] [bp-10h]@36

  v5 = this;
  gmVendorUI::UpdateTotalValue(this);
  v6 = _vendorID;
  if ( ACCWeenieObject::prevRequest == 10 && ACCWeenieObject::prevRequestObjectID == _vendorID )
    ACCWeenieObject::RecordResponse(_vendorID);
  v7 = v5->shopVendorID;
  v8 = v7 == v6;
  updating = v7 == v6;
  if ( v7 )
    gmVendorUI::CloseVendor(v5, v7 == v6);
  v5->shopVendorID = v6;
  v9 = ClientObjMaintSystem::GetWeenieObject(v6);
  if ( v9 )
  {
    _range = *(float *)&v9[18].hash_next;
    v11 = v9->id;
    v12 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::RegisterObjectRangeHandler(v12, (ObjectRangeHandler *)&v5->vfptr, v11, _range, 1, 0, 1.0, 0.0);
  }
  v13 = (VendorProfile *)operator new(0x28u);
  if ( v13 )
    VendorProfile::VendorProfile(v13);
  else
    v14 = 0;
  v15 = (int)_vendorProfile;
  v5->shopVendorProfile = (VendorProfile *)v14;
  VendorProfile::operator=(v14, v15);
  v16 = operator new(0x10u);
  if ( v16 )
  {
    *(_DWORD *)v16 = &PackableList<ItemProfile>::vftable;
    *((_DWORD *)v16 + 1) = 0;
    *((_DWORD *)v16 + 2) = 0;
    *((_DWORD *)v16 + 3) = 0;
  }
  else
  {
    v16 = 0;
  }
  v17 = (int)_itemProfileList;
  v5->shopItemProfileList = (PackableList<ItemProfile> *)v16;
  PackableList<ItemProfile>::operator=((PackableList<ItemProfile> *)v16, v17);
  _vendorID = 0;
  v18 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v18, (TResult *)&_vendorProfile, &ClientObjMaintSystem_ClassType, (Interface **)&_vendorID);
  v30 = _vendorID;
  v19 = _vendorID;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( _vendorID )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)_vendorID + 16))(_vendorID);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&_itemProfileList, v30, 0);
  if ( v19 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v19 + 20))(v19);
  v20 = v5->shopItemProfileList->head;
  for ( _vendorID = 0; v20; ++_vendorID )
  {
    if ( v20->data.pwd )
    {
      v21 = ClientObjMaintSystem::GetWeenieObject(v20->data.iid);
      v22 = v21;
      if ( v21 )
      {
        if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v21) )
          PublicWeenieDesc::operator=((int)&v22[12].id, (int)v20->data.pwd);
        CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, v20->data.iid);
      }
      else
      {
        v23 = CFactory::MakeCWeenieObject(v20->data.iid);
        CObjectMaint::AddWeenieObject((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, (CWeenieObject *)v23);
        PublicWeenieDesc::operator=(v23 + 152, (int)v20->data.pwd);
        ACCWeenieObject::DeterminePositionState((ACCWeenieObject *)v23);
        ACCWeenieObject::DeclareValid((ACCWeenieObject *)v23);
      }
      v24 = v5->shopItemProfileList->head;
      v25 = 0;
      if ( v24 )
      {
        while ( v25 != _vendorID )
        {
          v24 = v24->next;
          ++v25;
          if ( !v24 )
            goto LABEL_28;
        }
      }
      else
      {
LABEL_28:
        v24 = 0;
      }
      ItemProfile::Clear(&v24->data);
      v8 = updating;
    }
    v20 = v20->next;
  }
  if ( v8 )
  {
    while ( 1 )
    {
      v26 = v5->m_buyList.head;
      if ( !v26 )
        break;
      while ( 1 )
      {
        ItemProfile::ItemProfile(&profile);
        v27 = (int)v5->shopItemProfileList->head;
        if ( !v27 )
          break;
        while ( *(_DWORD *)(v27 + 8) != v26->data.iid )
        {
          v27 = *(_DWORD *)(v27 + 16);
          if ( !v27 )
            goto LABEL_36;
        }
        ItemProfile::operator=((int)&profile, v27);
        ItemProfile::~ItemProfile(&profile);
        v26 = v26->next;
        if ( !v26 )
          goto LABEL_46;
      }
LABEL_36:
      ItemProfile::ItemProfile(&val, &v26->data);
      PackableList<ItemProfile>::Remove(&v5->m_buyList, &val);
      ItemProfile::~ItemProfile(&val);
      ItemProfile::~ItemProfile(&profile);
    }
  }
  else
  {
    if ( _startMode == 2 )
    {
      v28 = v5->m_vendorPanel;
      if ( !v28 )
        goto LABEL_46;
      v31 = 268435641;
    }
    else
    {
      if ( _startMode != 3 )
        goto LABEL_46;
      v28 = v5->m_vendorPanel;
      if ( !v28 )
        goto LABEL_46;
      v31 = 268435643;
    }
    v5->m_last_sale = 0;
    UIElement_Panel::OpenTab(v28, v31);
  }
LABEL_46:
  LOBYTE(v8) = v8 != 0;
  ((void (__stdcall *)(int))v5->m_itemsUI->vfptr->OpenVendor)(v8);
  ((void (__stdcall *)(int))v5->m_sellUI->vfptr->OpenVendor)(v8);
  ((void (__stdcall *)(int))v5->m_buyUI->vfptr->OpenVendor)(v8);
  v29 = GlobalEventHandler::GetGlobalEventHandler();
  v29->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v29, (unsigned int)&loc_4DD264, (NoticeHandler *)&v5->vfptr);
  v5->vfptr[2].__vecDelDtor((IInputActionCallback *)v5, 1u);
  if ( (_DWORD)spObjMaint.m_pInterface )
    ((void (*)(void))spObjMaint.m_pInterface->vfptr->Release)();
}
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;

//----- (004C4F00) --------------------------------------------------------  // acclient.c:246859
char __thiscall VendorSellUI::AcceptDragObject(VendorSellUI *this, unsigned int _itemID)
{
  VendorSellUI *v2; // edi@1
  char v3; // al@1
  HashBaseData<unsigned long> *v4; // esi@2
  signed int v5; // ebx@3
  unsigned int v6; // eax@5
  PStringBase<unsigned short> *v7; // eax@8
  int v8; // eax@13
  UIElement *v9; // eax@13
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@8
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@8
  StringInfo siError; // [sp+10h] [bp-90h]@8

  v2 = this;
  v3 = VendorSellUI::DragItemAcceptable(this, _itemID, 0);
  if ( !v3 )
    return v3;
  v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  if ( !v4 )
    return 0;
  v5 = 0;
  if ( GenItemHolder::splitSize == GenItemHolder::maxSplitSize )
  {
    ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v4, 0);
    goto LABEL_12;
  }
  if ( SmartBox::smartbox )
    v6 = SmartBox::smartbox->player_id;
  else
    v6 = 0;
  if ( !ItemHolder::AttemptToPlaceInContainer(_itemID, v6, (unsigned int)v4[15].vfptr, 0, 0) )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot split the stack to sell it");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  v2->m_splitItem = 0;
  v5 = 1;
  v2->m_splitItemClassID.id = v4[13].id;
  v2->m_splitItemStackSize = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v4);
  v7 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    &errorText,
    0,
    L"Splitting the %s before selling them",
    v7->m_charbuffer);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  StringInfo::StringInfo(&siError);
  StringInfo::SetLiteralValue(&siError, &errorText, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  StringInfo::~StringInfo(&siError);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
LABEL_12:
  VendorSellUI::AddItemToSell(v2, _itemID);
  if ( v5 )
  {
    v8 = UIElement_ItemList::GetNumUIItems(v2->m_sellShopList);
    v9 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_sellShopList->vfptr, v8 - 1);
    if ( v9 )
    {
      v2->m_splitItem = (UIElement_UIItem *)v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)268435506);
      return 1;
    }
    v2->m_splitItem = 0;
  }
  return 1;
}

//----- (004C50D0) --------------------------------------------------------  // acclient.c:246933
void __thiscall gmVendorUI::HandleButtonClicks(gmVendorUI *this, unsigned int _elementID)
{
  gmVendorUI *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@8
  ACCWeenieObject *v4; // edi@8
  unsigned int v5; // eax@9
  int v6; // eax@11
  HashBaseData<unsigned long> *v7; // eax@13
  bool v8; // cl@13
  HashBaseData<unsigned long> *v9; // eax@18
  bool v10; // bl@18
  VendorBuyUI *v11; // eax@22
  unsigned int v12; // eax@28
  HashBaseData<unsigned long> *v13; // ebp@28
  HashBaseData<unsigned long>Vtbl *v14; // edi@28
  int v15; // eax@28
  unsigned int v16; // edi@29
  int v17; // eax@29
  IDClass<_tagDataID,32,0> *v18; // eax@32
  PackableList<ItemProfile> *v19; // edi@35
  unsigned int v20; // edi@36
  VendorProfile *v21; // ecx@39
  unsigned int v22; // ebx@39
  ClientUISystem *v23; // eax@39
  unsigned int itemCount; // [sp+8h] [bp-130h]@6
  int v25; // [sp+Ch] [bp-12Ch]@6
  PStringBase<unsigned short> v26; // [sp+10h] [bp-128h]@27
  IDClass<_tagDataID,32,0> trade_id; // [sp+14h] [bp-124h]@1
  PStringBase<unsigned short> v28; // [sp+18h] [bp-120h]@33
  PStringBase<unsigned short> v29; // [sp+1Ch] [bp-11Ch]@24
  PStringBase<unsigned short> _value; // [sp+20h] [bp-118h]@6
  unsigned int containerCount; // [sp+24h] [bp-114h]@28
  IDClass<_tagDataID,32,0> v32; // [sp+28h] [bp-110h]@39
  IDClass<_tagDataID,32,0> result; // [sp+2Ch] [bp-10Ch]@32
  StringInfo siError; // [sp+30h] [bp-108h]@6
  PropertyCollection pc; // [sp+C0h] [bp-78h]@6

  v2 = this;
  VendorProfile::VendorTradeCurrency(this->shopVendorProfile, &trade_id);
  switch ( _elementID )
  {
    case 0x100000D6u:
      if ( v2->m_buyList.head || v2->m_sellList.head )
      {
        if ( !gmVendorUI::m_curDialogContext )
        {
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &_value,
            L"You have not completed all transactions. Are you sure you want to leave this vendor?");
          StringInfo::SetLiteralValue(&siError, &_value, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
          PropertyCollection::PropertyCollection(&pc);
          itemCount = 0;
          v25 = 0;
          BaseProperty::SetPropertyName((BaseProperty *)&itemCount, 0x8Eu);
          BaseProperty::SetEnum((BaseProperty *)&itemCount, 1u);
          PropertyCollection::AddProperty(&pc, (BaseProperty *)&itemCount);
          BaseProperty::SetPropertyName((BaseProperty *)&itemCount, 0xC5u);
          BaseProperty::SetStringInfo((BaseProperty *)&itemCount, &siError);
          PropertyCollection::AddProperty(&pc, (BaseProperty *)&itemCount);
          gmVendorUI::m_curDialogContext = DialogFactory::MakeCallbackDialogInCurrentUI(
                                             &pc,
                                             gmVendorUI::CloseVendorDialogCallback);
          BaseProperty::~BaseProperty((BaseProperty *)&itemCount);
          PropertyCollection::~PropertyCollection(&pc);
          StringInfo::~StringInfo(&siError);
        }
      }
      else
      {
        v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
      }
      return;
    case 0x100000C2u:
      gmVendorUI::BuySingleItem(v2, ACCWeenieObject::selectedID);
      return;
    case 0x100000C3u:
      v3 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      v4 = (ACCWeenieObject *)v3;
      if ( v3 )
      {
        v5 = v3[20].id;
        if ( v5 && v5 > 1 )
        {
          v6 = ItemHolder::GetObjectSplitSize(v4);
          VendorItemsUI::AddToBuyList(v2->m_itemsUI, v4, v6);
        }
        else
        {
          VendorItemsUI::AddToBuyList(v2->m_itemsUI, v4, 1);
        }
      }
      return;
    case 0x100000CBu:
      v7 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      v8 = 0;
      if ( v7 )
        v8 = v7[21].vfptr > (HashBaseData<unsigned long>Vtbl *)1;
      gmVendorUI::RemoveProfileFromList(&v2->m_buyList, ACCWeenieObject::selectedID, 2 * (v8 == 0) - 1);
      goto LABEL_16;
    case 0x100000CCu:
      PackableList<ItemProfile>::Flush(&v2->m_buyList);
      VendorBuyUI::Update(v2->m_buyUI);
      return;
    case 0x100000C9u:
      v9 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      v10 = 0;
      if ( v9 )
        v10 = v9[21].vfptr > (HashBaseData<unsigned long>Vtbl *)1;
      if ( !gmVendorUI::BuySingleItem(v2, ACCWeenieObject::selectedID) )
        return;
      gmVendorUI::RemoveProfileFromList(&v2->m_buyList, ACCWeenieObject::selectedID, 2 * (v10 == 0) - 1);
      goto LABEL_16;
    case 0x100000CAu:
      v11 = v2->m_buyUI;
      if ( trade_id.id == stru_83F540.id )
      {
        if ( v11->m_transactionValue > v2->m_totalValue )
        {
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v26, L"You don't have enough money");
          StringInfo::SetLiteralValue(&siError, &v26, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v26);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          StringInfo::~StringInfo(&siError);
          return;
        }
      }
      else if ( v11->m_transactionValue > v2->shopVendorProfile->trade_num - v2->m_last_sale )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v29, L"You don't have enough money");
        StringInfo::SetLiteralValue(&siError, &v29, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v29);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_25:
        StringInfo::~StringInfo(&siError);
        return;
      }
      gmVendorUI::RecordContents(v11->m_buyShopList, &v2->m_buyList, 1, 1);
      gmVendorUI::InqListSlotCount(&v2->m_buyList, &itemCount, &containerCount);
      v12 = GetPlayerID();
      v13 = ClientObjMaintSystem::GetWeenieObject(v12);
      v14 = v13[17].vfptr;
      v15 = ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v13);
      if ( containerCount > (unsigned int)((char *)v14 - v15)
        || (v16 = v13[16].id, v17 = ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v13), itemCount > v16 - v17) )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v28,
          L"You must empty some slots in your backpack first");
        StringInfo::SetLiteralValue(&siError, &v28, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v28);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        goto LABEL_25;
      }
      if ( trade_id.id != stru_83F540.id )
        v2->m_last_sale = v2->m_buyUI->m_transactionValue;
      v18 = VendorProfile::VendorTradeCurrency(v2->shopVendorProfile, &result);
      gmVendorUI::SendShopEvent(v2->shopVendorID, &v2->m_buyList, (IDClass<_tagDataID,32,0>)v18->id, 0);
      PackableList<ItemProfile>::Flush(&v2->m_buyList);
LABEL_16:
      VendorBuyUI::Update(v2->m_buyUI);
      return;
    case 0x100000D4u:
      gmVendorUI::VendorItemSetSellState(ACCWeenieObject::selectedID, 0);
      gmVendorUI::RemoveProfileFromList(&v2->m_sellList, ACCWeenieObject::selectedID, -1);
      goto LABEL_41;
    case 0x100000D5u:
      v19 = &v2->m_sellList;
      goto LABEL_40;
    case 0x100000D2u:
      v20 = ACCWeenieObject::selectedID;
      if ( !gmVendorUI::SellSingleItem(v2, ACCWeenieObject::selectedID) )
        return;
      gmVendorUI::VendorItemSetSellState(v20, 0);
      gmVendorUI::RemoveProfileFromList(&v2->m_sellList, v20, -1);
      goto LABEL_41;
    case 0x100000D3u:
      v19 = &v2->m_sellList;
      if ( !gmVendorUI::RecordContents(v2->m_sellUI->m_sellShopList, &v2->m_sellList, 1, 1) )
      {
        v21 = v2->shopVendorProfile;
        v2->m_last_sale = 0;
        VendorProfile::VendorTradeCurrency(v21, &v32);
        v22 = v2->shopVendorID;
        CM_Vendor::Event_Sell(v2->shopVendorID, &v2->m_sellList);
        ACCWeenieObject::RecordRequest(v22, IR_SHOP_EVENT);
        v23 = ClientUISystem::GetUISystem();
        ClientUISystem::IncrementBusyCount(v23);
LABEL_40:
        gmVendorUI::FlushSellListSellState(v19);
        PackableList<ItemProfile>::Flush(v19);
LABEL_41:
        VendorSellUI::Update(v2->m_sellUI);
      }
      return;
    default:
      return;
  }
}

//----- (004C5680) --------------------------------------------------------  // acclient.c:247138
void __thiscall gmVendorUI::HandleDropRelease(gmVendorUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  UIElement *v4; // eax@1
  gmVendorUI *v5; // edi@1
  DropItemFlags dropFlags; // [sp+8h] [bp-8h]@4
  unsigned int dropSpellID; // [sp+Ch] [bp-4h]@4

  v2 = i_rMsg->dwParam1;
  v3 = *(UIElement **)(v2 + 8);
  v4 = *(UIElement **)(v2 + 16);
  v5 = this;
  if ( v3 )
  {
    if ( v4 )
    {
      if ( UIElement::IsAncestorOfMe(v4, (UIElement *)&this->m_sellUI->m_sellShopList->vfptr) )
      {
        UIElement_ItemList::InqDropIconInfo(v3, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
        if ( i_rMsg )
        {
          if ( !(dropFlags & 0xE) )
            VendorSellUI::AcceptDragObject(v5->m_sellUI, (unsigned int)i_rMsg);
        }
      }
    }
  }
}

//----- (004C56F0) --------------------------------------------------------  // acclient.c:247169
void __thiscall gmVendorUI::RecvNotice_OpenVendor(gmVendorUI *this, unsigned int i_vendorID, VendorProfile *i_vendorProfile, PackableList<ItemProfile> *i_itemProfileList, ShopMode i_startMode)
{
  gmVendorUI::OpenVendor(
    (gmVendorUI *)((char *)this - 1528),
    i_vendorID,
    i_vendorProfile,
    i_itemProfileList,
    i_startMode);
}

//----- (004C5700) --------------------------------------------------------  // acclient.c:247180
int __thiscall gmVendorUI::ListenToElementMessage(gmVendorUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  UIElement_Panel *v5; // eax@11
  int v6; // eax@12
  int v7; // eax@13

  v2 = i_rMsg->idMessage;
  v3 = (UIElement *)this;
  if ( v2 == 28 )
  {
    if ( this->m_itemsUI )
    {
      gmVendorUI::HandleMousePresses(this, i_rMsg);
      return UIElement::ListenToElementMessage(v3, i_rMsg);
    }
  }
  else
  {
    if ( v2 == 1 )
    {
      gmVendorUI::HandleButtonClicks(this, i_rMsg->idElement);
      return UIElement::ListenToElementMessage(v3, i_rMsg);
    }
    if ( v2 == 7 )
    {
      if ( i_rMsg->idElement == 268435647 )
      {
        VendorItemsUI::UpdateItemsList(this->m_itemsUI, 0, 1);
        return UIElement::ListenToElementMessage(v3, i_rMsg);
      }
    }
    else if ( v2 != 44 || i_rMsg->idElement != 268435640 )
    {
      if ( v2 == 21 )
        gmVendorUI::HandleDropRelease(this, i_rMsg);
    }
    else
    {
      v5 = this->m_vendorPanel;
      if ( v5 )
      {
        v6 = v5->m_OpenPageToken - 268435644;
        if ( !v6 )
        {
          VendorItemsUI::UpdateItemsList(this->m_itemsUI, 0, 0);
          return UIElement::ListenToElementMessage(v3, i_rMsg);
        }
        v7 = v6 - 8;
        if ( !v7 )
        {
          VendorBuyUI::Update(this->m_buyUI);
          return UIElement::ListenToElementMessage(v3, i_rMsg);
        }
        if ( v7 == 9 )
        {
          VendorSellUI::Update(this->m_sellUI);
          return UIElement::ListenToElementMessage(v3, i_rMsg);
        }
      }
    }
  }
  return UIElement::ListenToElementMessage(v3, i_rMsg);
}

//----- (006F27D0) --------------------------------------------------------  // acclient.c:774935
void _E91_86()
{
  outside_val_78 = 1000.0 + 1.0;
}

//----- (006F27F0) --------------------------------------------------------  // acclient.c:774941
void _E93_62()
{
  block_length_78 = 24.0 * 8.0;
}

//----- (006F2810) --------------------------------------------------------  // acclient.c:774947
void _E95_62()
{
  half_square_length_78 = 24.0 * 0.5;
}

//----- (006F2830) --------------------------------------------------------  // acclient.c:774953
int _E97_87()
{
  return atexit(nullsub_761);
}

//----- (006F2840) --------------------------------------------------------  // acclient.c:774959
int _E100_80()
{
  return atexit(nullsub_762);
}

//----- (006F2850) --------------------------------------------------------  // acclient.c:774965
int _E103_72()
{
  return atexit(_E104_87);
}

//----- (006F2860) --------------------------------------------------------  // acclient.c:774971
void _E109_34()
{
  DEFAULT_VIEW_RADIUS_47 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2880) --------------------------------------------------------  // acclient.c:774977
void _E111_23()
{
  MIN_QUANTUM_47 = 1.0 / 30.0;
}

//----- (006F28A0) --------------------------------------------------------  // acclient.c:774983
void _E113_11()
{
  MAX_QUANTUM_47 = 1.0 / 5.0;
}

//----- (006F28C0) --------------------------------------------------------  // acclient.c:774989
void _E115_37()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_82, PFID_A8R8G8B8);
}

//----- (006F28D0) --------------------------------------------------------  // acclient.c:774995
void _E118_42()
{
  LOWEST_DATA_RATE_84 = 1024;
}

//----- (006F28E0) --------------------------------------------------------  // acclient.c:775001
void _E120_30()
{
  HIGHEST_DATA_RATE_84 = 0x7FFF;
}

//----- (006F28F0) --------------------------------------------------------  // acclient.c:775007
int _E122_16()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_84;
  INITIAL_MAX_DATA_RATE_32 = LOWEST_DATA_RATE_84;
  return result;
}

//----- (006F2900) --------------------------------------------------------  // acclient.c:775017
int _E124_39()
{
  return atexit(_E125_45);
}

//----- (006F2910) --------------------------------------------------------  // acclient.c:775023
int _E127_34()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_32, "Misc.TooltipEnable");
  return atexit(_E128_45);
}

//----- (006F2930) --------------------------------------------------------  // acclient.c:775030
int _E130_28()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_32, "Misc.TooltipDelay");
  return atexit(_E131_35);
}

//----- (006F2950) --------------------------------------------------------  // acclient.c:775037
int sub_6F2950()
{
  return atexit(nullsub_760);
}

//----- (007614C0) --------------------------------------------------------  // acclient.c:888751
void __cdecl _E128_45()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007614F0) --------------------------------------------------------  // acclient.c:888764
void __cdecl _E131_35()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

