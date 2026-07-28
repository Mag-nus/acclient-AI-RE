/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TradeSystem
   Object     : AC\accui_misc\TradeSystem.obj
   Functions  : 44
   Addresses  : 00508970 - 00709310 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00508970) --------------------------------------------------------  // acclient.c:310186
LONG __thiscall ClientMagicSystem::AddRef(ClientTradeSystem *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0056D900) --------------------------------------------------------  // acclient.c:410112
ClientTradeSystem *__cdecl ClientTradeSystem::GetTradeSystem()
{
  return ClientTradeSystem::s_pTradeSystem;
}
// 87073C: using guessed type struct ClientTradeSystem *ClientTradeSystem::s_pTradeSystem;

//----- (0056D910) --------------------------------------------------------  // acclient.c:410119
void ClientTradeSystem::OnShutdown()
{
  if ( ClientTradeSystem::s_pTradeSystem )
  {
    ((void (*)(void))ClientTradeSystem::s_pTradeSystem->vfptr->Release)();
    ClientTradeSystem::s_pTradeSystem = 0;
  }
}
// 87073C: using guessed type struct ClientTradeSystem *ClientTradeSystem::s_pTradeSystem;

//----- (0056D930) --------------------------------------------------------  // acclient.c:410130
unsigned int __stdcall ClientTradeSystem::Handle_Trade__Recv_OpenTrade(unsigned int source)
{
  CM_Trade::SendNotice_OpenTrade(source);
  return 0;
}

//----- (0056D950) --------------------------------------------------------  // acclient.c:410137
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_ResetTrade(ClientTradeSystem *this, unsigned int source)
{
  ClientTradeSystem *v2; // esi@1
  IACPlugin *v3; // eax@2

  v2 = this;
  CM_Trade::SendNotice_ResetTrade(source);
  if ( APIManager::APIIsReady() )
  {
    v3 = APIManager::GetACPlugin();
    v3->vfptr[6].AddRef((IUnknown *)v3);
  }
  Trade::Reset(v2->m_pTrade);
  return 0;
}

//----- (0056D990) --------------------------------------------------------  // acclient.c:410154
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_TradeFailure(ClientTradeSystem *this, unsigned int i_iidItem, unsigned int etype)
{
  Trade::RemoveItem(this->m_pTrade, i_iidItem, 1u);
  CM_Trade::SendNotice_TradeFailure(i_iidItem, etype);
  return 0;
}

//----- (0056D9C0) --------------------------------------------------------  // acclient.c:410162
unsigned int ClientTradeSystem::Handle_Trade__Recv_ClearTradeAcceptance()
{
  CM_Trade::SendNotice_ClearTradeAcceptance();
  return 0;
}

//----- (0056D9D0) --------------------------------------------------------  // acclient.c:410169
void __stdcall ClientTradeSystem::AddItemToSelfTradeList(unsigned int i_iidItem, int i_nPos)
{
  CM_Trade::Event_AddToTrade(i_iidItem, i_nPos);
}

//----- (0056D9F0) --------------------------------------------------------  // acclient.c:410175
void __thiscall ClientTradeSystem::AcceptTrade(ClientTradeSystem *this)
{
  this->m_pTrade->_accepted = 1;
  CM_Trade::Event_AcceptTrade(this->m_pTrade);
}

//----- (0056DA10) --------------------------------------------------------  // acclient.c:410182
void __thiscall ClientTradeSystem::DeclineTrade(ClientTradeSystem *this)
{
  this->m_pTrade->_accepted = 0;
  CM_Trade::Event_DeclineTrade();
}

//----- (0056DA40) --------------------------------------------------------  // acclient.c:410189
unsigned int __thiscall ClientTradeSystem::GetNumSelfObjectsInTrade(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = Trade::GetNumContainers(this->m_pTrade);
  return v2 + Trade::GetNumItems(v1->m_pTrade);
}

//----- (0056DA60) --------------------------------------------------------  // acclient.c:410200
unsigned int __thiscall ClientTradeSystem::GetNumPartnerObjectsInTrade(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = Trade::GetNumPartnerContainers(this->m_pTrade);
  return v2 + Trade::GetNumPartnerItems(v1->m_pTrade);
}

//----- (0056DA80) --------------------------------------------------------  // acclient.c:410211
bool __thiscall ClientTradeSystem::IsPartnerTradingItem(ClientTradeSystem *this, unsigned int i_iidItem)
{
  return Trade::IsPartnerTradingItem(this->m_pTrade, i_iidItem) != 0;
}

//----- (0056DAA0) --------------------------------------------------------  // acclient.c:410217
void __thiscall ClientTradeSystem::OnEndCharacterSession(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  Trade *v2; // ecx@1
  Trade *v3; // eax@3
  Trade *v4; // eax@4

  v1 = this;
  v2 = this->m_pTrade;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->m_pTrade = 0;
  v1->m_iidTradeInitiator = 0;
  v1->m_iidTradePartner = 0;
  v1->attemptTradeToPlayerID = 0;
  v1->attemptTradeObjectID = 0;
  v3 = (Trade *)operator new(0x40u);
  if ( v3 )
  {
    Trade::Trade(v3);
    v1->m_pTrade = v4;
  }
  else
  {
    v1->m_pTrade = 0;
  }
}

//----- (0056DAF0) --------------------------------------------------------  // acclient.c:410246
void __thiscall ClientTradeSystem::~ClientTradeSystem(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  Trade *v2; // ecx@1

  v1 = this;
  v2 = this->m_pTrade;
  v1->vfptr = (InterfaceVtbl *)&ClientTradeSystem::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->m_pTrade = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CFCEC: using guessed type __int32 (__stdcall *ClientTradeSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0056DB30) --------------------------------------------------------  // acclient.c:410267
TResult *__thiscall ClientTradeSystem::QueryInterface(ClientTradeSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S127_18 & 1 )
  {
    v4 = Offsets_9[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientTradeSystem_InterfaceType_60;
    _S127_18 |= 1u;
    Offsets_9[0].key = (_GUID *)&ClientTradeSystem_InterfaceType_60;
    dword_8707C8 = 0;
    dword_8707CC = (int)&ClientSystem_InterfaceType_88;
    dword_8707D0 = 0;
    dword_8707D4 = (int)&stru_7CFCD8;
    dword_8707D8 = 0;
    dword_8707DC = 0;
    dword_8707E0 = 0;
  }
  v5 = (int)Offsets_9;
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
// 8707C8: using guessed type int dword_8707C8;
// 8707CC: using guessed type int dword_8707CC;
// 8707D0: using guessed type int dword_8707D0;
// 8707D4: using guessed type int dword_8707D4;
// 8707D8: using guessed type int dword_8707D8;
// 8707DC: using guessed type int dword_8707DC;
// 8707E0: using guessed type int dword_8707E0;

//----- (0056DC00) --------------------------------------------------------  // acclient.c:410334
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_RemoveFromTrade(ClientTradeSystem *this, unsigned int i_iidItem, unsigned int id)
{
  if ( id == 1 )
  {
    Trade::RemoveItem(this->m_pTrade, i_iidItem, 1u);
  }
  else if ( id == 2 )
  {
    Trade::RemoveItem(this->m_pTrade, i_iidItem, 2u);
  }
  CM_Trade::SendNotice_RemoveItemFromTrade(i_iidItem, id);
  return 0;
}

//----- (0056DC40) --------------------------------------------------------  // acclient.c:410349
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_AcceptTrade(ClientTradeSystem *this, unsigned int source)
{
  unsigned int v2; // eax@4
  unsigned int v3; // eax@11
  IACPlugin *v4; // eax@15
  IACPlugin *v6; // eax@17

  if ( source )
  {
    if ( SmartBox::smartbox )
      v2 = SmartBox::smartbox->player_id;
    else
      v2 = 0;
    if ( source == v2 )
      this->m_pTrade->_accepted = 1;
    else
      this->m_pTrade->_p_accepted = 1;
  }
  else
  {
    this->m_pTrade->_accepted = 0;
  }
  CM_Trade::SendNotice_AcceptTrade(source);
  if ( source )
  {
    if ( SmartBox::smartbox )
      v3 = SmartBox::smartbox->player_id;
    else
      v3 = 0;
    if ( source == v3 )
    {
      if ( APIManager::APIIsReady() )
      {
        v6 = APIManager::GetACPlugin();
        ((void (__stdcall *)(IACPlugin *, signed int))v6->vfptr[5].Release)(v6, 1);
      }
    }
    else if ( APIManager::APIIsReady() )
    {
      v4 = APIManager::GetACPlugin();
      ((void (__stdcall *)(IACPlugin *, signed int))v4->vfptr[5].Release)(v4, 2);
      return 0;
    }
  }
  return 0;
}

//----- (0056DCE0) --------------------------------------------------------  // acclient.c:410397
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_DeclineTrade(ClientTradeSystem *this, unsigned int source)
{
  unsigned int v2; // eax@2
  IACPlugin *v3; // eax@9
  IACPlugin *v5; // eax@11

  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  if ( source == v2 )
    this->m_pTrade->_accepted = 0;
  else
    this->m_pTrade->_p_accepted = 0;
  CM_Trade::SendNotice_DeclineTrade(source);
  if ( source == SmartBox::smartbox->player_id )
  {
    if ( APIManager::APIIsReady() )
    {
      v5 = APIManager::GetACPlugin();
      ((void (__stdcall *)(IACPlugin *, signed int))v5->vfptr[6].QueryInterface)(v5, 1);
    }
  }
  else if ( APIManager::APIIsReady() )
  {
    v3 = APIManager::GetACPlugin();
    ((void (__stdcall *)(IACPlugin *, signed int))v3->vfptr[6].QueryInterface)(v3, 2);
    return 0;
  }
  return 0;
}

//----- (0056DD60) --------------------------------------------------------  // acclient.c:410430
void __thiscall ClientTradeSystem::ClientTradeSystem(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  Trade *v2; // eax@1
  Trade *v3; // eax@2

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientTradeSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  ClientTradeSystem::s_pTradeSystem = this;
  InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
  v1->m_iidTradeInitiator = 0;
  v1->m_iidTradePartner = 0;
  v1->attemptTradeToPlayerID = 0;
  v1->attemptTradeObjectID = 0;
  v2 = (Trade *)operator new(0x40u);
  if ( v2 )
  {
    Trade::Trade(v2);
    v1->m_pTrade = v3;
  }
  else
  {
    v1->m_pTrade = 0;
  }
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CFCEC: using guessed type __int32 (__stdcall *ClientTradeSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 87073C: using guessed type struct ClientTradeSystem *ClientTradeSystem::s_pTradeSystem;

//----- (0056DDD0) --------------------------------------------------------  // acclient.c:410465
int __thiscall ClientTradeSystem::GetItemLocationInPartnerTradeList(ClientTradeSystem *this, unsigned int i_iidItem)
{
  PackableLLNode<ContentProfile> *v2; // ecx@1
  int result; // eax@1

  v2 = this->m_pTrade->_partner_list.head;
  result = 0;
  if ( v2 )
  {
    while ( v2->data.m_iid != i_iidItem )
    {
      v2 = v2->next;
      ++result;
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0056DE00) --------------------------------------------------------  // acclient.c:410491
unsigned int __thiscall ClientTradeSystem::Release(ClientTradeSystem *this)
{
  ClientTradeSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientTradeSystem::~ClientTradeSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (0056DE30) --------------------------------------------------------  // acclient.c:410507
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_CloseTrade(ClientTradeSystem *this, unsigned int etype)
{
  ClientTradeSystem *v2; // edi@1
  unsigned int v3; // eax@1
  char *v4; // esi@1
  IACPlugin *v5; // eax@5
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  v3 = _wcslen(L"The trade has been cancelled.");
  PStringBase<unsigned short>::allocate_ref_buffer(&i_text, v3);
  _wcscpy(i_text.m_charbuffer->m_data, L"The trade has been cancelled.");
  ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, &i_text, 0x1Au, 1, 0);
  v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  CM_Trade::SendNotice_CloseTrade(etype);
  if ( APIManager::APIIsReady() )
  {
    v5 = APIManager::GetACPlugin();
    v5->vfptr[5].AddRef((IUnknown *)v5);
  }
  Trade::Reset(v2->m_pTrade);
  v2->m_iidTradeInitiator = 0;
  v2->m_iidTradePartner = 0;
  return 0;
}

//----- (0056DEE0) --------------------------------------------------------  // acclient.c:410537
char __stdcall ClientTradeSystem::AttemptToOpenTradeNegotiations(unsigned int i_iidPlayer)
{
  char *v2; // esi@2
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@2
  StringInfo siError; // [sp+4h] [bp-90h]@2

  if ( ClientCombatSystem::GetCombatSystem()->combatMode != 1 )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You need to be in peace mode to trade.");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v2 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  if ( !i_iidPlayer )
    return 0;
  CM_Trade::Event_OpenTradeNegotiations(i_iidPlayer);
  return 1;
}

//----- (0056DF80) --------------------------------------------------------  // acclient.c:410565
void __thiscall ClientTradeSystem::AttemptToTradeItem(ClientTradeSystem *this, unsigned int idPlayer, unsigned int idObject)
{
  ClientTradeSystem *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1
  unsigned int v5; // eax@3
  PStringBase<unsigned short> _value; // [sp+8h] [bp-94h]@6
  StringInfo siError; // [sp+Ch] [bp-90h]@6

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(idObject);
  if ( v4 && ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    v5 = v3->m_iidTradePartner;
    if ( v5 )
    {
      if ( v5 == idPlayer )
      {
        CM_Trade::SendNotice_TradeAnItemForDummies(idObject);
      }
      else
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You are already trading with someone else.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    else
    {
      ItemHolder::UseObject(idPlayer, 0, 0);
      v3->attemptTradeToPlayerID = idPlayer;
      v3->attemptTradeObjectID = idObject;
    }
  }
}

//----- (0056E050) --------------------------------------------------------  // acclient.c:410604
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_RegisterTrade(ClientTradeSystem *this, unsigned int initiator, unsigned int partner, long double stamp)
{
  ClientTradeSystem *v4; // esi@1
  Trade *v5; // ecx@1
  unsigned int v6; // eax@3
  IACPlugin *v7; // eax@9
  unsigned int v8; // eax@10

  v4 = this;
  v5 = this->m_pTrade;
  v4->m_iidTradeInitiator = initiator;
  v4->m_iidTradePartner = partner;
  if ( v5 )
  {
    Trade::Register(v5, partner, stamp);
    if ( SmartBox::smartbox )
      v6 = SmartBox::smartbox->player_id;
    else
      v6 = 0;
    v4->m_pTrade->_initiator = initiator == v6;
    CM_Trade::SendNotice_RegisterTrade(initiator, partner, stamp);
    if ( APIManager::APIIsReady() )
    {
      v7 = APIManager::GetACPlugin();
      ((void (__stdcall *)(IACPlugin *, unsigned int))v7->vfptr[4].Release)(v7, partner);
    }
    v8 = v4->attemptTradeToPlayerID;
    if ( v4->m_iidTradePartner == v8 )
      ClientTradeSystem::AttemptToTradeItem(v4, v8, v4->attemptTradeObjectID);
    v4->attemptTradeObjectID = 0;
    v4->attemptTradeToPlayerID = 0;
  }
  return 0;
}

//----- (0056E100) --------------------------------------------------------  // acclient.c:410640
char __thiscall ClientTradeSystem::AddPartnerItem(ClientTradeSystem *this, unsigned int itemID, unsigned int pos)
{
  unsigned int v3; // ebx@1
  HashBaseData<unsigned long> *v4; // ebp@1
  InterfaceSystem *v5; // eax@1
  unsigned int v6; // edi@1
  ClientObjMaintSystem *v7; // edi@5
  int v9; // [sp-8h] [bp-2Ch]@1
  ClientTradeSystem *v10; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v12; // [sp+18h] [bp-Ch]@3
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+1Ch] [bp-8h]@1

  v3 = itemID;
  v10 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(itemID);
  itemID = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, &result, &ClientObjMaintSystem_ClassType_5, (Interface **)&itemID);
  v9 = itemID;
  v6 = itemID;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( itemID )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)itemID + 16))(itemID);
  itemID = *(_DWORD *)InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v12, v9, 0);
  if ( v6 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v6 + 20))(v6);
  v7 = spObjMaint.m_pInterface;
  if ( !(_DWORD)spObjMaint.m_pInterface )
    return 0;
  if ( (itemID & 0x80000000) != 0 || (Trade::AddItem(v10->m_pTrade, v3, 2u, pos), !v4) )
  {
    v7->vfptr->Release((Interface *)v7);
    return 0;
  }
  ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v4);
  CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&v7->vfptr, v3);
  v7->vfptr->Release((Interface *)v7);
  return 1;
}

//----- (0056E1E0) --------------------------------------------------------  // acclient.c:410683
unsigned int __thiscall ClientTradeSystem::Handle_Trade__Recv_AddToTrade(ClientTradeSystem *this, unsigned int item, unsigned int id, unsigned int loc)
{
  IACPlugin *v4; // eax@6

  if ( id == 1 )
  {
    Trade::AddItem(this->m_pTrade, item, 1u, loc);
  }
  else if ( id == 2 )
  {
    ClientTradeSystem::AddPartnerItem(this, item, loc);
  }
  CM_Trade::SendNotice_AddItemToTrade(item, id, loc);
  if ( APIManager::APIIsReady() )
  {
    v4 = APIManager::GetACPlugin();
    v4->vfptr[5].QueryInterface((IUnknown *)v4, (_GUID *)id, (void **)item);
  }
  return 0;
}

//----- (0056E240) --------------------------------------------------------  // acclient.c:410705
void ClientTradeSystem::NotifyServerThatTradeIsOutOfSync()
{
  Trade *v1; // eax@1
  Trade v2; // [sp+0h] [bp-40h]@1

  Trade::Trade(&v2);
  CM_Trade::Event_AcceptTrade(v1);
  v2._partner_list.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  PackableList<ContentProfile>::Flush(&v2._partner_list);
  v2._partner_list.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2._self_list.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  PackableList<ContentProfile>::Flush(&v2._self_list);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);

//----- (007091D0) --------------------------------------------------------  // acclient.c:796363
void sub_7091D0()
{
  flt_87075C = 1000.0 + 1.0;
}

//----- (007091F0) --------------------------------------------------------  // acclient.c:796369
void sub_7091F0()
{
  flt_870760 = 24.0 * 8.0;
}

//----- (00709210) --------------------------------------------------------  // acclient.c:796375
void sub_709210()
{
  flt_870764 = 24.0 * 0.5;
}

//----- (00709230) --------------------------------------------------------  // acclient.c:796381
int sub_709230()
{
  return atexit(nullsub_1375);
}

//----- (00709240) --------------------------------------------------------  // acclient.c:796387
int sub_709240()
{
  return atexit(nullsub_1376);
}

//----- (00709250) --------------------------------------------------------  // acclient.c:796393
int sub_709250()
{
  return atexit(nullsub_1377);
}

//----- (00709260) --------------------------------------------------------  // acclient.c:796399
void sub_709260()
{
  flt_870768 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709280) --------------------------------------------------------  // acclient.c:796405
void _E108_92()
{
  dbl_870770 = 1.0 / 30.0;
}

//----- (007092A0) --------------------------------------------------------  // acclient.c:796411
void _E110_76()
{
  dbl_870778 = 1.0 / 5.0;
}

//----- (007092C0) --------------------------------------------------------  // acclient.c:796417
void sub_7092C0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870780, PFID_A8R8G8B8);
}

//----- (007092D0) --------------------------------------------------------  // acclient.c:796423
void _E115_76()
{
  dword_8707B8 = 1024;
}

//----- (007092E0) --------------------------------------------------------  // acclient.c:796429
void _E117_72()
{
  dword_8707BC = 0x7FFF;
}

//----- (007092F0) --------------------------------------------------------  // acclient.c:796435
int _E119_26()
{
  const int result; // eax@1

  result = dword_8707B8;
  dword_8707C0 = dword_8707B8;
  return result;
}

//----- (00709300) --------------------------------------------------------  // acclient.c:796445
int _E121_67()
{
  return atexit(_E122_94);
}

//----- (00709310) --------------------------------------------------------  // acclient.c:796451
int sub_709310()
{
  return atexit(nullsub_1374);
}

