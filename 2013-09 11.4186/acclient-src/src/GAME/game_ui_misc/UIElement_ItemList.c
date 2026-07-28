/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_ItemList
   Object     : GAME\game_ui_misc\UIElement_ItemList.obj
   Functions  : 81
   Addresses  : 004E24A0 - 00763110 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E24A0) --------------------------------------------------------  // acclient.c:272392
BOOL __thiscall UIElement_ItemList::IsAliasList(UIElement_ItemList *this)
{
  return this->vendorItemList || this->salvageList || this->shortcutList;
}

//----- (004E24D0) --------------------------------------------------------  // acclient.c:272398
void __stdcall UIElement_ItemList::HandleTargetedUseLeftClick(UIElement_UIItem *_item)
{
  Target_Mode v2; // ecx@3
  Target_Mode v3; // ST04_4@4
  unsigned int v4; // ST00_4@4
  unsigned int v5; // esi@5
  Target_Mode v6; // ST04_4@6
  ClientUISystem *v7; // eax@6

  if ( _item && ClientUISystem::GetUISystem() )
  {
    v2 = ClientUISystem::GetUISystem()->targetMode;
    if ( _item->spellID )
    {
      v3 = v2;
      v4 = _item->spellID;
      ClientUISystem::GetUISystem();
      ClientUISystem::ExecuteTargetModeForSpell(v4, v3);
    }
    else
    {
      v5 = _item->itemID;
      if ( v5 )
      {
        v6 = v2;
        v7 = ClientUISystem::GetUISystem();
        ClientUISystem::ExecuteTargetModeForItem(v7, v5, v6);
      }
    }
  }
}

//----- (004E2530) --------------------------------------------------------  // acclient.c:272431
void __thiscall UIElement_ItemList::ItemList_SetChildList(UIElement_ItemList *this, UIElement_ItemList *_childList)
{
  this->childList = _childList;
}

//----- (004E2540) --------------------------------------------------------  // acclient.c:272437
void __thiscall UIElement_ItemList::RecvNotice_BeginDrag(UIElement_ItemList *this, unsigned int i_itemID, unsigned int i_spellID, bool i_bIsAlias)
{
  UIElement_ItemList *v4; // esi@1

  v4 = this;
  if ( BYTE1(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]) && i_itemID && !i_bIsAlias )
    UIListener::RegisterForGlobalMessage(
      (UIListener *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[21],
      3u);
  if ( BYTE2(v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12]) )
  {
    if ( i_spellID )
      UIListener::RegisterForGlobalMessage(
        (UIListener *)&v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[21],
        3u);
  }
}

//----- (004E2590) --------------------------------------------------------  // acclient.c:272456
void __thiscall UIElement_ItemList::RegisterItemListDragHandler(UIElement_ItemList *this, ItemListDragHandler *_handler)
{
  this->m_dragHandler = _handler;
}

//----- (004E25A0) --------------------------------------------------------  // acclient.c:272462
void __thiscall UIElement_ItemList::UnregisterItemListDragHandler(UIElement_ItemList *this)
{
  this->m_dragHandler = 0;
}

//----- (004E25B0) --------------------------------------------------------  // acclient.c:272468
void __thiscall UIElement_ItemList::SetAsPendingItem(UIElement_ItemList *this, UIElement_UIItem *_pendingItem)
{
  this->m_pendingItem = _pendingItem;
}

//----- (004E25C0) --------------------------------------------------------  // acclient.c:272474
void __thiscall UIElement_ItemList::DeletePendingItem(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  UIElement_UIItem *v2; // ecx@1

  v1 = this;
  v2 = this->m_pendingItem;
  if ( v2 )
  {
    UIElement_UIItem::Clear_UIItem(v2);
    UIElement_UIItem::UIItem_SetState(v1->m_pendingItem, 0x1000001Cu);
    v1->m_pendingItem = 0;
  }
}

//----- (004E25F0) --------------------------------------------------------  // acclient.c:272490
int __thiscall UIElement_ItemList::WhatDragScrollRegion(UIElement_ItemList *this, int xPos, int yPos)
{
  UIElement_ItemList *v3; // esi@1
  int result; // eax@2

  v3 = this;
  if ( !UIElement::IsVisible((UIElement *)&this->vfptr) )
    return 0;
  if ( v3->m_dragScrollVertical
    && xPos >= (signed int)UIRegion::GetScreenX0((UIRegion *)&v3->vfptr)
    && xPos <= (signed int)UIRegion::GetScreenX1((UIRegion *)&v3->vfptr) )
  {
    if ( yPos < (signed int)UIRegion::GetScreenY0((UIRegion *)&v3->vfptr)
      && yPos >= (signed int)(UIRegion::GetScreenY0((UIRegion *)&v3->vfptr) - v3->m_dragScrollMarginHeight) )
      return 1;
    if ( yPos > (signed int)UIRegion::GetScreenY1((UIRegion *)&v3->vfptr)
      && yPos <= (signed int)(v3->m_dragScrollMarginHeight + UIRegion::GetScreenY1((UIRegion *)&v3->vfptr)) )
      return 2;
  }
  if ( !v3->m_dragScrollHorizontal
    || yPos < (signed int)UIRegion::GetScreenY0((UIRegion *)&v3->vfptr)
    || yPos > (signed int)UIRegion::GetScreenY1((UIRegion *)&v3->vfptr) )
    goto LABEL_24;
  if ( xPos < (signed int)UIRegion::GetScreenX0((UIRegion *)&v3->vfptr)
    && xPos >= (signed int)(UIRegion::GetScreenX0((UIRegion *)&v3->vfptr) - v3->m_dragScrollMarginWidth) )
    return 3;
  if ( xPos > (signed int)UIRegion::GetScreenX1((UIRegion *)&v3->vfptr)
    && xPos <= (signed int)(v3->m_dragScrollMarginWidth + UIRegion::GetScreenX1((UIRegion *)&v3->vfptr)) )
    result = 4;
  else
LABEL_24:
    result = 0;
  return result;
}

//----- (004E26F0) --------------------------------------------------------  // acclient.c:272526
void __cdecl UIElement_ItemList::InqDropIconInfo(UIElement *_dropIcon, unsigned int *_itemID, unsigned int *_spellID, DropItemFlags *_flags)
{
  DropItemFlags *v4; // eax@1
  unsigned int *v5; // ebp@1
  UIElement *v6; // esi@1
  bool v7; // zf@1
  unsigned int *v8; // edi@1
  IInputActionCallbackVtbl *v9; // edx@2
  IInputActionCallbackVtbl *v10; // edx@5
  int v11; // edx@8
  IInputActionCallbackVtbl *v12; // eax@8
  IInputActionCallbackVtbl *v13; // edx@11
  IInputActionCallbackVtbl *v14; // edx@14
  IInputActionCallbackVtbl *v15; // edx@17
  char v16; // al@17
  BasePropertyValue *v17; // esi@17
  BasePropertyDesc *v18; // ecx@21
  unsigned int v19; // edx@21
  int v20; // edx@25
  BasePropertyDesc *v21; // ecx@29
  unsigned int v22; // edx@29
  BasePropertyValue *v23; // ecx@33
  unsigned int v24; // edx@33
  BasePropertyDesc *v25; // ecx@37
  unsigned int v26; // edx@37
  BasePropertyValue *v27; // ecx@41
  unsigned int v28; // edx@41
  BasePropertyDesc *v29; // ecx@45
  unsigned int v30; // edx@45
  BasePropertyValue *v31; // ecx@49
  unsigned int v32; // edx@49
  BasePropertyDesc *v33; // ecx@53
  unsigned int v34; // edx@53
  BasePropertyValue *v35; // ecx@57
  unsigned int v36; // edx@57
  BasePropertyDesc *v37; // ecx@61
  unsigned int v38; // edx@61
  BasePropertyValue *v39; // ecx@65
  unsigned int v40; // edx@65
  bool isContainer; // [sp+49h] [bp-39h]@8
  int dropItemID; // [sp+4Ah] [bp-38h]@2
  int dropSpellID; // [sp+4Eh] [bp-34h]@2
  BaseProperty salvageProp; // [sp+52h] [bp-30h]@17
  BaseProperty shortcutProp; // [sp+5Ah] [bp-28h]@14
  BaseProperty vendorProp; // [sp+62h] [bp-20h]@11
  BaseProperty containerProp; // [sp+6Ah] [bp-18h]@8
  BaseProperty spellIDProp; // [sp+72h] [bp-10h]@5
  BaseProperty itemIDProp; // [sp+7Ah] [bp-8h]@2

  v4 = _flags;
  v5 = _spellID;
  v6 = _dropIcon;
  v7 = _dropIcon == 0;
  v8 = _itemID;
  *_itemID = 0;
  *v5 = 0;
  *v4 = 0;
  if ( !v7 )
  {
    v9 = v6->vfptr;
    dropItemID = 0;
    dropSpellID = 0;
    itemIDProp.m_pcPropertyDesc = 0;
    itemIDProp.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v9[17].OnAction)(
                            v6,
                            268435471,
                            &itemIDProp)
      && itemIDProp.m_pcPropertyValue )
      ((void (__stdcall *)(int *))itemIDProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&dropItemID);
    v10 = v6->vfptr;
    spellIDProp.m_pcPropertyDesc = 0;
    spellIDProp.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v10[17].OnAction)(
                            v6,
                            268435472,
                            &spellIDProp)
      && spellIDProp.m_pcPropertyValue )
      ((void (__stdcall *)(int *))spellIDProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&dropSpellID);
    v11 = dropSpellID;
    *v8 = dropItemID;
    *v5 = v11;
    v12 = v6->vfptr;
    isContainer = 0;
    LOBYTE(_dropIcon) = 0;
    LOBYTE(_spellID) = 0;
    LOBYTE(_itemID) = 0;
    containerProp.m_pcPropertyDesc = 0;
    containerProp.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v12[17].OnAction)(
                            v6,
                            268435473,
                            &containerProp)
      && containerProp.m_pcPropertyValue )
      ((void (__stdcall *)(bool *))containerProp.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&isContainer);
    v13 = v6->vfptr;
    vendorProp.m_pcPropertyDesc = 0;
    vendorProp.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v13[17].OnAction)(
                            v6,
                            268435475,
                            &vendorProp)
      && vendorProp.m_pcPropertyValue )
      ((void (__stdcall *)(unsigned int **))vendorProp.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&_spellID);
    v14 = v6->vfptr;
    shortcutProp.m_pcPropertyDesc = 0;
    shortcutProp.m_pcPropertyValue = 0;
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v14[17].OnAction)(
                            v6,
                            268435474,
                            &shortcutProp)
      && shortcutProp.m_pcPropertyValue )
      ((void (__stdcall *)(UIElement **))shortcutProp.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&_dropIcon);
    v15 = v6->vfptr;
    salvageProp.m_pcPropertyDesc = 0;
    salvageProp.m_pcPropertyValue = 0;
    v16 = ((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v15[17].OnAction)(v6, 268435476, &salvageProp);
    v17 = salvageProp.m_pcPropertyValue;
    if ( v16 && salvageProp.m_pcPropertyValue )
    {
      salvageProp.m_pcPropertyValue->vfptr[28].__vecDelDtor(
        (ReferenceCountTemplate<1048576,1> *)salvageProp.m_pcPropertyValue,
        (unsigned int)&_itemID);
      v17 = salvageProp.m_pcPropertyValue;
    }
    *_flags = (isContainer != 0) | ((_BYTE)_dropIcon != 0 ? 4 : 0) | ((_BYTE)_spellID != 0 ? 2 : 0) | ((_BYTE)_itemID != 0 ? 8 : 0);
    if ( (_DWORD)salvageProp.m_pcPropertyDesc )
    {
      v18 = salvageProp.m_pcPropertyDesc;
      v19 = salvageProp.m_pcPropertyDesc->m_cRef - 1;
      salvageProp.m_pcPropertyDesc->m_cRef = v19;
      if ( !v19 )
        ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
      v17 = salvageProp.m_pcPropertyValue;
      salvageProp.m_pcPropertyDesc = 0;
    }
    if ( v17 )
    {
      v20 = v17->m_cRef - 1;
      v17->m_cRef = v20;
      if ( !v20 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      salvageProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)shortcutProp.m_pcPropertyDesc )
    {
      v21 = shortcutProp.m_pcPropertyDesc;
      v22 = shortcutProp.m_pcPropertyDesc->m_cRef - 1;
      shortcutProp.m_pcPropertyDesc->m_cRef = v22;
      if ( !v22 )
        ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
      shortcutProp.m_pcPropertyDesc = 0;
    }
    if ( shortcutProp.m_pcPropertyValue )
    {
      v23 = shortcutProp.m_pcPropertyValue;
      v24 = shortcutProp.m_pcPropertyValue->m_cRef - 1;
      shortcutProp.m_pcPropertyValue->m_cRef = v24;
      if ( !v24 )
        ((void (__stdcall *)(signed int))v23->vfptr->__vecDelDtor)(1);
      shortcutProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)vendorProp.m_pcPropertyDesc )
    {
      v25 = vendorProp.m_pcPropertyDesc;
      v26 = vendorProp.m_pcPropertyDesc->m_cRef - 1;
      vendorProp.m_pcPropertyDesc->m_cRef = v26;
      if ( !v26 )
        ((void (__stdcall *)(signed int))v25->vfptr->__vecDelDtor)(1);
      vendorProp.m_pcPropertyDesc = 0;
    }
    if ( vendorProp.m_pcPropertyValue )
    {
      v27 = vendorProp.m_pcPropertyValue;
      v28 = vendorProp.m_pcPropertyValue->m_cRef - 1;
      vendorProp.m_pcPropertyValue->m_cRef = v28;
      if ( !v28 )
        ((void (__stdcall *)(signed int))v27->vfptr->__vecDelDtor)(1);
      vendorProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)containerProp.m_pcPropertyDesc )
    {
      v29 = containerProp.m_pcPropertyDesc;
      v30 = containerProp.m_pcPropertyDesc->m_cRef - 1;
      containerProp.m_pcPropertyDesc->m_cRef = v30;
      if ( !v30 )
        ((void (__stdcall *)(signed int))v29->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyDesc = 0;
    }
    if ( containerProp.m_pcPropertyValue )
    {
      v31 = containerProp.m_pcPropertyValue;
      v32 = containerProp.m_pcPropertyValue->m_cRef - 1;
      containerProp.m_pcPropertyValue->m_cRef = v32;
      if ( !v32 )
        ((void (__stdcall *)(signed int))v31->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)spellIDProp.m_pcPropertyDesc )
    {
      v33 = spellIDProp.m_pcPropertyDesc;
      v34 = spellIDProp.m_pcPropertyDesc->m_cRef - 1;
      spellIDProp.m_pcPropertyDesc->m_cRef = v34;
      if ( !v34 )
        ((void (__stdcall *)(signed int))v33->vfptr->__vecDelDtor)(1);
      spellIDProp.m_pcPropertyDesc = 0;
    }
    if ( spellIDProp.m_pcPropertyValue )
    {
      v35 = spellIDProp.m_pcPropertyValue;
      v36 = spellIDProp.m_pcPropertyValue->m_cRef - 1;
      spellIDProp.m_pcPropertyValue->m_cRef = v36;
      if ( !v36 )
        ((void (__stdcall *)(signed int))v35->vfptr->__vecDelDtor)(1);
      spellIDProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      v37 = itemIDProp.m_pcPropertyDesc;
      v38 = itemIDProp.m_pcPropertyDesc->m_cRef - 1;
      itemIDProp.m_pcPropertyDesc->m_cRef = v38;
      if ( !v38 )
        ((void (__stdcall *)(signed int))v37->vfptr->__vecDelDtor)(1);
      itemIDProp.m_pcPropertyDesc = 0;
    }
    if ( itemIDProp.m_pcPropertyValue )
    {
      v39 = itemIDProp.m_pcPropertyValue;
      v40 = itemIDProp.m_pcPropertyValue->m_cRef - 1;
      itemIDProp.m_pcPropertyValue->m_cRef = v40;
      if ( !v40 )
        ((void (__stdcall *)(signed int))v39->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004E2A50) --------------------------------------------------------  // acclient.c:272763
char __thiscall UIElement_ItemList::PrepareDragIcon(UIElement_ItemList *this, UIElement_UIItem *_item)
{
  UIRegion *v2; // esi@1
  HashBaseData<unsigned long> *v3; // ebx@3
  Graphic *v4; // eax@5
  Graphic *v5; // eax@5
  unsigned int v6; // ebx@8
  int v7; // edi@10
  int v8; // eax@11
  BasePropertyDesc *v9; // ecx@19
  unsigned int v10; // edx@19
  BasePropertyValue *v11; // ecx@23
  unsigned int v12; // edx@23
  BasePropertyDesc *v13; // ecx@27
  unsigned int v14; // edx@27
  BasePropertyValue *v15; // ecx@31
  unsigned int v16; // edx@31
  BasePropertyDesc *v17; // ecx@35
  unsigned int v18; // edx@35
  BasePropertyValue *v19; // ecx@39
  unsigned int v20; // edx@39
  BasePropertyDesc *v21; // ecx@43
  unsigned int v22; // edx@43
  BasePropertyValue *v23; // ecx@47
  unsigned int v24; // edx@47
  BasePropertyDesc *v25; // ecx@51
  unsigned int v26; // edx@51
  BasePropertyValue *v27; // ecx@55
  unsigned int v28; // edx@55
  unsigned int v30; // ST10_4@59
  ClientMagicSystem *v31; // eax@59
  Graphic *v32; // ebx@59
  Graphic *v33; // eax@60
  Graphic *v34; // eax@61
  unsigned int v35; // edi@64
  UIElement_ItemList *v36; // [sp+24h] [bp-30h]@1
  Graphic *v37; // [sp+28h] [bp-2Ch]@0
  BaseProperty salvageProp; // [sp+2Ch] [bp-28h]@16
  BaseProperty shortcutProp; // [sp+34h] [bp-20h]@14
  BaseProperty vendorProp; // [sp+3Ch] [bp-18h]@12
  BaseProperty spellIDProp; // [sp+44h] [bp-10h]@10
  BaseProperty itemIDProp; // [sp+4Ch] [bp-8h]@8

  v2 = (UIRegion *)&_item->m_dragIcon->vfptr;
  v36 = this;
  if ( !v2 )
    return 0;
  if ( _item->itemID )
  {
    UIRegion::ClearImage(v2);
    v3 = ClientObjMaintSystem::GetWeenieObject(_item->itemID);
    if ( v3 )
    {
      UIRegion::SetBlitMode(v2, Blit_3Alpha);
      v37 = (Graphic *)operator new(0xCu);
      if ( v37 )
      {
        v4 = ACCWeenieObject::GetDragIcon((ACCWeenieObject *)v3);
        Graphic::Graphic(v37, v4);
      }
      else
      {
        v5 = 0;
      }
      UIRegion::SetImage(v2, v5);
    }
    itemIDProp.m_pcPropertyDesc = 0;
    itemIDProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&itemIDProp, 0x1000000Fu);
    v6 = _item->itemID;
    if ( itemIDProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&itemIDProp);
      ((void (__stdcall *)(unsigned int))itemIDProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v6);
    }
    ((void (__thiscall *)(UIRegion *, BaseProperty *))v2->vfptr[17].OnLoseFocus)(v2, &itemIDProp);
    spellIDProp.m_pcPropertyDesc = 0;
    spellIDProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&spellIDProp, 0x10000011u);
    v7 = _item->isContainer;
    if ( spellIDProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&spellIDProp);
      LOBYTE(v8) = v7 != 0;
      ((void (__stdcall *)(int))spellIDProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v8);
    }
    ((void (__thiscall *)(UIRegion *, BaseProperty *))v2->vfptr[17].OnLoseFocus)(v2, &spellIDProp);
    vendorProp.m_pcPropertyDesc = 0;
    vendorProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&vendorProp, 0x10000013u);
    LOBYTE(v37) = v36->vendorItemList;
    if ( vendorProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&vendorProp);
      ((void (__stdcall *)(Graphic *))vendorProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v37);
    }
    ((void (__thiscall *)(UIRegion *, BaseProperty *))v2->vfptr[17].OnLoseFocus)(v2, &vendorProp);
    shortcutProp.m_pcPropertyDesc = 0;
    shortcutProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&shortcutProp, 0x10000012u);
    LOBYTE(v37) = v36->shortcutList;
    if ( shortcutProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&shortcutProp);
      ((void (__stdcall *)(Graphic *))shortcutProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v37);
    }
    ((void (__thiscall *)(_DWORD, _DWORD))v2->vfptr[17].OnLoseFocus)(v2, &shortcutProp);
    salvageProp.m_pcPropertyDesc = 0;
    salvageProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&salvageProp, 0x10000014u);
    LOBYTE(v37) = v36->salvageList;
    if ( salvageProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&salvageProp);
      ((void (__stdcall *)(Graphic *))salvageProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v37);
    }
    ((void (__thiscall *)(_DWORD, _DWORD))v2->vfptr[17].OnLoseFocus)(v2, &salvageProp);
    if ( (_DWORD)salvageProp.m_pcPropertyDesc )
    {
      v9 = salvageProp.m_pcPropertyDesc;
      v10 = salvageProp.m_pcPropertyDesc->m_cRef - 1;
      salvageProp.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      salvageProp.m_pcPropertyDesc = 0;
    }
    if ( salvageProp.m_pcPropertyValue )
    {
      v11 = salvageProp.m_pcPropertyValue;
      v12 = salvageProp.m_pcPropertyValue->m_cRef - 1;
      salvageProp.m_pcPropertyValue->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      salvageProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)shortcutProp.m_pcPropertyDesc )
    {
      v13 = shortcutProp.m_pcPropertyDesc;
      v14 = shortcutProp.m_pcPropertyDesc->m_cRef - 1;
      shortcutProp.m_pcPropertyDesc->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      shortcutProp.m_pcPropertyDesc = 0;
    }
    if ( shortcutProp.m_pcPropertyValue )
    {
      v15 = shortcutProp.m_pcPropertyValue;
      v16 = shortcutProp.m_pcPropertyValue->m_cRef - 1;
      shortcutProp.m_pcPropertyValue->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      shortcutProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)vendorProp.m_pcPropertyDesc )
    {
      v17 = vendorProp.m_pcPropertyDesc;
      v18 = vendorProp.m_pcPropertyDesc->m_cRef - 1;
      vendorProp.m_pcPropertyDesc->m_cRef = v18;
      if ( !v18 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      vendorProp.m_pcPropertyDesc = 0;
    }
    if ( vendorProp.m_pcPropertyValue )
    {
      v19 = vendorProp.m_pcPropertyValue;
      v20 = vendorProp.m_pcPropertyValue->m_cRef - 1;
      vendorProp.m_pcPropertyValue->m_cRef = v20;
      if ( !v20 )
        ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
      vendorProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)spellIDProp.m_pcPropertyDesc )
    {
      v21 = spellIDProp.m_pcPropertyDesc;
      v22 = spellIDProp.m_pcPropertyDesc->m_cRef - 1;
      spellIDProp.m_pcPropertyDesc->m_cRef = v22;
      if ( !v22 )
        ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
      spellIDProp.m_pcPropertyDesc = 0;
    }
    if ( spellIDProp.m_pcPropertyValue )
    {
      v23 = spellIDProp.m_pcPropertyValue;
      v24 = spellIDProp.m_pcPropertyValue->m_cRef - 1;
      spellIDProp.m_pcPropertyValue->m_cRef = v24;
      if ( !v24 )
        ((void (__stdcall *)(signed int))v23->vfptr->__vecDelDtor)(1);
      spellIDProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      v25 = itemIDProp.m_pcPropertyDesc;
      v26 = itemIDProp.m_pcPropertyDesc->m_cRef - 1;
      itemIDProp.m_pcPropertyDesc->m_cRef = v26;
      if ( !v26 )
        ((void (__stdcall *)(signed int))v25->vfptr->__vecDelDtor)(1);
      itemIDProp.m_pcPropertyDesc = 0;
    }
    if ( itemIDProp.m_pcPropertyValue )
    {
      v27 = itemIDProp.m_pcPropertyValue;
      v28 = itemIDProp.m_pcPropertyValue->m_cRef - 1;
      itemIDProp.m_pcPropertyValue->m_cRef = v28;
      if ( !v28 )
        ((void (__stdcall *)(signed int))v27->vfptr->__vecDelDtor)(1);
    }
    return 1;
  }
  if ( !_item->spellID )
    return 0;
  UIRegion::ClearImage(v2);
  v30 = _item->spellID;
  v31 = ClientMagicSystem::GetMagicSystem();
  v32 = ClientMagicSystem::GetSpellIcon(v31, v30);
  if ( v32 )
  {
    UIRegion::SetBlitMode(v2, Blit_3Alpha);
    v33 = (Graphic *)operator new(0xCu);
    if ( v33 )
      Graphic::Graphic(v33, v32);
    else
      v34 = 0;
    UIRegion::SetImage(v2, v34);
  }
  spellIDProp.m_pcPropertyDesc = 0;
  spellIDProp.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&spellIDProp, 0x10000010u);
  v35 = _item->spellID;
  if ( spellIDProp.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&spellIDProp);
    ((void (__stdcall *)(unsigned int))spellIDProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v35);
  }
  ((void (__thiscall *)(_DWORD, _DWORD))v2->vfptr[17].OnLoseFocus)(v2, &spellIDProp);
  itemIDProp.m_pcPropertyDesc = 0;
  itemIDProp.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&itemIDProp, 0x10000012u);
  LOBYTE(v37) = v36->shortcutList;
  if ( itemIDProp.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&itemIDProp);
    ((void (__stdcall *)(Graphic *))itemIDProp.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v37);
  }
  ((void (__thiscall *)(_DWORD, _DWORD))v2->vfptr[17].OnLoseFocus)(v2, &itemIDProp);
  BaseProperty::~BaseProperty(&itemIDProp);
  BaseProperty::~BaseProperty(&spellIDProp);
  return 1;
}

//----- (004E2ED0) --------------------------------------------------------  // acclient.c:273013
int __thiscall UIElement_ItemList::ItemList_IsInList(UIElement_ItemList *this, unsigned int _itemID)
{
  UIElement_ItemList *v2; // edi@1
  unsigned int v3; // esi@1
  UIElement *v4; // ecx@2
  int v5; // eax@3
  int result; // eax@6

  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    while ( 1 )
    {
      v4 = v2->m_listItems.m_data[v3];
      if ( v4 )
      {
        v5 = ((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506);
        if ( v5 )
        {
          if ( *(_DWORD *)(v5 + 1532) == _itemID )
            break;
        }
      }
      ++v3;
      if ( v3 >= v2->m_listItems.m_num )
        goto LABEL_6;
    }
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (004E2F30) --------------------------------------------------------  // acclient.c:273052
int __thiscall UIElement_ItemList::ItemList_GetItem(UIElement_ItemList *this, unsigned int i_iidItem)
{
  UIElement_ItemList *v2; // edi@1
  unsigned int v3; // esi@1
  UIElement *v4; // ecx@2
  int result; // eax@3

  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    while ( 1 )
    {
      v4 = v2->m_listItems.m_data[v3];
      if ( v4 )
      {
        result = ((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506);
        if ( result )
        {
          if ( *(_DWORD *)(result + 1532) == i_iidItem )
            break;
        }
      }
      ++v3;
      if ( v3 >= v2->m_listItems.m_num )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (004E2F80) --------------------------------------------------------  // acclient.c:273089
int __thiscall UIElement_ItemList::GetNumUIItems(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // edi@1
  int v2; // ebx@1
  unsigned int v3; // esi@1
  UIElement *v4; // eax@2
  UIElement_UIItem *v5; // eax@3

  v1 = this;
  v2 = 0;
  v3 = 0;
  if ( (signed int)this->m_listItems.m_num > 0 )
  {
    do
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v3);
      if ( v4 )
      {
        v5 = (UIElement_UIItem *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          if ( UIElement_UIItem::UIItem_GetState(v5) != (UIElement *)268435484 )
            ++v2;
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < (signed int)v1->m_listItems.m_num );
  }
  return v2;
}

//----- (004E2FE0) --------------------------------------------------------  // acclient.c:273122
void __thiscall UIElement_ItemList::ItemList_SetSelectedItem(UIElement_ItemList *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  UIElement_ItemList *v3; // ebx@1
  unsigned int v4; // edi@1
  UIElement *v5; // ecx@2
  int v6; // eax@3
  int v7; // esi@3

  v3 = this;
  v4 = 0;
  if ( this->m_listItems.m_num )
  {
    do
    {
      v5 = v3->m_listItems.m_data[v4];
      if ( v5 )
      {
        v6 = ((int (__stdcall *)(signed int))v5->vfptr[12].OnAction)(268435506);
        v7 = v6;
        if ( v6 )
        {
          if ( !*(_DWORD *)(v6 + 1536) )
          {
            if ( *(_DWORD *)(v6 + 1532) == _oldSelectedID )
              UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v6, 0);
            if ( *(_DWORD *)(v7 + 1532) == _selectedID )
            {
              if ( _selectedID )
                UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v7, 1);
            }
          }
        }
      }
      ++v4;
    }
    while ( v4 < v3->m_listItems.m_num );
  }
}

//----- (004E3070) --------------------------------------------------------  // acclient.c:273162
void __thiscall UIElement_ItemList::UpdateOpenContainerIndicator(UIElement_ItemList *this, unsigned int _containerID)
{
  UIElement_ItemList *v2; // edi@1
  unsigned int v3; // esi@1
  UIElement *v4; // ecx@2
  int v5; // eax@3

  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    do
    {
      v4 = v2->m_listItems.m_data[v3];
      if ( v4 )
      {
        v5 = ((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506);
        if ( v5 )
        {
          if ( _containerID && *(_DWORD *)(v5 + 1532) == _containerID )
            UIElement_UIItem::SetOpenContainerState((UIElement_UIItem *)v5, 1);
          else
            UIElement_UIItem::SetOpenContainerState((UIElement_UIItem *)v5, 0);
        }
      }
      ++v3;
    }
    while ( v3 < v2->m_listItems.m_num );
  }
}

//----- (004E30D0) --------------------------------------------------------  // acclient.c:273194
void __thiscall UIElement_ItemList::TrackDragScrolling(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  int v2; // edi@1
  int v3; // eax@1
  int v4; // ecx@1
  double v5; // st7@11

  v1 = this;
  v2 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
  v3 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
  v4 = UIElement_ItemList::WhatDragScrollRegion(v1, v2, v3);
  if ( v1->m_inDragScrollRegion )
  {
    if ( v4 )
    {
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) > v1->m_nextDragScrollTime )
      {
        v1->m_nextDragScrollTime = v1->m_dragScrollDelay + COERCE_DOUBLE(Timer::cur_time.Cmd);
        switch ( v4 )
        {
          case 1:
            UIElement_ListBox::ScrollToY(
              (UIElement_ListBox *)&v1->vfptr,
              v1->m_iScrollableY - v1->m_dragScrollJumpDistance);
            break;
          case 2:
            UIElement_ListBox::ScrollToY(
              (UIElement_ListBox *)&v1->vfptr,
              v1->m_iScrollableY + v1->m_dragScrollJumpDistance);
            break;
          case 3:
            UIElement_ListBox::ScrollToX(
              (UIElement_ListBox *)&v1->vfptr,
              v1->m_iScrollableX - v1->m_dragScrollJumpDistance);
            break;
          case 4:
            UIElement_ListBox::ScrollToX(
              (UIElement_ListBox *)&v1->vfptr,
              v1->m_iScrollableX + v1->m_dragScrollJumpDistance);
            break;
          default:
            return;
        }
      }
    }
    else
    {
      v1->m_inDragScrollRegion = 0;
    }
  }
  else if ( v4 )
  {
    v5 = v1->m_dragScrollDelay;
    v1->m_inDragScrollRegion = 1;
    v1->m_nextDragScrollTime = v5 + COERCE_DOUBLE(Timer::cur_time.Cmd);
  }
}

//----- (004E31E0) --------------------------------------------------------  // acclient.c:273254
char __thiscall UIElement_ItemList::InqAvailableProperties(UIElement_ItemList *this, AvailablePropertySet *_set)
{
  char v2; // bl@1
  char result; // al@4

  v2 = 1;
  if ( !UIElement_ListBox::InqAvailableProperties((UIElement_ListBox *)&this->vfptr, _set) )
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

//----- (004E3220) --------------------------------------------------------  // acclient.c:273276
void __thiscall UIElement_ItemList::ListenToGlobalMessage(UIElement_ItemList *this, unsigned int messageID, int data_int)
{
  if ( messageID == 3 )
  {
    if ( UIElementManager::s_pInstance->m_dragElement )
    {
      UIElement_ItemList::TrackDragScrolling(this);
    }
    else
    {
      this->m_inDragScrollRegion = 0;
      UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    }
  }
}

//----- (004E3250) --------------------------------------------------------  // acclient.c:273293
void __thiscall UIElement_ItemList::HandleSingleSelection(UIElement_ItemList *this, UIElement_UIItem *_item)
{
  UIElement_ListBox *v2; // ebx@1
  int v3; // ebp@1
  unsigned int v4; // edi@1
  UIElement *v5; // eax@2
  int v6; // esi@3

  v2 = (UIElement_ListBox *)this;
  v3 = UIElement_ItemList::GetNumUIItems(this);
  v4 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v5 = UIElement_ListBox::GetItem(v2, v4);
      if ( v5 )
      {
        v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435506);
        if ( v6 )
        {
          if ( *(_DWORD *)(v6 + 1532) == _item->itemID && (UIElement_UIItem *)v6 != _item )
          {
            UIElement_UIItem::SetSelectableState((UIElement_UIItem *)v6, 0);
            UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v6, 0);
          }
        }
      }
      ++v4;
    }
    while ( (signed int)v4 < v3 );
  }
  UIElement_UIItem::SetSelectableState(_item, 1);
  UIElement_UIItem::SetSelectedState(_item, 1);
}

//----- (004E32D0) --------------------------------------------------------  // acclient.c:273330
void __thiscall UIElement_ItemList::ItemList_BeginDrag(UIElement_ItemList *this, int x, int y)
{
  UIElement_ItemList *v3; // esi@1
  int v4; // ST0C_4@2
  unsigned int v5; // eax@2
  UIElement *v6; // eax@2
  UIElement_UIItem *v7; // eax@3
  UIElement_UIItem *v8; // edi@3
  int v9; // eax@14
  int v10; // eax@16
  UIElement_ItemList *v11; // [sp-2h] [bp-4h]@1

  v11 = this;
  v3 = this;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x10000016u, (bool *)&v11 + 3);
  if ( BYTE3(v11) )
  {
    v4 = y - UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
    v5 = UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
    v6 = UIElement_ListBox::GetItemAtPoint((UIElement_ListBox *)&v3->vfptr, x - v5, v4);
    if ( v6 )
    {
      v7 = (UIElement_UIItem *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
      v8 = v7;
      if ( v7 )
      {
        if ( UIElement_ItemList::PrepareDragIcon(v3, v7) )
        {
          if ( !v8->selected )
            ACCWeenieObject::SetSelectedObject(v8->itemID, 0);
          if ( !v3->vendorItemList && !v3->salvageList && !v3->shortcutList )
            UIElement_UIItem::SetWaitingState(v8, 1);
          UIElementManager::StartDragandDrop(UIElementManager::s_pInstance, v8->m_dragIcon, 16, 16);
          v9 = v3->vendorItemList || v3->salvageList || v3->shortcutList;
          CM_Item::SendNotice_BeginDrag(v8->itemID, v8->spellID, v9);
          v10 = UIElement_ListBox::WhatNum((UIElement_ListBox *)&v3->vfptr, (UIElement *)&v8->vfptr);
          CM_Item::SendNotice_ItemListBeginDrag((UIElement *)&v3->vfptr, v10);
        }
      }
    }
  }
}

//----- (004E3400) --------------------------------------------------------  // acclient.c:273374
void __thiscall UIElement_ItemList::ItemList_DragOver(UIElement_ItemList *this, UIElement *_dragElement, UIElement_UIItem *_catchElement)
{
  UIElement_ItemList *v3; // esi@1
  UIElement_UIItem *v4; // edi@2
  ItemListDragHandler *v5; // ecx@3
  char v6; // bl@3
  UIElement_UIItem *v7; // ebp@3
  bool v8; // al@10
  HashBaseData<unsigned long> *v9; // eax@15
  unsigned int dropSpellID; // [sp+0h] [bp-4h]@1

  dropSpellID = (unsigned int)this;
  v3 = this;
  if ( _dragElement )
  {
    v4 = _catchElement;
    if ( _catchElement )
    {
      UIElement_ItemList::InqDropIconInfo(
        _dragElement,
        (unsigned int *)&_catchElement,
        &dropSpellID,
        (DropItemFlags *)&_dragElement);
      v5 = v3->m_dragHandler;
      v6 = (char)_dragElement;
      v7 = _catchElement;
      if ( (!v5
         || !(unsigned __int8)((int (__stdcall *)(UIElement_UIItem *, UIElement_UIItem *, unsigned int, UIElement *))v5->vfptr->OnItemListDragOver)(
                                v4,
                                _catchElement,
                                dropSpellID,
                                _dragElement))
        && !v3->vendorItemList
        && !v3->salvageList
        && !v3->shortcutList
        && v7
        && !(v6 & 0xE) )
      {
        v8 = v3->containerList;
        if ( v6 & 1 )
        {
          if ( !v8 )
          {
            UIElement_UIItem::SetDragAcceptState(v4, 0x10000041u);
            return;
          }
          goto LABEL_19;
        }
        if ( !v8 )
        {
LABEL_19:
          UIElement_UIItem::SetDragAcceptState(v4, 0x10000040u);
          return;
        }
        if ( UIElement_UIItem::UIItem_GetState(v4) != (UIElement *)268435484
          && (v9 = ClientObjMaintSystem::GetWeenieObject(v4->itemID)) != 0
          && ACCWeenieObject::GetNumEmptyItemSlots((ACCWeenieObject *)v9) )
          UIElement_UIItem::SetDragAcceptState(v4, 0x10000046u);
        else
          UIElement_UIItem::SetDragAcceptState(v4, 0x10000041u);
      }
    }
  }
}

//----- (004E3530) --------------------------------------------------------  // acclient.c:273440
bool __thiscall UIElement_ItemList::InternalDeleteItem(UIElement_ItemList *this, UIElement_UIItem *_item)
{
  UIElement_ItemList *v2; // esi@1
  unsigned int v3; // eax@1
  bool v4; // bl@1

  v2 = this;
  v3 = UIElement_ListBox::RemoveItem((UIElement_ListBox *)&this->vfptr, (UIElement *)&_item->vfptr);
  v4 = v3 != 0;
  if ( v3 )
    List<PFileNode *>::push_back(&v2->m_listUIItemCache, &_item);
  return v4;
}

//----- (004E3560) --------------------------------------------------------  // acclient.c:273455
void __thiscall UIElement_ItemList::RecvNotice_SetSelectedItem(UIElement_ItemList *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  UIElement_ItemList::ItemList_SetSelectedItem((UIElement_ItemList *)((char *)this - 1640), _oldSelectedID, _selectedID);
}

//----- (004E3570) --------------------------------------------------------  // acclient.c:273461
int __thiscall UIElement_ItemList::InternalCreateItem(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  ListNode<UIElement_UIItem *> *v2; // eax@1
  ListNode<UIElement_UIItem *> *v3; // ecx@2
  UIElement_UIItem *v4; // edi@5
  int result; // eax@6
  int v6; // edi@7
  ElementDesc *v7; // eax@8
  UIElement_UIItem *v8; // esi@9
  unsigned int elementID; // [sp+0h] [bp-4h]@1

  elementID = (unsigned int)this;
  v1 = this;
  v2 = this->m_listUIItemCache._head;
  if ( v2
    && ((v3 = v2->next, (v1->m_listUIItemCache._head = v3) == 0) ? (v1->m_listUIItemCache._tail = 0) : (v3->prev = 0),
        v4 = v2->data,
        operator delete(v2),
        --v1->m_listUIItemCache._num_elements,
        v4) )
  {
    UIElement_UIItem::UIItem_SetState(v4, 0x1000001Cu);
    UIElement_UIItem::SetDragAcceptState(v4, 0x1000003Fu);
    result = (int)v4;
  }
  else
  {
    UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000000Eu, &elementID);
    result = DBObj::GetByEnum(268435512, 5, 0x23u);
    v6 = result;
    if ( result )
    {
      v7 = UIElementManager::CreateChildElement(
             UIElementManager::s_pInstance,
             (UIElement *)&v1->vfptr,
             (LayoutDesc *)result,
             elementID);
      if ( v7 )
      {
        v8 = (UIElement_UIItem *)(*(int (__thiscall **)(ElementDesc *, signed int))&v7->vfptr[4].gap4[0])(v7, 268435506);
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
        result = (int)v8;
      }
      else
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
        result = 0;
      }
    }
  }
  return result;
}

//----- (004E3650) --------------------------------------------------------  // acclient.c:273516
void __thiscall UIElement_ItemList::ItemList_SetParentList(UIElement_ItemList *this, UIElement_ItemList *_newParent)
{
  UIElement_ItemList *v2; // esi@1
  UIElement_ItemList *v3; // ecx@1

  v2 = this;
  v3 = this->parentList;
  if ( v3 )
  {
    if ( v3 == v2 )
    {
      v2->parentList = _newParent;
    }
    else
    {
      if ( v3 != _newParent )
      {
        v3->openItemID = 0;
        UIElement_ItemList::UpdateOpenContainerIndicator(v3, 0);
      }
      v2->parentList = _newParent;
    }
  }
  else
  {
    v2->parentList = _newParent;
  }
}

//----- (004E36B0) --------------------------------------------------------  // acclient.c:273546
void __thiscall UIElement_ItemList::ItemList_AddEmptySlot(UIElement_ItemList *this, int _pos)
{
  UIElement_ListBox *v2; // edi@1
  int v3; // eax@1
  UIElement_UIItem *v4; // esi@1

  v2 = (UIElement_ListBox *)this;
  v3 = UIElement_ItemList::InternalCreateItem(this);
  v4 = (UIElement_UIItem *)v3;
  if ( v3 )
  {
    UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v3);
    UIElement_UIItem::UIItem_SetState(v4, 0x1000001Cu);
  }
  if ( _pos == -1 )
    UIElement_ListBox::AddItem(v2, (UIElement *)&v4->vfptr);
  else
    UIElement_ListBox::InsertItem(v2, (UIElement *)&v4->vfptr, _pos);
}

//----- (004E3700) --------------------------------------------------------  // acclient.c:273567
void __thiscall UIElement_ItemList::UpdateEmptySlots(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  int v2; // ebx@3
  signed int v3; // edi@4
  int v4; // ecx@4
  int v5; // ebx@6
  int v6; // eax@7
  UIElement_UIItem *v7; // edi@7
  int v8; // eax@12
  int v9; // ebx@12
  int i; // ebp@12
  UIElement *v11; // eax@13
  UIElement_UIItem *v12; // eax@14
  UIElement_UIItem *v13; // edi@14
  UIElement *v14; // eax@18
  UIElement_UIItem *v15; // eax@19
  int v16; // eax@21
  UIElement_UIItem *v17; // edi@21
  unsigned int v18; // ebp@25
  signed int j; // ebx@25
  UIElement *v20; // eax@26
  UIElement_UIItem *v21; // eax@27
  UIElement_UIItem *v22; // edi@27
  bool bNeedsAnEmptySlot; // [sp+7h] [bp-Dh]@17
  int fixedListSize; // [sp+8h] [bp-Ch]@2
  int maxCols; // [sp+Ch] [bp-8h]@3
  int maxRows; // [sp+10h] [bp-4h]@3

  v1 = this;
  if ( UIElement::IsVisible((UIElement *)&this->vfptr) )
  {
    UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x10000015u, &fixedListSize);
    if ( fixedListSize == -1 )
    {
      v2 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
      UIRegion::GetHeight((UIRegion *)&v1->vfptr);
      UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x5Fu, &maxCols);
      UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x60u, &maxRows);
      if ( maxCols == -1 )
      {
        v3 = v1->m_cellW;
        v4 = v3 * v1->m_listItems.m_num;
        if ( v4 >= v2 )
        {
          if ( v4 > v2 )
          {
            v8 = (v3 - v2 + v4 - 1) / v3;
            v9 = 0;
            for ( i = v8; v9 < i; ++v9 )
            {
              v11 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v1->m_listItems.m_num - 1);
              if ( !v11 )
                break;
              v12 = (UIElement_UIItem *)v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)268435506);
              v13 = v12;
              if ( !v12 )
                break;
              if ( UIElement_UIItem::UIItem_GetState(v12) != (UIElement *)268435484 )
                break;
              UIElement_ItemList::InternalDeleteItem(v1, v13);
            }
          }
        }
        else if ( (v2 - v4) / v3 > 0 )
        {
          v5 = (v2 - v4) / v3;
          do
          {
            v6 = UIElement_ItemList::InternalCreateItem(v1);
            v7 = (UIElement_UIItem *)v6;
            if ( v6 )
            {
              UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v6);
              UIElement_UIItem::UIItem_SetState(v7, 0x1000001Cu);
            }
            UIElement_ListBox::AddItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)&v7->vfptr);
            --v5;
          }
          while ( v5 );
        }
        bNeedsAnEmptySlot = 0;
        UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000017u, &bNeedsAnEmptySlot);
        if ( bNeedsAnEmptySlot )
        {
          v14 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v1->m_listItems.m_num - 1);
          if ( v14 )
          {
            v15 = (UIElement_UIItem *)v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)268435506);
            if ( v15 )
            {
              if ( UIElement_UIItem::UIItem_GetState(v15) != (UIElement *)268435484 )
              {
                v16 = UIElement_ItemList::InternalCreateItem(v1);
                v17 = (UIElement_UIItem *)v16;
                if ( v16 )
                {
                  UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v16);
                  UIElement_UIItem::UIItem_SetState(v17, 0x1000001Cu);
                }
                UIElement_ListBox::AddItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)&v17->vfptr);
              }
            }
          }
        }
      }
      else if ( maxRows == -1 )
      {
        v18 = v1->m_listItems.m_num;
        for ( j = 0; j < (signed int)v18; ++j )
        {
          v20 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v1->m_listItems.m_num - 1);
          if ( !v20 )
            break;
          v21 = (UIElement_UIItem *)v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)268435506);
          v22 = v21;
          if ( !v21 )
            break;
          if ( UIElement_UIItem::UIItem_GetState(v21) != (UIElement *)268435484 )
            break;
          UIElement_ItemList::InternalDeleteItem(v1, v22);
        }
      }
    }
  }
}

//----- (004E3910) --------------------------------------------------------  // acclient.c:273695
void __thiscall UIElement_ItemList::UpdateFixedSlots(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // edi@1
  unsigned int v2; // eax@2
  int v3; // ebx@4
  int v4; // eax@5
  UIElement_UIItem *v5; // esi@5
  int v6; // eax@10
  int v7; // esi@11
  UIElement *v8; // eax@12
  UIElement_UIItem *v9; // eax@13
  int fixedListSize; // [sp+4h] [bp-8h]@1
  UIElement_UIItem *val; // [sp+8h] [bp-4h]@14

  v1 = this;
  UIElement::GetAttribute_Int((UIElement *)&this->vfptr, 0x10000015u, &fixedListSize);
  if ( fixedListSize != -1 )
  {
    v2 = v1->m_listItems.m_num;
    if ( (signed int)v2 >= fixedListSize )
    {
      if ( (signed int)v2 > fixedListSize )
      {
        v6 = v2 - fixedListSize;
        if ( v6 > 0 )
        {
          v7 = v6;
          do
          {
            v8 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v1->m_listItems.m_num - 1);
            if ( v8 )
            {
              v9 = (UIElement_UIItem *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506);
              if ( v9 )
              {
                val = v9;
                if ( UIElement_ListBox::RemoveItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)&v9->vfptr) )
                  List<PFileNode *>::push_back(&v1->m_listUIItemCache, &val);
              }
            }
            --v7;
          }
          while ( v7 );
        }
      }
    }
    else if ( (signed int)(fixedListSize - v2) > 0 )
    {
      v3 = fixedListSize - v2;
      do
      {
        v4 = UIElement_ItemList::InternalCreateItem(v1);
        v5 = (UIElement_UIItem *)v4;
        if ( v4 )
        {
          UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v4);
          UIElement_UIItem::UIItem_SetState(v5, 0x1000001Cu);
        }
        UIElement_ListBox::AddItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)&v5->vfptr);
        --v3;
      }
      while ( v3 );
    }
  }
}

//----- (004E39E0) --------------------------------------------------------  // acclient.c:273762
void __thiscall UIElement_ItemList::ItemList_UpdateContainerListSize(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  HashBaseData<unsigned long> *v2; // eax@2
  int v3; // ecx@4
  unsigned int v4; // eax@8

  v1 = this;
  if ( this->parentContainerID )
  {
    v2 = ClientObjMaintSystem::GetWeenieObject(this->parentContainerID);
    if ( v2 )
    {
      if ( v1->containerList )
        v3 = (int)v2[17].vfptr;
      else
        v3 = v2[16].id;
      if ( !((unsigned int)v2[21].hash_next & 1) )
      {
        v4 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
        if ( v1->parentContainerID != v4 )
        {
          v3 = 0;
LABEL_12:
          UIElement::SetAttribute_Int((UIElement *)&v1->vfptr, 0x10000015u, v3);
          UIElement_ItemList::UpdateFixedSlots(v1);
          return;
        }
      }
      if ( v3 >= 0 )
        goto LABEL_12;
      UIElement::SetAttribute_Int((UIElement *)&v1->vfptr, 0x10000015u, -1);
      UIElement_ItemList::UpdateEmptySlots(v1);
    }
  }
}

//----- (004E3A70) --------------------------------------------------------  // acclient.c:273800
List<UIElement_UIItem *> *__thiscall List<UIElement_UIItem *>::scalar_deleting_destructor(List<UIElement_UIItem *> *this, unsigned int a2)
{
  List<UIElement_UIItem *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<UIElement_UIItem *>Vtbl *)&List<UIElement_UIItem *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF8F4: using guessed type int (__thiscall *List<UIElement_UIItem *>::vftable)(void *, char);

//----- (004E3AA0) --------------------------------------------------------  // acclient.c:273814
void __userpurge UIElement_ItemList::UIElement_ItemList(UIElement_ItemList *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_ItemList *v4; // esi@1

  v4 = this;
  UIElement_ListBox::UIElement_ListBox((UIElement_ListBox *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->parentContainerID = 0;
  v4->openItemID = 0;
  v4->removedItemID = 0;
  v4->childList = 0;
  v4->parentList = 0;
  v4->containerList = 0;
  v4->vendorItemList = 0;
  v4->shortcutList = 0;
  v4->salvageList = 0;
  v4->m_pendingItem = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_ItemList::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&UIElement_ItemList::vftable;
  v4->m_cellW = 32;
  v4->m_cellH = 32;
  v4->m_listUIItemCache._head = 0;
  v4->m_listUIItemCache._tail = 0;
  v4->m_listUIItemCache._num_elements = 0;
  v4->m_listUIItemCache.vfptr = (List<UIElement_UIItem *>Vtbl *)&List<UIElement_UIItem *>::vftable;
  v4->m_dragHandler = 0;
  v4->m_singleSelection = 0;
  v4->m_dragScrollItemScrolling = 0;
  v4->m_dragScrollSpellScrolling = 0;
  v4->m_dragScrollVertical = 0;
  v4->m_dragScrollHorizontal = 0;
  v4->m_dragScrollMarginWidth = 0;
  v4->m_dragScrollMarginHeight = 0;
  v4->m_inDragScrollRegion = 0;
  LODWORD(v4->m_nextDragScrollTime) = 0;
  HIDWORD(v4->m_nextDragScrollTime) = 0;
  v4->m_dragScrollJumpDistance = 1;
  LODWORD(v4->m_dragScrollDelay) = 1065353216;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7BF8F4: using guessed type int (__thiscall *List<UIElement_UIItem *>::vftable)(void *, char);
// 7BF8F8: using guessed type bool (__thiscall *UIElement_ItemList::vftable)(DBCache *this);
// 7BFBA0: using guessed type int (__thiscall *UIElement_ItemList::vftable)(void *, char);

//----- (004E3BA0) --------------------------------------------------------  // acclient.c:273859
UIElement_ItemList *__thiscall UIElement_ItemList::DynamicCast(UIElement_ItemList *this, unsigned int i_eType)
{
  UIElement_ItemList *result; // eax@1

  result = this;
  if ( i_eType != 268435505 && i_eType != 5 )
    result = (UIElement_ItemList *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E3BD0) --------------------------------------------------------  // acclient.c:273870
signed int UIElement_ItemList::GetUIElementType()
{
  return 268435505;
}

//----- (004E3BE0) --------------------------------------------------------  // acclient.c:273876
void __thiscall UIElement_ItemList::~UIElement_ItemList(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  NoticeHandler *v2; // ebp@1
  GlobalEventHandler *v3; // eax@1
  ListNode<UIElement_UIItem *> *i; // edi@3
  ListNode<UIElement_UIItem *> *v5; // ecx@8
  ListNode<UIElement_UIItem *> *v6; // eax@9
  ListNode<UIElement_UIItem *> *v7; // ecx@16
  ListNode<UIElement_UIItem *> *v8; // eax@17

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_ItemList::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&UIElement_ItemList::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  for ( i = v1->m_listUIItemCache._head; i; i = i->next )
  {
    if ( i->data )
      UIElement::AddToDeleteQueue((UIElement *)&i->data->vfptr);
  }
  while ( 1 )
  {
    v5 = v1->m_listUIItemCache._head;
    if ( !v5 )
      break;
    v6 = v5->next;
    v1->m_listUIItemCache._head = v6;
    if ( v6 )
      v6->prev = 0;
    else
      v1->m_listUIItemCache._tail = 0;
    if ( v5 )
      operator delete(v5);
    --v1->m_listUIItemCache._num_elements;
  }
  UIElement_ListBox::Flush((UIElement_ListBox *)&v1->vfptr);
  v1->m_listUIItemCache.vfptr = (List<UIElement_UIItem *>Vtbl *)&List<UIElement_UIItem *>::vftable;
  while ( 1 )
  {
    v7 = v1->m_listUIItemCache._head;
    if ( !v7 )
      break;
    v8 = v7->next;
    v1->m_listUIItemCache._head = v8;
    if ( v8 )
      v8->prev = 0;
    else
      v1->m_listUIItemCache._tail = 0;
    if ( v7 )
      operator delete(v7);
    --v1->m_listUIItemCache._num_elements;
  }
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_ListBox::~UIElement_ListBox((UIElement_ListBox *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7BF8F4: using guessed type int (__thiscall *List<UIElement_UIItem *>::vftable)(void *, char);
// 7BF8F8: using guessed type bool (__thiscall *UIElement_ItemList::vftable)(DBCache *this);
// 7BFBA0: using guessed type int (__thiscall *UIElement_ItemList::vftable)(void *, char);

//----- (004E3CD0) --------------------------------------------------------  // acclient.c:273942
void __usercall UIElement_ItemList::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_ItemList *v3; // eax@1

  v3 = (UIElement_ItemList *)operator new(0x6C8u);
  if ( v3 )
    UIElement_ItemList::UIElement_ItemList(v3, a1, _layout, _full_desc);
}

//----- (004E3D00) --------------------------------------------------------  // acclient.c:273952
void __thiscall UIElement_ItemList::OnVisibilityChanged(UIElement_ItemList *this, bool i_bVisible)
{
  UIElement_ItemList *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( i_bVisible )
      UIElement_ItemList::UpdateEmptySlots(v2);
  }
}

//----- (004E3D30) --------------------------------------------------------  // acclient.c:273966
void __thiscall UIElement_ItemList::ResizeTo(UIElement_ItemList *this, const int _width, const int _height)
{
  UIElement_ItemList *v3; // esi@1

  v3 = this;
  UIElement_ListBox::ResizeTo((UIElement_ListBox *)&this->vfptr, _width, _height);
  if ( (v3->m_nFlags >> 17) & 1 )
    UIElement_ItemList::UpdateEmptySlots(v3);
}

//----- (004E3D60) --------------------------------------------------------  // acclient.c:273977
void __thiscall UIElement_ItemList::ItemList_Flush(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  UIElement_UIItem *v2; // ecx@1
  unsigned int v3; // ebx@3
  UIElement *v4; // eax@4
  UIElement_UIItem *v5; // eax@5
  UIElement_UIItem *v6; // edi@5

  v1 = this;
  v2 = this->m_pendingItem;
  if ( v2 )
  {
    UIElement_UIItem::Clear_UIItem(v2);
    UIElement_UIItem::UIItem_SetState(v1->m_pendingItem, 0x1000001Cu);
    v1->m_pendingItem = 0;
  }
  v3 = 0;
  if ( (signed int)v1->m_listItems.m_num > 0 )
  {
    do
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, v3);
      if ( v4 )
      {
        v5 = (UIElement_UIItem *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        v6 = v5;
        if ( v5 )
        {
          UIElement_UIItem::Clear_UIItem(v5);
          UIElement_UIItem::UIItem_SetState(v6, 0x1000001Cu);
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < (signed int)v1->m_listItems.m_num );
  }
  v1->openItemID = 0;
  UIElement_ItemList::UpdateOpenContainerIndicator(v1, 0);
  UIElement_ItemList::UpdateEmptySlots(v1);
}

//----- (004E3E00) --------------------------------------------------------  // acclient.c:274020
UIElement_UIItem *__thiscall UIElement_ItemList::ItemList_AddItem(UIElement_ItemList *this, unsigned int _itemID)
{
  UIElement_ItemList *v2; // esi@1
  unsigned int v3; // ebx@1
  UIElement *v4; // ecx@2
  UIElement_UIItem *v5; // eax@3
  UIElement_UIItem *v6; // edi@3
  int v7; // eax@7
  UIElement_UIItem *v8; // edi@7
  UIElement *v9; // eax@9
  UIElement_UIItem *v10; // eax@10
  char selectable; // [sp+Ch] [bp-8h]@12
  int fixedListSize; // [sp+10h] [bp-4h]@6

  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    while ( 1 )
    {
      v4 = v2->m_listItems.m_data[v3];
      if ( v4 )
      {
        v5 = (UIElement_UIItem *)((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506);
        v6 = v5;
        if ( v5 )
        {
          if ( UIElement_UIItem::UIItem_GetState(v5) == (UIElement *)268435484 )
            break;
        }
      }
      ++v3;
      if ( v3 >= v2->m_listItems.m_num )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    UIElement::GetAttribute_Int((UIElement *)&v2->vfptr, 0x10000015u, &fixedListSize);
    if ( fixedListSize != -1 )
      return 0;
    v7 = UIElement_ItemList::InternalCreateItem(v2);
    v8 = (UIElement_UIItem *)v7;
    if ( v7 )
    {
      UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v7);
      UIElement_UIItem::UIItem_SetState(v8, 0x1000001Cu);
    }
    UIElement_ListBox::AddItem((UIElement_ListBox *)&v2->vfptr, (UIElement *)&v8->vfptr);
    v9 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->vfptr, v2->m_listItems.m_num - 1);
    if ( !v9 )
      return 0;
    v10 = (UIElement_UIItem *)v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)268435506);
    v6 = v10;
    if ( !v10 || UIElement_UIItem::UIItem_GetState(v10) != (UIElement *)268435484 )
      return 0;
  }
  selectable = 1;
  if ( v2->m_singleSelection )
    selectable = UIElement_ItemList::ItemList_IsInList(v2, _itemID) == 0;
  UIElement_UIItem::Init_UIItem(v6, _itemID, v2->containerList);
  UIElement_UIItem::UIItem_SetState(v6, 0x1000001Du);
  UIElement_UIItem::SetSelectableState(v6, selectable);
  UIElement_UIItem::UIItem_Update(v6);
  UIElement_ItemList::UpdateEmptySlots(v2);
  return v6;
}

//----- (004E3F40) --------------------------------------------------------  // acclient.c:274090
UIElement_UIItem *__thiscall UIElement_ItemList::ItemList_InsertItem(UIElement_ItemList *this, unsigned int _itemID, int _pos)
{
  UIElement_ItemList *v3; // esi@1
  UIElement *v4; // eax@1
  UIElement_UIItem *v5; // eax@2
  UIElement_UIItem *v6; // edi@2
  UIElement_UIItem *val; // [sp+8h] [bp-8h]@4
  int fixedListSize; // [sp+Ch] [bp-4h]@7

  v3 = this;
  v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&this->vfptr, this->m_listItems.m_num - 1);
  if ( v4 )
  {
    v5 = (UIElement_UIItem *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
    v6 = v5;
    if ( v5 )
    {
      if ( UIElement_UIItem::UIItem_GetState(v5) == (UIElement *)268435484 )
      {
        val = v6;
        if ( UIElement_ListBox::RemoveItem((UIElement_ListBox *)&v3->vfptr, (UIElement *)&v6->vfptr) )
          List<PFileNode *>::push_back(&v3->m_listUIItemCache, &val);
        goto LABEL_6;
      }
    }
  }
  UIElement::GetAttribute_Int((UIElement *)&v3->vfptr, 0x10000015u, &fixedListSize);
  if ( fixedListSize == -1 )
  {
LABEL_6:
    UIElement_ItemList::ItemList_AddEmptySlot(v3, _pos);
    return UIElement_ItemList::ItemList_AddItem(v3, _itemID);
  }
  return 0;
}

//----- (004E3FE0) --------------------------------------------------------  // acclient.c:274127
void __thiscall UIElement_ItemList::ItemList_DeleteItem(UIElement_ItemList *this, unsigned int _itemID)
{
  UIElement_ItemList *v2; // edi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // ebp@2
  UIElement *v5; // ecx@3
  int v6; // eax@4
  unsigned int v7; // esi@4
  int v8; // eax@10

  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    v4 = _itemID;
    while ( 1 )
    {
      v5 = v2->m_listItems.m_data[v3];
      if ( v5 )
      {
        v6 = ((int (__stdcall *)(signed int))v5->vfptr[12].OnAction)(268435506);
        v7 = v6;
        if ( v6 )
        {
          if ( *(_DWORD *)(v6 + 1532) == v4 )
            break;
        }
      }
      ++v3;
      if ( v3 >= v2->m_listItems.m_num )
      {
        UIElement_ItemList::UpdateEmptySlots(v2);
        return;
      }
    }
    if ( v2->m_singleSelection )
    {
      if ( *(_BYTE *)(v6 + 1600) )
      {
        v8 = UIElement_ItemList::ItemList_GetItem(v2, v4);
        if ( v8 )
          UIElement_UIItem::SetSelectableState((UIElement_UIItem *)v8, 1);
      }
    }
    _itemID = v7;
    if ( UIElement_ListBox::RemoveItem((UIElement_ListBox *)&v2->vfptr, (UIElement *)v7) )
      List<PFileNode *>::push_back(&v2->m_listUIItemCache, (UIElement_UIItem *const *)&_itemID);
  }
  UIElement_ItemList::UpdateEmptySlots(v2);
}

//----- (004E40A0) --------------------------------------------------------  // acclient.c:274179
UIElement_UIItem *__thiscall UIElement_ItemList::ItemList_AddSpellShortcut(UIElement_ItemList *this, unsigned int _spellID)
{
  UIElement_ItemList *v2; // esi@1
  unsigned int v3; // ebx@1
  UIElement *v4; // ecx@2
  UIElement_UIItem *v5; // eax@3
  UIElement_UIItem *v6; // edi@3
  int v7; // eax@7
  UIElement_UIItem *v8; // edi@7
  UIElement *v9; // eax@9
  UIElement_UIItem *v10; // eax@10
  int fixedListSize; // [sp+4h] [bp-4h]@1

  fixedListSize = (int)this;
  v2 = this;
  v3 = 0;
  if ( this->m_listItems.m_num )
  {
    do
    {
      v4 = v2->m_listItems.m_data[v3];
      if ( v4 )
      {
        v5 = (UIElement_UIItem *)((int (__stdcall *)(signed int))v4->vfptr[12].OnAction)(268435506);
        v6 = v5;
        if ( v5 )
        {
          if ( UIElement_UIItem::UIItem_GetState(v5) == (UIElement *)268435484 )
            goto LABEL_12;
        }
      }
      ++v3;
    }
    while ( v3 < v2->m_listItems.m_num );
  }
  UIElement::GetAttribute_Int((UIElement *)&v2->vfptr, 0x10000015u, &fixedListSize);
  if ( fixedListSize == -1 )
  {
    v7 = UIElement_ItemList::InternalCreateItem(v2);
    v8 = (UIElement_UIItem *)v7;
    if ( v7 )
    {
      UIElement_UIItem::Clear_UIItem((UIElement_UIItem *)v7);
      UIElement_UIItem::UIItem_SetState(v8, 0x1000001Cu);
    }
    UIElement_ListBox::AddItem((UIElement_ListBox *)&v2->vfptr, (UIElement *)&v8->vfptr);
    v9 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->vfptr, v2->m_listItems.m_num - 1);
    if ( v9 )
    {
      v10 = (UIElement_UIItem *)v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)268435506);
      v6 = v10;
      if ( v10 )
      {
        if ( UIElement_UIItem::UIItem_GetState(v10) == (UIElement *)268435484 )
        {
LABEL_12:
          UIElement_UIItem::Init_UIItem_Spell_Shortcut(v6, _spellID);
          UIElement_UIItem::UIItem_SetState(v6, 0x1000001Du);
          UIElement_UIItem::UIItem_Update(v6);
          UIElement_ItemList::UpdateEmptySlots(v2);
          return v6;
        }
      }
    }
  }
  return 0;
}

//----- (004E41B0) --------------------------------------------------------  // acclient.c:274248
UIElement_UIItem *__thiscall UIElement_ItemList::ItemList_InsertSpellShortcut(UIElement_ItemList *this, unsigned int _spellID, int _pos)
{
  UIElement_ItemList *v3; // esi@1
  UIElement *v4; // eax@1
  UIElement_UIItem *v5; // eax@2
  UIElement_UIItem *v6; // edi@2
  UIElement_UIItem *val; // [sp+8h] [bp-8h]@4
  int fixedListSize; // [sp+Ch] [bp-4h]@7

  v3 = this;
  v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&this->vfptr, this->m_listItems.m_num - 1);
  if ( v4 )
  {
    v5 = (UIElement_UIItem *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
    v6 = v5;
    if ( v5 )
    {
      if ( UIElement_UIItem::UIItem_GetState(v5) == (UIElement *)268435484 )
      {
        val = v6;
        if ( UIElement_ListBox::RemoveItem((UIElement_ListBox *)&v3->vfptr, (UIElement *)&v6->vfptr) )
          List<PFileNode *>::push_back(&v3->m_listUIItemCache, &val);
        goto LABEL_6;
      }
    }
  }
  UIElement::GetAttribute_Int((UIElement *)&v3->vfptr, 0x10000015u, &fixedListSize);
  if ( fixedListSize == -1 )
  {
LABEL_6:
    UIElement_ItemList::ItemList_AddEmptySlot(v3, _pos);
    return UIElement_ItemList::ItemList_AddSpellShortcut(v3, _spellID);
  }
  return 0;
}

//----- (004E4250) --------------------------------------------------------  // acclient.c:274285
bool __thiscall UIElement_ItemList::AcceptDragObject(UIElement_ItemList *this, unsigned int i_itemID, bool i_isContainer)
{
  UIElement_ItemList *v3; // edi@1
  UIElement *v4; // eax@1
  int v5; // esi@2
  bool result; // al@3
  HashBaseData<unsigned long> *v7; // eax@4
  bool v8; // al@11
  char *v9; // esi@17
  UIElement_UIItem *v10; // eax@20
  ACCWeenieObject *v11; // eax@21
  char *v12; // esi@21
  char *v13; // esi@24
  int v14; // ebx@28
  int v15; // eax@28
  HashBaseData<unsigned long> *v16; // eax@30
  unsigned int v17; // ebp@30
  HashBaseData<unsigned long> *v18; // ecx@34
  PSRefBufferCharData<unsigned short> *v19; // esi@36
  ACCWeenieObject *v20; // eax@40
  HashBaseData<unsigned long> *v21; // eax@48
  UIElement_UIItem *v22; // esi@54
  int v23; // eax@55
  UIElement *v24; // eax@55
  UIElement_UIItem *v25; // eax@56
  UIElement_UIItem *v26; // esi@56
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-9Ch]@1
  int v28; // [sp+Ch] [bp-98h]@1
  CaseInsensitiveStringBase<PStringBase<char> > v29; // [sp+10h] [bp-94h]@21
  StringInfo siError; // [sp+14h] [bp-90h]@7

  v3 = this;
  BYTE2(v28) = 0;
  errorText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)-1;
  v4 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&this->vfptr);
  if ( !v4 )
    return 0;
  v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
  if ( !v5 )
    return 0;
  v7 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  if ( v3->parentContainerID == i_itemID
    && v7
    && ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[5].__vecDelDtor)(v7) )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      L"You cannot place yourself in your inventory!");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
LABEL_8:
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_9:
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  v8 = v3->containerList;
  if ( !v8 )
    goto LABEL_71;
  if ( !i_isContainer && !*(_DWORD *)(v5 + 1564) )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot place item in container list");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_9;
  }
  if ( !v8 )
  {
LABEL_71:
    if ( i_isContainer )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot place container in item list");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v9 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      }
      goto LABEL_8;
    }
  }
  v10 = v3->m_pendingItem;
  if ( v10 )
  {
    v11 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v29, (PStringBase<unsigned short> *)v10->itemID, 2u, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"Already attempting to place %s here",
      v11->vfptr);
    v12 = &v29.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v29.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    v13 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) || !v13 )
      return 0;
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    result = 0;
  }
  else
  {
    if ( ItemHolder::AttemptMerge(i_itemID, *(_DWORD *)(v5 + 1532), 1) )
      goto LABEL_72;
    v14 = UIElement_ListBox::WhatNum((UIElement_ListBox *)&v3->vfptr, (UIElement *)v5);
    v15 = UIElement_ItemList::GetNumUIItems(v3);
    if ( v14 > v15 )
      v14 = v15;
    v16 = ClientObjMaintSystem::GetWeenieObject(*(_DWORD *)(v5 + 1532));
    v17 = v3->parentContainerID;
    BYTE3(v28) = 0;
    if ( v16 )
    {
      if ( i_isContainer )
      {
        if ( v16[17].vfptr )
          v17 = *(_DWORD *)(v5 + 1532);
      }
      else if ( v16[16].id )
      {
        v17 = *(_DWORD *)(v5 + 1532);
        BYTE3(v28) = 1;
      }
      else if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v16) )
      {
        v20 = ACCWeenieObject::GetObjectNameWide(
                (ACCWeenieObject *)&v29,
                *(PStringBase<unsigned short> **)(v5 + 1532),
                2u,
                0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &errorText,
          0,
          L"The %s cannot accept items",
          v20->vfptr);
        PStringBase<char>::~PStringBase<char>(&v29);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        return 0;
      }
    }
    v18 = ClientObjMaintSystem::GetWeenieObject(v17);
    if ( v18 )
    {
      if ( i_isContainer )
      {
        v19 = (PSRefBufferCharData<unsigned short> *)ACCWeenieObject::GetPlaceInContainersList(
                                                       (ACCWeenieObject *)v18,
                                                       i_itemID);
        errorText.m_charbuffer = v19;
      }
      else
      {
        errorText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)ACCWeenieObject::GetPlaceInItemsList(
                                                                          (ACCWeenieObject *)v18,
                                                                          i_itemID);
        v19 = errorText.m_charbuffer;
      }
      if ( v19 != (PSRefBufferCharData<unsigned short> *)-1 )
      {
        if ( (PSRefBufferCharData<unsigned short> *)v14 == v19 )
          return 0;
        if ( (unsigned __int16 *)v14 == (unsigned __int16 *)((char *)&v19->m_data[0] + 1)
          && GenItemHolder::splitSize == GenItemHolder::maxSplitSize )
          return 0;
      }
    }
    else
    {
      v19 = errorText.m_charbuffer;
    }
    v21 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
    if ( v21
      && v21[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1
      && GenItemHolder::splitSize != GenItemHolder::maxSplitSize )
      return 0;
    if ( v17 && ItemHolder::IsDragIntoContainerAttemptLegal(i_itemID, v17) && v17 == v3->parentContainerID )
    {
      v22 = UIElement_ItemList::ItemList_InsertItem(v3, i_itemID, v14);
      if ( v22 )
        goto LABEL_73;
      v23 = UIElement_ItemList::GetNumUIItems(v3);
      v24 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v3->vfptr, v23 - 1);
      if ( v24 )
      {
        v25 = (UIElement_UIItem *)v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)268435506);
        v26 = v25;
        if ( v25 )
        {
          UIElement_UIItem::Clear_UIItem(v25);
          UIElement_UIItem::UIItem_SetState(v26, 0x1000001Cu);
        }
      }
      v22 = UIElement_ItemList::ItemList_InsertItem(v3, i_itemID, v14);
      if ( v22 )
      {
LABEL_73:
        UIElement_UIItem::SetWaitingState(v22, 1);
        v3->m_pendingItem = v22;
      }
      v19 = errorText.m_charbuffer;
    }
    if ( v19 != (PSRefBufferCharData<unsigned short> *)-1
      && (signed int)v19 < v14
      && GenItemHolder::splitSize == GenItemHolder::maxSplitSize )
      --v14;
    if ( v17
      && ItemHolder::AttemptToPlaceInContainer(i_itemID, v17, 0, BYTE3(v28), v17 != v3->parentContainerID ? 0 : v14) )
LABEL_72:
      BYTE2(v28) = 1;
    result = BYTE2(v28);
  }
  return result;
}

//----- (004E4750) --------------------------------------------------------  // acclient.c:274512
UIElement_ItemList *__thiscall UIElement_ItemList::scalar_deleting_destructor(UIElement_ItemList *this, unsigned int a2)
{
  UIElement_ItemList *v2; // esi@1

  v2 = this;
  UIElement_ItemList::~UIElement_ItemList(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E4770) --------------------------------------------------------  // acclient.c:274524
void __cdecl UIElement_ItemList::Register()
{
  UIElement::RegisterElementClass(
    0x10000031u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_ItemList::Create);
}

//----- (004E4790) --------------------------------------------------------  // acclient.c:274532
void __thiscall UIElement_ItemList::HandleDropRelease(UIElement_ItemList *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // ebp@1
  UIElement *v4; // esi@1
  UIElement_ItemList *v5; // edi@1
  unsigned int v6; // ebx@5
  HashBaseData<unsigned long> *v7; // esi@7
  unsigned int dropItemID; // [sp+Ch] [bp-8h]@5
  unsigned int dropSpellID; // [sp+10h] [bp-4h]@5

  v2 = i_rMsg->dwParam1;
  v3 = *(UIElement **)(v2 + 16);
  v4 = *(UIElement **)(v2 + 8);
  v5 = this;
  if ( v4 && v3 && (UIElement::IsAncestorOfMe(v3, (UIElement *)&this->vfptr) || (UIElement_ItemList *)v3 == v5) )
  {
    UIElement_ItemList::InqDropIconInfo(v4, &dropItemID, &dropSpellID, (DropItemFlags *)&i_rMsg);
    v6 = dropItemID;
    if ( dropItemID )
    {
      if ( !((unsigned __int8)i_rMsg & 0xE) )
      {
        v7 = ClientObjMaintSystem::GetWeenieObject(dropItemID);
        if ( (UIElement_ItemList *)v3 == v5
          || (unsigned __int8)UIElement_ItemList::IsAliasList(v5)
          || !UIElement_ItemList::AcceptDragObject(v5, v6, (unsigned __int8)i_rMsg & 1) )
        {
          if ( v7 )
            ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v7, 0);
        }
      }
    }
  }
}

//----- (004E4830) --------------------------------------------------------  // acclient.c:274569
void __thiscall UIElement_ItemList::InitItemList(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  int v2; // ebx@2
  int v3; // eax@3
  UIRegion *v4; // edi@3
  int v5; // eax@7
  UIRegion *v6; // edi@7
  int numSlots; // [sp+0h] [bp-4h]@1

  numSlots = (int)this;
  v1 = this;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x10000011u, &this->containerList);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000013u, &v1->vendorItemList);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000012u, &v1->shortcutList);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000014u, &v1->salvageList);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000052u, &v1->m_singleSelection);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x1000005Cu, &v1->m_dragScrollItemScrolling);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x1000005Du, &v1->m_dragScrollSpellScrolling);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000054u, &v1->m_dragScrollVertical);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x10000053u, &v1->m_dragScrollHorizontal);
  UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x10000059u, &v1->m_dragScrollMarginWidth);
  UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x1000005Au, &v1->m_dragScrollMarginHeight);
  UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x10000057u, &v1->m_dragScrollJumpDistance);
  UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x1000005Bu, &v1->m_dragScrollDelay);
  UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x10000015u, &numSlots);
  if ( numSlots < 0 )
  {
    v5 = UIElement_ItemList::InternalCreateItem(v1);
    v6 = (UIRegion *)v5;
    if ( v5 )
    {
      v1->m_cellW = UIRegion::GetWidth((UIRegion *)v5);
      v1->m_cellH = UIRegion::GetHeight(v6);
      UIElement_ListBox::AddItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)v6);
    }
    goto LABEL_9;
  }
  v2 = 0;
  if ( numSlots <= 0 )
  {
LABEL_9:
    UIElement_ItemList::ItemList_Flush(v1);
    return;
  }
  do
  {
    v3 = UIElement_ItemList::InternalCreateItem(v1);
    v4 = (UIRegion *)v3;
    if ( v3 )
    {
      v1->m_cellW = UIRegion::GetWidth((UIRegion *)v3);
      v1->m_cellH = UIRegion::GetHeight(v4);
      UIElement_ListBox::AddItem((UIElement_ListBox *)&v1->vfptr, (UIElement *)v4);
    }
    ++v2;
  }
  while ( v2 < numSlots );
  UIElement_ItemList::ItemList_Flush(v1);
}

//----- (004E49D0) --------------------------------------------------------  // acclient.c:274631
void __thiscall UIElement_ItemList::ItemList_SetParentContainer(UIElement_ItemList *this, unsigned int _parentContainerID, int _refresh, int _draw)
{
  unsigned int v4; // ebp@1
  UIElement_ItemList *v5; // edi@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@9
  IDList *v8; // eax@13
  IDList *v9; // esi@15
  int i; // ebx@16
  unsigned int v11; // eax@17
  unsigned int _parentContainerIDa; // [sp+10h] [bp+4h]@5

  v4 = _parentContainerID;
  v5 = this;
  v6 = ClientObjMaintSystem::GetWeenieObject(_parentContainerID);
  if ( v6
    && ((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v6[21].hash_next
     || v6[16].id
     || v6[17].vfptr) )
  {
    _parentContainerIDa = 0;
    if ( v5->parentContainerID != v4 )
    {
      _parentContainerIDa = 1;
      v5->parentContainerID = v4;
    }
    UIElement_ItemList::ItemList_UpdateContainerListSize(v5);
    UIElement_ItemList::ItemList_Flush(v5);
    if ( (unsigned int)v6[21].hash_next & 1
      || (!SmartBox::smartbox ? (v7 = 0) : (v7 = SmartBox::smartbox->player_id), v4 == v7) )
    {
      v8 = v5->containerList ? ACCWeenieObject::GetContainedContainersList((ACCWeenieObject *)v6) : ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v6);
      v9 = v8;
      if ( v8 )
      {
        IDList::SetCurToNum(v8, 0);
        for ( i = 0; i < v9->numIDs; ++i )
        {
          v11 = IDList::GetCurID(v9);
          if ( v11 )
            UIElement_ItemList::ItemList_AddItem(v5, v11);
          IDList::SetCurToNext(v9);
        }
      }
    }
    if ( _parentContainerIDa )
      CM_UI::SendNotice_NewParentContainer(v4);
  }
  else
  {
    v5->parentContainerID = 0;
    UIElement_ItemList::ItemList_Flush(v5);
  }
}

//----- (004E4AE0) --------------------------------------------------------  // acclient.c:274687
int __thiscall UIElement_ItemList::ItemList_OpenContainer(UIElement_ItemList *this, unsigned int _containerID, int _checkIfInList)
{
  UIElement_ItemList *v3; // esi@1
  UIElement_ItemList *v5; // ecx@6
  UIElement_ItemList *v6; // ecx@7

  v3 = this;
  if ( !_containerID )
    return 0;
  if ( this->openItemID != _containerID )
  {
    if ( _checkIfInList && !UIElement_ItemList::ItemList_IsInList(this, _containerID) )
      return 0;
    v5 = v3->childList;
    if ( v5 )
    {
      UIElement_ItemList::ItemList_SetParentList(v5, v3);
      UIElement_ItemList::ItemList_SetParentContainer(v3->childList, _containerID, 0, 1);
      v6 = v3->childList;
      if ( v6->m_listItems.m_num )
        UIElement_ListBox::ScrollToShow((UIElement_ListBox *)&v6->vfptr, 0);
    }
    v3->openItemID = _containerID;
    UIElement_ItemList::UpdateOpenContainerIndicator(v3, _containerID);
  }
  return 1;
}

//----- (004E4B60) --------------------------------------------------------  // acclient.c:274716
void __thiscall UIElement_ItemList::ItemList_OpenFirstContainer(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // esi@1
  UIElement *v2; // ecx@1
  int v3; // eax@2
  unsigned int v4; // edi@3
  UIElement_ItemList *v5; // ecx@6
  UIElement_ItemList *v6; // ecx@7
  UIElement_ItemList *v7; // ecx@10

  v1 = this;
  v2 = *this->m_listItems.m_data;
  if ( v2 && (v3 = ((int (__stdcall *)(signed int))v2->vfptr[12].OnAction)(268435506)) != 0 )
  {
    v4 = *(_DWORD *)(v3 + 1532);
    if ( v4 && v1->openItemID != v4 && UIElement_ItemList::ItemList_IsInList(v1, *(_DWORD *)(v3 + 1532)) )
    {
      v5 = v1->childList;
      if ( v5 )
      {
        UIElement_ItemList::ItemList_SetParentList(v5, v1);
        UIElement_ItemList::ItemList_SetParentContainer(v1->childList, v4, 0, 1);
        v6 = v1->childList;
        if ( v6->m_listItems.m_num )
          UIElement_ListBox::ScrollToShow((UIElement_ListBox *)&v6->vfptr, 0);
      }
      v1->openItemID = v4;
      UIElement_ItemList::UpdateOpenContainerIndicator(v1, v4);
    }
  }
  else
  {
    v7 = v1->childList;
    if ( v7 )
      UIElement_ItemList::ItemList_SetParentContainer(v7, 0, 0, 1);
  }
}

//----- (004E4C00) --------------------------------------------------------  // acclient.c:274755
void __thiscall UIElement_ItemList::RefreshList(UIElement_ItemList *this)
{
  UIElement_ItemList::ItemList_SetParentContainer(this, this->parentContainerID, 1, 1);
}

//----- (004E4C20) --------------------------------------------------------  // acclient.c:274761
void __thiscall UIElement_ItemList::ServerSaysAttemptFailed(UIElement_ItemList *this, unsigned int _itemID)
{
  UIElement_ItemList *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // edi@3
  UIElement *v5; // ecx@4
  int v6; // eax@5

  v2 = this;
  v3 = this->parentContainerID;
  if ( v3 )
  {
    if ( v3 != _itemID )
    {
      v4 = 0;
      if ( !this->m_listItems.m_num )
        return;
      while ( 1 )
      {
        v5 = v2->m_listItems.m_data[v4];
        if ( v5 )
        {
          v6 = ((int (__stdcall *)(signed int))v5->vfptr[12].OnAction)(268435506);
          if ( v6 )
          {
            if ( *(_DWORD *)(v6 + 1532) == _itemID )
              break;
          }
        }
        ++v4;
        if ( v4 >= v2->m_listItems.m_num )
          return;
      }
      v3 = v2->parentContainerID;
    }
    UIElement_ItemList::ItemList_SetParentContainer(v2, v3, 1, 1);
  }
}

//----- (004E4CA0) --------------------------------------------------------  // acclient.c:274801
void __thiscall UIElement_ItemList::PostInit(UIElement_ItemList *this)
{
  UIElement_ItemList *v1; // edi@1
  GlobalEventHandler *v2; // esi@1
  int v3; // eax@3
  int v4; // eax@6
  int v5; // eax@9
  int v6; // eax@12
  int v7; // eax@15

  v1 = this;
  UIElement_Scrollable::PostInit((UIElement_Scrollable *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100011u, (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100010u, (NoticeHandler *)v4);
    if ( v1 )
      v5 = (int)&v1->vfptr;
    else
      v5 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100008u, (NoticeHandler *)v5);
    if ( v1 )
      v6 = (int)&v1->vfptr;
    else
      v6 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100009u, (NoticeHandler *)v6);
    if ( v1 )
      v7 = (int)&v1->vfptr;
    else
      v7 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100131u, (NoticeHandler *)v7);
  }
  UIElement_ItemList::InitItemList(v1);
}

//----- (004E4D50) --------------------------------------------------------  // acclient.c:274846
int __thiscall UIElement_ItemList::ListenToElementMessage(UIElement_ItemList *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement_ItemList *v3; // esi@1
  UIElement *v4; // eax@2
  int v5; // edi@3
  unsigned int v6; // eax@4
  UIElement_ItemList *v8; // ecx@11
  unsigned int v9; // edi@12
  int v10; // ebx@15
  unsigned int v11; // ST08_4@25
  ClientUISystem *v12; // eax@25
  unsigned int v13; // edi@26
  ClientUISystem *v14; // eax@27
  UIElement *v15; // ecx@29
  UIElement_UIItem *v16; // eax@30

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 != 28 )
  {
    if ( v2 == 21 )
    {
      v15 = i_rMsg->pElement;
      if ( v15 )
      {
        v16 = (UIElement_UIItem *)((int (__stdcall *)(signed int))v15->vfptr[12].OnAction)(268435506);
        if ( v16 )
          UIElement_UIItem::SetDragAcceptState(v16, 0x1000003Fu);
      }
      UIElement_ItemList::HandleDropRelease(v3, i_rMsg);
    }
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  }
  v4 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&this->vfptr);
  if ( !v4 )
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
  if ( !v5 )
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  v6 = i_rMsg->dwParam1;
  if ( v6 == 7 )
  {
    if ( ClientUISystem::GetUISystem()->targetMode )
    {
      UIElement_ItemList::HandleTargetedUseLeftClick((UIElement_UIItem *)v5);
      return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
    }
    if ( *(_DWORD *)(v5 + 1532) )
    {
      if ( v3->m_singleSelection )
        UIElement_ItemList::HandleSingleSelection(v3, (UIElement_UIItem *)v5);
      ACCWeenieObject::SetSelectedObject(*(_DWORD *)(v5 + 1532), 0);
      if ( v3->containerList )
      {
        v8 = v3->childList;
        if ( v8 )
        {
          UIElement_ItemList::ItemList_SetParentList(v8, v3);
          UIElement_ItemList::ItemList_SetParentContainer(v3->childList, *(_DWORD *)(v5 + 1532), 0, 1);
          v9 = *(_DWORD *)(v5 + 1532);
          if ( v3->openItemID != v9 )
          {
            v3->openItemID = v9;
            UIElement_ItemList::UpdateOpenContainerIndicator(v3, v9);
            UIElement_ListBox::ScrollToHome((UIElement_ListBox *)&v3->childList->vfptr);
            return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
          }
        }
      }
    }
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  }
  if ( v6 == 10 )
  {
    v10 = *(_DWORD *)(v5 + 1532);
    if ( v10
      && !v3->vendorItemList
      && !v3->salvageList
      && (!v3->containerList || v10 == ClientUISystem::GetUISystem()->groundObject) )
    {
      ItemHolder::UseObject(*(_DWORD *)(v5 + 1532), 0, 0);
      return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
    }
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  }
  if ( v6 != 8 )
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  if ( !*(_DWORD *)(v5 + 1532) )
  {
    v13 = *(_DWORD *)(v5 + 1536);
    if ( v13 )
    {
      v14 = ClientUISystem::GetUISystem();
      ClientUISystem::ExamineSpell(v14, v13);
      return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
    }
    return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
  }
  if ( v3->m_singleSelection )
    UIElement_ItemList::HandleSingleSelection(v3, (UIElement_UIItem *)v5);
  ACCWeenieObject::SetSelectedObject(*(_DWORD *)(v5 + 1532), 0);
  v11 = *(_DWORD *)(v5 + 1532);
  v12 = ClientUISystem::GetUISystem();
  ClientUISystem::ExamineObject(v12, v11);
  return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)&v3->vfptr, i_rMsg);
}

//----- (004E4F90) --------------------------------------------------------  // acclient.c:274955
void __thiscall UIElement_ItemList::ItemAttributesChanged(UIElement_ItemList *this, unsigned int _itemID, int _flags)
{
  UIElement_ItemList *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@4
  UIElement *v6; // ecx@5
  int v7; // eax@6

  v3 = this;
  v4 = this->parentContainerID;
  if ( _itemID == v4 && _flags & 1 )
    UIElement_ItemList::ItemList_SetParentContainer(this, v4, 1, 1);
  v5 = 0;
  if ( v3->m_listItems.m_num )
  {
    do
    {
      v6 = v3->m_listItems.m_data[v5];
      if ( v6 )
      {
        v7 = ((int (__stdcall *)(signed int))v6->vfptr[12].OnAction)(268435506);
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 1532) == _itemID )
            UIElement_UIItem::UIItem_Update((UIElement_UIItem *)v7);
        }
      }
      ++v5;
    }
    while ( v5 < v3->m_listItems.m_num );
  }
}

//----- (004E5000) --------------------------------------------------------  // acclient.c:274989
void __thiscall UIElement_ItemList::ServerSaysMoveItem(UIElement_ItemList *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  UIElement_ItemList *v9; // esi@1
  HashBaseData<unsigned long> *v10; // eax@1
  HashBaseData<unsigned long> *v11; // edi@1
  int v12; // eax@2
  unsigned int v13; // eax@10

  v9 = this;
  v10 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v11 = v10;
  if ( !v10
    || ((v12 = ((unsigned int)v10[21].hash_next >> 23) & 1, !(((unsigned int)v11[21].hash_next >> 23) & 1))
     && !v11[16].id
     && !v11[17].vfptr
     || v9->containerList)
    && (v12 || v11[16].id || v11[17].vfptr || !v9->containerList) )
  {
    v13 = v9->parentContainerID;
    if ( v13 )
    {
      if ( _oldContainer == v13 || _newContainer == v13 )
      {
        UIElement_ItemList::ItemList_SetParentContainer(v9, v13, 1, 1);
      }
      else if ( UIElement_ItemList::ItemList_IsInList(v9, _itemID) )
      {
        UIElement_ItemList::ItemList_SetParentContainer(v9, v9->parentContainerID, 1, 1);
        return;
      }
      if ( v11
        && _newContainer == v9->parentContainerID
        && ACCWeenieObject::IsContainer((ACCWeenieObject *)v11)
        && ACCWeenieObject::selectedID == _itemID )
        UIElement_ItemList::ItemList_OpenContainer(v9, _itemID, 0);
    }
  }
}

//----- (004E50F0) --------------------------------------------------------  // acclient.c:275029
void __thiscall UIElement_ItemList::RecvNotice_ServerSaysAttemptFailed(UIElement_ItemList *this, unsigned int i_itemID)
{
  UIElement_ItemList::ServerSaysAttemptFailed((UIElement_ItemList *)((char *)this - 1640), i_itemID);
}

//----- (004E5100) --------------------------------------------------------  // acclient.c:275035
void __thiscall UIElement_ItemList::RecvNotice_ItemAttributesChanged(UIElement_ItemList *this, unsigned int i_target, unsigned int i_attrib)
{
  UIElement_ItemList::ItemAttributesChanged((UIElement_ItemList *)((char *)this - 1640), i_target, i_attrib);
}

//----- (004E5110) --------------------------------------------------------  // acclient.c:275041
void __thiscall UIElement_ItemList::RecvNotice_ServerSaysMoveItem(UIElement_ItemList *this, unsigned int i_itemID, unsigned int i_oldContainer, unsigned int i_oldWielder, unsigned int i_oldLocation, unsigned int i_newContainer, int i_place, unsigned int i_newWielder, unsigned int i_newLocation)
{
  UIElement_ItemList::ServerSaysMoveItem(
    (UIElement_ItemList *)((char *)this - 1640),
    i_itemID,
    i_oldContainer,
    i_oldWielder,
    i_oldLocation,
    i_newContainer,
    i_place,
    i_newWielder,
    i_newLocation);
}

//----- (006BAD40) --------------------------------------------------------  // acclient.c:722818
char __thiscall List<PFileNode *>::push_back(List<UIElement_UIItem *> *this, UIElement_UIItem *const *val)
{
  List<UIElement_UIItem *> *v2; // esi@1
  void *v3; // eax@1
  char result; // al@3
  ListNode<UIElement_UIItem *> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = *val;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (ListNode<UIElement_UIItem *> *)v3;
      *((_DWORD *)v3 + 2) = v5;
      v2->_tail = (ListNode<UIElement_UIItem *> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (ListNode<UIElement_UIItem *> *)v3;
      v2->_tail = (ListNode<UIElement_UIItem *> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006F6250) --------------------------------------------------------  // acclient.c:778816
void sub_6F6250()
{
  flt_840698 = 1000.0 + 1.0;
}

//----- (006F6270) --------------------------------------------------------  // acclient.c:778822
void _E93_90()
{
  flt_84069C = 24.0 * 8.0;
}

//----- (006F6290) --------------------------------------------------------  // acclient.c:778828
void _E95_90()
{
  flt_8406A0 = 24.0 * 0.5;
}

//----- (006F62B0) --------------------------------------------------------  // acclient.c:778834
int sub_6F62B0()
{
  return atexit(nullsub_979);
}

//----- (006F62C0) --------------------------------------------------------  // acclient.c:778840
int sub_6F62C0()
{
  return atexit(nullsub_980);
}

//----- (006F62D0) --------------------------------------------------------  // acclient.c:778846
int sub_6F62D0()
{
  return atexit(nullsub_981);
}

//----- (006F62E0) --------------------------------------------------------  // acclient.c:778852
void _E109_44()
{
  DEFAULT_VIEW_RADIUS_74 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6300) --------------------------------------------------------  // acclient.c:778858
void _E111_31()
{
  MIN_QUANTUM_74 = 1.0 / 30.0;
}

//----- (006F6320) --------------------------------------------------------  // acclient.c:778864
void _E113_19()
{
  MAX_QUANTUM_74 = 1.0 / 5.0;
}

//----- (006F6340) --------------------------------------------------------  // acclient.c:778870
void _E115_48()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8406B8, PFID_A8R8G8B8);
}

//----- (006F6350) --------------------------------------------------------  // acclient.c:778876
int _E117_46()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_39, "Misc.TooltipEnable");
  return atexit(sub_7630E0);
}

//----- (006F6370) --------------------------------------------------------  // acclient.c:778883
int _E120_38()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_39, "Misc.TooltipDelay");
  return atexit(sub_763110);
}

//----- (006F6390) --------------------------------------------------------  // acclient.c:778890
void _E124_46()
{
  dword_8406F8 = 1024;
}

//----- (006F63A0) --------------------------------------------------------  // acclient.c:778896
void _E126_21()
{
  dword_8406FC = 0x7FFF;
}

//----- (006F63B0) --------------------------------------------------------  // acclient.c:778902
int _E128_6()
{
  const int result; // eax@1

  result = dword_8406F8;
  INITIAL_MAX_DATA_RATE_47 = dword_8406F8;
  return result;
}

//----- (006F63C0) --------------------------------------------------------  // acclient.c:778912
int _E130_34()
{
  return atexit(_E131_40);
}

//----- (006F63D0) --------------------------------------------------------  // acclient.c:778918
int sub_6F63D0()
{
  return atexit(nullsub_978);
}

//----- (007630E0) --------------------------------------------------------  // acclient.c:889860
void __cdecl sub_7630E0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763110) --------------------------------------------------------  // acclient.c:889873
void __cdecl sub_763110()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

