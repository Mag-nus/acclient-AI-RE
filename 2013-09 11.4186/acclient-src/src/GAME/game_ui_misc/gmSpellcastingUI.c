/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSpellcastingUI
   Object     : GAME\game_ui_misc\gmSpellcastingUI.obj
   Functions  : 64
   Addresses  : 004C5810 - 007615A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C5810) --------------------------------------------------------  // acclient.c:247247
signed int __stdcall gmSpellcastingUI::GetNextTabID(unsigned int _id)
{
  signed int result; // eax@4

  if ( _id > 0x100005C2 || _id == 268436930 )
  {
LABEL_11:
    result = 268435619;
  }
  else
  {
    switch ( _id )
    {
      case 0x100000A3u:
        result = 268435620;
        break;
      case 0x100000A4u:
        result = 268435621;
        break;
      case 0x100000A5u:
        result = 268435622;
        break;
      case 0x100000A6u:
        result = 268435623;
        break;
      case 0x100000A7u:
        result = 268435624;
        break;
      case 0x100000A8u:
        result = 268435625;
        break;
      case 0x100000A9u:
        result = 268436930;
        break;
      default:
        goto LABEL_11;
    }
  }
  return result;
}

//----- (004C5890) --------------------------------------------------------  // acclient.c:247289
signed int __stdcall gmSpellcastingUI::GetPrevTabID(unsigned int _id)
{
  signed int result; // eax@4

  if ( _id > 0x100005C2 )
  {
$L192539:
    result = 268435619;
  }
  else if ( _id == 268436930 )
  {
    result = 268435625;
  }
  else
  {
    switch ( _id )
    {
      case 0x100000A3u:
        result = 268436930;
        break;
      case 0x100000A5u:
        result = 268435620;
        break;
      case 0x100000A6u:
        result = 268435621;
        break;
      case 0x100000A7u:
        result = 268435622;
        break;
      case 0x100000A8u:
        result = 268435623;
        break;
      case 0x100000A9u:
        result = 268435624;
        break;
      default:
        goto $L192539;
    }
  }
  return result;
}

//----- (004C5910) --------------------------------------------------------  // acclient.c:247332
int __thiscall gmSpellcastingUI::GetOpenSubMenuIndex(gmSpellcastingUI *this)
{
  UIElement_Panel *v1; // eax@1
  unsigned int v2; // eax@2
  int result; // eax@5

  v1 = this->m_spellcastPanel;
  if ( v1 && (v2 = v1->m_OpenPageToken, v2 <= 0x100005C3) )
  {
    if ( v2 == 268436931 )
    {
      result = 7;
    }
    else
    {
      switch ( v2 )
      {
        case 0x100000ABu:
          result = 1;
          break;
        case 0x100000ACu:
          result = 2;
          break;
        case 0x100000ADu:
          result = 3;
          break;
        case 0x100000AEu:
          result = 4;
          break;
        case 0x100000AFu:
          result = 5;
          break;
        case 0x100000B0u:
          result = 6;
          break;
        default:
          goto $L192545;
      }
    }
  }
  else
  {
$L192545:
    result = 0;
  }
  return result;
}

//----- (004C5990) --------------------------------------------------------  // acclient.c:247381
char __stdcall SpellCastSubMenu::OnItemListDragOver(UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  if ( _dropSpellID )
    UIElement_UIItem::SetDragAcceptState(_catchElement, 0x10000040u);
  return 1;
}

//----- (004C59F0) --------------------------------------------------------  // acclient.c:247412
void __thiscall gmSpellcastingUI::~gmSpellcastingUI(gmSpellcastingUI *this)
{
  UIElement_Field *v1; // edi@1
  NoticeHandler *v2; // ebx@1
  GlobalEventHandler *v3; // eax@1
  int v4; // esi@3
  signed int v5; // ebp@3
  UIElement_ItemList *v6; // ecx@4

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSpellcastingUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSpellcastingUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = (int)&v1[1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22];
  v5 = 8;
  do
  {
    v6 = *(UIElement_ItemList **)(v4 - 24);
    v4 -= 28;
    *(_DWORD *)v4 = &SpellCastSubMenu::vftable;
    if ( v6 )
      UIElement_ItemList::UnregisterItemListDragHandler(v6);
    --v5;
  }
  while ( v5 );
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7B5E84: using guessed type bool (__thiscall *SpellCastSubMenu::vftable)(SpellCastSubMenu *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B5E88: using guessed type bool (__thiscall *gmSpellcastingUI::vftable)(DBCache *this);
// 7B6130: using guessed type int (__thiscall *gmSpellcastingUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C5A60) --------------------------------------------------------  // acclient.c:247450
gmSpellcastingUI *__thiscall gmSpellcastingUI::DynamicCast(gmSpellcastingUI *this, unsigned int i_eType)
{
  gmSpellcastingUI *result; // eax@1

  result = this;
  if ( i_eType != 268435477 )
    result = (gmSpellcastingUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004C5A80) --------------------------------------------------------  // acclient.c:247461
signed int gmSpellcastingUI::GetUIElementType()
{
  return 268435477;
}

//----- (004C5A90) --------------------------------------------------------  // acclient.c:247467
void __thiscall SpellCastSubMenu::Init(SpellCastSubMenu *this, UIElement *parent, unsigned int elementID, unsigned int tabID, int index)
{
  SpellCastSubMenu *v5; // esi@1
  UIElement *v6; // eax@1
  UIElement *v7; // eax@2
  UIElement_ItemList *v8; // eax@3

  v5 = this;
  v6 = UIElement::GetChildRecursive(parent, elementID);
  v5->m_tabIndex = index;
  if ( v6 )
  {
    v7 = UIElement::GetChildRecursive(v6, 0x100000B6u);
    if ( v7 )
      v8 = (UIElement_ItemList *)v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435505);
    else
      v8 = 0;
    v5->m_spellItemList = v8;
    if ( v8 )
      UIElement_ItemList::RegisterItemListDragHandler(v8, (ItemListDragHandler *)&v5->vfptr);
  }
  v5->m_spellTabElement = UIElement::GetChildRecursive(parent, tabID);
}

//----- (004C5B00) --------------------------------------------------------  // acclient.c:247492
void __thiscall SpellCastSubMenu::SetSelected(SpellCastSubMenu *this, unsigned int _selectedSpellID)
{
  SpellCastSubMenu *v2; // esi@1
  unsigned int v3; // edi@1
  UIElement *v4; // eax@2
  int v5; // eax@3
  UIElement_ListBox *v6; // ecx@6

  v2 = this;
  v3 = 0;
  if ( (signed int)this->m_spellItemList->m_listItems.m_num <= 0 )
  {
    this->m_selectedSpellID = _selectedSpellID;
  }
  else
  {
    do
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_spellItemList->vfptr, v3);
      if ( v4 )
      {
        v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          if ( _selectedSpellID && *(_DWORD *)(v5 + 1536) == _selectedSpellID )
          {
            UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v5, 1);
            v6 = (UIElement_ListBox *)&v2->m_spellItemList->vfptr;
            v2->m_endowmentSelected = 0;
            UIElement_ListBox::ScrollToView(v6, v3);
          }
          else
          {
            UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v5, 0);
          }
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < (signed int)v2->m_spellItemList->m_listItems.m_num );
    v2->m_selectedSpellID = _selectedSpellID;
  }
}

//----- (004C5B90) --------------------------------------------------------  // acclient.c:247537
char __thiscall SpellCastSubMenu::SelectSpellFromIndex(SpellCastSubMenu *this, int index)
{
  SpellCastSubMenu *v2; // esi@1
  UIElement_ListBox *v3; // ecx@1
  UIElement *v4; // eax@2
  int v5; // eax@3
  unsigned int v6; // eax@4
  char result; // al@5

  v2 = this;
  v3 = (UIElement_ListBox *)&this->m_spellItemList->vfptr;
  if ( v3
    && (v4 = UIElement_ListBox::GetItem(v3, index)) != 0
    && (v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506)) != 0
    && (v6 = *(_DWORD *)(v5 + 1536)) != 0 )
  {
    SpellCastSubMenu::SetSelected(v2, v6);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004C5BE0) --------------------------------------------------------  // acclient.c:247564
void __thiscall SpellCastSubMenu::UpdateShortcutOverlays(SpellCastSubMenu *this)
{
  SpellCastSubMenu *v1; // edi@1
  UIElement_ItemList *v2; // ecx@1
  signed int i; // esi@2
  UIElement *v4; // eax@3
  UIElement_UIItem *v5; // ecx@4

  v1 = this;
  v2 = this->m_spellItemList;
  if ( v2 )
  {
    for ( i = 0; i < (signed int)v2->m_listItems.m_num; ++i )
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->vfptr, i);
      if ( v4 )
      {
        v5 = (UIElement_UIItem *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          if ( i < 0 || i >= 9 )
            UIElement_UIItem::SetShortcutNum(v5, -1, 0);
          else
            UIElement_UIItem::SetShortcutNum(v5, i, 0);
        }
      }
      v2 = v1->m_spellItemList;
    }
  }
}

//----- (004C5C40) --------------------------------------------------------  // acclient.c:247596
void __userpurge gmSpellcastingUI::gmSpellcastingUI(gmSpellcastingUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpellcastingUI *v4; // esi@1
  int v5; // eax@1
  signed int v6; // edx@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSpellcastingUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSpellcastingUI::vftable;
  v4->m_spellcastPanel = 0;
  v4->m_spellName = 0;
  v4->m_spellcastButton = 0;
  v4->m_endowmentIcon = 0;
  v4->m_endowmentIcon_Overlay = 0;
  v4->m_endowmentIcon_Underlay = 0;
  v4->m_endowmentIcon_Selected = 0;
  v4->m_spellcastBackground = 0;
  v4->m_endowmentPresent = 0;
  v5 = (int)v4->m_subMenus;
  v6 = 8;
  do
  {
    *(_DWORD *)v5 = &SpellCastSubMenu::vftable;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 16) = 0;
    *(_DWORD *)(v5 + 20) = 0;
    *(_BYTE *)(v5 + 24) = 0;
    v5 += 28;
    --v6;
  }
  while ( v6 );
}
// 7B5E84: using guessed type bool (__thiscall *SpellCastSubMenu::vftable)(SpellCastSubMenu *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7B5E88: using guessed type bool (__thiscall *gmSpellcastingUI::vftable)(DBCache *this);
// 7B6130: using guessed type int (__thiscall *gmSpellcastingUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004C5CE0) --------------------------------------------------------  // acclient.c:247638
gmSpellcastingUI *__thiscall gmSpellcastingUI::vector_deleting_destructor(gmSpellcastingUI *this, unsigned int a2)
{
  gmSpellcastingUI *v2; // esi@1

  v2 = this;
  gmSpellcastingUI::~gmSpellcastingUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004C5D00) --------------------------------------------------------  // acclient.c:247650
void __thiscall gmSpellcastingUI::PostInit(gmSpellcastingUI *this)
{
  gmSpellcastingUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  UIElement *v7; // eax@9
  int v8; // eax@10
  UIElement *v9; // eax@12
  UIElement *v10; // eax@13
  UIElement *v11; // ecx@13
  UIElement *v12; // eax@13
  UIElement *v13; // ecx@13
  UIElement *v14; // eax@13
  UIElement *v15; // ecx@13
  GlobalEventHandler *v16; // eax@14
  GlobalEventHandler *v17; // edi@14
  int v18; // esi@15

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000A2u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)8);
  else
    v3 = 0;
  v1->m_spellcastPanel = (UIElement_Panel *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000048Bu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_spellName = (UIElement_Text *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000A0u);
  v1->m_spellcastBackground = v6;
  if ( v6 )
    ((void (__thiscall *)(UIElement *, signed int))v6->vfptr[22].OnLoseFocus)(v6, 1);
  v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000B2u);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)1);
  else
    v8 = 0;
  v1->m_spellcastButton = (UIElement_Button *)v8;
  v9 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000B1u);
  v1->m_endowmentIcon = v9;
  if ( v9 )
  {
    v10 = UIElement::GetChildRecursive(v9, 0x10000453u);
    v11 = v1->m_endowmentIcon;
    v1->m_endowmentIcon_Overlay = v10;
    v12 = UIElement::GetChildRecursive(v11, 0x10000452u);
    v13 = v1->m_endowmentIcon;
    v1->m_endowmentIcon_Underlay = v12;
    v14 = UIElement::GetChildRecursive(v13, 0x10000454u);
    v15 = v1->m_endowmentIcon;
    v1->m_endowmentIcon_Selected = v14;
    ((void (__stdcall *)(signed int))v15->vfptr[22].OnLoseFocus)(1);
    ((void (__stdcall *)(_DWORD))v1->m_endowmentIcon->vfptr[2].__vecDelDtor)(0);
  }
  SpellCastSubMenu::Init(v1->m_subMenus, (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000AAu, 0x100000A3u, 0);
  SpellCastSubMenu::Init(&v1->m_subMenus[1], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000ABu, 0x100000A4u, 1);
  SpellCastSubMenu::Init(&v1->m_subMenus[2], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000ACu, 0x100000A5u, 2);
  SpellCastSubMenu::Init(&v1->m_subMenus[3], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000ADu, 0x100000A6u, 3);
  SpellCastSubMenu::Init(&v1->m_subMenus[4], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000AEu, 0x100000A7u, 4);
  SpellCastSubMenu::Init(&v1->m_subMenus[5], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000AFu, 0x100000A8u, 5);
  SpellCastSubMenu::Init(&v1->m_subMenus[6], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100000B0u, 0x100000A9u, 6);
  SpellCastSubMenu::Init(&v1->m_subMenus[7], (UIElement *)&v1->m_spellcastPanel->vfptr, 0x100005C3u, 0x100005C2u, 7);
  v16 = GlobalEventHandler::GetGlobalEventHandler();
  v17 = v16;
  if ( v16 )
  {
    v18 = (int)&v1->vfptr;
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v17,
      (unsigned int)((char *)&loc_4DD1EE + 1),
      (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 100008u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100118u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v17,
      (unsigned int)((char *)&loc_4DD1F9 + 2),
      (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v17,
      (unsigned int)((char *)&loc_4DD200 + 2),
      (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, (unsigned int)&loc_4DD203, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, (unsigned int)&loc_4DD260, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100106u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, (unsigned int)&loc_4DD24B, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100108u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100109u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100136u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100139u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, (unsigned int)&loc_4DD26A, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100137u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100110u, (NoticeHandler *)v18);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100111u, (NoticeHandler *)v18);
  }
}

//----- (004C6000) --------------------------------------------------------  // acclient.c:247755
void __usercall gmSpellcastingUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpellcastingUI *v3; // eax@1

  v3 = (gmSpellcastingUI *)operator new(0x708u);
  if ( v3 )
    gmSpellcastingUI::gmSpellcastingUI(v3, a1, _layout, _full_desc);
}

//----- (004C6030) --------------------------------------------------------  // acclient.c:247765
void __cdecl gmSpellcastingUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000015u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSpellcastingUI::Create);
}

//----- (004C6050) --------------------------------------------------------  // acclient.c:247773
void __thiscall gmSpellcastingUI::Cast(gmSpellcastingUI *this)
{
  int v1; // eax@1
  gmSpellcastingUI *v2; // ecx@1
  unsigned int v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@1
  unsigned int v6; // ecx@2
  char *v7; // esi@4
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@4
  StringInfo siError; // [sp+8h] [bp-90h]@4

  v1 = gmSpellcastingUI::GetOpenSubMenuIndex(this);
  v3 = v2->m_subMenus[v1].m_selectedSpellID;
  v4 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
  if ( *(_BYTE *)(28 * v4 + v5 + 1600) && (v6 = *(_DWORD *)(v5 + 1568)) != 0 )
  {
    ItemHolder::UseObject(v6, 1, 1);
  }
  else if ( v3 )
  {
    if ( ClientMagicSystem::GetMagicSystem() )
      ClientMagicSystem::CastSpell(v3);
  }
  else
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You must select a spell to cast");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v7 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
  }
}

//----- (004C6120) --------------------------------------------------------  // acclient.c:247814
void __usercall gmSpellcastingUI::UpdateEndowmentIcon(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  gmSpellcastingUI *v2; // esi@1
  unsigned int v3; // eax@5
  HashBaseData<unsigned long> *v4; // eax@7
  unsigned int v5; // eax@8
  unsigned int v6; // edi@8
  HashBaseData<unsigned long> *v7; // ebx@9
  int v8; // eax@10
  int v9; // ecx@13
  UIRegion *v10; // ecx@14
  ClientMagicSystem *v11; // eax@14
  ClientMagicSystem *v12; // ebp@14
  Graphic *v13; // edi@15
  Graphic *v14; // eax@16
  Graphic *v15; // eax@17
  Graphic *v16; // edi@21
  Graphic *v17; // eax@22
  Graphic *v18; // eax@22
  int v19; // eax@24
  UIElement *v20; // ecx@24
  AC1Legacy::PStringBase<char> *v21; // edi@27
  PStringBase<unsigned short> *v22; // eax@27
  int v23; // [sp-8h] [bp-140h]@7
  bool endowmentPresent; // [sp+Bh] [bp-12Dh]@4
  PStringBase<unsigned short> strTooltip; // [sp+Ch] [bp-12Ch]@27
  PStringBase<unsigned short> _value; // [sp+10h] [bp-128h]@27
  PStringBase<unsigned short> v27; // [sp+14h] [bp-124h]@27
  AC1Legacy::PStringBase<char> result; // [sp+18h] [bp-120h]@27
  StringInfo _text; // [sp+1Ch] [bp-11Ch]@27
  int v30; // [sp+ACh] [bp-8Ch]@27

  v2 = this;
  if ( this->m_endowmentIcon && this->m_endowmentIcon_Overlay && this->m_endowmentIcon_Underlay )
  {
    endowmentPresent = 0;
    if ( SmartBox::smartbox )
      v3 = SmartBox::smartbox->player_id;
    else
      v3 = 0;
    v23 = a2;
    v4 = ClientObjMaintSystem::GetWeenieObject(v3);
    if ( !v4
      || (v5 = (unsigned int)ACCWeenieObject::GetObjectAtLocation((ACCWeenieObject *)v4, 0x1000000u, 0), (v6 = v5) == 0)
      || (v7 = ClientObjMaintSystem::GetWeenieObject(v5)) == 0
      || (v8 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[6].__vecDelDtor)(v7), SBYTE1(v8) >= 0)
      || !v7[22].id )
    {
      v2->m_endowmentItemID = 0;
      v2->m_endowmentSpellID = 0;
      v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)].m_endowmentSelected = 0;
      ((void (__stdcall *)(_DWORD))v2->m_endowmentIcon->vfptr[2].__vecDelDtor)(0);
LABEL_28:
      v2->m_endowmentPresent = endowmentPresent;
      return;
    }
    endowmentPresent = 1;
    if ( !v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)].m_selectedSpellID )
    {
      v9 = (int)&v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)];
      *(_BYTE *)(v9 + 24) = 1;
      SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v9, 0);
    }
    v10 = (UIRegion *)&v2->m_endowmentIcon_Underlay->vfptr;
    v2->m_endowmentItemID = v6;
    v2->m_endowmentSpellID = v7[22].id;
    UIRegion::ClearImage(v10);
    v11 = ClientMagicSystem::GetMagicSystem();
    v12 = v11;
    if ( v11 )
    {
      v13 = ClientMagicSystem::GetSpellIcon(v11, v2->m_endowmentSpellID);
      if ( v13 )
      {
        UIRegion::SetBlitMode((UIRegion *)&v2->m_endowmentIcon_Underlay->vfptr, Blit_3Alpha);
        v14 = (Graphic *)operator new(0xCu);
        if ( v14 )
          Graphic::Graphic(v14, v13);
        else
          v15 = 0;
        UIRegion::SetImage((UIRegion *)&v2->m_endowmentIcon_Underlay->vfptr, v15);
      }
      UIRegion::ClearImage((UIRegion *)&v2->m_endowmentIcon_Overlay->vfptr);
      UIRegion::SetBlitMode((UIRegion *)&v2->m_endowmentIcon_Overlay->vfptr, Blit_3Alpha);
      v16 = (Graphic *)operator new(0xCu);
      if ( v16 )
      {
        v17 = ACCWeenieObject::GetDragIcon((ACCWeenieObject *)v7);
        Graphic::Graphic(v16, v17);
      }
      else
      {
        v18 = 0;
      }
      UIRegion::SetImage((UIRegion *)&v2->m_endowmentIcon_Overlay->vfptr, v18);
      v19 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
      v20 = v2->m_endowmentIcon_Selected;
      if ( v2->m_subMenus[v19].m_endowmentSelected )
        ((void (__stdcall *)(signed int, int))v20->vfptr[2].__vecDelDtor)(1, v23);
      else
        ((void (__stdcall *)(_DWORD, int))v20->vfptr[2].__vecDelDtor)(0, v23);
      CSpellBase::CSpellBase((CSpellBase *)&v30);
      ClientMagicSystem::InqSpellBase(v12, v2->m_endowmentSpellID, (CSpellBase *)&v30);
      v21 = SpellComponentBase::InqName((SpellComponentBase *)&v30, &result);
      v22 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v7, &v27, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &_value,
        0,
        L"%s (%hs)\nDouble-click to cast this spell",
        v22->m_charbuffer,
        v21->m_buffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v27);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&result);
      StringInfo::StringInfo(&_text);
      StringInfo::SetLiteralValue(&_text, &_value, 1);
      UIElement::SetTooltip(v2->m_endowmentIcon, &_text);
      *((_DWORD *)&v2->m_endowmentIcon->0 + 41) |= 0x20u;
      ((void (__cdecl *)(signed int))v2->m_endowmentIcon->vfptr[2].__vecDelDtor)(1);
      StringInfo::~StringInfo((StringInfo *)&result);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strTooltip);
      CSpellBase::~CSpellBase((CSpellBase *)&_text.m_strComment);
      goto LABEL_28;
    }
  }
}
// 4C6120: could not find valid save-restore pair for edi

//----- (004C6400) --------------------------------------------------------  // acclient.c:247942
void __thiscall gmSpellcastingUI::RecvNotice_CastCurrentSpell(gmSpellcastingUI *this)
{
  gmSpellcastingUI::Cast((gmSpellcastingUI *)((char *)this - 1528));
}

//----- (004C6410) --------------------------------------------------------  // acclient.c:247948
void __thiscall SpellCastSubMenu::RemoveSpellFromPlayerModule(SpellCastSubMenu *this, unsigned int _spellID)
{
  SpellCastSubMenu *v2; // ebx@1
  InterfaceSystem *v3; // eax@1
  Interface *v4; // esi@1
  int v5; // ebp@3
  CPlayerModule *v6; // esi@5
  int v7; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v10; // [sp+18h] [bp-Ch]@3
  InterfacePtr<CPlayerModule> playerModule; // [sp+1Ch] [bp-8h]@1

  v2 = this;
  _rpInterface = 0;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType_4, &_rpInterface);
  v7 = (int)_rpInterface;
  v4 = _rpInterface;
  playerModule.m_pInterface = 0;
  playerModule.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v5 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&playerModule, (int)&v10, v7, 0);
  if ( v4 )
    v4->vfptr->Release(v4);
  v6 = playerModule.m_pInterface;
  if ( (_DWORD)playerModule.m_pInterface )
  {
    if ( v5 >= 0 )
    {
      PlayerModule::RemoveSpellFavorite((PlayerModule *)&playerModule.m_pInterface->vfptr, _spellID, v2->m_tabIndex);
      CM_Character::Event_RemoveSpellFavorite(_spellID, v2->m_tabIndex);
    }
    v6->vfptr->Release((Interface *)v6);
  }
}

//----- (004C64C0) --------------------------------------------------------  // acclient.c:247987
void __thiscall SpellCastSubMenu::AddSpellToPlayerModule(SpellCastSubMenu *this, unsigned int _spellID, unsigned int _pos)
{
  SpellCastSubMenu *v3; // ebx@1
  InterfaceSystem *v4; // eax@1
  Interface *v5; // esi@1
  int v6; // ebp@3
  CPlayerModule *v7; // esi@5
  int v8; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v11; // [sp+18h] [bp-Ch]@3
  InterfacePtr<CPlayerModule> playerModule; // [sp+1Ch] [bp-8h]@1

  v3 = this;
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &CPlayerModule_ClassType_4, &_rpInterface);
  v8 = (int)_rpInterface;
  v5 = _rpInterface;
  playerModule.m_pInterface = 0;
  playerModule.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v6 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&playerModule, (int)&v11, v8, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v7 = playerModule.m_pInterface;
  if ( (_DWORD)playerModule.m_pInterface )
  {
    if ( v6 >= 0 )
    {
      PlayerModule::AddSpellFavorite((PlayerModule *)&playerModule.m_pInterface->vfptr, _spellID, _pos, v3->m_tabIndex);
      CM_Character::Event_AddSpellFavorite(_spellID, _pos, v3->m_tabIndex);
    }
    v7->vfptr->Release((Interface *)v7);
  }
}

//----- (004C6570) --------------------------------------------------------  // acclient.c:248026
void __thiscall SpellCastSubMenu::UpdateFromPlayerModule(SpellCastSubMenu *this)
{
  SpellCastSubMenu *v1; // ebx@1
  UIElement_ItemList *v2; // ecx@1
  void *v3; // ebp@1
  InterfaceSystem *v4; // eax@1
  PSRefBufferCharData<unsigned short> *v5; // esi@1
  int v6; // edi@3
  CPlayerModule *v7; // ecx@5
  PackableList<unsigned long> *v8; // eax@7
  PackableLLNode<unsigned long> *v9; // esi@7
  InterfaceSystem *v10; // eax@7
  PSRefBufferCharData<unsigned short> *v11; // edi@7
  int v12; // ebx@9
  CACQualities *v13; // edi@11
  void *v14; // ebx@15
  const unsigned int v15; // edi@17
  void *v16; // eax@17
  void *v17; // eax@24
  unsigned int v18; // esi@24
  unsigned int *v19; // eax@25
  SpellCastSubMenu *v20; // edi@28
  UIElement_UIItem *v21; // esi@28
  ClientMagicSystem *v22; // edi@28
  AC1Legacy::PStringBase<char> *v23; // eax@30
  PackableList<unsigned long> *v24; // edi@30
  char *v25; // esi@33
  AC1Legacy::PSRefBuffer<char> *v26; // esi@36
  AC1Legacy::PSRefBuffer<char> *v27; // esi@39
  PackableLLNode<unsigned long> *v28; // eax@42
  SpellCastSubMenu *v29; // esi@44
  void *v30; // esi@44
  void *v31; // eax@45
  InterfaceVtbl *v32; // edx@46
  PlayerDesc *v33; // ecx@46
  void *v34; // esi@50
  void *v35; // eax@51
  int v36; // [sp-8h] [bp-160h]@1
  int v37; // [sp-8h] [bp-160h]@7
  PStringBase<unsigned short> strTooltip; // [sp+10h] [bp-148h]@1
  PackableList<unsigned long> *spellList; // [sp+14h] [bp-144h]@1
  SpellCastSubMenu *v40; // [sp+18h] [bp-140h]@1
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-13Ch]@7
  InterfacePtr<CPlayerModule> playerModule; // [sp+24h] [bp-134h]@1
  PackableLLIter<unsigned long> iter; // [sp+2Ch] [bp-12Ch]@9
  TResult result; // [sp+34h] [bp-124h]@3
  CSpellBase spellBase; // [sp+38h] [bp-120h]@29
  StringInfo _text; // [sp+C8h] [bp-90h]@33

  v1 = this;
  v2 = this->m_spellItemList;
  v3 = 0;
  v40 = v1;
  v1->m_numSpells = 0;
  UIElement_ItemList::ItemList_Flush(v2);
  strTooltip.m_charbuffer = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, (TResult *)&spellList, &CPlayerModule_ClassType_4, (Interface **)&strTooltip);
  v36 = (int)strTooltip.m_charbuffer;
  v5 = strTooltip.m_charbuffer;
  playerModule.m_pInterface = 0;
  playerModule.m_trStatus.m_val = 0;
  if ( strTooltip.m_charbuffer )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&strTooltip.m_charbuffer->m_data[0] + 16))(strTooltip.m_charbuffer);
  v6 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&playerModule, (int)&result, v36, 0);
  if ( v5 )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&v5->m_data[0] + 20))(v5);
  v7 = playerModule.m_pInterface;
  if ( (_DWORD)playerModule.m_pInterface )
  {
    if ( v6 >= 0 )
    {
      v8 = PlayerModule::GetFavoriteSpellsList((PlayerModule *)&playerModule.m_pInterface->vfptr, v1->m_tabIndex);
      v9 = v8->head;
      spellList = v8;
      strTooltip.m_charbuffer = 0;
      v10 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v10, &result, &PlayerDesc_ClassType_14, (Interface **)&strTooltip);
      v37 = (int)strTooltip.m_charbuffer;
      v11 = strTooltip.m_charbuffer;
      playerDesc.m_pInterface = 0;
      playerDesc.m_trStatus.m_val = 0;
      if ( strTooltip.m_charbuffer )
        (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&strTooltip.m_charbuffer->m_data[0]
                                                                      + 16))(strTooltip.m_charbuffer);
      v12 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&iter, v37, 0);
      if ( v11 )
        (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&v11->m_data[0] + 20))(v11);
      v13 = (CACQualities *)playerDesc.m_pInterface;
      if ( !(_DWORD)playerDesc.m_pInterface )
        goto LABEL_14;
      if ( v12 < 0 )
      {
        playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
LABEL_14:
        ((void (*)(void))playerModule.m_pInterface->vfptr->Release)();
        return;
      }
      v14 = 0;
      if ( v9 )
      {
        do
        {
          if ( !CACQualities::IsSpellKnown(v13, v9->data) )
          {
            v15 = v9->data;
            v16 = operator new(8u);
            if ( v16 )
            {
              *(_DWORD *)v16 = v15;
              *((_DWORD *)v16 + 1) = v3;
            }
            else
            {
              v16 = 0;
            }
            v13 = (CACQualities *)playerDesc.m_pInterface;
            v3 = v16;
            if ( !v14 )
              v14 = v16;
          }
          v9 = v9->next;
        }
        while ( v9 );
        while ( v3 )
        {
          v17 = v3;
          v3 = (void *)*((_DWORD *)v3 + 1);
          v18 = *(_DWORD *)v17;
          operator delete(v17);
          SpellCastSubMenu::RemoveSpellFromPlayerModule(v40, v18);
        }
      }
      iter._current = spellList->head;
      v19 = &iter._current->data;
      if ( iter._current )
      {
        while ( 1 )
        {
          v20 = v40;
          v21 = UIElement_ItemList::ItemList_AddSpellShortcut(v40->m_spellItemList, *v19);
          ++v20->m_numSpells;
          v22 = ClientMagicSystem::GetMagicSystem();
          if ( !v22 )
            break;
          CSpellBase::CSpellBase(&spellBase);
          if ( ClientMagicSystem::InqSpellBase(v22, iter._current->data, &spellBase) )
          {
            v23 = SpellComponentBase::InqName(
                    (SpellComponentBase *)&spellBase,
                    (AC1Legacy::PStringBase<char> *)&spellList);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &strTooltip,
              0,
              L"%hs\nDouble-click to cast this spell",
              v23->m_buffer->m_data);
            v24 = spellList;
            if ( !InterlockedDecrement((volatile LONG *)&spellList->head) && v24 )
              v24->vfptr->__vecDelDtor((PackObj *)v24, 1u);
            StringInfo::StringInfo(&_text);
            StringInfo::SetLiteralValue(&_text, &strTooltip, 1);
            UIElement::SetTooltip((UIElement *)&v21->vfptr, &_text);
            *((_DWORD *)&v21->0 + 41) |= 0x20u;
            StringInfo::~StringInfo(&_text);
            v25 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v25 )
              (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
          }
          MetaSpell::~MetaSpell(&spellBase._meta_spell);
          v26 = spellBase._desc.m_buffer;
          spellBase._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
          if ( !InterlockedDecrement((volatile LONG *)&spellBase._desc.m_buffer->m_cRef) && v26 )
            v26->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v26, 1u);
          v27 = spellBase._name.m_buffer;
          if ( !InterlockedDecrement((volatile LONG *)&spellBase._name.m_buffer->m_cRef) && v27 )
            v27->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v27, 1u);
          v28 = iter._current->next;
          spellBase.vfptr = (PackObjVtbl *)&PackObj::vftable;
          iter._current = v28;
          if ( !v28 )
          {
            v13 = (CACQualities *)playerDesc.m_pInterface;
            goto LABEL_44;
          }
          v19 = &iter._current->data;
        }
        v34 = v3;
        while ( v34 )
        {
          v35 = v34;
          v34 = (void *)*((_DWORD *)v34 + 1);
          operator delete(v35);
        }
        v33 = playerDesc.m_pInterface;
        v32 = playerDesc.m_pInterface->vfptr;
      }
      else
      {
LABEL_44:
        v29 = v40;
        SpellCastSubMenu::SetSelected(v40, v40->m_selectedSpellID);
        SpellCastSubMenu::UpdateShortcutOverlays(v29);
        v30 = v3;
        while ( v30 )
        {
          v31 = v30;
          v30 = (void *)*((_DWORD *)v30 + 1);
          operator delete(v31);
        }
        v32 = v13->vfptr;
        v33 = (PlayerDesc *)v13;
      }
      v32->Release((Interface *)v33);
      v7 = playerModule.m_pInterface;
    }
    ((void (*)(void))v7->vfptr->Release)();
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004C68F0) --------------------------------------------------------  // acclient.c:248247
unsigned int __thiscall SpellCastSubMenu::RemoveSpellFromMenu(SpellCastSubMenu *this, unsigned int _spellID)
{
  SpellCastSubMenu *v2; // edi@1
  unsigned int result; // eax@2
  int v4; // ebp@3
  unsigned int v5; // ebx@3
  UIElement *v6; // eax@4
  UIElement_UIItem *v7; // eax@5
  UIElement_UIItem *v8; // esi@5

  v2 = this;
  if ( _spellID )
  {
    v4 = UIElement_ItemList::GetNumUIItems(this->m_spellItemList);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_9:
      result = -1;
    }
    else
    {
      while ( 1 )
      {
        v6 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_spellItemList->vfptr, v5);
        if ( v6 )
        {
          v7 = (UIElement_UIItem *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
          v8 = v7;
          if ( v7 )
          {
            if ( UIElement_UIItem::UIItem_GetState(v7) == (UIElement *)268435485 && v8->spellID == _spellID )
              break;
          }
        }
        ++v5;
        if ( (signed int)v5 >= v4 )
          goto LABEL_9;
      }
      --v2->m_numSpells;
      SpellCastSubMenu::RemoveSpellFromPlayerModule(v2, _spellID);
      SpellCastSubMenu::UpdateFromPlayerModule(v2);
      if ( _spellID == v2->m_selectedSpellID )
        SpellCastSubMenu::SetSelected(v2, 0);
      result = v5;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (004C69A0) --------------------------------------------------------  // acclient.c:248302
void __thiscall gmSpellcastingUI::RecvNotice_PlayerDescReceived(gmSpellcastingUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  SpellCastSubMenu *v3; // esi@1
  signed int v4; // edi@1

  v3 = (SpellCastSubMenu *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9];
  v4 = 8;
  do
  {
    SpellCastSubMenu::UpdateFromPlayerModule(v3);
    ++v3;
    --v4;
  }
  while ( v4 );
}

//----- (004C69D0) --------------------------------------------------------  // acclient.c:248319
void __thiscall gmSpellcastingUI::RecvNotice_RemoveSpellShortcut(gmSpellcastingUI *this, unsigned int i_spellID)
{
  int v2; // eax@1
  int v3; // ecx@1

  v2 = gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528));
  SpellCastSubMenu::RemoveSpellFromMenu((SpellCastSubMenu *)(28 * v2 + v3 + 1576), i_spellID);
}

//----- (004C6A00) --------------------------------------------------------  // acclient.c:248329
void __thiscall gmSpellcastingUI::RecvNotice_SpellRemoved(gmSpellcastingUI *this, unsigned int i_eSpellID)
{
  SpellCastSubMenu *v2; // esi@1
  signed int v3; // edi@1

  v2 = (SpellCastSubMenu *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9];
  v3 = 8;
  do
  {
    SpellCastSubMenu::UpdateFromPlayerModule(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
}

//----- (004C6A30) --------------------------------------------------------  // acclient.c:248346
void __thiscall gmSpellcastingUI::UpdateCastButtonTooltip(gmSpellcastingUI *this)
{
  gmSpellcastingUI *v1; // esi@1
  int v2; // edi@2
  unsigned int v3; // ebp@2
  HashBaseData<unsigned long> *v4; // ebx@9
  char *v5; // esi@13
  AC1Legacy::PStringBase<char> *v6; // edi@15
  PStringBase<unsigned short> *v7; // eax@15
  const unsigned __int16 *v8; // eax@15
  char *v9; // edi@15
  unsigned int v10; // edi@18
  AC1Legacy::PSRefBuffer<char> *v11; // edi@21
  HashBaseData<unsigned long> *v12; // eax@29
  PStringBase<unsigned short> *v13; // eax@30
  AC1Legacy::PStringBase<char> *v14; // eax@33
  PSRefBufferCharData<unsigned short> **v15; // eax@33
  PSRefBufferCharData<unsigned short> **v16; // ebp@33
  char *v17; // edi@34
  int v18; // edi@38
  AC1Legacy::PSRefBuffer<char> *v19; // edi@41
  char *v20; // ST10_4@47
  AC1Legacy::PStringBase<char> *v21; // eax@49
  HashBaseData<unsigned long> *v22; // eax@49
  PStringBase<unsigned short> *v23; // eax@50
  char *v24; // ST10_4@51
  AC1Legacy::PStringBase<char> *v25; // eax@53
  int v26; // edi@53
  char *v27; // esi@60
  LONG v28; // eax@13
  PStringBase<unsigned short> strTooltip; // [sp+18h] [bp-A8h]@2
  ItemUses uses; // [sp+1Ch] [bp-A4h]@24
  PStringBase<unsigned short> strSpellName; // [sp+20h] [bp-A0h]@2
  AC1Legacy::PStringBase<char> result; // [sp+24h] [bp-9Ch]@15
  ClientMagicSystem *pMagicSystem; // [sp+28h] [bp-98h]@1
  unsigned int selectedSpellID; // [sp+2Ch] [bp-94h]@2
  CSpellBase spellBase; // [sp+30h] [bp-90h]@14

  v1 = this;
  pMagicSystem = ClientMagicSystem::GetMagicSystem();
  if ( !pMagicSystem )
    return;
  v2 = v1->m_subMenus[7].m_numSpells
     + v1->m_subMenus[6].m_numSpells
     + v1->m_subMenus[5].m_numSpells
     + v1->m_subMenus[4].m_numSpells
     + v1->m_subMenus[3].m_numSpells
     + v1->m_subMenus[2].m_numSpells
     + v1->m_subMenus[1].m_numSpells
     + v1->m_subMenus[0].m_numSpells;
  ((void (__stdcall *)(signed int))v1->m_spellcastButton->vfptr[13].__vecDelDtor)(13);
  *((_DWORD *)&v1->m_spellcastButton->0 + 41) &= 0xFFFFFFDF;
  UIElement::ClearTooltip((UIElement *)&v1->m_spellcastButton->vfptr);
  v3 = v1->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v1)].m_selectedSpellID;
  strSpellName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  selectedSpellID = v3;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  UIElement_Text::ClearAllText(v1->m_spellName);
  strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( v1->m_endowmentItemID )
  {
    if ( !v3 )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(v1->m_endowmentItemID);
      if ( !v4 )
      {
        if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8])
          && strTooltip.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
          (**(void (__thiscall ***)(unsigned __int16 *, signed int))&strTooltip.m_charbuffer[-1].m_data[6])(
            &strTooltip.m_charbuffer[-1].m_data[6],
            1);
        v5 = (char *)&strSpellName.m_charbuffer[-1].m_data[6];
        v28 = InterlockedDecrement((volatile LONG *)&strSpellName.m_charbuffer[-1].m_data[8]);
        goto LABEL_64;
      }
      CSpellBase::CSpellBase(&spellBase);
      if ( ClientMagicSystem::InqSpellBase(pMagicSystem, v1->m_endowmentSpellID, &spellBase) )
      {
        v6 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, &result);
        v7 = ACCWeenieObject::GetObjectNameWide(
               (ACCWeenieObject *)v4,
               (PStringBase<unsigned short> *)&selectedSpellID,
               NAME_APPROPRIATE,
               0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&pMagicSystem,
          0,
          L"%s (%hs)",
          v7->m_charbuffer,
          v6->m_buffer->m_data);
        PStringBase<unsigned short>::operator=(&strSpellName, v8);
        v9 = (char *)&pMagicSystem[-1].m_hashSpellComponentIconTable.m_intrusiveTable.m_aInplaceBuckets[22];
        if ( !InterlockedDecrement((volatile LONG *)&pMagicSystem[-1].m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets)
          && v9 )
          (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
        v10 = selectedSpellID - 20;
        if ( !InterlockedDecrement((volatile LONG *)(selectedSpellID - 20 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        v11 = result.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      }
      ItemUses::ItemUses(&uses, (const unsigned int)v4[18].vfptr);
      if ( ItemUses::IsUseable_SelfTarget(&uses) )
      {
        ((void (__stdcall *)(signed int))v1->m_spellcastButton->vfptr[13].__vecDelDtor)(1);
        PStringBase<unsigned short>::sprintf(&strTooltip, L"USE the %s", strSpellName.m_charbuffer);
      }
      else if ( ACCWeenieObject::selectedID )
      {
        if ( ItemHolder::TargetCompatibleWithObject(ACCWeenieObject::selectedID, v1->m_endowmentItemID, 1, 0) )
        {
          ((void (__stdcall *)(signed int))v1->m_spellcastButton->vfptr[13].__vecDelDtor)(1);
          PStringBase<unsigned short>::sprintf(&strTooltip, L"USE the %s", strSpellName.m_charbuffer);
          v12 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
          if ( v12 )
          {
            v13 = ACCWeenieObject::GetObjectNameWide(
                    (ACCWeenieObject *)v12,
                    (PStringBase<unsigned short> *)&result,
                    NAME_APPROPRIATE,
                    0);
            PStringBase<unsigned short>::sprintf_append(&strTooltip, L" on %s", v13->m_charbuffer);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          }
        }
        else
        {
          PStringBase<unsigned short>::sprintf(
            &strTooltip,
            L"You must select an appropriate\ntarget for the %s",
            strSpellName.m_charbuffer);
        }
      }
      else
      {
        PStringBase<unsigned short>::sprintf(
          &strTooltip,
          L"You must select a target for the %s",
          strSpellName.m_charbuffer);
      }
      goto LABEL_56;
    }
  }
  else if ( !v3 )
  {
    if ( v1->m_endowmentPresent || v2 )
      PStringBase<unsigned short>::set(&strTooltip, L"Select a spell to cast");
    else
      PStringBase<unsigned short>::set(&strTooltip, L"You have no spells ready to cast");
    goto LABEL_57;
  }
  CSpellBase::CSpellBase(&spellBase);
  if ( ClientMagicSystem::InqSpellBase(pMagicSystem, v3, &spellBase) )
  {
    v14 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, &result);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&uses,
      0,
      v14->m_buffer->m_data);
    v16 = v15;
    if ( strSpellName.m_charbuffer != *v15 )
    {
      v17 = (char *)&strSpellName.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strSpellName.m_charbuffer[-1].m_data[8]) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      strSpellName.m_charbuffer = *v16;
      InterlockedIncrement((volatile LONG *)&strSpellName.m_charbuffer[-1].m_data[8]);
    }
    v18 = uses._useable_bitfield - 20;
    if ( !InterlockedDecrement((volatile LONG *)(uses._useable_bitfield - 20 + 4)) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    v19 = result.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v19 )
      v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
    if ( CSpellBase::IsUntargeted(&spellBase) || spellBase._bitfield & 8 )
    {
      ((void (__stdcall *)(signed int))v1->m_spellcastButton->vfptr[13].__vecDelDtor)(1);
      v25 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, (AC1Legacy::PStringBase<char> *)&uses);
      PStringBase<unsigned short>::sprintf(&strTooltip, L"CAST %hs", v25->m_buffer->m_data);
      v26 = uses._useable_bitfield;
      if ( !InterlockedDecrement((volatile LONG *)(uses._useable_bitfield + 4)) && v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
      goto LABEL_56;
    }
    if ( ACCWeenieObject::selectedID )
    {
      ClientMagicSystem::GetMagicSystem();
      if ( ClientMagicSystem::ObjectCompatibleWithSpell(ACCWeenieObject::selectedID, selectedSpellID, 1, 0) )
      {
        ((void (__stdcall *)(_DWORD))v1->m_spellcastButton->vfptr[13].__vecDelDtor)(1);
        v21 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, (AC1Legacy::PStringBase<char> *)&uses);
        PStringBase<unsigned short>::sprintf(&strTooltip, L"CAST %hs", v21->m_buffer->m_data);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&uses);
        v22 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
        if ( v22 )
        {
          v23 = ACCWeenieObject::GetObjectNameWide(
                  (ACCWeenieObject *)v22,
                  (PStringBase<unsigned short> *)&uses,
                  NAME_APPROPRIATE,
                  0);
          PStringBase<unsigned short>::sprintf_append(&strTooltip, L" on %s", v23->m_charbuffer);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&uses);
        }
        goto LABEL_56;
      }
      v24 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, (AC1Legacy::PStringBase<char> *)&uses)->m_buffer->m_data;
      PStringBase<unsigned short>::sprintf(&strTooltip, L"You must select an appropriate target for %hs", v24);
    }
    else
    {
      v20 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, (AC1Legacy::PStringBase<char> *)&uses)->m_buffer->m_data;
      PStringBase<unsigned short>::sprintf(&strTooltip, L"You must select a target for %hs", v20);
    }
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&uses);
  }
LABEL_56:
  CSpellBase::~CSpellBase(&spellBase);
LABEL_57:
  if ( *(_DWORD *)&strTooltip.m_charbuffer[-1].m_data[14] == 1 )
  {
    *((_DWORD *)&v1->m_spellcastButton->0 + 41) &= 0xFFFFFFDF;
    UIElement::ClearTooltip((UIElement *)&v1->m_spellcastButton->vfptr);
  }
  else
  {
    UIElement_Text::SetText(v1->m_spellName, &strSpellName);
    StringInfo::StringInfo((StringInfo *)&spellBase);
    StringInfo::SetLiteralValue((StringInfo *)&spellBase, &strTooltip, 1);
    UIElement::SetTooltip((UIElement *)&v1->m_spellcastButton->vfptr, (StringInfo *)&spellBase);
    *((_DWORD *)&v1->m_spellcastButton->0 + 41) |= 0x20u;
    StringInfo::~StringInfo((StringInfo *)&spellBase);
  }
  v27 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v27 )
    (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
  v5 = (char *)&strSpellName.m_charbuffer[-1].m_data[6];
  v28 = InterlockedDecrement((volatile LONG *)&strSpellName.m_charbuffer[-1].m_data[8]);
LABEL_64:
  if ( !v28 )
  {
    if ( v5 )
      (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  }
}
// 7B63B8: using guessed type wchar_t aYouMustSelec_7[33];

//----- (004C7060) --------------------------------------------------------  // acclient.c:248596
void __thiscall SpellCastSubMenu::AddFavorite(SpellCastSubMenu *this, unsigned int _spellID, int _pos, bool allowReplace)
{
  SpellCastSubMenu *v4; // esi@1
  InterfaceSystem *v5; // eax@1
  PSRefBufferCharData<unsigned short> *v6; // edi@1
  CPlayerModule *v7; // ebp@5
  PackableList<unsigned long> *v8; // eax@7
  PackableLLNode<unsigned long> *v9; // eax@8
  int v10; // eax@14
  int v11; // ebp@14
  UIElement_UIItem *v12; // ebx@17
  AC1Legacy::PStringBase<char> *v13; // eax@20
  int v14; // [sp-8h] [bp-14Ch]@1
  PStringBase<unsigned short> strTooltip; // [sp+10h] [bp-134h]@1
  TResult result; // [sp+14h] [bp-130h]@1
  InterfacePtr<CPlayerModule> playerModule; // [sp+18h] [bp-12Ch]@1
  char v18; // [sp+20h] [bp-124h]@3
  StringInfo _text; // [sp+24h] [bp-120h]@20
  CSpellBase spellBase; // [sp+B4h] [bp-90h]@19

  v4 = this;
  strTooltip.m_charbuffer = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, &result, &CPlayerModule_ClassType_4, (Interface **)&strTooltip);
  v14 = (int)strTooltip.m_charbuffer;
  v6 = strTooltip.m_charbuffer;
  playerModule.m_pInterface = 0;
  playerModule.m_trStatus.m_val = 0;
  if ( strTooltip.m_charbuffer )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&strTooltip.m_charbuffer->m_data[0] + 16))(strTooltip.m_charbuffer);
  strTooltip.m_charbuffer = *(PSRefBufferCharData<unsigned short> **)InterfacePtr<CPlayerModule>::_QueryInterface(
                                                                       &playerModule,
                                                                       (int)&v18,
                                                                       v14,
                                                                       0);
  if ( v6 )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&v6->m_data[0] + 20))(v6);
  v7 = playerModule.m_pInterface;
  if ( !(_DWORD)playerModule.m_pInterface )
    return;
  if ( (signed int)strTooltip.m_charbuffer < 0 )
  {
LABEL_12:
    v7->vfptr->Release((Interface *)v7);
    return;
  }
  v8 = PlayerModule::GetFavoriteSpellsList((PlayerModule *)&playerModule.m_pInterface->vfptr, v4->m_tabIndex);
  if ( allowReplace || (v9 = v8->head) == 0 )
  {
LABEL_11:
    if ( _spellID )
    {
      v10 = SpellCastSubMenu::RemoveSpellFromMenu(v4, _spellID);
      v11 = _pos;
      if ( v10 != -1 && v10 < _pos )
        v11 = _pos - 1;
      v12 = UIElement_ItemList::ItemList_InsertSpellShortcut(v4->m_spellItemList, _spellID, v11);
      ++v4->m_numSpells;
      strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)ClientMagicSystem::GetMagicSystem();
      if ( strTooltip.m_charbuffer )
      {
        CSpellBase::CSpellBase(&spellBase);
        if ( ClientMagicSystem::InqSpellBase((ClientMagicSystem *)strTooltip.m_charbuffer, _spellID, &spellBase) )
        {
          v13 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, (AC1Legacy::PStringBase<char> *)&result);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &strTooltip,
            0,
            L"%hs\nDouble-click to cast this spell",
            v13->m_buffer->m_data);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&result);
          StringInfo::StringInfo(&_text);
          StringInfo::SetLiteralValue(&_text, &strTooltip, 1);
          UIElement::SetTooltip((UIElement *)&v12->vfptr, &_text);
          *((_DWORD *)&v12->0 + 41) |= 0x20u;
          StringInfo::~StringInfo(&_text);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strTooltip);
        }
        if ( v11 == -1 )
          v11 = v4->m_numSpells;
        SpellCastSubMenu::AddSpellToPlayerModule(v4, _spellID, v11);
        SpellCastSubMenu::SetSelected(v4, _spellID);
        SpellCastSubMenu::UpdateShortcutOverlays(v4);
        CSpellBase::~CSpellBase(&spellBase);
        ((void (*)(void))playerModule.m_pInterface->vfptr->Release)();
      }
      else
      {
        ((void (*)(void))playerModule.m_pInterface->vfptr->Release)();
      }
      return;
    }
    goto LABEL_12;
  }
  while ( v9->data != _spellID )
  {
    v9 = v9->next;
    if ( !v9 )
      goto LABEL_11;
  }
  v7->vfptr->Release((Interface *)v7);
}

//----- (004C7270) --------------------------------------------------------  // acclient.c:248700
void __thiscall gmSpellcastingUI::RecvNotice_SelectionChanged(gmSpellcastingUI *this)
{
  gmSpellcastingUI::UpdateCastButtonTooltip((gmSpellcastingUI *)((char *)this - 1528));
}

//----- (004C7280) --------------------------------------------------------  // acclient.c:248706
void __userpurge gmSpellcastingUI::RecvNotice_SetCombatMode(gmSpellcastingUI *this@<ecx>, int a2@<edi>, COMBAT_MODE i_eCombatMode)
{
  gmSpellcastingUI *v3; // esi@2

  if ( i_eCombatMode == 8 )
  {
    v3 = (gmSpellcastingUI *)((char *)this - 1528);
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22][1].m_hashNext)(
      &this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22],
      1);
    gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v3);
  }
  else
  {
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22][1].m_hashNext)(
      &this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22],
      0);
  }
}

//----- (004C72D0) --------------------------------------------------------  // acclient.c:248728
void __userpurge gmSpellcastingUI::RecvNotice_ServerSaysMoveItem(gmSpellcastingUI *this@<ecx>, int a2@<edi>, unsigned int i_itemID, unsigned int i_oldContainer, unsigned int i_oldWielder, unsigned int i_oldLocation, unsigned int i_newContainer, int i_place, unsigned int i_newWielder, unsigned int i_newLocation)
{
  unsigned int v10; // edx@2
  unsigned int v11; // eax@6
  gmSpellcastingUI *v12; // esi@9

  if ( SmartBox::smartbox )
    v10 = SmartBox::smartbox->player_id;
  else
    v10 = 0;
  if ( i_oldWielder == v10
    || (!SmartBox::smartbox ? (v11 = 0) : (v11 = SmartBox::smartbox->player_id), i_newWielder == v11) )
  {
    v12 = (gmSpellcastingUI *)((char *)this - 1528);
    gmSpellcastingUI::UpdateEndowmentIcon((gmSpellcastingUI *)((char *)this - 1528), a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v12);
  }
}

//----- (004C7320) --------------------------------------------------------  // acclient.c:248748
void __userpurge gmSpellcastingUI::AddSpellShortcut(gmSpellcastingUI *this@<ecx>, int a2@<edi>, unsigned int i_spellID, int _pos, bool allowReplace)
{
  gmSpellcastingUI *v5; // esi@1
  int v6; // eax@1

  v5 = this;
  v6 = gmSpellcastingUI::GetOpenSubMenuIndex(this);
  SpellCastSubMenu::AddFavorite(&v5->m_subMenus[v6], i_spellID, _pos, allowReplace);
  gmSpellcastingUI::UpdateEndowmentIcon(v5, a2);
  gmSpellcastingUI::UpdateCastButtonTooltip(v5);
}

//----- (004C7360) --------------------------------------------------------  // acclient.c:248761
void __thiscall gmSpellcastingUI::RecvNotice_ItemListBeginDrag(gmSpellcastingUI *this, UIElement *i_itemList, int i_slotNum)
{
  int v3; // edi@1
  signed int v4; // esi@1
  UIElement_ListBox **v5; // eax@1
  UIElement *v6; // eax@5
  int v7; // eax@6
  unsigned int v8; // eax@7

  v3 = (int)this;
  v4 = 0;
  v5 = (UIElement_ListBox **)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10];
  while ( (UIElement *)*v5 != i_itemList )
  {
    ++v4;
    v5 += 7;
    if ( v4 >= 8 )
      return;
  }
  v6 = UIElement_ListBox::GetItem(*v5, i_slotNum);
  if ( v6 )
  {
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 1536);
      if ( v8 )
      {
        SpellCastSubMenu::RemoveSpellFromMenu((SpellCastSubMenu *)(28 * v4 + v3 + 48), v8);
        gmSpellcastingUI::UpdateEndowmentIcon((gmSpellcastingUI *)(v3 - 1528), v3);
        gmSpellcastingUI::UpdateCastButtonTooltip((gmSpellcastingUI *)(v3 - 1528));
      }
    }
  }
}

//----- (004C73E0) --------------------------------------------------------  // acclient.c:248798
void __usercall gmSpellcastingUI::RecvNotice_NextSpellTab(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  HashSet<UIElement *>Vtbl *v2; // edx@1
  gmSpellcastingUI *v3; // esi@2
  signed int v4; // eax@2
  UIElement_Panel *v5; // edx@2

  v2 = this->m_hashElementsRegisteredWith.vfptr;
  if ( v2 )
  {
    v3 = (gmSpellcastingUI *)((char *)this - 1528);
    v4 = gmSpellcastingUI::GetNextTabID((unsigned int)v2[439].__vecDelDtor);
    UIElement_Panel::OpenTab(v5, v4);
    gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v3);
  }
}

//----- (004C7420) --------------------------------------------------------  // acclient.c:248817
void __usercall gmSpellcastingUI::RecvNotice_PrevSpellTab(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  HashSet<UIElement *>Vtbl *v2; // edx@1
  gmSpellcastingUI *v3; // esi@2
  signed int v4; // eax@2
  UIElement_Panel *v5; // edx@2

  v2 = this->m_hashElementsRegisteredWith.vfptr;
  if ( v2 )
  {
    v3 = (gmSpellcastingUI *)((char *)this - 1528);
    v4 = gmSpellcastingUI::GetPrevTabID((unsigned int)v2[439].__vecDelDtor);
    UIElement_Panel::OpenTab(v5, v4);
    gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v3);
  }
}

//----- (004C7460) --------------------------------------------------------  // acclient.c:248836
void __thiscall gmSpellcastingUI::RecvNotice_NextSpellSelection(gmSpellcastingUI *this)
{
  int v1; // edi@1
  gmSpellcastingUI *v2; // esi@1
  UIElement_ItemList *v3; // ebx@1
  int v4; // ebp@1
  int v5; // eax@3
  int v6; // eax@5
  unsigned int v7; // edi@7
  UIElement *v8; // eax@8
  int v9; // eax@10
  int v10; // edx@10
  int v11; // eax@16
  UIElement_ListBox *v12; // ecx@16
  UIElement *v13; // eax@17
  int v14; // eax@18
  unsigned int v15; // eax@19
  int which; // [sp+10h] [bp-8h]@6
  gmSpellcastingUI *v17; // [sp+14h] [bp-4h]@1

  v1 = (int)this;
  v2 = (gmSpellcastingUI *)((char *)this - 1528);
  v17 = this;
  v3 = (UIElement_ItemList *)*((_DWORD *)&this[-1].m_children
                             + 7 * gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528))
                             + 418);
  v4 = UIElement_ItemList::GetNumUIItems(v3);
  if ( !v4 )
  {
    if ( !*(_BYTE *)(v1 + 36) )
      return;
    goto LABEL_3;
  }
  if ( v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)].m_endowmentSelected )
  {
    v6 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
    SpellCastSubMenu::SelectSpellFromIndex(&v2->m_subMenus[v6], 0);
    goto LABEL_21;
  }
  which = 0;
  if ( !v3 )
    goto LABEL_16;
  v7 = 0;
  if ( v4 <= 0 )
    goto LABEL_16;
  while ( 1 )
  {
    v8 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v3->vfptr, v7);
    if ( v8 )
    {
      if ( v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506) )
      {
        v9 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
        if ( *(_DWORD *)(v10 + 1536) == v2->m_subMenus[v9].m_selectedSpellID )
          break;
      }
    }
    ++v7;
    if ( (signed int)v7 >= v4 )
      goto LABEL_16;
  }
  v1 = v7 + 1;
  which = v1;
  if ( v1 != v4 )
  {
LABEL_16:
    v11 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
    v12 = (UIElement_ListBox *)&v2->m_subMenus[v11].m_spellItemList->vfptr;
    v1 = (int)&v2->m_subMenus[v11];
    if ( v12 )
    {
      v13 = UIElement_ListBox::GetItem(v12, which);
      if ( v13 )
      {
        v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)268435506);
        if ( v14 )
        {
          v15 = *(_DWORD *)(v14 + 1536);
          if ( v15 )
            SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v1, v15);
        }
      }
    }
    goto LABEL_21;
  }
  if ( !LOBYTE(v17->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]) )
  {
    which = 0;
    goto LABEL_16;
  }
LABEL_3:
  v5 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
  v2->m_subMenus[v5].m_endowmentSelected = 1;
  SpellCastSubMenu::SetSelected(&v2->m_subMenus[v5], 0);
LABEL_21:
  gmSpellcastingUI::UpdateEndowmentIcon(v2, v1);
  gmSpellcastingUI::UpdateCastButtonTooltip(v2);
}

//----- (004C75D0) --------------------------------------------------------  // acclient.c:248936
void __thiscall gmSpellcastingUI::RecvNotice_PrevSpellSelection(gmSpellcastingUI *this)
{
  int v1; // edi@1
  gmSpellcastingUI *v2; // esi@1
  UIElement_ItemList *v3; // ebx@1
  int v4; // ebp@1
  int v5; // eax@3
  int v6; // eax@5
  unsigned int v7; // edi@7
  UIElement *v8; // eax@8
  int v9; // eax@10
  int v10; // edx@10
  int v11; // eax@16
  UIElement_ListBox *v12; // ecx@16
  UIElement *v13; // eax@17
  int v14; // eax@18
  unsigned int v15; // eax@19
  int which; // [sp+10h] [bp-8h]@6
  gmSpellcastingUI *v17; // [sp+14h] [bp-4h]@1

  v1 = (int)this;
  v2 = (gmSpellcastingUI *)((char *)this - 1528);
  v17 = this;
  v3 = (UIElement_ItemList *)*((_DWORD *)&this[-1].m_children
                             + 7 * gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528))
                             + 418);
  v4 = UIElement_ItemList::GetNumUIItems(v3);
  if ( !v4 )
  {
    if ( !*(_BYTE *)(v1 + 36) )
      return;
    goto LABEL_3;
  }
  if ( v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)].m_endowmentSelected )
  {
    v6 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
    SpellCastSubMenu::SelectSpellFromIndex(&v2->m_subMenus[v6], v4 - 1);
    goto LABEL_21;
  }
  which = 0;
  if ( !v3 )
    goto LABEL_16;
  v7 = 0;
  if ( v4 <= 0 )
    goto LABEL_16;
  while ( 1 )
  {
    v8 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v3->vfptr, v7);
    if ( v8 )
    {
      if ( v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506) )
      {
        v9 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
        if ( *(_DWORD *)(v10 + 1536) == v2->m_subMenus[v9].m_selectedSpellID )
          break;
      }
    }
    ++v7;
    if ( (signed int)v7 >= v4 )
      goto LABEL_16;
  }
  v1 = v7 - 1;
  which = v1;
  if ( v1 >= 0 )
  {
LABEL_16:
    v11 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
    v12 = (UIElement_ListBox *)&v2->m_subMenus[v11].m_spellItemList->vfptr;
    v1 = (int)&v2->m_subMenus[v11];
    if ( v12 )
    {
      v13 = UIElement_ListBox::GetItem(v12, which);
      if ( v13 )
      {
        v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)268435506);
        if ( v14 )
        {
          v15 = *(_DWORD *)(v14 + 1536);
          if ( v15 )
            SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v1, v15);
        }
      }
    }
    goto LABEL_21;
  }
  if ( !LOBYTE(v17->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]) )
  {
    which = v4 - 1;
    goto LABEL_16;
  }
LABEL_3:
  v5 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
  v2->m_subMenus[v5].m_endowmentSelected = 1;
  SpellCastSubMenu::SetSelected(&v2->m_subMenus[v5], 0);
LABEL_21:
  gmSpellcastingUI::UpdateEndowmentIcon(v2, v1);
  gmSpellcastingUI::UpdateCastButtonTooltip(v2);
}

//----- (004C7740) --------------------------------------------------------  // acclient.c:249036
void __usercall gmSpellcastingUI::RecvNotice_FirstSpellTab(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  gmSpellcastingUI *v2; // esi@1
  HashSet<UIElement *>Vtbl *v3; // ecx@1
  gmSpellcastingUI *v4; // esi@2

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.vfptr;
  if ( v3 )
  {
    UIElement_Panel::OpenTab((UIElement_Panel *)v3, 0x100000A3u);
    v4 = (gmSpellcastingUI *)((char *)v2 - 1528);
    gmSpellcastingUI::UpdateEndowmentIcon(v4, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v4);
  }
}

//----- (004C7770) --------------------------------------------------------  // acclient.c:249054
void __usercall gmSpellcastingUI::RecvNotice_LastSpellTab(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  gmSpellcastingUI *v2; // esi@1
  HashSet<UIElement *>Vtbl *v3; // ecx@1
  gmSpellcastingUI *v4; // esi@2

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.vfptr;
  if ( v3 )
  {
    UIElement_Panel::OpenTab((UIElement_Panel *)v3, 0x100005C2u);
    v4 = (gmSpellcastingUI *)((char *)v2 - 1528);
    gmSpellcastingUI::UpdateEndowmentIcon(v4, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v4);
  }
}

//----- (004C77A0) --------------------------------------------------------  // acclient.c:249072
void __usercall gmSpellcastingUI::RecvNotice_FirstSpellSelection(gmSpellcastingUI *this@<ecx>, int a2@<edi>)
{
  char v2; // al@1
  gmSpellcastingUI *v3; // esi@1
  gmSpellcastingUI *v4; // ecx@1
  int v5; // ecx@2
  int v6; // eax@3
  int v7; // eax@4

  v2 = LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6]);
  v3 = (gmSpellcastingUI *)((char *)this - 1528);
  v4 = (gmSpellcastingUI *)((char *)this - 1528);
  if ( v2 )
  {
    v5 = (int)&v3->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v4)];
    *(_BYTE *)(v5 + 24) = 1;
    SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v5, 0);
    gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
    gmSpellcastingUI::UpdateCastButtonTooltip(v3);
  }
  else
  {
    v6 = gmSpellcastingUI::GetOpenSubMenuIndex(v4);
    if ( UIElement_ItemList::GetNumUIItems(v3->m_subMenus[v6].m_spellItemList) > 0 )
    {
      v7 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
      SpellCastSubMenu::SelectSpellFromIndex(&v3->m_subMenus[v7], 0);
      gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
      gmSpellcastingUI::UpdateCastButtonTooltip(v3);
    }
  }
}

//----- (004C7820) --------------------------------------------------------  // acclient.c:249106
void __thiscall gmSpellcastingUI::RecvNotice_LastSpellSelection(gmSpellcastingUI *this)
{
  int v1; // edi@1
  gmSpellcastingUI *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  int v5; // ST00_4@2
  int v6; // eax@2
  int v7; // ecx@4

  v1 = (int)this;
  v2 = (gmSpellcastingUI *)((char *)this - 1528);
  v3 = gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528));
  v4 = UIElement_ItemList::GetNumUIItems(v2->m_subMenus[v3].m_spellItemList);
  if ( v4 <= 0 )
  {
    if ( *(_BYTE *)(v1 + 36) )
    {
      v7 = (int)&v2->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v2)];
      *(_BYTE *)(v7 + 24) = 1;
      SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v7, 0);
      gmSpellcastingUI::UpdateEndowmentIcon(v2, v1);
      gmSpellcastingUI::UpdateCastButtonTooltip(v2);
    }
  }
  else
  {
    v5 = v4 - 1;
    v6 = gmSpellcastingUI::GetOpenSubMenuIndex(v2);
    SpellCastSubMenu::SelectSpellFromIndex(&v2->m_subMenus[v6], v5);
    gmSpellcastingUI::UpdateEndowmentIcon(v2, v1);
    gmSpellcastingUI::UpdateCastButtonTooltip(v2);
  }
}

//----- (004C78B0) --------------------------------------------------------  // acclient.c:249142
void __thiscall gmSpellcastingUI::RecvNotice_CastQuickslotSpell(gmSpellcastingUI *this, int i_slot)
{
  gmSpellcastingUI *v2; // esi@1
  int v3; // eax@1
  UIElement_ListBox *v4; // ecx@1
  int v5; // edi@1
  UIElement *v6; // eax@2
  int v7; // eax@3
  unsigned int v8; // eax@4

  v2 = (gmSpellcastingUI *)((char *)this - 1528);
  v3 = gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528));
  v4 = (UIElement_ListBox *)&v2->m_subMenus[v3].m_spellItemList->vfptr;
  v5 = (int)&v2->m_subMenus[v3];
  if ( v4 )
  {
    v6 = UIElement_ListBox::GetItem(v4, i_slot);
    if ( v6 )
    {
      v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 1536);
        if ( v8 )
        {
          SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v5, v8);
          gmSpellcastingUI::UpdateEndowmentIcon(v2, v5);
          gmSpellcastingUI::UpdateCastButtonTooltip(v2);
          gmSpellcastingUI::Cast(v2);
        }
      }
    }
  }
}

//----- (004C7930) --------------------------------------------------------  // acclient.c:249178
void __thiscall gmSpellcastingUI::HandleDropRelease(gmSpellcastingUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmSpellcastingUI *v3; // esi@1
  UIElement *v4; // ecx@1
  int v5; // edi@1
  int v6; // eax@3
  int v7; // eax@5
  UIElement *v8; // eax@5
  int v9; // eax@6
  UIElement *v10; // ST08_4@7
  int v11; // eax@7
  int v12; // eax@7
  signed int v13; // eax@10
  int v14; // ecx@10
  DropItemFlags dropFlags; // [sp+8h] [bp-8h]@3
  unsigned int dropItemID; // [sp+Ch] [bp-4h]@3

  v2 = i_rMsg->dwParam1;
  v3 = this;
  v4 = *(UIElement **)(v2 + 8);
  v5 = *(_DWORD *)(v2 + 16);
  if ( v4 && v5 )
  {
    UIElement_ItemList::InqDropIconInfo(v4, &dropItemID, (unsigned int *)&i_rMsg, &dropFlags);
    v6 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
    if ( UIElement::IsAncestorOfMe((UIElement *)v5, (UIElement *)&v3->m_subMenus[v6].m_spellItemList->vfptr) )
    {
      if ( i_rMsg )
      {
        v7 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
        v8 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v3->m_subMenus[v7].m_spellItemList->vfptr);
        if ( v8 )
        {
          v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435506);
          if ( v9 )
          {
            v10 = (UIElement *)v9;
            v11 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
            v12 = UIElement_ListBox::WhatNum((UIElement_ListBox *)&v3->m_subMenus[v11].m_spellItemList->vfptr, v10);
            gmSpellcastingUI::AddSpellShortcut(v3, v5, (unsigned int)i_rMsg, v12, 1);
          }
        }
      }
    }
    else if ( (UIElement *)v5 == v3->m_spellcastBackground )
    {
      gmSpellcastingUI::AddSpellShortcut(v3, v5, (unsigned int)i_rMsg, -1, 1);
    }
    else
    {
      v13 = 0;
      v14 = (int)&v3->m_subMenus[0].m_spellTabElement;
      while ( v5 != *(_DWORD *)v14 )
      {
        ++v13;
        v14 += 28;
        if ( v13 >= 8 )
          return;
      }
      if ( i_rMsg )
      {
        SpellCastSubMenu::AddFavorite(&v3->m_subMenus[v13], (unsigned int)i_rMsg, -1, 1);
        gmSpellcastingUI::UpdateEndowmentIcon(v3, v5);
        gmSpellcastingUI::UpdateCastButtonTooltip(v3);
      }
    }
  }
}

//----- (004C7A70) --------------------------------------------------------  // acclient.c:249249
void __userpurge gmSpellcastingUI::RecvNotice_AddSpellShortcut(gmSpellcastingUI *this@<ecx>, int a2@<edi>, unsigned int i_spellID)
{
  gmSpellcastingUI *v3; // esi@1
  int v4; // eax@1

  v3 = (gmSpellcastingUI *)((char *)this - 1528);
  v4 = gmSpellcastingUI::GetOpenSubMenuIndex((gmSpellcastingUI *)((char *)this - 1528));
  SpellCastSubMenu::AddFavorite(&v3->m_subMenus[v4], i_spellID, -1, 0);
  gmSpellcastingUI::UpdateEndowmentIcon(v3, a2);
  gmSpellcastingUI::UpdateCastButtonTooltip(v3);
}

//----- (004C7AB0) --------------------------------------------------------  // acclient.c:249262
int __thiscall gmSpellcastingUI::ListenToElementMessage(gmSpellcastingUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmSpellcastingUI *v3; // esi@1
  int v4; // eax@3
  int v5; // eax@4
  UIElement *v6; // eax@4
  int v7; // eax@5
  unsigned int v8; // ecx@6
  unsigned int v9; // eax@7
  unsigned int v10; // ST00_4@8
  int v11; // eax@8
  unsigned int v12; // eax@13
  int v13; // ecx@14
  unsigned int v15; // ST00_4@18
  ClientUISystem *v16; // eax@18
  int v17; // eax@25

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 == 28 )
  {
    if ( this->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(this)].m_spellItemList )
    {
      v4 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
      if ( UIElement::IsAncestorOfMe(i_rMsg->pElement, (UIElement *)&v3->m_subMenus[v4].m_spellItemList->vfptr) )
      {
        v5 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
        v6 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v3->m_subMenus[v5].m_spellItemList->vfptr);
        if ( v6 )
        {
          v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
          if ( v7 )
          {
            v8 = i_rMsg->dwParam1;
            if ( v8 == 7 )
            {
              v9 = *(_DWORD *)(v7 + 1536);
              if ( v9 )
              {
                v10 = v9;
                v11 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
                SpellCastSubMenu::SetSelected(&v3->m_subMenus[v11], v10);
                gmSpellcastingUI::UpdateEndowmentIcon(v3, (int)i_rMsg);
                gmSpellcastingUI::UpdateCastButtonTooltip(v3);
              }
            }
            else if ( v8 == 10 && *(_DWORD *)(v7 + 1536) )
            {
              gmSpellcastingUI::Cast(v3);
            }
          }
        }
      }
    }
    if ( i_rMsg->idElement == 268435633 )
    {
      v12 = i_rMsg->dwParam1;
      if ( v12 == 7 )
      {
        v13 = (int)&v3->m_subMenus[gmSpellcastingUI::GetOpenSubMenuIndex(v3)];
        *(_BYTE *)(v13 + 24) = 1;
        SpellCastSubMenu::SetSelected((SpellCastSubMenu *)v13, 0);
        gmSpellcastingUI::UpdateEndowmentIcon(v3, (int)i_rMsg);
        gmSpellcastingUI::UpdateCastButtonTooltip(v3);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
      if ( v12 != 10 )
      {
        if ( v12 == 8 && v3->m_endowmentItemID )
        {
          v15 = v3->m_endowmentItemID;
          v16 = ClientUISystem::GetUISystem();
          ClientUISystem::ExamineObject(v16, v15);
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
LABEL_21:
      gmSpellcastingUI::Cast(v3);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
  }
  else if ( v2 == 1 )
  {
    if ( i_rMsg->idElement == 268435634 )
      goto LABEL_21;
  }
  else
  {
    if ( v2 == 21 )
    {
      gmSpellcastingUI::HandleDropRelease(this, i_rMsg);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
    if ( v2 == 44 )
    {
      gmSpellcastingUI::UpdateEndowmentIcon(this, (int)i_rMsg);
      gmSpellcastingUI::UpdateCastButtonTooltip(v3);
      v17 = gmSpellcastingUI::GetOpenSubMenuIndex(v3);
      SpellCastSubMenu::UpdateShortcutOverlays(&v3->m_subMenus[v17]);
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (006F2960) --------------------------------------------------------  // acclient.c:775043
void _E91_87()
{
  outside_val_79 = 1000.0 + 1.0;
}

//----- (006F2980) --------------------------------------------------------  // acclient.c:775049
void _E93_63()
{
  block_length_79 = 24.0 * 8.0;
}

//----- (006F29A0) --------------------------------------------------------  // acclient.c:775055
void _E95_63()
{
  half_square_length_79 = 24.0 * 0.5;
}

//----- (006F29C0) --------------------------------------------------------  // acclient.c:775061
int _E97_88()
{
  return atexit(nullsub_756);
}

//----- (006F29D0) --------------------------------------------------------  // acclient.c:775067
int _E100_81()
{
  return atexit(nullsub_757);
}

//----- (006F29E0) --------------------------------------------------------  // acclient.c:775073
int _E103_73()
{
  return atexit(_E104_88);
}

//----- (006F29F0) --------------------------------------------------------  // acclient.c:775079
void _E109_35()
{
  DEFAULT_VIEW_RADIUS_48 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F2A10) --------------------------------------------------------  // acclient.c:775085
void _E111_24()
{
  MIN_QUANTUM_48 = 1.0 / 30.0;
}

//----- (006F2A30) --------------------------------------------------------  // acclient.c:775091
void _E113_12()
{
  MAX_QUANTUM_48 = 1.0 / 5.0;
}

//----- (006F2A50) --------------------------------------------------------  // acclient.c:775097
void _E115_38()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_83, PFID_A8R8G8B8);
}

//----- (006F2A60) --------------------------------------------------------  // acclient.c:775103
void _E118_43()
{
  LOWEST_DATA_RATE_85 = 1024;
}

//----- (006F2A70) --------------------------------------------------------  // acclient.c:775109
void _E120_31()
{
  HIGHEST_DATA_RATE_85 = 0x7FFF;
}

//----- (006F2A80) --------------------------------------------------------  // acclient.c:775115
int _E122_17()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_85;
  INITIAL_MAX_DATA_RATE_33 = LOWEST_DATA_RATE_85;
  return result;
}

//----- (006F2A90) --------------------------------------------------------  // acclient.c:775125
int _E124_40()
{
  return atexit(_E125_46);
}

//----- (006F2AA0) --------------------------------------------------------  // acclient.c:775131
int _E127_35()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_33, "Misc.TooltipEnable");
  return atexit(_E128_46);
}

//----- (006F2AC0) --------------------------------------------------------  // acclient.c:775138
int _E130_29()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_33, "Misc.TooltipDelay");
  return atexit(_E131_36);
}

//----- (006F2AE0) --------------------------------------------------------  // acclient.c:775145
int sub_6F2AE0()
{
  return atexit(nullsub_755);
}

//----- (00761570) --------------------------------------------------------  // acclient.c:888777
void __cdecl _E128_46()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007615A0) --------------------------------------------------------  // acclient.c:888790
void __cdecl _E131_36()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

