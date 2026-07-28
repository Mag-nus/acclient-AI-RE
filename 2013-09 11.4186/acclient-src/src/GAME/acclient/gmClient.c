/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmClient
   Object     : GAME\acclient\gmClient.obj
   Functions  : 203
   Addresses  : 004015D0 - 00725A90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004015D0) --------------------------------------------------------  // acclient.c:61150
void __cdecl Serializer::SerializeBytes(char *io_buff, unsigned int i_size, Archive *io_archive)
{
  unsigned int v3; // eax@1

  v3 = Archive::GetBytes(io_archive, i_size);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      qmemcpy((void *)v3, io_buff, i_size);
    else
      qmemcpy(io_buff, (const void *)v3, i_size);
  }
}

//----- (00401640) --------------------------------------------------------  // acclient.c:61165
void __thiscall TransientArchive::TransientArchive(TransientArchive *this, Archive::tagPacking __formal)
{
  TransientArchive *v2; // esi@1
  SmartBuffer *v3; // eax@1
  SmartBuffer v4; // [sp+8h] [bp-Ch]@1

  v2 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  this->m_flags = 0;
  this->m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&this->m_buffer);
  v2->m_currOffset = 0;
  v2->m_pcUserDataHash = 0;
  v2->m_pVersionStack = 0;
  v2->vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
  SmartBuffer::SmartBuffer(&v4);
  Archive::InitForPacking((Archive *)&v2->vfptr, &Archive::SetCurrentCoreVersion, v3);
  SmartBuffer::ReleaseMasterBuffer(&v4);
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (004016B0) --------------------------------------------------------  // acclient.c:61188
void __thiscall TransientArchive::InitForPacking(TransientArchive *this, SmartBuffer *i_buffer)
{
  Archive::InitForPacking((Archive *)&this->vfptr, &Archive::SetCurrentCoreVersion, i_buffer);
}

//----- (004016D0) --------------------------------------------------------  // acclient.c:61194
void __thiscall TransientArchive::InitForUnpacking(TransientArchive *this, SmartBuffer *i_buffer)
{
  Archive::InitForUnpacking((Archive *)&this->vfptr, &Archive::SetCurrentCoreVersion, i_buffer);
}

//----- (004016F0) --------------------------------------------------------  // acclient.c:61200
void __thiscall PStringBase<char>::set(PStringBase<char> *this, PStringBase<char> *str)
{
  PStringBase<char> *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_charbuffer;
  if ( this->m_charbuffer != str->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = str->m_charbuffer;
    v2->m_charbuffer = str->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00401740) --------------------------------------------------------  // acclient.c:61224
void __cdecl GlobalRegistry::GetRegistry()
{
  GlobalRegistryInstance *v0; // eax@2
  GlobalRegistryInstance *v1; // eax@3

  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v0 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v0 )
    {
      GlobalRegistryInstance::GlobalRegistryInstance(v0);
      GlobalRegistry::s_pcGlobalRegistry = v1;
    }
    else
    {
      GlobalRegistry::s_pcGlobalRegistry = 0;
    }
  }
}

//----- (00401780) --------------------------------------------------------  // acclient.c:61245
void __userpurge gmClient::OnDDDEvent(gmClient *this@<ecx>, double a2@<st0>, DDDEvent evtNum, unsigned int nBytes)
{
  gmClient *v4; // esi@1

  v4 = this;
  Client::OnDDDEvent((Client *)&this->vfptr, a2, evtNum, nBytes);
  if ( evtNum == 4 )
    (*(void (__thiscall **)(int, PStringBase<char> *))&v4[-1].m_strKeymapFile.m_charbuffer[9].m_data[0])(
      &v4[-1].m_strKeymapFile,
      &PStringBase<char>::null_string);
}

//----- (004017B0) --------------------------------------------------------  // acclient.c:61258
bool __thiscall gmClient::UseTime(gmClient *this)
{
  Client *v1; // esi@1

  v1 = (Client *)this;
  ((void (*)(void))this->m_UIQueueManager->vfptr[1].IUnknown_Release)();
  return Client::UseTime(v1);
}

//----- (004017D0) --------------------------------------------------------  // acclient.c:61268
void gmClient::DetachUIPreferences()
{
  UIPreferences::DetachPreference(&Sound_SoundDisabled);
  UIPreferences::DetachPreference(&Sound_SoundVolume);
  UIPreferences::DetachPreference(&Sound_AmbientSoundDisabled);
  UIPreferences::DetachPreference(&Sound_AmbientSoundVolume);
  UIPreferences::DetachPreference(&Sound_InterfaceSoundDisabled);
  UIPreferences::DetachPreference(&Sound_InterfaceSoundVolume);
  UIPreferences::DetachPreference(&Sound_SoundFeatures);
  UIPreferences::DetachPreference(&Sound_PlaySoundOnlyWhenActive);
  UIPreferences::DetachPreference(&Misc_TooltipDelay);
  UIPreferences::DetachPreference(&Misc_TooltipEnable);
  UIPreferences::DetachPreference(&Render_TextureFiltering);
  UIPreferences::DetachPreference(&Render_BuildingDetailTextures);
  UIPreferences::DetachPreference(&Render_MultiPassAlpha);
  UIPreferences::DetachPreference(&Render_LandscapeTextureDetail);
  UIPreferences::DetachPreference(&Render_EnvironmentTextureDetail);
  UIPreferences::DetachPreference(&Render_SceneryDrawDistance);
  UIPreferences::DetachPreference(&Render_LandscapeDrawDistance);
  UIPreferences::DetachPreference(&Render_ScreenBrightness);
  UIPreferences::DetachPreference(&Display_FullScreen_0);
  UIPreferences::DetachPreference(&Display_SyncToRefresh_0);
  UIPreferences::DetachPreference(&Display_Resolution_0);
  UIPreferences::DetachPreference(&Input_MouseLookSensitivity);
  UIPreferences::DetachPreference(&Input_InvertMouseLookYAxis);
  UIPreferences::DetachPreference(&Camera_AlignToSlope);
  UIPreferences::DetachPreference(&Camera_Stiffness);
  UIPreferences::DetachPreference(&Camera_AdjustmentSpeed);
  UIPreferences::DetachPreference(&UI_ChatFontFace);
  UIPreferences::DetachPreference(&UI_ChatFontSize);
}

//----- (004018F0) --------------------------------------------------------  // acclient.c:61301
void __cdecl gmClient::GRPCallback_OnFontPreferenceChanged()
{
  CM_UI::SendNotice_FontSettingsChanged(gmClient::sm_nFontFace, gmClient::sm_nFontSize);
}

//----- (00401910) --------------------------------------------------------  // acclient.c:61307
bool __thiscall PStringBase<char>::operator==(PStringBase<char> *this, PStringBase<char> *rhs)
{
  PSRefBufferCharData<char> *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@2
  int v5; // edx@2
  bool result; // al@5

  v2 = rhs->m_charbuffer;
  v3 = this->m_charbuffer;
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[12] == *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12]
    && ((v4 = *(_DWORD *)&v3[-1].m_data[8], v5 = *(_DWORD *)&v2[-1].m_data[8], v4 == v5) || v4 == -1 || v5 == -1) )
    result = strcmp(v3->m_data, v2->m_data) == 0;
  else
    result = 0;
  return result;
}

//----- (00401990) --------------------------------------------------------  // acclient.c:61326
void __cdecl Serializer::SerializeObject(char *io_object, Archive *io_archive)
{
  char *v2; // eax@1

  Archive::CheckAlignment(io_archive, 1u);
  v2 = (char *)Archive::GetBytes(io_archive, 1u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (004019D0) --------------------------------------------------------  // acclient.c:61342
void __cdecl Serializer::SerializeObject(unsigned __int16 *io_object, Archive *io_archive)
{
  unsigned __int16 *v2; // eax@1

  Archive::CheckAlignment(io_archive, 2u);
  v2 = (unsigned __int16 *)Archive::GetBytes(io_archive, 2u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (00401A10) --------------------------------------------------------  // acclient.c:61358
unsigned int __cdecl Tokenize(const char *_string)
{
  unsigned int result; // eax@2

  if ( _string )
    result = compute_str_hash((char *)_string);
  else
    result = 0;
  return result;
}

//----- (00401A30) --------------------------------------------------------  // acclient.c:61370
void __thiscall PStringBase<char>::PStringBase<char>(PStringBase<char> *this)
{
  volatile LONG *v1; // ST00_4@1

  v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v1);
}

//----- (00401A50) --------------------------------------------------------  // acclient.c:61380
PStringBase<unsigned short> *__thiscall PStringBase<unsigned short>::operator=(PStringBase<unsigned short> *this, const unsigned __int16 *rhs)
{
  PStringBase<unsigned short> *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  int v4; // edi@2
  PSRefBufferCharData<unsigned short> *v5; // eax@5

  v2 = this;
  v3 = this->m_charbuffer;
  if ( this->m_charbuffer != *(PSRefBufferCharData<unsigned short> **)rhs )
  {
    v4 = (int)&v3[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(PSRefBufferCharData<unsigned short> **)rhs;
    v2->m_charbuffer = *(PSRefBufferCharData<unsigned short> **)rhs;
    InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
  }
  return v2;
}

//----- (00401AA0) --------------------------------------------------------  // acclient.c:61402
void __thiscall PStringBase<unsigned short>::PStringBase<unsigned short>(PStringBase<unsigned short> *this)
{
  volatile LONG *v1; // ST00_4@1

  v1 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v1);
}

//----- (00401AC0) --------------------------------------------------------  // acclient.c:61412
HRESULT __stdcall Interface::IUnknown_QueryInterface(Interface *this, _GUID *iid, void **ppvObject)
{
  return *(_DWORD *)((int (__stdcall *)(Interface **, _GUID *, void **))this->vfptr->QueryInterface)(
                      &this,
                      iid,
                      ppvObject);
}

//----- (00401AE0) --------------------------------------------------------  // acclient.c:61421
int __stdcall Interface::IUnknown_AddRef(Interface *this)
{
  return ((int (*)(void))this->vfptr->AddRef)();
}

//----- (00401AF0) --------------------------------------------------------  // acclient.c:61427
int __stdcall Interface::IUnknown_Release(Interface *this)
{
  return ((int (*)(void))this->vfptr->Release)();
}

//----- (00401B00) --------------------------------------------------------  // acclient.c:61433
Turbine_RefCount *__thiscall Turbine_RefCount::scalar_deleting_destructor(Turbine_RefCount *this, unsigned int a2)
{
  Turbine_RefCount *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);

//----- (00401B20) --------------------------------------------------------  // acclient.c:61446
void __thiscall gmClient::~gmClient(gmClient *this)
{
  gmClient *v1; // esi@1
  char *v2; // edi@1
  char *v3; // ebp@1
  int v4; // edi@4
  int v5; // edi@7
  int v6; // edi@10
  int v7; // edi@13
  int v8; // edi@16
  int v9; // edi@19

  v1 = this;
  v2 = &this->m_startChar.m_charbuffer[-2].m_data[12];
  v3 = (char *)&this->pNetAuth_;
  this[-1].m_strKeymapFile.m_charbuffer = (PSRefBufferCharData<char> *)&gmClient::vftable;
  *(_DWORD *)&this[-1].m_bKeymapLoaded = &gmClient::vftable;
  this->vfptr = (InterfaceVtbl *)&gmClient::vftable;
  this->m_ErrorText.m_charbuffer = (PSRefBufferCharData<char> *)&gmClient::vftable;
  this->m_CmdChars.m_charbuffer = (PSRefBufferCharData<char> *)&gmClient::vftable;
  this->pNetAuth_ = (NetAuthenticator *)&gmClient::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v4 = (int)&v1->vfptr[-1].RecvNotice_TextTag_DIDClick;
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = *((_DWORD *)&v1->m_running_check + 1) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = (int)((char *)v1->m_running_check.m_UniqueClientSemaphore - 20);
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = (int)((char *)&v1->packControl_[-1].lastEmpty_ + 4);
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = (int)&v1->m_logonEventQueue[-3].tail_;
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = (int)&v1->smartbox_[-1].num_cells;
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  NoticeHandler::~NoticeHandler((NoticeHandler *)(v1 != (gmClient *)28 ? (unsigned int)v3 : 0));
  Client::~Client((Client *)&v1->vfptr);
}
// 792B70: using guessed type bool (__thiscall *gmClient::vftable)(DBObj *this);
// 792BD0: using guessed type int (*gmClient::vftable)();
// 792BE0: using guessed type int (*gmClient::vftable)();
// 792BEC: using guessed type int (__stdcall *gmClient::vftable)(char);
// 792BF8: using guessed type void (__thiscall *gmClient::vftable)(ArgumentParser *__hidden this);
// 792C48: using guessed type __int32 (__stdcall *gmClient::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00401C50) --------------------------------------------------------  // acclient.c:61498
void __thiscall CPluginPrototype::OnPluggedIn(CPluginPrototype *this, CPluginManager *pManager)
{
  this->m_pManager = pManager;
}

//----- (00401C60) --------------------------------------------------------  // acclient.c:61504
accountID *__thiscall Client::GetAccountName(Client *this)
{
  return &this->m_account;
}

//----- (00401C70) --------------------------------------------------------  // acclient.c:61510
PStringBase<char> *__thiscall Client::GetHostName(Client *this)
{
  return &this->m_hostName;
}

//----- (00401CA0) --------------------------------------------------------  // acclient.c:61528
PStringBase<unsigned short> *__thiscall Client::GetWorldName(Client *this)
{
  return &this->m_worldName;
}

//----- (00401CB0) --------------------------------------------------------  // acclient.c:61534
int __thiscall gmClient::vector_deleting_destructor(void *this, char a2)
{
  return gmClient::scalar_deleting_destructor((gmClient *)((char *)this - 8), a2);
}

//----- (00401CC0) --------------------------------------------------------  // acclient.c:61540
int __thiscall gmClient::vector_deleting_destructor(void *this, char a2)
{
  return gmClient::scalar_deleting_destructor((gmClient *)((char *)this - 12), a2);
}

//----- (00401CD0) --------------------------------------------------------  // acclient.c:61546
TResult *__thiscall Client::QueryInterface(Client *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppObject)
{
  TResult *v4; // eax@6

  if ( i_rcInterface->m_data1 == -559038737
    && *(_DWORD *)&i_rcInterface->m_data2 == *(_DWORD *)&Interface_InterfaceType_1.m_data2
    && *(_DWORD *)&i_rcInterface->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_1.m_data4[0]
    && *(_DWORD *)&i_rcInterface->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_1.m_data4[4]
    && this )
  {
    *o_ppObject = this;
    ((void (*)(void))this->vfptr->AddRef)();
    v4 = result;
    result->m_val = 0;
  }
  else
  {
    v4 = result;
    result->m_val = -2147467262;
  }
  return v4;
}

//----- (00401D30) --------------------------------------------------------  // acclient.c:61570
LONG __thiscall Client::AddRef(Client *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (00401D40) --------------------------------------------------------  // acclient.c:61576
unsigned int __thiscall Client::Release(Client *this)
{
  Client *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    v1->vfptr->__vecDelDtor(&v1->vfptr, 1);
  return v2;
}

//----- (00401D70) --------------------------------------------------------  // acclient.c:61589
unsigned int __thiscall ReferenceCountTemplate<1048576,2>::Release(ReferenceCountTemplate<1048576,2> *this)
{
  char *v1; // esi@1
  unsigned int result; // eax@2

  v1 = (char *)&this->m_cRef;
  if ( InterlockedDecrement((volatile LONG *)&this->m_cRef) )
    result = *(_DWORD *)v1;
  else
    result = 0;
  return result;
}

//----- (00401D90) --------------------------------------------------------  // acclient.c:61603
void __thiscall gmClient::Cleanup(gmClient *this)
{
  gmClient *v1; // ebx@1
  GlobalEventHandler *v2; // eax@1
  int v3; // ecx@3
  CInputManager *v4; // edi@9
  PSRefBufferCharData<char> *v5; // ST0C_4@9
  char *v6; // esi@9
  char *v7; // esi@12
  PStringBase<char> strKeymapFilePath; // [sp+Ch] [bp-8h]@9
  PStringBase<char> strPreferenceFile; // [sp+10h] [bp-4h]@9

  v1 = this;
  gmClient::DetachUIPreferences();
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->UnRegisterNoticeHandler((NoticeRegistrar *)v2, 100002u, (NoticeHandler *)v3);
  }
  if ( ICIDM::s_cidm )
  {
    if ( *(_DWORD *)&v1->m_strKeymapFile.m_charbuffer[-1].m_data[12] != 1 && v1->m_bKeymapLoaded )
    {
      strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
      strKeymapFilePath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PSUtils::get_directory(&strKeymapFilePath, &strPreferenceFile);
      PSUtils::path_append(&strKeymapFilePath, &v1->m_strKeymapFile);
      v4 = ICIDM::s_cidm;
      v5 = strKeymapFilePath.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&strKeymapFilePath.m_charbuffer[-1]);
      ((void (__thiscall *)(CInputManager *, PSRefBufferCharData<char> *))v4->vfptr->SaveKeyMap)(v4, v5);
      v6 = &strKeymapFilePath.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strKeymapFilePath.m_charbuffer[-1]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    ((void (*)(void))ICIDM::s_cidm->vfptr->ClearKeyMap)();
  }
  UserPreferences::UnregisterPreference(&Input_KeymapFile);
  UserPreferences::UnregisterPreference(&UI_ChatFontFace);
  UserPreferences::UnregisterPreference(&UI_ChatFontSize);
  Client::Cleanup((Client *)&v1->vfptr);
}

//----- (00401ED0) --------------------------------------------------------  // acclient.c:61656
NetError *__thiscall gmClient::Connect(gmClient *this, NetError *result)
{
  Client::Connect((Client *)&this->vfptr, result);
  return result;
}

//----- (00401EF0) --------------------------------------------------------  // acclient.c:61663
void __thiscall gmClient::SetKeyMapFileName(gmClient *this, PStringBase<char> *i_strKeymapFilename)
{
  gmClient *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_strKeymapFile.m_charbuffer;
  if ( v3 != i_strKeymapFilename->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = i_strKeymapFilename->m_charbuffer;
    v2->m_strKeymapFile.m_charbuffer = i_strKeymapFilename->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00401F40) --------------------------------------------------------  // acclient.c:61687
void __userpurge UserPreferences::RegisterPreference(PStringBase<char> *_pVariable@<eax>, void *a2@<ecx>, PStringBase<char> *_Name, PStringBase<char> *_Description, void (__cdecl *_OnChangedCallbackFP)(PStringBase<char> *), const unsigned int _NumChoices, PStringBase<char> *_pChoiceStrings, const unsigned int *_pChoiceValues)
{
  PStringBase<char> *v8; // esi@1
  GlobalRegistryInstance *v9; // eax@3
  GlobalRegistryInstance *v10; // eax@4
  int v11; // eax@9

  v8 = _Name;
  if ( a2 )
    GlobalRegistry::RegisterVariableInternal(
      a2,
      GRVDataType_PString,
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

//----- (00401FC0) --------------------------------------------------------  // acclient.c:61724
void __userpurge UserPreferences::RegisterPreference(unsigned int *_pVariable@<eax>, void *a2@<ecx>, PStringBase<char> *_Name, PStringBase<char> *_Description, void (__cdecl *_OnChangedCallbackFP)(PStringBase<char> *), const unsigned int _NumChoices, PStringBase<char> *_pChoiceStrings, const unsigned int *_pChoiceValues)
{
  PStringBase<char> *v8; // esi@1
  GlobalRegistryInstance *v9; // eax@3
  GlobalRegistryInstance *v10; // eax@4
  int v11; // eax@9

  v8 = _Name;
  if ( a2 )
    GlobalRegistry::RegisterVariableInternal(
      a2,
      GRVDataType_UInt32,
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

//----- (00402040) --------------------------------------------------------  // acclient.c:61761
void __thiscall Client::SetHostName(Client *this, PStringBase<char> *newName)
{
  Client *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_hostName.m_charbuffer;
  if ( v3 != newName->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = newName->m_charbuffer;
    v2->m_hostName.m_charbuffer = newName->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00402090) --------------------------------------------------------  // acclient.c:61785
void __thiscall Client::SetWorldName(Client *this, PStringBase<unsigned short> *_worldName)
{
  Client *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<unsigned short> *v5; // eax@5

  v2 = this;
  v3 = this->m_worldName.m_charbuffer;
  if ( v3 != _worldName->m_charbuffer )
  {
    v4 = (int)&v3[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = _worldName->m_charbuffer;
    v2->m_worldName.m_charbuffer = _worldName->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
  }
}

//----- (004020E0) --------------------------------------------------------  // acclient.c:61809
void __thiscall CommandLineArg::~CommandLineArg(CommandLineArg *this)
{
  CommandLineArg *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4

  v1 = this;
  v2 = &this->Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->LongVersion.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (00402130) --------------------------------------------------------  // acclient.c:61828
char __thiscall PStringBase<unsigned short>::allocate_ref_buffer(PStringBase<unsigned short> *this, unsigned int len)
{
  int v2; // esi@2
  unsigned int v3; // ST0C_4@4
  signed int v9; // eax@4
  void *v10; // eax@2
  char result; // al@10
  PStringBase<unsigned short> *v12; // [sp+4h] [bp-8h]@1

  v12 = this;
  if ( len >= 0x10 )
  {
    if ( len > 0x10000 )
    {
      v9 = (len & 0xFFFF0000) + 0x10000;
    }
    else
    {
      v3 = 2 * len;
      __asm { bsr     this, [esp+0Ch+var_4] }
      v9 = 1 << (_EAX + 1);
    }
    v2 = v9 - 16;
    if ( v9 == 16 )
      v10 = operator new[](0x34u);
    else
      v10 = operator new[](2 * v2 + 52);
  }
  else
  {
    v2 = 0;
    v10 = operator new[](0x34u);
  }
  if ( v10 )
  {
    *((_DWORD *)v10 + 1) = 1;
    *(_DWORD *)v10 = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)v10 + 4) = 1;
    *((_DWORD *)v10 + 2) = 1;
    *((_DWORD *)v10 + 3) = -1;
    *((_WORD *)v10 + 10) = 0;
    v12->m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)v10 + 20);
    *(_DWORD *)&v12->m_charbuffer[-1].m_data[14] = len + 1;
    *(_DWORD *)&v12->m_charbuffer[-1].m_data[10] = v2 + 16;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (004021F0) --------------------------------------------------------  // acclient.c:61883
int __thiscall PStringBase<char>::vsprintf(PStringBase<char> *this, const char *fmt, char *args)
{
  PStringBase<char> *v3; // edi@1
  int v4; // ebx@1
  int v5; // esi@1

  v3 = this;
  v4 = __vscprintf(fmt, args);
  v5 = (int)&v3->m_charbuffer[-2].m_data[12];
  PStringBase<char>::allocate_ref_buffer(v3, v4);
  __vsnprintf(v3->m_charbuffer->m_data, v4 + 1, fmt, args);
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return v4;
}

//----- (00402260) --------------------------------------------------------  // acclient.c:61900
void __thiscall PStringBase<char>::Serialize(PStringBase<char> *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  PStringBase<char> *v3; // edi@1
  unsigned int v4; // ebx@4

  v2 = io_archive;
  v3 = this;
  if ( io_archive->m_flags & 1 )
    io_archive = (Archive *)(*(_DWORD *)&this->m_charbuffer[-1].m_data[12] - 1);
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v2);
  if ( !((v2->m_flags >> 2) & 1) )
  {
    v4 = (unsigned int)io_archive;
    if ( ~LOBYTE(v2->m_flags) & 1 )
    {
      if ( v4 > Archive::GetSizeLeft(v2) )
      {
        Archive::RaiseError(v2);
        return;
      }
      ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v3->m_charbuffer[-2].m_data[12]);
      PStringBase<char>::allocate_ref_buffer(v3, v4);
      v3->m_charbuffer->m_data[v4] = 0;
    }
    Serializer::SerializeBytes(v3->m_charbuffer->m_data, v4, v2);
  }
}

//----- (004022F0) --------------------------------------------------------  // acclient.c:61930
void __thiscall PStringBase<unsigned short>::append_n_chars(PStringBase<unsigned short> *this, const unsigned __int16 *str, unsigned int count)
{
  const unsigned __int16 *v3; // edx@1
  PStringBase<unsigned short> *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // eax@4
  int v6; // ebx@4
  unsigned int v7; // ecx@4
  int v8; // edi@7

  v3 = str;
  v4 = this;
  if ( str && *str && count )
  {
    v5 = this->m_charbuffer;
    v6 = *(_DWORD *)&this->m_charbuffer[-1].m_data[14];
    v7 = v6 + count;
    if ( *(_DWORD *)&v5[-1].m_data[8] != 1 || v7 > *(_DWORD *)&v5[-1].m_data[10] )
    {
      v8 = (int)&v5[-1].m_data[6];
      PStringBase<unsigned short>::allocate_ref_buffer(v4, v7 - 1);
      _wcscpy(v4->m_charbuffer->m_data, (const wchar_t *)(v8 + 20));
      ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)v8);
      v3 = str;
    }
    else
    {
      *(_DWORD *)&v5[-1].m_data[14] = v7;
      *(_DWORD *)&v4->m_charbuffer[-1].m_data[12] = -1;
    }
    _wcsncpy((wchar_t *)v4->m_charbuffer + v6 - 1, v3, count);
    v4->m_charbuffer->m_data[*(_DWORD *)&v4->m_charbuffer[-1].m_data[14] - 1] = 0;
  }
}

//----- (00402380) --------------------------------------------------------  // acclient.c:61965
int __thiscall PStringBase<unsigned short>::vsprintf(PStringBase<unsigned short> *this, const unsigned __int16 *fmt, char *args)
{
  PStringBase<unsigned short> *v3; // edi@1
  int v4; // ebx@1
  int v5; // esi@1

  v3 = this;
  v4 = __vscwprintf(fmt, args);
  v5 = (int)&v3->m_charbuffer[-1].m_data[6];
  PStringBase<unsigned short>::allocate_ref_buffer(v3, v4);
  __vsnwprintf(v3->m_charbuffer->m_data, v4 + 1, fmt, args);
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return v4;
}

//----- (004023F0) --------------------------------------------------------  // acclient.c:61982
TResult *__thiscall ClassFactoryForceClient_ClassType::QueryInterface(ClassFactoryForceClient_ClassType *this, TResult *result, Turbine_GUID *_rInterfaceType, void **_ppOutInterface)
{
  ClassFactoryForceClient_ClassType *v4; // esi@1
  TResult *v5; // eax@10

  v4 = this;
  if ( (_rInterfaceType->m_data1 == 1244181156
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&IObjectFactory_InterfaceType_0.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&IObjectFactory_InterfaceType_0.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&IObjectFactory_InterfaceType_0.m_data4[4]
     || _rInterfaceType->m_data1 == -559038737
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&Interface_InterfaceType_1.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_1.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_1.m_data4[4])
    && this )
  {
    this->vfptr->AddRef((Interface *)this);
    *_ppOutInterface = v4;
    v5 = result;
    result->m_val = 0;
  }
  else
  {
    v5 = result;
    result->m_val = -2147467262;
  }
  return v5;
}

//----- (00402490) --------------------------------------------------------  // acclient.c:62018
int __thiscall gmClient::scalar_deleting_destructor(gmClient *this, char a2)
{
  gmClient *v2; // esi@1
  int result; // eax@1

  v2 = this;
  gmClient::~gmClient(this);
  result = (int)&v2[-1].m_strKeymapFile;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_strKeymapFile);
    result = (int)&v2[-1].m_strKeymapFile;
  }
  return result;
}

//----- (004024C0) --------------------------------------------------------  // acclient.c:62035
char __thiscall ArgumentParser::CommandLineArgList::AddCmd(ArgumentParser::CommandLineArgList *this, int type, char ShortCmd, PStringBase<char> *LongCmd, PStringBase<char> *Descript, void *Dest, unsigned int dwParam, unsigned int dwExtraData)
{
  ArgumentParser::CommandLineArgList *v8; // esi@1
  char v9; // al@1
  char *v10; // esi@1
  char v11; // bl@1
  char *v12; // esi@4
  CommandLineArg data; // [sp+Ch] [bp-1Ch]@1

  data.ArgType = type;
  data.LongVersion.m_charbuffer = LongCmd->m_charbuffer;
  v8 = this;
  data.ShortVersion = ShortCmd;
  InterlockedIncrement((volatile LONG *)&data.LongVersion.m_charbuffer[-1]);
  data.Description.m_charbuffer = Descript->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&data.Description.m_charbuffer[-1]);
  data.VariableToModify = Dest;
  data.ValueToStore = dwParam;
  data.UserData = dwExtraData;
  v9 = ArgumentParser::CommandLineArgList::add(v8, &data);
  v10 = &data.Description.m_charbuffer[-2].m_data[12];
  v11 = v9;
  if ( !InterlockedDecrement((volatile LONG *)&data.Description.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v12 = &data.LongVersion.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&data.LongVersion.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return v11;
}

//----- (00402570) --------------------------------------------------------  // acclient.c:62066
int PStringBase<char>::sprintf(PStringBase<char> *this, const char *fmt, ...)
{
  va_list va; // [sp+Ch] [bp+Ch]@1

  va_start(va, fmt);
  return PStringBase<char>::vsprintf(this, fmt, va);
}

//----- (00402590) --------------------------------------------------------  // acclient.c:62075
void __thiscall PStringBase<unsigned short>::PStringBase<unsigned short>(PStringBase<unsigned short> *this, const unsigned __int16 *str)
{
  PStringBase<unsigned short> *v2; // esi@1
  unsigned int v3; // eax@3
  volatile LONG *v4; // ST04_4@4

  v2 = this;
  if ( str && *str )
  {
    v3 = _wcslen(str);
    PStringBase<unsigned short>::allocate_ref_buffer(v2, v3);
    _wcscpy(v2->m_charbuffer->m_data, str);
  }
  else
  {
    v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    this->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
}

//----- (004025F0) --------------------------------------------------------  // acclient.c:62097
void __thiscall PStringBase<unsigned short>::append_string(PStringBase<unsigned short> *this, PStringBase<unsigned short> *str)
{
  int v2; // edx@1

  v2 = *(_DWORD *)&str->m_charbuffer[-1].m_data[14];
  if ( v2 != 1 )
    PStringBase<unsigned short>::append_n_chars(this, str->m_charbuffer->m_data, v2 - 1);
}

//----- (00402610) --------------------------------------------------------  // acclient.c:62107
int PStringBase<unsigned short>::sprintf(PStringBase<unsigned short> *this, const unsigned __int16 *fmt, ...)
{
  va_list va; // [sp+Ch] [bp+Ch]@1

  va_start(va, fmt);
  return PStringBase<unsigned short>::vsprintf(this, fmt, va);
}

//----- (00402630) --------------------------------------------------------  // acclient.c:62116
void __thiscall gmClient::gmClient(gmClient *this)
{
  gmClient *v1; // esi@1
  volatile LONG *v2; // ST18_4@1
  volatile LONG *v3; // ST18_4@1
  volatile LONG *v4; // ST18_4@1
  volatile LONG *v5; // ST18_4@1
  volatile LONG *v6; // ST18_4@1
  volatile LONG *v7; // ST18_4@1
  volatile LONG *v8; // ST18_4@1
  char *v9; // ebx@4
  unsigned int v10; // eax@10
  PSRefBufferCharData<char> *v11; // ebx@10
  int v12; // ebx@11
  PSRefBufferCharData<char> *v13; // eax@14
  char *v14; // edi@15
  DiskSpace *v15; // ecx@15
  char *v16; // edi@18
  PStringBase<char> strPreferenceFile; // [sp+10h] [bp-110h]@2
  int v18; // [sp+14h] [bp-10Ch]@2
  PStringBase<char> strDirectory; // [sp+18h] [bp-108h]@1
  char buffer[260]; // [sp+1Ch] [bp-104h]@8

  v1 = this;
  Client::Client((Client *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  v1->vfptr = (InterfaceVtbl *)&gmClient::vftable;
  v1->vfptr = (ArgumentParserVtbl *)&gmClient::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&gmClient::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmClient::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&gmClient::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmClient::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_startChar.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_createChar.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strKeymapFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->m_bKeymapLoaded = 0;
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strZoneTicket.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
  v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strGLSTicket.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v6);
  v7 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_wstrMigrationURL.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v7);
  v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strVGPassword.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v8);
  strDirectory.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !PSUtils::get_cwd(&strDirectory) )
    goto LABEL_23;
  strPreferenceFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&strPreferenceFile, "%s\\UserPreferences.ini", strDirectory.m_charbuffer);
  PSUtils::cleanup_filename(&strPreferenceFile, 0);
  BYTE3(v18) = PSUtils::check_access(&strPreferenceFile, 0);
  if ( BYTE3(v18) )
    PStringBase<unsigned short>::operator=(
      (PStringBase<unsigned short> *)&v1->m_preferencesFile,
      (const unsigned __int16 *)&strPreferenceFile);
  v9 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( !BYTE3(v18) )
  {
LABEL_23:
    if ( SHGetSpecialFolderPathA(0, buffer, 5, 1) )
    {
      PStringBase<char>::sprintf(&strDirectory, "%s\\Asheron's Call", buffer);
      PSUtils::create_directory(&strDirectory);
      PStringBase<char>::sprintf(&v1->m_preferencesFile, "%s\\UserPreferences.ini", strDirectory.m_charbuffer);
    }
  }
  v10 = _wcslen(L"http://acbm.turbinegames.com/IISAcBillingMigration/IISAcBillingMigration.dll?ac1");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&strPreferenceFile, v10);
  _wcscpy(
    (wchar_t *)strPreferenceFile.m_charbuffer,
    L"http://acbm.turbinegames.com/IISAcBillingMigration/IISAcBillingMigration.dll?ac1");
  v11 = (PSRefBufferCharData<char> *)v1->m_wstrMigrationURL.m_charbuffer;
  if ( v11 != strPreferenceFile.m_charbuffer )
  {
    v12 = (int)&v11[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    v13 = strPreferenceFile.m_charbuffer;
    v1->m_wstrMigrationURL.m_charbuffer = (PSRefBufferCharData<unsigned short> *)strPreferenceFile.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v13[-1]);
  }
  v14 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  gmNoticeHandler::RecvNotice_PrevSpellSelection(v15);
  v16 = &strDirectory.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strDirectory.m_charbuffer[-1]) )
  {
    if ( v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  }
}
// 792B70: using guessed type bool (__thiscall *gmClient::vftable)(DBObj *this);
// 792BD0: using guessed type int (*gmClient::vftable)();
// 792BE0: using guessed type int (*gmClient::vftable)();
// 792BEC: using guessed type int (__stdcall *gmClient::vftable)(char);
// 792BF8: using guessed type void (__thiscall *gmClient::vftable)(ArgumentParser *__hidden this);
// 792C48: using guessed type __int32 (__stdcall *gmClient::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

//----- (004028B0) --------------------------------------------------------  // acclient.c:62231
void __thiscall gmClient::BuildCommandLineArgs(gmClient *this, ArgumentParser::CommandLineArgList *Args)
{
  gmClient *v2; // ebp@1
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
  PStringBase<char> LongCmd; // [sp+30h] [bp-8h]@1
  PStringBase<char> Descript; // [sp+34h] [bp-4h]@1

  v2 = this;
  PStringBase<char>::PStringBase<char>(&Descript, "<name> : Character Name you would like to play");
  PStringBase<char>::PStringBase<char>(&LongCmd, "user");
  v3 = Args;
  ArgumentParser::CommandLineArgList::AddCmd(Args, 50, 117, &LongCmd, &Descript, &v2->vfptr, 0, 0);
  v4 = &LongCmd.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LongCmd.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<name> : Character Name you would like to create/play");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "create");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 50, 114, (PStringBase<char> *)&Args, &Descript, &v2->m_startChar, 0, 0);
  v6 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<string>: Specify ticket data.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "zoneticket");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    50,
    122,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_bKeymapLoaded,
    0,
    0);
  v8 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<ticket> : Raw GLS ticket data.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "glsticketdirect");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    50,
    0,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_strZoneTicket,
    0,
    0);
  v10 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "Tells the client to use GLS authentication.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "glsticket");
  ArgumentParser::CommandLineArgList::AddCmd(v3, 1, 0, (PStringBase<char> *)&Args, &Descript, 0, 0, 0);
  v12 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v13 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<name> : Location of the account migration server");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "migrationurl");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    58,
    0,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_strGLSTicket,
    0,
    0);
  v14 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  PStringBase<char>::PStringBase<char>(&Descript, "<pw> : Vanguard pw.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&Args, "vgpassword");
  ArgumentParser::CommandLineArgList::AddCmd(
    v3,
    50,
    118,
    (PStringBase<char> *)&Args,
    &Descript,
    &v2->m_wstrMigrationURL,
    0,
    0);
  v16 = (char *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&Args[-1].m_ShortNamesHash.m_intrusiveTable.m_buckets) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  v17 = &Descript.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Descript.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  Client::BuildCommandLineArgs((Client *)&v2->vfptr, v3);
}

//----- (00402C10) --------------------------------------------------------  // acclient.c:62353
char __thiscall gmClient::EvaluateCommandLineArg(gmClient *this, CommandLineArg *ArgData, PStringBase<char> *arg)
{
  CommandLineArg *v3; // esi@1
  gmClient *v4; // ebp@1
  char result; // al@1
  bool v6; // al@2
  char *v7; // esi@2
  bool v8; // bl@2
  bool v9; // bl@6
  char *v10; // esi@6
  char *v11; // esi@9
  char *v12; // esi@13
  char *v13; // esi@16
  PStringBase<char> szName; // [sp+10h] [bp-8h]@6
  char v15; // [sp+14h] [bp-4h]@6

  v3 = ArgData;
  v4 = this;
  result = Client::EvaluateCommandLineArg((Client *)&this->vfptr, ArgData, arg);
  LOBYTE(arg) = result;
  if ( result )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&ArgData, "glsticket");
    v6 = PStringBase<char>::operator==(&v3->LongVersion, (PStringBase<char> *)&ArgData);
    v7 = (char *)&ArgData[-1].LongVersion;
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)&ArgData[-1].Description) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    if ( v8 )
    {
      PStringBase<char>::PStringBase<char>(&szName, "GLSTicket");
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&ArgData, "Software\\Turbine\\ac1");
      v9 = RegEdit::QueryStrValue(
             (RegEdit *)&v15,
             (PStringBase<char> *)&ArgData,
             &szName,
             &v4->m_strZoneTicket,
             (HKEY__ *)0x80000001);
      v10 = (char *)&ArgData[-1].LongVersion;
      if ( !InterlockedDecrement((volatile LONG *)&ArgData[-1].Description) && v10 )
        (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
      v11 = &szName.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&szName.m_charbuffer[-1]) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      if ( v9 )
      {
        PStringBase<char>::PStringBase<char>(&szName, "GLSTicket");
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&ArgData, "Software\\Turbine\\ac1");
        RegEdit::DeleteValue((RegEdit *)&v15, (PStringBase<char> *)&ArgData, &szName, (HKEY__ *)0x80000001);
        v12 = (char *)&ArgData[-1].LongVersion;
        if ( !InterlockedDecrement((volatile LONG *)&ArgData[-1].Description) && v12 )
          (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
        v13 = &szName.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&szName.m_charbuffer[-1]) )
        {
          if ( v13 )
            (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
        }
      }
    }
    result = (char)arg;
  }
  return result;
}

//----- (00402D80) --------------------------------------------------------  // acclient.c:62419
char __thiscall gmClient::OnCommandLineEvaluationDone(gmClient *this)
{
  gmClient *v1; // edi@1
  char *v2; // esi@1
  char *v3; // esi@5
  PStringBase<char> v5; // [sp+4h] [bp-4h]@1

  v5.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  v2 = (char *)(&this[-1].m_strVGPassword + 1);
  if ( *(_DWORD *)(*(_DWORD *)(*(int (__thiscall **)(PStringBase<char> *))(*((_DWORD *)&this[-1].m_strVGPassword + 1)
                                                                         + 52))(&this[-1].m_strVGPassword + 1)
                 + 8) == 1 )
  {
    PStringBase<char>::PStringBase<char>(&v5, "You must specify an account name");
  }
  else
  {
    if ( *(_DWORD *)(*(_DWORD *)(*(int (__thiscall **)(char *))(*(_DWORD *)v2 + 60))(v2) - 4) != 1 )
      return 1;
    PStringBase<char>::PStringBase<char>(&v5, "You must specify a host name");
  }
  ((void (__thiscall *)(gmClient *, PStringBase<char> *))v1->vfptr[1].IUnknown_Release)(v1, &v5);
  v3 = &v5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v5.m_charbuffer[-1]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
  return 0;
}

//----- (00402E00) --------------------------------------------------------  // acclient.c:62452
char __thiscall gmClient::InitKeymap(gmClient *this, PStringBase<char> *i_strKeymapFilename)
{
  CInputManager *v2; // esi@1
  gmClient *v3; // ebx@1
  PSRefBufferCharData<char> *v4; // ST0C_4@7
  char *v5; // esi@9
  volatile LONG *v6; // ST0C_4@9
  char *v7; // esi@12
  char result; // al@15
  PStringBase<char> strKeymapFilePath; // [sp+10h] [bp-Ch]@3
  PStringBase<char> new_extension; // [sp+14h] [bp-8h]@6
  PStringBase<char> strPreferenceFile; // [sp+18h] [bp-4h]@3

  v2 = ICIDM::s_cidm;
  v3 = this;
  if ( ICIDM::s_cidm
    && (unsigned __int8)(*(int (__thiscall **)(CInputManager *))&ICIDM::s_cidm->vfptr->gap4[4])(ICIDM::s_cidm) )
  {
    strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
    strKeymapFilePath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PSUtils::get_directory(&strKeymapFilePath, &strPreferenceFile);
    if ( *(_DWORD *)&i_strKeymapFilename->m_charbuffer[-1].m_data[12] == 1 )
    {
      if ( *(_DWORD *)&v3->m_strKeymapFile.m_charbuffer[-1].m_data[12] == 1 )
      {
        PSUtils::get_process_name((PStringBase<char> *)&i_strKeymapFilename);
        PSUtils::strip_directory((PStringBase<char> *)&i_strKeymapFilename);
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)&v3->m_strKeymapFile,
          (const unsigned __int16 *)&i_strKeymapFilename);
        PStringBase<char>::PStringBase<char>(&new_extension, "keymap");
        PSUtils::change_extension(&v3->m_strKeymapFile, &new_extension);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&new_extension);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_strKeymapFilename);
      }
    }
    else
    {
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)&v3->m_strKeymapFile,
        (const unsigned __int16 *)i_strKeymapFilename);
    }
    PSUtils::path_append(&strKeymapFilePath, &v3->m_strKeymapFile);
    PSUtils::cleanup_filename(&strKeymapFilePath, 1);
    v4 = strKeymapFilePath.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strKeymapFilePath.m_charbuffer[-1]);
    if ( !(unsigned __int8)(*(int (__thiscall **)(CInputManager *, PSRefBufferCharData<char> *))&v2->vfptr->gap28[0])(
                             v2,
                             v4) )
      (*(void (__thiscall **)(CInputManager *))&v2->vfptr->gap4[4])(v2);
    ((void (__thiscall *)(CInputManager *, signed int))v2->vfptr->AddKeyMap)(v2, 268435457);
    ((void (__thiscall *)(_DWORD, signed int))v2->vfptr->AddKeyMap)(v2, 1);
    v5 = &strKeymapFilePath.m_charbuffer[-2].m_data[12];
    v6 = (volatile LONG *)&strKeymapFilePath.m_charbuffer[-1];
    v3->m_bKeymapLoaded = 1;
    if ( !InterlockedDecrement(v6) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v7 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00402F90) --------------------------------------------------------  // acclient.c:62527
char __thiscall gmClient::InitPreferences(gmClient *this)
{
  gmClient *v1; // ebx@1
  char *v2; // esi@1
  char *v3; // esi@4
  char *v4; // esi@7
  PStringBase<char> _Description; // [sp+8h] [bp-4h]@1

  _Description.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Description, "The filename of the keymap file to use");
  UserPreferences::RegisterPreference(&_Description, &v1->m_strKeymapFile, &Input_KeymapFile, &_Description, 0, 0, 0, 0);
  v2 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Chat Font Face");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_Description,
    &gmClient::sm_nFontFace,
    &UI_ChatFontFace,
    &_Description,
    (void (__cdecl *)(PStringBase<char> *))gmClient::GRPCallback_OnFontPreferenceChanged,
    5u,
    UI_ChatFontFace_Choices,
    0);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Chat Font Size");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_Description,
    &gmClient::sm_nFontSize,
    &UI_ChatFontSize,
    &_Description,
    (void (__cdecl *)(PStringBase<char> *))gmClient::GRPCallback_OnFontPreferenceChanged,
    5u,
    UI_ChatFontSize_Choices,
    0);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  return Client::InitPreferences((Client *)&v1->vfptr);
}

//----- (00403090) --------------------------------------------------------  // acclient.c:62572
char __thiscall gmClient::InitAuth(gmClient *this)
{
  gmClient *v1; // esi@1
  PStringBase<char> *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // ST0C_4@2
  unsigned int v5; // ST08_4@2
  unsigned int v6; // eax@4
  unsigned int v7; // ST0C_4@4
  unsigned int v8; // ST08_4@4
  TransientArchive ar; // [sp+8h] [bp-24h]@2

  v1 = this;
  v2 = &this->m_strVGPassword;
  if ( *(_DWORD *)&this->m_strVGPassword.m_charbuffer[-1].m_data[12] != 1 )
  {
    TransientArchive::TransientArchive(&ar, 0);
    PStringBase<char>::Serialize(v2, (Archive *)&ar.vfptr);
    v3 = Archive::GetSizeUsed((Archive *)&ar.vfptr);
    v4 = Archive::PeekBytes((Archive *)&ar.vfptr, 0, v3);
    v5 = Archive::GetSizeUsed((Archive *)&ar.vfptr);
    NetAuthenticator::SetToAuthType(&v1->m_netAuth, 2u, &v1->m_account, v5, (const char *)v4);
LABEL_5:
    Archive::~Archive((Archive *)&ar.vfptr);
    return 1;
  }
  if ( *(_DWORD *)&this->m_strGLSTicket.m_charbuffer[-1].m_data[12] != 1 )
  {
    TransientArchive::TransientArchive(&ar, 0);
    PStringBase<char>::Serialize(&v1->m_strGLSTicket, (Archive *)&ar.vfptr);
    v6 = Archive::GetSizeUsed((Archive *)&ar.vfptr);
    v7 = Archive::PeekBytes((Archive *)&ar.vfptr, 0, v6);
    v8 = Archive::GetSizeUsed((Archive *)&ar.vfptr);
    NetAuthenticator::SetToAuthType(&v1->m_netAuth, 0x40000002u, &v1->m_account, v8, (const char *)v7);
    goto LABEL_5;
  }
  return Client::InitAuth((Client *)&this->vfptr);
}

//----- (00403170) --------------------------------------------------------  // acclient.c:62612
PStringBase<unsigned short> *__thiscall PStringBase<char>::to_wpstring(PStringBase<char> *this, PStringBase<unsigned short> *result, const unsigned __int16 i_sourceCodePage)
{
  LPCSTR *v3; // ebp@1
  int v4; // ecx@1
  PSRefBufferCharData<unsigned short> *v5; // eax@2
  PStringBase<unsigned short> *v6; // edi@2
  int v7; // esi@2
  int v8; // eax@3
  int v9; // edi@3
  int v10; // eax@5
  DWORD v11; // eax@7
  DWORD v13; // eax@11
  const unsigned __int16 *v14; // [sp-20h] [bp-54h]@0
  int v15; // [sp-1Ch] [bp-50h]@0
  DWORD v16; // [sp-18h] [bp-4Ch]@0
  DWORD v17; // [sp-14h] [bp-48h]@0
  DWORD v18; // [sp+0h] [bp-34h]@4
  DWORD v19; // [sp+4h] [bp-30h]@4
  PStringBase<unsigned short> *v20; // [sp+8h] [bp-2Ch]@7
  unsigned __int16 *v21; // [sp+18h] [bp-1Ch]@5
  char *v22; // [sp+1Ch] [bp-18h]@2
  PStringBase<unsigned short> ret_str; // [sp+30h] [bp-4h]@1

  ret_str.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = (LPCSTR *)this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v4 = *((_DWORD *)*v3 - 1);
  if ( v4 == 1 )
  {
    v5 = ret_str.m_charbuffer;
    v6 = result;
    result->m_charbuffer = ret_str.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    v7 = (int)&ret_str.m_charbuffer[-1].m_data[6];
    v22 = (char *)&ret_str.m_charbuffer[-1].m_data[8];
  }
  else
  {
    v8 = MultiByteToWideChar(i_sourceCodePage, 0, *v3, v4, 0, 0);
    v9 = v8;
    if ( v8 )
    {
      PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&v21, v8);
      v10 = MultiByteToWideChar(i_sourceCodePage, 0, *v3, *((_DWORD *)*v3 - 1), v21, v9);
      if ( v10 )
      {
        v6 = v20;
        *(_DWORD *)(v18 - 4) = v10;
        v13 = v18;
        v6->m_charbuffer = (PSRefBufferCharData<unsigned short> *)v18;
        InterlockedIncrement((volatile LONG *)(v13 - 16));
        if ( !InterlockedDecrement((volatile LONG *)(v18 - 20 + 4)) && v18 != 20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))(v18 - 20))(v18 - 20, 1);
        return v6;
      }
      v17 = GetLastError();
      v16 = GetLastError();
      v15 = i_sourceCodePage;
      v14 = L"Failed conversion from codepage %hu! GetLastError %d (0x%08x)\n";
    }
    else
    {
      v19 = GetLastError();
      v18 = GetLastError();
    }
    PStringBase<unsigned short>::sprintf((PStringBase<unsigned short> *)&v18, v14, v15, v16, v17);
    v11 = v18;
    v6 = v20;
    v20->m_charbuffer = (PSRefBufferCharData<unsigned short> *)v18;
    InterlockedIncrement((volatile LONG *)(v11 - 16));
    v7 = v18 - 20;
    v17 = v18 - 20 + 4;
  }
  if ( !InterlockedDecrement((volatile LONG *)v17) && v7 )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    return v6;
  }
  return v6;
}

//----- (004032B0) --------------------------------------------------------  // acclient.c:62694
void __thiscall Client::SetAccountName(Client *this, accountID *account)
{
  char *v2; // esi@1

  v2 = (char *)&this->m_account;
  AC1Legacy::PStringBase<char>::set(
    (AC1Legacy::PStringBase<char> *)&this->m_account.m_buffer,
    account->m_buffer->m_data);
  *((_DWORD *)v2 + 1) = account->fIsDarkMajestyExpansion_;
  *((_DWORD *)v2 + 2) = account->m_fIsThroneOfDestinyExpansion;
  *((_DWORD *)v2 + 3) = account->m_fPreOrderedThroneOfDestinyExpansion;
}

//----- (004032E0) --------------------------------------------------------  // acclient.c:62708
void __thiscall AC1Legacy::PStringBase<char>::set(AC1Legacy::PStringBase<char> *this, const char *str)
{
  AC1Legacy::PStringBase<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // ebx@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@8
  volatile LONG *v5; // ecx@12

  v2 = this;
  if ( str && *str )
  {
    v3 = this->m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&this->m_buffer->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    AC1Legacy::PStringBase<char>::allocate_ref_buffer(v2, strlen(str));
    strcpy(v2->m_buffer->m_data, str);
  }
  else
  {
    v4 = this->m_buffer;
    if ( this->m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
      v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
      v2->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement(v5);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00403380) --------------------------------------------------------  // acclient.c:62743
void __thiscall AC1Legacy::PStringBase<char>::allocate_ref_buffer(AC1Legacy::PStringBase<char> *this, unsigned int len)
{
  AC1Legacy::PStringBase<char> *v2; // edi@1
  unsigned int v3; // esi@1
  void *v4; // eax@3

  v2 = this;
  v3 = 1;
  do
    v3 *= 2;
  while ( len > v3 );
  v4 = operator new[](v3 + 24);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)v4 + 2) = 1;
    *((_DWORD *)v4 + 3) = 1;
    *((_DWORD *)v4 + 4) = -1;
    *((_BYTE *)v4 + 20) = 0;
    v2->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v4;
    *((_DWORD *)v4 + 2) = len + 1;
    v2->m_buffer->m_size = v3 + 1;
  }
  else
  {
    v2->m_buffer = 0;
    v8 = len + 1;
    v2->m_buffer->m_size = v3 + 1;
  }
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (00403400) --------------------------------------------------------  // acclient.c:62777
TResult *__stdcall ClassFactoryForceClient_ClassType::CreateInstance(TResult *result, Interface *_pOuterInterface, Turbine_GUID *_rInterfaceType, void **_ppvObject)
{
  TResult *v5; // eax@2
  gmClient *v6; // eax@3
  int v7; // eax@4
  Interface *v8; // ecx@6
  void **v9; // ST08_4@7
  Interface *v10; // ecx@7
  bool v11; // zf@7
  TResult *v12; // esi@7
  int v13; // [sp+8h] [bp-Ch]@6
  InterfacePtr<Interface> spInterface; // [sp+Ch] [bp-8h]@6

  if ( _pOuterInterface )
  {
    v5 = result;
    result->m_val = -2147221232;
    return v5;
  }
  v6 = (gmClient *)operator new(0x160u);
  if ( v6 )
    gmClient::gmClient(v6);
  else
    v7 = 0;
  spInterface.m_pInterface = 0;
  spInterface.m_trStatus.m_val = 0;
  spInterface.m_trStatus.m_val = *(_DWORD *)InterfacePtr<Interface>::_QueryInterface(&spInterface, (int)&v13, v7);
  v8 = spInterface.m_pInterface;
  if ( _ppvObject )
  {
    v9 = _ppvObject;
    *_ppvObject = 0;
    ((void (__stdcall *)(Interface **, Turbine_GUID *, void **))v8->vfptr->QueryInterface)(
      &_pOuterInterface,
      _rInterfaceType,
      v9);
    ((void (*)(void))spInterface.m_pInterface->vfptr->Release)();
    v10 = spInterface.m_pInterface;
    v11 = (_DWORD)spInterface.m_pInterface == 0;
    v12 = result;
    result->m_val = (unsigned int)_pOuterInterface;
    if ( !v11 )
    {
      ((void (*)(void))v10->vfptr->Release)();
      return result;
    }
  }
  else
  {
    v12 = result;
    result->m_val = -2147467261;
    if ( v8 )
      ((void (*)(void))v8->vfptr->Release)();
  }
  return v12;
}

//----- (004034D0) --------------------------------------------------------  // acclient.c:62835
int __thiscall InterfacePtr<Interface>::_QueryInterface(InterfacePtr<Interface> *this, int a2, int a3)
{
  InterfacePtr<Interface> *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  Interface *v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  InterfacePtr<Interface> *v9; // [sp+4h] [bp-4h]@1

  v9 = this;
  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(int *, Turbine_GUID *, int *))(v4 + 12))(&v9, &Interface_InterfaceType_1, &a3);
    v6 = v3->m_pInterface;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = (Interface *)v8;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = 0;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    InterfacePtr<Interface>::operator=(this, 0);
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (00403570) --------------------------------------------------------  // acclient.c:62883
InterfacePtr<Interface> *__thiscall InterfacePtr<Interface>::operator=(InterfacePtr<Interface> *this, Interface *_ptr)
{
  InterfacePtr<Interface> *v2; // esi@1
  Interface *v3; // edi@1

  v2 = this;
  v3 = this->m_pInterface;
  if ( this->m_pInterface != _ptr )
  {
    this->m_pInterface = _ptr;
    if ( _ptr )
      ((void (*)(void))_ptr->vfptr->AddRef)();
    if ( v3 )
      v3->vfptr->Release(v3);
    v2->m_trStatus.m_val = 0;
  }
  return v2;
}

//----- (004035B0) --------------------------------------------------------  // acclient.c:62903
void gmClient::InitUIPreferences()
{
  const unsigned int v1; // ST20_4@1
  const unsigned int v2; // eax@1
  const unsigned int v3; // ST20_4@1
  const unsigned int v4; // eax@1
  const unsigned int v5; // ST20_4@1
  const unsigned int v6; // eax@1
  const unsigned int v7; // ST20_4@1
  const unsigned int v8; // eax@1
  const unsigned int v9; // ST20_4@1
  const unsigned int v10; // eax@1
  const unsigned int v11; // ST20_4@1
  const unsigned int v12; // eax@1
  const unsigned int v13; // ST20_4@1
  const unsigned int v14; // eax@1
  unsigned int v15; // esi@1
  unsigned int v16; // eax@1
  unsigned int v17; // esi@3
  unsigned int v18; // eax@4
  const unsigned int v19; // ST20_4@6
  const unsigned int v20; // eax@6
  const unsigned int v21; // ST20_4@6
  const unsigned int v22; // eax@6
  const unsigned int v23; // ST20_4@6
  const unsigned int v24; // eax@6
  const unsigned int v25; // ST20_4@6
  const unsigned int v26; // eax@6
  unsigned int v27; // esi@6
  unsigned int v28; // eax@6
  unsigned int v29; // esi@8
  unsigned int v30; // eax@9
  unsigned int v31; // esi@11
  unsigned int v32; // eax@12
  unsigned int v33; // esi@14
  unsigned int v34; // eax@15
  unsigned int v35; // esi@17
  unsigned int v36; // eax@18
  const unsigned int v37; // ST20_4@20
  const unsigned int v38; // eax@20
  unsigned int v39; // esi@20
  unsigned int v40; // eax@20
  unsigned int v41; // esi@22
  unsigned int v42; // eax@23
  unsigned int v43; // esi@25
  unsigned int v44; // eax@26
  unsigned int v45; // esi@28
  unsigned int v46; // eax@29
  unsigned int v47; // esi@31
  unsigned int v48; // eax@32
  const unsigned int v49; // ST20_4@34
  const unsigned int v50; // eax@34
  unsigned int v51; // esi@34
  unsigned int v52; // eax@34
  unsigned int v53; // esi@36
  unsigned int v54; // eax@37
  unsigned int v55; // esi@39
  unsigned int v56; // eax@40
  unsigned int v57; // esi@42
  unsigned int v58; // eax@43
  const unsigned int v59; // ST20_4@45
  const unsigned int v60; // eax@45
  const unsigned int v61; // ST20_4@45
  const unsigned int v62; // eax@45
  const unsigned int v63; // ST20_4@45
  const unsigned int v64; // eax@45
  unsigned int v65; // esi@45
  unsigned int v66; // eax@45
  unsigned int v67; // esi@47
  unsigned int v68; // eax@48
  unsigned int v69; // esi@50
  unsigned int v70; // eax@51
  unsigned int v71; // esi@53
  unsigned int v72; // eax@54
  unsigned int v73; // esi@56
  unsigned int v74; // eax@57
  const unsigned int v75; // ST20_4@59
  const unsigned int v76; // eax@59
  unsigned int v77; // esi@59
  unsigned int v78; // eax@59
  unsigned int v79; // esi@61
  unsigned int v80; // eax@62
  unsigned int v81; // esi@64
  unsigned int v82; // eax@65
  unsigned int v83; // esi@67
  unsigned int v84; // eax@68
  unsigned int v85; // esi@70
  unsigned int v86; // eax@71
  const unsigned int v87; // ST20_4@73
  const unsigned int v88; // eax@73
  unsigned int v89; // esi@73
  unsigned int v90; // eax@73
  unsigned int v91; // esi@75
  unsigned int v92; // eax@76
  unsigned int v93; // esi@78
  unsigned int v94; // eax@79
  const unsigned int v95; // ST20_4@81
  const unsigned int v96; // eax@81
  unsigned int v97; // esi@81
  unsigned int v98; // eax@81
  unsigned int v99; // esi@83
  unsigned int v100; // eax@84
  unsigned int v101; // esi@86
  unsigned int v102; // eax@87
  unsigned int v103; // esi@89
  unsigned int v104; // eax@90
  unsigned int v105; // esi@92
  unsigned int v106; // eax@93
  unsigned int v107; // esi@95
  unsigned int v108; // eax@96
  const unsigned int v109; // ST20_4@98
  const unsigned int v110; // eax@98
  const unsigned int v111; // ST20_4@98
  const unsigned int v112; // eax@98
  const unsigned int v113; // ST20_4@98
  const unsigned int v114; // eax@98
  const unsigned int v115; // ST20_4@98
  const unsigned int v116; // eax@98
  const unsigned int v117; // ST20_4@98
  const unsigned int v118; // eax@98
  const unsigned int v119; // ST20_4@98
  const unsigned int v120; // eax@98
  const unsigned int v121; // ST20_4@98
  const unsigned int v122; // eax@98
  const unsigned int v123; // ST20_4@98
  const unsigned int v124; // eax@98
  const unsigned int v125; // ST20_4@98
  const unsigned int v126; // eax@98
  const unsigned int v127; // ST20_4@98
  const unsigned int v128; // eax@98
  const unsigned int v129; // ST20_4@98
  const unsigned int v130; // eax@98
  const unsigned int v131; // ST20_4@98
  const unsigned int v132; // eax@98
  const unsigned int v133; // ST20_4@98
  const unsigned int v134; // eax@98
  const unsigned int v135; // ST20_4@98
  const unsigned int v136; // eax@98
  const unsigned int v137; // ST20_4@98
  const unsigned int v138; // eax@98
  SmartArray<unsigned long,1> arrayLandscapeDrawDistance; // [sp+8h] [bp-60h]@81
  SmartArray<unsigned long,1> arrayEnvTextureDetail; // [sp+14h] [bp-54h]@59
  SmartArray<unsigned long,1> arrayLanTextureDetail; // [sp+20h] [bp-48h]@45
  SmartArray<unsigned long,1> arrayChatFontSize; // [sp+2Ch] [bp-3Ch]@20
  SmartArray<unsigned long,1> arrayChatFontFace; // [sp+38h] [bp-30h]@6
  SmartArray<unsigned long,1> arrayTextureFiltering; // [sp+44h] [bp-24h]@34
  SmartArray<unsigned long,1> arraySceneryDrawDistance; // [sp+50h] [bp-18h]@73
  SmartArray<unsigned long,1> arraySoundFeatures; // [sp+5Ch] [bp-Ch]@1

  v1 = compute_str_hash("ID_Sound_DisableSound_Help");
  v2 = compute_str_hash("ID_Sound_DisableSound");
  UIPreferences::AttachPreference(&Sound_SoundDisabled, 4u, 0x10000003u, v2, v1);
  v3 = compute_str_hash("ID_Sound_EffectVolume_Help");
  v4 = compute_str_hash("ID_Sound_EffectVolume");
  UIPreferences::AttachPreference(&Sound_SoundVolume, 3u, 0x10000003u, v4, v3);
  UIPreferences::SetPreferenceRange(&Sound_SoundVolume, 0.0, 1.0);
  v5 = compute_str_hash("ID_Sound_DisableAmbientSound_Help");
  v6 = compute_str_hash("ID_Sound_DisableAmbientSound");
  UIPreferences::AttachPreference(&Sound_AmbientSoundDisabled, 4u, 0x10000003u, v6, v5);
  v7 = compute_str_hash("ID_Sound_AmbientVolume_Help");
  v8 = compute_str_hash("ID_Sound_AmbientVolume");
  UIPreferences::AttachPreference(&Sound_AmbientSoundVolume, 3u, 0x10000003u, v8, v7);
  UIPreferences::SetPreferenceRange(&Sound_AmbientSoundVolume, 0.0, 1.0);
  v9 = compute_str_hash("ID_Sound_DisableInterfaceSound_Help");
  v10 = compute_str_hash("ID_Sound_DisableInterfaceSound");
  UIPreferences::AttachPreference(&Sound_InterfaceSoundDisabled, 4u, 0x10000003u, v10, v9);
  v11 = compute_str_hash("ID_Sound_InterfaceVolume_Help");
  v12 = compute_str_hash("ID_Sound_InterfaceVolume");
  UIPreferences::AttachPreference(&Sound_InterfaceSoundVolume, 3u, 0x10000003u, v12, v11);
  UIPreferences::SetPreferenceRange(&Sound_InterfaceSoundVolume, 0.0, 1.0);
  v13 = compute_str_hash("ID_Sound_SoundFeatures_Help");
  v14 = compute_str_hash("ID_Sound_SoundFeatures");
  UIPreferences::AttachPreference(&Sound_SoundFeatures, 2u, 0x10000003u, v14, v13);
  arraySoundFeatures.m_data = 0;
  arraySoundFeatures.m_sizeAndDeallocate = 0;
  arraySoundFeatures.m_num = 0;
  v15 = compute_str_hash("ID_Sound_Stereo");
  v16 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arraySoundFeatures, v16) )
    arraySoundFeatures.m_data[arraySoundFeatures.m_num++] = v15;
  v17 = compute_str_hash("ID_Sound_Mono");
  if ( arraySoundFeatures.m_num < (arraySoundFeatures.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v18 = SmartArray<UIChildFramework *,1>::get_new_size((arraySoundFeatures.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arraySoundFeatures, v18)) )
    arraySoundFeatures.m_data[arraySoundFeatures.m_num++] = v17;
  UIPreferences::SetEnumChoices(&Sound_SoundFeatures, &arraySoundFeatures);
  v19 = compute_str_hash("ID_Sound_NoFocusNoSound_Help");
  v20 = compute_str_hash("ID_Sound_NoFocusNoSound");
  UIPreferences::AttachPreference(&Sound_PlaySoundOnlyWhenActive, 4u, 0x10000003u, v20, v19);
  v21 = compute_str_hash("ID_Misc_TooltipDelay_Help");
  v22 = compute_str_hash("ID_Misc_TooltipDelay");
  UIPreferences::AttachPreference(&Misc_TooltipDelay, 3u, 0x10000003u, v22, v21);
  UIPreferences::SetPreferenceRange(&Misc_TooltipDelay, 0.0, 10.0);
  v23 = compute_str_hash("ID_Misc_TooltipEnable_Help");
  v24 = compute_str_hash("ID_Misc_TooltipEnable");
  UIPreferences::AttachPreference(&Misc_TooltipEnable, 4u, 0x10000003u, v24, v23);
  v25 = compute_str_hash("ID_UI_ChatFontFace_Help");
  v26 = compute_str_hash("ID_UI_ChatFontFace");
  UIPreferences::AttachPreference(&UI_ChatFontFace, 2u, 0x10000003u, v26, v25);
  arrayChatFontFace.m_data = 0;
  arrayChatFontFace.m_sizeAndDeallocate = 0;
  arrayChatFontFace.m_num = 0;
  v27 = compute_str_hash("ID_UI_Value_Arial");
  v28 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontFace, v28) )
    arrayChatFontFace.m_data[arrayChatFontFace.m_num++] = v27;
  v29 = compute_str_hash("ID_UI_Value_CourierNew");
  if ( arrayChatFontFace.m_num < (arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v30 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontFace, v30)) )
    arrayChatFontFace.m_data[arrayChatFontFace.m_num++] = v29;
  v31 = compute_str_hash("ID_UI_Value_PalatinoLinotype");
  if ( arrayChatFontFace.m_num < (arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v32 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontFace, v32)) )
    arrayChatFontFace.m_data[arrayChatFontFace.m_num++] = v31;
  v33 = compute_str_hash("ID_UI_Value_Tahoma");
  if ( arrayChatFontFace.m_num < (arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v34 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontFace, v34)) )
    arrayChatFontFace.m_data[arrayChatFontFace.m_num++] = v33;
  v35 = compute_str_hash("ID_UI_Value_TimesNewRoman");
  if ( arrayChatFontFace.m_num < (arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v36 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontFace.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontFace, v36)) )
    arrayChatFontFace.m_data[arrayChatFontFace.m_num++] = v35;
  UIPreferences::SetEnumChoices(&UI_ChatFontFace, &arrayChatFontFace);
  v37 = compute_str_hash("ID_UI_ChatFontSize_Help");
  v38 = compute_str_hash("ID_UI_ChatFontSize");
  UIPreferences::AttachPreference(&UI_ChatFontSize, 2u, 0x10000003u, v38, v37);
  arrayChatFontSize.m_data = 0;
  arrayChatFontSize.m_sizeAndDeallocate = 0;
  arrayChatFontSize.m_num = 0;
  v39 = compute_str_hash("ID_UI_Value_Tiny");
  v40 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontSize, v40) )
    arrayChatFontSize.m_data[arrayChatFontSize.m_num++] = v39;
  v41 = compute_str_hash("ID_UI_Value_Small");
  if ( arrayChatFontSize.m_num < (arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v42 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontSize, v42)) )
    arrayChatFontSize.m_data[arrayChatFontSize.m_num++] = v41;
  v43 = compute_str_hash("ID_UI_Value_Medium");
  if ( arrayChatFontSize.m_num < (arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v44 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontSize, v44)) )
    arrayChatFontSize.m_data[arrayChatFontSize.m_num++] = v43;
  v45 = compute_str_hash("ID_UI_Value_Large");
  if ( arrayChatFontSize.m_num < (arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v46 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontSize, v46)) )
    arrayChatFontSize.m_data[arrayChatFontSize.m_num++] = v45;
  v47 = compute_str_hash("ID_UI_Value_XLarge");
  if ( arrayChatFontSize.m_num < (arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v48 = SmartArray<UIChildFramework *,1>::get_new_size((arrayChatFontSize.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayChatFontSize, v48)) )
    arrayChatFontSize.m_data[arrayChatFontSize.m_num++] = v47;
  UIPreferences::SetEnumChoices(&UI_ChatFontSize, &arrayChatFontSize);
  v49 = compute_str_hash("ID_Graphics_TextureFiltering_Help");
  v50 = compute_str_hash("ID_Graphics_TextureFiltering");
  UIPreferences::AttachPreference(&Render_TextureFiltering, 2u, 0x10000003u, v50, v49);
  arrayTextureFiltering.m_data = 0;
  arrayTextureFiltering.m_sizeAndDeallocate = 0;
  arrayTextureFiltering.m_num = 0;
  v51 = compute_str_hash("ID_Graphics_TextureFiltering_Bilinear");
  v52 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayTextureFiltering, v52) )
    arrayTextureFiltering.m_data[arrayTextureFiltering.m_num++] = v51;
  v53 = compute_str_hash("ID_Graphics_TextureFiltering_Trilinear");
  if ( arrayTextureFiltering.m_num < (arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v54 = SmartArray<UIChildFramework *,1>::get_new_size((arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayTextureFiltering, v54)) )
    arrayTextureFiltering.m_data[arrayTextureFiltering.m_num++] = v53;
  v55 = compute_str_hash("ID_Graphics_TextureFiltering_Sharp");
  if ( arrayTextureFiltering.m_num < (arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v56 = SmartArray<UIChildFramework *,1>::get_new_size((arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayTextureFiltering, v56)) )
    arrayTextureFiltering.m_data[arrayTextureFiltering.m_num++] = v55;
  v57 = compute_str_hash("ID_Graphics_TextureFiltering_Anisotropic");
  if ( arrayTextureFiltering.m_num < (arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v58 = SmartArray<UIChildFramework *,1>::get_new_size((arrayTextureFiltering.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayTextureFiltering, v58)) )
    arrayTextureFiltering.m_data[arrayTextureFiltering.m_num++] = v57;
  UIPreferences::SetEnumChoices(&Render_TextureFiltering, &arrayTextureFiltering);
  v59 = compute_str_hash("ID_Graphics_BuildingDetailTextures_Help");
  v60 = compute_str_hash("ID_Graphics_BuildingDetailTextures");
  UIPreferences::AttachPreference(&Render_BuildingDetailTextures, 4u, 0x10000003u, v60, v59);
  v61 = compute_str_hash("ID_Graphics_MultiPassAlpha_Help");
  v62 = compute_str_hash("ID_Graphics_MultiPassAlpha");
  UIPreferences::AttachPreference(&Render_MultiPassAlpha, 4u, 0x10000003u, v62, v61);
  v63 = compute_str_hash("ID_Graphics_LandscapeTextureDetail_Help");
  v64 = compute_str_hash("ID_Graphics_LandscapeTextureDetail");
  UIPreferences::AttachPreference(&Render_LandscapeTextureDetail, 2u, 0x10000003u, v64, v63);
  arrayLanTextureDetail.m_data = 0;
  arrayLanTextureDetail.m_sizeAndDeallocate = 0;
  arrayLanTextureDetail.m_num = 0;
  v65 = compute_str_hash("ID_Graphics_Value_VeryLow");
  v66 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLanTextureDetail, v66) )
    arrayLanTextureDetail.m_data[arrayLanTextureDetail.m_num++] = v65;
  v67 = compute_str_hash("ID_Graphics_Value_Low");
  if ( arrayLanTextureDetail.m_num < (arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v68 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLanTextureDetail, v68)) )
    arrayLanTextureDetail.m_data[arrayLanTextureDetail.m_num++] = v67;
  v69 = compute_str_hash("ID_Graphics_Value_Medium");
  if ( arrayLanTextureDetail.m_num < (arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v70 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLanTextureDetail, v70)) )
    arrayLanTextureDetail.m_data[arrayLanTextureDetail.m_num++] = v69;
  v71 = compute_str_hash("ID_Graphics_Value_High");
  if ( arrayLanTextureDetail.m_num < (arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v72 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLanTextureDetail, v72)) )
    arrayLanTextureDetail.m_data[arrayLanTextureDetail.m_num++] = v71;
  v73 = compute_str_hash("ID_Graphics_Value_VeryHigh");
  if ( arrayLanTextureDetail.m_num < (arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v74 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLanTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLanTextureDetail, v74)) )
    arrayLanTextureDetail.m_data[arrayLanTextureDetail.m_num++] = v73;
  UIPreferences::SetEnumChoices(&Render_LandscapeTextureDetail, &arrayLanTextureDetail);
  v75 = compute_str_hash("ID_Graphics_EnvironmentTextureDetail_Help");
  v76 = compute_str_hash("ID_Graphics_EnvironmentTextureDetail");
  UIPreferences::AttachPreference(&Render_EnvironmentTextureDetail, 2u, 0x10000003u, v76, v75);
  arrayEnvTextureDetail.m_data = 0;
  arrayEnvTextureDetail.m_sizeAndDeallocate = 0;
  arrayEnvTextureDetail.m_num = 0;
  v77 = compute_str_hash("ID_Graphics_Value_VeryLow");
  v78 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayEnvTextureDetail, v78) )
    arrayEnvTextureDetail.m_data[arrayEnvTextureDetail.m_num++] = v77;
  v79 = compute_str_hash("ID_Graphics_Value_Low");
  if ( arrayEnvTextureDetail.m_num < (arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v80 = SmartArray<UIChildFramework *,1>::get_new_size((arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayEnvTextureDetail, v80)) )
    arrayEnvTextureDetail.m_data[arrayEnvTextureDetail.m_num++] = v79;
  v81 = compute_str_hash("ID_Graphics_Value_Medium");
  if ( arrayEnvTextureDetail.m_num < (arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v82 = SmartArray<UIChildFramework *,1>::get_new_size((arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayEnvTextureDetail, v82)) )
    arrayEnvTextureDetail.m_data[arrayEnvTextureDetail.m_num++] = v81;
  v83 = compute_str_hash("ID_Graphics_Value_High");
  if ( arrayEnvTextureDetail.m_num < (arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v84 = SmartArray<UIChildFramework *,1>::get_new_size((arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayEnvTextureDetail, v84)) )
    arrayEnvTextureDetail.m_data[arrayEnvTextureDetail.m_num++] = v83;
  v85 = compute_str_hash("ID_Graphics_Value_VeryHigh");
  if ( arrayEnvTextureDetail.m_num < (arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v86 = SmartArray<UIChildFramework *,1>::get_new_size((arrayEnvTextureDetail.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayEnvTextureDetail, v86)) )
    arrayEnvTextureDetail.m_data[arrayEnvTextureDetail.m_num++] = v85;
  UIPreferences::SetEnumChoices(&Render_EnvironmentTextureDetail, &arrayEnvTextureDetail);
  v87 = compute_str_hash("ID_Graphics_SceneryDrawDistance_Help");
  v88 = compute_str_hash("ID_Graphics_SceneryDrawDistance");
  UIPreferences::AttachPreference(&Render_SceneryDrawDistance, 2u, 0x10000003u, v88, v87);
  arraySceneryDrawDistance.m_data = 0;
  arraySceneryDrawDistance.m_sizeAndDeallocate = 0;
  arraySceneryDrawDistance.m_num = 0;
  v89 = compute_str_hash("ID_Graphics_Value_Low");
  v90 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arraySceneryDrawDistance, v90) )
    arraySceneryDrawDistance.m_data[arraySceneryDrawDistance.m_num++] = v89;
  v91 = compute_str_hash("ID_Graphics_Value_Medium");
  if ( arraySceneryDrawDistance.m_num < (arraySceneryDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v92 = SmartArray<UIChildFramework *,1>::get_new_size((arraySceneryDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arraySceneryDrawDistance, v92)) )
    arraySceneryDrawDistance.m_data[arraySceneryDrawDistance.m_num++] = v91;
  v93 = compute_str_hash("ID_Graphics_Value_High");
  if ( arraySceneryDrawDistance.m_num < (arraySceneryDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v94 = SmartArray<UIChildFramework *,1>::get_new_size((arraySceneryDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arraySceneryDrawDistance, v94)) )
    arraySceneryDrawDistance.m_data[arraySceneryDrawDistance.m_num++] = v93;
  UIPreferences::SetEnumChoices(&Render_SceneryDrawDistance, &arraySceneryDrawDistance);
  v95 = compute_str_hash("ID_Graphics_LandscapeDrawDistance_Help");
  v96 = compute_str_hash("ID_Graphics_LandscapeDrawDistance");
  UIPreferences::AttachPreference(&Render_LandscapeDrawDistance, 2u, 0x10000003u, v96, v95);
  arrayLandscapeDrawDistance.m_data = 0;
  arrayLandscapeDrawDistance.m_sizeAndDeallocate = 0;
  arrayLandscapeDrawDistance.m_num = 0;
  v97 = compute_str_hash("ID_Graphics_Value_VeryLow");
  v98 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v98) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v97;
  v99 = compute_str_hash("ID_Graphics_Value_Low");
  if ( arrayLandscapeDrawDistance.m_num < (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v100 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v100)) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v99;
  v101 = compute_str_hash("ID_Graphics_Value_Medium");
  if ( arrayLandscapeDrawDistance.m_num < (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v102 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v102)) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v101;
  v103 = compute_str_hash("ID_Graphics_Value_High");
  if ( arrayLandscapeDrawDistance.m_num < (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v104 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v104)) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v103;
  v105 = compute_str_hash("ID_Graphics_Value_VeryHigh");
  if ( arrayLandscapeDrawDistance.m_num < (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v106 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v106)) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v105;
  v107 = compute_str_hash("ID_Graphics_Value_Extreme");
  if ( arrayLandscapeDrawDistance.m_num < (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF)
    || (v108 = SmartArray<UIChildFramework *,1>::get_new_size((arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&arrayLandscapeDrawDistance, v108)) )
    arrayLandscapeDrawDistance.m_data[arrayLandscapeDrawDistance.m_num++] = v107;
  UIPreferences::SetEnumChoices(&Render_LandscapeDrawDistance, &arrayLandscapeDrawDistance);
  v109 = compute_str_hash("ID_Graphics_FieldOfView_Help");
  v110 = compute_str_hash("ID_Graphics_FieldOfView");
  UIPreferences::AttachPreference(&Render_FieldOfView, 3u, 0x10000003u, v110, v109);
  UIPreferences::SetPreferenceRange(&Render_FieldOfView, 10.0, 160.0);
  v111 = compute_str_hash("ID_Graphics_ScreenBrightness_Help");
  v112 = compute_str_hash("ID_Graphics_ScreenBrightness");
  UIPreferences::AttachPreference(&Render_ScreenBrightness, 3u, 0x10000003u, v112, v111);
  UIPreferences::SetPreferenceRange(&Render_ScreenBrightness, -1.0, 1.0);
  v113 = compute_str_hash("ID_Graphics_AdaptiveDegrade_Help");
  v114 = compute_str_hash("ID_Graphics_AdaptiveDegrade");
  UIPreferences::AttachPreference(&Render_AutomaticDegrades, 4u, 0x10000003u, v114, v113);
  v115 = compute_str_hash("ID_Graphics_AdaptiveDegradeBias_Help");
  v116 = compute_str_hash("ID_Graphics_AdaptiveDegradeBias");
  UIPreferences::AttachPreference(&Render_GraphicsPerformance, 3u, 0x10000003u, v116, v115);
  UIPreferences::SetPreferenceRange(&Render_GraphicsPerformance, -1.0, 1.0);
  v117 = compute_str_hash("ID_Graphics_DegradeDistance_Help");
  v118 = compute_str_hash("ID_Graphics_DegradeDistance");
  UIPreferences::AttachPreference(&Render_DegradeDistance, 3u, 0x10000003u, v118, v117);
  UIPreferences::SetPreferenceRange(&Render_DegradeDistance, 0.0, 100.0);
  v119 = compute_str_hash("ID_Rendering_FullScreen_Help");
  v120 = compute_str_hash("ID_Rendering_FullScreen");
  UIPreferences::AttachPreference(&Display_FullScreen_0, 4u, 0x10000003u, v120, v119);
  v121 = compute_str_hash("ID_Rendering_SyncToDisplayRefresh_Help");
  v122 = compute_str_hash("ID_Rendering_SyncToDisplayRefresh");
  UIPreferences::AttachPreference(&Display_SyncToRefresh_0, 4u, 0x10000003u, v122, v121);
  v123 = compute_str_hash("ID_Rendering_DisplayResolution_Help");
  v124 = compute_str_hash("ID_Rendering_DisplayResolution");
  UIPreferences::AttachPreference(&Display_Resolution_0, 2u, 0x10000003u, v124, v123);
  v125 = compute_str_hash("ID_Rendering_RefreshRate_Help");
  v126 = compute_str_hash("ID_Rendering_RefreshRate");
  UIPreferences::AttachPreference(&Display_RefreshRate_0, 2u, 0x10000003u, v126, v125);
  v127 = compute_str_hash("ID_Input_MouseLookSensitivity_Help");
  v128 = compute_str_hash("ID_Input_MouseLookSensitivity");
  UIPreferences::AttachPreference(&Input_MouseLookSensitivity, 3u, 0x10000003u, v128, v127);
  UIPreferences::SetPreferenceRange(&Input_MouseLookSensitivity, 0.0099999998, 1.0);
  v129 = compute_str_hash("ID_Input_InvertMouseLookYAxis_Help");
  v130 = compute_str_hash("ID_Input_InvertMouseLookYAxis");
  UIPreferences::AttachPreference(&Input_InvertMouseLookYAxis, 4u, 0x10000003u, v130, v129);
  v131 = compute_str_hash("ID_Input_UseMouseTurning_Help");
  v132 = compute_str_hash("ID_Input_UseMouseTurning");
  UIPreferences::AttachPreference(&Input_UseMouseTurning, 4u, 0x10000003u, v132, v131);
  v133 = compute_str_hash("ID_Camera_AlignToSlope_Help");
  v134 = compute_str_hash("ID_Camera_AlignToSlope");
  UIPreferences::AttachPreference(&Camera_AlignToSlope, 4u, 0x10000003u, v134, v133);
  v135 = compute_str_hash("ID_Camera_Stiffness_Help");
  v136 = compute_str_hash("ID_Camera_Stiffness");
  UIPreferences::AttachPreference(&Camera_Stiffness, 3u, 0x10000003u, v136, v135);
  UIPreferences::SetPreferenceRange(&Camera_Stiffness, 0.2857143, 1.0);
  v137 = compute_str_hash("ID_Camera_AdjustmentSpeed_Help");
  v138 = compute_str_hash("ID_Camera_AdjustmentSpeed");
  UIPreferences::AttachPreference(&Camera_AdjustmentSpeed, 3u, 0x10000003u, v138, v137);
  UIPreferences::SetPreferenceRange(&Camera_AdjustmentSpeed, 5.0, 80.0);
  if ( (arrayLandscapeDrawDistance.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayLandscapeDrawDistance.m_data);
  if ( (arraySceneryDrawDistance.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arraySceneryDrawDistance.m_data);
  if ( (arrayEnvTextureDetail.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayEnvTextureDetail.m_data);
  if ( (arrayLanTextureDetail.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayLanTextureDetail.m_data);
  if ( (arrayTextureFiltering.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayTextureFiltering.m_data);
  if ( (arrayChatFontSize.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayChatFontSize.m_data);
  if ( (arrayChatFontFace.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayChatFontFace.m_data);
  if ( (arraySoundFeatures.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arraySoundFeatures.m_data);
}

//----- (004047A0) --------------------------------------------------------  // acclient.c:63383
bool __thiscall gmClient::Init(gmClient *this, PStringBase<char> *windowTitle, const int language_i, const int region_i)
{
  gmClient *v4; // esi@1
  bool result; // al@1
  UIQueueManager *v6; // eax@2
  IQueuedUIEventDeliverer *v7; // eax@3
  GlobalEventHandler *v8; // eax@5

  v4 = this;
  Device::ForceDisplayResolution(1, 0x320u, 0x258u);
  result = Client::Init((Client *)&v4->vfptr, windowTitle, language_i, region_i);
  if ( result )
  {
    v6 = (UIQueueManager *)operator new(0x58u);
    if ( v6 )
      UIQueueManager::UIQueueManager(v6, v4->netQueues_[9]);
    else
      v7 = 0;
    v4->m_UIQueueManager = v7;
    ((void (__thiscall *)(IQueuedUIEventDeliverer *))v7->vfptr[1].IUnknown_QueryInterface)(v7);
    _setlocale(0, "English");
    v8 = GlobalEventHandler::GetGlobalEventHandler();
    if ( v8 )
      v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100002u, (NoticeHandler *)&v4->vfptr);
    gmClient::InitUIPreferences();
    result = 1;
  }
  return result;
}

//----- (00404840) --------------------------------------------------------  // acclient.c:63414
void __thiscall PStringBase<unsigned short>::PStringBase<unsigned short>(PStringBase<unsigned short> *this, _WidthConvert __formal, const char *str)
{
  PStringBase<unsigned short> *v3; // esi@1
  volatile LONG *v4; // ST04_4@1
  PSRefBufferCharData<unsigned short> *v5; // eax@1
  int v6; // ecx@1
  char *v7; // edi@3
  const char *v8; // edi@6
  PStringBase<unsigned short> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = this;
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&str, str);
  v5 = PStringBase<char>::to_wpstring((PStringBase<char> *)&str, &result, 0)->m_charbuffer;
  v6 = *(_DWORD *)&v5[-1].m_data[14];
  if ( v6 != 1 )
    PStringBase<unsigned short>::append_n_chars(v3, v5->m_data, v6 - 1);
  v7 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  v8 = str - 20;
  if ( !InterlockedDecrement((volatile LONG *)str - 4) )
  {
    if ( v8 )
      (**(void (__thiscall ***)(const char *, signed int))v8)(v8, 1);
  }
}

//----- (004048E0) --------------------------------------------------------  // acclient.c:63446
void __thiscall gmClient::RecvNotice_WorldName(gmClient *this, AC1Legacy::PStringBase<char> *i_strName)
{
  gmClient *v2; // esi@1
  AC1Legacy::PStringBase<char> *v3; // esi@1

  v2 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&i_strName,
    0,
    i_strName->m_buffer->m_data);
  v2[-1].vfptr[11].__vecDelDtor((CPluginPrototype *)&v2[-1].vfptr, (unsigned int)&i_strName);
  v3 = i_strName - 5;
  if ( !InterlockedDecrement((volatile LONG *)&i_strName[-4]) )
  {
    if ( v3 )
      ((void (__thiscall *)(_DWORD, _DWORD))v3->m_buffer->vfptr)(v3, 1);
  }
}

//----- (006C2E20) --------------------------------------------------------  // acclient.c:731398
int _E73_0()
{
  return atexit(_E74_2);
}

//----- (006C2E30) --------------------------------------------------------  // acclient.c:731404
int _E76_0()
{
  return atexit(_E77_28);
}

//----- (006C2E40) --------------------------------------------------------  // acclient.c:731410
int _E79_0()
{
  return atexit(_E80_2);
}

//----- (006C2E50) --------------------------------------------------------  // acclient.c:731416
void _E98_0()
{
  LOWEST_DATA_RATE_52 = 1024;
}

//----- (006C2E60) --------------------------------------------------------  // acclient.c:731422
void _E100_0()
{
  HIGHEST_DATA_RATE_52 = 0x7FFF;
}

//----- (006C2E70) --------------------------------------------------------  // acclient.c:731428
int _E102_0()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_52;
  INITIAL_MAX_DATA_RATE_0 = LOWEST_DATA_RATE_52;
  return result;
}

//----- (006C2E80) --------------------------------------------------------  // acclient.c:731438
void _E104_0()
{
  LODWORD(dword_836504) = 1053364187;
}

//----- (006C2E90) --------------------------------------------------------  // acclient.c:731444
void _E106_0()
{
  outside_val_0 = 1000.0 + 1.0;
}

//----- (006C2EB0) --------------------------------------------------------  // acclient.c:731450
void _E108_0()
{
  block_length_0 = 24.0 * 8.0;
}

//----- (006C2ED0) --------------------------------------------------------  // acclient.c:731456
void _E110_0()
{
  half_square_length_0 = 24.0 * 0.5;
}

//----- (006C2EF0) --------------------------------------------------------  // acclient.c:731462
void _E112_0()
{
  DEFAULT_VIEW_RADIUS_0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006C2F10) --------------------------------------------------------  // acclient.c:731468
void _E114_0()
{
  MIN_QUANTUM_0 = 1.0 / 30.0;
}

//----- (006C2F30) --------------------------------------------------------  // acclient.c:731474
void _E116_0()
{
  MAX_QUANTUM_0 = 1.0 / 5.0;
}

//----- (006C2F50) --------------------------------------------------------  // acclient.c:731480
void _E118_0()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_0, PFID_A8R8G8B8);
}

//----- (006C2F60) --------------------------------------------------------  // acclient.c:731486
int _E121_0()
{
  return atexit(_E122_39);
}

//----- (006C2F70) --------------------------------------------------------  // acclient.c:731492
int _E124_0()
{
  PStringBase<char>::PStringBase<char>(&Input_KeymapFile, "Input.KeymapFile");
  return atexit(_E125_15);
}

//----- (006C2F90) --------------------------------------------------------  // acclient.c:731499
int _E127_0()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontFace, "UI.ChatFontFace");
  return atexit(_E128_16);
}

//----- (006C2FB0) --------------------------------------------------------  // acclient.c:731506
int _E130_0()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontSize, "UI.ChatFontSize");
  return atexit(_E131_12);
}

//----- (006C2FD0) --------------------------------------------------------  // acclient.c:731513
int _E133_0()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontFace_Choices, "Arial");
  PStringBase<char>::PStringBase<char>(&stru_836570, "CourierNew");
  PStringBase<char>::PStringBase<char>(&stru_836574, "PalatinoLinotype");
  PStringBase<char>::PStringBase<char>(&stru_836578, "Tahoma");
  PStringBase<char>::PStringBase<char>(&stru_83657C, "TimesNewRoman");
  return atexit(_E134_11);
}

//----- (006C3030) --------------------------------------------------------  // acclient.c:731524
int _E136()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontSize_Choices, "Tiny");
  PStringBase<char>::PStringBase<char>(&stru_836584, "Small");
  PStringBase<char>::PStringBase<char>(&stru_836588, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83658C, "Large");
  PStringBase<char>::PStringBase<char>(&stru_836590, "XL");
  return atexit(_E137_12);
}

//----- (006C3090) --------------------------------------------------------  // acclient.c:731535
int _E139()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_0, "Display.Resolution");
  return atexit(_E140_7);
}

//----- (006C30B0) --------------------------------------------------------  // acclient.c:731542
int _E142()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_0, "Display.FullScreen");
  return atexit(_E143_9);
}

//----- (006C30D0) --------------------------------------------------------  // acclient.c:731549
int _E145()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_0, "Display.RefreshRate");
  return atexit(_E146_8);
}

//----- (006C30F0) --------------------------------------------------------  // acclient.c:731556
int _E148()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_0, "Display.SyncToRefresh");
  return atexit(_E149_8);
}

//----- (006C3110) --------------------------------------------------------  // acclient.c:731563
int _E151()
{
  PStringBase<char>::PStringBase<char>(&Camera_AlignToSlope, "Camera.AlignToSlope");
  return atexit(_E152_7);
}

//----- (006C3130) --------------------------------------------------------  // acclient.c:731570
int _E154()
{
  PStringBase<char>::PStringBase<char>(&Camera_Stiffness, "Camera.Stiffness");
  return atexit(_E155_5);
}

//----- (006C3150) --------------------------------------------------------  // acclient.c:731577
int _E157()
{
  PStringBase<char>::PStringBase<char>(&Camera_AdjustmentSpeed, "Camera.AdjustmentSpeed");
  return atexit(_E158_8);
}

//----- (006C3170) --------------------------------------------------------  // acclient.c:731584
int _E160()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled, "Sound.SoundDisabled");
  return atexit(_E161_5);
}

//----- (006C3190) --------------------------------------------------------  // acclient.c:731591
int _E163()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume, "Sound.SoundVolume");
  return atexit(_E164_9);
}

//----- (006C31B0) --------------------------------------------------------  // acclient.c:731598
int _E166()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled, "Sound.AmbientSoundDisabled");
  return atexit(_E167_5);
}

//----- (006C31D0) --------------------------------------------------------  // acclient.c:731605
int _E169()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume, "Sound.AmbientSoundVolume");
  return atexit(_E170_5);
}

//----- (006C31F0) --------------------------------------------------------  // acclient.c:731612
int _E172()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled, "Sound.InterfaceSoundDisabled");
  return atexit(_E173_4);
}

//----- (006C3210) --------------------------------------------------------  // acclient.c:731619
int _E175()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume, "Sound.InterfaceSoundVolume");
  return atexit(_E176_5);
}

//----- (006C3230) --------------------------------------------------------  // acclient.c:731626
int _E178()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures, "Sound.SoundFeatures");
  return atexit(_E179_4);
}

//----- (006C3250) --------------------------------------------------------  // acclient.c:731633
int _E181()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E182_4);
}

//----- (006C3270) --------------------------------------------------------  // acclient.c:731640
int _E184()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_8365D4, "Mono");
  return atexit(_E185_3);
}

//----- (006C32A0) --------------------------------------------------------  // acclient.c:731648
int _E187()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable, "Misc.TooltipEnable");
  return atexit(_E188_4);
}

//----- (006C32C0) --------------------------------------------------------  // acclient.c:731655
int _E190()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay, "Misc.TooltipDelay");
  return atexit(_E191_3);
}

//----- (006C32E0) --------------------------------------------------------  // acclient.c:731662
int _E193()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering, "Render.TextureFiltering");
  return atexit(_E194_10);
}

//----- (006C3300) --------------------------------------------------------  // acclient.c:731669
int _E196()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures, "Render.LandscapeDetailTextures");
  return atexit(_E197_1);
}

//----- (006C3320) --------------------------------------------------------  // acclient.c:731676
int _E199()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures, "Render.BuildingDetailTextures");
  return atexit(_E200_6);
}

//----- (006C3340) --------------------------------------------------------  // acclient.c:731683
int _E202()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView, "Render.FieldOfView");
  return atexit(_E203_5);
}

//----- (006C3360) --------------------------------------------------------  // acclient.c:731690
int _E205()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail, "Render.LandscapeTextureDetail");
  return atexit(_E206_7);
}

//----- (006C3380) --------------------------------------------------------  // acclient.c:731697
int _E208()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail, "Render.EnvironmentTextureDetail");
  return atexit(_E209_2);
}

//----- (006C33A0) --------------------------------------------------------  // acclient.c:731704
int _E211()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance, "Render.SceneryDrawDistance");
  return atexit(_E212_5);
}

//----- (006C33C0) --------------------------------------------------------  // acclient.c:731711
int _E214()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance, "Render.LandscapeDrawDistance");
  return atexit(_E215_1);
}

//----- (006C33E0) --------------------------------------------------------  // acclient.c:731718
int _E217()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness, "Render.ScreenBrightness");
  return atexit(_E218_2);
}

//----- (006C3400) --------------------------------------------------------  // acclient.c:731725
int _E220()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio, "Render.AspectRatio");
  return atexit(_E221_2);
}

//----- (006C3420) --------------------------------------------------------  // acclient.c:731732
int _E223()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter, "Render.DisplayAdapter");
  return atexit(_E224_2);
}

//----- (006C3440) --------------------------------------------------------  // acclient.c:731739
int _E226()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass, "Render.MaxHardwareClass");
  return atexit(_E227_2);
}

//----- (006C3460) --------------------------------------------------------  // acclient.c:731746
int _E229()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades, "Render.AutomaticDegrades");
  return atexit(_E230_2);
}

//----- (006C3480) --------------------------------------------------------  // acclient.c:731753
int _E232()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance, "Render.GraphicsPerformance");
  return atexit(_E233_1);
}

//----- (006C34A0) --------------------------------------------------------  // acclient.c:731760
int _E235()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance, "Render.DegradeDistance");
  return atexit(_E236_1);
}

//----- (006C34C0) --------------------------------------------------------  // acclient.c:731767
int _E238()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha, "Render.MultiPassAlpha");
  return atexit(_E239_2);
}

//----- (006C34E0) --------------------------------------------------------  // acclient.c:731774
int _E241()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_836624, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_836628, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83662C, "Anisotropic");
  return atexit(_E242_2);
}

//----- (006C3530) --------------------------------------------------------  // acclient.c:731784
int _E244()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836634, "Low");
  PStringBase<char>::PStringBase<char>(&stru_836638, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83663C, "High");
  PStringBase<char>::PStringBase<char>(&stru_836640, "VeryHigh");
  return atexit(_E245_1);
}

//----- (006C3590) --------------------------------------------------------  // acclient.c:731795
int _E247()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836648, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83664C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836650, "High");
  PStringBase<char>::PStringBase<char>(&stru_836654, "VeryHigh");
  return atexit(_E248_1);
}

//----- (006C35F0) --------------------------------------------------------  // acclient.c:731806
int _E250()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83665C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836660, "High");
  return atexit(_E251_1);
}

//----- (006C3630) --------------------------------------------------------  // acclient.c:731815
int _E253()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_836668, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83666C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_836670, "High");
  PStringBase<char>::PStringBase<char>(&stru_836674, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_836678, "Extreme");
  return atexit(_E254_2);
}

//----- (006C36A0) --------------------------------------------------------  // acclient.c:731827
int _E256()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_836680, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_836684, "Wide");
  return atexit(_E257_0);
}

//----- (006C36E0) --------------------------------------------------------  // acclient.c:731836
int _E259()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSensitivity, "Input.MouseLookSensitivity");
  return atexit(_E260_1);
}

//----- (006C3700) --------------------------------------------------------  // acclient.c:731843
int _E262()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSmoothingAmount, "Input.MouseLookSmoothingAmount");
  return atexit(_E263);
}

//----- (006C3720) --------------------------------------------------------  // acclient.c:731850
int _E265()
{
  PStringBase<char>::PStringBase<char>(&Input_InvertMouseLookYAxis, "Input.InvertMouseLookYAxis");
  return atexit(_E266);
}

//----- (006C3740) --------------------------------------------------------  // acclient.c:731857
int _E268()
{
  PStringBase<char>::PStringBase<char>(&Input_UseMouseTurning, "Input.UseMouseTurning");
  return atexit(_E269);
}

//----- (006C3760) --------------------------------------------------------  // acclient.c:731864
int _E271()
{
  PStringBase<char>::PStringBase<char>(&waveform_None, "None");
  return atexit(_E272);
}

//----- (006C3780) --------------------------------------------------------  // acclient.c:731871
int _E274()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed, "Speed");
  return atexit(_E275);
}

//----- (006C37A0) --------------------------------------------------------  // acclient.c:731878
int _E277()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise, "Noise");
  return atexit(_E278);
}

//----- (006C37C0) --------------------------------------------------------  // acclient.c:731885
int _E280()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine, "Sine");
  return atexit(_E281_0);
}

//----- (006C37E0) --------------------------------------------------------  // acclient.c:731892
int _E283()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square, "Square");
  return atexit(_E284);
}

//----- (006C3800) --------------------------------------------------------  // acclient.c:731899
int _E286()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce, "Bounce");
  return atexit(_E287_0);
}

//----- (006C3820) --------------------------------------------------------  // acclient.c:731906
int _E289()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin, "Perlin");
  return atexit(_E290_0);
}

//----- (006C3840) --------------------------------------------------------  // acclient.c:731913
int _E292()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal, "Fractal");
  return atexit(_E293);
}

//----- (006C3860) --------------------------------------------------------  // acclient.c:731920
int _E295()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop, "FrameLoop");
  return atexit(_E296_0);
}

//----- (006C3880) --------------------------------------------------------  // acclient.c:731927
int __thiscall _E298(unsigned int this)
{
  int v1; // eax@1
  int v2; // esi@1
  Interface *v3; // ST08_4@2
  InterfaceSystem *v4; // eax@2
  TResult result; // [sp+0h] [bp-4h]@1

  result.m_val = this;
  v1 = (int)operator new(0xCu);
  v2 = v1;
  if ( v1 )
  {
    v3 = (Interface *)v1;
    *(_DWORD *)v1 = &ClassFactoryForceClient_ClassType::vftable;
    *(_DWORD *)(v1 + 8) = 1;
    *(_DWORD *)(v1 + 4) = &ReferenceCountTemplate<1048576,2>::vftable;
    v4 = InterfaceSystem::GetInstance();
    InterfaceSystem::RegisterClassA(v4, &result, &Client_ClassType_0, v3, 0);
    v1 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
  }
  return v1;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 792CDC: using guessed type __int32 (__stdcall *ClassFactoryForceClient_ClassType::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006C38D0) --------------------------------------------------------  // acclient.c:731954
int _E1_1()
{
  return atexit(_E2_1);
}

//----- (00724F50) --------------------------------------------------------  // acclient.c:822615
void __cdecl _E125_15()
{
  char *v0; // esi@1

  v0 = &Input_KeymapFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_KeymapFile.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724F80) --------------------------------------------------------  // acclient.c:822628
void __cdecl _E128_16()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontFace.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontFace.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724FB0) --------------------------------------------------------  // acclient.c:822641
void __cdecl _E131_12()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontSize.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontSize.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724FE0) --------------------------------------------------------  // acclient.c:822654
void __cdecl _E134_11()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)UI_ChatFontSize_Choices;
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

//----- (00725020) --------------------------------------------------------  // acclient.c:822679
void __cdecl _E137_12()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Display_Resolution_0;
  v1 = 5;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00725060) --------------------------------------------------------  // acclient.c:822704
void __cdecl _E140_7()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725090) --------------------------------------------------------  // acclient.c:822717
void __cdecl _E143_9()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007250C0) --------------------------------------------------------  // acclient.c:822730
void __cdecl _E146_8()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007250F0) --------------------------------------------------------  // acclient.c:822743
void __cdecl _E149_8()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725120) --------------------------------------------------------  // acclient.c:822756
void __cdecl _E152_7()
{
  char *v0; // esi@1

  v0 = &Camera_AlignToSlope.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AlignToSlope.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725150) --------------------------------------------------------  // acclient.c:822769
void __cdecl _E155_5()
{
  char *v0; // esi@1

  v0 = &Camera_Stiffness.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_Stiffness.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725180) --------------------------------------------------------  // acclient.c:822782
void __cdecl _E158_8()
{
  char *v0; // esi@1

  v0 = &Camera_AdjustmentSpeed.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AdjustmentSpeed.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007251B0) --------------------------------------------------------  // acclient.c:822795
void __cdecl _E161_5()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007251E0) --------------------------------------------------------  // acclient.c:822808
void __cdecl _E164_9()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725210) --------------------------------------------------------  // acclient.c:822821
void __cdecl _E167_5()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725240) --------------------------------------------------------  // acclient.c:822834
void __cdecl _E170_5()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725270) --------------------------------------------------------  // acclient.c:822847
void __cdecl _E173_4()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007252A0) --------------------------------------------------------  // acclient.c:822860
void __cdecl _E176_5()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007252D0) --------------------------------------------------------  // acclient.c:822873
void __cdecl _E179_4()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725300) --------------------------------------------------------  // acclient.c:822886
void __cdecl _E182_4()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725330) --------------------------------------------------------  // acclient.c:822899
void __cdecl _E185_3()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Misc_TooltipEnable;
  v1 = 2;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00725370) --------------------------------------------------------  // acclient.c:822924
void __cdecl _E188_4()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007253A0) --------------------------------------------------------  // acclient.c:822937
void __cdecl _E191_3()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007253D0) --------------------------------------------------------  // acclient.c:822950
void __cdecl _E194_10()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725400) --------------------------------------------------------  // acclient.c:822963
void __cdecl _E197_1()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725430) --------------------------------------------------------  // acclient.c:822976
void __cdecl _E200_6()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725460) --------------------------------------------------------  // acclient.c:822989
void __cdecl _E203_5()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725490) --------------------------------------------------------  // acclient.c:823002
void __cdecl _E206_7()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007254C0) --------------------------------------------------------  // acclient.c:823015
void __cdecl _E209_2()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007254F0) --------------------------------------------------------  // acclient.c:823028
void __cdecl _E212_5()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725520) --------------------------------------------------------  // acclient.c:823041
void __cdecl _E215_1()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725550) --------------------------------------------------------  // acclient.c:823054
void __cdecl _E218_2()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725580) --------------------------------------------------------  // acclient.c:823067
void __cdecl _E221_2()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007255B0) --------------------------------------------------------  // acclient.c:823080
void __cdecl _E224_2()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007255E0) --------------------------------------------------------  // acclient.c:823093
void __cdecl _E227_2()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725610) --------------------------------------------------------  // acclient.c:823106
void __cdecl _E230_2()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725640) --------------------------------------------------------  // acclient.c:823119
void __cdecl _E233_1()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725670) --------------------------------------------------------  // acclient.c:823132
void __cdecl _E236_1()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007256A0) --------------------------------------------------------  // acclient.c:823145
void __cdecl _E239_2()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007256D0) --------------------------------------------------------  // acclient.c:823158
void __cdecl _E242_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices;
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

//----- (00725710) --------------------------------------------------------  // acclient.c:823183
void __cdecl _E245_1()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices;
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

//----- (00725750) --------------------------------------------------------  // acclient.c:823208
void __cdecl _E248_1()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices;
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

//----- (00725790) --------------------------------------------------------  // acclient.c:823233
void __cdecl _E251_1()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices;
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

//----- (007257D0) --------------------------------------------------------  // acclient.c:823258
void __cdecl _E254_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices;
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

//----- (00725810) --------------------------------------------------------  // acclient.c:823283
void __cdecl _E257_0()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Input_MouseLookSensitivity;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00725850) --------------------------------------------------------  // acclient.c:823308
void __cdecl _E260_1()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSensitivity.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSensitivity.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725880) --------------------------------------------------------  // acclient.c:823321
void __cdecl _E263()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSmoothingAmount.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSmoothingAmount.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007258B0) --------------------------------------------------------  // acclient.c:823334
void __cdecl _E266()
{
  char *v0; // esi@1

  v0 = &Input_InvertMouseLookYAxis.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_InvertMouseLookYAxis.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007258E0) --------------------------------------------------------  // acclient.c:823347
void __cdecl _E269()
{
  char *v0; // esi@1

  v0 = &Input_UseMouseTurning.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_UseMouseTurning.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725910) --------------------------------------------------------  // acclient.c:823360
void __cdecl _E272()
{
  char *v0; // esi@1

  v0 = &waveform_None.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725940) --------------------------------------------------------  // acclient.c:823373
void __cdecl _E275()
{
  char *v0; // esi@1

  v0 = &waveform_Speed.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725970) --------------------------------------------------------  // acclient.c:823386
void __cdecl _E278()
{
  char *v0; // esi@1

  v0 = &waveform_Noise.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007259A0) --------------------------------------------------------  // acclient.c:823399
void __cdecl _E281_0()
{
  char *v0; // esi@1

  v0 = &waveform_Sine.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007259D0) --------------------------------------------------------  // acclient.c:823412
void __cdecl _E284()
{
  char *v0; // esi@1

  v0 = &waveform_Square.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725A00) --------------------------------------------------------  // acclient.c:823425
void __cdecl _E287_0()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725A30) --------------------------------------------------------  // acclient.c:823438
void __cdecl _E290_0()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725A60) --------------------------------------------------------  // acclient.c:823451
void __cdecl _E293()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725A90) --------------------------------------------------------  // acclient.c:823464
void __cdecl _E296_0()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

