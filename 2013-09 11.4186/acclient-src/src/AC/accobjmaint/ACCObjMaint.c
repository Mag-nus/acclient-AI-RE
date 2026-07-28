/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCObjMaint
   Object     : AC\accobjmaint\ACCObjMaint.obj
   Functions  : 113
   Addresses  : 00557660 - 00707D50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00557660) --------------------------------------------------------  // acclient.c:390879
void __stdcall ACCObjectMaint::SetVisualDesc(CPhysicsObj *object, VisualDesc *vdesc)
{
  CPhysicsObj::DoObjDescChangesFromDefault(object, (ObjDesc *)vdesc);
}

//----- (00557680) --------------------------------------------------------  // acclient.c:390885
void __thiscall ACCObjectMaint::SetPlayerVisualDesc(ACCObjectMaint *this, VisualDesc *new_player_vdesc)
{
  ACCObjectMaint *v2; // esi@1
  ObjDesc *v3; // ecx@1
  ObjDesc *v4; // eax@4
  ObjDesc *v5; // eax@5

  v2 = this;
  v3 = this->player_objdesc;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->player_objdesc = 0;
  }
  if ( new_player_vdesc )
  {
    v4 = (ObjDesc *)operator new(0x2Cu);
    if ( v4 )
    {
      ObjDesc::ObjDesc(v4, (ObjDesc *)new_player_vdesc);
      v2->player_objdesc = v5;
      ECM_Character::SendNotice_PlayerObjDescChanged();
    }
    else
    {
      v2->player_objdesc = 0;
      ECM_Character::SendNotice_PlayerObjDescChanged();
    }
  }
}

//----- (005576E0) --------------------------------------------------------  // acclient.c:390917
ObjDesc *__thiscall ACCObjectMaint::GetPlayerVisualDesc(ACCObjectMaint *this)
{
  return this->player_objdesc;
}

//----- (005576F0) --------------------------------------------------------  // acclient.c:390923
int __thiscall ACCObjectMaint::DeleteObject(ACCObjectMaint *this, unsigned int object_id)
{
  CObjectMaint *v2; // edi@1
  IACPlugin *v3; // eax@2

  v2 = (CObjectMaint *)this;
  if ( APIManager::APIIsReady() )
  {
    v3 = APIManager::GetACPlugin();
    ((void (__stdcall *)(IACPlugin *, unsigned int))v3->vfptr[3].QueryInterface)(v3, object_id);
  }
  ACCWeenieObject::SetCorpseDeleted(object_id);
  return CObjectMaint::DeleteObject(v2, object_id);
}

//----- (00557730) --------------------------------------------------------  // acclient.c:390939
void __thiscall ClientObjMaintSystem::~ClientObjMaintSystem(ClientObjMaintSystem *this)
{
  unsigned int v1; // esi@1
  char *v2; // edi@1
  int v3; // ecx@1

  v1 = this != (ClientObjMaintSystem *)8 ? (unsigned int)this : 0;
  v2 = (char *)&this[-1].object_destruction_queue.minAllocatedNodes;
  this[-1].object_destruction_queue.minAllocatedNodes = (int)&ClientObjMaintSystem::vftable;
  this[-1].player_objdesc = (ObjDesc *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientObjMaintSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  v3 = *(this != (ClientObjMaintSystem *)8 ? &this->object_destruction_queue.allocatedNodes : 504);
  *(_DWORD *)v1 = &ACCObjectMaint::vftable;
  *(_DWORD *)(v1 + 4) = &CObjectMaint::vftable;
  if ( v3 )
  {
    (**(void (__stdcall ***)(_DWORD))v3)(1);
    *(_DWORD *)(v1 + 504) = 0;
  }
  CObjectMaint::~CObjectMaint((CObjectMaint *)v1);
  if ( v2 )
  {
    *((_DWORD *)v2 + 1) = &ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler((NoticeHandler *)v2 + 1);
  }
  else
  {
    v0 = (size_t)&ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler(0);
  }
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CBCE4: using guessed type __int32 (__stdcall *ACCObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 7CBD80: using guessed type __int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBDBC: using guessed type __int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005577B0) --------------------------------------------------------  // acclient.c:390978
HashBaseData<unsigned long> *__cdecl ClientObjMaintSystem::GetWeenieObject(unsigned int i_iid)
{
  HashBaseData<unsigned long> *result; // eax@2

  if ( CObjectMaint::s_pcInstance )
    result = CObjectMaint::GetWeenieObject(CObjectMaint::s_pcInstance, i_iid);
  else
    result = 0;
  return result;
}

//----- (005577D0) --------------------------------------------------------  // acclient.c:390990
HashBaseData<unsigned long> *__cdecl ClientObjMaintSystem::GetPhysicsObject(unsigned int i_iid)
{
  HashBaseData<unsigned long> *result; // eax@2

  if ( CObjectMaint::s_pcInstance )
    result = CObjectMaint::GetObjectA(CObjectMaint::s_pcInstance, i_iid);
  else
    result = 0;
  return result;
}

//----- (005577F0) --------------------------------------------------------  // acclient.c:391002
void __thiscall Attribute::Attribute(Attribute *this, Attribute *__that)
{
  this->vfptr = (PackObjVtbl *)&Attribute::vftable;
  this->_level_from_cp = __that->_level_from_cp;
  this->_init_level = __that->_init_level;
  this->_cp_spent = __that->_cp_spent;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);

//----- (00557820) --------------------------------------------------------  // acclient.c:391012
void __thiscall SecondaryAttribute::SecondaryAttribute(SecondaryAttribute *this, SecondaryAttribute *__that)
{
  this->vfptr = (PackObjVtbl *)&Attribute::vftable;
  this->_level_from_cp = __that->_level_from_cp;
  this->_init_level = __that->_init_level;
  this->_cp_spent = __that->_cp_spent;
  this->vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
  this->_current_level = __that->_current_level;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (00557850) --------------------------------------------------------  // acclient.c:391025
int __thiscall ClientObjMaintSystem::Release(ClientObjMaintSystem *this)
{
  char *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@2

  v1 = (char *)&this->vfptr;
  v2 = (char *)&this->m_cTurbineRefCount.m_cRef;
  if ( InterlockedDecrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef) )
  {
    v3 = *(_DWORD *)v2;
    if ( v3 )
      return v3;
  }
  else
  {
    v3 = 0;
  }
  if ( v1 )
    (*(void (__thiscall **)(char *, signed int))(*(_DWORD *)v1 + 32))(v1, 1);
  return v3;
}

//----- (00557880) --------------------------------------------------------  // acclient.c:391049
ACCObjectMaint *__thiscall ACCObjectMaint::scalar_deleting_destructor(ACCObjectMaint *this, unsigned int a2)
{
  ACCObjectMaint *v2; // esi@1
  ObjDesc *v3; // ecx@1

  v2 = this;
  v3 = this->player_objdesc;
  v2->vfptr = (InterfaceVtbl *)&ACCObjectMaint::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->player_objdesc = 0;
  }
  CObjectMaint::~CObjectMaint((CObjectMaint *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CBCE4: using guessed type __int32 (__stdcall *ACCObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

//----- (005578D0) --------------------------------------------------------  // acclient.c:391072
int __thiscall ClientObjMaintSystem::scalar_deleting_destructor(ClientObjMaintSystem *this, char a2)
{
  ClientObjMaintSystem *v2; // esi@1
  int result; // eax@1

  v2 = this;
  ClientObjMaintSystem::~ClientObjMaintSystem(this);
  result = (int)&v2[-1].object_destruction_queue.minAllocatedNodes;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].object_destruction_queue.minAllocatedNodes);
    result = (int)&v2[-1].object_destruction_queue.minAllocatedNodes;
  }
  return result;
}

//----- (00557900) --------------------------------------------------------  // acclient.c:391089
TResult *__thiscall ClientObjMaintSystem::QueryInterface(ClientObjMaintSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S127_15 & 1 )
  {
    v4 = Offsets_1[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientObjMaintSystem_InterfaceType_68;
    _S127_15 |= 1u;
    Offsets_1[0].key = (_GUID *)&ClientObjMaintSystem_InterfaceType_68;
    dword_86FF08 = 0;
    dword_86FF0C = (int)&ClientSystem_InterfaceType_78;
    dword_86FF10 = 0;
    dword_86FF14 = (int)&CObjectMaint_InterfaceType_79;
    dword_86FF18 = 8;
    dword_86FF1C = (int)&stru_7CBCD0;
    dword_86FF20 = 8;
    dword_86FF24 = 0;
    dword_86FF28 = 0;
  }
  v5 = (int)Offsets_1;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 86FF08: using guessed type int dword_86FF08;
// 86FF0C: using guessed type int dword_86FF0C;
// 86FF10: using guessed type int dword_86FF10;
// 86FF14: using guessed type int dword_86FF14;
// 86FF18: using guessed type int dword_86FF18;
// 86FF1C: using guessed type int dword_86FF1C;
// 86FF20: using guessed type int dword_86FF20;
// 86FF24: using guessed type int dword_86FF24;
// 86FF28: using guessed type int dword_86FF28;

//----- (005579F0) --------------------------------------------------------  // acclient.c:391160
TResult *__thiscall ClientObjMaintSystem::QueryInterface(ClientObjMaintSystem *this, TResult *result, Turbine_GUID *a3, void **a4)
{
  return ClientObjMaintSystem::QueryInterface((ClientObjMaintSystem *)((char *)this - 8), result, a3, a4);
}

//----- (00557A00) --------------------------------------------------------  // acclient.c:391166
LONG __thiscall ClientObjMaintSystem::AddRef(ClientObjMaintSystem *this)
{
  return ClientObjMaintSystem::AddRef((ClientCombatSystem *)&this[-1].object_destruction_queue.minAllocatedNodes);
}

//----- (00557A10) --------------------------------------------------------  // acclient.c:391172
int __thiscall ClientObjMaintSystem::Release(ClientObjMaintSystem *this)
{
  return ClientObjMaintSystem::Release((ClientObjMaintSystem *)((char *)this - 8));
}

//----- (00557A20) --------------------------------------------------------  // acclient.c:391178
void __thiscall ACCObjectMaint::SetWeenieDesc(ACCObjectMaint *this, CWeenieObject *wobj, WeenieDesc *wdesc, int _recreated)
{
  CWeenieObject *v4; // esi@1
  int v5; // ebp@1
  CObjectMaint *v6; // ebx@1
  unsigned int v7; // edi@1
  int v8; // ST10_4@1
  HashBaseData<unsigned long> *v9; // eax@9
  int v10; // eax@13
  unsigned int v11; // ecx@19
  unsigned int v12; // [sp-14h] [bp-30h]@17
  int v13; // [sp-10h] [bp-2Ch]@17
  unsigned int v14; // [sp-Ch] [bp-28h]@17
  unsigned int v15; // [sp-8h] [bp-24h]@17
  unsigned int newWielderID; // [sp+10h] [bp-Ch]@1
  unsigned int oldWielderID; // [sp+14h] [bp-8h]@1
  unsigned int oldLocation; // [sp+18h] [bp-4h]@1
  unsigned int wobja; // [sp+20h] [bp+4h]@1
  unsigned int newContainerID; // [sp+24h] [bp+8h]@1

  v4 = wobj;
  v5 = *((_DWORD *)&wobj[2].12 + 2);
  v6 = (CObjectMaint *)this;
  oldWielderID = LODWORD(wobj[2].update_time);
  oldLocation = *((_DWORD *)&wobj[2].netblob_list + 1);
  v7 = wobj->id;
  wobja = (unsigned int)wdesc[7].vfptr;
  newWielderID = (unsigned int)wdesc[8].vfptr;
  v8 = (int)wdesc;
  newContainerID = (unsigned int)wdesc[11].vfptr;
  PublicWeenieDesc::operator=((int)&v4[1].blobOrdering.blockedSince_, v8);
  ACCWeenieObject::DeterminePositionState((ACCWeenieObject *)v4);
  v4[1].vfptr = (HashBaseData<unsigned long>Vtbl *)CObjectMaint::GetObjectInventory(v6, v7);
  if ( _recreated )
  {
    if ( v4[1].id )
    {
      v4[1].id = 0;
    }
    else if ( v5 != wobja || oldWielderID != newWielderID || oldLocation != newContainerID )
    {
      Proto_UI::SendForceObjdesc(v7);
      v4[1].id = 1;
      *((_DWORD *)&v4[2].12 + 2) = v5;
      LODWORD(v4[2].update_time) = oldWielderID;
      *((_DWORD *)&v4[2].netblob_list + 1) = oldLocation;
    }
  }
  if ( wobja )
  {
    v9 = CObjectMaint::GetWeenieObject(v6, wobja);
    if ( !v9
      || (!((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v4[3].m_handlers)
       && !v4[2].blobOrdering.receivedFirstEntry_
       && v4[2].blobOrdering.mode_ == TSRECV_BLOCK ? (v10 = ACCWeenieObject::GetPlaceInItemsList(
                                                              (ACCWeenieObject *)v9,
                                                              v7)) : (v10 = ACCWeenieObject::GetPlaceInContainersList(
                                                                              (ACCWeenieObject *)v9,
                                                                              v7)),
          v10 == -1) )
      v10 = 0;
    v15 = 0;
    v14 = 0;
    v13 = v10;
    v12 = wobja;
    goto LABEL_28;
  }
  if ( SmartBox::smartbox )
    v11 = SmartBox::smartbox->player_id;
  else
    v11 = 0;
  if ( v11 == LODWORD(v4[2].update_time) && SmartBox::smartbox && SmartBox::smartbox->player_id )
  {
    v15 = newContainerID;
    v14 = newWielderID;
LABEL_27:
    v13 = 0;
    v12 = 0;
LABEL_28:
    ACCWeenieObject::ServerSaysMoveItem((ACCWeenieObject *)v4, v12, v13, v14, v15, 1);
    goto LABEL_29;
  }
  if ( _recreated )
  {
    v15 = newContainerID;
    v14 = newWielderID;
    goto LABEL_27;
  }
LABEL_29:
  ACCWeenieObject::DeclareValid((ACCWeenieObject *)v4);
}

//----- (00557BA0) --------------------------------------------------------  // acclient.c:391271
char __thiscall ClientObjMaintSystem::UpdateStackSize(ClientObjMaintSystem *this, char ts, unsigned int item, unsigned int amount, unsigned int newValue)
{
  HashBaseData<unsigned long> *v5; // eax@2
  HashBaseData<unsigned long> *v6; // esi@2
  char result; // al@7

  if ( item
    && (v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)&this->vfptr, item), (v6 = v5) != 0)
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, 0x1000Cu, ts) != 0 )
  {
    if ( v6[21].vfptr >= (HashBaseData<unsigned long>Vtbl *)amount )
      ACCWeenieObject::ServerSaysSetStackSize((ACCWeenieObject *)v6, amount, newValue);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00557C10) --------------------------------------------------------  // acclient.c:391294
int __thiscall PackableList<InventoryPlacement>::InsertTail(PackableList<InventoryPlacement> *this, InventoryPlacement *val)
{
  PackableList<InventoryPlacement> *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@5
  PackableLLNode<InventoryPlacement> *v5; // ecx@6

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &InventoryPlacement::vftable;
    *((_DWORD *)v3 + 1) = val->iid_;
    *((_DWORD *)v3 + 2) = val->loc_;
    *((_DWORD *)v3 + 3) = val->priority_;
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v5 = v2->tail;
    v5->next = (PackableLLNode<InventoryPlacement> *)v3;
    *((_DWORD *)v3 + 5) = v5;
    v2->tail = (PackableLLNode<InventoryPlacement> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  else
  {
    v2->head = (PackableLLNode<InventoryPlacement> *)v3;
    v2->tail = (PackableLLNode<InventoryPlacement> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  return result;
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (00557C80) --------------------------------------------------------  // acclient.c:391337
int __thiscall ClientObjMaintSystem::UpdateStat<Attribute_QualityType,Attribute const &>(int this, unsigned int stype, char new_ts, unsigned int object_id, Attribute *val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x80000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetAttribute(v7, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Attribute_StatType, stype);
  }
  return 0;
}

//----- (00557D00) --------------------------------------------------------  // acclient.c:391359
int __thiscall ClientObjMaintSystem::UpdateStat<Attribute_QualityType,unsigned long>(int this, unsigned int stype, char new_ts, unsigned int object_id, unsigned int init_val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x80000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetAttribute(v7, stype, init_val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, init_val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Attribute_StatType, stype);
  }
  return 0;
}

//----- (00557D80) --------------------------------------------------------  // acclient.c:391382
int __thiscall ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,SecondaryAttribute const &>(int this, unsigned int stype, char new_ts, unsigned int object_id, SecondaryAttribute *val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x90000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetAttribute2nd(v7, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Attribute_2nd_StatType, stype);
  }
  return 0;
}

//----- (00557E00) --------------------------------------------------------  // acclient.c:391404
int __thiscall ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,unsigned long>(int this, unsigned int stype, char new_ts, unsigned int object_id, unsigned int val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x90000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetAttribute2nd(v7, stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Attribute_2nd_StatType, stype);
  }
  return 0;
}

//----- (00557E80) --------------------------------------------------------  // acclient.c:391427
int __thiscall ClientObjMaintSystem::UpdateStat<Skill_QualityType,Skill const &>(int this, unsigned int stype, char new_ts, unsigned int object_id, Skill *val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x40000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetSkill(v7, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Skill_StatType, stype);
  }
  return 0;
}

//----- (00557F00) --------------------------------------------------------  // acclient.c:391449
int __thiscall ClientObjMaintSystem::UpdateStat<Skill_QualityType,unsigned long>(int this, unsigned int stype, char new_ts, unsigned int object_id, unsigned int val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x40000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetSkillLevel(v7, stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Skill_StatType, stype);
  }
  return 0;
}

//----- (00557F80) --------------------------------------------------------  // acclient.c:391472
int __thiscall ClientObjMaintSystem::UpdateStat<Skill_QualityType,enum  SKILL_ADVANCEMENT_CLASS>(int this, unsigned int stype, char new_ts, unsigned int object_id, SKILL_ADVANCEMENT_CLASS val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  CACQualities *v7; // ecx@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x40000, new_ts) != 0 )
  {
    v7 = (CACQualities *)v6[27].id;
    if ( v7 )
      CACQualities::SetSkillAdvancementClass(v7, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Skill_StatType, stype);
  }
  return 0;
}

//----- (00558000) --------------------------------------------------------  // acclient.c:391494
int __thiscall ClientObjMaintSystem::UpdateStat<Int_QualityType,long>(int this, unsigned int stype, char new_ts, unsigned int object_id, int val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x10000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetInt((CBaseQualities *)(v7 + 56), stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Int_StatType, stype);
  }
  return 0;
}

//----- (00558090) --------------------------------------------------------  // acclient.c:391517
int __thiscall ClientObjMaintSystem::UpdateStat<Int64_QualityType,__int64>(int this, unsigned int stype, char new_ts, unsigned int object_id, __int64 val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0xE0000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetInt64((CBaseQualities *)(v7 + 56), stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Int64_StatType, stype);
  }
  return 0;
}

//----- (00558110) --------------------------------------------------------  // acclient.c:391539
int __thiscall ClientObjMaintSystem::UpdateStat<Bool_QualityType,int>(int this, unsigned int stype, char new_ts, unsigned int object_id, int val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0xD0000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetBool((CBaseQualities *)(v7 + 56), stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Bool_StatType, stype);
  }
  return 0;
}

//----- (005581A0) --------------------------------------------------------  // acclient.c:391562
int __thiscall ClientObjMaintSystem::UpdateStat<Float_QualityType,double>(int this, unsigned int stype, char new_ts, unsigned int object_id, long double val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x20000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetFloat((CBaseQualities *)(v7 + 56), stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Float_StatType, stype);
  }
  return 0;
}

//----- (00558220) --------------------------------------------------------  // acclient.c:391584
int __thiscall ClientObjMaintSystem::UpdateStat<String_QualityType,::PStringBase<char> const &,signed char,::PStringBase<char> const &,__segment,egacy>(int this, unsigned int stype, char new_ts, unsigned int object_id, AC1Legacy::PStringBase<char> *val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4
  AC1Legacy::PSRefBuffer<char> *v8; // edi@6

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x50000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetString((CBaseQualities *)(v7 + 56), stype, val);
    v8 = val->m_buffer;
    InterlockedIncrement((volatile LONG *)&val->m_buffer->m_cRef);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, String_StatType, stype);
  }
  return 0;
}

//----- (005582D0) --------------------------------------------------------  // acclient.c:391611
int __thiscall ClientObjMaintSystem::UpdateStat<DataID_QualityType,IDClass<_tagDataID,32,0>>(int this, unsigned int stype, char new_ts, unsigned int object_id, IDClass<_tagDataID,32,0> val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x60000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetDataID((CBaseQualities *)(v7 + 56), stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, DataID_StatType, stype);
  }
  return 0;
}

//----- (00558360) --------------------------------------------------------  // acclient.c:391634
int __thiscall ClientObjMaintSystem::UpdateStat<InstanceID_QualityType,unsigned long>(int this, unsigned int stype, char new_ts, unsigned int object_id, unsigned int val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x70000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetInstanceID((CBaseQualities *)(v7 + 56), stype, val);
    ACCWeenieObject::OnStatUpdated((ACCWeenieObject *)v6, stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, InstanceID_StatType, stype);
  }
  return 0;
}

//----- (005583F0) --------------------------------------------------------  // acclient.c:391657
int __thiscall ClientObjMaintSystem::UpdateStat<Position_QualityType,Position const &>(int this, unsigned int stype, char new_ts, unsigned int object_id, Position *val)
{
  HashBaseData<unsigned long> *v5; // eax@1
  HashBaseData<unsigned long> *v6; // esi@1
  unsigned int v7; // eax@4

  v5 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v6 = v5;
  if ( v5
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v5)
    && WTimeStamper::UpdateTS((WTimeStamper *)v6[27].hash_next, stype | 0x30000, new_ts) != 0 )
  {
    v7 = v6[27].id;
    if ( v7 )
      CBaseQualities::SetPosition((CBaseQualities *)(v7 + 56), stype, val);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallChangeHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v6, Position_StatType, stype);
  }
  return 0;
}

//----- (00558470) --------------------------------------------------------  // acclient.c:391679
int __thiscall ClientObjMaintSystem::RemoveStat<Int_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x10000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveInt((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, Int_StatType, stype);
  }
  return 0;
}

//----- (005584F0) --------------------------------------------------------  // acclient.c:391701
int __thiscall ClientObjMaintSystem::RemoveStat<Int64_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0xE0000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveInt64((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, Int64_StatType, stype);
  }
  return 0;
}

//----- (00558570) --------------------------------------------------------  // acclient.c:391723
int __thiscall ClientObjMaintSystem::RemoveStat<Bool_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0xD0000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveBool((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, Bool_StatType, stype);
  }
  return 0;
}

//----- (005585F0) --------------------------------------------------------  // acclient.c:391745
int __thiscall ClientObjMaintSystem::RemoveStat<Float_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x20000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveFloat((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, Float_StatType, stype);
  }
  return 0;
}

//----- (00558670) --------------------------------------------------------  // acclient.c:391767
int __thiscall ClientObjMaintSystem::RemoveStat<String_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x50000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveString((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, String_StatType, stype);
  }
  return 0;
}

//----- (005586F0) --------------------------------------------------------  // acclient.c:391789
int __thiscall ClientObjMaintSystem::RemoveStat<DataID_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x60000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveDataID((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, DataID_StatType, stype);
  }
  return 0;
}

//----- (00558770) --------------------------------------------------------  // acclient.c:391811
int __thiscall ClientObjMaintSystem::RemoveStat<InstanceID_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x70000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemoveInstanceID((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, InstanceID_StatType, stype);
  }
  return 0;
}

//----- (005587F0) --------------------------------------------------------  // acclient.c:391833
int __thiscall ClientObjMaintSystem::RemoveStat<Position_QualityType>(int this, unsigned int stype, char new_ts, unsigned int object_id)
{
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // esi@1
  unsigned int v6; // eax@4

  v4 = CObjectMaint::GetWeenieObject((CObjectMaint *)(this + 8), object_id);
  v5 = v4;
  if ( v4
    && ACCWeenieObject::SetupStamper((ACCWeenieObject *)v4)
    && WTimeStamper::UpdateTS((WTimeStamper *)v5[27].hash_next, stype | 0x30000, new_ts) != 0 )
  {
    v6 = v5[27].id;
    if ( v6 )
      CBaseQualities::RemovePosition((CBaseQualities *)(v6 + 56), stype);
    if ( QualityRegistrar::s_pQR )
      QualityRegistrar::CallRemoveHandler(QualityRegistrar::s_pQR, (CWeenieObject *)v5, Position_StatType, stype);
  }
  return 0;
}

//----- (00558870) --------------------------------------------------------  // acclient.c:391855
unsigned int __thiscall ACCObjectMaint::CreateObject(ACCObjectMaint *this, unsigned int objectID, VisualDesc *vdesc, PhysicsDesc *physicsdesc, WeenieDesc *wdesc)
{
  unsigned int v5; // ebp@1
  ACCObjectMaint *v6; // esi@1
  HashBaseData<unsigned long> *v7; // eax@1
  HashBaseData<unsigned long> *v8; // eax@4
  unsigned int v9; // edi@7
  IDClass<_tagDataID,32,0> *v10; // eax@8
  unsigned int result; // eax@10
  IDClass<_tagDataID,32,0> *v12; // eax@13
  HashBaseData<unsigned long> *v13; // eax@14
  int v14; // ebx@14
  unsigned int v15; // eax@16
  unsigned int v16; // eax@27
  unsigned int v17; // eax@28

  v5 = objectID;
  v6 = this;
  v7 = this->object_table.buckets[this->object_table.table_mask & (objectID ^ (objectID >> this->object_table.key_shift))];
  if ( v7 )
  {
    while ( objectID != v7->id )
    {
      v7 = v7->hash_next;
      if ( !v7 )
        goto LABEL_4;
    }
    result = 0;
  }
  else
  {
LABEL_4:
    v8 = this->weenie_object_table.buckets[this->weenie_object_table.table_mask & (objectID ^ (objectID >> this->weenie_object_table.key_shift))];
    if ( v8 )
    {
      while ( objectID != v8->id )
      {
        v8 = v8->hash_next;
        if ( !v8 )
          goto LABEL_7;
      }
      result = 0;
    }
    else
    {
LABEL_7:
      v9 = (unsigned int)CObjectMaint::GetNullObject((CObjectMaint *)&this->vfptr, objectID, 0);
      if ( v9 )
      {
        v10 = PhysicsDesc::get_setup_id(physicsdesc, (IDClass<_tagDataID,32,0> *)&objectID);
        if ( CPhysicsObj::InitNullObject((CPhysicsObj *)v9, (IDClass<_tagDataID,32,0>)v10->id) )
        {
          HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v6->null_object_table.vfptr, *(_DWORD *)(v9 + 8));
          CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&v6->vfptr, *(_DWORD *)(v9 + 8));
        }
        else
        {
          CObjectMaint::DeleteObject((CObjectMaint *)&v6->vfptr, (CPhysicsObj *)v9);
          v9 = 0;
        }
      }
      else
      {
        v12 = PhysicsDesc::get_setup_id(physicsdesc, (IDClass<_tagDataID,32,0> *)&objectID);
        v9 = (unsigned int)CPhysicsObj::makeObject((IDClass<_tagDataID,32,0>)v12->id, v5, 1);
      }
      v13 = CObjectMaint::GetNullWeenieObject((CObjectMaint *)&v6->vfptr, v5, 0);
      v14 = (int)v13;
      if ( v13 )
      {
        HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v6->null_weenie_object_table.vfptr, v13->id);
        CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&v6->vfptr, *(_DWORD *)(v14 + 8));
        if ( SmartBox::smartbox )
          v15 = SmartBox::smartbox->player_id;
        else
          v15 = 0;
        if ( v15 == v5 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 128))(v14);
      }
      else
      {
        v14 = CFactory::MakeCWeenieObject(v5);
      }
      if ( v14 )
      {
        CObjectMaint::AddWeenieObject((CObjectMaint *)&v6->vfptr, (CWeenieObject *)v14);
        ((void (__thiscall *)(ACCObjectMaint *, int, WeenieDesc *, _DWORD))v6->vfptr[1].AddRef)(v6, v14, wdesc, 0);
      }
      if ( v9 )
      {
        if ( v14 )
        {
          CPhysicsObj::set_weenie_obj_ptr((CPhysicsObj *)v9, (CWeenieObject *)v14);
          Client::SetPortA((PlayerModule *)v14, v9);
        }
        if ( CPhysicsObj::set_description((CPhysicsObj *)v9, physicsdesc, 1) )
        {
          CPhysicsObj::DoObjDescChanges((CPhysicsObj *)v9, (ObjDesc *)vdesc);
          CObjectMaint::SetChildren((CObjectMaint *)&v6->vfptr, (CPhysicsObj *)v9, physicsdesc);
          v16 = PhysicsDesc::get_parent_id(physicsdesc);
          if ( v16 )
          {
            objectID = (unsigned int)CObjectMaint::GetObjectA((CObjectMaint *)&v6->vfptr, v16);
            v17 = PhysicsDesc::get_parent_location_id((ACCharGenResult *)physicsdesc);
            CPhysicsObj::set_parent((CPhysicsObj *)v9, (CPhysicsObj *)objectID, v17);
          }
          CObjectMaint::AddObject((CObjectMaint *)&v6->vfptr, (CPhysicsObj *)v9);
        }
      }
      if ( v14 )
        ECM_Physics::SendNotice_CreateObject(v5);
      result = v9;
    }
  }
  return result;
}

//----- (00558A70) --------------------------------------------------------  // acclient.c:391973
void __thiscall ACCObjectMaint::ViewObjectContents(ACCObjectMaint *this, unsigned int object_id, PackableList<ContentProfile> *new_contents)
{
  ACCObjectMaint *v3; // edi@1
  HashBaseData<unsigned long> *v4; // esi@1
  CObjectInventory *v5; // eax@2
  HashBaseData<unsigned long> *v6; // eax@3
  int v7; // eax@5
  HashBaseData<unsigned long> *v8; // eax@5
  IDList *v9; // edi@7
  IDList *v10; // ebx@7
  PackableLLNode<ContentProfile> *i; // esi@7

  v3 = this;
  v4 = CObjectMaint::GetObjectInventory((CObjectMaint *)&this->vfptr, object_id);
  if ( !v4 )
  {
    v5 = (CObjectInventory *)operator new(0x4Cu);
    if ( v5 )
    {
      CObjectInventory::CObjectInventory(v5, object_id);
      v4 = v6;
    }
    else
    {
      v4 = 0;
    }
    v7 = v3->object_inventory_table.table_mask & (v4->id ^ (v4->id >> v3->object_inventory_table.key_shift));
    v4->hash_next = v3->object_inventory_table.buckets[v7];
    v3->object_inventory_table.buckets[v7] = v4;
    v8 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->vfptr, object_id);
    if ( v8 )
      v8[6].id = (unsigned int)v4;
  }
  v9 = (IDList *)&v4[1];
  IDList::Clear((IDList *)&v4[1]);
  v10 = (IDList *)&v4[3];
  IDList::Clear((IDList *)&v4[3]);
  for ( i = new_contents->head; i; i = i->next )
  {
    if ( i->data.m_uContainerProperties )
      IDList::Add(v10, i->data.m_iid);
    else
      IDList::Add(v9, i->data.m_iid);
  }
}

//----- (00558B30) --------------------------------------------------------  // acclient.c:392020
void __thiscall ACCObjectMaint::StopViewingObjectContents(ACCObjectMaint *this, unsigned int object_id)
{
  ACCObjectMaint *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // eax@3

  v2 = this;
  v3 = CObjectMaint::GetWeenieObject((CObjectMaint *)&this->vfptr, object_id);
  if ( v3 )
    v3[6].id = 0;
  v4 = HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v2->object_inventory_table.vfptr, object_id);
  if ( v4 )
    v4->vfptr->__vecDelDtor(v4, 1u);
}

//----- (00558B70) --------------------------------------------------------  // acclient.c:392036
void __thiscall ClientObjMaintSystem::ClientObjMaintSystem(ClientObjMaintSystem *this)
{
  int v1; // esi@1
  char *v2; // edi@1
  Interface *v3; // edi@1
  Interface *v4; // ST08_4@1
  InterfaceSystem *v5; // eax@1
  int v6; // [sp+8h] [bp-10h]@1
  TResult tr; // [sp+Ch] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+10h] [bp-8h]@1

  v1 = (int)this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v2 = (char *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&ClientSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  CObjectMaint::CObjectMaint((CObjectMaint *)&this->vfptr);
  *(_DWORD *)v2 = &ACCObjectMaint::vftable;
  *((_DWORD *)v2 + 1) = &CObjectMaint::vftable;
  *((_DWORD *)v2 + 126) = 0;
  *(_DWORD *)v1 = &ClientObjMaintSystem::vftable;
  *(_DWORD *)(v1 + 4) = &ClientHousingSystem::vftable;
  *(_DWORD *)v2 = &ClientObjMaintSystem::vftable;
  *(_DWORD *)(v1 + 12) = &CObjectMaint::vftable;
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&v6, v1);
  v3 = spcIFace.m_pInterface;
  v4 = spcIFace.m_pInterface;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::RegisterClassA(v5, &tr, &ClientObjMaintSystem_ClassType_1, v4, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CBCE4: using guessed type __int32 (__stdcall *ACCObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 7CBD80: using guessed type __int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBDBC: using guessed type __int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBDE8: using guessed type __int32 (__stdcall *ClientSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00558C20) --------------------------------------------------------  // acclient.c:392078
void __thiscall ClientObjMaintSystem::OnShutdown(ClientObjMaintSystem *this)
{
  ClientObjMaintSystem *v1; // esi@1
  Interface *v2; // edi@1
  Interface *v3; // ST08_4@1
  InterfaceSystem *v4; // eax@1
  TResult result; // [sp+8h] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+Ch] [bp-8h]@1

  v1 = this;
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&result, (int)this);
  v2 = spcIFace.m_pInterface;
  v3 = spcIFace.m_pInterface;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::UnregisterClassA(v4, &result, &ClientObjMaintSystem_ClassType_1, v3, 0);
  CObjectMaint::OnShutdown((CObjectMaint *)&v1->vfptr);
  if ( v2 )
    v2->vfptr->Release(v2);
}

//----- (00558C80) --------------------------------------------------------  // acclient.c:392101
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateAttribute(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, Attribute *val)
{
  return ClientObjMaintSystem::UpdateStat<Attribute_QualityType,Attribute const &>((int)this, stype, wts, sender, val);
}

//----- (00558CA0) --------------------------------------------------------  // acclient.c:392107
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateAttributeLevel(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, int val)
{
  return ClientObjMaintSystem::UpdateStat<Attribute_QualityType,unsigned long>((int)this, stype, wts, sender, val);
}

//----- (00558CC0) --------------------------------------------------------  // acclient.c:392113
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateAttribute2nd(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, SecondaryAttribute *val)
{
  return ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,SecondaryAttribute const &>(
           (int)this,
           stype,
           wts,
           sender,
           val);
}

//----- (00558CE0) --------------------------------------------------------  // acclient.c:392124
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateAttribute2ndLevel(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, int val)
{
  return ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,unsigned long>((int)this, stype, wts, sender, val);
}

//----- (00558D00) --------------------------------------------------------  // acclient.c:392130
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateSkill(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, Skill *val)
{
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,Skill const &>((int)this, stype, wts, sender, val);
}

//----- (00558D20) --------------------------------------------------------  // acclient.c:392136
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateSkillLevel(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, int val)
{
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,unsigned long>((int)this, stype, wts, sender, val);
}

//----- (00558D40) --------------------------------------------------------  // acclient.c:392142
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateSkillAC(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, SKILL_ADVANCEMENT_CLASS val)
{
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,enum  SKILL_ADVANCEMENT_CLASS>(
           (int)this,
           stype,
           wts,
           sender,
           val);
}

//----- (00558D60) --------------------------------------------------------  // acclient.c:392153
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateInt(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, int val)
{
  return ClientObjMaintSystem::UpdateStat<Int_QualityType,long>((int)this, stype, wts, sender, val);
}

//----- (00558D80) --------------------------------------------------------  // acclient.c:392159
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateInt64(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, __int64 val)
{
  return ClientObjMaintSystem::UpdateStat<Int64_QualityType,__int64>((int)this, stype, wts, sender, val);
}

//----- (00558DB0) --------------------------------------------------------  // acclient.c:392165
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateBool(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, int val)
{
  return ClientObjMaintSystem::UpdateStat<Bool_QualityType,int>((int)this, stype, wts, sender, val);
}

//----- (00558DD0) --------------------------------------------------------  // acclient.c:392171
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateFloat(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, long double val)
{
  return ClientObjMaintSystem::UpdateStat<Float_QualityType,double>((int)this, stype, wts, sender, val);
}

//----- (00558E00) --------------------------------------------------------  // acclient.c:392177
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateString(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, AC1Legacy::PStringBase<char> *val)
{
  return ClientObjMaintSystem::UpdateStat<String_QualityType,::PStringBase<char> const &,signed char,::PStringBase<char> const &,__segment,egacy>(
           (int)this,
           stype,
           wts,
           sender,
           val);
}

//----- (00558E20) --------------------------------------------------------  // acclient.c:392188
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateDataID(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, IDClass<_tagDataID,32,0> val)
{
  return ClientObjMaintSystem::UpdateStat<DataID_QualityType,IDClass<_tagDataID,32,0>>(
           (int)this,
           stype,
           wts,
           sender,
           val);
}

//----- (00558E40) --------------------------------------------------------  // acclient.c:392199
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdateInstanceID(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, unsigned int val)
{
  return ClientObjMaintSystem::UpdateStat<InstanceID_QualityType,unsigned long>((int)this, stype, wts, sender, val);
}

//----- (00558E60) --------------------------------------------------------  // acclient.c:392205
int __thiscall ClientObjMaintSystem::Handle_Qualities__UpdatePosition(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype, Position *val)
{
  return ClientObjMaintSystem::UpdateStat<Position_QualityType,Position const &>((int)this, stype, wts, sender, val);
}

//----- (00558E80) --------------------------------------------------------  // acclient.c:392211
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute(ClientObjMaintSystem *this, char wts, unsigned int stype, Attribute *val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Attribute_QualityType,Attribute const &>((int)this, stype, wts, v4, val);
}

//----- (00558EB0) --------------------------------------------------------  // acclient.c:392223
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttributeLevel(ClientObjMaintSystem *this, char wts, unsigned int stype, int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Attribute_QualityType,unsigned long>((int)this, stype, wts, v4, val);
}

//----- (00558EE0) --------------------------------------------------------  // acclient.c:392235
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute2nd(ClientObjMaintSystem *this, char wts, unsigned int stype, SecondaryAttribute *val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,SecondaryAttribute const &>(
           (int)this,
           stype,
           wts,
           v4,
           val);
}

//----- (00558F10) --------------------------------------------------------  // acclient.c:392252
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute2ndLevel(ClientObjMaintSystem *this, char wts, unsigned int stype, int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Attribute_2nd_QualityType,unsigned long>((int)this, stype, wts, v4, val);
}

//----- (00558F40) --------------------------------------------------------  // acclient.c:392264
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkill(ClientObjMaintSystem *this, char wts, unsigned int stype, Skill *val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,Skill const &>((int)this, stype, wts, v4, val);
}

//----- (00558F70) --------------------------------------------------------  // acclient.c:392276
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkillLevel(ClientObjMaintSystem *this, char wts, unsigned int stype, int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,unsigned long>((int)this, stype, wts, v4, val);
}

//----- (00558FA0) --------------------------------------------------------  // acclient.c:392288
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkillAC(ClientObjMaintSystem *this, char wts, unsigned int stype, SKILL_ADVANCEMENT_CLASS val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Skill_QualityType,enum  SKILL_ADVANCEMENT_CLASS>(
           (int)this,
           stype,
           wts,
           v4,
           val);
}

//----- (00558FD0) --------------------------------------------------------  // acclient.c:392305
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInt(ClientObjMaintSystem *this, char wts, unsigned int stype, int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Int_QualityType,long>((int)this, stype, wts, v4, val);
}

//----- (00559000) --------------------------------------------------------  // acclient.c:392317
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInt64(ClientObjMaintSystem *this, char wts, unsigned int stype, __int64 val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Int64_QualityType,__int64>((int)this, stype, wts, v4, val);
}

//----- (00559030) --------------------------------------------------------  // acclient.c:392329
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateBool(ClientObjMaintSystem *this, char wts, unsigned int stype, int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Bool_QualityType,int>((int)this, stype, wts, v4, val);
}

//----- (00559060) --------------------------------------------------------  // acclient.c:392341
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateFloat(ClientObjMaintSystem *this, char wts, unsigned int stype, long double val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Float_QualityType,double>((int)this, stype, wts, v4, val);
}

//----- (00559090) --------------------------------------------------------  // acclient.c:392353
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateString(ClientObjMaintSystem *this, char wts, unsigned int stype, AC1Legacy::PStringBase<char> *val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<String_QualityType,::PStringBase<char> const &,signed char,::PStringBase<char> const &,__segment,egacy>(
           (int)this,
           stype,
           wts,
           v4,
           val);
}

//----- (005590C0) --------------------------------------------------------  // acclient.c:392370
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateDataID(ClientObjMaintSystem *this, char wts, unsigned int stype, IDClass<_tagDataID,32,0> val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<DataID_QualityType,IDClass<_tagDataID,32,0>>((int)this, stype, wts, v4, val);
}

//----- (005590F0) --------------------------------------------------------  // acclient.c:392382
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInstanceID(ClientObjMaintSystem *this, char wts, unsigned int stype, unsigned int val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<InstanceID_QualityType,unsigned long>((int)this, stype, wts, v4, val);
}

//----- (00559120) --------------------------------------------------------  // acclient.c:392394
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateUpdatePosition(ClientObjMaintSystem *this, char wts, unsigned int stype, Position *val)
{
  unsigned int v4; // eax@2

  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  return ClientObjMaintSystem::UpdateStat<Position_QualityType,Position const &>((int)this, stype, wts, v4, val);
}

//----- (00559150) --------------------------------------------------------  // acclient.c:392406
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveIntEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<Int_QualityType>((int)this, stype, wts, sender);
}

//----- (00559170) --------------------------------------------------------  // acclient.c:392412
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveInt64Event(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<Int64_QualityType>((int)this, stype, wts, sender);
}

//----- (00559190) --------------------------------------------------------  // acclient.c:392418
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveBoolEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<Bool_QualityType>((int)this, stype, wts, sender);
}

//----- (005591B0) --------------------------------------------------------  // acclient.c:392424
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveFloatEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<Float_QualityType>((int)this, stype, wts, sender);
}

//----- (005591D0) --------------------------------------------------------  // acclient.c:392430
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveStringEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<String_QualityType>((int)this, stype, wts, sender);
}

//----- (005591F0) --------------------------------------------------------  // acclient.c:392436
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveDataIDEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<DataID_QualityType>((int)this, stype, wts, sender);
}

//----- (00559210) --------------------------------------------------------  // acclient.c:392442
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemoveInstanceIDEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<InstanceID_QualityType>((int)this, stype, wts, sender);
}

//----- (00559230) --------------------------------------------------------  // acclient.c:392448
int __thiscall ClientObjMaintSystem::Handle_Qualities__RemovePositionEvent(ClientObjMaintSystem *this, char wts, unsigned int sender, unsigned int stype)
{
  return ClientObjMaintSystem::RemoveStat<Position_QualityType>((int)this, stype, wts, sender);
}

//----- (00559250) --------------------------------------------------------  // acclient.c:392454
void __thiscall ClientObjMaintSystem::OnShutdown(ClientObjMaintSystem *this)
{
  ClientObjMaintSystem::OnShutdown((ClientObjMaintSystem *)((char *)this - 8));
}

//----- (00559260) --------------------------------------------------------  // acclient.c:392460
void __cdecl ClientObjMaintSystem::Allocate()
{
  ClientObjMaintSystem *v0; // eax@1

  v0 = (ClientObjMaintSystem *)operator new(0x204u);
  if ( v0 )
    ClientObjMaintSystem::ClientObjMaintSystem(v0);
}

//----- (00559280) --------------------------------------------------------  // acclient.c:392470
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveIntEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<Int_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<Int_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (005592C0) --------------------------------------------------------  // acclient.c:392482
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveInt64Event(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<Int64_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<Int64_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559300) --------------------------------------------------------  // acclient.c:392494
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveBoolEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<Bool_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<Bool_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559340) --------------------------------------------------------  // acclient.c:392506
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveFloatEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<Float_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<Float_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559380) --------------------------------------------------------  // acclient.c:392518
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveStringEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<String_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<String_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (005593C0) --------------------------------------------------------  // acclient.c:392530
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveDataIDEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<DataID_QualityType>((int)this, stype, wts, SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<DataID_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559400) --------------------------------------------------------  // acclient.c:392542
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemoveInstanceIDEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<InstanceID_QualityType>(
               (int)this,
               stype,
               wts,
               SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<InstanceID_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559440) --------------------------------------------------------  // acclient.c:392558
int __thiscall ClientObjMaintSystem::Handle_Qualities__PrivateRemovePositionEvent(ClientObjMaintSystem *this, char wts, unsigned int stype)
{
  int result; // eax@2

  if ( SmartBox::smartbox )
    result = ClientObjMaintSystem::RemoveStat<Position_QualityType>(
               (int)this,
               stype,
               wts,
               SmartBox::smartbox->player_id);
  else
    result = ClientObjMaintSystem::RemoveStat<Position_QualityType>((int)this, stype, wts, 0);
  return result;
}

//----- (00559480) --------------------------------------------------------  // acclient.c:392574
void __thiscall PackableList<InventoryPlacement>::Flush(PackableList<InventoryPlacement> *this)
{
  PackableList<InventoryPlacement> *v1; // esi@1
  PackableLLNode<InventoryPlacement> *v2; // ecx@2
  PackableLLNode<InventoryPlacement> *v3; // eax@3

  v1 = this;
  while ( v1->head )
  {
    v2 = v1->head;
    if ( v2 )
    {
      v3 = v2->next;
      v1->head = v3;
      if ( v3 )
        v3->prev = 0;
      else
        v1->tail = 0;
      if ( v2 )
      {
        v2->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
        operator delete(v2);
      }
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005594D0) --------------------------------------------------------  // acclient.c:392604
PackableList<InventoryPlacement> *__thiscall PackableList<InventoryPlacement>::operator=(PackableList<InventoryPlacement> *this, int a2)
{
  PackableList<InventoryPlacement> *v2; // edi@1
  int i; // esi@1
  void *v4; // eax@2
  PackableLLNode<InventoryPlacement> *v5; // ecx@7
  int v6; // ecx@8

  v2 = this;
  PackableList<InventoryPlacement>::Flush(this);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 16) )
  {
    v4 = operator new(0x18u);
    if ( v4 )
    {
      *(_DWORD *)v4 = &InventoryPlacement::vftable;
      *((_DWORD *)v4 + 1) = *(_DWORD *)(i + 4);
      *((_DWORD *)v4 + 2) = *(_DWORD *)(i + 8);
      *((_DWORD *)v4 + 3) = *(_DWORD *)(i + 12);
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 5) = 0;
    }
    else
    {
      v4 = 0;
    }
    if ( v2->head )
    {
      v5 = v2->tail;
      v5->next = (PackableLLNode<InventoryPlacement> *)v4;
      *((_DWORD *)v4 + 5) = v5;
    }
    else
    {
      v2->head = (PackableLLNode<InventoryPlacement> *)v4;
    }
    v6 = v2->curNum + 1;
    v2->tail = (PackableLLNode<InventoryPlacement> *)v4;
    v2->curNum = v6;
    if ( !i )
      break;
  }
  return v2;
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (00559550) --------------------------------------------------------  // acclient.c:392651
void __thiscall ACCObjectMaint::UpdateObjectInventory(ACCObjectMaint *this, unsigned int object_id, PackableList<InventoryPlacement> *new_inv)
{
  HashBaseData<unsigned long> *v3; // eax@1

  v3 = CObjectMaint::GetObjectInventory((CObjectMaint *)&this->vfptr, object_id);
  PackableList<InventoryPlacement>::operator=((PackableList<InventoryPlacement> *)&v3[5], (int)new_inv);
}

//----- (00707C10) --------------------------------------------------------  // acclient.c:794972
void sub_707C10()
{
  flt_86FF50 = 1000.0 + 1.0;
}

//----- (00707C30) --------------------------------------------------------  // acclient.c:794978
void sub_707C30()
{
  flt_86FF54 = 24.0 * 8.0;
}

//----- (00707C50) --------------------------------------------------------  // acclient.c:794984
void sub_707C50()
{
  flt_86FF58 = 24.0 * 0.5;
}

//----- (00707C70) --------------------------------------------------------  // acclient.c:794990
int sub_707C70()
{
  return atexit(nullsub_1296);
}

//----- (00707C80) --------------------------------------------------------  // acclient.c:794996
int sub_707C80()
{
  return atexit(nullsub_1297);
}

//----- (00707C90) --------------------------------------------------------  // acclient.c:795002
int sub_707C90()
{
  return atexit(nullsub_1298);
}

//----- (00707CA0) --------------------------------------------------------  // acclient.c:795008
void sub_707CA0()
{
  flt_86FF5C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00707CC0) --------------------------------------------------------  // acclient.c:795014
void _E108_84()
{
  dbl_86FF60 = 1.0 / 30.0;
}

//----- (00707CE0) --------------------------------------------------------  // acclient.c:795020
void _E110_66()
{
  dbl_86FF68 = 1.0 / 5.0;
}

//----- (00707D00) --------------------------------------------------------  // acclient.c:795026
void _E112_97()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86FF70, PFID_A8R8G8B8);
}

//----- (00707D10) --------------------------------------------------------  // acclient.c:795032
void _E114_58()
{
  dword_86FFA8 = 1024;
}

//----- (00707D20) --------------------------------------------------------  // acclient.c:795038
void _E116_22()
{
  dword_86FFAC = 0x7FFF;
}

//----- (00707D30) --------------------------------------------------------  // acclient.c:795044
int _E118_72()
{
  const int result; // eax@1

  result = dword_86FFA8;
  dword_86FFB0 = dword_86FFA8;
  return result;
}

//----- (00707D40) --------------------------------------------------------  // acclient.c:795054
int _E124_63()
{
  return atexit(_E125_61);
}

//----- (00707D50) --------------------------------------------------------  // acclient.c:795060
int sub_707D50()
{
  return atexit(nullsub_1295);
}

