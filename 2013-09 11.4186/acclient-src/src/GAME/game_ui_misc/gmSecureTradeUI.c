/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSecureTradeUI
   Object     : GAME\game_ui_misc\gmSecureTradeUI.obj
   Functions  : 62
   Addresses  : 004C9650 - 006F2DC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C9650) --------------------------------------------------------  // acclient.c:250937
void __thiscall gmSecureTradeUI::~gmSecureTradeUI(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@1
  CPlayerSystem *v3; // eax@3
  GlobalEventHandler *v4; // eax@3

  v1 = this;
  v2 = this->m_pSelfItemsList;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmSecureTradeUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmSecureTradeUI::vftable;
  v1->vfptr = (ObjectRangeHandlerVtbl *)&gmSecureTradeUI::vftable;
  v1->vfptr = (ItemListDragHandlerVtbl *)&gmSecureTradeUI::vftable;
  if ( v2 )
    UIElement_ItemList::UnregisterItemListDragHandler(v2);
  v3 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UnregisterAllObjectRangeHandlers(v3, (ObjectRangeHandler *)&v1->vfptr);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, (NoticeHandler *)&v1->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B7018: using guessed type bool (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B701C: using guessed type void (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, unsigned __int32);
// 7B7028: using guessed type bool (__thiscall *gmSecureTradeUI::vftable)(DBCache *this);
// 7B72D0: using guessed type int (__thiscall *gmSecureTradeUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C96D0) --------------------------------------------------------  // acclient.c:250968
gmSecureTradeUI *__thiscall gmSecureTradeUI::DynamicCast(gmSecureTradeUI *this, unsigned int i_eType)
{
  gmSecureTradeUI *result; // eax@1

  result = this;
  if ( i_eType != 268435474 )
    result = (gmSecureTradeUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004C96F0) --------------------------------------------------------  // acclient.c:250979
signed int gmSecureTradeUI::GetUIElementType()
{
  return 268435474;
}

//----- (004C9700) --------------------------------------------------------  // acclient.c:250985
void __thiscall gmSecureTradeUI::UpdateTradeButtonState(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@3
  int v3; // edi@4
  int v4; // eax@4
  UIElement_Button *v5; // ecx@4
  int v6; // edi@4
  UIElement_Button *v7; // ecx@7
  UIElement_Button *v8; // ecx@10

  v1 = this;
  if ( this->m_pTradeButton )
  {
    if ( this->m_pSelfItemsList )
    {
      v2 = this->m_pOtherItemsList;
      if ( v2 )
      {
        v3 = UIElement_ItemList::GetNumUIItems(v2);
        v4 = UIElement_ItemList::GetNumUIItems(v1->m_pSelfItemsList);
        v5 = v1->m_pTradeButton;
        v6 = v4 + v3;
        if ( v5->m_state == 6 && !v6 )
          ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(13);
        v7 = v1->m_pTradeButton;
        if ( v7->m_state == 1 && !v6 )
          ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
        v8 = v1->m_pTradeButton;
        if ( v8->m_state == 13 && v6 > 0 )
          ((void (__stdcall *)(signed int))v8->vfptr[13].__vecDelDtor)(1);
      }
    }
  }
}

//----- (004C97C0) --------------------------------------------------------  // acclient.c:251028
void __userpurge gmSecureTradeUI::gmSecureTradeUI(gmSecureTradeUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSecureTradeUI *v4; // esi@1
  unsigned int v5; // edx@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->m_pTradeButton = 0;
  v4->m_pSelfPlayerName = 0;
  v4->m_pSelfTotalItemsLabel = 0;
  v4->m_pSelfItemsList = 0;
  v4->m_pOtherTradeStatusIndicator = 0;
  v4->m_pOtherPlayerName = 0;
  v4->m_pOtherTotalItemsLabel = 0;
  v4->m_pOtherItemsList = 0;
  v4->m_pClearAllItemsButton = 0;
  v4->splitItemID = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSecureTradeUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSecureTradeUI::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&gmSecureTradeUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmSecureTradeUI::vftable;
  v5 = stru_83F6EC.id;
  v4->splitItemStackSize = 0;
  v4->splitItemClassID.id = v5;
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7B7018: using guessed type bool (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B701C: using guessed type void (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, unsigned __int32);
// 7B7028: using guessed type bool (__thiscall *gmSecureTradeUI::vftable)(DBCache *this);
// 7B72D0: using guessed type int (__thiscall *gmSecureTradeUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C9870) --------------------------------------------------------  // acclient.c:251065
gmSecureTradeUI *__thiscall gmSecureTradeUI::vector_deleting_destructor(gmSecureTradeUI *this, unsigned int a2)
{
  gmSecureTradeUI *v2; // esi@1

  v2 = this;
  gmSecureTradeUI::~gmSecureTradeUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004C9890) --------------------------------------------------------  // acclient.c:251077
void __usercall gmSecureTradeUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSecureTradeUI *v3; // eax@1

  v3 = (gmSecureTradeUI *)operator new(0x634u);
  if ( v3 )
    gmSecureTradeUI::gmSecureTradeUI(v3, a1, _layout, _full_desc);
}

//----- (004C98C0) --------------------------------------------------------  // acclient.c:251087
void __thiscall gmSecureTradeUI::RecvNotice_ServerSaysAttemptFailed(gmSecureTradeUI *this, unsigned int i_iidItem)
{
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9] = 0;
}

//----- (004C98D0) --------------------------------------------------------  // acclient.c:251093
void __thiscall gmSecureTradeUI::SetMyItemNumber(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  int v2; // eax@2
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // esi@2
  PStringBase<unsigned short> result; // [sp+4h] [bp-94h]@2
  StringInfo v6; // [sp+8h] [bp-90h]@2

  v1 = this;
  if ( this->m_pSelfTotalItemsLabel )
  {
    StringInfo::StringInfo(&v6);
    StringInfo::SetStringIDandTableEnum(&v6, ID_SecureTrade_TotalItemsLabel, 268435457);
    v2 = UIElement_ItemList::GetNumUIItems(v1->m_pSelfItemsList);
    StringInfo::AddVariable_Int(&v6, ID_Items, v2);
    v3 = StringInfo::GetString(&v6, &result, 0);
    UIElement_Text::SetText(v1->m_pSelfTotalItemsLabel, v3);
    v4 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    StringInfo::~StringInfo(&v6);
  }
}

//----- (004C9970) --------------------------------------------------------  // acclient.c:251122
void __thiscall gmSecureTradeUI::SetOtherItemNumber(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  int v2; // eax@2
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // esi@2
  PStringBase<unsigned short> result; // [sp+4h] [bp-94h]@2
  StringInfo v6; // [sp+8h] [bp-90h]@2

  v1 = this;
  if ( this->m_pOtherItemsList )
  {
    StringInfo::StringInfo(&v6);
    StringInfo::SetStringIDandTableEnum(&v6, ID_SecureTrade_TotalItemsLabel, 268435457);
    v2 = UIElement_ItemList::GetNumUIItems(v1->m_pOtherItemsList);
    StringInfo::AddVariable_Int(&v6, ID_Items, v2);
    v3 = StringInfo::GetString(&v6, &result, 0);
    UIElement_Text::SetText(v1->m_pOtherTotalItemsLabel, v3);
    v4 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    StringInfo::~StringInfo(&v6);
  }
}

//----- (004C9A10) --------------------------------------------------------  // acclient.c:251151
void __thiscall gmSecureTradeUI::AcceptTheTrade(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  ClientTradeSystem *v2; // eax@1
  unsigned int v3; // edi@1
  ClientTradeSystem *v4; // eax@1
  unsigned int v5; // ebx@1
  ClientTradeSystem *v6; // eax@3
  UIElement_Button *v7; // ecx@5

  v1 = this;
  v2 = ClientTradeSystem::GetTradeSystem();
  v3 = ClientTradeSystem::GetNumSelfObjectsInTrade(v2);
  v4 = ClientTradeSystem::GetTradeSystem();
  v5 = ClientTradeSystem::GetNumPartnerObjectsInTrade(v4);
  if ( v3 != UIElement_ItemList::GetNumUIItems(v1->m_pSelfItemsList)
    || v5 != UIElement_ItemList::GetNumUIItems(v1->m_pOtherItemsList) )
  {
    ClientTradeSystem::GetTradeSystem();
    ClientTradeSystem::NotifyServerThatTradeIsOutOfSync();
  }
  else
  {
    v6 = ClientTradeSystem::GetTradeSystem();
    ClientTradeSystem::AcceptTrade(v6);
  }
  v7 = v1->m_pTradeButton;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(6);
  gmSecureTradeUI::UpdateTradeButtonState(v1);
}

//----- (004C9A90) --------------------------------------------------------  // acclient.c:251184
void __thiscall gmSecureTradeUI::DeclineTheTrade(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  ClientTradeSystem *v2; // eax@1
  UIElement_Button *v3; // ecx@1

  v1 = this;
  v2 = ClientTradeSystem::GetTradeSystem();
  ClientTradeSystem::DeclineTrade(v2);
  v3 = v1->m_pTradeButton;
  if ( v3 )
    ((void (__stdcall *)(signed int))v3->vfptr[13].__vecDelDtor)(1);
  gmSecureTradeUI::UpdateTradeButtonState(v1);
}

//----- (004C9AC0) --------------------------------------------------------  // acclient.c:251200
void __thiscall gmSecureTradeUI::FlushTradeLists(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // ebx@1
  UIElement_ItemList *v2; // ecx@1
  int v3; // edi@2
  unsigned int v4; // esi@2
  UIElement *v5; // eax@3
  int v6; // eax@4
  HashBaseData<unsigned long> *v7; // eax@5
  UIElement_ItemList *v8; // ecx@9
  int v9; // ebp@10
  unsigned int v10; // edi@10
  UIElement *v11; // eax@11
  int v12; // eax@12
  HashBaseData<unsigned long> *v13; // esi@13

  v1 = this;
  v2 = this->m_pSelfItemsList;
  if ( v2 )
  {
    v3 = UIElement_ItemList::GetNumUIItems(v2);
    v4 = 0;
    if ( v3 > 0 )
    {
      do
      {
        v5 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_pSelfItemsList->vfptr, v4);
        if ( v5 )
        {
          v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
          if ( v6 )
          {
            v7 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v6 + 1532));
            if ( v7 )
              ACCWeenieObject::SetTradeState((ACCWeenieObject *)v7, 0);
          }
        }
        ++v4;
      }
      while ( (signed int)v4 < v3 );
    }
    UIElement_ItemList::ItemList_Flush(v1->m_pSelfItemsList);
  }
  v8 = v1->m_pOtherItemsList;
  if ( v8 )
  {
    v9 = UIElement_ItemList::GetNumUIItems(v8);
    v10 = 0;
    if ( v9 > 0 )
    {
      do
      {
        v11 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_pOtherItemsList->vfptr, v10);
        if ( v11 )
        {
          v12 = v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)268435506);
          if ( v12 )
          {
            v13 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v12 + 1532));
            if ( v13 )
            {
              if ( ClientTradeSystem::GetTradeSystem()
                && ClientTradeSystem::GetTradeSystem()->m_iidTradePartner
                && !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v13)
                && !((unsigned int)v13[16].hash_next & 0x3F00000) )
                ACCWeenieObject::AddContentsToDestructionQueue((ACCWeenieObject *)v13);
            }
          }
        }
        ++v10;
      }
      while ( (signed int)v10 < v9 );
    }
    UIElement_ItemList::ItemList_Flush(v1->m_pOtherItemsList);
  }
}

//----- (004C9BE0) --------------------------------------------------------  // acclient.c:251278
void __thiscall gmSecureTradeUI::RemoveItem(gmSecureTradeUI *this, ACCWeenieObject *i_pItem)
{
  gmSecureTradeUI *v2; // esi@1

  v2 = this;
  if ( this->m_pSelfItemsList && i_pItem )
  {
    i_pItem->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)&i_pItem->vfptr, (NoticeHandler *)&this->vfptr);
    if ( UIElement_ItemList::ItemList_IsInList(v2->m_pSelfItemsList, i_pItem->id) )
    {
      ACCWeenieObject::SetTradeState(i_pItem, 0);
      UIElement_ItemList::ItemList_DeleteItem(v2->m_pSelfItemsList, i_pItem->id);
      gmSecureTradeUI::SetMyItemNumber(v2);
      gmSecureTradeUI::UpdateTradeButtonState(v2);
    }
    else if ( UIElement_ItemList::ItemList_IsInList(v2->m_pOtherItemsList, i_pItem->id) )
    {
      UIElement_ItemList::ItemList_DeleteItem(v2->m_pOtherItemsList, i_pItem->id);
      gmSecureTradeUI::SetOtherItemNumber(v2);
      gmSecureTradeUI::UpdateTradeButtonState(v2);
      if ( ClientTradeSystem::GetTradeSystem() )
      {
        if ( ClientTradeSystem::GetTradeSystem()->m_iidTradePartner
          && !ACCWeenieObject::IsOwnedByPlayer(i_pItem)
          && !(i_pItem->pwd._location & 0x3F00000) )
          ACCWeenieObject::AddContentsToDestructionQueue(i_pItem);
      }
    }
  }
}

//----- (004C9CC0) --------------------------------------------------------  // acclient.c:251310
void __cdecl gmSecureTradeUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000012u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSecureTradeUI::Create);
}

//----- (004C9CE0) --------------------------------------------------------  // acclient.c:251318
void __thiscall gmSecureTradeUI::RecvNotice_AcceptTrade(gmSecureTradeUI *this, unsigned int i_iidSource)
{
  gmSecureTradeUI *v2; // esi@2
  int v3; // ecx@2
  unsigned int v4; // eax@5
  HashSetData<UIElement *> *v5; // ecx@8
  int v6; // ecx@10

  if ( !i_iidSource )
  {
    v2 = (gmSecureTradeUI *)((char *)this - 1528);
    v3 = *((_DWORD *)&this[-1].m_hashElementsRegisteredWith + 399);
    if ( v3 )
    {
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v3 + 156))(1);
      gmSecureTradeUI::UpdateTradeButtonState(v2);
      return;
    }
    goto LABEL_12;
  }
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  if ( i_iidSource == v4 )
  {
    v2 = (gmSecureTradeUI *)((char *)this - 1528);
    v6 = *((_DWORD *)&this[-1].m_hashElementsRegisteredWith + 399);
    if ( v6 )
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6 + 156))(6);
LABEL_12:
    gmSecureTradeUI::UpdateTradeButtonState(v2);
    return;
  }
  v5 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  if ( v5 )
    ((void (__stdcall *)(signed int))v5->m_hashKey->m_alphaImage)(6);
}

//----- (004C9D70) --------------------------------------------------------  // acclient.c:251358
void __thiscall gmSecureTradeUI::RecvNotice_DeclineTrade(gmSecureTradeUI *this, unsigned int i_iidSource)
{
  unsigned int v2; // eax@2
  gmSecureTradeUI *v3; // esi@5
  int v4; // ecx@5
  HashSetData<UIElement *> *v5; // ecx@9

  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  if ( i_iidSource == v2 )
  {
    v3 = (gmSecureTradeUI *)((char *)this - 1528);
    v4 = *((_DWORD *)&this[-1].m_hashElementsRegisteredWith + 399);
    if ( v4 )
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v4 + 156))(1);
    gmSecureTradeUI::UpdateTradeButtonState(v3);
  }
  else
  {
    v5 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->m_hashKey->m_alphaImage)(13);
  }
}

//----- (004C9DD0) --------------------------------------------------------  // acclient.c:251386
void __thiscall gmSecureTradeUI::SetTradePartner(gmSecureTradeUI *this, unsigned int i_iidPartner)
{
  gmSecureTradeUI *v2; // ebx@1
  ACCWeenieObject *v3; // eax@3
  unsigned int v4; // esi@3
  char *v5; // esi@6
  PStringBase<unsigned short> strCharName; // [sp+4h] [bp-4h]@1

  strCharName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  if ( this->m_pOtherPlayerName )
  {
    strCharName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( i_iidPartner )
    {
      v3 = ACCWeenieObject::GetObjectNameWide(
             (ACCWeenieObject *)&i_iidPartner,
             (PStringBase<unsigned short> *)i_iidPartner,
             2u,
             0);
      PStringBase<unsigned short>::operator=(&strCharName, (const unsigned __int16 *)v3);
      v4 = i_iidPartner - 20;
      if ( !InterlockedDecrement((volatile LONG *)(i_iidPartner - 20 + 4)) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
    }
    UIElement_Text::SetText(v2->m_pOtherPlayerName, &strCharName);
    v5 = (char *)&strCharName.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strCharName.m_charbuffer[-1].m_data[8]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
  }
}

//----- (004C9E80) --------------------------------------------------------  // acclient.c:251426
char __thiscall gmSecureTradeUI::AddMyItem(gmSecureTradeUI *this, unsigned int i_iidItem, unsigned int i_uiPos)
{
  gmSecureTradeUI *v3; // esi@1
  char result; // al@2
  UIElement_Button *v5; // ecx@3
  UIElement *v6; // ecx@5
  int v7; // eax@7
  HashBaseData<unsigned long> *v8; // eax@9

  v3 = this;
  if ( this->m_pSelfItemsList )
  {
    v5 = this->m_pTradeButton;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
    gmSecureTradeUI::UpdateTradeButtonState(v3);
    v6 = v3->m_pOtherTradeStatusIndicator;
    if ( v6 )
      ((void (__stdcall *)(signed int))v6->vfptr[13].__vecDelDtor)(13);
    v7 = UIElement_ItemList::ItemList_GetItem(v3->m_pSelfItemsList, i_iidItem);
    if ( v7 )
    {
      UIElement_UIItem::SetWaitingState((UIElement_UIItem *)v7, 0);
      result = 1;
    }
    else
    {
      v8 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
      if ( v8 )
        ACCWeenieObject::SetTradeState((ACCWeenieObject *)v8, 1);
      UIElement_ItemList::ItemList_InsertItem(v3->m_pSelfItemsList, i_iidItem, i_uiPos);
      gmSecureTradeUI::SetMyItemNumber(v3);
      gmSecureTradeUI::UpdateTradeButtonState(v3);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C9F30) --------------------------------------------------------  // acclient.c:251470
char __thiscall gmSecureTradeUI::AddPartnerItem(gmSecureTradeUI *this, unsigned int i_iidItem, unsigned int i_uiPos)
{
  gmSecureTradeUI *v3; // esi@1
  char result; // al@2
  UIElement_Button *v5; // ecx@3
  UIElement *v6; // ecx@5
  int v7; // eax@7

  v3 = this;
  if ( this->m_pOtherItemsList )
  {
    v5 = this->m_pTradeButton;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
    gmSecureTradeUI::UpdateTradeButtonState(v3);
    v6 = v3->m_pOtherTradeStatusIndicator;
    if ( v6 )
      ((void (__stdcall *)(signed int))v6->vfptr[13].__vecDelDtor)(13);
    v7 = UIElement_ItemList::ItemList_GetItem(v3->m_pOtherItemsList, i_iidItem);
    if ( v7 )
    {
      UIElement_UIItem::SetWaitingState((UIElement_UIItem *)v7, 0);
      result = 1;
    }
    else
    {
      UIElement_ItemList::ItemList_InsertItem(v3->m_pOtherItemsList, i_iidItem, i_uiPos);
      gmSecureTradeUI::SetOtherItemNumber(v3);
      gmSecureTradeUI::UpdateTradeButtonState(v3);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C9FC0) --------------------------------------------------------  // acclient.c:251510
char __thiscall gmSecureTradeUI::RemoveAddedItem(gmSecureTradeUI *this, unsigned int itemID)
{
  gmSecureTradeUI *v2; // esi@1
  char result; // al@2
  UIElement_Button *v4; // ecx@3
  UIElement *v5; // ecx@5
  int v6; // eax@7
  UIElement_UIItem *v7; // eax@8
  UIElement_UIItem *v8; // edi@8

  v2 = this;
  if ( this->m_pSelfItemsList )
  {
    v4 = this->m_pTradeButton;
    if ( v4 )
      ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(1);
    gmSecureTradeUI::UpdateTradeButtonState(v2);
    v5 = v2->m_pOtherTradeStatusIndicator;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(13);
    v6 = UIElement_ItemList::ItemList_GetItem(v2->m_pSelfItemsList, itemID);
    if ( v6
      && (v7 = (UIElement_UIItem *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v6 + 148))(v6, 268435506),
          (v8 = v7) != 0) )
    {
      UIElement_UIItem::SetWaitingState(v7, 0);
      gmSecureTradeUI::RemoveItem(v2, v8->weenObj);
      gmSecureTradeUI::SetMyItemNumber(v2);
      gmSecureTradeUI::UpdateTradeButtonState(v2);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CA060) --------------------------------------------------------  // acclient.c:251554
char __thiscall gmSecureTradeUI::RemovePartnerItem(gmSecureTradeUI *this, unsigned int itemID)
{
  gmSecureTradeUI *v2; // esi@1
  char result; // al@2
  UIElement_Button *v4; // ecx@3
  UIElement *v5; // ecx@5
  int v6; // eax@7
  UIElement_UIItem *v7; // eax@8
  UIElement_UIItem *v8; // edi@8

  v2 = this;
  if ( this->m_pOtherItemsList )
  {
    v4 = this->m_pTradeButton;
    if ( v4 )
      ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(1);
    gmSecureTradeUI::UpdateTradeButtonState(v2);
    v5 = v2->m_pOtherTradeStatusIndicator;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(13);
    v6 = UIElement_ItemList::ItemList_GetItem(v2->m_pOtherItemsList, itemID);
    if ( v6
      && (v7 = (UIElement_UIItem *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v6 + 148))(v6, 268435506),
          (v8 = v7) != 0) )
    {
      UIElement_UIItem::SetWaitingState(v7, 0);
      gmSecureTradeUI::RemoveItem(v2, v8->weenObj);
      gmSecureTradeUI::SetOtherItemNumber(v2);
      gmSecureTradeUI::UpdateTradeButtonState(v2);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CA100) --------------------------------------------------------  // acclient.c:251598
void __thiscall gmSecureTradeUI::Reset(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  unsigned int v2; // eax@2
  UIElement *v3; // ecx@4

  v1 = this;
  if ( (this->m_nFlags >> 17) & 1 )
  {
    v2 = (unsigned int)ClientTradeSystem::GetTradeSystem();
    if ( v2 )
      v2 = ClientTradeSystem::GetTradeSystem()->m_iidTradePartner;
    gmSecureTradeUI::SetTradePartner(v1, v2);
    v3 = v1->m_pOtherTradeStatusIndicator;
    if ( v3 )
      ((void (__stdcall *)(signed int))v3->vfptr[13].__vecDelDtor)(13);
    gmSecureTradeUI::FlushTradeLists(v1);
    gmSecureTradeUI::SetMyItemNumber(v1);
    gmSecureTradeUI::SetOtherItemNumber(v1);
    gmSecureTradeUI::UpdateTradeButtonState(v1);
  }
}

//----- (004CA160) --------------------------------------------------------  // acclient.c:251622
void __thiscall gmSecureTradeUI::PostInit(gmSecureTradeUI *this)
{
  gmSecureTradeUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@6
  int v5; // eax@9
  int v6; // eax@12
  int v7; // eax@15
  int v8; // eax@18
  int v9; // eax@21
  int v10; // eax@24
  int v11; // eax@27
  int v12; // eax@30
  int v13; // eax@33
  int v14; // eax@36
  int v15; // eax@39
  int v16; // eax@42
  UIElement *v17; // eax@45
  int v18; // eax@46
  UIElement *v19; // eax@48
  int v20; // eax@49
  UIElement *v21; // eax@51
  int v22; // eax@52
  UIElement *v23; // eax@54
  UIElement_ItemList *v24; // eax@55
  UIElement *v25; // eax@59
  int v26; // eax@60
  UIElement *v27; // eax@62
  int v28; // eax@63
  UIElement *v29; // eax@65
  int v30; // eax@66
  UIElement *v31; // eax@68

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD231, (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD236, (NoticeHandler *)v4);
    if ( v1 )
      v5 = (int)&v1->vfptr;
    else
      v5 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100083u, (NoticeHandler *)v5);
    if ( v1 )
      v6 = (int)&v1->vfptr;
    else
      v6 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100085u, (NoticeHandler *)v6);
    if ( v1 )
      v7 = (int)&v1->vfptr;
    else
      v7 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100088u, (NoticeHandler *)v7);
    if ( v1 )
      v8 = (int)&v1->vfptr;
    else
      v8 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)gmKeyboardUI::ListenToElementMessage,
      (NoticeHandler *)v8);
    if ( v1 )
      v9 = (int)&v1->vfptr;
    else
      v9 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD239, (NoticeHandler *)v9);
    if ( v1 )
      v10 = (int)&v1->vfptr;
    else
      v10 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100087u, (NoticeHandler *)v10);
    if ( v1 )
      v11 = (int)&v1->vfptr;
    else
      v11 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100084u, (NoticeHandler *)v11);
    if ( v1 )
      v12 = (int)&v1->vfptr;
    else
      v12 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD232, (NoticeHandler *)v12);
    if ( v1 )
      v13 = (int)&v1->vfptr;
    else
      v13 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD23A, (NoticeHandler *)v13);
    if ( v1 )
      v14 = (int)&v1->vfptr;
    else
      v14 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100008u, (NoticeHandler *)v14);
    if ( v1 )
      v15 = (int)&v1->vfptr;
    else
      v15 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100009u, (NoticeHandler *)v15);
    if ( v1 )
      v16 = (int)&v1->vfptr;
    else
      v16 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100011u, (NoticeHandler *)v16);
  }
  v17 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000086u);
  if ( v17 )
    v18 = v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)1);
  else
    v18 = 0;
  v1->m_pTradeButton = (UIElement_Button *)v18;
  v19 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000085u);
  if ( v19 )
    v20 = v19->vfptr[12].OnAction((IInputActionCallback *)v19, (InputEvent *)12);
  else
    v20 = 0;
  v1->m_pSelfPlayerName = (UIElement_Text *)v20;
  v21 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000087u);
  if ( v21 )
    v22 = v21->vfptr[12].OnAction((IInputActionCallback *)v21, (InputEvent *)12);
  else
    v22 = 0;
  v1->m_pSelfTotalItemsLabel = (UIElement_Text *)v22;
  v23 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000088u);
  if ( v23 )
    v24 = (UIElement_ItemList *)v23->vfptr[12].OnAction((IInputActionCallback *)v23, (InputEvent *)268435505);
  else
    v24 = 0;
  v1->m_pSelfItemsList = v24;
  if ( v24 )
    UIElement_ItemList::RegisterItemListDragHandler(v24, (ItemListDragHandler *)&v1->vfptr);
  v1->m_pOtherTradeStatusIndicator = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000007Fu);
  v25 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000007Eu);
  if ( v25 )
    v26 = v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)12);
  else
    v26 = 0;
  v1->m_pOtherPlayerName = (UIElement_Text *)v26;
  v27 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000080u);
  if ( v27 )
    v28 = v27->vfptr[12].OnAction((IInputActionCallback *)v27, (InputEvent *)12);
  else
    v28 = 0;
  v1->m_pOtherTotalItemsLabel = (UIElement_Text *)v28;
  v29 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000081u);
  if ( v29 )
    v30 = v29->vfptr[12].OnAction((IInputActionCallback *)v29, (InputEvent *)268435505);
  else
    v30 = 0;
  v1->m_pOtherItemsList = (UIElement_ItemList *)v30;
  v31 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000008Au);
  if ( v31 )
  {
    v1->m_pClearAllItemsButton = (UIElement_Button *)v31->vfptr[12].OnAction(
                                                       (IInputActionCallback *)v31,
                                                       (InputEvent *)1);
    gmSecureTradeUI::Reset(v1);
  }
  else
  {
    v1->m_pClearAllItemsButton = 0;
    gmSecureTradeUI::Reset(v1);
  }
}

//----- (004CA470) --------------------------------------------------------  // acclient.c:251796
void __thiscall gmSecureTradeUI::OnVisibilityChanged(gmSecureTradeUI *this, bool i_bVisible)
{
  gmSecureTradeUI *v2; // esi@1
  CPlayerSystem *v3; // eax@3
  ClientTradeSystem *v4; // eax@3

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( !i_bVisible )
    {
      v3 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::UnregisterAllObjectRangeHandlers(v3, (ObjectRangeHandler *)&v2->vfptr);
      v4 = ClientTradeSystem::GetTradeSystem();
      ClientTradeSystem::CloseTradeNegotiations(v4);
      gmSecureTradeUI::Reset(v2);
    }
  }
}

//----- (004CA4C0) --------------------------------------------------------  // acclient.c:251818
void __thiscall gmSecureTradeUI::OnObjectRangeExit(gmSecureTradeUI *this, unsigned int _objectID)
{
  gmSecureTradeUI *v2; // esi@1
  unsigned int v3; // eax@1
  ClientTradeSystem *v4; // eax@4

  v2 = this;
  v3 = (unsigned int)ClientTradeSystem::GetTradeSystem();
  if ( v3 )
    v3 = ClientTradeSystem::GetTradeSystem()->m_iidTradePartner;
  if ( _objectID == v3 )
  {
    v4 = ClientTradeSystem::GetTradeSystem();
    ClientTradeSystem::CloseTradeNegotiations(v4);
    gmSecureTradeUI::Reset((gmSecureTradeUI *)((char *)v2 - 1532));
  }
}

//----- (004CA500) --------------------------------------------------------  // acclient.c:251837
void __thiscall gmSecureTradeUI::RecvNotice_AddItemToTrade(gmSecureTradeUI *this, unsigned int i_iidItem, unsigned int i_eTradeListID, unsigned int i_uiPos)
{
  if ( i_eTradeListID == 2 )
  {
    gmSecureTradeUI::AddPartnerItem((gmSecureTradeUI *)((char *)this - 1528), i_iidItem, i_uiPos);
  }
  else if ( i_eTradeListID == 1 )
  {
    gmSecureTradeUI::AddMyItem((gmSecureTradeUI *)((char *)this - 1528), i_iidItem, i_uiPos);
  }
}

//----- (004CA540) --------------------------------------------------------  // acclient.c:251850
void __thiscall gmSecureTradeUI::RecvNotice_ClearTradeAcceptance(gmSecureTradeUI *this)
{
  gmSecureTradeUI::Reset((gmSecureTradeUI *)((char *)this - 1528));
}

//----- (004CA550) --------------------------------------------------------  // acclient.c:251856
void __thiscall gmSecureTradeUI::RecvNotice_CloseTrade(gmSecureTradeUI *this, unsigned int i_eError)
{
  char *v2; // esi@1
  char *v3; // esi@2
  PStringBase<unsigned short> _text; // [sp+0h] [bp-4h]@1

  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = (char *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12];
  gmSecureTradeUI::Reset((gmSecureTradeUI *)((char *)this - 1528));
  if ( *((_DWORD *)v2 + 390) )
  {
    _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    UIElement_Text::SetText(*((UIElement_Text **)v2 + 390), &_text);
    v3 = (char *)&_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (004CA5C0) --------------------------------------------------------  // acclient.c:251880
void __thiscall gmSecureTradeUI::RecvNotice_RegisterTrade(gmSecureTradeUI *this, unsigned int i_iidInitiator, unsigned int i_iidPartner, long double i_ttStamp)
{
  gmSecureTradeUI *v4; // edi@1
  gmSecureTradeUI *v5; // esi@1
  int v6; // eax@2
  ObjectRangeHandler *v7; // ST00_4@4
  CPlayerSystem *v8; // eax@4

  v4 = this;
  v5 = (gmSecureTradeUI *)((char *)this - 1528);
  ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12][3].m_hashKey)(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12],
    1);
  gmSecureTradeUI::SetTradePartner(v5, i_iidPartner);
  if ( v4 == (gmSecureTradeUI *)1528 )
    v6 = 0;
  else
    v6 = (int)&v4->m_hashElementsRegisteredWith;
  v7 = (ObjectRangeHandler *)v6;
  v8 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::RegisterObjectRangeHandler(v8, v7, i_iidPartner, 5.0, 1, 0, 1.0, 0.0);
}

//----- (004CA630) --------------------------------------------------------  // acclient.c:251904
void __thiscall gmSecureTradeUI::RecvNotice_RemoveItemFromTrade(gmSecureTradeUI *this, unsigned int i_iidItem, unsigned int i_eTradeListID)
{
  if ( i_eTradeListID == 2 )
  {
    gmSecureTradeUI::RemovePartnerItem((gmSecureTradeUI *)((char *)this - 1528), i_iidItem);
  }
  else if ( i_eTradeListID == 1 )
  {
    gmSecureTradeUI::RemoveAddedItem((gmSecureTradeUI *)((char *)this - 1528), i_iidItem);
  }
}

//----- (004CA670) --------------------------------------------------------  // acclient.c:251917
void __thiscall gmSecureTradeUI::RecvNotice_ResetTrade(gmSecureTradeUI *this, unsigned int i_iidSource)
{
  gmSecureTradeUI::Reset((gmSecureTradeUI *)((char *)this - 1528));
}

//----- (004CA680) --------------------------------------------------------  // acclient.c:251923
void __thiscall gmSecureTradeUI::RecvNotice_TradeFailure(gmSecureTradeUI *this, unsigned int i_iidItem, unsigned int i_eError)
{
  gmSecureTradeUI::RemoveAddedItem((gmSecureTradeUI *)((char *)this - 1528), i_iidItem);
}

//----- (004CA6A0) --------------------------------------------------------  // acclient.c:251929
char __thiscall gmSecureTradeUI::DragItemAcceptable(gmSecureTradeUI *this, unsigned int i_iidItem, bool _silent)
{
  gmSecureTradeUI *v3; // edi@1
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  char *v6; // esi@4
  char v8; // al@11
  PStringBase<unsigned short> _value; // [sp+8h] [bp-94h]@4
  StringInfo siError; // [sp+Ch] [bp-90h]@4

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
  v5 = v4;
  if ( !v4 )
    return 0;
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    if ( !_silent )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can only trade items you are carrying");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      v6 = (char *)&_value.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
    }
    return 0;
  }
  if ( UIElement_ItemList::ItemList_IsInList(v3->m_pSelfItemsList, v5->id) )
    return 0;
  if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v5) )
    v8 = LOBYTE(v5[21].hash_next);
  return 1;
}

//----- (004CA780) --------------------------------------------------------  // acclient.c:251970
int __thiscall gmSecureTradeUI::AddItem(gmSecureTradeUI *this, unsigned int _itemID, int _position, bool _removeDuplicates, bool _addContents, bool _excludeIfUnacceptable)
{
  gmSecureTradeUI *v6; // edi@1
  HashBaseData<unsigned long> *v8; // esi@3
  int v9; // ebp@3
  UIElement *v10; // ebx@7
  int v11; // ST10_4@7
  unsigned int v12; // ST0C_4@7
  PStringBase<unsigned short> *v13; // eax@10
  int v14; // ebx@10
  IDList *v15; // eax@13
  IDList *v16; // esi@13
  int v17; // eax@14
  unsigned int v18; // eax@15
  int v19; // ecx@17
  char *v20; // esi@18
  int contentNum; // [sp+4h] [bp-9Ch]@10
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@10
  int placedPosition; // [sp+Ch] [bp-94h]@3
  StringInfo siError; // [sp+10h] [bp-90h]@13

  v6 = this;
  if ( !this->m_pSelfItemsList )
    return -1;
  placedPosition = -1;
  v8 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v9 = _position;
  if ( !ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v8)
    && !ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v8) )
  {
    if ( UIElement_ItemList::ItemList_IsInList(v6->m_pSelfItemsList, v8->id) )
      return -1;
    ACCWeenieObject::SetTradeState((ACCWeenieObject *)v8, 1);
    v10 = (UIElement *)UIElement_ItemList::ItemList_InsertItem(v6->m_pSelfItemsList, v8->id, _position);
    gmSecureTradeUI::SetMyItemNumber(v6);
    gmSecureTradeUI::UpdateTradeButtonState(v6);
    v11 = UIElement_ListBox::WhatNum((UIElement_ListBox *)&v6->m_pSelfItemsList->vfptr, v10);
    v12 = v8->id;
    placedPosition = v11;
    ClientTradeSystem::GetTradeSystem();
    ClientTradeSystem::AddItemToSelfTradeList(v12, v11);
  }
  if ( _addContents && ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v8) > 0 )
  {
    v13 = ACCWeenieObject::GetObjectNameWide(
            (ACCWeenieObject *)v8,
            (PStringBase<unsigned short> *)&contentNum,
            NAME_APPROPRIATE,
            0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"Trading contents of %s",
      v13->m_charbuffer);
    v14 = contentNum - 20;
    if ( !InterlockedDecrement((volatile LONG *)(contentNum - 20 + 4)) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    v15 = ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v8);
    v16 = v15;
    if ( v15 )
    {
      IDList::SetCurToNum(v15, 0);
      v17 = v16->numIDs;
      contentNum = 0;
      if ( v17 > 0 )
      {
        do
        {
          v18 = IDList::GetCurID(v16);
          if ( gmSecureTradeUI::AddItem(v6, v18, v9, _removeDuplicates, 0, 1) != -1 )
            v9 = 0;
          IDList::SetCurToNext(v16);
          v19 = v16->numIDs;
          ++contentNum;
        }
        while ( contentNum < v19 );
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
  return placedPosition;
}

//----- (004CA980) --------------------------------------------------------  // acclient.c:252063
char __thiscall gmSecureTradeUI::OnItemListDragOver(gmSecureTradeUI *this, UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && !(_dropFlags & 0xE) )
  {
    if ( gmSecureTradeUI::DragItemAcceptable((gmSecureTradeUI *)((char *)this - 1536), _dropItemID, 1) )
    {
      UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
      return 1;
    }
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000041u);
  }
  return 1;
}

//----- (004CA9D0) --------------------------------------------------------  // acclient.c:252078
void __thiscall gmSecureTradeUI::ItemAttributesChanged(gmSecureTradeUI *this, unsigned int i_iidItem, int _flags)
{
  gmSecureTradeUI *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@3
  signed int v5; // eax@5

  v3 = this;
  if ( this->splitItemID )
  {
    if ( _flags & 1 )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
      if ( v4 )
      {
        if ( v4[13].id == v3->splitItemClassID.id )
        {
          v5 = v4[20].id;
          if ( !v5 )
            v5 = 1;
          if ( v5 == v3->splitItemStackSize )
          {
            gmSecureTradeUI::AddItem(v3, i_iidItem, 0, 0, 0, 1);
            v3->splitItemID = 0;
          }
        }
      }
    }
  }
}

//----- (004CAA40) --------------------------------------------------------  // acclient.c:252109
char __thiscall gmSecureTradeUI::AcceptDragObject(gmSecureTradeUI *this, unsigned int i_iidObject)
{
  gmSecureTradeUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // esi@2
  unsigned int v4; // ecx@4
  PStringBase<unsigned short> *v5; // eax@7
  char *v6; // esi@7
  char *v7; // esi@10
  char *v9; // esi@13
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@7
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@7
  StringInfo siError; // [sp+10h] [bp-90h]@10

  v2 = this;
  if ( !gmSecureTradeUI::DragItemAcceptable(this, i_iidObject, 0) )
    return 0;
  v3 = ClientObjMaintSystem::GetWeenieObject(i_iidObject);
  if ( GenItemHolder::splitSize != GenItemHolder::maxSplitSize )
  {
    if ( SmartBox::smartbox )
      v4 = SmartBox::smartbox->player_id;
    else
      v4 = 0;
    if ( ItemHolder::AttemptToPlaceInContainer(v3->id, v4, (unsigned int)v3[15].vfptr, 0, 0) )
    {
      v2->splitItemID = v3->id;
      v2->splitItemClassID.id = v3[13].id;
      v2->splitItemStackSize = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v3);
      v5 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"Splitting the %s before trading them",
        v5->m_charbuffer);
      v6 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      v7 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v7 )
      {
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        return 1;
      }
      return 1;
    }
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot split the stack to trade it");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    v9 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v3, 0);
  gmSecureTradeUI::AddItem(v2, v3->id, 0, 1, 1, 0);
  return 1;
}

//----- (004CAC20) --------------------------------------------------------  // acclient.c:252174
void __thiscall gmSecureTradeUI::ServerSaysMoveItem(gmSecureTradeUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmSecureTradeUI *v9; // edi@1
  unsigned int v10; // eax@2
  ClientTradeSystem *v11; // eax@7
  HashBaseData<unsigned long> *v12; // ebx@9
  InterfacePtr<Interface> *v13; // eax@9
  char v14; // al@13
  ClientObjMaintSystem *v15; // ebx@13
  ClientTradeSystem *v16; // eax@15
  unsigned int v17; // eax@15
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+4h] [bp-10h]@9
  InterfacePtr<Interface> result; // [sp+Ch] [bp-8h]@9

  v9 = this;
  if ( this->m_pOtherItemsList )
  {
    v10 = (unsigned int)ClientTradeSystem::GetTradeSystem();
    if ( v10 )
      v10 = ClientTradeSystem::GetTradeSystem()->m_iidTradePartner;
    if ( _newContainer == v10 )
    {
      if ( ClientTradeSystem::GetTradeSystem() )
      {
        if ( ClientTradeSystem::GetTradeSystem()->m_iidTradePartner )
        {
          v11 = ClientTradeSystem::GetTradeSystem();
          if ( ClientTradeSystem::IsPartnerTradingItem(v11, _itemID)
            && !UIElement_ItemList::ItemList_IsInList(v9->m_pOtherItemsList, _itemID) )
          {
            v12 = ClientObjMaintSystem::GetWeenieObject(_itemID);
            v13 = GetClassObject(&result, &ClientObjMaintSystem_ClassType_0);
            InterfacePtr<ClientObjMaintSystem>::InterfacePtr<ClientObjMaintSystem>(&spObjMaint, v13);
            if ( (_DWORD)result.m_pInterface )
              ((void (*)(void))result.m_pInterface->vfptr->Release)();
            if ( v12 )
              ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v12);
            v14 = InterfacePtr<PlayerDesc>::IsValid((InterfacePtr<PlayerDesc> *)&spObjMaint);
            v15 = spObjMaint.m_pInterface;
            if ( v14 )
              CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, _itemID);
            v16 = ClientTradeSystem::GetTradeSystem();
            v17 = ClientTradeSystem::GetItemLocationInPartnerTradeList(v16, _itemID);
            gmSecureTradeUI::AddPartnerItem(v9, _itemID, v17);
            gmSecureTradeUI::SetOtherItemNumber(v9);
            gmSecureTradeUI::UpdateTradeButtonState(v9);
            if ( v15 )
              v15->vfptr->Release((Interface *)v15);
          }
        }
      }
    }
  }
}

//----- (004CAD30) --------------------------------------------------------  // acclient.c:252230
void __thiscall gmSecureTradeUI::RecvNotice_ServerSaysMoveItem(gmSecureTradeUI *this, unsigned int i_itemID, unsigned int i_oldContainer, unsigned int i_oldWielder, unsigned int i_oldLocation, unsigned int i_newContainer, int i_place, unsigned int i_newWielder, unsigned int i_newLocation)
{
  gmSecureTradeUI::ServerSaysMoveItem(
    (gmSecureTradeUI *)((char *)this - 1528),
    i_itemID,
    i_oldContainer,
    i_oldWielder,
    i_oldLocation,
    i_newContainer,
    i_place,
    i_newWielder,
    i_newLocation);
}

//----- (004CAD40) --------------------------------------------------------  // acclient.c:252245
void __thiscall gmSecureTradeUI::RecvNotice_ItemAttributesChanged(gmSecureTradeUI *this, unsigned int i_iidObject, unsigned int i_attrib)
{
  gmSecureTradeUI::ItemAttributesChanged((gmSecureTradeUI *)((char *)this - 1528), i_iidObject, i_attrib);
}

//----- (004CAD50) --------------------------------------------------------  // acclient.c:252251
char __thiscall gmSecureTradeUI::TradeAnItemForDummies(gmSecureTradeUI *this, unsigned int i_iidItemToTrade)
{
  gmSecureTradeUI *v2; // esi@1
  UIElement_ItemList *v3; // ecx@1
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@6
  StringInfo siError; // [sp+8h] [bp-90h]@6

  v2 = this;
  v3 = this->m_pSelfItemsList;
  if ( !v3 )
    return 0;
  if ( UIElement_ItemList::ItemList_IsInList(v3, i_iidItemToTrade) )
    return 0;
  if ( i_iidItemToTrade == ACCWeenieObject::selectedID && GenItemHolder::splitSize != GenItemHolder::maxSplitSize )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You must split the stack before trading it.");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  gmSecureTradeUI::AddItem(v2, i_iidItemToTrade, 0, 1, 1, 0);
  return 1;
}

//----- (004CAE10) --------------------------------------------------------  // acclient.c:252279
void __thiscall gmSecureTradeUI::HandleDropRelease(gmSecureTradeUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  UIElement *v4; // eax@1
  gmSecureTradeUI *v5; // edi@1
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
      if ( UIElement::IsAncestorOfMe(v4, (UIElement *)&this->m_pSelfItemsList->vfptr) )
      {
        UIElement_ItemList::InqDropIconInfo(v3, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
        if ( i_rMsg )
        {
          if ( !(dropFlags & 0xE) )
            gmSecureTradeUI::AcceptDragObject(v5, (unsigned int)i_rMsg);
        }
      }
    }
  }
}

//----- (004CAE80) --------------------------------------------------------  // acclient.c:252310
int __thiscall gmSecureTradeUI::ListenToElementMessage(gmSecureTradeUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1
  ClientTradeSystem *v4; // eax@8
  UIElement_Button *v5; // eax@9
  unsigned int v6; // eax@10

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268435590 )
    {
      v5 = this->m_pTradeButton;
      if ( v5 )
      {
        v6 = v5->m_state;
        if ( v6 == 6 )
        {
          gmSecureTradeUI::AcceptTheTrade(this);
          return UIElement::ListenToElementMessage(v2, i_rMsg);
        }
        if ( v6 == 1 )
          gmSecureTradeUI::DeclineTheTrade(this);
      }
    }
    else
    {
      if ( i_rMsg->idElement == 268435594 )
      {
        v4 = ClientTradeSystem::GetTradeSystem();
        ClientTradeSystem::ResetTrade(v4);
        return UIElement::ListenToElementMessage(v2, i_rMsg);
      }
      if ( i_rMsg->idElement == 268435595 )
      {
        ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
        return UIElement::ListenToElementMessage(v2, i_rMsg);
      }
    }
  }
  else if ( i_rMsg->idMessage == 21 )
  {
    gmSecureTradeUI::HandleDropRelease(this, i_rMsg);
    return UIElement::ListenToElementMessage(v2, i_rMsg);
  }
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004CAF30) --------------------------------------------------------  // acclient.c:252359
void __thiscall gmSecureTradeUI::RecvNotice_TradeAnItemForDummies(gmSecureTradeUI *this, unsigned int i_iidObject)
{
  gmSecureTradeUI::TradeAnItemForDummies((gmSecureTradeUI *)((char *)this - 1528), i_iidObject);
}

//----- (006F2C40) --------------------------------------------------------  // acclient.c:775245
void _E91_89()
{
  outside_val_81 = 1000.0 + 1.0;
}

//----- (006F2C60) --------------------------------------------------------  // acclient.c:775251
void _E93_65()
{
  block_length_81 = 24.0 * 8.0;
}

//----- (006F2C80) --------------------------------------------------------  // acclient.c:775257
void _E95_65()
{
  half_square_length_81 = 24.0 * 0.5;
}

//----- (006F2CA0) --------------------------------------------------------  // acclient.c:775263
int _E97_90()
{
  return atexit(nullsub_746);
}

//----- (006F2CB0) --------------------------------------------------------  // acclient.c:775269
int _E100_83()
{
  return atexit(nullsub_747);
}

//----- (006F2CC0) --------------------------------------------------------  // acclient.c:775275
int _E103_75()
{
  return atexit(_E104_90);
}

//----- (006F2CD0) --------------------------------------------------------  // acclient.c:775281
void _E109_37()
{
  DEFAULT_VIEW_RADIUS_50 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2CF0) --------------------------------------------------------  // acclient.c:775287
void _E111_26()
{
  MIN_QUANTUM_50 = 1.0 / 30.0;
}

//----- (006F2D10) --------------------------------------------------------  // acclient.c:775293
void _E113_14()
{
  MAX_QUANTUM_50 = 1.0 / 5.0;
}

//----- (006F2D30) --------------------------------------------------------  // acclient.c:775299
void _E115_40()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_85, PFID_A8R8G8B8);
}

//----- (006F2D40) --------------------------------------------------------  // acclient.c:775305
void _E118_45()
{
  LOWEST_DATA_RATE_87 = 1024;
}

//----- (006F2D50) --------------------------------------------------------  // acclient.c:775311
void _E120_33()
{
  HIGHEST_DATA_RATE_87 = 0x7FFF;
}

//----- (006F2D60) --------------------------------------------------------  // acclient.c:775317
int _E122_19()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_87;
  INITIAL_MAX_DATA_RATE_35 = LOWEST_DATA_RATE_87;
  return result;
}

//----- (006F2D70) --------------------------------------------------------  // acclient.c:775327
int _E124_42()
{
  return atexit(_E125_48);
}

//----- (006F2D80) --------------------------------------------------------  // acclient.c:775333
unsigned int _E127_36()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SecureTrade_TotalItemsLabel");
  ID_SecureTrade_TotalItemsLabel = result;
  return result;
}

//----- (006F2DA0) --------------------------------------------------------  // acclient.c:775343
unsigned int _E129_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ITEMS");
  ID_Items = result;
  return result;
}

//----- (006F2DC0) --------------------------------------------------------  // acclient.c:775353
int sub_6F2DC0()
{
  return atexit(nullsub_745);
}

