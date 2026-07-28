/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmExternalContainerUI
   Object     : GAME\game_ui_misc\gmExternalContainerUI.obj
   Functions  : 32
   Addresses  : 004CBA20 - 006F3060 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CBA20) --------------------------------------------------------  // acclient.c:253041
void __thiscall gmExternalContainerUI::~gmExternalContainerUI(gmExternalContainerUI *this)
{
  gmExternalContainerUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@1
  CPlayerSystem *v3; // eax@3
  GlobalEventHandler *v4; // eax@3

  v1 = this;
  v2 = this->m_itemList;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmExternalContainerUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmExternalContainerUI::vftable;
  v1->vfptr = (ObjectRangeHandlerVtbl *)&gmExternalContainerUI::vftable;
  v1->vfptr = (ItemListDragHandlerVtbl *)&gmExternalContainerUI::vftable;
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
// 7B7D7C: using guessed type bool (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B7D80: using guessed type void (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, unsigned __int32);
// 7B7D88: using guessed type bool (__thiscall *gmExternalContainerUI::vftable)(DBCache *this);
// 7B8030: using guessed type int (__thiscall *gmExternalContainerUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CBAA0) --------------------------------------------------------  // acclient.c:253072
gmExternalContainerUI *__thiscall gmExternalContainerUI::DynamicCast(gmExternalContainerUI *this, unsigned int i_eType)
{
  gmExternalContainerUI *result; // eax@1

  result = this;
  if ( i_eType != 268435469 )
    result = (gmExternalContainerUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CBAD0) --------------------------------------------------------  // acclient.c:253089
int __thiscall gmExternalContainerUI::ListenToElementMessage(gmExternalContainerUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 && i_rMsg->idElement == 268435560 )
    ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004CBB00) --------------------------------------------------------  // acclient.c:253100
void __thiscall gmExternalContainerUI::RecvNotice_StopViewingObject(gmExternalContainerUI *this, unsigned int i_objid)
{
  if ( (HashSetData<UIElement *> *)i_objid == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4],
      0);
}

//----- (004CBB30) --------------------------------------------------------  // acclient.c:253109
void __thiscall gmExternalContainerUI::RecvNotice_ServerSaysMoveItem(gmExternalContainerUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  if ( (HashSetData<UIElement *> *)_itemID == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][205].m_hashNext
    && (HashSetData<UIElement *> *)_newContainer != this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1][205].m_hashNext )
    UIElement_ItemList::ItemList_OpenFirstContainer((UIElement_ItemList *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0]);
}

//----- (004CBB60) --------------------------------------------------------  // acclient.c:253117
bool __thiscall gmExternalContainerUI::DragItemAcceptable(gmExternalContainerUI *this, unsigned int _itemID, bool _silent)
{
  unsigned int v3; // eax@1
  bool result; // al@2
  HashBaseData<unsigned long> *v5; // esi@3
  HashBaseData<unsigned long> *v6; // eax@5
  int not_owner; // [sp+0h] [bp-4h]@1

  not_owner = (int)this;
  v3 = this->groundObjectID;
  if ( v3 )
  {
    v5 = ClientObjMaintSystem::GetWeenieObject(v3);
    if ( v5 )
    {
      v6 = ClientObjMaintSystem::GetWeenieObject(_itemID);
      if ( v6 )
      {
        not_owner = 1;
        result = ItemHolder::CheckHookStatus((ACCWeenieObject *)v6, (ACCWeenieObject *)v5, &not_owner) != 0;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004CBBD0) --------------------------------------------------------  // acclient.c:253156
void __thiscall gmExternalContainerUI::SetGroundObject(gmExternalContainerUI *this, unsigned int _groundObjectID)
{
  gmExternalContainerUI *v2; // esi@1
  unsigned int v3; // ST24_4@2
  ObjectRangeHandler *v4; // ST20_4@2
  CPlayerSystem *v5; // eax@2
  UIElement_ItemList *v6; // ecx@3
  HashBaseData<unsigned long> *v7; // eax@7
  long double _range; // ST08_8@8
  unsigned int v9; // ST04_4@8
  CPlayerSystem *v10; // eax@8

  v2 = this;
  if ( this->groundObjectID )
  {
    v3 = this->groundObjectID;
    v4 = (ObjectRangeHandler *)&this->vfptr;
    v5 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::UnregisterObjectRangeHandler(v5, v4, v3);
  }
  v6 = v2->m_topContainer;
  v2->groundObjectID = _groundObjectID;
  UIElement_ItemList::ItemList_Flush(v6);
  UIElement_ItemList::ItemList_AddItem(v2->m_topContainer, _groundObjectID);
  UIElement_ItemList::ItemList_SetParentContainer(v2->m_containerList, _groundObjectID, 0, 1);
  if ( !UIElement_ItemList::ItemList_OpenContainer(v2->m_topContainer, _groundObjectID, 1) )
    UIElement_ItemList::ItemList_SetParentContainer(v2->m_itemList, 0, 0, 1);
  if ( _groundObjectID )
  {
    v7 = ClientObjMaintSystem::GetWeenieObject(_groundObjectID);
    if ( v7 )
    {
      _range = *(float *)&v7[18].hash_next;
      v9 = v7->id;
      v10 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::RegisterObjectRangeHandler(v10, (ObjectRangeHandler *)&v2->vfptr, v9, _range, 1, 0, 1.0, 0.0);
    }
    v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 1u);
  }
  else
  {
    v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
  }
}

//----- (004CBCB0) --------------------------------------------------------  // acclient.c:253202
void __thiscall gmExternalContainerUI::CloseCurrentContainer(gmExternalContainerUI *this)
{
  gmExternalContainerUI *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ST08_4@2
  CPlayerSystem *v4; // eax@2
  UIElement_ItemList *v5; // ecx@2

  v1 = this;
  v2 = this->groundObjectID;
  if ( v2 )
  {
    ItemHolder::UseObject(v2, 0, 0);
    v3 = v1->groundObjectID;
    v4 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::UnregisterObjectRangeHandler(v4, (ObjectRangeHandler *)&v1->vfptr, v3);
    v5 = v1->m_topContainer;
    v1->groundObjectID = 0;
    UIElement_ItemList::ItemList_Flush(v5);
    UIElement_ItemList::ItemList_SetParentContainer(v1->m_containerList, 0, 0, 1);
  }
}

//----- (004CBD10) --------------------------------------------------------  // acclient.c:253226
void __thiscall gmExternalContainerUI::OnObjectRangeExit(gmExternalContainerUI *this, unsigned int _objectID)
{
  if ( (HashSetData<UIElement *> *)_objectID == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3],
      0);
}

//----- (004CBD40) --------------------------------------------------------  // acclient.c:253235
void __userpurge gmExternalContainerUI::gmExternalContainerUI(gmExternalContainerUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmExternalContainerUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->m_topContainer = 0;
  v4->m_containerList = 0;
  v4->m_itemList = 0;
  v4->groundObjectID = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmExternalContainerUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmExternalContainerUI::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&gmExternalContainerUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmExternalContainerUI::vftable;
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7B7D7C: using guessed type bool (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B7D80: using guessed type void (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, unsigned __int32);
// 7B7D88: using guessed type bool (__thiscall *gmExternalContainerUI::vftable)(DBCache *this);
// 7B8030: using guessed type int (__thiscall *gmExternalContainerUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CBDC0) --------------------------------------------------------  // acclient.c:253262
gmExternalContainerUI *__thiscall gmExternalContainerUI::scalar_deleting_destructor(gmExternalContainerUI *this, unsigned int a2)
{
  gmExternalContainerUI *v2; // esi@1

  v2 = this;
  gmExternalContainerUI::~gmExternalContainerUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CBDE0) --------------------------------------------------------  // acclient.c:253274
void __thiscall gmExternalContainerUI::PostInit(gmExternalContainerUI *this)
{
  gmExternalContainerUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@6
  int v5; // eax@9
  int v6; // eax@12
  UIElement *v7; // eax@15
  int v8; // eax@16
  UIElement *v9; // eax@18
  int v10; // eax@19
  UIElement *v11; // eax@21
  UIElement_ItemList *v12; // eax@22

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F9, (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100116u, (NoticeHandler *)v4);
    if ( v1 )
      v5 = (int)&v1->vfptr;
    else
      v5 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100008u, (NoticeHandler *)v5);
    if ( v1 )
      v6 = (int)&v1->vfptr;
    else
      v6 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD258, (NoticeHandler *)v6);
  }
  v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000064u);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435505);
  else
    v8 = 0;
  v1->m_topContainer = (UIElement_ItemList *)v8;
  v9 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000067u);
  if ( v9 )
    v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)268435505);
  else
    v10 = 0;
  v1->m_containerList = (UIElement_ItemList *)v10;
  v11 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000006Au);
  if ( v11 )
    v12 = (UIElement_ItemList *)v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)268435505);
  else
    v12 = 0;
  v1->m_itemList = v12;
  if ( v12 )
    UIElement_ItemList::RegisterItemListDragHandler(v12, (ItemListDragHandler *)&v1->vfptr);
  UIElement_ItemList::ItemList_SetChildList(v1->m_topContainer, v1->m_itemList);
  UIElement_ItemList::ItemList_SetChildList(v1->m_containerList, v1->m_itemList);
  v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 0);
}

//----- (004CBF20) --------------------------------------------------------  // acclient.c:253341
void __usercall gmExternalContainerUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmExternalContainerUI *v3; // eax@1

  v3 = (gmExternalContainerUI *)operator new(0x614u);
  if ( v3 )
    gmExternalContainerUI::gmExternalContainerUI(v3, a1, _layout, _full_desc);
}

//----- (004CBF50) --------------------------------------------------------  // acclient.c:253351
void __thiscall gmExternalContainerUI::OnVisibilityChanged(gmExternalContainerUI *this, bool i_bVisible)
{
  gmExternalContainerUI *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( !i_bVisible )
      gmExternalContainerUI::CloseCurrentContainer(v2);
  }
}

//----- (004CBF80) --------------------------------------------------------  // acclient.c:253365
char __thiscall gmExternalContainerUI::OnItemListDragOver(gmExternalContainerUI *this, UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && !(_dropFlags & 0xE) )
  {
    if ( gmExternalContainerUI::DragItemAcceptable((gmExternalContainerUI *)((char *)this - 1536), _dropItemID, 1) )
    {
      UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
      return 1;
    }
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000041u);
  }
  return 1;
}

//----- (004CBFD0) --------------------------------------------------------  // acclient.c:253380
void __thiscall gmExternalContainerUI::RecvNotice_SetGroundObject(gmExternalContainerUI *this, unsigned int i_objid)
{
  gmExternalContainerUI::SetGroundObject((gmExternalContainerUI *)((char *)this - 1528), i_objid);
}

//----- (004CBFE0) --------------------------------------------------------  // acclient.c:253386
void __cdecl gmExternalContainerUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000000Du,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmExternalContainerUI::Create);
}

//----- (006F2F20) --------------------------------------------------------  // acclient.c:775453
void _E91_91()
{
  outside_val_83 = 1000.0 + 1.0;
}

//----- (006F2F40) --------------------------------------------------------  // acclient.c:775459
void _E93_67()
{
  block_length_83 = 24.0 * 8.0;
}

//----- (006F2F60) --------------------------------------------------------  // acclient.c:775465
void _E95_67()
{
  half_square_length_83 = 24.0 * 0.5;
}

//----- (006F2F80) --------------------------------------------------------  // acclient.c:775471
int _E97_92()
{
  return atexit(nullsub_736);
}

//----- (006F2F90) --------------------------------------------------------  // acclient.c:775477
int _E100_85()
{
  return atexit(nullsub_737);
}

//----- (006F2FA0) --------------------------------------------------------  // acclient.c:775483
int _E103_77()
{
  return atexit(_E104_92);
}

//----- (006F2FB0) --------------------------------------------------------  // acclient.c:775489
void _E109_39()
{
  DEFAULT_VIEW_RADIUS_52 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2FD0) --------------------------------------------------------  // acclient.c:775495
void _E111_28()
{
  MIN_QUANTUM_52 = 1.0 / 30.0;
}

//----- (006F2FF0) --------------------------------------------------------  // acclient.c:775501
void _E113_16()
{
  MAX_QUANTUM_52 = 1.0 / 5.0;
}

//----- (006F3010) --------------------------------------------------------  // acclient.c:775507
void _E115_42()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_87, PFID_A8R8G8B8);
}

//----- (006F3020) --------------------------------------------------------  // acclient.c:775513
int _E117_30()
{
  return atexit(nullsub_734);
}

//----- (006F3030) --------------------------------------------------------  // acclient.c:775519
void _E121_41()
{
  LOWEST_DATA_RATE_89 = 1024;
}

//----- (006F3040) --------------------------------------------------------  // acclient.c:775525
void _E123_16()
{
  HIGHEST_DATA_RATE_89 = 0x7FFF;
}

//----- (006F3050) --------------------------------------------------------  // acclient.c:775531
int _E125_3()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_89;
  INITIAL_MAX_DATA_RATE_37 = LOWEST_DATA_RATE_89;
  return result;
}

//----- (006F3060) --------------------------------------------------------  // acclient.c:775541
int sub_6F3060()
{
  return atexit(nullsub_735);
}

