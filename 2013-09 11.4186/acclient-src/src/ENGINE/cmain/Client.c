/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Client
   Object     : ENGINE\cmain\Client.obj
   Functions  : 168
   Addresses  : 00411110 - 00726820 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00411110) --------------------------------------------------------  // acclient.c:77182
void __thiscall IInputActionCallback::~IInputActionCallback(IInputActionCallback *this)
{
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(this);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);

//----- (00411130) --------------------------------------------------------  // acclient.c:77191
IInputActionCallback *__thiscall IInputActionCallback::scalar_deleting_destructor(IInputActionCallback *this, unsigned int a2)
{
  IInputActionCallback *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);

//----- (00411160) --------------------------------------------------------  // acclient.c:77206
gmClient *__cdecl Client::GetInstance()
{
  return Client::m_instance;
}

//----- (00411170) --------------------------------------------------------  // acclient.c:77212
void __usercall Client::CleanupUI(Client *this@<ecx>, signed int a2@<edi>)
{
  Client *v2; // esi@1
  UIFlow *v3; // ecx@1
  IQueuedUIEventDeliverer *v4; // ecx@5
  IQueuedUIEventDeliverer *v5; // ecx@6
  PSRefBufferCharData<char> *v6; // ecx@10

  v2 = this;
  v3 = this->m_ui;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_ui = 0;
  }
  if ( UIElementManager::s_pInstance )
  {
    UIElementManager::Cleanup(UIElementManager::s_pInstance, a2);
    UIElementManager::DestroyUIElementManager();
  }
  v4 = v2->m_UIQueueManager;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[1].IUnknown_AddRef)();
    v5 = v2->m_UIQueueManager;
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v2->m_UIQueueManager = 0;
    }
  }
  if ( v2->smartbox_ )
    SmartBox::Cleanup();
  v6 = (PSRefBufferCharData<char> *)ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(&v2->vfptr);
  Device::Cleanup(v6);
  KeyStone::Cleanup();
  CoUninitialize();
}

//----- (00411200) --------------------------------------------------------  // acclient.c:77254
void __thiscall Client::CleanupDatabase(Client *this)
{
  Client *v1; // esi@1
  CLCache *v2; // ecx@1

  v1 = this;
  v2 = this->m_pDBCache;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pDBCache = 0;
  }
}

//----- (00411220) --------------------------------------------------------  // acclient.c:77269
int __cdecl portal_new_handler(unsigned int size)
{
  PopupError("OUT OF MEMORY: Failed to allocate %d bytes.", size);
  DebugBreak();
  return 0;
}

//----- (00411240) --------------------------------------------------------  // acclient.c:77277
void Client::CleanupPreferences()
{
  PSRefBufferCharData<char> *v1; // ecx@1

  UserPreferences::UnregisterPreference(&Net_BindInterface);
  UserPreferences::UnregisterPreference(&Net_ComputeUniquePort);
  UserPreferences::UnregisterPreference(&Net_UserSpecifiedPort);
  CIme::CleanupPreferences();
  UserPreferences::Save();
  UserPreferences::Cleanup(v1);
}

//----- (00411270) --------------------------------------------------------  // acclient.c:77290
char __thiscall Client::InitAuth(Client *this)
{
  NetAuthenticator::SetToAuthType(&this->m_netAuth, 1u, &this->m_account, 0, 0);
  return 1;
}

//----- (00411290) --------------------------------------------------------  // acclient.c:77297
char __thiscall Client::Disconnect(Client *this)
{
  Client *v1; // esi@1
  ClientNet *v2; // ecx@2

  v1 = this;
  if ( this->m_connected )
  {
    v2 = this->m_net;
    if ( v2 )
      ClientNet::LogOffServer(v2);
    ((void (*)(void))v1->m_pDBCache->vfptr[1].IUnknown_Release)();
    v1->m_connected = 0;
  }
  return 1;
}

//----- (004112D0) --------------------------------------------------------  // acclient.c:77315
#error "41132D: call analysis failed (funcsize=27)"

//----- (00411340) --------------------------------------------------------  // acclient.c:77318
int Client::GetCharactersToWrapUsageTo()
{
  return -1;
}

//----- (00411350) --------------------------------------------------------  // acclient.c:77324
signed int __thiscall Client::GetNameRuleLanguage(Client *this)
{
  CLCache *v1; // eax@1
  signed int result; // eax@2

  v1 = this->m_pDBCache;
  if ( v1 )
    result = v1->m_eNameRuleLanguage;
  else
    result = 1;
  return result;
}

//----- (00411370) --------------------------------------------------------  // acclient.c:77338
double __thiscall LinkStatusHolder::GetPacketLossPercentage(LinkStatusHolder *this)
{
  return this->m_fPacketLoss;
}

//----- (00411380) --------------------------------------------------------  // acclient.c:77344
long double __thiscall LinkStatusHolder::GetConnectionStatus(LinkStatusHolder *this, int *bConnected)
{
  bool v2; // zf@1
  long double result; // st7@2

  v2 = this->m_eLinkState != 3;
  *bConnected = this->m_eLinkState == 3;
  if ( v2 )
    result = 0.0;
  else
    result = COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_tLastHeardFromCurServer;
  if ( this->m_nodropKick )
  {
    if ( result > 15.0 )
      result = 15.0;
  }
  return result;
}

//----- (004113D0) --------------------------------------------------------  // acclient.c:77364
void __thiscall LinkStatusHolder::OnHeartbeat(LinkStatusHolder *this, CLinkStatusAverages *Avgs)
{
  *(_QWORD *)&this->m_tLastHeardFromCurServer = Timer::cur_time;
  this->m_fPacketLoss = CLinkStatusAverages::GetAveragePacketLoss(Avgs);
}

//----- (00411400) --------------------------------------------------------  // acclient.c:77371
signed int __cdecl ConstructClassObjectEx<UIFlow,Interface>(Turbine_GUID *i_rcClassType)
{
  InterfaceSystem *v1; // eax@1
  Interface *pcInterface; // [sp+0h] [bp-8h]@1
  TResult cTr; // [sp+4h] [bp-4h]@1

  pcInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::CreateInstance(v1, &cTr, i_rcClassType, &Interface_InterfaceType_4, 0, (void **)&pcInterface);
  return (cTr.m_val & 0x80000000) != 0 ? 0 : (unsigned int)pcInterface;
}

//----- (00411450) --------------------------------------------------------  // acclient.c:77384
int __thiscall NetError::Pack(NetError *this, void **addr, unsigned int size)
{
  NetError *v3; // esi@1
  char *v4; // edx@3

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() && size >= 4 )
  {
    *(_DWORD *)*addr = v3->m_stringID;
    v4 = (char *)*addr + 4;
    *addr = v4;
    if ( size - 4 >= 4 )
    {
      *(_DWORD *)v4 = v3->m_tableID;
      *addr = (char *)*addr + 4;
    }
  }
  return ((int (__thiscall *)(NetError *))v3->vfptr->GetPackSize)(v3);
}

//----- (004114A0) --------------------------------------------------------  // acclient.c:77405
int __thiscall NetError::UnPack(NetError *this, void **addr, unsigned int size)
{
  NetError *v3; // esi@1
  int result; // eax@2
  char *v5; // edx@4

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    if ( size >= 4 )
    {
      v3->m_stringID = *(_DWORD *)*addr;
      v5 = (char *)*addr + 4;
      *addr = v5;
      if ( size - 4 >= 4 )
      {
        v3->m_tableID = *(_DWORD *)v5;
        *addr = (char *)*addr + 4;
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00411510) --------------------------------------------------------  // acclient.c:77446
void __thiscall AC1Legacy::PStringBase<char>::break_reference(AC1Legacy::PStringBase<char> *this)
{
  AC1Legacy::PStringBase<char> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // ebx@1

  v1 = this;
  v2 = this->m_buffer;
  if ( this->m_buffer->m_cRef == 1 )
  {
    v2->m_hash = -1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::allocate_ref_buffer(this, v2->m_len - 1);
    qmemcpy(v1->m_buffer->m_data, v2->m_data, v1->m_buffer->m_len);
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) )
    {
      if ( v2 )
        v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    }
  }
}

//----- (00411570) --------------------------------------------------------  // acclient.c:77470
void __thiscall Client::Cleanup(Client *this)
{
  Client *v1; // esi@1
  QualityRegistrar *v2; // ecx@1
  GlobalEventHandler *v3; // ecx@3
  InterfaceSystem *v4; // edi@6

  v1 = this;
  ((void (*)(void))this->vfptr[1].AddRef)();
  CCommunicationSystem::Cleanup();
  v1->vfptr[5].Release((Interface *)v1);
  CLanguageInfoInterface::Shutdown();
  ((void (__thiscall *)(Client *))v1->vfptr[5].QueryInterface)(v1);
  ((void (__thiscall *)(Client *))v1->vfptr[4].QueryInterface)(v1);
  v2 = v1->m_qualityRegistrar;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->m_eventHandler;
  v1->m_qualityRegistrar = 0;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v1->m_eventHandler = 0;
  InterfaceSystem::GetInstance();
  if ( InterfaceSystem::s_pInterfaceSystem )
  {
    v4 = InterfaceSystem::s_pInterfaceSystem;
    InterfaceSystem::~InterfaceSystem(InterfaceSystem::s_pInterfaceSystem);
    operator delete(v4);
    InterfaceSystem::s_pInterfaceSystem = 0;
    InterfaceSystem::s_bInterfaceSystemDestroyed = 1;
  }
  v1->vfptr[5].AddRef((Interface *)v1);
  SoundManager::Cleanup();
}
// 836744: using guessed type bool InterfaceSystem::s_bInterfaceSystemDestroyed;

//----- (00411620) --------------------------------------------------------  // acclient.c:77507
unsigned int __thiscall Client::GetLanguage(Client *this)
{
  Client *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  PStringBase<char> v3; // ST04_4@2
  bool v4; // zf@2
  unsigned int result; // eax@2
  unsigned int newlang; // [sp+0h] [bp-4h]@1

  newlang = (unsigned int)this;
  v1 = this;
  v2 = this->m_LanguageStr.m_charbuffer;
  if ( *(_DWORD *)&v2[-1].m_data[12] == 1
    || (v3.m_charbuffer = this->m_LanguageStr.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&v2[-1]),
        v4 = EnumMapper::GetEnum(0xCu, v3, &newlang) == 0,
        result = newlang,
        v4) )
    result = v1->m_Language;
  return result;
}

//----- (00411660) --------------------------------------------------------  // acclient.c:77530
char __thiscall Client::InitUI(Client *this, PStringBase<char> *windowTitle)
{
  Client *v2; // esi@1
  SmartBox *v3; // eax@4
  signed int v5; // eax@9

  v2 = this;
  CoInitialize(0);
  KeyStone::Init();
  if ( !Device::Init(v2->m_fWindowed != 0, windowTitle, 800, 600, 1, &PStringBase<char>::null_string) )
    return 0;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(16, &v2->vfptr, -1);
  SoundManager::Init(Device::m_hWnd);
  v3 = SmartBox::Init(v2->netQueues_[10], 0);
  v2->smartbox_ = v3;
  if ( !v3 )
  {
    PopupError("FATAL ERROR: Cannot initialize the render engine!\n");
    return 0;
  }
  SmartBox::Hide(v3);
  UIElementManager::CreateUIElementManager();
  if ( UIElementManager::s_pInstance )
    UIElementManager::Init(UIElementManager::s_pInstance);
  v5 = ConstructClassObjectEx<UIFlow,Interface>(&UIFlow_ClassType_0);
  v2->m_ui = (UIFlow *)v5;
  if ( !v5 )
    return 0;
  DBObj::InitLoad();
  return 1;
}

//----- (00411740) --------------------------------------------------------  // acclient.c:77564
BOOL __thiscall Client::AddNetQueue(Client *this, __int16 queueID)
{
  Client *v2; // esi@1
  void *v3; // eax@1
  NIList<NetBlob *> *v4; // ecx@2
  int v5; // eax@4
  NIList<NetBlob *> *v6; // eax@4

  v2 = this;
  v3 = operator new(8u);
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    v4 = (NIList<NetBlob *> *)v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = queueID;
  v2->netQueues_[v5] = v4;
  v6 = v2->netQueues_[v5];
  return v6 && PacketController::AddReceiveQueue(v2->packControl_, queueID, v6);
}

//----- (004117B0) --------------------------------------------------------  // acclient.c:77591
bool __thiscall Client::Run(Client *this)
{
  Client *v1; // esi@1
  int v2; // eax@1
  char v4; // [sp+4h] [bp-Ch]@1

  v1 = this;
  v2 = ((int (__stdcall *)(char *))this->vfptr[1].QueryInterface)(&v4);
  if ( ID_NetError_None.m_stringID == *(_DWORD *)(v2 + 4) && ID_NetError_None.m_tableID == *(_DWORD *)(v2 + 8) )
  {
    while ( (unsigned __int8)((int (__thiscall *)(Client *))v1->vfptr[2].IUnknown_QueryInterface)(v1) )
      ;
  }
  return 0;
}

//----- (004117F0) --------------------------------------------------------  // acclient.c:77608
void __thiscall Client::SetLanguage(Client *this, PStringBase<char> *_lang)
{
  Client *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_LanguageStr.m_charbuffer;
  if ( v3 != _lang->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = _lang->m_charbuffer;
    v2->m_LanguageStr.m_charbuffer = _lang->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00411840) --------------------------------------------------------  // acclient.c:77632
void __userpurge Client::OnDDDEvent(Client *this@<ecx>, double a2@<st0>, DDDEvent evtNum, unsigned int nBytes)
{
  Client *v4; // esi@1
  DiskSpace *v5; // ecx@4
  SmartBox *v6; // ecx@6

  v4 = this;
  if ( evtNum == 4 )
  {
    CLanguageInfoInterface::Shutdown();
    if ( MasterPropertyGrabber::s_spcMasterPropertyList )
    {
      (*(void (**)(void))(*(_DWORD *)MasterPropertyGrabber::s_spcMasterPropertyList + 20))();
      MasterPropertyGrabber::s_spcMasterPropertyList = 0;
    }
    DBCache::FlushFreeObjects(0);
    DBCache::FlushFreeObjects(0);
    DBCache::FlushFreeObjects(0);
    CLanguageInfoInterface::Startup();
    if ( DBCache::IsLoader() )
      gmNoticeHandler::RecvNotice_PrevSpellSelection(v5);
    v6 = (SmartBox *)v4->m_eventHandler;
    if ( v6 )
      SmartBox::SetRegion(v6, a2, nBytes);
  }
}
// 836DB8: using guessed type int MasterPropertyGrabber::s_spcMasterPropertyList;

//----- (004118C0) --------------------------------------------------------  // acclient.c:77661
void __thiscall Client::ProcessLogonEventQueue(Client *this)
{
  NIList<NetBlob *> *v1; // eax@1
  NIListElement<NetBlob *> *v2; // ecx@3
  NetBlob *v3; // esi@4
  NIListElement<NetBlob *> *v4; // edx@5
  char *v5; // eax@8
  _GUID *v6; // edi@11
  int v7; // ebx@11
  IChatClient *v8; // eax@11
  Client *v9; // [sp+10h] [bp-4h]@1

  v1 = this->m_logonEventQueue;
  v9 = this;
  if ( v1 && v1->head_ )
  {
    do
    {
      v2 = v1->head_;
      if ( v1->head_ )
      {
        v4 = v2->next_;
        v1->head_ = v4;
        if ( !v4 )
          v1->tail_ = 0;
        v3 = v2->data_;
        operator delete(v2);
      }
      else
      {
        v3 = 0;
      }
      v5 = v3->buf_;
      if ( v5 )
      {
        if ( v3->bufSize_ >= 4 && *(_DWORD *)v5 == 63454 )
        {
          v6 = (_GUID *)*((_DWORD *)v5 + 1);
          v7 = (int)(v5 + 8);
          CCommunicationSystem::GetChatManager();
          v8 = AC1ClientChatManager::GetIChatClient();
          if ( v8 )
            v8->vfptr[1].QueryInterface((IUnknown *)v8, v6, (void **)v7);
        }
      }
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
      v1 = v9->m_logonEventQueue;
    }
    while ( v1->head_ );
  }
}

//----- (00411960) --------------------------------------------------------  // acclient.c:77715
void __thiscall LinkStatusHolder::OnNetStatusChange(LinkStatusHolder *this, NetStatus Status, int Param1, int Param2)
{
  double v4; // st7@4
  unsigned int v5; // edx@6

  switch ( Status )
  {
    case 0:
      this->m_eLinkState = 1;
      LODWORD(this->m_fConnectionProgress) = 1036831949;
      break;
    case 1:
      this->m_fConnectionProgress = (double)Param1 * 0.5 / (double)Param2 + 0.1;
      break;
    case 2:
      v4 = (double)Param1 * 0.030000001 + 0.60000002;
      this->m_fConnectionProgress = v4;
      if ( v4 > 0.89999998 )
        LODWORD(this->m_fConnectionProgress) = 1063675494;
      break;
    case 3:
      LODWORD(this->m_fConnectionProgress) = 1065353216;
      this->m_eLinkState = 3;
      this->m_errFinal.m_stringID = ID_NetError_None.m_stringID;
      this->m_errFinal.m_tableID = ID_NetError_None.m_tableID;
      v5 = i_key.m_dwKey;
      LODWORD(this->m_tLastHeardFromCurServer) = Timer::cur_time.Cmd;
      HIDWORD(this->m_tLastHeardFromCurServer) = v5;
      break;
    case 4:
      this->m_errFinal.m_stringID = *(_DWORD *)(Param1 + 4);
      this->m_errFinal.m_tableID = *(_DWORD *)(Param1 + 8);
      this->m_eLinkState = 4;
      break;
    default:
      return;
  }
}

//----- (00411A30) --------------------------------------------------------  // acclient.c:77755
void __userpurge UserPreferences::RegisterPreference(bool *_pVariable@<eax>, void *a2@<ecx>, PStringBase<char> *_Name, PStringBase<char> *_Description, void (__cdecl *_OnChangedCallbackFP)(PStringBase<char> *), const unsigned int _NumChoices, PStringBase<char> *_pChoiceStrings, const unsigned int *_pChoiceValues)
{
  PStringBase<char> *v8; // esi@1
  GlobalRegistryInstance *v9; // eax@3
  GlobalRegistryInstance *v10; // eax@4
  int v11; // eax@9

  v8 = _Name;
  if ( a2 )
    GlobalRegistry::RegisterVariableInternal(
      a2,
      GRVDataType_Bool,
      _Name,
      _Description,
      _OnChangedCallbackFP,
      _NumChoices,
      _pChoiceStrings,
      _pChoiceValues);
  v9 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v10 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v10 )
      GlobalRegistryInstance::GlobalRegistryInstance(v10);
    else
      v9 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v9;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v9, v8, (GRPObject **)&_Name) )
  {
    v11 = (*(int (**)(void))&_Name->m_charbuffer[4].m_data[4])();
    if ( v11 )
      *(_BYTE *)(v11 + 40) = 1;
  }
}

//----- (00411AB0) --------------------------------------------------------  // acclient.c:77792
void __thiscall NetAuthenticator::~NetAuthenticator(NetAuthenticator *this)
{
  NetAuthenticator *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4

  v1 = this;
  operator delete[](this->m_ExtraData.m_pBuf);
  v1->m_ExtraData.m_pBuf = 0;
  operator delete[](v1->m_CryptoData.m_pBuf);
  v1->m_CryptoData.m_pBuf = 0;
  v2 = v1->m_AccountToLogonAs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->m_Account.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00411B20) --------------------------------------------------------  // acclient.c:77814
char __thiscall Client::InitNet(Client *this)
{
  Client *v1; // esi@1
  ClientNet *v2; // eax@1
  ClientNet *v3; // eax@2
  char result; // al@5
  PacketController *v5; // eax@6
  PacketController *v6; // eax@7
  void *v7; // eax@11
  signed int v8; // eax@13

  v1 = this;
  v2 = (ClientNet *)operator new(0x8CD0u);
  if ( v2 )
    ClientNet::ClientNet(v2);
  else
    v3 = 0;
  v1->m_net = v3;
  if ( v3 )
  {
    v5 = (PacketController *)operator new(0x70u);
    if ( v5 )
      PacketController::PacketController(v5, v1->m_net);
    else
      v6 = 0;
    v1->packControl_ = v6;
    if ( v6 )
    {
      v7 = operator new[](0x30u);
      v1->netQueues_ = (NIList<NetBlob *> **)v7;
      if ( v7 )
      {
        v8 = 0;
        do
        {
          v1->netQueues_[v8] = 0;
          ++v8;
        }
        while ( v8 < 12 );
        if ( Client::AddNetQueue(v1, 2)
          && Client::AddNetQueue(v1, 10)
          && Client::AddNetQueue(v1, 9)
          && Client::AddNetQueue(v1, 4)
          && Client::AddNetQueue(v1, 5) )
        {
          v1->m_logonEventQueue = (NIList<NetBlob *> *)*((_DWORD *)v1->netQueues_ + 4);
          result = 1;
        }
        else
        {
          PopupError("FATAL ERROR: Client CANNOT add all of the Net Queues\n");
          result = 0;
        }
      }
      else
      {
        PopupError("FATAL ERROR: Client can't allocate netqueue array\n");
        result = 0;
      }
    }
    else
    {
      PopupError("FATAL ERROR: Client can't allocate a packet controller\n");
      result = 0;
    }
  }
  else
  {
    PopupError("FATAL ERROR: Client can't initialize the Network!\n");
    result = 0;
  }
  return result;
}

//----- (00411C40) --------------------------------------------------------  // acclient.c:77889
#error "411CAD: call analysis failed (funcsize=34)"

//----- (00411CC0) --------------------------------------------------------  // acclient.c:77892
CDDDStatusPlugin *__thiscall CDDDStatusPlugin::vector_deleting_destructor(CDDDStatusPlugin *this, unsigned int a2)
{
  CDDDStatusPlugin *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  v3 = this->m_pManager;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, (CPluginPrototype *)&v2->vfptr);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);

//----- (00411D00) --------------------------------------------------------  // acclient.c:77912
void __thiscall Client::CleanupNet(Client *this)
{
  Client *v1; // ebp@1
  ClientNet *v2; // ecx@1
  void *v3; // esi@3
  ClientNet *v4; // eax@5
  bool v5; // zf@7
  signed int v6; // eax@8
  int v7; // edi@9
  int v8; // eax@10
  int v9; // esi@11
  int v10; // ecx@12
  int v11; // eax@19
  int v12; // ecx@21
  signed int v13; // [sp+Ch] [bp-4h]@8

  v1 = this;
  v2 = this->m_net;
  if ( v2 )
    ClientNet::LogOffServer(v2);
  v3 = v1->packControl_;
  if ( v3 )
  {
    PacketController::~PacketController(v1->packControl_);
    operator delete(v3);
  }
  v4 = v1->m_net;
  v1->packControl_ = 0;
  if ( v4 )
    ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->netQueues_ == 0;
  v1->m_net = 0;
  if ( !v5 )
  {
    v6 = 0;
    v13 = 0;
    do
    {
      v7 = *(int *)((char *)v1->netQueues_ + v6);
      if ( v7 )
      {
        v8 = *(_DWORD *)v7;
        if ( *(_DWORD *)v7 )
        {
          v10 = *(_DWORD *)(v8 + 4);
          *(_DWORD *)v7 = v10;
          if ( !v10 )
            *(_DWORD *)(v7 + 4) = 0;
          v9 = *(_DWORD *)v8;
          operator delete((void *)v8);
        }
        else
        {
          v9 = 0;
        }
        while ( v9 )
        {
          if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
          v11 = *(_DWORD *)v7;
          if ( *(_DWORD *)v7 )
          {
            v12 = *(_DWORD *)(v11 + 4);
            *(_DWORD *)v7 = v12;
            if ( !v12 )
              *(_DWORD *)(v7 + 4) = 0;
            v9 = *(_DWORD *)v11;
            operator delete((void *)v11);
          }
          else
          {
            v9 = 0;
          }
        }
        NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v7);
        operator delete((void *)v7);
        v6 = v13;
      }
      v6 += 4;
      v13 = v6;
    }
    while ( v6 < 48 );
    operator delete[](v1->netQueues_);
  }
}

//----- (00411E20) --------------------------------------------------------  // acclient.c:77999
bool __thiscall Client::Init(Client *this, PStringBase<char> *windowTitle, const int language_i, const int region_i)
{
  Client *v4; // esi@1
  HMODULE v5; // eax@4
  PSRefBufferCharData<unsigned short> *v6; // ecx@4
  PSRefBufferCharData<unsigned short> *v7; // ecx@5
  PSRefBufferCharData<unsigned short> *v8; // ecx@5
  int v10; // eax@8
  int v11; // eax@9
  int v12; // eax@10
  PStringBase<unsigned short> v13; // [sp-10h] [bp-B0h]@5
  PStringBase<unsigned short> v14; // [sp-Ch] [bp-ACh]@5
  PStringBase<unsigned short> v15; // [sp-8h] [bp-A8h]@5
  PlatformString::DisplayStringMode v16; // [sp-4h] [bp-A4h]@5
  _OSVERSIONINFOA osvi; // [sp+8h] [bp-98h]@2

  v4 = this;
  _set_new_handler(portal_new_handler);
  if ( (unsigned __int8)((int (__thiscall *)(Client *))v4->vfptr[5].IUnknown_Release)(v4) )
    return 0;
  memset(&osvi, 0, sizeof(osvi));
  osvi.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(&osvi) || osvi.dwPlatformId == 1 )
  {
    v5 = LoadLibraryA("unicows.dll");
    if ( !v5 )
    {
      v16 = 0;
      v15.m_charbuffer = v6;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, &word_794320);
      v14.m_charbuffer = v7;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v14, &word_794320);
      v13.m_charbuffer = v8;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v13, L"UnicoWS.dll");
      PlatformString::DisplayString(0x6Du, v13, v14, v15, v16);
      return 0;
    }
    FreeLibrary(v5);
  }
  Timer::Init();
  Random::Seed();
  v10 = CFactory::MakeGlobalEventHandler();
  v4->m_eventHandler = (GlobalEventHandler *)v10;
  if ( !v10 )
    return 0;
  v11 = CFactory::MakeQualityRegistrar();
  v4->m_qualityRegistrar = (QualityRegistrar *)v11;
  if ( !v11 )
    return 0;
  ((void (__thiscall *)(Client *))v4->vfptr[4].IUnknown_Release)(v4);
  v12 = v4->vfptr[4].AddRef((Interface *)v4);
  if ( !(_BYTE)v12 )
    return 0;
  LOBYTE(v12) = v4->m_fReadOnlyDatFiles != 0;
  if ( !(unsigned __int8)((int (__thiscall *)(Client *, const int, const int, int))v4->vfptr[4].Release)(
                           v4,
                           language_i,
                           region_i,
                           v12)
    || !CLanguageInfoInterface::Startup() )
    return 0;
  return (unsigned __int8)((int (__thiscall *)(Client *, PStringBase<char> *))v4->vfptr[5].IUnknown_AddRef)(
                            v4,
                            windowTitle) != 0;
}
// 7923DC: using guessed type int (__cdecl *__cdecl _set_new_handler(int (__cdecl *)(unsigned int)))(unsigned int);

//----- (00411F40) --------------------------------------------------------  // acclient.c:78067
char __thiscall Client::IsAlreadyRunning(Client *this)
{
  PSRefBufferCharData<unsigned short> *v1; // ecx@1
  PSRefBufferCharData<unsigned short> *v2; // ecx@2
  PSRefBufferCharData<unsigned short> *v3; // ecx@2
  char result; // al@2
  PStringBase<unsigned short> v5; // [sp-10h] [bp-14h]@2
  PStringBase<unsigned short> v6; // [sp-Ch] [bp-10h]@2
  PStringBase<unsigned short> v7; // [sp-8h] [bp-Ch]@2
  PlatformString::DisplayStringMode v8; // [sp-4h] [bp-8h]@2

  this->m_running_check.m_UniqueClientSemaphore = CreateSemaphoreA(0, 0, 1, "Empyrean Client");
  if ( GetLastError() == 183 )
  {
    v8 = 0;
    v7.m_charbuffer = v1;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v7, &word_794320);
    v6.m_charbuffer = v2;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v6, &word_794320);
    v5.m_charbuffer = v3;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, &word_794320);
    PlatformString::DisplayString(0xCCu, v5, v6, v7, v8);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00411FB0) --------------------------------------------------------  // acclient.c:78099
char __thiscall Client::InitPreferences(Client *this)
{
  Client *v1; // esi@1
  PStringBase<char> *v2; // eax@1
  char *v3; // edi@1
  bool *v4; // eax@4
  char *v5; // edi@4
  unsigned int *v6; // eax@7
  char *v7; // esi@7
  PSRefBufferCharData<char> *v8; // ecx@7
  PStringBase<char> _Description; // [sp+8h] [bp-4h]@1

  _Description.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  UserPreferences::Initialize(0, &this->m_preferencesFile);
  UserPreferences::Load();
  PStringBase<char>::PStringBase<char>(&_Description, "Network Bind Interface");
  UserPreferences::RegisterPreference(
    v2,
    &v1->m_strPreferenceBindInterface,
    &Net_BindInterface,
    &_Description,
    0,
    0,
    0,
    0);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Flag to compute a unique port");
  UserPreferences::RegisterPreference(
    v4,
    &v1->m_bPreferenceComputeUniquePort,
    &Net_ComputeUniquePort,
    &_Description,
    0,
    0,
    0,
    0);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "The user specified port");
  UserPreferences::RegisterPreference(
    v6,
    &v1->m_nPreferenceUserSpecifiedPort,
    &Net_UserSpecifiedPort,
    &_Description,
    0,
    0,
    0,
    0);
  v7 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  CIme::InitPreferences(v8);
  return 1;
}

//----- (004120C0) --------------------------------------------------------  // acclient.c:78159
void __thiscall Client::BuildCommandLineArgs(Client *this, ArgumentParser::CommandLineArgList *Args)
{
  Client *v2; // ebp@1
  ArgumentParser::CommandLineArgList *v3; // ebx@1
  char *v4; // edi@1
  char *v5; // edi@4
  char *v6; // edi@7
  char *v7; // edi@10
  char *v8; // edi@13
  char *v9; // edi@16
  char *v10; // edi@19
  char *v11; // edi@22
  char *v12; // edi@25
  char *v13; // edi@28
  char *v14; // edi@31
  char *v15; // edi@34
  char *v16; // edi@37
  char *v17; // edi@40
  char *v18; // edi@43
  char *v19; // edi@46
  char *v20; // edi@49
  char *v21; // edi@52
  PStringBase<char> LongCmd; // [sp+40h] [bp-8h]@1
  PStringBase<char> Descript; // [sp+44h] [bp-4h]@1

  v2 = this;
  PStringBase<char>::PStringBase<char>(&Descript, "<string>: Specifies the account name to logon with.");
  PStringBase<char>::PStringBase<char>(&LongCmd, "account");
  v3 = Args;
  ArgumentParser::CommandLineArgList::AddCmd(Args, 2, 97, &LongCmd, &Descript, 0, 0, 0);
  v4 = &LongCmd.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LongCmd.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<32 bitfield>: Controls what kinds of debug outputs are enabled.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "debug");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 2, 0, (PStringBase<char> *)&Args, &Descript, 0, 0, 0);
  v6 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "[host/IP]:Specifies where to find the server to talk to.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "host");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    50,
    104,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_LanguageStr,
    0,
    0);
  v8 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<string>: Language to run the client in.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "language");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 50, 0, (PStringBase<char> *)&Args, &Descript, &v2->m_pPrimer, 0, 0);
  v10 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<1-65535>: Specify the outgoing network port to use.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "outport");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 34, 113, (PStringBase<char> *)&Args, &Descript, &v2->m_port, 0, 0);
  v12 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v13 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<1-65535>: Specify the server port to contact. See 'host'");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "port");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    34,
    112,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_noflowqueue,
    0,
    0);
  v14 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<string>: Specify the preferences file to use.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "prefs");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    50,
    0,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_FullOutputText,
    0,
    0);
  v16 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  v17 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "Opens the DAT files readonly");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "rodat");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 3, 0, (PStringBase<char> *)&Args, &Descript, 0, 0, 0);
  v18 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  v19 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "Enables the use of the memory manager.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "usemem");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 17, 0, (PStringBase<char> *)&Args, &Descript, &v2->m_fWindowed, 1u, 0);
  v20 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  v21 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) )
  {
    if ( v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  }
}

//----- (004124F0) --------------------------------------------------------  // acclient.c:78297
char __thiscall Client::EvaluateCommandLineArg(Client *this, CommandLineArg *ArgData, PStringBase<char> *arg)
{
  CommandLineArg *v3; // esi@1
  char result; // al@1
  PStringBase<char> *v5; // esi@2
  bool v6; // al@2
  char *v7; // edi@2
  bool v8; // bl@2
  bool v9; // al@7
  char *v10; // edi@7
  bool v11; // bl@7
  PSRefBufferCharData<char> *v12; // esi@11
  unsigned __int32 v13; // esi@11
  bool v14; // bl@12
  char *v15; // edi@12
  bool v16; // bl@16
  signed int v17; // eax@17
  bool v18; // bl@20
  Client *v19; // [sp+Ch] [bp-8h]@1
  PStringBase<char> rhs; // [sp+10h] [bp-4h]@2
  char ArgDataa; // [sp+18h] [bp+4h]@1

  v3 = ArgData;
  v19 = this;
  result = ArgumentParser::EvaluateCommandLineArg(ArgData, arg);
  ArgDataa = result;
  if ( result )
  {
    PStringBase<char>::PStringBase<char>(&rhs, "account");
    v5 = &v3->LongVersion;
    v6 = PStringBase<char>::operator==(v5, &rhs);
    v7 = &rhs.m_charbuffer[-2].m_data[12];
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      AC1Legacy::PStringBase<char>::set(
        (AC1Legacy::PStringBase<char> *)&v19->m_fReadOnlyDatFiles,
        arg->m_charbuffer->m_data);
      AC1Legacy::PStringBase<char>::break_reference((AC1Legacy::PStringBase<char> *)&v19->m_fReadOnlyDatFiles);
      __strlwr((char *)(v19->m_fReadOnlyDatFiles + 20));
      return ArgDataa;
    }
    PStringBase<char>::PStringBase<char>(&rhs, "debug");
    v9 = PStringBase<char>::operator==(v5, &rhs);
    v10 = &rhs.m_charbuffer[-2].m_data[12];
    v11 = v9;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    if ( v11 )
    {
      v12 = arg->m_charbuffer;
      *__errno() = 0;
      v13 = _strtoul(v12->m_data, 0, 0);
      Turbine::Debug::SetDebugFlags(v13, 1);
      Turbine::Debug::SetDebugFlags(~v13, 0);
      return ArgDataa;
    }
    PStringBase<char>::PStringBase<char>(&rhs, "logfile");
    v14 = PStringBase<char>::operator==(v5, &rhs);
    v15 = &rhs.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    if ( !v14 )
    {
      PStringBase<char>::PStringBase<char>(&rhs, "outport");
      v16 = PStringBase<char>::operator==(v5, &rhs);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
      if ( v16 )
      {
        v17 = v19->m_port;
        if ( v17 < 1 || v17 > 0xFFFF )
        {
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&arg, "Client port must be between 1 and 65535\n");
          ((void (__thiscall *)(Client *, PStringBase<char> **))v19->vfptr[1].IUnknown_Release)(v19, &arg);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
          return 0;
        }
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&rhs, "rodat");
        v18 = PStringBase<char>::operator==(v5, &rhs);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
        if ( v18 )
          v19->m_fUseMemoryManager = *(_DWORD *)&arg->m_charbuffer[-1].m_data[12] == 1;
      }
    }
    result = ArgDataa;
  }
  return result;
}

//----- (00412720) --------------------------------------------------------  // acclient.c:78392
void __thiscall Client::FinishOutputText(Client *this)
{
  PSRefBufferCharData<unsigned short> *v1; // ecx@1
  PSRefBufferCharData<unsigned short> *v2; // ecx@1
  PStringBase<unsigned short> v3; // [sp-10h] [bp-10h]@1
  PStringBase<unsigned short> v4; // [sp-Ch] [bp-Ch]@1
  PStringBase<unsigned short> v5; // [sp-8h] [bp-8h]@1
  PlatformString::DisplayStringMode v6; // [sp-4h] [bp-4h]@1

  v6 = 0;
  v5.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, &word_794320);
  v4.m_charbuffer = v1;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v4, &word_794320);
  v3.m_charbuffer = v2;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v3, &word_794320);
  PlatformString::DisplayString(0xCDu, v3, v4, v5, v6);
}

//----- (00412760) --------------------------------------------------------  // acclient.c:78412
char __thiscall Client::RemoveDDDStatusPlugin(Client *this, CDDDStatusPlugin *i_pPlugin)
{
  CLCache *v2; // eax@1
  char result; // al@2

  v2 = this->m_pDBCache;
  if ( v2 )
    result = CPluginManager::RemovePluginPrototype(
               (CPluginManager *)&v2->m_Plugins,
               (CPluginPrototype *)&i_pPlugin->vfptr);
  else
    result = 0;
  return result;
}

//----- (00412780) --------------------------------------------------------  // acclient.c:78428
PStringBase<unsigned short> *__thiscall NetError::GetLogString(NetError *this, PStringBase<unsigned short> *result)
{
  NetError *v2; // esi@1
  PStringBase<unsigned short> *v3; // eax@3
  StringInfo v4; // [sp+4h] [bp-90h]@3

  v2 = this;
  if ( this->m_stringID && this->m_tableID )
  {
    StringInfo::StringInfo(&v4);
    StringInfo::SetStringIDandTableEnum(&v4, v2->m_stringID, v2->m_tableID);
    StringInfo::GetLogString(&v4, result, 1);
    StringInfo::~StringInfo(&v4);
    v3 = result;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(result, L"unknown");
    v3 = result;
  }
  return v3;
}

//----- (00412800) --------------------------------------------------------  // acclient.c:78452
int ArgumentParser::GetCharactersToWrapUsageTo()
{
  return 80;
}

//----- (00412810) --------------------------------------------------------  // acclient.c:78458
void __thiscall Client::~Client(Client *this)
{
  Client *v1; // esi@1
  int v2; // edi@3
  int v3; // edi@6
  int v4; // edi@9
  int v5; // edi@12
  int v6; // edi@15
  ReferenceCountTemplate<1048576,2>Vtbl *v7; // edi@18
  int v8; // edi@21
  int v9; // edi@24
  int v10; // edi@27
  CPluginManager *v11; // ecx@27
  CPluginManager *v12; // ecx@31
  unsigned int v13; // ebx@33
  int v14; // esi@33
  int v15; // esi@36
  char *v16; // [sp+24h] [bp-4h]@1

  v1 = this;
  this[-1].pNetAuth_ = (NetAuthenticator *)&Client::vftable;
  this[-1].smartbox_ = (SmartBox *)&Client::vftable;
  this->vfptr = (InterfaceVtbl *)&Client::vftable;
  this->m_ErrorText.m_charbuffer = (PSRefBufferCharData<char> *)&Client::vftable;
  this->m_CmdChars.m_charbuffer = (PSRefBufferCharData<char> *)&Client::vftable;
  v16 = (char *)&this[-1].smartbox_;
  Client::m_instance = 0;
  if ( this->m_nPreferenceUserSpecifiedPort )
  {
    CloseHandle((HANDLE)this->m_nPreferenceUserSpecifiedPort);
    v1->m_nPreferenceUserSpecifiedPort = 0;
  }
  v2 = v1->m_netAuth.m_CryptoData.m_cbCurSize - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  NetAuthenticator::~NetAuthenticator((NetAuthenticator *)&v1->m_latencyDelay);
  v3 = (int)&v1->m_hostName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = v1->m_fReadOnlyDatFiles - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = v1->m_fUseMemoryManager - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = v1->m_fWindowed - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = v1->m_cTurbineRefCount.vfptr;
  if ( !InterlockedDecrement((volatile LONG *)&v7[1]) && v7 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v7->__vecDelDtor)(v7, 1);
  v8 = (int)&v1->m_errFinal.vfptr[-1];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = LODWORD(v1->m_fPacketLoss) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = v1 != (Client *)28 ? (unsigned int)&v1->m_CmdChars : 0;
  HIDWORD(v1->m_tLastHeardFromCurServer) = &ReferenceCountTemplate<1048576,2>::vftable;
  v11 = *(CPluginManager **)(v10 + 4);
  *(_DWORD *)(v10 + 32) = &PackObj::vftable;
  *(_DWORD *)v10 = &CPluginPrototype::vftable;
  if ( v11 )
  {
    CPluginManager::RemovePluginPrototype(
      v11,
      (CPluginPrototype *)(v1 != (Client *)28 ? (unsigned int)&v1->m_CmdChars : 0));
    (v1 != (Client *)28 ? &v1->m_CmdChars + 1 : 4)->m_charbuffer = 0;
  }
  *(_DWORD *)(v1 != (Client *)28 ? (unsigned int)&v1->m_ErrorText : 0) = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1 != (Client *)28 ? (unsigned int)&v1->m_ErrorText : 0);
  v12 = (CPluginManager *)*(v1 != (Client *)28 ? &v1->vfptr : 4);
  *(_DWORD *)(v1 != (Client *)28 ? (unsigned int)v1 : 0) = &CPluginPrototype::vftable;
  if ( v12 )
  {
    CPluginManager::RemovePluginPrototype(v12, (CPluginPrototype *)(v1 != (Client *)28 ? (unsigned int)v1 : 0));
    *(v1 != (Client *)28 ? &v1->vfptr : 4) = 0;
  }
  v13 = v1 != (Client *)28 ? (unsigned int)v16 : 0;
  v14 = *(_DWORD *)(v1 != (Client *)28 ? v16 + 8 : 8) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = *(_DWORD *)(v13 + 4) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v15 + 4)) )
  {
    if ( v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 794CCC: using guessed type int (*Client::vftable)();
// 794CDC: using guessed type int (*Client::vftable)();
// 794CE8: using guessed type int (__stdcall *Client::vftable)(char);
// 794CF8: using guessed type void (__thiscall *Client::vftable)(ArgumentParser *__hidden this);
// 794D48: using guessed type __int32 (__stdcall *Client::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00412A20) --------------------------------------------------------  // acclient.c:78559
int __thiscall Client::vector_deleting_destructor(void *this, char a2)
{
  return Client::scalar_deleting_destructor((Client *)((char *)this - 8), a2);
}

//----- (00412A30) --------------------------------------------------------  // acclient.c:78565
int __thiscall Client::vector_deleting_destructor(void *this, char a2)
{
  return Client::scalar_deleting_destructor((Client *)((char *)this - 12), a2);
}

//----- (00412A40) --------------------------------------------------------  // acclient.c:78571
void __thiscall Client::AppendOutputText(Client *this, const char *Text, ArgumentParser::OutputTextType i_eFormattingHint)
{
  Client *v3; // edi@1
  ArgumentParser::OutputTextType v4; // ecx@3
  int v5; // eax@3
  int v6; // esi@5

  v3 = this;
  ArgumentParser::AppendOutputText(Text, i_eFormattingHint);
  if ( Text && *Text )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_eFormattingHint, Text);
    v4 = i_eFormattingHint;
    v5 = *(_DWORD *)(i_eFormattingHint - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(
        (PStringBase<char> *)&v3->m_cTurbineRefCount.m_cRef,
        (const char *)i_eFormattingHint,
        v5 - 1);
      v4 = i_eFormattingHint;
    }
    v6 = v4 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
  }
}

//----- (00412AB0) --------------------------------------------------------  // acclient.c:78603
LinkStatusHolder *__thiscall LinkStatusHolder::vector_deleting_destructor(LinkStatusHolder *this, unsigned int a2)
{
  LinkStatusHolder *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  v3 = this->m_pManager;
  v2->m_errFinal.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, (CPluginPrototype *)&v2->vfptr);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);

//----- (00412AF0) --------------------------------------------------------  // acclient.c:78625
void __thiscall Client::Client(Client *this)
{
  Client *v1; // esi@1
  volatile LONG *v2; // ST04_4@1
  volatile LONG *v3; // ST04_4@1
  volatile LONG *v4; // ST04_4@1
  volatile LONG *v5; // ST04_4@1
  volatile LONG *v6; // ST04_4@1
  volatile LONG *v7; // ST04_4@1
  volatile LONG *v8; // ST04_4@1
  volatile LONG *v9; // ST04_4@1
  volatile LONG *v10; // ST04_4@1

  v1 = this;
  this->vfptr = (ArgumentParserVtbl *)&ArgumentParser::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_ErrorText.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  PStringBase<char>::PStringBase<char>(&v1->m_CmdChars, "-/");
  v1->vfptr = (CPluginPrototypeVtbl *)&CDDDStatusPlugin::vftable;
  v1->m_pManager = 0;
  v1->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  v1->m_pManager = 0;
  v1->vfptr = (CPluginPrototypeVtbl *)&LinkStatusHolder::vftable;
  v1->m_eLinkState = 0;
  LODWORD(v1->m_tLastHeardFromCurServer) = 0;
  HIDWORD(v1->m_tLastHeardFromCurServer) = 0;
  LODWORD(v1->m_fConnectionProgress) = 0;
  LODWORD(v1->m_fPacketLoss) = 1065353216;
  v1->m_errFinal.vfptr = (PackObjVtbl *)&NetError::vftable;
  v1->m_nodropKick = 0;
  v1->vfptr = (InterfaceVtbl *)&Client::vftable;
  v1->vfptr = (ArgumentParserVtbl *)&Client::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&Client::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&Client::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&Client::vftable;
  v1->m_cTurbineRefCount.m_cRef = 1;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_FullOutputText.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_preferencesFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->m_fWindowed = 1;
  v1->m_fUseMemoryManager = 0;
  v1->m_fReadOnlyDatFiles = 1;
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->m_account.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  v1->m_account.fIsDarkMajestyExpansion_ = 0;
  v1->m_account.m_fIsThroneOfDestinyExpansion = 0;
  v1->m_account.m_fPreOrderedThroneOfDestinyExpansion = 0;
  v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_pPrimer.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v6);
  v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_LanguageStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v7);
  v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_hostName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v8);
  v1->m_noflowqueue = 0;
  v1->m_port = 7304;
  v1->m_clientPort = 0;
  v1->m_latencyDelay = 0;
  v1->m_latencyPercent = 0;
  v1->m_Language = 1;
  v9 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_worldName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v9);
  v1->m_pDBCache = 0;
  v1->m_ui = 0;
  v1->m_connected = 0;
  NetAuthenticator::NetAuthenticator(&v1->m_netAuth);
  v1->m_net = 0;
  v1->m_eventHandler = 0;
  v1->m_qualityRegistrar = 0;
  v10 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strPreferenceBindInterface.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v10);
  v1->m_bPreferenceComputeUniquePort = 0;
  v1->m_nPreferenceUserSpecifiedPort = 0;
  v1->m_UIQueueManager = 0;
  v1->smartbox_ = 0;
  v1->m_logonEventQueue = 0;
  v1->packControl_ = 0;
  v1->netQueues_ = 0;
  v1->m_running_check.m_UniqueClientSemaphore = 0;
  Client::m_instance = (gmClient *)v1;
  CCommunicationSystem::Init();
  Turbine::Debug::SetDebugFlags(0x100u, 1);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7949A8: using guessed type int (__thiscall *CDDDStatusPlugin::vftable)(void *, char);
// 794C80: using guessed type void (__thiscall *ArgumentParser::vftable)(ArgumentParser *__hidden this);
// 794CCC: using guessed type int (*Client::vftable)();
// 794CDC: using guessed type int (*Client::vftable)();
// 794CE8: using guessed type int (__stdcall *Client::vftable)(char);
// 794CF8: using guessed type void (__thiscall *Client::vftable)(ArgumentParser *__hidden this);
// 794D48: using guessed type __int32 (__stdcall *Client::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 794DD8: using guessed type int (__thiscall *LinkStatusHolder::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00412CE0) --------------------------------------------------------  // acclient.c:78732
int __thiscall Client::scalar_deleting_destructor(Client *this, char a2)
{
  Client *v2; // esi@1
  int result; // eax@1

  v2 = this;
  Client::~Client(this);
  result = (int)&v2[-1].pNetAuth_;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].pNetAuth_);
    result = (int)&v2[-1].pNetAuth_;
  }
  return result;
}

//----- (00412D10) --------------------------------------------------------  // acclient.c:78749
bool __thiscall Client::InitDatabase(Client *this, const int language_i, const int region_i, int open_readonly)
{
  Client *v4; // esi@1
  int v5; // eax@1
  bool result; // al@2
  char v7; // al@3
  char *v8; // edi@3
  bool v9; // bl@3
  PSRefBufferCharData<unsigned short> *v10; // ecx@3
  PSRefBufferCharData<unsigned short> *v11; // ecx@7
  PSRefBufferCharData<unsigned short> *v12; // ecx@7
  InterfaceVtbl *v13; // edx@8
  unsigned int v14; // eax@8
  PStringBase<unsigned short> v15; // [sp+0h] [bp-20h]@7
  PStringBase<unsigned short> v16; // [sp+4h] [bp-1Ch]@7
  PStringBase<unsigned short> v17; // [sp+8h] [bp-18h]@7
  PlatformString::DisplayStringMode v18; // [sp+Ch] [bp-14h]@7
  PStringBase<char> v19; // [sp+1Ch] [bp-4h]@1

  v19.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v4 = this;
  v5 = CFactory::Make_Client_Cache();
  v4->m_pDBCache = (CLCache *)v5;
  if ( v5 )
  {
    PStringBase<char>::PStringBase<char>(&v19, "client_portal.dat");
    v7 = ((int (__stdcall *)(PStringBase<char> *, int, signed int, _DWORD, signed int, _DWORD, _DWORD))v4->m_pDBCache->vfptr[4].IUnknown_Release)(
           &v19,
           open_readonly,
           1,
           0,
           1,
           0,
           0);
    v8 = &v19.m_charbuffer[-2].m_data[12];
    v9 = v7 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    if ( v9 )
    {
      v18 = 0;
      v17.m_charbuffer = v10;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v17, &word_794320);
      v16.m_charbuffer = v11;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v16, &word_794320);
      v15.m_charbuffer = v12;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, &word_794320);
      PlatformString::DisplayString(0xC9u, v15, v16, v17, v18);
      result = 0;
    }
    else
    {
      CLCache::SetNetQueue(v4->m_pDBCache, v4->netQueues_[5]);
      CPluginManager::AddPluginPrototype((CPluginManager *)&v4->m_pDBCache->m_Plugins, (CPluginPrototype *)&v4->vfptr);
      v13 = v4->vfptr;
      v18 = 1;
      v14 = ((int (__thiscall *)(Client *))v13[3].IUnknown_AddRef)(v4);
      result = DBCache::SetLocalLanguage(v14, 1) != 0;
    }
  }
  else
  {
    PopupError("FATAL ERROR: Client can't allocate a cache\n");
    result = 0;
  }
  return result;
}

//----- (00412E20) --------------------------------------------------------  // acclient.c:78818
int __thiscall Client::Connect(Client *this, NetError *result)
{
  Client *v2; // esi@1
  int v3; // eax@1
  const char *v4; // ebp@1
  unsigned int v5; // edi@1
  int v6; // edx@3
  const char *v7; // ST24_4@3
  HMODULE v8; // edi@3
  void (__stdcall *v9)(); // ebx@5
  unsigned int v10; // eax@5
  unsigned int v11; // eax@6
  int v12; // ecx@7
  int v13; // esi@14
  PSRefBufferCharData<char> *v14; // edi@17
  int v15; // esi@17
  int v16; // esi@24
  void (__cdecl *v17)(PacketInfo *, unsigned int); // edi@24
  HMODULE v19; // [sp-Ch] [bp-21Ch]@0
  int v20; // [sp-8h] [bp-218h]@0
  int v21; // [sp+4h] [bp-20Ch]@6
  PSRefBufferCharData<char> *v22; // [sp+8h] [bp-208h]@17
  int (__thiscall **v23)(void *, char); // [sp+Ch] [bp-204h]@6
  unsigned int v24; // [sp+10h] [bp-200h]@6
  int port; // [sp+14h] [bp-1FCh]@1
  PStringBase<char> userStr; // [sp+18h] [bp-1F8h]@14
  NetError err; // [sp+1Ch] [bp-1F4h]@5
  ClientNetConfiguration cfg; // [sp+2Ch] [bp-1E4h]@3
  DatIDStamp datver; // [sp+4Ch] [bp-1C4h]@14
  StringInfo v30; // [sp+60h] [bp-1B0h]@14
  StringInfo copy; // [sp+F0h] [bp-120h]@14
  StringInfo v32; // [sp+180h] [bp-90h]@24

  v2 = this;
  ((void (*)(void))this->vfptr[5].IUnknown_QueryInterface)();
  v3 = v2->m_clientPort;
  v4 = v2->m_hostName.m_charbuffer->m_data;
  port = v2->m_port;
  v5 = v3;
  if ( !v3 )
    v5 = v2->m_nPreferenceUserSpecifiedPort;
  CPluginManager::AddPluginPrototype((CPluginManager *)&v2->m_net->m_Plugins, (CPluginPrototype *)&v2->vfptr);
  cfg.DesiredInterface.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  cfg.pfnRecvLogger = 0;
  cfg.pfnSendLogger = 0;
  cfg.pfnUncompressedRecvLogger = 0;
  cfg.pfnUncompressedSendLogger = 0;
  cfg.dwUserLoggingData = 0;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v6 = v2->m_bPreferenceComputeUniquePort;
  v7 = v2->m_strPreferenceBindInterface.m_charbuffer->m_data;
  cfg.dwPort = v5;
  cfg.bAutoGenerateUniquePort = v6;
  AC1Legacy::PStringBase<char>::set(&cfg.DesiredInterface, v7);
  v8 = LoadLibraryA("acpl.dll");
  if ( v8 || (v8 = LoadLibraryA("pl.dll")) != 0 )
  {
    v9 = *(void (__stdcall **)())GetProcAddress;
    v20 = (int)"LogWireDataSent";
    v19 = v8;
    err.m_tableID = (int)GetProcAddress(v8, "LogWireDataReceived");
    v9();
    err.m_stringID = v10;
  }
  DatIDStamp::DatIDStamp((DatIDStamp *)&cfg.dwUserLoggingData);
  ClientNet::Init(
    v2->m_net,
    (NetError *)&v23,
    v21,
    v4,
    (DatIDStamp *)&cfg.dwUserLoggingData,
    &v2->m_netAuth,
    (ClientNetConfiguration *)&err);
  v11 = v24;
  if ( v24 != ID_NetError_None.m_stringID )
    goto LABEL_30;
  v12 = port;
  if ( port == ID_NetError_None.m_tableID )
  {
    while ( v2->m_eLinkState < 3 )
      Client::KeepUIAlive(v2);
    v11 = v2->m_errFinal.m_stringID;
    v12 = v2->m_errFinal.m_tableID;
    v24 = v2->m_errFinal.m_stringID;
    port = v12;
  }
  if ( v11 != ID_NetError_None.m_stringID || v12 != ID_NetError_None.m_tableID )
  {
LABEL_30:
    StringInfo::StringInfo((StringInfo *)((char *)&v30 + 128));
    StringInfo::SetStringIDandTableEnum((StringInfo *)((char *)&v30 + 128), v24, port);
    StringInfo::StringInfo((StringInfo *)((char *)&copy + 128), (StringInfo *)((char *)&v30 + 128));
    StringInfo::~StringInfo((StringInfo *)((char *)&v30 + 128));
    StringInfo::StringInfo((StringInfo *)&datver._maj_vnum.Data2, (StringInfo *)((char *)&copy + 128));
    StringInfo::~StringInfo((StringInfo *)((char *)&copy + 128));
    NetError::GetLogString((NetError *)&v23, (PStringBase<unsigned short> *)&v21);
    PStringBase<unsigned short>::to_spstring((PStringBase<unsigned short> *)&v21, &userStr, 0);
    v13 = v21 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v21 - 20 + 4)) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v22 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v14 = userStr.m_charbuffer;
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&v22,
      "Failed to establish connection to the server: %s (%8X:%08X)",
      userStr.m_charbuffer,
      *(_DWORD *)&datver._maj_vnum.Data4[4],
      *(_DWORD *)&datver._maj_vnum.Data4[0],
      v19,
      v20);
    PopupError(v22->m_data);
    v15 = (int)&v22[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v22[-1]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v14[-1]) && v14 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v14[-2].m_data[12])(&v14[-2].m_data[12], 1);
    StringInfo::~StringInfo((StringInfo *)&datver._maj_vnum.Data2);
    v12 = port;
    v11 = v24;
  }
  else
  {
    v2->m_connected = 1;
  }
  v16 = *(_DWORD *)&v32.m_Override;
  *(_DWORD *)(*(_DWORD *)&v32.m_Override + 8) = v12;
  *(_DWORD *)v16 = &NetError::vftable;
  *(_DWORD *)(v16 + 4) = v11;
  v23 = &PackObj::vftable;
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&cfg.dwUserLoggingData);
  v17 = cfg.pfnSendLogger;
  if ( !InterlockedDecrement((volatile LONG *)cfg.pfnSendLogger + 1) && v17 )
    (**(void (__thiscall ***)(void (__cdecl *)(PacketInfo *, unsigned int), signed int))v17)(v17, 1);
  return v16;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004130F0) --------------------------------------------------------  // acclient.c:78959
char __thiscall Client::AddDDDStatusPlugin(Client *this, CDDDStatusPlugin *i_pPlugin)
{
  CLCache *v2; // eax@1
  char result; // al@2

  v2 = this->m_pDBCache;
  if ( v2 )
    result = CPluginManager::AddPluginPrototype((CPluginManager *)&v2->m_Plugins, (CPluginPrototype *)&i_pPlugin->vfptr);
  else
    result = 0;
  return result;
}

//----- (006C3B70) --------------------------------------------------------  // acclient.c:732139
int _E73_8()
{
  return atexit(_E74_11);
}

//----- (006C3B80) --------------------------------------------------------  // acclient.c:732145
int _E76_3()
{
  return atexit(_E77_31);
}

//----- (006C3B90) --------------------------------------------------------  // acclient.c:732151
int _E79_3()
{
  return atexit(_E80_5);
}

//----- (006C3BA0) --------------------------------------------------------  // acclient.c:732157
void _E98_1()
{
  LOWEST_DATA_RATE_53 = 1024;
}

//----- (006C3BB0) --------------------------------------------------------  // acclient.c:732163
void _E100_1()
{
  HIGHEST_DATA_RATE_53 = 0x7FFF;
}

//----- (006C3BC0) --------------------------------------------------------  // acclient.c:732169
int _E102_1()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_53;
  INITIAL_MAX_DATA_RATE_1 = LOWEST_DATA_RATE_53;
  return result;
}

//----- (006C3BD0) --------------------------------------------------------  // acclient.c:732179
int _E104_1()
{
  PStringBase<char>::PStringBase<char>(&Net_BindInterface, "Net.BindInterface");
  return atexit(_E105_66);
}

//----- (006C3BF0) --------------------------------------------------------  // acclient.c:732186
int _E107()
{
  PStringBase<char>::PStringBase<char>(&Net_ComputeUniquePort, "Net.ComputeUniquePort");
  return atexit(sub_726580);
}

//----- (006C3C10) --------------------------------------------------------  // acclient.c:732193
int _E110_1()
{
  PStringBase<char>::PStringBase<char>(&Net_UserSpecifiedPort, "Net.UserSpecifiedPort");
  return atexit(_E111_69);
}

//----- (006C3C30) --------------------------------------------------------  // acclient.c:732200
int _E113()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_0, "None");
  return atexit(_E114_74);
}

//----- (006C3C50) --------------------------------------------------------  // acclient.c:732207
int _E116_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_0, "Speed");
  return atexit(sub_726610);
}

//----- (006C3C70) --------------------------------------------------------  // acclient.c:732214
int _E119()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_0, "Noise");
  return atexit(_E120_86);
}

//----- (006C3C90) --------------------------------------------------------  // acclient.c:732221
int _E122()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_0, "Sine");
  return atexit(_E123_57);
}

//----- (006C3CB0) --------------------------------------------------------  // acclient.c:732228
int _E125()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_0, "Square");
  return atexit(_E126_65);
}

//----- (006C3CD0) --------------------------------------------------------  // acclient.c:732235
int _E128()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_0, "Bounce");
  return atexit(_E129_59);
}

//----- (006C3CF0) --------------------------------------------------------  // acclient.c:732242
int _E131()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_0, "Perlin");
  return atexit(_E132_59);
}

//----- (006C3D10) --------------------------------------------------------  // acclient.c:732249
int _E134()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_0, "Fractal");
  return atexit(_E135_67);
}

//----- (006C3D30) --------------------------------------------------------  // acclient.c:732256
int _E137()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_0, "FrameLoop");
  return atexit(_E138_53);
}

//----- (006C3D50) --------------------------------------------------------  // acclient.c:732263
int _E140()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_1, "Display.Resolution");
  return atexit(_E141_55);
}

//----- (006C3D70) --------------------------------------------------------  // acclient.c:732270
int _E143()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_1, "Display.FullScreen");
  return atexit(_E144_51);
}

//----- (006C3D90) --------------------------------------------------------  // acclient.c:732277
int _E146()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_1, "Display.RefreshRate");
  return atexit(_E147_50);
}

//----- (006C3DB0) --------------------------------------------------------  // acclient.c:732284
int _E149()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_1, "Display.SyncToRefresh");
  return atexit(_E150_49);
}

//----- (006C3DD0) --------------------------------------------------------  // acclient.c:732291
void _E152()
{
  LODWORD(dword_836A50) = 1053364187;
}

//----- (006C3DE0) --------------------------------------------------------  // acclient.c:732297
void _E154_0()
{
  outside_val_1 = 1000.0 + 1.0;
}

//----- (006C3E00) --------------------------------------------------------  // acclient.c:732303
void _E156()
{
  block_length_1 = 24.0 * 8.0;
}

//----- (006C3E20) --------------------------------------------------------  // acclient.c:732309
void _E158()
{
  half_square_length_1 = 24.0 * 0.5;
}

//----- (006C3E40) --------------------------------------------------------  // acclient.c:732315
void _E160_0()
{
  DEFAULT_VIEW_RADIUS_1 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006C3E60) --------------------------------------------------------  // acclient.c:732321
void _E162()
{
  MIN_QUANTUM_1 = 1.0 / 30.0;
}

//----- (006C3E80) --------------------------------------------------------  // acclient.c:732327
void _E164()
{
  MAX_QUANTUM_1 = 1.0 / 5.0;
}

//----- (006C3EA0) --------------------------------------------------------  // acclient.c:732333
void _E166_0()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_1, PFID_A8R8G8B8);
}

//----- (006C3EB0) --------------------------------------------------------  // acclient.c:732339
int _E168()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_0, "Misc.TooltipEnable");
  return atexit(_E169_40);
}

//----- (006C3ED0) --------------------------------------------------------  // acclient.c:732346
int _E171()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_0, "Misc.TooltipDelay");
  return atexit(_E172_38);
}

//----- (006C3EF0) --------------------------------------------------------  // acclient.c:732353
int _E174()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_0, "Sound.SoundDisabled");
  return atexit(_E175_35);
}

//----- (006C3F10) --------------------------------------------------------  // acclient.c:732360
int _E177()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_0, "Sound.SoundVolume");
  return atexit(_E178_35);
}

//----- (006C3F30) --------------------------------------------------------  // acclient.c:732367
int _E180()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_0, "Sound.AmbientSoundDisabled");
  return atexit(_E181_35);
}

//----- (006C3F50) --------------------------------------------------------  // acclient.c:732374
int _E183()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_0, "Sound.AmbientSoundVolume");
  return atexit(_E184_33);
}

//----- (006C3F70) --------------------------------------------------------  // acclient.c:732381
int _E186()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_0, "Sound.InterfaceSoundDisabled");
  return atexit(_E187_32);
}

//----- (006C3F90) --------------------------------------------------------  // acclient.c:732388
int _E189()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_0, "Sound.InterfaceSoundVolume");
  return atexit(_E190_33);
}

//----- (006C3FB0) --------------------------------------------------------  // acclient.c:732395
int _E192()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_0, "Sound.SoundFeatures");
  return atexit(_E193_32);
}

//----- (006C3FD0) --------------------------------------------------------  // acclient.c:732402
int _E195()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_0, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E196_40);
}

//----- (006C3FF0) --------------------------------------------------------  // acclient.c:732409
int _E198()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_0, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_836ADC, "Mono");
  return atexit(_E199_31);
}

//----- (006C4020) --------------------------------------------------------  // acclient.c:732417
void _E201()
{
  VOL_MIN_DIST_SQ = 5.0 * 5.0;
}

//----- (006C4040) --------------------------------------------------------  // acclient.c:732423
void _E203()
{
  INV_LOG_OF_2 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006C4060) --------------------------------------------------------  // acclient.c:732429
int _E205_0()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_0, "Render.TextureFiltering");
  return atexit(_E206_8);
}

//----- (006C4080) --------------------------------------------------------  // acclient.c:732436
int _E208_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_0, "Render.LandscapeDetailTextures");
  return atexit(_E209_3);
}

//----- (006C40A0) --------------------------------------------------------  // acclient.c:732443
int _E211_0()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_0, "Render.BuildingDetailTextures");
  return atexit(_E212_6);
}

//----- (006C40C0) --------------------------------------------------------  // acclient.c:732450
int _E214_0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_0, "Render.FieldOfView");
  return atexit(_E215_2);
}

//----- (006C40E0) --------------------------------------------------------  // acclient.c:732457
int _E217_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_0, "Render.LandscapeTextureDetail");
  return atexit(_E218_3);
}

//----- (006C4100) --------------------------------------------------------  // acclient.c:732464
int _E220_0()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_0, "Render.EnvironmentTextureDetail");
  return atexit(_E221_3);
}

//----- (006C4120) --------------------------------------------------------  // acclient.c:732471
int _E223_0()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_0, "Render.SceneryDrawDistance");
  return atexit(_E224_3);
}

//----- (006C4140) --------------------------------------------------------  // acclient.c:732478
int _E226_0()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_0, "Render.LandscapeDrawDistance");
  return atexit(_E227_3);
}

//----- (006C4160) --------------------------------------------------------  // acclient.c:732485
int _E229_0()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_0, "Render.ScreenBrightness");
  return atexit(_E230_3);
}

//----- (006C4180) --------------------------------------------------------  // acclient.c:732492
int _E232_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_0, "Render.AspectRatio");
  return atexit(_E233_2);
}

//----- (006C41A0) --------------------------------------------------------  // acclient.c:732499
int _E235_0()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_0, "Render.DisplayAdapter");
  return atexit(_E236_2);
}

//----- (006C41C0) --------------------------------------------------------  // acclient.c:732506
int _E238_0()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_0, "Render.MaxHardwareClass");
  return atexit(_E239_3);
}

//----- (006C41E0) --------------------------------------------------------  // acclient.c:732513
int _E241_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_0, "Render.AutomaticDegrades");
  return atexit(_E242_3);
}

//----- (006C4200) --------------------------------------------------------  // acclient.c:732520
int _E244_0()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_0, "Render.GraphicsPerformance");
  return atexit(_E245_2);
}

//----- (006C4220) --------------------------------------------------------  // acclient.c:732527
int _E247_0()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_0, "Render.DegradeDistance");
  return atexit(_E248_2);
}

//----- (006C4240) --------------------------------------------------------  // acclient.c:732534
int _E250_0()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_0, "Render.MultiPassAlpha");
  return atexit(_E251_2);
}

//----- (006C4260) --------------------------------------------------------  // acclient.c:732541
int _E253_0()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_0, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_836B34, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_836B38, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_836B3C, "Anisotropic");
  return atexit(_E254_3);
}

//----- (006C42B0) --------------------------------------------------------  // acclient.c:732551
int _E256_0()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_0, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836B44, "Low");
  PStringBase<char>::PStringBase<char>(&stru_836B48, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836B4C, "High");
  PStringBase<char>::PStringBase<char>(&stru_836B50, "VeryHigh");
  return atexit(_E257_1);
}

//----- (006C4310) --------------------------------------------------------  // acclient.c:732562
int _E259_0()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_0, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836B58, "Low");
  PStringBase<char>::PStringBase<char>(&stru_836B5C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836B60, "High");
  PStringBase<char>::PStringBase<char>(&stru_836B64, "VeryHigh");
  return atexit(_E260_2);
}

//----- (006C4370) --------------------------------------------------------  // acclient.c:732573
int _E262_0()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_836B6C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836B70, "High");
  return atexit(_E263_0);
}

//----- (006C43B0) --------------------------------------------------------  // acclient.c:732582
int _E265_0()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_0, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836B78, "Low");
  PStringBase<char>::PStringBase<char>(&stru_836B7C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836B80, "High");
  PStringBase<char>::PStringBase<char>(&stru_836B84, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_836B88, "Extreme");
  return atexit(_E266_0);
}

//----- (006C4420) --------------------------------------------------------  // acclient.c:732594
int _E268_0()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_0, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_836B90, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_836B94, "Wide");
  return atexit(_E269_0);
}

//----- (006C4460) --------------------------------------------------------  // acclient.c:732603
int _E1_3()
{
  return atexit(_E2_3);
}

//----- (00725EB0) --------------------------------------------------------  // acclient.c:823693
void __cdecl _E169_40()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725EE0) --------------------------------------------------------  // acclient.c:823706
void __cdecl _E172_38()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725F10) --------------------------------------------------------  // acclient.c:823719
void __cdecl _E175_35()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725F40) --------------------------------------------------------  // acclient.c:823732
void __cdecl _E178_35()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725F70) --------------------------------------------------------  // acclient.c:823745
void __cdecl _E181_35()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725FA0) --------------------------------------------------------  // acclient.c:823758
void __cdecl _E184_33()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725FD0) --------------------------------------------------------  // acclient.c:823771
void __cdecl _E187_32()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726000) --------------------------------------------------------  // acclient.c:823784
void __cdecl _E190_33()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726030) --------------------------------------------------------  // acclient.c:823797
void __cdecl _E193_32()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726060) --------------------------------------------------------  // acclient.c:823810
void __cdecl _E196_40()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726090) --------------------------------------------------------  // acclient.c:823823
void __cdecl _E199_31()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007260D0) --------------------------------------------------------  // acclient.c:823848
void __cdecl _E206_8()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726100) --------------------------------------------------------  // acclient.c:823861
void __cdecl _E209_3()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726130) --------------------------------------------------------  // acclient.c:823874
void __cdecl _E212_6()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726160) --------------------------------------------------------  // acclient.c:823887
void __cdecl _E215_2()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726190) --------------------------------------------------------  // acclient.c:823900
void __cdecl _E218_3()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007261C0) --------------------------------------------------------  // acclient.c:823913
void __cdecl _E221_3()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007261F0) --------------------------------------------------------  // acclient.c:823926
void __cdecl _E224_3()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726220) --------------------------------------------------------  // acclient.c:823939
void __cdecl _E227_3()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726250) --------------------------------------------------------  // acclient.c:823952
void __cdecl _E230_3()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726280) --------------------------------------------------------  // acclient.c:823965
void __cdecl _E233_2()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007262B0) --------------------------------------------------------  // acclient.c:823978
void __cdecl _E236_2()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007262E0) --------------------------------------------------------  // acclient.c:823991
void __cdecl _E239_3()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726310) --------------------------------------------------------  // acclient.c:824004
void __cdecl _E242_3()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726340) --------------------------------------------------------  // acclient.c:824017
void __cdecl _E245_2()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726370) --------------------------------------------------------  // acclient.c:824030
void __cdecl _E248_2()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007263A0) --------------------------------------------------------  // acclient.c:824043
void __cdecl _E251_2()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007263D0) --------------------------------------------------------  // acclient.c:824056
void __cdecl _E254_3()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_0;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00726410) --------------------------------------------------------  // acclient.c:824081
void __cdecl _E257_1()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_0;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00726450) --------------------------------------------------------  // acclient.c:824106
void __cdecl _E260_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_0;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00726490) --------------------------------------------------------  // acclient.c:824131
void __cdecl _E263_0()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_0;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007264D0) --------------------------------------------------------  // acclient.c:824156
void __cdecl _E266_0()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_0;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00726510) --------------------------------------------------------  // acclient.c:824181
void __cdecl _E269_0()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_836B98;
  v1 = 3;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00726550) --------------------------------------------------------  // acclient.c:824206
void __cdecl _E105_66()
{
  char *v0; // esi@1

  v0 = &Net_BindInterface.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Net_BindInterface.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726580) --------------------------------------------------------  // acclient.c:824219
void __cdecl sub_726580()
{
  char *v0; // esi@1

  v0 = &Net_ComputeUniquePort.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Net_ComputeUniquePort.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007265B0) --------------------------------------------------------  // acclient.c:824232
void __cdecl _E111_69()
{
  char *v0; // esi@1

  v0 = &Net_UserSpecifiedPort.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Net_UserSpecifiedPort.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007265E0) --------------------------------------------------------  // acclient.c:824245
void __cdecl _E114_74()
{
  char *v0; // esi@1

  v0 = &waveform_None_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726610) --------------------------------------------------------  // acclient.c:824258
void __cdecl sub_726610()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726640) --------------------------------------------------------  // acclient.c:824271
void __cdecl _E120_86()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726670) --------------------------------------------------------  // acclient.c:824284
void __cdecl _E123_57()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007266A0) --------------------------------------------------------  // acclient.c:824297
void __cdecl _E126_65()
{
  char *v0; // esi@1

  v0 = &waveform_Square_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007266D0) --------------------------------------------------------  // acclient.c:824310
void __cdecl _E129_59()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726700) --------------------------------------------------------  // acclient.c:824323
void __cdecl _E132_59()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726730) --------------------------------------------------------  // acclient.c:824336
void __cdecl _E135_67()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726760) --------------------------------------------------------  // acclient.c:824349
void __cdecl _E138_53()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726790) --------------------------------------------------------  // acclient.c:824362
void __cdecl _E141_55()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007267C0) --------------------------------------------------------  // acclient.c:824375
void __cdecl _E144_51()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007267F0) --------------------------------------------------------  // acclient.c:824388
void __cdecl _E147_50()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726820) --------------------------------------------------------  // acclient.c:824401
void __cdecl _E150_49()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

