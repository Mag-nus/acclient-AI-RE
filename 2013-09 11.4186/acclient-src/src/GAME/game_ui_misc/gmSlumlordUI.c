/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSlumlordUI
   Object     : GAME\game_ui_misc\gmSlumlordUI.obj
   Functions  : 55
   Addresses  : 004C7C70 - 006F2C30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C7C70) --------------------------------------------------------  // acclient.c:249369
void __thiscall gmSlumlordUI::OnVisibilityChanged(gmSlumlordUI *this, bool i_bVisible)
{
  gmSlumlordUI *v2; // esi@1
  CPlayerSystem *v3; // eax@3

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( !i_bVisible )
    {
      v3 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::UnregisterAllObjectRangeHandlers(v3, (ObjectRangeHandler *)&v2->vfptr);
    }
  }
}

//----- (004C7CB0) --------------------------------------------------------  // acclient.c:249387
void __thiscall gmSlumlordUI::OnObjectRangeExit(gmSlumlordUI *this, unsigned int _objectID)
{
  if ( (IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *)_objectID == this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14],
      0);
}

//----- (004C7CE0) --------------------------------------------------------  // acclient.c:249396
char __thiscall gmSlumlordUI::BackupHouseProfile(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  int v2; // eax@1
  int v3; // ecx@2
  HouseProfile *v4; // eax@3
  HouseProfile *v5; // eax@4

  v1 = this;
  v2 = (int)this->m_pHouseProfile;
  if ( !v2 )
    return 0;
  v3 = (int)this->m_pBackupHouseProfile;
  if ( v3 )
  {
    HouseProfile::operator=(v3, v2);
  }
  else
  {
    v4 = (HouseProfile *)operator new(0x4Cu);
    if ( v4 )
      HouseProfile::HouseProfile(v4, v1->m_pHouseProfile);
    else
      v5 = 0;
    v1->m_pBackupHouseProfile = v5;
    if ( !v5 )
      return 0;
  }
  return 1;
}

//----- (004C7D30) --------------------------------------------------------  // acclient.c:249428
bool __thiscall gmSlumlordUI::AmIHouseOwner(gmSlumlordUI *this)
{
  HouseProfile *v1; // ecx@1
  bool result; // al@3

  v1 = this->m_pHouseProfile;
  if ( v1 )
  {
    if ( SmartBox::smartbox )
      result = v1->_owner == SmartBox::smartbox->player_id;
    else
      result = v1->_owner == 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C7D60) --------------------------------------------------------  // acclient.c:249449
bool __thiscall gmSlumlordUI::IsPaymentAllowed(gmSlumlordUI *this)
{
  HouseProfile *v1; // eax@1
  __int32 v2; // ecx@2
  bool result; // al@4

  v1 = this->m_pHouseProfile;
  if ( !v1 )
    return 0;
  v2 = this->m_eCurrentHouseOp - 1;
  if ( v2 )
  {
    if ( v2 != 1 )
      return 0;
    result = v1->_owner != 0;
  }
  else
  {
    result = v1->_owner == 0;
  }
  return result;
}

//----- (004C7D90) --------------------------------------------------------  // acclient.c:249473
bool __thiscall gmSlumlordUI::AddPayment(gmSlumlordUI *this, HousePayment *pay)
{
  gmSlumlordUI *v2; // eax@1
  HouseProfile *v3; // ecx@1
  bool result; // al@2

  v2 = this;
  v3 = this->m_pHouseProfile;
  if ( v3 )
    result = HouseProfile::Pay(v3, v2->m_eCurrentHouseOp, pay) != 0;
  else
    result = 0;
  return result;
}

//----- (004C7DC0) --------------------------------------------------------  // acclient.c:249489
bool __thiscall gmSlumlordUI::NeedsMore(gmSlumlordUI *this, IDClass<_tagDataID,32,0> wcid)
{
  gmSlumlordUI *v2; // eax@1
  HouseProfile *v3; // ecx@1
  bool result; // al@2

  v2 = this;
  v3 = this->m_pHouseProfile;
  if ( v3 )
    result = HouseProfile::NeedsMore(v3, v2->m_eCurrentHouseOp, wcid) != 0;
  else
    result = 0;
  return result;
}

//----- (004C7DF0) --------------------------------------------------------  // acclient.c:249505
void __userpurge gmSlumlordUI::gmSlumlordUI(gmSlumlordUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSlumlordUI *v4; // esi@1

  v4 = this;
  UIElement_Panel::UIElement_Panel((UIElement_Panel *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->m_iidOwner = 0;
  v4->m_pHouseProfile = 0;
  v4->m_pBackupHouseProfile = 0;
  v4->m_eCurrentHouseOp = 0;
  v4->m_pCurItemList = 0;
  v4->m_pBuyRequirementsText = 0;
  v4->m_pBuyHouseOwnerText = 0;
  v4->m_pBuyItemList = 0;
  v4->m_pBuyButton = 0;
  v4->m_pRentRequirementsText = 0;
  v4->m_pRentHouseOwnerText = 0;
  v4->m_pRentItemList = 0;
  v4->m_pRentButton = 0;
  v4->m_uiHousePurchaseDialogContext = 0;
  v4->m_uiRentPaymentByProxyDialogContext = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSlumlordUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSlumlordUI::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&gmSlumlordUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmSlumlordUI::vftable;
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7B6754: using guessed type bool (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B6758: using guessed type void (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, unsigned __int32);
// 7B6760: using guessed type bool (__thiscall *gmSlumlordUI::vftable)(DBCache *this);
// 7B6A08: using guessed type int (__thiscall *gmSlumlordUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C7EB0) --------------------------------------------------------  // acclient.c:249543
gmSlumlordUI *__thiscall gmSlumlordUI::DynamicCast(gmSlumlordUI *this, unsigned int i_eType)
{
  gmSlumlordUI *result; // eax@1

  result = this;
  if ( i_eType != 268435475 )
    result = (gmSlumlordUI *)(i_eType != 8 ? 0 : (unsigned int)this);
  return result;
}

//----- (004C7ED0) --------------------------------------------------------  // acclient.c:249554
signed int gmSlumlordUI::GetUIElementType()
{
  return 268435475;
}

//----- (004C7EE0) --------------------------------------------------------  // acclient.c:249560
void __thiscall gmSlumlordUI::~gmSlumlordUI(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  ObjectRangeHandler *v3; // ST04_4@1
  CPlayerSystem *v4; // eax@1
  UIElement_ItemList *v5; // ecx@1
  UIElement_ItemList *v6; // ecx@3
  GlobalEventHandler *v7; // eax@5

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (ObjectRangeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSlumlordUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSlumlordUI::vftable;
  this->vfptr = (ObjectRangeHandlerVtbl *)&gmSlumlordUI::vftable;
  this->vfptr = (ItemListDragHandlerVtbl *)&gmSlumlordUI::vftable;
  v4 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UnregisterAllObjectRangeHandlers(v4, v3);
  v5 = v1->m_pBuyItemList;
  if ( v5 )
    UIElement_ItemList::UnregisterItemListDragHandler(v5);
  v6 = v1->m_pRentItemList;
  if ( v6 )
    UIElement_ItemList::UnregisterItemListDragHandler(v6);
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v7 )
    v7->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v7, v2);
  DialogFactory::CloseDialog(v1->m_uiHousePurchaseDialogContext);
  v1->m_uiHousePurchaseDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_uiRentPaymentByProxyDialogContext);
  v1->m_uiRentPaymentByProxyDialogContext = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Panel::~UIElement_Panel((UIElement_Panel *)&v1->vfptr);
}
// 7B6754: using guessed type bool (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B6758: using guessed type void (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, unsigned __int32);
// 7B6760: using guessed type bool (__thiscall *gmSlumlordUI::vftable)(DBCache *this);
// 7B6A08: using guessed type int (__thiscall *gmSlumlordUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C7F90) --------------------------------------------------------  // acclient.c:249603
void __usercall gmSlumlordUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSlumlordUI *v3; // eax@1

  v3 = (gmSlumlordUI *)operator new(0x728u);
  if ( v3 )
    gmSlumlordUI::gmSlumlordUI(v3, a1, _layout, _full_desc);
}

//----- (004C7FC0) --------------------------------------------------------  // acclient.c:249613
void __thiscall gmSlumlordUI::RecvNotice_FailedHouseTransaction(gmSlumlordUI *this, unsigned int i_eType)
{
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] )
    CM_House::Event_QueryLord((unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0]);
}

//----- (004C7FE0) --------------------------------------------------------  // acclient.c:249620
void __thiscall gmSlumlordUI::UpdateButtons(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  HouseProfile *v2; // ecx@4

  v1 = this;
  if ( this->m_eCurrentHouseOp == Undef_HouseOp )
  {
    ((void (__stdcall *)(_DWORD))this->m_pBuyButton->vfptr[13].__vecDelDtor)(13);
LABEL_3:
    ((void (__stdcall *)(signed int))v1->m_pRentButton->vfptr[13].__vecDelDtor)(13);
    return;
  }
  v2 = this->m_pHouseProfile;
  if ( v2 && v2->_owner == 0 && v2 && HouseProfile::IsPaidInFull(v2, Buy_House) != 0 )
    ((void (__stdcall *)(signed int))v1->m_pBuyButton->vfptr[13].__vecDelDtor)(1);
  else
    ((void (__stdcall *)(signed int))v1->m_pBuyButton->vfptr[13].__vecDelDtor)(13);
  if ( UIElement_ItemList::GetNumUIItems(v1->m_pRentItemList) <= 0 )
    goto LABEL_3;
  ((void (__stdcall *)(signed int))v1->m_pRentButton->vfptr[13].__vecDelDtor)(1);
}

//----- (004C8080) --------------------------------------------------------  // acclient.c:249644
void __thiscall gmSlumlordUI::CleanItemLists(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  HouseProfile *v2; // esi@1

  v1 = this;
  gmSalvageUI::ClearAllTradeStates(this->m_pBuyItemList);
  UIElement_ItemList::ItemList_Flush(v1->m_pBuyItemList);
  ((void (__stdcall *)(signed int))v1->m_pBuyButton->vfptr[13].__vecDelDtor)(13);
  gmSalvageUI::ClearAllTradeStates(v1->m_pRentItemList);
  UIElement_ItemList::ItemList_Flush(v1->m_pRentItemList);
  ((void (__stdcall *)(signed int))v1->m_pRentButton->vfptr[13].__vecDelDtor)(13);
  v2 = v1->m_pHouseProfile;
  if ( v2 )
  {
    HousePaymentList::ClearPayment(&v2->_buy);
    HousePaymentList::ClearPayment(&v2->_rent);
  }
}

//----- (004C80F0) --------------------------------------------------------  // acclient.c:249665
char __thiscall gmSlumlordUI::AddItem(gmSlumlordUI *this, ACCWeenieObject *i_pItem)
{
  gmSlumlordUI *v2; // edi@1
  UIElement_ItemList *v3; // ecx@3
  HousePayment payment; // [sp+8h] [bp-18h]@5

  v2 = this;
  if ( !i_pItem )
    return 0;
  if ( ACCWeenieObject::GetNumContainedItems(i_pItem) > 0 )
    return 0;
  v3 = v2->m_pCurItemList;
  if ( !v3 || UIElement_ItemList::ItemList_IsInList(v3, i_pItem->id) )
    return 0;
  HousePayment::HousePayment(&payment);
  payment.wcid.id = i_pItem->pwd._wcid.id;
  payment.num = ACCWeenieObject::GetHousePayment(i_pItem);
  if ( !gmSlumlordUI::AddPayment(v2, &payment) )
  {
    HousePayment::~HousePayment(&payment);
    return 0;
  }
  ACCWeenieObject::SetTradeState(i_pItem, 1);
  UIElement_ItemList::ItemList_AddItem(v2->m_pCurItemList, i_pItem->id);
  i_pItem->vfptr->RegisterNoticeHandler((NoticeRegistrar *)&i_pItem->vfptr, 100015u, (NoticeHandler *)&v2->vfptr);
  HousePayment::~HousePayment(&payment);
  return 1;
}

//----- (004C81B0) --------------------------------------------------------  // acclient.c:249695
void __thiscall gmSlumlordUI::RemoveItem(gmSlumlordUI *this, ACCWeenieObject *i_pItem)
{
  gmSlumlordUI *v2; // esi@1
  UIElement_ItemList *v3; // ecx@1
  int v4; // ebp@3
  unsigned int v5; // ebx@3
  UIElement *v6; // eax@4
  int v7; // eax@5
  int v8; // eax@9
  HouseProfile *v9; // ecx@9
  HousePayment payment; // [sp+8h] [bp-18h]@9

  v2 = this;
  v3 = this->m_pCurItemList;
  if ( v3 )
  {
    if ( i_pItem )
    {
      v4 = UIElement_ItemList::GetNumUIItems(v3);
      v5 = 0;
      if ( v4 > 0 )
      {
        while ( 1 )
        {
          v6 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_pCurItemList->vfptr, v5);
          if ( v6 )
          {
            v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
            if ( v7 )
            {
              if ( *(_DWORD *)(v7 + 1532) == i_pItem->id )
                break;
            }
          }
          ++v5;
          if ( (signed int)v5 >= v4 )
            return;
        }
        ACCWeenieObject::SetTradeState(i_pItem, 0);
        i_pItem->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)&i_pItem->vfptr, (NoticeHandler *)&v2->vfptr);
        UIElement_ItemList::ItemList_DeleteItem(v2->m_pCurItemList, i_pItem->id);
        HousePayment::HousePayment(&payment);
        payment.wcid.id = i_pItem->pwd._wcid.id;
        v8 = ACCWeenieObject::GetHousePayment(i_pItem);
        v9 = v2->m_pHouseProfile;
        payment.num = v8;
        if ( v9 )
          HouseProfile::RemovePayment(v9, v2->m_eCurrentHouseOp, &payment);
        HousePayment::~HousePayment(&payment);
      }
    }
  }
}

//----- (004C82A0) --------------------------------------------------------  // acclient.c:249750
gmSlumlordUI *__thiscall gmSlumlordUI::scalar_deleting_destructor(gmSlumlordUI *this, unsigned int a2)
{
  gmSlumlordUI *v2; // esi@1

  v2 = this;
  gmSlumlordUI::~gmSlumlordUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004C82C0) --------------------------------------------------------  // acclient.c:249762
void __thiscall gmSlumlordUI::PostInit(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@6
  int v5; // eax@9
  int v6; // eax@12
  int v7; // eax@15
  UIElement *v8; // eax@18
  int v9; // eax@19
  UIElement *v10; // eax@21
  int v11; // eax@22
  UIElement *v12; // eax@24
  UIElement_ItemList *v13; // eax@25
  UIElement *v14; // eax@29
  int v15; // eax@30
  UIElement *v16; // eax@32
  int v17; // eax@33
  UIElement *v18; // eax@35
  int v19; // eax@36
  UIElement *v20; // eax@38
  UIElement_ItemList *v21; // eax@39
  UIElement *v22; // eax@43
  int v23; // eax@44

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)byte_4DD229, (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&byte_4DD226, (NoticeHandler *)v4);
    if ( v1 )
      v5 = (int)&v1->vfptr;
    else
      v5 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100118u, (NoticeHandler *)v5);
    if ( v1 )
      v6 = (int)&v1->vfptr;
    else
      v6 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100008u, (NoticeHandler *)v6);
    if ( v1 )
      v7 = (int)&v1->vfptr;
    else
      v7 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, (NoticeHandler *)v7);
  }
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000091u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_pBuyRequirementsText = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000093u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pBuyHouseOwnerText = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000095u);
  if ( v12 )
    v13 = (UIElement_ItemList *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)268435505);
  else
    v13 = 0;
  v1->m_pBuyItemList = v13;
  if ( v13 )
    UIElement_ItemList::RegisterItemListDragHandler(v13, (ItemListDragHandler *)&v1->vfptr);
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000094u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)1);
  else
    v15 = 0;
  v1->m_pBuyButton = (UIElement_Button *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000098u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)12);
  else
    v17 = 0;
  v1->m_pRentRequirementsText = (UIElement_Text *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000009Au);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)12);
  else
    v19 = 0;
  v1->m_pRentHouseOwnerText = (UIElement_Text *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000009Cu);
  if ( v20 )
    v21 = (UIElement_ItemList *)v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)268435505);
  else
    v21 = 0;
  v1->m_pRentItemList = v21;
  if ( v21 )
    UIElement_ItemList::RegisterItemListDragHandler(v21, (ItemListDragHandler *)&v1->vfptr);
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000009Bu);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)1);
  else
    v23 = 0;
  v1->m_pRentButton = (UIElement_Button *)v23;
  gmSlumlordUI::CleanItemLists(v1);
  gmSlumlordUI::UpdateButtons(v1);
}
// 4DD226: using guessed type char byte_4DD226;

//----- (004C84D0) --------------------------------------------------------  // acclient.c:249877
void __cdecl gmSlumlordUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000013u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSlumlordUI::Create);
}

//----- (004C84F0) --------------------------------------------------------  // acclient.c:249885
void __thiscall gmSlumlordUI::RecvNotice_ItemListBeginDrag(gmSlumlordUI *this, UIElement *i_itemList, int i_slotNum)
{
  gmSlumlordUI *v3; // esi@1
  UIElement_ListBox *v4; // ecx@1
  UIElement *v5; // eax@2
  int v6; // eax@3
  unsigned int v7; // eax@4
  HashBaseData<unsigned long> *v8; // eax@5
  gmSlumlordUI *v9; // esi@5

  v3 = this;
  v4 = (UIElement_ListBox *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  if ( (UIElement *)v4 == i_itemList )
  {
    v5 = UIElement_ListBox::GetItem(v4, i_slotNum);
    if ( v5 )
    {
      v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 1532);
        if ( v7 )
        {
          v8 = ClientObjMaintSystem::GetWeenieObject(v7);
          v9 = (gmSlumlordUI *)((char *)v3 - 1760);
          gmSlumlordUI::RemoveItem(v9, (ACCWeenieObject *)v8);
          gmSlumlordUI::UpdateButtons(v9);
        }
      }
    }
  }
}

//----- (004C8550) --------------------------------------------------------  // acclient.c:249919
void __thiscall gmSlumlordUI::RecvNotice_ServerSaysMoveItem(gmSlumlordUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmSlumlordUI *v9; // edi@1
  UIElement_ItemList *v10; // ecx@1
  HashBaseData<unsigned long> *v11; // eax@3
  ACCWeenieObject *v12; // esi@3
  gmSlumlordUI *v13; // edi@5

  v9 = this;
  v10 = (UIElement_ItemList *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  if ( v10 )
  {
    if ( UIElement_ItemList::ItemList_GetItem(v10, _itemID) )
    {
      v11 = ClientObjMaintSystem::GetWeenieObject(_itemID);
      v12 = (ACCWeenieObject *)v11;
      if ( v11 )
      {
        if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v11) )
        {
          v13 = (gmSlumlordUI *)((char *)v9 - 1760);
          gmSlumlordUI::RemoveItem(v13, v12);
          gmSlumlordUI::UpdateButtons(v13);
        }
      }
    }
  }
}

//----- (004C85A0) --------------------------------------------------------  // acclient.c:249949
void __thiscall gmSlumlordUI::RecvNotice_BeingDeleted(gmSlumlordUI *this, CWeenieObject *i_obj)
{
  gmSlumlordUI::RemoveItem((gmSlumlordUI *)((char *)this - 1760), (ACCWeenieObject *)i_obj);
}

//----- (004C85B0) --------------------------------------------------------  // acclient.c:249955
char __thiscall gmSlumlordUI::AddObject(gmSlumlordUI *this, ACCWeenieObject *i_pObject)
{
  gmSlumlordUI *v2; // edi@1
  char result; // al@2

  v2 = this;
  if ( i_pObject )
  {
    if ( ACCWeenieObject::GetNumContainedItems(i_pObject) )
      result = gmSlumlordUI::AddContainer(v2, i_pObject);
    else
      result = gmSlumlordUI::AddItem(v2, i_pObject);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C85F0) --------------------------------------------------------  // acclient.c:249976
bool __thiscall gmSlumlordUI::DragItemAcceptable(gmSlumlordUI *this, unsigned int i_iidItem, bool _silent)
{
  gmSlumlordUI *v3; // edi@1
  bool result; // al@2
  HashBaseData<unsigned long> *v5; // eax@3
  HashBaseData<unsigned long> *v6; // esi@3
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@6
  StringInfo siError; // [sp+8h] [bp-90h]@6

  v3 = this;
  if ( !this->m_pCurItemList )
    return 0;
  v5 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v5) )
  {
    if ( !_silent )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can only trade items you are carrying");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
    }
    return 0;
  }
  if ( UIElement_ItemList::ItemList_IsInList(v3->m_pCurItemList, v6->id) || !gmSlumlordUI::IsPaymentAllowed(v3) )
    return 0;
  if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v6) <= 0 )
    result = gmSlumlordUI::NeedsMore(v3, (IDClass<_tagDataID,32,0>)v6[13].id);
  else
    result = 1;
  return result;
}

//----- (004C86E0) --------------------------------------------------------  // acclient.c:250015
char __thiscall gmSlumlordUI::AddContainer(gmSlumlordUI *this, ACCWeenieObject *i_pContainer)
{
  gmSlumlordUI *v2; // ebx@1
  IDList *v3; // eax@3
  IDList *v4; // esi@3
  int v5; // edi@4
  unsigned int v6; // eax@5
  unsigned int v7; // eax@6
  HashBaseData<unsigned long> *v8; // eax@6
  char result; // al@10

  v2 = this;
  if ( i_pContainer
    && ACCWeenieObject::GetNumContainedItems(i_pContainer)
    && (v3 = ACCWeenieObject::GetContainedItemsList(i_pContainer), (v4 = v3) != 0) )
  {
    IDList::SetCurToNum(v3, 0);
    v5 = 0;
    if ( v4->numIDs > 0 )
    {
      while ( 1 )
      {
        v6 = IDList::GetCurID(v4);
        if ( !gmSlumlordUI::DragItemAcceptable(v2, v6, 1) )
          goto LABEL_8;
        v7 = IDList::GetCurID(v4);
        v8 = ClientObjMaintSystem::GetWeenieObject(v7);
        if ( v8 )
          break;
LABEL_9:
        ++v5;
        if ( v5 >= v4->numIDs )
          goto LABEL_10;
      }
      gmSlumlordUI::AddObject(v2, (ACCWeenieObject *)v8);
LABEL_8:
      IDList::SetCurToNext(v4);
      goto LABEL_9;
    }
LABEL_10:
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C8770) --------------------------------------------------------  // acclient.c:250065
char __thiscall gmSlumlordUI::OnItemListDragOver(gmSlumlordUI *this, UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && !(_dropFlags & 0xE) )
  {
    if ( gmSlumlordUI::DragItemAcceptable((gmSlumlordUI *)((char *)this - 1768), _dropItemID, 1) )
    {
      UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
      return 1;
    }
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000041u);
  }
  return 1;
}

//----- (004C87C0) --------------------------------------------------------  // acclient.c:250080
bool __thiscall gmSlumlordUI::AcceptDragObject(gmSlumlordUI *this, unsigned int i_iidItem)
{
  gmSlumlordUI *v2; // edi@1
  bool v3; // al@1
  HashBaseData<unsigned long> *v4; // esi@2
  unsigned int v5; // eax@5
  PStringBase<unsigned short> *v6; // eax@8
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@8
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@8
  StringInfo siError; // [sp+10h] [bp-90h]@8

  v2 = this;
  v3 = gmSlumlordUI::DragItemAcceptable(this, i_iidItem, 0);
  if ( v3 )
  {
    v4 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
    if ( !v4 )
      return 0;
    if ( GenItemHolder::splitSize != GenItemHolder::maxSplitSize )
    {
      if ( SmartBox::smartbox )
        v5 = SmartBox::smartbox->player_id;
      else
        v5 = 0;
      if ( ItemHolder::AttemptToPlaceInContainer(i_iidItem, v5, (unsigned int)v4[15].vfptr, 0, 0) )
      {
        ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v4);
        v6 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &errorText,
          0,
          L"Splitting the %s before adding to housing panel",
          v6->m_charbuffer);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        return 1;
      }
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot split the stack for dwelling costs");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      return 0;
    }
    ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v4, 0);
    gmSlumlordUI::AddObject(v2, (ACCWeenieObject *)v4);
    gmSlumlordUI::UpdateButtons(v2);
    v3 = 1;
  }
  return v3;
}

//----- (004C8940) --------------------------------------------------------  // acclient.c:250138
char __thiscall gmSlumlordUI::MakePayment(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // edi@1
  HouseOp v2; // eax@1
  UIElement_ItemList *v3; // ecx@3
  int v4; // ebp@5
  unsigned int v5; // esi@5
  UIElement *v6; // eax@6
  int v7; // eax@7
  unsigned int v8; // eax@8
  int v10; // edi@15
  unsigned int iidLord; // [sp+4h] [bp-18h]@4
  unsigned int val; // [sp+8h] [bp-14h]@9
  PackableList<unsigned long> stuff; // [sp+Ch] [bp-10h]@5

  v1 = this;
  v2 = this->m_eCurrentHouseOp;
  if ( v2 != 1 && v2 != 2 )
    return 0;
  v3 = this->m_pCurItemList;
  if ( !v3 )
    return 0;
  iidLord = v1->m_iidOwner;
  if ( !v1->m_iidOwner )
    return 0;
  stuff.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  stuff.head = 0;
  stuff.tail = 0;
  stuff.curNum = 0;
  v4 = UIElement_ItemList::GetNumUIItems(v3);
  v5 = 0;
  if ( v4 > 0 )
  {
    do
    {
      v6 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_pCurItemList->vfptr, v5);
      if ( v6 )
      {
        v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 1532);
          if ( v8 )
          {
            val = v8;
            PackableList<unsigned long>::InsertTail(&stuff, &val);
          }
        }
      }
      ++v5;
    }
    while ( (signed int)v5 < v4 );
  }
  if ( !stuff.head )
  {
    stuff.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
    PackableList<unsigned long>::Flush(&stuff);
    return 0;
  }
  gmSlumlordUI::CleanItemLists(v1);
  gmSlumlordUI::UpdateButtons(v1);
  if ( stuff.head )
  {
    v10 = v1->m_eCurrentHouseOp - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        CM_House::Event_RentHouse(iidLord, &stuff);
    }
    else
    {
      CM_House::Event_BuyHouse(iidLord, &stuff);
    }
  }
  stuff.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(&stuff);
  return 1;
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (004C8A80) --------------------------------------------------------  // acclient.c:250219
void __thiscall gmSlumlordUI::HandleDropRelease(gmSlumlordUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  gmSlumlordUI *v4; // edi@1
  UIElement *v5; // ecx@1
  DropItemFlags dropFlags; // [sp+8h] [bp-8h]@3
  unsigned int dropSpellID; // [sp+Ch] [bp-4h]@3

  v2 = i_rMsg->dwParam1;
  v3 = *(UIElement **)(v2 + 16);
  v4 = this;
  v5 = *(UIElement **)(v2 + 8);
  if ( v5 )
  {
    if ( v3 )
    {
      UIElement_ItemList::InqDropIconInfo(v5, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
      if ( i_rMsg )
      {
        if ( UIElement::IsAncestorOfMe(v3, (UIElement *)&v4->m_pBuyItemList->vfptr) )
        {
          if ( !(dropFlags & 0xE) )
            gmSlumlordUI::AcceptDragObject(v4, (unsigned int)i_rMsg);
        }
        else if ( UIElement::IsAncestorOfMe(v3, (UIElement *)&v4->m_pRentItemList->vfptr) && !(dropFlags & 0xE) )
        {
          gmSlumlordUI::AcceptDragObject(v4, (unsigned int)i_rMsg);
        }
      }
    }
  }
}

//----- (004C8B20) --------------------------------------------------------  // acclient.c:250254
char __thiscall gmSlumlordUI::RefreshHouse(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // esi@1
  PStringBase<unsigned short> *v2; // eax@3
  char *v3; // edi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@6
  PStringBase<unsigned short> *v5; // eax@10
  char *v6; // edi@10
  AC1Legacy::PSRefBuffer<char> *v7; // edi@13
  HouseProfile *v8; // eax@16
  PSRefBufferCharData<unsigned short> *v9; // edi@17
  int v10; // eax@17
  AC1Legacy::PSRefBuffer<char> *v11; // eax@22
  unsigned int v12; // ecx@22
  AC1Legacy::PSRefBuffer<char> *v13; // ebx@25
  PStringBase<unsigned short> *v14; // eax@26
  char *v15; // edi@26
  PStringBase<unsigned short> *v16; // eax@30
  char *v17; // edi@30
  char result; // al@36
  AC1Legacy::PStringBase<char> rent_text; // [sp+10h] [bp-8h]@3
  PStringBase<unsigned short> v20; // [sp+14h] [bp-4h]@3

  v1 = this;
  if ( this->m_pHouseProfile )
  {
    if ( this->m_pBuyRequirementsText )
    {
      rent_text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      HouseProfile::ComposeText(v1->m_pHouseProfile, Buy_House, &rent_text);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, 0, rent_text.m_buffer->m_data);
      UIElement_Text::SetText(v1->m_pBuyRequirementsText, v2);
      v3 = (char *)&v20.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) && v3 )
        (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
      v4 = rent_text.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&rent_text.m_buffer->m_cRef) && v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
    if ( v1->m_pRentRequirementsText )
    {
      rent_text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      HouseProfile::ComposeText2(v1->m_pHouseProfile, Rent_House, &rent_text);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, 0, rent_text.m_buffer->m_data);
      UIElement_Text::SetText(v1->m_pRentRequirementsText, v5);
      v6 = (char *)&v20.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) && v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      v7 = rent_text.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&rent_text.m_buffer->m_cRef) && v7 )
        v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&rent_text, "Owner: ");
    v8 = v1->m_pHouseProfile;
    if ( v8->_name.m_buffer->m_len == 1 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v20, "None");
      v9 = v20.m_charbuffer;
      v10 = *(_DWORD *)&v20.m_charbuffer->m_data[4];
      if ( v10 != 1
        && v20.m_charbuffer != (PSRefBufferCharData<unsigned short> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(&rent_text, (const char *)&v20.m_charbuffer->m_data[10], v10 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v9->m_data[2]) )
        (**(void (__thiscall ***)(PSRefBufferCharData<unsigned short> *, signed int))&v9->m_data[0])(v9, 1);
    }
    else
    {
      v11 = v8->_name.m_buffer;
      v12 = v11->m_len;
      if ( v12 != 1 && v11 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(&rent_text, v11->m_data, v12 - 1);
    }
    v13 = rent_text.m_buffer;
    if ( v1->m_pBuyHouseOwnerText )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, 0, rent_text.m_buffer->m_data);
      UIElement_Text::SetText(v1->m_pBuyHouseOwnerText, v14);
      v15 = (char *)&v20.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) )
      {
        if ( v15 )
          (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
      }
    }
    if ( v1->m_pRentHouseOwnerText )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, 0, v13->m_data);
      UIElement_Text::SetText(v1->m_pRentHouseOwnerText, v16);
      v17 = (char *)&v20.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) )
      {
        if ( v17 )
          (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      }
    }
    gmSlumlordUI::CleanItemLists(v1);
    gmSlumlordUI::UpdateButtons(v1);
    if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) )
    {
      if ( v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004C8D90) --------------------------------------------------------  // acclient.c:250369
char __thiscall gmSlumlordUI::CloseBuyHouseConfirmationDialog(gmSlumlordUI *this, bool i_bConfirm)
{
  gmSlumlordUI *v2; // esi@1
  HouseProfile *v3; // ecx@1
  char result; // al@2

  v2 = this;
  v3 = this->m_pHouseProfile;
  v2->m_uiHousePurchaseDialogContext = 0;
  if ( v3 )
  {
    if ( i_bConfirm )
    {
      if ( HouseProfile::IsPaidInFull(v3, Buy_House) != 0 )
        gmSlumlordUI::MakePayment(v2);
      result = 1;
    }
    else
    {
      v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C8DF0) --------------------------------------------------------  // acclient.c:250400
char __thiscall gmSlumlordUI::CloseRentPaymentByProxyConfirmationDialog(gmSlumlordUI *this, bool i_bConfirm)
{
  gmSlumlordUI *v2; // esi@1
  UIElement_ItemList *v3; // ecx@1
  char result; // al@2

  v2 = this;
  v3 = this->m_pRentItemList;
  v2->m_uiRentPaymentByProxyDialogContext = 0;
  if ( v3 )
  {
    if ( i_bConfirm )
    {
      if ( UIElement_ItemList::GetNumUIItems(v3) )
        gmSlumlordUI::MakePayment(v2);
      result = 1;
    }
    else
    {
      v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C8E40) --------------------------------------------------------  // acclient.c:250431
void __thiscall gmSlumlordUI::RecvNotice_CloseDialog(gmSlumlordUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmSlumlordUI *v6; // edi@1
  HashTableData<unsigned long,BaseProperty> *v7; // eax@1
  unsigned int v8; // edx@9
  HashTableData<unsigned long,BaseProperty> **v9; // eax@9
  int v10; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v11; // eax@9
  int v12; // ecx@22
  int v13; // edx@22
  int v14; // edx@26
  BasePropertyDesc *v15; // ecx@29
  unsigned int v16; // edx@29
  BasePropertyValue *v17; // ecx@33
  unsigned int v18; // edx@33
  unsigned int type; // [sp+Ch] [bp-14h]@1
  int v20; // [sp+10h] [bp-10h]@9
  int v21; // [sp+14h] [bp-Ch]@9
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
    v20 = 0;
    v21 = 0;
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
        BaseProperty::operator=(&v20, (int)&v11->m_data);
        v10 = v21;
        if ( v21 )
        {
          (*(void (__stdcall **)(PropertyCollection **))(*(_DWORD *)v21 + 112))(&data);
          v10 = v21;
        }
      }
    }
LABEL_16:
    if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13] == (HashSetData<UIElement *> *)context )
    {
      gmSlumlordUI::CloseBuyHouseConfirmationDialog((gmSlumlordUI *)((char *)v6 - 1760), (bool)data);
    }
    else
    {
      if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14] != (HashSetData<UIElement *> *)context )
      {
LABEL_21:
        if ( v20 )
        {
          v12 = v20;
          v13 = *(_DWORD *)(v20 + 4) - 1;
          *(_DWORD *)(v20 + 4) = v13;
          if ( !v13 )
            (**(void (__stdcall ***)(_DWORD))v12)(1);
          v10 = v21;
          v20 = 0;
        }
        if ( v10 )
        {
          v14 = *(_DWORD *)(v10 + 4) - 1;
          *(_DWORD *)(v10 + 4) = v14;
          if ( !v14 )
            (**(void (__stdcall ***)(_DWORD))v10)(1);
        }
        goto LABEL_28;
      }
      gmSlumlordUI::CloseRentPaymentByProxyConfirmationDialog((gmSlumlordUI *)((char *)v6 - 1760), (bool)data);
    }
    v10 = v21;
    goto LABEL_21;
  }
LABEL_28:
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v15 = p.m_pcPropertyDesc;
    v16 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v16;
    if ( !v16 )
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v17 = p.m_pcPropertyValue;
    v18 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
  }
}

//----- (004C8FD0) --------------------------------------------------------  // acclient.c:250561
char __thiscall gmSlumlordUI::UpdateHouse(gmSlumlordUI *this, unsigned int i_iidOwner, HouseProfile *houseProfile)
{
  gmSlumlordUI *v3; // esi@1
  int v4; // ecx@1
  HouseProfile *v5; // eax@2
  HouseProfile *v6; // eax@3

  v3 = this;
  v4 = (int)this->m_pHouseProfile;
  v3->m_iidOwner = i_iidOwner;
  if ( v4 )
  {
    HouseProfile::operator=(v4, (int)houseProfile);
  }
  else
  {
    v5 = (HouseProfile *)operator new(0x4Cu);
    if ( v5 )
      HouseProfile::HouseProfile(v5, houseProfile);
    else
      v6 = 0;
    v3->m_pHouseProfile = v6;
    if ( !v6 )
      return 0;
  }
  gmSlumlordUI::BackupHouseProfile(v3);
  gmSlumlordUI::RefreshHouse(v3);
  return 1;
}

//----- (004C9040) --------------------------------------------------------  // acclient.c:250592
void __thiscall gmSlumlordUI::RecvNotice_UpdateHouseProfile(gmSlumlordUI *this, unsigned int i_iidOwner, HouseProfile *i_prof)
{
  gmSlumlordUI *v3; // esi@1
  char *v4; // edi@1
  int v5; // eax@2
  unsigned int v6; // ST04_4@4
  ObjectRangeHandler *v7; // ST00_4@4
  CPlayerSystem *v8; // eax@4

  v3 = this;
  v4 = (char *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[15];
  gmSlumlordUI::UpdateHouse((gmSlumlordUI *)((char *)this - 1760), i_iidOwner, i_prof);
  (*(void (__thiscall **)(char *, signed int))(*(_DWORD *)v4 + 24))(v4, 1);
  if ( v3 == (gmSlumlordUI *)1760 )
    v5 = 0;
  else
    v5 = (int)&v3->m_hashElementsRegisteredWith;
  v6 = (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
  v7 = (ObjectRangeHandler *)v5;
  v8 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::RegisterObjectRangeHandler(v8, v7, v6, 9.0, 1, 0, 1.0, 0.0);
}

//----- (004C90B0) --------------------------------------------------------  // acclient.c:250616
char __thiscall gmSlumlordUI::MakeBuyHouseConfirmationDialog(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // edi@1
  char result; // al@2
  char *v3; // esi@3
  unsigned __int32 v4; // eax@10
  BasePropertyDesc *v5; // ecx@12
  unsigned int v6; // edx@12
  BasePropertyValue *v7; // ecx@16
  unsigned int v8; // esi@16
  BasePropertyDesc *v9; // ecx@21
  unsigned int v10; // edx@21
  BasePropertyValue *v11; // ecx@25
  unsigned int v12; // esi@25
  BaseProperty p; // [sp+10h] [bp-114h]@6
  PStringBase<unsigned short> _value; // [sp+18h] [bp-10Ch]@3
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@6
  StringInfo v16; // [sp+94h] [bp-90h]@3

  v1 = this;
  if ( this->m_uiHousePurchaseDialogContext )
  {
    result = 0;
  }
  else
  {
    StringInfo::StringInfo(&v16);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &_value,
      L"When you buy a landscape house like this one, you are restricted from buying another for 30 days. Are you sure you want to buy this house?");
    StringInfo::SetLiteralValue(&v16, &_value, 1);
    v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&_value,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v16);
    }
    _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&_value,
      &p);
    v4 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v1->m_uiHousePurchaseDialogContext = v4;
    if ( v4 )
    {
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
      StringInfo::~StringInfo(&v16);
      result = 1;
    }
    else
    {
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
      StringInfo::~StringInfo(&v16);
      result = 0;
    }
  }
  return result;
}

//----- (004C92B0) --------------------------------------------------------  // acclient.c:250730
char __thiscall gmSlumlordUI::MakeRentPaymentByProxyConfirmationDialog(gmSlumlordUI *this)
{
  gmSlumlordUI *v1; // edi@1
  char result; // al@2
  char *v3; // esi@3
  unsigned __int32 v4; // eax@10
  BasePropertyDesc *v5; // ecx@12
  unsigned int v6; // edx@12
  BasePropertyValue *v7; // ecx@16
  unsigned int v8; // esi@16
  BasePropertyDesc *v9; // ecx@21
  unsigned int v10; // edx@21
  BasePropertyValue *v11; // ecx@25
  unsigned int v12; // esi@25
  BaseProperty p; // [sp+10h] [bp-114h]@6
  PStringBase<unsigned short> _value; // [sp+18h] [bp-10Ch]@3
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@6
  StringInfo v16; // [sp+94h] [bp-90h]@3

  v1 = this;
  if ( this->m_uiRentPaymentByProxyDialogContext )
  {
    result = 0;
  }
  else
  {
    StringInfo::StringInfo(&v16);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &_value,
      L"You are paying maintenance on someone else's house. Are you sure you wish to continue?");
    StringInfo::SetLiteralValue(&v16, &_value, 1);
    v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&_value,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v16);
    }
    _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&_value,
      &p);
    v4 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v1->m_uiRentPaymentByProxyDialogContext = v4;
    if ( v4 )
    {
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
      StringInfo::~StringInfo(&v16);
      result = 1;
    }
    else
    {
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
      StringInfo::~StringInfo(&v16);
      result = 0;
    }
  }
  return result;
}

//----- (004C94B0) --------------------------------------------------------  // acclient.c:250844
int __thiscall gmSlumlordUI::ListenToElementMessage(gmSlumlordUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Panel *v2; // esi@1
  bool v3; // al@4
  UIElement_ItemList *v5; // eax@8
  bool v6; // zf@9
  unsigned int v7; // eax@18
  HouseProfile *v8; // eax@21

  v2 = (UIElement_Panel *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    v7 = i_rMsg->idElement;
    if ( i_rMsg->idElement == 268435614 )
    {
      ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
      return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
    }
    if ( v7 == 268435604 )
    {
      v8 = this->m_pHouseProfile;
      if ( !v8 || v8->_type != 4 )
      {
        gmSlumlordUI::MakeBuyHouseConfirmationDialog(this);
        return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
      }
    }
    else
    {
      if ( v7 != 268435611 )
        return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
      if ( !gmSlumlordUI::AmIHouseOwner(this) )
      {
        gmSlumlordUI::MakeRentPaymentByProxyConfirmationDialog((gmSlumlordUI *)v2);
        return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
      }
    }
    gmSlumlordUI::MakePayment((gmSlumlordUI *)v2);
    return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
  }
  if ( i_rMsg->idMessage == 21 )
  {
    if ( UIElement::IsAncestorOfMe(i_rMsg->pElement, (UIElement *)&this->m_pCurItemList->vfptr) )
    {
      gmSlumlordUI::HandleDropRelease((gmSlumlordUI *)v2, i_rMsg);
      return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
    }
    return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
  }
  if ( i_rMsg->idMessage == 24 )
  {
    v3 = i_rMsg->dwParam1 != 0;
    if ( (gmSlumlordUI *)i_rMsg->pElement == this )
    {
      gmSlumlordUI::CleanItemLists(this);
      gmSlumlordUI::UpdateButtons((gmSlumlordUI *)v2);
      return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
    }
    if ( i_rMsg->idElement == 268435600 )
    {
      if ( v3 )
      {
        v5 = this->m_pBuyItemList;
        this->m_eCurrentHouseOp = 1;
        this->m_pCurItemList = v5;
        return UIElement_Panel::ListenToElementMessage((UIElement_Panel *)&this->vfptr, i_rMsg);
      }
      v6 = this->m_eCurrentHouseOp == 1;
LABEL_10:
      if ( v6 )
      {
        this->m_eCurrentHouseOp = 0;
        this->m_pCurItemList = 0;
        return UIElement_Panel::ListenToElementMessage((UIElement_Panel *)&this->vfptr, i_rMsg);
      }
      return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
    }
    if ( i_rMsg->idElement == 268435607 )
    {
      if ( v3 )
      {
        this->m_pCurItemList = this->m_pRentItemList;
        this->m_eCurrentHouseOp = 2;
        return UIElement_Panel::ListenToElementMessage((UIElement_Panel *)&this->vfptr, i_rMsg);
      }
      v6 = this->m_eCurrentHouseOp == 2;
      goto LABEL_10;
    }
  }
  return UIElement_Panel::ListenToElementMessage(v2, i_rMsg);
}

//----- (004CB270) --------------------------------------------------------  // acclient.c:252581
void __stdcall gmSalvageUI::ClearAllTradeStates(UIElement_ItemList *_list)
{
  int v2; // ebx@1
  unsigned int v3; // esi@1
  UIElement *v4; // eax@2
  int v5; // eax@3
  HashBaseData<unsigned long> *v6; // eax@4

  v2 = UIElement_ItemList::GetNumUIItems(_list);
  v3 = 0;
  if ( v2 > 0 )
  {
    do
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&_list->vfptr, v3);
      if ( v4 )
      {
        v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          v6 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v5 + 1532));
          if ( v6 )
            ACCWeenieObject::SetTradeState((ACCWeenieObject *)v6, 0);
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < v2 );
  }
}

//----- (006F2AF0) --------------------------------------------------------  // acclient.c:775151
void _E91_88()
{
  outside_val_80 = 1000.0 + 1.0;
}

//----- (006F2B10) --------------------------------------------------------  // acclient.c:775157
void _E93_64()
{
  block_length_80 = 24.0 * 8.0;
}

//----- (006F2B30) --------------------------------------------------------  // acclient.c:775163
void _E95_64()
{
  half_square_length_80 = 24.0 * 0.5;
}

//----- (006F2B50) --------------------------------------------------------  // acclient.c:775169
int _E97_89()
{
  return atexit(nullsub_751);
}

//----- (006F2B60) --------------------------------------------------------  // acclient.c:775175
int _E100_82()
{
  return atexit(nullsub_752);
}

//----- (006F2B70) --------------------------------------------------------  // acclient.c:775181
int _E103_74()
{
  return atexit(_E104_89);
}

//----- (006F2B80) --------------------------------------------------------  // acclient.c:775187
void _E109_36()
{
  DEFAULT_VIEW_RADIUS_49 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2BA0) --------------------------------------------------------  // acclient.c:775193
void _E111_25()
{
  MIN_QUANTUM_49 = 1.0 / 30.0;
}

//----- (006F2BC0) --------------------------------------------------------  // acclient.c:775199
void _E113_13()
{
  MAX_QUANTUM_49 = 1.0 / 5.0;
}

//----- (006F2BE0) --------------------------------------------------------  // acclient.c:775205
void _E115_39()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_84, PFID_A8R8G8B8);
}

//----- (006F2BF0) --------------------------------------------------------  // acclient.c:775211
void _E118_44()
{
  LOWEST_DATA_RATE_86 = 1024;
}

//----- (006F2C00) --------------------------------------------------------  // acclient.c:775217
void _E120_32()
{
  HIGHEST_DATA_RATE_86 = 0x7FFF;
}

//----- (006F2C10) --------------------------------------------------------  // acclient.c:775223
int _E122_18()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_86;
  INITIAL_MAX_DATA_RATE_34 = LOWEST_DATA_RATE_86;
  return result;
}

//----- (006F2C20) --------------------------------------------------------  // acclient.c:775233
int _E124_41()
{
  return atexit(_E125_47);
}

//----- (006F2C30) --------------------------------------------------------  // acclient.c:775239
int sub_6F2C30()
{
  return atexit(nullsub_750);
}

