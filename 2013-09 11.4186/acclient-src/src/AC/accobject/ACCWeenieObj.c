/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCWeenieObj
   Object     : AC\accobject\ACCWeenieObj.obj
   Functions  : 148
   Addresses  : 004F80B0 - 00774B00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F80B0) --------------------------------------------------------  // acclient.c:291504
LongHash<IconData> *__thiscall LongHash<CObjectInventory>::vector_deleting_destructor(LongHash<IconData> *this, unsigned int a2)
{
  LongHash<IconData> *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  v3 = this->fPlacementNew_;
  this->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](this->buckets);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (0052C1C0) --------------------------------------------------------  // acclient.c:347847
int __stdcall CEnvCell::handle_move_restriction(ObjCollisionProfile *prof)
{
  return 1;
}

//----- (0058BCA0) --------------------------------------------------------  // acclient.c:436286
void __thiscall ACCWeenieObject::SetOpenable(ACCWeenieObject *this, const int openable)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( openable )
    this->pwd._bitfield = v2 | 1;
  else
    this->pwd._bitfield = v2 & 0xFFFFFFFE;
}

//----- (0058BCD0) --------------------------------------------------------  // acclient.c:436298
void __thiscall ACCWeenieObject::SetStuck(ACCWeenieObject *this, const int stuck)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( stuck )
    this->pwd._bitfield = v2 | 4;
  else
    this->pwd._bitfield = v2 & 0xFFFFFFFB;
}

//----- (0058BD00) --------------------------------------------------------  // acclient.c:436310
void __thiscall ACCWeenieObject::SetInscribable(ACCWeenieObject *this, const int inscribable)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( inscribable )
    this->pwd._bitfield = v2 | 2;
  else
    this->pwd._bitfield = v2 & 0xFFFFFFFD;
}

//----- (0058BD30) --------------------------------------------------------  // acclient.c:436322
void __thiscall ACCWeenieObject::SetHiddenAdmin(ACCWeenieObject *this, const int hide)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( hide )
    this->pwd._bitfield = v2 | 0x40;
  else
    this->pwd._bitfield = v2 & 0xFFFFFFBF;
}

//----- (0058BD60) --------------------------------------------------------  // acclient.c:436334
void __thiscall ACCWeenieObject::SetUIHidden(ACCWeenieObject *this, const int hide)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( hide )
    this->pwd._bitfield = v2 | 0x80;
  else
    this->pwd._bitfield = v2 & 0xFFFFFF7F;
}

//----- (0058BD90) --------------------------------------------------------  // acclient.c:436346
void __thiscall ACCWeenieObject::SetCellBarrierImmune(ACCWeenieObject *this, const int b)
{
  unsigned int v2; // eax@1

  v2 = this->pwd._bitfield;
  if ( b )
    this->pwd._bitfield = v2 | 0x400000;
  else
    this->pwd._bitfield = v2 & 0xFFBFFFFF;
}

//----- (0058BDC0) --------------------------------------------------------  // acclient.c:436358
void __thiscall ACCWeenieObject::ResetPlayerDesc(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  PlayerDesc *v2; // ecx@1
  PlayerDesc *v3; // eax@3
  PlayerDesc *v4; // eax@4

  v1 = this;
  v2 = this->m_pQualities;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pQualities = 0;
  }
  v3 = (PlayerDesc *)operator new(0x90u);
  if ( v3 )
  {
    PlayerDesc::PlayerDesc(v3);
    v1->m_pQualities = v4;
  }
  else
  {
    v1->m_pQualities = 0;
  }
}

//----- (0058BE10) --------------------------------------------------------  // acclient.c:436385
void __thiscall ACCWeenieObject::SetParentedState(ACCWeenieObject *this, int _parentedState)
{
  if ( _parentedState )
    this->pwd._location = this->pwd._valid_locations;
  else
    this->pwd._location = 0;
}

//----- (0058BE40) --------------------------------------------------------  // acclient.c:436394
void __thiscall ACCWeenieObject::ServerSaysContainID(ACCWeenieObject *this, unsigned int _item, int _place, int _itemIsContainer)
{
  CObjectInventory *v4; // eax@1
  int v5; // ecx@2

  v4 = this->objInventory;
  if ( v4 )
  {
    v5 = (int)&v4->_containersList;
    if ( !_itemIsContainer )
      v5 = (int)&v4->_itemsList;
    IDList::AddAtNum((IDList *)v5, _item, _place, 1);
  }
}

//----- (0058BE70) --------------------------------------------------------  // acclient.c:436410
void __thiscall ACCWeenieObject::DeterminePositionState(ACCWeenieObject *this)
{
  if ( this->beingRemoved )
  {
    this->current_state = 3;
  }
  else if ( this->pwd._containerID )
  {
    this->current_state = 2;
  }
  else
  {
    this->current_state = this->pwd._location != 0;
  }
}

//----- (0058BEB0) --------------------------------------------------------  // acclient.c:436427
int __thiscall ACCWeenieObject::GetNumContainedItems(ACCWeenieObject *this)
{
  CObjectInventory *v1; // eax@1
  int result; // eax@2

  v1 = this->objInventory;
  if ( v1 )
    result = v1->_itemsList.numIDs;
  else
    result = 0;
  return result;
}

//----- (0058BEC0) --------------------------------------------------------  // acclient.c:436441
int __thiscall ACCWeenieObject::GetNumContainedContainers(ACCWeenieObject *this)
{
  CObjectInventory *v1; // eax@1
  int result; // eax@2

  v1 = this->objInventory;
  if ( v1 )
    result = v1->_containersList.numIDs;
  else
    result = 0;
  return result;
}

//----- (0058BED0) --------------------------------------------------------  // acclient.c:436455
int __thiscall ACCWeenieObject::GetNumEmptyItemSlots(ACCWeenieObject *this)
{
  int result; // eax@1
  CObjectInventory *v2; // ecx@2

  result = this->pwd._itemsCapacity;
  if ( result != -1 )
  {
    v2 = this->objInventory;
    if ( v2 )
      result -= v2->_itemsList.numIDs;
  }
  return result;
}

//----- (0058BEF0) --------------------------------------------------------  // acclient.c:436471
IDList *__thiscall ACCWeenieObject::GetContainedItemsList(ACCWeenieObject *this)
{
  CObjectInventory *v1; // eax@1
  IDList *result; // eax@2

  v1 = this->objInventory;
  if ( v1 )
    result = &v1->_itemsList;
  else
    result = 0;
  return result;
}

//----- (0058BF00) --------------------------------------------------------  // acclient.c:436485
IDList *__thiscall ACCWeenieObject::GetContainedContainersList(ACCWeenieObject *this)
{
  CObjectInventory *v1; // eax@1
  IDList *result; // eax@2

  v1 = this->objInventory;
  if ( v1 )
    result = &v1->_containersList;
  else
    result = 0;
  return result;
}

//----- (0058BF10) --------------------------------------------------------  // acclient.c:436499
IDList *__thiscall ACCWeenieObject::GetExhaustiveContainedItemsList(ACCWeenieObject *this, IDList *result)
{
  ACCWeenieObject *v2; // ebx@1
  CObjectInventory *v3; // eax@1
  int v4; // esi@2
  int v5; // edi@3
  unsigned int v6; // eax@4
  CObjectInventory *v7; // eax@5
  int v8; // ebx@6
  int v9; // ebp@7
  unsigned int v10; // eax@8
  HashBaseData<unsigned long> *v11; // eax@8
  unsigned int v12; // eax@9
  int v13; // esi@10
  int v14; // edi@11
  unsigned int v15; // eax@12
  IDList allMyContainedItems; // [sp+Ch] [bp-18h]@1

  v2 = this;
  IDList::IDList(&allMyContainedItems);
  v3 = v2->objInventory;
  if ( v3 )
  {
    v4 = (int)&v3->_itemsList;
    if ( v3 != (CObjectInventory *)-12 )
    {
      v5 = 0;
      if ( v3->_itemsList.numIDs > 0 )
      {
        do
        {
          v6 = IDList::GetByNum((IDList *)v4, v5);
          IDList::Add(&allMyContainedItems, v6);
          ++v5;
        }
        while ( v5 < *(_DWORD *)(v4 + 16) );
      }
    }
  }
  v7 = v2->objInventory;
  if ( v7 )
  {
    v8 = (int)&v7->_containersList;
    if ( v7 != (CObjectInventory *)-36 )
    {
      v9 = 0;
      if ( v7->_containersList.numIDs > 0 )
      {
        do
        {
          v10 = IDList::GetByNum((IDList *)v8, v9);
          v11 = ClientObjMaintSystem::GetWeenieObject(v10);
          if ( v11 )
          {
            v12 = v11[6].id;
            if ( v12 )
            {
              v13 = v12 + 12;
              if ( v12 != -12 )
              {
                v14 = 0;
                if ( *(_DWORD *)(v12 + 28) > 0 )
                {
                  do
                  {
                    v15 = IDList::GetByNum((IDList *)v13, v14);
                    IDList::Add(&allMyContainedItems, v15);
                    ++v14;
                  }
                  while ( v14 < *(_DWORD *)(v13 + 16) );
                }
              }
            }
          }
          ++v9;
        }
        while ( v9 < *(_DWORD *)(v8 + 16) );
      }
    }
  }
  IDList::IDList(result, &allMyContainedItems);
  IDList::~IDList(&allMyContainedItems);
  return result;
}

//----- (0058BFF0) --------------------------------------------------------  // acclient.c:436585
PackableList<InventoryPlacement> *__thiscall ACCWeenieObject::GetInvPlacementList(ACCWeenieObject *this)
{
  CObjectInventory *v1; // eax@1
  PackableList<InventoryPlacement> *result; // eax@2

  v1 = this->objInventory;
  if ( v1 )
    result = &v1->_invPlacement;
  else
    result = 0;
  return result;
}

//----- (0058C000) --------------------------------------------------------  // acclient.c:436599
int __thiscall ACCWeenieObject::AllContainedObjectsExist(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // ebx@1
  CObjectInventory *v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  unsigned int v5; // eax@4
  HashBaseData<unsigned long> *v6; // eax@4
  CObjectInventory *v7; // eax@7
  int v8; // esi@8
  int v9; // edi@9
  unsigned int v10; // eax@10

  v1 = this;
  v2 = this->objInventory;
  if ( v2 && (v3 = (int)&v2->_containersList, v2 != (CObjectInventory *)-36) && (v4 = 0, v2->_containersList.numIDs) )
  {
    while ( 1 )
    {
      v5 = IDList::GetByNum((IDList *)v3, v4);
      v6 = ClientObjMaintSystem::GetWeenieObject(v5);
      if ( !v6 || !ACCWeenieObject::AllContainedObjectsExist((ACCWeenieObject *)v6) )
        break;
      ++v4;
      if ( (unsigned int)v4 >= *(_DWORD *)(v3 + 16) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v7 = v1->objInventory;
    if ( !v7 )
      return 1;
    v8 = (int)&v7->_itemsList;
    if ( v7 == (CObjectInventory *)-12 )
      return 1;
    v9 = 0;
    if ( !v7->_itemsList.numIDs )
      return 1;
    while ( 1 )
    {
      v10 = IDList::GetByNum((IDList *)v8, v9);
      if ( !ClientObjMaintSystem::GetWeenieObject(v10) )
        break;
      ++v9;
      if ( (unsigned int)v9 >= *(_DWORD *)(v8 + 16) )
        return 1;
    }
  }
  return 0;
}

//----- (0058C090) --------------------------------------------------------  // acclient.c:436653
int __thiscall ACCWeenieObject::GetPlaceInItemsList(ACCWeenieObject *this, unsigned int _id)
{
  CObjectInventory *v2; // eax@1
  int result; // eax@2

  v2 = this->objInventory;
  if ( v2 )
    result = IDList::GetPlaceInList(&v2->_itemsList, _id);
  else
    result = 0;
  return result;
}

//----- (0058C0B0) --------------------------------------------------------  // acclient.c:436667
int __thiscall ACCWeenieObject::GetPlaceInContainersList(ACCWeenieObject *this, unsigned int _id)
{
  CObjectInventory *v2; // eax@1
  int result; // eax@2

  v2 = this->objInventory;
  if ( v2 )
    result = IDList::GetPlaceInList(&v2->_containersList, _id);
  else
    result = 0;
  return result;
}

//----- (0058C0D0) --------------------------------------------------------  // acclient.c:436681
void __thiscall ACCWeenieObject::SetWaitingState(ACCWeenieObject *this, int _waiting)
{
  if ( _waiting != this->waiting )
  {
    this->waiting = _waiting;
    if ( this->valid )
      GenItemHolder::ItemAttributesChanged_s(this->id, 0);
  }
}

//----- (0058C100) --------------------------------------------------------  // acclient.c:436692
void __thiscall ACCWeenieObject::SetShortcutNum(ACCWeenieObject *this, int i_nShortcutNum, bool i_bGhosted)
{
  int v3; // eax@3

  if ( i_nShortcutNum != this->shortcutNum || i_bGhosted != this->m_bShortcutGhosted )
  {
    this->shortcutNum = i_nShortcutNum;
    v3 = this->valid;
    this->m_bShortcutGhosted = i_bGhosted;
    if ( v3 )
      GenItemHolder::ItemAttributesChanged_s(this->id, 0);
  }
}

//----- (0058C140) --------------------------------------------------------  // acclient.c:436707
void __thiscall ACCWeenieObject::SetTradeState(ACCWeenieObject *this, int _tradeState)
{
  if ( _tradeState != this->tradeState )
  {
    this->tradeState = _tradeState;
    if ( this->valid )
      GenItemHolder::ItemAttributesChanged_s(this->id, 0);
  }
}

//----- (0058C170) --------------------------------------------------------  // acclient.c:436718
void __thiscall ACCWeenieObject::SetSellState(ACCWeenieObject *this, int _sellState)
{
  if ( _sellState != this->sellState )
  {
    this->sellState = _sellState;
    if ( this->valid )
      GenItemHolder::ItemAttributesChanged_s(this->id, 0);
  }
}

//----- (0058C1A0) --------------------------------------------------------  // acclient.c:436729
int __cdecl ACCWeenieObject::ObjectsInRange(unsigned int _ID1, unsigned int _ID2, long double _range, bool _use_radii, bool _xy_only)
{
  HashBaseData<unsigned long> *v5; // esi@1
  HashBaseData<unsigned long> *v6; // eax@1

  v5 = CObjectMaint::GetObjectA(CWeenieObject::objMaint, _ID1);
  v6 = CObjectMaint::GetObjectA(CWeenieObject::objMaint, _ID2);
  if ( v5 && v6 )
  {
    if ( _xy_only )
    {
      if ( Position::xy_distance((Position *)&v5[6], (Position *)&v6[6]) <= _range )
        return 1;
    }
    else if ( CPhysicsObj::get_distance_to_object((CPhysicsObj *)v5, (CPhysicsObj *)v6, _use_radii) <= _range )
    {
      return 1;
    }
  }
  return 0;
}

//----- (0058C220) --------------------------------------------------------  // acclient.c:436752
void __cdecl ACCWeenieObject::RecordRequest(unsigned int _requestObjID, InventoryRequest _request)
{
  ACCWeenieObject::prevRequestObjectID = _requestObjID;
  ACCWeenieObject::prevRequest = _request;
  *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;

//----- (0058C250) --------------------------------------------------------  // acclient.c:436763
int __thiscall ACCWeenieObject::InqShowableOnRadar(ACCWeenieObject *this, AC1Legacy::Vector3 *cur_pos)
{
  int result; // eax@2
  RadarEnum v3; // eax@3

  result = 0;
  if ( this->_phys_obj )
  {
    v3 = this->pwd._radar_enum;
    if ( v3 == 2 || v3 == 4 || v3 == 3 )
      result = 1;
  }
  return result;
}

//----- (0058C280) --------------------------------------------------------  // acclient.c:436779
void __thiscall ACCWeenieObject::SetStructure(ACCWeenieObject *this, const unsigned int structure)
{
  this->pwd._structure = structure;
  GenItemHolder::ItemAttributesChanged_s(this->id, 0);
}

//----- (0058C2A0) --------------------------------------------------------  // acclient.c:436786
void __thiscall ACCWeenieObject::SetMaxStructure(ACCWeenieObject *this, const unsigned int maxStructure)
{
  this->pwd._maxStructure = maxStructure;
  GenItemHolder::ItemAttributesChanged_s(this->id, 0);
}

//----- (0058C2C0) --------------------------------------------------------  // acclient.c:436793
void __thiscall ACCWeenieObject::SetStackSize(ACCWeenieObject *this, const unsigned int stackSize)
{
  this->pwd._stackSize = stackSize;
  GenItemHolder::ItemAttributesChanged_s(this->id, 0);
}

//----- (0058C2E0) --------------------------------------------------------  // acclient.c:436800
void __cdecl ACCWeenieObject::SetSelectedObject(unsigned int _selectedID, int _reselect)
{
  unsigned int v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@4
  HashBaseData<unsigned long> *v4; // eax@7
  IACPlugin *v5; // eax@14

  v2 = ACCWeenieObject::selectedID;
  if ( _reselect || ACCWeenieObject::selectedID != _selectedID )
  {
    if ( ACCWeenieObject::selectedID )
    {
      v3 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v3 )
        v3[9].vfptr = 0;
    }
    ACCWeenieObject::selectedID = _selectedID;
    if ( _selectedID )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(_selectedID);
      if ( v4 )
        v4[9].vfptr = (HashBaseData<unsigned long>Vtbl *)1;
    }
    if ( v2 != _selectedID )
    {
      ACCWeenieObject::prevSelectedID = v2;
      if ( v2 )
        ACCWeenieObject::prevSelectedValidID = v2;
      CM_UI::SendNotice_SelectionChanged();
    }
    GenItemHolder::SetSelectedItem_s(v2, ACCWeenieObject::selectedID);
    if ( APIManager::APIIsReady() )
    {
      v5 = APIManager::GetACPlugin();
      ((void (__stdcall *)(IACPlugin *, unsigned int, _Formatted))v5->vfptr[3].AddRef)(
        v5,
        v2,
        ACCWeenieObject::selectedID);
    }
  }
}
// 870E4C: using guessed type unsigned __int32 ACCWeenieObject::prevSelectedValidID;

//----- (0058C380) --------------------------------------------------------  // acclient.c:436844
void __cdecl ACCWeenieObject::SetPreviousSelectedObject(unsigned int _selectedID)
{
  ACCWeenieObject::prevSelectedID = _selectedID;
}

//----- (0058C390) --------------------------------------------------------  // acclient.c:436850
void __cdecl ACCWeenieObject::SetSelectedObjectID(unsigned int _selectedID)
{
  ACCWeenieObject::selectedID = _selectedID;
}

//----- (0058C3A0) --------------------------------------------------------  // acclient.c:436856
int __thiscall ACCWeenieObject::DoCollision(ACCWeenieObject *this, EnvCollisionProfile *prof)
{
  CPhysicsObj *v2; // ecx@1
  unsigned int v3; // eax@2

  v2 = this->_phys_obj;
  if ( v2 )
  {
    v3 = v2->state;
    if ( SBYTE1(v3) < 0 )
      CPhysicsObj::play_default_script(v2);
  }
  return 1;
}

//----- (0058C3D0) --------------------------------------------------------  // acclient.c:436872
BOOL __thiscall ACCWeenieObject::IsThePlayer(ACCWeenieObject *this)
{
  return this->id == SmartBox::smartbox->player_id;
}

//----- (0058C3F0) --------------------------------------------------------  // acclient.c:436878
unsigned int __thiscall ACCWeenieObject::IsCreature(ACCWeenieObject *this)
{
  return ((unsigned int)((int (*)(void))this->vfptr[6].__vecDelDtor)() >> 4) & 1;
}

//----- (0058C400) --------------------------------------------------------  // acclient.c:436884
bool __thiscall ACCWeenieObject::CanJump(ACCWeenieObject *this, float extent)
{
  ACCWeenieObject *v2; // esi@1
  PlayerDesc *v3; // eax@2
  bool result; // al@3

  v2 = this;
  if ( ((int (*)(void))this->vfptr[5].__vecDelDtor)() && (v3 = v2->m_pQualities) != 0 )
    result = ((int (__thiscall *)(int, _DWORD))v3->vfptr->CanJump)(&v3->vfptr, LODWORD(extent)) != 0;
  else
    result = 0;
  return result;
}

//----- (0058C440) --------------------------------------------------------  // acclient.c:436899
bool __thiscall ACCWeenieObject::JumpStaminaCost(ACCWeenieObject *this, float extent, int *cost)
{
  ACCWeenieObject *v3; // esi@1
  PlayerDesc *v4; // eax@2
  bool result; // al@3

  v3 = this;
  if ( ((int (*)(void))this->vfptr[5].__vecDelDtor)() && (v4 = v3->m_pQualities) != 0 )
    result = ((int (__thiscall *)(int, _DWORD, int *))v4->vfptr->JumpStaminaCost)(&v4->vfptr, LODWORD(extent), cost) != 0;
  else
    result = 0;
  return result;
}

//----- (0058C480) --------------------------------------------------------  // acclient.c:436914
int __thiscall ACCWeenieObject::PlayScript(ACCWeenieObject *this, PScriptType script_type, float mod)
{
  CPhysicsObj *v3; // ecx@1
  int result; // eax@2

  v3 = this->_phys_obj;
  if ( v3 )
    result = CPhysicsObj::play_script(v3, script_type, mod);
  else
    result = 0;
  return result;
}

//----- (0058C4A0) --------------------------------------------------------  // acclient.c:436928
int __thiscall ACCWeenieObject::GetNumEmitters(ACCWeenieObject *this)
{
  CPhysicsObj *v1; // ecx@1
  int result; // eax@2

  v1 = this->_phys_obj;
  if ( v1 )
    result = CPhysicsObj::get_num_emitters(v1);
  else
    result = 0;
  return result;
}

//----- (0058C4C0) --------------------------------------------------------  // acclient.c:436942
int __thiscall ACCWeenieObject::GetGlobalVelocity(ACCWeenieObject *this, AC1Legacy::Vector3 *velocity)
{
  CPhysicsObj *v2; // ecx@1
  int v3; // eax@2
  AC1Legacy::Vector3 *v4; // eax@3
  AC1Legacy::Vector3 result; // [sp+0h] [bp-Ch]@3

  v2 = this->_phys_obj;
  if ( v2 )
  {
    v4 = CPhysicsObj::get_velocity(v2, &result);
    velocity->x = v4->x;
    velocity->y = v4->y;
    velocity->z = v4->z;
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (0058C500) --------------------------------------------------------  // acclient.c:436966
BOOL __thiscall ACCWeenieObject::CanBypassMoveRestrictions(ACCWeenieObject *this)
{
  unsigned int v1; // eax@1

  v1 = this->pwd._bitfield;
  return v1 & 0x100000 && v1 & 0x400000;
}

//----- (0058C520) --------------------------------------------------------  // acclient.c:436975
bool __thiscall ACCWeenieObject::InqJumpVelocity(ACCWeenieObject *this, float extent, float *v_z)
{
  ACCWeenieObject *v3; // esi@1
  PlayerDesc *v4; // eax@2
  bool result; // al@3

  v3 = this;
  if ( ((int (*)(void))this->vfptr[5].__vecDelDtor)() && (v4 = v3->m_pQualities) != 0 )
    result = ((int (__thiscall *)(int, _DWORD, float *))v4->vfptr->InqJumpVelocity)(&v4->vfptr, LODWORD(extent), v_z) != 0;
  else
    result = 0;
  return result;
}

//----- (0058C560) --------------------------------------------------------  // acclient.c:436990
bool __thiscall ACCWeenieObject::InqRunRate(ACCWeenieObject *this, float *rate)
{
  ACCWeenieObject *v2; // esi@1
  PlayerDesc *v3; // eax@2
  bool result; // al@3

  v2 = this;
  if ( ((int (*)(void))this->vfptr[5].__vecDelDtor)() && (v3 = v2->m_pQualities) != 0 )
    result = v3->vfptr->InqRunRate((CBaseQualities *)&v3->vfptr, rate) != 0;
  else
    result = 0;
  return result;
}

//----- (0058C5A0) --------------------------------------------------------  // acclient.c:437005
bool __thiscall ACCWeenieObject::InqMaxRunRate(ACCWeenieObject *this, float *rate)
{
  ACCWeenieObject *v2; // esi@1
  PlayerDesc *v3; // eax@2
  bool result; // al@3

  v2 = this;
  if ( ((int (*)(void))this->vfptr[5].__vecDelDtor)() && (v3 = v2->m_pQualities) != 0 )
    result = v3->vfptr->InqMaxRunRate((CBaseQualities *)&v3->vfptr, rate) != 0;
  else
    result = 0;
  return result;
}

//----- (0058C5E0) --------------------------------------------------------  // acclient.c:437020
int __thiscall ACCWeenieObject::SetupStamper(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  int result; // eax@2
  ACWTimeStamper *v3; // eax@3
  ACWTimeStamper *v4; // eax@4

  v1 = this;
  if ( this->_stamper )
  {
    result = 1;
  }
  else
  {
    v3 = (ACWTimeStamper *)operator new(0x80u);
    if ( v3 )
    {
      ACWTimeStamper::ACWTimeStamper(v3);
      v1->_stamper = v4;
      result = v4 != 0;
    }
    else
    {
      v1->_stamper = 0;
      result = 0;
    }
  }
  return result;
}

//----- (0058C630) --------------------------------------------------------  // acclient.c:437051
int __thiscall ACCWeenieObject::IsAllegianceMember(ACCWeenieObject *this, ACCWeenieObject *wobj)
{
  unsigned int v2; // eax@2
  int result; // eax@3

  if ( wobj && (v2 = this->pwd._monarch) != 0 )
    result = v2 == wobj->pwd._monarch;
  else
    result = 0;
  return result;
}

//----- (0058C660) --------------------------------------------------------  // acclient.c:437064
int __thiscall ACCWeenieObject::IsHook(ACCWeenieObject *this)
{
  int result; // eax@1

  result = 0;
  if ( this->pwd._hook_type )
  {
    if ( this->pwd._hook_item_types )
      result = 1;
  }
  return result;
}

//----- (0058C680) --------------------------------------------------------  // acclient.c:437078
void __thiscall ACCWeenieObject::OnStatUpdated(ACCWeenieObject *this, unsigned int stype, int val)
{
  switch ( stype )
  {
    case 3u:
      ACCWeenieObject::SetOpenable(this, val == 0);
      break;
    case 1u:
      ACCWeenieObject::SetStuck(this, val);
      break;
    case 0x16u:
      ACCWeenieObject::SetInscribable(this, val);
      break;
    case 0x1Au:
      ACCWeenieObject::SetHiddenAdmin(this, val);
      break;
    case 0x18u:
      ACCWeenieObject::SetUIHidden(this, val);
      break;
    case 0x19u:
      ACCWeenieObject::SetCellBarrierImmune(this, val);
      break;
    default:
      return;
  }
}

//----- (0058C730) --------------------------------------------------------  // acclient.c:437106
CWeenieObject *__thiscall CWeenieObject::vector_deleting_destructor(CWeenieObject *this, unsigned int a2)
{
  return CWeenieObject::scalar_deleting_destructor((CWeenieObject *)((char *)this - 12), a2);
}

//----- (0058C740) --------------------------------------------------------  // acclient.c:437112
CWeenieObject *__thiscall CWeenieObject::scalar_deleting_destructor(CWeenieObject *this, unsigned int a2)
{
  CWeenieObject *v2; // esi@1
  NoticeRegistrar *v3; // edi@1

  v2 = this;
  v3 = (NoticeRegistrar *)&this->vfptr;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&CWeenieObject::vftable;
  this->vfptr = (NoticeRegistrarVtbl *)&CWeenieObject::vftable;
  TSRecv::~TSRecv(&this->blobOrdering);
  NoticeRegistrar::~NoticeRegistrar(v3);
  v2->hash_next = 0;
  v2->id = 0;
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7E3DF4: using guessed type void *CWeenieObject::vftable;
// 7E3E08: using guessed type int (__thiscall *CWeenieObject::vftable)(void *, char);

//----- (0058C790) --------------------------------------------------------  // acclient.c:437135
void __thiscall ACCWeenieObject::ACCWeenieObject(ACCWeenieObject *this, unsigned int iid)
{
  ACCWeenieObject *v2; // esi@1
  char *v3; // edi@1
  unsigned int v4; // ecx@1
  PlayerDesc *v5; // eax@2
  PlayerDesc *v6; // eax@3

  v2 = this;
  v3 = (char *)&this->vfptr;
  this->hash_next = 0;
  this->id = iid;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  NoticeRegistrar::NoticeRegistrar((NoticeRegistrar *)&this->vfptr);
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)&CWeenieObject::vftable;
  *(_DWORD *)v3 = &CWeenieObject::vftable;
  v2->netblob_list = 0;
  TSRecv::TSRecv(&v2->blobOrdering, 0, 0x80000000);
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)&ACCWeenieObject::vftable;
  *(_DWORD *)v3 = &ACCWeenieObject::vftable;
  v2->objInventory = 0;
  v2->valid = 0;
  v2->awaitingAuthentication = 0;
  v2->markedForDeletion = 0;
  v2->movedWhileMarkedForDeletion = 0;
  v2->beingRemoved = 0;
  v2->current_state = 0;
  v2->selected = 0;
  v2->waiting = 0;
  v2->sellState = 0;
  v2->tradeState = 0;
  v2->shortcutNum = -1;
  v2->m_bShortcutGhosted = 0;
  v2->preRemoveContainerID = 0;
  v2->preRemoveWielderID = 0;
  v2->preRemoveLocation = 0;
  v2->preRemoveContainerPlace = 0;
  v2->_phys_obj = 0;
  PublicWeenieDesc::PublicWeenieDesc(&v2->pwd);
  v4 = v2->id;
  v2->_stamper = 0;
  v2->m_pQualities = 0;
  if ( v4 == SmartBox::smartbox->player_id )
  {
    v5 = (PlayerDesc *)operator new(0x90u);
    if ( v5 )
    {
      PlayerDesc::PlayerDesc(v5);
      v2->m_pQualities = v6;
    }
    else
    {
      v2->m_pQualities = 0;
    }
  }
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7E3DF4: using guessed type void *CWeenieObject::vftable;
// 7E3E08: using guessed type int (__thiscall *CWeenieObject::vftable)(void *, char);
// 7E3E88: using guessed type void *ACCWeenieObject::vftable;
// 7E3EA0: using guessed type int (__thiscall *ACCWeenieObject::vftable)(void *, char);

//----- (0058C890) --------------------------------------------------------  // acclient.c:437198
unsigned int __thiscall ACCWeenieObject::IsPlayer(ACCWeenieObject *this)
{
  return (this->pwd._bitfield >> 3) & 1;
}

//----- (0058C8A0) --------------------------------------------------------  // acclient.c:437204
unsigned int __thiscall ACCWeenieObject::IsPKLite(ACCWeenieObject *this)
{
  return (this->pwd._bitfield >> 25) & 1;
}

//----- (0058C8B0) --------------------------------------------------------  // acclient.c:437210
unsigned int __thiscall ACCWeenieObject::IsPK(ACCWeenieObject *this)
{
  return (this->pwd._bitfield >> 5) & 1;
}

//----- (0058C8C0) --------------------------------------------------------  // acclient.c:437216
unsigned int __thiscall ACCWeenieObject::IsImpenetrable(ACCWeenieObject *this)
{
  return (this->pwd._bitfield >> 21) & 1;
}

//----- (0058C8D0) --------------------------------------------------------  // acclient.c:437222
ITEM_TYPE __thiscall ACCWeenieObject::InqType(ACCWeenieObject *this)
{
  return this->pwd._type;
}

//----- (0058C8E0) --------------------------------------------------------  // acclient.c:437228
unsigned int __thiscall ACCWeenieObject::IsCorpse(ACCWeenieObject *this)
{
  return (this->pwd._bitfield >> 13) & 1;
}

//----- (0058C8F0) --------------------------------------------------------  // acclient.c:437234
ACCWeenieObject *__thiscall ACCWeenieObject::vector_deleting_destructor(ACCWeenieObject *this, unsigned int a2)
{
  return ACCWeenieObject::scalar_deleting_destructor((ACCWeenieObject *)((char *)this - 12), a2);
}

//----- (0058C900) --------------------------------------------------------  // acclient.c:437240
IDClass<_tagDataID,32,0> *__thiscall ACCWeenieObject::InqIconID(ACCWeenieObject *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->pwd._iconID.id;
  return v2;
}

//----- (0058C910) --------------------------------------------------------  // acclient.c:437250
BOOL __thiscall ACCWeenieObject::IsPlayerKiller(ACCWeenieObject *this)
{
  unsigned int v1; // eax@1

  v1 = this->pwd._bitfield;
  return v1 & 0x20 || v1 & 0x2000000;
}

//----- (0058C930) --------------------------------------------------------  // acclient.c:437259
void __thiscall ACCWeenieObject::~ACCWeenieObject(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  PlayerDesc *v2; // ecx@1

  v1 = this;
  v2 = this->m_pQualities;
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)&ACCWeenieObject::vftable;
  v1->vfptr = (NoticeRegistrarVtbl *)&ACCWeenieObject::vftable;
  if ( v2 )
  {
    PlayerDesc::Cleanup(v2);
    ((void (*)(void))v1->m_pQualities->vfptr->Release)();
  }
  PublicWeenieDesc::~PublicWeenieDesc(&v1->pwd);
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)&CWeenieObject::vftable;
  v1->vfptr = (NoticeRegistrarVtbl *)&CWeenieObject::vftable;
  TSRecv::~TSRecv(&v1->blobOrdering);
  NoticeRegistrar::~NoticeRegistrar((NoticeRegistrar *)&v1->vfptr);
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  v1->hash_next = 0;
  v1->id = 0;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7E3DF4: using guessed type void *CWeenieObject::vftable;
// 7E3E08: using guessed type int (__thiscall *CWeenieObject::vftable)(void *, char);
// 7E3E88: using guessed type void *ACCWeenieObject::vftable;
// 7E3EA0: using guessed type int (__thiscall *ACCWeenieObject::vftable)(void *, char);

//----- (0058C9A0) --------------------------------------------------------  // acclient.c:437289
void __thiscall ACCWeenieObject::AddContentsToDestructionQueue(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // ebx@1
  CObjectInventory *v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  unsigned int v5; // eax@4
  CObjectInventory *v6; // eax@5
  int v7; // esi@6
  int v8; // edi@7
  unsigned int v9; // eax@8

  v1 = this;
  v2 = this->objInventory;
  if ( v2 )
  {
    v3 = (int)&v2->_containersList;
    if ( v2 != (CObjectInventory *)-36 )
    {
      v4 = 0;
      if ( v2->_containersList.numIDs > 0 )
      {
        do
        {
          v5 = IDList::GetByNum((IDList *)v3, v4);
          CObjectMaint::AddObjectToBeDestroyed(CWeenieObject::objMaint, v5);
          ++v4;
        }
        while ( v4 < *(_DWORD *)(v3 + 16) );
      }
    }
  }
  v6 = v1->objInventory;
  if ( v6 )
  {
    v7 = (int)&v6->_itemsList;
    if ( v6 != (CObjectInventory *)-12 )
    {
      v8 = 0;
      if ( v6->_itemsList.numIDs > 0 )
      {
        do
        {
          v9 = IDList::GetByNum((IDList *)v7, v8);
          CObjectMaint::AddObjectToBeDestroyed(CWeenieObject::objMaint, v9);
          ++v8;
        }
        while ( v8 < *(_DWORD *)(v7 + 16) );
      }
    }
  }
}

//----- (0058CA20) --------------------------------------------------------  // acclient.c:437343
void __thiscall ACCWeenieObject::RemoveContentsFromDestructionQueue(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // ebp@1
  CObjectInventory *v2; // eax@1
  int v3; // edi@2
  int v4; // ebx@3
  unsigned int v5; // esi@4
  HashBaseData<unsigned long> *v6; // eax@4
  CObjectInventory *v7; // eax@7
  int v8; // esi@8
  int v9; // edi@9
  unsigned int v10; // eax@10

  v1 = this;
  v2 = this->objInventory;
  if ( v2 )
  {
    v3 = (int)&v2->_containersList;
    if ( v2 != (CObjectInventory *)-36 )
    {
      v4 = 0;
      if ( v2->_containersList.numIDs > 0 )
      {
        do
        {
          v5 = IDList::GetByNum((IDList *)v3, v4);
          CObjectMaint::RemoveObjectToBeDestroyed(CWeenieObject::objMaint, v5);
          v6 = ClientObjMaintSystem::GetWeenieObject(v5);
          if ( v6 )
            ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v6);
          ++v4;
        }
        while ( v4 < *(_DWORD *)(v3 + 16) );
      }
    }
  }
  v7 = v1->objInventory;
  if ( v7 )
  {
    v8 = (int)&v7->_itemsList;
    if ( v7 != (CObjectInventory *)-12 )
    {
      v9 = 0;
      if ( v7->_itemsList.numIDs > 0 )
      {
        do
        {
          v10 = IDList::GetByNum((IDList *)v8, v9);
          CObjectMaint::RemoveObjectToBeDestroyed(CWeenieObject::objMaint, v10);
          ++v9;
        }
        while ( v9 < *(_DWORD *)(v8 + 16) );
      }
    }
  }
}

//----- (0058CAB0) --------------------------------------------------------  // acclient.c:437401
void __cdecl ACCWeenieObject::RecordResponse(unsigned int _responseObjID)
{
  if ( _responseObjID == ACCWeenieObject::prevRequestObjectID )
  {
    ACCWeenieObject::prevRequestObjectID = 0;
    ACCWeenieObject::prevRequest = 0;
    LODWORD(ACCWeenieObject::prevRequestTime) = 0;
    dword_870ECC = 0;
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058CAE0) --------------------------------------------------------  // acclient.c:437417
int __thiscall ACCWeenieObject::InqCollisionProfile(ACCWeenieObject *this, ObjCollisionProfile *prof)
{
  ACCWeenieObject *v2; // esi@1
  const int v3; // eax@1
  const int v4; // eax@1

  v2 = this;
  prof->wcid.id = this->pwd._wcid.id;
  prof->itemType = ((int (*)(void))this->vfptr[6].__vecDelDtor)();
  v3 = ((int (__thiscall *)(ACCWeenieObject *))v2->vfptr[11].__vecDelDtor)(v2);
  ObjCollisionProfile::SetCreature(prof, v3);
  v4 = ((int (__thiscall *)(ACCWeenieObject *))v2->vfptr[4].__vecDelDtor)(v2);
  ObjCollisionProfile::SetPlayer(prof, v4);
  ObjCollisionProfile::SetAttackable(prof, (v2->pwd._bitfield >> 4) & 1);
  ObjCollisionProfile::SetDoor(prof, (v2->pwd._bitfield >> 12) & 1);
  return 1;
}

//----- (0058CB50) --------------------------------------------------------  // acclient.c:437436
int __thiscall ACCWeenieObject::UpdateHouseRestrictionTS(ACCWeenieObject *this, char ts)
{
  ACCWeenieObject *v2; // esi@1
  int result; // eax@1

  v2 = this;
  result = ACCWeenieObject::SetupStamper(this);
  if ( result )
    result = WTimeStamper::UpdateHouseRestrictionTS((WTimeStamper *)&v2->_stamper->vfptr, ts);
  return result;
}

//----- (0058CB80) --------------------------------------------------------  // acclient.c:437449
int __thiscall ACCWeenieObject::MagicPackIsOwned(ACCWeenieObject *this, IDClass<_tagDataID,32,0> wcidEssence)
{
  CObjectInventory *v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  unsigned int v5; // eax@4
  HashBaseData<unsigned long> *v6; // eax@4
  int result; // eax@7

  v2 = this->objInventory;
  if ( v2 && (v3 = (int)&v2->_containersList, v2 != (CObjectInventory *)-36) && (v4 = 0, v2->_containersList.numIDs > 0) )
  {
    while ( 1 )
    {
      v5 = IDList::GetByNum((IDList *)v3, v4);
      v6 = ClientObjMaintSystem::GetWeenieObject(v5);
      if ( v6 )
      {
        if ( v6[13].id == wcidEssence.id )
          break;
      }
      ++v4;
      if ( v4 >= *(_DWORD *)(v3 + 16) )
        goto LABEL_7;
    }
    result = 1;
  }
  else
  {
LABEL_7:
    result = 0;
  }
  return result;
}

//----- (0058CBE0) --------------------------------------------------------  // acclient.c:437485
int __thiscall ACCWeenieObject::IsStorage(ACCWeenieObject *this)
{
  unsigned int v1; // esi@1
  int v2; // eax@2
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v1 = this->pwd._wcid.id;
  if ( v1 == stru_870F0C.id )
  {
    v2 = 0;
  }
  else
  {
    DBObj::GetDIDByEnum(&result, 268435457, 12);
    v2 = result.id == v1;
  }
  return v2;
}

//----- (0058CC20) --------------------------------------------------------  // acclient.c:437506
ACCWeenieObject *__thiscall ACCWeenieObject::scalar_deleting_destructor(ACCWeenieObject *this, unsigned int a2)
{
  ACCWeenieObject *v2; // esi@1

  v2 = this;
  ACCWeenieObject::~ACCWeenieObject(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0058CC40) --------------------------------------------------------  // acclient.c:437518
void __thiscall ACCWeenieObject::ServerSaysSetStackSize(ACCWeenieObject *this, int _size, unsigned int _value)
{
  ACCWeenieObject *v3; // esi@1
  unsigned int v4; // ST00_4@1
  int v5; // eax@1
  int v6; // eax@2

  v3 = this;
  v4 = this->id;
  this->pwd._stackSize = _size;
  GenItemHolder::ItemAttributesChanged_s(v4, 0);
  v5 = v3->waiting;
  v3->pwd._value = _value;
  if ( v5 )
  {
    v6 = v3->valid;
    v3->waiting = 0;
    if ( v6 )
      GenItemHolder::ItemAttributesChanged_s(v3->id, 0);
  }
  if ( v3->id == ACCWeenieObject::prevRequestObjectID )
  {
    ACCWeenieObject::prevRequestObjectID = 0;
    ACCWeenieObject::prevRequest = 0;
    LODWORD(ACCWeenieObject::prevRequestTime) = 0;
    dword_870ECC = 0;
  }
  if ( v3->markedForDeletion )
    v3->movedWhileMarkedForDeletion = 1;
  GenItemHolder::ItemAttributesChanged_s(v3->id, 0);
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058CCE0) --------------------------------------------------------  // acclient.c:437555
void __thiscall ACCWeenieObject::AddContent(ACCWeenieObject *this, ACCWeenieObject *_weenObj, int _place)
{
  ACCWeenieObject *v3; // ebx@1
  CObjectInventory *v4; // ecx@2
  unsigned int v5; // edi@3
  int v6; // esi@3
  ACCWeenieObject *v7; // eax@8
  bool v8; // sf@8
  unsigned __int8 v9; // of@8
  int *v10; // eax@8

  v3 = this;
  if ( _weenObj )
  {
    v4 = this->objInventory;
    if ( v4 )
    {
      v5 = _weenObj->id;
      v6 = (int)&v4->_itemsList;
      if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & _weenObj->pwd._bitfield
        || _weenObj->pwd._itemsCapacity
        || _weenObj->pwd._containersCapacity )
        v6 = (int)&v4->_containersList;
      if ( !IDList::IsInList((IDList *)v6, _weenObj->id) )
      {
        v7 = *(ACCWeenieObject **)(v6 + 16);
        _weenObj = v7;
        v9 = __OFSUB__(v7, _place);
        v8 = (signed int)((char *)v7 - _place) < 0;
        v10 = (int *)&_weenObj;
        if ( !(v8 ^ v9) )
          v10 = &_place;
        IDList::AddAtNum((IDList *)v6, v5, *v10, 1);
        GenItemHolder::ItemAttributesChanged_s(v3->id, 0);
      }
    }
  }
}

//----- (0058CD70) --------------------------------------------------------  // acclient.c:437595
void __thiscall ACCWeenieObject::RemoveContent(ACCWeenieObject *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // edi@1
  CObjectInventory *v3; // edx@2
  int v4; // ecx@3

  v2 = this;
  if ( _weenObj )
  {
    v3 = this->objInventory;
    if ( v3 )
    {
      v4 = (int)&v3->_itemsList;
      if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & _weenObj->pwd._bitfield
        || _weenObj->pwd._itemsCapacity
        || _weenObj->pwd._containersCapacity )
        v4 = (int)&v3->_containersList;
      IDList::RemoveByID((IDList *)v4, _weenObj->id);
      GenItemHolder::ItemAttributesChanged_s(v2->id, 0);
    }
  }
}

//----- (0058CDD0) --------------------------------------------------------  // acclient.c:437619
CObjectInventory *__thiscall ACCWeenieObject::GetLocationOnObject(ACCWeenieObject *this, unsigned int _id)
{
  CObjectInventory *result; // eax@1
  PackableLLNode<InventoryPlacement> *v3; // ecx@2

  result = this->objInventory;
  if ( result )
  {
    v3 = result->_invPlacement.head;
    if ( v3 )
    {
      while ( 1 )
      {
        result = (CObjectInventory *)v3->data.loc_;
        if ( v3->data.iid_ == _id )
          break;
        v3 = v3->next;
        if ( !v3 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      result = 0;
    }
  }
  return result;
}

//----- (0058CE00) --------------------------------------------------------  // acclient.c:437650
CObjectInventory *__thiscall ACCWeenieObject::GetObjectAtLocation(ACCWeenieObject *this, unsigned int _loc, unsigned int _priority)
{
  CObjectInventory *result; // eax@1
  PackableLLNode<InventoryPlacement> *v4; // ecx@2

  result = this->objInventory;
  if ( result )
  {
    v4 = result->_invPlacement.head;
    if ( v4 )
    {
      while ( 1 )
      {
        result = (CObjectInventory *)v4->data.iid_;
        if ( _priority & v4->data.priority_ || !_priority )
        {
          if ( v4->data.loc_ & _loc )
            break;
        }
        v4 = v4->next;
        if ( !v4 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      result = 0;
    }
  }
  return result;
}

//----- (0058CE50) --------------------------------------------------------  // acclient.c:437684
int __thiscall ACCWeenieObject::IsOwnedByTrader(ACCWeenieObject *this, unsigned int _id)
{
  ACCWeenieObject *v2; // esi@1
  int result; // eax@2
  HashBaseData<unsigned long> *v4; // eax@7

  v2 = this;
  if ( !_id )
    return 0;
  if ( this->id == _id || this->pwd._containerID == _id || this->pwd._wielderID == _id )
  {
    result = 1;
  }
  else
  {
    v4 = ClientObjMaintSystem::GetWeenieObject(_id);
    if ( !v4 )
      return 0;
    result = ACCWeenieObject::GetLocationOnObject((ACCWeenieObject *)v4, v2->id) != 0;
  }
  return result;
}

//----- (0058CEB0) --------------------------------------------------------  // acclient.c:437708
int __thiscall ACCWeenieObject::IsOwnedByObject(ACCWeenieObject *this, unsigned int _id)
{
  int result; // eax@1
  ACCWeenieObject *v3; // esi@1
  ACCWeenieObject *v4; // edi@6

  result = _id;
  v3 = this;
  if ( _id )
  {
    if ( this->id == _id || this->pwd._containerID == _id || this->pwd._wielderID == _id )
    {
      result = 1;
    }
    else
    {
      result = (int)ClientObjMaintSystem::GetWeenieObject(_id);
      v4 = (ACCWeenieObject *)result;
      if ( result )
      {
        if ( v3->pwd._containerID
          && ACCWeenieObject::GetPlaceInContainersList((ACCWeenieObject *)result, v3->pwd._containerID) != -1 )
          result = 1;
        else
          result = ACCWeenieObject::GetLocationOnObject(v4, v3->id) != 0;
      }
    }
  }
  return result;
}

//----- (0058CF30) --------------------------------------------------------  // acclient.c:437740
IconData *__thiscall IconData::scalar_deleting_destructor(IconData *this, unsigned int a2)
{
  IconData *v2; // esi@1
  Graphic *v3; // ecx@1
  Graphic *v4; // ecx@3

  v2 = this;
  v3 = this->m_pIcon;
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)&IconData::vftable;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v2->m_pDragIcon;
  v2->m_pIcon = 0;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v2->m_pDragIcon = 0;
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  v2->hash_next = 0;
  v2->id = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7E3F24: using guessed type int (__thiscall *IconData::vftable)(void *, char);

//----- (0058CF80) --------------------------------------------------------  // acclient.c:437767
unsigned int __thiscall ACCWeenieObject::GetHousePayment(ACCWeenieObject *this)
{
  unsigned int result; // eax@1

  result = this->pwd._stackSize;
  if ( !result )
    result = 1;
  return result;
}

//----- (0058CF90) --------------------------------------------------------  // acclient.c:437778
unsigned int __thiscall PackableList<InventoryPlacement>::InsertPos(PackableList<InventoryPlacement> *this, const unsigned int pos, InventoryPlacement *val)
{
  PackableList<InventoryPlacement> *v3; // esi@1
  const unsigned int v4; // ebx@1
  void *v5; // eax@1
  PackableLLNode<InventoryPlacement> *v6; // ecx@4
  const unsigned int result; // eax@5
  PackableLLNode<InventoryPlacement> *v8; // ecx@10
  PackableLLNode<InventoryPlacement> *v9; // edx@11

  v3 = this;
  v4 = pos;
  v5 = operator new(0x18u);
  if ( v5 )
  {
    *(_DWORD *)v5 = &InventoryPlacement::vftable;
    *((_DWORD *)v5 + 1) = val->iid_;
    *((_DWORD *)v5 + 2) = val->loc_;
    *((_DWORD *)v5 + 3) = val->priority_;
    *((_DWORD *)v5 + 4) = 0;
    *((_DWORD *)v5 + 5) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = v3->head;
  if ( !v6 )
  {
    v3->head = (PackableLLNode<InventoryPlacement> *)v5;
    v3->tail = (PackableLLNode<InventoryPlacement> *)v5;
    ++v3->curNum;
    return 0;
  }
  if ( pos )
  {
    while ( v6 )
    {
      --v4;
      v6 = v6->next;
      if ( !v4 )
        goto LABEL_9;
    }
    goto LABEL_10;
  }
LABEL_9:
  if ( !v6 )
  {
LABEL_10:
    v8 = v3->tail;
    v8->next = (PackableLLNode<InventoryPlacement> *)v5;
    *((_DWORD *)v5 + 5) = v8;
    v3->tail = (PackableLLNode<InventoryPlacement> *)v5;
    result = v3->curNum;
    v3->curNum = result + 1;
    return result;
  }
  v9 = v6->prev;
  if ( v9 )
    v9->next = (PackableLLNode<InventoryPlacement> *)v5;
  else
    v3->head = (PackableLLNode<InventoryPlacement> *)v5;
  *((_DWORD *)v5 + 5) = v6->prev;
  *((_DWORD *)v5 + 4) = v6;
  v6->prev = (PackableLLNode<InventoryPlacement> *)v5;
  ++v3->curNum;
  return pos;
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (0058D050) --------------------------------------------------------  // acclient.c:437849
int __cdecl ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(int _quiet)
{
  char *v1; // esi@4
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@4
  StringInfo siError; // [sp+4h] [bp-90h]@4

  if ( !ClientUISystem::GetUISystem() )
    return 0;
  if ( ACCWeenieObject::prevRequest == IR_NONE )
  {
    if ( !ACCWeenieObject::attackInProgress )
      return 1;
    if ( !_quiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &_value,
        L"You cannot move or use an item while attacking");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
    }
    return 0;
  }
  if ( !_quiet )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You can only move or use one item at a time");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v1 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v1 )
        (**(void (__thiscall ***)(char *, signed int))v1)(v1, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
  }
  return 0;
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870ED0: using guessed type int ACCWeenieObject::attackInProgress;

//----- (0058D160) --------------------------------------------------------  // acclient.c:437894
int __thiscall ACCWeenieObject::IsOwnedByPlayer(ACCWeenieObject *this)
{
  return ACCWeenieObject::IsOwnedByObject(this, SmartBox::smartbox->player_id);
}

//----- (0058D180) --------------------------------------------------------  // acclient.c:437900
void __thiscall IconData::RenderIcons(IconData *this, ACCWeenieObject *_weenObj)
{
  IconData *v2; // esi@1
  ACCWeenieObject *v3; // edi@1
  Graphic *v4; // ecx@1
  Graphic *v5; // ecx@3
  int v6; // eax@7
  int v7; // eax@9
  QualifiedDataID *v8; // eax@11
  QualifiedDataID *v9; // eax@11
  int v10; // eax@11
  RenderSurface *v11; // ebp@11
  QualifiedDataID *v12; // eax@11
  int v13; // eax@11
  RenderSurface *v14; // edi@11
  int v15; // eax@11
  int v16; // ebx@11
  int v17; // edi@12
  PixelFormatID v18; // eax@12
  Graphic *v19; // eax@19
  Graphic *v20; // eax@20
  int v21; // eax@22
  int v22; // edi@22
  int v23; // ebp@23
  PixelFormatID v24; // eax@23
  Graphic *v25; // eax@28
  Graphic *v26; // eax@29
  DBObjGrabber<RenderSurface> spOverlay; // [sp+2Ch] [bp-38h]@11
  int spUnderlay; // [sp+30h] [bp-34h]@11
  int spBackground; // [sp+34h] [bp-30h]@9
  DBObjGrabber<RenderSurface> spIcon; // [sp+38h] [bp-2Ch]@11
  QualifiedDataID v31; // [sp+3Ch] [bp-28h]@11
  QualifiedDataID v32; // [sp+44h] [bp-20h]@11
  QualifiedDataID v33; // [sp+4Ch] [bp-18h]@11
  RGBAColor white; // [sp+54h] [bp-10h]@18

  v2 = this;
  v3 = _weenObj;
  this->m_idIcon.id = *(_DWORD *)_weenObj->vfptr[25].__vecDelDtor(
                                   (HashBaseData<unsigned long> *)_weenObj,
                                   (unsigned int)&_weenObj);
  v2->m_idCustomOverlay.id = v3->pwd._iconOverlayID.id;
  v2->m_idCustomUnderlay.id = v3->pwd._iconUnderlayID.id;
  v2->m_itemType = ((int (__thiscall *)(ACCWeenieObject *))v3->vfptr[6].__vecDelDtor)(v3);
  v2->m_effects = v3->pwd._effects;
  v4 = v2->m_pIcon;
  if ( v4 )
    ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  v5 = v2->m_pDragIcon;
  v2->m_pIcon = 0;
  if ( v5 )
    ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
  v2->m_pDragIcon = 0;
  if ( ((int (__thiscall *)(ACCWeenieObject *))v3->vfptr[5].__vecDelDtor)(v3) )
  {
    v2->m_idIcon.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&_weenObj, 268435460, 7)->id;
    v2->m_itemType = 512;
  }
  v6 = LowestSetBit(v2->m_itemType) + 1;
  if ( !v6 )
    v6 = 33;
  spBackground = DBObj::GetByEnum(v6, 268435460, 0xCu);
  v7 = LowestSetBit(v2->m_effects);
  _weenObj = (ACCWeenieObject *)DBObj::GetByEnum(v7 + 1, 268435461, 0xCu);
  if ( !_weenObj )
    _weenObj = (ACCWeenieObject *)DBObj::GetByEnum(33, 268435461, 0xCu);
  QualifiedDataID::QualifiedDataID(&v31, v2->m_idCustomUnderlay, 0xCu);
  spUnderlay = DBObj::Get(v8);
  QualifiedDataID::QualifiedDataID(&v32, v2->m_idIcon, 0xCu);
  v10 = DBObj::Get(v9);
  v11 = (RenderSurface *)v10;
  spIcon.m_object = (RenderSurface *)v10;
  QualifiedDataID::QualifiedDataID(&v33, v2->m_idCustomOverlay, 0xCu);
  v13 = DBObj::Get(v12);
  v14 = (RenderSurface *)v13;
  spOverlay.m_object = (RenderSurface *)v13;
  v15 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
  v16 = v15;
  if ( v15 )
  {
    v17 = *(_DWORD *)v15;
    v18 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
    if ( (unsigned __int8)(*(int (__thiscall **)(int, signed int, signed int, PixelFormatID, signed int))(v17 + 88))(
                            v16,
                            32,
                            32,
                            v18,
                            1) )
    {
      if ( v11 )
        SurfaceWindow::Blit((SurfaceWindow *)(v16 + 172), &v11->window, 0, 1.0);
      if ( spOverlay.m_object )
        SurfaceWindow::Blit((SurfaceWindow *)(v16 + 172), &spOverlay.m_object->window, Blit_4Alpha, 1.0);
      if ( _weenObj )
      {
        LODWORD(white.r) = 1065353216;
        LODWORD(white.g) = 1065353216;
        LODWORD(white.b) = 1065353216;
        LODWORD(white.a) = 1065353216;
        SurfaceWindow::ReplaceColor(
          (SurfaceWindow *)(v16 + 172),
          &white,
          (SurfaceWindow *)&_weenObj->pwd._iconOverlayID);
      }
      v19 = (Graphic *)operator new(0xCu);
      if ( v19 )
        Graphic::Graphic(v19, (RenderSurface *)v16);
      else
        v20 = 0;
      v2->m_pDragIcon = v20;
      v21 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
      v22 = v21;
      if ( v21 )
      {
        v23 = *(_DWORD *)v21;
        v24 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
        if ( (unsigned __int8)(*(int (__thiscall **)(int, signed int, signed int, PixelFormatID, signed int))(v23 + 88))(
                                v22,
                                32,
                                32,
                                v24,
                                1) )
        {
          if ( spBackground )
            SurfaceWindow::Blit((SurfaceWindow *)(v22 + 172), (SurfaceWindow *)(spBackground + 172), 0, 1.0);
          if ( spUnderlay )
            SurfaceWindow::Blit((SurfaceWindow *)(v22 + 172), (SurfaceWindow *)(spUnderlay + 172), Blit_3Alpha, 1.0);
          SurfaceWindow::Blit((SurfaceWindow *)(v22 + 172), (SurfaceWindow *)(v16 + 172), Blit_3Alpha, 1.0);
          v25 = (Graphic *)operator new(0xCu);
          if ( v25 )
            Graphic::Graphic(v25, (RenderSurface *)v22);
          else
            v26 = 0;
          v2->m_pIcon = v26;
        }
        (*(void (__thiscall **)(int))(*(_DWORD *)v22 + 20))(v22);
        v11 = spIcon.m_object;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 20))(v16);
    v14 = spOverlay.m_object;
  }
  if ( v14 )
    v14->vfptr->Release((Interface *)v14);
  if ( v11 )
    v11->vfptr->Release((Interface *)v11);
  if ( spUnderlay )
    (*(void (**)(void))(*(_DWORD *)spUnderlay + 20))();
  if ( _weenObj )
    ((void (*)(void))_weenObj->vfptr[5].__vecDelDtor)();
  if ( spBackground )
    (*(void (**)(void))(*(_DWORD *)spBackground + 20))();
}

//----- (0058D4A0) --------------------------------------------------------  // acclient.c:438055
int __thiscall PackableList<InventoryPlacement>::Remove(PackableList<InventoryPlacement> *this, InventoryPlacement *val)
{
  PackableList<InventoryPlacement> *v2; // esi@1
  int result; // eax@1
  unsigned int v4; // edi@2
  PackableLLNode<InventoryPlacement> *v5; // ecx@4
  int v6; // edx@11
  int v7; // edx@15
  int v8; // edx@15
  int v9; // ecx@15

  v2 = this;
  result = (int)this->head;
  if ( result )
  {
    v4 = val->iid_;
    if ( *(_DWORD *)(result + 4) != v4 || *(_DWORD *)(result + 8) != val->loc_ )
    {
      if ( *(_DWORD *)(result + 16) )
      {
        while ( 1 )
        {
          v6 = *(_DWORD *)(result + 16);
          if ( *(_DWORD *)(v6 + 4) == v4 && *(_DWORD *)(v6 + 8) == val->loc_ )
            break;
          result = *(_DWORD *)(result + 16);
          if ( !*(_DWORD *)(v6 + 16) )
            goto LABEL_14;
        }
        v7 = *(_DWORD *)(result + 16);
        val->iid_ = *(_DWORD *)(v7 + 4);
        val->loc_ = *(_DWORD *)(v7 + 8);
        val->priority_ = *(_DWORD *)(v7 + 12);
        v8 = *(_DWORD *)(result + 16);
        v9 = *(_DWORD *)(v8 + 16);
        *(_DWORD *)(result + 16) = v9;
        if ( v9 )
          *(_DWORD *)(v9 + 20) = result;
        else
          v2->tail = (PackableLLNode<InventoryPlacement> *)result;
        *(_DWORD *)v8 = &PackObj::vftable;
        operator delete((void *)v8);
        --v2->curNum;
        result = 1;
      }
      else
      {
LABEL_14:
        result = 0;
      }
    }
    else
    {
      val->iid_ = *(_DWORD *)(result + 4);
      val->loc_ = *(_DWORD *)(result + 8);
      val->priority_ = *(_DWORD *)(result + 12);
      v5 = this->head->next;
      v2->head = v5;
      if ( v5 )
        v5->prev = 0;
      else
        v2->tail = 0;
      if ( result )
      {
        *(_DWORD *)result = &PackObj::vftable;
        operator delete((void *)result);
      }
      --v2->curNum;
      result = 1;
    }
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0058D590) --------------------------------------------------------  // acclient.c:438131
void __thiscall ACCWeenieObject::UIAttemptWield(ACCWeenieObject *this, unsigned int _loc)
{
  ACCWeenieObject *v2; // esi@1
  unsigned int v3; // eax@2

  v2 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    v3 = v2->pwd._stackSize;
    if ( v3 && v3 > 1 && GenItemHolder::splitSize != GenItemHolder::maxSplitSize )
    {
      CM_Inventory::Event_StackableSplitToWield(v2->id, _loc, GenItemHolder::splitSize);
    }
    else
    {
      CM_Inventory::Event_GetAndWieldItem(v2->id, _loc);
      ACCWeenieObject::prevRequestObjectID = v2->id;
      ACCWeenieObject::prevRequest = 7;
      *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
    }
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058D620) --------------------------------------------------------  // acclient.c:438159
void __thiscall ACCWeenieObject::UIAttemptGive(ACCWeenieObject *this, unsigned int _targetID, unsigned int _amount)
{
  ACCWeenieObject *v3; // esi@1

  v3 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_GiveObjectRequest(_targetID, v3->id, _amount);
    ACCWeenieObject::prevRequestObjectID = v3->id;
    ACCWeenieObject::prevRequest = 9;
    *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058D680) --------------------------------------------------------  // acclient.c:438178
void __thiscall ACCWeenieObject::UIAttemptPutInContainer(ACCWeenieObject *this, unsigned int _container, int _place)
{
  ACCWeenieObject *v3; // esi@1
  signed int v4; // eax@2

  v3 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_PutItemInContainer(v3->id, _container, _place);
    v4 = v3->current_state;
    if ( v4 )
    {
      if ( v4 > 0 && v4 <= 2 )
        ACCWeenieObject::RecordRequest(v3->id, IR_PUT_IN_CONTAINER);
    }
    else
    {
      ACCWeenieObject::prevRequestObjectID = v3->id;
      ACCWeenieObject::prevRequest = 4;
      *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
    }
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058D700) --------------------------------------------------------  // acclient.c:438207
void __thiscall ACCWeenieObject::UIAttemptPutIn3D(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  signed int v2; // eax@2

  v1 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_DropItem(v1->id);
    v2 = v1->current_state;
    if ( v2 )
    {
      if ( v2 > 0 && v2 <= 2 )
        ACCWeenieObject::RecordRequest(v1->id, IR_DROP);
    }
    else
    {
      ACCWeenieObject::prevRequestObjectID = v1->id;
      ACCWeenieObject::prevRequest = 3;
      *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
    }
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058D770) --------------------------------------------------------  // acclient.c:438236
void __thiscall ACCWeenieObject::UIAttemptMerge(ACCWeenieObject *this, unsigned int _mergeToItem, int _amount)
{
  ACCWeenieObject *v3; // esi@1

  v3 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_StackableMerge(v3->id, _mergeToItem, _amount);
    ACCWeenieObject::prevRequestObjectID = v3->id;
    ACCWeenieObject::prevRequest = 1;
    *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058D7D0) --------------------------------------------------------  // acclient.c:438255
void __thiscall ACCWeenieObject::UIAttemptSplitToContainer(ACCWeenieObject *this, unsigned int _container, int _place, int _amount)
{
  ACCWeenieObject *v4; // esi@1
  int v5; // eax@2

  v4 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_StackableSplitToContainer(v4->id, _container, _place, _amount);
    ACCWeenieObject::prevRequestObjectID = v4->id;
    ACCWeenieObject::prevRequest = 2;
    *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
    v5 = v4->pwd._wcid.id;
    ACCWeenieObject::splitStackSize = _amount;
    ACCWeenieObject::splitClassID = v5;
    *(_QWORD *)&ACCWeenieObject::splitTime = Timer::cur_time;
  }
}
// 870EB4: using guessed type unsigned __int32 ACCWeenieObject::splitStackSize;
// 870EB8: using guessed type double ACCWeenieObject::splitTime;
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;
// 870F78: using guessed type int ACCWeenieObject::splitClassID;

//----- (0058D850) --------------------------------------------------------  // acclient.c:438282
void __thiscall ACCWeenieObject::UIAttemptSplitTo3D(ACCWeenieObject *this, int _amount)
{
  ACCWeenieObject *v2; // esi@1
  int v3; // ecx@2

  v2 = this;
  if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
  {
    CM_Inventory::Event_StackableSplitTo3D(v2->id, _amount);
    ACCWeenieObject::prevRequestObjectID = v2->id;
    ACCWeenieObject::prevRequest = 2;
    *(_QWORD *)&ACCWeenieObject::prevRequestTime = Timer::cur_time;
    v3 = v2->pwd._wcid.id;
    ACCWeenieObject::splitStackSize = _amount;
    ACCWeenieObject::splitClassID = v3;
    *(_QWORD *)&ACCWeenieObject::splitTime = Timer::cur_time;
  }
}
// 870EB4: using guessed type unsigned __int32 ACCWeenieObject::splitStackSize;
// 870EB8: using guessed type double ACCWeenieObject::splitTime;
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;
// 870F78: using guessed type int ACCWeenieObject::splitClassID;

//----- (0058D8C0) --------------------------------------------------------  // acclient.c:438309
void __thiscall ACCWeenieObject::SetPlayerWieldLocation(ACCWeenieObject *this, const unsigned int _newLocation)
{
  ACCWeenieObject *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@1
  unsigned int v4; // ecx@2
  PackableList<InventoryPlacement> *v5; // ebx@3
  unsigned int v6; // edi@4
  unsigned int v7; // eax@4
  CPhysicsObj *v8; // ecx@5
  unsigned int v9; // ecx@8
  unsigned int v10; // edx@8
  InventoryPlacement curIP; // [sp+4h] [bp-10h]@5

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(SmartBox::smartbox->player_id);
  if ( v3 )
  {
    v4 = v3[6].id;
    if ( v4 )
    {
      v5 = (PackableList<InventoryPlacement> *)(v4 + 60);
      if ( v4 != -60 )
      {
        v6 = v2->id;
        v7 = (unsigned int)ACCWeenieObject::GetLocationOnObject((ACCWeenieObject *)v3, v2->id);
        if ( v7 )
        {
          curIP.priority_ = v2->pwd._priority;
          curIP.vfptr = (PackObjVtbl *)&InventoryPlacement::vftable;
          curIP.iid_ = v6;
          curIP.loc_ = v7;
          PackableList<InventoryPlacement>::Remove(v5, &curIP);
          v8 = v2->_phys_obj;
          if ( v8 )
            CPhysicsObj::SetTranslucencyHierarchical(v8, 0.0);
        }
        if ( _newLocation )
        {
          v9 = v2->id;
          v10 = v2->pwd._priority;
          curIP.loc_ = _newLocation;
          curIP.iid_ = v9;
          curIP.vfptr = (PackObjVtbl *)&InventoryPlacement::vftable;
          curIP.priority_ = v10;
          PackableList<InventoryPlacement>::InsertPos(v5, 0, &curIP);
        }
      }
    }
  }
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (0058D980) --------------------------------------------------------  // acclient.c:438362
void __thiscall IconData::IconData(IconData *this, ACCWeenieObject *_weenObj, int _id)
{
  unsigned int v3; // edx@1

  this->hash_next = 0;
  this->id = _id;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&IconData::vftable;
  this->m_idIcon.id = stru_870F0C.id;
  this->m_idCustomOverlay.id = stru_870F0C.id;
  v3 = stru_870F0C.id;
  this->m_itemType = 0;
  this->m_effects = 0;
  this->m_pIcon = 0;
  this->m_pDragIcon = 0;
  this->m_idCustomUnderlay.id = v3;
  IconData::RenderIcons(this, _weenObj);
}
// 7E3F24: using guessed type int (__thiscall *IconData::vftable)(void *, char);

//----- (0058D9D0) --------------------------------------------------------  // acclient.c:438382
int __thiscall IconData::UpdateIcons(IconData *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // esi@1
  IconData *v3; // edi@1
  int result; // eax@6

  v2 = _weenObj;
  v3 = this;
  if ( this->m_idIcon.id == *(_DWORD *)_weenObj->vfptr[25].__vecDelDtor(
                                         (HashBaseData<unsigned long> *)_weenObj,
                                         (unsigned int)&_weenObj)
    && v3->m_idCustomOverlay.id == v2->pwd._iconOverlayID.id
    && v3->m_idCustomUnderlay.id == v2->pwd._iconUnderlayID.id
    && v3->m_itemType == ((int (__thiscall *)(ACCWeenieObject *))v2->vfptr[6].__vecDelDtor)(v2)
    && v3->m_effects == v2->pwd._effects )
  {
    result = 0;
  }
  else
  {
    IconData::RenderIcons(v3, v2);
    result = 1;
  }
  return result;
}

//----- (0058DA40) --------------------------------------------------------  // acclient.c:438409
int __userpurge ACCWeenieObject::CanMoveInto@<eax>(ACCWeenieObject *this@<ecx>, int a2@<ebx>, CWeenieObject *mover)
{
  ACCWeenieObject *v3; // esi@1
  unsigned int v4; // eax@2
  unsigned int v5; // edx@2
  RestrictionDB *v6; // ecx@4
  unsigned int v7; // esi@6
  InterfacePtr<Interface> *v8; // eax@7
  int v9; // ebx@9
  double v10; // st7@12
  int v12; // [sp-4h] [bp-20h]@9
  InterfacePtr<Interface> result; // [sp+8h] [bp-14h]@7
  AC1Legacy::Vector3 v; // [sp+10h] [bp-Ch]@7

  v3 = this;
  if ( !mover )
    return 0;
  v4 = this->pwd._house_owner_iid;
  v5 = mover->id;
  if ( v4 )
  {
    if ( v4 != v5 )
    {
      v6 = this->pwd._db;
      if ( v6 )
      {
        if ( !RestrictionDB::IsAllowedIn(v6, v5, (unsigned int)mover[3].blobOrdering.head_.m_pNext) )
        {
          v7 = v3->pwd._pscript;
          if ( v7 )
          {
            v8 = GetClassObject(&result, &CPlayerModule_ClassType_6);
            InterfacePtr<CPlayerModule>::InterfacePtr<CPlayerModule>((InterfacePtr<CPlayerModule> *)&v, v8);
            if ( (_DWORD)result.m_pInterface )
              ((void (*)(void))result.m_pInterface->vfptr->Release)();
            v12 = a2;
            v9 = (signed int)v.x;
            if ( (_DWORD)v.x )
            {
              if ( !(unsigned __int8)PlayerModule::DisableHouseRestrictionEffects((PlayerModule *)((_DWORD)v.x + 4)) )
              {
                if ( ((int (__thiscall *)(CWeenieObject *, AC1Legacy::Vector3 *, int))mover->vfptr[28].__vecDelDtor)(
                       mover,
                       &v,
                       v12) )
                  v10 = AC1Legacy::Vector3::magnitude((AC1Legacy::Vector3 *)((char *)&v + 4)) * 0.1;
                mover->vfptr[26].__vecDelDtor((HashBaseData<unsigned long> *)mover, v7);
              }
              (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
            }
          }
          return 0;
        }
      }
    }
  }
  return 1;
}
// 58DA40: could not find valid save-restore pair for ebx

//----- (0058DB70) --------------------------------------------------------  // acclient.c:438470
BOOL __cdecl ACCWeenieObject::HasCorpseBeenOpened(const unsigned int corpseID)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v1; // eax@1
  bool v2; // zf@1

  v1 = stru_8206DC.m_buckets[corpseID % stru_8206DC.m_numBuckets];
  v2 = v1 == 0;
  if ( v1 )
  {
    do
    {
      if ( v1->m_hashKey.id == corpseID )
        break;
      v1 = v1->m_hashNext;
    }
    while ( v1 );
    v2 = v1 == 0;
  }
  return !v2;
}

//----- (0058DBB0) --------------------------------------------------------  // acclient.c:438492
void __thiscall ACCWeenieObject::ServerSaysMoveItem(ACCWeenieObject *this, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation, int _broadcast)
{
  ACCWeenieObject *v6; // esi@1
  unsigned int v7; // ebp@1
  HashBaseData<unsigned long> *v8; // eax@2
  HashBaseData<unsigned long> *v9; // eax@5
  unsigned int v10; // eax@7
  int v11; // eax@11
  int v12; // eax@17
  unsigned int oldWielder; // [sp+10h] [bp-8h]@1
  unsigned int oldLocation; // [sp+14h] [bp-4h]@1

  v6 = this;
  v7 = this->pwd._containerID;
  oldWielder = this->pwd._wielderID;
  oldLocation = this->pwd._location;
  if ( v7 )
  {
    v8 = ClientObjMaintSystem::GetWeenieObject(v7);
    if ( v8 )
      ACCWeenieObject::RemoveContent((ACCWeenieObject *)v8, v6);
  }
  v6->pwd._containerID = _newContainer;
  if ( _newContainer )
  {
    v9 = ClientObjMaintSystem::GetWeenieObject(_newContainer);
    if ( v9 )
      ACCWeenieObject::AddContent((ACCWeenieObject *)v9, v6, _place);
  }
  v10 = SmartBox::smartbox->player_id;
  if ( _newWielder == v10 )
  {
    ACCWeenieObject::SetPlayerWieldLocation(v6, _newLocation);
    v6->pwd._wielderID = SmartBox::smartbox->player_id;
  }
  else if ( oldWielder == v10 )
  {
    ACCWeenieObject::SetPlayerWieldLocation(v6, 0);
    v6->pwd._wielderID = 0;
  }
  v11 = v6->beingRemoved;
  v6->pwd._location = _newLocation;
  if ( v11 )
  {
    v6->current_state = 3;
  }
  else if ( v6->pwd._containerID )
  {
    v6->current_state = 2;
  }
  else
  {
    v6->current_state = _newLocation != 0;
  }
  if ( v6->waiting )
  {
    v12 = v6->valid;
    v6->waiting = 0;
    if ( v12 )
      GenItemHolder::ItemAttributesChanged_s(v6->id, 0);
  }
  if ( v6->id == ACCWeenieObject::prevRequestObjectID )
  {
    ACCWeenieObject::prevRequestObjectID = 0;
    ACCWeenieObject::prevRequest = 0;
    LODWORD(ACCWeenieObject::prevRequestTime) = 0;
    dword_870ECC = 0;
  }
  if ( v6->markedForDeletion )
    v6->movedWhileMarkedForDeletion = 1;
  if ( _broadcast )
    GenItemHolder::ServerSaysMoveItem_s(
      v6->id,
      v7,
      oldWielder,
      oldLocation,
      _newContainer,
      _place,
      _newWielder,
      _newLocation);
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0058DD20) --------------------------------------------------------  // acclient.c:438579
void __thiscall ACCWeenieObject::Remove(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edx@1
  unsigned int v4; // edi@2
  HashBaseData<unsigned long> *v5; // eax@3
  IACPlugin *v6; // eax@6

  v1 = this;
  v2 = this->pwd._containerID;
  v3 = this->pwd._location;
  this->preRemoveWielderID = this->pwd._wielderID;
  this->preRemoveContainerID = v2;
  this->preRemoveLocation = v3;
  this->preRemoveContainerPlace = 0;
  this->beingRemoved = 1;
  ACCWeenieObject::ServerSaysMoveItem(this, 0, 0, 0, 0, 1);
  if ( v1->id == ACCWeenieObject::selectedID )
  {
    v4 = ACCWeenieObject::selectedID;
    if ( ACCWeenieObject::selectedID )
    {
      v5 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v5 )
        v5[9].vfptr = 0;
      ACCWeenieObject::selectedID = 0;
      ACCWeenieObject::prevSelectedID = v4;
      ACCWeenieObject::prevSelectedValidID = v4;
      CM_UI::SendNotice_SelectionChanged();
      GenItemHolder::SetSelectedItem_s(v4, ACCWeenieObject::selectedID);
      if ( APIManager::APIIsReady() )
      {
        v6 = APIManager::GetACPlugin();
        ((void (__stdcall *)(IACPlugin *, unsigned int, _Formatted))v6->vfptr[3].AddRef)(
          v6,
          v4,
          ACCWeenieObject::selectedID);
      }
    }
  }
  v1->beingRemoved = 0;
}
// 870E4C: using guessed type unsigned __int32 ACCWeenieObject::prevSelectedValidID;

//----- (0058DDD0) --------------------------------------------------------  // acclient.c:438625
void __thiscall ACCWeenieObject::IconDataChanged(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ecx@1

  v1 = this;
  v2 = this->id;
  v3 = *((_DWORD *)dword_8206C8 + (dword_8206C0 & (v2 ^ (v2 >> dword_8206C4))));
  if ( v3 )
  {
    while ( v2 != *(_DWORD *)(v3 + 8) )
    {
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      if ( IconData::UpdateIcons((IconData *)v3, v1) )
        GenItemHolder::ItemAttributesChanged_s(v1->id, 2);
    }
  }
}
// 8206C0: using guessed type int dword_8206C0;
// 8206C4: using guessed type int dword_8206C4;

//----- (0058DE30) --------------------------------------------------------  // acclient.c:438653
void __thiscall ACCWeenieObject::GetIconData(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  unsigned int v2; // edx@1
  int v3; // eax@1
  IconData *v4; // eax@6
  int v5; // eax@7
  int v6; // edx@9

  v1 = this;
  v2 = this->id;
  v3 = *((_DWORD *)dword_8206C8 + (dword_8206C0 & (v2 ^ (v2 >> dword_8206C4))));
  if ( v3 )
  {
    while ( v2 != *(_DWORD *)(v3 + 8) )
    {
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v3 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = 0;
  }
  if ( !v3 )
  {
    v4 = (IconData *)operator new(0x28u);
    if ( v4 )
      IconData::IconData(v4, v1, v1->id);
    else
      v5 = 0;
    v6 = dword_8206C0 & (*(_DWORD *)(v5 + 8) ^ (*(_DWORD *)(v5 + 8) >> dword_8206C4));
    *(_DWORD *)(v5 + 4) = *((_DWORD *)dword_8206C8 + v6);
    *((_DWORD *)dword_8206C8 + v6) = v5;
  }
}
// 8206C0: using guessed type int dword_8206C0;
// 8206C4: using guessed type int dword_8206C4;

//----- (0058DEC0) --------------------------------------------------------  // acclient.c:438695
void __thiscall ACCWeenieObject::SetType(ACCWeenieObject *this, ITEM_TYPE type)
{
  this->pwd._type = type;
  if ( this->valid )
    ACCWeenieObject::IconDataChanged(this);
}

//----- (0058DEE0) --------------------------------------------------------  // acclient.c:438703
void __thiscall ACCWeenieObject::SetUseability(ACCWeenieObject *this, ITEM_USEABLE useability)
{
  this->pwd._useability = useability;
  if ( this->valid )
    ACCWeenieObject::IconDataChanged(this);
}

//----- (0058DF00) --------------------------------------------------------  // acclient.c:438711
void __thiscall ACCWeenieObject::SetEffects(ACCWeenieObject *this, const unsigned int effects)
{
  this->pwd._effects = effects;
  if ( this->valid )
    ACCWeenieObject::IconDataChanged(this);
}

//----- (0058DF20) --------------------------------------------------------  // acclient.c:438719
void __thiscall ACCWeenieObject::OnStatUpdated(ACCWeenieObject *this, unsigned int stype, int val)
{
  ACCWeenieObject *v3; // esi@1

  v3 = this;
  switch ( stype )
  {
    case 0xCu:
      ACCWeenieObject::SetStackSize(this, val);
      break;
    case 0xBu:
      this->pwd._maxStackSize = val;
      break;
    case 1u:
      ACCWeenieObject::SetType(this, (ITEM_TYPE)val);
      break;
    case 0x10u:
      ACCWeenieObject::SetUseability(this, (ITEM_USEABLE)val);
      break;
    case 0x12u:
      ACCWeenieObject::SetEffects(this, val);
      break;
    case 0x32u:
      this->pwd._ammoType = val;
      break;
    case 0x33u:
      this->pwd._combatUse = val;
      break;
    case 0x5Cu:
      ACCWeenieObject::SetStructure(this, val);
      break;
    case 0x5Bu:
      ACCWeenieObject::SetMaxStructure(this, val);
      break;
    case 9u:
      this->pwd._valid_locations = val;
      break;
    case 4u:
      this->pwd._priority = val;
      break;
    case 0xAu:
      if ( ACCWeenieObject::prevRequestObjectID != this->id && !ACCWeenieObject::IsOwnedByPlayer(this) )
        v3->pwd._location = val;
      break;
    case 7u:
      this->pwd._containersCapacity = val;
      break;
    case 6u:
      this->pwd._itemsCapacity = val;
      break;
    case 0x13u:
      this->pwd._value = val;
      break;
    case 0x97u:
      this->pwd._hook_type = val;
      break;
    case 0x98u:
      this->pwd._hook_item_types = val;
      break;
    case 0x5Fu:
      this->pwd._blipColor = val;
      break;
    case 0x85u:
      this->pwd._radar_enum = val;
      break;
    case 0x86u:
      PublicWeenieDesc::SetPlayerKillerStatus(&this->pwd, val);
      break;
    default:
      return;
  }
}
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;

//----- (0058E180) --------------------------------------------------------  // acclient.c:438794
void __thiscall ACCWeenieObject::OnStatUpdated(ACCWeenieObject *this, unsigned int stype, IDClass<_tagDataID,32,0> id)
{
  switch ( stype )
  {
    case 8u:
      this->pwd._iconID.id = id.id;
      goto LABEL_5;
    case 0x32u:
      this->pwd._iconOverlayID.id = id.id;
      goto LABEL_5;
    case 0x34u:
      this->pwd._iconUnderlayID.id = id.id;
LABEL_5:
      if ( this->valid )
        ACCWeenieObject::IconDataChanged(this);
      break;
    case 0x2Cu:
      this->pwd._pscript = id.id;
      break;
    default:
      return;
  }
}

//----- (0058E220) --------------------------------------------------------  // acclient.c:438819
void __thiscall ACCWeenieObject::OnStatUpdated(ACCWeenieObject *this, unsigned int stype, unsigned int id)
{
  ACCWeenieObject *v3; // esi@1
  unsigned int v4; // eax@4

  v3 = this;
  switch ( stype )
  {
    case 2u:
      if ( ACCWeenieObject::prevRequestObjectID != this->id
        && !ACCWeenieObject::IsOwnedByObject(this, SmartBox::smartbox->player_id) )
      {
        v4 = GetPlayerID();
        if ( id == v4 && v4 )
          ACCWeenieObject::ServerSaysMoveItem(v3, id, 0, 0, 0, 1);
        else
          v3->pwd._containerID = id;
      }
      break;
    case 3u:
      if ( ACCWeenieObject::prevRequestObjectID != this->id
        && !ACCWeenieObject::IsOwnedByObject(this, SmartBox::smartbox->player_id) )
        v3->pwd._wielderID = id;
      break;
    case 0x20u:
      this->pwd._house_owner_iid = id;
      break;
    case 0x1Au:
      this->pwd._monarch = id;
      break;
    case 0x2Cu:
      this->pwd._pet_owner = id;
      break;
    default:
      return;
  }
}
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;

//----- (0058E340) --------------------------------------------------------  // acclient.c:438859
void __thiscall ACCWeenieObject::DeclareValid(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  CObjectInventory *v2; // eax@1
  int v3; // edi@2
  unsigned int v4; // eax@3
  int i; // edi@4
  unsigned int v6; // eax@5
  unsigned int v7; // eax@6
  int v8; // edi@6
  signed int v9; // eax@19
  ACCWeenieObject *v10; // [sp+0h] [bp-4h]@1

  v10 = this;
  v1 = this;
  v2 = this->objInventory;
  this->valid = 1;
  if ( v2 )
  {
    v3 = 0;
    if ( v2->_itemsList.numIDs > 0 )
    {
      do
      {
        v4 = IDList::GetByNum(&v1->objInventory->_itemsList, v3);
        CObjectMaint::RemoveObjectToBeDestroyed(CWeenieObject::objMaint, v4);
        ++v3;
      }
      while ( v3 < v1->objInventory->_itemsList.numIDs );
    }
    for ( i = 0; i < v1->objInventory->_containersList.numIDs; ++i )
    {
      v6 = IDList::GetByNum(&v1->objInventory->_containersList, i);
      CObjectMaint::RemoveObjectToBeDestroyed(CWeenieObject::objMaint, v6);
    }
  }
  v7 = v1->id;
  v8 = *((_DWORD *)dword_8206C8 + (dword_8206C0 & (v7 ^ (v1->id >> dword_8206C4))));
  if ( v8 )
  {
    while ( v7 != *(_DWORD *)(v8 + 8) )
    {
      v8 = *(_DWORD *)(v8 + 4);
      if ( !v8 )
        goto LABEL_17;
    }
    if ( v8
      && (*(_DWORD *)(v8 + 12) != *(_DWORD *)v1->vfptr[25].__vecDelDtor(
                                               (HashBaseData<unsigned long> *)v1,
                                               (unsigned int)&v10)
       || *(_DWORD *)(v8 + 16) != v1->pwd._iconOverlayID.id
       || *(_DWORD *)(v8 + 20) != v1->pwd._iconUnderlayID.id
       || *(_DWORD *)(v8 + 24) != ((int (__thiscall *)(ACCWeenieObject *))v1->vfptr[6].__vecDelDtor)(v1)
       || *(_DWORD *)(v8 + 28) != v1->pwd._effects) )
    {
      IconData::RenderIcons((IconData *)v8, v1);
      GenItemHolder::ItemAttributesChanged_s(v1->id, 2);
    }
  }
LABEL_17:
  GenItemHolder::ItemAttributesChanged_s(v1->id, 1);
  if ( ACCWeenieObject::splitClassID != stru_870F0C.id )
  {
    if ( ACCWeenieObject::splitClassID != v1->pwd._wcid.id )
      goto LABEL_27;
    v9 = v1->pwd._stackSize;
    if ( !v9 )
      v9 = 1;
    if ( ACCWeenieObject::splitStackSize != v9 )
    {
LABEL_27:
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - ACCWeenieObject::splitTime > 10.0 )
        ACCWeenieObject::splitClassID = stru_870F0C.id;
    }
    else
    {
      ACCWeenieObject::SetSelectedObject(v1->id, 0);
      ACCWeenieObject::splitClassID = stru_870F0C.id;
    }
  }
}
// 8206C0: using guessed type int dword_8206C0;
// 8206C4: using guessed type int dword_8206C4;
// 870EB4: using guessed type unsigned __int32 ACCWeenieObject::splitStackSize;
// 870EB8: using guessed type double ACCWeenieObject::splitTime;
// 870F78: using guessed type int ACCWeenieObject::splitClassID;

//----- (0058E4D0) --------------------------------------------------------  // acclient.c:438947
void __thiscall ACCWeenieObject::ObjectBeingDeleted(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  int v2; // eax@1
  int v3; // ebp@1
  CObjectInventory *v4; // eax@4
  unsigned int v5; // edi@6
  HashBaseData<unsigned long> *v6; // ebx@6
  HashBaseData<unsigned long> *v7; // eax@6
  int i; // ebp@12
  unsigned int v9; // edi@13
  HashBaseData<unsigned long> *v10; // ebx@13
  HashBaseData<unsigned long> *v11; // eax@13
  unsigned int v12; // edi@19
  int v13; // edx@19
  int v14; // eax@19
  int v15; // ecx@23
  int v16; // ecx@26
  ACWTimeStamper *v17; // ecx@29

  v1 = this;
  v2 = this->markedForDeletion;
  v3 = 0;
  this->_phys_obj = 0;
  if ( !v2 || this->movedWhileMarkedForDeletion )
    ACCWeenieObject::Remove(this);
  v4 = v1->objInventory;
  if ( v4 )
  {
    if ( v4->_itemsList.numIDs > 0 )
    {
      do
      {
        v5 = IDList::GetByNum(&v1->objInventory->_itemsList, v3);
        v6 = CObjectMaint::GetObjectA(CWeenieObject::objMaint, v5);
        v7 = ClientObjMaintSystem::GetWeenieObject(v5);
        if ( (!v7 || v7[15].vfptr == (HashBaseData<unsigned long>Vtbl *)v1->id) && (!v6 || !v6[12].vfptr) )
          CObjectMaint::AddObjectToBeDestroyed(CWeenieObject::objMaint, v5);
        ++v3;
      }
      while ( v3 < v1->objInventory->_itemsList.numIDs );
    }
    for ( i = 0; i < v1->objInventory->_containersList.numIDs; ++i )
    {
      v9 = IDList::GetByNum(&v1->objInventory->_containersList, i);
      v10 = CObjectMaint::GetObjectA(CWeenieObject::objMaint, v9);
      v11 = ClientObjMaintSystem::GetWeenieObject(v9);
      if ( (!v11 || v11[15].vfptr == (HashBaseData<unsigned long>Vtbl *)v1->id) && (!v10 || !v10[12].vfptr) )
        CObjectMaint::AddObjectToBeDestroyed(CWeenieObject::objMaint, v9);
    }
  }
  v12 = v1->id;
  v13 = dword_8206C0 & (v12 ^ (v1->id >> dword_8206C4));
  v14 = *((_DWORD *)dword_8206C8 + v13);
  if ( v14 )
  {
    if ( *(_DWORD *)(v14 + 8) == v12 )
    {
      *((_DWORD *)dword_8206C8 + v13) = *(_DWORD *)(v14 + 4);
    }
    else
    {
      if ( !*(_DWORD *)(v14 + 4) )
        goto LABEL_29;
      while ( 1 )
      {
        v15 = *(_DWORD *)(v14 + 4);
        if ( *(_DWORD *)(v15 + 8) == v12 )
          break;
        v14 = *(_DWORD *)(v14 + 4);
        if ( !*(_DWORD *)(v15 + 4) )
          goto LABEL_29;
      }
      v16 = *(_DWORD *)(v14 + 4);
      *(_DWORD *)(v14 + 4) = *(_DWORD *)(v16 + 4);
      v14 = v16;
    }
    if ( v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  }
LABEL_29:
  v17 = v1->_stamper;
  if ( v17 )
  {
    ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
    v1->_stamper = 0;
  }
  CWeenieObject::ObjectBeingDeleted((CWeenieObject *)&v1->vfptr);
}
// 8206C0: using guessed type int dword_8206C0;
// 8206C4: using guessed type int dword_8206C4;

//----- (0058E650) --------------------------------------------------------  // acclient.c:439040
Graphic *__thiscall ACCWeenieObject::GetIcon(ACCWeenieObject *this)
{
  int v1; // eax@1

  ACCWeenieObject::GetIconData(this);
  return *(Graphic **)(v1 + 32);
}

//----- (0058E660) --------------------------------------------------------  // acclient.c:439049
Graphic *__thiscall ACCWeenieObject::GetDragIcon(ACCWeenieObject *this)
{
  int v1; // eax@1

  ACCWeenieObject::GetIconData(this);
  return *(Graphic **)(v1 + 36);
}

//----- (0058E670) --------------------------------------------------------  // acclient.c:439058
void __cdecl ACCWeenieObject::SetCorpseOpened(const unsigned int corpseID)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v1; // eax@1

  v1 = stru_8206DC.m_buckets[corpseID % stru_8206DC.m_numBuckets];
  if ( !v1 )
    goto LABEL_9;
  while ( v1->m_hashKey.id != corpseID )
  {
    v1 = v1->m_hashNext;
    if ( !v1 )
    {
      HashSet<unsigned long>::add(&ACCWeenieObject::m_openedCorpses, &corpseID);
      return;
    }
  }
  if ( !v1 )
LABEL_9:
    HashSet<unsigned long>::add(&ACCWeenieObject::m_openedCorpses, &corpseID);
}

//----- (0058E6C0) --------------------------------------------------------  // acclient.c:439080
void __cdecl ACCWeenieObject::SetCorpseDeleted(const unsigned int corpseID)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v1; // eax@1

  v1 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         &stru_8206DC,
         (IDClass<_tagDataID,32,0> *)&corpseID);
  if ( v1 )
    operator delete(v1);
}

//----- (0058E6E0) --------------------------------------------------------  // acclient.c:439092
char *__thiscall ACCWeenieObject::GetObjectName(ACCWeenieObject *this, NameType _nameType, int _playerIsBackpack)
{
  ACCWeenieObject *v3; // esi@1
  NameType v5; // ebx@4
  unsigned int v6; // eax@5
  AC1Legacy::PSRefBuffer<char> *v7; // esi@9
  bool v8; // bl@9
  AC1Legacy::PSRefBuffer<char> *v9; // esi@12
  int v10; // eax@12
  char v11; // cl@13
  LONG (__stdcall *v12)(volatile LONG *); // ebx@14
  AC1Legacy::PSRefBuffer<char> *v13; // esi@18
  int v14; // eax@18
  char v15; // cl@19
  unsigned int v16; // eax@24
  char *v17; // edi@25
  char v18; // al@26
  char v19; // al@28
  AC1Legacy::PSRefBuffer<char> *v20; // esi@31
  unsigned int v21; // edi@31
  const char *v22; // edi@32
  char *v23; // esi@32
  PStringBase<char> v24; // ST0C_4@36
  char *v25; // eax@37
  signed int v26; // edx@37
  char v27; // cl@38
  __int32 v28; // edi@39
  int v29; // edi@42
  ACCWeenieObject *v30; // [sp+14h] [bp-Ch]@1
  PStringBase<char> str; // [sp+18h] [bp-8h]@32
  AC1Legacy::PStringBase<char> name_with_material; // [sp+1Ch] [bp-4h]@31

  v3 = this;
  v30 = this;
  if ( _playerIsBackpack && ((int (*)(void))this->vfptr[5].__vecDelDtor)() )
  {
    byte_870E58 = 0;
    *(_DWORD *)ACCWeenieObject::nameString = *(_DWORD *)"Backpack";
    dword_870E54 = 1801675120;
    return ACCWeenieObject::nameString;
  }
  v5 = _nameType;
  ACCWeenieObject::nameString[0] = 0;
  if ( _nameType == 2 )
  {
    v6 = v3->pwd._stackSize;
    if ( !v6 || v6 <= 1 )
      goto LABEL_18;
    _nameType = 1;
  }
  else if ( _nameType != 1 )
  {
    goto LABEL_18;
  }
  v7 = v3->pwd._plural_name.m_buffer;
  InterlockedIncrement((volatile LONG *)&v7->m_cRef);
  v8 = v7->m_len != 1;
  if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  if ( v8 )
  {
    v9 = v30->pwd._plural_name.m_buffer;
    InterlockedIncrement((volatile LONG *)&v9->m_cRef);
    v10 = (int)v9->m_data;
    do
    {
      v11 = *(_BYTE *)v10;
      *(_BYTE *)(ACCWeenieObject::nameString - v9->m_data + v10) = *(_BYTE *)v10;
      ++v10;
    }
    while ( v11 );
    v12 = InterlockedDecrement;
    if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    goto LABEL_31;
  }
  v5 = _nameType;
  v3 = v30;
LABEL_18:
  v13 = v3->pwd._name.m_buffer;
  InterlockedIncrement((volatile LONG *)&v13->m_cRef);
  v14 = (int)v13->m_data;
  do
  {
    v15 = *(_BYTE *)v14;
    *(_BYTE *)(ACCWeenieObject::nameString - v13->m_data + v14) = *(_BYTE *)v14;
    ++v14;
  }
  while ( v15 );
  if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  if ( v5 == 1 )
  {
    v16 = strlen(ACCWeenieObject::nameString);
    if ( (signed int)v16 <= 0 )
      return ACCWeenieObject::nameString;
    v17 = &ACCWeenieObject::nameString[-1];
    if ( *((_BYTE *)&ACCWeenieObject::prevSelectedValidID + v16 + 3) == 115 )
    {
      do
        v18 = (v17++)[1];
      while ( v18 );
      *(_WORD *)v17 = *(_WORD *)"es";
      v17[2] = 0;
    }
    else
    {
      do
        v19 = (v17++)[1];
      while ( v19 );
      *(_WORD *)v17 = *(_WORD *)"s";
    }
  }
  v12 = InterlockedDecrement;
LABEL_31:
  v20 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  name_with_material.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v21 = v30->pwd._material_type;
  if ( (signed int)v21 > 0 )
  {
    _playerIsBackpack = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_nameType, ACCWeenieObject::nameString);
    AppraisalSystem::InqMaterialName(v21, (PStringBase<char> *)&_playerIsBackpack);
    PStringBase<char>::PStringBase<char>(&str, &name);
    v22 = PStringBase<char>::replace((PStringBase<char> *)&_nameType, (PStringBase<char> *)&_playerIsBackpack, &str);
    v23 = &str.m_charbuffer[-2].m_data[12];
    if ( !v12((volatile LONG *)&str.m_charbuffer[-1]) && v23 )
      (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
    if ( v22 )
    {
      v24.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
      PStringBase<char>::trim((PStringBase<char> *)&_nameType, 1, 1, v24);
    }
    AC1Legacy::PStringBase<char>::sprintf(&name_with_material, "%s %s", _playerIsBackpack, _nameType);
    v20 = name_with_material.m_buffer;
    v25 = name_with_material.m_buffer->m_data;
    v26 = ACCWeenieObject::nameString - name_with_material.m_buffer->m_data;
    do
    {
      v27 = *v25;
      v25[v26] = *v25;
      ++v25;
    }
    while ( v27 );
    v28 = _nameType - 20;
    if ( !v12((volatile LONG *)(_nameType - 20 + 4)) && v28 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
    v29 = _playerIsBackpack - 20;
    if ( !v12((volatile LONG *)(_playerIsBackpack - 20 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
  }
  if ( ACCWeenieObject::nameString[0] != 43 || !(v30->pwd._bitfield & 0x40) )
  {
    if ( !v12((volatile LONG *)&v20->m_cRef) && v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
    return ACCWeenieObject::nameString;
  }
  if ( !v12((volatile LONG *)&v20->m_cRef) )
  {
    if ( v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
  }
  return &ACCWeenieObject::nameString[1];
}
// 870E4C: using guessed type unsigned __int32 ACCWeenieObject::prevSelectedValidID;
// 870E54: using guessed type int dword_870E54;
// 870E58: using guessed type char byte_870E58;
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0058EA10) --------------------------------------------------------  // acclient.c:439265
char *__cdecl ACCWeenieObject::GetObjectName(ACCWeenieObject *this, unsigned int _objID, NameType _nameType)
{
  char *result; // eax@3
  HashBaseData<unsigned long> *v4; // eax@4

  if ( _nameType && this == (ACCWeenieObject *)SmartBox::smartbox->player_id )
  {
    dword_870E54 = 1801675120;
    *(_DWORD *)ACCWeenieObject::nameString = *(_DWORD *)"Backpack";
    byte_870E58 = 0;
    result = ACCWeenieObject::nameString;
  }
  else
  {
    v4 = ClientObjMaintSystem::GetWeenieObject((unsigned int)this);
    if ( v4 )
    {
      result = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v4, (NameType)_objID, 0);
    }
    else
    {
      ACCWeenieObject::nameString[0] = 0;
      result = ACCWeenieObject::nameString;
    }
  }
  return result;
}
// 870E54: using guessed type int dword_870E54;
// 870E58: using guessed type char byte_870E58;

//----- (0058EA80) --------------------------------------------------------  // acclient.c:439296
PStringBase<unsigned short> *__thiscall ACCWeenieObject::GetObjectNameWide(ACCWeenieObject *this, PStringBase<unsigned short> *result, NameType _nameType, int _playerIsBackpack)
{
  const char *v4; // eax@1

  v4 = ACCWeenieObject::GetObjectName(this, _nameType, _playerIsBackpack);
  PStringBase<unsigned short>::PStringBase<unsigned short>(result, 0, v4);
  return result;
}

//----- (0058EAB0) --------------------------------------------------------  // acclient.c:439306
ACCWeenieObject *__cdecl ACCWeenieObject::GetObjectNameWide(ACCWeenieObject *this, PStringBase<unsigned short> *result, unsigned int _objID, NameType _nameType)
{
  char *v4; // eax@1

  v4 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)result, _objID, _nameType);
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)this, 0, v4);
  return this;
}

//----- (0058EAE0) --------------------------------------------------------  // acclient.c:439316
void __thiscall ACCWeenieObject::ServerSaysAttemptFailed(ACCWeenieObject *this, unsigned int _etype, int _printError)
{
  ACCWeenieObject *v3; // esi@1
  int v4; // eax@2
  PStringBase<unsigned short> *v5; // eax@7
  PStringBase<unsigned short> *v6; // ecx@7
  PStringBase<unsigned short> *v7; // eax@8
  PStringBase<unsigned short> *v8; // eax@9
  PStringBase<unsigned short> *v9; // eax@10
  PStringBase<unsigned short> *v10; // eax@11
  PStringBase<unsigned short> *v11; // eax@12
  PStringBase<unsigned short> *v12; // eax@13
  PStringBase<unsigned short> *v13; // eax@14
  PStringBase<unsigned short> *v14; // ecx@21
  int v15; // eax@24
  char *v16; // edi@35
  PStringBase<unsigned short> errorText; // [sp+4h] [bp-B4h]@6
  PStringBase<unsigned short> v18; // [sp+8h] [bp-B0h]@10
  PStringBase<unsigned short> v19; // [sp+Ch] [bp-ACh]@9
  PStringBase<unsigned short> v20; // [sp+10h] [bp-A8h]@8
  PStringBase<unsigned short> v21; // [sp+14h] [bp-A4h]@11
  PStringBase<unsigned short> result; // [sp+18h] [bp-A0h]@7
  PStringBase<unsigned short> v23; // [sp+1Ch] [bp-9Ch]@12
  PStringBase<unsigned short> rhs; // [sp+20h] [bp-98h]@13
  PStringBase<unsigned short> v25; // [sp+24h] [bp-94h]@14
  StringInfo siError; // [sp+28h] [bp-90h]@35

  v3 = this;
  if ( this->waiting )
  {
    v4 = this->valid;
    this->waiting = 0;
    if ( v4 )
      GenItemHolder::ItemAttributesChanged_s(this->id, 0);
  }
  if ( ClientUISystem::GetUISystem() )
  {
    if ( !_printError )
    {
LABEL_38:
      if ( v3->id == ACCWeenieObject::prevRequestObjectID )
      {
        ACCWeenieObject::prevRequestObjectID = 0;
        ACCWeenieObject::prevRequest = 0;
        LODWORD(ACCWeenieObject::prevRequestTime) = 0;
        dword_870ECC = 0;
      }
      GenItemHolder::ServerSaysAttemptFailed_s(v3->id);
      return;
    }
    errorText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    switch ( ACCWeenieObject::prevRequest )
    {
      case 1:
        v5 = ACCWeenieObject::GetObjectNameWide(v3, &result, NAME_PLURAL, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be merged", v5->m_charbuffer);
        v6 = &result;
        goto LABEL_15;
      case 2:
        v7 = ACCWeenieObject::GetObjectNameWide(v3, &v20, NAME_PLURAL, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be split", v7->m_charbuffer);
        v6 = &v20;
        goto LABEL_15;
      case 3:
        v8 = ACCWeenieObject::GetObjectNameWide(v3, &v19, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be moved", v8->m_charbuffer);
        v6 = &v19;
        goto LABEL_15;
      case 4:
        v9 = ACCWeenieObject::GetObjectNameWide(v3, &v18, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be picked up", v9->m_charbuffer);
        v6 = &v18;
        goto LABEL_15;
      case 5:
        v10 = ACCWeenieObject::GetObjectNameWide(v3, &v21, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be put in the container", v10->m_charbuffer);
        v6 = &v21;
        goto LABEL_15;
      case 6:
        v11 = ACCWeenieObject::GetObjectNameWide(v3, &v23, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be dropped", v11->m_charbuffer);
        v6 = &v23;
        goto LABEL_15;
      case 7:
        v12 = ACCWeenieObject::GetObjectNameWide(v3, &rhs, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be wielded", v12->m_charbuffer);
        v6 = &rhs;
        goto LABEL_15;
      case 9:
        v13 = ACCWeenieObject::GetObjectNameWide(v3, &v25, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::sprintf(&errorText, L"The %s can't be given", v13->m_charbuffer);
        v6 = &v25;
LABEL_15:
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v6);
        break;
      default:
        break;
    }
    if ( _etype > 0x2A )
    {
      if ( _etype > 0x39 )
      {
        if ( _etype == 1006 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L" - the container is closed");
          PStringBase<unsigned short>::operator+=(&errorText, &result);
          v14 = &result;
          goto LABEL_34;
        }
      }
      else
      {
        if ( _etype >= 0x37 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, L" - unable to move to object");
          PStringBase<unsigned short>::operator+=(&errorText, &v20);
          v14 = &v20;
          goto LABEL_34;
        }
        if ( _etype == 54 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v19, L" - action cancelled");
          PStringBase<unsigned short>::operator+=(&errorText, &v19);
          v14 = &v19;
          goto LABEL_34;
        }
      }
    }
    else
    {
      if ( _etype == 42 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, L" - you are too encumbered");
        v15 = *(_DWORD *)&v18.m_charbuffer[-1].m_data[14];
        if ( v15 != 1 )
          PStringBase<unsigned short>::append_n_chars(&errorText, v18.m_charbuffer->m_data, v15 - 1);
        v14 = &v18;
        goto LABEL_34;
      }
      if ( _etype == 29 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v21, L" - you're too busy");
        PStringBase<unsigned short>::operator+=(&errorText, &v21);
        v14 = &v21;
        goto LABEL_34;
      }
      if ( _etype == 32 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v23, L" - you must control both objects");
        PStringBase<unsigned short>::operator+=(&errorText, &v23);
        v14 = &v23;
        goto LABEL_34;
      }
      if ( _etype == 40 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L" - the item is under someone else's control");
        PStringBase<unsigned short>::operator+=(&errorText, &rhs);
        v14 = &rhs;
LABEL_34:
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v14);
        goto LABEL_35;
      }
    }
LABEL_35:
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    v16 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    goto LABEL_38;
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;
// 870EC8: using guessed type double ACCWeenieObject::prevRequestTime;
// 870ECC: using guessed type int dword_870ECC;

//----- (0070A790) --------------------------------------------------------  // acclient.c:797679
int sub_70A790()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_33, "Display.Resolution");
  return atexit(_E74_84);
}

//----- (0070A7B0) --------------------------------------------------------  // acclient.c:797686
int _E76_68()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_33, "Display.FullScreen");
  return atexit(_E77_96);
}

//----- (0070A7D0) --------------------------------------------------------  // acclient.c:797693
int _E79_62()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_33, "Display.RefreshRate");
  return atexit(_E80_61);
}

//----- (0070A7F0) --------------------------------------------------------  // acclient.c:797700
int _E82_40()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_33, "Display.SyncToRefresh");
  return atexit(_E83_38);
}

//----- (0070A810) --------------------------------------------------------  // acclient.c:797707
void _E85_28()
{
  dword_870F10 = 1024;
}

//----- (0070A820) --------------------------------------------------------  // acclient.c:797713
void _E87()
{
  dword_870F14 = 0x7FFF;
}

//----- (0070A830) --------------------------------------------------------  // acclient.c:797719
int _E89_9()
{
  const int result; // eax@1

  result = dword_870F10;
  dword_870F18 = dword_870F10;
  return result;
}

//----- (0070A840) --------------------------------------------------------  // acclient.c:797729
void _E107_40()
{
  LODWORD(dword_870F1C) = 1053364187;
}

//----- (0070A850) --------------------------------------------------------  // acclient.c:797735
void _E109_76()
{
  flt_870F20 = 1000.0 + 1.0;
}

//----- (0070A870) --------------------------------------------------------  // acclient.c:797741
void _E111_52()
{
  flt_870F24 = 24.0 * 8.0;
}

//----- (0070A890) --------------------------------------------------------  // acclient.c:797747
void _E113_28()
{
  flt_870F28 = 24.0 * 0.5;
}

//----- (0070A8B0) --------------------------------------------------------  // acclient.c:797753
void _E115_82()
{
  flt_870F2C = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070A8D0) --------------------------------------------------------  // acclient.c:797759
void _E117_76()
{
  dbl_870F30 = 1.0 / 30.0;
}

//----- (0070A8F0) --------------------------------------------------------  // acclient.c:797765
void _E119_29()
{
  dbl_870F38 = 1.0 / 5.0;
}

//----- (0070A910) --------------------------------------------------------  // acclient.c:797771
int _E124_69()
{
  return atexit(_E125_66);
}

//----- (0070A920) --------------------------------------------------------  // acclient.c:797777
int _E127_58()
{
  return atexit(_E128_64);
}

//----- (0070A930) --------------------------------------------------------  // acclient.c:797783
int _E130_52()
{
  return atexit(_E131_54);
}

//----- (0070A940) --------------------------------------------------------  // acclient.c:797789
void _E133_45()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870F40, PFID_A8R8G8B8);
}

//----- (0070A950) --------------------------------------------------------  // acclient.c:797795
int _E136_31()
{
  return atexit(_E137_38);
}

//----- (0070A960) --------------------------------------------------------  // acclient.c:797801
int _E139_31()
{
  void *v0; // eax@1
  signed int v1; // ecx@1
  signed int v2; // eax@1
  unsigned int v3; // eax@3

  v0 = operator new[](0x320u);
  v1 = 1;
  dword_8206C8 = v0;
  dword_8206CC = 200;
  dword_8206C4 = 8;
  v2 = 1;
  do
  {
    v1 *= 2;
    dword_8206C0 = v2;
    v2 |= v1;
  }
  while ( (unsigned int)v2 < 0xC8 );
  v3 = 0;
  do
    *((_DWORD *)dword_8206C8 + v3++) = 0;
  while ( v3 < dword_8206CC );
  ACCWeenieObject::iconDataTable = (int (__thiscall *(*)[2])(void *, char))LongHash<CWeenieObject>::vftable;
  return atexit(_E140_32);
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 8206BC: using guessed type int (__thiscall *(*ACCWeenieObject::iconDataTable)[2])(void *, char);
// 8206C0: using guessed type int dword_8206C0;
// 8206C4: using guessed type int dword_8206C4;
// 8206CC: using guessed type int dword_8206CC;

//----- (0070A9D0) --------------------------------------------------------  // acclient.c:797835
int _E142_28()
{
  ACCWeenieObject::splitClassID = stru_870F0C.id;
  return atexit(_E143_32);
}
// 870F78: using guessed type int ACCWeenieObject::splitClassID;

//----- (0070A9F0) --------------------------------------------------------  // acclient.c:797843
int _E145_30()
{
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(
    (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *)&stru_8206DC,
    0x14u);
  return atexit(_E146_32);
}

//----- (0070AA10) --------------------------------------------------------  // acclient.c:797852
int sub_70AA10()
{
  return atexit(nullsub_1415);
}

//----- (00774A20) --------------------------------------------------------  // acclient.c:908215
void __cdecl _E140_32()
{
  ACCWeenieObject::iconDataTable = (int (__thiscall *(*)[2])(void *, char))LongHash<CWeenieObject>::vftable;
  if ( !dword_8206D0 )
    operator delete[](dword_8206C8);
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 8206BC: using guessed type int (__thiscall *(*ACCWeenieObject::iconDataTable)[2])(void *, char);
// 8206D0: using guessed type int dword_8206D0;

//----- (00774A40) --------------------------------------------------------  // acclient.c:908226
void __cdecl _E74_84()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774A70) --------------------------------------------------------  // acclient.c:908239
void __cdecl _E77_96()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774AA0) --------------------------------------------------------  // acclient.c:908252
void __cdecl _E80_61()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774AD0) --------------------------------------------------------  // acclient.c:908265
void __cdecl _E83_38()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774B00) --------------------------------------------------------  // acclient.c:908278
void __cdecl _E146_32()
{
  ACCWeenieObject::m_openedCorpses.vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_8206DC);
  stru_8206DC.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
  if ( (HashSetData<IDClass<_tagDataID,32,0> > **)stru_8206DC.m_buckets != stru_8206DC.m_aInplaceBuckets )
    operator delete[](stru_8206DC.m_buckets);
  stru_8206DC.m_buckets = 0;
  stru_8206DC.m_firstInterestingBucket = 0;
  stru_8206DC.m_numBuckets = 0;
  stru_8206DC.m_numElements = 0;
}
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);

