/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmPaperDollUI
   Object     : GAME\game_ui_misc\gmPaperDollUI.obj
   Functions  : 59
   Addresses  : 004A3550 - 00760E30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A3550) --------------------------------------------------------  // acclient.c:219648
int __thiscall InventoryPlacement::UnPack(InventoryPlacement *this, void **addr, unsigned int size)
{
  char *v3; // edx@1
  char *v4; // edx@1

  this->iid_ = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  this->loc_ = *(_DWORD *)v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  this->priority_ = *(_DWORD *)v4;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (004A3580) --------------------------------------------------------  // acclient.c:219665
bool __stdcall ItemListDragHandler::OnItemListDragOver(UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  return 0;
}

//----- (004A3590) --------------------------------------------------------  // acclient.c:219671
void __thiscall gmPaperDollUI::~gmPaperDollUI(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // esi@1
  NoticeHandler *v2; // ebp@1
  char *v3; // ebx@1
  UIElement_ItemList *v4; // ecx@1
  UIElement_ItemList *v5; // ecx@3
  UIElement_ItemList *v6; // ecx@5
  UIElement_ItemList *v7; // ecx@7
  UIElement_ItemList *v8; // ecx@9
  UIElement_ItemList *v9; // ecx@11
  UIElement_ItemList *v10; // ecx@13
  UIElement_ItemList *v11; // ecx@15
  UIElement_ItemList *v12; // ecx@17
  UIElement_ItemList *v13; // ecx@19
  UIElement_ItemList *v14; // ecx@21
  UIElement_ItemList *v15; // ecx@23
  UIElement_ItemList *v16; // ecx@25
  UIElement_ItemList *v17; // ecx@27
  UIElement_ItemList *v18; // ecx@29
  UIElement_ItemList *v19; // ecx@31
  UIElement_ItemList *v20; // ecx@33
  UIElement_ItemList *v21; // ecx@35
  UIElement_ItemList *v22; // ecx@37
  UIElement_ItemList *v23; // ecx@39
  UIElement_ItemList *v24; // ecx@41
  UIElement_ItemList *v25; // ecx@43
  UIElement_ItemList *v26; // ecx@45
  UIElement_ItemList *v27; // ecx@47
  UIElement_Viewport *v28; // eax@49
  CPhysicsObj *v29; // ecx@51
  RenderSurface *v30; // ecx@53
  GlobalEventHandler *v31; // eax@55

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmPaperDollUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmPaperDollUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmPaperDollUI::vftable;
  this->vfptr = (ItemListDragHandlerVtbl *)&gmPaperDollUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xBu);
  v4 = v1->m_neckSlot;
  if ( v4 )
    UIElement_ItemList::UnregisterItemListDragHandler(v4);
  v5 = v1->m_leftWristSlot;
  if ( v5 )
    UIElement_ItemList::UnregisterItemListDragHandler(v5);
  v6 = v1->m_leftRingSlot;
  if ( v6 )
    UIElement_ItemList::UnregisterItemListDragHandler(v6);
  v7 = v1->m_rightWristSlot;
  if ( v7 )
    UIElement_ItemList::UnregisterItemListDragHandler(v7);
  v8 = v1->m_rightRingSlot;
  if ( v8 )
    UIElement_ItemList::UnregisterItemListDragHandler(v8);
  v9 = v1->m_weaponReadySlot;
  if ( v9 )
    UIElement_ItemList::UnregisterItemListDragHandler(v9);
  v10 = v1->m_ammoReadySlot;
  if ( v10 )
    UIElement_ItemList::UnregisterItemListDragHandler(v10);
  v11 = v1->m_shieldReadySlot;
  if ( v11 )
    UIElement_ItemList::UnregisterItemListDragHandler(v11);
  v12 = v1->m_clothesPantsSlot;
  if ( v12 )
    UIElement_ItemList::UnregisterItemListDragHandler(v12);
  v13 = v1->m_clothesShirtSlot;
  if ( v13 )
    UIElement_ItemList::UnregisterItemListDragHandler(v13);
  v14 = v1->m_trinketOneSlot;
  if ( v14 )
    UIElement_ItemList::UnregisterItemListDragHandler(v14);
  v15 = v1->m_cloakSlot;
  if ( v15 )
    UIElement_ItemList::UnregisterItemListDragHandler(v15);
  v16 = v1->m_sigilOneSlot;
  if ( v16 )
    UIElement_ItemList::UnregisterItemListDragHandler(v16);
  v17 = v1->m_sigilTwoSlot;
  if ( v17 )
    UIElement_ItemList::UnregisterItemListDragHandler(v17);
  v18 = v1->m_sigilThreeSlot;
  if ( v18 )
    UIElement_ItemList::UnregisterItemListDragHandler(v18);
  v19 = v1->m_headSlot;
  if ( v19 )
    UIElement_ItemList::UnregisterItemListDragHandler(v19);
  v20 = v1->m_chestSlot;
  if ( v20 )
    UIElement_ItemList::UnregisterItemListDragHandler(v20);
  v21 = v1->m_abdomenSlot;
  if ( v21 )
    UIElement_ItemList::UnregisterItemListDragHandler(v21);
  v22 = v1->m_upperArmSlot;
  if ( v22 )
    UIElement_ItemList::UnregisterItemListDragHandler(v22);
  v23 = v1->m_lowerArmSlot;
  if ( v23 )
    UIElement_ItemList::UnregisterItemListDragHandler(v23);
  v24 = v1->m_handSlot;
  if ( v24 )
    UIElement_ItemList::UnregisterItemListDragHandler(v24);
  v25 = v1->m_upperLegSlot;
  if ( v25 )
    UIElement_ItemList::UnregisterItemListDragHandler(v25);
  v26 = v1->m_lowerLegSlot;
  if ( v26 )
    UIElement_ItemList::UnregisterItemListDragHandler(v26);
  v27 = v1->m_footSlot;
  if ( v27 )
    UIElement_ItemList::UnregisterItemListDragHandler(v27);
  v28 = v1->m_pPaperDoll;
  if ( v28 )
    CreatureMode::RemoveAllObjects((CreatureMode *)&v28->creature_mode_objects);
  v29 = v1->m_pInventoryObject;
  if ( v29 )
    ((void (__stdcall *)(_DWORD))v29->vfptr->__vecDelDtor)(1);
  v30 = v1->m_clickMap;
  v1->m_pInventoryObject = 0;
  if ( v30 )
  {
    ((void (*)(void))v30->vfptr->Release)();
    v1->m_clickMap = 0;
  }
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    322,
    v3);
  v31 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v31 )
    v31->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v31, v2);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7ABA7C: using guessed type bool (__thiscall *gmPaperDollUI::vftable)(gmPaperDollUI *this, UIElement_UIItem *_catchElement, UI_SLOT_SIDE slotSide, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7ABA80: using guessed type void (__thiscall *gmPaperDollUI::vftable[2])(gmPaperDollUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7ABA88: using guessed type bool (__thiscall *gmPaperDollUI::vftable)(DBCache *this);
// 7ABD30: using guessed type int (__thiscall *gmPaperDollUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A37C0) --------------------------------------------------------  // acclient.c:219817
gmPaperDollUI *__thiscall gmPaperDollUI::DynamicCast(gmPaperDollUI *this, unsigned int i_eType)
{
  gmPaperDollUI *result; // eax@1

  result = this;
  if ( i_eType != 268435492 )
    result = (gmPaperDollUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A37E0) --------------------------------------------------------  // acclient.c:219828
signed int gmPaperDollUI::GetUIElementType()
{
  return 268435492;
}

//----- (004A37F0) --------------------------------------------------------  // acclient.c:219834
void __stdcall gmPaperDollUI::GetLocationInfoFromElementID(unsigned int _elemID, unsigned int *_loc, UI_SLOT_SIDE *_slotSide)
{
  *_loc = 0;
  *_slotSide = 0;
  if ( _elemID > 0x1000058E )
  {
    switch ( _elemID )
    {
      case 0x100005E9u:
        *_loc = 0x8000000;
        *_slotSide = 0;
        break;
      case 0x10000595u:
        *_loc = 0x10000000;
        *_slotSide = 0;
        break;
      case 0x10000596u:
        *_loc = 0x20000000;
        *_slotSide = 0;
        break;
      case 0x10000597u:
        *_loc = 0x40000000;
        *_slotSide = 0;
        break;
      case 0x100005ABu:
        *_loc = 1;
        *_slotSide = 0;
        break;
      case 0x100005ACu:
        *_loc = 512;
        *_slotSide = 0;
        break;
      case 0x100005ADu:
        *_loc = 1024;
        *_slotSide = 0;
        break;
      case 0x100005AEu:
        *_loc = 2048;
        *_slotSide = 0;
        break;
      case 0x100005AFu:
        *_loc = 4096;
        *_slotSide = 0;
        break;
      case 0x100005B0u:
        *_loc = 32;
        *_slotSide = 0;
        break;
      case 0x100005B1u:
        *_loc = 0x2000;
        *_slotSide = 0;
        break;
      case 0x100005B2u:
        *_loc = 0x4000;
        *_slotSide = 0;
        break;
      case 0x100005B3u:
        *_loc = 256;
        *_slotSide = 0;
        break;
      default:
        return;
    }
  }
  else if ( _elemID == 268436878 )
  {
    *_loc = 0x4000000;
    *_slotSide = 0;
  }
  else
  {
    switch ( _elemID )
    {
      case 0x100001DAu:
        *_loc = 0x8000;
        *_slotSide = 0;
        break;
      case 0x100001DBu:
        *_loc = 0x10000;
        *_slotSide = 1;
        break;
      case 0x100001DCu:
        *_loc = 0x40000;
        *_slotSide = 1;
        break;
      case 0x100001DDu:
        *_loc = 0x20000;
        *_slotSide = 2;
        break;
      case 0x100001DEu:
        *_loc = 0x80000;
        *_slotSide = 2;
        break;
      case 0x100001DFu:
        *_loc = 55574528;
        *_slotSide = 0;
        break;
      case 0x100001E0u:
        *_loc = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
        *_slotSide = 0;
        break;
      case 0x100001E1u:
        *_loc = 0x200000;
        *_slotSide = 0;
        break;
      case 0x100001E3u:
        *_loc = 64;
        *_slotSide = 0;
        break;
      case 0x100001E2u:
        *_loc = 2;
        *_slotSide = 0;
        break;
      default:
        return;
    }
  }
}

//----- (004A3A70) --------------------------------------------------------  // acclient.c:219954
void __thiscall gmPaperDollUI::HandlePaperDollDragOver(gmPaperDollUI *this, UIElement *_dragElement)
{
  gmPaperDollUI *v2; // esi@1
  CPlayerSystem *v3; // eax@3
  int blockedBySelf; // [sp+4h] [bp-Ch]@4
  DropItemFlags dropFlags; // [sp+8h] [bp-8h]@1
  unsigned int dropSpellID; // [sp+Ch] [bp-4h]@1

  v2 = this;
  UIElement_ItemList::InqDropIconInfo(_dragElement, (unsigned int *)&_dragElement, &dropSpellID, &dropFlags);
  if ( _dragElement )
  {
    if ( !(dropFlags & 0xE) )
    {
      v3 = CPlayerSystem::GetPlayerSystem();
      if ( v3 )
      {
        blockedBySelf = 0;
        if ( CPlayerSystem::AutoWearIsLegal(v3, (unsigned int)_dragElement, &blockedBySelf, 1) )
        {
          ((void (__stdcall *)(signed int))v2->m_paperDollDragOverlay->vfptr[13].__vecDelDtor)(268435520);
        }
        else if ( !blockedBySelf )
        {
          ((void (__stdcall *)(signed int))v2->m_paperDollDragOverlay->vfptr[13].__vecDelDtor)(268435521);
        }
      }
    }
  }
}

//----- (004A3B10) --------------------------------------------------------  // acclient.c:219986
char __stdcall gmPaperDollUI::AcceptDragObject(unsigned int _itemID, unsigned int *_loc, UI_SLOT_SIDE *_slotSide)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  HashBaseData<unsigned long>Vtbl *v7; // eax@3
  unsigned int *v8; // ebx@3
  UI_SLOT_SIDE *v9; // edi@3
  CPlayerSystem *v10; // ecx@7
  unsigned int v11; // esi@8

  v4 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v5 = v4;
  if ( !v4 )
    return 0;
  v7 = v4[16].vfptr;
  v8 = _loc;
  v9 = _slotSide;
  if ( *_loc == 0x200000 && (unsigned int)v7 & 0x100000 )
  {
    v7 = (HashBaseData<unsigned long>Vtbl *)((unsigned int)v7 | 0x200000);
    *_slotSide = 1;
  }
  if ( (unsigned int)v7 & *v8 )
  {
    v10 = CPlayerSystem::GetPlayerSystem();
    if ( v10 )
    {
      v11 = v5->id;
      if ( *v8 & 0x80001FF )
      {
        _itemID = 0;
        if ( CPlayerSystem::AutoWear(v10, v11, (int *)&_itemID, 0) )
          return 1;
      }
      else if ( CPlayerSystem::AutoWield(v10, v11, *v9, 0, 1, 0, 0) )
      {
        return 1;
      }
    }
  }
  return 0;
}

//----- (004A3BC0) --------------------------------------------------------  // acclient.c:220030
void __thiscall gmPaperDollUI::RedressCreature(gmPaperDollUI *this)
{
  SmartBox *v1; // edi@1
  gmPaperDollUI *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@4
  CPhysicsObj *v4; // eax@4
  UIElement_Viewport *v5; // eax@4
  int v6; // eax@7

  v1 = SmartBox::smartbox;
  v2 = this;
  if ( SmartBox::smartbox )
  {
    if ( this->m_pInventoryObject )
      goto LABEL_10;
    if ( SmartBox::smartbox->player )
    {
      v3 = ClientObjMaintSystem::GetPhysicsObject(SmartBox::smartbox->player_id);
      v4 = CPhysicsObj::makeObject((CPhysicsObj *)v3);
      v2->m_pInventoryObject = v4;
      CPhysicsObj::set_heading(v4, 191.3679, 1);
      CPhysicsObj::set_sequence_animation(v2->m_pInventoryObject, v2->m_didAnimation, 1, 1u, 0.0);
      v5 = v2->m_pPaperDoll;
      if ( v5 )
        CreatureMode::AddObject((CreatureMode *)&v5->creature_mode_objects, v2->m_pInventoryObject);
    }
    if ( v2->m_pInventoryObject )
    {
LABEL_10:
      v6 = SmartBox::get_player_visualdesc(v1);
      CPhysicsObj::DoObjDescChangesFromDefault(v2->m_pInventoryObject, (ObjDesc *)v6);
    }
  }
}

//----- (004A3C70) --------------------------------------------------------  // acclient.c:220066
void __thiscall gmPaperDollUI::EndPartSelectionLighting(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // esi@1
  CPhysicsObj *v2; // ecx@1

  v1 = this;
  v2 = this->m_pInventoryObject;
  v1->m_cFlipCount = 0;
  v1->m_selectionMask = 0;
  if ( v2 )
    CPhysicsObj::RestoreLighting(v2);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
}

//----- (004A3CA0) --------------------------------------------------------  // acclient.c:220081
void __thiscall gmPaperDollUI::ApplyPartSelectionLighting(gmPaperDollUI *this, unsigned int _locations, float _luminosity, float _diffuse)
{
  gmPaperDollUI *v4; // esi@1
  CPhysicsObj *v5; // ecx@1
  unsigned int v6; // eax@6
  unsigned int v7; // eax@9
  unsigned int v8; // eax@12
  unsigned int v9; // eax@15
  unsigned int v10; // eax@18
  unsigned int v11; // eax@21
  unsigned int v12; // eax@26

  v4 = this;
  v5 = this->m_pInventoryObject;
  if ( v5 )
  {
    if ( _locations == 0x7FFFFFFF )
    {
      CPhysicsObj::SetLighting(v5, _luminosity, _diffuse);
    }
    else
    {
      if ( v4->m_selectionMask & 1 )
        CPhysicsObj::SetPartLighting(v5, 0x10u, _luminosity, _diffuse);
      v6 = v4->m_selectionMask;
      if ( v6 & 2 || BYTE1(v6) & 2 )
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 9u, _luminosity, _diffuse);
      v7 = v4->m_selectionMask;
      if ( v7 & 4 || BYTE1(v7) & 4 )
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0, _luminosity, _diffuse);
      v8 = v4->m_selectionMask;
      if ( v8 & 8 || BYTE1(v8) & 8 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xAu, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xDu, _luminosity, _diffuse);
      }
      v9 = v4->m_selectionMask;
      if ( v9 & 0x10 || BYTE1(v9) & 0x10 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xBu, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xEu, _luminosity, _diffuse);
      }
      v10 = v4->m_selectionMask;
      if ( v10 & 0x40 || BYTE1(v10) & 0x20 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 1u, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 5u, _luminosity, _diffuse);
      }
      v11 = v4->m_selectionMask;
      if ( (v11 & 0x80u) != 0 || BYTE1(v11) & 0x40 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 2u, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 6u, _luminosity, _diffuse);
      }
      if ( v4->m_selectionMask & 0x20 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xCu, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 0xFu, _luminosity, _diffuse);
      }
      v12 = v4->m_selectionMask;
      if ( BYTE1(v12) & 1 )
      {
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 3u, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 7u, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 4u, _luminosity, _diffuse);
        CPhysicsObj::SetPartLighting(v4->m_pInventoryObject, 8u, _luminosity, _diffuse);
      }
    }
  }
}

//----- (004A3E50) --------------------------------------------------------  // acclient.c:220153
void __thiscall gmPaperDollUI::UpdateAetheria(gmPaperDollUI *this, CWeenieObject *cwobj)
{
  gmPaperDollUI *v2; // esi@1
  CBaseQualities *v3; // ecx@1
  int v4; // edi@1
  int v5; // ebx@1
  int v6; // edx@1
  int v7; // edx@1
  int aetheria_bits; // [sp+0h] [bp-4h]@1

  aetheria_bits = (int)this;
  v2 = this;
  v3 = (CBaseQualities *)&cwobj[4].vfptr[2].GetNoticeHandlers;
  aetheria_bits = 0;
  CBaseQualities::InqInt(v3, 0x142u, &aetheria_bits, 0, 0);
  v4 = aetheria_bits & 2;
  v5 = aetheria_bits & 4;
  ((void (__stdcall *)(unsigned int))v2->m_sigilOneItem->vfptr[2].__vecDelDtor)(aetheria_bits & 0xFFFFFF01);
  LOBYTE(v6) = v4 != 0;
  ((void (__stdcall *)(int))v2->m_sigilTwoItem->vfptr[2].__vecDelDtor)(v6);
  LOBYTE(v7) = v5 != 0;
  ((void (__stdcall *)(int))v2->m_sigilThreeItem->vfptr[2].__vecDelDtor)(v7);
}

//----- (004A3ED0) --------------------------------------------------------  // acclient.c:220178
void __thiscall gmPaperDollUI::UpdateForRace(gmPaperDollUI *this, unsigned int heritage)
{
  gmPaperDollUI *v2; // esi@1
  int *v3; // ecx@4
  int *v4; // edx@4
  IDClass<_tagDataID,32,0> *v5; // eax@5
  CPhysicsObj *v6; // ecx@5
  IDClass<_tagDataID,32,0> v7; // ST00_4@5
  IDClass<_tagDataID,32,0> *v8; // eax@6
  CPhysicsObj *v9; // ecx@6
  IDClass<_tagDataID,32,0> v10; // ST00_4@6
  IDClass<_tagDataID,32,0> result; // [sp+4h] [bp-80h]@5
  IDClass<_tagDataID,32,0> v12; // [sp+8h] [bp-7Ch]@6
  int v13; // [sp+Ch] [bp-78h]@2
  int v14; // [sp+10h] [bp-74h]@2
  int v15; // [sp+14h] [bp-70h]@2
  int v16; // [sp+18h] [bp-6Ch]@2
  int v17; // [sp+1Ch] [bp-68h]@2
  int v18; // [sp+20h] [bp-64h]@2
  int v19; // [sp+24h] [bp-60h]@3
  int v20; // [sp+28h] [bp-5Ch]@3
  int v21; // [sp+2Ch] [bp-58h]@3
  int v22; // [sp+30h] [bp-54h]@3
  int v23; // [sp+34h] [bp-50h]@3
  int v24; // [sp+38h] [bp-4Ch]@3
  Vector3 direction; // [sp+3Ch] [bp-48h]@4
  Vector3 position; // [sp+48h] [bp-3Ch]@4
  int v27; // [sp+54h] [bp-30h]@5
  int v28; // [sp+58h] [bp-2Ch]@5
  int v29; // [sp+5Ch] [bp-28h]@5
  int v30; // [sp+60h] [bp-24h]@5
  int v31; // [sp+64h] [bp-20h]@5
  int v32; // [sp+68h] [bp-1Ch]@5
  int v33; // [sp+6Ch] [bp-18h]@6
  int v34; // [sp+70h] [bp-14h]@6
  int v35; // [sp+74h] [bp-10h]@6
  int v36; // [sp+78h] [bp-Ch]@6
  int v37; // [sp+7Ch] [bp-8h]@6
  int v38; // [sp+80h] [bp-4h]@6

  v2 = this;
  switch ( heritage )
  {
    case 6u:
    case 7u:
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v16 = 1039516303;
      v17 = -1069547520;
      v18 = 1063339950;
      UIElement_Viewport::SetCamera(this->m_pPaperDoll, (Vector3 *)&v16, (Vector3 *)&v13);
      return;
    case 9u:
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v22 = 1039516303;
      v23 = -1067869798;
      v24 = 1063339950;
      UIElement_Viewport::SetCamera(this->m_pPaperDoll, (Vector3 *)&v22, (Vector3 *)&v19);
      return;
    case 8u:
      LODWORD(direction.x) = 0;
      LODWORD(direction.y) = 0;
      LODWORD(direction.z) = 0;
      LODWORD(position.x) = 1039516303;
      LODWORD(position.y) = -1067869798;
      LODWORD(position.z) = 1065353216;
      v3 = (int *)&direction;
      v4 = (int *)&position;
      goto LABEL_7;
    case 0xCu:
      v5 = DBObj::GetDIDByEnum(&result, 268435473, 7);
      v6 = v2->m_pInventoryObject;
      v7.id = v5->id;
      v2->m_didAnimation.id = v5->id;
      CPhysicsObj::set_sequence_animation(v6, v7, 1, 1u, 0.0);
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v30 = 1039516303;
      v31 = -1067869798;
      v32 = 1063339950;
      v3 = &v27;
      v4 = &v30;
      goto LABEL_7;
    case 0xDu:
      v8 = DBObj::GetDIDByEnum(&v12, 268435475, 7);
      v9 = v2->m_pInventoryObject;
      v10.id = v8->id;
      v2->m_didAnimation.id = v8->id;
      CPhysicsObj::set_sequence_animation(v9, v10, 1, 1u, 0.0);
      v33 = 0;
      v34 = 0;
      v35 = 0;
      v36 = 1039516303;
      v37 = -1067869798;
      v38 = 1063339950;
      v3 = &v33;
      v4 = &v36;
LABEL_7:
      UIElement_Viewport::SetCamera(v2->m_pPaperDoll, (Vector3 *)v4, (Vector3 *)v3);
      break;
    default:
      return;
  }
}

//----- (004A40C0) --------------------------------------------------------  // acclient.c:220288
void __userpurge gmPaperDollUI::gmPaperDollUI(gmPaperDollUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPaperDollUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&ItemListDragHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmPaperDollUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmPaperDollUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmPaperDollUI::vftable;
  v4->vfptr = (ItemListDragHandlerVtbl *)&gmPaperDollUI::vftable;
  v4->m_neckSlot = 0;
  v4->m_leftWristSlot = 0;
  v4->m_leftRingSlot = 0;
  v4->m_rightWristSlot = 0;
  v4->m_rightRingSlot = 0;
  v4->m_weaponReadySlot = 0;
  v4->m_ammoReadySlot = 0;
  v4->m_shieldReadySlot = 0;
  v4->m_clothesPantsSlot = 0;
  v4->m_clothesShirtSlot = 0;
  v4->m_trinketOneSlot = 0;
  v4->m_cloakSlot = 0;
  v4->m_sigilOneSlot = 0;
  v4->m_sigilTwoSlot = 0;
  v4->m_sigilThreeSlot = 0;
  v4->m_headSlot = 0;
  v4->m_chestSlot = 0;
  v4->m_abdomenSlot = 0;
  v4->m_upperArmSlot = 0;
  v4->m_lowerArmSlot = 0;
  v4->m_handSlot = 0;
  v4->m_upperLegSlot = 0;
  v4->m_lowerLegSlot = 0;
  v4->m_footSlot = 0;
  v4->m_pInventoryObject = 0;
  v4->m_pPaperDoll = 0;
  v4->m_dragIcon = 0;
  v4->m_paperDollDragMask = 0;
  v4->m_paperDollDragOverlay = 0;
  v4->m_sigilOneItem = 0;
  v4->m_sigilTwoItem = 0;
  v4->m_sigilThreeItem = 0;
  v4->m_clickMap = 0;
  v4->m_cFlipCount = 0;
  LODWORD(v4->m_timeNextFlip) = 0;
  HIDWORD(v4->m_timeNextFlip) = 0;
  v4->m_selectionMask = 0;
  v4->m_didAnimation.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&_full_desc, 268435461, 7)->id;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7ABA78: using guessed type bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7ABA7C: using guessed type bool (__thiscall *gmPaperDollUI::vftable)(gmPaperDollUI *this, UIElement_UIItem *_catchElement, UI_SLOT_SIDE slotSide, unsigned __int32 _dropSpellID, enum DropItemFlags);
// 7ABA80: using guessed type void (__thiscall *gmPaperDollUI::vftable[2])(gmPaperDollUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7ABA88: using guessed type bool (__thiscall *gmPaperDollUI::vftable)(DBCache *this);
// 7ABD30: using guessed type int (__thiscall *gmPaperDollUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A4220) --------------------------------------------------------  // acclient.c:220349
gmPaperDollUI *__thiscall gmPaperDollUI::scalar_deleting_destructor(gmPaperDollUI *this, unsigned int a2)
{
  gmPaperDollUI *v2; // esi@1

  v2 = this;
  gmPaperDollUI::~gmPaperDollUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A4240) --------------------------------------------------------  // acclient.c:220361
void __usercall gmPaperDollUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPaperDollUI *v3; // eax@1

  v3 = (gmPaperDollUI *)operator new(0x6A8u);
  if ( v3 )
    gmPaperDollUI::gmPaperDollUI(v3, a1, _layout, _full_desc);
}

//----- (004A4270) --------------------------------------------------------  // acclient.c:220371
char __stdcall gmPaperDollUI::OnItemListDragOver(UIElement_UIItem *_catchElement, unsigned int _dropItemID, unsigned int _dropSpellID, DropItemFlags _dropFlags)
{
  unsigned int v5; // esi@1
  HashBaseData<unsigned long> *v6; // edi@3
  UIElement_UIItem *v7; // ebx@5
  IInputActionCallbackVtbl *v8; // eax@5
  HashBaseData<unsigned long>Vtbl *v9; // eax@7
  CPlayerSystem *pPlayerSystem; // [sp+Ch] [bp-4h]@4

  v5 = 0;
  if ( _dropItemID )
  {
    if ( !(_dropFlags & 0xE) )
    {
      v6 = ClientObjMaintSystem::GetWeenieObject(_dropItemID);
      if ( v6 )
      {
        pPlayerSystem = CPlayerSystem::GetPlayerSystem();
        if ( pPlayerSystem )
        {
          v7 = _catchElement;
          v8 = _catchElement->vfptr;
          _dropFlags = 0;
          if ( ((int (__thiscall *)(UIElement_UIItem *))v8[13].OnAction)(_catchElement) )
            v5 = *(_DWORD *)(((int (__thiscall *)(UIElement_UIItem *))v7->vfptr[13].OnAction)(v7) + 740);
          gmPaperDollUI::GetLocationInfoFromElementID(v5, (unsigned int *)&_dropFlags, (UI_SLOT_SIDE *)&_catchElement);
          v9 = v6[16].vfptr;
          if ( _dropFlags == 0x200000 && (unsigned int)v9 & 0x100000 )
            v9 = (HashBaseData<unsigned long>Vtbl *)(_dropFlags | (unsigned int)v9);
          if ( (unsigned int)v9 & _dropFlags && CPlayerSystem::AutoWieldIsLegal(pPlayerSystem, _dropItemID, 1) )
          {
            UIElement_UIItem::SetDragAcceptState(v7, 0x10000040u);
            return 1;
          }
          UIElement_UIItem::SetDragAcceptState(v7, 0x10000041u);
        }
      }
    }
  }
  return 1;
}

//----- (004A4350) --------------------------------------------------------  // acclient.c:220414
void __thiscall gmPaperDollUI::RecvNotice_PlayerObjDescChanged(gmPaperDollUI *this)
{
  gmPaperDollUI::RedressCreature((gmPaperDollUI *)((char *)this - 1528));
}

//----- (004A4360) --------------------------------------------------------  // acclient.c:220420
void __thiscall gmPaperDollUI::UpdatePartSelectionLighting(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // esi@1
  unsigned int v2; // ecx@1
  float v3; // eax@6
  float v4; // ecx@6

  v1 = this;
  v2 = this->m_cFlipCount;
  if ( v2 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= v1->m_timeNextFlip )
  {
    if ( v2 == 1 )
    {
      v3 = LIGHT_HIGH_MAX;
      v4 = LIGHT_HIGH_MIN;
    }
    else
    {
      if ( v2 != 2 )
      {
        gmPaperDollUI::EndPartSelectionLighting(v1);
        return;
      }
      v3 = LIGHT_LOW_MAX;
      v4 = LIGHT_LOW_MIN;
    }
    gmPaperDollUI::ApplyPartSelectionLighting(v1, v1->m_selectionMask, v4, v3);
    ++v1->m_cFlipCount;
    v1->m_timeNextFlip = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.2;
  }
}

//----- (004A43E0) --------------------------------------------------------  // acclient.c:220453
void __thiscall gmPaperDollUI::RecvNotice_PlayerDescReceived(gmPaperDollUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmPaperDollUI *v3; // esi@1
  CBaseQualities *v4; // ebp@1
  int v5; // edi@1
  int v6; // ebx@1
  int v7; // edx@1
  int v8; // edx@1
  int aetheria_bits; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = (CBaseQualities *)&i_playerDesc->vfptr;
  aetheria_bits = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x142u, &aetheria_bits, 0, 0);
  v5 = aetheria_bits & 2;
  v6 = aetheria_bits & 4;
  (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v3->m_box.m_x1 + 24))(aetheria_bits & 0xFFFFFF01);
  LOBYTE(v7) = v5 != 0;
  (*(void (__stdcall **)(int))(*(_DWORD *)v3->m_box.m_y1 + 24))(v7);
  LOBYTE(v8) = v6 != 0;
  (*(void (__stdcall **)(int))(*(_DWORD *)v3->m_ptTilingOffset.x + 24))(v8);
  i_playerDesc = 0;
  CBaseQualities::InqInt(v4, 0xBCu, (int *)&i_playerDesc, 0, 0);
  gmPaperDollUI::UpdateForRace((gmPaperDollUI *)((char *)v3 - 1528), (unsigned int)i_playerDesc);
}

//----- (004A4490) --------------------------------------------------------  // acclient.c:220480
void __thiscall gmPaperDollUI::OnQualityChanged(gmPaperDollUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmPaperDollUI::UpdateAetheria((gmPaperDollUI *)((char *)this - 1532), cwobj);
}

//----- (004A44B0) --------------------------------------------------------  // acclient.c:220486
InventoryPlacement *__cdecl InventoryPlacement::DetermineHigherPriority(InventoryPlacement *_ip1, InventoryPlacement *_ip2, unsigned int _releventLocations)
{
  InventoryPlacement *result; // eax@1
  unsigned int v4; // ebp@1
  unsigned int v5; // ecx@1
  unsigned int v6; // esi@1
  unsigned int v7; // edi@1

  result = _ip1;
  v4 = _ip2->priority_;
  v5 = _releventLocations & _ip1->loc_;
  v6 = _releventLocations & _ip2->loc_;
  v7 = _ip1->priority_;
  if ( v5 && !v7 && v5 >= 0x200 && v5 <= 0x4000 )
    v7 = 127;
  if ( !v6 || v4 )
    goto LABEL_11;
  if ( v6 >= 0x200 && v6 <= 0x4000 )
  {
    v4 = 127;
LABEL_11:
    if ( v4 > v7 )
      result = _ip2;
  }
  return result;
}

//----- (004A4530) --------------------------------------------------------  // acclient.c:220514
BOOL __thiscall ACCWeenieObject::IsContainer(ACCWeenieObject *this)
{
  return (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & this->pwd._bitfield
      || this->pwd._itemsCapacity
      || this->pwd._containersCapacity;
}

//----- (004A4560) --------------------------------------------------------  // acclient.c:220522
void __cdecl gmPaperDollUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000024u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmPaperDollUI::Create);
}

//----- (004A4580) --------------------------------------------------------  // acclient.c:220530
char __userpurge gmPaperDollUI::PrepareDragIcon@<al>(gmPaperDollUI *this@<ecx>, int a2@<esi>, unsigned int _itemID)
{
  unsigned int v3; // ebp@1
  gmPaperDollUI *v4; // edi@1
  HashBaseData<unsigned long> *v5; // esi@2
  Graphic *v6; // ebp@3
  Graphic *v7; // eax@4
  Graphic *v8; // eax@4
  unsigned int v9; // edx@15
  BasePropertyValue *v10; // ecx@18
  unsigned int v11; // edx@18
  BasePropertyDesc *v12; // ecx@22
  unsigned int v13; // edx@22
  BasePropertyValue *v14; // ecx@26
  unsigned int v15; // edx@26
  char result; // al@28
  int v17; // [sp+0h] [bp-24h]@2
  BaseProperty containerProp; // [sp+14h] [bp-10h]@12
  BaseProperty itemIDProp; // [sp+1Ch] [bp-8h]@10

  v3 = _itemID;
  v4 = this;
  if ( _itemID )
  {
    v17 = a2;
    UIRegion::ClearImage((UIRegion *)&this->m_dragIcon->vfptr);
    v5 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v5 )
    {
      UIRegion::SetBlitMode((UIRegion *)&v4->m_dragIcon->vfptr, Blit_3Alpha);
      v6 = (Graphic *)operator new(0xCu);
      if ( v6 )
      {
        v7 = ACCWeenieObject::GetDragIcon((ACCWeenieObject *)v5);
        Graphic::Graphic(v6, v7);
      }
      else
      {
        v8 = 0;
      }
      UIRegion::SetImage((UIRegion *)&v4->m_dragIcon->vfptr, v8);
      if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v5[21].hash_next)
        && !v5[16].id )
        v5[17].vfptr;
      v3 = _itemID;
    }
    itemIDProp.m_pcPropertyDesc = 0;
    itemIDProp.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&itemIDProp, 0x1000000Fu);
    if ( itemIDProp.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&itemIDProp);
      ((void (__stdcall *)(unsigned int))itemIDProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v3);
    }
    ((void (__stdcall *)(BaseProperty *, int))v4->m_dragIcon->vfptr[17].OnLoseFocus)(&itemIDProp, v17);
    containerProp.m_pcPropertyValue = 0;
    itemIDProp.m_pcPropertyDesc = 0;
    BaseProperty::SetPropertyName((BaseProperty *)((char *)&containerProp + 4), 0x10000011u);
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      BaseProperty::CheckCopyOnWrite((BaseProperty *)((char *)&containerProp + 4));
      ((void (__stdcall *)(BasePropertyDesc *))itemIDProp.m_pcPropertyDesc->vfptr[29].__vecDelDtor)(containerProp.m_pcPropertyDesc);
    }
    ((void (__cdecl *)(BasePropertyValue **))v4->m_dragIcon->vfptr[17].OnLoseFocus)(&containerProp.m_pcPropertyValue);
    if ( (_DWORD)containerProp.m_pcPropertyDesc )
    {
      v9 = containerProp.m_pcPropertyDesc->m_cRef - 1;
      containerProp.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(signed int))containerProp.m_pcPropertyDesc->vfptr->__vecDelDtor)(1);
    }
    if ( containerProp.m_pcPropertyValue )
    {
      v10 = containerProp.m_pcPropertyValue;
      v11 = containerProp.m_pcPropertyValue->m_cRef - 1;
      containerProp.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      containerProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)itemIDProp.m_pcPropertyDesc )
    {
      v12 = itemIDProp.m_pcPropertyDesc;
      v13 = itemIDProp.m_pcPropertyDesc->m_cRef - 1;
      itemIDProp.m_pcPropertyDesc->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      itemIDProp.m_pcPropertyDesc = 0;
    }
    if ( itemIDProp.m_pcPropertyValue )
    {
      v14 = itemIDProp.m_pcPropertyValue;
      v15 = itemIDProp.m_pcPropertyValue->m_cRef - 1;
      itemIDProp.m_pcPropertyValue->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 4A4580: could not find valid save-restore pair for esi

//----- (004A4750) --------------------------------------------------------  // acclient.c:220638
unsigned int __stdcall gmPaperDollUI::GetUpperInvObj(unsigned int _locations)
{
  unsigned int v2; // eax@2
  HashBaseData<unsigned long> *v3; // eax@4
  PackableList<InventoryPlacement> *v5; // eax@8
  unsigned int v6; // ecx@9
  PackableLLNode<InventoryPlacement> *v7; // esi@9
  InventoryPlacement *v8; // eax@11
  InventoryPlacement curIP; // [sp+4h] [bp-20h]@9
  InventoryPlacement upperObj; // [sp+14h] [bp-10h]@9

  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  v3 = ClientObjMaintSystem::GetWeenieObject(v2);
  if ( !v3 )
    return 0;
  if ( !_locations )
    return 0;
  v5 = ACCWeenieObject::GetInvPlacementList((ACCWeenieObject *)v3);
  if ( !v5 )
    return 0;
  v6 = 0;
  upperObj.vfptr = (PackObjVtbl *)&InventoryPlacement::vftable;
  upperObj.iid_ = 0;
  upperObj.loc_ = 0;
  upperObj.priority_ = 0;
  curIP.vfptr = (PackObjVtbl *)&InventoryPlacement::vftable;
  curIP.iid_ = 0;
  curIP.loc_ = 0;
  curIP.priority_ = 0;
  v7 = v5->head;
  if ( !v7 )
    goto LABEL_19;
  do
  {
    curIP.iid_ = v7->data.iid_;
    curIP.loc_ = v7->data.loc_;
    curIP.priority_ = v7->data.priority_;
    if ( curIP.loc_ & _locations )
    {
      v8 = InventoryPlacement::DetermineHigherPriority(&curIP, &upperObj, _locations);
      v6 = v8->iid_;
      upperObj.iid_ = v8->iid_;
      upperObj.loc_ = v8->loc_;
      upperObj.priority_ = v8->priority_;
    }
    v7 = v7->next;
  }
  while ( v7 );
  if ( !v6 )
  {
LABEL_19:
    if ( SmartBox::smartbox )
      return SmartBox::smartbox->player_id;
    return 0;
  }
  return v6;
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (004A4850) --------------------------------------------------------  // acclient.c:220701
void __thiscall gmPaperDollUI::CreateClickMap(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // edi@1
  RenderSurface *v2; // ecx@1
  QualifiedDataID *v3; // eax@3
  int v4; // esi@3
  int v5; // eax@4
  char v6; // al@6
  int v7; // ecx@6
  IDClass<_tagDataID,32,0> clickMapID; // [sp+8h] [bp-Ch]@3
  QualifiedDataID v9; // [sp+Ch] [bp-8h]@3

  v1 = this;
  v2 = this->m_clickMap;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_clickMap = 0;
  }
  DBObj::GetDIDByEnum(&clickMapID, 268435468, 7);
  QualifiedDataID::QualifiedDataID(&v9, clickMapID, 0xCu);
  v4 = DBObj::Get(v3);
  if ( v4 )
  {
    v5 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
    v1->m_clickMap = (RenderSurface *)v5;
    if ( v5
      && (unsigned __int8)(*(int (__thiscall **)(int, _DWORD, _DWORD, _DWORD, signed int))(*(_DWORD *)v5 + 88))(
                            v5,
                            *(_DWORD *)(v4 + 160),
                            *(_DWORD *)(v4 + 164),
                            *(_DWORD *)(v4 + 220),
                            1) )
    {
      v6 = SurfaceWindow::Blit(&v1->m_clickMap->window, (SurfaceWindow *)(v4 + 172), 0, 1.0);
      v7 = v4;
      if ( v6 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
        return;
      }
    }
    else
    {
      v7 = v4;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v7);
  }
}

//----- (004A4920) --------------------------------------------------------  // acclient.c:220752
unsigned int __thiscall gmPaperDollUI::GetPaperDollItemUnderMouse(gmPaperDollUI *this, int window_mousex, int window_mousey)
{
  gmPaperDollUI *v3; // edi@1
  UIRegion *v4; // ecx@1
  unsigned int result; // eax@3
  const int v6; // esi@4
  unsigned int v7; // eax@4
  unsigned int v8; // esi@6
  RGBAColor rgbaVal; // [sp+4h] [bp-10h]@4

  v3 = this;
  v4 = (UIRegion *)&this->m_paperDollDragMask->vfptr;
  if ( v4 && v3->m_clickMap )
  {
    v6 = window_mousex - UIRegion::GetScreenX0(v4);
    v7 = UIRegion::GetScreenY0((UIRegion *)&v3->m_paperDollDragMask->vfptr);
    if ( SurfaceWindow::GetColorFromPoint(&v3->m_clickMap->window, &rgbaVal, v6, window_mousey - v7) )
    {
      v8 = 0;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Head) )
        v8 = 1;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Chest) )
        v8 = 514;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Abdomen) )
        v8 = 1028;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Upper_Arm) )
        v8 = 2056;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Lower_Arm) )
        v8 = 4112;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Upper_Leg) )
        v8 = 8256;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Lower_Leg) )
        v8 = 16512;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Hand) )
        v8 = 32;
      if ( (unsigned __int8)RGBAColor::operator==(&rgbaVal, &RGBAColor_HitTest_Foot) )
        v8 = 256;
      result = gmPaperDollUI::GetUpperInvObj(v8);
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

//----- (004A4A70) --------------------------------------------------------  // acclient.c:220804
bool __stdcall gmPaperDollUI::AcceptPaperDollDragObject(unsigned int _itemID)
{
  HashBaseData<unsigned long> *v2; // eax@1
  HashBaseData<unsigned long> *v3; // esi@1
  char *v4; // esi@3
  CPlayerSystem *v6; // eax@9
  PStringBase<unsigned short> _value; // [sp+4h] [bp-98h]@3
  int blockedBySelf; // [sp+8h] [bp-94h]@10
  StringInfo siError; // [sp+Ch] [bp-90h]@3

  v2 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v3 = v2;
  if ( !v2 )
    return 0;
  if ( !((unsigned int)v2[16].vfptr & 0x8007FFF) )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can't put that item there");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v4 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  if ( !ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
    return 0;
  v6 = CPlayerSystem::GetPlayerSystem();
  if ( !v6 )
    return 0;
  blockedBySelf = 0;
  return CPlayerSystem::AutoWear(v6, v3->id, &blockedBySelf, 0) != 0;
}

//----- (004A4B50) --------------------------------------------------------  // acclient.c:220843
signed int __stdcall gmPaperDollUI::GetSelectionMaskFromObject(unsigned int _objID)
{
  signed int v2; // ebx@1
  unsigned int v3; // eax@2
  signed int result; // eax@5

  v2 = 0;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( _objID == v3 )
  {
    result = 0x7FFFFFFF;
  }
  else
  {
    if ( gmPaperDollUI::GetUpperInvObj(0x404u) == _objID )
      v2 = 4;
    if ( gmPaperDollUI::GetUpperInvObj(0x2040u) == _objID )
      v2 |= 0x40u;
    if ( gmPaperDollUI::GetUpperInvObj(0x4080u) == _objID )
      v2 |= 0x80u;
    if ( gmPaperDollUI::GetUpperInvObj(0x100u) == _objID )
      v2 |= 0x100u;
    if ( gmPaperDollUI::GetUpperInvObj(0x202u) == _objID )
      v2 |= 2u;
    if ( gmPaperDollUI::GetUpperInvObj(0x808u) == _objID )
      v2 |= 8u;
    if ( gmPaperDollUI::GetUpperInvObj(0x1010u) == _objID )
      v2 |= 0x10u;
    if ( gmPaperDollUI::GetUpperInvObj(0x20u) == _objID )
      v2 |= 0x20u;
    if ( gmPaperDollUI::GetUpperInvObj(0x404u) == _objID )
      v2 |= 4u;
    if ( gmPaperDollUI::GetUpperInvObj(1u) == _objID )
      v2 |= 1u;
    result = v2;
  }
  return result;
}

//----- (004A4C50) --------------------------------------------------------  // acclient.c:220886
void __thiscall gmPaperDollUI::BeginPartSelectionLighting(gmPaperDollUI *this, unsigned int _objID)
{
  gmPaperDollUI *v2; // esi@1
  signed int v3; // eax@1
  unsigned int v4; // edx@2
  CPhysicsObj *v5; // ecx@2

  v2 = this;
  v3 = gmPaperDollUI::GetSelectionMaskFromObject(_objID);
  if ( v3 )
  {
    v2->m_cFlipCount = 1;
    v4 = Timer::cur_time.Param;
    LODWORD(v2->m_timeNextFlip) = Timer::cur_time.Cmd;
    v5 = v2->m_pInventoryObject;
    HIDWORD(v2->m_timeNextFlip) = v4;
    v2->m_selectionMask = v3;
    if ( v5 )
    {
      CPhysicsObj::RestoreLighting(v5);
      UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
    }
  }
}

//----- (004A4CB0) --------------------------------------------------------  // acclient.c:220912
void __thiscall gmPaperDollUI::ListenToGlobalMessage(gmPaperDollUI *this, unsigned int i_messageID, int i_data_int)
{
  gmPaperDollUI *v3; // ebp@1
  InterfaceSystem *v4; // eax@3
  unsigned int v5; // edi@3
  int v6; // ebx@5
  PlayerDesc *v7; // edi@7
  int v8; // [sp-8h] [bp-2Ch]@3
  unsigned int heritage; // [sp+10h] [bp-14h]@3
  TResult result; // [sp+14h] [bp-10h]@3
  char v11; // [sp+18h] [bp-Ch]@5
  InterfacePtr<PlayerDesc> spPD; // [sp+1Ch] [bp-8h]@3

  v3 = this;
  if ( i_messageID == 3 )
  {
    gmPaperDollUI::UpdatePartSelectionLighting(this);
  }
  else if ( i_messageID == 11 )
  {
    heritage = 0;
    i_messageID = 0;
    v4 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_5, (Interface **)&i_messageID);
    v5 = i_messageID;
    v8 = i_messageID;
    spPD.m_pInterface = 0;
    spPD.m_trStatus.m_val = 0;
    if ( i_messageID )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)i_messageID + 16))(i_messageID);
    v6 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v11, v8, 0);
    if ( v5 )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 20))(v5);
    v7 = spPD.m_pInterface;
    if ( (_DWORD)spPD.m_pInterface )
    {
      if ( v6 >= 0 )
      {
        CBaseQualities::InqInt((CBaseQualities *)&spPD.m_pInterface->vfptr, 0xBCu, (int *)&heritage, 0, 0);
        gmPaperDollUI::UpdateForRace(v3, heritage);
      }
      v7->vfptr->Release((Interface *)v7);
    }
  }
}

//----- (004A4D80) --------------------------------------------------------  // acclient.c:220959
void __stdcall gmPaperDollUI::HandleDropRelease(UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // ebp@1
  int v4; // esi@1
  unsigned int v5; // edi@1
  int v6; // edx@3
  int v7; // ecx@3
  unsigned int v8; // eax@5
  char v9; // al@9
  HashBaseData<unsigned long> *v10; // eax@14
  UI_SLOT_SIDE slotSide; // [sp+10h] [bp-10h]@3
  unsigned int dropItemID; // [sp+14h] [bp-Ch]@5
  DropItemFlags dropFlags; // [sp+18h] [bp-8h]@5
  unsigned int dropSpellID; // [sp+1Ch] [bp-4h]@5

  v2 = i_rMsg->dwParam1;
  v3 = *(UIElement **)(v2 + 8);
  v4 = *(_DWORD *)(v2 + 16);
  v5 = 0;
  if ( v3 && v4 )
  {
    v6 = *(_DWORD *)v4;
    v7 = *(_DWORD *)(v2 + 16);
    i_rMsg = 0;
    slotSide = 0;
    if ( (*(int (__thiscall **)(int))(v6 + 160))(v7) )
      v5 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 160))(v4) + 740);
    gmPaperDollUI::GetLocationInfoFromElementID(v5, (unsigned int *)&i_rMsg, &slotSide);
    UIElement_ItemList::InqDropIconInfo(v3, &dropItemID, &dropSpellID, &dropFlags);
    v8 = dropItemID;
    if ( dropItemID )
    {
      if ( !(dropFlags & 0xE) )
      {
        if ( !(dropFlags & 1) )
        {
          if ( i_rMsg )
          {
            v9 = gmPaperDollUI::AcceptDragObject(dropItemID, (unsigned int *)&i_rMsg, &slotSide);
LABEL_12:
            if ( v9 )
              return;
            v8 = dropItemID;
            goto LABEL_14;
          }
          if ( *(_DWORD *)(v4 + 740) == 268435926 )
          {
            v9 = gmPaperDollUI::AcceptPaperDollDragObject(dropItemID);
            goto LABEL_12;
          }
        }
LABEL_14:
        v10 = ClientObjMaintSystem::GetWeenieObject(v8);
        if ( v10 )
          ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v10, 0);
        return;
      }
    }
  }
}

//----- (004A4E70) --------------------------------------------------------  // acclient.c:221022
void __thiscall gmPaperDollUI::RecvNotice_SetSelectedItem(gmPaperDollUI *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  if ( _selectedID )
    gmPaperDollUI::BeginPartSelectionLighting((gmPaperDollUI *)((char *)this - 1528), _selectedID);
}

//----- (004A4E90) --------------------------------------------------------  // acclient.c:221029
void __thiscall gmPaperDollUI::UpdateItemSlotTooltip(gmPaperDollUI *this, UIElement_ItemList *i_pSlot, unsigned int _itemID)
{
  gmPaperDollUI *v3; // esi@1
  char v4; // bl@1
  unsigned int v5; // ebp@1
  ACCWeenieObject *v6; // eax@2
  bool v7; // zf@2
  int v8; // edi@7
  int v9; // ebx@87
  int v10; // esi@87
  ACCWeenieObject *v11; // eax@89
  int v12; // esi@89
  UIElement *v13; // eax@92
  UIElement *v14; // esi@92
  char *v15; // esi@94
  char *v16; // esi@97
  PStringBase<unsigned short> strTooltip; // [sp+10h] [bp-A0h]@1
  PStringBase<unsigned short> strItemName; // [sp+14h] [bp-9Ch]@1
  PSRefBufferCharData<unsigned short> **v19; // [sp+18h] [bp-98h]@2
  int v20; // [sp+1Ch] [bp-94h]@2
  StringInfo siTooltip; // [sp+20h] [bp-90h]@92

  strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  strItemName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v4 = 0;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v5 = _itemID;
  if ( _itemID )
  {
    v6 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v20, (PStringBase<unsigned short> *)_itemID, 2u, 0);
    v7 = strItemName.m_charbuffer == (PSRefBufferCharData<unsigned short> *)v6->vfptr;
    v19 = (PSRefBufferCharData<unsigned short> **)v6;
    if ( !v7 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&strItemName.m_charbuffer[-1].m_data[8])
        && strItemName.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
        (**(void (__thiscall ***)(unsigned __int16 *, signed int))&strItemName.m_charbuffer[-1].m_data[6])(
          &strItemName.m_charbuffer[-1].m_data[6],
          1);
      strItemName.m_charbuffer = *v19;
      InterlockedIncrement((volatile LONG *)&strItemName.m_charbuffer[-1].m_data[8]);
      v5 = _itemID;
    }
    v8 = v20 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v20 - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
  if ( i_pSlot == v3->m_neckSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag necklaces here to wear them");
      goto LABEL_92;
    }
LABEL_84:
    v4 = 1;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_leftWristSlot || i_pSlot == v3->m_rightWristSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag bracelets here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_leftRingSlot || i_pSlot == v3->m_rightRingSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag rings here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_weaponReadySlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag weapons here to wield them");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_ammoReadySlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag missile ammunition here to wield it");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_shieldReadySlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag shields here to wield them");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_trinketOneSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag trinkets here to activate them");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_cloakSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag cloaks here to activate them");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_sigilOneSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag a Blue Aetheria sigil here to activate it");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_sigilTwoSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag a Yellow Aetheria sigil here to activate it");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_sigilThreeSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag a Red Aetheria sigil here to activate it");
      goto LABEL_92;
    }
    v4 = 0;
    goto LABEL_85;
  }
  if ( i_pSlot == v3->m_clothesPantsSlot || i_pSlot == v3->m_clothesShirtSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag clothing items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_headSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag head items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_chestSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag chest items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_abdomenSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag abdomen items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_upperArmSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag upper arm items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_lowerArmSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag lower arm items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_handSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag glove items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_upperLegSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag upper leg items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_lowerLegSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag lower leg items here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
  if ( i_pSlot == v3->m_footSlot )
  {
    if ( !v5 )
    {
      PStringBase<unsigned short>::set(&strTooltip, L"Drag foot coverings here to wear them");
      goto LABEL_92;
    }
    goto LABEL_84;
  }
LABEL_85:
  if ( v5 )
  {
    if ( v4 )
    {
      v9 = (int)L"take off";
      v10 = (int)L"worn";
    }
    else
    {
      v9 = (int)L"unwield";
      v10 = (int)L"wielded";
    }
    v11 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v19, (PStringBase<unsigned short> *)v5, 2u, 0);
    PStringBase<unsigned short>::sprintf(&strTooltip, L"%s (%s)\nDouble-click to %s", v11->vfptr, v10, v9);
    v12 = (int)(v19 - 5);
    if ( !InterlockedDecrement((volatile LONG *)v19 - 4) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
  }
LABEL_92:
  StringInfo::StringInfo(&siTooltip);
  StringInfo::SetLiteralValue(&siTooltip, &strTooltip, 1);
  v13 = UIElement_ListBox::GetItem((UIElement_ListBox *)&i_pSlot->vfptr, 0);
  v14 = v13;
  if ( v13 )
  {
    UIElement::SetTooltip(v13, &siTooltip);
    *((_DWORD *)&v14->0 + 41) |= 0x20u;
  }
  StringInfo::~StringInfo(&siTooltip);
  v15 = (char *)&strItemName.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strItemName.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  v16 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) )
  {
    if ( v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  }
}
// 7ABEDC: using guessed type wchar_t aWielded[8];
// 7ABEEC: using guessed type wchar_t aUnwield[8];
// 7ABEFC: using guessed type wchar_t aWorn[5];
// 7ABF08: using guessed type wchar_t aTakeOff[9];

//----- (004A5360) --------------------------------------------------------  // acclient.c:221326
void __thiscall gmPaperDollUI::PostInit(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // esi@1
  UIElement *v2; // eax@1
  UIElement_ItemList *v3; // eax@2
  UIElement *v4; // eax@4
  UIElement_ItemList *v5; // eax@5
  UIElement *v6; // eax@7
  UIElement_ItemList *v7; // eax@8
  UIElement *v8; // eax@10
  UIElement_ItemList *v9; // eax@11
  UIElement *v10; // eax@13
  UIElement_ItemList *v11; // eax@14
  UIElement *v12; // eax@16
  UIElement_ItemList *v13; // eax@17
  UIElement *v14; // eax@19
  UIElement_ItemList *v15; // eax@20
  UIElement *v16; // eax@22
  UIElement_ItemList *v17; // eax@23
  UIElement *v18; // eax@25
  UIElement_ItemList *v19; // eax@26
  UIElement *v20; // eax@28
  UIElement_ItemList *v21; // eax@29
  UIElement *v22; // eax@31
  UIElement_ItemList *v23; // eax@32
  UIElement *v24; // eax@34
  UIElement_ItemList *v25; // eax@35
  UIElement *v26; // eax@37
  UIElement_ItemList *v27; // eax@38
  UIElement *v28; // eax@40
  UIElement_ItemList *v29; // eax@41
  UIElement *v30; // eax@43
  UIElement_ItemList *v31; // eax@44
  UIElement *v32; // eax@46
  UIElement_ItemList *v33; // eax@47
  UIElement *v34; // eax@49
  UIElement_ItemList *v35; // eax@50
  UIElement *v36; // eax@52
  UIElement_ItemList *v37; // eax@53
  UIElement *v38; // eax@55
  UIElement_ItemList *v39; // eax@56
  UIElement *v40; // eax@58
  UIElement_ItemList *v41; // eax@59
  UIElement *v42; // eax@61
  UIElement_ItemList *v43; // eax@62
  UIElement *v44; // eax@64
  UIElement_ItemList *v45; // eax@65
  UIElement *v46; // eax@67
  UIElement_ItemList *v47; // eax@68
  UIElement *v48; // eax@70
  UIElement_ItemList *v49; // eax@71
  UIElement *v50; // eax@73
  UIElement_Viewport *v51; // eax@74
  UIElement_Viewport *v52; // ecx@77
  UIElement *v53; // eax@78
  UIElement *v54; // eax@78
  UIElement *v55; // eax@78
  UIElement *v56; // eax@78
  int v57; // eax@79
  GlobalEventHandler *v58; // eax@81
  GlobalEventHandler *v59; // edi@81
  int v60; // eax@83
  int v61; // edi@83
  ElementDesc *v62; // eax@84
  Vector3 direction; // [sp+24h] [bp-18h]@77
  Vector3 position; // [sp+30h] [bp-Ch]@77

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DAu);
  if ( v2 )
    v3 = (UIElement_ItemList *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435505);
  else
    v3 = 0;
  v1->m_neckSlot = v3;
  UIElement_ItemList::RegisterItemListDragHandler(v3, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_neckSlot, 0);
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DBu);
  if ( v4 )
    v5 = (UIElement_ItemList *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435505);
  else
    v5 = 0;
  v1->m_leftWristSlot = v5;
  UIElement_ItemList::RegisterItemListDragHandler(v5, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_leftWristSlot, 0);
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DCu);
  if ( v6 )
    v7 = (UIElement_ItemList *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435505);
  else
    v7 = 0;
  v1->m_leftRingSlot = v7;
  UIElement_ItemList::RegisterItemListDragHandler(v7, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_leftRingSlot, 0);
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DDu);
  if ( v8 )
    v9 = (UIElement_ItemList *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)268435505);
  else
    v9 = 0;
  v1->m_rightWristSlot = v9;
  UIElement_ItemList::RegisterItemListDragHandler(v9, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_rightWristSlot, 0);
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DEu);
  if ( v10 )
    v11 = (UIElement_ItemList *)v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)268435505);
  else
    v11 = 0;
  v1->m_rightRingSlot = v11;
  UIElement_ItemList::RegisterItemListDragHandler(v11, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_rightRingSlot, 0);
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001DFu);
  if ( v12 )
    v13 = (UIElement_ItemList *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)268435505);
  else
    v13 = 0;
  v1->m_weaponReadySlot = v13;
  UIElement_ItemList::RegisterItemListDragHandler(v13, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_weaponReadySlot, 0);
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001E0u);
  if ( v14 )
    v15 = (UIElement_ItemList *)v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)268435505);
  else
    v15 = 0;
  v1->m_ammoReadySlot = v15;
  UIElement_ItemList::RegisterItemListDragHandler(v15, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_ammoReadySlot, 0);
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001E1u);
  if ( v16 )
    v17 = (UIElement_ItemList *)v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)268435505);
  else
    v17 = 0;
  v1->m_shieldReadySlot = v17;
  UIElement_ItemList::RegisterItemListDragHandler(v17, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_shieldReadySlot, 0);
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001E3u);
  if ( v18 )
    v19 = (UIElement_ItemList *)v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)268435505);
  else
    v19 = 0;
  v1->m_clothesPantsSlot = v19;
  UIElement_ItemList::RegisterItemListDragHandler(v19, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_clothesPantsSlot, 0);
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001E2u);
  if ( v20 )
    v21 = (UIElement_ItemList *)v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)268435505);
  else
    v21 = 0;
  v1->m_clothesShirtSlot = v21;
  UIElement_ItemList::RegisterItemListDragHandler(v21, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_clothesShirtSlot, 0);
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000058Eu);
  if ( v22 )
    v23 = (UIElement_ItemList *)v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)268435505);
  else
    v23 = 0;
  v1->m_trinketOneSlot = v23;
  UIElement_ItemList::RegisterItemListDragHandler(v23, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_trinketOneSlot, 0);
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005E9u);
  if ( v24 )
    v25 = (UIElement_ItemList *)v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)268435505);
  else
    v25 = 0;
  v1->m_cloakSlot = v25;
  UIElement_ItemList::RegisterItemListDragHandler(v25, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_cloakSlot, 0);
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000595u);
  if ( v26 )
    v27 = (UIElement_ItemList *)v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)268435505);
  else
    v27 = 0;
  v1->m_sigilOneSlot = v27;
  UIElement_ItemList::RegisterItemListDragHandler(v27, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_sigilOneSlot, 0);
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000596u);
  if ( v28 )
    v29 = (UIElement_ItemList *)v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)268435505);
  else
    v29 = 0;
  v1->m_sigilTwoSlot = v29;
  UIElement_ItemList::RegisterItemListDragHandler(v29, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_sigilTwoSlot, 0);
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000597u);
  if ( v30 )
    v31 = (UIElement_ItemList *)v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)268435505);
  else
    v31 = 0;
  v1->m_sigilThreeSlot = v31;
  UIElement_ItemList::RegisterItemListDragHandler(v31, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_sigilThreeSlot, 0);
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005ABu);
  if ( v32 )
    v33 = (UIElement_ItemList *)v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)268435505);
  else
    v33 = 0;
  v1->m_headSlot = v33;
  UIElement_ItemList::RegisterItemListDragHandler(v33, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_headSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_headSlot->vfptr[2].__vecDelDtor)(0);
  v34 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005ACu);
  if ( v34 )
    v35 = (UIElement_ItemList *)v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)268435505);
  else
    v35 = 0;
  v1->m_chestSlot = v35;
  UIElement_ItemList::RegisterItemListDragHandler(v35, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_chestSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_chestSlot->vfptr[2].__vecDelDtor)(0);
  v36 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005ADu);
  if ( v36 )
    v37 = (UIElement_ItemList *)v36->vfptr[12].OnAction((IInputActionCallback *)v36, (InputEvent *)268435505);
  else
    v37 = 0;
  v1->m_abdomenSlot = v37;
  UIElement_ItemList::RegisterItemListDragHandler(v37, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_abdomenSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_abdomenSlot->vfptr[2].__vecDelDtor)(0);
  v38 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005AEu);
  if ( v38 )
    v39 = (UIElement_ItemList *)v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)268435505);
  else
    v39 = 0;
  v1->m_upperArmSlot = v39;
  UIElement_ItemList::RegisterItemListDragHandler(v39, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_upperArmSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_upperArmSlot->vfptr[2].__vecDelDtor)(0);
  v40 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005AFu);
  if ( v40 )
    v41 = (UIElement_ItemList *)v40->vfptr[12].OnAction((IInputActionCallback *)v40, (InputEvent *)268435505);
  else
    v41 = 0;
  v1->m_lowerArmSlot = v41;
  UIElement_ItemList::RegisterItemListDragHandler(v41, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_lowerArmSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_lowerArmSlot->vfptr[2].__vecDelDtor)(0);
  v42 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005B0u);
  if ( v42 )
    v43 = (UIElement_ItemList *)v42->vfptr[12].OnAction((IInputActionCallback *)v42, (InputEvent *)268435505);
  else
    v43 = 0;
  v1->m_handSlot = v43;
  UIElement_ItemList::RegisterItemListDragHandler(v43, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_handSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_handSlot->vfptr[2].__vecDelDtor)(0);
  v44 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005B1u);
  if ( v44 )
    v45 = (UIElement_ItemList *)v44->vfptr[12].OnAction((IInputActionCallback *)v44, (InputEvent *)268435505);
  else
    v45 = 0;
  v1->m_upperLegSlot = v45;
  UIElement_ItemList::RegisterItemListDragHandler(v45, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_upperLegSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_upperLegSlot->vfptr[2].__vecDelDtor)(0);
  v46 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005B2u);
  if ( v46 )
    v47 = (UIElement_ItemList *)v46->vfptr[12].OnAction((IInputActionCallback *)v46, (InputEvent *)268435505);
  else
    v47 = 0;
  v1->m_lowerLegSlot = v47;
  UIElement_ItemList::RegisterItemListDragHandler(v47, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_lowerLegSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_lowerLegSlot->vfptr[2].__vecDelDtor)(0);
  v48 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005B3u);
  if ( v48 )
    v49 = (UIElement_ItemList *)v48->vfptr[12].OnAction((IInputActionCallback *)v48, (InputEvent *)268435505);
  else
    v49 = 0;
  v1->m_footSlot = v49;
  UIElement_ItemList::RegisterItemListDragHandler(v49, (ItemListDragHandler *)&v1->vfptr);
  gmPaperDollUI::UpdateItemSlotTooltip(v1, v1->m_footSlot, 0);
  ((void (__stdcall *)(_DWORD))v1->m_footSlot->vfptr[2].__vecDelDtor)(0);
  v50 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001D5u);
  if ( v50 )
    v51 = (UIElement_Viewport *)v50->vfptr[12].OnAction((IInputActionCallback *)v50, (InputEvent *)13);
  else
    v51 = 0;
  v1->m_pPaperDoll = v51;
  if ( v51 )
  {
    LODWORD(direction.x) = 0;
    LODWORD(direction.y) = 0;
    LODWORD(direction.z) = 0;
    LODWORD(position.x) = 1039516303;
    LODWORD(position.y) = -1072064102;
    LODWORD(position.z) = 1063339950;
    UIElement_Viewport::SetCamera(v51, &position, &direction);
    v52 = v1->m_pPaperDoll;
    LODWORD(position.x) = 1050253722;
    LODWORD(position.y) = 1072902963;
    LODWORD(position.z) = 1059481190;
    UIElement_Viewport::SetLight(v52, DISTANT_LIGHT, 2.0, &position);
    CreatureMode::UseSharpMode((CreatureMode *)&v1->m_pPaperDoll->creature_mode_objects);
    gmPaperDollUI::RedressCreature(v1);
  }
  v1->m_paperDollDragMask = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001D6u);
  v1->m_paperDollDragOverlay = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000046Du);
  v53 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000595u);
  v1->m_sigilOneItem = v53;
  v53->vfptr[2].__vecDelDtor((IInputActionCallback *)v53, 0);
  v54 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000596u);
  v1->m_sigilTwoItem = v54;
  v54->vfptr[2].__vecDelDtor((IInputActionCallback *)v54, 0);
  v55 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000597u);
  v1->m_sigilThreeItem = v55;
  v55->vfptr[2].__vecDelDtor((IInputActionCallback *)v55, 0);
  v56 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005BEu);
  if ( v56 )
    v57 = v56->vfptr[12].OnAction((IInputActionCallback *)v56, (InputEvent *)1);
  else
    v57 = 0;
  v1->m_SlotCheckbox = (UIElement_Button *)v57;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    322,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    188,
    &v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xBu);
  v58 = GlobalEventHandler::GetGlobalEventHandler();
  v59 = v58;
  if ( v58 )
  {
    v58->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v58, 100016u, (NoticeHandler *)&v1->vfptr);
    v59->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v59, 100010u, (NoticeHandler *)&v1->vfptr);
    v59->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v59, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  }
  v60 = DBObj::GetByEnum(268435512, 5, 0x23u);
  v61 = v60;
  if ( v60 )
  {
    v62 = UIElementManager::CreateChildElement(
            UIElementManager::s_pInstance,
            v1->m_paperDollDragMask,
            (LayoutDesc *)v60,
            0x10000345u);
    v1->m_dragIcon = (UIElement *)v62;
    ((void (__thiscall *)(ElementDesc *, _DWORD))v62->vfptr->HandleNode)(v62, 0);
  }
  gmPaperDollUI::CreateClickMap(v1);
  UIElement::SetAttribute_Bool((UIElement *)&v1->m_SlotCheckbox->vfptr, 0xEu, 0);
  if ( v61 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v61 + 20))(v61);
}

//----- (004A5C30) --------------------------------------------------------  // acclient.c:221672
UIElementMessageListenResult __thiscall gmPaperDollUI::ListenToElementMessage(gmPaperDollUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  int v4; // esi@1
  int v5; // ecx@3
  UIElementMessageListenResult result; // eax@4
  unsigned int v7; // eax@12
  unsigned int v8; // edi@12
  int v9; // edi@17
  int v10; // eax@17
  unsigned int v11; // edi@17
  unsigned int v12; // eax@18
  Target_Mode v13; // ST08_4@21
  unsigned int v14; // ST04_4@21
  ClientUISystem *v15; // eax@21
  ClientUISystem *v16; // eax@24

  v2 = i_rMsg;
  v3 = i_rMsg->idMessage;
  v4 = (int)this;
  if ( v3 == 1 )
  {
    if ( i_rMsg->idElement == 268436926 )
    {
      UIElement::GetAttribute_Bool((UIElement *)&this->m_SlotCheckbox->vfptr, 0xEu, (bool *)&i_rMsg);
      v5 = *(_DWORD *)(v4 + 1640);
      if ( (_BYTE)i_rMsg )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1652) + 24))(0);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1600) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1604) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1608) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1612) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1616) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1620) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1624) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1628) + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1632) + 24))(1);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      else
      {
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v5 + 24))(1);
        (*(void (__stdcall **)(signed int))(**(_DWORD **)(v4 + 1652) + 24))(1);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1600) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1604) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1608) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1612) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1616) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1620) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1624) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1628) + 24))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 1632) + 24))(0);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      return result;
    }
    return UIElement::ListenToElementMessage((UIElement *)v4, v2);
  }
  if ( v3 == 21 )
  {
    if ( i_rMsg->idElement == 268435926 )
      ((void (__stdcall *)(signed int))this->m_paperDollDragOverlay->vfptr[13].__vecDelDtor)(268435519);
    gmPaperDollUI::HandleDropRelease(v2);
    result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
  }
  else
  {
    if ( v3 == 33 )
    {
      if ( i_rMsg->idElement == 268435926 )
      {
        v7 = gmPaperDollUI::GetPaperDollItemUnderMouse(this, i_rMsg->ptWindow.x, i_rMsg->ptWindow.y);
        v8 = v7;
        if ( v7 )
        {
          if ( gmPaperDollUI::PrepareDragIcon((gmPaperDollUI *)v4, v4, v7) )
          {
            UIElementManager::StartDragandDrop(UIElementManager::s_pInstance, *(UIElement **)(v4 + 1648), 16, 16);
            CM_Item::SendNotice_BeginDrag(v8, 0, 0);
            return UIElement::ListenToElementMessage((UIElement *)v4, v2);
          }
        }
      }
      return UIElement::ListenToElementMessage((UIElement *)v4, v2);
    }
    if ( v3 == 28 )
    {
      if ( i_rMsg->idElement != 268435926 )
        return UIElement::ListenToElementMessage((UIElement *)v4, v2);
      v9 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
      v10 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
      v11 = gmPaperDollUI::GetPaperDollItemUnderMouse((gmPaperDollUI *)v4, v9, v10);
      if ( !v11 )
        return UIElement::ListenToElementMessage((UIElement *)v4, v2);
      v12 = v2->dwParam1;
      if ( v12 != 7 )
      {
        if ( v12 == 8 )
        {
          ACCWeenieObject::SetSelectedObject(v11, 0);
          v16 = ClientUISystem::GetUISystem();
          ClientUISystem::ExamineObject(v16, v11);
          return UIElement::ListenToElementMessage((UIElement *)v4, v2);
        }
        return UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      if ( ClientUISystem::GetUISystem() && ClientUISystem::GetUISystem()->targetMode )
      {
        v13 = ClientUISystem::GetUISystem()->targetMode;
        v14 = GetPlayerID();
        v15 = ClientUISystem::GetUISystem();
        ClientUISystem::ExecuteTargetModeForItem(v15, v14, v13);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      else
      {
        ACCWeenieObject::SetSelectedObject(v11, 0);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
    }
    else
    {
      if ( v3 != 62 || i_rMsg->idElement != 268435926 )
        return UIElement::ListenToElementMessage((UIElement *)v4, v2);
      if ( !i_rMsg->dwParam1 )
      {
        ((void (__stdcall *)(signed int))this->m_paperDollDragOverlay->vfptr[13].__vecDelDtor)(268435519);
        return UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      if ( UIElementManager::s_pInstance->m_dragElement )
      {
        gmPaperDollUI::HandlePaperDollDragOver(this, UIElementManager::s_pInstance->m_dragElement);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
      else
      {
        ((void (__stdcall *)(_DWORD))this->m_paperDollDragOverlay->vfptr[13].__vecDelDtor)(268435519);
        result = UIElement::ListenToElementMessage((UIElement *)v4, v2);
      }
    }
  }
  return result;
}

//----- (004A5F90) --------------------------------------------------------  // acclient.c:221820
void __thiscall gmPaperDollUI::SetUIItemIntoLocation(gmPaperDollUI *this, unsigned int _itemID, unsigned int _location)
{
  gmPaperDollUI *v3; // esi@1
  CPlayerSystem *v4; // eax@1
  unsigned int v5; // ebx@1
  CPlayerSystem *v6; // ebp@1

  v3 = this;
  v4 = CPlayerSystem::GetPlayerSystem();
  v5 = _location;
  v6 = v4;
  if ( SBYTE1(v5) < 0 )
  {
    v4->m_invSlotModule.neckSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_neckSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_neckSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_neckSlot, _itemID);
  }
  if ( v5 & 0x10000 )
  {
    v6->m_invSlotModule.leftWristSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_leftWristSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_leftWristSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_leftWristSlot, _itemID);
  }
  if ( v5 & 0x20000 )
  {
    v6->m_invSlotModule.rightWristSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_rightWristSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_rightWristSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_rightWristSlot, _itemID);
  }
  if ( v5 & 0x40000 )
  {
    v6->m_invSlotModule.leftRingSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_leftRingSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_leftRingSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_leftRingSlot, _itemID);
  }
  if ( v5 & 0x80000 )
  {
    v6->m_invSlotModule.rightRingSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_rightRingSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_rightRingSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_rightRingSlot, _itemID);
  }
  if ( _location & 0x3500000 )
  {
    v6->m_invSlotModule.weaponReadySlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_weaponReadySlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_weaponReadySlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_weaponReadySlot, _itemID);
  }
  if ( v5 & 0x200000 )
  {
    v6->m_invSlotModule.shieldReadySlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_shieldReadySlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_shieldReadySlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_shieldReadySlot, _itemID);
  }
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & _location )
  {
    v6->m_invSlotModule.ammoReadySlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_ammoReadySlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_ammoReadySlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_ammoReadySlot, _itemID);
  }
  if ( _location & 0x40 )
  {
    v6->m_invSlotModule.clothesPantsSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_clothesPantsSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_clothesPantsSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_clothesPantsSlot, _itemID);
  }
  if ( _location & 2 )
  {
    v6->m_invSlotModule.clothesShirtSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_clothesShirtSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_clothesShirtSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_clothesShirtSlot, _itemID);
  }
  if ( _location & 0x4000000 )
  {
    v6->m_invSlotModule.trinketOneSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_trinketOneSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_trinketOneSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_trinketOneSlot, _itemID);
  }
  if ( _location & 0x8000000 )
  {
    v6->m_invSlotModule.cloakSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_cloakSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_cloakSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_cloakSlot, _itemID);
  }
  if ( _location & 0x10000000 )
  {
    v6->m_invSlotModule.sigilOneSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_sigilOneSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_sigilOneSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_sigilOneSlot, _itemID);
  }
  if ( _location & 0x20000000 )
  {
    v6->m_invSlotModule.sigilTwoSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_sigilTwoSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_sigilTwoSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_sigilTwoSlot, _itemID);
  }
  if ( _location & 0x40000000 )
  {
    v6->m_invSlotModule.sigilThreeSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_sigilThreeSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_sigilThreeSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_sigilThreeSlot, _itemID);
  }
  if ( _location & 1 )
  {
    v6->m_invSlotModule.headSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_headSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_headSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_headSlot, _itemID);
  }
  if ( BYTE1(v5) & 2 )
  {
    v6->m_invSlotModule.chestSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_chestSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_chestSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_chestSlot, _itemID);
  }
  if ( BYTE1(v5) & 4 )
  {
    v6->m_invSlotModule.abdomenSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_abdomenSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_abdomenSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_abdomenSlot, _itemID);
  }
  if ( BYTE1(v5) & 8 )
  {
    v6->m_invSlotModule.upperArmSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_upperArmSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_upperArmSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_upperArmSlot, _itemID);
  }
  if ( BYTE1(v5) & 0x10 )
  {
    v6->m_invSlotModule.lowerArmSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_lowerArmSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_lowerArmSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_lowerArmSlot, _itemID);
  }
  if ( _location & 0x20 )
  {
    v6->m_invSlotModule.handSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_handSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_handSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_handSlot, _itemID);
  }
  if ( BYTE1(v5) & 0x20 )
  {
    v6->m_invSlotModule.upperLegSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_upperLegSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_upperLegSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_upperLegSlot, _itemID);
  }
  if ( BYTE1(v5) & 0x40 )
  {
    v6->m_invSlotModule.lowerLegSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_lowerLegSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_lowerLegSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_lowerLegSlot, _itemID);
  }
  if ( BYTE1(v5) & 1 )
  {
    v6->m_invSlotModule.footSlot->m_itemID = _itemID;
    UIElement_ItemList::ItemList_Flush(v3->m_footSlot);
    UIElement_ItemList::ItemList_AddItem(v3->m_footSlot, _itemID);
    gmPaperDollUI::UpdateItemSlotTooltip(v3, v3->m_footSlot, _itemID);
  }
}

//----- (004A64A0) --------------------------------------------------------  // acclient.c:222002
void __thiscall gmPaperDollUI::ServerSaysMoveItem(gmPaperDollUI *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  gmPaperDollUI *v9; // ebx@1
  HashBaseData<unsigned long> *v10; // edi@1
  CPlayerSystem *v11; // eax@1
  CPlayerSystem *v12; // esi@1
  unsigned int v13; // eax@4
  unsigned int v14; // eax@8
  unsigned int v15; // edx@8
  unsigned int v16; // ecx@10
  unsigned int v17; // eax@12
  unsigned int v18; // eax@16
  unsigned int v19; // edx@18

  v9 = this;
  v10 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v11 = CPlayerSystem::GetPlayerSystem();
  v12 = v11;
  if ( v10 )
  {
    if ( v11 )
    {
      v13 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
      if ( _oldWielder == v13 && _oldLocation )
      {
        v14 = (unsigned int)v10[16].vfptr;
        v15 = v12->inventoryMask;
        if ( v14 & 0x8007FFF )
        {
          v16 = v12->clothingPriorityMask;
          v12->inventoryMask = ~v14 & v15;
          v12->clothingPriorityMask = ~v10[15].id & v16;
          gmPaperDollUI::SetUIItemIntoLocation(v9, 0, v14);
        }
        else
        {
          v12->inventoryMask = ~_oldLocation & v15;
          gmPaperDollUI::SetUIItemIntoLocation(v9, 0, _oldLocation);
        }
      }
    }
    if ( SmartBox::smartbox )
      v17 = SmartBox::smartbox->player_id;
    else
      v17 = 0;
    if ( _newWielder == v17 && _newLocation )
    {
      v18 = (unsigned int)v10[16].vfptr;
      if ( v18 & 0x8007FFF )
      {
        v19 = v12->clothingPriorityMask;
        v12->inventoryMask |= v18;
        v12->clothingPriorityMask = v10[15].id | v19;
        gmPaperDollUI::SetUIItemIntoLocation(v9, _itemID, v18);
      }
      else
      {
        v12->inventoryMask |= _newLocation;
        gmPaperDollUI::SetUIItemIntoLocation(v9, _itemID, _newLocation);
      }
    }
  }
}

//----- (004A65C0) --------------------------------------------------------  // acclient.c:222067
char __thiscall gmPaperDollUI::RemakeCharacterInventory(gmPaperDollUI *this)
{
  gmPaperDollUI *v1; // ebx@1
  unsigned int v2; // eax@2
  HashBaseData<unsigned long> *v3; // esi@4
  CPlayerSystem *v4; // eax@4
  CPlayerSystem *v5; // edi@4
  PackableList<InventoryPlacement> *v6; // eax@6
  PackableLLNode<InventoryPlacement> *i; // esi@7
  unsigned int v8; // eax@8
  unsigned int v9; // ecx@8
  unsigned int v10; // edx@8

  v1 = this;
  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  v3 = ClientObjMaintSystem::GetWeenieObject(v2);
  v4 = CPlayerSystem::GetPlayerSystem();
  v5 = v4;
  if ( v3 )
  {
    if ( v4 )
    {
      v4->inventoryMask = 0;
      v4->clothingPriorityMask = 0;
      gmPaperDollUI::SetUIItemIntoLocation(v1, 0, 0x7FFFFFFFu);
      v6 = ACCWeenieObject::GetInvPlacementList((ACCWeenieObject *)v3);
      if ( v6 )
      {
        for ( i = v6->head; i; i = i->next )
        {
          v8 = i->data.loc_;
          v9 = i->data.iid_;
          v10 = i->data.priority_;
          if ( v8 )
            v5->inventoryMask |= v8;
          if ( v8 & 0x8007FFF )
            v5->clothingPriorityMask |= v10;
          gmPaperDollUI::SetUIItemIntoLocation(v1, v9, v8);
        }
        gmPaperDollUI::RedressCreature(v1);
      }
    }
  }
  return 1;
}

//----- (006F0C20) --------------------------------------------------------  // acclient.c:772947
void _E91_69()
{
  outside_val_61 = 1000.0 + 1.0;
}

//----- (006F0C40) --------------------------------------------------------  // acclient.c:772953
void _E93_45()
{
  block_length_61 = 24.0 * 8.0;
}

//----- (006F0C60) --------------------------------------------------------  // acclient.c:772959
void _E95_45()
{
  half_square_length_61 = 24.0 * 0.5;
}

//----- (006F0C80) --------------------------------------------------------  // acclient.c:772965
int _E97_70()
{
  return atexit(_E98_82);
}

//----- (006F0C90) --------------------------------------------------------  // acclient.c:772971
int _E100_63()
{
  return atexit(nullsub_839);
}

//----- (006F0CA0) --------------------------------------------------------  // acclient.c:772977
int _E103_55()
{
  return atexit(_E104_70);
}

//----- (006F0CB0) --------------------------------------------------------  // acclient.c:772983
void _E109_25()
{
  DEFAULT_VIEW_RADIUS_34 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0CD0) --------------------------------------------------------  // acclient.c:772989
void _E111_14()
{
  MIN_QUANTUM_34 = 1.0 / 30.0;
}

//----- (006F0CF0) --------------------------------------------------------  // acclient.c:772995
void _E113_2()
{
  MAX_QUANTUM_34 = 1.0 / 5.0;
}

//----- (006F0D10) --------------------------------------------------------  // acclient.c:773001
void _E115_28()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_69, PFID_A8R8G8B8);
}

//----- (006F0D20) --------------------------------------------------------  // acclient.c:773007
int _E117_24()
{
  return atexit(nullsub_836);
}

//----- (006F0D30) --------------------------------------------------------  // acclient.c:773013
void _E121_36()
{
  LOWEST_DATA_RATE_75 = 1024;
}

//----- (006F0D40) --------------------------------------------------------  // acclient.c:773019
void _E123_14()
{
  HIGHEST_DATA_RATE_75 = 0x7FFF;
}

//----- (006F0D50) --------------------------------------------------------  // acclient.c:773025
int _E125_1()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_75;
  INITIAL_MAX_DATA_RATE_23 = LOWEST_DATA_RATE_75;
  return result;
}

//----- (006F0D60) --------------------------------------------------------  // acclient.c:773035
int _E127_29()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_28, "Misc.TooltipEnable");
  return atexit(_E128_43);
}

//----- (006F0D80) --------------------------------------------------------  // acclient.c:773042
int _E130_24()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_28, "Misc.TooltipDelay");
  return atexit(_E131_33);
}

//----- (006F0DA0) --------------------------------------------------------  // acclient.c:773049
int sub_6F0DA0()
{
  return atexit(nullsub_837);
}

//----- (00760E00) --------------------------------------------------------  // acclient.c:888632
void __cdecl _E128_43()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760E30) --------------------------------------------------------  // acclient.c:888645
void __cdecl _E131_33()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

