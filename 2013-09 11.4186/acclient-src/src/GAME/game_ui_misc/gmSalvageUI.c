/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSalvageUI
   Object     : GAME\game_ui_misc\gmSalvageUI.obj
   Functions  : 41
   Addresses  : 004CAF40 - 006F2F10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CAF40) --------------------------------------------------------  // acclient.c:252365
void __thiscall gmSalvageUI::~gmSalvageUI(gmSalvageUI *this)
{
  gmSalvageUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@1
  GlobalEventHandler *v3; // eax@3

  v1 = this;
  v2 = this->m_salvageList;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmSalvageUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmSalvageUI::vftable;
  v1->vfptr = (ItemListDragHandlerVtbl *)&gmSalvageUI::vftable;
  if ( v2 )
    UIElement_ItemList::UnregisterItemListDragHandler(v2);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)&v1->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B772C: using guessed type bool (__thiscall *gmSalvageUI::vftable)(gmSalvageUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B7730: using guessed type bool (__thiscall *gmSalvageUI::vftable)(DBCache *this);
// 7B79D8: using guessed type int (__thiscall *gmSalvageUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CAFA0) --------------------------------------------------------  // acclient.c:252391
gmSalvageUI *__thiscall gmSalvageUI::DynamicCast(gmSalvageUI *this, unsigned int i_eType)
{
  gmSalvageUI *result; // eax@1

  result = this;
  if ( i_eType != 268435473 )
    result = (gmSalvageUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CAFC0) --------------------------------------------------------  // acclient.c:252402
signed int gmSalvageUI::GetUIElementType()
{
  return 268435473;
}

//----- (004CAFD0) --------------------------------------------------------  // acclient.c:252408
void __thiscall gmSalvageUI::RemoveItem(gmSalvageUI *this, unsigned int _itemID)
{
  gmSalvageUI *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@2
  UIElement *v4; // ecx@5

  v2 = this;
  if ( this->m_salvageList )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v3 )
      ACCWeenieObject::SetTradeState((ACCWeenieObject *)v3, 0);
    UIElement_ItemList::ItemList_DeleteItem(v2->m_salvageList, _itemID);
    if ( !UIElement_ItemList::GetNumUIItems(v2->m_salvageList) )
    {
      v4 = v2->m_salvageButton;
      v2->m_material = 0;
      if ( v4 )
        ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(13);
    }
  }
}

//----- (004CB040) --------------------------------------------------------  // acclient.c:252432
bool __thiscall gmSalvageUI::IsItemSuitable(gmSalvageUI *this, ACCWeenieObject *item)
{
  gmSalvageUI *v2; // esi@1
  bool result; // al@2
  int v4; // ebx@3
  CPlayerSystem *v5; // eax@6
  unsigned int v6; // eax@7

  v2 = this;
  if ( item )
  {
    v4 = item->pwd._material_type;
    if ( TinkeringSystem::IsValidMaterialType(item->pwd._material_type)
      && item->pwd._structure < 0x64
      && ((v5 = CPlayerSystem::GetPlayerSystem(),
           (unsigned __int8)PlayerModule::SalvageMultiple((PlayerModule *)&v5->playerModule.vfptr))
       || (v6 = v2->m_material) == 0
       || v4 == v6) )
      result = ~BYTE3(item->pwd._bitfield) & 1;
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CB0B0) --------------------------------------------------------  // acclient.c:252462
void __userpurge gmSalvageUI::gmSalvageUI(gmSalvageUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSalvageUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->m_salvageList = 0;
  v4->m_salvageButton = 0;
  v4->m_toolID = 0;
  v4->m_material = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSalvageUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSalvageUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmSalvageUI::vftable;
}
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B772C: using guessed type bool (__thiscall *gmSalvageUI::vftable)(gmSalvageUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B7730: using guessed type bool (__thiscall *gmSalvageUI::vftable)(DBCache *this);
// 7B79D8: using guessed type int (__thiscall *gmSalvageUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CB120) --------------------------------------------------------  // acclient.c:252485
gmSalvageUI *__thiscall gmSalvageUI::vector_deleting_destructor(gmSalvageUI *this, unsigned int a2)
{
  gmSalvageUI *v2; // esi@1

  v2 = this;
  gmSalvageUI::~gmSalvageUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CB140) --------------------------------------------------------  // acclient.c:252497
void __thiscall gmSalvageUI::PostInit(gmSalvageUI *this)
{
  gmSalvageUI *v1; // edi@1
  UIElement *v2; // eax@1
  UIElement_ItemList *v3; // eax@2
  GlobalEventHandler *v4; // eax@6
  GlobalEventHandler *v5; // esi@6
  int v6; // edi@7

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000074u);
  if ( v2 )
    v3 = (UIElement_ItemList *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435505);
  else
    v3 = 0;
  v1->m_salvageList = v3;
  if ( v3 )
    UIElement_ItemList::RegisterItemListDragHandler(v3, (ItemListDragHandler *)&v1->vfptr);
  v1->m_salvageButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000076u);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  v5 = v4;
  if ( v4 )
  {
    v6 = (int)&v1->vfptr;
    v4->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v4,
      (unsigned int)((char *)nullsub_1891 + 1),
      (NoticeHandler *)v6);
    v5->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v5,
      (unsigned int)((char *)nullsub_1891 + 2),
      (NoticeHandler *)v6);
    v5->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v5, (unsigned int)&byte_4DD224, (NoticeHandler *)v6);
    v5->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v5, 5100118u, (NoticeHandler *)v6);
  }
}
// 4DD221: using guessed type int __stdcall nullsub_1891(int);
// 4DD224: using guessed type char byte_4DD224;

//----- (004CB1E0) --------------------------------------------------------  // acclient.c:252538
void __usercall gmSalvageUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSalvageUI *v3; // eax@1

  v3 = (gmSalvageUI *)operator new(0x610u);
  if ( v3 )
    gmSalvageUI::gmSalvageUI(v3, a1, _layout, _full_desc);
}

//----- (004CB210) --------------------------------------------------------  // acclient.c:252548
void __thiscall gmSalvageUI::RecvNotice_RemoveSalvageItem(gmSalvageUI *this, unsigned int i_itemID)
{
  gmSalvageUI::RemoveItem((gmSalvageUI *)((char *)this - 1528), i_itemID);
}

//----- (004CB220) --------------------------------------------------------  // acclient.c:252554
void __thiscall gmSalvageUI::RecvNotice_ItemListBeginDrag(gmSalvageUI *this, UIElement *i_itemList, int i_slotNum)
{
  gmSalvageUI *v3; // esi@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v4; // ecx@1
  UIElement *v5; // eax@2
  int v6; // eax@3
  unsigned int v7; // eax@4

  v3 = this;
  v4 = this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
  if ( (UIElement *)v4 == i_itemList )
  {
    v5 = UIElement_ListBox::GetItem((UIElement_ListBox *)v4, i_slotNum);
    if ( v5 )
    {
      v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 1532);
        if ( v7 )
          gmSalvageUI::RemoveItem((gmSalvageUI *)((char *)v3 - 1528), v7);
      }
    }
  }
}

//----- (004CB2D0) --------------------------------------------------------  // acclient.c:252613
char __thiscall gmSalvageUI::_AddItem(gmSalvageUI *this, ACCWeenieObject *item)
{
  gmSalvageUI *v2; // esi@1
  UIElement_ItemList *v3; // ecx@1
  char result; // al@2
  UIElement *v5; // ecx@7

  v2 = this;
  v3 = this->m_salvageList;
  if ( v3 )
  {
    if ( UIElement_ItemList::ItemList_IsInList(v3, item->id) || !gmSalvageUI::IsItemSuitable(v2, item) )
    {
      result = 0;
    }
    else
    {
      ACCWeenieObject::SetTradeState(item, 1);
      UIElement_ItemList::ItemList_AddItem(v2->m_salvageList, item->id);
      if ( UIElement_ItemList::GetNumUIItems(v2->m_salvageList) == 1 )
      {
        v2->m_material = item->pwd._material_type;
        v5 = v2->m_salvageButton;
        if ( v5 )
          ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CB360) --------------------------------------------------------  // acclient.c:252650
void __cdecl gmSalvageUI::Register()
{
  UIElement::RegisterElementClass(0x10000011u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSalvageUI::Create);
}

//----- (004CB380) --------------------------------------------------------  // acclient.c:252656
void __thiscall gmSalvageUI::OpenSalvagePanel(gmSalvageUI *this, unsigned int i_toolID)
{
  gmSalvageUI *v2; // esi@1
  UIElement_ItemList *v3; // ST00_4@1
  UIElement *v4; // ecx@1

  v2 = this;
  v3 = this->m_salvageList;
  this->m_toolID = i_toolID;
  gmSalvageUI::ClearAllTradeStates(v3);
  UIElement_ItemList::ItemList_Flush(v2->m_salvageList);
  v4 = v2->m_salvageButton;
  v2->m_material = 0;
  if ( v4 )
    ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(13);
  v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 1u);
}

//----- (004CB3E0) --------------------------------------------------------  // acclient.c:252675
void __thiscall gmSalvageUI::CloseSalvagePanel(gmSalvageUI *this)
{
  gmSalvageUI *v1; // esi@1
  UIElement_ItemList *v2; // ST00_4@1
  UIElement *v3; // ecx@1

  v1 = this;
  v2 = this->m_salvageList;
  this->m_toolID = 0;
  gmSalvageUI::ClearAllTradeStates(v2);
  UIElement_ItemList::ItemList_Flush(v1->m_salvageList);
  v3 = v1->m_salvageButton;
  v1->m_material = 0;
  if ( v3 )
    ((void (__stdcall *)(signed int))v3->vfptr[13].__vecDelDtor)(13);
}

//----- (004CB430) --------------------------------------------------------  // acclient.c:252693
char __thiscall gmSalvageUI::AddNewItem(gmSalvageUI *this, unsigned int _itemID)
{
  gmSalvageUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  ACCWeenieObject *v4; // esi@1
  char result; // al@2

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v4 = (ACCWeenieObject *)v3;
  if ( v3 )
  {
    if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v3) <= 0 )
      result = gmSalvageUI::_AddItem(v2, v4);
    else
      result = gmSalvageUI::_AddContainedItems(v2, v4);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CB470) --------------------------------------------------------  // acclient.c:252718
void __thiscall gmSalvageUI::OnVisibilityChanged(gmSalvageUI *this, bool i_bVisible)
{
  gmSalvageUI *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( !i_bVisible )
      gmSalvageUI::CloseSalvagePanel(v2);
  }
}

//----- (004CB4A0) --------------------------------------------------------  // acclient.c:252732
void __thiscall gmSalvageUI::RecvNotice_OpenSalvagePanel(gmSalvageUI *this, unsigned int i_toolID)
{
  gmSalvageUI::OpenSalvagePanel((gmSalvageUI *)((char *)this - 1528), i_toolID);
}

//----- (004CB4B0) --------------------------------------------------------  // acclient.c:252738
void __thiscall gmSalvageUI::RecvNotice_AddSalvageItem(gmSalvageUI *this, unsigned int i_itemID)
{
  gmSalvageUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  ACCWeenieObject *v4; // esi@1

  v2 = (gmSalvageUI *)((char *)this - 1528);
  v3 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  v4 = (ACCWeenieObject *)v3;
  if ( v3 )
  {
    if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v3) <= 0 )
      gmSalvageUI::_AddItem(v2, v4);
    else
      gmSalvageUI::_AddContainedItems(v2, v4);
  }
}

//----- (004CB4F0) --------------------------------------------------------  // acclient.c:252757
char __thiscall gmSalvageUI::_AddContainedItems(gmSalvageUI *this, ACCWeenieObject *container)
{
  gmSalvageUI *v2; // ebx@1
  PStringBase<unsigned short> *v3; // eax@1
  char *v4; // esi@1
  IDList *v5; // eax@4
  IDList *v6; // edi@4
  int i; // ebp@5
  unsigned int v8; // eax@6
  HashBaseData<unsigned long> *v9; // eax@6
  ACCWeenieObject *v10; // esi@6
  char *v11; // esi@11
  char v12; // al@14
  char *v13; // esi@15
  PStringBase<unsigned short> errorText; // [sp+10h] [bp-98h]@1
  PStringBase<unsigned short> result; // [sp+14h] [bp-94h]@1
  StringInfo siError; // [sp+18h] [bp-90h]@4

  v2 = this;
  v3 = ACCWeenieObject::GetObjectNameWide(container, &result, NAME_APPROPRIATE, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Adding contents of %s", v3->m_charbuffer);
  v4 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  StringInfo::StringInfo(&siError);
  StringInfo::SetLiteralValue(&siError, &errorText, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  v5 = ACCWeenieObject::GetContainedItemsList(container);
  v6 = v5;
  if ( v5 )
  {
    IDList::SetCurToNum(v5, 0);
    for ( i = 0; i < v6->numIDs; ++i )
    {
      v8 = IDList::GetCurID(v6);
      v9 = ClientObjMaintSystem::GetWeenieObject(v8);
      v10 = (ACCWeenieObject *)v9;
      if ( v9 )
      {
        if ( ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v9) <= 0 )
          gmSalvageUI::_AddItem(v2, v10);
        else
          gmSalvageUI::_AddContainedItems(v2, v10);
      }
      IDList::SetCurToNext(v6);
    }
    StringInfo::~StringInfo(&siError);
    v11 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    v12 = 1;
  }
  else
  {
    StringInfo::~StringInfo(&siError);
    v13 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v12 = 0;
  }
  return v12;
}

//----- (004CB650) --------------------------------------------------------  // acclient.c:252824
bool __thiscall gmSalvageUI::DragItemAcceptable(gmSalvageUI *this, unsigned int _itemID, bool _silent)
{
  gmSalvageUI *v3; // edi@1
  HashBaseData<unsigned long> *v4; // eax@1
  ACCWeenieObject *v5; // esi@1
  char *v6; // esi@4
  bool result; // al@8
  UIElement_ItemList *v8; // ecx@9
  PStringBase<unsigned short> _value; // [sp+Ch] [bp-94h]@4
  StringInfo siError; // [sp+10h] [bp-90h]@4

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v5 = (ACCWeenieObject *)v4;
  if ( !v4 )
    return 0;
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    if ( !_silent )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can only salvage items that you own!");
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
  v8 = v3->m_salvageList;
  if ( !v8 || UIElement_ItemList::ItemList_IsInList(v8, _itemID) )
    return 0;
  if ( ACCWeenieObject::GetNumContainedItems(v5) <= 0 )
    result = gmSalvageUI::IsItemSuitable(v3, v5);
  else
    result = 1;
  return result;
}

//----- (004CB740) --------------------------------------------------------  // acclient.c:252869
char __thiscall gmSalvageUI::OnItemListDragOver(gmSalvageUI *this, UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropItemID && !(_dropFlags & 0xE) )
  {
    if ( gmSalvageUI::DragItemAcceptable((gmSalvageUI *)((char *)this - 1532), _dropItemID, 1) )
    {
      UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
      return 1;
    }
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000041u);
  }
  return 1;
}

//----- (004CB790) --------------------------------------------------------  // acclient.c:252884
bool __thiscall gmSalvageUI::AcceptDragObject(gmSalvageUI *this, unsigned int _itemID)
{
  gmSalvageUI *v2; // esi@1
  bool result; // al@1

  v2 = this;
  result = gmSalvageUI::DragItemAcceptable(this, _itemID, 0);
  if ( result )
  {
    if ( v2->m_salvageList )
      gmSalvageUI::AddNewItem(v2, _itemID);
    result = 1;
  }
  return result;
}

//----- (004CB7D0) --------------------------------------------------------  // acclient.c:252901
void __thiscall gmSalvageUI::HandleDropRelease(gmSalvageUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  UIElement *v4; // eax@1
  gmSalvageUI *v5; // edi@1
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
      if ( UIElement::IsAncestorOfMe(v4, (UIElement *)&this->m_salvageList->vfptr) )
      {
        UIElement_ItemList::InqDropIconInfo(v3, (unsigned int *)&i_rMsg, &dropSpellID, &dropFlags);
        if ( i_rMsg )
        {
          if ( !(dropFlags & 0xE) )
            gmSalvageUI::AcceptDragObject(v5, (unsigned int)i_rMsg);
        }
      }
    }
  }
}

//----- (004CB840) --------------------------------------------------------  // acclient.c:252932
char __thiscall gmSalvageUI::Salvage(gmSalvageUI *this)
{
  gmSalvageUI *v1; // esi@1
  UIElement_ItemList *v2; // ecx@1
  unsigned int i; // edi@2
  UIElement *v4; // eax@3
  int v5; // eax@4
  unsigned int v6; // eax@5
  UIElement *v7; // ecx@10
  unsigned int val; // [sp+8h] [bp-14h]@6
  PackableList<unsigned long> loot; // [sp+Ch] [bp-10h]@2

  v1 = this;
  v2 = this->m_salvageList;
  if ( !v2 )
    return 0;
  loot.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  loot.head = 0;
  loot.tail = 0;
  loot.curNum = 0;
  for ( i = UIElement_ItemList::GetNumUIItems(v2) - 1; (i & 0x80000000) == 0; --i )
  {
    v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->m_salvageList->vfptr, i);
    if ( v4 )
    {
      v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
      if ( v5 )
      {
        v6 = *(_DWORD *)(v5 + 1532);
        if ( v6 )
        {
          val = v6;
          PackableList<unsigned long>::InsertTail(&loot, &val);
        }
      }
    }
  }
  if ( !loot.head || !v1->m_toolID )
  {
    loot.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
    PackableList<unsigned long>::Flush(&loot);
    return 0;
  }
  gmSalvageUI::ClearAllTradeStates(v1->m_salvageList);
  CM_Inventory::Event_CreateTinkeringTool(v1->m_toolID, &loot);
  UIElement_ItemList::ItemList_Flush(v1->m_salvageList);
  v7 = v1->m_salvageButton;
  v1->m_material = 0;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
  loot.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(&loot);
  return 1;
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (004CB950) --------------------------------------------------------  // acclient.c:252989
int __thiscall gmSalvageUI::ListenToElementMessage(gmSalvageUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmSalvageUI *v3; // esi@1
  UIElement *v4; // eax@4
  int v5; // eax@5

  v2 = i_rMsg->idMessage;
  v3 = this;
  switch ( v2 )
  {
    case 0x1Cu:
      if ( this->m_salvageList )
      {
        if ( UIElement::IsAncestorOfMe(i_rMsg->pElement, (UIElement *)&this->m_salvageList->vfptr) )
        {
          v4 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v3->m_salvageList->vfptr);
          if ( v4 )
          {
            v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
            if ( v5 )
            {
              if ( i_rMsg->dwParam1 == 10 )
              {
                gmSalvageUI::RemoveItem(v3, *(_DWORD *)(v5 + 1532));
                return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
              }
            }
          }
        }
      }
      break;
    case 1u:
      if ( i_rMsg->idElement == 268435576 )
      {
        ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
      if ( i_rMsg->idElement == 268435574 )
      {
        gmSalvageUI::Salvage(this);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
      break;
    case 0x15u:
      gmSalvageUI::HandleDropRelease(this, i_rMsg);
      break;
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (006F2DD0) --------------------------------------------------------  // acclient.c:775359
void _E91_90()
{
  outside_val_82 = 1000.0 + 1.0;
}

//----- (006F2DF0) --------------------------------------------------------  // acclient.c:775365
void _E93_66()
{
  block_length_82 = 24.0 * 8.0;
}

//----- (006F2E10) --------------------------------------------------------  // acclient.c:775371
void _E95_66()
{
  half_square_length_82 = 24.0 * 0.5;
}

//----- (006F2E30) --------------------------------------------------------  // acclient.c:775377
int _E97_91()
{
  return atexit(nullsub_741);
}

//----- (006F2E40) --------------------------------------------------------  // acclient.c:775383
int _E100_84()
{
  return atexit(nullsub_742);
}

//----- (006F2E50) --------------------------------------------------------  // acclient.c:775389
int _E103_76()
{
  return atexit(_E104_91);
}

//----- (006F2E60) --------------------------------------------------------  // acclient.c:775395
void _E109_38()
{
  DEFAULT_VIEW_RADIUS_51 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2E80) --------------------------------------------------------  // acclient.c:775401
void _E111_27()
{
  MIN_QUANTUM_51 = 1.0 / 30.0;
}

//----- (006F2EA0) --------------------------------------------------------  // acclient.c:775407
void _E113_15()
{
  MAX_QUANTUM_51 = 1.0 / 5.0;
}

//----- (006F2EC0) --------------------------------------------------------  // acclient.c:775413
void _E115_41()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_86, PFID_A8R8G8B8);
}

//----- (006F2ED0) --------------------------------------------------------  // acclient.c:775419
void _E118_46()
{
  LOWEST_DATA_RATE_88 = 1024;
}

//----- (006F2EE0) --------------------------------------------------------  // acclient.c:775425
void _E120_34()
{
  HIGHEST_DATA_RATE_88 = 0x7FFF;
}

//----- (006F2EF0) --------------------------------------------------------  // acclient.c:775431
int _E122_20()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_88;
  INITIAL_MAX_DATA_RATE_36 = LOWEST_DATA_RATE_88;
  return result;
}

//----- (006F2F00) --------------------------------------------------------  // acclient.c:775441
int _E124_43()
{
  return atexit(_E125_49);
}

//----- (006F2F10) --------------------------------------------------------  // acclient.c:775447
int sub_6F2F10()
{
  return atexit(nullsub_740);
}

