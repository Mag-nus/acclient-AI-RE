/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmInventoryUI
   Object     : GAME\game_ui_misc\gmInventoryUI.obj
   Functions  : 28
   Addresses  : 004A6670 - 006F0EC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A6670) --------------------------------------------------------  // acclient.c:222117
void __userpurge gmInventoryUI::gmInventoryUI(gmInventoryUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmInventoryUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_paperDollUI = 0;
  v4->m_backpackUI = 0;
  v4->m_3DItemsUI = 0;
  v4->m_titleText = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmInventoryUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmInventoryUI::vftable;
}
// 7AC670: using guessed type bool (__thiscall *gmInventoryUI::vftable)(DBCache *this);
// 7AC918: using guessed type int (__thiscall *gmInventoryUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A66C0) --------------------------------------------------------  // acclient.c:222136
gmInventoryUI *__thiscall gmInventoryUI::DynamicCast(gmInventoryUI *this, unsigned int i_eType)
{
  gmInventoryUI *result; // eax@1

  result = this;
  if ( i_eType != 268435491 )
    result = (gmInventoryUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A66E0) --------------------------------------------------------  // acclient.c:222147
signed int gmInventoryUI::GetUIElementType()
{
  return 268435491;
}

//----- (004A66F0) --------------------------------------------------------  // acclient.c:222153
void __usercall gmInventoryUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmInventoryUI *v3; // eax@1

  v3 = (gmInventoryUI *)operator new(0x60Cu);
  if ( v3 )
    gmInventoryUI::gmInventoryUI(v3, a1, _layout, _full_desc);
}

//----- (004A6720) --------------------------------------------------------  // acclient.c:222163
void __thiscall gmInventoryUI::RecvNotice_UpdateCharacterInformation(gmInventoryUI *this, CACQualities *i_playerDesc)
{
  gmInventoryUI *v2; // esi@1
  gmBackpackUI *v3; // ecx@1

  v2 = this;
  CACQualities::InqLoad(i_playerDesc, (float *)&i_playerDesc);
  v3 = (gmBackpackUI *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
  if ( v3 )
    gmBackpackUI::SetLoadLevel(v3, *(float *)&i_playerDesc);
}

//----- (004A6750) --------------------------------------------------------  // acclient.c:222176
void __thiscall gmInventoryUI::RecvNotice_SetDisplayInventory(gmInventoryUI *this, int display)
{
  gmInventoryUI *v2; // esi@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v3; // eax@1
  unsigned int v4; // ecx@3
  unsigned int v5; // eax@7
  unsigned int v6; // eax@10
  unsigned int v7; // eax@13
  gmPaperDollUI *v8; // ecx@16

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
  if ( v3 )
  {
    v4 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
    if ( *((_DWORD *)v3[386].__vecDelDtor + 411) != v4 )
    {
      UIElement_ItemList::ItemList_Flush((UIElement_ItemList *)v3[385].__vecDelDtor);
      if ( SmartBox::smartbox )
        v5 = SmartBox::smartbox->player_id;
      else
        v5 = 0;
      UIElement_ItemList::ItemList_AddItem(
        (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[385].__vecDelDtor,
        v5);
      if ( SmartBox::smartbox )
        v6 = SmartBox::smartbox->player_id;
      else
        v6 = 0;
      UIElement_ItemList::ItemList_SetParentContainer(
        (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[386].__vecDelDtor,
        v6,
        0,
        1);
      if ( SmartBox::smartbox )
        v7 = SmartBox::smartbox->player_id;
      else
        v7 = 0;
      UIElement_ItemList::ItemList_OpenContainer(
        (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[385].__vecDelDtor,
        v7,
        1);
    }
  }
  v8 = (gmPaperDollUI *)v2->m_hashElementsRegisteredWith.vfptr;
  if ( v8 )
    gmPaperDollUI::RemakeCharacterInventory(v8);
}

//----- (004A6810) --------------------------------------------------------  // acclient.c:222226
void __thiscall gmInventoryUI::RecvNotice_ItemAttributesChanged(gmInventoryUI *this, unsigned int i_target, unsigned int i_attrib)
{
  unsigned int v3; // eax@2
  HashSet<UIElement *>Vtbl *v4; // ecx@6

  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( i_target == v3 && i_attrib & 1 )
  {
    v4 = this->m_hashElementsRegisteredWith.vfptr;
    if ( v4 )
      gmPaperDollUI::RemakeCharacterInventory((gmPaperDollUI *)v4);
  }
}

//----- (004A6840) --------------------------------------------------------  // acclient.c:222244
void __thiscall gmInventoryUI::RecvNotice_ServerSaysMoveItem(gmInventoryUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmInventoryUI *v9; // esi@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v10; // eax@2
  gmPaperDollUI *v11; // ecx@4

  v9 = this;
  if ( _itemID == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey[1].m_box.m_x0 )
  {
    v10 = this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
    if ( _newContainer != *((_DWORD *)v10[386].__vecDelDtor + 411) )
      UIElement_ItemList::ItemList_OpenFirstContainer((UIElement_ItemList *)v10[385].__vecDelDtor);
  }
  v11 = (gmPaperDollUI *)v9->m_hashElementsRegisteredWith.vfptr;
  if ( v11 )
    gmPaperDollUI::ServerSaysMoveItem(
      v11,
      _itemID,
      _oldContainer,
      _oldWielder,
      _oldLocation,
      _newContainer,
      _place,
      _newWielder,
      _newLocation);
}

//----- (004A68B0) --------------------------------------------------------  // acclient.c:222272
void __thiscall gmInventoryUI::RecvNotice_EndPendingInPlayer(gmInventoryUI *this)
{
  gmInventoryUI *v1; // esi@1
  HashSetData<UIElement *> *v2; // eax@1
  UIElement_ItemList *v3; // eax@2

  v1 = this;
  v2 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
  if ( v2 )
  {
    v3 = (UIElement_ItemList *)v2[192].m_hashKey;
    if ( v3 )
    {
      UIElement_ItemList::DeletePendingItem(v3);
      UIElement_ItemList::RefreshList((UIElement_ItemList *)v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey);
    }
  }
}

//----- (004A68E0) --------------------------------------------------------  // acclient.c:222292
UIElement_Field *__thiscall gmInventoryUI::vector_deleting_destructor(gmInventoryUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmInventoryUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmInventoryUI::vftable;
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
// 7AC670: using guessed type bool (__thiscall *gmInventoryUI::vftable)(DBCache *this);
// 7AC918: using guessed type int (__thiscall *gmInventoryUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A6940) --------------------------------------------------------  // acclient.c:222317
void __thiscall gmInventoryUI::PostInit(gmInventoryUI *this)
{
  gmInventoryUI *v1; // edi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  GlobalEventHandler *v8; // esi@10
  int v9; // edi@10

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_titleText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001D3u);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001CDu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435492);
  else
    v3 = 0;
  v1->m_paperDollUI = (gmPaperDollUI *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001CEu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435490);
  else
    v5 = 0;
  v1->m_backpackUI = (gmBackpackUI *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001CFu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435489);
  else
    v7 = 0;
  v1->m_3DItemsUI = (gm3DItemsUI *)v7;
  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = (int)&v1->vfptr;
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)((char *)&loc_4DD1F0 + 1), (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)((char *)&loc_4DD1F0 + 2), (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)((char *)&loc_4DD1F5 + 1), (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 5100134u, (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100011u, (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100008u, (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 5100123u, (NoticeHandler *)v9);
  v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 5100125u, (NoticeHandler *)v9);
}

//----- (004A6A60) --------------------------------------------------------  // acclient.c:222364
void __cdecl gmInventoryUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000023u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmInventoryUI::Create);
}

//----- (004A6A80) --------------------------------------------------------  // acclient.c:222372
void __thiscall gmInventoryUI::RecvNotice_OpenContainedContainer(gmInventoryUI *this, unsigned int i_containerID)
{
  gmInventoryUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // esi@1
  unsigned int v5; // ecx@7

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
  v4 = v3;
  if ( v3
    && ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v3)
    && ((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v4[21].hash_next
     || v4[16].id
     || v4[17].vfptr) )
  {
    ((void (__thiscall *)(int, signed int))v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][3].m_hashKey)(
      &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
      1);
    if ( SmartBox::smartbox )
      v5 = SmartBox::smartbox->player_id;
    else
      v5 = 0;
    if ( i_containerID == v5 )
    {
      if ( SmartBox::smartbox )
        UIElement_ItemList::ItemList_OpenContainer(
          (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[385].__vecDelDtor,
          SmartBox::smartbox->player_id,
          1);
      else
        UIElement_ItemList::ItemList_OpenContainer(
          (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[385].__vecDelDtor,
          0,
          1);
    }
    else
    {
      UIElement_ItemList::ItemList_OpenContainer(
        (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[386].__vecDelDtor,
        i_containerID,
        1);
    }
  }
}

//----- (004A6B50) --------------------------------------------------------  // acclient.c:222419
void __thiscall gmInventoryUI::RecvNotice_ShowPendingInPlayer(gmInventoryUI *this, unsigned int i_itemID)
{
  gmInventoryUI *v2; // edi@1
  HashSetData<UIElement *> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // eax@4
  UIElement_UIItem *v5; // eax@6
  UIElement_UIItem *v6; // esi@6

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
  if ( v3 )
  {
    if ( v3[192].m_hashKey )
    {
      if ( i_itemID )
      {
        v4 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
        if ( v4 )
        {
          if ( !ACCWeenieObject::IsContainer((ACCWeenieObject *)v4) )
          {
            v5 = UIElement_ItemList::ItemList_InsertItem(
                   (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey,
                   i_itemID,
                   0);
            v6 = v5;
            if ( v5 )
            {
              UIElement_UIItem::SetWaitingState(v5, 1);
              UIElement_ItemList::SetAsPendingItem(
                (UIElement_ItemList *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey,
                v6);
            }
          }
        }
      }
    }
  }
}

//----- (004A6BC0) --------------------------------------------------------  // acclient.c:222460
void __thiscall gmInventoryUI::RecvNotice_PlayerDescReceived(gmInventoryUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmInventoryUI *v3; // edi@1
  unsigned int v4; // eax@2
  ACCWeenieObject *v5; // eax@4
  int v6; // esi@4
  char *v7; // esi@7
  PStringBase<unsigned short> invOfText; // [sp+Ch] [bp-8h]@4
  int v9; // [sp+10h] [bp-4h]@4

  v3 = this;
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  v5 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v9, (PStringBase<unsigned short> *)v4, 0, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&invOfText, 0, L"Inventory of %s", v5->vfptr);
  v6 = v9 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v9 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  UIElement_Text::SetText(
    (UIElement_Text *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1],
    &invOfText);
  UIElement_ItemList::ItemList_SetChildList(
    (UIElement_ItemList *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[385].__vecDelDtor,
    (UIElement_ItemList *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey);
  UIElement_ItemList::ItemList_SetChildList(
    (UIElement_ItemList *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[386].__vecDelDtor,
    (UIElement_ItemList *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][192].m_hashKey);
  v7 = (char *)&invOfText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&invOfText.m_charbuffer[-1].m_data[8]) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  }
}

//----- (004A6C90) --------------------------------------------------------  // acclient.c:222498
void __thiscall gmInventoryUI::RecvNotice_NewParentContainer(gmInventoryUI *this, unsigned int i_newContainerID)
{
  gmInventoryUI *v2; // ebx@1
  unsigned int v3; // ecx@2
  unsigned int v4; // esi@5
  LONG v5; // eax@5
  ACCWeenieObject *v6; // eax@6
  int v7; // esi@6
  gmInventoryUI *v8; // [sp+0h] [bp-4h]@1

  v8 = this;
  v2 = this;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( i_newContainerID == v3 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_newContainerID,
      L"Contents of Backpack");
    UIElement_Text::SetText(
      (UIElement_Text *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][191].m_hashNext,
      (PStringBase<unsigned short> *)&i_newContainerID);
    v4 = i_newContainerID - 20;
    v5 = InterlockedDecrement((volatile LONG *)(i_newContainerID - 20 + 4));
  }
  else
  {
    v6 = ACCWeenieObject::GetObjectNameWide(
           (ACCWeenieObject *)&v8,
           (PStringBase<unsigned short> *)i_newContainerID,
           2u,
           0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_newContainerID,
      0,
      L"Contents of %s",
      v6->vfptr);
    v7 = (int)&v8[-1].vfptr;
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1].vfptr + 1) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    UIElement_Text::SetText(
      (UIElement_Text *)v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][191].m_hashNext,
      (PStringBase<unsigned short> *)&i_newContainerID);
    v4 = i_newContainerID - 20;
    v5 = InterlockedDecrement((volatile LONG *)(i_newContainerID - 20 + 4));
  }
  if ( !v5 )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (006F0DB0) --------------------------------------------------------  // acclient.c:773055
void _E91_70()
{
  outside_val_62 = 1000.0 + 1.0;
}

//----- (006F0DD0) --------------------------------------------------------  // acclient.c:773061
void _E93_46()
{
  block_length_62 = 24.0 * 8.0;
}

//----- (006F0DF0) --------------------------------------------------------  // acclient.c:773067
void _E95_46()
{
  half_square_length_62 = 24.0 * 0.5;
}

//----- (006F0E10) --------------------------------------------------------  // acclient.c:773073
int _E97_71()
{
  return atexit(_E98_83);
}

//----- (006F0E20) --------------------------------------------------------  // acclient.c:773079
int _E100_64()
{
  return atexit(nullsub_834);
}

//----- (006F0E30) --------------------------------------------------------  // acclient.c:773085
int _E103_56()
{
  return atexit(_E104_71);
}

//----- (006F0E40) --------------------------------------------------------  // acclient.c:773091
void _E109_26()
{
  DEFAULT_VIEW_RADIUS_35 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0E60) --------------------------------------------------------  // acclient.c:773097
void _E111_15()
{
  MIN_QUANTUM_35 = 1.0 / 30.0;
}

//----- (006F0E80) --------------------------------------------------------  // acclient.c:773103
void _E113_3()
{
  MAX_QUANTUM_35 = 1.0 / 5.0;
}

//----- (006F0EA0) --------------------------------------------------------  // acclient.c:773109
void _E115_29()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_70, PFID_A8R8G8B8);
}

//----- (006F0EB0) --------------------------------------------------------  // acclient.c:773115
int _E117_25()
{
  return atexit(nullsub_831);
}

//----- (006F0EC0) --------------------------------------------------------  // acclient.c:773121
int sub_6F0EC0()
{
  return atexit(nullsub_832);
}

